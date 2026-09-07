// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: meshutils/uvparam.cpp
// Functions: 3
// ============================================================

#include "meshutils\uvparam.h"

//------------------------------------------------------------------------------
// Address: 0x00572DB0
// Name: public: class Vector4D CMesh::PlaneFromTriangle(int)const
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall CMesh::PlaneFromTriangle(CMesh *this, Vector4D *result, int nTriangle)
{
  unsigned int *m_pIndices; // edx
  unsigned int v4; // esi
  unsigned int *v5; // eax
  int m_nVertexStrideFloats; // edx
  float *m_pVerts; // ecx
  int v8; // esi
  __int64 v9; // xmm0_8
  int v10; // esi
  int v11; // eax
  __int64 v12; // xmm0_8
  float v13; // esi
  float v14; // xmm7_4
  float v15; // xmm1_4
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float C_8; // [esp+Ch] [ebp-1Ch]
  Vector B; // [esp+10h] [ebp-18h] BYREF
  Vector A; // [esp+1Ch] [ebp-Ch]

  m_pIndices = this->m_pIndices;
  v4 = m_pIndices[3 * nTriangle];
  v5 = &m_pIndices[3 * nTriangle];
  m_nVertexStrideFloats = this->m_nVertexStrideFloats;
  m_pVerts = this->m_pVerts;
  v8 = m_nVertexStrideFloats * v4;
  v9 = *(_QWORD *)&m_pVerts[v8];
  A.z = m_pVerts[v8 + 2];
  v10 = m_nVertexStrideFloats * v5[1];
  v11 = m_nVertexStrideFloats * v5[2];
  *(_QWORD *)&A.x = v9;
  *(_QWORD *)&B.x = *(_QWORD *)&m_pVerts[v10];
  v12 = *(_QWORD *)&m_pVerts[v11];
  v13 = m_pVerts[v10 + 2];
  C_8 = m_pVerts[v11 + 2];
  v14 = *(float *)&v12 - A.x;
  *(float *)&v12 = (float)((float)(*(float *)&v12 - A.x) * (float)(B.y - A.y))
                 - (float)((float)(*((float *)&v12 + 1) - A.y) * (float)(B.x - A.x));
  v15 = (float)((float)(C_8 - A.z) * (float)(B.x - A.x)) - (float)(v14 * (float)(v13 - A.z));
  B.x = -(float)((float)((float)(*((float *)&v12 + 1) - A.y) * (float)(v13 - A.z))
               - (float)((float)(C_8 - A.z) * (float)(B.y - A.y)));
  B.y = -v15;
  B.z = -*(float *)&v12;
  VectorNormalize(vec: &B);
  y = B.y;
  x = B.x;
  *(float *)&v12 = A.x;
  z = B.z;
  result->y = B.y;
  *(float *)&v12 = (float)((float)(*(float *)&v12 * x) + (float)(y * A.y)) + (float)(A.z * z);
  result->x = x;
  result->z = z;
  LODWORD(result->w) = v12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005730A0
// Name: int AddTriangleToChart(class CMesh const __near &,int,struct UVChart_t __near *,float,class CUtlVector<bool,class CUtlMemory<bool,int>> __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddTriangleToChart(
        CMesh *inputMesh,
        int nTriangle,
        UVChart_t *pChart,
        float flThreshold,
        CUtlVector<bool,CUtlMemory<bool,int> > *usedTriangles,
        int *pAdjacency)
{
  UVChart_t *v7; // edx
  int m_nAllocationCount; // eax
  CUtlVector<int,CUtlMemory<int,int> > *p_m_TriangleList; // esi
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // edi
  int *v15; // esi
  int v16; // eax
  Vector4D vTriPlane; // [esp+18h] [ebp-10h] BYREF
  int nTrianglea; // [esp+34h] [ebp+Ch]
  int nAdded; // [esp+40h] [ebp+18h]

  if ( usedTriangles->m_Memory.m_pMemory[nTriangle] )
    return 0;
  CMesh::PlaneFromTriangle(this: inputMesh, result: &vTriPlane, nTriangle);
  v7 = pChart;
  if ( flThreshold > (float)((float)((float)(pChart->m_vPlane.y * vTriPlane.y)
                                   + (float)(pChart->m_vPlane.x * vTriPlane.x))
                           + (float)(pChart->m_vPlane.z * vTriPlane.z)) )
    return 0;
  m_nAllocationCount = pChart->m_TriangleList.m_Memory.m_nAllocationCount;
  p_m_TriangleList = &pChart->m_TriangleList;
  m_Size = pChart->m_TriangleList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<HemiLightData_t *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)p_m_TriangleList,
      num: m_Size - m_nAllocationCount + 1);
    v7 = pChart;
  }
  ++pChart->m_TriangleList.m_Size;
  m_pMemory = p_m_TriangleList->m_Memory.m_pMemory;
  v12 = pChart->m_TriangleList.m_Size - m_Size - 1;
  pChart->m_TriangleList.m_pElements = pChart->m_TriangleList.m_Memory.m_pMemory;
  if ( v12 > 0 )
  {
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v7 = pChart;
  }
  v13 = &p_m_TriangleList->m_Memory.m_pMemory[m_Size];
  if ( v13 != nullptr )
    *v13 = nTriangle;
  usedTriangles->m_Memory.m_pMemory[nTriangle] = true;
  nAdded = 1;
  v15 = &pAdjacency[3 * nTriangle];
  for ( nTrianglea = 3; nTrianglea != 0; --nTrianglea )
  {
    if ( *v15 != -1 )
    {
      v16 = AddTriangleToChart(inputMesh, nTriangle: *v15, pChart: v7, flThreshold, usedTriangles, pAdjacency);
      v7 = pChart;
      nAdded += v16;
    }
    ++v15;
  }
  return nAdded;
}

//------------------------------------------------------------------------------
// Address: 0x005731B0
// Name: bool CreateUniqueUVParameterization(class CMesh __near *,class CMesh const __near &,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __cdecl CreateUniqueUVParameterization(
        CMesh *pMeshOut,
        CMesh *inputMesh,
        float flThreshold,
        int nAtlasTextureSizeX,
        int nAtlasTextureSizeY,
        float flGutterSize)
{
  int *v6; // eax
  char result; // al
  int FirstAttributeOffset; // ebx
  int v9; // edi
  int v10; // ebx
  int i; // eax
  int v12; // edi
  UVChart_t *v13; // eax
  UVChart_t *v14; // esi
  int *v15; // eax
  int m_Size; // edi
  int v17; // edi
  UVChart_t **v18; // eax
  int v19; // edi
  float *p_y; // esi
  UVChart_t *v21; // ebx
  int v22; // edi
  Vector4D *v23; // eax
  float v24; // xmm1_4
  int v25; // eax
  unsigned int v26; // ebx
  UVChart_t *v27; // esi
  float z; // edx
  float v29; // xmm0_4
  float v30; // xmm2_4
  int v31; // eax
  int v32; // ecx
  const float *v33; // eax
  float x; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float y; // xmm2_4
  float v38; // xmm0_4
  float *v39; // edi
  float *v40; // eax
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm1_4
  int v47; // ecx
  int v48; // edx
  float v49; // xmm4_4
  float v50; // xmm5_4
  int v51; // eax
  float v52; // xmm0_4
  float v53; // xmm1_4
  float *v54; // eax
  int m_nVertexStart; // eax
  int v56; // edx
  float *v57; // ecx
  int v58; // ebx
  float v59; // xmm0_4
  int v60; // ecx
  int v61; // edi
  float v62; // xmm4_4
  float v63; // xmm6_4
  float *v64; // esi
  UVChart_t *v65; // edx
  int v66; // ecx
  float v67; // xmm1_4
  float v68; // xmm0_4
  float v69; // xmm3_4
  float v70; // xmm4_4
  float v71; // xmm0_4
  float v72; // xmm1_4
  int v73; // eax
  float v74; // xmm2_4
  float *v75; // eax
  float *v76; // eax
  const float *m_nVertexStrideFloats; // ecx
  float *v78; // esi
  int j; // eax
  int v80; // ecx
  float v81; // xmm1_4
  float v82; // xmm0_4
  int v83; // edx
  int v84; // edi
  float *v85; // eax
  int k; // ebx
  UVChart_t *v87; // esi
  int *m_pMemory; // eax
  int m_nGrowSize; // esi
  bool *v90; // eax
  int m_nIndexCount; // [esp+10h] [ebp-E8h]
  CMesh tempMesh; // [esp+18h] [ebp-E0h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > triangleIndices; // [esp+48h] [ebp-B0h] BYREF
  int v94; // [esp+5Ch] [ebp-9Ch]
  CUtlVector<AtlasChart_t,CUtlMemory<AtlasChart_t,int> > atlasChartVector; // [esp+60h] [ebp-98h] BYREF
  int nPosOffset; // [esp+74h] [ebp-84h]
  Vector2D vGutterOffset; // [esp+78h] [ebp-80h]
  CUtlVector<bool,CUtlMemory<bool,int> > usedTriangles; // [esp+80h] [ebp-78h] BYREF
  int v99; // [esp+94h] [ebp-64h]
  Vector4D v100; // [esp+98h] [ebp-60h] BYREF
  Vector vBoundsDelta; // [esp+A8h] [ebp-50h] BYREF
  float v102; // [esp+B4h] [ebp-44h]
  CUtlVector<UVChart_t *,CUtlMemory<UVChart_t *,int> > chartList; // [esp+B8h] [ebp-40h] BYREF
  __int128 vMinBounds; // [esp+CCh] [ebp-2Ch] OVERLAPPED BYREF
  int nTexOffset; // [esp+DCh] [ebp-1Ch]
  int *pAdjacencyBuffer; // [esp+E0h] [ebp-18h]
  int nAdded; // [esp+E4h] [ebp-14h]
  int nTris; // [esp+E8h] [ebp-10h]
  bool bMadeAtlas; // [esp+EFh] [ebp-9h]
  int c; // [esp+F0h] [ebp-8h]
  int t; // [esp+F4h] [ebp-4h]

  v6 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)inputMesh->m_nIndexCount >> 30 != 0 ? -1 : 4 * inputMesh->m_nIndexCount);
  m_nIndexCount = inputMesh->m_nIndexCount;
  pAdjacencyBuffer = v6;
  result = CMesh::CalculateAdjacency(this: inputMesh, pAdjacencyOut: v6, nSizeAdjacencyOut: m_nIndexCount);
  if ( result != 0 )
  {
    FirstAttributeOffset = CMesh::FindFirstAttributeOffset(this: inputMesh, nType: VERTEX_ELEMENT_POSITION);
    nPosOffset = FirstAttributeOffset;
    nTexOffset = CMesh::FindFirstAttributeOffset(this: inputMesh, nType: VERTEX_ELEMENT_TEXCOORD2D_0);
    if ( nTexOffset == -1
      && (nTexOffset = CMesh::FindFirstAttributeOffset(this: inputMesh, nType: VERTEX_ELEMENT_TEXCOORD3D_0)) == -1
      || FirstAttributeOffset == -1 )
    {
      _Warning(a1: "Cannot create UV parameterization without position or texcoords!\n");
      return 0;
    }
    else
    {
      v9 = inputMesh->m_nIndexCount;
      v10 = v9 / 3;
      memset(&triangleIndices, 0, sizeof(triangleIndices));
      memset(&usedTriangles, 0, sizeof(usedTriangles));
      memset(&chartList, 0, sizeof(chartList));
      if ( v9 / 3 > 0 )
        CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
          this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&triangleIndices,
          elem: 0,
          num: v9 / 3);
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(this: &usedTriangles, num: v9 / 3);
      for ( i = 0; i < v10; ++i )
      {
        triangleIndices.m_Memory.m_pMemory[i] = i;
        usedTriangles.m_Memory.m_pMemory[i] = false;
      }
      nTris = (int)usedTriangles.m_Memory.m_pMemory;
      t = v9 / 3;
      if ( v10 > 0 )
      {
        do
        {
          v12 = 0;
          while ( *(_BYTE *)(v12 + nTris) != 0 )
          {
            if ( ++v12 >= v10 )
              goto LABEL_30;
          }
          if ( v12 <= -1 )
            break;
          CMesh::PlaneFromTriangle(this: inputMesh, result: (Vector4D *)&vMinBounds, nTriangle: v12);
          *(float *)&nAdded = *((float *)&vMinBounds + 1) * *((float *)&vMinBounds + 1);
          if ( (float)((float)((float)(*((float *)&vMinBounds + 1) * *((float *)&vMinBounds + 1))
                             + (float)(*(float *)&vMinBounds * *(float *)&vMinBounds))
                     + (float)(*((float *)&vMinBounds + 2) * *((float *)&vMinBounds + 2))) >= 0.89999998 )
          {
            v13 = (UVChart_t *)MemAlloc_Alloc(nSize: 0x3Cu);
            if ( v13 != nullptr )
            {
              v13->m_TriangleList.m_Memory.m_pMemory = nullptr;
              v13->m_TriangleList.m_Memory.m_nAllocationCount = 0;
              v13->m_TriangleList.m_Memory.m_nGrowSize = 0;
              v13->m_TriangleList.m_Size = 0;
              v13->m_TriangleList.m_pElements = nullptr;
              v14 = v13;
            }
            else
            {
              v14 = nullptr;
            }
            v15 = pAdjacencyBuffer;
            *(Vector *)&v14->m_vPlane.x = (Vector)vMinBounds;
            v14->m_vPlane.w = *((float *)&vMinBounds + 3);
            v14->m_vMinUV.x = 3.4028235e38;
            v14->m_vMinUV.y = 3.4028235e38;
            v14->m_vMaxUV.x = -3.4028235e38;
            v14->m_vMaxUV.y = -3.4028235e38;
            *(float *)&nAdded = COERCE_FLOAT(
                                  AddTriangleToChart(
                                    inputMesh,
                                    nTriangle: v12,
                                    pChart: v14,
                                    flThreshold,
                                    &usedTriangles,
                                    pAdjacency: v15));
            if ( nAdded < 1 )
              _Msg(a1: "Error: didn't add any triangles to chart: %d\n", v12);
            m_Size = chartList.m_Size;
            t -= nAdded;
            c = chartList.m_Size;
            if ( chartList.m_Size + 1 > chartList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<HemiLightData_t *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&chartList,
                num: chartList.m_Size - chartList.m_Memory.m_nAllocationCount + 1);
              m_Size = chartList.m_Size;
            }
            v17 = m_Size + 1;
            chartList.m_Size = v17;
            chartList.m_pElements = chartList.m_Memory.m_pMemory;
            if ( v17 - c - 1 > 0 )
              _V_memmove(
                dest: &chartList.m_Memory.m_pMemory[c + 1],
                src: &chartList.m_Memory.m_pMemory[c],
                count: 4 * (v17 - c - 1));
            v18 = &chartList.m_Memory.m_pMemory[c];
            if ( v18 != nullptr )
              *v18 = v14;
            if ( v17 > 10000 )
              break;
          }
          else
          {
            --t;
            *(_BYTE *)(v12 + nTris) = 1;
          }
        }
        while ( t > 0 );
      }
LABEL_30:
      free(pMem: pAdjacencyBuffer);
      memset(&atlasChartVector, 0, sizeof(atlasChartVector));
      CMesh::CMesh(this: &tempMesh);
      v19 = chartList.m_Size;
      t = 0;
      if ( chartList.m_Size >= 10000 )
      {
        bMadeAtlas = false;
        _Msg(a1: "Too many charts (%d), creating planar mapping\n", chartList.m_Size);
        CMesh::CalculateBounds(
          this: inputMesh,
          pMinOut: (Vector *)((char *)&vMinBounds + 4),
          pMaxOut: (Vector *)&v100.y,
          nStartVertex: 0,
          nVertexCount: 0);
        vBoundsDelta.y = v100.y - *((float *)&vMinBounds + 1);
        v102 = v100.w - *((float *)&vMinBounds + 3);
        DuplicateMesh(pMeshOut, inputMesh);
        v80 = 0;
        if ( pMeshOut->m_nVertexCount > 0 )
        {
          v81 = 1.0 / vBoundsDelta.y;
          v82 = 1.0 / v102;
          v83 = nPosOffset;
          v84 = nTexOffset;
          do
          {
            v85 = &pMeshOut->m_pVerts[v80 * pMeshOut->m_nVertexStrideFloats];
            v85[v84] = (float)(v85[v83] - *((float *)&vMinBounds + 1)) * v81;
            ++v80;
            v85[v84 + 1] = (float)(v85[v83 + 2] - *((float *)&vMinBounds + 3)) * v82;
          }
          while ( v80 < pMeshOut->m_nVertexCount );
        }
      }
      else
      {
        if ( chartList.m_Size > 0 )
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::InsertMultipleBefore(
            this: &atlasChartVector,
            elem: 0,
            num: chartList.m_Size);
        c = 0;
        if ( v19 > 0 )
        {
          p_y = &atlasChartVector.m_Memory.m_pMemory->m_vAtlasMax.y;
          do
          {
            v21 = chartList.m_Memory.m_pMemory[c];
            v22 = 0;
            nTris = v21->m_TriangleList.m_Size;
            memset(&vBoundsDelta, 0, sizeof(vBoundsDelta));
            if ( nTris > 0 )
            {
              do
              {
                v23 = CMesh::PlaneFromTriangle(
                        this: inputMesh,
                        result: &v100,
                        nTriangle: v21->m_TriangleList.m_Memory.m_pMemory[v22]);
                vBoundsDelta.x = vBoundsDelta.x + v23->x;
                vBoundsDelta.y = v23->y + vBoundsDelta.y;
                ++v22;
                vBoundsDelta.z = v23->z + vBoundsDelta.z;
              }
              while ( v22 < nTris );
            }
            t += nTris;
            *(Vector *)((char *)&vMinBounds + 4) = vBoundsDelta;
            VectorNormalize(vec: (Vector *)((char *)&vMinBounds + 4));
            v24 = *((float *)&vMinBounds + 3);
            v25 = c;
            *(_QWORD *)&v21->m_vPlane.x = *(_QWORD *)((char *)&vMinBounds + 4);
            v21->m_vPlane.z = v24;
            v21->m_vPlane.w = 0.0;
            *(p_y - 5) = 0.0;
            *(p_y - 4) = 0.0;
            *(p_y - 3) = 0.0;
            *(p_y - 2) = 0.0;
            *(p_y - 1) = 0.0;
            *p_y = 0.0;
            *((_BYTE *)p_y + 4) = 0;
            p_y += 7;
            c = v25 + 1;
          }
          while ( v25 + 1 < chartList.m_Size );
        }
        CMesh::AllocateMesh(
          this: &tempMesh,
          nVertexCount: 3 * t,
          nIndexCount: 3 * t,
          nVertexStride: inputMesh->m_nVertexStrideFloats,
          pAttributes: inputMesh->m_pAttributes,
          nAtrributeCount: inputMesh->m_nAttributeCount);
        v26 = 0;
        *(float *)&nTris = 0.0;
        v99 = 0;
        if ( chartList.m_Size > 0 )
        {
          pAdjacencyBuffer = (int *)atlasChartVector.m_Memory.m_pMemory;
          do
          {
            v27 = chartList.m_Memory.m_pMemory[v99];
            z = v27->m_vPlane.z;
            *(_QWORD *)((char *)&vMinBounds + 4) = *(_QWORD *)&v27->m_vPlane.x;
            v29 = 1.0;
            *((float *)&vMinBounds + 3) = z;
            v30 = 0.0;
            v100.y = 0.0;
            v100.z = 1.0;
            v100.w = 0.0;
            if ( (float)((float)((float)(*((float *)&vMinBounds + 1) * 0.0) + *((float *)&vMinBounds + 2))
                       + (float)(z * 0.0)) > 0.94999999 )
            {
              v30 = 1.0;
              v29 = 0.0;
              v100.y = 0.0;
              v100.z = 0.0;
              v100.w = 1.0;
            }
            vBoundsDelta.y = (float)(*((float *)&vMinBounds + 2) * v30) - (float)(z * v29);
            vBoundsDelta.z = (float)(z * 0.0) - (float)(v30 * *((float *)&vMinBounds + 1));
            v102 = (float)(v29 * *((float *)&vMinBounds + 1)) - (float)(*((float *)&vMinBounds + 2) * 0.0);
            VectorNormalize(vec: (Vector *)&vBoundsDelta.y);
            v100.y = (float)(vBoundsDelta.z * *((float *)&vMinBounds + 3)) - (float)(v102 * *((float *)&vMinBounds + 2));
            v100.z = (float)(v102 * *((float *)&vMinBounds + 1)) - (float)(*((float *)&vMinBounds + 3) * vBoundsDelta.y);
            v100.w = (float)(*((float *)&vMinBounds + 2) * vBoundsDelta.y)
                   - (float)(vBoundsDelta.z * *((float *)&vMinBounds + 1));
            VectorNormalize(vec: (Vector *)&v100.y);
            v31 = v27->m_TriangleList.m_Size;
            v27->m_nVertexStart = v26;
            v94 = v31;
            for ( t = 0; t < v94; ++t )
            {
              v32 = 12 * v27->m_TriangleList.m_Memory.m_pMemory[t];
              c = v32;
              nAdded = 3;
              while ( 1 )
              {
                v33 = &inputMesh->m_pVerts[inputMesh->m_nVertexStrideFloats
                                         * *(unsigned int *)((char *)inputMesh->m_pIndices + v32)];
                x = v27->m_vMinUV.x;
                v35 = (float)((float)(v33[nPosOffset] * vBoundsDelta.y) + (float)(v33[nPosOffset + 1] * vBoundsDelta.z))
                    + (float)(v33[nPosOffset + 2] * v102);
                v36 = (float)((float)(v33[nPosOffset] * v100.y) + (float)(v33[nPosOffset + 1] * v100.z))
                    + (float)(v33[nPosOffset + 2] * v100.w);
                vGutterOffset.x = v35;
                vGutterOffset.y = v36;
                if ( x > v35 )
                  x = v35;
                v27->m_vMinUV.x = x;
                y = v27->m_vMinUV.y;
                if ( y > v36 )
                  y = v36;
                v27->m_vMinUV.y = y;
                if ( v35 <= v27->m_vMaxUV.x )
                  v35 = v27->m_vMaxUV.x;
                v27->m_vMaxUV.x = v35;
                v38 = v27->m_vMaxUV.y;
                if ( v36 > v38 )
                  v38 = v36;
                v27->m_vMaxUV.y = v38;
                v39 = &tempMesh.m_pVerts[v26 * tempMesh.m_nVertexStrideFloats];
                CopyVertex(pOut: v39, pIn: v33, nFloats: inputMesh->m_nVertexStrideFloats);
                c += 4;
                *(Vector2D *)&v39[nTexOffset] = vGutterOffset;
                tempMesh.m_pIndices[v26] = v26;
                ++v26;
                --nAdded;
                if ( *(float *)&nAdded == 0.0 )
                  break;
                v32 = c;
              }
            }
            v40 = (float *)pAdjacencyBuffer;
            v41 = v27->m_vMaxUV.x - v27->m_vMinUV.x;
            v27->m_nVertexCount = v26 - v27->m_nVertexStart;
            *v40 = v41;
            v42 = v27->m_vMaxUV.y - v27->m_vMinUV.y;
            v43 = *v40;
            v40[1] = v42;
            v44 = v43 * v42;
            v45 = v27->m_vMaxUV.x - v27->m_vMinUV.x;
            *(float *)&nTris = v44 + *(float *)&nTris;
            v46 = v27->m_vMaxUV.y - v27->m_vMinUV.y;
            if ( v45 == 0.0 || v46 == 0.0 )
            {
              m_nVertexStart = v27->m_nVertexStart;
              if ( m_nVertexStart < m_nVertexStart + v27->m_nVertexCount )
              {
                v56 = nTexOffset;
                do
                {
                  v57 = &tempMesh.m_pVerts[v56 + m_nVertexStart * tempMesh.m_nVertexStrideFloats];
                  *v57 = 0.0;
                  v57[1] = 0.0;
                  ++m_nVertexStart;
                }
                while ( m_nVertexStart < v27->m_nVertexStart + v27->m_nVertexCount );
              }
            }
            else
            {
              v47 = v27->m_nVertexStart;
              if ( v47 < v47 + v27->m_nVertexCount )
              {
                v48 = nTexOffset;
                v49 = 1.0 / v45;
                v50 = 1.0 / v46;
                do
                {
                  v51 = v48 + v47 * tempMesh.m_nVertexStrideFloats;
                  v52 = tempMesh.m_pVerts[v51] - v27->m_vMinUV.x;
                  v53 = tempMesh.m_pVerts[v51 + 1] - v27->m_vMinUV.y;
                  v54 = &tempMesh.m_pVerts[v51];
                  *v54 = v49 * v52;
                  v54[1] = v50 * v53;
                  ++v47;
                }
                while ( v47 < v27->m_nVertexStart + v27->m_nVertexCount );
              }
            }
            pAdjacencyBuffer += 7;
            ++v99;
          }
          while ( v99 < chartList.m_Size );
        }
        v58 = chartList.m_Size;
        bMadeAtlas = true;
        _Msg(a1: "Attempting to atlas %d charts\n", chartList.m_Size);
        v59 = fsqrt(*(float *)&nTris);
        v60 = 8;
        if ( (int)v59 / 64 >= 8 )
          v60 = (int)v59 / 64;
        PackChartsIntoAtlas(
          pCharts: atlasChartVector.m_Memory.m_pMemory,
          nCharts: atlasChartVector.m_Size,
          nAtlasTextureSizeX: (int)v59 - 2 * v60,
          nAtlasTextureSizeY: (int)v59 - 2 * v60,
          nAtlasGrow: v60);
        v61 = 0;
        v62 = flGutterSize / (float)nAtlasTextureSizeY;
        v63 = flGutterSize / (float)nAtlasTextureSizeX;
        vGutterOffset.y = v62;
        if ( v58 > 0 )
        {
          v64 = &atlasChartVector.m_Memory.m_pMemory->m_vAtlasMax.y;
          while ( 1 )
          {
            v65 = chartList.m_Memory.m_pMemory[v61];
            v66 = v65->m_nVertexStart;
            v67 = *(v64 - 2) + v62;
            v68 = *(v64 - 3) + v63;
            v69 = (float)(*v64 - v62) - v67;
            v70 = (float)(*(v64 - 1) - v63) - v68;
            v71 = v68 - (float)(v70 * 0.0);
            v72 = v67 - (float)(v69 * 0.0);
            if ( v66 < v66 + v65->m_nVertexCount )
            {
              do
              {
                v73 = nTexOffset + v66 * tempMesh.m_nVertexStrideFloats;
                v74 = (float)(v70 * tempMesh.m_pVerts[v73]) + v71;
                v75 = &tempMesh.m_pVerts[v73];
                *v75 = v74;
                v75[1] = (float)(v69 * v75[1]) + v72;
                ++v66;
              }
              while ( v66 < v65->m_nVertexStart + v65->m_nVertexCount );
            }
            ++v61;
            v64 += 7;
            if ( v61 >= chartList.m_Size )
              break;
            v62 = vGutterOffset.y;
          }
        }
        v76 = (float *)MemAlloc_Alloc(
                         nSize: (unsigned __int64)(unsigned int)tempMesh.m_nVertexStrideFloats >> 30 != 0
                       ? -1
                       : 4 * tempMesh.m_nVertexStrideFloats);
        m_nVertexStrideFloats = (const float *)tempMesh.m_nVertexStrideFloats;
        v78 = v76;
        for ( j = 0; j < tempMesh.m_nVertexStrideFloats; ++j )
        {
          v78[j] = 0.000001;
          m_nVertexStrideFloats = (const float *)tempMesh.m_nVertexStrideFloats;
        }
        WeldVertices(pMeshOut, inputMesh: (int)&tempMesh, pEpsilons: v78, nEpsilons: m_nVertexStrideFloats);
        free(pMem: v78);
      }
      for ( k = 0; k < chartList.m_Size; ++k )
      {
        v87 = chartList.m_Memory.m_pMemory[k];
        if ( v87 != nullptr )
        {
          v87->m_TriangleList.m_Size = 0;
          if ( v87->m_TriangleList.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v87->m_TriangleList.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v87->m_TriangleList.m_Memory.m_pMemory);
              v87->m_TriangleList.m_Memory.m_pMemory = nullptr;
            }
            v87->m_TriangleList.m_Memory.m_nAllocationCount = 0;
          }
          m_pMemory = v87->m_TriangleList.m_Memory.m_pMemory;
          v87->m_TriangleList.m_pElements = m_pMemory;
          if ( v87->m_TriangleList.m_Memory.m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
              v87->m_TriangleList.m_Memory.m_pMemory = nullptr;
            }
            v87->m_TriangleList.m_Memory.m_nAllocationCount = 0;
          }
          free(pMem: v87);
        }
      }
      m_nGrowSize = chartList.m_Memory.m_nGrowSize;
      if ( chartList.m_Memory.m_nGrowSize >= 0 && chartList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: chartList.m_Memory.m_pMemory);
        chartList.m_Memory.m_pMemory = nullptr;
      }
      CMesh::~CMesh(this: &tempMesh);
      if ( atlasChartVector.m_Memory.m_nGrowSize >= 0 && atlasChartVector.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: atlasChartVector.m_Memory.m_pMemory);
      if ( m_nGrowSize >= 0 && chartList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: chartList.m_Memory.m_pMemory);
      v90 = usedTriangles.m_Memory.m_pMemory;
      usedTriangles.m_Size = 0;
      if ( usedTriangles.m_Memory.m_nGrowSize >= 0 )
      {
        if ( usedTriangles.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: usedTriangles.m_Memory.m_pMemory);
          v90 = nullptr;
          usedTriangles.m_Memory.m_pMemory = nullptr;
        }
        usedTriangles.m_Memory.m_nAllocationCount = 0;
      }
      usedTriangles.m_pElements = v90;
      if ( usedTriangles.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v90 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v90);
          usedTriangles.m_Memory.m_pMemory = nullptr;
        }
        usedTriangles.m_Memory.m_nAllocationCount = 0;
      }
      if ( triangleIndices.m_Memory.m_nGrowSize >= 0 && triangleIndices.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: triangleIndices.m_Memory.m_pMemory);
      return bMadeAtlas;
    }
  }
  return result;
}
