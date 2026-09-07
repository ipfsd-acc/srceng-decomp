// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/optimize_subd.cpp
// Functions: 16
// ============================================================

#include "utils\studiomdl\optimize_subd.h"

//------------------------------------------------------------------------------
// Address: 0x004243C0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *pPatch,
        unsigned __int16 k)
{
  OptimizedModel::HalfEdge *v3; // eax
  OptimizedModel::HalfEdge *v4; // ecx
  OptimizedModel::HalfEdge *twin; // eax

  v3 = &pPatch->halfEdges[k];
  while ( 1 )
  {
    v4 = v3;
    if ( v3->patch->bndEdge[v3->localID] != 0 )
      break;
    twin = v3->twin;
    if ( twin == nullptr )
      break;
    v3 = &twin->patch->halfEdges[dword_63F548[twin->localID]];
    if ( v3 == nullptr )
      break;
    if ( v3 == &pPatch->halfEdges[k] )
      return;
  }
  pPatch->halfEdges[k].sectorStart = v4;
}

//------------------------------------------------------------------------------
// Address: 0x00424440
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  OptimizedModel::HalfEdge *sectorStart; // edx
  __int16 v4; // di
  OptimizedModel::HalfEdge *v5; // ecx
  OptimizedModel::HalfEdge *v6; // eax
  OptimizedModel::HalfEdge *twin; // eax
  int localID; // eax
  OptimizedModel::SubD_Face_t *patch; // edx
  OptimizedModel::HalfEdge *v10; // ecx
  int v11; // eax
  int v12; // eax

  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  v4 = 0;
  v5 = sectorStart;
  if ( sectorStart->twin != nullptr )
  {
    v6 = &sectorStart->twin->patch->halfEdges[dword_63F548[sectorStart->twin->localID]];
    if ( (OptimizedModel::SubD_Face_t *)((char *)sectorStart->twin->patch + 16
                                                                          * dword_63F548[sectorStart->twin->localID]) != (OptimizedModel::SubD_Face_t *)-236 )
    {
      while ( v6 != sectorStart )
      {
        v5 = v6;
        twin = v6->twin;
        if ( twin != nullptr )
        {
          v6 = &twin->patch->halfEdges[dword_63F548[twin->localID]];
          if ( v6 != nullptr )
            continue;
        }
        goto LABEL_8;
      }
      v5 = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
    }
  }
LABEL_8:
  localID = v5->localID;
  patch = v5->patch;
  if ( patch->bndEdge[localID] != 0 )
    v4 = 1;
  v10 = v5->twin;
  v11 = (int)&patch->halfEdges[dword_63F570[localID]];
  do
  {
    if ( *(_WORD *)(*(_DWORD *)(v11 + 12) + 2 * *(unsigned __int8 *)(v11 + 8) + 154) != 0 )
      ++v4;
    v12 = *(_DWORD *)v11;
    if ( v12 == 0 )
      break;
    v11 = *(_DWORD *)(v12 + 12) + 16 * dword_63F570[*(unsigned __int8 *)(v12 + 8)] + 236;
    if ( v11 == 0 )
      break;
  }
  while ( (OptimizedModel::HalfEdge *)v11 != v10 );
  if ( v4 == 1 )
  {
    baseQuad->halfEdges[baseLocalID].sectorStart = &baseQuad->halfEdges[baseLocalID];
    baseQuad->bndVtx[baseLocalID] = 0;
  }
  else if ( (unsigned __int16)v4 >= 2u )
  {
    baseQuad->bndVtx[baseLocalID] = 1;
    if ( (unsigned __int16)v4 > 2u )
      baseQuad->cornerVtx[baseLocalID] = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424570
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  unsigned __int16 *v5; // edx
  unsigned __int16 *vtx1RingSize; // eax
  int i; // esi
  int v8; // ebx
  int v9; // eax
  OptimizedModel::HalfEdge *sectorStart; // edx
  int v11; // edx
  int v12; // edx
  OptimizedModel::HalfEdge *heEnd; // [esp+Ch] [ebp-4h]
  unsigned __int16 *oneRing; // [esp+18h] [ebp+8h]
  OptimizedModel::HalfEdge *heBase; // [esp+1Ch] [ebp+Ch]

  v5 = baseQuad->oneRing;
  oneRing = baseQuad->oneRing;
  if ( baseLocalID != 0 )
  {
    vtx1RingSize = baseQuad->vtx1RingSize;
    for ( i = baseLocalID; i != 0; --i )
    {
      v8 = *vtx1RingSize++;
      v5 += v8;
    }
    oneRing = v5;
  }
  v9 = baseLocalID;
  baseQuad->vtx1RingCenterQuadOffset[baseLocalID] = 1;
  baseQuad->valences[baseLocalID] = 0;
  baseQuad->vtx1RingSize[baseLocalID] = 0;
  heBase = &baseQuad->halfEdges[MOD4[baseLocalID]];
  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  oneRing[baseQuad->vtx1RingSize[baseLocalID]++] = sectorStart->patch->vtxIDs[MOD4[sectorStart->localID]];
  ++baseQuad->valences[baseLocalID];
  oneRing[baseQuad->vtx1RingSize[baseLocalID]] = sectorStart->patch->vtxIDs[MOD4[sectorStart->localID + 1]];
  ++baseQuad->vtx1RingSize[v9];
  heEnd = sectorStart->twin;
  v11 = (int)&sectorStart->patch->halfEdges[dword_63F570[sectorStart->localID]];
  while ( 1 )
  {
    oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                     + 2 * MOD4[*(unsigned __int8 *)(v11 + 8) + 3]
                                                     + 2);
    ++baseQuad->valences[v9];
    oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                     + 2 * MOD4[*(unsigned __int8 *)(v11 + 8)]
                                                     + 2);
    if ( *(OptimizedModel::HalfEdge **)v11 == heBase )
      baseQuad->vtx1RingCenterQuadOffset[v9] = baseQuad->vtx1RingSize[v9] - 1;
    if ( *(_WORD *)(*(_DWORD *)(v11 + 12) + 2 * *(unsigned __int8 *)(v11 + 8) + 154) != 0 && baseQuad->bndVtx[v9] != 0 )
      break;
    v12 = *(_DWORD *)v11;
    if ( v12 == 0 )
      break;
    v11 = *(_DWORD *)(v12 + 12) + 16 * dword_63F570[*(unsigned __int8 *)(v12 + 8)] + 236;
    if ( v11 == 0 )
      break;
    if ( (OptimizedModel::HalfEdge *)v11 == heEnd )
    {
      oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                       + 2 * MOD4[*(unsigned __int8 *)(v11 + 8) + 3]
                                                       + 2);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424730
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  int v3; // edx
  OptimizedModel::HalfEdge *sectorStart; // eax
  int v5; // eax
  char v6; // cl
  int v7; // eax
  __int16 nbCorners_4; // [esp+Ch] [ebp-4h]
  OptimizedModel::HalfEdge *heEnd; // [esp+1Ch] [ebp+Ch]

  v3 = baseLocalID;
  baseQuad->nbCornerVtx[baseLocalID] = 0;
  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  baseQuad->nbCornerVtx[baseLocalID] |= sectorStart->patch->cornerVtx[MOD4[sectorStart->localID + 1]] == 2;
  nbCorners_4 = 1;
  heEnd = sectorStart->twin;
  v5 = (int)&sectorStart->patch->halfEdges[dword_63F570[sectorStart->localID]];
  do
  {
    v6 = nbCorners_4++;
    baseQuad->nbCornerVtx[v3] |= (*(_WORD *)(*(_DWORD *)(v5 + 12) + 2 * *(unsigned __int8 *)(v5 + 8) + 162) == 2) << v6;
    if ( *(_WORD *)(*(_DWORD *)(v5 + 12) + 2 * *(unsigned __int8 *)(v5 + 8) + 154) != 0 && baseQuad->bndVtx[v3] != 0 )
      break;
    v7 = *(_DWORD *)v5;
    if ( v7 == 0 )
      break;
    v5 = *(_DWORD *)(v7 + 12) + 16 * dword_63F570[*(unsigned __int8 *)(v7 + 8)] + 236;
    if ( v5 == 0 )
      break;
  }
  while ( (OptimizedModel::HalfEdge *)v5 != heEnd );
}

//------------------------------------------------------------------------------
// Address: 0x00424830
// Name: private: void OptimizedModel::COptimizeSubDBuilder::RotateFace(struct OptimizedModel::SubD_Face_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::RotateFace(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *pPatch,
        int nTimesToRotate)
{
  OptimizedModel::HalfEdge *v3; // edx
  OptimizedModel::HalfEdge *v4; // esi
  OptimizedModel::HalfEdge *halfEdges; // ecx
  int v6; // ebx
  unsigned __int16 *bndEdge; // edx
  __int64 v8; // xmm0_8
  unsigned __int8 v9; // al
  OptimizedModel::SubD_Face_t v10; // [esp+0h] [ebp-13Ch] BYREF
  OptimizedModel::HalfEdge *twin; // [esp+130h] [ebp-Ch]
  OptimizedModel::HalfEdge *v12; // [esp+134h] [ebp-8h]
  OptimizedModel::HalfEdge *v13; // [esp+138h] [ebp-4h]

  if ( nTimesToRotate > 0 )
  {
    do
    {
      twin = pPatch->halfEdges[1].twin;
      v12 = pPatch->halfEdges[2].twin;
      v3 = pPatch->halfEdges[3].twin;
      v10 = *pPatch;
      v4 = pPatch->halfEdges[0].twin;
      halfEdges = pPatch->halfEdges;
      v13 = v3;
      v6 = 3;
      bndEdge = pPatch->bndEdge;
      do
      {
        *(bndEdge - 76) = v10.vtxIDs[v6 % 4];
        *bndEdge = v10.bndEdge[v6 % 4];
        v8 = *(_QWORD *)&v10.halfEdges[v6 % 4].twin;
        *(bndEdge - 4) = v10.bndVtx[v6 % 4];
        *(_QWORD *)&halfEdges->twin = v8;
        v9 = v6 - 3;
        *(_QWORD *)&halfEdges->localID = *(_QWORD *)&v10.halfEdges[v6 % 4].localID;
        ++v6;
        halfEdges->localID = v9;
        halfEdges->sectorStart = halfEdges;
        ++bndEdge;
        ++halfEdges;
      }
      while ( v6 - 3 < 4 );
      if ( v4 != nullptr )
        v4->twin = &pPatch->halfEdges[1];
      if ( twin != nullptr )
        twin->twin = &pPatch->halfEdges[2];
      if ( v12 != nullptr )
        v12->twin = &pPatch->halfEdges[3];
      if ( v13 != nullptr )
        v13->twin = pPatch->halfEdges;
      --nTimesToRotate;
    }
    while ( nTimesToRotate != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004249E0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::SubD_Face_t *v1; // edi
  int v2; // eax
  unsigned __int16 *minOneRingIndex; // esi
  int *m_pMemory; // ecx
  int v5; // ebx
  unsigned __int16 *v6; // esi
  unsigned __int16 v7; // di
  int v8; // edx
  bool v9; // zf
  OptimizedModel::SubD_Face_t *pPatch; // [esp+0h] [ebp-24h]
  int *v11; // [esp+4h] [ebp-20h]
  int i; // [esp+8h] [ebp-1Ch]
  int v13; // [esp+Ch] [ebp-18h]
  unsigned __int16 *v14; // [esp+10h] [ebp-14h]
  unsigned __int16 nMinNeighborOffset; // [esp+14h] [ebp-10h]
  int nMinNeighborIdx; // [esp+18h] [ebp-Ch]
  OptimizedModel::COptimizeSubDBuilder *v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]

  v17 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v18 = 0;
    while ( 1 )
    {
      v1 = &this->m_faceList->m_Memory.m_pMemory[v18];
      v2 = 0;
      minOneRingIndex = v1->minOneRingIndex;
      pPatch = v1;
      v14 = v1->minOneRingIndex;
      v13 = 4;
      while ( 1 )
      {
        m_pMemory = this->m_IndexRemapTable.m_Memory.m_pMemory;
        nMinNeighborIdx = m_pMemory[v1->oneRing[v2]];
        v5 = *(minOneRingIndex - 12) + v2 - 1;
        v11 = m_pMemory;
        nMinNeighborOffset = 0;
        if ( v2 <= v5 )
        {
          v6 = &v1->oneRing[v2];
          v7 = 0;
          v8 = v5 - v2 + 1;
          while ( 1 )
          {
            if ( m_pMemory[*v6] < nMinNeighborIdx )
            {
              nMinNeighborIdx = m_pMemory[*v6];
              nMinNeighborOffset = v7;
            }
            ++v6;
            ++v7;
            if ( --v8 == 0 )
              break;
            m_pMemory = v11;
          }
          v1 = pPatch;
          minOneRingIndex = v14;
        }
        *minOneRingIndex++ = nMinNeighborOffset;
        v9 = v13-- == 1;
        v2 = v5 + 1;
        v14 = minOneRingIndex;
        if ( v9 )
          break;
        this = v17;
      }
      ++v18;
      if ( ++i >= v17->m_numPatches )
        break;
      this = v17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424AB0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // edx
  OptimizedModel::SubD_Face_t *v2; // eax
  unsigned __int16 *bndEdge; // ecx
  OptimizedModel::SubD_Face_t **p_patch; // eax
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // ecx
  const mstudio_meshvertexdata_t *v6; // edi
  int origMeshVertID; // esi
  int v8; // ebx
  _QWORD *pVertexData; // eax
  unsigned int v10; // esi
  __int64 v11; // xmm0_8
  unsigned int v12; // esi
  int v13; // eax
  float *v14; // ecx
  unsigned int v15; // esi
  bool v16; // zf
  int v17; // ecx
  int v18; // eax
  float *v19; // ecx
  unsigned int v20; // esi
  int v21; // ecx
  OptimizedModel::HalfEdge *v22; // eax
  __int64 v23; // [esp+0h] [ebp-48h]
  float v24; // [esp+8h] [ebp-40h]
  float v25; // [esp+14h] [ebp-34h]
  OptimizedModel::SubD_Face_t *pPatch; // [esp+18h] [ebp-30h]
  int m_numPatches; // [esp+1Ch] [ebp-2Ch]
  int i; // [esp+20h] [ebp-28h]
  int v29; // [esp+24h] [ebp-24h]
  OptimizedModel::Vertex_t *m_pMemory; // [esp+28h] [ebp-20h]
  int v31; // [esp+2Ch] [ebp-1Ch]
  int *v32; // [esp+30h] [ebp-18h]
  unsigned __int16 *v33; // [esp+34h] [ebp-14h]
  unsigned __int16 j; // [esp+3Ch] [ebp-Ch]
  OptimizedModel::SubD_Face_t *v36; // [esp+40h] [ebp-8h]
  OptimizedModel::SubD_Face_t **v37; // [esp+44h] [ebp-4h]

  v1 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v31 = 0;
    do
    {
      v2 = &v1->m_faceList->m_Memory.m_pMemory[v31];
      v32 = &MOD4[1];
      bndEdge = v2->bndEdge;
      pPatch = v2;
      p_patch = &v2->halfEdges[0].patch;
      v33 = bndEdge;
      v37 = p_patch;
      do
      {
        if ( *(p_patch - 3) == nullptr )
        {
          m_vtxList = v1->m_vtxList;
          v6 = *v1->m_vtxData;
          origMeshVertID = m_vtxList->m_Memory.m_pMemory[(*p_patch)->vtxIDs[MOD4[*((unsigned __int8 *)p_patch - 4)]]].origMeshVertID;
          v8 = *((unsigned __int8 *)p_patch - 4);
          pVertexData = v6->modelvertexdata->pVertexData;
          v10 = (unsigned int)v6[-1].modelvertexdata
              + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
              + origMeshVertID;
          v29 = 0;
          v11 = pVertexData[6 * v10 + 2];
          v25 = *(float *)&pVertexData[6 * v10 + 3];
          v12 = (unsigned int)v6[-1].modelvertexdata
              + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
              + m_vtxList->m_Memory.m_pMemory[(*v37)->vtxIDs[MOD4[v8 + 1]]].origMeshVertID;
          v24 = *(float *)&pVertexData[6 * v12 + 3];
          v23 = pVertexData[6 * v12 + 2];
          m_numPatches = this->m_numPatches;
          if ( m_numPatches > 0 )
          {
            m_pMemory = m_vtxList->m_Memory.m_pMemory;
            v36 = this->m_faceList->m_Memory.m_pMemory;
            while ( 2 )
            {
              for ( j = 0; j < 4u; ++j )
              {
                v13 = v36->vtxIDs[MOD4[j]];
                v14 = (float *)v6->modelvertexdata->pVertexData;
                v15 = (unsigned int)v6[-1].modelvertexdata
                    + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
                    + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v13 + v13);
                v16 = *(float *)&v23 == v14[12 * v15 + 4];
                v17 = (int)&v14[12 * v15 + 4];
                if ( v16 && *((float *)&v23 + 1) == *(float *)(v17 + 4) && v24 == *(float *)(v17 + 8) )
                {
                  v18 = v36->vtxIDs[MOD4[j + 1]];
                  v19 = (float *)v6->modelvertexdata->pVertexData;
                  v20 = (unsigned int)v6[-1].modelvertexdata
                      + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
                      + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v18 + v18);
                  v16 = *(float *)&v11 == v19[12 * v20 + 4];
                  v21 = (int)&v19[12 * v20 + 4];
                  if ( v16 && *((float *)&v11 + 1) == *(float *)(v21 + 4) && v25 == *(float *)(v21 + 8) )
                  {
                    v22 = &v36->halfEdges[j];
                    goto LABEL_17;
                  }
                }
              }
              ++v36;
              if ( ++v29 < m_numPatches )
                continue;
              break;
            }
          }
          v22 = nullptr;
LABEL_17:
          *(v37 - 3) = (OptimizedModel::SubD_Face_t *)v22;
          if ( v22 != nullptr )
          {
            v22->twin = (OptimizedModel::HalfEdge *)(v37 - 3);
          }
          else
          {
            *v33 = 1;
            pPatch->bndVtx[*(v32 - 1)] = 1;
            pPatch->bndVtx[*v32] = 1;
          }
          v1 = this;
          p_patch = v37;
        }
        ++v33;
        p_patch += 4;
        v37 = p_patch;
        ++v32;
      }
      while ( (int)v32 < (int)&MOD4[5] );
      ++v31;
      ++i;
    }
    while ( i < v1->m_numPatches );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424D60
// Name: public: void OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // ebx
  OptimizedModel::SubD_Face_t *v2; // esi
  int *v3; // edi
  OptimizedModel::HalfEdge *halfEdges; // eax
  const mstudio_meshvertexdata_t *v5; // ecx
  _QWORD *pVertexData; // eax
  __int64 v7; // xmm0_8
  unsigned int v8; // ebx
  __int64 v9; // xmm0_8
  unsigned int v10; // ecx
  bool v11; // zf
  __int64 vC; // [esp+24h] [ebp-40h]
  float vC_8; // [esp+2Ch] [ebp-38h]
  float vB_8; // [esp+38h] [ebp-2Ch]
  __int64 vA; // [esp+3Ch] [ebp-28h]
  float vA_8; // [esp+44h] [ebp-20h]
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // [esp+4Ch] [ebp-18h]
  int i; // [esp+50h] [ebp-14h]
  int v19; // [esp+54h] [ebp-10h]
  OptimizedModel::HalfEdge *v20; // [esp+58h] [ebp-Ch]
  int v22; // [esp+60h] [ebp-4h]

  v1 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v22 = 0;
    do
    {
      v2 = &v1->m_faceList->m_Memory.m_pMemory[v22];
      v3 = MOD4;
      halfEdges = v2->halfEdges;
      v20 = v2->halfEdges;
      v19 = 4;
      do
      {
        if ( halfEdges->twin != nullptr && halfEdges->twin->twin != halfEdges )
        {
          _Msg(a1: "Topology error at vertices %d, %d, %d\n", v2->vtxIDs[v3[3]], v2->vtxIDs[*v3], v2->vtxIDs[v3[1]]);
          v5 = *v1->m_vtxData;
          pVertexData = v5->modelvertexdata->pVertexData;
          v7 = pVertexData[6
                         * (int)((int)v5[-1].modelvertexdata
                               + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
                               + v1->m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[3]]].origMeshVertID)
                         + 2];
          m_vtxList = this->m_vtxList;
          vA_8 = *(float *)&pVertexData[6
                                      * (int)((int)v5[-1].modelvertexdata
                                            + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
                                            + v1->m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[3]]].origMeshVertID)
                                      + 3];
          v8 = (unsigned int)v5[-1].modelvertexdata
             + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
             + m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[*v3]].origMeshVertID;
          vA = v7;
          v9 = pVertexData[6 * v8 + 2];
          vB_8 = *(float *)&pVertexData[6 * v8 + 3];
          v10 = 6
              * ((int)v5[-1].modelvertexdata
               + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
               + m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[1]]].origMeshVertID);
          vC = pVertexData[v10 + 2];
          vC_8 = *(float *)&pVertexData[v10 + 3];
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&vA, *((float *)&vA + 1), vA_8);
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&v9, *((float *)&v9 + 1), vB_8);
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&vC, *((float *)&vC + 1), vC_8);
          v1 = this;
          halfEdges = v20;
        }
        ++halfEdges;
        ++v3;
        v11 = v19-- == 1;
        v20 = halfEdges;
      }
      while ( !v11 );
      ++v22;
      ++i;
    }
    while ( i < v1->m_numPatches );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424F90
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(
        OptimizedModel::COptimizeSubDBuilder *this@<ecx>,
        int a2@<ebx>,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  const mstudio_meshvertexdata_t *v5; // ebx
  OptimizedModel::HalfEdge *sectorStart; // esi
  const mstudio_modelvertexdata_t *modelvertexdata; // edx
  int origMeshVertID; // ecx
  _QWORD *pVertexData; // eax
  unsigned int v10; // edx
  __int64 v11; // xmm0_8
  float v12; // ecx
  OptimizedModel::Vertex_t *m_pMemory; // eax
  const mstudio_modelvertexdata_t *v14; // edx
  int v15; // ecx
  unsigned int v16; // ecx
  Vector *v17; // eax
  const mstudio_meshvertexdata_t *v18; // ebx
  int v19; // ecx
  float *v20; // eax
  int v21; // esi
  const mstudio_meshvertexdata_t *v22; // ebx
  int v23; // ecx
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  int v27; // esi
  int v28; // eax
  int v29; // edx
  float v30; // xmm0_4
  long double v31; // [esp-4h] [ebp-50h]
  Vector vec; // [esp+8h] [ebp-44h] BYREF
  Vector center_pos; // [esp+14h] [ebp-38h]
  Vector eVec1; // [esp+20h] [ebp-2Ch] BYREF
  Vector eVec2; // [esp+2Ch] [ebp-20h] BYREF
  Vector center_nor; // [esp+38h] [ebp-14h] BYREF
  const mstudio_modelvertexdata_t *v37; // [esp+44h] [ebp-8h]
  int v38; // [esp+48h] [ebp-4h]

  if ( baseQuad->bndVtx[baseLocalID] != 0 )
  {
    LODWORD(v31) = a2;
    if ( baseQuad->cornerVtx[baseLocalID] != 0 )
    {
      v5 = *this->m_vtxData;
      sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
      modelvertexdata = v5->modelvertexdata;
      origMeshVertID = this->m_vtxList->m_Memory.m_pMemory[sectorStart->patch->vtxIDs[sectorStart->localID]].origMeshVertID;
      v38 = 9 * sectorStart->patch->vtxIDs[sectorStart->localID];
      pVertexData = v5->modelvertexdata->pVertexData;
      v10 = 6 * ((int)v5[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30 + origMeshVertID);
      v11 = pVertexData[v10 + 2];
      v12 = *(float *)&pVertexData[v10 + 3];
      m_pMemory = this->m_vtxList->m_Memory.m_pMemory;
      v14 = v5->modelvertexdata;
      center_pos.z = v12;
      v15 = m_pMemory[v38 / 9u].origMeshVertID;
      v37 = v14;
      v16 = (unsigned int)v5[-1].modelvertexdata + (unsigned int)v14[-3].pVertexData / 0x30 + v15;
      *(_QWORD *)&center_pos.x = v11;
      v17 = (Vector *)((char *)v14->pVertexData + 48 * v16 + 28);
      center_nor = *v17;
      VectorNormalize(vec: &center_nor);
      v18 = *this->m_vtxData;
      v19 = this->m_vtxList->m_Memory.m_pMemory[sectorStart->patch->vtxIDs[MOD4[sectorStart->localID + 1]]].origMeshVertID;
      v37 = v18->modelvertexdata;
      v20 = (float *)((char *)v37->pVertexData
                    + 48 * ((int)v18[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v19)
                    + 16);
      eVec1.x = *v20 - *(float *)&v11;
      eVec1.y = v20[1] - *((float *)&v11 + 1);
      eVec1.z = v20[2] - center_pos.z;
      *(float *)&v11 = (float)((float)(center_nor.y * eVec1.y) + (float)(center_nor.x * eVec1.x))
                     + (float)(center_nor.z * eVec1.z);
      vec.x = eVec1.x - (float)(center_nor.x * *(float *)&v11);
      vec.y = eVec1.y - (float)(center_nor.y * *(float *)&v11);
      vec.z = eVec1.z - (float)(center_nor.z * *(float *)&v11);
      VectorNormalize(&vec);
      v21 = (int)&sectorStart->patch->halfEdges[dword_63F570[sectorStart->localID]];
      do
      {
        v22 = *this->m_vtxData;
        v23 = this->m_vtxList->m_Memory.m_pMemory[*(unsigned __int16 *)(*(_DWORD *)(v21 + 12)
                                                                      + 2 * MOD4[*(unsigned __int8 *)(v21 + 8)]
                                                                      + 2)].origMeshVertID;
        v37 = v22->modelvertexdata;
        v24 = *((float *)v37->pVertexData
              + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
              + 5);
        v25 = *((float *)v37->pVertexData
              + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
              + 6);
        eVec2.x = *((float *)v37->pVertexData
                  + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
                  + 4)
                - center_pos.x;
        eVec2.y = v24 - center_pos.y;
        eVec2.z = v25 - center_pos.z;
        v26 = (float)((float)(center_nor.y * (float)(v24 - center_pos.y)) + (float)(center_nor.x * eVec2.x))
            + (float)(center_nor.z * (float)(v25 - center_pos.z));
        vec.x = eVec2.x - (float)(center_nor.x * v26);
        vec.y = (float)(v24 - center_pos.y) - (float)(center_nor.y * v26);
        vec.z = (float)(v25 - center_pos.z) - (float)(center_nor.z * v26);
        VectorNormalize(&vec);
        if ( *(_WORD *)(*(_DWORD *)(v21 + 12) + 2 * *(unsigned __int8 *)(v21 + 8) + 154) != 0 )
          break;
        v27 = *(_DWORD *)v21;
        if ( v27 == 0 )
          break;
        v28 = *(unsigned __int8 *)(v27 + 8);
        v29 = *(_DWORD *)(v27 + 12);
        v21 = v29 + 16 * dword_63F570[v28] + 236;
      }
      while ( v29 + 16 * dword_63F570[v28] != -236 );
      VectorNormalize(vec: &eVec1);
      VectorNormalize(vec: &eVec2);
      v30 = (float)((float)(eVec2.y * eVec1.y) + (float)(eVec2.x * eVec1.x)) + (float)(eVec2.z * eVec1.z);
      __libm_sse2_acos(x: v31);
      baseQuad->loopGapAngle[baseLocalID] = (int)(v30 * 65535.0 * 0.1591549432737564);
    }
    else
    {
      baseQuad->loopGapAngle[baseLocalID] = 0xFFFF / (2 * (baseQuad->valences[baseLocalID] == 2) + 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425330
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(struct OptimizedModel::SubD_Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad)
{
  unsigned __int16 *vUV0; // edx
  unsigned __int16 v3; // si
  unsigned __int16 origMeshVertID; // ax
  OptimizedModel::HalfEdge *twin; // ebx
  OptimizedModel::HalfEdge *v6; // ecx
  unsigned __int16 patchID; // di
  OptimizedModel::HalfEdge *v8; // eax
  __int16 v9; // si
  __int16 iMaxNeighborCorner; // [esp+10h] [ebp-28h]
  unsigned __int16 iNeighborPatchU; // [esp+14h] [ebp-24h]
  unsigned __int16 iNeighborPatch; // [esp+18h] [ebp-20h]
  unsigned __int16 p; // [esp+1Ch] [ebp-1Ch]
  OptimizedModel::HalfEdge *halfEdges; // [esp+20h] [ebp-18h]
  int i; // [esp+24h] [ebp-14h]
  OptimizedModel::COptimizeSubDBuilder *v16; // [esp+28h] [ebp-10h]
  unsigned __int16 v17; // [esp+2Ch] [ebp-Ch]
  unsigned __int16 v18; // [esp+30h] [ebp-8h]
  unsigned __int16 iMaxPatch; // [esp+34h] [ebp-4h]

  p = baseQuad->patchID;
  v16 = this;
  i = 0;
  halfEdges = baseQuad->halfEdges;
  vUV0 = baseQuad->vUV0;
  while ( 1 )
  {
    v3 = *(vUV0 - 100);
    origMeshVertID = this->m_vtxList->m_Memory.m_pMemory[v3].origMeshVertID;
    *vUV0 = origMeshVertID;
    vUV0[4] = origMeshVertID;
    vUV0[8] = origMeshVertID;
    twin = halfEdges->twin;
    v17 = -1;
    if ( halfEdges->twin != nullptr )
    {
      v17 = twin->patch->vtxIDs[(twin->localID + 1) & 3];
      if ( v17 != 0xFFFF && twin->patch->patchID > p )
        vUV0[4] = this->m_vtxList->m_Memory.m_pMemory[v17].origMeshVertID;
    }
    iNeighborPatchU = -1;
    v6 = baseQuad->halfEdges[(i + 3) % 4].twin;
    v18 = -1;
    if ( v6 != nullptr )
    {
      v18 = v6->patch->vtxIDs[v6->localID & 3];
      if ( v18 != 0xFFFF )
      {
        iNeighborPatchU = v6->patch->patchID;
        if ( iNeighborPatchU > p )
          vUV0[8] = v16->m_vtxList->m_Memory.m_pMemory[v18].origMeshVertID;
      }
    }
    patchID = baseQuad->patchID;
    v8 = twin;
    iNeighborPatch = -1;
    iMaxNeighborCorner = v3;
    iMaxPatch = baseQuad->patchID;
    if ( twin != nullptr )
    {
      do
      {
        v8 = v8->patch->halfEdges[dword_63F548[v8->localID]].twin;
        v9 = -1;
        if ( v8 != nullptr )
          v9 = v8->patch->vtxIDs[(v8->localID + 1) & 3];
        if ( v9 != -1 )
        {
          iNeighborPatch = v8->patch->patchID;
          if ( iNeighborPatch <= iMaxPatch )
          {
            patchID = iMaxPatch;
          }
          else
          {
            patchID = v8->patch->patchID;
            iMaxPatch = patchID;
            iMaxNeighborCorner = v9;
          }
        }
      }
      while ( iNeighborPatch != iNeighborPatchU && v8 != nullptr );
      v3 = iMaxNeighborCorner;
    }
    if ( v6 != nullptr && v6->patch->patchID > patchID )
    {
      v3 = v18;
      patchID = v6->patch->patchID;
    }
    if ( twin != nullptr && twin->patch->patchID > patchID )
      v3 = v17;
    ++halfEdges;
    vUV0[12] = v16->m_vtxList->m_Memory.m_pMemory[v3].origMeshVertID;
    ++vUV0;
    if ( ++i >= 4 )
      break;
    this = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425550
// Name: private: void OptimizedModel::COptimizeSubDBuilder::Propagate(class CUtlVector<struct OptimizedModel::Orientation,class CUtlMemory<struct OptimizedModel::Orientation,int>> __near &,struct OptimizedModel::HalfEdge __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::Propagate(
        OptimizedModel::COptimizeSubDBuilder *this,
        CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > *orientationArray,
        OptimizedModel::HalfEdge *pEdge,
        bool dir)
{
  OptimizedModel::HalfEdge *i; // esi
  OptimizedModel::SubD_Face_t *patch; // edx
  OptimizedModel::HalfEdge *halfEdges; // eax
  int j; // ecx
  OptimizedModel::Orientation *v8; // eax
  OptimizedModel::Orientation v9; // cl

  for ( i = pEdge->twin;
        i != nullptr;
        i = i->patch->halfEdges[dword_63F548[i->localID]].patch->halfEdges[dword_63F548[i->patch->halfEdges[dword_63F548[i->localID]].localID]].twin )
  {
    patch = i->patch;
    if ( patch == nullptr )
      break;
    halfEdges = patch->halfEdges;
    for ( j = 0; halfEdges != i; ++j )
      ++halfEdges;
    v8 = &orientationArray->m_Memory.m_pMemory[patch->patchID];
    if ( j == 1 || j == 3 )
    {
      if ( (*(_BYTE *)v8 & 4) != 0 )
        return;
      v9 = (OptimizedModel::Orientation)(*(_BYTE *)v8 & 0xFE | (dir ^ (j == 1)) & 1 | 4);
    }
    else
    {
      if ( (*(_BYTE *)v8 & 8) != 0 )
        return;
      v9 = (OptimizedModel::Orientation)(*(_BYTE *)v8 & 0xFD | (2 * ((dir ^ (j == 0)) & 1 | 4)));
    }
    *v8 = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425620
// Name: public: void OptimizedModel::COptimizeSubDBuilder::TagCreases(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::TagCreases(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // esi
  int v2; // eax
  int *v3; // edi
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  const mstudio_meshvertexdata_t *const *m_vtxData; // ecx
  const mstudio_meshvertexdata_t *v11; // edi
  int *v12; // ecx
  float *v13; // ebx
  int v14; // eax
  unsigned int v15; // kr00_4
  int v16; // ecx
  unsigned int v17; // esi
  bool v18; // zf
  int v19; // ecx
  const mstudio_meshvertexdata_t *v20; // edi
  const mstudio_modelvertexdata_t *modelvertexdata; // ebx
  unsigned int v22; // esi
  int quad0vtx1ID; // [esp+4h] [ebp-24h]
  int quad1vtx1ID; // [esp+8h] [ebp-20h]
  OptimizedModel::Vertex_t *m_pMemory; // [esp+Ch] [ebp-1Ch]
  OptimizedModel::Vertex_t *v26; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  int *v28; // [esp+14h] [ebp-14h]
  _WORD *v29; // [esp+18h] [ebp-10h]
  OptimizedModel::SubD_Face_t *pPatch; // [esp+20h] [ebp-8h]
  int *v32; // [esp+24h] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; (unsigned __int16)i < v1->m_numPatches; v2 = (unsigned __int16)i )
  {
    v3 = dword_63F588;
    v4 = (int)&v1->m_faceList->m_Memory.m_pMemory[v2];
    pPatch = (OptimizedModel::SubD_Face_t *)v4;
    v32 = dword_63F588;
    v29 = (_WORD *)(v4 + 154);
    v28 = (int *)(v4 + 236);
    while ( 1 )
    {
      v5 = *v28;
      if ( *v28 != 0 )
      {
        v6 = *(_DWORD *)(v5 + 12);
        v7 = *(unsigned __int8 *)(v5 + 8);
        quad0vtx1ID = *(unsigned __int16 *)(v4 + 2 * *v3 + 2);
        v8 = *(unsigned __int16 *)(v6 + 2 * MOD4_0[v7] + 2);
        v9 = *(unsigned __int16 *)(v6 + 2 * dword_63F588[v7] + 2);
        quad1vtx1ID = v8;
        m_vtxData = v1->m_vtxData;
        v11 = *m_vtxData;
        m_pMemory = v1->m_vtxList->m_Memory.m_pMemory;
        v12 = **(int ***)m_vtxData;
        v13 = (float *)(*v12
                      + 48
                      * ((int)v11[-1].modelvertexdata
                       + *(v12 - 6) / 0x30u
                       + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v9 + v9))
                      + 28);
        v14 = pPatch->vtxIDs[*(v32 - 1)];
        v15 = *(v12 - 6);
        v16 = *v12;
        v17 = (unsigned int)v11[-1].modelvertexdata
            + v15 / 0x30
            + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v14 + v14);
        v18 = *v13 == *(float *)(v16 + 48 * v17 + 28);
        v19 = v16 + 48 * v17 + 28;
        if ( !v18
          || v13[1] != *(float *)(v19 + 4)
          || v13[2] != *(float *)(v19 + 8)
          || (v20 = *this->m_vtxData,
              v26 = this->m_vtxList->m_Memory.m_pMemory,
              modelvertexdata = v20->modelvertexdata,
              v22 = (unsigned int)v20[-1].modelvertexdata
                  + (unsigned int)v20->modelvertexdata[-3].pVertexData / 0x30
                  + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad0vtx1ID + quad0vtx1ID),
              *((float *)modelvertexdata->pVertexData
              + 12
              * ((int)v20[-1].modelvertexdata
               + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
               + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
              + 7) != *((float *)v20->modelvertexdata->pVertexData + 12 * v22 + 7))
          || *((float *)modelvertexdata->pVertexData
             + 12
             * ((int)v20[-1].modelvertexdata
              + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
             + 8) != *((float *)modelvertexdata->pVertexData + 12 * v22 + 8)
          || *((float *)modelvertexdata->pVertexData
             + 12
             * ((int)v20[-1].modelvertexdata
              + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
             + 9) != *((float *)modelvertexdata->pVertexData + 12 * v22 + 9) )
        {
          *v29 = 1;
          pPatch->bndVtx[*(v32 - 1)] = 1;
          pPatch->bndVtx[*v32] = 1;
        }
        v1 = this;
      }
      ++v29;
      v28 += 4;
      v3 = v32 + 1;
      v32 = v3;
      if ( (int)v3 >= (int)dword_63F598 )
        break;
      v4 = (int)pPatch;
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004258D0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::RemapIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::RemapIndices(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v5; // eax
  int *v6; // edi
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // edi
  int v8; // eax
  int v9; // ecx
  const mstudio_meshvertexdata_t *v10; // esi
  _QWORD *pVertexData; // ecx
  __int64 v12; // xmm0_8
  _QWORD *v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // esi
  OptimizedModel::COptimizeSubDBuilder *v17; // edx
  int v18; // esi
  float vPosi_8; // [esp+14h] [ebp-28h]
  __int64 vPosj; // [esp+18h] [ebp-24h]
  int v21; // [esp+28h] [ebp-14h]
  int v22; // [esp+2Ch] [ebp-10h]
  int j; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  int ia; // [esp+34h] [ebp-8h]

  v1 = this;
  for ( i = 0; i < v1->m_vtxList->m_Size; ++i )
  {
    m_Size = v1->m_IndexRemapTable.m_Size;
    m_nAllocationCount = v1->m_IndexRemapTable.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_IndexRemapTable,
        num: m_Size - m_nAllocationCount + 1);
    ++v1->m_IndexRemapTable.m_Size;
    m_pMemory = v1->m_IndexRemapTable.m_Memory.m_pMemory;
    v5 = v1->m_IndexRemapTable.m_Size - m_Size - 1;
    v1->m_IndexRemapTable.m_pElements = m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
    v6 = &v1->m_IndexRemapTable.m_Memory.m_pMemory[m_Size];
    if ( v6 != nullptr )
      *v6 = i;
  }
  m_vtxList = v1->m_vtxList;
  v8 = m_vtxList->m_Size;
  v21 = 0;
  if ( v8 > 0 )
  {
    ia = 0;
    do
    {
      v9 = v21 + 1;
      j = v21 + 1;
      if ( v21 + 1 < v8 )
      {
        v22 = ia * 9 + 9;
        do
        {
          v10 = *v1->m_vtxData;
          pVertexData = v10->modelvertexdata->pVertexData;
          v12 = pVertexData[6
                          * (int)((int)v10[-1].modelvertexdata
                                + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
                                + m_vtxList->m_Memory.m_pMemory[ia].origMeshVertID)
                          + 2];
          vPosi_8 = *(float *)&pVertexData[6
                                         * (int)((int)v10[-1].modelvertexdata
                                               + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
                                               + m_vtxList->m_Memory.m_pMemory[ia].origMeshVertID)
                                         + 3];
          v13 = pVertexData;
          v14 = (unsigned int)v10[-1].modelvertexdata
              + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&m_vtxList->m_Memory.m_pMemory->origMeshVertID + v22);
          vPosj = v13[6 * v14 + 2];
          if ( *(float *)&vPosj == *(float *)&v12
            && *((float *)&vPosj + 1) == *((float *)&v12 + 1)
            && *(float *)&v13[6 * v14 + 3] == vPosi_8 )
          {
            v15 = j;
            v16 = v21;
            if ( v21 >= j )
              v16 = j;
            v17 = this;
            this->m_IndexRemapTable.m_Memory.m_pMemory[j] = v16;
            v18 = v21;
            if ( v21 >= j )
              v18 = j;
            this->m_IndexRemapTable.m_Memory.m_pMemory[v21] = v18;
          }
          else
          {
            v15 = j;
            v17 = this;
          }
          m_vtxList = v17->m_vtxList;
          v22 += 9;
          v1 = this;
          j = v15 + 1;
        }
        while ( v15 + 1 < m_vtxList->m_Size );
        v9 = v21 + 1;
      }
      m_vtxList = v1->m_vtxList;
      v8 = m_vtxList->m_Size;
      ++ia;
      v21 = v9;
    }
    while ( v9 < v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425AA0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(
        OptimizedModel::COptimizeSubDBuilder *this)
{
  int v2; // edi
  OptimizedModel::Orientation *m_pMemory; // ebx
  bool v4; // zf
  OptimizedModel::SubD_Face_t *v5; // edx
  OptimizedModel::HalfEdge *halfEdges; // eax
  int v7; // edi
  OptimizedModel::HalfEdge *v8; // [esp-8h] [ebp-30h]
  int m_numPatches; // [esp-4h] [ebp-2Ch]
  CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > orientationArray; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v11; // [esp+20h] [ebp-8h]
  OptimizedModel::HalfEdge *pEdges; // [esp+24h] [ebp-4h]

  v2 = 0;
  m_numPatches = this->m_numPatches;
  memset(&orientationArray, 0, sizeof(orientationArray));
  CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int>>::InsertMultipleBefore(
    this: &orientationArray,
    elem: 0,
    num: m_numPatches);
  m_pMemory = orientationArray.m_Memory.m_pMemory;
  if ( this->m_numPatches > 0 )
  {
    v11 = 0;
    do
    {
      v4 = (*(_BYTE *)&m_pMemory[v2] & 4) == 0;
      v5 = this->m_faceList->m_Memory.m_pMemory;
      halfEdges = v5[v11 / 0x12C].halfEdges;
      pEdges = halfEdges;
      if ( v4 )
      {
        v8 = &v5[v11 / 0x12C].halfEdges[1];
        m_pMemory[v2] = (OptimizedModel::Orientation)(*(_BYTE *)&m_pMemory[v2] & 0xFA | 4);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: v8, dir: false);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: pEdges + 3, dir: true);
        halfEdges = pEdges;
      }
      if ( (*(_BYTE *)&m_pMemory[v2] & 8) == 0 )
      {
        m_pMemory[v2] = (OptimizedModel::Orientation)(*(_BYTE *)&m_pMemory[v2] & 0xF5 | 8);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: halfEdges, dir: false);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: pEdges + 2, dir: true);
      }
      v11 += 300;
      ++v2;
    }
    while ( v2 < this->m_numPatches );
  }
  v7 = 0;
  if ( this->m_numPatches > 0 )
  {
    v11 = 0;
    do
    {
      OptimizedModel::COptimizeSubDBuilder::RotateFace(
        this,
        pPatch: &this->m_faceList->m_Memory.m_pMemory[v11 / 0x12C],
        nTimesToRotate: nTimesToRotate[2 * ((*(_BYTE *)&m_pMemory[v7] & 2) != 0) + (*(_BYTE *)&m_pMemory[v7] & 1)]);
      v11 += 300;
      ++v7;
    }
    while ( v7 < this->m_numPatches );
  }
  if ( orientationArray.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00425BD0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ProcessPatches(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ProcessPatches(
        OptimizedModel::COptimizeSubDBuilder *this,
        bool bIsTagged,
        bool bMendVertices)
{
  int v3; // edi
  _WORD *v5; // eax
  int v6; // esi
  int j; // ecx
  int v8; // edi
  _DWORD *v9; // edx
  OptimizedModel::SubD_Face_t *v10; // esi
  OptimizedModel::SubD_Face_t *v11; // edi
  int m; // esi
  int n; // esi
  int m_Size; // esi
  int v15; // edi
  OptimizedModel::SubD_Face_t *m_pMemory; // ecx
  int v17; // eax
  int v18; // eax
  OptimizedModel::SubD_Face_t *v19; // edi
  int v20; // eax
  int ii; // edx
  OptimizedModel::SubD_Face_t *v22; // esi
  OptimizedModel::SubD_Face_t *v23; // edi
  OptimizedModel::SubD_Face_t *v24; // eax
  int v25; // edx
  OptimizedModel::SubD_Face_t *v26; // edi
  OptimizedModel::SubD_Face_t *v27; // esi
  bool v28; // zf
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > regFaceList; // [esp+Ch] [ebp-34h] BYREF
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > extraFaceList; // [esp+20h] [ebp-20h] BYREF
  OptimizedModel::SubD_Face_t *pPatch; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  int k; // [esp+3Ch] [ebp-4h]
  int bIsTaggeda; // [esp+48h] [ebp+8h]
  int bIsTaggedb; // [esp+48h] [ebp+8h]
  int bIsTaggedc; // [esp+48h] [ebp+8h]
  int bIsTaggedd; // [esp+48h] [ebp+8h]

  v3 = 0;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    pPatch = nullptr;
    do
    {
      v5 = (unsigned __int16 *)((char *)&pPatch->patchID + (unsigned int)this->m_faceList->m_Memory.m_pMemory);
      k = 0;
      v6 = 0;
      for ( j = 77; j < 81; ++j )
      {
        *v5 = i;
        if ( !bIsTagged )
        {
          v5[j - 4] = 0;
          v5[j] = 0;
          v5[j + 4] = 0;
        }
        v8 = k;
        v5[j + 8] = 0;
        v5[j - 12] = 0;
        v5[j - 8] = 0;
        v5[j + 12] = -1;
        v5[2 * v8 + 93] = 0x4000;
        v5[2 * v8 + 94] = 0x4000;
        v9 = &v5[v6 + 118];
        *(_DWORD *)&v5[v6 + 120] = v9;
        *v9 = 0;
        LOBYTE(v5[v6 + 122]) = v8;
        *(_DWORD *)&v5[v6 + 124] = v5;
        v6 += 8;
        k = v8 + 1;
      }
      ++pPatch;
      v3 = 0;
      ++i;
    }
    while ( i < this->m_numPatches );
  }
  OptimizedModel::COptimizeSubDBuilder::RemapIndices(this);
  OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(this);
  OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(this);
  OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(this);
  if ( !bIsTagged )
    OptimizedModel::COptimizeSubDBuilder::TagCreases(this);
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    pPatch = nullptr;
    do
    {
      v10 = (OptimizedModel::SubD_Face_t *)((char *)pPatch + (unsigned int)this->m_faceList->m_Memory.m_pMemory);
      for ( bIsTaggeda = 0; bIsTaggeda < 4; ++bIsTaggeda )
      {
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(this, pPatch: v10, k: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(this, baseQuad: v10, baseLocalID: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(this, baseQuad: v10, baseLocalID: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(
          this,
          a2: (int)this,
          baseQuad: v10,
          baseLocalID: bIsTaggeda);
      }
      ++pPatch;
      v3 = 0;
      ++i;
    }
    while ( i < this->m_numPatches );
  }
  pPatch = nullptr;
  if ( this->m_numPatches > 0 )
  {
    bIsTaggedb = 0;
    do
    {
      v11 = &this->m_faceList->m_Memory.m_pMemory[bIsTaggedb];
      for ( m = 0; m < 4; ++m )
        OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(this, baseQuad: v11, baseLocalID: m);
      ++bIsTaggedb;
      pPatch = (OptimizedModel::SubD_Face_t *)((char *)pPatch + 1);
    }
    while ( (int)pPatch < this->m_numPatches );
    v3 = 0;
  }
  for ( n = 0; n < this->m_numPatches; ++v3 )
  {
    OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(
      this,
      baseQuad: &this->m_faceList->m_Memory.m_pMemory[v3]);
    ++n;
  }
  OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(this);
  m_Size = 0;
  memset(&regFaceList, 0, sizeof(regFaceList));
  memset(&extraFaceList, 0, sizeof(extraFaceList));
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    bIsTaggedc = 0;
    do
    {
      pPatch = &this->m_faceList->m_Memory.m_pMemory[bIsTaggedc];
      if ( OptimizedModel::FaceIsRegular(patch: pPatch) )
      {
        v15 = m_Size;
        if ( m_Size + 1 > regFaceList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
            this: &regFaceList.m_Memory,
            num: m_Size - regFaceList.m_Memory.m_nAllocationCount + 1);
          m_Size = regFaceList.m_Size;
        }
        m_pMemory = regFaceList.m_Memory.m_pMemory;
        regFaceList.m_Size = ++m_Size;
        regFaceList.m_pElements = regFaceList.m_Memory.m_pMemory;
        if ( m_Size - v15 - 1 > 0 )
        {
          _V_memmove(
            dest: &regFaceList.m_Memory.m_pMemory[v15 + 1],
            src: &regFaceList.m_Memory.m_pMemory[v15],
            count: 300 * (m_Size - v15 - 1));
          m_pMemory = regFaceList.m_Memory.m_pMemory;
        }
      }
      else
      {
        v15 = extraFaceList.m_Size;
        v17 = extraFaceList.m_Size;
        if ( extraFaceList.m_Size + 1 > extraFaceList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
            this: &extraFaceList.m_Memory,
            num: extraFaceList.m_Size - extraFaceList.m_Memory.m_nAllocationCount + 1);
          v17 = extraFaceList.m_Size;
        }
        m_pMemory = extraFaceList.m_Memory.m_pMemory;
        extraFaceList.m_Size = v17 + 1;
        v18 = v17 - v15;
        extraFaceList.m_pElements = extraFaceList.m_Memory.m_pMemory;
        if ( v18 > 0 )
        {
          _V_memmove(
            dest: &extraFaceList.m_Memory.m_pMemory[v15 + 1],
            src: &extraFaceList.m_Memory.m_pMemory[v15],
            count: 300 * v18);
          m_pMemory = extraFaceList.m_Memory.m_pMemory;
        }
      }
      v19 = &m_pMemory[v15];
      if ( v19 != nullptr )
      {
        qmemcpy(v19, pPatch, sizeof(OptimizedModel::SubD_Face_t));
        m_Size = regFaceList.m_Size;
      }
      ++bIsTaggedc;
      ++i;
    }
    while ( i < this->m_numPatches );
  }
  if ( m_Size > 0 )
  {
    v20 = 0;
    for ( ii = m_Size; ii != 0; --ii )
    {
      v22 = &regFaceList.m_Memory.m_pMemory[v20];
      v23 = &this->m_faceList->m_Memory.m_pMemory[v20++];
      qmemcpy(v23, v22, sizeof(OptimizedModel::SubD_Face_t));
    }
    m_Size = regFaceList.m_Size;
  }
  if ( extraFaceList.m_Size > 0 )
  {
    v24 = extraFaceList.m_Memory.m_pMemory;
    v25 = m_Size;
    bIsTaggedd = extraFaceList.m_Size;
    do
    {
      v26 = &this->m_faceList->m_Memory.m_pMemory[v25];
      v27 = v24++;
      ++v25;
      v28 = bIsTaggedd-- == 1;
      qmemcpy(v26, v27, sizeof(OptimizedModel::SubD_Face_t));
    }
    while ( !v28 );
  }
  if ( extraFaceList.m_Memory.m_nGrowSize >= 0 && extraFaceList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: extraFaceList.m_Memory.m_pMemory);
  if ( regFaceList.m_Memory.m_nGrowSize >= 0 && regFaceList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: regFaceList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00425F60
// Name: public: OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(class CUtlVector<struct OptimizedModel::SubD_Face_t,class CUtlMemory<struct OptimizedModel::SubD_Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> const __near &,struct mstudio_meshvertexdata_t const __near * const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::COptimizeSubDBuilder *__thiscall OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(
        OptimizedModel::COptimizeSubDBuilder *this,
        CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *subDFaceList,
        const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vertexList,
        const mstudio_meshvertexdata_t *const *vertexData,
        bool bIsTagged,
        bool bMendVertices)
{
  this->m_vtxList = vertexList;
  this->m_faceList = subDFaceList;
  this->m_vtxData = vertexData;
  this->m_IndexRemapTable.m_Memory.m_pMemory = nullptr;
  this->m_IndexRemapTable.m_Memory.m_nAllocationCount = 0;
  this->m_IndexRemapTable.m_Memory.m_nGrowSize = 0;
  this->m_IndexRemapTable.m_Size = 0;
  this->m_IndexRemapTable.m_pElements = nullptr;
  this->m_numPatches = subDFaceList->m_Size;
  OptimizedModel::COptimizeSubDBuilder::ProcessPatches(this, bIsTagged, bMendVertices);
  return this;
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0041CFD0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *pPatch,
        unsigned __int16 k)
{
  OptimizedModel::HalfEdge *v3; // eax
  OptimizedModel::HalfEdge *v4; // ecx
  OptimizedModel::HalfEdge *twin; // eax

  v3 = &pPatch->halfEdges[k];
  while ( 1 )
  {
    v4 = v3;
    if ( v3->patch->bndEdge[v3->localID] != 0 )
      break;
    twin = v3->twin;
    if ( twin == nullptr )
      break;
    v3 = &twin->patch->halfEdges[dword_636540[twin->localID]];
    if ( v3 == nullptr )
      break;
    if ( v3 == &pPatch->halfEdges[k] )
      return;
  }
  pPatch->halfEdges[k].sectorStart = v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041D050
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  OptimizedModel::HalfEdge *sectorStart; // edx
  __int16 v4; // di
  OptimizedModel::HalfEdge *v5; // ecx
  OptimizedModel::HalfEdge *v6; // eax
  OptimizedModel::HalfEdge *twin; // eax
  int localID; // eax
  OptimizedModel::SubD_Face_t *patch; // edx
  OptimizedModel::HalfEdge *v10; // ecx
  int v11; // eax
  int v12; // eax

  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  v4 = 0;
  v5 = sectorStart;
  if ( sectorStart->twin != nullptr )
  {
    v6 = &sectorStart->twin->patch->halfEdges[dword_636540[sectorStart->twin->localID]];
    if ( (OptimizedModel::SubD_Face_t *)((char *)sectorStart->twin->patch + 16
                                                                          * dword_636540[sectorStart->twin->localID]) != (OptimizedModel::SubD_Face_t *)-236 )
    {
      while ( v6 != sectorStart )
      {
        v5 = v6;
        twin = v6->twin;
        if ( twin != nullptr )
        {
          v6 = &twin->patch->halfEdges[dword_636540[twin->localID]];
          if ( v6 != nullptr )
            continue;
        }
        goto LABEL_8;
      }
      v5 = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
    }
  }
LABEL_8:
  localID = v5->localID;
  patch = v5->patch;
  if ( patch->bndEdge[localID] != 0 )
    v4 = 1;
  v10 = v5->twin;
  v11 = (int)&patch->halfEdges[dword_636568[localID]];
  do
  {
    if ( *(_WORD *)(*(_DWORD *)(v11 + 12) + 2 * *(unsigned __int8 *)(v11 + 8) + 154) != 0 )
      ++v4;
    v12 = *(_DWORD *)v11;
    if ( v12 == 0 )
      break;
    v11 = *(_DWORD *)(v12 + 12) + 16 * dword_636568[*(unsigned __int8 *)(v12 + 8)] + 236;
    if ( v11 == 0 )
      break;
  }
  while ( (OptimizedModel::HalfEdge *)v11 != v10 );
  if ( v4 == 1 )
  {
    baseQuad->halfEdges[baseLocalID].sectorStart = &baseQuad->halfEdges[baseLocalID];
    baseQuad->bndVtx[baseLocalID] = 0;
  }
  else if ( (unsigned __int16)v4 >= 2u )
  {
    baseQuad->bndVtx[baseLocalID] = 1;
    if ( (unsigned __int16)v4 > 2u )
      baseQuad->cornerVtx[baseLocalID] = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D180
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  unsigned __int16 *v5; // edx
  unsigned __int16 *vtx1RingSize; // eax
  int i; // esi
  int v8; // ebx
  int v9; // eax
  OptimizedModel::HalfEdge *sectorStart; // edx
  int v11; // edx
  int v12; // edx
  OptimizedModel::HalfEdge *heEnd; // [esp+Ch] [ebp-4h]
  unsigned __int16 *oneRing; // [esp+18h] [ebp+8h]
  OptimizedModel::HalfEdge *heBase; // [esp+1Ch] [ebp+Ch]

  v5 = baseQuad->oneRing;
  oneRing = baseQuad->oneRing;
  if ( baseLocalID != 0 )
  {
    vtx1RingSize = baseQuad->vtx1RingSize;
    for ( i = baseLocalID; i != 0; --i )
    {
      v8 = *vtx1RingSize++;
      v5 += v8;
    }
    oneRing = v5;
  }
  v9 = baseLocalID;
  baseQuad->vtx1RingCenterQuadOffset[baseLocalID] = 1;
  baseQuad->valences[baseLocalID] = 0;
  baseQuad->vtx1RingSize[baseLocalID] = 0;
  heBase = &baseQuad->halfEdges[MOD4[baseLocalID]];
  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  oneRing[baseQuad->vtx1RingSize[baseLocalID]++] = sectorStart->patch->vtxIDs[MOD4[sectorStart->localID]];
  ++baseQuad->valences[baseLocalID];
  oneRing[baseQuad->vtx1RingSize[baseLocalID]] = sectorStart->patch->vtxIDs[MOD4[sectorStart->localID + 1]];
  ++baseQuad->vtx1RingSize[v9];
  heEnd = sectorStart->twin;
  v11 = (int)&sectorStart->patch->halfEdges[dword_636568[sectorStart->localID]];
  while ( 1 )
  {
    oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                     + 2 * MOD4[*(unsigned __int8 *)(v11 + 8) + 3]
                                                     + 2);
    ++baseQuad->valences[v9];
    oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                     + 2 * MOD4[*(unsigned __int8 *)(v11 + 8)]
                                                     + 2);
    if ( *(OptimizedModel::HalfEdge **)v11 == heBase )
      baseQuad->vtx1RingCenterQuadOffset[v9] = baseQuad->vtx1RingSize[v9] - 1;
    if ( *(_WORD *)(*(_DWORD *)(v11 + 12) + 2 * *(unsigned __int8 *)(v11 + 8) + 154) != 0 && baseQuad->bndVtx[v9] != 0 )
      break;
    v12 = *(_DWORD *)v11;
    if ( v12 == 0 )
      break;
    v11 = *(_DWORD *)(v12 + 12) + 16 * dword_636568[*(unsigned __int8 *)(v12 + 8)] + 236;
    if ( v11 == 0 )
      break;
    if ( (OptimizedModel::HalfEdge *)v11 == heEnd )
    {
      oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                       + 2 * MOD4[*(unsigned __int8 *)(v11 + 8) + 3]
                                                       + 2);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D340
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  int v3; // edx
  OptimizedModel::HalfEdge *sectorStart; // eax
  int v5; // eax
  char v6; // cl
  int v7; // eax
  __int16 nbCorners_4; // [esp+Ch] [ebp-4h]
  OptimizedModel::HalfEdge *heEnd; // [esp+1Ch] [ebp+Ch]

  v3 = baseLocalID;
  baseQuad->nbCornerVtx[baseLocalID] = 0;
  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  baseQuad->nbCornerVtx[baseLocalID] |= sectorStart->patch->cornerVtx[MOD4[sectorStart->localID + 1]] == 2;
  nbCorners_4 = 1;
  heEnd = sectorStart->twin;
  v5 = (int)&sectorStart->patch->halfEdges[dword_636568[sectorStart->localID]];
  do
  {
    v6 = nbCorners_4++;
    baseQuad->nbCornerVtx[v3] |= (*(_WORD *)(*(_DWORD *)(v5 + 12) + 2 * *(unsigned __int8 *)(v5 + 8) + 162) == 2) << v6;
    if ( *(_WORD *)(*(_DWORD *)(v5 + 12) + 2 * *(unsigned __int8 *)(v5 + 8) + 154) != 0 && baseQuad->bndVtx[v3] != 0 )
      break;
    v7 = *(_DWORD *)v5;
    if ( v7 == 0 )
      break;
    v5 = *(_DWORD *)(v7 + 12) + 16 * dword_636568[*(unsigned __int8 *)(v7 + 8)] + 236;
    if ( v5 == 0 )
      break;
  }
  while ( (OptimizedModel::HalfEdge *)v5 != heEnd );
}

//------------------------------------------------------------------------------
// Address: 0x0041D440
// Name: private: void OptimizedModel::COptimizeSubDBuilder::RotateFace(struct OptimizedModel::SubD_Face_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::RotateFace(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *pPatch,
        int nTimesToRotate)
{
  OptimizedModel::HalfEdge *v3; // edx
  OptimizedModel::HalfEdge *v4; // esi
  OptimizedModel::HalfEdge *halfEdges; // ecx
  int v6; // ebx
  unsigned __int16 *bndEdge; // edx
  __int64 v8; // xmm0_8
  unsigned __int8 v9; // al
  OptimizedModel::SubD_Face_t v10; // [esp+0h] [ebp-13Ch] BYREF
  OptimizedModel::HalfEdge *twin; // [esp+130h] [ebp-Ch]
  OptimizedModel::HalfEdge *v12; // [esp+134h] [ebp-8h]
  OptimizedModel::HalfEdge *v13; // [esp+138h] [ebp-4h]

  if ( nTimesToRotate > 0 )
  {
    do
    {
      twin = pPatch->halfEdges[1].twin;
      v12 = pPatch->halfEdges[2].twin;
      v3 = pPatch->halfEdges[3].twin;
      v10 = *pPatch;
      v4 = pPatch->halfEdges[0].twin;
      halfEdges = pPatch->halfEdges;
      v13 = v3;
      v6 = 3;
      bndEdge = pPatch->bndEdge;
      do
      {
        *(bndEdge - 76) = v10.vtxIDs[v6 % 4];
        *bndEdge = v10.bndEdge[v6 % 4];
        v8 = *(_QWORD *)&v10.halfEdges[v6 % 4].twin;
        *(bndEdge - 4) = v10.bndVtx[v6 % 4];
        *(_QWORD *)&halfEdges->twin = v8;
        v9 = v6 - 3;
        *(_QWORD *)&halfEdges->localID = *(_QWORD *)&v10.halfEdges[v6 % 4].localID;
        ++v6;
        halfEdges->localID = v9;
        halfEdges->sectorStart = halfEdges;
        ++bndEdge;
        ++halfEdges;
      }
      while ( v6 - 3 < 4 );
      if ( v4 != nullptr )
        v4->twin = &pPatch->halfEdges[1];
      if ( twin != nullptr )
        twin->twin = &pPatch->halfEdges[2];
      if ( v12 != nullptr )
        v12->twin = &pPatch->halfEdges[3];
      if ( v13 != nullptr )
        v13->twin = pPatch->halfEdges;
      --nTimesToRotate;
    }
    while ( nTimesToRotate != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D5F0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::SubD_Face_t *v1; // edi
  int v2; // eax
  unsigned __int16 *minOneRingIndex; // esi
  int *m_pMemory; // ecx
  int v5; // ebx
  unsigned __int16 *v6; // esi
  unsigned __int16 v7; // di
  int v8; // edx
  bool v9; // zf
  OptimizedModel::SubD_Face_t *pPatch; // [esp+0h] [ebp-24h]
  int *v11; // [esp+4h] [ebp-20h]
  int i; // [esp+8h] [ebp-1Ch]
  int v13; // [esp+Ch] [ebp-18h]
  unsigned __int16 *v14; // [esp+10h] [ebp-14h]
  unsigned __int16 nMinNeighborOffset; // [esp+14h] [ebp-10h]
  int nMinNeighborIdx; // [esp+18h] [ebp-Ch]
  OptimizedModel::COptimizeSubDBuilder *v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]

  v17 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v18 = 0;
    while ( 1 )
    {
      v1 = &this->m_faceList->m_Memory.m_pMemory[v18];
      v2 = 0;
      minOneRingIndex = v1->minOneRingIndex;
      pPatch = v1;
      v14 = v1->minOneRingIndex;
      v13 = 4;
      while ( 1 )
      {
        m_pMemory = this->m_IndexRemapTable.m_Memory.m_pMemory;
        nMinNeighborIdx = m_pMemory[v1->oneRing[v2]];
        v5 = *(minOneRingIndex - 12) + v2 - 1;
        v11 = m_pMemory;
        nMinNeighborOffset = 0;
        if ( v2 <= v5 )
        {
          v6 = &v1->oneRing[v2];
          v7 = 0;
          v8 = v5 - v2 + 1;
          while ( 1 )
          {
            if ( m_pMemory[*v6] < nMinNeighborIdx )
            {
              nMinNeighborIdx = m_pMemory[*v6];
              nMinNeighborOffset = v7;
            }
            ++v6;
            ++v7;
            if ( --v8 == 0 )
              break;
            m_pMemory = v11;
          }
          v1 = pPatch;
          minOneRingIndex = v14;
        }
        *minOneRingIndex++ = nMinNeighborOffset;
        v9 = v13-- == 1;
        v2 = v5 + 1;
        v14 = minOneRingIndex;
        if ( v9 )
          break;
        this = v17;
      }
      ++v18;
      if ( ++i >= v17->m_numPatches )
        break;
      this = v17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D6C0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // edx
  OptimizedModel::SubD_Face_t *v2; // eax
  unsigned __int16 *bndEdge; // ecx
  OptimizedModel::SubD_Face_t **p_patch; // eax
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // ecx
  const mstudio_meshvertexdata_t *v6; // edi
  int origMeshVertID; // esi
  int v8; // ebx
  _QWORD *pVertexData; // eax
  unsigned int v10; // esi
  __int64 v11; // xmm0_8
  unsigned int v12; // esi
  int v13; // eax
  float *v14; // ecx
  unsigned int v15; // esi
  bool v16; // zf
  int v17; // ecx
  int v18; // eax
  float *v19; // ecx
  unsigned int v20; // esi
  int v21; // ecx
  OptimizedModel::HalfEdge *v22; // eax
  __int64 v23; // [esp+0h] [ebp-48h]
  float v24; // [esp+8h] [ebp-40h]
  float v25; // [esp+14h] [ebp-34h]
  OptimizedModel::SubD_Face_t *pPatch; // [esp+18h] [ebp-30h]
  int m_numPatches; // [esp+1Ch] [ebp-2Ch]
  int i; // [esp+20h] [ebp-28h]
  int v29; // [esp+24h] [ebp-24h]
  OptimizedModel::Vertex_t *m_pMemory; // [esp+28h] [ebp-20h]
  int v31; // [esp+2Ch] [ebp-1Ch]
  int *v32; // [esp+30h] [ebp-18h]
  unsigned __int16 *v33; // [esp+34h] [ebp-14h]
  unsigned __int16 j; // [esp+3Ch] [ebp-Ch]
  OptimizedModel::SubD_Face_t *v36; // [esp+40h] [ebp-8h]
  OptimizedModel::SubD_Face_t **v37; // [esp+44h] [ebp-4h]

  v1 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v31 = 0;
    do
    {
      v2 = &v1->m_faceList->m_Memory.m_pMemory[v31];
      v32 = &MOD4[1];
      bndEdge = v2->bndEdge;
      pPatch = v2;
      p_patch = &v2->halfEdges[0].patch;
      v33 = bndEdge;
      v37 = p_patch;
      do
      {
        if ( *(p_patch - 3) == nullptr )
        {
          m_vtxList = v1->m_vtxList;
          v6 = *v1->m_vtxData;
          origMeshVertID = m_vtxList->m_Memory.m_pMemory[(*p_patch)->vtxIDs[MOD4[*((unsigned __int8 *)p_patch - 4)]]].origMeshVertID;
          v8 = *((unsigned __int8 *)p_patch - 4);
          pVertexData = v6->modelvertexdata->pVertexData;
          v10 = (unsigned int)v6[-1].modelvertexdata
              + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
              + origMeshVertID;
          v29 = 0;
          v11 = pVertexData[6 * v10 + 2];
          v25 = *(float *)&pVertexData[6 * v10 + 3];
          v12 = (unsigned int)v6[-1].modelvertexdata
              + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
              + m_vtxList->m_Memory.m_pMemory[(*v37)->vtxIDs[MOD4[v8 + 1]]].origMeshVertID;
          v24 = *(float *)&pVertexData[6 * v12 + 3];
          v23 = pVertexData[6 * v12 + 2];
          m_numPatches = this->m_numPatches;
          if ( m_numPatches > 0 )
          {
            m_pMemory = m_vtxList->m_Memory.m_pMemory;
            v36 = this->m_faceList->m_Memory.m_pMemory;
            while ( 2 )
            {
              for ( j = 0; j < 4u; ++j )
              {
                v13 = v36->vtxIDs[MOD4[j]];
                v14 = (float *)v6->modelvertexdata->pVertexData;
                v15 = (unsigned int)v6[-1].modelvertexdata
                    + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
                    + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v13 + v13);
                v16 = *(float *)&v23 == v14[12 * v15 + 4];
                v17 = (int)&v14[12 * v15 + 4];
                if ( v16 && *((float *)&v23 + 1) == *(float *)(v17 + 4) && v24 == *(float *)(v17 + 8) )
                {
                  v18 = v36->vtxIDs[MOD4[j + 1]];
                  v19 = (float *)v6->modelvertexdata->pVertexData;
                  v20 = (unsigned int)v6[-1].modelvertexdata
                      + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
                      + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v18 + v18);
                  v16 = *(float *)&v11 == v19[12 * v20 + 4];
                  v21 = (int)&v19[12 * v20 + 4];
                  if ( v16 && *((float *)&v11 + 1) == *(float *)(v21 + 4) && v25 == *(float *)(v21 + 8) )
                  {
                    v22 = &v36->halfEdges[j];
                    goto LABEL_17;
                  }
                }
              }
              ++v36;
              if ( ++v29 < m_numPatches )
                continue;
              break;
            }
          }
          v22 = nullptr;
LABEL_17:
          *(v37 - 3) = (OptimizedModel::SubD_Face_t *)v22;
          if ( v22 != nullptr )
          {
            v22->twin = (OptimizedModel::HalfEdge *)(v37 - 3);
          }
          else
          {
            *v33 = 1;
            pPatch->bndVtx[*(v32 - 1)] = 1;
            pPatch->bndVtx[*v32] = 1;
          }
          v1 = this;
          p_patch = v37;
        }
        ++v33;
        p_patch += 4;
        v37 = p_patch;
        ++v32;
      }
      while ( (int)v32 < (int)&MOD4[5] );
      ++v31;
      ++i;
    }
    while ( i < v1->m_numPatches );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D970
// Name: public: void OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // ebx
  OptimizedModel::SubD_Face_t *v2; // esi
  int *v3; // edi
  OptimizedModel::HalfEdge *halfEdges; // eax
  const mstudio_meshvertexdata_t *v5; // ecx
  _QWORD *pVertexData; // eax
  __int64 v7; // xmm0_8
  unsigned int v8; // ebx
  __int64 v9; // xmm0_8
  unsigned int v10; // ecx
  bool v11; // zf
  __int64 vC; // [esp+24h] [ebp-40h]
  float vC_8; // [esp+2Ch] [ebp-38h]
  float vB_8; // [esp+38h] [ebp-2Ch]
  __int64 vA; // [esp+3Ch] [ebp-28h]
  float vA_8; // [esp+44h] [ebp-20h]
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // [esp+4Ch] [ebp-18h]
  int i; // [esp+50h] [ebp-14h]
  int v19; // [esp+54h] [ebp-10h]
  OptimizedModel::HalfEdge *v20; // [esp+58h] [ebp-Ch]
  int v22; // [esp+60h] [ebp-4h]

  v1 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v22 = 0;
    do
    {
      v2 = &v1->m_faceList->m_Memory.m_pMemory[v22];
      v3 = MOD4;
      halfEdges = v2->halfEdges;
      v20 = v2->halfEdges;
      v19 = 4;
      do
      {
        if ( halfEdges->twin != nullptr && halfEdges->twin->twin != halfEdges )
        {
          _Msg(a1: "Topology error at vertices %d, %d, %d\n", v2->vtxIDs[v3[3]], v2->vtxIDs[*v3], v2->vtxIDs[v3[1]]);
          v5 = *v1->m_vtxData;
          pVertexData = v5->modelvertexdata->pVertexData;
          v7 = pVertexData[6
                         * (int)((int)v5[-1].modelvertexdata
                               + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
                               + v1->m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[3]]].origMeshVertID)
                         + 2];
          m_vtxList = this->m_vtxList;
          vA_8 = *(float *)&pVertexData[6
                                      * (int)((int)v5[-1].modelvertexdata
                                            + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
                                            + v1->m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[3]]].origMeshVertID)
                                      + 3];
          v8 = (unsigned int)v5[-1].modelvertexdata
             + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
             + m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[*v3]].origMeshVertID;
          vA = v7;
          v9 = pVertexData[6 * v8 + 2];
          vB_8 = *(float *)&pVertexData[6 * v8 + 3];
          v10 = 6
              * ((int)v5[-1].modelvertexdata
               + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
               + m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[1]]].origMeshVertID);
          vC = pVertexData[v10 + 2];
          vC_8 = *(float *)&pVertexData[v10 + 3];
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&vA, *((float *)&vA + 1), vA_8);
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&v9, *((float *)&v9 + 1), vB_8);
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&vC, *((float *)&vC + 1), vC_8);
          v1 = this;
          halfEdges = v20;
        }
        ++halfEdges;
        ++v3;
        v11 = v19-- == 1;
        v20 = halfEdges;
      }
      while ( !v11 );
      ++v22;
      ++i;
    }
    while ( i < v1->m_numPatches );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DBA0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(
        OptimizedModel::COptimizeSubDBuilder *this@<ecx>,
        int a2@<ebx>,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  const mstudio_meshvertexdata_t *v5; // ebx
  OptimizedModel::HalfEdge *sectorStart; // esi
  const mstudio_modelvertexdata_t *modelvertexdata; // edx
  int origMeshVertID; // ecx
  _QWORD *pVertexData; // eax
  unsigned int v10; // edx
  __int64 v11; // xmm0_8
  float v12; // ecx
  OptimizedModel::Vertex_t *m_pMemory; // eax
  const mstudio_modelvertexdata_t *v14; // edx
  int v15; // ecx
  unsigned int v16; // ecx
  Vector *v17; // eax
  const mstudio_meshvertexdata_t *v18; // ebx
  int v19; // ecx
  float *v20; // eax
  int v21; // esi
  const mstudio_meshvertexdata_t *v22; // ebx
  int v23; // ecx
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  int v27; // esi
  int v28; // eax
  int v29; // edx
  float v30; // xmm0_4
  long double v31; // [esp-4h] [ebp-50h]
  Vector vec; // [esp+8h] [ebp-44h] BYREF
  Vector center_pos; // [esp+14h] [ebp-38h]
  Vector eVec1; // [esp+20h] [ebp-2Ch] BYREF
  Vector eVec2; // [esp+2Ch] [ebp-20h] BYREF
  Vector center_nor; // [esp+38h] [ebp-14h] BYREF
  const mstudio_modelvertexdata_t *v37; // [esp+44h] [ebp-8h]
  int v38; // [esp+48h] [ebp-4h]

  if ( baseQuad->bndVtx[baseLocalID] != 0 )
  {
    LODWORD(v31) = a2;
    if ( baseQuad->cornerVtx[baseLocalID] != 0 )
    {
      v5 = *this->m_vtxData;
      sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
      modelvertexdata = v5->modelvertexdata;
      origMeshVertID = this->m_vtxList->m_Memory.m_pMemory[sectorStart->patch->vtxIDs[sectorStart->localID]].origMeshVertID;
      v38 = 9 * sectorStart->patch->vtxIDs[sectorStart->localID];
      pVertexData = v5->modelvertexdata->pVertexData;
      v10 = 6 * ((int)v5[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30 + origMeshVertID);
      v11 = pVertexData[v10 + 2];
      v12 = *(float *)&pVertexData[v10 + 3];
      m_pMemory = this->m_vtxList->m_Memory.m_pMemory;
      v14 = v5->modelvertexdata;
      center_pos.z = v12;
      v15 = m_pMemory[v38 / 9u].origMeshVertID;
      v37 = v14;
      v16 = (unsigned int)v5[-1].modelvertexdata + (unsigned int)v14[-3].pVertexData / 0x30 + v15;
      *(_QWORD *)&center_pos.x = v11;
      v17 = (Vector *)((char *)v14->pVertexData + 48 * v16 + 28);
      center_nor = *v17;
      VectorNormalize(vec: &center_nor);
      v18 = *this->m_vtxData;
      v19 = this->m_vtxList->m_Memory.m_pMemory[sectorStart->patch->vtxIDs[MOD4[sectorStart->localID + 1]]].origMeshVertID;
      v37 = v18->modelvertexdata;
      v20 = (float *)((char *)v37->pVertexData
                    + 48 * ((int)v18[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v19)
                    + 16);
      eVec1.x = *v20 - *(float *)&v11;
      eVec1.y = v20[1] - *((float *)&v11 + 1);
      eVec1.z = v20[2] - center_pos.z;
      *(float *)&v11 = (float)((float)(center_nor.y * eVec1.y) + (float)(center_nor.x * eVec1.x))
                     + (float)(center_nor.z * eVec1.z);
      vec.x = eVec1.x - (float)(center_nor.x * *(float *)&v11);
      vec.y = eVec1.y - (float)(center_nor.y * *(float *)&v11);
      vec.z = eVec1.z - (float)(center_nor.z * *(float *)&v11);
      VectorNormalize(&vec);
      v21 = (int)&sectorStart->patch->halfEdges[dword_636568[sectorStart->localID]];
      do
      {
        v22 = *this->m_vtxData;
        v23 = this->m_vtxList->m_Memory.m_pMemory[*(unsigned __int16 *)(*(_DWORD *)(v21 + 12)
                                                                      + 2 * MOD4[*(unsigned __int8 *)(v21 + 8)]
                                                                      + 2)].origMeshVertID;
        v37 = v22->modelvertexdata;
        v24 = *((float *)v37->pVertexData
              + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
              + 5);
        v25 = *((float *)v37->pVertexData
              + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
              + 6);
        eVec2.x = *((float *)v37->pVertexData
                  + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
                  + 4)
                - center_pos.x;
        eVec2.y = v24 - center_pos.y;
        eVec2.z = v25 - center_pos.z;
        v26 = (float)((float)(center_nor.y * (float)(v24 - center_pos.y)) + (float)(center_nor.x * eVec2.x))
            + (float)(center_nor.z * (float)(v25 - center_pos.z));
        vec.x = eVec2.x - (float)(center_nor.x * v26);
        vec.y = (float)(v24 - center_pos.y) - (float)(center_nor.y * v26);
        vec.z = (float)(v25 - center_pos.z) - (float)(center_nor.z * v26);
        VectorNormalize(&vec);
        if ( *(_WORD *)(*(_DWORD *)(v21 + 12) + 2 * *(unsigned __int8 *)(v21 + 8) + 154) != 0 )
          break;
        v27 = *(_DWORD *)v21;
        if ( v27 == 0 )
          break;
        v28 = *(unsigned __int8 *)(v27 + 8);
        v29 = *(_DWORD *)(v27 + 12);
        v21 = v29 + 16 * dword_636568[v28] + 236;
      }
      while ( v29 + 16 * dword_636568[v28] != -236 );
      VectorNormalize(vec: &eVec1);
      VectorNormalize(vec: &eVec2);
      v30 = (float)((float)(eVec2.y * eVec1.y) + (float)(eVec2.x * eVec1.x)) + (float)(eVec2.z * eVec1.z);
      __libm_sse2_acos(x: v31);
      baseQuad->loopGapAngle[baseLocalID] = (int)(v30 * 65535.0 * 0.1591549432737564);
    }
    else
    {
      baseQuad->loopGapAngle[baseLocalID] = 0xFFFF / (2 * (baseQuad->valences[baseLocalID] == 2) + 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DF40
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(struct OptimizedModel::SubD_Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad)
{
  unsigned __int16 *vUV0; // edx
  unsigned __int16 v3; // si
  unsigned __int16 origMeshVertID; // ax
  OptimizedModel::HalfEdge *twin; // ebx
  OptimizedModel::HalfEdge *v6; // ecx
  unsigned __int16 patchID; // di
  OptimizedModel::HalfEdge *v8; // eax
  __int16 v9; // si
  __int16 iMaxNeighborCorner; // [esp+10h] [ebp-28h]
  unsigned __int16 iNeighborPatchU; // [esp+14h] [ebp-24h]
  unsigned __int16 iNeighborPatch; // [esp+18h] [ebp-20h]
  unsigned __int16 p; // [esp+1Ch] [ebp-1Ch]
  OptimizedModel::HalfEdge *halfEdges; // [esp+20h] [ebp-18h]
  int i; // [esp+24h] [ebp-14h]
  OptimizedModel::COptimizeSubDBuilder *v16; // [esp+28h] [ebp-10h]
  unsigned __int16 v17; // [esp+2Ch] [ebp-Ch]
  unsigned __int16 v18; // [esp+30h] [ebp-8h]
  unsigned __int16 iMaxPatch; // [esp+34h] [ebp-4h]

  p = baseQuad->patchID;
  v16 = this;
  i = 0;
  halfEdges = baseQuad->halfEdges;
  vUV0 = baseQuad->vUV0;
  while ( 1 )
  {
    v3 = *(vUV0 - 100);
    origMeshVertID = this->m_vtxList->m_Memory.m_pMemory[v3].origMeshVertID;
    *vUV0 = origMeshVertID;
    vUV0[4] = origMeshVertID;
    vUV0[8] = origMeshVertID;
    twin = halfEdges->twin;
    v17 = -1;
    if ( halfEdges->twin != nullptr )
    {
      v17 = twin->patch->vtxIDs[(twin->localID + 1) & 3];
      if ( v17 != 0xFFFF && twin->patch->patchID > p )
        vUV0[4] = this->m_vtxList->m_Memory.m_pMemory[v17].origMeshVertID;
    }
    iNeighborPatchU = -1;
    v6 = baseQuad->halfEdges[(i + 3) % 4].twin;
    v18 = -1;
    if ( v6 != nullptr )
    {
      v18 = v6->patch->vtxIDs[v6->localID & 3];
      if ( v18 != 0xFFFF )
      {
        iNeighborPatchU = v6->patch->patchID;
        if ( iNeighborPatchU > p )
          vUV0[8] = v16->m_vtxList->m_Memory.m_pMemory[v18].origMeshVertID;
      }
    }
    patchID = baseQuad->patchID;
    v8 = twin;
    iNeighborPatch = -1;
    iMaxNeighborCorner = v3;
    iMaxPatch = baseQuad->patchID;
    if ( twin != nullptr )
    {
      do
      {
        v8 = v8->patch->halfEdges[dword_636540[v8->localID]].twin;
        v9 = -1;
        if ( v8 != nullptr )
          v9 = v8->patch->vtxIDs[(v8->localID + 1) & 3];
        if ( v9 != -1 )
        {
          iNeighborPatch = v8->patch->patchID;
          if ( iNeighborPatch <= iMaxPatch )
          {
            patchID = iMaxPatch;
          }
          else
          {
            patchID = v8->patch->patchID;
            iMaxPatch = patchID;
            iMaxNeighborCorner = v9;
          }
        }
      }
      while ( iNeighborPatch != iNeighborPatchU && v8 != nullptr );
      v3 = iMaxNeighborCorner;
    }
    if ( v6 != nullptr && v6->patch->patchID > patchID )
    {
      v3 = v18;
      patchID = v6->patch->patchID;
    }
    if ( twin != nullptr && twin->patch->patchID > patchID )
      v3 = v17;
    ++halfEdges;
    vUV0[12] = v16->m_vtxList->m_Memory.m_pMemory[v3].origMeshVertID;
    ++vUV0;
    if ( ++i >= 4 )
      break;
    this = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E160
// Name: private: void OptimizedModel::COptimizeSubDBuilder::Propagate(class CUtlVector<struct OptimizedModel::Orientation,class CUtlMemory<struct OptimizedModel::Orientation,int>> __near &,struct OptimizedModel::HalfEdge __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::Propagate(
        OptimizedModel::COptimizeSubDBuilder *this,
        CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > *orientationArray,
        OptimizedModel::HalfEdge *pEdge,
        bool dir)
{
  OptimizedModel::HalfEdge *i; // esi
  OptimizedModel::SubD_Face_t *patch; // edx
  OptimizedModel::HalfEdge *halfEdges; // eax
  int j; // ecx
  OptimizedModel::Orientation *v8; // eax
  OptimizedModel::Orientation v9; // cl

  for ( i = pEdge->twin;
        i != nullptr;
        i = i->patch->halfEdges[dword_636540[i->localID]].patch->halfEdges[dword_636540[i->patch->halfEdges[dword_636540[i->localID]].localID]].twin )
  {
    patch = i->patch;
    if ( patch == nullptr )
      break;
    halfEdges = patch->halfEdges;
    for ( j = 0; halfEdges != i; ++j )
      ++halfEdges;
    v8 = &orientationArray->m_Memory.m_pMemory[patch->patchID];
    if ( j == 1 || j == 3 )
    {
      if ( (*(_BYTE *)v8 & 4) != 0 )
        return;
      v9 = (OptimizedModel::Orientation)(*(_BYTE *)v8 & 0xFE | (dir ^ (j == 1)) & 1 | 4);
    }
    else
    {
      if ( (*(_BYTE *)v8 & 8) != 0 )
        return;
      v9 = (OptimizedModel::Orientation)(*(_BYTE *)v8 & 0xFD | (2 * ((dir ^ (j == 0)) & 1 | 4)));
    }
    *v8 = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E230
// Name: public: void OptimizedModel::COptimizeSubDBuilder::TagCreases(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::TagCreases(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // esi
  int v2; // eax
  int *v3; // edi
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  const mstudio_meshvertexdata_t *const *m_vtxData; // ecx
  const mstudio_meshvertexdata_t *v11; // edi
  int *v12; // ecx
  float *v13; // ebx
  int v14; // eax
  unsigned int v15; // kr00_4
  int v16; // ecx
  unsigned int v17; // esi
  bool v18; // zf
  int v19; // ecx
  const mstudio_meshvertexdata_t *v20; // edi
  const mstudio_modelvertexdata_t *modelvertexdata; // ebx
  unsigned int v22; // esi
  int quad0vtx1ID; // [esp+4h] [ebp-24h]
  int quad1vtx1ID; // [esp+8h] [ebp-20h]
  OptimizedModel::Vertex_t *m_pMemory; // [esp+Ch] [ebp-1Ch]
  OptimizedModel::Vertex_t *v26; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  int *v28; // [esp+14h] [ebp-14h]
  _WORD *v29; // [esp+18h] [ebp-10h]
  OptimizedModel::SubD_Face_t *pPatch; // [esp+20h] [ebp-8h]
  int *v32; // [esp+24h] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; (unsigned __int16)i < v1->m_numPatches; v2 = (unsigned __int16)i )
  {
    v3 = dword_636580;
    v4 = (int)&v1->m_faceList->m_Memory.m_pMemory[v2];
    pPatch = (OptimizedModel::SubD_Face_t *)v4;
    v32 = dword_636580;
    v29 = (_WORD *)(v4 + 154);
    v28 = (int *)(v4 + 236);
    while ( 1 )
    {
      v5 = *v28;
      if ( *v28 != 0 )
      {
        v6 = *(_DWORD *)(v5 + 12);
        v7 = *(unsigned __int8 *)(v5 + 8);
        quad0vtx1ID = *(unsigned __int16 *)(v4 + 2 * *v3 + 2);
        v8 = *(unsigned __int16 *)(v6 + 2 * MOD4_0[v7] + 2);
        v9 = *(unsigned __int16 *)(v6 + 2 * dword_636580[v7] + 2);
        quad1vtx1ID = v8;
        m_vtxData = v1->m_vtxData;
        v11 = *m_vtxData;
        m_pMemory = v1->m_vtxList->m_Memory.m_pMemory;
        v12 = **(int ***)m_vtxData;
        v13 = (float *)(*v12
                      + 48
                      * ((int)v11[-1].modelvertexdata
                       + *(v12 - 6) / 0x30u
                       + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v9 + v9))
                      + 28);
        v14 = pPatch->vtxIDs[*(v32 - 1)];
        v15 = *(v12 - 6);
        v16 = *v12;
        v17 = (unsigned int)v11[-1].modelvertexdata
            + v15 / 0x30
            + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v14 + v14);
        v18 = *v13 == *(float *)(v16 + 48 * v17 + 28);
        v19 = v16 + 48 * v17 + 28;
        if ( !v18
          || v13[1] != *(float *)(v19 + 4)
          || v13[2] != *(float *)(v19 + 8)
          || (v20 = *this->m_vtxData,
              v26 = this->m_vtxList->m_Memory.m_pMemory,
              modelvertexdata = v20->modelvertexdata,
              v22 = (unsigned int)v20[-1].modelvertexdata
                  + (unsigned int)v20->modelvertexdata[-3].pVertexData / 0x30
                  + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad0vtx1ID + quad0vtx1ID),
              *((float *)modelvertexdata->pVertexData
              + 12
              * ((int)v20[-1].modelvertexdata
               + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
               + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
              + 7) != *((float *)v20->modelvertexdata->pVertexData + 12 * v22 + 7))
          || *((float *)modelvertexdata->pVertexData
             + 12
             * ((int)v20[-1].modelvertexdata
              + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
             + 8) != *((float *)modelvertexdata->pVertexData + 12 * v22 + 8)
          || *((float *)modelvertexdata->pVertexData
             + 12
             * ((int)v20[-1].modelvertexdata
              + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
             + 9) != *((float *)modelvertexdata->pVertexData + 12 * v22 + 9) )
        {
          *v29 = 1;
          pPatch->bndVtx[*(v32 - 1)] = 1;
          pPatch->bndVtx[*v32] = 1;
        }
        v1 = this;
      }
      ++v29;
      v28 += 4;
      v3 = v32 + 1;
      v32 = v3;
      if ( (int)v3 >= (int)dword_636590 )
        break;
      v4 = (int)pPatch;
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E4E0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::RemapIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::RemapIndices(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v5; // eax
  int *v6; // edi
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // edi
  int v8; // eax
  int v9; // ecx
  const mstudio_meshvertexdata_t *v10; // esi
  _QWORD *pVertexData; // ecx
  __int64 v12; // xmm0_8
  _QWORD *v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // esi
  OptimizedModel::COptimizeSubDBuilder *v17; // edx
  int v18; // esi
  float vPosi_8; // [esp+14h] [ebp-28h]
  __int64 vPosj; // [esp+18h] [ebp-24h]
  int v21; // [esp+28h] [ebp-14h]
  int v22; // [esp+2Ch] [ebp-10h]
  int j; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  int ia; // [esp+34h] [ebp-8h]

  v1 = this;
  for ( i = 0; i < v1->m_vtxList->m_Size; ++i )
  {
    m_Size = v1->m_IndexRemapTable.m_Size;
    m_nAllocationCount = v1->m_IndexRemapTable.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_IndexRemapTable,
        num: m_Size - m_nAllocationCount + 1);
    ++v1->m_IndexRemapTable.m_Size;
    m_pMemory = v1->m_IndexRemapTable.m_Memory.m_pMemory;
    v5 = v1->m_IndexRemapTable.m_Size - m_Size - 1;
    v1->m_IndexRemapTable.m_pElements = m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
    v6 = &v1->m_IndexRemapTable.m_Memory.m_pMemory[m_Size];
    if ( v6 != nullptr )
      *v6 = i;
  }
  m_vtxList = v1->m_vtxList;
  v8 = m_vtxList->m_Size;
  v21 = 0;
  if ( v8 > 0 )
  {
    ia = 0;
    do
    {
      v9 = v21 + 1;
      j = v21 + 1;
      if ( v21 + 1 < v8 )
      {
        v22 = ia * 9 + 9;
        do
        {
          v10 = *v1->m_vtxData;
          pVertexData = v10->modelvertexdata->pVertexData;
          v12 = pVertexData[6
                          * (int)((int)v10[-1].modelvertexdata
                                + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
                                + m_vtxList->m_Memory.m_pMemory[ia].origMeshVertID)
                          + 2];
          vPosi_8 = *(float *)&pVertexData[6
                                         * (int)((int)v10[-1].modelvertexdata
                                               + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
                                               + m_vtxList->m_Memory.m_pMemory[ia].origMeshVertID)
                                         + 3];
          v13 = pVertexData;
          v14 = (unsigned int)v10[-1].modelvertexdata
              + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&m_vtxList->m_Memory.m_pMemory->origMeshVertID + v22);
          vPosj = v13[6 * v14 + 2];
          if ( *(float *)&vPosj == *(float *)&v12
            && *((float *)&vPosj + 1) == *((float *)&v12 + 1)
            && *(float *)&v13[6 * v14 + 3] == vPosi_8 )
          {
            v15 = j;
            v16 = v21;
            if ( v21 >= j )
              v16 = j;
            v17 = this;
            this->m_IndexRemapTable.m_Memory.m_pMemory[j] = v16;
            v18 = v21;
            if ( v21 >= j )
              v18 = j;
            this->m_IndexRemapTable.m_Memory.m_pMemory[v21] = v18;
          }
          else
          {
            v15 = j;
            v17 = this;
          }
          m_vtxList = v17->m_vtxList;
          v22 += 9;
          v1 = this;
          j = v15 + 1;
        }
        while ( v15 + 1 < m_vtxList->m_Size );
        v9 = v21 + 1;
      }
      m_vtxList = v1->m_vtxList;
      v8 = m_vtxList->m_Size;
      ++ia;
      v21 = v9;
    }
    while ( v9 < v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E6B0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(
        OptimizedModel::COptimizeSubDBuilder *this)
{
  int v2; // edi
  OptimizedModel::Orientation *m_pMemory; // ebx
  bool v4; // zf
  OptimizedModel::SubD_Face_t *v5; // edx
  OptimizedModel::HalfEdge *halfEdges; // eax
  int v7; // edi
  OptimizedModel::HalfEdge *v8; // [esp-8h] [ebp-30h]
  int m_numPatches; // [esp-4h] [ebp-2Ch]
  CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > orientationArray; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v11; // [esp+20h] [ebp-8h]
  OptimizedModel::HalfEdge *pEdges; // [esp+24h] [ebp-4h]

  v2 = 0;
  m_numPatches = this->m_numPatches;
  memset(&orientationArray, 0, sizeof(orientationArray));
  CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int>>::InsertMultipleBefore(
    this: &orientationArray,
    elem: 0,
    num: m_numPatches);
  m_pMemory = orientationArray.m_Memory.m_pMemory;
  if ( this->m_numPatches > 0 )
  {
    v11 = 0;
    do
    {
      v4 = (*(_BYTE *)&m_pMemory[v2] & 4) == 0;
      v5 = this->m_faceList->m_Memory.m_pMemory;
      halfEdges = v5[v11 / 0x12C].halfEdges;
      pEdges = halfEdges;
      if ( v4 )
      {
        v8 = &v5[v11 / 0x12C].halfEdges[1];
        m_pMemory[v2] = (OptimizedModel::Orientation)(*(_BYTE *)&m_pMemory[v2] & 0xFA | 4);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: v8, dir: false);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: pEdges + 3, dir: true);
        halfEdges = pEdges;
      }
      if ( (*(_BYTE *)&m_pMemory[v2] & 8) == 0 )
      {
        m_pMemory[v2] = (OptimizedModel::Orientation)(*(_BYTE *)&m_pMemory[v2] & 0xF5 | 8);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: halfEdges, dir: false);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: pEdges + 2, dir: true);
      }
      v11 += 300;
      ++v2;
    }
    while ( v2 < this->m_numPatches );
  }
  v7 = 0;
  if ( this->m_numPatches > 0 )
  {
    v11 = 0;
    do
    {
      OptimizedModel::COptimizeSubDBuilder::RotateFace(
        this,
        pPatch: &this->m_faceList->m_Memory.m_pMemory[v11 / 0x12C],
        nTimesToRotate: nTimesToRotate[2 * ((*(_BYTE *)&m_pMemory[v7] & 2) != 0) + (*(_BYTE *)&m_pMemory[v7] & 1)]);
      v11 += 300;
      ++v7;
    }
    while ( v7 < this->m_numPatches );
  }
  if ( orientationArray.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041E7E0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ProcessPatches(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ProcessPatches(
        OptimizedModel::COptimizeSubDBuilder *this,
        bool bIsTagged,
        bool bMendVertices)
{
  int v3; // edi
  _WORD *v5; // eax
  int v6; // esi
  int j; // ecx
  int v8; // edi
  _DWORD *v9; // edx
  OptimizedModel::SubD_Face_t *v10; // esi
  OptimizedModel::SubD_Face_t *v11; // edi
  int m; // esi
  int n; // esi
  int m_Size; // esi
  int v15; // edi
  OptimizedModel::SubD_Face_t *m_pMemory; // ecx
  int v17; // eax
  int v18; // eax
  OptimizedModel::SubD_Face_t *v19; // edi
  int v20; // eax
  int ii; // edx
  OptimizedModel::SubD_Face_t *v22; // esi
  OptimizedModel::SubD_Face_t *v23; // edi
  OptimizedModel::SubD_Face_t *v24; // eax
  int v25; // edx
  OptimizedModel::SubD_Face_t *v26; // edi
  OptimizedModel::SubD_Face_t *v27; // esi
  bool v28; // zf
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > regFaceList; // [esp+Ch] [ebp-34h] BYREF
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > extraFaceList; // [esp+20h] [ebp-20h] BYREF
  OptimizedModel::SubD_Face_t *pPatch; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  int k; // [esp+3Ch] [ebp-4h]
  int bIsTaggeda; // [esp+48h] [ebp+8h]
  int bIsTaggedb; // [esp+48h] [ebp+8h]
  int bIsTaggedc; // [esp+48h] [ebp+8h]
  int bIsTaggedd; // [esp+48h] [ebp+8h]

  v3 = 0;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    pPatch = nullptr;
    do
    {
      v5 = (unsigned __int16 *)((char *)&pPatch->patchID + (unsigned int)this->m_faceList->m_Memory.m_pMemory);
      k = 0;
      v6 = 0;
      for ( j = 77; j < 81; ++j )
      {
        *v5 = i;
        if ( !bIsTagged )
        {
          v5[j - 4] = 0;
          v5[j] = 0;
          v5[j + 4] = 0;
        }
        v8 = k;
        v5[j + 8] = 0;
        v5[j - 12] = 0;
        v5[j - 8] = 0;
        v5[j + 12] = -1;
        v5[2 * v8 + 93] = 0x4000;
        v5[2 * v8 + 94] = 0x4000;
        v9 = &v5[v6 + 118];
        *(_DWORD *)&v5[v6 + 120] = v9;
        *v9 = 0;
        LOBYTE(v5[v6 + 122]) = v8;
        *(_DWORD *)&v5[v6 + 124] = v5;
        v6 += 8;
        k = v8 + 1;
      }
      ++pPatch;
      v3 = 0;
      ++i;
    }
    while ( i < this->m_numPatches );
  }
  OptimizedModel::COptimizeSubDBuilder::RemapIndices(this);
  OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(this);
  OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(this);
  OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(this);
  if ( !bIsTagged )
    OptimizedModel::COptimizeSubDBuilder::TagCreases(this);
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    pPatch = nullptr;
    do
    {
      v10 = (OptimizedModel::SubD_Face_t *)((char *)pPatch + (unsigned int)this->m_faceList->m_Memory.m_pMemory);
      for ( bIsTaggeda = 0; bIsTaggeda < 4; ++bIsTaggeda )
      {
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(this, pPatch: v10, k: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(this, baseQuad: v10, baseLocalID: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(this, baseQuad: v10, baseLocalID: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(
          this,
          a2: (int)this,
          baseQuad: v10,
          baseLocalID: bIsTaggeda);
      }
      ++pPatch;
      v3 = 0;
      ++i;
    }
    while ( i < this->m_numPatches );
  }
  pPatch = nullptr;
  if ( this->m_numPatches > 0 )
  {
    bIsTaggedb = 0;
    do
    {
      v11 = &this->m_faceList->m_Memory.m_pMemory[bIsTaggedb];
      for ( m = 0; m < 4; ++m )
        OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(this, baseQuad: v11, baseLocalID: m);
      ++bIsTaggedb;
      pPatch = (OptimizedModel::SubD_Face_t *)((char *)pPatch + 1);
    }
    while ( (int)pPatch < this->m_numPatches );
    v3 = 0;
  }
  for ( n = 0; n < this->m_numPatches; ++v3 )
  {
    OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(
      this,
      baseQuad: &this->m_faceList->m_Memory.m_pMemory[v3]);
    ++n;
  }
  OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(this);
  m_Size = 0;
  memset(&regFaceList, 0, sizeof(regFaceList));
  memset(&extraFaceList, 0, sizeof(extraFaceList));
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    bIsTaggedc = 0;
    do
    {
      pPatch = &this->m_faceList->m_Memory.m_pMemory[bIsTaggedc];
      if ( OptimizedModel::FaceIsRegular(patch: pPatch) )
      {
        v15 = m_Size;
        if ( m_Size + 1 > regFaceList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
            this: &regFaceList.m_Memory,
            num: m_Size - regFaceList.m_Memory.m_nAllocationCount + 1);
          m_Size = regFaceList.m_Size;
        }
        m_pMemory = regFaceList.m_Memory.m_pMemory;
        regFaceList.m_Size = ++m_Size;
        regFaceList.m_pElements = regFaceList.m_Memory.m_pMemory;
        if ( m_Size - v15 - 1 > 0 )
        {
          _V_memmove(
            dest: &regFaceList.m_Memory.m_pMemory[v15 + 1],
            src: &regFaceList.m_Memory.m_pMemory[v15],
            count: 300 * (m_Size - v15 - 1));
          m_pMemory = regFaceList.m_Memory.m_pMemory;
        }
      }
      else
      {
        v15 = extraFaceList.m_Size;
        v17 = extraFaceList.m_Size;
        if ( extraFaceList.m_Size + 1 > extraFaceList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
            this: &extraFaceList.m_Memory,
            num: extraFaceList.m_Size - extraFaceList.m_Memory.m_nAllocationCount + 1);
          v17 = extraFaceList.m_Size;
        }
        m_pMemory = extraFaceList.m_Memory.m_pMemory;
        extraFaceList.m_Size = v17 + 1;
        v18 = v17 - v15;
        extraFaceList.m_pElements = extraFaceList.m_Memory.m_pMemory;
        if ( v18 > 0 )
        {
          _V_memmove(
            dest: &extraFaceList.m_Memory.m_pMemory[v15 + 1],
            src: &extraFaceList.m_Memory.m_pMemory[v15],
            count: 300 * v18);
          m_pMemory = extraFaceList.m_Memory.m_pMemory;
        }
      }
      v19 = &m_pMemory[v15];
      if ( v19 != nullptr )
      {
        qmemcpy(v19, pPatch, sizeof(OptimizedModel::SubD_Face_t));
        m_Size = regFaceList.m_Size;
      }
      ++bIsTaggedc;
      ++i;
    }
    while ( i < this->m_numPatches );
  }
  if ( m_Size > 0 )
  {
    v20 = 0;
    for ( ii = m_Size; ii != 0; --ii )
    {
      v22 = &regFaceList.m_Memory.m_pMemory[v20];
      v23 = &this->m_faceList->m_Memory.m_pMemory[v20++];
      qmemcpy(v23, v22, sizeof(OptimizedModel::SubD_Face_t));
    }
    m_Size = regFaceList.m_Size;
  }
  if ( extraFaceList.m_Size > 0 )
  {
    v24 = extraFaceList.m_Memory.m_pMemory;
    v25 = m_Size;
    bIsTaggedd = extraFaceList.m_Size;
    do
    {
      v26 = &this->m_faceList->m_Memory.m_pMemory[v25];
      v27 = v24++;
      ++v25;
      v28 = bIsTaggedd-- == 1;
      qmemcpy(v26, v27, sizeof(OptimizedModel::SubD_Face_t));
    }
    while ( !v28 );
  }
  if ( extraFaceList.m_Memory.m_nGrowSize >= 0 && extraFaceList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: extraFaceList.m_Memory.m_pMemory);
  if ( regFaceList.m_Memory.m_nGrowSize >= 0 && regFaceList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: regFaceList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041EB70
// Name: public: OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(class CUtlVector<struct OptimizedModel::SubD_Face_t,class CUtlMemory<struct OptimizedModel::SubD_Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> const __near &,struct mstudio_meshvertexdata_t const __near * const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::COptimizeSubDBuilder *__thiscall OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(
        OptimizedModel::COptimizeSubDBuilder *this,
        CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *subDFaceList,
        const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vertexList,
        const mstudio_meshvertexdata_t *const *vertexData,
        bool bIsTagged,
        bool bMendVertices)
{
  this->m_vtxList = vertexList;
  this->m_faceList = subDFaceList;
  this->m_vtxData = vertexData;
  this->m_IndexRemapTable.m_Memory.m_pMemory = nullptr;
  this->m_IndexRemapTable.m_Memory.m_nAllocationCount = 0;
  this->m_IndexRemapTable.m_Memory.m_nGrowSize = 0;
  this->m_IndexRemapTable.m_Size = 0;
  this->m_IndexRemapTable.m_pElements = nullptr;
  this->m_numPatches = subDFaceList->m_Size;
  OptimizedModel::COptimizeSubDBuilder::ProcessPatches(this, bIsTagged, bMendVertices);
  return this;
}

} // namespace studiomdl

// ============================================================
// Overlay from subdbaker (Missing functions)
// ============================================================
namespace subdbaker {

//------------------------------------------------------------------------------
// Address: 0x00401030
// Name: bool OptimizedModel::FaceIsRegular(struct OptimizedModel::SubD_Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl OptimizedModel::FaceIsRegular(OptimizedModel::SubD_Face_t *patch)
{
  return patch->valences[0] == 4
      && patch->valences[1] == 4
      && patch->valences[2] == 4
      && patch->valences[3] == 4
      && patch->bndVtx[0] == 0
      && patch->bndVtx[1] == 0
      && patch->bndVtx[2] == 0
      && patch->bndVtx[3] == 0
      && patch->bndEdge[0] == 0
      && patch->bndEdge[1] == 0
      && patch->bndEdge[2] == 0
      && patch->bndEdge[3] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *pPatch,
        unsigned __int16 k)
{
  OptimizedModel::HalfEdge *v3; // eax
  OptimizedModel::HalfEdge *v4; // ecx
  OptimizedModel::HalfEdge *twin; // eax

  v3 = &pPatch->halfEdges[k];
  while ( 1 )
  {
    v4 = v3;
    if ( v3->patch->bndEdge[v3->localID] != 0 )
      break;
    twin = v3->twin;
    if ( twin == nullptr )
      break;
    v3 = &twin->patch->halfEdges[dword_52003C[twin->localID]];
    if ( v3 == nullptr )
      break;
    if ( v3 == &pPatch->halfEdges[k] )
      return;
  }
  pPatch->halfEdges[k].sectorStart = v4;
}

//------------------------------------------------------------------------------
// Address: 0x00401140
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  OptimizedModel::HalfEdge *sectorStart; // edx
  __int16 v4; // di
  OptimizedModel::HalfEdge *v5; // ecx
  OptimizedModel::HalfEdge *v6; // eax
  OptimizedModel::HalfEdge *twin; // eax
  int localID; // eax
  OptimizedModel::SubD_Face_t *patch; // edx
  OptimizedModel::HalfEdge *v10; // ecx
  int v11; // eax
  int v12; // eax

  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  v4 = 0;
  v5 = sectorStart;
  if ( sectorStart->twin != nullptr )
  {
    v6 = &sectorStart->twin->patch->halfEdges[dword_52003C[sectorStart->twin->localID]];
    if ( (OptimizedModel::SubD_Face_t *)((char *)sectorStart->twin->patch + 16
                                                                          * dword_52003C[sectorStart->twin->localID]) != (OptimizedModel::SubD_Face_t *)-236 )
    {
      while ( v6 != sectorStart )
      {
        v5 = v6;
        twin = v6->twin;
        if ( twin != nullptr )
        {
          v6 = &twin->patch->halfEdges[dword_52003C[twin->localID]];
          if ( v6 != nullptr )
            continue;
        }
        goto LABEL_8;
      }
      v5 = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
    }
  }
LABEL_8:
  localID = v5->localID;
  patch = v5->patch;
  if ( patch->bndEdge[localID] != 0 )
    v4 = 1;
  v10 = v5->twin;
  v11 = (int)&patch->halfEdges[dword_520064[localID]];
  do
  {
    if ( *(_WORD *)(*(_DWORD *)(v11 + 12) + 2 * *(unsigned __int8 *)(v11 + 8) + 154) != 0 )
      ++v4;
    v12 = *(_DWORD *)v11;
    if ( v12 == 0 )
      break;
    v11 = *(_DWORD *)(v12 + 12) + 16 * dword_520064[*(unsigned __int8 *)(v12 + 8)] + 236;
    if ( v11 == 0 )
      break;
  }
  while ( (OptimizedModel::HalfEdge *)v11 != v10 );
  if ( v4 == 1 )
  {
    baseQuad->halfEdges[baseLocalID].sectorStart = &baseQuad->halfEdges[baseLocalID];
    baseQuad->bndVtx[baseLocalID] = 0;
  }
  else if ( (unsigned __int16)v4 >= 2u )
  {
    baseQuad->bndVtx[baseLocalID] = 1;
    if ( (unsigned __int16)v4 > 2u )
      baseQuad->cornerVtx[baseLocalID] = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401270
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  unsigned __int16 *v5; // edx
  unsigned __int16 *vtx1RingSize; // eax
  int i; // esi
  int v8; // ebx
  int v9; // eax
  OptimizedModel::HalfEdge *sectorStart; // edx
  int v11; // edx
  int v12; // edx
  OptimizedModel::HalfEdge *heEnd; // [esp+Ch] [ebp-4h]
  unsigned __int16 *oneRing; // [esp+18h] [ebp+8h]
  OptimizedModel::HalfEdge *heBase; // [esp+1Ch] [ebp+Ch]

  v5 = baseQuad->oneRing;
  oneRing = baseQuad->oneRing;
  if ( baseLocalID != 0 )
  {
    vtx1RingSize = baseQuad->vtx1RingSize;
    for ( i = baseLocalID; i != 0; --i )
    {
      v8 = *vtx1RingSize++;
      v5 += v8;
    }
    oneRing = v5;
  }
  v9 = baseLocalID;
  baseQuad->vtx1RingCenterQuadOffset[baseLocalID] = 1;
  baseQuad->valences[baseLocalID] = 0;
  baseQuad->vtx1RingSize[baseLocalID] = 0;
  heBase = &baseQuad->halfEdges[MOD4[baseLocalID]];
  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  oneRing[baseQuad->vtx1RingSize[baseLocalID]++] = sectorStart->patch->vtxIDs[MOD4[sectorStart->localID]];
  ++baseQuad->valences[baseLocalID];
  oneRing[baseQuad->vtx1RingSize[baseLocalID]] = sectorStart->patch->vtxIDs[MOD4[sectorStart->localID + 1]];
  ++baseQuad->vtx1RingSize[v9];
  heEnd = sectorStart->twin;
  v11 = (int)&sectorStart->patch->halfEdges[dword_520064[sectorStart->localID]];
  while ( 1 )
  {
    oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                     + 2 * MOD4[*(unsigned __int8 *)(v11 + 8) + 3]
                                                     + 2);
    ++baseQuad->valences[v9];
    oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                     + 2 * MOD4[*(unsigned __int8 *)(v11 + 8)]
                                                     + 2);
    if ( *(OptimizedModel::HalfEdge **)v11 == heBase )
      baseQuad->vtx1RingCenterQuadOffset[v9] = baseQuad->vtx1RingSize[v9] - 1;
    if ( *(_WORD *)(*(_DWORD *)(v11 + 12) + 2 * *(unsigned __int8 *)(v11 + 8) + 154) != 0 && baseQuad->bndVtx[v9] != 0 )
      break;
    v12 = *(_DWORD *)v11;
    if ( v12 == 0 )
      break;
    v11 = *(_DWORD *)(v12 + 12) + 16 * dword_520064[*(unsigned __int8 *)(v12 + 8)] + 236;
    if ( v11 == 0 )
      break;
    if ( (OptimizedModel::HalfEdge *)v11 == heEnd )
    {
      oneRing[baseQuad->vtx1RingSize[v9]++] = *(_WORD *)(*(_DWORD *)(v11 + 12)
                                                       + 2 * MOD4[*(unsigned __int8 *)(v11 + 8) + 3]
                                                       + 2);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401430
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  int v3; // edx
  OptimizedModel::HalfEdge *sectorStart; // eax
  int v5; // eax
  char v6; // cl
  int v7; // eax
  __int16 nbCorners_4; // [esp+Ch] [ebp-4h]
  OptimizedModel::HalfEdge *heEnd; // [esp+1Ch] [ebp+Ch]

  v3 = baseLocalID;
  baseQuad->nbCornerVtx[baseLocalID] = 0;
  sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
  baseQuad->nbCornerVtx[baseLocalID] |= sectorStart->patch->cornerVtx[MOD4[sectorStart->localID + 1]] == 2;
  nbCorners_4 = 1;
  heEnd = sectorStart->twin;
  v5 = (int)&sectorStart->patch->halfEdges[dword_520064[sectorStart->localID]];
  do
  {
    v6 = nbCorners_4++;
    baseQuad->nbCornerVtx[v3] |= (*(_WORD *)(*(_DWORD *)(v5 + 12) + 2 * *(unsigned __int8 *)(v5 + 8) + 162) == 2) << v6;
    if ( *(_WORD *)(*(_DWORD *)(v5 + 12) + 2 * *(unsigned __int8 *)(v5 + 8) + 154) != 0 && baseQuad->bndVtx[v3] != 0 )
      break;
    v7 = *(_DWORD *)v5;
    if ( v7 == 0 )
      break;
    v5 = *(_DWORD *)(v7 + 12) + 16 * dword_520064[*(unsigned __int8 *)(v7 + 8)] + 236;
    if ( v5 == 0 )
      break;
  }
  while ( (OptimizedModel::HalfEdge *)v5 != heEnd );
}

//------------------------------------------------------------------------------
// Address: 0x00401530
// Name: private: void OptimizedModel::COptimizeSubDBuilder::RotateFace(struct OptimizedModel::SubD_Face_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::RotateFace(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *pPatch,
        int nTimesToRotate)
{
  OptimizedModel::HalfEdge *v3; // edx
  OptimizedModel::HalfEdge *v4; // esi
  OptimizedModel::HalfEdge *halfEdges; // ecx
  int v6; // ebx
  unsigned __int16 *bndEdge; // edx
  __int64 v8; // xmm0_8
  unsigned __int8 v9; // al
  OptimizedModel::SubD_Face_t v10; // [esp+0h] [ebp-13Ch] BYREF
  OptimizedModel::HalfEdge *twin; // [esp+130h] [ebp-Ch]
  OptimizedModel::HalfEdge *v12; // [esp+134h] [ebp-8h]
  OptimizedModel::HalfEdge *v13; // [esp+138h] [ebp-4h]

  if ( nTimesToRotate > 0 )
  {
    do
    {
      twin = pPatch->halfEdges[1].twin;
      v12 = pPatch->halfEdges[2].twin;
      v3 = pPatch->halfEdges[3].twin;
      v10 = *pPatch;
      v4 = pPatch->halfEdges[0].twin;
      halfEdges = pPatch->halfEdges;
      v13 = v3;
      v6 = 3;
      bndEdge = pPatch->bndEdge;
      do
      {
        *(bndEdge - 76) = v10.vtxIDs[v6 % 4];
        *bndEdge = v10.bndEdge[v6 % 4];
        v8 = *(_QWORD *)&v10.halfEdges[v6 % 4].twin;
        *(bndEdge - 4) = v10.bndVtx[v6 % 4];
        *(_QWORD *)&halfEdges->twin = v8;
        v9 = v6 - 3;
        *(_QWORD *)&halfEdges->localID = *(_QWORD *)&v10.halfEdges[v6 % 4].localID;
        ++v6;
        halfEdges->localID = v9;
        halfEdges->sectorStart = halfEdges;
        ++bndEdge;
        ++halfEdges;
      }
      while ( v6 - 3 < 4 );
      if ( v4 != nullptr )
        v4->twin = &pPatch->halfEdges[1];
      if ( twin != nullptr )
        twin->twin = &pPatch->halfEdges[2];
      if ( v12 != nullptr )
        v12->twin = &pPatch->halfEdges[3];
      if ( v13 != nullptr )
        v13->twin = pPatch->halfEdges;
      --nTimesToRotate;
    }
    while ( nTimesToRotate != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401650
// Name: public: void CUtlMemory<struct OptimizedModel::SubD_Face_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
        CUtlMemory<OptimizedModel::SubD_Face_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  OptimizedModel::SubD_Face_t *m_pMemory; // edx
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
    v7 = 300 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::SubD_Face_t *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v7);
    else
      this->m_pMemory = (OptimizedModel::SubD_Face_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004016F0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::SubD_Face_t *v1; // edi
  int v2; // eax
  unsigned __int16 *minOneRingIndex; // esi
  int *m_pMemory; // ecx
  int v5; // ebx
  unsigned __int16 *v6; // esi
  unsigned __int16 v7; // di
  int v8; // edx
  bool v9; // zf
  OptimizedModel::SubD_Face_t *pPatch; // [esp+0h] [ebp-24h]
  int *v11; // [esp+4h] [ebp-20h]
  int i; // [esp+8h] [ebp-1Ch]
  int v13; // [esp+Ch] [ebp-18h]
  unsigned __int16 *v14; // [esp+10h] [ebp-14h]
  unsigned __int16 nMinNeighborOffset; // [esp+14h] [ebp-10h]
  int nMinNeighborIdx; // [esp+18h] [ebp-Ch]
  OptimizedModel::COptimizeSubDBuilder *v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]

  v17 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v18 = 0;
    while ( 1 )
    {
      v1 = &this->m_faceList->m_Memory.m_pMemory[v18];
      v2 = 0;
      minOneRingIndex = v1->minOneRingIndex;
      pPatch = v1;
      v14 = v1->minOneRingIndex;
      v13 = 4;
      while ( 1 )
      {
        m_pMemory = this->m_IndexRemapTable.m_Memory.m_pMemory;
        nMinNeighborIdx = m_pMemory[v1->oneRing[v2]];
        v5 = *(minOneRingIndex - 12) + v2 - 1;
        v11 = m_pMemory;
        nMinNeighborOffset = 0;
        if ( v2 <= v5 )
        {
          v6 = &v1->oneRing[v2];
          v7 = 0;
          v8 = v5 - v2 + 1;
          while ( 1 )
          {
            if ( m_pMemory[*v6] < nMinNeighborIdx )
            {
              nMinNeighborIdx = m_pMemory[*v6];
              nMinNeighborOffset = v7;
            }
            ++v6;
            ++v7;
            if ( --v8 == 0 )
              break;
            m_pMemory = v11;
          }
          v1 = pPatch;
          minOneRingIndex = v14;
        }
        *minOneRingIndex++ = nMinNeighborOffset;
        v9 = v13-- == 1;
        v2 = v5 + 1;
        v14 = minOneRingIndex;
        if ( v9 )
          break;
        this = v17;
      }
      ++v18;
      if ( ++i >= v17->m_numPatches )
        break;
      this = v17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004017C0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // edx
  OptimizedModel::SubD_Face_t *v2; // eax
  unsigned __int16 *bndEdge; // ecx
  OptimizedModel::SubD_Face_t **p_patch; // eax
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // ecx
  const mstudio_meshvertexdata_t *v6; // edi
  int origMeshVertID; // esi
  int v8; // ebx
  _QWORD *pVertexData; // eax
  unsigned int v10; // esi
  __int64 v11; // xmm0_8
  unsigned int v12; // esi
  int v13; // eax
  float *v14; // ecx
  unsigned int v15; // esi
  bool v16; // zf
  int v17; // ecx
  int v18; // eax
  float *v19; // ecx
  unsigned int v20; // esi
  int v21; // ecx
  OptimizedModel::HalfEdge *v22; // eax
  __int64 v23; // [esp+0h] [ebp-48h]
  float v24; // [esp+8h] [ebp-40h]
  float v25; // [esp+14h] [ebp-34h]
  OptimizedModel::SubD_Face_t *pPatch; // [esp+18h] [ebp-30h]
  int m_numPatches; // [esp+1Ch] [ebp-2Ch]
  int i; // [esp+20h] [ebp-28h]
  int v29; // [esp+24h] [ebp-24h]
  OptimizedModel::Vertex_t *m_pMemory; // [esp+28h] [ebp-20h]
  int v31; // [esp+2Ch] [ebp-1Ch]
  int *v32; // [esp+30h] [ebp-18h]
  unsigned __int16 *v33; // [esp+34h] [ebp-14h]
  unsigned __int16 j; // [esp+3Ch] [ebp-Ch]
  OptimizedModel::SubD_Face_t *v36; // [esp+40h] [ebp-8h]
  OptimizedModel::SubD_Face_t **v37; // [esp+44h] [ebp-4h]

  v1 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v31 = 0;
    do
    {
      v2 = &v1->m_faceList->m_Memory.m_pMemory[v31];
      v32 = &MOD4[1];
      bndEdge = v2->bndEdge;
      pPatch = v2;
      p_patch = &v2->halfEdges[0].patch;
      v33 = bndEdge;
      v37 = p_patch;
      do
      {
        if ( *(p_patch - 3) == nullptr )
        {
          m_vtxList = v1->m_vtxList;
          v6 = *v1->m_vtxData;
          origMeshVertID = m_vtxList->m_Memory.m_pMemory[(*p_patch)->vtxIDs[MOD4[*((unsigned __int8 *)p_patch - 4)]]].origMeshVertID;
          v8 = *((unsigned __int8 *)p_patch - 4);
          pVertexData = v6->modelvertexdata->pVertexData;
          v10 = (unsigned int)v6[-1].modelvertexdata
              + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
              + origMeshVertID;
          v29 = 0;
          v11 = pVertexData[6 * v10 + 2];
          v25 = *(float *)&pVertexData[6 * v10 + 3];
          v12 = (unsigned int)v6[-1].modelvertexdata
              + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
              + m_vtxList->m_Memory.m_pMemory[(*v37)->vtxIDs[MOD4[v8 + 1]]].origMeshVertID;
          v24 = *(float *)&pVertexData[6 * v12 + 3];
          v23 = pVertexData[6 * v12 + 2];
          m_numPatches = this->m_numPatches;
          if ( m_numPatches > 0 )
          {
            m_pMemory = m_vtxList->m_Memory.m_pMemory;
            v36 = this->m_faceList->m_Memory.m_pMemory;
            while ( 2 )
            {
              for ( j = 0; j < 4u; ++j )
              {
                v13 = v36->vtxIDs[MOD4[j]];
                v14 = (float *)v6->modelvertexdata->pVertexData;
                v15 = (unsigned int)v6[-1].modelvertexdata
                    + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
                    + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v13 + v13);
                v16 = *(float *)&v23 == v14[12 * v15 + 4];
                v17 = (int)&v14[12 * v15 + 4];
                if ( v16 && *((float *)&v23 + 1) == *(float *)(v17 + 4) && v24 == *(float *)(v17 + 8) )
                {
                  v18 = v36->vtxIDs[MOD4[j + 1]];
                  v19 = (float *)v6->modelvertexdata->pVertexData;
                  v20 = (unsigned int)v6[-1].modelvertexdata
                      + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30
                      + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v18 + v18);
                  v16 = *(float *)&v11 == v19[12 * v20 + 4];
                  v21 = (int)&v19[12 * v20 + 4];
                  if ( v16 && *((float *)&v11 + 1) == *(float *)(v21 + 4) && v25 == *(float *)(v21 + 8) )
                  {
                    v22 = &v36->halfEdges[j];
                    goto LABEL_17;
                  }
                }
              }
              ++v36;
              if ( ++v29 < m_numPatches )
                continue;
              break;
            }
          }
          v22 = nullptr;
LABEL_17:
          *(v37 - 3) = (OptimizedModel::SubD_Face_t *)v22;
          if ( v22 != nullptr )
          {
            v22->twin = (OptimizedModel::HalfEdge *)(v37 - 3);
          }
          else
          {
            *v33 = 1;
            pPatch->bndVtx[*(v32 - 1)] = 1;
            pPatch->bndVtx[*v32] = 1;
          }
          v1 = this;
          p_patch = v37;
        }
        ++v33;
        p_patch += 4;
        v37 = p_patch;
        ++v32;
      }
      while ( (int)v32 < (int)&MOD4[5] );
      ++v31;
      ++i;
    }
    while ( i < v1->m_numPatches );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A70
// Name: public: void OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // ebx
  OptimizedModel::SubD_Face_t *v2; // esi
  int *v3; // edi
  OptimizedModel::HalfEdge *halfEdges; // eax
  const mstudio_meshvertexdata_t *v5; // ecx
  _QWORD *pVertexData; // eax
  __int64 v7; // xmm0_8
  unsigned int v8; // ebx
  __int64 v9; // xmm0_8
  unsigned int v10; // ecx
  bool v11; // zf
  __int64 vC; // [esp+24h] [ebp-40h]
  float vC_8; // [esp+2Ch] [ebp-38h]
  float vB_8; // [esp+38h] [ebp-2Ch]
  __int64 vA; // [esp+3Ch] [ebp-28h]
  float vA_8; // [esp+44h] [ebp-20h]
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // [esp+4Ch] [ebp-18h]
  int i; // [esp+50h] [ebp-14h]
  int v19; // [esp+54h] [ebp-10h]
  OptimizedModel::HalfEdge *v20; // [esp+58h] [ebp-Ch]
  int v22; // [esp+60h] [ebp-4h]

  v1 = this;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    v22 = 0;
    do
    {
      v2 = &v1->m_faceList->m_Memory.m_pMemory[v22];
      v3 = MOD4;
      halfEdges = v2->halfEdges;
      v20 = v2->halfEdges;
      v19 = 4;
      do
      {
        if ( halfEdges->twin != nullptr && halfEdges->twin->twin != halfEdges )
        {
          _Msg(a1: "Topology error at vertices %d, %d, %d\n", v2->vtxIDs[v3[3]], v2->vtxIDs[*v3], v2->vtxIDs[v3[1]]);
          v5 = *v1->m_vtxData;
          pVertexData = v5->modelvertexdata->pVertexData;
          v7 = pVertexData[6
                         * (int)((int)v5[-1].modelvertexdata
                               + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
                               + v1->m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[3]]].origMeshVertID)
                         + 2];
          m_vtxList = this->m_vtxList;
          vA_8 = *(float *)&pVertexData[6
                                      * (int)((int)v5[-1].modelvertexdata
                                            + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
                                            + v1->m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[3]]].origMeshVertID)
                                      + 3];
          v8 = (unsigned int)v5[-1].modelvertexdata
             + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
             + m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[*v3]].origMeshVertID;
          vA = v7;
          v9 = pVertexData[6 * v8 + 2];
          vB_8 = *(float *)&pVertexData[6 * v8 + 3];
          v10 = 6
              * ((int)v5[-1].modelvertexdata
               + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30
               + m_vtxList->m_Memory.m_pMemory[v2->vtxIDs[v3[1]]].origMeshVertID);
          vC = pVertexData[v10 + 2];
          vC_8 = *(float *)&pVertexData[v10 + 3];
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&vA, *((float *)&vA + 1), vA_8);
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&v9, *((float *)&v9 + 1), vB_8);
          _Msg(a1: "spaceLocator -p %.4f %.4f %.4f;\n", *(float *)&vC, *((float *)&vC + 1), vC_8);
          v1 = this;
          halfEdges = v20;
        }
        ++halfEdges;
        ++v3;
        v11 = v19-- == 1;
        v20 = halfEdges;
      }
      while ( !v11 );
      ++v22;
      ++i;
    }
    while ( i < v1->m_numPatches );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401CA0
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(struct OptimizedModel::SubD_Face_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(
        OptimizedModel::COptimizeSubDBuilder *this@<ecx>,
        int a2@<ebx>,
        OptimizedModel::SubD_Face_t *baseQuad,
        unsigned __int16 baseLocalID)
{
  const mstudio_meshvertexdata_t *v5; // ebx
  OptimizedModel::HalfEdge *sectorStart; // esi
  const mstudio_modelvertexdata_t *modelvertexdata; // edx
  int origMeshVertID; // ecx
  _QWORD *pVertexData; // eax
  unsigned int v10; // edx
  __int64 v11; // xmm0_8
  float v12; // ecx
  OptimizedModel::Vertex_t *m_pMemory; // eax
  const mstudio_modelvertexdata_t *v14; // edx
  int v15; // ecx
  unsigned int v16; // ecx
  Vector *v17; // eax
  const mstudio_meshvertexdata_t *v18; // ebx
  int v19; // ecx
  float *v20; // eax
  int v21; // esi
  const mstudio_meshvertexdata_t *v22; // ebx
  int v23; // ecx
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  int v27; // esi
  int v28; // eax
  int v29; // edx
  float v30; // xmm0_4
  long double v31; // [esp-4h] [ebp-50h]
  Vector vec; // [esp+8h] [ebp-44h] BYREF
  Vector center_pos; // [esp+14h] [ebp-38h]
  Vector eVec1; // [esp+20h] [ebp-2Ch] BYREF
  Vector eVec2; // [esp+2Ch] [ebp-20h] BYREF
  Vector center_nor; // [esp+38h] [ebp-14h] BYREF
  const mstudio_modelvertexdata_t *v37; // [esp+44h] [ebp-8h]
  int v38; // [esp+48h] [ebp-4h]

  if ( baseQuad->bndVtx[baseLocalID] != 0 )
  {
    LODWORD(v31) = a2;
    if ( baseQuad->cornerVtx[baseLocalID] != 0 )
    {
      v5 = *this->m_vtxData;
      sectorStart = baseQuad->halfEdges[MOD4[baseLocalID]].sectorStart;
      modelvertexdata = v5->modelvertexdata;
      origMeshVertID = this->m_vtxList->m_Memory.m_pMemory[sectorStart->patch->vtxIDs[sectorStart->localID]].origMeshVertID;
      v38 = 9 * sectorStart->patch->vtxIDs[sectorStart->localID];
      pVertexData = v5->modelvertexdata->pVertexData;
      v10 = 6 * ((int)v5[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30 + origMeshVertID);
      v11 = pVertexData[v10 + 2];
      v12 = *(float *)&pVertexData[v10 + 3];
      m_pMemory = this->m_vtxList->m_Memory.m_pMemory;
      v14 = v5->modelvertexdata;
      center_pos.z = v12;
      v15 = m_pMemory[v38 / 9u].origMeshVertID;
      v37 = v14;
      v16 = (unsigned int)v5[-1].modelvertexdata + (unsigned int)v14[-3].pVertexData / 0x30 + v15;
      *(_QWORD *)&center_pos.x = v11;
      v17 = (Vector *)((char *)v14->pVertexData + 48 * v16 + 28);
      center_nor = *v17;
      VectorNormalize(vec: &center_nor);
      v18 = *this->m_vtxData;
      v19 = this->m_vtxList->m_Memory.m_pMemory[sectorStart->patch->vtxIDs[MOD4[sectorStart->localID + 1]]].origMeshVertID;
      v37 = v18->modelvertexdata;
      v20 = (float *)((char *)v37->pVertexData
                    + 48 * ((int)v18[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v19)
                    + 16);
      eVec1.x = *v20 - *(float *)&v11;
      eVec1.y = v20[1] - *((float *)&v11 + 1);
      eVec1.z = v20[2] - center_pos.z;
      *(float *)&v11 = (float)((float)(center_nor.y * eVec1.y) + (float)(center_nor.x * eVec1.x))
                     + (float)(center_nor.z * eVec1.z);
      vec.x = eVec1.x - (float)(center_nor.x * *(float *)&v11);
      vec.y = eVec1.y - (float)(center_nor.y * *(float *)&v11);
      vec.z = eVec1.z - (float)(center_nor.z * *(float *)&v11);
      VectorNormalize(&vec);
      v21 = (int)&sectorStart->patch->halfEdges[dword_520064[sectorStart->localID]];
      do
      {
        v22 = *this->m_vtxData;
        v23 = this->m_vtxList->m_Memory.m_pMemory[*(unsigned __int16 *)(*(_DWORD *)(v21 + 12)
                                                                      + 2 * MOD4[*(unsigned __int8 *)(v21 + 8)]
                                                                      + 2)].origMeshVertID;
        v37 = v22->modelvertexdata;
        v24 = *((float *)v37->pVertexData
              + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
              + 5);
        v25 = *((float *)v37->pVertexData
              + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
              + 6);
        eVec2.x = *((float *)v37->pVertexData
                  + 12 * ((int)v22[-1].modelvertexdata + (unsigned int)v37[-3].pVertexData / 0x30 + v23)
                  + 4)
                - center_pos.x;
        eVec2.y = v24 - center_pos.y;
        eVec2.z = v25 - center_pos.z;
        v26 = (float)((float)(center_nor.y * (float)(v24 - center_pos.y)) + (float)(center_nor.x * eVec2.x))
            + (float)(center_nor.z * (float)(v25 - center_pos.z));
        vec.x = eVec2.x - (float)(center_nor.x * v26);
        vec.y = (float)(v24 - center_pos.y) - (float)(center_nor.y * v26);
        vec.z = (float)(v25 - center_pos.z) - (float)(center_nor.z * v26);
        VectorNormalize(&vec);
        if ( *(_WORD *)(*(_DWORD *)(v21 + 12) + 2 * *(unsigned __int8 *)(v21 + 8) + 154) != 0 )
          break;
        v27 = *(_DWORD *)v21;
        if ( v27 == 0 )
          break;
        v28 = *(unsigned __int8 *)(v27 + 8);
        v29 = *(_DWORD *)(v27 + 12);
        v21 = v29 + 16 * dword_520064[v28] + 236;
      }
      while ( v29 + 16 * dword_520064[v28] != -236 );
      VectorNormalize(vec: &eVec1);
      VectorNormalize(vec: &eVec2);
      v30 = (float)((float)(eVec2.y * eVec1.y) + (float)(eVec2.x * eVec1.x)) + (float)(eVec2.z * eVec1.z);
      __libm_sse2_acos(x: v31);
      baseQuad->loopGapAngle[baseLocalID] = (int)(v30 * 65535.0 * 0.1591549432737564);
    }
    else
    {
      baseQuad->loopGapAngle[baseLocalID] = 0xFFFF / (2 * (baseQuad->valences[baseLocalID] == 2) + 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402040
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(struct OptimizedModel::SubD_Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(
        OptimizedModel::COptimizeSubDBuilder *this,
        OptimizedModel::SubD_Face_t *baseQuad)
{
  unsigned __int16 *vUV0; // edx
  unsigned __int16 v3; // si
  unsigned __int16 origMeshVertID; // ax
  OptimizedModel::HalfEdge *twin; // ebx
  OptimizedModel::HalfEdge *v6; // ecx
  unsigned __int16 patchID; // di
  OptimizedModel::HalfEdge *v8; // eax
  __int16 v9; // si
  __int16 iMaxNeighborCorner; // [esp+10h] [ebp-28h]
  unsigned __int16 iNeighborPatchU; // [esp+14h] [ebp-24h]
  unsigned __int16 iNeighborPatch; // [esp+18h] [ebp-20h]
  unsigned __int16 p; // [esp+1Ch] [ebp-1Ch]
  OptimizedModel::HalfEdge *halfEdges; // [esp+20h] [ebp-18h]
  int i; // [esp+24h] [ebp-14h]
  OptimizedModel::COptimizeSubDBuilder *v16; // [esp+28h] [ebp-10h]
  unsigned __int16 v17; // [esp+2Ch] [ebp-Ch]
  unsigned __int16 v18; // [esp+30h] [ebp-8h]
  unsigned __int16 iMaxPatch; // [esp+34h] [ebp-4h]

  p = baseQuad->patchID;
  v16 = this;
  i = 0;
  halfEdges = baseQuad->halfEdges;
  vUV0 = baseQuad->vUV0;
  while ( 1 )
  {
    v3 = *(vUV0 - 100);
    origMeshVertID = this->m_vtxList->m_Memory.m_pMemory[v3].origMeshVertID;
    *vUV0 = origMeshVertID;
    vUV0[4] = origMeshVertID;
    vUV0[8] = origMeshVertID;
    twin = halfEdges->twin;
    v17 = -1;
    if ( halfEdges->twin != nullptr )
    {
      v17 = twin->patch->vtxIDs[(twin->localID + 1) & 3];
      if ( v17 != 0xFFFF && twin->patch->patchID > p )
        vUV0[4] = this->m_vtxList->m_Memory.m_pMemory[v17].origMeshVertID;
    }
    iNeighborPatchU = -1;
    v6 = baseQuad->halfEdges[(i + 3) % 4].twin;
    v18 = -1;
    if ( v6 != nullptr )
    {
      v18 = v6->patch->vtxIDs[v6->localID & 3];
      if ( v18 != 0xFFFF )
      {
        iNeighborPatchU = v6->patch->patchID;
        if ( iNeighborPatchU > p )
          vUV0[8] = v16->m_vtxList->m_Memory.m_pMemory[v18].origMeshVertID;
      }
    }
    patchID = baseQuad->patchID;
    v8 = twin;
    iNeighborPatch = -1;
    iMaxNeighborCorner = v3;
    iMaxPatch = baseQuad->patchID;
    if ( twin != nullptr )
    {
      do
      {
        v8 = v8->patch->halfEdges[dword_52003C[v8->localID]].twin;
        v9 = -1;
        if ( v8 != nullptr )
          v9 = v8->patch->vtxIDs[(v8->localID + 1) & 3];
        if ( v9 != -1 )
        {
          iNeighborPatch = v8->patch->patchID;
          if ( iNeighborPatch <= iMaxPatch )
          {
            patchID = iMaxPatch;
          }
          else
          {
            patchID = v8->patch->patchID;
            iMaxPatch = patchID;
            iMaxNeighborCorner = v9;
          }
        }
      }
      while ( iNeighborPatch != iNeighborPatchU && v8 != nullptr );
      v3 = iMaxNeighborCorner;
    }
    if ( v6 != nullptr && v6->patch->patchID > patchID )
    {
      v3 = v18;
      patchID = v6->patch->patchID;
    }
    if ( twin != nullptr && twin->patch->patchID > patchID )
      v3 = v17;
    ++halfEdges;
    vUV0[12] = v16->m_vtxList->m_Memory.m_pMemory[v3].origMeshVertID;
    ++vUV0;
    if ( ++i >= 4 )
      break;
    this = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402260
// Name: private: void OptimizedModel::COptimizeSubDBuilder::Propagate(class CUtlVector<struct OptimizedModel::Orientation,class CUtlMemory<struct OptimizedModel::Orientation,int>> __near &,struct OptimizedModel::HalfEdge __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::Propagate(
        OptimizedModel::COptimizeSubDBuilder *this,
        CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > *orientationArray,
        OptimizedModel::HalfEdge *pEdge,
        bool dir)
{
  OptimizedModel::HalfEdge *i; // esi
  OptimizedModel::SubD_Face_t *patch; // edx
  OptimizedModel::HalfEdge *halfEdges; // eax
  int j; // ecx
  OptimizedModel::Orientation *v8; // eax
  OptimizedModel::Orientation v9; // cl

  for ( i = pEdge->twin;
        i != nullptr;
        i = i->patch->halfEdges[dword_52003C[i->localID]].patch->halfEdges[dword_52003C[i->patch->halfEdges[dword_52003C[i->localID]].localID]].twin )
  {
    patch = i->patch;
    if ( patch == nullptr )
      break;
    halfEdges = patch->halfEdges;
    for ( j = 0; halfEdges != i; ++j )
      ++halfEdges;
    v8 = &orientationArray->m_Memory.m_pMemory[patch->patchID];
    if ( j == 1 || j == 3 )
    {
      if ( (*(_BYTE *)v8 & 4) != 0 )
        return;
      v9 = (OptimizedModel::Orientation)(*(_BYTE *)v8 & 0xFE | (dir ^ (j == 1)) & 1 | 4);
    }
    else
    {
      if ( (*(_BYTE *)v8 & 8) != 0 )
        return;
      v9 = (OptimizedModel::Orientation)(*(_BYTE *)v8 & 0xFD | (2 * ((dir ^ (j == 0)) & 1 | 4)));
    }
    *v8 = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402330
// Name: public: void OptimizedModel::COptimizeSubDBuilder::TagCreases(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::TagCreases(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // esi
  int v2; // eax
  int *v3; // edi
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  const mstudio_meshvertexdata_t *const *m_vtxData; // ecx
  const mstudio_meshvertexdata_t *v11; // edi
  int *v12; // ecx
  float *v13; // ebx
  int v14; // eax
  unsigned int v15; // kr00_4
  int v16; // ecx
  unsigned int v17; // esi
  bool v18; // zf
  int v19; // ecx
  const mstudio_meshvertexdata_t *v20; // edi
  const mstudio_modelvertexdata_t *modelvertexdata; // ebx
  unsigned int v22; // esi
  int quad0vtx1ID; // [esp+4h] [ebp-24h]
  int quad1vtx1ID; // [esp+8h] [ebp-20h]
  OptimizedModel::Vertex_t *m_pMemory; // [esp+Ch] [ebp-1Ch]
  OptimizedModel::Vertex_t *v26; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  int *v28; // [esp+14h] [ebp-14h]
  _WORD *v29; // [esp+18h] [ebp-10h]
  OptimizedModel::SubD_Face_t *pPatch; // [esp+20h] [ebp-8h]
  int *v32; // [esp+24h] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; (unsigned __int16)i < v1->m_numPatches; v2 = (unsigned __int16)i )
  {
    v3 = dword_52007C;
    v4 = (int)&v1->m_faceList->m_Memory.m_pMemory[v2];
    pPatch = (OptimizedModel::SubD_Face_t *)v4;
    v32 = dword_52007C;
    v29 = (_WORD *)(v4 + 154);
    v28 = (int *)(v4 + 236);
    while ( 1 )
    {
      v5 = *v28;
      if ( *v28 != 0 )
      {
        v6 = *(_DWORD *)(v5 + 12);
        v7 = *(unsigned __int8 *)(v5 + 8);
        quad0vtx1ID = *(unsigned __int16 *)(v4 + 2 * *v3 + 2);
        v8 = *(unsigned __int16 *)(v6 + 2 * MOD4_0[v7] + 2);
        v9 = *(unsigned __int16 *)(v6 + 2 * dword_52007C[v7] + 2);
        quad1vtx1ID = v8;
        m_vtxData = v1->m_vtxData;
        v11 = *m_vtxData;
        m_pMemory = v1->m_vtxList->m_Memory.m_pMemory;
        v12 = **(int ***)m_vtxData;
        v13 = (float *)(*v12
                      + 48
                      * ((int)v11[-1].modelvertexdata
                       + *(v12 - 6) / 0x30u
                       + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v9 + v9))
                      + 28);
        v14 = pPatch->vtxIDs[*(v32 - 1)];
        v15 = *(v12 - 6);
        v16 = *v12;
        v17 = (unsigned int)v11[-1].modelvertexdata
            + v15 / 0x30
            + *(unsigned __int16 *)((char *)&m_pMemory->origMeshVertID + 8 * v14 + v14);
        v18 = *v13 == *(float *)(v16 + 48 * v17 + 28);
        v19 = v16 + 48 * v17 + 28;
        if ( !v18
          || v13[1] != *(float *)(v19 + 4)
          || v13[2] != *(float *)(v19 + 8)
          || (v20 = *this->m_vtxData,
              v26 = this->m_vtxList->m_Memory.m_pMemory,
              modelvertexdata = v20->modelvertexdata,
              v22 = (unsigned int)v20[-1].modelvertexdata
                  + (unsigned int)v20->modelvertexdata[-3].pVertexData / 0x30
                  + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad0vtx1ID + quad0vtx1ID),
              *((float *)modelvertexdata->pVertexData
              + 12
              * ((int)v20[-1].modelvertexdata
               + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
               + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
              + 7) != *((float *)v20->modelvertexdata->pVertexData + 12 * v22 + 7))
          || *((float *)modelvertexdata->pVertexData
             + 12
             * ((int)v20[-1].modelvertexdata
              + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
             + 8) != *((float *)modelvertexdata->pVertexData + 12 * v22 + 8)
          || *((float *)modelvertexdata->pVertexData
             + 12
             * ((int)v20[-1].modelvertexdata
              + (unsigned int)modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&v26->origMeshVertID + 8 * quad1vtx1ID + quad1vtx1ID))
             + 9) != *((float *)modelvertexdata->pVertexData + 12 * v22 + 9) )
        {
          *v29 = 1;
          pPatch->bndVtx[*(v32 - 1)] = 1;
          pPatch->bndVtx[*v32] = 1;
        }
        v1 = this;
      }
      ++v29;
      v28 += 4;
      v3 = v32 + 1;
      v32 = v3;
      if ( (int)v3 >= (int)dword_52008C )
        break;
      v4 = (int)pPatch;
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025E0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::RemapIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::RemapIndices(OptimizedModel::COptimizeSubDBuilder *this)
{
  OptimizedModel::COptimizeSubDBuilder *v1; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v5; // eax
  int *v6; // edi
  const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // edi
  int v8; // eax
  int v9; // ecx
  const mstudio_meshvertexdata_t *v10; // esi
  _QWORD *pVertexData; // ecx
  __int64 v12; // xmm0_8
  _QWORD *v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // esi
  OptimizedModel::COptimizeSubDBuilder *v17; // edx
  int v18; // esi
  float vPosi_8; // [esp+14h] [ebp-28h]
  __int64 vPosj; // [esp+18h] [ebp-24h]
  int v21; // [esp+28h] [ebp-14h]
  int v22; // [esp+2Ch] [ebp-10h]
  int j; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  int ia; // [esp+34h] [ebp-8h]

  v1 = this;
  for ( i = 0; i < v1->m_vtxList->m_Size; ++i )
  {
    m_Size = v1->m_IndexRemapTable.m_Size;
    m_nAllocationCount = v1->m_IndexRemapTable.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<KeyValues *,int> *)&v1->m_IndexRemapTable,
        num: m_Size - m_nAllocationCount + 1);
    ++v1->m_IndexRemapTable.m_Size;
    m_pMemory = v1->m_IndexRemapTable.m_Memory.m_pMemory;
    v5 = v1->m_IndexRemapTable.m_Size - m_Size - 1;
    v1->m_IndexRemapTable.m_pElements = m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
    v6 = &v1->m_IndexRemapTable.m_Memory.m_pMemory[m_Size];
    if ( v6 != nullptr )
      *v6 = i;
  }
  m_vtxList = v1->m_vtxList;
  v8 = m_vtxList->m_Size;
  v21 = 0;
  if ( v8 > 0 )
  {
    ia = 0;
    do
    {
      v9 = v21 + 1;
      j = v21 + 1;
      if ( v21 + 1 < v8 )
      {
        v22 = ia * 9 + 9;
        do
        {
          v10 = *v1->m_vtxData;
          pVertexData = v10->modelvertexdata->pVertexData;
          v12 = pVertexData[6
                          * (int)((int)v10[-1].modelvertexdata
                                + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
                                + m_vtxList->m_Memory.m_pMemory[ia].origMeshVertID)
                          + 2];
          vPosi_8 = *(float *)&pVertexData[6
                                         * (int)((int)v10[-1].modelvertexdata
                                               + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
                                               + m_vtxList->m_Memory.m_pMemory[ia].origMeshVertID)
                                         + 3];
          v13 = pVertexData;
          v14 = (unsigned int)v10[-1].modelvertexdata
              + (unsigned int)v10->modelvertexdata[-3].pVertexData / 0x30
              + *(unsigned __int16 *)((char *)&m_vtxList->m_Memory.m_pMemory->origMeshVertID + v22);
          vPosj = v13[6 * v14 + 2];
          if ( *(float *)&vPosj == *(float *)&v12
            && *((float *)&vPosj + 1) == *((float *)&v12 + 1)
            && *(float *)&v13[6 * v14 + 3] == vPosi_8 )
          {
            v15 = j;
            v16 = v21;
            if ( v21 >= j )
              v16 = j;
            v17 = this;
            this->m_IndexRemapTable.m_Memory.m_pMemory[j] = v16;
            v18 = v21;
            if ( v21 >= j )
              v18 = j;
            this->m_IndexRemapTable.m_Memory.m_pMemory[v21] = v18;
          }
          else
          {
            v15 = j;
            v17 = this;
          }
          m_vtxList = v17->m_vtxList;
          v22 += 9;
          v1 = this;
          j = v15 + 1;
        }
        while ( v15 + 1 < m_vtxList->m_Size );
        v9 = v21 + 1;
      }
      m_vtxList = v1->m_vtxList;
      v8 = m_vtxList->m_Size;
      ++ia;
      v21 = v9;
    }
    while ( v9 < v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004027B0
// Name: private: void OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(
        OptimizedModel::COptimizeSubDBuilder *this)
{
  int v1; // edi
  OptimizedModel::Orientation *m_pMemory; // ebx
  OptimizedModel::HalfEdge *halfEdges; // eax
  bool v5; // zf
  int v6; // edi
  int m_nGrowSize; // esi
  int m_numPatches; // [esp-4h] [ebp-38h]
  CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > orientationArray; // [esp+Ch] [ebp-28h] BYREF
  unsigned int v10; // [esp+20h] [ebp-14h]
  OptimizedModel::HalfEdge *pEdges; // [esp+24h] [ebp-10h]
  int v12; // [esp+30h] [ebp-4h]

  v1 = 0;
  memset(&orientationArray, 0, sizeof(orientationArray));
  m_numPatches = this->m_numPatches;
  v12 = 0;
  CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int>>::InsertMultipleBefore(
    this: &orientationArray,
    elem: 0,
    num: m_numPatches);
  m_pMemory = orientationArray.m_Memory.m_pMemory;
  if ( this->m_numPatches > 0 )
  {
    v10 = 0;
    do
    {
      halfEdges = this->m_faceList->m_Memory.m_pMemory[v10 / 0x12C].halfEdges;
      v5 = (*(_BYTE *)&m_pMemory[v1] & 4) == 0;
      pEdges = halfEdges;
      if ( v5 )
      {
        m_pMemory[v1] = (OptimizedModel::Orientation)(*(_BYTE *)&m_pMemory[v1] & 0xFA | 4);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: halfEdges + 1, dir: false);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: pEdges + 3, dir: true);
        halfEdges = pEdges;
      }
      if ( (*(_BYTE *)&m_pMemory[v1] & 8) == 0 )
      {
        m_pMemory[v1] = (OptimizedModel::Orientation)(*(_BYTE *)&m_pMemory[v1] & 0xF5 | 8);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: halfEdges, dir: false);
        OptimizedModel::COptimizeSubDBuilder::Propagate(this, &orientationArray, pEdge: pEdges + 2, dir: true);
      }
      v10 += 300;
      ++v1;
    }
    while ( v1 < this->m_numPatches );
  }
  v6 = 0;
  if ( this->m_numPatches > 0 )
  {
    v10 = 0;
    do
    {
      OptimizedModel::COptimizeSubDBuilder::RotateFace(
        this,
        pPatch: &this->m_faceList->m_Memory.m_pMemory[v10 / 0x12C],
        nTimesToRotate: nTimesToRotate[2 * ((*(_BYTE *)&m_pMemory[v6] & 2) != 0) + (*(_BYTE *)&m_pMemory[v6] & 1)]);
      v10 += 300;
      ++v6;
    }
    while ( v6 < this->m_numPatches );
  }
  m_nGrowSize = orientationArray.m_Memory.m_nGrowSize;
  v12 = 1;
  orientationArray.m_Size = 0;
  if ( orientationArray.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    m_pMemory = nullptr;
  }
  v12 = -1;
  if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00402930
// Name: public: void OptimizedModel::COptimizeSubDBuilder::ProcessPatches(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::ProcessPatches(
        OptimizedModel::COptimizeSubDBuilder *this,
        bool bIsTagged,
        bool bMendVertices)
{
  int v3; // edi
  _WORD *v5; // eax
  int v6; // esi
  int j; // ecx
  int v8; // edi
  _DWORD *v9; // edx
  OptimizedModel::SubD_Face_t *v10; // esi
  OptimizedModel::SubD_Face_t *v11; // edi
  int m; // esi
  int n; // esi
  int m_Size; // esi
  OptimizedModel::SubD_Face_t *v15; // eax
  int v16; // edi
  OptimizedModel::SubD_Face_t *m_pMemory; // ecx
  int v18; // eax
  int v19; // eax
  OptimizedModel::SubD_Face_t *v20; // edi
  int v21; // eax
  int ii; // edx
  OptimizedModel::SubD_Face_t *v23; // esi
  OptimizedModel::SubD_Face_t *v24; // edi
  int v25; // edx
  OptimizedModel::SubD_Face_t *v26; // edi
  OptimizedModel::SubD_Face_t *v27; // esi
  bool v28; // zf
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > regFaceList; // [esp+Ch] [ebp-40h] BYREF
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > extraFaceList; // [esp+20h] [ebp-2Ch] BYREF
  OptimizedModel::SubD_Face_t *pPatch; // [esp+34h] [ebp-18h]
  int i; // [esp+38h] [ebp-14h]
  int k; // [esp+3Ch] [ebp-10h]
  int v34; // [esp+48h] [ebp-4h]
  int bIsTaggeda; // [esp+54h] [ebp+8h]
  int bIsTaggedb; // [esp+54h] [ebp+8h]
  int bIsTaggedc; // [esp+54h] [ebp+8h]
  int bIsTaggedd; // [esp+54h] [ebp+8h]

  v3 = 0;
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    pPatch = nullptr;
    do
    {
      v5 = (unsigned __int16 *)((char *)&pPatch->patchID + (unsigned int)this->m_faceList->m_Memory.m_pMemory);
      k = 0;
      v6 = 0;
      for ( j = 77; j < 81; ++j )
      {
        *v5 = i;
        if ( !bIsTagged )
        {
          v5[j - 4] = 0;
          v5[j] = 0;
          v5[j + 4] = 0;
        }
        v8 = k;
        v5[j + 8] = 0;
        v5[j - 12] = 0;
        v5[j - 8] = 0;
        v5[j + 12] = -1;
        v5[2 * v8 + 93] = 0x4000;
        v5[2 * v8 + 94] = 0x4000;
        v9 = &v5[v6 + 118];
        *(_DWORD *)&v5[v6 + 120] = v9;
        *v9 = 0;
        LOBYTE(v5[v6 + 122]) = v8;
        *(_DWORD *)&v5[v6 + 124] = v5;
        v6 += 8;
        k = v8 + 1;
      }
      ++pPatch;
      v3 = 0;
      ++i;
    }
    while ( i < this->m_numPatches );
  }
  OptimizedModel::COptimizeSubDBuilder::RemapIndices(this);
  OptimizedModel::COptimizeSubDBuilder::BuildNeighborhoodInfo(this);
  OptimizedModel::COptimizeSubDBuilder::CheckForManifoldMesh(this);
  OptimizedModel::COptimizeSubDBuilder::ConsistentPatchOrientation(this);
  if ( !bIsTagged )
    OptimizedModel::COptimizeSubDBuilder::TagCreases(this);
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    pPatch = nullptr;
    do
    {
      v10 = (OptimizedModel::SubD_Face_t *)((char *)pPatch + (unsigned int)this->m_faceList->m_Memory.m_pMemory);
      for ( bIsTaggeda = 0; bIsTaggeda < 4; ++bIsTaggeda )
      {
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorStart(this, pPatch: v10, k: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputePerVertexInfo(this, baseQuad: v10, baseLocalID: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorOneRing(this, baseQuad: v10, baseLocalID: bIsTaggeda);
        OptimizedModel::COptimizeSubDBuilder::ComputeSectorAngle(
          this,
          a2: (int)this,
          baseQuad: v10,
          baseLocalID: bIsTaggeda);
      }
      ++pPatch;
      v3 = 0;
      ++i;
    }
    while ( i < this->m_numPatches );
  }
  pPatch = nullptr;
  if ( this->m_numPatches > 0 )
  {
    bIsTaggedb = 0;
    do
    {
      v11 = &this->m_faceList->m_Memory.m_pMemory[bIsTaggedb];
      for ( m = 0; m < 4; ++m )
        OptimizedModel::COptimizeSubDBuilder::ComputeNbCorners(this, baseQuad: v11, baseLocalID: m);
      ++bIsTaggedb;
      pPatch = (OptimizedModel::SubD_Face_t *)((char *)pPatch + 1);
    }
    while ( (int)pPatch < this->m_numPatches );
    v3 = 0;
  }
  for ( n = 0; n < this->m_numPatches; ++v3 )
  {
    OptimizedModel::COptimizeSubDBuilder::ComputeNeighborTexcoords(
      this,
      baseQuad: &this->m_faceList->m_Memory.m_pMemory[v3]);
    ++n;
  }
  OptimizedModel::COptimizeSubDBuilder::SetMinOneRingIndices(this);
  m_Size = 0;
  memset(&regFaceList, 0, sizeof(regFaceList));
  v15 = nullptr;
  v34 = 1;
  memset(&extraFaceList, 0, sizeof(extraFaceList));
  i = 0;
  if ( this->m_numPatches > 0 )
  {
    bIsTaggedc = 0;
    do
    {
      pPatch = &this->m_faceList->m_Memory.m_pMemory[bIsTaggedc];
      if ( OptimizedModel::FaceIsRegular(patch: pPatch) )
      {
        v16 = m_Size;
        if ( m_Size + 1 > regFaceList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
            this: &regFaceList.m_Memory,
            num: m_Size - regFaceList.m_Memory.m_nAllocationCount + 1);
          m_Size = regFaceList.m_Size;
        }
        m_pMemory = regFaceList.m_Memory.m_pMemory;
        regFaceList.m_Size = ++m_Size;
        regFaceList.m_pElements = regFaceList.m_Memory.m_pMemory;
        if ( m_Size - v16 - 1 > 0 )
        {
          _V_memmove(
            dest: &regFaceList.m_Memory.m_pMemory[v16 + 1],
            src: &regFaceList.m_Memory.m_pMemory[v16],
            count: 300 * (m_Size - v16 - 1));
          m_pMemory = regFaceList.m_Memory.m_pMemory;
        }
      }
      else
      {
        v16 = extraFaceList.m_Size;
        v18 = extraFaceList.m_Size;
        if ( extraFaceList.m_Size + 1 > extraFaceList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
            this: &extraFaceList.m_Memory,
            num: extraFaceList.m_Size - extraFaceList.m_Memory.m_nAllocationCount + 1);
          v18 = extraFaceList.m_Size;
        }
        m_pMemory = extraFaceList.m_Memory.m_pMemory;
        extraFaceList.m_Size = v18 + 1;
        v19 = v18 - v16;
        extraFaceList.m_pElements = extraFaceList.m_Memory.m_pMemory;
        if ( v19 > 0 )
        {
          _V_memmove(
            dest: &extraFaceList.m_Memory.m_pMemory[v16 + 1],
            src: &extraFaceList.m_Memory.m_pMemory[v16],
            count: 300 * v19);
          m_pMemory = extraFaceList.m_Memory.m_pMemory;
        }
      }
      v20 = &m_pMemory[v16];
      if ( v20 != nullptr )
      {
        qmemcpy(v20, pPatch, sizeof(OptimizedModel::SubD_Face_t));
        m_Size = regFaceList.m_Size;
      }
      ++bIsTaggedc;
      ++i;
    }
    while ( i < this->m_numPatches );
    v15 = extraFaceList.m_Memory.m_pMemory;
  }
  if ( m_Size > 0 )
  {
    v21 = 0;
    for ( ii = m_Size; ii != 0; --ii )
    {
      v23 = &regFaceList.m_Memory.m_pMemory[v21];
      v24 = &this->m_faceList->m_Memory.m_pMemory[v21++];
      qmemcpy(v24, v23, sizeof(OptimizedModel::SubD_Face_t));
    }
    m_Size = regFaceList.m_Size;
    v15 = extraFaceList.m_Memory.m_pMemory;
  }
  if ( extraFaceList.m_Size > 0 )
  {
    v25 = m_Size;
    bIsTaggedd = extraFaceList.m_Size;
    do
    {
      v26 = &this->m_faceList->m_Memory.m_pMemory[v25];
      v27 = v15++;
      ++v25;
      v28 = bIsTaggedd-- == 1;
      qmemcpy(v26, v27, sizeof(OptimizedModel::SubD_Face_t));
    }
    while ( !v28 );
    v15 = extraFaceList.m_Memory.m_pMemory;
  }
  LOBYTE(v34) = 2;
  extraFaceList.m_Size = 0;
  if ( extraFaceList.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
    extraFaceList.m_Memory.m_pMemory = nullptr;
    v15 = nullptr;
  }
  LOBYTE(v34) = 0;
  if ( extraFaceList.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
  v34 = 3;
  regFaceList.m_Size = 0;
  if ( regFaceList.m_Memory.m_nGrowSize >= 0 && regFaceList.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: regFaceList.m_Memory.m_pMemory);
    regFaceList.m_Memory.m_pMemory = nullptr;
  }
  v34 = -1;
  if ( regFaceList.m_Memory.m_nGrowSize >= 0 && regFaceList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: regFaceList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00402D50
// Name: public: OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(class CUtlVector<struct OptimizedModel::SubD_Face_t,class CUtlMemory<struct OptimizedModel::SubD_Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> const __near &,struct mstudio_meshvertexdata_t const __near * const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::COptimizeSubDBuilder *__thiscall OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(
        OptimizedModel::COptimizeSubDBuilder *this,
        CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *subDFaceList,
        const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vertexList,
        const mstudio_meshvertexdata_t *const *vertexData,
        bool bIsTagged,
        bool bMendVertices)
{
  this->m_vtxList = vertexList;
  this->m_faceList = subDFaceList;
  this->m_vtxData = vertexData;
  this->m_IndexRemapTable.m_Memory.m_pMemory = nullptr;
  this->m_IndexRemapTable.m_Memory.m_nAllocationCount = 0;
  this->m_IndexRemapTable.m_Memory.m_nGrowSize = 0;
  this->m_IndexRemapTable.m_Size = 0;
  this->m_IndexRemapTable.m_pElements = nullptr;
  this->m_numPatches = subDFaceList->m_Size;
  OptimizedModel::COptimizeSubDBuilder::ProcessPatches(this, bIsTagged, bMendVertices);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408220
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<KeyValues *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  KeyValues **m_pMemory; // edx
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
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AB60
// Name: public: CUtlMemory<struct OptimizedModel::Orientation,int>::~CUtlMemory<struct OptimizedModel::Orientation,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Orientation,int>::~CUtlMemory<OptimizedModel::Orientation,int>(
        CUtlMemory<OptimizedModel::Orientation,int> *this)
{
  if ( this->m_nGrowSize >= 0 )
  {
    if ( this->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
      this->m_pMemory = nullptr;
    }
    this->m_nAllocationCount = 0;
  }
}

} // namespace subdbaker
