// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/floatbitmap_bilateralfilter.cpp
// Functions: 2
// ============================================================

#include "bitmap\floatbitmap_bilateralfilter.h"

//------------------------------------------------------------------------------
// Address: 0x00405B00
// Name: TBFCalculationThreadFN
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall TBFCalculationThreadFN@<eax>(int a1@<edi>, int *ctx1)
{
  int *v2; // esi
  int v3; // edx
  int v4; // eax
  int v5; // edx
  int *v6; // esi
  int v7; // ecx
  int v8; // edi
  int v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // edx
  double v13; // xmm0_8
  int v14; // ecx
  int v15; // edi
  int v16; // eax
  int v17; // ecx
  float v18; // xmm1_4
  int v19; // edi
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  int v24; // eax
  int v25; // ecx
  int v26; // esi
  int v27; // eax
  int v28; // ecx
  long double v30; // [esp-4h] [ebp-54h]
  double v31; // [esp+4h] [ebp-4Ch]
  float v32; // [esp+Ch] [ebp-44h]
  float this_p; // [esp+10h] [ebp-40h]
  float centerp; // [esp+14h] [ebp-3Ch]
  int v35; // [esp+18h] [ebp-38h]
  int v36; // [esp+1Ch] [ebp-34h]
  int iy; // [esp+20h] [ebp-30h]
  int v38; // [esp+24h] [ebp-2Ch]
  int v39; // [esp+28h] [ebp-28h]
  int ix; // [esp+2Ch] [ebp-24h]
  float filter_sum; // [esp+30h] [ebp-20h]
  float sum_weights; // [esp+34h] [ebp-1Ch]
  int v43; // [esp+38h] [ebp-18h]
  int v44; // [esp+3Ch] [ebp-14h]
  int v45; // [esp+3Ch] [ebp-14h]
  int v46; // [esp+40h] [ebp-10h]
  int v47; // [esp+44h] [ebp-Ch]
  int y; // [esp+48h] [ebp-8h]
  int x; // [esp+4Ch] [ebp-4h]

  v2 = ctx1;
  v3 = *ctx1;
  v4 = ctx1[1];
  y = *ctx1;
  if ( *ctx1 <= v4 )
  {
    LODWORD(v30) = a1;
    while ( 1 )
    {
      if ( v2[2] == 0 )
        _ReportProgress(a1: "Performing bilateral filter", a2: v4 - *v2 + 1, a3: v3 - *v2);
      x = 0;
      if ( *(int *)v2[6] > 0 )
        break;
LABEL_32:
      v4 = v2[1];
      v3 = y + 1;
      y = v3;
      if ( v3 > v4 )
        return 0;
    }
LABEL_6:
    v5 = 280;
    v46 = 280;
LABEL_7:
    v6 = (int *)v2[5];
    v7 = ctx1[3];
    v8 = -v7;
    v9 = -v7;
    v10 = 0.0;
    v11 = 0.0;
    sum_weights = 0.0;
    filter_sum = 0.0;
    centerp = *(float *)(x * *(int *)((char *)v6 + v5)
                       + y * *(int *)((char *)v6 + v5 + 128)
                       + *(int *)((char *)v6 + v5 - 256));
    v38 = v7;
    v36 = -v7;
    iy = -v7;
    if ( -v7 > v7 )
      goto LABEL_30;
LABEL_10:
    ix = v8;
    if ( v8 > v7 )
      goto LABEL_29;
    v12 = v9 + y;
    v35 = v9 * v9;
    v13 = 1.0 / ((double)v7 * 2.0 * 0.033);
    v14 = v8 + x;
    v47 = v9 + y;
    v31 = v13;
    v32 = *((float *)ctx1 + 4);
    v39 = v8 + x;
    while ( 1 )
    {
      v15 = v14;
      v43 = v14;
      v44 = *v6;
      if ( v14 < *v6 )
      {
        if ( v14 >= 0 )
          goto LABEL_18;
        v15 = v14 + v44 * ((*v6 - v14 - 1) / v44);
        v43 = v15;
      }
      else
      {
        v15 = v14 % v44;
        v43 = v14 % v44;
      }
      v12 = v47;
LABEL_18:
      v16 = v6[1];
      v17 = v12;
      if ( v12 < v16 )
      {
        if ( v12 < 0 )
          v17 = v47 + v6[1] * ((v16 - v12 - 1) / v6[1]);
      }
      else
      {
        v17 = v12 % v6[1];
      }
      v45 = 0;
      if ( v6[2] <= 0 )
      {
        v15 = v43;
        v45 = 0 % v6[2];
      }
      v18 = *(float *)(v17 * *(int *)((char *)v6 + v46 + 128)
                     + v45 * *(int *)((char *)v6 + v46 + 256)
                     + v15 * *(int *)((char *)v6 + v46)
                     + *(int *)((char *)v6 + v46 - 256));
      v19 = ix;
      this_p = v18;
      __libm_sse2_exp(x: v30);
      LODWORD(v20) = COERCE_UNSIGNED_INT((double)(v35 + ix * ix) * v13) ^ _mask__NegFloat_;
      LODWORD(v21) = COERCE_UNSIGNED_INT(centerp - v18) & _mask__AbsFloat_;
      if ( v21 <= v32 )
        v22 = 1.0 - (float)(v21 / v32);
      else
        v22 = 0.0;
      v23 = v22 * v20;
      v10 = (float)(v22 * v20) + sum_weights;
      v14 = v39 + 1;
      v11 = (float)(v23 * this_p) + filter_sum;
      sum_weights = v10;
      filter_sum = v11;
      ++ix;
      ++v39;
      if ( v19 + 1 > v38 )
      {
        v9 = iy;
        v5 = v46;
        v7 = v38;
LABEL_29:
        iy = ++v9;
        if ( v9 <= v7 )
        {
          v8 = v36;
          goto LABEL_10;
        }
LABEL_30:
        v24 = ctx1[6];
        v25 = y * *(_DWORD *)(v5 + v24 + 128);
        v26 = x * *(_DWORD *)(v5 + v24);
        v27 = *(_DWORD *)(v5 + v24 - 256);
        v28 = v26 + v25;
        v2 = ctx1;
        v5 += 4;
        *(float *)(v28 + v27) = v11 / v10;
        v46 = v5;
        if ( v5 >= 296 )
        {
          if ( ++x >= *(_DWORD *)ctx1[6] )
            goto LABEL_32;
          goto LABEL_6;
        }
        goto LABEL_7;
      }
      v13 = v31;
      v12 = v47;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405DF0
// Name: public: void FloatBitMap_t::TileableBilateralFilter(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::TileableBilateralFilter(
        FloatBitMap_t *this,
        int radius_in_pixels,
        float edge_threshold_value)
{
  int CPUInformation; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ebx
  int v8; // esi
  TBFCalculationContext *v9; // edi
  int v10; // eax
  ThreadHandle_t__ *SimpleThread; // eax
  int i; // esi
  FloatBitMap_t orig; // [esp+8h] [ebp-728h] BYREF
  TBFCalculationContext ctxs[32]; // [esp+32Ch] [ebp-404h] BYREF
  ThreadHandle_t__ *waithandles[32]; // [esp+6ACh] [ebp-84h]
  FloatBitMap_t *v16; // [esp+72Ch] [ebp-4h]
  int nthreads; // [esp+738h] [ebp+8h]
  int ystep; // [esp+73Ch] [ebp+Ch]

  v16 = this;
  FloatBitMap_t::FloatBitMap_t(this: &orig, pOrig: this);
  ctxs[0].radius_in_pixels = radius_in_pixels;
  ctxs[0].edge_threshold_value = edge_threshold_value;
  ctxs[0].orig_bm = &orig;
  ctxs[0].dest_bm = this;
  CPUInformation = _GetCPUInformation();
  v5 = 32;
  if ( *(_BYTE *)(CPUInformation + 6) <= 0x20u )
  {
    nthreads = *(unsigned __int8 *)(_GetCPUInformation() + 6);
    v5 = nthreads;
  }
  else
  {
    nthreads = 32;
  }
  v6 = this->m_nRows / v5;
  v7 = 0;
  v8 = 0;
  ystep = v6;
  v9 = ctxs;
  do
  {
    if ( v8 != 0 )
      *v9 = ctxs[0];
    v9->thread_number = v8;
    v9->min_y = v7;
    if ( v8 == v5 - 1 )
    {
      v9->max_y = v16->m_nRows - 1;
    }
    else
    {
      v10 = ystep + v7 - 1;
      if ( v16->m_nRows - 1 < v10 )
        v10 = v16->m_nRows - 1;
      v9->max_y = v10;
    }
    SimpleThread = (ThreadHandle_t__ *)_CreateSimpleThread(a1: TBFCalculationThreadFN, a2: v9);
    v5 = nthreads;
    v7 += ystep;
    waithandles[v8++] = SimpleThread;
    ++v9;
  }
  while ( v8 < nthreads );
  for ( i = 0; i < nthreads; ++i )
    _ThreadJoin(a1: waithandles[i]);
  CSOAContainer::~CSOAContainer(this: &orig);
}
