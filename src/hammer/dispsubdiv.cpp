// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/dispsubdiv.cpp
// Functions: 85
// ============================================================

#include "hammer\dispsubdiv.h"

//------------------------------------------------------------------------------
// Address: 0x1001D690
// Name: public: void CUtlLinkedList<class CMapDisp,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMapDisp,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CMapDisp,unsigned short> *m_pMemory; // ecx
  int v3; // esi
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<CMapDisp,unsigned short> *v5; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v7; // ax
  CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *v8; // [esp+0h] [ebp-4h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CMapDisp::~CMapDisp(this: &v5->m_Element);
        v5->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = v8->m_FirstFree;
        else
          m_FirstFree = m_Next;
        this = v8;
        v5->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v7 = this->m_Head;
    if ( v7 != 0xFFFF )
      this->m_FirstFree = v7;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D730
// Name: public: void CUtlLinkedList<class CMapDisp,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMapDisp,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CMapDisp,unsigned short> *v3; // eax
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
// Address: 0x1001D7F0
// Name: protected: unsigned short CUtlLinkedList<class CMapDisp,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMapDisp,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CMapDisp,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CMapDisp,unsigned short> *v11; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1001DAD0
// Name: public: CUtlLinkedList<class CMapDisp,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMapDisp,unsigned short>,unsigned short>>::~CUtlLinkedList<class CMapDisp,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMapDisp,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::~CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>(
        CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *this)
{
  CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DB40
// Name: public: void CUtlLinkedList<class CMapDisp,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMapDisp,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CMapDisp,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x100288F0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivQuad_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>::Grow(
        CUtlMemory<Shoreline_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Shoreline_t *m_pMemory; // ecx

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
      this->m_pMemory = (Shoreline_t *)_realloc_crt(ptr: m_pMemory, size: 96 * m_nAllocationCount);
    else
      this->m_pMemory = (Shoreline_t *)MemAlloc_Alloc(nSize: 96 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C090
// Name: void DestroyEditDispSubdivMesh(class IEditDispSubdivMesh __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyEditDispSubdivMesh(IEditDispSubdivMesh **pSubdivMesh)
{
  if ( *pSubdivMesh != nullptr )
  {
    operator delete(p: *pSubdivMesh);
    *pSubdivMesh = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C0B0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivPoint_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *m_pMemory; // ecx
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
    v7 = 124 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *)_realloc_crt(
                                                                                         ptr: m_pMemory,
                                                                                         size: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C140
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivEdge_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // ecx

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
      this->m_pMemory = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *)_realloc_crt(
                                                                                        ptr: m_pMemory,
                                                                                        size: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *)MemAlloc_Alloc(nSize: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C1F0
// Name: private: struct CEditDispSubdivMesh::SubdivPoint_t __near * CEditDispSubdivMesh::GetPoint(int)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *__thiscall CEditDispSubdivMesh::GetPoint(
        CEditDispSubdivMesh *this,
        int ptHandle)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *m_pMemory; // esi
  int v3; // edx

  if ( ptHandle >= 0
    && ptHandle < this->m_Points.m_Memory.m_nAllocationCount
    && ptHandle <= this->m_Points.m_LastAlloc.index
    && ((m_pMemory = this->m_Points.m_Memory.m_pMemory, v3 = ptHandle, m_pMemory[ptHandle].m_Previous != ptHandle)
     || m_pMemory[v3].m_Next == ptHandle) )
  {
    return &m_pMemory[v3];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C230
// Name: private: struct CEditDispSubdivMesh::SubdivEdge_t __near * CEditDispSubdivMesh::GetEdge(int)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *__thiscall CEditDispSubdivMesh::GetEdge(
        CEditDispSubdivMesh *this,
        int edgeHandle)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // esi
  int v3; // edx

  if ( edgeHandle >= 0
    && edgeHandle < this->m_Edges.m_Memory.m_nAllocationCount
    && edgeHandle <= this->m_Edges.m_LastAlloc.index
    && ((m_pMemory = this->m_Edges.m_Memory.m_pMemory, v3 = edgeHandle, m_pMemory[edgeHandle].m_Previous != edgeHandle)
     || m_pMemory[v3].m_Next == edgeHandle) )
  {
    return &m_pMemory[v3];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C280
// Name: private: struct CEditDispSubdivMesh::SubdivQuad_t __near * CEditDispSubdivMesh::GetQuad(int)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *__thiscall CEditDispSubdivMesh::GetQuad(
        CEditDispSubdivMesh *this,
        int quadHandle)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *m_pMemory; // esi
  int v3; // edx

  if ( quadHandle >= 0
    && quadHandle < this->m_Quads.m_Memory.m_nAllocationCount
    && quadHandle <= this->m_Quads.m_LastAlloc.index
    && ((m_pMemory = this->m_Quads.m_Memory.m_pMemory, v3 = quadHandle, m_pMemory[quadHandle].m_Previous != quadHandle)
     || m_pMemory[v3].m_Next == quadHandle) )
  {
    return &m_pMemory[v3];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C2C0
// Name: private: void CEditDispSubdivMesh::Point_PointCrease(struct CEditDispSubdivMesh::SubdivPoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::Point_PointCrease(
        CEditDispSubdivMesh *this,
        CEditDispSubdivMesh::SubdivPoint_t *pPoint)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  int *m_EdgeHandles; // ebx
  int v10; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // edi
  int v12; // edx
  float *p_x; // eax
  float v14; // xmm7_4
  CEditDispSubdivMesh::SubdivPoint_t *pPointa; // [esp+8h] [ebp+8h]

  v3 = 0.0;
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  v8 = 0.0;
  if ( pPoint->m_uValence != 0 )
  {
    m_EdgeHandles = pPoint->m_EdgeHandles;
    pPointa = (CEditDispSubdivMesh::SubdivPoint_t *)pPoint->m_uValence;
    do
    {
      v10 = *m_EdgeHandles;
      if ( *m_EdgeHandles >= 0
        && v10 < this->m_Edges.m_Memory.m_nAllocationCount
        && v10 <= this->m_Edges.m_LastAlloc.index )
      {
        m_pMemory = this->m_Edges.m_Memory.m_pMemory;
        v12 = v10;
        if ( m_pMemory[v10].m_Previous != v10 || m_pMemory[v12].m_Next == v10 )
        {
          p_x = &m_pMemory[v12].m_Element.m_vNewEdgePoint.x;
          if ( &m_pMemory[v12] != nullptr && p_x[10] > 0.0 )
          {
            v3 = v3 + *p_x;
            v4 = v4 + p_x[1];
            v5 = v5 + p_x[2];
            v6 = v6 + p_x[3];
            v7 = v7 + p_x[4];
            v8 = v8 + p_x[5];
          }
        }
      }
      ++m_EdgeHandles;
      pPointa = (CEditDispSubdivMesh::SubdivPoint_t *)((char *)pPointa - 1);
    }
    while ( pPointa != nullptr );
  }
  pPoint->m_vNewPoint.x = pPoint->m_vPoint.x * 6.0;
  pPoint->m_vNewPoint.y = pPoint->m_vPoint.y * 6.0;
  pPoint->m_vNewPoint.z = pPoint->m_vPoint.z * 6.0;
  v14 = pPoint->m_vNewPoint.x + v3;
  pPoint->m_vNewPoint.x = v14;
  pPoint->m_vNewPoint.y = pPoint->m_vNewPoint.y + v4;
  pPoint->m_vNewPoint.z = pPoint->m_vNewPoint.z + v5;
  pPoint->m_vNewPoint.x = v14 * 0.125;
  pPoint->m_vNewPoint.y = pPoint->m_vNewPoint.y * 0.125;
  pPoint->m_vNewPoint.z = pPoint->m_vNewPoint.z * 0.125;
  pPoint->m_vNewNormal.x = pPoint->m_vNormal.x * 6.0;
  pPoint->m_vNewNormal.y = pPoint->m_vNormal.y * 6.0;
  pPoint->m_vNewNormal.z = pPoint->m_vNormal.z * 6.0;
  pPoint->m_vNewNormal.x = v6 + pPoint->m_vNewNormal.x;
  pPoint->m_vNewNormal.y = pPoint->m_vNewNormal.y + v7;
  pPoint->m_vNewNormal.z = pPoint->m_vNewNormal.z + v8;
  pPoint->m_vNewNormal.x = pPoint->m_vNewNormal.x * 0.125;
  pPoint->m_vNewNormal.y = pPoint->m_vNewNormal.y * 0.125;
  pPoint->m_vNewNormal.z = pPoint->m_vNewNormal.z * 0.125;
}

//------------------------------------------------------------------------------
// Address: 0x1002C460
// Name: private: void CEditDispSubdivMesh::Quad_Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::Quad_Init(CEditDispSubdivMesh *this, int quadHandle)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *m_pMemory; // esi
  int v3; // edx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v4; // eax
  __int16 *m_QuadIndices; // ecx
  int *m_PointHandles; // eax
  int i; // edx

  if ( quadHandle >= 0
    && quadHandle < this->m_Quads.m_Memory.m_nAllocationCount
    && quadHandle <= this->m_Quads.m_LastAlloc.index )
  {
    m_pMemory = this->m_Quads.m_Memory.m_pMemory;
    v3 = quadHandle;
    if ( m_pMemory[quadHandle].m_Previous != quadHandle || m_pMemory[v3].m_Next == quadHandle )
    {
      v4 = &m_pMemory[v3];
      if ( &m_pMemory[v3] != nullptr )
      {
        *(_QWORD *)&v4->m_Element.m_vCentroid.y = 0;
        v4->m_Element.m_vCentroid.x = 0.0;
        *(_QWORD *)&v4->m_Element.m_vNormal.y = 0;
        v4->m_Element.m_vNormal.x = 0.0;
        v4->m_Element.m_EditDispHandle = -1;
        v4->m_Element.m_Level = -1;
        v4->m_Element.m_ndxParent = -1;
        m_QuadIndices = v4->m_Element.m_QuadIndices;
        m_PointHandles = v4->m_Element.m_PointHandles;
        for ( i = 4; i != 0; --i )
        {
          *(m_PointHandles - 4) = -1;
          *m_PointHandles = -1;
          m_PointHandles[4] = -1;
          *m_QuadIndices = -1;
          ++m_PointHandles;
          ++m_QuadIndices;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C4F0
// Name: private: void CEditDispSubdivMesh::Quad_CalcCentroid(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::Quad_CalcCentroid(CEditDispSubdivMesh *this, int quadHandle)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *m_pMemory; // edx
  int v3; // esi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v4; // edx
  float v5; // xmm0_4
  float v6; // xmm1_4
  int v7; // ebx
  int v8; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v9; // edi
  int v10; // esi
  float *p_x; // eax
  float v12; // xmm2_4

  if ( quadHandle >= 0
    && quadHandle < this->m_Quads.m_Memory.m_nAllocationCount
    && quadHandle <= this->m_Quads.m_LastAlloc.index )
  {
    m_pMemory = this->m_Quads.m_Memory.m_pMemory;
    v3 = quadHandle;
    if ( m_pMemory[quadHandle].m_Previous != quadHandle || m_pMemory[v3].m_Next == quadHandle )
    {
      v4 = &m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = 0.0;
        *(_QWORD *)&v4->m_Element.m_vCentroid.y = 0;
        v4->m_Element.m_vCentroid.x = 0.0;
        v6 = 0.0;
        v7 = 44;
        do
        {
          v8 = *(_DWORD *)((char *)&v4->m_Element.m_vCentroid.x + v7);
          if ( v8 >= 0
            && v8 < this->m_Points.m_Memory.m_nAllocationCount
            && v8 <= this->m_Points.m_LastAlloc.index
            && ((v9 = this->m_Points.m_Memory.m_pMemory, v10 = v8, v9[v8].m_Previous != v8) || v9[v10].m_Next == v8) )
          {
            p_x = &v9[v10].m_Element.m_vPoint.x;
          }
          else
          {
            p_x = nullptr;
          }
          v12 = *p_x + v4->m_Element.m_vCentroid.x;
          v4->m_Element.m_vCentroid.x = v12;
          v5 = v5 + p_x[1];
          v7 += 4;
          v4->m_Element.m_vCentroid.y = v5;
          v6 = v6 + p_x[2];
          v4->m_Element.m_vCentroid.z = v6;
        }
        while ( v7 < 60 );
        v4->m_Element.m_vCentroid.x = v12 * 0.25;
        v4->m_Element.m_vCentroid.y = v5 * 0.25;
        v4->m_Element.m_vCentroid.z = v6 * 0.25;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C5D0
// Name: private: void CEditDispSubdivMesh::Quad_CalcNormal(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::Quad_CalcNormal(CEditDispSubdivMesh *this, int quadHandle)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *m_pMemory; // esi
  int v3; // edx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v4; // edi
  int v5; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v6; // esi
  int v7; // edx
  float *p_x; // ebx
  int v9; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v10; // esi
  int v11; // edx
  float *v12; // esi
  int v13; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v14; // edi
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  CEditDispSubdivMesh::SubdivQuad_t *pQuad; // [esp+8h] [ebp+8h]

  if ( quadHandle >= 0
    && quadHandle < this->m_Quads.m_Memory.m_nAllocationCount
    && quadHandle <= this->m_Quads.m_LastAlloc.index )
  {
    m_pMemory = this->m_Quads.m_Memory.m_pMemory;
    v3 = quadHandle;
    if ( m_pMemory[quadHandle].m_Previous != quadHandle || m_pMemory[v3].m_Next == quadHandle )
    {
      v4 = &m_pMemory[v3];
      pQuad = &m_pMemory[v3].m_Element;
      if ( &m_pMemory[v3] != nullptr )
      {
        v5 = v4->m_Element.m_PointHandles[0];
        if ( v5 >= 0
          && v5 < this->m_Points.m_Memory.m_nAllocationCount
          && v5 <= this->m_Points.m_LastAlloc.index
          && ((v6 = this->m_Points.m_Memory.m_pMemory, v7 = v5, v6[v5].m_Previous != v5) || v6[v7].m_Next == v5) )
        {
          p_x = &v6[v7].m_Element.m_vPoint.x;
        }
        else
        {
          p_x = nullptr;
        }
        v9 = v4->m_Element.m_PointHandles[1];
        if ( v9 >= 0
          && v9 < this->m_Points.m_Memory.m_nAllocationCount
          && v9 <= this->m_Points.m_LastAlloc.index
          && ((v10 = this->m_Points.m_Memory.m_pMemory, v11 = v9, v10[v9].m_Previous != v9) || v10[v11].m_Next == v9) )
        {
          v12 = &v10[v11].m_Element.m_vPoint.x;
        }
        else
        {
          v12 = nullptr;
        }
        v13 = v4->m_Element.m_PointHandles[2];
        if ( v13 >= 0 && v13 < this->m_Points.m_Memory.m_nAllocationCount && v13 <= this->m_Points.m_LastAlloc.index )
        {
          v14 = this->m_Points.m_Memory.m_pMemory;
          v15 = v13;
          if ( v14[v13].m_Previous != v13 || v14[v15].m_Next == v13 )
          {
            v16 = &v14[v15].m_Element.m_vPoint.x;
            v4 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *)pQuad;
            goto LABEL_29;
          }
          v4 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *)pQuad;
        }
        v16 = nullptr;
LABEL_29:
        v17 = v16[1] - p_x[1];
        v18 = v16[2] - p_x[2];
        v19 = v12[1] - p_x[1];
        v20 = v12[2] - p_x[2];
        v21 = *v12 - *p_x;
        v22 = *v16 - *p_x;
        v4->m_Element.m_vNormal.x = (float)(v17 * v20) - (float)(v18 * v19);
        v4->m_Element.m_vNormal.y = (float)(v18 * v21) - (float)(v22 * v20);
        v4->m_Element.m_vNormal.z = (float)(v22 * v19) - (float)(v17 * v21);
        VectorNormalize(vec: &v4->m_Element.m_vNormal);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C730
// Name: public: void CUtlLinkedList<struct CEditDispSubdivMesh::SubdivEdge_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::EnsureCapacity(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int> > *this,
        int num)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v4; // edx

  if ( this->m_Memory.m_nAllocationCount >= num )
    goto LABEL_5;
  m_pMemory = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = m_pMemory;
  }
  else
  {
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *)_realloc_crt(
                                                                                                 ptr: m_pMemory,
                                                                                                 size: 56 * num);
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    v4 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *)MemAlloc_Alloc(nSize: 56 * num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C7A0
// Name: public: void CUtlLinkedList<struct CEditDispSubdivMesh::SubdivQuad_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::EnsureCapacity(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int> > *this,
        int num)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v4; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *)_realloc_crt(ptr: m_pMemory, size: 96 * num);
    else
      v4 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *)MemAlloc_Alloc(nSize: 96 * num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C810
// Name: public: void CUtlLinkedList<struct CEditDispSubdivMesh::SubdivPoint_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v2; // esi
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
// Address: 0x1002C870
// Name: public: void CUtlLinkedList<struct CEditDispSubdivMesh::SubdivEdge_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v2; // esi
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
// Address: 0x1002C8D0
// Name: public: void CUtlLinkedList<struct CEditDispSubdivMesh::SubdivQuad_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v2; // esi
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
// Address: 0x1002C930
// Name: protected: int CUtlLinkedList<struct CEditDispSubdivMesh::SubdivPoint_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *m_pMemory; // ecx
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
    CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1002CA60
// Name: protected: int CUtlLinkedList<struct CEditDispSubdivMesh::SubdivEdge_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1002CB90
// Name: protected: int CUtlLinkedList<struct CEditDispSubdivMesh::SubdivQuad_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *m_pMemory; // ecx
  int v9; // edx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    v9 = result;
    if ( multilist )
    {
      m_pMemory[v9].m_Next = -1;
      m_pMemory[v9].m_Previous = -1;
    }
    else
    {
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
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
    CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>::Grow(
      (CUtlMemory<Shoreline_t,int> *)this,
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
      if ( `CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x1002CCC0
// Name: private: void CEditDispSubdivMesh::Point_PointOrdinary(struct CEditDispSubdivMesh::SubdivPoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::Point_PointOrdinary(
        CEditDispSubdivMesh *this,
        CEditDispSubdivMesh::SubdivPoint_t *pPoint)
{
  CEditDispSubdivMesh::SubdivPoint_t *v2; // edx
  float v3; // xmm0_4
  int m_uValence; // ebx
  CEditDispSubdivMesh *v5; // esi
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  int *m_EdgeHandles; // edi
  int i; // ecx
  int v13; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // esi
  int v15; // edx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v16; // eax
  float v17; // xmm4_4
  int v18; // edi
  int *v19; // ecx
  int v20; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v21; // esi
  int v22; // edx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v23; // eax
  int *m_QuadHandles; // esi
  int j; // ebx
  int v26; // edx
  int k; // eax
  float v28; // xmm5_4
  int v29; // ebx
  float v30; // xmm6_4
  float v31; // xmm7_4
  int v32; // esi
  _DWORD *v33; // ecx
  int v34; // eax
  int v35; // edx
  float *v36; // eax
  float v37; // xmm0_4
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm7_4
  int quadList[32]; // [esp+0h] [ebp-A0h]
  Vector edgeAccumNormal; // [esp+80h] [ebp-20h]
  Vector edgeAccumPoint; // [esp+8Ch] [ebp-14h]
  int v44; // [esp+98h] [ebp-8h]
  CEditDispSubdivMesh *v45; // [esp+9Ch] [ebp-4h]

  v2 = pPoint;
  v3 = 0.0;
  m_uValence = pPoint->m_uValence;
  v5 = this;
  v45 = this;
  v6 = 0.0;
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  if ( m_uValence != 0 )
  {
    m_EdgeHandles = pPoint->m_EdgeHandles;
    for ( i = m_uValence; i != 0; --i )
    {
      v13 = *m_EdgeHandles;
      if ( *m_EdgeHandles >= 0 && v13 < v5->m_Edges.m_Memory.m_nAllocationCount && v13 <= v5->m_Edges.m_LastAlloc.index )
      {
        m_pMemory = v45->m_Edges.m_Memory.m_pMemory;
        v15 = v13;
        if ( m_pMemory[v13].m_Previous != v13 || m_pMemory[v15].m_Next == v13 )
        {
          v16 = &v45->m_Edges.m_Memory.m_pMemory[v15];
          if ( v16 != nullptr )
          {
            v3 = v3 + v16->m_Element.m_vNewEdgePoint.x;
            v6 = v6 + v16->m_Element.m_vNewEdgePoint.y;
            v7 = v7 + v16->m_Element.m_vNewEdgePoint.z;
            v8 = v8 + v16->m_Element.m_vNewEdgeNormal.x;
            v9 = v9 + v16->m_Element.m_vNewEdgeNormal.y;
            v10 = v16->m_Element.m_vNewEdgeNormal.z + v10;
          }
        }
        v2 = pPoint;
      }
      v5 = v45;
      ++m_EdgeHandles;
    }
  }
  v17 = 1.0 / (float)(v2->m_uValence * v2->m_uValence);
  v18 = 0;
  edgeAccumPoint.x = v3 * v17;
  edgeAccumPoint.y = v6 * v17;
  edgeAccumPoint.z = v7 * v17;
  edgeAccumNormal.x = v8 * v17;
  edgeAccumNormal.y = v9 * v17;
  edgeAccumNormal.z = v10 * v17;
  if ( m_uValence > 0 )
  {
    v19 = v2->m_EdgeHandles;
    v44 = m_uValence;
    while ( 1 )
    {
      v20 = *v19;
      if ( *v19 >= 0 && v20 < v5->m_Edges.m_Memory.m_nAllocationCount && v20 <= v5->m_Edges.m_LastAlloc.index )
      {
        v21 = v45->m_Edges.m_Memory.m_pMemory;
        v22 = v20;
        if ( v21[v20].m_Previous != v20 || v21[v22].m_Next == v20 )
        {
          v23 = &v45->m_Edges.m_Memory.m_pMemory[v22];
          if ( v23 != nullptr )
          {
            m_QuadHandles = v23->m_Element.m_QuadHandles;
            for ( j = 2; j != 0; --j )
            {
              v26 = *m_QuadHandles;
              if ( *m_QuadHandles != -1 )
              {
                for ( k = 0; k < v18; ++k )
                {
                  if ( v26 == quadList[k] )
                    break;
                }
                if ( k == v18 )
                  quadList[v18++] = v26;
              }
              ++m_QuadHandles;
            }
          }
        }
        v2 = pPoint;
      }
      ++v19;
      if ( --v44 == 0 )
        break;
      v5 = v45;
    }
  }
  v28 = 0.0;
  v29 = 0;
  v30 = 0.0;
  v31 = 0.0;
  if ( v18 > 0 )
  {
    do
    {
      v32 = quadList[v29];
      CEditDispSubdivMesh::Quad_CalcCentroid(this: v45, quadHandle: v32);
      if ( v32 >= 0
        && v32 < v33[22]
        && v32 <= v33[29]
        && ((v34 = v33[21], v35 = 96 * v32, *(_DWORD *)(v34 + 96 * v32 + 88) != v32)
         || *(_DWORD *)(v34 + v35 + 92) == v32) )
      {
        v36 = (float *)(v35 + v34);
      }
      else
      {
        v36 = nullptr;
      }
      v28 = v28 + *v36;
      v30 = v30 + v36[1];
      v31 = v31 + v36[2];
      ++v29;
    }
    while ( v29 < v18 );
    v2 = pPoint;
  }
  v37 = (float)((float)v2->m_uValence - 2.0) / (float)v2->m_uValence;
  v2->m_vNewPoint.x = v2->m_vPoint.x * v37;
  v2->m_vNewPoint.y = v2->m_vPoint.y * v37;
  v2->m_vNewPoint.z = v2->m_vPoint.z * v37;
  v2->m_vNewPoint.x = v2->m_vNewPoint.x + edgeAccumPoint.x;
  v2->m_vNewPoint.y = v2->m_vNewPoint.y + edgeAccumPoint.y;
  v2->m_vNewPoint.z = v2->m_vNewPoint.z + edgeAccumPoint.z;
  v38 = v28 * v17;
  v2->m_vNewPoint.x = v2->m_vNewPoint.x + v38;
  v39 = v30 * v17;
  v2->m_vNewPoint.y = v2->m_vNewPoint.y + v39;
  v40 = v31 * v17;
  v2->m_vNewPoint.z = v2->m_vNewPoint.z + v40;
  v2->m_vNewNormal.x = v37 * v2->m_vNormal.x;
  v2->m_vNewNormal.y = v2->m_vNormal.y * v37;
  v2->m_vNewNormal.z = v2->m_vNormal.z * v37;
  v2->m_vNewNormal.x = v2->m_vNewNormal.x + edgeAccumNormal.x;
  v2->m_vNewNormal.y = v2->m_vNewNormal.y + edgeAccumNormal.y;
  v2->m_vNewNormal.z = v2->m_vNewNormal.z + edgeAccumNormal.z;
  v2->m_vNewNormal.x = v2->m_vNewNormal.x + v38;
  v2->m_vNewNormal.y = v2->m_vNewNormal.y + v39;
  v2->m_vNewNormal.z = v2->m_vNewNormal.z + v40;
}

//------------------------------------------------------------------------------
// Address: 0x1002CFD0
// Name: private: void CEditDispSubdivMesh::Edge_CalcNewPoint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::Edge_CalcNewPoint(CEditDispSubdivMesh *this, int edgeHandle)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // edx
  int v4; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v5; // ebx
  int v6; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v7; // edx
  int v8; // ecx
  float *p_x; // edx
  int v10; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v11; // esi
  int v12; // ecx
  float *v13; // esi
  float v14; // xmm1_4
  float v15; // xmm2_4
  CEditDispSubdivMesh *v16; // ecx
  CEditDispSubdivMesh *v17; // ecx
  CEditDispSubdivMesh *v18; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *Quad; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  CEditDispSubdivMesh *v22; // ecx
  float m_flSharpness; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  int v26; // [esp-Ch] [ebp-44h]
  float vSharpPoint; // [esp+4h] [ebp-34h]
  float vSharpPoint_8; // [esp+Ch] [ebp-2Ch]
  float vSmoothPoint; // [esp+10h] [ebp-28h]
  float vSmoothPoint_4; // [esp+14h] [ebp-24h]
  float vSmoothPoint_8; // [esp+18h] [ebp-20h]
  Vector vSharpNormal; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector vSmoothNormal; // [esp+28h] [ebp-10h] BYREF
  CEditDispSubdivMesh::SubdivQuad_t *pQuad0; // [esp+34h] [ebp-4h]
  CEditDispSubdivMesh::SubdivPoint_t *pPoint0; // [esp+40h] [ebp+8h]

  if ( edgeHandle >= 0
    && edgeHandle < this->m_Edges.m_Memory.m_nAllocationCount
    && edgeHandle <= this->m_Edges.m_LastAlloc.index )
  {
    m_pMemory = this->m_Edges.m_Memory.m_pMemory;
    v4 = edgeHandle;
    if ( m_pMemory[edgeHandle].m_Previous != edgeHandle || m_pMemory[v4].m_Next == edgeHandle )
    {
      v5 = &m_pMemory[v4];
      if ( &m_pMemory[v4] != nullptr && v5->m_Element.m_bActive )
      {
        v6 = v5->m_Element.m_PointHandles[0];
        if ( v6 >= 0
          && v6 < this->m_Points.m_Memory.m_nAllocationCount
          && v6 <= this->m_Points.m_LastAlloc.index
          && ((v7 = this->m_Points.m_Memory.m_pMemory, v8 = v6, v7[v6].m_Previous != v6) || v7[v8].m_Next == v6) )
        {
          pPoint0 = &v7[v8].m_Element;
          p_x = &v7[v8].m_Element.m_vPoint.x;
        }
        else
        {
          p_x = nullptr;
          pPoint0 = nullptr;
        }
        v10 = v5->m_Element.m_PointHandles[1];
        if ( v10 >= 0
          && v10 < this->m_Points.m_Memory.m_nAllocationCount
          && v10 <= this->m_Points.m_LastAlloc.index
          && ((v11 = this->m_Points.m_Memory.m_pMemory, v12 = v10, v11[v10].m_Previous != v10) || v11[v12].m_Next == v10) )
        {
          v13 = &v11[v12].m_Element.m_vPoint.x;
        }
        else
        {
          v13 = nullptr;
        }
        if ( p_x != nullptr && v13 != nullptr )
        {
          v14 = p_x[1] + v13[1];
          v15 = v13[2] + p_x[2];
          vSharpPoint = (float)(*v13 + *p_x) * 0.5;
          memset(&vSharpNormal, 0, sizeof(vSharpNormal));
          vSharpNormal.x = p_x[3] + v13[3];
          vSharpNormal.y = p_x[4] + v13[4];
          vSharpPoint_8 = v15 * 0.5;
          vSharpNormal.z = v13[5] + p_x[5];
          VectorNormalize(vec: &vSharpNormal);
          memset(&vSmoothNormal, 0, sizeof(vSmoothNormal));
          vSmoothPoint = 0.0;
          vSmoothPoint_4 = 0.0;
          vSmoothPoint_8 = 0.0;
          if ( v5->m_Element.m_QuadHandles[1] == -1 || v5->m_Element.m_flSharpness == 1.0 )
          {
            v26 = v5->m_Element.m_QuadHandles[0];
            v5->m_Element.m_flSharpness = 1.0;
            CEditDispSubdivMesh::Quad_CalcCentroid(this, quadHandle: v26);
            CEditDispSubdivMesh::Quad_CalcNormal(this: v22, quadHandle: v5->m_Element.m_QuadHandles[0]);
          }
          else
          {
            CEditDispSubdivMesh::Quad_CalcCentroid(this, quadHandle: v5->m_Element.m_QuadHandles[0]);
            CEditDispSubdivMesh::Quad_CalcCentroid(this: v16, quadHandle: v5->m_Element.m_QuadHandles[1]);
            CEditDispSubdivMesh::Quad_CalcNormal(this: v17, quadHandle: v5->m_Element.m_QuadHandles[0]);
            CEditDispSubdivMesh::Quad_CalcNormal(this, quadHandle: v5->m_Element.m_QuadHandles[1]);
            pQuad0 = (CEditDispSubdivMesh::SubdivQuad_t *)CEditDispSubdivMesh::GetQuad(
                                                            this,
                                                            quadHandle: v5->m_Element.m_QuadHandles[0]);
            Quad = CEditDispSubdivMesh::GetQuad(this: v18, quadHandle: v5->m_Element.m_QuadHandles[1]);
            v20 = (float)(Quad->m_Element.m_vCentroid.z
                        + (float)(pQuad0->m_vCentroid.z + (float)(v13[2] + pPoint0->m_vPoint.z)))
                * 0.25;
            v21 = (float)(Quad->m_Element.m_vCentroid.x
                        + (float)(pQuad0->m_vCentroid.x + (float)(*v13 + pPoint0->m_vPoint.x)))
                * 0.25;
            vSmoothPoint_4 = (float)(Quad->m_Element.m_vCentroid.y
                                   + (float)(pQuad0->m_vCentroid.y + (float)(pPoint0->m_vPoint.y + v13[1])))
                           * 0.25;
            vSmoothNormal.x = pPoint0->m_vNormal.x + v13[3];
            vSmoothPoint_8 = v20;
            vSmoothNormal.y = pPoint0->m_vNormal.y + v13[4];
            vSmoothPoint = v21;
            vSmoothNormal.z = v13[5] + pPoint0->m_vNormal.z;
            vSmoothNormal.x = pQuad0->m_vNormal.x + vSmoothNormal.x;
            vSmoothNormal.y = pQuad0->m_vNormal.y + vSmoothNormal.y;
            vSmoothNormal.z = pQuad0->m_vNormal.z + vSmoothNormal.z;
            vSmoothNormal.x = vSmoothNormal.x + Quad->m_Element.m_vNormal.x;
            vSmoothNormal.y = Quad->m_Element.m_vNormal.y + vSmoothNormal.y;
            vSmoothNormal.z = Quad->m_Element.m_vNormal.z + vSmoothNormal.z;
            VectorNormalize(vec: &vSmoothNormal);
          }
          m_flSharpness = v5->m_Element.m_flSharpness;
          v5->m_Element.m_vNewEdgePoint.x = (float)((float)(1.0 - m_flSharpness) * vSmoothPoint)
                                          + (float)(m_flSharpness * vSharpPoint);
          v5->m_Element.m_vNewEdgePoint.y = (float)(vSmoothPoint_4 * (float)(1.0 - m_flSharpness))
                                          + (float)((float)(v14 * 0.5) * m_flSharpness);
          v5->m_Element.m_vNewEdgePoint.z = (float)(vSmoothPoint_8 * (float)(1.0 - m_flSharpness))
                                          + (float)(vSharpPoint_8 * m_flSharpness);
          vSmoothNormal.y = vSmoothNormal.y * (float)(1.0 - m_flSharpness);
          vSmoothNormal.z = vSmoothNormal.z * (float)(1.0 - m_flSharpness);
          vSmoothNormal.x = (float)(1.0 - m_flSharpness) * vSmoothNormal.x;
          v24 = v5->m_Element.m_flSharpness;
          vSharpNormal.y = vSharpNormal.y * v24;
          v25 = vSmoothNormal.x + (float)(v24 * vSharpNormal.x);
          vSharpNormal.x = v24 * vSharpNormal.x;
          vSharpNormal.z = vSharpNormal.z * v24;
          v5->m_Element.m_vNewEdgeNormal.x = v25;
          v5->m_Element.m_vNewEdgeNormal.y = vSmoothNormal.y + vSharpNormal.y;
          v5->m_Element.m_vNewEdgeNormal.z = vSmoothNormal.z + vSharpNormal.z;
          VectorNormalize(vec: &v5->m_Element.m_vNewEdgeNormal);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D3C0
// Name: public: virtual void CEditDispSubdivMesh::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::Init(CEditDispSubdivMesh *this)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int v3; // ebx
  int v4; // edi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *m_pMemory; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v6; // eax

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
  {
    v3 = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
    v4 = v3 << 9;
    if ( this->m_Points.m_Memory.m_nAllocationCount < v3 << 9 && this->m_Points.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = this->m_Points.m_Memory.m_pMemory;
      this->m_Points.m_Memory.m_nAllocationCount = v4;
      if ( m_pMemory != nullptr )
        v6 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *)_realloc_crt(
                                                                              ptr: m_pMemory,
                                                                              size: 63488 * v3);
      else
        v6 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *)MemAlloc_Alloc(nSize: 63488 * v3);
      this->m_Points.m_Memory.m_pMemory = v6;
    }
    this->m_Points.m_pElements = this->m_Points.m_Memory.m_pMemory;
    CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::EnsureCapacity(
      this: &this->m_Edges,
      num: v3 << 10);
    CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::EnsureCapacity(
      this: &this->m_Quads,
      num: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D440
// Name: public: virtual void CEditDispSubdivMesh::GetDispFrom(class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::GetDispFrom(CEditDispSubdivMesh *this, CMapDisp *pDisp)
{
  int m_Head; // edx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v4; // eax
  __int16 *m_QuadIndices; // edi
  int *m_PointHandles; // eax
  int v7; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v8; // esi
  int v9; // ecx
  CoreDispVert_t *m_pVerts; // edx
  float z; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  CoreDispVert_t *v14; // edx
  int v15; // ecx
  bool v16; // zf
  Vector vSubVert; // [esp+4h] [ebp-18h] BYREF
  CEditDispSubdivMesh *v18; // [esp+10h] [ebp-Ch]
  int v19; // [esp+14h] [ebp-8h]
  int quadHandle; // [esp+18h] [ebp-4h]
  CMapDisp *pDispa; // [esp+24h] [ebp+8h]

  m_Head = this->m_Quads.m_Head;
  v18 = this;
  quadHandle = m_Head;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      if ( m_Head >= 0
        && m_Head < this->m_Quads.m_Memory.m_nAllocationCount
        && m_Head <= this->m_Quads.m_LastAlloc.index )
      {
        v4 = &this->m_Quads.m_Memory.m_pMemory[m_Head];
        if ( (v4->m_Previous != m_Head || v4->m_Next == m_Head)
          && v4 != nullptr
          && v4->m_Element.m_EditDispHandle == pDisp->m_EditHandle
          && v4->m_Element.m_Level == pDisp->m_CoreDispInfo.m_Power )
        {
          m_QuadIndices = v4->m_Element.m_QuadIndices;
          m_PointHandles = v4->m_Element.m_PointHandles;
          pDispa = (CMapDisp *)m_PointHandles;
          v19 = 4;
          do
          {
            v7 = *m_PointHandles;
            if ( v7 >= 0 && v7 < this->m_Points.m_Memory.m_nAllocationCount && v7 <= this->m_Points.m_LastAlloc.index )
            {
              v8 = &this->m_Points.m_Memory.m_pMemory[v7];
              if ( (v8->m_Previous != v7 || v8->m_Next == v7) && v8 != nullptr )
              {
                v9 = *m_QuadIndices;
                m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
                z = m_pVerts[v9].m_FlatVert.z;
                v12 = v8->m_Element.m_vPoint.x - m_pVerts[v9].m_FlatVert.x;
                vSubVert.y = v8->m_Element.m_vPoint.y - m_pVerts[v9].m_FlatVert.y;
                v13 = v8->m_Element.m_vPoint.z - z;
                vSubVert.x = v12;
                vSubVert.z = v13;
                CMapDisp::UpdateVertPositionForSubdiv(this: pDisp, iVert: v9, vecNewSubdivPos: &vSubVert);
                v14 = pDisp->m_CoreDispInfo.m_pVerts;
                v15 = *m_QuadIndices;
                v14[v15].m_SubdivNormal.x = v8->m_Element.m_vNormal.x;
                v14[v15].m_SubdivNormal.y = v8->m_Element.m_vNormal.y;
                v14[v15].m_SubdivNormal.z = v8->m_Element.m_vNormal.z;
                this = v18;
              }
              m_Head = quadHandle;
            }
            m_PointHandles = &pDispa->m_nObjectID;
            ++m_QuadIndices;
            v16 = v19-- == 1;
            pDispa = (CMapDisp *)((char *)pDispa + 4);
          }
          while ( !v16 );
        }
      }
      quadHandle = this->m_Quads.m_Memory.m_pMemory[m_Head].m_Next;
      if ( quadHandle == -1 )
        break;
      m_Head = quadHandle;
    }
  }
  CMapDisp::UpdateData(this: pDisp);
  *(_WORD *)&pDisp->m_bSubdiv = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002D5E0
// Name: public: CUtlLinkedList<struct CEditDispSubdivMesh::SubdivPoint_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::~CUtlLinkedList<struct CEditDispSubdivMesh::SubdivPoint_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivPoint_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::~CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int> > *this)
{
  CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D650
// Name: public: CUtlLinkedList<struct CEditDispSubdivMesh::SubdivEdge_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::~CUtlLinkedList<struct CEditDispSubdivMesh::SubdivEdge_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivEdge_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::~CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int> > *this)
{
  CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D6C0
// Name: public: CUtlLinkedList<struct CEditDispSubdivMesh::SubdivQuad_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::~CUtlLinkedList<struct CEditDispSubdivMesh::SubdivQuad_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivQuad_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::~CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int> > *this)
{
  CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D730
// Name: public: void CUtlLinkedList<struct CEditDispSubdivMesh::SubdivPoint_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::Unlink(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v2; // eax
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
// Address: 0x1002D7B0
// Name: public: void CUtlLinkedList<struct CEditDispSubdivMesh::SubdivEdge_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::Unlink(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v2; // eax
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
// Address: 0x1002D840
// Name: public: void CUtlLinkedList<struct CEditDispSubdivMesh::SubdivQuad_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::Unlink(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v2; // eax
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
// Address: 0x1002D8C0
// Name: public: CEditDispSubdivMesh::CEditDispSubdivMesh(void)
// Source: json
//------------------------------------------------------------------------------
CEditDispSubdivMesh *__thiscall CEditDispSubdivMesh::CEditDispSubdivMesh(CEditDispSubdivMesh *this)
{
  CEditDispSubdivMesh *result; // eax
  CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int> > *p_m_Points; // edx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v4; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v5; // ecx

  result = this;
  p_m_Points = &this->m_Points;
  this->__vftable = (CEditDispSubdivMesh_vtbl *)&CEditDispSubdivMesh::`vftable';
  this->m_Points.m_Memory.m_pMemory = nullptr;
  this->m_Points.m_Memory.m_nAllocationCount = 0;
  this->m_Points.m_Memory.m_nGrowSize = 0;
  this->m_Points.m_LastAlloc.index = -1;
  m_pMemory = this->m_Points.m_Memory.m_pMemory;
  p_m_Points->m_Head = -1;
  p_m_Points->m_Tail = -1;
  p_m_Points->m_FirstFree = -1;
  p_m_Points->m_ElementCount = 0;
  p_m_Points->m_NumAlloced = 0;
  p_m_Points->m_pElements = m_pMemory;
  result->m_Edges.m_Memory.m_pMemory = nullptr;
  result->m_Edges.m_Memory.m_nAllocationCount = 0;
  result->m_Edges.m_Memory.m_nGrowSize = 0;
  result->m_Edges.m_LastAlloc.index = -1;
  v4 = result->m_Edges.m_Memory.m_pMemory;
  result->m_Edges.m_Head = -1;
  result->m_Edges.m_Tail = -1;
  result->m_Edges.m_FirstFree = -1;
  result->m_Edges.m_ElementCount = 0;
  result->m_Edges.m_NumAlloced = 0;
  result->m_Edges.m_pElements = v4;
  result->m_Quads.m_Memory.m_pMemory = nullptr;
  result->m_Quads.m_Memory.m_nAllocationCount = 0;
  result->m_Quads.m_Memory.m_nGrowSize = 0;
  result->m_Quads.m_LastAlloc.index = -1;
  v5 = result->m_Quads.m_Memory.m_pMemory;
  result->m_Quads.m_Head = -1;
  result->m_Quads.m_Tail = -1;
  result->m_Quads.m_FirstFree = -1;
  result->m_Quads.m_ElementCount = 0;
  result->m_Quads.m_NumAlloced = 0;
  result->m_Quads.m_pElements = v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D990
// Name: public: virtual void CEditDispSubdivMesh::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::Shutdown(CEditDispSubdivMesh *this)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *m_pMemory; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v3; // edx

  CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::RemoveAll(this: &this->m_Points);
  if ( this->m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Points.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Points.m_Memory.m_pMemory);
      this->m_Points.m_Memory.m_pMemory = nullptr;
    }
    this->m_Points.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Points.m_FirstFree = -1;
  this->m_Points.m_LastAlloc.index = -1;
  m_pMemory = this->m_Points.m_Memory.m_pMemory;
  this->m_Points.m_NumAlloced = 0;
  this->m_Points.m_pElements = m_pMemory;
  CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::RemoveAll(this: &this->m_Edges);
  if ( this->m_Edges.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Edges.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Edges.m_Memory.m_pMemory);
      this->m_Edges.m_Memory.m_pMemory = nullptr;
    }
    this->m_Edges.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Edges.m_pElements = this->m_Edges.m_Memory.m_pMemory;
  this->m_Edges.m_FirstFree = -1;
  this->m_Edges.m_NumAlloced = 0;
  this->m_Edges.m_LastAlloc.index = -1;
  CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::RemoveAll(this: &this->m_Quads);
  if ( this->m_Quads.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Quads.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Quads.m_Memory.m_pMemory);
      this->m_Quads.m_Memory.m_pMemory = nullptr;
    }
    this->m_Quads.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_Quads.m_Memory.m_pMemory;
  this->m_Quads.m_NumAlloced = 0;
  this->m_Quads.m_FirstFree = -1;
  this->m_Quads.m_LastAlloc.index = -1;
  this->m_Quads.m_pElements = v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA40
// Name: private: void CEditDispSubdivMesh::CatmullClarkSubdivision(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::CatmullClarkSubdivision(CEditDispSubdivMesh *this)
{
  int i; // esi
  int j; // ebx
  int k; // esi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // eax
  bool v6; // zf
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v7; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *Point; // eax
  unsigned int m_uValence; // ecx
  int m_Head; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v11; // edx
  int v12; // eax
  int *m_EdgeHandles; // esi
  int v14; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v15; // ecx
  __int16 v16; // ax
  int m; // esi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v18; // eax
  int m_Next; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v20; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v21; // eax
  int sharpThreshold; // [esp+8h] [ebp-14h]
  int v23; // [esp+Ch] [ebp-10h]
  int sharpCount; // [esp+10h] [ebp-Ch]
  int ptHandle; // [esp+14h] [ebp-8h]
  bool bHasNeighbors; // [esp+1Bh] [ebp-1h]

  for ( i = this->m_Edges.m_Head; i != -1; i = this->m_Edges.m_Memory.m_pMemory[i].m_Next )
    CEditDispSubdivMesh::Edge_CalcNewPoint(this, edgeHandle: i);
  for ( j = this->m_Points.m_Head; j != -1; j = this->m_Points.m_Memory.m_pMemory[j].m_Next )
  {
    for ( k = this->m_Edges.m_Head; k != -1; k = this->m_Edges.m_Memory.m_pMemory[k].m_Next )
    {
      if ( k < 0
        || k >= this->m_Edges.m_Memory.m_nAllocationCount
        || k > this->m_Edges.m_LastAlloc.index
        || (m_pMemory = this->m_Edges.m_Memory.m_pMemory, v6 = m_pMemory[k].m_Previous == k, v7 = &m_pMemory[k], v6)
        && v7->m_Next != k )
      {
        v7 = nullptr;
      }
      if ( v7->m_Element.m_bActive && (j == v7->m_Element.m_PointHandles[0] || j == v7->m_Element.m_PointHandles[1]) )
      {
        Point = CEditDispSubdivMesh::GetPoint(this, ptHandle: j);
        m_uValence = Point->m_Element.m_uValence;
        if ( m_uValence < 0x10 )
        {
          Point->m_Element.m_EdgeHandles[m_uValence] = k;
          ++Point->m_Element.m_uValence;
        }
      }
    }
  }
  m_Head = this->m_Points.m_Head;
  ptHandle = m_Head;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      if ( m_Head < 0 )
        goto LABEL_45;
      if ( m_Head >= this->m_Points.m_Memory.m_nAllocationCount )
        goto LABEL_45;
      if ( m_Head > this->m_Points.m_LastAlloc.index )
        goto LABEL_45;
      v11 = &this->m_Points.m_Memory.m_pMemory[m_Head];
      if ( v11->m_Previous == m_Head && v11->m_Next != m_Head )
        goto LABEL_45;
      if ( v11 == nullptr )
        goto LABEL_45;
      v12 = v11->m_Element.m_uValence;
      sharpThreshold = v12 - 1;
      sharpCount = 0;
      bHasNeighbors = false;
      v11->m_Element.m_uType = 0;
      if ( v12 == 0 )
        break;
      m_EdgeHandles = v11->m_Element.m_EdgeHandles;
      v23 = v11->m_Element.m_uValence;
      do
      {
        v14 = *m_EdgeHandles;
        if ( *m_EdgeHandles >= 0
          && v14 < this->m_Edges.m_Memory.m_nAllocationCount
          && v14 <= this->m_Edges.m_LastAlloc.index )
        {
          v15 = &this->m_Edges.m_Memory.m_pMemory[v14];
          if ( (v15->m_Previous != v14 || v15->m_Next == v14) && v15 != nullptr )
          {
            if ( v15->m_Element.m_flSharpness > 0.0 )
              ++sharpCount;
            v6 = v15->m_Element.m_QuadHandles[1] == -1;
            m_Head = ptHandle;
            if ( !v6 )
              bHasNeighbors = true;
          }
          else
          {
            m_Head = ptHandle;
          }
        }
        ++m_EdgeHandles;
        --v23;
      }
      while ( v23 != 0 );
      if ( !bHasNeighbors || sharpCount >= sharpThreshold )
        break;
      if ( sharpCount > 1 )
      {
        v16 = 2;
LABEL_44:
        v11->m_Element.m_uType = v16;
      }
LABEL_45:
      m_Head = this->m_Points.m_Memory.m_pMemory[m_Head].m_Next;
      ptHandle = m_Head;
      if ( m_Head == -1 )
        goto LABEL_46;
    }
    v16 = 1;
    goto LABEL_44;
  }
LABEL_46:
  for ( m = this->m_Points.m_Head; m != -1; m = this->m_Points.m_Memory.m_pMemory[m].m_Next )
  {
    if ( m >= 0 && m < this->m_Points.m_Memory.m_nAllocationCount && m <= this->m_Points.m_LastAlloc.index )
    {
      v18 = &this->m_Points.m_Memory.m_pMemory[m];
      if ( (v18->m_Previous != m || v18->m_Next == m) && v18 != nullptr )
      {
        if ( v18->m_Element.m_uType != 0 )
        {
          if ( v18->m_Element.m_uType == 1 )
          {
            v18->m_Element.m_vNewPoint.x = v18->m_Element.m_vPoint.x;
            v18->m_Element.m_vNewPoint.y = v18->m_Element.m_vPoint.y;
            v18->m_Element.m_vNewPoint.z = v18->m_Element.m_vPoint.z;
            v18->m_Element.m_vNewNormal.x = v18->m_Element.m_vNormal.x;
            v18->m_Element.m_vNewNormal.y = v18->m_Element.m_vNormal.y;
            v18->m_Element.m_vNewNormal.z = v18->m_Element.m_vNormal.z;
          }
          else if ( v18->m_Element.m_uType == 2 )
          {
            CEditDispSubdivMesh::Point_PointCrease(this, pPoint: &this->m_Points.m_Memory.m_pMemory[m].m_Element);
          }
        }
        else
        {
          CEditDispSubdivMesh::Point_PointOrdinary(this, pPoint: &this->m_Points.m_Memory.m_pMemory[m].m_Element);
        }
      }
    }
  }
  m_Next = this->m_Points.m_Head;
  if ( m_Next != -1 )
  {
    v20 = this->m_Points.m_Memory.m_pMemory;
    do
    {
      if ( m_Next < 0
        || m_Next >= this->m_Points.m_Memory.m_nAllocationCount
        || m_Next > this->m_Points.m_LastAlloc.index
        || (v21 = &v20[m_Next])->m_Previous == m_Next && v21->m_Next != m_Next )
      {
        v21 = nullptr;
      }
      v21->m_Element.m_vPoint.x = v21->m_Element.m_vNewPoint.x;
      v21->m_Element.m_vPoint.y = v21->m_Element.m_vNewPoint.y;
      v21->m_Element.m_vPoint.z = v21->m_Element.m_vNewPoint.z;
      v21->m_Element.m_vNewNormal.x = v21->m_Element.m_vNewNormal.x;
      v21->m_Element.m_vNewNormal.y = v21->m_Element.m_vNewNormal.y;
      v21->m_Element.m_vNewNormal.z = v21->m_Element.m_vNewNormal.z;
      v21->m_Element.m_vNewPoint.z = 0.0;
      v21->m_Element.m_vNewPoint.y = 0.0;
      v21->m_Element.m_vNewPoint.x = 0.0;
      v21->m_Element.m_vNewNormal.z = 0.0;
      v21->m_Element.m_vNewNormal.y = 0.0;
      v21->m_Element.m_vNewNormal.x = 0.0;
      v21->m_Element.m_uValence = 0;
      v20 = this->m_Points.m_Memory.m_pMemory;
      m_Next = v20[m_Next].m_Next;
    }
    while ( m_Next != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DD10
// Name: class IEditDispSubdivMesh __near * CreateEditDispSubdivMesh(void)
// Source: json
//------------------------------------------------------------------------------
CEditDispSubdivMesh *__cdecl CreateEditDispSubdivMesh()
{
  CEditDispSubdivMesh *v0; // eax

  v0 = (CEditDispSubdivMesh *)operator new(nSize: 0x7Cu);
  if ( v0 != nullptr )
    return CEditDispSubdivMesh::CEditDispSubdivMesh(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DD70
// Name: public: int CUtlLinkedList<struct CEditDispSubdivMesh::SubdivEdge_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::AddToTail(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // ecx
  int v5; // eax
  int m_Tail; // edx

  result = CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::Unlink(
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
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002DE20
// Name: public: int CUtlLinkedList<struct CEditDispSubdivMesh::SubdivQuad_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AddToTail(
        CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *m_pMemory; // eax
  int v5; // ecx
  int m_Tail; // edx

  result = CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::Unlink(
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
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002DEC0
// Name: private: int CEditDispSubdivMesh::BuildSubdivPoint(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditDispSubdivMesh::BuildSubdivPoint(
        CEditDispSubdivMesh *this,
        const Vector *vPoint,
        const Vector *vPointNormal)
{
  int result; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *v4; // esi
  int v5; // edx
  char *v6; // edi
  CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int> > *p_m_Points; // esi
  int v8; // eax
  int v9; // edi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *m_pMemory; // eax
  int v11; // ecx
  int m_Tail; // edx
  int v13; // ecx
  int v14; // ecx

  for ( result = this->m_Points.m_Head; result != -1; result = this->m_Points.m_Memory.m_pMemory[result].m_Next )
  {
    if ( result >= 0
      && result < this->m_Points.m_Memory.m_nAllocationCount
      && result <= this->m_Points.m_LastAlloc.index )
    {
      v4 = &this->m_Points.m_Memory.m_pMemory[result];
      if ( (v4->m_Previous != result || v4->m_Next == result) && v4 != nullptr )
      {
        v5 = 0;
        v6 = (char *)((char *)vPoint - (char *)v4);
        while ( fabs(*(float *)&v6[(_DWORD)v4] - v4->m_Element.m_vPoint.x) <= 0.1 )
        {
          ++v5;
          v4 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int> *)((char *)v4 + 4);
          if ( v5 >= 3 )
            return result;
        }
      }
    }
  }
  p_m_Points = &this->m_Points;
  v8 = CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::AllocInternal(
         this: &this->m_Points,
         multilist: false);
  v9 = v8;
  if ( v8 == -1 )
  {
    result = -1;
  }
  else
  {
    CUtlLinkedList<CEditDispSubdivMesh::SubdivPoint_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivPoint_t,int>,int>>::Unlink(
      this: p_m_Points,
      elem: v8);
    m_pMemory = p_m_Points->m_Memory.m_pMemory;
    v11 = v9;
    m_pMemory[v11].m_Next = -1;
    m_Tail = p_m_Points->m_Tail;
    m_pMemory[v11].m_Previous = m_Tail;
    p_m_Points->m_Tail = v9;
    if ( m_Tail == -1 )
      p_m_Points->m_Head = v9;
    else
      p_m_Points->m_Memory.m_pMemory[m_Tail].m_Next = v9;
    ++p_m_Points->m_ElementCount;
    result = v9;
  }
  if ( result < 0 )
    goto LABEL_30;
  if ( result < p_m_Points->m_Memory.m_nAllocationCount && result <= p_m_Points->m_LastAlloc.index )
  {
    v13 = (int)&p_m_Points->m_Memory.m_pMemory[result];
    if ( (*(_DWORD *)(v13 + 116) != result || *(_DWORD *)(v13 + 120) == result) && v13 != 0 )
    {
      *(_QWORD *)(v13 + 4) = 0;
      *(_DWORD *)v13 = 0;
      *(_QWORD *)(v13 + 16) = 0;
      *(_DWORD *)(v13 + 12) = 0;
      *(_QWORD *)(v13 + 28) = 0;
      *(_DWORD *)(v13 + 24) = 0;
      *(_QWORD *)(v13 + 40) = 0;
      *(_DWORD *)(v13 + 36) = 0;
      *(_WORD *)(v13 + 48) = -1;
      *(_WORD *)(v13 + 50) = 0;
      *(_DWORD *)(v13 + 52) = -1;
      *(_DWORD *)(v13 + 56) = -1;
      *(_DWORD *)(v13 + 60) = -1;
      *(_DWORD *)(v13 + 64) = -1;
      *(_DWORD *)(v13 + 68) = -1;
      *(_DWORD *)(v13 + 72) = -1;
      *(_DWORD *)(v13 + 76) = -1;
      *(_DWORD *)(v13 + 80) = -1;
    }
  }
  if ( result >= p_m_Points->m_Memory.m_nAllocationCount
    || result > p_m_Points->m_LastAlloc.index
    || *(_DWORD *)((v14 = (int)&p_m_Points->m_Memory.m_pMemory[result]) + 116) == result
    && *(_DWORD *)(v14 + 120) != result )
  {
LABEL_30:
    v14 = 0;
  }
  *(Vector *)v14 = *vPoint;
  *(Vector *)(v14 + 12) = *vPointNormal;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E0B0
// Name: private: int CEditDispSubdivMesh::BuildSubdivEdge(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditDispSubdivMesh::BuildSubdivEdge(
        CEditDispSubdivMesh *this,
        int ndxEdge,
        int quadHandle,
        int parentHandle,
        int ndxChild)
{
  CEditDispSubdivMesh *v5; // esi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v6; // ebx
  int result; // eax
  _DWORD *p_x; // ecx
  int v9; // edi
  int v10; // esi
  int v11; // edx
  CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int> > *p_m_Edges; // edi
  int v13; // ecx
  bool v14; // zf
  int v15; // edi
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v20; // [esp+Ch] [ebp-4h]

  v5 = this;
  if ( quadHandle < 0 )
    return -1;
  if ( quadHandle >= this->m_Quads.m_Memory.m_nAllocationCount )
    return -1;
  if ( quadHandle > this->m_Quads.m_LastAlloc.index )
    return -1;
  v6 = &this->m_Quads.m_Memory.m_pMemory[quadHandle];
  if ( v6->m_Previous == quadHandle && v6->m_Next != quadHandle )
    return -1;
  if ( v6 == nullptr )
    return -1;
  result = this->m_Edges.m_Head;
  if ( result == -1 )
  {
LABEL_21:
    p_m_Edges = &v5->m_Edges;
    result = CUtlLinkedList<CEditDispSubdivMesh::SubdivEdge_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int>,int>>::AddToTail(this: &v5->m_Edges);
    if ( result < 0 )
      goto LABEL_32;
    if ( result < v5->m_Edges.m_Memory.m_nAllocationCount && result <= v5->m_Edges.m_LastAlloc.index )
    {
      v13 = (int)&p_m_Edges->m_Memory.m_pMemory[result];
      if ( (*(_DWORD *)(v13 + 48) != result || *(_DWORD *)(v13 + 52) == result) && v13 != 0 )
      {
        *(_DWORD *)(v13 + 8) = 0;
        *(_DWORD *)(v13 + 4) = 0;
        *(_DWORD *)v13 = 0;
        *(_DWORD *)(v13 + 20) = 0;
        *(_DWORD *)(v13 + 16) = 0;
        *(_DWORD *)(v13 + 12) = 0;
        *(_DWORD *)(v13 + 40) = 1065353216;
        *(_BYTE *)(v13 + 44) = 0;
        *(_DWORD *)(v13 + 24) = -1;
        *(_DWORD *)(v13 + 32) = -1;
        *(_DWORD *)(v13 + 28) = -1;
        *(_DWORD *)(v13 + 36) = -1;
      }
    }
    if ( result >= v5->m_Edges.m_Memory.m_nAllocationCount
      || result > v5->m_Edges.m_LastAlloc.index
      || (v14 = p_m_Edges->m_Memory.m_pMemory[result].m_Previous == result,
          v15 = (int)&p_m_Edges->m_Memory.m_pMemory[result],
          v14)
      && *(_DWORD *)(v15 + 52) != result )
    {
LABEL_32:
      v15 = 0;
    }
    *(_DWORD *)(v15 + 24) = v6->m_Element.m_PointHandles[ndxEdge];
    *(_DWORD *)(v15 + 28) = v6->m_Element.m_PointHandles[(ndxEdge + 1) % 4];
    *(_DWORD *)(v15 + 32) = quadHandle;
    *(_BYTE *)(v15 + 44) = 1;
    if ( ndxChild != -1 )
    {
      if ( ndxEdge == ndxChild || ndxEdge == (ndxChild + 3) % 4 )
      {
        if ( parentHandle >= 0
          && parentHandle < v5->m_Quads.m_Memory.m_nAllocationCount
          && parentHandle <= v5->m_Quads.m_LastAlloc.index )
        {
          v16 = (int)&v5->m_Quads.m_Memory.m_pMemory[parentHandle];
          if ( (*(_DWORD *)(v16 + 88) != parentHandle || *(_DWORD *)(v16 + 92) == parentHandle) && v16 != 0 )
          {
            v17 = *(_DWORD *)(v16 + 4 * ndxEdge + 60);
            if ( v17 < 0
              || v17 >= v5->m_Edges.m_Memory.m_nAllocationCount
              || v17 > v5->m_Edges.m_LastAlloc.index
              || *(_DWORD *)((v18 = (int)&v5->m_Edges.m_Memory.m_pMemory[v17]) + 48) == v17
              && *(_DWORD *)(v18 + 52) != v17 )
            {
              v18 = 0;
            }
            *(float *)(v15 + 40) = *(float *)(v18 + 40);
          }
        }
      }
      else
      {
        *(_DWORD *)(v15 + 40) = 0;
      }
    }
    return result;
  }
  while ( 1 )
  {
    if ( result < 0 )
      goto LABEL_20;
    if ( result >= v5->m_Edges.m_Memory.m_nAllocationCount )
      goto LABEL_20;
    if ( result > v5->m_Edges.m_LastAlloc.index )
      goto LABEL_20;
    p_x = (_DWORD *)&v5->m_Edges.m_Memory.m_pMemory[result].m_Element.m_vNewEdgePoint.x;
    if ( p_x[12] == result && p_x[13] != result )
      goto LABEL_20;
    if ( p_x == nullptr )
      goto LABEL_20;
    v9 = p_x[7];
    v10 = p_x[6];
    v20 = v6->m_Element.m_PointHandles[(ndxEdge + 1) % 4];
    v11 = v6->m_Element.m_PointHandles[ndxEdge];
    if ( v11 == v10 && v20 == v9 )
      break;
    if ( v11 == v9 && v20 == v10 )
      break;
    v5 = this;
LABEL_20:
    result = v5->m_Edges.m_Memory.m_pMemory[result].m_Next;
    if ( result == -1 )
      goto LABEL_21;
  }
  if ( p_x[8] != quadHandle && p_x[9] == -1 )
  {
    p_x[9] = quadHandle;
    p_x[10] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E320
// Name: private: int CEditDispSubdivMesh::BuildSubdivQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditDispSubdivMesh::BuildSubdivQuad(CEditDispSubdivMesh *this, int ndxChild, int parentHandle)
{
  CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int> > *p_m_Quads; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *m_pMemory; // esi
  int v6; // edx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v7; // esi
  int v9; // edi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v10; // ecx
  int v11; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v12; // edi
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *Edge; // eax
  CEditDispSubdivMesh *v14; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v15; // eax
  CEditDispSubdivMesh *v16; // ecx
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v17; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v18; // eax
  CEditDispSubdivMesh *v19; // ecx
  int v20; // esi
  int *m_EdgeHandles; // edi
  CEditDispSubdivMesh::SubdivEdge_t *pEdge2; // [esp+8h] [ebp-Ch]
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *pEdge2a; // [esp+8h] [ebp-Ch]
  CEditDispSubdivMesh::SubdivEdge_t *pEdge2b; // [esp+8h] [ebp-Ch]
  int quadHandle; // [esp+Ch] [ebp-8h]
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *pEdge1; // [esp+10h] [ebp-4h]
  CEditDispSubdivMesh::SubdivEdge_t *pEdge1a; // [esp+10h] [ebp-4h]
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *pEdge1b; // [esp+10h] [ebp-4h]
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *pEdge1c; // [esp+10h] [ebp-4h]

  p_m_Quads = &this->m_Quads;
  if ( parentHandle < 0 )
    return -1;
  if ( parentHandle >= p_m_Quads->m_Memory.m_nAllocationCount )
    return -1;
  if ( parentHandle > p_m_Quads->m_LastAlloc.index )
    return -1;
  m_pMemory = p_m_Quads->m_Memory.m_pMemory;
  v6 = parentHandle;
  if ( p_m_Quads->m_Memory.m_pMemory[parentHandle].m_Previous == parentHandle && m_pMemory[v6].m_Next != parentHandle )
    return -1;
  v7 = &m_pMemory[v6];
  if ( v7 == nullptr )
    return -1;
  v9 = CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AddToTail(this: p_m_Quads);
  quadHandle = v9;
  CEditDispSubdivMesh::Quad_Init(this, quadHandle: v9);
  if ( v9 >= 0
    && v9 < this->m_Quads.m_Memory.m_nAllocationCount
    && v9 <= this->m_Quads.m_LastAlloc.index
    && ((v10 = this->m_Quads.m_Memory.m_pMemory, v11 = v9, v10[v9].m_Previous != v9) || v10[v11].m_Next == v9) )
  {
    v12 = &v10[v11];
  }
  else
  {
    v12 = nullptr;
  }
  v12->m_Element.m_ndxParent = parentHandle;
  v12->m_Element.m_EditDispHandle = v7->m_Element.m_EditDispHandle;
  v12->m_Element.m_Level = v7->m_Element.m_Level + 1;
  switch ( ndxChild )
  {
    case 0:
      v12->m_Element.m_QuadIndices[0] = v7->m_Element.m_QuadIndices[0];
      v12->m_Element.m_QuadIndices[1] = (int)(float)((float)(v7->m_Element.m_QuadIndices[0]
                                                           + v7->m_Element.m_QuadIndices[1])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[2] = (int)(float)((float)(v7->m_Element.m_QuadIndices[0]
                                                           + v7->m_Element.m_QuadIndices[2])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[3] = (int)(float)((float)(v7->m_Element.m_QuadIndices[0]
                                                           + v7->m_Element.m_QuadIndices[3])
                                                   * 0.5);
      pEdge1 = CEditDispSubdivMesh::GetEdge(this, edgeHandle: v7->m_Element.m_EdgeHandles[0]);
      Edge = CEditDispSubdivMesh::GetEdge(this, edgeHandle: v7->m_Element.m_EdgeHandles[3]);
      pEdge2 = &Edge->m_Element;
      if ( pEdge1 != nullptr && Edge != nullptr )
      {
        v12->m_Element.m_PointHandles[0] = v7->m_Element.m_PointHandles[0];
        v12->m_Element.m_PointHandles[1] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &pEdge1->m_Element.m_vNewEdgePoint,
                                             vPointNormal: &pEdge1->m_Element.m_vNewEdgeNormal);
        v12->m_Element.m_PointHandles[2] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &v7->m_Element.m_vCentroid,
                                             vPointNormal: &v7->m_Element.m_vNormal);
        v12->m_Element.m_PointHandles[3] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &pEdge2->m_vNewEdgePoint,
                                             vPointNormal: &pEdge2->m_vNewEdgeNormal);
      }
      break;
    case 1:
      v12->m_Element.m_QuadIndices[0] = (int)(float)((float)(v7->m_Element.m_QuadIndices[0]
                                                           + v7->m_Element.m_QuadIndices[1])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[1] = v7->m_Element.m_QuadIndices[1];
      v12->m_Element.m_QuadIndices[2] = (int)(float)((float)(v7->m_Element.m_QuadIndices[2]
                                                           + v7->m_Element.m_QuadIndices[1])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[3] = (int)(float)((float)(v7->m_Element.m_QuadIndices[0]
                                                           + v7->m_Element.m_QuadIndices[2])
                                                   * 0.5);
      pEdge2a = CEditDispSubdivMesh::GetEdge(this, edgeHandle: v7->m_Element.m_EdgeHandles[0]);
      v15 = CEditDispSubdivMesh::GetEdge(this: v14, edgeHandle: v7->m_Element.m_EdgeHandles[1]);
      pEdge1a = &v15->m_Element;
      if ( pEdge2a != nullptr && v15 != nullptr )
      {
        v12->m_Element.m_PointHandles[0] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &pEdge2a->m_Element.m_vNewEdgePoint,
                                             vPointNormal: &pEdge2a->m_Element.m_vNewEdgeNormal);
        v12->m_Element.m_PointHandles[1] = v7->m_Element.m_PointHandles[1];
        v12->m_Element.m_PointHandles[2] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &pEdge1a->m_vNewEdgePoint,
                                             vPointNormal: &pEdge1a->m_vNewEdgeNormal);
        v12->m_Element.m_PointHandles[3] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &v7->m_Element.m_vCentroid,
                                             vPointNormal: &v7->m_Element.m_vNormal);
      }
      break;
    case 2:
      v12->m_Element.m_QuadIndices[0] = (int)(float)((float)(v7->m_Element.m_QuadIndices[2]
                                                           + v7->m_Element.m_QuadIndices[0])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[1] = (int)(float)((float)(v7->m_Element.m_QuadIndices[2]
                                                           + v7->m_Element.m_QuadIndices[1])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[2] = v7->m_Element.m_QuadIndices[2];
      v12->m_Element.m_QuadIndices[3] = (int)(float)((float)(v7->m_Element.m_QuadIndices[2]
                                                           + v7->m_Element.m_QuadIndices[3])
                                                   * 0.5);
      pEdge1b = CEditDispSubdivMesh::GetEdge(this, edgeHandle: v7->m_Element.m_EdgeHandles[1]);
      v17 = CEditDispSubdivMesh::GetEdge(this: v16, edgeHandle: v7->m_Element.m_EdgeHandles[2]);
      pEdge2b = &v17->m_Element;
      if ( pEdge1b != nullptr && v17 != nullptr )
      {
        v12->m_Element.m_PointHandles[0] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &v7->m_Element.m_vCentroid,
                                             vPointNormal: &v7->m_Element.m_vNormal);
        v12->m_Element.m_PointHandles[1] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &pEdge1b->m_Element.m_vNewEdgePoint,
                                             vPointNormal: &pEdge1b->m_Element.m_vNewEdgeNormal);
        v12->m_Element.m_PointHandles[2] = v7->m_Element.m_PointHandles[2];
        v12->m_Element.m_PointHandles[3] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &pEdge2b->m_vNewEdgePoint,
                                             vPointNormal: &pEdge2b->m_vNewEdgeNormal);
      }
      break;
    case 3:
      v12->m_Element.m_QuadIndices[0] = (int)(float)((float)(v7->m_Element.m_QuadIndices[3]
                                                           + v7->m_Element.m_QuadIndices[0])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[1] = (int)(float)((float)(v7->m_Element.m_QuadIndices[0]
                                                           + v7->m_Element.m_QuadIndices[2])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[2] = (int)(float)((float)(v7->m_Element.m_QuadIndices[3]
                                                           + v7->m_Element.m_QuadIndices[2])
                                                   * 0.5);
      v12->m_Element.m_QuadIndices[3] = v7->m_Element.m_QuadIndices[3];
      pEdge1c = CEditDispSubdivMesh::GetEdge(this, edgeHandle: v7->m_Element.m_EdgeHandles[2]);
      v18 = CEditDispSubdivMesh::GetEdge(this, edgeHandle: v7->m_Element.m_EdgeHandles[3]);
      if ( pEdge1c != nullptr && v18 != nullptr )
      {
        v12->m_Element.m_PointHandles[0] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this: v19,
                                             vPoint: &v18->m_Element.m_vNewEdgePoint,
                                             vPointNormal: &v18->m_Element.m_vNewEdgeNormal);
        v12->m_Element.m_PointHandles[1] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &v7->m_Element.m_vCentroid,
                                             vPointNormal: &v7->m_Element.m_vNormal);
        v12->m_Element.m_PointHandles[2] = CEditDispSubdivMesh::BuildSubdivPoint(
                                             this,
                                             vPoint: &pEdge1c->m_Element.m_vNewEdgePoint,
                                             vPointNormal: &pEdge1c->m_Element.m_vNewEdgeNormal);
        v12->m_Element.m_PointHandles[3] = v7->m_Element.m_PointHandles[3];
      }
      break;
    default:
      break;
  }
  v20 = 0;
  m_EdgeHandles = v12->m_Element.m_EdgeHandles;
  do
    *m_EdgeHandles++ = CEditDispSubdivMesh::BuildSubdivEdge(this, ndxEdge: v20++, quadHandle, parentHandle, ndxChild);
  while ( v20 < 4 );
  return quadHandle;
}

//------------------------------------------------------------------------------
// Address: 0x1002E740
// Name: public: virtual void CEditDispSubdivMesh::AddDispTo(class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::AddDispTo(CEditDispSubdivMesh *this, CMapDisp *pDisp)
{
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v3; // esi
  int v5; // eax
  int v6; // edi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  IWorldEditDispMgr_vtbl *v13; // edx
  int (*SelectCount)(void); // eax
  CMapDisp *v15; // eax
  float *v16; // esi
  float *p_z; // edi
  int v18; // eax
  float *v19; // ecx
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float *v26; // eax
  int *m_PointHandles; // ebx
  int j; // edi
  int v29; // edi
  int *m_EdgeHandles; // esi
  Vector vPoints[4]; // [esp+Ch] [ebp-A0h] BYREF
  Vector vPointNormals[4]; // [esp+3Ch] [ebp-70h] BYREF
  Vector vPoint; // [esp+6Ch] [ebp-40h]
  CEditDispSubdivMesh::SubdivQuad_t *pQuad; // [esp+78h] [ebp-34h]
  int quadHandle; // [esp+7Ch] [ebp-30h]
  int count; // [esp+80h] [ebp-2Ch]
  int v37; // [esp+84h] [ebp-28h]
  char *v38; // [esp+88h] [ebp-24h]
  Vector vNormal; // [esp+8Ch] [ebp-20h] BYREF
  int i; // [esp+98h] [ebp-14h]
  CEditDispSubdivMesh *v41; // [esp+9Ch] [ebp-10h]
  IWorldEditDispMgr *pDispMgr; // [esp+A0h] [ebp-Ch]
  int v43; // [esp+A4h] [ebp-8h]
  int ndxSelect; // [esp+A8h] [ebp-4h]
  float *pDispa; // [esp+B4h] [ebp+8h]

  v41 = this;
  quadHandle = CUtlLinkedList<CEditDispSubdivMesh::SubdivQuad_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>>::AddToTail(this: &this->m_Quads);
  CEditDispSubdivMesh::Quad_Init(this, quadHandle);
  v3 = &this->m_Quads.m_Memory.m_pMemory[quadHandle];
  v3->m_Element.m_ndxParent = -1;
  v3->m_Element.m_EditDispHandle = pDisp->m_EditHandle;
  v3->m_Element.m_Level = 0;
  v5 = 1 << pDisp->m_CoreDispInfo.m_Power;
  v3->m_Element.m_QuadIndices[0] = 0;
  pQuad = &v3->m_Element;
  LOWORD(v5) = v5 + 1;
  v3->m_Element.m_QuadIndices[1] = v5 * (v5 - 1);
  v3->m_Element.m_QuadIndices[2] = v5 * v5 - 1;
  v3->m_Element.m_QuadIndices[3] = v5 - 1;
  pDispMgr = GetActiveWorldEditDispManager();
  if ( pDispMgr != nullptr )
  {
    pDispa = &pDisp->m_CoreDispInfo.m_Surf.m_Points[0].z;
    v6 = 0;
    v37 = -56 - (_DWORD)pDisp;
    v43 = 0;
    do
    {
      v7 = pDisp->m_CoreDispInfo.m_Surf.m_Points[3].y - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].y;
      v8 = pDisp->m_CoreDispInfo.m_Surf.m_Points[3].z - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].z;
      v9 = pDisp->m_CoreDispInfo.m_Surf.m_Points[1].y - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].y;
      v10 = pDisp->m_CoreDispInfo.m_Surf.m_Points[1].z - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].z;
      v11 = pDisp->m_CoreDispInfo.m_Surf.m_Points[3].x - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].x;
      v12 = pDisp->m_CoreDispInfo.m_Surf.m_Points[1].x - pDisp->m_CoreDispInfo.m_Surf.m_Points[0].x;
      *(float *)((char *)&vPointNormals[0].x + v6) = (float)(v7 * v10) - (float)(v8 * v9);
      *(float *)((char *)&vPointNormals[0].y + v6) = (float)(v8 * v12) - (float)(v11 * v10);
      *(float *)((char *)&vPointNormals[0].z + v6) = (float)(v11 * v9) - (float)(v7 * v12);
      VectorNormalize(vec: (Vector *)((char *)vPointNormals + v6));
      v13 = pDispMgr->__vftable;
      *(float *)((char *)&vPoints[0].x + v6) = *(pDispa - 2);
      *(float *)((char *)&vPoints[0].y + v6) = *(pDispa - 1);
      SelectCount = (int (*)(void))v13->SelectCount;
      *(float *)((char *)&vPoints[0].z + v6) = *pDispa;
      count = SelectCount();
      ndxSelect = 0;
      if ( count > 0 )
      {
        v38 = (char *)pDispa + v37;
        do
        {
          v15 = pDispMgr->GetFromSelect(this: pDispMgr, a2: ndxSelect);
          v16 = (float *)v15;
          if ( v15 != nullptr && v15 != pDisp )
          {
            p_z = &v15->m_CoreDispInfo.m_Surf.m_Points[0].z;
            for ( i = 4; i != 0; --i )
            {
              vPoint = *(Vector *)(p_z - 2);
              v18 = 0;
              v19 = (float *)((char *)&vPoints[0].x + v43);
              while ( fabs(*v19 - *(&vPoint.x + v18)) <= 0.0099999998 )
              {
                ++v18;
                ++v19;
                if ( v18 >= 3 )
                {
                  v20 = v16[22] - v16[13];
                  v21 = v16[23] - v16[14];
                  v22 = v16[16] - v16[13];
                  v23 = v16[17] - v16[14];
                  v24 = v16[21] - v16[12];
                  v25 = v16[15] - v16[12];
                  vNormal.x = (float)(v20 * v23) - (float)(v21 * v22);
                  vNormal.y = (float)(v21 * v25) - (float)(v24 * v23);
                  vNormal.z = (float)(v24 * v22) - (float)(v20 * v25);
                  VectorNormalize(vec: &vNormal);
                  v26 = (float *)((int)&vPointNormals[0].x + (_DWORD)v38);
                  *v26 = *(float *)((char *)&vPointNormals[0].x + (_DWORD)v38) + vNormal.x;
                  v26[1] = v26[1] + vNormal.y;
                  v26[2] = v26[2] + vNormal.z;
                  break;
                }
              }
              p_z += 3;
            }
            v6 = v43;
          }
          ++ndxSelect;
        }
        while ( ndxSelect < count );
        v3 = (UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *)pQuad;
      }
      VectorNormalize(vec: (Vector *)((char *)vPointNormals + v6));
      pDispa += 3;
      v6 += 12;
      v43 = v6;
    }
    while ( v6 < 48 );
    m_PointHandles = v3->m_Element.m_PointHandles;
    for ( j = 0; j < 4; ++j )
      *m_PointHandles++ = CEditDispSubdivMesh::BuildSubdivPoint(
                            this: v41,
                            vPoint: &vPoints[j],
                            vPointNormal: &vPointNormals[j]);
    v29 = 0;
    m_EdgeHandles = v3->m_Element.m_EdgeHandles;
    do
      *m_EdgeHandles++ = CEditDispSubdivMesh::BuildSubdivEdge(
                           this: v41,
                           ndxEdge: v29++,
                           quadHandle,
                           parentHandle: -1,
                           ndxChild: -1);
    while ( v29 < 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EAB0
// Name: private: void CEditDispSubdivMesh::UpdateSubdivisionHierarchy(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::UpdateSubdivisionHierarchy(CEditDispSubdivMesh *this, int ndxLevel)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int> *v4; // ecx
  int *m_ndxChild; // ebx
  int v6; // esi
  int v7; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v8; // ecx
  int v9; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v10; // ecx
  int v11; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v12; // ecx
  int v13; // eax
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *m_pMemory; // ecx
  bool v15; // zf
  UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivEdge_t,int> *v16; // ecx
  _DWORD *p_x; // [esp+4h] [ebp-10h]
  int quadCount; // [esp+8h] [ebp-Ch]
  int ndxQuad; // [esp+Ch] [ebp-8h]
  int quadHandle; // [esp+10h] [ebp-4h]

  quadCount = this->m_Quads.m_ElementCount;
  m_Head = this->m_Quads.m_Head;
  quadHandle = m_Head;
  ndxQuad = 0;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      if ( ndxQuad >= quadCount )
        return;
      if ( m_Head >= 0
        && m_Head < this->m_Quads.m_Memory.m_nAllocationCount
        && m_Head <= this->m_Quads.m_LastAlloc.index )
      {
        v4 = &this->m_Quads.m_Memory.m_pMemory[m_Head];
        p_x = (_DWORD *)&v4->m_Element.m_vCentroid.x;
        if ( (v4->m_Previous != m_Head || v4->m_Next == m_Head) && v4 != nullptr )
        {
          m_ndxChild = v4->m_Element.m_ndxChild;
          if ( v4->m_Element.m_ndxChild[0] != -1 )
          {
            ++ndxQuad;
            quadHandle = v4->m_Next;
            goto LABEL_46;
          }
          v6 = 0;
          while ( 1 )
          {
            *m_ndxChild++ = CEditDispSubdivMesh::BuildSubdivQuad(this, ndxChild: v6++, parentHandle: m_Head);
            if ( v6 >= 4 )
              break;
            m_Head = quadHandle;
          }
          v7 = p_x[15];
          if ( v7 >= 0 && v7 < this->m_Edges.m_Memory.m_nAllocationCount && v7 <= this->m_Edges.m_LastAlloc.index )
          {
            v8 = &this->m_Edges.m_Memory.m_pMemory[v7];
            if ( (v8->m_Previous != v7 || v8->m_Next == v7) && v8 != nullptr )
              v8->m_Element.m_bActive = false;
          }
          v9 = p_x[16];
          if ( v9 >= 0 && v9 < this->m_Edges.m_Memory.m_nAllocationCount && v9 <= this->m_Edges.m_LastAlloc.index )
          {
            v10 = &this->m_Edges.m_Memory.m_pMemory[v9];
            if ( (v10->m_Previous != v9 || v10->m_Next == v9) && v10 != nullptr )
              v10->m_Element.m_bActive = false;
          }
          v11 = p_x[17];
          if ( v11 >= 0 && v11 < this->m_Edges.m_Memory.m_nAllocationCount && v11 <= this->m_Edges.m_LastAlloc.index )
          {
            v12 = &this->m_Edges.m_Memory.m_pMemory[v11];
            if ( (v12->m_Previous != v11 || v12->m_Next == v11) && v12 != nullptr )
              v12->m_Element.m_bActive = false;
          }
          v13 = p_x[18];
          if ( v13 >= 0 && v13 < this->m_Edges.m_Memory.m_nAllocationCount && v13 <= this->m_Edges.m_LastAlloc.index )
          {
            m_pMemory = this->m_Edges.m_Memory.m_pMemory;
            v15 = m_pMemory[v13].m_Previous == v13;
            v16 = &m_pMemory[v13];
            if ( (!v15 || v16->m_Next == v13) && v16 != nullptr )
              v16->m_Element.m_bActive = false;
          }
          m_Head = quadHandle;
        }
      }
      ++ndxQuad;
      quadHandle = this->m_Quads.m_Memory.m_pMemory[m_Head].m_Next;
LABEL_46:
      if ( quadHandle == -1 )
        return;
      m_Head = quadHandle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EC60
// Name: public: virtual void CEditDispSubdivMesh::DoCatmullClarkSubdivision(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispSubdivMesh::DoCatmullClarkSubdivision(CEditDispSubdivMesh *this)
{
  int i; // esi

  for ( i = 0; i < 4; ++i )
  {
    CEditDispSubdivMesh::CatmullClarkSubdivision(this);
    CEditDispSubdivMesh::UpdateSubdivisionHierarchy(this, ndxLevel: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5820
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_FirstFree;
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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
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
    CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
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
      if ( `CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8 )
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
  if ( `CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101B63B0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

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
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
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
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *)v5;
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
// Address: 0x101B6BB0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(this);
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
// Address: 0x101B6C00
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::LinkBefore(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
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
// Address: 0x101B80A0
// Name: protected: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // ecx

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
      if ( `CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x101B8210
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
// Address: 0x101B8AD0
// Name: public: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AddToTail(class IUndoElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        IUndoElement **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // esi

  result = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
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
// Address: 0x10207810
// Name: protected: unsigned short CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>::Grow(
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
      if ( `CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10208AD0
// Name: public: void CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v3; // eax
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
// Address: 0x102091C0
// Name: public: void CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x10209A90
// Name: public: unsigned short CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v4; // ecx

  v2 = (unsigned __int16)CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
      CUtlString::CUtlString(this: &v4->m_Element.m_DirName);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10209AD0
// Name: public: void CUtlLinkedList<struct CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  bool v2; // sf
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short> *v4; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v6; // ax
  CUtlLinkedList<CAssetCache::DirToCheck_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAssetCache::DirToCheck_t,unsigned short>,unsigned short> > *v7; // [esp+0h] [ebp-4h]

  v7 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = this->m_Memory.m_pMemory[m_Head].m_Element.m_DirName.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
        v4 = &this->m_Memory.m_pMemory[m_Head];
        v4->m_Element.m_DirName.m_Storage.m_nActualLength = 0;
        if ( !v2 )
        {
          if ( v4->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory);
            this = v7;
            v4->m_Element.m_DirName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Element.m_DirName.m_Storage.m_Memory.m_nAllocationCount = 0;
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
// Address: 0x102B4010
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
// Address: 0x102B4080
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
// Address: 0x102B4200
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
// Address: 0x102B4410
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
// Address: 0x102F0F50
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
// Address: 0x102F10B0
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
// Address: 0x102F33D0
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
// Address: 0x102F39A0
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
// Address: 0x102F47B0
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
// Address: 0x102F4820
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
// Address: 0x102F4CC0
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
// Address: 0x102F60E0
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
// Address: 0x102F6860
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
// Address: 0x102F7910
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
// Address: 0x102F8E70
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
// Address: 0x102F9580
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
// Address: 0x102FBC80
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
// Address: 0x10308C20
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
// Address: 0x103327D0
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
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(this: &this->m_Memory, num: 1);
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
// Address: 0x10332970
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
// Address: 0x103329D0
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
// Address: 0x10487B70
// Name: protected: unsigned short CUtlLinkedList<struct SelectionInfo_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SelectionInfo_t __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>::Grow(
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
      if ( `CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x104882D0
// Name: public: void CUtlLinkedList<struct SelectionInfo_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SelectionInfo_t __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *v2; // esi
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
// Address: 0x10488700
// Name: public: void CUtlLinkedList<struct SelectionInfo_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SelectionInfo_t __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // eax
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
// Address: 0x104893D0
// Name: public: void CUtlLinkedList<struct SelectionInfo_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SelectionInfo_t __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *v7; // ebx

  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x1048AE80
// Name: public: unsigned short CUtlLinkedList<struct SelectionInfo_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SelectionInfo_t __near *,unsigned short>,unsigned short>>::AddToTail(struct SelectionInfo_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *this,
        SelectionInfo_t **src)
{
  int v3; // esi
  int result; // eax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *v5; // eax

  v3 = (unsigned __int16)CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::LinkBefore(
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
// Address: 0x1048AEC0
// Name: public: bool CUtlLinkedList<struct SelectionInfo_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SelectionInfo_t __near *,unsigned short>,unsigned short>>::FindAndRemove(struct SelectionInfo_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::FindAndRemove(
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *this,
        SelectionInfo_t **src)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // edx

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
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem: m_Head);
  this->m_Memory.m_pMemory[m_Head].m_Next = this->m_FirstFree;
  this->m_FirstFree = m_Head;
  return 1;
}
