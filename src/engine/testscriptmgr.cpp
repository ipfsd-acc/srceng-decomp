// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/testscriptmgr.cpp
// Functions: 218
// ============================================================

#include "engine\testscriptmgr.h"

//------------------------------------------------------------------------------
// Address: 0x10038610
// Name: protected: unsigned short CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10038900
// Name: protected: int CUtlLinkedList<struct CAsyncWavDataCache::StreamedEntry_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *m_pMemory; // ecx
  int v10; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result << 6;
    if ( multilist )
    {
      *(int *)((char *)&m_pMemory->m_Next + v10) = -1;
      *(int *)((char *)&m_pMemory->m_Previous + v10) = -1;
    }
    else
    {
      *(int *)((char *)&m_pMemory->m_Next + v10) = result;
      *(int *)((char *)&m_pMemory->m_Previous + v10) = result;
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
    CUtlMemory<maplist_map_t,int>::Grow((CUtlMemory<VMatrix,int> *)this, num: 1);
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
      if ( `CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x100398E0
// Name: public: void CUtlLinkedList<struct CAsyncWavDataCache::StreamedEntry_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CAsyncWavDataCache::StreamedEntry_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
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
// Address: 0x1003A740
// Name: public: void CUtlLinkedList<struct CAsyncWavDataCache::StreamedEntry_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CAsyncWavDataCache::StreamedEntry_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::Unlink(
        CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v2; // eax
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
// Address: 0x1003BC80
// Name: public: unsigned short CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AddToTail(unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this,
        unsigned int *src)
{
  int v3; // esi
  int result; // eax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v5; // eax

  v3 = (unsigned __int16)CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v3);
    v5 = &this->m_Memory.m_pMemory[v3];
    if ( v5 != nullptr )
      v5->m_Element = *src;
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064C00
// Name: protected: unsigned short CUtlLinkedList<struct CBrushBatchRender::brushrender_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBrushBatchRender::brushrender_t __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10065180
// Name: public: void CUtlLinkedList<class CClientSendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CClientSendTable __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<unsigned int,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<unsigned int,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v7; // ebx

  CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100877A0
// Name: public: void CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<unsigned short,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D180
// Name: public: void CUtlLinkedList<class CEventInfo,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::RemoveAll(
        CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[8 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[8 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[8 * m_nIndex + 8].m_pNext == &m_pBlockHeader[8 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)m_pBlockHeader[8 * m_nIndex + 8].m_nBlockSize != &m_pBlockHeader[8 * m_nIndex + 1] )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)p_m_Memory;
          }
          else
          {
            if ( m_pBlockHeader[8 * m_nIndex + 3].m_nBlockSize != 0 )
              free(pMem: (void *)m_pBlockHeader[8 * m_nIndex + 3].m_nBlockSize);
            CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&m_pBlockHeader[8 * m_nIndex + 5].m_nBlockSize);
            v5 = p_m_Memory;
            m_pBlockHeader[8 * m_nIndex + 4].m_nBlockSize = (int)&IRecipientFilter::`vftable';
            m_pBlockHeader[8 * m_nIndex + 8].m_pNext = &m_pBlockHeader[8 * m_nIndex + 1];
            m_pBlockHeader[8 * m_nIndex + 8].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[8 * m_nIndex + 1];
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x1008D270
// Name: public: void CUtlLinkedList<class CEventInfo,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::Free(
        CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 56);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 60) = *(_DWORD *)(elem + 60);
      else
        this->m_Head = *(_DWORD *)(elem + 60);
      v4 = *(_DWORD *)(elem + 60);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 56) = *(_DWORD *)(elem + 56);
      else
        this->m_Tail = *(_DWORD *)(elem + 56);
      *(_DWORD *)(elem + 60) = elem;
      *(_DWORD *)(elem + 56) = elem;
      --this->m_ElementCount;
    }
  }
  if ( *(_DWORD *)(elem + 20) != 0 )
    free(pMem: *(void **)(elem + 20));
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)(elem + 36));
  *(_DWORD *)(elem + 28) = &IRecipientFilter::`vftable';
  *(_DWORD *)(elem + 60) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x100BE120
// Name: protected: int CUtlLinkedList<struct decal_t __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct decal_t __near *,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BE2B0
// Name: public: void CUtlLinkedList<class CDispShadowDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowDecal,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v2; // ax
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v3; // edx
  CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>::Iterator_t it; // [esp+0h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v2;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        ++v2;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
        it.index = v2;
      }
      while ( v2 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE370
// Name: protected: unsigned short CUtlLinkedList<class CDispShadowDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100BE500
// Name: public: void CUtlLinkedList<class CDispShadowFragment,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowFragment,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v3; // si
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v5; // edi
  CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>::Iterator_t it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v3;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        v4 = v3;
        if ( v3 < this->m_Memory.m_nAllocationCount && v3 <= index )
        {
          v5 = &this->m_Memory.m_pMemory[v3];
          if ( v5->m_Previous != v3 || v5->m_Next == v3 )
          {
            free(pMem: v5->m_Element.m_ShadowVerts);
            v4 = v3;
            v5->m_Element.m_ShadowVerts = nullptr;
            v5->m_Previous = v3;
            v5->m_Next = this->m_FirstFree;
            this->m_FirstFree = v3;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v3 = v4 + 1;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v3 = -1;
        it.index = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE5D0
// Name: protected: unsigned short CUtlLinkedList<class CDispShadowFragment,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowFragment,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100BE750
// Name: public: void CUtlLinkedList<class CDispDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecal,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v2; // ax
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v3; // edx
  CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>::Iterator_t it; // [esp+0h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v2;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        ++v2;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
        it.index = v2;
      }
      while ( v2 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE800
// Name: protected: unsigned short CUtlLinkedList<class CDispDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecal,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDispDecal,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100BE980
// Name: public: void CUtlLinkedList<class CDispDecalFragment,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecalFragment,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v3; // si
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v5; // edi
  CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>::Iterator_t it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v3;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        v4 = v3;
        if ( v3 < this->m_Memory.m_nAllocationCount && v3 <= index )
        {
          v5 = &this->m_Memory.m_pMemory[v3];
          if ( v5->m_Previous != v3 || v5->m_Next == v3 )
          {
            free(pMem: v5->m_Element.m_pVerts);
            v4 = v3;
            v5->m_Element.m_pVerts = nullptr;
            v5->m_Previous = v3;
            v5->m_Next = this->m_FirstFree;
            this->m_FirstFree = v3;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v3 = v4 + 1;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v3 = -1;
        it.index = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEA50
// Name: protected: unsigned short CUtlLinkedList<class CDispDecalFragment,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100BF6B0
// Name: public: void CUtlLinkedList<class CDispShadowDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowDecal,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = v3->m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = v3->m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF760
// Name: public: void CUtlLinkedList<struct CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF7F0
// Name: public: void CUtlLinkedList<class CDispDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecal,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF890
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFB20
// Name: public: void CUtlLinkedList<class CDispShadowDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowDecal,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax

  CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    v5->m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFBC0
// Name: public: void CUtlLinkedList<struct CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v7; // ebx

  CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFC50
// Name: public: void CUtlLinkedList<class CDispDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecal,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CDispDecal,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFCE0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDEF0
// Name: public: void CUtlLinkedList<struct CModelRender::ModelInstance_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // ecx
  int v3; // esi
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // edx
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v6; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v8; // ax
  CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *v9; // [esp+0h] [ebp-4h]

  v9 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_pLightingState = m_pMemory[v3].m_Element.m_pLightingState;
        m_Next = m_pMemory[v3].m_Next;
        v6 = &m_pMemory[v3];
        CUtlMemoryPool::Free(this: &CModelRender::ModelInstanceLightingState_t::s_Allocator, memBlock: m_pLightingState);
        v6->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = v9->m_FirstFree;
        else
          m_FirstFree = m_Next;
        this = v9;
        v6->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v8 = this->m_Head;
    if ( v8 != 0xFFFF )
      this->m_FirstFree = v8;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDF80
// Name: protected: unsigned short CUtlLinkedList<struct CModelRender::ModelInstance_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100E0280
// Name: public: void CUtlLinkedList<struct CModelRender::ModelInstance_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0CD0
// Name: public: void CUtlLinkedList<struct CModelRender::ModelInstance_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F78D0
// Name: public: void CUtlLinkedList<struct COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7940
// Name: protected: unsigned short CUtlLinkedList<struct moverlayfragment_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100F7AC0
// Name: public: void CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v2; // ax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v3; // edx
  CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>::Iterator_t it; // [esp+0h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v2;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        ++v2;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
        it.index = v2;
      }
      while ( v2 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7B70
// Name: protected: unsigned short CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100F7D50
// Name: protected: unsigned short CUtlLinkedList<struct COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100F8180
// Name: public: void CUtlLinkedList<struct moverlayfragment_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F82E0
// Name: public: void CUtlLinkedList<struct COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8380
// Name: public: void CUtlLinkedList<struct COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F85F0
// Name: public: void CUtlLinkedList<struct moverlayfragment_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct moverlayfragment_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v3; // si
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v5; // edi
  CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>::Iterator_t it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v3;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        v4 = v3;
        if ( v3 < this->m_Memory.m_nAllocationCount && v3 <= index )
        {
          v5 = &this->m_Memory.m_pMemory[v3];
          if ( v5->m_Previous != v3 || v5->m_Next == v3 )
          {
            CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v5->m_Element.m_aPrimVerts);
            v5->m_Previous = v3;
            v5->m_Next = this->m_FirstFree;
            v4 = v3;
            this->m_FirstFree = v3;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v3 = v4 + 1;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v3 = -1;
        it.index = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102AD0
// Name: public: void CUtlLinkedList<unsigned short,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this,
        int growSize)
{
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v4; // [esp-4h] [ebp-Ch]

  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v4 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = nullptr;
    this->m_Memory.m_nGrowSize = growSize;
  }
  else
  {
    this->m_Memory.m_nGrowSize = growSize;
    this->m_pElements = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BFE0
// Name: protected: int CUtlLinkedList<unsigned short,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal(
        CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010C170
// Name: protected: unsigned short CUtlLinkedList<struct msurface2_t __near *,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct msurface2_t __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<msurface2_t *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010C2F0
// Name: public: void CUtlLinkedList<struct CShadowMgr::Shadow_t,unsigned short,0,int,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          LOWORD(m_FirstFree) = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C360
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowDecal_t,unsigned short,1,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowDecal_t,unsigned short>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *this)
{
  int index; // edx
  int v2; // eax
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C3E0
// Name: protected: int CUtlLinkedList<struct CShadowMgr::ShadowDecal_t,unsigned short,1,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFFFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_27:
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
    CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
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
      if ( `CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010C520
// Name: public: void CUtlLinkedList<struct CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C590
// Name: protected: unsigned short CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010C710
// Name: public: void CUtlLinkedList<struct CShadowMgr::Shadow_t,unsigned short,0,int,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::Unlink(
        CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *this,
        int elem)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v2; // eax
  int m_Previous; // ebx
  int m_Next; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Previous = v2->m_Previous;
      m_Next = v2->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( (_WORD)m_Next == 0xFFFF )
        this->m_Tail = v2->m_Previous;
      else
        this->m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Previous = v2->m_Previous;
      --this->m_ElementCount;
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C7D0
// Name: protected: int CUtlLinkedList<struct CShadowMgr::Shadow_t,unsigned short,0,int,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // ecx
  int v10; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_27:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      v11 = &m_pMemory[v10];
      v11->m_Next = -1;
      v11->m_Previous = -1;
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
    CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010C930
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010CAB0
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010CC30
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010CDC0
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010CF50
// Name: protected: unsigned short CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010D0D0
// Name: protected: unsigned short CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010D250
// Name: protected: int CUtlLinkedList<struct CShadowMgr::SurfaceBounds_t,unsigned short,0,int,class CUtlMemoryFixed<struct UtlLinkedListElem_t<struct CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *this,
        bool multilist)
{
  int result; // eax
  unsigned int index; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ecx
  int v8; // edx
  unsigned int v9; // ecx
  int v10; // [esp+4h] [ebp-4h]
  int v11; // [esp+4h] [ebp-4h]

  result = this->m_FirstFree;
  if ( result != 0xFFFF )
  {
    this->m_FirstFree = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0)
                                            + 80 * result
                                            + 0x42);
LABEL_23:
    v7 = (unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0;
    if ( multilist )
    {
      v9 = 80 * result + v7;
      *(_WORD *)(v9 + 66) = -1;
      *(_WORD *)(v9 + 64) = -1;
    }
    else
    {
      v8 = 10 * result;
      *(_WORD *)(v7 + 8 * v8 + 66) = result;
      *(_WORD *)(v7 + 8 * v8 + 64) = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index >= 0x400 )
  {
    v10 = 0;
  }
  else
  {
    v4 = index + 1;
    if ( v4 >= 0x400 )
      v4 = -1;
    v10 = v4;
  }
  result = v10;
  if ( v10 < 0 )
  {
    this->m_pElements = (UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short> *)((unsigned int)&this->m_Memory.m_Memory[15]
                                                                                          & 0xFFFFFFF0);
    v5 = this->m_LastAlloc.index;
    if ( v5 >= 0x400 )
    {
      v11 = 0;
    }
    else
    {
      v6 = v5 + 1;
      if ( v6 >= 0x400 )
        v6 = -1;
      v11 = v6;
    }
    result = v11;
    if ( v11 < 0 )
    {
      if ( `CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_23;
  }
  if ( `CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010D3B0
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ecx
  int v10; // edx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_26:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &m_pMemory[v10];
      v11->m_Next = -1;
      v11->m_Previous = -1;
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
    CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>::Grow(
      this: &this->m_Memory,
      num: 1);
    v7 = this->m_LastAlloc.index;
    this->m_pElements = this->m_Memory.m_pMemory;
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
      if ( `CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_26;
  }
  if ( `CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010F040
// Name: public: void CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v2; // ax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short> *v3; // edx
  CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>::Iterator_t it; // [esp+0h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v2;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        ++v2;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
        it.index = v2;
      }
      while ( v2 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F150
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowDecal_t,unsigned short,1,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(
        CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v2; // eax
  int m_Previous; // ebx
  int m_Next; // edx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Previous = v2->m_Previous;
      m_Next = v2->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( (_WORD)m_Next == 0xFFFF )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F1F0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F260
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F2E0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F400
// Name: public: void CUtlLinkedList<struct CShadowMgr::Shadow_t,unsigned short,0,int,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *this,
        int before,
        int elem)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // ebx
  int v5; // eax
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F4A0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F560
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F620
// Name: public: void CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::Unlink(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F6E0
// Name: public: void CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<unsigned short,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FCB0
// Name: public: void CUtlLinkedList<class PackedEntity __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class PackedEntity __near *,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::Free(
        CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
          (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)this,
          i: elem,
          it: (const CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&this->m_LastAlloc) )
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
// Address: 0x1010FD20
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowDecal_t,unsigned short,1,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowDecal_t,unsigned short>,int>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *this,
        int before,
        int elem)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FE10
// Name: public: void CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<unsigned short,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<unsigned short,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v7; // ebx

  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
    (CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *)this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FEA0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FF40
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FFE0
// Name: public: void CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110AC0
// Name: public: void CUtlLinkedList<struct CShadowMgr::SurfaceBounds_t,unsigned short,0,int,class CUtlMemoryFixed<struct UtlLinkedListElem_t<struct CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *this)
{
  int m_Head; // eax
  int v2; // esi
  int v3; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = 10 * m_Head;
        v3 = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * m_Head + 0x42);
        *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * m_Head + 0x40) = m_Head;
        if ( v3 == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          LOWORD(m_FirstFree) = v3;
        *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 8 * v2 + 0x42) = m_FirstFree;
        m_Head = v3;
      }
      while ( v3 != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110B50
// Name: public: void CUtlLinkedList<struct CShadowMgr::SurfaceBounds_t,unsigned short,0,int,class CUtlMemoryFixed<struct UtlLinkedListElem_t<struct CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::Unlink(
        CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *this,
        unsigned int elem)
{
  int v2; // ebx
  int v3; // esi

  if ( elem < 0x400
    && (signed int)elem <= this->m_LastAlloc.index
    && *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40) != elem )
  {
    v2 = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40);
    v3 = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42);
    if ( (_WORD)v2 == 0xFFFF )
      this->m_Head = v3;
    else
      *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * v2 + 0x42) = v3;
    if ( (_WORD)v3 == 0xFFFF )
      this->m_Tail = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40);
    else
      *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * (unsigned __int16)v3 + 0x40) = *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40);
    --this->m_ElementCount;
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42) = elem;
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110D20
// Name: public: void CUtlLinkedList<struct CShadowMgr::SurfaceBounds_t,unsigned short,0,int,class CUtlMemoryFixed<struct UtlLinkedListElem_t<struct CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::LinkAfter(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::LinkAfter(
        CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *this,
        int after,
        unsigned int elem)
{
  int v4; // eax

  if ( elem < 0x400
    && (signed int)elem <= this->m_LastAlloc.index
    && *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40) != elem )
  {
    CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::Unlink(
      this,
      elem);
  }
  *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40) = after;
  if ( after == 0xFFFF )
  {
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42) = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42) = *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * after + 0x42);
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * after + 0x42) = elem;
  }
  v4 = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42);
  if ( (_WORD)v4 == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * v4 + 0x40) = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112250
// Name: public: unsigned short CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax

  v2 = (unsigned __int16)CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::LinkBefore(
      (CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *)this,
      before: 0xFFFFu,
      elem: v2);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101129B0
// Name: public: unsigned short CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::InsertBefore(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::InsertBefore(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this,
        unsigned __int16 before)
{
  int v3; // edi
  unsigned __int16 result; // ax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v5; // esi

  v3 = (unsigned __int16)CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal(
                           this,
                           multilist: false);
  result = -1;
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::LinkBefore(
      this,
      before,
      elem: v3);
    v5 = &this->m_Memory.m_pMemory[v3];
    if ( v5 != nullptr )
    {
      Frustum_t::Frustum_t(this: &this->m_Memory.m_pMemory[v3].m_Element.m_Frustum);
      FlashlightState_t::FlashlightState_t(this: &v5->m_Element.m_FlashlightState);
      CMaterialsBuckets<msurface2_t *>::CMaterialsBuckets<msurface2_t *>(this: &v5->m_Element.m_MaterialBuckets);
      CMaterialsBuckets<msurface2_t *>::CMaterialsBuckets<msurface2_t *>(this: &v5->m_Element.m_OccluderBuckets);
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10112A20
// Name: public: void CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // di
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v5; // ax
  CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(this: &v2->m_Element.m_OccluderBuckets);
        CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(this: &v2->m_Element.m_MaterialBuckets);
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = v6->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        this = v6;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FA40
// Name: protected: unsigned short CUtlLinkedList<class CFrameSnapshot __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CFrameSnapshot __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1011FBC0
// Name: protected: int CUtlLinkedList<class PackedEntity __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class PackedEntity __near *,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal(
        CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B890
// Name: protected: unsigned short CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1012BA10
// Name: protected: unsigned short CUtlLinkedList<float,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<float,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1012BB90
// Name: public: void CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BC20
// Name: public: void CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BCB0
// Name: public: void CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::LinkAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::LinkAfter(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v4; // edi
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v5; // eax
  int m_Next; // eax

  if ( elem < this->m_Memory.m_nAllocationCount
    && elem <= this->m_LastAlloc.index
    && this->m_Memory.m_pMemory[elem].m_Previous != elem )
  {
    CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::Unlink(
      this,
      elem);
  }
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v4->m_Next = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    v5 = &this->m_Memory.m_pMemory[after];
    v4->m_Next = v5->m_Next;
    v5->m_Next = elem;
  }
  m_Next = v4->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BD50
// Name: public: void CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // di
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v5; // ax
  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        if ( v2->m_Element.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v2->m_Element.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Element.m_Memory.m_pMemory);
            this = v6;
            v2->m_Element.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_Memory.m_nAllocationCount = 0;
        }
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BE00
// Name: public: unsigned short CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::AddToHead(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AddToHead(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v4; // ecx

  v2 = (unsigned __int16)CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::LinkAfter(
      this,
      after: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
      CUtlBuffer::CUtlBuffer(this: &v4->m_Element, growSize: 0, initSize: 0, nFlags: 0);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012BE40
// Name: public: unsigned short CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v4; // ecx

  v2 = (unsigned __int16)CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
      CUtlBuffer::CUtlBuffer(this: &v4->m_Element, growSize: 0, initSize: 0, nFlags: 0);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012D380
// Name: protected: int CUtlLinkedList<struct CServerRemoteAccess::DataResponse_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v8; // ecx

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
    CUtlMemory<ToolModule_t,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1012D4B0
// Name: protected: int CUtlLinkedList<struct CServerRemoteAccess::ListenerStore_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v8; // ecx

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
    CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimSequence_t,int> *)this,
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
      if ( `CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1012D6A0
// Name: public: void CUtlLinkedList<struct CServerRemoteAccess::ListenerStore_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::ListenerStore_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v2; // esi
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
// Address: 0x1012D700
// Name: public: void CUtlLinkedList<struct CServerRemoteAccess::DataResponse_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::DataResponse_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::Unlink(
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v2; // eax
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
// Address: 0x1012D790
// Name: public: void CUtlLinkedList<struct CServerRemoteAccess::ListenerStore_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::ListenerStore_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::Unlink(
        CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v2; // eax
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
// Address: 0x1012DF60
// Name: public: int CUtlLinkedList<struct CServerRemoteAccess::DataResponse_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *m_pMemory; // ecx
  int v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v7; // ecx
  CUtlBuffer *p_packet; // ecx

  result = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::Unlink(
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
    v7 = this->m_Memory.m_pMemory;
    ++this->m_ElementCount;
    p_packet = &v7[v5].m_Element.packet;
    if ( p_packet != nullptr )
      CUtlBuffer::CUtlBuffer(this: p_packet, growSize: 0, initSize: 0, nFlags: 0);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012DFD0
// Name: public: int CUtlLinkedList<struct CServerRemoteAccess::ListenerStore_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::ListenerStore_t,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AddToTail(
        CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *m_pMemory; // ecx
  unsigned int v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v7; // esi
  netadr_s *p_adr; // esi

  result = CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::Unlink(
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
      p_adr = &v7->m_Element.adr;
      netadr_s::SetIP(this: p_adr, unIP: 0);
      netadr_s::SetPort(this: p_adr, newport: 0);
      netadr_s::SetType(this: p_adr, newtype: NA_IP);
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012E060
// Name: public: void CUtlLinkedList<struct CServerRemoteAccess::DataResponse_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::DataResponse_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *this)
{
  int m_Head; // edi
  int m_Next; // ebx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v3; // esi
  int m_FirstFree; // eax
  int v5; // eax
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
        v3 = &this->m_Memory.m_pMemory[m_Head];
        if ( v3->m_Element.packet.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_Element.packet.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Element.packet.m_Memory.m_pMemory);
            this = v6;
            v3->m_Element.packet.m_Memory.m_pMemory = nullptr;
          }
          v3->m_Element.packet.m_Memory.m_nAllocationCount = 0;
        }
        v3->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v3->m_Next = m_FirstFree;
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
// Address: 0x10168700
// Name: protected: unsigned short CUtlLinkedList<class CClientSendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CClientSendTable __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10168880
// Name: protected: unsigned short CUtlLinkedList<class CRecvDecoder __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CRecvDecoder __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CRecvDecoder *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10168A90
// Name: public: void CUtlLinkedList<class RecvTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class RecvTable __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<unsigned int,unsigned short> *m_pMemory; // eax
  int m_Previous; // edi
  unsigned __int16 *p_m_Next; // edx
  unsigned __int16 v7; // cx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Previous = m_pMemory[elem].m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = v7;
      }
      else
      {
        m_pMemory[m_Previous].m_Next = v7;
        v2 = elem;
      }
      if ( v7 == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[v7].m_Previous = m_Previous;
      *p_m_Next = v2;
      --this->m_ElementCount;
      m_pMemory[elem].m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CC80
// Name: protected: int CUtlLinkedList<class CDTIRecvTable __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CDTIRecvTable __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::AllocInternal(
        CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CDTIRecvTable *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1016D1D0
// Name: public: void CUtlLinkedList<class CDTIRecvTable __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CDTIRecvTable __near *,int>,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::PurgeAndDeleteElements(
        CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int> > *this)
{
  int m_Head; // eax
  int v3; // eax
  CDTIRecvTable *m_Element; // edi
  int m_Next; // ecx
  bool v6; // sf
  CDTIProp *m_pMemory; // eax
  UtlLinkedListElem_t<CDTIRecvTable *,int> *v8; // ecx
  int iNext; // [esp+8h] [ebp-4h]

  m_Head = this->m_Head;
  if ( m_Head != -1 )
  {
    do
    {
      v3 = m_Head;
      m_Element = this->m_Memory.m_pMemory[v3].m_Element;
      m_Next = this->m_Memory.m_pMemory[v3].m_Next;
      iNext = m_Next;
      if ( m_Element != nullptr )
      {
        CUtlVector<CDTIProp,CUtlMemory<CDTIProp,int>>::RemoveAll(this: &m_Element->m_Props);
        if ( m_Element->m_Props.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_Element->m_Props.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_Props.m_Memory.m_pMemory);
            m_Element->m_Props.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Props.m_Memory.m_nAllocationCount = 0;
        }
        v6 = m_Element->m_Props.m_Memory.m_nGrowSize < 0;
        m_pMemory = m_Element->m_Props.m_Memory.m_pMemory;
        m_Element->m_Props.m_pElements = m_pMemory;
        if ( !v6 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            m_Element->m_Props.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Props.m_Memory.m_nAllocationCount = 0;
        }
        v6 = m_Element->m_Name.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Element->m_Name.m_Storage.m_nActualLength = 0;
        if ( !v6 )
        {
          if ( m_Element->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_Name.m_Storage.m_Memory.m_pMemory);
            m_Element->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: m_Element);
        m_Next = iNext;
      }
      m_Head = m_Next;
    }
    while ( m_Next != -1 );
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_Memory.m_pMemory;
  this->m_NumAlloced = 0;
  this->m_FirstFree = -1;
  this->m_LastAlloc.index = -1;
  this->m_pElements = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1016D430
// Name: public: void CUtlLinkedList<class CFrameSnapshot __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CFrameSnapshot __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<unsigned int,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D4A0
// Name: protected: unsigned short CUtlLinkedList<class CDTISendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDTISendTable __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1016DD10
// Name: public: void CUtlLinkedList<class CDTISendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDTISendTable __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  CDTISendTable *m_Element; // esi
  unsigned __int16 m_Next; // bx
  bool v5; // sf
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Element = this->m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
      if ( m_Element != nullptr )
      {
        v5 = m_Element->m_NetTableName.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Element->m_NetTableName.m_Storage.m_nActualLength = 0;
        if ( !v5 )
        {
          if ( m_Element->m_NetTableName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_NetTableName.m_Storage.m_Memory.m_pMemory);
            m_Element->m_NetTableName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_NetTableName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: m_Element);
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = -1;
  m_pMemory = this->m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NumAlloced = -65536;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10171B50
// Name: protected: unsigned short CUtlLinkedList<class RecvTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class RecvTable __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<RecvTable *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10172810
// Name: public: void CUtlLinkedList<class CClientSendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CClientSendTable __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  CClientSendTable *m_Element; // edi
  unsigned __int16 m_Next; // bx
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Element = this->m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
      if ( m_Element != nullptr )
      {
        CClientSendTable::~CClientSendTable(this: m_Element);
        free(pMem: m_Element);
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = -1;
  m_pMemory = this->m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NumAlloced = -65536;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10172D20
// Name: public: void CUtlLinkedList<class CRecvDecoder __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CRecvDecoder __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  unsigned __int16 m_Next; // cx
  CRecvDecoder *m_Element; // esi
  const RecvProp **m_pMemory; // eax
  const RecvProp **v6; // eax
  UtlLinkedListElem_t<CRecvDecoder *,unsigned short> *v7; // ecx
  unsigned __int16 iNext; // [esp+8h] [ebp-4h]

  m_Head = this->m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
      m_Element = this->m_Memory.m_pMemory[m_Head].m_Element;
      iNext = m_Next;
      if ( m_Element != nullptr )
      {
        m_Element->m_DatatableProps.m_Size = 0;
        if ( m_Element->m_DatatableProps.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_Element->m_DatatableProps.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_DatatableProps.m_Memory.m_pMemory);
            m_Element->m_DatatableProps.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = m_Element->m_DatatableProps.m_Memory.m_pMemory;
        m_Element->m_DatatableProps.m_pElements = m_pMemory;
        if ( m_Element->m_DatatableProps.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            m_Element->m_DatatableProps.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
        }
        m_Element->m_Props.m_Size = 0;
        if ( m_Element->m_Props.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_Element->m_Props.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_Props.m_Memory.m_pMemory);
            m_Element->m_Props.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Props.m_Memory.m_nAllocationCount = 0;
        }
        v6 = m_Element->m_Props.m_Memory.m_pMemory;
        m_Element->m_Props.m_pElements = v6;
        if ( m_Element->m_Props.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v6 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
            m_Element->m_Props.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Props.m_Memory.m_nAllocationCount = 0;
        }
        CSendTablePrecalc::~CSendTablePrecalc(this: &m_Element->m_Precalc);
        free(pMem: m_Element);
        m_Next = iNext;
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = -1;
  v7 = this->m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NumAlloced = -65536;
  this->m_pElements = v7;
}

//------------------------------------------------------------------------------
// Address: 0x101A4A30
// Name: protected: unsigned short CUtlLinkedList<class VisCacheEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101A4BC0
// Name: public: void CUtlLinkedList<class VisCacheEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class VisCacheEntry,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4C80
// Name: public: void CUtlLinkedList<class VisCacheEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *this,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v4; // edi
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v5; // eax
  int m_Next; // eax

  if ( elem < this->m_Memory.m_nAllocationCount
    && elem <= this->m_LastAlloc.index
    && this->m_Memory.m_pMemory[elem].m_Previous != elem )
  {
    CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::Unlink(
      this,
      elem);
  }
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v4->m_Next = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    v5 = &this->m_Memory.m_pMemory[after];
    v4->m_Next = v5->m_Next;
    v5->m_Next = elem;
  }
  m_Next = v4->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4F50
// Name: public: void CUtlLinkedList<class VisCacheEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class VisCacheEntry,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *this)
{
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v1; // esi
  unsigned __int16 m_Next; // bx
  unsigned __int16 *m_pMemory; // eax
  unsigned __int16 *v4; // eax
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 m_Head; // ax
  unsigned __int16 i; // [esp+0h] [ebp-8h]
  CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *v8; // [esp+4h] [ebp-4h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    i = this->m_Head;
    if ( i != 0xFFFF )
    {
      do
      {
        v1 = &this->m_Memory.m_pMemory[i];
        m_Next = v1->m_Next;
        v1->m_Element.nodelist.m_Size = 0;
        if ( v1->m_Element.nodelist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v1->m_Element.nodelist.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Element.nodelist.m_Memory.m_pMemory);
            this = v8;
            v1->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v1->m_Element.nodelist.m_Memory.m_pMemory;
        v1->m_Element.nodelist.m_pElements = m_pMemory;
        if ( v1->m_Element.nodelist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            this = v8;
            v1->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
        }
        v1->m_Element.leaflist.m_Size = 0;
        if ( v1->m_Element.leaflist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v1->m_Element.leaflist.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Element.leaflist.m_Memory.m_pMemory);
            this = v8;
            v1->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
        }
        v4 = v1->m_Element.leaflist.m_Memory.m_pMemory;
        v1->m_Element.leaflist.m_pElements = v4;
        if ( v1->m_Element.leaflist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
            this = v8;
            v1->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
        }
        v1->m_Previous = i;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v1->m_Next = m_FirstFree;
        i = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
      this->m_FirstFree = m_Head;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5D70
// Name: protected: unsigned short CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101B6900
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6C90
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8000
// Name: public: unsigned short CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this)
{
  int v2; // edi
  int result; // eax
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v4; // esi

  v2 = (unsigned __int16)CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
    {
      v4->m_Element.m_pChannel = nullptr;
      v4->m_Element.m_Socket = -1;
      CUtlBuffer::CUtlBuffer(this: &v4->m_Element.m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
      CUtlBuffer::CUtlBuffer(this: &v4->m_Element.m_To, growSize: 0, initSize: 0, nFlags: 0);
    }
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B8060
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // di
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v5; // ax
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        if ( v2->m_Element.m_To.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v2->m_Element.m_To.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Element.m_To.m_Memory.m_pMemory);
            this = v6;
            v2->m_Element.m_To.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_To.m_Memory.m_nAllocationCount = 0;
        }
        if ( v2->m_Element.m_Buffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v2->m_Element.m_Buffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Element.m_Buffer.m_Memory.m_pMemory);
            this = v6;
            v2->m_Element.m_Buffer.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_Buffer.m_Memory.m_nAllocationCount = 0;
        }
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D72C0
// Name: protected: int CUtlLinkedList<class CEventInfo,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal(
        CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[7].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[7].m_nBlockSize = 0;
      result[7].m_pNext = nullptr;
    }
    else
    {
      result[7].m_nBlockSize = (int)result;
      result[7].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[8 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[8 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101D9740
// Name: protected: int CUtlLinkedList<class CSpatialEntry,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CSpatialEntry,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal(
        CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D98D0
// Name: protected: int CUtlLinkedList<struct LeafListData_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal(
        CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)this->m_FirstFree;
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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101D9A60
// Name: protected: unsigned short CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocated; // ecx
  int result; // eax
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  int index; // eax
  int v11; // ecx
  unsigned __int8 *v12; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = *(_WORD *)&this->m_Memory.m_MemoryStack.m_pBase[60 * m_FirstFree + 58];
LABEL_27:
    v12 = &this->m_Memory.m_MemoryStack.m_pBase[60 * (unsigned __int16)result];
    if ( multilist )
    {
      *((_WORD *)v12 + 29) = -1;
      *((_WORD *)v12 + 28) = -1;
    }
    else
    {
      *((_WORD *)v12 + 29) = result;
      *((_WORD *)v12 + 28) = result;
    }
    return result;
  }
  m_nAllocated = this->m_Memory.m_nAllocated;
  if ( this->m_LastAlloc.index >= m_nAllocated )
  {
    m_nAllocated = this->m_Memory.m_nAllocated;
    LOWORD(result) = m_nAllocated != 0 ? 0 : -1;
  }
  else
  {
    result = this->m_LastAlloc.index;
    if ( result >= m_nAllocated )
      LOWORD(result) = -1;
    else
      LOWORD(result) = result + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocated )
  {
    m_alignment = this->m_Memory.m_MemoryStack.m_alignment;
    this->m_Memory.m_nAllocated = m_nAllocated + 1;
    v7 = 60;
    if ( m_alignment >= 0x3C )
      v7 = m_alignment;
    v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
    v9 = &this->m_Memory.m_MemoryStack.m_pNextAlloc[v8];
    if ( v9 <= this->m_Memory.m_MemoryStack.m_pCommitLimit
      || CMemoryStack::CommitTo(
           this: &this->m_Memory.m_MemoryStack,
           pNextAlloc: &this->m_Memory.m_MemoryStack.m_pNextAlloc[v8]) != 0 )
    {
      this->m_Memory.m_MemoryStack.m_pNextAlloc = v9;
    }
    index = this->m_LastAlloc.index;
    this->m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)this->m_Memory.m_MemoryStack.m_pBase;
    v11 = this->m_Memory.m_nAllocated;
    if ( index >= v11 )
    {
      v11 = this->m_Memory.m_nAllocated;
      LOWORD(result) = v11 != 0 ? 0 : -1;
    }
    else
    {
      result = this->m_LastAlloc.index;
      LOWORD(result) = result >= v11 ? -1 : result + 1;
    }
    if ( (unsigned __int16)result >= v11 )
    {
      if ( `CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101DA7F0
// Name: public: void CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::EnsureCapacity(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this,
        int num)
{
  int m_nAllocated; // eax
  unsigned int m_alignment; // ecx
  unsigned int v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // edi
  unsigned __int8 *m_pBase; // eax

  m_nAllocated = this->m_Memory.m_nAllocated;
  if ( m_nAllocated >= num )
  {
    this->m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)this->m_Memory.m_MemoryStack.m_pBase;
  }
  else
  {
    this->m_Memory.m_nAllocated = num;
    m_alignment = this->m_Memory.m_MemoryStack.m_alignment;
    v5 = 60 * (num - m_nAllocated);
    if ( v5 <= m_alignment )
      v5 = this->m_Memory.m_MemoryStack.m_alignment;
    v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
    v7 = &this->m_Memory.m_MemoryStack.m_pNextAlloc[v6];
    if ( v7 <= this->m_Memory.m_MemoryStack.m_pCommitLimit
      || CMemoryStack::CommitTo(
           this: &this->m_Memory.m_MemoryStack,
           pNextAlloc: &this->m_Memory.m_MemoryStack.m_pNextAlloc[v6]) != 0 )
    {
      m_pBase = this->m_Memory.m_MemoryStack.m_pBase;
      this->m_Memory.m_MemoryStack.m_pNextAlloc = v7;
      this->m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)m_pBase;
    }
    else
    {
      this->m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)this->m_Memory.m_MemoryStack.m_pBase;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DAD60
// Name: public: void CUtlLinkedList<class CSpatialEntry,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CSpatialEntry,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)m_pBlockHeader
                                                                                     + 12 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[1] + 12 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)&m_pBlockHeader[1].m_nBlockSize
               + 3 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 12 * m_nIndex)
            && *(&m_pBlockHeader[2].m_pNext + 3 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 12 * m_nIndex) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[1].m_nBlockSize + 3 * m_nIndex) = (int)m_pBlockHeader + 12 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[2].m_pNext + 3 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 12 * m_nIndex;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x101DAE30
// Name: public: void CUtlLinkedList<struct LeafListData_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::RemoveAll(
        CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x101DBD90
// Name: public: void CUtlLinkedList<class CSpatialEntry,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CSpatialEntry,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::Purge(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this);
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
// Address: 0x101DBDE0
// Name: public: void CUtlLinkedList<class CSpatialEntry,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CSpatialEntry,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
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
// Address: 0x101DBE70
// Name: public: void CUtlLinkedList<struct LeafListData_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::Purge(
        CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::RemoveAll(this);
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
// Address: 0x101DBEC0
// Name: public: void CUtlLinkedList<struct LeafListData_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::LinkBefore(
        CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
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
// Address: 0x101DD350
// Name: public: void CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this)
{
  unsigned __int16 m_Head; // si
  unsigned __int8 *v2; // edx
  unsigned __int16 v3; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_MemoryStack.m_pBase[60 * m_Head];
        v3 = *((_WORD *)v2 + 29);
        *((_WORD *)v2 + 28) = m_Head;
        if ( v3 == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = v3;
        *((_WORD *)v2 + 29) = m_FirstFree;
        m_Head = v3;
      }
      while ( v3 != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD3D0
// Name: public: void CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::Unlink(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  unsigned __int8 *m_pBase; // esi
  unsigned __int8 *v4; // eax
  int v5; // edi
  unsigned __int16 v6; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocated && elem <= this->m_LastAlloc.index )
  {
    m_pBase = this->m_Memory.m_MemoryStack.m_pBase;
    v4 = &m_pBase[60 * elem];
    if ( *((_WORD *)v4 + 28) != elem )
    {
      v5 = *((unsigned __int16 *)v4 + 28);
      v6 = *((_WORD *)v4 + 29);
      if ( (_WORD)v5 == 0xFFFF )
      {
        this->m_Head = v6;
      }
      else
      {
        *(_WORD *)&m_pBase[60 * v5 + 58] = v6;
        v2 = elem;
      }
      if ( v6 == 0xFFFF )
        this->m_Tail = *((_WORD *)v4 + 28);
      else
        *(_WORD *)&this->m_Memory.m_MemoryStack.m_pBase[60 * v6 + 56] = *((_WORD *)v4 + 28);
      *((_WORD *)v4 + 29) = v2;
      *((_WORD *)v4 + 28) = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDDF0
// Name: public: void CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::LinkBefore(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  unsigned __int8 *m_pBase; // edx
  unsigned __int8 *v5; // ecx
  unsigned __int16 m_Tail; // ax

  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::Unlink(
    this,
    elem);
  m_pBase = this->m_Memory.m_MemoryStack.m_pBase;
  v5 = &m_pBase[60 * elem];
  *((_WORD *)v5 + 29) = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    *((_WORD *)v5 + 28) = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = *(_WORD *)&m_pBase[60 * before + 56];
    *((_WORD *)v5 + 28) = m_Tail;
    *(_WORD *)&m_pBase[60 * before + 56] = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    *(_WORD *)&m_pBase[60 * m_Tail + 58] = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E65D0
// Name: protected: unsigned short CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlString,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101E6830
// Name: public: void CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlString,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E68C0
// Name: public: void CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlString,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlString,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlString,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6950
// Name: public: void CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  bool v2; // sf
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<CUtlString,unsigned short> *v4; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v6; // ax
  CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *v7; // [esp+0h] [ebp-4h]

  v7 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = this->m_Memory.m_pMemory[m_Head].m_Element.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
        v4 = &this->m_Memory.m_pMemory[m_Head];
        v4->m_Element.m_Storage.m_nActualLength = 0;
        if ( !v2 )
        {
          if ( v4->m_Element.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_Storage.m_Memory.m_pMemory);
            this = v7;
            v4->m_Element.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Element.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v4->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v4->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v6 = this->m_Head;
    if ( v6 != 0xFFFF )
      this->m_FirstFree = v6;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6A10
// Name: public: void CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Remove(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  bool v3; // sf
  UtlLinkedListElem_t<CUtlString,unsigned short> *v4; // esi

  CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  v3 = this->m_Memory.m_pMemory[elem].m_Element.m_Storage.m_Memory.m_nGrowSize < 0;
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Element.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( v4->m_Element.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_Storage.m_Memory.m_pMemory);
      v4->m_Element.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v4->m_Element.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v4->m_Next = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x101EE3F0
// Name: Test_RandomChance
// Source: json
//------------------------------------------------------------------------------
void __usercall Test_RandomChance(int a1@<esi>, const CCommand *args)
{
  const char *v3; // eax
  IUniformRandomStream *v4; // ecx
  vgui::CTreeViewListControl *v5; // ecx
  int m_nArgc; // eax
  int v7; // esi
  const char **v8; // ebx
  const char *v9; // eax
  ECommandTarget_t TraceType; // eax
  char pDest[8]; // [esp+Ch] [ebp-400h] BYREF
  float v12; // [esp+414h] [ebp+8h]

  if ( args->m_nArgc < 3 )
    _Error(a1: "Test_RandomChance: requires percentage chance parameter (0-100) followed by command to execute.");
  v3 = defaultValue;
  if ( args->m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  v12 = atof(nptr: v3);
  if ( (double)v12 > _RandomFloat(this: v4, a2: 0.0, a3: 100.0) )
  {
    m_nArgc = args->m_nArgc;
    *(_DWORD *)pDest = a1;
    v7 = 2;
    pDest[0] = 0;
    if ( m_nArgc > 2 )
    {
      v8 = &args->m_ppArgv[2];
      do
      {
        if ( v7 < 0 || v7 >= m_nArgc )
          v9 = defaultValue;
        else
          v9 = *v8;
        V_strncat(pDest, pSrc: v9, destBufferSize: 0x400u, max_chars_to_copy: -1);
        V_strncat(pDest, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
        m_nArgc = args->m_nArgc;
        ++v7;
        ++v8;
      }
      while ( v7 < args->m_nArgc );
    }
    TraceType = CTraceFilter::GetTraceType(this: v5);
    Cbuf_InsertText(eTarget: TraceType, pText: pDest, nTickDelay: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE4D0
// Name: Test_SendKey
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_SendKey(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    Sys_TestSendKey(pKey: v1);
  }
  else
  {
    _Error(a1: "Test_SendKey: requires key to send.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE510
// Name: void Test_Wait(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_Wait(const CCommand *args)
{
  const char *v1; // eax
  CStatTime *v2; // ecx
  float flSeconds; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    flSeconds = atof(nptr: v1);
    g_TestScriptMgr.m_WaitUntil = _Plat_FloatTime(this: v2) + flSeconds;
  }
  else
  {
    _Error(a1: "Test_Wait: requires seconds parameter.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE560
// Name: private: void CTestScriptMgr::RunCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::RunCommands(CTestScriptMgr *this)
{
  int v2; // ebx
  vgui::CTreeViewListControl *v3; // ecx
  char v4; // al
  ECommandTarget_t TraceType; // eax
  void *m_hFile; // [esp-20h] [ebp-230h]
  char *p_tempVal; // [esp-1Ch] [ebp-22Ch]
  char curCommand[515]; // [esp+Ch] [ebp-204h] BYREF
  char tempVal; // [esp+20Fh] [ebp-1h] BYREF

  while ( this->m_WaitUntil <= _Plat_FloatTime((CStatTime *)this) && this->m_NextCheckPoint[0] == 0 )
  {
    v2 = 0;
    tempVal = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &curCommand[v2], a3: 1, a4: this->m_hFile);
        v4 = curCommand[v2];
        if ( v4 == 47 )
          break;
        tempVal = 0;
        if ( v4 == 59 || v4 == 10 || g_pFileSystem->EndOfFile(this: g_pFileSystem, a2: this->m_hFile) )
          goto LABEL_15;
        ++v2;
      }
      if ( tempVal != 0 )
        break;
      tempVal = 1;
      ++v2;
    }
    tempVal = 0;
    do
    {
      if ( g_pFileSystem->EndOfFile(this: g_pFileSystem, a2: this->m_hFile) )
        break;
      p_tempVal = &tempVal;
      ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Read)(a1: &g_pFileSystem->IBaseFileSystem);
    }
    while ( tempVal != 10 );
    --v2;
LABEL_15:
    curCommand[v2] = 0;
    if ( curCommand[0] != 0 )
    {
      if ( testscript_debug.m_pParent != nullptr && testscript_debug.m_pParent->m_Value.m_nValue != 0 )
        _Msg(a1: "Executing command from script: %s\n", curCommand);
      TraceType = CTraceFilter::GetTraceType(this: v3);
      Cbuf_AddText(eTarget: TraceType, pText: curCommand, nTickDelay: 0);
      Cbuf_Execute();
    }
    else
    {
      m_hFile = this->m_hFile;
      if ( ((unsigned __int8 (__thiscall *)(IFileSystem *))g_pFileSystem->EndOfFile)(a1: g_pFileSystem) != 0 )
      {
        CLoaderMemAlloc::CrtIsValidPointer(
          this: (ConVar *)&testscript_running.IConVar,
          value: 0,
          a2: (unsigned int)m_hFile,
          a3: (int)p_tempVal);
        if ( this->m_hFile != nullptr )
        {
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
          this->m_hFile = nullptr;
        }
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE6D0
// Name: public: bool CTestScriptMgr::StartTestScript(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTestScriptMgr::StartTestScript(CTestScriptMgr *this, const char *pFilename)
{
  void *v3; // eax
  unsigned int v5; // [esp+0h] [ebp-204h]
  char fullName[512]; // [esp+4h] [ebp-200h] BYREF

  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&testscript_running.IConVar,
    value: 0,
    a2: v5,
    a3: *(int *)fullName);
  if ( this->m_hFile != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
    this->m_hFile = nullptr;
  }
  V_snprintf(pDest: fullName, maxLen: 512, pFormat: "testscripts\\%s", pFilename);
  v3 = (void *)((int (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Open)(a1: &g_pFileSystem->IBaseFileSystem);
  this->m_hFile = v3;
  if ( v3 == nullptr )
    return 0;
  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&testscript_running.IConVar,
    value: 1,
    a2: (unsigned int)fullName,
    a3: (int)"rt");
  CTestScriptMgr::RunCommands(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EE770
// Name: protected: int CUtlLinkedList<class CLoopInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CLoopInfo __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AllocInternal(
        CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CLoopInfo *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x101EE8A0
// Name: Test_StartScript
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_StartScript(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    if ( CTestScriptMgr::StartTestScript(this: &g_TestScriptMgr, pFilename: v1) == 0 )
    {
      v2 = defaultValue;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      _Warning(a1: "Error starting testscript '%s'\n", v2);
    }
  }
  else
  {
    _Warning(a1: "Test_StartScript: requires filename of script to start (file must be under testscripts directory).\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE900
// Name: private: class CLoopInfo __near * CTestScriptMgr::FindLoop(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLoopInfo *__thiscall CTestScriptMgr::FindLoop(CTestScriptMgr *this, const char *pLoopName)
{
  int m_Head; // edi

  m_Head = this->m_Loops.m_Head;
  if ( m_Head == -1 )
    return nullptr;
  while ( _V_stricmp(s1: pLoopName, s2: this->m_Loops.m_Memory.m_pMemory[m_Head].m_Element->m_Name) != 0 )
  {
    m_Head = this->m_Loops.m_Memory.m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      return nullptr;
  }
  return this->m_Loops.m_Memory.m_pMemory[m_Head].m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x101EE960
// Name: private: void CTestScriptMgr::LoopCount(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::LoopCount(CTestScriptMgr *this, const char *pLoopName, int nTimes)
{
  CLoopInfo *Loop; // esi
  int m_ListIndex; // edi

  if ( this->m_hFile == nullptr )
    _Error(a1: "CTestScriptMgr: not initialized.");
  Loop = CTestScriptMgr::FindLoop(this, pLoopName);
  if ( Loop == nullptr )
    _Error(a1: "CTestScriptMgr::LoopCount( %s ): no loop with this name exists.", pLoopName);
  if ( ++Loop->m_nCount < nTimes || nTimes == -1 )
  {
    _Msg(a1: "Performing loop to %s (%d iterations)\n", pLoopName, Loop->m_nCount);
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: this->m_hFile,
      a3: Loop->m_iNextCommandPos,
      a4: FILESYSTEM_SEEK_HEAD);
  }
  else
  {
    m_ListIndex = Loop->m_ListIndex;
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Loops,
      elem: m_ListIndex);
    this->m_Loops.m_Memory.m_pMemory[m_ListIndex].m_Next = this->m_Loops.m_FirstFree;
    this->m_Loops.m_FirstFree = m_ListIndex;
    free(pMem: Loop);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEA10
// Name: private: void CTestScriptMgr::LoopForNumSeconds(char const __near *,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::LoopForNumSeconds(CTestScriptMgr *this, const char *pLoopName, double nSeconds)
{
  CStatTime *v4; // ecx
  CLoopInfo *Loop; // esi
  int m_ListIndex; // edi

  if ( this->m_hFile == nullptr )
    _Error(a1: "CTestScriptMgr: not initialized.");
  Loop = CTestScriptMgr::FindLoop(this, pLoopName);
  if ( Loop == nullptr )
    _Error(a1: "CTestScriptMgr::LoopForNumSeconds( %s ): no loop with this name exists.", pLoopName);
  if ( nSeconds <= _Plat_FloatTime(this: v4) - Loop->m_flStartTime )
  {
    m_ListIndex = Loop->m_ListIndex;
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Loops,
      elem: m_ListIndex);
    this->m_Loops.m_Memory.m_pMemory[m_ListIndex].m_Next = this->m_Loops.m_FirstFree;
    this->m_Loops.m_FirstFree = m_ListIndex;
    free(pMem: Loop);
  }
  else
  {
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: this->m_hFile,
      a3: Loop->m_iNextCommandPos,
      a4: FILESYSTEM_SEEK_HEAD);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEAB0
// Name: public: void CTestScriptMgr::SetWaitCheckPoint(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::SetWaitCheckPoint(CTestScriptMgr *this, const char *pCheckPointName, bool bOnce)
{
  const char *v4; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  if ( testscript_debug.m_pParent != nullptr
    && testscript_debug.m_pParent->m_Value.m_nValue != 0
    && _V_stricmp(s1: pCheckPointName, s2: "frame_end") != 0 )
  {
    v4 = " (once).";
    if ( !bOnce )
      v4 = ".";
    _Msg(a1: "TESTSCRIPT: waiting for checkpoint '%s'%s\n", pCheckPointName, v4);
  }
  if ( !bOnce
    || pCheckPointName == nullptr
    || (search.key = pCheckPointName,
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
          this: &this->m_CheckPointsHit.m_Elements.m_Tree,
          &search) == -1) )
  {
    V_strncpy(pDest: this->m_NextCheckPoint, pSrc: pCheckPointName, maxLen: 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEB40
// Name: public: int CUtlLinkedList<class CLoopInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CLoopInfo __near *,int>,int>>::AddToTail(class CLoopInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AddToTail(
        CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int> > *this,
        CLoopInfo **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<CLoopInfo *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CLoopInfo *,int> *v8; // esi

  result = CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x101EEBB0
// Name: void Test_RunFrame(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_RunFrame()
{
  if ( testscript_debug.m_pParent != nullptr
    && testscript_debug.m_pParent->m_Value.m_nValue != 0
    && _V_stricmp(s1: "frame_end", s2: "frame_end") != 0 )
  {
    _Msg(a1: "TESTSCRIPT: waiting for checkpoint '%s'%s\n", "frame_end", ".");
  }
  V_strncpy(pDest: g_TestScriptMgr.m_NextCheckPoint, pSrc: "frame_end", maxLen: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101EEC10
// Name: void Test_WaitForCheckPoint(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_WaitForCheckPoint(const CCommand *args)
{
  int m_nArgc; // eax
  bool v3; // cc
  const char *v4; // eax
  const char *v5; // eax
  bool bOnce; // [esp+Ch] [ebp+8h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    if ( m_nArgc < 3 )
      goto LABEL_7;
    v3 = m_nArgc <= 2;
    v4 = defaultValue;
    if ( !v3 )
      v4 = args->m_ppArgv[2];
    bOnce = true;
    if ( _V_stricmp(s1: v4, s2: "once") != 0 )
LABEL_7:
      bOnce = false;
    v5 = defaultValue;
    if ( args->m_nArgc > 1 )
      v5 = args->m_ppArgv[1];
    CTestScriptMgr::SetWaitCheckPoint(this: &g_TestScriptMgr, pCheckPointName: v5, bOnce);
  }
  else
  {
    _Error(a1: "Test_WaitForCheckPoint <checkpoint name> [once]: requires checkpoint name.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEC80
// Name: void Test_LoopCount(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_LoopCount(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // ecx
  const char *v3; // esi
  int v4; // eax

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 3 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    v3 = defaultValue;
    if ( m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = atoi(nptr: v2);
    CTestScriptMgr::LoopCount(this: &g_TestScriptMgr, pLoopName: v3, nTimes: v4);
  }
  else
  {
    _Error(a1: "Test_LoopCount: requires a loop name and number of times to loop.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EECE0
// Name: void Test_Loop(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_Loop(const CCommand *args)
{
  const char *v1; // edi
  CLoopInfo *Loop; // esi

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    if ( g_TestScriptMgr.m_hFile == nullptr )
      _Error(a1: "CTestScriptMgr: not initialized.");
    Loop = CTestScriptMgr::FindLoop(this: &g_TestScriptMgr, pLoopName: v1);
    if ( Loop == nullptr )
      _Error(a1: "CTestScriptMgr::LoopCount( %s ): no loop with this name exists.", v1);
    _Msg(a1: "Performing loop to %s (%d iterations)\n", v1, ++Loop->m_nCount);
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: g_TestScriptMgr.m_hFile,
      a3: Loop->m_iNextCommandPos,
      a4: FILESYSTEM_SEEK_HEAD);
  }
  else
  {
    _Error(a1: "Test_Loop: requires a loop name.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EED80
// Name: void Test_LoopForNumSeconds(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_LoopForNumSeconds(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // ecx
  const char *v3; // esi
  double v4; // st7

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 3 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    v3 = defaultValue;
    if ( m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = atof(nptr: v2);
    CTestScriptMgr::LoopForNumSeconds(this: &g_TestScriptMgr, pLoopName: v3, nSeconds: v4);
  }
  else
  {
    _Error(a1: "Test_LoopLoopForNumSeconds: requires a loop name and number of seconds to loop.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEDE0
// Name: private: void CTestScriptMgr::StartLoop(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::StartLoop(CTestScriptMgr *this, CLoopInfo *pLoopName)
{
  const char *v3; // ebx
  CLoopInfo *v4; // esi
  CStatTime *v5; // ecx

  if ( this->m_hFile == nullptr )
    _Error(a1: "CTestScriptMgr: not initialized.");
  v3 = (const char *)pLoopName;
  if ( CTestScriptMgr::FindLoop(this, (const char *)pLoopName) != nullptr )
    _Error(a1: "CTestScriptMgr::StartLoop( %s ): loop already exists.", v3);
  v4 = (CLoopInfo *)MemAlloc_Alloc(nSize: 0x58u);
  pLoopName = v4;
  V_strncpy(pDest: v4->m_Name, pSrc: v3, maxLen: 64);
  v4->m_nCount = 0;
  v4->m_flStartTime = _Plat_FloatTime(this: v5);
  v4->m_iNextCommandPos = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
  v4->m_ListIndex = CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AddToTail(
                      this: &this->m_Loops,
                      src: &pLoopName);
}

//------------------------------------------------------------------------------
// Address: 0x101EEE70
// Name: void Test_StartLoop(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_StartLoop(const CCommand *args)
{
  char *v1; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = (char *)defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = (char *)args->m_ppArgv[1];
    CTestScriptMgr::StartLoop(this: &g_TestScriptMgr, pLoopName: (CLoopInfo *)v1);
  }
  else
  {
    _Error(a1: "Test_StartLoop: requires a loop name.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEEB0
// Name: public: CTestScriptMgr::CTestScriptMgr(void)
// Source: json
//------------------------------------------------------------------------------
CTestScriptMgr *__thiscall CTestScriptMgr::CTestScriptMgr(CTestScriptMgr *this)
{
  UtlLinkedListElem_t<CLoopInfo *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // ecx

  this->__vftable = (CTestScriptMgr_vtbl *)&CTestScriptMgr::`vftable';
  this->m_Loops.m_Memory.m_pMemory = nullptr;
  this->m_Loops.m_Memory.m_nAllocationCount = 0;
  this->m_Loops.m_Memory.m_nGrowSize = 0;
  this->m_Loops.m_LastAlloc.index = -1;
  m_pMemory = this->m_Loops.m_Memory.m_pMemory;
  this->m_Loops.m_Head = -1;
  this->m_Loops.m_Tail = -1;
  this->m_Loops.m_FirstFree = -1;
  this->m_Loops.m_ElementCount = 0;
  this->m_Loops.m_NumAlloced = 0;
  this->m_Loops.m_pElements = m_pMemory;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_Root = -1;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_NumElements = 0;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_LastAlloc.index = -1;
  v3 = this->m_CheckPointsHit.m_Elements.m_Tree.m_Elements.m_pMemory;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_pElements = v3;
  if ( this->m_CheckPointsHit.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_CheckPointsHit.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_hFile = nullptr;
  this->m_NextCheckPoint[0] = 0;
  this->m_WaitUntil = _Plat_FloatTime(this: (CStatTime *)v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EEF20
// Name: public: virtual CTestScriptMgr::~CTestScriptMgr(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CTestScriptMgr::~CTestScriptMgr(CTestScriptMgr *this)
{
  unsigned int v2; // [esp-4h] [ebp-8h]
  int v3; // [esp+0h] [ebp-4h]

  this->__vftable = (CTestScriptMgr_vtbl *)&CTestScriptMgr::`vftable';
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&testscript_running.IConVar, value: 0, a2: v2, a3: v3);
  if ( this->m_hFile != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
    this->m_hFile = nullptr;
  }
  CUtlDict<int,int>::RemoveAll(this: &this->m_CheckPointsHit);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &this->m_CheckPointsHit.m_Elements.m_Tree);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Loops);
  if ( this->m_Loops.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Loops.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Loops.m_Memory.m_pMemory);
      this->m_Loops.m_Memory.m_pMemory = nullptr;
    }
    this->m_Loops.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEFE0
// Name: public: void CTestScriptMgr::CheckPoint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::CheckPoint(CTestScriptMgr *this, const char *pName)
{
  const char *v3; // ebx

  if ( this->m_hFile != nullptr && this->m_WaitUntil <= _Plat_FloatTime((CStatTime *)this) )
  {
    v3 = pName;
    if ( testscript_debug.m_pParent != nullptr
      && testscript_debug.m_pParent->m_Value.m_nValue != 0
      && _V_stricmp(s1: pName, s2: "frame_end") != 0 )
    {
      _Msg(a1: "TESTSCRIPT: CheckPoint -> '%s'.\n", v3);
    }
    pName = nullptr;
    CUtlDict<int,int>::Insert(this: &this->m_CheckPointsHit, pName: v3, element: (const int *)&pName);
    if ( this->m_NextCheckPoint[0] == 0 || _V_stricmp(s1: this->m_NextCheckPoint, s2: v3) == 0 )
    {
      this->m_NextCheckPoint[0] = 0;
      CTestScriptMgr::RunCommands(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276B90
// Name: protected: int CUtlLinkedList<struct CCommandBuffer::Command_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal(
        CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 16);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 12) = 0;
    }
    else
    {
      *(_DWORD *)(result + 16) = result;
      *(_DWORD *)(result + 12) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
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
    CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
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
      if ( `CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)((char *)v8 + 20 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 20 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10276DB0
// Name: public: void CUtlLinkedList<struct CCommandBuffer::Command_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::RemoveAll(
        CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *this)
{
  CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

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
          i = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(this: &v1->m_Memory, &result, &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)((char *)m_pBlockHeader + 20 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[1] + 20 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t **)&m_pBlockHeader[2].m_nBlockSize
               + 5 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex)
            && *(&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex) )
          {
            v1 = (CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[2].m_nBlockSize + 5 * m_nIndex) = (int)m_pBlockHeader + 20 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 20 * m_nIndex;
            v1 = (CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *)v5;
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
// Address: 0x10276E80
// Name: public: void CUtlLinkedList<struct CCommandBuffer::Command_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::LinkBefore(
        CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 12);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v5 = *(_DWORD *)(elem + 16);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 12);
    *(_DWORD *)(before + 12) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 12) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 16) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276F10
// Name: public: void CUtlLinkedList<struct CCommandBuffer::Command_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::Free(
        CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 12);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v4 = *(_DWORD *)(elem + 16);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x10277680
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102776F0
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10277870
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277AD0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ACC10
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x102AD250
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102AF8F0
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x102B4B70
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102B4CD0
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102B65D0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
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
// Address: 0x102B7050
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B70D0
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
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
// Address: 0x102B76A0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B84B0
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x102B8520
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B89C0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1660
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102C2E30
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x102C5A00
// Name: protected: int CUtlLinkedList<int,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<int,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal(
        CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<int,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102C6090
// Name: public: int CUtlLinkedList<int,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<int,int>,int>>::AddToHead(int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AddToHead(
        CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > *this,
        int *src)
{
  int result; // eax
  int v4; // esi
  UtlLinkedListElem_t<int,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Next; // eax
  UtlLinkedListElem_t<int,int> *v8; // edi

  result = CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    if ( result >= 0
      && result < this->m_Memory.m_nAllocationCount
      && result <= this->m_LastAlloc.index
      && this->m_Memory.m_pMemory[result].m_Previous != result )
    {
      CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
        elem: result);
    }
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Previous = -1;
    m_pMemory[v6].m_Next = this->m_Head;
    this->m_Head = v4;
    m_Next = m_pMemory[v4].m_Next;
    if ( m_Next == -1 )
      this->m_Tail = v4;
    else
      this->m_Memory.m_pMemory[m_Next].m_Previous = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6120
// Name: public: int CUtlLinkedList<int,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<int,int>,int>>::AddToTail(int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AddToTail(
        CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > *this,
        int *src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<int,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<int,int> *v8; // esi

  result = CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x102C80E0
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
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
// Address: 0x102CDED0
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102E3180
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
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
    CUtlMemory<CPortalRect,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102E32B0
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
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
// Address: 0x1031E220
// Name: _dynamic_initializer_for__testscript_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__testscript_debug__()
{
  ConVar::ConVar(
    this: &testscript_debug,
    pName: "testscript_debug",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Debug test scripts.");
  return atexit(func: dynamic_atexit_destructor_for__testscript_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E250
// Name: _dynamic_initializer_for__testscript_running__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__testscript_running__()
{
  ConVar::ConVar(
    this: &testscript_running,
    pName: "testscript_running",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to true when test scripts are running");
  return atexit(func: dynamic_atexit_destructor_for__testscript_running__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E280
// Name: _dynamic_initializer_for__Test_Wait_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_Wait_command__()
{
  ConCommand::ConCommand(
    this: &Test_Wait_command,
    pName: "Test_Wait",
    callback: (void (__cdecl *)())Test_Wait,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_Wait_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E2B0
// Name: _dynamic_initializer_for__Test_RunFrame_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_RunFrame_command__()
{
  ConCommand::ConCommand(
    this: &Test_RunFrame_command,
    pName: "Test_RunFrame",
    callback: Test_RunFrame,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_RunFrame_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E2E0
// Name: _dynamic_initializer_for__Test_WaitForCheckPoint_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_WaitForCheckPoint_command__()
{
  ConCommand::ConCommand(
    this: &Test_WaitForCheckPoint_command,
    pName: "Test_WaitForCheckPoint",
    callback: (void (__cdecl *)())Test_WaitForCheckPoint,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_WaitForCheckPoint_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E310
// Name: _dynamic_initializer_for__Test_StartLoop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_StartLoop_command__()
{
  ConCommand::ConCommand(
    this: &Test_StartLoop_command,
    pName: "Test_StartLoop",
    callback: (void (__cdecl *)())Test_StartLoop,
    pHelpString: "Test_StartLoop <loop name> - Denote the start of a loop. Really just defines a named point you can jump to.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_StartLoop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E340
// Name: _dynamic_initializer_for__Test_LoopCount_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_LoopCount_command__()
{
  ConCommand::ConCommand(
    this: &Test_LoopCount_command,
    pName: "Test_LoopCount",
    callback: (void (__cdecl *)())Test_LoopCount,
    pHelpString: "Test_LoopCount <loop name> <count> - loop back to the specified loop start point the specified # of times.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_LoopCount_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E370
// Name: _dynamic_initializer_for__Test_Loop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_Loop_command__()
{
  ConCommand::ConCommand(
    this: &Test_Loop_command,
    pName: "Test_Loop",
    callback: (void (__cdecl *)())Test_Loop,
    pHelpString: "Test_Loop <loop name> - loop back to the specified loop start point unconditionally.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_Loop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E3A0
// Name: _dynamic_initializer_for__Test_LoopForNumSeconds_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_LoopForNumSeconds_command__()
{
  ConCommand::ConCommand(
    this: &Test_LoopForNumSeconds_command,
    pName: "Test_LoopForNumSeconds",
    callback: (void (__cdecl *)())Test_LoopForNumSeconds,
    pHelpString: "Test_LoopForNumSeconds <loop name> <time> - loop back to the specified start point for the specified # of seconds.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E3D0
// Name: _dynamic_initializer_for__Test_RandomChance_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_RandomChance_command__()
{
  ConCommand::ConCommand(
    this: &Test_RandomChance_command,
    pName: "Test_RandomChance",
    callback: (void (__cdecl *)())Test_RandomChance,
    pHelpString: "Test_RandomChance <percent chance, 0-100> <token1> <token2...> - Roll the dice and maybe run the command following t"
    "he percentage chance.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_RandomChance_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E400
// Name: _dynamic_initializer_for__Test_SendKey_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_SendKey_command__()
{
  ConCommand::ConCommand(
    this: &Test_SendKey_command,
    pName: "Test_SendKey",
    callback: (void (__cdecl *)())Test_SendKey,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_SendKey_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E430
// Name: _dynamic_initializer_for__Test_StartScript_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_StartScript_command__()
{
  ConCommand::ConCommand(
    this: &Test_StartScript_command,
    pName: "Test_StartScript",
    callback: (void (__cdecl *)())Test_StartScript,
    pHelpString: "Start a test script running..",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_StartScript_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326C90
// Name: _dynamic_atexit_destructor_for__testscript_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__testscript_debug__()
{
  ConVar::~ConVar(this: &testscript_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10326CA0
// Name: _dynamic_atexit_destructor_for__testscript_running__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__testscript_running__()
{
  ConVar::~ConVar(this: &testscript_running);
}

//------------------------------------------------------------------------------
// Address: 0x10326CB0
// Name: _dynamic_atexit_destructor_for__Test_Wait_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_Wait_command__()
{
  ConCommand::~ConCommand(this: &Test_Wait_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326CC0
// Name: _dynamic_atexit_destructor_for__Test_RunFrame_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_RunFrame_command__()
{
  ConCommand::~ConCommand(this: &Test_RunFrame_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326CD0
// Name: _dynamic_atexit_destructor_for__Test_WaitForCheckPoint_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_WaitForCheckPoint_command__()
{
  ConCommand::~ConCommand(this: &Test_WaitForCheckPoint_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326CE0
// Name: _dynamic_atexit_destructor_for__Test_StartLoop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_StartLoop_command__()
{
  ConCommand::~ConCommand(this: &Test_StartLoop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326CF0
// Name: _dynamic_atexit_destructor_for__Test_LoopCount_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_LoopCount_command__()
{
  ConCommand::~ConCommand(this: &Test_LoopCount_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326D00
// Name: _dynamic_atexit_destructor_for__Test_Loop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_Loop_command__()
{
  ConCommand::~ConCommand(this: &Test_Loop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326D10
// Name: _dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__()
{
  ConCommand::~ConCommand(this: &Test_LoopForNumSeconds_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326D20
// Name: _dynamic_atexit_destructor_for__Test_RandomChance_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_RandomChance_command__()
{
  ConCommand::~ConCommand(this: &Test_RandomChance_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326D30
// Name: _dynamic_atexit_destructor_for__Test_SendKey_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_SendKey_command__()
{
  ConCommand::~ConCommand(this: &Test_SendKey_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326D40
// Name: _dynamic_atexit_destructor_for__Test_StartScript_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_StartScript_command__()
{
  ConCommand::~ConCommand(this: &Test_StartScript_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031E460
// Name: _dynamic_initializer_for__g_InitTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_InitTracker__()
{
  int v0; // edx
  int *p_m_nGrowSize; // eax

  v0 = 3;
  p_m_nGrowSize = &g_InitTracker.m_Funcs[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v0;
  }
  while ( v0 >= 0 );
  g_InitTracker.m_nNumFuncs[0] = 0;
  g_InitTracker.m_nNumFuncs[1] = 0;
  g_InitTracker.m_nNumFuncs[2] = 0;
  g_InitTracker.m_nNumFuncs[3] = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_InitTracker__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E4B0
// Name: _dynamic_initializer_for____g_CVoiceServer_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CVoiceServer_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CVoiceServer_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E4C0
// Name: _dynamic_initializer_for____g_CreateCVoiceServerIVoiceServer_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVoiceServerIVoiceServer_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVoiceServerIVoiceServer_reg,
           fn: (void *(__cdecl *)())_CreateCVoiceServerIVoiceServer_interface,
           pName: "VoiceServer002");
}

//------------------------------------------------------------------------------
// Address: 0x10326D50
// Name: _dynamic_atexit_destructor_for__g_TestScriptMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TestScriptMgr__()
{
  CTestScriptMgr::~CTestScriptMgr(this: &g_TestScriptMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10326D60
// Name: _dynamic_atexit_destructor_for__g_InitTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_InitTracker__()
{
  CInitTracker::~CInitTracker(this: &g_InitTracker);
}

//------------------------------------------------------------------------------
// Address: 0x10326D70
// Name: _dynamic_atexit_destructor_for____g_CVoiceServer_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_CVoiceServer_singleton__()
{
  _g_CVoiceServer_singleton.__vftable = (CVoiceServer_vtbl *)&IVoiceServer::`vftable';
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10038220
// Name: protected: unsigned short CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10038510
// Name: protected: int CUtlLinkedList<struct CAsyncWavDataCache::StreamedEntry_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *m_pMemory; // ecx
  int v10; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result << 6;
    if ( multilist )
    {
      *(int *)((char *)&m_pMemory->m_Next + v10) = -1;
      *(int *)((char *)&m_pMemory->m_Previous + v10) = -1;
    }
    else
    {
      *(int *)((char *)&m_pMemory->m_Next + v10) = result;
      *(int *)((char *)&m_pMemory->m_Previous + v10) = result;
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
    CUtlMemory<maplist_map_t,int>::Grow((CUtlMemory<VMatrix,int> *)this, num: 1);
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
      if ( `CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x100394F0
// Name: public: void CUtlLinkedList<struct CAsyncWavDataCache::StreamedEntry_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CAsyncWavDataCache::StreamedEntry_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
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
// Address: 0x1003A3D0
// Name: public: void CUtlLinkedList<struct CAsyncWavDataCache::StreamedEntry_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CAsyncWavDataCache::StreamedEntry_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::Unlink(
        CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v2; // eax
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
// Address: 0x1003B910
// Name: public: unsigned short CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AddToTail(unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this,
        unsigned int *src)
{
  int v3; // esi
  int result; // eax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v5; // eax

  v3 = (unsigned __int16)CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v3);
    v5 = &this->m_Memory.m_pMemory[v3];
    if ( v5 != nullptr )
      v5->m_Element = *src;
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100649B0
// Name: protected: unsigned short CUtlLinkedList<struct CBrushBatchRender::brushrender_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBrushBatchRender::brushrender_t __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100874C0
// Name: public: void CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<unsigned short,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CE30
// Name: public: void CUtlLinkedList<class CEventInfo,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::RemoveAll(
        CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[8 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[8 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[8 * m_nIndex + 8].m_pNext == &m_pBlockHeader[8 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)m_pBlockHeader[8 * m_nIndex + 8].m_nBlockSize != &m_pBlockHeader[8 * m_nIndex + 1] )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)p_m_Memory;
          }
          else
          {
            if ( m_pBlockHeader[8 * m_nIndex + 3].m_nBlockSize != 0 )
              free(pMem: (void *)m_pBlockHeader[8 * m_nIndex + 3].m_nBlockSize);
            CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&m_pBlockHeader[8 * m_nIndex + 5].m_nBlockSize);
            v5 = p_m_Memory;
            m_pBlockHeader[8 * m_nIndex + 4].m_nBlockSize = (int)&IRecipientFilter::`vftable';
            m_pBlockHeader[8 * m_nIndex + 8].m_pNext = &m_pBlockHeader[8 * m_nIndex + 1];
            m_pBlockHeader[8 * m_nIndex + 8].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[8 * m_nIndex + 1];
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x1008CF20
// Name: public: void CUtlLinkedList<class CEventInfo,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::Free(
        CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 56);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 60) = *(_DWORD *)(elem + 60);
      else
        this->m_Head = *(_DWORD *)(elem + 60);
      v4 = *(_DWORD *)(elem + 60);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 56) = *(_DWORD *)(elem + 56);
      else
        this->m_Tail = *(_DWORD *)(elem + 56);
      *(_DWORD *)(elem + 60) = elem;
      *(_DWORD *)(elem + 56) = elem;
      --this->m_ElementCount;
    }
  }
  if ( *(_DWORD *)(elem + 20) != 0 )
    free(pMem: *(void **)(elem + 20));
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)(elem + 36));
  *(_DWORD *)(elem + 28) = &IRecipientFilter::`vftable';
  *(_DWORD *)(elem + 60) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x100BDE00
// Name: protected: int CUtlLinkedList<struct decal_t __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct decal_t __near *,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BDF90
// Name: public: void CUtlLinkedList<class CDispShadowDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowDecal,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v2; // ax
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v3; // edx
  CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>::Iterator_t it; // [esp+0h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v2;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        ++v2;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
        it.index = v2;
      }
      while ( v2 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE050
// Name: protected: unsigned short CUtlLinkedList<class CDispShadowDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100BE1E0
// Name: public: void CUtlLinkedList<class CDispShadowFragment,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowFragment,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v3; // si
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v5; // edi
  CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>::Iterator_t it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v3;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        v4 = v3;
        if ( v3 < this->m_Memory.m_nAllocationCount && v3 <= index )
        {
          v5 = &this->m_Memory.m_pMemory[v3];
          if ( v5->m_Previous != v3 || v5->m_Next == v3 )
          {
            free(pMem: v5->m_Element.m_ShadowVerts);
            v4 = v3;
            v5->m_Element.m_ShadowVerts = nullptr;
            v5->m_Previous = v3;
            v5->m_Next = this->m_FirstFree;
            this->m_FirstFree = v3;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v3 = v4 + 1;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v3 = -1;
        it.index = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE430
// Name: public: void CUtlLinkedList<class CDispDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecal,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v2; // ax
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v3; // edx
  CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>::Iterator_t it; // [esp+0h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v2;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        ++v2;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
        it.index = v2;
      }
      while ( v2 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE4E0
// Name: protected: unsigned short CUtlLinkedList<class CDispDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecal,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDispDecal,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100BE660
// Name: public: void CUtlLinkedList<class CDispDecalFragment,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecalFragment,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v3; // si
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v5; // edi
  CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>::Iterator_t it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v3;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        v4 = v3;
        if ( v3 < this->m_Memory.m_nAllocationCount && v3 <= index )
        {
          v5 = &this->m_Memory.m_pMemory[v3];
          if ( v5->m_Previous != v3 || v5->m_Next == v3 )
          {
            free(pMem: v5->m_Element.m_pVerts);
            v4 = v3;
            v5->m_Element.m_pVerts = nullptr;
            v5->m_Previous = v3;
            v5->m_Next = this->m_FirstFree;
            this->m_FirstFree = v3;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v3 = v4 + 1;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v3 = -1;
        it.index = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE730
// Name: protected: unsigned short CUtlLinkedList<class CDispDecalFragment,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100BF390
// Name: public: void CUtlLinkedList<class CSpatialEntry,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CSpatialEntry,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
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
// Address: 0x100BF420
// Name: public: void CUtlLinkedList<class CDispShadowDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowDecal,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = v3->m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = v3->m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF4D0
// Name: public: void CUtlLinkedList<class CDispDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecal,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF770
// Name: public: void CUtlLinkedList<class CDispShadowDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispShadowDecal,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax

  CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    v5->m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF810
// Name: public: void CUtlLinkedList<struct CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v7; // ebx

  CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF8A0
// Name: public: void CUtlLinkedList<class CDispDecal,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDispDecal,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CDispDecal,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDC80
// Name: public: void CUtlLinkedList<struct CModelRender::ModelInstance_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // ecx
  int v3; // esi
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // edx
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v6; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v8; // ax
  CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *v9; // [esp+0h] [ebp-4h]

  v9 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_pLightingState = m_pMemory[v3].m_Element.m_pLightingState;
        m_Next = m_pMemory[v3].m_Next;
        v6 = &m_pMemory[v3];
        CUtlMemoryPool::Free(this: &CModelRender::ModelInstanceLightingState_t::s_Allocator, memBlock: m_pLightingState);
        v6->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = v9->m_FirstFree;
        else
          m_FirstFree = m_Next;
        this = v9;
        v6->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v8 = this->m_Head;
    if ( v8 != 0xFFFF )
      this->m_FirstFree = v8;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDD10
// Name: protected: unsigned short CUtlLinkedList<struct CModelRender::ModelInstance_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100E0010
// Name: public: void CUtlLinkedList<struct CModelRender::ModelInstance_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0A60
// Name: public: void CUtlLinkedList<struct CModelRender::ModelInstance_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7830
// Name: public: void CUtlLinkedList<struct COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F78A0
// Name: protected: unsigned short CUtlLinkedList<struct moverlayfragment_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100F7A20
// Name: public: void CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v2; // ax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v3; // edx
  CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>::Iterator_t it; // [esp+0h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v2;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        ++v2;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
        it.index = v2;
      }
      while ( v2 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7AD0
// Name: protected: unsigned short CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100F7CB0
// Name: protected: unsigned short CUtlLinkedList<struct COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100F80E0
// Name: public: void CUtlLinkedList<struct moverlayfragment_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8170
// Name: public: void CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<unsigned short,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F82D0
// Name: public: void CUtlLinkedList<struct COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F83E0
// Name: public: void CUtlLinkedList<struct COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8650
// Name: public: void CUtlLinkedList<struct moverlayfragment_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct moverlayfragment_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v3; // si
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v5; // edi
  CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>::Iterator_t it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v3;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        v4 = v3;
        if ( v3 < this->m_Memory.m_nAllocationCount && v3 <= index )
        {
          v5 = &this->m_Memory.m_pMemory[v3];
          if ( v5->m_Previous != v3 || v5->m_Next == v3 )
          {
            CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v5->m_Element.m_aPrimVerts);
            v5->m_Previous = v3;
            v5->m_Next = this->m_FirstFree;
            v4 = v3;
            this->m_FirstFree = v3;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v3 = v4 + 1;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v3 = -1;
        it.index = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102A70
// Name: public: void CUtlLinkedList<unsigned short,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this,
        int growSize)
{
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v4; // [esp-4h] [ebp-Ch]

  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v4 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = nullptr;
    this->m_Memory.m_nGrowSize = growSize;
  }
  else
  {
    this->m_Memory.m_nGrowSize = growSize;
    this->m_pElements = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102AC0
// Name: public: void CUtlLinkedList<class CSpatialEntry,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CSpatialEntry,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::Purge(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this);
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
// Address: 0x1010BF20
// Name: protected: int CUtlLinkedList<unsigned short,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal(
        CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010C0B0
// Name: protected: unsigned short CUtlLinkedList<struct msurface2_t __near *,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct msurface2_t __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<msurface2_t *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010C230
// Name: public: void CUtlLinkedList<struct CShadowMgr::Shadow_t,unsigned short,0,int,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          LOWORD(m_FirstFree) = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C2A0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowDecal_t,unsigned short,1,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowDecal_t,unsigned short>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *this)
{
  int index; // edx
  int v2; // eax
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C320
// Name: protected: int CUtlLinkedList<struct CShadowMgr::ShadowDecal_t,unsigned short,1,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFFFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_27:
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
    CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
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
      if ( `CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010C460
// Name: public: void CUtlLinkedList<struct CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C4D0
// Name: protected: unsigned short CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010C650
// Name: public: void CUtlLinkedList<struct CShadowMgr::Shadow_t,unsigned short,0,int,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::Unlink(
        CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *this,
        int elem)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v2; // eax
  int m_Previous; // ebx
  int m_Next; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Previous = v2->m_Previous;
      m_Next = v2->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( (_WORD)m_Next == 0xFFFF )
        this->m_Tail = v2->m_Previous;
      else
        this->m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Previous = v2->m_Previous;
      --this->m_ElementCount;
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C870
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010C9F0
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<MatchingProp_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010CB70
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010CD00
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010CE90
// Name: protected: unsigned short CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010D010
// Name: protected: unsigned short CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010D190
// Name: protected: int CUtlLinkedList<struct CShadowMgr::SurfaceBounds_t,unsigned short,0,int,class CUtlMemoryFixed<struct UtlLinkedListElem_t<struct CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *this,
        bool multilist)
{
  int result; // eax
  unsigned int index; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ecx
  int v8; // edx
  unsigned int v9; // ecx
  int v10; // [esp+4h] [ebp-4h]
  int v11; // [esp+4h] [ebp-4h]

  result = this->m_FirstFree;
  if ( result != 0xFFFF )
  {
    this->m_FirstFree = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0)
                                            + 80 * result
                                            + 0x42);
LABEL_23:
    v7 = (unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0;
    if ( multilist )
    {
      v9 = 80 * result + v7;
      *(_WORD *)(v9 + 66) = -1;
      *(_WORD *)(v9 + 64) = -1;
    }
    else
    {
      v8 = 10 * result;
      *(_WORD *)(v7 + 8 * v8 + 66) = result;
      *(_WORD *)(v7 + 8 * v8 + 64) = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index >= 0x400 )
  {
    v10 = 0;
  }
  else
  {
    v4 = index + 1;
    if ( v4 >= 0x400 )
      v4 = -1;
    v10 = v4;
  }
  result = v10;
  if ( v10 < 0 )
  {
    this->m_pElements = (UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short> *)((unsigned int)&this->m_Memory.m_Memory[15]
                                                                                          & 0xFFFFFFF0);
    v5 = this->m_LastAlloc.index;
    if ( v5 >= 0x400 )
    {
      v11 = 0;
    }
    else
    {
      v6 = v5 + 1;
      if ( v6 >= 0x400 )
        v6 = -1;
      v11 = v6;
    }
    result = v11;
    if ( v11 < 0 )
    {
      if ( `CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_23;
  }
  if ( `CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010D2F0
// Name: protected: unsigned short CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ecx
  int v10; // edx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_26:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &m_pMemory[v10];
      v11->m_Next = -1;
      v11->m_Previous = -1;
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
    CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>::Grow(
      this: &this->m_Memory,
      num: 1);
    v7 = this->m_LastAlloc.index;
    this->m_pElements = this->m_Memory.m_pMemory;
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
      if ( `CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_26;
  }
  if ( `CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1010EFE0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowDecal_t,unsigned short,1,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(
        CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v2; // eax
  int m_Previous; // ebx
  int m_Next; // edx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Previous = v2->m_Previous;
      m_Next = v2->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( (_WORD)m_Next == 0xFFFF )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F080
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F0F0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F170
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F340
// Name: public: void CUtlLinkedList<struct CShadowMgr::Shadow_t,unsigned short,0,int,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *this,
        int before,
        int elem)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // ebx
  int v5; // eax
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F3E0
// Name: public: void CUtlLinkedList<struct CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F470
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F500
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F5C0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F680
// Name: public: void CUtlLinkedList<class RecvTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class RecvTable __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<unsigned int,unsigned short> *m_pMemory; // eax
  int m_Previous; // edi
  unsigned __int16 *p_m_Next; // edx
  unsigned __int16 v7; // cx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Previous = m_pMemory[elem].m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = v7;
      }
      else
      {
        m_pMemory[m_Previous].m_Next = v7;
        v2 = elem;
      }
      if ( v7 == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[v7].m_Previous = m_Previous;
      *p_m_Next = v2;
      --this->m_ElementCount;
      m_pMemory[elem].m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F710
// Name: public: void CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::Unlink(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FD10
// Name: public: void CUtlLinkedList<class PackedEntity __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class PackedEntity __near *,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::Free(
        CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
          (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)this,
          i: elem,
          it: (const CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&this->m_LastAlloc) )
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
// Address: 0x1010FD80
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowDecal_t,unsigned short,1,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowDecal_t,unsigned short>,int>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *this,
        int before,
        int elem)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FEC0
// Name: public: void CUtlLinkedList<class CClientSendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CClientSendTable __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<unsigned int,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<unsigned int,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v7; // ebx

  CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FFD0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110050
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101100F0
// Name: public: void CUtlLinkedList<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110190
// Name: public: void CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::LinkBefore(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110C70
// Name: public: void CUtlLinkedList<struct CShadowMgr::SurfaceBounds_t,unsigned short,0,int,class CUtlMemoryFixed<struct UtlLinkedListElem_t<struct CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *this)
{
  int m_Head; // eax
  int v2; // esi
  int v3; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = 10 * m_Head;
        v3 = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * m_Head + 0x42);
        *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * m_Head + 0x40) = m_Head;
        if ( v3 == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          LOWORD(m_FirstFree) = v3;
        *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 8 * v2 + 0x42) = m_FirstFree;
        m_Head = v3;
      }
      while ( v3 != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110D00
// Name: public: void CUtlLinkedList<struct CShadowMgr::SurfaceBounds_t,unsigned short,0,int,class CUtlMemoryFixed<struct UtlLinkedListElem_t<struct CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::Unlink(
        CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *this,
        unsigned int elem)
{
  int v2; // ebx
  int v3; // esi

  if ( elem < 0x400
    && (signed int)elem <= this->m_LastAlloc.index
    && *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40) != elem )
  {
    v2 = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40);
    v3 = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42);
    if ( (_WORD)v2 == 0xFFFF )
      this->m_Head = v3;
    else
      *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * v2 + 0x42) = v3;
    if ( (_WORD)v3 == 0xFFFF )
      this->m_Tail = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40);
    else
      *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * (unsigned __int16)v3 + 0x40) = *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40);
    --this->m_ElementCount;
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42) = elem;
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110ED0
// Name: public: void CUtlLinkedList<struct CShadowMgr::SurfaceBounds_t,unsigned short,0,int,class CUtlMemoryFixed<struct UtlLinkedListElem_t<struct CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::LinkAfter(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::LinkAfter(
        CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *this,
        int after,
        unsigned int elem)
{
  int v4; // eax

  if ( elem < 0x400
    && (signed int)elem <= this->m_LastAlloc.index
    && *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40) != elem )
  {
    CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::Unlink(
      this,
      elem);
  }
  *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x40) = after;
  if ( after == 0xFFFF )
  {
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42) = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42) = *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * after + 0x42);
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * after + 0x42) = elem;
  }
  v4 = *(unsigned __int16 *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * elem + 0x42);
  if ( (_WORD)v4 == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    *(_WORD *)(((unsigned int)&this->m_Memory.m_Memory[15] & 0xFFFFFFF0) + 80 * v4 + 0x40) = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101123F0
// Name: public: unsigned short CUtlLinkedList<struct CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax

  v2 = (unsigned __int16)CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::LinkBefore(
      (CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *)this,
      before: 0xFFFFu,
      elem: v2);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10112B50
// Name: public: unsigned short CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::InsertBefore(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::InsertBefore(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this,
        unsigned __int16 before)
{
  int v3; // edi
  unsigned __int16 result; // ax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v5; // esi

  v3 = (unsigned __int16)CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::AllocInternal(
                           this,
                           multilist: false);
  result = -1;
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::LinkBefore(
      this,
      before,
      elem: v3);
    v5 = &this->m_Memory.m_pMemory[v3];
    if ( v5 != nullptr )
    {
      Frustum_t::Frustum_t(this: &this->m_Memory.m_pMemory[v3].m_Element.m_Frustum);
      FlashlightState_t::FlashlightState_t(this: &v5->m_Element.m_FlashlightState);
      CMaterialsBuckets<msurface2_t *>::CMaterialsBuckets<msurface2_t *>(this: &v5->m_Element.m_MaterialBuckets);
      CMaterialsBuckets<msurface2_t *>::CMaterialsBuckets<msurface2_t *>(this: &v5->m_Element.m_OccluderBuckets);
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10112BC0
// Name: public: void CUtlLinkedList<struct CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,class CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::RemoveAll(
        CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // di
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v5; // ax
  CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(this: &v2->m_Element.m_OccluderBuckets);
        CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(this: &v2->m_Element.m_MaterialBuckets);
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = v6->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        this = v6;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D4C0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
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
// Address: 0x1011FAE0
// Name: protected: unsigned short CUtlLinkedList<class CFrameSnapshot __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CFrameSnapshot __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1011FC60
// Name: protected: int CUtlLinkedList<class PackedEntity __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class PackedEntity __near *,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal(
        CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011FDF0
// Name: public: void CUtlLinkedList<class CSpatialEntry,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CSpatialEntry,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(
        CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)m_pBlockHeader
                                                                                     + 12 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[1] + 12 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)&m_pBlockHeader[1].m_nBlockSize
               + 3 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 12 * m_nIndex)
            && *(&m_pBlockHeader[2].m_pNext + 3 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 12 * m_nIndex) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[1].m_nBlockSize + 3 * m_nIndex) = (int)m_pBlockHeader + 12 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[2].m_pNext + 3 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 12 * m_nIndex;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x1012BA00
// Name: protected: unsigned short CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1012BB80
// Name: protected: unsigned short CUtlLinkedList<float,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<float,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<float,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<float,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1012BD00
// Name: public: void CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BD90
// Name: public: void CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BE20
// Name: public: void CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::LinkAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::LinkAfter(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v4; // edi
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v5; // eax
  int m_Next; // eax

  if ( elem < this->m_Memory.m_nAllocationCount
    && elem <= this->m_LastAlloc.index
    && this->m_Memory.m_pMemory[elem].m_Previous != elem )
  {
    CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::Unlink(
      this,
      elem);
  }
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v4->m_Next = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    v5 = &this->m_Memory.m_pMemory[after];
    v4->m_Next = v5->m_Next;
    v5->m_Next = elem;
  }
  m_Next = v4->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BEC0
// Name: public: void CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // di
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v5; // ax
  CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        if ( v2->m_Element.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v2->m_Element.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Element.m_Memory.m_pMemory);
            this = v6;
            v2->m_Element.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_Memory.m_nAllocationCount = 0;
        }
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BF70
// Name: public: unsigned short CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::AddToHead(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AddToHead(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v4; // ecx

  v2 = (unsigned __int16)CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::LinkAfter(
      this,
      after: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
      CUtlBuffer::CUtlBuffer(this: &v4->m_Element, growSize: 0, initSize: 0, nFlags: 0);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012BFB0
// Name: public: unsigned short CUtlLinkedList<class CUtlBuffer,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlBuffer,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax
  UtlLinkedListElem_t<CUtlBuffer,unsigned short> *v4; // ecx

  v2 = (unsigned __int16)CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CUtlBuffer,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlBuffer,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
      CUtlBuffer::CUtlBuffer(this: &v4->m_Element, growSize: 0, initSize: 0, nFlags: 0);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012D440
// Name: protected: int CUtlLinkedList<struct CServerRemoteAccess::DataResponse_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v8; // ecx

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
    CUtlMemory<ToolModule_t,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1012D570
// Name: protected: int CUtlLinkedList<struct CServerRemoteAccess::ListenerStore_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v8; // ecx

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
    CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimSequence_t,int> *)this,
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
      if ( `CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1012D760
// Name: public: void CUtlLinkedList<struct CServerRemoteAccess::ListenerStore_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::ListenerStore_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v2; // esi
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
// Address: 0x1012D7C0
// Name: public: void CUtlLinkedList<struct CServerRemoteAccess::DataResponse_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::DataResponse_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::Unlink(
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v2; // eax
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
// Address: 0x1012D850
// Name: public: void CUtlLinkedList<struct CServerRemoteAccess::ListenerStore_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::ListenerStore_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::Unlink(
        CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v2; // eax
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
// Address: 0x1012E020
// Name: public: int CUtlLinkedList<struct CServerRemoteAccess::DataResponse_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *m_pMemory; // ecx
  int v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v7; // ecx
  CUtlBuffer *p_packet; // ecx

  result = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::Unlink(
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
    v7 = this->m_Memory.m_pMemory;
    ++this->m_ElementCount;
    p_packet = &v7[v5].m_Element.packet;
    if ( p_packet != nullptr )
      CUtlBuffer::CUtlBuffer(this: p_packet, growSize: 0, initSize: 0, nFlags: 0);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012E090
// Name: public: int CUtlLinkedList<struct CServerRemoteAccess::ListenerStore_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::ListenerStore_t,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AddToTail(
        CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *m_pMemory; // ecx
  unsigned int v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v7; // esi
  netadr_s *p_adr; // esi

  result = CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::Unlink(
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
      p_adr = &v7->m_Element.adr;
      netadr_s::SetIP(this: p_adr, unIP: 0);
      netadr_s::SetPort(this: p_adr, newport: 0);
      netadr_s::SetType(this: p_adr, newtype: NA_IP);
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012E120
// Name: public: void CUtlLinkedList<struct CServerRemoteAccess::DataResponse_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CServerRemoteAccess::DataResponse_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *this)
{
  int m_Head; // edi
  int m_Next; // ebx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v3; // esi
  int m_FirstFree; // eax
  int v5; // eax
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
        v3 = &this->m_Memory.m_pMemory[m_Head];
        if ( v3->m_Element.packet.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_Element.packet.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Element.packet.m_Memory.m_pMemory);
            this = v6;
            v3->m_Element.packet.m_Memory.m_pMemory = nullptr;
          }
          v3->m_Element.packet.m_Memory.m_nAllocationCount = 0;
        }
        v3->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v3->m_Next = m_FirstFree;
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
// Address: 0x10168A00
// Name: protected: unsigned short CUtlLinkedList<class CRecvDecoder __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CRecvDecoder __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CRecvDecoder *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1016CD70
// Name: protected: int CUtlLinkedList<class CDTIRecvTable __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CDTIRecvTable __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::AllocInternal(
        CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CDTIRecvTable *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1016D020
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
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
// Address: 0x1016D340
// Name: public: void CUtlLinkedList<class CDTIRecvTable __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CDTIRecvTable __near *,int>,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int>>::PurgeAndDeleteElements(
        CUtlLinkedList<CDTIRecvTable *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDTIRecvTable *,int>,int> > *this)
{
  int m_Head; // eax
  int v3; // eax
  CDTIRecvTable *m_Element; // edi
  int m_Next; // ecx
  bool v6; // sf
  CDTIProp *m_pMemory; // eax
  UtlLinkedListElem_t<CDTIRecvTable *,int> *v8; // ecx
  int iNext; // [esp+8h] [ebp-4h]

  m_Head = this->m_Head;
  if ( m_Head != -1 )
  {
    do
    {
      v3 = m_Head;
      m_Element = this->m_Memory.m_pMemory[v3].m_Element;
      m_Next = this->m_Memory.m_pMemory[v3].m_Next;
      iNext = m_Next;
      if ( m_Element != nullptr )
      {
        CUtlVector<CDTIProp,CUtlMemory<CDTIProp,int>>::RemoveAll(this: &m_Element->m_Props);
        if ( m_Element->m_Props.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_Element->m_Props.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_Props.m_Memory.m_pMemory);
            m_Element->m_Props.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Props.m_Memory.m_nAllocationCount = 0;
        }
        v6 = m_Element->m_Props.m_Memory.m_nGrowSize < 0;
        m_pMemory = m_Element->m_Props.m_Memory.m_pMemory;
        m_Element->m_Props.m_pElements = m_pMemory;
        if ( !v6 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            m_Element->m_Props.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Props.m_Memory.m_nAllocationCount = 0;
        }
        v6 = m_Element->m_Name.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Element->m_Name.m_Storage.m_nActualLength = 0;
        if ( !v6 )
        {
          if ( m_Element->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_Name.m_Storage.m_Memory.m_pMemory);
            m_Element->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: m_Element);
        m_Next = iNext;
      }
      m_Head = m_Next;
    }
    while ( m_Next != -1 );
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_Memory.m_pMemory;
  this->m_NumAlloced = 0;
  this->m_FirstFree = -1;
  this->m_LastAlloc.index = -1;
  this->m_pElements = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1016D5A0
// Name: protected: unsigned short CUtlLinkedList<class CDTISendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDTISendTable __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1016DE10
// Name: public: void CUtlLinkedList<class CDTISendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDTISendTable __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  CDTISendTable *m_Element; // esi
  unsigned __int16 m_Next; // bx
  bool v5; // sf
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Element = this->m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
      if ( m_Element != nullptr )
      {
        v5 = m_Element->m_NetTableName.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Element->m_NetTableName.m_Storage.m_nActualLength = 0;
        if ( !v5 )
        {
          if ( m_Element->m_NetTableName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_NetTableName.m_Storage.m_Memory.m_pMemory);
            m_Element->m_NetTableName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_NetTableName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: m_Element);
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = -1;
  m_pMemory = this->m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NumAlloced = -65536;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10171CC0
// Name: public: void CUtlLinkedList<class CFrameSnapshot __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CFrameSnapshot __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<unsigned int,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171EE0
// Name: protected: unsigned short CUtlLinkedList<class RecvTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class RecvTable __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<RecvTable *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10172BA0
// Name: public: void CUtlLinkedList<class CClientSendTable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CClientSendTable __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  CClientSendTable *m_Element; // edi
  unsigned __int16 m_Next; // bx
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Element = this->m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
      if ( m_Element != nullptr )
      {
        CClientSendTable::~CClientSendTable(this: m_Element);
        free(pMem: m_Element);
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = -1;
  m_pMemory = this->m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NumAlloced = -65536;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x101730B0
// Name: public: void CUtlLinkedList<class CRecvDecoder __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CRecvDecoder __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  unsigned __int16 m_Next; // cx
  CRecvDecoder *m_Element; // esi
  const RecvProp **m_pMemory; // eax
  const RecvProp **v6; // eax
  UtlLinkedListElem_t<CRecvDecoder *,unsigned short> *v7; // ecx
  unsigned __int16 iNext; // [esp+8h] [ebp-4h]

  m_Head = this->m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
      m_Element = this->m_Memory.m_pMemory[m_Head].m_Element;
      iNext = m_Next;
      if ( m_Element != nullptr )
      {
        m_Element->m_DatatableProps.m_Size = 0;
        if ( m_Element->m_DatatableProps.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_Element->m_DatatableProps.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_DatatableProps.m_Memory.m_pMemory);
            m_Element->m_DatatableProps.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = m_Element->m_DatatableProps.m_Memory.m_pMemory;
        m_Element->m_DatatableProps.m_pElements = m_pMemory;
        if ( m_Element->m_DatatableProps.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            m_Element->m_DatatableProps.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_DatatableProps.m_Memory.m_nAllocationCount = 0;
        }
        m_Element->m_Props.m_Size = 0;
        if ( m_Element->m_Props.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_Element->m_Props.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_Props.m_Memory.m_pMemory);
            m_Element->m_Props.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Props.m_Memory.m_nAllocationCount = 0;
        }
        v6 = m_Element->m_Props.m_Memory.m_pMemory;
        m_Element->m_Props.m_pElements = v6;
        if ( m_Element->m_Props.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v6 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
            m_Element->m_Props.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_Props.m_Memory.m_nAllocationCount = 0;
        }
        CSendTablePrecalc::~CSendTablePrecalc(this: &m_Element->m_Precalc);
        free(pMem: m_Element);
        m_Next = iNext;
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = -1;
  v7 = this->m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NumAlloced = -65536;
  this->m_pElements = v7;
}

//------------------------------------------------------------------------------
// Address: 0x101A4E50
// Name: protected: unsigned short CUtlLinkedList<class VisCacheEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101A4FE0
// Name: public: void CUtlLinkedList<class VisCacheEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class VisCacheEntry,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A50A0
// Name: public: void CUtlLinkedList<class VisCacheEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *this,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v4; // edi
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v5; // eax
  int m_Next; // eax

  if ( elem < this->m_Memory.m_nAllocationCount
    && elem <= this->m_LastAlloc.index
    && this->m_Memory.m_pMemory[elem].m_Previous != elem )
  {
    CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::Unlink(
      this,
      elem);
  }
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v4->m_Next = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    v5 = &this->m_Memory.m_pMemory[after];
    v4->m_Next = v5->m_Next;
    v5->m_Next = elem;
  }
  m_Next = v4->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A5370
// Name: public: void CUtlLinkedList<class VisCacheEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class VisCacheEntry,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *this)
{
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v1; // esi
  unsigned __int16 m_Next; // bx
  unsigned __int16 *m_pMemory; // eax
  unsigned __int16 *v4; // eax
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 m_Head; // ax
  unsigned __int16 i; // [esp+0h] [ebp-8h]
  CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short> > *v8; // [esp+4h] [ebp-4h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    i = this->m_Head;
    if ( i != 0xFFFF )
    {
      do
      {
        v1 = &this->m_Memory.m_pMemory[i];
        m_Next = v1->m_Next;
        v1->m_Element.nodelist.m_Size = 0;
        if ( v1->m_Element.nodelist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v1->m_Element.nodelist.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Element.nodelist.m_Memory.m_pMemory);
            this = v8;
            v1->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v1->m_Element.nodelist.m_Memory.m_pMemory;
        v1->m_Element.nodelist.m_pElements = m_pMemory;
        if ( v1->m_Element.nodelist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            this = v8;
            v1->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
        }
        v1->m_Element.leaflist.m_Size = 0;
        if ( v1->m_Element.leaflist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v1->m_Element.leaflist.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Element.leaflist.m_Memory.m_pMemory);
            this = v8;
            v1->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
        }
        v4 = v1->m_Element.leaflist.m_Memory.m_pMemory;
        v1->m_Element.leaflist.m_pElements = v4;
        if ( v1->m_Element.leaflist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
            this = v8;
            v1->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
        }
        v1->m_Previous = i;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v1->m_Next = m_FirstFree;
        i = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
      this->m_FirstFree = m_Head;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6070
// Name: protected: unsigned short CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101B6D30
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B70C0
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8430
// Name: public: unsigned short CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this)
{
  int v2; // edi
  int result; // eax
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v4; // esi

  v2 = (unsigned __int16)CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
    {
      v4->m_Element.m_pChannel = nullptr;
      v4->m_Element.m_Socket = -1;
      CUtlBuffer::CUtlBuffer(this: &v4->m_Element.m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
      CUtlBuffer::CUtlBuffer(this: &v4->m_Element.m_To, growSize: 0, initSize: 0, nFlags: 0);
    }
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B8490
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // di
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v5; // ax
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        if ( v2->m_Element.m_To.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v2->m_Element.m_To.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Element.m_To.m_Memory.m_pMemory);
            this = v6;
            v2->m_Element.m_To.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_To.m_Memory.m_nAllocationCount = 0;
        }
        if ( v2->m_Element.m_Buffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v2->m_Element.m_Buffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Element.m_Buffer.m_Memory.m_pMemory);
            this = v6;
            v2->m_Element.m_Buffer.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_Buffer.m_Memory.m_nAllocationCount = 0;
        }
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7650
// Name: protected: int CUtlLinkedList<class CEventInfo,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal(
        CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[7].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[7].m_nBlockSize = 0;
      result[7].m_pNext = nullptr;
    }
    else
    {
      result[7].m_nBlockSize = (int)result;
      result[7].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[8 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[8 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101D9B60
// Name: protected: int CUtlLinkedList<class CSpatialEntry,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CSpatialEntry,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal(
        CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D9CF0
// Name: protected: int CUtlLinkedList<struct LeafListData_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal(
        CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)this->m_FirstFree;
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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101D9E80
// Name: protected: unsigned short CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocated; // ecx
  int result; // eax
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  int index; // eax
  int v11; // ecx
  unsigned __int8 *v12; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = *(_WORD *)&this->m_Memory.m_MemoryStack.m_pBase[60 * m_FirstFree + 58];
LABEL_27:
    v12 = &this->m_Memory.m_MemoryStack.m_pBase[60 * (unsigned __int16)result];
    if ( multilist )
    {
      *((_WORD *)v12 + 29) = -1;
      *((_WORD *)v12 + 28) = -1;
    }
    else
    {
      *((_WORD *)v12 + 29) = result;
      *((_WORD *)v12 + 28) = result;
    }
    return result;
  }
  m_nAllocated = this->m_Memory.m_nAllocated;
  if ( this->m_LastAlloc.index >= m_nAllocated )
  {
    m_nAllocated = this->m_Memory.m_nAllocated;
    LOWORD(result) = m_nAllocated != 0 ? 0 : -1;
  }
  else
  {
    result = this->m_LastAlloc.index;
    if ( result >= m_nAllocated )
      LOWORD(result) = -1;
    else
      LOWORD(result) = result + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocated )
  {
    m_alignment = this->m_Memory.m_MemoryStack.m_alignment;
    this->m_Memory.m_nAllocated = m_nAllocated + 1;
    v7 = 60;
    if ( m_alignment >= 0x3C )
      v7 = m_alignment;
    v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
    v9 = &this->m_Memory.m_MemoryStack.m_pNextAlloc[v8];
    if ( v9 <= this->m_Memory.m_MemoryStack.m_pCommitLimit
      || CMemoryStack::CommitTo(
           this: &this->m_Memory.m_MemoryStack,
           pNextAlloc: &this->m_Memory.m_MemoryStack.m_pNextAlloc[v8]) )
    {
      this->m_Memory.m_MemoryStack.m_pNextAlloc = v9;
    }
    index = this->m_LastAlloc.index;
    this->m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)this->m_Memory.m_MemoryStack.m_pBase;
    v11 = this->m_Memory.m_nAllocated;
    if ( index >= v11 )
    {
      v11 = this->m_Memory.m_nAllocated;
      LOWORD(result) = v11 != 0 ? 0 : -1;
    }
    else
    {
      result = this->m_LastAlloc.index;
      LOWORD(result) = result >= v11 ? -1 : result + 1;
    }
    if ( (unsigned __int16)result >= v11 )
    {
      if ( `CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101DAC10
// Name: public: void CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::EnsureCapacity(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this,
        int num)
{
  int m_nAllocated; // eax
  unsigned int m_alignment; // ecx
  unsigned int v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // edi
  unsigned __int8 *m_pBase; // eax

  m_nAllocated = this->m_Memory.m_nAllocated;
  if ( m_nAllocated >= num )
  {
    this->m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)this->m_Memory.m_MemoryStack.m_pBase;
  }
  else
  {
    this->m_Memory.m_nAllocated = num;
    m_alignment = this->m_Memory.m_MemoryStack.m_alignment;
    v5 = 60 * (num - m_nAllocated);
    if ( v5 <= m_alignment )
      v5 = this->m_Memory.m_MemoryStack.m_alignment;
    v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
    v7 = &this->m_Memory.m_MemoryStack.m_pNextAlloc[v6];
    if ( v7 <= this->m_Memory.m_MemoryStack.m_pCommitLimit
      || CMemoryStack::CommitTo(
           this: &this->m_Memory.m_MemoryStack,
           pNextAlloc: &this->m_Memory.m_MemoryStack.m_pNextAlloc[v6]) )
    {
      m_pBase = this->m_Memory.m_MemoryStack.m_pBase;
      this->m_Memory.m_MemoryStack.m_pNextAlloc = v7;
      this->m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)m_pBase;
    }
    else
    {
      this->m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)this->m_Memory.m_MemoryStack.m_pBase;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB180
// Name: public: void CUtlLinkedList<struct LeafListData_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::RemoveAll(
        CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x101DC0E0
// Name: public: void CUtlLinkedList<struct LeafListData_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::Purge(
        CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::RemoveAll(this);
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
// Address: 0x101DC130
// Name: public: void CUtlLinkedList<struct LeafListData_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::LinkBefore(
        CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
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
// Address: 0x101DD5C0
// Name: public: void CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this)
{
  unsigned __int16 m_Head; // si
  unsigned __int8 *v2; // edx
  unsigned __int16 v3; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_MemoryStack.m_pBase[60 * m_Head];
        v3 = *((_WORD *)v2 + 29);
        *((_WORD *)v2 + 28) = m_Head;
        if ( v3 == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = v3;
        *((_WORD *)v2 + 29) = m_FirstFree;
        m_Head = v3;
      }
      while ( v3 != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD640
// Name: public: void CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::Unlink(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  unsigned __int8 *m_pBase; // esi
  unsigned __int8 *v4; // eax
  int v5; // edi
  unsigned __int16 v6; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocated && elem <= this->m_LastAlloc.index )
  {
    m_pBase = this->m_Memory.m_MemoryStack.m_pBase;
    v4 = &m_pBase[60 * elem];
    if ( *((_WORD *)v4 + 28) != elem )
    {
      v5 = *((unsigned __int16 *)v4 + 28);
      v6 = *((_WORD *)v4 + 29);
      if ( (_WORD)v5 == 0xFFFF )
      {
        this->m_Head = v6;
      }
      else
      {
        *(_WORD *)&m_pBase[60 * v5 + 58] = v6;
        v2 = elem;
      }
      if ( v6 == 0xFFFF )
        this->m_Tail = *((_WORD *)v4 + 28);
      else
        *(_WORD *)&this->m_Memory.m_MemoryStack.m_pBase[60 * v6 + 56] = *((_WORD *)v4 + 28);
      *((_WORD *)v4 + 29) = v2;
      *((_WORD *)v4 + 28) = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE060
// Name: public: void CUtlLinkedList<struct EntityInfo_t,unsigned short,0,unsigned short,class CUtlMemoryStack<struct UtlLinkedListElem_t<struct EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::LinkBefore(
        CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  unsigned __int8 *m_pBase; // edx
  unsigned __int8 *v5; // ecx
  unsigned __int16 m_Tail; // ax

  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::Unlink(
    this,
    elem);
  m_pBase = this->m_Memory.m_MemoryStack.m_pBase;
  v5 = &m_pBase[60 * elem];
  *((_WORD *)v5 + 29) = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    *((_WORD *)v5 + 28) = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = *(_WORD *)&m_pBase[60 * before + 56];
    *((_WORD *)v5 + 28) = m_Tail;
    *(_WORD *)&m_pBase[60 * before + 56] = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    *(_WORD *)&m_pBase[60 * m_Tail + 58] = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6900
// Name: protected: unsigned short CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlString,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101E6B60
// Name: public: void CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlString,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6BF0
// Name: public: void CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlString,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlString,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlString,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6C80
// Name: public: void CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  bool v2; // sf
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<CUtlString,unsigned short> *v4; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v6; // ax
  CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *v7; // [esp+0h] [ebp-4h]

  v7 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = this->m_Memory.m_pMemory[m_Head].m_Element.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
        v4 = &this->m_Memory.m_pMemory[m_Head];
        v4->m_Element.m_Storage.m_nActualLength = 0;
        if ( !v2 )
        {
          if ( v4->m_Element.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_Storage.m_Memory.m_pMemory);
            this = v7;
            v4->m_Element.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Element.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v4->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v4->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v6 = this->m_Head;
    if ( v6 != 0xFFFF )
      this->m_FirstFree = v6;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6D40
// Name: public: void CUtlLinkedList<class CUtlString,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CUtlString,unsigned short>,unsigned short>>::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Remove(
        CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  bool v3; // sf
  UtlLinkedListElem_t<CUtlString,unsigned short> *v4; // esi

  CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  v3 = this->m_Memory.m_pMemory[elem].m_Element.m_Storage.m_Memory.m_nGrowSize < 0;
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Element.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( v4->m_Element.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_Storage.m_Memory.m_pMemory);
      v4->m_Element.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v4->m_Element.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v4->m_Next = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x101EE6B0
// Name: Test_RandomChance
// Source: json
//------------------------------------------------------------------------------
void __usercall Test_RandomChance(int a1@<esi>, const CCommand *args)
{
  const char *v3; // eax
  IUniformRandomStream *v4; // ecx
  vgui::CTreeViewListControl *v5; // ecx
  int m_nArgc; // eax
  int v7; // esi
  const char **v8; // ebx
  const char *v9; // eax
  ECommandTarget_t TraceType; // eax
  char newString[1024]; // [esp+Ch] [ebp-400h] BYREF
  float flPercent; // [esp+414h] [ebp+8h]

  if ( args->m_nArgc < 3 )
    _Error(a1: "Test_RandomChance: requires percentage chance parameter (0-100) followed by command to execute.");
  v3 = defaultValue;
  if ( args->m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  flPercent = atof(nptr: v3);
  if ( (double)flPercent > _RandomFloat(this: v4, a2: 0.0, a3: 100.0) )
  {
    m_nArgc = args->m_nArgc;
    *(_DWORD *)newString = a1;
    v7 = 2;
    newString[0] = 0;
    if ( m_nArgc > 2 )
    {
      v8 = &args->m_ppArgv[2];
      do
      {
        if ( v7 < 0 || v7 >= m_nArgc )
          v9 = defaultValue;
        else
          v9 = *v8;
        V_strncat(pDest: newString, pSrc: v9, destBufferSize: 0x400u, max_chars_to_copy: -1);
        V_strncat(pDest: newString, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
        m_nArgc = args->m_nArgc;
        ++v7;
        ++v8;
      }
      while ( v7 < args->m_nArgc );
    }
    TraceType = CTraceFilter::GetTraceType(this: v5);
    Cbuf_InsertText(eTarget: TraceType, pText: newString, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE790
// Name: Test_SendKey
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_SendKey(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    Sys_TestSendKey(pKey: v1);
  }
  else
  {
    _Error(a1: "Test_SendKey: requires key to send.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE7D0
// Name: void Test_Wait(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_Wait(const CCommand *args)
{
  const char *v1; // eax
  int v2; // ecx
  float flSeconds; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    flSeconds = atof(nptr: v1);
    g_TestScriptMgr.m_WaitUntil = _Plat_FloatTime(a1: v2) + flSeconds;
  }
  else
  {
    _Error(a1: "Test_Wait: requires seconds parameter.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE820
// Name: private: void CTestScriptMgr::RunCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::RunCommands(CTestScriptMgr *this)
{
  int v2; // ebx
  vgui::CTreeViewListControl *v3; // ecx
  char v4; // al
  ECommandTarget_t TraceType; // eax
  char curCommand[515]; // [esp+Ch] [ebp-204h] BYREF
  char tempVal; // [esp+20Fh] [ebp-1h] BYREF

  while ( this->m_WaitUntil <= _Plat_FloatTime(a1: this) && this->m_NextCheckPoint[0] == 0 )
  {
    v2 = 0;
    tempVal = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &curCommand[v2], a3: 1, a4: this->m_hFile);
        v4 = curCommand[v2];
        if ( v4 == 47 )
          break;
        tempVal = 0;
        if ( v4 == 59 || v4 == 10 || g_pFileSystem->EndOfFile(this: g_pFileSystem, a2: this->m_hFile) )
          goto LABEL_15;
        ++v2;
      }
      if ( tempVal != 0 )
        break;
      tempVal = 1;
      ++v2;
    }
    for ( tempVal = 0;
          tempVal != 10;
          g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &tempVal, a3: 1, a4: this->m_hFile) )
    {
      if ( g_pFileSystem->EndOfFile(this: g_pFileSystem, a2: this->m_hFile) )
        break;
    }
    --v2;
LABEL_15:
    curCommand[v2] = 0;
    if ( curCommand[0] != 0 )
    {
      if ( testscript_debug.m_pParent != nullptr && testscript_debug.m_pParent->m_Value.m_nValue != 0 )
        _Msg(a1: "Executing command from script: %s\n", curCommand);
      TraceType = CTraceFilter::GetTraceType(this: v3);
      Cbuf_AddText(eTarget: TraceType, pText: curCommand, nTickDelay: 0);
      Cbuf_Execute();
    }
    else if ( g_pFileSystem->EndOfFile(this: g_pFileSystem, a2: this->m_hFile) )
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&testscript_running.IConVar, value: 0);
      if ( this->m_hFile != nullptr )
      {
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
        this->m_hFile = nullptr;
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE990
// Name: public: bool CTestScriptMgr::StartTestScript(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTestScriptMgr::StartTestScript(CTestScriptMgr *this, const char *pFilename)
{
  void *v3; // eax
  char fullName[512]; // [esp+4h] [ebp-200h] BYREF

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&testscript_running.IConVar, value: 0);
  if ( this->m_hFile != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
    this->m_hFile = nullptr;
  }
  V_snprintf(pDest: fullName, maxLen: 512, pFormat: "testscripts\\%s", pFilename);
  v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: fullName, a3: "rt", a4: 0);
  this->m_hFile = v3;
  if ( v3 == nullptr )
    return 0;
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&testscript_running.IConVar, value: 1);
  CTestScriptMgr::RunCommands(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EEA30
// Name: protected: int CUtlLinkedList<class CLoopInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CLoopInfo __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AllocInternal(
        CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CLoopInfo *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x101EEB60
// Name: Test_StartScript
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_StartScript(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    if ( CTestScriptMgr::StartTestScript(this: &g_TestScriptMgr, pFilename: v1) == 0 )
    {
      v2 = defaultValue;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      _Warning(a1: "Error starting testscript '%s'\n", v2);
    }
  }
  else
  {
    _Warning(a1: "Test_StartScript: requires filename of script to start (file must be under testscripts directory).\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEBC0
// Name: private: class CLoopInfo __near * CTestScriptMgr::FindLoop(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLoopInfo *__thiscall CTestScriptMgr::FindLoop(CTestScriptMgr *this, const char *pLoopName)
{
  int m_Head; // edi

  m_Head = this->m_Loops.m_Head;
  if ( m_Head == -1 )
    return nullptr;
  while ( _V_stricmp(s1: pLoopName, s2: this->m_Loops.m_Memory.m_pMemory[m_Head].m_Element->m_Name) != 0 )
  {
    m_Head = this->m_Loops.m_Memory.m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      return nullptr;
  }
  return this->m_Loops.m_Memory.m_pMemory[m_Head].m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x101EEC20
// Name: private: void CTestScriptMgr::LoopCount(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::LoopCount(CTestScriptMgr *this, const char *pLoopName, int nTimes)
{
  CLoopInfo *Loop; // esi
  int m_ListIndex; // edi

  if ( this->m_hFile == nullptr )
    _Error(a1: "CTestScriptMgr: not initialized.");
  Loop = CTestScriptMgr::FindLoop(this, pLoopName);
  if ( Loop == nullptr )
    _Error(a1: "CTestScriptMgr::LoopCount( %s ): no loop with this name exists.", pLoopName);
  if ( ++Loop->m_nCount < nTimes || nTimes == -1 )
  {
    _Msg(a1: "Performing loop to %s (%d iterations)\n", pLoopName, Loop->m_nCount);
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: this->m_hFile,
      a3: Loop->m_iNextCommandPos,
      a4: FILESYSTEM_SEEK_HEAD);
  }
  else
  {
    m_ListIndex = Loop->m_ListIndex;
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Loops,
      elem: m_ListIndex);
    this->m_Loops.m_Memory.m_pMemory[m_ListIndex].m_Next = this->m_Loops.m_FirstFree;
    this->m_Loops.m_FirstFree = m_ListIndex;
    free(pMem: Loop);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EECD0
// Name: private: void CTestScriptMgr::LoopForNumSeconds(char const __near *,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::LoopForNumSeconds(CTestScriptMgr *this, const char *pLoopName, double nSeconds)
{
  int v4; // ecx
  CLoopInfo *Loop; // esi
  int m_ListIndex; // edi

  if ( this->m_hFile == nullptr )
    _Error(a1: "CTestScriptMgr: not initialized.");
  Loop = CTestScriptMgr::FindLoop(this, pLoopName);
  if ( Loop == nullptr )
    _Error(a1: "CTestScriptMgr::LoopForNumSeconds( %s ): no loop with this name exists.", pLoopName);
  if ( nSeconds <= _Plat_FloatTime(a1: v4) - Loop->m_flStartTime )
  {
    m_ListIndex = Loop->m_ListIndex;
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Loops,
      elem: m_ListIndex);
    this->m_Loops.m_Memory.m_pMemory[m_ListIndex].m_Next = this->m_Loops.m_FirstFree;
    this->m_Loops.m_FirstFree = m_ListIndex;
    free(pMem: Loop);
  }
  else
  {
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: this->m_hFile,
      a3: Loop->m_iNextCommandPos,
      a4: FILESYSTEM_SEEK_HEAD);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EED70
// Name: public: void CTestScriptMgr::SetWaitCheckPoint(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::SetWaitCheckPoint(CTestScriptMgr *this, const char *pCheckPointName, bool bOnce)
{
  const char *v4; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  if ( testscript_debug.m_pParent != nullptr
    && testscript_debug.m_pParent->m_Value.m_nValue != 0
    && _V_stricmp(s1: pCheckPointName, s2: "frame_end") != 0 )
  {
    v4 = " (once).";
    if ( !bOnce )
      v4 = ".";
    _Msg(a1: "TESTSCRIPT: waiting for checkpoint '%s'%s\n", pCheckPointName, v4);
  }
  if ( !bOnce
    || pCheckPointName == nullptr
    || (search.key = pCheckPointName,
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
          this: &this->m_CheckPointsHit.m_Elements.m_Tree,
          &search) == -1) )
  {
    V_strncpy(pDest: this->m_NextCheckPoint, pSrc: pCheckPointName, maxLen: 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEE00
// Name: public: int CUtlLinkedList<class CLoopInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CLoopInfo __near *,int>,int>>::AddToTail(class CLoopInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AddToTail(
        CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int> > *this,
        CLoopInfo **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<CLoopInfo *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CLoopInfo *,int> *v8; // esi

  result = CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x101EEED0
// Name: void Test_WaitForCheckPoint(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_WaitForCheckPoint(const CCommand *args)
{
  int m_nArgc; // eax
  bool v3; // cc
  const char *v4; // eax
  const char *v5; // eax
  bool bOnce; // [esp+Ch] [ebp+8h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    if ( m_nArgc < 3 )
      goto LABEL_7;
    v3 = m_nArgc <= 2;
    v4 = defaultValue;
    if ( !v3 )
      v4 = args->m_ppArgv[2];
    bOnce = true;
    if ( _V_stricmp(s1: v4, s2: "once") != 0 )
LABEL_7:
      bOnce = false;
    v5 = defaultValue;
    if ( args->m_nArgc > 1 )
      v5 = args->m_ppArgv[1];
    CTestScriptMgr::SetWaitCheckPoint(this: &g_TestScriptMgr, pCheckPointName: v5, bOnce);
  }
  else
  {
    _Error(a1: "Test_WaitForCheckPoint <checkpoint name> [once]: requires checkpoint name.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEF40
// Name: void Test_LoopCount(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_LoopCount(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // ecx
  const char *v3; // esi
  int v4; // eax

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 3 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    v3 = defaultValue;
    if ( m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = atoi(nptr: v2);
    CTestScriptMgr::LoopCount(this: &g_TestScriptMgr, pLoopName: v3, nTimes: v4);
  }
  else
  {
    _Error(a1: "Test_LoopCount: requires a loop name and number of times to loop.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEFA0
// Name: void Test_Loop(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_Loop(const CCommand *args)
{
  const char *v1; // edi
  CLoopInfo *Loop; // esi

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    if ( g_TestScriptMgr.m_hFile == nullptr )
      _Error(a1: "CTestScriptMgr: not initialized.");
    Loop = CTestScriptMgr::FindLoop(this: &g_TestScriptMgr, pLoopName: v1);
    if ( Loop == nullptr )
      _Error(a1: "CTestScriptMgr::LoopCount( %s ): no loop with this name exists.", v1);
    _Msg(a1: "Performing loop to %s (%d iterations)\n", v1, ++Loop->m_nCount);
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: g_TestScriptMgr.m_hFile,
      a3: Loop->m_iNextCommandPos,
      a4: FILESYSTEM_SEEK_HEAD);
  }
  else
  {
    _Error(a1: "Test_Loop: requires a loop name.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF040
// Name: void Test_LoopForNumSeconds(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_LoopForNumSeconds(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // ecx
  const char *v3; // esi
  double nSeconds; // st7

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 3 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    v3 = defaultValue;
    if ( m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    nSeconds = atof(nptr: v2);
    CTestScriptMgr::LoopForNumSeconds(this: &g_TestScriptMgr, pLoopName: v3, nSeconds);
  }
  else
  {
    _Error(a1: "Test_LoopLoopForNumSeconds: requires a loop name and number of seconds to loop.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF0A0
// Name: private: void CTestScriptMgr::StartLoop(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::StartLoop(CTestScriptMgr *this, CLoopInfo *pLoopName)
{
  const char *v3; // ebx
  CLoopInfo *v4; // esi
  int v5; // ecx

  if ( this->m_hFile == nullptr )
    _Error(a1: "CTestScriptMgr: not initialized.");
  v3 = (const char *)pLoopName;
  if ( CTestScriptMgr::FindLoop(this, (const char *)pLoopName) != nullptr )
    _Error(a1: "CTestScriptMgr::StartLoop( %s ): loop already exists.", v3);
  v4 = (CLoopInfo *)MemAlloc_Alloc(nSize: 0x58u);
  pLoopName = v4;
  V_strncpy(pDest: v4->m_Name, pSrc: v3, maxLen: 64);
  v4->m_nCount = 0;
  v4->m_flStartTime = _Plat_FloatTime(a1: v5);
  v4->m_iNextCommandPos = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
  v4->m_ListIndex = CUtlLinkedList<CLoopInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CLoopInfo *,int>,int>>::AddToTail(
                      this: &this->m_Loops,
                      src: &pLoopName);
}

//------------------------------------------------------------------------------
// Address: 0x101EF130
// Name: void Test_StartLoop(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_StartLoop(const CCommand *args)
{
  char *v1; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = (char *)defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = (char *)args->m_ppArgv[1];
    CTestScriptMgr::StartLoop(this: &g_TestScriptMgr, pLoopName: (CLoopInfo *)v1);
  }
  else
  {
    _Error(a1: "Test_StartLoop: requires a loop name.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF170
// Name: public: CTestScriptMgr::CTestScriptMgr(void)
// Source: json
//------------------------------------------------------------------------------
CTestScriptMgr *__thiscall CTestScriptMgr::CTestScriptMgr(CTestScriptMgr *this)
{
  UtlLinkedListElem_t<CLoopInfo *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // ecx

  this->__vftable = (CTestScriptMgr_vtbl *)&CTestScriptMgr::`vftable';
  this->m_Loops.m_Memory.m_pMemory = nullptr;
  this->m_Loops.m_Memory.m_nAllocationCount = 0;
  this->m_Loops.m_Memory.m_nGrowSize = 0;
  this->m_Loops.m_LastAlloc.index = -1;
  m_pMemory = this->m_Loops.m_Memory.m_pMemory;
  this->m_Loops.m_Head = -1;
  this->m_Loops.m_Tail = -1;
  this->m_Loops.m_FirstFree = -1;
  this->m_Loops.m_ElementCount = 0;
  this->m_Loops.m_NumAlloced = 0;
  this->m_Loops.m_pElements = m_pMemory;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_Root = -1;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_NumElements = 0;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_LastAlloc.index = -1;
  v3 = this->m_CheckPointsHit.m_Elements.m_Tree.m_Elements.m_pMemory;
  this->m_CheckPointsHit.m_Elements.m_Tree.m_pElements = v3;
  if ( this->m_CheckPointsHit.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_CheckPointsHit.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_hFile = nullptr;
  this->m_NextCheckPoint[0] = 0;
  this->m_WaitUntil = _Plat_FloatTime(a1: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EF1E0
// Name: public: virtual CTestScriptMgr::~CTestScriptMgr(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CTestScriptMgr::~CTestScriptMgr(CTestScriptMgr *this)
{
  this->__vftable = (CTestScriptMgr_vtbl *)&CTestScriptMgr::`vftable';
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&testscript_running.IConVar, value: 0);
  if ( this->m_hFile != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
    this->m_hFile = nullptr;
  }
  CUtlDict<int,int>::RemoveAll(this: &this->m_CheckPointsHit);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &this->m_CheckPointsHit.m_Elements.m_Tree);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Loops);
  if ( this->m_Loops.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Loops.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Loops.m_Memory.m_pMemory);
      this->m_Loops.m_Memory.m_pMemory = nullptr;
    }
    this->m_Loops.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF290
// Name: public: void CTestScriptMgr::CheckPoint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestScriptMgr::CheckPoint(CTestScriptMgr *this, char *pName)
{
  char *v3; // ebx

  if ( this->m_hFile != nullptr && this->m_WaitUntil <= _Plat_FloatTime(a1: this) )
  {
    v3 = pName;
    if ( testscript_debug.m_pParent != nullptr
      && testscript_debug.m_pParent->m_Value.m_nValue != 0
      && _V_stricmp(s1: pName, s2: "frame_end") != 0 )
    {
      _Msg(a1: "TESTSCRIPT: CheckPoint -> '%s'.\n", v3);
    }
    pName = nullptr;
    CUtlDict<int,int>::Insert(this: &this->m_CheckPointsHit, pName: v3, element: (const int *)&pName);
    if ( this->m_NextCheckPoint[0] == 0 || _V_stricmp(s1: this->m_NextCheckPoint, s2: v3) == 0 )
    {
      this->m_NextCheckPoint[0] = 0;
      CTestScriptMgr::RunCommands(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276C10
// Name: protected: int CUtlLinkedList<struct CCommandBuffer::Command_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal(
        CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 16);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 12) = 0;
    }
    else
    {
      *(_DWORD *)(result + 16) = result;
      *(_DWORD *)(result + 12) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
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
    CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
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
      if ( `CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)((char *)v8 + 20 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 20 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10276E30
// Name: public: void CUtlLinkedList<struct CCommandBuffer::Command_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::RemoveAll(
        CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *this)
{
  CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

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
          i = CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(this: &v1->m_Memory, &result, &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)((char *)m_pBlockHeader + 20 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[1] + 20 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t **)&m_pBlockHeader[2].m_nBlockSize
               + 5 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex)
            && *(&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex) )
          {
            v1 = (CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[2].m_nBlockSize + 5 * m_nIndex) = (int)m_pBlockHeader + 20 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 20 * m_nIndex;
            v1 = (CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *)v5;
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
// Address: 0x10276F00
// Name: public: void CUtlLinkedList<struct CCommandBuffer::Command_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::LinkBefore(
        CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 12);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v5 = *(_DWORD *)(elem + 16);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 12);
    *(_DWORD *)(before + 12) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 12) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 16) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276F90
// Name: public: void CUtlLinkedList<struct CCommandBuffer::Command_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::Free(
        CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 12);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v4 = *(_DWORD *)(elem + 16);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x102777B0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277820
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x102779A0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277C00
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ACDB0
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x102AD3F0
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102AFA90
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x102B4CF0
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102B4E50
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102B7180
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B7750
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8560
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x102B85D0
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B8A70
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1750
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102C2F20
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x102C5AA0
// Name: protected: int CUtlLinkedList<int,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<int,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal(
        CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<int,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102C6140
// Name: public: int CUtlLinkedList<int,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<int,int>,int>>::AddToHead(int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AddToHead(
        CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > *this,
        int *src)
{
  int result; // eax
  int v4; // esi
  UtlLinkedListElem_t<int,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Next; // eax
  UtlLinkedListElem_t<int,int> *v8; // edi

  result = CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    if ( result >= 0
      && result < this->m_Memory.m_nAllocationCount
      && result <= this->m_LastAlloc.index
      && this->m_Memory.m_pMemory[result].m_Previous != result )
    {
      CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
        elem: result);
    }
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Previous = -1;
    m_pMemory[v6].m_Next = this->m_Head;
    this->m_Head = v4;
    m_Next = m_pMemory[v4].m_Next;
    if ( m_Next == -1 )
      this->m_Tail = v4;
    else
      this->m_Memory.m_pMemory[m_Next].m_Previous = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C61D0
// Name: public: int CUtlLinkedList<int,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<int,int>,int>>::AddToTail(int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AddToTail(
        CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int> > *this,
        int *src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<int,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<int,int> *v8; // esi

  result = CUtlLinkedList<int,int,0,int,CUtlMemory<UtlLinkedListElem_t<int,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x102C81C0
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
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
// Address: 0x102CDFF0
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
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
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102E32F0
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
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
    CUtlMemory<CPortalRect,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x102E3420
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
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
// Address: 0x1031E490
// Name: _dynamic_initializer_for__Test_RunFrame_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_RunFrame_command__()
{
  ConCommand::ConCommand(
    this: &Test_RunFrame_command,
    pName: "Test_RunFrame",
    callback: Test_RunFrame,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_RunFrame_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E4F0
// Name: _dynamic_initializer_for__Test_StartLoop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_StartLoop_command__()
{
  ConCommand::ConCommand(
    this: &Test_StartLoop_command,
    pName: "Test_StartLoop",
    callback: Test_StartLoop,
    pHelpString: "Test_StartLoop <loop name> - Denote the start of a loop. Really just defines a named point you can jump to.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_StartLoop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E520
// Name: _dynamic_initializer_for__Test_LoopCount_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_LoopCount_command__()
{
  ConCommand::ConCommand(
    this: &Test_LoopCount_command,
    pName: "Test_LoopCount",
    callback: Test_LoopCount,
    pHelpString: "Test_LoopCount <loop name> <count> - loop back to the specified loop start point the specified # of times.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_LoopCount_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E550
// Name: _dynamic_initializer_for__Test_Loop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_Loop_command__()
{
  ConCommand::ConCommand(
    this: &Test_Loop_command,
    pName: "Test_Loop",
    callback: Test_Loop,
    pHelpString: "Test_Loop <loop name> - loop back to the specified loop start point unconditionally.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_Loop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E580
// Name: _dynamic_initializer_for__Test_LoopForNumSeconds_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_LoopForNumSeconds_command__()
{
  ConCommand::ConCommand(
    this: &Test_LoopForNumSeconds_command,
    pName: "Test_LoopForNumSeconds",
    callback: Test_LoopForNumSeconds,
    pHelpString: "Test_LoopForNumSeconds <loop name> <time> - loop back to the specified start point for the specified # of seconds.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E5B0
// Name: _dynamic_initializer_for__Test_RandomChance_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_RandomChance_command__()
{
  ConCommand::ConCommand(
    this: &Test_RandomChance_command,
    pName: "Test_RandomChance",
    callback: (void (__cdecl *)(const CCommand *))Test_RandomChance,
    pHelpString: "Test_RandomChance <percent chance, 0-100> <token1> <token2...> - Roll the dice and maybe run the command following t"
    "he percentage chance.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_RandomChance_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E5E0
// Name: _dynamic_initializer_for__Test_SendKey_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_SendKey_command__()
{
  ConCommand::ConCommand(
    this: &Test_SendKey_command,
    pName: "Test_SendKey",
    callback: Test_SendKey,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_SendKey_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E610
// Name: _dynamic_initializer_for__Test_StartScript_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_StartScript_command__()
{
  ConCommand::ConCommand(
    this: &Test_StartScript_command,
    pName: "Test_StartScript",
    callback: Test_StartScript,
    pHelpString: "Start a test script running..",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_StartScript_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326E80
// Name: _dynamic_atexit_destructor_for__testscript_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__testscript_debug__()
{
  ConVar::~ConVar(this: &testscript_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10326E90
// Name: _dynamic_atexit_destructor_for__testscript_running__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__testscript_running__()
{
  ConVar::~ConVar(this: &testscript_running);
}

//------------------------------------------------------------------------------
// Address: 0x10326EA0
// Name: _dynamic_atexit_destructor_for__Test_Wait_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_Wait_command__()
{
  ConCommand::~ConCommand(this: &Test_Wait_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EB0
// Name: _dynamic_atexit_destructor_for__Test_RunFrame_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_RunFrame_command__()
{
  ConCommand::~ConCommand(this: &Test_RunFrame_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EC0
// Name: _dynamic_atexit_destructor_for__Test_WaitForCheckPoint_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_WaitForCheckPoint_command__()
{
  ConCommand::~ConCommand(this: &Test_WaitForCheckPoint_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326ED0
// Name: _dynamic_atexit_destructor_for__Test_StartLoop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_StartLoop_command__()
{
  ConCommand::~ConCommand(this: &Test_StartLoop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EE0
// Name: _dynamic_atexit_destructor_for__Test_LoopCount_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_LoopCount_command__()
{
  ConCommand::~ConCommand(this: &Test_LoopCount_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EF0
// Name: _dynamic_atexit_destructor_for__Test_Loop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_Loop_command__()
{
  ConCommand::~ConCommand(this: &Test_Loop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F00
// Name: _dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__()
{
  ConCommand::~ConCommand(this: &Test_LoopForNumSeconds_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F10
// Name: _dynamic_atexit_destructor_for__Test_RandomChance_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_RandomChance_command__()
{
  ConCommand::~ConCommand(this: &Test_RandomChance_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F20
// Name: _dynamic_atexit_destructor_for__Test_SendKey_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_SendKey_command__()
{
  ConCommand::~ConCommand(this: &Test_SendKey_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F30
// Name: _dynamic_atexit_destructor_for__Test_StartScript_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_StartScript_command__()
{
  ConCommand::~ConCommand(this: &Test_StartScript_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031E640
// Name: _dynamic_initializer_for__g_InitTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_InitTracker__()
{
  int v0; // edx
  int *p_m_nGrowSize; // eax

  v0 = 3;
  p_m_nGrowSize = &g_InitTracker.m_Funcs[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v0;
  }
  while ( v0 >= 0 );
  g_InitTracker.m_nNumFuncs[0] = 0;
  g_InitTracker.m_nNumFuncs[1] = 0;
  g_InitTracker.m_nNumFuncs[2] = 0;
  g_InitTracker.m_nNumFuncs[3] = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_InitTracker__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E690
// Name: _dynamic_initializer_for____g_CVoiceServer_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CVoiceServer_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CVoiceServer_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E6A0
// Name: _dynamic_initializer_for____g_CreateCVoiceServerIVoiceServer_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVoiceServerIVoiceServer_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVoiceServerIVoiceServer_reg,
           fn: _CreateCVoiceServerIVoiceServer_interface,
           pName: "VoiceServer002");
}

//------------------------------------------------------------------------------
// Address: 0x10326F40
// Name: _dynamic_atexit_destructor_for__g_TestScriptMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TestScriptMgr__()
{
  CTestScriptMgr::~CTestScriptMgr(this: &g_TestScriptMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10326F50
// Name: _dynamic_atexit_destructor_for__g_InitTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_InitTracker__()
{
  CInitTracker::~CInitTracker(this: &g_InitTracker);
}

//------------------------------------------------------------------------------
// Address: 0x10326F60
// Name: _dynamic_atexit_destructor_for____g_CVoiceServer_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_CVoiceServer_singleton__()
{
  _g_CVoiceServer_singleton.__vftable = (CVoiceServer_vtbl *)&IVoiceServer::`vftable';
}

} // namespace engine_xlsp
