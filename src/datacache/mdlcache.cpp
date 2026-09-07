// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datacache/mdlcache.cpp
// Functions: 179
// ============================================================

#include "datacache\mdlcache.h"

//------------------------------------------------------------------------------
// Address: 0x100015E0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pBlocks; // eax

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
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nGrowSize + 8);
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
// Address: 0x100017F0
// Name: public: virtual void CMDLCache::InitPreloadData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::InitPreloadData(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100028C0
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::AllocInternal(
        CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)this->m_FirstFree;
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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Next(
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
    CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Next(
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
      if ( `CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002B10
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pNext; // eax

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
// Address: 0x100034B0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::RemoveAll(
        CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *this)
{
  CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

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
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Next(
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
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *)v5;
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
// Address: 0x10003DE0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::Unlink(
        CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *this,
        unsigned int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::IsIdxAfter(
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
// Address: 0x10003E40
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::Purge(
        CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::RemoveAll(this);
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
// Address: 0x10003E90
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::Free(
        CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 8);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Head = *(_DWORD *)(elem + 12);
      v4 = *(_DWORD *)(elem + 12);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Tail = *(_DWORD *)(elem + 8);
      *(_DWORD *)(elem + 12) = elem;
      *(_DWORD *)(elem + 8) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 12) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004260
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::LinkBefore(
        CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::IsIdxAfter(
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
// Address: 0x10004E70
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10004EA0
// Name: public: static float float16::Convert16bitFloatTo32bits(unsigned short)
// Source: json
//------------------------------------------------------------------------------
double __cdecl float16::Convert16bitFloatTo32bits(unsigned int input)
{
  int v1; // ecx
  float v3; // xmm0_4

  v1 = (input >> 10) & 0x1F;
  if ( v1 == 31 )
  {
    if ( (input & 0x3FF) != 0 )
    {
      return 0.0;
    }
    else if ( (input & 0x8000) != 0 )
    {
      return -1.0 * 65504.0;
    }
    else
    {
      return 1.0 * 65504.0;
    }
  }
  else if ( (_WORD)v1 != 0 || (input & 0x3FF) == 0 )
  {
    return COERCE_FLOAT((input & 0x3FF
                       | (8
                        * (input & 0x8000
                         | ((((((unsigned __int16)input >> 10) & 0x1F) + 112)
                           * ((((unsigned __int16)input >> 10) & 0x1F) != 0)) << 7)))) << 13);
  }
  else
  {
    if ( (input & 0x8000) != 0 )
      v3 = -1.0;
    else
      v3 = 1.0;
    return (float)((float)(v3 * (float)((float)(input & 0x3FF) * 0.0009765625)) * 0.000061035156);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004FA0
// Name: bool Studio_ConvertStudioHdrToNewVersion(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Studio_ConvertStudioHdrToNewVersion(studiohdr_t *pStudioHdr)
{
  int v2; // ebx
  int v4; // edx
  int v5; // ecx
  unsigned __int8 *v6; // edi
  int k; // edx
  int v8; // ecx
  char *v9; // ecx
  int m; // edi
  int v11; // ecx
  char *v12; // ecx
  int v13; // edx
  int j; // edx
  int v15; // ecx
  char *v16; // ecx
  int version; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  char bResult_3; // [esp+1Bh] [ebp+Bh]

  v2 = pStudioHdr->version;
  version = v2;
  if ( v2 == 49 )
    return 1;
  bResult_3 = 1;
  if ( v2 < 46 )
  {
    v4 = 0;
    for ( i = 0; v4 < pStudioHdr->numlocalanim; i = v4 )
    {
      v5 = v4;
      if ( v4 < 0 || v4 >= pStudioHdr->numlocalanim )
        v5 = 0;
      v6 = (unsigned __int8 *)pStudioHdr + 100 * v5 + pStudioHdr->localanimindex;
      if ( *((_DWORD *)v6 + 21) != 0 )
      {
        memset(dst: v6 + 16, value: 0, count: 0x54u);
        v4 = i;
        *((_DWORD *)v6 + 4) = 1;
        v2 = version;
        *((_DWORD *)v6 + 13) = -1;
        bResult_3 = 0;
      }
      ++v4;
    }
  }
  if ( v2 >= 47 )
  {
    if ( v2 == 47 )
    {
      for ( j = 0; j < pStudioHdr->numlocalanim; ++j )
      {
        v15 = j;
        if ( j < 0 || j >= pStudioHdr->numlocalanim )
          v15 = 0;
        v16 = (char *)pStudioHdr + 100 * v15 + pStudioHdr->localanimindex;
        if ( *((_DWORD *)v16 + 23) != 0 )
        {
          *((_DWORD *)v16 + 23) = 0;
          *((_WORD *)v16 + 44) = 0;
          bResult_3 = 0;
        }
      }
      goto LABEL_20;
    }
  }
  else
  {
    if ( pStudioHdr->unused4 != 0 )
    {
      pStudioHdr->unused4 = 0;
      bResult_3 = 0;
    }
    for ( k = 0; k < pStudioHdr->numlocalanim; *((_WORD *)v9 + 44) = 0 )
    {
      v8 = k;
      if ( k < 0 || k >= pStudioHdr->numlocalanim )
        v8 = 0;
      v9 = (char *)pStudioHdr + 100 * v8 + pStudioHdr->localanimindex;
      ++k;
      *((_DWORD *)v9 + 23) = 0;
    }
  }
  if ( v2 < 49 )
  {
LABEL_20:
    for ( m = 0; m < pStudioHdr->numlocalanim; ++m )
    {
      v11 = m;
      if ( m < 0 || m >= pStudioHdr->numlocalanim )
        v11 = 0;
      v12 = (char *)pStudioHdr + 100 * v11 + pStudioHdr->localanimindex;
      v13 = *((_DWORD *)v12 + 3);
      if ( (v13 & 0x40) != 0 )
      {
        *((_DWORD *)v12 + 3) = v13 & 0xFFFFFFBF;
        bResult_3 = 0;
      }
    }
  }
  pStudioHdr->version = 49;
  return bResult_3;
}

//------------------------------------------------------------------------------
// Address: 0x10005120
// Name: void Studio_SetRootLOD(struct studiohdr_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Studio_SetRootLOD(studiohdr_t *pStudioHdr, int rootLOD)
{
  studiohdr_t *v2; // edx
  unsigned __int8 numAllowedRootLODs; // al
  int v4; // ecx
  mstudiobodyparts_t *v5; // eax
  int v6; // edi
  _DWORD *v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // ebx
  mstudiobodyparts_t *pBodyPart; // [esp+0h] [ebp-1Ch]
  int bodyPartID; // [esp+4h] [ebp-18h]
  int modelID; // [esp+8h] [ebp-14h]
  int tangentsindex; // [esp+Ch] [ebp-10h]
  int vertexindex; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]

  v2 = pStudioHdr;
  numAllowedRootLODs = pStudioHdr->numAllowedRootLODs;
  v4 = 0;
  if ( numAllowedRootLODs != 0 && rootLOD >= numAllowedRootLODs )
    rootLOD = numAllowedRootLODs - 1;
  vertexindex = 0;
  tangentsindex = 0;
  bodyPartID = 0;
  if ( pStudioHdr->numbodyparts <= 0 )
  {
    pStudioHdr->rootLOD = rootLOD;
  }
  else
  {
    v16 = 0;
    do
    {
      modelID = 0;
      v5 = (mstudiobodyparts_t *)((char *)v2 + v16 + v2->bodypartindex);
      pBodyPart = v5;
      if ( v5->nummodels > 0 )
      {
        v17 = 0;
        while ( 1 )
        {
          v6 = 0;
          v7 = (int *)((char *)&v5->sznameindex + v17 + v5->modelindex);
          if ( (int)v7[18] > 0 )
          {
            v8 = 0;
            do
            {
              v9 = (int)&v7[v8] + v7[19];
              ++v6;
              v10 = *(_DWORD *)(v9 + 4 * rootLOD + 52);
              *(_DWORD *)(v9 + 12) = v4;
              *(_DWORD *)(v9 + 8) = v10;
              v4 += v10;
              v8 += 29;
            }
            while ( v6 < v7[18] );
            v5 = pBodyPart;
            v2 = pStudioHdr;
          }
          v17 += 148;
          v7[20] = v4;
          v7[21] = vertexindex;
          v7[22] = tangentsindex;
          vertexindex += 48 * v4;
          tangentsindex += 16 * v4;
          if ( ++modelID >= v5->nummodels )
            break;
          v4 = 0;
        }
        v4 = 0;
      }
      v16 += 16;
      ++bodyPartID;
    }
    while ( bodyPartID < v2->numbodyparts );
    v2->rootLOD = rootLOD;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005230
// Name: int Studio_LoadVertexes(struct vertexFileHeader_t const __near *,struct vertexFileHeader_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Studio_LoadVertexes(
        vertexFileHeader_t *pTempVvdHdr,
        vertexFileHeader_t *pNewVvdHdr,
        int rootLOD,
        bool bNeedsTangentS)
{
  int j; // ecx
  int *numLODVertexes; // eax
  int result; // eax
  _DWORD *v9; // ebx
  unsigned int vertexDataStart; // [esp-4h] [ebp-10h]
  int numVertexes; // [esp+14h] [ebp+8h]
  int numVertexesa; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  vertexDataStart = pTempVvdHdr->vertexDataStart;
  numVertexes = pTempVvdHdr->numLODVertexes[rootLOD];
  memcpy(dst: (unsigned __int8 *)pNewVvdHdr, src: (unsigned __int8 *)pTempVvdHdr, count: vertexDataStart);
  j = 0;
  if ( rootLOD > 0 )
  {
    numLODVertexes = pNewVvdHdr->numLODVertexes;
    for ( j = rootLOD; j != 0; --j )
      *numLODVertexes++ = pNewVvdHdr->numLODVertexes[rootLOD];
  }
  if ( bNeedsTangentS )
    pNewVvdHdr->tangentDataStart = pNewVvdHdr->vertexDataStart + 48 * numVertexes;
  else
    pNewVvdHdr->tangentDataStart = j;
  if ( pNewVvdHdr->numFixups == j )
  {
    memcpy(
      dst: (unsigned __int8 *)pNewVvdHdr + pNewVvdHdr->vertexDataStart,
      src: (unsigned __int8 *)pTempVvdHdr + pTempVvdHdr->vertexDataStart,
      count: 48 * numVertexes);
    if ( bNeedsTangentS )
      memcpy(
        dst: (unsigned __int8 *)pNewVvdHdr + pNewVvdHdr->tangentDataStart,
        src: (unsigned __int8 *)pTempVvdHdr + pTempVvdHdr->tangentDataStart,
        count: 16 * numVertexes);
    return numVertexes;
  }
  else
  {
    result = 0;
    numVertexesa = 0;
    i = j;
    if ( pTempVvdHdr->numFixups > j )
    {
      v9 = (int *)((char *)&pTempVvdHdr->checksum + pTempVvdHdr->fixupTableStart);
      do
      {
        if ( *(v9 - 2) >= rootLOD )
        {
          memcpy(
            dst: (unsigned __int8 *)pNewVvdHdr + 48 * result + pNewVvdHdr->vertexDataStart,
            src: (unsigned __int8 *)pTempVvdHdr + 48 * *(v9 - 1) + pTempVvdHdr->vertexDataStart,
            count: 48 * *v9);
          if ( bNeedsTangentS )
            memcpy(
              dst: (unsigned __int8 *)pNewVvdHdr + 16 * numVertexesa + pNewVvdHdr->tangentDataStart,
              src: (unsigned __int8 *)pTempVvdHdr + 16 * *(v9 - 1) + pTempVvdHdr->tangentDataStart,
              count: 16 * *v9);
          numVertexesa += *v9;
          result = numVertexesa;
        }
        v9 += 3;
        ++i;
      }
      while ( i < pTempVvdHdr->numFixups );
      j = 0;
    }
    pNewVvdHdr->numFixups = j;
    pNewVvdHdr->fixupTableStart = j;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005370
// Name: public: virtual bool CDefaultDataCacheClient::HandleCacheNotification(struct DataCacheNotification_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDefaultDataCacheClient::HandleCacheNotification(
        CDefaultDataCacheClient *this,
        const DataCacheNotification_t *notification)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10005380
// Name: public: static bool CModelSwapper::ModelSubstitution_t::AreEqual(struct CModelSwapper::ModelSubstitution_t const __near &,struct CModelSwapper::ModelSubstitution_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CModelSwapper::ModelSubstitution_t::AreEqual(
        const CModelSwapper::ModelSubstitution_t *lhs,
        const CModelSwapper::ModelSubstitution_t *rhs)
{
  return _V_stricmp(s1: lhs->pOriginalModelName, s2: rhs->pOriginalModelName) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100053A0
// Name: public: static unsigned int CModelSwapper::ModelSubstitution_t::Hash(struct CModelSwapper::ModelSubstitution_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CModelSwapper::ModelSubstitution_t::Hash(const CModelSwapper::ModelSubstitution_t *value)
{
  return HashStringCaseless(pszKey: value->pOriginalModelName);
}

//------------------------------------------------------------------------------
// Address: 0x100053B0
// Name: StudioHdrLookupSurfaceProps
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioHdrLookupSurfaceProps(studiohdr_t *pStudioHdrIn@<edi>)
{
  int v1; // ebx
  char *v2; // esi
  int v3; // [esp+4h] [ebp-4h]

  v1 = 0;
  pStudioHdrIn->surfacepropLookup = physprops->GetSurfaceIndex(
                                      this: physprops,
                                      a2: (char *)pStudioHdrIn + pStudioHdrIn->surfacepropindex);
  if ( pStudioHdrIn->numbones > 0 )
  {
    v3 = 0;
    do
    {
      v2 = (char *)pStudioHdrIn + v3 + pStudioHdrIn->boneindex;
      v3 += 216;
      ++v1;
      *((_DWORD *)v2 + 46) = physprops->GetSurfaceIndex(this: physprops, a2: &v2[*((_DWORD *)v2 + 44)]);
    }
    while ( v1 < pStudioHdrIn->numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005420
// Name: StudioHdrSetAnimEventFlag
// Source: json
//------------------------------------------------------------------------------
void __fastcall StudioHdrSetAnimEventFlag(int a1, studiohdr_t *pStudioHdrIn)
{
  int numlocalseq; // edi
  int v3; // ecx
  int v4; // eax

  numlocalseq = pStudioHdrIn->numlocalseq;
  v3 = 0;
  if ( numlocalseq <= 0 )
  {
LABEL_7:
    pStudioHdrIn->flags |= 0x100000u;
  }
  else
  {
    while ( 1 )
    {
      v4 = v3;
      if ( v3 < 0 || v3 >= numlocalseq )
        v4 = 0;
      if ( *(_DWORD *)&pStudioHdrIn->name[212 * v4 + 12 + pStudioHdrIn->localseqindex] != 0 )
        break;
      if ( ++v3 >= numlocalseq )
        goto LABEL_7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005470
// Name: public: virtual class IDataCacheSection __near * CMDLCache::GetCacheSection(enum MDLCacheDataType_t)
// Source: json
//------------------------------------------------------------------------------
IDataCacheSection *__thiscall CMDLCache::GetCacheSection(CMDLCache *this, MDLCacheDataType_t type)
{
  if ( type != MDLCACHE_STUDIOHWDATA )
  {
    if ( type == MDLCACHE_ANIMBLOCK )
      return this->m_pAnimBlocksCacheSection;
    if ( type != MDLCACHE_VERTEXES )
      return this->m_pModelCacheSection;
  }
  return this->m_pMeshCacheSection;
}

//------------------------------------------------------------------------------
// Address: 0x100054C0
// Name: public: void __near * CMDLCacheData::Detach(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMDLCacheData::Detach(CMDLCacheData *this)
{
  void *result; // eax

  result = this->m_pData;
  if ( this->m_pData != nullptr )
  {
    this->m_pData = nullptr;
    this->m_nDataSize = 0;
  }
  else
  {
    _Warning(a1: "ERROR: CMDLCacheData::Detach used incorrectly (there is no data to return!)\n");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100054F0
// Name: public: virtual void __near * CMDLCache::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IStudioDataCache *__thiscall CMDLCache::QueryInterface(CMDLCache *this, const char *pInterfaceName)
{
  int v3; // eax
  int v5; // eax

  v3 = _V_strlen(str: "VStudioDataCache005");
  if ( V_strncmp(s1: pInterfaceName, s2: "VStudioDataCache005", count: v3 + 1) != 0 )
  {
    v5 = _V_strlen(str: "MDLCache004");
    return V_strncmp(s1: pInterfaceName, s2: "MDLCache004", count: v5 + 1) == 0 ? (IStudioDataCache *)this : nullptr;
  }
  else if ( this != nullptr )
  {
    return &this->IStudioDataCache;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005560
// Name: public: virtual void CMDLCache::SetCacheNotify(class IMDLCacheNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::SetCacheNotify(CMDLCache *this, IMDLCacheNotify *pNotify)
{
  this->m_pCacheNotify = pNotify;
}

//------------------------------------------------------------------------------
// Address: 0x10005570
// Name: SortLessFuncWrinkle
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SortLessFuncWrinkle(const mstudiovertanim_wrinkle_t *left, const mstudiovertanim_wrinkle_t *right)
{
  return left->index < right->index;
}

//------------------------------------------------------------------------------
// Address: 0x10005590
// Name: private: void CMDLCache::UnloadHardwareData(struct studiodata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::UnloadHardwareData(CMDLCache *this, studiodata_t *pStudioData)
{
  if ( pStudioData != nullptr && (pStudioData->m_nFlags & 1) != 0 )
  {
    if ( this->m_pCacheNotify != nullptr )
      this->m_pCacheNotify->OnDataUnloaded(
        this: this->m_pCacheNotify,
        a2: MDLCACHE_STUDIOHWDATA,
        a3: pStudioData->m_Handle);
    g_pStudioRender->UnloadModel(this: g_pStudioRender, a2: &pStudioData->m_HardwareData);
    *(_QWORD *)&pStudioData->m_HardwareData.m_RootLOD = 0;
    *(_QWORD *)&pStudioData->m_HardwareData.m_pLODs = 0;
    *(_QWORD *)&pStudioData->m_HardwareData.m_NumFacesRenderedThisFrame = 0;
    pStudioData->m_HardwareData.m_pStudioHdr = nullptr;
    pStudioData->m_nFlags &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005600
// Name: private: virtual bool CMDLCache::GetItemName(unsigned int,void const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLCache::GetItemName(
        CMDLCache *this,
        unsigned int clientId,
        const void *pItem,
        char *pDest,
        unsigned int nMaxLen)
{
  const char *v5; // eax

  if ( pItem != (const void *)clientId )
  {
    v5 = (const char *)(*(int (__thiscall **)(char *, unsigned int))(*((_DWORD *)this - 2) + 108))(
                         a1: (char *)this - 8,
                         a2: HIWORD(clientId));
    V_snprintf(pDest, maxLen: nMaxLen, pFormat: "%s - %s", g_ppszTypes[(unsigned __int16)clientId], v5);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10005660
// Name: public: virtual void CMDLCache::BeginLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::BeginLock(CMDLCache *this)
{
  this->m_pModelCacheSection->BeginFrameLocking(this: this->m_pModelCacheSection);
  this->m_pMeshCacheSection->BeginFrameLocking(this: this->m_pMeshCacheSection);
  this->m_pAnimBlocksCacheSection->BeginFrameLocking(this: this->m_pAnimBlocksCacheSection);
}

//------------------------------------------------------------------------------
// Address: 0x10005690
// Name: public: virtual void CMDLCache::EndLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::EndLock(CMDLCache *this)
{
  this->m_pModelCacheSection->EndFrameLocking(this: this->m_pModelCacheSection);
  this->m_pMeshCacheSection->EndFrameLocking(this: this->m_pMeshCacheSection);
  this->m_pAnimBlocksCacheSection->EndFrameLocking(this: this->m_pAnimBlocksCacheSection);
}

//------------------------------------------------------------------------------
// Address: 0x100056C0
// Name: private: void CMDLCache::RestoreFrameLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::RestoreFrameLock(CMDLCache *this)
{
  for ( ; this->m_nModelCacheFrameLocks != 0; --this->m_nModelCacheFrameLocks )
    this->m_pModelCacheSection->BeginFrameLocking(this: this->m_pModelCacheSection);
  for ( ; this->m_nMeshCacheFrameLocks != 0; --this->m_nMeshCacheFrameLocks )
    this->m_pMeshCacheSection->BeginFrameLocking(this: this->m_pMeshCacheSection);
  for ( ; this->m_nAnimBlockCacheFrameLocks != 0; --this->m_nAnimBlockCacheFrameLocks )
    this->m_pAnimBlocksCacheSection->BeginFrameLocking(this: this->m_pAnimBlocksCacheSection);
}

//------------------------------------------------------------------------------
// Address: 0x10005730
// Name: public: virtual int __near * CMDLCache::GetFrameUnlockCounterPtrOLD(void)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CMDLCache::GetFrameUnlockCounterPtrOLD(CMDLCache *this)
{
  IDataCacheSection *v1; // eax

  v1 = this->GetCacheSection(this, a2: 0);
  return v1->GetFrameUnlockCounterPtr(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10005750
// Name: public: virtual int __near * CMDLCache::GetFrameUnlockCounterPtr(enum MDLCacheDataType_t)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CMDLCache::GetFrameUnlockCounterPtr(CMDLCache *this, MDLCacheDataType_t type)
{
  IDataCacheSection *v2; // eax

  v2 = this->GetCacheSection(this, a2: type);
  return v2->GetFrameUnlockCounterPtr(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10005770
// Name: public: void __near * CMDLCache::AllocData(enum MDLCacheDataType_t,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMDLCache::AllocData(CMDLCache *this, MDLCacheDataType_t type, int size)
{
  void *v3; // eax

  v3 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + 35);
  if ( v3 != nullptr )
  {
    *(_DWORD *)((((unsigned int)v3 + 35) & 0xFFFFFFE0) - 4) = v3;
    return ((unsigned int)v3 + 35) & 0xFFFFFFE0;
  }
  else
  {
    _Error(a1: "CMDLCache:: Out of memory");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100057B0
// Name: public: void CMDLCache::CacheData(struct memhandle_t__ __near * __near *,void __near *,int,char const __near *,enum MDLCacheDataType_t,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::CacheData(
        CMDLCache *this,
        memhandle_t__ **c,
        void *pData,
        int size,
        const char *name,
        MDLCacheDataType_t type,
        void *id)
{
  void *v7; // edi
  int v8; // eax

  if ( pData != nullptr )
  {
    v7 = id;
    if ( id == (void *)-1 )
      v7 = pData;
    v8 = ((int (__stdcall *)(MDLCacheDataType_t))this->GetCacheSection)(a1: type);
    (*(void (__thiscall **)(int, void *, void *, int, memhandle_t__ **))(*(_DWORD *)v8 + 28))(
      a1: v8,
      a2: v7,
      a3: pData,
      a4: size,
      a5: c);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100057F0
// Name: public: void __near * CMDLCache::CheckData(struct memhandle_t__ __near *,enum MDLCacheDataType_t)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMDLCache::CheckData(CMDLCache *this, memhandle_t__ *c, MDLCacheDataType_t type)
{
  IDataCacheSection *v3; // eax

  v3 = this->GetCacheSection(this, a2: type);
  return v3->Get(this: v3, a2: c, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10005820
// Name: public: void __near * CFixedBudgetMemoryPool<65536,137>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CFixedBudgetMemoryPool<65536,137>::Alloc(CFixedBudgetMemoryPool<65536,137> *this)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int8 *v3; // eax
  TSLNodeBase_t *v4; // edi
  int i; // ebx
  TSLNodeBase_t *Next; // edi
  int DepthAndSequence; // eax

  if ( this->m_pBase == nullptr )
  {
    if ( (`CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::`local static guard' & 1) == 0 )
    {
      `CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::`local static guard' |= 1u;
      `CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::autoMutex__.m_ownerID = 0;
      `CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::autoMutex__.m_depth = 0;
    }
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != `CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::autoMutex__.m_ownerID
      && _InterlockedCompareExchange(
           (volatile signed __int32 *)&`CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::autoMutex__,
           CurrentThreadId,
           0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(
        a1: &`CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::autoMutex__,
        a2: CurrentThreadId,
        a3: 0);
    }
    else
    {
      ++`CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::autoMutex__.m_depth;
    }
    if ( this->m_pBase == nullptr )
    {
      v3 = (unsigned __int8 *)operator new(nSize: 0x890000u);
      this->m_pBase = v3;
      v4 = (TSLNodeBase_t *)v3;
      this->m_pLimit = v3 + 8978432;
      for ( i = 137; i != 0; --i )
      {
        CTSListBase::Push(this: &this->m_freeList, pNode: v4);
        v4 += 0x2000;
      }
    }
    if ( --`CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::autoMutex__.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&`CFixedBudgetMemoryPool<65536,137>::Alloc'::`5'::autoMutex__, 0);
  }
  Next = this->m_freeList.m_Head.value.Next;
  DepthAndSequence = this->m_freeList.m_Head.value32.DepthAndSequence;
  if ( this->m_freeList.m_Head.value.Next == nullptr )
    return (TSLNodeBase_t *)operator new(nSize: 0x10000u);
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_freeList.m_Head.value.Next;
    DepthAndSequence = this->m_freeList.m_Head.value32.DepthAndSequence;
    if ( this->m_freeList.m_Head.value.Next == nullptr )
      return (TSLNodeBase_t *)operator new(nSize: 0x10000u);
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10005930
// Name: public: static bool CDefOps<int>::LessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<int>::LessFunc(const int *lhs, const int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10005950
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct AsyncInfo_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *m_pBlocks; // eax

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
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: 24 * m_nGrowSize + 8);
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
// Address: 0x100059E0
// Name: void std::_Push_heap<struct mstudiovertanim_t __near *,int,struct mstudiovertanim_t,bool (*)(struct mstudiovertanim_t const __near &,struct mstudiovertanim_t const __near &)>(struct mstudiovertanim_t __near *,int,int,struct mstudiovertanim_t __near &&,bool (*)(struct mstudiovertanim_t const __near &,struct mstudiovertanim_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<mstudiovertanim_t *,int,mstudiovertanim_t,bool (__cdecl *)(mstudiovertanim_t const &,mstudiovertanim_t const &)>(
        mstudiovertanim_t *_First,
        int _Hole,
        int _Top,
        mstudiovertanim_t *_Val,
        bool (__cdecl *_Pred)(const mstudiovertanim_t *, const mstudiovertanim_t *))
{
  int v5; // edi
  int i; // esi
  mstudiovertanim_t *v7; // ebx
  mstudiovertanim_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    *(_QWORD *)&v8->index = *(_QWORD *)&v7->index;
    *(_QWORD *)&v8->flDelta[2].m_storage.rawWord = *(_QWORD *)&v7->flDelta[2].m_storage.rawWord;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10005A60
// Name: void std::_Push_heap<struct mstudiovertanim_wrinkle_t __near *,int,struct mstudiovertanim_wrinkle_t,bool (*)(struct mstudiovertanim_wrinkle_t const __near &,struct mstudiovertanim_wrinkle_t const __near &)>(struct mstudiovertanim_wrinkle_t __near *,int,int,struct mstudiovertanim_wrinkle_t __near &&,bool (*)(struct mstudiovertanim_wrinkle_t const __near &,struct mstudiovertanim_wrinkle_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<mstudiovertanim_wrinkle_t *,int,mstudiovertanim_wrinkle_t,bool (__cdecl *)(mstudiovertanim_wrinkle_t const &,mstudiovertanim_wrinkle_t const &)>(
        mstudiovertanim_wrinkle_t *_First,
        int _Hole,
        int _Top,
        mstudiovertanim_wrinkle_t *_Val,
        bool (__cdecl *_Pred)(const mstudiovertanim_wrinkle_t *, const mstudiovertanim_wrinkle_t *))
{
  int v5; // edi
  int i; // esi
  mstudiovertanim_wrinkle_t *v7; // ebx
  mstudiovertanim_wrinkle_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    *(_QWORD *)&v8->index = *(_QWORD *)&v7->index;
    *(_QWORD *)&v8->flDelta[2].m_storage.rawWord = *(_QWORD *)&v7->flDelta[2].m_storage.rawWord;
    v8->wrinkledelta = v7->wrinkledelta;
    v5 = i;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10005B00
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int16 *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005B90
// Name: public: void CUtlMemory<unsigned long,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned long,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005C20
// Name: public: void mstudiovertanim_t::ConvertToFixed(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mstudiovertanim_t::ConvertToFixed(mstudiovertanim_t *this, float flVertAnimFixedPointScale)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v7; // [esp-18h] [ebp-1Ch]
  unsigned int v8; // [esp-14h] [ebp-18h]
  unsigned int v9; // [esp-Ch] [ebp-10h]
  unsigned int rawWord; // [esp-8h] [ebp-Ch]
  float flVertAnimFixedPointScalea; // [esp+Ch] [ebp+8h]

  flVertAnimFixedPointScalea = 1.0 / flVertAnimFixedPointScale;
  v3 = (int)(float16::Convert16bitFloatTo32bits(input: this->flDelta[0].m_storage.rawWord) * flVertAnimFixedPointScalea);
  rawWord = this->flDelta[1].m_storage.rawWord;
  this->delta[0] = v3;
  v4 = (int)(float16::Convert16bitFloatTo32bits(input: rawWord) * flVertAnimFixedPointScalea);
  v9 = this->flDelta[2].m_storage.rawWord;
  this->delta[1] = v4;
  this->delta[2] = (int)(float16::Convert16bitFloatTo32bits(input: v9) * flVertAnimFixedPointScalea);
  v5 = (int)(float16::Convert16bitFloatTo32bits(input: this->flNDelta[0].m_storage.rawWord) * flVertAnimFixedPointScalea);
  v8 = this->flNDelta[1].m_storage.rawWord;
  this->ndelta[0] = v5;
  v6 = (int)(float16::Convert16bitFloatTo32bits(input: v8) * flVertAnimFixedPointScalea);
  v7 = this->flNDelta[2].m_storage.rawWord;
  this->ndelta[1] = v6;
  this->ndelta[2] = (int)(float16::Convert16bitFloatTo32bits(input: v7) * flVertAnimFixedPointScalea);
}

//------------------------------------------------------------------------------
// Address: 0x10005CC0
// Name: public: char const __near * studiohdr_t::pszName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall studiohdr_t::pszName(studiohdr_t *this)
{
  int studiohdr2index; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // ecx

  studiohdr2index = this->studiohdr2index;
  if ( studiohdr2index == 0 )
    return this->name;
  v2 = *(_DWORD *)&this->name[studiohdr2index + 8];
  v3 = (char *)this + studiohdr2index;
  if ( v2 == 0 || &v3[v2] == nullptr )
    return this->name;
  v4 = *((_DWORD *)v3 + 5);
  if ( v4 != 0 )
    return &v3[v4];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10005CF0
// Name: public: static void __near * studiodata_t::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl studiodata_t::operator new(unsigned int size)
{
  DWORD CurrentThreadId; // ecx
  void *result; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != studiodata_t::s_Allocator.m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&studiodata_t::s_Allocator.m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &studiodata_t::s_Allocator.m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++studiodata_t::s_Allocator.m_mutex.m_depth;
  }
  result = CUtlMemoryPool::Alloc(this: &studiodata_t::s_Allocator, amount: size);
  if ( --studiodata_t::s_Allocator.m_mutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&studiodata_t::s_Allocator.m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005D60
// Name: public: static void studiodata_t::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl studiodata_t::operator delete(void *p)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != studiodata_t::s_Allocator.m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&studiodata_t::s_Allocator.m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &studiodata_t::s_Allocator.m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++studiodata_t::s_Allocator.m_mutex.m_depth;
  }
  CUtlMemoryPool::Free(this: &studiodata_t::s_Allocator, memBlock: p);
  if ( --studiodata_t::s_Allocator.m_mutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&studiodata_t::s_Allocator.m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10005DD0
// Name: void FreeAnimBlock(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeAnimBlock(TSLNodeBase_t *p)
{
  if ( (unsigned __int8 *)p < g_AnimBlockAllocator.m_pBase || (unsigned __int8 *)p >= g_AnimBlockAllocator.m_pLimit )
    g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: p);
  else
    CTSListBase::Push(this: &g_AnimBlockAllocator.m_freeList, pNode: p);
}

//------------------------------------------------------------------------------
// Address: 0x10005E10
// Name: MakeFilename
// Source: json
//------------------------------------------------------------------------------
void __usercall MakeFilename(char *szFileName@<esi>, studiohdr_t *pStudioHdr@<edx>, const char *pszExtension)
{
  int studiohdr2index; // eax
  int v4; // ecx
  char *v5; // eax
  int v6; // ecx
  char *name; // eax
  char szBaseModelName[260]; // [esp+0h] [ebp-104h] BYREF

  studiohdr2index = pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v4 = *(_DWORD *)&pStudioHdr->name[studiohdr2index + 8], v5 = (char *)pStudioHdr + studiohdr2index, v4 != 0)
    && &v5[v4] != nullptr )
  {
    v6 = *((_DWORD *)v5 + 5);
    if ( v6 != 0 )
      name = &v5[v6];
    else
      name = nullptr;
  }
  else
  {
    name = pStudioHdr->name;
  }
  V_StripExtension(in: name, out: szBaseModelName, outSize: 260);
  V_snprintf(pDest: szFileName, maxLen: 260, pFormat: "models/%s%s", szBaseModelName, pszExtension);
  V_FixSlashes(pname: szFileName, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x10005E80
// Name: private: void CMDLCacheData::Deallocate(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCacheData::Deallocate(CMDLCacheData *this, TSLNodeBase_t *pData)
{
  CMDLCacheData::AllocType_t m_AllocType; // eax
  __int32 v3; // eax

  m_AllocType = this->m_AllocType;
  if ( m_AllocType != ALLOC_MALLOC )
  {
    v3 = m_AllocType - 1;
    if ( v3 != 0 )
    {
      if ( v3 == 1 )
      {
        if ( (unsigned __int8 *)pData < g_AnimBlockAllocator.m_pBase
          || (unsigned __int8 *)pData >= g_AnimBlockAllocator.m_pLimit )
        {
          g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: pData);
        }
        else
        {
          CTSListBase::Push(this: &g_AnimBlockAllocator.m_freeList, pNode: pData);
        }
      }
    }
    else
    {
      g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: pData);
    }
  }
  else
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005EF0
// Name: public: virtual bool CDefaultDataCacheClient::GetItemName(unsigned int,void const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDefaultDataCacheClient::GetItemName(
        CDefaultDataCacheClient *this,
        unsigned int clientId,
        unsigned int pItem,
        char *pDest,
        char *nMaxLen)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10005F30
// Name: public: virtual struct virtualmodel_t __near * CMDLCache::GetVirtualModel(unsigned short)
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall CMDLCache::GetVirtualModel(CMDLCache *this, int handle)
{
  const studiohdr_t *v4; // eax

  if ( mod_test_not_available.m_pParent != nullptr && mod_test_not_available.m_pParent->m_Value.m_nValue != 0 )
    return nullptr;
  if ( (_WORD)handle != 0xFFFF )
  {
    v4 = this->GetStudioHdr(this, a2: handle);
    if ( v4 != nullptr )
      return this->GetVirtualModelFast(this, a2: v4, a3: handle);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10005F80
// Name: private: bool CMDLCache::BuildHardwareData(unsigned short,struct studiodata_t __near *,struct studiohdr_t __near *,class CMDLCacheData __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::BuildHardwareData(
        CMDLCache *this,
        int handle,
        studiodata_t *pStudioData,
        studiohdr_t *pStudioHdr,
        OptimizedModel::FileHeader_t *cacheData)
{
  OptimizedModel::FileHeader_t *version; // ecx
  ConVar *m_pParent; // eax
  int studiohdr2index; // eax
  int v9; // ecx
  char *v10; // eax
  int v11; // ecx
  char *name; // eax
  int v14; // eax
  int v15; // ecx
  char *v16; // eax
  int v17; // ecx
  char *v18; // eax
  bool v19; // bl
  OptimizedModel::FileHeader_t *pVtxHdr; // [esp+20h] [ebp+14h]

  version = (OptimizedModel::FileHeader_t *)cacheData->version;
  pVtxHdr = version;
  if ( version == nullptr )
    goto LABEL_16;
  m_pParent = mod_trace_load.m_pParent;
  if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
  {
    studiohdr2index = pStudioHdr->studiohdr2index;
    if ( studiohdr2index != 0
      && (v9 = *(_DWORD *)&pStudioHdr->name[studiohdr2index + 8], v10 = (char *)pStudioHdr + studiohdr2index, v9 != 0)
      && &v10[v9] != nullptr )
    {
      v11 = *((_DWORD *)v10 + 5);
      if ( v11 != 0 )
        name = &v10[v11];
      else
        name = nullptr;
    }
    else
    {
      name = pStudioHdr->name;
    }
    _Msg(a1: "MDLCache: Alloc VTX %s\n", name);
    m_pParent = mod_trace_load.m_pParent;
    version = pVtxHdr;
  }
  if ( version->version != 7 )
  {
    _Warning(a1: "Error Index File for '%s' version %d should be %d\n");
LABEL_16:
    pStudioData->m_nFlags |= 8u;
    return 0;
  }
  if ( version->checkSum != pStudioHdr->checksum )
  {
    _Warning(a1: "Error Index File for '%s' checksum %ld should be %ld\n");
    goto LABEL_16;
  }
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
    v14 = pStudioHdr->studiohdr2index;
    if ( v14 != 0
      && (v15 = *(_DWORD *)&pStudioHdr->name[v14 + 8], v16 = (char *)pStudioHdr + v14, v15 != 0)
      && &v16[v15] != nullptr )
    {
      v17 = *((_DWORD *)v16 + 5);
      if ( v17 != 0 )
        v18 = &v16[v17];
      else
        v18 = nullptr;
    }
    else
    {
      v18 = pStudioHdr->name;
    }
    _Msg(a1: "MDLCache: Load studiomdl %s\n", v18);
  }
  this->BeginCoarseLock(this);
  this->BeginLock(this);
  v19 = g_pStudioRender->LoadModel(this: g_pStudioRender, a2: pStudioHdr, a3: pVtxHdr, a4: &pStudioData->m_HardwareData);
  this->EndLock(this);
  this->EndCoarseLock(this);
  if ( v19 )
    pStudioData->m_nFlags |= 1u;
  else
    pStudioData->m_nFlags |= 8u;
  if ( this->m_pCacheNotify != nullptr )
    this->m_pCacheNotify->OnDataLoaded(this: this->m_pCacheNotify, a2: MDLCACHE_STUDIOHWDATA, a3: handle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006150
// Name: private: virtual bool CMDLCache::GetAsyncLoad(enum MDLCacheDataType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLCache::GetAsyncLoad(CMDLCache *this, MDLCacheDataType_t type)
{
  bool result; // al

  switch ( type )
  {
    case MDLCACHE_STUDIOHWDATA:
      if ( mod_load_mesh_async.m_pParent == nullptr )
        goto LABEL_4;
      result = mod_load_mesh_async.m_pParent->m_Value.m_nValue != 0;
      break;
    case MDLCACHE_VCOLLIDE:
      if ( mod_load_vcollide_async.m_pParent == nullptr )
        goto LABEL_7;
      result = mod_load_vcollide_async.m_pParent->m_Value.m_nValue != 0;
      break;
    case MDLCACHE_ANIMBLOCK:
      if ( mod_load_anims_async.m_pParent != nullptr )
        result = mod_load_anims_async.m_pParent->m_Value.m_nValue != 0;
      else
LABEL_4:
        result = false;
      break;
    case MDLCACHE_VERTEXES:
      if ( mod_load_mesh_async.m_pParent != nullptr )
        result = mod_load_mesh_async.m_pParent->m_Value.m_nValue != 0;
      else
LABEL_7:
        result = false;
      break;
    default:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006200
// Name: private: virtual bool CMDLCache::SetAsyncLoad(enum MDLCacheDataType_t,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLCache::SetAsyncLoad(CMDLCache *this, MDLCacheDataType_t type, bool bAsync)
{
  bool v3; // bl
  int m_nValue; // eax
  bool v5; // bl
  bool result; // al
  bool v7; // bl

  v3 = false;
  switch ( type )
  {
    case MDLCACHE_STUDIOHWDATA:
    case MDLCACHE_VERTEXES:
      if ( mod_load_mesh_async.m_pParent != nullptr )
        m_nValue = mod_load_mesh_async.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v3 = m_nValue != 0;
      ConVar::SetValue(this: (ConVar *)&mod_load_mesh_async.IConVar, value: bAsync);
      goto LABEL_13;
    case MDLCACHE_VCOLLIDE:
      if ( mod_load_vcollide_async.m_pParent != nullptr )
      {
        v5 = mod_load_vcollide_async.m_pParent->m_Value.m_nValue != 0;
        ConVar::SetValue(this: (ConVar *)&mod_load_vcollide_async.IConVar, value: bAsync);
        result = v5;
      }
      else
      {
        ConVar::SetValue(this: (ConVar *)&mod_load_vcollide_async.IConVar, value: bAsync);
        result = false;
      }
      break;
    case MDLCACHE_ANIMBLOCK:
      if ( mod_load_anims_async.m_pParent != nullptr )
      {
        v7 = mod_load_anims_async.m_pParent->m_Value.m_nValue != 0;
        ConVar::SetValue(this: (ConVar *)&mod_load_anims_async.IConVar, value: bAsync);
        result = v7;
      }
      else
      {
        ConVar::SetValue(this: (ConVar *)&mod_load_anims_async.IConVar, value: bAsync);
        result = false;
      }
      break;
    case MDLCACHE_VIRTUALMODEL:
      result = false;
      break;
    default:
LABEL_13:
      result = v3;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100062F0
// Name: public: void CMDLCache::FreeData(enum MDLCacheDataType_t,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::FreeData(CMDLCache *this, MDLCacheDataType_t type, TSLNodeBase_t *pData)
{
  if ( type == MDLCACHE_ANIMBLOCK )
  {
    if ( (unsigned __int8 *)pData < g_AnimBlockAllocator.m_pBase
      || (unsigned __int8 *)pData >= g_AnimBlockAllocator.m_pLimit )
    {
      g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: pData);
    }
    else
    {
      CTSListBase::Push(this: &g_AnimBlockAllocator.m_freeList, pNode: pData);
    }
  }
  else if ( pData != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)pData & 0xFFFFFFFC) - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006350
// Name: public: CTSQueue<struct studiodata_t __near *,0,1>::CTSQueue<struct studiodata_t __near *,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<studiodata_t *,0,1> *__thiscall CTSQueue<studiodata_t *,0,1>::CTSQueue<studiodata_t *,0,1>(
        CTSQueue<studiodata_t *,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<studiodata_t *,0,1>::Node_t *v3; // eax

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
  v3 = (CTSQueue<studiodata_t *,0,1>::Node_t *)operator new(nSize: 8u);
  this->m_Tail.value.pNode = v3;
  this->m_Head.value.pNode = v3;
  v3->pNext = (CTSQueue<studiodata_t *,0,1>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100063E0
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::HashFastData_t_<struct memhandle_t__ __near *>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *(CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *)result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)m_pBlockHeader;
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
// Address: 0x10006460
// Name: void std::_Adjust_heap<struct mstudiovertanim_t __near *,int,struct mstudiovertanim_t,bool (*)(struct mstudiovertanim_t const __near &,struct mstudiovertanim_t const __near &)>(struct mstudiovertanim_t __near *,int,int,struct mstudiovertanim_t __near &&,bool (*)(struct mstudiovertanim_t const __near &,struct mstudiovertanim_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<mstudiovertanim_t *,int,mstudiovertanim_t,bool (__cdecl *)(mstudiovertanim_t const &,mstudiovertanim_t const &)>(
        mstudiovertanim_t *_First,
        int _Hole,
        int _Bottom,
        mstudiovertanim_t *_Val,
        bool (__cdecl *_Pred)(const mstudiovertanim_t *, const mstudiovertanim_t *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  int v9; // ecx
  __int64 v10; // xmm0_8
  int i; // esi
  const mstudiovertanim_t *_Bottoma; // [esp+1Ch] [ebp+10h]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = v6;
      v6 = v7;
      *(_QWORD *)&_First[v9].index = *(_QWORD *)&_First[v7].index;
      v10 = *(_QWORD *)&_First[v7].flDelta[2].m_storage.rawWord;
      v7 = 2 * v7 + 2;
      *(_QWORD *)&_First[v9].flDelta[2].m_storage.rawWord = v10;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  for ( i = (v6 - 1) / 2; _Hole < v6; i = (i - 1) / 2 )
  {
    _Bottoma = &_First[i];
    if ( !_Pred(a1: _Bottoma, a2: _Val) )
      break;
    _First[v6] = *_Bottoma;
    v6 = i;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10006570
// Name: void std::_Adjust_heap<struct mstudiovertanim_wrinkle_t __near *,int,struct mstudiovertanim_wrinkle_t,bool (*)(struct mstudiovertanim_wrinkle_t const __near &,struct mstudiovertanim_wrinkle_t const __near &)>(struct mstudiovertanim_wrinkle_t __near *,int,int,struct mstudiovertanim_wrinkle_t __near &&,bool (*)(struct mstudiovertanim_wrinkle_t const __near &,struct mstudiovertanim_wrinkle_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<mstudiovertanim_wrinkle_t *,int,mstudiovertanim_wrinkle_t,bool (__cdecl *)(mstudiovertanim_wrinkle_t const &,mstudiovertanim_wrinkle_t const &)>(
        mstudiovertanim_wrinkle_t *_First,
        int _Hole,
        int _Bottom,
        mstudiovertanim_wrinkle_t *_Val,
        bool (__cdecl *_Pred)(const mstudiovertanim_wrinkle_t *, const mstudiovertanim_wrinkle_t *))
{
  int v5; // eax
  int v6; // edi
  int v7; // esi
  bool v8; // zf
  mstudiovertanim_wrinkle_t *v9; // eax
  mstudiovertanim_wrinkle_t *v10; // ecx
  mstudiovertanim_wrinkle_t *v11; // ecx
  int i; // esi
  const mstudiovertanim_wrinkle_t *_Bottoma; // [esp+1Ch] [ebp+10h]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = &_First[v7];
      v10 = &_First[v6];
      *(_QWORD *)&v10->index = *(_QWORD *)&v9->index;
      *(_QWORD *)&v10->flDelta[2].m_storage.rawWord = *(_QWORD *)&v9->flDelta[2].m_storage.rawWord;
      v6 = v7;
      v7 = 2 * v7 + 2;
      v10->wrinkledelta = v9->wrinkledelta;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    v11 = &_First[v5 - 1];
    _First[v6] = *v11;
    v6 = v5 - 1;
  }
  for ( i = (v6 - 1) / 2; _Hole < v6; i = (i - 1) / 2 )
  {
    _Bottoma = &_First[i];
    if ( !_Pred(a1: _Bottoma, a2: _Val) )
      break;
    _First[v6] = *_Bottoma;
    v6 = i;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x100066A0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct AsyncInfo_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AsyncInfo_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[3 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[3 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[3 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100068E0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct studiodata_t __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006990
// Name: public: void __near * CUtlBuffer::Detach(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CUtlBuffer::Detach(CUtlBuffer *this)
{
  unsigned __int8 *m_pMemory; // esi

  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_pMemory = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  else
  {
    m_pMemory = nullptr;
  }
  this->m_Get = 0;
  this->m_Put = 0;
  this->m_Error = 0;
  this->m_nOffset = 0;
  this->m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this, nPut: 0);
  return m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100069C0
// Name: public: void CMDLCacheData::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCacheData::Purge(CMDLCacheData *this)
{
  if ( this->m_pData != nullptr )
  {
    CMDLCacheData::Deallocate(this, pData: (TSLNodeBase_t *)this->m_pData);
    this->m_pData = nullptr;
    this->m_nDataSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100069E0
// Name: private: void CMDLCache::DestroyVCollide(struct studiodata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::DestroyVCollide(CMDLCache *this, studiodata_t *pStudioData)
{
  unsigned __int16 m_nFlags; // ax
  bool v3; // zf
  CStudioVCollide *m_pVCollide; // edi

  m_nFlags = pStudioData->m_nFlags;
  if ( (m_nFlags & 2) != 0 )
  {
    v3 = pStudioData->m_pVCollide == nullptr;
    pStudioData->m_nFlags = m_nFlags & 0xFFFD;
    if ( !v3 )
    {
      if ( this->m_pCacheNotify != nullptr )
        this->m_pCacheNotify->OnDataUnloaded(
          this: this->m_pCacheNotify,
          a2: MDLCACHE_VCOLLIDE,
          a3: pStudioData->m_Handle);
      m_pVCollide = pStudioData->m_pVCollide;
      if ( _InterlockedDecrement(&m_pVCollide->m_iRefs) == 0 && m_pVCollide->OnFinalRelease(this: m_pVCollide) )
        ((void (__thiscall *)(CStudioVCollide *, int))m_pVCollide->dtr_CRefCountServiceBase<1,CRefMT>)(
          a1: m_pVCollide,
          a2: 1);
      pStudioData->m_pVCollide = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006A90
// Name: public: void CMDLCache::UncacheData(struct memhandle_t__ __near *,enum MDLCacheDataType_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::UncacheData(CMDLCache *this, TSLNodeBase_t *c, MDLCacheDataType_t type, bool bLockedOk)
{
  TSLNodeBase_t *v4; // edi
  IDataCacheSection *v6; // esi

  v4 = c;
  if ( c != nullptr )
  {
    v6 = this->GetCacheSection(this, a2: type);
    if ( v6->IsPresent(this: v6, a2: (memhandle_t__ *)v4)
      && (bLockedOk || v6->GetLockCount(this: v6, a2: (memhandle_t__ *)v4) <= 0) )
    {
      v6->BreakLock(this: v6, a2: (memhandle_t__ *)v4);
      v6->Remove(this: v6, a2: (memhandle_t__ *)v4, a3: (const void **)&c, a4: nullptr, a5: false);
      CMDLCache::FreeData(this, type, pData: c);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006B10
// Name: public: virtual bool CMDLCache::ReleaseAnimBlockAllocator(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::ReleaseAnimBlockAllocator(CMDLCache *this)
{
  if ( g_AnimBlockAllocator.m_pBase != nullptr )
  {
    if ( g_AnimBlockAllocator.m_freeList.m_Head.value.Depth != 137 )
    {
      DevWarning(a1: "Failure to release anim block allocator, unexpected remaining allocations\n");
      return 0;
    }
    free(pMem: g_AnimBlockAllocator.m_pBase);
  }
  g_AnimBlockAllocator.m_pLimit = nullptr;
  g_AnimBlockAllocator.m_pBase = nullptr;
  if ( ((unsigned __int8)&g_AnimBlockAllocator & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_AnimBlockAllocator.m_freeList.m_Head.value64 = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006B80
// Name: clear_anim_cache
// Source: json
//------------------------------------------------------------------------------
void __cdecl clear_anim_cache()
{
  g_MDLCache.m_pAnimBlocksCacheSection->Purge(this: g_MDLCache.m_pAnimBlocksCacheSection, a2: 0x20000000u);
  if ( g_AnimBlockAllocator.m_pBase != nullptr && g_AnimBlockAllocator.m_freeList.m_Head.value.Depth != 137 )
  {
    _Msg(
      a1: "Cannot clear animblock cache - %d blocks still in use!\n",
      137 - g_AnimBlockAllocator.m_freeList.m_Head.value.Depth);
  }
  else
  {
    _Msg(a1: "Animblock cache successfully cleared\n");
    if ( g_AnimBlockAllocator.m_pBase != nullptr )
      free(pMem: g_AnimBlockAllocator.m_pBase);
    g_AnimBlockAllocator.m_pLimit = nullptr;
    g_AnimBlockAllocator.m_pBase = nullptr;
    if ( ((unsigned __int8)&g_AnimBlockAllocator & 7) != 0 )
    {
      _Error(a1: "CTSListBase: Misaligned list\n");
      __debugbreak();
    }
    g_AnimBlockAllocator.m_freeList.m_Head.value64 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006C20
// Name: public: struct CTSQueue<struct studiodata_t __near *,0,1>::Node_t __near * CTSQueue<struct studiodata_t __near *,0,1>::Push(struct CTSQueue<struct studiodata_t __near *,0,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<studiodata_t *,0,1>::Node_t *__thiscall CTSQueue<studiodata_t *,0,1>::Push(
        CTSQueue<studiodata_t *,0,1> *this,
        CTSQueue<studiodata_t *,0,1>::Node_t *pNode)
{
  CTSQueue<studiodata_t *,0,1>::Node_t *v3; // edi
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<studiodata_t *,0,1>::Node_t *)this;
  v3 = this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<studiodata_t *,0,1> *)_InterlockedCompareExchange(
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
// Address: 0x10006CD0
// Name: public: struct CTSQueue<struct studiodata_t __near *,0,1>::Node_t __near * CTSQueue<struct studiodata_t __near *,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<studiodata_t *,0,1>::Node_t *__thiscall CTSQueue<studiodata_t *,0,1>::Pop(CTSQueue<studiodata_t *,0,1> *this)
{
  CTSQueue<studiodata_t *,0,1> *v1; // esi
  CTSQueue<studiodata_t *,0,1> *pNext; // eax
  studiodata_t *sequence; // edi
  CTSQueue<studiodata_t *,0,1>::Node_t *pNode; // [esp-Ch] [ebp-2Ch]
  CTSQueue<studiodata_t *,0,1>::NodeLink_t *head_4; // [esp+4h] [ebp-1Ch]
  int *pHead; // [esp+Ch] [ebp-14h]
  CTSQueue<studiodata_t *,0,1>::NodeLink_t *pTailNode; // [esp+10h] [ebp-10h]

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
          pNext = (CTSQueue<studiodata_t *,0,1> *)v1->m_Head.value.pNode->pNext;
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
    sequence = (studiodata_t *)pNext->m_Head.value.sequence;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNext, a3: *pHead + 1, a4: pNode, a5: *pHead) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem = sequence;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x10006DB0
// Name: protected: bool CUtlHash<struct CModelSwapper::ModelSubstitution_t,bool (*)(struct CModelSwapper::ModelSubstitution_t const __near &,struct CModelSwapper::ModelSubstitution_t const __near &),unsigned int (*)(struct CModelSwapper::ModelSubstitution_t const __near &)>::DoFind(struct CModelSwapper::ModelSubstitution_t const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>::DoFind(
        CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl*)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl*)(CModelSwapper::ModelSubstitution_t const &)> *this,
        const CModelSwapper::ModelSubstitution_t *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  int m_Size; // ecx
  CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int> > *v9; // eax
  int v10; // edi
  int v11; // ebx
  const CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int> > *bucket; // [esp+8h] [ebp-4h]
  int keyDataCount; // [esp+18h] [ebp+Ch]

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = v6;
  m_Size = this->m_Buckets.m_Memory.m_pMemory[v7].m_Size;
  v9 = &this->m_Buckets.m_Memory.m_pMemory[v7];
  v10 = 0;
  bucket = v9;
  keyDataCount = m_Size;
  if ( m_Size > 0 )
  {
    v11 = 0;
    while ( !this->m_CompareFunc(a1: &v9->m_Memory.m_pMemory[v11], a2: src) )
    {
      ++v10;
      ++v11;
      if ( v10 >= keyDataCount )
        break;
      v9 = (CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int> > *)bucket;
    }
    m_Size = keyDataCount;
  }
  if ( v10 == m_Size )
    return 0;
  *pIndex = v10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007000
// Name: void std::_Make_heap<struct mstudiovertanim_t __near *,int,struct mstudiovertanim_t,bool (*)(struct mstudiovertanim_t const __near &,struct mstudiovertanim_t const __near &)>(struct mstudiovertanim_t __near *,struct mstudiovertanim_t __near *,bool (*)(struct mstudiovertanim_t const __near &,struct mstudiovertanim_t const __near &),int __near *,struct mstudiovertanim_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<mstudiovertanim_t *,int,mstudiovertanim_t,bool (__cdecl *)(mstudiovertanim_t const &,mstudiovertanim_t const &)>(
        mstudiovertanim_t *_First,
        mstudiovertanim_t *_Last,
        bool (__cdecl *_Pred)(const mstudiovertanim_t *, const mstudiovertanim_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  mstudiovertanim_t *i; // edx
  __int64 v8; // xmm0_8
  mstudiovertanim_t *v9; // edx
  int v10; // eax
  int v11; // esi
  __int64 v12; // xmm0_8
  int v13; // ebx
  bool v14; // zf
  int v15; // ecx
  __int64 v16; // xmm0_8
  int v17; // ebx
  mstudiovertanim_t _Val; // [esp+4h] [ebp-18h] BYREF
  int v19; // [esp+14h] [ebp-8h]
  mstudiovertanim_t *v20; // [esp+18h] [ebp-4h]
  int _Hole; // [esp+24h] [ebp+8h]
  int _Bottom; // [esp+28h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v20 )
    {
      v8 = *(_QWORD *)&i[-1].index;
      v9 = i - 1;
      v10 = v5 - 1;
      v11 = v6 - 2;
      *(_QWORD *)&_Val.index = v8;
      v12 = *(_QWORD *)&v9->flDelta[2].m_storage.rawWord;
      _Hole = v10;
      v20 = v9;
      v19 = v11;
      *(_QWORD *)&_Val.flDelta[2].m_storage.rawWord = v12;
      v13 = v10;
      v14 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v11], a2: &_First[v11 - 1]) )
            --v11;
          v15 = v13;
          v13 = v11;
          *(_QWORD *)&_First[v15].index = *(_QWORD *)&_First[v11].index;
          v16 = *(_QWORD *)&_First[v11].flDelta[2].m_storage.rawWord;
          v11 = 2 * v11 + 2;
          *(_QWORD *)&_First[v15].flDelta[2].m_storage.rawWord = v16;
        }
        while ( v11 < _Bottom );
        v4 = _Bottom;
        v10 = _Hole;
        v14 = v11 == _Bottom;
      }
      if ( v14 )
      {
        v17 = v13;
        *(_QWORD *)&_First[v17].index = *(_QWORD *)&_First[v4 - 1].index;
        *(_QWORD *)&_First[v17].flDelta[2].m_storage.rawWord = *(_QWORD *)&_First[v4 - 1].flDelta[2].m_storage.rawWord;
        v13 = v4 - 1;
      }
      std::_Push_heap<mstudiovertanim_t *,int,mstudiovertanim_t,bool (__cdecl *)(mstudiovertanim_t const &,mstudiovertanim_t const &)>(
        _First,
        _Hole: v13,
        _Top: v10,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007110
// Name: void std::_Make_heap<struct mstudiovertanim_wrinkle_t __near *,int,struct mstudiovertanim_wrinkle_t,bool (*)(struct mstudiovertanim_wrinkle_t const __near &,struct mstudiovertanim_wrinkle_t const __near &)>(struct mstudiovertanim_wrinkle_t __near *,struct mstudiovertanim_wrinkle_t __near *,bool (*)(struct mstudiovertanim_wrinkle_t const __near &,struct mstudiovertanim_wrinkle_t const __near &),int __near *,struct mstudiovertanim_wrinkle_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<mstudiovertanim_wrinkle_t *,int,mstudiovertanim_wrinkle_t,bool (__cdecl *)(mstudiovertanim_wrinkle_t const &,mstudiovertanim_wrinkle_t const &)>(
        mstudiovertanim_wrinkle_t *_First,
        mstudiovertanim_wrinkle_t *_Last,
        bool (__cdecl *_Pred)(const mstudiovertanim_wrinkle_t *, const mstudiovertanim_wrinkle_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  mstudiovertanim_wrinkle_t *v7; // edx
  __int64 v8; // xmm0_8
  mstudiovertanim_wrinkle_t *v9; // edx
  int v10; // eax
  int v11; // esi
  __int64 v12; // xmm0_8
  int v13; // edi
  bool v14; // zf
  mstudiovertanim_wrinkle_t *v15; // eax
  mstudiovertanim_wrinkle_t *v16; // ecx
  mstudiovertanim_wrinkle_t *v17; // edx
  mstudiovertanim_wrinkle_t *v18; // esi
  mstudiovertanim_wrinkle_t _Val; // [esp+4h] [ebp-1Ch] BYREF
  int v20; // [esp+18h] [ebp-8h]
  mstudiovertanim_wrinkle_t *v21; // [esp+1Ch] [ebp-4h]
  int _Hole; // [esp+28h] [ebp+8h]
  int _Bottom; // [esp+2Ch] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    v7 = &_First[v5];
    while ( 1 )
    {
      v8 = *(_QWORD *)&v7[-1].index;
      v9 = v7 - 1;
      v10 = v5 - 1;
      v11 = v6 - 2;
      *(_QWORD *)&_Val.index = v8;
      v12 = *(_QWORD *)&v9->flDelta[2].m_storage.rawWord;
      v21 = v9;
      LOWORD(v9) = v9->wrinkledelta;
      _Hole = v10;
      v20 = v11;
      *(_QWORD *)&_Val.flDelta[2].m_storage.rawWord = v12;
      _Val.wrinkledelta = (__int16)v9;
      v13 = v10;
      v14 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v11], a2: &_First[v11 - 1]) )
            --v11;
          v15 = &_First[v11];
          v16 = &_First[v13];
          *(_QWORD *)&v16->index = *(_QWORD *)&v15->index;
          *(_QWORD *)&v16->flDelta[2].m_storage.rawWord = *(_QWORD *)&v15->flDelta[2].m_storage.rawWord;
          v13 = v11;
          v11 = 2 * v11 + 2;
          v16->wrinkledelta = v15->wrinkledelta;
        }
        while ( v11 < _Bottom );
        v4 = _Bottom;
        v10 = _Hole;
        v14 = v11 == _Bottom;
      }
      if ( v14 )
      {
        v17 = &_First[v4 - 1];
        v18 = &_First[v13];
        *(_QWORD *)&v18->index = *(_QWORD *)&v17->index;
        *(_QWORD *)&v18->flDelta[2].m_storage.rawWord = *(_QWORD *)&v17->flDelta[2].m_storage.rawWord;
        v18->wrinkledelta = v17->wrinkledelta;
        v13 = v4 - 1;
      }
      std::_Push_heap<mstudiovertanim_wrinkle_t *,int,mstudiovertanim_wrinkle_t,bool (__cdecl *)(mstudiovertanim_wrinkle_t const &,mstudiovertanim_wrinkle_t const &)>(
        _First,
        _Hole: v13,
        _Top: v10,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v7 = v21;
      v6 = v20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100072B0
// Name: protected: int CUtlLinkedList<struct AsyncInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AsyncInfo_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AllocInternal(
        CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[2].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[2].m_nBlockSize = 0;
      result[2].m_pNext = nullptr;
    }
    else
    {
      result[2].m_nBlockSize = (int)result;
      result[2].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Next(
                                                                                     (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *)this,
                                                                                     result: (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *)&v13,
                                                                                     it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t **)&v14;
  }
  v8 = *v7;
  v9 = (int)v7[1];
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *)&v15;
    }
    v8 = v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[3 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[3 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008100
// Name: public: void CModelSwapper::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelSwapper::Cleanup(CModelSwapper *this)
{
  int i; // edi
  int m_Size; // edx
  int v4; // ecx

  for ( i = 0; i < this->m_Strings.m_Size; ++i )
    free(pMem: (void *)this->m_Strings.m_Memory.m_pMemory[i]);
  this->m_Strings.m_Size = 0;
  m_Size = this->m_ModelLookup.m_Buckets.m_Size;
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      this->m_ModelLookup.m_Buckets.m_Memory.m_pMemory[v4++].m_Size = 0;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008160
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008190
// Name: public: CMDLCacheData::CMDLCacheData(enum MDLCacheDataType_t,enum CMDLCacheData::AllocType_t,class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
CMDLCacheData *__thiscall CMDLCacheData::CMDLCacheData(
        CMDLCacheData *this,
        MDLCacheDataType_t dataType,
        CMDLCacheData::AllocType_t allocType,
        CUtlBuffer *pDataBuffer)
{
  this->m_AllocType = allocType;
  this->m_pData = nullptr;
  this->m_nDataSize = 0;
  this->m_DataType = dataType;
  if ( pDataBuffer != nullptr && pDataBuffer->m_nMaxPut != 0 )
  {
    this->m_pData = pDataBuffer->m_Memory.m_pMemory;
    this->m_nDataSize = pDataBuffer->m_nMaxPut;
    if ( pDataBuffer->m_Memory.m_nGrowSize < 0 )
    {
      CUtlBuffer::SetExternalBuffer(this: pDataBuffer, pMemory: nullptr, nSize: 0, nInitialPut: 0, nFlags: 0);
      return this;
    }
    CUtlBuffer::Detach(this: pDataBuffer);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100081F0
// Name: public: void CTSQueue<struct studiodata_t __near *,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<studiodata_t *,0,1>::Purge(CTSQueue<studiodata_t *,0,1> *this)
{
  CTSQueue<studiodata_t *,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  for ( i = CTSQueue<studiodata_t *,0,1>::Pop(this); i != nullptr; i = CTSQueue<studiodata_t *,0,1>::Pop(this) )
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
// Address: 0x100083F0
// Name: public: void CUtlLinkedList<struct AsyncInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AsyncInfo_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::RemoveAll(
        CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *v1; // esi
  void *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *v3; // ebx
  int v4; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>::Next(
                this: v1,
                (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *)&result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::Iterator_t *)&it) )
    {
      v3 = *(CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t **)i;
      v4 = *((_DWORD *)i + 1);
      it.m_nIndex = v4;
      it.m_pBlockHeader = v3;
      if ( v3 != nullptr )
      {
        if ( v4 >= 0 && v4 < v3->m_nBlockSize )
        {
          if ( &v3[3 * v4] == (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&v3[3 * v4 + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || v3[3 * v4 + 3].m_pNext == &v3[3 * v4 + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)v3[3 * v4 + 3].m_nBlockSize != &v3[3 * v4 + 1] )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            v3[3 * v4 + 3].m_pNext = &v3[3 * v4 + 1];
            v3[3 * v4 + 3].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&v3[3 * v4 + 1];
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> > *)v5;
          }
        }
      }
      else if ( v4 == -1 )
      {
        break;
      }
      if ( v3 == (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *)v4 == v1[3].m_pBlocks )
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
// Address: 0x1000A630
// Name: public: virtualgroup_t::virtualgroup_t(void)
// Source: json
//------------------------------------------------------------------------------
virtualgroup_t *__thiscall virtualgroup_t::virtualgroup_t(virtualgroup_t *this)
{
  this->boneMap.m_Memory.m_pMemory = nullptr;
  this->boneMap.m_Memory.m_nAllocationCount = 0;
  this->boneMap.m_Memory.m_nGrowSize = 0;
  this->boneMap.m_Size = 0;
  this->boneMap.m_pElements = nullptr;
  this->masterBone.m_Memory.m_pMemory = nullptr;
  this->masterBone.m_Memory.m_nAllocationCount = 0;
  this->masterBone.m_Memory.m_nGrowSize = 0;
  this->masterBone.m_Size = 0;
  this->masterBone.m_pElements = nullptr;
  this->masterSeq.m_Memory.m_pMemory = nullptr;
  this->masterSeq.m_Memory.m_nAllocationCount = 0;
  this->masterSeq.m_Memory.m_nGrowSize = 0;
  this->masterSeq.m_Size = 0;
  this->masterSeq.m_pElements = nullptr;
  this->masterAnim.m_Memory.m_pMemory = nullptr;
  this->masterAnim.m_Memory.m_nAllocationCount = 0;
  this->masterAnim.m_Memory.m_nGrowSize = 0;
  this->masterAnim.m_Size = 0;
  this->masterAnim.m_pElements = nullptr;
  this->masterAttachment.m_Memory.m_pMemory = nullptr;
  this->masterAttachment.m_Memory.m_nAllocationCount = 0;
  this->masterAttachment.m_Memory.m_nGrowSize = 0;
  this->masterAttachment.m_Size = 0;
  this->masterAttachment.m_pElements = nullptr;
  this->masterPose.m_Memory.m_pMemory = nullptr;
  this->masterPose.m_Memory.m_nAllocationCount = 0;
  this->masterPose.m_Memory.m_nGrowSize = 0;
  this->masterPose.m_Size = 0;
  this->masterPose.m_pElements = nullptr;
  this->masterNode.m_Memory.m_pMemory = nullptr;
  this->masterNode.m_Memory.m_nAllocationCount = 0;
  this->masterNode.m_Memory.m_nGrowSize = 0;
  this->masterNode.m_Size = 0;
  this->masterNode.m_pElements = nullptr;
  this->cache = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A6B0
// Name: public: char const __near * CModelSwapper::TranslateModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CModelSwapper::TranslateModelName(CModelSwapper *this, const char *pOriginalModelName)
{
  unsigned int v3; // ecx
  unsigned int v4; // esi
  CModelSwapper::ModelSubstitution_t *m_pMemory; // eax
  unsigned int v6; // edi
  CModelSwapper::ModelSubstitution_t searchData; // [esp+Ch] [ebp-14h] BYREF
  unsigned int pBucket; // [esp+18h] [ebp-8h] BYREF
  int pIndex; // [esp+1Ch] [ebp-4h] BYREF

  searchData.pOriginalModelName = pOriginalModelName;
  if ( (`CModelSwapper::TranslateModelName'::`2'::`local static guard' & 1) == 0 )
  {
    `CModelSwapper::TranslateModelName'::`2'::`local static guard' |= 1u;
    ConVarRef::ConVarRef(this: &`CModelSwapper::TranslateModelName'::`2'::gpu_level, pName: "gpu_level");
  }
  pIndex = 0;
  if ( CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>::DoFind(
         this: &this->m_ModelLookup,
         src: &searchData,
         &pBucket,
         &pIndex) == 0 )
    return pOriginalModelName;
  v3 = pIndex | (pBucket << 16);
  if ( v3 == -1 )
    return pOriginalModelName;
  v4 = HIWORD(v3);
  m_pMemory = this->m_ModelLookup.m_Buckets.m_Memory.m_pMemory[v4].m_Memory.m_pMemory;
  v6 = (unsigned __int16)pIndex;
  if ( `CModelSwapper::TranslateModelName'::`2'::gpu_level.m_pConVarState->m_Value.m_nValue > m_pMemory[v6].nMaxGPULevel )
    return pOriginalModelName;
  DevMsg(
    a1: "Substituting model %s for %s because gpu_level is %d\n",
    m_pMemory[v6].pSubstituteModelName,
    pOriginalModelName,
    `CModelSwapper::TranslateModelName'::`2'::gpu_level.m_pConVarState->m_Value.m_nValue);
  return this->m_ModelLookup.m_Buckets.m_Memory.m_pMemory[v4].m_Memory.m_pMemory[v6].pSubstituteModelName;
}

//------------------------------------------------------------------------------
// Address: 0x1000A780
// Name: public: virtual char const __near * CMDLCache::GetModelName(unsigned short)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLCache::GetModelName(CMDLCache *this, unsigned __int16 handle)
{
  if ( handle == 0xFFFF )
    return "models/error.mdl";
  else
    return this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x1000A7B0
// Name: private: char const __near * CMDLCache::GetActualModelName(unsigned short)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLCache::GetActualModelName(CMDLCache *this, unsigned __int16 handle)
{
  UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx

  if ( handle == 0xFFFF )
    return "models/error.mdl";
  m_pMemory = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( (m_pMemory[handle].m_Data.elem->m_nFlags & 4) != 0 )
    return "models/error.mdl";
  else
    return m_pMemory[handle].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x1000A7F0
// Name: public: virtual int CMDLCache::AddRef(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLCache::AddRef(CMDLCache *this, unsigned __int16 handle)
{
  studiodata_t *elem; // eax

  elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
  return ++elem->m_nRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000A810
// Name: public: virtual int CMDLCache::GetRef(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLCache::GetRef(CMDLCache *this, unsigned __int16 handle)
{
  studiodata_t **p_elem; // eax

  if ( (*((_BYTE *)this + 160) & 4) != 0
    && *(p_elem = &this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem) != nullptr )
  {
    return (*p_elem)->m_nRefCount;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A840
// Name: private: virtual void CMDLCache::ReloadVCollide(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::ReloadVCollide(CMDLCache *this, int handle)
{
  studiodata_t *elem; // edi
  virtualmodel_t *v4; // eax
  virtualmodel_t *v5; // edi
  int v6; // ebx
  int v7; // [esp+Ch] [ebp-4h]

  elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
  if ( _executeCount < 1 )
  {
    ++_executeCount;
    _Warning(a1: "ReloadVCollide invoked and will leak memory\n");
  }
  elem->m_nFlags &= 0xFF7Du;
  elem->m_pVCollide = nullptr;
  v4 = this->GetVirtualModel(this, a2: handle);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v6 = 1;
    if ( v4->m_group.m_Size > 1 )
    {
      v7 = 1;
      do
      {
        this->ReloadVCollide(this, a2: (unsigned __int16)v5->m_group.m_Memory.m_pMemory[v7++].cache);
        ++v6;
      }
      while ( v6 < v5->m_group.m_Size );
    }
  }
  this->GetVCollideEx(this, a2: handle, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000A8F0
// Name: public: virtual bool CMDLCache::GetVCollideSize(unsigned short,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::GetVCollideSize(CMDLCache *this, unsigned __int16 handle, int *pVCollideSize)
{
  CStudioVCollide *m_pVCollide; // esi
  int v5; // edi

  *pVCollideSize = 0;
  m_pVCollide = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem->m_pVCollide;
  if ( m_pVCollide == nullptr )
    return 0;
  v5 = 0;
  if ( (*(_WORD *)&m_pVCollide->m_vcollide & 0x7FFF) != 0 )
  {
    do
      *pVCollideSize += g_pPhysicsCollision->CollideSize(
                          this: g_pPhysicsCollision,
                          a2: m_pVCollide->m_vcollide.solids[v5++]);
    while ( v5 < (*(_WORD *)&m_pVCollide->m_vcollide & 0x7FFF) );
  }
  *pVCollideSize += m_pVCollide->m_vcollide.descSize;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A970
// Name: public: virtual int CMDLCache::GetAutoplayList(unsigned short,unsigned short __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLCache::GetAutoplayList(CMDLCache *this, int handle, unsigned __int16 **pAutoplayList)
{
  virtualmodel_t *v5; // eax
  studiodata_t *elem; // eax

  if ( pAutoplayList != nullptr )
    *pAutoplayList = nullptr;
  if ( (_WORD)handle == 0xFFFF )
    return 0;
  v5 = this->GetVirtualModel(this, a2: handle);
  if ( v5 != nullptr )
  {
    if ( pAutoplayList != nullptr && v5->m_autoplaySequences.m_Size != 0 )
      *pAutoplayList = v5->m_autoplaySequences.m_Memory.m_pMemory;
    return v5->m_autoplaySequences.m_Size;
  }
  else
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
    if ( pAutoplayList != nullptr )
      *pAutoplayList = elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory;
    return elem->m_vecAutoplaySequenceList.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A9F0
// Name: private: bool CMDLCache::ReadFileNative(char __near *,char const __near *,class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLCache::ReadFileNative(
        CMDLCache *this,
        char *pFileName,
        const char *pPath,
        CUtlBuffer *buf,
        int nMaxBytes)
{
  const char *v5; // eax

  v5 = CModelSwapper::TranslateModelName(this: &this->m_ModelSwapper, pOriginalModelName: pFileName);
  return g_pFullFileSystem->ReadFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: v5,
           a3: pPath,
           a4: buf,
           a5: nMaxBytes,
           a6: 0,
           a7: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000AA30
// Name: public: virtual struct studiohdr_t __near * CMDLCache::LockStudioHdr(unsigned short)
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CMDLCache::LockStudioHdr(CMDLCache *this, studiohdr_t *handle)
{
  int v4; // edi
  studiodata_t *elem; // ebx
  studiohdr_t *m_pForceLockedStudioHdr; // ebx
  IDataCacheSection *v7; // eax
  studiohdr_t *pStdioHdr; // [esp+Ch] [ebp+8h]

  if ( (_WORD)handle == 0xFFFF )
    return nullptr;
  v4 = (unsigned __int16)handle;
  elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
  if ( elem->m_pForceLockedStudioHdr != nullptr )
  {
    _InterlockedExchangeAdd(&elem->m_iStudioHdrVirtualLock.m_value, 1u);
    return elem->m_pForceLockedStudioHdr;
  }
  else
  {
    this->BeginLock(this);
    pStdioHdr = this->GetStudioHdr(this, a2: handle);
    if ( pStdioHdr != nullptr )
    {
      if ( elem->m_pForceLockedStudioHdr != nullptr )
      {
        _InterlockedExchangeAdd(&elem->m_iStudioHdrVirtualLock.m_value, 1u);
        m_pForceLockedStudioHdr = elem->m_pForceLockedStudioHdr;
        this->EndLock(this);
        return m_pForceLockedStudioHdr;
      }
      else
      {
        v7 = this->GetCacheSection(this, a2: 0);
        v7->Lock(this: v7, a2: this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem->m_MDLCache);
        this->EndLock(this);
        return pStdioHdr;
      }
    }
    else
    {
      this->EndLock(this);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AB00
// Name: public: virtual void CMDLCache::UnlockStudioHdr(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::UnlockStudioHdr(CMDLCache *this, unsigned __int16 handle)
{
  studiodata_t *elem; // eax
  IDataCacheSection *v4; // eax

  if ( handle != 0xFFFF )
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
    if ( elem->m_pForceLockedStudioHdr != nullptr )
    {
      _InterlockedExchangeAdd(&elem->m_iStudioHdrVirtualLock.m_value, 0xFFFFFFFF);
    }
    else if ( elem->m_MDLCache != nullptr )
    {
      v4 = this->GetCacheSection(this, a2: 0);
      v4->Unlock(this: v4, a2: this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem->m_MDLCache);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AB60
// Name: public: virtual void CMDLCache::SetUserData(unsigned short,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::SetUserData(CMDLCache *this, unsigned __int16 handle, void *pData)
{
  if ( handle != 0xFFFF )
    this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem->m_pUserData = pData;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB90
// Name: public: virtual void __near * CMDLCache::GetUserData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMDLCache::GetUserData(CMDLCache *this, unsigned __int16 handle)
{
  if ( handle == 0xFFFF )
    return nullptr;
  else
    return this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem->m_pUserData;
}

//------------------------------------------------------------------------------
// Address: 0x1000ABC0
// Name: public: virtual bool CMDLCache::IsErrorModel(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLCache::IsErrorModel(CMDLCache *this, unsigned __int16 handle)
{
  return handle != 0xFFFF
      && (this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem->m_nFlags & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000AC00
// Name: private: virtual bool CMDLCache::HandleCacheNotification(struct DataCacheNotification_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::HandleCacheNotification(CMDLCache *this, const DataCacheNotification_t *notification)
{
  const char *v3; // eax
  unsigned int clientId; // eax

  if ( (unsigned int)(notification->type - 1) > 2 )
    return 0;
  if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = (const char *)(*(int (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 2) + 108))(
                         a1: (char *)this - 8,
                         a2: HIWORD(notification->clientId));
    _Msg(a1: "MDLCache: Data cache discard %s %s\n", g_ppszTypes[(unsigned __int16)notification->clientId], v3);
  }
  clientId = notification->clientId;
  if ( notification->pItemData == (const void *)clientId || (unsigned __int16)clientId != 1 )
  {
    CMDLCache::FreeData(
      this: (CMDLCache *)((char *)this - 8),
      type: (MDLCacheDataType_t)(unsigned __int16)notification->clientId,
      pData: (TSLNodeBase_t *)notification->pItemData);
    return 1;
  }
  else
  {
    CMDLCache::UnloadHardwareData(
      this: (CMDLCache *)((char *)this - 8),
      pStudioData: *(studiodata_t **)(this->m_nAnimBlockCacheFrameLocks + 16 * HIWORD(clientId) + 12));
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ACB0
// Name: public: virtual bool CMDLCache::VerifyHeaders(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::VerifyHeaders(CMDLCache *this, studiohdr_t *pStudioHdr)
{
  const char *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  char pFileName[260]; // [esp+8h] [ebp-164h] BYREF
  CUtlBuffer vtxHeader; // [esp+10Ch] [ebp-60h] BYREF
  CUtlBuffer vvdHeader; // [esp+13Ch] [ebp-30h] BYREF

  if ( pStudioHdr->numbodyparts == 0 )
    return 1;
  MakeFilename(szFileName: pFileName, pStudioHdr, pszExtension: ".vvd");
  if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "MDLCache: Load VVD (verify) %s\n", pFileName);
  CUtlBuffer::CUtlBuffer(this: &vvdHeader, growSize: 0, initSize: 64, nFlags: 0);
  v4 = CModelSwapper::TranslateModelName(this: (CModelSwapper *)((char *)this + 160), pOriginalModelName: pFileName);
  if ( !g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: v4,
          a3: "GAME",
          a4: &vvdHeader,
          a5: 64,
          a6: 0,
          a7: nullptr) )
  {
    if ( vvdHeader.m_Memory.m_nGrowSize >= 0 && vvdHeader.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vvdHeader.m_Memory.m_pMemory);
      return 0;
    }
    return 0;
  }
  v5 = &vvdHeader.m_Memory.m_pMemory[vvdHeader.m_Get - vvdHeader.m_nOffset];
  if ( *(_DWORD *)v5 != 1448297545 || *((_DWORD *)v5 + 1) != 4 || *((_DWORD *)v5 + 2) != pStudioHdr->checksum )
  {
    if ( vvdHeader.m_Memory.m_nGrowSize >= 0 && vvdHeader.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vvdHeader.m_Memory.m_pMemory);
    return 0;
  }
  MakeFilename(szFileName: pFileName, pStudioHdr, pszExtension: ".dx90.vtx");
  if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "MDLCache: Load VTX (verify) %s\n", pFileName);
  CUtlBuffer::CUtlBuffer(this: &vtxHeader, growSize: 0, initSize: 36, nFlags: 0);
  if ( CMDLCache::ReadFileNative(
         this: (CMDLCache *)((char *)this - 4),
         pFileName,
         pPath: "GAME",
         buf: &vtxHeader,
         nMaxBytes: 36)
    && *(_DWORD *)(v6 = &vtxHeader.m_Memory.m_pMemory[vtxHeader.m_Get - vtxHeader.m_nOffset]) == 7
    && *((_DWORD *)v6 + 4) == pStudioHdr->checksum )
  {
    CUtlBuffer::~CUtlBuffer(this: &vtxHeader);
    CUtlBuffer::~CUtlBuffer(this: &vvdHeader);
    return 1;
  }
  else
  {
    CUtlBuffer::~CUtlBuffer(this: &vtxHeader);
    CUtlBuffer::~CUtlBuffer(this: &vvdHeader);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AE80
// Name: private: enum FSAsyncStatus_t CMDLCache::LoadData(char const __near *,char const __near *,void __near *,int,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CMDLCache::LoadData(
        CMDLCache *this,
        const char *pszFilename,
        const char *pszPathID,
        void *pDest,
        int nBytes,
        int nOffset,
        bool bAsync,
        FSAsyncControl_t__ **pControl)
{
  const char *v8; // esi
  FileAsyncRequest_t asyncRequest; // [esp+4h] [ebp-2Ch] BYREF

  if ( *pControl != nullptr )
    return FSASYNC_ERR_FAILURE;
  v8 = CModelSwapper::TranslateModelName(this: &this->m_ModelSwapper, pOriginalModelName: pszFilename);
  memset(dst: (unsigned __int8 *)&asyncRequest, value: 0, count: sizeof(asyncRequest));
  asyncRequest.pszPathID = pszPathID;
  asyncRequest.pszFilename = v8;
  asyncRequest.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
  asyncRequest.pData = pDest;
  asyncRequest.nBytes = nBytes;
  asyncRequest.nOffset = nOffset;
  if ( pDest == nullptr )
    asyncRequest.flags = 1;
  if ( !bAsync )
    asyncRequest.flags |= 4u;
  return g_pFullFileSystem->AsyncReadMultiple(this: g_pFullFileSystem, a2: &asyncRequest, a3: 1, a4: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000AF20
// Name: private: struct vertexFileHeader_t __near * CMDLCache::BuildAndCacheVertexData(struct studiohdr_t __near *,class CMDLCacheData __near &)
// Source: json
//------------------------------------------------------------------------------
vertexFileHeader_t *__thiscall CMDLCache::BuildAndCacheVertexData(
        CMDLCache *this,
        studiohdr_t *pStudioHdr,
        CMDLCacheData *cacheData)
{
  ConVar *m_pParent; // edi
  int studiohdr2index; // eax
  int v6; // ecx
  char *v7; // eax
  int v8; // ecx
  char *name; // eax
  _DWORD *m_pData; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  char *v14; // eax
  int v15; // ecx
  char *v16; // eax
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  char *v21; // eax
  int v22; // ecx
  char *v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // ecx
  char *v27; // eax
  int v28; // ecx
  char *v29; // eax
  int v30; // edx
  int v31; // edx
  int v32; // eax
  int v33; // ebx
  const char *v34; // eax
  IDataCacheSection *v35; // eax
  char *v36; // eax
  IDataCacheSection *v37; // eax
  vertexFileHeader_t *pRawVvdHdr; // [esp+Ch] [ebp-Ch]
  vertexFileHeader_t *pVvdHdr; // [esp+10h] [ebp-8h]
  int handle; // [esp+14h] [ebp-4h]
  int rootLOD; // [esp+24h] [ebp+Ch]

  m_pParent = mod_trace_load.m_pParent;
  handle = LOWORD(pStudioHdr->virtualModel);
  if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
  {
    studiohdr2index = pStudioHdr->studiohdr2index;
    if ( studiohdr2index != 0
      && (v6 = *(_DWORD *)&pStudioHdr->name[studiohdr2index + 8], v7 = (char *)pStudioHdr + studiohdr2index, v6 != 0)
      && &v7[v6] != nullptr )
    {
      v8 = *((_DWORD *)v7 + 5);
      if ( v8 != 0 )
        name = &v7[v8];
      else
        name = nullptr;
    }
    else
    {
      name = pStudioHdr->name;
    }
    _Msg(a1: "MDLCache: Load VVD for %s\n", name);
    m_pParent = mod_trace_load.m_pParent;
  }
  m_pData = cacheData->m_pData;
  v11 = *(_DWORD *)cacheData->m_pData;
  pRawVvdHdr = (vertexFileHeader_t *)cacheData->m_pData;
  if ( v11 != 1448297545 )
  {
    v12 = pStudioHdr->studiohdr2index;
    if ( v12 != 0
      && (v13 = *(_DWORD *)&pStudioHdr->name[v12 + 8], v14 = (char *)pStudioHdr + v12, v13 != 0)
      && &v14[v13] != nullptr )
    {
      v15 = *((_DWORD *)v14 + 5);
      if ( v15 != 0 )
        v16 = &v14[v15];
      else
        v16 = nullptr;
    }
    else
    {
      v16 = pStudioHdr->name;
    }
    _Warning(a1: "Error Vertex File for '%s' id %d should be %d\n", v16, v11, 1448297545);
    return nullptr;
  }
  v18 = m_pData[1];
  if ( v18 == 4 )
  {
    v24 = m_pData[2];
    if ( v24 == pStudioHdr->checksum )
    {
      v30 = m_pData[3];
      if ( v30 == 0 )
        return nullptr;
      v31 = v30 - 1;
      rootLOD = pStudioHdr->rootLOD;
      if ( rootLOD >= v31 )
        rootLOD = v31;
      v32 = m_pData[rootLOD + 4] + 1;
      v33 = 16 * v32 + m_pData[14] + 48 * v32;
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      {
        v34 = this->GetModelName(this, a2: handle);
        _Msg(a1: "MDLCache: Alloc VVD %s\n", v34);
      }
      pVvdHdr = (vertexFileHeader_t *)CMDLCache::AllocData(this, type: MDLCACHE_VERTEXES, size: v33);
      v35 = this->GetCacheSection(this, a2: 5);
      v35->BeginFrameLocking(this: v35);
      v36 = studiohdr_t::pszName(this: pStudioHdr);
      CMDLCache::CacheData(
        this,
        c: &this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem->m_VertexCache,
        pData: pVvdHdr,
        size: v33,
        name: v36,
        type: MDLCACHE_VERTEXES,
        id: (void *)(((unsigned __int16)handle << 16) | 5));
      Studio_LoadVertexes(pTempVvdHdr: pRawVvdHdr, pNewVvdHdr: pVvdHdr, rootLOD, bNeedsTangentS: true);
      v37 = this->GetCacheSection(this, a2: 5);
      v37->EndFrameLocking(this: v37);
      return pVvdHdr;
    }
    else
    {
      v25 = pStudioHdr->studiohdr2index;
      if ( v25 != 0
        && (v26 = *(_DWORD *)&pStudioHdr->name[v25 + 8], v27 = (char *)pStudioHdr + v25, v26 != 0)
        && &v27[v26] != nullptr )
      {
        v28 = *((_DWORD *)v27 + 5);
        if ( v28 != 0 )
          v29 = &v27[v28];
        else
          v29 = nullptr;
      }
      else
      {
        v29 = pStudioHdr->name;
      }
      _Warning(a1: "Error Vertex File for '%s' checksum %ld should be %ld\n", v29, v24, pStudioHdr->checksum);
      return nullptr;
    }
  }
  else
  {
    v19 = pStudioHdr->studiohdr2index;
    if ( v19 != 0
      && (v20 = *(_DWORD *)&pStudioHdr->name[v19 + 8], v21 = (char *)pStudioHdr + v19, v20 != 0)
      && &v21[v20] != nullptr )
    {
      v22 = *((_DWORD *)v21 + 5);
      if ( v22 != 0 )
        v23 = &v21[v22];
      else
        v23 = nullptr;
    }
    else
    {
      v23 = pStudioHdr->name;
    }
    _Warning(a1: "Error Vertex File for '%s' version %d should be %d\n", v23, v18, 4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B160
// Name: public: virtual struct vertexFileHeader_t __near * CMDLCache::GetVertexData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
vertexFileHeader_t *__thiscall CMDLCache::GetVertexData(CMDLCache *this, int handle)
{
  vertexFileHeader_t *result; // eax
  IStudioDataCache_vtbl *v3; // edi
  IStudioDataCache *v4; // esi
  studiohdr_t *v5; // eax

  if ( mod_test_not_available.m_pParent != nullptr && mod_test_not_available.m_pParent->m_Value.m_nValue != 0
    || mod_test_verts_not_available.m_pParent != nullptr
    && mod_test_verts_not_available.m_pParent->m_Value.m_nValue != 0 )
  {
    return nullptr;
  }
  result = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem->m_pForceLockedVertexFileHeader;
  if ( result == nullptr )
  {
    v3 = this->IStudioDataCache::IAppSystem::__vftable;
    v4 = &this->IStudioDataCache;
    v5 = this->GetStudioHdr(this, a2: handle);
    return v3->CacheVertexData(this: v4, a2: v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B1C0
// Name: public: virtual void CMDLCache::ResetErrorModelStatus(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::ResetErrorModelStatus(CMDLCache *this, unsigned __int16 handle)
{
  studiodata_t *elem; // eax

  if ( handle != 0xFFFF )
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
    elem->m_nFlags &= 0xFFF3u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B1F0
// Name: public: void CUtlLinkedList<struct AsyncInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AsyncInfo_t,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::Free(
        CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 16);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 20) = *(_DWORD *)(elem + 20);
      else
        this->m_Head = *(_DWORD *)(elem + 20);
      v4 = *(_DWORD *)(elem + 20);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Tail = *(_DWORD *)(elem + 16);
      *(_DWORD *)(elem + 20) = elem;
      *(_DWORD *)(elem + 16) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 20) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000B260
// Name: void std::_Sort_heap<struct mstudiovertanim_t __near *,bool (*)(struct mstudiovertanim_t const __near &,struct mstudiovertanim_t const __near &)>(struct mstudiovertanim_t __near *,struct mstudiovertanim_t __near *,bool (*)(struct mstudiovertanim_t const __near &,struct mstudiovertanim_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<mstudiovertanim_t *,bool (__cdecl *)(mstudiovertanim_t const &,mstudiovertanim_t const &)>(
        mstudiovertanim_t *_First,
        mstudiovertanim_t *_Last,
        bool (__cdecl *_Pred)(const mstudiovertanim_t *, const mstudiovertanim_t *))
{
  int v3; // eax
  mstudiovertanim_t *v4; // esi
  mstudiovertanim_t _Val; // [esp+4h] [ebp-10h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF0) > 16 )
  {
    v4 = _Last - 1;
    do
    {
      _Val = *v4;
      *v4 = *_First;
      std::_Adjust_heap<mstudiovertanim_t *,int,mstudiovertanim_t,bool (__cdecl *)(mstudiovertanim_t const &,mstudiovertanim_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 16) >> 4,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 16;
    }
    while ( (int)(v3 & 0xFFFFFFF0) > 16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B2E0
// Name: void std::_Sort_heap<struct mstudiovertanim_wrinkle_t __near *,bool (*)(struct mstudiovertanim_wrinkle_t const __near &,struct mstudiovertanim_wrinkle_t const __near &)>(struct mstudiovertanim_wrinkle_t __near *,struct mstudiovertanim_wrinkle_t __near *,bool (*)(struct mstudiovertanim_wrinkle_t const __near &,struct mstudiovertanim_wrinkle_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<mstudiovertanim_wrinkle_t *,bool (__cdecl *)(mstudiovertanim_wrinkle_t const &,mstudiovertanim_wrinkle_t const &)>(
        mstudiovertanim_wrinkle_t *_First,
        mstudiovertanim_wrinkle_t *_Last,
        bool (__cdecl *_Pred)(const mstudiovertanim_wrinkle_t *, const mstudiovertanim_wrinkle_t *))
{
  int v3; // ecx
  mstudiovertanim_wrinkle_t *v4; // esi
  __int16 wrinkledelta; // dx
  mstudiovertanim_wrinkle_t _Val; // [esp+8h] [ebp-14h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( _Last - _First > 1 )
  {
    v4 = _Last - 1;
    do
    {
      wrinkledelta = v4->wrinkledelta;
      _Val.mstudiovertanim_t = v4->mstudiovertanim_t;
      *v4 = *_First;
      _Val.wrinkledelta = wrinkledelta;
      std::_Adjust_heap<mstudiovertanim_wrinkle_t *,int,mstudiovertanim_wrinkle_t,bool (__cdecl *)(mstudiovertanim_wrinkle_t const &,mstudiovertanim_wrinkle_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 18) / 18,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 18;
    }
    while ( v3 / 18 > 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B6D0
// Name: public: void CUtlLinkedList<struct AsyncInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AsyncInfo_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::LinkBefore(
        CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 16);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 20) = *(_DWORD *)(elem + 20);
      else
        this->m_Head = *(_DWORD *)(elem + 20);
      v5 = *(_DWORD *)(elem + 20);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Tail = *(_DWORD *)(elem + 16);
      *(_DWORD *)(elem + 20) = elem;
      *(_DWORD *)(elem + 16) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 20) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 16);
    *(_DWORD *)(before + 16) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 16) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 20) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BAD0
// Name: int GetAsyncInfoIndex(unsigned short,enum MDLCacheDataType_t,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAsyncInfoIndex(unsigned __int16 hModel, MDLCacheDataType_t type, int iAnimBlock)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int16 v4; // ax
  int result; // eax
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_AsyncInfoMapMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_AsyncInfoMapMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_AsyncInfoMapMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_AsyncInfoMapMutex.m_depth;
  }
  search.key = iAnimBlock | ((type | (8 * hModel)) << 13);
  v4 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_AsyncInfoMap.m_Tree,
         &search);
  if ( v4 == 0xFFFF )
    result = NO_ASYNC;
  else
    result = g_AsyncInfoMap.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  if ( --g_AsyncInfoMapMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_AsyncInfoMapMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BB70
// Name: private: enum FSAsyncStatus_t CMDLCache::LoadData(char const __near *,char const __near *,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CMDLCache::LoadData(
        CMDLCache *this,
        const char *pszFilename,
        const char *pszPathID,
        bool bAsync,
        FSAsyncControl_t__ **pControl)
{
  const char *v5; // esi
  unsigned __int8 dst[44]; // [esp+4h] [ebp-2Ch] BYREF

  if ( *pControl != nullptr )
    return FSASYNC_ERR_FAILURE;
  v5 = CModelSwapper::TranslateModelName(this: &this->m_ModelSwapper, pOriginalModelName: pszFilename);
  memset(dst, value: 0, count: sizeof(dst));
  *(_DWORD *)dst = v5;
  *(_DWORD *)&dst[36] = 0xFFFF;
  *(_DWORD *)&dst[32] = pszPathID;
  memset(&dst[4], 0, 12);
  *(_DWORD *)&dst[28] = 1;
  if ( !bAsync )
    *(_DWORD *)&dst[28] = 5;
  return g_pFullFileSystem->AsyncReadMultiple(
           this: g_pFullFileSystem,
           a2: (const FileAsyncRequest_t *)dst,
           a3: 1,
           a4: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC10
// Name: public: bool CMDLCacheData::ReadFileNative(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLCacheData::ReadFileNative(CMDLCacheData *this, char *pFileName, const char *pPath)
{
  const char *v4; // eax
  bool result; // al
  unsigned __int8 *m_pMemory; // edi
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF
  bool bSuccess_3; // [esp+43h] [ebp+Bh]

  if ( this->m_pData != nullptr )
  {
    CMDLCacheData::Deallocate(this, pData: (TSLNodeBase_t *)this->m_pData);
    this->m_pData = nullptr;
    this->m_nDataSize = 0;
  }
  if ( this->m_AllocType != ALLOC_MALLOC )
  {
    _Warning(a1: "ERROR: CMDLCacheData::ReadFileNative is only supported when using ALLOC_MALLOC\n");
    return false;
  }
  else
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    v4 = CModelSwapper::TranslateModelName(this: &g_MDLCache.m_ModelSwapper, pOriginalModelName: pFileName);
    result = g_pFullFileSystem->ReadFile(
               this: &g_pFullFileSystem->IBaseFileSystem,
               a2: v4,
               a3: pPath,
               a4: &buf,
               a5: 0,
               a6: 0,
               a7: nullptr);
    bSuccess_3 = result;
    if ( result )
    {
      this->m_nDataSize = buf.m_nMaxPut;
      if ( buf.m_Memory.m_nGrowSize >= 0 )
      {
        m_pMemory = buf.m_Memory.m_pMemory;
        buf.m_Memory.m_pMemory = nullptr;
        buf.m_Memory.m_nAllocationCount = 0;
      }
      else
      {
        m_pMemory = nullptr;
      }
      memset(&buf.m_Get, 0, 9);
      buf.m_nOffset = 0;
      buf.m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
      result = bSuccess_3;
      this->m_pData = m_pMemory;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return bSuccess_3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BCF0
// Name: private: void CMDLCache::InitStudioData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::InitStudioData(CMDLCache *this, unsigned __int16 handle)
{
  studiodata_t *v3; // eax
  studiodata_t *v4; // esi

  v3 = (studiodata_t *)studiodata_t::operator new(size: 0x8Cu);
  if ( v3 != nullptr )
  {
    v3->m_vecAnimBlocks.m_Memory.m_pMemory = nullptr;
    v3->m_vecAnimBlocks.m_Memory.m_nAllocationCount = 0;
    v3->m_vecAnimBlocks.m_Memory.m_nGrowSize = 0;
    v3->m_vecAnimBlocks.m_Size = 0;
    v3->m_vecAnimBlocks.m_pElements = nullptr;
    v3->m_vecFakeAnimBlockStall.m_Memory.m_pMemory = nullptr;
    v3->m_vecFakeAnimBlockStall.m_Memory.m_nAllocationCount = 0;
    v3->m_vecFakeAnimBlockStall.m_Memory.m_nGrowSize = 0;
    v3->m_vecFakeAnimBlockStall.m_Size = 0;
    v3->m_vecFakeAnimBlockStall.m_pElements = nullptr;
    v3->m_vecAutoplaySequenceList.m_Memory.m_pMemory = nullptr;
    v3->m_vecAutoplaySequenceList.m_Memory.m_nAllocationCount = 0;
    v3->m_vecAutoplaySequenceList.m_Memory.m_nGrowSize = 0;
    v3->m_vecAutoplaySequenceList.m_Size = 0;
    v3->m_vecAutoplaySequenceList.m_pElements = nullptr;
    v3->m_iStudioHdrVirtualLock.m_value = 0;
    v3->m_ForceLockMutex.m_ownerID = 0;
    v3->m_ForceLockMutex.m_depth = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem = v4;
  memset(dst: (unsigned __int8 *)v4, value: 0, count: sizeof(studiodata_t));
  v4->m_Handle = handle;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD80
// Name: private: void CMDLCache::AllocateAnimBlocks(struct studiodata_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::AllocateAnimBlocks(CMDLCache *this, studiodata_t *pStudioData, int nCount)
{
  if ( pStudioData->m_vecAnimBlocks.m_Size < nCount )
    CUtlVector<ResourceList_t__ *,CUtlMemory<ResourceList_t__ *,int>>::InsertMultipleBefore(
      this: (CUtlVector<int,CUtlMemory<int,int> > *)&pStudioData->m_vecAnimBlocks,
      elem: pStudioData->m_vecAnimBlocks.m_Size,
      num: nCount - pStudioData->m_vecAnimBlocks.m_Size);
  memset(dst: (unsigned __int8 *)pStudioData->m_vecAnimBlocks.m_Memory.m_pMemory, value: 0, count: 4 * nCount);
  if ( pStudioData->m_vecFakeAnimBlockStall.m_Size < nCount )
    CUtlVector<ResourceList_t__ *,CUtlMemory<ResourceList_t__ *,int>>::InsertMultipleBefore(
      this: (CUtlVector<int,CUtlMemory<int,int> > *)&pStudioData->m_vecFakeAnimBlockStall,
      elem: pStudioData->m_vecFakeAnimBlockStall.m_Size,
      num: nCount - pStudioData->m_vecFakeAnimBlockStall.m_Size);
  memset(dst: (unsigned __int8 *)pStudioData->m_vecFakeAnimBlockStall.m_Memory.m_pMemory, value: 0, count: 4 * nCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000BDF0
// Name: public: virtual bool CMDLCache::HasAnimBlockBeenPreloaded(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLCache::HasAnimBlockBeenPreloaded(CMDLCache *this, unsigned __int16 handle, int nBlock)
{
  studiodata_t *elem; // eax
  memhandle_t__ *v6; // edi
  IDataCacheSection *v7; // eax
  CThreadFastMutex *p_m_AsyncMutex; // edi
  DWORD CurrentThreadId; // eax
  bool v10; // zf
  studiodata_t *pStudioData; // [esp+4h] [ebp-8h]

  if ( (mod_test_not_available.m_pParent == nullptr || mod_test_not_available.m_pParent->m_Value.m_nValue == 0)
    && handle != 0xFFFF )
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
    pStudioData = elem;
    if ( nBlock <= 0 )
      return true;
    if ( nBlock < elem->m_vecAnimBlocks.m_Size )
    {
      v6 = elem->m_vecAnimBlocks.m_Memory.m_pMemory[nBlock];
      v7 = this->GetCacheSection(this, a2: 3);
      if ( v7->Get(this: v7, a2: v6, a3: true) != nullptr )
        return true;
      p_m_AsyncMutex = &this->m_AsyncMutex;
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != this->m_AsyncMutex.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++this->m_AsyncMutex.m_depth;
      }
      if ( CMDLCache::CheckData(
             this,
             c: pStudioData->m_vecAnimBlocks.m_Memory.m_pMemory[nBlock],
             type: MDLCACHE_ANIMBLOCK) != nullptr )
      {
        v10 = this->m_AsyncMutex.m_depth-- == 1;
        if ( v10 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
        return true;
      }
      v10 = this->m_AsyncMutex.m_depth-- == 1;
      if ( v10 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
      return GetAsyncInfoIndex(hModel: handle, type: MDLCACHE_ANIMBLOCK, iAnimBlock: nBlock) != NO_ASYNC;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000BF00
// Name: private: void CMDLCache::AllocateAutoplaySequences(struct studiodata_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::AllocateAutoplaySequences(CMDLCache *this, studiodata_t *pStudioData, int nCount)
{
  bool v3; // sf

  v3 = pStudioData->m_vecAutoplaySequenceList.m_Memory.m_nGrowSize < 0;
  pStudioData->m_vecAutoplaySequenceList.m_Size = 0;
  if ( !v3 )
  {
    if ( pStudioData->m_vecAutoplaySequenceList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioData->m_vecAutoplaySequenceList.m_Memory.m_pMemory);
      pStudioData->m_vecAutoplaySequenceList.m_Memory.m_pMemory = nullptr;
    }
    pStudioData->m_vecAutoplaySequenceList.m_Memory.m_nAllocationCount = 0;
  }
  pStudioData->m_vecAutoplaySequenceList.m_pElements = pStudioData->m_vecAutoplaySequenceList.m_Memory.m_pMemory;
  if ( pStudioData->m_vecAutoplaySequenceList.m_Size < nCount )
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: &pStudioData->m_vecAutoplaySequenceList,
      elem: pStudioData->m_vecAutoplaySequenceList.m_Size,
      num: nCount - pStudioData->m_vecAutoplaySequenceList.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x1000BF60
// Name: private: bool CMDLCache::ReadMDLFile(unsigned short,char const __near *,class CMDLCacheData __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::ReadMDLFile(
        CMDLCache *this,
        unsigned __int16 handle,
        const char *pMDLFileName,
        CMDLCacheData *cacheData)
{
  studiohdr_t *m_pData; // eax
  char pFileName[260]; // [esp+Ch] [ebp-104h] BYREF

  V_strncpy(pDest: pFileName, pSrc: pMDLFileName, maxLen: 260);
  V_FixSlashes(pname: pFileName, separator: 92);
  if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "MDLCache: Load studiohdr %s\n", pFileName);
  if ( CMDLCacheData::ReadFileNative(this: cacheData, pFileName, pPath: "GAME")
    && (m_pData = (studiohdr_t *)cacheData->m_pData, cacheData->m_pData != nullptr) )
  {
    if ( cacheData->m_nDataSize >= 0x198u )
    {
      if ( m_pData->id == 1414743113 )
      {
        m_pData->virtualModel = (void *)handle;
        if ( developer.m_pConVarState->m_Value.m_nValue < 2
          || this->VerifyHeaders(this: &this->IStudioDataCache, a2: m_pData) )
        {
          return 1;
        }
        else
        {
          DevWarning(a1: "Model %s has mismatched .vvd + .vtx files!\n", pMDLFileName);
          return 0;
        }
      }
      else
      {
        DevWarning(a1: "Model %s not a .MDL format file!\n", pMDLFileName);
        return 0;
      }
    }
    else
    {
      DevWarning(a1: "Empty model %s\n", pMDLFileName);
      return 0;
    }
  }
  else
  {
    DevWarning(a1: "Failed to load %s!\n", pMDLFileName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C170
// Name: public: void CUtlDict<struct studiodata_t __near *,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<studiodata_t *,unsigned short>::RemoveAll(CUtlDict<studiodata_t *,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1000C240
// Name: public: void CModelSwapper::LoadSubstitutionFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelSwapper::LoadSubstitutionFile(CModelSwapper *this, KeyValues *pSubstitutionDefinitionFile)
{
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  int Int; // ebx
  int v8; // edi
  int v9; // eax
  int v10; // ecx
  unsigned int i; // ebx
  char *v12; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v16; // eax
  const char **v17; // eax
  char *v18; // edi
  int v19; // edi
  int v20; // eax
  const char **v21; // ecx
  int v22; // eax
  const char **v23; // eax
  CModelSwapper::ModelSubstitution_t modelSubstitution; // [esp+Ch] [ebp-20h] BYREF
  int pIndex; // [esp+18h] [ebp-14h] BYREF
  unsigned int pBucket; // [esp+1Ch] [ebp-10h] BYREF
  const char *pSubstituteModelName; // [esp+20h] [ebp-Ch]
  const char *pOriginalModelName; // [esp+24h] [ebp-8h]
  KeyValues *pKV; // [esp+28h] [ebp-4h]
  KeyValues *pSubKV; // [esp+34h] [ebp+8h]

  CModelSwapper::Cleanup(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    pKV = KeyValues::KeyValues(this: v3, setName: "ModelSubstitution");
  else
    pKV = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: pKV,
          filesystem: v4,
          resourceName: (const char *)pSubstitutionDefinitionFile,
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "PERF WARNING: Failed to open model substitution file, cannot swap models out based on gpu_level!\n");
    goto LABEL_36;
  }
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKV);
  pSubKV = FirstSubKey;
  if ( FirstSubKey == nullptr )
  {
LABEL_36:
    KeyValues::deleteThis(this: pKV);
    return;
  }
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "sub") == 0 )
    {
      Int = KeyValues::GetInt(this: FirstSubKey, keyName: "maxgpulevel", defaultValue: 1);
      pOriginalModelName = KeyValues::GetString(this: FirstSubKey, keyName: "original", defaultValue: defaultValue);
      pSubstituteModelName = KeyValues::GetString(this: FirstSubKey, keyName: "substitute", defaultValue: defaultValue);
      v8 = _V_strlen(str: pOriginalModelName);
      v9 = _V_strlen(str: pSubstituteModelName);
      v10 = 260 - this->m_nMaxExtensionLength;
      if ( v8 >= v10 || v9 >= v10 )
      {
        _Warning(a1: "PERF WARNING: error parsing cfg/model_substitution.txt\n");
      }
      else
      {
        modelSubstitution.nMaxGPULevel = Int;
        for ( i = 0; i < 4; ++i )
        {
          v12 = (char *)operator new(nSize: 0x104u);
          modelSubstitution.pOriginalModelName = v12;
          V_strncpy(pDest: v12, pSrc: pOriginalModelName, maxLen: 260);
          V_strncat(pDest: v12, pSrc: s_ModelSwapperExtensions[i], destBufferSize: 0x104u, max_chars_to_copy: -1);
          m_Size = this->m_Strings.m_Size;
          m_nAllocationCount = this->m_Strings.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_Strings.m_Size;
          m_pMemory = this->m_Strings.m_Memory.m_pMemory;
          v16 = this->m_Strings.m_Size - m_Size - 1;
          this->m_Strings.m_pElements = this->m_Strings.m_Memory.m_pMemory;
          if ( v16 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
          v17 = &this->m_Strings.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = modelSubstitution.pOriginalModelName;
          v18 = (char *)operator new(nSize: 0x104u);
          modelSubstitution.pSubstituteModelName = v18;
          V_strncpy(pDest: v18, pSrc: pSubstituteModelName, maxLen: 260);
          V_strncat(pDest: v18, pSrc: s_ModelSwapperExtensions[i], destBufferSize: 0x104u, max_chars_to_copy: -1);
          v19 = this->m_Strings.m_Size;
          v20 = this->m_Strings.m_Memory.m_nAllocationCount;
          if ( v19 + 1 > v20 )
            CUtlMemory<unsigned long,int>::Grow(
              (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
              num: v19 - v20 + 1);
          ++this->m_Strings.m_Size;
          v21 = this->m_Strings.m_Memory.m_pMemory;
          v22 = this->m_Strings.m_Size - v19 - 1;
          this->m_Strings.m_pElements = this->m_Strings.m_Memory.m_pMemory;
          if ( v22 > 0 )
            _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
          v23 = &this->m_Strings.m_Memory.m_pMemory[v19];
          if ( v23 != nullptr )
            *v23 = modelSubstitution.pSubstituteModelName;
          if ( CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>::DoFind(
                 this: &this->m_ModelLookup,
                 src: &modelSubstitution,
                 &pBucket,
                 &pIndex) == 0 )
            CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>::InsertBefore(
              this: &this->m_ModelLookup.m_Buckets.m_Memory.m_pMemory[pBucket],
              elem: this->m_ModelLookup.m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
              src: &modelSubstitution);
        }
      }
      FirstSubKey = pSubKV;
    }
    pSubKV = KeyValues::GetNextKey(this: FirstSubKey);
    if ( pSubKV == nullptr )
      break;
    FirstSubKey = pSubKV;
  }
  KeyValues::deleteThis(this: pKV);
}

//------------------------------------------------------------------------------
// Address: 0x1000C4F0
// Name: public: virtual enum InitReturnVal_t CMDLCache::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLCache::Init(CMDLCache *this)
{
  IDataCacheSection *v2; // eax
  IDataCacheSection v3; // edi
  int v4; // eax
  DataCacheLimits_t limits; // [esp+4h] [ebp-10h] BYREF

  if ( (*((_BYTE *)this + 160) & 4) == 0 )
  {
    if ( g_pCVar != nullptr )
      ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
    if ( this->m_pModelCacheSection == nullptr )
    {
      limits.nMaxBytes = -1;
      limits.nMaxItems = -1;
      limits.nMinBytes = 0;
      limits.nMinItems = 0;
      this->m_pModelCacheSection = g_pDataCache->AddSection(
                                     this: g_pDataCache,
                                     a2: &this->CDefaultDataCacheClient,
                                     a3: "ModelData",
                                     a4: &limits,
                                     a5: 0);
    }
    if ( this->m_pMeshCacheSection == nullptr )
    {
      limits.nMaxBytes = -1;
      limits.nMaxItems = -1;
      limits.nMinBytes = 0;
      limits.nMinItems = 0;
      v2 = g_pDataCache->AddSection(
             this: g_pDataCache,
             a2: &this->CDefaultDataCacheClient,
             a3: "ModelMesh",
             a4: &limits,
             a5: 0);
      this->m_pMeshCacheSection = v2;
      v3.__vftable = v2->__vftable;
      v4 = v2->GetOptions(this: v2);
      v3.SetOptions(this: this->m_pMeshCacheSection, a2: v4 | 0x10);
    }
    if ( this->m_pAnimBlocksCacheSection == nullptr )
    {
      limits.nMaxBytes = -1;
      limits.nMaxItems = -1;
      limits.nMinBytes = 0;
      limits.nMinItems = 0;
      this->m_pAnimBlocksCacheSection = g_pDataCache->AddSection(
                                          this: g_pDataCache,
                                          a2: &this->CDefaultDataCacheClient,
                                          a3: "AnimBlock",
                                          a4: &limits,
                                          a5: 0);
    }
    *((_BYTE *)this + 160) = *((_BYTE *)this + 160) & 0xFA | 4;
    CModelSwapper::LoadSubstitutionFile(
      this: &this->m_ModelSwapper,
      pSubstitutionDefinitionFile: (KeyValues *)"cfg/model_substitution.txt");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C600
// Name: private: void CMDLCache::ConvertFlexData(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::ConvertFlexData(CMDLCache *this, studiohdr_t *pStudioHdr)
{
  studiohdr_t *v2; // eax
  float flVertAnimFixedPointScale; // xmm0_4
  int v4; // edi
  int v5; // edx
  int v6; // edx
  mstudiomodel_t *v7; // ecx
  mstudiomesh_t *v8; // eax
  char *v9; // esi
  int v10; // ebx
  int v11; // ecx
  int v12; // ecx
  mstudiovertanim_wrinkle_t *v13; // edi
  mstudiovertanim_wrinkle_t *v14; // esi
  mstudiovertanim_t *v15; // edi
  mstudiovertanim_t *v16; // esi
  mstudiobodyparts_t *pBody; // [esp+10h] [ebp-38h]
  mstudiomodel_t *pModel; // [esp+14h] [ebp-34h]
  int v19; // [esp+18h] [ebp-30h]
  int i; // [esp+1Ch] [ebp-2Ch]
  int j; // [esp+20h] [ebp-28h]
  int k; // [esp+24h] [ebp-24h]
  int l; // [esp+28h] [ebp-20h]
  int v24; // [esp+30h] [ebp-18h]
  int v25; // [esp+34h] [ebp-14h]
  int v26; // [esp+38h] [ebp-10h]
  mstudiomesh_t *pMesh; // [esp+3Ch] [ebp-Ch]
  int v28; // [esp+40h] [ebp-8h]
  bool bIsWrinkleAnim; // [esp+47h] [ebp-1h]

  v2 = pStudioHdr;
  if ( (pStudioHdr->flags & 0x200000) != 0 )
    flVertAnimFixedPointScale = pStudioHdr->flVertAnimFixedPointScale;
  else
    flVertAnimFixedPointScale = 0.00024414062;
  v4 = 0;
  i = 0;
  if ( pStudioHdr->numbodyparts > 0 )
  {
    v5 = 0;
    v19 = 0;
    do
    {
      v6 = (int)v2 + v5 + v2->bodypartindex;
      j = 0;
      pBody = (mstudiobodyparts_t *)v6;
      if ( *(int *)(v6 + 4) <= 0 )
        goto LABEL_33;
      v24 = 0;
      do
      {
        k = 0;
        v7 = (mstudiomodel_t *)(v6 + v24 + *(_DWORD *)(v6 + 12));
        pModel = v7;
        if ( v7->nummeshes <= 0 )
          goto LABEL_32;
        v25 = 0;
        do
        {
          l = 0;
          v8 = (mstudiomesh_t *)&v7->name[v25 + v7->meshindex];
          pMesh = v8;
          if ( v8->numflexes <= 0 )
            goto LABEL_30;
          v26 = 0;
          do
          {
            v9 = (char *)v8 + v26 + v8->flexindex;
            bIsWrinkleAnim = v9[32] == 1;
            if ( *((int *)v9 + 5) > 0 )
            {
              v28 = 0;
              v10 = 0;
              do
              {
                v11 = *((_DWORD *)v9 + 6);
                if ( bIsWrinkleAnim )
                  v12 = v10 + v11;
                else
                  v12 = v28 + v11;
                mstudiovertanim_t::ConvertToFixed(this: (mstudiovertanim_t *)&v9[v12], flVertAnimFixedPointScale);
                v28 += 16;
                ++v4;
                v10 += 18;
              }
              while ( v4 < *((_DWORD *)v9 + 5) );
              v8 = pMesh;
            }
            if ( v9[32] != 0 )
            {
              if ( v9[32] != 1 )
                goto LABEL_28;
              v13 = (mstudiovertanim_wrinkle_t *)&v9[*((_DWORD *)v9 + 6)];
              v14 = &v13[*((_DWORD *)v9 + 5)];
              if ( v14 - v13 > 1 )
                std::_Make_heap<mstudiovertanim_wrinkle_t *,int,mstudiovertanim_wrinkle_t,bool (__cdecl *)(mstudiovertanim_wrinkle_t const &,mstudiovertanim_wrinkle_t const &)>(
                  _First: v13,
                  _Last: v14,
                  _Pred: (bool (__cdecl *)(const mstudiovertanim_wrinkle_t *, const mstudiovertanim_wrinkle_t *))SortLessFuncWrinkle);
              std::_Sort_heap<mstudiovertanim_wrinkle_t *,bool (__cdecl *)(mstudiovertanim_wrinkle_t const &,mstudiovertanim_wrinkle_t const &)>(
                _First: v13,
                _Last: v14,
                _Pred: (bool (__cdecl *)(const mstudiovertanim_wrinkle_t *, const mstudiovertanim_wrinkle_t *))SortLessFuncWrinkle);
            }
            else
            {
              v15 = (mstudiovertanim_t *)&v9[*((_DWORD *)v9 + 6)];
              v16 = &v15[*((_DWORD *)v9 + 5)];
              if ( (int)(((char *)v16 - (char *)v15) & 0xFFFFFFF0) > 16 )
                std::_Make_heap<mstudiovertanim_t *,int,mstudiovertanim_t,bool (__cdecl *)(mstudiovertanim_t const &,mstudiovertanim_t const &)>(
                  _First: v15,
                  _Last: v16,
                  _Pred: (bool (__cdecl *)(const mstudiovertanim_t *, const mstudiovertanim_t *))SortLessFuncWrinkle);
              std::_Sort_heap<mstudiovertanim_t *,bool (__cdecl *)(mstudiovertanim_t const &,mstudiovertanim_t const &)>(
                _First: v15,
                _Last: v16,
                _Pred: (bool (__cdecl *)(const mstudiovertanim_t *, const mstudiovertanim_t *))SortLessFuncWrinkle);
            }
            v8 = pMesh;
LABEL_28:
            v26 += 60;
            v4 = 0;
            ++l;
          }
          while ( l < v8->numflexes );
          v7 = pModel;
          v6 = (int)pBody;
LABEL_30:
          v25 += 116;
          ++k;
        }
        while ( k < v7->nummeshes );
        v2 = pStudioHdr;
LABEL_32:
        v24 += 148;
        ++j;
      }
      while ( j < *(_DWORD *)(v6 + 4) );
LABEL_33:
      v5 = v19 + 16;
      ++i;
      v19 += 16;
    }
    while ( i < v2->numbodyparts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C800
// Name: public: void CMDLCache::ReleaseMaterialSystemObjects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::ReleaseMaterialSystemObjects(CMDLCache *this, int nChangeFlags)
{
  IDataCacheSection *m_pMeshCacheSection; // ecx
  IDataCacheSection *v4; // ecx
  IDataCacheSection *m_pAnimBlocksCacheSection; // ecx
  unsigned __int16 Inorder; // ax
  studiodata_t *elem; // ebx
  IMDLCacheNotify *m_pCacheNotify; // ecx
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  m_pMeshCacheSection = this->m_pMeshCacheSection;
  *((_BYTE *)this + 160) |= 1u;
  if ( m_pMeshCacheSection->IsFrameLocking(this: m_pMeshCacheSection) )
  {
    this->m_nMeshCacheFrameLocks = 0;
    do
    {
      v4 = this->m_pMeshCacheSection;
      ++this->m_nMeshCacheFrameLocks;
    }
    while ( v4->EndFrameLocking(this: v4) != 0 );
  }
  if ( this->m_pAnimBlocksCacheSection->IsFrameLocking(this: this->m_pAnimBlocksCacheSection) )
  {
    this->m_nAnimBlockCacheFrameLocks = 0;
    do
    {
      m_pAnimBlocksCacheSection = this->m_pAnimBlocksCacheSection;
      ++this->m_nAnimBlockCacheFrameLocks;
    }
    while ( m_pAnimBlocksCacheSection->EndFrameLocking(this: m_pAnimBlocksCacheSection) != 0 );
  }
  Inorder = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MDLDict.m_Elements.m_Tree);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    if ( elem != nullptr && (elem->m_nFlags & 1) != 0 )
    {
      m_pCacheNotify = this->m_pCacheNotify;
      if ( m_pCacheNotify != nullptr )
        m_pCacheNotify->OnDataUnloaded(this: m_pCacheNotify, a2: MDLCACHE_STUDIOHWDATA, a3: elem->m_Handle);
      g_pStudioRender->UnloadModel(this: g_pStudioRender, a2: &elem->m_HardwareData);
      *(_QWORD *)&elem->m_HardwareData.m_RootLOD = 0;
      *(_QWORD *)&elem->m_HardwareData.m_pLODs = 0;
      *(_QWORD *)&elem->m_HardwareData.m_NumFacesRenderedThisFrame = 0;
      elem->m_HardwareData.m_pStudioHdr = nullptr;
      elem->m_nFlags &= ~1u;
      Inorder = i;
    }
    Inorder = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_MDLDict.m_Elements.m_Tree,
                i: Inorder);
  }
  CMDLCache::RestoreFrameLock(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000C920
// Name: private: struct studiohdr_t __near * CMDLCache::UnserializeMDL(unsigned short,class CMDLCacheData __near &)
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CMDLCache::UnserializeMDL(CMDLCache *this, int handle, studiohdr_t *cacheData)
{
  studiohdr_t *id; // edi
  ConVar *m_pParent; // eax
  int v7; // eax
  bool v8; // zf
  int v9; // ecx
  const char *v10; // eax
  void *v11; // eax
  int v12; // ebx
  IDataCacheSection *v13; // eax
  IDataCacheSection *v14; // eax
  studiodata_t **v15; // edi
  unsigned int length; // [esp+8h] [ebp-Ch]
  studiodata_t **p_elem; // [esp+Ch] [ebp-8h]
  studiodata_t *v18; // [esp+Ch] [ebp-8h]
  unsigned __int8 *dst; // [esp+10h] [ebp-4h]
  studiohdr_t *pStudioHdrIn; // [esp+20h] [ebp+Ch]

  id = (studiohdr_t *)cacheData->id;
  pStudioHdrIn = id;
  if ( id == nullptr )
    return nullptr;
  m_pParent = r_rootlod.m_pParent;
  if ( r_rootlod.m_pParent != nullptr && r_rootlod.m_pParent->m_Value.m_nValue > 0 )
  {
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      v7 = _CommandLine();
      v8 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-r_rootlod_enable") == 0;
      m_pParent = r_rootlod.m_pParent;
      s_bTempRootLodEnable = !v8;
    }
    if ( s_bTempRootLodEnable )
    {
      if ( m_pParent != nullptr )
        Studio_SetRootLOD(pStudioHdr: id, rootLOD: m_pParent->m_Value.m_nValue);
      else
        Studio_SetRootLOD(pStudioHdr: id, rootLOD: 0);
    }
    else if ( _executeCount_0 < 5 )
    {
      ++_executeCount_0;
      _Warning(a1: "r_rootlod is temporarily unsupported: bugbait#70052");
    }
  }
  StudioHdrLookupSurfaceProps(pStudioHdrIn: id);
  if ( id->numincludemodels == 0 )
    StudioHdrSetAnimEventFlag(a1: v9, pStudioHdrIn: id);
  id->virtualModel = (void *)(unsigned __int16)handle;
  if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = this->GetModelName(this, a2: handle);
    _Msg(a1: "MDLCache: Alloc studiohdr %s\n", v10);
  }
  v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: id->length + 35);
  if ( v11 != nullptr )
  {
    *(_DWORD *)((((unsigned int)v11 + 35) & 0xFFFFFFE0) - 4) = v11;
    dst = (unsigned __int8 *)(((unsigned int)v11 + 35) & 0xFFFFFFE0);
    p_elem = &this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
    v12 = (unsigned __int16)handle << 16;
    this->GetModelName(this, a2: handle);
    length = id->length;
    v18 = *p_elem;
    if ( v12 == -1 )
      v12 = (int)dst;
    v13 = this->GetCacheSection(this, a2: 0);
    v13->Add(this: v13, a2: v12, a3: dst, a4: length, a5: &v18->m_MDLCache);
    if ( mod_lock_mdls_on_load.m_pParent != nullptr && mod_lock_mdls_on_load.m_pParent->m_Value.m_nValue != 0 )
    {
      v14 = this->GetCacheSection(this, a2: 0);
      v15 = &this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
      (*v15)->m_pForceLockedStudioHdr = (studiohdr_t *)v14->Lock(this: v14, a2: (*v15)->m_MDLCache);
    }
    memcpy(dst, src: (unsigned __int8 *)pStudioHdrIn, count: pStudioHdrIn->length);
    if ( (*((_DWORD *)dst + 38) & 0x4000) == 0 )
    {
      CMDLCache::ConvertFlexData(this, pStudioHdr: (studiohdr_t *)dst);
      *((_DWORD *)dst + 38) |= 0x4000u;
    }
    if ( this->m_pCacheNotify != nullptr )
      this->m_pCacheNotify->OnDataLoaded(this: this->m_pCacheNotify, a2: MDLCACHE_STUDIOHDR, a3: handle);
    return (studiohdr_t *)dst;
  }
  else
  {
    _Error(a1: "CMDLCache:: Out of memory");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CB40
// Name: public: virtual void CMDLCache::Flush(enum MDLCacheFlush_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::Flush(CMDLCache *this, MDLCacheFlush_t nFlushFlags)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MDLDict.m_Elements.m_Tree);
        (_WORD)i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_MDLDict.m_Elements.m_Tree,
              i) )
  {
    this->Flush(this, a2: i, a3: nFlushFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CB90
// Name: public: virtual void CMDLCache::BeginMapLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::BeginMapLoad(CMDLCache *this)
{
  IDataCacheSection *m_pModelCacheSection; // ecx
  IDataCacheSection *m_pMeshCacheSection; // ecx
  IDataCacheSection *m_pAnimBlocksCacheSection; // ecx
  studiodata_t *elem; // edi
  IDataCacheSection *v6; // eax
  IDataCacheSection *v7; // eax
  IDataCacheSection *v8; // eax
  IDataCacheSection *v9; // eax
  unsigned __int16 i; // [esp+8h] [ebp-4h]

  if ( this->m_pModelCacheSection->IsFrameLocking(this: this->m_pModelCacheSection) )
  {
    this->m_nModelCacheFrameLocks = 0;
    do
    {
      m_pModelCacheSection = this->m_pModelCacheSection;
      ++this->m_nModelCacheFrameLocks;
    }
    while ( m_pModelCacheSection->EndFrameLocking(this: m_pModelCacheSection) != 0 );
  }
  if ( this->m_pMeshCacheSection->IsFrameLocking(this: this->m_pMeshCacheSection) )
  {
    this->m_nMeshCacheFrameLocks = 0;
    do
    {
      m_pMeshCacheSection = this->m_pMeshCacheSection;
      ++this->m_nMeshCacheFrameLocks;
    }
    while ( m_pMeshCacheSection->EndFrameLocking(this: m_pMeshCacheSection) != 0 );
  }
  if ( this->m_pAnimBlocksCacheSection->IsFrameLocking(this: this->m_pAnimBlocksCacheSection) )
  {
    this->m_nAnimBlockCacheFrameLocks = 0;
    do
    {
      m_pAnimBlocksCacheSection = this->m_pAnimBlocksCacheSection;
      ++this->m_nAnimBlockCacheFrameLocks;
    }
    while ( m_pAnimBlocksCacheSection->EndFrameLocking(this: m_pAnimBlocksCacheSection) != 0 );
  }
  for ( i = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MDLDict.m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_MDLDict.m_Elements.m_Tree,
              i) )
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem->m_pForceLockedStudioHdr != nullptr )
    {
      while ( elem->m_iStudioHdrVirtualLock.m_value > 0 )
      {
        _InterlockedExchangeAdd(&elem->m_iStudioHdrVirtualLock.m_value, 0xFFFFFFFF);
        v6 = this->GetCacheSection(this, a2: 0);
        v6->Lock(this: v6, a2: elem->m_MDLCache);
      }
      while ( elem->m_iStudioHdrVirtualLock.m_value < 0 )
      {
        _InterlockedExchangeAdd(&elem->m_iStudioHdrVirtualLock.m_value, 1u);
        v7 = this->GetCacheSection(this, a2: 0);
        v7->Unlock(this: v7, a2: elem->m_MDLCache);
      }
      v8 = this->GetCacheSection(this, a2: 0);
      v8->Unlock(this: v8, a2: elem->m_MDLCache);
      elem->m_pForceLockedStudioHdr = nullptr;
    }
    if ( elem->m_pForceLockedVertexFileHeader != nullptr )
    {
      v9 = this->GetCacheSection(this, a2: 5);
      v9->Unlock(this: v9, a2: elem->m_VertexCache);
      elem->m_pForceLockedVertexFileHeader = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CD10
// Name: public: virtual void CMDLCache::EndMapLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::EndMapLoad(CMDLCache *this)
{
  int m_nValue; // eax
  unsigned __int16 Inorder; // ax
  int v4; // esi
  studiodata_t *elem; // eax
  unsigned __int16 v6; // ax
  bool bLockMdls; // [esp+6h] [ebp-2h]
  bool bLockMeshes; // [esp+7h] [ebp-1h]

  this->FinishPendingLoads(this);
  if ( mod_lock_mdls_on_load.m_pParent != nullptr )
    m_nValue = mod_lock_mdls_on_load.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bLockMdls = m_nValue != 0;
  if ( mod_load_mesh_async.m_pParent != nullptr && mod_load_mesh_async.m_pParent->m_Value.m_nValue != 0
    || mod_lock_meshes_on_load.m_pParent == nullptr
    || (bLockMeshes = true, mod_lock_meshes_on_load.m_pParent->m_Value.m_nValue == 0) )
  {
    bLockMeshes = false;
  }
  if ( m_nValue != 0 || bLockMeshes )
  {
    Inorder = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MDLDict.m_Elements.m_Tree);
    v4 = Inorder;
    if ( Inorder != 0xFFFF )
    {
      do
      {
        if ( bLockMdls
          && this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v4].m_Data.elem->m_pForceLockedStudioHdr == nullptr )
        {
          this->Flush(this, a2: v4, a3: 1);
        }
        if ( bLockMeshes )
        {
          elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v4].m_Data.elem;
          if ( (elem->m_nFlags & 0x10) == 0 && elem->m_pForceLockedVertexFileHeader == nullptr )
            this->Flush(this, a2: v4, a3: 64);
        }
        v6 = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
               this: &this->m_MDLDict.m_Elements.m_Tree,
               i: v4);
        v4 = v6;
      }
      while ( v6 != 0xFFFF );
    }
  }
  CMDLCache::RestoreFrameLock(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000CE00
// Name: public: virtual bool CMDLCache::IsDataLoaded(unsigned short,enum MDLCacheDataType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLCache::IsDataLoaded(CMDLCache *this, unsigned __int16 handle, MDLCacheDataType_t type)
{
  CUtlDict<studiodata_t *,unsigned short> *p_m_MDLDict; // ecx
  studiodata_t *elem; // esi
  IDataCacheSection *v6; // eax
  __int16 v7; // ax
  int m_Size; // eax
  IDataCacheSection *v9; // eax
  int i; // [esp+14h] [ebp+8h]

  if ( handle != 0xFFFF )
  {
    p_m_MDLDict = &this->m_MDLDict;
    if ( handle < this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount
      && handle <= this->m_MDLDict.m_Elements.m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_MDLDict->m_Elements.m_Tree,
           i: handle) != handle )
    {
      elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
      switch ( type )
      {
        case MDLCACHE_STUDIOHDR:
          v6 = this->GetCacheSection(this, a2: 0);
          LOBYTE(v7) = v6->IsPresent(this: v6, a2: elem->m_MDLCache);
          return v7;
        case MDLCACHE_STUDIOHWDATA:
          return elem->m_nFlags & 1;
        case MDLCACHE_VCOLLIDE:
          LOBYTE(v7) = (elem->m_nFlags & 2) != 0;
          return v7;
        case MDLCACHE_ANIMBLOCK:
          m_Size = elem->m_vecAnimBlocks.m_Size;
          if ( m_Size == 0 )
            goto LABEL_17;
          i = 0;
          if ( m_Size <= 0 )
            goto LABEL_14;
          break;
        case MDLCACHE_VIRTUALMODEL:
          LOBYTE(v7) = elem->m_pVirtualModel != nullptr;
          return v7;
        case MDLCACHE_VERTEXES:
          LOBYTE(v7) = this->m_pMeshCacheSection->IsPresent(this: this->m_pMeshCacheSection, a2: elem->m_VertexCache);
          return v7;
        default:
          goto LABEL_17;
      }
      while ( elem->m_vecAnimBlocks.m_Memory.m_pMemory[i] != nullptr )
      {
        v9 = this->GetCacheSection(this, a2: 3);
        if ( !v9->IsPresent(this: v9, a2: elem->m_vecAnimBlocks.m_Memory.m_pMemory[i]) )
          break;
        if ( ++i >= elem->m_vecAnimBlocks.m_Size )
        {
LABEL_14:
          LOBYTE(v7) = 1;
          return v7;
        }
      }
    }
  }
LABEL_17:
  LOBYTE(v7) = 0;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF50
// Name: public: int CUtlLinkedList<struct AsyncInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AsyncInfo_t,int>>>::AddToTail(struct AsyncInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AddToTail(
        CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> > > *this,
        const AsyncInfo_t *src)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *result; // eax
  AsyncInfo_t *v4; // esi

  result = CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AllocInternal(
             this,
             multilist: false);
  v4 = (AsyncInfo_t *)result;
  if ( result != nullptr )
  {
    CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::LinkBefore(
      this,
      before: 0,
      elem: (int)result);
    *v4 = *src;
    return (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D210
// Name: ReleaseMaterialSystemObjects
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseMaterialSystemObjects(int nChangeFlags)
{
  CMDLCache::ReleaseMaterialSystemObjects(this: &g_MDLCache, nChangeFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1000D230
// Name: public: bool CUtlMap<int,int,unsigned short>::Remove(int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<int,int,unsigned short>::Remove(CUtlMap<int,int,unsigned short> *this, int *key)
{
  int v3; // edi
  int v4; // eax
  CUtlMap<int,int,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-8h] BYREF

  dummyNode.key = *key;
  v3 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  if ( (_WORD)v3 == 0xFFFF )
    return 0;
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v3);
  v4 = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Left = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Right = this->m_Tree.m_FirstFree;
  this->m_Tree.m_FirstFree = v3;
  --this->m_Tree.m_NumElements;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D2A0
// Name: public: unsigned short CUtlDict<struct studiodata_t __near *,unsigned short>::Insert(char const __near *,struct studiodata_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<studiodata_t *,unsigned short>::Insert(
        CUtlDict<studiodata_t *,unsigned short> *this,
        const char *pName,
        studiodata_t **element)
{
  char *v4; // eax
  studiodata_t *v5; // edx
  CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x1000D310
// Name: public: void CUtlDict<struct studiodata_t __near *,unsigned short>::RemoveAt(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<studiodata_t *,unsigned short>::RemoveAt(
        CUtlDict<studiodata_t *,unsigned short> *this,
        unsigned __int16 elem)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[elem].m_Data.key);
  if ( elem != 0xFFFF )
  {
    CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_Elements.m_Tree,
      elem);
    this->m_Elements.m_Tree.m_Elements.m_pMemory[elem].m_Left = elem;
    this->m_Elements.m_Tree.m_Elements.m_pMemory[elem].m_Right = this->m_Elements.m_Tree.m_FirstFree;
    --this->m_Elements.m_Tree.m_NumElements;
    this->m_Elements.m_Tree.m_FirstFree = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D370
// Name: int SetAsyncInfoIndex(unsigned short,enum MDLCacheDataType_t,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SetAsyncInfoIndex(unsigned __int16 hModel, MDLCacheDataType_t type, int iAnimBlock, int index)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int16 v5; // cx
  int v6; // esi
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *v7; // eax
  unsigned __int16 v8; // dx
  int v9; // edx
  CUtlMap<int,int,unsigned short>::Node_t insert; // [esp+8h] [ebp-14h] BYREF
  int key; // [esp+10h] [ebp-Ch] BYREF
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_AsyncInfoMapMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_AsyncInfoMapMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_AsyncInfoMapMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_AsyncInfoMapMutex.m_depth;
  }
  key = iAnimBlock | ((type | (8 * hModel)) << 13);
  if ( index == NO_ASYNC )
  {
    CUtlMap<int,int,unsigned short>::Remove(this: &g_AsyncInfoMap, &key);
  }
  else
  {
    insert.key = iAnimBlock | ((type | (8 * hModel)) << 13);
    insert.elem = index;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &g_AsyncInfoMap.m_Tree,
      &insert,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&g_AsyncInfoMap);
    v6 = v5;
    v7 = &g_AsyncInfoMap.m_Tree.m_Elements.m_pMemory[v5];
    v8 = parent[0];
    v7->m_Right = -1;
    v7->m_Left = -1;
    v7->m_Tag = 0;
    v7->m_Parent = v8;
    if ( v8 == 0xFFFF )
    {
      g_AsyncInfoMap.m_Tree.m_Root = v5;
    }
    else
    {
      v9 = v8;
      if ( leftchild )
        g_AsyncInfoMap.m_Tree.m_Elements.m_pMemory[v9].m_Left = v5;
      else
        g_AsyncInfoMap.m_Tree.m_Elements.m_pMemory[v9].m_Right = v5;
    }
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &g_AsyncInfoMap.m_Tree,
      elem: v5);
    ++g_AsyncInfoMap.m_Tree.m_NumElements;
    if ( &g_AsyncInfoMap.m_Tree.m_Elements.m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *)-8 )
      g_AsyncInfoMap.m_Tree.m_Elements.m_pMemory[v6].m_Data = insert;
  }
  if ( --g_AsyncInfoMapMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_AsyncInfoMapMutex, 0);
  return index;
}

//------------------------------------------------------------------------------
// Address: 0x1000D4C0
// Name: public: virtual unsigned short CMDLCache::FindMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CMDLCache::FindMDL(CMDLCache *this, const char *pMDLRelativePath)
{
  unsigned __int16 v3; // ax
  int v4; // esi
  unsigned __int16 v5; // ax
  char szFixedName[260]; // [esp+Ch] [ebp-10Ch] BYREF
  CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t search; // [esp+110h] [ebp-8h] BYREF

  V_strncpy(pDest: szFixedName, pSrc: pMDLRelativePath, maxLen: 260);
  V_RemoveDotSlashes(pFilename: szFixedName, separator: 47);
  if ( g_pResourceAccessControl != nullptr
    && !g_pResourceAccessControl->IsAccessAllowed(this: g_pResourceAccessControl, a2: RESOURCE_MODEL, a3: szFixedName) )
  {
    V_strncpy(pDest: szFixedName, pSrc: "models/error.mdl", maxLen: 260);
  }
  search.key = szFixedName;
  v3 = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_MDLDict.m_Elements.m_Tree,
         &search);
  v4 = v3;
  if ( v3 == 0xFFFF )
  {
    pMDLRelativePath = nullptr;
    v5 = CUtlDict<studiodata_t *,unsigned short>::Insert(
           this: &this->m_MDLDict,
           pName: szFixedName,
           element: (studiodata_t **)&pMDLRelativePath);
    v4 = v5;
    CMDLCache::InitStudioData(this, handle: v5);
  }
  this->AddRef(this, a2: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000D590
// Name: private: bool CMDLCache::ClearAsync(unsigned short,enum MDLCacheDataType_t,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::ClearAsync(
        CMDLCache *this,
        unsigned __int16 handle,
        MDLCacheDataType_t type,
        int iAnimBlock,
        bool bAbort)
{
  FSAsyncControl_t__ **AsyncInfoIndex; // edi
  CThreadFastMutex *p_m_AsyncMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v9; // zf
  DWORD v10; // eax
  int ignored; // [esp+8h] [ebp-10h] BYREF
  CMDLCache *v13; // [esp+10h] [ebp-8h]
  void *pData; // [esp+14h] [ebp-4h] BYREF

  v13 = this;
  AsyncInfoIndex = (FSAsyncControl_t__ **)GetAsyncInfoIndex(hModel: handle, type, iAnimBlock);
  if ( AsyncInfoIndex == (FSAsyncControl_t__ **)NO_ASYNC )
    return 0;
  p_m_AsyncMutex = &this->m_AsyncMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncMutex->m_depth;
  }
  v9 = p_m_AsyncMutex->m_depth-- == 1;
  if ( v9 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
  if ( *AsyncInfoIndex != nullptr )
  {
    if ( bAbort )
    {
      g_pFullFileSystem->AsyncAbort(this: g_pFullFileSystem, a2: *AsyncInfoIndex);
      if ( g_pFullFileSystem->AsyncGetResult(this: g_pFullFileSystem, a2: *AsyncInfoIndex, a3: &pData, a4: &ignored) == FSASYNC_OK )
      {
        if ( type == MDLCACHE_ANIMBLOCK )
          FreeAnimBlock(p: (TSLNodeBase_t *)pData);
        else
          g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: pData);
      }
    }
    g_pFullFileSystem->AsyncRelease(this: g_pFullFileSystem, a2: *AsyncInfoIndex);
    *AsyncInfoIndex = nullptr;
  }
  SetAsyncInfoIndex(hModel: handle, type, iAnimBlock, index: NO_ASYNC);
  v10 = GetCurrentThreadId();
  if ( v10 != p_m_AsyncMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, v10, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncMutex, a2: v10, a3: 0);
  }
  else
  {
    ++p_m_AsyncMutex->m_depth;
  }
  CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::Free(
    this: &v13->m_PendingAsyncs,
    elem: (int)AsyncInfoIndex);
  v9 = p_m_AsyncMutex->m_depth-- == 1;
  if ( v9 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D7C0
// Name: private: void CMDLCache::ShutdownStudioData(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::ShutdownStudioData(CMDLCache *this, int handle, bool bImmediate)
{
  CTSQueue<studiodata_t *,0,1>::Node_t *v4; // eax
  studiodata_t *v5; // ebx
  studiodata_t *elem; // ebx
  studiodata_t *v7; // ebx
  studiodata_t **bImmediatea; // [esp+18h] [ebp+Ch]

  this->BeginLock(this);
  if ( bImmediate )
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
    if ( CMDLCache::ClearAsync(this, handle: elem->m_Handle, type: MDLCACHE_STUDIOHWDATA, iAnimBlock: 0, bAbort: true) != 0 )
      this->m_pMeshCacheSection->Unlock(this: this->m_pMeshCacheSection, a2: elem->m_VertexCache);
    CMDLCache::ClearAsync(this, handle: elem->m_Handle, type: MDLCACHE_VERTEXES, iAnimBlock: 0, bAbort: true);
    this->Flush(this, a2: handle, a3: -1);
    v7 = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
    if ( v7 != nullptr )
    {
      CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v7->m_vecAutoplaySequenceList);
      CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v7->m_vecFakeAnimBlockStall);
      CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v7->m_vecAnimBlocks);
      studiodata_t::operator delete(p: v7);
    }
  }
  else
  {
    bImmediatea = &this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
    v4 = (CTSQueue<studiodata_t *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_UnloadHandles.m_FreeNodes);
    if ( v4 != nullptr )
    {
      v4->elem = *bImmediatea;
    }
    else
    {
      v4 = (CTSQueue<studiodata_t *,0,1>::Node_t *)operator new(nSize: 8u);
      if ( v4 != nullptr )
        v4->elem = *bImmediatea;
      else
        v4 = nullptr;
    }
    CTSQueue<studiodata_t *,0,1>::Push(this: &this->m_UnloadHandles, pNode: v4);
    v5 = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
    if ( CMDLCache::ClearAsync(this, handle: v5->m_Handle, type: MDLCACHE_STUDIOHWDATA, iAnimBlock: 0, bAbort: true) != 0 )
      this->m_pMeshCacheSection->Unlock(this: this->m_pMeshCacheSection, a2: v5->m_VertexCache);
    CMDLCache::ClearAsync(this, handle: v5->m_Handle, type: MDLCACHE_VERTEXES, iAnimBlock: 0, bAbort: true);
  }
  this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem = nullptr;
  this->EndLock(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000D910
// Name: public: virtual int CMDLCache::Release(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLCache::Release(CMDLCache *this, int handle)
{
  UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  studiodata_t *elem; // eax
  int v6; // ebx

  if ( (*((_BYTE *)this + 160) & 4) == 0 )
    return 0;
  m_pMemory = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( m_pMemory[(unsigned __int16)handle].m_Data.elem == nullptr )
    return 0;
  elem = m_pMemory[(unsigned __int16)handle].m_Data.elem;
  v6 = --elem->m_nRefCount;
  if ( v6 <= 0 )
  {
    CMDLCache::ShutdownStudioData(this, handle, bImmediate: false);
    CUtlDict<studiodata_t *,unsigned short>::RemoveAt(this: &this->m_MDLDict, elem: handle);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1000D970
// Name: private: void CMDLCache::FreeAnimBlocks(struct studiodata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::FreeAnimBlocks(CMDLCache *this, TSLNodeBase_t *pStudioData)
{
  TSLNodeBase_t *v2; // edi
  int v3; // esi
  memhandle_t__ **v4; // eax
  memhandle_t__ *v5; // ebx
  IDataCacheSection *v6; // esi
  TSLNodeBase_t *Next; // ecx
  int i; // [esp+10h] [ebp-4h]

  v2 = pStudioData;
  v3 = 0;
  for ( i = 0; v3 < (int)v2[8].Next; i = v3 )
  {
    if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "MDLCache: Free Anim block: %d\n", v3);
    CMDLCache::ClearAsync(
      this,
      handle: (unsigned __int16)v2[17].Next,
      type: MDLCACHE_ANIMBLOCK,
      iAnimBlock: v3,
      bAbort: true);
    v4 = (memhandle_t__ **)(*((_DWORD *)&v2[6].Next + 1) + 4 * v3);
    if ( *v4 != nullptr )
    {
      v5 = *v4;
      v6 = this->GetCacheSection(this, a2: 3);
      if ( v6->IsPresent(this: v6, a2: v5) )
      {
        v6->BreakLock(this: v6, a2: v5);
        v6->Remove(this: v6, a2: v5, a3: (const void **)&pStudioData, a4: nullptr, a5: false);
        if ( (unsigned __int8 *)pStudioData < g_AnimBlockAllocator.m_pBase
          || (unsigned __int8 *)pStudioData >= g_AnimBlockAllocator.m_pLimit )
        {
          g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: pStudioData);
        }
        else
        {
          CTSListBase::Push(this: &g_AnimBlockAllocator.m_freeList, pNode: pStudioData);
        }
      }
      v3 = i;
    }
    ++v3;
  }
  v2[8].Next = nullptr;
  if ( *((int *)&v2[7].Next + 1) >= 0 )
  {
    if ( *((_DWORD *)&v2[6].Next + 1) != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)&v2[6].Next + 1));
      *((_DWORD *)&v2[6].Next + 1) = 0;
    }
    v2[7].Next = nullptr;
  }
  *((_DWORD *)&v2[8].Next + 1) = *((_DWORD *)&v2[6].Next + 1);
  *((_DWORD *)&v2[10].Next + 1) = 0;
  if ( (int)v2[10].Next < 0 )
  {
    v2[11].Next = v2[9].Next;
  }
  else
  {
    if ( v2[9].Next != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2[9].Next);
      v2[9].Next = nullptr;
    }
    Next = v2[9].Next;
    *((_DWORD *)&v2[9].Next + 1) = 0;
    v2[11].Next = Next;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DAC0
// Name: public: virtualmodel_t::virtualmodel_t(void)
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall virtualmodel_t::virtualmodel_t(virtualmodel_t *this)
{
  this->m_Lock.m_ownerID = 0;
  this->m_Lock.m_depth = 0;
  this->m_seq.m_Memory.m_pMemory = nullptr;
  this->m_seq.m_Memory.m_nAllocationCount = 0;
  this->m_seq.m_Memory.m_nGrowSize = 0;
  this->m_seq.m_Size = 0;
  this->m_seq.m_pElements = nullptr;
  this->m_anim.m_Memory.m_pMemory = nullptr;
  this->m_anim.m_Memory.m_nAllocationCount = 0;
  this->m_anim.m_Memory.m_nGrowSize = 0;
  this->m_anim.m_Size = 0;
  this->m_anim.m_pElements = nullptr;
  this->m_attachment.m_Memory.m_pMemory = nullptr;
  this->m_attachment.m_Memory.m_nAllocationCount = 0;
  this->m_attachment.m_Memory.m_nGrowSize = 0;
  this->m_attachment.m_Size = 0;
  this->m_attachment.m_pElements = nullptr;
  this->m_pose.m_Memory.m_pMemory = nullptr;
  this->m_pose.m_Memory.m_nAllocationCount = 0;
  this->m_pose.m_Memory.m_nGrowSize = 0;
  this->m_pose.m_Size = 0;
  this->m_pose.m_pElements = nullptr;
  this->m_group.m_Memory.m_pMemory = nullptr;
  this->m_group.m_Memory.m_nAllocationCount = 0;
  this->m_group.m_Memory.m_nGrowSize = 0;
  this->m_group.m_Size = 0;
  this->m_group.m_pElements = nullptr;
  this->m_node.m_Memory.m_pMemory = nullptr;
  this->m_node.m_Memory.m_nAllocationCount = 0;
  this->m_node.m_Memory.m_nGrowSize = 0;
  this->m_node.m_Size = 0;
  this->m_node.m_pElements = nullptr;
  this->m_iklock.m_Memory.m_pMemory = nullptr;
  this->m_iklock.m_Memory.m_nAllocationCount = 0;
  this->m_iklock.m_Memory.m_nGrowSize = 0;
  this->m_iklock.m_Size = 0;
  this->m_iklock.m_pElements = nullptr;
  this->m_autoplaySequences.m_Memory.m_pMemory = nullptr;
  this->m_autoplaySequences.m_Memory.m_nAllocationCount = 0;
  this->m_autoplaySequences.m_Memory.m_nGrowSize = 0;
  this->m_autoplaySequences.m_Size = 0;
  this->m_autoplaySequences.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000DB60
// Name: public: void CMDLCache::RestoreMaterialSystemObjects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::RestoreMaterialSystemObjects(CMDLCache *this, char nChangeFlags)
{
  IDataCacheSection *m_pMeshCacheSection; // ecx
  IDataCacheSection *v4; // ecx
  IDataCacheSection *m_pAnimBlocksCacheSection; // ecx
  unsigned __int16 Inorder; // ax
  int v7; // edi
  studiodata_t *elem; // ebx
  IDataCacheSection *v9; // eax
  ConVar *m_pParent; // eax
  unsigned __int16 v11; // ax
  bool bIsMDLInMemory_3; // [esp+17h] [ebp+Bh]

  m_pMeshCacheSection = this->m_pMeshCacheSection;
  *((_BYTE *)this + 160) &= ~1u;
  if ( m_pMeshCacheSection->IsFrameLocking(this: m_pMeshCacheSection) )
  {
    this->m_nMeshCacheFrameLocks = 0;
    do
    {
      v4 = this->m_pMeshCacheSection;
      ++this->m_nMeshCacheFrameLocks;
    }
    while ( v4->EndFrameLocking(this: v4) != 0 );
  }
  if ( this->m_pAnimBlocksCacheSection->IsFrameLocking(this: this->m_pAnimBlocksCacheSection) )
  {
    this->m_nAnimBlockCacheFrameLocks = 0;
    do
    {
      m_pAnimBlocksCacheSection = this->m_pAnimBlocksCacheSection;
      ++this->m_nAnimBlockCacheFrameLocks;
    }
    while ( m_pAnimBlocksCacheSection->EndFrameLocking(this: m_pAnimBlocksCacheSection) != 0 );
  }
  Inorder = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MDLDict.m_Elements.m_Tree);
  v7 = Inorder;
  if ( Inorder != 0xFFFF )
  {
    do
    {
      elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v7].m_Data.elem;
      v9 = this->GetCacheSection(this, a2: 0);
      bIsMDLInMemory_3 = v9->IsPresent(this: v9, a2: elem->m_MDLCache);
      if ( (nChangeFlags & 1) != 0 )
      {
        m_pParent = mod_trace_load.m_pParent;
        if ( mod_trace_load.m_pParent != nullptr )
        {
          if ( mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
          {
            _Msg(a1: "MDLCache: Free studiohdr\n");
            m_pParent = mod_trace_load.m_pParent;
          }
          if ( m_pParent != nullptr )
          {
            if ( m_pParent->m_Value.m_nValue != 0 )
            {
              _Msg(a1: "MDLCache: Free VVD\n");
              m_pParent = mod_trace_load.m_pParent;
            }
            if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
              _Msg(a1: "MDLCache: Free VTX\n");
          }
        }
        CMDLCache::ClearAsync(this, handle: v7, type: MDLCACHE_STUDIOHWDATA, iAnimBlock: 0, bAbort: true);
        this->Flush(this, a2: v7, a3: 64);
      }
      if ( bIsMDLInMemory_3 )
        this->GetHardwareData(this, a2: v7);
      v11 = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_MDLDict.m_Elements.m_Tree,
              i: v7);
      v7 = v11;
    }
    while ( v11 != 0xFFFF );
  }
  CMDLCache::RestoreFrameLock(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000DCC0
// Name: private: int CMDLCache::ProcessPendingAsync(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLCache::ProcessPendingAsync(CMDLCache *this, int iAsync)
{
  CThreadFastMutex *p_m_AsyncMutex; // esi
  DWORD CurrentThreadId; // ecx
  FSAsyncStatus_t v6; // ebx
  int result; // eax
  __int64 v8; // xmm0_8
  CMDLCache *v9; // edi
  CUtlBuffer pDataBuffer; // [esp+8h] [ebp-9Ch] BYREF
  CUtlBuffer buf; // [esp+38h] [ebp-6Ch] BYREF
  CMDLCacheData cacheData; // [esp+68h] [ebp-3Ch] BYREF
  CMDLCacheData v13; // [esp+78h] [ebp-2Ch] BYREF
  CMDLCache *v14; // [esp+88h] [ebp-1Ch]
  AsyncInfo_t info; // [esp+8Ch] [ebp-18h]
  void *pData; // [esp+9Ch] [ebp-8h] BYREF
  int nBytesRead; // [esp+A0h] [ebp-4h] BYREF

  v14 = this;
  if ( (unsigned __int8)_ThreadInMainThread() == 0 || iAsync == NO_ASYNC )
    return -1;
  pData = nullptr;
  nBytesRead = 0;
  p_m_AsyncMutex = &this->m_AsyncMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncMutex->m_depth;
  }
  if ( p_m_AsyncMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
  v6 = g_pFullFileSystem->AsyncGetResult(
         this: g_pFullFileSystem,
         a2: *(FSAsyncControl_t__ **)iAsync,
         a3: &pData,
         a4: &nBytesRead);
  if ( v6 == FSASYNC_STATUS_PENDING )
    return 0;
  *(_QWORD *)&info.hControl = *(_QWORD *)iAsync;
  v8 = *(_QWORD *)(iAsync + 8);
  v9 = v14;
  *(_QWORD *)&info.type = v8;
  CMDLCache::ClearAsync(
    this: v14,
    handle: info.hModel,
    type: (MDLCacheDataType_t)v8,
    iAnimBlock: SHIDWORD(v8),
    bAbort: false);
  switch ( (int)v8 )
  {
    case 1:
    case 2:
    case 5:
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: pData, nSize: nBytesRead, nFlags: 8);
      CMDLCacheData::CMDLCacheData(
        this: &cacheData,
        dataType: (MDLCacheDataType_t)v8,
        allocType: ALLOC_OPTIMALREADBUFFER,
        pDataBuffer: &buf);
      if ( v6 != FSASYNC_OK )
        CMDLCacheData::Purge(this: &cacheData);
      CMDLCache::ProcessDataIntoCache(this: v9, handle: info.hModel, &cacheData, iAnimBlock: 0);
      CMDLCacheData::Purge(this: &cacheData);
      CUtlBuffer::~CUtlBuffer(this: &buf);
      result = 1;
      break;
    case 3:
      CUtlBuffer::CUtlBuffer(this: &pDataBuffer, pBuffer: pData, nSize: nBytesRead, nFlags: 8);
      CMDLCacheData::CMDLCacheData(
        this: &v13,
        dataType: (MDLCacheDataType_t)v8,
        allocType: ALLOC_ANIMBLOCK,
        &pDataBuffer);
      if ( v6 != FSASYNC_OK )
        CMDLCacheData::Purge(this: &v13);
      CMDLCache::ProcessDataIntoCache(this: v9, handle: info.hModel, cacheData: &v13, iAnimBlock: info.iAnimBlock);
      CMDLCacheData::Purge(this: &v13);
      CUtlBuffer::~CUtlBuffer(this: &pDataBuffer);
      goto LABEL_18;
    default:
LABEL_18:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE80
// Name: private: void CMDLCache::ProcessPendingAsyncs(enum MDLCacheDataType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::ProcessPendingAsyncs(CMDLCache *this, MDLCacheDataType_t type)
{
  CThreadFastMutex *p_m_AsyncMutex; // edi
  DWORD CurrentThreadId; // ecx
  int m_Head; // eax
  int v6; // esi

  if ( (unsigned __int8)_ThreadInMainThread() != 0 && this->m_PendingAsyncs.m_ElementCount != 0 && !bReentering )
  {
    bReentering = true;
    p_m_AsyncMutex = &this->m_AsyncMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_AsyncMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_AsyncMutex.m_depth;
    }
    m_Head = this->m_PendingAsyncs.m_Head;
    if ( m_Head != 0 )
    {
      do
      {
        v6 = *(_DWORD *)(m_Head + 20);
        if ( (type == MDLCACHE_NONE || *(_DWORD *)(m_Head + 8) == type)
          && CMDLCache::ProcessPendingAsync(this, iAsync: m_Head) <= 0 )
        {
          break;
        }
        m_Head = v6;
      }
      while ( v6 != 0 );
    }
    bReentering = false;
    if ( p_m_AsyncMutex->m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DF30
// Name: private: struct vertexFileHeader_t __near * CMDLCache::LoadVertexData(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
vertexFileHeader_t *__thiscall CMDLCache::LoadVertexData(CMDLCache *this, studiohdr_t *pStudioHdr)
{
  unsigned __int16 virtualModel; // bx
  int v4; // esi
  bool v5; // zf
  int AsyncInfoIndex; // eax
  int m_nValue; // eax
  CThreadFastMutex *p_m_AsyncMutex; // esi
  DWORD CurrentThreadId; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *v11; // eax
  AsyncInfo_t *v12; // ebx
  IDataCacheSection *v13; // eax
  char *v14; // ebx
  memhandle_t__ *m_VertexCache; // esi
  IDataCacheSection *v16; // eax
  char pFileName[260]; // [esp+Ch] [ebp-11Ch] BYREF
  int handle; // [esp+110h] [ebp-18h]
  AsyncInfo_t info; // [esp+114h] [ebp-14h] BYREF
  int v20; // [esp+124h] [ebp-4h]

  virtualModel = (unsigned __int16)pStudioHdr->virtualModel;
  v4 = 16 * virtualModel;
  v5 = ((*(studiodata_t **)((char *)&this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem + v4))->m_nFlags
      & 0x10) == 0;
  handle = virtualModel;
  v20 = v4;
  if ( !v5 )
    return nullptr;
  AsyncInfoIndex = GetAsyncInfoIndex(hModel: virtualModel, type: MDLCACHE_VERTEXES, iAnimBlock: 0);
  if ( AsyncInfoIndex == NO_ASYNC )
  {
    MakeFilename(szFileName: pFileName, pStudioHdr, pszExtension: ".vvd");
    if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "MDLCache: Begin load VVD %s\n", pFileName);
    info.hModel = virtualModel;
    info.type = MDLCACHE_VERTEXES;
    info.iAnimBlock = 0;
    info.hControl = nullptr;
    if ( mod_load_mesh_async.m_pParent != nullptr )
      m_nValue = mod_load_mesh_async.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    CMDLCache::LoadData(
      this,
      pszFilename: pFileName,
      pszPathID: "GAME",
      bAsync: m_nValue != 0,
      pControl: &info.hControl);
    p_m_AsyncMutex = &this->m_AsyncMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_AsyncMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_AsyncMutex.m_depth;
    }
    v11 = CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AllocInternal(
            this: &this->m_PendingAsyncs,
            multilist: false);
    v12 = (AsyncInfo_t *)v11;
    if ( v11 != nullptr )
    {
      CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::LinkBefore(
        this: &this->m_PendingAsyncs,
        before: 0,
        elem: (int)v11);
      *v12 = info;
    }
    AsyncInfoIndex = SetAsyncInfoIndex(hModel: handle, type: MDLCACHE_VERTEXES, iAnimBlock: 0, index: (int)v12);
    v5 = this->m_AsyncMutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
    v4 = v20;
  }
  CMDLCache::ProcessPendingAsync(this, iAsync: AsyncInfoIndex);
  if ( (mod_load_mesh_async.m_pParent == nullptr || mod_load_mesh_async.m_pParent->m_Value.m_nValue == 0)
    && mod_lock_meshes_on_load.m_pParent != nullptr
    && mod_lock_meshes_on_load.m_pParent->m_Value.m_nValue != 0 )
  {
    v13 = this->GetCacheSection(this, a2: 5);
    v14 = (char *)&this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem + v4;
    *(_DWORD *)(*(_DWORD *)v14 + 120) = v13->Lock(this: v13, a2: *(memhandle_t__ **)(*(_DWORD *)v14 + 92));
  }
  m_VertexCache = (*(studiodata_t **)((char *)&this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem + v4))->m_VertexCache;
  v16 = this->GetCacheSection(this, a2: 5);
  return (vertexFileHeader_t *)v16->Get(this: v16, a2: m_VertexCache, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000E100
// Name: public: virtual void CMDLCache::MarkFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::MarkFrame(CMDLCache *this)
{
  CMDLCache::ProcessPendingAsyncs(this, type: MDLCACHE_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x1000E110
// Name: public: CUtlHash<struct CModelSwapper::ModelSubstitution_t,bool (*)(struct CModelSwapper::ModelSubstitution_t const __near &,struct CModelSwapper::ModelSubstitution_t const __near &),unsigned int (*)(struct CModelSwapper::ModelSubstitution_t const __near &)>::CUtlHash<struct CModelSwapper::ModelSubstitution_t,bool (*)(struct CModelSwapper::ModelSubstitution_t const __near &,struct CModelSwapper::ModelSubstitution_t const __near &),unsigned int (*)(struct CModelSwapper::ModelSubstitution_t const __near &)>(int,int,int,bool (*)(struct CModelSwapper::ModelSubstitution_t const __near &,struct CModelSwapper::ModelSubstitution_t const __near &),unsigned int (*)(struct CModelSwapper::ModelSubstitution_t const __near &))
// Source: json
//------------------------------------------------------------------------------
CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl*)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl*)(CModelSwapper::ModelSubstitution_t const &)> *__thiscall CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>::CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>(
        CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl*)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl*)(CModelSwapper::ModelSubstitution_t const &)> *this,
        int bucketCount,
        int growCount,
        int initCount,
        bool (__cdecl *compareFunc)(const CModelSwapper::ModelSubstitution_t *, const CModelSwapper::ModelSubstitution_t *),
        unsigned int (__cdecl *keyFunc)(const CModelSwapper::ModelSubstitution_t *))
{
  int v7; // esi
  int v8; // eax
  CUtlMemory<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // ecx
  int v12; // eax
  bool v13; // zf
  bool (__cdecl *compareFunca)(const CModelSwapper::ModelSubstitution_t *, const CModelSwapper::ModelSubstitution_t *); // [esp+20h] [ebp+14h]
  unsigned int (__cdecl *keyFunca)(const CModelSwapper::ModelSubstitution_t *); // [esp+24h] [ebp+18h]

  v7 = bucketCount;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  this->m_CompareFunc = compareFunc;
  this->m_KeyFunc = keyFunc;
  if ( bucketCount >= 0x10000 )
  {
    bucketCount = 0x10000;
    v7 = 0x10000;
  }
  CUtlVector<CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>,CUtlMemory<CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>,int>>::RemoveAll(this: &this->m_Buckets);
  CUtlVector<CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>,CUtlMemory<CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>,int>>::InsertMultipleBefore(
    this: &this->m_Buckets,
    elem: this->m_Buckets.m_Size,
    num: v7);
  if ( v7 > 0 )
  {
    v8 = 0;
    compareFunca = nullptr;
    keyFunca = (unsigned int (__cdecl *)(const CModelSwapper::ModelSubstitution_t *))v7;
    do
    {
      v9 = (CUtlMemory<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t,int> *)((char *)this->m_Buckets.m_Memory.m_pMemory + v8);
      v9[1].m_pMemory = nullptr;
      if ( initCount != 0 )
      {
        m_nAllocationCount = v9->m_nAllocationCount;
        if ( initCount > m_nAllocationCount )
          CUtlMemory<CModelSwapper::ModelSubstitution_t,int>::Grow(this: v9, num: initCount - m_nAllocationCount);
        v9[1].m_pMemory = (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *)((char *)v9[1].m_pMemory + initCount);
        m_pMemory = v9->m_pMemory;
        v12 = (int)v9[1].m_pMemory - initCount;
        v9[1].m_nAllocationCount = (int)v9->m_pMemory;
        if ( v12 > 0 && initCount > 0 )
          _V_memmove(dest: &m_pMemory[initCount], src: m_pMemory, count: 12 * v12);
      }
      *(_DWORD *)((char *)compareFunca + (unsigned int)this->m_Buckets.m_Memory.m_pMemory + 8) = growCount;
      v8 = (int)compareFunca + 20;
      v13 = keyFunca == (unsigned int (__cdecl *)(const CModelSwapper::ModelSubstitution_t *))1;
      keyFunca = (unsigned int (__cdecl *)(const CModelSwapper::ModelSubstitution_t *))((char *)keyFunca - 1);
      compareFunca = (bool (__cdecl *)(const CModelSwapper::ModelSubstitution_t *, const CModelSwapper::ModelSubstitution_t *))((char *)compareFunca + 20);
    }
    while ( !v13 );
    v7 = bucketCount;
  }
  this->m_bPowerOfTwo = ((v7 - 1) & v7) == 0;
  this->m_ModMask = ((v7 - 1) & v7) == 0 ? v7 - 1 : 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E200
// Name: public: CModelSwapper::CModelSwapper(void)
// Source: json
//------------------------------------------------------------------------------
CModelSwapper *__thiscall CModelSwapper::CModelSwapper(CModelSwapper *this)
{
  unsigned int v1; // edi
  int v3; // eax

  v1 = 0;
  this->m_Strings.m_Memory.m_pMemory = nullptr;
  this->m_Strings.m_Memory.m_nAllocationCount = 0;
  this->m_Strings.m_Memory.m_nGrowSize = 0;
  this->m_Strings.m_Size = 0;
  this->m_Strings.m_pElements = nullptr;
  CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>::CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>(
    this: &this->m_ModelLookup,
    bucketCount: 256,
    growCount: 0,
    initCount: 0,
    compareFunc: (bool (__cdecl *)(const CModelSwapper::ModelSubstitution_t *, const CModelSwapper::ModelSubstitution_t *))CModelSwapper::ModelSubstitution_t::AreEqual,
    keyFunc: CModelSwapper::ModelSubstitution_t::Hash);
  this->m_nMaxExtensionLength = 0;
  do
  {
    v3 = _V_strlen(str: s_ModelSwapperExtensions[v1]);
    if ( this->m_nMaxExtensionLength < v3 )
      this->m_nMaxExtensionLength = v3;
    ++v1;
  }
  while ( v1 < 4 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E260
// Name: public: virtual CMDLCache::~CMDLCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::~CMDLCache(CMDLCache *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CModelSwapper::Cleanup(this: &this->m_ModelSwapper);
  CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>::Purge(this: &this->m_ModelSwapper.m_ModelLookup);
  CUtlVector<CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>,CUtlMemory<CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>,int>>::~CUtlVector<CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>,CUtlMemory<CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int>>,int>>(this: &this->m_ModelSwapper.m_ModelLookup.m_Buckets);
  CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ModelSwapper);
  CTSQueue<studiodata_t *,0,1>::Purge(this: &this->m_UnloadHandles);
  free(pMem: this->m_UnloadHandles.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_UnloadHandles.m_FreeNodes);
  CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::RemoveAll(this: &this->m_PendingAsyncs);
  m_pBlocks = this->m_PendingAsyncs.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_PendingAsyncs.m_Memory.m_pBlocks = nullptr;
    this->m_PendingAsyncs.m_Memory.m_nAllocationCount = 0;
  }
  CUtlDict<studiodata_t *,unsigned short>::RemoveAll(this: &this->m_MDLDict);
  CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_MDLDict.m_Elements.m_Tree);
  this->CDefaultDataCacheClient::IDataCacheClient::__vftable = (CDefaultDataCacheClient_vtbl *)&IDataCacheClient::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1000E300
// Name: RestoreMaterialSystemObjects
// Source: json
//------------------------------------------------------------------------------
void __cdecl RestoreMaterialSystemObjects(char nChangeFlags)
{
  CMDLCache::RestoreMaterialSystemObjects(this: &g_MDLCache, nChangeFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1000E320
// Name: public: CMDLCache::CMDLCache(void)
// Source: json
//------------------------------------------------------------------------------
CMDLCache *__thiscall CMDLCache::CMDLCache(CMDLCache *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx

  this->IStudioDataCache::IAppSystem::__vftable = (IStudioDataCache_vtbl *)&IStudioDataCache::`vftable';
  this->CDefaultDataCacheClient::IDataCacheClient::__vftable = (CDefaultDataCacheClient_vtbl *)&CDefaultDataCacheClient::`vftable';
  this->CTier3AppSystem<IMDLCache,0>::CTier2AppSystem<IMDLCache,0>::CTier1AppSystem<IMDLCache,0>::CTier0AppSystem<IMDLCache>::CBaseAppSystem<IMDLCache>::IMDLCache::IAppSystem::__vftable = (CMDLCache_vtbl *)&CMDLCache::`vftable'{for `CTier3AppSystem<IMDLCache,0>'};
  this->IStudioDataCache::IAppSystem::__vftable = (IStudioDataCache_vtbl *)&CMDLCache::`vftable'{for `IStudioDataCache'};
  this->CDefaultDataCacheClient::IDataCacheClient::__vftable = (CDefaultDataCacheClient_vtbl *)&CMDLCache::`vftable'{for `CDefaultDataCacheClient'};
  this->m_MDLDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_MDLDict.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_MDLDict.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_MDLDict.m_Elements.m_Tree.m_pElements = m_pMemory;
  if ( this->m_MDLDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_MDLDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_PendingAsyncs.m_Memory.m_pBlocks = nullptr;
  this->m_PendingAsyncs.m_Memory.m_nAllocationCount = 0;
  this->m_PendingAsyncs.m_Memory.m_nGrowSize = 0;
  this->m_PendingAsyncs.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_PendingAsyncs.m_LastAlloc.m_nIndex = -1;
  this->m_PendingAsyncs.m_Head = 0;
  this->m_PendingAsyncs.m_Tail = 0;
  this->m_PendingAsyncs.m_FirstFree = 0;
  this->m_PendingAsyncs.m_ElementCount = 0;
  this->m_PendingAsyncs.m_NumAlloced = 0;
  this->m_PendingAsyncs.m_pElements = nullptr;
  this->m_QueuedLoadingMutex.m_ownerID = 0;
  this->m_QueuedLoadingMutex.m_depth = 0;
  this->m_AsyncMutex.m_ownerID = 0;
  this->m_AsyncMutex.m_depth = 0;
  CTSQueue<studiodata_t *,0,1>::CTSQueue<studiodata_t *,0,1>(this: &this->m_UnloadHandles);
  CModelSwapper::CModelSwapper(this: &this->m_ModelSwapper);
  *((_BYTE *)this + 160) &= 0xF8u;
  this->m_pCacheNotify = nullptr;
  this->m_pModelCacheSection = nullptr;
  this->m_pMeshCacheSection = nullptr;
  this->m_pAnimBlocksCacheSection = nullptr;
  this->m_nModelCacheFrameLocks = 0;
  this->m_nMeshCacheFrameLocks = 0;
  this->m_nAnimBlockCacheFrameLocks = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E3E0
// Name: public: virtual struct vcollide_t __near * CMDLCache::GetVCollide(unsigned short)
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__thiscall CMDLCache::GetVCollide(CMDLCache *this, int handle)
{
  return this->GetVCollideEx(this, a2: handle, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000E490
// Name: public: virtual void CMDLCache::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::Shutdown(CMDLCache *this)
{
  char v2; // al
  bool v3; // zf
  unsigned __int16 Inorder; // ax
  int v5; // esi
  unsigned __int16 v6; // ax

  v2 = *((_BYTE *)this + 160);
  if ( (v2 & 4) != 0 )
  {
    v3 = this->m_pModelCacheSection == nullptr;
    *((_BYTE *)this + 160) = v2 & 0xFB;
    if ( !v3 || this->m_pMeshCacheSection != nullptr )
    {
      Inorder = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MDLDict.m_Elements.m_Tree);
      v5 = Inorder;
      if ( Inorder != 0xFFFF )
      {
        do
        {
          CMDLCache::ShutdownStudioData(this, handle: v5, bImmediate: true);
          v6 = CUtlRBTree<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,studiodata_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                 this: &this->m_MDLDict.m_Elements.m_Tree,
                 i: v5);
          v5 = v6;
        }
        while ( v6 != 0xFFFF );
      }
      CUtlDict<studiodata_t *,unsigned short>::RemoveAll(this: &this->m_MDLDict);
      if ( this->m_pModelCacheSection != nullptr )
      {
        g_pDataCache->RemoveSection(this: g_pDataCache, a2: "ModelData", a3: true);
        this->m_pModelCacheSection = nullptr;
      }
      if ( this->m_pMeshCacheSection != nullptr )
      {
        g_pDataCache->RemoveSection(this: g_pDataCache, a2: "ModelMesh", a3: true);
        this->m_pMeshCacheSection = nullptr;
      }
    }
    if ( this->m_pAnimBlocksCacheSection != nullptr )
    {
      g_pDataCache->RemoveSection(this: g_pDataCache, a2: "AnimBlock", a3: true);
      this->m_pAnimBlocksCacheSection = nullptr;
    }
    if ( g_pCVar != nullptr )
      ConVar_Unregister();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E570
// Name: private: void CMDLCache::UnserializeVCollide(unsigned short,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::UnserializeVCollide(CMDLCache *this, int handle, bool bUseAsync, bool synchronousLoad)
{
  int v5; // edi
  studiodata_t *v6; // esi
  virtualmodel_t *v7; // esi
  studiodata_t *elem; // edi
  const char *v9; // eax
  CStudioVCollide *m_pVCollide; // ecx
  studiodata_t *v11; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  bool v13; // cl
  const char *v14; // edi
  const char *v15; // eax
  DWORD v16; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *v17; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *m_pNext; // eax
  int m_nBlockSize; // eax
  int m_Tail; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t v21; // xmm0_8
  bool v22; // zf
  CThreadFastMutex *p_m_AsyncMutex; // esi
  DWORD CurrentThreadId; // ecx
  char pFileName[260]; // [esp+Ch] [ebp-124h] BYREF
  studiodata_t *pStudioData; // [esp+110h] [ebp-20h]
  int v27; // [esp+114h] [ebp-1Ch]
  AsyncInfo_t info; // [esp+118h] [ebp-18h] BYREF
  int i; // [esp+128h] [ebp-8h]
  int iAsync; // [esp+12Ch] [ebp-4h]
  bool bAsyncLoad; // [esp+140h] [ebp+10h]

  v5 = 16 * (unsigned __int16)handle;
  v6 = *(studiodata_t **)((char *)&this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem + v5);
  v27 = v5;
  pStudioData = v6;
  iAsync = GetAsyncInfoIndex(hModel: handle, type: MDLCACHE_VCOLLIDE, iAnimBlock: 0);
  if ( iAsync != NO_ASYNC )
  {
    if ( synchronousLoad )
    {
      p_m_AsyncMutex = &this->m_AsyncMutex;
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != this->m_AsyncMutex.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++this->m_AsyncMutex.m_depth;
      }
      v22 = this->m_AsyncMutex.m_depth-- == 1;
      if ( v22 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
      if ( *(_DWORD *)iAsync != 0 )
        g_pFullFileSystem->AsyncFinish(this: g_pFullFileSystem, a2: *(FSAsyncControl_t__ **)iAsync, a3: true);
    }
LABEL_54:
    CMDLCache::ProcessPendingAsync(this, iAsync);
    return;
  }
  v6->m_nFlags = v6->m_nFlags & 0xFF7D | 0x80;
  v6->m_pVCollide = nullptr;
  v7 = this->GetVirtualModel(this, a2: handle);
  if ( v7 == nullptr || (i = 1, v7->m_group.m_Size <= 1) )
  {
LABEL_10:
    if ( (_WORD)handle == 0xFFFF )
    {
      v9 = "models/error.mdl";
    }
    else
    {
      m_pMemory = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory;
      if ( ((*(studiodata_t **)((char *)&m_pMemory->m_Data.elem + v5))->m_nFlags & 4) != 0 )
        v9 = "models/error.mdl";
      else
        v9 = *(const char **)((char *)&m_pMemory->m_Data.key + v5);
    }
    V_strncpy(pDest: pFileName, pSrc: v9, maxLen: 260);
    V_SetExtension(path: pFileName, extension: ".phy", pathStringLength: 260);
    V_FixSlashes(pname: pFileName, separator: 92);
    v13 = bUseAsync && !synchronousLoad;
    bAsyncLoad = v13;
    if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
    {
      v14 = "Async";
      if ( !v13 )
        v14 = "Sync";
      v15 = this->GetModelName(this, a2: handle);
      _Msg(a1: "MDLCache: %s load vcollide %s\n", v14, v15);
    }
    info.hModel = handle;
    info.type = MDLCACHE_VCOLLIDE;
    info.iAnimBlock = 0;
    info.hControl = nullptr;
    CMDLCache::LoadData(this, pszFilename: pFileName, pszPathID: "GAME", bAsync: bAsyncLoad, pControl: &info.hControl);
    v16 = GetCurrentThreadId();
    if ( v16 != this->m_AsyncMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_AsyncMutex, v16, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: v16, a3: 0);
    }
    else
    {
      ++this->m_AsyncMutex.m_depth;
    }
    v17 = CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AllocInternal(
            this: &this->m_PendingAsyncs,
            multilist: false);
    if ( v17 != nullptr )
    {
      if ( !CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>::IsIdxAfter(
              this: &this->m_PendingAsyncs.m_Memory,
              i: (unsigned int)v17,
              it: &this->m_PendingAsyncs.m_LastAlloc) )
      {
        m_pNext = v17[2].m_pNext;
        if ( m_pNext != v17 )
        {
          if ( m_pNext != nullptr )
            m_pNext[2].m_nBlockSize = v17[2].m_nBlockSize;
          else
            this->m_PendingAsyncs.m_Head = v17[2].m_nBlockSize;
          m_nBlockSize = v17[2].m_nBlockSize;
          if ( m_nBlockSize != 0 )
            *(_DWORD *)(m_nBlockSize + 16) = v17[2].m_pNext;
          else
            this->m_PendingAsyncs.m_Tail = (int)v17[2].m_pNext;
          v17[2].m_nBlockSize = (int)v17;
          v17[2].m_pNext = v17;
          --this->m_PendingAsyncs.m_ElementCount;
        }
      }
      v17[2].m_nBlockSize = 0;
      m_Tail = this->m_PendingAsyncs.m_Tail;
      v17[2].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)m_Tail;
      this->m_PendingAsyncs.m_Tail = (int)v17;
      if ( m_Tail != 0 )
        *(_DWORD *)(m_Tail + 20) = v17;
      else
        this->m_PendingAsyncs.m_Head = (int)v17;
      v21 = *(CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)&info.hControl;
      ++this->m_PendingAsyncs.m_ElementCount;
      *v17 = v21;
      v17[1] = *(CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *)&info.type;
    }
    iAsync = SetAsyncInfoIndex(hModel: handle, type: MDLCACHE_VCOLLIDE, iAnimBlock: 0, index: (int)v17);
    v22 = this->m_AsyncMutex.m_depth-- == 1;
    if ( v22 )
    {
      _InterlockedExchange((volatile __int32 *)&this->m_AsyncMutex, 0);
      CMDLCache::ProcessPendingAsync(this, iAsync);
      return;
    }
    goto LABEL_54;
  }
  iAsync = 144;
  while ( 1 )
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[*(unsigned __int16 *)((char *)&v7->m_group.m_Memory.m_pMemory->cache
                                                                                      + iAsync)].m_Data.elem;
    if ( (elem->m_nFlags & 2) == 0 )
      CMDLCache::UnserializeVCollide(
        this,
        handle: *(_WORD *)((char *)&v7->m_group.m_Memory.m_pMemory->cache + iAsync),
        bUseAsync,
        synchronousLoad);
    if ( elem->m_pVCollide != nullptr )
      break;
    iAsync += 144;
    if ( ++i >= v7->m_group.m_Size )
    {
      v5 = v27;
      goto LABEL_10;
    }
  }
  _InterlockedExchangeAdd(&elem->m_pVCollide->m_iRefs, 1u);
  m_pVCollide = elem->m_pVCollide;
  v11 = pStudioData;
  pStudioData->m_nFlags |= 2u;
  v11->m_pVCollide = m_pVCollide;
}

//------------------------------------------------------------------------------
// Address: 0x1000E8B0
// Name: public: virtual struct vcollide_t __near * CMDLCache::GetVCollideEx(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__thiscall CMDLCache::GetVCollideEx(CMDLCache *this, int handle, bool synchronousLoad)
{
  studiodata_t *elem; // ebx
  int m_nValue; // eax
  unsigned __int16 m_nFlags; // ax
  bool v8; // zf
  virtualmodel_t *v9; // eax
  int m_Size; // edi
  int v11; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *m_pMemory; // esi
  virtualgroup_t *v13; // eax
  studiodata_t *v14; // ecx
  CStudioVCollide *m_pVCollide; // eax

  if ( mod_test_not_available.m_pParent != nullptr && mod_test_not_available.m_pParent->m_Value.m_nValue != 0 )
    return nullptr;
  if ( (_WORD)handle != 0xFFFF )
  {
    elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
    if ( (elem->m_nFlags & 2) == 0 )
    {
      if ( mod_load_vcollide_async.m_pParent != nullptr )
        m_nValue = mod_load_vcollide_async.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      CMDLCache::UnserializeVCollide(this, handle, bUseAsync: m_nValue != 0, synchronousLoad);
    }
    m_nFlags = elem->m_nFlags;
    if ( (m_nFlags & 0x80u) == 0 )
    {
      v8 = elem->m_pVCollide == nullptr;
      elem->m_nFlags = m_nFlags | 0x80;
      if ( v8 )
      {
        v9 = this->GetVirtualModel(this, a2: handle);
        if ( v9 != nullptr )
        {
          m_Size = v9->m_group.m_Size;
          v11 = 1;
          if ( m_Size > 1 )
          {
            m_pMemory = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory;
            v13 = v9->m_group.m_Memory.m_pMemory + 1;
            while ( 1 )
            {
              v14 = m_pMemory[LOWORD(v13->cache)].m_Data.elem;
              if ( v14->m_pVCollide != nullptr )
                break;
              ++v11;
              ++v13;
              if ( v11 >= m_Size )
                goto LABEL_19;
            }
            elem->m_pVCollide = v14->m_pVCollide;
            _InterlockedExchangeAdd(&v14->m_pVCollide->m_iRefs, 1u);
          }
        }
      }
    }
LABEL_19:
    m_pVCollide = elem->m_pVCollide;
    if ( m_pVCollide != nullptr )
      return &m_pVCollide->m_vcollide;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000E9A0
// Name: private: unsigned char __near * CMDLCache::UnserializeAnimBlock(unsigned short,bool,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMDLCache::UnserializeAnimBlock(CMDLCache *this, int handle, bool bUseAsync, int nBlock)
{
  int AsyncInfoIndex; // eax
  studiohdr_t *v7; // eax
  int v8; // ecx
  int v9; // ebx
  mstudioanimblock_t *v10; // ecx
  const char *v11; // edx
  int v12; // ebx
  const char *v14; // eax
  void *v15; // eax
  char *v16; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *v17; // eax
  memhandle_t__ *v18; // edi
  IDataCacheSection *v19; // eax
  char pFileName[260]; // [esp+Ch] [ebp-120h] BYREF
  AsyncInfo_t info; // [esp+110h] [ebp-1Ch] BYREF
  void *pData; // [esp+120h] [ebp-Ch]
  mstudioanimblock_t *pBlock; // [esp+124h] [ebp-8h]
  studiodata_t *pStudioData; // [esp+128h] [ebp-4h]
  studiohdr_t *pStudioHdr; // [esp+13Ch] [ebp+10h]

  pStudioData = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
  AsyncInfoIndex = GetAsyncInfoIndex(hModel: handle, type: MDLCACHE_ANIMBLOCK, iAnimBlock: nBlock);
  if ( AsyncInfoIndex == NO_ASYNC )
  {
    v7 = this->GetStudioHdr(this, a2: handle);
    v8 = v7->animblockindex + 8 * nBlock;
    v9 = *(int *)((char *)&v7->version + v8);
    v10 = (mstudioanimblock_t *)((char *)v7 + v8);
    v11 = (char *)v7 + v7->szanimblocknameindex;
    v12 = v9 - v10->datastart;
    pStudioHdr = v7;
    pBlock = v10;
    if ( v12 == 0 )
      return nullptr;
    pStudioData->m_vecAnimBlocks.m_Memory.m_pMemory[nBlock] = nullptr;
    V_strncpy(pDest: pFileName, pSrc: v11, maxLen: 260);
    V_FixSlashes(pname: pFileName, separator: 92);
    if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
    {
      v14 = this->GetModelName(this, a2: handle);
      _Msg(a1: "MDLCache: Begin load Anim Block %s (block %i, bytes %d)\n", v14, nBlock, v12);
    }
    info.hModel = handle;
    info.type = MDLCACHE_ANIMBLOCK;
    info.iAnimBlock = nBlock;
    info.hControl = nullptr;
    if ( v12 > 0x10000 )
    {
      pData = nullptr;
      v16 = studiohdr_t::pszName(this: pStudioHdr);
      _Warning(a1: "%s(%d): MDL Cache allocation outside the pool. %s : %d.\n", "mdlcache.cpp", 1704, v16, v12);
      v15 = pData;
    }
    else
    {
      v15 = CFixedBudgetMemoryPool<65536,137>::Alloc(this: &g_AnimBlockAllocator);
    }
    CMDLCache::LoadData(
      this,
      pszFilename: pFileName,
      pszPathID: "GAME",
      pDest: v15,
      nBytes: v12,
      nOffset: pBlock->datastart,
      bAsync: bUseAsync,
      pControl: &info.hControl);
    v17 = CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AddToTail(
            this: &this->m_PendingAsyncs,
            src: &info);
    AsyncInfoIndex = SetAsyncInfoIndex(hModel: handle, type: MDLCACHE_ANIMBLOCK, iAnimBlock: nBlock, index: (int)v17);
  }
  CMDLCache::ProcessPendingAsync(this, iAsync: AsyncInfoIndex);
  v18 = pStudioData->m_vecAnimBlocks.m_Memory.m_pMemory[nBlock];
  v19 = this->GetCacheSection(this, a2: 3);
  return (unsigned __int8 *)v19->Get(this: v19, a2: v18, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000EB40
// Name: public: virtual unsigned char __near * CMDLCache::GetAnimBlock(unsigned short,int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMDLCache::GetAnimBlock(CMDLCache *this, int handle, int nBlock, bool preloadIfMissing)
{
  studiodata_t *elem; // ebx
  CThreadFastMutex *p_m_AsyncMutex; // edi
  DWORD CurrentThreadId; // eax
  studiohdr_t *v9; // eax
  bool v10; // zf
  memhandle_t__ *v11; // edi
  IDataCacheSection *v12; // eax
  int m_depth; // edx
  __int32 m_pMemory; // ecx
  unsigned __int8 *v15; // edi
  DWORD v16; // eax
  int m_nValue; // eax
  unsigned int v18; // eax
  unsigned int *v19; // edx
  unsigned int v20; // ecx
  int v21; // ecx
  int v22; // [esp+4h] [ebp-8h]

  if ( mod_test_not_available.m_pParent != nullptr && mod_test_not_available.m_pParent->m_Value.m_nValue != 0
    || (_WORD)handle == 0xFFFF )
  {
    return nullptr;
  }
  elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
  if ( elem->m_vecAnimBlocks.m_Size == 0 )
  {
    p_m_AsyncMutex = &this->m_AsyncMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_AsyncMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_AsyncMutex.m_depth;
    }
    if ( elem->m_vecAnimBlocks.m_Size == 0 )
    {
      v9 = this->GetStudioHdr(this, a2: handle);
      CMDLCache::AllocateAnimBlocks(this, pStudioData: elem, nCount: v9->numanimblocks);
    }
    v10 = this->m_AsyncMutex.m_depth-- == 1;
    if ( v10 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
  }
  if ( nBlock < 0 || nBlock >= elem->m_vecAnimBlocks.m_Size )
    return nullptr;
  v11 = elem->m_vecAnimBlocks.m_Memory.m_pMemory[nBlock];
  v22 = nBlock;
  v12 = this->GetCacheSection(this, a2: 3);
  v15 = (unsigned __int8 *)v12->Get(this: v12, a2: v11, a3: true);
  if ( v15 == nullptr )
  {
    v16 = GetCurrentThreadId();
    if ( v16 != this->m_AsyncMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_AsyncMutex, v16, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: v16, a3: 0);
    }
    else
    {
      ++this->m_AsyncMutex.m_depth;
    }
    v15 = (unsigned __int8 *)CMDLCache::CheckData(
                               this,
                               c: elem->m_vecAnimBlocks.m_Memory.m_pMemory[v22],
                               type: MDLCACHE_ANIMBLOCK);
    if ( v15 == nullptr )
    {
      m_pMemory = (__int32)elem->m_vecAnimBlocks.m_Memory.m_pMemory;
      *(_DWORD *)(v22 * 4 + m_pMemory) = 0;
      if ( preloadIfMissing )
      {
        if ( mod_load_anims_async.m_pParent != nullptr )
          m_nValue = mod_load_anims_async.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        v15 = CMDLCache::UnserializeAnimBlock(this, handle, bUseAsync: m_nValue != 0, nBlock);
      }
    }
    v10 = this->m_AsyncMutex.m_depth-- == 1;
    m_depth = this->m_AsyncMutex.m_depth;
    if ( v10 )
      m_pMemory = _InterlockedExchange((volatile __int32 *)&this->m_AsyncMutex, 0);
  }
  if ( mod_load_fakestall.m_pParent == nullptr || mod_load_fakestall.m_pParent->m_Value.m_nValue == 0 )
    return v15;
  v18 = _Plat_MSTime(a1: m_pMemory, a2: m_depth);
  v19 = elem->m_vecFakeAnimBlockStall.m_Memory.m_pMemory;
  v20 = v19[nBlock];
  if ( v20 == 0 || v20 > v18 )
    v19[nBlock] = v18;
  v21 = mod_load_fakestall.m_pParent != nullptr ? mod_load_fakestall.m_pParent->m_Value.m_nValue : 0;
  if ( (int)(v18 - elem->m_vecFakeAnimBlockStall.m_Memory.m_pMemory[v22]) < v21 )
    return nullptr;
  else
    return v15;
}

//------------------------------------------------------------------------------
// Address: 0x1000ED10
// Name: public: virtual struct virtualmodel_t __near * CMDLCache::GetVirtualModelFast(struct studiohdr_t const __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall CMDLCache::GetVirtualModelFast(
        CMDLCache *this,
        const studiohdr_t *pStudioHdr,
        unsigned __int16 handle)
{
  studiodata_t *elem; // edi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  int v9; // ecx
  char *name; // eax
  studiodata_t *v11; // ebx
  virtualmodel_t *v12; // eax
  virtualmodel_t *v13; // eax

  if ( pStudioHdr->numincludemodels == 0 )
    return nullptr;
  elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
  if ( elem == nullptr )
    return nullptr;
  if ( elem->m_pVirtualModel == nullptr )
  {
    studiohdr2index = pStudioHdr->studiohdr2index;
    if ( studiohdr2index != 0
      && (v7 = *(_DWORD *)&pStudioHdr->name[studiohdr2index + 8], v8 = (char *)pStudioHdr + studiohdr2index, v7 != 0)
      && &v8[v7] != nullptr )
    {
      v9 = *((_DWORD *)v8 + 5);
      if ( v9 != 0 )
        name = &v8[v9];
      else
        name = nullptr;
    }
    else
    {
      name = pStudioHdr->name;
    }
    _DevMsg(a1: 2, a2: "Loading virtual model for %s\n", name);
    this->BeginLock(this);
    v11 = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
    v12 = (virtualmodel_t *)operator new(nSize: 0xA8u);
    if ( v12 != nullptr )
      v13 = virtualmodel_t::virtualmodel_t(this: v12);
    else
      v13 = nullptr;
    v11->m_pVirtualModel = v13;
    elem->m_pVirtualModel->m_group.m_Memory.m_pMemory[CUtlVector<virtualgroup_t,CUtlMemory<virtualgroup_t,int>>::InsertBefore(
                                                        this: &elem->m_pVirtualModel->m_group,
                                                        elem: elem->m_pVirtualModel->m_group.m_Size)].cache = (void *)handle;
    virtualmodel_t::AppendModels(this: elem->m_pVirtualModel, group: 0, pStudioHdr);
    this->EndLock(this);
  }
  return elem->m_pVirtualModel;
}

//------------------------------------------------------------------------------
// Address: 0x1000EE00
// Name: private: bool CMDLCache::UnserializeHardwareData(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::UnserializeHardwareData(CMDLCache *this, studiodata_t *handle, bool bUseAsync)
{
  studiodata_t *elem; // esi
  studiohdr_t *v7; // eax
  const char *v8; // eax
  unsigned __int16 m_nFlags; // ax
  int AsyncInfoIndex; // eax
  const char *v11; // eax
  CThreadFastMutex *p_m_AsyncMutex; // esi
  DWORD CurrentThreadId; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int> >::BlockHeader_t *v14; // eax
  bool v16; // cc
  void (__thiscall *EndLock)(IMDLCache *); // edx
  bool v18; // bl
  char pFileName[260]; // [esp+4h] [ebp-118h] BYREF
  studiohdr_t *pStudioHdr; // [esp+108h] [ebp-14h]
  AsyncInfo_t info; // [esp+10Ch] [ebp-10h] BYREF
  studiodata_t *pStudioData; // [esp+124h] [ebp+8h]

  if ( (*((_BYTE *)this + 160) & 1) != 0 )
    return 0;
  elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
  pStudioData = elem;
  this->BeginLock(this);
  v7 = this->GetStudioHdr(this, a2: handle);
  pStudioHdr = v7;
  if ( v7 != nullptr && v7->numbodyparts != 0 )
  {
    if ( (elem->m_nFlags & 8) != 0 )
    {
LABEL_16:
      this->EndLock(this);
      return 0;
    }
    if ( mod_trace_load.m_pParent != nullptr
      && mod_trace_load.m_pParent->m_Value.m_nValue != 0
      && GetAsyncInfoIndex(hModel: (unsigned __int16)handle, type: MDLCACHE_STUDIOHWDATA, iAnimBlock: 0) == NO_ASYNC
      && GetAsyncInfoIndex(hModel: (unsigned __int16)handle, type: MDLCACHE_VERTEXES, iAnimBlock: 0) == NO_ASYNC
      && mod_trace_load.m_pParent != nullptr
      && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
    {
      v8 = this->GetModelName(this, a2: handle);
      _Msg(a1: "MDLCache: Begin load studiomdl %s\n", v8);
    }
    if ( this->GetVertexData(this, a2: handle) == nullptr )
    {
      m_nFlags = elem->m_nFlags;
      if ( (m_nFlags & 0x10) != 0 )
        elem->m_nFlags = m_nFlags | 8;
      goto LABEL_16;
    }
    AsyncInfoIndex = GetAsyncInfoIndex(hModel: (unsigned __int16)handle, type: MDLCACHE_STUDIOHWDATA, iAnimBlock: 0);
    if ( AsyncInfoIndex == NO_ASYNC )
    {
      this->m_pMeshCacheSection->Lock(this: this->m_pMeshCacheSection, a2: elem->m_VertexCache);
      MakeFilename(szFileName: pFileName, pStudioHdr, pszExtension: ".dx90.vtx");
      if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
      {
        v11 = this->GetModelName(this, a2: handle);
        _Msg(a1: "MDLCache: Begin load VTX %s\n", v11);
      }
      info.hModel = (unsigned __int16)handle;
      info.type = MDLCACHE_STUDIOHWDATA;
      info.iAnimBlock = 0;
      info.hControl = nullptr;
      CMDLCache::LoadData(this, pszFilename: pFileName, pszPathID: "GAME", bAsync: bUseAsync, pControl: &info.hControl);
      p_m_AsyncMutex = &this->m_AsyncMutex;
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != this->m_AsyncMutex.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++this->m_AsyncMutex.m_depth;
      }
      v14 = CUtlLinkedList<AsyncInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AsyncInfo_t,int>>>::AddToTail(
              this: &this->m_PendingAsyncs,
              src: &info);
      AsyncInfoIndex = SetAsyncInfoIndex(
                         hModel: (unsigned __int16)handle,
                         type: MDLCACHE_STUDIOHWDATA,
                         iAnimBlock: 0,
                         index: (int)v14);
      if ( this->m_AsyncMutex.m_depth-- == 1 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
      elem = pStudioData;
    }
    v16 = CMDLCache::ProcessPendingAsync(this, iAsync: AsyncInfoIndex) <= 0;
    EndLock = this->EndLock;
    if ( v16 || (elem->m_nFlags & 8) != 0 )
    {
      ((void (__fastcall *)(CMDLCache *))EndLock)(a1: this);
      return 0;
    }
    else
    {
      v18 = elem->m_HardwareData.m_NumStudioMeshes != 0;
      ((void (__fastcall *)(CMDLCache *))EndLock)(a1: this);
      return v18;
    }
  }
  else
  {
    elem->m_nFlags |= 8u;
    this->EndLock(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F040
// Name: public: virtual struct studiohwdata_t __near * CMDLCache::GetHardwareData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
studiohwdata_t *__thiscall CMDLCache::GetHardwareData(CMDLCache *this, studiodata_t *handle)
{
  studiodata_t *elem; // edi
  void (*UnlockMutex)(void); // eax
  int m_nValue; // eax

  if ( mod_test_not_available.m_pParent != nullptr && mod_test_not_available.m_pParent->m_Value.m_nValue != 0
    || mod_test_mesh_not_available.m_pParent != nullptr && mod_test_mesh_not_available.m_pParent->m_Value.m_nValue != 0 )
  {
    return nullptr;
  }
  elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
  if ( (elem->m_nFlags & 9) == 0 )
  {
    this->m_pMeshCacheSection->LockMutex(this: this->m_pMeshCacheSection);
    UnlockMutex = (void (*)(void))this->m_pMeshCacheSection->UnlockMutex;
    if ( (elem->m_nFlags & 9) != 0 )
    {
      UnlockMutex();
    }
    else
    {
      UnlockMutex();
      if ( mod_load_mesh_async.m_pParent != nullptr )
        m_nValue = mod_load_mesh_async.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( CMDLCache::UnserializeHardwareData(this, handle, bUseAsync: m_nValue != 0) == 0 )
        return nullptr;
    }
  }
  return &elem->m_HardwareData;
}

//------------------------------------------------------------------------------
// Address: 0x1000F0E0
// Name: public: virtual void CMDLCache::FinishPendingLoads(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::FinishPendingLoads(CMDLCache *this)
{
  CThreadFastMutex *p_m_AsyncMutex; // edi
  DWORD CurrentThreadId; // ecx
  int i; // esi

  if ( (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    p_m_AsyncMutex = &this->m_AsyncMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_AsyncMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_AsyncMutex.m_depth;
    }
    for ( i = this->m_PendingAsyncs.m_Head; i != 0; i = *(_DWORD *)(i + 20) )
    {
      if ( *(_DWORD *)i != 0 )
        g_pFullFileSystem->AsyncFinish(this: g_pFullFileSystem, a2: *(FSAsyncControl_t__ **)i, a3: true);
    }
    CMDLCache::ProcessPendingAsyncs(this, type: MDLCACHE_NONE);
    if ( this->m_AsyncMutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F170
// Name: public: virtual struct vertexFileHeader_t __near * CMDLCache::CacheVertexData(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
vertexFileHeader_t *__thiscall CMDLCache::CacheVertexData(CMDLCache *this, studiohdr_t *pStudioHdr)
{
  int v3; // esi
  int v4; // ecx
  vertexFileHeader_t *result; // eax
  int v6; // eax
  int v7; // [esp+8h] [ebp-4h]

  v3 = 2 * LOWORD(pStudioHdr->virtualModel);
  v4 = *((_DWORD *)this->m_MDLDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc + 4 * LOWORD(pStudioHdr->virtualModel) + 3);
  result = *(vertexFileHeader_t **)(v4 + 120);
  if ( result == nullptr )
  {
    v7 = *(_DWORD *)(v4 + 92);
    v6 = (*(int (__thiscall **)(char *, int))(*((_DWORD *)this - 1) + 112))(a1: (char *)this - 4, a2: 5);
    result = (vertexFileHeader_t *)(*(int (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 52))(a1: v6, a2: v7, a3: 1);
    if ( result == nullptr )
    {
      *(_DWORD *)(*((_DWORD *)this->m_MDLDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc + 2 * v3 + 3) + 92) = 0;
      return CMDLCache::LoadVertexData(this: (CMDLCache *)((char *)this - 4), pStudioHdr);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F1E0
// Name: public: struct virtualmodel_t __near * studiohdr_t::GetVirtualModel(void)const
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall studiohdr_t::GetVirtualModel(studiohdr_t *this)
{
  if ( this->numincludemodels != 0 )
    return CMDLCache::GetVirtualModelFast(
             this: &g_MDLCache,
             pStudioHdr: this,
             handle: (unsigned __int16)this->virtualModel);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000F210
// Name: private: void CMDLCache::FreeVirtualModel(struct studiodata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::FreeVirtualModel(CMDLCache *this, studiodata_t *pStudioData)
{
  studiodata_t *v2; // edi
  virtualmodel_t *m_pVirtualModel; // eax
  int m_Size; // eax
  int v6; // ebx
  int cache_low; // edi
  virtualmodel_t *v8; // esi
  int v9; // [esp+8h] [ebp-4h]

  v2 = pStudioData;
  if ( pStudioData != nullptr )
  {
    m_pVirtualModel = pStudioData->m_pVirtualModel;
    if ( m_pVirtualModel != nullptr )
    {
      m_Size = m_pVirtualModel->m_group.m_Size;
      if ( m_Size > 1 )
      {
        v6 = 1;
        v9 = m_Size - 1;
        do
        {
          cache_low = LOWORD(v2->m_pVirtualModel->m_group.m_Memory.m_pMemory[v6].cache);
          CMDLCache::FreeVirtualModel(
            this,
            pStudioData: this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[cache_low].m_Data.elem);
          this->Release(this, a2: cache_low);
          v2 = pStudioData;
          ++v6;
          --v9;
        }
        while ( v9 != 0 );
      }
      v8 = v2->m_pVirtualModel;
      if ( v8 != nullptr )
      {
        CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v8->m_autoplaySequences);
        CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v8->m_iklock);
        CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v8->m_node);
        CUtlVector<virtualgroup_t,CUtlMemory<virtualgroup_t,int>>::~CUtlVector<virtualgroup_t,CUtlMemory<virtualgroup_t,int>>(this: &v8->m_group);
        CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v8->m_pose);
        CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v8->m_attachment);
        CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v8->m_anim);
        CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v8->m_seq);
        free(pMem: v8);
      }
      v2->m_pVirtualModel = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F2E0
// Name: private: void CMDLCache::UnserializeAllVirtualModelsAndAnimBlocks(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::UnserializeAllVirtualModelsAndAnimBlocks(CMDLCache *this, studiohdr_t *handle)
{
  int v4; // edi
  studiohdr_t *pStudioHdr; // [esp+10h] [ebp+8h]

  if ( (_WORD)handle != 0xFFFF )
  {
    CMDLCache::FreeVirtualModel(
      this,
      pStudioData: this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem);
    if ( mod_forcedata.m_pParent != nullptr && mod_forcedata.m_pParent->m_Value.m_nValue != 0 )
    {
      this->GetVirtualModel(this, a2: (unsigned __int16)handle);
      v4 = 1;
      pStudioHdr = this->GetStudioHdr(this, a2: handle);
      if ( pStudioHdr->numanimblocks > 1 )
      {
        do
          this->GetAnimBlock(this, a2: (unsigned __int16)handle, a3: v4++, a4: true);
        while ( v4 < pStudioHdr->numanimblocks );
      }
      CMDLCache::ProcessPendingAsyncs(this, type: MDLCACHE_ANIMBLOCK);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F370
// Name: public: virtual void CMDLCache::TouchAllData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::TouchAllData(CMDLCache *this, int handle)
{
  studiohdr_t *v3; // ebx
  virtualmodel_t *v4; // esi
  int v5; // ebx
  int j; // esi
  studiohdr_t *pStudioHdr; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = this->GetStudioHdr(this, a2: handle);
  pStudioHdr = v3;
  v4 = this->GetVirtualModel(this, a2: handle);
  if ( v4 != nullptr )
  {
    i = 1;
    if ( v4->m_group.m_Size > 1 )
    {
      v5 = 1;
      do
      {
        if ( LOWORD(v4->m_group.m_Memory.m_pMemory[v5].cache) != 0xFFFF )
          this->GetStudioHdr(this, a2: (unsigned __int16)v4->m_group.m_Memory.m_pMemory[v5].cache);
        ++v5;
        ++i;
      }
      while ( i < v4->m_group.m_Size );
      v3 = pStudioHdr;
    }
  }
  for ( j = 1; j < v3->numanimblocks; ++j )
    CMDLCache::GetAnimBlock(this: &g_MDLCache, handle: LOWORD(v3->virtualModel), nBlock: j, preloadIfMissing: true);
  if ( v3->numbodyparts != 0
    && (mod_dont_load_vertices.m_pParent == nullptr || mod_dont_load_vertices.m_pParent->m_Value.m_nValue == 0) )
  {
    this->CacheVertexData(this: &this->IStudioDataCache, a2: v3);
    this->GetHardwareData(this, a2: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F450
// Name: private: bool CMDLCache::ProcessDataIntoCache(unsigned short,class CMDLCacheData __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::ProcessDataIntoCache(
        CMDLCache *this,
        studiohdr_t *handle,
        studiohdr_t *cacheData,
        int iAnimBlock)
{
  studiohdr_t *v6; // ecx
  studiohdr_t *v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,studiodata_t *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  studiodata_t *elem; // esi
  studiohdr_t *v11; // eax
  studiohdr_t *v12; // esi
  char *v13; // eax
  int v14; // edi
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  int v21; // edi
  CStudioVCollide *v22; // eax
  const char *v23; // edx
  vcollide_t *p_m_vcollide; // esi
  IPhysicsCollision_vtbl *v25; // edi
  char *v26; // eax
  char *v27; // eax
  char pCacheName[260]; // [esp+8h] [ebp-14Ch] BYREF
  CUtlBuffer buf; // [esp+10Ch] [ebp-48h] BYREF
  phyheader_s header; // [esp+13Ch] [ebp-18h] BYREF
  int v31; // [esp+14Ch] [ebp-8h]
  studiohdr_t *pStudioHdrCurrent; // [esp+150h] [ebp-4h]
  CMDLCacheData *cacheDataa; // [esp+160h] [ebp+Ch]

  v6 = nullptr;
  pStudioHdrCurrent = nullptr;
  if ( cacheData->checksum != 0 )
  {
    v7 = this->GetStudioHdr(this, a2: handle);
    pStudioHdrCurrent = v7;
    if ( v7 == nullptr )
      return 0;
    v6 = v7;
  }
  m_pMemory = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  v31 = (unsigned __int16)handle;
  elem = m_pMemory[(unsigned __int16)handle].m_Data.elem;
  cacheDataa = (CMDLCacheData *)(16 * (unsigned __int16)handle);
  if ( elem != nullptr )
  {
    switch ( cacheData->checksum )
    {
      case 0:
        v11 = CMDLCache::UnserializeMDL(this, (int)handle, cacheData);
        v12 = v11;
        if ( v11 == nullptr )
          return 0;
        if ( Studio_ConvertStudioHdrToNewVersion(pStudioHdr: v11) == 0 )
        {
          v13 = studiohdr_t::pszName(this: v12);
          _Warning(a1: "MDLCache: %s needs to be recompiled\n", v13);
        }
        if ( v12->numincludemodels == 0 )
        {
          v14 = studiohdr_t::CountAutoplaySequences(this: v12);
          if ( v14 != 0 )
          {
            CMDLCache::AllocateAutoplaySequences(
              this,
              pStudioData: *(studiodata_t **)((char *)&cacheDataa->m_AllocType
                               + (unsigned int)this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory),
              nCount: v14);
            studiohdr_t::CopyAutoplaySequences(
              this: v12,
              pOut: *(unsigned __int16 **)(*(CMDLCacheData::AllocType_t *)((char *)&cacheDataa->m_AllocType
                                                                   + (unsigned int)this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory)
                                   + 96),
              outCount: v14);
          }
        }
        CMDLCache::UnserializeAllVirtualModelsAndAnimBlocks(this, handle);
        return 1;
      case 1:
        if ( cacheData->id != 0 )
        {
          CMDLCache::BuildHardwareData(
            this,
            (int)handle,
            pStudioData: elem,
            pStudioHdr: v6,
            (OptimizedModel::FileHeader_t *)cacheData);
        }
        else
        {
          elem->m_nFlags |= 8u;
          if ( v6->numbodyparts != 0 )
          {
            v16 = studiohdr_t::pszName(this: v6);
            _Warning(a1: "MDLCache: Failed load of .VTX data for %s\n", v16);
            return 0;
          }
        }
        this->m_pMeshCacheSection->Unlock(this: this->m_pMeshCacheSection, a2: elem->m_VertexCache);
        this->m_pMeshCacheSection->Age(this: this->m_pMeshCacheSection, a2: elem->m_VertexCache);
        if ( (elem->m_nFlags & 8) != 0 )
          return 1;
        this->GetVertexData(this, a2: (unsigned __int16)handle);
        return 1;
      case 2:
        elem->m_nFlags |= 2u;
        if ( cacheData->id != 0 )
        {
          if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
          {
            v20 = studiohdr_t::pszName(this: v6);
            _Msg(a1: "MDLCache: Finish load vcollide for %s\n", v20);
          }
          CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: (const void *)cacheData->id, nSize: cacheData->version, nFlags: 8);
          CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: cacheData->version);
          CUtlBuffer::Get(this: &buf, pMem: &header, size: 16);
          if ( header.size == 16 && header.solidCount > 0 )
          {
            v21 = buf.m_nMaxPut - buf.m_Get;
            v22 = (CStudioVCollide *)operator new(nSize: 0x18u);
            if ( v22 != nullptr )
            {
              v22->m_iRefs = 1;
              v22->__vftable = (CStudioVCollide_vtbl *)&CStudioVCollide::`vftable';
            }
            else
            {
              v22 = nullptr;
            }
            v23 = (const char *)&buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset];
            elem->m_pVCollide = v22;
            p_m_vcollide = &v22->m_vcollide;
            g_pPhysicsCollision->VCollideLoad(
              this: g_pPhysicsCollision,
              a2: &v22->m_vcollide,
              a3: header.solidCount,
              a4: v23,
              a5: v21,
              a6: false);
            if ( mod_check_vcollide.m_pParent != nullptr && mod_check_vcollide.m_pParent->m_Value.m_nValue != 0 )
            {
              v25 = g_pPhysicsCollision->__vftable;
              v26 = studiohdr_t::pszName(this: pStudioHdrCurrent);
              v25->VCollideCheck(this: g_pPhysicsCollision, a2: p_m_vcollide, a3: v26);
            }
            if ( this->m_pCacheNotify != nullptr )
              this->m_pCacheNotify->OnDataLoaded(
                this: this->m_pCacheNotify,
                a2: MDLCACHE_VCOLLIDE,
                a3: (unsigned __int16)handle);
          }
          CUtlBuffer::~CUtlBuffer(this: &buf);
          return 1;
        }
        if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
        {
          v27 = studiohdr_t::pszName(this: v6);
          _Warning(a1: "MDLCache: Failed load of .PHY data for %s\n", v27);
        }
        break;
      case 3:
        if ( cacheData->id != 0 )
        {
          if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
          {
            v17 = studiohdr_t::pszName(this: v6);
            _Msg(a1: "MDLCache: Finish load anim block %s (block %i)\n", v17, iAnimBlock);
            v6 = pStudioHdrCurrent;
          }
          v18 = studiohdr_t::pszName(this: v6);
          V_snprintf(pDest: pCacheName, maxLen: 260, pFormat: "%s (block %i)", v18, iAnimBlock);
          CMDLCache::CacheData(
            this,
            c: &elem->m_vecAnimBlocks.m_Memory.m_pMemory[iAnimBlock],
            pData: (void *)cacheData->id,
            size: cacheData->version,
            name: pCacheName,
            type: MDLCACHE_ANIMBLOCK,
            id: (void *)((v31 << 16) | 3));
          CMDLCacheData::Detach(this: (CMDLCacheData *)cacheData);
          return 1;
        }
        else
        {
          if ( mod_trace_load.m_pParent != nullptr && mod_trace_load.m_pParent->m_Value.m_nValue != 0 )
          {
            v19 = studiohdr_t::pszName(this: v6);
            _Msg(a1: "MDLCache: Failed load anim block %s (block %i)\n", v19, iAnimBlock);
          }
          if ( elem->m_vecAnimBlocks.m_Size > iAnimBlock )
            elem->m_vecAnimBlocks.m_Memory.m_pMemory[iAnimBlock] = nullptr;
          return 0;
        }
      case 5:
        if ( cacheData->id != 0 )
        {
          CMDLCache::BuildAndCacheVertexData(this, pStudioHdr: v6, (CMDLCacheData *)cacheData);
          return 1;
        }
        else
        {
          elem->m_nFlags |= 0x10u;
          if ( v6->numbodyparts != 0 )
          {
            v15 = studiohdr_t::pszName(this: v6);
            _Warning(a1: "MDLCache: Failed load of .VVD data for %s\n", v15);
            return 0;
          }
          else
          {
            return 1;
          }
        }
      default:
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F840
// Name: private: void CMDLCache::Flush(struct studiodata_t __near *,enum MDLCacheFlush_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::Flush(CMDLCache *this, studiodata_t *pStudioData, MDLCacheFlush_t nFlushFlags)
{
  IDataCacheSection *v4; // eax
  IDataCacheSection *v5; // eax
  bool bIgnoreLock; // [esp+Ch] [ebp-4h]

  bIgnoreLock = nFlushFlags < 0;
  if ( (nFlushFlags & 2) != 0 )
    CMDLCache::UnloadHardwareData(this, pStudioData);
  if ( (nFlushFlags & 4) != 0 )
    CMDLCache::DestroyVCollide(this, pStudioData);
  if ( (nFlushFlags & 0x10) != 0 )
    CMDLCache::FreeVirtualModel(this, pStudioData);
  if ( (nFlushFlags & 8) != 0 )
    CMDLCache::FreeAnimBlocks(this, (TSLNodeBase_t *)pStudioData);
  if ( (nFlushFlags & 0x20) != 0 )
  {
    pStudioData->m_vecAutoplaySequenceList.m_Size = 0;
    if ( pStudioData->m_vecAutoplaySequenceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pStudioData->m_vecAutoplaySequenceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioData->m_vecAutoplaySequenceList.m_Memory.m_pMemory);
        pStudioData->m_vecAutoplaySequenceList.m_Memory.m_pMemory = nullptr;
      }
      pStudioData->m_vecAutoplaySequenceList.m_Memory.m_nAllocationCount = 0;
    }
    pStudioData->m_vecAutoplaySequenceList.m_pElements = pStudioData->m_vecAutoplaySequenceList.m_Memory.m_pMemory;
  }
  if ( (nFlushFlags & 1) != 0 )
  {
    if ( pStudioData->m_pForceLockedStudioHdr != nullptr )
    {
      v4 = this->GetCacheSection(this, a2: 0);
      v4->Unlock(this: v4, a2: pStudioData->m_MDLCache);
      pStudioData->m_pForceLockedStudioHdr = nullptr;
    }
    CMDLCache::UncacheData(
      this,
      c: (TSLNodeBase_t *)pStudioData->m_MDLCache,
      type: MDLCACHE_STUDIOHDR,
      bLockedOk: bIgnoreLock);
    pStudioData->m_MDLCache = nullptr;
  }
  if ( (nFlushFlags & 0x40) != 0 )
  {
    if ( pStudioData->m_pForceLockedVertexFileHeader != nullptr )
    {
      v5 = this->GetCacheSection(this, a2: 5);
      v5->Unlock(this: v5, a2: pStudioData->m_VertexCache);
      pStudioData->m_pForceLockedVertexFileHeader = nullptr;
    }
    CMDLCache::ClearAsync(this, handle: pStudioData->m_Handle, type: MDLCACHE_VERTEXES, iAnimBlock: 0, bAbort: true);
    CMDLCache::UncacheData(
      this,
      c: (TSLNodeBase_t *)pStudioData->m_VertexCache,
      type: MDLCACHE_VERTEXES,
      bLockedOk: bIgnoreLock);
    pStudioData->m_VertexCache = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F950
// Name: public: virtual void CMDLCache::Flush(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::Flush(CMDLCache *this, unsigned __int16 handle, MDLCacheFlush_t nFlushFlags)
{
  CMDLCache::Flush(
    this,
    pStudioData: this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem,
    nFlushFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1000F970
// Name: public: virtual void CMDLCache::UnloadQueuedHardwareData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::UnloadQueuedHardwareData(CMDLCache *this)
{
  CMDLCache *v1; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CTSQueue<studiodata_t *,0,1>::Node_t *v3; // eax
  studiodata_t *elem; // esi
  unsigned __int16 m_nFlags; // ax
  bool v6; // zf
  volatile signed __int32 *m_pVCollide; // edi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  memhandle_t__ *m_VertexCache; // ebx
  int v12; // edi
  unsigned __int16 *m_pMemory; // eax
  unsigned int *v14; // eax
  memhandle_t__ **v15; // eax
  DWORD CurrentThreadId; // eax
  int v17; // [esp+Ch] [ebp-10h] BYREF
  int v18; // [esp+10h] [ebp-Ch] BYREF
  CMDLCache *v19; // [esp+14h] [ebp-8h]
  memhandle_t__ *m_MDLCache; // [esp+18h] [ebp-4h]

  v1 = this;
  BeginLock = this->BeginLock;
  v19 = this;
  ((void (__fastcall *)(CMDLCache *))BeginLock)(a1: this);
  while ( 1 )
  {
    v3 = CTSQueue<studiodata_t *,0,1>::Pop(this: &v1->m_UnloadHandles);
    if ( v3 == nullptr )
      break;
    elem = v3->elem;
    CTSListBase::Push(this: &v1->m_UnloadHandles.m_FreeNodes, pNode: (TSLNodeBase_t *)v3);
    if ( elem != nullptr && (elem->m_nFlags & 1) != 0 )
    {
      if ( v1->m_pCacheNotify != nullptr )
        v1->m_pCacheNotify->OnDataUnloaded(this: v1->m_pCacheNotify, a2: MDLCACHE_STUDIOHWDATA, a3: elem->m_Handle);
      g_pStudioRender->UnloadModel(this: g_pStudioRender, a2: &elem->m_HardwareData);
      *(_QWORD *)&elem->m_HardwareData.m_RootLOD = 0;
      *(_QWORD *)&elem->m_HardwareData.m_pLODs = 0;
      *(_QWORD *)&elem->m_HardwareData.m_NumFacesRenderedThisFrame = 0;
      elem->m_HardwareData.m_pStudioHdr = nullptr;
      elem->m_nFlags &= ~1u;
    }
    m_nFlags = elem->m_nFlags;
    if ( (m_nFlags & 2) != 0 )
    {
      v6 = elem->m_pVCollide == nullptr;
      elem->m_nFlags = m_nFlags & 0xFFFD;
      if ( !v6 )
      {
        if ( v1->m_pCacheNotify != nullptr )
          v1->m_pCacheNotify->OnDataUnloaded(this: v1->m_pCacheNotify, a2: MDLCACHE_VCOLLIDE, a3: elem->m_Handle);
        m_pVCollide = (volatile signed __int32 *)elem->m_pVCollide;
        if ( _InterlockedDecrement(m_pVCollide + 1) == 0
          && (*(unsigned __int8 (__thiscall **)(volatile signed __int32 *))(*m_pVCollide + 4))(a1: m_pVCollide) != 0 )
        {
          (**(void (__thiscall ***)(volatile signed __int32 *, int))m_pVCollide)(a1: m_pVCollide, a2: 1);
        }
        elem->m_pVCollide = nullptr;
      }
    }
    CMDLCache::FreeVirtualModel(this: v1, pStudioData: elem);
    CMDLCache::FreeAnimBlocks(this: v1, pStudioData: (TSLNodeBase_t *)elem);
    elem->m_vecAutoplaySequenceList.m_Size = 0;
    if ( elem->m_vecAutoplaySequenceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory);
        elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory = nullptr;
      }
      elem->m_vecAutoplaySequenceList.m_Memory.m_nAllocationCount = 0;
    }
    elem->m_vecAutoplaySequenceList.m_pElements = elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory;
    if ( elem->m_pForceLockedStudioHdr != nullptr )
    {
      v8 = (int)v1->GetCacheSection(this: v1, a2: MDLCACHE_STUDIOHDR);
      (*(void (__thiscall **)(int, memhandle_t__ *))(*(_DWORD *)v8 + 48))(a1: v8, a2: elem->m_MDLCache);
      elem->m_pForceLockedStudioHdr = nullptr;
    }
    m_MDLCache = elem->m_MDLCache;
    if ( m_MDLCache != nullptr )
    {
      v9 = (int)v1->GetCacheSection(this: v1, a2: MDLCACHE_STUDIOHDR);
      if ( (*(unsigned __int8 (__thiscall **)(int, memhandle_t__ *))(*(_DWORD *)v9 + 40))(a1: v9, a2: m_MDLCache) != 0 )
      {
        (*(void (__thiscall **)(int, memhandle_t__ *))(*(_DWORD *)v9 + 84))(a1: v9, a2: m_MDLCache);
        (*(void (__thiscall **)(int, memhandle_t__ *, int *, _DWORD, _DWORD))(*(_DWORD *)v9 + 36))(
          a1: v9,
          a2: m_MDLCache,
          a3: &v18,
          a4: 0,
          a5: 0);
        if ( v18 != 0 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((v18 & 0xFFFFFFFC) - 4));
      }
    }
    v6 = elem->m_pForceLockedVertexFileHeader == nullptr;
    elem->m_MDLCache = nullptr;
    if ( !v6 )
    {
      v10 = (int)v1->GetCacheSection(this: v1, a2: MDLCACHE_VERTEXES);
      (*(void (__thiscall **)(int, memhandle_t__ *))(*(_DWORD *)v10 + 48))(a1: v10, a2: elem->m_VertexCache);
      elem->m_pForceLockedVertexFileHeader = nullptr;
    }
    CMDLCache::ClearAsync(this: v1, handle: elem->m_Handle, type: MDLCACHE_VERTEXES, iAnimBlock: 0, bAbort: true);
    m_VertexCache = elem->m_VertexCache;
    if ( m_VertexCache != nullptr )
    {
      v12 = (int)v19->GetCacheSection(this: v19, a2: MDLCACHE_VERTEXES);
      if ( (*(unsigned __int8 (__thiscall **)(int, memhandle_t__ *))(*(_DWORD *)v12 + 40))(a1: v12, a2: m_VertexCache) != 0 )
      {
        (*(void (__thiscall **)(int, memhandle_t__ *))(*(_DWORD *)v12 + 84))(a1: v12, a2: m_VertexCache);
        (*(void (__thiscall **)(int, memhandle_t__ *, int *, _DWORD, _DWORD))(*(_DWORD *)v12 + 36))(
          a1: v12,
          a2: m_VertexCache,
          a3: &v17,
          a4: 0,
          a5: 0);
        if ( v17 != 0 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((v17 & 0xFFFFFFFC) - 4));
      }
    }
    elem->m_VertexCache = nullptr;
    elem->m_vecAutoplaySequenceList.m_Size = 0;
    if ( elem->m_vecAutoplaySequenceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory);
        elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory = nullptr;
      }
      elem->m_vecAutoplaySequenceList.m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory;
    elem->m_vecAutoplaySequenceList.m_pElements = m_pMemory;
    if ( elem->m_vecAutoplaySequenceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        elem->m_vecAutoplaySequenceList.m_Memory.m_pMemory = nullptr;
      }
      elem->m_vecAutoplaySequenceList.m_Memory.m_nAllocationCount = 0;
    }
    elem->m_vecFakeAnimBlockStall.m_Size = 0;
    if ( elem->m_vecFakeAnimBlockStall.m_Memory.m_nGrowSize >= 0 )
    {
      if ( elem->m_vecFakeAnimBlockStall.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_vecFakeAnimBlockStall.m_Memory.m_pMemory);
        elem->m_vecFakeAnimBlockStall.m_Memory.m_pMemory = nullptr;
      }
      elem->m_vecFakeAnimBlockStall.m_Memory.m_nAllocationCount = 0;
    }
    v14 = elem->m_vecFakeAnimBlockStall.m_Memory.m_pMemory;
    elem->m_vecFakeAnimBlockStall.m_pElements = v14;
    if ( elem->m_vecFakeAnimBlockStall.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v14 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
        elem->m_vecFakeAnimBlockStall.m_Memory.m_pMemory = nullptr;
      }
      elem->m_vecFakeAnimBlockStall.m_Memory.m_nAllocationCount = 0;
    }
    elem->m_vecAnimBlocks.m_Size = 0;
    if ( elem->m_vecAnimBlocks.m_Memory.m_nGrowSize >= 0 )
    {
      if ( elem->m_vecAnimBlocks.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_vecAnimBlocks.m_Memory.m_pMemory);
        elem->m_vecAnimBlocks.m_Memory.m_pMemory = nullptr;
      }
      elem->m_vecAnimBlocks.m_Memory.m_nAllocationCount = 0;
    }
    v15 = elem->m_vecAnimBlocks.m_Memory.m_pMemory;
    elem->m_vecAnimBlocks.m_pElements = v15;
    if ( elem->m_vecAnimBlocks.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v15 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
        elem->m_vecAnimBlocks.m_Memory.m_pMemory = nullptr;
      }
      elem->m_vecAnimBlocks.m_Memory.m_nAllocationCount = 0;
    }
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != studiodata_t::s_Allocator.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&studiodata_t::s_Allocator.m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &studiodata_t::s_Allocator.m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++studiodata_t::s_Allocator.m_mutex.m_depth;
    }
    CUtlMemoryPool::Free(this: &studiodata_t::s_Allocator, memBlock: elem);
    if ( --studiodata_t::s_Allocator.m_mutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&studiodata_t::s_Allocator.m_mutex, 0);
    v1 = v19;
  }
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD20
// Name: public: virtual struct studiohdr_t __near * CMDLCache::GetStudioHdr(unsigned short)
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CMDLCache::GetStudioHdr(CMDLCache *this, studiohdr_t *handle)
{
  studiohdr_t *v2; // ebx
  studiohdr_t *result; // eax
  int v5; // edi
  studiodata_t *elem; // ecx
  CThreadFastMutex *p_m_ForceLockMutex; // ebx
  const char *CurrentThreadId; // eax
  volatile signed __int32 m_ownerID; // ecx
  studiodata_t *v10; // eax
  bool v11; // zf
  IDataCacheSection *v12; // eax
  const char *ActualModelName; // eax
  bool v14; // cc
  studiodata_t *v15; // eax
  CThreadFastMutex *v16; // eax
  ConVar *m_pParent; // eax
  IDataCacheSection *v18; // eax
  CThreadFastMutex *v19; // eax
  CMDLCacheData cacheData; // [esp+8h] [ebp-18h] BYREF
  const char *pModelName; // [esp+18h] [ebp-8h]
  studiodata_t *pStudioData; // [esp+1Ch] [ebp-4h]
  studiohdr_t *pHdra; // [esp+28h] [ebp+8h]
  studiohdr_t *pHdr; // [esp+28h] [ebp+8h]

  v2 = handle;
  if ( (_WORD)handle == 0xFFFF )
    return nullptr;
  v5 = (unsigned __int16)handle;
  elem = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
  pStudioData = elem;
  if ( elem == nullptr )
  {
    _Warning(
      a1: "-------------------------------------------------------------------------------\n"
      "CMDLCache::GetStudioHdr(0x%X) : invalid handle, not in dictionary (of size %u).\n"
      "-------------------------------------------------------------------------------\n",
      (unsigned __int16)handle,
      this->m_MDLDict.m_Elements.m_Tree.m_NumElements);
    return nullptr;
  }
  result = elem->m_pForceLockedStudioHdr;
  if ( result == nullptr )
  {
    if ( mod_lock_mdls_on_load.m_pParent != nullptr && mod_lock_mdls_on_load.m_pParent->m_Value.m_nValue != 0 )
    {
      p_m_ForceLockMutex = &elem->m_ForceLockMutex;
      CurrentThreadId = (const char *)GetCurrentThreadId();
      m_ownerID = p_m_ForceLockMutex->m_ownerID;
      pModelName = CurrentThreadId;
      if ( CurrentThreadId != (const char *)m_ownerID
        && _InterlockedCompareExchange(
             (volatile signed __int32 *)p_m_ForceLockMutex,
             (signed __int32)CurrentThreadId,
             0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: p_m_ForceLockMutex, a2: pModelName, a3: 0);
      }
      else
      {
        ++p_m_ForceLockMutex->m_depth;
      }
      v10 = pStudioData;
      if ( pStudioData->m_pForceLockedStudioHdr != nullptr )
      {
        v11 = p_m_ForceLockMutex->m_depth-- == 1;
        if ( v11 )
          _InterlockedExchange((volatile __int32 *)p_m_ForceLockMutex, 0);
        return v10->m_pForceLockedStudioHdr;
      }
      v2 = handle;
    }
    pHdra = (studiohdr_t *)this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem->m_MDLCache;
    v12 = this->GetCacheSection(this, a2: 0);
    pHdr = (studiohdr_t *)v12->Get(this: v12, a2: (memhandle_t__ *)pHdra, a3: true);
    if ( pHdr != nullptr )
    {
      m_pParent = mod_lock_mdls_on_load.m_pParent;
      if ( mod_lock_mdls_on_load.m_pParent == nullptr )
        return pHdr;
      if ( mod_lock_mdls_on_load.m_pParent->m_Value.m_nValue == 0 )
      {
LABEL_35:
        if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
        {
          v19 = &pStudioData->m_ForceLockMutex;
          v11 = pStudioData->m_ForceLockMutex.m_depth-- == 1;
          if ( v11 )
            _InterlockedExchange((volatile __int32 *)v19, 0);
        }
        return pHdr;
      }
      v18 = this->GetCacheSection(this, a2: 0);
      v18->Lock(this: v18, a2: this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem->m_MDLCache);
      this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem->m_pForceLockedStudioHdr = pHdr;
    }
    else
    {
      this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem->m_MDLCache = nullptr;
      this->BeginLock(this);
      ActualModelName = CMDLCache::GetActualModelName(this, handle: (unsigned __int16)v2);
      v14 = developer.m_pConVarState->m_Value.m_nValue <= 1;
      pModelName = ActualModelName;
      if ( !v14 )
      {
        DevMsg(a1: "Loading %s\n", ActualModelName);
        ActualModelName = pModelName;
      }
      memset(&cacheData, 0, sizeof(cacheData));
      if ( CMDLCache::ReadMDLFile(this, handle: (unsigned __int16)v2, pMDLFileName: ActualModelName, &cacheData) == 0 )
      {
        v15 = this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
        if ( (v15->m_nFlags & 4) != 0
          || (v15->m_nFlags |= 4u,
              CMDLCache::ReadMDLFile(this, handle: (unsigned __int16)v2, pMDLFileName: "models/error.mdl", &cacheData) == 0) )
        {
          _Error(a1: "Model %s not found and %s couldn't be loaded", pModelName, "models/error.mdl");
          if ( mod_lock_mdls_on_load.m_pParent != nullptr && mod_lock_mdls_on_load.m_pParent->m_Value.m_nValue != 0 )
          {
            v16 = &pStudioData->m_ForceLockMutex;
            v11 = pStudioData->m_ForceLockMutex.m_depth-- == 1;
            if ( v11 )
              _InterlockedExchange((volatile __int32 *)v16, 0);
          }
          CMDLCacheData::Purge(this: &cacheData);
          this->EndLock(this);
          return nullptr;
        }
      }
      if ( CMDLCache::ProcessDataIntoCache(this, handle: v2, (studiohdr_t *)&cacheData, iAnimBlock: 0) != 0 )
        pHdr = (studiohdr_t *)CMDLCache::CheckData(
                                this,
                                c: this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem->m_MDLCache,
                                type: MDLCACHE_STUDIOHDR);
      CMDLCacheData::Purge(this: &cacheData);
      this->EndLock(this);
    }
    m_pParent = mod_lock_mdls_on_load.m_pParent;
    goto LABEL_35;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000FFA0
// Name: public: struct studiohdr_t const __near * studiohdr_t::FindModel(void __near * __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall studiohdr_t::FindModel(studiohdr_t *this, void **cache, const char *pModelName)
{
  unsigned __int16 MDL; // ax

  MDL = CMDLCache::FindMDL(this: &g_MDLCache, pMDLRelativePath: pModelName);
  *cache = (void *)MDL;
  return CMDLCache::GetStudioHdr(this: &g_MDLCache, handle: (studiohdr_t *)MDL);
}

//------------------------------------------------------------------------------
// Address: 0x1000FFD0
// Name: public: struct studiohdr_t const __near * virtualgroup_t::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall virtualgroup_t::GetStudioHdr(virtualgroup_t *this)
{
  return CMDLCache::GetStudioHdr(this: &g_MDLCache, handle: (studiohdr_t *)LOWORD(this->cache));
}

//------------------------------------------------------------------------------
// Address: 0x1000FFE0
// Name: CleanupMaterialSystemObjects
// Source: json
//------------------------------------------------------------------------------
void CleanupMaterialSystemObjects()
{
  CMDLCache::UnloadQueuedHardwareData(this: &g_MDLCache);
}

//------------------------------------------------------------------------------
// Address: 0x1000FFF0
// Name: public: virtual bool CMDLCache::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMDLCache::Connect(CMDLCache *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v3)(const char *, int *); // esi
  IPhysicsSurfaceProps *v4; // eax
  void *(__cdecl *v6)(const char *, int *); // [esp+4h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 160) & 2) == 0 )
  {
    v3 = factory;
    v6 = factory;
    pFactoryList = factory;
    ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
    ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
    CDataManagerBase::Unlock(pFactoryList: &v6, nFactoryCount: 1);
    v4 = (IPhysicsSurfaceProps *)v3(a1: "VPhysicsSurfaceProps001", a2: nullptr);
    *((_BYTE *)this + 160) |= 2u;
    physprops = v4;
    if ( g_pMaterialSystem != nullptr )
    {
      g_pMaterialSystem->AddReleaseFunc(this: g_pMaterialSystem, a2: ReleaseMaterialSystemObjects);
      g_pMaterialSystem->AddRestoreFunc(
        this: g_pMaterialSystem,
        a2: (void (__cdecl *)(int))RestoreMaterialSystemObjects);
      g_pMaterialSystem->AddEndFrameCleanupFunc(this: g_pMaterialSystem, a2: CleanupMaterialSystemObjects);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100100A0
// Name: public: virtual void CMDLCache::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10010110
// Name: public: virtual void CMDLCache::MarkAsLoaded(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::MarkAsLoaded(CMDLCache *this, studiohdr_t *handle)
{
  IDataCacheSection *v3; // eax
  studiodata_t **p_elem; // edi
  IDataCacheSection *v5; // eax
  studiodata_t **v6; // esi

  if ( mod_lock_mdls_on_load.m_pParent != nullptr && mod_lock_mdls_on_load.m_pParent->m_Value.m_nValue != 0 )
  {
    CMDLCache::GetStudioHdr(this: &g_MDLCache, handle);
    if ( this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem->m_pForceLockedStudioHdr == nullptr )
    {
      v3 = this->GetCacheSection(this, a2: 0);
      p_elem = &this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
      (*p_elem)->m_pForceLockedStudioHdr = (studiohdr_t *)v3->Lock(this: v3, a2: (*p_elem)->m_MDLCache);
    }
  }
  if ( (mod_dont_load_vertices.m_pParent == nullptr || mod_dont_load_vertices.m_pParent->m_Value.m_nValue == 0)
    && (mod_load_mesh_async.m_pParent == nullptr || mod_load_mesh_async.m_pParent->m_Value.m_nValue == 0)
    && mod_lock_meshes_on_load.m_pParent != nullptr
    && mod_lock_meshes_on_load.m_pParent->m_Value.m_nValue != 0
    && (this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem->m_nFlags & 0x10) == 0 )
  {
    this->GetVertexData(this, a2: (unsigned __int16)handle);
    if ( this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem->m_pForceLockedVertexFileHeader == nullptr )
    {
      v5 = this->GetCacheSection(this, a2: 5);
      v6 = &this->m_MDLDict.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)handle].m_Data.elem;
      (*v6)->m_pForceLockedVertexFileHeader = (vertexFileHeader_t *)v5->Lock(this: v5, a2: (*v6)->m_VertexCache);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100103A0
// Name: public: virtual void CMDLCache::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCache::Reconnect(
        CBaseAppSystem<IDataCache> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x100112E0
// Name: public: void CUtlHash<struct CModelSwapper::ModelSubstitution_t,bool (*)(struct CModelSwapper::ModelSubstitution_t const __near &,struct CModelSwapper::ModelSubstitution_t const __near &),unsigned int (*)(struct CModelSwapper::ModelSubstitution_t const __near &)>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl *)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl *)(CModelSwapper::ModelSubstitution_t const &)>::Purge(
        CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl*)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl*)(CModelSwapper::ModelSubstitution_t const &)> *this)
{
  int v1; // edi
  int m_Size; // ebx
  CUtlVector<CModelSwapper::ModelSubstitution_t,CUtlMemory<CModelSwapper::ModelSubstitution_t,int> > *v3; // esi
  CUtlHash<CModelSwapper::ModelSubstitution_t,bool (__cdecl*)(CModelSwapper::ModelSubstitution_t const &,CModelSwapper::ModelSubstitution_t const &),unsigned int (__cdecl*)(CModelSwapper::ModelSubstitution_t const &)> *v4; // [esp+0h] [ebp-4h]

  v4 = this;
  if ( this->m_Buckets.m_Size > 0 )
  {
    v1 = 0;
    m_Size = this->m_Buckets.m_Size;
    do
    {
      v3 = &this->m_Buckets.m_Memory.m_pMemory[v1];
      v3->m_Size = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      ++v1;
      --m_Size;
      v3->m_pElements = v3->m_Memory.m_pMemory;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016FA0
// Name: public: void CUtlMemory<struct CModelSwapper::ModelSubstitution_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CModelSwapper::ModelSubstitution_t,int>::Grow(
        CUtlMemory<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017300
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
// Address: 0x10017370
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
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
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
// Address: 0x100174F0
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
// Address: 0x10017810
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
// Address: 0x10017930
// Name: protected: virtual bool CRefCountServiceBase<1,class CRefMT>::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRefCountServiceBase<1,CRefMT>::OnFinalRelease(CDataManagerBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100054A0
// Name: __CreateCMDLCacheIMDLCache_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMDLCache *__cdecl _CreateCMDLCacheIMDLCache_interface()
{
  return &g_MDLCache;
}

//------------------------------------------------------------------------------
// Address: 0x100054B0
// Name: __CreateCMDLCacheIStudioDataCache_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IStudioDataCache *__cdecl _CreateCMDLCacheIStudioDataCache_interface()
{
  return &g_MDLCache.IStudioDataCache;
}

//------------------------------------------------------------------------------
// Address: 0x10010210
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
