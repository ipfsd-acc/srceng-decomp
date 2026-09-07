// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/studiorendercontext.cpp
// Functions: 144
// ============================================================

#include "studiorender\studiorendercontext.h"

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: void CUtlMemory<class CUtlVector<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,class CUtlMemory<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>,int>::Grow(
        CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *m_pMemory; // edx
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
      this->m_pMemory = (CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001400
// Name: public: int CUtlVector<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,class CUtlMemory<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100014B0
// Name: public: int CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>::InsertMultipleBefore(
        CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CCachedRenderData::CacheDict_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CCachedRenderData::CacheDict_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CCachedRenderData::CacheDict_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Tag = 0;
          v11->m_FlexTag = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001540
// Name: public: void CUtlVector<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,class CUtlMemory<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001770
// Name: public: void CUtlVector<class CUtlVector<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,class CUtlMemory<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,int>>,class CUtlMemory<class CUtlVector<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,class CUtlMemory<class CUtlVector<struct CCachedRenderData::CacheDict_t,class CUtlMemory<struct CCachedRenderData::CacheDict_t,int>>,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> >,int> > *this)
{
  int v1; // edi
  int v2; // eax
  CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *v3; // esi
  CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *m_pMemory; // eax
  CUtlVector<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> >,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    for ( i = 20 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *)((char *)this->m_Memory.m_pMemory + v2);
      CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      i -= 20;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100034E0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct DecalVertex_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<DecalVertex_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<DecalVertex_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100141B0
// Name: public: void CUtlMemory<struct GetTriangles_MaterialBatch_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<GetTriangles_MaterialBatch_t,int>::Grow(
        CUtlMemory<GetTriangles_MaterialBatch_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  GetTriangles_MaterialBatch_t *m_pMemory; // edx
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
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (GetTriangles_MaterialBatch_t *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v7);
    else
      this->m_pMemory = (GetTriangles_MaterialBatch_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014240
// Name: public: void CUtlMemory<struct GetTriangles_Vertex_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<GetTriangles_Vertex_t,int>::Grow(CUtlMemory<GetTriangles_Vertex_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  GetTriangles_Vertex_t *m_pMemory; // edx
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
      this->m_pMemory = (GetTriangles_Vertex_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (GetTriangles_Vertex_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100142D0
// Name: public: int CUtlVector<struct GetTriangles_Vertex_t,class CUtlMemory<struct GetTriangles_Vertex_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<GetTriangles_Vertex_t,CUtlMemory<GetTriangles_Vertex_t,int>>::InsertMultipleBefore(
        CUtlVector<GetTriangles_Vertex_t,CUtlMemory<GetTriangles_Vertex_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  GetTriangles_Vertex_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<GetTriangles_Vertex_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 84 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10014340
// Name: public: int CUtlVector<struct GetTriangles_MaterialBatch_t,class CUtlMemory<struct GetTriangles_MaterialBatch_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::InsertBefore(
        CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  GetTriangles_MaterialBatch_t *m_pMemory; // ecx
  int v6; // eax
  GetTriangles_MaterialBatch_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<GetTriangles_MaterialBatch_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Verts.m_Memory.m_pMemory = nullptr;
    v7->m_Verts.m_Memory.m_nAllocationCount = 0;
    v7->m_Verts.m_Memory.m_nGrowSize = 0;
    v7->m_Verts.m_Size = 0;
    v7->m_Verts.m_pElements = nullptr;
    v7->m_TriListIndices.m_Memory.m_pMemory = nullptr;
    v7->m_TriListIndices.m_Memory.m_nAllocationCount = 0;
    v7->m_TriListIndices.m_Memory.m_nGrowSize = 0;
    v7->m_TriListIndices.m_Size = 0;
    v7->m_TriListIndices.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100143C0
// Name: public: void CUtlVector<struct GetTriangles_MaterialBatch_t,class CUtlMemory<struct GetTriangles_MaterialBatch_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::RemoveAll(
        CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    v7 = 44 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 9) = 0;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( *((_DWORD *)v3 + 6) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 6));
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      v4 = *((void **)v3 + 6);
      *((_DWORD *)v3 + 10) = v4;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v5 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v5;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 44;
      v7 -= 44;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045EE0
// Name: public: int CUtlVector<union __m128,class CUtlMemoryAligned<union __m128,16>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<__m128,CUtlMemoryAligned<__m128,16>>::InsertMultipleBefore(
        CUtlVector<__m128,CUtlMemoryAligned<__m128,16> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  __m128 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemoryAligned<__m128,16>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1004E120
// Name: public: CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>>::~CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>::~CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>(
        CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *this)
{
  bool v2; // sf
  IStudioRender::FacesRenderedInfo_t *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
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
      free(pMem: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E320
// Name: public: int CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>>::InsertBefore(int,struct IStudioRender::FacesRenderedInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>::InsertBefore(
        CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *this,
        int elem,
        const IStudioRender::FacesRenderedInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  IStudioRender::FacesRenderedInfo_t *m_pMemory; // ecx
  int v7; // eax
  IStudioRender::FacesRenderedInfo_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1004E3A0
// Name: public: CUtlVector<union __m128,class CUtlMemoryAligned<union __m128,16>>::~CUtlVector<union __m128,class CUtlMemoryAligned<union __m128,16>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<__m128,CUtlMemoryAligned<__m128,16>>::~CUtlVector<__m128,CUtlMemoryAligned<__m128,16>>(
        CUtlVector<__m128,CUtlMemoryAligned<__m128,16> > *this)
{
  __m128 *m_pMemory; // eax

  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((int)this->m_Memory.m_pMemory & 0xFFFFFFFC) - 4));
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pMemory & 0xFFFFFFFC) - 4));
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
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
}

//------------------------------------------------------------------------------
// Address: 0x1004E660
// Name: public: int CUtlVector<class CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>>,class CUtlMemory<class CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> >,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CStudioRender::ShadowState_t,int>::Grow(
      (CUtlMemory<CStudioRender::ShadowState_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF20
// Name: public: void CUtlVector<class CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>>,class CUtlMemory<class CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> >,CUtlMemory<CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> >,int> > *this)
{
  int v1; // edi
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> >,CUtlMemory<CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          free(pMem: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          free(pMem: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050AE0
// Name: public: int studiohwdata_t::GetLODForMetric(float)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall studiohwdata_t::GetLODForMetric(studiohwdata_t *this, float lodMetric)
{
  int result; // eax
  float m_fValue; // xmm0_4
  studioloddata_t *m_pLODs; // edx
  int m_NumLODs; // ecx
  int v7; // ecx
  float *i; // edx

  if ( (`studiohwdata_t::GetLODForMetric'::`2'::`local static guard' & 1) == 0 )
  {
    `studiohwdata_t::GetLODForMetric'::`2'::`local static guard' |= 1u;
    ConVarRef::ConVarRef(this: &`studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale, pName: "r_lod_switch_scale");
  }
  if ( this->m_NumLODs == 0 )
    return 0;
  if ( ConVarRef::IsValid(this: &`studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale) )
    m_fValue = `studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale.m_pConVarState->m_Value.m_fValue;
  else
    m_fValue = 1.0;
  m_pLODs = this->m_pLODs;
  m_NumLODs = this->m_NumLODs - 1;
  if ( m_pLODs[this->m_NumLODs - 1].m_SwitchPoint >= 0.0 )
    m_NumLODs = this->m_NumLODs;
  result = this->m_RootLOD;
  v7 = m_NumLODs - 1;
  if ( this->m_RootLOD >= v7 )
    return v7;
  for ( i = &m_pLODs[result + 1].m_SwitchPoint; (float)(*i * m_fValue) <= lodMetric; i += 8 )
  {
    if ( ++result >= v7 )
      return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10050B80
// Name: void StudioChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StudioChangeCallback()
{
  MaterialLock_t__ *v0; // eax

  v0 = g_pMaterialSystem->Lock(this: g_pMaterialSystem);
  g_pMaterialSystem->Unlock(this: g_pMaterialSystem, a2: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10050BB0
// Name: void BuildTexturePath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildTexturePath(const char *pTexturePath, const char *pTextureName, char *pDest, int destSizeInBytes)
{
  const char *v4; // edi
  char *v5; // esi
  int i; // eax
  char v7; // cl
  char texturePath[260]; // [esp+0h] [ebp-104h] BYREF

  if ( pTexturePath != nullptr )
  {
    v4 = pTextureName;
    if ( pTextureName != nullptr && pDest != nullptr && destSizeInBytes > 0 )
    {
      texturePath[0] = 0;
      V_strncpy(pDest: texturePath, pSrc: pTexturePath, maxLen: 260);
      v5 = texturePath;
      if ( texturePath[0] == 92 || texturePath[0] == 47 )
        v5 = &texturePath[1];
      if ( *pTextureName == 92 || *pTextureName == 47 )
        v4 = pTextureName + 1;
      for ( i = _V_strlen(str: v5); i > 0; i = _V_strlen(str: v5) )
      {
        v7 = v5[i - 1];
        if ( v7 != 92 && v7 != 47 )
          break;
        v5[i - 1] = 0;
      }
      *pDest = 0;
      V_ComposeFileName(path: v5, filename: v4, dest: pDest, destSize: destSizeInBytes);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050C80
// Name: public: virtual struct StudioDecalHandle_t__ __near * CStudioRenderContext::CreateDecalList(struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
StudioDecalHandle_t__ *__thiscall CStudioRenderContext::CreateDecalList(CStudioRenderContext *this, studiohwdata_t *a1)
{
  return CStudioRender::CreateDecalList(this: g_pStudioRenderImp, pHardwareData: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10050C90
// Name: public: virtual int CStudioRenderContext::ComputeModelLod(struct studiohwdata_t __near *,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRenderContext::ComputeModelLod(
        CStudioRenderContext *this,
        studiohwdata_t *pHardwareData,
        float flUnitSphereSize,
        float *pMetric)
{
  float lodMetric; // xmm0_4

  lodMetric = 0.0;
  if ( flUnitSphereSize != 0.0 )
    lodMetric = 100.0 / flUnitSphereSize;
  if ( pMetric != nullptr )
    *pMetric = lodMetric;
  return studiohwdata_t::GetLODForMetric(this: pHardwareData, lodMetric);
}

//------------------------------------------------------------------------------
// Address: 0x10050CD0
// Name: public: virtual void __near * CStudioRenderContext::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CStudioRenderContext::QueryInterface(CStudioRenderContext *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10050CF0
// Name: public: virtual void CStudioRenderContext::Mat_Stub(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::Mat_Stub(CStudioRenderContext *this, IMaterialSystem *pMatSys)
{
  g_pMaterialSystem = pMatSys;
}

//------------------------------------------------------------------------------
// Address: 0x10050D00
// Name: private: void CStudioRenderContext::ComputeMaterialFlags(struct studiohdr_t __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::ComputeMaterialFlags(
        CStudioRenderContext *this,
        studiohdr_t *phdr,
        IMaterial *pMaterial)
{
  IMaterialVar *v3; // eax
  IMaterialVar *v4; // eax
  IMaterialVar *v5; // esi

  if ( pMaterial->UsesEnvCubemap(this: pMaterial) )
    phdr->flags |= 2u;
  if ( pMaterial->NeedsPowerOfTwoFrameBufferTexture(this: pMaterial, a2: false) )
    phdr->flags |= 0x20u;
  v3 = pMaterial->FindVarFast(this: pMaterial, a2: "$bumpmap", a3: &bumpvarCache);
  if ( v3 != nullptr && v3->IsDefined(this: v3) && pMaterial->NeedsTangentSpace(this: pMaterial) )
    phdr->flags |= 0x80u;
  v4 = pMaterial->FindVarFast(this: pMaterial, a2: "$phong", a3: &phongVarCache);
  v5 = v4;
  if ( v4 != nullptr && v4->IsDefined(this: v4) && v5->GetIntValueInternal(this: v5) != 0 )
    phdr->flags |= 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x10050DC0
// Name: GetTextureName
// Source: json
//------------------------------------------------------------------------------
char *__fastcall GetTextureName(
        OptimizedModel::FileHeader_t *pVtxHeader,
        int lodID,
        studiohdr_t *phdr,
        int inMaterialID)
{
  int v4; // eax
  int v5; // edx
  char *v6; // eax
  int v7; // ecx
  char *i; // esi

  v4 = pVtxHeader->materialReplacementListOffset + 8 * lodID;
  v5 = *(int *)((char *)&pVtxHeader->version + v4);
  v6 = (char *)pVtxHeader + v4;
  v7 = 0;
  if ( v5 <= 0 )
    return (char *)phdr
         + 64 * inMaterialID
         + phdr->textureindex
         + *(int *)((char *)&phdr->id + 64 * inMaterialID + phdr->textureindex);
  for ( i = &v6[*((_DWORD *)v6 + 1)]; *(__int16 *)i != inMaterialID; i += 6 )
  {
    if ( ++v7 >= v5 )
      return (char *)phdr
           + 64 * inMaterialID
           + phdr->textureindex
           + *(int *)((char *)&phdr->id + 64 * inMaterialID + phdr->textureindex);
  }
  return &i[*(_DWORD *)(i + 2)];
}

//------------------------------------------------------------------------------
// Address: 0x10050E20
// Name: SuppressAllHWMorphs
// Source: json
//------------------------------------------------------------------------------
void __cdecl SuppressAllHWMorphs(mstudiomodel_t *pModel, OptimizedModel::ModelLODHeader_t *pVtxLOD)
{
  int v2; // ebx
  _DWORD *v3; // ecx
  int v4; // edi
  int v5; // esi
  int v6; // eax
  char v7; // dl
  int k; // [esp+4h] [ebp-4h]

  v2 = 0;
  for ( k = 0; k < pModel->nummeshes; ++k )
  {
    v3 = (int *)((char *)&pVtxLOD->numMeshes + v2 + pVtxLOD->meshOffset);
    v4 = 0;
    if ( (int)*v3 > 0 )
    {
      v5 = 0;
      do
      {
        v6 = v5 + v3[1];
        v7 = *((_BYTE *)v3 + v6 + 24);
        if ( (v7 & 4) != 0 )
          *((_BYTE *)v3 + v6 + 24) = v7 | 8;
        ++v4;
        v5 += 33;
      }
      while ( v4 < *v3 );
    }
    v2 += 9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050E80
// Name: ComputeTotalFlexCount
// Source: json
//------------------------------------------------------------------------------
int __cdecl ComputeTotalFlexCount(int pModel)
{
  int v2; // ecx
  int v3; // edi
  int v4; // edx
  int v5; // esi
  unsigned int v6; // ecx
  _DWORD *v7; // eax
  int nFlexCount; // [esp+14h] [ebp+8h]

  v2 = *(_DWORD *)(pModel + 72);
  v3 = 0;
  v4 = 0;
  v5 = 0;
  nFlexCount = 0;
  if ( v2 >= 2 )
  {
    v6 = ((unsigned int)(v2 - 2) >> 1) + 1;
    v7 = (_DWORD *)(*(_DWORD *)(pModel + 76) + pModel + 132);
    v3 = 2 * v6;
    do
    {
      v4 += *(v7 - 29);
      v5 += *v7;
      v7 += 58;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v3 < *(_DWORD *)(pModel + 72) )
    nFlexCount = *(_DWORD *)(*(_DWORD *)(pModel + 76) + 116 * v3 + pModel + 16);
  return nFlexCount + v5 + v4;
}

//------------------------------------------------------------------------------
// Address: 0x10050EE0
// Name: private: int CStudioRenderContext::CountDeltaFlexedStripGroups(struct mstudiomodel_t __near *,struct OptimizedModel::ModelLODHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRenderContext::CountDeltaFlexedStripGroups(
        CStudioRenderContext *this,
        mstudiomodel_t *pModel,
        OptimizedModel::ModelLODHeader_t *pVtxLOD)
{
  int result; // eax
  int *v4; // edx
  int nummeshes; // edi
  int v6; // esi
  _BYTE *v7; // ecx

  result = 0;
  if ( pModel->nummeshes > 0 )
  {
    v4 = (int *)((char *)&pVtxLOD->numMeshes + pVtxLOD->meshOffset);
    nummeshes = pModel->nummeshes;
    do
    {
      v6 = *v4;
      if ( *v4 > 0 )
      {
        v7 = (char *)v4 + v4[1] + 24;
        do
        {
          if ( (*v7 & 4) != 0 )
            ++result;
          v7 += 33;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = (int *)((char *)v4 + 9);
      --nummeshes;
    }
    while ( nummeshes != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10050F30
// Name: private: int CStudioRenderContext::CountFlexedVertices(struct mstudiomesh_t __near *,struct OptimizedModel::StripGroupHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRenderContext::CountFlexedVertices(
        CStudioRenderContext *this,
        mstudiomesh_t *pMesh,
        OptimizedModel::StripGroupHeader_t *pStripGroup)
{
  void *v5; // esp
  int numVerts; // ecx
  int v7; // eax
  unsigned __int16 *v8; // edx
  int numflexes; // ecx
  _BYTE *v10; // esi
  unsigned __int16 *v11; // edx
  int v12; // ebx
  int v13; // ecx
  _WORD v14[6]; // [esp+0h] [ebp-10h] BYREF
  int nVAnimSizeBytes; // [esp+Ch] [ebp-4h]
  int nFlexVertCount; // [esp+18h] [ebp+8h]
  OptimizedModel::StripGroupHeader_t *pStripGroupa; // [esp+1Ch] [ebp+Ch]

  if ( pMesh->numflexes == 0 )
    return 0;
  v5 = alloca(2 * *(int *)((char *)&pMesh->vertexdata.numLODVertexes[7] + pMesh->modelindex));
  memset(
    dst: (unsigned __int8 *)v14,
    value: 0xFFu,
    count: 2 * *(int *)((char *)&pMesh->vertexdata.numLODVertexes[7] + pMesh->modelindex));
  numVerts = pStripGroup->numVerts;
  v7 = 0;
  if ( pStripGroup->numVerts > 0 )
  {
    v8 = (unsigned __int16 *)((char *)&pStripGroup->vertOffset + pStripGroup->vertOffset);
    do
    {
      v14[*v8] = v7++;
      v8 = (unsigned __int16 *)((char *)v8 + 9);
    }
    while ( v7 < numVerts );
  }
  numflexes = pMesh->numflexes;
  nFlexVertCount = 0;
  if ( numflexes > 0 )
  {
    v10 = (char *)&pMesh->meshid + pMesh->flexindex;
    pStripGroupa = (OptimizedModel::StripGroupHeader_t *)pMesh->numflexes;
    do
    {
      v11 = (unsigned __int16 *)&v10[*((_DWORD *)v10 - 2) - 32];
      nVAnimSizeBytes = 2 * (*v10 != 0) + 16;
      if ( *((int *)v10 - 3) > 0 )
      {
        v12 = *((_DWORD *)v10 - 3);
        do
        {
          v13 = *v11;
          if ( v14[v13] != 0xFFFF )
          {
            ++nFlexVertCount;
            v14[v13] = -1;
          }
          v11 = (unsigned __int16 *)((char *)v11 + nVAnimSizeBytes);
          --v12;
        }
        while ( v12 != 0 );
      }
      v10 += 60;
      pStripGroupa = (OptimizedModel::StripGroupHeader_t *)((char *)pStripGroupa - 1);
    }
    while ( pStripGroupa != nullptr );
  }
  return nFlexVertCount;
}

//------------------------------------------------------------------------------
// Address: 0x10051010
// Name: SortVertCount
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortVertCount(_DWORD *arg1, _DWORD *arg2)
{
  return s_pVertexCount[*arg2] - s_pVertexCount[*arg1];
}

//------------------------------------------------------------------------------
// Address: 0x10051030
// Name: private: void CStudioRenderContext::DetermineHWMorphing(struct mstudiomodel_t __near *,struct OptimizedModel::ModelLODHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DetermineHWMorphing(
        CStudioRenderContext *this,
        mstudiomodel_t *pModel,
        OptimizedModel::ModelLODHeader_t *pVtxLOD)
{
  bool (__thiscall *HasFastVertexTextures)(IMaterialSystemHardwareConfig *); // edx
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  unsigned int v9; // esi
  void *v10; // esp
  int v11; // ebx
  mstudiomesh_t *v12; // edi
  int *v13; // esi
  int v14; // eax
  OptimizedModel::StripGroupHeader_t *v15; // eax
  int v16; // eax
  int v17; // ecx
  void *v18; // esp
  int j; // eax
  void *v20; // esp
  int k; // eax
  int v22; // ecx
  int v23; // edi
  int v24; // ecx
  int *v25; // ecx
  int v26; // esi
  int v27; // eax
  char v28; // dl
  _DWORD v29[3]; // [esp+0h] [ebp-34h] BYREF
  unsigned int v30; // [esp+Ch] [ebp-28h]
  int nFlexedStripGroup; // [esp+10h] [ebp-24h]
  int nMaxHWMorphBatchCount; // [esp+14h] [ebp-20h]
  CStudioRenderContext *v33; // [esp+18h] [ebp-1Ch]
  bool *pSuppressHWMorph; // [esp+1Ch] [ebp-18h]
  int i; // [esp+20h] [ebp-14h]
  int v36; // [esp+24h] [ebp-10h]
  int nCount; // [esp+28h] [ebp-Ch]
  int v38; // [esp+2Ch] [ebp-8h]
  int v39; // [esp+30h] [ebp-4h]

  HasFastVertexTextures = g_pMaterialSystemHardwareConfig->HasFastVertexTextures;
  v33 = this;
  if ( HasFastVertexTextures(this: g_pMaterialSystemHardwareConfig) )
  {
    v5 = ComputeTotalFlexCount((int)pModel);
    if ( v5 != 0 )
    {
      if ( v5 >= 200 )
      {
        v6 = g_pMaterialSystemHardwareConfig->MaxHWMorphBatchCount(this: g_pMaterialSystemHardwareConfig);
        nMaxHWMorphBatchCount = v6;
        if ( pModel->nummeshes > v6 )
        {
          v7 = CStudioRenderContext::CountDeltaFlexedStripGroups(this, pModel, pVtxLOD);
          v8 = v7;
          nFlexedStripGroup = v7;
          if ( v7 > v6 )
          {
            v9 = (4 * v7 + 15) & 0xFFFFFFF0;
            v30 = v9;
            v10 = alloca(4 * v7);
            pSuppressHWMorph = (bool *)v29;
            nCount = 0;
            i = 0;
            if ( pModel->nummeshes > 0 )
            {
              v38 = 0;
              v39 = 0;
              do
              {
                v11 = 0;
                v12 = (mstudiomesh_t *)&pModel->name[v39 + pModel->meshindex];
                v13 = (int *)((char *)&pVtxLOD->numMeshes + v38 + pVtxLOD->meshOffset);
                if ( *v13 > 0 )
                {
                  v14 = 0;
                  v36 = 0;
                  do
                  {
                    v15 = (OptimizedModel::StripGroupHeader_t *)((char *)v13 + v14 + v13[1]);
                    if ( (v15->flags & 4) != 0 )
                    {
                      v16 = CStudioRenderContext::CountFlexedVertices(this: v33, pMesh: v12, pStripGroup: v15);
                      v17 = nCount;
                      *(_DWORD *)&pSuppressHWMorph[4 * nCount] = v16;
                      nCount = v17 + 1;
                    }
                    ++v11;
                    v14 = v36 + 33;
                    v36 += 33;
                  }
                  while ( v11 < *v13 );
                }
                v39 += 116;
                v38 += 9;
                ++i;
              }
              while ( i < pModel->nummeshes );
              v6 = nMaxHWMorphBatchCount;
              v8 = nFlexedStripGroup;
              v9 = v30;
            }
            v18 = alloca(v9);
            for ( j = 0; j < v8; ++j )
              v29[j] = j;
            s_pVertexCount = (int *)pSuppressHWMorph;
            qsort(base: v29, num: nCount, width: 4u, comp: (int (__cdecl *)(const void *, const void *))SortVertCount);
            v20 = alloca(v8);
            pSuppressHWMorph = (bool *)v29;
            memset(dst: (unsigned __int8 *)v29, value: 1u, count: v8);
            for ( k = 0; k < v6; pSuppressHWMorph[v22] = false )
              v22 = v29[k++];
            v23 = 0;
            v36 = 0;
            if ( pModel->nummeshes > 0 )
            {
              nCount = 0;
              do
              {
                v24 = nCount + pVtxLOD->meshOffset;
                i = 0;
                v25 = (int *)((char *)&pVtxLOD->numMeshes + v24);
                if ( *v25 > 0 )
                {
                  v26 = 0;
                  do
                  {
                    v27 = v26 + v25[1];
                    v28 = *((_BYTE *)v25 + v27 + 24);
                    if ( (v28 & 4) != 0 )
                    {
                      if ( pSuppressHWMorph[v23] )
                        *((_BYTE *)v25 + v27 + 24) = v28 | 8;
                      ++v23;
                    }
                    v26 += 33;
                    ++i;
                  }
                  while ( i < *v25 );
                }
                nCount += 9;
                ++v36;
              }
              while ( v36 < pModel->nummeshes );
            }
          }
        }
      }
      else
      {
        SuppressAllHWMorphs(pModel, pVtxLOD);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051250
// Name: private: void CStudioRenderContext::R_StudioBuildMeshStrips(struct studiomeshgroup_t __near *,struct OptimizedModel::StripGroupHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::R_StudioBuildMeshStrips(
        CStudioRenderContext *this,
        studiomeshgroup_t *pMeshGroup,
        OptimizedModel::StripGroupHeader_t *pStripGroup)
{
  int numStrips; // edx
  int v5; // esi
  unsigned int v6; // eax
  int *v7; // ecx
  int v8; // edi
  OptimizedModel::StripHeader_t *v9; // eax
  studiomeshgroup_t *v10; // edx
  int v11; // ecx
  OptimizedModel::StripHeader_t *v12; // ecx
  char *v13; // eax
  OptimizedModel::StripHeader_t *m_pStripData; // ecx
  unsigned int v15; // edi
  int i; // [esp+Ch] [ebp-4h]
  int boneStateChangeOffset; // [esp+1Ch] [ebp+Ch]

  numStrips = pStripGroup->numStrips;
  v5 = 0;
  v6 = 0;
  if ( numStrips > 0 )
  {
    v7 = (int *)((char *)&pStripGroup->numStrips + pStripGroup->stripOffset + 3);
    do
    {
      v8 = *v7;
      v7 = (int *)((char *)v7 + 35);
      --numStrips;
      v6 += 8 * v8 + 35;
    }
    while ( numStrips != 0 );
  }
  v9 = (OptimizedModel::StripHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v6);
  v10 = pMeshGroup;
  pMeshGroup->m_pStripData = v9;
  v11 = pStripGroup->numStrips;
  boneStateChangeOffset = 35 * v11;
  i = 0;
  if ( v11 <= 0 )
  {
    pMeshGroup->m_NumStrips = v11;
  }
  else
  {
    do
    {
      v12 = &v10->m_pStripData[v5];
      v13 = (char *)pStripGroup + v5 * 35 + pStripGroup->stripOffset;
      *(_QWORD *)&v12->numIndices = *(_QWORD *)v13;
      *(_QWORD *)&v12->numVerts = *((_QWORD *)v13 + 1);
      *(_QWORD *)&v12->numBones = *((_QWORD *)v13 + 2);
      *(_QWORD *)((char *)&v12->boneStateChangeOffset + 1) = *((_QWORD *)v13 + 3);
      *(_WORD *)((char *)&v12->topologyOffset + 1) = *((_WORD *)v13 + 16);
      HIBYTE(v12->topologyOffset) = v13[34];
      v10->m_pStripData[v5].boneStateChangeOffset = boneStateChangeOffset - v5 * 35;
      m_pStripData = v10->m_pStripData;
      v15 = 8 * m_pStripData[v5].numBoneStateChanges;
      if ( v15 != 0 )
      {
        memcpy(
          dst: (unsigned __int8 *)m_pStripData + boneStateChangeOffset,
          src: (unsigned __int8 *)pStripGroup
        + v5 * 35
        + pStripGroup->stripOffset
        + *(int *)((char *)&pStripGroup->stripOffset + v5 * 35 + pStripGroup->stripOffset + 3),
          count: v15);
        v10 = pMeshGroup;
        boneStateChangeOffset += v15;
      }
      ++v5;
      ++i;
    }
    while ( i < pStripGroup->numStrips );
    v10->m_NumStrips = pStripGroup->numStrips;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051360
// Name: private: unsigned __int64 CStudioRenderContext::CalculateVertexFormat(struct studiohdr_t const __near *,struct studioloddata_t const __near *,struct mstudiomesh_t const __near *,struct OptimizedModel::StripGroupHeader_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRenderContext::CalculateVertexFormat(
        CStudioRenderContext *this,
        const studiohdr_t *pStudioHdr,
        const studioloddata_t *pStudioLodData,
        const mstudiomesh_t *pMesh,
        OptimizedModel::StripGroupHeader_t *pGroup,
        bool bIsHwSkinned)
{
  int numStrips; // eax
  int v8; // ebx
  __int16 *v9; // edx
  int numskinfamilies; // eax
  unsigned __int64 v11; // rdi
  bool bSkinnedMesh_3; // [esp+1Fh] [ebp+Bh]

  numStrips = pGroup->numStrips;
  bSkinnedMesh_3 = pStudioHdr->numbones > 1;
  v8 = 0;
  if ( numStrips > 0 )
  {
    v9 = (__int16 *)((char *)&pGroup->numStrips + pGroup->stripOffset);
    do
    {
      if ( v8 <= *v9 )
        v8 = *v9;
      v9 = (__int16 *)((char *)v9 + 35);
      --numStrips;
    }
    while ( numStrips != 0 );
  }
  numskinfamilies = pStudioHdr->numskinfamilies;
  v11 = 0;
  if ( numskinfamilies > 0 )
  {
    do
    {
      LODWORD(v11) = v11 | 0x103;
      if ( ((v11 >> 15) & 7) < 4 )
        LODWORD(v11) = v11 & 0xFFFC7FFF | 0x20000;
      if ( ((v11 >> 18) & 7) < 2 )
        LODWORD(v11) = v11 & 0xFFE3FFFF | 0x80000;
      --numskinfamilies;
    }
    while ( numskinfamilies != 0 );
  }
  if ( bSkinnedMesh_3 )
  {
    if ( v8 > 0 )
      LODWORD(v11) = v11 | 0x2000;
    LODWORD(v11) = v11 | 0x80;
  }
  if ( bIsHwSkinned
    && g_pMaterialSystemHardwareConfig->SupportsCompressedVertices(this: g_pMaterialSystemHardwareConfig) == VERTEX_COMPRESSION_ON )
  {
    return v11 | 0x400;
  }
  else
  {
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051500
// Name: private: bool CStudioRenderContext::MeshNeedsTangentSpace(struct studiohdr_t __near *,struct studioloddata_t __near *,struct mstudiomesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioRenderContext::MeshNeedsTangentSpace(
        CStudioRenderContext *this,
        studiohdr_t *pStudioHdr,
        studioloddata_t *pStudioLodData,
        mstudiomesh_t *pMesh)
{
  char *v4; // ebx
  int numskinfamilies; // eax
  int v6; // edi
  IMaterial *v7; // ecx

  if ( pStudioHdr == nullptr )
    return 0;
  v4 = (char *)pStudioHdr + pStudioHdr->skinindex;
  if ( v4 == nullptr )
    return 0;
  numskinfamilies = pStudioHdr->numskinfamilies;
  if ( numskinfamilies == 0 )
    return 0;
  v6 = 0;
  if ( numskinfamilies <= 0 )
    return 0;
  while ( 1 )
  {
    v7 = pStudioLodData->ppMaterials[*(__int16 *)&v4[2 * pMesh->material]];
    if ( v7 != nullptr && v7->NeedsTangentSpace(this: v7) )
      break;
    if ( ++v6 >= pStudioHdr->numskinfamilies )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10051580
// Name: public: struct vertexFileHeader_t const __near * mstudiomodel_t::CacheVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
const vertexFileHeader_t *__thiscall mstudiomodel_t::CacheVertexData(mstudiomodel_t *this, studiohdr_t *pModelData)
{
  return g_pStudioDataCache->CacheVertexData(this: g_pStudioDataCache, a2: pModelData);
}

//------------------------------------------------------------------------------
// Address: 0x100515A0
// Name: public: virtual void CStudioRenderContext::RefreshStudioHdr(struct studiohdr_t __near *,struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CStudioRenderContext::RefreshStudioHdr(const Vector *normal, Vector *dest)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100515B0
// Name: public: virtual void CStudioRenderContext::SetEyeViewTarget(struct studiohdr_t const __near *,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::SetEyeViewTarget(
        CStudioRenderContext *this,
        const studiohdr_t *pStudioHdr,
        int nBodyIndex,
        const Vector *viewtarget)
{
  this->m_RC.m_ViewTarget = *viewtarget;
}

//------------------------------------------------------------------------------
// Address: 0x100515D0
// Name: public: virtual int CStudioRenderContext::GetNumAmbientLightSamples(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRenderContext::GetNumAmbientLightSamples(CStudioRenderContext *this)
{
  return 6;
}

//------------------------------------------------------------------------------
// Address: 0x100515E0
// Name: public: virtual class Vector const __near * CStudioRenderContext::GetAmbientLightDirections(void)
// Source: json
//------------------------------------------------------------------------------
TableVector *__thiscall CStudioRenderContext::GetAmbientLightDirections(CStudioRenderContext *this)
{
  return s_pAmbientLightDir;
}

//------------------------------------------------------------------------------
// Address: 0x100515F0
// Name: public: virtual int CStudioRenderContext::GetNumLODs(struct studiohwdata_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRenderContext::GetNumLODs(CStudioRenderContext *this, const studiohwdata_t *hardwareData)
{
  return hardwareData->m_NumLODs;
}

//------------------------------------------------------------------------------
// Address: 0x10051600
// Name: public: virtual float CStudioRenderContext::GetLODSwitchValue(struct studiohwdata_t const __near &,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CStudioRenderContext::GetLODSwitchValue(
        CStudioRenderContext *this,
        const studiohwdata_t *hardwareData,
        int nLOD)
{
  return hardwareData->m_pLODs[nLOD].m_SwitchPoint;
}

//------------------------------------------------------------------------------
// Address: 0x10051620
// Name: public: virtual void CStudioRenderContext::SetLODSwitchValue(struct studiohwdata_t __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::SetLODSwitchValue(
        CStudioRenderContext *this,
        studiohwdata_t *hardwareData,
        int nLOD,
        float flSwitchValue)
{
  MaterialLock_t__ *v4; // eax

  v4 = g_pMaterialSystem->Lock(this: g_pMaterialSystem);
  hardwareData->m_pLODs[nLOD].m_SwitchPoint = flSwitchValue;
  g_pMaterialSystem->Unlock(this: g_pMaterialSystem, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10051660
// Name: public: virtual int CStudioRenderContext::GetMaterialList(struct studiohdr_t __near *,int,class IMaterial __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRenderContext::GetMaterialList(
        CStudioRenderContext *this,
        studiohdr_t *pStudioHdr,
        int count,
        IMaterial **ppMaterials)
{
  IMaterial *v5; // edi
  int v7; // eax
  const char *v8; // ebx
  int v9; // eax
  char v10; // cl
  const char *v11; // eax
  IMaterialSystem_vtbl *v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  char szPath[260]; // [esp+8h] [ebp-110h] BYREF
  int v17; // [esp+10Ch] [ebp-Ch]
  int i; // [esp+110h] [ebp-8h]
  int j; // [esp+114h] [ebp-4h]
  int found; // [esp+120h] [ebp+8h]

  v5 = nullptr;
  if ( pStudioHdr->textureindex == 0 )
    return 0;
  found = 0;
  i = 0;
  if ( pStudioHdr->numtextures > 0 )
  {
    v7 = 0;
    v17 = 0;
    while ( 1 )
    {
      v8 = (char *)pStudioHdr
         + v7
         + pStudioHdr->textureindex
         + *(int *)((char *)&pStudioHdr->id + v7 + pStudioHdr->textureindex);
      if ( *v8 == 92 || *v8 == 47 )
        ++v8;
      j = 0;
      if ( pStudioHdr->numcdtextures > 0 )
      {
        do
        {
          if ( v5 != nullptr && !v5->IsErrorMaterial(this: v5) )
            break;
          v9 = *(int *)((char *)&pStudioHdr->id + 4 * j + pStudioHdr->cdtextureindex);
          v10 = *((_BYTE *)&pStudioHdr->id + v9);
          v11 = (char *)pStudioHdr + v9;
          if ( v10 == 92 || v10 == 47 )
            ++v11;
          V_ComposeFileName(path: v11, filename: v8, dest: szPath, destSize: 260);
          v12 = g_pMaterialSystem->__vftable;
          v13 = (pStudioHdr->flags & 0x200) != 0
              ? ((int (__stdcall *)(const char *, const char *, _DWORD, _DWORD))v12->FindMaterial)(
                  a1: "models/obsolete/obsolete",
                  a2: "Model textures",
                  a3: 0,
                  a4: 0)
              : ((int (__stdcall *)(char *, const char *, _DWORD, _DWORD))v12->FindMaterial)(
                  a1: szPath,
                  a2: "Model textures",
                  a3: 0,
                  a4: 0);
          v5 = (IMaterial *)v13;
          ++j;
        }
        while ( j < pStudioHdr->numcdtextures );
        if ( v5 != nullptr )
        {
          if ( found >= count )
            return found;
          v14 = found;
          v15 = 0;
          if ( found <= 0 )
            goto LABEL_27;
          while ( ppMaterials[v15] != v5 )
          {
            if ( ++v15 >= found )
              goto LABEL_27;
          }
          if ( v15 >= found )
            break;
        }
      }
LABEL_28:
      v7 = v17 + 64;
      ++i;
      v17 += 64;
      if ( i >= pStudioHdr->numtextures )
        return found;
      v5 = nullptr;
    }
    v14 = found;
LABEL_27:
    ppMaterials[v14] = v5;
    found = v14 + 1;
    goto LABEL_28;
  }
  return found;
}

//------------------------------------------------------------------------------
// Address: 0x100517D0
// Name: public: virtual int CStudioRenderContext::GetMaterialListFromBodyAndSkin(unsigned short,int,int,int,class IMaterial __near * __near *)
// Source: json
//------------------------------------------------------------------------------
studiohwdata_t *__thiscall CStudioRenderContext::GetMaterialListFromBodyAndSkin(
        CStudioRenderContext *this,
        int studio,
        int nSkin,
        int nBody,
        int nCountOutputMaterials,
        IMaterial **ppOutputMaterials)
{
  int v6; // esi
  studiohwdata_t *result; // eax
  studiohdr_t *v9; // edi
  mstudiomodel_t *v10; // edx
  int v11; // edi
  IMaterial *v12; // ecx
  int v13; // eax
  studiohdr_t *pStudioHdr; // [esp+4h] [ebp-20h]
  IMaterial **ppInputMaterials; // [esp+8h] [ebp-1Ch]
  __int16 *pSkinRef; // [esp+Ch] [ebp-18h]
  studiohwdata_t *pStudioHWData; // [esp+10h] [ebp-14h]
  int lodID; // [esp+14h] [ebp-10h]
  int k; // [esp+18h] [ebp-Ch]
  mstudiomodel_t *pModel; // [esp+1Ch] [ebp-8h] BYREF
  int v21; // [esp+20h] [ebp-4h]
  int i; // [esp+3Ch] [ebp+18h]

  v6 = 0;
  result = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: studio);
  pStudioHWData = result;
  if ( result != nullptr )
  {
    lodID = result->m_RootLOD;
    if ( result->m_RootLOD < result->m_NumLODs )
    {
      v21 = 32 * result->m_RootLOD;
      do
      {
        v9 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: studio);
        pStudioHdr = v9;
        ppInputMaterials = pStudioHWData->m_pLODs[v21 / 0x20u].ppMaterials;
        if ( nSkin >= v9->numskinfamilies )
          nSkin = 0;
        pSkinRef = (__int16 *)((char *)v9 + 2 * nSkin * v9->numskinref + v9->skinindex);
        for ( i = 0; i < v9->numbodyparts; ++i )
        {
          pModel = nullptr;
          R_StudioSetupModel(bodypart: i, entity_body: nBody, ppSubModel: &pModel, pStudioHdr: v9);
          v10 = pModel;
          k = 0;
          if ( pModel->nummeshes > 0 )
          {
            v11 = 0;
            do
            {
              v12 = ppInputMaterials[pSkinRef[*(_DWORD *)&v10->name[v11 + v10->meshindex]]];
              v13 = 0;
              if ( v6 <= 0 )
                goto LABEL_14;
              while ( ppOutputMaterials[v13] != v12 )
              {
                if ( ++v13 >= v6 )
                  goto LABEL_14;
              }
              if ( v13 >= v6 )
              {
LABEL_14:
                ppOutputMaterials[v6++] = v12;
                if ( v6 >= nCountOutputMaterials )
                  return (studiohwdata_t *)v6;
              }
              v11 += 116;
              ++k;
            }
            while ( k < v10->nummeshes );
            v9 = pStudioHdr;
          }
        }
        v21 += 32;
        ++lodID;
      }
      while ( lodID < pStudioHWData->m_NumLODs );
    }
    return (studiohwdata_t *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051920
// Name: public: virtual void CStudioRenderContext::UpdateConfig(struct StudioRenderConfig_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::UpdateConfig(CStudioRenderContext *this, const StudioRenderConfig_t *config)
{
  qmemcpy(&this->m_RC, config, 0x38u);
}

//------------------------------------------------------------------------------
// Address: 0x10051940
// Name: public: virtual void CStudioRenderContext::GetCurrentConfig(struct StudioRenderConfig_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::GetCurrentConfig(CStudioRenderContext *this, StudioRenderConfig_t *config)
{
  *config = this->m_RC.m_Config.StudioRenderConfig_t;
}

//------------------------------------------------------------------------------
// Address: 0x10051960
// Name: public: virtual void CStudioRenderContext::ForcedMaterialOverride(class IMaterial __near *,enum OverrideType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::ForcedMaterialOverride(
        CStudioRenderContext *this,
        IMaterial *newMaterial,
        OverrideType_t nOverrideType)
{
  this->m_RC.m_pForcedMaterial = newMaterial;
  this->m_RC.m_nForcedMaterialType = nOverrideType;
}

//------------------------------------------------------------------------------
// Address: 0x10051980
// Name: public: virtual void CStudioRenderContext::SetViewState(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::SetViewState(
        CStudioRenderContext *this,
        const Vector *viewOrigin,
        const Vector *viewRight,
        const Vector *viewUp,
        const Vector *viewPlaneNormal)
{
  this->m_RC.m_ViewOrigin = *viewOrigin;
  this->m_RC.m_ViewRight = *viewRight;
  this->m_RC.m_ViewUp = *viewUp;
  this->m_RC.m_ViewPlaneNormal = *viewPlaneNormal;
}

//------------------------------------------------------------------------------
// Address: 0x100519E0
// Name: public: virtual void CStudioRenderContext::SetColorModulation(float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::SetColorModulation(CStudioRenderContext *this, const float *pColor)
{
  this->m_RC.m_ColorMod[0] = *pColor;
  this->m_RC.m_ColorMod[1] = pColor[1];
  this->m_RC.m_ColorMod[2] = pColor[2];
}

//------------------------------------------------------------------------------
// Address: 0x10051A10
// Name: public: virtual void CStudioRenderContext::SetAlphaModulation(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::SetAlphaModulation(CStudioRenderContext *this, float alpha)
{
  this->m_RC.m_AlphaMod = alpha;
}

//------------------------------------------------------------------------------
// Address: 0x10051A30
// Name: private: void CStudioRenderContext::GenerateRandomFlexWeights(int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::GenerateRandomFlexWeights(
        CStudioRenderContext *this,
        int nWeightCount,
        float *pWeights,
        float *pDelayedWeights)
{
  int m_nValue; // eax
  void *v6; // esp
  int i; // eax
  int j; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // ebx
  int k; // edi
  double v13; // st7
  int v14; // edx
  int m; // edi
  double v16; // st7
  int v17; // edx
  _DWORD v18[3]; // [esp+8h] [ebp-10h]
  int nRandomFlex; // [esp+14h] [ebp-4h]
  unsigned int nWeightCounta; // [esp+20h] [ebp+8h]

  if ( r_randomflex.m_pParent != nullptr )
  {
    m_nValue = r_randomflex.m_pParent->m_Value.m_nValue;
    nRandomFlex = m_nValue;
    if ( m_nValue > 0 && pWeights != nullptr )
    {
      if ( m_nValue > nWeightCount )
        nRandomFlex = nWeightCount;
      nWeightCounta = 4 * nWeightCount;
      v6 = alloca(4 * nWeightCount);
      for ( i = 0; i < nWeightCount; ++i )
        v18[i] = i;
      for ( j = 0; j < nWeightCount; ++j )
      {
        v9 = _RandomInt(a1: 0, a2: nWeightCount - 1);
        v10 = v18[v9];
        v18[v9] = v18[j];
        v18[j] = v10;
      }
      memset(dst: (unsigned __int8 *)pWeights, value: 0, count: nWeightCounta);
      v11 = nRandomFlex;
      for ( k = 0; k < v11; pWeights[v14] = v13 )
      {
        v13 = _RandomFloat(a1: 0, a2: 1065353216);
        v14 = v18[k++];
      }
      if ( pDelayedWeights != nullptr )
      {
        memset(dst: (unsigned __int8 *)pDelayedWeights, value: 0, count: nWeightCounta);
        for ( m = 0; m < v11; pDelayedWeights[v17] = v16 )
        {
          v16 = _RandomFloat(a1: 0, a2: 1065353216);
          v17 = v18[m++];
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051B60
// Name: private: void CStudioRenderContext::InvokeBindProxies(class IMatRenderContext __near *,class ICallQueue __near *,struct DrawModelInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::InvokeBindProxies(
        CStudioRenderContext *this,
        IMatRenderContext *pRenderContext,
        ICallQueue *pCallQueue,
        const DrawModelInfo_t *info)
{
  int skin; // ecx
  const DrawModelInfo_t *v6; // edi
  studiohdr_t *m_pStudioHdr; // esi
  __int16 *v8; // eax
  void *v9; // esp
  bool v10; // cc
  mstudiomodel_t *v11; // ecx
  int v12; // edi
  int v13; // eax
  IMaterial *v14; // esi
  IMaterial_vtbl *v15; // edx
  unsigned __int8 v16[12]; // [esp+0h] [ebp-20h] BYREF
  IMaterial **ppMaterials; // [esp+Ch] [ebp-14h]
  int somethingOtherThanI; // [esp+10h] [ebp-10h]
  __int16 *pSkinRef; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  mstudiomodel_t *pModel; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_RC.m_pForcedMaterial != nullptr )
  {
    if ( this->m_RC.m_nForcedMaterialType == OVERRIDE_NORMAL
      && this->m_RC.m_pForcedMaterial->HasProxy(this: this->m_RC.m_pForcedMaterial) )
    {
      this->m_RC.m_pForcedMaterial->CallBindProxy(
        this: this->m_RC.m_pForcedMaterial,
        a2: info->m_pClientEntity,
        a3: pCallQueue);
    }
  }
  else
  {
    skin = this->m_RC.m_Config.skin;
    v6 = info;
    if ( skin <= 0 )
      skin = info->m_Skin;
    m_pStudioHdr = info->m_pStudioHdr;
    v8 = (__int16 *)((char *)info->m_pStudioHdr + info->m_pStudioHdr->skinindex);
    pSkinRef = v8;
    if ( skin > 0 && skin < m_pStudioHdr->numskinfamilies )
      pSkinRef = &v8[skin * m_pStudioHdr->numskinref];
    v9 = alloca(m_pStudioHdr->numtextures);
    memset(dst: v16, value: 0, count: m_pStudioHdr->numtextures);
    v10 = m_pStudioHdr->numbodyparts <= 0;
    ppMaterials = info->m_pHardwareData->m_pLODs[info->m_Lod].ppMaterials;
    i = 0;
    if ( !v10 )
    {
      do
      {
        R_StudioSetupModel(bodypart: i, entity_body: v6->m_Body, ppSubModel: &pModel, pStudioHdr: m_pStudioHdr);
        v11 = pModel;
        v10 = pModel->nummeshes <= 0;
        somethingOtherThanI = 0;
        if ( !v10 )
        {
          v12 = 0;
          do
          {
            v13 = pSkinRef[*(_DWORD *)&v11->name[v12 + v11->meshindex]];
            if ( v16[v13] == 0 )
            {
              v14 = ppMaterials[v13];
              v15 = v14->__vftable;
              v16[v13] = 1;
              if ( v15->HasProxy(this: v14) )
                v14->CallBindProxy(this: v14, a2: info->m_pClientEntity, a3: pCallQueue);
              v11 = pModel;
            }
            v12 += 116;
            ++somethingOtherThanI;
          }
          while ( somethingOtherThanI < v11->nummeshes );
          v6 = info;
        }
        m_pStudioHdr = v6->m_pStudioHdr;
        ++i;
      }
      while ( i < m_pStudioHdr->numbodyparts );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051CE0
// Name: public: virtual enum AppSystemTier_t CTier3AppSystem<class IStudioRender,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier3AppSystem<IStudioRender,0>::GetTier(CTier3AppSystem<IStudioRender,0> *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10051CF0
// Name: public: virtual void CBaseAppSystem<class IStudioRender>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IStudioRender>::Reconnect(
        CBaseAppSystem<IStudioRender> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10051D10
// Name: public: CUtlEnvelope<struct ColorMeshInfo_t __near *>::CUtlEnvelope<struct ColorMeshInfo_t __near *>(struct ColorMeshInfo_t __near * const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlEnvelope<ColorMeshInfo_t *> *__thiscall CUtlEnvelope<ColorMeshInfo_t *>::CUtlEnvelope<ColorMeshInfo_t *>(
        CUtlEnvelope<ColorMeshInfo_t *> *this,
        ColorMeshInfo_t **pData,
        int nElems)
{
  int v3; // edi
  unsigned __int8 *v5; // eax

  v3 = 4 * nElems;
  if ( pData != nullptr )
  {
    this->m_nBytes = v3;
    if ( v3 <= 4 )
    {
      memcpy(dst: (unsigned __int8 *)this, src: (unsigned __int8 *)pData, count: v3);
    }
    else
    {
      v5 = (unsigned __int8 *)operator new(nSize: v3);
      this->m_pData = v5;
      memcpy(dst: v5, src: (unsigned __int8 *)pData, count: v3);
    }
    return this;
  }
  else
  {
    this->m_pData = nullptr;
    this->m_nBytes = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051D80
// Name: private: void CUtlDataEnvelope::Assign(class CUtlDataEnvelope const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDataEnvelope::Assign(CUtlDataEnvelope *this, CUtlDataEnvelope *from)
{
  CUtlDataEnvelope *m_pData; // ebx
  int m_nBytes; // esi
  unsigned __int8 *v5; // eax

  m_pData = from;
  m_nBytes = from->m_nBytes;
  if ( m_nBytes != 0 )
  {
    if ( m_nBytes > 4 )
      m_pData = (CUtlDataEnvelope *)from->m_pData;
  }
  else
  {
    m_pData = nullptr;
  }
  if ( m_pData != nullptr )
  {
    this->m_nBytes = m_nBytes;
    if ( m_nBytes <= 4 )
    {
      memcpy(dst: (unsigned __int8 *)this, src: (unsigned __int8 *)m_pData, count: m_nBytes);
    }
    else
    {
      v5 = (unsigned __int8 *)operator new(nSize: m_nBytes);
      this->m_pData = v5;
      memcpy(dst: v5, src: (unsigned __int8 *)m_pData, count: m_nBytes);
    }
  }
  else
  {
    this->m_pData = nullptr;
    this->m_nBytes = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051E20
// Name: private: void CStudioRenderContext::LoadMaterials(struct studiohdr_t __near *,struct OptimizedModel::FileHeader_t __near *,struct studioloddata_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::LoadMaterials(
        CStudioRenderContext *this,
        studiohdr_t *phdr,
        OptimizedModel::FileHeader_t *pVtxHeader,
        studioloddata_t *lodData,
        int lodID)
{
  int numtextures; // eax
  IMaterial *v7; // ebx
  int v8; // edi
  char *TextureName; // eax
  IMaterialSystem_vtbl *v10; // edx
  int v11; // eax
  const char *v12; // eax
  int j; // edi
  char *v14; // eax
  int v15; // edi
  int v16; // eax
  const char *v17; // eax
  bool v18; // al
  char szPrefix[256]; // [esp+Ch] [ebp-208h] BYREF
  char szPath[260]; // [esp+10Ch] [ebp-108h] BYREF
  CStudioRenderContext *v21; // [esp+210h] [ebp-4h]
  int i; // [esp+21Ch] [ebp+8h]

  numtextures = phdr->numtextures;
  v21 = this;
  lodData->numMaterials = numtextures;
  if ( numtextures != 0 )
  {
    lodData->ppMaterials = (IMaterial **)operator new(nSize: 4 * numtextures);
    lodData->pMaterialFlags = (int *)operator new(nSize: 4 * lodData->numMaterials);
    if ( phdr->textureindex != 0 )
    {
      i = 0;
      if ( phdr->numtextures > 0 )
      {
        do
        {
          v7 = nullptr;
          v8 = 0;
          szPath[0] = 0;
          if ( phdr->numcdtextures <= 0 )
            goto LABEL_16;
          do
          {
            if ( v7 != nullptr && !v7->IsErrorMaterial(this: v7) )
              break;
            TextureName = GetTextureName(pVtxHeader, lodID, phdr, inMaterialID: i);
            BuildTexturePath(
              pTexturePath: (const char *)phdr + *(int *)((char *)&phdr->id + 4 * v8 + phdr->cdtextureindex),
              pTextureName: TextureName,
              pDest: szPath,
              destSizeInBytes: 260);
            v10 = g_pMaterialSystem->__vftable;
            if ( (phdr->flags & 0x200) != 0 )
            {
              v11 = ((int (__stdcall *)(const char *, const char *, _DWORD, _DWORD))v10->FindMaterial)(
                      a1: "models/obsolete/obsolete",
                      a2: "Model textures",
                      a3: 0,
                      a4: 0);
              v7 = (IMaterial *)v11;
              if ( v11 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 168))(a1: v11) != 0 )
                _Warning(a1: "StudioRender: OBSOLETE material missing: \"models/obsolete/obsolete\"\n");
            }
            else
            {
              v7 = (IMaterial *)((int (__stdcall *)(char *, const char *, _DWORD, _DWORD))v10->FindMaterial)(
                                  a1: szPath,
                                  a2: "Model textures",
                                  a3: 0,
                                  a4: 0);
            }
            ++v8;
          }
          while ( v8 < phdr->numcdtextures );
          if ( v7 == nullptr || v7->IsErrorMaterial(this: v7) )
          {
LABEL_16:
            v12 = studiohdr_t::pszName(this: phdr);
            V_strncpy(pDest: szPrefix, pSrc: v12, maxLen: 256);
            V_strncat(pDest: szPrefix, pSrc: " : ", destBufferSize: 0x100u, max_chars_to_copy: -1);
            for ( j = 0; j < phdr->numcdtextures; ++j )
            {
              V_strncpy(
                pDest: szPath,
                pSrc: (const char *)phdr + *(int *)((char *)&phdr->id + 4 * j + phdr->cdtextureindex),
                maxLen: 260);
              v14 = GetTextureName(pVtxHeader, lodID, phdr, inMaterialID: i);
              V_strncat(pDest: szPath, pSrc: v14, destBufferSize: 0x104u, max_chars_to_copy: -1);
              V_FixSlashes(pname: szPath, separator: 92);
              g_pMaterialSystem->FindMaterial(
                this: g_pMaterialSystem,
                a2: szPath,
                a3: "Model textures",
                a4: true,
                a5: szPrefix);
            }
          }
          v15 = i;
          lodData->ppMaterials[i] = v7;
          if ( v7 != nullptr )
          {
            v7->IncrementReferenceCount(this: v7);
            CStudioRenderContext::ComputeMaterialFlags(this: v21, phdr, pMaterial: v7);
            v16 = (int)v7->FindVarFast(this: v7, a2: "$clientShader", a3: &dword_10436D3C);
            if ( v16 != 0 )
            {
              v17 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v16 + 28))(a1: v16);
              v18 = _V_stricmp(s1: v17, s2: "MouthShader") == 0;
            }
            else
            {
              v18 = false;
            }
            lodData->pMaterialFlags[i] = v18;
          }
          ++i;
        }
        while ( v15 + 1 < phdr->numtextures );
      }
    }
  }
  else
  {
    lodData->ppMaterials = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052100
// Name: private: int CStudioRenderContext::ComputeRenderLOD(class IMatRenderContext __near *,struct DrawModelInfo_t const __near &,class Vector const __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRenderContext::ComputeRenderLOD(
        CStudioRenderContext *this,
        IMatRenderContext *pRenderContext,
        const DrawModelInfo_t *info,
        const Vector *origin,
        float *pMetric)
{
  int result; // eax
  int v7; // edi
  int m_RootLOD; // ecx
  double v9; // st7
  studiohwdata_t *m_pHardwareData; // ecx
  float lodMetric; // xmm0_4
  float screenSize; // [esp+24h] [ebp+Ch]

  result = info->m_Lod;
  v7 = info->m_pHardwareData->m_NumLODs - 1;
  if ( pMetric != nullptr )
    *pMetric = 0.0;
  if ( result == -2 )
    return v7;
  if ( result == -1 )
  {
    v9 = ((double (__stdcall *)(const Vector *, int))pRenderContext->ComputePixelWidthOfSphere)(
           a1: origin,
           a2: 1056964608);
    m_pHardwareData = info->m_pHardwareData;
    if ( v9 == 0.0 )
    {
      lodMetric = 0.0;
    }
    else
    {
      screenSize = v9;
      lodMetric = 100.0 / screenSize;
    }
    if ( pMetric != nullptr )
      *pMetric = lodMetric;
    result = studiohwdata_t::GetLODForMetric(this: m_pHardwareData, lodMetric);
    if ( (info->m_pStudioHdr->flags & 0x40) != 0 )
      --v7;
    m_RootLOD = info->m_pHardwareData->m_RootLOD;
    if ( result < m_RootLOD )
      return m_RootLOD;
  }
  else
  {
    m_RootLOD = info->m_pHardwareData->m_RootLOD;
    if ( result < m_RootLOD )
      return m_RootLOD;
  }
  if ( result > v7 )
    return v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100521C0
// Name: public: float __near * CMatRenderData<float>::Lock(int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CMatRenderData<float>::Lock(CMatRenderData<float> *this, int nCount, float *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  float *result; // eax
  unsigned int v6; // ebx
  float *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(float *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 4 * nCount;
    result = (float *)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: 4 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052240
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<VMatrix> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(VMatrix *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x100522A0
// Name: public: StudioRenderContext_t::StudioRenderContext_t(struct StudioRenderContext_t const __near &)
// Source: json
//------------------------------------------------------------------------------
StudioRenderContext_t *__thiscall StudioRenderContext_t::StudioRenderContext_t(
        StudioRenderContext_t *this,
        const StudioRenderContext_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10052480
// Name: public: struct matrix3x4_t __near * CMatRenderData<struct matrix3x4_t>::Lock(int,struct matrix3x4_t const __near *)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__thiscall CMatRenderData<matrix3x4_t>::Lock(
        CMatRenderData<matrix3x4_t> *this,
        int nCount,
        const matrix3x4_t *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  matrix3x4_t *result; // eax
  unsigned int v6; // edi
  matrix3x4_t *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(const matrix3x4_t *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 48 * nCount;
    result = (matrix3x4_t *)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: 48 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052500
// Name: public: struct StudioArrayData_t __near * CMatRenderData<struct StudioArrayData_t>::Lock(int,struct StudioArrayData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
StudioArrayData_t *__thiscall CMatRenderData<StudioArrayData_t>::Lock(
        CMatRenderData<StudioArrayData_t> *this,
        int nCount,
        StudioArrayData_t *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  StudioArrayData_t *result; // eax
  unsigned int v6; // edi
  StudioArrayData_t *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(StudioArrayData_t *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 16 * nCount;
    result = (StudioArrayData_t *)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: 16 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052580
// Name: public: struct MeshInstanceData_t __near * CMatRenderData<struct MeshInstanceData_t>::Lock(int,struct MeshInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
MeshInstanceData_t *__thiscall CMatRenderData<MeshInstanceData_t>::Lock(
        CMatRenderData<MeshInstanceData_t> *this,
        int nCount,
        const MeshInstanceData_t *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  MeshInstanceData_t *result; // eax
  unsigned int v6; // edi
  MeshInstanceData_t *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(const MeshInstanceData_t *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 76 * nCount;
    result = (MeshInstanceData_t *)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: 76 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052600
// Name: public: struct FlashlightState_t __near * CMatRenderData<struct FlashlightState_t>::Lock(int,struct FlashlightState_t const __near *)
// Source: json
//------------------------------------------------------------------------------
FlashlightState_t *__thiscall CMatRenderData<FlashlightState_t>::Lock(
        CMatRenderData<FlashlightState_t> *this,
        int nCount,
        const FlashlightState_t *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  FlashlightState_t *result; // eax
  unsigned int v6; // edi
  FlashlightState_t *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(const FlashlightState_t *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 252 * nCount;
    result = (FlashlightState_t *)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: 252 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052680
// Name: public: class VMatrix __near * CMatRenderData<class VMatrix>::Lock(int,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall CMatRenderData<VMatrix>::Lock(CMatRenderData<VMatrix> *this, int nCount, const VMatrix *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  VMatrix *result; // eax
  unsigned int v6; // edi
  VMatrix *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(const VMatrix *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = nCount << 6;
    result = (VMatrix *)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: nCount << 6);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052700
// Name: public: CMemberFunctor4<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::CMemberFunctor4<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, const matrix3x4_t *, int),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        const matrix3x4_t *arg3,
        int *arg4)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_Proxy.m_pObject = pObject;
  this->m_Proxy.m_pfnProxied = pfnProxied;
  qmemcpy((void *)&this->m_arg1, arg1, sizeof(this->m_arg1));
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100527B0
// Name: protected: virtual bool CRefCountServiceBase<1,class CRefMT>::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRefCountServiceBase<1,CRefMT>::OnFinalRelease(ConCommand *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100527C0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x100527D0
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
// Address: 0x10052800
// Name: private: void CStudioRenderContext::R_StudioBuildMorph(struct studiohdr_t __near *,struct studiomeshgroup_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::StripGroupHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::R_StudioBuildMorph(
        CStudioRenderContext *this,
        studiohdr_t *pStudioHdr,
        studiomeshgroup_t *pMeshGroup,
        mstudiomesh_t *pMesh,
        OptimizedModel::StripGroupHeader_t *pStripGroup)
{
  mstudiomesh_t *v5; // ebx
  int modelindex; // edx
  void *v7; // esp
  int numVerts; // ecx
  int v9; // eax
  unsigned __int16 *v10; // edx
  IMatRenderContext *v11; // eax
  int numflexes; // ecx
  int v13; // eax
  _BYTE *v14; // edx
  IMorph *v15; // eax
  float flVertAnimFixedPointScale; // xmm0_4
  int v17; // ecx
  char *v18; // edi
  int v19; // edi
  int v20; // eax
  int v21; // ebx
  __int16 *v22; // esi
  int v23; // eax
  float v24; // xmm2_4
  int v25; // edx
  float v26; // xmm2_4
  int v27; // edx
  IMatRenderContext *m_pObject; // esi
  unsigned int v29; // [esp+8h] [ebp-14Ch]
  _WORD v30[6]; // [esp+Ch] [ebp-148h] BYREF
  char pTemp[256]; // [esp+18h] [ebp-13Ch] BYREF
  CMorphBuilder morphBuilder; // [esp+118h] [ebp-3Ch] BYREF
  unsigned __int16 *pMeshIndexToGroupIndex; // [esp+148h] [ebp-Ch]
  int nVAnimSizeBytes; // [esp+14Ch] [ebp-8h]
  CMatRenderContextPtr pRenderContext; // [esp+150h] [ebp-4h]
  studiohdr_t *pStudioHdra; // [esp+15Ch] [ebp+8h]
  unsigned int i; // [esp+168h] [ebp+14h]
  int ia; // [esp+168h] [ebp+14h]

  if ( g_pMaterialSystemHardwareConfig->HasFastVertexTextures(this: g_pMaterialSystemHardwareConfig)
    && (pMeshGroup->m_Flags & 4) != 0
    && (pStripGroup->flags & 8) == 0 )
  {
    v5 = pMesh;
    modelindex = pMesh->modelindex;
    v7 = alloca(2 * *(int *)((char *)&pMesh->vertexdata.numLODVertexes[7] + modelindex));
    v29 = 2 * *(int *)((char *)&pMesh->vertexdata.numLODVertexes[7] + modelindex);
    pMeshIndexToGroupIndex = v30;
    memset(dst: (unsigned __int8 *)v30, value: 0xFFu, count: v29);
    numVerts = pStripGroup->numVerts;
    v9 = 0;
    if ( pStripGroup->numVerts > 0 )
    {
      v10 = (unsigned __int16 *)((char *)&pStripGroup->vertOffset + pStripGroup->vertOffset);
      do
      {
        v30[*v10] = v9++;
        v10 = (unsigned __int16 *)((char *)v10 + 9);
      }
      while ( v9 < numVerts );
    }
    v11 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    pRenderContext.m_pObject = v11;
    if ( v11 != nullptr )
      v11->BeginRender(this: v11);
    numflexes = pMesh->numflexes;
    v13 = 0;
    i = 27;
    if ( numflexes > 0 )
    {
      v14 = (char *)&pMesh->meshid + pMesh->flexindex;
      while ( *v14 != 1 )
      {
        ++v13;
        v14 += 60;
        if ( v13 >= numflexes )
          goto LABEL_15;
      }
      i = 31;
    }
LABEL_15:
    V_snprintf(pDest: pTemp, maxLen: 256, pFormat: "%s [%p]", pStudioHdr->name, pMeshGroup);
    v15 = pRenderContext.m_pObject->CreateMorph(this: pRenderContext.m_pObject, a2: i, a3: pTemp);
    pMeshGroup->m_pMorph = v15;
    if ( (pStudioHdr->flags & 0x200000) != 0 )
      flVertAnimFixedPointScale = pStudioHdr->flVertAnimFixedPointScale;
    else
      flVertAnimFixedPointScale = 0.00024414062;
    morphBuilder.m_pMorph = v15;
    ((void (__stdcall *)(_DWORD))v15->Lock)(a1: 1.0 / flVertAnimFixedPointScale);
    v17 = 0;
    ia = 0;
    if ( pMesh->numflexes > 0 )
    {
      v18 = nullptr;
      pStudioHdra = nullptr;
      while ( 1 )
      {
        v19 = (int)&v18[(_DWORD)v5 + v5->flexindex];
        v20 = *(_DWORD *)(v19 + 24);
        v21 = 0;
        nVAnimSizeBytes = 2 * (*(_BYTE *)(v19 + 32) != 0) + 16;
        if ( *(int *)(v19 + 20) > 0 )
        {
          v22 = (__int16 *)(v20 + v19 + 6);
          do
          {
            v23 = pMeshIndexToGroupIndex[(unsigned __int16)*(v22 - 3)];
            if ( (_WORD)v23 != 0xFFFF )
            {
              v24 = (float)*v22;
              v25 = v22[1];
              morphBuilder.m_Info.m_PositionDelta.x = (float)*(v22 - 1) * flVertAnimFixedPointScale;
              morphBuilder.m_Info.m_PositionDelta.y = v24 * flVertAnimFixedPointScale;
              morphBuilder.m_Info.m_PositionDelta.z = (float)v25 * flVertAnimFixedPointScale;
              v26 = (float)v22[3];
              v27 = v22[4];
              morphBuilder.m_Info.m_NormalDelta.x = (float)v22[2] * flVertAnimFixedPointScale;
              morphBuilder.m_Info.m_NormalDelta.y = v26 * flVertAnimFixedPointScale;
              morphBuilder.m_Info.m_NormalDelta.z = (float)v27 * flVertAnimFixedPointScale;
              morphBuilder.m_Info.m_flSpeed = (float)*((unsigned __int8 *)v22 - 4) * 0.0039215689;
              morphBuilder.m_Info.m_flSide = (float)*((unsigned __int8 *)v22 - 3) * 0.0039215689;
              if ( *(_BYTE *)(v19 + 32) == 1 )
                morphBuilder.m_Info.m_flWrinkleDelta = (float)v22[5] * flVertAnimFixedPointScale;
              else
                morphBuilder.m_Info.m_flWrinkleDelta = 0.0;
              morphBuilder.m_Info.m_nMorphTargetId = v17;
              morphBuilder.m_Info.m_nVertexId = v23;
              morphBuilder.m_pMorph->AddMorph(this: morphBuilder.m_pMorph, a2: (const MorphVertexInfo_t *)&morphBuilder);
              v17 = ia;
            }
            v22 = (__int16 *)((char *)v22 + nVAnimSizeBytes);
            ++v21;
          }
          while ( v21 < *(_DWORD *)(v19 + 20) );
        }
        ++v17;
        v18 = &pStudioHdra->name[48];
        ia = v17;
        pStudioHdra = (studiohdr_t *)((char *)pStudioHdra + 60);
        if ( v17 >= pMesh->numflexes )
          break;
        v5 = pMesh;
      }
    }
    morphBuilder.m_pMorph->Unlock(this: morphBuilder.m_pMorph);
    m_pObject = pRenderContext.m_pObject;
    morphBuilder.m_pMorph = nullptr;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
  else
  {
    pMeshGroup->m_pMorph = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052B20
// Name: private: void CStudioRenderContext::R_StudioDestroyStaticMeshes(int,struct studiomeshdata_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::R_StudioDestroyStaticMeshes(
        CStudioRenderContext *this,
        int numStudioMeshes,
        studiomeshdata_t **ppStudioMeshes)
{
  void **v3; // ebx
  IMatRenderContext *v4; // eax
  int v5; // esi
  int v6; // ebx
  int v7; // esi
  int i; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  CMatRenderContextPtr pRenderContext; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v3 = (void **)ppStudioMeshes;
  if ( *ppStudioMeshes != nullptr )
  {
    v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    pRenderContext.m_pObject = v4;
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    v5 = 0;
    for ( i = 0; v5 < numStudioMeshes; i = v5 )
    {
      v6 = (int)*v3 + 8 * v5;
      j = 0;
      if ( *(int *)v6 > 0 )
      {
        v11 = 0;
        do
        {
          v7 = v11 + *(_DWORD *)(v6 + 4);
          if ( *(_DWORD *)(v7 + 16) != 0 )
          {
            free(pMem: *(void **)(v7 + 16));
            *(_DWORD *)(v7 + 16) = 0;
          }
          if ( *(_DWORD *)(v7 + 24) != 0 )
          {
            free(pMem: *(void **)(v7 + 24));
            *(_DWORD *)(v7 + 24) = 0;
          }
          if ( *(_DWORD *)(v7 + 28) != 0 )
          {
            free(pMem: *(void **)(v7 + 28));
            *(_DWORD *)(v7 + 28) = 0;
          }
          if ( *(_DWORD *)(v7 + 32) != 0 )
          {
            free(pMem: *(void **)(v7 + 32));
            *(_DWORD *)(v7 + 32) = 0;
          }
          if ( *(_DWORD *)v7 != 0 )
          {
            ((void (__thiscall *)(CMatRenderContextPtr, _DWORD))pRenderContext.m_pObject->DestroyStaticMesh)(
              a1: pRenderContext,
              a2: *(_DWORD *)v7);
            *(_DWORD *)v7 = 0;
          }
          if ( *(_DWORD *)(v7 + 40) != 0 )
          {
            ((void (__thiscall *)(CMatRenderContextPtr, _DWORD))pRenderContext.m_pObject->DestroyMorph)(
              a1: pRenderContext,
              a2: *(_DWORD *)(v7 + 40));
            *(_DWORD *)(v7 + 40) = 0;
          }
          if ( *(_DWORD *)(v7 + 12) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v7 + 12));
            *(_DWORD *)(v7 + 12) = 0;
          }
          v11 += 44;
          ++j;
        }
        while ( j < *(_DWORD *)v6 );
        v5 = i;
      }
      if ( *(_DWORD *)(v6 + 4) != 0 )
      {
        free(pMem: *(void **)(v6 + 4));
        *(_DWORD *)(v6 + 4) = 0;
      }
      v3 = (void **)ppStudioMeshes;
      ++v5;
    }
    if ( *v3 != nullptr )
    {
      free(pMem: *v3);
      *v3 = nullptr;
    }
    if ( pRenderContext.m_pObject != nullptr )
    {
      ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->EndRender)(a1: pRenderContext);
      ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->Release)(a1: pRenderContext);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052C80
// Name: private: void CStudioRenderContext::BuildDecalBoneMap(struct studiohdr_t __near *,int __near *,int __near *,int __near *,struct mstudiomesh_t __near *,struct OptimizedModel::StripGroupHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::BuildDecalBoneMap(
        CStudioRenderContext *this,
        studiohdr_t *pStudioHdr,
        int *pUsedBones,
        int *pBoneRemap,
        int *pMaxBoneCount,
        mstudiomesh_t *pMesh,
        OptimizedModel::StripGroupHeader_t *pStripGroup)
{
  OptimizedModel::StripGroupHeader_t *v7; // eax
  int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  int v12; // eax
  bool v13; // sf
  int *v14; // eax
  int v15; // eax
  int *v16; // eax
  int v17; // eax
  int *v18; // eax
  int v19; // eax
  int *v20; // eax
  int v21; // eax
  int *v22; // eax
  bool v23; // cc
  int v24; // edx
  int v25; // ecx
  int v26; // eax
  int i; // [esp+8h] [ebp-8h]
  const mstudio_meshvertexdata_t *pVertData; // [esp+Ch] [ebp-4h]
  float *pStudioHdra; // [esp+18h] [ebp+8h]
  int nBoneCount; // [esp+20h] [ebp+10h]
  mstudiomesh_t *pMesha; // [esp+28h] [ebp+18h]

  pVertData = GetFatVertexData(pMesh, pStudioHdr);
  v7 = pStripGroup;
  i = 0;
  if ( pStripGroup->numVerts > 0 )
  {
    pMesha = nullptr;
    do
    {
      v9 = 0;
      v10 = (unsigned int)pVertData->modelvertexdata->pVertexData
          + 48
          * ((int)pVertData[-1].modelvertexdata
           + (unsigned int)pVertData->modelvertexdata[-3].pVertexData / 0x30
           + *(unsigned __int16 *)((char *)&v7->vertOffset + (_DWORD)pMesha + v7->vertOffset));
      v11 = *(unsigned __int8 *)(v10 + 15);
      nBoneCount = v11;
      if ( v11 >= 4 )
      {
        pStudioHdra = (float *)(v10 + 8);
        do
        {
          if ( *(pStudioHdra - 2) != 0.0 )
          {
            v12 = *(unsigned __int8 *)(v9 + v10 + 12);
            v13 = pBoneRemap[v12] < 0;
            v14 = &pBoneRemap[v12];
            if ( v13 )
              *v14 = (*pUsedBones)++;
          }
          if ( *(pStudioHdra - 1) != 0.0 )
          {
            v15 = *(unsigned __int8 *)(v9 + v10 + 13);
            v13 = pBoneRemap[v15] < 0;
            v16 = &pBoneRemap[v15];
            if ( v13 )
              *v16 = (*pUsedBones)++;
          }
          if ( *pStudioHdra != 0.0 )
          {
            v17 = *(unsigned __int8 *)(v9 + v10 + 14);
            v13 = pBoneRemap[v17] < 0;
            v18 = &pBoneRemap[v17];
            if ( v13 )
              *v18 = (*pUsedBones)++;
          }
          if ( pStudioHdra[1] != 0.0 )
          {
            v19 = *(unsigned __int8 *)(v10 + v9 + 15);
            v13 = pBoneRemap[v19] < 0;
            v20 = &pBoneRemap[v19];
            if ( v13 )
              *v20 = (*pUsedBones)++;
          }
          v11 = nBoneCount;
          pStudioHdra += 4;
          v9 += 4;
        }
        while ( v9 < nBoneCount - 3 );
      }
      if ( v9 < (int)v11 )
      {
        do
        {
          if ( *(float *)(v10 + 4 * v9) != 0.0 )
          {
            v21 = *(unsigned __int8 *)(v9 + v10 + 12);
            v13 = pBoneRemap[v21] < 0;
            v22 = &pBoneRemap[v21];
            if ( v13 )
              *v22 = (*pUsedBones)++;
          }
          ++v9;
        }
        while ( v9 < nBoneCount );
      }
      pMesha = (mstudiomesh_t *)((char *)pMesha + 9);
      v23 = ++i < pStripGroup->numVerts;
      v7 = pStripGroup;
    }
    while ( v23 );
  }
  v24 = 0;
  if ( v7->numStrips > 0 )
  {
    v25 = 0;
    do
    {
      v26 = *(__int16 *)((char *)&v7->numStrips + v25 + v7->stripOffset);
      if ( v26 > *pMaxBoneCount )
        *pMaxBoneCount = v26;
      v7 = pStripGroup;
      ++v24;
      v25 += 35;
    }
    while ( v24 < pStripGroup->numStrips );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052E30
// Name: private: void CStudioRenderContext::ComputeHWMorphDecalBoneRemap(struct studiohdr_t __near *,struct OptimizedModel::FileHeader_t __near *,struct studiohwdata_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::ComputeHWMorphDecalBoneRemap(
        CStudioRenderContext *this,
        studiohdr_t *pStudioHdr,
        OptimizedModel::FileHeader_t *pVtxHdr,
        studiohwdata_t *pStudioHWData,
        int nLOD)
{
  studiohdr_t *v5; // esi
  int numbones; // eax
  void *v7; // esp
  studioloddata_t *v8; // edi
  int v9; // ebx
  OptimizedModel::BodyPartHeader_t *v10; // edx
  mstudiobodyparts_t *v11; // ecx
  bool v12; // cc
  char *v13; // ebx
  int v14; // ecx
  OptimizedModel::ModelLODHeader_t *v15; // eax
  int v16; // edi
  mstudiomesh_t *v17; // edi
  int *v18; // esi
  int v19; // ebx
  unsigned __int8 *v20; // eax
  int *v21; // [esp-Ch] [ebp-68h]
  unsigned int v22; // [esp-8h] [ebp-64h]
  _DWORD v23[3]; // [esp+0h] [ebp-5Ch] BYREF
  int nBufSize; // [esp+Ch] [ebp-50h]
  mstudiobodyparts_t *pBodyPart; // [esp+10h] [ebp-4Ch]
  OptimizedModel::ModelLODHeader_t *pVtxLOD; // [esp+14h] [ebp-48h]
  CStudioRenderContext *v27; // [esp+18h] [ebp-44h]
  studiomeshdata_t *pMeshData; // [esp+1Ch] [ebp-40h]
  int v29; // [esp+20h] [ebp-3Ch]
  OptimizedModel::BodyPartHeader_t *pVtxBodyPart; // [esp+24h] [ebp-38h]
  int nMaxBoneCount; // [esp+28h] [ebp-34h] BYREF
  int *pBoneRemap; // [esp+2Ch] [ebp-30h]
  int nUsedBones; // [esp+30h] [ebp-2Ch] BYREF
  int i; // [esp+34h] [ebp-28h]
  studioloddata_t *pStudioLOD; // [esp+38h] [ebp-24h]
  int v36; // [esp+3Ch] [ebp-20h]
  int k; // [esp+40h] [ebp-1Ch]
  int l; // [esp+44h] [ebp-18h]
  int v39; // [esp+48h] [ebp-14h]
  int v40; // [esp+4Ch] [ebp-10h]
  int j; // [esp+50h] [ebp-Ch]
  int v42; // [esp+54h] [ebp-8h]
  int v43; // [esp+58h] [ebp-4h]
  studiohwdata_t *pStudioHWDataa; // [esp+6Ch] [ebp+10h]

  v5 = pStudioHdr;
  numbones = pStudioHdr->numbones;
  v27 = this;
  if ( numbones != 0 )
  {
    nBufSize = 4 * numbones;
    v7 = alloca(4 * numbones);
    pBoneRemap = v23;
    memset(dst: (unsigned __int8 *)v23, value: 0xFFu, count: 4 * numbones);
    v23[0] = 0;
    v8 = &pStudioHWData->m_pLODs[nLOD];
    v9 = 0;
    nMaxBoneCount = 0;
    nUsedBones = 1;
    pStudioLOD = v8;
    i = 0;
    if ( pStudioHdr->numbodyparts > 0 )
    {
      v39 = 0;
      do
      {
        v10 = (OptimizedModel::BodyPartHeader_t *)((char *)pVtxHdr + 8 * v9 + pVtxHdr->bodyPartOffset);
        v11 = (mstudiobodyparts_t *)((char *)v5 + v39 + v5->bodypartindex);
        v12 = v11->nummodels <= 0;
        pBodyPart = v11;
        pVtxBodyPart = v10;
        j = 0;
        if ( !v12 )
        {
          v29 = 12 * nLOD;
          v40 = 0;
          while ( 1 )
          {
            v13 = (char *)v11 + v40 + v11->modelindex;
            v14 = (int)&v10[j] + v10->modelOffset;
            v15 = (OptimizedModel::ModelLODHeader_t *)(v14 + v29 + *(_DWORD *)(v14 + 4));
            pVtxLOD = v15;
            k = 0;
            if ( *((int *)v13 + 18) > 0 )
            {
              v16 = 0;
              v42 = 0;
              v36 = 0;
              do
              {
                v17 = (mstudiomesh_t *)&v13[v16 + *((_DWORD *)v13 + 19)];
                v18 = (int *)((char *)&v15->numMeshes + v42 + v15->meshOffset);
                pMeshData = &pStudioLOD->m_pMeshData[v17->meshid];
                l = 0;
                if ( *v18 > 0 )
                {
                  v43 = 0;
                  pStudioHWDataa = nullptr;
                  do
                  {
                    if ( *(int *)((char *)&pStudioHWDataa[1].m_NumStudioMeshes + (unsigned int)pMeshData->m_pMeshGroup) != 0 )
                    {
                      CStudioRenderContext::BuildDecalBoneMap(
                        this: v27,
                        pStudioHdr,
                        pUsedBones: &nUsedBones,
                        pBoneRemap,
                        pMaxBoneCount: &nMaxBoneCount,
                        pMesh: v17,
                        pStripGroup: (OptimizedModel::StripGroupHeader_t *)((char *)v18 + v43 + v18[1]));
                      v15 = pVtxLOD;
                    }
                    pStudioHWDataa = (studiohwdata_t *)((char *)pStudioHWDataa + 44);
                    v43 += 33;
                    ++l;
                  }
                  while ( l < *v18 );
                }
                v42 += 9;
                v16 = v36 + 116;
                ++k;
                v36 += 116;
              }
              while ( k < *((_DWORD *)v13 + 18) );
              v5 = pStudioHdr;
              v8 = pStudioLOD;
            }
            v11 = pBodyPart;
            v40 += 148;
            if ( ++j >= pBodyPart->nummodels )
              break;
            v10 = pVtxBodyPart;
          }
          v9 = i;
        }
        v39 += 16;
        i = ++v9;
      }
      while ( v9 < v5->numbodyparts );
      v19 = nUsedBones;
      if ( nUsedBones > 1 )
      {
        if ( v19 > ((int (__thiscall *)(IMaterialSystemHardwareConfig *, _DWORD))g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices)(
                     a1: g_pMaterialSystemHardwareConfig,
                     a2: v23[0]) )
          _Warning(a1: "Hardware morphing of decals will be busted! Too many unique bones on flexed vertices!\n");
        v20 = (unsigned __int8 *)operator new(nSize: 4 * v5->numbones);
        v22 = nBufSize;
        v21 = pBoneRemap;
        v8->m_pHWMorphDecalBoneRemap = (int *)v20;
        memcpy(dst: v20, src: (unsigned __int8 *)v21, count: v22);
        v8->m_nDecalBoneCount = nMaxBoneCount;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053060
// Name: public: virtual void CStudioRenderContext::SetAmbientLightColors(class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRenderContext::SetAmbientLightColors(
        CStudioRenderContext *this@<ecx>,
        int a2@<edi>,
        const Vector *pColors)
{
  int v3; // esi

  *(Vector *)&this->m_RC.m_LightBoxColors[0].x = *pColors;
  this->m_RC.m_LightBoxColors[0].w = 1.0;
  this->m_RC.m_LightBoxColors[1].x = pColors[1].x;
  this->m_RC.m_LightBoxColors[1].y = pColors[1].y;
  this->m_RC.m_LightBoxColors[1].z = pColors[1].z;
  this->m_RC.m_LightBoxColors[1].w = 1.0;
  this->m_RC.m_LightBoxColors[2].x = pColors[2].x;
  this->m_RC.m_LightBoxColors[2].y = pColors[2].y;
  this->m_RC.m_LightBoxColors[2].z = pColors[2].z;
  this->m_RC.m_LightBoxColors[2].w = 1.0;
  this->m_RC.m_LightBoxColors[3].x = pColors[3].x;
  this->m_RC.m_LightBoxColors[3].y = pColors[3].y;
  this->m_RC.m_LightBoxColors[3].z = pColors[3].z;
  this->m_RC.m_LightBoxColors[3].w = 1.0;
  this->m_RC.m_LightBoxColors[4].x = pColors[4].x;
  this->m_RC.m_LightBoxColors[4].y = pColors[4].y;
  this->m_RC.m_LightBoxColors[4].z = pColors[4].z;
  this->m_RC.m_LightBoxColors[4].w = 1.0;
  this->m_RC.m_LightBoxColors[5].x = pColors[5].x;
  this->m_RC.m_LightBoxColors[5].y = pColors[5].y;
  this->m_RC.m_LightBoxColors[5].z = pColors[5].z;
  this->m_RC.m_LightBoxColors[5].w = 1.0;
  v3 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 64))(a1: v3);
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10053180
// Name: public: virtual void CStudioRenderContext::SetAmbientLightColors(class Vector4D const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::SetAmbientLightColors(CStudioRenderContext *this, const Vector4D *pColors)
{
  Vector4D *m_LightBoxColors; // ebx
  IMatRenderContext *v3; // esi

  m_LightBoxColors = this->m_RC.m_LightBoxColors;
  qmemcpy(this->m_RC.m_LightBoxColors, pColors, sizeof(this->m_RC.m_LightBoxColors));
  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v3->SetAmbientLightCube(this: v3, a2: m_LightBoxColors);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100531E0
// Name: public: virtual void CStudioRenderContext::SetLocalLights(int,struct LightDesc_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::SetLocalLights(
        CStudioRenderContext *this,
        int nLightCount,
        const LightDesc_t *pLights)
{
  IMatRenderContext *v4; // eax
  IMatRenderContext *v5; // esi
  IMatRenderContext_vtbl *v6; // edx

  this->m_RC.m_NumLocalLights = CopyLocalLightingState(
                                  nMaxLights: 4,
                                  pDest: this->m_RC.m_LocalLights,
                                  nLightCount,
                                  pSrc: pLights);
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v5 = v4;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v6 = v5->__vftable;
  if ( (*((_BYTE *)&this->m_RC.m_Config.StudioRenderConfig_t + 37) & 8) != 0 )
    v6->DisableAllLocalLights(this: v5);
  else
    v6->SetLights(this: v5, a2: this->m_RC.m_NumLocalLights, a3: this->m_RC.m_LocalLights);
  v5->EndRender(this: v5);
  v5->Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10053260
// Name: public: CMatRenderData<struct matrix3x4_t>::CMatRenderData<struct matrix3x4_t>(class IMatRenderContext __near *,int,struct matrix3x4_t const __near *)
// Source: json
//------------------------------------------------------------------------------
CMatRenderData<matrix3x4_t> *__thiscall CMatRenderData<matrix3x4_t>::CMatRenderData<matrix3x4_t>(
        CMatRenderData<matrix3x4_t> *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const matrix3x4_t *pSrcData)
{
  this->m_pRenderContext = pRenderContext;
  this->m_nCount = 0;
  this->m_pRenderData = nullptr;
  this->m_bNeedsUnlock = false;
  CMatRenderData<matrix3x4_t>::Lock(this, nCount, pSrcData);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10053290
// Name: public: CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct FlexWeights_t const __near &,int),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t __near *,struct FlexWeights_t,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct FlexWeights_t const __near &,int),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t __near *,struct FlexWeights_t,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct FlexWeights_t const __near &,int),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near * const __near &,struct FlexWeights_t const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, matrix3x4_t *, const FlexWeights_t *, int),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        matrix3x4_t **arg3,
        const FlexWeights_t *arg4,
        int *arg5)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  this->m_Proxy.m_pObject = pObject;
  this->m_Proxy.m_pfnProxied = pfnProxied;
  qmemcpy((void *)&this->m_arg1, arg1, sizeof(this->m_arg1));
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  this->m_arg5 = *arg5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10053310
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > *this)
{
  return ++this->m_iRefs;
}

//------------------------------------------------------------------------------
// Address: 0x10053320
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > *this)
{
  CRefCountServiceDestruct<CRefST> *v1; // ecx
  bool v2; // zf
  int result; // eax

  v1 = &this->CRefCountServiceDestruct<CRefST>;
  v2 = v1->m_iRefs-- == 1;
  result = v1->m_iRefs;
  if ( v2 )
  {
    ((void (__thiscall *)(CRefCountServiceDestruct<CRefST> *, _DWORD))v1->dtr_CRefCountServiceDestruct<CRefST>)(
      a1: v1,
      a2: 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10053340
// Name: public: virtual void CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct FlexWeights_t const __near &,int),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t __near *,struct FlexWeights_t,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: &this->m_arg1,
    a3: &this->m_arg2,
    a4: this->m_arg3,
    a5: &this->m_arg4,
    a6: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x10053370
// Name: public: CMemberFunctor6<class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int),struct StudioModelArrayInfo_t,struct StudioRenderContext_t,int,struct StudioArrayInstanceData_t __near *,unsigned int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor6<class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int),struct StudioModelArrayInfo_t,struct StudioRenderContext_t,int,struct StudioArrayInstanceData_t __near *,unsigned int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int),struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int const __near &,struct StudioArrayInstanceData_t __near * const __near &,unsigned int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const StudioModelArrayInfo_t *, const StudioRenderContext_t *, int, StudioArrayInstanceData_t *, int, int),
        const StudioModelArrayInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        int *arg3,
        StudioArrayInstanceData_t **arg4,
        unsigned int *arg5,
        int *arg6)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  this->m_Proxy.m_pfnProxied = pfnProxied;
  this->m_Proxy.m_pObject = pObject;
  this->m_arg1 = *arg1;
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  this->m_arg5 = *arg5;
  this->m_arg6 = *arg6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100533F0
// Name: public: virtual void CMemberFunctor6<class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int),struct StudioModelArrayInfo_t,struct StudioRenderContext_t,int,struct StudioArrayInstanceData_t __near *,unsigned int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: &this->m_arg1,
    a3: &this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5,
    a7: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x10053420
// Name: public: CMemberFunctor6<class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int),struct StudioModelArrayInfo_t,struct StudioRenderContext_t,int,struct StudioArrayInstanceData_t __near *,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor6<class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int),struct StudioModelArrayInfo_t,struct StudioRenderContext_t,int,struct StudioArrayInstanceData_t __near *,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int),struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int const __near &,struct StudioArrayInstanceData_t __near * const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const StudioModelArrayInfo_t *, const StudioRenderContext_t *, int, StudioArrayInstanceData_t *, int, int),
        const StudioModelArrayInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        int *arg3,
        StudioArrayInstanceData_t **arg4,
        int *arg5,
        int *arg6)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  this->m_Proxy.m_pfnProxied = pfnProxied;
  this->m_Proxy.m_pObject = pObject;
  this->m_arg1 = *arg1;
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  this->m_arg5 = *arg5;
  this->m_arg6 = *arg6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100534A0
// Name: public: virtual void CMemberFunctor6<class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo2_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayData_t __near *,int,int),struct StudioModelArrayInfo2_t,struct StudioRenderContext_t,int,struct StudioArrayData_t __near *,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo2_t const &,StudioRenderContext_t const &,int,StudioArrayData_t *,int,int),StudioModelArrayInfo2_t,StudioRenderContext_t,int,StudioArrayData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo2_t const &,StudioRenderContext_t const &,int,StudioArrayData_t *,int,int),StudioModelArrayInfo2_t,StudioRenderContext_t,int,StudioArrayData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: &this->m_arg1,
    a3: &this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5,
    a7: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x100534D0
// Name: public: virtual void CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct StudioRenderContext_t const __near &,int,struct StudioArrayData_t __near *,int,int),struct StudioRenderContext_t,int,struct StudioArrayData_t __near *,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(StudioRenderContext_t const &,int,StudioArrayData_t *,int,int),StudioRenderContext_t,int,StudioArrayData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(StudioRenderContext_t const &,int,StudioArrayData_t *,int,int),StudioRenderContext_t,int,StudioArrayData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: &this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x10053500
// Name: public: CMemberFunctor4<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor4<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, const matrix3x4_t *, int),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        const matrix3x4_t *arg3,
        int *arg4)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  this->m_Proxy.m_pObject = pObject;
  this->m_Proxy.m_pfnProxied = pfnProxied;
  qmemcpy((void *)&this->m_arg1, arg1, sizeof(this->m_arg1));
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100535B0
// Name: public: virtual void CMemberFunctor4<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: &this->m_arg1,
    a3: &this->m_arg2,
    a4: &this->m_arg3,
    a5: this->m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x100535E0
// Name: public: CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t,struct StudioRenderContext_t,int,struct MeshInstanceData_t __near *,class CUtlEnvelope<struct ColorMeshInfo_t __near *>,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t,struct StudioRenderContext_t,int,struct MeshInstanceData_t __near *,class CUtlEnvelope<struct ColorMeshInfo_t __near *>,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int const __near &,struct MeshInstanceData_t __near * const __near &,class CUtlEnvelope<struct ColorMeshInfo_t __near *> const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, int, const MeshInstanceData_t *, ColorMeshInfo_t **),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        int *arg3,
        MeshInstanceData_t **arg4,
        const CUtlEnvelope<ColorMeshInfo_t *> *arg5)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  this->m_Proxy.m_pObject = pObject;
  this->m_Proxy.m_pfnProxied = pfnProxied;
  qmemcpy((void *)&this->m_arg1, arg1, sizeof(this->m_arg1));
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  CUtlDataEnvelope::Assign(this: &this->m_arg5, from: &arg5->CUtlDataEnvelope);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10053670
// Name: public: CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t,struct StudioRenderContext_t,int,struct MeshInstanceData_t __near *,struct ColorMeshInfo_t __near * __near *,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t,struct StudioRenderContext_t,int,struct MeshInstanceData_t __near *,struct ColorMeshInfo_t __near * __near *,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int const __near &,struct MeshInstanceData_t __near * const __near &,struct ColorMeshInfo_t __near * __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, int, const MeshInstanceData_t *, ColorMeshInfo_t **),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        int *arg3,
        MeshInstanceData_t **arg4,
        ColorMeshInfo_t ***arg5)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  this->m_Proxy.m_pObject = pObject;
  this->m_Proxy.m_pfnProxied = pfnProxied;
  qmemcpy((void *)&this->m_arg1, arg1, sizeof(this->m_arg1));
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  this->m_arg5 = *arg5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100536F0
// Name: public: virtual void CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t,struct StudioRenderContext_t,int,struct MeshInstanceData_t __near *,struct ColorMeshInfo_t __near * __near *,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: &this->m_arg1,
    a3: &this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x10053720
// Name: public: virtual void CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(class IMaterial __near *,void __near *,struct FlashlightState_t __near *,class VMatrix __near *,class ITexture __near *),class IMaterial __near *,void __near *,struct FlashlightState_t __near *,class VMatrix __near *,class ITexture __near *,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *),IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *),IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x100537C0
// Name: public: virtual void CMemberFunctor2<class CStudioRender __near *,void (CStudioRender::*)(int,bool),int,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CStudioRender *,void (__thiscall CStudioRender::*)(int,bool),int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CStudioRender *,void (__thiscall CStudioRender::*)(int,bool),int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1, a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x100537E0
// Name: public: virtual void CMemberFunctor0<class CStudioRender __near *,void (CStudioRender::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CStudioRender *,void (__thiscall CStudioRender::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CStudioRender *,void (__thiscall CStudioRender::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100537F0
// Name: public: CMemberFunctor3<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::CMemberFunctor3<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, const matrix3x4_t *),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        const matrix3x4_t *arg3)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_Proxy.m_pObject = pObject;
  this->m_Proxy.m_pfnProxied = pfnProxied;
  qmemcpy((void *)&this->m_arg1, arg1, sizeof(this->m_arg1));
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10053890
// Name: public: virtual void CMemberFunctor3<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &),struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: &this->m_arg1, a3: &this->m_arg2, a4: &this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x100538B0
// Name: public: virtual void CMemberFunctor1<class CStudioRender __near *,void (CStudioRender::*)(struct StudioDecalHandle_t__ __near *),struct StudioDecalHandle_t__ __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *),StudioDecalHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *),StudioDecalHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100538C0
// Name: public: CMemberFunctor11<class CStudioRender __near *,void (CStudioRender::*)(struct StudioDecalHandle_t__ __near *,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct studiohdr_t __near *,struct Ray_t const __near &,class Vector const __near &,class IMaterial __near *,float,int,bool,int),struct StudioDecalHandle_t__ __near *,struct StudioRenderContext_t,struct matrix3x4_t __near *,struct studiohdr_t __near *,struct Ray_t,class Vector,class IMaterial __near *,float,int,bool,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::CMemberFunctor11<class CStudioRender __near *,void (CStudioRender::*)(struct StudioDecalHandle_t__ __near *,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct studiohdr_t __near *,struct Ray_t const __near &,class Vector const __near &,class IMaterial __near *,float,int,bool,int),struct StudioDecalHandle_t__ __near *,struct StudioRenderContext_t,struct matrix3x4_t __near *,struct studiohdr_t __near *,struct Ray_t,class Vector,class IMaterial __near *,float,int,bool,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(class CStudioRender __near *,void (CStudioRender::*)(struct StudioDecalHandle_t__ __near *,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct studiohdr_t __near *,struct Ray_t const __near &,class Vector const __near &,class IMaterial __near *,float,int,bool,int),struct StudioDecalHandle_t__ __near * const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near * const __near &,struct studiohdr_t __near * const __near &,struct Ray_t const __near &,class Vector const __near &,class IMaterial __near * const __near &,float const __near &,int const __near &,bool const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, StudioDecalHandle_t__ *, const StudioRenderContext_t *, matrix3x4_t *, studiohdr_t *, const Ray_t *, const Vector *, IMaterial *, float, int, bool, int),
        StudioDecalHandle_t__ **arg1,
        const StudioRenderContext_t *arg2,
        matrix3x4_t **arg3,
        studiohdr_t **arg4,
        const Ray_t *arg5,
        const Vector *arg6,
        IMaterial **arg7,
        float *arg8,
        int *arg9,
        bool *arg10,
        int *arg11)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_Proxy.m_pObject = pObject;
  this->m_Proxy.m_pfnProxied = pfnProxied;
  this->m_arg1 = *arg1;
  StudioRenderContext_t::StudioRenderContext_t(this: &this->m_arg2, __that: arg2);
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  qmemcpy((void *)&this->m_arg5, arg5, sizeof(this->m_arg5));
  this->m_arg6 = *arg6;
  this->m_arg7 = *arg7;
  this->m_arg8 = *arg8;
  this->m_arg9 = *arg9;
  this->m_arg10 = *arg10;
  this->m_arg11 = *arg11;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10053980
// Name: public: virtual void CMemberFunctor11<class CStudioRender __near *,void (CStudioRender::*)(struct StudioDecalHandle_t__ __near *,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct studiohdr_t __near *,struct Ray_t const __near &,class Vector const __near &,class IMaterial __near *,float,int,bool,int),struct StudioDecalHandle_t__ __near *,struct StudioRenderContext_t,struct matrix3x4_t __near *,struct studiohdr_t __near *,struct Ray_t,class Vector,class IMaterial __near *,float,int,bool,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(CStudioRender *, StudioDecalHandle_t__ *, StudioRenderContext_t *, matrix3x4_t *, studiohdr_t *, Ray_t *, Vector *, IMaterial *, _DWORD, int, bool, int))this->m_Proxy.m_pfnProxied)(
    a1: this->m_Proxy.m_pObject,
    a2: this->m_arg1,
    a3: &this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: &this->m_arg5,
    a7: &this->m_arg6,
    a8: this->m_arg7,
    a9: LODWORD(this->m_arg8),
    a10: this->m_arg9,
    a11: this->m_arg10,
    a12: this->m_arg11);
}

//------------------------------------------------------------------------------
// Address: 0x100539E0
// Name: public: virtual enum InitReturnVal_t CStudioRenderContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CStudioRenderContext::Init(CStudioRenderContext *this)
{
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  if ( g_pMaterialSystem != nullptr && g_pMaterialSystemHardwareConfig != nullptr )
    return CStudioRender::Init(this: g_pStudioRenderImp);
  else
    return INIT_FAILED;
}

//------------------------------------------------------------------------------
// Address: 0x10053A50
// Name: public: virtual void CStudioRenderContext::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::Shutdown(CStudioRenderContext *this)
{
  CStudioRender::Shutdown(this: g_pStudioRenderImp);
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10053A70
// Name: private: bool CStudioRenderContext::R_AddVertexToMesh<1>(char const __near *,bool,class CMeshBuilder __near &,struct OptimizedModel::Vertex_t __near *,struct mstudiomesh_t __near *,struct mstudio_meshvertexdata_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CStudioRenderContext::R_AddVertexToMesh<1>@<al>(
        CStudioRenderContext *this@<ecx>,
        int a2@<ebp>,
        const char *pModelName,
        bool bNeedsTangentSpace,
        CMeshBuilder *meshBuilder,
        OptimizedModel::Vertex_t *pVertex,
        mstudiomesh_t *pMesh,
        const mstudio_meshvertexdata_t *vertData,
        bool hwSkin)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  char *v10; // edx
  float *v11; // edi
  float *m_pCurrPosition; // ecx
  float v13; // xmm7_4
  float x; // xmm2_4
  float *v15; // eax
  const mstudio_meshvertexdata_t *v16; // ecx
  const mstudio_modelvertexdata_t *v17; // edx
  float v18; // xmm4_4
  int v19; // eax
  float z; // xmm3_4
  float v21; // xmm0_4
  __int128 v22; // xmm1
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float *m_pCurrNormal; // edi
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm6_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  int v36; // eax
  unsigned int v37; // edi
  OptimizedModel::Vertex_t *v38; // ecx
  int v39; // edx
  float v40; // xmm1_4
  float v41; // xmm1_4
  int v42; // edx
  unsigned __int8 v43; // al
  unsigned __int8 *v44; // eax
  _DWORD *v45; // ecx
  Vector v47; // [esp+1Ch] [ebp-4Ch] BYREF
  _BYTE vecTangentS[20]; // [esp+28h] [ebp-40h] OVERLAPPED
  float v49; // [esp+48h] [ebp-20h]
  int v50; // [esp+4Ch] [ebp-1Ch]
  unsigned __int8 v51; // [esp+50h] [ebp-18h]
  int origMeshVertID; // [esp+54h] [ebp-14h]
  unsigned __int8 numBones; // [esp+5Ah] [ebp-Eh]
  char v54; // [esp+5Bh] [ebp-Dh]
  int v55; // [esp+5Ch] [ebp-Ch]
  int idx; // [esp+60h] [ebp-8h]
  int retaddr; // [esp+68h] [ebp+0h]

  v55 = a2;
  idx = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  v10 = (char *)vertData[-1].modelvertexdata + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30;
  origMeshVertID = pVertex->origMeshVertID;
  v11 = (float *)((char *)modelvertexdata->pVertexData + 48 * (_DWORD)&v10[origMeshVertID]);
  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v54 = 1;
  *m_pCurrPosition = v11[4];
  m_pCurrPosition[1] = v11[5];
  m_pCurrPosition[2] = v11[6];
  CVertexBuilder::CompressedNormal3f<1>(this: &meshBuilder->m_VertexBuilder, nx: v11[7], ny: v11[8], nz: v11[9]);
  v13 = 0.0;
  x = 1.0;
  v15 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  v16 = vertData;
  *v15 = v11[10];
  v17 = vertData->modelvertexdata;
  v15[1] = v11[11];
  if ( v17->pTangentData != nullptr )
  {
    v18 = v11[8];
    v19 = (int)v17->pTangentData
        + 16 * ((int)vertData[-1].modelvertexdata + ((unsigned int)v17[-3].pTangentData >> 4) + origMeshVertID);
    v47.x = *(float *)v19;
    v47.y = *(float *)(v19 + 4);
    z = *(float *)(v19 + 8);
    v47.z = z;
    *(_DWORD *)vecTangentS = *(_DWORD *)(v19 + 12);
    v21 = v11[7];
    v22 = 0;
    *(float *)&v22 = fsqrt(
                       (float)((float)((float)((float)(v18 * z) - (float)(v11[9] * v47.y))
                                     * (float)((float)(v18 * z) - (float)(v11[9] * v47.y)))
                             + (float)((float)((float)(v11[9] * v47.x) - (float)(z * v21))
                                     * (float)((float)(v11[9] * v47.x) - (float)(z * v21))))
                     + (float)((float)((float)(v47.y * v21) - (float)(v18 * v47.x))
                             * (float)((float)(v47.y * v21) - (float)(v18 * v47.x))));
    *(_OWORD *)&vecTangentS[4] = v22;
    if ( *(float *)&v22 < 0.1 )
    {
      v23 = v11[9];
      if ( fabs(v21) <= 0.69999999 )
      {
        v28 = v21 * 0.0;
        v29 = (float)(v11[8] * 0.0) - (float)(v23 * 0.0);
        v26 = v23 - v28;
        v27 = v28 - v11[8];
        v47.x = v29;
      }
      else
      {
        v24 = v11[8] * 0.0;
        v25 = v24 - v23;
        v26 = (float)(v23 * 0.0) - (float)(v21 * 0.0);
        v27 = v21 - v24;
        v47.x = v25;
      }
      v47.z = v27;
      v47.y = v26;
      VectorNormalize(vec: &v47);
      z = v47.z;
      x = 1.0;
      v16 = vertData;
    }
    m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
    v31 = -1.0;
    v50 = *(_DWORD *)m_pCurrNormal;
    if ( v47.x >= 0.0 )
      v32 = 1.0;
    else
      v32 = -1.0;
    if ( v47.y >= 0.0 )
      v33 = 1.0;
    else
      v33 = -1.0;
    if ( z >= 0.0 )
      v31 = 1.0;
    v34 = 1.0 / (float)((float)((float)(v33 * v47.y) + (float)(v32 * v47.x)) + (float)(z * v31));
    v13 = 0.0;
    *(_DWORD *)m_pCurrNormal = v50
                             | (((unsigned __int8)(int)(float)((float)((float)((float)((float)((float)((float)((float)((float)(v32 * v47.x) * v34) * 63.0) * v32)
                                                                                             - (float)((float)(1.0 - v32) * 0.5))
                                                                                     + 64.0)
                                                                             * v31)
                                                                     - (float)((float)(1.0 - v31) * 0.5))
                                                             + 128.0)
                               | ((unsigned __int8)(int)(float)((float)((float)((float)((float)((float)((float)((float)((float)(v33 * v47.y) * v34) * 63.0) * v33)
                                                                                              - (float)((float)(1.0 - v33) * 0.5))
                                                                                      + 64.0)
                                                                              * *(float *)vecTangentS)
                                                                      - (float)((float)(1.0 - *(float *)vecTangentS)
                                                                              * 0.5))
                                                              + 128.0) << 8)) << 16);
  }
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  v35 = 0.0;
  if ( !hwSkin )
  {
    meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                  * meshBuilder->m_VertexBuilder.m_nCurrentVertex] = 0;
    meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                  * meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                  + 1] = 0;
    meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                  * meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                  + 2] = 0;
    v38 = pVertex;
    meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                  * meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                  + 3] = 0;
    goto LABEL_40;
  }
  v36 = 0;
  v37 = (unsigned int)v16->modelvertexdata->pVertexData
      + 48
      * ((int)vertData[-1].modelvertexdata + (unsigned int)v16->modelvertexdata[-3].pVertexData / 0x30 + origMeshVertID);
  v38 = pVertex;
  numBones = pVertex->numBones;
  v39 = numBones;
  origMeshVertID = numBones;
  if ( numBones >= 4u )
  {
    do
    {
      v40 = (float)((float)((float)(*(float *)(v37 + 4 * pVertex->boneWeightIndex[v36]) + v35)
                          + *(float *)(v37 + 4 * pVertex->boneWeightIndex[v36 + 1]))
                  + *(float *)(v37 + 4 * pVertex->boneWeightIndex[v36 + 2]))
          + *(float *)(v37 + 4 * pVertex->boneWeightIndex[v36 + 3]);
      v36 += 4;
      v35 = v40;
    }
    while ( v36 < origMeshVertID - 3 );
    v39 = origMeshVertID;
  }
  if ( v36 < v39 )
  {
    do
    {
      v41 = *(float *)(v37 + 4 * pVertex->boneWeightIndex[v36++]);
      v35 = v41 + v35;
    }
    while ( v36 < origMeshVertID );
  }
  if ( numBones != 0
    && *(_BYTE *)(v37 + 15) <= 3u
    && COERCE_FLOAT(COERCE_UNSIGNED_INT(v35 - 1.0) & _mask__AbsFloat_) > 0.001 )
  {
    v54 = 0;
  }
  else if ( v35 != 0.0 )
  {
    goto LABEL_28;
  }
  v35 = 1.0;
LABEL_28:
  v42 = 0;
  if ( origMeshVertID <= 0 )
    goto LABEL_36;
  do
  {
    v43 = v38->boneID[v42];
    if ( v43 == 0xFF )
    {
      v44 = &meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                           * meshBuilder->m_VertexBuilder.m_nCurrentVertex];
      *((_DWORD *)&v47.x + v42) = 0;
      v44[v42] = 0;
    }
    else
    {
      *(&v47.x + v42) = *(float *)(v37 + 4 * v38->boneWeightIndex[v42]) * (float)(1.0 / v35);
      if ( v43 == 255 )
        v43 = 0;
      meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                    * meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                    + v42] = v43;
      v38 = pVertex;
    }
    ++v42;
  }
  while ( v42 < v38->numBones );
  if ( v42 < 4 )
  {
LABEL_36:
    memset(&v47.x + v42, 0, 4 * (4 - v42));
    do
    {
      ++v42;
      meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                    * meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                    - 1
                                                    + v42] = 0;
    }
    while ( v42 < 4 );
    v38 = pVertex;
  }
  x = v47.x;
  v13 = v47.z;
LABEL_40:
  if ( v38->numBones != 0 )
  {
    v45 = (_DWORD *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                   + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                   * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight);
    v49 = x * 32768.0;
    origMeshVertID = v51 | 0xC00;
    v50 = (int)(float)(x * 32768.0);
    *v45 = (unsigned __int16)(v50 - 1);
    if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 1 )
    {
      v49 = v13 * 32768.0;
      v50 = v51 | 0xC00;
      origMeshVertID = (int)(float)(v13 * 32768.0);
      *v45 |= (0x7FFF - origMeshVertID - (int)(float)(x * 32768.0)) << 16;
    }
  }
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  return v54;
}

//------------------------------------------------------------------------------
// Address: 0x10054080
// Name: private: bool CStudioRenderContext::R_AddVertexToMesh<0>(char const __near *,bool,class CMeshBuilder __near &,struct OptimizedModel::Vertex_t __near *,struct mstudiomesh_t __near *,struct mstudio_meshvertexdata_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CStudioRenderContext::R_AddVertexToMesh<0>@<al>(
        CStudioRenderContext *this@<ecx>,
        int a2@<ebp>,
        const char *pModelName,
        bool bNeedsTangentSpace,
        CMeshBuilder *meshBuilder,
        OptimizedModel::Vertex_t *pVertex,
        mstudiomesh_t *pMesh,
        const mstudio_meshvertexdata_t *vertData,
        bool hwSkin)
{
  OptimizedModel::Vertex_t *v9; // ecx
  const mstudio_modelvertexdata_t *modelvertexdata; // esi
  float *v11; // eax
  double v12; // st7
  float *m_pCurrPosition; // edi
  int v14; // xmm0_4
  int v15; // xmm1_4
  CMeshBuilder *v16; // edi
  float *m_pCurrNormal; // edx
  float *v18; // edx
  float v19; // xmm4_4
  int v20; // edx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  __int64 *v30; // eax
  int v31; // eax
  float v32; // xmm0_4
  char *v33; // edi
  float v34; // xmm1_4
  float v35; // xmm1_4
  int v36; // edx
  CVertexBuilder *p_m_VertexBuilder; // esi
  unsigned __int8 v38; // al
  unsigned __int8 *v39; // eax
  int v40; // edx
  unsigned __int8 *m_pBoneMatrixIndex; // eax
  __int64 v43; // [esp-Ch] [ebp-24h] BYREF
  _BYTE v44[20]; // [esp-4h] [ebp-1Ch] OVERLAPPED
  int idx; // [esp+10h] [ebp-8h]
  int retaddr; // [esp+18h] [ebp+0h]

  *(_DWORD *)&v44[16] = a2;
  idx = retaddr;
  v9 = pVertex;
  modelvertexdata = vertData->modelvertexdata;
  v11 = (float *)((char *)vertData->modelvertexdata->pVertexData
                + 48
                * ((int)vertData[-1].modelvertexdata
                 + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30
                 + pVertex->origMeshVertID));
  *(_DWORD *)&v44[8] = pVertex->origMeshVertID;
  v12 = v11[4];
  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v44[15] = 1;
  *m_pCurrPosition = v12;
  m_pCurrPosition[1] = v11[5];
  m_pCurrPosition[2] = v11[6];
  v14 = *((_DWORD *)v11 + 8);
  v15 = *((_DWORD *)v11 + 9);
  v16 = meshBuilder;
  m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
  *m_pCurrNormal = v11[7];
  *((_DWORD *)m_pCurrNormal + 1) = v14;
  *((_DWORD *)m_pCurrNormal + 2) = v15;
  v18 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  *v18 = v11[10];
  v18[1] = v11[11];
  if ( modelvertexdata->pTangentData != nullptr )
  {
    v19 = v11[8];
    v20 = (int)modelvertexdata->pTangentData
        + 16
        * ((int)vertData[-1].modelvertexdata + ((unsigned int)modelvertexdata[-3].pTangentData >> 4)
                                             + *(_DWORD *)&v44[8]);
    v43 = *(_QWORD *)v20;
    *(_DWORD *)v44 = *(_DWORD *)(v20 + 8);
    *(_DWORD *)&v44[4] = *(_DWORD *)(v20 + 12);
    v21 = v11[7];
    v22 = (float)(v19 * *(float *)v44) - (float)(v11[9] * *((float *)&v43 + 1));
    if ( fsqrt(
           (float)((float)(v22 * v22)
                 + (float)((float)((float)(v11[9] * *(float *)&v43) - (float)(v21 * *(float *)v44))
                         * (float)((float)(v11[9] * *(float *)&v43) - (float)(v21 * *(float *)v44))))
         + (float)((float)((float)(v21 * *((float *)&v43 + 1)) - (float)(v19 * *(float *)&v43))
                 * (float)((float)(v21 * *((float *)&v43 + 1)) - (float)(v19 * *(float *)&v43)))) < 0.1 )
    {
      v23 = v11[9];
      v24 = v11[8] * 0.0;
      if ( fabs(v21) <= 0.69999999 )
      {
        v28 = v21 * 0.0;
        v29 = v24 - (float)(v23 * 0.0);
        v26 = v23 - v28;
        v27 = v28 - v11[8];
        *(float *)&v43 = v29;
      }
      else
      {
        v25 = v24 - v23;
        v26 = (float)(v23 * 0.0) - (float)(v21 * 0.0);
        v27 = v21 - v24;
        *(float *)&v43 = v25;
      }
      *(float *)v44 = v27;
      *((float *)&v43 + 1) = v26;
      VectorNormalize(vec: (Vector *)&v43);
      v9 = pVertex;
    }
    v30 = (__int64 *)((char *)meshBuilder->m_VertexBuilder.m_pUserData
                    + meshBuilder->m_VertexBuilder.m_nCurrentVertex * meshBuilder->m_VertexBuilder.m_VertexSize_UserData);
    v16 = meshBuilder;
    *v30 = v43;
    v30[1] = *(_QWORD *)v44;
  }
  *(_DWORD *)v16->m_VertexBuilder.m_pCurrColor = -1;
  if ( !hwSkin )
  {
    p_m_VertexBuilder = &v16->m_VertexBuilder;
    v16->m_VertexBuilder.m_pBoneMatrixIndex[v16->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                          * v16->m_VertexBuilder.m_nCurrentVertex] = 0;
    v16->m_VertexBuilder.m_pBoneMatrixIndex[v16->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                          * v16->m_VertexBuilder.m_nCurrentVertex
                                          + 1] = 0;
    v16->m_VertexBuilder.m_pBoneMatrixIndex[v16->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                          * v16->m_VertexBuilder.m_nCurrentVertex
                                          + 2] = 0;
    v40 = v16->m_VertexBuilder.m_VertexSize_BoneMatrixIndex * v16->m_VertexBuilder.m_nCurrentVertex;
    m_pBoneMatrixIndex = v16->m_VertexBuilder.m_pBoneMatrixIndex;
    v43 = 1065353216;
    m_pBoneMatrixIndex[v40 + 3] = 0;
    goto LABEL_32;
  }
  v31 = 0;
  v32 = 0.0;
  v33 = (char *)vertData->modelvertexdata->pVertexData
      + 48
      * ((int)vertData[-1].modelvertexdata
       + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30
       + *(_DWORD *)&v44[8]);
  v44[14] = v9->numBones;
  if ( v44[14] >= 4u )
  {
    do
    {
      v34 = (float)((float)((float)(*(float *)&v33[4 * v9->boneWeightIndex[v31]] + v32)
                          + *(float *)&v33[4 * v9->boneWeightIndex[v31 + 1]])
                  + *(float *)&v33[4 * v9->boneWeightIndex[v31 + 2]])
          + *(float *)&v33[4 * v9->boneWeightIndex[v31 + 3]];
      v31 += 4;
      v32 = v34;
    }
    while ( v31 < v44[14] - 3 );
  }
  for ( ; v31 < v44[14]; v32 = v35 + v32 )
    v35 = *(float *)&v33[4 * v9->boneWeightIndex[v31++]];
  if ( v44[14] != 0
    && (unsigned __int8)v33[15] <= 3u
    && COERCE_FLOAT(COERCE_UNSIGNED_INT(v32 - 1.0) & _mask__AbsFloat_) > 0.001 )
  {
    v44[15] = 0;
LABEL_18:
    v32 = 1.0;
    goto LABEL_19;
  }
  if ( v32 == 0.0 )
    goto LABEL_18;
LABEL_19:
  v36 = 0;
  if ( v44[14] == 0 )
    goto LABEL_28;
  p_m_VertexBuilder = &meshBuilder->m_VertexBuilder;
  do
  {
    v38 = v9->boneID[v36];
    if ( v38 == 0xFF )
    {
      v39 = &meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                           * meshBuilder->m_VertexBuilder.m_nCurrentVertex];
      *(_DWORD *)&v44[4 * v36 - 8] = 0;
      v39[v36] = 0;
    }
    else
    {
      *(float *)&v44[4 * v36 - 8] = *(float *)&v33[4 * v9->boneWeightIndex[v36]] * (float)(1.0 / v32);
      if ( v38 == 255 )
        v38 = 0;
      meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                    * meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                    + v36] = v38;
      v9 = pVertex;
    }
    ++v36;
  }
  while ( v36 < v9->numBones );
  if ( v36 < 4 )
  {
LABEL_28:
    p_m_VertexBuilder = &meshBuilder->m_VertexBuilder;
    memset(&v44[4 * v36 - 8], 0, 4 * (4 - v36));
    do
    {
      ++v36;
      meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                    * meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                    - 1
                                                    + v36] = 0;
    }
    while ( v36 < 4 );
    v9 = pVertex;
  }
LABEL_32:
  if ( v9->numBones != 0 )
    *(_QWORD *)((char *)p_m_VertexBuilder->m_pBoneWeight
              + p_m_VertexBuilder->m_nCurrentVertex * p_m_VertexBuilder->m_VertexSize_BoneWeight) = v43;
  CVertexBuilder::AdvanceVertex(this: p_m_VertexBuilder);
  return v44[15];
}

//------------------------------------------------------------------------------
// Address: 0x100544C0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CRenderDataFunctorAllocator,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CStudioRender __near *,class CStudioRender,void,struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct FlexWeights_t const __near &,int,struct DrawModelInfo_t,struct StudioRenderContext_t,struct matrix3x4_t __near *,struct FlexWeights_t,int>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct FlexWeights_t const __near &,int),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near * const __near &,struct FlexWeights_t const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int,DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int>(
        CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, matrix3x4_t *, const FlexWeights_t *, int),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        matrix3x4_t **arg3,
        const FlexWeights_t *arg4,
        int *arg5)
{
  CRenderDataFunctorAllocator *m_pAllocator; // edi
  CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v9; // esi

  m_pAllocator = this->m_pAllocator;
  v9 = (CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this->m_pAllocator->m_pRenderContext->LockRenderData(this: this->m_pAllocator->m_pRenderContext, a2: 1116);
  m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v9);
  if ( v9 != nullptr )
    return CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
             this: v9,
             pObject,
             pfnProxied,
             arg1,
             arg2,
             arg3,
             arg4,
             arg5);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10054520
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CRenderDataFunctorAllocator,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CStudioRender __near *,class CStudioRender,void,struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int,struct StudioModelArrayInfo_t,struct StudioRenderContext_t,int,struct StudioArrayInstanceData_t __near *,int,int>(class CStudioRender __near *,void (CStudioRender::*)(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int),struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int const __near &,struct StudioArrayInstanceData_t __near * const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int,StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int>(
        CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const StudioModelArrayInfo_t *, const StudioRenderContext_t *, int, StudioArrayInstanceData_t *, int, int),
        const StudioModelArrayInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        int *arg3,
        StudioArrayInstanceData_t **arg4,
        int *arg5,
        int *arg6)
{
  CRenderDataFunctorAllocator *m_pAllocator; // edi
  CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // esi

  m_pAllocator = this->m_pAllocator;
  v10 = (CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this->m_pAllocator->m_pRenderContext->LockRenderData(this: this->m_pAllocator->m_pRenderContext, a2: 652);
  m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v10);
  if ( v10 != nullptr )
    return CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
             this: v10,
             pObject,
             pfnProxied,
             arg1,
             arg2,
             arg3,
             arg4,
             arg5,
             arg6);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10054580
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CRenderDataFunctorAllocator,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CStudioRender __near *,class CStudioRender,void,struct StudioRenderContext_t const __near &,int,struct StudioArrayData_t __near *,int,int,struct StudioRenderContext_t,int,struct StudioArrayData_t __near *,int,int>(class CStudioRender __near *,void (CStudioRender::*)(struct StudioRenderContext_t const __near &,int,struct StudioArrayData_t __near *,int,int),struct StudioRenderContext_t const __near &,int const __near &,struct StudioArrayData_t __near * const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,StudioRenderContext_t const &,int,StudioArrayData_t *,int,int,StudioRenderContext_t,int,StudioArrayData_t *,int,int>(
        CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const StudioRenderContext_t *, int, StudioArrayData_t *, int, int),
        const StudioRenderContext_t *arg1,
        const int *arg2,
        StudioArrayData_t *const *arg3,
        const int *arg4,
        const int *arg5)
{
  CRenderDataFunctorAllocator *m_pAllocator; // edi
  char *v9; // esi

  m_pAllocator = this->m_pAllocator;
  v9 = (char *)this->m_pAllocator->m_pRenderContext->LockRenderData(this: this->m_pAllocator->m_pRenderContext, a2: 636);
  m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v9);
  if ( v9 == nullptr )
    return nullptr;
  *((_DWORD *)v9 + 3) = 1;
  *(_DWORD *)v9 = &CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(StudioRenderContext_t const &,int,StudioArrayData_t *,int,int),StudioRenderContext_t,int,StudioArrayData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)v9 + 2) = &CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(StudioRenderContext_t const &,int,StudioArrayData_t *,int,int),StudioRenderContext_t,int,StudioArrayData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_DWORD *)v9 + 5) = pObject;
  *((_DWORD *)v9 + 4) = pfnProxied;
  StudioRenderContext_t::StudioRenderContext_t(this: (StudioRenderContext_t *)(v9 + 24), __that: arg1);
  *((_DWORD *)v9 + 155) = *arg2;
  *((StudioArrayData_t **)v9 + 156) = *arg3;
  *((_DWORD *)v9 + 157) = *arg4;
  *((_DWORD *)v9 + 158) = *arg5;
  return (CFunctor *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x10054620
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CRenderDataFunctorAllocator,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CStudioRender __near *,class CStudioRender,void,struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *,struct DrawModelInfo_t,struct StudioRenderContext_t,int,struct MeshInstanceData_t __near *,class CUtlEnvelope<struct ColorMeshInfo_t __near *>>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int const __near &,struct MeshInstanceData_t __near * const __near &,class CUtlEnvelope<struct ColorMeshInfo_t __near *> const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *,DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>>(
        CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, int, const MeshInstanceData_t *, ColorMeshInfo_t **),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        int *arg3,
        MeshInstanceData_t **arg4,
        const CUtlEnvelope<ColorMeshInfo_t *> *arg5)
{
  CRenderDataFunctorAllocator *m_pAllocator; // edi
  CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v9; // esi

  m_pAllocator = this->m_pAllocator;
  v9 = (CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this->m_pAllocator->m_pRenderContext->LockRenderData(this: this->m_pAllocator->m_pRenderContext, a2: 1116);
  m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v9);
  if ( v9 != nullptr )
    return CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
             this: v9,
             pObject,
             pfnProxied,
             arg1,
             arg2,
             arg3,
             arg4,
             arg5);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10054680
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CRenderDataFunctorAllocator,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CStudioRender __near *,class CStudioRender,void,struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *,struct DrawModelInfo_t,struct StudioRenderContext_t,int,struct MeshInstanceData_t __near *,struct ColorMeshInfo_t __near * __near *>(class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int const __near &,struct MeshInstanceData_t __near * const __near &,struct ColorMeshInfo_t __near * __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *,DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *>(
        CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, const DrawModelInfo_t *, const StudioRenderContext_t *, int, const MeshInstanceData_t *, ColorMeshInfo_t **),
        const DrawModelInfo_t *arg1,
        const StudioRenderContext_t *arg2,
        int *arg3,
        MeshInstanceData_t **arg4,
        ColorMeshInfo_t ***arg5)
{
  CRenderDataFunctorAllocator *m_pAllocator; // edi
  CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v9; // esi

  m_pAllocator = this->m_pAllocator;
  v9 = (CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this->m_pAllocator->m_pRenderContext->LockRenderData(this: this->m_pAllocator->m_pRenderContext, a2: 1112);
  m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v9);
  if ( v9 != nullptr )
    return CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
             this: v9,
             pObject,
             pfnProxied,
             arg1,
             arg2,
             arg3,
             arg4,
             arg5);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100546E0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CRenderDataFunctorAllocator,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CStudioRender __near *,class CStudioRender,void,class IMaterial __near *,void __near *,struct FlashlightState_t __near *,class VMatrix __near *,class ITexture __near *,class IMaterial __near *,void __near *,struct FlashlightState_t __near *,class VMatrix __near *,class ITexture __near *>(class CStudioRender __near *,void (CStudioRender::*)(class IMaterial __near *,void __near *,struct FlashlightState_t __near *,class VMatrix __near *,class ITexture __near *),class IMaterial __near * const __near &,void __near * const __near &,struct FlashlightState_t __near * const __near &,class VMatrix __near * const __near &,class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *,IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *>(
        CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, IMaterial *, void *, FlashlightState_t *, VMatrix *, ITexture *),
        IMaterial *const *arg1,
        void *const *arg2,
        FlashlightState_t *const *arg3,
        VMatrix *const *arg4,
        ITexture *const *arg5)
{
  CRenderDataFunctorAllocator *m_pAllocator; // edi
  _DWORD *v9; // esi

  m_pAllocator = this->m_pAllocator;
  v9 = this->m_pAllocator->m_pRenderContext->LockRenderData(this: this->m_pAllocator->m_pRenderContext, a2: 44);
  m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v9);
  if ( v9 == nullptr )
    return nullptr;
  v9[3] = 1;
  *v9 = &CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *),IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  v9[2] = &CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *),IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  v9[4] = pfnProxied;
  v9[5] = pObject;
  v9[6] = *arg1;
  v9[7] = *arg2;
  v9[8] = *arg3;
  v9[9] = *arg4;
  v9[10] = *arg5;
  return (CFunctor *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x10054760
// Name: public: virtual void CMemberFunctor5<class CStudioRender __near *,void (CStudioRender::*)(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *),struct DrawModelInfo_t,struct StudioRenderContext_t,int,struct MeshInstanceData_t __near *,class CUtlEnvelope<struct ColorMeshInfo_t __near *>,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  int m_nBytes; // edx
  ColorMeshInfo_t **p_m_arg5; // ecx

  m_nBytes = this->m_arg5.m_nBytes;
  p_m_arg5 = (ColorMeshInfo_t **)&this->m_arg5;
  if ( m_nBytes != 0 )
  {
    if ( m_nBytes > 4 )
      p_m_arg5 = (ColorMeshInfo_t **)*p_m_arg5;
  }
  else
  {
    p_m_arg5 = nullptr;
  }
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: &this->m_arg1,
    a3: &this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: p_m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x100547A0
// Name: public: virtual bool CStudioRenderContext::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStudioRenderContext::Connect(
        CStudioRenderContext *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // esi
  IStudioDataCache *v3; // eax
  void *(__cdecl *v5)(const char *, int *); // [esp+4h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  v2 = factory;
  v5 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  _heap_term(pFactoryList: &v5, nFactoryCount: 1);
  v3 = (IStudioDataCache *)v2(a1: "VStudioDataCache005", a2: nullptr);
  g_pStudioDataCache = v3;
  if ( g_pMaterialSystem == nullptr || g_pMaterialSystemHardwareConfig == nullptr || v3 == nullptr )
  {
    _Msg(a1: "StudioRender failed to connect to a required system\n");
    v3 = g_pStudioDataCache;
  }
  g_StudioRenderFunctorFactory.m_pAllocator = &g_RenderDataAllocator;
  return g_pMaterialSystem != nullptr && g_pMaterialSystemHardwareConfig != nullptr && v3 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10054850
// Name: public: virtual void CStudioRenderContext::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10054870
// Name: private: void CStudioRenderContext::R_StudioBuildMeshGroup(char const __near *,bool,struct studioloddata_t __near *,struct studiomeshgroup_t __near *,struct OptimizedModel::StripGroupHeader_t __near *,struct mstudiomesh_t __near *,struct studiohdr_t __near *,unsigned __int64,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::R_StudioBuildMeshGroup(
        CStudioRenderContext *this,
        const char *pModelName,
        bool bNeedsTangentSpace,
        studioloddata_t *pStudioLodData,
        studiomeshgroup_t *pMeshGroup,
        OptimizedModel::StripGroupHeader_t *pStripGroup,
        mstudiomesh_t *pMesh,
        studiohdr_t *pStudioHdr,
        unsigned __int64 vertexFormat,
        VertexStreamSpec_t *pStreamSpec)
{
  IMatRenderContext *v10; // edi
  IMesh *v11; // eax
  studiomeshgroup_t *v12; // edi
  VertexCompressionType_t v13; // esi
  unsigned int v14; // ebx
  char v15; // bl
  int numVerts; // eax
  const mstudio_meshvertexdata_t *FatVertexData; // ecx
  int v19; // edi
  int vertOffset; // eax
  char v21; // al
  int v22; // ebx
  int v23; // edx
  signed int m_nCurrentIndex; // eax
  __int16 v25; // cx
  int m_nVertexCount; // eax
  int v27; // eax
  int v28; // ecx
  unsigned __int8 *v29; // eax
  int numTopologyIndices; // eax
  unsigned __int8 *v31; // eax
  int j; // ecx
  int stripOffset; // edx
  char *v34; // eax
  unsigned int v35; // edx
  int v36; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F4h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-Ch]
  BOOL hwSkin; // [esp+1F4h] [ebp-8h]
  CStudioRenderContext *v41; // [esp+1F8h] [ebp-4h]
  int savedregs; // [esp+1FCh] [ebp+0h] BYREF
  bool bSubDQuads_3; // [esp+213h] [ebp+17h]
  int i; // [esp+214h] [ebp+18h]
  const mstudio_meshvertexdata_t *vertData; // [esp+21Ch] [ebp+20h]
  int v46; // [esp+224h] [ebp+28h]
  char bBadBoneWeights_3; // [esp+22Bh] [ebp+2Fh]

  v41 = this;
  v10 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, const char *, _DWORD, VertexStreamSpec_t *))v10->CreateStaticMesh)(
                   a1: v10,
                   a2: vertexFormat,
                   a3: HIDWORD(vertexFormat),
                   a4: "Model Verts",
                   a5: 0,
                   a6: pStreamSpec);
  v12 = pMeshGroup;
  pMeshGroup->m_pMesh = v11;
  if ( (vertexFormat & 0x400) != 0 )
  {
    v13 = VERTEX_COMPRESSION_ON;
    v46 = 1;
  }
  else
  {
    v46 = 0;
    v13 = VERTEX_COMPRESSION_NONE;
  }
  v14 = (unsigned int)pMeshGroup->m_Flags >> 1;
  pMeshGroup->m_ColorMeshID = -1;
  v15 = v14 & 1;
  LOBYTE(hwSkin) = v15;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_CompressionType = v13;
  meshBuilder.m_VertexBuilder.m_CompressionType = v13;
  if ( v15 != 0 )
    numVerts = pStripGroup->numVerts;
  else
    numVerts = 0;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: pMeshGroup->m_pMesh,
    type: MATERIAL_HETEROGENOUS,
    nVertexCount: numVerts,
    nIndexCount: pStripGroup->numIndices,
    pMeshSettings: nullptr);
  bBadBoneWeights_3 = 0;
  if ( v15 != 0 )
  {
    FatVertexData = GetFatVertexData(pMesh, pStudioHdr);
    vertData = FatVertexData;
    i = 0;
    if ( pStripGroup->numVerts > 0 )
    {
      v19 = 0;
      while ( 1 )
      {
        vertOffset = pStripGroup->vertOffset;
        if ( v46 == 1 )
          v21 = CStudioRenderContext::R_AddVertexToMesh<1>(
                  this: v41,
                  a2: (int)&savedregs,
                  pModelName,
                  bNeedsTangentSpace,
                  &meshBuilder,
                  pVertex: (OptimizedModel::Vertex_t *)((char *)pStripGroup + v19 + vertOffset),
                  pMesh,
                  vertData: FatVertexData,
                  hwSkin);
        else
          v21 = CStudioRenderContext::R_AddVertexToMesh<0>(
                  this: v41,
                  a2: (int)&savedregs,
                  pModelName,
                  bNeedsTangentSpace,
                  &meshBuilder,
                  pVertex: (OptimizedModel::Vertex_t *)((char *)pStripGroup + v19 + vertOffset),
                  pMesh,
                  vertData: FatVertexData,
                  hwSkin);
        if ( v21 == 0 )
          bBadBoneWeights_3 = 1;
        v19 += 9;
        if ( ++i >= pStripGroup->numVerts )
          break;
        FatVertexData = vertData;
      }
      if ( bBadBoneWeights_3 != 0 )
        ConMsg(a1: "Bad data found in model \"%s\" (bad bone weights)\n", (const char *)pMesh + pMesh->modelindex);
      v12 = pMeshGroup;
    }
  }
  bSubDQuads_3 = (*((_BYTE *)&pStripGroup->numStrips + pStripGroup->stripOffset + 2) & 6) != 0;
  v22 = 0;
  v23 = 0;
  if ( pStripGroup->numIndices > 0 )
  {
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      if ( bSubDQuads_3 )
        v25 = v23;
      else
        v25 = *(_WORD *)((char *)&pStripGroup->numVerts + 2 * v23 + pStripGroup->indexOffset);
      meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v25 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
      if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
        meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v23;
    }
    while ( v23 < pStripGroup->numIndices );
    v22 = 0;
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  v27 = 2 * pStripGroup->numIndices;
  v28 = (unsigned int)pStripGroup->numIndices >> 31 != 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v29 = (unsigned __int8 *)operator new(nSize: v27 | -v28);
  v12->m_pIndices = (unsigned __int16 *)v29;
  memcpy(dst: v29, src: (unsigned __int8 *)pStripGroup + pStripGroup->indexOffset, count: 2 * pStripGroup->numIndices);
  v12->m_pTopologyIndices = nullptr;
  numTopologyIndices = pStripGroup->numTopologyIndices;
  if ( numTopologyIndices > 0 )
  {
    v31 = (unsigned __int8 *)operator new(nSize: 2 * numTopologyIndices);
    v12->m_pTopologyIndices = (unsigned __int16 *)v31;
    memcpy(
      dst: v31,
      src: (unsigned __int8 *)pStripGroup + pStripGroup->topologyOffset,
      count: 2 * pStripGroup->numTopologyIndices);
  }
  v12->m_pUniqueFaces = (int *)operator new(nSize: 4 * pStripGroup->numStrips);
  for ( j = 0; j < pStripGroup->numStrips; v22 += 35 )
  {
    stripOffset = pStripGroup->stripOffset;
    v34 = (char *)pStripGroup + v22;
    if ( (*((_BYTE *)&pStripGroup->numStrips + v22 + stripOffset + 2) & 6) != 0 )
    {
      v36 = *(_DWORD *)&v34[stripOffset] / 4;
    }
    else
    {
      v35 = (unsigned __int64)(1431655766LL * *(int *)&v34[stripOffset]) >> 32;
      v36 = v35 + (v35 >> 31);
    }
    v12->m_pUniqueFaces[j] = v36;
    pStudioLodData->m_NumFaces += v12->m_pUniqueFaces[j++];
  }
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10054C50
// Name: private: void CStudioRenderContext::R_StudioCreateSingleMesh(struct studiohdr_t __near *,struct studioloddata_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::MeshHeader_t __near *,int,struct studiomeshdata_t __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::R_StudioCreateSingleMesh(
        CStudioRenderContext *this,
        studiohdr_t *pStudioHdr,
        studioloddata_t *pStudioLodData,
        mstudiomesh_t *pMesh,
        OptimizedModel::MeshHeader_t *pVtxMesh,
        int numBones,
        studiomeshdata_t *pMeshData,
        int *pColorMeshID)
{
  OptimizedModel::MeshHeader_t *v9; // eax
  studiomeshgroup_t *v10; // edi
  OptimizedModel::StripGroupHeader_t *v11; // esi
  unsigned __int64 v12; // rax
  const char *v13; // eax
  int v14; // eax
  unsigned __int16 v15; // cx
  int numVerts; // eax
  int j; // ecx
  unsigned __int64 v18; // [esp-10h] [ebp-30h]
  char bNeedsTangentSpace; // [esp+8h] [ebp-18h]
  bool bIsHwSkinned; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+18h] [ebp-8h]
  int v24; // [esp+1Ch] [ebp-4h]

  bNeedsTangentSpace = CStudioRenderContext::MeshNeedsTangentSpace(this, pStudioHdr, pStudioLodData, pMesh);
  pMeshData->m_NumGroup = pVtxMesh->numStripGroups;
  pMeshData->m_pMeshGroup = (studiomeshgroup_t *)operator new(nSize: 44 * pVtxMesh->numStripGroups);
  v9 = pVtxMesh;
  i = 0;
  if ( pVtxMesh->numStripGroups > 0 )
  {
    v22 = 0;
    v23 = 0;
    while ( 1 )
    {
      v10 = &pMeshData->m_pMeshGroup[v22];
      v11 = (OptimizedModel::StripGroupHeader_t *)((char *)v9 + v23 + v9->stripGroupHeaderOffset);
      v10->m_MeshNeedsRestore = false;
      v10->m_Flags = 0;
      if ( (v11->flags & 4) != 0 )
        v10->m_Flags = 4;
      bIsHwSkinned = (v11->flags & 2) != 0;
      if ( (v11->flags & 2) != 0 )
        v10->m_Flags |= 2u;
      LODWORD(v12) = CStudioRenderContext::CalculateVertexFormat(
                       this,
                       pStudioHdr,
                       pStudioLodData,
                       pMesh,
                       pGroup: v11,
                       bIsHwSkinned);
      v18 = v12;
      v13 = studiohdr_t::pszName(this: pStudioHdr);
      CStudioRenderContext::R_StudioBuildMeshGroup(
        this,
        pModelName: v13,
        bNeedsTangentSpace,
        pStudioLodData,
        pMeshGroup: v10,
        pStripGroup: v11,
        pMesh,
        pStudioHdr,
        vertexFormat: v18,
        pStreamSpec: nullptr);
      CStudioRenderContext::R_StudioBuildMeshStrips(this, pMeshGroup: v10, pStripGroup: v11);
      CStudioRenderContext::R_StudioBuildMorph(this, pStudioHdr, pMeshGroup: v10, pMesh, pStripGroup: v11);
      v10->m_pGroupIndexToMeshIndex = (unsigned __int16 *)operator new(nSize: 2 * (v11->numVerts + 4));
      v10->m_NumVertices = v11->numVerts;
      v14 = 0;
      if ( v11->numVerts > 0 )
      {
        v24 = 0;
        do
        {
          v15 = *(_WORD *)((char *)&v11->vertOffset + v24 + v11->vertOffset);
          v24 += 9;
          v10->m_pGroupIndexToMeshIndex[v14++] = v15;
        }
        while ( v14 < v11->numVerts );
      }
      numVerts = v11->numVerts;
      for ( j = v11->numVerts; j < v11->numVerts + 4; ++j )
      {
        v10->m_pGroupIndexToMeshIndex[j] = v10->m_pGroupIndexToMeshIndex[numVerts - 1];
        numVerts = v11->numVerts;
      }
      v23 += 33;
      ++v22;
      v10->m_ColorMeshID = *(_WORD *)pColorMeshID;
      ++*pColorMeshID;
      if ( ++i >= pVtxMesh->numStripGroups )
        break;
      v9 = pVtxMesh;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054DF0
// Name: private: void CStudioRenderContext::R_StudioCreateStaticMeshes(struct studiohdr_t __near *,struct OptimizedModel::FileHeader_t __near *,struct studiohwdata_t __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::R_StudioCreateStaticMeshes(
        CStudioRenderContext *this,
        studiohdr_t *pStudioHdr,
        OptimizedModel::FileHeader_t *pVtxHdr,
        studiohwdata_t *pStudioHWData,
        int nLodID,
        int *pColorMeshID)
{
  int v6; // edi
  studiohdr_t *v7; // eax
  int v8; // edx
  OptimizedModel::BodyPartHeader_t *v9; // ecx
  mstudiobodyparts_t *v10; // ebx
  int v11; // edx
  int v12; // eax
  OptimizedModel::ModelLODHeader_t *v13; // edi
  mstudiomodel_t *v14; // esi
  IVBAllocTracker *v15; // ecx
  void (__thiscall *TrackMeshAllocations)(IVBAllocTracker *, const char *); // eax
  mstudiobodyparts_t *pBodyPart; // [esp+8h] [ebp-30h]
  OptimizedModel::BodyPartHeader_t *pVtxBodyPart; // [esp+10h] [ebp-28h]
  int v19; // [esp+14h] [ebp-24h]
  int i; // [esp+18h] [ebp-20h]
  int v21; // [esp+1Ch] [ebp-1Ch]
  int k; // [esp+20h] [ebp-18h]
  int v24; // [esp+28h] [ebp-10h]
  int v25; // [esp+2Ch] [ebp-Ch]
  int j; // [esp+30h] [ebp-8h]
  int v27; // [esp+34h] [ebp-4h]

  v6 = nLodID;
  pStudioHWData->m_pLODs[nLodID].m_pMeshData = (studiomeshdata_t *)operator new(nSize: 8 * pStudioHWData->m_NumStudioMeshes);
  v7 = pStudioHdr;
  v8 = 0;
  i = 0;
  if ( pStudioHdr->numbodyparts > 0 )
  {
    v24 = 0;
    do
    {
      v9 = (OptimizedModel::BodyPartHeader_t *)((char *)pVtxHdr + 8 * v8 + pVtxHdr->bodyPartOffset);
      v10 = (mstudiobodyparts_t *)((char *)v7 + v24 + v7->bodypartindex);
      pBodyPart = v10;
      pVtxBodyPart = v9;
      j = 0;
      if ( v10->nummodels > 0 )
      {
        v11 = 12 * v6;
        v19 = 12 * v6;
        v25 = 0;
        while ( 1 )
        {
          v12 = (int)&v9[j] + v9->modelOffset;
          v13 = (OptimizedModel::ModelLODHeader_t *)(v12 + v11 + *(_DWORD *)(v12 + 4));
          v14 = (mstudiomodel_t *)((char *)v10 + v25 + v10->modelindex);
          CStudioRenderContext::DetermineHWMorphing(this, pModel: v14, pVtxLOD: v13);
          v15 = g_VBAllocTracker;
          if ( g_VBAllocTracker != nullptr )
          {
            if ( pStudioHdr->numbones > 8 || pStudioHdr->numflexdesc > 0 )
            {
              ((void (__stdcall *)(const char *))g_VBAllocTracker->TrackMeshAllocations)(a1: "R_StudioCreateStaticMeshes (character)");
            }
            else
            {
              TrackMeshAllocations = g_VBAllocTracker->TrackMeshAllocations;
              if ( (pStudioHdr->flags & 0x10) != 0 )
                ((void (__stdcall *)(const char *))TrackMeshAllocations)(a1: "R_StudioCreateStaticMeshes (prop_static)");
              else
                ((void (__stdcall *)(const char *))TrackMeshAllocations)(a1: "R_StudioCreateStaticMeshes (prop_dynamic)");
            }
            v15 = g_VBAllocTracker;
          }
          k = 0;
          if ( v14->nummeshes > 0 )
          {
            v21 = 0;
            v27 = 0;
            do
            {
              CStudioRenderContext::R_StudioCreateSingleMesh(
                this,
                pStudioHdr,
                pStudioLodData: &pStudioHWData->m_pLODs[nLodID],
                pMesh: (mstudiomesh_t *)&v14->name[v27 + v14->meshindex],
                pVtxMesh: (OptimizedModel::MeshHeader_t *)((char *)v13 + v21 + v13->meshOffset),
                numBones: pVtxHdr->maxBonesPerVert,
                pMeshData: &pStudioHWData->m_pLODs[nLodID].m_pMeshData[*(_DWORD *)&v14->name[v27 + 32 + v14->meshindex]],
                pColorMeshID);
              v27 += 116;
              ++k;
              v21 += 9;
            }
            while ( k < v14->nummeshes );
            v15 = g_VBAllocTracker;
            v10 = pBodyPart;
          }
          if ( v15 != nullptr )
            v15->TrackMeshAllocations(this: v15, a2: nullptr);
          v25 += 148;
          if ( ++j >= v10->nummodels )
            break;
          v11 = v19;
          v9 = pVtxBodyPart;
        }
        v7 = pStudioHdr;
        v6 = nLodID;
        v8 = i;
      }
      v24 += 16;
      i = ++v8;
    }
    while ( v8 < v7->numbodyparts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054FC0
// Name: public: virtual bool CStudioRenderContext::LoadModel(struct studiohdr_t __near *,void __near *,struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioRenderContext::LoadModel(
        CStudioRenderContext *this,
        studiohdr_t *pStudioHdr,
        OptimizedModel::FileHeader_t *pVtxBuffer,
        studiohwdata_t *pStudioHWData)
{
  studiohdr_t *v4; // ecx
  const char *v7; // eax
  int v9; // eax
  int v10; // eax
  int m_NumStudioMeshes; // edx
  int v12; // ecx
  int rootLOD; // eax
  studioloddata_t *v14; // eax
  studiohdr_t *v15; // eax
  int m_RootLOD; // edi
  int v17; // ecx
  char *v18; // ecx
  int v19; // eax
  int nColorMeshID; // [esp+Ch] [ebp-8h] BYREF
  CStudioRenderContext *v21; // [esp+10h] [ebp-4h]
  int j; // [esp+20h] [ebp+Ch]
  int ja; // [esp+20h] [ebp+Ch]
  int i; // [esp+24h] [ebp+10h]
  int ia; // [esp+24h] [ebp+10h]

  v21 = this;
  v4 = pStudioHdr;
  if ( pStudioHdr == nullptr || pVtxBuffer == nullptr || pStudioHWData == nullptr )
    return 0;
  if ( pVtxBuffer->checkSum != pStudioHdr->checksum )
  {
    v7 = studiohdr_t::pszName(this: pStudioHdr);
    _ConDMsg(a1: "Error! Model %s .vtx file out of synch with .mdl\n", v7);
    return 0;
  }
  pStudioHWData->m_NumStudioMeshes = 0;
  i = 0;
  if ( pStudioHdr->numbodyparts > 0 )
  {
    v9 = 0;
    nColorMeshID = 0;
    do
    {
      v10 = (int)v4 + v9 + v4->bodypartindex;
      j = 0;
      if ( *(int *)(v10 + 4) > 0 )
      {
        m_NumStudioMeshes = pStudioHWData->m_NumStudioMeshes;
        v12 = 0;
        do
        {
          m_NumStudioMeshes += *(_DWORD *)(v12 + *(_DWORD *)(v10 + 12) + v10 + 72);
          pStudioHWData->m_NumStudioMeshes = m_NumStudioMeshes;
          v12 += 148;
          ++j;
        }
        while ( j < *(_DWORD *)(v10 + 4) );
        v4 = pStudioHdr;
      }
      v9 = nColorMeshID + 16;
      ++i;
      nColorMeshID += 16;
    }
    while ( i < v4->numbodyparts );
  }
  rootLOD = v4->rootLOD;
  if ( rootLOD >= pVtxBuffer->numLODs - 1 )
    rootLOD = pVtxBuffer->numLODs - 1;
  pStudioHWData->m_RootLOD = rootLOD;
  pStudioHWData->m_NumLODs = pVtxBuffer->numLODs;
  v14 = (studioloddata_t *)operator new(nSize: 32 * pVtxBuffer->numLODs);
  pStudioHWData->m_pLODs = v14;
  memset(dst: (unsigned __int8 *)v14, value: 0, count: 32 * pVtxBuffer->numLODs);
  v15 = pStudioHdr;
  pStudioHdr->flags &= 0xFFFFFF5D;
  nColorMeshID = 0;
  m_RootLOD = pStudioHWData->m_RootLOD;
  if ( pStudioHWData->m_RootLOD < pStudioHWData->m_NumLODs )
  {
    v17 = 32 * m_RootLOD;
    ia = m_RootLOD;
    ja = 12 * m_RootLOD;
    while ( 1 )
    {
      CStudioRenderContext::LoadMaterials(
        this: v21,
        phdr: v15,
        pVtxHeader: pVtxBuffer,
        lodData: (studioloddata_t *)((char *)pStudioHWData->m_pLODs + v17),
        lodID: m_RootLOD);
      CStudioRenderContext::R_StudioCreateStaticMeshes(
        this: v21,
        pStudioHdr,
        pVtxHdr: pVtxBuffer,
        pStudioHWData,
        nLodID: m_RootLOD,
        pColorMeshID: &nColorMeshID);
      CStudioRenderContext::ComputeHWMorphDecalBoneRemap(
        this: v21,
        pStudioHdr,
        pVtxHdr: pVtxBuffer,
        pStudioHWData,
        nLOD: m_RootLOD);
      v18 = (char *)pVtxBuffer
          + pVtxBuffer->bodyPartOffset
          + *(int *)((char *)&pVtxBuffer->vertCacheSize + pVtxBuffer->bodyPartOffset);
      v19 = ja + *((_DWORD *)v18 + 1);
      ja += 12;
      pStudioHWData->m_pLODs[ia].m_SwitchPoint = *(float *)&v18[v19 + 8];
      ++m_RootLOD;
      ++ia;
      if ( m_RootLOD >= pStudioHWData->m_NumLODs )
        break;
      v17 = ia * 32;
      v15 = pStudioHdr;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10055160
// Name: public: virtual void CStudioRenderContext::DrawModel(struct DrawModelResults_t __near *,struct DrawModelInfo_t const __near &,struct matrix3x4_t __near *,float __near *,float __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DrawModel(
        CStudioRenderContext *this,
        DrawModelResults_t *pResults,
        float info,
        matrix3x4_t *pBoneToWorld,
        float *pFlexWeights,
        float *pFlexDelayedWeights,
        const Vector *origin,
        int flags)
{
  const DrawModelInfo_t *v8; // edi
  studiohwdata_t *v9; // eax
  IMatRenderContext *v10; // esi
  int v11; // eax
  int v12; // edx
  float *v13; // eax
  ICallQueue *v14; // ebx
  studiohdr_t *m_pStudioHdr; // ecx
  int numflexdesc; // eax
  float *m_pRenderData; // eax
  CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v18; // eax
  bool v19; // zf
  CMatRenderData<matrix3x4_t> rdMatrix; // [esp+8h] [ebp-44h] BYREF
  CMatRenderData<float> rdFlex; // [esp+18h] [ebp-34h] BYREF
  CMatRenderData<float> rdFlexDelayed; // [esp+28h] [ebp-24h] BYREF
  FlexWeights_t flex; // [esp+38h] [ebp-14h] BYREF
  unsigned __int64 v24; // [esp+40h] [ebp-Ch] BYREF
  CStudioRenderContext *v25; // [esp+48h] [ebp-4h]

  v25 = this;
  if ( pResults != nullptr )
  {
    pResults->m_TextureMemoryBytes = 0;
    pResults->m_ActualTriCount = 0;
  }
  v8 = (const DrawModelInfo_t *)LODWORD(info);
  if ( *(_DWORD *)LODWORD(info) != 0 )
  {
    v9 = *(studiohwdata_t **)(LODWORD(info) + 4);
    if ( v9 != nullptr && v9->m_NumLODs != 0 && v9->m_pLODs != nullptr )
    {
      CStudioRenderContext::GenerateRandomFlexWeights(
        this,
        nWeightCount: *(_DWORD *)(*(_DWORD *)LODWORD(info) + 260),
        pWeights: pFlexWeights,
        pDelayedWeights: pFlexDelayedWeights);
      v10 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
      if ( v10 != nullptr )
        v10->BeginRender(this: v10);
      v11 = CStudioRenderContext::ComputeRenderLOD(this: v25, pRenderContext: v10, info: v8, origin, pMetric: &info);
      v8->m_Lod = v11;
      if ( pResults != nullptr )
      {
        v12 = (int)info;
        pResults->m_nLODUsed = v11;
        pResults->m_flLODMetric = v12;
      }
      info = 0.0;
      HIDWORD(v24) = flags & 0x10;
      if ( (flags & 0x10) != 0 )
      {
        info = COERCE_FLOAT((int)g_pMaterialSystem->Lock(this: g_pMaterialSystem));
        g_pMaterialSystem->Flush(this: g_pMaterialSystem, a2: true);
      }
      if ( pResults != nullptr )
      {
        origin = (const Vector *)&pResults->m_RenderTime;
        pResults->m_RenderTime.m_Duration.m_Int64 = __rdtsc();
      }
      v13 = pFlexWeights;
      if ( pFlexWeights == nullptr )
        v13 = s_pZeroFlexWeights;
      flex.m_pFlexWeights = v13;
      flex.m_pFlexDelayedWeights = pFlexDelayedWeights;
      if ( pFlexDelayedWeights == nullptr )
        flex.m_pFlexDelayedWeights = v13;
      v14 = v10->GetCallQueue(this: v10);
      if ( v14 != nullptr
        && studio_queue_mode.m_pParent != nullptr
        && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
      {
        CMatRenderData<matrix3x4_t>::CMatRenderData<matrix3x4_t>(
          this: &rdMatrix,
          pRenderContext: v10,
          nCount: v8->m_pStudioHdr->numbones,
          pSrcData: pBoneToWorld);
        rdFlex.m_pRenderContext = v10;
        memset(&rdFlex.m_pRenderData, 0, 9);
        rdFlexDelayed.m_pRenderContext = v10;
        memset(&rdFlexDelayed.m_pRenderData, 0, 9);
        CStudioRenderContext::InvokeBindProxies(this: v25, pRenderContext: v10, pCallQueue: v14, info: v8);
        m_pStudioHdr = v8->m_pStudioHdr;
        pBoneToWorld = rdMatrix.m_pRenderData;
        numflexdesc = m_pStudioHdr->numflexdesc;
        if ( numflexdesc != 0 )
        {
          CMatRenderData<float>::Lock(this: &rdFlex, nCount: numflexdesc, pSrcData: flex.m_pFlexWeights);
          m_pRenderData = rdFlex.m_pRenderData;
          flex.m_pFlexWeights = rdFlex.m_pRenderData;
          if ( pFlexDelayedWeights != nullptr )
          {
            CMatRenderData<float>::Lock(
              this: &rdFlexDelayed,
              nCount: v8->m_pStudioHdr->numflexdesc,
              pSrcData: flex.m_pFlexDelayedWeights);
            m_pRenderData = rdFlexDelayed.m_pRenderData;
          }
          flex.m_pFlexDelayedWeights = m_pRenderData;
        }
        v18 = CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t *,FlexWeights_t const &,int,DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t *,FlexWeights_t,int>(
                this: &g_StudioRenderFunctorFactory,
                pObject: g_pStudioRenderImp,
                pfnProxied: CStudioRender::DrawModel,
                arg1: v8,
                arg2: &v25->m_RC,
                arg3: &pBoneToWorld,
                arg4: &flex,
                arg5: &flags);
        v14->QueueFunctorInternal(this: v14, a2: v18);
        CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<VMatrix> *)&rdFlexDelayed);
        CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<VMatrix> *)&rdFlex);
        CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<VMatrix> *)&rdMatrix);
      }
      else
      {
        CStudioRender::DrawModel(this: g_pStudioRenderImp, info: v8, rc: &v25->m_RC, pBoneToWorld, &flex, flags);
      }
      if ( HIDWORD(v24) != 0 )
      {
        g_pMaterialSystem->Flush(this: g_pMaterialSystem, a2: true);
        g_pMaterialSystem->Flush(this: g_pMaterialSystem, a2: true);
        g_pMaterialSystem->Unlock(this: g_pMaterialSystem, a2: (MaterialLock_t__ *)LODWORD(info));
      }
      if ( pResults != nullptr )
      {
        pBoneToWorld = (matrix3x4_t *)&v24;
        v24 = __rdtsc();
        v19 = (flags & 0x40) == 0;
        pResults->m_RenderTime.m_Duration.m_Int64 = v24 - pResults->m_RenderTime.m_Duration.m_Int64;
        if ( !v19 )
          v25->GetPerfStats(this: v25, a2: pResults, a3: v8, a4: nullptr);
      }
      v10->EndRender(this: v10);
      v10->Release(this: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055430
// Name: public: virtual void CStudioRenderContext::DrawModelArray(struct StudioModelArrayInfo_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DrawModelArray(
        CStudioRenderContext *this,
        const StudioModelArrayInfo_t *drawInfo,
        int nCount,
        StudioArrayInstanceData_t *pInstanceData,
        int nInstanceStride,
        int nFlags)
{
  IMatRenderContext *m_pObject; // edi
  ICallQueue *v8; // esi
  StudioArrayInstanceData_t *v9; // ebx
  int v10; // esi
  StudioArrayInstanceData_t *v11; // eax
  int i; // edx
  StudioArrayInstanceData_t *v13; // esi
  StudioArrayInstanceData_t *v14; // edi
  IMatRenderContext *m_pRenderContext; // ecx
  CRenderDataFunctorAllocator *m_pAllocator; // ebx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // eax
  CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v18; // esi
  CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v19; // eax
  CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v20; // eax
  StudioArrayInstanceData_t *renderData_4; // [esp+10h] [ebp-18h]
  ICallQueue *pCallQueue; // [esp+1Ch] [ebp-Ch]
  CMatRenderContextPtr pRenderContext; // [esp+20h] [ebp-8h]
  CStudioRender *pRenderContexta; // [esp+20h] [ebp-8h]

  m_pObject = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v8 = m_pObject->GetCallQueue(this: m_pObject);
  pCallQueue = v8;
  if ( v8 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    v9 = pInstanceData;
    if ( m_pObject->IsRenderData(this: m_pObject, a2: pInstanceData) )
    {
      v20 = CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int,StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,int,int>(
              this: &g_StudioRenderFunctorFactory,
              pObject: g_pStudioRenderImp,
              pfnProxied: CStudioRender::DrawModelArray,
              arg1: drawInfo,
              arg2: &this->m_RC,
              arg3: &nCount,
              arg4: &pInstanceData,
              arg5: &nInstanceStride,
              arg6: &nFlags);
      v8->QueueFunctorInternal(this: v8, a2: v20);
    }
    else
    {
      v10 = nCount;
      v11 = (StudioArrayInstanceData_t *)m_pObject->LockRenderData(this: m_pObject, a2: 68 * nCount);
      renderData_4 = v11;
      pInstanceData = v11;
      if ( v10 > 0 )
      {
        for ( i = v10; i != 0; --i )
        {
          v13 = v9;
          v9 = (StudioArrayInstanceData_t *)((char *)v9 + nInstanceStride);
          v14 = v11++;
          qmemcpy(v14, v13, sizeof(StudioArrayInstanceData_t));
        }
        m_pObject = pRenderContext.m_pObject;
      }
      pRenderContexta = g_pStudioRenderImp;
      m_pRenderContext = g_StudioRenderFunctorFactory.m_pAllocator->m_pRenderContext;
      m_pAllocator = g_StudioRenderFunctorFactory.m_pAllocator;
      LockRenderData = g_StudioRenderFunctorFactory.m_pAllocator->m_pRenderContext->LockRenderData;
      nInstanceStride = 68;
      v18 = (CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)LockRenderData(this: m_pRenderContext, a2: 652);
      m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v18);
      if ( v18 != nullptr )
        v19 = CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo_t const &,StudioRenderContext_t const &,int,StudioArrayInstanceData_t *,int,int),StudioModelArrayInfo_t,StudioRenderContext_t,int,StudioArrayInstanceData_t *,unsigned int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
                this: v18,
                pObject: pRenderContexta,
                pfnProxied: CStudioRender::DrawModelArray,
                arg1: drawInfo,
                arg2: &this->m_RC,
                arg3: &nCount,
                arg4: &pInstanceData,
                arg5: (unsigned int *)&nInstanceStride,
                arg6: &nFlags);
      else
        v19 = nullptr;
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: v19);
      if ( renderData_4 != nullptr )
        m_pObject->UnlockRenderData(this: m_pObject, a2: renderData_4);
    }
  }
  else
  {
    CStudioRender::DrawModelArray(
      this: g_pStudioRenderImp,
      drawInfo,
      rc: &this->m_RC,
      nCount,
      pInstanceData,
      nInstanceStride,
      nFlags);
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100555F0
// Name: public: virtual void CStudioRenderContext::DrawModelArray(struct StudioModelArrayInfo2_t const __near &,int,struct StudioArrayData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DrawModelArray(
        CStudioRenderContext *this,
        const StudioModelArrayInfo2_t *drawInfo,
        int nCount,
        StudioArrayData_t *pArrayData,
        int nInstanceStride,
        int nFlags)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v8; // edi
  CRenderDataFunctorAllocator *m_pAllocator; // ebx
  char *v10; // esi
  StudioArrayData_t *m_pRenderData; // edx
  const StudioRenderContext_t *p_m_RC; // [esp-4h] [ebp-28h]
  CMatRenderData<StudioArrayData_t> arrayRenderData; // [esp+Ch] [ebp-18h] BYREF
  ICallQueue *pCallQueue; // [esp+1Ch] [ebp-8h]
  CStudioRenderContext *v15; // [esp+20h] [ebp-4h]
  StudioArrayData_t *pArrayDataa; // [esp+34h] [ebp+10h]

  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v15 = this;
  v8 = GetRenderContext(this: g_pMaterialSystem);
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  pCallQueue = v8->GetCallQueue(this: v8);
  if ( pCallQueue != nullptr
    && studio_queue_mode.m_pParent != nullptr
    && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    arrayRenderData.m_pRenderContext = v8;
    memset(&arrayRenderData.m_pRenderData, 0, 9);
    CMatRenderData<StudioArrayData_t>::Lock(this: &arrayRenderData, nCount, pSrcData: pArrayData);
    m_pAllocator = g_StudioRenderFunctorFactory.m_pAllocator;
    pArrayDataa = (StudioArrayData_t *)g_pStudioRenderImp;
    v10 = (char *)g_StudioRenderFunctorFactory.m_pAllocator->m_pRenderContext->LockRenderData(
                    this: g_StudioRenderFunctorFactory.m_pAllocator->m_pRenderContext,
                    a2: 644);
    m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v10);
    if ( v10 != nullptr )
    {
      *((_DWORD *)v10 + 3) = 1;
      *(_DWORD *)v10 = &CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo2_t const &,StudioRenderContext_t const &,int,StudioArrayData_t *,int,int),StudioModelArrayInfo2_t,StudioRenderContext_t,int,StudioArrayData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      *((_DWORD *)v10 + 2) = &CMemberFunctor6<CStudioRender *,void (__thiscall CStudioRender::*)(StudioModelArrayInfo2_t const &,StudioRenderContext_t const &,int,StudioArrayData_t *,int,int),StudioModelArrayInfo2_t,StudioRenderContext_t,int,StudioArrayData_t *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
      *((_DWORD *)v10 + 5) = pArrayDataa;
      *((_DWORD *)v10 + 4) = CStudioRender::DrawModelArray2;
      *((_DWORD *)v10 + 6) = drawInfo->m_nFlashlightCount;
      p_m_RC = &v15->m_RC;
      *((_DWORD *)v10 + 7) = drawInfo->m_pFlashlights;
      StudioRenderContext_t::StudioRenderContext_t(this: (StudioRenderContext_t *)(v10 + 32), __that: p_m_RC);
      m_pRenderData = arrayRenderData.m_pRenderData;
      *((_DWORD *)v10 + 157) = nCount;
      *((_DWORD *)v10 + 158) = m_pRenderData;
      *((_DWORD *)v10 + 159) = nInstanceStride;
      *((_DWORD *)v10 + 160) = nFlags;
    }
    else
    {
      v10 = nullptr;
    }
    pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: (CFunctor *)v10);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<VMatrix> *)&arrayRenderData);
  }
  else
  {
    CStudioRender::DrawModelArray2(
      this: g_pStudioRenderImp,
      drawInfo,
      rc: &this->m_RC,
      nCount,
      pArrayData,
      nInstanceStride,
      nFlags);
  }
  v8->EndRender(this: v8);
  v8->Release(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10055760
// Name: public: virtual void CStudioRenderContext::DrawModelShadowArray(int,struct StudioArrayData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DrawModelShadowArray(
        CStudioRenderContext *this,
        int nCount,
        StudioArrayData_t *pShadowData,
        int nInstanceStride,
        int nFlags)
{
  IMatRenderContext *v5; // esi
  ICallQueue *v6; // edi
  CFunctor *v7; // eax
  CMatRenderData<StudioArrayData_t> renderData; // [esp+8h] [ebp-14h] BYREF
  CStudioRenderContext *v9; // [esp+18h] [ebp-4h]

  v9 = this;
  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v6 = v5->GetCallQueue(this: v5);
  if ( v6 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    renderData.m_pRenderContext = v5;
    memset(&renderData.m_pRenderData, 0, 9);
    CMatRenderData<StudioArrayData_t>::Lock(this: &renderData, nCount, pSrcData: pShadowData);
    pShadowData = renderData.m_pRenderData;
    v7 = CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,StudioRenderContext_t const &,int,StudioArrayData_t *,int,int,StudioRenderContext_t,int,StudioArrayData_t *,int,int>(
           this: &g_StudioRenderFunctorFactory,
           pObject: g_pStudioRenderImp,
           pfnProxied: CStudioRender::DrawModelShadowArray,
           arg1: &v9->m_RC,
           arg2: &nCount,
           arg3: &pShadowData,
           arg4: &nInstanceStride,
           arg5: &nFlags);
    v6->QueueFunctorInternal(this: v6, a2: v7);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<VMatrix> *)&renderData);
  }
  else
  {
    CStudioRender::DrawModelShadowArray(
      this: g_pStudioRenderImp,
      rc: &v9->m_RC,
      nCount,
      pShadowData,
      nInstanceStride,
      flags: nFlags);
  }
  v5->EndRender(this: v5);
  v5->Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10055860
// Name: public: virtual void CStudioRenderContext::DrawModelStaticProp(struct DrawModelInfo_t const __near &,struct matrix3x4_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DrawModelStaticProp(
        CStudioRenderContext *this,
        const DrawModelInfo_t *info,
        const matrix3x4_t *modelToWorld,
        int flags)
{
  int m_RootLOD; // eax
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // ebx
  ICallQueue *v8; // eax
  CRenderDataFunctorAllocator *m_pAllocator; // edi
  CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // esi
  CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v11; // eax
  ICallQueue *pCallQueue; // [esp+Ch] [ebp-Ch]
  CStudioRender *pObject; // [esp+10h] [ebp-8h]

  m_RootLOD = info->m_pHardwareData->m_RootLOD;
  if ( info->m_Lod < m_RootLOD )
    info->m_Lod = m_RootLOD;
  v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v7 = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v8 = v7->GetCallQueue(this: v7);
  pCallQueue = v8;
  if ( v8 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    CStudioRenderContext::InvokeBindProxies(this, pRenderContext: v7, pCallQueue: v8, info);
    pObject = g_pStudioRenderImp;
    m_pAllocator = g_StudioRenderFunctorFactory.m_pAllocator;
    v10 = (CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)g_StudioRenderFunctorFactory.m_pAllocator->m_pRenderContext->LockRenderData(this: g_StudioRenderFunctorFactory.m_pAllocator->m_pRenderContext, a2: 1152);
    m_pAllocator->m_pRenderContext->UnlockRenderData(this: m_pAllocator->m_pRenderContext, a2: v10);
    if ( v10 != nullptr )
    {
      v11 = CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
              this: v10,
              pObject,
              pfnProxied: CStudioRender::DrawModelStaticProp,
              arg1: info,
              arg2: &this->m_RC,
              arg3: modelToWorld,
              arg4: &flags);
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: v11);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    CStudioRender::DrawModelStaticProp(
      this: g_pStudioRenderImp,
      info,
      rc: &this->m_RC,
      rootToWorld: modelToWorld,
      flags);
  }
  v7->EndRender(this: v7);
  v7->Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10055980
// Name: public: virtual void CStudioRenderContext::DrawModelArrayStaticProp(struct DrawModelInfo_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DrawModelArrayStaticProp(
        CStudioRenderContext *this,
        const DrawModelInfo_t *info,
        int nInstanceCount,
        const MeshInstanceData_t *pInstanceData,
        ColorMeshInfo_t **pColorMeshes)
{
  int m_RootLOD; // eax
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // edi
  ICallQueue *v8; // esi
  CUtlEnvelope<ColorMeshInfo_t *> *v9; // eax
  CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // eax
  CMemberFunctor5<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *),DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v11; // eax
  CMatRenderData<MeshInstanceData_t> renderData; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlEnvelope<ColorMeshInfo_t *> v13; // [esp+1Ch] [ebp-Ch] BYREF
  CStudioRenderContext *v14; // [esp+24h] [ebp-4h]

  m_RootLOD = info->m_pHardwareData->m_RootLOD;
  v14 = this;
  if ( info->m_Lod < m_RootLOD )
    info->m_Lod = m_RootLOD;
  v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v7 = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v8 = v7->GetCallQueue(this: v7);
  if ( v8 == nullptr || studio_queue_mode.m_pParent == nullptr || studio_queue_mode.m_pParent->m_Value.m_nValue == 0 )
  {
    CStudioRender::DrawModelArrayStaticProp(
      this: g_pStudioRenderImp,
      info,
      rc: &v14->m_RC,
      nInstanceCount,
      pInstanceData,
      pColorMeshes);
    goto LABEL_14;
  }
  CStudioRenderContext::InvokeBindProxies(this: v14, pRenderContext: v7, pCallQueue: v8, info);
  renderData.m_pRenderContext = v7;
  memset(&renderData.m_pRenderData, 0, 9);
  CMatRenderData<MeshInstanceData_t>::Lock(this: &renderData, nCount: nInstanceCount, pSrcData: pInstanceData);
  pInstanceData = renderData.m_pRenderData;
  if ( pColorMeshes == nullptr )
  {
    v11 = CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *,DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,ColorMeshInfo_t * *>(
            this: &g_StudioRenderFunctorFactory,
            pObject: g_pStudioRenderImp,
            pfnProxied: CStudioRender::DrawModelArrayStaticProp,
            arg1: info,
            arg2: &v14->m_RC,
            arg3: &nInstanceCount,
            arg4: &pInstanceData,
            arg5: &pColorMeshes);
    v8->QueueFunctorInternal(this: v8, a2: v11);
    goto LABEL_12;
  }
  v9 = CUtlEnvelope<ColorMeshInfo_t *>::CUtlEnvelope<ColorMeshInfo_t *>(
         this: &v13,
         pData: pColorMeshes,
         nElems: nInstanceCount);
  v10 = CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,DrawModelInfo_t const &,StudioRenderContext_t const &,int,MeshInstanceData_t const *,ColorMeshInfo_t * *,DrawModelInfo_t,StudioRenderContext_t,int,MeshInstanceData_t *,CUtlEnvelope<ColorMeshInfo_t *>>(
          this: &g_StudioRenderFunctorFactory,
          pObject: g_pStudioRenderImp,
          pfnProxied: CStudioRender::DrawModelArrayStaticProp,
          arg1: info,
          arg2: &v14->m_RC,
          arg3: &nInstanceCount,
          arg4: &pInstanceData,
          arg5: v9);
  v8->QueueFunctorInternal(this: v8, a2: v10);
  if ( v13.m_nBytes <= 4 )
  {
LABEL_12:
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<VMatrix> *)&renderData);
    goto LABEL_14;
  }
  free(pMem: v13.m_pData);
  CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<VMatrix> *)&renderData);
LABEL_14:
  v7->EndRender(this: v7);
  v7->Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10055AF0
// Name: public: virtual void CStudioRenderContext::DrawStaticPropShadows(struct DrawModelInfo_t const __near &,struct matrix3x4_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DrawStaticPropShadows(
        CStudioRenderContext *this,
        const DrawModelInfo_t *info,
        const matrix3x4_t *modelToWorld,
        int flags)
{
  IMatRenderContext *v5; // esi
  ICallQueue *v6; // ebx
  CStudioRender *v7; // edi
  CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v8; // eax
  CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v9; // eax

  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v6 = v5->GetCallQueue(this: v5);
  if ( v6 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = g_pStudioRenderImp;
    v8 = (CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)operator new(nSize: 0x480u);
    if ( v8 != nullptr )
    {
      v9 = CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor4<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &,int),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
             this: v8,
             pObject: v7,
             pfnProxied: CStudioRender::DrawStaticPropShadows,
             arg1: info,
             arg2: &this->m_RC,
             arg3: modelToWorld,
             arg4: &flags);
      v6->QueueFunctorInternal(this: v6, a2: v9);
    }
    else
    {
      v6->QueueFunctorInternal(this: v6, a2: nullptr);
    }
  }
  else
  {
    CStudioRender::DrawStaticPropShadows(
      this: g_pStudioRenderImp,
      info,
      rc: &this->m_RC,
      rootToWorld: modelToWorld,
      flags);
  }
  v5->EndRender(this: v5);
  v5->Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10055BD0
// Name: public: virtual void CStudioRenderContext::AddShadow(class IMaterial __near *,void __near *,struct FlashlightState_t __near *,class VMatrix __near *,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::AddShadow(
        CStudioRenderContext *this,
        IMaterial *pMaterial,
        void *pProxyData,
        FlashlightState_t *pFlashlightState,
        VMatrix *pWorldToTexture,
        ITexture *pFlashlightDepthTexture)
{
  IMatRenderContext *v6; // esi
  ICallQueue *v7; // edi
  CFunctor *v8; // eax
  CMatRenderData<FlashlightState_t> rdFlashlight; // [esp+Ch] [ebp-20h] BYREF
  CMatRenderData<VMatrix> rdMatrix; // [esp+1Ch] [ebp-10h] BYREF

  v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v7 = v6->GetCallQueue(this: v6);
  if ( v7 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( pProxyData != nullptr )
    {
      _Warning(a1: "Cannot call CStudioRenderContext::AddShadows w/ proxies in queued mode!\n");
    }
    else
    {
      rdFlashlight.m_pRenderContext = v6;
      memset(&rdFlashlight.m_pRenderData, 0, 9);
      CMatRenderData<FlashlightState_t>::Lock(this: &rdFlashlight, nCount: 1, pSrcData: pFlashlightState);
      rdMatrix.m_pRenderContext = v6;
      memset(&rdMatrix.m_pRenderData, 0, 9);
      CMatRenderData<VMatrix>::Lock(this: &rdMatrix, nCount: 1, pSrcData: pWorldToTexture);
      pWorldToTexture = rdMatrix.m_pRenderData;
      pFlashlightState = rdFlashlight.m_pRenderData;
      pProxyData = nullptr;
      v8 = CCustomizedFunctorFactory<CRenderDataFunctorAllocator,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CStudioRender *,CStudioRender,void,IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *,IMaterial *,void *,FlashlightState_t *,VMatrix *,ITexture *>(
             this: &g_StudioRenderFunctorFactory,
             pObject: g_pStudioRenderImp,
             pfnProxied: CStudioRender::AddShadow,
             arg1: &pMaterial,
             arg2: &pProxyData,
             arg3: &pFlashlightState,
             arg4: &pWorldToTexture,
             arg5: &pFlashlightDepthTexture);
      v7->QueueFunctorInternal(this: v7, a2: v8);
      CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: &rdMatrix);
      CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<VMatrix> *)&rdFlashlight);
    }
  }
  else
  {
    CStudioRender::AddShadow(
      this: g_pStudioRenderImp,
      pMaterial,
      pProxyData,
      pFlashlightState,
      pWorldToTexture,
      pFlashlightDepthTexture);
  }
  v6->EndRender(this: v6);
  v6->Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10055D00
// Name: public: void ICallQueue::QueueCall<class CStudioRender __near *,class CStudioRender,void>(class CStudioRender __near *,void (CStudioRender::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CStudioRender *,CStudioRender,void>(
        ICallQueue *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this))
{
  CFunctor *v4; // eax

  v4 = (CFunctor *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CStudioRender *,void (__thiscall CStudioRender::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CStudioRender *,void (__thiscall CStudioRender::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4[2].m_nUserID = (unsigned int)pObject;
    this->QueueFunctorInternal(this, a2: v4);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055D60
// Name: public: void ICallQueue::QueueCall<class CStudioRender __near *,class CStudioRender,void,void (*)(int,struct IStudioRender::FacesRenderedInfo_t __near *,int),void (*)(int,struct IStudioRender::FacesRenderedInfo_t __near *,int)>(class CStudioRender __near *,void (CStudioRender::*)(void (*)(int,struct IStudioRender::FacesRenderedInfo_t __near *,int)),void (*const __near &)(int,struct IStudioRender::FacesRenderedInfo_t __near *,int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CStudioRender *,CStudioRender,void,void (__cdecl *)(int,IStudioRender::FacesRenderedInfo_t *,int),void (__cdecl *)(int,IStudioRender::FacesRenderedInfo_t *,int)>(
        ICallQueue *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, void (__cdecl *)(int, IStudioRender::FacesRenderedInfo_t *, int)),
        CFunctor_vtbl **arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)operator new(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CStudioRender *,void (__thiscall CStudioRender::*)(void (__cdecl *)(int,IStudioRender::FacesRenderedInfo_t *,int)),void (__cdecl *)(int,IStudioRender::FacesRenderedInfo_t *,int),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CStudioRender *,void (__thiscall CStudioRender::*)(void (__cdecl *)(int,IStudioRender::FacesRenderedInfo_t *,int)),void (__cdecl *)(int,IStudioRender::FacesRenderedInfo_t *,int),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    v5[3].__vftable = *arg1;
    this->QueueFunctorInternal(this, a2: v5);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055DC0
// Name: public: void ICallQueue::QueueCall<class CStudioRender __near *,class CStudioRender,void,struct StudioDecalHandle_t__ __near *,struct StudioDecalHandle_t__ __near *>(class CStudioRender __near *,void (CStudioRender::*)(struct StudioDecalHandle_t__ __near *),struct StudioDecalHandle_t__ __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CStudioRender *,CStudioRender,void,StudioDecalHandle_t__ *,StudioDecalHandle_t__ *>(
        ICallQueue *this,
        CStudioRender *pObject,
        void (__thiscall *pfnProxied)(CStudioRender *this, StudioDecalHandle_t__ *),
        CFunctor_vtbl **arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)operator new(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *),StudioDecalHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *),StudioDecalHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    v5[3].__vftable = *arg1;
    this->QueueFunctorInternal(this, a2: v5);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055E20
// Name: public: virtual void CStudioRenderContext::UnloadModel(struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::UnloadModel(CStudioRenderContext *this, studiohwdata_t *pHardwareData)
{
  int m_RootLOD; // edi
  int v4; // edi
  int j; // ebx
  IMaterial **ppMaterials; // edx
  int v7; // edi
  int v8; // ebx
  IMatRenderContext *v9; // esi
  CStudioRender *v10; // edi
  _DWORD *v11; // eax
  int i; // [esp+18h] [ebp+8h]
  ICallQueue *ia; // [esp+18h] [ebp+8h]

  m_RootLOD = pHardwareData->m_RootLOD;
  i = m_RootLOD;
  if ( m_RootLOD < pHardwareData->m_NumLODs )
  {
    v4 = m_RootLOD;
    do
    {
      for ( j = 0; j < pHardwareData->m_pLODs[v4].numMaterials; ++j )
      {
        ppMaterials = pHardwareData->m_pLODs[v4].ppMaterials;
        if ( ppMaterials[j] != nullptr )
          ppMaterials[j]->DecrementReferenceCount(this: ppMaterials[j]);
      }
      free(pMem: pHardwareData->m_pLODs[v4].ppMaterials);
      free(pMem: pHardwareData->m_pLODs[v4].pMaterialFlags);
      pHardwareData->m_pLODs[v4].ppMaterials = nullptr;
      pHardwareData->m_pLODs[v4++].pMaterialFlags = nullptr;
      ++i;
    }
    while ( i < pHardwareData->m_NumLODs );
  }
  v7 = pHardwareData->m_RootLOD;
  if ( pHardwareData->m_RootLOD < pHardwareData->m_NumLODs )
  {
    v8 = v7;
    do
    {
      CStudioRenderContext::R_StudioDestroyStaticMeshes(
        this,
        numStudioMeshes: pHardwareData->m_NumStudioMeshes,
        ppStudioMeshes: &pHardwareData->m_pLODs[v8].m_pMeshData);
      ++v7;
      ++v8;
    }
    while ( v7 < pHardwareData->m_NumLODs );
  }
  free(pMem: pHardwareData->m_pLODs);
  pHardwareData->m_pLODs = nullptr;
  v9 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  ia = v9->GetCallQueue(this: v9);
  if ( ia != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = g_pStudioRenderImp;
    v11 = operator new(nSize: 0x20u);
    if ( v11 != nullptr )
    {
      v11[3] = 1;
      *v11 = &CMemberFunctor2<CStudioRender *,void (__thiscall CStudioRender::*)(int,bool),int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v11[2] = &CMemberFunctor2<CStudioRender *,void (__thiscall CStudioRender::*)(int,bool),int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v11[4] = CStudioRender::UpdateModelFaceCounts;
      v11[5] = v10;
      v11[6] = 0;
      *((_BYTE *)v11 + 28) = 1;
      ia->QueueFunctorInternal(this: ia, a2: (CFunctor *)v11);
    }
    else
    {
      ia->QueueFunctorInternal(this: ia, a2: nullptr);
    }
  }
  else
  {
    CStudioRender::UpdateModelFaceCounts(this: g_pStudioRenderImp, nSpewFromCurrentFrame: 0, bClearHistory: true);
  }
  v9->EndRender(this: v9);
  v9->Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10055FB0
// Name: public: virtual void CStudioRenderContext::BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::BeginFrame(CStudioRenderContext *this)
{
  int m_nValue; // ecx
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  ICallQueue *v5; // eax

  *((_BYTE *)&this->m_RC.m_Config + 56) |= 3u;
  if ( r_hwmorph.m_pParent != nullptr )
    m_nValue = r_hwmorph.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  *((_BYTE *)&this->m_RC.m_Config + 56) ^= (*((_BYTE *)&this->m_RC.m_Config + 56) ^ (4 * (m_nValue != 0))) & 4;
  if ( g_pMaterialSystem->GetThreadMode(this: g_pMaterialSystem) != MATERIAL_SINGLE_THREADED )
    *((_BYTE *)&this->m_RC.m_Config + 56) &= ~4u;
  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v4 = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v5 = v4->GetCallQueue(this: v4);
  if ( v5 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    g_RenderDataAllocator.m_pRenderContext = v4;
    ICallQueue::QueueCall<CStudioRender *,CStudioRender,void>(
      this: v5,
      pObject: g_pStudioRenderImp,
      pfnProxied: CStudioRender::BeginFrame);
  }
  else
  {
    CStudioRender::BeginFrame(this: g_pStudioRenderImp);
  }
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10056070
// Name: public: virtual void CStudioRenderContext::EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::EndFrame(CStudioRenderContext *this)
{
  IMatRenderContext *v1; // esi
  ICallQueue *v2; // eax

  v1 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  v2 = v1->GetCallQueue(this: v1);
  if ( v2 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    ICallQueue::QueueCall<CStudioRender *,CStudioRender,void>(
      this: v2,
      pObject: g_pStudioRenderImp,
      pfnProxied: CStudioRender::EndFrame);
    g_RenderDataAllocator.m_pRenderContext = nullptr;
  }
  else
  {
    CStudioRender::EndFrame(this: g_pStudioRenderImp);
  }
  v1->EndRender(this: v1);
  v1->Release(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100560F0
// Name: public: virtual void CStudioRenderContext::DrawStaticPropDecals(struct DrawModelInfo_t const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DrawStaticPropDecals(
        CStudioRenderContext *this,
        const DrawModelInfo_t *info,
        const matrix3x4_t *modelToWorld)
{
  IMatRenderContext *v4; // esi
  ICallQueue *v5; // ebx
  CStudioRender *v6; // edi
  CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v7; // eax
  CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v8; // eax

  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v5 = v4->GetCallQueue(this: v4);
  if ( v5 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    v6 = g_pStudioRenderImp;
    v7 = (CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)operator new(nSize: 0x47Cu);
    if ( v7 != nullptr )
    {
      v8 = CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor3<CStudioRender *,void (__thiscall CStudioRender::*)(DrawModelInfo_t const &,StudioRenderContext_t const &,matrix3x4_t const &),DrawModelInfo_t,StudioRenderContext_t,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
             this: v7,
             pObject: v6,
             pfnProxied: CStudioRender::DrawStaticPropDecals,
             arg1: info,
             arg2: &this->m_RC,
             arg3: modelToWorld);
      v5->QueueFunctorInternal(this: v5, a2: v8);
    }
    else
    {
      v5->QueueFunctorInternal(this: v5, a2: nullptr);
    }
  }
  else
  {
    CStudioRender::DrawStaticPropDecals(this: g_pStudioRenderImp, drawInfo: info, rc: &this->m_RC, modelToWorld);
  }
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100561C0
// Name: public: virtual void CStudioRenderContext::GatherRenderedFaceInfo(void (*)(int,struct IStudioRender::FacesRenderedInfo_t __near *,int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::GatherRenderedFaceInfo(
        CStudioRenderContext *this,
        void (__cdecl *pFunc)(int, IStudioRender::FacesRenderedInfo_t *, int))
{
  IMatRenderContext *v2; // esi
  ICallQueue *v3; // eax

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = v2->GetCallQueue(this: v2);
  if ( v3 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
    ICallQueue::QueueCall<CStudioRender *,CStudioRender,void,void (__cdecl *)(int,IStudioRender::FacesRenderedInfo_t *,int),void (__cdecl *)(int,IStudioRender::FacesRenderedInfo_t *,int)>(
      this: v3,
      pObject: g_pStudioRenderImp,
      pfnProxied: CStudioRender::GatherRenderedFaceInfo,
      arg1: (CFunctor_vtbl **)&pFunc);
  else
    CStudioRender::GatherRenderedFaceInfo(this: g_pStudioRenderImp, pFunc);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10056250
// Name: public: virtual void CStudioRenderContext::ClearAllShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::ClearAllShadows(CStudioRenderContext *this)
{
  IMatRenderContext *v1; // esi
  ICallQueue *v2; // eax

  v1 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  v2 = v1->GetCallQueue(this: v1);
  if ( v2 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
    ICallQueue::QueueCall<CStudioRender *,CStudioRender,void>(
      this: v2,
      pObject: g_pStudioRenderImp,
      pfnProxied: CStudioRender::ClearAllShadows);
  else
    CStudioRender::ClearAllShadows(this: g_pStudioRenderImp);
  v1->EndRender(this: v1);
  v1->Release(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100562D0
// Name: public: virtual void CStudioRenderContext::DestroyDecalList(struct StudioDecalHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::DestroyDecalList(CStudioRenderContext *this, StudioDecalHandle_t__ *handle)
{
  IMatRenderContext *v2; // esi
  ICallQueue *v3; // eax

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = v2->GetCallQueue(this: v2);
  if ( v3 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
    ICallQueue::QueueCall<CStudioRender *,CStudioRender,void,StudioDecalHandle_t__ *,StudioDecalHandle_t__ *>(
      this: v3,
      pObject: g_pStudioRenderImp,
      pfnProxied: CStudioRender::DestroyDecalList,
      arg1: (CFunctor_vtbl **)&handle);
  else
    CStudioRender::DestroyDecalList(this: g_pStudioRenderImp, hDecal: handle);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10056360
// Name: public: virtual void CStudioRenderContext::AddDecal(struct StudioDecalHandle_t__ __near *,struct studiohdr_t __near *,struct matrix3x4_t __near *,struct Ray_t const __near &,class Vector const __near &,class IMaterial __near *,float,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::AddDecal(
        CStudioRenderContext *this,
        StudioDecalHandle_t__ *handle,
        studiohdr_t *pStudioHdr,
        matrix3x4_t *pBoneToWorld,
        const Ray_t *ray,
        const Vector *decalUp,
        IMaterial *pDecalMaterial,
        float radius,
        int body,
        bool noPokethru,
        int maxLODToDecal)
{
  IMatRenderContext *v12; // esi
  ICallQueue *v13; // ebx
  CStudioRender *v14; // edi
  CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v15; // eax
  CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v16; // eax

  v12 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v12 != nullptr )
    v12->BeginRender(this: v12);
  v13 = v12->GetCallQueue(this: v12);
  if ( v13 != nullptr && studio_queue_mode.m_pParent != nullptr && studio_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    v14 = g_pStudioRenderImp;
    v15 = (CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)operator new(nSize: 0x2F0u);
    if ( v15 != nullptr )
    {
      v16 = CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor11<CStudioRender *,void (__thiscall CStudioRender::*)(StudioDecalHandle_t__ *,StudioRenderContext_t const &,matrix3x4_t *,studiohdr_t *,Ray_t const &,Vector const &,IMaterial *,float,int,bool,int),StudioDecalHandle_t__ *,StudioRenderContext_t,matrix3x4_t *,studiohdr_t *,Ray_t,Vector,IMaterial *,float,int,bool,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
              this: v15,
              pObject: v14,
              pfnProxied: CStudioRender::AddDecal,
              arg1: &handle,
              arg2: &this->m_RC,
              arg3: &pBoneToWorld,
              arg4: &pStudioHdr,
              arg5: ray,
              arg6: decalUp,
              arg7: &pDecalMaterial,
              arg8: &radius,
              arg9: &body,
              arg10: &noPokethru,
              arg11: &maxLODToDecal);
      v13->QueueFunctorInternal(this: v13, a2: v16);
    }
    else
    {
      v13->QueueFunctorInternal(this: v13, a2: nullptr);
    }
  }
  else
  {
    CStudioRender::AddDecal(
      this: g_pStudioRenderImp,
      hDecal: handle,
      rc: &this->m_RC,
      pBoneToWorld,
      pStudioHdr,
      ray,
      decalUp,
      pDecalMaterial,
      radius,
      body,
      noPokethru,
      maxLODToDecal);
  }
  v12->EndRender(this: v12);
  v12->Release(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10056470
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  int m_Size; // eax
  int v4; // edi
  int v5; // ebx
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v8; // eax

  m_Size = this->m_Size;
  if ( m_Size < num )
  {
    v4 = num - m_Size;
    v5 = this->m_Size;
    if ( num != m_Size )
    {
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( v5 + v4 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: v4 + v5 - m_nAllocationCount);
      this->m_Size += v4;
      m_pMemory = this->m_Memory.m_pMemory;
      v8 = this->m_Size - v5 - v4;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v8 > 0 && v4 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + v4], src: &m_pMemory[v5], count: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100564D0
// Name: public: virtual void CStudioRenderContext::GetPerfStats(struct DrawModelResults_t __near *,struct DrawModelInfo_t const __near &,class CUtlBuffer __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::GetPerfStats(
        CStudioRenderContext *this,
        DrawModelResults_t *pResults,
        const DrawModelInfo_t *info,
        CUtlBuffer *pSpewBuf)
{
  const DrawModelInfo_t *v4; // ebx
  int v5; // esi
  DrawModelResults_t *v6; // edi
  int m_Lod; // eax
  studioloddata_t *m_pLODs; // ecx
  int j; // eax
  int m_Skin; // ecx
  __int16 *v11; // ecx
  studiohdr_t *m_pStudioHdr; // eax
  mstudiomodel_t *v13; // edx
  char *v14; // eax
  IMaterial *m_pForcedMaterial; // ecx
  int v16; // eax
  bool v17; // zf
  int m_Size; // ebx
  IMaterial **v19; // esi
  CUtlBuffer *v20; // esi
  const char *v21; // eax
  int v22; // eax
  int v23; // eax
  studiomeshgroup_t *v24; // ebx
  bool v25; // al
  bool v26; // cl
  OptimizedModel::StripHeader_t *v27; // esi
  int m; // eax
  int v29; // edx
  int v30; // edi
  const char *v31; // ecx
  const char *v32; // eax
  CUtlBuffer *v33; // ecx
  int v34; // eax
  bool *m_pMemory; // edx
  int m_Body; // [esp-Ch] [ebp-6Ch]
  int numbones; // [esp-4h] [ebp-64h]
  CUtlVector<bool,CUtlMemory<bool,int> > hardwareBonesUsed; // [esp+Ch] [ebp-54h] BYREF
  CStudioRenderContext *v39; // [esp+20h] [ebp-40h]
  studiomeshdata_t *pStudioMeshes; // [esp+24h] [ebp-3Ch]
  IMaterial **ppMaterials; // [esp+28h] [ebp-38h]
  __int16 *pSkinRef; // [esp+2Ch] [ebp-34h]
  int i; // [esp+30h] [ebp-30h]
  int k; // [esp+34h] [ebp-2Ch]
  int stripGroupID; // [esp+38h] [ebp-28h]
  int stripID; // [esp+3Ch] [ebp-24h]
  int v47; // [esp+40h] [ebp-20h]
  studiomeshdata_t *pMeshData; // [esp+44h] [ebp-1Ch]
  unsigned int v49; // [esp+48h] [ebp-18h]
  unsigned int v50; // [esp+4Ch] [ebp-14h]
  int numPasses; // [esp+50h] [ebp-10h]
  int nNumVerts; // [esp+54h] [ebp-Ch]
  mstudiomodel_t *pModel; // [esp+58h] [ebp-8h] BYREF
  bool bIsFlexed; // [esp+5Eh] [ebp-2h]
  bool bIsHWSkinned; // [esp+5Fh] [ebp-1h]

  v4 = info;
  v5 = 0;
  v6 = pResults;
  pResults->m_TextureMemoryBytes = 0;
  pResults->m_ActualTriCount = 0;
  pResults->m_Materials.m_Size = 0;
  m_Lod = info->m_Lod;
  v39 = this;
  if ( m_Lod >= 0 )
  {
    m_pLODs = info->m_pHardwareData->m_pLODs;
    if ( m_pLODs != nullptr )
    {
      numbones = info->m_pStudioHdr->numbones;
      pStudioMeshes = m_pLODs[m_Lod].m_pMeshData;
      memset(&hardwareBonesUsed, 0, sizeof(hardwareBonesUsed));
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(this: &hardwareBonesUsed, num: numbones);
      for ( j = 0; j < info->m_pStudioHdr->numbones; ++j )
        hardwareBonesUsed.m_Memory.m_pMemory[j] = false;
      pResults->m_NumMaterials = 0;
      m_Skin = info->m_Skin;
      ppMaterials = info->m_pHardwareData->m_pLODs[info->m_Lod].ppMaterials;
      if ( m_Skin >= info->m_pStudioHdr->numskinfamilies )
        m_Skin = 0;
      v11 = (__int16 *)((char *)info->m_pStudioHdr
                      + 2 * m_Skin * info->m_pStudioHdr->numskinref
                      + info->m_pStudioHdr->skinindex);
      pResults->m_NumBatches = 0;
      m_pStudioHdr = info->m_pStudioHdr;
      pSkinRef = v11;
      i = 0;
      if ( m_pStudioHdr->numbodyparts > 0 )
      {
        do
        {
          m_Body = v4->m_Body;
          pModel = nullptr;
          R_StudioSetupModel(bodypart: v5, entity_body: m_Body, ppSubModel: &pModel, pStudioHdr: m_pStudioHdr);
          v13 = pModel;
          k = 0;
          if ( pModel->nummeshes > 0 )
          {
            v47 = 0;
            do
            {
              v14 = &v13->name[v13->meshindex + v47];
              m_pForcedMaterial = ppMaterials[pSkinRef[*(_DWORD *)v14]];
              v16 = *((_DWORD *)v14 + 8);
              v17 = pStudioMeshes[v16].m_NumGroup == 0;
              nNumVerts = (int)m_pForcedMaterial;
              pMeshData = &pStudioMeshes[v16];
              if ( !v17 )
              {
                if ( ++v6->m_NumMaterials < 8 )
                {
                  m_Size = v6->m_Materials.m_Size;
                  v6->m_Materials.m_Size = m_Size + 1;
                  v6->m_Materials.m_pElements = (IMaterial **)&v6->m_Materials;
                  v19 = (IMaterial **)((char *)&v6->m_Materials + 4 * m_Size);
                  v4 = info;
                  if ( v19 != nullptr )
                    *v19 = m_pForcedMaterial;
                }
                v20 = pSpewBuf;
                if ( pSpewBuf != nullptr )
                {
                  v21 = (const char *)m_pForcedMaterial->GetName(this: m_pForcedMaterial);
                  CUtlBuffer::Printf(this: v20, pFmt: "    material: %s\n", v21);
                  m_pForcedMaterial = (IMaterial *)nNumVerts;
                }
                if ( v39->m_RC.m_pForcedMaterial != nullptr )
                  m_pForcedMaterial = v39->m_RC.m_pForcedMaterial;
                v22 = m_pForcedMaterial->GetNumPasses(this: m_pForcedMaterial);
                numPasses = v22;
                if ( v20 != nullptr )
                  CUtlBuffer::Printf(this: v20, pFmt: "        numPasses:%d\n", v22);
                v23 = (*(int (__thiscall **)(int))(*(_DWORD *)nNumVerts + 144))(a1: nNumVerts);
                v6->m_TextureMemoryBytes += v23;
                if ( v20 != nullptr )
                  CUtlBuffer::Printf(
                    this: v20,
                    pFmt: "        texture memory: %d (Only valid in a rendering app)\n",
                    v23);
                stripGroupID = 0;
                if ( pMeshData->m_NumGroup > 0 )
                {
                  v49 = 0;
                  do
                  {
                    v24 = &pMeshData->m_pMeshGroup[v49 / 0x2C];
                    v25 = (v24->m_Flags & 2) != 0;
                    bIsFlexed = (v24->m_Flags & 4) != 0;
                    v26 = v25;
                    bIsHWSkinned = v25;
                    if ( v20 != nullptr )
                    {
                      CUtlBuffer::Printf(this: v20, pFmt: "        %d batch(es):\n", v24->m_NumStrips);
                      v26 = bIsHWSkinned;
                    }
                    stripID = 0;
                    if ( v24->m_NumStrips > 0 )
                    {
                      v50 = 0;
                      do
                      {
                        ++v6->m_NumBatches;
                        v27 = &v24->m_pStripData[v50 / 0x23];
                        if ( v26 )
                        {
                          for ( m = 0; m < v27->numBoneStateChanges; hardwareBonesUsed.m_Memory.m_pMemory[v29] = true )
                            v29 = *(int *)((char *)&v27->indexOffset + 8 * m++ + v27->boneStateChangeOffset);
                        }
                        v17 = (v27->flags & 6) == 0;
                        nNumVerts = 3;
                        if ( !v17 )
                          nNumVerts = 4;
                        v30 = v27->numIndices / nNumVerts;
                        if ( pSpewBuf != nullptr )
                        {
                          v17 = !v26;
                          v31 = "hwskinned ";
                          if ( v17 )
                            v31 = "swskinned ";
                          v32 = "flexed ";
                          if ( !bIsFlexed )
                            v32 = "nonflexed ";
                          CUtlBuffer::Printf(this: pSpewBuf, pFmt: "            %s%s", v32, v31);
                          if ( nNumVerts == 3 )
                            CUtlBuffer::Printf(this: pSpewBuf, pFmt: "tris: %d ", v30);
                          else
                            CUtlBuffer::Printf(this: pSpewBuf, pFmt: "quads: %d ", v30);
                          CUtlBuffer::Printf(
                            this: pSpewBuf,
                            pFmt: "bone changes: %d bones/strip: %d\n",
                            v27->numBoneStateChanges,
                            v27->numBones);
                          v26 = bIsHWSkinned;
                        }
                        pResults->m_ActualTriCount += numPasses * v30;
                        v50 += 35;
                        v6 = pResults;
                        ++stripID;
                      }
                      while ( stripID < v24->m_NumStrips );
                      v20 = pSpewBuf;
                    }
                    v49 += 44;
                    ++stripGroupID;
                  }
                  while ( stripGroupID < pMeshData->m_NumGroup );
                  v4 = info;
                }
                v13 = pModel;
              }
              v47 += 116;
              ++k;
            }
            while ( k < v13->nummeshes );
            v5 = i;
          }
          m_pStudioHdr = v4->m_pStudioHdr;
          i = ++v5;
        }
        while ( v5 < m_pStudioHdr->numbodyparts );
      }
      v33 = pSpewBuf;
      if ( pSpewBuf != nullptr )
      {
        HIBYTE(pSpewBuf) = 0;
        CUtlBuffer::Put(this: v33, pMem: (char *)&pSpewBuf + 3, size: 1);
      }
      v34 = 0;
      v6->m_NumHardwareBones = 0;
      if ( v4->m_pStudioHdr->numbones <= 0 )
      {
        m_pMemory = hardwareBonesUsed.m_Memory.m_pMemory;
      }
      else
      {
        do
        {
          m_pMemory = hardwareBonesUsed.m_Memory.m_pMemory;
          if ( hardwareBonesUsed.m_Memory.m_pMemory[v34] )
            ++v6->m_NumHardwareBones;
          ++v34;
        }
        while ( v34 < v4->m_pStudioHdr->numbones );
      }
      if ( hardwareBonesUsed.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100568B0
// Name: public: CStudioRenderContext::CStudioRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
CStudioRenderContext *__thiscall CStudioRenderContext::CStudioRenderContext(CStudioRenderContext *this)
{
  this->m_RC.m_ColorMod[2] = 1.0;
  this->m_RC.m_ColorMod[1] = 1.0;
  this->m_RC.m_ColorMod[0] = 1.0;
  this->m_RC.m_AlphaMod = 1.0;
  this->__vftable = (CStudioRenderContext_vtbl *)&CStudioRenderContext::`vftable';
  this->m_RC.m_pForcedMaterial = nullptr;
  this->m_RC.m_nForcedMaterialType = OVERRIDE_NORMAL;
  this->m_RC.m_ViewOrigin.x = 0.0;
  this->m_RC.m_ViewOrigin.y = 0.0;
  this->m_RC.m_ViewOrigin.z = 0.0;
  this->m_RC.m_ViewRight.x = 0.0;
  this->m_RC.m_ViewRight.y = 0.0;
  this->m_RC.m_ViewRight.z = 0.0;
  this->m_RC.m_ViewUp.x = 0.0;
  this->m_RC.m_ViewUp.y = 0.0;
  this->m_RC.m_ViewUp.z = 0.0;
  this->m_RC.m_ViewPlaneNormal.x = 0.0;
  this->m_RC.m_ViewPlaneNormal.y = 0.0;
  this->m_RC.m_ViewPlaneNormal.z = 0.0;
  *((_BYTE *)&this->m_RC.m_Config + 56) |= 4u;
  this->m_RC.m_NumLocalLights = 0;
  this->m_RC.m_LightBoxColors[0].x = 0.0;
  this->m_RC.m_LightBoxColors[1].x = 0.0;
  this->m_RC.m_LightBoxColors[0].y = 0.0;
  this->m_RC.m_LightBoxColors[0].z = 0.0;
  this->m_RC.m_LightBoxColors[0].w = 0.0;
  this->m_RC.m_LightBoxColors[1].y = 0.0;
  this->m_RC.m_LightBoxColors[1].z = 0.0;
  this->m_RC.m_LightBoxColors[1].w = 0.0;
  this->m_RC.m_LightBoxColors[2].x = 0.0;
  this->m_RC.m_LightBoxColors[2].y = 0.0;
  this->m_RC.m_LightBoxColors[2].z = 0.0;
  this->m_RC.m_LightBoxColors[2].w = 0.0;
  this->m_RC.m_LightBoxColors[3].x = 0.0;
  this->m_RC.m_LightBoxColors[3].y = 0.0;
  this->m_RC.m_LightBoxColors[3].z = 0.0;
  this->m_RC.m_LightBoxColors[3].w = 0.0;
  this->m_RC.m_LightBoxColors[4].x = 0.0;
  this->m_RC.m_LightBoxColors[4].y = 0.0;
  this->m_RC.m_LightBoxColors[4].z = 0.0;
  this->m_RC.m_LightBoxColors[4].w = 0.0;
  this->m_RC.m_LightBoxColors[5].x = 0.0;
  this->m_RC.m_LightBoxColors[5].y = 0.0;
  this->m_RC.m_LightBoxColors[5].z = 0.0;
  this->m_RC.m_LightBoxColors[5].w = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10058400
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100585D0
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

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
// Address: 0x100590E0
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050C70
// Name: __CreateCStudioRenderContextIStudioRender_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStudioRenderContext *__cdecl _CreateCStudioRenderContextIStudioRender_interface()
{
  return &s_StudioRenderContext;
}
