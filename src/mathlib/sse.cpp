// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/sse.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102617E0
// Name: float FastCos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FastCos(unsigned int x)
{
  __m128 v1; // xmm0
  unsigned int v2; // edx
  __m128 v3; // xmm6
  float v4; // xmm5_4

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = ((int)v1.m128_f32[0] << 30) & 0x80000000;
  v3 = (__m128)sincos_masks[(int)v1.m128_f32[0] & 1];
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - (float)(int)v1.m128_f32[0], 1.0);
  LODWORD(v4) = COERCE_UNSIGNED_INT(1.0 - v1.m128_f32[0]) & v3.m128_i32[0] | _mm_andnot_ps(v3, v1).m128_u32[0];
  return (float)(COERCE_FLOAT(LODWORD(v4) | v2)
               * (float)((float)((float)((float)((float)((float)((float)(v4 * v4) * -0.0046817539) + 0.079692625)
                                               * (float)(v4 * v4))
                                       + -0.64596409)
                               * (float)(v4 * v4))
                       + 1.5707964));
}

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x004123E0
// Name: float _SSE_Sqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_Sqrt(float x)
{
  return fsqrt(x);
}

//------------------------------------------------------------------------------
// Address: 0x00412400
// Name: float _SSE_RSqrtAccurate(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_RSqrtAccurate(float a)
{
  float v1; // xmm0_4

  v1 = 1.0 / fsqrt(a);
  return (float)((float)((float)0.5 * v1) * (float)((float)3.0 - (float)((float)(a * v1) * v1)));
}

//------------------------------------------------------------------------------
// Address: 0x00412450
// Name: void _SSE_VectorNormalizeFast(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall _SSE_VectorNormalizeFast(Vector *vec)
{
  float v1; // xmm0_4
  float v2; // [esp+0h] [ebp-40h]
  float v3; // [esp+30h] [ebp-10h]

  v3 = vec->z * vec->z + vec->y * vec->y + vec->x * vec->x + 0.00000011920929;
  v1 = 1.0 / fsqrt(v3);
  v2 = (float)((float)0.5 * v1) * (float)((float)3.0 - (float)((float)(v3 * v1) * v1));
  vec->x = vec->x * v2;
  vec->y = v2 * vec->y;
  vec->z = v2 * vec->z;
}

//------------------------------------------------------------------------------
// Address: 0x004124E0
// Name: float _SSE_InvRSquared(float const __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall _SSE_InvRSquared@<st0>(__m128 a1@<xmm3>, __m128 *v)
{
  __m128 v2; // xmm1

  v2 = _mm_mul_ps(*v, *v);
  return (float)(1.0
               / fmaxf(
                   (float)(v2.m128_f32[0] + _mm_shuffle_ps(v2, v2, 1).m128_f32[0]) + _mm_movehl_ps(a1, v2).m128_f32[0],
                   1.0));
}

//------------------------------------------------------------------------------
// Address: 0x00412520
// Name: void _SSE_SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall _SSE_SinCos(__m128 a1@<xmm2>, __m128 a2@<xmm6>, unsigned int x, float *s, float *c)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm0
  int v7; // ecx
  int v8; // edx
  __m128 v9; // xmm3
  int v10; // xmm4_4
  float v11; // xmm5_4

  v5 = (__m128)x;
  v5.m128_f32[0] = *(float *)&x * 0.63661975;
  v6 = _mm_and_ps(v5, (__m128)0x7FFFFFFFu);
  v7 = (int)v6.m128_f32[0] << 30;
  v8 = ((int)v6.m128_f32[0] + 1) << 30;
  v9 = (__m128)sincos_inv_masks[(int)v6.m128_f32[0] & 1];
  v6.m128_f32[0] = fminf(v6.m128_f32[0] - (float)(int)v6.m128_f32[0], 1.0);
  a2.m128_f32[0] = 1.0 - v6.m128_f32[0];
  v10 = a2.m128_i32[0] & v9.m128_i32[0];
  a1.m128_f32[0] = v9.m128_f32[0];
  v9.m128_f32[0] = _mm_andnot_ps(v9, v6).m128_f32[0];
  v6.m128_i32[0] = v6.m128_i32[0] & a1.m128_i32[0] | _mm_andnot_ps(a1, a2).m128_u32[0];
  LODWORD(v11) = v10 | v9.m128_i32[0];
  *s = (float)((float)((float)((float)((float)((float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) * -0.0046817539)
                                             + 0.079692625)
                                     * (float)(v6.m128_f32[0] * v6.m128_f32[0]))
                             + -0.64596409)
                     * (float)(v6.m128_f32[0] * v6.m128_f32[0]))
             + 1.5707964)
     * COERCE_FLOAT(v6.m128_i32[0] | x & 0x80000000 ^ v7 & 0x80000000);
  *c = (float)((float)((float)((float)((float)((float)((float)(v11 * v11) * -0.0046817539) + 0.079692625)
                                     * (float)(v11 * v11))
                             + -0.64596409)
                     * (float)(v11 * v11))
             + 1.5707964)
     * COERCE_FLOAT(LODWORD(v11) | v8 & 0x80000000);
}

//------------------------------------------------------------------------------
// Address: 0x00412660
// Name: float _SSE_cos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_cos(unsigned int x)
{
  __m128 v1; // xmm0
  unsigned int v2; // edx
  __m128 v3; // xmm6

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = ((int)v1.m128_f32[0] << 30) & 0x80000000;
  v3 = (__m128)sincos_masks[(int)v1.m128_f32[0] & 1];
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - (float)(int)v1.m128_f32[0], 1.0);
  v1.m128_i32[0] = COERCE_UNSIGNED_INT(1.0 - v1.m128_f32[0]) & v3.m128_i32[0] | _mm_andnot_ps(v3, v1).m128_u32[0];
  return (float)(COERCE_FLOAT(v1.m128_i32[0] | v2)
               * (float)((float)((float)((float)((float)((float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) * -0.0046817539)
                                                       + 0.079692625)
                                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                                       + -0.64596409)
                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                       + 1.5707964));
}

//------------------------------------------------------------------------------
// Address: 0x00412730
// Name: void _SSE2_SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _SSE2_SinCos(unsigned int x, float *s, float *c)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm4
  __m128i v5; // xmm2
  __m128i v6; // xmm1
  __m128 v7; // xmm5
  float v8; // xmm6_4

  v3 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v3.m128_f32[0] = v3.m128_f32[0] * 0.63661975;
  v4 = (__m128)0x3F800000u;
  v5 = _mm_cvttps_epi32(v3);
  v6 = _mm_cvtsi32_si128(2u);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(_mm_cvtsi32_si128(1u), v5), (__m128i)0LL);
  v3.m128_f32[0] = fminf(v3.m128_f32[0] - _mm_cvtepi32_ps(v5).m128_f32[0], 1.0);
  v4.m128_f32[0] = 1.0 - v3.m128_f32[0];
  LODWORD(v8) = COERCE_UNSIGNED_INT(1.0 - v3.m128_f32[0]) & v7.m128_i32[0] | _mm_andnot_ps(v7, v3).m128_u32[0];
  v3.m128_i32[0] = v3.m128_i32[0] & v7.m128_i32[0] | _mm_andnot_ps(v7, v4).m128_u32[0];
  *s = (float)((float)((float)((float)((float)((float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) * -0.0046817539)
                                             + 0.079692625)
                                     * (float)(v3.m128_f32[0] * v3.m128_f32[0]))
                             + -0.64596409)
                     * (float)(v3.m128_f32[0] * v3.m128_f32[0]))
             + 1.5707964)
     * COERCE_FLOAT(v3.m128_i32[0] | (_mm_and_si128(v5, v6).m128i_u32[0] << 30) ^ x & 0x80000000);
  *c = (float)((float)((float)((float)((float)((float)((float)(v8 * v8) * -0.0046817539) + 0.079692625)
                                     * (float)(v8 * v8))
                             + -0.64596409)
                     * (float)(v8 * v8))
             + 1.5707964)
     * COERCE_FLOAT(LODWORD(v8) | (_mm_and_si128(_mm_add_epi32(_mm_cvtsi32_si128(1u), v5), v6).m128i_u32[0] << 30));
}

//------------------------------------------------------------------------------
// Address: 0x00412850
// Name: float _SSE2_cos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE2_cos(unsigned int x)
{
  __m128 v1; // xmm0
  __m128 v2; // xmm4
  __m128i v3; // xmm2
  __m128 v4; // xmm5

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = (__m128)0x3F800000u;
  v3 = _mm_cvttps_epi32(v1);
  v4 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(_mm_cvtsi32_si128(1u), v3), (__m128i)0LL);
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - _mm_cvtepi32_ps(v3).m128_f32[0], 1.0);
  v2.m128_f32[0] = 1.0 - v1.m128_f32[0];
  v1.m128_i32[0] = v1.m128_i32[0] & v4.m128_i32[0] | _mm_andnot_ps(v4, v2).m128_u32[0];
  return (float)((float)((float)((float)((float)((float)((float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) * -0.0046817539)
                                                       + 0.079692625)
                                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                                       + -0.64596409)
                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                       + 1.5707964)
               * COERCE_FLOAT(v1.m128_i32[0] | (_mm_and_si128(v3, _mm_cvtsi32_si128(2u)).m128i_u32[0] << 30)));
}

} // namespace choreogen

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10261810
// Name: float FastCos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FastCos(unsigned int x)
{
  __m128 v1; // xmm0
  unsigned int v2; // edx
  __m128 v3; // xmm6
  float v4; // xmm5_4

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = ((int)v1.m128_f32[0] << 30) & 0x80000000;
  v3 = (__m128)sincos_masks[(int)v1.m128_f32[0] & 1];
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - (float)(int)v1.m128_f32[0], 1.0);
  LODWORD(v4) = COERCE_UNSIGNED_INT(1.0 - v1.m128_f32[0]) & v3.m128_i32[0] | _mm_andnot_ps(v3, v1).m128_u32[0];
  return (float)(COERCE_FLOAT(LODWORD(v4) | v2)
               * (float)((float)((float)((float)((float)((float)((float)(v4 * v4) * -0.0046817539) + 0.079692625)
                                               * (float)(v4 * v4))
                                       + -0.64596409)
                               * (float)(v4 * v4))
                       + 1.5707964));
}

} // namespace engine_xlsp

// ============================================================
// Overlay from meshutilstest (Missing functions)
// ============================================================
namespace meshutilstest {

//------------------------------------------------------------------------------
// Address: 0x00406D40
// Name: float _SSE_Sqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_Sqrt(float x)
{
  return fsqrt(x);
}

//------------------------------------------------------------------------------
// Address: 0x00406D60
// Name: float _SSE_RSqrtAccurate(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_RSqrtAccurate(float a)
{
  float v1; // xmm0_4

  v1 = 1.0 / fsqrt(a);
  return (float)((float)((float)0.5 * v1) * (float)((float)3.0 - (float)((float)(a * v1) * v1)));
}

//------------------------------------------------------------------------------
// Address: 0x00406DB0
// Name: void _SSE_VectorNormalizeFast(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall _SSE_VectorNormalizeFast(Vector *vec)
{
  float v1; // xmm0_4
  float v2; // [esp+0h] [ebp-40h]
  float v3; // [esp+30h] [ebp-10h]

  v3 = vec->z * vec->z + vec->y * vec->y + vec->x * vec->x + 0.00000011920929;
  v1 = 1.0 / fsqrt(v3);
  v2 = (float)((float)0.5 * v1) * (float)((float)3.0 - (float)((float)(v3 * v1) * v1));
  vec->x = vec->x * v2;
  vec->y = v2 * vec->y;
  vec->z = v2 * vec->z;
}

//------------------------------------------------------------------------------
// Address: 0x00406E40
// Name: float _SSE_InvRSquared(float const __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall _SSE_InvRSquared@<st0>(__m128 a1@<xmm3>, __m128 *v)
{
  __m128 v2; // xmm1

  v2 = _mm_mul_ps(*v, *v);
  return (float)(1.0
               / fmaxf(
                   (float)(v2.m128_f32[0] + _mm_shuffle_ps(v2, v2, 1).m128_f32[0]) + _mm_movehl_ps(a1, v2).m128_f32[0],
                   1.0));
}

//------------------------------------------------------------------------------
// Address: 0x00406E80
// Name: void _SSE_SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall _SSE_SinCos(__m128 a1@<xmm2>, __m128 a2@<xmm6>, unsigned int x, float *s, float *c)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm0
  int v7; // ecx
  int v8; // edx
  __m128 v9; // xmm3
  int v10; // xmm4_4
  float v11; // xmm5_4

  v5 = (__m128)x;
  v5.m128_f32[0] = *(float *)&x * 0.63661975;
  v6 = _mm_and_ps(v5, (__m128)0x7FFFFFFFu);
  v7 = (int)v6.m128_f32[0] << 30;
  v8 = ((int)v6.m128_f32[0] + 1) << 30;
  v9 = (__m128)sincos_inv_masks[(int)v6.m128_f32[0] & 1];
  v6.m128_f32[0] = fminf(v6.m128_f32[0] - (float)(int)v6.m128_f32[0], 1.0);
  a2.m128_f32[0] = 1.0 - v6.m128_f32[0];
  v10 = a2.m128_i32[0] & v9.m128_i32[0];
  a1.m128_f32[0] = v9.m128_f32[0];
  v9.m128_f32[0] = _mm_andnot_ps(v9, v6).m128_f32[0];
  v6.m128_i32[0] = v6.m128_i32[0] & a1.m128_i32[0] | _mm_andnot_ps(a1, a2).m128_u32[0];
  LODWORD(v11) = v10 | v9.m128_i32[0];
  *s = (float)((float)((float)((float)((float)((float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) * -0.0046817539)
                                             + 0.079692625)
                                     * (float)(v6.m128_f32[0] * v6.m128_f32[0]))
                             + -0.64596409)
                     * (float)(v6.m128_f32[0] * v6.m128_f32[0]))
             + 1.5707964)
     * COERCE_FLOAT(v6.m128_i32[0] | x & 0x80000000 ^ v7 & 0x80000000);
  *c = (float)((float)((float)((float)((float)((float)((float)(v11 * v11) * -0.0046817539) + 0.079692625)
                                     * (float)(v11 * v11))
                             + -0.64596409)
                     * (float)(v11 * v11))
             + 1.5707964)
     * COERCE_FLOAT(LODWORD(v11) | v8 & 0x80000000);
}

//------------------------------------------------------------------------------
// Address: 0x00406FC0
// Name: float _SSE_cos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_cos(unsigned int x)
{
  __m128 v1; // xmm0
  unsigned int v2; // edx
  __m128 v3; // xmm6

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = ((int)v1.m128_f32[0] << 30) & 0x80000000;
  v3 = (__m128)sincos_masks[(int)v1.m128_f32[0] & 1];
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - (float)(int)v1.m128_f32[0], 1.0);
  v1.m128_i32[0] = COERCE_UNSIGNED_INT(1.0 - v1.m128_f32[0]) & v3.m128_i32[0] | _mm_andnot_ps(v3, v1).m128_u32[0];
  return (float)(COERCE_FLOAT(v1.m128_i32[0] | v2)
               * (float)((float)((float)((float)((float)((float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) * -0.0046817539)
                                                       + 0.079692625)
                                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                                       + -0.64596409)
                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                       + 1.5707964));
}

//------------------------------------------------------------------------------
// Address: 0x00407090
// Name: void _SSE2_SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _SSE2_SinCos(unsigned int x, float *s, float *c)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm4
  __m128i v5; // xmm2
  __m128i v6; // xmm1
  __m128 v7; // xmm5
  float v8; // xmm6_4

  v3 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v3.m128_f32[0] = v3.m128_f32[0] * 0.63661975;
  v4 = (__m128)0x3F800000u;
  v5 = _mm_cvttps_epi32(v3);
  v6 = _mm_cvtsi32_si128(2u);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(_mm_cvtsi32_si128(1u), v5), (__m128i)0LL);
  v3.m128_f32[0] = fminf(v3.m128_f32[0] - _mm_cvtepi32_ps(v5).m128_f32[0], 1.0);
  v4.m128_f32[0] = 1.0 - v3.m128_f32[0];
  LODWORD(v8) = COERCE_UNSIGNED_INT(1.0 - v3.m128_f32[0]) & v7.m128_i32[0] | _mm_andnot_ps(v7, v3).m128_u32[0];
  v3.m128_i32[0] = v3.m128_i32[0] & v7.m128_i32[0] | _mm_andnot_ps(v7, v4).m128_u32[0];
  *s = (float)((float)((float)((float)((float)((float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) * -0.0046817539)
                                             + 0.079692625)
                                     * (float)(v3.m128_f32[0] * v3.m128_f32[0]))
                             + -0.64596409)
                     * (float)(v3.m128_f32[0] * v3.m128_f32[0]))
             + 1.5707964)
     * COERCE_FLOAT(v3.m128_i32[0] | (_mm_and_si128(v5, v6).m128i_u32[0] << 30) ^ x & 0x80000000);
  *c = (float)((float)((float)((float)((float)((float)((float)(v8 * v8) * -0.0046817539) + 0.079692625)
                                     * (float)(v8 * v8))
                             + -0.64596409)
                     * (float)(v8 * v8))
             + 1.5707964)
     * COERCE_FLOAT(LODWORD(v8) | (_mm_and_si128(_mm_add_epi32(_mm_cvtsi32_si128(1u), v5), v6).m128i_u32[0] << 30));
}

//------------------------------------------------------------------------------
// Address: 0x004071B0
// Name: float _SSE2_cos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE2_cos(unsigned int x)
{
  __m128 v1; // xmm0
  __m128 v2; // xmm4
  __m128i v3; // xmm2
  __m128 v4; // xmm5

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = (__m128)0x3F800000u;
  v3 = _mm_cvttps_epi32(v1);
  v4 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(_mm_cvtsi32_si128(1u), v3), (__m128i)0LL);
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - _mm_cvtepi32_ps(v3).m128_f32[0], 1.0);
  v2.m128_f32[0] = 1.0 - v1.m128_f32[0];
  v1.m128_i32[0] = v1.m128_i32[0] & v4.m128_i32[0] | _mm_andnot_ps(v4, v2).m128_u32[0];
  return (float)((float)((float)((float)((float)((float)((float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) * -0.0046817539)
                                                       + 0.079692625)
                                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                                       + -0.64596409)
                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                       + 1.5707964)
               * COERCE_FLOAT(v1.m128_i32[0] | (_mm_and_si128(v3, _mm_cvtsi32_si128(2u)).m128i_u32[0] << 30)));
}

} // namespace meshutilstest

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00442640
// Name: float _SSE_Sqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_Sqrt(float x)
{
  return fsqrt(x);
}

//------------------------------------------------------------------------------
// Address: 0x00442660
// Name: float _SSE_RSqrtAccurate(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_RSqrtAccurate(float a)
{
  float v1; // xmm0_4

  v1 = 1.0 / fsqrt(a);
  return (float)((float)((float)0.5 * v1) * (float)((float)3.0 - (float)((float)(a * v1) * v1)));
}

//------------------------------------------------------------------------------
// Address: 0x004426B0
// Name: float _SSE_RSqrtFast(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_RSqrtFast(float x)
{
  return (float)(1.0 / fsqrt(x));
}

//------------------------------------------------------------------------------
// Address: 0x004426D0
// Name: void _SSE_VectorNormalizeFast(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall _SSE_VectorNormalizeFast(Vector *vec)
{
  float v1; // xmm0_4
  float v2; // [esp+0h] [ebp-40h]
  float v3; // [esp+30h] [ebp-10h]

  v3 = vec->z * vec->z + vec->y * vec->y + vec->x * vec->x + 0.00000011920929;
  v1 = 1.0 / fsqrt(v3);
  v2 = (float)((float)0.5 * v1) * (float)((float)3.0 - (float)((float)(v3 * v1) * v1));
  vec->x = vec->x * v2;
  vec->y = v2 * vec->y;
  vec->z = v2 * vec->z;
}

//------------------------------------------------------------------------------
// Address: 0x00442760
// Name: float _SSE_InvRSquared(float const __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall _SSE_InvRSquared@<st0>(__m128 a1@<xmm3>, __m128 *v)
{
  __m128 v2; // xmm1

  v2 = _mm_mul_ps(*v, *v);
  return (float)(1.0
               / fmaxf(
                   (float)(v2.m128_f32[0] + _mm_shuffle_ps(v2, v2, 1).m128_f32[0]) + _mm_movehl_ps(a1, v2).m128_f32[0],
                   1.0));
}

//------------------------------------------------------------------------------
// Address: 0x004427A0
// Name: void _SSE_SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall _SSE_SinCos(__m128 a1@<xmm2>, __m128 a2@<xmm6>, unsigned int x, float *s, float *c)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm0
  int v7; // ecx
  int v8; // edx
  __m128 v9; // xmm3
  int v10; // xmm4_4
  float v11; // xmm5_4

  v5 = (__m128)x;
  v5.m128_f32[0] = *(float *)&x * 0.63661975;
  v6 = _mm_and_ps(v5, (__m128)0x7FFFFFFFu);
  v7 = (int)v6.m128_f32[0] << 30;
  v8 = ((int)v6.m128_f32[0] + 1) << 30;
  v9 = (__m128)sincos_inv_masks[(int)v6.m128_f32[0] & 1];
  v6.m128_f32[0] = fminf(v6.m128_f32[0] - (float)(int)v6.m128_f32[0], 1.0);
  a2.m128_f32[0] = 1.0 - v6.m128_f32[0];
  v10 = a2.m128_i32[0] & v9.m128_i32[0];
  a1.m128_f32[0] = v9.m128_f32[0];
  v9.m128_f32[0] = _mm_andnot_ps(v9, v6).m128_f32[0];
  v6.m128_i32[0] = v6.m128_i32[0] & a1.m128_i32[0] | _mm_andnot_ps(a1, a2).m128_u32[0];
  LODWORD(v11) = v10 | v9.m128_i32[0];
  *s = (float)((float)((float)((float)((float)((float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) * -0.0046817539)
                                             + 0.079692625)
                                     * (float)(v6.m128_f32[0] * v6.m128_f32[0]))
                             + -0.64596409)
                     * (float)(v6.m128_f32[0] * v6.m128_f32[0]))
             + 1.5707964)
     * COERCE_FLOAT(v6.m128_i32[0] | x & 0x80000000 ^ v7 & 0x80000000);
  *c = (float)((float)((float)((float)((float)((float)((float)(v11 * v11) * -0.0046817539) + 0.079692625)
                                     * (float)(v11 * v11))
                             + -0.64596409)
                     * (float)(v11 * v11))
             + 1.5707964)
     * COERCE_FLOAT(LODWORD(v11) | v8 & 0x80000000);
}

//------------------------------------------------------------------------------
// Address: 0x004428E0
// Name: float _SSE_cos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_cos(unsigned int x)
{
  __m128 v1; // xmm0
  unsigned int v2; // edx
  __m128 v3; // xmm6

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = ((int)v1.m128_f32[0] << 30) & 0x80000000;
  v3 = (__m128)sincos_masks[(int)v1.m128_f32[0] & 1];
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - (float)(int)v1.m128_f32[0], 1.0);
  v1.m128_i32[0] = COERCE_UNSIGNED_INT(1.0 - v1.m128_f32[0]) & v3.m128_i32[0] | _mm_andnot_ps(v3, v1).m128_u32[0];
  return (float)(COERCE_FLOAT(v1.m128_i32[0] | v2)
               * (float)((float)((float)((float)((float)((float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) * -0.0046817539)
                                                       + 0.079692625)
                                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                                       + -0.64596409)
                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                       + 1.5707964));
}

//------------------------------------------------------------------------------
// Address: 0x004429B0
// Name: void _SSE2_SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _SSE2_SinCos(unsigned int x, float *s, float *c)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm4
  __m128i v5; // xmm2
  __m128i v6; // xmm1
  __m128 v7; // xmm5
  float v8; // xmm6_4

  v3 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v3.m128_f32[0] = v3.m128_f32[0] * 0.63661975;
  v4 = (__m128)0x3F800000u;
  v5 = _mm_cvttps_epi32(v3);
  v6 = _mm_cvtsi32_si128(2u);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(_mm_cvtsi32_si128(1u), v5), (__m128i)0LL);
  v3.m128_f32[0] = fminf(v3.m128_f32[0] - _mm_cvtepi32_ps(v5).m128_f32[0], 1.0);
  v4.m128_f32[0] = 1.0 - v3.m128_f32[0];
  LODWORD(v8) = COERCE_UNSIGNED_INT(1.0 - v3.m128_f32[0]) & v7.m128_i32[0] | _mm_andnot_ps(v7, v3).m128_u32[0];
  v3.m128_i32[0] = v3.m128_i32[0] & v7.m128_i32[0] | _mm_andnot_ps(v7, v4).m128_u32[0];
  *s = (float)((float)((float)((float)((float)((float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) * -0.0046817539)
                                             + 0.079692625)
                                     * (float)(v3.m128_f32[0] * v3.m128_f32[0]))
                             + -0.64596409)
                     * (float)(v3.m128_f32[0] * v3.m128_f32[0]))
             + 1.5707964)
     * COERCE_FLOAT(v3.m128_i32[0] | (_mm_and_si128(v5, v6).m128i_u32[0] << 30) ^ x & 0x80000000);
  *c = (float)((float)((float)((float)((float)((float)((float)(v8 * v8) * -0.0046817539) + 0.079692625)
                                     * (float)(v8 * v8))
                             + -0.64596409)
                     * (float)(v8 * v8))
             + 1.5707964)
     * COERCE_FLOAT(LODWORD(v8) | (_mm_and_si128(_mm_add_epi32(_mm_cvtsi32_si128(1u), v5), v6).m128i_u32[0] << 30));
}

//------------------------------------------------------------------------------
// Address: 0x00442AD0
// Name: float _SSE2_cos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE2_cos(unsigned int x)
{
  __m128 v1; // xmm0
  __m128 v2; // xmm4
  __m128i v3; // xmm2
  __m128 v4; // xmm5

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = (__m128)0x3F800000u;
  v3 = _mm_cvttps_epi32(v1);
  v4 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(_mm_cvtsi32_si128(1u), v3), (__m128i)0LL);
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - _mm_cvtepi32_ps(v3).m128_f32[0], 1.0);
  v2.m128_f32[0] = 1.0 - v1.m128_f32[0];
  v1.m128_i32[0] = v1.m128_i32[0] & v4.m128_i32[0] | _mm_andnot_ps(v4, v2).m128_u32[0];
  return (float)((float)((float)((float)((float)((float)((float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) * -0.0046817539)
                                                       + 0.079692625)
                                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                                       + -0.64596409)
                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                       + 1.5707964)
               * COERCE_FLOAT(v1.m128_i32[0] | (_mm_and_si128(v3, _mm_cvtsi32_si128(2u)).m128i_u32[0] << 30)));
}

} // namespace pcffix

// ============================================================
// Overlay from worldrenderertest (Missing functions)
// ============================================================
namespace worldrenderertest {

//------------------------------------------------------------------------------
// Address: 0x0040EFE0
// Name: float _SSE_Sqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_Sqrt(float x)
{
  return fsqrt(x);
}

//------------------------------------------------------------------------------
// Address: 0x0040F000
// Name: float _SSE_RSqrtAccurate(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_RSqrtAccurate(float a)
{
  float v1; // xmm0_4

  v1 = 1.0 / fsqrt(a);
  return (float)((float)((float)0.5 * v1) * (float)((float)3.0 - (float)((float)(a * v1) * v1)));
}

//------------------------------------------------------------------------------
// Address: 0x0040F050
// Name: void _SSE_VectorNormalizeFast(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall _SSE_VectorNormalizeFast(Vector *vec)
{
  float v1; // xmm0_4
  float v2; // [esp+0h] [ebp-40h]
  float v3; // [esp+30h] [ebp-10h]

  v3 = vec->z * vec->z + vec->y * vec->y + vec->x * vec->x + 0.00000011920929;
  v1 = 1.0 / fsqrt(v3);
  v2 = (float)((float)0.5 * v1) * (float)((float)3.0 - (float)((float)(v3 * v1) * v1));
  vec->x = vec->x * v2;
  vec->y = v2 * vec->y;
  vec->z = v2 * vec->z;
}

//------------------------------------------------------------------------------
// Address: 0x0040F0E0
// Name: float _SSE_InvRSquared(float const __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall _SSE_InvRSquared@<st0>(__m128 a1@<xmm3>, __m128 *v)
{
  __m128 v2; // xmm1

  v2 = _mm_mul_ps(*v, *v);
  return (float)(1.0
               / fmaxf(
                   (float)(v2.m128_f32[0] + _mm_shuffle_ps(v2, v2, 1).m128_f32[0]) + _mm_movehl_ps(a1, v2).m128_f32[0],
                   1.0));
}

//------------------------------------------------------------------------------
// Address: 0x0040F120
// Name: void _SSE_SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall _SSE_SinCos(__m128 a1@<xmm2>, __m128 a2@<xmm6>, unsigned int x, float *s, float *c)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm0
  int v7; // ecx
  int v8; // edx
  __m128 v9; // xmm3
  int v10; // xmm4_4
  float v11; // xmm5_4

  v5 = (__m128)x;
  v5.m128_f32[0] = *(float *)&x * 0.63661975;
  v6 = _mm_and_ps(v5, (__m128)0x7FFFFFFFu);
  v7 = (int)v6.m128_f32[0] << 30;
  v8 = ((int)v6.m128_f32[0] + 1) << 30;
  v9 = (__m128)sincos_inv_masks[(int)v6.m128_f32[0] & 1];
  v6.m128_f32[0] = fminf(v6.m128_f32[0] - (float)(int)v6.m128_f32[0], 1.0);
  a2.m128_f32[0] = 1.0 - v6.m128_f32[0];
  v10 = a2.m128_i32[0] & v9.m128_i32[0];
  a1.m128_f32[0] = v9.m128_f32[0];
  v9.m128_f32[0] = _mm_andnot_ps(v9, v6).m128_f32[0];
  v6.m128_i32[0] = v6.m128_i32[0] & a1.m128_i32[0] | _mm_andnot_ps(a1, a2).m128_u32[0];
  LODWORD(v11) = v10 | v9.m128_i32[0];
  *s = (float)((float)((float)((float)((float)((float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) * -0.0046817539)
                                             + 0.079692625)
                                     * (float)(v6.m128_f32[0] * v6.m128_f32[0]))
                             + -0.64596409)
                     * (float)(v6.m128_f32[0] * v6.m128_f32[0]))
             + 1.5707964)
     * COERCE_FLOAT(v6.m128_i32[0] | x & 0x80000000 ^ v7 & 0x80000000);
  *c = (float)((float)((float)((float)((float)((float)((float)(v11 * v11) * -0.0046817539) + 0.079692625)
                                     * (float)(v11 * v11))
                             + -0.64596409)
                     * (float)(v11 * v11))
             + 1.5707964)
     * COERCE_FLOAT(LODWORD(v11) | v8 & 0x80000000);
}

//------------------------------------------------------------------------------
// Address: 0x0040F260
// Name: float _SSE_cos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE_cos(unsigned int x)
{
  __m128 v1; // xmm0
  unsigned int v2; // edx
  __m128 v3; // xmm6

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = ((int)v1.m128_f32[0] << 30) & 0x80000000;
  v3 = (__m128)sincos_masks[(int)v1.m128_f32[0] & 1];
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - (float)(int)v1.m128_f32[0], 1.0);
  v1.m128_i32[0] = COERCE_UNSIGNED_INT(1.0 - v1.m128_f32[0]) & v3.m128_i32[0] | _mm_andnot_ps(v3, v1).m128_u32[0];
  return (float)(COERCE_FLOAT(v1.m128_i32[0] | v2)
               * (float)((float)((float)((float)((float)((float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) * -0.0046817539)
                                                       + 0.079692625)
                                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                                       + -0.64596409)
                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                       + 1.5707964));
}

//------------------------------------------------------------------------------
// Address: 0x0040F330
// Name: void _SSE2_SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _SSE2_SinCos(unsigned int x, float *s, float *c)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm4
  __m128i v5; // xmm2
  __m128i v6; // xmm1
  __m128 v7; // xmm5
  float v8; // xmm6_4

  v3 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v3.m128_f32[0] = v3.m128_f32[0] * 0.63661975;
  v4 = (__m128)0x3F800000u;
  v5 = _mm_cvttps_epi32(v3);
  v6 = _mm_cvtsi32_si128(2u);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(_mm_cvtsi32_si128(1u), v5), (__m128i)0LL);
  v3.m128_f32[0] = fminf(v3.m128_f32[0] - _mm_cvtepi32_ps(v5).m128_f32[0], 1.0);
  v4.m128_f32[0] = 1.0 - v3.m128_f32[0];
  LODWORD(v8) = COERCE_UNSIGNED_INT(1.0 - v3.m128_f32[0]) & v7.m128_i32[0] | _mm_andnot_ps(v7, v3).m128_u32[0];
  v3.m128_i32[0] = v3.m128_i32[0] & v7.m128_i32[0] | _mm_andnot_ps(v7, v4).m128_u32[0];
  *s = (float)((float)((float)((float)((float)((float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) * -0.0046817539)
                                             + 0.079692625)
                                     * (float)(v3.m128_f32[0] * v3.m128_f32[0]))
                             + -0.64596409)
                     * (float)(v3.m128_f32[0] * v3.m128_f32[0]))
             + 1.5707964)
     * COERCE_FLOAT(v3.m128_i32[0] | (_mm_and_si128(v5, v6).m128i_u32[0] << 30) ^ x & 0x80000000);
  *c = (float)((float)((float)((float)((float)((float)((float)(v8 * v8) * -0.0046817539) + 0.079692625)
                                     * (float)(v8 * v8))
                             + -0.64596409)
                     * (float)(v8 * v8))
             + 1.5707964)
     * COERCE_FLOAT(LODWORD(v8) | (_mm_and_si128(_mm_add_epi32(_mm_cvtsi32_si128(1u), v5), v6).m128i_u32[0] << 30));
}

//------------------------------------------------------------------------------
// Address: 0x0040F450
// Name: float _SSE2_cos(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _SSE2_cos(unsigned int x)
{
  __m128 v1; // xmm0
  __m128 v2; // xmm4
  __m128i v3; // xmm2
  __m128 v4; // xmm5

  v1 = _mm_and_ps((__m128)x, (__m128)0x7FFFFFFFu);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] + 1.5707964) * 0.63661975;
  v2 = (__m128)0x3F800000u;
  v3 = _mm_cvttps_epi32(v1);
  v4 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(_mm_cvtsi32_si128(1u), v3), (__m128i)0LL);
  v1.m128_f32[0] = fminf(v1.m128_f32[0] - _mm_cvtepi32_ps(v3).m128_f32[0], 1.0);
  v2.m128_f32[0] = 1.0 - v1.m128_f32[0];
  v1.m128_i32[0] = v1.m128_i32[0] & v4.m128_i32[0] | _mm_andnot_ps(v4, v2).m128_u32[0];
  return (float)((float)((float)((float)((float)((float)((float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) * -0.0046817539)
                                                       + 0.079692625)
                                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                                       + -0.64596409)
                               * (float)(v1.m128_f32[0] * v1.m128_f32[0]))
                       + 1.5707964)
               * COERCE_FLOAT(v1.m128_i32[0] | (_mm_and_si128(v3, _mm_cvtsi32_si128(2u)).m128i_u32[0] << 30)));
}

} // namespace worldrenderertest
