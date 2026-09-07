// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/floatbitmap4.cpp
// Functions: 8
// ============================================================

#include "bitmap\floatbitmap4.h"

//------------------------------------------------------------------------------
// Address: 0x00401320
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x00401340
// Name: public: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::Purge(CUtlBlockMemory<CacheOptimizedTriangle,int> *this)
{
  int i; // edi

  if ( this->m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_nBlocks; ++i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory[i]);
    this->m_nBlocks = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
    this->m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401390
// Name: protected: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        CUtlBlockMemory<CacheOptimizedTriangle,int> *this,
        int nBlocks)
{
  int v2; // ebx
  int m_nBlocks; // edi
  IMemAlloc_vtbl *v5; // edx
  CacheOptimizedTriangle **v6; // eax
  unsigned int v7; // ebx

  v2 = nBlocks;
  m_nBlocks = this->m_nBlocks;
  this->m_nBlocks = nBlocks;
  if ( nBlocks < m_nBlocks )
  {
    do
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory[v2++]);
    while ( v2 < m_nBlocks );
  }
  v5 = _g_pMemAlloc->__vftable;
  if ( this->m_pMemory != nullptr )
    v6 = (CacheOptimizedTriangle **)((int (__stdcall *)(CacheOptimizedTriangle **, int))v5->Realloc_2)(
                                      a1: this->m_pMemory,
                                      a2: 4 * this->m_nBlocks);
  else
    v6 = (CacheOptimizedTriangle **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * this->m_nBlocks);
  this->m_pMemory = v6;
  if ( v6 == nullptr )
    _Error(a1: "CUtlBlockMemory overflow!\n");
  if ( m_nBlocks < this->m_nBlocks )
  {
    v7 = 16 * (3 * ((32 * *((_DWORD *)this + 2)) >> 5) + 3);
    do
      this->m_pMemory[m_nBlocks++] = (CacheOptimizedTriangle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    while ( m_nBlocks < this->m_nBlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401440
// Name: SSBumpCalculationThreadFN
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
unsigned int __usercall SSBumpCalculationThreadFN@<eax>(int a1@<ebp>, float *ctx1)
{
  float *v2; // esi
  _DWORD *v3; // eax
  char *v4; // eax
  RayTracingSingleResult *v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int *v9; // ecx
  float *v10; // eax
  double v11; // xmm0_8
  __int64 v12; // xmm0_8
  int v13; // edx
  int v14; // ecx
  float v15; // xmm1_4
  RayTracingEnvironment *v16; // ecx
  int *v17; // eax
  int v18; // ecx
  int v19; // eax
  const TableVector *v20; // edx
  unsigned __int64 v21; // xmm1_8
  int v22; // eax
  int v23; // edx
  int v24; // eax
  float v25; // xmm6_4
  float v26; // xmm3_4
  float v27; // xmm7_4
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm4_4
  int v31; // eax
  int v32; // edi
  int v33; // edx
  int v34; // eax
  float *v35; // ecx
  unsigned int v36; // eax
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  int v41; // ecx
  _DWORD *v42; // eax
  float z; // ecx
  int v44; // edi
  float v45; // xmm0_4
  bool v46; // zf
  _DWORD *v47; // esi
  int v48; // edx
  int v49; // eax
  _DWORD *v50; // eax
  int v51; // edx
  int v52; // esi
  _DWORD *v53; // eax
  int v54; // esi
  int v55; // edx
  const TableVector *v56; // edx
  _DWORD *v57; // eax
  int v58; // esi
  int *v59; // edx
  RayTracingSingleResult *v61; // [esp-24h] [ebp-424h]
  _BYTE v62[12]; // [esp-Ch] [ebp-40Ch] BYREF
  RayStream ray_trace_stream_ctx; // [esp+0h] [ebp-400h] BYREF
  Vector ldir; // [esp+3A0h] [ebp-60h]
  __int128 trace_dir; // [esp+3ACh] [ebp-54h] OVERLAPPED BYREF
  Vector surf_pnt; // [esp+3BCh] [ebp-44h] BYREF
  Vector trace_end; // [esp+3C8h] [ebp-38h]
  char *v68; // [esp+3D4h] [ebp-2Ch]
  RayTracingSingleResult *this_rslt; // [esp+3D8h] [ebp-28h]
  int v70; // [esp+3DCh] [ebp-24h]
  const TableVector *v71; // [esp+3E0h] [ebp-20h]
  int y; // [esp+3E4h] [ebp-1Ch]
  int v73; // [esp+3E8h] [ebp-18h]
  float *v74; // [esp+3ECh] [ebp-14h]
  int x; // [esp+3F0h] [ebp-10h]
  int r; // [esp+3F4h] [ebp-Ch]
  void *v77; // [esp+3F8h] [ebp-8h]
  void *retaddr; // [esp+400h] [ebp+0h]

  r = a1;
  v77 = retaddr;
  v2 = ctx1;
  v3 = *((_DWORD **)ctx1 + 1);
  memset(&ray_trace_stream_ctx.PendingStreamOutputs[7][1], 0, 32);
  v4 = (char *)operator new(size: 24 * *((_DWORD *)ctx1 + 3) * *v3);
  v5 = *((RayTracingSingleResult **)ctx1 + 7);
  v68 = v4;
  v6 = *((_DWORD *)ctx1 + 8);
  for ( this_rslt = v5; (int)v5 <= v6; this_rslt = v5 )
  {
    if ( *((_DWORD *)v2 + 10) == 0 )
      _ReportProgress(a1: "Computing output", a2: v6 - *((_DWORD *)v2 + 7) + 1, a3: (char *)v5 - *((_DWORD *)v2 + 7));
    v73 = 0;
    if ( *((int *)v2 + 3) > 0 )
    {
      v7 = **((_DWORD **)v2 + 1);
      v74 = nullptr;
      do
      {
        v8 = 0;
        if ( v7 > 0 )
        {
          *(float *)&trace_dir = (float)(int)this_rslt;
          do
          {
            v9 = *((int **)v2 + 2);
            v10 = (float *)((char *)v74 + *((_DWORD *)v2 + 5));
            v11 = (float)(*(float *)(v8 * v9[73] + (_DWORD)this_rslt * v9[105] + v9[9]) * v2[4]) + 0.55;
            DWORD2(trace_dir) = trace_dir;
            *(float *)&v11 = v11;
            HIDWORD(trace_dir) = LODWORD(v11);
            *((float *)&trace_dir + 1) = (float)v8;
            surf_pnt = *(Vector *)((char *)&trace_dir + 4);
            v12 = *(_QWORD *)v10;
            ldir.z = v10[2];
            v13 = *v9;
            *(_QWORD *)&ldir.x = v12;
            if ( v13 <= v9[1] )
              v14 = v9[1];
            else
              v14 = *v9;
            v15 = (float)(3 * v14);
            v61 = (RayTracingSingleResult *)&v68[24 * v73 + 24 * v8 * *((_DWORD *)v2 + 3)];
            surf_pnt.x = (float)(ldir.x * v15) + (float)v8;
            v16 = *(RayTracingEnvironment **)v2;
            surf_pnt.y = surf_pnt.y + (float)(ldir.y * v15);
            surf_pnt.z = surf_pnt.z + (float)(ldir.z * v15);
            RayTracingEnvironment::AddToRayStream(
              this: v16,
              s: (RayStream *)v62,
              start: (const Vector *)((char *)&trace_dir + 4),
              end: &surf_pnt,
              rslt_out: v61,
              cullMode: RTE_CULL_NONE);
            v7 = **((_DWORD **)v2 + 1);
            ++v8;
          }
          while ( v8 < v7 );
        }
        v74 += 3;
        ++v73;
      }
      while ( v73 < *((_DWORD *)v2 + 3) );
      v5 = this_rslt;
    }
    if ( *((_DWORD *)v2 + 3) != 0 )
      RayTracingEnvironment::FinishRayStream(
        this: *(RayTracingEnvironment **)v2,
        s: (RayStream *)v62,
        cullMode: RTE_CULL_NONE);
    v17 = *((int **)v2 + 2);
    v18 = 0;
    y = 0;
    if ( *v17 > 0 )
    {
      do
      {
        v19 = ~(2 * (unsigned __int8)*((_DWORD *)v2 + 9)) & 2 | 1;
        v20 = g_localBumpBasis;
        v73 = 408;
        v71 = g_localBumpBasis;
        LODWORD(trace_end.x) = v19;
        while ( 1 )
        {
          v21 = *(_QWORD *)&v20->x;
          v22 = v18 + (_DWORD)v5 * **((_DWORD **)v2 + 2);
          ray_trace_stream_ctx.PendingRays[7].direction.z.m128_i32[3] = LODWORD(v20->z);
          v23 = 3 * v22;
          v24 = *((_DWORD *)v2 + 6);
          v25 = *(float *)(v24 + 4 * v23 + 4);
          v26 = *(float *)(v24 + 4 * v23);
          v27 = *(float *)(v24 + 4 * v23 + 8);
          *(unsigned __int64 *)((char *)ray_trace_stream_ctx.PendingRays[7].direction.z.m128_u64 + 4) = v21;
          v28 = (float)((float)(v25 * *((float *)&v21 + 1)) + (float)(v26 * *(float *)&v21))
              + (float)(v27 * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[3]);
          v29 = 0.0;
          v30 = 0.0;
          if ( v28 >= 0.0 )
          {
            v32 = *((_DWORD *)v2 + 3);
            if ( v32 != 0 )
            {
              LODWORD(trace_end.y) = &v68[24 * v18 * v32];
              v33 = 0;
              if ( v32 >= 4 )
              {
                v70 = (_DWORD)v2[9] & 1;
                v34 = *((_DWORD *)v2 + 5);
                x = LODWORD(trace_end.y) + 36;
                v35 = (float *)(v34 + 8);
                v74 = (float *)(v34 + 20);
                v36 = ((unsigned int)(v32 - 4) >> 2) + 1;
                v33 = 4 * v36;
                do
                {
                  if ( v70 != 0 )
                    v37 = *v35;
                  else
                    v37 = (float)((float)(*(v35 - 1) * *((float *)&v21 + 1))
                                + (float)(*(v35 - 2) * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[1]))
                        + (float)(ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[3] * *v35);
                  if ( v37 > 0.0 )
                  {
                    v30 = v30 + v37;
                    if ( *(_DWORD *)(x - 24) == -1 )
                      v29 = v37 + v29;
                  }
                  if ( v70 != 0 )
                    v38 = v35[3];
                  else
                    v38 = (float)((float)(*(v74 - 1) * *((float *)&v21 + 1))
                                + (float)(v35[1] * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[1]))
                        + (float)(*v74 * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[3]);
                  if ( v38 > 0.0 )
                  {
                    v30 = v30 + v38;
                    if ( *(_DWORD *)x == -1 )
                      v29 = v38 + v29;
                  }
                  if ( v70 != 0 )
                    v39 = v35[6];
                  else
                    v39 = (float)((float)(v74[2] * *((float *)&v21 + 1))
                                + (float)(v35[4] * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[1]))
                        + (float)(v74[3] * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[3]);
                  if ( v39 > 0.0 )
                  {
                    v30 = v30 + v39;
                    if ( *(_DWORD *)(x + 24) == -1 )
                      v29 = v39 + v29;
                  }
                  if ( v70 != 0 )
                    v40 = v35[9];
                  else
                    v40 = (float)((float)(v74[5] * *((float *)&v21 + 1))
                                + (float)(v35[7] * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[1]))
                        + (float)(v74[6] * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[3]);
                  if ( v40 > 0.0 )
                  {
                    v30 = v30 + v40;
                    if ( *(_DWORD *)(x + 48) == -1 )
                      v29 = v40 + v29;
                  }
                  v74 += 12;
                  x += 96;
                  v35 += 12;
                  --v36;
                }
                while ( v36 != 0 );
                v32 = *((_DWORD *)v2 + 3);
                v18 = y;
              }
              if ( v33 < v32 )
              {
                v41 = *((_DWORD *)v2 + 5);
                v70 = (_DWORD)v2[9] & 1;
                LODWORD(trace_end.z) = v41 + 12 * v33;
                v42 = (_DWORD *)(LODWORD(trace_end.y) + 24 * v33 + 12);
                z = trace_end.z;
                v44 = v32 - v33;
                do
                {
                  if ( v70 != 0 )
                    v45 = *(float *)(LODWORD(z) + 8);
                  else
                    v45 = (float)((float)(*(float *)(LODWORD(z) + 4) * *((float *)&v21 + 1))
                                + (float)(*(float *)LODWORD(z)
                                        * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[1]))
                        + (float)(*(float *)(LODWORD(z) + 8)
                                * ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[3]);
                  if ( v45 > 0.0 )
                  {
                    v30 = v30 + v45;
                    if ( *v42 == -1 )
                      v29 = v45 + v29;
                  }
                  LODWORD(z) += 12;
                  v42 += 6;
                  --v44;
                }
                while ( v44 != 0 );
                v18 = y;
              }
            }
            else
            {
              v30 = 1.0;
              v29 = 1.0;
            }
            *(float *)((_DWORD)this_rslt * *(_DWORD *)(v73 + *((_DWORD *)v2 + 1))
                     + v18 * *(_DWORD *)(v73 + *((_DWORD *)v2 + 1) - 128)
                     + *(_DWORD *)(v73 + *((_DWORD *)v2 + 1) - 384)) = (float)(v28 * v29) / v30;
            v5 = this_rslt;
            v31 = v73;
          }
          else
          {
            v31 = v73;
            *(_DWORD *)((_DWORD)v5 * *(_DWORD *)(v73 + *((_DWORD *)v2 + 1))
                      + v18 * *(_DWORD *)(v73 + *((_DWORD *)v2 + 1) - 128)
                      + *(_DWORD *)(v73 + *((_DWORD *)v2 + 1) - 384)) = 0;
            v18 = y;
          }
          ++v71;
          v46 = LODWORD(trace_end.x)-- == 1;
          v73 = v31 + 4;
          if ( v46 )
            break;
          v20 = v71;
        }
        if ( ((_BYTE)v2[9] & 1) != 0 )
        {
          v47 = *((_DWORD **)v2 + 1);
          v48 = (_DWORD)v5 * v47[102] + v18 * v47[70];
          v49 = v47[6];
          x = (int)v47;
          *(float *)((_DWORD)v5 * v47[103] + v18 * v47[71] + v47[7]) = *(float *)(v48 + v49);
          v50 = *((_DWORD **)ctx1 + 1);
          v51 = (_DWORD)v5 * v50[102] + y * v50[70];
          v52 = v50[6];
          x = (int)v50;
          *(float *)((_DWORD)v5 * v50[104] + y * v50[72] + v50[8]) = *(float *)(v51 + v52);
          v53 = *((_DWORD **)ctx1 + 1);
          v54 = (_DWORD)v5 * v53[102];
          v55 = y * v53[70];
          x = (int)v53;
          *(float *)((_DWORD)v5 * v53[105] + y * v53[73] + v53[9]) = *(float *)(v54 + v55 + v53[6]);
        }
        else
        {
          v56 = *((const TableVector **)v2 + 1);
          v57 = *((_DWORD **)v2 + 2);
          v58 = v57[105];
          v71 = v56;
          *(float *)((_DWORD)v5 * LODWORD(v56[35].x) + v18 * LODWORD(v56[24].y) + LODWORD(v56[3].x)) = *(float *)((_DWORD)v5 * v58 + v18 * v57[73] + v57[9]);
        }
        v2 = ctx1;
        v59 = *((int **)ctx1 + 2);
        v18 = y + 1;
        y = v18;
      }
      while ( v18 < *v59 );
    }
    v6 = *((_DWORD *)v2 + 8);
    v5 = (RayTracingSingleResult *)((char *)v5 + 1);
  }
  operator delete(p: v68);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401AF0
// Name: public: void FloatBitMap_t::ComputeVertexPositionsAndNormals(float,class Vector __near * __near *,class Vector __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::ComputeVertexPositionsAndNormals(
        FloatBitMap_t *this,
        float flHeightScale,
        Vector **ppPosOut,
        Vector **ppNormalOut)
{
  FloatBitMap_t *v4; // edi
  int v5; // eax
  int v6; // ecx
  Vector *v7; // eax
  int v8; // edx
  Vector *v9; // esi
  int m_nColumns; // eax
  int v11; // ecx
  float v12; // xmm0_4
  float *p_x; // eax
  Vector *v14; // eax
  bool v15; // cc
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  int m_nRows; // ebx
  int v20; // esi
  int v21; // edi
  int v22; // eax
  int v23; // edx
  Vector *v24; // ebx
  __int64 v25; // xmm0_8
  float v26; // xmm1_4
  int v27; // ecx
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  int v31; // ecx
  float v32; // xmm3_4
  float v33; // xmm5_4
  float v34; // xmm1_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  bool v39; // zf
  FloatBitMap_t *v40; // edx
  __int64 e2; // [esp+Ch] [ebp-6Ch]
  float e2_8; // [esp+14h] [ebp-64h]
  __int64 e1; // [esp+18h] [ebp-60h]
  float e1_8; // [esp+20h] [ebp-58h]
  __int64 p0; // [esp+24h] [ebp-54h]
  float p0_8; // [esp+2Ch] [ebp-4Ch]
  Vector n2; // [esp+30h] [ebp-48h] BYREF
  Vector n1; // [esp+3Ch] [ebp-3Ch] BYREF
  Vector avg_normal; // [esp+48h] [ebp-30h] BYREF
  int v50; // [esp+54h] [ebp-24h]
  Vector *v51; // [esp+58h] [ebp-20h]
  Vector *v52; // [esp+5Ch] [ebp-1Ch]
  int v53; // [esp+60h] [ebp-18h]
  int y0; // [esp+64h] [ebp-14h]
  int xofs; // [esp+68h] [ebp-10h]
  int v56; // [esp+6Ch] [ebp-Ch]
  int y; // [esp+70h] [ebp-8h]
  FloatBitMap_t *v58; // [esp+74h] [ebp-4h]
  int x; // [esp+80h] [ebp+8h]

  v4 = this;
  v5 = 12 * this->m_nRows * this->m_nColumns;
  v6 = (12 * (unsigned __int64)(unsigned int)(this->m_nRows * this->m_nColumns)) >> 32 != 0;
  v58 = v4;
  v7 = (Vector *)operator new(size: v5 | -v6);
  v8 = 0;
  v9 = v7;
  v52 = v7;
  y = 0;
  if ( v4->m_nRows > 0 )
  {
    m_nColumns = v4->m_nColumns;
    do
    {
      v11 = 0;
      if ( m_nColumns > 0 )
      {
        v12 = (float)v8;
        do
        {
          p_x = &v9[v11 + v8 * m_nColumns].x;
          *p_x = (float)v11;
          p_x[1] = v12;
          v8 = y;
          p_x[2] = *(float *)&v4->m_pAttributePtrs[3][y * v4->m_nRowStrideInBytes[3] + v11 * v4->m_nStrideInBytes[3]]
                 * flHeightScale;
          m_nColumns = v4->m_nColumns;
          ++v11;
        }
        while ( v11 < v4->m_nColumns );
      }
      y = ++v8;
    }
    while ( v8 < v4->m_nRows );
  }
  v14 = (Vector *)operator new(size: 12 * v4->m_nRows * v4->m_nColumns);
  v15 = v4->m_nRows <= 0;
  v51 = v14;
  y = 0;
  if ( !v15 )
  {
    do
    {
      x = 0;
      if ( v4->m_nColumns > 0 )
      {
        do
        {
          memset(&avg_normal, 0, sizeof(avg_normal));
          xofs = -1;
          while ( 1 )
          {
            v16 = y - 1;
            v50 = x + xofs;
            v56 = y - 1;
            v53 = 3;
            while ( 1 )
            {
              v17 = v50;
              if ( v50 < 0 )
                v17 = v4->m_nColumns + v50;
              y0 = v16;
              if ( v16 < 0 )
                y0 = v16 + v4->m_nRows;
              v18 = v4->m_nColumns;
              m_nRows = v4->m_nRows;
              v20 = v17 % v4->m_nColumns;
              v21 = y0 % m_nRows;
              v22 = y0 % m_nRows + 1;
              y0 = (v20 + 1) % v18;
              v23 = v22 % m_nRows;
              v24 = v52;
              v25 = *(_QWORD *)&v52[v20 + v21 * v18].x;
              p0_8 = v52[v20 + v21 * v18].z;
              p0 = v25;
              e1_8 = v52[y0 + v21 * v18].z;
              e1 = *(_QWORD *)&v52[y0 + v21 * v18].x;
              e2 = *(_QWORD *)&v52[v20 + v23 * v18].x;
              e2_8 = v52[v20 + v23 * v18].z;
              v26 = (float)((float)(*((float *)&e2 + 1) - *((float *)&v25 + 1)) * (float)(*(float *)&e1 - *(float *)&v25))
                  - (float)((float)(*((float *)&e1 + 1) - *((float *)&v25 + 1)) * (float)(*(float *)&e2 - *(float *)&v25));
              n1.x = (float)((float)(e2_8 - p0_8) * (float)(*((float *)&e1 + 1) - *((float *)&v25 + 1)))
                   - (float)((float)(*((float *)&e2 + 1) - *((float *)&v25 + 1)) * (float)(e1_8 - p0_8));
              n1.y = (float)((float)(e1_8 - p0_8) * (float)(*(float *)&e2 - *(float *)&v25))
                   - (float)((float)(e2_8 - p0_8) * (float)(*(float *)&e1 - *(float *)&v25));
              n1.z = v26;
              if ( v26 < 0.0 )
              {
                n1.x = -(float)((float)((float)(e2_8 - p0_8) * (float)(*((float *)&e1 + 1) - *((float *)&v25 + 1)))
                              - (float)((float)(*((float *)&e2 + 1) - *((float *)&v25 + 1)) * (float)(e1_8 - p0_8)));
                n1.y = -e1_8;
                n1.z = -v26;
              }
              v27 = v23 * v18;
              v28 = v52[v27 + x].x - *(float *)&v25;
              v29 = v52[v27 + x].y - *((float *)&v25 + 1);
              v30 = v52[v27 + x].z - p0_8;
              v31 = v27 + y0;
              v32 = v52[v31].z - p0_8;
              v33 = v28;
              v34 = v52[v31].y - *((float *)&p0 + 1);
              v35 = v52[v31].x - *(float *)&p0;
              v36 = v34 * v30;
              v37 = (float)(v34 * v33) - (float)(v29 * v35);
              v38 = (float)(v30 * v35) - (float)(v32 * v33);
              n2.x = (float)(v32 * v29) - v36;
              n2.y = v38;
              n2.z = v37;
              if ( v37 < 0.0 )
              {
                n2.x = -(float)((float)(v32 * v29) - v36);
                n2.y = -v38;
                n2.z = -v37;
              }
              VectorNormalize(vec: &n1);
              VectorNormalize(vec: &n2);
              ++v56;
              v39 = v53-- == 1;
              avg_normal.x = n2.x + (float)(n1.x + avg_normal.x);
              avg_normal.y = n2.y + (float)(n1.y + avg_normal.y);
              avg_normal.z = (float)(avg_normal.z + n1.z) + n2.z;
              if ( v39 )
                break;
              v4 = v58;
              v16 = v56;
            }
            if ( ++xofs > 1 )
              break;
            v4 = v58;
          }
          VectorNormalize(vec: &avg_normal);
          v40 = v58;
          v51[x + y * v58->m_nColumns] = avg_normal;
          ++x;
          v4 = v40;
        }
        while ( x < v40->m_nColumns );
        v9 = v24;
      }
      ++y;
    }
    while ( y < v4->m_nRows );
    v14 = v51;
  }
  *ppPosOut = v9;
  *ppNormalOut = v14;
}

//------------------------------------------------------------------------------
// Address: 0x00401F10
// Name: public: class FloatBitMap_t __near * FloatBitMap_t::ComputeBumpmapFromHeightInAlphaChannel(float)const
// Source: json
//------------------------------------------------------------------------------
FloatBitMap_t *__thiscall FloatBitMap_t::ComputeBumpmapFromHeightInAlphaChannel(FloatBitMap_t *this, float flBumpScale)
{
  FloatBitMap_t *v2; // edi
  FloatBitMap_t *v3; // eax
  FloatBitMap_t *result; // eax
  float v5; // esi
  int m_nColumns; // edx
  int v7; // ecx
  int v8; // edx
  float x; // xmm2_4
  unsigned int v10; // ebx
  double v11; // st7
  unsigned int v12; // edi
  Vector *normals; // [esp+18h] [ebp-8h] BYREF
  const Vector *N; // [esp+1Ch] [ebp-4h]

  v2 = this;
  FloatBitMap_t::ComputeVertexPositionsAndNormals(
    this,
    flHeightScale: flBumpScale,
    ppPosOut: (Vector **)&flBumpScale,
    ppNormalOut: &normals);
  v3 = (FloatBitMap_t *)operator new(size: 0x324u);
  if ( v3 != nullptr )
    result = FloatBitMap_t::FloatBitMap_t(
               this: v3,
               nWidth: v2->m_nColumns,
               nHeight: v2->m_nRows,
               nDepth: 1,
               nAttributeMask: 15);
  else
    result = nullptr;
  v5 = 0.0;
  flBumpScale = 0.0;
  if ( v2->m_nRows > 0 )
  {
    m_nColumns = v2->m_nColumns;
    do
    {
      v7 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v8 = v7 + LODWORD(v5) * m_nColumns;
          x = normals[v8].x;
          v10 = result->m_nRowStrideInBytes[0];
          N = &normals[v8];
          *(float *)&result->m_pAttributePtrs[0][LODWORD(v5) * v10 + v7 * result->m_nStrideInBytes[0]] = (float)(x + 1.0) * 0.5;
          *(float *)&result->m_pAttributePtrs[1][LODWORD(v5) * result->m_nRowStrideInBytes[1]
                                               + v7 * result->m_nStrideInBytes[1]] = (float)(N->y + 1.0) * 0.5;
          *(float *)&result->m_pAttributePtrs[2][LODWORD(v5) * result->m_nRowStrideInBytes[2]
                                               + v7 * result->m_nStrideInBytes[2]] = (float)(N->z + 1.0) * 0.5;
          v11 = *(float *)&v2->m_pAttributePtrs[3][LODWORD(v5) * v2->m_nRowStrideInBytes[3]
                                                 + v7 * v2->m_nStrideInBytes[3]];
          v5 = flBumpScale;
          v12 = LODWORD(flBumpScale) * result->m_nRowStrideInBytes[3] + v7 * result->m_nStrideInBytes[3];
          ++v7;
          *(float *)&result->m_pAttributePtrs[3][v12] = v11;
          v2 = this;
          m_nColumns = this->m_nColumns;
        }
        while ( v7 < this->m_nColumns );
      }
      ++LODWORD(v5);
      flBumpScale = v5;
    }
    while ( SLODWORD(v5) < v2->m_nRows );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402080
// Name: public: RayTracingEnvironment::RayTracingEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
RayTracingEnvironment *__thiscall RayTracingEnvironment::RayTracingEnvironment(RayTracingEnvironment *this)
{
  CUtlBlockVector<CacheOptimizedTriangle> *p_OptimizedTriangleList; // ecx
  unsigned int v3; // eax
  int v4; // ecx
  __m128 v5; // xmm1

  p_OptimizedTriangleList = &this->OptimizedTriangleList;
  this->OptimizedKDTree.m_Memory.m_pMemory = nullptr;
  this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  this->OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  this->OptimizedKDTree.m_Size = 0;
  this->OptimizedKDTree.m_pElements = nullptr;
  p_OptimizedTriangleList->m_Memory.m_pMemory = nullptr;
  p_OptimizedTriangleList->m_Memory.m_nBlocks = 0;
  *((_DWORD *)&p_OptimizedTriangleList->m_Memory + 2) = 0;
  CUtlBlockMemory<CacheOptimizedTriangle,int>::Purge(this: &p_OptimizedTriangleList->m_Memory);
  v3 = 1023;
  v4 = 1024;
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = 1023;
  do
  {
    v4 >>= 1;
    v3 = ((v3 & 0xF8000000) + 0x8000000) ^ v3 & 0x7FFFFFF;
  }
  while ( v4 > 1 );
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = v3;
  this->OptimizedTriangleList.m_Size = 0;
  this->OptimizedTriangleList.m_pElements = nullptr;
  this->TriangleIndexList.m_Memory.m_pMemory = nullptr;
  this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  this->TriangleIndexList.m_Memory.m_nGrowSize = 0;
  this->TriangleIndexList.m_Size = 0;
  this->TriangleIndexList.m_pElements = nullptr;
  this->LightList.m_Memory.m_pMemory = nullptr;
  this->LightList.m_Memory.m_nAllocationCount = 0;
  this->LightList.m_Memory.m_nGrowSize = 0;
  this->LightList.m_Size = 0;
  this->LightList.m_pElements = nullptr;
  this->TriangleColors.m_Memory.m_pMemory = nullptr;
  this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  this->TriangleColors.m_Memory.m_nGrowSize = 0;
  this->TriangleColors.m_Size = 0;
  this->TriangleColors.m_pElements = nullptr;
  this->TriangleMaterials.m_Memory.m_pMemory = nullptr;
  this->TriangleMaterials.m_Memory.m_nAllocationCount = 0;
  this->TriangleMaterials.m_Memory.m_nGrowSize = 0;
  this->TriangleMaterials.m_Size = 0;
  this->TriangleMaterials.m_pElements = nullptr;
  this->BackgroundColor.x = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  v5 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  this->BackgroundColor.y = v5;
  this->BackgroundColor.z = v5;
  this->Flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402180
// Name: public: class FloatBitMap_t __near * FloatBitMap_t::ComputeSelfShadowedBumpmapFromHeightInAlphaChannel(float,int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
FloatBitMap_t *__userpurge FloatBitMap_t::ComputeSelfShadowedBumpmapFromHeightInAlphaChannel@<eax>(
        FloatBitMap_t *this@<ecx>,
        int a2@<ebp>,
        double a3@<esi:edi>,
        float bump_scale,
        int nrays_to_trace_per_pixel,
        unsigned int nOptionFlags)
{
  float y; // esi
  float x; // edi
  int v8; // esi
  bool v9; // cc
  int v10; // ecx
  bool v11; // cc
  Vector *v12; // esi
  float v13; // xmm5_4
  float v14; // xmm6_4
  int v15; // ecx
  int v16; // edi
  int v17; // edx
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // edx
  int v21; // ecx
  float v22; // edx
  float v23; // xmm3_4
  int z_low; // esi
  FloatBitMap_t *v25; // eax
  double Element; // st7
  double v27; // st7
  double z; // xmm0_8
  double v29; // xmm0_8
  double v30; // xmm0_8
  _DWORD *v31; // eax
  int v32; // xmm1_4
  bool v33; // zf
  int v34; // ecx
  int CPUInformation; // eax
  int v36; // ecx
  int v37; // eax
  int *v38; // eax
  int v39; // ecx
  int v40; // edx
  int v41; // ecx
  int v42; // ecx
  int SimpleThread; // eax
  int v44; // ecx
  int v45; // edx
  int v46; // ecx
  int v47; // edx
  int v48; // eax
  int v49; // edx
  int v50; // edi
  int v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  _DWORD *v54; // eax
  int v55; // edi
  float v56; // xmm0_4
  int v57; // edx
  void *m_nGrowSize; // eax
  int v59; // esi
  void *v60; // eax
  void *v61; // eax
  void *v62; // eax
  void **v63; // eax
  void *v64; // eax
  int v66; // [esp+8h] [ebp-7A0h]
  int v67; // [esp+8h] [ebp-7A0h]
  long double v68; // [esp+Ch] [ebp-79Ch]
  long double v69; // [esp+Ch] [ebp-79Ch]
  long double v70; // [esp+Ch] [ebp-79Ch]
  long double v71; // [esp+Ch] [ebp-79Ch]
  __int64 v72; // [esp+1Ch] [ebp-78Ch]
  _BYTE v73[1401]; // [esp+24h] [ebp-784h] OVERLAPPED BYREF
  ThreadHandle_t__ *waithandles[32]; // [esp+5A8h] [ebp-200h]
  Vector trace_dir; // [esp+62Ch] [ebp-17Ch] BYREF
  HaltonSequenceGenerator_t v76; // [esp+638h] [ebp-170h] BYREF
  DirectionalSampler_t my_sphere_sampler; // [esp+644h] [ebp-164h] BYREF
  _DWORD v78[3]; // [esp+65Ch] [ebp-14Ch] BYREF
  RayTracingEnvironment rtEnv; // [esp+668h] [ebp-140h]
  Vector v80; // [esp+738h] [ebp-70h] BYREF
  Vector v1; // [esp+744h] [ebp-64h] BYREF
  Vector v3; // [esp+750h] [ebp-58h] BYREF
  Vector *normals; // [esp+75Ch] [ebp-4Ch]
  Vector v2; // [esp+760h] [ebp-48h] BYREF
  Vector v0; // [esp+76Ch] [ebp-3Ch] BYREF
  Vector *verts; // [esp+778h] [ebp-30h]
  int v87; // [esp+77Ch] [ebp-2Ch]
  int tcnt; // [esp+780h] [ebp-28h]
  int i; // [esp+784h] [ebp-24h]
  int min_x; // [esp+788h] [ebp-20h]
  int max_x; // [esp+78Ch] [ebp-1Ch]
  int max_y; // [esp+790h] [ebp-18h]
  int t; // [esp+794h] [ebp-14h]
  int x1; // [esp+798h] [ebp-10h]
  int tilex; // [esp+79Ch] [ebp-Ch]
  int nX; // [esp+7A0h] [ebp-8h]
  int retaddr; // [esp+7A8h] [ebp+0h]

  tilex = a2;
  nX = retaddr;
  v68 = a3;
  y = *(float *)&this;
  LODWORD(v0.y) = this;
  LODWORD(v0.z) = 1;
  FloatBitMap_t::ComputeVertexPositionsAndNormals(
    this,
    flHeightScale: bump_scale,
    ppPosOut: (Vector **)&v0,
    ppNormalOut: (Vector **)&v3);
  RayTracingEnvironment::RayTracingEnvironment(this: (RayTracingEnvironment *)v78);
  v78[0] |= 2u;
  x = v0.x;
  if ( nrays_to_trace_per_pixel != 0 )
  {
    RayTracingEnvironment::MakeRoomForTriangles(
      this: (RayTracingEnvironment *)v78,
      ntris: 18 * *(_DWORD *)LODWORD(y) * *(_DWORD *)(LODWORD(y) + 4));
    max_y = -1;
    do
    {
      min_x = -1;
      do
      {
        v8 = *(_DWORD *)LODWORD(v0.y);
        max_x = *(_DWORD *)(LODWORD(v0.y) + 4);
        v9 = max_y <= 0;
        v10 = v8 - 1;
        v87 = 0;
        tcnt = v8 - 1;
        x1 = 0;
        i = max_x - 1;
        if ( max_y < 0 )
        {
          v9 = max_y <= 0;
          v87 = v8 / 2;
        }
        if ( !v9 )
        {
          v10 = v8 / 2;
          tcnt = v8 / 2;
        }
        v11 = min_x <= 0;
        if ( min_x < 0 )
        {
          x1 = max_x / 2;
          v11 = min_x <= 0;
        }
        if ( !v11 )
          i = max_x / 2;
        for ( t = x1; t <= i; ++t )
        {
          v12 = (Vector *)v87;
          if ( v87 <= v10 )
          {
            v13 = (float)t;
            v14 = (float)(t + 1);
            *((float *)&rtEnv.TriangleMaterials + 5) = (float)t;
            for ( *((float *)&rtEnv.TriangleMaterials + 6) = v14; ; v14 = *((float *)&rtEnv.TriangleMaterials + 6) )
            {
              v15 = *(_DWORD *)LODWORD(v0.y);
              v16 = *(_DWORD *)(LODWORD(v0.y) + 4);
              v17 = max_y * *(_DWORD *)LODWORD(v0.y);
              v18 = (float)(min_x * v16);
              verts = (Vector *)((char *)&v12->x + 1);
              v19 = (float)v17;
              max_x = ((int)&v12->x + 1) % v15;
              v20 = (t + 1) % v16;
              x = v0.x;
              x1 = v20;
              v2 = *(Vector *)(LODWORD(v0.x) + 12 * ((_DWORD)v12 + t * v15));
              v80 = *(Vector *)(LODWORD(v0.x) + 12 * (max_x + t * v15));
              *(_QWORD *)&v3.y = *(_QWORD *)(LODWORD(v0.x) + 12 * (max_x + v20 * v15));
              normals = *(Vector **)(LODWORD(v0.x) + 12 * (max_x + v20 * v15) + 8);
              v21 = 3 * ((_DWORD)v12 + v20 * v15);
              *(_QWORD *)&v1.x = *(_QWORD *)(LODWORD(v0.x) + 4 * v21);
              v22 = *(float *)(LODWORD(v0.x) + 4 * v21 + 8);
              v23 = (float)(int)v12;
              v2.x = v19 + (float)(int)v12;
              v2.y = v18 + v13;
              v80.x = v19 + (float)((int)&v12->x + 1);
              v80.y = v18 + v13;
              z_low = LODWORD(v0.z);
              v3.y = v80.x;
              v1.x = v19 + v23;
              v3.z = v18 + v14;
              v1.y = v18 + v14;
              v1.z = v22;
              trace_dir.x = 1.0;
              trace_dir.y = 1.0;
              trace_dir.z = 1.0;
              RayTracingEnvironment::AddTriangle(
                this: (RayTracingEnvironment *)v78,
                id: SLODWORD(v0.z),
                v1: &v2,
                v2: &v80,
                v3: (Vector *)&v3.y,
                color: &trace_dir);
              ++z_low;
              my_sphere_sampler.vrot.seed = 1065353216;
              my_sphere_sampler.vrot.base = 1065353216;
              my_sphere_sampler.vrot.fbase = 1.0;
              RayTracingEnvironment::AddTriangle(
                this: (RayTracingEnvironment *)v78,
                id: z_low,
                v1: &v2,
                v2: &v1,
                v3: (Vector *)&v3.y,
                color: (const Vector *)&my_sphere_sampler.vrot);
              v10 = tcnt;
              LODWORD(v0.z) = z_low + 1;
              v12 = verts;
              if ( (int)verts > tcnt )
                break;
              v13 = *((float *)&rtEnv.TriangleMaterials + 5);
            }
          }
        }
        ++min_x;
      }
      while ( min_x <= 1 );
      ++max_y;
    }
    while ( max_y <= 1 );
    _ReportProgress(a1: "Creating kd-tree", a2: 0, a3: 0);
    RayTracingEnvironment::SetupAccelerationStructure(this: (RayTracingEnvironment *)v78);
    y = v0.y;
  }
  v25 = (FloatBitMap_t *)operator new(size: 0x324u);
  if ( v25 != nullptr )
    max_y = (int)FloatBitMap_t::FloatBitMap_t(
                   this: v25,
                   nWidth: *(_DWORD *)LODWORD(y),
                   nHeight: *(_DWORD *)(LODWORD(y) + 4),
                   nDepth: 1,
                   nAttributeMask: 15);
  else
    max_y = 0;
  max_x = (int)operator new(size: 12 * nrays_to_trace_per_pixel);
  HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: &v76, b: 2);
  HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: &my_sphere_sampler.zdot, b: 3);
  if ( nrays_to_trace_per_pixel > 0 )
  {
    v87 = max_x + 8;
    x1 = nrays_to_trace_per_pixel;
    do
    {
      v66 = v76.seed++;
      Element = HaltonSequenceGenerator_t::GetElement(this: &v76, elem: v66);
      v67 = my_sphere_sampler.zdot.seed++;
      v0.z = Element + Element - 1.0;
      v27 = HaltonSequenceGenerator_t::GetElement(this: &my_sphere_sampler.zdot, elem: v67);
      z = v0.z;
      *(float *)&tcnt = v27 * 6.283185307179586;
      __libm_sse2_acos(x: v68);
      *(float *)&z = z;
      __libm_sse2_sin(x: v69);
      verts = (Vector *)LODWORD(z);
      v29 = *(float *)&tcnt;
      __libm_sse2_cos(x: v70);
      *(float *)&v29 = v29;
      *(float *)&waithandles[30] = *(float *)&v29 * *(float *)&verts;
      v30 = *(float *)&tcnt;
      __libm_sse2_sin(x: v71);
      v31 = (_DWORD *)v87;
      v32 = LODWORD(v0.z) & _mask__AbsFloat_;
      *(float *)&v30 = v30;
      *(float *)&v30 = *(float *)&v30 * *(float *)&verts;
      *(ThreadHandle_t__ **)(v87 - 8) = waithandles[30];
      *(v31 - 1) = LODWORD(v30);
      *v31 = v32;
      v33 = x1-- == 1;
      v87 = (int)(v31 + 3);
    }
    while ( !v33 );
  }
  LODWORD(v72) = v78;
  HIDWORD(v72) = max_y;
  *(float *)v73 = y;
  *(_DWORD *)&v73[4] = nrays_to_trace_per_pixel;
  v34 = *(_DWORD *)(LODWORD(y) + 4);
  *(float *)&v73[8] = bump_scale;
  *(_DWORD *)&v73[12] = max_x;
  *(float *)&v73[16] = v3.x;
  *(_DWORD *)&v73[20] = 0;
  *(_DWORD *)&v73[24] = v34 - 1;
  *(_DWORD *)&v73[28] = nOptionFlags;
  CPUInformation = _GetCPUInformation();
  v36 = 32;
  if ( *(_BYTE *)(CPUInformation + 6) <= 0x20u )
  {
    t = *(unsigned __int8 *)(_GetCPUInformation() + 6);
    v36 = t;
  }
  else
  {
    t = 32;
  }
  v37 = *(_DWORD *)(LODWORD(y) + 4) / v36;
  x1 = 0;
  min_x = 0;
  tcnt = v37;
  v38 = (int *)&v73[24];
  for ( i = (int)&v73[24]; ; v38 = (int *)i )
  {
    v39 = min_x;
    if ( min_x != 0 )
    {
      *((_QWORD *)v38 - 4) = v72;
      qmemcpy(v38 - 6, v73, 36);
    }
    v40 = t;
    v38[2] = v39;
    v41 = x1;
    *(v38 - 1) = x1;
    if ( min_x == v40 - 1 )
    {
      v42 = *(_DWORD *)(LODWORD(y) + 4) - 1;
    }
    else
    {
      v42 = tcnt + v41 - 1;
      if ( *(_DWORD *)(LODWORD(y) + 4) - 1 < v42 )
        v42 = *(_DWORD *)(LODWORD(y) + 4) - 1;
    }
    t = 0;
    max_y = i - 32;
    max_x = (int)SSBumpCalculationThreadFN;
    *v38 = v42;
    SimpleThread = _CreateSimpleThread(a1: max_x, a2: max_y);
    v44 = min_x;
    i += 44;
    *(_DWORD *)&v73[4 * min_x + 1400] = SimpleThread;
    x1 += tcnt;
    min_x = v44 + 1;
    if ( v44 + 1 >= t )
      break;
  }
  for ( x1 = 0; x1 < t; ++x1 )
  {
    v45 = *(_DWORD *)&v73[4 * x1 + 1400];
    t = -1;
    _ThreadJoin(a1: v45);
  }
  if ( (nOptionFlags & 2) != 0 )
  {
    v46 = 0;
    x1 = 0;
    if ( *(int *)(LODWORD(y) + 4) > 0 )
    {
      v47 = *(_DWORD *)LODWORD(y);
      do
      {
        v48 = 0;
        t = 0;
        if ( v47 > 0 )
        {
          do
          {
            v49 = v46 * *(_DWORD *)(LODWORD(y) + 408) + v48 * *(_DWORD *)(LODWORD(y) + 280);
            v50 = v48 * *(_DWORD *)(LODWORD(y) + 284);
            v51 = x1 * *(_DWORD *)(LODWORD(y) + 412);
            v52 = *(float *)(v49 + *(_DWORD *)(LODWORD(y) + 24));
            y = v0.y;
            v46 = x1;
            v53 = (float)(v52 + *(float *)(v51 + v50 + *(_DWORD *)(LODWORD(y) + 28)))
                + *(float *)(x1 * *(_DWORD *)(LODWORD(y) + 416)
                           + t * *(_DWORD *)(LODWORD(y) + 288)
                           + *(_DWORD *)(LODWORD(y) + 32));
            v54 = (_DWORD *)max_y;
            v55 = x1 * v54[102] + t * v54[70];
            v56 = v53 * 0.57735026;
            *(float *)(*(_DWORD *)(max_y + 24) + v55) = *(float *)(*(_DWORD *)(max_y + 24) + v55) * v56;
            v57 = v46 * v54[103] + t * v54[71];
            *(float *)(v57 + v54[7]) = *(float *)(v57 + v54[7]) * v56;
            *(float *)(v54[8] + v46 * v54[104] + t * v54[72]) = *(float *)(v54[8] + v46 * v54[104] + t * v54[72]) * v56;
            v47 = *(_DWORD *)LODWORD(y);
            v48 = t + 1;
            t = v48;
          }
          while ( v48 < v47 );
          x = v0.x;
        }
        x1 = ++v46;
      }
      while ( v46 < *(_DWORD *)(LODWORD(y) + 4) );
    }
  }
  operator delete(p: (void *)LODWORD(x));
  operator delete(p: (void *)max_x);
  operator delete(p: (void *)LODWORD(v3.x));
  m_nGrowSize = (void *)rtEnv.TriangleColors.m_Memory.m_nGrowSize;
  v59 = 0;
  rtEnv.TriangleMaterials.m_Memory.m_pMemory = nullptr;
  if ( (int)rtEnv.TriangleColors.m_pElements >= 0 )
  {
    if ( rtEnv.TriangleColors.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)rtEnv.TriangleColors.m_Memory.m_nGrowSize);
      m_nGrowSize = nullptr;
      rtEnv.TriangleColors.m_Memory.m_nGrowSize = 0;
    }
    rtEnv.TriangleColors.m_Size = 0;
  }
  rtEnv.TriangleMaterials.m_Memory.m_nAllocationCount = (int)m_nGrowSize;
  if ( (int)rtEnv.TriangleColors.m_pElements >= 0 )
  {
    if ( m_nGrowSize != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nGrowSize);
      rtEnv.TriangleColors.m_Memory.m_nGrowSize = 0;
    }
    rtEnv.TriangleColors.m_Size = 0;
  }
  v60 = (void *)rtEnv.LightList.m_Memory.m_nGrowSize;
  rtEnv.TriangleColors.m_Memory.m_pMemory = nullptr;
  if ( (int)rtEnv.LightList.m_pElements >= 0 )
  {
    if ( rtEnv.LightList.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)rtEnv.LightList.m_Memory.m_nGrowSize);
      v60 = nullptr;
      rtEnv.LightList.m_Memory.m_nGrowSize = 0;
    }
    rtEnv.LightList.m_Size = 0;
  }
  rtEnv.TriangleColors.m_Memory.m_nAllocationCount = (int)v60;
  if ( (int)rtEnv.LightList.m_pElements >= 0 )
  {
    if ( v60 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v60);
      rtEnv.LightList.m_Memory.m_nGrowSize = 0;
    }
    rtEnv.LightList.m_Size = 0;
  }
  v61 = (void *)rtEnv.TriangleIndexList.m_Memory.m_nGrowSize;
  rtEnv.LightList.m_Memory.m_pMemory = nullptr;
  if ( (int)rtEnv.TriangleIndexList.m_pElements >= 0 )
  {
    if ( rtEnv.TriangleIndexList.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)rtEnv.TriangleIndexList.m_Memory.m_nGrowSize);
      v61 = nullptr;
      rtEnv.TriangleIndexList.m_Memory.m_nGrowSize = 0;
    }
    rtEnv.TriangleIndexList.m_Size = 0;
  }
  rtEnv.LightList.m_Memory.m_nAllocationCount = (int)v61;
  if ( (int)rtEnv.TriangleIndexList.m_pElements >= 0 )
  {
    if ( v61 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v61);
      rtEnv.TriangleIndexList.m_Memory.m_nGrowSize = 0;
    }
    rtEnv.TriangleIndexList.m_Size = 0;
  }
  v62 = *((void **)&rtEnv.OptimizedTriangleList.m_Memory + 2);
  rtEnv.TriangleIndexList.m_Memory.m_pMemory = nullptr;
  if ( (int)rtEnv.OptimizedTriangleList.m_pElements >= 0 )
  {
    if ( *((_DWORD *)&rtEnv.OptimizedTriangleList.m_Memory + 2) != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)&rtEnv.OptimizedTriangleList.m_Memory + 2));
      v62 = nullptr;
      *((_DWORD *)&rtEnv.OptimizedTriangleList.m_Memory + 2) = 0;
    }
    rtEnv.OptimizedTriangleList.m_Size = 0;
  }
  rtEnv.TriangleIndexList.m_Memory.m_nAllocationCount = (int)v62;
  if ( (int)rtEnv.OptimizedTriangleList.m_pElements >= 0 )
  {
    if ( v62 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v62);
      *((_DWORD *)&rtEnv.OptimizedTriangleList.m_Memory + 2) = 0;
    }
    rtEnv.OptimizedTriangleList.m_Size = 0;
  }
  v63 = (void **)rtEnv.OptimizedKDTree.m_Memory.m_nGrowSize;
  rtEnv.OptimizedTriangleList.m_Memory.m_pMemory = nullptr;
  if ( rtEnv.OptimizedKDTree.m_Memory.m_nGrowSize != 0 )
  {
    if ( rtEnv.OptimizedKDTree.m_Size > 0 )
    {
      do
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v63[v59]);
        v63 = (void **)rtEnv.OptimizedKDTree.m_Memory.m_nGrowSize;
        ++v59;
      }
      while ( v59 < rtEnv.OptimizedKDTree.m_Size );
    }
    rtEnv.OptimizedKDTree.m_Size = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v63);
    v63 = nullptr;
    rtEnv.OptimizedKDTree.m_Memory.m_nGrowSize = 0;
    v59 = 0;
  }
  rtEnv.OptimizedTriangleList.m_Memory.m_nBlocks = 0;
  if ( v63 != nullptr )
  {
    if ( rtEnv.OptimizedKDTree.m_Size > 0 )
    {
      do
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v63[v59]);
        v63 = (void **)rtEnv.OptimizedKDTree.m_Memory.m_nGrowSize;
        ++v59;
      }
      while ( v59 < rtEnv.OptimizedKDTree.m_Size );
    }
    rtEnv.OptimizedKDTree.m_Size = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v63);
    rtEnv.OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  }
  v64 = (void *)rtEnv.BackgroundColor.z.m128_i32[1];
  rtEnv.OptimizedKDTree.m_Memory.m_pMemory = nullptr;
  if ( rtEnv.BackgroundColor.z.m128_i32[3] >= 0 )
  {
    if ( rtEnv.BackgroundColor.z.m128_i32[1] != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)rtEnv.BackgroundColor.z.m128_i32[1]);
      v64 = nullptr;
      rtEnv.BackgroundColor.z.m128_i32[1] = 0;
    }
    rtEnv.BackgroundColor.z.m128_i32[2] = 0;
  }
  rtEnv.OptimizedKDTree.m_Memory.m_nAllocationCount = (int)v64;
  if ( rtEnv.BackgroundColor.z.m128_i32[3] >= 0 && v64 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v64);
  return (FloatBitMap_t *)max_y;
}
