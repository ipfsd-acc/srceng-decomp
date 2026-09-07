// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/occlusionquerymgr.cpp
// Functions: 20
// ============================================================

#include "materialsystem\occlusionquerymgr.h"

//------------------------------------------------------------------------------
// Address: 0x10054440
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 40 * m_nGrowSize + 8);
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
// Address: 0x100544D0
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = m_pBlockHeader;
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
// Address: 0x10054550
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[5 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[5 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[5 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100545D0
// Name: public: void COcclusionQueryMgr::OnCreateOcclusionQueryObject(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQueryMgr::OnCreateOcclusionQueryObject(
        COcclusionQueryMgr *this,
        OcclusionQueryObjectHandle_t__ *h)
{
  int i; // esi

  for ( i = 0; i < 4; ++i )
    *((_DWORD *)h + i) = g_pShaderAPI->CreateOcclusionQueryObject(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10054600
// Name: public: void COcclusionQueryMgr::AllocOcclusionQueryObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQueryMgr::AllocOcclusionQueryObjects(COcclusionQueryMgr *this)
{
  int i; // edi
  int j; // esi

  for ( i = this->m_OcclusionQueryObjects.m_Head; i != 0; i = *(_DWORD *)(i + 36) )
  {
    for ( j = 0; j < 4; ++j )
    {
      *(_DWORD *)(i + 4 * j) = g_pShaderAPI->CreateOcclusionQueryObject(this: g_pShaderAPI);
      *(_BYTE *)(i + j + 28) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054640
// Name: public: void COcclusionQueryMgr::FreeOcclusionQueryObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQueryMgr::FreeOcclusionQueryObjects(COcclusionQueryMgr *this)
{
  int i; // edi
  int j; // esi
  ShaderAPIOcclusionQuery_t__ *v3; // ebx

  for ( i = this->m_OcclusionQueryObjects.m_Head; i != 0; i = *(_DWORD *)(i + 36) )
  {
    for ( j = 0; j < 4; ++j )
    {
      if ( *(_DWORD *)(i + 4 * j) != 0 )
      {
        if ( *(_BYTE *)(j + i + 28) != 0 )
        {
          v3 = *(ShaderAPIOcclusionQuery_t__ **)(i + 4 * j);
          while ( g_pShaderAPI->OcclusionQuery_GetNumPixelsRendered(this: g_pShaderAPI, a2: v3, a3: true) == -1 )
            ;
        }
        g_pShaderAPI->DestroyOcclusionQueryObject(this: g_pShaderAPI, a2: *(ShaderAPIOcclusionQuery_t__ **)(i + 4 * j));
        *(_DWORD *)(i + 4 * j) = 0;
        *(_BYTE *)(j + i + 28) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100546B0
// Name: public: void COcclusionQueryMgr::ResetOcclusionQueryObject(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQueryMgr::ResetOcclusionQueryObject(
        COcclusionQueryMgr *this,
        OcclusionQueryObjectHandle_t__ *hOcclusionQuery)
{
  OcclusionQueryObjectHandle_t__ *v2; // eax
  OcclusionQueryObjectHandle_t__ *v3; // esi
  OcclusionQueryObjectHandle_t__ *v4; // ebx
  ShaderAPIOcclusionQuery_t__ *v5; // edi
  int i; // [esp+0h] [ebp-4h]

  v2 = hOcclusionQuery;
  if ( hOcclusionQuery != nullptr
    && (*((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 8) != hOcclusionQuery
     || *((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 9) == hOcclusionQuery) )
  {
    v3 = hOcclusionQuery + 7;
    v4 = hOcclusionQuery;
    for ( i = 4; i != 0; --i )
    {
      if ( *(_BYTE *)v3 != 0 )
      {
        v5 = *(ShaderAPIOcclusionQuery_t__ **)v4;
        while ( g_pShaderAPI->OcclusionQuery_GetNumPixelsRendered(this: g_pShaderAPI, a2: v5, a3: true) == -1 )
          ;
        v2 = hOcclusionQuery;
      }
      *(_BYTE *)v3 = 0;
      ++v4;
      v3 = (OcclusionQueryObjectHandle_t__ *)((char *)v3 + 1);
    }
    *((_DWORD *)v2 + 4) = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054720
// Name: public: void COcclusionQueryMgr::BeginOcclusionQueryDrawing(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQueryMgr::BeginOcclusionQueryDrawing(
        COcclusionQueryMgr *this,
        OcclusionQueryObjectHandle_t__ *hOcclusionQuery)
{
  int v2; // ebx
  ShaderAPIOcclusionQuery_t__ *v3; // esi
  int v4; // eax
  int v5; // edx

  if ( hOcclusionQuery != nullptr
    && (*((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 8) != hOcclusionQuery
     || *((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 9) == hOcclusionQuery) )
  {
    v2 = *((_DWORD *)hOcclusionQuery + 6);
    v3 = *((ShaderAPIOcclusionQuery_t__ **)hOcclusionQuery + v2);
    if ( v3 != nullptr )
    {
      if ( *((_BYTE *)hOcclusionQuery + v2 + 28) != 0 )
      {
        v4 = g_pShaderAPI->OcclusionQuery_GetNumPixelsRendered(this: g_pShaderAPI, a2: v3, a3: false);
        if ( v4 == -1 )
        {
          if ( *((_DWORD *)hOcclusionQuery + 5) == this->m_nFrameCount )
          {
            v5 = s_nWarnCount++;
            if ( v5 < 5 )
              DevWarning(a1: "blocking issue in occlusion queries! Grab brian!\n");
          }
          do
            v4 = g_pShaderAPI->OcclusionQuery_GetNumPixelsRendered(this: g_pShaderAPI, a2: v3, a3: true);
          while ( v4 == -1 );
        }
        if ( v4 >= 0 )
          *((_DWORD *)hOcclusionQuery + 4) = v4;
        *((_BYTE *)hOcclusionQuery + v2 + 28) = 0;
      }
      g_pShaderAPI->BeginOcclusionQueryDrawing(this: g_pShaderAPI, a2: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100547E0
// Name: public: void COcclusionQueryMgr::EndOcclusionQueryDrawing(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQueryMgr::EndOcclusionQueryDrawing(
        COcclusionQueryMgr *this,
        OcclusionQueryObjectHandle_t__ *hOcclusionQuery)
{
  int v3; // edi

  if ( hOcclusionQuery != nullptr
    && (*((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 8) != hOcclusionQuery
     || *((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 9) == hOcclusionQuery) )
  {
    v3 = *((_DWORD *)hOcclusionQuery + 6);
    if ( *((_DWORD *)hOcclusionQuery + v3) != 0 )
    {
      g_pShaderAPI->EndOcclusionQueryDrawing(
        this: g_pShaderAPI,
        a2: *((ShaderAPIOcclusionQuery_t__ **)hOcclusionQuery + v3));
      *((_BYTE *)hOcclusionQuery + v3 + 28) = 1;
      hOcclusionQuery[5] = (OcclusionQueryObjectHandle_t__)this->m_nFrameCount;
      *((_DWORD *)hOcclusionQuery + 6) = (v3 + 1) % 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054840
// Name: public: void COcclusionQueryMgr::OcclusionQuery_IssueNumPixelsRenderedQuery(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQueryMgr::OcclusionQuery_IssueNumPixelsRenderedQuery(
        COcclusionQueryMgr *this,
        OcclusionQueryObjectHandle_t__ *hOcclusionQuery)
{
  int i; // ebx
  int v3; // esi
  ShaderAPIOcclusionQuery_t__ *v4; // eax
  int v5; // eax

  if ( hOcclusionQuery != nullptr
    && (*((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 8) != hOcclusionQuery
     || *((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 9) == hOcclusionQuery) )
  {
    for ( i = 0; i < 4; ++i )
    {
      v3 = (i + *((_DWORD *)hOcclusionQuery + 6)) % 4;
      v4 = *((ShaderAPIOcclusionQuery_t__ **)hOcclusionQuery + v3);
      if ( v4 != nullptr && *((_BYTE *)hOcclusionQuery + v3 + 28) != 0 )
      {
        v5 = g_pShaderAPI->OcclusionQuery_GetNumPixelsRendered(this: g_pShaderAPI, a2: v4, a3: false);
        if ( v5 >= 0 )
        {
          *((_DWORD *)hOcclusionQuery + 4) = v5;
          *((_BYTE *)hOcclusionQuery + v3 + 28) = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100548B0
// Name: public: int COcclusionQueryMgr::OcclusionQuery_GetNumPixelsRendered(struct OcclusionQueryObjectHandle_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COcclusionQueryMgr::OcclusionQuery_GetNumPixelsRendered(
        COcclusionQueryMgr *this,
        OcclusionQueryObjectHandle_t__ *h,
        bool bDoQuery)
{
  if ( bDoQuery )
    COcclusionQueryMgr::OcclusionQuery_IssueNumPixelsRenderedQuery(this, hOcclusionQuery: h);
  return *((_DWORD *)h + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100548E0
// Name: protected: int CUtlLinkedList<struct COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::AllocInternal(
        CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[4].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[4].m_nBlockSize = 0;
      result[4].m_pNext = nullptr;
    }
    else
    {
      result[4].m_nBlockSize = (int)result;
      result[4].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Next(
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
    CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Next(
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
      if ( `CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[5 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[5 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10054A70
// Name: public: void CUtlLinkedList<struct COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::RemoveAll(
        CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > > *this)
{
  CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

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
          i = CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::Next(
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
          if ( &m_pBlockHeader[5 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[5 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[5 * m_nIndex + 5].m_pNext == &m_pBlockHeader[5 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *)m_pBlockHeader[5 * m_nIndex + 5].m_nBlockSize != &m_pBlockHeader[5 * m_nIndex + 1] )
          {
            v1 = (CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[5 * m_nIndex + 5].m_pNext = &m_pBlockHeader[5 * m_nIndex + 1];
            m_pBlockHeader[5 * m_nIndex + 5].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[5 * m_nIndex + 1];
            v1 = (CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > > *)v5;
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
// Address: 0x10054B40
// Name: public: void CUtlLinkedList<struct COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::LinkBefore(
        CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 32);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 36) = *(_DWORD *)(elem + 36);
      else
        this->m_Head = *(_DWORD *)(elem + 36);
      v5 = *(_DWORD *)(elem + 36);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 32) = *(_DWORD *)(elem + 32);
      else
        this->m_Tail = *(_DWORD *)(elem + 32);
      *(_DWORD *)(elem + 36) = elem;
      *(_DWORD *)(elem + 32) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 36) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 32);
    *(_DWORD *)(before + 32) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 32) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 36) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054BD0
// Name: public: int CUtlLinkedList<struct COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::InsertBefore(
        CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> > > *this,
        int before)
{
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *v4; // esi
  int i; // eax

  result = CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != nullptr )
  {
    CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::LinkBefore(
      this,
      before,
      elem: (int)result);
    for ( i = 0; i < 4; ++i )
    {
      *((_DWORD *)&v4->m_pNext + i) = 0;
      *((_BYTE *)&v4[3].m_nBlockSize + i) = 0;
    }
    v4[2].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *)-1;
    v4[2].m_nBlockSize = -1;
    v4[3].m_pNext = nullptr;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054C30
// Name: public: void COcclusionQueryMgr::DestroyOcclusionQueryObject(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQueryMgr::DestroyOcclusionQueryObject(
        COcclusionQueryMgr *this,
        OcclusionQueryObjectHandle_t__ *hOcclusionQuery)
{
  int i; // ebx
  ShaderAPIOcclusionQuery_t__ *v3; // edi
  CThreadFastMutex *p_m_Mutex; // edi
  DWORD CurrentThreadId; // eax
  OcclusionQueryObjectHandle_t__ *v6; // eax
  OcclusionQueryObjectHandle_t__ *v7; // eax

  if ( hOcclusionQuery != nullptr
    && (*((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 8) != hOcclusionQuery
     || *((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 9) == hOcclusionQuery) )
  {
    for ( i = 0; i < 4; ++i )
    {
      v3 = *((ShaderAPIOcclusionQuery_t__ **)hOcclusionQuery + i);
      if ( v3 != nullptr )
      {
        if ( *((_BYTE *)hOcclusionQuery + i + 28) != 0 )
        {
          while ( g_pShaderAPI->OcclusionQuery_GetNumPixelsRendered(this: g_pShaderAPI, a2: v3, a3: true) == -1 )
            ;
        }
        g_pShaderAPI->DestroyOcclusionQueryObject(
          this: g_pShaderAPI,
          a2: *((ShaderAPIOcclusionQuery_t__ **)hOcclusionQuery + i));
      }
    }
    p_m_Mutex = &this->m_Mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_Mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_Mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_Mutex.m_depth;
    }
    if ( !CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>::IsIdxAfter(
            this: &this->m_OcclusionQueryObjects.m_Memory,
            i: (unsigned int)hOcclusionQuery,
            it: &this->m_OcclusionQueryObjects.m_LastAlloc) )
    {
      v6 = *((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 8);
      if ( v6 != hOcclusionQuery )
      {
        if ( v6 != nullptr )
          v6[9] = hOcclusionQuery[9];
        else
          this->m_OcclusionQueryObjects.m_Head = (int)hOcclusionQuery[9];
        v7 = *((OcclusionQueryObjectHandle_t__ **)hOcclusionQuery + 9);
        if ( v7 != nullptr )
          v7[8] = hOcclusionQuery[8];
        else
          this->m_OcclusionQueryObjects.m_Tail = (int)hOcclusionQuery[8];
        *((_DWORD *)hOcclusionQuery + 9) = hOcclusionQuery;
        *((_DWORD *)hOcclusionQuery + 8) = hOcclusionQuery;
        --this->m_OcclusionQueryObjects.m_ElementCount;
      }
    }
    hOcclusionQuery[9] = (OcclusionQueryObjectHandle_t__)this->m_OcclusionQueryObjects.m_FirstFree;
    this->m_OcclusionQueryObjects.m_FirstFree = (int)hOcclusionQuery;
    if ( this->m_Mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054D50
// Name: public: struct OcclusionQueryObjectHandle_t__ __near * COcclusionQueryMgr::CreateOcclusionQueryObject(void)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *__thiscall COcclusionQueryMgr::CreateOcclusionQueryObject(
        COcclusionQueryMgr *this)
{
  CThreadFastMutex *p_m_Mutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *result; // eax

  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_Mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_Mutex->m_depth;
  }
  result = CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::InsertBefore(
             this: &this->m_OcclusionQueryObjects,
             before: 0);
  if ( p_m_Mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10252520
// Name: protected: unsigned short CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>::Grow(
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
      if ( `CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x102526A0
// Name: public: void CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // eax
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
// Address: 0x10252730
// Name: public: void CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v7; // ebx

  CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::Unlink(
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
