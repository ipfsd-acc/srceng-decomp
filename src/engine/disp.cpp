// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/disp.cpp
// Functions: 42
// ============================================================

#include "engine\disp.h"

//------------------------------------------------------------------------------
// Address: 0x100B9550
// Name: public: virtual class CPowerInfo const __near * CDispInfo::GetPowerInfo(void)const
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__thiscall CDispInfo::GetPowerInfo(CDispInfo *this)
{
  return (const CPowerInfo *)LODWORD(this->m_BaseSurfaceTexCoords[3].y);
}

//------------------------------------------------------------------------------
// Address: 0x100B9560
// Name: public: virtual class CDispNeighbor __near * CDispInfo::GetEdgeNeighbor(int)
// Source: json
//------------------------------------------------------------------------------
CDispNeighbor *__thiscall CDispInfo::GetEdgeNeighbor(CDispInfo *this, int index)
{
  return (CDispNeighbor *)((char *)&this->m_BaseSurfaceTexCoords[4] + 12 * index);
}

//------------------------------------------------------------------------------
// Address: 0x100B9580
// Name: public: virtual class CDispCornerNeighbors __near * CDispInfo::GetCornerNeighbors(int)
// Source: json
//------------------------------------------------------------------------------
CDispCornerNeighbors *__thiscall CDispInfo::GetCornerNeighbors(CDispInfo *this, int index)
{
  return (CDispCornerNeighbors *)(&this->m_EdgeNeighbors[3].m_SubNeighbors[1].m_NeighborOrientation + 10 * index);
}

//------------------------------------------------------------------------------
// Address: 0x100B95A0
// Name: public: virtual class CDispUtilsHelper __near * CDispInfo::GetDispUtilsByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__thiscall CDispInfo::GetDispUtilsByIndex(CDispInfo *this, int index)
{
  int v2; // eax

  if ( index == 0xFFFF )
    return nullptr;
  v2 = *(_DWORD *)(*(_DWORD *)&this->m_Tag + 4) + 620 * index;
  if ( v2 == 0 )
    return nullptr;
  else
    return (CDispUtilsHelper *)(v2 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100B95D0
// Name: private: void CDispInfo::UpdateNodeBoundingBoxes_R(class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::UpdateNodeBoundingBoxes_R(
        CDispInfo *this,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  int v5; // eax
  DispNodeInfo_t *v6; // esi
  int v7; // ebx
  DispNodeInfo_t *v8; // ecx
  double x; // st7
  double y; // st7
  double z; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // ecx
  int v16; // eax
  unsigned int m_nIndexSize; // ecx
  unsigned __int16 *m_pIndices; // edx
  unsigned __int16 v19; // bx
  int j; // edx
  double v21; // st7
  float *v22; // ecx
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  unsigned __int16 tempIndices[4]; // [esp+0h] [ebp-8h]
  const CVertIndex *nodeIndexa; // [esp+10h] [ebp+8h]
  int iNodeBitIndexa; // [esp+14h] [ebp+Ch]
  int i; // [esp+18h] [ebp+10h]

  v5 = nodeIndex->x + this->m_pPowerInfo->m_SideLength * nodeIndex->y;
  v6 = &this->m_pNodeInfo[iNodeBitIndex];
  v6->m_maxs.x = -3.4028235e38;
  v6->m_maxs.y = -3.4028235e38;
  v6->m_maxs.z = -3.4028235e38;
  v6->m_mins.x = 3.4028235e38;
  v6->m_mins.y = 3.4028235e38;
  v6->m_mins.z = 3.4028235e38;
  if ( iLevel + 1 < this->m_Power && (v6->m_Flags & 1) != 0 )
  {
    v7 = iNodeBitIndex + 1;
    nodeIndexa = (const CVertIndex *)(16 * v5);
    for ( iNodeBitIndexa = 4; iNodeBitIndexa != 0; --iNodeBitIndexa )
    {
      CDispInfo::UpdateNodeBoundingBoxes_R(
        this,
        nodeIndex: (const CVertIndex *)((char *)nodeIndexa + (unsigned int)this->m_pPowerInfo->m_pChildVerts),
        iNodeBitIndex: v7,
        iLevel: iLevel + 1);
      v8 = &this->m_pNodeInfo[v7];
      if ( v8->m_mins.x != 3.4028235e38 )
      {
        x = v6->m_maxs.x;
        if ( v8->m_maxs.x >= x )
          x = v8->m_maxs.x;
        v6->m_maxs.x = x;
        y = v6->m_maxs.y;
        if ( v8->m_maxs.y >= y )
          y = v8->m_maxs.y;
        v6->m_maxs.y = y;
        z = v6->m_maxs.z;
        if ( v8->m_maxs.z >= z )
          z = v8->m_maxs.z;
        v6->m_maxs.z = z;
        v12 = v6->m_mins.x;
        if ( v8->m_mins.x <= v12 )
          v12 = v8->m_mins.x;
        v6->m_mins.x = v12;
        v13 = v6->m_mins.y;
        if ( v8->m_mins.y <= v13 )
          v13 = v8->m_mins.y;
        v6->m_mins.y = v13;
        v14 = v6->m_mins.z;
        if ( v8->m_mins.z <= v14 )
          v14 = v8->m_mins.z;
        v6->m_mins.z = v14;
      }
      v7 += this->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      ++nodeIndexa;
    }
  }
  v15 = 0;
  i = 0;
  if ( v6->m_Count != 0 )
  {
    do
    {
      v16 = v15 + v6->m_FirstTesselationIndex;
      m_nIndexSize = this->m_MeshReader.m_nIndexSize;
      m_pIndices = this->m_MeshReader.m_pIndices;
      tempIndices[0] = m_pIndices[v16 * m_nIndexSize] - LOWORD(this->m_iVertOffset);
      v19 = m_pIndices[m_nIndexSize * (v16 + 1)];
      LOWORD(m_pIndices) = this->m_iVertOffset;
      tempIndices[1] = v19 - (_WORD)m_pIndices;
      tempIndices[2] = this->m_MeshReader.m_pIndices[m_nIndexSize * (v16 + 2)] - (_WORD)m_pIndices;
      for ( j = 0; j < 3; ++j )
      {
        v21 = v6->m_maxs.x;
        v22 = (float *)((char *)this->m_MeshReader.m_pPosition
                      + this->m_MeshReader.m_VertexSize_Position * tempIndices[j]);
        if ( *v22 >= v21 )
          v21 = *v22;
        v6->m_maxs.x = v21;
        v23 = v6->m_maxs.y;
        if ( v22[1] >= v23 )
          v23 = v22[1];
        v6->m_maxs.y = v23;
        v24 = v6->m_maxs.z;
        if ( v22[2] >= v24 )
          v24 = v22[2];
        v6->m_maxs.z = v24;
        v25 = v6->m_mins.x;
        if ( *v22 <= v25 )
          v25 = *v22;
        v6->m_mins.x = v25;
        v26 = v6->m_mins.y;
        if ( v22[1] <= v26 )
          v26 = v22[1];
        v6->m_mins.y = v26;
        v27 = v6->m_mins.z;
        if ( v22[2] <= v27 )
          v27 = v22[2];
        v6->m_mins.z = v27;
      }
      v15 = i + 3;
      i = v15;
    }
    while ( v15 < v6->m_Count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9850
// Name: public: class Vector CDispInfo::GetFlatVert(int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CDispInfo::GetFlatVert(CDispInfo *this, Vector *result, int iVertex)
{
  int m_SideLength; // esi
  int v4; // eax
  int v5; // edx
  float v6; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float ooInt; // [esp+10h] [ebp+Ch]

  m_SideLength = this->m_pPowerInfo->m_SideLength;
  v4 = iVertex / m_SideLength;
  v5 = iVertex % m_SideLength;
  ooInt = 1.0 / (float)(m_SideLength - 1);
  v6 = (float)v4 * ooInt;
  v8 = (float)((float)(this->m_BaseSurfacePositions[1].x - this->m_BaseSurfacePositions[0].x) * v6)
     + this->m_BaseSurfacePositions[0].x;
  v9 = (float)((float)(this->m_BaseSurfacePositions[1].y - this->m_BaseSurfacePositions[0].y) * v6)
     + this->m_BaseSurfacePositions[0].y;
  v10 = (float)((float)(this->m_BaseSurfacePositions[1].z - this->m_BaseSurfacePositions[0].z) * v6)
      + this->m_BaseSurfacePositions[0].z;
  v11 = (float)((float)(this->m_BaseSurfacePositions[2].x - this->m_BaseSurfacePositions[3].x) * v6)
      + this->m_BaseSurfacePositions[3].x;
  v12 = (float)((float)(this->m_BaseSurfacePositions[2].y - this->m_BaseSurfacePositions[3].y) * v6)
      + this->m_BaseSurfacePositions[3].y;
  v13 = (float)((float)(this->m_BaseSurfacePositions[2].z - this->m_BaseSurfacePositions[3].z) * v6)
      + this->m_BaseSurfacePositions[3].z;
  v14 = (float)v5 * ooInt;
  result->x = (float)((float)(v11 - v8) * v14) + v8;
  result->y = (float)((float)(v12 - v9) * v14) + v9;
  result->z = (float)((float)(v13 - v10) * v14) + v10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B9980
// Name: public: virtual void CDispInfo::ComputeLightmapAndTextureCoordinate(struct RayDispOutput_t const __near &,class Vector2D __near *,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDispInfo::ComputeLightmapAndTextureCoordinate(
        CDispInfo *this@<ecx>,
        const RayDispOutput_t *output,
        Vector2D *luv,
        Vector2D tuv)
{
  const RayDispOutput_t *v4; // edi
  IMaterialSystem_vtbl *v6; // ebx
  int v7; // eax
  Vector2D *v8; // eax
  __m128i v9; // xmm1
  float v10; // xmm0_4
  double v; // st7
  int v12; // ebx
  int v13; // ecx
  float v14; // xmm3_4
  int v15; // eax
  float v16; // xmm2_4
  float v17; // xmm1_4
  int v18; // ecx
  double v19; // st7
  float v20; // xmm3_4
  float v21; // [esp+0h] [ebp-38h]
  float v22; // [esp+4h] [ebp-34h]
  Vector2D u; // [esp+18h] [ebp-20h] BYREF
  Vector2D v1; // [esp+20h] [ebp-18h] BYREF
  Vector2D v2; // [esp+28h] [ebp-10h] BYREF
  __int64 baseUV; // [esp+30h] [ebp-8h] OVERLAPPED BYREF

  v4 = output;
  if ( luv != nullptr )
  {
    ComputePointFromBarycentric(
      v0: (const Vector2D *)((char *)this->m_MeshReader.m_pTexCoord[1]
                       + this->m_MeshReader.m_VertexSize_TexCoord[1] * output->ndxVerts[0]),
      v1: (const Vector2D *)((char *)this->m_MeshReader.m_pTexCoord[1]
                       + this->m_MeshReader.m_VertexSize_TexCoord[1] * output->ndxVerts[1]),
      v2: (const Vector2D *)((char *)this->m_MeshReader.m_pTexCoord[1]
                       + this->m_MeshReader.m_VertexSize_TexCoord[1] * output->ndxVerts[2]),
      u: output->u,
      v: output->v,
      pt: luv);
    v6 = materials->__vftable;
    v7 = SortInfoToLightmapPage(sortID: this->m_ParentSurfID->materialSortID);
    v6->GetLightmapPageSize(this: materials, a2: v7, a3: (int *)&output, a4: (int *)&baseUV + 1);
    v8 = luv;
    v9 = _mm_cvtsi32_si128(HIDWORD(baseUV));
    v10 = (float)(int)output * luv->x;
    luv->x = v10;
    *(float *)v9.m128i_i32 = _mm_cvtepi32_ps(v9).m128_f32[0] * v8->y;
    LODWORD(v8->y) = v9.m128i_i32[0];
    v8->x = v10
          - (float)((float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
                                      + (((char *)this->m_ParentSurfID - (char *)host_state.worldbrush->surfaces2)
                                       & 0xFFFFFFE0))
                  + 0.5);
    v8->y = *(float *)v9.m128i_i32
          - (float)((float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
                                      + (((char *)this->m_ParentSurfID - (char *)host_state.worldbrush->surfaces2)
                                       & 0xFFFFFFE0))
                  + 0.5);
  }
  if ( LODWORD(tuv.x) != 0 )
  {
    v = v4->v;
    v12 = (1 << this->m_Power) + 1;
    v13 = v4->ndxVerts[1];
    v14 = (float)(v4->ndxVerts[0] / v12);
    v15 = v13 / v12;
    v16 = 1.0 / (float)(1 << this->m_Power);
    u.x = (float)((float)v4->ndxVerts[0] - (float)((float)v12 * v14)) * v16;
    v17 = (float)v13;
    v18 = v4->ndxVerts[2];
    u.y = v14 * v16;
    v1.x = (float)(v17 - (float)((float)v12 * (float)v15)) * v16;
    v22 = v;
    v19 = v4->u;
    v1.y = (float)v15 * v16;
    v21 = v19;
    v20 = (float)(v18 / v12);
    v2.x = (float)((float)v18 - (float)((float)v12 * v20)) * v16;
    v2.y = v20 * v16;
    ComputePointFromBarycentric(v0: &u, &v1, &v2, u: v21, v: v22, pt: (Vector2D *)&baseUV);
    TexCoordInQuadFromBarycentric(
      v1: this->m_BaseSurfaceTexCoords,
      v2: &this->m_BaseSurfaceTexCoords[3],
      v3: &this->m_BaseSurfaceTexCoords[2],
      v4: &this->m_BaseSurfaceTexCoords[1],
      uv: (const Vector2D *)&baseUV,
      texCoord: (Vector2D *)LODWORD(tuv.x));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9BC0
// Name: public: void CMeshBuilder::BeginModify(class IMesh __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::BeginModify(
        CMeshBuilder *this,
        IMesh *pMesh,
        int nFirstVertex,
        int nVertexCount,
        int nFirstIndex,
        int nIndexCount)
{
  if ( nVertexCount < 0 )
    nVertexCount = pMesh->VertexCount(this: pMesh);
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->ModifyBeginEx(
    this: pMesh,
    a2: false,
    a3: nFirstVertex,
    a4: nVertexCount,
    a5: nFirstIndex,
    a6: nIndexCount,
    a7: this);
  this->m_IndexBuilder.m_nIndexCount = nIndexCount;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_bModify = true;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_VertexBuilder.m_pVertexBuffer = pMesh;
  qmemcpy(&this->m_VertexBuilder, this, 0xA4u);
  this->m_VertexBuilder.m_nVertexCount = nVertexCount;
  this->m_VertexBuilder.m_nMaxVertexCount = nVertexCount;
  this->m_VertexBuilder.m_NumBoneWeights = this->m_VertexBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  this->m_VertexBuilder.m_bModify = true;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x100B9CB0
// Name: public: void CEngineTesselateHelper::EndTriangle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTesselateHelper::EndTriangle(CEngineTesselateHelper *this)
{
  int m_iVertOffset; // eax
  int m_nCurrentIndex; // edx
  int v3; // edx
  int v4; // edx

  m_iVertOffset = this->m_pDisp->m_iVertOffset;
  this->m_IndexMesh.m_IndexBuilder.m_pIndices[this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex] = m_iVertOffset
                                                                                                + LOWORD(this->m_IndexMesh.m_IndexBuilder.m_nIndexOffset)
                                                                                                + this->m_TempIndices[0];
  this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex += this->m_IndexMesh.m_IndexBuilder.m_nIndexSize;
  m_nCurrentIndex = this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex;
  if ( m_nCurrentIndex > this->m_IndexMesh.m_IndexBuilder.m_nIndexCount )
    this->m_IndexMesh.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
  this->m_IndexMesh.m_IndexBuilder.m_pIndices[this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex] = m_iVertOffset
                                                                                                + this->m_TempIndices[1]
                                                                                                + LOWORD(this->m_IndexMesh.m_IndexBuilder.m_nIndexOffset);
  this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex += this->m_IndexMesh.m_IndexBuilder.m_nIndexSize;
  v3 = this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex;
  if ( v3 > this->m_IndexMesh.m_IndexBuilder.m_nIndexCount )
    this->m_IndexMesh.m_IndexBuilder.m_nIndexCount = v3;
  this->m_IndexMesh.m_IndexBuilder.m_pIndices[this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex] = this->m_TempIndices[2]
                                                                                                + m_iVertOffset
                                                                                                + LOWORD(this->m_IndexMesh.m_IndexBuilder.m_nIndexOffset);
  this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex += this->m_IndexMesh.m_IndexBuilder.m_nIndexSize;
  v4 = this->m_IndexMesh.m_IndexBuilder.m_nCurrentIndex;
  if ( v4 > this->m_IndexMesh.m_IndexBuilder.m_nIndexCount )
    this->m_IndexMesh.m_IndexBuilder.m_nIndexCount = v4;
  this->m_pDisp->m_Indices.m_Memory.m_pMemory[this->m_nIndices] = m_iVertOffset + this->m_TempIndices[0];
  this->m_pDisp->m_Indices.m_Memory.m_pMemory[this->m_nIndices + 1] = m_iVertOffset + this->m_TempIndices[1];
  this->m_pDisp->m_Indices.m_Memory.m_pMemory[this->m_nIndices + 2] = m_iVertOffset + this->m_TempIndices[2];
  this->m_nIndices += 3;
}

//------------------------------------------------------------------------------
// Address: 0x100B9DD0
// Name: private: void CDispInfo::UpdateNodeBoundingBoxes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::UpdateNodeBoundingBoxes(CDispInfo *this)
{
  int v2; // edx
  int v3; // ecx
  Vector *p_m_mins; // eax
  Vector *p_m_maxs; // eax
  const CPowerInfo *m_pPowerInfo; // ecx
  int v7; // eax
  int x; // ecx
  DispNodeInfo_t *m_pNodeInfo; // esi
  int v10; // ebx
  int v11; // eax
  DispNodeInfo_t *v12; // ecx
  double v13; // st7
  double y; // st7
  double z; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  int v19; // ecx
  int v20; // eax
  unsigned int m_nIndexSize; // ecx
  unsigned __int16 *m_pIndices; // edx
  unsigned __int16 v23; // bx
  int j; // edx
  double v25; // st7
  float *v26; // ecx
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  int i; // [esp+0h] [ebp-Ch]
  int v33; // [esp+0h] [ebp-Ch]
  int v34; // [esp+4h] [ebp-8h]
  __int16 v35; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( this->m_pPowerInfo->m_NodeCount > 0 )
  {
    v3 = 0;
    do
    {
      p_m_mins = &this->m_pNodeInfo[v3].m_mins;
      p_m_mins->x = 3.4028235e38;
      p_m_mins->y = 3.4028235e38;
      p_m_mins->z = 3.4028235e38;
      p_m_maxs = &this->m_pNodeInfo[v3].m_maxs;
      p_m_maxs->x = -3.4028235e38;
      p_m_maxs->y = -3.4028235e38;
      p_m_maxs->z = -3.4028235e38;
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_pPowerInfo->m_NodeCount );
  }
  m_pPowerInfo = this->m_pPowerInfo;
  v7 = m_pPowerInfo->m_SideLength * m_pPowerInfo->m_RootNode.y;
  x = m_pPowerInfo->m_RootNode.x;
  m_pNodeInfo = this->m_pNodeInfo;
  m_pNodeInfo->m_maxs.x = -3.4028235e38;
  m_pNodeInfo->m_maxs.y = -3.4028235e38;
  m_pNodeInfo->m_maxs.z = -3.4028235e38;
  v10 = 1;
  v11 = x + v7;
  m_pNodeInfo->m_mins.x = 3.4028235e38;
  m_pNodeInfo->m_mins.y = 3.4028235e38;
  m_pNodeInfo->m_mins.z = 3.4028235e38;
  if ( this->m_Power > 1 && (m_pNodeInfo->m_Flags & 1) != 0 )
  {
    v34 = 16 * v11;
    for ( i = 4; i != 0; --i )
    {
      CDispInfo::UpdateNodeBoundingBoxes_R(
        this,
        nodeIndex: (const CVertIndex *)((char *)this->m_pPowerInfo->m_pChildVerts->m_Verts + v34),
        iNodeBitIndex: v10,
        iLevel: 1);
      v12 = &this->m_pNodeInfo[v10];
      if ( v12->m_mins.x != 3.4028235e38 )
      {
        v13 = m_pNodeInfo->m_maxs.x;
        if ( v12->m_maxs.x >= v13 )
          v13 = v12->m_maxs.x;
        m_pNodeInfo->m_maxs.x = v13;
        y = m_pNodeInfo->m_maxs.y;
        if ( v12->m_maxs.y >= y )
          y = v12->m_maxs.y;
        m_pNodeInfo->m_maxs.y = y;
        z = m_pNodeInfo->m_maxs.z;
        if ( v12->m_maxs.z >= z )
          z = v12->m_maxs.z;
        m_pNodeInfo->m_maxs.z = z;
        v16 = m_pNodeInfo->m_mins.x;
        if ( v12->m_mins.x <= v16 )
          v16 = v12->m_mins.x;
        m_pNodeInfo->m_mins.x = v16;
        v17 = m_pNodeInfo->m_mins.y;
        if ( v12->m_mins.y <= v17 )
          v17 = v12->m_mins.y;
        m_pNodeInfo->m_mins.y = v17;
        v18 = m_pNodeInfo->m_mins.z;
        if ( v12->m_mins.z <= v18 )
          v18 = v12->m_mins.z;
        m_pNodeInfo->m_mins.z = v18;
      }
      v10 += this->m_pPowerInfo->m_NodeIndexIncrements[0];
      v34 += 4;
    }
  }
  v19 = 0;
  v33 = 0;
  if ( m_pNodeInfo->m_Count != 0 )
  {
    do
    {
      v20 = v19 + m_pNodeInfo->m_FirstTesselationIndex;
      m_nIndexSize = this->m_MeshReader.m_nIndexSize;
      m_pIndices = this->m_MeshReader.m_pIndices;
      LOWORD(v34) = m_pIndices[v20 * m_nIndexSize] - LOWORD(this->m_iVertOffset);
      v23 = m_pIndices[m_nIndexSize * (v20 + 1)];
      LOWORD(m_pIndices) = this->m_iVertOffset;
      HIWORD(v34) = v23 - (_WORD)m_pIndices;
      v35 = this->m_MeshReader.m_pIndices[m_nIndexSize * (v20 + 2)] - (_WORD)m_pIndices;
      for ( j = 0; j < 3; ++j )
      {
        v25 = m_pNodeInfo->m_maxs.x;
        v26 = (float *)((char *)this->m_MeshReader.m_pPosition
                      + this->m_MeshReader.m_VertexSize_Position * *((unsigned __int16 *)&v34 + j));
        if ( *v26 >= v25 )
          v25 = *v26;
        m_pNodeInfo->m_maxs.x = v25;
        v27 = m_pNodeInfo->m_maxs.y;
        if ( v26[1] >= v27 )
          v27 = v26[1];
        m_pNodeInfo->m_maxs.y = v27;
        v28 = m_pNodeInfo->m_maxs.z;
        if ( v26[2] >= v28 )
          v28 = v26[2];
        m_pNodeInfo->m_maxs.z = v28;
        v29 = m_pNodeInfo->m_mins.x;
        if ( *v26 <= v29 )
          v29 = *v26;
        m_pNodeInfo->m_mins.x = v29;
        v30 = m_pNodeInfo->m_mins.y;
        if ( v26[1] <= v30 )
          v30 = v26[1];
        m_pNodeInfo->m_mins.y = v30;
        v31 = m_pNodeInfo->m_mins.z;
        if ( v26[2] <= v31 )
          v31 = v26[2];
        m_pNodeInfo->m_mins.z = v31;
      }
      v19 = v33 + 3;
      v33 = v19;
    }
    while ( v19 < m_pNodeInfo->m_Count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA080
// Name: public: void CDispInfo::InitializeActiveVerts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::InitializeActiveVerts(CDispInfo *this)
{
  CBitVec<289> *p_m_ActiveVerts; // ecx
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  const CPowerInfo *m_pPowerInfo; // esi
  int v8; // ecx
  int v9; // edx
  const CPowerInfo *v10; // esi
  int v11; // ecx
  int v12; // edx
  const CPowerInfo *v13; // esi
  int v14; // ecx
  int v15; // edx
  const CPowerInfo *v16; // esi
  int v17; // ecx
  unsigned int *v18; // eax
  CVertIndex nodeIndex; // [esp+0h] [ebp-4h]

  nodeIndex = (CVertIndex)this;
  p_m_ActiveVerts = &this->m_ActiveVerts;
  if ( p_m_ActiveVerts != nullptr )
  {
    p_m_ActiveVerts->m_Ints[0] = 0;
    p_m_ActiveVerts->m_Ints[1] = 0;
    p_m_ActiveVerts->m_Ints[2] = 0;
    p_m_ActiveVerts->m_Ints[3] = 0;
    p_m_ActiveVerts->m_Ints[4] = 0;
    p_m_ActiveVerts->m_Ints[5] = 0;
    p_m_ActiveVerts->m_Ints[6] = 0;
    p_m_ActiveVerts->m_Ints[7] = 0;
    p_m_ActiveVerts->m_Ints[8] = 0;
    p_m_ActiveVerts->m_Ints[9] = 0;
  }
  p_m_ActiveVerts->m_Ints[0] |= 1u;
  v3 = this->m_pPowerInfo->m_SideLength - 1;
  this->m_ActiveVerts.m_Ints[v3 >> 5] |= 1 << (v3 & 0x1F);
  v4 = this->m_pPowerInfo->m_SideLength * this->m_pPowerInfo->m_SideLength - 1;
  this->m_ActiveVerts.m_Ints[v4 >> 5] |= 1 << (v4 & 0x1F);
  v5 = this->m_pPowerInfo->m_SideLength * (this->m_pPowerInfo->m_SideLength - 1);
  this->m_ActiveVerts.m_Ints[v5 >> 5] |= 1 << (v5 & 0x1F);
  v6 = this->m_pPowerInfo->m_RootNode.x + this->m_pPowerInfo->m_SideLength * this->m_pPowerInfo->m_RootNode.y;
  this->m_ActiveVerts.m_Ints[v6 >> 5] |= 1 << (v6 & 0x1F);
  if ( this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_Span != 0
    || this->m_EdgeNeighbors[0].m_SubNeighbors[1].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[0].m_SubNeighbors[1].m_Span != 0 )
  {
    m_pPowerInfo = this->m_pPowerInfo;
    v8 = g_EdgeDims[0];
    *(&nodeIndex.x + SLOWORD(g_EdgeDims[0])) = LOWORD(g_EdgeSideLenMul[0]) * LOWORD(m_pPowerInfo->m_SideLengthM1);
    *(&nodeIndex.x + (v8 == 0)) = m_pPowerInfo->m_MidPoint;
    v9 = nodeIndex.x + m_pPowerInfo->m_SideLength * nodeIndex.y;
    this->m_ActiveVerts.m_Ints[v9 >> 5] |= 1 << ((LOBYTE(nodeIndex.x)
                                                + LOBYTE(m_pPowerInfo->m_SideLength) * LOBYTE(nodeIndex.y))
                                               & 0x1F);
  }
  if ( this->m_EdgeNeighbors[1].m_SubNeighbors[0].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[1].m_SubNeighbors[0].m_Span != 0
    || this->m_EdgeNeighbors[1].m_SubNeighbors[1].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[1].m_SubNeighbors[1].m_Span != 0 )
  {
    v10 = this->m_pPowerInfo;
    v11 = dword_104196CC;
    *(&nodeIndex.x + (__int16)dword_104196CC) = word_10419748 * LOWORD(v10->m_SideLengthM1);
    *(&nodeIndex.x + (v11 == 0)) = v10->m_MidPoint;
    v12 = nodeIndex.x + v10->m_SideLength * nodeIndex.y;
    this->m_ActiveVerts.m_Ints[v12 >> 5] |= 1 << ((LOBYTE(nodeIndex.x) + LOBYTE(v10->m_SideLength) * LOBYTE(nodeIndex.y))
                                                & 0x1F);
  }
  if ( this->m_EdgeNeighbors[2].m_SubNeighbors[0].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[2].m_SubNeighbors[0].m_Span != 0
    || this->m_EdgeNeighbors[2].m_SubNeighbors[1].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[2].m_SubNeighbors[1].m_Span != 0 )
  {
    v13 = this->m_pPowerInfo;
    v14 = dword_104196D0;
    *(&nodeIndex.x + (__int16)dword_104196D0) = word_1041974C * LOWORD(v13->m_SideLengthM1);
    *(&nodeIndex.x + (v14 == 0)) = v13->m_MidPoint;
    v15 = nodeIndex.x + v13->m_SideLength * nodeIndex.y;
    this->m_ActiveVerts.m_Ints[v15 >> 5] |= 1 << ((LOBYTE(nodeIndex.x) + LOBYTE(v13->m_SideLength) * LOBYTE(nodeIndex.y))
                                                & 0x1F);
  }
  if ( this->m_EdgeNeighbors[3].m_SubNeighbors[0].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[3].m_SubNeighbors[0].m_Span != 0
    || this->m_EdgeNeighbors[3].m_SubNeighbors[1].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[3].m_SubNeighbors[1].m_Span != 0 )
  {
    v16 = this->m_pPowerInfo;
    v17 = dword_104196D4;
    *(&nodeIndex.x + (__int16)dword_104196D4) = word_10419750 * LOWORD(v16->m_SideLengthM1);
    *(&nodeIndex.x + (v17 == 0)) = v16->m_MidPoint;
    v18 = &this->m_ActiveVerts.m_Ints[(nodeIndex.x + v16->m_SideLength * nodeIndex.y) >> 5];
    *v18 |= 1 << ((LOBYTE(nodeIndex.x) + LOBYTE(v16->m_SideLength) * LOBYTE(nodeIndex.y)) & 0x1F);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA360
// Name: bool DispInfoRenderDebugModes(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DispInfoRenderDebugModes()
{
  int m_nValue; // eax
  bool result; // al

  result = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
        && (mat_wireframe.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
            m_nValue != 0)
        || mat_luxels.m_pParent != nullptr && mat_luxels.m_pParent->m_Value.m_nValue != 0
        || r_DispWalkable.m_pParent != nullptr && r_DispWalkable.m_pParent->m_Value.m_nValue != 0
        || r_DispBuildable.m_pParent != nullptr && r_DispBuildable.m_pParent->m_Value.m_nValue != 0
        || mat_surfaceid.m_pParent != nullptr && mat_surfaceid.m_pParent->m_Value.m_nValue != 0
        || mat_surfacemat.m_pParent != nullptr && mat_surfacemat.m_pParent->m_Value.m_nValue != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BA3F0
// Name: ProcessLightmapSample
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessLightmapSample(
        const ProcessLightmapSampleData_t *data,
        const Vector *vPos,
        const Vector *vNormal,
        const Vector *vTangentS,
        const Vector *vTangentT,
        int t,
        int s,
        int tmax,
        int smax)
{
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  int v12; // eax
  float v13; // xmm0_4
  float *p_x; // eax

  v9 = (float)((float)((float)(data->m_vLightOrigin.y - vPos->y) * (float)(data->m_vLightOrigin.y - vPos->y))
             + (float)((float)(data->m_vLightOrigin.x - vPos->x) * (float)(data->m_vLightOrigin.x - vPos->x)))
     + (float)((float)(data->m_vLightOrigin.z - vPos->z) * (float)(data->m_vLightOrigin.z - vPos->z));
  if ( data->m_LightDistSqr > v9 )
  {
    if ( v9 == 0.0 )
      v10 = 1.0;
    else
      v10 = data->m_ooQuadraticAttn / v9;
    v11 = (float)(1.0 - (float)(data->m_ooRadiusSq * v9)) * v10;
    if ( v11 > 2.0 )
      v11 = 2.0;
    v12 = s + smax * t;
    v13 = (float)(data->m_Intensity.x * v11) + blocklights[0][v12].x;
    p_x = &blocklights[0][v12].x;
    *p_x = v13;
    p_x[1] = (float)(data->m_Intensity.y * v11) + p_x[1];
    p_x[2] = (float)(data->m_Intensity.z * v11) + p_x[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA4D0
// Name: ProcessLightmapSampleBumped
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessLightmapSampleBumped(
        const ProcessLightmapSampleData_t *data,
        const Vector *vPos,
        const Vector *vNormal,
        const Vector *vTangentS,
        const Vector *vTangentT,
        int t,
        int s,
        int tmax,
        int smax)
{
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float y; // xmm0_4
  float x; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  double z; // st7
  double v20; // st5
  unsigned int v21; // ecx
  double v22; // st5
  double v23; // st5
  double v24; // st7
  double v25; // st5
  double v26; // st4
  double v27; // st3
  double v28; // st2
  double v29; // st6
  double v30; // st2
  double v31; // st3
  double v32; // st2
  double v33; // st6
  double v34; // st2
  double v35; // st6
  double v36; // st7
  Vector vLightVecTangent; // [esp+4h] [ebp-Ch] BYREF
  float scale; // [esp+18h] [ebp+8h]
  float scalea; // [esp+18h] [ebp+8h]
  float distSqr; // [esp+1Ch] [ebp+Ch]

  v10 = data->m_vLightOrigin.x - vPos->x;
  v11 = data->m_vLightOrigin.y - vPos->y;
  v12 = data->m_vLightOrigin.z - vPos->z;
  v13 = (float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v12 * v12);
  distSqr = v13;
  if ( data->m_LightDistSqr > v13 )
  {
    if ( v13 == 0.0 )
      scale = 1.0;
    else
      scale = data->m_ooQuadraticAttn / v13;
    vLightVecTangent.x = v10;
    vLightVecTangent.y = v11;
    vLightVecTangent.z = v12;
    VectorNormalize(vec: &vLightVecTangent);
    y = vLightVecTangent.y;
    x = vLightVecTangent.x;
    v16 = vTangentT->x;
    vLightVecTangent.x = (float)((float)(vTangentS->y * vLightVecTangent.y) + (float)(vTangentS->x * vLightVecTangent.x))
                       + (float)(vTangentS->z * vLightVecTangent.z);
    vLightVecTangent.y = (float)((float)(vTangentT->y * vLightVecTangent.y) + (float)(v16 * x))
                       + (float)(vTangentT->z * vLightVecTangent.z);
    v17 = (float)((float)(vNormal->y * y) + (float)(vNormal->x * x)) + (float)(vNormal->z * vLightVecTangent.z);
    v18 = (float)(1.0 - (float)(data->m_ooRadiusSq * distSqr)) * scale;
    vLightVecTangent.z = v17;
    scalea = v18;
    if ( v18 > 2.0 )
      scalea = 2.0;
    z = vLightVecTangent.z;
    v20 = 0.0;
    if ( vLightVecTangent.z > 0.0 )
      v20 = vLightVecTangent.z;
    v21 = 4 * (s + smax * t);
    v22 = v20 * scalea;
    blocklights[0][v21 / 4].x = data->m_Intensity.x * v22 + blocklights[0][v21 / 4].x;
    *(float *)&dword_104F1D84[v21] = v22 * data->m_Intensity.y + *(float *)&dword_104F1D84[v21];
    *(float *)&dword_104F1D88[v21] = v22 * data->m_Intensity.z + *(float *)&dword_104F1D88[v21];
    v23 = z;
    v24 = scalea;
    v25 = v23 * 0.57735026;
    v26 = vLightVecTangent.y;
    v27 = vLightVecTangent.x;
    v28 = 0.0;
    v29 = 0.0 * vLightVecTangent.y + 0.81649661 * vLightVecTangent.x + v25;
    if ( v29 > 0.0 )
      v28 = v29;
    v30 = v28 * v24;
    flt_10531D80[v21] = data->m_Intensity.x * v30 + flt_10531D80[v21];
    flt_10531D84[v21] = v30 * data->m_Intensity.y + flt_10531D84[v21];
    flt_10531D88[v21] = v30 * data->m_Intensity.z + flt_10531D88[v21];
    v31 = v27 * -0.40824822;
    v32 = 0.0;
    v33 = v26 * 0.70710677 + v31 + v25;
    if ( v33 > 0.0 )
      v32 = v33;
    v34 = v32 * v24;
    flt_10571D80[v21] = data->m_Intensity.x * v34 + flt_10571D80[v21];
    flt_10571D84[v21] = v34 * data->m_Intensity.y + flt_10571D84[v21];
    flt_10571D88[v21] = v34 * data->m_Intensity.z + flt_10571D88[v21];
    v35 = v25 + v31 - v26 * 0.70710677;
    if ( v35 <= 0.0 )
      v35 = 0.0;
    v36 = v24 * v35;
    *(float *)&dword_105B1D80[v21] = data->m_Intensity.x * v36 + *(float *)&dword_105B1D80[v21];
    *(float *)&dword_105B1D84[v21] = v36 * data->m_Intensity.y + *(float *)&dword_105B1D84[v21];
    *(float *)&dword_105B1D88[v21] = v36 * data->m_Intensity.z + *(float *)&dword_105B1D88[v21];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA7A0
// Name: ProcessLightmapSampleAlpha
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessLightmapSampleAlpha(
        const ProcessLightmapSampleData_t *data,
        const Vector *vPos,
        const Vector *vNormal,
        const Vector *vTangentS,
        const Vector *vTangentT,
        int t,
        int s,
        int tmax,
        int smax)
{
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4

  v9 = (float)((float)((float)(data->m_vLightOrigin.y - vPos->y) * (float)(data->m_vLightOrigin.y - vPos->y))
             + (float)((float)(data->m_vLightOrigin.x - vPos->x) * (float)(data->m_vLightOrigin.x - vPos->x)))
     + (float)((float)(data->m_vLightOrigin.z - vPos->z) * (float)(data->m_vLightOrigin.z - vPos->z));
  if ( data->m_LightDistSqr > v9 )
  {
    if ( v9 == 0.0 )
      v10 = 1.0;
    else
      v10 = data->m_ooQuadraticAttn / v9;
    v11 = (float)(1.0 - (float)(data->m_ooRadiusSq * v9)) * v10;
    if ( v11 > 1.0 )
      v11 = 1.0;
    dword_104F1D8C[4 * s + 4 * smax * t] = (float)(data->m_Intensity.x * v11) + dword_104F1D8C[4 * s + 4 * smax * t];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA850
// Name: public: virtual bool CDispInfo::TestRay(struct Ray_t const __near &,float,float,float __near &,class Vector2D __near *,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDispInfo::TestRay@<al>(
        CDispInfo *this@<ecx>,
        float a2@<ebp>,
        const Ray_t *ray,
        float start,
        float end,
        float *dist,
        Vector2D *luv,
        Vector2D *tuv)
{
  int v9; // eax
  CDispCollTree *CollisionTree; // ecx
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  _DWORD v17[3]; // [esp-Ch] [ebp-7Ch] BYREF
  Ray_t shortenedRay; // [esp+0h] [ebp-70h] BYREF
  _BYTE v19[12]; // [esp+50h] [ebp-20h] BYREF
  RayDispOutput_t output; // [esp+5Ch] [ebp-14h]
  float retaddr; // [esp+70h] [ebp+0h]

  output.u = a2;
  output.v = retaddr;
  v9 = DispInfo_ComputeIndex(hArray: host_state.worldbrush->hDispInfos, pInfo: this);
  CollisionTree = CollisionBSPData_GetCollisionTree(i: v9);
  if ( CollisionTree == nullptr )
    return 0;
  v11 = (float)(ray->m_Delta.x * start) + ray->m_Start.x;
  v12 = (float)(ray->m_Delta.y * start) + ray->m_Start.y;
  v13 = (float)(ray->m_Delta.z * start) + ray->m_Start.z;
  v14 = (float)(ray->m_Delta.z * end) + ray->m_Start.z;
  v15 = (float)((float)(ray->m_Delta.x * end) + ray->m_Start.x) - v11;
  shortenedRay.m_Start.z = (float)((float)(ray->m_Delta.y * end) + ray->m_Start.y) - v12;
  shortenedRay.m_Start.y = v15;
  shortenedRay.m_Start.w = v14 - v13;
  BYTE1(shortenedRay.m_Extents.z) = (float)((float)((float)(shortenedRay.m_Start.z * shortenedRay.m_Start.z)
                                                  + (float)(v15 * v15))
                                          + (float)(shortenedRay.m_Start.w * shortenedRay.m_Start.w)) != 0.0;
  shortenedRay.m_Extents.y = 0.0;
  memset(&shortenedRay.m_StartOffset.y, 0, 12);
  memset(&shortenedRay.m_Delta.y, 0, 12);
  LOBYTE(shortenedRay.m_Extents.z) = 1;
  *(float *)v17 = v11;
  *(float *)&v17[1] = v12;
  *(float *)&v17[2] = v13;
  *(_DWORD *)&output.ndxVerts[2] = 1065353216;
  if ( CDispCollTree::AABBTree_Ray(this: CollisionTree, ray: (const Ray_t *)v17, output: (RayDispOutput_t *)v19) == 0 )
    return 0;
  *dist = (float)((float)(1.0 - *(float *)&output.ndxVerts[2]) * start) + (float)(*(float *)&output.ndxVerts[2] * end);
  this->ComputeLightmapAndTextureCoordinate(this, a2: (const RayDispOutput_t *)v19, a3: luv, a4: tuv);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BA9D0
// Name: public: void CDispInfo::UpdateBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::UpdateBoundingBox(CDispInfo *this)
{
  const CPowerInfo *m_pPowerInfo; // edi
  int v2; // esi
  double x; // st7
  float *v4; // edx
  double y; // st7
  double z; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7

  this->m_BBoxMin.x = 1.0e24;
  this->m_BBoxMin.y = 1.0e24;
  this->m_BBoxMin.z = 1.0e24;
  m_pPowerInfo = this->m_pPowerInfo;
  v2 = 0;
  this->m_BBoxMax.x = -1.0e24;
  this->m_BBoxMax.y = -1.0e24;
  for ( this->m_BBoxMax.z = -1.0e24; v2 < m_pPowerInfo->m_MaxVerts; this->m_BBoxMax.z = v9 )
  {
    x = this->m_BBoxMin.x;
    v4 = (float *)((char *)this->m_MeshReader.m_pPosition + v2 * this->m_MeshReader.m_VertexSize_Position);
    if ( *v4 <= x )
      x = *v4;
    this->m_BBoxMin.x = x;
    y = this->m_BBoxMin.y;
    if ( v4[1] <= y )
      y = v4[1];
    this->m_BBoxMin.y = y;
    z = this->m_BBoxMin.z;
    if ( v4[2] <= z )
      z = v4[2];
    this->m_BBoxMin.z = z;
    v7 = this->m_BBoxMax.x;
    if ( *v4 >= v7 )
      v7 = *v4;
    this->m_BBoxMax.x = v7;
    v8 = this->m_BBoxMax.y;
    if ( v4[1] >= v8 )
      v8 = v4[1];
    this->m_BBoxMax.y = v8;
    v9 = this->m_BBoxMax.z;
    if ( v4[2] >= v9 )
      v9 = v4[2];
    ++v2;
  }
  CDispInfo::UpdateNodeBoundingBoxes(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BAAA0
// Name: private: void CDispInfo::TestAddDecalTri(int,unsigned short,class CDispDecal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::TestAddDecalTri(
        CDispInfo *this,
        int iIndexStart,
        unsigned __int16 decalHandle,
        decal_t *pDispDecal)
{
  unsigned __int16 *m_pIndices; // ecx
  unsigned int m_nIndexSize; // eax
  __int16 m_iVertOffset; // di
  int m_VertexSize_Position; // ecx
  float *v10; // edi
  float *v11; // eax
  float *v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  int v19; // ecx
  float *m_pPosition; // edi
  float v21; // xmm5_4
  int v22; // edi
  float *v23; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  decal_t *x_low; // eax
  float v27; // xmm0_4
  float v28; // xmm1_4
  float *v29; // eax
  float v30; // xmm5_4
  float *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm1_4
  decal_t *v34; // eax
  float v35; // xmm1_4
  float *v36; // edi
  float v37; // xmm0_4
  float v38; // xmm1_4
  CDecalVert *v39; // edi
  int clippedVertCount; // eax
  CDispDecalFragment *DispDecalFragment; // eax
  int v42; // ebx
  int v43; // ecx
  int v44; // edx
  unsigned int v45; // ebx
  float *p_y; // ecx
  CDecalVert *m_pVerts; // edi
  char *v48; // edx
  float *v49; // edi
  float *v50; // edi
  float *v51; // edi
  float *v52; // edi
  float *v53; // edi
  float *v54; // edi
  float *v55; // edi
  float *v56; // edi
  float *v57; // edi
  float *v58; // edi
  float *v59; // edx
  double v60; // st7
  int v61; // edx
  int v62; // ecx
  int v63; // ebx
  int v64; // edi
  CDecalVert *v65; // edx
  float *v66; // edx
  float *v67; // edx
  CDecalVert verts[3]; // [esp+Ch] [ebp-80h] BYREF
  Vector vNormal; // [esp+6Ch] [ebp-20h] BYREF
  unsigned __int16 tempIndices[4]; // [esp+78h] [ebp-14h]
  int v71; // [esp+80h] [ebp-Ch]
  int v72; // [esp+84h] [ebp-8h]
  int i; // [esp+88h] [ebp-4h]
  int outCount; // [esp+94h] [ebp+8h]
  int outCounta; // [esp+94h] [ebp+8h]
  int iVert; // [esp+98h] [ebp+Ch]
  decal_t *pDecal; // [esp+9Ch] [ebp+10h]

  m_pIndices = this->m_MeshReader.m_pIndices;
  pDecal = (decal_t *)LODWORD(pDispDecal->position.x);
  m_nIndexSize = this->m_MeshReader.m_nIndexSize;
  m_iVertOffset = this->m_iVertOffset;
  tempIndices[0] = m_pIndices[iIndexStart * m_nIndexSize] - m_iVertOffset;
  tempIndices[1] = m_pIndices[m_nIndexSize * (iIndexStart + 1)] - m_iVertOffset;
  tempIndices[2] = m_pIndices[m_nIndexSize * (iIndexStart + 2)] - m_iVertOffset;
  m_VertexSize_Position = this->m_MeshReader.m_VertexSize_Position;
  v10 = (float *)((char *)this->m_MeshReader.m_pPosition + tempIndices[0] * m_VertexSize_Position);
  i = tempIndices[0];
  v11 = (float *)((char *)this->m_MeshReader.m_pPosition + tempIndices[1] * m_VertexSize_Position);
  outCount = tempIndices[1];
  v12 = (float *)((char *)this->m_MeshReader.m_pPosition + tempIndices[2] * m_VertexSize_Position);
  v13 = v11[1] - v10[1];
  v14 = v12[1] - v10[1];
  v15 = v11[2] - v10[2];
  v16 = v12[2] - v10[2];
  v17 = *v11 - *v10;
  v18 = *v12 - *v10;
  v72 = tempIndices[2];
  vNormal.x = (float)(v14 * v15) - (float)(v13 * v16);
  vNormal.y = (float)(v16 * v17) - (float)(v15 * v18);
  vNormal.z = (float)(v13 * v18) - (float)(v14 * v17);
  VectorNormalize(vec: &vNormal);
  if ( (float)((float)((float)((float)(pDecal->position.y - v10[1]) * vNormal.y)
                     + (float)((float)(pDecal->position.x - *v10) * vNormal.x))
             + (float)((float)(pDecal->position.z - v10[2]) * vNormal.z)) < *(float *)&pDispDecal->color )
  {
    v19 = this->m_MeshReader.m_VertexSize_Position;
    m_pPosition = this->m_MeshReader.m_pPosition;
    verts[0].m_vPos.x = *(float *)((char *)m_pPosition + i * v19);
    verts[0].m_vPos.y = *(float *)((char *)m_pPosition + i * v19 + 4);
    v21 = *(float *)((char *)m_pPosition + i * v19 + 8);
    v22 = this->m_MeshReader.m_VertexSize_TexCoord[1];
    v23 = (float *)((char *)this->m_MeshReader.m_pTexCoord[1] + i * v22);
    verts[0].m_vPos.z = v21;
    v24 = v23[1];
    verts[0].m_cLMCoords.x = *v23;
    v25 = pDispDecal->saxis.x * verts[0].m_vPos.x;
    x_low = (decal_t *)LODWORD(pDispDecal->position.x);
    verts[0].m_cLMCoords.y = v24;
    v27 = (float)((float)((float)(pDispDecal->saxis.y * verts[0].m_vPos.y) + v25) + (float)(pDispDecal->saxis.z * v21))
        - x_low->dx;
    v28 = (float)((float)((float)(pDispDecal->dy * verts[0].m_vPos.y) + (float)(pDispDecal->dx * verts[0].m_vPos.x))
                + (float)(pDispDecal->scale * v21))
        - x_low->dy;
    v29 = (float *)((char *)this->m_MeshReader.m_pPosition + outCount * v19);
    verts[0].m_ctCoords.y = v28 + 0.5;
    verts[0].m_ctCoords.x = v27 + 0.5;
    verts[1].m_vPos.x = *v29;
    verts[1].m_vPos.y = v29[1];
    v30 = v29[2];
    v31 = (float *)((char *)this->m_MeshReader.m_pTexCoord[1] + outCount * v22);
    verts[1].m_vPos.z = v30;
    v32 = v31[1];
    v33 = *v31;
    v34 = (decal_t *)LODWORD(pDispDecal->position.x);
    verts[1].m_cLMCoords.x = v33;
    verts[1].m_cLMCoords.y = v32;
    v35 = (float)((float)((float)((float)(pDispDecal->dy * verts[1].m_vPos.y)
                                + (float)(verts[1].m_vPos.x * pDispDecal->dx))
                        + (float)(pDispDecal->scale * v30))
                - v34->dy)
        + 0.5;
    verts[1].m_ctCoords.x = (float)((float)((float)((float)(pDispDecal->saxis.y * verts[1].m_vPos.y)
                                                  + (float)(verts[1].m_vPos.x * pDispDecal->saxis.x))
                                          + (float)(pDispDecal->saxis.z * v30))
                                  - v34->dx)
                          + 0.5;
    verts[1].m_ctCoords.y = v35;
    v36 = (float *)((char *)this->m_MeshReader.m_pTexCoord[1] + v72 * v22);
    verts[2].m_vPos = *(Vector *)((char *)this->m_MeshReader.m_pPosition + v72 * v19);
    v37 = v36[1];
    verts[2].m_cLMCoords.x = *v36;
    verts[2].m_cLMCoords.y = v37;
    v38 = (float)((float)((float)((float)(pDispDecal->dy * verts[2].m_vPos.y)
                                + (float)(verts[2].m_vPos.x * pDispDecal->dx))
                        + (float)(pDispDecal->scale * verts[2].m_vPos.z))
                - v34->dy)
        + 0.5;
    verts[2].m_ctCoords.x = (float)((float)((float)((float)(pDispDecal->saxis.y * verts[2].m_vPos.y)
                                                  + (float)(verts[2].m_vPos.x * pDispDecal->saxis.x))
                                          + (float)(pDispDecal->saxis.z * verts[2].m_vPos.z))
                                  - v34->dx)
                          + 0.5;
    verts[2].m_ctCoords.y = v38;
    v39 = R_DoDecalSHClip(pInVerts: verts, pOutVerts: nullptr, pDecal, nStartVerts: 3, vecNormal: &vec3_origin);
    clippedVertCount = pDecal->clippedVertCount;
    *(_DWORD *)tempIndices = v39;
    outCounta = clippedVertCount;
    if ( (unsigned int)clippedVertCount > 2 )
    {
      if ( clippedVertCount >= 6 )
      {
        outCounta = 6;
        clippedVertCount = 6;
      }
      DispDecalFragment = CDispInfo::AllocateDispDecalFragment(this, h: decalHandle, nVerts: clippedVertCount);
      v42 = outCounta;
      v43 = 0;
      iVert = 0;
      if ( outCounta >= 4 )
      {
        v72 = 36 - (_DWORD)v39;
        v71 = 68 - (_DWORD)v39;
        v44 = -28 - (_DWORD)v39;
        v45 = ((unsigned int)(outCounta - 4) >> 2) + 1;
        p_y = &v39->m_cLMCoords.y;
        i = -28 - (_DWORD)v39;
        iVert = 4 * v45;
        while ( 1 )
        {
          m_pVerts = DispDecalFragment->m_pVerts;
          v48 = (char *)p_y + v44;
          *(float *)&v48[(_DWORD)m_pVerts] = *(p_y - 7);
          *(float *)&v48[(_DWORD)m_pVerts + 4] = *(p_y - 6);
          *(float *)&v48[(_DWORD)m_pVerts + 8] = *(p_y - 5);
          v49 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 16];
          *v49 = *(p_y - 3);
          v49[1] = *(p_y - 2);
          v50 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 24];
          *v50 = *(p_y - 1);
          v50[1] = *p_y;
          v51 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 32];
          *v51 = p_y[1];
          v51[1] = p_y[2];
          v51[2] = p_y[3];
          v52 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 48];
          *v52 = p_y[5];
          v52[1] = p_y[6];
          v53 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 56];
          *v53 = p_y[7];
          v53[1] = p_y[8];
          v54 = (float *)((char *)&DispDecalFragment->m_pVerts->m_vPos.x + (unsigned int)p_y + v72);
          *v54 = p_y[9];
          v54[1] = p_y[10];
          v54[2] = p_y[11];
          v55 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 80];
          *v55 = p_y[13];
          v55[1] = p_y[14];
          v56 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 88];
          *v56 = p_y[15];
          v56[1] = p_y[16];
          v57 = (float *)((char *)&DispDecalFragment->m_pVerts->m_vPos.x + (unsigned int)p_y + v71);
          *v57 = p_y[17];
          v57[1] = p_y[18];
          v57[2] = p_y[19];
          v58 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 112];
          *v58 = p_y[21];
          v58[1] = p_y[22];
          v59 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 120];
          *v59 = p_y[23];
          v60 = p_y[24];
          p_y += 32;
          v59[1] = v60;
          if ( --v45 == 0 )
            break;
          v44 = i;
        }
        v39 = *(CDecalVert **)tempIndices;
        v42 = outCounta;
        v43 = iVert;
      }
      if ( v43 < v42 )
      {
        v61 = -28 - (_DWORD)v39;
        v62 = (int)&v39[v43].m_cLMCoords.y;
        v63 = v42 - iVert;
        for ( i = -28 - (_DWORD)v39; ; v61 = i )
        {
          v64 = v62 + v61;
          v65 = DispDecalFragment->m_pVerts;
          *(float *)((char *)&v65->m_vPos.x + v64) = *(float *)(v62 - 28);
          v62 += 32;
          --v63;
          *(float *)((char *)&v65->m_vPos.y + v64) = *(float *)(v62 - 56);
          *(float *)((char *)&v65->m_vPos.z + v64) = *(float *)(v62 - 52);
          v66 = (float *)((char *)&DispDecalFragment->m_pVerts->m_ctCoords.x + v64);
          *v66 = *(float *)(v62 - 44);
          v66[1] = *(float *)(v62 - 40);
          v67 = (float *)((char *)&DispDecalFragment->m_pVerts->m_cLMCoords.x + v64);
          *v67 = *(float *)(v62 - 36);
          v67[1] = *(float *)(v62 - 32);
          if ( v63 == 0 )
            break;
        }
        LOBYTE(v42) = outCounta;
      }
      DispDecalFragment->m_pDecal = pDecal;
      DispDecalFragment->m_nVerts = v42;
      HIWORD(pDispDecal->material) += (unsigned __int8)v42;
      LOWORD(pDispDecal->lightmapOffset) += DispDecalFragment->m_nVerts - 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB030
// Name: private: void CDispInfo::TestAddDecalTri(int,unsigned short,class CDispShadowDecal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::TestAddDecalTri(
        CDispInfo *this,
        ShadowVertex_t **iIndexStart,
        unsigned __int16 decalHandle,
        CDispShadowDecal *pDecal)
{
  unsigned int m_nIndexSize; // eax
  unsigned __int16 *m_pIndices; // ecx
  __int16 m_iVertOffset; // dx
  unsigned __int16 v8; // di
  unsigned __int16 v9; // bx
  int v10; // ecx
  float *m_pNormal; // edi
  unsigned __int16 v12; // bx
  int m_VertexSize_Normal; // edx
  float v14; // xmm2_4
  float v15; // xmm3_4
  float *v16; // eax
  float v17; // xmm1_4
  float *v18; // ecx
  int v19; // eax
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  int v23; // eax
  float *v24; // ecx
  float v25; // xmm2_4
  float v26; // xmm3_4
  CDispShadowDecal *v27; // ebx
  float v28; // xmm0_4
  int m_Shadow; // edx
  int v30; // eax
  int v31; // edi
  CDispShadowFragment *ShadowDecalFragment; // eax
  int v33; // ecx
  int v34; // edx
  ShadowVertex_t *m_ShadowVerts; // esi
  float *p_x; // edi
  float *v37; // edi
  float *v38; // esi
  float *v39; // edi
  float *v40; // esi
  float *v41; // edi
  float *v42; // esi
  float *v43; // edi
  float *v44; // esi
  float *v45; // edi
  float *v46; // esi
  ShadowVertex_t *v47; // esi
  float *v48; // edi
  float *v49; // edi
  float *v50; // esi
  double v51; // st7
  int v52; // esi
  int v53; // ebx
  ShadowVertex_t *v54; // edx
  float *v55; // esi
  float *v56; // esi
  float *v57; // edx
  ShadowClipState_t clip; // [esp+Ch] [ebp-644h] BYREF
  Vector vPositions[3]; // [esp+618h] [ebp-38h] BYREF
  Vector *ppPosition[3]; // [esp+63Ch] [ebp-14h] BYREF
  int count; // [esp+648h] [ebp-8h]

  m_nIndexSize = this->m_MeshReader.m_nIndexSize;
  m_pIndices = this->m_MeshReader.m_pIndices;
  m_iVertOffset = this->m_iVertOffset;
  v8 = m_pIndices[(_DWORD)iIndexStart * m_nIndexSize];
  HIWORD(count) = m_pIndices[m_nIndexSize * ((_DWORD)iIndexStart + 1)] - m_iVertOffset;
  v9 = m_pIndices[m_nIndexSize * ((_DWORD)iIndexStart + 2)];
  v10 = (unsigned __int16)(v8 - m_iVertOffset);
  m_pNormal = this->m_MeshReader.m_pNormal;
  v12 = v9 - m_iVertOffset;
  m_VertexSize_Normal = this->m_MeshReader.m_VertexSize_Normal;
  v14 = *(float *)((char *)m_pNormal + m_VertexSize_Normal * v10 + 4);
  v15 = *(float *)((char *)m_pNormal + m_VertexSize_Normal * v10 + 8);
  v16 = (float *)((char *)this->m_MeshReader.m_pPosition + v10 * this->m_MeshReader.m_VertexSize_Position);
  vPositions[0].x = *v16 + (float)(*(float *)((char *)m_pNormal + m_VertexSize_Normal * v10) * 0.1);
  vPositions[0].y = v16[1] + (float)(v14 * 0.1);
  v17 = v16[2];
  v18 = (float *)((char *)this->m_MeshReader.m_pPosition + this->m_MeshReader.m_VertexSize_Position * HIWORD(count));
  v19 = m_VertexSize_Normal * HIWORD(count);
  vPositions[0].z = v17 + (float)(v15 * 0.1);
  v20 = *(float *)((char *)m_pNormal + v19 + 4);
  v21 = *(float *)((char *)m_pNormal + v19 + 8);
  vPositions[1].x = (float)(*(float *)((char *)m_pNormal + v19) * 0.1) + *v18;
  vPositions[1].y = v18[1] + (float)(v20 * 0.1);
  v22 = v18[2];
  v23 = m_VertexSize_Normal * v12;
  v24 = (float *)((char *)this->m_MeshReader.m_pPosition + this->m_MeshReader.m_VertexSize_Position * v12);
  vPositions[1].z = v22 + (float)(v21 * 0.1);
  v25 = *(float *)((char *)m_pNormal + v23 + 4) * 0.1;
  v26 = *(float *)((char *)m_pNormal + v23 + 8) * 0.1;
  vPositions[2].x = *v24 + (float)(*(float *)((char *)m_pNormal + v23) * 0.1);
  v27 = pDecal;
  vPositions[2].y = v24[1] + v25;
  v28 = v24[2];
  ppPosition[2] = &vPositions[2];
  m_Shadow = pDecal->m_Shadow;
  ppPosition[1] = &vPositions[1];
  ppPosition[0] = vPositions;
  vPositions[2].z = v28 + v26;
  v30 = g_pShadowMgr->ProjectAndClipVerticesEx(
          this: g_pShadowMgr,
          a2: m_Shadow,
          a3: 3,
          a4: ppPosition,
          a5: &iIndexStart,
          a6: &clip);
  v31 = v30;
  count = v30;
  if ( v30 >= 3 )
  {
    ShadowDecalFragment = CDispInfo::AllocateShadowDecalFragment(this, h: decalHandle, nCount: v30);
    v33 = 0;
    ShadowDecalFragment->m_nVerts = v31;
    if ( v31 >= 4 )
    {
      v34 = 0;
      do
      {
        m_ShadowVerts = ShadowDecalFragment->m_ShadowVerts;
        p_x = &iIndexStart[v33]->m_Position.x;
        v33 += 4;
        m_ShadowVerts[v34].m_Position.x = *p_x;
        m_ShadowVerts[v34].m_Position.y = p_x[1];
        m_ShadowVerts[v34].m_Position.z = p_x[2];
        v37 = &ShadowDecalFragment->m_ShadowVerts[v34].m_ShadowSpaceTexCoord.x;
        v38 = &iIndexStart[v33 - 4]->m_Position.x;
        *v37 = v38[3];
        v37[1] = v38[4];
        v37[2] = v38[5];
        v39 = &iIndexStart[v33 - 3]->m_Position.x;
        v40 = &ShadowDecalFragment->m_ShadowVerts[v34 + 1].m_Position.x;
        *v40 = *v39;
        v40[1] = v39[1];
        v40[2] = v39[2];
        v41 = &ShadowDecalFragment->m_ShadowVerts[v34 + 1].m_ShadowSpaceTexCoord.x;
        v42 = &iIndexStart[v33 - 3]->m_Position.x;
        *v41 = v42[3];
        v41[1] = v42[4];
        v41[2] = v42[5];
        v43 = &iIndexStart[v33 - 2]->m_Position.x;
        v44 = &ShadowDecalFragment->m_ShadowVerts[v34 + 2].m_Position.x;
        *v44 = *v43;
        v44[1] = v43[1];
        v44[2] = v43[2];
        v45 = &ShadowDecalFragment->m_ShadowVerts[v34 + 2].m_ShadowSpaceTexCoord.x;
        v46 = &iIndexStart[v33 - 2]->m_Position.x;
        *v45 = v46[3];
        v45[1] = v46[4];
        v45[2] = v46[5];
        v47 = ShadowDecalFragment->m_ShadowVerts;
        v48 = &iIndexStart[v33 - 1]->m_Position.x;
        v47[v34 + 3].m_Position.x = *v48;
        v47[v34 + 3].m_Position.y = v48[1];
        v47[v34 + 3].m_Position.z = v48[2];
        v49 = &ShadowDecalFragment->m_ShadowVerts[v34 + 3].m_ShadowSpaceTexCoord.x;
        v50 = &iIndexStart[v33 - 1]->m_Position.x;
        v34 += 4;
        *v49 = v50[3];
        v49[1] = v50[4];
        v51 = v50[5];
        v52 = count;
        v49[2] = v51;
      }
      while ( v33 < v52 - 3 );
      v31 = count;
    }
    if ( v33 < v31 )
    {
      v53 = v33;
      do
      {
        v54 = ShadowDecalFragment->m_ShadowVerts;
        v55 = &iIndexStart[v33++]->m_Position.x;
        v54[v53].m_Position.x = *v55;
        v54[v53].m_Position.y = v55[1];
        v54[v53].m_Position.z = v55[2];
        v56 = &ShadowDecalFragment->m_ShadowVerts[v53].m_ShadowSpaceTexCoord.x;
        v57 = &iIndexStart[v33 - 1]->m_Position.x;
        ++v53;
        *v56 = v57[3];
        v56[1] = v57[4];
        v56[2] = v57[5];
      }
      while ( v33 < v31 );
      v27 = pDecal;
    }
    v27->m_nVerts += LOWORD(ShadowDecalFragment->m_nVerts);
    v27->m_nTris += LOWORD(ShadowDecalFragment->m_nVerts) - 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB380
// Name: public: void CDispInfo::SpecifyDynamicMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SpecifyDynamicMesh(CDispInfo *this)
{
  IMatRenderContext *v2; // ebx
  IMesh *v3; // edi
  int v4; // edi
  CDispRenderVert *m_pMemory; // eax
  float *m_pCurrPosition; // ecx
  float *p_x; // eax
  float *v8; // ecx
  float *v9; // ecx
  float *v10; // ecx
  float *m_pCurrNormal; // edx
  float *v12; // ecx
  float *v13; // ecx
  float *v14; // eax
  int v15; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder builder; // [esp+8h] [ebp-1F0h] BYREF
  int m_MaxVerts; // [esp+1F4h] [ebp-4h]

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = v2->GetDynamicMesh(this: v2, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &builder);
  CMeshBuilder::Begin(
    this: &builder,
    pMesh: v3,
    type: MATERIAL_TRIANGLES,
    nVertexCount: this->m_pPowerInfo->m_MaxVerts,
    nIndexCount: this->m_nIndices,
    pMeshSettings: nullptr);
  if ( this->m_pPowerInfo->m_MaxVerts > 0 )
  {
    v4 = 0;
    m_MaxVerts = this->m_pPowerInfo->m_MaxVerts;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
      *builder.m_VertexBuilder.m_pCurrPosition = m_pMemory[v4].m_vPos.x;
      p_x = &m_pMemory[v4].m_vPos.x;
      m_pCurrPosition[1] = p_x[1];
      m_pCurrPosition[2] = p_x[2];
      v8 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
      *builder.m_VertexBuilder.m_pCurrTexCoord[0] = p_x[12];
      v8[1] = p_x[13];
      v9 = builder.m_VertexBuilder.m_pCurrTexCoord[1];
      *builder.m_VertexBuilder.m_pCurrTexCoord[1] = p_x[14];
      v9[1] = p_x[15];
      v10 = builder.m_VertexBuilder.m_pCurrTexCoord[2];
      *builder.m_VertexBuilder.m_pCurrTexCoord[2] = this->m_BumpSTexCoordOffset;
      v10[1] = 0.0;
      m_pCurrNormal = builder.m_VertexBuilder.m_pCurrNormal;
      *builder.m_VertexBuilder.m_pCurrNormal = p_x[3];
      m_pCurrNormal[1] = p_x[4];
      m_pCurrNormal[2] = p_x[5];
      v12 = (float *)((char *)builder.m_VertexBuilder.m_pTangentS
                    + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentS);
      *v12 = p_x[6];
      v12[1] = p_x[7];
      v12[2] = p_x[8];
      v13 = p_x + 9;
      v14 = (float *)((char *)builder.m_VertexBuilder.m_pTangentT
                    + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentT);
      *v14 = *v13;
      v14[1] = v13[1];
      v14[2] = v13[2];
      CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
      ++v4;
      --m_MaxVerts;
    }
    while ( m_MaxVerts != 0 );
  }
  v15 = 0;
  if ( this->m_nIndices > 0 )
  {
    m_nCurrentIndex = builder.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      builder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                         + this->m_Indices.m_Memory.m_pMemory[v15]
                                                         - LOWORD(this->m_iVertOffset);
      m_nCurrentIndex = builder.m_IndexBuilder.m_nIndexSize + builder.m_IndexBuilder.m_nCurrentIndex;
      builder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
      if ( m_nCurrentIndex > builder.m_IndexBuilder.m_nIndexCount )
        builder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v15;
    }
    while ( v15 < this->m_nIndices );
  }
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  builder.m_pMesh->UnlockMesh(
    this: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount,
    a4: &builder);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
  builder.m_pMesh = nullptr;
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100BB630
// Name: public: void CDispInfo::SpecifyWalkableDynamicMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SpecifyWalkableDynamicMesh(CDispInfo *this)
{
  IMatRenderContext *v2; // edi
  IMesh *v3; // ebx
  int m_MaxVerts; // ebx
  int v5; // edi
  CDispRenderVert *m_pMemory; // eax
  float *m_pCurrPosition; // ecx
  int v8; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder v11; // [esp+18h] [ebp-1ECh] BYREF
  IMatRenderContext *v12; // [esp+200h] [ebp-4h]

  v2 = materials->GetRenderContext(this: materials);
  v12 = v2;
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = v2->GetDynamicMesh(this: v2, a2: false, a3: nullptr, a4: nullptr, a5: g_materialTranslucentSingleColor);
  ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))g_materialTranslucentSingleColor->ColorModulate)(
    a1: g_materialTranslucentSingleColor,
    a2: 1.0,
    a3: 1.0,
    a4: 0.0);
  ((void (__stdcall *)(_DWORD))g_materialTranslucentSingleColor->AlphaModulate)(a1: 0.33000001);
  CMeshBuilder::CMeshBuilder(this: &v11);
  CMeshBuilder::Begin(
    this: &v11,
    pMesh: v3,
    type: MATERIAL_TRIANGLES,
    nVertexCount: this->m_pPowerInfo->m_MaxVerts,
    nIndexCount: this->m_nWalkIndexCount,
    pMeshSettings: nullptr);
  m_MaxVerts = this->m_pPowerInfo->m_MaxVerts;
  if ( m_MaxVerts > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pCurrPosition = v11.m_VertexBuilder.m_pCurrPosition;
      *v11.m_VertexBuilder.m_pCurrPosition = m_pMemory[v5].m_vPos.x;
      m_pCurrPosition[1] = m_pMemory[v5].m_vPos.y;
      m_pCurrPosition[2] = m_pMemory[v5].m_vPos.z;
      CVertexBuilder::AdvanceVertex(this: &v11.m_VertexBuilder);
      ++v5;
      --m_MaxVerts;
    }
    while ( m_MaxVerts != 0 );
    v2 = v12;
  }
  v8 = 0;
  if ( this->m_nWalkIndexCount > 0 )
  {
    m_nCurrentIndex = v11.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      v11.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(v11.m_IndexBuilder.m_nIndexOffset)
                                                     + this->m_pWalkIndices[v8];
      m_nCurrentIndex = v11.m_IndexBuilder.m_nIndexSize + v11.m_IndexBuilder.m_nCurrentIndex;
      v11.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
      if ( m_nCurrentIndex > v11.m_IndexBuilder.m_nIndexCount )
        v11.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v8;
    }
    while ( v8 < this->m_nWalkIndexCount );
  }
  if ( v11.m_bGenerateIndices )
  {
    switch ( v11.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * v11.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * v11.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * v11.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * v11.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = v11.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(this: &v11.m_IndexBuilder, primitiveType: v11.m_Type, nIndexCount: m_nVertexCount);
  }
  v11.m_pMesh->UnlockMesh(
    this: v11.m_pMesh,
    a2: v11.m_VertexBuilder.m_nVertexCount,
    a3: v11.m_IndexBuilder.m_nIndexCount,
    a4: &v11);
  v11.m_IndexBuilder.m_pIndexBuffer = nullptr;
  v11.m_IndexBuilder.m_nMaxIndexCount = 0;
  v11.m_VertexBuilder.m_nMaxVertexCount = 0;
  v11.m_VertexBuilder.m_pVertexBuffer = nullptr;
  v11.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  v11.m_pMesh->Draw_2(this: v11.m_pMesh, a2: -1, a3: 0);
  v11.m_pMesh = nullptr;
  if ( v11.m_VertexBuilder.m_pVertexBuffer != nullptr
    && v11.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v11.m_VertexBuilder.m_pVertexBuffer) )
  {
    v11.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v11.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( v11.m_IndexBuilder.m_pIndexBuffer != nullptr
    && v11.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v11.m_IndexBuilder.m_pIndexBuffer) )
  {
    v11.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v11.m_IndexBuilder.m_pIndexBuffer);
  }
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100BB8A0
// Name: public: void CDispInfo::SpecifyBuildableDynamicMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SpecifyBuildableDynamicMesh(CDispInfo *this)
{
  IMatRenderContext *v2; // edi
  IMesh *v3; // ebx
  int m_MaxVerts; // ebx
  int v5; // edi
  CDispRenderVert *m_pMemory; // eax
  float *m_pCurrPosition; // ecx
  int v8; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder v11; // [esp+18h] [ebp-1ECh] BYREF
  IMatRenderContext *v12; // [esp+200h] [ebp-4h]

  v2 = materials->GetRenderContext(this: materials);
  v12 = v2;
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))g_materialTranslucentSingleColor->ColorModulate)(
    a1: g_materialTranslucentSingleColor,
    a2: 0.0,
    a3: 1.0,
    a4: 1.0);
  ((void (__stdcall *)(_DWORD))g_materialTranslucentSingleColor->AlphaModulate)(a1: 0.33000001);
  v3 = v2->GetDynamicMesh(this: v2, a2: false, a3: nullptr, a4: nullptr, a5: g_materialTranslucentSingleColor);
  CMeshBuilder::CMeshBuilder(this: &v11);
  CMeshBuilder::Begin(
    this: &v11,
    pMesh: v3,
    type: MATERIAL_TRIANGLES,
    nVertexCount: this->m_pPowerInfo->m_MaxVerts,
    nIndexCount: this->m_nBuildIndexCount,
    pMeshSettings: nullptr);
  m_MaxVerts = this->m_pPowerInfo->m_MaxVerts;
  if ( m_MaxVerts > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pCurrPosition = v11.m_VertexBuilder.m_pCurrPosition;
      *v11.m_VertexBuilder.m_pCurrPosition = m_pMemory[v5].m_vPos.x;
      m_pCurrPosition[1] = m_pMemory[v5].m_vPos.y;
      m_pCurrPosition[2] = m_pMemory[v5].m_vPos.z;
      CVertexBuilder::AdvanceVertex(this: &v11.m_VertexBuilder);
      ++v5;
      --m_MaxVerts;
    }
    while ( m_MaxVerts != 0 );
    v2 = v12;
  }
  v8 = 0;
  if ( this->m_nBuildIndexCount > 0 )
  {
    m_nCurrentIndex = v11.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      v11.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(v11.m_IndexBuilder.m_nIndexOffset)
                                                     + this->m_pBuildIndices[v8];
      m_nCurrentIndex = v11.m_IndexBuilder.m_nIndexSize + v11.m_IndexBuilder.m_nCurrentIndex;
      v11.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
      if ( m_nCurrentIndex > v11.m_IndexBuilder.m_nIndexCount )
        v11.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v8;
    }
    while ( v8 < this->m_nBuildIndexCount );
  }
  if ( v11.m_bGenerateIndices )
  {
    switch ( v11.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * v11.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * v11.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * v11.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * v11.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = v11.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(this: &v11.m_IndexBuilder, primitiveType: v11.m_Type, nIndexCount: m_nVertexCount);
  }
  v11.m_pMesh->UnlockMesh(
    this: v11.m_pMesh,
    a2: v11.m_VertexBuilder.m_nVertexCount,
    a3: v11.m_IndexBuilder.m_nIndexCount,
    a4: &v11);
  v11.m_IndexBuilder.m_pIndexBuffer = nullptr;
  v11.m_IndexBuilder.m_nMaxIndexCount = 0;
  v11.m_VertexBuilder.m_nMaxVertexCount = 0;
  v11.m_VertexBuilder.m_pVertexBuffer = nullptr;
  v11.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  v11.m_pMesh->Draw_2(this: v11.m_pMesh, a2: -1, a3: 0);
  v11.m_pMesh = nullptr;
  if ( v11.m_VertexBuilder.m_pVertexBuffer != nullptr
    && v11.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v11.m_VertexBuilder.m_pVertexBuffer) )
  {
    v11.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v11.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( v11.m_IndexBuilder.m_pIndexBuffer != nullptr
    && v11.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v11.m_IndexBuilder.m_pIndexBuffer) )
  {
    v11.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v11.m_IndexBuilder.m_pIndexBuffer);
  }
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100BBB10
// Name: public: bool CDispInfo::Render(class CGroupMesh __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispInfo::Render(CDispInfo *this, CGroupMesh *pGroup, bool bAllowDebugModes)
{
  IMatRenderContext *v5; // edi
  int v6; // eax
  msurface2_t *m_ParentSurfID; // eax
  msurface2_t *v8; // eax
  mtexinfo_t *v9; // eax
  unsigned __int8 *v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // eax
  char *v14; // eax
  int m_nVisible; // ecx
  char pDest[32]; // [esp+14h] [ebp-44h] BYREF
  Vector textPos; // [esp+34h] [ebp-24h] BYREF
  float v18; // [esp+40h] [ebp-18h] BYREF
  float v19; // [esp+44h] [ebp-14h]
  float v20; // [esp+48h] [ebp-10h]
  Vector v21; // [esp+4Ch] [ebp-Ch] BYREF

  if ( this->m_pMesh == nullptr )
    return 0;
  if ( bAllowDebugModes )
  {
    v5 = materials->GetRenderContext(this: materials);
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    if ( sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive() )
    {
      v6 = mat_wireframe.m_pParent != nullptr ? mat_wireframe.m_pParent->m_Value.m_nValue : 0;
      if ( v6 != 0 )
      {
        v5->Bind(this: v5, a2: g_materialWorldWireframeZBuffer, a3: nullptr);
        CDispInfo::SpecifyDynamicMesh(this);
      }
    }
    if ( mat_luxels.m_pParent != nullptr && mat_luxels.m_pParent->m_Value.m_nValue != 0 )
    {
      v5->Bind(
        this: v5,
        a2: host_state.worldbrush->texinfo[*((unsigned __int16 *)this->m_ParentSurfID + 11) >> 1].material,
        a3: nullptr);
      pGroup->m_pMesh->Draw_2(this: pGroup->m_pMesh, a2: this->m_iIndexOffset, a3: this->m_nIndices);
      v5->Bind(this: v5, a2: g_materialDebugLuxels, a3: nullptr);
      CDispInfo::SpecifyDynamicMesh(this);
    }
    if ( r_DispWalkable.m_pParent != nullptr && r_DispWalkable.m_pParent->m_Value.m_nValue != 0
      || r_DispBuildable.m_pParent != nullptr && r_DispBuildable.m_pParent->m_Value.m_nValue != 0 )
    {
      v5->Bind(
        this: v5,
        a2: host_state.worldbrush->texinfo[*((unsigned __int16 *)this->m_ParentSurfID + 11) >> 1].material,
        a3: nullptr);
      pGroup->m_pMesh->Draw_2(this: pGroup->m_pMesh, a2: this->m_iIndexOffset, a3: this->m_nIndices);
      if ( r_DispWalkable.m_pParent != nullptr && r_DispWalkable.m_pParent->m_Value.m_nValue != 0 )
        CDispInfo::SpecifyWalkableDynamicMesh(this);
      if ( r_DispBuildable.m_pParent != nullptr && r_DispBuildable.m_pParent->m_Value.m_nValue != 0 )
        CDispInfo::SpecifyBuildableDynamicMesh(this);
    }
    if ( mat_surfaceid.m_pParent != nullptr && mat_surfaceid.m_pParent->m_Value.m_nValue != 0 )
    {
      this->GetBoundingBox(this, a2: (Vector *)&v18, a3: &v21);
      textPos.x = (float)(v21.x + v18) * 0.5;
      textPos.y = (float)(v21.y + v19) * 0.5;
      textPos.z = (float)(v21.z + v20) * 0.5;
      if ( mat_surfaceid.m_pParent != nullptr && mat_surfaceid.m_pParent->m_Value.m_nValue == 2 )
        m_ParentSurfID = (msurface2_t *)(this->m_ParentSurfID - host_state.worldbrush->surfaces2);
      else
        m_ParentSurfID = this->m_ParentSurfID;
      V_snprintf(pDest, maxLen: 32, pFormat: "%d", m_ParentSurfID);
      CDebugOverlay::AddTextOverlay(&textPos, duration: 0.0, text: pDest);
    }
    if ( mat_surfacemat.m_pParent != nullptr && mat_surfacemat.m_pParent->m_Value.m_nValue != 0 )
    {
      this->GetBoundingBox(this, a2: (Vector *)&v18, a3: &textPos);
      v8 = this->m_ParentSurfID;
      v21.x = (float)(textPos.x + v18) * 0.5;
      v21.y = (float)(textPos.y + v19) * 0.5;
      v21.z = (float)(textPos.z + v20) * 0.5;
      v9 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)v8 + 11) >> 1];
      if ( v9->material != nullptr )
        v10 = (unsigned __int8 *)v9->material->GetName(this: v9->material);
      else
        v10 = "no material";
      strrchr(string: v10, chr: 0x2Fu);
      v12 = v11;
      strrchr(string: v10, chr: 0x5Cu);
      if ( v12 > v13 )
        v13 = v12;
      if ( v13 != 0 )
        v14 = (char *)(v13 + 1);
      else
        v14 = (char *)v10;
      CDebugOverlay::AddTextOverlay(textPos: &v21, duration: 0.0, text: v14);
    }
    if ( v5 != nullptr )
    {
      v5->EndRender(this: v5);
      v5->Release(this: v5);
      return 1;
    }
  }
  else
  {
    m_nVisible = pGroup->m_nVisible;
    if ( m_nVisible < pGroup->m_Visible.m_Size && this->m_nIndices != 0 )
    {
      pGroup->m_Visible.m_Memory.m_pMemory[m_nVisible].m_FirstIndex = this->m_iIndexOffset;
      pGroup->m_Visible.m_Memory.m_pMemory[pGroup->m_nVisible].m_NumIndices = this->m_nIndices;
      pGroup->m_VisibleDisps.m_Memory.m_pMemory[pGroup->m_nVisible++] = this;
      ++pGroup->m_pGroup->m_nVisible;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BBE80
// Name: void IterateLightmapSamples(class CDispInfo __near *,struct ProcessLightmapSampleData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IterateLightmapSamples(CDispInfo *pDisp, const ProcessLightmapSampleData_t *data)
{
  unsigned __int8 *v2; // ebx
  char *v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // edx
  float v10; // xmm0_4
  CTriInfo *m_pTriInfos; // ecx
  int v12; // eax
  CTriInfo *v13; // esi
  int m_VertexSize_Position; // ecx
  float *m_pPosition; // edx
  int v16; // eax
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  int v21; // eax
  float v22; // xmm7_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  int v28; // eax
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  int m_VertexSize_Normal; // ecx
  float *m_pNormal; // edx
  int v35; // eax
  float v36; // xmm6_4
  float v37; // xmm0_4
  int v38; // eax
  float v39; // xmm7_4
  float v40; // xmm0_4
  int v41; // eax
  float v42; // xmm4_4
  float v43; // xmm5_4
  int m_VertexSize_TangentS; // ecx
  float v45; // xmm3_4
  float *m_pTangentS; // edx
  int v47; // eax
  float v48; // xmm6_4
  float v49; // xmm3_4
  int v50; // eax
  float v51; // xmm7_4
  float v52; // xmm3_4
  int v53; // eax
  float v54; // xmm4_4
  float v55; // xmm5_4
  int m_VertexSize_TangentT; // ecx
  float *m_pTangentT; // edx
  int v58; // eax
  float v59; // xmm4_4
  float v60; // xmm5_4
  float v61; // xmm6_4
  int v62; // eax
  float v63; // xmm7_4
  float v64; // xmm2_4
  int v65; // eax
  float v66; // xmm3_4
  float v67; // xmm2_4
  int v68; // esi
  Vector vPos; // [esp+0h] [ebp-94h] BYREF
  float v70; // [esp+10h] [ebp-84h]
  float v71; // [esp+14h] [ebp-80h]
  Vector vNormal; // [esp+18h] [ebp-7Ch] BYREF
  float v73; // [esp+28h] [ebp-6Ch]
  float v74; // [esp+2Ch] [ebp-68h]
  Vector vTangentS; // [esp+30h] [ebp-64h] BYREF
  float v76; // [esp+40h] [ebp-54h]
  float v77; // [esp+44h] [ebp-50h]
  Vector vTangentT; // [esp+48h] [ebp-4Ch] BYREF
  float v79; // [esp+58h] [ebp-3Ch]
  float v80; // [esp+5Ch] [ebp-38h]
  float v81; // [esp+64h] [ebp-30h]
  float v82; // [esp+68h] [ebp-2Ch]
  float v83; // [esp+70h] [ebp-24h]
  float v84; // [esp+74h] [ebp-20h]
  float a; // [esp+78h] [ebp-1Ch]
  float b; // [esp+7Ch] [ebp-18h]
  float c; // [esp+80h] [ebp-14h]
  int s; // [esp+84h] [ebp-10h]
  int tmax; // [esp+88h] [ebp-Ch]
  int t; // [esp+8Ch] [ebp-8h]
  int smax; // [esp+90h] [ebp-4h]

  if ( g_DispLightmapSamplePositions.m_Size != 0 )
  {
    v2 = &g_DispLightmapSamplePositions.m_Memory.m_pMemory[pDisp->m_iLightmapSamplePositionStart];
    v3 = (char *)host_state.worldbrush->surfacelighting
       + (((char *)pDisp->m_ParentSurfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
    v4 = *((__int16 *)v3 + 2);
    v5 = *((__int16 *)v3 + 3) + 1;
    v6 = v4 + 1;
    smax = v6;
    tmax = v5;
    for ( t = 0; t < v5; ++t )
    {
      s = 0;
      if ( v6 > 0 )
      {
        do
        {
          LOBYTE(v7) = *v2;
          if ( *v2 == 0xFF )
          {
            v8 = *++v2;
            v7 = v8 + 255;
          }
          else
          {
            v7 = (unsigned __int8)v7;
          }
          v9 = v7;
          v10 = (float)v2[1];
          m_pTriInfos = pDisp->m_pPowerInfo->m_pTriInfos;
          v12 = m_pTriInfos[v7].m_Indices[2];
          v13 = &m_pTriInfos[v9];
          m_VertexSize_Position = pDisp->m_MeshReader.m_VertexSize_Position;
          m_pPosition = pDisp->m_MeshReader.m_pPosition;
          v16 = m_VertexSize_Position * v12;
          v17 = *(float *)((char *)m_pPosition + v16);
          v18 = *(float *)((char *)m_pPosition + v16 + 4);
          v19 = *(float *)((char *)m_pPosition + v16 + 8);
          v20 = (float)v2[3] * 0.0039215689;
          v21 = m_VertexSize_Position * v13->m_Indices[1];
          v22 = *(float *)((char *)m_pPosition + v21);
          v23 = (float)v2[2] * 0.0039215689;
          v24 = v17 * v20;
          v25 = v19 * v20;
          c = v20;
          v26 = v18 * v20;
          v79 = *(float *)((char *)m_pPosition + v21 + 4) * v23;
          v27 = *(float *)((char *)m_pPosition + v21 + 8);
          v28 = m_VertexSize_Position * v13->m_Indices[0];
          v29 = v10 * 0.0039215689;
          v30 = *(float *)((char *)m_pPosition + v28 + 8);
          v80 = v27 * v23;
          v31 = *(float *)((char *)m_pPosition + v28 + 4);
          b = v23;
          v32 = (float)((float)(v29 * *(float *)((char *)m_pPosition + v28)) + (float)(v22 * v23)) + v24;
          a = v29;
          v2 += 4;
          vPos.x = v32;
          vPos.y = (float)((float)(v31 * v29) + v79) + v26;
          vPos.z = (float)((float)(v30 * v29) + v80) + v25;
          if ( CDispInfo::NumLightMaps(this: pDisp) > 1 )
          {
            m_VertexSize_Normal = pDisp->m_MeshReader.m_VertexSize_Normal;
            m_pNormal = pDisp->m_MeshReader.m_pNormal;
            v35 = m_VertexSize_Normal * v13->m_Indices[2];
            v36 = *(float *)((char *)m_pNormal + v35);
            v73 = *(float *)((char *)m_pNormal + v35 + 4) * c;
            v37 = *(float *)((char *)m_pNormal + v35 + 8);
            v38 = m_VertexSize_Normal * v13->m_Indices[1];
            v39 = *(float *)((char *)m_pNormal + v38);
            v74 = v37 * c;
            v83 = *(float *)((char *)m_pNormal + v38 + 4) * b;
            v40 = *(float *)((char *)m_pNormal + v38 + 8);
            v41 = m_VertexSize_Normal * v13->m_Indices[0];
            v42 = *(float *)((char *)m_pNormal + v41 + 4);
            v43 = *(float *)((char *)m_pNormal + v41 + 8);
            m_VertexSize_TangentS = pDisp->m_MeshReader.m_VertexSize_TangentS;
            v84 = v40 * b;
            v45 = a * *(float *)((char *)m_pNormal + v41);
            m_pTangentS = pDisp->m_MeshReader.m_pTangentS;
            vNormal.x = (float)(v45 + (float)(v39 * b)) + (float)(v36 * c);
            vNormal.y = (float)((float)(v42 * a) + v83) + v73;
            vNormal.z = (float)((float)(v43 * a) + (float)(v40 * b)) + v74;
            v47 = m_VertexSize_TangentS * v13->m_Indices[2];
            v48 = *(float *)((char *)m_pTangentS + v47);
            v70 = *(float *)((char *)m_pTangentS + v47 + 4) * c;
            v49 = *(float *)((char *)m_pTangentS + v47 + 8);
            v50 = m_VertexSize_TangentS * v13->m_Indices[1];
            v51 = *(float *)((char *)m_pTangentS + v50);
            v71 = v49 * c;
            v76 = *(float *)((char *)m_pTangentS + v50 + 4) * b;
            v52 = *(float *)((char *)m_pTangentS + v50 + 8);
            v53 = m_VertexSize_TangentS * v13->m_Indices[0];
            v54 = *(float *)((char *)m_pTangentS + v53 + 4);
            v55 = *(float *)((char *)m_pTangentS + v53 + 8);
            v77 = v52 * b;
            vTangentS.x = (float)((float)(*(float *)((char *)m_pTangentS + v53) * a) + (float)(v51 * b))
                        + (float)(v48 * c);
            vTangentS.y = (float)((float)(v54 * a) + v76) + v70;
            vTangentS.z = (float)((float)(v55 * a) + (float)(v52 * b)) + v71;
            m_VertexSize_TangentT = pDisp->m_MeshReader.m_VertexSize_TangentT;
            m_pTangentT = pDisp->m_MeshReader.m_pTangentT;
            v58 = m_VertexSize_TangentT * v13->m_Indices[2];
            v59 = *(float *)((char *)m_pTangentT + v58);
            v60 = *(float *)((char *)m_pTangentT + v58 + 4);
            v61 = *(float *)((char *)m_pTangentT + v58 + 8);
            v62 = m_VertexSize_TangentT * v13->m_Indices[1];
            v63 = *(float *)((char *)m_pTangentT + v62);
            v81 = *(float *)((char *)m_pTangentT + v62 + 4) * b;
            v64 = *(float *)((char *)m_pTangentT + v62 + 8);
            v65 = m_VertexSize_TangentT * v13->m_Indices[0];
            v66 = *(float *)((char *)m_pTangentT + v65 + 8);
            v82 = v64 * b;
            v67 = (float)((float)(*(float *)((char *)m_pTangentT + v65 + 4) * a) + v81) + (float)(v60 * c);
            vTangentT.x = (float)((float)(*(float *)((char *)m_pTangentT + v65) * a) + (float)(v63 * b))
                        + (float)(v59 * c);
            vTangentT.y = v67;
            vTangentT.z = (float)((float)(v66 * a) + v82) + (float)(v61 * c);
          }
          v68 = s;
          data->pProcessLightmapSampleDataFunc(
            a1: data,
            a2: &vPos,
            a3: &vNormal,
            a4: &vTangentS,
            a5: &vTangentT,
            a6: t,
            a7: s,
            a8: tmax,
            a9: smax);
          s = v68 + 1;
        }
        while ( v68 + 1 < smax );
        v5 = tmax;
        v6 = smax;
      }
    }
  }
  else if ( _executeCount < 20 )
  {
    ++_executeCount;
    _Warning(
      a1: "Cannot update displacement for dlight - set 'r_dlightsenable 1' and reload the map! (data may also have been culle"
      "d by MakeGameData)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC2D0
// Name: public: void CDispInfo::AddSingleDynamicLight(struct dlight_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddSingleDynamicLight(CDispInfo *this, dlight_t *dl)
{
  double minlight; // st7
  int style; // eax
  __m128i v4; // xmm0
  float v5; // xmm1_4
  int g; // eax
  float v7; // xmm2_4
  int b; // eax
  float y; // xmm0_4
  ProcessLightmapSampleData_t data; // [esp+0h] [ebp-28h] BYREF

  minlight = dl->minlight;
  style = dl->style;
  data.m_LightDistSqr = dl->radius * dl->radius;
  v4 = _mm_cvtsi32_si128(d_lightstylevalue[style]);
  v5 = dword_10425B80[dl->color.exponent];
  g = dl->color.g;
  *(float *)v4.m128i_i32 = _mm_cvtepi32_ps(v4).m128_f32[0] * 0.0037878789;
  data.m_Intensity.x = (float)((float)dl->color.r * v5) * *(float *)v4.m128i_i32;
  v7 = (float)g;
  b = dl->color.b;
  data.m_Intensity.y = (float)(v7 * v5) * *(float *)v4.m128i_i32;
  data.m_Intensity.z = (float)((float)b * v5) * *(float *)v4.m128i_i32;
  if ( g_flMinLightingValue >= minlight )
    minlight = g_flMinLightingValue;
  data.m_vLightOrigin.x = dl->origin.x;
  y = dl->origin.y;
  data.m_ooQuadraticAttn = minlight * data.m_LightDistSqr;
  data.m_vLightOrigin.y = y;
  data.m_vLightOrigin.z = dl->origin.z;
  data.m_ooRadiusSq = 1.0 / (float)(dl->radius * dl->radius);
  data.pProcessLightmapSampleDataFunc = ProcessLightmapSample;
  IterateLightmapSamples(pDisp: this, &data);
}

//------------------------------------------------------------------------------
// Address: 0x100BC3C0
// Name: public: void CDispInfo::AddSingleDynamicLightBumped(struct dlight_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddSingleDynamicLightBumped(CDispInfo *this, dlight_t *dl)
{
  double minlight; // st7
  int style; // eax
  __m128i v4; // xmm0
  float v5; // xmm1_4
  int g; // eax
  float v7; // xmm2_4
  int b; // eax
  float y; // xmm0_4
  ProcessLightmapSampleData_t data; // [esp+0h] [ebp-28h] BYREF

  minlight = dl->minlight;
  style = dl->style;
  data.m_LightDistSqr = dl->radius * dl->radius;
  v4 = _mm_cvtsi32_si128(d_lightstylevalue[style]);
  v5 = dword_10425B80[dl->color.exponent];
  g = dl->color.g;
  *(float *)v4.m128i_i32 = _mm_cvtepi32_ps(v4).m128_f32[0] * 0.0037878789;
  data.m_Intensity.x = (float)((float)dl->color.r * v5) * *(float *)v4.m128i_i32;
  v7 = (float)g;
  b = dl->color.b;
  data.m_Intensity.y = (float)(v7 * v5) * *(float *)v4.m128i_i32;
  data.m_Intensity.z = (float)((float)b * v5) * *(float *)v4.m128i_i32;
  if ( g_flMinLightingValue >= minlight )
    minlight = g_flMinLightingValue;
  data.m_vLightOrigin.x = dl->origin.x;
  y = dl->origin.y;
  data.m_ooQuadraticAttn = minlight * data.m_LightDistSqr;
  data.m_vLightOrigin.y = y;
  data.m_vLightOrigin.z = dl->origin.z;
  data.m_ooRadiusSq = 1.0 / (float)(dl->radius * dl->radius);
  data.pProcessLightmapSampleDataFunc = ProcessLightmapSampleBumped;
  IterateLightmapSamples(pDisp: this, &data);
}

//------------------------------------------------------------------------------
// Address: 0x100BC4B0
// Name: public: void CDispInfo::AddSingleDynamicAlphaLight(struct dlight_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddSingleDynamicAlphaLight(CDispInfo *this, dlight_t *dl)
{
  bool v2; // zf
  float v3; // xmm1_4
  float v4; // xmm0_4
  float minlight; // xmm0_4
  ProcessLightmapSampleData_t data; // [esp+0h] [ebp-28h] BYREF

  v2 = (dl->flags & 8) == 0;
  v3 = dl->radius * dl->radius;
  v4 = (float)((float)dl->color.r * dword_10425B80[dl->color.exponent])
     * (float)((float)d_lightstylevalue[dl->style] * 0.0037878789);
  data.m_LightDistSqr = v3;
  data.m_Intensity.x = v4;
  if ( !v2 )
  {
    data.m_Intensity.x = v4 * -1.0;
    data.m_Intensity.y = data.m_Intensity.y * -1.0;
    data.m_Intensity.z = data.m_Intensity.z * -1.0;
  }
  minlight = dl->minlight;
  if ( g_flMinLightingValue > minlight )
    minlight = g_flMinLightingValue;
  data.m_ooQuadraticAttn = minlight * v3;
  data.m_vLightOrigin = dl->origin;
  data.m_ooRadiusSq = 1.0 / (float)(dl->radius * dl->radius);
  data.pProcessLightmapSampleDataFunc = ProcessLightmapSampleAlpha;
  IterateLightmapSamples(pDisp: this, &data);
}

//------------------------------------------------------------------------------
// Address: 0x100BC5B0
// Name: private: bool CDispInfo::SetupDecalNodeIntersect_R(class CVertIndex const __near &,int,class CDispDecalBase __near *,struct ShadowInfo_t const __near *,int,class CDecalNodeSetupCache __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispInfo::SetupDecalNodeIntersect_R(
        CDispInfo *this,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        CDispDecalBase *pDispDecal,
        const CVertIndex *pInfo,
        const CVertIndex *iLevel,
        CDecalNodeSetupCache *pCache)
{
  const CPowerInfo *m_pPowerInfo; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // ebx
  CDispDecalBase *v15; // ebx
  float *v16; // edx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float x; // xmm0_4
  double v21; // st7
  double y; // st6
  double v23; // st5
  int v24; // eax
  double v25; // rt0
  int v26; // eax
  float *v27; // edx
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  unsigned int v31; // eax
  float *v32; // edx
  double v33; // st3
  double v34; // st4
  double v35; // st6
  int v36; // edx
  float *v37; // eax
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  unsigned int v41; // edx
  double v42; // st6
  float *v43; // edx
  double v44; // st5
  double v45; // st4
  double v46; // st2
  double v47; // st6
  double v48; // st5
  double v49; // rt0
  double v50; // st4
  double v51; // st5
  double v52; // st6
  double v53; // rt2
  double v54; // st4
  double v55; // st6
  bool v56; // zf
  float vMin; // [esp+Ch] [ebp-1Ch]
  float vMina; // [esp+Ch] [ebp-1Ch]
  float vMin_4; // [esp+10h] [ebp-18h]
  float vMin_4a; // [esp+10h] [ebp-18h]
  float vMin_8; // [esp+14h] [ebp-14h]
  float vMin_8a; // [esp+14h] [ebp-14h]
  float vMax; // [esp+18h] [ebp-10h]
  float vMaxa; // [esp+18h] [ebp-10h]
  float vMax_4; // [esp+1Ch] [ebp-Ch]
  float vMax_4a; // [esp+1Ch] [ebp-Ch]
  float vMax_8; // [esp+20h] [ebp-8h]
  float vMax_8a; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int anyChildIntersected; // [esp+30h] [ebp+8h]
  char anyChildIntersected_3; // [esp+33h] [ebp+Bh]
  const CVertIndex *cornerVert; // [esp+3Ch] [ebp+14h]
  float *sideVert; // [esp+40h] [ebp+18h]
  const CVertIndex *sideVertc; // [esp+40h] [ebp+18h]
  float *sideVerta; // [esp+40h] [ebp+18h]
  float *sideVertb; // [esp+40h] [ebp+18h]
  CDecalNodeSetupCache *pCachea; // [esp+44h] [ebp+1Ch]

  m_pPowerInfo = this->m_pPowerInfo;
  v9 = nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y;
  if ( (int)iLevel + 1 >= this->m_Power )
  {
    v15 = pDispDecal;
    if ( pCache->m_CacheIndex[v9] != pCache->m_CurrentCacheIndex )
    {
      sideVert = &pCache->m_ProjectedVert[v9].x;
      v16 = (float *)((char *)this->m_MeshReader.m_pPosition + v9 * this->m_MeshReader.m_VertexSize_Position);
      if ( pInfo != nullptr )
      {
        v17 = *v16;
        v18 = v16[1];
        v19 = v16[2];
        *sideVert = (float)((float)((float)(*(float *)&pInfo[1] * v18) + (float)(*(float *)pInfo * *v16))
                          + (float)(*(float *)&pInfo[2] * v19))
                  + *(float *)&pInfo[3];
        sideVert[1] = (float)((float)((float)(*(float *)&pInfo[5] * v18) + (float)(*(float *)&pInfo[4] * v17))
                            + (float)(*(float *)&pInfo[6] * v19))
                    + *(float *)&pInfo[7];
        sideVert[2] = (float)((float)((float)(*(float *)&pInfo[9] * v18) + (float)(*(float *)&pInfo[8] * v17))
                            + (float)(*(float *)&pInfo[10] * v19))
                    + *(float *)&pInfo[11];
      }
      else
      {
        *sideVert = (float)((float)((float)((float)(*(float *)&pDispDecal[1].m_nTris * v16[1])
                                          + (float)(*v16 * *(float *)&pDispDecal[1].m_Flags))
                                  + (float)(*(float *)pDispDecal[2].m_NodeIntersect.m_Ints * v16[2]))
                          - *(float *)(pDispDecal[1].m_NodeIntersect.m_Ints[0] + 44))
                  + 0.5;
        sideVert[1] = (float)((float)((float)((float)(*(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[2] * v16[1])
                                            + (float)(*v16 * *(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[1]))
                                    + (float)(*(float *)&pDispDecal[2].m_Flags * v16[2]))
                            - *(float *)(pDispDecal[1].m_NodeIntersect.m_Ints[0] + 48))
                    + 0.5;
        sideVert[2] = 0.0;
      }
      pCache->m_CacheIndex[v9] = pCache->m_CurrentCacheIndex;
    }
    x = pCache->m_ProjectedVert[v9].x;
    vMin_8 = pCache->m_ProjectedVert[v9].z;
    v21 = vMin_8;
    y = pCache->m_ProjectedVert[v9].y;
    v23 = y;
    v24 = 16 * v9;
    vMin = x;
    vMax = x;
    vMax_8 = vMin_8;
    pCachea = (CDecalNodeSetupCache *)v24;
    anyChildIntersected = 4;
    while ( 1 )
    {
      sideVertc = (CVertIndex *)((char *)this->m_pPowerInfo->m_pSideVerts->m_Verts + v24);
      cornerVert = (CVertIndex *)((char *)this->m_pPowerInfo->m_pSideVertCorners->m_Verts + v24);
      v26 = sideVertc->x + this->m_pPowerInfo->m_SideLength * sideVertc->y;
      if ( pCache->m_CacheIndex[v26] != pCache->m_CurrentCacheIndex )
      {
        sideVerta = &pCache->m_ProjectedVert[v26].x;
        v27 = (float *)((char *)this->m_MeshReader.m_pPosition + v26 * this->m_MeshReader.m_VertexSize_Position);
        if ( pInfo != nullptr )
        {
          v28 = *v27;
          v29 = v27[1];
          v30 = v27[2];
          *sideVerta = (float)((float)((float)(*(float *)&pInfo[1] * v29) + (float)(*(float *)pInfo * *v27))
                             + (float)(*(float *)&pInfo[2] * v30))
                     + *(float *)&pInfo[3];
          sideVerta[1] = (float)((float)((float)(*(float *)&pInfo[5] * v29) + (float)(*(float *)&pInfo[4] * v28))
                               + (float)(*(float *)&pInfo[6] * v30))
                       + *(float *)&pInfo[7];
          sideVerta[2] = (float)((float)((float)(*(float *)&pInfo[9] * v29) + (float)(*(float *)&pInfo[8] * v28))
                               + (float)(*(float *)&pInfo[10] * v30))
                       + *(float *)&pInfo[11];
        }
        else
        {
          *sideVerta = (float)((float)((float)((float)(*(float *)&v15[1].m_nTris * v27[1])
                                             + (float)(*v27 * *(float *)&v15[1].m_Flags))
                                     + (float)(*(float *)v15[2].m_NodeIntersect.m_Ints * v27[2]))
                             - *(float *)(v15[1].m_NodeIntersect.m_Ints[0] + 44))
                     + 0.5;
          v15 = pDispDecal;
          sideVerta[1] = (float)((float)((float)((float)(*(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[2] * v27[1])
                                               + (float)(*v27 * *(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[1]))
                                       + (float)(*(float *)&pDispDecal[2].m_Flags * v27[2]))
                               - *(float *)(pDispDecal[1].m_NodeIntersect.m_Ints[0] + 48))
                       + 0.5;
          sideVerta[2] = 0.0;
        }
        pCache->m_CacheIndex[v26] = pCache->m_CurrentCacheIndex;
      }
      v31 = 3 * v26;
      v32 = (float *)((char *)pCache + 4 * v31);
      v33 = vMin;
      if ( *v32 <= (double)vMin )
        v33 = pCache->m_ProjectedVert[v31 / 3].x;
      vMina = v33;
      if ( v32[1] <= y )
        y = v32[1];
      vMin_4 = y;
      if ( v32[2] <= v21 )
        v21 = v32[2];
      v34 = vMax;
      if ( pCache->m_ProjectedVert[v31 / 3].x >= (double)vMax )
        v34 = pCache->m_ProjectedVert[v31 / 3].x;
      vMaxa = v34;
      if ( v32[1] >= v23 )
        v23 = v32[1];
      vMax_4 = v23;
      v35 = vMax_8;
      if ( v32[2] >= (double)vMax_8 )
        v35 = v32[2];
      vMax_8a = v35;
      v36 = cornerVert->x + this->m_pPowerInfo->m_SideLength * cornerVert->y;
      if ( pCache->m_CacheIndex[v36] != pCache->m_CurrentCacheIndex )
      {
        sideVertb = &pCache->m_ProjectedVert[v36].x;
        v37 = (float *)((char *)this->m_MeshReader.m_pPosition + v36 * this->m_MeshReader.m_VertexSize_Position);
        if ( pInfo != nullptr )
        {
          v38 = *v37;
          v39 = v37[1];
          v40 = v37[2];
          *sideVertb = (float)((float)((float)(*(float *)&pInfo[1] * v39) + (float)(*(float *)pInfo * *v37))
                             + (float)(*(float *)&pInfo[2] * v40))
                     + *(float *)&pInfo[3];
          sideVertb[1] = (float)((float)((float)(*(float *)&pInfo[5] * v39) + (float)(*(float *)&pInfo[4] * v38))
                               + (float)(*(float *)&pInfo[6] * v40))
                       + *(float *)&pInfo[7];
          sideVertb[2] = (float)((float)((float)(*(float *)&pInfo[9] * v39) + (float)(*(float *)&pInfo[8] * v38))
                               + (float)(*(float *)&pInfo[10] * v40))
                       + *(float *)&pInfo[11];
        }
        else
        {
          *sideVertb = (float)((float)((float)((float)(*(float *)&v15[1].m_nTris * v37[1])
                                             + (float)(*v37 * *(float *)&v15[1].m_Flags))
                                     + (float)(*(float *)v15[2].m_NodeIntersect.m_Ints * v37[2]))
                             - *(float *)(v15[1].m_NodeIntersect.m_Ints[0] + 44))
                     + 0.5;
          v15 = pDispDecal;
          sideVertb[1] = (float)((float)((float)((float)(*(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[2] * v37[1])
                                               + (float)(*v37 * *(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[1]))
                                       + (float)(*(float *)&pDispDecal[2].m_Flags * v37[2]))
                               - *(float *)(pDispDecal[1].m_NodeIntersect.m_Ints[0] + 48))
                       + 0.5;
          sideVertb[2] = 0.0;
        }
        pCache->m_CacheIndex[v36] = pCache->m_CurrentCacheIndex;
      }
      v41 = 3 * v36;
      v42 = pCache->m_ProjectedVert[v41 / 3].x;
      v43 = (float *)((char *)pCache + 4 * v41);
      v44 = vMina;
      if ( v42 <= vMina )
        v44 = v42;
      vMin = v44;
      v45 = vMin_4;
      if ( v43[1] <= (double)vMin_4 )
        v45 = v43[1];
      vMin_4a = v45;
      if ( v43[2] <= v21 )
        v21 = v43[2];
      v46 = v42;
      v47 = vMaxa;
      if ( v46 >= vMaxa )
        v47 = v46;
      vMax = v47;
      v48 = vMax_4;
      if ( v43[1] >= (double)vMax_4 )
        v48 = v43[1];
      v49 = v45;
      v50 = v48;
      v51 = v49;
      vMax_4a = v50;
      v52 = vMax_8a;
      if ( v43[2] >= (double)vMax_8a )
        v52 = v43[2];
      pCachea = (CDecalNodeSetupCache *)((char *)pCachea + 4);
      v53 = v50;
      v54 = v52;
      v55 = v53;
      v56 = anyChildIntersected-- == 1;
      vMax_8 = v54;
      if ( v56 )
        break;
      v24 = (int)pCachea;
      v25 = v51;
      v23 = v55;
      y = v25;
    }
    if ( vMin <= 1.0
      && vMax >= 0.0
      && vMin_4a <= 1.0
      && vMax_4a >= 0.0
      && (pInfo == nullptr || vMax_8 >= 0.0 && (vMin_8a = v21) <= *(float *)&pInfo[17]) )
    {
      v15->m_NodeIntersect.m_Ints[iNodeBitIndex >> 5] |= 1 << (iNodeBitIndex & 0x1F);
      return 1;
    }
  }
  else
  {
    v10 = iNodeBitIndex + 1;
    anyChildIntersected_3 = 0;
    v11 = 4 * v9;
    for ( i = 4; i != 0; --i )
    {
      if ( CDispInfo::SetupDecalNodeIntersect_R(
             this,
             nodeIndex: &m_pPowerInfo->m_pChildVerts->m_Verts[v11],
             iNodeBitIndex: v10,
             pDispDecal,
             (const ShadowInfo_t *)pInfo,
             iLevel: (int)iLevel + 1,
             pCache) )
      {
        anyChildIntersected_3 = 1;
      }
      m_pPowerInfo = this->m_pPowerInfo;
      v10 += m_pPowerInfo->m_NodeIndexIncrements[(_DWORD)iLevel];
      ++v11;
    }
    if ( anyChildIntersected_3 != 0 )
    {
      pDispDecal->m_NodeIntersect.m_Ints[iNodeBitIndex >> 5] |= 1 << (iNodeBitIndex & 0x1F);
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BCC70
// Name: private: void CDispInfo::SetupDecalNodeIntersect(class CVertIndex const __near &,int,class CDispDecalBase __near *,struct ShadowInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SetupDecalNodeIntersect(
        CDispInfo *this,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        CDispDecalBase *pDispDecal,
        const CVertIndex *pInfo)
{
  char v5; // al
  unsigned __int8 m_Flags; // cl

  if ( pDispDecal != nullptr )
  {
    pDispDecal->m_NodeIntersect.m_Ints[0] = 0;
    pDispDecal->m_NodeIntersect.m_Ints[1] = 0;
    pDispDecal->m_NodeIntersect.m_Ints[2] = 0;
  }
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    cache.m_CurrentCacheIndex = 0;
  }
  ++cache.m_CurrentCacheIndex;
  v5 = CDispInfo::SetupDecalNodeIntersect_R(
         this,
         nodeIndex,
         iNodeBitIndex,
         pDispDecal,
         pInfo,
         iLevel: nullptr,
         pCache: &cache);
  pDispDecal->m_Flags |= 1u;
  m_Flags = pDispDecal->m_Flags;
  if ( v5 != 0 )
    pDispDecal->m_Flags = m_Flags & 0xFB;
  else
    pDispDecal->m_Flags = m_Flags | 4;
}

//------------------------------------------------------------------------------
// Address: 0x100BCCE0
// Name: void TesselateDisplacementNode<class CEngineTesselateHelper>(class CEngineTesselateHelper __near *,class CVertIndex const __near &,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacementNode<CEngineTesselateHelper>(
        CEngineTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        char iLevel,
        int *pActiveChildren)
{
  int v5; // eax
  int v6; // ecx
  const CVertIndex *v7; // ebx
  __int16 v8; // dx
  __int16 v9; // di
  int v10; // eax
  __int16 vertInc; // [esp+4h] [ebp-8h]
  int iVert; // [esp+8h] [ebp-4h]
  int iCurTriVert; // [esp+14h] [ebp+8h]
  int iLevela; // [esp+1Ch] [ebp+10h]

  v5 = 1 << (pHelper->m_pPowerInfo->m_Power - iLevel - 1);
  v6 = 0;
  iCurTriVert = 0;
  vertInc = v5;
  iVert = 0;
  if ( g_TWinding.m_nVerts > 0 )
  {
    v7 = nodeIndex;
    iLevela = 0;
    while ( 1 )
    {
      v8 = v7->x + v5 * *(__int16 *)((char *)&g_TWinding.m_Verts->m_Index.x + v6);
      v9 = v7->y + v5 * *(__int16 *)((char *)&g_TWinding.m_Verts->m_Index.y + v6);
      v10 = *(__int16 *)((char *)&g_TWinding.m_Verts->m_iNode + v6);
      if ( v10 == -1 || pActiveChildren[v10] == 0 )
      {
        v7 = nodeIndex;
        if ( ((1 << ((v8 + LOBYTE(pHelper->m_pPowerInfo->m_SideLength) * v9) & 0x1F))
            & pHelper->m_pActiveVerts[(v8 + pHelper->m_pPowerInfo->m_SideLength * v9) >> 5]) != 0 )
        {
          pHelper->m_TempIndices[iCurTriVert++] = v8 + v9 * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          if ( iCurTriVert == 2 )
          {
            pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
            CEngineTesselateHelper::EndTriangle(this: pHelper);
            pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
            iCurTriVert = 1;
          }
        }
      }
      else
      {
        iCurTriVert = 0;
      }
      iLevela += 6;
      if ( ++iVert >= g_TWinding.m_nVerts )
        break;
      v6 = iLevela;
      LOWORD(v5) = vertInc;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCE30
// Name: void TesselateDisplacement_R<class CEngineTesselateHelper>(class CEngineTesselateHelper __near *,class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacement_R<CEngineTesselateHelper>(
        CEngineTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  int m_nIndices; // eax
  DispNodeInfo_t *v6; // edi
  const CPowerInfo *m_pPowerInfo; // ecx
  int v8; // edx
  int v9; // ebx
  const CPowerInfo *v10; // ecx
  const CVertIndex *v11; // edi
  unsigned int v12; // edx
  unsigned __int16 v13; // ax
  int bActiveChildren[4]; // [esp+Ch] [ebp-18h] BYREF
  DispNodeInfo_t *nodeInfo; // [esp+1Ch] [ebp-8h]
  int oldIndexCount; // [esp+20h] [ebp-4h]
  int iChild; // [esp+2Ch] [ebp+8h]
  int iNodeBitIndexa; // [esp+34h] [ebp+10h]

  m_nIndices = pHelper->m_nIndices;
  v6 = &pHelper->m_pDisp->m_pNodeInfo[iNodeBitIndex];
  m_pPowerInfo = pHelper->m_pPowerInfo;
  v8 = m_pPowerInfo->m_Power - 1;
  nodeInfo = v6;
  oldIndexCount = m_nIndices;
  if ( iLevel < v8 )
  {
    v9 = iNodeBitIndex + 1;
    iChild = 0;
    iNodeBitIndexa = 4 * (nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y);
    do
    {
      v10 = pHelper->m_pPowerInfo;
      v11 = &v10->m_pChildVerts->m_Verts[iNodeBitIndexa];
      v12 = pHelper->m_pActiveVerts[(v11->x + v10->m_SideLength * v11->y) >> 5]
          & (1 << ((v11->x + LOBYTE(v10->m_SideLength) * v11->y) & 0x1F));
      bActiveChildren[iChild] = v12;
      if ( v12 != 0 )
        TesselateDisplacement_R<CEngineTesselateHelper>(pHelper, nodeIndex: v11, iNodeBitIndex: v9, iLevel: iLevel + 1);
      else
        *(_WORD *)&pHelper->m_pDisp->m_pNodeInfo[v9].m_Count = 0;
      v9 += pHelper->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      ++iNodeBitIndexa;
      ++iChild;
    }
    while ( iChild < 4 );
    v6 = nodeInfo;
  }
  else
  {
    memset(bActiveChildren, 0, sizeof(bActiveChildren));
  }
  if ( pHelper->m_nIndices == oldIndexCount )
  {
    v6->m_Flags = 0;
  }
  else
  {
    v6->m_Flags = 1;
    oldIndexCount = pHelper->m_nIndices;
  }
  TesselateDisplacementNode<CEngineTesselateHelper>(pHelper, nodeIndex, iLevel, pActiveChildren: bActiveChildren);
  v13 = oldIndexCount;
  v6->m_Count = LOBYTE(pHelper->m_nIndices) - oldIndexCount;
  v6->m_FirstTesselationIndex = v13;
}

//------------------------------------------------------------------------------
// Address: 0x100BCF70
// Name: public: void CDispInfo::TesselateDisplacement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::TesselateDisplacement(CDispInfo *this)
{
  int v2; // edi
  CGroupMesh *m_pMesh; // eax
  CDispUtilsHelper_vtbl *v4; // eax
  int m_iIndexOffset; // [esp-8h] [ebp-214h]
  CEngineTesselateHelper helper; // [esp+8h] [ebp-204h] BYREF

  CDispInfo::ClearAllDecalFragments(this);
  CDispInfo::ClearAllShadowDecalFragments(this);
  v2 = this->m_pPowerInfo->m_SideLength - 1;
  CMeshBuilder::CMeshBuilder(this: &helper.m_IndexMesh);
  m_pMesh = this->m_pMesh;
  m_iIndexOffset = this->m_iIndexOffset;
  helper.m_pDisp = this;
  CMeshBuilder::BeginModify(
    this: &helper.m_IndexMesh,
    pMesh: m_pMesh->m_pMesh,
    nFirstVertex: 0,
    nVertexCount: 0,
    nFirstIndex: m_iIndexOffset,
    nIndexCount: 6 * v2 * v2);
  v4 = this->CDispUtilsHelper::__vftable;
  helper.m_pActiveVerts = this->m_ActiveVerts.m_Ints;
  helper.m_pPowerInfo = v4->GetPowerInfo(this: &this->CDispUtilsHelper);
  helper.m_nIndices = 0;
  TesselateDisplacement_R<CEngineTesselateHelper>(
    pHelper: &helper,
    nodeIndex: &helper.m_pPowerInfo->m_RootNode,
    iNodeBitIndex: 0,
    iLevel: 0);
  helper.m_IndexMesh.m_pMesh->ModifyEnd(this: helper.m_IndexMesh.m_pMesh, a2: &helper.m_IndexMesh);
  this->m_nIndices = helper.m_nIndices;
}

//------------------------------------------------------------------------------
// Address: 0x10314650
// Name: _dynamic_initializer_for__disp_dynamic__
// Source: semantic_dyn_pfx_disp
//------------------------------------------------------------------------------
int dynamic_initializer_for__disp_dynamic__()
{
  ConVar::ConVar(this: &disp_dynamic, pName: "disp_dynamic", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__disp_dynamic__);
}

//------------------------------------------------------------------------------
// Address: 0x10319BE0
// Name: _dynamic_initializer_for__disp_list_all_collideable_command__
// Source: semantic_dyn_pfx_disp
//------------------------------------------------------------------------------
int dynamic_initializer_for__disp_list_all_collideable_command__()
{
  ConCommand::ConCommand(
    this: &disp_list_all_collideable_command,
    pName: "disp_list_all_collideable",
    callback: disp_list_all_collideable,
    pHelpString: "List all collideable displacements",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__disp_list_all_collideable_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322D60
// Name: _dynamic_atexit_destructor_for__disp_dynamic__
// Source: semantic_dyn_pfx_disp
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__disp_dynamic__()
{
  ConVar::~ConVar(this: &disp_dynamic);
}

//------------------------------------------------------------------------------
// Address: 0x10325120
// Name: _dynamic_atexit_destructor_for__disp_list_all_collideable_command__
// Source: semantic_dyn_pfx_disp
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__disp_list_all_collideable_command__()
{
  ConCommand::~ConCommand(this: &disp_list_all_collideable_command);
}

//------------------------------------------------------------------------------
// Address: 0x10314680
// Name: _dynamic_initializer_for__g_ConstructorChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ConstructorChecker__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ConstructorChecker__);
}

//------------------------------------------------------------------------------
// Address: 0x10314690
// Name: _dynamic_initializer_for__g_InitMainView__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int dynamic_initializer_for__g_InitMainView__()
{
  float z; // xmm2_4
  float y; // xmm3_4
  float x; // xmm4_4
  unsigned int result; // eax

  z = vec3_origin.z;
  y = vec3_origin.y;
  x = vec3_origin.x;
  for ( result = 0; (int)result < 24; result += 12 )
  {
    g_MainViewOrigin[result / 0xC].x = x;
    g_MainViewOrigin[result / 0xC].y = y;
    g_MainViewOrigin[result / 0xC].z = z;
    g_MainViewForward[result / 0xC].x = 1.0;
    dword_104F1BF8[result / 4] = 0;
    dword_104F1BFC[result / 4] = 0;
    g_MainViewRight[result / 0xC].x = 0.0;
    dword_104F1C10[result / 4] = -1082130432;
    dword_104F1C14[result / 4] = 0;
    g_MainViewUp[result / 0xC].x = 0.0;
    dword_104F1C28[result / 4] = 0;
    dword_104F1C2C[result / 4] = 1065353216;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10319C10
// Name: _dynamic_initializer_for__path_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__path_command__()
{
  ConCommand::ConCommand(
    this: &path_command,
    pName: "path",
    callback: path,
    pHelpString: "Show the engine filesystem path.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__path_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319C40
// Name: _dynamic_initializer_for__fs_printopenfiles_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_printopenfiles_command__()
{
  ConCommand::ConCommand(
    this: &fs_printopenfiles_command,
    pName: "fs_printopenfiles",
    callback: fs_printopenfiles,
    pHelpString: "Show all files currently opened by the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_printopenfiles_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319C70
// Name: _dynamic_initializer_for__fs_warning_level_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_warning_level_command__()
{
  ConCommand::ConCommand(
    this: &fs_warning_level_command,
    pName: "fs_warning_level",
    callback: (void (__cdecl *)())fs_warning_level,
    pHelpString: "Set the filesystem warning level.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_warning_level_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319CA0
// Name: _dynamic_initializer_for__fs_syncdvddevcache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_syncdvddevcache_command__()
{
  ConCommand::ConCommand(
    this: &fs_syncdvddevcache_command,
    pName: "fs_syncdvddevcache",
    callback: fs_syncdvddevcache,
    pHelpString: "Force the 360 to get updated files that are in your p4 changelist(s) from the host PC when running with -dvddev.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_syncdvddevcache_command__);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100B9220
// Name: public: virtual class CPowerInfo const __near * CDispInfo::GetPowerInfo(void)const
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__thiscall CDispInfo::GetPowerInfo(CDispInfo *this)
{
  return (const CPowerInfo *)LODWORD(this->m_BaseSurfaceTexCoords[3].y);
}

//------------------------------------------------------------------------------
// Address: 0x100B9230
// Name: public: virtual class CDispNeighbor __near * CDispInfo::GetEdgeNeighbor(int)
// Source: json
//------------------------------------------------------------------------------
CDispNeighbor *__thiscall CDispInfo::GetEdgeNeighbor(CDispInfo *this, int index)
{
  return (CDispNeighbor *)((char *)&this->m_BaseSurfaceTexCoords[4] + 12 * index);
}

//------------------------------------------------------------------------------
// Address: 0x100B9250
// Name: public: virtual class CDispCornerNeighbors __near * CDispInfo::GetCornerNeighbors(int)
// Source: json
//------------------------------------------------------------------------------
CDispCornerNeighbors *__thiscall CDispInfo::GetCornerNeighbors(CDispInfo *this, int index)
{
  return (CDispCornerNeighbors *)(&this->m_EdgeNeighbors[3].m_SubNeighbors[1].m_NeighborOrientation + 10 * index);
}

//------------------------------------------------------------------------------
// Address: 0x100B9270
// Name: public: virtual class CDispUtilsHelper __near * CDispInfo::GetDispUtilsByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__thiscall CDispInfo::GetDispUtilsByIndex(CDispInfo *this, int index)
{
  int v2; // eax

  if ( index == 0xFFFF )
    return nullptr;
  v2 = *(_DWORD *)(*(_DWORD *)&this->m_Tag + 4) + 620 * index;
  if ( v2 == 0 )
    return nullptr;
  else
    return (CDispUtilsHelper *)(v2 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100B92A0
// Name: private: void CDispInfo::UpdateNodeBoundingBoxes_R(class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::UpdateNodeBoundingBoxes_R(
        CDispInfo *this,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  int v5; // eax
  DispNodeInfo_t *v6; // esi
  int v7; // ebx
  DispNodeInfo_t *v8; // ecx
  double x; // st7
  double y; // st7
  double z; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // ecx
  int v16; // eax
  unsigned int m_nIndexSize; // ecx
  unsigned __int16 *m_pIndices; // edx
  unsigned __int16 v19; // bx
  int j; // edx
  double v21; // st7
  float *v22; // ecx
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  unsigned __int16 tempIndices[4]; // [esp+0h] [ebp-8h]
  const CVertIndex *nodeIndexa; // [esp+10h] [ebp+8h]
  int iNodeBitIndexa; // [esp+14h] [ebp+Ch]
  int i; // [esp+18h] [ebp+10h]

  v5 = nodeIndex->x + this->m_pPowerInfo->m_SideLength * nodeIndex->y;
  v6 = &this->m_pNodeInfo[iNodeBitIndex];
  v6->m_maxs.x = -3.4028235e38;
  v6->m_maxs.y = -3.4028235e38;
  v6->m_maxs.z = -3.4028235e38;
  v6->m_mins.x = 3.4028235e38;
  v6->m_mins.y = 3.4028235e38;
  v6->m_mins.z = 3.4028235e38;
  if ( iLevel + 1 < this->m_Power && (v6->m_Flags & 1) != 0 )
  {
    v7 = iNodeBitIndex + 1;
    nodeIndexa = (const CVertIndex *)(16 * v5);
    for ( iNodeBitIndexa = 4; iNodeBitIndexa != 0; --iNodeBitIndexa )
    {
      CDispInfo::UpdateNodeBoundingBoxes_R(
        this,
        nodeIndex: (const CVertIndex *)((char *)nodeIndexa + (unsigned int)this->m_pPowerInfo->m_pChildVerts),
        iNodeBitIndex: v7,
        iLevel: iLevel + 1);
      v8 = &this->m_pNodeInfo[v7];
      if ( v8->m_mins.x != 3.4028235e38 )
      {
        x = v6->m_maxs.x;
        if ( v8->m_maxs.x >= x )
          x = v8->m_maxs.x;
        v6->m_maxs.x = x;
        y = v6->m_maxs.y;
        if ( v8->m_maxs.y >= y )
          y = v8->m_maxs.y;
        v6->m_maxs.y = y;
        z = v6->m_maxs.z;
        if ( v8->m_maxs.z >= z )
          z = v8->m_maxs.z;
        v6->m_maxs.z = z;
        v12 = v6->m_mins.x;
        if ( v8->m_mins.x <= v12 )
          v12 = v8->m_mins.x;
        v6->m_mins.x = v12;
        v13 = v6->m_mins.y;
        if ( v8->m_mins.y <= v13 )
          v13 = v8->m_mins.y;
        v6->m_mins.y = v13;
        v14 = v6->m_mins.z;
        if ( v8->m_mins.z <= v14 )
          v14 = v8->m_mins.z;
        v6->m_mins.z = v14;
      }
      v7 += this->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      ++nodeIndexa;
    }
  }
  v15 = 0;
  i = 0;
  if ( v6->m_Count != 0 )
  {
    do
    {
      v16 = v15 + v6->m_FirstTesselationIndex;
      m_nIndexSize = this->m_MeshReader.m_nIndexSize;
      m_pIndices = this->m_MeshReader.m_pIndices;
      tempIndices[0] = m_pIndices[v16 * m_nIndexSize] - LOWORD(this->m_iVertOffset);
      v19 = m_pIndices[m_nIndexSize * (v16 + 1)];
      LOWORD(m_pIndices) = this->m_iVertOffset;
      tempIndices[1] = v19 - (_WORD)m_pIndices;
      tempIndices[2] = this->m_MeshReader.m_pIndices[m_nIndexSize * (v16 + 2)] - (_WORD)m_pIndices;
      for ( j = 0; j < 3; ++j )
      {
        v21 = v6->m_maxs.x;
        v22 = (float *)((char *)this->m_MeshReader.m_pPosition
                      + this->m_MeshReader.m_VertexSize_Position * tempIndices[j]);
        if ( *v22 >= v21 )
          v21 = *v22;
        v6->m_maxs.x = v21;
        v23 = v6->m_maxs.y;
        if ( v22[1] >= v23 )
          v23 = v22[1];
        v6->m_maxs.y = v23;
        v24 = v6->m_maxs.z;
        if ( v22[2] >= v24 )
          v24 = v22[2];
        v6->m_maxs.z = v24;
        v25 = v6->m_mins.x;
        if ( *v22 <= v25 )
          v25 = *v22;
        v6->m_mins.x = v25;
        v26 = v6->m_mins.y;
        if ( v22[1] <= v26 )
          v26 = v22[1];
        v6->m_mins.y = v26;
        v27 = v6->m_mins.z;
        if ( v22[2] <= v27 )
          v27 = v22[2];
        v6->m_mins.z = v27;
      }
      v15 = i + 3;
      i = v15;
    }
    while ( v15 < v6->m_Count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9520
// Name: public: class Vector CDispInfo::GetFlatVert(int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CDispInfo::GetFlatVert(CDispInfo *this, Vector *result, int iVertex)
{
  int m_SideLength; // esi
  int v4; // eax
  int v5; // edx
  float v6; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float ooInt; // [esp+10h] [ebp+Ch]

  m_SideLength = this->m_pPowerInfo->m_SideLength;
  v4 = iVertex / m_SideLength;
  v5 = iVertex % m_SideLength;
  ooInt = 1.0 / (float)(m_SideLength - 1);
  v6 = (float)v4 * ooInt;
  v8 = (float)((float)(this->m_BaseSurfacePositions[1].x - this->m_BaseSurfacePositions[0].x) * v6)
     + this->m_BaseSurfacePositions[0].x;
  v9 = (float)((float)(this->m_BaseSurfacePositions[1].y - this->m_BaseSurfacePositions[0].y) * v6)
     + this->m_BaseSurfacePositions[0].y;
  v10 = (float)((float)(this->m_BaseSurfacePositions[1].z - this->m_BaseSurfacePositions[0].z) * v6)
      + this->m_BaseSurfacePositions[0].z;
  v11 = (float)((float)(this->m_BaseSurfacePositions[2].x - this->m_BaseSurfacePositions[3].x) * v6)
      + this->m_BaseSurfacePositions[3].x;
  v12 = (float)((float)(this->m_BaseSurfacePositions[2].y - this->m_BaseSurfacePositions[3].y) * v6)
      + this->m_BaseSurfacePositions[3].y;
  v13 = (float)((float)(this->m_BaseSurfacePositions[2].z - this->m_BaseSurfacePositions[3].z) * v6)
      + this->m_BaseSurfacePositions[3].z;
  v14 = (float)v5 * ooInt;
  result->x = (float)((float)(v11 - v8) * v14) + v8;
  result->y = (float)((float)(v12 - v9) * v14) + v9;
  result->z = (float)((float)(v13 - v10) * v14) + v10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B9650
// Name: public: virtual void CDispInfo::ComputeLightmapAndTextureCoordinate(struct RayDispOutput_t const __near &,class Vector2D __near *,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ComputeLightmapAndTextureCoordinate(
        CDispInfo *this,
        const RayDispOutput_t *output,
        Vector2D *luv,
        Vector2D *tuv)
{
  const RayDispOutput_t *v4; // edi
  IMaterialSystem_vtbl *v6; // ebx
  int v7; // eax
  Vector2D *v8; // eax
  __m128i v9; // xmm1
  float v10; // xmm0_4
  double v11; // st7
  int v12; // ebx
  int v13; // ecx
  float v14; // xmm3_4
  int v15; // eax
  float v16; // xmm2_4
  float v17; // xmm1_4
  int v18; // ecx
  double v19; // st7
  float v20; // xmm3_4
  float u; // [esp+Ch] [ebp-38h]
  float v; // [esp+10h] [ebp-34h]
  Vector2D baseUV[3]; // [esp+24h] [ebp-20h] BYREF
  Vector2D pt; // [esp+3Ch] [ebp-8h] BYREF

  v4 = output;
  if ( luv != nullptr )
  {
    ComputePointFromBarycentric(
      v0: (const Vector2D *)((char *)this->m_MeshReader.m_pTexCoord[1]
                       + this->m_MeshReader.m_VertexSize_TexCoord[1] * output->ndxVerts[0]),
      v1: (const Vector2D *)((char *)this->m_MeshReader.m_pTexCoord[1]
                       + this->m_MeshReader.m_VertexSize_TexCoord[1] * output->ndxVerts[1]),
      v2: (const Vector2D *)((char *)this->m_MeshReader.m_pTexCoord[1]
                       + this->m_MeshReader.m_VertexSize_TexCoord[1] * output->ndxVerts[2]),
      u: output->u,
      v: output->v,
      pt: luv);
    v6 = materials->__vftable;
    v7 = SortInfoToLightmapPage(sortID: this->m_ParentSurfID->materialSortID);
    v6->GetLightmapPageSize(this: materials, a2: v7, a3: (int *)&output, a4: (int *)&pt.y);
    v8 = luv;
    v9 = _mm_cvtsi32_si128(LODWORD(pt.y));
    v10 = (float)(int)output * luv->x;
    luv->x = v10;
    *(float *)v9.m128i_i32 = _mm_cvtepi32_ps(v9).m128_f32[0] * v8->y;
    LODWORD(v8->y) = v9.m128i_i32[0];
    v8->x = v10
          - (float)((float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
                                      + (((char *)this->m_ParentSurfID - (char *)host_state.worldbrush->surfaces2)
                                       & 0xFFFFFFE0))
                  + 0.5);
    v8->y = *(float *)v9.m128i_i32
          - (float)((float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
                                      + (((char *)this->m_ParentSurfID - (char *)host_state.worldbrush->surfaces2)
                                       & 0xFFFFFFE0))
                  + 0.5);
  }
  if ( tuv != nullptr )
  {
    v11 = v4->v;
    v12 = (1 << this->m_Power) + 1;
    v13 = v4->ndxVerts[1];
    v14 = (float)(v4->ndxVerts[0] / v12);
    v15 = v13 / v12;
    v16 = 1.0 / (float)(1 << this->m_Power);
    baseUV[0].x = (float)((float)v4->ndxVerts[0] - (float)((float)v12 * v14)) * v16;
    v17 = (float)v13;
    v18 = v4->ndxVerts[2];
    baseUV[0].y = v14 * v16;
    baseUV[1].x = (float)(v17 - (float)((float)v12 * (float)v15)) * v16;
    v = v11;
    v19 = v4->u;
    baseUV[1].y = (float)v15 * v16;
    u = v19;
    v20 = (float)(v18 / v12);
    baseUV[2].x = (float)((float)v18 - (float)((float)v12 * v20)) * v16;
    baseUV[2].y = v20 * v16;
    ComputePointFromBarycentric(v0: baseUV, v1: &baseUV[1], v2: &baseUV[2], u, v, &pt);
    TexCoordInQuadFromBarycentric(
      v1: this->m_BaseSurfaceTexCoords,
      v2: &this->m_BaseSurfaceTexCoords[3],
      v3: &this->m_BaseSurfaceTexCoords[2],
      v4: &this->m_BaseSurfaceTexCoords[1],
      uv: &pt,
      texCoord: tuv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9890
// Name: public: void CMeshBuilder::BeginModify(class IMesh __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::BeginModify(
        CMeshBuilder *this,
        IMesh *pMesh,
        int nFirstVertex,
        int nVertexCount,
        int nFirstIndex,
        int nIndexCount)
{
  if ( nVertexCount < 0 )
    nVertexCount = pMesh->VertexCount(this: pMesh);
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->ModifyBeginEx(
    this: pMesh,
    a2: false,
    a3: nFirstVertex,
    a4: nVertexCount,
    a5: nFirstIndex,
    a6: nIndexCount,
    a7: this);
  this->m_IndexBuilder.m_nIndexCount = nIndexCount;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_bModify = true;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_VertexBuilder.m_pVertexBuffer = pMesh;
  qmemcpy(&this->m_VertexBuilder, this, 0xA4u);
  this->m_VertexBuilder.m_nVertexCount = nVertexCount;
  this->m_VertexBuilder.m_nMaxVertexCount = nVertexCount;
  this->m_VertexBuilder.m_NumBoneWeights = this->m_VertexBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  this->m_VertexBuilder.m_bModify = true;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x100B9AA0
// Name: private: void CDispInfo::UpdateNodeBoundingBoxes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::UpdateNodeBoundingBoxes(CDispInfo *this)
{
  int v2; // edx
  int v3; // ecx
  Vector *p_m_mins; // eax
  Vector *p_m_maxs; // eax
  const CPowerInfo *m_pPowerInfo; // ecx
  int v7; // eax
  int x; // ecx
  DispNodeInfo_t *m_pNodeInfo; // esi
  int v10; // ebx
  int v11; // eax
  DispNodeInfo_t *v12; // ecx
  double v13; // st7
  double y; // st7
  double z; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  int v19; // ecx
  int v20; // eax
  unsigned int m_nIndexSize; // ecx
  unsigned __int16 *m_pIndices; // edx
  unsigned __int16 v23; // bx
  int j; // edx
  double v25; // st7
  float *v26; // ecx
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  int i; // [esp+0h] [ebp-Ch]
  int v33; // [esp+0h] [ebp-Ch]
  int v34; // [esp+4h] [ebp-8h]
  __int16 v35; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( this->m_pPowerInfo->m_NodeCount > 0 )
  {
    v3 = 0;
    do
    {
      p_m_mins = &this->m_pNodeInfo[v3].m_mins;
      p_m_mins->x = 3.4028235e38;
      p_m_mins->y = 3.4028235e38;
      p_m_mins->z = 3.4028235e38;
      p_m_maxs = &this->m_pNodeInfo[v3].m_maxs;
      p_m_maxs->x = -3.4028235e38;
      p_m_maxs->y = -3.4028235e38;
      p_m_maxs->z = -3.4028235e38;
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_pPowerInfo->m_NodeCount );
  }
  m_pPowerInfo = this->m_pPowerInfo;
  v7 = m_pPowerInfo->m_SideLength * m_pPowerInfo->m_RootNode.y;
  x = m_pPowerInfo->m_RootNode.x;
  m_pNodeInfo = this->m_pNodeInfo;
  m_pNodeInfo->m_maxs.x = -3.4028235e38;
  m_pNodeInfo->m_maxs.y = -3.4028235e38;
  m_pNodeInfo->m_maxs.z = -3.4028235e38;
  v10 = 1;
  v11 = x + v7;
  m_pNodeInfo->m_mins.x = 3.4028235e38;
  m_pNodeInfo->m_mins.y = 3.4028235e38;
  m_pNodeInfo->m_mins.z = 3.4028235e38;
  if ( this->m_Power > 1 && (m_pNodeInfo->m_Flags & 1) != 0 )
  {
    v34 = 16 * v11;
    for ( i = 4; i != 0; --i )
    {
      CDispInfo::UpdateNodeBoundingBoxes_R(
        this,
        nodeIndex: (const CVertIndex *)((char *)this->m_pPowerInfo->m_pChildVerts->m_Verts + v34),
        iNodeBitIndex: v10,
        iLevel: 1);
      v12 = &this->m_pNodeInfo[v10];
      if ( v12->m_mins.x != 3.4028235e38 )
      {
        v13 = m_pNodeInfo->m_maxs.x;
        if ( v12->m_maxs.x >= v13 )
          v13 = v12->m_maxs.x;
        m_pNodeInfo->m_maxs.x = v13;
        y = m_pNodeInfo->m_maxs.y;
        if ( v12->m_maxs.y >= y )
          y = v12->m_maxs.y;
        m_pNodeInfo->m_maxs.y = y;
        z = m_pNodeInfo->m_maxs.z;
        if ( v12->m_maxs.z >= z )
          z = v12->m_maxs.z;
        m_pNodeInfo->m_maxs.z = z;
        v16 = m_pNodeInfo->m_mins.x;
        if ( v12->m_mins.x <= v16 )
          v16 = v12->m_mins.x;
        m_pNodeInfo->m_mins.x = v16;
        v17 = m_pNodeInfo->m_mins.y;
        if ( v12->m_mins.y <= v17 )
          v17 = v12->m_mins.y;
        m_pNodeInfo->m_mins.y = v17;
        v18 = m_pNodeInfo->m_mins.z;
        if ( v12->m_mins.z <= v18 )
          v18 = v12->m_mins.z;
        m_pNodeInfo->m_mins.z = v18;
      }
      v10 += this->m_pPowerInfo->m_NodeIndexIncrements[0];
      v34 += 4;
    }
  }
  v19 = 0;
  v33 = 0;
  if ( m_pNodeInfo->m_Count != 0 )
  {
    do
    {
      v20 = v19 + m_pNodeInfo->m_FirstTesselationIndex;
      m_nIndexSize = this->m_MeshReader.m_nIndexSize;
      m_pIndices = this->m_MeshReader.m_pIndices;
      LOWORD(v34) = m_pIndices[v20 * m_nIndexSize] - LOWORD(this->m_iVertOffset);
      v23 = m_pIndices[m_nIndexSize * (v20 + 1)];
      LOWORD(m_pIndices) = this->m_iVertOffset;
      HIWORD(v34) = v23 - (_WORD)m_pIndices;
      v35 = this->m_MeshReader.m_pIndices[m_nIndexSize * (v20 + 2)] - (_WORD)m_pIndices;
      for ( j = 0; j < 3; ++j )
      {
        v25 = m_pNodeInfo->m_maxs.x;
        v26 = (float *)((char *)this->m_MeshReader.m_pPosition
                      + this->m_MeshReader.m_VertexSize_Position * *((unsigned __int16 *)&v34 + j));
        if ( *v26 >= v25 )
          v25 = *v26;
        m_pNodeInfo->m_maxs.x = v25;
        v27 = m_pNodeInfo->m_maxs.y;
        if ( v26[1] >= v27 )
          v27 = v26[1];
        m_pNodeInfo->m_maxs.y = v27;
        v28 = m_pNodeInfo->m_maxs.z;
        if ( v26[2] >= v28 )
          v28 = v26[2];
        m_pNodeInfo->m_maxs.z = v28;
        v29 = m_pNodeInfo->m_mins.x;
        if ( *v26 <= v29 )
          v29 = *v26;
        m_pNodeInfo->m_mins.x = v29;
        v30 = m_pNodeInfo->m_mins.y;
        if ( v26[1] <= v30 )
          v30 = v26[1];
        m_pNodeInfo->m_mins.y = v30;
        v31 = m_pNodeInfo->m_mins.z;
        if ( v26[2] <= v31 )
          v31 = v26[2];
        m_pNodeInfo->m_mins.z = v31;
      }
      v19 = v33 + 3;
      v33 = v19;
    }
    while ( v19 < m_pNodeInfo->m_Count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9D50
// Name: public: void CDispInfo::InitializeActiveVerts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::InitializeActiveVerts(CDispInfo *this)
{
  CBitVec<289> *p_m_ActiveVerts; // ecx
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  const CPowerInfo *m_pPowerInfo; // esi
  int v8; // ecx
  int v9; // edx
  const CPowerInfo *v10; // esi
  int v11; // ecx
  int v12; // edx
  const CPowerInfo *v13; // esi
  int v14; // ecx
  int v15; // edx
  const CPowerInfo *v16; // esi
  int v17; // ecx
  unsigned int *v18; // eax
  CVertIndex nodeIndex; // [esp+0h] [ebp-4h]

  nodeIndex = (CVertIndex)this;
  p_m_ActiveVerts = &this->m_ActiveVerts;
  if ( p_m_ActiveVerts != nullptr )
  {
    p_m_ActiveVerts->m_Ints[0] = 0;
    p_m_ActiveVerts->m_Ints[1] = 0;
    p_m_ActiveVerts->m_Ints[2] = 0;
    p_m_ActiveVerts->m_Ints[3] = 0;
    p_m_ActiveVerts->m_Ints[4] = 0;
    p_m_ActiveVerts->m_Ints[5] = 0;
    p_m_ActiveVerts->m_Ints[6] = 0;
    p_m_ActiveVerts->m_Ints[7] = 0;
    p_m_ActiveVerts->m_Ints[8] = 0;
    p_m_ActiveVerts->m_Ints[9] = 0;
  }
  p_m_ActiveVerts->m_Ints[0] |= 1u;
  v3 = this->m_pPowerInfo->m_SideLength - 1;
  this->m_ActiveVerts.m_Ints[v3 >> 5] |= 1 << (v3 & 0x1F);
  v4 = this->m_pPowerInfo->m_SideLength * this->m_pPowerInfo->m_SideLength - 1;
  this->m_ActiveVerts.m_Ints[v4 >> 5] |= 1 << (v4 & 0x1F);
  v5 = this->m_pPowerInfo->m_SideLength * (this->m_pPowerInfo->m_SideLength - 1);
  this->m_ActiveVerts.m_Ints[v5 >> 5] |= 1 << (v5 & 0x1F);
  v6 = this->m_pPowerInfo->m_RootNode.x + this->m_pPowerInfo->m_SideLength * this->m_pPowerInfo->m_RootNode.y;
  this->m_ActiveVerts.m_Ints[v6 >> 5] |= 1 << (v6 & 0x1F);
  if ( this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_Span != 0
    || this->m_EdgeNeighbors[0].m_SubNeighbors[1].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[0].m_SubNeighbors[1].m_Span != 0 )
  {
    m_pPowerInfo = this->m_pPowerInfo;
    v8 = g_EdgeDims[0];
    *(&nodeIndex.x + SLOWORD(g_EdgeDims[0])) = LOWORD(g_EdgeSideLenMul[0]) * LOWORD(m_pPowerInfo->m_SideLengthM1);
    *(&nodeIndex.x + (v8 == 0)) = m_pPowerInfo->m_MidPoint;
    v9 = nodeIndex.x + m_pPowerInfo->m_SideLength * nodeIndex.y;
    this->m_ActiveVerts.m_Ints[v9 >> 5] |= 1 << ((LOBYTE(nodeIndex.x)
                                                + LOBYTE(m_pPowerInfo->m_SideLength) * LOBYTE(nodeIndex.y))
                                               & 0x1F);
  }
  if ( this->m_EdgeNeighbors[1].m_SubNeighbors[0].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[1].m_SubNeighbors[0].m_Span != 0
    || this->m_EdgeNeighbors[1].m_SubNeighbors[1].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[1].m_SubNeighbors[1].m_Span != 0 )
  {
    v10 = this->m_pPowerInfo;
    v11 = dword_104196CC;
    *(&nodeIndex.x + (__int16)dword_104196CC) = word_10419748 * LOWORD(v10->m_SideLengthM1);
    *(&nodeIndex.x + (v11 == 0)) = v10->m_MidPoint;
    v12 = nodeIndex.x + v10->m_SideLength * nodeIndex.y;
    this->m_ActiveVerts.m_Ints[v12 >> 5] |= 1 << ((LOBYTE(nodeIndex.x) + LOBYTE(v10->m_SideLength) * LOBYTE(nodeIndex.y))
                                                & 0x1F);
  }
  if ( this->m_EdgeNeighbors[2].m_SubNeighbors[0].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[2].m_SubNeighbors[0].m_Span != 0
    || this->m_EdgeNeighbors[2].m_SubNeighbors[1].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[2].m_SubNeighbors[1].m_Span != 0 )
  {
    v13 = this->m_pPowerInfo;
    v14 = dword_104196D0;
    *(&nodeIndex.x + (__int16)dword_104196D0) = word_1041974C * LOWORD(v13->m_SideLengthM1);
    *(&nodeIndex.x + (v14 == 0)) = v13->m_MidPoint;
    v15 = nodeIndex.x + v13->m_SideLength * nodeIndex.y;
    this->m_ActiveVerts.m_Ints[v15 >> 5] |= 1 << ((LOBYTE(nodeIndex.x) + LOBYTE(v13->m_SideLength) * LOBYTE(nodeIndex.y))
                                                & 0x1F);
  }
  if ( this->m_EdgeNeighbors[3].m_SubNeighbors[0].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[3].m_SubNeighbors[0].m_Span != 0
    || this->m_EdgeNeighbors[3].m_SubNeighbors[1].m_iNeighbor != 0xFFFF
    && this->m_EdgeNeighbors[3].m_SubNeighbors[1].m_Span != 0 )
  {
    v16 = this->m_pPowerInfo;
    v17 = dword_104196D4;
    *(&nodeIndex.x + (__int16)dword_104196D4) = word_10419750 * LOWORD(v16->m_SideLengthM1);
    *(&nodeIndex.x + (v17 == 0)) = v16->m_MidPoint;
    v18 = &this->m_ActiveVerts.m_Ints[(nodeIndex.x + v16->m_SideLength * nodeIndex.y) >> 5];
    *v18 |= 1 << ((LOBYTE(nodeIndex.x) + LOBYTE(v16->m_SideLength) * LOBYTE(nodeIndex.y)) & 0x1F);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA030
// Name: bool DispInfoRenderDebugModes(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DispInfoRenderDebugModes()
{
  int m_nValue; // eax
  bool result; // al

  result = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
        && (mat_wireframe.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
            m_nValue != 0)
        || mat_luxels.m_pParent != nullptr && mat_luxels.m_pParent->m_Value.m_nValue != 0
        || r_DispWalkable.m_pParent != nullptr && r_DispWalkable.m_pParent->m_Value.m_nValue != 0
        || r_DispBuildable.m_pParent != nullptr && r_DispBuildable.m_pParent->m_Value.m_nValue != 0
        || mat_surfaceid.m_pParent != nullptr && mat_surfaceid.m_pParent->m_Value.m_nValue != 0
        || mat_surfacemat.m_pParent != nullptr && mat_surfacemat.m_pParent->m_Value.m_nValue != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BA0C0
// Name: ProcessLightmapSample
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessLightmapSample(
        const ProcessLightmapSampleData_t *data,
        const Vector *vPos,
        const Vector *vNormal,
        const Vector *vTangentS,
        const Vector *vTangentT,
        int t,
        int s,
        int tmax,
        int smax)
{
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  int v12; // eax
  float v13; // xmm0_4
  float *p_x; // eax

  v9 = (float)((float)((float)(data->m_vLightOrigin.y - vPos->y) * (float)(data->m_vLightOrigin.y - vPos->y))
             + (float)((float)(data->m_vLightOrigin.x - vPos->x) * (float)(data->m_vLightOrigin.x - vPos->x)))
     + (float)((float)(data->m_vLightOrigin.z - vPos->z) * (float)(data->m_vLightOrigin.z - vPos->z));
  if ( data->m_LightDistSqr > v9 )
  {
    if ( v9 == 0.0 )
      v10 = 1.0;
    else
      v10 = data->m_ooQuadraticAttn / v9;
    v11 = (float)(1.0 - (float)(data->m_ooRadiusSq * v9)) * v10;
    if ( v11 > 2.0 )
      v11 = 2.0;
    v12 = s + smax * t;
    v13 = (float)(data->m_Intensity.x * v11) + blocklights[0][v12].x;
    p_x = &blocklights[0][v12].x;
    *p_x = v13;
    p_x[1] = (float)(data->m_Intensity.y * v11) + p_x[1];
    p_x[2] = (float)(data->m_Intensity.z * v11) + p_x[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA1A0
// Name: ProcessLightmapSampleBumped
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessLightmapSampleBumped(
        const ProcessLightmapSampleData_t *data,
        const Vector *vPos,
        const Vector *vNormal,
        const Vector *vTangentS,
        const Vector *vTangentT,
        int t,
        int s,
        int tmax,
        int smax)
{
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float y; // xmm0_4
  float x; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  double z; // st7
  double v20; // st5
  unsigned int v21; // ecx
  double v22; // st5
  double v23; // st5
  double v24; // st7
  double v25; // st5
  double v26; // st4
  double v27; // st3
  double v28; // st2
  double v29; // st6
  double v30; // st2
  double v31; // st3
  double v32; // st2
  double v33; // st6
  double v34; // st2
  double v35; // st6
  double v36; // st7
  Vector vLightVecTangent; // [esp+4h] [ebp-Ch] BYREF
  float scale; // [esp+18h] [ebp+8h]
  float scalea; // [esp+18h] [ebp+8h]
  float distSqr; // [esp+1Ch] [ebp+Ch]

  v10 = data->m_vLightOrigin.x - vPos->x;
  v11 = data->m_vLightOrigin.y - vPos->y;
  v12 = data->m_vLightOrigin.z - vPos->z;
  v13 = (float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v12 * v12);
  distSqr = v13;
  if ( data->m_LightDistSqr > v13 )
  {
    if ( v13 == 0.0 )
      scale = 1.0;
    else
      scale = data->m_ooQuadraticAttn / v13;
    vLightVecTangent.x = v10;
    vLightVecTangent.y = v11;
    vLightVecTangent.z = v12;
    VectorNormalize(vec: &vLightVecTangent);
    y = vLightVecTangent.y;
    x = vLightVecTangent.x;
    v16 = vTangentT->x;
    vLightVecTangent.x = (float)((float)(vTangentS->y * vLightVecTangent.y) + (float)(vTangentS->x * vLightVecTangent.x))
                       + (float)(vTangentS->z * vLightVecTangent.z);
    vLightVecTangent.y = (float)((float)(vTangentT->y * vLightVecTangent.y) + (float)(v16 * x))
                       + (float)(vTangentT->z * vLightVecTangent.z);
    v17 = (float)((float)(vNormal->y * y) + (float)(vNormal->x * x)) + (float)(vNormal->z * vLightVecTangent.z);
    v18 = (float)(1.0 - (float)(data->m_ooRadiusSq * distSqr)) * scale;
    vLightVecTangent.z = v17;
    scalea = v18;
    if ( v18 > 2.0 )
      scalea = 2.0;
    z = vLightVecTangent.z;
    v20 = 0.0;
    if ( vLightVecTangent.z > 0.0 )
      v20 = vLightVecTangent.z;
    v21 = 4 * (s + smax * t);
    v22 = v20 * scalea;
    blocklights[0][v21 / 4].x = data->m_Intensity.x * v22 + blocklights[0][v21 / 4].x;
    *(float *)&dword_104F1D84[v21] = v22 * data->m_Intensity.y + *(float *)&dword_104F1D84[v21];
    *(float *)&dword_104F1D88[v21] = v22 * data->m_Intensity.z + *(float *)&dword_104F1D88[v21];
    v23 = z;
    v24 = scalea;
    v25 = v23 * 0.57735026;
    v26 = vLightVecTangent.y;
    v27 = vLightVecTangent.x;
    v28 = 0.0;
    v29 = 0.0 * vLightVecTangent.y + 0.81649661 * vLightVecTangent.x + v25;
    if ( v29 > 0.0 )
      v28 = v29;
    v30 = v28 * v24;
    flt_10531D80[v21] = data->m_Intensity.x * v30 + flt_10531D80[v21];
    flt_10531D84[v21] = v30 * data->m_Intensity.y + flt_10531D84[v21];
    flt_10531D88[v21] = v30 * data->m_Intensity.z + flt_10531D88[v21];
    v31 = v27 * -0.40824822;
    v32 = 0.0;
    v33 = v26 * 0.70710677 + v31 + v25;
    if ( v33 > 0.0 )
      v32 = v33;
    v34 = v32 * v24;
    flt_10571D80[v21] = data->m_Intensity.x * v34 + flt_10571D80[v21];
    flt_10571D84[v21] = v34 * data->m_Intensity.y + flt_10571D84[v21];
    flt_10571D88[v21] = v34 * data->m_Intensity.z + flt_10571D88[v21];
    v35 = v25 + v31 - v26 * 0.70710677;
    if ( v35 <= 0.0 )
      v35 = 0.0;
    v36 = v24 * v35;
    *(float *)&dword_105B1D80[v21] = data->m_Intensity.x * v36 + *(float *)&dword_105B1D80[v21];
    *(float *)&dword_105B1D84[v21] = v36 * data->m_Intensity.y + *(float *)&dword_105B1D84[v21];
    *(float *)&dword_105B1D88[v21] = v36 * data->m_Intensity.z + *(float *)&dword_105B1D88[v21];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA470
// Name: ProcessLightmapSampleAlpha
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessLightmapSampleAlpha(
        const ProcessLightmapSampleData_t *data,
        const Vector *vPos,
        const Vector *vNormal,
        const Vector *vTangentS,
        const Vector *vTangentT,
        int t,
        int s,
        int tmax,
        int smax)
{
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4

  v9 = (float)((float)((float)(data->m_vLightOrigin.y - vPos->y) * (float)(data->m_vLightOrigin.y - vPos->y))
             + (float)((float)(data->m_vLightOrigin.x - vPos->x) * (float)(data->m_vLightOrigin.x - vPos->x)))
     + (float)((float)(data->m_vLightOrigin.z - vPos->z) * (float)(data->m_vLightOrigin.z - vPos->z));
  if ( data->m_LightDistSqr > v9 )
  {
    if ( v9 == 0.0 )
      v10 = 1.0;
    else
      v10 = data->m_ooQuadraticAttn / v9;
    v11 = (float)(1.0 - (float)(data->m_ooRadiusSq * v9)) * v10;
    if ( v11 > 1.0 )
      v11 = 1.0;
    dword_104F1D8C[4 * s + 4 * smax * t] = (float)(data->m_Intensity.x * v11) + dword_104F1D8C[4 * s + 4 * smax * t];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA520
// Name: public: virtual bool CDispInfo::TestRay(struct Ray_t const __near &,float,float,float __near &,class Vector2D __near *,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDispInfo::TestRay@<al>(
        CDispInfo *this@<ecx>,
        float a2@<ebp>,
        const Ray_t *ray,
        float start,
        float end,
        float *dist,
        Vector2D *luv,
        Vector2D *tuv)
{
  int v9; // eax
  CDispCollTree *CollisionTree; // ecx
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  _DWORD v17[3]; // [esp-Ch] [ebp-7Ch] BYREF
  Ray_t shortenedRay; // [esp+0h] [ebp-70h] BYREF
  _BYTE v19[12]; // [esp+50h] [ebp-20h] BYREF
  RayDispOutput_t output; // [esp+5Ch] [ebp-14h]
  float retaddr; // [esp+70h] [ebp+0h]

  output.u = a2;
  output.v = retaddr;
  v9 = DispInfo_ComputeIndex(hArray: host_state.worldbrush->hDispInfos, pInfo: this);
  CollisionTree = CollisionBSPData_GetCollisionTree(i: v9);
  if ( CollisionTree == nullptr )
    return 0;
  v11 = (float)(ray->m_Delta.x * start) + ray->m_Start.x;
  v12 = (float)(ray->m_Delta.y * start) + ray->m_Start.y;
  v13 = (float)(ray->m_Delta.z * start) + ray->m_Start.z;
  v14 = (float)(ray->m_Delta.z * end) + ray->m_Start.z;
  v15 = (float)((float)(ray->m_Delta.x * end) + ray->m_Start.x) - v11;
  shortenedRay.m_Start.z = (float)((float)(ray->m_Delta.y * end) + ray->m_Start.y) - v12;
  shortenedRay.m_Start.y = v15;
  shortenedRay.m_Start.w = v14 - v13;
  BYTE1(shortenedRay.m_Extents.z) = (float)((float)((float)(shortenedRay.m_Start.z * shortenedRay.m_Start.z)
                                                  + (float)(v15 * v15))
                                          + (float)(shortenedRay.m_Start.w * shortenedRay.m_Start.w)) != 0.0;
  shortenedRay.m_Extents.y = 0.0;
  memset(&shortenedRay.m_StartOffset.y, 0, 12);
  memset(&shortenedRay.m_Delta.y, 0, 12);
  LOBYTE(shortenedRay.m_Extents.z) = 1;
  *(float *)v17 = v11;
  *(float *)&v17[1] = v12;
  *(float *)&v17[2] = v13;
  *(_DWORD *)&output.ndxVerts[2] = 1065353216;
  if ( !CDispCollTree::AABBTree_Ray(this: CollisionTree, ray: (const Ray_t *)v17, output: (RayDispOutput_t *)v19) )
    return 0;
  *dist = (float)((float)(1.0 - *(float *)&output.ndxVerts[2]) * start) + (float)(*(float *)&output.ndxVerts[2] * end);
  this->ComputeLightmapAndTextureCoordinate(this, a2: (const RayDispOutput_t *)v19, a3: luv, a4: tuv);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BA6A0
// Name: public: void CDispInfo::UpdateBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::UpdateBoundingBox(CDispInfo *this)
{
  const CPowerInfo *m_pPowerInfo; // edi
  int v2; // esi
  double x; // st7
  float *v4; // edx
  double y; // st7
  double z; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7

  this->m_BBoxMin.x = 1.0e24;
  this->m_BBoxMin.y = 1.0e24;
  this->m_BBoxMin.z = 1.0e24;
  m_pPowerInfo = this->m_pPowerInfo;
  v2 = 0;
  this->m_BBoxMax.x = -1.0e24;
  this->m_BBoxMax.y = -1.0e24;
  for ( this->m_BBoxMax.z = -1.0e24; v2 < m_pPowerInfo->m_MaxVerts; this->m_BBoxMax.z = v9 )
  {
    x = this->m_BBoxMin.x;
    v4 = (float *)((char *)this->m_MeshReader.m_pPosition + v2 * this->m_MeshReader.m_VertexSize_Position);
    if ( *v4 <= x )
      x = *v4;
    this->m_BBoxMin.x = x;
    y = this->m_BBoxMin.y;
    if ( v4[1] <= y )
      y = v4[1];
    this->m_BBoxMin.y = y;
    z = this->m_BBoxMin.z;
    if ( v4[2] <= z )
      z = v4[2];
    this->m_BBoxMin.z = z;
    v7 = this->m_BBoxMax.x;
    if ( *v4 >= v7 )
      v7 = *v4;
    this->m_BBoxMax.x = v7;
    v8 = this->m_BBoxMax.y;
    if ( v4[1] >= v8 )
      v8 = v4[1];
    this->m_BBoxMax.y = v8;
    v9 = this->m_BBoxMax.z;
    if ( v4[2] >= v9 )
      v9 = v4[2];
    ++v2;
  }
  CDispInfo::UpdateNodeBoundingBoxes(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BA770
// Name: private: void CDispInfo::TestAddDecalTri(int,unsigned short,class CDispDecal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::TestAddDecalTri(
        CDispInfo *this,
        int iIndexStart,
        unsigned __int16 decalHandle,
        decal_t *pDispDecal)
{
  unsigned __int16 *m_pIndices; // ecx
  unsigned int m_nIndexSize; // eax
  __int16 m_iVertOffset; // di
  int m_VertexSize_Position; // ecx
  float *v10; // edi
  float *v11; // eax
  float *v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  int v19; // ecx
  float *m_pPosition; // edi
  float v21; // xmm5_4
  int v22; // edi
  float *v23; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  decal_t *x_low; // eax
  float v27; // xmm0_4
  float v28; // xmm1_4
  float *v29; // eax
  float v30; // xmm5_4
  float *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm1_4
  decal_t *v34; // eax
  float v35; // xmm1_4
  float *v36; // edi
  float v37; // xmm0_4
  float v38; // xmm1_4
  int v39; // edi
  int clippedVertCount; // eax
  CDispDecalFragment *DispDecalFragment; // eax
  int v42; // ebx
  int v43; // ecx
  int v44; // edx
  unsigned int v45; // ebx
  float *v46; // ecx
  CDecalVert *m_pVerts; // edi
  char *v48; // edx
  float *v49; // edi
  float *v50; // edi
  float *v51; // edi
  float *v52; // edi
  float *v53; // edi
  float *v54; // edi
  float *v55; // edi
  float *v56; // edi
  float *v57; // edi
  float *v58; // edi
  float *v59; // edx
  double v60; // st7
  int v61; // edx
  int v62; // ecx
  int v63; // ebx
  int v64; // edi
  CDecalVert *v65; // edx
  float *v66; // edx
  float *v67; // edx
  CDecalVert verts[3]; // [esp+Ch] [ebp-80h] BYREF
  Vector vNormal; // [esp+6Ch] [ebp-20h] BYREF
  unsigned __int16 tempIndices[4]; // [esp+78h] [ebp-14h]
  int v71; // [esp+80h] [ebp-Ch]
  int v72; // [esp+84h] [ebp-8h]
  int i; // [esp+88h] [ebp-4h]
  int outCount; // [esp+94h] [ebp+8h]
  int outCounta; // [esp+94h] [ebp+8h]
  int iVert; // [esp+98h] [ebp+Ch]
  decal_t *pDecal; // [esp+9Ch] [ebp+10h]

  m_pIndices = this->m_MeshReader.m_pIndices;
  pDecal = (decal_t *)LODWORD(pDispDecal->position.x);
  m_nIndexSize = this->m_MeshReader.m_nIndexSize;
  m_iVertOffset = this->m_iVertOffset;
  tempIndices[0] = m_pIndices[iIndexStart * m_nIndexSize] - m_iVertOffset;
  tempIndices[1] = m_pIndices[m_nIndexSize * (iIndexStart + 1)] - m_iVertOffset;
  tempIndices[2] = m_pIndices[m_nIndexSize * (iIndexStart + 2)] - m_iVertOffset;
  m_VertexSize_Position = this->m_MeshReader.m_VertexSize_Position;
  v10 = (float *)((char *)this->m_MeshReader.m_pPosition + tempIndices[0] * m_VertexSize_Position);
  i = tempIndices[0];
  v11 = (float *)((char *)this->m_MeshReader.m_pPosition + tempIndices[1] * m_VertexSize_Position);
  outCount = tempIndices[1];
  v12 = (float *)((char *)this->m_MeshReader.m_pPosition + tempIndices[2] * m_VertexSize_Position);
  v13 = v11[1] - v10[1];
  v14 = v12[1] - v10[1];
  v15 = v11[2] - v10[2];
  v16 = v12[2] - v10[2];
  v17 = *v11 - *v10;
  v18 = *v12 - *v10;
  v72 = tempIndices[2];
  vNormal.x = (float)(v14 * v15) - (float)(v13 * v16);
  vNormal.y = (float)(v16 * v17) - (float)(v15 * v18);
  vNormal.z = (float)(v13 * v18) - (float)(v14 * v17);
  VectorNormalize(vec: &vNormal);
  if ( (float)((float)((float)((float)(pDecal->position.y - v10[1]) * vNormal.y)
                     + (float)((float)(pDecal->position.x - *v10) * vNormal.x))
             + (float)((float)(pDecal->position.z - v10[2]) * vNormal.z)) < *(float *)&pDispDecal->color )
  {
    v19 = this->m_MeshReader.m_VertexSize_Position;
    m_pPosition = this->m_MeshReader.m_pPosition;
    verts[0].m_vPos.x = *(float *)((char *)m_pPosition + i * v19);
    verts[0].m_vPos.y = *(float *)((char *)m_pPosition + i * v19 + 4);
    v21 = *(float *)((char *)m_pPosition + i * v19 + 8);
    v22 = this->m_MeshReader.m_VertexSize_TexCoord[1];
    v23 = (float *)((char *)this->m_MeshReader.m_pTexCoord[1] + i * v22);
    verts[0].m_vPos.z = v21;
    v24 = v23[1];
    verts[0].m_cLMCoords.x = *v23;
    v25 = pDispDecal->saxis.x * verts[0].m_vPos.x;
    x_low = (decal_t *)LODWORD(pDispDecal->position.x);
    verts[0].m_cLMCoords.y = v24;
    v27 = (float)((float)((float)(pDispDecal->saxis.y * verts[0].m_vPos.y) + v25) + (float)(pDispDecal->saxis.z * v21))
        - x_low->dx;
    v28 = (float)((float)((float)(pDispDecal->dy * verts[0].m_vPos.y) + (float)(pDispDecal->dx * verts[0].m_vPos.x))
                + (float)(pDispDecal->scale * v21))
        - x_low->dy;
    v29 = (float *)((char *)this->m_MeshReader.m_pPosition + outCount * v19);
    verts[0].m_ctCoords.y = v28 + 0.5;
    verts[0].m_ctCoords.x = v27 + 0.5;
    verts[1].m_vPos.x = *v29;
    verts[1].m_vPos.y = v29[1];
    v30 = v29[2];
    v31 = (float *)((char *)this->m_MeshReader.m_pTexCoord[1] + outCount * v22);
    verts[1].m_vPos.z = v30;
    v32 = v31[1];
    v33 = *v31;
    v34 = (decal_t *)LODWORD(pDispDecal->position.x);
    verts[1].m_cLMCoords.x = v33;
    verts[1].m_cLMCoords.y = v32;
    v35 = (float)((float)((float)((float)(pDispDecal->dy * verts[1].m_vPos.y)
                                + (float)(verts[1].m_vPos.x * pDispDecal->dx))
                        + (float)(pDispDecal->scale * v30))
                - v34->dy)
        + 0.5;
    verts[1].m_ctCoords.x = (float)((float)((float)((float)(pDispDecal->saxis.y * verts[1].m_vPos.y)
                                                  + (float)(verts[1].m_vPos.x * pDispDecal->saxis.x))
                                          + (float)(pDispDecal->saxis.z * v30))
                                  - v34->dx)
                          + 0.5;
    verts[1].m_ctCoords.y = v35;
    v36 = (float *)((char *)this->m_MeshReader.m_pTexCoord[1] + v72 * v22);
    verts[2].m_vPos = *(Vector *)((char *)this->m_MeshReader.m_pPosition + v72 * v19);
    v37 = v36[1];
    verts[2].m_cLMCoords.x = *v36;
    verts[2].m_cLMCoords.y = v37;
    v38 = (float)((float)((float)((float)(pDispDecal->dy * verts[2].m_vPos.y)
                                + (float)(verts[2].m_vPos.x * pDispDecal->dx))
                        + (float)(pDispDecal->scale * verts[2].m_vPos.z))
                - v34->dy)
        + 0.5;
    verts[2].m_ctCoords.x = (float)((float)((float)((float)(pDispDecal->saxis.y * verts[2].m_vPos.y)
                                                  + (float)(verts[2].m_vPos.x * pDispDecal->saxis.x))
                                          + (float)(pDispDecal->saxis.z * verts[2].m_vPos.z))
                                  - v34->dx)
                          + 0.5;
    verts[2].m_ctCoords.y = v38;
    v39 = R_DoDecalSHClip(pInVerts: verts, pOutVerts: nullptr, pDecal, nStartVerts: 3, vecNormal: &vec3_origin);
    clippedVertCount = pDecal->clippedVertCount;
    *(_DWORD *)tempIndices = v39;
    outCounta = clippedVertCount;
    if ( (unsigned int)clippedVertCount > 2 )
    {
      if ( clippedVertCount >= 6 )
      {
        outCounta = 6;
        clippedVertCount = 6;
      }
      DispDecalFragment = CDispInfo::AllocateDispDecalFragment(this, h: decalHandle, nVerts: clippedVertCount);
      v42 = outCounta;
      v43 = 0;
      iVert = 0;
      if ( outCounta >= 4 )
      {
        v72 = 36 - v39;
        v71 = 68 - v39;
        v44 = -28 - v39;
        v45 = ((unsigned int)(outCounta - 4) >> 2) + 1;
        v46 = (float *)(v39 + 28);
        i = -28 - v39;
        iVert = 4 * v45;
        while ( 1 )
        {
          m_pVerts = DispDecalFragment->m_pVerts;
          v48 = (char *)v46 + v44;
          *(float *)&v48[(_DWORD)m_pVerts] = *(v46 - 7);
          *(float *)&v48[(_DWORD)m_pVerts + 4] = *(v46 - 6);
          *(float *)&v48[(_DWORD)m_pVerts + 8] = *(v46 - 5);
          v49 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 16];
          *v49 = *(v46 - 3);
          v49[1] = *(v46 - 2);
          v50 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 24];
          *v50 = *(v46 - 1);
          v50[1] = *v46;
          v51 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 32];
          *v51 = v46[1];
          v51[1] = v46[2];
          v51[2] = v46[3];
          v52 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 48];
          *v52 = v46[5];
          v52[1] = v46[6];
          v53 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 56];
          *v53 = v46[7];
          v53[1] = v46[8];
          v54 = (float *)((char *)&DispDecalFragment->m_pVerts->m_vPos.x + (unsigned int)v46 + v72);
          *v54 = v46[9];
          v54[1] = v46[10];
          v54[2] = v46[11];
          v55 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 80];
          *v55 = v46[13];
          v55[1] = v46[14];
          v56 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 88];
          *v56 = v46[15];
          v56[1] = v46[16];
          v57 = (float *)((char *)&DispDecalFragment->m_pVerts->m_vPos.x + (unsigned int)v46 + v71);
          *v57 = v46[17];
          v57[1] = v46[18];
          v57[2] = v46[19];
          v58 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 112];
          *v58 = v46[21];
          v58[1] = v46[22];
          v59 = (float *)&v48[(unsigned int)DispDecalFragment->m_pVerts + 120];
          *v59 = v46[23];
          v60 = v46[24];
          v46 += 32;
          v59[1] = v60;
          if ( --v45 == 0 )
            break;
          v44 = i;
        }
        v39 = *(_DWORD *)tempIndices;
        v42 = outCounta;
        v43 = iVert;
      }
      if ( v43 < v42 )
      {
        v61 = -28 - v39;
        v62 = v39 + 32 * v43 + 28;
        v63 = v42 - iVert;
        for ( i = -28 - v39; ; v61 = i )
        {
          v64 = v62 + v61;
          v65 = DispDecalFragment->m_pVerts;
          *(float *)((char *)&v65->m_vPos.x + v64) = *(float *)(v62 - 28);
          v62 += 32;
          --v63;
          *(float *)((char *)&v65->m_vPos.y + v64) = *(float *)(v62 - 56);
          *(float *)((char *)&v65->m_vPos.z + v64) = *(float *)(v62 - 52);
          v66 = (float *)((char *)&DispDecalFragment->m_pVerts->m_ctCoords.x + v64);
          *v66 = *(float *)(v62 - 44);
          v66[1] = *(float *)(v62 - 40);
          v67 = (float *)((char *)&DispDecalFragment->m_pVerts->m_cLMCoords.x + v64);
          *v67 = *(float *)(v62 - 36);
          v67[1] = *(float *)(v62 - 32);
          if ( v63 == 0 )
            break;
        }
        LOBYTE(v42) = outCounta;
      }
      DispDecalFragment->m_pDecal = pDecal;
      DispDecalFragment->m_nVerts = v42;
      HIWORD(pDispDecal->material) += (unsigned __int8)v42;
      LOWORD(pDispDecal->lightmapOffset) += DispDecalFragment->m_nVerts - 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAD00
// Name: private: void CDispInfo::TestAddDecalTri(int,unsigned short,class CDispShadowDecal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::TestAddDecalTri(
        CDispInfo *this,
        ShadowVertex_t **iIndexStart,
        unsigned __int16 decalHandle,
        CDispShadowDecal *pDecal)
{
  unsigned int m_nIndexSize; // eax
  unsigned __int16 *m_pIndices; // ecx
  __int16 m_iVertOffset; // dx
  unsigned __int16 v8; // di
  unsigned __int16 v9; // bx
  int v10; // ecx
  float *m_pNormal; // edi
  unsigned __int16 v12; // bx
  int m_VertexSize_Normal; // edx
  float v14; // xmm2_4
  float v15; // xmm3_4
  float *v16; // eax
  float v17; // xmm1_4
  float *v18; // ecx
  int v19; // eax
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  int v23; // eax
  float *v24; // ecx
  float v25; // xmm2_4
  float v26; // xmm3_4
  CDispShadowDecal *v27; // ebx
  float v28; // xmm0_4
  int m_Shadow; // edx
  int v30; // eax
  int v31; // edi
  CDispShadowFragment *ShadowDecalFragment; // eax
  int v33; // ecx
  int v34; // edx
  ShadowVertex_t *m_ShadowVerts; // esi
  float *p_x; // edi
  float *v37; // edi
  float *v38; // esi
  float *v39; // edi
  float *v40; // esi
  float *v41; // edi
  float *v42; // esi
  float *v43; // edi
  float *v44; // esi
  float *v45; // edi
  float *v46; // esi
  ShadowVertex_t *v47; // esi
  float *v48; // edi
  float *v49; // edi
  float *v50; // esi
  double v51; // st7
  int v52; // esi
  int v53; // ebx
  ShadowVertex_t *v54; // edx
  float *v55; // esi
  float *v56; // esi
  float *v57; // edx
  ShadowClipState_t clip; // [esp+Ch] [ebp-644h] BYREF
  Vector vPositions[3]; // [esp+618h] [ebp-38h] BYREF
  Vector *ppPosition[3]; // [esp+63Ch] [ebp-14h] BYREF
  int count; // [esp+648h] [ebp-8h]

  m_nIndexSize = this->m_MeshReader.m_nIndexSize;
  m_pIndices = this->m_MeshReader.m_pIndices;
  m_iVertOffset = this->m_iVertOffset;
  v8 = m_pIndices[(_DWORD)iIndexStart * m_nIndexSize];
  HIWORD(count) = m_pIndices[m_nIndexSize * ((_DWORD)iIndexStart + 1)] - m_iVertOffset;
  v9 = m_pIndices[m_nIndexSize * ((_DWORD)iIndexStart + 2)];
  v10 = (unsigned __int16)(v8 - m_iVertOffset);
  m_pNormal = this->m_MeshReader.m_pNormal;
  v12 = v9 - m_iVertOffset;
  m_VertexSize_Normal = this->m_MeshReader.m_VertexSize_Normal;
  v14 = *(float *)((char *)m_pNormal + m_VertexSize_Normal * v10 + 4);
  v15 = *(float *)((char *)m_pNormal + m_VertexSize_Normal * v10 + 8);
  v16 = (float *)((char *)this->m_MeshReader.m_pPosition + v10 * this->m_MeshReader.m_VertexSize_Position);
  vPositions[0].x = *v16 + (float)(*(float *)((char *)m_pNormal + m_VertexSize_Normal * v10) * 0.1);
  vPositions[0].y = v16[1] + (float)(v14 * 0.1);
  v17 = v16[2];
  v18 = (float *)((char *)this->m_MeshReader.m_pPosition + this->m_MeshReader.m_VertexSize_Position * HIWORD(count));
  v19 = m_VertexSize_Normal * HIWORD(count);
  vPositions[0].z = v17 + (float)(v15 * 0.1);
  v20 = *(float *)((char *)m_pNormal + v19 + 4);
  v21 = *(float *)((char *)m_pNormal + v19 + 8);
  vPositions[1].x = (float)(*(float *)((char *)m_pNormal + v19) * 0.1) + *v18;
  vPositions[1].y = v18[1] + (float)(v20 * 0.1);
  v22 = v18[2];
  v23 = m_VertexSize_Normal * v12;
  v24 = (float *)((char *)this->m_MeshReader.m_pPosition + this->m_MeshReader.m_VertexSize_Position * v12);
  vPositions[1].z = v22 + (float)(v21 * 0.1);
  v25 = *(float *)((char *)m_pNormal + v23 + 4) * 0.1;
  v26 = *(float *)((char *)m_pNormal + v23 + 8) * 0.1;
  vPositions[2].x = *v24 + (float)(*(float *)((char *)m_pNormal + v23) * 0.1);
  v27 = pDecal;
  vPositions[2].y = v24[1] + v25;
  v28 = v24[2];
  ppPosition[2] = &vPositions[2];
  m_Shadow = pDecal->m_Shadow;
  ppPosition[1] = &vPositions[1];
  ppPosition[0] = vPositions;
  vPositions[2].z = v28 + v26;
  v30 = g_pShadowMgr->ProjectAndClipVerticesEx(
          this: g_pShadowMgr,
          a2: m_Shadow,
          a3: 3,
          a4: ppPosition,
          a5: &iIndexStart,
          a6: &clip);
  v31 = v30;
  count = v30;
  if ( v30 >= 3 )
  {
    ShadowDecalFragment = CDispInfo::AllocateShadowDecalFragment(this, h: decalHandle, nCount: v30);
    v33 = 0;
    ShadowDecalFragment->m_nVerts = v31;
    if ( v31 >= 4 )
    {
      v34 = 0;
      do
      {
        m_ShadowVerts = ShadowDecalFragment->m_ShadowVerts;
        p_x = &iIndexStart[v33]->m_Position.x;
        v33 += 4;
        m_ShadowVerts[v34].m_Position.x = *p_x;
        m_ShadowVerts[v34].m_Position.y = p_x[1];
        m_ShadowVerts[v34].m_Position.z = p_x[2];
        v37 = &ShadowDecalFragment->m_ShadowVerts[v34].m_ShadowSpaceTexCoord.x;
        v38 = &iIndexStart[v33 - 4]->m_Position.x;
        *v37 = v38[3];
        v37[1] = v38[4];
        v37[2] = v38[5];
        v39 = &iIndexStart[v33 - 3]->m_Position.x;
        v40 = &ShadowDecalFragment->m_ShadowVerts[v34 + 1].m_Position.x;
        *v40 = *v39;
        v40[1] = v39[1];
        v40[2] = v39[2];
        v41 = &ShadowDecalFragment->m_ShadowVerts[v34 + 1].m_ShadowSpaceTexCoord.x;
        v42 = &iIndexStart[v33 - 3]->m_Position.x;
        *v41 = v42[3];
        v41[1] = v42[4];
        v41[2] = v42[5];
        v43 = &iIndexStart[v33 - 2]->m_Position.x;
        v44 = &ShadowDecalFragment->m_ShadowVerts[v34 + 2].m_Position.x;
        *v44 = *v43;
        v44[1] = v43[1];
        v44[2] = v43[2];
        v45 = &ShadowDecalFragment->m_ShadowVerts[v34 + 2].m_ShadowSpaceTexCoord.x;
        v46 = &iIndexStart[v33 - 2]->m_Position.x;
        *v45 = v46[3];
        v45[1] = v46[4];
        v45[2] = v46[5];
        v47 = ShadowDecalFragment->m_ShadowVerts;
        v48 = &iIndexStart[v33 - 1]->m_Position.x;
        v47[v34 + 3].m_Position.x = *v48;
        v47[v34 + 3].m_Position.y = v48[1];
        v47[v34 + 3].m_Position.z = v48[2];
        v49 = &ShadowDecalFragment->m_ShadowVerts[v34 + 3].m_ShadowSpaceTexCoord.x;
        v50 = &iIndexStart[v33 - 1]->m_Position.x;
        v34 += 4;
        *v49 = v50[3];
        v49[1] = v50[4];
        v51 = v50[5];
        v52 = count;
        v49[2] = v51;
      }
      while ( v33 < v52 - 3 );
      v31 = count;
    }
    if ( v33 < v31 )
    {
      v53 = v33;
      do
      {
        v54 = ShadowDecalFragment->m_ShadowVerts;
        v55 = &iIndexStart[v33++]->m_Position.x;
        v54[v53].m_Position.x = *v55;
        v54[v53].m_Position.y = v55[1];
        v54[v53].m_Position.z = v55[2];
        v56 = &ShadowDecalFragment->m_ShadowVerts[v53].m_ShadowSpaceTexCoord.x;
        v57 = &iIndexStart[v33 - 1]->m_Position.x;
        ++v53;
        *v56 = v57[3];
        v56[1] = v57[4];
        v56[2] = v57[5];
      }
      while ( v33 < v31 );
      v27 = pDecal;
    }
    v27->m_nVerts += LOWORD(ShadowDecalFragment->m_nVerts);
    v27->m_nTris += LOWORD(ShadowDecalFragment->m_nVerts) - 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB050
// Name: public: void CDispInfo::SpecifyDynamicMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SpecifyDynamicMesh(CDispInfo *this)
{
  IMatRenderContext *v2; // ebx
  IMesh *v3; // edi
  int v4; // edi
  CDispRenderVert *m_pMemory; // eax
  float *m_pCurrPosition; // ecx
  float *p_x; // eax
  float *v8; // ecx
  float *v9; // ecx
  float *v10; // ecx
  float *m_pCurrNormal; // edx
  float *v12; // ecx
  float *v13; // ecx
  float *v14; // eax
  int v15; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder builder; // [esp+8h] [ebp-1F0h] BYREF
  int m_MaxVerts; // [esp+1F4h] [ebp-4h]

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = v2->GetDynamicMesh(this: v2, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &builder);
  CMeshBuilder::Begin(
    this: &builder,
    pMesh: v3,
    type: MATERIAL_TRIANGLES,
    nVertexCount: this->m_pPowerInfo->m_MaxVerts,
    nIndexCount: this->m_nIndices,
    pMeshSettings: nullptr);
  if ( this->m_pPowerInfo->m_MaxVerts > 0 )
  {
    v4 = 0;
    m_MaxVerts = this->m_pPowerInfo->m_MaxVerts;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
      *builder.m_VertexBuilder.m_pCurrPosition = m_pMemory[v4].m_vPos.x;
      p_x = &m_pMemory[v4].m_vPos.x;
      m_pCurrPosition[1] = p_x[1];
      m_pCurrPosition[2] = p_x[2];
      v8 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
      *builder.m_VertexBuilder.m_pCurrTexCoord[0] = p_x[12];
      v8[1] = p_x[13];
      v9 = builder.m_VertexBuilder.m_pCurrTexCoord[1];
      *builder.m_VertexBuilder.m_pCurrTexCoord[1] = p_x[14];
      v9[1] = p_x[15];
      v10 = builder.m_VertexBuilder.m_pCurrTexCoord[2];
      *builder.m_VertexBuilder.m_pCurrTexCoord[2] = this->m_BumpSTexCoordOffset;
      v10[1] = 0.0;
      m_pCurrNormal = builder.m_VertexBuilder.m_pCurrNormal;
      *builder.m_VertexBuilder.m_pCurrNormal = p_x[3];
      m_pCurrNormal[1] = p_x[4];
      m_pCurrNormal[2] = p_x[5];
      v12 = (float *)((char *)builder.m_VertexBuilder.m_pTangentS
                    + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentS);
      *v12 = p_x[6];
      v12[1] = p_x[7];
      v12[2] = p_x[8];
      v13 = p_x + 9;
      v14 = (float *)((char *)builder.m_VertexBuilder.m_pTangentT
                    + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentT);
      *v14 = *v13;
      v14[1] = v13[1];
      v14[2] = v13[2];
      CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
      ++v4;
      --m_MaxVerts;
    }
    while ( m_MaxVerts != 0 );
  }
  v15 = 0;
  if ( this->m_nIndices > 0 )
  {
    m_nCurrentIndex = builder.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      builder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                         + this->m_Indices.m_Memory.m_pMemory[v15]
                                                         - LOWORD(this->m_iVertOffset);
      m_nCurrentIndex = builder.m_IndexBuilder.m_nIndexSize + builder.m_IndexBuilder.m_nCurrentIndex;
      builder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
      if ( m_nCurrentIndex > builder.m_IndexBuilder.m_nIndexCount )
        builder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v15;
    }
    while ( v15 < this->m_nIndices );
  }
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  builder.m_pMesh->UnlockMesh(
    this: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount,
    a4: &builder);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
  builder.m_pMesh = nullptr;
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100BB300
// Name: public: void CDispInfo::SpecifyWalkableDynamicMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SpecifyWalkableDynamicMesh(CDispInfo *this)
{
  IMatRenderContext *m_pObject; // edi
  IMesh *v3; // ebx
  int m_MaxVerts; // ebx
  int v5; // edi
  CDispRenderVert *m_pMemory; // eax
  float *m_pCurrPosition; // ecx
  int v8; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder builder; // [esp+2Ch] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+214h] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v3 = m_pObject->GetDynamicMesh(
         this: m_pObject,
         a2: false,
         a3: nullptr,
         a4: nullptr,
         a5: g_materialTranslucentSingleColor);
  ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))g_materialTranslucentSingleColor->ColorModulate)(
    a1: g_materialTranslucentSingleColor,
    a2: 1.0,
    a3: 1.0,
    a4: 0.0);
  ((void (__stdcall *)(_DWORD))g_materialTranslucentSingleColor->AlphaModulate)(a1: 0.33000001);
  CMeshBuilder::CMeshBuilder(this: &builder);
  CMeshBuilder::Begin(
    this: &builder,
    pMesh: v3,
    type: MATERIAL_TRIANGLES,
    nVertexCount: this->m_pPowerInfo->m_MaxVerts,
    nIndexCount: this->m_nWalkIndexCount,
    pMeshSettings: nullptr);
  m_MaxVerts = this->m_pPowerInfo->m_MaxVerts;
  if ( m_MaxVerts > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
      *builder.m_VertexBuilder.m_pCurrPosition = m_pMemory[v5].m_vPos.x;
      m_pCurrPosition[1] = m_pMemory[v5].m_vPos.y;
      m_pCurrPosition[2] = m_pMemory[v5].m_vPos.z;
      CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
      ++v5;
      --m_MaxVerts;
    }
    while ( m_MaxVerts != 0 );
    m_pObject = pRenderContext.m_pObject;
  }
  v8 = 0;
  if ( this->m_nWalkIndexCount > 0 )
  {
    m_nCurrentIndex = builder.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      builder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                         + this->m_pWalkIndices[v8];
      m_nCurrentIndex = builder.m_IndexBuilder.m_nIndexSize + builder.m_IndexBuilder.m_nCurrentIndex;
      builder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
      if ( m_nCurrentIndex > builder.m_IndexBuilder.m_nIndexCount )
        builder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v8;
    }
    while ( v8 < this->m_nWalkIndexCount );
  }
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  builder.m_pMesh->UnlockMesh(
    this: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount,
    a4: &builder);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
  builder.m_pMesh = nullptr;
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100BB570
// Name: public: void CDispInfo::SpecifyBuildableDynamicMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SpecifyBuildableDynamicMesh(CDispInfo *this)
{
  IMatRenderContext *m_pObject; // edi
  IMesh *v3; // ebx
  int m_MaxVerts; // ebx
  int v5; // edi
  CDispRenderVert *m_pMemory; // eax
  float *m_pCurrPosition; // ecx
  int v8; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder builder; // [esp+1Ch] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+204h] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))g_materialTranslucentSingleColor->ColorModulate)(
    a1: g_materialTranslucentSingleColor,
    a2: 0.0,
    a3: 1.0,
    a4: 1.0);
  ((void (__stdcall *)(_DWORD))g_materialTranslucentSingleColor->AlphaModulate)(a1: 0.33000001);
  v3 = m_pObject->GetDynamicMesh(
         this: m_pObject,
         a2: false,
         a3: nullptr,
         a4: nullptr,
         a5: g_materialTranslucentSingleColor);
  CMeshBuilder::CMeshBuilder(this: &builder);
  CMeshBuilder::Begin(
    this: &builder,
    pMesh: v3,
    type: MATERIAL_TRIANGLES,
    nVertexCount: this->m_pPowerInfo->m_MaxVerts,
    nIndexCount: this->m_nBuildIndexCount,
    pMeshSettings: nullptr);
  m_MaxVerts = this->m_pPowerInfo->m_MaxVerts;
  if ( m_MaxVerts > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
      *builder.m_VertexBuilder.m_pCurrPosition = m_pMemory[v5].m_vPos.x;
      m_pCurrPosition[1] = m_pMemory[v5].m_vPos.y;
      m_pCurrPosition[2] = m_pMemory[v5].m_vPos.z;
      CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
      ++v5;
      --m_MaxVerts;
    }
    while ( m_MaxVerts != 0 );
    m_pObject = pRenderContext.m_pObject;
  }
  v8 = 0;
  if ( this->m_nBuildIndexCount > 0 )
  {
    m_nCurrentIndex = builder.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      builder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                         + this->m_pBuildIndices[v8];
      m_nCurrentIndex = builder.m_IndexBuilder.m_nIndexSize + builder.m_IndexBuilder.m_nCurrentIndex;
      builder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
      if ( m_nCurrentIndex > builder.m_IndexBuilder.m_nIndexCount )
        builder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v8;
    }
    while ( v8 < this->m_nBuildIndexCount );
  }
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  builder.m_pMesh->UnlockMesh(
    this: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount,
    a4: &builder);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
  builder.m_pMesh = nullptr;
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100BB7E0
// Name: public: bool CDispInfo::Render(class CGroupMesh __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispInfo::Render(CDispInfo *this, CGroupMesh *pGroup, bool bAllowDebugModes)
{
  IMatRenderContext *v5; // edi
  int v6; // eax
  msurface2_t *m_ParentSurfID; // eax
  msurface2_t *v8; // eax
  mtexinfo_t *v9; // eax
  unsigned __int8 *v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // eax
  const char *v14; // eax
  int m_nVisible; // ecx
  char buf[32]; // [esp+54h] [ebp-44h] BYREF
  Vector vecCenter; // [esp+74h] [ebp-24h] BYREF
  Vector bbMin; // [esp+80h] [ebp-18h] BYREF
  Vector bbMax; // [esp+8Ch] [ebp-Ch] BYREF

  if ( this->m_pMesh == nullptr )
    return 0;
  if ( bAllowDebugModes )
  {
    v5 = materials->GetRenderContext(this: materials);
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    if ( sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive() )
    {
      v6 = mat_wireframe.m_pParent != nullptr ? mat_wireframe.m_pParent->m_Value.m_nValue : 0;
      if ( v6 != 0 )
      {
        v5->Bind(this: v5, a2: g_materialWorldWireframeZBuffer, a3: nullptr);
        CDispInfo::SpecifyDynamicMesh(this);
      }
    }
    if ( mat_luxels.m_pParent != nullptr && mat_luxels.m_pParent->m_Value.m_nValue != 0 )
    {
      v5->Bind(
        this: v5,
        a2: host_state.worldbrush->texinfo[*((unsigned __int16 *)this->m_ParentSurfID + 11) >> 1].material,
        a3: nullptr);
      pGroup->m_pMesh->Draw_2(this: pGroup->m_pMesh, a2: this->m_iIndexOffset, a3: this->m_nIndices);
      v5->Bind(this: v5, a2: g_materialDebugLuxels, a3: nullptr);
      CDispInfo::SpecifyDynamicMesh(this);
    }
    if ( r_DispWalkable.m_pParent != nullptr && r_DispWalkable.m_pParent->m_Value.m_nValue != 0
      || r_DispBuildable.m_pParent != nullptr && r_DispBuildable.m_pParent->m_Value.m_nValue != 0 )
    {
      v5->Bind(
        this: v5,
        a2: host_state.worldbrush->texinfo[*((unsigned __int16 *)this->m_ParentSurfID + 11) >> 1].material,
        a3: nullptr);
      pGroup->m_pMesh->Draw_2(this: pGroup->m_pMesh, a2: this->m_iIndexOffset, a3: this->m_nIndices);
      if ( r_DispWalkable.m_pParent != nullptr && r_DispWalkable.m_pParent->m_Value.m_nValue != 0 )
        CDispInfo::SpecifyWalkableDynamicMesh(this);
      if ( r_DispBuildable.m_pParent != nullptr && r_DispBuildable.m_pParent->m_Value.m_nValue != 0 )
        CDispInfo::SpecifyBuildableDynamicMesh(this);
    }
    if ( mat_surfaceid.m_pParent != nullptr && mat_surfaceid.m_pParent->m_Value.m_nValue != 0 )
    {
      this->GetBoundingBox(this, a2: &bbMin, a3: &bbMax);
      vecCenter.x = (float)(bbMax.x + bbMin.x) * 0.5;
      vecCenter.y = (float)(bbMax.y + bbMin.y) * 0.5;
      vecCenter.z = (float)(bbMax.z + bbMin.z) * 0.5;
      if ( mat_surfaceid.m_pParent != nullptr && mat_surfaceid.m_pParent->m_Value.m_nValue == 2 )
        m_ParentSurfID = (msurface2_t *)(this->m_ParentSurfID - host_state.worldbrush->surfaces2);
      else
        m_ParentSurfID = this->m_ParentSurfID;
      V_snprintf(pDest: buf, maxLen: 32, pFormat: "%d", m_ParentSurfID);
      CDebugOverlay::AddTextOverlay(textPos: &vecCenter, duration: 0.0, text: buf);
    }
    if ( mat_surfacemat.m_pParent != nullptr && mat_surfacemat.m_pParent->m_Value.m_nValue != 0 )
    {
      this->GetBoundingBox(this, a2: &bbMin, a3: &vecCenter);
      v8 = this->m_ParentSurfID;
      bbMax.x = (float)(vecCenter.x + bbMin.x) * 0.5;
      bbMax.y = (float)(vecCenter.y + bbMin.y) * 0.5;
      bbMax.z = (float)(vecCenter.z + bbMin.z) * 0.5;
      v9 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)v8 + 11) >> 1];
      if ( v9->material != nullptr )
        v10 = (unsigned __int8 *)v9->material->GetName(this: v9->material);
      else
        v10 = "no material";
      strrchr(string: v10, chr: 0x2Fu);
      v12 = v11;
      strrchr(string: v10, chr: 0x5Cu);
      if ( v12 > v13 )
        v13 = v12;
      if ( v13 != 0 )
        v14 = (const char *)(v13 + 1);
      else
        v14 = (const char *)v10;
      CDebugOverlay::AddTextOverlay(textPos: &bbMax, duration: 0.0, text: v14);
    }
    if ( v5 != nullptr )
    {
      v5->EndRender(this: v5);
      v5->Release(this: v5);
      return 1;
    }
  }
  else
  {
    m_nVisible = pGroup->m_nVisible;
    if ( m_nVisible < pGroup->m_Visible.m_Size && this->m_nIndices != 0 )
    {
      pGroup->m_Visible.m_Memory.m_pMemory[m_nVisible].m_FirstIndex = this->m_iIndexOffset;
      pGroup->m_Visible.m_Memory.m_pMemory[pGroup->m_nVisible].m_NumIndices = this->m_nIndices;
      pGroup->m_VisibleDisps.m_Memory.m_pMemory[pGroup->m_nVisible++] = this;
      ++pGroup->m_pGroup->m_nVisible;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BBB50
// Name: void IterateLightmapSamples(class CDispInfo __near *,struct ProcessLightmapSampleData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IterateLightmapSamples(CDispInfo *pDisp, const ProcessLightmapSampleData_t *data)
{
  unsigned __int8 *v2; // ebx
  char *v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // edx
  float v10; // xmm0_4
  CTriInfo *m_pTriInfos; // ecx
  int v12; // eax
  CTriInfo *v13; // esi
  int m_VertexSize_Position; // ecx
  float *m_pPosition; // edx
  int v16; // eax
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  int v21; // eax
  float v22; // xmm7_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  int v28; // eax
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  int m_VertexSize_Normal; // ecx
  float *m_pNormal; // edx
  int v35; // eax
  float v36; // xmm6_4
  float v37; // xmm0_4
  int v38; // eax
  float v39; // xmm7_4
  float v40; // xmm0_4
  int v41; // eax
  float v42; // xmm4_4
  float v43; // xmm5_4
  int m_VertexSize_TangentS; // ecx
  float v45; // xmm3_4
  float *m_pTangentS; // edx
  int v47; // eax
  float v48; // xmm6_4
  float v49; // xmm3_4
  int v50; // eax
  float v51; // xmm7_4
  float v52; // xmm3_4
  int v53; // eax
  float v54; // xmm4_4
  float v55; // xmm5_4
  int m_VertexSize_TangentT; // ecx
  float *m_pTangentT; // edx
  int v58; // eax
  float v59; // xmm4_4
  float v60; // xmm5_4
  float v61; // xmm6_4
  int v62; // eax
  float v63; // xmm7_4
  float v64; // xmm2_4
  int v65; // eax
  float v66; // xmm3_4
  float v67; // xmm2_4
  int v68; // esi
  Vector vPos; // [esp+0h] [ebp-94h] BYREF
  float v70; // [esp+10h] [ebp-84h]
  float v71; // [esp+14h] [ebp-80h]
  Vector vNormal; // [esp+18h] [ebp-7Ch] BYREF
  float v73; // [esp+28h] [ebp-6Ch]
  float v74; // [esp+2Ch] [ebp-68h]
  Vector vTangentS; // [esp+30h] [ebp-64h] BYREF
  float v76; // [esp+40h] [ebp-54h]
  float v77; // [esp+44h] [ebp-50h]
  Vector vTangentT; // [esp+48h] [ebp-4Ch] BYREF
  float v79; // [esp+58h] [ebp-3Ch]
  float v80; // [esp+5Ch] [ebp-38h]
  float v81; // [esp+64h] [ebp-30h]
  float v82; // [esp+68h] [ebp-2Ch]
  float v83; // [esp+70h] [ebp-24h]
  float v84; // [esp+74h] [ebp-20h]
  float a; // [esp+78h] [ebp-1Ch]
  float b; // [esp+7Ch] [ebp-18h]
  float c; // [esp+80h] [ebp-14h]
  int s; // [esp+84h] [ebp-10h]
  int tmax; // [esp+88h] [ebp-Ch]
  int t; // [esp+8Ch] [ebp-8h]
  int smax; // [esp+90h] [ebp-4h]

  if ( g_DispLightmapSamplePositions.m_Size != 0 )
  {
    v2 = &g_DispLightmapSamplePositions.m_Memory.m_pMemory[pDisp->m_iLightmapSamplePositionStart];
    v3 = (char *)host_state.worldbrush->surfacelighting
       + (((char *)pDisp->m_ParentSurfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
    v4 = *((__int16 *)v3 + 2);
    v5 = *((__int16 *)v3 + 3) + 1;
    v6 = v4 + 1;
    smax = v6;
    tmax = v5;
    for ( t = 0; t < v5; ++t )
    {
      s = 0;
      if ( v6 > 0 )
      {
        do
        {
          LOBYTE(v7) = *v2;
          if ( *v2 == 0xFF )
          {
            v8 = *++v2;
            v7 = v8 + 255;
          }
          else
          {
            v7 = (unsigned __int8)v7;
          }
          v9 = v7;
          v10 = (float)v2[1];
          m_pTriInfos = pDisp->m_pPowerInfo->m_pTriInfos;
          v12 = m_pTriInfos[v7].m_Indices[2];
          v13 = &m_pTriInfos[v9];
          m_VertexSize_Position = pDisp->m_MeshReader.m_VertexSize_Position;
          m_pPosition = pDisp->m_MeshReader.m_pPosition;
          v16 = m_VertexSize_Position * v12;
          v17 = *(float *)((char *)m_pPosition + v16);
          v18 = *(float *)((char *)m_pPosition + v16 + 4);
          v19 = *(float *)((char *)m_pPosition + v16 + 8);
          v20 = (float)v2[3] * 0.0039215689;
          v21 = m_VertexSize_Position * v13->m_Indices[1];
          v22 = *(float *)((char *)m_pPosition + v21);
          v23 = (float)v2[2] * 0.0039215689;
          v24 = v17 * v20;
          v25 = v19 * v20;
          c = v20;
          v26 = v18 * v20;
          v79 = *(float *)((char *)m_pPosition + v21 + 4) * v23;
          v27 = *(float *)((char *)m_pPosition + v21 + 8);
          v28 = m_VertexSize_Position * v13->m_Indices[0];
          v29 = v10 * 0.0039215689;
          v30 = *(float *)((char *)m_pPosition + v28 + 8);
          v80 = v27 * v23;
          v31 = *(float *)((char *)m_pPosition + v28 + 4);
          b = v23;
          v32 = (float)((float)(v29 * *(float *)((char *)m_pPosition + v28)) + (float)(v22 * v23)) + v24;
          a = v29;
          v2 += 4;
          vPos.x = v32;
          vPos.y = (float)((float)(v31 * v29) + v79) + v26;
          vPos.z = (float)((float)(v30 * v29) + v80) + v25;
          if ( CDispInfo::NumLightMaps(this: pDisp) > 1 )
          {
            m_VertexSize_Normal = pDisp->m_MeshReader.m_VertexSize_Normal;
            m_pNormal = pDisp->m_MeshReader.m_pNormal;
            v35 = m_VertexSize_Normal * v13->m_Indices[2];
            v36 = *(float *)((char *)m_pNormal + v35);
            v73 = *(float *)((char *)m_pNormal + v35 + 4) * c;
            v37 = *(float *)((char *)m_pNormal + v35 + 8);
            v38 = m_VertexSize_Normal * v13->m_Indices[1];
            v39 = *(float *)((char *)m_pNormal + v38);
            v74 = v37 * c;
            v83 = *(float *)((char *)m_pNormal + v38 + 4) * b;
            v40 = *(float *)((char *)m_pNormal + v38 + 8);
            v41 = m_VertexSize_Normal * v13->m_Indices[0];
            v42 = *(float *)((char *)m_pNormal + v41 + 4);
            v43 = *(float *)((char *)m_pNormal + v41 + 8);
            m_VertexSize_TangentS = pDisp->m_MeshReader.m_VertexSize_TangentS;
            v84 = v40 * b;
            v45 = a * *(float *)((char *)m_pNormal + v41);
            m_pTangentS = pDisp->m_MeshReader.m_pTangentS;
            vNormal.x = (float)(v45 + (float)(v39 * b)) + (float)(v36 * c);
            vNormal.y = (float)((float)(v42 * a) + v83) + v73;
            vNormal.z = (float)((float)(v43 * a) + (float)(v40 * b)) + v74;
            v47 = m_VertexSize_TangentS * v13->m_Indices[2];
            v48 = *(float *)((char *)m_pTangentS + v47);
            v70 = *(float *)((char *)m_pTangentS + v47 + 4) * c;
            v49 = *(float *)((char *)m_pTangentS + v47 + 8);
            v50 = m_VertexSize_TangentS * v13->m_Indices[1];
            v51 = *(float *)((char *)m_pTangentS + v50);
            v71 = v49 * c;
            v76 = *(float *)((char *)m_pTangentS + v50 + 4) * b;
            v52 = *(float *)((char *)m_pTangentS + v50 + 8);
            v53 = m_VertexSize_TangentS * v13->m_Indices[0];
            v54 = *(float *)((char *)m_pTangentS + v53 + 4);
            v55 = *(float *)((char *)m_pTangentS + v53 + 8);
            v77 = v52 * b;
            vTangentS.x = (float)((float)(*(float *)((char *)m_pTangentS + v53) * a) + (float)(v51 * b))
                        + (float)(v48 * c);
            vTangentS.y = (float)((float)(v54 * a) + v76) + v70;
            vTangentS.z = (float)((float)(v55 * a) + (float)(v52 * b)) + v71;
            m_VertexSize_TangentT = pDisp->m_MeshReader.m_VertexSize_TangentT;
            m_pTangentT = pDisp->m_MeshReader.m_pTangentT;
            v58 = m_VertexSize_TangentT * v13->m_Indices[2];
            v59 = *(float *)((char *)m_pTangentT + v58);
            v60 = *(float *)((char *)m_pTangentT + v58 + 4);
            v61 = *(float *)((char *)m_pTangentT + v58 + 8);
            v62 = m_VertexSize_TangentT * v13->m_Indices[1];
            v63 = *(float *)((char *)m_pTangentT + v62);
            v81 = *(float *)((char *)m_pTangentT + v62 + 4) * b;
            v64 = *(float *)((char *)m_pTangentT + v62 + 8);
            v65 = m_VertexSize_TangentT * v13->m_Indices[0];
            v66 = *(float *)((char *)m_pTangentT + v65 + 8);
            v82 = v64 * b;
            v67 = (float)((float)(*(float *)((char *)m_pTangentT + v65 + 4) * a) + v81) + (float)(v60 * c);
            vTangentT.x = (float)((float)(*(float *)((char *)m_pTangentT + v65) * a) + (float)(v63 * b))
                        + (float)(v59 * c);
            vTangentT.y = v67;
            vTangentT.z = (float)((float)(v66 * a) + v82) + (float)(v61 * c);
          }
          v68 = s;
          data->pProcessLightmapSampleDataFunc(
            a1: data,
            a2: &vPos,
            a3: &vNormal,
            a4: &vTangentS,
            a5: &vTangentT,
            a6: t,
            a7: s,
            a8: tmax,
            a9: smax);
          s = v68 + 1;
        }
        while ( v68 + 1 < smax );
        v5 = tmax;
        v6 = smax;
      }
    }
  }
  else if ( _executeCount < 20 )
  {
    ++_executeCount;
    _Warning(
      a1: "Cannot update displacement for dlight - set 'r_dlightsenable 1' and reload the map! (data may also have been culle"
      "d by MakeGameData)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBFA0
// Name: public: void CDispInfo::AddSingleDynamicLight(struct dlight_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddSingleDynamicLight(CDispInfo *this, dlight_t *dl)
{
  double minlight; // st7
  int style; // eax
  __m128i v4; // xmm0
  float v5; // xmm1_4
  int g; // eax
  float v7; // xmm2_4
  int b; // eax
  float y; // xmm0_4
  ProcessLightmapSampleData_t data; // [esp+0h] [ebp-28h] BYREF

  minlight = dl->minlight;
  style = dl->style;
  data.m_LightDistSqr = dl->radius * dl->radius;
  v4 = _mm_cvtsi32_si128(d_lightstylevalue[style]);
  v5 = dword_10425B80[dl->color.exponent];
  g = dl->color.g;
  *(float *)v4.m128i_i32 = _mm_cvtepi32_ps(v4).m128_f32[0] * 0.0037878789;
  data.m_Intensity.x = (float)((float)dl->color.r * v5) * *(float *)v4.m128i_i32;
  v7 = (float)g;
  b = dl->color.b;
  data.m_Intensity.y = (float)(v7 * v5) * *(float *)v4.m128i_i32;
  data.m_Intensity.z = (float)((float)b * v5) * *(float *)v4.m128i_i32;
  if ( g_flMinLightingValue >= minlight )
    minlight = g_flMinLightingValue;
  data.m_vLightOrigin.x = dl->origin.x;
  y = dl->origin.y;
  data.m_ooQuadraticAttn = minlight * data.m_LightDistSqr;
  data.m_vLightOrigin.y = y;
  data.m_vLightOrigin.z = dl->origin.z;
  data.m_ooRadiusSq = 1.0 / (float)(dl->radius * dl->radius);
  data.pProcessLightmapSampleDataFunc = ProcessLightmapSample;
  IterateLightmapSamples(pDisp: this, &data);
}

//------------------------------------------------------------------------------
// Address: 0x100BC090
// Name: public: void CDispInfo::AddSingleDynamicLightBumped(struct dlight_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddSingleDynamicLightBumped(CDispInfo *this, dlight_t *dl)
{
  double minlight; // st7
  int style; // eax
  __m128i v4; // xmm0
  float v5; // xmm1_4
  int g; // eax
  float v7; // xmm2_4
  int b; // eax
  float y; // xmm0_4
  ProcessLightmapSampleData_t data; // [esp+0h] [ebp-28h] BYREF

  minlight = dl->minlight;
  style = dl->style;
  data.m_LightDistSqr = dl->radius * dl->radius;
  v4 = _mm_cvtsi32_si128(d_lightstylevalue[style]);
  v5 = dword_10425B80[dl->color.exponent];
  g = dl->color.g;
  *(float *)v4.m128i_i32 = _mm_cvtepi32_ps(v4).m128_f32[0] * 0.0037878789;
  data.m_Intensity.x = (float)((float)dl->color.r * v5) * *(float *)v4.m128i_i32;
  v7 = (float)g;
  b = dl->color.b;
  data.m_Intensity.y = (float)(v7 * v5) * *(float *)v4.m128i_i32;
  data.m_Intensity.z = (float)((float)b * v5) * *(float *)v4.m128i_i32;
  if ( g_flMinLightingValue >= minlight )
    minlight = g_flMinLightingValue;
  data.m_vLightOrigin.x = dl->origin.x;
  y = dl->origin.y;
  data.m_ooQuadraticAttn = minlight * data.m_LightDistSqr;
  data.m_vLightOrigin.y = y;
  data.m_vLightOrigin.z = dl->origin.z;
  data.m_ooRadiusSq = 1.0 / (float)(dl->radius * dl->radius);
  data.pProcessLightmapSampleDataFunc = ProcessLightmapSampleBumped;
  IterateLightmapSamples(pDisp: this, &data);
}

//------------------------------------------------------------------------------
// Address: 0x100BC180
// Name: public: void CDispInfo::AddSingleDynamicAlphaLight(struct dlight_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddSingleDynamicAlphaLight(CDispInfo *this, dlight_t *dl)
{
  bool v2; // zf
  float v3; // xmm1_4
  float v4; // xmm0_4
  float minlight; // xmm0_4
  ProcessLightmapSampleData_t data; // [esp+0h] [ebp-28h] BYREF

  v2 = (dl->flags & 8) == 0;
  v3 = dl->radius * dl->radius;
  v4 = (float)((float)dl->color.r * dword_10425B80[dl->color.exponent])
     * (float)((float)d_lightstylevalue[dl->style] * 0.0037878789);
  data.m_LightDistSqr = v3;
  data.m_Intensity.x = v4;
  if ( !v2 )
  {
    data.m_Intensity.x = v4 * -1.0;
    data.m_Intensity.y = data.m_Intensity.y * -1.0;
    data.m_Intensity.z = data.m_Intensity.z * -1.0;
  }
  minlight = dl->minlight;
  if ( g_flMinLightingValue > minlight )
    minlight = g_flMinLightingValue;
  data.m_ooQuadraticAttn = minlight * v3;
  data.m_vLightOrigin = dl->origin;
  data.m_ooRadiusSq = 1.0 / (float)(dl->radius * dl->radius);
  data.pProcessLightmapSampleDataFunc = ProcessLightmapSampleAlpha;
  IterateLightmapSamples(pDisp: this, &data);
}

//------------------------------------------------------------------------------
// Address: 0x100BC280
// Name: private: bool CDispInfo::SetupDecalNodeIntersect_R(class CVertIndex const __near &,int,class CDispDecalBase __near *,struct ShadowInfo_t const __near *,int,class CDecalNodeSetupCache __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispInfo::SetupDecalNodeIntersect_R(
        CDispInfo *this,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        CDispDecalBase *pDispDecal,
        const CVertIndex *pInfo,
        const CVertIndex *iLevel,
        CDecalNodeSetupCache *pCache)
{
  const CPowerInfo *m_pPowerInfo; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // ebx
  CDispDecalBase *v15; // ebx
  float *v16; // edx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float x; // xmm0_4
  double v21; // st7
  double y; // st6
  double v23; // st5
  int v24; // eax
  double v25; // rt0
  int v26; // eax
  float *v27; // edx
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  unsigned int v31; // eax
  float *v32; // edx
  double v33; // st3
  double v34; // st4
  double v35; // st6
  int v36; // edx
  float *v37; // eax
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  unsigned int v41; // edx
  double v42; // st6
  float *v43; // edx
  double v44; // st5
  double v45; // st4
  double v46; // st2
  double v47; // st6
  double v48; // st5
  double v49; // rt0
  double v50; // st4
  double v51; // st5
  double v52; // st6
  double v53; // rt2
  double v54; // st4
  double v55; // st6
  bool v56; // zf
  float vMin; // [esp+Ch] [ebp-1Ch]
  float vMina; // [esp+Ch] [ebp-1Ch]
  float vMin_4; // [esp+10h] [ebp-18h]
  float vMin_4a; // [esp+10h] [ebp-18h]
  float vMin_8; // [esp+14h] [ebp-14h]
  float vMin_8a; // [esp+14h] [ebp-14h]
  float vMax; // [esp+18h] [ebp-10h]
  float vMaxa; // [esp+18h] [ebp-10h]
  float vMax_4; // [esp+1Ch] [ebp-Ch]
  float vMax_4a; // [esp+1Ch] [ebp-Ch]
  float vMax_8; // [esp+20h] [ebp-8h]
  float vMax_8a; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int anyChildIntersected; // [esp+30h] [ebp+8h]
  char anyChildIntersected_3; // [esp+33h] [ebp+Bh]
  const CVertIndex *cornerVert; // [esp+3Ch] [ebp+14h]
  float *sideVert; // [esp+40h] [ebp+18h]
  const CVertIndex *sideVertc; // [esp+40h] [ebp+18h]
  float *sideVerta; // [esp+40h] [ebp+18h]
  float *sideVertb; // [esp+40h] [ebp+18h]
  CDecalNodeSetupCache *pCachea; // [esp+44h] [ebp+1Ch]

  m_pPowerInfo = this->m_pPowerInfo;
  v9 = nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y;
  if ( (int)iLevel + 1 >= this->m_Power )
  {
    v15 = pDispDecal;
    if ( pCache->m_CacheIndex[v9] != pCache->m_CurrentCacheIndex )
    {
      sideVert = &pCache->m_ProjectedVert[v9].x;
      v16 = (float *)((char *)this->m_MeshReader.m_pPosition + v9 * this->m_MeshReader.m_VertexSize_Position);
      if ( pInfo != nullptr )
      {
        v17 = *v16;
        v18 = v16[1];
        v19 = v16[2];
        *sideVert = (float)((float)((float)(*(float *)&pInfo[1] * v18) + (float)(*(float *)pInfo * *v16))
                          + (float)(*(float *)&pInfo[2] * v19))
                  + *(float *)&pInfo[3];
        sideVert[1] = (float)((float)((float)(*(float *)&pInfo[5] * v18) + (float)(*(float *)&pInfo[4] * v17))
                            + (float)(*(float *)&pInfo[6] * v19))
                    + *(float *)&pInfo[7];
        sideVert[2] = (float)((float)((float)(*(float *)&pInfo[9] * v18) + (float)(*(float *)&pInfo[8] * v17))
                            + (float)(*(float *)&pInfo[10] * v19))
                    + *(float *)&pInfo[11];
      }
      else
      {
        *sideVert = (float)((float)((float)((float)(*(float *)&pDispDecal[1].m_nTris * v16[1])
                                          + (float)(*v16 * *(float *)&pDispDecal[1].m_Flags))
                                  + (float)(*(float *)pDispDecal[2].m_NodeIntersect.m_Ints * v16[2]))
                          - *(float *)(pDispDecal[1].m_NodeIntersect.m_Ints[0] + 44))
                  + 0.5;
        sideVert[1] = (float)((float)((float)((float)(*(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[2] * v16[1])
                                            + (float)(*v16 * *(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[1]))
                                    + (float)(*(float *)&pDispDecal[2].m_Flags * v16[2]))
                            - *(float *)(pDispDecal[1].m_NodeIntersect.m_Ints[0] + 48))
                    + 0.5;
        sideVert[2] = 0.0;
      }
      pCache->m_CacheIndex[v9] = pCache->m_CurrentCacheIndex;
    }
    x = pCache->m_ProjectedVert[v9].x;
    vMin_8 = pCache->m_ProjectedVert[v9].z;
    v21 = vMin_8;
    y = pCache->m_ProjectedVert[v9].y;
    v23 = y;
    v24 = 16 * v9;
    vMin = x;
    vMax = x;
    vMax_8 = vMin_8;
    pCachea = (CDecalNodeSetupCache *)v24;
    anyChildIntersected = 4;
    while ( 1 )
    {
      sideVertc = (CVertIndex *)((char *)this->m_pPowerInfo->m_pSideVerts->m_Verts + v24);
      cornerVert = (CVertIndex *)((char *)this->m_pPowerInfo->m_pSideVertCorners->m_Verts + v24);
      v26 = sideVertc->x + this->m_pPowerInfo->m_SideLength * sideVertc->y;
      if ( pCache->m_CacheIndex[v26] != pCache->m_CurrentCacheIndex )
      {
        sideVerta = &pCache->m_ProjectedVert[v26].x;
        v27 = (float *)((char *)this->m_MeshReader.m_pPosition + v26 * this->m_MeshReader.m_VertexSize_Position);
        if ( pInfo != nullptr )
        {
          v28 = *v27;
          v29 = v27[1];
          v30 = v27[2];
          *sideVerta = (float)((float)((float)(*(float *)&pInfo[1] * v29) + (float)(*(float *)pInfo * *v27))
                             + (float)(*(float *)&pInfo[2] * v30))
                     + *(float *)&pInfo[3];
          sideVerta[1] = (float)((float)((float)(*(float *)&pInfo[5] * v29) + (float)(*(float *)&pInfo[4] * v28))
                               + (float)(*(float *)&pInfo[6] * v30))
                       + *(float *)&pInfo[7];
          sideVerta[2] = (float)((float)((float)(*(float *)&pInfo[9] * v29) + (float)(*(float *)&pInfo[8] * v28))
                               + (float)(*(float *)&pInfo[10] * v30))
                       + *(float *)&pInfo[11];
        }
        else
        {
          *sideVerta = (float)((float)((float)((float)(*(float *)&v15[1].m_nTris * v27[1])
                                             + (float)(*v27 * *(float *)&v15[1].m_Flags))
                                     + (float)(*(float *)v15[2].m_NodeIntersect.m_Ints * v27[2]))
                             - *(float *)(v15[1].m_NodeIntersect.m_Ints[0] + 44))
                     + 0.5;
          v15 = pDispDecal;
          sideVerta[1] = (float)((float)((float)((float)(*(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[2] * v27[1])
                                               + (float)(*v27 * *(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[1]))
                                       + (float)(*(float *)&pDispDecal[2].m_Flags * v27[2]))
                               - *(float *)(pDispDecal[1].m_NodeIntersect.m_Ints[0] + 48))
                       + 0.5;
          sideVerta[2] = 0.0;
        }
        pCache->m_CacheIndex[v26] = pCache->m_CurrentCacheIndex;
      }
      v31 = 3 * v26;
      v32 = (float *)((char *)pCache + 4 * v31);
      v33 = vMin;
      if ( *v32 <= (double)vMin )
        v33 = pCache->m_ProjectedVert[v31 / 3].x;
      vMina = v33;
      if ( v32[1] <= y )
        y = v32[1];
      vMin_4 = y;
      if ( v32[2] <= v21 )
        v21 = v32[2];
      v34 = vMax;
      if ( pCache->m_ProjectedVert[v31 / 3].x >= (double)vMax )
        v34 = pCache->m_ProjectedVert[v31 / 3].x;
      vMaxa = v34;
      if ( v32[1] >= v23 )
        v23 = v32[1];
      vMax_4 = v23;
      v35 = vMax_8;
      if ( v32[2] >= (double)vMax_8 )
        v35 = v32[2];
      vMax_8a = v35;
      v36 = cornerVert->x + this->m_pPowerInfo->m_SideLength * cornerVert->y;
      if ( pCache->m_CacheIndex[v36] != pCache->m_CurrentCacheIndex )
      {
        sideVertb = &pCache->m_ProjectedVert[v36].x;
        v37 = (float *)((char *)this->m_MeshReader.m_pPosition + v36 * this->m_MeshReader.m_VertexSize_Position);
        if ( pInfo != nullptr )
        {
          v38 = *v37;
          v39 = v37[1];
          v40 = v37[2];
          *sideVertb = (float)((float)((float)(*(float *)&pInfo[1] * v39) + (float)(*(float *)pInfo * *v37))
                             + (float)(*(float *)&pInfo[2] * v40))
                     + *(float *)&pInfo[3];
          sideVertb[1] = (float)((float)((float)(*(float *)&pInfo[5] * v39) + (float)(*(float *)&pInfo[4] * v38))
                               + (float)(*(float *)&pInfo[6] * v40))
                       + *(float *)&pInfo[7];
          sideVertb[2] = (float)((float)((float)(*(float *)&pInfo[9] * v39) + (float)(*(float *)&pInfo[8] * v38))
                               + (float)(*(float *)&pInfo[10] * v40))
                       + *(float *)&pInfo[11];
        }
        else
        {
          *sideVertb = (float)((float)((float)((float)(*(float *)&v15[1].m_nTris * v37[1])
                                             + (float)(*v37 * *(float *)&v15[1].m_Flags))
                                     + (float)(*(float *)v15[2].m_NodeIntersect.m_Ints * v37[2]))
                             - *(float *)(v15[1].m_NodeIntersect.m_Ints[0] + 44))
                     + 0.5;
          v15 = pDispDecal;
          sideVertb[1] = (float)((float)((float)((float)(*(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[2] * v37[1])
                                               + (float)(*v37 * *(float *)&pDispDecal[2].m_NodeIntersect.m_Ints[1]))
                                       + (float)(*(float *)&pDispDecal[2].m_Flags * v37[2]))
                               - *(float *)(pDispDecal[1].m_NodeIntersect.m_Ints[0] + 48))
                       + 0.5;
          sideVertb[2] = 0.0;
        }
        pCache->m_CacheIndex[v36] = pCache->m_CurrentCacheIndex;
      }
      v41 = 3 * v36;
      v42 = pCache->m_ProjectedVert[v41 / 3].x;
      v43 = (float *)((char *)pCache + 4 * v41);
      v44 = vMina;
      if ( v42 <= vMina )
        v44 = v42;
      vMin = v44;
      v45 = vMin_4;
      if ( v43[1] <= (double)vMin_4 )
        v45 = v43[1];
      vMin_4a = v45;
      if ( v43[2] <= v21 )
        v21 = v43[2];
      v46 = v42;
      v47 = vMaxa;
      if ( v46 >= vMaxa )
        v47 = v46;
      vMax = v47;
      v48 = vMax_4;
      if ( v43[1] >= (double)vMax_4 )
        v48 = v43[1];
      v49 = v45;
      v50 = v48;
      v51 = v49;
      vMax_4a = v50;
      v52 = vMax_8a;
      if ( v43[2] >= (double)vMax_8a )
        v52 = v43[2];
      pCachea = (CDecalNodeSetupCache *)((char *)pCachea + 4);
      v53 = v50;
      v54 = v52;
      v55 = v53;
      v56 = anyChildIntersected-- == 1;
      vMax_8 = v54;
      if ( v56 )
        break;
      v24 = (int)pCachea;
      v25 = v51;
      v23 = v55;
      y = v25;
    }
    if ( vMin <= 1.0
      && vMax >= 0.0
      && vMin_4a <= 1.0
      && vMax_4a >= 0.0
      && (pInfo == nullptr || vMax_8 >= 0.0 && (vMin_8a = v21) <= *(float *)&pInfo[17]) )
    {
      v15->m_NodeIntersect.m_Ints[iNodeBitIndex >> 5] |= 1 << (iNodeBitIndex & 0x1F);
      return 1;
    }
  }
  else
  {
    v10 = iNodeBitIndex + 1;
    anyChildIntersected_3 = 0;
    v11 = 4 * v9;
    for ( i = 4; i != 0; --i )
    {
      if ( CDispInfo::SetupDecalNodeIntersect_R(
             this,
             nodeIndex: &m_pPowerInfo->m_pChildVerts->m_Verts[v11],
             iNodeBitIndex: v10,
             pDispDecal,
             (const ShadowInfo_t *)pInfo,
             iLevel: (int)iLevel + 1,
             pCache) )
      {
        anyChildIntersected_3 = 1;
      }
      m_pPowerInfo = this->m_pPowerInfo;
      v10 += m_pPowerInfo->m_NodeIndexIncrements[(_DWORD)iLevel];
      ++v11;
    }
    if ( anyChildIntersected_3 != 0 )
    {
      pDispDecal->m_NodeIntersect.m_Ints[iNodeBitIndex >> 5] |= 1 << (iNodeBitIndex & 0x1F);
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BC940
// Name: private: void CDispInfo::SetupDecalNodeIntersect(class CVertIndex const __near &,int,class CDispDecalBase __near *,struct ShadowInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SetupDecalNodeIntersect(
        CDispInfo *this,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        CDispDecalBase *pDispDecal,
        const CVertIndex *pInfo)
{
  char v5; // al
  unsigned __int8 m_Flags; // cl

  if ( pDispDecal != nullptr )
  {
    pDispDecal->m_NodeIntersect.m_Ints[0] = 0;
    pDispDecal->m_NodeIntersect.m_Ints[1] = 0;
    pDispDecal->m_NodeIntersect.m_Ints[2] = 0;
  }
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    cache.m_CurrentCacheIndex = 0;
  }
  ++cache.m_CurrentCacheIndex;
  v5 = CDispInfo::SetupDecalNodeIntersect_R(
         this,
         nodeIndex,
         iNodeBitIndex,
         pDispDecal,
         pInfo,
         iLevel: nullptr,
         pCache: &cache);
  pDispDecal->m_Flags |= 1u;
  m_Flags = pDispDecal->m_Flags;
  if ( v5 != 0 )
    pDispDecal->m_Flags = m_Flags & 0xFB;
  else
    pDispDecal->m_Flags = m_Flags | 4;
}

//------------------------------------------------------------------------------
// Address: 0x100BC9B0
// Name: void TesselateDisplacementNode<class CEngineTesselateHelper>(class CEngineTesselateHelper __near *,class CVertIndex const __near &,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacementNode<CEngineTesselateHelper>(
        CEngineTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        char iLevel,
        int *pActiveChildren)
{
  int v5; // eax
  int v6; // ecx
  const CVertIndex *v7; // ebx
  __int16 v8; // dx
  __int16 v9; // di
  int v10; // eax
  __int16 vertInc; // [esp+4h] [ebp-8h]
  int iVert; // [esp+8h] [ebp-4h]
  int iCurTriVert; // [esp+14h] [ebp+8h]
  int iLevela; // [esp+1Ch] [ebp+10h]

  v5 = 1 << (pHelper->m_pPowerInfo->m_Power - iLevel - 1);
  v6 = 0;
  iCurTriVert = 0;
  vertInc = v5;
  iVert = 0;
  if ( g_TWinding.m_nVerts > 0 )
  {
    v7 = nodeIndex;
    iLevela = 0;
    while ( 1 )
    {
      v8 = v7->x + v5 * *(__int16 *)((char *)&g_TWinding.m_Verts->m_Index.x + v6);
      v9 = v7->y + v5 * *(__int16 *)((char *)&g_TWinding.m_Verts->m_Index.y + v6);
      v10 = *(__int16 *)((char *)&g_TWinding.m_Verts->m_iNode + v6);
      if ( v10 == -1 || pActiveChildren[v10] == 0 )
      {
        v7 = nodeIndex;
        if ( ((1 << ((v8 + LOBYTE(pHelper->m_pPowerInfo->m_SideLength) * v9) & 0x1F))
            & pHelper->m_pActiveVerts[(v8 + pHelper->m_pPowerInfo->m_SideLength * v9) >> 5]) != 0 )
        {
          pHelper->m_TempIndices[iCurTriVert++] = v8 + v9 * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          if ( iCurTriVert == 2 )
          {
            pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
            CEngineTesselateHelper::EndTriangle(this: pHelper);
            pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
            iCurTriVert = 1;
          }
        }
      }
      else
      {
        iCurTriVert = 0;
      }
      iLevela += 6;
      if ( ++iVert >= g_TWinding.m_nVerts )
        break;
      v6 = iLevela;
      LOWORD(v5) = vertInc;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCB00
// Name: void TesselateDisplacement_R<class CEngineTesselateHelper>(class CEngineTesselateHelper __near *,class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacement_R<CEngineTesselateHelper>(
        CEngineTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  int m_nIndices; // eax
  DispNodeInfo_t *v6; // edi
  const CPowerInfo *m_pPowerInfo; // ecx
  int v8; // edx
  int v9; // ebx
  const CPowerInfo *v10; // ecx
  const CVertIndex *v11; // edi
  unsigned int v12; // edx
  unsigned __int16 v13; // ax
  int bActiveChildren[4]; // [esp+Ch] [ebp-18h] BYREF
  DispNodeInfo_t *nodeInfo; // [esp+1Ch] [ebp-8h]
  int oldIndexCount; // [esp+20h] [ebp-4h]
  int iChild; // [esp+2Ch] [ebp+8h]
  int iNodeBitIndexa; // [esp+34h] [ebp+10h]

  m_nIndices = pHelper->m_nIndices;
  v6 = &pHelper->m_pDisp->m_pNodeInfo[iNodeBitIndex];
  m_pPowerInfo = pHelper->m_pPowerInfo;
  v8 = m_pPowerInfo->m_Power - 1;
  nodeInfo = v6;
  oldIndexCount = m_nIndices;
  if ( iLevel < v8 )
  {
    v9 = iNodeBitIndex + 1;
    iChild = 0;
    iNodeBitIndexa = 4 * (nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y);
    do
    {
      v10 = pHelper->m_pPowerInfo;
      v11 = &v10->m_pChildVerts->m_Verts[iNodeBitIndexa];
      v12 = pHelper->m_pActiveVerts[(v11->x + v10->m_SideLength * v11->y) >> 5]
          & (1 << ((v11->x + LOBYTE(v10->m_SideLength) * v11->y) & 0x1F));
      bActiveChildren[iChild] = v12;
      if ( v12 != 0 )
        TesselateDisplacement_R<CEngineTesselateHelper>(pHelper, nodeIndex: v11, iNodeBitIndex: v9, iLevel: iLevel + 1);
      else
        *(_WORD *)&pHelper->m_pDisp->m_pNodeInfo[v9].m_Count = 0;
      v9 += pHelper->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      ++iNodeBitIndexa;
      ++iChild;
    }
    while ( iChild < 4 );
    v6 = nodeInfo;
  }
  else
  {
    memset(bActiveChildren, 0, sizeof(bActiveChildren));
  }
  if ( pHelper->m_nIndices == oldIndexCount )
  {
    v6->m_Flags = 0;
  }
  else
  {
    v6->m_Flags = 1;
    oldIndexCount = pHelper->m_nIndices;
  }
  TesselateDisplacementNode<CEngineTesselateHelper>(pHelper, nodeIndex, iLevel, pActiveChildren: bActiveChildren);
  v13 = oldIndexCount;
  v6->m_Count = LOBYTE(pHelper->m_nIndices) - oldIndexCount;
  v6->m_FirstTesselationIndex = v13;
}

//------------------------------------------------------------------------------
// Address: 0x100BCC40
// Name: public: void CDispInfo::TesselateDisplacement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::TesselateDisplacement(CDispInfo *this)
{
  int v2; // edi
  CGroupMesh *m_pMesh; // eax
  CDispUtilsHelper_vtbl *v4; // eax
  int m_iIndexOffset; // [esp-8h] [ebp-214h]
  CEngineTesselateHelper helper; // [esp+8h] [ebp-204h] BYREF

  CDispInfo::ClearAllDecalFragments(this);
  CDispInfo::ClearAllShadowDecalFragments(this);
  v2 = this->m_pPowerInfo->m_SideLength - 1;
  CMeshBuilder::CMeshBuilder(this: &helper.m_IndexMesh);
  m_pMesh = this->m_pMesh;
  m_iIndexOffset = this->m_iIndexOffset;
  helper.m_pDisp = this;
  CMeshBuilder::BeginModify(
    this: &helper.m_IndexMesh,
    pMesh: m_pMesh->m_pMesh,
    nFirstVertex: 0,
    nVertexCount: 0,
    nFirstIndex: m_iIndexOffset,
    nIndexCount: 6 * v2 * v2);
  v4 = this->CDispUtilsHelper::__vftable;
  helper.m_pActiveVerts = this->m_ActiveVerts.m_Ints;
  helper.m_pPowerInfo = v4->GetPowerInfo(this: &this->CDispUtilsHelper);
  helper.m_nIndices = 0;
  TesselateDisplacement_R<CEngineTesselateHelper>(
    pHelper: &helper,
    nodeIndex: &helper.m_pPowerInfo->m_RootNode,
    iNodeBitIndex: 0,
    iLevel: 0);
  helper.m_IndexMesh.m_pMesh->ModifyEnd(this: helper.m_IndexMesh.m_pMesh, a2: &helper.m_IndexMesh);
  this->m_nIndices = helper.m_nIndices;
}

//------------------------------------------------------------------------------
// Address: 0x10314810
// Name: _dynamic_initializer_for__disp_dynamic__
// Source: semantic_dyn_pfx_disp
//------------------------------------------------------------------------------
int dynamic_initializer_for__disp_dynamic__()
{
  ConVar::ConVar(this: &disp_dynamic, pName: "disp_dynamic", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__disp_dynamic__);
}

//------------------------------------------------------------------------------
// Address: 0x10319DC0
// Name: _dynamic_initializer_for__disp_list_all_collideable_command__
// Source: semantic_dyn_pfx_disp
//------------------------------------------------------------------------------
int dynamic_initializer_for__disp_list_all_collideable_command__()
{
  ConCommand::ConCommand(
    this: &disp_list_all_collideable_command,
    pName: "disp_list_all_collideable",
    callback: (void (__cdecl *)())disp_list_all_collideable,
    pHelpString: "List all collideable displacements",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__disp_list_all_collideable_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322F30
// Name: _dynamic_atexit_destructor_for__disp_dynamic__
// Source: semantic_dyn_pfx_disp
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__disp_dynamic__()
{
  ConVar::~ConVar(this: &disp_dynamic);
}

//------------------------------------------------------------------------------
// Address: 0x10325310
// Name: _dynamic_atexit_destructor_for__disp_list_all_collideable_command__
// Source: semantic_dyn_pfx_disp
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__disp_list_all_collideable_command__()
{
  ConCommand::~ConCommand(this: &disp_list_all_collideable_command);
}

//------------------------------------------------------------------------------
// Address: 0x10314840
// Name: _dynamic_initializer_for__g_ConstructorChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ConstructorChecker__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ConstructorChecker__);
}

//------------------------------------------------------------------------------
// Address: 0x10314850
// Name: _dynamic_initializer_for__g_InitMainView__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int dynamic_initializer_for__g_InitMainView__()
{
  float z; // xmm2_4
  float y; // xmm3_4
  float x; // xmm4_4
  unsigned int result; // eax

  z = vec3_origin.z;
  y = vec3_origin.y;
  x = vec3_origin.x;
  for ( result = 0; (int)result < 24; result += 12 )
  {
    g_MainViewOrigin[result / 0xC].x = x;
    g_MainViewOrigin[result / 0xC].y = y;
    g_MainViewOrigin[result / 0xC].z = z;
    g_MainViewForward[result / 0xC].x = 1.0;
    dword_104F1BF8[result / 4] = 0;
    dword_104F1BFC[result / 4] = 0;
    g_MainViewRight[result / 0xC].x = 0.0;
    dword_104F1C10[result / 4] = -1082130432;
    dword_104F1C14[result / 4] = 0;
    g_MainViewUp[result / 0xC].x = 0.0;
    dword_104F1C28[result / 4] = 0;
    dword_104F1C2C[result / 4] = 1065353216;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10319DF0
// Name: _dynamic_initializer_for__path_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__path_command__()
{
  ConCommand::ConCommand(
    this: &path_command,
    pName: "path",
    callback: (void (__cdecl *)())path,
    pHelpString: "Show the engine filesystem path.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__path_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319E20
// Name: _dynamic_initializer_for__fs_printopenfiles_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_printopenfiles_command__()
{
  ConCommand::ConCommand(
    this: &fs_printopenfiles_command,
    pName: "fs_printopenfiles",
    callback: (void (__cdecl *)())fs_printopenfiles,
    pHelpString: "Show all files currently opened by the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_printopenfiles_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319E50
// Name: _dynamic_initializer_for__fs_warning_level_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_warning_level_command__()
{
  ConCommand::ConCommand(
    this: &fs_warning_level_command,
    pName: "fs_warning_level",
    callback: (void (__cdecl *)())fs_warning_level,
    pHelpString: "Set the filesystem warning level.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_warning_level_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319E80
// Name: _dynamic_initializer_for__fs_syncdvddevcache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_syncdvddevcache_command__()
{
  ConCommand::ConCommand(
    this: &fs_syncdvddevcache_command,
    pName: "fs_syncdvddevcache",
    callback: (void (__cdecl *)())fs_syncdvddevcache,
    pHelpString: "Force the 360 to get updated files that are in your p4 changelist(s) from the host PC when running with -dvddev.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_syncdvddevcache_command__);
}

} // namespace engine_xlsp
