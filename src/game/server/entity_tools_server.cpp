// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/entity_tools_server.cpp
// Functions: 135
// ============================================================

#include "game\server\entity_tools_server.h"

//------------------------------------------------------------------------------
// Address: 0x1001EA00
// Name: public: void CUtlMemory<struct ScriptedNPCInteraction_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ScriptedNPCInteraction_t,int>::Grow(CUtlMemory<ScriptedNPCInteraction_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ScriptedNPCInteraction_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 180 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ScriptedNPCInteraction_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ScriptedNPCInteraction_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045170
// Name: protected: int CUtlLinkedList<struct AI_Follower_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AI_Follower_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::AllocInternal(
        CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 72);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 72) = 0;
      *(_DWORD *)(result + 68) = 0;
    }
    else
    {
      *(_DWORD *)(result + 72) = result;
      *(_DWORD *)(result + 68) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
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
    CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
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
      if ( `CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)((char *)v8 + 76 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 76 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10045640
// Name: public: void CUtlLinkedList<struct AI_Follower_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AI_Follower_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::RemoveAll(
        CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > > *this)
{
  CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

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
          i = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
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
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)((char *)m_pBlockHeader
                                                                                         + 76 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[1] + 76 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t **)&m_pBlockHeader[9].m_nBlockSize
               + 19 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 76 * m_nIndex)
            && *(&m_pBlockHeader[10].m_pNext + 19 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 76 * m_nIndex) )
          {
            v1 = (CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[9].m_nBlockSize + 19 * m_nIndex) = (int)m_pBlockHeader + 76 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[10].m_pNext + 19 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 76 * m_nIndex;
            v1 = (CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > > *)v5;
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
// Address: 0x10045D80
// Name: public: void CUtlLinkedList<struct AI_Follower_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AI_Follower_t,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::Free(
        CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 68);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 72) = *(_DWORD *)(elem + 72);
      else
        this->m_Head = *(_DWORD *)(elem + 72);
      v4 = *(_DWORD *)(elem + 72);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 68) = *(_DWORD *)(elem + 68);
      else
        this->m_Tail = *(_DWORD *)(elem + 68);
      *(_DWORD *)(elem + 72) = elem;
      *(_DWORD *)(elem + 68) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 72) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x10045DF0
// Name: public: void CUtlLinkedList<struct AI_Follower_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct AI_Follower_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>>::LinkBefore(
        CUtlLinkedList<AI_Follower_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 68);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 72) = *(_DWORD *)(elem + 72);
      else
        this->m_Head = *(_DWORD *)(elem + 72);
      v5 = *(_DWORD *)(elem + 72);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 68) = *(_DWORD *)(elem + 68);
      else
        this->m_Tail = *(_DWORD *)(elem + 68);
      *(_DWORD *)(elem + 72) = elem;
      *(_DWORD *)(elem + 68) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 72) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 68);
    *(_DWORD *)(before + 68) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 68) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 72) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100634F0
// Name: public: void CUtlMemory<struct AI_Waypoint_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<AI_Waypoint_t,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078220
// Name: public: void CUtlLinkedList<struct CAI_PlaneSolver::CircleObstacles_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CAI_PlaneSolver::CircleObstacles_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAI_PlaneSolver::CircleObstacles_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int>>>::RemoveAll(
        CUtlLinkedList<CAI_PlaneSolver::CircleObstacles_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[4 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[4 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[4 * m_nIndex + 4].m_pNext == &m_pBlockHeader[4 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *)m_pBlockHeader[4 * m_nIndex + 4].m_nBlockSize != &m_pBlockHeader[4 * m_nIndex + 1] )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[4 * m_nIndex + 4].m_pNext = &m_pBlockHeader[4 * m_nIndex + 1];
            m_pBlockHeader[4 * m_nIndex + 4].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[4 * m_nIndex + 1];
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x10078410
// Name: public: void CUtlLinkedList<struct CAI_PlaneSolver::CircleObstacles_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CAI_PlaneSolver::CircleObstacles_t,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAI_PlaneSolver::CircleObstacles_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int>>>::Free(
        CUtlLinkedList<CAI_PlaneSolver::CircleObstacles_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 24);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 28) = *(_DWORD *)(elem + 28);
      else
        this->m_Head = *(_DWORD *)(elem + 28);
      v4 = *(_DWORD *)(elem + 28);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 24) = *(_DWORD *)(elem + 24);
      else
        this->m_Tail = *(_DWORD *)(elem + 24);
      *(_DWORD *)(elem + 28) = elem;
      *(_DWORD *)(elem + 24) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 28) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x1008A6D0
// Name: protected: int CUtlLinkedList<struct CResponseQueue::CDeferredResponse,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::AllocInternal(
        CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 64);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 64) = 0;
      *(_DWORD *)(result + 60) = 0;
    }
    else
    {
      *(_DWORD *)(result + 64) = result;
      *(_DWORD *)(result + 60) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)((char *)v8 + 68 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 68 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A940
// Name: public: void CUtlLinkedList<struct CResponseQueue::CDeferredResponse,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::LinkBefore(
        CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 60);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 64) = *(_DWORD *)(elem + 64);
      else
        this->m_Head = *(_DWORD *)(elem + 64);
      v5 = *(_DWORD *)(elem + 64);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 60) = *(_DWORD *)(elem + 60);
      else
        this->m_Tail = *(_DWORD *)(elem + 60);
      *(_DWORD *)(elem + 64) = elem;
      *(_DWORD *)(elem + 60) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 64) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 60);
    *(_DWORD *)(before + 60) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 60) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 64) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B1B0
// Name: public: void CUtlLinkedList<struct CResponseQueue::CDeferredResponse,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CResponseQueue::CDeferredResponse,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>>::RemoveAll(
        CUtlLinkedList<CResponseQueue::CDeferredResponse,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)((char *)m_pBlockHeader + 68 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[1] + 68 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t **)&m_pBlockHeader[8].m_nBlockSize
               + 17 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 68 * m_nIndex)
            && *(&m_pBlockHeader[9].m_pNext + 17 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 68 * m_nIndex) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)p_m_Memory;
          }
          else
          {
            CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: (CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl*)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short> > *)((char *)&m_pBlockHeader[2] + 68 * m_nIndex));
            v5 = p_m_Memory;
            *(&m_pBlockHeader[8].m_nBlockSize + 17 * m_nIndex) = (int)m_pBlockHeader + 68 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[9].m_pNext + 17 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 68 * m_nIndex;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x100AE710
// Name: protected: unsigned short CUtlLinkedList<class CBaseCombatWeapon __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CBaseCombatWeapon __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
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
      if ( `CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100B77D0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct VisibilityCacheEntry_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short> *m_pMemory; // edx
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: m_pMemory,
                                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF950
// Name: public: void CUtlMemory<class CAnimationLayer,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CAnimationLayer,int>::Grow(CUtlMemory<CAnimationLayer,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CAnimationLayer *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 76 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CAnimationLayer *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CAnimationLayer *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F56D0
// Name: public: void CUtlMemory<struct modifiedconvars_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<modifiedconvars_t,int>::Grow(CUtlMemory<modifiedconvars_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  modifiedconvars_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 384 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (modifiedconvars_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (modifiedconvars_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD330
// Name: public: void CUtlMemory<struct SaveRestoreBlockHeader_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SaveRestoreBlockHeader_t,int>::Grow(CUtlMemory<AIChannelScheduleState_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  AIChannelScheduleState_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (AIChannelScheduleState_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (AIChannelScheduleState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E860
// Name: public: virtual void __near * CServerTools::CreateEntityByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CServerTools::CreateEntityByName(CRespawnEntitiesFilter *this, const char *pClassname)
{
  return CreateEntityByName(className: pClassname, iForceEdictIndex: -1, bNotify: true);
}

//------------------------------------------------------------------------------
// Address: 0x10112360
// Name: public: void CUtlMemory<class CEffectScriptElement,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CEffectScriptElement,int>::Grow(CUtlMemory<CEffectScriptElement,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CEffectScriptElement *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 432 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CEffectScriptElement *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CEffectScriptElement *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011A770
// Name: protected: unsigned short CUtlLinkedList<class CEnvWindShared __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CEnvWindShared __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CEnvWindShared *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10130F10
// Name: protected: unsigned short CUtlLinkedList<class CFuncAreaPortalBase __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CFuncAreaPortalBase __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10142310
// Name: protected: unsigned short CUtlLinkedList<class CMapEntityRef,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMapEntityRef,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CMapEntityRef,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10142540
// Name: public: void CUtlLinkedList<class CRagdollEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short> *v2; // edx
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
// Address: 0x101425B0
// Name: public: void CUtlLinkedList<class CRagdollEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CRagdollEntry,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CMapEntityRef,unsigned short> *v3; // eax
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
// Address: 0x10143110
// Name: public: void CUtlLinkedList<class CMapEntityRef,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMapEntityRef,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CMapEntityRef,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CMapEntityRef,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CMapEntityRef,unsigned short> *v7; // ebx

  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x10161C90
// Name: protected: int CUtlLinkedList<class CInfoCameraLink __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CInfoCameraLink __near *,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::AllocInternal(
        CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101620F0
// Name: public: void CUtlLinkedList<class CInfoCameraLink __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CInfoCameraLink __near *,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::RemoveAll(
        CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)((char *)m_pBlockHeader
                                                                                             + 12 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[1] + 12 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t **)&m_pBlockHeader[1].m_nBlockSize
               + 3 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 12 * m_nIndex)
            && *(&m_pBlockHeader[2].m_pNext + 3 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 12 * m_nIndex) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[1].m_nBlockSize + 3 * m_nIndex) = (int)m_pBlockHeader + 12 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[2].m_pNext + 3 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 12 * m_nIndex;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x10162280
// Name: public: void CUtlLinkedList<class CInfoCameraLink __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CInfoCameraLink __near *,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::Free(
        CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>::IsIdxAfter(
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
// Address: 0x101622F0
// Name: public: void CUtlLinkedList<class CInfoCameraLink __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CInfoCameraLink __near *,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::LinkBefore(
        CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>::IsIdxAfter(
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
// Address: 0x10162660
// Name: public: static class CUtlLinkedList<class CInfoRemarkable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CInfoRemarkable __near *,unsigned short>,unsigned short>> __near * CInfoRemarkable::GetListOfAllThatIsRemarkable(void)
// Source: json
//------------------------------------------------------------------------------
CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short> > *__cdecl CInfoRemarkable::GetListOfAllThatIsRemarkable()
{
  return &g_RemarkableList.m_list;
}

//------------------------------------------------------------------------------
// Address: 0x10162680
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CInfoRemarkable __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: m_pMemory,
                                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162730
// Name: protected: unsigned short CUtlLinkedList<class CInfoRemarkable __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CInfoRemarkable __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CInfoRemarkable *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CInfoRemarkable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10176430
// Name: public: void CUtlMemory<struct VoiceCommandMenuItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VoiceCommandMenuItem_t,int>::Grow(CUtlMemory<VoiceCommandMenuItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VoiceCommandMenuItem_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 72 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VoiceCommandMenuItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (VoiceCommandMenuItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181AB0
// Name: public: void CUtlMemory<struct constraint_anchor_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<constraint_anchor_t,int>::Grow(CUtlMemory<CEventAbsoluteTag,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CEventAbsoluteTag *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CEventAbsoluteTag *)_g_pMemAlloc->Realloc_2(
                                               this: _g_pMemAlloc,
                                               a2: m_pMemory,
                                               a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CEventAbsoluteTag *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101859B0
// Name: public: void CUtlMemory<struct vehiclescript_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vehiclescript_t,int>::Grow(CUtlMemory<vehiclescript_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vehiclescript_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 916 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vehiclescript_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vehiclescript_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101865D0
// Name: public: void CUtlMemory<struct touchevent_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<touchevent_t,int>::Grow(CUtlMemory<CAI_InterestTarget_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CAI_InterestTarget_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CAI_InterestTarget_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CAI_InterestTarget_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191F10
// Name: public: void CUtlMemory<struct damageevent_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<damageevent_t,int>::Grow(CUtlMemory<damageevent_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  damageevent_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 104 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (damageevent_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (damageevent_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196290
// Name: public: void CUtlMemory<class CUtlVector<class CNavArea __near *,class CUtlMemory<class CNavArea __near *,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196DA0
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
// Address: 0x10196E10
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
// Address: 0x10196EA0
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct watcher_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct watcher_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short> *v9; // ecx

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
      (CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101B8890
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CPlayerSimInfo,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                this: _g_pMemAlloc,
                                                                                a2: m_pMemory,
                                                                                a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                this: _g_pMemAlloc,
                                                                                a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8940
// Name: public: void CUtlMemory<class CUserCmd,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUserCmd,int>::Grow(CUtlMemory<CUserCmd,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUserCmd *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 88 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUserCmd *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUserCmd *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BAE00
// Name: public: void CUtlLinkedList<class CPlayerSimInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPlayerSimInfo,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *v2; // edx
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
// Address: 0x101BAE70
// Name: public: void CUtlLinkedList<class CPlayerCmdInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPlayerCmdInfo,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short> *v2; // esi
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
// Address: 0x101BAF10
// Name: protected: unsigned short CUtlLinkedList<class CPlayerSimInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPlayerSimInfo,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101BB0F0
// Name: protected: unsigned short CUtlLinkedList<class CPlayerCmdInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPlayerCmdInfo,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short> *v11; // ecx

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
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101BD820
// Name: public: void CUtlLinkedList<class CPlayerSimInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPlayerSimInfo,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *v3; // eax
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
// Address: 0x101BD8B0
// Name: public: void CUtlLinkedList<class CPlayerCmdInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPlayerCmdInfo,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CPlayerCmdInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CPlayerCmdInfo,unsigned short> *v3; // eax
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
// Address: 0x101C1400
// Name: public: void CUtlLinkedList<class CPlayerSimInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPlayerSimInfo,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *v7; // ebx

  CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x101C6640
// Name: public: unsigned short CUtlLinkedList<class CPlayerSimInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPlayerSimInfo,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax
  UtlLinkedListElem_t<CPlayerSimInfo,unsigned short> *v4; // eax

  v2 = (unsigned __int16)CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CPlayerSimInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPlayerSimInfo,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
    {
      *(_QWORD *)&v4->m_Element.m_flTime = 0;
      v4->m_Element.m_nTicksCorrected = 0;
      v4->m_Element.m_flFinalSimulationTime = 0.0;
      v4->m_Element.m_flGameSimulationTime = 0.0;
      v4->m_Element.m_flServerFrameTime = 0.0;
      v4->m_Element.m_vecAbsOrigin.x = 0.0;
      v4->m_Element.m_vecAbsOrigin.y = 0.0;
      v4->m_Element.m_vecAbsOrigin.z = 0.0;
    }
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C8DE0
// Name: public: void CUtlLinkedList<struct LagRecord,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LagRecord,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::Unlink(
        CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > > *this,
        int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 304) != elem )
  {
    v3 = *(_DWORD *)(elem + 304);
    v4 = *(_DWORD *)(elem + 308);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 308) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 304) = v3;
    else
      this->m_Tail = v3;
    --this->m_ElementCount;
    *(_DWORD *)(elem + 308) = elem;
    *(_DWORD *)(elem + 304) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8E50
// Name: protected: int CUtlLinkedList<struct LagRecord,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LagRecord,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *__thiscall CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::AllocInternal(
        CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[38].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[38].m_nBlockSize = 0;
      result[38].m_pNext = nullptr;
    }
    else
    {
      result[38].m_nBlockSize = (int)result;
      result[38].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
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
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[39 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[39 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101CA660
// Name: public: void CUtlLinkedList<struct LagRecord,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LagRecord,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::RemoveAll(
        CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CResponseQueue::CDeferredResponse,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[39 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[39 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[39 * m_nIndex + 39].m_pNext == &m_pBlockHeader[39 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)m_pBlockHeader[39 * m_nIndex + 39].m_nBlockSize != &m_pBlockHeader[39 * m_nIndex + 1] )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[39 * m_nIndex + 39].m_pNext = &m_pBlockHeader[39 * m_nIndex + 1];
            m_pBlockHeader[39 * m_nIndex + 39].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[39 * m_nIndex + 1];
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<AI_Follower_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
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
// Address: 0x101CDDD0
// Name: public: int CUtlLinkedList<struct LagRecord,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LagRecord,int>>>::AddToHead(void)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *__thiscall CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::AddToHead(
        CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int> >::BlockHeader_t *v3; // esi
  int m_nBlockSize; // eax

  result = CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != nullptr )
  {
    if ( !CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>::IsIdxAfter(
            this: &this->m_Memory,
            i: (int)result,
            it: &this->m_LastAlloc)
      && v3[38].m_pNext != v3 )
    {
      CUtlLinkedList<LagRecord,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LagRecord,int>>>::Unlink(
        this,
        elem: (int)v3);
    }
    v3[38].m_pNext = nullptr;
    v3[38].m_nBlockSize = this->m_Head;
    this->m_Head = (int)v3;
    m_nBlockSize = v3[38].m_nBlockSize;
    if ( m_nBlockSize != 0 )
    {
      *(_DWORD *)(m_nBlockSize + 304) = v3;
      ++this->m_ElementCount;
    }
    else
    {
      ++this->m_ElementCount;
      this->m_Tail = (int)v3;
    }
    LagRecord::LagRecord(this: (LagRecord *)v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EE7E0
// Name: public: void CUtlMemory<struct breakmodel_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<breakmodel_t,int>::Grow(CUtlMemory<breakmodel_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  breakmodel_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 1068 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (breakmodel_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (breakmodel_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF0C0
// Name: public: void CUtlLinkedList<class CEnvWindShared __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CEnvWindShared __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *v2; // esi
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
// Address: 0x101EF130
// Name: protected: unsigned short CUtlLinkedList<class CHandle<class CBaseAnimating>,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CHandle<class CBaseAnimating>,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CHandle<CBaseAnimating>,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CHandle<CBaseAnimating>,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CHandle<CBaseAnimating>,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CHandle<CBaseAnimating>,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CHandle<CBaseAnimating>,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CHandle<CBaseAnimating>,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101F2260
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CRagdollEntry,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // edx
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<void *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<void *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3250
// Name: protected: unsigned short CUtlLinkedList<class CRagdollEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10200360
// Name: public: void CUtlMemory<struct NPCInterjection,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<NPCInterjection,int>::Grow(CUtlMemory<NPCInterjection,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  NPCInterjection *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 172 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (NPCInterjection *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (NPCInterjection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B290
// Name: public: void CUtlMemory<struct AsyncCaption_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<AsyncCaption_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231AD0
// Name: public: void CUtlMemory<struct grouptemplate_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<grouptemplate_t,int>::Grow(CUtlMemory<grouptemplate_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  grouptemplate_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 2060 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (grouptemplate_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (grouptemplate_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10282D90
// Name: protected: int CUtlLinkedList<class CDamageRecord __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CDamageRecord __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::AllocInternal(
        CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CDamageRecord *,int> *v8; // ecx

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
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
      if ( `CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1028A720
// Name: public: void CUtlLinkedList<class CDamageRecord __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CDamageRecord __near *,int>,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::PurgeAndDeleteElements(
        CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int> > *this)
{
  int m_Head; // eax
  int v3; // eax
  int m_Next; // edi
  UtlLinkedListElem_t<CDamageRecord *,int> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != -1 )
  {
    do
    {
      v3 = m_Head;
      m_Next = this->m_Memory.m_pMemory[v3].m_Next;
      free(pMem: this->m_Memory.m_pMemory[v3].m_Element);
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
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_NumAlloced = 0;
  this->m_FirstFree = -1;
  this->m_LastAlloc.index = -1;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x102A80A0
// Name: public: void CUtlMemory<class CNavLadder __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CNavLadder *,int>::Grow(CUtlMemory<vgui::TreeNode *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::TreeNode **m_pMemory; // edx
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
      this->m_pMemory = (vgui::TreeNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::TreeNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CA5B0
// Name: public: void CUtlLinkedList<class CFuncAreaPortalBase __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CFuncAreaPortalBase __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *m_pMemory; // eax
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
// Address: 0x102CD850
// Name: protected: unsigned short CUtlLinkedList<class ActiveGrenade __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class ActiveGrenade __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x102CE000
// Name: public: void CUtlLinkedList<class ActiveGrenade __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class ActiveGrenade __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
      free(pMem: this->m_Memory.m_pMemory[m_Head].m_Element);
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)this);
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
// Address: 0x102CE810
// Name: protected: unsigned short CUtlLinkedList<class BotProfile __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class BotProfile __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<BotProfile *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x102CEAE0
// Name: public: void CUtlLinkedList<class CEnvWindShared __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CEnvWindShared __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *v7; // ebx

  CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x102CEEF0
// Name: public: void CUtlLinkedList<class BotProfile __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class BotProfile __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  unsigned __int16 m_Next; // cx
  BotProfile *m_Element; // esi
  const BotProfile **m_pMemory; // eax
  UtlLinkedListElem_t<BotProfile *,unsigned short> *v6; // ecx
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
        if ( m_Element->m_name != nullptr )
          free(pMem: m_Element->m_name);
        m_Element->m_templates.m_Size = 0;
        if ( m_Element->m_templates.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_Element->m_templates.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_templates.m_Memory.m_pMemory);
            m_Element->m_templates.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_templates.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = m_Element->m_templates.m_Memory.m_pMemory;
        m_Element->m_templates.m_pElements = m_pMemory;
        if ( m_Element->m_templates.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            m_Element->m_templates.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_templates.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: (void *)m_Element);
        m_Next = iNext;
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)this);
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
  v6 = this->m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NumAlloced = -65536;
  this->m_pElements = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10309D70
// Name: protected: unsigned short CUtlLinkedList<class CFuncNavBlocker __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CFuncNavBlocker __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CInfoRemarkable *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1030A460
// Name: public: bool CUtlLinkedList<class CFuncNavBlocker __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CFuncNavBlocker __near *,unsigned short>,unsigned short>>::FindAndRemove(class CFuncNavBlocker __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::FindAndRemove(
        CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *this,
        CBaseCombatWeapon **src)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *m_pMemory; // edx

  m_Head = this->m_Head;
  if ( m_Head == 0xFFFF )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  while ( m_pMemory[m_Head].m_Element != *src )
  {
    m_Head = m_pMemory[m_Head].m_Next;
    if ( m_Head == 0xFFFF )
      return 0;
  }
  CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem: m_Head);
  this->m_Memory.m_pMemory[m_Head].m_Next = this->m_FirstFree;
  this->m_FirstFree = m_Head;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1030A9E0
// Name: public: void CUtlMemory<struct OneWayLink_t,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OneWayLink_t,int>::ConvertToGrowableMemory(
        CUtlMemory<OneWayLink_t,int> *this,
        int nGrowSize)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // esi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = nGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 12 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (OneWayLink_t *)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10336DF0
// Name: public: virtual bool CServerTools::GetPlayerPosition(class Vector __near &,class QAngle __near &,class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerTools::GetPlayerPosition(
        CServerTools *this,
        Vector *org,
        QAngle *ang,
        IClientEntity *pClientPlayer)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v5; // esi
  float *v7; // eax
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // edx
  Vector v9; // [esp+4h] [ebp-Ch] BYREF

  LocalPlayer = (CBasePlayer *)this->GetIServerEntity(this, a2: pClientPlayer);
  if ( LocalPlayer == nullptr )
    LocalPlayer = UTIL_GetLocalPlayer();
  v5 = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return 0;
  v7 = (float *)LocalPlayer->EyePosition(this: LocalPlayer, result: &v9);
  org->x = *v7;
  org->y = v7[1];
  EyeAngles = v5->EyeAngles;
  org->z = v7[2];
  *ang = *EyeAngles(this: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10336E70
// Name: public: virtual bool CServerTools::SnapPlayerToPosition(class Vector const __near &,class QAngle const __near &,class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerTools::SnapPlayerToPosition(
        CServerTools *this,
        const Vector *org,
        const QAngle *ang,
        IClientEntity *pClientPlayer)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v5; // esi
  float *v7; // eax
  Vector absOrigin; // [esp+4h] [ebp-Ch] BYREF

  LocalPlayer = (CBasePlayer *)this->GetIServerEntity(this, a2: pClientPlayer);
  if ( LocalPlayer == nullptr )
    LocalPlayer = UTIL_GetLocalPlayer();
  v5 = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return 0;
  v7 = (float *)LocalPlayer->GetViewOffset(this: LocalPlayer);
  absOrigin.x = org->x - *v7;
  absOrigin.y = org->y - v7[1];
  absOrigin.z = org->z - v7[2];
  CBaseEntity::SetAbsOrigin(this: v5, &absOrigin);
  CBasePlayer::SnapEyeAngles(this: v5, viewAngles: ang);
  v5->SetParent(this: v5, a2: nullptr, a3: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10336F10
// Name: public: virtual int CServerTools::GetPlayerFOV(class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CServerTools::GetPlayerFOV(CServerTools *this, IClientEntity *pClientPlayer)
{
  CBasePlayer *result; // eax

  result = (CBasePlayer *)this->GetIServerEntity(this, a2: pClientPlayer);
  if ( result != nullptr )
    return (CBasePlayer *)CBasePlayer::GetFOV(this: result);
  result = UTIL_GetLocalPlayer();
  if ( result != nullptr )
    return (CBasePlayer *)CBasePlayer::GetFOV(this: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10336F40
// Name: public: virtual bool CServerTools::GetKeyValue(void __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerTools::GetKeyValue(
        CServerTools *this,
        void *pEntity,
        const char *szField,
        char *szValue,
        int iMaxLen)
{
  return (*(bool (__thiscall **)(void *, const char *, char *, int))(*(_DWORD *)pEntity + 140))(
           a1: pEntity,
           a2: szField,
           a3: szValue,
           a4: iMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x10336F60
// Name: public: virtual bool CServerTools::SetKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerTools::SetKeyValue(CServerTools *this, void *pEntity, const char *szField, const char *szValue)
{
  return (*(bool (__thiscall **)(void *, const char *, const char *))(*(_DWORD *)pEntity + 136))(
           a1: pEntity,
           a2: szField,
           a3: szValue);
}

//------------------------------------------------------------------------------
// Address: 0x10336F80
// Name: public: virtual bool CServerTools::SetKeyValue(void __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerTools::SetKeyValue(CServerTools *this, void *pEntity, const char *szField, float flValue)
{
  return (*(bool (__stdcall **)(const char *, _DWORD))(*(_DWORD *)pEntity + 132))(a1: szField, a2: LODWORD(flValue));
}

//------------------------------------------------------------------------------
// Address: 0x10336FB0
// Name: public: virtual bool CServerTools::SetKeyValue(void __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerTools::SetKeyValue(
        CServerTools *this,
        void *pEntity,
        const char *szField,
        const Vector *vecValue)
{
  return (*(bool (__thiscall **)(void *, const char *, const Vector *))(*(_DWORD *)pEntity + 124))(
           a1: pEntity,
           a2: szField,
           a3: vecValue);
}

//------------------------------------------------------------------------------
// Address: 0x10336FD0
// Name: public: virtual void CServerTools::DispatchSpawn(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerTools::DispatchSpawn(CServerTools *this, CBaseEntity *pEntity)
{
  DispatchSpawn(pEntity, bRunVScripts: true);
}

//------------------------------------------------------------------------------
// Address: 0x10336FF0
// Name: public: virtual bool CServerTools::DestroyEntityByHammerId(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerTools::DestroyEntityByHammerId(CServerTools *this, int iHammerID)
{
  CBaseEntity *v2; // eax

  v2 = (CBaseEntity *)this->FindEntityByHammerID(this, a2: iHammerID);
  if ( v2 == nullptr )
    return 0;
  UTIL_Remove(oldObj: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10337020
// Name: public: virtual void CServerTools::AddOriginToPVS(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerTools::AddOriginToPVS(CServerTools *this, const Vector *org)
{
  engine->AddOriginToPVS(this: engine, a2: org);
}

//------------------------------------------------------------------------------
// Address: 0x10337040
// Name: public: virtual void CServerTools::RemoveEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerTools::RemoveEntity(CServerTools *this, int nHammerID)
{
  CBaseEntity *v2; // eax

  v2 = (CBaseEntity *)this->FindEntityByHammerID(this, a2: nHammerID);
  if ( v2 != nullptr )
    UTIL_Remove(oldObj: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10337060
// Name: public: virtual void __near * CServerTools::FirstEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CServerTools::FirstEntity(CServerTools *this)
{
  return CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10337070
// Name: public: virtual void __near * CServerTools::NextEntity(void __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CServerTools::NextEntity(CServerTools *this, CBaseEntity *pEntity)
{
  if ( pEntity != nullptr )
    return CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: pEntity);
  else
    return CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103370A0
// Name: public: virtual void __near * CServerTools::FindEntityByHammerID(int)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CServerTools::FindEntityByHammerID(CServerTools *this, int iHammerID)
{
  CBaseEntity *result; // eax

  result = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
  if ( result == nullptr )
    return nullptr;
  while ( result->m_iHammerID != iHammerID )
  {
    result = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: result);
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103370E0
// Name: public: virtual void CServerTools::MoveEngineViewTo(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerTools::MoveEngineViewTo(CServerTools *this, const Vector *vPos, const QAngle *vAngles)
{
  CBasePlayer *ListenServerHost; // eax
  CBasePlayer *v4; // esi
  float *v5; // eax
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  Vector absOrigin; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  ListenServerHost = UTIL_GetListenServerHost();
  v4 = ListenServerHost;
  if ( ListenServerHost != nullptr )
  {
    EnableNoClip(pPlayer: ListenServerHost);
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
    v5 = (float *)v4->EyePosition(this: v4, result: &absOrigin);
    v6 = v5[2] - v4->m_vecAbsOrigin.z;
    v7 = vPos->x - (float)(*v5 - v4->m_vecAbsOrigin.x);
    absOrigin.y = vPos->y - (float)(v5[1] - v4->m_vecAbsOrigin.y);
    v8 = vPos->z - v6;
    absOrigin.x = v7;
    absOrigin.z = v8;
    CBaseEntity::SetAbsOrigin(this: v4, &absOrigin);
    CBasePlayer::SnapEyeAngles(this: v4, viewAngles: vAngles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103371A0
// Name: void CC_Ent_Keyvalue(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CC_Ent_Keyvalue(int a1@<edi>, const CCommand *args)
{
  int m_nArgc; // eax
  bool v3; // cc
  const char *v4; // eax
  int v5; // eax
  CBaseEntity *EntityByHammerID; // edi
  int v7; // eax
  int v8; // esi
  const char **v9; // ebx
  const char *v10; // ecx
  const char *v11; // eax

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 4 || (m_nArgc & 1) != 0 )
  {
    _Msg(a1: "Format: ent_keyvalue <entity id> \"key1\"=\"value1\" \"key2\" \"value2\" ... \"keyN\" \"valueN\"\n");
  }
  else
  {
    v3 = m_nArgc <= 1;
    v4 = locale;
    if ( !v3 )
      v4 = args->m_ppArgv[1];
    v5 = atoi(nptr: v4);
    EntityByHammerID = CServerTools::FindEntityByHammerID(this: &g_ServerTools, iHammerID: v5);
    if ( EntityByHammerID != nullptr )
    {
      v7 = args->m_nArgc;
      v8 = 2;
      if ( args->m_nArgc > 2 )
      {
        v9 = &args->m_ppArgv[2];
        do
        {
          if ( v8 < 0 || v8 >= v7 )
            v10 = locale;
          else
            v10 = *v9;
          if ( v8 + 1 < 0 || v8 + 1 >= v7 )
            v11 = locale;
          else
            v11 = v9[1];
          v8 += 2;
          v9 += 2;
          EntityByHammerID->KeyValue_4(this: EntityByHammerID, a2: v10, a3: v11);
          v7 = args->m_nArgc;
        }
        while ( v8 < args->m_nArgc );
      }
    }
    else
    {
      _Msg(a1: "Entity ID %d not found.\n", a1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10337270
// Name: public: virtual class IServerEntity __near * CServerTools::GetIServerEntity(class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseHandle *__thiscall CServerTools::GetIServerEntity(CServerTools *this, IClientEntity *pClientEntity)
{
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // ecx
  int v5; // eax

  if ( pClientEntity == nullptr )
    return nullptr;
  m_Index = pClientEntity->GetRefEHandle(this: pClientEntity)->m_Index;
  if ( m_Index == -1 )
    return nullptr;
  if ( (unsigned __int16)m_Index >= 0x800u )
    return nullptr;
  m_pEntity = gEntList.m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == nullptr )
    return nullptr;
  v5 = (unsigned __int16)m_Index | (gEntList.m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber << 16);
  if ( v5 == -1 || ((m_Index ^ v5) & 0x3FF0000) != 0 )
    return nullptr;
  else
    return m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x103372F0
// Name: public: virtual bool CServerTools::SetPlayerFOV(int,class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerTools::SetPlayerFOV(CServerTools *this, int fov, IClientEntity *pClientPlayer)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v4; // esi
  unsigned int m_Index; // eax
  CBaseEntity **v7; // ecx
  CBaseEntity *v8; // eax

  LocalPlayer = (CBasePlayer *)this->GetIServerEntity(this, a2: pClientPlayer);
  if ( LocalPlayer == nullptr )
    LocalPlayer = UTIL_GetLocalPlayer();
  v4 = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return false;
  CBasePlayer::SetDefaultFOV(this: LocalPlayer, FOV: fov);
  m_Index = v4->m_hZoomOwner.m_Value.m_Index;
  if ( m_Index == -1
    || (v7 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
    || (v8 = *v7, *v7 == nullptr) )
  {
    v8 = v4;
  }
  return CBasePlayer::SetFOV(this: v4, pRequester: v8, FOV: fov, zoomRate: 0.0, iZoomStart: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10337370
// Name: public: virtual bool CServerTools::IsInNoClipMode(class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerTools::IsInNoClipMode(CServerTools *this, IClientEntity *pClientPlayer)
{
  CBasePlayer *LocalPlayer; // eax

  LocalPlayer = (CBasePlayer *)this->GetIServerEntity(this, a2: pClientPlayer);
  return LocalPlayer == nullptr && (LocalPlayer = UTIL_GetLocalPlayer()) == nullptr
      || LocalPlayer->m_MoveType.m_Value == 8;
}

//------------------------------------------------------------------------------
// Address: 0x103373B0
// Name: protected: int CUtlLinkedList<class CFoundryEntitySpawnRecord __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CFoundryEntitySpawnRecord __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CFoundryEntitySpawnRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int>,int>>::AllocInternal(
        CUtlLinkedList<CFoundryEntitySpawnRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int> *v8; // ecx

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
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
      if ( `CUtlLinkedList<CFoundryEntitySpawnRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CFoundryEntitySpawnRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x103374E0
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
// Address: 0x10337560
// Name: public: virtual void CServerTools::ReloadParticleDefintions(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerTools::ReloadParticleDefintions(
        CServerTools *this,
        const char *pFileName,
        const void *pBufData,
        int nLen)
{
  CUtlBuffer buf; // [esp+0h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: pBufData, nSize: nLen, nFlags: 8);
  CParticleSystemMgr::ReadParticleConfigFile(
    this: g_pParticleSystemMgr,
    &buf,
    bPrecache: true,
    bDecommitTempMemory: true,
    pFileName: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103375B0
// Name: public: void CUtlLinkedList<class CFoundryEntitySpawnRecord __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CFoundryEntitySpawnRecord __near *,int>,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CFoundryEntitySpawnRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int>,int>>::PurgeAndDeleteElements(
        CUtlLinkedList<CFoundryEntitySpawnRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int>,int> > *this)
{
  int m_Head; // eax
  int v3; // eax
  CFoundryEntitySpawnRecord *m_Element; // esi
  int m_Next; // ecx
  char *m_pMemory; // eax
  UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int> *v7; // ecx
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
        m_Element->m_VMFText.m_Size = 0;
        if ( m_Element->m_VMFText.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_Element->m_VMFText.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Element->m_VMFText.m_Memory.m_pMemory);
            m_Element->m_VMFText.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_VMFText.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = m_Element->m_VMFText.m_Memory.m_pMemory;
        m_Element->m_VMFText.m_pElements = m_Element->m_VMFText.m_Memory.m_pMemory;
        if ( m_Element->m_VMFText.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            m_Element->m_VMFText.m_Memory.m_pMemory = nullptr;
          }
          m_Element->m_VMFText.m_Memory.m_nAllocationCount = 0;
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
  v7 = this->m_Memory.m_pMemory;
  this->m_NumAlloced = 0;
  this->m_FirstFree = -1;
  this->m_LastAlloc.index = -1;
  this->m_pElements = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10337670
// Name: void HandleFoundryEntitySpawnRecords(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleFoundryEntitySpawnRecords()
{
  int m_Head; // eax
  UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int> *m_pMemory; // ecx
  int v2; // ebx
  CFoundryEntitySpawnRecord *m_Element; // esi
  bool v4; // cc
  int m_iEntityIndex; // eax
  CBaseEntity *EntityByName; // edi
  const char *Next; // ebx
  int m_debugOverlays; // eax
  int v9; // eax
  char szClassName[2048]; // [esp+0h] [ebp-834h] BYREF
  CMapEntitySpawner spawner; // [esp+800h] [ebp-34h] BYREF
  int v12; // [esp+824h] [ebp-10h]
  CEntityMapData entData; // [esp+828h] [ebp-Ch] BYREF

  if ( g_FoundryEntitySpawnRecords.m_ElementCount != 0 )
  {
    CMapEntitySpawner::CMapEntitySpawner(this: &spawner);
    m_Head = g_FoundryEntitySpawnRecords.m_Head;
    spawner.m_bFoundryMode = true;
    if ( g_FoundryEntitySpawnRecords.m_Head != -1 )
    {
      m_pMemory = g_FoundryEntitySpawnRecords.m_Memory.m_pMemory;
      do
      {
        v2 = 12 * m_Head;
        m_Element = m_pMemory[m_Head].m_Element;
        v4 = m_Element->m_iEntityIndex <= 0;
        v12 = 12 * m_Head;
        if ( !v4 )
        {
          gEntList.m_EntPtrArray[m_Element->m_iEntityIndex].m_SerialNumber = m_Element->m_iSerialNumber;
          engine->ForceFlushEntity(this: engine, a2: m_Element->m_iEntityIndex);
        }
        entData.m_pEntData = m_Element->m_VMFText.m_Memory.m_pMemory;
        entData.m_pCurrentKey = entData.m_pEntData;
        entData.m_nEntDataSize = -1;
        if ( CEntityMapData::ExtractValue(this: &entData, keyName: "classname", value: szClassName) )
        {
          m_iEntityIndex = m_Element->m_iEntityIndex;
          if ( m_iEntityIndex == 0 )
            m_iEntityIndex = -1;
          EntityByName = CreateEntityByName(className: szClassName, iForceEdictIndex: m_iEntityIndex, bNotify: true);
          if ( EntityByName != nullptr )
          {
            Next = (const char *)CBaseTempEntity::GetNext(this: (CBaseAchievement *)&entData);
            CBaseEntity::ParseMapData(this: EntityByName, mapData: &entData);
            m_debugOverlays = m_Element->m_debugOverlays;
            if ( m_debugOverlays != -1 )
              EntityByName->m_debugOverlays = m_debugOverlays;
            EntityByName->m_iHammerID = m_Element->m_iHammerID;
            v9 = CBaseTempEntity::GetNext(this: (CBaseAchievement *)&entData);
            CMapEntitySpawner::AddEntity(
              this: &spawner,
              pEntity: EntityByName,
              pCurMapData: Next,
              iMapDataLength: 2 - (_DWORD)Next + v9);
            v2 = v12;
          }
          else
          {
            _Warning(
              a1: "HandleFoundryEntitySpawnRecords - CreateEntityByName( %s, %d ) failed\n",
              szClassName,
              m_Element->m_iEntityIndex);
          }
        }
        m_pMemory = g_FoundryEntitySpawnRecords.m_Memory.m_pMemory;
        m_Head = *(int *)((char *)&g_FoundryEntitySpawnRecords.m_Memory.m_pMemory->m_Next + v2);
      }
      while ( m_Head != -1 );
    }
    CMapEntitySpawner::HandleTemplates(this: &spawner);
    CMapEntitySpawner::SpawnAndActivate(this: &spawner, bActivateEntities: true);
    PrecachePointTemplates();
    CGlobalEntityList::CleanupDeleteList(this: &gEntList);
    CUtlLinkedList<CFoundryEntitySpawnRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int>,int>>::PurgeAndDeleteElements(this: &g_FoundryEntitySpawnRecords);
    CMapEntitySpawner::~CMapEntitySpawner(this: &spawner);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103377F0
// Name: public: virtual bool CServerTools::RespawnEntitiesWithEdits(class CEntityRespawnInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerTools::RespawnEntitiesWithEdits(CServerTools *this, CEntityRespawnInfo *pInfos, int nInfos)
{
  CUtlMemory<unsigned char,int> *v3; // esi
  int v4; // ebx
  CUtlMemory<unsigned char,int> *v5; // eax
  int v6; // eax
  int v7; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v10; // eax
  void *v11; // eax
  CBaseEntity *v12; // edi
  signed int v13; // eax
  int v14; // eax
  int v15; // edi
  UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int> *v16; // ecx
  int v17; // eax
  int m_Tail; // edx
  bool v19; // zf
  UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int> *v20; // eax
  int i; // [esp+Ch] [ebp-4h]

  v3 = nullptr;
  v4 = 0;
  i = 0;
  if ( nInfos > 0 )
  {
    while ( 1 )
    {
      v5 = (CUtlMemory<unsigned char,int> *)operator new(nSize: 0x24u);
      if ( v5 != nullptr )
      {
        v5->m_pMemory = nullptr;
        v5->m_nAllocationCount = 0;
        v5->m_nGrowSize = 0;
        v5[1].m_pMemory = nullptr;
        v5[1].m_nAllocationCount = 0;
        v3 = v5;
      }
      v6 = _V_strlen(str: pInfos[v4].m_pEntText);
      v7 = v6 + 1;
      v3[1].m_pMemory = nullptr;
      if ( v6 != -1 )
      {
        m_nAllocationCount = v3->m_nAllocationCount;
        if ( v7 > m_nAllocationCount )
          CUtlMemory<bool,int>::Grow(this: v3, num: v7 - m_nAllocationCount);
        v3[1].m_pMemory += v7;
        m_pMemory = (char *)v3->m_pMemory;
        v10 = (int)&v3[1].m_pMemory[-v7];
        v3[1].m_nAllocationCount = (int)v3->m_pMemory;
        if ( v10 > 0 && v7 > 0 )
          _V_memmove(dest: &m_pMemory[v7], src: m_pMemory, count: v10);
      }
      V_strncpy(pDest: (char *)v3->m_pMemory, pSrc: pInfos[v4].m_pEntText, maxLen: (int)v3[1].m_pMemory);
      v3[2].m_pMemory = (unsigned __int8 *)pInfos[v4].m_nHammerID;
      v11 = this->FindEntityByHammerID(this, a2: pInfos[v4].m_nHammerID);
      v12 = (CBaseEntity *)v11;
      if ( v11 != nullptr )
      {
        v13 = *((_DWORD *)v11 + 6);
        if ( v13 != 0 )
          v13 = (signed int)(v13 - (unsigned int)gpGlobals->pEdicts) >> 4;
        v3[1].m_nGrowSize = v13;
        v3[2].m_nAllocationCount = HIWORD(v12->GetRefEHandle(this: v12)->m_Index);
        v3[2].m_nGrowSize = v12->m_debugOverlays;
        UTIL_Remove(oldObj: v12);
      }
      else
      {
        v3[1].m_nGrowSize = -1;
        v3[2].m_nAllocationCount = -1;
        v3[2].m_nGrowSize = -1;
      }
      v14 = CUtlLinkedList<CFoundryEntitySpawnRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFoundryEntitySpawnRecord *,int>,int>>::AllocInternal(
              this: &g_FoundryEntitySpawnRecords,
              multilist: false);
      v15 = v14;
      if ( v14 != -1 )
      {
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
          this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_FoundryEntitySpawnRecords,
          elem: v14);
        v16 = g_FoundryEntitySpawnRecords.m_Memory.m_pMemory;
        v17 = v15;
        g_FoundryEntitySpawnRecords.m_Memory.m_pMemory[v17].m_Next = -1;
        m_Tail = g_FoundryEntitySpawnRecords.m_Tail;
        v16[v17].m_Previous = g_FoundryEntitySpawnRecords.m_Tail;
        g_FoundryEntitySpawnRecords.m_Tail = v15;
        if ( m_Tail == -1 )
          g_FoundryEntitySpawnRecords.m_Head = v15;
        else
          g_FoundryEntitySpawnRecords.m_Memory.m_pMemory[m_Tail].m_Next = v15;
        ++g_FoundryEntitySpawnRecords.m_ElementCount;
        v19 = &g_FoundryEntitySpawnRecords.m_Memory.m_pMemory[v17] == nullptr;
        v20 = &g_FoundryEntitySpawnRecords.m_Memory.m_pMemory[v17];
        v4 = i;
        if ( !v19 )
          v20->m_Element = (CFoundryEntitySpawnRecord *)v3;
      }
      i = ++v4;
      if ( v4 >= nInfos )
        break;
      v3 = nullptr;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10338B50
// Name: public: void CUtlMemory<struct ikcontextikrule_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ikcontextikrule_t,int>::Grow(CUtlMemory<ikcontextikrule_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ikcontextikrule_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 132 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ikcontextikrule_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ikcontextikrule_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103474A0
// Name: public: void CUtlMemory<struct CExpressionSample,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CExpressionSample,int>::Grow(CUtlMemory<CExpressionSample,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CExpressionSample *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CExpressionSample *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CExpressionSample *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035BB80
// Name: public: void CUtlMemory<struct masscenteroverride_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<masscenteroverride_t,int>::Grow(
        CUtlMemory<vgui::RichText::TFormatStream,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::RichText::TFormatStream *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v7);
    else
      this->m_pMemory = (vgui::RichText::TFormatStream *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10363830
// Name: public: bool CUtlLinkedList<class ResponseRules::CRR_Concept,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::IsValidIndex(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::IsValidIndex(
        CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int> > *this,
        int i)
{
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *v3; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  v3 = &this->m_Memory.m_pMemory[i];
  return v3->m_Previous != i || v3->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x10364D80
// Name: public: void CUtlLinkedList<class ResponseRules::CRR_Concept,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::RemoveAll(
        CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int> > *this)
{
  unsigned int m_Head; // eax
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *v2; // esi
  unsigned int m_Next; // edx
  unsigned int m_FirstFree; // eax
  unsigned int v5; // eax

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
// Address: 0x10364EB0
// Name: protected: unsigned int CUtlLinkedList<class ResponseRules::CRR_Concept,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::AllocInternal(
        CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int> > *this,
        bool multilist)
{
  int result; // eax
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>::Grow(
      this: &this->m_Memory,
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
      if ( `CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10366DB0
// Name: public: void CUtlLinkedList<class ResponseRules::CRR_Concept,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Purge(
        CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int> > *this)
{
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *m_pMemory; // ecx

  CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_FirstFree = 0xFFFF;
  this->m_NumAlloced = 0;
  this->m_LastAlloc.index = -1;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10366E00
// Name: public: unsigned int CUtlLinkedList<class ResponseRules::CRR_Concept,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Find(class ResponseRules::CRR_Concept const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Find(
        CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int> > *this,
        ResponseRules::CRR_Concept *src)
{
  unsigned int m_Head; // edi
  const char *StringConcept; // [esp+Ch] [ebp-4h]

  m_Head = this->m_Head;
  if ( m_Head == 0xFFFF )
    return 0xFFFF;
  while ( 1 )
  {
    StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: &this->m_Memory.m_pMemory[m_Head].m_Element);
    if ( StringConcept == ResponseRules::CRR_Concept::GetStringConcept(this: src) )
      break;
    m_Head = this->m_Memory.m_pMemory[m_Head].m_Next;
    if ( m_Head == 0xFFFF )
      return 0xFFFF;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x1036A940
// Name: public: void CUtlLinkedList<class ResponseRules::CRR_Concept,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Unlink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Unlink(
        CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int> > *this,
        int elem)
{
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *v2; // eax
  int m_Previous; // ebx
  unsigned int m_Next; // edx
  unsigned int v5; // edx

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
// Address: 0x1036C200
// Name: public: void CUtlLinkedList<class ResponseRules::CRR_Concept,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::LinkBefore(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::LinkBefore(
        CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int> > *this,
        unsigned int before,
        unsigned int elem)
{
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short> *v7; // ebx

  CUtlLinkedList<ResponseRules::CRR_Concept,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ResponseRules::CRR_Concept,unsigned short>,unsigned int>>::Unlink(
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
// Address: 0x1037DC80
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
// Address: 0x1037DF10
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
// Address: 0x1038BFB0
// Name: public: void CUtlMemory<struct bbox_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bbox_t,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039DC80
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
// Address: 0x1039DDE0
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
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
// Address: 0x103A0100
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
// Address: 0x103A0720
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
// Address: 0x103A1530
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
// Address: 0x103A15A0
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
// Address: 0x103A1A40
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
// Address: 0x103A2E50
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
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
// Address: 0x103A4620
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
// Address: 0x103A5BC0
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
// Address: 0x103A6200
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
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
// Address: 0x103A88A0
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
// Address: 0x103BBE20
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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
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
// Address: 0x103BC270
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
// Address: 0x103C0040
// Name: public: void CUtlMemory<struct template_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<template_t,int>::Grow(
        CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // edx

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
        m_nAllocationCount = 1;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::AnimationController::ActiveAnimation_t *)_g_pMemAlloc->Realloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: m_pMemory,
                                                                          a3: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (vgui::AnimationController::ActiveAnimation_t *)_g_pMemAlloc->Alloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D1D80
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
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
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
// Address: 0x103D1EB0
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
// Address: 0x103D1F10
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
// Address: 0x10131090
// Name: struct datamap_t __near * DataMapInit<class CFuncAreaPortalBase>(class CFuncAreaPortalBase __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncAreaPortalBase>()
{
  if ( (_S2_112 & 1) == 0 )
  {
    _S2_112 |= 1u;
    nameHolder_209.m_pszBase = "CFuncAreaPortalBase";
    nameHolder_209.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_209.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_209.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_209.m_Names.m_Size = 0;
    nameHolder_209.m_Names.m_pElements = nullptr;
    nameHolder_209.m_nLenBase = 19;
    atexit(func: DataMapInit_CFuncAreaPortalBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncAreaPortalBase::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncAreaPortalBase::m_DataMap.dataNumFields = 2;
  CFuncAreaPortalBase::m_DataMap.dataDesc = &dataDesc_199[1];
  return &CFuncAreaPortalBase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10162380
// Name: struct datamap_t __near * DataMapInit<class CInfoCameraLink>(class CInfoCameraLink __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CInfoCameraLink>()
{
  if ( (_S2_136 & 1) == 0 )
  {
    _S2_136 |= 1u;
    nameHolder_238.m_pszBase = "CInfoCameraLink";
    nameHolder_238.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_238.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_238.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_238.m_Names.m_Size = 0;
    nameHolder_238.m_Names.m_pElements = nullptr;
    nameHolder_238.m_nLenBase = 15;
    atexit(func: DataMapInit_CInfoCameraLink__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CInfoCameraLink::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CInfoCameraLink::m_DataMap.dataNumFields = 4;
  CInfoCameraLink::m_DataMap.dataDesc = &dataDesc_225[1];
  return &CInfoCameraLink::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10162400
// Name: class CInfoCameraLink __near * _CreateEntityTemplate<class CInfoCameraLink>(class CInfoCameraLink __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CInfoCameraLink *__cdecl _CreateEntityTemplate<CInfoCameraLink>(CInfoCameraLink *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  _DWORD *v5; // edi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CInfoCameraLink::`vftable';
    v3[213] = -1;
    v3[214] = -1;
    v4 = CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::AllocInternal(
           this: &g_InfoCameraLinkList,
           multilist: false);
    v5 = (_DWORD *)v4;
    if ( v4 != 0 )
    {
      CUtlLinkedList<CInfoCameraLink *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CInfoCameraLink *,int>>>::LinkBefore(
        this: &g_InfoCameraLinkList,
        before: 0,
        elem: v4);
      *v5 = v3;
    }
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CInfoCameraLink *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1490
// Name: struct datamap_t __near * DataMapInit<class CPlayerState>(class CPlayerState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPlayerState>()
{
  if ( (_S2_171 & 1) == 0 )
  {
    _S2_171 |= 1u;
    nameHolder_323.m_pszBase = "CPlayerState";
    nameHolder_323.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_323.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_323.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_323.m_Names.m_Size = 0;
    nameHolder_323.m_Names.m_pElements = nullptr;
    nameHolder_323.m_nLenBase = 12;
    atexit(func: DataMapInit_CPlayerState__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPlayerState::m_DataMap.baseMap = nullptr;
  CPlayerState::m_DataMap.dataNumFields = 2;
  CPlayerState::m_DataMap.dataDesc = &dataDesc_310[1];
  return &CPlayerState::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101C1520
// Name: struct datamap_t __near * DataMapInit<class CBasePlayer>(class CBasePlayer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBasePlayer>()
{
  if ( (_S3_95 & 1) == 0 )
  {
    _S3_95 |= 1u;
    nameHolder_324.m_pszBase = "CBasePlayer";
    nameHolder_324.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_324.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_324.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_324.m_Names.m_Size = 0;
    nameHolder_324.m_Names.m_pElements = nullptr;
    nameHolder_324.m_nLenBase = 11;
    atexit(func: DataMapInit_CBasePlayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBasePlayer::m_DataMap.baseMap = &CBaseCombatCharacter::m_DataMap;
  if ( (_S3_95 & 2) == 0 )
  {
    _S3_95 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    *(_QWORD *)dataDesc_311[3].flatOffset = 0;
    *(_QWORD *)dataDesc_311[4].flatOffset = 0;
    *(_QWORD *)&dataDesc_311[2].td = 0;
    *(_QWORD *)&dataDesc_311[2].override_field = 0;
    *(_QWORD *)&dataDesc_311[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_311[2].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_311[5].flatOffset = 0;
    dataDesc_311[2].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_311[2].inputFunc = nullptr;
    dataDesc_311[3].fieldType = FIELD_EMBEDDED;
    dataDesc_311[3].fieldName = "pl";
    dataDesc_311[3].fieldOffset = 2900;
    *(_DWORD *)&dataDesc_311[3].fieldSize = 131073;
    dataDesc_311[3].externalName = nullptr;
    dataDesc_311[3].pSaveRestoreOps = nullptr;
    dataDesc_311[3].inputFunc = nullptr;
    dataDesc_311[3].td = &CPlayerState::m_DataMap;
    dataDesc_311[3].fieldSizeInBytes = 52;
    dataDesc_311[3].override_field = nullptr;
    dataDesc_311[3].override_count = 0;
    dataDesc_311[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[3].flatGroup = 0;
    dataDesc_311[4].fieldType = FIELD_INTEGER;
    dataDesc_311[4].fieldName = "m_StuckLast";
    dataDesc_311[4].fieldOffset = 2284;
    *(_DWORD *)&dataDesc_311[4].fieldSize = 131073;
    dataDesc_311[4].externalName = nullptr;
    dataDesc_311[4].pSaveRestoreOps = nullptr;
    dataDesc_311[4].inputFunc = nullptr;
    dataDesc_311[4].td = nullptr;
    dataDesc_311[4].fieldSizeInBytes = 4;
    dataDesc_311[4].override_field = nullptr;
    dataDesc_311[4].override_count = 0;
    dataDesc_311[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[4].flatGroup = 0;
    dataDesc_311[5].fieldType = FIELD_INTEGER;
    dataDesc_311[5].fieldName = "m_nButtons";
    dataDesc_311[5].fieldOffset = 2952;
    dataDesc_311[5].fieldSize = 1;
    dataDesc_311[5].flags = 2;
    dataDesc_311[5].externalName = nullptr;
    dataDesc_311[5].pSaveRestoreOps = nullptr;
    dataDesc_311[5].inputFunc = nullptr;
    dataDesc_311[5].td = nullptr;
    dataDesc_311[5].fieldSizeInBytes = 4;
    dataDesc_311[5].override_field = nullptr;
    dataDesc_311[5].override_count = 0;
    dataDesc_311[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[5].flatGroup = 0;
    dataDesc_311[6].fieldType = FIELD_INTEGER;
    dataDesc_311[6].fieldName = "m_afButtonLast";
    dataDesc_311[6].fieldOffset = 2964;
    dataDesc_311[6].fieldSize = 1;
    dataDesc_311[6].flags = 2;
    dataDesc_311[6].externalName = nullptr;
    dataDesc_311[6].pSaveRestoreOps = nullptr;
    dataDesc_311[6].inputFunc = nullptr;
    dataDesc_311[6].td = nullptr;
    dataDesc_311[6].fieldSizeInBytes = 4;
    dataDesc_311[6].override_field = nullptr;
    dataDesc_311[6].override_count = 0;
    dataDesc_311[6].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[6].flatGroup = 0;
    dataDesc_311[7].fieldType = FIELD_INTEGER;
    dataDesc_311[7].fieldName = "m_afButtonPressed";
    dataDesc_311[7].fieldOffset = 2956;
    dataDesc_311[7].fieldSize = 1;
    *(_QWORD *)dataDesc_311[7].flatOffset = 0;
    *(_QWORD *)dataDesc_311[8].flatOffset = 0;
    *(_QWORD *)dataDesc_311[9].flatOffset = 0;
    *(_QWORD *)dataDesc_311[10].flatOffset = 0;
    dataDesc_311[7].flags = 2;
    dataDesc_311[7].externalName = nullptr;
    dataDesc_311[7].pSaveRestoreOps = nullptr;
    dataDesc_311[7].inputFunc = nullptr;
    dataDesc_311[7].td = nullptr;
    dataDesc_311[7].fieldSizeInBytes = 4;
    dataDesc_311[7].override_field = nullptr;
    dataDesc_311[7].override_count = 0;
    dataDesc_311[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[7].flatGroup = 0;
    dataDesc_311[8].fieldType = FIELD_INTEGER;
    dataDesc_311[8].fieldName = "m_afButtonReleased";
    dataDesc_311[8].fieldOffset = 2960;
    dataDesc_311[8].fieldSize = 1;
    dataDesc_311[8].flags = 2;
    dataDesc_311[8].externalName = nullptr;
    dataDesc_311[8].pSaveRestoreOps = nullptr;
    dataDesc_311[8].inputFunc = nullptr;
    dataDesc_311[8].td = nullptr;
    dataDesc_311[8].fieldSizeInBytes = 4;
    dataDesc_311[8].override_field = nullptr;
    dataDesc_311[8].override_count = 0;
    dataDesc_311[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[8].flatGroup = 0;
    dataDesc_311[9].fieldType = FIELD_INTEGER;
    dataDesc_311[9].fieldName = "m_afButtonDisabled";
    dataDesc_311[9].fieldOffset = 2968;
    dataDesc_311[9].fieldSize = 1;
    dataDesc_311[9].flags = 2;
    dataDesc_311[9].externalName = nullptr;
    dataDesc_311[9].pSaveRestoreOps = nullptr;
    dataDesc_311[9].inputFunc = nullptr;
    dataDesc_311[9].td = nullptr;
    dataDesc_311[9].fieldSizeInBytes = 4;
    dataDesc_311[9].override_field = nullptr;
    dataDesc_311[9].override_count = 0;
    dataDesc_311[9].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[9].flatGroup = 0;
    dataDesc_311[10].fieldType = FIELD_INTEGER;
    dataDesc_311[10].fieldName = "m_afButtonForced";
    dataDesc_311[10].fieldOffset = 2972;
    dataDesc_311[10].fieldSize = 1;
    dataDesc_311[10].flags = 2;
    dataDesc_311[10].externalName = nullptr;
    dataDesc_311[10].pSaveRestoreOps = nullptr;
    dataDesc_311[10].inputFunc = nullptr;
    dataDesc_311[10].td = nullptr;
    dataDesc_311[10].fieldSizeInBytes = 4;
    dataDesc_311[10].override_field = nullptr;
    dataDesc_311[10].override_count = 0;
    dataDesc_311[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[10].flatGroup = 0;
    dataDesc_311[11].fieldType = FIELD_INTEGER;
    dataDesc_311[11].fieldName = "m_iFOV";
    dataDesc_311[11].fieldOffset = 3148;
    dataDesc_311[11].fieldSize = 1;
    dataDesc_311[11].flags = 2;
    dataDesc_311[11].externalName = nullptr;
    dataDesc_311[11].pSaveRestoreOps = nullptr;
    dataDesc_311[11].inputFunc = nullptr;
    dataDesc_311[11].td = nullptr;
    dataDesc_311[11].fieldSizeInBytes = 4;
    dataDesc_311[11].override_field = nullptr;
    dataDesc_311[11].override_count = 0;
    dataDesc_311[11].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[11].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[11].flatGroup = 0;
    dataDesc_311[12].fieldType = FIELD_INTEGER;
    dataDesc_311[12].fieldName = "m_iFOVStart";
    dataDesc_311[12].fieldOffset = 3156;
    dataDesc_311[12].fieldSize = 1;
    dataDesc_311[12].flags = 2;
    *(_QWORD *)dataDesc_311[12].flatOffset = 0;
    *(_QWORD *)dataDesc_311[13].flatOffset = 0;
    *(_QWORD *)dataDesc_311[14].flatOffset = 0;
    *(_QWORD *)dataDesc_311[15].flatOffset = 0;
    dataDesc_311[12].externalName = nullptr;
    dataDesc_311[12].pSaveRestoreOps = nullptr;
    dataDesc_311[12].inputFunc = nullptr;
    dataDesc_311[12].td = nullptr;
    dataDesc_311[12].fieldSizeInBytes = 4;
    dataDesc_311[12].override_field = nullptr;
    dataDesc_311[12].override_count = 0;
    dataDesc_311[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[12].flatGroup = 0;
    dataDesc_311[13].fieldType = FIELD_TIME;
    dataDesc_311[13].fieldName = "m_flFOVTime";
    dataDesc_311[13].fieldOffset = 3160;
    dataDesc_311[13].fieldSize = 1;
    dataDesc_311[13].flags = 2;
    dataDesc_311[13].externalName = nullptr;
    dataDesc_311[13].pSaveRestoreOps = nullptr;
    dataDesc_311[13].inputFunc = nullptr;
    dataDesc_311[13].td = nullptr;
    dataDesc_311[13].fieldSizeInBytes = 4;
    dataDesc_311[13].override_field = nullptr;
    dataDesc_311[13].override_count = 0;
    dataDesc_311[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[13].flatGroup = 0;
    dataDesc_311[14].fieldType = FIELD_INTEGER;
    dataDesc_311[14].fieldName = "m_iDefaultFOV";
    dataDesc_311[14].fieldOffset = 3152;
    dataDesc_311[14].fieldSize = 1;
    dataDesc_311[14].flags = 2;
    dataDesc_311[14].externalName = nullptr;
    dataDesc_311[14].pSaveRestoreOps = nullptr;
    dataDesc_311[14].inputFunc = nullptr;
    dataDesc_311[14].td = nullptr;
    dataDesc_311[14].fieldSizeInBytes = 4;
    dataDesc_311[14].override_field = nullptr;
    dataDesc_311[14].override_count = 0;
    dataDesc_311[14].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[14].flatGroup = 0;
    dataDesc_311[15].fieldType = FIELD_FLOAT;
    dataDesc_311[15].fieldName = "m_flVehicleViewFOV";
    dataDesc_311[15].fieldOffset = 4056;
    dataDesc_311[15].fieldSize = 1;
    dataDesc_311[15].flags = 2;
    dataDesc_311[15].externalName = nullptr;
    dataDesc_311[15].pSaveRestoreOps = nullptr;
    dataDesc_311[15].inputFunc = nullptr;
    dataDesc_311[15].td = nullptr;
    dataDesc_311[15].fieldSizeInBytes = 4;
    dataDesc_311[15].override_field = nullptr;
    dataDesc_311[15].override_count = 0;
    dataDesc_311[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[15].flatGroup = 0;
    dataDesc_311[16].fieldType = FIELD_INTEGER;
    dataDesc_311[16].fieldName = "m_iObserverMode";
    dataDesc_311[16].fieldOffset = 3144;
    dataDesc_311[16].fieldSize = 1;
    dataDesc_311[16].flags = 2;
    dataDesc_311[16].externalName = nullptr;
    dataDesc_311[16].pSaveRestoreOps = nullptr;
    dataDesc_311[16].inputFunc = nullptr;
    dataDesc_311[16].td = nullptr;
    dataDesc_311[16].fieldSizeInBytes = 4;
    dataDesc_311[16].override_field = nullptr;
    dataDesc_311[16].override_count = 0;
    dataDesc_311[16].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[16].flatGroup = 0;
    dataDesc_311[17].fieldType = FIELD_INTEGER;
    dataDesc_311[17].fieldName = "m_iObserverLastMode";
    dataDesc_311[17].fieldOffset = 3164;
    dataDesc_311[17].fieldSize = 1;
    dataDesc_311[17].flags = 2;
    dataDesc_311[17].externalName = nullptr;
    dataDesc_311[18].flags = 2;
    dataDesc_311[19].fieldSize = 1;
    dataDesc_311[19].flags = 2;
    *(_QWORD *)dataDesc_311[17].flatOffset = 0;
    dataDesc_311[20].fieldSize = 32;
    *(_QWORD *)dataDesc_311[18].flatOffset = 0;
    dataDesc_311[20].flags = 2;
    *(_QWORD *)dataDesc_311[19].flatOffset = 0;
    dataDesc_311[18].fieldSize = 1;
    dataDesc_311[21].fieldSize = 1;
    *(_QWORD *)dataDesc_311[20].flatOffset = 0;
    dataDesc_311[17].pSaveRestoreOps = nullptr;
    dataDesc_311[17].inputFunc = nullptr;
    dataDesc_311[17].td = nullptr;
    dataDesc_311[17].fieldSizeInBytes = 4;
    dataDesc_311[17].override_field = nullptr;
    dataDesc_311[17].override_count = 0;
    dataDesc_311[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[17].flatGroup = 0;
    dataDesc_311[18].fieldType = FIELD_EHANDLE;
    dataDesc_311[18].fieldName = "m_hObserverTarget";
    dataDesc_311[18].fieldOffset = 3168;
    dataDesc_311[18].externalName = nullptr;
    dataDesc_311[18].pSaveRestoreOps = nullptr;
    dataDesc_311[18].inputFunc = nullptr;
    dataDesc_311[18].td = nullptr;
    dataDesc_311[18].fieldSizeInBytes = 4;
    dataDesc_311[18].override_field = nullptr;
    dataDesc_311[18].override_count = 0;
    dataDesc_311[18].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[18].flatGroup = 0;
    dataDesc_311[19].fieldType = FIELD_BOOLEAN;
    dataDesc_311[19].fieldName = "m_bForcedObserverMode";
    dataDesc_311[19].fieldOffset = 3172;
    dataDesc_311[19].externalName = nullptr;
    dataDesc_311[19].pSaveRestoreOps = nullptr;
    dataDesc_311[19].inputFunc = nullptr;
    dataDesc_311[19].td = nullptr;
    dataDesc_311[19].fieldSizeInBytes = 1;
    dataDesc_311[19].override_field = nullptr;
    dataDesc_311[19].override_count = 0;
    dataDesc_311[19].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[19].flatGroup = 0;
    dataDesc_311[20].fieldType = FIELD_CHARACTER;
    dataDesc_311[20].fieldName = "m_szAnimExtension";
    dataDesc_311[20].fieldOffset = 2977;
    dataDesc_311[20].externalName = nullptr;
    dataDesc_311[20].pSaveRestoreOps = nullptr;
    dataDesc_311[20].inputFunc = nullptr;
    dataDesc_311[20].td = nullptr;
    dataDesc_311[20].fieldSizeInBytes = 32;
    dataDesc_311[20].override_field = nullptr;
    dataDesc_311[20].override_count = 0;
    dataDesc_311[20].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[20].flatGroup = 0;
    dataDesc_311[21].fieldType = FIELD_INTEGER;
    dataDesc_311[21].fieldName = "m_nUpdateRate";
    dataDesc_311[21].fieldOffset = 3012;
    dataDesc_311[21].flags = 2;
    dataDesc_311[21].externalName = nullptr;
    dataDesc_311[21].pSaveRestoreOps = nullptr;
    dataDesc_311[21].inputFunc = nullptr;
    dataDesc_311[21].td = nullptr;
    dataDesc_311[21].fieldSizeInBytes = 4;
    dataDesc_311[21].override_field = nullptr;
    dataDesc_311[21].override_count = 0;
    dataDesc_311[21].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[21].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[21].flatGroup = 0;
    dataDesc_311[22].fieldSize = 1;
    dataDesc_311[22].flags = 2;
    dataDesc_311[23].fieldSize = 1;
    dataDesc_311[23].flags = 2;
    dataDesc_311[24].fieldSize = 1;
    dataDesc_311[24].flags = 2;
    dataDesc_311[25].fieldSize = 1;
    *(_QWORD *)dataDesc_311[22].flatOffset = 0;
    dataDesc_311[25].flags = 2;
    *(_QWORD *)dataDesc_311[23].flatOffset = 0;
    dataDesc_311[26].fieldSize = 1;
    *(_QWORD *)dataDesc_311[24].flatOffset = 0;
    dataDesc_311[22].fieldType = FIELD_FLOAT;
    dataDesc_311[22].fieldName = "m_fLerpTime";
    dataDesc_311[22].fieldOffset = 3016;
    dataDesc_311[22].externalName = nullptr;
    dataDesc_311[22].pSaveRestoreOps = nullptr;
    dataDesc_311[22].inputFunc = nullptr;
    dataDesc_311[22].td = nullptr;
    dataDesc_311[22].fieldSizeInBytes = 4;
    dataDesc_311[22].override_field = nullptr;
    dataDesc_311[22].override_count = 0;
    dataDesc_311[22].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[22].flatGroup = 0;
    dataDesc_311[23].fieldType = FIELD_BOOLEAN;
    dataDesc_311[23].fieldName = "m_bLagCompensation";
    dataDesc_311[23].fieldOffset = 3020;
    dataDesc_311[23].externalName = nullptr;
    dataDesc_311[23].pSaveRestoreOps = nullptr;
    dataDesc_311[23].inputFunc = nullptr;
    dataDesc_311[23].td = nullptr;
    dataDesc_311[23].fieldSizeInBytes = 1;
    dataDesc_311[23].override_field = nullptr;
    dataDesc_311[23].override_count = 0;
    dataDesc_311[23].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[23].flatGroup = 0;
    dataDesc_311[24].fieldType = FIELD_BOOLEAN;
    dataDesc_311[24].fieldName = "m_bPredictWeapons";
    dataDesc_311[24].fieldOffset = 3021;
    dataDesc_311[24].externalName = nullptr;
    dataDesc_311[24].pSaveRestoreOps = nullptr;
    dataDesc_311[24].inputFunc = nullptr;
    dataDesc_311[24].td = nullptr;
    dataDesc_311[24].fieldSizeInBytes = 1;
    dataDesc_311[24].override_field = nullptr;
    dataDesc_311[24].override_count = 0;
    dataDesc_311[24].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[24].flatGroup = 0;
    dataDesc_311[25].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_311[25].fieldName = "m_vecAdditionalPVSOrigin";
    dataDesc_311[25].fieldOffset = 3028;
    dataDesc_311[25].externalName = nullptr;
    dataDesc_311[25].pSaveRestoreOps = nullptr;
    dataDesc_311[25].inputFunc = nullptr;
    dataDesc_311[25].td = nullptr;
    dataDesc_311[25].fieldSizeInBytes = 12;
    dataDesc_311[25].override_field = nullptr;
    dataDesc_311[25].override_count = 0;
    dataDesc_311[25].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[25].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[25].flatGroup = 0;
    dataDesc_311[26].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_311[26].fieldName = "m_vecCameraPVSOrigin";
    dataDesc_311[26].fieldOffset = 3040;
    dataDesc_311[26].flags = 2;
    dataDesc_311[26].externalName = nullptr;
    dataDesc_311[26].pSaveRestoreOps = nullptr;
    dataDesc_311[27].fieldSize = 1;
    dataDesc_311[27].flags = 2;
    dataDesc_311[28].fieldSize = 1;
    dataDesc_311[28].flags = 2;
    *(_QWORD *)dataDesc_311[26].flatOffset = 0;
    dataDesc_311[29].fieldSize = 1;
    *(_QWORD *)dataDesc_311[27].flatOffset = 0;
    dataDesc_311[29].flags = 2;
    *(_QWORD *)dataDesc_311[28].flatOffset = 0;
    dataDesc_311[30].fieldSize = 1;
    *(_QWORD *)dataDesc_311[29].flatOffset = 0;
    dataDesc_311[26].inputFunc = nullptr;
    dataDesc_311[26].td = nullptr;
    dataDesc_311[26].fieldSizeInBytes = 12;
    dataDesc_311[26].override_field = nullptr;
    dataDesc_311[26].override_count = 0;
    dataDesc_311[26].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[26].flatGroup = 0;
    dataDesc_311[27].fieldType = FIELD_BOOLEAN;
    dataDesc_311[27].fieldName = "m_bDropEnabled";
    dataDesc_311[27].fieldOffset = 3052;
    dataDesc_311[27].externalName = nullptr;
    dataDesc_311[27].pSaveRestoreOps = nullptr;
    dataDesc_311[27].inputFunc = nullptr;
    dataDesc_311[27].td = nullptr;
    dataDesc_311[27].fieldSizeInBytes = 1;
    dataDesc_311[27].override_field = nullptr;
    dataDesc_311[27].override_count = 0;
    dataDesc_311[27].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[27].flatGroup = 0;
    dataDesc_311[28].fieldType = FIELD_BOOLEAN;
    dataDesc_311[28].fieldName = "m_bDuckEnabled";
    dataDesc_311[28].fieldOffset = 3053;
    dataDesc_311[28].externalName = nullptr;
    dataDesc_311[28].pSaveRestoreOps = nullptr;
    dataDesc_311[28].inputFunc = nullptr;
    dataDesc_311[28].td = nullptr;
    dataDesc_311[28].fieldSizeInBytes = 1;
    dataDesc_311[28].override_field = nullptr;
    dataDesc_311[28].override_count = 0;
    dataDesc_311[28].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[28].flatGroup = 0;
    dataDesc_311[29].fieldType = FIELD_EHANDLE;
    dataDesc_311[29].fieldName = "m_hUseEntity";
    dataDesc_311[29].fieldOffset = 3056;
    dataDesc_311[29].externalName = nullptr;
    dataDesc_311[29].pSaveRestoreOps = nullptr;
    dataDesc_311[29].inputFunc = nullptr;
    dataDesc_311[29].td = nullptr;
    dataDesc_311[29].fieldSizeInBytes = 4;
    dataDesc_311[29].override_field = nullptr;
    dataDesc_311[29].override_count = 0;
    dataDesc_311[29].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[29].flatGroup = 0;
    dataDesc_311[30].fieldType = FIELD_INTEGER;
    dataDesc_311[30].fieldName = "m_iTrain";
    dataDesc_311[30].fieldOffset = 3060;
    dataDesc_311[30].flags = 2;
    dataDesc_311[30].externalName = nullptr;
    dataDesc_311[30].pSaveRestoreOps = nullptr;
    dataDesc_311[30].inputFunc = nullptr;
    dataDesc_311[30].td = nullptr;
    dataDesc_311[30].fieldSizeInBytes = 4;
    dataDesc_311[30].override_field = nullptr;
    dataDesc_311[30].override_count = 0;
    dataDesc_311[30].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[30].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[30].flatGroup = 0;
    dataDesc_311[31].fieldSize = 1;
    dataDesc_311[31].flags = 2;
    dataDesc_311[32].fieldSize = 1;
    dataDesc_311[32].flags = 2;
    dataDesc_311[33].fieldSize = 1;
    dataDesc_311[33].flags = 2;
    dataDesc_311[34].fieldSize = 64;
    *(_QWORD *)dataDesc_311[31].flatOffset = 0;
    dataDesc_311[34].flags = 2;
    *(_QWORD *)dataDesc_311[32].flatOffset = 0;
    dataDesc_311[35].fieldSize = 1;
    *(_QWORD *)dataDesc_311[33].flatOffset = 0;
    dataDesc_311[31].fieldType = FIELD_FLOAT;
    dataDesc_311[31].fieldName = "m_iRespawnFrames";
    dataDesc_311[31].fieldOffset = 3064;
    dataDesc_311[31].externalName = nullptr;
    dataDesc_311[31].pSaveRestoreOps = nullptr;
    dataDesc_311[31].inputFunc = nullptr;
    dataDesc_311[31].td = nullptr;
    dataDesc_311[31].fieldSizeInBytes = 4;
    dataDesc_311[31].override_field = nullptr;
    dataDesc_311[31].override_count = 0;
    dataDesc_311[31].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[31].flatGroup = 0;
    dataDesc_311[32].fieldType = FIELD_INTEGER;
    dataDesc_311[32].fieldName = "m_afPhysicsFlags";
    dataDesc_311[32].fieldOffset = 3068;
    dataDesc_311[32].externalName = nullptr;
    dataDesc_311[32].pSaveRestoreOps = nullptr;
    dataDesc_311[32].inputFunc = nullptr;
    dataDesc_311[32].td = nullptr;
    dataDesc_311[32].fieldSizeInBytes = 4;
    dataDesc_311[32].override_field = nullptr;
    dataDesc_311[32].override_count = 0;
    dataDesc_311[32].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[32].flatGroup = 0;
    dataDesc_311[33].fieldType = FIELD_EHANDLE;
    dataDesc_311[33].fieldName = "m_hVehicle";
    dataDesc_311[33].fieldOffset = 3072;
    dataDesc_311[33].externalName = nullptr;
    dataDesc_311[33].pSaveRestoreOps = nullptr;
    dataDesc_311[33].inputFunc = nullptr;
    dataDesc_311[33].td = nullptr;
    dataDesc_311[33].fieldSizeInBytes = 4;
    dataDesc_311[33].override_field = nullptr;
    dataDesc_311[33].override_count = 0;
    dataDesc_311[33].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[33].flatGroup = 0;
    dataDesc_311[34].fieldType = FIELD_CHARACTER;
    dataDesc_311[34].fieldName = "m_szNetworkIDString";
    dataDesc_311[34].fieldOffset = 4098;
    dataDesc_311[34].externalName = nullptr;
    dataDesc_311[34].pSaveRestoreOps = nullptr;
    dataDesc_311[34].inputFunc = nullptr;
    dataDesc_311[34].td = nullptr;
    dataDesc_311[34].fieldSizeInBytes = 64;
    dataDesc_311[34].override_field = nullptr;
    dataDesc_311[34].override_count = 0;
    dataDesc_311[34].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[34].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[34].flatGroup = 0;
    dataDesc_311[35].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_311[35].fieldName = "m_oldOrigin";
    dataDesc_311[35].fieldOffset = 3268;
    dataDesc_311[35].flags = 2;
    dataDesc_311[35].externalName = nullptr;
    dataDesc_311[35].pSaveRestoreOps = nullptr;
    dataDesc_311[36].fieldSize = 1;
    dataDesc_311[36].flags = 2;
    dataDesc_311[37].fieldSize = 1;
    dataDesc_311[37].flags = 2;
    *(_QWORD *)dataDesc_311[35].flatOffset = 0;
    dataDesc_311[38].fieldSize = 5;
    *(_QWORD *)dataDesc_311[36].flatOffset = 0;
    dataDesc_311[38].flags = 2;
    *(_QWORD *)dataDesc_311[37].flatOffset = 0;
    dataDesc_311[39].fieldSize = 1;
    *(_QWORD *)dataDesc_311[38].flatOffset = 0;
    dataDesc_311[35].inputFunc = nullptr;
    dataDesc_311[35].td = nullptr;
    dataDesc_311[35].fieldSizeInBytes = 12;
    dataDesc_311[35].override_field = nullptr;
    dataDesc_311[35].override_count = 0;
    dataDesc_311[35].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[35].flatGroup = 0;
    dataDesc_311[36].fieldType = FIELD_VECTOR;
    dataDesc_311[36].fieldName = "m_vecSmoothedVelocity";
    dataDesc_311[36].fieldOffset = 3280;
    dataDesc_311[36].externalName = nullptr;
    dataDesc_311[36].pSaveRestoreOps = nullptr;
    dataDesc_311[36].inputFunc = nullptr;
    dataDesc_311[36].td = nullptr;
    dataDesc_311[36].fieldSizeInBytes = 12;
    dataDesc_311[36].override_field = nullptr;
    dataDesc_311[36].override_count = 0;
    dataDesc_311[36].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[36].flatGroup = 0;
    dataDesc_311[37].fieldType = FIELD_INTEGER;
    dataDesc_311[37].fieldName = "m_iTargetVolume";
    dataDesc_311[37].fieldOffset = 3300;
    dataDesc_311[37].externalName = nullptr;
    dataDesc_311[37].pSaveRestoreOps = nullptr;
    dataDesc_311[37].inputFunc = nullptr;
    dataDesc_311[37].td = nullptr;
    dataDesc_311[37].fieldSizeInBytes = 4;
    dataDesc_311[37].override_field = nullptr;
    dataDesc_311[37].override_count = 0;
    dataDesc_311[37].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[37].flatGroup = 0;
    dataDesc_311[38].fieldType = FIELD_INTEGER;
    dataDesc_311[38].fieldName = "m_rgItems";
    dataDesc_311[38].fieldOffset = 3304;
    dataDesc_311[38].externalName = nullptr;
    dataDesc_311[38].pSaveRestoreOps = nullptr;
    dataDesc_311[38].inputFunc = nullptr;
    dataDesc_311[38].td = nullptr;
    dataDesc_311[38].fieldSizeInBytes = 20;
    dataDesc_311[38].override_field = nullptr;
    dataDesc_311[38].override_count = 0;
    dataDesc_311[38].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[38].flatGroup = 0;
    dataDesc_311[39].fieldType = FIELD_TIME;
    dataDesc_311[39].fieldName = "m_flSuitUpdate";
    dataDesc_311[39].fieldOffset = 3336;
    dataDesc_311[39].flags = 2;
    dataDesc_311[39].externalName = nullptr;
    dataDesc_311[39].pSaveRestoreOps = nullptr;
    dataDesc_311[39].inputFunc = nullptr;
    dataDesc_311[39].td = nullptr;
    dataDesc_311[39].fieldSizeInBytes = 4;
    dataDesc_311[39].override_field = nullptr;
    dataDesc_311[39].override_count = 0;
    dataDesc_311[39].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[39].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[39].flatGroup = 0;
    dataDesc_311[40].fieldSize = 4;
    dataDesc_311[40].flags = 2;
    dataDesc_311[41].fieldSize = 1;
    dataDesc_311[41].flags = 2;
    dataDesc_311[42].fieldSize = 32;
    dataDesc_311[42].flags = 2;
    dataDesc_311[43].fieldSize = 32;
    *(_QWORD *)dataDesc_311[40].flatOffset = 0;
    dataDesc_311[43].flags = 2;
    *(_QWORD *)dataDesc_311[41].flatOffset = 0;
    dataDesc_311[44].fieldSize = 1;
    *(_QWORD *)dataDesc_311[42].flatOffset = 0;
    dataDesc_311[40].fieldType = FIELD_INTEGER;
    dataDesc_311[40].fieldName = "m_rgSuitPlayList";
    dataDesc_311[40].fieldOffset = 3340;
    dataDesc_311[40].externalName = nullptr;
    dataDesc_311[40].pSaveRestoreOps = nullptr;
    dataDesc_311[40].inputFunc = nullptr;
    dataDesc_311[40].td = nullptr;
    dataDesc_311[40].fieldSizeInBytes = 16;
    dataDesc_311[40].override_field = nullptr;
    dataDesc_311[40].override_count = 0;
    dataDesc_311[40].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[40].flatGroup = 0;
    dataDesc_311[41].fieldType = FIELD_INTEGER;
    dataDesc_311[41].fieldName = "m_iSuitPlayNext";
    dataDesc_311[41].fieldOffset = 3356;
    dataDesc_311[41].externalName = nullptr;
    dataDesc_311[41].pSaveRestoreOps = nullptr;
    dataDesc_311[41].inputFunc = nullptr;
    dataDesc_311[41].td = nullptr;
    dataDesc_311[41].fieldSizeInBytes = 4;
    dataDesc_311[41].override_field = nullptr;
    dataDesc_311[41].override_count = 0;
    dataDesc_311[41].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[41].flatGroup = 0;
    dataDesc_311[42].fieldType = FIELD_INTEGER;
    dataDesc_311[42].fieldName = "m_rgiSuitNoRepeat";
    dataDesc_311[42].fieldOffset = 3360;
    dataDesc_311[42].externalName = nullptr;
    dataDesc_311[42].pSaveRestoreOps = nullptr;
    dataDesc_311[42].inputFunc = nullptr;
    dataDesc_311[42].td = nullptr;
    dataDesc_311[42].fieldSizeInBytes = 128;
    dataDesc_311[42].override_field = nullptr;
    dataDesc_311[42].override_count = 0;
    dataDesc_311[42].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[42].flatGroup = 0;
    dataDesc_311[43].fieldType = FIELD_TIME;
    dataDesc_311[43].fieldName = "m_rgflSuitNoRepeatTime";
    dataDesc_311[43].fieldOffset = 3488;
    dataDesc_311[43].externalName = nullptr;
    dataDesc_311[43].pSaveRestoreOps = nullptr;
    dataDesc_311[43].inputFunc = nullptr;
    dataDesc_311[43].td = nullptr;
    dataDesc_311[43].fieldSizeInBytes = 128;
    dataDesc_311[43].override_field = nullptr;
    dataDesc_311[43].override_count = 0;
    dataDesc_311[43].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[43].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[43].flatGroup = 0;
    dataDesc_311[44].fieldType = FIELD_BOOLEAN;
    dataDesc_311[44].fieldName = "m_bPauseBonusProgress";
    dataDesc_311[44].fieldOffset = 3080;
    dataDesc_311[44].flags = 2;
    dataDesc_311[44].externalName = nullptr;
    dataDesc_311[44].pSaveRestoreOps = nullptr;
    dataDesc_311[45].fieldSize = 1;
    dataDesc_311[45].flags = 2;
    dataDesc_311[46].fieldSize = 1;
    dataDesc_311[46].flags = 2;
    *(_QWORD *)dataDesc_311[44].flatOffset = 0;
    dataDesc_311[47].fieldSize = 1;
    *(_QWORD *)dataDesc_311[45].flatOffset = 0;
    dataDesc_311[47].flags = 2;
    *(_QWORD *)dataDesc_311[46].flatOffset = 0;
    dataDesc_311[48].fieldSize = 1;
    *(_QWORD *)dataDesc_311[47].flatOffset = 0;
    dataDesc_311[44].inputFunc = nullptr;
    dataDesc_311[44].td = nullptr;
    dataDesc_311[44].fieldSizeInBytes = 1;
    dataDesc_311[44].override_field = nullptr;
    dataDesc_311[44].override_count = 0;
    dataDesc_311[44].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[44].flatGroup = 0;
    dataDesc_311[45].fieldType = FIELD_INTEGER;
    dataDesc_311[45].fieldName = "m_iBonusProgress";
    dataDesc_311[45].fieldOffset = 3084;
    dataDesc_311[45].externalName = nullptr;
    dataDesc_311[45].pSaveRestoreOps = nullptr;
    dataDesc_311[45].inputFunc = nullptr;
    dataDesc_311[45].td = nullptr;
    dataDesc_311[45].fieldSizeInBytes = 4;
    dataDesc_311[45].override_field = nullptr;
    dataDesc_311[45].override_count = 0;
    dataDesc_311[45].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[45].flatGroup = 0;
    dataDesc_311[46].fieldType = FIELD_INTEGER;
    dataDesc_311[46].fieldName = "m_iBonusChallenge";
    dataDesc_311[46].fieldOffset = 3088;
    dataDesc_311[46].externalName = nullptr;
    dataDesc_311[46].pSaveRestoreOps = nullptr;
    dataDesc_311[46].inputFunc = nullptr;
    dataDesc_311[46].td = nullptr;
    dataDesc_311[46].fieldSizeInBytes = 4;
    dataDesc_311[46].override_field = nullptr;
    dataDesc_311[46].override_count = 0;
    dataDesc_311[46].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[46].flatGroup = 0;
    dataDesc_311[47].fieldType = FIELD_INTEGER;
    dataDesc_311[47].fieldName = "m_lastDamageAmount";
    dataDesc_311[47].fieldOffset = 3096;
    dataDesc_311[47].externalName = nullptr;
    dataDesc_311[47].pSaveRestoreOps = nullptr;
    dataDesc_311[47].inputFunc = nullptr;
    dataDesc_311[47].td = nullptr;
    dataDesc_311[47].fieldSizeInBytes = 4;
    dataDesc_311[47].override_field = nullptr;
    dataDesc_311[47].override_count = 0;
    dataDesc_311[47].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[47].flatGroup = 0;
    dataDesc_311[48].fieldType = FIELD_TIME;
    dataDesc_311[48].fieldName = "m_fTimeLastHurt";
    dataDesc_311[48].fieldOffset = 3100;
    dataDesc_311[48].flags = 2;
    dataDesc_311[48].externalName = nullptr;
    dataDesc_311[48].pSaveRestoreOps = nullptr;
    dataDesc_311[48].inputFunc = nullptr;
    dataDesc_311[48].td = nullptr;
    dataDesc_311[48].fieldSizeInBytes = 4;
    dataDesc_311[48].override_field = nullptr;
    dataDesc_311[48].override_count = 0;
    dataDesc_311[48].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[48].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[48].flatGroup = 0;
    dataDesc_311[49].fieldSize = 1;
    dataDesc_311[49].flags = 2;
    dataDesc_311[50].fieldSize = 1;
    dataDesc_311[50].flags = 2;
    dataDesc_311[51].fieldSize = 32;
    dataDesc_311[51].flags = 2;
    dataDesc_311[52].fieldSize = 1;
    *(_QWORD *)dataDesc_311[49].flatOffset = 0;
    dataDesc_311[52].flags = 2;
    *(_QWORD *)dataDesc_311[50].flatOffset = 0;
    dataDesc_311[53].fieldSize = 1;
    *(_QWORD *)dataDesc_311[51].flatOffset = 0;
    dataDesc_311[49].fieldType = FIELD_TIME;
    dataDesc_311[49].fieldName = "m_tbdPrev";
    dataDesc_311[49].fieldOffset = 3180;
    dataDesc_311[49].externalName = nullptr;
    dataDesc_311[49].pSaveRestoreOps = nullptr;
    dataDesc_311[49].inputFunc = nullptr;
    dataDesc_311[49].td = nullptr;
    dataDesc_311[49].fieldSizeInBytes = 4;
    dataDesc_311[49].override_field = nullptr;
    dataDesc_311[49].override_count = 0;
    dataDesc_311[49].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[49].flatGroup = 0;
    dataDesc_311[50].fieldType = FIELD_FLOAT;
    dataDesc_311[50].fieldName = "m_flStepSoundTime";
    dataDesc_311[50].fieldOffset = 3788;
    dataDesc_311[50].externalName = nullptr;
    dataDesc_311[50].pSaveRestoreOps = nullptr;
    dataDesc_311[50].inputFunc = nullptr;
    dataDesc_311[50].td = nullptr;
    dataDesc_311[50].fieldSizeInBytes = 4;
    dataDesc_311[50].override_field = nullptr;
    dataDesc_311[50].override_count = 0;
    dataDesc_311[50].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[50].flatGroup = 0;
    dataDesc_311[51].fieldType = FIELD_CHARACTER;
    dataDesc_311[51].fieldName = "m_szNetname";
    dataDesc_311[51].fieldOffset = 3969;
    dataDesc_311[51].externalName = nullptr;
    dataDesc_311[51].pSaveRestoreOps = nullptr;
    dataDesc_311[51].inputFunc = nullptr;
    dataDesc_311[51].td = nullptr;
    dataDesc_311[51].fieldSizeInBytes = 32;
    dataDesc_311[51].override_field = nullptr;
    dataDesc_311[51].override_count = 0;
    dataDesc_311[51].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[51].flatGroup = 0;
    dataDesc_311[52].fieldType = FIELD_INTEGER;
    dataDesc_311[52].fieldName = "m_idrowndmg";
    dataDesc_311[52].fieldOffset = 3184;
    dataDesc_311[52].externalName = nullptr;
    dataDesc_311[52].pSaveRestoreOps = nullptr;
    dataDesc_311[52].inputFunc = nullptr;
    dataDesc_311[52].td = nullptr;
    dataDesc_311[52].fieldSizeInBytes = 4;
    dataDesc_311[52].override_field = nullptr;
    dataDesc_311[52].override_count = 0;
    dataDesc_311[52].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[52].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[52].flatGroup = 0;
    dataDesc_311[53].fieldType = FIELD_INTEGER;
    dataDesc_311[53].fieldName = "m_idrownrestored";
    dataDesc_311[53].fieldOffset = 3188;
    dataDesc_311[53].flags = 2;
    dataDesc_311[53].externalName = nullptr;
    dataDesc_311[53].pSaveRestoreOps = nullptr;
    dataDesc_311[54].fieldSize = 1;
    dataDesc_311[54].flags = 2;
    dataDesc_311[55].fieldSize = 1;
    dataDesc_311[55].flags = 2;
    *(_QWORD *)dataDesc_311[53].flatOffset = 0;
    dataDesc_311[56].fieldSize = 1;
    *(_QWORD *)dataDesc_311[54].flatOffset = 0;
    dataDesc_311[56].flags = 2;
    *(_QWORD *)dataDesc_311[55].flatOffset = 0;
    dataDesc_311[57].fieldSize = 1;
    *(_QWORD *)dataDesc_311[56].flatOffset = 0;
    dataDesc_311[53].inputFunc = nullptr;
    dataDesc_311[53].td = nullptr;
    dataDesc_311[53].fieldSizeInBytes = 4;
    dataDesc_311[53].override_field = nullptr;
    dataDesc_311[53].override_count = 0;
    dataDesc_311[53].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[53].flatGroup = 0;
    dataDesc_311[54].fieldType = FIELD_INTEGER;
    dataDesc_311[54].fieldName = "m_nPoisonDmg";
    dataDesc_311[54].fieldOffset = 3192;
    dataDesc_311[54].externalName = nullptr;
    dataDesc_311[54].pSaveRestoreOps = nullptr;
    dataDesc_311[54].inputFunc = nullptr;
    dataDesc_311[54].td = nullptr;
    dataDesc_311[54].fieldSizeInBytes = 4;
    dataDesc_311[54].override_field = nullptr;
    dataDesc_311[54].override_count = 0;
    dataDesc_311[54].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[54].flatGroup = 0;
    dataDesc_311[55].fieldType = FIELD_INTEGER;
    dataDesc_311[55].fieldName = "m_nPoisonRestored";
    dataDesc_311[55].fieldOffset = 3196;
    dataDesc_311[55].externalName = nullptr;
    dataDesc_311[55].pSaveRestoreOps = nullptr;
    dataDesc_311[55].inputFunc = nullptr;
    dataDesc_311[55].td = nullptr;
    dataDesc_311[55].fieldSizeInBytes = 4;
    dataDesc_311[55].override_field = nullptr;
    dataDesc_311[55].override_count = 0;
    dataDesc_311[55].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[55].flatGroup = 0;
    dataDesc_311[56].fieldType = FIELD_INTEGER;
    dataDesc_311[56].fieldName = "m_bitsHUDDamage";
    dataDesc_311[56].fieldOffset = 3128;
    dataDesc_311[56].externalName = nullptr;
    dataDesc_311[56].pSaveRestoreOps = nullptr;
    dataDesc_311[56].inputFunc = nullptr;
    dataDesc_311[56].td = nullptr;
    dataDesc_311[56].fieldSizeInBytes = 4;
    dataDesc_311[56].override_field = nullptr;
    dataDesc_311[56].override_count = 0;
    dataDesc_311[56].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[56].flatGroup = 0;
    dataDesc_311[57].fieldType = FIELD_BOOLEAN;
    dataDesc_311[57].fieldName = "m_fInitHUD";
    dataDesc_311[57].fieldOffset = 3628;
    dataDesc_311[57].flags = 2;
    dataDesc_311[57].externalName = nullptr;
    dataDesc_311[57].pSaveRestoreOps = nullptr;
    dataDesc_311[57].inputFunc = nullptr;
    dataDesc_311[57].td = nullptr;
    dataDesc_311[57].fieldSizeInBytes = 1;
    dataDesc_311[57].override_field = nullptr;
    dataDesc_311[57].override_count = 0;
    dataDesc_311[57].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[57].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[57].flatGroup = 0;
    dataDesc_311[58].fieldSize = 1;
    dataDesc_311[58].flags = 2;
    dataDesc_311[59].fieldSize = 1;
    dataDesc_311[59].flags = 2;
    dataDesc_311[60].fieldSize = 1;
    dataDesc_311[60].flags = 2;
    dataDesc_311[61].fieldSize = 1;
    *(_QWORD *)dataDesc_311[58].flatOffset = 0;
    dataDesc_311[61].flags = 2;
    *(_QWORD *)dataDesc_311[59].flatOffset = 0;
    dataDesc_311[62].fieldSize = 1;
    *(_QWORD *)dataDesc_311[60].flatOffset = 0;
    dataDesc_311[58].fieldType = FIELD_TIME;
    dataDesc_311[58].fieldName = "m_flDeathTime";
    dataDesc_311[58].fieldOffset = 3132;
    dataDesc_311[58].externalName = nullptr;
    dataDesc_311[58].pSaveRestoreOps = nullptr;
    dataDesc_311[58].inputFunc = nullptr;
    dataDesc_311[58].td = nullptr;
    dataDesc_311[58].fieldSizeInBytes = 4;
    dataDesc_311[58].override_field = nullptr;
    dataDesc_311[58].override_count = 0;
    dataDesc_311[58].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[58].flatGroup = 0;
    dataDesc_311[59].fieldType = FIELD_TIME;
    dataDesc_311[59].fieldName = "m_flDeathAnimTime";
    dataDesc_311[59].fieldOffset = 3136;
    dataDesc_311[59].externalName = nullptr;
    dataDesc_311[59].pSaveRestoreOps = nullptr;
    dataDesc_311[59].inputFunc = nullptr;
    dataDesc_311[59].td = nullptr;
    dataDesc_311[59].fieldSizeInBytes = 4;
    dataDesc_311[59].override_field = nullptr;
    dataDesc_311[59].override_count = 0;
    dataDesc_311[59].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[59].flatGroup = 0;
    dataDesc_311[60].fieldType = FIELD_TIME;
    dataDesc_311[60].fieldName = "m_fForceTeam";
    dataDesc_311[60].fieldOffset = 3140;
    dataDesc_311[60].externalName = nullptr;
    dataDesc_311[60].pSaveRestoreOps = nullptr;
    dataDesc_311[60].inputFunc = nullptr;
    dataDesc_311[60].td = nullptr;
    dataDesc_311[60].fieldSizeInBytes = 4;
    dataDesc_311[60].override_field = nullptr;
    dataDesc_311[60].override_count = 0;
    dataDesc_311[60].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[60].flatGroup = 0;
    dataDesc_311[61].fieldType = FIELD_INTEGER;
    dataDesc_311[61].fieldName = "m_iFrags";
    dataDesc_311[61].fieldOffset = 3680;
    dataDesc_311[61].externalName = nullptr;
    dataDesc_311[61].pSaveRestoreOps = nullptr;
    dataDesc_311[61].inputFunc = nullptr;
    dataDesc_311[61].td = nullptr;
    dataDesc_311[61].fieldSizeInBytes = 4;
    dataDesc_311[61].override_field = nullptr;
    dataDesc_311[61].override_count = 0;
    dataDesc_311[61].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[61].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[61].flatGroup = 0;
    dataDesc_311[62].fieldType = FIELD_INTEGER;
    dataDesc_311[62].fieldName = "m_iDeaths";
    dataDesc_311[62].fieldOffset = 3684;
    dataDesc_311[62].flags = 2;
    dataDesc_311[62].externalName = nullptr;
    dataDesc_311[62].pSaveRestoreOps = nullptr;
    dataDesc_311[63].fieldSize = 1;
    dataDesc_311[63].flags = 2;
    dataDesc_311[64].fieldSize = 1;
    dataDesc_311[64].flags = 2;
    *(_QWORD *)dataDesc_311[62].flatOffset = 0;
    dataDesc_311[65].fieldSize = 1;
    *(_QWORD *)dataDesc_311[63].flatOffset = 0;
    dataDesc_311[65].flags = 2;
    *(_QWORD *)dataDesc_311[64].flatOffset = 0;
    dataDesc_311[66].fieldSize = 1;
    *(_QWORD *)dataDesc_311[65].flatOffset = 0;
    dataDesc_311[62].inputFunc = nullptr;
    dataDesc_311[62].td = nullptr;
    dataDesc_311[62].fieldSizeInBytes = 4;
    dataDesc_311[62].override_field = nullptr;
    dataDesc_311[62].override_count = 0;
    dataDesc_311[62].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[62].flatGroup = 0;
    dataDesc_311[63].fieldType = FIELD_BOOLEAN;
    dataDesc_311[63].fieldName = "m_bAllowInstantSpawn";
    dataDesc_311[63].fieldOffset = 3792;
    dataDesc_311[63].externalName = nullptr;
    dataDesc_311[63].pSaveRestoreOps = nullptr;
    dataDesc_311[63].inputFunc = nullptr;
    dataDesc_311[63].td = nullptr;
    dataDesc_311[63].fieldSizeInBytes = 1;
    dataDesc_311[63].override_field = nullptr;
    dataDesc_311[63].override_count = 0;
    dataDesc_311[63].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[63].flatGroup = 0;
    dataDesc_311[64].fieldType = FIELD_TIME;
    dataDesc_311[64].fieldName = "m_flNextDecalTime";
    dataDesc_311[64].fieldOffset = 3652;
    dataDesc_311[64].externalName = nullptr;
    dataDesc_311[64].pSaveRestoreOps = nullptr;
    dataDesc_311[64].inputFunc = nullptr;
    dataDesc_311[64].td = nullptr;
    dataDesc_311[64].fieldSizeInBytes = 4;
    dataDesc_311[64].override_field = nullptr;
    dataDesc_311[64].override_count = 0;
    dataDesc_311[64].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[64].flatGroup = 0;
    dataDesc_311[65].fieldType = FIELD_INTEGER;
    dataDesc_311[65].fieldName = "m_ArmorValue";
    dataDesc_311[65].fieldOffset = 3660;
    dataDesc_311[65].externalName = nullptr;
    dataDesc_311[65].pSaveRestoreOps = nullptr;
    dataDesc_311[65].inputFunc = nullptr;
    dataDesc_311[65].td = nullptr;
    dataDesc_311[65].fieldSizeInBytes = 4;
    dataDesc_311[65].override_field = nullptr;
    dataDesc_311[65].override_count = 0;
    dataDesc_311[65].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[65].flatGroup = 0;
    dataDesc_311[66].fieldType = FIELD_VECTOR;
    dataDesc_311[66].fieldName = "m_DmgOrigin";
    dataDesc_311[66].fieldOffset = 3104;
    dataDesc_311[66].flags = 2;
    dataDesc_311[66].externalName = nullptr;
    dataDesc_311[66].pSaveRestoreOps = nullptr;
    dataDesc_311[66].inputFunc = nullptr;
    dataDesc_311[66].td = nullptr;
    dataDesc_311[66].fieldSizeInBytes = 12;
    dataDesc_311[66].override_field = nullptr;
    dataDesc_311[66].override_count = 0;
    dataDesc_311[66].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[66].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[66].flatGroup = 0;
    dataDesc_311[67].fieldSize = 1;
    dataDesc_311[67].flags = 2;
    dataDesc_311[68].fieldSize = 1;
    dataDesc_311[68].flags = 2;
    dataDesc_311[69].fieldSize = 1;
    dataDesc_311[69].flags = 2;
    dataDesc_311[70].fieldSize = 1;
    *(_QWORD *)dataDesc_311[67].flatOffset = 0;
    dataDesc_311[70].flags = 2;
    *(_QWORD *)dataDesc_311[68].flatOffset = 0;
    dataDesc_311[71].fieldSize = 1;
    *(_QWORD *)dataDesc_311[69].flatOffset = 0;
    dataDesc_311[67].fieldType = FIELD_FLOAT;
    dataDesc_311[67].fieldName = "m_DmgTake";
    dataDesc_311[67].fieldOffset = 3116;
    dataDesc_311[67].externalName = nullptr;
    dataDesc_311[67].pSaveRestoreOps = nullptr;
    dataDesc_311[67].inputFunc = nullptr;
    dataDesc_311[67].td = nullptr;
    dataDesc_311[67].fieldSizeInBytes = 4;
    dataDesc_311[67].override_field = nullptr;
    dataDesc_311[67].override_count = 0;
    dataDesc_311[67].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[67].flatGroup = 0;
    dataDesc_311[68].fieldType = FIELD_FLOAT;
    dataDesc_311[68].fieldName = "m_DmgSave";
    dataDesc_311[68].fieldOffset = 3120;
    dataDesc_311[68].externalName = nullptr;
    dataDesc_311[68].pSaveRestoreOps = nullptr;
    dataDesc_311[68].inputFunc = nullptr;
    dataDesc_311[68].td = nullptr;
    dataDesc_311[68].fieldSizeInBytes = 4;
    dataDesc_311[68].override_field = nullptr;
    dataDesc_311[68].override_count = 0;
    dataDesc_311[68].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[68].flatGroup = 0;
    dataDesc_311[69].fieldType = FIELD_TIME;
    dataDesc_311[69].fieldName = "m_AirFinished";
    dataDesc_311[69].fieldOffset = 3664;
    dataDesc_311[69].externalName = nullptr;
    dataDesc_311[69].pSaveRestoreOps = nullptr;
    dataDesc_311[69].inputFunc = nullptr;
    dataDesc_311[69].td = nullptr;
    dataDesc_311[69].fieldSizeInBytes = 4;
    dataDesc_311[69].override_field = nullptr;
    dataDesc_311[69].override_count = 0;
    dataDesc_311[69].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[69].flatGroup = 0;
    dataDesc_311[70].fieldType = FIELD_TIME;
    dataDesc_311[70].fieldName = "m_PainFinished";
    dataDesc_311[70].fieldOffset = 3668;
    dataDesc_311[70].externalName = nullptr;
    dataDesc_311[70].pSaveRestoreOps = nullptr;
    dataDesc_311[70].inputFunc = nullptr;
    dataDesc_311[70].td = nullptr;
    dataDesc_311[70].fieldSizeInBytes = 4;
    dataDesc_311[70].override_field = nullptr;
    dataDesc_311[70].override_count = 0;
    dataDesc_311[70].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[70].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[70].flatGroup = 0;
    dataDesc_311[71].fieldType = FIELD_INTEGER;
    dataDesc_311[71].fieldName = "m_iPlayerLocked";
    dataDesc_311[71].fieldOffset = 3672;
    dataDesc_311[71].flags = 2;
    dataDesc_311[71].externalName = nullptr;
    dataDesc_311[71].pSaveRestoreOps = nullptr;
    dataDesc_311[72].fieldSize = 2;
    dataDesc_311[72].flags = 2;
    dataDesc_311[73].fieldSize = 1;
    dataDesc_311[73].flags = 2;
    *(_QWORD *)dataDesc_311[71].flatOffset = 0;
    dataDesc_311[74].fieldSize = 1;
    *(_QWORD *)dataDesc_311[72].flatOffset = 0;
    dataDesc_311[74].flags = 2;
    *(_QWORD *)dataDesc_311[73].flatOffset = 0;
    dataDesc_311[75].fieldSize = 1;
    *(_QWORD *)dataDesc_311[74].flatOffset = 0;
    dataDesc_311[71].inputFunc = nullptr;
    dataDesc_311[71].td = nullptr;
    dataDesc_311[71].fieldSizeInBytes = 4;
    dataDesc_311[71].override_field = nullptr;
    dataDesc_311[71].override_count = 0;
    dataDesc_311[71].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[71].flatGroup = 0;
    dataDesc_311[72].fieldType = FIELD_EHANDLE;
    dataDesc_311[72].fieldName = "m_hViewModel";
    dataDesc_311[72].fieldOffset = 3688;
    dataDesc_311[72].externalName = nullptr;
    dataDesc_311[72].pSaveRestoreOps = nullptr;
    dataDesc_311[72].inputFunc = nullptr;
    dataDesc_311[72].td = nullptr;
    dataDesc_311[72].fieldSizeInBytes = 8;
    dataDesc_311[72].override_field = nullptr;
    dataDesc_311[72].override_count = 0;
    dataDesc_311[72].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[72].flatGroup = 0;
    dataDesc_311[73].fieldType = FIELD_FLOAT;
    dataDesc_311[73].fieldName = "m_flMaxspeed";
    dataDesc_311[73].fieldOffset = 3796;
    dataDesc_311[73].externalName = nullptr;
    dataDesc_311[73].pSaveRestoreOps = nullptr;
    dataDesc_311[73].inputFunc = nullptr;
    dataDesc_311[73].td = nullptr;
    dataDesc_311[73].fieldSizeInBytes = 4;
    dataDesc_311[73].override_field = nullptr;
    dataDesc_311[73].override_count = 0;
    dataDesc_311[73].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[73].flatGroup = 0;
    dataDesc_311[74].fieldType = FIELD_TIME;
    dataDesc_311[74].fieldName = "m_flWaterJumpTime";
    dataDesc_311[74].fieldOffset = 3816;
    dataDesc_311[74].externalName = nullptr;
    dataDesc_311[74].pSaveRestoreOps = nullptr;
    dataDesc_311[74].inputFunc = nullptr;
    dataDesc_311[74].td = nullptr;
    dataDesc_311[74].fieldSizeInBytes = 4;
    dataDesc_311[74].override_field = nullptr;
    dataDesc_311[74].override_count = 0;
    dataDesc_311[74].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[74].flatGroup = 0;
    dataDesc_311[75].fieldType = FIELD_VECTOR;
    dataDesc_311[75].fieldName = "m_vecWaterJumpVel";
    dataDesc_311[75].fieldOffset = 3820;
    dataDesc_311[75].flags = 2;
    dataDesc_311[75].externalName = nullptr;
    dataDesc_311[75].pSaveRestoreOps = nullptr;
    dataDesc_311[75].inputFunc = nullptr;
    dataDesc_311[75].td = nullptr;
    dataDesc_311[75].fieldSizeInBytes = 12;
    dataDesc_311[75].override_field = nullptr;
    dataDesc_311[75].override_count = 0;
    dataDesc_311[75].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[75].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[75].flatGroup = 0;
    dataDesc_311[76].fieldType = FIELD_INTEGER;
    dataDesc_311[76].fieldName = "m_nImpulse";
    dataDesc_311[76].fieldSize = 1;
    dataDesc_311[76].flags = 2;
    dataDesc_311[77].fieldSize = 1;
    dataDesc_311[77].flags = 2;
    dataDesc_311[78].fieldSize = 1;
    dataDesc_311[78].flags = 2;
    dataDesc_311[79].fieldSize = 1;
    *(_QWORD *)dataDesc_311[76].flatOffset = 0;
    dataDesc_311[79].flags = 2;
    *(_QWORD *)dataDesc_311[77].flatOffset = 0;
    dataDesc_311[80].fieldSize = 1;
    *(_QWORD *)dataDesc_311[78].flatOffset = 0;
    dataDesc_311[76].fieldOffset = 3832;
    dataDesc_311[76].externalName = nullptr;
    dataDesc_311[76].pSaveRestoreOps = nullptr;
    dataDesc_311[76].inputFunc = nullptr;
    dataDesc_311[76].td = nullptr;
    dataDesc_311[76].fieldSizeInBytes = 4;
    dataDesc_311[76].override_field = nullptr;
    dataDesc_311[76].override_count = 0;
    dataDesc_311[76].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[76].flatGroup = 0;
    dataDesc_311[77].fieldType = FIELD_TIME;
    dataDesc_311[77].fieldName = "m_flSwimSoundTime";
    dataDesc_311[77].fieldOffset = 3836;
    dataDesc_311[77].externalName = nullptr;
    dataDesc_311[77].pSaveRestoreOps = nullptr;
    dataDesc_311[77].inputFunc = nullptr;
    dataDesc_311[77].td = nullptr;
    dataDesc_311[77].fieldSizeInBytes = 4;
    dataDesc_311[77].override_field = nullptr;
    dataDesc_311[77].override_count = 0;
    dataDesc_311[77].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[77].flatGroup = 0;
    dataDesc_311[78].fieldType = FIELD_VECTOR;
    dataDesc_311[78].fieldName = "m_vecLadderNormal";
    dataDesc_311[78].fieldOffset = 3804;
    dataDesc_311[78].externalName = nullptr;
    dataDesc_311[78].pSaveRestoreOps = nullptr;
    dataDesc_311[78].inputFunc = nullptr;
    dataDesc_311[78].td = nullptr;
    dataDesc_311[78].fieldSizeInBytes = 12;
    dataDesc_311[78].override_field = nullptr;
    dataDesc_311[78].override_count = 0;
    dataDesc_311[78].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[78].flatGroup = 0;
    dataDesc_311[79].fieldType = FIELD_TIME;
    dataDesc_311[79].fieldName = "m_flFlashTime";
    dataDesc_311[79].fieldOffset = 3840;
    dataDesc_311[79].externalName = nullptr;
    dataDesc_311[79].pSaveRestoreOps = nullptr;
    dataDesc_311[79].inputFunc = nullptr;
    dataDesc_311[79].td = nullptr;
    dataDesc_311[79].fieldSizeInBytes = 4;
    dataDesc_311[79].override_field = nullptr;
    dataDesc_311[79].override_count = 0;
    dataDesc_311[79].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[79].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[79].flatGroup = 0;
    dataDesc_311[80].fieldType = FIELD_INTEGER;
    dataDesc_311[80].fieldName = "m_nDrownDmgRate";
    dataDesc_311[80].fieldOffset = 3844;
    dataDesc_311[80].flags = 2;
    dataDesc_311[80].externalName = nullptr;
    dataDesc_311[80].pSaveRestoreOps = nullptr;
    dataDesc_311[80].inputFunc = nullptr;
    dataDesc_311[80].td = nullptr;
    dataDesc_311[81].fieldSize = 1;
    dataDesc_311[81].flags = 2;
    dataDesc_311[82].fieldSize = 1;
    dataDesc_311[82].flags = 2;
    *(_QWORD *)dataDesc_311[80].flatOffset = 0;
    dataDesc_311[83].fieldSize = 8;
    *(_QWORD *)dataDesc_311[81].flatOffset = 0;
    dataDesc_311[83].flags = 2;
    *(_QWORD *)dataDesc_311[82].flatOffset = 0;
    dataDesc_311[84].fieldSize = 1;
    *(_QWORD *)dataDesc_311[83].flatOffset = 0;
    dataDesc_311[80].fieldSizeInBytes = 4;
    dataDesc_311[80].override_field = nullptr;
    dataDesc_311[80].override_count = 0;
    dataDesc_311[80].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[80].flatGroup = 0;
    dataDesc_311[81].fieldType = FIELD_INTEGER;
    dataDesc_311[81].fieldName = "m_iSuicideCustomKillFlags";
    dataDesc_311[81].fieldOffset = 3216;
    dataDesc_311[81].externalName = nullptr;
    dataDesc_311[81].pSaveRestoreOps = nullptr;
    dataDesc_311[81].inputFunc = nullptr;
    dataDesc_311[81].td = nullptr;
    dataDesc_311[81].fieldSizeInBytes = 4;
    dataDesc_311[81].override_field = nullptr;
    dataDesc_311[81].override_count = 0;
    dataDesc_311[81].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[81].flatGroup = 0;
    dataDesc_311[82].fieldType = FIELD_INTEGER;
    dataDesc_311[82].fieldName = "m_bitsDamageType";
    dataDesc_311[82].fieldOffset = 3124;
    dataDesc_311[82].externalName = nullptr;
    dataDesc_311[82].pSaveRestoreOps = nullptr;
    dataDesc_311[82].inputFunc = nullptr;
    dataDesc_311[82].td = nullptr;
    dataDesc_311[82].fieldSizeInBytes = 4;
    dataDesc_311[82].override_field = nullptr;
    dataDesc_311[82].override_count = 0;
    dataDesc_311[82].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[82].flatGroup = 0;
    dataDesc_311[83].fieldType = FIELD_CHARACTER;
    dataDesc_311[83].fieldName = "m_rgbTimeBasedDamage";
    dataDesc_311[83].fieldOffset = 3200;
    dataDesc_311[83].externalName = nullptr;
    dataDesc_311[83].pSaveRestoreOps = nullptr;
    dataDesc_311[83].inputFunc = nullptr;
    dataDesc_311[83].td = nullptr;
    dataDesc_311[83].fieldSizeInBytes = 8;
    dataDesc_311[83].override_field = nullptr;
    dataDesc_311[83].override_count = 0;
    dataDesc_311[83].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[83].flatGroup = 0;
    dataDesc_311[84].fieldType = FIELD_FLOAT;
    dataDesc_311[84].fieldName = "m_fLastPlayerTalkTime";
    dataDesc_311[84].fieldOffset = 3892;
    dataDesc_311[84].flags = 2;
    dataDesc_311[84].externalName = nullptr;
    dataDesc_311[84].pSaveRestoreOps = nullptr;
    dataDesc_311[84].inputFunc = nullptr;
    dataDesc_311[84].td = nullptr;
    dataDesc_311[84].fieldSizeInBytes = 4;
    dataDesc_311[84].override_field = nullptr;
    dataDesc_311[84].override_count = 0;
    dataDesc_311[84].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[84].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[84].flatGroup = 0;
    dataDesc_311[85].fieldType = FIELD_EHANDLE;
    dataDesc_311[85].fieldName = "m_hLastWeapon";
    dataDesc_311[85].fieldSize = 1;
    dataDesc_311[85].flags = 2;
    dataDesc_311[86].fieldSize = 1;
    dataDesc_311[86].flags = 2;
    dataDesc_311[87].fieldSize = 1;
    dataDesc_311[87].flags = 2;
    dataDesc_311[88].fieldSize = 1;
    *(_QWORD *)dataDesc_311[85].flatOffset = 0;
    dataDesc_311[88].flags = 2;
    *(_QWORD *)dataDesc_311[86].flatOffset = 0;
    dataDesc_311[89].fieldSize = 1;
    *(_QWORD *)dataDesc_311[87].flatOffset = 0;
    dataDesc_311[85].fieldOffset = 3896;
    dataDesc_311[85].externalName = nullptr;
    dataDesc_311[85].pSaveRestoreOps = nullptr;
    dataDesc_311[85].inputFunc = nullptr;
    dataDesc_311[85].td = nullptr;
    dataDesc_311[85].fieldSizeInBytes = 4;
    dataDesc_311[85].override_field = nullptr;
    dataDesc_311[85].override_count = 0;
    dataDesc_311[85].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[85].flatGroup = 0;
    dataDesc_311[86].fieldType = FIELD_FLOAT;
    dataDesc_311[86].fieldName = "m_flOldPlayerZ";
    dataDesc_311[86].fieldOffset = 3920;
    dataDesc_311[86].externalName = nullptr;
    dataDesc_311[86].pSaveRestoreOps = nullptr;
    dataDesc_311[86].inputFunc = nullptr;
    dataDesc_311[86].td = nullptr;
    dataDesc_311[86].fieldSizeInBytes = 4;
    dataDesc_311[86].override_field = nullptr;
    dataDesc_311[86].override_count = 0;
    dataDesc_311[86].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[86].flatGroup = 0;
    dataDesc_311[87].fieldType = FIELD_FLOAT;
    dataDesc_311[87].fieldName = "m_flOldPlayerViewOffsetZ";
    dataDesc_311[87].fieldOffset = 3924;
    dataDesc_311[87].externalName = nullptr;
    dataDesc_311[87].pSaveRestoreOps = nullptr;
    dataDesc_311[87].inputFunc = nullptr;
    dataDesc_311[87].td = nullptr;
    dataDesc_311[87].fieldSizeInBytes = 4;
    dataDesc_311[87].override_field = nullptr;
    dataDesc_311[87].override_count = 0;
    dataDesc_311[87].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[87].flatGroup = 0;
    dataDesc_311[88].fieldType = FIELD_BOOLEAN;
    dataDesc_311[88].fieldName = "m_bPlayerUnderwater";
    dataDesc_311[88].fieldOffset = 3928;
    dataDesc_311[88].externalName = nullptr;
    dataDesc_311[88].pSaveRestoreOps = nullptr;
    dataDesc_311[88].inputFunc = nullptr;
    dataDesc_311[88].td = nullptr;
    dataDesc_311[88].fieldSizeInBytes = 1;
    dataDesc_311[88].override_field = nullptr;
    dataDesc_311[88].override_count = 0;
    dataDesc_311[88].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[88].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[88].flatGroup = 0;
    dataDesc_311[89].fieldType = FIELD_EHANDLE;
    dataDesc_311[89].fieldName = "m_hViewEntity";
    dataDesc_311[89].fieldOffset = 3932;
    dataDesc_311[89].flags = 2;
    dataDesc_311[89].externalName = nullptr;
    dataDesc_311[89].pSaveRestoreOps = nullptr;
    dataDesc_311[89].inputFunc = nullptr;
    dataDesc_311[89].td = nullptr;
    dataDesc_311[90].fieldSize = 1;
    dataDesc_311[90].flags = 2;
    dataDesc_311[91].fieldSize = 1;
    dataDesc_311[91].flags = 2;
    *(_QWORD *)dataDesc_311[89].flatOffset = 0;
    dataDesc_311[92].fieldSize = 1;
    *(_QWORD *)dataDesc_311[90].flatOffset = 0;
    dataDesc_311[92].flags = 2;
    *(_QWORD *)dataDesc_311[91].flatOffset = 0;
    dataDesc_311[93].fieldSize = 1;
    *(_QWORD *)dataDesc_311[92].flatOffset = 0;
    dataDesc_311[89].fieldSizeInBytes = 4;
    dataDesc_311[89].override_field = nullptr;
    dataDesc_311[89].override_count = 0;
    dataDesc_311[89].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[89].flatGroup = 0;
    dataDesc_311[90].fieldType = FIELD_BOOLEAN;
    dataDesc_311[90].fieldName = "m_bShouldDrawPlayerWhileUsingViewEntity";
    dataDesc_311[90].fieldOffset = 3936;
    dataDesc_311[90].externalName = nullptr;
    dataDesc_311[90].pSaveRestoreOps = nullptr;
    dataDesc_311[90].inputFunc = nullptr;
    dataDesc_311[90].td = nullptr;
    dataDesc_311[90].fieldSizeInBytes = 1;
    dataDesc_311[90].override_field = nullptr;
    dataDesc_311[90].override_count = 0;
    dataDesc_311[90].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[90].flatGroup = 0;
    dataDesc_311[91].fieldType = FIELD_EHANDLE;
    dataDesc_311[91].fieldName = "m_hConstraintEntity";
    dataDesc_311[91].fieldOffset = 3940;
    dataDesc_311[91].externalName = nullptr;
    dataDesc_311[91].pSaveRestoreOps = nullptr;
    dataDesc_311[91].inputFunc = nullptr;
    dataDesc_311[91].td = nullptr;
    dataDesc_311[91].fieldSizeInBytes = 4;
    dataDesc_311[91].override_field = nullptr;
    dataDesc_311[91].override_count = 0;
    dataDesc_311[91].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[91].flatGroup = 0;
    dataDesc_311[92].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_311[92].fieldName = "m_vecConstraintCenter";
    dataDesc_311[92].fieldOffset = 3944;
    dataDesc_311[92].externalName = nullptr;
    dataDesc_311[92].pSaveRestoreOps = nullptr;
    dataDesc_311[92].inputFunc = nullptr;
    dataDesc_311[92].td = nullptr;
    dataDesc_311[92].fieldSizeInBytes = 12;
    dataDesc_311[92].override_field = nullptr;
    dataDesc_311[92].override_count = 0;
    dataDesc_311[92].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[92].flatGroup = 0;
    dataDesc_311[93].fieldType = FIELD_FLOAT;
    dataDesc_311[93].fieldName = "m_flConstraintRadius";
    dataDesc_311[93].fieldOffset = 3956;
    dataDesc_311[93].flags = 2;
    dataDesc_311[93].externalName = nullptr;
    dataDesc_311[93].pSaveRestoreOps = nullptr;
    dataDesc_311[93].inputFunc = nullptr;
    dataDesc_311[93].td = nullptr;
    dataDesc_311[93].fieldSizeInBytes = 4;
    dataDesc_311[93].override_field = nullptr;
    dataDesc_311[93].override_count = 0;
    dataDesc_311[93].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[93].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[93].flatGroup = 0;
    dataDesc_311[94].fieldType = FIELD_FLOAT;
    dataDesc_311[94].fieldName = "m_flConstraintWidth";
    dataDesc_311[94].fieldSize = 1;
    dataDesc_311[94].flags = 2;
    dataDesc_311[95].fieldSize = 1;
    dataDesc_311[95].flags = 2;
    dataDesc_311[96].fieldSize = 1;
    dataDesc_311[96].flags = 2;
    dataDesc_311[97].fieldSize = 1;
    *(_QWORD *)dataDesc_311[94].flatOffset = 0;
    dataDesc_311[97].flags = 2;
    *(_QWORD *)dataDesc_311[95].flatOffset = 0;
    dataDesc_311[98].fieldSize = 1;
    *(_QWORD *)dataDesc_311[96].flatOffset = 0;
    dataDesc_311[94].fieldOffset = 3960;
    dataDesc_311[94].externalName = nullptr;
    dataDesc_311[94].pSaveRestoreOps = nullptr;
    dataDesc_311[94].inputFunc = nullptr;
    dataDesc_311[94].td = nullptr;
    dataDesc_311[94].fieldSizeInBytes = 4;
    dataDesc_311[94].override_field = nullptr;
    dataDesc_311[94].override_count = 0;
    dataDesc_311[94].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[94].flatGroup = 0;
    dataDesc_311[95].fieldType = FIELD_FLOAT;
    dataDesc_311[95].fieldName = "m_flConstraintSpeedFactor";
    dataDesc_311[95].fieldOffset = 3964;
    dataDesc_311[95].externalName = nullptr;
    dataDesc_311[95].pSaveRestoreOps = nullptr;
    dataDesc_311[95].inputFunc = nullptr;
    dataDesc_311[95].td = nullptr;
    dataDesc_311[95].fieldSizeInBytes = 4;
    dataDesc_311[95].override_field = nullptr;
    dataDesc_311[95].override_count = 0;
    dataDesc_311[95].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[95].flatGroup = 0;
    dataDesc_311[96].fieldType = FIELD_BOOLEAN;
    dataDesc_311[96].fieldName = "m_bConstraintPastRadius";
    dataDesc_311[96].fieldOffset = 3968;
    dataDesc_311[96].externalName = nullptr;
    dataDesc_311[96].pSaveRestoreOps = nullptr;
    dataDesc_311[96].inputFunc = nullptr;
    dataDesc_311[96].td = nullptr;
    dataDesc_311[96].fieldSizeInBytes = 1;
    dataDesc_311[96].override_field = nullptr;
    dataDesc_311[96].override_count = 0;
    dataDesc_311[96].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[96].flatGroup = 0;
    dataDesc_311[97].fieldType = FIELD_EHANDLE;
    dataDesc_311[97].fieldName = "m_hZoomOwner";
    dataDesc_311[97].fieldOffset = 3176;
    dataDesc_311[97].externalName = nullptr;
    dataDesc_311[97].pSaveRestoreOps = nullptr;
    dataDesc_311[97].inputFunc = nullptr;
    dataDesc_311[97].td = nullptr;
    dataDesc_311[97].fieldSizeInBytes = 4;
    dataDesc_311[97].override_field = nullptr;
    dataDesc_311[97].override_count = 0;
    dataDesc_311[97].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[97].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[97].flatGroup = 0;
    dataDesc_311[98].fieldType = FIELD_FLOAT;
    dataDesc_311[98].fieldName = "m_flLaggedMovementValue";
    dataDesc_311[98].fieldOffset = 4004;
    dataDesc_311[98].flags = 2;
    dataDesc_311[98].externalName = nullptr;
    dataDesc_311[98].pSaveRestoreOps = nullptr;
    dataDesc_311[98].inputFunc = nullptr;
    dataDesc_311[98].td = nullptr;
    dataDesc_311[99].fieldSize = 1;
    dataDesc_311[99].flags = 2;
    dataDesc_311[100].fieldSize = 1;
    dataDesc_311[100].flags = 2;
    *(_QWORD *)dataDesc_311[98].flatOffset = 0;
    dataDesc_311[101].fieldSize = 1;
    *(_QWORD *)dataDesc_311[99].flatOffset = 0;
    dataDesc_311[101].flags = 2;
    *(_QWORD *)dataDesc_311[100].flatOffset = 0;
    dataDesc_311[102].fieldSize = 18;
    *(_QWORD *)dataDesc_311[101].flatOffset = 0;
    dataDesc_311[98].fieldSizeInBytes = 4;
    dataDesc_311[98].override_field = nullptr;
    dataDesc_311[98].override_count = 0;
    dataDesc_311[98].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[98].flatGroup = 0;
    dataDesc_311[99].fieldType = FIELD_VECTOR;
    dataDesc_311[99].fieldName = "m_vNewVPhysicsPosition";
    dataDesc_311[99].fieldOffset = 4008;
    dataDesc_311[99].externalName = nullptr;
    dataDesc_311[99].pSaveRestoreOps = nullptr;
    dataDesc_311[99].inputFunc = nullptr;
    dataDesc_311[99].td = nullptr;
    dataDesc_311[99].fieldSizeInBytes = 12;
    dataDesc_311[99].override_field = nullptr;
    dataDesc_311[99].override_count = 0;
    dataDesc_311[99].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[99].flatGroup = 0;
    dataDesc_311[100].fieldType = FIELD_VECTOR;
    dataDesc_311[100].fieldName = "m_vNewVPhysicsVelocity";
    dataDesc_311[100].fieldOffset = 4020;
    dataDesc_311[100].externalName = nullptr;
    dataDesc_311[100].pSaveRestoreOps = nullptr;
    dataDesc_311[100].inputFunc = nullptr;
    dataDesc_311[100].td = nullptr;
    dataDesc_311[100].fieldSizeInBytes = 12;
    dataDesc_311[100].override_field = nullptr;
    dataDesc_311[100].override_count = 0;
    dataDesc_311[100].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[100].flatGroup = 0;
    dataDesc_311[101].fieldType = FIELD_BOOLEAN;
    dataDesc_311[101].fieldName = "m_bSinglePlayerGameEnding";
    dataDesc_311[101].fieldOffset = 4190;
    dataDesc_311[101].externalName = nullptr;
    dataDesc_311[101].pSaveRestoreOps = nullptr;
    dataDesc_311[101].inputFunc = nullptr;
    dataDesc_311[101].td = nullptr;
    dataDesc_311[101].fieldSizeInBytes = 1;
    dataDesc_311[101].override_field = nullptr;
    dataDesc_311[101].override_count = 0;
    dataDesc_311[101].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[101].flatGroup = 0;
    dataDesc_311[102].fieldType = FIELD_CHARACTER;
    dataDesc_311[102].fieldName = "m_szLastPlaceName";
    dataDesc_311[102].fieldOffset = 4080;
    dataDesc_311[102].flags = 2;
    dataDesc_311[102].externalName = nullptr;
    dataDesc_311[102].pSaveRestoreOps = nullptr;
    dataDesc_311[102].inputFunc = nullptr;
    dataDesc_311[102].td = nullptr;
    dataDesc_311[102].fieldSizeInBytes = 18;
    dataDesc_311[102].override_field = nullptr;
    dataDesc_311[102].override_count = 0;
    dataDesc_311[102].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[102].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[102].flatGroup = 0;
    dataDesc_311[103].fieldType = FIELD_BOOLEAN;
    dataDesc_311[103].fieldName = "m_autoKickDisabled";
    dataDesc_311[103].fieldSize = 1;
    dataDesc_311[103].fieldTolerance = 0.0;
    dataDesc_311[103].fieldOffset = 4200;
    dataDesc_311[103].flags = 2;
    dataDesc_311[103].externalName = nullptr;
    dataDesc_311[103].pSaveRestoreOps = nullptr;
    dataDesc_311[103].inputFunc = nullptr;
    dataDesc_311[103].td = nullptr;
    dataDesc_311[103].fieldSizeInBytes = 1;
    dataDesc_311[103].override_field = nullptr;
    dataDesc_311[103].override_count = 0;
    *(_QWORD *)dataDesc_311[103].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[103].flatGroup = 0;
    dataDesc_311[104].fieldType = FIELD_VOID;
    dataDesc_311[104].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                    this: &nameHolder_324,
                                    pszIdentifier: "PlayerDeathThink");
    dataDesc_311[104].fieldOffset = 0;
    *(_DWORD *)&dataDesc_311[104].fieldSize = 2097153;
    dataDesc_311[104].externalName = nullptr;
    dataDesc_311[104].pSaveRestoreOps = nullptr;
    dataDesc_311[104].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBasePlayer::`vcall'{1392,{flat}};
    *(_QWORD *)&dataDesc_311[104].td = 0;
    *(_QWORD *)&dataDesc_311[104].override_field = 0;
    *(_QWORD *)&dataDesc_311[104].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_311[104].flatOffset[1] = 0;
    dataDesc_311[105].fieldType = FIELD_VOID;
    dataDesc_311[105].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                    this: &nameHolder_324,
                                    pszIdentifier: "PlayerForceTeamThink");
    dataDesc_311[105].flags = 32;
    *(_QWORD *)&dataDesc_311[105].td = 0;
    *(_QWORD *)&dataDesc_311[105].override_field = 0;
    *(_QWORD *)&dataDesc_311[105].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_311[105].flatOffset[1] = 0;
    dataDesc_311[105].fieldSize = 1;
    dataDesc_311[106].fieldSize = 1;
    dataDesc_311[106].flags = 8;
    dataDesc_311[107].fieldSize = 1;
    *(_QWORD *)&dataDesc_311[106].td = 0;
    *(_QWORD *)&dataDesc_311[106].override_field = 0;
    *(_QWORD *)&dataDesc_311[106].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_311[106].flatOffset[1] = 0;
    dataDesc_311[105].fieldOffset = 0;
    dataDesc_311[105].externalName = nullptr;
    dataDesc_311[105].pSaveRestoreOps = nullptr;
    dataDesc_311[105].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBasePlayer::`vcall'{1396,{flat}};
    dataDesc_311[106].fieldType = FIELD_INTEGER;
    dataDesc_311[106].fieldName = "InputSetHealth";
    dataDesc_311[106].fieldOffset = 0;
    dataDesc_311[106].externalName = "SetHealth";
    dataDesc_311[106].pSaveRestoreOps = nullptr;
    dataDesc_311[106].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBasePlayer::InputSetHealth;
    dataDesc_311[107].fieldType = FIELD_BOOLEAN;
    dataDesc_311[107].fieldName = "InputSetHUDVisibility";
    dataDesc_311[107].fieldOffset = 0;
    dataDesc_311[107].flags = 8;
    dataDesc_311[107].externalName = "SetHUDVisibility";
    dataDesc_311[107].pSaveRestoreOps = nullptr;
    dataDesc_311[107].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBasePlayer::InputSetHUDVisibility;
    *(_QWORD *)&dataDesc_311[107].td = 0;
    *(_QWORD *)&dataDesc_311[107].override_field = 0;
    *(_QWORD *)&dataDesc_311[107].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_311[107].flatOffset[1] = 0;
    dataDesc_311[108].fieldType = FIELD_STRING;
    dataDesc_311[108].fieldName = "InputSetFogController";
    dataDesc_311[108].fieldOffset = 0;
    dataDesc_311[108].fieldSize = 1;
    *(_QWORD *)dataDesc_311[109].flatOffset = 0;
    dataDesc_311[108].flags = 8;
    *(_QWORD *)dataDesc_311[110].flatOffset = 0;
    dataDesc_311[109].fieldSize = 1;
    dataDesc_311[110].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)&dataDesc_311[108].td = 0;
    *(_QWORD *)&dataDesc_311[108].override_field = 0;
    *(_QWORD *)&dataDesc_311[108].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_311[108].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_311[111].flatOffset = 0;
    dataDesc_311[108].externalName = "SetFogController";
    dataDesc_311[108].pSaveRestoreOps = nullptr;
    dataDesc_311[108].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBasePlayer::InputSetFogController;
    dataDesc_311[109].fieldType = FIELD_INTEGER;
    dataDesc_311[109].fieldName = "m_nNumCrouches";
    dataDesc_311[109].fieldOffset = 3848;
    dataDesc_311[109].flags = 2;
    dataDesc_311[109].externalName = nullptr;
    dataDesc_311[109].pSaveRestoreOps = nullptr;
    dataDesc_311[109].inputFunc = nullptr;
    dataDesc_311[109].td = nullptr;
    dataDesc_311[109].fieldSizeInBytes = 4;
    dataDesc_311[109].override_field = nullptr;
    dataDesc_311[109].override_count = 0;
    dataDesc_311[109].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[109].flatGroup = 0;
    dataDesc_311[110].fieldName = "m_bDuckToggled";
    dataDesc_311[110].fieldOffset = 3852;
    dataDesc_311[110].fieldSize = 1;
    dataDesc_311[110].flags = 2;
    dataDesc_311[110].externalName = nullptr;
    dataDesc_311[110].pSaveRestoreOps = nullptr;
    dataDesc_311[110].inputFunc = nullptr;
    dataDesc_311[110].td = nullptr;
    dataDesc_311[110].fieldSizeInBytes = 1;
    dataDesc_311[110].override_field = nullptr;
    dataDesc_311[110].override_count = 0;
    dataDesc_311[110].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[110].flatGroup = 0;
    dataDesc_311[111].fieldType = FIELD_FLOAT;
    dataDesc_311[111].fieldName = "m_flForwardMove";
    dataDesc_311[111].fieldOffset = 3856;
    dataDesc_311[111].fieldSize = 1;
    dataDesc_311[111].flags = 2;
    dataDesc_311[111].externalName = nullptr;
    dataDesc_311[111].pSaveRestoreOps = nullptr;
    dataDesc_311[111].inputFunc = nullptr;
    dataDesc_311[111].td = nullptr;
    dataDesc_311[111].fieldSizeInBytes = 4;
    dataDesc_311[111].override_field = nullptr;
    dataDesc_311[111].override_count = 0;
    dataDesc_311[111].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[111].flatGroup = 0;
    dataDesc_311[112].fieldType = FIELD_FLOAT;
    dataDesc_311[112].fieldName = "m_flSideMove";
    dataDesc_311[112].fieldOffset = 3860;
    dataDesc_311[112].fieldSize = 1;
    dataDesc_311[112].flags = 2;
    dataDesc_311[112].externalName = nullptr;
    dataDesc_311[112].pSaveRestoreOps = nullptr;
    dataDesc_311[112].inputFunc = nullptr;
    dataDesc_311[112].td = nullptr;
    dataDesc_311[112].fieldSizeInBytes = 4;
    dataDesc_311[112].override_field = nullptr;
    dataDesc_311[112].override_count = 0;
    dataDesc_311[112].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[112].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[112].flatGroup = 0;
    dataDesc_311[113].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_311[113].flags = 2;
    dataDesc_311[114].flags = 2;
    dataDesc_311[113].fieldSize = 1;
    *(_QWORD *)dataDesc_311[113].flatOffset = 0;
    dataDesc_311[114].fieldSize = 1;
    *(_QWORD *)dataDesc_311[114].flatOffset = 0;
    dataDesc_311[115].fieldSize = 1;
    dataDesc_311[115].fieldType = FIELD_EHANDLE;
    dataDesc_311[116].fieldType = FIELD_EHANDLE;
    dataDesc_311[117].fieldSize = 1;
    *(_QWORD *)dataDesc_311[115].flatOffset = 0;
    dataDesc_311[113].fieldName = "m_vecPreviouslyPredictedOrigin";
    dataDesc_311[113].fieldOffset = 4064;
    dataDesc_311[113].externalName = nullptr;
    dataDesc_311[113].pSaveRestoreOps = nullptr;
    dataDesc_311[113].inputFunc = nullptr;
    dataDesc_311[113].td = nullptr;
    dataDesc_311[113].fieldSizeInBytes = 12;
    dataDesc_311[113].override_field = nullptr;
    dataDesc_311[113].override_count = 0;
    dataDesc_311[113].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[113].flatGroup = 0;
    dataDesc_311[114].fieldType = FIELD_INTEGER;
    dataDesc_311[114].fieldName = "m_nNumCrateHudHints";
    dataDesc_311[114].fieldOffset = 3864;
    dataDesc_311[114].externalName = nullptr;
    dataDesc_311[114].pSaveRestoreOps = nullptr;
    dataDesc_311[114].inputFunc = nullptr;
    dataDesc_311[114].td = nullptr;
    dataDesc_311[114].fieldSizeInBytes = 4;
    dataDesc_311[114].override_field = nullptr;
    dataDesc_311[114].override_count = 0;
    dataDesc_311[114].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[114].flatGroup = 0;
    dataDesc_311[115].fieldName = "m_hPostProcessCtrl";
    dataDesc_311[115].fieldOffset = 2872;
    dataDesc_311[115].flags = 2;
    dataDesc_311[115].externalName = nullptr;
    dataDesc_311[115].pSaveRestoreOps = nullptr;
    dataDesc_311[115].inputFunc = nullptr;
    dataDesc_311[115].td = nullptr;
    dataDesc_311[115].fieldSizeInBytes = 4;
    dataDesc_311[115].override_field = nullptr;
    dataDesc_311[115].override_count = 0;
    dataDesc_311[115].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_311[115].flatGroup = 0;
    dataDesc_311[116].fieldName = "m_hColorCorrectionCtrl";
    dataDesc_311[116].fieldOffset = 2876;
    *(_DWORD *)&dataDesc_311[116].fieldSize = 131073;
    dataDesc_311[116].externalName = nullptr;
    dataDesc_311[116].pSaveRestoreOps = nullptr;
    dataDesc_311[116].inputFunc = nullptr;
    dataDesc_311[116].td = nullptr;
    dataDesc_311[116].fieldSizeInBytes = 4;
    dataDesc_311[116].override_field = nullptr;
    dataDesc_311[116].override_count = 0;
    dataDesc_311[116].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[116].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[116].flatGroup = 0;
    dataDesc_311[117].fieldType = FIELD_EMBEDDED;
    dataDesc_311[117].fieldName = "m_PlayerFog";
    dataDesc_311[117].fieldOffset = 2792;
    dataDesc_311[117].flags = 2;
    dataDesc_311[117].externalName = nullptr;
    dataDesc_311[117].pSaveRestoreOps = nullptr;
    dataDesc_311[117].inputFunc = nullptr;
    dataDesc_311[117].td = &fogplayerparams_t::m_DataMap;
    dataDesc_311[117].fieldSizeInBytes = 60;
    dataDesc_311[117].override_field = nullptr;
    dataDesc_311[117].override_count = 0;
    dataDesc_311[117].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_311[117].flatOffset = 0;
    *(_DWORD *)&dataDesc_311[117].flatGroup = 0;
  }
  CBasePlayer::m_DataMap.dataNumFields = 117;
  CBasePlayer::m_DataMap.dataDesc = &dataDesc_311[1];
  return &CBasePlayer::m_DataMap;
}
