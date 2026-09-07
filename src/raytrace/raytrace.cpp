// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: raytrace/raytrace.cpp
// Functions: 17
// ============================================================

#include "raytrace\raytrace.h"

//------------------------------------------------------------------------------
// Address: 0x0042E550
// Name: public: void CacheOptimizedTriangle::ChangeIntoIntersectionFormat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CacheOptimizedTriangle::ChangeIntoIntersectionFormat(CacheOptimizedTriangle *this)
{
  int m_nTriangleID; // edx
  float y; // xmm2_4
  int x_low; // xmm3_4
  int v5; // edi
  float z; // xmm4_4
  int v7; // ecx
  int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  __int128 srcTri; // [esp+4h] [ebp-50h]
  __int64 srcTri_16; // [esp+14h] [ebp-40h]
  __int128 srcTri_24; // [esp+1Ch] [ebp-38h]
  __int64 v28; // [esp+30h] [ebp-24h]
  int v29; // [esp+38h] [ebp-1Ch]
  __int64 v30; // [esp+3Ch] [ebp-18h]
  int v31; // [esp+44h] [ebp-10h]
  Vector N; // [esp+48h] [ebp-Ch] BYREF

  srcTri = *(_OWORD *)&this->m_Data.m_IntersectData.m_flNx;
  m_nTriangleID = this->m_Data.m_GeometryData.m_nTriangleID;
  srcTri_16 = *(_QWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[3];
  srcTri_24 = *(_OWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[5];
  this->m_Data.m_IntersectData.m_nFlags = LODWORD(this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
  this->m_Data.m_IntersectData.m_nTriangleID = m_nTriangleID;
  N.x = (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2)))
      - (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3)));
  N.y = (float)((float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)));
  N.z = (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)));
  VectorNormalize(vec: &N);
  y = N.y;
  x_low = LODWORD(N.x);
  v5 = fabs(N.y) > fabs(N.x);
  z = N.z;
  if ( fabs(N.z) > fabs(*(&N.x + v5)) )
    v5 = 2;
  this->m_Data.m_IntersectData.m_flD = (float)((float)(*((float *)&srcTri + 2) * N.y)
                                             + (float)(*((float *)&srcTri + 1) * N.x))
                                     + (float)(*((float *)&srcTri + 3) * N.z);
  v30 = srcTri_16;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_GeometryData.m_nTriangleID = x_low;
  this->m_Data.m_IntersectData.m_flNy = y;
  N.z = *((float *)&srcTri + 3);
  this->m_Data.m_IntersectData.m_flNz = z;
  v28 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v7 = (v5 + 1) % 3;
  v8 = (v5 + 2) % 3;
  v9 = *(&N.x + v7);
  v31 = srcTri_24;
  v10 = *((float *)&v30 + v7) - v9;
  this->m_Data.m_IntersectData.m_nCoordSelect0 = v7;
  v29 = HIDWORD(srcTri_24);
  v11 = *(&N.x + v8) - *((float *)&v30 + v8);
  v12 = (float)(v9 * v11) + (float)(*(&N.x + v8) * v10);
  v13 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_nCoordSelect1 = v8;
  v14 = -v12;
  v15 = (float)((float)(v13 * v11) + (float)(*((float *)&v28 + v8) * v10)) - v12;
  if ( v15 < 0.0 )
  {
    v11 = -v11;
    v10 = -v10;
    v14 = -v14;
    v15 = -v15;
  }
  v16 = 1.0 / v15;
  v17 = (float)(1.0 / v15) * v11;
  v18 = v16;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v16 * v14;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0] = v17;
  v28 = srcTri_16;
  v29 = srcTri_24;
  v19 = *((float *)&v28 + v8);
  v20 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1] = v18 * v10;
  v30 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v31 = HIDWORD(srcTri_24);
  v21 = v19 - *((float *)&v30 + v8);
  v22 = *((float *)&v30 + v7) - v20;
  N.z = *((float *)&srcTri + 3);
  v23 = -(float)((float)(v20 * v21) + (float)(v19 * v22));
  v24 = (float)((float)(*(&N.x + v7) * v21) + (float)(*(&N.x + v8) * v22)) + v23;
  if ( v24 < 0.0 )
  {
    v21 = -v21;
    v22 = -v22;
    v23 = -v23;
    v24 = -v24;
  }
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = (float)(1.0 / v24) * v21;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = (float)(1.0 / v24) * v22;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5] = (float)(1.0 / v24) * v23;
}

//------------------------------------------------------------------------------
// Address: 0x0042E980
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<int,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int *m_pMemory; // edx
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
      this->m_pMemory = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EA10
// Name: public: void RayTracingEnvironment::Trace4Rays<1>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<1>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(Four_Zeros, v48));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F010
// Name: public: void RayTracingEnvironment::Trace4Rays<2>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<2>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(v48, Four_Zeros));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F610
// Name: public: void RayTracingEnvironment::Trace4Rays<0>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<0>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 *v51; // ecx
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm0
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  int (__thiscall *v64)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v65; // al
  __m128 v66; // xmm4
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm2
  _DWORD v71[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v72; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v73; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v74; // [esp-D0h] [ebp-DCh]
  __m128 v75; // [esp-C0h] [ebp-CCh]
  __m128 v76; // [esp-B0h] [ebp-BCh]
  _QWORD v77[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v78; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v79; // [esp-60h] [ebp-6Ch]
  __m128 v80; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v81; // [esp-40h] [ebp-4Ch]
  int *v82; // [esp-2Ch] [ebp-38h]
  int v83; // [esp-28h] [ebp-34h]
  int v84; // [esp-24h] [ebp-30h]
  int v85; // [esp-20h] [ebp-2Ch]
  int v86; // [esp-1Ch] [ebp-28h]
  int v87; // [esp-18h] [ebp-24h]
  int v88; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v90; // [esp-Ch] [ebp-18h]
  __m128 *v91; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v93; // [esp+0h] [ebp-Ch]
  void *v94; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v93 = a4;
  v94 = retaddr;
  v9 = alloca(41592);
  v90 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v77 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v77[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v77;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v77;
  *(__m128 *)&v77[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v79 = TMin;
  v81 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v71, value: 0xFFu, count: sizeof(v71));
    if ( (a6 & 1) != 0 )
    {
      v83 = 0;
      v86 = 1;
    }
    else
    {
      v83 = 1;
      v86 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    m_pMemory = v90->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v81;
    v28 = v79;
    for ( j = (__m128 *)v71; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v91 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v90->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v77[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v83 + v31);
              v36 = *(&v86 + v31);
              v37 = v91 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v91 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v86 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v83 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v91;
        v81 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v90->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v82 )
        {
          v39 = *k;
          v82 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v90->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v90->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v90->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v71[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, a5[3]), _mm_mul_ps(a5[4], v43)), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v74 = v42;
            v47 = _mm_add_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(v42, *a5));
            v48 = _mm_mul_ps(a5[2], v44);
            v76 = v44;
            v49 = _mm_div_ps(_mm_sub_ps(_mm_shuffle_ps(m_flD_low, m_flD_low, 0), _mm_add_ps(v47, v48)), v45);
            v50 = _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v45), _mm_cmplt_ps(v45, FourNegativeEpsilons));
            v71[(unsigned __int8)v39] = v39;
            v51 = a7;
            v52 = _mm_and_ps(_mm_and_ps(v50, _mm_cmplt_ps(v26, v49)), _mm_cmplt_ps(v49, a7[4]));
            v75 = v43;
            v79 = v49;
            v80 = v52;
            if ( _mm_movemask_ps(v52) != 0 )
            {
              v53 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v56 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              v58 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v56));
              v59 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v60 = _mm_add_ps(v58, _mm_shuffle_ps(v54, v54, 0));
              v80 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v61 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v57),
                        _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v56)),
                      _mm_shuffle_ps(v59, v59, 0));
              v26 = FourZeros;
              v62 = _mm_add_ps(v61, v60);
              v73 = v60;
              v78 = v61;
              v63 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v60), v52), _mm_cmple_ps(FourZeros, v61)),
                      _mm_cmple_ps(v62, Four_Ones));
              v80 = v63;
              if ( _mm_movemask_ps(v63) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v64 = **a9;
                  v72 = _mm_sub_ps(Four_Ones, v62);
                  v65 = v64(a1: a9, a2: v40, a3: a5, a4: &v80, a5: &v78, a6: &v72, a7: &v73, a8: v39);
                  v27 = v81;
                  v49 = v79;
                  v51 = a7;
                  if ( v65 != 0 )
                  {
                    v63 = Four_Zeros;
                    v80 = Four_Zeros;
                  }
                  else
                  {
                    v63 = v80;
                  }
                }
                else
                {
                  v27 = v81;
                }
                v66 = v51[3];
                m_nCoordSelect0 = v39;
                v51[3] = _mm_or_ps(
                           _mm_andnot_ps(v63, v66),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v63));
                v67 = *v51;
                v51[4] = _mm_or_ps(_mm_andnot_ps(v63, v51[4]), _mm_and_ps(v49, v63));
                v68 = _mm_andnot_ps(v63, v67);
                v69 = v51[1];
                *v51 = _mm_or_ps(_mm_and_ps(v63, v74), v68);
                v70 = v51[2];
                v51[1] = _mm_or_ps(_mm_and_ps(v63, v75), _mm_andnot_ps(v63, v69));
                v51[2] = _mm_or_ps(_mm_and_ps(v63, v76), _mm_andnot_ps(v63, v70));
                v26 = FourZeros;
              }
              else
              {
                v27 = v81;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v91;
      }
      if ( j == (__m128 *)v71 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v81 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FC00
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        const FourRays *rays,
        char DirectionSignMask,
        RayTracingResult *rslt_out,
        int skip_id,
        ITransparentTriangleCallback *pCallback,
        RTECullMode_t cullMode)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( cullMode == RTE_CULL_FRONT )
  {
    RayTracingEnvironment::Trace4Rays<1>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else if ( cullMode == RTE_CULL_BACK )
  {
    RayTracingEnvironment::Trace4Rays<2>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else
  {
    RayTracingEnvironment::Trace4Rays<0>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FC70
// Name: public: void RayTracingEnvironment::CalculateTriangleListBounds(int const __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::CalculateTriangleListBounds(
        RayTracingEnvironment *this,
        const int *tris,
        int ntris,
        Vector *minout,
        Vector *maxout)
{
  int v7; // ecx
  float *p_m_flNz; // eax
  float x; // xmm0_4
  float v10; // xmm0_4
  float y; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // xmm0_4
  int i; // [esp+10h] [ebp+10h]

  minout->x = 9.9999998e22;
  minout->y = 9.9999998e22;
  minout->z = 9.9999998e22;
  maxout->x = -9.9999998e22;
  maxout->y = -9.9999998e22;
  maxout->z = -9.9999998e22;
  for ( i = 0; i < ntris; ++i )
  {
    v7 = 3;
    p_m_flNz = &this->OptimizedTriangleList.m_Memory.m_pMemory[tris[i] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                           + 2) >> 27)][tris[i]
                                                                                      & ((32
                                                                                        * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                          + 2)) >> 5)].m_Data.m_IntersectData.m_flNz;
    do
    {
      x = minout->x;
      if ( *(p_m_flNz - 1) <= minout->x )
        x = *(p_m_flNz - 1);
      minout->x = x;
      v10 = maxout->x;
      if ( maxout->x <= *(p_m_flNz - 1) )
        v10 = *(p_m_flNz - 1);
      maxout->x = v10;
      y = minout->y;
      if ( *p_m_flNz <= y )
        y = *p_m_flNz;
      minout->y = y;
      v12 = maxout->y;
      if ( v12 <= *p_m_flNz )
        v12 = *p_m_flNz;
      maxout->y = v12;
      z = minout->z;
      if ( p_m_flNz[1] <= z )
        z = p_m_flNz[1];
      minout->z = z;
      v14 = maxout->z;
      if ( v14 <= p_m_flNz[1] )
        v14 = p_m_flNz[1];
      p_m_flNz += 3;
      --v7;
      maxout->z = v14;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FDB0
// Name: public: float RayTracingEnvironment::CalculateCostsOfSplit(int,int const __near *,int,class Vector,class Vector,float __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall RayTracingEnvironment::CalculateCostsOfSplit(
        RayTracingEnvironment *this,
        int split_plane,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        float *split_value,
        int *nleft,
        int *nright,
        int *nboth)
{
  int *v10; // eax
  int *v11; // edx
  float v12; // xmm5_4
  float v13; // xmm4_4
  int *v14; // ebx
  int v16; // ecx
  CacheOptimizedTriangle *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  int v25; // xmm0_4
  double v26; // st7
  Vector RightMins; // [esp+0h] [ebp-1Ch]
  Vector LeftMaxes; // [esp+Ch] [ebp-10h]
  int t; // [esp+18h] [ebp-4h]
  float ISA; // [esp+4Ch] [ebp+30h]

  v10 = nleft;
  v11 = nright;
  v12 = 9.9999998e22;
  v13 = -9.9999998e22;
  v14 = nboth;
  v16 = 0;
  *nleft = 0;
  *nright = 0;
  *nboth = 0;
  t = 0;
  if ( ntris > 0 )
  {
    while ( 1 )
    {
      v17 = &this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                              + 2) >> 27)][tri_list[v16]
                                                                                         & ((32
                                                                                           * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                             + 2)) >> 5)];
      v18 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v18 <= v12 )
        v12 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v13 <= v18 )
        v13 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      v19 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v19 <= v12 )
        v12 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v13 <= v19 )
        v13 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v20 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v20 <= v12 )
        v12 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v13 <= v20 )
        v13 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      v21 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v22 = *split_value;
      v23 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v21 <= v18 )
        v18 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v23 <= v21 )
        v23 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v24 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v24 <= v18 )
        v18 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v23 <= v24 )
        v23 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v18 >= v22 )
        break;
      if ( v22 >= v23 )
      {
        v10 = nleft;
        ++*nleft;
        v11 = nright;
        v17->m_Data.m_GeometryData.m_nTmpData0 = -1;
        goto LABEL_28;
      }
      if ( v18 == v23 )
        break;
      v14 = nboth;
      ++*nboth;
      v10 = nleft;
      v11 = nright;
      v17->m_Data.m_GeometryData.m_nTmpData0 = 0;
LABEL_29:
      v16 = t + 1;
      t = v16;
      if ( v16 >= ntris )
        goto LABEL_30;
    }
    v11 = nright;
    ++*nright;
    v10 = nleft;
    v17->m_Data.m_GeometryData.m_nTmpData0 = 1;
LABEL_28:
    v14 = nboth;
    goto LABEL_29;
  }
LABEL_30:
  if ( *v10 == 0 || *v14 != 0 )
  {
LABEL_34:
    if ( *v11 == 0 )
      goto LABEL_38;
    goto LABEL_35;
  }
  if ( *v11 == 0 )
  {
    *split_value = v13;
    goto LABEL_34;
  }
LABEL_35:
  if ( *v14 == 0 && *v10 == 0 )
    *split_value = v12;
LABEL_38:
  LeftMaxes = MaxBound;
  RightMins = MinBound;
  v25 = *(_DWORD *)split_value;
  *(&LeftMaxes.x + split_plane) = *split_value;
  v26 = LeftMaxes.x - MinBound.x;
  *((_DWORD *)&RightMins.x + split_plane) = v25;
  ISA = 1.0
      / (float)((float)((float)((float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.x - MinBound.x))
                              + (float)((float)(MaxBound.y - MinBound.y) * (float)(MaxBound.x - MinBound.x)))
                      + (float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.y - MinBound.y)))
              * 2.0);
  return (((MaxBound.y - RightMins.y) * (MaxBound.z - RightMins.z)
         + (MaxBound.x - RightMins.x) * (MaxBound.y - RightMins.y)
         + (MaxBound.z - RightMins.z) * (MaxBound.x - RightMins.x))
        * 2.0
        * ISA
        * (double)*v11
        + ((LeftMaxes.y - MinBound.y) * (LeftMaxes.z - MinBound.z)
         + (LeftMaxes.z - MinBound.z) * v26
         + v26 * (LeftMaxes.y - MinBound.y))
        * 2.0
        * ISA
        * (double)*v10
        + (double)*v14)
       * 167.0
       + 75.0;
}

//------------------------------------------------------------------------------
// Address: 0x00430020
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int num)
{
  Vector *m_pMemory; // edx
  unsigned int v4; // eax
  Vector *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (Vector *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430090
// Name: public: int CUtlVector<struct CacheOptimizedKDNode,class CUtlMemory<struct CacheOptimizedKDNode,int>>::InsertBefore(int,struct CacheOptimizedKDNode const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int>>::InsertBefore(
        CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int> > *this,
        int elem,
        const CacheOptimizedKDNode *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CacheOptimizedKDNode *m_pMemory; // ecx
  int v7; // eax
  CacheOptimizedKDNode *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00430100
// Name: public: int CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>::InsertBefore(int,struct CacheOptimizedTriangle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
        CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int> > *this,
        int elem,
        const CacheOptimizedTriangle *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  CacheOptimizedTriangle *v10; // eax

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        this: &this->m_Memory,
        nBlocks: m_nBlocks + (v6 + v7 - 1) / v6);
  }
  v8 = ++this->m_Size - elem - 1;
  this->m_pElements = nullptr;
  if ( v8 > 0 )
  {
    v9 = *((_DWORD *)&this->m_Memory + 2);
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + 1) >> (v9 >> 27)][(elem + 1) & ((32 * v9) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (v9 >> 27)][elem & ((32 * v9) >> 5)],
      count: 48 * v8);
  }
  v10 = &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                               & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v10 != nullptr )
    *v10 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00430210
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        const Vector *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v7; // eax
  Vector *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Vector,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x00430290
// Name: public: void RayTracingEnvironment::MakeRoomForTriangles(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::MakeRoomForTriangles(RayTracingEnvironment *this, int ntris)
{
  if ( (this->Flags & 2) == 0 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(this: &this->TriangleColors, num: ntris);
}

//------------------------------------------------------------------------------
// Address: 0x004302B0
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color,
        unsigned __int16 flags,
        int materialIndex)
{
  float y; // xmm0_4
  int m_Size; // eax
  int m_nAllocationCount; // eax
  int v12; // edi
  int *m_pMemory; // ecx
  int v14; // eax
  int *v15; // eax
  CacheOptimizedTriangle tmptri; // [esp+0h] [ebp-30h] BYREF

  tmptri.m_Data.m_GeometryData.m_nTriangleID = id;
  *(Vector *)tmptri.m_Data.m_GeometryData.m_VertexCoordData = *v1;
  *(Vector *)&tmptri.m_Data.m_GeometryData.m_VertexCoordData[3] = *v2;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v3->x;
  y = v3->y;
  tmptri.m_Data.m_GeometryData.m_nFlags = flags;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = y;
  m_Size = this->OptimizedTriangleList.m_Size;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = v3->z;
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
    this: &this->OptimizedTriangleList,
    elem: m_Size,
    src: &tmptri);
  if ( (this->Flags & 2) == 0 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &this->TriangleColors,
      elem: this->TriangleColors.m_Size,
      src: color);
  if ( (this->Flags & 4) == 0 )
  {
    m_nAllocationCount = this->TriangleMaterials.m_Memory.m_nAllocationCount;
    v12 = this->TriangleMaterials.m_Size;
    if ( v12 + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(this: &this->TriangleMaterials.m_Memory, num: v12 - m_nAllocationCount + 1);
    ++this->TriangleMaterials.m_Size;
    m_pMemory = this->TriangleMaterials.m_Memory.m_pMemory;
    v14 = this->TriangleMaterials.m_Size - v12 - 1;
    this->TriangleMaterials.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
    v15 = &this->TriangleMaterials.m_Memory.m_pMemory[v12];
    if ( v15 != nullptr )
      *v15 = materialIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004303D0
// Name: public: void RayTracingEnvironment::RefineNode(int,int const __near *,int,class Vector,class Vector,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::RefineNode(
        RayTracingEnvironment *this,
        int node_number,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        int depth)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // edi
  float v14; // xmm6_4
  int v15; // edi
  int v16; // eax
  float v17; // xmm0_4
  bool v18; // cc
  double v19; // st7
  int v20; // edx
  int v21; // ecx
  CacheOptimizedTriangle *v22; // eax
  int *v23; // eax
  int v24; // edx
  int v25; // ecx
  float v26; // xmm0_4
  int v27; // edx
  char m_nTmpData1; // al
  float v29; // eax
  float v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  CacheOptimizedKDNode *v34; // eax
  const int *v35; // ecx
  int v36; // eax
  CacheOptimizedKDNode *v37; // edx
  int v38; // eax
  float *p_Children; // ecx
  const int *v40; // ecx
  int v41; // eax
  CacheOptimizedKDNode *v42; // edx
  int v43; // eax
  float *v44; // ecx
  int *v45; // ebx
  int v46; // edi
  int v47; // edi
  int v48; // eax
  int *v49; // ecx
  int v50; // eax
  int *v51; // edi
  Vector RightMins; // [esp+24h] [ebp-50h]
  Vector LeftMaxes; // [esp+30h] [ebp-44h]
  int *new_triangle_list; // [esp+3Ch] [ebp-38h]
  int right_child; // [esp+40h] [ebp-34h] BYREF
  int trial_nright; // [esp+44h] [ebp-30h] BYREF
  int trial_nleft; // [esp+48h] [ebp-2Ch] BYREF
  int trial_cost; // [esp+4Ch] [ebp-28h]
  float best_splitvalue; // [esp+50h] [ebp-24h]
  float best_cost; // [esp+54h] [ebp-20h]
  int best_nright; // [esp+58h] [ebp-1Ch]
  int best_nboth; // [esp+5Ch] [ebp-18h]
  int split_plane; // [esp+60h] [ebp-14h]
  int tv; // [esp+64h] [ebp-10h]
  float trial_splitvalue; // [esp+68h] [ebp-Ch] BYREF
  int best_nleft; // [esp+6Ch] [ebp-8h]
  int ts; // [esp+70h] [ebp-4h]
  const int *tri_lista; // [esp+80h] [ebp+Ch]
  const int *tri_listb; // [esp+80h] [ebp+Ch]
  int left_child; // [esp+84h] [ebp+10h]
  int *left_childa; // [esp+84h] [ebp+10h]
  int left_childb; // [esp+84h] [ebp+10h]
  Vector RightMaxes; // 0:^40.12
  Vector LeftMins; // 0:^4C.12

  if ( ntris < 3 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      m_Size = this->TriangleIndexList.m_Size;
      m_nAllocationCount = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(this: &this->TriangleIndexList.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++this->TriangleIndexList.m_Size;
      m_pMemory = this->TriangleIndexList.m_Memory.m_pMemory;
      v12 = this->TriangleIndexList.m_Size - m_Size - 1;
      this->TriangleIndexList.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &this->TriangleIndexList.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = tri_list[depth];
    }
    return;
  }
  v14 = 9.9999998e22;
  v15 = 0;
  best_cost = 9.9999998e22;
  best_nleft = 0;
  best_nright = 0;
  best_nboth = 0;
  best_splitvalue = 0.0;
  split_plane = 0;
  new_triangle_list = (int *)(ntris / 10 + 1);
  left_child = 0;
  do
  {
    v16 = -1;
    ts = -1;
    if ( ntris <= -1 )
      goto LABEL_30;
    while ( 2 )
    {
      tv = 0;
      while ( 1 )
      {
        if ( v16 == -1 )
        {
          trial_splitvalue = (float)(*(&MinBound.x + v15) + *(&MaxBound.x + v15)) * 0.5;
          goto LABEL_21;
        }
        v17 = *(&this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                                  + 2) >> 27)]->m_Data.m_IntersectData.m_flNy
              + 8 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 4 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 2 * tv
              + tv
              + left_child);
        v18 = v17 <= *(&MaxBound.x + left_child);
        trial_splitvalue = v17;
        if ( v18 && *(&MinBound.x + left_child) <= v17 )
          break;
        v15 = left_child;
LABEL_28:
        ++tv;
        v16 = ts;
        if ( tv >= 3 )
          goto LABEL_29;
      }
      v15 = left_child;
LABEL_21:
      v19 = RayTracingEnvironment::CalculateCostsOfSplit(
              this,
              split_plane: v15,
              tri_list,
              ntris,
              MinBound,
              MaxBound,
              split_value: &trial_splitvalue,
              nleft: &trial_nleft,
              nright: &trial_nright,
              nboth: &right_child);
      *(float *)&trial_cost = v19;
      if ( best_cost > v19 )
      {
        v14 = *(float *)&trial_cost;
        best_nright = trial_nright;
        v20 = 0;
        split_plane = v15;
        best_cost = *(float *)&trial_cost;
        best_nleft = trial_nleft;
        best_nboth = right_child;
        best_splitvalue = trial_splitvalue;
        if ( ntris > 0 )
        {
          do
          {
            v21 = *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2);
            trial_cost = tri_list[v20];
            v22 = &this->OptimizedTriangleList.m_Memory.m_pMemory[trial_cost >> (v21 >> 27)][trial_cost
                                                                                           & ((32 * v21) >> 5)];
            ++v20;
            v22->m_Data.m_GeometryData.m_nTmpData1 = v22->m_Data.m_GeometryData.m_nTmpData0;
          }
          while ( v20 < ntris );
          v15 = left_child;
        }
      }
      v16 = ts;
      if ( ts != -1 )
        goto LABEL_28;
LABEL_29:
      ts = (int)new_triangle_list + v16;
      if ( (int)new_triangle_list + v16 < ntris )
      {
        v16 = ts;
        continue;
      }
      break;
    }
LABEL_30:
    left_child = ++v15;
  }
  while ( v15 < 3 );
  if ( v14 >= (float)(167 * ntris) || depth > 21 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      v47 = this->TriangleIndexList.m_Size;
      v48 = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( v47 + 1 > v48 )
        CUtlMemory<int,int>::Grow(this: &this->TriangleIndexList.m_Memory, num: v47 - v48 + 1);
      ++this->TriangleIndexList.m_Size;
      v49 = this->TriangleIndexList.m_Memory.m_pMemory;
      v50 = this->TriangleIndexList.m_Size - v47 - 1;
      this->TriangleIndexList.m_pElements = v49;
      if ( v50 > 0 )
        _V_memmove(dest: &v49[v47 + 1], src: &v49[v47], count: 4 * v50);
      v51 = &this->TriangleIndexList.m_Memory.m_pMemory[v47];
      if ( v51 != nullptr )
        *v51 = tri_list[depth];
    }
  }
  else
  {
    *(float *)&v23 = COERCE_FLOAT(operator new(size: 4 * ntris));
    LeftMaxes = MaxBound;
    RightMins = MinBound;
    LeftMins = MinBound;
    RightMaxes = MaxBound;
    v24 = split_plane;
    v25 = 0;
    v26 = best_splitvalue;
    new_triangle_list = v23;
    *(&LeftMaxes.x + split_plane) = best_splitvalue;
    *(&RightMins.x + v24) = v26;
    tv = 0;
    if ( ntris > 0 )
    {
      best_cost = *(float *)&v23;
      LODWORD(best_splitvalue) = &v23[best_nleft];
      left_childa = &v23[ntris];
      do
      {
        v27 = tri_list[v25];
        m_nTmpData1 = this->OptimizedTriangleList.m_Memory.m_pMemory[v27 >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                             + 2) >> 27)][v27
                                                                                        & ((32
                                                                                          * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                            + 2)) >> 5)].m_Data.m_GeometryData.m_nTmpData1;
        if ( m_nTmpData1 == -1 )
        {
          v30 = best_cost;
          *(_DWORD *)LODWORD(best_cost) = v27;
          LODWORD(best_cost) = LODWORD(v30) + 4;
        }
        else if ( m_nTmpData1 != 0 )
        {
          if ( m_nTmpData1 == 1 )
            *--left_childa = v27;
        }
        else
        {
          v29 = best_splitvalue;
          *(_DWORD *)LODWORD(best_splitvalue) = v27;
          LODWORD(best_splitvalue) = LODWORD(v29) + 4;
        }
        v25 = tv + 1;
        tv = v25;
      }
      while ( v25 < ntris );
      v24 = split_plane;
    }
    v31 = this->OptimizedKDTree.m_Size;
    v32 = v31 + 1;
    v33 = v24 + 4 * v31;
    left_childb = v31;
    v34 = this->OptimizedKDTree.m_Memory.m_pMemory;
    right_child = v32;
    v34[node_number].Children = v33;
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue = v26;
    v36 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_lista = (const int *)this->OptimizedKDTree.m_Size;
    v35 = tri_lista;
    if ( (int)tri_lista + 1 > v36 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->OptimizedKDTree.m_Memory, num: (int)tri_lista - v36 + 1);
      v35 = tri_lista;
    }
    ++this->OptimizedKDTree.m_Size;
    v37 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v38 = this->OptimizedKDTree.m_Size - (_DWORD)v35 - 1;
    this->OptimizedKDTree.m_pElements = v37;
    if ( v38 > 0 )
    {
      _V_memmove(dest: &v37[(int)v35 + 1], src: &v37[(_DWORD)v35], count: 8 * v38);
      v35 = tri_lista;
    }
    p_Children = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v35].Children;
    if ( p_Children != nullptr )
    {
      *p_Children = MinBound.y;
      p_Children[1] = MinBound.z;
    }
    v41 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_listb = (const int *)this->OptimizedKDTree.m_Size;
    v40 = tri_listb;
    if ( (int)tri_listb + 1 > v41 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->OptimizedKDTree.m_Memory, num: (int)tri_listb - v41 + 1);
      v40 = tri_listb;
    }
    ++this->OptimizedKDTree.m_Size;
    v42 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v43 = this->OptimizedKDTree.m_Size - (_DWORD)v40 - 1;
    this->OptimizedKDTree.m_pElements = v42;
    if ( v43 > 0 )
    {
      _V_memmove(dest: &v42[(int)v40 + 1], src: &v42[(_DWORD)v40], count: 8 * v43);
      v40 = tri_listb;
    }
    v44 = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v40].Children;
    if ( v44 != nullptr )
    {
      *v44 = MinBound.y;
      v44[1] = MinBound.z;
    }
    if ( ntris < 20 && (best_nleft == 0 || best_nright == 0) )
      depth += 100;
    v45 = new_triangle_list;
    v46 = depth + 1;
    RayTracingEnvironment::RefineNode(
      this,
      node_number: left_childb,
      tri_list: new_triangle_list,
      ntris: best_nleft + best_nboth,
      MinBound: LeftMins,
      MaxBound: LeftMaxes,
      depth: depth + 1);
    RayTracingEnvironment::RefineNode(
      this,
      node_number: right_child,
      tri_list: &v45[best_nleft],
      ntris: best_nright + best_nboth,
      MinBound: RightMins,
      MaxBound: RightMaxes,
      depth: v46);
    operator delete(p: v45);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430990
// Name: public: void RayTracingEnvironment::SetupAccelerationStructure(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::SetupAccelerationStructure(RayTracingEnvironment *this)
{
  int *v2; // edi
  int i; // eax
  int j; // edi
  CacheOptimizedKDNode root; // [esp+Ch] [ebp-8h] BYREF

  CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int>>::InsertBefore(
    this: &this->OptimizedKDTree,
    elem: this->OptimizedKDTree.m_Size,
    src: &root);
  v2 = (int *)operator new(size: 4 * this->OptimizedTriangleList.m_Size);
  for ( i = 0; i < this->OptimizedTriangleList.m_Size; ++i )
    v2[i] = i;
  RayTracingEnvironment::CalculateTriangleListBounds(
    this,
    tris: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    minout: &this->m_MinBound,
    maxout: &this->m_MaxBound);
  RayTracingEnvironment::RefineNode(
    this,
    node_number: 0,
    tri_list: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    MinBound: this->m_MinBound,
    MaxBound: this->m_MaxBound,
    depth: 0);
  operator delete(p: v2);
  for ( j = 0; j < this->OptimizedTriangleList.m_Size; ++j )
    CacheOptimizedTriangle::ChangeIntoIntersectionFormat(this: &this->OptimizedTriangleList.m_Memory.m_pMemory[j >> (*((int *)&this->OptimizedTriangleList.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5)]);
}

//------------------------------------------------------------------------------
// Address: 0x00430A70
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color)
{
  RayTracingEnvironment::AddTriangle(this, id, v1, v2, v3, color, flags: 0, materialIndex: 0);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102A5410
// Name: public: int FourRays::CalculateDirectionSignMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall FourRays::CalculateDirectionSignMask(FourRays *this)
{
  int v1; // edx
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // esi
  int v7; // edx
  int result; // eax
  int v9; // esi
  int v10; // edx
  int v11; // edi
  int v12; // esi
  int v13; // edx
  int v14; // edi
  int v15; // esi
  int v16; // esi
  int v17; // edx
  int v18; // esi
  int v19; // edi
  int v20; // ecx
  int v21; // esi

  v1 = this->direction.x.m128_i32[0];
  v2 = v1 | this->direction.x.m128_i32[1];
  v3 = this->direction.x.m128_i32[2];
  v4 = v3 & this->direction.x.m128_i32[1] & v1;
  v5 = v3 | v2;
  v6 = this->direction.x.m128_i32[3];
  v7 = v6 & v4;
  if ( (v6 | v5) < 0 )
  {
    if ( v7 >= 0 )
      return -1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  v9 = this->direction.y.m128_i32[0];
  v10 = v9 | this->direction.y.m128_i32[1];
  v11 = this->direction.y.m128_i32[2];
  v12 = v11 & this->direction.y.m128_i32[1] & v9;
  v13 = v11 | v10;
  v14 = this->direction.y.m128_i32[3];
  v15 = v14 & v12;
  if ( (v14 | v13) < 0 )
  {
    if ( v15 >= 0 )
      return -1;
    result |= 2u;
  }
  v16 = this->direction.z.m128_i32[0];
  v17 = v16 | this->direction.z.m128_i32[1];
  v18 = this->direction.z.m128_i32[1] & v16;
  v19 = this->direction.z.m128_i32[2];
  v20 = this->direction.z.m128_i32[3];
  v21 = v19 & v18;
  if ( (v19 | v17 | v20) >= 0 )
    return result;
  if ( (v20 & v21) >= 0 )
    return -1;
  return result | 4;
}

//------------------------------------------------------------------------------
// Address: 0x102A5490
// Name: public: void CacheOptimizedTriangle::ChangeIntoIntersectionFormat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CacheOptimizedTriangle::ChangeIntoIntersectionFormat(CacheOptimizedTriangle *this)
{
  int m_nTriangleID; // edx
  float y; // xmm2_4
  int x_low; // xmm3_4
  int v5; // edi
  float z; // xmm4_4
  int v7; // ecx
  int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  __int128 srcTri; // [esp+4h] [ebp-50h]
  __int64 srcTri_16; // [esp+14h] [ebp-40h]
  __int128 srcTri_24; // [esp+1Ch] [ebp-38h]
  __int64 v28; // [esp+30h] [ebp-24h]
  int v29; // [esp+38h] [ebp-1Ch]
  __int64 v30; // [esp+3Ch] [ebp-18h]
  int v31; // [esp+44h] [ebp-10h]
  Vector N; // [esp+48h] [ebp-Ch] BYREF

  srcTri = *(_OWORD *)&this->m_Data.m_IntersectData.m_flNx;
  m_nTriangleID = this->m_Data.m_GeometryData.m_nTriangleID;
  srcTri_16 = *(_QWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[3];
  srcTri_24 = *(_OWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[5];
  this->m_Data.m_IntersectData.m_nFlags = LODWORD(this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
  this->m_Data.m_IntersectData.m_nTriangleID = m_nTriangleID;
  N.x = (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2)))
      - (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3)));
  N.y = (float)((float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)));
  N.z = (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)));
  VectorNormalize(vec: &N);
  y = N.y;
  x_low = LODWORD(N.x);
  v5 = fabs(N.y) > fabs(N.x);
  z = N.z;
  if ( fabs(N.z) > fabs(*(&N.x + v5)) )
    v5 = 2;
  this->m_Data.m_IntersectData.m_flD = (float)((float)(*((float *)&srcTri + 2) * N.y)
                                             + (float)(*((float *)&srcTri + 1) * N.x))
                                     + (float)(*((float *)&srcTri + 3) * N.z);
  v30 = srcTri_16;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_GeometryData.m_nTriangleID = x_low;
  this->m_Data.m_IntersectData.m_flNy = y;
  N.z = *((float *)&srcTri + 3);
  this->m_Data.m_IntersectData.m_flNz = z;
  v28 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v7 = (v5 + 1) % 3;
  v8 = (v5 + 2) % 3;
  v9 = *(&N.x + v7);
  v31 = srcTri_24;
  v10 = *((float *)&v30 + v7) - v9;
  this->m_Data.m_IntersectData.m_nCoordSelect0 = v7;
  v29 = HIDWORD(srcTri_24);
  v11 = *(&N.x + v8) - *((float *)&v30 + v8);
  v12 = (float)(v9 * v11) + (float)(*(&N.x + v8) * v10);
  v13 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_nCoordSelect1 = v8;
  v14 = -v12;
  v15 = (float)((float)(v13 * v11) + (float)(*((float *)&v28 + v8) * v10)) - v12;
  if ( v15 < 0.0 )
  {
    v11 = -v11;
    v10 = -v10;
    v14 = -v14;
    v15 = -v15;
  }
  v16 = 1.0 / v15;
  v17 = (float)(1.0 / v15) * v11;
  v18 = v16;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v16 * v14;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0] = v17;
  v28 = srcTri_16;
  v29 = srcTri_24;
  v19 = *((float *)&v28 + v8);
  v20 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1] = v18 * v10;
  v30 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v31 = HIDWORD(srcTri_24);
  v21 = v19 - *((float *)&v30 + v8);
  v22 = *((float *)&v30 + v7) - v20;
  N.z = *((float *)&srcTri + 3);
  v23 = -(float)((float)(v20 * v21) + (float)(v19 * v22));
  v24 = (float)((float)(*(&N.x + v7) * v21) + (float)(*(&N.x + v8) * v22)) + v23;
  if ( v24 < 0.0 )
  {
    v21 = -v21;
    v22 = -v22;
    v23 = -v23;
    v24 = -v24;
  }
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = (float)(1.0 / v24) * v21;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = (float)(1.0 / v24) * v22;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5] = (float)(1.0 / v24) * v23;
}

//------------------------------------------------------------------------------
// Address: 0x102A5780
// Name: public: void RayTracingEnvironment::Trace4Rays<1>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<1>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(Four_Zeros, v48));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5D80
// Name: public: void RayTracingEnvironment::Trace4Rays<2>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<2>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(v48, Four_Zeros));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A6380
// Name: public: void RayTracingEnvironment::Trace4Rays<0>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<0>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 *v51; // ecx
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm0
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  int (__thiscall *v64)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v65; // al
  __m128 v66; // xmm4
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm2
  _DWORD v71[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v72; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v73; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v74; // [esp-D0h] [ebp-DCh]
  __m128 v75; // [esp-C0h] [ebp-CCh]
  __m128 v76; // [esp-B0h] [ebp-BCh]
  _QWORD v77[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v78; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v79; // [esp-60h] [ebp-6Ch]
  __m128 v80; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v81; // [esp-40h] [ebp-4Ch]
  int *v82; // [esp-2Ch] [ebp-38h]
  int v83; // [esp-28h] [ebp-34h]
  int v84; // [esp-24h] [ebp-30h]
  int v85; // [esp-20h] [ebp-2Ch]
  int v86; // [esp-1Ch] [ebp-28h]
  int v87; // [esp-18h] [ebp-24h]
  int v88; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v90; // [esp-Ch] [ebp-18h]
  __m128 *v91; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v93; // [esp+0h] [ebp-Ch]
  void *v94; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v93 = a4;
  v94 = retaddr;
  v9 = alloca(41592);
  v90 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v77 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v77[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v77;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v77;
  *(__m128 *)&v77[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v79 = TMin;
  v81 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v71, value: 0xFFu, count: sizeof(v71));
    if ( (a6 & 1) != 0 )
    {
      v83 = 0;
      v86 = 1;
    }
    else
    {
      v83 = 1;
      v86 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    m_pMemory = v90->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v81;
    v28 = v79;
    for ( j = (__m128 *)v71; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v91 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v90->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v77[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v83 + v31);
              v36 = *(&v86 + v31);
              v37 = v91 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v91 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v86 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v83 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v91;
        v81 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v90->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v82 )
        {
          v39 = *k;
          v82 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v90->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v90->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v90->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v71[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, a5[3]), _mm_mul_ps(a5[4], v43)), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v74 = v42;
            v47 = _mm_add_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(v42, *a5));
            v48 = _mm_mul_ps(a5[2], v44);
            v76 = v44;
            v49 = _mm_div_ps(_mm_sub_ps(_mm_shuffle_ps(m_flD_low, m_flD_low, 0), _mm_add_ps(v47, v48)), v45);
            v50 = _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v45), _mm_cmplt_ps(v45, FourNegativeEpsilons));
            v71[(unsigned __int8)v39] = v39;
            v51 = a7;
            v52 = _mm_and_ps(_mm_and_ps(v50, _mm_cmplt_ps(v26, v49)), _mm_cmplt_ps(v49, a7[4]));
            v75 = v43;
            v79 = v49;
            v80 = v52;
            if ( _mm_movemask_ps(v52) != 0 )
            {
              v53 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v56 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              v58 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v56));
              v59 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v60 = _mm_add_ps(v58, _mm_shuffle_ps(v54, v54, 0));
              v80 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v61 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v57),
                        _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v56)),
                      _mm_shuffle_ps(v59, v59, 0));
              v26 = FourZeros;
              v62 = _mm_add_ps(v61, v60);
              v73 = v60;
              v78 = v61;
              v63 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v60), v52), _mm_cmple_ps(FourZeros, v61)),
                      _mm_cmple_ps(v62, Four_Ones));
              v80 = v63;
              if ( _mm_movemask_ps(v63) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v64 = **a9;
                  v72 = _mm_sub_ps(Four_Ones, v62);
                  v65 = v64(a1: a9, a2: v40, a3: a5, a4: &v80, a5: &v78, a6: &v72, a7: &v73, a8: v39);
                  v27 = v81;
                  v49 = v79;
                  v51 = a7;
                  if ( v65 != 0 )
                  {
                    v63 = Four_Zeros;
                    v80 = Four_Zeros;
                  }
                  else
                  {
                    v63 = v80;
                  }
                }
                else
                {
                  v27 = v81;
                }
                v66 = v51[3];
                m_nCoordSelect0 = v39;
                v51[3] = _mm_or_ps(
                           _mm_andnot_ps(v63, v66),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v63));
                v67 = *v51;
                v51[4] = _mm_or_ps(_mm_andnot_ps(v63, v51[4]), _mm_and_ps(v49, v63));
                v68 = _mm_andnot_ps(v63, v67);
                v69 = v51[1];
                *v51 = _mm_or_ps(_mm_and_ps(v63, v74), v68);
                v70 = v51[2];
                v51[1] = _mm_or_ps(_mm_and_ps(v63, v75), _mm_andnot_ps(v63, v69));
                v51[2] = _mm_or_ps(_mm_and_ps(v63, v76), _mm_andnot_ps(v63, v70));
                v26 = FourZeros;
              }
              else
              {
                v27 = v81;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v91;
      }
      if ( j == (__m128 *)v71 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v81 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A6970
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        const FourRays *rays,
        char DirectionSignMask,
        RayTracingResult *rslt_out,
        int skip_id,
        ITransparentTriangleCallback *pCallback,
        RTECullMode_t cullMode)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( cullMode == RTE_CULL_FRONT )
  {
    RayTracingEnvironment::Trace4Rays<1>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else if ( cullMode == RTE_CULL_BACK )
  {
    RayTracingEnvironment::Trace4Rays<2>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else
  {
    RayTracingEnvironment::Trace4Rays<0>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A69E0
// Name: public: void RayTracingEnvironment::CalculateTriangleListBounds(int const __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::CalculateTriangleListBounds(
        RayTracingEnvironment *this,
        const int *tris,
        int ntris,
        Vector *minout,
        Vector *maxout)
{
  int v7; // ecx
  float *p_m_flNz; // eax
  float x; // xmm0_4
  float v10; // xmm0_4
  float y; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // xmm0_4
  int i; // [esp+10h] [ebp+10h]

  minout->x = 9.9999998e22;
  minout->y = 9.9999998e22;
  minout->z = 9.9999998e22;
  maxout->x = -9.9999998e22;
  maxout->y = -9.9999998e22;
  maxout->z = -9.9999998e22;
  for ( i = 0; i < ntris; ++i )
  {
    v7 = 3;
    p_m_flNz = &this->OptimizedTriangleList.m_Memory.m_pMemory[tris[i] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                           + 2) >> 27)][tris[i]
                                                                                      & ((32
                                                                                        * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                          + 2)) >> 5)].m_Data.m_IntersectData.m_flNz;
    do
    {
      x = minout->x;
      if ( *(p_m_flNz - 1) <= minout->x )
        x = *(p_m_flNz - 1);
      minout->x = x;
      v10 = maxout->x;
      if ( maxout->x <= *(p_m_flNz - 1) )
        v10 = *(p_m_flNz - 1);
      maxout->x = v10;
      y = minout->y;
      if ( *p_m_flNz <= y )
        y = *p_m_flNz;
      minout->y = y;
      v12 = maxout->y;
      if ( v12 <= *p_m_flNz )
        v12 = *p_m_flNz;
      maxout->y = v12;
      z = minout->z;
      if ( p_m_flNz[1] <= z )
        z = p_m_flNz[1];
      minout->z = z;
      v14 = maxout->z;
      if ( v14 <= p_m_flNz[1] )
        v14 = p_m_flNz[1];
      p_m_flNz += 3;
      --v7;
      maxout->z = v14;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A6B10
// Name: public: float RayTracingEnvironment::CalculateCostsOfSplit(int,int const __near *,int,class Vector,class Vector,float __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall RayTracingEnvironment::CalculateCostsOfSplit(
        RayTracingEnvironment *this,
        int split_plane,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        float *split_value,
        int *nleft,
        int *nright,
        int *nboth)
{
  int *v10; // eax
  int *v11; // edx
  float v12; // xmm5_4
  float v13; // xmm4_4
  int *v14; // ebx
  int v16; // ecx
  CacheOptimizedTriangle *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  int v25; // xmm0_4
  double v26; // st7
  Vector RightMins; // [esp+0h] [ebp-1Ch]
  Vector LeftMaxes; // [esp+Ch] [ebp-10h]
  int t; // [esp+18h] [ebp-4h]
  float ISA; // [esp+4Ch] [ebp+30h]

  v10 = nleft;
  v11 = nright;
  v12 = 9.9999998e22;
  v13 = -9.9999998e22;
  v14 = nboth;
  v16 = 0;
  *nleft = 0;
  *nright = 0;
  *nboth = 0;
  t = 0;
  if ( ntris > 0 )
  {
    while ( 1 )
    {
      v17 = &this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                              + 2) >> 27)][tri_list[v16]
                                                                                         & ((32
                                                                                           * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                             + 2)) >> 5)];
      v18 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v18 <= v12 )
        v12 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v13 <= v18 )
        v13 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      v19 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v19 <= v12 )
        v12 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v13 <= v19 )
        v13 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v20 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v20 <= v12 )
        v12 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v13 <= v20 )
        v13 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      v21 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v22 = *split_value;
      v23 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v21 <= v18 )
        v18 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v23 <= v21 )
        v23 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v24 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v24 <= v18 )
        v18 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v23 <= v24 )
        v23 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v18 >= v22 )
        break;
      if ( v22 >= v23 )
      {
        v10 = nleft;
        ++*nleft;
        v11 = nright;
        v17->m_Data.m_GeometryData.m_nTmpData0 = -1;
        goto LABEL_28;
      }
      if ( v18 == v23 )
        break;
      v14 = nboth;
      ++*nboth;
      v10 = nleft;
      v11 = nright;
      v17->m_Data.m_GeometryData.m_nTmpData0 = 0;
LABEL_29:
      v16 = t + 1;
      t = v16;
      if ( v16 >= ntris )
        goto LABEL_30;
    }
    v11 = nright;
    ++*nright;
    v10 = nleft;
    v17->m_Data.m_GeometryData.m_nTmpData0 = 1;
LABEL_28:
    v14 = nboth;
    goto LABEL_29;
  }
LABEL_30:
  if ( *v10 == 0 || *v14 != 0 )
  {
LABEL_34:
    if ( *v11 == 0 )
      goto LABEL_38;
    goto LABEL_35;
  }
  if ( *v11 == 0 )
  {
    *split_value = v13;
    goto LABEL_34;
  }
LABEL_35:
  if ( *v14 == 0 && *v10 == 0 )
    *split_value = v12;
LABEL_38:
  LeftMaxes = MaxBound;
  RightMins = MinBound;
  v25 = *(_DWORD *)split_value;
  *(&LeftMaxes.x + split_plane) = *split_value;
  v26 = LeftMaxes.x - MinBound.x;
  *((_DWORD *)&RightMins.x + split_plane) = v25;
  ISA = 1.0
      / (float)((float)((float)((float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.x - MinBound.x))
                              + (float)((float)(MaxBound.y - MinBound.y) * (float)(MaxBound.x - MinBound.x)))
                      + (float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.y - MinBound.y)))
              * 2.0);
  return (((MaxBound.y - RightMins.y) * (MaxBound.z - RightMins.z)
         + (MaxBound.x - RightMins.x) * (MaxBound.y - RightMins.y)
         + (MaxBound.z - RightMins.z) * (MaxBound.x - RightMins.x))
        * 2.0
        * ISA
        * (double)*v11
        + ((LeftMaxes.y - MinBound.y) * (LeftMaxes.z - MinBound.z)
         + (LeftMaxes.z - MinBound.z) * v26
         + v26 * (LeftMaxes.y - MinBound.y))
        * 2.0
        * ISA
        * (double)*v10
        + (double)*v14)
       * 167.0
       + 75.0;
}

//------------------------------------------------------------------------------
// Address: 0x102A6E90
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        int a5,
        RayTracingResult *a6,
        int a7,
        ITransparentTriangleCallback *a8,
        RTECullMode_t a9)
{
  int v10; // eax
  int v11; // edi
  int v12; // eax
  char *v13; // ecx
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  int *v20; // esi
  int v21; // xmm4_4
  int v22; // xmm3_4
  int v23; // xmm2_4
  _BYTE *v24; // eax
  char v25; // al
  int v26; // ecx
  float *m128_f32; // eax
  int v28; // esi
  double v29; // st7
  bool v30; // zf
  _DWORD v31[3]; // [esp-Ch] [ebp-11Ch] BYREF
  RayTracingResult tmpresults_4; // [esp+4h] [ebp-10Ch] OVERLAPPED
  __m128 v33; // [esp+54h] [ebp-BCh]
  _BYTE v34[96]; // [esp+64h] [ebp-ACh] OVERLAPPED BYREF
  int v35; // [esp+D0h] [ebp-40h]
  float v36; // [esp+D4h] [ebp-3Ch]
  float v37; // [esp+D8h] [ebp-38h]
  float v38; // [esp+DCh] [ebp-34h]
  char *v39; // [esp+E0h] [ebp-30h]
  int v40; // [esp+E4h] [ebp-2Ch]
  _BYTE *v41; // [esp+E8h] [ebp-28h]
  int v42; // [esp+ECh] [ebp-24h]
  int v43; // [esp+F0h] [ebp-20h]
  int v44; // [esp+F4h] [ebp-1Ch]
  int v45; // [esp+F8h] [ebp-18h]
  RayTracingEnvironment *v46; // [esp+FCh] [ebp-14h] BYREF
  int v47; // [esp+100h] [ebp-10h]
  _DWORD v48[2]; // [esp+104h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+110h] [ebp+0h]

  v48[0] = a4;
  v48[1] = retaddr;
  tmpresults_4.HitDistance = TMax;
  v33 = TMin;
  v46 = this;
  v10 = FourRays::CalculateDirectionSignMask(this: (FourRays *)a5);
  if ( v10 == -1 )
  {
    *(_OWORD *)v34 = *(_OWORD *)a5;
    *(_OWORD *)&v34[16] = *(_OWORD *)(a5 + 16);
    v11 = 1;
    v12 = a5 + 48;
    v13 = (char *)&v46 + 3;
    *(_OWORD *)&v34[32] = *(_OWORD *)(a5 + 32);
    v47 = 16843009;
    v44 = 1;
    v45 = a5 + 48;
    v39 = (char *)&v46 + 3;
    v43 = 4;
    do
    {
      if ( v13[v11] != 0 )
      {
        v14 = *(float *)v12;
        v15 = *(float *)(v12 + 16);
        v16 = *(float *)(v12 + 32);
        v17 = 0;
        v17.m128_f32[0] = *(float *)v12;
        *(__m128 *)&v34[48] = _mm_shuffle_ps(v17, v17, 0);
        v18 = 0;
        v18.m128_f32[0] = v15;
        *(__m128 *)&v34[64] = _mm_shuffle_ps(v18, v18, 0);
        v19 = 0;
        v19.m128_f32[0] = v16;
        v13[v11] = 2;
        *(__m128 *)&v34[80] = _mm_shuffle_ps(v19, v19, 0);
        if ( v11 < 4 )
        {
          v20 = (int *)(v12 + 20);
          v41 = &v34[-a5 + 16];
          do
          {
            if ( *((_BYTE *)&v48[-1] + v11) != 0 )
            {
              v21 = *(v20 - 4);
              v38 = v14;
              v40 = v21;
              if ( (((v21 < 0) ^ (unsigned __int8)~(v14 < 0.0)) & 1) != 0 )
              {
                v22 = *v20;
                v37 = v15;
                v42 = v22;
                if ( (((v22 < 0) ^ (unsigned __int8)~(v15 < 0.0)) & 1) != 0 )
                {
                  v23 = v20[4];
                  v36 = v16;
                  v35 = v23;
                  if ( (((v23 < 0) ^ (unsigned __int8)~(v16 < 0.0)) & 1) != 0 )
                  {
                    v24 = v41;
                    *((_BYTE *)&v48[-1] + v11) = 2;
                    *(_DWORD *)&v34[4 * v11 + 48] = v21;
                    *(_DWORD *)&v34[(_DWORD)v20 - a5] = v22;
                    *(int *)((char *)v20 + (_DWORD)v24) = v23;
                  }
                }
              }
            }
            ++v11;
            ++v20;
          }
          while ( v11 < 4 );
        }
        v25 = FourRays::CalculateDirectionSignMask(this: (FourRays *)v34);
        if ( a9 == RTE_CULL_FRONT )
        {
          RayTracingEnvironment::Trace4Rays<1>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        else if ( a9 == RTE_CULL_BACK )
        {
          RayTracingEnvironment::Trace4Rays<2>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        else
        {
          RayTracingEnvironment::Trace4Rays<0>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        v26 = 0;
        m128_f32 = a6->HitDistance.m128_f32;
        do
        {
          if ( *((_BYTE *)&v48[-1] + v26) == 2 )
          {
            v28 = tmpresults_4.HitIds[v26 - 4];
            *m128_f32 = *(float *)((char *)m128_f32 + (char *)v31 - (char *)a6);
            *((_BYTE *)&v48[-1] + v26) = 0;
            v29 = *(float *)&v31[v26];
            *((_DWORD *)m128_f32 - 4) = v28;
            *(m128_f32 - 16) = v29;
            *(m128_f32 - 12) = tmpresults_4.surface_normal.x.m128_f32[v26];
            *(m128_f32 - 8) = *(float *)&tmpresults_4.HitIds[v26 - 8];
          }
          ++v26;
          ++m128_f32;
        }
        while ( v26 < 4 );
        TMin = v33;
        TMax = tmpresults_4.HitDistance;
        v12 = v45;
        v11 = v44;
        v13 = v39;
      }
      v12 += 4;
      ++v11;
      v30 = v43-- == 1;
      v45 = v12;
      v44 = v11;
    }
    while ( !v30 );
  }
  else
  {
    RayTracingEnvironment::Trace4Rays(
      this,
      TMin,
      TMax,
      rays: (const FourRays *)a5,
      DirectionSignMask: v10,
      rslt_out: a6,
      skip_id: a7,
      pCallback: a8,
      cullMode: a9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A7130
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color,
        unsigned __int16 flags,
        int materialIndex)
{
  float y; // xmm0_4
  int m_Size; // eax
  int m_nAllocationCount; // eax
  int v12; // edi
  int *m_pMemory; // ecx
  int v14; // eax
  int *v15; // eax
  CacheOptimizedTriangle tmptri; // [esp+0h] [ebp-30h] BYREF

  tmptri.m_Data.m_GeometryData.m_nTriangleID = id;
  *(Vector *)tmptri.m_Data.m_GeometryData.m_VertexCoordData = *v1;
  *(Vector *)&tmptri.m_Data.m_GeometryData.m_VertexCoordData[3] = *v2;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v3->x;
  y = v3->y;
  tmptri.m_Data.m_GeometryData.m_nFlags = flags;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = y;
  m_Size = this->OptimizedTriangleList.m_Size;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = v3->z;
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
    this: &this->OptimizedTriangleList,
    elem: m_Size,
    src: &tmptri);
  if ( (this->Flags & 2) == 0 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &this->TriangleColors,
      elem: this->TriangleColors.m_Size,
      src: color);
  if ( (this->Flags & 4) == 0 )
  {
    m_nAllocationCount = this->TriangleMaterials.m_Memory.m_nAllocationCount;
    v12 = this->TriangleMaterials.m_Size;
    if ( v12 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->TriangleMaterials,
        num: v12 - m_nAllocationCount + 1);
    ++this->TriangleMaterials.m_Size;
    m_pMemory = this->TriangleMaterials.m_Memory.m_pMemory;
    v14 = this->TriangleMaterials.m_Size - v12 - 1;
    this->TriangleMaterials.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
    v15 = &this->TriangleMaterials.m_Memory.m_pMemory[v12];
    if ( v15 != nullptr )
      *v15 = materialIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A7250
// Name: public: void RayTracingEnvironment::RefineNode(int,int const __near *,int,class Vector,class Vector,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::RefineNode(
        RayTracingEnvironment *this,
        int node_number,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        int depth)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // edi
  float v14; // xmm6_4
  int v15; // edi
  int v16; // eax
  float v17; // xmm0_4
  bool v18; // cc
  double v19; // st7
  int v20; // edx
  int v21; // ecx
  CacheOptimizedTriangle *v22; // eax
  int *v23; // eax
  int v24; // edx
  int v25; // ecx
  float v26; // xmm0_4
  int v27; // edx
  char m_nTmpData1; // al
  float v29; // eax
  float v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  CacheOptimizedKDNode *v34; // eax
  const int *v35; // ecx
  int v36; // eax
  CacheOptimizedKDNode *v37; // edx
  int v38; // eax
  float *p_Children; // ecx
  const int *v40; // ecx
  int v41; // eax
  CacheOptimizedKDNode *v42; // edx
  int v43; // eax
  float *v44; // ecx
  int *v45; // ebx
  int v46; // edi
  int v47; // edi
  int v48; // eax
  int *v49; // ecx
  int v50; // eax
  int *v51; // edi
  Vector RightMins; // [esp+24h] [ebp-50h]
  Vector LeftMaxes; // [esp+30h] [ebp-44h]
  int *new_triangle_list; // [esp+3Ch] [ebp-38h]
  int right_child; // [esp+40h] [ebp-34h] BYREF
  int trial_nright; // [esp+44h] [ebp-30h] BYREF
  int trial_nleft; // [esp+48h] [ebp-2Ch] BYREF
  int trial_cost; // [esp+4Ch] [ebp-28h]
  float best_splitvalue; // [esp+50h] [ebp-24h]
  float best_cost; // [esp+54h] [ebp-20h]
  int best_nright; // [esp+58h] [ebp-1Ch]
  int best_nboth; // [esp+5Ch] [ebp-18h]
  int split_plane; // [esp+60h] [ebp-14h]
  int tv; // [esp+64h] [ebp-10h]
  float trial_splitvalue; // [esp+68h] [ebp-Ch] BYREF
  int best_nleft; // [esp+6Ch] [ebp-8h]
  int ts; // [esp+70h] [ebp-4h]
  const int *tri_lista; // [esp+80h] [ebp+Ch]
  const int *tri_listb; // [esp+80h] [ebp+Ch]
  int left_child; // [esp+84h] [ebp+10h]
  int *left_childa; // [esp+84h] [ebp+10h]
  int left_childb; // [esp+84h] [ebp+10h]
  Vector RightMaxes; // 0:^40.12
  Vector LeftMins; // 0:^4C.12

  if ( ntris < 3 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      m_Size = this->TriangleIndexList.m_Size;
      m_nAllocationCount = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->TriangleIndexList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->TriangleIndexList.m_Size;
      m_pMemory = this->TriangleIndexList.m_Memory.m_pMemory;
      v12 = this->TriangleIndexList.m_Size - m_Size - 1;
      this->TriangleIndexList.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &this->TriangleIndexList.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = tri_list[depth];
    }
    return;
  }
  v14 = 9.9999998e22;
  v15 = 0;
  best_cost = 9.9999998e22;
  best_nleft = 0;
  best_nright = 0;
  best_nboth = 0;
  best_splitvalue = 0.0;
  split_plane = 0;
  new_triangle_list = (int *)(ntris / 10 + 1);
  left_child = 0;
  do
  {
    v16 = -1;
    ts = -1;
    if ( ntris <= -1 )
      goto LABEL_30;
    while ( 2 )
    {
      tv = 0;
      while ( 1 )
      {
        if ( v16 == -1 )
        {
          trial_splitvalue = (float)(*(&MinBound.x + v15) + *(&MaxBound.x + v15)) * 0.5;
          goto LABEL_21;
        }
        v17 = *(&this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                                  + 2) >> 27)]->m_Data.m_IntersectData.m_flNy
              + 8 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 4 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 2 * tv
              + tv
              + left_child);
        v18 = v17 <= *(&MaxBound.x + left_child);
        trial_splitvalue = v17;
        if ( v18 && *(&MinBound.x + left_child) <= v17 )
          break;
        v15 = left_child;
LABEL_28:
        ++tv;
        v16 = ts;
        if ( tv >= 3 )
          goto LABEL_29;
      }
      v15 = left_child;
LABEL_21:
      v19 = RayTracingEnvironment::CalculateCostsOfSplit(
              this,
              split_plane: v15,
              tri_list,
              ntris,
              MinBound,
              MaxBound,
              split_value: &trial_splitvalue,
              nleft: &trial_nleft,
              nright: &trial_nright,
              nboth: &right_child);
      *(float *)&trial_cost = v19;
      if ( best_cost > v19 )
      {
        v14 = *(float *)&trial_cost;
        best_nright = trial_nright;
        v20 = 0;
        split_plane = v15;
        best_cost = *(float *)&trial_cost;
        best_nleft = trial_nleft;
        best_nboth = right_child;
        best_splitvalue = trial_splitvalue;
        if ( ntris > 0 )
        {
          do
          {
            v21 = *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2);
            trial_cost = tri_list[v20];
            v22 = &this->OptimizedTriangleList.m_Memory.m_pMemory[trial_cost >> (v21 >> 27)][trial_cost
                                                                                           & ((32 * v21) >> 5)];
            ++v20;
            v22->m_Data.m_GeometryData.m_nTmpData1 = v22->m_Data.m_GeometryData.m_nTmpData0;
          }
          while ( v20 < ntris );
          v15 = left_child;
        }
      }
      v16 = ts;
      if ( ts != -1 )
        goto LABEL_28;
LABEL_29:
      ts = (int)new_triangle_list + v16;
      if ( (int)new_triangle_list + v16 < ntris )
      {
        v16 = ts;
        continue;
      }
      break;
    }
LABEL_30:
    left_child = ++v15;
  }
  while ( v15 < 3 );
  if ( v14 >= (float)(167 * ntris) || depth > 21 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      v47 = this->TriangleIndexList.m_Size;
      v48 = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( v47 + 1 > v48 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->TriangleIndexList,
          num: v47 - v48 + 1);
      ++this->TriangleIndexList.m_Size;
      v49 = this->TriangleIndexList.m_Memory.m_pMemory;
      v50 = this->TriangleIndexList.m_Size - v47 - 1;
      this->TriangleIndexList.m_pElements = v49;
      if ( v50 > 0 )
        _V_memmove(dest: &v49[v47 + 1], src: &v49[v47], count: 4 * v50);
      v51 = &this->TriangleIndexList.m_Memory.m_pMemory[v47];
      if ( v51 != nullptr )
        *v51 = tri_list[depth];
    }
  }
  else
  {
    *(float *)&v23 = COERCE_FLOAT(operator new(nSize: 4 * ntris));
    LeftMaxes = MaxBound;
    RightMins = MinBound;
    LeftMins = MinBound;
    RightMaxes = MaxBound;
    v24 = split_plane;
    v25 = 0;
    v26 = best_splitvalue;
    new_triangle_list = v23;
    *(&LeftMaxes.x + split_plane) = best_splitvalue;
    *(&RightMins.x + v24) = v26;
    tv = 0;
    if ( ntris > 0 )
    {
      best_cost = *(float *)&v23;
      LODWORD(best_splitvalue) = &v23[best_nleft];
      left_childa = &v23[ntris];
      do
      {
        v27 = tri_list[v25];
        m_nTmpData1 = this->OptimizedTriangleList.m_Memory.m_pMemory[v27 >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                             + 2) >> 27)][v27
                                                                                        & ((32
                                                                                          * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                            + 2)) >> 5)].m_Data.m_GeometryData.m_nTmpData1;
        if ( m_nTmpData1 == -1 )
        {
          v30 = best_cost;
          *(_DWORD *)LODWORD(best_cost) = v27;
          LODWORD(best_cost) = LODWORD(v30) + 4;
        }
        else if ( m_nTmpData1 != 0 )
        {
          if ( m_nTmpData1 == 1 )
            *--left_childa = v27;
        }
        else
        {
          v29 = best_splitvalue;
          *(_DWORD *)LODWORD(best_splitvalue) = v27;
          LODWORD(best_splitvalue) = LODWORD(v29) + 4;
        }
        v25 = tv + 1;
        tv = v25;
      }
      while ( v25 < ntris );
      v24 = split_plane;
    }
    v31 = this->OptimizedKDTree.m_Size;
    v32 = v31 + 1;
    v33 = v24 + 4 * v31;
    left_childb = v31;
    v34 = this->OptimizedKDTree.m_Memory.m_pMemory;
    right_child = v32;
    v34[node_number].Children = v33;
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue = v26;
    v36 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_lista = (const int *)this->OptimizedKDTree.m_Size;
    v35 = tri_lista;
    if ( (int)tri_lista + 1 > v36 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(
        this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->OptimizedKDTree,
        num: (int)tri_lista - v36 + 1);
      v35 = tri_lista;
    }
    ++this->OptimizedKDTree.m_Size;
    v37 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v38 = this->OptimizedKDTree.m_Size - (_DWORD)v35 - 1;
    this->OptimizedKDTree.m_pElements = v37;
    if ( v38 > 0 )
    {
      _V_memmove(dest: &v37[(int)v35 + 1], src: &v37[(_DWORD)v35], count: 8 * v38);
      v35 = tri_lista;
    }
    p_Children = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v35].Children;
    if ( p_Children != nullptr )
    {
      *p_Children = MinBound.y;
      p_Children[1] = MinBound.z;
    }
    v41 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_listb = (const int *)this->OptimizedKDTree.m_Size;
    v40 = tri_listb;
    if ( (int)tri_listb + 1 > v41 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(
        this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->OptimizedKDTree,
        num: (int)tri_listb - v41 + 1);
      v40 = tri_listb;
    }
    ++this->OptimizedKDTree.m_Size;
    v42 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v43 = this->OptimizedKDTree.m_Size - (_DWORD)v40 - 1;
    this->OptimizedKDTree.m_pElements = v42;
    if ( v43 > 0 )
    {
      _V_memmove(dest: &v42[(int)v40 + 1], src: &v42[(_DWORD)v40], count: 8 * v43);
      v40 = tri_listb;
    }
    v44 = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v40].Children;
    if ( v44 != nullptr )
    {
      *v44 = MinBound.y;
      v44[1] = MinBound.z;
    }
    if ( ntris < 20 && (best_nleft == 0 || best_nright == 0) )
      depth += 100;
    v45 = new_triangle_list;
    v46 = depth + 1;
    RayTracingEnvironment::RefineNode(
      this,
      node_number: left_childb,
      tri_list: new_triangle_list,
      ntris: best_nleft + best_nboth,
      MinBound: LeftMins,
      MaxBound: LeftMaxes,
      depth: depth + 1);
    RayTracingEnvironment::RefineNode(
      this,
      node_number: right_child,
      tri_list: &v45[best_nleft],
      ntris: best_nright + best_nboth,
      MinBound: RightMins,
      MaxBound: RightMaxes,
      depth: v46);
    operator delete(p: v45);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A7810
// Name: public: void RayTracingEnvironment::SetupAccelerationStructure(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::SetupAccelerationStructure(RayTracingEnvironment *this)
{
  int *v2; // edi
  int i; // eax
  int j; // edi
  CacheOptimizedKDNode root; // [esp+Ch] [ebp-8h] BYREF

  CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->OptimizedKDTree,
    elem: this->OptimizedKDTree.m_Size,
    src: (const vgui::PropertySheet::Page_t *)&root);
  v2 = (int *)operator new(nSize: 4 * this->OptimizedTriangleList.m_Size);
  for ( i = 0; i < this->OptimizedTriangleList.m_Size; ++i )
    v2[i] = i;
  RayTracingEnvironment::CalculateTriangleListBounds(
    this,
    tris: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    minout: &this->m_MinBound,
    maxout: &this->m_MaxBound);
  RayTracingEnvironment::RefineNode(
    this,
    node_number: 0,
    tri_list: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    MinBound: this->m_MinBound,
    MaxBound: this->m_MaxBound,
    depth: 0);
  operator delete(p: v2);
  for ( j = 0; j < this->OptimizedTriangleList.m_Size; ++j )
    CacheOptimizedTriangle::ChangeIntoIntersectionFormat(this: &this->OptimizedTriangleList.m_Memory.m_pMemory[j >> (*((int *)&this->OptimizedTriangleList.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5)]);
}

//------------------------------------------------------------------------------
// Address: 0x102A78F0
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color)
{
  RayTracingEnvironment::AddTriangle(this, id, v1, v2, v3, color, flags: 0, materialIndex: 0);
}

} // namespace hammer_dll

// ============================================================
// Overlay from lightworld (Missing functions)
// ============================================================
namespace lightworld {

//------------------------------------------------------------------------------
// Address: 0x0040BA70
// Name: public: void RayTracingEnvironment::Trace4Rays<1>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<1>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(Four_Zeros, v48));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C070
// Name: public: void RayTracingEnvironment::Trace4Rays<2>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<2>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(v48, Four_Zeros));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C670
// Name: public: void RayTracingEnvironment::Trace4Rays<0>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<0>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 *v51; // ecx
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm0
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  int (__thiscall *v64)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v65; // al
  __m128 v66; // xmm4
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm2
  _DWORD v71[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v72; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v73; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v74; // [esp-D0h] [ebp-DCh]
  __m128 v75; // [esp-C0h] [ebp-CCh]
  __m128 v76; // [esp-B0h] [ebp-BCh]
  _QWORD v77[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v78; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v79; // [esp-60h] [ebp-6Ch]
  __m128 v80; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v81; // [esp-40h] [ebp-4Ch]
  int *v82; // [esp-2Ch] [ebp-38h]
  int v83; // [esp-28h] [ebp-34h]
  int v84; // [esp-24h] [ebp-30h]
  int v85; // [esp-20h] [ebp-2Ch]
  int v86; // [esp-1Ch] [ebp-28h]
  int v87; // [esp-18h] [ebp-24h]
  int v88; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v90; // [esp-Ch] [ebp-18h]
  __m128 *v91; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v93; // [esp+0h] [ebp-Ch]
  void *v94; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v93 = a4;
  v94 = retaddr;
  v9 = alloca(41592);
  v90 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v77 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v77[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v77;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v77;
  *(__m128 *)&v77[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v79 = TMin;
  v81 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v71, value: 0xFFu, count: sizeof(v71));
    if ( (a6 & 1) != 0 )
    {
      v83 = 0;
      v86 = 1;
    }
    else
    {
      v83 = 1;
      v86 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    m_pMemory = v90->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v81;
    v28 = v79;
    for ( j = (__m128 *)v71; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v91 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v90->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v77[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v83 + v31);
              v36 = *(&v86 + v31);
              v37 = v91 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v91 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v86 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v83 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v91;
        v81 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v90->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v82 )
        {
          v39 = *k;
          v82 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v90->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v90->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v90->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v71[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, a5[3]), _mm_mul_ps(a5[4], v43)), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v74 = v42;
            v47 = _mm_add_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(v42, *a5));
            v48 = _mm_mul_ps(a5[2], v44);
            v76 = v44;
            v49 = _mm_div_ps(_mm_sub_ps(_mm_shuffle_ps(m_flD_low, m_flD_low, 0), _mm_add_ps(v47, v48)), v45);
            v50 = _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v45), _mm_cmplt_ps(v45, FourNegativeEpsilons));
            v71[(unsigned __int8)v39] = v39;
            v51 = a7;
            v52 = _mm_and_ps(_mm_and_ps(v50, _mm_cmplt_ps(v26, v49)), _mm_cmplt_ps(v49, a7[4]));
            v75 = v43;
            v79 = v49;
            v80 = v52;
            if ( _mm_movemask_ps(v52) != 0 )
            {
              v53 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v56 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              v58 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v56));
              v59 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v60 = _mm_add_ps(v58, _mm_shuffle_ps(v54, v54, 0));
              v80 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v61 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v57),
                        _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v56)),
                      _mm_shuffle_ps(v59, v59, 0));
              v26 = FourZeros;
              v62 = _mm_add_ps(v61, v60);
              v73 = v60;
              v78 = v61;
              v63 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v60), v52), _mm_cmple_ps(FourZeros, v61)),
                      _mm_cmple_ps(v62, Four_Ones));
              v80 = v63;
              if ( _mm_movemask_ps(v63) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v64 = **a9;
                  v72 = _mm_sub_ps(Four_Ones, v62);
                  v65 = v64(a1: a9, a2: v40, a3: a5, a4: &v80, a5: &v78, a6: &v72, a7: &v73, a8: v39);
                  v27 = v81;
                  v49 = v79;
                  v51 = a7;
                  if ( v65 != 0 )
                  {
                    v63 = Four_Zeros;
                    v80 = Four_Zeros;
                  }
                  else
                  {
                    v63 = v80;
                  }
                }
                else
                {
                  v27 = v81;
                }
                v66 = v51[3];
                m_nCoordSelect0 = v39;
                v51[3] = _mm_or_ps(
                           _mm_andnot_ps(v63, v66),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v63));
                v67 = *v51;
                v51[4] = _mm_or_ps(_mm_andnot_ps(v63, v51[4]), _mm_and_ps(v49, v63));
                v68 = _mm_andnot_ps(v63, v67);
                v69 = v51[1];
                *v51 = _mm_or_ps(_mm_and_ps(v63, v74), v68);
                v70 = v51[2];
                v51[1] = _mm_or_ps(_mm_and_ps(v63, v75), _mm_andnot_ps(v63, v69));
                v51[2] = _mm_or_ps(_mm_and_ps(v63, v76), _mm_andnot_ps(v63, v70));
                v26 = FourZeros;
              }
              else
              {
                v27 = v81;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v91;
      }
      if ( j == (__m128 *)v71 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v81 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC60
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        const FourRays *rays,
        char DirectionSignMask,
        RayTracingResult *rslt_out,
        int skip_id,
        ITransparentTriangleCallback *pCallback,
        RTECullMode_t cullMode)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( cullMode == RTE_CULL_FRONT )
  {
    RayTracingEnvironment::Trace4Rays<1>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else if ( cullMode == RTE_CULL_BACK )
  {
    RayTracingEnvironment::Trace4Rays<2>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else
  {
    RayTracingEnvironment::Trace4Rays<0>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
}

} // namespace lightworld

// ============================================================
// Overlay from subdbaker (Missing functions)
// ============================================================
namespace subdbaker {

//------------------------------------------------------------------------------
// Address: 0x004C2AF0
// Name: public: void CacheOptimizedTriangle::ChangeIntoIntersectionFormat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CacheOptimizedTriangle::ChangeIntoIntersectionFormat(CacheOptimizedTriangle *this)
{
  int m_nTriangleID; // edx
  float y; // xmm2_4
  int x_low; // xmm3_4
  int v5; // edi
  float z; // xmm4_4
  int v7; // ecx
  int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  __int128 srcTri; // [esp+4h] [ebp-50h]
  __int64 srcTri_16; // [esp+14h] [ebp-40h]
  __int128 srcTri_24; // [esp+1Ch] [ebp-38h]
  __int64 v28; // [esp+30h] [ebp-24h]
  int v29; // [esp+38h] [ebp-1Ch]
  __int64 v30; // [esp+3Ch] [ebp-18h]
  int v31; // [esp+44h] [ebp-10h]
  Vector N; // [esp+48h] [ebp-Ch] BYREF

  srcTri = *(_OWORD *)&this->m_Data.m_IntersectData.m_flNx;
  m_nTriangleID = this->m_Data.m_GeometryData.m_nTriangleID;
  srcTri_16 = *(_QWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[3];
  srcTri_24 = *(_OWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[5];
  this->m_Data.m_IntersectData.m_nFlags = LODWORD(this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
  this->m_Data.m_IntersectData.m_nTriangleID = m_nTriangleID;
  N.x = (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2)))
      - (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3)));
  N.y = (float)((float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)));
  N.z = (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)));
  VectorNormalize(vec: &N);
  y = N.y;
  x_low = LODWORD(N.x);
  v5 = fabs(N.y) > fabs(N.x);
  z = N.z;
  if ( fabs(N.z) > fabs(*(&N.x + v5)) )
    v5 = 2;
  this->m_Data.m_IntersectData.m_flD = (float)((float)(*((float *)&srcTri + 2) * N.y)
                                             + (float)(*((float *)&srcTri + 1) * N.x))
                                     + (float)(*((float *)&srcTri + 3) * N.z);
  v30 = srcTri_16;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_GeometryData.m_nTriangleID = x_low;
  this->m_Data.m_IntersectData.m_flNy = y;
  N.z = *((float *)&srcTri + 3);
  this->m_Data.m_IntersectData.m_flNz = z;
  v28 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v7 = (v5 + 1) % 3;
  v8 = (v5 + 2) % 3;
  v9 = *(&N.x + v7);
  v31 = srcTri_24;
  v10 = *((float *)&v30 + v7) - v9;
  this->m_Data.m_IntersectData.m_nCoordSelect0 = v7;
  v29 = HIDWORD(srcTri_24);
  v11 = *(&N.x + v8) - *((float *)&v30 + v8);
  v12 = (float)(v9 * v11) + (float)(*(&N.x + v8) * v10);
  v13 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_nCoordSelect1 = v8;
  v14 = -v12;
  v15 = (float)((float)(v13 * v11) + (float)(*((float *)&v28 + v8) * v10)) - v12;
  if ( v15 < 0.0 )
  {
    v11 = -v11;
    v10 = -v10;
    v14 = -v14;
    v15 = -v15;
  }
  v16 = 1.0 / v15;
  v17 = (float)(1.0 / v15) * v11;
  v18 = v16;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v16 * v14;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0] = v17;
  v28 = srcTri_16;
  v29 = srcTri_24;
  v19 = *((float *)&v28 + v8);
  v20 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1] = v18 * v10;
  v30 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v31 = HIDWORD(srcTri_24);
  v21 = v19 - *((float *)&v30 + v8);
  v22 = *((float *)&v30 + v7) - v20;
  N.z = *((float *)&srcTri + 3);
  v23 = -(float)((float)(v20 * v21) + (float)(v19 * v22));
  v24 = (float)((float)(*(&N.x + v7) * v21) + (float)(*(&N.x + v8) * v22)) + v23;
  if ( v24 < 0.0 )
  {
    v21 = -v21;
    v22 = -v22;
    v23 = -v23;
    v24 = -v24;
  }
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = (float)(1.0 / v24) * v21;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = (float)(1.0 / v24) * v22;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5] = (float)(1.0 / v24) * v23;
}

//------------------------------------------------------------------------------
// Address: 0x004C2E80
// Name: public: void RayTracingEnvironment::Trace4Rays<1>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<1>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (int)v72, value: (unsigned __int8 *)0xFF, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(Four_Zeros, v48));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C3480
// Name: public: void RayTracingEnvironment::Trace4Rays<2>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<2>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (int)v72, value: (unsigned __int8 *)0xFF, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(v48, Four_Zeros));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C3A80
// Name: public: void RayTracingEnvironment::Trace4Rays<0>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<0>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 *v51; // ecx
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm0
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  int (__thiscall *v64)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v65; // al
  __m128 v66; // xmm4
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm2
  _DWORD v71[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v72; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v73; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v74; // [esp-D0h] [ebp-DCh]
  __m128 v75; // [esp-C0h] [ebp-CCh]
  __m128 v76; // [esp-B0h] [ebp-BCh]
  _QWORD v77[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v78; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v79; // [esp-60h] [ebp-6Ch]
  __m128 v80; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v81; // [esp-40h] [ebp-4Ch]
  int *v82; // [esp-2Ch] [ebp-38h]
  int v83; // [esp-28h] [ebp-34h]
  int v84; // [esp-24h] [ebp-30h]
  int v85; // [esp-20h] [ebp-2Ch]
  int v86; // [esp-1Ch] [ebp-28h]
  int v87; // [esp-18h] [ebp-24h]
  int v88; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v90; // [esp-Ch] [ebp-18h]
  __m128 *v91; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v93; // [esp+0h] [ebp-Ch]
  void *v94; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v93 = a4;
  v94 = retaddr;
  v9 = alloca(41592);
  v90 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v77 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v77[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v77;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v77;
  *(__m128 *)&v77[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v79 = TMin;
  v81 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (int)v71, value: (unsigned __int8 *)0xFF, count: sizeof(v71));
    if ( (a6 & 1) != 0 )
    {
      v83 = 0;
      v86 = 1;
    }
    else
    {
      v83 = 1;
      v86 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    m_pMemory = v90->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v81;
    v28 = v79;
    for ( j = (__m128 *)v71; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v91 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v90->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v77[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v83 + v31);
              v36 = *(&v86 + v31);
              v37 = v91 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v91 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v86 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v83 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v91;
        v81 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v90->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v82 )
        {
          v39 = *k;
          v82 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v90->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v90->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v90->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v71[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, a5[3]), _mm_mul_ps(a5[4], v43)), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v74 = v42;
            v47 = _mm_add_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(v42, *a5));
            v48 = _mm_mul_ps(a5[2], v44);
            v76 = v44;
            v49 = _mm_div_ps(_mm_sub_ps(_mm_shuffle_ps(m_flD_low, m_flD_low, 0), _mm_add_ps(v47, v48)), v45);
            v50 = _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v45), _mm_cmplt_ps(v45, FourNegativeEpsilons));
            v71[(unsigned __int8)v39] = v39;
            v51 = a7;
            v52 = _mm_and_ps(_mm_and_ps(v50, _mm_cmplt_ps(v26, v49)), _mm_cmplt_ps(v49, a7[4]));
            v75 = v43;
            v79 = v49;
            v80 = v52;
            if ( _mm_movemask_ps(v52) != 0 )
            {
              v53 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v56 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              v58 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v56));
              v59 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v60 = _mm_add_ps(v58, _mm_shuffle_ps(v54, v54, 0));
              v80 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v61 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v57),
                        _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v56)),
                      _mm_shuffle_ps(v59, v59, 0));
              v26 = FourZeros;
              v62 = _mm_add_ps(v61, v60);
              v73 = v60;
              v78 = v61;
              v63 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v60), v52), _mm_cmple_ps(FourZeros, v61)),
                      _mm_cmple_ps(v62, Four_Ones));
              v80 = v63;
              if ( _mm_movemask_ps(v63) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v64 = **a9;
                  v72 = _mm_sub_ps(Four_Ones, v62);
                  v65 = v64(a1: a9, a2: v40, a3: a5, a4: &v80, a5: &v78, a6: &v72, a7: &v73, a8: v39);
                  v27 = v81;
                  v49 = v79;
                  v51 = a7;
                  if ( v65 != 0 )
                  {
                    v63 = Four_Zeros;
                    v80 = Four_Zeros;
                  }
                  else
                  {
                    v63 = v80;
                  }
                }
                else
                {
                  v27 = v81;
                }
                v66 = v51[3];
                m_nCoordSelect0 = v39;
                v51[3] = _mm_or_ps(
                           _mm_andnot_ps(v63, v66),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v63));
                v67 = *v51;
                v51[4] = _mm_or_ps(_mm_andnot_ps(v63, v51[4]), _mm_and_ps(v49, v63));
                v68 = _mm_andnot_ps(v63, v67);
                v69 = v51[1];
                *v51 = _mm_or_ps(_mm_and_ps(v63, v74), v68);
                v70 = v51[2];
                v51[1] = _mm_or_ps(_mm_and_ps(v63, v75), _mm_andnot_ps(v63, v69));
                v51[2] = _mm_or_ps(_mm_and_ps(v63, v76), _mm_andnot_ps(v63, v70));
                v26 = FourZeros;
              }
              else
              {
                v27 = v81;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v91;
      }
      if ( j == (__m128 *)v71 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v81 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4070
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        const FourRays *rays,
        char DirectionSignMask,
        RayTracingResult *rslt_out,
        int skip_id,
        ITransparentTriangleCallback *pCallback,
        RTECullMode_t cullMode)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( cullMode == RTE_CULL_FRONT )
  {
    RayTracingEnvironment::Trace4Rays<1>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else if ( cullMode == RTE_CULL_BACK )
  {
    RayTracingEnvironment::Trace4Rays<2>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else
  {
    RayTracingEnvironment::Trace4Rays<0>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C40E0
// Name: public: void RayTracingEnvironment::CalculateTriangleListBounds(int const __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::CalculateTriangleListBounds(
        RayTracingEnvironment *this,
        const int *tris,
        int ntris,
        Vector *minout,
        Vector *maxout)
{
  int v7; // ecx
  float *p_m_flNz; // eax
  float x; // xmm0_4
  float v10; // xmm0_4
  float y; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // xmm0_4
  int i; // [esp+10h] [ebp+10h]

  minout->x = 9.9999998e22;
  minout->y = 9.9999998e22;
  minout->z = 9.9999998e22;
  maxout->x = -9.9999998e22;
  maxout->y = -9.9999998e22;
  maxout->z = -9.9999998e22;
  for ( i = 0; i < ntris; ++i )
  {
    v7 = 3;
    p_m_flNz = &this->OptimizedTriangleList.m_Memory.m_pMemory[tris[i] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                           + 2) >> 27)][tris[i]
                                                                                      & ((32
                                                                                        * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                          + 2)) >> 5)].m_Data.m_IntersectData.m_flNz;
    do
    {
      x = minout->x;
      if ( *(p_m_flNz - 1) <= minout->x )
        x = *(p_m_flNz - 1);
      minout->x = x;
      v10 = maxout->x;
      if ( maxout->x <= *(p_m_flNz - 1) )
        v10 = *(p_m_flNz - 1);
      maxout->x = v10;
      y = minout->y;
      if ( *p_m_flNz <= y )
        y = *p_m_flNz;
      minout->y = y;
      v12 = maxout->y;
      if ( v12 <= *p_m_flNz )
        v12 = *p_m_flNz;
      maxout->y = v12;
      z = minout->z;
      if ( p_m_flNz[1] <= z )
        z = p_m_flNz[1];
      minout->z = z;
      v14 = maxout->z;
      if ( v14 <= p_m_flNz[1] )
        v14 = p_m_flNz[1];
      p_m_flNz += 3;
      --v7;
      maxout->z = v14;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4210
// Name: public: float RayTracingEnvironment::CalculateCostsOfSplit(int,int const __near *,int,class Vector,class Vector,float __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall RayTracingEnvironment::CalculateCostsOfSplit(
        RayTracingEnvironment *this,
        int split_plane,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        float *split_value,
        int *nleft,
        int *nright,
        int *nboth)
{
  int *v10; // eax
  int *v11; // edx
  float v12; // xmm5_4
  float v13; // xmm4_4
  int *v14; // ebx
  int v16; // ecx
  CacheOptimizedTriangle *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  int v25; // xmm0_4
  double v26; // st7
  Vector RightMins; // [esp+0h] [ebp-1Ch]
  Vector LeftMaxes; // [esp+Ch] [ebp-10h]
  int t; // [esp+18h] [ebp-4h]
  float ISA; // [esp+4Ch] [ebp+30h]

  v10 = nleft;
  v11 = nright;
  v12 = 9.9999998e22;
  v13 = -9.9999998e22;
  v14 = nboth;
  v16 = 0;
  *nleft = 0;
  *nright = 0;
  *nboth = 0;
  t = 0;
  if ( ntris > 0 )
  {
    while ( 1 )
    {
      v17 = &this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                              + 2) >> 27)][tri_list[v16]
                                                                                         & ((32
                                                                                           * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                             + 2)) >> 5)];
      v18 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v18 <= v12 )
        v12 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v13 <= v18 )
        v13 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      v19 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v19 <= v12 )
        v12 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v13 <= v19 )
        v13 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v20 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v20 <= v12 )
        v12 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v13 <= v20 )
        v13 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      v21 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v22 = *split_value;
      v23 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v21 <= v18 )
        v18 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v23 <= v21 )
        v23 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v24 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v24 <= v18 )
        v18 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v23 <= v24 )
        v23 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v18 >= v22 )
        break;
      if ( v22 >= v23 )
      {
        v10 = nleft;
        ++*nleft;
        v11 = nright;
        v17->m_Data.m_GeometryData.m_nTmpData0 = -1;
        goto LABEL_28;
      }
      if ( v18 == v23 )
        break;
      v14 = nboth;
      ++*nboth;
      v10 = nleft;
      v11 = nright;
      v17->m_Data.m_GeometryData.m_nTmpData0 = 0;
LABEL_29:
      v16 = t + 1;
      t = v16;
      if ( v16 >= ntris )
        goto LABEL_30;
    }
    v11 = nright;
    ++*nright;
    v10 = nleft;
    v17->m_Data.m_GeometryData.m_nTmpData0 = 1;
LABEL_28:
    v14 = nboth;
    goto LABEL_29;
  }
LABEL_30:
  if ( *v10 == 0 || *v14 != 0 )
  {
LABEL_34:
    if ( *v11 == 0 )
      goto LABEL_38;
    goto LABEL_35;
  }
  if ( *v11 == 0 )
  {
    *split_value = v13;
    goto LABEL_34;
  }
LABEL_35:
  if ( *v14 == 0 && *v10 == 0 )
    *split_value = v12;
LABEL_38:
  LeftMaxes = MaxBound;
  RightMins = MinBound;
  v25 = *(_DWORD *)split_value;
  *(&LeftMaxes.x + split_plane) = *split_value;
  v26 = LeftMaxes.x - MinBound.x;
  *((_DWORD *)&RightMins.x + split_plane) = v25;
  ISA = 1.0
      / (float)((float)((float)((float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.x - MinBound.x))
                              + (float)((float)(MaxBound.y - MinBound.y) * (float)(MaxBound.x - MinBound.x)))
                      + (float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.y - MinBound.y)))
              * 2.0);
  return (((MaxBound.y - RightMins.y) * (MaxBound.z - RightMins.z)
         + (MaxBound.x - RightMins.x) * (MaxBound.y - RightMins.y)
         + (MaxBound.z - RightMins.z) * (MaxBound.x - RightMins.x))
        * 2.0
        * ISA
        * (double)*v11
        + ((LeftMaxes.y - MinBound.y) * (LeftMaxes.z - MinBound.z)
         + (LeftMaxes.z - MinBound.z) * v26
         + v26 * (LeftMaxes.y - MinBound.y))
        * 2.0
        * ISA
        * (double)*v10
        + (double)*v14)
       * 167.0
       + 75.0;
}

//------------------------------------------------------------------------------
// Address: 0x004C46F0
// Name: public: void RayTracingEnvironment::MakeRoomForTriangles(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::MakeRoomForTriangles(RayTracingEnvironment *this, int ntris)
{
  if ( (this->Flags & 2) == 0 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(this: &this->TriangleColors, num: ntris);
}

//------------------------------------------------------------------------------
// Address: 0x004C4710
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color,
        unsigned __int16 flags,
        int materialIndex)
{
  float y; // xmm0_4
  int m_Size; // eax
  int m_nAllocationCount; // eax
  int v12; // edi
  int *m_pMemory; // ecx
  int v14; // eax
  int *v15; // eax
  CacheOptimizedTriangle tmptri; // [esp+0h] [ebp-30h] BYREF

  tmptri.m_Data.m_GeometryData.m_nTriangleID = id;
  *(Vector *)tmptri.m_Data.m_GeometryData.m_VertexCoordData = *v1;
  *(Vector *)&tmptri.m_Data.m_GeometryData.m_VertexCoordData[3] = *v2;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v3->x;
  y = v3->y;
  tmptri.m_Data.m_GeometryData.m_nFlags = flags;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = y;
  m_Size = this->OptimizedTriangleList.m_Size;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = v3->z;
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
    this: &this->OptimizedTriangleList,
    elem: m_Size,
    src: &tmptri);
  if ( (this->Flags & 2) == 0 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &this->TriangleColors,
      elem: this->TriangleColors.m_Size,
      src: color);
  if ( (this->Flags & 4) == 0 )
  {
    m_nAllocationCount = this->TriangleMaterials.m_Memory.m_nAllocationCount;
    v12 = this->TriangleMaterials.m_Size;
    if ( v12 + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<KeyValues *,int> *)&this->TriangleMaterials,
        num: v12 - m_nAllocationCount + 1);
    ++this->TriangleMaterials.m_Size;
    m_pMemory = this->TriangleMaterials.m_Memory.m_pMemory;
    v14 = this->TriangleMaterials.m_Size - v12 - 1;
    this->TriangleMaterials.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
    v15 = &this->TriangleMaterials.m_Memory.m_pMemory[v12];
    if ( v15 != nullptr )
      *v15 = materialIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4830
// Name: public: void RayTracingEnvironment::RefineNode(int,int const __near *,int,class Vector,class Vector,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::RefineNode(
        RayTracingEnvironment *this,
        int node_number,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        int depth)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // edi
  float v14; // xmm6_4
  int v15; // edi
  int v16; // eax
  float v17; // xmm0_4
  bool v18; // cc
  double v19; // st7
  int v20; // edx
  int v21; // ecx
  CacheOptimizedTriangle *v22; // eax
  int *v23; // eax
  int v24; // edx
  int v25; // ecx
  float v26; // xmm0_4
  int v27; // edx
  char m_nTmpData1; // al
  float v29; // eax
  float v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  CacheOptimizedKDNode *v34; // eax
  const int *v35; // ecx
  int v36; // eax
  CacheOptimizedKDNode *v37; // edx
  int v38; // eax
  float *p_Children; // ecx
  const int *v40; // ecx
  int v41; // eax
  CacheOptimizedKDNode *v42; // edx
  int v43; // eax
  float *v44; // ecx
  int *v45; // ebx
  int v46; // edi
  int v47; // edi
  int v48; // eax
  int *v49; // ecx
  int v50; // eax
  int *v51; // edi
  Vector RightMins; // [esp+24h] [ebp-50h]
  Vector LeftMaxes; // [esp+30h] [ebp-44h]
  int *new_triangle_list; // [esp+3Ch] [ebp-38h]
  int right_child; // [esp+40h] [ebp-34h] BYREF
  int trial_nright; // [esp+44h] [ebp-30h] BYREF
  int trial_nleft; // [esp+48h] [ebp-2Ch] BYREF
  int trial_cost; // [esp+4Ch] [ebp-28h]
  float best_splitvalue; // [esp+50h] [ebp-24h]
  float best_cost; // [esp+54h] [ebp-20h]
  int best_nright; // [esp+58h] [ebp-1Ch]
  int best_nboth; // [esp+5Ch] [ebp-18h]
  int split_plane; // [esp+60h] [ebp-14h]
  int tv; // [esp+64h] [ebp-10h]
  float trial_splitvalue; // [esp+68h] [ebp-Ch] BYREF
  int best_nleft; // [esp+6Ch] [ebp-8h]
  int ts; // [esp+70h] [ebp-4h]
  const int *tri_lista; // [esp+80h] [ebp+Ch]
  const int *tri_listb; // [esp+80h] [ebp+Ch]
  int left_child; // [esp+84h] [ebp+10h]
  int *left_childa; // [esp+84h] [ebp+10h]
  int left_childb; // [esp+84h] [ebp+10h]
  Vector RightMaxes; // 0:^40.12
  Vector LeftMins; // 0:^4C.12

  if ( ntris < 3 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      m_Size = this->TriangleIndexList.m_Size;
      m_nAllocationCount = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<KeyValues *,int> *)&this->TriangleIndexList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->TriangleIndexList.m_Size;
      m_pMemory = this->TriangleIndexList.m_Memory.m_pMemory;
      v12 = this->TriangleIndexList.m_Size - m_Size - 1;
      this->TriangleIndexList.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &this->TriangleIndexList.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = tri_list[depth];
    }
    return;
  }
  v14 = 9.9999998e22;
  v15 = 0;
  best_cost = 9.9999998e22;
  best_nleft = 0;
  best_nright = 0;
  best_nboth = 0;
  best_splitvalue = 0.0;
  split_plane = 0;
  new_triangle_list = (int *)(ntris / 10 + 1);
  left_child = 0;
  do
  {
    v16 = -1;
    ts = -1;
    if ( ntris <= -1 )
      goto LABEL_30;
    while ( 2 )
    {
      tv = 0;
      while ( 1 )
      {
        if ( v16 == -1 )
        {
          trial_splitvalue = (float)(*(&MinBound.x + v15) + *(&MaxBound.x + v15)) * 0.5;
          goto LABEL_21;
        }
        v17 = *(&this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                                  + 2) >> 27)]->m_Data.m_IntersectData.m_flNy
              + 8 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 4 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 2 * tv
              + tv
              + left_child);
        v18 = v17 <= *(&MaxBound.x + left_child);
        trial_splitvalue = v17;
        if ( v18 && *(&MinBound.x + left_child) <= v17 )
          break;
        v15 = left_child;
LABEL_28:
        ++tv;
        v16 = ts;
        if ( tv >= 3 )
          goto LABEL_29;
      }
      v15 = left_child;
LABEL_21:
      v19 = RayTracingEnvironment::CalculateCostsOfSplit(
              this,
              split_plane: v15,
              tri_list,
              ntris,
              MinBound,
              MaxBound,
              split_value: &trial_splitvalue,
              nleft: &trial_nleft,
              nright: &trial_nright,
              nboth: &right_child);
      *(float *)&trial_cost = v19;
      if ( best_cost > v19 )
      {
        v14 = *(float *)&trial_cost;
        best_nright = trial_nright;
        v20 = 0;
        split_plane = v15;
        best_cost = *(float *)&trial_cost;
        best_nleft = trial_nleft;
        best_nboth = right_child;
        best_splitvalue = trial_splitvalue;
        if ( ntris > 0 )
        {
          do
          {
            v21 = *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2);
            trial_cost = tri_list[v20];
            v22 = &this->OptimizedTriangleList.m_Memory.m_pMemory[trial_cost >> (v21 >> 27)][trial_cost
                                                                                           & ((32 * v21) >> 5)];
            ++v20;
            v22->m_Data.m_GeometryData.m_nTmpData1 = v22->m_Data.m_GeometryData.m_nTmpData0;
          }
          while ( v20 < ntris );
          v15 = left_child;
        }
      }
      v16 = ts;
      if ( ts != -1 )
        goto LABEL_28;
LABEL_29:
      ts = (int)new_triangle_list + v16;
      if ( (int)new_triangle_list + v16 < ntris )
      {
        v16 = ts;
        continue;
      }
      break;
    }
LABEL_30:
    left_child = ++v15;
  }
  while ( v15 < 3 );
  if ( v14 >= (float)(167 * ntris) || depth > 21 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      v47 = this->TriangleIndexList.m_Size;
      v48 = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( v47 + 1 > v48 )
        CUtlMemory<int,int>::Grow(this: (CUtlMemory<KeyValues *,int> *)&this->TriangleIndexList, num: v47 - v48 + 1);
      ++this->TriangleIndexList.m_Size;
      v49 = this->TriangleIndexList.m_Memory.m_pMemory;
      v50 = this->TriangleIndexList.m_Size - v47 - 1;
      this->TriangleIndexList.m_pElements = v49;
      if ( v50 > 0 )
        _V_memmove(dest: &v49[v47 + 1], src: &v49[v47], count: 4 * v50);
      v51 = &this->TriangleIndexList.m_Memory.m_pMemory[v47];
      if ( v51 != nullptr )
        *v51 = tri_list[depth];
    }
  }
  else
  {
    *(float *)&v23 = COERCE_FLOAT(operator new(nSize: 4 * ntris));
    LeftMaxes = MaxBound;
    RightMins = MinBound;
    LeftMins = MinBound;
    RightMaxes = MaxBound;
    v24 = split_plane;
    v25 = 0;
    v26 = best_splitvalue;
    new_triangle_list = v23;
    *(&LeftMaxes.x + split_plane) = best_splitvalue;
    *(&RightMins.x + v24) = v26;
    tv = 0;
    if ( ntris > 0 )
    {
      best_cost = *(float *)&v23;
      LODWORD(best_splitvalue) = &v23[best_nleft];
      left_childa = &v23[ntris];
      do
      {
        v27 = tri_list[v25];
        m_nTmpData1 = this->OptimizedTriangleList.m_Memory.m_pMemory[v27 >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                             + 2) >> 27)][v27
                                                                                        & ((32
                                                                                          * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                            + 2)) >> 5)].m_Data.m_GeometryData.m_nTmpData1;
        if ( m_nTmpData1 == -1 )
        {
          v30 = best_cost;
          *(_DWORD *)LODWORD(best_cost) = v27;
          LODWORD(best_cost) = LODWORD(v30) + 4;
        }
        else if ( m_nTmpData1 != 0 )
        {
          if ( m_nTmpData1 == 1 )
            *--left_childa = v27;
        }
        else
        {
          v29 = best_splitvalue;
          *(_DWORD *)LODWORD(best_splitvalue) = v27;
          LODWORD(best_splitvalue) = LODWORD(v29) + 4;
        }
        v25 = tv + 1;
        tv = v25;
      }
      while ( v25 < ntris );
      v24 = split_plane;
    }
    v31 = this->OptimizedKDTree.m_Size;
    v32 = v31 + 1;
    v33 = v24 + 4 * v31;
    left_childb = v31;
    v34 = this->OptimizedKDTree.m_Memory.m_pMemory;
    right_child = v32;
    v34[node_number].Children = v33;
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue = v26;
    v36 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_lista = (const int *)this->OptimizedKDTree.m_Size;
    v35 = tri_lista;
    if ( (int)tri_lista + 1 > v36 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->OptimizedKDTree.m_Memory, num: (int)tri_lista - v36 + 1);
      v35 = tri_lista;
    }
    ++this->OptimizedKDTree.m_Size;
    v37 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v38 = this->OptimizedKDTree.m_Size - (_DWORD)v35 - 1;
    this->OptimizedKDTree.m_pElements = v37;
    if ( v38 > 0 )
    {
      _V_memmove(dest: &v37[(int)v35 + 1], src: &v37[(_DWORD)v35], count: 8 * v38);
      v35 = tri_lista;
    }
    p_Children = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v35].Children;
    if ( p_Children != nullptr )
    {
      *p_Children = MinBound.y;
      p_Children[1] = MinBound.z;
    }
    v41 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_listb = (const int *)this->OptimizedKDTree.m_Size;
    v40 = tri_listb;
    if ( (int)tri_listb + 1 > v41 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->OptimizedKDTree.m_Memory, num: (int)tri_listb - v41 + 1);
      v40 = tri_listb;
    }
    ++this->OptimizedKDTree.m_Size;
    v42 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v43 = this->OptimizedKDTree.m_Size - (_DWORD)v40 - 1;
    this->OptimizedKDTree.m_pElements = v42;
    if ( v43 > 0 )
    {
      _V_memmove(dest: &v42[(int)v40 + 1], src: &v42[(_DWORD)v40], count: 8 * v43);
      v40 = tri_listb;
    }
    v44 = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v40].Children;
    if ( v44 != nullptr )
    {
      *v44 = MinBound.y;
      v44[1] = MinBound.z;
    }
    if ( ntris < 20 && (best_nleft == 0 || best_nright == 0) )
      depth += 100;
    v45 = new_triangle_list;
    v46 = depth + 1;
    RayTracingEnvironment::RefineNode(
      this,
      node_number: left_childb,
      tri_list: new_triangle_list,
      ntris: best_nleft + best_nboth,
      MinBound: LeftMins,
      MaxBound: LeftMaxes,
      depth: depth + 1);
    RayTracingEnvironment::RefineNode(
      this,
      node_number: right_child,
      tri_list: &v45[best_nleft],
      ntris: best_nright + best_nboth,
      MinBound: RightMins,
      MaxBound: RightMaxes,
      depth: v46);
    free(pMem: v45);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4DF0
// Name: public: void RayTracingEnvironment::SetupAccelerationStructure(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::SetupAccelerationStructure(RayTracingEnvironment *this)
{
  int *v2; // edi
  int i; // eax
  int j; // edi
  CacheOptimizedKDNode root; // [esp+Ch] [ebp-8h] BYREF

  CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int>>::InsertBefore(
    this: &this->OptimizedKDTree,
    elem: this->OptimizedKDTree.m_Size,
    src: &root);
  v2 = (int *)operator new(nSize: 4 * this->OptimizedTriangleList.m_Size);
  for ( i = 0; i < this->OptimizedTriangleList.m_Size; ++i )
    v2[i] = i;
  RayTracingEnvironment::CalculateTriangleListBounds(
    this,
    tris: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    minout: &this->m_MinBound,
    maxout: &this->m_MaxBound);
  RayTracingEnvironment::RefineNode(
    this,
    node_number: 0,
    tri_list: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    MinBound: this->m_MinBound,
    MaxBound: this->m_MaxBound,
    depth: 0);
  free(pMem: v2);
  for ( j = 0; j < this->OptimizedTriangleList.m_Size; ++j )
    CacheOptimizedTriangle::ChangeIntoIntersectionFormat(this: &this->OptimizedTriangleList.m_Memory.m_pMemory[j >> (*((int *)&this->OptimizedTriangleList.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5)]);
}

//------------------------------------------------------------------------------
// Address: 0x004C4ED0
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color)
{
  RayTracingEnvironment::AddTriangle(this, id, v1, v2, v3, color, flags: 0, materialIndex: 0);
}

} // namespace subdbaker

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00640B00
// Name: public: void CacheOptimizedTriangle::ChangeIntoIntersectionFormat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CacheOptimizedTriangle::ChangeIntoIntersectionFormat(CacheOptimizedTriangle *this)
{
  int m_nTriangleID; // edx
  float y; // xmm2_4
  int x_low; // xmm3_4
  int v5; // edi
  float z; // xmm4_4
  int v7; // ecx
  int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  __int128 srcTri; // [esp+4h] [ebp-50h]
  __int64 srcTri_16; // [esp+14h] [ebp-40h]
  __int128 srcTri_24; // [esp+1Ch] [ebp-38h]
  __int64 v28; // [esp+30h] [ebp-24h]
  int v29; // [esp+38h] [ebp-1Ch]
  __int64 v30; // [esp+3Ch] [ebp-18h]
  int v31; // [esp+44h] [ebp-10h]
  Vector N; // [esp+48h] [ebp-Ch] BYREF

  srcTri = *(_OWORD *)&this->m_Data.m_IntersectData.m_flNx;
  m_nTriangleID = this->m_Data.m_GeometryData.m_nTriangleID;
  srcTri_16 = *(_QWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[3];
  srcTri_24 = *(_OWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[5];
  this->m_Data.m_IntersectData.m_nFlags = LODWORD(this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
  this->m_Data.m_IntersectData.m_nTriangleID = m_nTriangleID;
  N.x = (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2)))
      - (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3)));
  N.y = (float)((float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)));
  N.z = (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)));
  VectorNormalize(vec: &N);
  y = N.y;
  x_low = LODWORD(N.x);
  v5 = fabs(N.y) > fabs(N.x);
  z = N.z;
  if ( fabs(N.z) > fabs(*(&N.x + v5)) )
    v5 = 2;
  this->m_Data.m_IntersectData.m_flD = (float)((float)(*((float *)&srcTri + 2) * N.y)
                                             + (float)(*((float *)&srcTri + 1) * N.x))
                                     + (float)(*((float *)&srcTri + 3) * N.z);
  v30 = srcTri_16;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_GeometryData.m_nTriangleID = x_low;
  this->m_Data.m_IntersectData.m_flNy = y;
  N.z = *((float *)&srcTri + 3);
  this->m_Data.m_IntersectData.m_flNz = z;
  v28 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v7 = (v5 + 1) % 3;
  v8 = (v5 + 2) % 3;
  v9 = *(&N.x + v7);
  v31 = srcTri_24;
  v10 = *((float *)&v30 + v7) - v9;
  this->m_Data.m_IntersectData.m_nCoordSelect0 = v7;
  v29 = HIDWORD(srcTri_24);
  v11 = *(&N.x + v8) - *((float *)&v30 + v8);
  v12 = (float)(v9 * v11) + (float)(*(&N.x + v8) * v10);
  v13 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_nCoordSelect1 = v8;
  v14 = -v12;
  v15 = (float)((float)(v13 * v11) + (float)(*((float *)&v28 + v8) * v10)) - v12;
  if ( v15 < 0.0 )
  {
    v11 = -v11;
    v10 = -v10;
    v14 = -v14;
    v15 = -v15;
  }
  v16 = 1.0 / v15;
  v17 = (float)(1.0 / v15) * v11;
  v18 = v16;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v16 * v14;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0] = v17;
  v28 = srcTri_16;
  v29 = srcTri_24;
  v19 = *((float *)&v28 + v8);
  v20 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1] = v18 * v10;
  v30 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v31 = HIDWORD(srcTri_24);
  v21 = v19 - *((float *)&v30 + v8);
  v22 = *((float *)&v30 + v7) - v20;
  N.z = *((float *)&srcTri + 3);
  v23 = -(float)((float)(v20 * v21) + (float)(v19 * v22));
  v24 = (float)((float)(*(&N.x + v7) * v21) + (float)(*(&N.x + v8) * v22)) + v23;
  if ( v24 < 0.0 )
  {
    v21 = -v21;
    v22 = -v22;
    v23 = -v23;
    v24 = -v24;
  }
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = (float)(1.0 / v24) * v21;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = (float)(1.0 / v24) * v22;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5] = (float)(1.0 / v24) * v23;
}

//------------------------------------------------------------------------------
// Address: 0x00640DF0
// Name: public: unsigned int RayTracingEnvironment::GetSerializationNumBytes(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall RayTracingEnvironment::GetSerializationNumBytes(RayTracingEnvironment *this, char nSerializationFlags)
{
  int result; // eax

  result = 4
         * (this->TriangleIndexList.m_Size
          + 2 * (this->OptimizedKDTree.m_Size + 2 * (3 * this->OptimizedTriangleList.m_Size + 3)));
  if ( (nSerializationFlags & 1) != 0 )
    result += 12 * this->TriangleColors.m_Size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00640E30
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00640EA0
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00640F10
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) != 0 )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00640F80
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00641030
// Name: public: void RayTracingEnvironment::Trace4Rays<1>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<1>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(Four_Zeros, v48));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00641630
// Name: public: void RayTracingEnvironment::Trace4Rays<2>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<2>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(v48, Four_Zeros));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00641C30
// Name: public: void RayTracingEnvironment::Trace4Rays<0>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<0>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 *v51; // ecx
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm0
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  int (__thiscall *v64)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v65; // al
  __m128 v66; // xmm4
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm2
  _DWORD v71[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v72; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v73; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v74; // [esp-D0h] [ebp-DCh]
  __m128 v75; // [esp-C0h] [ebp-CCh]
  __m128 v76; // [esp-B0h] [ebp-BCh]
  _QWORD v77[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v78; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v79; // [esp-60h] [ebp-6Ch]
  __m128 v80; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v81; // [esp-40h] [ebp-4Ch]
  int *v82; // [esp-2Ch] [ebp-38h]
  int v83; // [esp-28h] [ebp-34h]
  int v84; // [esp-24h] [ebp-30h]
  int v85; // [esp-20h] [ebp-2Ch]
  int v86; // [esp-1Ch] [ebp-28h]
  int v87; // [esp-18h] [ebp-24h]
  int v88; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v90; // [esp-Ch] [ebp-18h]
  __m128 *v91; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v93; // [esp+0h] [ebp-Ch]
  void *v94; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v93 = a4;
  v94 = retaddr;
  v9 = alloca(41592);
  v90 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v77 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v77[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v77;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v77;
  *(__m128 *)&v77[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v79 = TMin;
  v81 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v71, value: 0xFFu, count: sizeof(v71));
    if ( (a6 & 1) != 0 )
    {
      v83 = 0;
      v86 = 1;
    }
    else
    {
      v83 = 1;
      v86 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    m_pMemory = v90->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v81;
    v28 = v79;
    for ( j = (__m128 *)v71; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v91 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v90->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v77[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v83 + v31);
              v36 = *(&v86 + v31);
              v37 = v91 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v91 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v86 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v83 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v91;
        v81 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v90->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v82 )
        {
          v39 = *k;
          v82 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v90->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v90->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v90->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v71[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, a5[3]), _mm_mul_ps(a5[4], v43)), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v74 = v42;
            v47 = _mm_add_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(v42, *a5));
            v48 = _mm_mul_ps(a5[2], v44);
            v76 = v44;
            v49 = _mm_div_ps(_mm_sub_ps(_mm_shuffle_ps(m_flD_low, m_flD_low, 0), _mm_add_ps(v47, v48)), v45);
            v50 = _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v45), _mm_cmplt_ps(v45, FourNegativeEpsilons));
            v71[(unsigned __int8)v39] = v39;
            v51 = a7;
            v52 = _mm_and_ps(_mm_and_ps(v50, _mm_cmplt_ps(v26, v49)), _mm_cmplt_ps(v49, a7[4]));
            v75 = v43;
            v79 = v49;
            v80 = v52;
            if ( _mm_movemask_ps(v52) != 0 )
            {
              v53 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v56 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              v58 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v56));
              v59 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v60 = _mm_add_ps(v58, _mm_shuffle_ps(v54, v54, 0));
              v80 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v61 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v57),
                        _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v56)),
                      _mm_shuffle_ps(v59, v59, 0));
              v26 = FourZeros;
              v62 = _mm_add_ps(v61, v60);
              v73 = v60;
              v78 = v61;
              v63 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v60), v52), _mm_cmple_ps(FourZeros, v61)),
                      _mm_cmple_ps(v62, Four_Ones));
              v80 = v63;
              if ( _mm_movemask_ps(v63) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v64 = **a9;
                  v72 = _mm_sub_ps(Four_Ones, v62);
                  v65 = v64(a1: a9, a2: v40, a3: a5, a4: &v80, a5: &v78, a6: &v72, a7: &v73, a8: v39);
                  v27 = v81;
                  v49 = v79;
                  v51 = a7;
                  if ( v65 != 0 )
                  {
                    v63 = Four_Zeros;
                    v80 = Four_Zeros;
                  }
                  else
                  {
                    v63 = v80;
                  }
                }
                else
                {
                  v27 = v81;
                }
                v66 = v51[3];
                m_nCoordSelect0 = v39;
                v51[3] = _mm_or_ps(
                           _mm_andnot_ps(v63, v66),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v63));
                v67 = *v51;
                v51[4] = _mm_or_ps(_mm_andnot_ps(v63, v51[4]), _mm_and_ps(v49, v63));
                v68 = _mm_andnot_ps(v63, v67);
                v69 = v51[1];
                *v51 = _mm_or_ps(_mm_and_ps(v63, v74), v68);
                v70 = v51[2];
                v51[1] = _mm_or_ps(_mm_and_ps(v63, v75), _mm_andnot_ps(v63, v69));
                v51[2] = _mm_or_ps(_mm_and_ps(v63, v76), _mm_andnot_ps(v63, v70));
                v26 = FourZeros;
              }
              else
              {
                v27 = v81;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v91;
      }
      if ( j == (__m128 *)v71 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v81 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00642220
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        const FourRays *rays,
        char DirectionSignMask,
        RayTracingResult *rslt_out,
        int skip_id,
        ITransparentTriangleCallback *pCallback,
        RTECullMode_t cullMode)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( cullMode == RTE_CULL_FRONT )
  {
    RayTracingEnvironment::Trace4Rays<1>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else if ( cullMode == RTE_CULL_BACK )
  {
    RayTracingEnvironment::Trace4Rays<2>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else
  {
    RayTracingEnvironment::Trace4Rays<0>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00642290
// Name: public: void RayTracingEnvironment::CalculateTriangleListBounds(int const __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::CalculateTriangleListBounds(
        RayTracingEnvironment *this,
        const int *tris,
        int ntris,
        Vector *minout,
        Vector *maxout)
{
  int v7; // ecx
  float *p_m_flNz; // eax
  float x; // xmm0_4
  float v10; // xmm0_4
  float y; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // xmm0_4
  int i; // [esp+10h] [ebp+10h]

  minout->x = 9.9999998e22;
  minout->y = 9.9999998e22;
  minout->z = 9.9999998e22;
  maxout->x = -9.9999998e22;
  maxout->y = -9.9999998e22;
  maxout->z = -9.9999998e22;
  for ( i = 0; i < ntris; ++i )
  {
    v7 = 3;
    p_m_flNz = &this->OptimizedTriangleList.m_Memory.m_pMemory[tris[i] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                           + 2) >> 27)][tris[i]
                                                                                      & ((32
                                                                                        * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                          + 2)) >> 5)].m_Data.m_IntersectData.m_flNz;
    do
    {
      x = minout->x;
      if ( *(p_m_flNz - 1) <= minout->x )
        x = *(p_m_flNz - 1);
      minout->x = x;
      v10 = maxout->x;
      if ( maxout->x <= *(p_m_flNz - 1) )
        v10 = *(p_m_flNz - 1);
      maxout->x = v10;
      y = minout->y;
      if ( *p_m_flNz <= y )
        y = *p_m_flNz;
      minout->y = y;
      v12 = maxout->y;
      if ( v12 <= *p_m_flNz )
        v12 = *p_m_flNz;
      maxout->y = v12;
      z = minout->z;
      if ( p_m_flNz[1] <= z )
        z = p_m_flNz[1];
      minout->z = z;
      v14 = maxout->z;
      if ( v14 <= p_m_flNz[1] )
        v14 = p_m_flNz[1];
      p_m_flNz += 3;
      --v7;
      maxout->z = v14;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x006423C0
// Name: public: float RayTracingEnvironment::CalculateCostsOfSplit(int,int const __near *,int,class Vector,class Vector,float __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall RayTracingEnvironment::CalculateCostsOfSplit(
        RayTracingEnvironment *this,
        int split_plane,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        float *split_value,
        int *nleft,
        int *nright,
        int *nboth)
{
  int *v10; // eax
  int *v11; // edx
  float v12; // xmm5_4
  float v13; // xmm4_4
  int *v14; // ebx
  int v16; // ecx
  CacheOptimizedTriangle *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  int v25; // xmm0_4
  double v26; // st7
  Vector RightMins; // [esp+0h] [ebp-1Ch]
  Vector LeftMaxes; // [esp+Ch] [ebp-10h]
  int t; // [esp+18h] [ebp-4h]
  float ISA; // [esp+4Ch] [ebp+30h]

  v10 = nleft;
  v11 = nright;
  v12 = 9.9999998e22;
  v13 = -9.9999998e22;
  v14 = nboth;
  v16 = 0;
  *nleft = 0;
  *nright = 0;
  *nboth = 0;
  t = 0;
  if ( ntris > 0 )
  {
    while ( 1 )
    {
      v17 = &this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                              + 2) >> 27)][tri_list[v16]
                                                                                         & ((32
                                                                                           * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                             + 2)) >> 5)];
      v18 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v18 <= v12 )
        v12 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v13 <= v18 )
        v13 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      v19 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v19 <= v12 )
        v12 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v13 <= v19 )
        v13 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v20 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v20 <= v12 )
        v12 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v13 <= v20 )
        v13 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      v21 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v22 = *split_value;
      v23 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v21 <= v18 )
        v18 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v23 <= v21 )
        v23 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v24 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v24 <= v18 )
        v18 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v23 <= v24 )
        v23 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v18 >= v22 )
        break;
      if ( v22 >= v23 )
      {
        v10 = nleft;
        ++*nleft;
        v11 = nright;
        v17->m_Data.m_GeometryData.m_nTmpData0 = -1;
        goto LABEL_28;
      }
      if ( v18 == v23 )
        break;
      v14 = nboth;
      ++*nboth;
      v10 = nleft;
      v11 = nright;
      v17->m_Data.m_GeometryData.m_nTmpData0 = 0;
LABEL_29:
      v16 = t + 1;
      t = v16;
      if ( v16 >= ntris )
        goto LABEL_30;
    }
    v11 = nright;
    ++*nright;
    v10 = nleft;
    v17->m_Data.m_GeometryData.m_nTmpData0 = 1;
LABEL_28:
    v14 = nboth;
    goto LABEL_29;
  }
LABEL_30:
  if ( *v10 == 0 || *v14 != 0 )
  {
LABEL_34:
    if ( *v11 == 0 )
      goto LABEL_38;
    goto LABEL_35;
  }
  if ( *v11 == 0 )
  {
    *split_value = v13;
    goto LABEL_34;
  }
LABEL_35:
  if ( *v14 == 0 && *v10 == 0 )
    *split_value = v12;
LABEL_38:
  LeftMaxes = MaxBound;
  RightMins = MinBound;
  v25 = *(_DWORD *)split_value;
  *(&LeftMaxes.x + split_plane) = *split_value;
  v26 = LeftMaxes.x - MinBound.x;
  *((_DWORD *)&RightMins.x + split_plane) = v25;
  ISA = 1.0
      / (float)((float)((float)((float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.x - MinBound.x))
                              + (float)((float)(MaxBound.y - MinBound.y) * (float)(MaxBound.x - MinBound.x)))
                      + (float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.y - MinBound.y)))
              * 2.0);
  return (((MaxBound.y - RightMins.y) * (MaxBound.z - RightMins.z)
         + (MaxBound.x - RightMins.x) * (MaxBound.y - RightMins.y)
         + (MaxBound.z - RightMins.z) * (MaxBound.x - RightMins.x))
        * 2.0
        * ISA
        * (double)*v11
        + ((LeftMaxes.y - MinBound.y) * (LeftMaxes.z - MinBound.z)
         + (LeftMaxes.z - MinBound.z) * v26
         + v26 * (LeftMaxes.y - MinBound.y))
        * 2.0
        * ISA
        * (double)*v10
        + (double)*v14)
       * 167.0
       + 75.0;
}

//------------------------------------------------------------------------------
// Address: 0x006427B0
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int16 *)&s,
          inputBuffer: (unsigned __int16 *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00642850
// Name: public: void RayTracingSerializationHeader::Put(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingSerializationHeader::Put(RayTracingSerializationHeader *this, CUtlBuffer *outbuf)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  unsigned int src; // [esp+4h] [ebp-10h]
  unsigned int srca; // [esp+4h] [ebp-10h]
  unsigned int srcb; // [esp+4h] [ebp-10h]
  unsigned int srcc; // [esp+4h] [ebp-10h]
  unsigned int srcd; // [esp+4h] [ebp-10h]
  unsigned int srce; // [esp+4h] [ebp-10h]

  src = this->m_nVersionNumber;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%d", src);
  else
    CUtlBuffer::PutTypeBin<int>(this: outbuf, src);
  srca = this->m_nSerializationFlags;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%d", srca);
  else
    CUtlBuffer::PutTypeBin<int>(this: outbuf, src: srca);
  srcb = this->m_nNumKDNodes;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%d", srcb);
  else
    CUtlBuffer::PutTypeBin<int>(this: outbuf, src: srcb);
  srcc = this->m_nNumTriangles;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%d", srcc);
  else
    CUtlBuffer::PutTypeBin<int>(this: outbuf, src: srcc);
  srcd = this->m_nNumTriangleIndices;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%d", srcd);
  else
    CUtlBuffer::PutTypeBin<int>(this: outbuf, src: srcd);
  srce = this->m_nNumColors;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%d", srce);
  else
    CUtlBuffer::PutTypeBin<int>(this: outbuf, src: srce);
  x = this->m_vMinBound.x;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%f", x);
  else
    CUtlBuffer::PutTypeBin<float>(this: outbuf, src: x);
  y = this->m_vMinBound.y;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%f", y);
  else
    CUtlBuffer::PutTypeBin<float>(this: outbuf, src: y);
  z = this->m_vMinBound.z;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%f", z);
  else
    CUtlBuffer::PutTypeBin<float>(this: outbuf, src: z);
  v6 = this->m_vMaxBound.x;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%f", v6);
  else
    CUtlBuffer::PutTypeBin<float>(this: outbuf, src: v6);
  v7 = this->m_vMaxBound.y;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%f", v7);
  else
    CUtlBuffer::PutTypeBin<float>(this: outbuf, src: v7);
  v8 = this->m_vMaxBound.z;
  if ( (outbuf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outbuf, pFmt: "%f", v8);
  else
    CUtlBuffer::PutTypeBin<float>(this: outbuf, src: v8);
}

//------------------------------------------------------------------------------
// Address: 0x00642A60
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color,
        unsigned __int16 flags,
        int materialIndex)
{
  float y; // xmm0_4
  int m_Size; // eax
  int m_nAllocationCount; // eax
  int v12; // edi
  int *m_pMemory; // ecx
  int v14; // eax
  int *v15; // eax
  CacheOptimizedTriangle tmptri; // [esp+0h] [ebp-30h] BYREF

  tmptri.m_Data.m_GeometryData.m_nTriangleID = id;
  *(Vector *)tmptri.m_Data.m_GeometryData.m_VertexCoordData = *v1;
  *(Vector *)&tmptri.m_Data.m_GeometryData.m_VertexCoordData[3] = *v2;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v3->x;
  y = v3->y;
  tmptri.m_Data.m_GeometryData.m_nFlags = flags;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = y;
  m_Size = this->OptimizedTriangleList.m_Size;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = v3->z;
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
    this: &this->OptimizedTriangleList,
    elem: m_Size,
    src: &tmptri);
  if ( (this->Flags & 2) == 0 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->TriangleColors,
      elem: this->TriangleColors.m_Size,
      src: (const CVTFTexture::ResourceMemorySection *)color);
  if ( (this->Flags & 4) == 0 )
  {
    m_nAllocationCount = this->TriangleMaterials.m_Memory.m_nAllocationCount;
    v12 = this->TriangleMaterials.m_Size;
    if ( v12 + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->TriangleMaterials,
        num: v12 - m_nAllocationCount + 1);
    ++this->TriangleMaterials.m_Size;
    m_pMemory = this->TriangleMaterials.m_Memory.m_pMemory;
    v14 = this->TriangleMaterials.m_Size - v12 - 1;
    this->TriangleMaterials.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
    v15 = &this->TriangleMaterials.m_Memory.m_pMemory[v12];
    if ( v15 != nullptr )
      *v15 = materialIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00642B80
// Name: public: void RayTracingEnvironment::RefineNode(int,int const __near *,int,class Vector,class Vector,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::RefineNode(
        RayTracingEnvironment *this,
        int node_number,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        int depth)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // edi
  float v14; // xmm6_4
  int v15; // edi
  int v16; // eax
  float v17; // xmm0_4
  bool v18; // cc
  double v19; // st7
  int v20; // edx
  int v21; // ecx
  CacheOptimizedTriangle *v22; // eax
  int *v23; // eax
  int v24; // edx
  int v25; // ecx
  float v26; // xmm0_4
  int v27; // edx
  char m_nTmpData1; // al
  float v29; // eax
  float v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  CacheOptimizedKDNode *v34; // eax
  const int *v35; // ecx
  int v36; // eax
  CacheOptimizedKDNode *v37; // edx
  int v38; // eax
  float *p_Children; // ecx
  const int *v40; // ecx
  int v41; // eax
  CacheOptimizedKDNode *v42; // edx
  int v43; // eax
  float *v44; // ecx
  int *v45; // ebx
  int v46; // edi
  int v47; // edi
  int v48; // eax
  int *v49; // ecx
  int v50; // eax
  int *v51; // edi
  Vector RightMins; // [esp+24h] [ebp-50h]
  Vector LeftMaxes; // [esp+30h] [ebp-44h]
  int *new_triangle_list; // [esp+3Ch] [ebp-38h]
  int right_child; // [esp+40h] [ebp-34h] BYREF
  int trial_nright; // [esp+44h] [ebp-30h] BYREF
  int trial_nleft; // [esp+48h] [ebp-2Ch] BYREF
  int trial_cost; // [esp+4Ch] [ebp-28h]
  float best_splitvalue; // [esp+50h] [ebp-24h]
  float best_cost; // [esp+54h] [ebp-20h]
  int best_nright; // [esp+58h] [ebp-1Ch]
  int best_nboth; // [esp+5Ch] [ebp-18h]
  int split_plane; // [esp+60h] [ebp-14h]
  int tv; // [esp+64h] [ebp-10h]
  float trial_splitvalue; // [esp+68h] [ebp-Ch] BYREF
  int best_nleft; // [esp+6Ch] [ebp-8h]
  int ts; // [esp+70h] [ebp-4h]
  const int *tri_lista; // [esp+80h] [ebp+Ch]
  const int *tri_listb; // [esp+80h] [ebp+Ch]
  int left_child; // [esp+84h] [ebp+10h]
  int *left_childa; // [esp+84h] [ebp+10h]
  int left_childb; // [esp+84h] [ebp+10h]
  Vector RightMaxes; // 0:^40.12
  Vector LeftMins; // 0:^4C.12

  if ( ntris < 3 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      m_Size = this->TriangleIndexList.m_Size;
      m_nAllocationCount = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->TriangleIndexList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->TriangleIndexList.m_Size;
      m_pMemory = this->TriangleIndexList.m_Memory.m_pMemory;
      v12 = this->TriangleIndexList.m_Size - m_Size - 1;
      this->TriangleIndexList.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &this->TriangleIndexList.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = tri_list[depth];
    }
    return;
  }
  v14 = 9.9999998e22;
  v15 = 0;
  best_cost = 9.9999998e22;
  best_nleft = 0;
  best_nright = 0;
  best_nboth = 0;
  best_splitvalue = 0.0;
  split_plane = 0;
  new_triangle_list = (int *)(ntris / 10 + 1);
  left_child = 0;
  do
  {
    v16 = -1;
    ts = -1;
    if ( ntris <= -1 )
      goto LABEL_30;
    while ( 2 )
    {
      tv = 0;
      while ( 1 )
      {
        if ( v16 == -1 )
        {
          trial_splitvalue = (float)(*(&MinBound.x + v15) + *(&MaxBound.x + v15)) * 0.5;
          goto LABEL_21;
        }
        v17 = *(&this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                                  + 2) >> 27)]->m_Data.m_IntersectData.m_flNy
              + 8 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 4 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 2 * tv
              + tv
              + left_child);
        v18 = v17 <= *(&MaxBound.x + left_child);
        trial_splitvalue = v17;
        if ( v18 && *(&MinBound.x + left_child) <= v17 )
          break;
        v15 = left_child;
LABEL_28:
        ++tv;
        v16 = ts;
        if ( tv >= 3 )
          goto LABEL_29;
      }
      v15 = left_child;
LABEL_21:
      v19 = RayTracingEnvironment::CalculateCostsOfSplit(
              this,
              split_plane: v15,
              tri_list,
              ntris,
              MinBound,
              MaxBound,
              split_value: &trial_splitvalue,
              nleft: &trial_nleft,
              nright: &trial_nright,
              nboth: &right_child);
      *(float *)&trial_cost = v19;
      if ( best_cost > v19 )
      {
        v14 = *(float *)&trial_cost;
        best_nright = trial_nright;
        v20 = 0;
        split_plane = v15;
        best_cost = *(float *)&trial_cost;
        best_nleft = trial_nleft;
        best_nboth = right_child;
        best_splitvalue = trial_splitvalue;
        if ( ntris > 0 )
        {
          do
          {
            v21 = *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2);
            trial_cost = tri_list[v20];
            v22 = &this->OptimizedTriangleList.m_Memory.m_pMemory[trial_cost >> (v21 >> 27)][trial_cost
                                                                                           & ((32 * v21) >> 5)];
            ++v20;
            v22->m_Data.m_GeometryData.m_nTmpData1 = v22->m_Data.m_GeometryData.m_nTmpData0;
          }
          while ( v20 < ntris );
          v15 = left_child;
        }
      }
      v16 = ts;
      if ( ts != -1 )
        goto LABEL_28;
LABEL_29:
      ts = (int)new_triangle_list + v16;
      if ( (int)new_triangle_list + v16 < ntris )
      {
        v16 = ts;
        continue;
      }
      break;
    }
LABEL_30:
    left_child = ++v15;
  }
  while ( v15 < 3 );
  if ( v14 >= (float)(167 * ntris) || depth > 21 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      v47 = this->TriangleIndexList.m_Size;
      v48 = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( v47 + 1 > v48 )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->TriangleIndexList,
          num: v47 - v48 + 1);
      ++this->TriangleIndexList.m_Size;
      v49 = this->TriangleIndexList.m_Memory.m_pMemory;
      v50 = this->TriangleIndexList.m_Size - v47 - 1;
      this->TriangleIndexList.m_pElements = v49;
      if ( v50 > 0 )
        _V_memmove(dest: &v49[v47 + 1], src: &v49[v47], count: 4 * v50);
      v51 = &this->TriangleIndexList.m_Memory.m_pMemory[v47];
      if ( v51 != nullptr )
        *v51 = tri_list[depth];
    }
  }
  else
  {
    *(float *)&v23 = COERCE_FLOAT(MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)ntris >> 30 != 0 ? -1 : 4 * ntris));
    LeftMaxes = MaxBound;
    RightMins = MinBound;
    LeftMins = MinBound;
    RightMaxes = MaxBound;
    v24 = split_plane;
    v25 = 0;
    v26 = best_splitvalue;
    new_triangle_list = v23;
    *(&LeftMaxes.x + split_plane) = best_splitvalue;
    *(&RightMins.x + v24) = v26;
    tv = 0;
    if ( ntris > 0 )
    {
      best_cost = *(float *)&v23;
      LODWORD(best_splitvalue) = &v23[best_nleft];
      left_childa = &v23[ntris];
      do
      {
        v27 = tri_list[v25];
        m_nTmpData1 = this->OptimizedTriangleList.m_Memory.m_pMemory[v27 >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                             + 2) >> 27)][v27
                                                                                        & ((32
                                                                                          * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                            + 2)) >> 5)].m_Data.m_GeometryData.m_nTmpData1;
        if ( m_nTmpData1 == -1 )
        {
          v30 = best_cost;
          *(_DWORD *)LODWORD(best_cost) = v27;
          LODWORD(best_cost) = LODWORD(v30) + 4;
        }
        else if ( m_nTmpData1 != 0 )
        {
          if ( m_nTmpData1 == 1 )
            *--left_childa = v27;
        }
        else
        {
          v29 = best_splitvalue;
          *(_DWORD *)LODWORD(best_splitvalue) = v27;
          LODWORD(best_splitvalue) = LODWORD(v29) + 4;
        }
        v25 = tv + 1;
        tv = v25;
      }
      while ( v25 < ntris );
      v24 = split_plane;
    }
    v31 = this->OptimizedKDTree.m_Size;
    v32 = v31 + 1;
    v33 = v24 + 4 * v31;
    left_childb = v31;
    v34 = this->OptimizedKDTree.m_Memory.m_pMemory;
    right_child = v32;
    v34[node_number].Children = v33;
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue = v26;
    v36 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_lista = (const int *)this->OptimizedKDTree.m_Size;
    v35 = tri_lista;
    if ( (int)tri_lista + 1 > v36 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(
        this: (CUtlMemory<ResourceEntryInfo,int> *)&this->OptimizedKDTree,
        num: (int)tri_lista - v36 + 1);
      v35 = tri_lista;
    }
    ++this->OptimizedKDTree.m_Size;
    v37 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v38 = this->OptimizedKDTree.m_Size - (_DWORD)v35 - 1;
    this->OptimizedKDTree.m_pElements = v37;
    if ( v38 > 0 )
    {
      _V_memmove(dest: &v37[(int)v35 + 1], src: &v37[(_DWORD)v35], count: 8 * v38);
      v35 = tri_lista;
    }
    p_Children = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v35].Children;
    if ( p_Children != nullptr )
    {
      *p_Children = MinBound.y;
      p_Children[1] = MinBound.z;
    }
    v41 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_listb = (const int *)this->OptimizedKDTree.m_Size;
    v40 = tri_listb;
    if ( (int)tri_listb + 1 > v41 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(
        this: (CUtlMemory<ResourceEntryInfo,int> *)&this->OptimizedKDTree,
        num: (int)tri_listb - v41 + 1);
      v40 = tri_listb;
    }
    ++this->OptimizedKDTree.m_Size;
    v42 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v43 = this->OptimizedKDTree.m_Size - (_DWORD)v40 - 1;
    this->OptimizedKDTree.m_pElements = v42;
    if ( v43 > 0 )
    {
      _V_memmove(dest: &v42[(int)v40 + 1], src: &v42[(_DWORD)v40], count: 8 * v43);
      v40 = tri_listb;
    }
    v44 = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v40].Children;
    if ( v44 != nullptr )
    {
      *v44 = MinBound.y;
      v44[1] = MinBound.z;
    }
    if ( ntris < 20 && (best_nleft == 0 || best_nright == 0) )
      depth += 100;
    v45 = new_triangle_list;
    v46 = depth + 1;
    RayTracingEnvironment::RefineNode(
      this,
      node_number: left_childb,
      tri_list: new_triangle_list,
      ntris: best_nleft + best_nboth,
      MinBound: LeftMins,
      MaxBound: LeftMaxes,
      depth: depth + 1);
    RayTracingEnvironment::RefineNode(
      this,
      node_number: right_child,
      tri_list: &v45[best_nleft],
      ntris: best_nright + best_nboth,
      MinBound: RightMins,
      MaxBound: RightMaxes,
      depth: v46);
    free(pMem: v45);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00643140
// Name: public: void RayTracingEnvironment::SetupAccelerationStructure(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::SetupAccelerationStructure(RayTracingEnvironment *this)
{
  int *v2; // edi
  int i; // eax
  int j; // edi
  CacheOptimizedKDNode root; // [esp+Ch] [ebp-8h] BYREF

  CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int>>::InsertBefore(
    this: &this->OptimizedKDTree,
    elem: this->OptimizedKDTree.m_Size,
    src: &root);
  v2 = (int *)MemAlloc_Alloc(
                nSize: (unsigned __int64)(unsigned int)this->OptimizedTriangleList.m_Size >> 30 != 0
              ? -1
              : 4 * this->OptimizedTriangleList.m_Size);
  for ( i = 0; i < this->OptimizedTriangleList.m_Size; ++i )
    v2[i] = i;
  RayTracingEnvironment::CalculateTriangleListBounds(
    this,
    tris: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    minout: &this->m_MinBound,
    maxout: &this->m_MaxBound);
  RayTracingEnvironment::RefineNode(
    this,
    node_number: 0,
    tri_list: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    MinBound: this->m_MinBound,
    MaxBound: this->m_MaxBound,
    depth: 0);
  free(pMem: v2);
  for ( j = 0; j < this->OptimizedTriangleList.m_Size; ++j )
    CacheOptimizedTriangle::ChangeIntoIntersectionFormat(this: &this->OptimizedTriangleList.m_Memory.m_pMemory[j >> (*((int *)&this->OptimizedTriangleList.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5)]);
}

//------------------------------------------------------------------------------
// Address: 0x00643220
// Name: public: void RayTracingEnvironment::Serialize(class CUtlBuffer __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::Serialize(
        RayTracingEnvironment *this,
        float outbuf,
        signed int nSerializationFlags)
{
  unsigned int m_Size; // ecx
  unsigned int v5; // edx
  unsigned int v6; // ecx
  unsigned int v7; // eax
  CUtlBuffer *v8; // esi
  float z; // xmm0_4
  bool v10; // cc
  CacheOptimizedKDNode *m_pMemory; // eax
  int Children; // edi
  CacheOptimizedKDNode *v13; // ebx
  CUtlBuffer *SplittingPlaneValue_low; // ebx
  bool v15; // zf
  float SplittingPlaneValue; // xmm0_4
  RayTracingEnvironment *v17; // edi
  int v18; // edx
  int v19; // edi
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float *v25; // ebx
  float v26; // xmm0_4
  unsigned __int8 *v27; // eax
  unsigned __int8 v28; // bl
  unsigned __int8 v29; // bl
  unsigned __int8 v30; // bl
  int v31; // edi
  CUtlBuffer *v32; // ebx
  int v33; // eax
  signed int *v34; // eax
  float *v35; // ebx
  float v36; // xmm0_4
  unsigned __int8 *v37; // eax
  float v38; // xmm0_4
  float *v39; // eax
  float v40; // xmm0_4
  int *v41; // eax
  RayTracingSerializationHeader hdr; // [esp+14h] [ebp-6Ch] BYREF
  float v43; // [esp+44h] [ebp-3Ch]
  float v44; // [esp+48h] [ebp-38h]
  float v45; // [esp+4Ch] [ebp-34h]
  float v46; // [esp+50h] [ebp-30h] BYREF
  float v47; // [esp+54h] [ebp-2Ch]
  float v48; // [esp+58h] [ebp-28h] BYREF
  float v49; // [esp+5Ch] [ebp-24h]
  float v50; // [esp+60h] [ebp-20h] BYREF
  int inputBuffer; // [esp+64h] [ebp-1Ch] BYREF
  int i; // [esp+68h] [ebp-18h]
  int v53; // [esp+6Ch] [ebp-14h] BYREF
  float v54; // [esp+70h] [ebp-10h] BYREF
  float v55; // [esp+74h] [ebp-Ch] BYREF
  float src; // [esp+78h] [ebp-8h] BYREF
  RayTracingEnvironment *v57; // [esp+7Ch] [ebp-4h]

  m_Size = this->OptimizedKDTree.m_Size;
  v5 = this->OptimizedTriangleList.m_Size;
  hdr.m_nSerializationFlags = nSerializationFlags;
  hdr.m_nNumKDNodes = m_Size;
  v6 = this->TriangleIndexList.m_Size;
  v57 = this;
  hdr.m_nVersionNumber = 1;
  hdr.m_nNumTriangles = v5;
  hdr.m_nNumTriangleIndices = v6;
  LODWORD(v43) = nSerializationFlags & 1;
  if ( (nSerializationFlags & 1) != 0 )
    v7 = this->TriangleColors.m_Size;
  else
    v7 = 0;
  v8 = (CUtlBuffer *)LODWORD(outbuf);
  hdr.m_vMinBound = this->m_MinBound;
  hdr.m_vMaxBound.x = this->m_MaxBound.x;
  hdr.m_vMaxBound.y = this->m_MaxBound.y;
  z = this->m_MaxBound.z;
  hdr.m_nNumColors = v7;
  hdr.m_vMaxBound.z = z;
  RayTracingSerializationHeader::Put(this: &hdr, outbuf: (CUtlBuffer *)LODWORD(outbuf));
  v10 = this->OptimizedKDTree.m_Size <= 0;
  nSerializationFlags = 0;
  if ( !v10 )
  {
    do
    {
      m_pMemory = v57->OptimizedKDTree.m_Memory.m_pMemory;
      Children = m_pMemory[nSerializationFlags].Children;
      v13 = &m_pMemory[nSerializationFlags];
      if ( (v8->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v8, pFmt: "%d", m_pMemory[nSerializationFlags].Children);
      }
      else
      {
        outbuf = *(float *)&m_pMemory[nSerializationFlags].Children;
        if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
        {
          if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: &v8->m_Byteswap,
              outputBuffer: (unsigned int *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset],
              inputBuffer: (unsigned int *)&outbuf,
              count: 1);
          else
            *(_DWORD *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = Children;
          v8->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
        }
      }
      if ( (v13->Children & 3) == 3 )
      {
        SplittingPlaneValue_low = (CUtlBuffer *)LODWORD(v13->SplittingPlaneValue);
        if ( (v8->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v8, pFmt: "%d", SplittingPlaneValue_low);
          goto LABEL_26;
        }
        outbuf = *(float *)&SplittingPlaneValue_low;
        if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
        {
          if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: &v8->m_Byteswap,
              outputBuffer: (unsigned int *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset],
              inputBuffer: (unsigned int *)&outbuf,
              count: 1);
          else
            *(_DWORD *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = SplittingPlaneValue_low;
LABEL_17:
          v8->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
        }
      }
      else
      {
        v15 = (v8->m_Flags & 1) == 0;
        SplittingPlaneValue = v13->SplittingPlaneValue;
        i = LODWORD(SplittingPlaneValue);
        if ( !v15 )
        {
          CUtlBuffer::Printf(this: v8, pFmt: "%f", SplittingPlaneValue);
          goto LABEL_26;
        }
        inputBuffer = LODWORD(SplittingPlaneValue);
        if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
        {
          if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<float>(
              this: &v8->m_Byteswap,
              outputBuffer: (float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset],
              (float *)&inputBuffer,
              count: 1);
          else
            *(_DWORD *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = i;
          goto LABEL_17;
        }
      }
LABEL_26:
      ++nSerializationFlags;
    }
    while ( nSerializationFlags < v57->OptimizedKDTree.m_Size );
  }
  v17 = v57;
  v18 = 0;
  v53 = 0;
  if ( v57->OptimizedTriangleList.m_Size <= 0 )
    goto LABEL_95;
  while ( 2 )
  {
    v19 = (int)&v17->OptimizedTriangleList.m_Memory.m_pMemory[v18 >> (*((int *)&v17->OptimizedTriangleList.m_Memory + 2) >> 27)][v18 & ((32 * *((_DWORD *)&v17->OptimizedTriangleList.m_Memory + 2)) >> 5)];
    v15 = (v8->m_Flags & 1) == 0;
    v20 = *(float *)v19;
    v54 = *(float *)v19;
    if ( v15 )
    {
      inputBuffer = LODWORD(v20);
      if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
      {
        if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: &v8->m_Byteswap,
            outputBuffer: (float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset],
            (float *)&inputBuffer,
            count: 1);
        else
          *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v54;
        v8->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
      }
    }
    else
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%f", v20);
    }
    v15 = (v8->m_Flags & 1) == 0;
    v21 = *(float *)(v19 + 4);
    src = v21;
    if ( v15 )
    {
      v55 = v21;
      if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
      {
        if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: &v8->m_Byteswap,
            outputBuffer: (float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset],
            inputBuffer: &v55,
            count: 1);
        else
          *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = src;
        v8->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
      }
    }
    else
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%f", v21);
    }
    v15 = (v8->m_Flags & 1) == 0;
    v22 = *(float *)(v19 + 8);
    v49 = v22;
    if ( v15 )
    {
      v50 = v22;
      if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
      {
        if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: &v8->m_Byteswap,
            outputBuffer: (float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset],
            inputBuffer: &v50,
            count: 1);
        else
          *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v49;
        v8->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
      }
    }
    else
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%f", v22);
    }
    v15 = (v8->m_Flags & 1) == 0;
    v23 = *(float *)(v19 + 12);
    v47 = v23;
    if ( v15 )
    {
      v48 = v23;
      if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
      {
        if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: &v8->m_Byteswap,
            outputBuffer: (float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset],
            inputBuffer: &v48,
            count: 1);
        else
          *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v47;
        v8->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
      }
    }
    else
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%f", v23);
    }
    v15 = (v8->m_Flags & 1) == 0;
    v24 = (float)*(int *)(v19 + 16);
    v45 = v24;
    if ( v15 )
    {
      v46 = v24;
      if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
      {
        if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: &v8->m_Byteswap,
            outputBuffer: (float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset],
            inputBuffer: &v46,
            count: 1);
        else
          *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v45;
        v8->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
      }
    }
    else
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%f", v24);
    }
    v25 = (float *)(v19 + 20);
    for ( i = 6; i != 0; --i )
    {
      v15 = (v8->m_Flags & 1) == 0;
      v26 = *v25;
      v44 = *v25;
      if ( v15 )
      {
        outbuf = v26;
        if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) == 0 )
          goto LABEL_77;
        if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
        {
          v27 = &v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset];
          if ( v27 != nullptr )
          {
            if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
            {
              LOBYTE(nSerializationFlags) = HIBYTE(outbuf);
              BYTE2(nSerializationFlags) = BYTE1(outbuf);
              HIBYTE(nSerializationFlags) = LOBYTE(outbuf);
              BYTE1(nSerializationFlags) = BYTE2(outbuf);
              _V_memcpy(dest: v27, src: &nSerializationFlags, count: 4);
              v8->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
              goto LABEL_77;
            }
            if ( v27 != (unsigned __int8 *)&outbuf )
            {
              *(float *)v27 = outbuf;
              v8->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
              goto LABEL_77;
            }
          }
        }
        else
        {
          *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v44;
        }
        v8->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
      }
      else
      {
        CUtlBuffer::Printf(this: v8, pFmt: "%f", v26);
      }
LABEL_77:
      ++v25;
    }
    v28 = *(_BYTE *)(v19 + 44);
    if ( (v8->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%hu", v28);
    }
    else if ( CUtlBuffer::CheckPut(this: v8, nSize: 1) != 0 )
    {
      v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v28;
      CUtlBuffer::AddNullTermination(this: v8, nPut: ++v8->m_Put);
    }
    v29 = *(_BYTE *)(v19 + 45);
    if ( (v8->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%hu", v29);
    }
    else if ( CUtlBuffer::CheckPut(this: v8, nSize: 1) != 0 )
    {
      v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v29;
      CUtlBuffer::AddNullTermination(this: v8, nPut: ++v8->m_Put);
    }
    v30 = *(_BYTE *)(v19 + 46);
    if ( (v8->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%hu", v30);
    }
    else if ( CUtlBuffer::CheckPut(this: v8, nSize: 1) != 0 )
    {
      v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v30;
      CUtlBuffer::AddNullTermination(this: v8, nPut: ++v8->m_Put);
    }
    if ( (v8->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v8, pFmt: "%hu", 0);
    }
    else if ( CUtlBuffer::CheckPut(this: v8, nSize: 1) != 0 )
    {
      v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: v8, nPut: ++v8->m_Put);
    }
    if ( ++v53 < v57->OptimizedTriangleList.m_Size )
    {
      v18 = v53;
      v17 = v57;
      continue;
    }
    break;
  }
LABEL_95:
  v31 = 0;
  if ( v57->TriangleIndexList.m_Size > 0 )
  {
    while ( 2 )
    {
      v15 = (v8->m_Flags & 1) == 0;
      v32 = (CUtlBuffer *)v57->TriangleIndexList.m_Memory.m_pMemory[v31];
      outbuf = *(float *)&v32;
      if ( v15 )
      {
        if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) == 0 )
          goto LABEL_107;
        v33 = v8->m_Put - v8->m_nOffset;
        if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
        {
          v34 = (signed int *)&v8->m_Memory.m_pMemory[v33];
          if ( v34 != nullptr )
          {
            if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
            {
              LOBYTE(nSerializationFlags) = HIBYTE(outbuf);
              BYTE1(nSerializationFlags) = BYTE2(outbuf);
              BYTE2(nSerializationFlags) = BYTE1(v32);
              HIBYTE(nSerializationFlags) = (_BYTE)v32;
              _V_memcpy(dest: v34, src: &nSerializationFlags, count: 4);
              v8->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
              goto LABEL_107;
            }
            if ( v34 != &nSerializationFlags )
            {
              *v34 = (signed int)v32;
              v8->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
              goto LABEL_107;
            }
          }
        }
        else
        {
          *(_DWORD *)&v8->m_Memory.m_pMemory[v33] = v32;
        }
        v8->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
      }
      else
      {
        CUtlBuffer::Printf(this: v8, pFmt: "%d", v32);
      }
LABEL_107:
      if ( ++v31 >= v57->TriangleIndexList.m_Size )
        break;
      continue;
    }
  }
  if ( v43 != 0.0 )
  {
    inputBuffer = 0;
    if ( v57->TriangleColors.m_Size > 0 )
    {
      i = 0;
      do
      {
        v35 = (float *)((char *)&v57->TriangleColors.m_Memory.m_pMemory->x + i);
        v15 = (v8->m_Flags & 1) == 0;
        v36 = *v35;
        v43 = *v35;
        if ( v15 )
        {
          outbuf = v36;
          if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) == 0 )
            goto LABEL_122;
          if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
          {
            v37 = &v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset];
            if ( v37 != nullptr )
            {
              if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
              {
                LOBYTE(nSerializationFlags) = HIBYTE(outbuf);
                BYTE2(nSerializationFlags) = BYTE1(outbuf);
                HIBYTE(nSerializationFlags) = LOBYTE(outbuf);
                BYTE1(nSerializationFlags) = BYTE2(outbuf);
                _V_memcpy(dest: v37, src: &nSerializationFlags, count: 4);
                v8->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
                goto LABEL_122;
              }
              if ( v37 != (unsigned __int8 *)&outbuf )
              {
                *(float *)v37 = outbuf;
                v8->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
                goto LABEL_122;
              }
            }
          }
          else
          {
            *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v43;
          }
          v8->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
        }
        else
        {
          CUtlBuffer::Printf(this: v8, pFmt: "%f", v36);
        }
LABEL_122:
        v15 = (v8->m_Flags & 1) == 0;
        v38 = v35[1];
        v44 = v38;
        if ( v15 )
        {
          v55 = v38;
          if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) == 0 )
            goto LABEL_133;
          if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
          {
            v39 = (float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset];
            if ( v39 != nullptr )
            {
              if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
              {
                LOBYTE(src) = HIBYTE(v55);
                BYTE2(src) = BYTE1(v55);
                HIBYTE(src) = LOBYTE(v55);
                BYTE1(src) = BYTE2(v55);
                _V_memcpy(dest: v39, &src, count: 4);
                v8->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
                goto LABEL_133;
              }
              if ( v39 != &v55 )
              {
                *v39 = v55;
                v8->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
                goto LABEL_133;
              }
            }
          }
          else
          {
            *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v44;
          }
          v8->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
        }
        else
        {
          CUtlBuffer::Printf(this: v8, pFmt: "%f", v38);
        }
LABEL_133:
        v15 = (v8->m_Flags & 1) == 0;
        v40 = v35[2];
        v45 = v40;
        if ( !v15 )
        {
          CUtlBuffer::Printf(this: v8, pFmt: "%f", v40);
          goto LABEL_144;
        }
        v53 = LODWORD(v40);
        if ( CUtlBuffer::CheckPut(this: v8, nSize: 4) != 0 )
        {
          if ( (*(_BYTE *)&v8->m_Byteswap & 1) == 0 )
          {
            *(float *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset] = v45;
LABEL_142:
            v8->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
            goto LABEL_144;
          }
          v41 = (int *)&v8->m_Memory.m_pMemory[v8->m_Put - v8->m_nOffset];
          if ( v41 == nullptr )
            goto LABEL_142;
          if ( (*(_BYTE *)&v8->m_Byteswap & 1) != 0 )
          {
            LOBYTE(v54) = HIBYTE(v53);
            BYTE2(v54) = BYTE1(v53);
            HIBYTE(v54) = v53;
            BYTE1(v54) = BYTE2(v53);
            _V_memcpy(dest: v41, src: &v54, count: 4);
            v8->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
          }
          else
          {
            if ( v41 == &v53 )
              goto LABEL_142;
            *v41 = v53;
            v8->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v8, nPut: v8->m_Put);
          }
        }
LABEL_144:
        i += 12;
        ++inputBuffer;
      }
      while ( inputBuffer < v57->TriangleColors.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00643D20
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color)
{
  RayTracingEnvironment::AddTriangle(this, id, v1, v2, v3, color, flags: 0, materialIndex: 0);
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10078510
// Name: public: int FourRays::CalculateDirectionSignMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall FourRays::CalculateDirectionSignMask(FourRays *this)
{
  int v1; // edx
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // esi
  int v7; // edx
  int result; // eax
  int v9; // esi
  int v10; // edx
  int v11; // edi
  int v12; // esi
  int v13; // edx
  int v14; // edi
  int v15; // esi
  int v16; // esi
  int v17; // edx
  int v18; // esi
  int v19; // edi
  int v20; // ecx
  int v21; // esi

  v1 = this->direction.x.m128_i32[0];
  v2 = v1 | this->direction.x.m128_i32[1];
  v3 = this->direction.x.m128_i32[2];
  v4 = v3 & this->direction.x.m128_i32[1] & v1;
  v5 = v3 | v2;
  v6 = this->direction.x.m128_i32[3];
  v7 = v6 & v4;
  if ( (v6 | v5) < 0 )
  {
    if ( v7 >= 0 )
      return -1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  v9 = this->direction.y.m128_i32[0];
  v10 = v9 | this->direction.y.m128_i32[1];
  v11 = this->direction.y.m128_i32[2];
  v12 = v11 & this->direction.y.m128_i32[1] & v9;
  v13 = v11 | v10;
  v14 = this->direction.y.m128_i32[3];
  v15 = v14 & v12;
  if ( (v14 | v13) < 0 )
  {
    if ( v15 >= 0 )
      return -1;
    result |= 2u;
  }
  v16 = this->direction.z.m128_i32[0];
  v17 = v16 | this->direction.z.m128_i32[1];
  v18 = this->direction.z.m128_i32[1] & v16;
  v19 = this->direction.z.m128_i32[2];
  v20 = this->direction.z.m128_i32[3];
  v21 = v19 & v18;
  if ( (v19 | v17 | v20) >= 0 )
    return result;
  if ( (v20 & v21) >= 0 )
    return -1;
  return result | 4;
}

//------------------------------------------------------------------------------
// Address: 0x10078590
// Name: public: void CacheOptimizedTriangle::ChangeIntoIntersectionFormat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CacheOptimizedTriangle::ChangeIntoIntersectionFormat(CacheOptimizedTriangle *this)
{
  int m_nTriangleID; // edx
  float y; // xmm2_4
  int x_low; // xmm3_4
  int v5; // edi
  float z; // xmm4_4
  int v7; // ecx
  int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  __int128 srcTri; // [esp+4h] [ebp-50h]
  __int64 srcTri_16; // [esp+14h] [ebp-40h]
  __int128 srcTri_24; // [esp+1Ch] [ebp-38h]
  __int64 v28; // [esp+30h] [ebp-24h]
  int v29; // [esp+38h] [ebp-1Ch]
  __int64 v30; // [esp+3Ch] [ebp-18h]
  int v31; // [esp+44h] [ebp-10h]
  Vector N; // [esp+48h] [ebp-Ch] BYREF

  srcTri = *(_OWORD *)&this->m_Data.m_IntersectData.m_flNx;
  m_nTriangleID = this->m_Data.m_GeometryData.m_nTriangleID;
  srcTri_16 = *(_QWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[3];
  srcTri_24 = *(_OWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[5];
  this->m_Data.m_IntersectData.m_nFlags = LODWORD(this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
  this->m_Data.m_IntersectData.m_nTriangleID = m_nTriangleID;
  N.x = (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2)))
      - (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3)));
  N.y = (float)((float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)));
  N.z = (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)));
  VectorNormalize(vec: &N);
  y = N.y;
  x_low = LODWORD(N.x);
  v5 = fabs(N.y) > fabs(N.x);
  z = N.z;
  if ( fabs(N.z) > fabs(*(&N.x + v5)) )
    v5 = 2;
  this->m_Data.m_IntersectData.m_flD = (float)((float)(*((float *)&srcTri + 2) * N.y)
                                             + (float)(*((float *)&srcTri + 1) * N.x))
                                     + (float)(*((float *)&srcTri + 3) * N.z);
  v30 = srcTri_16;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_GeometryData.m_nTriangleID = x_low;
  this->m_Data.m_IntersectData.m_flNy = y;
  N.z = *((float *)&srcTri + 3);
  this->m_Data.m_IntersectData.m_flNz = z;
  v28 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v7 = (v5 + 1) % 3;
  v8 = (v5 + 2) % 3;
  v9 = *(&N.x + v7);
  v31 = srcTri_24;
  v10 = *((float *)&v30 + v7) - v9;
  this->m_Data.m_IntersectData.m_nCoordSelect0 = v7;
  v29 = HIDWORD(srcTri_24);
  v11 = *(&N.x + v8) - *((float *)&v30 + v8);
  v12 = (float)(v9 * v11) + (float)(*(&N.x + v8) * v10);
  v13 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_nCoordSelect1 = v8;
  v14 = -v12;
  v15 = (float)((float)(v13 * v11) + (float)(*((float *)&v28 + v8) * v10)) - v12;
  if ( v15 < 0.0 )
  {
    v11 = -v11;
    v10 = -v10;
    v14 = -v14;
    v15 = -v15;
  }
  v16 = 1.0 / v15;
  v17 = (float)(1.0 / v15) * v11;
  v18 = v16;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v16 * v14;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0] = v17;
  v28 = srcTri_16;
  v29 = srcTri_24;
  v19 = *((float *)&v28 + v8);
  v20 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1] = v18 * v10;
  v30 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v31 = HIDWORD(srcTri_24);
  v21 = v19 - *((float *)&v30 + v8);
  v22 = *((float *)&v30 + v7) - v20;
  N.z = *((float *)&srcTri + 3);
  v23 = -(float)((float)(v20 * v21) + (float)(v19 * v22));
  v24 = (float)((float)(*(&N.x + v7) * v21) + (float)(*(&N.x + v8) * v22)) + v23;
  if ( v24 < 0.0 )
  {
    v21 = -v21;
    v22 = -v22;
    v23 = -v23;
    v24 = -v24;
  }
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = (float)(1.0 / v24) * v21;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = (float)(1.0 / v24) * v22;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5] = (float)(1.0 / v24) * v23;
}

//------------------------------------------------------------------------------
// Address: 0x10078880
// Name: public: void RayTracingEnvironment::Trace4Rays<1>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<1>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(Four_Zeros, v48));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078E80
// Name: public: void RayTracingEnvironment::Trace4Rays<2>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<2>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v72, value: 0xFFu, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(v48, Four_Zeros));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079480
// Name: public: void RayTracingEnvironment::Trace4Rays<0>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<0>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 *v51; // ecx
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm0
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  int (__thiscall *v64)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v65; // al
  __m128 v66; // xmm4
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm2
  _DWORD v71[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v72; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v73; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v74; // [esp-D0h] [ebp-DCh]
  __m128 v75; // [esp-C0h] [ebp-CCh]
  __m128 v76; // [esp-B0h] [ebp-BCh]
  _QWORD v77[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v78; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v79; // [esp-60h] [ebp-6Ch]
  __m128 v80; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v81; // [esp-40h] [ebp-4Ch]
  int *v82; // [esp-2Ch] [ebp-38h]
  int v83; // [esp-28h] [ebp-34h]
  int v84; // [esp-24h] [ebp-30h]
  int v85; // [esp-20h] [ebp-2Ch]
  int v86; // [esp-1Ch] [ebp-28h]
  int v87; // [esp-18h] [ebp-24h]
  int v88; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v90; // [esp-Ch] [ebp-18h]
  __m128 *v91; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v93; // [esp+0h] [ebp-Ch]
  void *v94; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v93 = a4;
  v94 = retaddr;
  v9 = alloca(41592);
  v90 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v77 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v77[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v77;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v77;
  *(__m128 *)&v77[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v79 = TMin;
  v81 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (unsigned __int8 *)v71, value: 0xFFu, count: sizeof(v71));
    if ( (a6 & 1) != 0 )
    {
      v83 = 0;
      v86 = 1;
    }
    else
    {
      v83 = 1;
      v86 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    m_pMemory = v90->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v81;
    v28 = v79;
    for ( j = (__m128 *)v71; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v91 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v90->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v77[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v83 + v31);
              v36 = *(&v86 + v31);
              v37 = v91 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v91 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v86 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v83 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v91;
        v81 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v90->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v82 )
        {
          v39 = *k;
          v82 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v90->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v90->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v90->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v71[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, a5[3]), _mm_mul_ps(a5[4], v43)), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v74 = v42;
            v47 = _mm_add_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(v42, *a5));
            v48 = _mm_mul_ps(a5[2], v44);
            v76 = v44;
            v49 = _mm_div_ps(_mm_sub_ps(_mm_shuffle_ps(m_flD_low, m_flD_low, 0), _mm_add_ps(v47, v48)), v45);
            v50 = _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v45), _mm_cmplt_ps(v45, FourNegativeEpsilons));
            v71[(unsigned __int8)v39] = v39;
            v51 = a7;
            v52 = _mm_and_ps(_mm_and_ps(v50, _mm_cmplt_ps(v26, v49)), _mm_cmplt_ps(v49, a7[4]));
            v75 = v43;
            v79 = v49;
            v80 = v52;
            if ( _mm_movemask_ps(v52) != 0 )
            {
              v53 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v56 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              v58 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v56));
              v59 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v60 = _mm_add_ps(v58, _mm_shuffle_ps(v54, v54, 0));
              v80 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v61 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v57),
                        _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v56)),
                      _mm_shuffle_ps(v59, v59, 0));
              v26 = FourZeros;
              v62 = _mm_add_ps(v61, v60);
              v73 = v60;
              v78 = v61;
              v63 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v60), v52), _mm_cmple_ps(FourZeros, v61)),
                      _mm_cmple_ps(v62, Four_Ones));
              v80 = v63;
              if ( _mm_movemask_ps(v63) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v64 = **a9;
                  v72 = _mm_sub_ps(Four_Ones, v62);
                  v65 = v64(a1: a9, a2: v40, a3: a5, a4: &v80, a5: &v78, a6: &v72, a7: &v73, a8: v39);
                  v27 = v81;
                  v49 = v79;
                  v51 = a7;
                  if ( v65 != 0 )
                  {
                    v63 = Four_Zeros;
                    v80 = Four_Zeros;
                  }
                  else
                  {
                    v63 = v80;
                  }
                }
                else
                {
                  v27 = v81;
                }
                v66 = v51[3];
                m_nCoordSelect0 = v39;
                v51[3] = _mm_or_ps(
                           _mm_andnot_ps(v63, v66),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v63));
                v67 = *v51;
                v51[4] = _mm_or_ps(_mm_andnot_ps(v63, v51[4]), _mm_and_ps(v49, v63));
                v68 = _mm_andnot_ps(v63, v67);
                v69 = v51[1];
                *v51 = _mm_or_ps(_mm_and_ps(v63, v74), v68);
                v70 = v51[2];
                v51[1] = _mm_or_ps(_mm_and_ps(v63, v75), _mm_andnot_ps(v63, v69));
                v51[2] = _mm_or_ps(_mm_and_ps(v63, v76), _mm_andnot_ps(v63, v70));
                v26 = FourZeros;
              }
              else
              {
                v27 = v81;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v91;
      }
      if ( j == (__m128 *)v71 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v81 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079A70
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        const FourRays *rays,
        char DirectionSignMask,
        RayTracingResult *rslt_out,
        int skip_id,
        ITransparentTriangleCallback *pCallback,
        RTECullMode_t cullMode)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( cullMode == RTE_CULL_FRONT )
  {
    RayTracingEnvironment::Trace4Rays<1>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else if ( cullMode == RTE_CULL_BACK )
  {
    RayTracingEnvironment::Trace4Rays<2>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else
  {
    RayTracingEnvironment::Trace4Rays<0>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079AE0
// Name: public: void RayTracingEnvironment::CalculateTriangleListBounds(int const __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::CalculateTriangleListBounds(
        RayTracingEnvironment *this,
        const int *tris,
        int ntris,
        Vector *minout,
        Vector *maxout)
{
  int v7; // ecx
  float *p_m_flNz; // eax
  float x; // xmm0_4
  float v10; // xmm0_4
  float y; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // xmm0_4
  int i; // [esp+10h] [ebp+10h]

  minout->x = 9.9999998e22;
  minout->y = 9.9999998e22;
  minout->z = 9.9999998e22;
  maxout->x = -9.9999998e22;
  maxout->y = -9.9999998e22;
  maxout->z = -9.9999998e22;
  for ( i = 0; i < ntris; ++i )
  {
    v7 = 3;
    p_m_flNz = &this->OptimizedTriangleList.m_Memory.m_pMemory[tris[i] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                           + 2) >> 27)][tris[i]
                                                                                      & ((32
                                                                                        * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                          + 2)) >> 5)].m_Data.m_IntersectData.m_flNz;
    do
    {
      x = minout->x;
      if ( *(p_m_flNz - 1) <= minout->x )
        x = *(p_m_flNz - 1);
      minout->x = x;
      v10 = maxout->x;
      if ( maxout->x <= *(p_m_flNz - 1) )
        v10 = *(p_m_flNz - 1);
      maxout->x = v10;
      y = minout->y;
      if ( *p_m_flNz <= y )
        y = *p_m_flNz;
      minout->y = y;
      v12 = maxout->y;
      if ( v12 <= *p_m_flNz )
        v12 = *p_m_flNz;
      maxout->y = v12;
      z = minout->z;
      if ( p_m_flNz[1] <= z )
        z = p_m_flNz[1];
      minout->z = z;
      v14 = maxout->z;
      if ( v14 <= p_m_flNz[1] )
        v14 = p_m_flNz[1];
      p_m_flNz += 3;
      --v7;
      maxout->z = v14;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079C10
// Name: public: float RayTracingEnvironment::CalculateCostsOfSplit(int,int const __near *,int,class Vector,class Vector,float __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall RayTracingEnvironment::CalculateCostsOfSplit(
        RayTracingEnvironment *this,
        int split_plane,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        float *split_value,
        int *nleft,
        int *nright,
        int *nboth)
{
  int *v10; // eax
  int *v11; // edx
  float v12; // xmm5_4
  float v13; // xmm4_4
  int *v14; // ebx
  int v16; // ecx
  CacheOptimizedTriangle *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  int v25; // xmm0_4
  double v26; // st7
  Vector RightMins; // [esp+0h] [ebp-1Ch]
  Vector LeftMaxes; // [esp+Ch] [ebp-10h]
  int t; // [esp+18h] [ebp-4h]
  float ISA; // [esp+4Ch] [ebp+30h]

  v10 = nleft;
  v11 = nright;
  v12 = 9.9999998e22;
  v13 = -9.9999998e22;
  v14 = nboth;
  v16 = 0;
  *nleft = 0;
  *nright = 0;
  *nboth = 0;
  t = 0;
  if ( ntris > 0 )
  {
    while ( 1 )
    {
      v17 = &this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                              + 2) >> 27)][tri_list[v16]
                                                                                         & ((32
                                                                                           * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                             + 2)) >> 5)];
      v18 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v18 <= v12 )
        v12 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v13 <= v18 )
        v13 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      v19 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v19 <= v12 )
        v12 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v13 <= v19 )
        v13 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v20 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v20 <= v12 )
        v12 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v13 <= v20 )
        v13 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      v21 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v22 = *split_value;
      v23 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v21 <= v18 )
        v18 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v23 <= v21 )
        v23 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v24 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v24 <= v18 )
        v18 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v23 <= v24 )
        v23 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v18 >= v22 )
        break;
      if ( v22 >= v23 )
      {
        v10 = nleft;
        ++*nleft;
        v11 = nright;
        v17->m_Data.m_GeometryData.m_nTmpData0 = -1;
        goto LABEL_28;
      }
      if ( v18 == v23 )
        break;
      v14 = nboth;
      ++*nboth;
      v10 = nleft;
      v11 = nright;
      v17->m_Data.m_GeometryData.m_nTmpData0 = 0;
LABEL_29:
      v16 = t + 1;
      t = v16;
      if ( v16 >= ntris )
        goto LABEL_30;
    }
    v11 = nright;
    ++*nright;
    v10 = nleft;
    v17->m_Data.m_GeometryData.m_nTmpData0 = 1;
LABEL_28:
    v14 = nboth;
    goto LABEL_29;
  }
LABEL_30:
  if ( *v10 == 0 || *v14 != 0 )
  {
LABEL_34:
    if ( *v11 == 0 )
      goto LABEL_38;
    goto LABEL_35;
  }
  if ( *v11 == 0 )
  {
    *split_value = v13;
    goto LABEL_34;
  }
LABEL_35:
  if ( *v14 == 0 && *v10 == 0 )
    *split_value = v12;
LABEL_38:
  LeftMaxes = MaxBound;
  RightMins = MinBound;
  v25 = *(_DWORD *)split_value;
  *(&LeftMaxes.x + split_plane) = *split_value;
  v26 = LeftMaxes.x - MinBound.x;
  *((_DWORD *)&RightMins.x + split_plane) = v25;
  ISA = 1.0
      / (float)((float)((float)((float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.x - MinBound.x))
                              + (float)((float)(MaxBound.y - MinBound.y) * (float)(MaxBound.x - MinBound.x)))
                      + (float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.y - MinBound.y)))
              * 2.0);
  return (((MaxBound.y - RightMins.y) * (MaxBound.z - RightMins.z)
         + (MaxBound.x - RightMins.x) * (MaxBound.y - RightMins.y)
         + (MaxBound.z - RightMins.z) * (MaxBound.x - RightMins.x))
        * 2.0
        * ISA
        * (double)*v11
        + ((LeftMaxes.y - MinBound.y) * (LeftMaxes.z - MinBound.z)
         + (LeftMaxes.z - MinBound.z) * v26
         + v26 * (LeftMaxes.y - MinBound.y))
        * 2.0
        * ISA
        * (double)*v10
        + (double)*v14)
       * 167.0
       + 75.0;
}

//------------------------------------------------------------------------------
// Address: 0x10079F90
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        int a5,
        RayTracingResult *a6,
        int a7,
        ITransparentTriangleCallback *a8,
        RTECullMode_t a9)
{
  int v10; // eax
  int v11; // edi
  int v12; // eax
  char *v13; // ecx
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  int *v20; // esi
  int v21; // xmm4_4
  int v22; // xmm3_4
  int v23; // xmm2_4
  _BYTE *v24; // eax
  char v25; // al
  int v26; // ecx
  float *m128_f32; // eax
  int v28; // esi
  double v29; // st7
  bool v30; // zf
  _DWORD v31[3]; // [esp-Ch] [ebp-11Ch] BYREF
  RayTracingResult tmpresults_4; // [esp+4h] [ebp-10Ch] OVERLAPPED
  __m128 v33; // [esp+54h] [ebp-BCh]
  _BYTE v34[96]; // [esp+64h] [ebp-ACh] OVERLAPPED BYREF
  int v35; // [esp+D0h] [ebp-40h]
  float v36; // [esp+D4h] [ebp-3Ch]
  float v37; // [esp+D8h] [ebp-38h]
  float v38; // [esp+DCh] [ebp-34h]
  char *v39; // [esp+E0h] [ebp-30h]
  int v40; // [esp+E4h] [ebp-2Ch]
  _BYTE *v41; // [esp+E8h] [ebp-28h]
  int v42; // [esp+ECh] [ebp-24h]
  int v43; // [esp+F0h] [ebp-20h]
  int v44; // [esp+F4h] [ebp-1Ch]
  int v45; // [esp+F8h] [ebp-18h]
  RayTracingEnvironment *v46; // [esp+FCh] [ebp-14h] BYREF
  int v47; // [esp+100h] [ebp-10h]
  _DWORD v48[2]; // [esp+104h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+110h] [ebp+0h]

  v48[0] = a4;
  v48[1] = retaddr;
  tmpresults_4.HitDistance = TMax;
  v33 = TMin;
  v46 = this;
  v10 = FourRays::CalculateDirectionSignMask(this: (FourRays *)a5);
  if ( v10 == -1 )
  {
    *(_OWORD *)v34 = *(_OWORD *)a5;
    *(_OWORD *)&v34[16] = *(_OWORD *)(a5 + 16);
    v11 = 1;
    v12 = a5 + 48;
    v13 = (char *)&v46 + 3;
    *(_OWORD *)&v34[32] = *(_OWORD *)(a5 + 32);
    v47 = 16843009;
    v44 = 1;
    v45 = a5 + 48;
    v39 = (char *)&v46 + 3;
    v43 = 4;
    do
    {
      if ( v13[v11] != 0 )
      {
        v14 = *(float *)v12;
        v15 = *(float *)(v12 + 16);
        v16 = *(float *)(v12 + 32);
        v17 = 0;
        v17.m128_f32[0] = *(float *)v12;
        *(__m128 *)&v34[48] = _mm_shuffle_ps(v17, v17, 0);
        v18 = 0;
        v18.m128_f32[0] = v15;
        *(__m128 *)&v34[64] = _mm_shuffle_ps(v18, v18, 0);
        v19 = 0;
        v19.m128_f32[0] = v16;
        v13[v11] = 2;
        *(__m128 *)&v34[80] = _mm_shuffle_ps(v19, v19, 0);
        if ( v11 < 4 )
        {
          v20 = (int *)(v12 + 20);
          v41 = &v34[-a5 + 16];
          do
          {
            if ( *((_BYTE *)&v48[-1] + v11) != 0 )
            {
              v21 = *(v20 - 4);
              v38 = v14;
              v40 = v21;
              if ( (((v21 < 0) ^ (unsigned __int8)~(v14 < 0.0)) & 1) != 0 )
              {
                v22 = *v20;
                v37 = v15;
                v42 = v22;
                if ( (((v22 < 0) ^ (unsigned __int8)~(v15 < 0.0)) & 1) != 0 )
                {
                  v23 = v20[4];
                  v36 = v16;
                  v35 = v23;
                  if ( (((v23 < 0) ^ (unsigned __int8)~(v16 < 0.0)) & 1) != 0 )
                  {
                    v24 = v41;
                    *((_BYTE *)&v48[-1] + v11) = 2;
                    *(_DWORD *)&v34[4 * v11 + 48] = v21;
                    *(_DWORD *)&v34[(_DWORD)v20 - a5] = v22;
                    *(int *)((char *)v20 + (_DWORD)v24) = v23;
                  }
                }
              }
            }
            ++v11;
            ++v20;
          }
          while ( v11 < 4 );
        }
        v25 = FourRays::CalculateDirectionSignMask(this: (FourRays *)v34);
        if ( a9 == RTE_CULL_FRONT )
        {
          RayTracingEnvironment::Trace4Rays<1>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        else if ( a9 == RTE_CULL_BACK )
        {
          RayTracingEnvironment::Trace4Rays<2>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        else
        {
          RayTracingEnvironment::Trace4Rays<0>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        v26 = 0;
        m128_f32 = a6->HitDistance.m128_f32;
        do
        {
          if ( *((_BYTE *)&v48[-1] + v26) == 2 )
          {
            v28 = tmpresults_4.HitIds[v26 - 4];
            *m128_f32 = *(float *)((char *)m128_f32 + (char *)v31 - (char *)a6);
            *((_BYTE *)&v48[-1] + v26) = 0;
            v29 = *(float *)&v31[v26];
            *((_DWORD *)m128_f32 - 4) = v28;
            *(m128_f32 - 16) = v29;
            *(m128_f32 - 12) = tmpresults_4.surface_normal.x.m128_f32[v26];
            *(m128_f32 - 8) = *(float *)&tmpresults_4.HitIds[v26 - 8];
          }
          ++v26;
          ++m128_f32;
        }
        while ( v26 < 4 );
        TMin = v33;
        TMax = tmpresults_4.HitDistance;
        v12 = v45;
        v11 = v44;
        v13 = v39;
      }
      v12 += 4;
      ++v11;
      v30 = v43-- == 1;
      v45 = v12;
      v44 = v11;
    }
    while ( !v30 );
  }
  else
  {
    RayTracingEnvironment::Trace4Rays(
      this,
      TMin,
      TMax,
      rays: (const FourRays *)a5,
      DirectionSignMask: v10,
      rslt_out: a6,
      skip_id: a7,
      pCallback: a8,
      cullMode: a9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A230
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color,
        unsigned __int16 flags,
        int materialIndex)
{
  float y; // xmm0_4
  int m_Size; // eax
  int m_nAllocationCount; // eax
  int v12; // edi
  int *m_pMemory; // ecx
  int v14; // eax
  int *v15; // eax
  CacheOptimizedTriangle tmptri; // [esp+0h] [ebp-30h] BYREF

  tmptri.m_Data.m_GeometryData.m_nTriangleID = id;
  *(Vector *)tmptri.m_Data.m_GeometryData.m_VertexCoordData = *v1;
  *(Vector *)&tmptri.m_Data.m_GeometryData.m_VertexCoordData[3] = *v2;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v3->x;
  y = v3->y;
  tmptri.m_Data.m_GeometryData.m_nFlags = flags;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = y;
  m_Size = this->OptimizedTriangleList.m_Size;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = v3->z;
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
    this: &this->OptimizedTriangleList,
    elem: m_Size,
    src: &tmptri);
  if ( (this->Flags & 2) == 0 )
    CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->TriangleColors,
      elem: this->TriangleColors.m_Size,
      src: (const CVTFTexture::ResourceMemorySection *)color);
  if ( (this->Flags & 4) == 0 )
  {
    m_nAllocationCount = this->TriangleMaterials.m_Memory.m_nAllocationCount;
    v12 = this->TriangleMaterials.m_Size;
    if ( v12 + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->TriangleMaterials,
        num: v12 - m_nAllocationCount + 1);
    ++this->TriangleMaterials.m_Size;
    m_pMemory = this->TriangleMaterials.m_Memory.m_pMemory;
    v14 = this->TriangleMaterials.m_Size - v12 - 1;
    this->TriangleMaterials.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
    v15 = &this->TriangleMaterials.m_Memory.m_pMemory[v12];
    if ( v15 != nullptr )
      *v15 = materialIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A350
// Name: public: void RayTracingEnvironment::RefineNode(int,int const __near *,int,class Vector,class Vector,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::RefineNode(
        RayTracingEnvironment *this,
        int node_number,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        int depth)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // edi
  float v14; // xmm6_4
  int v15; // edi
  int v16; // eax
  float v17; // xmm0_4
  bool v18; // cc
  double v19; // st7
  int v20; // edx
  int v21; // ecx
  CacheOptimizedTriangle *v22; // eax
  int *v23; // eax
  int v24; // edx
  int v25; // ecx
  float v26; // xmm0_4
  int v27; // edx
  char m_nTmpData1; // al
  float v29; // eax
  float v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  CacheOptimizedKDNode *v34; // eax
  const int *v35; // ecx
  int v36; // eax
  CacheOptimizedKDNode *v37; // edx
  int v38; // eax
  float *p_Children; // ecx
  const int *v40; // ecx
  int v41; // eax
  CacheOptimizedKDNode *v42; // edx
  int v43; // eax
  float *v44; // ecx
  int *v45; // ebx
  int v46; // edi
  int v47; // edi
  int v48; // eax
  int *v49; // ecx
  int v50; // eax
  int *v51; // edi
  Vector RightMins; // [esp+24h] [ebp-50h]
  Vector LeftMaxes; // [esp+30h] [ebp-44h]
  int *new_triangle_list; // [esp+3Ch] [ebp-38h]
  int right_child; // [esp+40h] [ebp-34h] BYREF
  int trial_nright; // [esp+44h] [ebp-30h] BYREF
  int trial_nleft; // [esp+48h] [ebp-2Ch] BYREF
  int trial_cost; // [esp+4Ch] [ebp-28h]
  float best_splitvalue; // [esp+50h] [ebp-24h]
  float best_cost; // [esp+54h] [ebp-20h]
  int best_nright; // [esp+58h] [ebp-1Ch]
  int best_nboth; // [esp+5Ch] [ebp-18h]
  int split_plane; // [esp+60h] [ebp-14h]
  int tv; // [esp+64h] [ebp-10h]
  float trial_splitvalue; // [esp+68h] [ebp-Ch] BYREF
  int best_nleft; // [esp+6Ch] [ebp-8h]
  int ts; // [esp+70h] [ebp-4h]
  const int *tri_lista; // [esp+80h] [ebp+Ch]
  const int *tri_listb; // [esp+80h] [ebp+Ch]
  int left_child; // [esp+84h] [ebp+10h]
  int *left_childa; // [esp+84h] [ebp+10h]
  int left_childb; // [esp+84h] [ebp+10h]
  Vector RightMaxes; // 0:^40.12
  Vector LeftMins; // 0:^4C.12

  if ( ntris < 3 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      m_Size = this->TriangleIndexList.m_Size;
      m_nAllocationCount = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->TriangleIndexList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->TriangleIndexList.m_Size;
      m_pMemory = this->TriangleIndexList.m_Memory.m_pMemory;
      v12 = this->TriangleIndexList.m_Size - m_Size - 1;
      this->TriangleIndexList.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &this->TriangleIndexList.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = tri_list[depth];
    }
    return;
  }
  v14 = 9.9999998e22;
  v15 = 0;
  best_cost = 9.9999998e22;
  best_nleft = 0;
  best_nright = 0;
  best_nboth = 0;
  best_splitvalue = 0.0;
  split_plane = 0;
  new_triangle_list = (int *)(ntris / 10 + 1);
  left_child = 0;
  do
  {
    v16 = -1;
    ts = -1;
    if ( ntris <= -1 )
      goto LABEL_30;
    while ( 2 )
    {
      tv = 0;
      while ( 1 )
      {
        if ( v16 == -1 )
        {
          trial_splitvalue = (float)(*(&MinBound.x + v15) + *(&MaxBound.x + v15)) * 0.5;
          goto LABEL_21;
        }
        v17 = *(&this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                                  + 2) >> 27)]->m_Data.m_IntersectData.m_flNy
              + 8 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 4 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 2 * tv
              + tv
              + left_child);
        v18 = v17 <= *(&MaxBound.x + left_child);
        trial_splitvalue = v17;
        if ( v18 && *(&MinBound.x + left_child) <= v17 )
          break;
        v15 = left_child;
LABEL_28:
        ++tv;
        v16 = ts;
        if ( tv >= 3 )
          goto LABEL_29;
      }
      v15 = left_child;
LABEL_21:
      v19 = RayTracingEnvironment::CalculateCostsOfSplit(
              this,
              split_plane: v15,
              tri_list,
              ntris,
              MinBound,
              MaxBound,
              split_value: &trial_splitvalue,
              nleft: &trial_nleft,
              nright: &trial_nright,
              nboth: &right_child);
      *(float *)&trial_cost = v19;
      if ( best_cost > v19 )
      {
        v14 = *(float *)&trial_cost;
        best_nright = trial_nright;
        v20 = 0;
        split_plane = v15;
        best_cost = *(float *)&trial_cost;
        best_nleft = trial_nleft;
        best_nboth = right_child;
        best_splitvalue = trial_splitvalue;
        if ( ntris > 0 )
        {
          do
          {
            v21 = *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2);
            trial_cost = tri_list[v20];
            v22 = &this->OptimizedTriangleList.m_Memory.m_pMemory[trial_cost >> (v21 >> 27)][trial_cost
                                                                                           & ((32 * v21) >> 5)];
            ++v20;
            v22->m_Data.m_GeometryData.m_nTmpData1 = v22->m_Data.m_GeometryData.m_nTmpData0;
          }
          while ( v20 < ntris );
          v15 = left_child;
        }
      }
      v16 = ts;
      if ( ts != -1 )
        goto LABEL_28;
LABEL_29:
      ts = (int)new_triangle_list + v16;
      if ( (int)new_triangle_list + v16 < ntris )
      {
        v16 = ts;
        continue;
      }
      break;
    }
LABEL_30:
    left_child = ++v15;
  }
  while ( v15 < 3 );
  if ( v14 >= (float)(167 * ntris) || depth > 21 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      v47 = this->TriangleIndexList.m_Size;
      v48 = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( v47 + 1 > v48 )
        CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->TriangleIndexList, num: v47 - v48 + 1);
      ++this->TriangleIndexList.m_Size;
      v49 = this->TriangleIndexList.m_Memory.m_pMemory;
      v50 = this->TriangleIndexList.m_Size - v47 - 1;
      this->TriangleIndexList.m_pElements = v49;
      if ( v50 > 0 )
        _V_memmove(dest: &v49[v47 + 1], src: &v49[v47], count: 4 * v50);
      v51 = &this->TriangleIndexList.m_Memory.m_pMemory[v47];
      if ( v51 != nullptr )
        *v51 = tri_list[depth];
    }
  }
  else
  {
    *(float *)&v23 = COERCE_FLOAT(MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)ntris >> 30 != 0 ? -1 : 4 * ntris));
    LeftMaxes = MaxBound;
    RightMins = MinBound;
    LeftMins = MinBound;
    RightMaxes = MaxBound;
    v24 = split_plane;
    v25 = 0;
    v26 = best_splitvalue;
    new_triangle_list = v23;
    *(&LeftMaxes.x + split_plane) = best_splitvalue;
    *(&RightMins.x + v24) = v26;
    tv = 0;
    if ( ntris > 0 )
    {
      best_cost = *(float *)&v23;
      LODWORD(best_splitvalue) = &v23[best_nleft];
      left_childa = &v23[ntris];
      do
      {
        v27 = tri_list[v25];
        m_nTmpData1 = this->OptimizedTriangleList.m_Memory.m_pMemory[v27 >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                             + 2) >> 27)][v27
                                                                                        & ((32
                                                                                          * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                            + 2)) >> 5)].m_Data.m_GeometryData.m_nTmpData1;
        if ( m_nTmpData1 == -1 )
        {
          v30 = best_cost;
          *(_DWORD *)LODWORD(best_cost) = v27;
          LODWORD(best_cost) = LODWORD(v30) + 4;
        }
        else if ( m_nTmpData1 != 0 )
        {
          if ( m_nTmpData1 == 1 )
            *--left_childa = v27;
        }
        else
        {
          v29 = best_splitvalue;
          *(_DWORD *)LODWORD(best_splitvalue) = v27;
          LODWORD(best_splitvalue) = LODWORD(v29) + 4;
        }
        v25 = tv + 1;
        tv = v25;
      }
      while ( v25 < ntris );
      v24 = split_plane;
    }
    v31 = this->OptimizedKDTree.m_Size;
    v32 = v31 + 1;
    v33 = v24 + 4 * v31;
    left_childb = v31;
    v34 = this->OptimizedKDTree.m_Memory.m_pMemory;
    right_child = v32;
    v34[node_number].Children = v33;
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue = v26;
    v36 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_lista = (const int *)this->OptimizedKDTree.m_Size;
    v35 = tri_lista;
    if ( (int)tri_lista + 1 > v36 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(
        this: (CUtlMemory<ResourceEntryInfo,int> *)&this->OptimizedKDTree,
        num: (int)tri_lista - v36 + 1);
      v35 = tri_lista;
    }
    ++this->OptimizedKDTree.m_Size;
    v37 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v38 = this->OptimizedKDTree.m_Size - (_DWORD)v35 - 1;
    this->OptimizedKDTree.m_pElements = v37;
    if ( v38 > 0 )
    {
      _V_memmove(dest: &v37[(int)v35 + 1], src: &v37[(_DWORD)v35], count: 8 * v38);
      v35 = tri_lista;
    }
    p_Children = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v35].Children;
    if ( p_Children != nullptr )
    {
      *p_Children = MinBound.y;
      p_Children[1] = MinBound.z;
    }
    v41 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_listb = (const int *)this->OptimizedKDTree.m_Size;
    v40 = tri_listb;
    if ( (int)tri_listb + 1 > v41 )
    {
      CUtlMemory<CacheOptimizedKDNode,int>::Grow(
        this: (CUtlMemory<ResourceEntryInfo,int> *)&this->OptimizedKDTree,
        num: (int)tri_listb - v41 + 1);
      v40 = tri_listb;
    }
    ++this->OptimizedKDTree.m_Size;
    v42 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v43 = this->OptimizedKDTree.m_Size - (_DWORD)v40 - 1;
    this->OptimizedKDTree.m_pElements = v42;
    if ( v43 > 0 )
    {
      _V_memmove(dest: &v42[(int)v40 + 1], src: &v42[(_DWORD)v40], count: 8 * v43);
      v40 = tri_listb;
    }
    v44 = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v40].Children;
    if ( v44 != nullptr )
    {
      *v44 = MinBound.y;
      v44[1] = MinBound.z;
    }
    if ( ntris < 20 && (best_nleft == 0 || best_nright == 0) )
      depth += 100;
    v45 = new_triangle_list;
    v46 = depth + 1;
    RayTracingEnvironment::RefineNode(
      this,
      node_number: left_childb,
      tri_list: new_triangle_list,
      ntris: best_nleft + best_nboth,
      MinBound: LeftMins,
      MaxBound: LeftMaxes,
      depth: depth + 1);
    RayTracingEnvironment::RefineNode(
      this,
      node_number: right_child,
      tri_list: &v45[best_nleft],
      ntris: best_nright + best_nboth,
      MinBound: RightMins,
      MaxBound: RightMaxes,
      depth: v46);
    free(pMem: v45);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A910
// Name: public: void RayTracingEnvironment::SetupAccelerationStructure(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::SetupAccelerationStructure(RayTracingEnvironment *this)
{
  int *v2; // edi
  int i; // eax
  int j; // edi
  CacheOptimizedKDNode root; // [esp+Ch] [ebp-8h] BYREF

  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)&this->OptimizedKDTree,
    elem: this->OptimizedKDTree.m_Size,
    src: (const unsigned __int64 *)&root);
  v2 = (int *)MemAlloc_Alloc(
                nSize: (unsigned __int64)(unsigned int)this->OptimizedTriangleList.m_Size >> 30 != 0
              ? -1
              : 4 * this->OptimizedTriangleList.m_Size);
  for ( i = 0; i < this->OptimizedTriangleList.m_Size; ++i )
    v2[i] = i;
  RayTracingEnvironment::CalculateTriangleListBounds(
    this,
    tris: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    minout: &this->m_MinBound,
    maxout: &this->m_MaxBound);
  RayTracingEnvironment::RefineNode(
    this,
    node_number: 0,
    tri_list: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    MinBound: this->m_MinBound,
    MaxBound: this->m_MaxBound,
    depth: 0);
  free(pMem: v2);
  for ( j = 0; j < this->OptimizedTriangleList.m_Size; ++j )
    CacheOptimizedTriangle::ChangeIntoIntersectionFormat(this: &this->OptimizedTriangleList.m_Memory.m_pMemory[j >> (*((int *)&this->OptimizedTriangleList.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5)]);
}

//------------------------------------------------------------------------------
// Address: 0x1007A9F0
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color)
{
  RayTracingEnvironment::AddTriangle(this, id, v1, v2, v3, color, flags: 0, materialIndex: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007AA20
// Name: public: void RayTracingEnvironment::AddAxisAlignedRectangularSolid(int,class Vector,class Vector,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddAxisAlignedRectangularSolid(
        RayTracingEnvironment *this,
        int id,
        Vector minc,
        Vector maxc,
        const Vector *color)
{
  Vector v6; // [esp+0h] [ebp-30h] BYREF
  Vector v2; // [esp+Ch] [ebp-24h] BYREF
  __int128 v1; // [esp+18h] [ebp-18h] BYREF
  float v3_4; // [esp+28h] [ebp-8h]
  float v3_8; // [esp+2Ch] [ebp-4h]

  v3_4 = minc.y;
  *(_QWORD *)&v6.x = *(_QWORD *)&minc.x;
  v6.z = maxc.z;
  v3_8 = maxc.z;
  v2 = maxc;
  *(_QWORD *)&v1 = __PAIR64__(LODWORD(maxc.y), LODWORD(minc.x));
  *((_QWORD *)&v1 + 1) = __PAIR64__(LODWORD(maxc.x), LODWORD(maxc.z));
  RayTracingEnvironment::AddTriangle(
    this,
    id,
    (const Vector *)&v1,
    &v2,
    v3: (const Vector *)&v1 + 1,
    color,
    flags: 0,
    materialIndex: 0);
  RayTracingEnvironment::AddTriangle(
    this,
    id: id + 1,
    (const Vector *)&v1,
    v2: (const Vector *)&v1 + 1,
    v3: &v6,
    color,
    flags: 0,
    materialIndex: 0);
  v2 = minc;
  *(_QWORD *)&v1 = __PAIR64__(LODWORD(minc.y), LODWORD(maxc.x));
  *((_QWORD *)&v1 + 1) = __PAIR64__(LODWORD(minc.x), LODWORD(minc.z));
  v6.x = maxc.x;
  v6.y = maxc.y;
  v6.z = minc.z;
  v3_4 = maxc.y;
  v3_8 = minc.z;
  RayTracingEnvironment::AddTriangle(
    this,
    id,
    v1: (const Vector *)&v1 + 1,
    v2: &v6,
    v3: (const Vector *)&v1,
    color,
    flags: 0,
    materialIndex: 0);
  RayTracingEnvironment::AddTriangle(
    this,
    id: id + 1,
    v1: (const Vector *)&v1 + 1,
    v2: (const Vector *)&v1,
    v3: &v2,
    color,
    flags: 0,
    materialIndex: 0);
  *(_QWORD *)&v2.x = *(_QWORD *)&minc.x;
  v2.z = maxc.z;
  *(Vector *)&v1 = minc;
  v6.x = minc.x;
  v6.y = maxc.y;
  v6.z = minc.z;
  HIDWORD(v1) = LODWORD(minc.x);
  v3_4 = maxc.y;
  v3_8 = maxc.z;
  RayTracingEnvironment::AddTriangle(
    this,
    id,
    v1: (const Vector *)&v1 + 1,
    v2: &v6,
    v3: (const Vector *)&v1,
    color,
    flags: 0,
    materialIndex: 0);
  RayTracingEnvironment::AddTriangle(
    this,
    id: id + 1,
    v1: (const Vector *)&v1 + 1,
    v2: (const Vector *)&v1,
    v3: &v2,
    color,
    flags: 0,
    materialIndex: 0);
  v2.y = minc.y;
  v2.x = maxc.x;
  v2.z = maxc.z;
  *(_QWORD *)&v1 = __PAIR64__(LODWORD(minc.y), LODWORD(maxc.x));
  *((_QWORD *)&v1 + 1) = __PAIR64__(LODWORD(maxc.x), LODWORD(minc.z));
  v6.x = maxc.x;
  v6.y = maxc.y;
  v6.z = minc.z;
  v3_4 = maxc.y;
  v3_8 = maxc.z;
  RayTracingEnvironment::AddTriangle(
    this,
    id,
    v1: (const Vector *)&v1 + 1,
    v2: &v6,
    v3: (const Vector *)&v1,
    color,
    flags: 0,
    materialIndex: 0);
  RayTracingEnvironment::AddTriangle(
    this,
    id: id + 1,
    v1: (const Vector *)&v1 + 1,
    v2: (const Vector *)&v1,
    v3: &v2,
    color,
    flags: 0,
    materialIndex: 0);
  v2.z = minc.z;
  *((_QWORD *)&v1 + 1) = __PAIR64__(LODWORD(minc.x), LODWORD(minc.z));
  v2.x = minc.x;
  v2.y = maxc.y;
  *(_QWORD *)&v1 = *(_QWORD *)&maxc.x;
  v6 = maxc;
  v3_4 = maxc.y;
  v3_8 = maxc.z;
  RayTracingEnvironment::AddTriangle(
    this,
    id,
    v1: (const Vector *)&v1 + 1,
    v2: &v6,
    v3: (const Vector *)&v1,
    color,
    flags: 0,
    materialIndex: 0);
  RayTracingEnvironment::AddTriangle(
    this,
    id: id + 1,
    v1: (const Vector *)&v1 + 1,
    v2: (const Vector *)&v1,
    v3: &v2,
    color,
    flags: 0,
    materialIndex: 0);
  v2 = minc;
  *(float *)&v1 = maxc.x;
  *(_QWORD *)((char *)&v1 + 4) = *(_QWORD *)&minc.y;
  v6.x = maxc.x;
  v6.y = minc.y;
  v6.z = maxc.z;
  HIDWORD(v1) = LODWORD(minc.x);
  v3_4 = minc.y;
  v3_8 = maxc.z;
  RayTracingEnvironment::AddTriangle(
    this,
    id,
    v1: (const Vector *)&v1 + 1,
    v2: &v6,
    v3: (const Vector *)&v1,
    color,
    flags: 0,
    materialIndex: 0);
  RayTracingEnvironment::AddTriangle(
    this,
    id: id + 1,
    v1: (const Vector *)&v1 + 1,
    v2: (const Vector *)&v1,
    v3: &v2,
    color,
    flags: 0,
    materialIndex: 0);
}

} // namespace vrad_dll

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1035DD70
// Name: public: int FourRays::CalculateDirectionSignMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall FourRays::CalculateDirectionSignMask(FourRays *this)
{
  int v1; // edx
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // esi
  int v7; // edx
  int result; // eax
  int v9; // esi
  int v10; // edx
  int v11; // edi
  int v12; // esi
  int v13; // edx
  int v14; // edi
  int v15; // esi
  int v16; // esi
  int v17; // edx
  int v18; // esi
  int v19; // edi
  int v20; // ecx
  int v21; // esi

  v1 = this->direction.x.m128_i32[0];
  v2 = v1 | this->direction.x.m128_i32[1];
  v3 = this->direction.x.m128_i32[2];
  v4 = v3 & this->direction.x.m128_i32[1] & v1;
  v5 = v3 | v2;
  v6 = this->direction.x.m128_i32[3];
  v7 = v6 & v4;
  if ( (v6 | v5) < 0 )
  {
    if ( v7 >= 0 )
      return -1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  v9 = this->direction.y.m128_i32[0];
  v10 = v9 | this->direction.y.m128_i32[1];
  v11 = this->direction.y.m128_i32[2];
  v12 = v11 & this->direction.y.m128_i32[1] & v9;
  v13 = v11 | v10;
  v14 = this->direction.y.m128_i32[3];
  v15 = v14 & v12;
  if ( (v14 | v13) < 0 )
  {
    if ( v15 >= 0 )
      return -1;
    result |= 2u;
  }
  v16 = this->direction.z.m128_i32[0];
  v17 = v16 | this->direction.z.m128_i32[1];
  v18 = this->direction.z.m128_i32[1] & v16;
  v19 = this->direction.z.m128_i32[2];
  v20 = this->direction.z.m128_i32[3];
  v21 = v19 & v18;
  if ( (v19 | v17 | v20) >= 0 )
    return result;
  if ( (v20 & v21) >= 0 )
    return -1;
  return result | 4;
}

//------------------------------------------------------------------------------
// Address: 0x1035DDF0
// Name: public: void CacheOptimizedTriangle::ChangeIntoIntersectionFormat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CacheOptimizedTriangle::ChangeIntoIntersectionFormat(CacheOptimizedTriangle *this)
{
  int m_nTriangleID; // edx
  float y; // xmm2_4
  int x_low; // xmm3_4
  int v5; // edi
  float z; // xmm4_4
  int v7; // ecx
  int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  __int128 srcTri; // [esp+4h] [ebp-50h]
  __int64 srcTri_16; // [esp+14h] [ebp-40h]
  __int128 srcTri_24; // [esp+1Ch] [ebp-38h]
  __int64 v28; // [esp+30h] [ebp-24h]
  int v29; // [esp+38h] [ebp-1Ch]
  __int64 v30; // [esp+3Ch] [ebp-18h]
  int v31; // [esp+44h] [ebp-10h]
  Vector N; // [esp+48h] [ebp-Ch] BYREF

  srcTri = *(_OWORD *)&this->m_Data.m_IntersectData.m_flNx;
  m_nTriangleID = this->m_Data.m_GeometryData.m_nTriangleID;
  srcTri_16 = *(_QWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[3];
  srcTri_24 = *(_OWORD *)&this->m_Data.m_GeometryData.m_VertexCoordData[5];
  this->m_Data.m_IntersectData.m_nFlags = LODWORD(this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
  this->m_Data.m_IntersectData.m_nTriangleID = m_nTriangleID;
  N.x = (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2)))
      - (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3)));
  N.y = (float)((float)(*(float *)&srcTri_24 - *((float *)&srcTri + 3))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_24 + 3) - *((float *)&srcTri + 3))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)));
  N.z = (float)((float)(*((float *)&srcTri_24 + 2) - *((float *)&srcTri + 2))
              * (float)(*(float *)&srcTri_16 - *((float *)&srcTri + 1)))
      - (float)((float)(*((float *)&srcTri_16 + 1) - *((float *)&srcTri + 2))
              * (float)(*((float *)&srcTri_24 + 1) - *((float *)&srcTri + 1)));
  VectorNormalize(vec: &N);
  y = N.y;
  x_low = LODWORD(N.x);
  v5 = fabs(N.y) > fabs(N.x);
  z = N.z;
  if ( fabs(N.z) > fabs(*(&N.x + v5)) )
    v5 = 2;
  this->m_Data.m_IntersectData.m_flD = (float)((float)(*((float *)&srcTri + 2) * N.y)
                                             + (float)(*((float *)&srcTri + 1) * N.x))
                                     + (float)(*((float *)&srcTri + 3) * N.z);
  v30 = srcTri_16;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_GeometryData.m_nTriangleID = x_low;
  this->m_Data.m_IntersectData.m_flNy = y;
  N.z = *((float *)&srcTri + 3);
  this->m_Data.m_IntersectData.m_flNz = z;
  v28 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v7 = (v5 + 1) % 3;
  v8 = (v5 + 2) % 3;
  v9 = *(&N.x + v7);
  v31 = srcTri_24;
  v10 = *((float *)&v30 + v7) - v9;
  this->m_Data.m_IntersectData.m_nCoordSelect0 = v7;
  v29 = HIDWORD(srcTri_24);
  v11 = *(&N.x + v8) - *((float *)&v30 + v8);
  v12 = (float)(v9 * v11) + (float)(*(&N.x + v8) * v10);
  v13 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_nCoordSelect1 = v8;
  v14 = -v12;
  v15 = (float)((float)(v13 * v11) + (float)(*((float *)&v28 + v8) * v10)) - v12;
  if ( v15 < 0.0 )
  {
    v11 = -v11;
    v10 = -v10;
    v14 = -v14;
    v15 = -v15;
  }
  v16 = 1.0 / v15;
  v17 = (float)(1.0 / v15) * v11;
  v18 = v16;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v16 * v14;
  *(_QWORD *)&N.x = *(_QWORD *)((char *)&srcTri + 4);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0] = v17;
  v28 = srcTri_16;
  v29 = srcTri_24;
  v19 = *((float *)&v28 + v8);
  v20 = *((float *)&v28 + v7);
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1] = v18 * v10;
  v30 = *(_QWORD *)((char *)&srcTri_24 + 4);
  v31 = HIDWORD(srcTri_24);
  v21 = v19 - *((float *)&v30 + v8);
  v22 = *((float *)&v30 + v7) - v20;
  N.z = *((float *)&srcTri + 3);
  v23 = -(float)((float)(v20 * v21) + (float)(v19 * v22));
  v24 = (float)((float)(*(&N.x + v7) * v21) + (float)(*(&N.x + v8) * v22)) + v23;
  if ( v24 < 0.0 )
  {
    v21 = -v21;
    v22 = -v22;
    v23 = -v23;
    v24 = -v24;
  }
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = (float)(1.0 / v24) * v21;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = (float)(1.0 / v24) * v22;
  this->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5] = (float)(1.0 / v24) * v23;
}

//------------------------------------------------------------------------------
// Address: 0x1035E0E0
// Name: public: void RayTracingEnvironment::Trace4Rays<1>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<1>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (int)v72, value: (unsigned __int8 *)0xFF, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(Four_Zeros, v48));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035E6E0
// Name: public: void RayTracingEnvironment::Trace4Rays<2>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<2>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 *v52; // ecx
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  int (__thiscall *v65)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v66; // al
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  _DWORD v72[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v73; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v74; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v75; // [esp-D0h] [ebp-DCh]
  __m128 v76; // [esp-C0h] [ebp-CCh]
  __m128 v77; // [esp-B0h] [ebp-BCh]
  _QWORD v78[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v79; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v80; // [esp-60h] [ebp-6Ch]
  __m128 v81; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v82; // [esp-40h] [ebp-4Ch]
  int *v83; // [esp-2Ch] [ebp-38h]
  int v84; // [esp-28h] [ebp-34h]
  int v85; // [esp-24h] [ebp-30h]
  int v86; // [esp-20h] [ebp-2Ch]
  int v87; // [esp-1Ch] [ebp-28h]
  int v88; // [esp-18h] [ebp-24h]
  int v89; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v91; // [esp-Ch] [ebp-18h]
  __m128 *v92; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v94; // [esp+0h] [ebp-Ch]
  void *v95; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v94 = a4;
  v95 = retaddr;
  v9 = alloca(41592);
  v91 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v78 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v78[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v78;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v78;
  *(__m128 *)&v78[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v80 = TMin;
  v82 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (int)v72, value: (unsigned __int8 *)0xFF, count: sizeof(v72));
    if ( (a6 & 1) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v86 = 0;
      v89 = 1;
    }
    else
    {
      v86 = 1;
      v89 = 0;
    }
    m_pMemory = v91->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v82;
    v28 = v80;
    for ( j = (__m128 *)v72; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v92 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v91->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v78[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v84 + v31);
              v36 = *(&v87 + v31);
              v37 = v92 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v92 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v87 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v84 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v92;
        v82 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v91->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v83 )
        {
          v39 = *k;
          v83 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v91->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v91->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v91->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v72[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = a5[4];
            v46 = _mm_mul_ps(v42, a5[3]);
            v75 = v42;
            v47 = _mm_mul_ps(v42, *a5);
            v48 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v45, v43), v46), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v77 = v44;
            v50 = _mm_div_ps(
                    _mm_sub_ps(
                      _mm_shuffle_ps(m_flD_low, m_flD_low, 0),
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v43), v47), _mm_mul_ps(a5[2], v44))),
                    v48);
            v51 = _mm_and_ps(
                    _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v48), _mm_cmplt_ps(v48, FourNegativeEpsilons)),
                    _mm_cmplt_ps(v48, Four_Zeros));
            v72[(unsigned __int8)v39] = v39;
            v52 = a7;
            v53 = _mm_and_ps(_mm_and_ps(v51, _mm_cmplt_ps(v26, v50)), _mm_cmplt_ps(v50, a7[4]));
            v76 = v43;
            v80 = v50;
            v81 = v53;
            if ( _mm_movemask_ps(v53) != 0 )
            {
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v56 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v58 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v50), a5[m_nCoordSelect0]);
              v59 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v57));
              v60 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v61 = _mm_add_ps(v59, _mm_shuffle_ps(v55, v55, 0));
              v81 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v58),
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v57)),
                      _mm_shuffle_ps(v60, v60, 0));
              v26 = FourZeros;
              v63 = _mm_add_ps(v62, v61);
              v74 = v61;
              v79 = v62;
              v64 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v61), v53), _mm_cmple_ps(FourZeros, v62)),
                      _mm_cmple_ps(v63, Four_Ones));
              v81 = v64;
              if ( _mm_movemask_ps(v64) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v65 = **a9;
                  v73 = _mm_sub_ps(Four_Ones, v63);
                  v66 = v65(a1: a9, a2: v40, a3: a5, a4: &v81, a5: &v79, a6: &v73, a7: &v74, a8: v39);
                  v27 = v82;
                  v50 = v80;
                  v52 = a7;
                  if ( v66 != 0 )
                  {
                    v64 = Four_Zeros;
                    v81 = Four_Zeros;
                  }
                  else
                  {
                    v64 = v81;
                  }
                }
                else
                {
                  v27 = v82;
                }
                v67 = v52[3];
                m_nCoordSelect0 = v39;
                v52[3] = _mm_or_ps(
                           _mm_andnot_ps(v64, v67),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v64));
                v68 = *v52;
                v52[4] = _mm_or_ps(_mm_andnot_ps(v64, v52[4]), _mm_and_ps(v50, v64));
                v69 = _mm_andnot_ps(v64, v68);
                v70 = v52[1];
                *v52 = _mm_or_ps(_mm_and_ps(v64, v75), v69);
                v71 = v52[2];
                v52[1] = _mm_or_ps(_mm_and_ps(v64, v76), _mm_andnot_ps(v64, v70));
                v52[2] = _mm_or_ps(_mm_and_ps(v64, v77), _mm_andnot_ps(v64, v71));
                v26 = FourZeros;
              }
              else
              {
                v27 = v82;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v92;
      }
      if ( j == (__m128 *)v72 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v82 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035ECE0
// Name: public: void RayTracingEnvironment::Trace4Rays<0>(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays<0>(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        __m128 *a5,
        char a6,
        __m128 *a7,
        int a8,
        int (__thiscall ***a9)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int))
{
  void *v9; // esp
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 *v19; // ecx
  Vector *p_m_MaxBound; // eax
  int v21; // edx
  int i; // esi
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  CacheOptimizedKDNode *m_pMemory; // edx
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 *j; // esi
  int Children; // ecx
  int v31; // eax
  CacheOptimizedKDNode *v32; // esi
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // edx
  int v36; // eax
  __m128 *v37; // ecx
  int *k; // eax
  int v39; // esi
  CacheOptimizedTriangle *v40; // eax
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 m_flD_low; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 *v51; // ecx
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm0
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  int (__thiscall *v64)(_DWORD, CacheOptimizedTriangle *, __m128 *, __m128 *, __m128 *, __m128 *, __m128 *, int); // edx
  char v65; // al
  __m128 v66; // xmm4
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm2
  _DWORD v71[256]; // [esp-4F0h] [ebp-4FCh] BYREF
  __m128 v72; // [esp-F0h] [ebp-FCh] BYREF
  __m128 v73; // [esp-E0h] [ebp-ECh] BYREF
  __m128 v74; // [esp-D0h] [ebp-DCh]
  __m128 v75; // [esp-C0h] [ebp-CCh]
  __m128 v76; // [esp-B0h] [ebp-BCh]
  _QWORD v77[6]; // [esp-A0h] [ebp-ACh] BYREF
  __m128 v78; // [esp-70h] [ebp-7Ch] BYREF
  __m128 v79; // [esp-60h] [ebp-6Ch]
  __m128 v80; // [esp-50h] [ebp-5Ch] BYREF
  __m128 v81; // [esp-40h] [ebp-4Ch]
  int *v82; // [esp-2Ch] [ebp-38h]
  int v83; // [esp-28h] [ebp-34h]
  int v84; // [esp-24h] [ebp-30h]
  int v85; // [esp-20h] [ebp-2Ch]
  int v86; // [esp-1Ch] [ebp-28h]
  int v87; // [esp-18h] [ebp-24h]
  int v88; // [esp-14h] [ebp-20h]
  CacheOptimizedKDNode *SplittingPlaneValue_low; // [esp-10h] [ebp-1Ch]
  RayTracingEnvironment *v90; // [esp-Ch] [ebp-18h]
  __m128 *v91; // [esp-8h] [ebp-14h]
  int m_nCoordSelect0; // [esp-4h] [ebp-10h]
  int v93; // [esp+0h] [ebp-Ch]
  void *v94; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v93 = a4;
  v94 = retaddr;
  v9 = alloca(41592);
  v90 = this;
  a7[3].m128_i32[0] = -1;
  a7[3].m128_i32[1] = -1;
  a7[3].m128_i32[2] = -1;
  a7[3].m128_i32[3] = -1;
  a7[4] = _mm_shuffle_ps((__m128)0x65A96816u, (__m128)0x65A96816u, 0);
  *a7 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[1] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  a7[2] = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v11 = a5[5];
  v12 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[3], Four_Zeros), Four_Epsilons), a5[3]);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(_mm_add_ps(v13, v13), _mm_mul_ps(_mm_mul_ps(v13, v13), v12));
  v15 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(a5[4], Four_Zeros), Four_Epsilons), a5[4]);
  *(__m128 *)v77 = v14;
  v16 = _mm_rcp_ps(v15);
  *(__m128 *)&v77[2] = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v16), v15));
  v17 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(v11, Four_Zeros), Four_Epsilons), v11);
  v18 = _mm_rcp_ps(v17);
  v19 = (__m128 *)v77;
  p_m_MaxBound = &this->m_MaxBound;
  v21 = (char *)a5 - (char *)v77;
  *(__m128 *)&v77[4] = _mm_sub_ps(_mm_add_ps(v18, v18), _mm_mul_ps(_mm_mul_ps(v18, v18), v17));
  for ( i = 3; i != 0; --i )
  {
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound[-1].x), (__m128)LODWORD(p_m_MaxBound[-1].x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    v24 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(p_m_MaxBound->x), (__m128)LODWORD(p_m_MaxBound->x), 0),
              *(__m128 *)((char *)v19 + v21)),
            *v19);
    p_m_MaxBound = (Vector *)((char *)p_m_MaxBound + 4);
    ++v19;
    TMin = _mm_max_ps(TMin, _mm_min_ps(v23, v24));
    TMax = _mm_min_ps(TMax, _mm_max_ps(v23, v24));
  }
  v79 = TMin;
  v81 = TMax;
  if ( _mm_movemask_ps(_mm_cmple_ps(TMin, TMax)) != 0 )
  {
    memset(dst: (int)v71, value: (unsigned __int8 *)0xFF, count: sizeof(v71));
    if ( (a6 & 1) != 0 )
    {
      v83 = 0;
      v86 = 1;
    }
    else
    {
      v83 = 1;
      v86 = 0;
    }
    if ( (a6 & 2) != 0 )
    {
      v84 = 0;
      v87 = 1;
    }
    else
    {
      v84 = 1;
      v87 = 0;
    }
    if ( (a6 & 4) != 0 )
    {
      v85 = 0;
      v88 = 1;
    }
    else
    {
      v85 = 1;
      v88 = 0;
    }
    m_pMemory = v90->OptimizedKDTree.m_Memory.m_pMemory;
    v26 = FourZeros;
    v27 = v81;
    v28 = v79;
    for ( j = (__m128 *)v71; ; j += 3 )
    {
      Children = m_pMemory->Children;
      v31 = m_pMemory->Children & 3;
      v91 = j;
      if ( v31 != 3 )
      {
        SplittingPlaneValue_low = v90->OptimizedKDTree.m_Memory.m_pMemory;
        do
        {
          v32 = &SplittingPlaneValue_low[Children >> 2];
          v33 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      (__m128)LODWORD(m_pMemory->SplittingPlaneValue),
                      0),
                    a5[v31]),
                  *(__m128 *)&v77[2 * v31]);
          v34 = _mm_cmple_ps(v28, v27);
          if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v33), v34)) != 0 )
          {
            if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v27), v34)) != 0 )
            {
              v35 = *(&v83 + v31);
              v36 = *(&v86 + v31);
              v37 = v91 - 3;
              v37->m128_i32[0] = (int)&v32[v35];
              v91 = v37;
              v37[1] = _mm_max_ps(v28, v33);
              v37[2] = v27;
              m_pMemory = &v32[v36];
            }
            else
            {
              m_pMemory = &v32[*(&v86 + v31)];
            }
            v27 = _mm_min_ps(v27, v33);
          }
          else
          {
            m_pMemory = &v32[*(&v83 + v31)];
            v28 = _mm_max_ps(v28, v33);
          }
          Children = m_pMemory->Children;
          v31 = m_pMemory->Children & 3;
        }
        while ( v31 != 3 );
        j = v91;
        v81 = v27;
      }
      SplittingPlaneValue_low = (CacheOptimizedKDNode *)LODWORD(m_pMemory->SplittingPlaneValue);
      if ( SplittingPlaneValue_low != nullptr )
      {
        for ( k = &v90->TriangleIndexList.m_Memory.m_pMemory[m_pMemory->Children >> 2]; ; k = v82 )
        {
          v39 = *k;
          v82 = k + 1;
          m_nCoordSelect0 = (unsigned __int8)v39;
          v40 = &v90->OptimizedTriangleList.m_Memory.m_pMemory[v39 >> (*((int *)&v90->OptimizedTriangleList.m_Memory + 2) >> 27)][v39 & ((32 * *((_DWORD *)&v90->OptimizedTriangleList.m_Memory + 2)) >> 5)];
          if ( v71[(unsigned __int8)v39] != v39 && v40->m_Data.m_IntersectData.m_nTriangleID != a8 )
          {
            ++n_intersection_calculations;
            v41 = a5[1];
            v42 = _mm_shuffle_ps(
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    (__m128)(unsigned int)v40->m_Data.m_GeometryData.m_nTriangleID,
                    0);
            v43 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNy),
                    0);
            v44 = _mm_shuffle_ps(
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flNz),
                    0);
            v45 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, a5[3]), _mm_mul_ps(a5[4], v43)), _mm_mul_ps(a5[5], v44));
            m_flD_low = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_flD);
            v74 = v42;
            v47 = _mm_add_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(v42, *a5));
            v48 = _mm_mul_ps(a5[2], v44);
            v76 = v44;
            v49 = _mm_div_ps(_mm_sub_ps(_mm_shuffle_ps(m_flD_low, m_flD_low, 0), _mm_add_ps(v47, v48)), v45);
            v50 = _mm_or_ps(_mm_cmplt_ps(FourEpsilons, v45), _mm_cmplt_ps(v45, FourNegativeEpsilons));
            v71[(unsigned __int8)v39] = v39;
            v51 = a7;
            v52 = _mm_and_ps(_mm_and_ps(v50, _mm_cmplt_ps(v26, v49)), _mm_cmplt_ps(v49, a7[4]));
            v75 = v43;
            v79 = v49;
            v80 = v52;
            if ( _mm_movemask_ps(v52) != 0 )
            {
              v53 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[1]);
              v54 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[2]);
              v55 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect0;
              v56 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              m_nCoordSelect0 = v40->m_Data.m_IntersectData.m_nCoordSelect1;
              v57 = _mm_add_ps(_mm_mul_ps(a5[m_nCoordSelect0 + 3], v49), a5[m_nCoordSelect0]);
              v58 = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v56));
              v59 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[5]);
              v60 = _mm_add_ps(v58, _mm_shuffle_ps(v54, v54, 0));
              v80 = (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[3]);
              v61 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            (__m128)LODWORD(v40->m_Data.m_IntersectData.m_ProjectedEdgeEquations[4]),
                            0),
                          v57),
                        _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v56)),
                      _mm_shuffle_ps(v59, v59, 0));
              v26 = FourZeros;
              v62 = _mm_add_ps(v61, v60);
              v73 = v60;
              v78 = v61;
              v63 = _mm_and_ps(
                      _mm_and_ps(_mm_and_ps(_mm_cmple_ps(FourZeros, v60), v52), _mm_cmple_ps(FourZeros, v61)),
                      _mm_cmple_ps(v62, Four_Ones));
              v80 = v63;
              if ( _mm_movemask_ps(v63) != 0 )
              {
                if ( (v40->m_Data.m_IntersectData.m_nFlags & 1) != 0 && a9 != nullptr )
                {
                  v64 = **a9;
                  v72 = _mm_sub_ps(Four_Ones, v62);
                  v65 = v64(a1: a9, a2: v40, a3: a5, a4: &v80, a5: &v78, a6: &v72, a7: &v73, a8: v39);
                  v27 = v81;
                  v49 = v79;
                  v51 = a7;
                  if ( v65 != 0 )
                  {
                    v63 = Four_Zeros;
                    v80 = Four_Zeros;
                  }
                  else
                  {
                    v63 = v80;
                  }
                }
                else
                {
                  v27 = v81;
                }
                v66 = v51[3];
                m_nCoordSelect0 = v39;
                v51[3] = _mm_or_ps(
                           _mm_andnot_ps(v63, v66),
                           _mm_and_ps(_mm_shuffle_ps((__m128)(unsigned int)v39, (__m128)(unsigned int)v39, 0), v63));
                v67 = *v51;
                v51[4] = _mm_or_ps(_mm_andnot_ps(v63, v51[4]), _mm_and_ps(v49, v63));
                v68 = _mm_andnot_ps(v63, v67);
                v69 = v51[1];
                *v51 = _mm_or_ps(_mm_and_ps(v63, v74), v68);
                v70 = v51[2];
                v51[1] = _mm_or_ps(_mm_and_ps(v63, v75), _mm_andnot_ps(v63, v69));
                v51[2] = _mm_or_ps(_mm_and_ps(v63, v76), _mm_andnot_ps(v63, v70));
                v26 = FourZeros;
              }
              else
              {
                v27 = v81;
              }
            }
          }
          SplittingPlaneValue_low = (CacheOptimizedKDNode *)((char *)SplittingPlaneValue_low - 1);
          if ( SplittingPlaneValue_low == nullptr )
            break;
        }
        if ( _mm_movemask_ps(_mm_cmple_ps(v27, a7[4])) == 0 )
          return;
        j = v91;
      }
      if ( j == (__m128 *)v71 )
        return;
      v27 = j[2];
      m_pMemory = (CacheOptimizedKDNode *)j->m128_i32[0];
      v28 = j[1];
      v81 = v27;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F2D0
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,int,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        const FourRays *rays,
        char DirectionSignMask,
        RayTracingResult *rslt_out,
        int skip_id,
        ITransparentTriangleCallback *pCallback,
        RTECullMode_t cullMode)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( cullMode == RTE_CULL_FRONT )
  {
    RayTracingEnvironment::Trace4Rays<1>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else if ( cullMode == RTE_CULL_BACK )
  {
    RayTracingEnvironment::Trace4Rays<2>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
  else
  {
    RayTracingEnvironment::Trace4Rays<0>(
      this,
      TMin,
      TMax,
      a4: (int)&savedregs,
      a5: &rays->origin.x,
      a6: DirectionSignMask,
      a7: &rslt_out->surface_normal.x,
      a8: skip_id,
      a9: pCallback);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F340
// Name: public: void RayTracingEnvironment::CalculateTriangleListBounds(int const __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::CalculateTriangleListBounds(
        RayTracingEnvironment *this,
        const int *tris,
        int ntris,
        Vector *minout,
        Vector *maxout)
{
  int v7; // ecx
  float *p_m_flNz; // eax
  float x; // xmm0_4
  float v10; // xmm0_4
  float y; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // xmm0_4
  int i; // [esp+10h] [ebp+10h]

  minout->x = 9.9999998e22;
  minout->y = 9.9999998e22;
  minout->z = 9.9999998e22;
  maxout->x = -9.9999998e22;
  maxout->y = -9.9999998e22;
  maxout->z = -9.9999998e22;
  for ( i = 0; i < ntris; ++i )
  {
    v7 = 3;
    p_m_flNz = &this->OptimizedTriangleList.m_Memory.m_pMemory[tris[i] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                           + 2) >> 27)][tris[i]
                                                                                      & ((32
                                                                                        * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                          + 2)) >> 5)].m_Data.m_IntersectData.m_flNz;
    do
    {
      x = minout->x;
      if ( *(p_m_flNz - 1) <= minout->x )
        x = *(p_m_flNz - 1);
      minout->x = x;
      v10 = maxout->x;
      if ( maxout->x <= *(p_m_flNz - 1) )
        v10 = *(p_m_flNz - 1);
      maxout->x = v10;
      y = minout->y;
      if ( *p_m_flNz <= y )
        y = *p_m_flNz;
      minout->y = y;
      v12 = maxout->y;
      if ( v12 <= *p_m_flNz )
        v12 = *p_m_flNz;
      maxout->y = v12;
      z = minout->z;
      if ( p_m_flNz[1] <= z )
        z = p_m_flNz[1];
      minout->z = z;
      v14 = maxout->z;
      if ( v14 <= p_m_flNz[1] )
        v14 = p_m_flNz[1];
      p_m_flNz += 3;
      --v7;
      maxout->z = v14;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F470
// Name: public: float RayTracingEnvironment::CalculateCostsOfSplit(int,int const __near *,int,class Vector,class Vector,float __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall RayTracingEnvironment::CalculateCostsOfSplit(
        RayTracingEnvironment *this,
        int split_plane,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        float *split_value,
        int *nleft,
        int *nright,
        int *nboth)
{
  int *v10; // eax
  int *v11; // edx
  float v12; // xmm5_4
  float v13; // xmm4_4
  int *v14; // ebx
  int v16; // ecx
  CacheOptimizedTriangle *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  int v25; // xmm0_4
  double v26; // st7
  Vector RightMins; // [esp+0h] [ebp-1Ch]
  Vector LeftMaxes; // [esp+Ch] [ebp-10h]
  int t; // [esp+18h] [ebp-4h]
  float ISA; // [esp+4Ch] [ebp+30h]

  v10 = nleft;
  v11 = nright;
  v12 = 9.9999998e22;
  v13 = -9.9999998e22;
  v14 = nboth;
  v16 = 0;
  *nleft = 0;
  *nright = 0;
  *nboth = 0;
  t = 0;
  if ( ntris > 0 )
  {
    while ( 1 )
    {
      v17 = &this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                              + 2) >> 27)][tri_list[v16]
                                                                                         & ((32
                                                                                           * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                             + 2)) >> 5)];
      v18 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v18 <= v12 )
        v12 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v13 <= v18 )
        v13 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      v19 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v19 <= v12 )
        v12 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v13 <= v19 )
        v13 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v20 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v20 <= v12 )
        v12 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v13 <= v20 )
        v13 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      v21 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v22 = *split_value;
      v23 = *(&v17->m_Data.m_IntersectData.m_flNy + split_plane);
      if ( v21 <= v18 )
        v18 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      if ( v23 <= v21 )
        v23 = v17->m_Data.m_GeometryData.m_VertexCoordData[split_plane + 3];
      v24 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v24 <= v18 )
        v18 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v23 <= v24 )
        v23 = v17->m_Data.m_IntersectData.m_ProjectedEdgeEquations[split_plane + 2];
      if ( v18 >= v22 )
        break;
      if ( v22 >= v23 )
      {
        v10 = nleft;
        ++*nleft;
        v11 = nright;
        v17->m_Data.m_GeometryData.m_nTmpData0 = -1;
        goto LABEL_28;
      }
      if ( v18 == v23 )
        break;
      v14 = nboth;
      ++*nboth;
      v10 = nleft;
      v11 = nright;
      v17->m_Data.m_GeometryData.m_nTmpData0 = 0;
LABEL_29:
      v16 = t + 1;
      t = v16;
      if ( v16 >= ntris )
        goto LABEL_30;
    }
    v11 = nright;
    ++*nright;
    v10 = nleft;
    v17->m_Data.m_GeometryData.m_nTmpData0 = 1;
LABEL_28:
    v14 = nboth;
    goto LABEL_29;
  }
LABEL_30:
  if ( *v10 == 0 || *v14 != 0 )
  {
LABEL_34:
    if ( *v11 == 0 )
      goto LABEL_38;
    goto LABEL_35;
  }
  if ( *v11 == 0 )
  {
    *split_value = v13;
    goto LABEL_34;
  }
LABEL_35:
  if ( *v14 == 0 && *v10 == 0 )
    *split_value = v12;
LABEL_38:
  LeftMaxes = MaxBound;
  RightMins = MinBound;
  v25 = *(_DWORD *)split_value;
  *(&LeftMaxes.x + split_plane) = *split_value;
  v26 = LeftMaxes.x - MinBound.x;
  *((_DWORD *)&RightMins.x + split_plane) = v25;
  ISA = 1.0
      / (float)((float)((float)((float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.x - MinBound.x))
                              + (float)((float)(MaxBound.y - MinBound.y) * (float)(MaxBound.x - MinBound.x)))
                      + (float)((float)(MaxBound.z - MinBound.z) * (float)(MaxBound.y - MinBound.y)))
              * 2.0);
  return (((MaxBound.y - RightMins.y) * (MaxBound.z - RightMins.z)
         + (MaxBound.x - RightMins.x) * (MaxBound.y - RightMins.y)
         + (MaxBound.z - RightMins.z) * (MaxBound.x - RightMins.x))
        * 2.0
        * ISA
        * (double)*v11
        + ((LeftMaxes.y - MinBound.y) * (LeftMaxes.z - MinBound.z)
         + (LeftMaxes.z - MinBound.z) * v26
         + v26 * (LeftMaxes.y - MinBound.y))
        * 2.0
        * ISA
        * (double)*v10
        + (double)*v14)
       * 167.0
       + 75.0;
}

//------------------------------------------------------------------------------
// Address: 0x1035F7F0
// Name: public: void RayTracingEnvironment::Trace4Rays(class FourRays const __near &,union __m128,union __m128,struct RayTracingResult __near *,int,class ITransparentTriangleCallback __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::Trace4Rays(
        RayTracingEnvironment *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int a4@<ebp>,
        int a5,
        RayTracingResult *a6,
        int a7,
        ITransparentTriangleCallback *a8,
        RTECullMode_t a9)
{
  int v10; // eax
  int v11; // edi
  int v12; // eax
  char *v13; // ecx
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  int *v20; // esi
  int v21; // xmm4_4
  int v22; // xmm3_4
  int v23; // xmm2_4
  _BYTE *v24; // eax
  char v25; // al
  int v26; // ecx
  float *m128_f32; // eax
  int v28; // esi
  double v29; // st7
  bool v30; // zf
  _DWORD v31[3]; // [esp-Ch] [ebp-11Ch] BYREF
  RayTracingResult tmpresults_4; // [esp+4h] [ebp-10Ch] OVERLAPPED
  __m128 v33; // [esp+54h] [ebp-BCh]
  _BYTE v34[96]; // [esp+64h] [ebp-ACh] OVERLAPPED BYREF
  int v35; // [esp+D0h] [ebp-40h]
  float v36; // [esp+D4h] [ebp-3Ch]
  float v37; // [esp+D8h] [ebp-38h]
  float v38; // [esp+DCh] [ebp-34h]
  char *v39; // [esp+E0h] [ebp-30h]
  int v40; // [esp+E4h] [ebp-2Ch]
  _BYTE *v41; // [esp+E8h] [ebp-28h]
  int v42; // [esp+ECh] [ebp-24h]
  int v43; // [esp+F0h] [ebp-20h]
  int v44; // [esp+F4h] [ebp-1Ch]
  int v45; // [esp+F8h] [ebp-18h]
  RayTracingEnvironment *v46; // [esp+FCh] [ebp-14h] BYREF
  int v47; // [esp+100h] [ebp-10h]
  _DWORD v48[2]; // [esp+104h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+110h] [ebp+0h]

  v48[0] = a4;
  v48[1] = retaddr;
  tmpresults_4.HitDistance = TMax;
  v33 = TMin;
  v46 = this;
  v10 = FourRays::CalculateDirectionSignMask(this: (FourRays *)a5);
  if ( v10 == -1 )
  {
    *(_OWORD *)v34 = *(_OWORD *)a5;
    *(_OWORD *)&v34[16] = *(_OWORD *)(a5 + 16);
    v11 = 1;
    v12 = a5 + 48;
    v13 = (char *)&v46 + 3;
    *(_OWORD *)&v34[32] = *(_OWORD *)(a5 + 32);
    v47 = 16843009;
    v44 = 1;
    v45 = a5 + 48;
    v39 = (char *)&v46 + 3;
    v43 = 4;
    do
    {
      if ( v13[v11] != 0 )
      {
        v14 = *(float *)v12;
        v15 = *(float *)(v12 + 16);
        v16 = *(float *)(v12 + 32);
        v17 = 0;
        v17.m128_f32[0] = *(float *)v12;
        *(__m128 *)&v34[48] = _mm_shuffle_ps(v17, v17, 0);
        v18 = 0;
        v18.m128_f32[0] = v15;
        *(__m128 *)&v34[64] = _mm_shuffle_ps(v18, v18, 0);
        v19 = 0;
        v19.m128_f32[0] = v16;
        v13[v11] = 2;
        *(__m128 *)&v34[80] = _mm_shuffle_ps(v19, v19, 0);
        if ( v11 < 4 )
        {
          v20 = (int *)(v12 + 20);
          v41 = &v34[-a5 + 16];
          do
          {
            if ( *((_BYTE *)&v48[-1] + v11) != 0 )
            {
              v21 = *(v20 - 4);
              v38 = v14;
              v40 = v21;
              if ( (((v21 < 0) ^ (unsigned __int8)~(v14 < 0.0)) & 1) != 0 )
              {
                v22 = *v20;
                v37 = v15;
                v42 = v22;
                if ( (((v22 < 0) ^ (unsigned __int8)~(v15 < 0.0)) & 1) != 0 )
                {
                  v23 = v20[4];
                  v36 = v16;
                  v35 = v23;
                  if ( (((v23 < 0) ^ (unsigned __int8)~(v16 < 0.0)) & 1) != 0 )
                  {
                    v24 = v41;
                    *((_BYTE *)&v48[-1] + v11) = 2;
                    *(_DWORD *)&v34[4 * v11 + 48] = v21;
                    *(_DWORD *)&v34[(_DWORD)v20 - a5] = v22;
                    *(int *)((char *)v20 + (_DWORD)v24) = v23;
                  }
                }
              }
            }
            ++v11;
            ++v20;
          }
          while ( v11 < 4 );
        }
        v25 = FourRays::CalculateDirectionSignMask(this: (FourRays *)v34);
        if ( a9 == RTE_CULL_FRONT )
        {
          RayTracingEnvironment::Trace4Rays<1>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        else if ( a9 == RTE_CULL_BACK )
        {
          RayTracingEnvironment::Trace4Rays<2>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        else
        {
          RayTracingEnvironment::Trace4Rays<0>(
            this: v46,
            TMin,
            TMax,
            a4: (int)v48,
            a5: (__m128 *)v34,
            a6: v25,
            a7: (__m128 *)v31,
            a8: a7,
            a9: a8);
        }
        v26 = 0;
        m128_f32 = a6->HitDistance.m128_f32;
        do
        {
          if ( *((_BYTE *)&v48[-1] + v26) == 2 )
          {
            v28 = tmpresults_4.HitIds[v26 - 4];
            *m128_f32 = *(float *)((char *)m128_f32 + (char *)v31 - (char *)a6);
            *((_BYTE *)&v48[-1] + v26) = 0;
            v29 = *(float *)&v31[v26];
            *((_DWORD *)m128_f32 - 4) = v28;
            *(m128_f32 - 16) = v29;
            *(m128_f32 - 12) = tmpresults_4.surface_normal.x.m128_f32[v26];
            *(m128_f32 - 8) = *(float *)&tmpresults_4.HitIds[v26 - 8];
          }
          ++v26;
          ++m128_f32;
        }
        while ( v26 < 4 );
        TMin = v33;
        TMax = tmpresults_4.HitDistance;
        v12 = v45;
        v11 = v44;
        v13 = v39;
      }
      v12 += 4;
      ++v11;
      v30 = v43-- == 1;
      v45 = v12;
      v44 = v11;
    }
    while ( !v30 );
  }
  else
  {
    RayTracingEnvironment::Trace4Rays(
      this,
      TMin,
      TMax,
      rays: (const FourRays *)a5,
      DirectionSignMask: v10,
      rslt_out: a6,
      skip_id: a7,
      pCallback: a8,
      cullMode: a9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035FA90
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color,
        unsigned __int16 flags,
        int materialIndex)
{
  float y; // xmm0_4
  int m_Size; // eax
  int m_nAllocationCount; // eax
  int v12; // edi
  int *m_pMemory; // ecx
  int v14; // eax
  int *v15; // eax
  CacheOptimizedTriangle tmptri; // [esp+0h] [ebp-30h] BYREF

  tmptri.m_Data.m_GeometryData.m_nTriangleID = id;
  *(Vector *)tmptri.m_Data.m_GeometryData.m_VertexCoordData = *v1;
  *(Vector *)&tmptri.m_Data.m_GeometryData.m_VertexCoordData[3] = *v2;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[2] = v3->x;
  y = v3->y;
  tmptri.m_Data.m_GeometryData.m_nFlags = flags;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[3] = y;
  m_Size = this->OptimizedTriangleList.m_Size;
  tmptri.m_Data.m_IntersectData.m_ProjectedEdgeEquations[4] = v3->z;
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
    this: &this->OptimizedTriangleList,
    elem: m_Size,
    src: &tmptri);
  if ( (this->Flags & 2) == 0 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->TriangleColors,
      elem: this->TriangleColors.m_Size,
      src: (const QAngle *)color);
  if ( (this->Flags & 4) == 0 )
  {
    m_nAllocationCount = this->TriangleMaterials.m_Memory.m_nAllocationCount;
    v12 = this->TriangleMaterials.m_Size;
    if ( v12 + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->TriangleMaterials,
        num: v12 - m_nAllocationCount + 1);
    ++this->TriangleMaterials.m_Size;
    m_pMemory = this->TriangleMaterials.m_Memory.m_pMemory;
    v14 = this->TriangleMaterials.m_Size - v12 - 1;
    this->TriangleMaterials.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v12 + 1], src: (unsigned __int8 *)&m_pMemory[v12], count: 4 * v14);
    v15 = &this->TriangleMaterials.m_Memory.m_pMemory[v12];
    if ( v15 != nullptr )
      *v15 = materialIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035FBB0
// Name: public: void RayTracingEnvironment::RefineNode(int,int const __near *,int,class Vector,class Vector,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::RefineNode(
        RayTracingEnvironment *this,
        int node_number,
        const int *tri_list,
        int ntris,
        Vector MinBound,
        Vector MaxBound,
        int depth)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // edi
  float v14; // xmm6_4
  int v15; // edi
  int v16; // eax
  float v17; // xmm0_4
  bool v18; // cc
  double v19; // st7
  int v20; // edx
  int v21; // ecx
  CacheOptimizedTriangle *v22; // eax
  int *v23; // eax
  int v24; // edx
  int v25; // ecx
  float v26; // xmm0_4
  int v27; // edx
  char m_nTmpData1; // al
  float v29; // eax
  float v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  CacheOptimizedKDNode *v34; // eax
  const int *v35; // ecx
  int v36; // eax
  CacheOptimizedKDNode *v37; // edx
  int v38; // eax
  float *p_Children; // ecx
  const int *v40; // ecx
  int v41; // eax
  CacheOptimizedKDNode *v42; // edx
  int v43; // eax
  float *v44; // ecx
  int *v45; // ebx
  int v46; // edi
  int v47; // edi
  int v48; // eax
  int *v49; // ecx
  int v50; // eax
  int *v51; // edi
  Vector RightMins; // [esp+24h] [ebp-50h]
  Vector LeftMaxes; // [esp+30h] [ebp-44h]
  int *new_triangle_list; // [esp+3Ch] [ebp-38h]
  int right_child; // [esp+40h] [ebp-34h] BYREF
  int trial_nright; // [esp+44h] [ebp-30h] BYREF
  int trial_nleft; // [esp+48h] [ebp-2Ch] BYREF
  int trial_cost; // [esp+4Ch] [ebp-28h]
  float best_splitvalue; // [esp+50h] [ebp-24h]
  float best_cost; // [esp+54h] [ebp-20h]
  int best_nright; // [esp+58h] [ebp-1Ch]
  int best_nboth; // [esp+5Ch] [ebp-18h]
  int split_plane; // [esp+60h] [ebp-14h]
  int tv; // [esp+64h] [ebp-10h]
  float trial_splitvalue; // [esp+68h] [ebp-Ch] BYREF
  int best_nleft; // [esp+6Ch] [ebp-8h]
  int ts; // [esp+70h] [ebp-4h]
  const int *tri_lista; // [esp+80h] [ebp+Ch]
  const int *tri_listb; // [esp+80h] [ebp+Ch]
  int left_child; // [esp+84h] [ebp+10h]
  int *left_childa; // [esp+84h] [ebp+10h]
  int left_childb; // [esp+84h] [ebp+10h]
  Vector RightMaxes; // 0:^40.12
  Vector LeftMins; // 0:^4C.12

  if ( ntris < 3 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      m_Size = this->TriangleIndexList.m_Size;
      m_nAllocationCount = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->TriangleIndexList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->TriangleIndexList.m_Size;
      m_pMemory = this->TriangleIndexList.m_Memory.m_pMemory;
      v12 = this->TriangleIndexList.m_Size - m_Size - 1;
      this->TriangleIndexList.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v12);
      v13 = &this->TriangleIndexList.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = tri_list[depth];
    }
    return;
  }
  v14 = 9.9999998e22;
  v15 = 0;
  best_cost = 9.9999998e22;
  best_nleft = 0;
  best_nright = 0;
  best_nboth = 0;
  best_splitvalue = 0.0;
  split_plane = 0;
  new_triangle_list = (int *)(ntris / 10 + 1);
  left_child = 0;
  do
  {
    v16 = -1;
    ts = -1;
    if ( ntris <= -1 )
      goto LABEL_30;
    while ( 2 )
    {
      tv = 0;
      while ( 1 )
      {
        if ( v16 == -1 )
        {
          trial_splitvalue = (float)(*(&MinBound.x + v15) + *(&MaxBound.x + v15)) * 0.5;
          goto LABEL_21;
        }
        v17 = *(&this->OptimizedTriangleList.m_Memory.m_pMemory[tri_list[v16] >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                                  + 2) >> 27)]->m_Data.m_IntersectData.m_flNy
              + 8 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 4 * (tri_list[v16] & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5))
              + 2 * tv
              + tv
              + left_child);
        v18 = v17 <= *(&MaxBound.x + left_child);
        trial_splitvalue = v17;
        if ( v18 && *(&MinBound.x + left_child) <= v17 )
          break;
        v15 = left_child;
LABEL_28:
        ++tv;
        v16 = ts;
        if ( tv >= 3 )
          goto LABEL_29;
      }
      v15 = left_child;
LABEL_21:
      v19 = RayTracingEnvironment::CalculateCostsOfSplit(
              this,
              split_plane: v15,
              tri_list,
              ntris,
              MinBound,
              MaxBound,
              split_value: &trial_splitvalue,
              nleft: &trial_nleft,
              nright: &trial_nright,
              nboth: &right_child);
      *(float *)&trial_cost = v19;
      if ( best_cost > v19 )
      {
        v14 = *(float *)&trial_cost;
        best_nright = trial_nright;
        v20 = 0;
        split_plane = v15;
        best_cost = *(float *)&trial_cost;
        best_nleft = trial_nleft;
        best_nboth = right_child;
        best_splitvalue = trial_splitvalue;
        if ( ntris > 0 )
        {
          do
          {
            v21 = *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2);
            trial_cost = tri_list[v20];
            v22 = &this->OptimizedTriangleList.m_Memory.m_pMemory[trial_cost >> (v21 >> 27)][trial_cost
                                                                                           & ((32 * v21) >> 5)];
            ++v20;
            v22->m_Data.m_GeometryData.m_nTmpData1 = v22->m_Data.m_GeometryData.m_nTmpData0;
          }
          while ( v20 < ntris );
          v15 = left_child;
        }
      }
      v16 = ts;
      if ( ts != -1 )
        goto LABEL_28;
LABEL_29:
      ts = (int)new_triangle_list + v16;
      if ( (int)new_triangle_list + v16 < ntris )
      {
        v16 = ts;
        continue;
      }
      break;
    }
LABEL_30:
    left_child = ++v15;
  }
  while ( v15 < 3 );
  if ( v14 >= (float)(167 * ntris) || depth > 21 )
  {
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].Children = 4 * this->TriangleIndexList.m_Size + 3;
    LODWORD(this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue) = ntris;
    for ( depth = 0; depth < ntris; ++depth )
    {
      v47 = this->TriangleIndexList.m_Size;
      v48 = this->TriangleIndexList.m_Memory.m_nAllocationCount;
      if ( v47 + 1 > v48 )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->TriangleIndexList,
          num: v47 - v48 + 1);
      ++this->TriangleIndexList.m_Size;
      v49 = this->TriangleIndexList.m_Memory.m_pMemory;
      v50 = this->TriangleIndexList.m_Size - v47 - 1;
      this->TriangleIndexList.m_pElements = v49;
      if ( v50 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v49[v47 + 1], src: (unsigned __int8 *)&v49[v47], count: 4 * v50);
      v51 = &this->TriangleIndexList.m_Memory.m_pMemory[v47];
      if ( v51 != nullptr )
        *v51 = tri_list[depth];
    }
  }
  else
  {
    *(float *)&v23 = COERCE_FLOAT(MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)ntris >> 30 != 0 ? -1 : 4 * ntris));
    LeftMaxes = MaxBound;
    RightMins = MinBound;
    LeftMins = MinBound;
    RightMaxes = MaxBound;
    v24 = split_plane;
    v25 = 0;
    v26 = best_splitvalue;
    new_triangle_list = v23;
    *(&LeftMaxes.x + split_plane) = best_splitvalue;
    *(&RightMins.x + v24) = v26;
    tv = 0;
    if ( ntris > 0 )
    {
      best_cost = *(float *)&v23;
      LODWORD(best_splitvalue) = &v23[best_nleft];
      left_childa = &v23[ntris];
      do
      {
        v27 = tri_list[v25];
        m_nTmpData1 = this->OptimizedTriangleList.m_Memory.m_pMemory[v27 >> (*((int *)&this->OptimizedTriangleList.m_Memory
                                                                             + 2) >> 27)][v27
                                                                                        & ((32
                                                                                          * *((_DWORD *)&this->OptimizedTriangleList.m_Memory
                                                                                            + 2)) >> 5)].m_Data.m_GeometryData.m_nTmpData1;
        if ( m_nTmpData1 == -1 )
        {
          v30 = best_cost;
          *(_DWORD *)LODWORD(best_cost) = v27;
          LODWORD(best_cost) = LODWORD(v30) + 4;
        }
        else if ( m_nTmpData1 != 0 )
        {
          if ( m_nTmpData1 == 1 )
            *--left_childa = v27;
        }
        else
        {
          v29 = best_splitvalue;
          *(_DWORD *)LODWORD(best_splitvalue) = v27;
          LODWORD(best_splitvalue) = LODWORD(v29) + 4;
        }
        v25 = tv + 1;
        tv = v25;
      }
      while ( v25 < ntris );
      v24 = split_plane;
    }
    v31 = this->OptimizedKDTree.m_Size;
    v32 = v31 + 1;
    v33 = v24 + 4 * v31;
    left_childb = v31;
    v34 = this->OptimizedKDTree.m_Memory.m_pMemory;
    right_child = v32;
    v34[node_number].Children = v33;
    this->OptimizedKDTree.m_Memory.m_pMemory[node_number].SplittingPlaneValue = v26;
    v36 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_lista = (const int *)this->OptimizedKDTree.m_Size;
    v35 = tri_lista;
    if ( (int)tri_lista + 1 > v36 )
    {
      CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
        this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->OptimizedKDTree,
        num: (int)tri_lista - v36 + 1);
      v35 = tri_lista;
    }
    ++this->OptimizedKDTree.m_Size;
    v37 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v38 = this->OptimizedKDTree.m_Size - (_DWORD)v35 - 1;
    this->OptimizedKDTree.m_pElements = v37;
    if ( v38 > 0 )
    {
      _V_memmove(dest: (unsigned __int8 *)&v37[(int)v35 + 1], src: (unsigned __int8 *)&v37[(_DWORD)v35], count: 8 * v38);
      v35 = tri_lista;
    }
    p_Children = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v35].Children;
    if ( p_Children != nullptr )
    {
      *p_Children = MinBound.y;
      p_Children[1] = MinBound.z;
    }
    v41 = this->OptimizedKDTree.m_Memory.m_nAllocationCount;
    tri_listb = (const int *)this->OptimizedKDTree.m_Size;
    v40 = tri_listb;
    if ( (int)tri_listb + 1 > v41 )
    {
      CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
        this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->OptimizedKDTree,
        num: (int)tri_listb - v41 + 1);
      v40 = tri_listb;
    }
    ++this->OptimizedKDTree.m_Size;
    v42 = this->OptimizedKDTree.m_Memory.m_pMemory;
    v43 = this->OptimizedKDTree.m_Size - (_DWORD)v40 - 1;
    this->OptimizedKDTree.m_pElements = v42;
    if ( v43 > 0 )
    {
      _V_memmove(dest: (unsigned __int8 *)&v42[(int)v40 + 1], src: (unsigned __int8 *)&v42[(_DWORD)v40], count: 8 * v43);
      v40 = tri_listb;
    }
    v44 = (float *)&this->OptimizedKDTree.m_Memory.m_pMemory[(_DWORD)v40].Children;
    if ( v44 != nullptr )
    {
      *v44 = MinBound.y;
      v44[1] = MinBound.z;
    }
    if ( ntris < 20 && (best_nleft == 0 || best_nright == 0) )
      depth += 100;
    v45 = new_triangle_list;
    v46 = depth + 1;
    RayTracingEnvironment::RefineNode(
      this,
      node_number: left_childb,
      tri_list: new_triangle_list,
      ntris: best_nleft + best_nboth,
      MinBound: LeftMins,
      MaxBound: LeftMaxes,
      depth: depth + 1);
    RayTracingEnvironment::RefineNode(
      this,
      node_number: right_child,
      tri_list: &v45[best_nleft],
      ntris: best_nright + best_nboth,
      MinBound: RightMins,
      MaxBound: RightMaxes,
      depth: v46);
    C_BaseEntity::operator delete(pMem: v45);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10360170
// Name: public: void RayTracingEnvironment::SetupAccelerationStructure(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::SetupAccelerationStructure(RayTracingEnvironment *this)
{
  int *v2; // edi
  int i; // eax
  int j; // edi
  CacheOptimizedKDNode root; // [esp+Ch] [ebp-8h] BYREF

  CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->OptimizedKDTree,
    elem: this->OptimizedKDTree.m_Size,
    src: (const vgui::PropertySheet::Page_t *)&root);
  v2 = (int *)MemAlloc_Alloc(
                nSize: (unsigned __int64)(unsigned int)this->OptimizedTriangleList.m_Size >> 30 != 0
              ? -1
              : 4 * this->OptimizedTriangleList.m_Size);
  for ( i = 0; i < this->OptimizedTriangleList.m_Size; ++i )
    v2[i] = i;
  RayTracingEnvironment::CalculateTriangleListBounds(
    this,
    tris: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    minout: &this->m_MinBound,
    maxout: &this->m_MaxBound);
  RayTracingEnvironment::RefineNode(
    this,
    node_number: 0,
    tri_list: v2,
    ntris: this->OptimizedTriangleList.m_Size,
    MinBound: this->m_MinBound,
    MaxBound: this->m_MaxBound,
    depth: 0);
  C_BaseEntity::operator delete(pMem: v2);
  for ( j = 0; j < this->OptimizedTriangleList.m_Size; ++j )
    CacheOptimizedTriangle::ChangeIntoIntersectionFormat(this: &this->OptimizedTriangleList.m_Memory.m_pMemory[j >> (*((int *)&this->OptimizedTriangleList.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2)) >> 5)]);
}

//------------------------------------------------------------------------------
// Address: 0x10360250
// Name: public: void RayTracingEnvironment::AddTriangle(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddTriangle(
        RayTracingEnvironment *this,
        int id,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *color)
{
  RayTracingEnvironment::AddTriangle(this, id, v1, v2, v3, color, flags: 0, materialIndex: 0);
}

} // namespace client
