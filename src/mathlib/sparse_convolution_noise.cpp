// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/sparse_convolution_noise.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10263470
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_10428E10[(unsigned __int8)((int)va + dword_10428E10[(unsigned __int8)(int)fxa])];
  v26 = dword_10428E10[(unsigned __int8)((int)va + dword_10428E10[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_10428E10[(unsigned __int8)((int)va + dword_10428E10[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_10428E10[(unsigned __int8)((int)va + dword_10428E10[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_10428E10[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_10428E10[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_10428E10[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_10428E10[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_10428E10[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_10428E10[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_10428E10[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_10428E10[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_10428E10[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_10428E10[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_10428E10[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_10428E10[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_10428E10[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_10428E10[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_10428E10[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_10428E10[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_10428E10[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_10428E10[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_10428E10[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_10428E10[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_10428E10[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_10428E10[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_10428E10[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_10428E10[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_10428E10[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_10428E10[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_10428E10[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_10428E10[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_10428E10[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_10428E10[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_10428E10[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_10428E10[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1002BB50
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_100F14F8[(unsigned __int8)((int)va + dword_100F14F8[(unsigned __int8)(int)fxa])];
  v26 = dword_100F14F8[(unsigned __int8)((int)va + dword_100F14F8[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_100F14F8[(unsigned __int8)((int)va + dword_100F14F8[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_100F14F8[(unsigned __int8)((int)va + dword_100F14F8[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_100F14F8[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_100F14F8[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_100F14F8[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_100F14F8[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_100F14F8[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_100F14F8[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_100F14F8[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_100F14F8[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_100F14F8[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_100F14F8[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_100F14F8[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_100F14F8[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_100F14F8[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_100F14F8[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_100F14F8[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_100F14F8[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_100F14F8[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_100F14F8[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_100F14F8[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_100F14F8[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_100F14F8[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_100F14F8[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_100F14F8[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_100F14F8[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_100F14F8[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_100F14F8[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_100F14F8[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_100F14F8[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_100F14F8[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_100F14F8[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_100F14F8[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_100F14F8[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace dedicated

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x005A8080
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_6014E8[(unsigned __int8)((int)va + dword_6014E8[(unsigned __int8)(int)fxa])];
  v26 = dword_6014E8[(unsigned __int8)((int)va + dword_6014E8[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_6014E8[(unsigned __int8)((int)va + dword_6014E8[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_6014E8[(unsigned __int8)((int)va + dword_6014E8[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_6014E8[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_6014E8[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_6014E8[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_6014E8[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_6014E8[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_6014E8[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_6014E8[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_6014E8[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_6014E8[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_6014E8[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_6014E8[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_6014E8[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_6014E8[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_6014E8[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_6014E8[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_6014E8[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_6014E8[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_6014E8[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_6014E8[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_6014E8[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_6014E8[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_6014E8[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_6014E8[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_6014E8[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_6014E8[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_6014E8[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_6014E8[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_6014E8[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_6014E8[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_6014E8[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_6014E8[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_6014E8[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00678130
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_758AD0[(unsigned __int8)((int)va + dword_758AD0[(unsigned __int8)(int)fxa])];
  v26 = dword_758AD0[(unsigned __int8)((int)va + dword_758AD0[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_758AD0[(unsigned __int8)((int)va + dword_758AD0[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_758AD0[(unsigned __int8)((int)va + dword_758AD0[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_758AD0[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_758AD0[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_758AD0[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_758AD0[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_758AD0[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_758AD0[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_758AD0[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_758AD0[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_758AD0[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_758AD0[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_758AD0[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_758AD0[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_758AD0[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_758AD0[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_758AD0[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_758AD0[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_758AD0[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_758AD0[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_758AD0[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_758AD0[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_758AD0[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_758AD0[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_758AD0[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_758AD0[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_758AD0[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_758AD0[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_758AD0[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_758AD0[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_758AD0[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_758AD0[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_758AD0[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_758AD0[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102634A0
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_10428E10[(unsigned __int8)((int)va + dword_10428E10[(unsigned __int8)(int)fxa])];
  v26 = dword_10428E10[(unsigned __int8)((int)va + dword_10428E10[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_10428E10[(unsigned __int8)((int)va + dword_10428E10[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_10428E10[(unsigned __int8)((int)va + dword_10428E10[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_10428E10[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_10428E10[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_10428E10[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_10428E10[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_10428E10[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_10428E10[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_10428E10[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_10428E10[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_10428E10[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_10428E10[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_10428E10[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_10428E10[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_10428E10[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_10428E10[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_10428E10[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_10428E10[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_10428E10[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_10428E10[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_10428E10[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_10428E10[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_10428E10[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_10428E10[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_10428E10[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_10428E10[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_10428E10[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_10428E10[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_10428E10[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_10428E10[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_10428E10[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_10428E10[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_10428E10[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_10428E10[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1059F730
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_10784020[(unsigned __int8)((int)va + dword_10784020[(unsigned __int8)(int)fxa])];
  v26 = dword_10784020[(unsigned __int8)((int)va + dword_10784020[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_10784020[(unsigned __int8)((int)va + dword_10784020[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_10784020[(unsigned __int8)((int)va + dword_10784020[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_10784020[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_10784020[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_10784020[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_10784020[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_10784020[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_10784020[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_10784020[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_10784020[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_10784020[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_10784020[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_10784020[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_10784020[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_10784020[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_10784020[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_10784020[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_10784020[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_10784020[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_10784020[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_10784020[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_10784020[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_10784020[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_10784020[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_10784020[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_10784020[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_10784020[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_10784020[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_10784020[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_10784020[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_10784020[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_10784020[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_10784020[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_10784020[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace hammer_dll

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005EA5D0
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_65A770[(unsigned __int8)((int)va + dword_65A770[(unsigned __int8)(int)fxa])];
  v26 = dword_65A770[(unsigned __int8)((int)va + dword_65A770[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_65A770[(unsigned __int8)((int)va + dword_65A770[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_65A770[(unsigned __int8)((int)va + dword_65A770[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_65A770[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_65A770[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_65A770[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_65A770[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_65A770[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_65A770[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_65A770[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_65A770[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_65A770[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_65A770[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_65A770[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_65A770[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_65A770[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_65A770[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_65A770[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_65A770[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_65A770[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_65A770[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_65A770[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_65A770[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_65A770[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_65A770[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_65A770[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_65A770[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_65A770[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_65A770[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_65A770[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_65A770[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_65A770[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_65A770[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_65A770[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_65A770[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

//------------------------------------------------------------------------------
// Address: 0x005EAB76
// Name: __getextendedkeycode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const NormKeyVals *__cdecl _getextendedkeycode(_KEY_EVENT_RECORD *pKE)
{
  unsigned int dwControlKeyState; // ebx
  const NormKeyVals *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // ecx
  int wVirtualScanCode; // eax

  dwControlKeyState = pKE->dwControlKeyState;
  if ( (dwControlKeyState & 0x100) != 0 )
  {
    result = nullptr;
    v3 = 0;
    v4 = 0;
    while ( EnhancedKeys[v4].ScanCode != pKE->wVirtualScanCode )
    {
      ++v4;
      ++v3;
      if ( v4 >= 12 )
        return result;
    }
    v5 = v3;
    if ( (dwControlKeyState & 3) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].AltChars;
    if ( (dwControlKeyState & 0xC) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].CtrlChars;
    if ( (dwControlKeyState & 0x10) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].ShiftChars;
    return (const NormKeyVals *)&EnhancedKeys[v5].RegChars;
  }
  else
  {
    wVirtualScanCode = pKE->wVirtualScanCode;
    if ( (dwControlKeyState & 3) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].AltChars;
    }
    else if ( (dwControlKeyState & 0xC) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].CtrlChars;
    }
    else if ( (dwControlKeyState & 0x10) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].ShiftChars;
    }
    else
    {
      result = &NormalKeys[wVirtualScanCode];
    }
    if ( result->RegChars.LeadChar != 0 && result->RegChars.LeadChar != 0xE0 || result->RegChars.SecondChar == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EAC29
// Name: __getch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getch_nolock()
{
  int result; // eax
  int AsciiChar; // edi
  const NormKeyVals *v2; // eax
  unsigned int oldstate; // [esp+4h] [ebp-20h] BYREF
  unsigned int NumRead; // [esp+8h] [ebp-1Ch] BYREF
  _INPUT_RECORD ConInpRec; // [esp+Ch] [ebp-18h] BYREF

  if ( chbuf == -1 )
  {
    if ( _coninpfh == (HANDLE)-2 )
      __initconin();
    if ( _coninpfh == (HANDLE)-1 )
    {
      return -1;
    }
    else
    {
      GetConsoleMode(hConsoleHandle: _coninpfh, lpMode: &oldstate);
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: 0);
      while ( 1 )
      {
        if ( !ReadConsoleInputA(
                hConsoleInput: _coninpfh,
                lpBuffer: &ConInpRec,
                nLength: 1u,
                lpNumberOfEventsRead: &NumRead)
          || NumRead == 0 )
        {
          AsciiChar = -1;
          goto LABEL_15;
        }
        if ( ConInpRec.EventType == 1 && ConInpRec.Event.KeyEvent.bKeyDown != 0 )
        {
          AsciiChar = (unsigned __int8)ConInpRec.Event.KeyEvent.uChar.AsciiChar;
          if ( ConInpRec.Event.KeyEvent.uChar.AsciiChar != 0 )
            goto LABEL_15;
          v2 = _getextendedkeycode(pKE: &ConInpRec.Event.KeyEvent);
          if ( v2 != nullptr )
            break;
        }
      }
      AsciiChar = v2->RegChars.LeadChar;
      chbuf = v2->RegChars.SecondChar;
LABEL_15:
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: oldstate);
      return AsciiChar;
    }
  }
  else
  {
    result = (unsigned __int8)chbuf;
    chbuf = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EAD02
// Name: _getch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl getch()
{
  int v1; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  v1 = _getch_nolock();
  _unlock(locknum: 3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x005EAD40
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005EAEBE
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EAEF2
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EAF50
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x005EAF90
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd(v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One_0;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EB06D
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONIN$",
             dwDesiredAccess: 0xC0000000,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _coninpfh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EB08C
// Name: ___termconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconin()
{
  HANDLE result; // eax

  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EB0A3
// Name: __ceil_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _ceil_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp();
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xCu, x, savedcw: v1);
    }
    return _except1(a1: (int)&savedregs, flags: 8, opcode: 12, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return v4;
    }
    else
    {
      return _except1(a1: (int)&savedregs, flags: 16, opcode: 12, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EB1D0
// Name: _dynamic_initializer_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupFunctions__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupFunctions__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB1E0
// Name: _dynamic_initializer_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExitStopper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ExitStopper__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB1F0
// Name: _dynamic_initializer_for__g_JointedModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_JointedModel__()
{
  CJointedModel::CJointedModel(this: &g_JointedModel);
  return atexit(func: dynamic_atexit_destructor_for__g_JointedModel__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB210
// Name: _dynamic_initializer_for__s_Balance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_Balance__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_Balance__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB220
// Name: _dynamic_initializer_for__s_Speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_Speed__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_Speed__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB230
// Name: _dynamic_initializer_for__s_UniqueVertices__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_UniqueVertices__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_UniqueVertices__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB240
// Name: _dynamic_initializer_for__s_UniqueVerticesMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_UniqueVerticesMap__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_UniqueVerticesMap__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB250
// Name: _dynamic_initializer_for__s_DeltaStates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DeltaStates__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DeltaStates__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB260
// Name: _dynamic_initializer_for__g_CDmeMdlListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMdlList *dynamic_initializer_for__g_CDmeMdlListPullInModule__()
{
  g_CDmeMdlListPullInModule = g_CDmeMdlListLinkerHack;
  return g_CDmeMdlListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB270
// Name: _dynamic_initializer_for__g_CDmeBBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBBox *dynamic_initializer_for__g_CDmeBBoxPullInModule__()
{
  g_CDmeBBoxPullInModule = g_CDmeBBoxLinkerHack;
  return g_CDmeBBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB280
// Name: _dynamic_initializer_for__g_CDmeHitboxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeHitbox *dynamic_initializer_for__g_CDmeHitboxPullInModule__()
{
  g_CDmeHitboxPullInModule = g_CDmeHitboxLinkerHack;
  return g_CDmeHitboxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB290
// Name: _dynamic_initializer_for__g_CDmeHitboxSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeHitboxSet *dynamic_initializer_for__g_CDmeHitboxSetPullInModule__()
{
  g_CDmeHitboxSetPullInModule = g_CDmeHitboxSetLinkerHack;
  return g_CDmeHitboxSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB2A0
// Name: _dynamic_initializer_for__g_CDmeHitboxSetListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeHitboxSetList *dynamic_initializer_for__g_CDmeHitboxSetListPullInModule__()
{
  g_CDmeHitboxSetListPullInModule = g_CDmeHitboxSetListLinkerHack;
  return g_CDmeHitboxSetListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB2B0
// Name: _dynamic_initializer_for__g_CDmeBodyPartPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBodyPart *dynamic_initializer_for__g_CDmeBodyPartPullInModule__()
{
  g_CDmeBodyPartPullInModule = g_CDmeBodyPartLinkerHack;
  return g_CDmeBodyPartLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB2C0
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPartPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBlankBodyPart *dynamic_initializer_for__g_CDmeBlankBodyPartPullInModule__()
{
  g_CDmeBlankBodyPartPullInModule = g_CDmeBlankBodyPartLinkerHack;
  return g_CDmeBlankBodyPartLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB2D0
// Name: _dynamic_initializer_for__g_CDmeLODPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeLOD *dynamic_initializer_for__g_CDmeLODPullInModule__()
{
  g_CDmeLODPullInModule = g_CDmeLODLinkerHack;
  return g_CDmeLODLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB2E0
// Name: _dynamic_initializer_for__g_CDmeLODListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeLODList *dynamic_initializer_for__g_CDmeLODListPullInModule__()
{
  g_CDmeLODListPullInModule = g_CDmeLODListLinkerHack;
  return g_CDmeLODListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB2F0
// Name: _dynamic_initializer_for__g_CDmeCollisionModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCollisionModel *dynamic_initializer_for__g_CDmeCollisionModelPullInModule__()
{
  g_CDmeCollisionModelPullInModule = g_CDmeCollisionModelLinkerHack;
  return g_CDmeCollisionModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB300
// Name: _dynamic_initializer_for__g_CDmeJointConstrainPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJointConstrain *dynamic_initializer_for__g_CDmeJointConstrainPullInModule__()
{
  g_CDmeJointConstrainPullInModule = g_CDmeJointConstrainLinkerHack;
  return g_CDmeJointConstrainLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB310
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFrictionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJointAnimatedFriction *dynamic_initializer_for__g_CDmeJointAnimatedFrictionPullInModule__()
{
  g_CDmeJointAnimatedFrictionPullInModule = g_CDmeJointAnimatedFrictionLinkerHack;
  return g_CDmeJointAnimatedFrictionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB320
// Name: _dynamic_initializer_for__g_CDmeCollisionJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCollisionJoint *dynamic_initializer_for__g_CDmeCollisionJointPullInModule__()
{
  g_CDmeCollisionJointPullInModule = g_CDmeCollisionJointLinkerHack;
  return g_CDmeCollisionJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB330
// Name: _dynamic_initializer_for__g_CDmeCollisionJointsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCollisionJoints *dynamic_initializer_for__g_CDmeCollisionJointsPullInModule__()
{
  g_CDmeCollisionJointsPullInModule = g_CDmeCollisionJointsLinkerHack;
  return g_CDmeCollisionJointsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB340
// Name: _dynamic_initializer_for__g_CDmeBodyGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBodyGroup *dynamic_initializer_for__g_CDmeBodyGroupPullInModule__()
{
  g_CDmeBodyGroupPullInModule = g_CDmeBodyGroupLinkerHack;
  return g_CDmeBodyGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB350
// Name: _dynamic_initializer_for__g_CDmeBodyGroupListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBodyGroupList *dynamic_initializer_for__g_CDmeBodyGroupListPullInModule__()
{
  g_CDmeBodyGroupListPullInModule = g_CDmeBodyGroupListLinkerHack;
  return g_CDmeBodyGroupListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB360
// Name: _dynamic_initializer_for__g_CDmeBoneWeightPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneWeight *dynamic_initializer_for__g_CDmeBoneWeightPullInModule__()
{
  g_CDmeBoneWeightPullInModule = g_CDmeBoneWeightLinkerHack;
  return g_CDmeBoneWeightLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB370
// Name: _dynamic_initializer_for__g_CDmeBoneMaskPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneMask *dynamic_initializer_for__g_CDmeBoneMaskPullInModule__()
{
  g_CDmeBoneMaskPullInModule = g_CDmeBoneMaskLinkerHack;
  return g_CDmeBoneMaskLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB380
// Name: _dynamic_initializer_for__g_CDmeBoneMaskListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneMaskList *dynamic_initializer_for__g_CDmeBoneMaskListPullInModule__()
{
  g_CDmeBoneMaskListPullInModule = g_CDmeBoneMaskListLinkerHack;
  return g_CDmeBoneMaskListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB390
// Name: _dynamic_initializer_for__g_CDmeMotionControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMotionControl *dynamic_initializer_for__g_CDmeMotionControlPullInModule__()
{
  g_CDmeMotionControlPullInModule = g_CDmeMotionControlLinkerHack;
  return g_CDmeMotionControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB3A0
// Name: _dynamic_initializer_for__g_CDmeIkChainPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkChain *dynamic_initializer_for__g_CDmeIkChainPullInModule__()
{
  g_CDmeIkChainPullInModule = g_CDmeIkChainLinkerHack;
  return g_CDmeIkChainLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB3B0
// Name: _dynamic_initializer_for__g_CDmeIkRangePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkRange *dynamic_initializer_for__g_CDmeIkRangePullInModule__()
{
  g_CDmeIkRangePullInModule = g_CDmeIkRangeLinkerHack;
  return g_CDmeIkRangeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB3C0
// Name: _dynamic_initializer_for__g_CDmeIkLockPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkLock *dynamic_initializer_for__g_CDmeIkLockPullInModule__()
{
  g_CDmeIkLockPullInModule = g_CDmeIkLockLinkerHack;
  return g_CDmeIkLockLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB3D0
// Name: _dynamic_initializer_for__g_CDmeIkRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkRule *dynamic_initializer_for__g_CDmeIkRulePullInModule__()
{
  g_CDmeIkRulePullInModule = g_CDmeIkRuleLinkerHack;
  return g_CDmeIkRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB3E0
// Name: _dynamic_initializer_for__g_CDmeIkTouchRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkTouchRule *dynamic_initializer_for__g_CDmeIkTouchRulePullInModule__()
{
  g_CDmeIkTouchRulePullInModule = g_CDmeIkTouchRuleLinkerHack;
  return g_CDmeIkTouchRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB3F0
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkFootstepRule *dynamic_initializer_for__g_CDmeIkFootstepRulePullInModule__()
{
  g_CDmeIkFootstepRulePullInModule = g_CDmeIkFootstepRuleLinkerHack;
  return g_CDmeIkFootstepRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB400
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkReleaseRule *dynamic_initializer_for__g_CDmeIkReleaseRulePullInModule__()
{
  g_CDmeIkReleaseRulePullInModule = g_CDmeIkReleaseRuleLinkerHack;
  return g_CDmeIkReleaseRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB410
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkAttachmentRule *dynamic_initializer_for__g_CDmeIkAttachmentRulePullInModule__()
{
  g_CDmeIkAttachmentRulePullInModule = g_CDmeIkAttachmentRuleLinkerHack;
  return g_CDmeIkAttachmentRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB420
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmd *dynamic_initializer_for__g_CDmeAnimCmdPullInModule__()
{
  g_CDmeAnimCmdPullInModule = g_CDmeAnimCmdLinkerHack;
  return g_CDmeAnimCmdLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB430
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoopPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdFixupLoop *dynamic_initializer_for__g_CDmeAnimCmdFixupLoopPullInModule__()
{
  g_CDmeAnimCmdFixupLoopPullInModule = g_CDmeAnimCmdFixupLoopLinkerHack;
  return g_CDmeAnimCmdFixupLoopLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB440
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdWeightList *dynamic_initializer_for__g_CDmeAnimCmdWeightListPullInModule__()
{
  g_CDmeAnimCmdWeightListPullInModule = g_CDmeAnimCmdWeightListLinkerHack;
  return g_CDmeAnimCmdWeightListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB450
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtractPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdSubtract *dynamic_initializer_for__g_CDmeAnimCmdSubtractPullInModule__()
{
  g_CDmeAnimCmdSubtractPullInModule = g_CDmeAnimCmdSubtractLinkerHack;
  return g_CDmeAnimCmdSubtractLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB460
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlignPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdAlign *dynamic_initializer_for__g_CDmeAnimCmdAlignPullInModule__()
{
  g_CDmeAnimCmdAlignPullInModule = g_CDmeAnimCmdAlignLinkerHack;
  return g_CDmeAnimCmdAlignLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB470
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateToPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdRotateTo *dynamic_initializer_for__g_CDmeAnimCmdRotateToPullInModule__()
{
  g_CDmeAnimCmdRotateToPullInModule = g_CDmeAnimCmdRotateToLinkerHack;
  return g_CDmeAnimCmdRotateToLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB480
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFramePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdWalkFrame *dynamic_initializer_for__g_CDmeAnimCmdWalkFramePullInModule__()
{
  g_CDmeAnimCmdWalkFramePullInModule = g_CDmeAnimCmdWalkFrameLinkerHack;
  return g_CDmeAnimCmdWalkFrameLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB490
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompressPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdCompress *dynamic_initializer_for__g_CDmeAnimCmdCompressPullInModule__()
{
  g_CDmeAnimCmdCompressPullInModule = g_CDmeAnimCmdCompressLinkerHack;
  return g_CDmeAnimCmdCompressLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB4A0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivativePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdDerivative *dynamic_initializer_for__g_CDmeAnimCmdDerivativePullInModule__()
{
  g_CDmeAnimCmdDerivativePullInModule = g_CDmeAnimCmdDerivativeLinkerHack;
  return g_CDmeAnimCmdDerivativeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB4B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDeltaPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdLinearDelta *dynamic_initializer_for__g_CDmeAnimCmdLinearDeltaPullInModule__()
{
  g_CDmeAnimCmdLinearDeltaPullInModule = g_CDmeAnimCmdLinearDeltaLinkerHack;
  return g_CDmeAnimCmdLinearDeltaLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB4C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDeltaPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdSplineDelta *dynamic_initializer_for__g_CDmeAnimCmdSplineDeltaPullInModule__()
{
  g_CDmeAnimCmdSplineDeltaPullInModule = g_CDmeAnimCmdSplineDeltaLinkerHack;
  return g_CDmeAnimCmdSplineDeltaLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB4D0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFramesPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdNumFrames *dynamic_initializer_for__g_CDmeAnimCmdNumFramesPullInModule__()
{
  g_CDmeAnimCmdNumFramesPullInModule = g_CDmeAnimCmdNumFramesLinkerHack;
  return g_CDmeAnimCmdNumFramesLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB4E0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtractPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdPreSubtract *dynamic_initializer_for__g_CDmeAnimCmdPreSubtractPullInModule__()
{
  g_CDmeAnimCmdPreSubtractPullInModule = g_CDmeAnimCmdPreSubtractLinkerHack;
  return g_CDmeAnimCmdPreSubtractLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB4F0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchyPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdLocalHierarchy *dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchyPullInModule__()
{
  g_CDmeAnimCmdLocalHierarchyPullInModule = g_CDmeAnimCmdLocalHierarchyLinkerHack;
  return g_CDmeAnimCmdLocalHierarchyLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB500
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimationPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdNoAnimation *dynamic_initializer_for__g_CDmeAnimCmdNoAnimationPullInModule__()
{
  g_CDmeAnimCmdNoAnimationPullInModule = g_CDmeAnimCmdNoAnimationLinkerHack;
  return g_CDmeAnimCmdNoAnimationLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB510
// Name: _dynamic_initializer_for__g_CDmeAnimationEventPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationEvent *dynamic_initializer_for__g_CDmeAnimationEventPullInModule__()
{
  g_CDmeAnimationEventPullInModule = g_CDmeAnimationEventLinkerHack;
  return g_CDmeAnimationEventLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB520
// Name: _dynamic_initializer_for__g_CDmeSequenceActivityPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceActivity *dynamic_initializer_for__g_CDmeSequenceActivityPullInModule__()
{
  g_CDmeSequenceActivityPullInModule = g_CDmeSequenceActivityLinkerHack;
  return g_CDmeSequenceActivityLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB530
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceBlendBase *dynamic_initializer_for__g_CDmeSequenceBlendBasePullInModule__()
{
  g_CDmeSequenceBlendBasePullInModule = g_CDmeSequenceBlendBaseLinkerHack;
  return g_CDmeSequenceBlendBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB540
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceBlend *dynamic_initializer_for__g_CDmeSequenceBlendPullInModule__()
{
  g_CDmeSequenceBlendPullInModule = g_CDmeSequenceBlendLinkerHack;
  return g_CDmeSequenceBlendLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB550
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlendPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceCalcBlend *dynamic_initializer_for__g_CDmeSequenceCalcBlendPullInModule__()
{
  g_CDmeSequenceCalcBlendPullInModule = g_CDmeSequenceCalcBlendLinkerHack;
  return g_CDmeSequenceCalcBlendLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB560
// Name: _dynamic_initializer_for__g_CDmeSequenceBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceBase *dynamic_initializer_for__g_CDmeSequenceBasePullInModule__()
{
  g_CDmeSequenceBasePullInModule = g_CDmeSequenceBaseLinkerHack;
  return g_CDmeSequenceBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB570
// Name: _dynamic_initializer_for__g_CDmeSequencePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequence *dynamic_initializer_for__g_CDmeSequencePullInModule__()
{
  g_CDmeSequencePullInModule = g_CDmeSequenceLinkerHack;
  return g_CDmeSequenceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB580
// Name: _dynamic_initializer_for__g_CDmeMultiSequencePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMultiSequence *dynamic_initializer_for__g_CDmeMultiSequencePullInModule__()
{
  g_CDmeMultiSequencePullInModule = g_CDmeMultiSequenceLinkerHack;
  return g_CDmeMultiSequenceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB590
// Name: _dynamic_initializer_for__g_CDmeSequenceListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceList *dynamic_initializer_for__g_CDmeSequenceListPullInModule__()
{
  g_CDmeSequenceListPullInModule = g_CDmeSequenceListLinkerHack;
  return g_CDmeSequenceListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB5A0
// Name: _dynamic_initializer_for__g_CDmeIncludeModelListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIncludeModelList *dynamic_initializer_for__g_CDmeIncludeModelListPullInModule__()
{
  g_CDmeIncludeModelListPullInModule = g_CDmeIncludeModelListLinkerHack;
  return g_CDmeIncludeModelListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB5B0
// Name: _dynamic_initializer_for__g_CDmeDefineBonePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDefineBone *dynamic_initializer_for__g_CDmeDefineBonePullInModule__()
{
  g_CDmeDefineBonePullInModule = g_CDmeDefineBoneLinkerHack;
  return g_CDmeDefineBoneLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB5C0
// Name: _dynamic_initializer_for__g_CDmeDefineBoneListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDefineBoneList *dynamic_initializer_for__g_CDmeDefineBoneListPullInModule__()
{
  g_CDmeDefineBoneListPullInModule = g_CDmeDefineBoneListLinkerHack;
  return g_CDmeDefineBoneListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB5D0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterialGroup *dynamic_initializer_for__g_CDmeMaterialGroupPullInModule__()
{
  g_CDmeMaterialGroupPullInModule = g_CDmeMaterialGroupLinkerHack;
  return g_CDmeMaterialGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB5E0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterialGroupList *dynamic_initializer_for__g_CDmeMaterialGroupListPullInModule__()
{
  g_CDmeMaterialGroupListPullInModule = g_CDmeMaterialGroupListLinkerHack;
  return g_CDmeMaterialGroupListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB5F0
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobalsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEyeballGlobals *dynamic_initializer_for__g_CDmeEyeballGlobalsPullInModule__()
{
  g_CDmeEyeballGlobalsPullInModule = g_CDmeEyeballGlobalsLinkerHack;
  return g_CDmeEyeballGlobalsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB600
// Name: _dynamic_initializer_for__g_CDmeEyeballPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEyeball *dynamic_initializer_for__g_CDmeEyeballPullInModule__()
{
  g_CDmeEyeballPullInModule = g_CDmeEyeballLinkerHack;
  return g_CDmeEyeballLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB610
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolumePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSkinnerVolume *dynamic_initializer_for__g_CDmeSkinnerVolumePullInModule__()
{
  g_CDmeSkinnerVolumePullInModule = g_CDmeSkinnerVolumeLinkerHack;
  return g_CDmeSkinnerVolumeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB620
// Name: _dynamic_initializer_for__g_CDmeSkinnerJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSkinnerJoint *dynamic_initializer_for__g_CDmeSkinnerJointPullInModule__()
{
  g_CDmeSkinnerJointPullInModule = g_CDmeSkinnerJointLinkerHack;
  return g_CDmeSkinnerJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB630
// Name: _dynamic_initializer_for__g_CDmeSkinnerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSkinner *dynamic_initializer_for__g_CDmeSkinnerPullInModule__()
{
  g_CDmeSkinnerPullInModule = g_CDmeSkinnerLinkerHack;
  return g_CDmeSkinnerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB640
// Name: _dynamic_initializer_for__g_CDmePoseParameterPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePoseParameter *dynamic_initializer_for__g_CDmePoseParameterPullInModule__()
{
  g_CDmePoseParameterPullInModule = g_CDmePoseParameterLinkerHack;
  return g_CDmePoseParameterLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB650
// Name: _dynamic_initializer_for__g_CDmePoseParameterListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePoseParameterList *dynamic_initializer_for__g_CDmePoseParameterListPullInModule__()
{
  g_CDmePoseParameterListPullInModule = g_CDmePoseParameterListLinkerHack;
  return g_CDmePoseParameterListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB660
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSizePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimBlockSize *dynamic_initializer_for__g_CDmeAnimBlockSizePullInModule__()
{
  g_CDmeAnimBlockSizePullInModule = g_CDmeAnimBlockSizeLinkerHack;
  return g_CDmeAnimBlockSizeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB670
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceLayerBase *dynamic_initializer_for__g_CDmeSequenceLayerBasePullInModule__()
{
  g_CDmeSequenceLayerBasePullInModule = g_CDmeSequenceLayerBaseLinkerHack;
  return g_CDmeSequenceLayerBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB680
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceAddLayer *dynamic_initializer_for__g_CDmeSequenceAddLayerPullInModule__()
{
  g_CDmeSequenceAddLayerPullInModule = g_CDmeSequenceAddLayerLinkerHack;
  return g_CDmeSequenceAddLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB690
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceBlendLayer *dynamic_initializer_for__g_CDmeSequenceBlendLayerPullInModule__()
{
  g_CDmeSequenceBlendLayerPullInModule = g_CDmeSequenceBlendLayerLinkerHack;
  return g_CDmeSequenceBlendLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB6A0
// Name: _dynamic_initializer_for__g_CDmeAssetRootPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAssetRoot *dynamic_initializer_for__g_CDmeAssetRootPullInModule__()
{
  g_CDmeAssetRootPullInModule = g_CDmeAssetRootLinkerHack;
  return g_CDmeAssetRootLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB6B0
// Name: _dynamic_initializer_for__g_CDmeRelatedAssetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRelatedAsset *dynamic_initializer_for__g_CDmeRelatedAssetPullInModule__()
{
  g_CDmeRelatedAssetPullInModule = g_CDmeRelatedAssetLinkerHack;
  return g_CDmeRelatedAssetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB6C0
// Name: _dynamic_initializer_for__g_CDmeElementGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeElementGroup *dynamic_initializer_for__g_CDmeElementGroupPullInModule__()
{
  g_CDmeElementGroupPullInModule = g_CDmeElementGroupLinkerHack;
  return g_CDmeElementGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB6D0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneFlexDriverControl *dynamic_initializer_for__g_CDmeBoneFlexDriverControlPullInModule__()
{
  g_CDmeBoneFlexDriverControlPullInModule = g_CDmeBoneFlexDriverControlLinkerHack;
  return g_CDmeBoneFlexDriverControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB6E0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneFlexDriver *dynamic_initializer_for__g_CDmeBoneFlexDriverPullInModule__()
{
  g_CDmeBoneFlexDriverPullInModule = g_CDmeBoneFlexDriverLinkerHack;
  return g_CDmeBoneFlexDriverLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB6F0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneFlexDriverList *dynamic_initializer_for__g_CDmeBoneFlexDriverListPullInModule__()
{
  g_CDmeBoneFlexDriverListPullInModule = g_CDmeBoneFlexDriverListLinkerHack;
  return g_CDmeBoneFlexDriverListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB700
// Name: _dynamic_initializer_for__g_CDmeProceduralBonePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeProceduralBone *dynamic_initializer_for__g_CDmeProceduralBonePullInModule__()
{
  g_CDmeProceduralBonePullInModule = g_CDmeProceduralBoneLinkerHack;
  return g_CDmeProceduralBoneLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB710
// Name: _dynamic_initializer_for__g_CDmeJiggleBonePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJiggleBone *dynamic_initializer_for__g_CDmeJiggleBonePullInModule__()
{
  g_CDmeJiggleBonePullInModule = g_CDmeJiggleBoneLinkerHack;
  return g_CDmeJiggleBoneLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB720
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettingsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysPanelSettings *dynamic_initializer_for__g_CDmeMatSysPanelSettingsPullInModule__()
{
  g_CDmeMatSysPanelSettingsPullInModule = g_CDmeMatSysPanelSettingsLinkerHack;
  return g_CDmeMatSysPanelSettingsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB730
// Name: _dynamic_initializer_for__g_CDmeMatSysRootPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysRoot *dynamic_initializer_for__g_CDmeMatSysRootPullInModule__()
{
  g_CDmeMatSysRootPullInModule = g_CDmeMatSysRootLinkerHack;
  return g_CDmeMatSysRootLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB740
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysMDLDag *dynamic_initializer_for__g_CDmeMatSysMDLDagPullInModule__()
{
  g_CDmeMatSysMDLDagPullInModule = g_CDmeMatSysMDLDagLinkerHack;
  return g_CDmeMatSysMDLDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB750
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysDMXDag *dynamic_initializer_for__g_CDmeMatSysDMXDagPullInModule__()
{
  g_CDmeMatSysDMXDagPullInModule = g_CDmeMatSysDMXDagLinkerHack;
  return g_CDmeMatSysDMXDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB760
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysMPPDag *dynamic_initializer_for__g_CDmeMatSysMPPDagPullInModule__()
{
  g_CDmeMatSysMPPDagPullInModule = g_CDmeMatSysMPPDagLinkerHack;
  return g_CDmeMatSysMPPDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB770
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommandPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAssemblyCommand *dynamic_initializer_for__g_CDmeAssemblyCommandPullInModule__()
{
  g_CDmeAssemblyCommandPullInModule = g_CDmeAssemblyCommandLinkerHack;
  return g_CDmeAssemblyCommandLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB780
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommandPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationAssemblyCommand *dynamic_initializer_for__g_CDmeAnimationAssemblyCommandPullInModule__()
{
  g_CDmeAnimationAssemblyCommandPullInModule = g_CDmeAnimationAssemblyCommandLinkerHack;
  return g_CDmeAnimationAssemblyCommandLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB790
// Name: _dynamic_initializer_for__g_CDmeFixupLoopPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFixupLoop *dynamic_initializer_for__g_CDmeFixupLoopPullInModule__()
{
  g_CDmeFixupLoopPullInModule = g_CDmeFixupLoopLinkerHack;
  return g_CDmeFixupLoopLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB7A0
// Name: _dynamic_initializer_for__g_CDmeSubtractPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSubtract *dynamic_initializer_for__g_CDmeSubtractPullInModule__()
{
  g_CDmeSubtractPullInModule = g_CDmeSubtractLinkerHack;
  return g_CDmeSubtractLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB7B0
// Name: _dynamic_initializer_for__g_CDmePreSubtractPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePreSubtract *dynamic_initializer_for__g_CDmePreSubtractPullInModule__()
{
  g_CDmePreSubtractPullInModule = g_CDmePreSubtractLinkerHack;
  return g_CDmePreSubtractLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB7C0
// Name: _dynamic_initializer_for__g_CDmeRotateToPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRotateTo *dynamic_initializer_for__g_CDmeRotateToPullInModule__()
{
  g_CDmeRotateToPullInModule = g_CDmeRotateToLinkerHack;
  return g_CDmeRotateToLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB7D0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmdPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneMaskCmd *dynamic_initializer_for__g_CDmeBoneMaskCmdPullInModule__()
{
  g_CDmeBoneMaskCmdPullInModule = g_CDmeBoneMaskCmdLinkerHack;
  return g_CDmeBoneMaskCmdLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB7E0
// Name: _dynamic_initializer_for__g_CDmeEyelidPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEyelid *dynamic_initializer_for__g_CDmeEyelidPullInModule__()
{
  g_CDmeEyelidPullInModule = g_CDmeEyelidLinkerHack;
  return g_CDmeEyelidLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB7F0
// Name: _dynamic_initializer_for__g_CDmeMouthPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMouth *dynamic_initializer_for__g_CDmeMouthPullInModule__()
{
  g_CDmeMouthPullInModule = g_CDmeMouthLinkerHack;
  return g_CDmeMouthLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB800
// Name: _dynamic_initializer_for__g_CDmElementPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *dynamic_initializer_for__g_CDmElementPullInModule__()
{
  g_CDmElementPullInModule = g_CDmElementLinkerHack;
  return g_CDmElementLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB810
// Name: _dynamic_initializer_for__g_CDmeTransformPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransform *dynamic_initializer_for__g_CDmeTransformPullInModule__()
{
  g_CDmeTransformPullInModule = g_CDmeTransformLinkerHack;
  return g_CDmeTransformLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB820
// Name: _dynamic_initializer_for__g_CDmeTransformListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformList *dynamic_initializer_for__g_CDmeTransformListPullInModule__()
{
  g_CDmeTransformListPullInModule = g_CDmeTransformListLinkerHack;
  return g_CDmeTransformListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB830
// Name: _dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDataBase *dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__()
{
  g_CDmeVertexDataBasePullInModule = g_CDmeVertexDataBaseLinkerHack;
  return g_CDmeVertexDataBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB840
// Name: _dynamic_initializer_for__g_CDmeVertexDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexData *dynamic_initializer_for__g_CDmeVertexDataPullInModule__()
{
  g_CDmeVertexDataPullInModule = g_CDmeVertexDataLinkerHack;
  return g_CDmeVertexDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB850
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDeltaData *dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__()
{
  g_CDmeVertexDeltaDataPullInModule = g_CDmeVertexDeltaDataLinkerHack;
  return g_CDmeVertexDeltaDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB860
// Name: _dynamic_initializer_for__g_CDmeShapePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeShape *dynamic_initializer_for__g_CDmeShapePullInModule__()
{
  g_CDmeShapePullInModule = g_CDmeShapeLinkerHack;
  return g_CDmeShapeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB870
// Name: _dynamic_initializer_for__g_CDmeMeshPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *dynamic_initializer_for__g_CDmeMeshPullInModule__()
{
  g_CDmeMeshPullInModule = g_CDmeMeshLinkerHack;
  return g_CDmeMeshLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB880
// Name: _dynamic_initializer_for__g_CDmeDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *dynamic_initializer_for__g_CDmeDagPullInModule__()
{
  g_CDmeDagPullInModule = g_CDmeDagLinkerHack;
  return g_CDmeDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB890
// Name: _dynamic_initializer_for__g_CDmeFaceSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFaceSet *dynamic_initializer_for__g_CDmeFaceSetPullInModule__()
{
  g_CDmeFaceSetPullInModule = g_CDmeFaceSetLinkerHack;
  return g_CDmeFaceSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB8A0
// Name: _dynamic_initializer_for__g_CDmeModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeModel *dynamic_initializer_for__g_CDmeModelPullInModule__()
{
  g_CDmeModelPullInModule = g_CDmeModelLinkerHack;
  return g_CDmeModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB8B0
// Name: _dynamic_initializer_for__g_CDmeJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJoint *dynamic_initializer_for__g_CDmeJointPullInModule__()
{
  g_CDmeJointPullInModule = g_CDmeJointLinkerHack;
  return g_CDmeJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB8C0
// Name: _dynamic_initializer_for__g_CDmeAttachmentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAttachment *dynamic_initializer_for__g_CDmeAttachmentPullInModule__()
{
  g_CDmeAttachmentPullInModule = g_CDmeAttachmentLinkerHack;
  return g_CDmeAttachmentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB8D0
// Name: _dynamic_initializer_for__g_CDmeMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMakefile *dynamic_initializer_for__g_CDmeMakefilePullInModule__()
{
  g_CDmeMakefilePullInModule = g_CDmeMakefileLinkerHack;
  return g_CDmeMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB8E0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDLMakefile *dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__()
{
  g_CDmeMDLMakefilePullInModule = g_CDmeMDLMakefileLinkerHack;
  return g_CDmeMDLMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB8F0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDCCMakefile *dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__()
{
  g_CDmeDCCMakefilePullInModule = g_CDmeDCCMakefileLinkerHack;
  return g_CDmeDCCMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB900
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaAnimationMakefile *dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__()
{
  g_CDmeMayaAnimationMakefilePullInModule = g_CDmeMayaAnimationMakefileLinkerHack;
  return g_CDmeMayaAnimationMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB910
// Name: _dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaCombinationOperator *dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__()
{
  g_CDmeMayaCombinationOperatorPullInModule = g_CDmeMayaCombinationOperatorLinkerHack;
  return g_CDmeMayaCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB920
// Name: _dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaMakefile *dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__()
{
  g_CDmeMayaMakefilePullInModule = g_CDmeMayaMakefileLinkerHack;
  return g_CDmeMayaMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB930
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaModelMakefile *dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__()
{
  g_CDmeMayaModelMakefilePullInModule = g_CDmeMayaModelMakefileLinkerHack;
  return g_CDmeMayaModelMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB940
// Name: _dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeXSIMakefile *dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__()
{
  g_CDmeXSIMakefilePullInModule = g_CDmeXSIMakefileLinkerHack;
  return g_CDmeXSIMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB950
// Name: _dynamic_initializer_for__g_CDmeSourcePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSource *dynamic_initializer_for__g_CDmeSourcePullInModule__()
{
  g_CDmeSourcePullInModule = g_CDmeSourceLinkerHack;
  return g_CDmeSourceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB960
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceDCCFile *dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__()
{
  g_CDmeSourceDCCFilePullInModule = g_CDmeSourceDCCFileLinkerHack;
  return g_CDmeSourceDCCFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB970
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaFile *dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__()
{
  g_CDmeSourceMayaFilePullInModule = g_CDmeSourceMayaFileLinkerHack;
  return g_CDmeSourceMayaFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB980
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaModelFile *dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__()
{
  g_CDmeSourceMayaModelFilePullInModule = g_CDmeSourceMayaModelFileLinkerHack;
  return g_CDmeSourceMayaModelFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB990
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaAnimationFile *dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__()
{
  g_CDmeSourceMayaAnimationFilePullInModule = g_CDmeSourceMayaAnimationFileLinkerHack;
  return g_CDmeSourceMayaAnimationFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB9A0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceXSIFile *dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__()
{
  g_CDmeSourceXSIFilePullInModule = g_CDmeSourceXSIFileLinkerHack;
  return g_CDmeSourceXSIFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB9B0
// Name: _dynamic_initializer_for__g_CDmeAnimationListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationList *dynamic_initializer_for__g_CDmeAnimationListPullInModule__()
{
  g_CDmeAnimationListPullInModule = g_CDmeAnimationListLinkerHack;
  return g_CDmeAnimationListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB9C0
// Name: _dynamic_initializer_for__g_CDmeClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *dynamic_initializer_for__g_CDmeClipPullInModule__()
{
  g_CDmeClipPullInModule = g_CDmeClipLinkerHack;
  return g_CDmeClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB9D0
// Name: _dynamic_initializer_for__g_CDmeChannelsClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *dynamic_initializer_for__g_CDmeChannelsClipPullInModule__()
{
  g_CDmeChannelsClipPullInModule = g_CDmeChannelsClipLinkerHack;
  return g_CDmeChannelsClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB9E0
// Name: _dynamic_initializer_for__g_CDmeChannelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannel *dynamic_initializer_for__g_CDmeChannelPullInModule__()
{
  g_CDmeChannelPullInModule = g_CDmeChannelLinkerHack;
  return g_CDmeChannelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EB9F0
// Name: _dynamic_initializer_for__g_CDmeTimeFramePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeFrame *dynamic_initializer_for__g_CDmeTimeFramePullInModule__()
{
  g_CDmeTimeFramePullInModule = g_CDmeTimeFrameLinkerHack;
  return g_CDmeTimeFrameLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA00
// Name: _dynamic_initializer_for__g_CDmeTrackGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrackGroup *dynamic_initializer_for__g_CDmeTrackGroupPullInModule__()
{
  g_CDmeTrackGroupPullInModule = g_CDmeTrackGroupLinkerHack;
  return g_CDmeTrackGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA10
// Name: _dynamic_initializer_for__g_CDmeTrackPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrack *dynamic_initializer_for__g_CDmeTrackPullInModule__()
{
  g_CDmeTrackPullInModule = g_CDmeTrackLinkerHack;
  return g_CDmeTrackLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA20
// Name: _dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationDominationRule *dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__()
{
  g_CDmeCombinationDominationRulePullInModule = g_CDmeCombinationDominationRuleLinkerHack;
  return g_CDmeCombinationDominationRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA30
// Name: _dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationInputControl *dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__()
{
  g_CDmeCombinationInputControlPullInModule = g_CDmeCombinationInputControlLinkerHack;
  return g_CDmeCombinationInputControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA40
// Name: _dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__()
{
  g_CDmeCombinationOperatorPullInModule = g_CDmeCombinationOperatorLinkerHack;
  return g_CDmeCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA50
// Name: _dynamic_initializer_for__g_CDmeIntLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<int> *dynamic_initializer_for__g_CDmeIntLogPullInModule__()
{
  g_CDmeIntLogPullInModule = g_CDmeIntLogLinkerHack;
  return g_CDmeIntLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA60
// Name: _dynamic_initializer_for__g_CDmeFloatLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<float> *dynamic_initializer_for__g_CDmeFloatLogPullInModule__()
{
  g_CDmeFloatLogPullInModule = g_CDmeFloatLogLinkerHack;
  return g_CDmeFloatLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA70
// Name: _dynamic_initializer_for__g_CDmeBoolLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<bool> *dynamic_initializer_for__g_CDmeBoolLogPullInModule__()
{
  g_CDmeBoolLogPullInModule = g_CDmeBoolLogLinkerHack;
  return g_CDmeBoolLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA80
// Name: _dynamic_initializer_for__g_CDmeColorLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Color> *dynamic_initializer_for__g_CDmeColorLogPullInModule__()
{
  g_CDmeColorLogPullInModule = g_CDmeColorLogLinkerHack;
  return g_CDmeColorLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBA90
// Name: _dynamic_initializer_for__g_CDmeVector2LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogPullInModule__()
{
  g_CDmeVector2LogPullInModule = g_CDmeVector2LogLinkerHack;
  return g_CDmeVector2LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBAA0
// Name: _dynamic_initializer_for__g_CDmeVector3LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector> *dynamic_initializer_for__g_CDmeVector3LogPullInModule__()
{
  g_CDmeVector3LogPullInModule = g_CDmeVector3LogLinkerHack;
  return g_CDmeVector3LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBAB0
// Name: _dynamic_initializer_for__g_CDmeVector4LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogPullInModule__()
{
  g_CDmeVector4LogPullInModule = g_CDmeVector4LogLinkerHack;
  return g_CDmeVector4LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBAC0
// Name: _dynamic_initializer_for__g_CDmeQAngleLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogPullInModule__()
{
  g_CDmeQAngleLogPullInModule = g_CDmeQAngleLogLinkerHack;
  return g_CDmeQAngleLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBAD0
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__()
{
  g_CDmeQuaternionLogPullInModule = g_CDmeQuaternionLogLinkerHack;
  return g_CDmeQuaternionLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBAE0
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__()
{
  g_CDmeVMatrixLogPullInModule = g_CDmeVMatrixLogLinkerHack;
  return g_CDmeVMatrixLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBAF0
// Name: _dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<int> *dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__()
{
  g_CDmeIntLogLayerPullInModule = g_CDmeIntLogLayerLinkerHack;
  return g_CDmeIntLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB00
// Name: _dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<float> *dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__()
{
  g_CDmeFloatLogLayerPullInModule = g_CDmeFloatLogLayerLinkerHack;
  return g_CDmeFloatLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB10
// Name: _dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<bool> *dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__()
{
  g_CDmeBoolLogLayerPullInModule = g_CDmeBoolLogLayerLinkerHack;
  return g_CDmeBoolLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB20
// Name: _dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Color> *dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__()
{
  g_CDmeColorLogLayerPullInModule = g_CDmeColorLogLayerLinkerHack;
  return g_CDmeColorLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB30
// Name: _dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__()
{
  g_CDmeVector2LogLayerPullInModule = g_CDmeVector2LogLayerLinkerHack;
  return g_CDmeVector2LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB40
// Name: _dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector> *dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__()
{
  g_CDmeVector3LogLayerPullInModule = g_CDmeVector3LogLayerLinkerHack;
  return g_CDmeVector3LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB50
// Name: _dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__()
{
  g_CDmeVector4LogLayerPullInModule = g_CDmeVector4LogLayerLinkerHack;
  return g_CDmeVector4LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB60
// Name: _dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__()
{
  g_CDmeQAngleLogLayerPullInModule = g_CDmeQAngleLogLayerLinkerHack;
  return g_CDmeQAngleLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB70
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__()
{
  g_CDmeQuaternionLogLayerPullInModule = g_CDmeQuaternionLogLayerLinkerHack;
  return g_CDmeQuaternionLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB80
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__()
{
  g_CDmeVMatrixLogLayerPullInModule = g_CDmeVMatrixLogLayerLinkerHack;
  return g_CDmeVMatrixLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBB90
// Name: _dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<int> *dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__()
{
  g_CDmeIntCurveInfoPullInModule = g_CDmeIntCurveInfoLinkerHack;
  return g_CDmeIntCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBBA0
// Name: _dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<float> *dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__()
{
  g_CDmeFloatCurveInfoPullInModule = g_CDmeFloatCurveInfoLinkerHack;
  return g_CDmeFloatCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBBB0
// Name: _dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<bool> *dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__()
{
  g_CDmeBoolCurveInfoPullInModule = g_CDmeBoolCurveInfoLinkerHack;
  return g_CDmeBoolCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBBC0
// Name: _dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Color> *dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__()
{
  g_CDmeColorCurveInfoPullInModule = g_CDmeColorCurveInfoLinkerHack;
  return g_CDmeColorCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBBD0
// Name: _dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector2D> *dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__()
{
  g_CDmeVector2CurveInfoPullInModule = g_CDmeVector2CurveInfoLinkerHack;
  return g_CDmeVector2CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBBE0
// Name: _dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector> *dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__()
{
  g_CDmeVector3CurveInfoPullInModule = g_CDmeVector3CurveInfoLinkerHack;
  return g_CDmeVector3CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBBF0
// Name: _dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector4D> *dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__()
{
  g_CDmeVector4CurveInfoPullInModule = g_CDmeVector4CurveInfoLinkerHack;
  return g_CDmeVector4CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBC00
// Name: _dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<QAngle> *dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__()
{
  g_CDmeQAngleCurveInfoPullInModule = g_CDmeQAngleCurveInfoLinkerHack;
  return g_CDmeQAngleCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBC10
// Name: _dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__()
{
  g_CDmeQuaternionCurveInfoPullInModule = g_CDmeQuaternionCurveInfoLinkerHack;
  return g_CDmeQuaternionCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBC20
// Name: _dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__()
{
  g_CDmeVMatrixCurveInfoPullInModule = g_CDmeVMatrixCurveInfoLinkerHack;
  return g_CDmeVMatrixCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBC30
// Name: _dynamic_initializer_for__g_CDmeComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeComponent *dynamic_initializer_for__g_CDmeComponentPullInModule__()
{
  g_CDmeComponentPullInModule = g_CDmeComponentLinkerHack;
  return g_CDmeComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBC40
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSingleIndexedComponent *dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__()
{
  g_CDmeSingleIndexedComponentPullInModule = g_CDmeSingleIndexedComponentLinkerHack;
  return g_CDmeSingleIndexedComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBC50
// Name: _dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDrawSettings *dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__()
{
  g_CDmeDrawSettingsPullInModule = g_CDmeDrawSettingsLinkerHack;
  return g_CDmeDrawSettingsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005EBC60
// Name: _dynamic_initializer_for__g_MtlLib__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MtlLib__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MtlLib__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC70
// Name: _dynamic_initializer_for__UNSPECIFIED_LOGGING_COLOR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__UNSPECIFIED_LOGGING_COLOR__()
{
  UNSPECIFIED_LOGGING_COLOR_15._color[0] = 0;
  UNSPECIFIED_LOGGING_COLOR_15._color[1] = 0;
  UNSPECIFIED_LOGGING_COLOR_15._color[2] = 0;
  UNSPECIFIED_LOGGING_COLOR_15._color[3] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005EBCA0
// Name: _dynamic_initializer_for__vec2_origin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__vec2_origin__()
{
  vec2_origin_14.x = 0.0;
  vec2_origin_14.y = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x005EBCD0
// Name: _dynamic_initializer_for__vec2_invalid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__vec2_invalid__()
{
  vec2_invalid_180.x = 3.4028235e38;
  vec2_invalid_180.y = 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x005EBD00
// Name: _dynamic_initializer_for__vec4_origin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__vec4_origin__()
{
  vec4_origin_8.x = 0.0;
  vec4_origin_8.y = 0.0;
  vec4_origin_8.z = 0.0;
  vec4_origin_8.w = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x005EBD50
// Name: _dynamic_initializer_for__vec4_invalid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__vec4_invalid__()
{
  vec4_invalid_145.x = 3.4028235e38;
  vec4_invalid_145.y = 3.4028235e38;
  vec4_invalid_145.z = 3.4028235e38;
  vec4_invalid_145.w = 3.4028235e38;
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00566B80
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_5BDC08[(unsigned __int8)((int)va + dword_5BDC08[(unsigned __int8)(int)fxa])];
  v26 = dword_5BDC08[(unsigned __int8)((int)va + dword_5BDC08[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_5BDC08[(unsigned __int8)((int)va + dword_5BDC08[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_5BDC08[(unsigned __int8)((int)va + dword_5BDC08[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_5BDC08[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_5BDC08[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_5BDC08[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_5BDC08[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_5BDC08[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_5BDC08[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_5BDC08[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_5BDC08[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_5BDC08[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_5BDC08[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_5BDC08[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_5BDC08[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_5BDC08[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_5BDC08[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_5BDC08[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_5BDC08[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_5BDC08[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_5BDC08[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_5BDC08[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_5BDC08[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_5BDC08[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_5BDC08[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_5BDC08[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_5BDC08[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_5BDC08[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_5BDC08[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_5BDC08[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_5BDC08[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_5BDC08[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_5BDC08[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_5BDC08[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_5BDC08[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00577400
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_5CA5C0[(unsigned __int8)((int)va + dword_5CA5C0[(unsigned __int8)(int)fxa])];
  v26 = dword_5CA5C0[(unsigned __int8)((int)va + dword_5CA5C0[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_5CA5C0[(unsigned __int8)((int)va + dword_5CA5C0[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_5CA5C0[(unsigned __int8)((int)va + dword_5CA5C0[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_5CA5C0[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_5CA5C0[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_5CA5C0[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_5CA5C0[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_5CA5C0[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_5CA5C0[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_5CA5C0[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_5CA5C0[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_5CA5C0[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_5CA5C0[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_5CA5C0[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_5CA5C0[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_5CA5C0[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_5CA5C0[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_5CA5C0[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_5CA5C0[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_5CA5C0[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_5CA5C0[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_5CA5C0[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_5CA5C0[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_5CA5C0[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_5CA5C0[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_5CA5C0[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_5CA5C0[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_5CA5C0[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_5CA5C0[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_5CA5C0[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_5CA5C0[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_5CA5C0[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_5CA5C0[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_5CA5C0[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_5CA5C0[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006A6FE0
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_79F190[(unsigned __int8)((int)va + dword_79F190[(unsigned __int8)(int)fxa])];
  v26 = dword_79F190[(unsigned __int8)((int)va + dword_79F190[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_79F190[(unsigned __int8)((int)va + dword_79F190[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_79F190[(unsigned __int8)((int)va + dword_79F190[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_79F190[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_79F190[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_79F190[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_79F190[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_79F190[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_79F190[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_79F190[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_79F190[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_79F190[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_79F190[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_79F190[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_79F190[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_79F190[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_79F190[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_79F190[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_79F190[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_79F190[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_79F190[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_79F190[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_79F190[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_79F190[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_79F190[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_79F190[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_79F190[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_79F190[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_79F190[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_79F190[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_79F190[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_79F190[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_79F190[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_79F190[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_79F190[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005793F0
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_5CC6B0[(unsigned __int8)((int)va + dword_5CC6B0[(unsigned __int8)(int)fxa])];
  v26 = dword_5CC6B0[(unsigned __int8)((int)va + dword_5CC6B0[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_5CC6B0[(unsigned __int8)((int)va + dword_5CC6B0[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_5CC6B0[(unsigned __int8)((int)va + dword_5CC6B0[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_5CC6B0[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_5CC6B0[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_5CC6B0[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_5CC6B0[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_5CC6B0[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_5CC6B0[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_5CC6B0[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_5CC6B0[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_5CC6B0[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_5CC6B0[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_5CC6B0[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_5CC6B0[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_5CC6B0[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_5CC6B0[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_5CC6B0[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_5CC6B0[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_5CC6B0[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_5CC6B0[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_5CC6B0[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_5CC6B0[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_5CC6B0[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_5CC6B0[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_5CC6B0[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_5CC6B0[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_5CC6B0[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_5CC6B0[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_5CC6B0[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_5CC6B0[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_5CC6B0[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_5CC6B0[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_5CC6B0[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_5CC6B0[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005E3460
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_651780[(unsigned __int8)((int)va + dword_651780[(unsigned __int8)(int)fxa])];
  v26 = dword_651780[(unsigned __int8)((int)va + dword_651780[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_651780[(unsigned __int8)((int)va + dword_651780[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_651780[(unsigned __int8)((int)va + dword_651780[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_651780[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_651780[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_651780[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_651780[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_651780[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_651780[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_651780[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_651780[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_651780[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_651780[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_651780[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_651780[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_651780[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_651780[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_651780[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_651780[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_651780[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_651780[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_651780[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_651780[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_651780[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_651780[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_651780[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_651780[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_651780[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_651780[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_651780[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_651780[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_651780[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_651780[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_651780[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_651780[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

//------------------------------------------------------------------------------
// Address: 0x005E3A06
// Name: __getextendedkeycode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const NormKeyVals *__cdecl _getextendedkeycode(_KEY_EVENT_RECORD *pKE)
{
  unsigned int dwControlKeyState; // ebx
  const NormKeyVals *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // ecx
  int wVirtualScanCode; // eax

  dwControlKeyState = pKE->dwControlKeyState;
  if ( (dwControlKeyState & 0x100) != 0 )
  {
    result = nullptr;
    v3 = 0;
    v4 = 0;
    while ( EnhancedKeys[v4].ScanCode != pKE->wVirtualScanCode )
    {
      ++v4;
      ++v3;
      if ( v4 >= 12 )
        return result;
    }
    v5 = v3;
    if ( (dwControlKeyState & 3) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].AltChars;
    if ( (dwControlKeyState & 0xC) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].CtrlChars;
    if ( (dwControlKeyState & 0x10) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].ShiftChars;
    return (const NormKeyVals *)&EnhancedKeys[v5].RegChars;
  }
  else
  {
    wVirtualScanCode = pKE->wVirtualScanCode;
    if ( (dwControlKeyState & 3) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].AltChars;
    }
    else if ( (dwControlKeyState & 0xC) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].CtrlChars;
    }
    else if ( (dwControlKeyState & 0x10) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].ShiftChars;
    }
    else
    {
      result = &NormalKeys[wVirtualScanCode];
    }
    if ( result->RegChars.LeadChar != 0 && result->RegChars.LeadChar != 0xE0 || result->RegChars.SecondChar == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E3AB9
// Name: __getch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getch_nolock()
{
  int result; // eax
  int AsciiChar; // edi
  const NormKeyVals *v2; // eax
  unsigned int oldstate; // [esp+4h] [ebp-20h] BYREF
  unsigned int NumRead; // [esp+8h] [ebp-1Ch] BYREF
  _INPUT_RECORD ConInpRec; // [esp+Ch] [ebp-18h] BYREF

  if ( chbuf == -1 )
  {
    if ( _coninpfh == (HANDLE)-2 )
      __initconin();
    if ( _coninpfh == (HANDLE)-1 )
    {
      return -1;
    }
    else
    {
      GetConsoleMode(hConsoleHandle: _coninpfh, lpMode: &oldstate);
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: 0);
      while ( 1 )
      {
        if ( !ReadConsoleInputA(
                hConsoleInput: _coninpfh,
                lpBuffer: &ConInpRec,
                nLength: 1u,
                lpNumberOfEventsRead: &NumRead)
          || NumRead == 0 )
        {
          AsciiChar = -1;
          goto LABEL_15;
        }
        if ( ConInpRec.EventType == 1 && ConInpRec.Event.KeyEvent.bKeyDown != 0 )
        {
          AsciiChar = (unsigned __int8)ConInpRec.Event.KeyEvent.uChar.AsciiChar;
          if ( ConInpRec.Event.KeyEvent.uChar.AsciiChar != 0 )
            goto LABEL_15;
          v2 = _getextendedkeycode(pKE: &ConInpRec.Event.KeyEvent);
          if ( v2 != nullptr )
            break;
        }
      }
      AsciiChar = v2->RegChars.LeadChar;
      chbuf = v2->RegChars.SecondChar;
LABEL_15:
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: oldstate);
      return AsciiChar;
    }
  }
  else
  {
    result = (unsigned __int8)chbuf;
    chbuf = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E3B92
// Name: _getch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl getch()
{
  int v1; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  v1 = _getch_nolock();
  _unlock(locknum: 3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3BD0
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005E3D4E
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E3D82
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E3DE0
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x005E3E20
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd(v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One_0;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E3EFD
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONIN$",
             dwDesiredAccess: 0xC0000000,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _coninpfh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E3F1C
// Name: ___termconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconin()
{
  HANDLE result; // eax

  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E3F33
// Name: __ceil_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _ceil_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp();
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xCu, x, savedcw: v1);
    }
    return _except1(a1: (int)&savedregs, flags: 8, opcode: 12, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return v4;
    }
    else
    {
      return _except1(a1: (int)&savedregs, flags: 16, opcode: 12, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E4060
// Name: _dynamic_initializer_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupFunctions__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupFunctions__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4070
// Name: _dynamic_initializer_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExitStopper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ExitStopper__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4080
// Name: _dynamic_initializer_for__g_JointedModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_JointedModel__()
{
  CJointedModel::CJointedModel(this: &g_JointedModel);
  return atexit(func: dynamic_atexit_destructor_for__g_JointedModel__);
}

//------------------------------------------------------------------------------
// Address: 0x005E40A0
// Name: _dynamic_initializer_for__s_Balance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_Balance__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_Balance__);
}

//------------------------------------------------------------------------------
// Address: 0x005E40B0
// Name: _dynamic_initializer_for__s_Speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_Speed__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_Speed__);
}

//------------------------------------------------------------------------------
// Address: 0x005E40C0
// Name: _dynamic_initializer_for__s_UniqueVertices__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_UniqueVertices__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_UniqueVertices__);
}

//------------------------------------------------------------------------------
// Address: 0x005E40D0
// Name: _dynamic_initializer_for__s_UniqueVerticesMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_UniqueVerticesMap__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_UniqueVerticesMap__);
}

//------------------------------------------------------------------------------
// Address: 0x005E40E0
// Name: _dynamic_initializer_for__s_DeltaStates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DeltaStates__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DeltaStates__);
}

//------------------------------------------------------------------------------
// Address: 0x005E40F0
// Name: _dynamic_initializer_for__g_CDmeMdlListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMdlList *dynamic_initializer_for__g_CDmeMdlListPullInModule__()
{
  g_CDmeMdlListPullInModule = g_CDmeMdlListLinkerHack;
  return g_CDmeMdlListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4100
// Name: _dynamic_initializer_for__g_CDmeBBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBBox *dynamic_initializer_for__g_CDmeBBoxPullInModule__()
{
  g_CDmeBBoxPullInModule = g_CDmeBBoxLinkerHack;
  return g_CDmeBBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4110
// Name: _dynamic_initializer_for__g_CDmeHitboxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeHitbox *dynamic_initializer_for__g_CDmeHitboxPullInModule__()
{
  g_CDmeHitboxPullInModule = g_CDmeHitboxLinkerHack;
  return g_CDmeHitboxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4120
// Name: _dynamic_initializer_for__g_CDmeHitboxSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeHitboxSet *dynamic_initializer_for__g_CDmeHitboxSetPullInModule__()
{
  g_CDmeHitboxSetPullInModule = g_CDmeHitboxSetLinkerHack;
  return g_CDmeHitboxSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4130
// Name: _dynamic_initializer_for__g_CDmeHitboxSetListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeHitboxSetList *dynamic_initializer_for__g_CDmeHitboxSetListPullInModule__()
{
  g_CDmeHitboxSetListPullInModule = g_CDmeHitboxSetListLinkerHack;
  return g_CDmeHitboxSetListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4140
// Name: _dynamic_initializer_for__g_CDmeBodyPartPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBodyPart *dynamic_initializer_for__g_CDmeBodyPartPullInModule__()
{
  g_CDmeBodyPartPullInModule = g_CDmeBodyPartLinkerHack;
  return g_CDmeBodyPartLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4150
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPartPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBlankBodyPart *dynamic_initializer_for__g_CDmeBlankBodyPartPullInModule__()
{
  g_CDmeBlankBodyPartPullInModule = g_CDmeBlankBodyPartLinkerHack;
  return g_CDmeBlankBodyPartLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4160
// Name: _dynamic_initializer_for__g_CDmeLODPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeLOD *dynamic_initializer_for__g_CDmeLODPullInModule__()
{
  g_CDmeLODPullInModule = g_CDmeLODLinkerHack;
  return g_CDmeLODLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4170
// Name: _dynamic_initializer_for__g_CDmeLODListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeLODList *dynamic_initializer_for__g_CDmeLODListPullInModule__()
{
  g_CDmeLODListPullInModule = g_CDmeLODListLinkerHack;
  return g_CDmeLODListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4180
// Name: _dynamic_initializer_for__g_CDmeCollisionModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCollisionModel *dynamic_initializer_for__g_CDmeCollisionModelPullInModule__()
{
  g_CDmeCollisionModelPullInModule = g_CDmeCollisionModelLinkerHack;
  return g_CDmeCollisionModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4190
// Name: _dynamic_initializer_for__g_CDmeJointConstrainPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJointConstrain *dynamic_initializer_for__g_CDmeJointConstrainPullInModule__()
{
  g_CDmeJointConstrainPullInModule = g_CDmeJointConstrainLinkerHack;
  return g_CDmeJointConstrainLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E41A0
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFrictionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJointAnimatedFriction *dynamic_initializer_for__g_CDmeJointAnimatedFrictionPullInModule__()
{
  g_CDmeJointAnimatedFrictionPullInModule = g_CDmeJointAnimatedFrictionLinkerHack;
  return g_CDmeJointAnimatedFrictionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E41B0
// Name: _dynamic_initializer_for__g_CDmeCollisionJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCollisionJoint *dynamic_initializer_for__g_CDmeCollisionJointPullInModule__()
{
  g_CDmeCollisionJointPullInModule = g_CDmeCollisionJointLinkerHack;
  return g_CDmeCollisionJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E41C0
// Name: _dynamic_initializer_for__g_CDmeCollisionJointsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCollisionJoints *dynamic_initializer_for__g_CDmeCollisionJointsPullInModule__()
{
  g_CDmeCollisionJointsPullInModule = g_CDmeCollisionJointsLinkerHack;
  return g_CDmeCollisionJointsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E41D0
// Name: _dynamic_initializer_for__g_CDmeBodyGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBodyGroup *dynamic_initializer_for__g_CDmeBodyGroupPullInModule__()
{
  g_CDmeBodyGroupPullInModule = g_CDmeBodyGroupLinkerHack;
  return g_CDmeBodyGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E41E0
// Name: _dynamic_initializer_for__g_CDmeBodyGroupListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBodyGroupList *dynamic_initializer_for__g_CDmeBodyGroupListPullInModule__()
{
  g_CDmeBodyGroupListPullInModule = g_CDmeBodyGroupListLinkerHack;
  return g_CDmeBodyGroupListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E41F0
// Name: _dynamic_initializer_for__g_CDmeBoneWeightPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneWeight *dynamic_initializer_for__g_CDmeBoneWeightPullInModule__()
{
  g_CDmeBoneWeightPullInModule = g_CDmeBoneWeightLinkerHack;
  return g_CDmeBoneWeightLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4200
// Name: _dynamic_initializer_for__g_CDmeBoneMaskPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneMask *dynamic_initializer_for__g_CDmeBoneMaskPullInModule__()
{
  g_CDmeBoneMaskPullInModule = g_CDmeBoneMaskLinkerHack;
  return g_CDmeBoneMaskLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4210
// Name: _dynamic_initializer_for__g_CDmeBoneMaskListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneMaskList *dynamic_initializer_for__g_CDmeBoneMaskListPullInModule__()
{
  g_CDmeBoneMaskListPullInModule = g_CDmeBoneMaskListLinkerHack;
  return g_CDmeBoneMaskListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4220
// Name: _dynamic_initializer_for__g_CDmeMotionControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMotionControl *dynamic_initializer_for__g_CDmeMotionControlPullInModule__()
{
  g_CDmeMotionControlPullInModule = g_CDmeMotionControlLinkerHack;
  return g_CDmeMotionControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4230
// Name: _dynamic_initializer_for__g_CDmeIkChainPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkChain *dynamic_initializer_for__g_CDmeIkChainPullInModule__()
{
  g_CDmeIkChainPullInModule = g_CDmeIkChainLinkerHack;
  return g_CDmeIkChainLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4240
// Name: _dynamic_initializer_for__g_CDmeIkRangePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkRange *dynamic_initializer_for__g_CDmeIkRangePullInModule__()
{
  g_CDmeIkRangePullInModule = g_CDmeIkRangeLinkerHack;
  return g_CDmeIkRangeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4250
// Name: _dynamic_initializer_for__g_CDmeIkLockPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkLock *dynamic_initializer_for__g_CDmeIkLockPullInModule__()
{
  g_CDmeIkLockPullInModule = g_CDmeIkLockLinkerHack;
  return g_CDmeIkLockLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4260
// Name: _dynamic_initializer_for__g_CDmeIkRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkRule *dynamic_initializer_for__g_CDmeIkRulePullInModule__()
{
  g_CDmeIkRulePullInModule = g_CDmeIkRuleLinkerHack;
  return g_CDmeIkRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4270
// Name: _dynamic_initializer_for__g_CDmeIkTouchRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkTouchRule *dynamic_initializer_for__g_CDmeIkTouchRulePullInModule__()
{
  g_CDmeIkTouchRulePullInModule = g_CDmeIkTouchRuleLinkerHack;
  return g_CDmeIkTouchRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4280
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkFootstepRule *dynamic_initializer_for__g_CDmeIkFootstepRulePullInModule__()
{
  g_CDmeIkFootstepRulePullInModule = g_CDmeIkFootstepRuleLinkerHack;
  return g_CDmeIkFootstepRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4290
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkReleaseRule *dynamic_initializer_for__g_CDmeIkReleaseRulePullInModule__()
{
  g_CDmeIkReleaseRulePullInModule = g_CDmeIkReleaseRuleLinkerHack;
  return g_CDmeIkReleaseRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E42A0
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIkAttachmentRule *dynamic_initializer_for__g_CDmeIkAttachmentRulePullInModule__()
{
  g_CDmeIkAttachmentRulePullInModule = g_CDmeIkAttachmentRuleLinkerHack;
  return g_CDmeIkAttachmentRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E42B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmd *dynamic_initializer_for__g_CDmeAnimCmdPullInModule__()
{
  g_CDmeAnimCmdPullInModule = g_CDmeAnimCmdLinkerHack;
  return g_CDmeAnimCmdLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E42C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoopPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdFixupLoop *dynamic_initializer_for__g_CDmeAnimCmdFixupLoopPullInModule__()
{
  g_CDmeAnimCmdFixupLoopPullInModule = g_CDmeAnimCmdFixupLoopLinkerHack;
  return g_CDmeAnimCmdFixupLoopLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E42D0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdWeightList *dynamic_initializer_for__g_CDmeAnimCmdWeightListPullInModule__()
{
  g_CDmeAnimCmdWeightListPullInModule = g_CDmeAnimCmdWeightListLinkerHack;
  return g_CDmeAnimCmdWeightListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E42E0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtractPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdSubtract *dynamic_initializer_for__g_CDmeAnimCmdSubtractPullInModule__()
{
  g_CDmeAnimCmdSubtractPullInModule = g_CDmeAnimCmdSubtractLinkerHack;
  return g_CDmeAnimCmdSubtractLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E42F0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlignPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdAlign *dynamic_initializer_for__g_CDmeAnimCmdAlignPullInModule__()
{
  g_CDmeAnimCmdAlignPullInModule = g_CDmeAnimCmdAlignLinkerHack;
  return g_CDmeAnimCmdAlignLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4300
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateToPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdRotateTo *dynamic_initializer_for__g_CDmeAnimCmdRotateToPullInModule__()
{
  g_CDmeAnimCmdRotateToPullInModule = g_CDmeAnimCmdRotateToLinkerHack;
  return g_CDmeAnimCmdRotateToLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4310
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFramePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdWalkFrame *dynamic_initializer_for__g_CDmeAnimCmdWalkFramePullInModule__()
{
  g_CDmeAnimCmdWalkFramePullInModule = g_CDmeAnimCmdWalkFrameLinkerHack;
  return g_CDmeAnimCmdWalkFrameLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4320
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompressPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdCompress *dynamic_initializer_for__g_CDmeAnimCmdCompressPullInModule__()
{
  g_CDmeAnimCmdCompressPullInModule = g_CDmeAnimCmdCompressLinkerHack;
  return g_CDmeAnimCmdCompressLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4330
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivativePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdDerivative *dynamic_initializer_for__g_CDmeAnimCmdDerivativePullInModule__()
{
  g_CDmeAnimCmdDerivativePullInModule = g_CDmeAnimCmdDerivativeLinkerHack;
  return g_CDmeAnimCmdDerivativeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4340
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDeltaPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdLinearDelta *dynamic_initializer_for__g_CDmeAnimCmdLinearDeltaPullInModule__()
{
  g_CDmeAnimCmdLinearDeltaPullInModule = g_CDmeAnimCmdLinearDeltaLinkerHack;
  return g_CDmeAnimCmdLinearDeltaLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4350
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDeltaPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdSplineDelta *dynamic_initializer_for__g_CDmeAnimCmdSplineDeltaPullInModule__()
{
  g_CDmeAnimCmdSplineDeltaPullInModule = g_CDmeAnimCmdSplineDeltaLinkerHack;
  return g_CDmeAnimCmdSplineDeltaLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4360
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFramesPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdNumFrames *dynamic_initializer_for__g_CDmeAnimCmdNumFramesPullInModule__()
{
  g_CDmeAnimCmdNumFramesPullInModule = g_CDmeAnimCmdNumFramesLinkerHack;
  return g_CDmeAnimCmdNumFramesLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4370
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtractPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdPreSubtract *dynamic_initializer_for__g_CDmeAnimCmdPreSubtractPullInModule__()
{
  g_CDmeAnimCmdPreSubtractPullInModule = g_CDmeAnimCmdPreSubtractLinkerHack;
  return g_CDmeAnimCmdPreSubtractLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4380
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchyPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdLocalHierarchy *dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchyPullInModule__()
{
  g_CDmeAnimCmdLocalHierarchyPullInModule = g_CDmeAnimCmdLocalHierarchyLinkerHack;
  return g_CDmeAnimCmdLocalHierarchyLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4390
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimationPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimCmdNoAnimation *dynamic_initializer_for__g_CDmeAnimCmdNoAnimationPullInModule__()
{
  g_CDmeAnimCmdNoAnimationPullInModule = g_CDmeAnimCmdNoAnimationLinkerHack;
  return g_CDmeAnimCmdNoAnimationLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E43A0
// Name: _dynamic_initializer_for__g_CDmeAnimationEventPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationEvent *dynamic_initializer_for__g_CDmeAnimationEventPullInModule__()
{
  g_CDmeAnimationEventPullInModule = g_CDmeAnimationEventLinkerHack;
  return g_CDmeAnimationEventLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E43B0
// Name: _dynamic_initializer_for__g_CDmeSequenceActivityPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceActivity *dynamic_initializer_for__g_CDmeSequenceActivityPullInModule__()
{
  g_CDmeSequenceActivityPullInModule = g_CDmeSequenceActivityLinkerHack;
  return g_CDmeSequenceActivityLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E43C0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceBlendBase *dynamic_initializer_for__g_CDmeSequenceBlendBasePullInModule__()
{
  g_CDmeSequenceBlendBasePullInModule = g_CDmeSequenceBlendBaseLinkerHack;
  return g_CDmeSequenceBlendBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E43D0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceBlend *dynamic_initializer_for__g_CDmeSequenceBlendPullInModule__()
{
  g_CDmeSequenceBlendPullInModule = g_CDmeSequenceBlendLinkerHack;
  return g_CDmeSequenceBlendLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E43E0
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlendPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceCalcBlend *dynamic_initializer_for__g_CDmeSequenceCalcBlendPullInModule__()
{
  g_CDmeSequenceCalcBlendPullInModule = g_CDmeSequenceCalcBlendLinkerHack;
  return g_CDmeSequenceCalcBlendLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E43F0
// Name: _dynamic_initializer_for__g_CDmeSequenceBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceBase *dynamic_initializer_for__g_CDmeSequenceBasePullInModule__()
{
  g_CDmeSequenceBasePullInModule = g_CDmeSequenceBaseLinkerHack;
  return g_CDmeSequenceBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4400
// Name: _dynamic_initializer_for__g_CDmeSequencePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequence *dynamic_initializer_for__g_CDmeSequencePullInModule__()
{
  g_CDmeSequencePullInModule = g_CDmeSequenceLinkerHack;
  return g_CDmeSequenceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4410
// Name: _dynamic_initializer_for__g_CDmeMultiSequencePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMultiSequence *dynamic_initializer_for__g_CDmeMultiSequencePullInModule__()
{
  g_CDmeMultiSequencePullInModule = g_CDmeMultiSequenceLinkerHack;
  return g_CDmeMultiSequenceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4420
// Name: _dynamic_initializer_for__g_CDmeSequenceListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceList *dynamic_initializer_for__g_CDmeSequenceListPullInModule__()
{
  g_CDmeSequenceListPullInModule = g_CDmeSequenceListLinkerHack;
  return g_CDmeSequenceListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4430
// Name: _dynamic_initializer_for__g_CDmeIncludeModelListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeIncludeModelList *dynamic_initializer_for__g_CDmeIncludeModelListPullInModule__()
{
  g_CDmeIncludeModelListPullInModule = g_CDmeIncludeModelListLinkerHack;
  return g_CDmeIncludeModelListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4440
// Name: _dynamic_initializer_for__g_CDmeDefineBonePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDefineBone *dynamic_initializer_for__g_CDmeDefineBonePullInModule__()
{
  g_CDmeDefineBonePullInModule = g_CDmeDefineBoneLinkerHack;
  return g_CDmeDefineBoneLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4450
// Name: _dynamic_initializer_for__g_CDmeDefineBoneListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDefineBoneList *dynamic_initializer_for__g_CDmeDefineBoneListPullInModule__()
{
  g_CDmeDefineBoneListPullInModule = g_CDmeDefineBoneListLinkerHack;
  return g_CDmeDefineBoneListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4460
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterialGroup *dynamic_initializer_for__g_CDmeMaterialGroupPullInModule__()
{
  g_CDmeMaterialGroupPullInModule = g_CDmeMaterialGroupLinkerHack;
  return g_CDmeMaterialGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4470
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterialGroupList *dynamic_initializer_for__g_CDmeMaterialGroupListPullInModule__()
{
  g_CDmeMaterialGroupListPullInModule = g_CDmeMaterialGroupListLinkerHack;
  return g_CDmeMaterialGroupListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4480
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobalsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEyeballGlobals *dynamic_initializer_for__g_CDmeEyeballGlobalsPullInModule__()
{
  g_CDmeEyeballGlobalsPullInModule = g_CDmeEyeballGlobalsLinkerHack;
  return g_CDmeEyeballGlobalsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4490
// Name: _dynamic_initializer_for__g_CDmeEyeballPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEyeball *dynamic_initializer_for__g_CDmeEyeballPullInModule__()
{
  g_CDmeEyeballPullInModule = g_CDmeEyeballLinkerHack;
  return g_CDmeEyeballLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E44A0
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolumePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSkinnerVolume *dynamic_initializer_for__g_CDmeSkinnerVolumePullInModule__()
{
  g_CDmeSkinnerVolumePullInModule = g_CDmeSkinnerVolumeLinkerHack;
  return g_CDmeSkinnerVolumeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E44B0
// Name: _dynamic_initializer_for__g_CDmeSkinnerJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSkinnerJoint *dynamic_initializer_for__g_CDmeSkinnerJointPullInModule__()
{
  g_CDmeSkinnerJointPullInModule = g_CDmeSkinnerJointLinkerHack;
  return g_CDmeSkinnerJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E44C0
// Name: _dynamic_initializer_for__g_CDmeSkinnerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSkinner *dynamic_initializer_for__g_CDmeSkinnerPullInModule__()
{
  g_CDmeSkinnerPullInModule = g_CDmeSkinnerLinkerHack;
  return g_CDmeSkinnerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E44D0
// Name: _dynamic_initializer_for__g_CDmePoseParameterPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePoseParameter *dynamic_initializer_for__g_CDmePoseParameterPullInModule__()
{
  g_CDmePoseParameterPullInModule = g_CDmePoseParameterLinkerHack;
  return g_CDmePoseParameterLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E44E0
// Name: _dynamic_initializer_for__g_CDmePoseParameterListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePoseParameterList *dynamic_initializer_for__g_CDmePoseParameterListPullInModule__()
{
  g_CDmePoseParameterListPullInModule = g_CDmePoseParameterListLinkerHack;
  return g_CDmePoseParameterListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E44F0
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSizePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimBlockSize *dynamic_initializer_for__g_CDmeAnimBlockSizePullInModule__()
{
  g_CDmeAnimBlockSizePullInModule = g_CDmeAnimBlockSizeLinkerHack;
  return g_CDmeAnimBlockSizeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4500
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceLayerBase *dynamic_initializer_for__g_CDmeSequenceLayerBasePullInModule__()
{
  g_CDmeSequenceLayerBasePullInModule = g_CDmeSequenceLayerBaseLinkerHack;
  return g_CDmeSequenceLayerBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4510
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceAddLayer *dynamic_initializer_for__g_CDmeSequenceAddLayerPullInModule__()
{
  g_CDmeSequenceAddLayerPullInModule = g_CDmeSequenceAddLayerLinkerHack;
  return g_CDmeSequenceAddLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4520
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequenceBlendLayer *dynamic_initializer_for__g_CDmeSequenceBlendLayerPullInModule__()
{
  g_CDmeSequenceBlendLayerPullInModule = g_CDmeSequenceBlendLayerLinkerHack;
  return g_CDmeSequenceBlendLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4530
// Name: _dynamic_initializer_for__g_CDmeAssetRootPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAssetRoot *dynamic_initializer_for__g_CDmeAssetRootPullInModule__()
{
  g_CDmeAssetRootPullInModule = g_CDmeAssetRootLinkerHack;
  return g_CDmeAssetRootLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4540
// Name: _dynamic_initializer_for__g_CDmeRelatedAssetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRelatedAsset *dynamic_initializer_for__g_CDmeRelatedAssetPullInModule__()
{
  g_CDmeRelatedAssetPullInModule = g_CDmeRelatedAssetLinkerHack;
  return g_CDmeRelatedAssetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4550
// Name: _dynamic_initializer_for__g_CDmeElementGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeElementGroup *dynamic_initializer_for__g_CDmeElementGroupPullInModule__()
{
  g_CDmeElementGroupPullInModule = g_CDmeElementGroupLinkerHack;
  return g_CDmeElementGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4560
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneFlexDriverControl *dynamic_initializer_for__g_CDmeBoneFlexDriverControlPullInModule__()
{
  g_CDmeBoneFlexDriverControlPullInModule = g_CDmeBoneFlexDriverControlLinkerHack;
  return g_CDmeBoneFlexDriverControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4570
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneFlexDriver *dynamic_initializer_for__g_CDmeBoneFlexDriverPullInModule__()
{
  g_CDmeBoneFlexDriverPullInModule = g_CDmeBoneFlexDriverLinkerHack;
  return g_CDmeBoneFlexDriverLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4580
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneFlexDriverList *dynamic_initializer_for__g_CDmeBoneFlexDriverListPullInModule__()
{
  g_CDmeBoneFlexDriverListPullInModule = g_CDmeBoneFlexDriverListLinkerHack;
  return g_CDmeBoneFlexDriverListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4590
// Name: _dynamic_initializer_for__g_CDmeProceduralBonePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeProceduralBone *dynamic_initializer_for__g_CDmeProceduralBonePullInModule__()
{
  g_CDmeProceduralBonePullInModule = g_CDmeProceduralBoneLinkerHack;
  return g_CDmeProceduralBoneLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E45A0
// Name: _dynamic_initializer_for__g_CDmeJiggleBonePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJiggleBone *dynamic_initializer_for__g_CDmeJiggleBonePullInModule__()
{
  g_CDmeJiggleBonePullInModule = g_CDmeJiggleBoneLinkerHack;
  return g_CDmeJiggleBoneLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E45B0
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettingsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysPanelSettings *dynamic_initializer_for__g_CDmeMatSysPanelSettingsPullInModule__()
{
  g_CDmeMatSysPanelSettingsPullInModule = g_CDmeMatSysPanelSettingsLinkerHack;
  return g_CDmeMatSysPanelSettingsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E45C0
// Name: _dynamic_initializer_for__g_CDmeMatSysRootPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysRoot *dynamic_initializer_for__g_CDmeMatSysRootPullInModule__()
{
  g_CDmeMatSysRootPullInModule = g_CDmeMatSysRootLinkerHack;
  return g_CDmeMatSysRootLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E45D0
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysMDLDag *dynamic_initializer_for__g_CDmeMatSysMDLDagPullInModule__()
{
  g_CDmeMatSysMDLDagPullInModule = g_CDmeMatSysMDLDagLinkerHack;
  return g_CDmeMatSysMDLDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E45E0
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysDMXDag *dynamic_initializer_for__g_CDmeMatSysDMXDagPullInModule__()
{
  g_CDmeMatSysDMXDagPullInModule = g_CDmeMatSysDMXDagLinkerHack;
  return g_CDmeMatSysDMXDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E45F0
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMatSysMPPDag *dynamic_initializer_for__g_CDmeMatSysMPPDagPullInModule__()
{
  g_CDmeMatSysMPPDagPullInModule = g_CDmeMatSysMPPDagLinkerHack;
  return g_CDmeMatSysMPPDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4600
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommandPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAssemblyCommand *dynamic_initializer_for__g_CDmeAssemblyCommandPullInModule__()
{
  g_CDmeAssemblyCommandPullInModule = g_CDmeAssemblyCommandLinkerHack;
  return g_CDmeAssemblyCommandLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4610
// Name: _dynamic_initializer_for__g_CDmeAnimationAssemblyCommandPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationAssemblyCommand *dynamic_initializer_for__g_CDmeAnimationAssemblyCommandPullInModule__()
{
  g_CDmeAnimationAssemblyCommandPullInModule = g_CDmeAnimationAssemblyCommandLinkerHack;
  return g_CDmeAnimationAssemblyCommandLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4620
// Name: _dynamic_initializer_for__g_CDmeFixupLoopPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFixupLoop *dynamic_initializer_for__g_CDmeFixupLoopPullInModule__()
{
  g_CDmeFixupLoopPullInModule = g_CDmeFixupLoopLinkerHack;
  return g_CDmeFixupLoopLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4630
// Name: _dynamic_initializer_for__g_CDmeSubtractPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSubtract *dynamic_initializer_for__g_CDmeSubtractPullInModule__()
{
  g_CDmeSubtractPullInModule = g_CDmeSubtractLinkerHack;
  return g_CDmeSubtractLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4640
// Name: _dynamic_initializer_for__g_CDmePreSubtractPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePreSubtract *dynamic_initializer_for__g_CDmePreSubtractPullInModule__()
{
  g_CDmePreSubtractPullInModule = g_CDmePreSubtractLinkerHack;
  return g_CDmePreSubtractLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4650
// Name: _dynamic_initializer_for__g_CDmeRotateToPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRotateTo *dynamic_initializer_for__g_CDmeRotateToPullInModule__()
{
  g_CDmeRotateToPullInModule = g_CDmeRotateToLinkerHack;
  return g_CDmeRotateToLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4660
// Name: _dynamic_initializer_for__g_CDmeBoneMaskCmdPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeBoneMaskCmd *dynamic_initializer_for__g_CDmeBoneMaskCmdPullInModule__()
{
  g_CDmeBoneMaskCmdPullInModule = g_CDmeBoneMaskCmdLinkerHack;
  return g_CDmeBoneMaskCmdLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4670
// Name: _dynamic_initializer_for__g_CDmeEyelidPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEyelid *dynamic_initializer_for__g_CDmeEyelidPullInModule__()
{
  g_CDmeEyelidPullInModule = g_CDmeEyelidLinkerHack;
  return g_CDmeEyelidLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4680
// Name: _dynamic_initializer_for__g_CDmeMouthPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMouth *dynamic_initializer_for__g_CDmeMouthPullInModule__()
{
  g_CDmeMouthPullInModule = g_CDmeMouthLinkerHack;
  return g_CDmeMouthLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4690
// Name: _dynamic_initializer_for__g_CDmElementPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *dynamic_initializer_for__g_CDmElementPullInModule__()
{
  g_CDmElementPullInModule = g_CDmElementLinkerHack;
  return g_CDmElementLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E46A0
// Name: _dynamic_initializer_for__g_CDmeTransformPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransform *dynamic_initializer_for__g_CDmeTransformPullInModule__()
{
  g_CDmeTransformPullInModule = g_CDmeTransformLinkerHack;
  return g_CDmeTransformLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E46B0
// Name: _dynamic_initializer_for__g_CDmeTransformListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformList *dynamic_initializer_for__g_CDmeTransformListPullInModule__()
{
  g_CDmeTransformListPullInModule = g_CDmeTransformListLinkerHack;
  return g_CDmeTransformListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E46C0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDataBase *dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__()
{
  g_CDmeVertexDataBasePullInModule = g_CDmeVertexDataBaseLinkerHack;
  return g_CDmeVertexDataBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E46D0
// Name: _dynamic_initializer_for__g_CDmeVertexDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexData *dynamic_initializer_for__g_CDmeVertexDataPullInModule__()
{
  g_CDmeVertexDataPullInModule = g_CDmeVertexDataLinkerHack;
  return g_CDmeVertexDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E46E0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDeltaData *dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__()
{
  g_CDmeVertexDeltaDataPullInModule = g_CDmeVertexDeltaDataLinkerHack;
  return g_CDmeVertexDeltaDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E46F0
// Name: _dynamic_initializer_for__g_CDmeShapePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeShape *dynamic_initializer_for__g_CDmeShapePullInModule__()
{
  g_CDmeShapePullInModule = g_CDmeShapeLinkerHack;
  return g_CDmeShapeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4700
// Name: _dynamic_initializer_for__g_CDmeMeshPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *dynamic_initializer_for__g_CDmeMeshPullInModule__()
{
  g_CDmeMeshPullInModule = g_CDmeMeshLinkerHack;
  return g_CDmeMeshLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4710
// Name: _dynamic_initializer_for__g_CDmeDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *dynamic_initializer_for__g_CDmeDagPullInModule__()
{
  g_CDmeDagPullInModule = g_CDmeDagLinkerHack;
  return g_CDmeDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4720
// Name: _dynamic_initializer_for__g_CDmeFaceSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFaceSet *dynamic_initializer_for__g_CDmeFaceSetPullInModule__()
{
  g_CDmeFaceSetPullInModule = g_CDmeFaceSetLinkerHack;
  return g_CDmeFaceSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4730
// Name: _dynamic_initializer_for__g_CDmeModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeModel *dynamic_initializer_for__g_CDmeModelPullInModule__()
{
  g_CDmeModelPullInModule = g_CDmeModelLinkerHack;
  return g_CDmeModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4740
// Name: _dynamic_initializer_for__g_CDmeJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJoint *dynamic_initializer_for__g_CDmeJointPullInModule__()
{
  g_CDmeJointPullInModule = g_CDmeJointLinkerHack;
  return g_CDmeJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4750
// Name: _dynamic_initializer_for__g_CDmeAttachmentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAttachment *dynamic_initializer_for__g_CDmeAttachmentPullInModule__()
{
  g_CDmeAttachmentPullInModule = g_CDmeAttachmentLinkerHack;
  return g_CDmeAttachmentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4760
// Name: _dynamic_initializer_for__g_CDmeMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMakefile *dynamic_initializer_for__g_CDmeMakefilePullInModule__()
{
  g_CDmeMakefilePullInModule = g_CDmeMakefileLinkerHack;
  return g_CDmeMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4770
// Name: _dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDLMakefile *dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__()
{
  g_CDmeMDLMakefilePullInModule = g_CDmeMDLMakefileLinkerHack;
  return g_CDmeMDLMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4780
// Name: _dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDCCMakefile *dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__()
{
  g_CDmeDCCMakefilePullInModule = g_CDmeDCCMakefileLinkerHack;
  return g_CDmeDCCMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4790
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaAnimationMakefile *dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__()
{
  g_CDmeMayaAnimationMakefilePullInModule = g_CDmeMayaAnimationMakefileLinkerHack;
  return g_CDmeMayaAnimationMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E47A0
// Name: _dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaCombinationOperator *dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__()
{
  g_CDmeMayaCombinationOperatorPullInModule = g_CDmeMayaCombinationOperatorLinkerHack;
  return g_CDmeMayaCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E47B0
// Name: _dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaMakefile *dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__()
{
  g_CDmeMayaMakefilePullInModule = g_CDmeMayaMakefileLinkerHack;
  return g_CDmeMayaMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E47C0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaModelMakefile *dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__()
{
  g_CDmeMayaModelMakefilePullInModule = g_CDmeMayaModelMakefileLinkerHack;
  return g_CDmeMayaModelMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E47D0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeXSIMakefile *dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__()
{
  g_CDmeXSIMakefilePullInModule = g_CDmeXSIMakefileLinkerHack;
  return g_CDmeXSIMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E47E0
// Name: _dynamic_initializer_for__g_CDmeSourcePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSource *dynamic_initializer_for__g_CDmeSourcePullInModule__()
{
  g_CDmeSourcePullInModule = g_CDmeSourceLinkerHack;
  return g_CDmeSourceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E47F0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceDCCFile *dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__()
{
  g_CDmeSourceDCCFilePullInModule = g_CDmeSourceDCCFileLinkerHack;
  return g_CDmeSourceDCCFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4800
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaFile *dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__()
{
  g_CDmeSourceMayaFilePullInModule = g_CDmeSourceMayaFileLinkerHack;
  return g_CDmeSourceMayaFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4810
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaModelFile *dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__()
{
  g_CDmeSourceMayaModelFilePullInModule = g_CDmeSourceMayaModelFileLinkerHack;
  return g_CDmeSourceMayaModelFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4820
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaAnimationFile *dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__()
{
  g_CDmeSourceMayaAnimationFilePullInModule = g_CDmeSourceMayaAnimationFileLinkerHack;
  return g_CDmeSourceMayaAnimationFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4830
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceXSIFile *dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__()
{
  g_CDmeSourceXSIFilePullInModule = g_CDmeSourceXSIFileLinkerHack;
  return g_CDmeSourceXSIFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4840
// Name: _dynamic_initializer_for__g_CDmeAnimationListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationList *dynamic_initializer_for__g_CDmeAnimationListPullInModule__()
{
  g_CDmeAnimationListPullInModule = g_CDmeAnimationListLinkerHack;
  return g_CDmeAnimationListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4850
// Name: _dynamic_initializer_for__g_CDmeClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *dynamic_initializer_for__g_CDmeClipPullInModule__()
{
  g_CDmeClipPullInModule = g_CDmeClipLinkerHack;
  return g_CDmeClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4860
// Name: _dynamic_initializer_for__g_CDmeChannelsClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *dynamic_initializer_for__g_CDmeChannelsClipPullInModule__()
{
  g_CDmeChannelsClipPullInModule = g_CDmeChannelsClipLinkerHack;
  return g_CDmeChannelsClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4870
// Name: _dynamic_initializer_for__g_CDmeChannelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannel *dynamic_initializer_for__g_CDmeChannelPullInModule__()
{
  g_CDmeChannelPullInModule = g_CDmeChannelLinkerHack;
  return g_CDmeChannelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4880
// Name: _dynamic_initializer_for__g_CDmeTimeFramePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeFrame *dynamic_initializer_for__g_CDmeTimeFramePullInModule__()
{
  g_CDmeTimeFramePullInModule = g_CDmeTimeFrameLinkerHack;
  return g_CDmeTimeFrameLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4890
// Name: _dynamic_initializer_for__g_CDmeTrackGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrackGroup *dynamic_initializer_for__g_CDmeTrackGroupPullInModule__()
{
  g_CDmeTrackGroupPullInModule = g_CDmeTrackGroupLinkerHack;
  return g_CDmeTrackGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E48A0
// Name: _dynamic_initializer_for__g_CDmeTrackPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrack *dynamic_initializer_for__g_CDmeTrackPullInModule__()
{
  g_CDmeTrackPullInModule = g_CDmeTrackLinkerHack;
  return g_CDmeTrackLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E48B0
// Name: _dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationDominationRule *dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__()
{
  g_CDmeCombinationDominationRulePullInModule = g_CDmeCombinationDominationRuleLinkerHack;
  return g_CDmeCombinationDominationRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E48C0
// Name: _dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationInputControl *dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__()
{
  g_CDmeCombinationInputControlPullInModule = g_CDmeCombinationInputControlLinkerHack;
  return g_CDmeCombinationInputControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E48D0
// Name: _dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__()
{
  g_CDmeCombinationOperatorPullInModule = g_CDmeCombinationOperatorLinkerHack;
  return g_CDmeCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E48E0
// Name: _dynamic_initializer_for__g_CDmeIntLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<int> *dynamic_initializer_for__g_CDmeIntLogPullInModule__()
{
  g_CDmeIntLogPullInModule = g_CDmeIntLogLinkerHack;
  return g_CDmeIntLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E48F0
// Name: _dynamic_initializer_for__g_CDmeFloatLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<float> *dynamic_initializer_for__g_CDmeFloatLogPullInModule__()
{
  g_CDmeFloatLogPullInModule = g_CDmeFloatLogLinkerHack;
  return g_CDmeFloatLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4900
// Name: _dynamic_initializer_for__g_CDmeBoolLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<bool> *dynamic_initializer_for__g_CDmeBoolLogPullInModule__()
{
  g_CDmeBoolLogPullInModule = g_CDmeBoolLogLinkerHack;
  return g_CDmeBoolLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4910
// Name: _dynamic_initializer_for__g_CDmeColorLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Color> *dynamic_initializer_for__g_CDmeColorLogPullInModule__()
{
  g_CDmeColorLogPullInModule = g_CDmeColorLogLinkerHack;
  return g_CDmeColorLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4920
// Name: _dynamic_initializer_for__g_CDmeVector2LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogPullInModule__()
{
  g_CDmeVector2LogPullInModule = g_CDmeVector2LogLinkerHack;
  return g_CDmeVector2LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4930
// Name: _dynamic_initializer_for__g_CDmeVector3LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector> *dynamic_initializer_for__g_CDmeVector3LogPullInModule__()
{
  g_CDmeVector3LogPullInModule = g_CDmeVector3LogLinkerHack;
  return g_CDmeVector3LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4940
// Name: _dynamic_initializer_for__g_CDmeVector4LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogPullInModule__()
{
  g_CDmeVector4LogPullInModule = g_CDmeVector4LogLinkerHack;
  return g_CDmeVector4LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4950
// Name: _dynamic_initializer_for__g_CDmeQAngleLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogPullInModule__()
{
  g_CDmeQAngleLogPullInModule = g_CDmeQAngleLogLinkerHack;
  return g_CDmeQAngleLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4960
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__()
{
  g_CDmeQuaternionLogPullInModule = g_CDmeQuaternionLogLinkerHack;
  return g_CDmeQuaternionLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4970
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__()
{
  g_CDmeVMatrixLogPullInModule = g_CDmeVMatrixLogLinkerHack;
  return g_CDmeVMatrixLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4980
// Name: _dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<int> *dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__()
{
  g_CDmeIntLogLayerPullInModule = g_CDmeIntLogLayerLinkerHack;
  return g_CDmeIntLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4990
// Name: _dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<float> *dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__()
{
  g_CDmeFloatLogLayerPullInModule = g_CDmeFloatLogLayerLinkerHack;
  return g_CDmeFloatLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E49A0
// Name: _dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<bool> *dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__()
{
  g_CDmeBoolLogLayerPullInModule = g_CDmeBoolLogLayerLinkerHack;
  return g_CDmeBoolLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E49B0
// Name: _dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Color> *dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__()
{
  g_CDmeColorLogLayerPullInModule = g_CDmeColorLogLayerLinkerHack;
  return g_CDmeColorLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E49C0
// Name: _dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__()
{
  g_CDmeVector2LogLayerPullInModule = g_CDmeVector2LogLayerLinkerHack;
  return g_CDmeVector2LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E49D0
// Name: _dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector> *dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__()
{
  g_CDmeVector3LogLayerPullInModule = g_CDmeVector3LogLayerLinkerHack;
  return g_CDmeVector3LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E49E0
// Name: _dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__()
{
  g_CDmeVector4LogLayerPullInModule = g_CDmeVector4LogLayerLinkerHack;
  return g_CDmeVector4LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E49F0
// Name: _dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__()
{
  g_CDmeQAngleLogLayerPullInModule = g_CDmeQAngleLogLayerLinkerHack;
  return g_CDmeQAngleLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A00
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__()
{
  g_CDmeQuaternionLogLayerPullInModule = g_CDmeQuaternionLogLayerLinkerHack;
  return g_CDmeQuaternionLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A10
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__()
{
  g_CDmeVMatrixLogLayerPullInModule = g_CDmeVMatrixLogLayerLinkerHack;
  return g_CDmeVMatrixLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A20
// Name: _dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<int> *dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__()
{
  g_CDmeIntCurveInfoPullInModule = g_CDmeIntCurveInfoLinkerHack;
  return g_CDmeIntCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A30
// Name: _dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<float> *dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__()
{
  g_CDmeFloatCurveInfoPullInModule = g_CDmeFloatCurveInfoLinkerHack;
  return g_CDmeFloatCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A40
// Name: _dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<bool> *dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__()
{
  g_CDmeBoolCurveInfoPullInModule = g_CDmeBoolCurveInfoLinkerHack;
  return g_CDmeBoolCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A50
// Name: _dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Color> *dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__()
{
  g_CDmeColorCurveInfoPullInModule = g_CDmeColorCurveInfoLinkerHack;
  return g_CDmeColorCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A60
// Name: _dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector2D> *dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__()
{
  g_CDmeVector2CurveInfoPullInModule = g_CDmeVector2CurveInfoLinkerHack;
  return g_CDmeVector2CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A70
// Name: _dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector> *dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__()
{
  g_CDmeVector3CurveInfoPullInModule = g_CDmeVector3CurveInfoLinkerHack;
  return g_CDmeVector3CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A80
// Name: _dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector4D> *dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__()
{
  g_CDmeVector4CurveInfoPullInModule = g_CDmeVector4CurveInfoLinkerHack;
  return g_CDmeVector4CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4A90
// Name: _dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<QAngle> *dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__()
{
  g_CDmeQAngleCurveInfoPullInModule = g_CDmeQAngleCurveInfoLinkerHack;
  return g_CDmeQAngleCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4AA0
// Name: _dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__()
{
  g_CDmeQuaternionCurveInfoPullInModule = g_CDmeQuaternionCurveInfoLinkerHack;
  return g_CDmeQuaternionCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4AB0
// Name: _dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__()
{
  g_CDmeVMatrixCurveInfoPullInModule = g_CDmeVMatrixCurveInfoLinkerHack;
  return g_CDmeVMatrixCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4AC0
// Name: _dynamic_initializer_for__g_CDmeComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeComponent *dynamic_initializer_for__g_CDmeComponentPullInModule__()
{
  g_CDmeComponentPullInModule = g_CDmeComponentLinkerHack;
  return g_CDmeComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4AD0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSingleIndexedComponent *dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__()
{
  g_CDmeSingleIndexedComponentPullInModule = g_CDmeSingleIndexedComponentLinkerHack;
  return g_CDmeSingleIndexedComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4AE0
// Name: _dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDrawSettings *dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__()
{
  g_CDmeDrawSettingsPullInModule = g_CDmeDrawSettingsLinkerHack;
  return g_CDmeDrawSettingsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005E4AF0
// Name: _dynamic_initializer_for__g_MtlLib__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MtlLib__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MtlLib__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4B00
// Name: _dynamic_initializer_for__UNSPECIFIED_LOGGING_COLOR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__UNSPECIFIED_LOGGING_COLOR__()
{
  UNSPECIFIED_LOGGING_COLOR_15._color[0] = 0;
  UNSPECIFIED_LOGGING_COLOR_15._color[1] = 0;
  UNSPECIFIED_LOGGING_COLOR_15._color[2] = 0;
  UNSPECIFIED_LOGGING_COLOR_15._color[3] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005E4B30
// Name: _dynamic_initializer_for__vec2_origin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__vec2_origin__()
{
  vec2_origin_14.x = 0.0;
  vec2_origin_14.y = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x005E4B60
// Name: _dynamic_initializer_for__vec2_invalid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__vec2_invalid__()
{
  vec2_invalid_180.x = 3.4028235e38;
  vec2_invalid_180.y = 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x005E4B90
// Name: _dynamic_initializer_for__vec4_origin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__vec4_origin__()
{
  vec4_origin_8.x = 0.0;
  vec4_origin_8.y = 0.0;
  vec4_origin_8.z = 0.0;
  vec4_origin_8.w = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x005E4BE0
// Name: _dynamic_initializer_for__vec4_invalid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__vec4_invalid__()
{
  vec4_invalid_145.x = 3.4028235e38;
  vec4_invalid_145.y = 3.4028235e38;
  vec4_invalid_145.z = 3.4028235e38;
  vec4_invalid_145.w = 3.4028235e38;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00576D40
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_5C92B8[(unsigned __int8)((int)va + dword_5C92B8[(unsigned __int8)(int)fxa])];
  v26 = dword_5C92B8[(unsigned __int8)((int)va + dword_5C92B8[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_5C92B8[(unsigned __int8)((int)va + dword_5C92B8[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_5C92B8[(unsigned __int8)((int)va + dword_5C92B8[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_5C92B8[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_5C92B8[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_5C92B8[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_5C92B8[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_5C92B8[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_5C92B8[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_5C92B8[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_5C92B8[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_5C92B8[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_5C92B8[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_5C92B8[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_5C92B8[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_5C92B8[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_5C92B8[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_5C92B8[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_5C92B8[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_5C92B8[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_5C92B8[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_5C92B8[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_5C92B8[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_5C92B8[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_5C92B8[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_5C92B8[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_5C92B8[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_5C92B8[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_5C92B8[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_5C92B8[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_5C92B8[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_5C92B8[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_5C92B8[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_5C92B8[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_5C92B8[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x006B37F0
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_7861B8[(unsigned __int8)((int)va + dword_7861B8[(unsigned __int8)(int)fxa])];
  v26 = dword_7861B8[(unsigned __int8)((int)va + dword_7861B8[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_7861B8[(unsigned __int8)((int)va + dword_7861B8[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_7861B8[(unsigned __int8)((int)va + dword_7861B8[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_7861B8[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_7861B8[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_7861B8[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_7861B8[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_7861B8[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_7861B8[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_7861B8[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_7861B8[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_7861B8[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_7861B8[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_7861B8[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_7861B8[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_7861B8[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_7861B8[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_7861B8[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_7861B8[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_7861B8[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_7861B8[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_7861B8[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_7861B8[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_7861B8[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_7861B8[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_7861B8[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_7861B8[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_7861B8[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_7861B8[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_7861B8[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_7861B8[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_7861B8[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_7861B8[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_7861B8[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_7861B8[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace vmap

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x10033840
// Name: float ImprovedPerlinNoise(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ImprovedPerlinNoise(const Vector *pnt)
{
  const Vector *v1; // eax
  float x; // xmm3_4
  __m128 x_low; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 y_low; // xmm4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z_low; // xmm2
  float v16; // xmm4_4
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm6_4
  int v25; // edi
  int v26; // esi
  int v27; // edx
  int v28; // ecx
  unsigned __int8 v29; // di
  unsigned __int8 v30; // si
  unsigned __int8 v31; // dl
  unsigned __int8 v32; // cl
  unsigned int v33; // eax
  unsigned int v34; // eax
  float v35; // xmm4_4
  float v36; // xmm3_4
  unsigned int v37; // eax
  float v38; // xmm5_4
  float v39; // xmm4_4
  unsigned int v40; // eax
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // edi
  unsigned int v44; // eax
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  unsigned int v48; // eax
  float v49; // xmm4_4
  unsigned int v50; // eax
  float v51; // xmm0_4
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  double v55; // st6
  float w; // [esp+8h] [ebp-28h]
  float g6; // [esp+Ch] [ebp-24h]
  float g2; // [esp+10h] [ebp-20h]
  float g2a; // [esp+10h] [ebp-20h]
  float g4; // [esp+14h] [ebp-1Ch]
  float g5; // [esp+18h] [ebp-18h]
  float g1; // [esp+1Ch] [ebp-14h]
  float g0; // [esp+20h] [ebp-10h]
  float va; // [esp+24h] [ebp-Ch]
  float v; // [esp+24h] [ebp-Ch]
  float u; // [esp+28h] [ebp-8h]
  float v68; // [esp+2Ch] [ebp-4h]
  float fxa; // [esp+38h] [ebp+8h]
  float fx; // [esp+38h] [ebp+8h]

  v1 = pnt;
  x = pnt->x;
  x_low = (__m128)LODWORD(pnt->x);
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v6.m128_i32[0] = 1258291200;
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v6).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v7 = x_low;
  v7.m128_f32[0] = (float)(x_low.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - x_low.m128_f32[0];
  v8.m128_f32[0] = _mm_cmpgt_ss(v8, v5).m128_f32[0];
  y_low = (__m128)LODWORD(pnt->y);
  fxa = v7.m128_f32[0] - COERCE_FLOAT(v8.m128_i32[0] & 0x3F800000);
  v10 = x - fxa;
  v11 = _mm_and_ps((__m128)0x80000000, y_low);
  v12.m128_i32[0] = v11.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v11), v8).m128_f32[0]) & 0x4B000000
                 | v11.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(v1->z);
  va = v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v12).m128_f32[0]) & 0x3F800000);
  v16 = y_low.m128_f32[0] - va;
  v17 = _mm_and_ps((__m128)0x80000000, z_low);
  v12.m128_i32[0] = v17.m128_i32[0];
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v17), v14).m128_f32[0]) & 0x4B000000
                  | v17.m128_i32[0];
  v18 = z_low;
  v18.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - z_low.m128_f32[0];
  v12.m128_f32[0] = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v12).m128_f32[0]) & 0x3F800000);
  v20 = v10;
  v21 = v16;
  LOBYTE(v1) = (int)v12.m128_f32[0];
  v22 = z_low.m128_f32[0] - v12.m128_f32[0];
  v23 = (((float)(v20 * 6.0) - 15.0) * v20 + 10.0) * (float)((float)(v20 * v20) * v20);
  u = v23;
  v24 = (((float)(v21 * 6.0) - 15.0) * v21 + 10.0) * (float)((float)(v21 * v21) * v21);
  v25 = dword_1007F510[(unsigned __int8)((int)va + dword_1007F510[(unsigned __int8)(int)fxa])];
  v26 = dword_1007F510[(unsigned __int8)((int)va + dword_1007F510[(unsigned __int8)(int)fxa] + 1)];
  v27 = dword_1007F510[(unsigned __int8)((int)va + dword_1007F510[(unsigned __int8)((int)fxa + 1)])];
  v28 = dword_1007F510[(unsigned __int8)((int)va + dword_1007F510[(unsigned __int8)((int)fxa + 1)] + 1)];
  v = v24;
  v29 = (_BYTE)v1 + v25;
  v30 = (_BYTE)v1 + v26;
  v31 = (_BYTE)v1 + v27;
  v32 = (_BYTE)v1 + v28;
  v33 = dword_1007F510[v29] & 0xF;
  w = (((float)(v22 * 6.0) - 15.0) * v22 + 10.0) * (float)((float)(v22 * v22) * v22);
  if ( v33 < 8 )
    v16 = v10;
  if ( (dword_1007F510[v29] & 0xFu) >= 4 )
  {
    if ( v33 != 12 && v33 != 14 )
      v10 = v22;
  }
  else
  {
    v10 = v21;
  }
  if ( (dword_1007F510[v29] & 1) != 0 )
    v16 = -v16;
  if ( (dword_1007F510[v29] & 2) != 0 )
    v10 = -v10;
  v34 = dword_1007F510[v31] & 0xF;
  g0 = v10 + v16;
  v68 = v20 - 1.0;
  if ( v34 >= 8 )
    v35 = v21;
  else
    v35 = v20 - 1.0;
  if ( (dword_1007F510[v31] & 0xFu) >= 4 )
  {
    if ( v34 == 12 || v34 == 14 )
      v36 = v20 - 1.0;
    else
      v36 = v22;
  }
  else
  {
    v36 = v21;
  }
  if ( (dword_1007F510[v31] & 1) != 0 )
    v35 = -v35;
  if ( (dword_1007F510[v31] & 2) != 0 )
    v36 = -v36;
  g1 = v36 + v35;
  v37 = dword_1007F510[v30] & 0xF;
  fx = v21 - 1.0;
  if ( v37 >= 8 )
    v38 = v21 - 1.0;
  else
    v38 = v20;
  if ( (dword_1007F510[v30] & 0xFu) >= 4 )
  {
    if ( v37 == 12 || v37 == 14 )
      v39 = v20;
    else
      v39 = v22;
  }
  else
  {
    v39 = v21 - 1.0;
  }
  if ( (dword_1007F510[v30] & 1) != 0 )
    v38 = -v38;
  if ( (dword_1007F510[v30] & 2) != 0 )
    v39 = -v39;
  v40 = dword_1007F510[v32] & 0xF;
  g2 = v39 + v38;
  if ( v40 >= 8 )
    v41 = v21 - 1.0;
  else
    v41 = v20 - 1.0;
  if ( (dword_1007F510[v32] & 0xFu) >= 4 )
  {
    if ( v40 == 12 || v40 == 14 )
      v42 = v20 - 1.0;
    else
      v42 = v22;
  }
  else
  {
    v42 = v21 - 1.0;
  }
  if ( (dword_1007F510[v32] & 1) != 0 )
    v41 = -v41;
  if ( (dword_1007F510[v32] & 2) != 0 )
    v42 = -v42;
  v43 = (unsigned __int8)(v29 + 1);
  v44 = dword_1007F510[v43] & 0xF;
  v45 = v42 + v41;
  if ( v44 >= 8 )
    v46 = v21;
  else
    v46 = v20;
  if ( (dword_1007F510[v43] & 0xFu) >= 4 )
  {
    if ( v44 == 12 || v44 == 14 )
      v47 = v20;
    else
      v47 = v22 - 1.0;
  }
  else
  {
    v47 = v21;
  }
  if ( (dword_1007F510[v43] & 1) != 0 )
    v46 = -v46;
  if ( (dword_1007F510[v43] & 2) != 0 )
    v47 = -v47;
  v48 = dword_1007F510[(unsigned __int8)(v31 + 1)] & 0xF;
  g4 = v47 + v46;
  if ( v48 >= 8 )
    v49 = v21;
  else
    v49 = v20 - 1.0;
  if ( (dword_1007F510[(unsigned __int8)(v31 + 1)] & 0xFu) >= 4 )
  {
    if ( v48 == 12 || v48 == 14 )
      v21 = v20 - 1.0;
    else
      v21 = v22 - 1.0;
  }
  if ( (dword_1007F510[(unsigned __int8)(v31 + 1)] & 1) != 0 )
    v49 = -v49;
  if ( (dword_1007F510[(unsigned __int8)(v31 + 1)] & 2) != 0 )
    v21 = -v21;
  v50 = dword_1007F510[(unsigned __int8)(v30 + 1)] & 0xF;
  g5 = v21 + v49;
  if ( v50 >= 8 )
    v51 = fx;
  else
    v51 = v20;
  if ( (dword_1007F510[(unsigned __int8)(v30 + 1)] & 0xFu) >= 4 )
  {
    if ( v50 != 12 && v50 != 14 )
      v20 = v22 - 1.0;
  }
  else
  {
    v20 = fx;
  }
  if ( (dword_1007F510[(unsigned __int8)(v30 + 1)] & 1) != 0 )
    v51 = -v51;
  if ( (dword_1007F510[(unsigned __int8)(v30 + 1)] & 2) != 0 )
    v20 = -v20;
  v52 = dword_1007F510[(unsigned __int8)(v32 + 1)] & 0xF;
  g6 = v20 + v51;
  if ( v52 >= 8 )
    v53 = fx;
  else
    v53 = v68;
  if ( (dword_1007F510[(unsigned __int8)(v32 + 1)] & 0xFu) >= 4 )
  {
    if ( v52 == 12 || v52 == 14 )
      v54 = v68;
    else
      v54 = v22 - 1.0;
  }
  else
  {
    v54 = fx;
  }
  if ( (dword_1007F510[(unsigned __int8)(v32 + 1)] & 1) != 0 )
    v53 = -v53;
  if ( (dword_1007F510[(unsigned __int8)(v32 + 1)] & 2) != 0 )
    v54 = -v54;
  v55 = g4 + (g5 - g4) * u;
  g2a = (float)((float)((float)((float)((float)(v45 - g2) * u) + g2) - (float)(g0 + (float)((float)(g1 - g0) * u))) * v)
      + (float)(g0 + (float)((float)(g1 - g0) * u));
  return g2a + (v55 + (u * (v54 + v53 - g6) + g6 - v55) * v - g2a) * w;
}

} // namespace matchmaking
