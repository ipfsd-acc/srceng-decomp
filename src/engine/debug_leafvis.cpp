// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/debug_leafvis.cpp
// Functions: 16
// ============================================================

#include "engine\debug_leafvis.h"

//------------------------------------------------------------------------------
// Address: 0x100AF880
// Name: bool CullNodeSIMD(class Frustum_t const __near &,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CullNodeSIMD(const Frustum_t *frustum, mnode_t *pNode)
{
  __m128 v2; // xmm0
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  __m128 v7; // xmm5
  int v8; // ecx
  __m128 *i; // eax
  __m128 v11; // [esp-Ch] [ebp-2Ch]
  __m128 centerz_4; // [esp+4h] [ebp-1Ch]

  v2 = _mm_and_ps((__m128)pNode->m_vecCenter, *(__m128 *)g_SIMD_clear_wmask);
  v3 = _mm_and_ps((__m128)pNode->m_vecHalfDiagonal, *(__m128 *)g_SIMD_clear_wmask);
  v4 = _mm_shuffle_ps(v2, v2, 0);
  v5 = _mm_shuffle_ps(v2, v2, 85);
  v6 = _mm_shuffle_ps(v3, v3, 0);
  v7 = _mm_shuffle_ps(v3, v3, 85);
  v8 = 0;
  v11 = _mm_shuffle_ps(v2, v2, 170);
  centerz_4 = _mm_shuffle_ps(v3, v3, 170);
  for ( i = &frustum->planes[0].nZ;
        _mm_movemask_ps(
          _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(i[6], v7), _mm_mul_ps(i[-1], v5)),
                _mm_add_ps(_mm_mul_ps(i[7], centerz_4), _mm_mul_ps(v11, *i))),
              _mm_add_ps(_mm_mul_ps(i[5], v6), _mm_mul_ps(i[-2], v4))),
            i[1])) == 0;
        i += 10 )
  {
    if ( ++v8 >= 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AF950
// Name: class Vector CSGInsidePoint(struct cplane_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl CSGInsidePoint(Vector *result, cplane_t *pPlanes, int planeCount)
{
  Vector *v3; // eax
  float y; // edx
  float z; // ecx
  int v6; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  unsigned int v9; // edx
  float *p_z; // ecx
  float v11; // xmm3_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm6_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float *p_y; // ecx
  int v26; // edi
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm0_4

  v3 = result;
  y = vec3_origin.y;
  result->x = vec3_origin.x;
  z = vec3_origin.z;
  v6 = 0;
  result->y = y;
  result->z = z;
  if ( planeCount >= 4 )
  {
    v7 = result->y;
    v8 = result->z;
    v9 = ((unsigned int)(planeCount - 4) >> 2) + 1;
    p_z = &pPlanes[1].normal.z;
    v6 = 4 * v9;
    do
    {
      v11 = *(p_z - 6);
      v12 = *(p_z - 5);
      v13 = (float)((float)((float)(v11 * v7) + (float)(*(p_z - 7) * result->x)) + (float)(v12 * v8)) - *(p_z - 4);
      if ( v13 < 0.0 )
      {
        result->x = result->x - (float)(*(p_z - 7) * v13);
        v7 = v7 - (float)(v11 * v13);
        v8 = v8 - (float)(v12 * v13);
      }
      v14 = *(p_z - 1);
      v15 = *p_z;
      v16 = (float)((float)((float)(v14 * v7) + (float)(*(p_z - 2) * result->x)) + (float)(*p_z * v8)) - p_z[1];
      if ( v16 < 0.0 )
      {
        result->x = result->x - (float)(*(p_z - 2) * v16);
        v7 = v7 - (float)(v14 * v16);
        v8 = v8 - (float)(v15 * v16);
      }
      v17 = p_z[4];
      v18 = p_z[5];
      v19 = (float)((float)((float)(v17 * v7) + (float)(p_z[3] * result->x)) + (float)(v18 * v8)) - p_z[6];
      if ( v19 < 0.0 )
      {
        result->x = result->x - (float)(p_z[3] * v19);
        v7 = v7 - (float)(v17 * v19);
        v8 = v8 - (float)(v18 * v19);
      }
      v20 = p_z[9];
      v21 = p_z[10];
      v22 = (float)((float)((float)(v20 * v7) + (float)(p_z[8] * result->x)) + (float)(v21 * v8)) - p_z[11];
      if ( v22 < 0.0 )
      {
        result->x = result->x - (float)(p_z[8] * v22);
        v7 = v7 - (float)(v20 * v22);
        v8 = v8 - (float)(v21 * v22);
      }
      p_z += 20;
      --v9;
    }
    while ( v9 != 0 );
    result->y = v7;
    result->z = v8;
  }
  if ( v6 < planeCount )
  {
    v23 = result->y;
    v24 = result->z;
    p_y = &pPlanes[v6].normal.y;
    v26 = planeCount - v6;
    do
    {
      v27 = *p_y;
      v28 = p_y[1];
      v29 = (float)((float)((float)(*p_y * v23) + (float)(*(p_y - 1) * result->x)) + (float)(v28 * v24)) - p_y[2];
      if ( v29 < 0.0 )
      {
        result->x = result->x - (float)(*(p_y - 1) * v29);
        v23 = v23 - (float)(v27 * v29);
        v24 = v24 - (float)(v28 * v29);
      }
      p_y += 5;
      --v26;
    }
    while ( v26 != 0 );
    result->y = v23;
    result->z = v24;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100AFBA0
// Name: void TranslatePlaneList(struct cplane_t __near *,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TranslatePlaneList(cplane_t *pPlanes, int planeCount, const Vector *offset)
{
  int v3; // esi
  unsigned int v4; // edx
  float *p_z; // eax
  float *p_dist; // eax
  int v7; // edi

  v3 = 0;
  if ( planeCount >= 4 )
  {
    v4 = ((unsigned int)(planeCount - 4) >> 2) + 1;
    p_z = &pPlanes[1].normal.z;
    v3 = 4 * v4;
    do
    {
      *(p_z - 4) = (float)((float)((float)(*(p_z - 6) * offset->y) + (float)(*(p_z - 7) * offset->x))
                         + (float)(*(p_z - 5) * offset->z))
                 + *(p_z - 4);
      p_z[1] = (float)((float)((float)(*(p_z - 1) * offset->y) + (float)(*(p_z - 2) * offset->x))
                     + (float)(offset->z * *p_z))
             + p_z[1];
      p_z[6] = (float)((float)((float)(p_z[4] * offset->y) + (float)(p_z[3] * offset->x)) + (float)(p_z[5] * offset->z))
             + p_z[6];
      p_z[11] = (float)((float)((float)(p_z[9] * offset->y) + (float)(p_z[8] * offset->x)) + (float)(p_z[10] * offset->z))
              + p_z[11];
      p_z += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
  if ( v3 < planeCount )
  {
    p_dist = &pPlanes[v3].dist;
    v7 = planeCount - v3;
    do
    {
      *p_dist = (float)((float)((float)(*(p_dist - 3) * offset->x) + (float)(*(p_dist - 2) * offset->y))
                      + (float)(offset->z * *(p_dist - 1)))
              + *p_dist;
      p_dist += 5;
      --v7;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AFCE0
// Name: int FindMinBrush(class CCollisionBSPData __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindMinBrush(CCollisionBSPData *pBSPData, int nodenum, int brushIndex)
{
  int v3; // ecx
  int result; // eax
  cnode_t *v5; // esi
  int v6; // ecx

  v3 = nodenum;
  for ( result = brushIndex; v3 >= 0; v3 = v5->children[1] )
  {
    v5 = &pBSPData->map_rootnode[v3];
    result = FindMinBrush(pBSPData, nodenum: v5->children[0], brushIndex: result);
  }
  v6 = pBSPData->map_leafbrushes.m_pArray[pBSPData->map_leafs.m_pArray[-v3 - 1].firstleafbrush];
  if ( v6 < result )
    return v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AFD40
// Name: void DrawLeafvis(struct leafvis_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DrawLeafvis(_BYTE *a1@<ebx>, leafvis_t *pVis)
{
  IMesh *v2; // esi
  float *p_y; // ebx
  int v4; // eax
  leafvis_t::Polygon_t *m_pMemory; // ecx
  int m_nVertCount; // ebx
  leafvis_t::Polygon_t *v7; // eax
  int v8; // esi
  void (__thiscall *v9)(int, int); // edx
  int v10; // esi
  int v11; // edi
  Vector *v12; // eax
  int v13; // ecx
  int v14; // eax
  _BYTE v16[504]; // [esp+18h] [ebp-208h] OVERLAPPED BYREF
  IMesh *pMesh; // [esp+210h] [ebp-10h]
  int i; // [esp+214h] [ebp-Ch]
  int nMask; // [esp+218h] [ebp-8h]
  int v20; // [esp+21Ch] [ebp-4h]

  v2 = (IMesh *)materials->GetRenderContext(this: materials);
  pMesh = v2;
  if ( v2 != nullptr )
    v2->IsDynamic(this: v2);
  if ( mat_leafvis_draw_mask.m_pParent != nullptr )
    *(_DWORD *)&v16[496] = mat_leafvis_draw_mask.m_pParent->m_Value.m_nValue;
  else
    *(_DWORD *)&v16[496] = 0;
  p_y = &pVis->m_Colors[0].y;
  nMask = 0;
  i = 1;
  *(_DWORD *)&v16[500] = &pVis->m_Colors[0].y;
  do
  {
    v20 = 0;
    if ( (*(_DWORD *)&v16[496] & i) != 0 )
    {
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))g_materialLeafVisWireframe->ColorModulate)(
        a1: *(p_y - 1),
        a2: *p_y,
        a3: p_y[1]);
      v2->ValidateData(this: v2, a2: (int)g_materialLeafVisWireframe, a3: nullptr);
      v4 = 0;
      *(_DWORD *)&v16[492] = 0;
      if ( pVis->m_Polygons.m_Size > 0 )
      {
        do
        {
          m_pMemory = pVis->m_Polygons.m_Memory.m_pMemory;
          m_nVertCount = m_pMemory[v4].m_nVertCount;
          v7 = &m_pMemory[v4];
          if ( m_nVertCount >= 3 && nMask == v7->m_DrawGroup )
          {
            v8 = ((int (__thiscall *)(IMesh *, int, _DWORD, _DWORD, _DWORD, _BYTE *))v2->IVertexBuffer::__vftable[1].AccessRawHardwareDataStream)(
                   a1: v2,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a1);
            memset(&v16[208], 0, 12);
            *(_DWORD *)&v16[224] = 0;
            *(_DWORD *)&v16[228] = 0;
            *(_DWORD *)&v16[232] = -1;
            *(_DWORD *)&v16[236] = 0;
            *(_DWORD *)&v16[408] = 0;
            *(_DWORD *)&v16[476] = -1;
            *(_DWORD *)&v16[480] = 0;
            memset(&v16[416], 0, 12);
            *(_DWORD *)&v16[472] = 0;
            *(_DWORD *)&v16[320] = -1;
            *(_DWORD *)&v16[180] = v8;
            v16[188] = 1;
            *(_DWORD *)&v16[184] = 1;
            v9 = *(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 40);
            *(_DWORD *)&v16[488] = v8;
            v9(a1: v8, a2: 1);
            (*(void (__thiscall **)(_DWORD, int, int, _BYTE *, _DWORD))(**(_DWORD **)&v16[180] + 68))(
              a1: *(_DWORD *)&v16[180],
              a2: 2 * m_nVertCount,
              a3: 2 * m_nVertCount,
              a4: v16,
              a5: 0);
            *(_DWORD *)&v16[208] = v8 + 4;
            *(_DWORD *)&v16[220] = *(_DWORD *)&v16[156];
            *(_DWORD *)&v16[212] = 2 * m_nVertCount;
            *(_DWORD *)&v16[408] = v8;
            *(_DWORD *)&v16[216] = 0;
            *(_DWORD *)&v16[204] = *(_DWORD *)&v16[176];
            v16[240] = 0;
            *(_DWORD *)&v16[192] = *(_DWORD *)&v16[164];
            qmemcpy(&v16[244], v16, 164);
            v10 = 0;
            *(_DWORD *)&v16[416] = 2 * m_nVertCount;
            *(_DWORD *)&v16[324] = *(_DWORD *)&v16[80] != 0 ? 2 : 0;
            *(_DWORD *)&v16[420] = 0;
            v16[412] = 0;
            if ( *(_DWORD *)&v16[476] == -1 )
            {
              *(_DWORD *)&v16[472] = 0;
              *(_DWORD *)&v16[476] = *(_DWORD *)&v16[160];
              *(_DWORD *)&v16[480] = *(_DWORD *)&v16[156];
            }
            *(_DWORD *)&v16[224] = 0;
            CVertexBuilder::Reset(this: (CVertexBuilder *)&v16[244]);
            v11 = v20;
            do
            {
              **(Vector **)&v16[428] = pVis->verts.m_Memory.m_pMemory[v11];
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&v16[244]);
              v12 = &pVis->verts.m_Memory.m_pMemory[v20 + ++v10 % m_nVertCount];
              v13 = *(_DWORD *)&v16[428];
              **(float **)&v16[428] = v12->x;
              *(float *)(v13 + 4) = v12->y;
              *(float *)(v13 + 8) = v12->z;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&v16[244]);
              ++v11;
            }
            while ( v10 < m_nVertCount );
            if ( v16[188] != 0 )
            {
              switch ( *(_DWORD *)&v16[184] )
              {
                case 4:
                  v14 = 2 * *(_DWORD *)&v16[420] - 2;
                  break;
                case 5:
                  v14 = 2 * *(_DWORD *)&v16[420];
                  break;
                case 6:
                  v14 = 3 * *(_DWORD *)&v16[420] - 6;
                  break;
                case 7:
                  v14 = 6 * *(_DWORD *)&v16[420] / 4;
                  break;
                case 0xA:
                  v14 = 0;
                  break;
                default:
                  v14 = *(_DWORD *)&v16[420];
                  break;
              }
              CIndexBuilder::GenerateIndices(
                this: (CIndexBuilder *)&v16[192],
                primitiveType: *(MaterialPrimitiveType_t *)&v16[184],
                nIndexCount: v14);
            }
            a1 = v16;
            (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)&v16[180] + 80))(
              a1: *(_DWORD *)&v16[180],
              a2: *(_DWORD *)&v16[420],
              a3: *(_DWORD *)&v16[216]);
            *(_DWORD *)&v16[208] = 0;
            *(_DWORD *)&v16[212] = 0;
            *(_DWORD *)&v16[416] = 0;
            *(_DWORD *)&v16[408] = 0;
            *(_DWORD *)&v16[320] = -1;
            *(_DWORD *)&v16[180] = 0;
            (*(void (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)&v16[488] + 48))(
              a1: *(_DWORD *)&v16[488],
              a2: -1,
              a3: 0);
            if ( *(_DWORD *)&v16[408] != 0
              && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&v16[408] + 8))(a1: *(_DWORD *)&v16[408]) != 0 )
            {
              (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&v16[408] + 16))(a1: *(_DWORD *)&v16[408]);
            }
            if ( *(_DWORD *)&v16[208] != 0
              && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&v16[208] + 8))(a1: *(_DWORD *)&v16[208]) != 0 )
            {
              (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&v16[208] + 16))(a1: *(_DWORD *)&v16[208]);
            }
            v2 = pMesh;
          }
          v20 += m_nVertCount;
          v4 = *(_DWORD *)&v16[492] + 1;
          *(_DWORD *)&v16[492] = v4;
        }
        while ( v4 < pVis->m_Polygons.m_Size );
        p_y = *(float **)&v16[500];
      }
    }
    p_y += 3;
    ++nMask;
    *(_DWORD *)&v16[500] = p_y;
    i = __ROL4__(i, 1);
  }
  while ( nMask < 4 );
  if ( v2 != nullptr )
  {
    ((void (__thiscall *)(IMesh *))v2->BeginCastBuffer)(a1: v2);
    v2->GetVertexFormat(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0130
// Name: void DrawLeafvis_Solid(struct leafvis_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawLeafvis_Solid(CMeshBuilder *p_meshBuilder@<edi>, leafvis_t *pVis)
{
  IMatRenderContext *m_pObject; // esi
  leafvis_t *v3; // ecx
  int v4; // eax
  int m_nVertCount; // edi
  IMesh *v6; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int v8; // edi
  int v9; // edx
  int v10; // esi
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  int v17; // eax
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  int v22; // ecx
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-230h] BYREF
  float v27; // [esp+1F0h] [ebp-48h]
  float v28; // [esp+1F4h] [ebp-44h]
  float v29; // [esp+1F8h] [ebp-40h]
  float v30; // [esp+1FCh] [ebp-3Ch]
  float v31; // [esp+200h] [ebp-38h]
  IMesh *pMesh; // [esp+204h] [ebp-34h]
  float v33; // [esp+208h] [ebp-30h]
  Vector normal; // [esp+20Ch] [ebp-2Ch] BYREF
  Vector lightNormal; // [esp+218h] [ebp-20h] BYREF
  int i; // [esp+224h] [ebp-14h]
  CMatRenderContextPtr pRenderContext; // [esp+228h] [ebp-10h]
  int vert; // [esp+22Ch] [ebp-Ch]
  int vertCount; // [esp+230h] [ebp-8h]
  int triangleCount; // [esp+234h] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  vert = 0;
  lightNormal.x = 1.0;
  lightNormal.y = 1.0;
  lightNormal.z = 1.0;
  VectorNormalize(vec: &lightNormal);
  m_pObject->Bind(this: m_pObject, a2: g_pMaterialDebugFlat, a3: nullptr);
  v3 = pVis;
  v4 = 0;
  for ( i = 0; v4 < pVis->m_Polygons.m_Size; i = v4 )
  {
    m_nVertCount = v3->m_Polygons.m_Memory.m_pMemory[v4].m_nVertCount;
    vertCount = m_nVertCount;
    if ( m_nVertCount >= 3 )
    {
      v6 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))m_pObject->GetDynamicMesh)(
                      a1: m_pObject,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0,
                      a6: p_meshBuilder);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_pMesh = v6;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_TRIANGLES;
      SetPrimitiveType = v6->SetPrimitiveType;
      v8 = 3 * m_nVertCount - 6;
      pMesh = v6;
      triangleCount = v8;
      SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v8, a3: v8, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v8;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v6;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = triangleCount;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      v9 = 3 * vert + 6;
      v10 = vert;
      v11 = *(&pVis->verts.m_Memory.m_pMemory->z + v9) - pVis->verts.m_Memory.m_pMemory[vert].z;
      v12 = *(&pVis->verts.m_Memory.m_pMemory->y + v9) - pVis->verts.m_Memory.m_pMemory[vert].y;
      v13 = pVis->verts.m_Memory.m_pMemory[vert + 1].x - pVis->verts.m_Memory.m_pMemory[vert].x;
      v14 = pVis->verts.m_Memory.m_pMemory[vert + 1].y - pVis->verts.m_Memory.m_pMemory[vert].y;
      v15 = pVis->verts.m_Memory.m_pMemory[vert + 1].z - pVis->verts.m_Memory.m_pMemory[vert].z;
      v16 = *(&pVis->verts.m_Memory.m_pMemory->x + v9) - pVis->verts.m_Memory.m_pMemory[vert].x;
      normal.x = (float)(v12 * v15) - (float)(v11 * v14);
      normal.y = (float)(v11 * v13) - (float)(v15 * v16);
      normal.z = (float)(v14 * v16) - (float)(v12 * v13);
      VectorNormalize(vec: &normal);
      v17 = vertCount;
      v18 = (float)((float)((float)((float)(normal.y * lightNormal.y) + (float)(normal.x * lightNormal.x))
                          + (float)(normal.z * lightNormal.z))
                  * 0.5)
          + 0.5;
      v19 = pVis->m_Colors[0].x * v18;
      v20 = pVis->m_Colors[0].y * v18;
      if ( vertCount > 0 )
      {
        v28 = (float)((float)(pVis->m_Colors[0].z * v18) * 255.0) + 8388608.0;
        v30 = (float)(v20 * 255.0) + 8388608.0;
        v33 = (float)(v19 * 255.0) + 8388608.0;
        for ( triangleCount = vertCount; triangleCount != 0; --triangleCount )
        {
          v21 = v28;
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = pVis->verts.m_Memory.m_pMemory[v10];
          v29 = v21;
          v27 = v30;
          v31 = v33;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v21)
                                                              | ((LOBYTE(v30) | ((LOBYTE(v33) | 0xFFFFFF00) << 8)) << 8);
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v10;
        }
        v17 = vertCount;
      }
      v22 = 0;
      triangleCount = v17 - 2;
      if ( v17 - 2 > 0 )
      {
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                            + v22
                                                                                            + 2;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                            + v22
                                                                                            + 1;
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          ++v22;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( v22 < triangleCount );
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
      p_meshBuilder = &meshBuilder;
      ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
      m_nVertCount = vertCount;
    }
    v3 = pVis;
    vert += m_nVertCount;
    v4 = i + 1;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100B06C0
// Name: public: leafvis_t::leafvis_t(void)
// Source: json
//------------------------------------------------------------------------------
leafvis_t *__thiscall leafvis_t::leafvis_t(leafvis_t *this)
{
  this->verts.m_Memory.m_pMemory = nullptr;
  this->verts.m_Memory.m_nAllocationCount = 0;
  this->verts.m_Memory.m_nGrowSize = 0;
  this->verts.m_Size = 0;
  this->verts.m_pElements = nullptr;
  this->m_Polygons.m_Memory.m_pMemory = nullptr;
  this->m_Polygons.m_Memory.m_nAllocationCount = 0;
  this->m_Polygons.m_Memory.m_nGrowSize = 0;
  this->m_Polygons.m_Size = 0;
  this->m_Polygons.m_pElements = nullptr;
  memset(dst: (unsigned __int8 *)this->m_Colors, value: 0, count: sizeof(this->m_Colors));
  this->leafIndex = 0;
  this->numbrushes = g_BSPData.numbrushes;
  this->numentitychars = g_BSPData.numentitychars;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B0900
// Name: void CSGPlaneList(struct leafvis_t __near *,class CUtlVector<struct cplane_t,class CUtlMemory<struct cplane_t,int>> __near &,enum DrawGroup_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSGPlaneList(
        CUtlMemory<CVTFTexture::ResourceMemorySection,int> *pVis,
        CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > *planeList,
        DrawGroup_t drawGroup)
{
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > *v3; // esi
  float v4; // ebx
  cplane_t *m_pMemory; // edi
  const Vector *v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // esi
  cplane_t *v10; // eax
  int v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // ecx
  double v16; // st7
  unsigned int v17; // eax
  int v18; // ecx
  double v19; // st7
  float y; // ecx
  int v21; // eax
  leafvis_t::Polygon_t *m_nGrowSize; // edx
  int v23; // eax
  leafvis_t::Polygon_t *v24; // ecx
  float v25; // edx
  int v26; // esi
  int m_nAllocationCount; // eax
  Vector *v28; // ecx
  int v29; // eax
  Vector *v30; // eax
  _BYTE v31[20]; // [esp-18h] [ebp-C4Ch]
  float v32[4]; // [esp-4h] [ebp-C38h]
  Vector outVerts; // [esp+Ch] [ebp-C28h] BYREF
  Vector vertsOut[128]; // [esp+2Ch] [ebp-C08h] BYREF
  Vector vertsIn[128]; // [esp+62Ch] [ebp-608h] BYREF
  Vector insidePoint; // [esp+C2Ch] [ebp-8h] BYREF

  v3 = planeList;
  v4 = *(float *)&planeList->m_Size;
  m_pMemory = planeList->m_Memory.m_pMemory;
  vertsIn[126].y = v4;
  CSGInsidePoint(result: (Vector *)&vertsIn[125].y, pPlanes: m_pMemory, planeCount: SLODWORD(v4));
  vertsIn[126].z = -vertsIn[125].y;
  vertsIn[127].x = -vertsIn[125].z;
  vertsIn[127].y = -vertsIn[126].x;
  TranslatePlaneList(pPlanes: m_pMemory, planeCount: SLODWORD(v4), offset: (Vector *)&vertsIn[126].z);
  insidePoint.x = 0.0;
  if ( SLODWORD(v4) > 0 )
  {
    vertsIn[127].z = 0.0;
    while ( 1 )
    {
      v6 = (Vector *)((char *)&v3->m_Memory.m_pMemory->normal + LODWORD(vertsIn[127].z));
      v32[0] = 9000.0;
      v7 = PolyFromPlane(pOutVerts: (Vector *)&vertsOut[125].y, normal: v6, dist: v6[1].x, fHalfScale: 9000.0);
      v8 = 0;
      insidePoint.y = 0.0;
      v9 = 0;
      do
      {
        if ( LODWORD(insidePoint.x) != v8 && v7 >= 3 )
        {
          v10 = planeList->m_Memory.m_pMemory;
          v32[0] = 0.1;
          v11 = ClipPolyToPlane(
                  inVerts: (Vector *)&vertsOut[125].y,
                  vertCount: v7,
                  &outVerts,
                  normal: &v10[v9].normal,
                  dist: v10[v9].dist,
                  fOnPlaneEpsilon: 0.1);
          v7 = v11;
          v12 = 0;
          if ( v11 >= 4 )
          {
            v13 = (unsigned int)(v11 - 4) >> 2;
            v14 = 0;
            v15 = v13 + 1;
            v12 = 4 * v15;
            do
            {
              v16 = *(float *)((char *)&outVerts.x + v14);
              v14 += 48;
              --v15;
              vertsOut[v14 / 0xC + 121].y = v16;
              vertsOut[v14 / 0xC + 121].z = *(float *)((char *)&insidePoint.z + v14 - 3156);
              vertsOut[v14 / 0xC + 122].x = *(float *)((char *)&insidePoint.z + v14 - 3152);
              vertsOut[v14 / 0xC + 122].y = *(float *)&v31[v14];
              vertsOut[v14 / 0xC + 122].z = *(float *)&v31[v14 + 4];
              vertsOut[v14 / 0xC + 123].x = *(float *)&v31[v14 + 8];
              vertsOut[v14 / 0xC + 123].y = *(float *)&v31[v14 + 12];
              vertsOut[v14 / 0xC + 123].z = *(float *)&v31[v14 + 16];
              vertsOut[v14 / 0xC + 124].x = v32[v14 / 4];
              vertsOut[v14 / 0xC + 124].y = v32[v14 / 4 + 1];
              vertsOut[v14 / 0xC + 124].z = v32[v14 / 4 + 2];
              vertsOut[v14 / 0xC + 125].x = v32[v14 / 4 + 3];
            }
            while ( v15 != 0 );
          }
          if ( v12 < v7 )
          {
            v17 = 12 * v12;
            v18 = v7 - v12;
            do
            {
              v19 = *(float *)((char *)&outVerts.x + v17);
              v17 += 12;
              --v18;
              vertsOut[v17 / 0xC + 124].y = v19;
              vertsOut[v17 / 0xC + 124].z = v32[v17 / 4 + 2];
              vertsOut[v17 / 0xC + 125].x = v32[v17 / 4 + 3];
            }
            while ( v18 != 0 );
          }
        }
        v8 = LODWORD(insidePoint.y) + 1;
        ++v9;
        LODWORD(insidePoint.y) = v8;
      }
      while ( v8 < SLODWORD(vertsIn[126].y) );
      if ( v7 >= 3 )
      {
        v21 = (int)pVis[2].m_pMemory;
        LODWORD(insidePoint.y) = pVis[2].m_nGrowSize;
        y = insidePoint.y;
        if ( LODWORD(insidePoint.y) + 1 > v21 )
        {
          CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
            this: (CUtlMemory<ResourceEntryInfo,int> *)&pVis[1].m_nGrowSize,
            num: LODWORD(insidePoint.y) - v21 + 1);
          y = insidePoint.y;
        }
        ++pVis[2].m_nGrowSize;
        m_nGrowSize = (leafvis_t::Polygon_t *)pVis[1].m_nGrowSize;
        v23 = pVis[2].m_nGrowSize - LODWORD(y) - 1;
        pVis[3].m_pMemory = (CVTFTexture::ResourceMemorySection *)m_nGrowSize;
        if ( v23 > 0 )
        {
          _V_memmove(dest: &m_nGrowSize[LODWORD(y) + 1], src: &m_nGrowSize[LODWORD(y)], count: 8 * v23);
          y = insidePoint.y;
        }
        v24 = (leafvis_t::Polygon_t *)(pVis[1].m_nGrowSize + 8 * LODWORD(y));
        if ( v24 != nullptr )
        {
          v24->m_nVertCount = v7;
          v24->m_DrawGroup = drawGroup;
        }
        v25 = COERCE_FLOAT(&vertsOut[126]);
        LODWORD(insidePoint.y) = &vertsOut[126];
        do
        {
          v26 = (int)pVis[1].m_pMemory;
          m_nAllocationCount = pVis->m_nAllocationCount;
          vertsIn[126].z = *(float *)(LODWORD(v25) - 8) + vertsIn[125].y;
          vertsIn[127].x = *(float *)(LODWORD(v25) - 4) + vertsIn[125].z;
          vertsIn[127].y = vertsIn[126].x + *(float *)LODWORD(v25);
          if ( v26 + 1 > m_nAllocationCount )
          {
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
              this: pVis,
              num: v26 - m_nAllocationCount + 1);
            v25 = insidePoint.y;
          }
          ++pVis[1].m_pMemory;
          v28 = (Vector *)pVis->m_pMemory;
          v29 = (int)pVis[1].m_pMemory - v26 - 1;
          pVis[1].m_nAllocationCount = (int)pVis->m_pMemory;
          if ( v29 > 0 )
          {
            _V_memmove(dest: &v28[v26 + 1], src: &v28[v26], count: 12 * v29);
            v25 = insidePoint.y;
          }
          v30 = (Vector *)&pVis->m_pMemory[v26];
          if ( v30 != nullptr )
          {
            v30->x = vertsIn[126].z;
            v30->y = vertsIn[127].x;
            v30->z = vertsIn[127].y;
          }
          LODWORD(v25) += 12;
          --v7;
          insidePoint.y = v25;
        }
        while ( v7 != 0 );
      }
      LODWORD(vertsIn[127].z) += 20;
      ++LODWORD(insidePoint.x);
      if ( SLODWORD(insidePoint.x) >= SLODWORD(vertsIn[126].y) )
        break;
      v3 = planeList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0C50
// Name: void AddLeafPortals(struct leafvis_t __near *,int,enum DrawGroup_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddLeafPortals(leafvis_t *pLeafvis, int leafIndex, DrawGroup_t drawGroup)
{
  float y; // xmm5_4
  float z; // xmm6_4
  int m_Size; // esi
  int v6; // ecx
  cplane_t *m_pMemory; // edi
  float *p_z; // edx
  int v9; // ebx
  _DWORD *p_x; // eax
  int v11; // edx
  float *v12; // ecx
  int v13; // ebx
  cplane_t *v14; // eax
  int v15; // edx
  float *v16; // ecx
  int v17; // ebx
  float *v18; // eax
  int v19; // edx
  float *v20; // ecx
  int v21; // ebx
  cplane_t *v22; // eax
  int v23; // edx
  float *v24; // ecx
  int v25; // ebx
  _DWORD *v26; // eax
  int v27; // edx
  float *v28; // ecx
  int v29; // ebx
  int v30; // esi
  _DWORD *v31; // edi
  cplane_t *v32; // eax
  cplane_t *v33; // eax
  cplane_t *v34; // eax
  cplane_t *v35; // eax
  cplane_t *v36; // eax
  cplane_t *v37; // eax
  int v38; // [esp+10h] [ebp-38h]
  int v39; // [esp+14h] [ebp-34h]
  float v40; // [esp+14h] [ebp-34h]
  float v41; // [esp+14h] [ebp-34h]
  int v42; // [esp+1Ch] [ebp-2Ch]
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > planeList; // [esp+20h] [ebp-28h] BYREF
  Vector normal; // [esp+34h] [ebp-14h]
  float v45; // [esp+40h] [ebp-8h]
  float v46; // [esp+44h] [ebp-4h]

  memset(&planeList, 0, sizeof(planeList));
  sub_100B0710(
    leafIndex,
    (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
    model: (mnode_t *)host_state.worldmodel);
  y = vec3_origin.y;
  z = vec3_origin.z;
  m_Size = planeList.m_Size;
  v6 = 0;
  m_pMemory = planeList.m_Memory.m_pMemory;
  normal.y = vec3_origin.y;
  normal.z = vec3_origin.z;
  LODWORD(v46) = LODWORD(vec3_origin.z) ^ _mask__NegFloat_;
  v38 = LODWORD(vec3_origin.y) ^ _mask__NegFloat_;
  v39 = LODWORD(vec3_origin.z) ^ _mask__NegFloat_;
  if ( planeList.m_Size <= 0 )
  {
LABEL_7:
    v9 = planeList.m_Size;
    if ( planeList.m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: planeList.m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
      z = normal.z;
      y = normal.y;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v9 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 20 * (m_Size - v9 - 1));
      z = normal.z;
      y = normal.y;
    }
    p_x = (_DWORD *)&m_pMemory[v9].normal.x;
    if ( p_x != nullptr )
    {
      *p_x = -1082130432;
      p_x[1] = v38;
      p_x[2] = v39;
      p_x[3] = -964689920;
      p_x[4] = v42;
    }
  }
  else
  {
    p_z = &planeList.m_Memory.m_pMemory->normal.z;
    while ( *(p_z - 2) != -1.0
         || COERCE_FLOAT(LODWORD(vec3_origin.y) ^ _mask__NegFloat_) != *(p_z - 1)
         || COERCE_FLOAT(LODWORD(vec3_origin.z) ^ _mask__NegFloat_) != *p_z )
    {
      ++v6;
      p_z += 5;
      if ( v6 >= planeList.m_Size )
        goto LABEL_7;
    }
    v32 = &planeList.m_Memory.m_pMemory[v6];
    if ( (float)((float)((float)((float)(v32->normal.y
                                       * (float)(COERCE_FLOAT(LODWORD(vec3_origin.y) ^ _mask__NegFloat_) * -16384.0))
                               + (float)(v32->normal.x * 16384.0))
                       + (float)(v32->normal.z
                               * (float)(COERCE_FLOAT(LODWORD(vec3_origin.z) ^ _mask__NegFloat_) * -16384.0)))
               - v32->dist) > 0.0 )
      v32->dist = -16384.0;
  }
  v11 = 0;
  v40 = z;
  v45 = z * -16384.0;
  if ( m_Size <= 0 )
  {
LABEL_19:
    v13 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
      z = normal.z;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v13 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: 20 * (m_Size - v13 - 1));
      z = normal.z;
    }
    v14 = &m_pMemory[v13];
    if ( v14 != nullptr )
    {
      v14->normal.x = 1.0;
      v14->normal.y = y;
      v14->normal.z = v40;
      v14->dist = -16384.0;
      *(_DWORD *)&v14->type = v42;
    }
  }
  else
  {
    v12 = &m_pMemory->normal.z;
    while ( *(v12 - 2) != 1.0 || y != *(v12 - 1) || z != *v12 )
    {
      ++v11;
      v12 += 5;
      if ( v11 >= m_Size )
        goto LABEL_19;
    }
    v33 = &m_pMemory[v11];
    if ( (float)((float)((float)((float)(v33->normal.y * (float)(y * -16384.0)) - (float)(v33->normal.x * 16384.0))
                       + (float)(v33->normal.z * (float)(z * -16384.0)))
               - v33->dist) > 0.0 )
      v33->dist = -16384.0;
  }
  v15 = 0;
  v41 = v46;
  if ( m_Size <= 0 )
  {
LABEL_31:
    v17 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
      z = normal.z;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v17 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 20 * (m_Size - v17 - 1));
      z = normal.z;
    }
    v18 = &m_pMemory[v17].normal.x;
    if ( v18 != nullptr )
    {
      *v18 = -0.0;
      v18[1] = -1.0;
      v18[2] = v41;
      v18[3] = -16384.0;
      *((_DWORD *)v18 + 4) = v42;
    }
  }
  else
  {
    v16 = &m_pMemory->normal.z;
    while ( *(v16 - 2) != -0.0 || *(v16 - 1) != -1.0 || v46 != *v16 )
    {
      ++v15;
      v16 += 5;
      if ( v15 >= m_Size )
        goto LABEL_31;
    }
    v34 = &m_pMemory[v15];
    if ( (float)((float)((float)((float)(v34->normal.y * 16384.0) + (float)(v34->normal.x * 0.0))
                       + (float)(v34->normal.z * (float)(v46 * -16384.0)))
               - v34->dist) > 0.0 )
      v34->dist = -16384.0;
  }
  v19 = 0;
  if ( m_Size <= 0 )
  {
LABEL_43:
    v21 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v21 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v21 + 1], src: &m_pMemory[v21], count: 20 * (m_Size - v21 - 1));
    v22 = &m_pMemory[v21];
    if ( v22 != nullptr )
    {
      v22->normal.x = 0.0;
      v22->normal.y = 1.0;
      v22->normal.z = z;
      v22->dist = -16384.0;
      *(_DWORD *)&v22->type = v42;
    }
  }
  else
  {
    v20 = &m_pMemory->normal.z;
    while ( *(v20 - 2) != 0.0 || *(v20 - 1) != 1.0 || z != *v20 )
    {
      ++v19;
      v20 += 5;
      if ( v19 >= m_Size )
        goto LABEL_43;
    }
    v35 = &m_pMemory[v19];
    if ( (float)((float)((float)((float)(v35->normal.x * -0.0) - (float)(v35->normal.y * 16384.0))
                       + (float)(v35->normal.z * v45))
               - v35->dist) > 0.0 )
      v35->dist = -16384.0;
  }
  v23 = 0;
  if ( m_Size <= 0 )
  {
LABEL_55:
    v25 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v25 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v25 + 1], src: &m_pMemory[v25], count: 20 * (m_Size - v25 - 1));
    v26 = (_DWORD *)&m_pMemory[v25].normal.x;
    if ( v26 != nullptr )
    {
      *v26 = 0x80000000;
      v26[1] = 0x80000000;
      v26[2] = -1082130432;
      v26[3] = -964689920;
      v26[4] = v42;
    }
  }
  else
  {
    v24 = &m_pMemory->normal.z;
    while ( *(v24 - 2) != -0.0 || *(v24 - 1) != -0.0 || *v24 != -1.0 )
    {
      ++v23;
      v24 += 5;
      if ( v23 >= m_Size )
        goto LABEL_55;
    }
    v36 = &m_pMemory[v23];
    if ( (float)((float)((float)((float)(v36->normal.y + v36->normal.x) * 0.0) + (float)(v36->normal.z * 16384.0))
               - v36->dist) > 0.0 )
      v36->dist = -16384.0;
  }
  v27 = 0;
  if ( m_Size <= 0 )
  {
LABEL_67:
    v29 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
    }
    planeList.m_Size = m_Size + 1;
    v30 = m_Size - v29;
    planeList.m_pElements = m_pMemory;
    if ( v30 > 0 )
      _V_memmove(dest: &m_pMemory[v29 + 1], src: &m_pMemory[v29], count: 20 * v30);
    v31 = (_DWORD *)&m_pMemory[v29].normal.x;
    if ( v31 != nullptr )
    {
      *v31 = 0;
      v31[1] = 0;
      v31[2] = 1065353216;
      v31[3] = -964689920;
      v31[4] = v42;
    }
  }
  else
  {
    v28 = &m_pMemory->normal.z;
    while ( *(v28 - 2) != 0.0 || *(v28 - 1) != 0.0 || *v28 != 1.0 )
    {
      ++v27;
      v28 += 5;
      if ( v27 >= m_Size )
        goto LABEL_67;
    }
    v37 = &m_pMemory[v27];
    if ( (float)((float)((float)((float)(v37->normal.y + v37->normal.x) * -0.0) - (float)(v37->normal.z * 16384.0))
               - v37->dist) > 0.0 )
      v37->dist = -16384.0;
  }
  CSGPlaneList(pVis: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)pLeafvis, &planeList, drawGroup);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&planeList);
}

//------------------------------------------------------------------------------
// Address: 0x100B1430
// Name: void RecomputeClipbrushes(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecomputeClipbrushes(bool bEnabled)
{
  leafvis_t **v1; // ebx
  int v2; // edi
  leafvis_t *v3; // esi
  leafvis_t::Polygon_t *m_pMemory; // eax
  Vector *v5; // eax
  int v6; // ebx
  unsigned __int8 *v7; // eax
  leafvis_t *v8; // esi
  int v9; // xmm0_4
  double v10; // st7
  int numbrushes; // eax
  int headnode; // ecx
  cnode_t *map_rootnode; // ebx
  cnode_t *v14; // esi
  int v15; // ecx
  cbrush_t *m_pArray; // ecx
  int m_Size; // esi
  __int16 v18; // ax
  cplane_t *v19; // ebx
  cboxbrush_t *v20; // eax
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  int v25; // ecx
  float *p_z; // edx
  int v27; // edi
  cplane_t *v28; // eax
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  int v33; // edx
  float *v34; // ecx
  int v35; // edi
  cplane_t *v36; // eax
  bool v37; // zf
  float *p_x; // eax
  cplane_t *v39; // eax
  int v40; // eax
  int v41; // edx
  cplane_t *plane; // eax
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  int v47; // ecx
  float *v48; // edx
  int v49; // edi
  cplane_t *v50; // eax
  int v51; // ecx
  float *v52; // eax
  float v53; // [esp+Ch] [ebp-70h]
  float v54; // [esp+10h] [ebp-6Ch]
  float v55; // [esp+14h] [ebp-68h]
  int v56; // [esp+1Ch] [ebp-60h]
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > planeList; // [esp+20h] [ebp-5Ch] BYREF
  float v58; // [esp+3Ch] [ebp-40h]
  int contents[3]; // [esp+40h] [ebp-3Ch]
  Vector normal; // [esp+4Ch] [ebp-30h] BYREF
  unsigned __int16 *p_firstbrushside; // [esp+58h] [ebp-24h]
  int v62; // [esp+5Ch] [ebp-20h]
  int lastBrush; // [esp+60h] [ebp-1Ch]
  int p_numsides; // [esp+64h] [ebp-18h]
  float v65; // [esp+68h] [ebp-14h]
  float v66; // [esp+6Ch] [ebp-10h]
  float v67; // [esp+70h] [ebp-Ch]
  int i; // [esp+74h] [ebp-8h]
  int j; // [esp+78h] [ebp-4h]
  int v; // [esp+84h] [ebp+8h]

  v1 = g_ClipVis;
  v2 = 0;
  do
  {
    v3 = *v1;
    if ( *v1 != nullptr )
    {
      v3->m_Polygons.m_Size = 0;
      if ( v3->m_Polygons.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Polygons.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Polygons.m_Memory.m_pMemory);
          v3->m_Polygons.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Polygons.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Polygons.m_Memory.m_pMemory;
      v3->m_Polygons.m_pElements = m_pMemory;
      if ( v3->m_Polygons.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Polygons.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Polygons.m_Memory.m_nAllocationCount = 0;
      }
      v3->verts.m_Size = 0;
      if ( v3->verts.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->verts.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->verts.m_Memory.m_pMemory);
          v3->verts.m_Memory.m_pMemory = nullptr;
        }
        v3->verts.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->verts.m_Memory.m_pMemory;
      v3->verts.m_pElements = v3->verts.m_Memory.m_pMemory;
      if ( v3->verts.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          v3->verts.m_Memory.m_pMemory = nullptr;
        }
        v3->verts.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
    }
    *v1++ = nullptr;
  }
  while ( (int)v1 < (int)&dword_104EF50C );
  if ( bEnabled )
  {
    v6 = 0;
    v = 0;
    contents[0] = 196608;
    contents[1] = 0x20000;
    contents[2] = 0x10000;
    while ( 1 )
    {
      v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x64u);
      v8 = (leafvis_t *)v7;
      if ( v7 != nullptr )
      {
        *(_DWORD *)v7 = 0;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        *((_DWORD *)v7 + 3) = 0;
        *((_DWORD *)v7 + 4) = 0;
        *((_DWORD *)v7 + 5) = 0;
        *((_DWORD *)v7 + 6) = 0;
        *((_DWORD *)v7 + 7) = 0;
        *((_DWORD *)v7 + 8) = 0;
        *((_DWORD *)v7 + 9) = 0;
        memset(dst: v7 + 40, value: 0, count: 0x30u);
        v8->leafIndex = 0;
        v8->numbrushes = g_BSPData.numbrushes;
        v8->numentitychars = g_BSPData.numentitychars;
      }
      else
      {
        v8 = nullptr;
      }
      g_ClipVis[v6] = v8;
      if ( v6 != 0 )
      {
        v9 = 1065353216;
        if ( v6 == 1 )
          v10 = 0.5;
        else
          v10 = 1.0;
      }
      else
      {
        v9 = 0;
        v10 = 1.0;
      }
      v8->m_Colors[0].x = v10;
      v8->m_Colors[0].y = 0.0;
      LODWORD(v8->m_Colors[0].z) = v9;
      numbrushes = g_BSPData.numbrushes;
      lastBrush = g_BSPData.numbrushes;
      if ( g_BSPData.numcmodels > 1 )
      {
        headnode = g_BSPData.map_cmodels.m_pArray[1].headnode;
        if ( headnode >= 0 )
        {
          map_rootnode = g_BSPData.map_rootnode;
          do
          {
            v14 = &map_rootnode[headnode];
            numbrushes = FindMinBrush(pBSPData: &g_BSPData, nodenum: v14->children[0], brushIndex: numbrushes);
            headnode = v14->children[1];
          }
          while ( headnode >= 0 );
        }
        v15 = g_BSPData.map_leafbrushes.m_pArray[g_BSPData.map_leafs.m_pArray[-headnode - 1].firstleafbrush];
        if ( v15 < numbrushes )
          numbrushes = v15;
        lastBrush = numbrushes;
      }
      i = 0;
      if ( numbrushes > 0 )
        break;
LABEL_96:
      if ( ++v >= 3 )
        return;
      v6 = v;
      v2 = 0;
    }
    v62 = contents[v];
    m_pArray = g_BSPData.map_brushes.m_pArray;
    while ( (m_pArray[v2].contents & 0x30000) != v62 )
    {
LABEL_95:
      i = ++v2;
      if ( v2 >= lastBrush )
        goto LABEL_96;
    }
    m_Size = 0;
    p_numsides = (int)&m_pArray[v2].numsides;
    v18 = *(_WORD *)p_numsides;
    v19 = nullptr;
    memset(&planeList, 0, sizeof(planeList));
    if ( v18 == -1 )
    {
      v20 = &g_BSPData.map_boxbrushes.m_pArray[m_pArray[v2].firstbrushside];
      j = (int)v20;
      p_firstbrushside = (unsigned __int16 *)((char *)&normal - (char *)v20);
      p_numsides = 3;
      do
      {
        normal = vec3_origin;
        *(_DWORD *)((char *)p_firstbrushside + (_DWORD)v20) = 1065353216;
        v21 = -v20->maxs.x;
        v22 = -normal.z;
        v23 = -normal.x;
        v24 = -normal.y;
        v55 = -normal.z;
        v25 = 0;
        v53 = -normal.x;
        v54 = -normal.y;
        v67 = -normal.x;
        v66 = -normal.y;
        v65 = -normal.z;
        v58 = (float)-normal.z * v21;
        if ( m_Size <= 0 )
        {
LABEL_50:
          v27 = m_Size;
          if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
              this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
              num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
            m_Size = planeList.m_Size;
            v19 = planeList.m_Memory.m_pMemory;
            v23 = v67;
            v24 = v66;
            v22 = v65;
          }
          planeList.m_Size = ++m_Size;
          planeList.m_pElements = v19;
          if ( m_Size - v27 - 1 > 0 )
          {
            _V_memmove(dest: &v19[v27 + 1], src: &v19[v27], count: 20 * (m_Size - v27 - 1));
            v23 = v67;
            v24 = v66;
            v22 = v65;
          }
          v28 = &v19[v27];
          if ( v28 != nullptr )
          {
            v28->normal.x = v53;
            v28->normal.y = v54;
            v28->normal.z = v55;
            v28->dist = v21;
            *(_DWORD *)&v28->type = v56;
          }
        }
        else
        {
          p_z = &v19->normal.z;
          while ( v23 != *(p_z - 2) || v24 != *(p_z - 1) || v22 != *p_z )
          {
            ++v25;
            p_z += 5;
            if ( v25 >= m_Size )
              goto LABEL_50;
          }
          p_x = &v19[v25].normal.x;
          if ( (float)((float)((float)((float)(p_x[1] * (float)(v24 * v21)) + (float)(*p_x * (float)(v23 * v21)))
                             + (float)(p_x[2] * v58))
                     - p_x[3]) > 0.0 )
            p_x[3] = v21;
        }
        v29 = -v23;
        v30 = -v24;
        v31 = -v22;
        v32 = *(float *)j;
        v33 = 0;
        if ( m_Size <= 0 )
        {
LABEL_62:
          v35 = m_Size;
          if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
              this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
              num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
            m_Size = planeList.m_Size;
            v19 = planeList.m_Memory.m_pMemory;
          }
          planeList.m_Size = ++m_Size;
          planeList.m_pElements = v19;
          if ( m_Size - v35 - 1 > 0 )
            _V_memmove(dest: &v19[v35 + 1], src: &v19[v35], count: 20 * (m_Size - v35 - 1));
          v36 = &v19[v35];
          if ( v36 != nullptr )
          {
            v36->normal.x = v29;
            v36->normal.y = v30;
            v36->normal.z = v31;
            v36->dist = v32;
            *(_DWORD *)&v36->type = v56;
          }
        }
        else
        {
          v34 = &v19->normal.z;
          while ( v29 != *(v34 - 2) || v30 != *(v34 - 1) || v31 != *v34 )
          {
            ++v33;
            v34 += 5;
            if ( v33 >= m_Size )
              goto LABEL_62;
          }
          v39 = &v19[v33];
          if ( (float)((float)((float)((float)(v39->normal.y * (float)(v30 * *(float *)j))
                                     + (float)(v39->normal.x * (float)(v29 * *(float *)j)))
                             + (float)(v39->normal.z * (float)(v31 * *(float *)j)))
                     - v39->dist) > 0.0 )
            v39->dist = v32;
        }
        v20 = (cboxbrush_t *)(j + 4);
        v37 = p_numsides-- == 1;
        j += 4;
      }
      while ( !v37 );
    }
    else
    {
      j = 0;
      if ( v18 == 0 )
      {
LABEL_91:
        CSGPlaneList(
          pVis: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)g_ClipVis[v],
          &planeList,
          drawGroup: DG_BASE);
        if ( planeList.m_Memory.m_nGrowSize >= 0 && v19 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
        m_pArray = g_BSPData.map_brushes.m_pArray;
        goto LABEL_95;
      }
      p_firstbrushside = &m_pArray[v2].firstbrushside;
      v40 = 0;
      do
      {
        v41 = v40 + *p_firstbrushside;
        if ( g_BSPData.map_brushsides.m_pArray[v41].bBevel == 0 )
        {
          plane = g_BSPData.map_brushsides.m_pArray[v41].plane;
          v43 = -plane->dist;
          v44 = -plane->normal.x;
          v45 = -plane->normal.y;
          v46 = -plane->normal.z;
          v47 = 0;
          if ( m_Size <= 0 )
          {
LABEL_83:
            v49 = m_Size;
            if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
                this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
                num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
              m_Size = planeList.m_Size;
              v19 = planeList.m_Memory.m_pMemory;
            }
            planeList.m_Size = ++m_Size;
            planeList.m_pElements = v19;
            if ( m_Size - v49 - 1 > 0 )
              _V_memmove(dest: &v19[v49 + 1], src: &v19[v49], count: 20 * (m_Size - v49 - 1));
            v50 = &v19[v49];
            if ( v50 != nullptr )
            {
              v50->normal.x = v44;
              v50->normal.y = v45;
              v50->normal.z = v46;
              v50->dist = v43;
              *(_DWORD *)&v50->type = v56;
            }
          }
          else
          {
            v48 = &v19->normal.z;
            while ( v44 != *(v48 - 2) || v45 != *(v48 - 1) || v46 != *v48 )
            {
              ++v47;
              v48 += 5;
              if ( v47 >= m_Size )
                goto LABEL_83;
            }
            v52 = &v19[v47].normal.x;
            if ( (float)((float)((float)((float)(v52[1] * (float)(v45 * v43)) + (float)(*v52 * (float)(v44 * v43)))
                               + (float)(v52[2] * (float)(v46 * v43)))
                       - v52[3]) > 0.0 )
              v52[3] = v43;
          }
        }
        v51 = *(unsigned __int16 *)p_numsides;
        v40 = j + 1;
        j = v40;
      }
      while ( v40 < v51 );
    }
    v2 = i;
    goto LABEL_91;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1B90
// Name: void ClipChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipChanged(IConVar *pConVar)
{
  ConVarRef clipVar; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &clipVar, pConVar);
  RecomputeClipbrushes(bEnabled: clipVar.m_pConVarState->m_Value.m_nValue != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B1BC0
// Name: void LeafVisDraw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LeafVisDraw(_BYTE *a1@<ebx>, int a2@<esi>)
{
  leafvis_t *v2; // eax
  int v3; // eax
  int v4; // esi
  int leafIndex; // eax
  dleafambientindex_t *m_pLeafAmbient; // ecx
  dleafambientindex_t *v7; // ebx
  int firstAmbientSample; // edx
  IMesh *v9; // esi
  float *v10; // eax
  dleafambientlighting_t *v11; // ecx
  float v12; // xmm2_4
  float v13; // xmm3_4
  int y; // edx
  float v15; // xmm0_4
  unsigned __int8 v16; // al
  float *m_pCurrPosition; // ecx
  float v18; // edi
  float v19; // ebx
  int v20; // edx
  float v21; // esi
  float v22; // xmm0_4
  float *v23; // eax
  int v24; // ecx
  float *v25; // eax
  float *v26; // eax
  int v27; // edx
  unsigned __int8 v28; // al
  float *v29; // ecx
  int v30; // edx
  float v31; // xmm0_4
  float *v32; // eax
  int v33; // ecx
  float *v34; // eax
  float *v35; // eax
  int v36; // edx
  unsigned __int8 v37; // al
  float *v38; // ecx
  int v39; // edx
  float *v40; // eax
  int v41; // ecx
  float *v42; // eax
  float *v43; // eax
  int v44; // edx
  unsigned __int8 v45; // al
  float *v46; // ecx
  int v47; // edx
  float *v48; // eax
  int v49; // ecx
  float *v50; // eax
  float *v51; // eax
  int v52; // edx
  unsigned __int8 v53; // al
  float *v54; // ecx
  int v55; // edx
  float *v56; // eax
  int v57; // ecx
  float *v58; // eax
  float *v59; // eax
  unsigned __int8 v60; // al
  float *v61; // ecx
  int v62; // edx
  float *v63; // eax
  int v64; // ecx
  float *v65; // eax
  float *v66; // eax
  int v67; // edx
  int m_nVertexCount; // eax
  int ambientSampleCount; // edx
  int m_nIndexCount; // [esp-4h] [ebp-394h]
  CMeshBuilder *f; // [esp+0h] [ebp-390h]
  CMeshBuilder v72; // [esp+8h] [ebp-388h] BYREF
  Vector v73; // [esp+1F0h] [ebp-1A0h] BYREF
  Vector v74; // [esp+1FCh] [ebp-194h] BYREF
  Vector v75; // [esp+208h] [ebp-188h] BYREF
  Vector v76; // [esp+214h] [ebp-17Ch] BYREF
  Vector v77; // [esp+220h] [ebp-170h] BYREF
  float v78[2]; // [esp+22Ch] [ebp-164h] BYREF
  Vector v79; // [esp+234h] [ebp-15Ch]
  Vector v80; // [esp+240h] [ebp-150h]
  Vector v81; // [esp+24Ch] [ebp-144h]
  Vector v82; // [esp+258h] [ebp-138h]
  Vector out; // [esp+264h] [ebp-12Ch]
  float v84; // [esp+270h] [ebp-120h]
  float v85; // [esp+274h] [ebp-11Ch]
  float v86; // [esp+278h] [ebp-118h]
  float v87; // [esp+27Ch] [ebp-114h]
  float v88; // [esp+280h] [ebp-110h]
  float v89; // [esp+284h] [ebp-10Ch]
  float v90; // [esp+288h] [ebp-108h]
  float v91; // [esp+28Ch] [ebp-104h]
  float v92; // [esp+290h] [ebp-100h]
  float v93; // [esp+294h] [ebp-FCh]
  float v94; // [esp+298h] [ebp-F8h]
  float v95; // [esp+29Ch] [ebp-F4h]
  float v96; // [esp+2A0h] [ebp-F0h]
  float v97; // [esp+2A4h] [ebp-ECh]
  float v98; // [esp+2A8h] [ebp-E8h]
  float v99; // [esp+2ACh] [ebp-E4h]
  float v100; // [esp+2B0h] [ebp-E0h]
  float v101; // [esp+2B4h] [ebp-DCh]
  float v102; // [esp+2B8h] [ebp-D8h]
  float v103; // [esp+2BCh] [ebp-D4h]
  float v104; // [esp+2C0h] [ebp-D0h]
  float v105; // [esp+2C4h] [ebp-CCh]
  float v106; // [esp+2C8h] [ebp-C8h]
  float v107; // [esp+2CCh] [ebp-C4h]
  float v108; // [esp+2D0h] [ebp-C0h]
  float v109; // [esp+2D4h] [ebp-BCh]
  float v110; // [esp+2D8h] [ebp-B8h]
  float v111; // [esp+2DCh] [ebp-B4h]
  float v112; // [esp+2E0h] [ebp-B0h]
  float v113; // [esp+2E4h] [ebp-ACh]
  float v114; // [esp+2E8h] [ebp-A8h]
  float v115; // [esp+2ECh] [ebp-A4h]
  float v116; // [esp+2F0h] [ebp-A0h]
  float v117; // [esp+2F4h] [ebp-9Ch]
  float v118; // [esp+2F8h] [ebp-98h]
  float v119; // [esp+2FCh] [ebp-94h]
  float v120; // [esp+300h] [ebp-90h]
  float v121; // [esp+304h] [ebp-8Ch]
  float v122; // [esp+308h] [ebp-88h]
  float v123; // [esp+30Ch] [ebp-84h]
  float v124; // [esp+310h] [ebp-80h]
  float v125; // [esp+314h] [ebp-7Ch]
  float v126; // [esp+318h] [ebp-78h]
  float v127; // [esp+31Ch] [ebp-74h]
  float v128; // [esp+320h] [ebp-70h]
  float v129; // [esp+324h] [ebp-6Ch]
  float v130; // [esp+328h] [ebp-68h]
  float v131; // [esp+32Ch] [ebp-64h]
  float v132; // [esp+330h] [ebp-60h]
  float v133; // [esp+334h] [ebp-5Ch]
  float v134; // [esp+338h] [ebp-58h]
  float v135; // [esp+33Ch] [ebp-54h]
  float v136; // [esp+340h] [ebp-50h]
  float v137; // [esp+344h] [ebp-4Ch]
  float v138; // [esp+348h] [ebp-48h]
  float v139; // [esp+34Ch] [ebp-44h]
  float v140; // [esp+350h] [ebp-40h]
  float v141; // [esp+354h] [ebp-3Ch]
  int v142; // [esp+358h] [ebp-38h]
  IMesh *v143; // [esp+35Ch] [ebp-34h]
  float v144; // [esp+360h] [ebp-30h]
  float v145; // [esp+364h] [ebp-2Ch]
  float v146; // [esp+368h] [ebp-28h]
  int v147; // [esp+36Ch] [ebp-24h]
  int v148; // [esp+370h] [ebp-20h]
  dleafambientindex_t *v149; // [esp+374h] [ebp-1Ch]
  const ColorRGBExp32 *v150; // [esp+378h] [ebp-18h]
  int v151; // [esp+37Ch] [ebp-14h]
  float v152; // [esp+380h] [ebp-10h]
  float v153; // [esp+384h] [ebp-Ch]
  int v154; // [esp+388h] [ebp-8h]
  unsigned __int8 v155; // [esp+38Ch] [ebp-4h]
  unsigned __int8 v156; // [esp+38Dh] [ebp-3h]
  unsigned __int8 v157; // [esp+38Fh] [ebp-1h]

  if ( g_FrustumVis != nullptr )
    DrawLeafvis(a1, pVis: g_FrustumVis);
  if ( g_LeafVis != nullptr )
    DrawLeafvis(a1, pVis: g_LeafVis);
  v2 = g_ClipVis[0];
  if ( g_ClipVis[0] != nullptr )
  {
    if ( g_ClipVis[0]->numbrushes != g_BSPData.numbrushes || g_ClipVis[0]->numentitychars != g_BSPData.numentitychars )
    {
      RecomputeClipbrushes(bEnabled: true);
      v2 = g_ClipVis[0];
    }
    if ( r_drawclipbrushes.m_pParent != nullptr && r_drawclipbrushes.m_pParent->m_Value.m_nValue == 2 )
    {
      DrawLeafvis_Solid(p_meshBuilder: nullptr, pVis: v2);
      DrawLeafvis_Solid(p_meshBuilder: nullptr, pVis: pVis);
      DrawLeafvis_Solid(p_meshBuilder: nullptr, pVis: dword_104EF508);
    }
    else
    {
      DrawLeafvis(a1, pVis: v2);
      DrawLeafvis(a1, pVis: pVis);
      DrawLeafvis(a1, pVis: dword_104EF508);
    }
  }
  if ( g_LeafVis != nullptr && r_visambient.m_pParent != nullptr && r_visambient.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int, _BYTE *))materials->GetRenderContext)(a1: materials, a2, a3: a1);
    v4 = v3;
    v147 = v3;
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(a1: v4, a2: g_pMaterialDebugFlat, a3: 0);
    leafIndex = g_LeafVis->leafIndex;
    m_pLeafAmbient = host_state.worldbrush->m_pLeafAmbient;
    v7 = &m_pLeafAmbient[leafIndex];
    v149 = v7;
    if ( v7->ambientSampleCount == 0 )
    {
      firstAmbientSample = v7->firstAmbientSample;
      if ( (_WORD)firstAmbientSample != 0 )
      {
        leafIndex = v7->firstAmbientSample;
        v149 = &m_pLeafAmbient[firstAmbientSample];
        v7 = v149;
      }
    }
    v148 = 0;
    if ( v7->ambientSampleCount != 0 )
    {
      v142 = leafIndex << 6;
      v151 = v157 << 8;
      while ( 1 )
      {
        v9 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD, int, CMeshBuilder *))(*(_DWORD *)v4 + 228))(
                        a1: v4,
                        a2: 1,
                        a3: 0,
                        a4: 0,
                        a5: 0,
                        a6: m_nIndexCount,
                        a7: f);
        v143 = v9;
        CMeshBuilder::CMeshBuilder(this: &v72);
        v72.m_pMesh = v9;
        v72.m_bGenerateIndices = true;
        v72.m_Type = MATERIAL_QUADS;
        v9->SetPrimitiveType(this: v9, a2: MATERIAL_TRIANGLES);
        v72.m_pMesh->LockMesh(this: v72.m_pMesh, a2: 24, a3: 36, a4: &v72, a5: nullptr);
        v72.m_IndexBuilder.m_nIndexOffset = v72.m_nFirstVertex;
        v72.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
        v72.m_IndexBuilder.m_nIndexCount = 0;
        v72.m_IndexBuilder.m_nMaxIndexCount = 36;
        v72.m_IndexBuilder.m_bModify = false;
        v72.m_IndexBuilder.m_pIndices = v72.m_pIndices;
        v72.m_IndexBuilder.m_nIndexSize = v72.m_nIndexSize;
        v72.m_IndexBuilder.m_nCurrentIndex = 0;
        CVertexBuilder::AttachBegin(this: &v72.m_VertexBuilder, pMesh: v9, nMaxVertexCount: 24, desc: &v72);
        v72.m_IndexBuilder.m_nCurrentIndex = 0;
        CVertexBuilder::Reset(this: &v72.m_VertexBuilder);
        v10 = (float *)((char *)&host_state.worldbrush->leafs->contents + v142);
        v11 = &host_state.worldbrush->m_pAmbientSamples[v148 + v7->firstAmbientSample];
        v12 = v10[5] - v10[9];
        v13 = v10[6] - v10[10];
        y = v11->y;
        v144 = (float)((float)((float)v11->x * v10[8]) * 0.0078431377) + (float)(v10[4] - v10[8]);
        v15 = (float)((float)((float)y * v10[9]) * 0.0078431377) + v12;
        v150 = (const ColorRGBExp32 *)v11;
        v145 = v15;
        v146 = (float)((float)((float)v11->z * v10[10]) * 0.0078431377) + v13;
        ColorRGBExp32ToVector(in: v11->cube.m_Color, out: (Vector *)v78);
        v155 = LinearToScreenGamma(f: v78[0]);
        v156 = LinearToScreenGamma(f: v78[1]);
        v16 = LinearToScreenGamma(f: v79.x);
        m_pCurrPosition = v72.m_VertexBuilder.m_pCurrPosition;
        v18 = v145;
        v19 = v146;
        v20 = v156;
        v21 = v144;
        v22 = v144 + 12.0;
        *v72.m_VertexBuilder.m_pCurrPosition = v144 + 12.0;
        v82.z = v18;
        out.x = v19;
        m_pCurrPosition[1] = v18 + 12.0;
        m_pCurrPosition[2] = v19 - 12.0;
        v154 = v16 | ((v20 | ((v151 | v155) << 8)) << 8);
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        v82.y = v21;
        v152 = v22;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v23 = v72.m_VertexBuilder.m_pCurrPosition;
        v24 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v81.z = v18;
        v23[1] = v18 - 12.0;
        v82.x = v19;
        v23[2] = v19 - 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v24;
        v81.y = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v25 = v72.m_VertexBuilder.m_pCurrPosition;
        v131 = v18;
        v132 = v19;
        v130 = v21;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v25[1] = v18 - 12.0;
        v25[2] = v19 + 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v26 = v72.m_VertexBuilder.m_pCurrPosition;
        v27 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v89 = v18;
        v26[1] = v18 + 12.0;
        v90 = v19;
        v26[2] = v19 + 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v27;
        v88 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        ColorRGBExp32ToVector(in: v150 + 1, out: &v73);
        v155 = LinearToScreenGamma(f: v73.x);
        v156 = LinearToScreenGamma(f: v73.y);
        v28 = LinearToScreenGamma(f: v73.z);
        v29 = v72.m_VertexBuilder.m_pCurrPosition;
        v30 = v156;
        v31 = v144 - 12.0;
        *v72.m_VertexBuilder.m_pCurrPosition = v144 - 12.0;
        v153 = v31;
        v125 = v18;
        v126 = v19;
        v29[1] = v18 - 12.0;
        v29[2] = v19 - 12.0;
        v154 = v28 | ((v30 | ((v151 | v155) << 8)) << 8);
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        v124 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v79.z = v18;
        v80.x = v19;
        v79.y = v21;
        v32 = v72.m_VertexBuilder.m_pCurrPosition;
        v33 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v32[1] = v18 + 12.0;
        v32[2] = v19 - 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v33;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v34 = v72.m_VertexBuilder.m_pCurrPosition;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v119 = v18;
        v34[1] = v18 + 12.0;
        v120 = v19;
        v34[2] = v19 + 12.0;
        v118 = v21;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v35 = v72.m_VertexBuilder.m_pCurrPosition;
        v36 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v80.z = v18;
        v35[1] = v18 - 12.0;
        v81.x = v19;
        v35[2] = v19 + 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v36;
        v80.y = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        ColorRGBExp32ToVector(in: v150 + 2, out: &v75);
        v155 = LinearToScreenGamma(f: v75.x);
        v156 = LinearToScreenGamma(f: v75.y);
        v37 = LinearToScreenGamma(f: v75.z);
        v38 = v72.m_VertexBuilder.m_pCurrPosition;
        v39 = v156;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v113 = v18;
        v38[1] = v18 + 12.0;
        v114 = v19;
        v38[2] = v19 + 12.0;
        v112 = v21;
        v154 = v37 | ((v39 | ((v151 | v155) << 8)) << 8);
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v40 = v72.m_VertexBuilder.m_pCurrPosition;
        v41 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v140 = v18;
        v40[1] = v18 + 12.0;
        v141 = v19;
        v40[2] = v19 + 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v41;
        v139 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v42 = v72.m_VertexBuilder.m_pCurrPosition;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v107 = v18;
        v42[1] = v18 + 12.0;
        v108 = v19;
        v42[2] = v19 - 12.0;
        v106 = v21;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v43 = v72.m_VertexBuilder.m_pCurrPosition;
        v44 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v86 = v18;
        v43[1] = v18 + 12.0;
        v87 = v19;
        v43[2] = v19 - 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v44;
        v85 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        ColorRGBExp32ToVector(in: v150 + 3, out: &v77);
        v155 = LinearToScreenGamma(f: v77.x);
        v156 = LinearToScreenGamma(f: v77.y);
        v45 = LinearToScreenGamma(f: v77.z);
        v101 = v18;
        v100 = v21;
        v102 = v19;
        v46 = v72.m_VertexBuilder.m_pCurrPosition;
        v47 = v156;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v46[1] = v18 - 12.0;
        v46[2] = v19 + 12.0;
        v154 = v45 | ((v47 | ((v151 | v155) << 8)) << 8);
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v48 = v72.m_VertexBuilder.m_pCurrPosition;
        v49 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        out.z = v18;
        v48[1] = v18 - 12.0;
        v84 = v19;
        v48[2] = v19 + 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v49;
        out.y = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v50 = v72.m_VertexBuilder.m_pCurrPosition;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v95 = v18;
        v50[1] = v18 - 12.0;
        v96 = v19;
        v50[2] = v19 - 12.0;
        v94 = v21;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v51 = v72.m_VertexBuilder.m_pCurrPosition;
        v52 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v137 = v18;
        v51[1] = v18 - 12.0;
        v138 = v19;
        v51[2] = v19 - 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v52;
        v136 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        ColorRGBExp32ToVector(in: v150 + 4, out: &v76);
        v155 = LinearToScreenGamma(f: v76.x);
        v156 = LinearToScreenGamma(f: v76.y);
        v53 = LinearToScreenGamma(f: v76.z);
        v54 = v72.m_VertexBuilder.m_pCurrPosition;
        v55 = v156;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v134 = v18;
        v54[1] = v18 - 12.0;
        v135 = v19;
        v54[2] = v19 + 12.0;
        v154 = v53 | ((v55 | ((v151 | v155) << 8)) << 8);
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        v133 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v56 = v72.m_VertexBuilder.m_pCurrPosition;
        v57 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v128 = v18;
        v56[1] = v18 - 12.0;
        v129 = v19;
        v56[2] = v19 + 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v57;
        v127 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v58 = v72.m_VertexBuilder.m_pCurrPosition;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v122 = v18;
        v58[1] = v18 + 12.0;
        v123 = v19;
        v58[2] = v19 + 12.0;
        v121 = v21;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v59 = v72.m_VertexBuilder.m_pCurrPosition;
        v116 = v18;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v117 = v19;
        v59[1] = v18 + 12.0;
        v59[2] = v19 + 12.0;
        v115 = v21;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        ColorRGBExp32ToVector(in: v150 + 5, out: &v74);
        v155 = LinearToScreenGamma(f: v74.x);
        v156 = LinearToScreenGamma(f: v74.y);
        v60 = LinearToScreenGamma(f: v74.z);
        v61 = v72.m_VertexBuilder.m_pCurrPosition;
        v62 = v156;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v110 = v18;
        v61[1] = v18 + 12.0;
        v111 = v19;
        v61[2] = v19 - 12.0;
        v154 = v60 | ((v62 | ((v151 | v155) << 8)) << 8);
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        v109 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v63 = v72.m_VertexBuilder.m_pCurrPosition;
        v64 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v104 = v18;
        v63[1] = v18 + 12.0;
        v105 = v19;
        v63[2] = v19 - 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v64;
        v103 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v65 = v72.m_VertexBuilder.m_pCurrPosition;
        *v72.m_VertexBuilder.m_pCurrPosition = v153;
        v98 = v18;
        v65[1] = v18 - 12.0;
        v99 = v19;
        v65[2] = v19 - 12.0;
        v97 = v21;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v154;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        v66 = v72.m_VertexBuilder.m_pCurrPosition;
        v67 = v154;
        *v72.m_VertexBuilder.m_pCurrPosition = v152;
        v92 = v18;
        v66[1] = v18 - 12.0;
        v93 = v19;
        v66[2] = v19 - 12.0;
        *(_DWORD *)v72.m_VertexBuilder.m_pCurrColor = v67;
        v91 = v21;
        CVertexBuilder::AdvanceVertex(this: &v72.m_VertexBuilder);
        if ( v72.m_bGenerateIndices )
        {
          switch ( v72.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * v72.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * v72.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * v72.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * v72.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              m_nVertexCount = v72.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &v72.m_IndexBuilder,
            primitiveType: v72.m_Type,
            nIndexCount: m_nVertexCount);
        }
        f = &v72;
        m_nIndexCount = v72.m_IndexBuilder.m_nIndexCount;
        ((void (__thiscall *)(IMesh *, int))v72.m_pMesh->UnlockMesh)(
          a1: v72.m_pMesh,
          a2: v72.m_VertexBuilder.m_nVertexCount);
        v72.m_IndexBuilder.m_pIndexBuffer = nullptr;
        v72.m_IndexBuilder.m_nMaxIndexCount = 0;
        v72.m_VertexBuilder.m_nMaxVertexCount = 0;
        v72.m_VertexBuilder.m_pVertexBuffer = nullptr;
        v72.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        v72.m_pMesh = nullptr;
        v143->Draw_2(this: v143, a2: -1, a3: 0);
        if ( v72.m_VertexBuilder.m_pVertexBuffer != nullptr
          && v72.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v72.m_VertexBuilder.m_pVertexBuffer) )
        {
          v72.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v72.m_VertexBuilder.m_pVertexBuffer);
        }
        if ( v72.m_IndexBuilder.m_pIndexBuffer != nullptr
          && v72.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v72.m_IndexBuilder.m_pIndexBuffer) )
        {
          v72.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v72.m_IndexBuilder.m_pIndexBuffer);
        }
        ambientSampleCount = v149->ambientSampleCount;
        v4 = v147;
        if ( ++v148 >= ambientSampleCount )
          break;
        v7 = v149;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2B00
// Name: void CSGFrustum(class Frustum_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSGFrustum(Frustum_t *frustum)
{
  int m_Size; // edi
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *v2; // esi
  unsigned __int8 *v3; // eax
  leafvis_t *v4; // esi
  cplane_t *m_pMemory; // ebx
  int v6; // esi
  cplane_t *v7; // eax
  cplane_t tmp; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > planeList; // [esp+20h] [ebp-18h] BYREF
  int i; // [esp+34h] [ebp-4h]

  m_Size = 0;
  v2 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_FrustumVis;
  if ( g_FrustumVis != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_FrustumVis->m_Polygons);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v2);
    free(pMem: v2);
  }
  v3 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x64u);
  v4 = (leafvis_t *)v3;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 5) = 0;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 9) = 0;
    memset(dst: v3 + 40, value: 0, count: 0x30u);
    v4->leafIndex = 0;
    v4->numbrushes = g_BSPData.numbrushes;
    v4->numentitychars = g_BSPData.numentitychars;
  }
  else
  {
    v4 = nullptr;
  }
  m_pMemory = nullptr;
  g_FrustumVis = v4;
  v4->m_Colors[2].x = 1.0;
  v4->m_Colors[2].y = 1.0;
  v4->m_Colors[2].z = 1.0;
  memset(&planeList, 0, sizeof(planeList));
  for ( i = 0; i < 6; ++i )
  {
    tmp.type = 5;
    Frustum_t::GetPlane(this: frustum, i, pNormalOut: &tmp.normal, pDistOut: &tmp.dist);
    v6 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v6 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 20 * (m_Size - v6 - 1));
    v7 = &m_pMemory[v6];
    if ( v7 != nullptr )
      *v7 = tmp;
  }
  CSGPlaneList(
    pVis: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)g_FrustumVis,
    &planeList,
    drawGroup: DG_FRUSTUM);
  if ( planeList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100B2C90
// Name: void LeafvisChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LeafvisChanged()
{
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *v0; // esi
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *v1; // esi

  v0 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_LeafVis;
  if ( g_LeafVis != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_LeafVis->m_Polygons);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v0);
    free(pMem: v0);
    g_LeafVis = nullptr;
  }
  v1 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_FrustumVis;
  if ( g_FrustumVis != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_FrustumVis->m_Polygons);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v1);
    free(pMem: v1);
    g_FrustumVis = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2CF0
// Name: void LeafVisBuild(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall LeafVisBuild(float a1@<ebp>, const Vector *p)
{
  void *v2; // esp
  int v3; // esi
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *v4; // edi
  bool v5; // zf
  int v6; // eax
  leafvis_t *v7; // eax
  leafvis_t *v8; // eax
  leafvis_t *v9; // eax
  leafvis_t *v10; // eax
  int m_nValue; // eax
  int v12; // eax
  worldbrushdata_t *pShared; // eax
  mleaf_t *leafs; // edi
  const CViewSetup *v15; // esi
  const Vector *v16; // eax
  int v17; // esi
  VectorAligned *p_m_vecHalfDiagonal; // eax
  int x_low; // edi
  bool v20; // al
  worldbrushdata_t *v21; // eax
  mleaf_t *v22; // ecx
  int v23; // edi
  int v24; // edx
  int v25; // esi
  __int16 *p_cluster; // ecx
  const QAngle *v27; // [esp-4h] [ebp-2194h]
  float v28; // [esp+0h] [ebp-2190h]
  float v29; // [esp+4h] [ebp-218Ch]
  float v30; // [esp+8h] [ebp-2188h]
  int cluster; // [esp+Ch] [ebp-2184h]
  float m_flAspectRatio; // [esp+Ch] [ebp-2184h]
  int v33; // [esp+10h] [ebp-2180h]
  unsigned __int8 v34[8192]; // [esp+24h] [ebp-216Ch] BYREF
  Frustum_t v35; // [esp+2024h] [ebp-16Ch] BYREF
  int v36; // [esp+216Ch] [ebp-24h]
  VectorAligned *v37; // [esp+2170h] [ebp-20h]
  int v38; // [esp+2174h] [ebp-1Ch]
  int v39; // [esp+2178h] [ebp-18h]
  int numleafs; // [esp+217Ch] [ebp-14h]
  bool v41; // [esp+2183h] [ebp-Dh]
  float flZNear; // [esp+2184h] [ebp-Ch]
  float flZFar; // [esp+2188h] [ebp-8h]
  float flAspectRatio; // [esp+2190h] [ebp+0h]

  flZNear = a1;
  flZFar = flAspectRatio;
  v2 = alloca(8552);
  if ( mat_leafvis.m_pParent == nullptr || mat_leafvis.m_pParent->m_Value.m_nValue == 0 )
    return;
  v3 = CM_PointLeafnum(p);
  if ( mat_leafvis_freeze.m_pParent != nullptr
    && mat_leafvis_freeze.m_pParent->m_Value.m_nValue != 0
    && last_leaf != -1
    && last_leaf < *(_DWORD *)(host_state.worldmodel->sprite.numframes + 16) )
  {
    v3 = last_leaf;
  }
  v4 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_LeafVis;
  if ( g_LeafVis == nullptr )
    goto LABEL_12;
  v5 = last_leaf == v3;
  if ( last_leaf == v3 )
  {
    if ( mat_leafvis_update_every_frame.m_pParent == nullptr
      || mat_leafvis_update_every_frame.m_pParent->m_Value.m_nValue == 0 )
    {
      return;
    }
LABEL_12:
    v5 = last_leaf == v3;
  }
  v41 = !v5;
  if ( !v5 )
  {
    v33 = CM_LeafCluster(leafnum: v3);
    v6 = CM_LeafArea(leafnum: v3);
    _DevMsg(a1: 1, a2: "Leaf %d, Area %d, Cluster %d\n", v3, v6, v33);
    v4 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_LeafVis;
  }
  last_leaf = v3;
  if ( v4 != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v4 + 1);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v4);
    free(pMem: v4);
  }
  v7 = (leafvis_t *)MemAlloc_Alloc(nSize: 0x64u);
  if ( v7 != nullptr )
    v8 = leafvis_t::leafvis_t(this: v7);
  else
    v8 = nullptr;
  g_LeafVis = v8;
  v8->m_Colors[0].x = 0.0;
  v8->m_Colors[0].y = 0.0;
  v8->m_Colors[0].z = 1.0;
  v9 = g_LeafVis;
  g_LeafVis->m_Colors[1].x = 0.0;
  v9->m_Colors[1].y = 0.0;
  v9->m_Colors[1].z = 1.0;
  v10 = g_LeafVis;
  g_LeafVis->m_Colors[3].x = 0.5;
  v10->m_Colors[3].y = 1.0;
  v10->m_Colors[3].z = 0.0;
  g_LeafVis->leafIndex = v3;
  if ( mat_leafvis.m_pParent != nullptr )
    m_nValue = mat_leafvis.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v12 = m_nValue - 2;
  if ( v12 != 0 )
  {
    if ( v12 == 1 )
    {
      pShared = host_state.worldmodel->brush.pShared;
      leafs = pShared->leafs;
      cluster = leafs[v3].cluster;
      numleafs = pShared->numleafs;
      CM_Vis(dest: v34, destlen: 0x2000, cluster, visType: 0);
      v15 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
      Frustum_t::Frustum_t(this: &v35);
      m_flAspectRatio = v15->m_flAspectRatio;
      v30 = g_EngineRenderer->GetFov(this: g_EngineRenderer);
      v29 = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
      v28 = g_EngineRenderer->GetZNear(this: g_EngineRenderer);
      v27 = g_EngineRenderer->ViewAngles(this: g_EngineRenderer);
      v16 = g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
      GeneratePerspectiveFrustum(
        origin: v16,
        angles: v27,
        flZNear: v28,
        flZFar: v29,
        flFovX: v30,
        flAspectRatio: m_flAspectRatio,
        frustum: &v35);
      CSGFrustum(frustum: &v35);
      v17 = 0;
      v39 = 0;
      v38 = 0;
      v36 = 0;
      if ( numleafs > 0 )
      {
        p_m_vecHalfDiagonal = &leafs->m_vecHalfDiagonal;
        v37 = &leafs->m_vecHalfDiagonal;
        do
        {
          x_low = SLOWORD(p_m_vecHalfDiagonal[1].x);
          if ( x_low >= 0
            && p_m_vecHalfDiagonal->x >= 0.03125
            && p_m_vecHalfDiagonal->y >= 0.03125
            && p_m_vecHalfDiagonal->z >= 0.03125 )
          {
            if ( ((unsigned __int8)(1 << (x_low & 7)) & v34[x_low >> 3]) != 0 )
            {
              ++v39;
              v20 = CullNodeSIMD(frustum: &v35, pNode: (mnode_t *)&p_m_vecHalfDiagonal[-2]) == 0;
              if ( v20 )
                ++v38;
              AddLeafPortals(pLeafvis: g_LeafVis, leafIndex: v17, drawGroup: (DrawGroup_t)v20);
            }
            else
            {
              ++v36;
              AddLeafPortals(pLeafvis: g_LeafVis, leafIndex: v17, drawGroup: DG_PVS_INVISIBLE_LEAVES);
            }
            p_m_vecHalfDiagonal = v37;
          }
          ++v17;
          p_m_vecHalfDiagonal += 4;
          v37 = p_m_vecHalfDiagonal;
        }
        while ( v17 < numleafs );
      }
      if ( v41 )
        _DevMsg(a1: 1, a2: "%d Leaves in PVS, %d visible, %d outside of PVS\n", v39, v38, v36);
    }
    else
    {
      AddLeafPortals(pLeafvis: g_LeafVis, leafIndex: v3, drawGroup: DG_BASE);
    }
  }
  else
  {
    v21 = host_state.worldmodel->brush.pShared;
    v22 = v21->leafs;
    v23 = v21->numleafs;
    v24 = v22[v3].cluster;
    v25 = 0;
    v39 = v24;
    if ( v23 > 0 )
    {
      p_cluster = &v22->cluster;
      numleafs = (int)p_cluster;
      do
      {
        if ( *p_cluster == v39 )
          AddLeafPortals(pLeafvis: g_LeafVis, leafIndex: v25, drawGroup: DG_BASE);
        ++v25;
        p_cluster = (__int16 *)(numleafs + 64);
        numleafs += 64;
      }
      while ( v25 < v23 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0710
// Name: sub_100B0710
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_100B0710(
        int leafIndex@<eax>,
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *planeList@<esi>,
        mnode_t *model)
{
  worldbrushdata_t *v4; // eax
  int v5; // eax
  mnode_t *v6; // ebx
  bool v7; // zf
  float *p_x; // eax
  float v9; // xmm3_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  int m_pMemory; // edi
  int v13; // edx
  float v14; // xmm0_4
  cplane_t *v15; // ebx
  cplane_t *v16; // ecx
  int m_nAllocationCount; // eax
  cplane_t *v18; // ecx
  int v19; // eax
  cplane_t *v20; // eax
  float y; // xmm4_4
  float *v22; // eax
  float v23; // [esp+8h] [ebp-20h]
  float v24; // [esp+14h] [ebp-14h]
  int v25; // [esp+18h] [ebp-10h]
  float v26[3]; // [esp+1Ch] [ebp-Ch] BYREF
  mnode_t *pNode; // [esp+30h] [ebp+8h]

  if ( model == nullptr || (v4 = (worldbrushdata_t *)model[4].children[1]) == nullptr || v4->nodes == nullptr )
    Sys_Error(error: "PlaneList: bad model");
  v5 = LODWORD(model[4].children[1]->m_vecCenter.y) + (leafIndex << 6);
  v6 = *(mnode_t **)(v5 + 8);
  pNode = v6;
  if ( v6 != nullptr )
  {
    while ( 1 )
    {
      v7 = v6->children[0] == (mnode_t *)v5;
      p_x = &v6->plane->normal.x;
      v9 = p_x[3];
      if ( v7 )
      {
        v24 = p_x[3];
      }
      else
      {
        v26[0] = -*p_x;
        v26[1] = -p_x[1];
        v9 = -v9;
        v24 = v9;
        v26[2] = -p_x[2];
        p_x = v26;
      }
      v10 = p_x[1];
      v11 = p_x[2];
      m_pMemory = (int)planeList[1].m_pMemory;
      v13 = 0;
      v23 = *p_x;
      v14 = *p_x * v9;
      if ( m_pMemory <= 0 )
      {
LABEL_17:
        m_nAllocationCount = planeList->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: planeList, num: m_pMemory - m_nAllocationCount + 1);
        ++planeList[1].m_pMemory;
        v18 = (cplane_t *)planeList->m_pMemory;
        v19 = (int)planeList[1].m_pMemory - m_pMemory - 1;
        planeList[1].m_nAllocationCount = (int)planeList->m_pMemory;
        if ( v19 > 0 )
          _V_memmove(dest: &v18[m_pMemory + 1], src: &v18[m_pMemory], count: 20 * v19);
        v20 = (cplane_t *)&planeList->m_pMemory[m_pMemory];
        if ( v20 != nullptr )
        {
          v20->normal.x = v23;
          v20->normal.y = v10;
          v20->normal.z = v11;
          v20->dist = v24;
          *(_DWORD *)&v20->type = v25;
        }
      }
      else
      {
        v15 = (cplane_t *)planeList->m_pMemory;
        v16 = (cplane_t *)planeList->m_pMemory;
        while ( *p_x != v16->normal.x || v10 != v16->normal.y || v11 != v16->normal.z )
        {
          ++v13;
          ++v16;
          if ( v13 >= m_pMemory )
          {
            v6 = pNode;
            goto LABEL_17;
          }
        }
        y = v15[v13].normal.y;
        v22 = &v15[v13].normal.x;
        v6 = pNode;
        if ( (float)((float)((float)((float)(y * (float)(v10 * v9)) + (float)(*v22 * v14))
                           + (float)(v22[2] * (float)(v11 * v9)))
                   - v22[3]) > 0.0 )
          v22[3] = v9;
      }
      v5 = (int)v6;
      pNode = v6->parent;
      if ( pNode == nullptr )
        break;
      v6 = v6->parent;
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100AF520
// Name: bool CullNodeSIMD(class Frustum_t const __near &,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CullNodeSIMD(const Frustum_t *frustum, mnode_t *pNode)
{
  __m128 v2; // xmm0
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  __m128 v7; // xmm5
  int v8; // ecx
  __m128 *i; // eax
  __m128 v11; // [esp-Ch] [ebp-2Ch]
  __m128 centerz_4; // [esp+4h] [ebp-1Ch]

  v2 = _mm_and_ps((__m128)pNode->m_vecCenter, *(__m128 *)g_SIMD_clear_wmask);
  v3 = _mm_and_ps((__m128)pNode->m_vecHalfDiagonal, *(__m128 *)g_SIMD_clear_wmask);
  v4 = _mm_shuffle_ps(v2, v2, 0);
  v5 = _mm_shuffle_ps(v2, v2, 85);
  v6 = _mm_shuffle_ps(v3, v3, 0);
  v7 = _mm_shuffle_ps(v3, v3, 85);
  v8 = 0;
  v11 = _mm_shuffle_ps(v2, v2, 170);
  centerz_4 = _mm_shuffle_ps(v3, v3, 170);
  for ( i = &frustum->planes[0].nZ;
        _mm_movemask_ps(
          _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(i[6], v7), _mm_mul_ps(i[-1], v5)),
                _mm_add_ps(_mm_mul_ps(i[7], centerz_4), _mm_mul_ps(v11, *i))),
              _mm_add_ps(_mm_mul_ps(i[5], v6), _mm_mul_ps(i[-2], v4))),
            i[1])) == 0;
        i += 10 )
  {
    if ( ++v8 >= 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AF5F0
// Name: class Vector CSGInsidePoint(struct cplane_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl CSGInsidePoint(Vector *result, cplane_t *pPlanes, int planeCount)
{
  Vector *v3; // eax
  float y; // edx
  float z; // ecx
  int v6; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  unsigned int v9; // edx
  float *p_z; // ecx
  float v11; // xmm3_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm6_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float *p_y; // ecx
  int v26; // edi
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm0_4

  v3 = result;
  y = vec3_origin.y;
  result->x = vec3_origin.x;
  z = vec3_origin.z;
  v6 = 0;
  result->y = y;
  result->z = z;
  if ( planeCount >= 4 )
  {
    v7 = result->y;
    v8 = result->z;
    v9 = ((unsigned int)(planeCount - 4) >> 2) + 1;
    p_z = &pPlanes[1].normal.z;
    v6 = 4 * v9;
    do
    {
      v11 = *(p_z - 6);
      v12 = *(p_z - 5);
      v13 = (float)((float)((float)(v11 * v7) + (float)(*(p_z - 7) * result->x)) + (float)(v12 * v8)) - *(p_z - 4);
      if ( v13 < 0.0 )
      {
        result->x = result->x - (float)(*(p_z - 7) * v13);
        v7 = v7 - (float)(v11 * v13);
        v8 = v8 - (float)(v12 * v13);
      }
      v14 = *(p_z - 1);
      v15 = *p_z;
      v16 = (float)((float)((float)(v14 * v7) + (float)(*(p_z - 2) * result->x)) + (float)(*p_z * v8)) - p_z[1];
      if ( v16 < 0.0 )
      {
        result->x = result->x - (float)(*(p_z - 2) * v16);
        v7 = v7 - (float)(v14 * v16);
        v8 = v8 - (float)(v15 * v16);
      }
      v17 = p_z[4];
      v18 = p_z[5];
      v19 = (float)((float)((float)(v17 * v7) + (float)(p_z[3] * result->x)) + (float)(v18 * v8)) - p_z[6];
      if ( v19 < 0.0 )
      {
        result->x = result->x - (float)(p_z[3] * v19);
        v7 = v7 - (float)(v17 * v19);
        v8 = v8 - (float)(v18 * v19);
      }
      v20 = p_z[9];
      v21 = p_z[10];
      v22 = (float)((float)((float)(v20 * v7) + (float)(p_z[8] * result->x)) + (float)(v21 * v8)) - p_z[11];
      if ( v22 < 0.0 )
      {
        result->x = result->x - (float)(p_z[8] * v22);
        v7 = v7 - (float)(v20 * v22);
        v8 = v8 - (float)(v21 * v22);
      }
      p_z += 20;
      --v9;
    }
    while ( v9 != 0 );
    result->y = v7;
    result->z = v8;
  }
  if ( v6 < planeCount )
  {
    v23 = result->y;
    v24 = result->z;
    p_y = &pPlanes[v6].normal.y;
    v26 = planeCount - v6;
    do
    {
      v27 = *p_y;
      v28 = p_y[1];
      v29 = (float)((float)((float)(*p_y * v23) + (float)(*(p_y - 1) * result->x)) + (float)(v28 * v24)) - p_y[2];
      if ( v29 < 0.0 )
      {
        result->x = result->x - (float)(*(p_y - 1) * v29);
        v23 = v23 - (float)(v27 * v29);
        v24 = v24 - (float)(v28 * v29);
      }
      p_y += 5;
      --v26;
    }
    while ( v26 != 0 );
    result->y = v23;
    result->z = v24;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100AF840
// Name: void TranslatePlaneList(struct cplane_t __near *,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TranslatePlaneList(cplane_t *pPlanes, int planeCount, const Vector *offset)
{
  int v3; // esi
  unsigned int v4; // edx
  float *p_z; // eax
  float *p_dist; // eax
  int v7; // edi

  v3 = 0;
  if ( planeCount >= 4 )
  {
    v4 = ((unsigned int)(planeCount - 4) >> 2) + 1;
    p_z = &pPlanes[1].normal.z;
    v3 = 4 * v4;
    do
    {
      *(p_z - 4) = (float)((float)((float)(*(p_z - 6) * offset->y) + (float)(*(p_z - 7) * offset->x))
                         + (float)(*(p_z - 5) * offset->z))
                 + *(p_z - 4);
      p_z[1] = (float)((float)((float)(*(p_z - 1) * offset->y) + (float)(*(p_z - 2) * offset->x))
                     + (float)(offset->z * *p_z))
             + p_z[1];
      p_z[6] = (float)((float)((float)(p_z[4] * offset->y) + (float)(p_z[3] * offset->x)) + (float)(p_z[5] * offset->z))
             + p_z[6];
      p_z[11] = (float)((float)((float)(p_z[9] * offset->y) + (float)(p_z[8] * offset->x)) + (float)(p_z[10] * offset->z))
              + p_z[11];
      p_z += 20;
      --v4;
    }
    while ( v4 != 0 );
  }
  if ( v3 < planeCount )
  {
    p_dist = &pPlanes[v3].dist;
    v7 = planeCount - v3;
    do
    {
      *p_dist = (float)((float)((float)(*(p_dist - 3) * offset->x) + (float)(*(p_dist - 2) * offset->y))
                      + (float)(offset->z * *(p_dist - 1)))
              + *p_dist;
      p_dist += 5;
      --v7;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF980
// Name: int FindMinBrush(class CCollisionBSPData __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindMinBrush(CCollisionBSPData *pBSPData, int nodenum, int brushIndex)
{
  int v3; // ecx
  int result; // eax
  cnode_t *v5; // esi
  int v6; // ecx

  v3 = nodenum;
  for ( result = brushIndex; v3 >= 0; v3 = v5->children[1] )
  {
    v5 = &pBSPData->map_rootnode[v3];
    result = FindMinBrush(pBSPData, nodenum: v5->children[0], brushIndex: result);
  }
  v6 = pBSPData->map_leafbrushes.m_pArray[pBSPData->map_leafs.m_pArray[-v3 - 1].firstleafbrush];
  if ( v6 < result )
    return v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF9E0
// Name: void DrawLeafvis(struct leafvis_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawLeafvis(CMeshBuilder *p_meshBuilder@<ebx>, leafvis_t *pVis)
{
  IMatRenderContext *m_pObject; // esi
  float *p_y; // ebx
  int v4; // eax
  leafvis_t::Polygon_t *m_pMemory; // ecx
  int m_nVertCount; // ebx
  leafvis_t::Polygon_t *v7; // eax
  IMesh *v8; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v10; // esi
  int v11; // edi
  Vector *v12; // eax
  float *m_pCurrPosition; // ecx
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+18h] [ebp-208h] BYREF
  IMesh *pMesh; // [esp+200h] [ebp-20h]
  int i; // [esp+204h] [ebp-1Ch]
  int nMask; // [esp+208h] [ebp-18h]
  float *v20; // [esp+20Ch] [ebp-14h]
  CMatRenderContextPtr pRenderContext; // [esp+210h] [ebp-10h]
  int v22; // [esp+214h] [ebp-Ch]
  int nPass; // [esp+218h] [ebp-8h]
  int nVertIndex; // [esp+21Ch] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  if ( mat_leafvis_draw_mask.m_pParent != nullptr )
    nMask = mat_leafvis_draw_mask.m_pParent->m_Value.m_nValue;
  else
    nMask = 0;
  p_y = &pVis->m_Colors[0].y;
  nPass = 0;
  v22 = 1;
  v20 = &pVis->m_Colors[0].y;
  do
  {
    nVertIndex = 0;
    if ( (nMask & v22) != 0 )
    {
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))g_materialLeafVisWireframe->ColorModulate)(
        a1: *(p_y - 1),
        a2: *p_y,
        a3: p_y[1]);
      m_pObject->Bind(this: m_pObject, a2: g_materialLeafVisWireframe, a3: nullptr);
      v4 = 0;
      i = 0;
      if ( pVis->m_Polygons.m_Size > 0 )
      {
        do
        {
          m_pMemory = pVis->m_Polygons.m_Memory.m_pMemory;
          m_nVertCount = m_pMemory[v4].m_nVertCount;
          v7 = &m_pMemory[v4];
          if ( m_nVertCount >= 3 && nPass == v7->m_DrawGroup )
          {
            v8 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))m_pObject->GetDynamicMesh)(
                            a1: m_pObject,
                            a2: 1,
                            a3: 0,
                            a4: 0,
                            a5: 0,
                            a6: p_meshBuilder);
            memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
            meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
            meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
            memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
            meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            meshBuilder.m_pMesh = v8;
            meshBuilder.m_bGenerateIndices = true;
            meshBuilder.m_Type = MATERIAL_LINES;
            SetPrimitiveType = v8->SetPrimitiveType;
            pMesh = v8;
            SetPrimitiveType(this: v8, a2: MATERIAL_LINES);
            meshBuilder.m_pMesh->LockMesh(
              this: meshBuilder.m_pMesh,
              a2: 2 * m_nVertCount,
              a3: 2 * m_nVertCount,
              a4: &meshBuilder,
              a5: nullptr);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
            meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2 * m_nVertCount;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = v8;
            meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_bModify = false;
            meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
            meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
            v10 = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 2 * m_nVertCount;
            meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
            meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_bModify = false;
            if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
            {
              meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
              meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
              meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
            }
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
            v11 = nVertIndex;
            do
            {
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = pVis->verts.m_Memory.m_pMemory[v11];
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v12 = &pVis->verts.m_Memory.m_pMemory[nVertIndex + ++v10 % m_nVertCount];
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = v12->x;
              m_pCurrPosition[1] = v12->y;
              m_pCurrPosition[2] = v12->z;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              ++v11;
            }
            while ( v10 < m_nVertCount );
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
            p_meshBuilder = &meshBuilder;
            ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
              a1: meshBuilder.m_pMesh,
              a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
              a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            meshBuilder.m_pMesh = nullptr;
            pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
          }
          nVertIndex += m_nVertCount;
          v4 = i + 1;
          i = v4;
        }
        while ( v4 < pVis->m_Polygons.m_Size );
        p_y = v20;
      }
    }
    p_y += 3;
    ++nPass;
    v20 = p_y;
    v22 = __ROL4__(v22, 1);
  }
  while ( nPass < 4 );
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AFDD0
// Name: void DrawLeafvis_Solid(struct leafvis_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawLeafvis_Solid(CMeshBuilder *p_meshBuilder@<edi>, leafvis_t *pVis)
{
  IMatRenderContext *m_pObject; // esi
  leafvis_t *v3; // ecx
  int v4; // eax
  int m_nVertCount; // edi
  IMesh *v6; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int v8; // edi
  int v9; // edx
  int v10; // esi
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  int v17; // eax
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  int v22; // ecx
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-230h] BYREF
  float v27; // [esp+1F0h] [ebp-48h]
  float v28; // [esp+1F4h] [ebp-44h]
  float v29; // [esp+1F8h] [ebp-40h]
  float v30; // [esp+1FCh] [ebp-3Ch]
  float v31; // [esp+200h] [ebp-38h]
  IMesh *pMesh; // [esp+204h] [ebp-34h]
  float v33; // [esp+208h] [ebp-30h]
  Vector normal; // [esp+20Ch] [ebp-2Ch] BYREF
  Vector lightNormal; // [esp+218h] [ebp-20h] BYREF
  int i; // [esp+224h] [ebp-14h]
  CMatRenderContextPtr pRenderContext; // [esp+228h] [ebp-10h]
  int vert; // [esp+22Ch] [ebp-Ch]
  int vertCount; // [esp+230h] [ebp-8h]
  int triangleCount; // [esp+234h] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  vert = 0;
  lightNormal.x = 1.0;
  lightNormal.y = 1.0;
  lightNormal.z = 1.0;
  VectorNormalize(vec: &lightNormal);
  m_pObject->Bind(this: m_pObject, a2: g_pMaterialDebugFlat, a3: nullptr);
  v3 = pVis;
  v4 = 0;
  for ( i = 0; v4 < pVis->m_Polygons.m_Size; i = v4 )
  {
    m_nVertCount = v3->m_Polygons.m_Memory.m_pMemory[v4].m_nVertCount;
    vertCount = m_nVertCount;
    if ( m_nVertCount >= 3 )
    {
      v6 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))m_pObject->GetDynamicMesh)(
                      a1: m_pObject,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0,
                      a6: p_meshBuilder);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_pMesh = v6;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_TRIANGLES;
      SetPrimitiveType = v6->SetPrimitiveType;
      v8 = 3 * m_nVertCount - 6;
      pMesh = v6;
      triangleCount = v8;
      SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v8, a3: v8, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v8;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v6;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = triangleCount;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      v9 = 3 * vert + 6;
      v10 = vert;
      v11 = *(&pVis->verts.m_Memory.m_pMemory->z + v9) - pVis->verts.m_Memory.m_pMemory[vert].z;
      v12 = *(&pVis->verts.m_Memory.m_pMemory->y + v9) - pVis->verts.m_Memory.m_pMemory[vert].y;
      v13 = pVis->verts.m_Memory.m_pMemory[vert + 1].x - pVis->verts.m_Memory.m_pMemory[vert].x;
      v14 = pVis->verts.m_Memory.m_pMemory[vert + 1].y - pVis->verts.m_Memory.m_pMemory[vert].y;
      v15 = pVis->verts.m_Memory.m_pMemory[vert + 1].z - pVis->verts.m_Memory.m_pMemory[vert].z;
      v16 = *(&pVis->verts.m_Memory.m_pMemory->x + v9) - pVis->verts.m_Memory.m_pMemory[vert].x;
      normal.x = (float)(v12 * v15) - (float)(v11 * v14);
      normal.y = (float)(v11 * v13) - (float)(v15 * v16);
      normal.z = (float)(v14 * v16) - (float)(v12 * v13);
      VectorNormalize(vec: &normal);
      v17 = vertCount;
      v18 = (float)((float)((float)((float)(normal.y * lightNormal.y) + (float)(normal.x * lightNormal.x))
                          + (float)(normal.z * lightNormal.z))
                  * 0.5)
          + 0.5;
      v19 = pVis->m_Colors[0].x * v18;
      v20 = pVis->m_Colors[0].y * v18;
      if ( vertCount > 0 )
      {
        v28 = (float)((float)(pVis->m_Colors[0].z * v18) * 255.0) + 8388608.0;
        v30 = (float)(v20 * 255.0) + 8388608.0;
        v33 = (float)(v19 * 255.0) + 8388608.0;
        for ( triangleCount = vertCount; triangleCount != 0; --triangleCount )
        {
          v21 = v28;
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = pVis->verts.m_Memory.m_pMemory[v10];
          v29 = v21;
          v27 = v30;
          v31 = v33;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v21)
                                                              | ((LOBYTE(v30) | ((LOBYTE(v33) | 0xFFFFFF00) << 8)) << 8);
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v10;
        }
        v17 = vertCount;
      }
      v22 = 0;
      triangleCount = v17 - 2;
      if ( v17 - 2 > 0 )
      {
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                            + v22
                                                                                            + 2;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                            + v22
                                                                                            + 1;
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          ++v22;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( v22 < triangleCount );
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
      p_meshBuilder = &meshBuilder;
      ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
      m_nVertCount = vertCount;
    }
    v3 = pVis;
    vert += m_nVertCount;
    v4 = i + 1;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100B0360
// Name: public: leafvis_t::leafvis_t(void)
// Source: json
//------------------------------------------------------------------------------
leafvis_t *__thiscall leafvis_t::leafvis_t(leafvis_t *this)
{
  this->verts.m_Memory.m_pMemory = nullptr;
  this->verts.m_Memory.m_nAllocationCount = 0;
  this->verts.m_Memory.m_nGrowSize = 0;
  this->verts.m_Size = 0;
  this->verts.m_pElements = nullptr;
  this->m_Polygons.m_Memory.m_pMemory = nullptr;
  this->m_Polygons.m_Memory.m_nAllocationCount = 0;
  this->m_Polygons.m_Memory.m_nGrowSize = 0;
  this->m_Polygons.m_Size = 0;
  this->m_Polygons.m_pElements = nullptr;
  memset(dst: (unsigned __int8 *)this->m_Colors, value: 0, count: sizeof(this->m_Colors));
  this->leafIndex = 0;
  this->numbrushes = g_BSPData.numbrushes;
  this->numentitychars = g_BSPData.numentitychars;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B05A0
// Name: void CSGPlaneList(struct leafvis_t __near *,class CUtlVector<struct cplane_t,class CUtlMemory<struct cplane_t,int>> __near &,enum DrawGroup_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSGPlaneList(
        leafvis_t *pVis,
        CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > *planeList,
        DrawGroup_t drawGroup)
{
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > *v3; // esi
  int m_Size; // ebx
  cplane_t *m_pMemory; // edi
  const Vector *p_normal; // eax
  int v7; // edi
  int v8; // eax
  int v9; // esi
  cplane_t *v10; // eax
  int v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // ecx
  double x; // st7
  unsigned int v17; // eax
  int v18; // ecx
  double v19; // st7
  int v20; // ecx
  int m_nAllocationCount; // eax
  leafvis_t::Polygon_t *v22; // edx
  int v23; // eax
  leafvis_t::Polygon_t *v24; // ecx
  float *p_z; // edx
  int v26; // esi
  int v27; // eax
  Vector *v28; // ecx
  int v29; // eax
  Vector *v30; // eax
  float v31[7]; // [esp+0h] [ebp-C54h]
  float fHalfScale[4]; // [esp+1Ch] [ebp-C38h]
  Vector vertsOut[128]; // [esp+2Ch] [ebp-C28h] BYREF
  Vector vertsIn[128]; // [esp+62Ch] [ebp-628h] BYREF
  Vector insidePoint; // [esp+C2Ch] [ebp-28h] BYREF
  int v36; // [esp+C38h] [ebp-1Ch]
  Vector vert; // [esp+C3Ch] [ebp-18h] BYREF
  unsigned int v38; // [esp+C48h] [ebp-Ch]
  int i; // [esp+C4Ch] [ebp-8h]
  int j; // [esp+C50h] [ebp-4h]

  v3 = planeList;
  m_Size = planeList->m_Size;
  m_pMemory = planeList->m_Memory.m_pMemory;
  v36 = m_Size;
  CSGInsidePoint(result: &insidePoint, pPlanes: m_pMemory, planeCount: m_Size);
  vert.x = -insidePoint.x;
  vert.y = -insidePoint.y;
  vert.z = -insidePoint.z;
  TranslatePlaneList(pPlanes: m_pMemory, planeCount: m_Size, offset: &vert);
  i = 0;
  if ( m_Size > 0 )
  {
    v38 = 0;
    while ( 1 )
    {
      p_normal = &v3->m_Memory.m_pMemory[v38 / 0x14].normal;
      fHalfScale[0] = 9000.0;
      v7 = PolyFromPlane(pOutVerts: vertsIn, normal: p_normal, dist: p_normal[1].x, fHalfScale: 9000.0);
      v8 = 0;
      j = 0;
      v9 = 0;
      do
      {
        if ( i != v8 && v7 >= 3 )
        {
          v10 = planeList->m_Memory.m_pMemory;
          fHalfScale[0] = 0.1;
          v11 = ClipPolyToPlane(
                  inVerts: vertsIn,
                  vertCount: v7,
                  outVerts: vertsOut,
                  normal: &v10[v9].normal,
                  dist: v10[v9].dist,
                  fOnPlaneEpsilon: 0.1);
          v7 = v11;
          v12 = 0;
          if ( v11 >= 4 )
          {
            v13 = (unsigned int)(v11 - 4) >> 2;
            v14 = 0;
            v15 = v13 + 1;
            v12 = 4 * v15;
            do
            {
              x = vertsOut[v14 / 0xC].x;
              v14 += 48;
              --v15;
              vertsOut[v14 / 0xC + 124].x = x;
              vertsOut[v14 / 0xC + 124].y = v31[v14 / 4];
              vertsOut[v14 / 0xC + 124].z = v31[v14 / 4 + 1];
              vertsOut[v14 / 0xC + 125].x = v31[v14 / 4 + 2];
              vertsOut[v14 / 0xC + 125].y = v31[v14 / 4 + 3];
              vertsOut[v14 / 0xC + 125].z = v31[v14 / 4 + 4];
              vertsOut[v14 / 0xC + 126].x = v31[v14 / 4 + 5];
              vertsOut[v14 / 0xC + 126].y = v31[v14 / 4 + 6];
              vertsOut[v14 / 0xC + 126].z = fHalfScale[v14 / 4];
              vertsOut[v14 / 0xC + 127].x = fHalfScale[v14 / 4 + 1];
              vertsOut[v14 / 0xC + 127].y = fHalfScale[v14 / 4 + 2];
              vertsOut[v14 / 0xC + 127].z = fHalfScale[v14 / 4 + 3];
            }
            while ( v15 != 0 );
          }
          if ( v12 < v7 )
          {
            v17 = 12 * v12;
            v18 = v7 - v12;
            do
            {
              v19 = vertsOut[v17 / 0xC].x;
              v17 += 12;
              --v18;
              vertsOut[v17 / 0xC + 127].x = v19;
              vertsOut[v17 / 0xC + 127].y = fHalfScale[v17 / 4 + 2];
              vertsOut[v17 / 0xC + 127].z = fHalfScale[v17 / 4 + 3];
            }
            while ( v18 != 0 );
          }
        }
        v8 = j + 1;
        ++v9;
        j = v8;
      }
      while ( v8 < v36 );
      if ( v7 >= 3 )
      {
        m_nAllocationCount = pVis->m_Polygons.m_Memory.m_nAllocationCount;
        j = pVis->m_Polygons.m_Size;
        v20 = j;
        if ( j + 1 > m_nAllocationCount )
        {
          CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
            this: (CUtlMemory<ResourceEntryInfo,int> *)&pVis->m_Polygons,
            num: j - m_nAllocationCount + 1);
          v20 = j;
        }
        ++pVis->m_Polygons.m_Size;
        v22 = pVis->m_Polygons.m_Memory.m_pMemory;
        v23 = pVis->m_Polygons.m_Size - v20 - 1;
        pVis->m_Polygons.m_pElements = v22;
        if ( v23 > 0 )
        {
          _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 8 * v23);
          v20 = j;
        }
        v24 = &pVis->m_Polygons.m_Memory.m_pMemory[v20];
        if ( v24 != nullptr )
        {
          v24->m_nVertCount = v7;
          v24->m_DrawGroup = drawGroup;
        }
        p_z = &vertsIn[0].z;
        j = (int)&vertsIn[0].z;
        do
        {
          v26 = pVis->verts.m_Size;
          v27 = pVis->verts.m_Memory.m_nAllocationCount;
          vert.x = *(p_z - 2) + insidePoint.x;
          vert.y = *(p_z - 1) + insidePoint.y;
          vert.z = insidePoint.z + *p_z;
          if ( v26 + 1 > v27 )
          {
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
              this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)pVis,
              num: v26 - v27 + 1);
            p_z = (float *)j;
          }
          ++pVis->verts.m_Size;
          v28 = pVis->verts.m_Memory.m_pMemory;
          v29 = pVis->verts.m_Size - v26 - 1;
          pVis->verts.m_pElements = pVis->verts.m_Memory.m_pMemory;
          if ( v29 > 0 )
          {
            _V_memmove(dest: &v28[v26 + 1], src: &v28[v26], count: 12 * v29);
            p_z = (float *)j;
          }
          v30 = &pVis->verts.m_Memory.m_pMemory[v26];
          if ( v30 != nullptr )
            *v30 = vert;
          p_z += 3;
          --v7;
          j = (int)p_z;
        }
        while ( v7 != 0 );
      }
      v38 += 20;
      if ( ++i >= v36 )
        break;
      v3 = planeList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B08F0
// Name: void AddLeafPortals(struct leafvis_t __near *,int,enum DrawGroup_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddLeafPortals(leafvis_t *pLeafvis, int leafIndex, DrawGroup_t drawGroup)
{
  float y; // xmm5_4
  float z; // xmm6_4
  int m_Size; // esi
  int v6; // ecx
  cplane_t *m_pMemory; // edi
  float *p_z; // edx
  int v9; // ebx
  _DWORD *p_x; // eax
  int v11; // edx
  float *v12; // ecx
  int v13; // ebx
  cplane_t *v14; // eax
  int v15; // edx
  float *v16; // ecx
  int v17; // ebx
  float *v18; // eax
  int v19; // edx
  float *v20; // ecx
  int v21; // ebx
  cplane_t *v22; // eax
  int v23; // edx
  float *v24; // ecx
  int v25; // ebx
  _DWORD *v26; // eax
  int v27; // edx
  float *v28; // ecx
  int v29; // ebx
  int v30; // esi
  _DWORD *v31; // edi
  cplane_t *v32; // eax
  cplane_t *v33; // eax
  cplane_t *v34; // eax
  cplane_t *v35; // eax
  cplane_t *v36; // eax
  cplane_t *v37; // eax
  int v38; // [esp+10h] [ebp-38h]
  int v39; // [esp+14h] [ebp-34h]
  float v40; // [esp+14h] [ebp-34h]
  float v41; // [esp+14h] [ebp-34h]
  int v42; // [esp+1Ch] [ebp-2Ch]
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > planeList; // [esp+20h] [ebp-28h] BYREF
  Vector normal; // [esp+34h] [ebp-14h]
  float v45; // [esp+40h] [ebp-8h]
  float v46; // [esp+44h] [ebp-4h]

  memset(&planeList, 0, sizeof(planeList));
  sub_100B03B0(leafIndex, model: host_state.worldmodel, &planeList);
  y = vec3_origin.y;
  z = vec3_origin.z;
  m_Size = planeList.m_Size;
  v6 = 0;
  m_pMemory = planeList.m_Memory.m_pMemory;
  normal.y = vec3_origin.y;
  normal.z = vec3_origin.z;
  LODWORD(v46) = LODWORD(vec3_origin.z) ^ _mask__NegFloat_;
  v38 = LODWORD(vec3_origin.y) ^ _mask__NegFloat_;
  v39 = LODWORD(vec3_origin.z) ^ _mask__NegFloat_;
  if ( planeList.m_Size <= 0 )
  {
LABEL_7:
    v9 = planeList.m_Size;
    if ( planeList.m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: planeList.m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
      z = normal.z;
      y = normal.y;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v9 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 20 * (m_Size - v9 - 1));
      z = normal.z;
      y = normal.y;
    }
    p_x = (_DWORD *)&m_pMemory[v9].normal.x;
    if ( p_x != nullptr )
    {
      *p_x = -1082130432;
      p_x[1] = v38;
      p_x[2] = v39;
      p_x[3] = -964689920;
      p_x[4] = v42;
    }
  }
  else
  {
    p_z = &planeList.m_Memory.m_pMemory->normal.z;
    while ( *(p_z - 2) != -1.0
         || COERCE_FLOAT(LODWORD(vec3_origin.y) ^ _mask__NegFloat_) != *(p_z - 1)
         || COERCE_FLOAT(LODWORD(vec3_origin.z) ^ _mask__NegFloat_) != *p_z )
    {
      ++v6;
      p_z += 5;
      if ( v6 >= planeList.m_Size )
        goto LABEL_7;
    }
    v32 = &planeList.m_Memory.m_pMemory[v6];
    if ( (float)((float)((float)((float)(v32->normal.y
                                       * (float)(COERCE_FLOAT(LODWORD(vec3_origin.y) ^ _mask__NegFloat_) * -16384.0))
                               + (float)(v32->normal.x * 16384.0))
                       + (float)(v32->normal.z
                               * (float)(COERCE_FLOAT(LODWORD(vec3_origin.z) ^ _mask__NegFloat_) * -16384.0)))
               - v32->dist) > 0.0 )
      v32->dist = -16384.0;
  }
  v11 = 0;
  v40 = z;
  v45 = z * -16384.0;
  if ( m_Size <= 0 )
  {
LABEL_19:
    v13 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
      z = normal.z;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v13 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: 20 * (m_Size - v13 - 1));
      z = normal.z;
    }
    v14 = &m_pMemory[v13];
    if ( v14 != nullptr )
    {
      v14->normal.x = 1.0;
      v14->normal.y = y;
      v14->normal.z = v40;
      v14->dist = -16384.0;
      *(_DWORD *)&v14->type = v42;
    }
  }
  else
  {
    v12 = &m_pMemory->normal.z;
    while ( *(v12 - 2) != 1.0 || y != *(v12 - 1) || z != *v12 )
    {
      ++v11;
      v12 += 5;
      if ( v11 >= m_Size )
        goto LABEL_19;
    }
    v33 = &m_pMemory[v11];
    if ( (float)((float)((float)((float)(v33->normal.y * (float)(y * -16384.0)) - (float)(v33->normal.x * 16384.0))
                       + (float)(v33->normal.z * (float)(z * -16384.0)))
               - v33->dist) > 0.0 )
      v33->dist = -16384.0;
  }
  v15 = 0;
  v41 = v46;
  if ( m_Size <= 0 )
  {
LABEL_31:
    v17 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
      z = normal.z;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v17 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 20 * (m_Size - v17 - 1));
      z = normal.z;
    }
    v18 = &m_pMemory[v17].normal.x;
    if ( v18 != nullptr )
    {
      *v18 = -0.0;
      v18[1] = -1.0;
      v18[2] = v41;
      v18[3] = -16384.0;
      *((_DWORD *)v18 + 4) = v42;
    }
  }
  else
  {
    v16 = &m_pMemory->normal.z;
    while ( *(v16 - 2) != -0.0 || *(v16 - 1) != -1.0 || v46 != *v16 )
    {
      ++v15;
      v16 += 5;
      if ( v15 >= m_Size )
        goto LABEL_31;
    }
    v34 = &m_pMemory[v15];
    if ( (float)((float)((float)((float)(v34->normal.y * 16384.0) + (float)(v34->normal.x * 0.0))
                       + (float)(v34->normal.z * (float)(v46 * -16384.0)))
               - v34->dist) > 0.0 )
      v34->dist = -16384.0;
  }
  v19 = 0;
  if ( m_Size <= 0 )
  {
LABEL_43:
    v21 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v21 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v21 + 1], src: &m_pMemory[v21], count: 20 * (m_Size - v21 - 1));
    v22 = &m_pMemory[v21];
    if ( v22 != nullptr )
    {
      v22->normal.x = 0.0;
      v22->normal.y = 1.0;
      v22->normal.z = z;
      v22->dist = -16384.0;
      *(_DWORD *)&v22->type = v42;
    }
  }
  else
  {
    v20 = &m_pMemory->normal.z;
    while ( *(v20 - 2) != 0.0 || *(v20 - 1) != 1.0 || z != *v20 )
    {
      ++v19;
      v20 += 5;
      if ( v19 >= m_Size )
        goto LABEL_43;
    }
    v35 = &m_pMemory[v19];
    if ( (float)((float)((float)((float)(v35->normal.x * -0.0) - (float)(v35->normal.y * 16384.0))
                       + (float)(v35->normal.z * v45))
               - v35->dist) > 0.0 )
      v35->dist = -16384.0;
  }
  v23 = 0;
  if ( m_Size <= 0 )
  {
LABEL_55:
    v25 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v25 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v25 + 1], src: &m_pMemory[v25], count: 20 * (m_Size - v25 - 1));
    v26 = (_DWORD *)&m_pMemory[v25].normal.x;
    if ( v26 != nullptr )
    {
      *v26 = 0x80000000;
      v26[1] = 0x80000000;
      v26[2] = -1082130432;
      v26[3] = -964689920;
      v26[4] = v42;
    }
  }
  else
  {
    v24 = &m_pMemory->normal.z;
    while ( *(v24 - 2) != -0.0 || *(v24 - 1) != -0.0 || *v24 != -1.0 )
    {
      ++v23;
      v24 += 5;
      if ( v23 >= m_Size )
        goto LABEL_55;
    }
    v36 = &m_pMemory[v23];
    if ( (float)((float)((float)((float)(v36->normal.y + v36->normal.x) * 0.0) + (float)(v36->normal.z * 16384.0))
               - v36->dist) > 0.0 )
      v36->dist = -16384.0;
  }
  v27 = 0;
  if ( m_Size <= 0 )
  {
LABEL_67:
    v29 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
    }
    planeList.m_Size = m_Size + 1;
    v30 = m_Size - v29;
    planeList.m_pElements = m_pMemory;
    if ( v30 > 0 )
      _V_memmove(dest: &m_pMemory[v29 + 1], src: &m_pMemory[v29], count: 20 * v30);
    v31 = (_DWORD *)&m_pMemory[v29].normal.x;
    if ( v31 != nullptr )
    {
      *v31 = 0;
      v31[1] = 0;
      v31[2] = 1065353216;
      v31[3] = -964689920;
      v31[4] = v42;
    }
  }
  else
  {
    v28 = &m_pMemory->normal.z;
    while ( *(v28 - 2) != 0.0 || *(v28 - 1) != 0.0 || *v28 != 1.0 )
    {
      ++v27;
      v28 += 5;
      if ( v27 >= m_Size )
        goto LABEL_67;
    }
    v37 = &m_pMemory[v27];
    if ( (float)((float)((float)((float)(v37->normal.y + v37->normal.x) * -0.0) - (float)(v37->normal.z * 16384.0))
               - v37->dist) > 0.0 )
      v37->dist = -16384.0;
  }
  CSGPlaneList(pVis: pLeafvis, &planeList, drawGroup);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&planeList);
}

//------------------------------------------------------------------------------
// Address: 0x100B10D0
// Name: void RecomputeClipbrushes(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecomputeClipbrushes(bool bEnabled)
{
  leafvis_t **v1; // ebx
  int v2; // edi
  leafvis_t *v3; // esi
  leafvis_t::Polygon_t *m_pMemory; // eax
  Vector *v5; // eax
  int v6; // ebx
  unsigned __int8 *v7; // eax
  leafvis_t *v8; // esi
  int v9; // xmm0_4
  double v10; // st7
  int numbrushes; // eax
  int headnode; // ecx
  cnode_t *map_rootnode; // ebx
  cnode_t *v14; // esi
  int v15; // ecx
  cbrush_t *m_pArray; // ecx
  int m_Size; // esi
  __int16 v18; // ax
  cplane_t *v19; // ebx
  cboxbrush_t *v20; // eax
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  int v25; // ecx
  float *p_z; // edx
  int v27; // edi
  cplane_t *v28; // eax
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  int v33; // edx
  float *v34; // ecx
  int v35; // edi
  cplane_t *v36; // eax
  bool v37; // zf
  float *p_x; // eax
  cplane_t *v39; // eax
  int v40; // eax
  int v41; // edx
  cplane_t *plane; // eax
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  int v47; // ecx
  float *v48; // edx
  int v49; // edi
  cplane_t *v50; // eax
  int v51; // ecx
  float *v52; // eax
  float v53; // [esp+Ch] [ebp-70h]
  float v54; // [esp+10h] [ebp-6Ch]
  float v55; // [esp+14h] [ebp-68h]
  int v56; // [esp+1Ch] [ebp-60h]
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > planeList; // [esp+20h] [ebp-5Ch] BYREF
  float v58; // [esp+3Ch] [ebp-40h]
  int contents[3]; // [esp+40h] [ebp-3Ch]
  Vector normal; // [esp+4Ch] [ebp-30h] BYREF
  unsigned __int16 *p_firstbrushside; // [esp+58h] [ebp-24h]
  int v62; // [esp+5Ch] [ebp-20h]
  int lastBrush; // [esp+60h] [ebp-1Ch]
  int p_numsides; // [esp+64h] [ebp-18h]
  float v65; // [esp+68h] [ebp-14h]
  float v66; // [esp+6Ch] [ebp-10h]
  float v67; // [esp+70h] [ebp-Ch]
  int i; // [esp+74h] [ebp-8h]
  int j; // [esp+78h] [ebp-4h]
  int v; // [esp+84h] [ebp+8h]

  v1 = g_ClipVis;
  v2 = 0;
  do
  {
    v3 = *v1;
    if ( *v1 != nullptr )
    {
      v3->m_Polygons.m_Size = 0;
      if ( v3->m_Polygons.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Polygons.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Polygons.m_Memory.m_pMemory);
          v3->m_Polygons.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Polygons.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Polygons.m_Memory.m_pMemory;
      v3->m_Polygons.m_pElements = m_pMemory;
      if ( v3->m_Polygons.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Polygons.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Polygons.m_Memory.m_nAllocationCount = 0;
      }
      v3->verts.m_Size = 0;
      if ( v3->verts.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->verts.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->verts.m_Memory.m_pMemory);
          v3->verts.m_Memory.m_pMemory = nullptr;
        }
        v3->verts.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->verts.m_Memory.m_pMemory;
      v3->verts.m_pElements = v3->verts.m_Memory.m_pMemory;
      if ( v3->verts.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          v3->verts.m_Memory.m_pMemory = nullptr;
        }
        v3->verts.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
    }
    *v1++ = nullptr;
  }
  while ( (int)v1 < (int)&dword_104EF50C );
  if ( bEnabled )
  {
    v6 = 0;
    v = 0;
    contents[0] = 196608;
    contents[1] = 0x20000;
    contents[2] = 0x10000;
    while ( 1 )
    {
      v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x64u);
      v8 = (leafvis_t *)v7;
      if ( v7 != nullptr )
      {
        *(_DWORD *)v7 = 0;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        *((_DWORD *)v7 + 3) = 0;
        *((_DWORD *)v7 + 4) = 0;
        *((_DWORD *)v7 + 5) = 0;
        *((_DWORD *)v7 + 6) = 0;
        *((_DWORD *)v7 + 7) = 0;
        *((_DWORD *)v7 + 8) = 0;
        *((_DWORD *)v7 + 9) = 0;
        memset(dst: v7 + 40, value: 0, count: 0x30u);
        v8->leafIndex = 0;
        v8->numbrushes = g_BSPData.numbrushes;
        v8->numentitychars = g_BSPData.numentitychars;
      }
      else
      {
        v8 = nullptr;
      }
      g_ClipVis[v6] = v8;
      if ( v6 != 0 )
      {
        v9 = 1065353216;
        if ( v6 == 1 )
          v10 = 0.5;
        else
          v10 = 1.0;
      }
      else
      {
        v9 = 0;
        v10 = 1.0;
      }
      v8->m_Colors[0].x = v10;
      v8->m_Colors[0].y = 0.0;
      LODWORD(v8->m_Colors[0].z) = v9;
      numbrushes = g_BSPData.numbrushes;
      lastBrush = g_BSPData.numbrushes;
      if ( g_BSPData.numcmodels > 1 )
      {
        headnode = g_BSPData.map_cmodels.m_pArray[1].headnode;
        if ( headnode >= 0 )
        {
          map_rootnode = g_BSPData.map_rootnode;
          do
          {
            v14 = &map_rootnode[headnode];
            numbrushes = FindMinBrush(pBSPData: &g_BSPData, nodenum: v14->children[0], brushIndex: numbrushes);
            headnode = v14->children[1];
          }
          while ( headnode >= 0 );
        }
        v15 = g_BSPData.map_leafbrushes.m_pArray[g_BSPData.map_leafs.m_pArray[-headnode - 1].firstleafbrush];
        if ( v15 < numbrushes )
          numbrushes = v15;
        lastBrush = numbrushes;
      }
      i = 0;
      if ( numbrushes > 0 )
        break;
LABEL_96:
      if ( ++v >= 3 )
        return;
      v6 = v;
      v2 = 0;
    }
    v62 = contents[v];
    m_pArray = g_BSPData.map_brushes.m_pArray;
    while ( (m_pArray[v2].contents & 0x30000) != v62 )
    {
LABEL_95:
      i = ++v2;
      if ( v2 >= lastBrush )
        goto LABEL_96;
    }
    m_Size = 0;
    p_numsides = (int)&m_pArray[v2].numsides;
    v18 = *(_WORD *)p_numsides;
    v19 = nullptr;
    memset(&planeList, 0, sizeof(planeList));
    if ( v18 == -1 )
    {
      v20 = &g_BSPData.map_boxbrushes.m_pArray[m_pArray[v2].firstbrushside];
      j = (int)v20;
      p_firstbrushside = (unsigned __int16 *)((char *)&normal - (char *)v20);
      p_numsides = 3;
      do
      {
        normal = vec3_origin;
        *(_DWORD *)((char *)p_firstbrushside + (_DWORD)v20) = 1065353216;
        v21 = -v20->maxs.x;
        v22 = -normal.z;
        v23 = -normal.x;
        v24 = -normal.y;
        v55 = -normal.z;
        v25 = 0;
        v53 = -normal.x;
        v54 = -normal.y;
        v67 = -normal.x;
        v66 = -normal.y;
        v65 = -normal.z;
        v58 = (float)-normal.z * v21;
        if ( m_Size <= 0 )
        {
LABEL_50:
          v27 = m_Size;
          if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
              this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
              num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
            m_Size = planeList.m_Size;
            v19 = planeList.m_Memory.m_pMemory;
            v23 = v67;
            v24 = v66;
            v22 = v65;
          }
          planeList.m_Size = ++m_Size;
          planeList.m_pElements = v19;
          if ( m_Size - v27 - 1 > 0 )
          {
            _V_memmove(dest: &v19[v27 + 1], src: &v19[v27], count: 20 * (m_Size - v27 - 1));
            v23 = v67;
            v24 = v66;
            v22 = v65;
          }
          v28 = &v19[v27];
          if ( v28 != nullptr )
          {
            v28->normal.x = v53;
            v28->normal.y = v54;
            v28->normal.z = v55;
            v28->dist = v21;
            *(_DWORD *)&v28->type = v56;
          }
        }
        else
        {
          p_z = &v19->normal.z;
          while ( v23 != *(p_z - 2) || v24 != *(p_z - 1) || v22 != *p_z )
          {
            ++v25;
            p_z += 5;
            if ( v25 >= m_Size )
              goto LABEL_50;
          }
          p_x = &v19[v25].normal.x;
          if ( (float)((float)((float)((float)(p_x[1] * (float)(v24 * v21)) + (float)(*p_x * (float)(v23 * v21)))
                             + (float)(p_x[2] * v58))
                     - p_x[3]) > 0.0 )
            p_x[3] = v21;
        }
        v29 = -v23;
        v30 = -v24;
        v31 = -v22;
        v32 = *(float *)j;
        v33 = 0;
        if ( m_Size <= 0 )
        {
LABEL_62:
          v35 = m_Size;
          if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
              this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
              num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
            m_Size = planeList.m_Size;
            v19 = planeList.m_Memory.m_pMemory;
          }
          planeList.m_Size = ++m_Size;
          planeList.m_pElements = v19;
          if ( m_Size - v35 - 1 > 0 )
            _V_memmove(dest: &v19[v35 + 1], src: &v19[v35], count: 20 * (m_Size - v35 - 1));
          v36 = &v19[v35];
          if ( v36 != nullptr )
          {
            v36->normal.x = v29;
            v36->normal.y = v30;
            v36->normal.z = v31;
            v36->dist = v32;
            *(_DWORD *)&v36->type = v56;
          }
        }
        else
        {
          v34 = &v19->normal.z;
          while ( v29 != *(v34 - 2) || v30 != *(v34 - 1) || v31 != *v34 )
          {
            ++v33;
            v34 += 5;
            if ( v33 >= m_Size )
              goto LABEL_62;
          }
          v39 = &v19[v33];
          if ( (float)((float)((float)((float)(v39->normal.y * (float)(v30 * *(float *)j))
                                     + (float)(v39->normal.x * (float)(v29 * *(float *)j)))
                             + (float)(v39->normal.z * (float)(v31 * *(float *)j)))
                     - v39->dist) > 0.0 )
            v39->dist = v32;
        }
        v20 = (cboxbrush_t *)(j + 4);
        v37 = p_numsides-- == 1;
        j += 4;
      }
      while ( !v37 );
    }
    else
    {
      j = 0;
      if ( v18 == 0 )
      {
LABEL_91:
        CSGPlaneList(pVis: g_ClipVis[v], &planeList, drawGroup: DG_BASE);
        if ( planeList.m_Memory.m_nGrowSize >= 0 && v19 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
        m_pArray = g_BSPData.map_brushes.m_pArray;
        goto LABEL_95;
      }
      p_firstbrushside = &m_pArray[v2].firstbrushside;
      v40 = 0;
      do
      {
        v41 = v40 + *p_firstbrushside;
        if ( g_BSPData.map_brushsides.m_pArray[v41].bBevel == 0 )
        {
          plane = g_BSPData.map_brushsides.m_pArray[v41].plane;
          v43 = -plane->dist;
          v44 = -plane->normal.x;
          v45 = -plane->normal.y;
          v46 = -plane->normal.z;
          v47 = 0;
          if ( m_Size <= 0 )
          {
LABEL_83:
            v49 = m_Size;
            if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
                this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
                num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
              m_Size = planeList.m_Size;
              v19 = planeList.m_Memory.m_pMemory;
            }
            planeList.m_Size = ++m_Size;
            planeList.m_pElements = v19;
            if ( m_Size - v49 - 1 > 0 )
              _V_memmove(dest: &v19[v49 + 1], src: &v19[v49], count: 20 * (m_Size - v49 - 1));
            v50 = &v19[v49];
            if ( v50 != nullptr )
            {
              v50->normal.x = v44;
              v50->normal.y = v45;
              v50->normal.z = v46;
              v50->dist = v43;
              *(_DWORD *)&v50->type = v56;
            }
          }
          else
          {
            v48 = &v19->normal.z;
            while ( v44 != *(v48 - 2) || v45 != *(v48 - 1) || v46 != *v48 )
            {
              ++v47;
              v48 += 5;
              if ( v47 >= m_Size )
                goto LABEL_83;
            }
            v52 = &v19[v47].normal.x;
            if ( (float)((float)((float)((float)(v52[1] * (float)(v45 * v43)) + (float)(*v52 * (float)(v44 * v43)))
                               + (float)(v52[2] * (float)(v46 * v43)))
                       - v52[3]) > 0.0 )
              v52[3] = v43;
          }
        }
        v51 = *(unsigned __int16 *)p_numsides;
        v40 = j + 1;
        j = v40;
      }
      while ( v40 < v51 );
    }
    v2 = i;
    goto LABEL_91;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1830
// Name: void ClipChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipChanged(IConVar *pConVar)
{
  ConVarRef clipVar; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &clipVar, pConVar);
  RecomputeClipbrushes(bEnabled: clipVar.m_pConVarState->m_Value.m_nValue != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B1860
// Name: void LeafVisDraw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LeafVisDraw(CMeshBuilder *a1@<ebx>, int a2@<esi>)
{
  leafvis_t *v2; // eax
  IMatRenderContext *v3; // eax
  IMatRenderContext *m_pObject; // esi
  int leafIndex; // eax
  dleafambientindex_t *m_pLeafAmbient; // ecx
  dleafambientindex_t *v7; // ebx
  int firstAmbientSample; // edx
  IMesh *v9; // esi
  float *v10; // eax
  dleafambientlighting_t *v11; // ecx
  float v12; // xmm2_4
  float v13; // xmm3_4
  int y; // edx
  float v15; // xmm0_4
  unsigned __int8 v16; // al
  float *m_pCurrPosition; // ecx
  float v18; // edi
  float z; // ebx
  int g; // edx
  float x; // esi
  float v22; // xmm0_4
  float *v23; // eax
  int v24; // ecx
  float *v25; // eax
  float *v26; // eax
  int v27; // edx
  unsigned __int8 v28; // al
  float *v29; // ecx
  int v30; // edx
  float v31; // xmm0_4
  float *v32; // eax
  int v33; // ecx
  float *v34; // eax
  float *v35; // eax
  int v36; // edx
  unsigned __int8 v37; // al
  float *v38; // ecx
  int v39; // edx
  float *v40; // eax
  int v41; // ecx
  float *v42; // eax
  float *v43; // eax
  int v44; // edx
  unsigned __int8 v45; // al
  float *v46; // ecx
  int v47; // edx
  float *v48; // eax
  int v49; // ecx
  float *v50; // eax
  float *v51; // eax
  int v52; // edx
  unsigned __int8 v53; // al
  float *v54; // ecx
  int v55; // edx
  float *v56; // eax
  int v57; // ecx
  float *v58; // eax
  float *v59; // eax
  unsigned __int8 v60; // al
  float *v61; // ecx
  int v62; // edx
  float *v63; // eax
  int v64; // ecx
  float *v65; // eax
  float *v66; // eax
  int v67; // edx
  int m_nVertexCount; // eax
  int ambientSampleCount; // edx
  int m_nIndexCount; // [esp+30h] [ebp-394h]
  CMeshBuilder *f; // [esp+34h] [ebp-390h]
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-388h] BYREF
  Vector v73; // [esp+224h] [ebp-1A0h] BYREF
  Vector v74; // [esp+230h] [ebp-194h] BYREF
  Vector v75; // [esp+23Ch] [ebp-188h] BYREF
  Vector v76; // [esp+248h] [ebp-17Ch] BYREF
  Vector v77; // [esp+254h] [ebp-170h] BYREF
  Vector out; // [esp+260h] [ebp-164h] BYREF
  float v79; // [esp+26Ch] [ebp-158h]
  float v80; // [esp+270h] [ebp-154h]
  float v81; // [esp+274h] [ebp-150h]
  float v82; // [esp+278h] [ebp-14Ch]
  float v83; // [esp+27Ch] [ebp-148h]
  float v84; // [esp+280h] [ebp-144h]
  float v85; // [esp+284h] [ebp-140h]
  float v86; // [esp+288h] [ebp-13Ch]
  float v87; // [esp+28Ch] [ebp-138h]
  float v88; // [esp+290h] [ebp-134h]
  float v89; // [esp+294h] [ebp-130h]
  float v90; // [esp+298h] [ebp-12Ch]
  float v91; // [esp+29Ch] [ebp-128h]
  float v92; // [esp+2A0h] [ebp-124h]
  float v93; // [esp+2A4h] [ebp-120h]
  float v94; // [esp+2A8h] [ebp-11Ch]
  float v95; // [esp+2ACh] [ebp-118h]
  float v96; // [esp+2B0h] [ebp-114h]
  float v97; // [esp+2B4h] [ebp-110h]
  float v98; // [esp+2B8h] [ebp-10Ch]
  float v99; // [esp+2BCh] [ebp-108h]
  float v100; // [esp+2C0h] [ebp-104h]
  float v101; // [esp+2C4h] [ebp-100h]
  float v102; // [esp+2C8h] [ebp-FCh]
  float v103; // [esp+2CCh] [ebp-F8h]
  float v104; // [esp+2D0h] [ebp-F4h]
  float v105; // [esp+2D4h] [ebp-F0h]
  float v106; // [esp+2D8h] [ebp-ECh]
  float v107; // [esp+2DCh] [ebp-E8h]
  float v108; // [esp+2E0h] [ebp-E4h]
  float v109; // [esp+2E4h] [ebp-E0h]
  float v110; // [esp+2E8h] [ebp-DCh]
  float v111; // [esp+2ECh] [ebp-D8h]
  float v112; // [esp+2F0h] [ebp-D4h]
  float v113; // [esp+2F4h] [ebp-D0h]
  float v114; // [esp+2F8h] [ebp-CCh]
  float v115; // [esp+2FCh] [ebp-C8h]
  float v116; // [esp+300h] [ebp-C4h]
  float v117; // [esp+304h] [ebp-C0h]
  float v118; // [esp+308h] [ebp-BCh]
  float v119; // [esp+30Ch] [ebp-B8h]
  float v120; // [esp+310h] [ebp-B4h]
  float v121; // [esp+314h] [ebp-B0h]
  float v122; // [esp+318h] [ebp-ACh]
  float v123; // [esp+31Ch] [ebp-A8h]
  float v124; // [esp+320h] [ebp-A4h]
  float v125; // [esp+324h] [ebp-A0h]
  float v126; // [esp+328h] [ebp-9Ch]
  float v127; // [esp+32Ch] [ebp-98h]
  float v128; // [esp+330h] [ebp-94h]
  float v129; // [esp+334h] [ebp-90h]
  float v130; // [esp+338h] [ebp-8Ch]
  float v131; // [esp+33Ch] [ebp-88h]
  float v132; // [esp+340h] [ebp-84h]
  float v133; // [esp+344h] [ebp-80h]
  float v134; // [esp+348h] [ebp-7Ch]
  float v135; // [esp+34Ch] [ebp-78h]
  float v136; // [esp+350h] [ebp-74h]
  float v137; // [esp+354h] [ebp-70h]
  float v138; // [esp+358h] [ebp-6Ch]
  float v139; // [esp+35Ch] [ebp-68h]
  float v140; // [esp+360h] [ebp-64h]
  float v141; // [esp+364h] [ebp-60h]
  float v142; // [esp+368h] [ebp-5Ch]
  float v143; // [esp+36Ch] [ebp-58h]
  float v144; // [esp+370h] [ebp-54h]
  float v145; // [esp+374h] [ebp-50h]
  float v146; // [esp+378h] [ebp-4Ch]
  float v147; // [esp+37Ch] [ebp-48h]
  float v148; // [esp+380h] [ebp-44h]
  float v149; // [esp+384h] [ebp-40h]
  float v150; // [esp+388h] [ebp-3Ch]
  int v151; // [esp+38Ch] [ebp-38h]
  IMesh *pMesh; // [esp+390h] [ebp-34h]
  Vector pos; // [esp+394h] [ebp-30h]
  CMatRenderContextPtr pRenderContext; // [esp+3A0h] [ebp-24h]
  int i; // [esp+3A4h] [ebp-20h]
  dleafambientindex_t *pAmbient; // [esp+3A8h] [ebp-1Ch]
  const dleafambientlighting_t *sample; // [esp+3ACh] [ebp-18h]
  int v158; // [esp+3B0h] [ebp-14h]
  float v159; // [esp+3B4h] [ebp-10h]
  float v160; // [esp+3B8h] [ebp-Ch]
  int v161; // [esp+3BCh] [ebp-8h]
  color32_s color; // [esp+3C0h] [ebp-4h]

  if ( g_FrustumVis != nullptr )
    DrawLeafvis(p_meshBuilder: a1, pVis: g_FrustumVis);
  if ( g_LeafVis != nullptr )
    DrawLeafvis(p_meshBuilder: a1, pVis: g_LeafVis);
  v2 = g_ClipVis[0];
  if ( g_ClipVis[0] != nullptr )
  {
    if ( g_ClipVis[0]->numbrushes != g_BSPData.numbrushes || g_ClipVis[0]->numentitychars != g_BSPData.numentitychars )
    {
      RecomputeClipbrushes(bEnabled: true);
      v2 = g_ClipVis[0];
    }
    if ( r_drawclipbrushes.m_pParent != nullptr && r_drawclipbrushes.m_pParent->m_Value.m_nValue == 2 )
    {
      DrawLeafvis_Solid(p_meshBuilder: nullptr, pVis: v2);
      DrawLeafvis_Solid(p_meshBuilder: nullptr, pVis: pVis);
      DrawLeafvis_Solid(p_meshBuilder: nullptr, pVis: dword_104EF508);
    }
    else
    {
      DrawLeafvis(p_meshBuilder: a1, pVis: v2);
      DrawLeafvis(p_meshBuilder: a1, pVis: pVis);
      DrawLeafvis(p_meshBuilder: a1, pVis: dword_104EF508);
    }
  }
  if ( g_LeafVis != nullptr && r_visambient.m_pParent != nullptr && r_visambient.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, CMeshBuilder *))materials->GetRenderContext)(
                                a1: materials,
                                a2,
                                a3: a1);
    m_pObject = v3;
    pRenderContext.m_pObject = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    m_pObject->Bind(this: m_pObject, a2: g_pMaterialDebugFlat, a3: nullptr);
    leafIndex = g_LeafVis->leafIndex;
    m_pLeafAmbient = host_state.worldbrush->m_pLeafAmbient;
    v7 = &m_pLeafAmbient[leafIndex];
    pAmbient = v7;
    if ( v7->ambientSampleCount == 0 )
    {
      firstAmbientSample = v7->firstAmbientSample;
      if ( (_WORD)firstAmbientSample != 0 )
      {
        leafIndex = v7->firstAmbientSample;
        pAmbient = &m_pLeafAmbient[firstAmbientSample];
        v7 = pAmbient;
      }
    }
    i = 0;
    if ( v7->ambientSampleCount != 0 )
    {
      v151 = leafIndex << 6;
      v158 = color.a << 8;
      while ( 1 )
      {
        v9 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int, CMeshBuilder *))m_pObject->GetDynamicMesh)(
                        a1: m_pObject,
                        a2: 1,
                        a3: 0,
                        a4: 0,
                        a5: 0,
                        a6: m_nIndexCount,
                        a7: f);
        pMesh = v9;
        CMeshBuilder::CMeshBuilder(this: &meshBuilder);
        meshBuilder.m_pMesh = v9;
        meshBuilder.m_bGenerateIndices = true;
        meshBuilder.m_Type = MATERIAL_QUADS;
        v9->SetPrimitiveType(this: v9, a2: MATERIAL_TRIANGLES);
        meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 24, a3: 36, a4: &meshBuilder, a5: nullptr);
        meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
        meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
        meshBuilder.m_IndexBuilder.m_bModify = false;
        meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
        meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        CVertexBuilder::AttachBegin(
          this: &meshBuilder.m_VertexBuilder,
          pMesh: v9,
          nMaxVertexCount: 24,
          desc: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
        v10 = (float *)((char *)&host_state.worldbrush->leafs->contents + v151);
        v11 = &host_state.worldbrush->m_pAmbientSamples[i + v7->firstAmbientSample];
        v12 = v10[5] - v10[9];
        v13 = v10[6] - v10[10];
        y = v11->y;
        pos.x = (float)((float)((float)v11->x * v10[8]) * 0.0078431377) + (float)(v10[4] - v10[8]);
        v15 = (float)((float)((float)y * v10[9]) * 0.0078431377) + v12;
        sample = v11;
        pos.y = v15;
        pos.z = (float)((float)((float)v11->z * v10[10]) * 0.0078431377) + v13;
        ColorRGBExp32ToVector(in: v11->cube.m_Color, &out);
        color.r = LinearToScreenGamma(f: out.x);
        color.g = LinearToScreenGamma(f: out.y);
        v16 = LinearToScreenGamma(f: out.z);
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v18 = pos.y;
        z = pos.z;
        g = color.g;
        x = pos.x;
        v22 = pos.x + 12.0;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = pos.x + 12.0;
        v89 = v18;
        v90 = z;
        m_pCurrPosition[1] = v18 + 12.0;
        m_pCurrPosition[2] = z - 12.0;
        v161 = v16 | ((g | ((v158 | color.r) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        v88 = x;
        v159 = v22;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v24 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v86 = v18;
        v23[1] = v18 - 12.0;
        v87 = z;
        v23[2] = z - 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
        v85 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v25 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v140 = v18;
        v141 = z;
        v139 = x;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v25[1] = v18 - 12.0;
        v25[2] = z + 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v27 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v98 = v18;
        v26[1] = v18 + 12.0;
        v99 = z;
        v26[2] = z + 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v27;
        v97 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ColorRGBExp32ToVector(in: &sample->cube.m_Color[1], out: &v73);
        color.r = LinearToScreenGamma(f: v73.x);
        color.g = LinearToScreenGamma(f: v73.y);
        v28 = LinearToScreenGamma(f: v73.z);
        v29 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v30 = color.g;
        v31 = pos.x - 12.0;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = pos.x - 12.0;
        v160 = v31;
        v134 = v18;
        v135 = z;
        v29[1] = v18 - 12.0;
        v29[2] = z - 12.0;
        v161 = v28 | ((v30 | ((v158 | color.r) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        v133 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v80 = v18;
        v81 = z;
        v79 = x;
        v32 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v33 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v32[1] = v18 + 12.0;
        v32[2] = z - 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v33;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v34 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v128 = v18;
        v34[1] = v18 + 12.0;
        v129 = z;
        v34[2] = z + 12.0;
        v127 = x;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v35 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v36 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v83 = v18;
        v35[1] = v18 - 12.0;
        v84 = z;
        v35[2] = z + 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v36;
        v82 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ColorRGBExp32ToVector(in: &sample->cube.m_Color[2], out: &v75);
        color.r = LinearToScreenGamma(f: v75.x);
        color.g = LinearToScreenGamma(f: v75.y);
        v37 = LinearToScreenGamma(f: v75.z);
        v38 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v39 = color.g;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v122 = v18;
        v38[1] = v18 + 12.0;
        v123 = z;
        v38[2] = z + 12.0;
        v121 = x;
        v161 = v37 | ((v39 | ((v158 | color.r) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v40 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v41 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v149 = v18;
        v40[1] = v18 + 12.0;
        v150 = z;
        v40[2] = z + 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v41;
        v148 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v42 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v116 = v18;
        v42[1] = v18 + 12.0;
        v117 = z;
        v42[2] = z - 12.0;
        v115 = x;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v44 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v95 = v18;
        v43[1] = v18 + 12.0;
        v96 = z;
        v43[2] = z - 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v44;
        v94 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ColorRGBExp32ToVector(in: &sample->cube.m_Color[3], out: &v77);
        color.r = LinearToScreenGamma(f: v77.x);
        color.g = LinearToScreenGamma(f: v77.y);
        v45 = LinearToScreenGamma(f: v77.z);
        v110 = v18;
        v109 = x;
        v111 = z;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v47 = color.g;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v46[1] = v18 - 12.0;
        v46[2] = z + 12.0;
        v161 = v45 | ((v47 | ((v158 | color.r) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v48 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v49 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v92 = v18;
        v48[1] = v18 - 12.0;
        v93 = z;
        v48[2] = z + 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v49;
        v91 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v50 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v104 = v18;
        v50[1] = v18 - 12.0;
        v105 = z;
        v50[2] = z - 12.0;
        v103 = x;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v51 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v52 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v146 = v18;
        v51[1] = v18 - 12.0;
        v147 = z;
        v51[2] = z - 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v52;
        v145 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ColorRGBExp32ToVector(in: &sample->cube.m_Color[4], out: &v76);
        color.r = LinearToScreenGamma(f: v76.x);
        color.g = LinearToScreenGamma(f: v76.y);
        v53 = LinearToScreenGamma(f: v76.z);
        v54 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v55 = color.g;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v143 = v18;
        v54[1] = v18 - 12.0;
        v144 = z;
        v54[2] = z + 12.0;
        v161 = v53 | ((v55 | ((v158 | color.r) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        v142 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v56 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v57 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v137 = v18;
        v56[1] = v18 - 12.0;
        v138 = z;
        v56[2] = z + 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v57;
        v136 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v58 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v131 = v18;
        v58[1] = v18 + 12.0;
        v132 = z;
        v58[2] = z + 12.0;
        v130 = x;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v59 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v125 = v18;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v126 = z;
        v59[1] = v18 + 12.0;
        v59[2] = z + 12.0;
        v124 = x;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ColorRGBExp32ToVector(in: &sample->cube.m_Color[5], out: &v74);
        color.r = LinearToScreenGamma(f: v74.x);
        color.g = LinearToScreenGamma(f: v74.y);
        v60 = LinearToScreenGamma(f: v74.z);
        v61 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v62 = color.g;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v119 = v18;
        v61[1] = v18 + 12.0;
        v120 = z;
        v61[2] = z - 12.0;
        v161 = v60 | ((v62 | ((v158 | color.r) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        v118 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v63 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v64 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v113 = v18;
        v63[1] = v18 + 12.0;
        v114 = z;
        v63[2] = z - 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v64;
        v112 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v65 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v160;
        v107 = v18;
        v65[1] = v18 - 12.0;
        v108 = z;
        v65[2] = z - 12.0;
        v106 = x;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v161;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v66 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v67 = v161;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v159;
        v101 = v18;
        v66[1] = v18 - 12.0;
        v102 = z;
        v66[2] = z - 12.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v67;
        v100 = x;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
        f = &meshBuilder;
        m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
        ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
          a1: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
        ambientSampleCount = pAmbient->ambientSampleCount;
        m_pObject = pRenderContext.m_pObject;
        if ( ++i >= ambientSampleCount )
          break;
        v7 = pAmbient;
      }
    }
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B27A0
// Name: void CSGFrustum(class Frustum_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSGFrustum(Frustum_t *frustum)
{
  int m_Size; // edi
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *v2; // esi
  unsigned __int8 *v3; // eax
  leafvis_t *v4; // esi
  cplane_t *m_pMemory; // ebx
  int v6; // esi
  cplane_t *v7; // eax
  cplane_t tmp; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > planeList; // [esp+20h] [ebp-18h] BYREF
  int i; // [esp+34h] [ebp-4h]

  m_Size = 0;
  v2 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_FrustumVis;
  if ( g_FrustumVis != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_FrustumVis->m_Polygons);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v2);
    free(pMem: v2);
  }
  v3 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x64u);
  v4 = (leafvis_t *)v3;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 5) = 0;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 9) = 0;
    memset(dst: v3 + 40, value: 0, count: 0x30u);
    v4->leafIndex = 0;
    v4->numbrushes = g_BSPData.numbrushes;
    v4->numentitychars = g_BSPData.numentitychars;
  }
  else
  {
    v4 = nullptr;
  }
  m_pMemory = nullptr;
  g_FrustumVis = v4;
  v4->m_Colors[2].x = 1.0;
  v4->m_Colors[2].y = 1.0;
  v4->m_Colors[2].z = 1.0;
  memset(&planeList, 0, sizeof(planeList));
  for ( i = 0; i < 6; ++i )
  {
    tmp.type = 5;
    Frustum_t::GetPlane(this: frustum, i, pNormalOut: &tmp.normal, pDistOut: &tmp.dist);
    v6 = m_Size;
    if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&planeList,
        num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
      m_Size = planeList.m_Size;
      m_pMemory = planeList.m_Memory.m_pMemory;
    }
    planeList.m_Size = ++m_Size;
    planeList.m_pElements = m_pMemory;
    if ( m_Size - v6 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 20 * (m_Size - v6 - 1));
    v7 = &m_pMemory[v6];
    if ( v7 != nullptr )
      *v7 = tmp;
  }
  CSGPlaneList(pVis: g_FrustumVis, &planeList, drawGroup: DG_FRUSTUM);
  if ( planeList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100B2930
// Name: void LeafvisChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LeafvisChanged()
{
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *v0; // esi
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *v1; // esi

  v0 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_LeafVis;
  if ( g_LeafVis != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_LeafVis->m_Polygons);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v0);
    free(pMem: v0);
    g_LeafVis = nullptr;
  }
  v1 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_FrustumVis;
  if ( g_FrustumVis != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_FrustumVis->m_Polygons);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v1);
    free(pMem: v1);
    g_FrustumVis = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2990
// Name: void LeafVisBuild(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall LeafVisBuild(int a1@<ebp>, const Vector *p)
{
  void *v2; // esp
  int v3; // esi
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *v4; // edi
  bool v5; // zf
  int v6; // eax
  leafvis_t *v7; // eax
  leafvis_t *v8; // eax
  leafvis_t *v9; // eax
  leafvis_t *v10; // eax
  int m_nValue; // eax
  int v12; // eax
  worldbrushdata_t *pShared; // eax
  mleaf_t *leafs; // edi
  const CViewSetup *v15; // esi
  const Vector *v16; // eax
  int v17; // esi
  VectorAligned *p_m_vecHalfDiagonal; // eax
  int x_low; // edi
  bool v20; // al
  worldbrushdata_t *v21; // eax
  mleaf_t *v22; // ecx
  int v23; // edi
  int cluster; // edx
  int v25; // esi
  __int16 *p_cluster; // ecx
  const QAngle *v27; // [esp-4h] [ebp-2194h]
  float flZNear; // [esp+0h] [ebp-2190h]
  float flZFar; // [esp+4h] [ebp-218Ch]
  float flFovX; // [esp+8h] [ebp-2188h]
  int flAspectRatio; // [esp+Ch] [ebp-2184h]
  float flAspectRatioa; // [esp+Ch] [ebp-2184h]
  int v33; // [esp+10h] [ebp-2180h]
  unsigned __int8 v34[8192]; // [esp+24h] [ebp-216Ch] BYREF
  Frustum_t v35; // [esp+2024h] [ebp-16Ch] BYREF
  int v36; // [esp+216Ch] [ebp-24h]
  VectorAligned *v37; // [esp+2170h] [ebp-20h]
  int v38; // [esp+2174h] [ebp-1Ch]
  int v39; // [esp+2178h] [ebp-18h]
  int numleafs; // [esp+217Ch] [ebp-14h]
  bool v41; // [esp+2183h] [ebp-Dh]
  int v42; // [esp+2184h] [ebp-Ch]
  void *v43; // [esp+2188h] [ebp-8h]
  void *retaddr; // [esp+2190h] [ebp+0h]

  v42 = a1;
  v43 = retaddr;
  v2 = alloca(8552);
  if ( mat_leafvis.m_pParent == nullptr || mat_leafvis.m_pParent->m_Value.m_nValue == 0 )
    return;
  v3 = CM_PointLeafnum(p);
  if ( mat_leafvis_freeze.m_pParent != nullptr
    && mat_leafvis_freeze.m_pParent->m_Value.m_nValue != 0
    && last_leaf != -1
    && last_leaf < *(_DWORD *)(host_state.worldmodel->sprite.numframes + 16) )
  {
    v3 = last_leaf;
  }
  v4 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_LeafVis;
  if ( g_LeafVis == nullptr )
    goto LABEL_12;
  v5 = last_leaf == v3;
  if ( last_leaf == v3 )
  {
    if ( mat_leafvis_update_every_frame.m_pParent == nullptr
      || mat_leafvis_update_every_frame.m_pParent->m_Value.m_nValue == 0 )
    {
      return;
    }
LABEL_12:
    v5 = last_leaf == v3;
  }
  v41 = !v5;
  if ( !v5 )
  {
    v33 = CM_LeafCluster(leafnum: v3);
    v6 = CM_LeafArea(leafnum: v3);
    _DevMsg(a1: 1, a2: "Leaf %d, Area %d, Cluster %d\n", v3, v6, v33);
    v4 = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)g_LeafVis;
  }
  last_leaf = v3;
  if ( v4 != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v4 + 1);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: v4);
    free(pMem: v4);
  }
  v7 = (leafvis_t *)MemAlloc_Alloc(nSize: 0x64u);
  if ( v7 != nullptr )
    v8 = leafvis_t::leafvis_t(this: v7);
  else
    v8 = nullptr;
  g_LeafVis = v8;
  v8->m_Colors[0].x = 0.0;
  v8->m_Colors[0].y = 0.0;
  v8->m_Colors[0].z = 1.0;
  v9 = g_LeafVis;
  g_LeafVis->m_Colors[1].x = 0.0;
  v9->m_Colors[1].y = 0.0;
  v9->m_Colors[1].z = 1.0;
  v10 = g_LeafVis;
  g_LeafVis->m_Colors[3].x = 0.5;
  v10->m_Colors[3].y = 1.0;
  v10->m_Colors[3].z = 0.0;
  g_LeafVis->leafIndex = v3;
  if ( mat_leafvis.m_pParent != nullptr )
    m_nValue = mat_leafvis.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v12 = m_nValue - 2;
  if ( v12 != 0 )
  {
    if ( v12 == 1 )
    {
      pShared = host_state.worldmodel->brush.pShared;
      leafs = pShared->leafs;
      flAspectRatio = leafs[v3].cluster;
      numleafs = pShared->numleafs;
      CM_Vis(dest: v34, destlen: 0x2000, cluster: flAspectRatio, visType: 0);
      v15 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
      Frustum_t::Frustum_t(this: &v35);
      flAspectRatioa = v15->m_flAspectRatio;
      flFovX = g_EngineRenderer->GetFov(this: g_EngineRenderer);
      flZFar = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
      flZNear = g_EngineRenderer->GetZNear(this: g_EngineRenderer);
      v27 = g_EngineRenderer->ViewAngles(this: g_EngineRenderer);
      v16 = g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
      GeneratePerspectiveFrustum(
        origin: v16,
        angles: v27,
        flZNear,
        flZFar,
        flFovX,
        flAspectRatio: flAspectRatioa,
        frustum: &v35);
      CSGFrustum(frustum: &v35);
      v17 = 0;
      v39 = 0;
      v38 = 0;
      v36 = 0;
      if ( numleafs > 0 )
      {
        p_m_vecHalfDiagonal = &leafs->m_vecHalfDiagonal;
        v37 = &leafs->m_vecHalfDiagonal;
        do
        {
          x_low = SLOWORD(p_m_vecHalfDiagonal[1].x);
          if ( x_low >= 0
            && p_m_vecHalfDiagonal->x >= 0.03125
            && p_m_vecHalfDiagonal->y >= 0.03125
            && p_m_vecHalfDiagonal->z >= 0.03125 )
          {
            if ( ((unsigned __int8)(1 << (x_low & 7)) & v34[x_low >> 3]) != 0 )
            {
              ++v39;
              v20 = CullNodeSIMD(frustum: &v35, pNode: (mnode_t *)&p_m_vecHalfDiagonal[-2]) == 0;
              if ( v20 )
                ++v38;
              AddLeafPortals(pLeafvis: g_LeafVis, leafIndex: v17, drawGroup: (DrawGroup_t)v20);
            }
            else
            {
              ++v36;
              AddLeafPortals(pLeafvis: g_LeafVis, leafIndex: v17, drawGroup: DG_PVS_INVISIBLE_LEAVES);
            }
            p_m_vecHalfDiagonal = v37;
          }
          ++v17;
          p_m_vecHalfDiagonal += 4;
          v37 = p_m_vecHalfDiagonal;
        }
        while ( v17 < numleafs );
      }
      if ( v41 )
        _DevMsg(a1: 1, a2: "%d Leaves in PVS, %d visible, %d outside of PVS\n", v39, v38, v36);
    }
    else
    {
      AddLeafPortals(pLeafvis: g_LeafVis, leafIndex: v3, drawGroup: DG_BASE);
    }
  }
  else
  {
    v21 = host_state.worldmodel->brush.pShared;
    v22 = v21->leafs;
    v23 = v21->numleafs;
    cluster = v22[v3].cluster;
    v25 = 0;
    v39 = cluster;
    if ( v23 > 0 )
    {
      p_cluster = &v22->cluster;
      numleafs = (int)p_cluster;
      do
      {
        if ( *p_cluster == v39 )
          AddLeafPortals(pLeafvis: g_LeafVis, leafIndex: v25, drawGroup: DG_BASE);
        ++v25;
        p_cluster = (__int16 *)(numleafs + 64);
        numleafs += 64;
      }
      while ( v25 < v23 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103190F0
// Name: _dynamic_initializer_for__debug_map_crc__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_map_crc__()
{
  ConVar::ConVar(
    this: &debug_map_crc,
    pName: "debug_map_crc",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Prints CRC for each map lump loaded");
  return atexit(func: dynamic_atexit_destructor_for__debug_map_crc__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D570
// Name: _dynamic_initializer_for__debug_paint_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_paint_alpha__()
{
  ConVar::ConVar(this: &debug_paint_alpha, pName: "debug_paint_alpha", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__debug_paint_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x10324D10
// Name: _dynamic_atexit_destructor_for__debug_map_crc__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_map_crc__()
{
  ConVar::~ConVar(this: &debug_map_crc);
}

//------------------------------------------------------------------------------
// Address: 0x103267F0
// Name: _dynamic_atexit_destructor_for__debug_paint_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_paint_alpha__()
{
  ConVar::~ConVar(this: &debug_paint_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x100B03B0
// Name: sub_100B03B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_100B03B0(
        int leafIndex@<eax>,
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *planeList@<esi>,
        mnode_t *model)
{
  worldbrushdata_t *v4; // eax
  int v5; // eax
  mnode_t *v6; // ebx
  bool v7; // zf
  float *p_x; // eax
  float v9; // xmm3_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  int m_pMemory; // edi
  int v13; // edx
  float v14; // xmm0_4
  cplane_t *v15; // ebx
  cplane_t *v16; // ecx
  int m_nAllocationCount; // eax
  cplane_t *v18; // ecx
  int v19; // eax
  cplane_t *v20; // eax
  float y; // xmm4_4
  float *v22; // eax
  float v23; // [esp+8h] [ebp-20h]
  float v24; // [esp+14h] [ebp-14h]
  int v25; // [esp+18h] [ebp-10h]
  float v26[3]; // [esp+1Ch] [ebp-Ch] BYREF
  mnode_t *pNode; // [esp+30h] [ebp+8h]

  if ( model == nullptr || (v4 = (worldbrushdata_t *)model[4].children[1]) == nullptr || v4->nodes == nullptr )
    Sys_Error(error: "PlaneList: bad model");
  v5 = LODWORD(model[4].children[1]->m_vecCenter.y) + (leafIndex << 6);
  v6 = *(mnode_t **)(v5 + 8);
  pNode = v6;
  if ( v6 != nullptr )
  {
    while ( 1 )
    {
      v7 = v6->children[0] == (mnode_t *)v5;
      p_x = &v6->plane->normal.x;
      v9 = p_x[3];
      if ( v7 )
      {
        v24 = p_x[3];
      }
      else
      {
        v26[0] = -*p_x;
        v26[1] = -p_x[1];
        v9 = -v9;
        v24 = v9;
        v26[2] = -p_x[2];
        p_x = v26;
      }
      v10 = p_x[1];
      v11 = p_x[2];
      m_pMemory = (int)planeList[1].m_pMemory;
      v13 = 0;
      v23 = *p_x;
      v14 = *p_x * v9;
      if ( m_pMemory <= 0 )
      {
LABEL_17:
        m_nAllocationCount = planeList->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: planeList, num: m_pMemory - m_nAllocationCount + 1);
        ++planeList[1].m_pMemory;
        v18 = (cplane_t *)planeList->m_pMemory;
        v19 = (int)planeList[1].m_pMemory - m_pMemory - 1;
        planeList[1].m_nAllocationCount = (int)planeList->m_pMemory;
        if ( v19 > 0 )
          _V_memmove(dest: &v18[m_pMemory + 1], src: &v18[m_pMemory], count: 20 * v19);
        v20 = (cplane_t *)&planeList->m_pMemory[m_pMemory];
        if ( v20 != nullptr )
        {
          v20->normal.x = v23;
          v20->normal.y = v10;
          v20->normal.z = v11;
          v20->dist = v24;
          *(_DWORD *)&v20->type = v25;
        }
      }
      else
      {
        v15 = (cplane_t *)planeList->m_pMemory;
        v16 = (cplane_t *)planeList->m_pMemory;
        while ( *p_x != v16->normal.x || v10 != v16->normal.y || v11 != v16->normal.z )
        {
          ++v13;
          ++v16;
          if ( v13 >= m_pMemory )
          {
            v6 = pNode;
            goto LABEL_17;
          }
        }
        y = v15[v13].normal.y;
        v22 = &v15[v13].normal.x;
        v6 = pNode;
        if ( (float)((float)((float)((float)(y * (float)(v10 * v9)) + (float)(*v22 * v14))
                           + (float)(v22[2] * (float)(v11 * v9)))
                   - v22[3]) > 0.0 )
          v22[3] = v9;
      }
      v5 = (int)v6;
      pNode = v6->parent;
      if ( pNode == nullptr )
        break;
      v6 = v6->parent;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031D5A0
// Name: _dynamic_initializer_for__g_PaintManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PaintManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PaintManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10326800
// Name: _dynamic_atexit_destructor_for__g_PaintManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PaintManager__()
{
  g_PaintManager.__vftable = (CPaintmapDataManager_vtbl *)&CPaintmapDataManager::`vftable';
}

} // namespace engine_xlsp
