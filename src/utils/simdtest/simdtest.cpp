// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/simdtest/simdtest.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: GammaToLinearBenchmark
// Source: json
//------------------------------------------------------------------------------
int __usercall GammaToLinearBenchmark@<eax>(int a1@<ecx>, int a2@<edi>, float a3@<esi>)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm0
  int i; // eax
  double v6; // st7
  int j; // esi
  double v8; // st7
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+Ch] [ebp-8h]
  float flStart; // [esp+10h] [ebp-4h]

  vecLinear.x = 0.67799997;
  vecLinear.y = 0.178;
  vecLinear.z = 0.278;
  _Plat_FloatTime(a1);
  v3 = _mm_max_ps((__m128)vecLinear, Four_Zeros);
  v4 = _mm_min_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(_mm_mul_ps(Four_GammaToLinearCoefficients_A, v3), Four_GammaToLinearCoefficients_B),
                 v3),
               Four_GammaToLinearCoefficients_C),
             v3),
           Four_GammaToLinearCoefficients_D),
         Four_Ones);
  for ( i = 100000000; i != 0; --i )
    vecRslt = (Vector4D)v4;
  v6 = _Plat_FloatTime(a1: a2);
  _Warning(a1: "simd = %f\n", v6 - a3);
  flStart = _Plat_FloatTime(a1: v10);
  for ( j = 100000000; j != 0; --j )
  {
    vecRslt.x = GammaToLinear(gamma: vecLinear.x);
    vecRslt.y = GammaToLinear(gamma: vecLinear.y);
    vecRslt.z = GammaToLinear(gamma: vecLinear.z);
  }
  v8 = _Plat_FloatTime(a1: v11);
  return _Warning(a1: "old = %f\n", v8 - flStart);
}

//------------------------------------------------------------------------------
// Address: 0x004011F0
// Name: bool SIMDTest(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall SIMDTest@<al>(int a1@<ebp>, int a2@<edi>)
{
  int v2; // eax
  __m128 *p_y; // edi
  float *v4; // esi
  float v5; // xmm0_4
  double v6; // st7
  double v7; // st6
  int v8; // eax
  double v9; // st6
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  float x; // ecx
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __int128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  int v21; // esi
  float v22; // xmm1_4
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 *v31; // ecx
  int v32; // edx
  __m128 *p_z; // eax
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm6
  __m128 v40; // xmm4
  __m128 v41; // xmm1
  __m128 v42; // xmm5
  __m128 v43; // xmm0
  __m128 v44; // xmm6
  __m128 v45; // xmm5
  __m128 v46; // xmm3
  __m128 v47; // xmm4
  __m128 v48; // xmm5
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm0
  __m128 v52; // xmm6
  __m128 v53; // xmm1
  __m128 v54; // xmm3
  __m128 v55; // xmm5
  __m128 v56; // xmm1
  double v57; // st7
  __m128 pts_4; // [esp+30h] [ebp-23Ch]
  __m128 pts_20; // [esp+40h] [ebp-22Ch]
  __m128 pts_36; // [esp+50h] [ebp-21Ch]
  __m128 SIMDMaxDist_4; // [esp+60h] [ebp-20Ch]
  __m128 SIMDMaxDist2_4; // [esp+70h] [ebp-1FCh]
  __m128 MiddleP_4; // [esp+90h] [ebp-1DCh]
  __m128 MiddleP_20; // [esp+A0h] [ebp-1CCh]
  __m128 MiddleP_36; // [esp+B0h] [ebp-1BCh]
  __m128 TimeScale_4; // [esp+C0h] [ebp-1ACh]
  __m128 Delta1_4; // [esp+D0h] [ebp-19Ch]
  __m128 Delta1_20; // [esp+E0h] [ebp-18Ch]
  __m128 Delta1_36; // [esp+F0h] [ebp-17Ch]
  _BYTE StartP_36[68]; // [esp+170h] [ebp-FCh] OVERLAPPED BYREF
  _BYTE v73[128]; // [esp+1C0h] [ebp-ACh] OVERLAPPED
  Vector offset; // [esp+240h] [ebp-2Ch]
  double v75; // [esp+254h] [ebp-18h]
  int v76; // [esp+25Ch] [ebp-10h]
  int v77; // [esp+260h] [ebp-Ch]
  int j; // [esp+264h] [ebp-8h]
  int retaddr; // [esp+26Ch] [ebp+0h]

  v77 = a1;
  j = retaddr;
  LOWORD(v76) = v76 & 0xFCC0 | 0x23F;
  SeedRandSIMD(seed: 0x1E52E5u);
  v2 = 0;
  LODWORD(offset.x) = g_CreationTime;
  p_y = &g_XYZ[0].y;
  do
  {
    HIDWORD(v75) = 0;
    v76 = v2;
    v4 = (float *)&StartP_36[24];
    do
    {
      v5 = (float)v76 * 0.00025025025;
      *(float *)&v73[4 * HIDWORD(v75) + 96] = v5;
      *v4 = v5 * 50.0;
      *(v4 - 2) = v5 * 100.0;
      *(v4 - 1) = v5 * 0.0;
      *(float *)&v73[116] = _RandomFloat(a1: -1054867456, a2: 1092616192);
      *(float *)&v73[120] = _RandomFloat(a1: -1054867456, a2: 1092616192);
      v6 = _RandomFloat(a1: -1054867456, a2: 1092616192);
      v7 = *(v4 - 2) + *(float *)&v73[116];
      ++v76;
      v8 = HIDWORD(v75) + 1;
      *(v4 - 2) = v7;
      v4 += 3;
      v9 = *(float *)&v73[120] + *(v4 - 4);
      HIDWORD(v75) = v8;
      *(v4 - 4) = v9;
      *(v4 - 3) = v6 + *(v4 - 3);
    }
    while ( v8 < 4 );
    v10 = *(__m128 *)&StartP_36[16];
    v11 = *(__m128 *)&StartP_36[52];
    x = offset.x;
    v2 = v76;
    *p_y = *(__m128 *)&StartP_36[28];
    p_y[1] = *(__m128 *)&StartP_36[40];
    p_y[-1] = v10;
    v13 = _mm_shuffle_ps(v10, *p_y, 68);
    v14 = _mm_shuffle_ps(v10, *p_y, 238);
    v15 = _mm_shuffle_ps(p_y[1], v11, 68);
    v16 = _mm_shuffle_ps(p_y[1], v11, 238);
    p_y[-1] = _mm_shuffle_ps(v13, v15, 136);
    *p_y = _mm_shuffle_ps(v13, v15, 221);
    v17 = *(_OWORD *)&v73[96];
    p_y[1] = _mm_shuffle_ps(v14, v16, 136);
    *(_OWORD *)LODWORD(x) = v17;
    p_y += 3;
    LODWORD(offset.x) = LODWORD(x) + 16;
  }
  while ( (int)p_y < (int)&vec2_origin_0 );
  *(double *)&offset.x = _Plat_FloatTime(a1: a2);
  v18 = (__m128)0x40000000u;
  v19 = (__m128)0x42C80000u;
  MiddleP_36 = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  Delta1_36 = _mm_shuffle_ps(v18, v18, 0);
  *(__m128 *)StartP_36 = _mm_shuffle_ps((__m128)0x40800000u, (__m128)0x40800000u, 0);
  TimeScale_4 = _mm_shuffle_ps(v19, v19, 0);
  v20 = 0u;
  Delta1_4 = _mm_shuffle_ps(v20, v20, 0);
  HIBYTE(v76) = 0;
  v21 = 0;
  *(_OWORD *)&v73[112] = 0x42C80000u;
  *(_OWORD *)&v73[96] = 0u;
  Delta1_20 = _mm_shuffle_ps((__m128)0xC2480000, (__m128)0xC2480000, 0);
  while ( 1 )
  {
    v22 = (double)v21 * 0.00001;
    v23 = 0;
    v23.m128_f32[0] = v22;
    SIMDMaxDist2_4 = _mm_shuffle_ps(v23, v23, 0);
    v24 = _mm_shuffle_ps(v18, v18, 0);
    pts_36 = _mm_max_ps(v24, _mm_max_ps(v24, v24));
    SIMDMaxDist_4 = _mm_mul_ps(pts_36, pts_36);
    MiddleP_4 = _mm_shuffle_ps(v20, v20, 0);
    MiddleP_20 = _mm_shuffle_ps(v19, v19, 0);
    v25 = MiddleP_4;
    v26 = MiddleP_4;
    v27 = MiddleP_4;
    v28 = MiddleP_4;
    v29 = MiddleP_4;
    v30 = MiddleP_4;
    v31 = g_CreationTime;
    v32 = 1000;
    p_z = &g_XYZ[0].z;
    while ( 1 )
    {
      v34 = _mm_min_ps(Four_Ones, _mm_mul_ps(_mm_sub_ps(SIMDMaxDist2_4, *v31), MiddleP_36));
      v35 = _mm_add_ps(_mm_mul_ps(v29, v34), v25);
      v36 = v30;
      v37 = _mm_add_ps(_mm_mul_ps(MiddleP_20, v34), v27);
      v38 = _mm_add_ps(_mm_mul_ps(v36, v34), v26);
      v39 = _mm_mul_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(Delta1_20, v34), MiddleP_20), v37), v34);
      v40 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(TimeScale_4, v34), v28), v35), v34), v35);
      v41 = *p_z;
      v42 = _mm_mul_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(Delta1_4, v34), MiddleP_4), v38), v34);
      v43 = p_z[-1];
      v44 = _mm_add_ps(v39, v37);
      v45 = _mm_add_ps(v42, v38);
      v46 = _mm_sub_ps(p_z[-2], v40);
      *(__m128 *)v73 = v40;
      v47 = _mm_sub_ps(v43, v45);
      *(__m128 *)&v73[16] = v45;
      v48 = _mm_sub_ps(v41, v44);
      v49 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v47, v47), _mm_mul_ps(v46, v46)), _mm_mul_ps(v48, v48));
      *(__m128 *)&v73[32] = v44;
      v50 = _mm_cmplt_ps(v49, *(__m128 *)StartP_36);
      v51 = _mm_cmplt_ps(SIMDMaxDist_4, v49);
      if ( _mm_movemask_ps(_mm_or_ps(v50, v51)) != 0 )
      {
        v52 = _mm_rsqrt_ps(v49);
        v53 = _mm_mul_ps(
                _mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v52, v52), v49)), v52),
                Four_PointFives);
        v54 = _mm_mul_ps(v46, v53);
        *(__m128 *)&StartP_36[16] = _mm_add_ps(_mm_mul_ps(v54, pts_36), *(__m128 *)v73);
        pts_4 = _mm_mul_ps(v47, v53);
        pts_20 = _mm_mul_ps(v48, v53);
        *(__m128 *)&v73[48] = _mm_mul_ps(v54, Delta1_36);
        *(__m128 *)&v73[64] = _mm_mul_ps(pts_4, Delta1_36);
        *(__m128 *)&v73[80] = _mm_mul_ps(pts_20, Delta1_36);
        *(__m128 *)&v73[64] = _mm_add_ps(*(__m128 *)&v73[16], *(__m128 *)&v73[64]);
        *(__m128 *)&v73[80] = _mm_add_ps(*(__m128 *)&v73[32], *(__m128 *)&v73[80]);
        v55 = _mm_or_ps(
                _mm_andnot_ps(
                  v50,
                  _mm_or_ps(
                    _mm_and_ps(_mm_add_ps(*(__m128 *)&v73[16], _mm_mul_ps(pts_4, pts_36)), v51),
                    _mm_andnot_ps(v51, p_z[-1]))),
                _mm_and_ps(*(__m128 *)&v73[64], v50));
        v56 = _mm_or_ps(
                _mm_andnot_ps(
                  v50,
                  _mm_or_ps(
                    _mm_and_ps(_mm_add_ps(*(__m128 *)&v73[32], _mm_mul_ps(pts_20, pts_36)), v51),
                    _mm_andnot_ps(v51, *p_z))),
                _mm_and_ps(*(__m128 *)&v73[80], v50));
        p_z[-2] = _mm_or_ps(
                    _mm_andnot_ps(
                      v50,
                      _mm_or_ps(_mm_andnot_ps(v51, p_z[-2]), _mm_and_ps(*(__m128 *)&StartP_36[16], v51))),
                    _mm_and_ps(_mm_add_ps(*(__m128 *)&v73[48], *(__m128 *)v73), v50));
        p_z[-1] = v55;
        *p_z = v56;
        HIBYTE(v76) = 1;
      }
      v20 = *(__m128 *)&v73[96];
      v19 = *(__m128 *)&v73[112];
      p_z += 3;
      ++v31;
      if ( --v32 == 0 )
        break;
      v30 = MiddleP_4;
      v25 = MiddleP_4;
      v27 = MiddleP_4;
      v26 = MiddleP_4;
      v29 = MiddleP_4;
      v28 = MiddleP_4;
    }
    if ( ++v21 >= 100000 )
      break;
    v18 = (__m128)0x40000000u;
  }
  v57 = _Plat_FloatTime(a1: v76);
  printf(format: "elapsed time=%f p/s=%f\n", v57 - *(double *)&offset.x, 400000000.0 / (v57 - *(double *)&offset.x));
  return HIBYTE(v76);
}

//------------------------------------------------------------------------------
// Address: 0x004017D0
// Name: void SSEClassTest(union __m128 const __near &,union __m128 __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SSEClassTest(const __m128 *val, __m128 *out)
{
  __m128 v2; // xmm0
  int i; // eax
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  int v6; // eax
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm2

  v2 = Four_Zeros;
  for ( i = 100000; i != 0; --i )
    v2 = _mm_min_ps(*val, _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*val, v2), *val), *val));
  v4 = v2;
  v5 = v2;
  v6 = 100000;
  do
  {
    --v6;
    v7 = _mm_mul_ps(v2, v2);
    v8 = _mm_mul_ps(v4, v4);
    v9 = _mm_mul_ps(v5, v5);
    v10 = _mm_add_ps(v7, v7);
    v11 = _mm_add_ps(v8, v8);
    v12 = _mm_add_ps(v9, v9);
    v13 = _mm_mul_ps(v10, v10);
    v14 = _mm_mul_ps(v11, v11);
    v15 = _mm_mul_ps(v12, v12);
    v2 = _mm_add_ps(v13, v13);
    v4 = _mm_add_ps(v14, v14);
    v5 = _mm_add_ps(v15, v15);
  }
  while ( v6 != 0 );
  *out = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v4, v4), _mm_mul_ps(v2, v2)), _mm_mul_ps(v5, v5));
}

//------------------------------------------------------------------------------
// Address: 0x00401850
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  unsigned int v3; // ebp
  int v4; // edi
  float v5; // esi
  int v6; // ecx
  float v8[3]; // [esp+20h] [ebp-1Ch] BYREF
  __m128 v9; // [esp+2Ch] [ebp-10h] BYREF
  unsigned int retaddr; // [esp+3Ch] [ebp+0h]

  *(unsigned __int64 *)((char *)v9.m128_u64 + 4) = __PAIR64__(retaddr, v3);
  InitCommandLineProgram(&argc, (char ***)&argv);
  SSEClassTest(val: &Four_PointFives, out: (__m128 *)v8);
  printf(format: "(%f,%f,%f,%f)\n", v8[0], v8[1], v8[2], v9.m128_f32[0]);
  GammaToLinearBenchmark(a1: v6, a2: v4, a3: v5);
  SIMDTest(a1: (int)&v9.m128_i32[1], a2: v4);
  return 0;
}
