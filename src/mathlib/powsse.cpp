// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/powsse.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1025DF80
// Name: float FastPow(float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FastPow(int a, float b)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  __m128 v5; // xmm0
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2

  if ( OOshift23 >= *(float *)&a )
    return 0.0;
  v3.m128_i32[0] = 1258291200;
  v4 = (__m128)COERCE_UNSIGNED_INT((float)a);
  v4.m128_f32[0] = (float)(v4.m128_f32[0] * OOshift23) - 127.0;
  v5 = _mm_and_ps((__m128)0x80000000, v4);
  v6.m128_i32[0] = v5.m128_i32[0];
  v3.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v5), v3).m128_f32[0]) & 0x4B000000 | v5.m128_i32[0];
  v7 = v4;
  v7.m128_f32[0] = (float)(v4.m128_f32[0] + v3.m128_f32[0]) - v3.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - v4.m128_f32[0];
  v8.m128_f32[0] = v7.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v8, v6).m128_f32[0]) & 0x3F800000);
  v9 = v4;
  v9.m128_f32[0] = (float)((float)(v4.m128_f32[0] - v8.m128_f32[0])
                         - (float)((float)(v4.m128_f32[0] - v8.m128_f32[0]) * (float)(v4.m128_f32[0] - v8.m128_f32[0])))
                 * 0.346607;
  v8.m128_i32[0] = 1258291200;
  v9.m128_f32[0] = (float)(v9.m128_f32[0] + v4.m128_f32[0]) * b;
  v10 = _mm_and_ps((__m128)0x80000000, v9);
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v9, v10), v8).m128_f32[0]) & 0x4B000000 | v10.m128_i32[0];
  v11 = v9;
  v11.m128_f32[0] = (float)(v9.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v12 = v11;
  v12.m128_f32[0] = v11.m128_f32[0] - v9.m128_f32[0];
  v11.m128_f32[0] = v9.m128_f32[0]
                  - (float)(v11.m128_f32[0]
                          - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v12, v10).m128_f32[0]) & 0x3F800000));
  return COERCE_FLOAT((int)(float)((float)((float)(v9.m128_f32[0] + 127.0)
                                         - (float)((float)(v11.m128_f32[0] - (float)(v11.m128_f32[0] * v11.m128_f32[0]))
                                                 * 0.33971))
                                 * shift23));
}

//------------------------------------------------------------------------------
// Address: 0x1025E0B0
// Name: float FastPow10(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FastPow10(unsigned int i)
{
  __m128 v1; // xmm0
  __m128 v2; // xmm2
  __m128 v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm2

  v1 = (__m128)i;
  v1.m128_f32[0] = *(float *)&i * 3.321928;
  v2.m128_i32[0] = 1258291200;
  v3 = _mm_and_ps((__m128)0x80000000, v1);
  v2.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v1, v3), v2).m128_f32[0]) & 0x4B000000 | v3.m128_i32[0];
  v4 = v1;
  v4.m128_f32[0] = (float)((float)(*(float *)&i * 3.321928) + v2.m128_f32[0]) - v2.m128_f32[0];
  v5 = v4;
  v5.m128_f32[0] = v4.m128_f32[0] - (float)(*(float *)&i * 3.321928);
  v4.m128_f32[0] = (float)(*(float *)&i * 3.321928)
                 - (float)(v4.m128_f32[0]
                         - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v5, v3).m128_f32[0]) & 0x3F800000));
  return COERCE_FLOAT((int)(float)((float)((float)((float)(*(float *)&i * 3.321928) + 127.0)
                                         - (float)((float)(v4.m128_f32[0] - (float)(v4.m128_f32[0] * v4.m128_f32[0]))
                                                 * 0.33971))
                                 * shift23));
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1025DFB0
// Name: float FastPow(float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FastPow(int a, float b)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  __m128 v5; // xmm0
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2

  if ( OOshift23 >= *(float *)&a )
    return 0.0;
  v3.m128_i32[0] = 1258291200;
  v4 = (__m128)COERCE_UNSIGNED_INT((float)a);
  v4.m128_f32[0] = (float)(v4.m128_f32[0] * OOshift23) - 127.0;
  v5 = _mm_and_ps((__m128)0x80000000, v4);
  v6.m128_i32[0] = v5.m128_i32[0];
  v3.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v5), v3).m128_f32[0]) & 0x4B000000 | v5.m128_i32[0];
  v7 = v4;
  v7.m128_f32[0] = (float)(v4.m128_f32[0] + v3.m128_f32[0]) - v3.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - v4.m128_f32[0];
  v8.m128_f32[0] = v7.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v8, v6).m128_f32[0]) & 0x3F800000);
  v9 = v4;
  v9.m128_f32[0] = (float)((float)(v4.m128_f32[0] - v8.m128_f32[0])
                         - (float)((float)(v4.m128_f32[0] - v8.m128_f32[0]) * (float)(v4.m128_f32[0] - v8.m128_f32[0])))
                 * 0.346607;
  v8.m128_i32[0] = 1258291200;
  v9.m128_f32[0] = (float)(v9.m128_f32[0] + v4.m128_f32[0]) * b;
  v10 = _mm_and_ps((__m128)0x80000000, v9);
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v9, v10), v8).m128_f32[0]) & 0x4B000000 | v10.m128_i32[0];
  v11 = v9;
  v11.m128_f32[0] = (float)(v9.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v12 = v11;
  v12.m128_f32[0] = v11.m128_f32[0] - v9.m128_f32[0];
  v11.m128_f32[0] = v9.m128_f32[0]
                  - (float)(v11.m128_f32[0]
                          - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v12, v10).m128_f32[0]) & 0x3F800000));
  return COERCE_FLOAT((int)(float)((float)((float)(v9.m128_f32[0] + 127.0)
                                         - (float)((float)(v11.m128_f32[0] - (float)(v11.m128_f32[0] * v11.m128_f32[0]))
                                                 * 0.33971))
                                 * shift23));
}

//------------------------------------------------------------------------------
// Address: 0x1025E0E0
// Name: float FastPow10(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FastPow10(unsigned int i)
{
  __m128 v1; // xmm0
  __m128 v2; // xmm2
  __m128 v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm2

  v1 = (__m128)i;
  v1.m128_f32[0] = *(float *)&i * 3.321928;
  v2.m128_i32[0] = 1258291200;
  v3 = _mm_and_ps((__m128)0x80000000, v1);
  v2.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v1, v3), v2).m128_f32[0]) & 0x4B000000 | v3.m128_i32[0];
  v4 = v1;
  v4.m128_f32[0] = (float)((float)(*(float *)&i * 3.321928) + v2.m128_f32[0]) - v2.m128_f32[0];
  v5 = v4;
  v5.m128_f32[0] = v4.m128_f32[0] - (float)(*(float *)&i * 3.321928);
  v4.m128_f32[0] = (float)(*(float *)&i * 3.321928)
                 - (float)(v4.m128_f32[0]
                         - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v5, v3).m128_f32[0]) & 0x3F800000));
  return COERCE_FLOAT((int)(float)((float)((float)((float)(*(float *)&i * 3.321928) + 127.0)
                                         - (float)((float)(v4.m128_f32[0] - (float)(v4.m128_f32[0] * v4.m128_f32[0]))
                                                 * 0.33971))
                                 * shift23));
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10205CC0
// Name: union __m128 Pow_FixedPoint_Exponent_SIMD(union __m128 const __near &,int)
// Source: json
//------------------------------------------------------------------------------
__m128 __cdecl Pow_FixedPoint_Exponent_SIMD(__m128 *result, const __m128 *x)
{
  __m128 v2; // xmm0
  int v3; // eax
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  int v6; // eax

  v2 = Four_Ones;
  v3 = abs32((int)x);
  if ( (v3 & 3) != 0 )
  {
    v4 = _mm_sqrt_ps(*result);
    if ( (v3 & 1) != 0 )
      v2 = _mm_sqrt_ps(v4);
    if ( (v3 & 2) != 0 )
      v2 = _mm_mul_ps(v2, v4);
  }
  v5 = *result;
  v6 = v3 >> 2;
  while ( 1 )
  {
    if ( (v6 & 1) != 0 )
      v2 = _mm_mul_ps(v2, v5);
    v6 >>= 1;
    if ( v6 == 0 )
      break;
    v5 = _mm_mul_ps(v5, v5);
  }
  if ( (int)x < 0 )
    return _mm_rcp_ps(_mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v2), Four_Epsilons), v2));
  return v2;
}

} // namespace hammer_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10077FC0
// Name: union __m128 Pow_FixedPoint_Exponent_SIMD(union __m128 const __near &,int)
// Source: json
//------------------------------------------------------------------------------
__m128 __cdecl Pow_FixedPoint_Exponent_SIMD(__m128 *result, const __m128 *x)
{
  __m128 v2; // xmm0
  int v3; // eax
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  int v6; // eax

  v2 = Four_Ones;
  v3 = abs32((int)x);
  if ( (v3 & 3) != 0 )
  {
    v4 = _mm_sqrt_ps(*result);
    if ( (v3 & 1) != 0 )
      v2 = _mm_sqrt_ps(v4);
    if ( (v3 & 2) != 0 )
      v2 = _mm_mul_ps(v2, v4);
  }
  v5 = *result;
  v6 = v3 >> 2;
  while ( 1 )
  {
    if ( (v6 & 1) != 0 )
      v2 = _mm_mul_ps(v2, v5);
    v6 >>= 1;
    if ( v6 == 0 )
      break;
    v5 = _mm_mul_ps(v5, v5);
  }
  if ( (int)x < 0 )
    return _mm_rcp_ps(_mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v2), Four_Epsilons), v2));
  return v2;
}

} // namespace vrad_dll

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1040D0E0
// Name: union __m128 Pow_FixedPoint_Exponent_SIMD(union __m128 const __near &,int)
// Source: json
//------------------------------------------------------------------------------
__m128 __cdecl Pow_FixedPoint_Exponent_SIMD(__m128 *result, const __m128 *x)
{
  __m128 v2; // xmm0
  int v3; // eax
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  int v6; // eax

  v2 = Four_Ones;
  v3 = abs32((int)x);
  if ( (v3 & 3) != 0 )
  {
    v4 = _mm_sqrt_ps(*result);
    if ( (v3 & 1) != 0 )
      v2 = _mm_sqrt_ps(v4);
    if ( (v3 & 2) != 0 )
      v2 = _mm_mul_ps(v2, v4);
  }
  v5 = *result;
  v6 = v3 >> 2;
  while ( 1 )
  {
    if ( (v6 & 1) != 0 )
      v2 = _mm_mul_ps(v2, v5);
    v6 >>= 1;
    if ( v6 == 0 )
      break;
    v5 = _mm_mul_ps(v5, v5);
  }
  if ( (int)x < 0 )
    return _mm_rcp_ps(_mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v2), Four_Epsilons), v2));
  return v2;
}

} // namespace client
