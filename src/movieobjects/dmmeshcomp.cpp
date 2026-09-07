// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmmeshcomp.cpp
// Functions: 9
// ============================================================

#include "movieobjects\dmmeshcomp.h"

//------------------------------------------------------------------------------
// Address: 0x00566B10
// Name: public: int CDmMeshComp::CVert::PositionIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmMeshComp::CVert::PositionIndex(CDmMeshComp::CVert *this)
{
  return this->m_positionIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00566BC0
// Name: public: bool CDmMeshComp::CEdge::operator==(class CDmMeshComp::CEdge const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmMeshComp::CEdge::operator==(CDmMeshComp::CEdge *this, const CDmMeshComp::CEdge *rhs)
{
  const Vector *m_pPosition; // edx
  const Vector *v3; // eax
  const Vector *v4; // esi
  const Vector *v5; // edi
  const Vector *v6; // esi
  const Vector *v7; // eax
  BOOL result; // eax

  m_pPosition = rhs->m_pVert0->m_pPosition;
  v3 = this->m_pVert0->m_pPosition;
  result = true;
  if ( (float)((float)((float)((float)(v3->y - m_pPosition->y) * (float)(v3->y - m_pPosition->y))
                     + (float)((float)(v3->x - m_pPosition->x) * (float)(v3->x - m_pPosition->x)))
             + (float)((float)(v3->z - m_pPosition->z) * (float)(v3->z - m_pPosition->z))) >= 0.00000011920929
    || (v4 = rhs->m_pVert1->m_pPosition,
        (float)((float)((float)((float)((v5 = this->m_pVert1->m_pPosition)->y - v4->y) * (float)(v5->y - v4->y))
                      + (float)((float)(v5->x - v4->x) * (float)(v5->x - v4->x)))
              + (float)((float)(v5->z - v4->z) * (float)(v5->z - v4->z))) >= 0.00000011920929) )
  {
    v6 = rhs->m_pVert1->m_pPosition;
    if ( (float)((float)((float)((float)(v3->y - v6->y) * (float)(v3->y - v6->y))
                       + (float)((float)(v3->x - v6->x) * (float)(v3->x - v6->x)))
               + (float)((float)(v3->z - v6->z) * (float)(v3->z - v6->z))) >= 0.00000011920929 )
      return false;
    v7 = this->m_pVert1->m_pPosition;
    if ( (float)((float)((float)((float)(v7->y - m_pPosition->y) * (float)(v7->y - m_pPosition->y))
                       + (float)((float)(v7->x - m_pPosition->x) * (float)(v7->x - m_pPosition->x)))
               + (float)((float)(v7->z - m_pPosition->z) * (float)(v7->z - m_pPosition->z))) >= 0.00000011920929 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00566DF0
// Name: public: class CDmMeshComp::CEdge __near * CDmMeshComp::FindEdge(int,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CDmMeshComp::CEdge *__thiscall CDmMeshComp::FindEdge(CDmMeshComp *this, int vIndex0, int vIndex1, bool *pReverse)
{
  int v4; // ebx
  CDmMeshComp::CVert *v5; // eax
  int v6; // esi
  CDmMeshComp::CEdge **i; // edi
  CDmMeshComp::CEdge *result; // eax
  CDmMeshComp::CVert *m_pVert0; // edx
  int v10; // ecx
  CDmMeshComp::CVert *v11; // ecx
  int v12; // ecx
  CDmMeshComp::CVert *m_pVert1; // ecx
  int m_positionIndex; // ecx
  int v15; // ecx
  int m_Size; // [esp+Ch] [ebp-4h]

  v4 = vIndex0;
  v5 = this->m_verts.m_Memory.m_pMemory[vIndex0];
  v6 = 0;
  m_Size = v5->m_edges.m_Size;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = v5->m_edges.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    m_pVert0 = (*i)->m_pVert0;
    v10 = m_pVert0 != nullptr ? m_pVert0->m_positionIndex : -1;
    if ( v10 == v4 )
      break;
LABEL_12:
    m_pVert1 = result->m_pVert1;
    if ( m_pVert1 != nullptr )
      m_positionIndex = m_pVert1->m_positionIndex;
    else
      m_positionIndex = -1;
    if ( m_positionIndex == v4 )
    {
      v15 = m_pVert0 != nullptr ? m_pVert0->m_positionIndex : -1;
      if ( v15 == vIndex1 )
      {
        if ( pReverse != nullptr )
          *pReverse = true;
        return result;
      }
    }
    if ( ++v6 >= m_Size )
      return nullptr;
  }
  v11 = result->m_pVert1;
  if ( v11 != nullptr )
    v12 = v11->m_positionIndex;
  else
    v12 = -1;
  if ( v12 != vIndex1 )
  {
    v4 = vIndex0;
    goto LABEL_12;
  }
  if ( pReverse != nullptr )
    *pReverse = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005671F0
// Name: public: class CDmMeshComp::CEdge __near * CDmMeshComp::FindOrCreateEdge(int,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CDmMeshComp::CEdge *__thiscall CDmMeshComp::FindOrCreateEdge(
        CDmMeshComp *this,
        int vIndex0,
        int vIndex1,
        bool *pReverse)
{
  CDmMeshComp::CEdge *result; // eax
  CDmMeshComp::CVert **m_pMemory; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // ebx
  CDmMeshComp::CEdge *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmMeshComp::CEdge **v11; // ecx
  int v12; // eax
  CDmMeshComp::CEdge **v13; // ecx
  CDmMeshComp::CEdge *v14; // edx
  CUtlSymbolTable::StringPool_t **v15; // edi
  int v16; // eax
  CUtlSymbolTable::StringPool_t **v17; // ecx
  int v18; // eax
  CDmMeshComp::CEdge **v19; // eax
  CUtlSymbolTable::StringPool_t **v20; // edi
  int v21; // eax
  CUtlSymbolTable::StringPool_t **v22; // ecx
  int v23; // eax
  CDmMeshComp::CEdge **v24; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *pVert1; // [esp+Ch] [ebp-8h]
  CDmMeshComp::CEdge *pEdge; // [esp+10h] [ebp-4h]
  CDmMeshComp::CEdge *pEdgea; // [esp+10h] [ebp-4h]

  result = CDmMeshComp::FindEdge(this, vIndex0, vIndex1, pReverse);
  if ( result == nullptr )
  {
    m_pMemory = this->m_verts.m_Memory.m_pMemory;
    v7 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)m_pMemory[vIndex0];
    if ( v7 != nullptr && (pVert1 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)m_pMemory[vIndex1]) != nullptr )
    {
      v8 = (CDmMeshComp::CEdge *)operator new(nSize: 0xCu);
      if ( v8 != nullptr )
      {
        v8->m_pVert0 = nullptr;
        v8->m_pVert1 = nullptr;
        v8->m_faceCount = 0;
        pEdge = v8;
      }
      else
      {
        pEdge = nullptr;
      }
      m_Size = this->m_edges.m_Size;
      m_nAllocationCount = this->m_edges.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_edges,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_edges.m_Size;
      v11 = this->m_edges.m_Memory.m_pMemory;
      v12 = this->m_edges.m_Size - m_Size - 1;
      this->m_edges.m_pElements = v11;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = &this->m_edges.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pEdge;
      v14 = this->m_edges.m_Memory.m_pMemory[m_Size];
      v14->m_pVert0 = (CDmMeshComp::CVert *)v7;
      v14->m_pVert1 = (CDmMeshComp::CVert *)pVert1;
      v15 = v7[2].m_pMemory;
      v16 = v7[1].m_nAllocationCount;
      pEdgea = v14;
      if ( (int)v15 + 1 > v16 )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7 + 1, num: (int)v15 - v16 + 1);
        v14 = pEdgea;
      }
      ++v7[2].m_pMemory;
      v17 = v7[1].m_pMemory;
      v18 = (char *)v7[2].m_pMemory - (char *)v15 - 1;
      v7[2].m_nAllocationCount = (int)v17;
      if ( v18 > 0 )
      {
        _V_memmove(dest: &v17[(_DWORD)v15 + 1], src: &v17[(_DWORD)v15], count: 4 * v18);
        v14 = pEdgea;
      }
      v19 = (CDmMeshComp::CEdge **)&v7[1].m_pMemory[(_DWORD)v15];
      if ( v19 != nullptr )
        *v19 = v14;
      if ( vIndex0 != vIndex1 )
      {
        v20 = pVert1[2].m_pMemory;
        v21 = pVert1[1].m_nAllocationCount;
        if ( (int)v20 + 1 > v21 )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: pVert1 + 1, num: (int)v20 - v21 + 1);
          v14 = pEdgea;
        }
        ++pVert1[2].m_pMemory;
        v22 = pVert1[1].m_pMemory;
        v23 = (char *)pVert1[2].m_pMemory - (char *)v20 - 1;
        pVert1[2].m_nAllocationCount = (int)v22;
        if ( v23 > 0 )
        {
          _V_memmove(dest: &v22[(_DWORD)v20 + 1], src: &v22[(_DWORD)v20], count: 4 * v23);
          v14 = pEdgea;
        }
        v24 = (CDmMeshComp::CEdge **)&pVert1[1].m_pMemory[(_DWORD)v20];
        if ( v24 != nullptr )
          *v24 = v14;
      }
      if ( pReverse != nullptr )
        *pReverse = false;
      return v14;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00567390
// Name: public: int CDmMeshComp::FindNeighbouringVerts(int,class CUtlVector<class CDmMeshComp::CVert __near *,class CUtlMemory<class CDmMeshComp::CVert __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTable::StringPool_t **__thiscall CDmMeshComp::FindNeighbouringVerts(
        CDmMeshComp *this,
        int vIndex,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *verts)
{
  CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *p_m_edges; // eax
  int v5; // ecx
  CDmMeshComp::CEdge *v6; // eax
  CDmMeshComp::CVert *m_pVert0; // ebx
  int m_positionIndex; // ecx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmMeshComp::CVert **v11; // ecx
  int v12; // eax
  CDmMeshComp::CVert **v13; // eax
  int v14; // eax
  CDmMeshComp::CVert **v15; // ecx
  int v16; // eax
  const CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *edges; // [esp+4h] [ebp-4h]
  int i; // [esp+14h] [ebp+Ch]

  verts[1].m_pMemory = nullptr;
  p_m_edges = &this->m_verts.m_Memory.m_pMemory[vIndex]->m_edges;
  v5 = 0;
  edges = p_m_edges;
  for ( i = 0; v5 < edges->m_Size; i = v5 )
  {
    v6 = p_m_edges->m_Memory.m_pMemory[v5];
    m_pVert0 = v6->m_pVert0;
    if ( v6->m_pVert0 != nullptr )
      m_positionIndex = m_pVert0->m_positionIndex;
    else
      m_positionIndex = -1;
    m_pMemory = (int)verts[1].m_pMemory;
    if ( m_positionIndex == vIndex )
    {
      m_pVert0 = v6->m_pVert1;
      m_nAllocationCount = verts->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: verts, num: m_pMemory - m_nAllocationCount + 1);
      ++verts[1].m_pMemory;
      v11 = (CDmMeshComp::CVert **)verts->m_pMemory;
      v12 = (int)verts[1].m_pMemory - m_pMemory - 1;
      verts[1].m_nAllocationCount = (int)verts->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_pMemory + 1], src: &v11[m_pMemory], count: 4 * v12);
      v13 = (CDmMeshComp::CVert **)&verts->m_pMemory[m_pMemory];
    }
    else
    {
      v14 = verts->m_nAllocationCount;
      if ( m_pMemory + 1 > v14 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: verts, num: m_pMemory - v14 + 1);
      ++verts[1].m_pMemory;
      v15 = (CDmMeshComp::CVert **)verts->m_pMemory;
      v16 = (int)verts[1].m_pMemory - m_pMemory - 1;
      verts[1].m_nAllocationCount = (int)verts->m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v15[m_pMemory + 1], src: &v15[m_pMemory], count: 4 * v16);
      v13 = (CDmMeshComp::CVert **)&verts->m_pMemory[m_pMemory];
    }
    if ( v13 != nullptr )
      *v13 = m_pVert0;
    p_m_edges = (CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *)edges;
    v5 = i + 1;
  }
  return verts[1].m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00567550
// Name: public: int CDmMeshComp::GetBorderEdges(class CUtlVector<class CUtlVector<class CDmMeshComp::CEdge __near *,class CUtlMemory<class CDmMeshComp::CEdge __near *,int>>,class CUtlMemory<class CUtlVector<class CDmMeshComp::CEdge __near *,class CUtlMemory<class CDmMeshComp::CEdge __near *,int>>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmMeshComp::GetBorderEdges(
        CDmMeshComp *this,
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *borderEdgesList)
{
  CUtlMemory<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,int> *v2; // edi
  CDmMeshComp *v3; // esi
  int v4; // eax
  CDmMeshComp::CEdge *v5; // ebx
  int v6; // ecx
  int v7; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v8; // esi
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // ebx
  CDmMeshComp::CVert *m_TotalLen; // ecx
  CDmMeshComp::CVert *m_pVert1; // edi
  CDmMeshComp::CVert *m_SpaceUsed; // edx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v16; // ecx
  int v17; // eax
  CDmMeshComp::CEdge **v18; // eax
  int v19; // esi
  int v20; // eax
  CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *v21; // ecx
  int v22; // eax
  int v23; // ecx
  CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *v24; // eax
  int m_Size; // ebx
  int v26; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v27; // esi
  CUtlSymbolTable::StringPool_t **v28; // ecx
  int v29; // eax
  CDmMeshComp::CEdge **v30; // ebx
  int v31; // eax
  int v32; // eax
  CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *v33; // ebx
  int v34; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v35; // esi
  CUtlSymbolTable::StringPool_t **v36; // edi
  char *v37; // eax
  CDmMeshComp::CVert *v38; // ecx
  CDmMeshComp::CVert *v39; // ebx
  CDmMeshComp::CVert *v40; // edx
  int *v41; // esi
  bool v42; // sf
  void *v43; // eax
  int v45; // eax
  CUtlSymbolTable::StringPool_t **v46; // ecx
  int v47; // eax
  CDmMeshComp::CEdge **v48; // edi
  CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *srcBorderEdges; // [esp+Ch] [ebp-2Ch]
  CDmMeshComp::CVert *m_pVert0; // [esp+10h] [ebp-28h]
  int j; // [esp+14h] [ebp-24h]
  int ja; // [esp+14h] [ebp-24h]
  int v54; // [esp+18h] [ebp-20h]
  int v55; // [esp+18h] [ebp-20h]
  int k; // [esp+1Ch] [ebp-1Ch]
  int ka; // [esp+1Ch] [ebp-1Ch]
  CDmMeshComp::CEdge *pSrcEdge; // [esp+20h] [ebp-18h]
  CUtlSymbolTable::StringPool_t **v59; // [esp+24h] [ebp-14h]
  int retVal; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int ia; // [esp+2Ch] [ebp-Ch]
  CDmMeshComp::CEdge *pEdge; // [esp+30h] [ebp-8h]
  CDmMeshComp::CEdge *pEdgea; // [esp+30h] [ebp-8h]
  bool anyConnected; // [esp+36h] [ebp-2h]
  bool connected; // [esp+37h] [ebp-1h]
  bool connecteda; // [esp+37h] [ebp-1h]

  v2 = (CUtlMemory<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,int> *)borderEdgesList;
  v3 = this;
  retVal = 0;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: borderEdgesList);
  v4 = 0;
  k = 0;
  if ( v3->m_edges.m_Size > 0 )
  {
    do
    {
      v5 = v3->m_edges.m_Memory.m_pMemory[v4];
      pEdge = v5;
      if ( v5->m_faceCount == 1 )
      {
        ++retVal;
        v6 = (int)&v2[1].m_pMemory[-1].m_pElements + 3;
        v7 = 20 * v6;
        connected = false;
        i = v6;
        v54 = 20 * v6;
        while ( v6 >= 0 )
        {
          v8 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)((char *)v2->m_pMemory + v7);
          v9 = (int)v8[1].m_pMemory - 1;
          if ( v9 >= 0 )
          {
            j = (int)v5->m_pVert0;
            v10 = &v8->m_pMemory[v9];
            while ( 1 )
            {
              m_TotalLen = (CDmMeshComp::CVert *)(*v10)->m_TotalLen;
              if ( m_TotalLen == (CDmMeshComp::CVert *)j )
                break;
              m_pVert1 = pEdge->m_pVert1;
              if ( m_TotalLen == m_pVert1 )
                break;
              m_SpaceUsed = (CDmMeshComp::CVert *)(*v10)->m_SpaceUsed;
              if ( m_SpaceUsed == (CDmMeshComp::CVert *)j || m_SpaceUsed == m_pVert1 )
                break;
              --v10;
              if ( --v9 < 0 )
                goto LABEL_21;
            }
            m_pMemory = v8[1].m_pMemory;
            m_nAllocationCount = v8->m_nAllocationCount;
            if ( (int)m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: (int)m_pMemory - m_nAllocationCount + 1);
            ++v8[1].m_pMemory;
            v16 = v8->m_pMemory;
            v17 = (char *)v8[1].m_pMemory - (char *)m_pMemory - 1;
            v8[1].m_nAllocationCount = (int)v8->m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[(_DWORD)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 4 * v17);
            v18 = (CDmMeshComp::CEdge **)&v8->m_pMemory[(_DWORD)m_pMemory];
            if ( v18 != nullptr )
              *v18 = pEdge;
            connected = true;
LABEL_21:
            v6 = i;
            v2 = (CUtlMemory<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,int> *)borderEdgesList;
          }
          --v6;
          v7 = v54 - 20;
          i = v6;
          v54 -= 20;
          if ( connected )
            goto LABEL_36;
          v5 = pEdge;
        }
        v19 = (int)v2[1].m_pMemory;
        v20 = v2->m_nAllocationCount;
        if ( v19 + 1 > v20 )
          CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
            this: v2,
            num: v19 - v20 + 1);
        ++v2[1].m_pMemory;
        v21 = v2->m_pMemory;
        v22 = (int)v2[1].m_pMemory - v19 - 1;
        v2[1].m_nAllocationCount = (int)v2->m_pMemory;
        if ( v22 > 0 )
          _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 20 * v22);
        v23 = v19;
        v24 = &v2->m_pMemory[v19];
        if ( v24 != nullptr )
        {
          v24->m_Memory.m_pMemory = nullptr;
          v24->m_Memory.m_nAllocationCount = 0;
          v24->m_Memory.m_nGrowSize = 0;
          v24->m_Size = 0;
          v24->m_pElements = nullptr;
        }
        m_Size = v2->m_pMemory[v23].m_Size;
        v26 = v2->m_pMemory[v23].m_Memory.m_nAllocationCount;
        v27 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_pMemory[v23];
        if ( m_Size + 1 > v26 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v27, num: m_Size - v26 + 1);
        ++v27[1].m_pMemory;
        v28 = v27->m_pMemory;
        v29 = (int)v27[1].m_pMemory - m_Size - 1;
        v27[1].m_nAllocationCount = (int)v27->m_pMemory;
        if ( v29 > 0 )
          _V_memmove(dest: &v28[m_Size + 1], src: &v28[m_Size], count: 4 * v29);
        v30 = (CDmMeshComp::CEdge **)&v27->m_pMemory[m_Size];
        if ( v30 != nullptr )
          *v30 = pEdge;
      }
LABEL_36:
      v3 = this;
      v4 = k + 1;
      k = v4;
    }
    while ( v4 < this->m_edges.m_Size );
  }
  do
  {
    v31 = (int)&v2[1].m_pMemory[-1].m_pElements + 3;
    anyConnected = false;
    pEdgea = (CDmMeshComp::CEdge *)v31;
    if ( v31 < 0 )
      break;
    v32 = 20 * v31;
    ia = v32;
    do
    {
      v33 = (CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *)((char *)v2->m_pMemory + v32);
      v34 = v33->m_Size - 1;
      srcBorderEdges = v33;
      for ( ja = v34; ja >= 0; --ja )
      {
        pSrcEdge = v33->m_Memory.m_pMemory[v34];
        connecteda = false;
        ka = 0;
        v55 = 0;
        do
        {
          if ( ka >= (int)pEdgea )
            break;
          v35 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_pMemory[v55];
          v36 = v35[1].m_pMemory;
          v37 = (char *)v36 - 1;
          if ( (int)v36 - 1 >= 0 )
          {
            m_pVert0 = pSrcEdge->m_pVert0;
            v59 = &v35->m_pMemory[(_DWORD)v37];
            while ( 1 )
            {
              v38 = (CDmMeshComp::CVert *)(*v59)->m_TotalLen;
              if ( v38 == m_pVert0 )
                break;
              v39 = pSrcEdge->m_pVert1;
              if ( v38 == v39 )
                break;
              v40 = (CDmMeshComp::CVert *)(*v59)->m_SpaceUsed;
              if ( v40 == m_pVert0 || v40 == v39 )
                break;
              --v59;
              if ( (int)--v37 < 0 )
              {
                v33 = srcBorderEdges;
                goto LABEL_50;
              }
            }
            v45 = v35->m_nAllocationCount;
            connecteda = true;
            anyConnected = true;
            if ( (int)v36 + 1 > v45 )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v35, num: (int)v36 - v45 + 1);
            ++v35[1].m_pMemory;
            v46 = v35->m_pMemory;
            v47 = (char *)v35[1].m_pMemory - (char *)v36 - 1;
            v35[1].m_nAllocationCount = (int)v35->m_pMemory;
            if ( v47 > 0 )
              _V_memmove(dest: &v46[(_DWORD)v36 + 1], src: &v46[(_DWORD)v36], count: 4 * v47);
            v48 = (CDmMeshComp::CEdge **)&v35->m_pMemory[(_DWORD)v36];
            if ( v48 != nullptr )
              *v48 = pSrcEdge;
            v33 = srcBorderEdges;
            if ( srcBorderEdges->m_Size - ja - 1 > 0 )
              _V_memmove(
                dest: &srcBorderEdges->m_Memory.m_pMemory[ja],
                src: &srcBorderEdges->m_Memory.m_pMemory[ja + 1],
                count: 4 * (srcBorderEdges->m_Size - ja - 1));
            --srcBorderEdges->m_Size;
          }
LABEL_50:
          ++ka;
          ++v55;
          v2 = (CUtlMemory<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,int> *)borderEdgesList;
        }
        while ( !connecteda );
        v34 = ja - 1;
      }
      if ( v33->m_Size == 0 )
      {
        v41 = (int *)((char *)v2->m_pMemory + ia);
        v42 = v41[2] < 0;
        v41[3] = 0;
        if ( !v42 )
        {
          if ( *v41 != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v41);
            *v41 = 0;
          }
          v41[1] = 0;
        }
        v42 = v41[2] < 0;
        v43 = (void *)*v41;
        v41[4] = *v41;
        if ( !v42 )
        {
          if ( v43 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v43);
            *v41 = 0;
          }
          v41[1] = 0;
        }
        if ( (char *)v2[1].m_pMemory - (char *)pEdgea - 1 > 0 )
          _V_memmove(
            dest: (char *)v2->m_pMemory + ia,
            src: (char *)&v2->m_pMemory[1] + ia,
            count: 20 * ((char *)v2[1].m_pMemory - (char *)pEdgea - 1));
        --v2[1].m_pMemory;
      }
      v32 = ia - 20;
      pEdgea = (CDmMeshComp::CEdge *)((char *)pEdgea - 1);
      ia -= 20;
    }
    while ( (int)pEdgea >= 0 );
  }
  while ( anyConnected );
  return retVal;
}

//------------------------------------------------------------------------------
// Address: 0x00567A50
// Name: public: class CDmMeshComp::CFace __near * CDmMeshComp::CreateFace(class CUtlVector<class CDmMeshComp::CVert __near *,class CUtlMemory<class CDmMeshComp::CVert __near *,int>> const __near &,class CUtlVector<class CDmMeshComp::CEdge __near *,class CUtlMemory<class CDmMeshComp::CEdge __near *,int>> const __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmMeshComp::CFace *__thiscall CDmMeshComp::CreateFace(
        CDmMeshComp *this,
        const CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *verts,
        const CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *edges,
        const CUtlVector<bool,CUtlMemory<bool,int> > *edgeReverseMap)
{
  CUtlFixedLinkedList<CDmMeshComp::CFace> *p_m_faces; // ebx
  int v5; // eax
  int v6; // esi
  int i; // eax

  p_m_faces = &this->m_faces;
  v5 = CUtlLinkedList<CDmMeshComp::CFace,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CDmMeshComp::CFace,int>>>::AllocInternal(
         this: &this->m_faces,
         multilist: false);
  v6 = v5;
  if ( v5 != 0 )
  {
    CUtlLinkedList<CDmMeshComp::CFace,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CDmMeshComp::CFace,int>>>::LinkBefore(
      this: p_m_faces,
      before: 0,
      elem: v5);
    *(_DWORD *)v6 = 0;
    *(_DWORD *)(v6 + 4) = 0;
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 12) = 0;
    *(_DWORD *)(v6 + 16) = 0;
    *(_DWORD *)(v6 + 20) = 0;
    *(_DWORD *)(v6 + 24) = 0;
    *(_DWORD *)(v6 + 28) = 0;
    *(_DWORD *)(v6 + 32) = 0;
    *(_DWORD *)(v6 + 36) = 0;
    *(_DWORD *)(v6 + 40) = 0;
    *(_DWORD *)(v6 + 44) = 0;
    *(_DWORD *)(v6 + 48) = 0;
    *(_DWORD *)(v6 + 52) = 0;
    *(_DWORD *)(v6 + 56) = 0;
  }
  else
  {
    v6 = 0;
  }
  *(_DWORD *)(v6 + 12) = 0;
  CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int>>::AddVectorToTail(
    this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)v6,
    src: verts);
  *(_DWORD *)(v6 + 32) = 0;
  CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int>>::AddVectorToTail(
    this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)(v6 + 20),
    src: (const CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)edges);
  *(_DWORD *)(v6 + 52) = 0;
  CUtlVector<bool,CUtlMemory<bool,int>>::AddVectorToTail(
    this: (CUtlVector<bool,CUtlMemory<bool,int> > *)(v6 + 40),
    src: edgeReverseMap);
  for ( i = edges->m_Size - 1; i >= 0; --i )
    ++edges->m_Memory.m_pMemory[i]->m_faceCount;
  return (CDmMeshComp::CFace *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x00567B00
// Name: public: CDmMeshComp::~CDmMeshComp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmMeshComp::~CDmMeshComp(CDmMeshComp *this)
{
  CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *p_m_verts; // ebx
  CUtlFixedLinkedList<CDmMeshComp::CFace> *p_m_faces; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CDmMeshComp::CFace,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CDmMeshComp::CFace,int> >::BlockHeader_t *v5; // [esp-4h] [ebp-14h]
  CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *p_m_edges; // [esp+Ch] [ebp-4h]

  p_m_verts = (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_verts;
  CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int>>::PurgeAndDeleteElements(this: &this->m_verts);
  p_m_edges = (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_edges;
  CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int>>::PurgeAndDeleteElements(this: &this->m_edges);
  p_m_faces = &this->m_faces;
  CUtlLinkedList<CDmMeshComp::CFace,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CDmMeshComp::CFace,int>>>::RemoveAll(this: &this->m_faces);
  m_pBlocks = p_m_faces->m_Memory.m_pBlocks;
  if ( p_m_faces->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    p_m_faces->m_Memory.m_pBlocks = nullptr;
    p_m_faces->m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: p_m_edges);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: p_m_verts);
}

//------------------------------------------------------------------------------
// Address: 0x00567B70
// Name: public: CDmMeshComp::CDmMeshComp(class CDmeMesh __near *,class CDmeVertexData __near *)
// Source: json
//------------------------------------------------------------------------------
CDmMeshComp *__thiscall CDmMeshComp::CDmMeshComp(CDmMeshComp *this, CDmeMesh *pMesh, CDmeVertexData *pPassedBase)
{
  CDmeVertexData *CurrentBaseState; // eax
  CDmMeshComp *v4; // ebx
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // eax
  CDmeVertexDataBase *m_pBase; // ecx
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  const CUtlVector<int,CUtlMemory<int,int> > *v10; // edx
  void *v11; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CDmMeshComp::CVert **m_pMemory; // ecx
  int v15; // eax
  int *v16; // esi
  int v17; // eax
  const CUtlVector<int,CUtlMemory<int,int> > *v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  CDmMeshComp::CEdge **v22; // edx
  CDmMeshComp::CEdge **v23; // eax
  CDmMeshComp::CEdge **v24; // ecx
  int v25; // esi
  int v26; // ecx
  int v27; // edi
  int v28; // eax
  int v29; // eax
  int v30; // edi
  CDmMeshComp::CEdge **v31; // eax
  int v32; // esi
  int *v33; // edi
  int v34; // eax
  int v35; // esi
  bool *v36; // edi
  int v37; // eax
  CDmMeshComp::CVert **v38; // edx
  int v39; // ecx
  CDmMeshComp::CVert **v40; // ecx
  int v41; // ecx
  CDmMeshComp::CVert **v42; // eax
  int v43; // ebx
  CDmMeshComp::CVert **v44; // ecx
  CDmMeshComp::CVert **v45; // ebx
  int v46; // ebx
  CDmMeshComp::CEdge **v47; // ecx
  CDmMeshComp::CEdge **v48; // ebx
  int v49; // eax
  int v50; // ebx
  bool *v51; // ecx
  int v52; // eax
  bool *v53; // ebx
  unsigned int v55; // [esp-4h] [ebp-78h]
  CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > verts; // [esp+Ch] [ebp-68h] BYREF
  CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > edges; // [esp+20h] [ebp-54h] BYREF
  CUtlVector<bool,CUtlMemory<bool,int> > edgeReverseMap; // [esp+34h] [ebp-40h] BYREF
  int nFaceSets; // [esp+48h] [ebp-2Ch]
  CDmMeshComp::CEdge *Edge; // [esp+4Ch] [ebp-28h]
  CDmeFaceSet *pFaceSet; // [esp+50h] [ebp-24h]
  const CUtlVector<int,CUtlMemory<int,int> > *vertexIndices; // [esp+54h] [ebp-20h]
  int j; // [esp+58h] [ebp-1Ch]
  const CUtlVector<int,CUtlMemory<int,int> > *pPositionIndices; // [esp+5Ch] [ebp-18h]
  int edgePosIndex0; // [esp+60h] [ebp-14h]
  int nIndices; // [esp+64h] [ebp-10h]
  CDmMeshComp *v67; // [esp+68h] [ebp-Ch]
  int edgePosIndex1; // [esp+6Ch] [ebp-8h]
  int facePosIndex; // [esp+70h] [ebp-4h]

  CurrentBaseState = pPassedBase;
  v4 = this;
  this->m_pMesh = pMesh;
  this->m_pBase = nullptr;
  this->m_verts.m_Memory.m_pMemory = nullptr;
  this->m_verts.m_Memory.m_nAllocationCount = 0;
  this->m_verts.m_Memory.m_nGrowSize = 0;
  this->m_verts.m_Size = 0;
  this->m_verts.m_pElements = nullptr;
  this->m_edges.m_Memory.m_pMemory = nullptr;
  this->m_edges.m_Memory.m_nAllocationCount = 0;
  this->m_edges.m_Memory.m_nGrowSize = 0;
  this->m_edges.m_Size = 0;
  this->m_edges.m_pElements = nullptr;
  this->m_faces.m_Memory.m_pBlocks = nullptr;
  this->m_faces.m_Memory.m_nAllocationCount = 0;
  this->m_faces.m_Memory.m_nGrowSize = 0;
  this->m_faces.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_faces.m_LastAlloc.m_nIndex = -1;
  v67 = this;
  this->m_faces.m_Head = 0;
  this->m_faces.m_Tail = 0;
  this->m_faces.m_FirstFree = 0;
  this->m_faces.m_ElementCount = 0;
  this->m_faces.m_NumAlloced = 0;
  this->m_faces.m_pElements = nullptr;
  if ( CurrentBaseState == nullptr )
    CurrentBaseState = CDmeMesh::GetCurrentBaseState(this: pMesh);
  v4->m_pBase = CurrentBaseState;
  if ( CurrentBaseState != nullptr && CurrentBaseState->m_pStandardFieldIndex[0] >= 0 )
  {
    PositionData = CDmeVertexDataBase::GetPositionData(this: CurrentBaseState);
    m_pBase = v4->m_pBase;
    nIndices = (int)PositionData;
    pPositionIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmeVertexDataBase::GetVertexIndexData(
                                                                       this: m_pBase,
                                                                       fieldId: FIELD_POSITION);
    v7 = *(_DWORD *)(nIndices + 12);
    edgePosIndex0 = v7;
    if ( v7 > 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: &v4->m_verts, num: v7);
      pPassedBase = nullptr;
      edgePosIndex1 = 0;
      do
      {
        vertexIndices = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                          this: v4->m_pBase,
                          fieldId: FIELD_POSITION,
                          nDataIndex: (int)pPassedBase);
        v8 = operator new(nSize: 0x20u);
        if ( v8 != nullptr )
        {
          v9 = edgePosIndex1 + *(_DWORD *)nIndices;
          *v8 = pPassedBase;
          v10 = vertexIndices;
          v8[2] = v9;
          v8[1] = v10;
          v8[4] = 8;
          v8[5] = 8;
          v8[3] = 0;
          v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
          v8[3] = v11;
          v8[6] = 0;
          v8[7] = v11;
          facePosIndex = (int)v8;
        }
        else
        {
          facePosIndex = 0;
        }
        m_Size = v4->m_verts.m_Size;
        m_nAllocationCount = v4->m_verts.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v4->m_verts,
            num: m_Size - m_nAllocationCount + 1);
        ++v4->m_verts.m_Size;
        m_pMemory = v4->m_verts.m_Memory.m_pMemory;
        v15 = v4->m_verts.m_Size - m_Size - 1;
        v4->m_verts.m_pElements = m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
        v16 = (int *)&v4->m_verts.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = facePosIndex;
        edgePosIndex1 += 12;
        pPassedBase = (CDmeVertexData *)((char *)pPassedBase + 1);
      }
      while ( (int)pPassedBase < edgePosIndex0 );
      v17 = CDmeMesh::FaceSetCount(this: pMesh);
      v18 = nullptr;
      nFaceSets = v17;
      for ( vertexIndices = nullptr; (int)v18 < nFaceSets; vertexIndices = v18 )
      {
        pFaceSet = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: (int)v18);
        v19 = pFaceSet->m_indices.m_Storage.m_Size;
        nIndices = v19;
        if ( v19 >= 4 )
        {
          CUtlFixedMemory<UtlLinkedListElem_t<CDmMeshComp::CFace,int>>::Grow(
            this: &v4->m_faces.m_Memory,
            num: v4->m_faces.m_ElementCount + v19 / 4 - v4->m_faces.m_Memory.m_nAllocationCount);
          v20 = nIndices / 2;
          v4->m_faces.m_pElements = nullptr;
          v21 = v4->m_edges.m_Size + v20;
          if ( v4->m_edges.m_Memory.m_nAllocationCount < v21 && v4->m_edges.m_Memory.m_nGrowSize >= 0 )
          {
            v22 = v4->m_edges.m_Memory.m_pMemory;
            v4->m_edges.m_Memory.m_nAllocationCount = v21;
            v55 = 4 * v21;
            if ( v22 != nullptr )
              v23 = (CDmMeshComp::CEdge **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v22, a3: v55);
            else
              v23 = (CDmMeshComp::CEdge **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v55);
            v4->m_edges.m_Memory.m_pMemory = v23;
          }
          v24 = v4->m_edges.m_Memory.m_pMemory;
          memset(&verts, 0, 12);
          v25 = 0;
          v4->m_edges.m_pElements = v24;
          v26 = -1;
          v27 = 0;
          v28 = 0;
          facePosIndex = -1;
          verts.m_Size = 0;
          verts.m_pElements = nullptr;
          memset(&edges, 0, sizeof(edges));
          memset(&edgeReverseMap, 0, sizeof(edgeReverseMap));
          HIBYTE(pPassedBase) = 0;
          j = 0;
          if ( nIndices > 0 )
          {
            while ( 1 )
            {
              v29 = pFaceSet->m_indices.m_Storage.m_Memory.m_pMemory[v28];
              if ( v29 >= 0 )
              {
                if ( facePosIndex >= 0 )
                {
                  edgePosIndex0 = v26;
                  v41 = pPositionIndices->m_Memory.m_pMemory[v29];
                  v42 = v4->m_verts.m_Memory.m_pMemory;
                  edgePosIndex1 = v41;
                  Edge = (CDmMeshComp::CEdge *)&v42[v41];
                  v43 = v27;
                  if ( v27 + 1 > verts.m_Memory.m_nAllocationCount )
                  {
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(
                      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&verts,
                      num: v27 - verts.m_Memory.m_nAllocationCount + 1);
                    v27 = verts.m_Size;
                  }
                  v44 = verts.m_Memory.m_pMemory;
                  verts.m_Size = ++v27;
                  verts.m_pElements = verts.m_Memory.m_pMemory;
                  if ( v27 - v43 - 1 > 0 )
                  {
                    _V_memmove(
                      dest: &verts.m_Memory.m_pMemory[v43 + 1],
                      src: &verts.m_Memory.m_pMemory[v43],
                      count: 4 * (v27 - v43 - 1));
                    v44 = verts.m_Memory.m_pMemory;
                  }
                  v45 = &v44[v43];
                  if ( v45 != nullptr )
                    *v45 = Edge->m_pVert0;
                  Edge = CDmMeshComp::FindOrCreateEdge(
                           this: v67,
                           vIndex0: edgePosIndex0,
                           vIndex1: edgePosIndex1,
                           pReverse: (bool *)&pPassedBase + 3);
                  v46 = v25;
                  if ( v25 + 1 > edges.m_Memory.m_nAllocationCount )
                  {
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(
                      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&edges,
                      num: v25 - edges.m_Memory.m_nAllocationCount + 1);
                    v25 = edges.m_Size;
                  }
                  v47 = edges.m_Memory.m_pMemory;
                  edges.m_Size = ++v25;
                  edges.m_pElements = edges.m_Memory.m_pMemory;
                  if ( v25 - v46 - 1 > 0 )
                  {
                    _V_memmove(
                      dest: &edges.m_Memory.m_pMemory[v46 + 1],
                      src: &edges.m_Memory.m_pMemory[v46],
                      count: 4 * (v25 - v46 - 1));
                    v47 = edges.m_Memory.m_pMemory;
                  }
                  v48 = &v47[v46];
                  if ( v48 != nullptr )
                    *v48 = Edge;
                  v49 = edgeReverseMap.m_Size;
                  v50 = edgeReverseMap.m_Size;
                  if ( edgeReverseMap.m_Size + 1 > edgeReverseMap.m_Memory.m_nAllocationCount )
                  {
                    CUtlMemory<bool,int>::Grow(
                      this: (CUtlMemory<unsigned char,int> *)&edgeReverseMap,
                      num: edgeReverseMap.m_Size - edgeReverseMap.m_Memory.m_nAllocationCount + 1);
                    v49 = edgeReverseMap.m_Size;
                  }
                  v51 = edgeReverseMap.m_Memory.m_pMemory;
                  edgeReverseMap.m_Size = v49 + 1;
                  v52 = v49 - v50;
                  edgeReverseMap.m_pElements = edgeReverseMap.m_Memory.m_pMemory;
                  if ( v52 > 0 )
                  {
                    _V_memmove(
                      dest: &edgeReverseMap.m_Memory.m_pMemory[v50 + 1],
                      src: &edgeReverseMap.m_Memory.m_pMemory[v50],
                      count: v52);
                    v51 = edgeReverseMap.m_Memory.m_pMemory;
                  }
                  v53 = &v51[v50];
                  if ( v53 != nullptr )
                    *v53 = HIBYTE(pPassedBase);
                  v4 = v67;
                }
                else
                {
                  v38 = v4->m_verts.m_Memory.m_pMemory;
                  facePosIndex = pPositionIndices->m_Memory.m_pMemory[v29];
                  edgePosIndex1 = facePosIndex;
                  Edge = (CDmMeshComp::CEdge *)&v38[facePosIndex];
                  v39 = v27;
                  edgePosIndex0 = v27;
                  if ( v27 + 1 > verts.m_Memory.m_nAllocationCount )
                  {
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(
                      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&verts,
                      num: v27 - verts.m_Memory.m_nAllocationCount + 1);
                    v27 = verts.m_Size;
                    v39 = edgePosIndex0;
                  }
                  verts.m_Size = ++v27;
                  verts.m_pElements = verts.m_Memory.m_pMemory;
                  if ( v27 - v39 - 1 > 0 )
                  {
                    _V_memmove(
                      dest: &verts.m_Memory.m_pMemory[v39 + 1],
                      src: &verts.m_Memory.m_pMemory[v39],
                      count: 4 * (v27 - v39 - 1));
                    v39 = edgePosIndex0;
                  }
                  v40 = &verts.m_Memory.m_pMemory[v39];
                  if ( v40 != nullptr )
                    *v40 = Edge->m_pVert0;
                }
              }
              else
              {
                edgePosIndex1 = facePosIndex;
                edgePosIndex0 = (int)CDmMeshComp::FindOrCreateEdge(
                                       this: v4,
                                       vIndex0: v26,
                                       vIndex1: facePosIndex,
                                       pReverse: (bool *)&pPassedBase + 3);
                v30 = v25;
                if ( v25 + 1 > edges.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<IDmFormatUpdater *,int>::Grow(
                    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&edges,
                    num: v25 - edges.m_Memory.m_nAllocationCount + 1);
                  v25 = edges.m_Size;
                }
                v31 = edges.m_Memory.m_pMemory;
                edges.m_Size = v25 + 1;
                v32 = v25 - v30;
                edges.m_pElements = edges.m_Memory.m_pMemory;
                if ( v32 > 0 )
                {
                  _V_memmove(
                    dest: &edges.m_Memory.m_pMemory[v30 + 1],
                    src: &edges.m_Memory.m_pMemory[v30],
                    count: 4 * v32);
                  v31 = edges.m_Memory.m_pMemory;
                }
                v33 = (int *)&v31[v30];
                if ( v33 != nullptr )
                  *v33 = edgePosIndex0;
                v34 = edgeReverseMap.m_Size;
                v35 = edgeReverseMap.m_Size;
                if ( edgeReverseMap.m_Size + 1 > edgeReverseMap.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<bool,int>::Grow(
                    this: (CUtlMemory<unsigned char,int> *)&edgeReverseMap,
                    num: edgeReverseMap.m_Size - edgeReverseMap.m_Memory.m_nAllocationCount + 1);
                  v34 = edgeReverseMap.m_Size;
                }
                v36 = edgeReverseMap.m_Memory.m_pMemory;
                edgeReverseMap.m_Size = v34 + 1;
                v37 = v34 - v35;
                edgeReverseMap.m_pElements = edgeReverseMap.m_Memory.m_pMemory;
                if ( v37 > 0 )
                  _V_memmove(
                    dest: &edgeReverseMap.m_Memory.m_pMemory[v35 + 1],
                    src: &edgeReverseMap.m_Memory.m_pMemory[v35],
                    count: v37);
                if ( &v36[v35] != nullptr )
                  v36[v35] = HIBYTE(pPassedBase);
                CDmMeshComp::CreateFace(this: v4, &verts, &edges, &edgeReverseMap);
                v27 = 0;
                v25 = 0;
                facePosIndex = -1;
                verts.m_Size = 0;
                edges.m_Size = 0;
                edgeReverseMap.m_Size = 0;
              }
              v28 = j + 1;
              j = v28;
              if ( v28 >= nIndices )
                break;
              v26 = edgePosIndex1;
            }
            if ( edgeReverseMap.m_Memory.m_nGrowSize >= 0 && edgeReverseMap.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: edgeReverseMap.m_Memory.m_pMemory);
            if ( edges.m_Memory.m_nGrowSize >= 0 && edges.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: edges.m_Memory.m_pMemory);
            if ( verts.m_Memory.m_nGrowSize >= 0 && verts.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: verts.m_Memory.m_pMemory);
          }
        }
        v18 = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)&vertexIndices->m_Memory.m_pMemory + 1);
      }
    }
  }
  return v4;
}
