// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/ssenoise.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x104C4140
// Name: union __m128 NoiseSIMD(union __m128 const __near &,union __m128 const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
__m128 *__cdecl NoiseSIMD(__m128 *result, const __m128 *x, const __m128 *y)
{
  return (__m128 *)perm_c[(unsigned __int8)(perm_b[(unsigned __int8)(perm_a[(unsigned __int8)(_mm_and_ps(
                                                                                                _mm_add_ps(
                                                                                                  *result,
                                                                                                  Four_MagicNumbers_0),
                                                                                                *(__m128 *)idx_mask).m128_i8[13]
                                                                                            + 1)]
                                                                   + _mm_and_ps(
                                                                       _mm_add_ps(*x, Four_MagicNumbers_0),
                                                                       *(__m128 *)idx_mask).m128_i8[13]
                                                                   + 1)]
                                          + _mm_and_ps(_mm_add_ps(*y, Four_MagicNumbers_0), *(__m128 *)idx_mask).m128_i8[13]
                                          + 1)];
}

//------------------------------------------------------------------------------
// Address: 0x104C48E0
// Name: class FourVectors DNoiseSIMD(union __m128 const __near &,union __m128 const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
FourVectors *__cdecl DNoiseSIMD(FourVectors *result, const __m128 *x, const __m128 *y, const __m128 *z)
{
  int v4; // esi
  int v5; // esi
  int v6; // xmm0_4
  float *v7; // esi
  int v8; // xmm0_4
  int *v9; // esi
  unsigned __int8 v10; // di
  int *v11; // esi
  unsigned __int8 v12; // dl
  int *v13; // esi
  int *v14; // ecx
  int v15; // xmm0_4
  int *v16; // ecx
  int v17; // xmm0_4
  int *v18; // eax
  int *v19; // eax
  unsigned __int8 v20; // di
  int *v21; // esi
  int v22; // xmm0_4
  int *v23; // esi
  unsigned __int8 v24; // di
  unsigned __int8 v25; // dl
  int *v26; // ecx
  int *v27; // ecx
  int *v28; // eax
  int v29; // xmm0_4
  int *v30; // eax
  unsigned __int8 v31; // di
  int *v32; // esi
  int v33; // xmm0_4
  int *v34; // esi
  int v35; // xmm0_4
  unsigned __int8 v36; // di
  int *v37; // esi
  int v38; // xmm0_4
  int *v39; // esi
  unsigned __int8 v40; // dl
  int *v41; // ecx
  int *v42; // ecx
  int *v43; // eax
  int v44; // xmm0_4
  int *v45; // eax
  unsigned __int8 v46; // di
  int *v47; // esi
  int v48; // xmm0_4
  int *v49; // esi
  unsigned __int8 v50; // di
  int *v51; // esi
  unsigned __int8 v52; // dl
  int *v53; // esi
  int *v54; // ecx
  int v55; // xmm0_4
  int *v56; // ecx
  int v57; // edx
  int *v58; // eax
  int v59; // xmm0_4
  int *v60; // eax
  int v61; // xmm0_4
  __m128 v63; // xmm2
  __m128 v64; // xmm3
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm1
  __m128 v72; // [esp-Ch] [ebp-1FCh]
  __m128 z_idx_4; // [esp+4h] [ebp-1ECh]
  __m128 y_idx_4; // [esp+14h] [ebp-1DCh]
  __m128 x_idx_4; // [esp+24h] [ebp-1CCh]
  __m128 ylattice000_4; // [esp+34h] [ebp-1BCh]
  __m128 xlattice001_4; // [esp+44h] [ebp-1ACh]
  __m128 xlattice111_4; // [esp+54h] [ebp-19Ch]
  __m128 zlattice011_4; // [esp+64h] [ebp-18Ch]
  __m128 xlattice100_4; // [esp+74h] [ebp-17Ch]
  __m128 zlattice111_4; // [esp+84h] [ebp-16Ch]
  __m128 zfrac_4; // [esp+94h] [ebp-15Ch]
  __m128 zlattice010_4; // [esp+A4h] [ebp-14Ch]
  __m128 xlattice010_4; // [esp+B4h] [ebp-13Ch]
  __m128 zlattice110_4; // [esp+C4h] [ebp-12Ch]
  __m128 xfrac_4; // [esp+D4h] [ebp-11Ch]
  __m128 zlattice001_4; // [esp+E4h] [ebp-10Ch]
  __m128 ylattice101_4; // [esp+F4h] [ebp-FCh]
  __m128 zlattice101_4; // [esp+104h] [ebp-ECh]
  __m128 ylattice100_4; // [esp+114h] [ebp-DCh]
  __m128 zlattice000_4; // [esp+124h] [ebp-CCh]
  __m128 xlattice011_4; // [esp+134h] [ebp-BCh]
  __m128 zlattice100_4; // [esp+144h] [ebp-ACh]
  __m128 yfrac_4; // [esp+154h] [ebp-9Ch]
  __m128 ylattice011_4; // [esp+164h] [ebp-8Ch]
  __m128 xlattice110_4; // [esp+174h] [ebp-7Ch]
  __m128 ylattice111_4; // [esp+184h] [ebp-6Ch]
  __m128 xlattice101_4; // [esp+194h] [ebp-5Ch]
  __m128 ylattice010_4; // [esp+1A4h] [ebp-4Ch]
  __m128 xlattice000_4; // [esp+1B4h] [ebp-3Ch]
  __m128 ylattice110_4; // [esp+1C4h] [ebp-2Ch]
  unsigned int v102; // [esp+1E0h] [ebp-10h]

  y_idx_4 = _mm_and_ps(_mm_add_ps(*x, Four_MagicNumbers_0), *(__m128 *)idx_mask);
  z_idx_4 = _mm_and_ps(_mm_add_ps(*y, Four_MagicNumbers_0), *(__m128 *)idx_mask);
  v72 = _mm_and_ps(_mm_add_ps(*z, Four_MagicNumbers_0), *(__m128 *)idx_mask);
  zlattice110_4.m128_f32[0] = (double)y_idx_4.m128_u8[0] * 0.00390625;
  v4 = perm_b[(unsigned __int8)(z_idx_4.m128_i8[1] + perm_a[y_idx_4.m128_u8[1]])];
  zlattice100_4.m128_f32[0] = (double)z_idx_4.m128_u8[0] * 0.00390625;
  v102 = ((unsigned int)v72.m128_i32[0] >> 8) + v4;
  zlattice111_4.m128_f32[0] = (double)v72.m128_u8[0] * 0.00390625;
  v5 = 3 * perm_c[(unsigned __int8)(v72.m128_i8[1] + v4)];
  v6 = LODWORD(s_randomGradients[v5]);
  v7 = &s_randomGradients[v5];
  ylattice010_4.m128_i32[0] = v6;
  x_idx_4.m128_f32[0] = v7[1];
  v8 = *((_DWORD *)v7 + 2);
  v9 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v102 + 1)]];
  ylattice100_4.m128_i32[0] = v8;
  ylattice000_4.m128_i32[0] = *v9;
  ylattice110_4.m128_i32[0] = v9[1];
  v10 = v72.m128_i8[1] + perm_b[(unsigned __int8)(z_idx_4.m128_i8[1] + perm_a[y_idx_4.m128_u8[1]] + 1)];
  xfrac_4.m128_i32[0] = v9[2];
  v11 = (int *)&s_randomGradients[3 * perm_c[v10]];
  zlattice010_4.m128_i32[0] = *v11;
  xlattice101_4.m128_i32[0] = v11[1];
  v12 = perm_a[(unsigned __int8)(y_idx_4.m128_i8[1] + 1)] + z_idx_4.m128_i8[1];
  zfrac_4.m128_i32[0] = v11[2];
  v13 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v10 + 1)]];
  zlattice000_4.m128_i32[0] = *v13;
  yfrac_4.m128_i32[0] = v13[1];
  v14 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[1] + perm_b[v12])]];
  xlattice111_4.m128_i32[0] = v13[2];
  zlattice011_4.m128_i32[0] = *v14;
  zlattice101_4.m128_i32[0] = v14[1];
  v15 = v14[2];
  v16 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[1] + perm_b[v12] + 1)]];
  xlattice011_4.m128_i32[0] = v15;
  ylattice111_4.m128_i32[0] = *v16;
  zlattice001_4.m128_i32[0] = v16[1];
  v17 = v16[2];
  LOBYTE(v16) = v72.m128_i8[1] + perm_b[(unsigned __int8)(v12 + 1)];
  ylattice101_4.m128_i32[0] = v17;
  v18 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)v16]];
  ylattice011_4.m128_i32[0] = *v18;
  xlattice000_4.m128_i32[0] = v18[1];
  xlattice010_4.m128_i32[0] = v18[2];
  v19 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)((_BYTE)v16 + 1)]];
  xlattice001_4.m128_i32[0] = *v19;
  xlattice110_4.m128_i32[0] = v19[1];
  zlattice110_4.m128_f32[1] = (double)y_idx_4.m128_u8[4] * 0.00390625;
  v20 = z_idx_4.m128_i8[5] + perm_a[y_idx_4.m128_u8[5]];
  zlattice100_4.m128_f32[1] = (double)z_idx_4.m128_u8[4] * 0.00390625;
  zlattice111_4.m128_f32[1] = (double)v72.m128_u8[4] * 0.00390625;
  v21 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[5] + LOBYTE(perm_b[v20]))]];
  xlattice100_4.m128_i32[0] = v19[2];
  ylattice010_4.m128_i32[1] = *v21;
  x_idx_4.m128_i32[1] = v21[1];
  v22 = v21[2];
  v23 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[5] + LOBYTE(perm_b[v20]) + 1)]];
  ylattice100_4.m128_i32[1] = v22;
  ylattice000_4.m128_i32[1] = *v23;
  v24 = v72.m128_i8[5] + perm_b[(unsigned __int8)(v20 + 1)];
  ylattice110_4.m128_i32[1] = v23[1];
  xfrac_4.m128_i32[1] = v23[2];
  zlattice010_4.m128_f32[1] = s_randomGradients[3 * perm_c[v24]];
  xlattice101_4.m128_f32[1] = s_randomGradients[3 * perm_c[v24] + 1];
  v25 = perm_a[(unsigned __int8)(y_idx_4.m128_i8[5] + 1)] + z_idx_4.m128_i8[5];
  zfrac_4.m128_f32[1] = s_randomGradients[3 * perm_c[v24] + 2];
  zlattice000_4.m128_f32[1] = s_randomGradients[3 * perm_c[(unsigned __int8)(v24 + 1)]];
  yfrac_4.m128_f32[1] = s_randomGradients[3 * perm_c[(unsigned __int8)(v24 + 1)] + 1];
  LOBYTE(v23) = v72.m128_i8[5] + perm_b[v25];
  xlattice111_4.m128_f32[1] = s_randomGradients[3 * perm_c[(unsigned __int8)(v24 + 1)] + 2];
  v26 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)v23]];
  zlattice011_4.m128_i32[1] = *v26;
  zlattice101_4.m128_i32[1] = v26[1];
  xlattice011_4.m128_i32[1] = v26[2];
  v27 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)((_BYTE)v23 + 1)]];
  ylattice111_4.m128_i32[1] = *v27;
  zlattice001_4.m128_i32[1] = v27[1];
  v28 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[5] + perm_b[(unsigned __int8)(v25 + 1)])]];
  ylattice101_4.m128_i32[1] = v27[2];
  ylattice011_4.m128_i32[1] = *v28;
  xlattice000_4.m128_i32[1] = v28[1];
  v29 = v28[2];
  v30 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[5] + perm_b[(unsigned __int8)(v25 + 1)] + 1)]];
  xlattice010_4.m128_i32[1] = v29;
  xlattice001_4.m128_i32[1] = *v30;
  xlattice110_4.m128_i32[1] = v30[1];
  zlattice110_4.m128_f32[2] = (double)y_idx_4.m128_u8[8] * 0.00390625;
  xlattice100_4.m128_i32[1] = v30[2];
  zlattice100_4.m128_f32[2] = (double)z_idx_4.m128_u8[8] * 0.00390625;
  v31 = z_idx_4.m128_i8[9] + perm_a[y_idx_4.m128_u8[9]];
  zlattice111_4.m128_f32[2] = (double)v72.m128_u8[8] * 0.00390625;
  v32 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + LOBYTE(perm_b[v31]))]];
  ylattice010_4.m128_i32[2] = *v32;
  x_idx_4.m128_i32[2] = v32[1];
  v33 = v32[2];
  v34 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + LOBYTE(perm_b[v31]) + 1)]];
  ylattice100_4.m128_i32[2] = v33;
  ylattice000_4.m128_i32[2] = *v34;
  ylattice110_4.m128_i32[2] = v34[1];
  v35 = v34[2];
  v36 = v72.m128_i8[9] + perm_b[(unsigned __int8)(v31 + 1)];
  v37 = (int *)&s_randomGradients[3 * perm_c[v36]];
  xfrac_4.m128_i32[2] = v35;
  zlattice010_4.m128_i32[2] = *v37;
  xlattice101_4.m128_i32[2] = v37[1];
  v38 = v37[2];
  v39 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v36 + 1)]];
  v40 = perm_a[(unsigned __int8)(y_idx_4.m128_i8[9] + 1)] + z_idx_4.m128_i8[9];
  zfrac_4.m128_i32[2] = v38;
  zlattice000_4.m128_i32[2] = *v39;
  yfrac_4.m128_i32[2] = v39[1];
  xlattice111_4.m128_i32[2] = v39[2];
  v41 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + perm_b[v40])]];
  zlattice011_4.m128_i32[2] = *v41;
  zlattice101_4.m128_i32[2] = v41[1];
  xlattice011_4.m128_i32[2] = v41[2];
  v42 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + perm_b[v40] + 1)]];
  ylattice111_4.m128_i32[2] = *v42;
  zlattice001_4.m128_i32[2] = v42[1];
  v43 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + perm_b[(unsigned __int8)(v40 + 1)])]];
  ylattice101_4.m128_i32[2] = v42[2];
  ylattice011_4.m128_i32[2] = *v43;
  xlattice000_4.m128_i32[2] = v43[1];
  v44 = v43[2];
  v45 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + perm_b[(unsigned __int8)(v40 + 1)] + 1)]];
  xlattice010_4.m128_i32[2] = v44;
  xlattice001_4.m128_i32[2] = *v45;
  xlattice110_4.m128_i32[2] = v45[1];
  zlattice110_4.m128_f32[3] = (double)y_idx_4.m128_u8[12] * 0.00390625;
  zlattice100_4.m128_f32[3] = (double)z_idx_4.m128_u8[12] * 0.00390625;
  v46 = z_idx_4.m128_i8[13] + perm_a[y_idx_4.m128_u8[13]];
  zlattice111_4.m128_f32[3] = 0.00390625 * (double)v72.m128_u8[12];
  v47 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + LOBYTE(perm_b[v46]))]];
  xlattice100_4.m128_i32[2] = v45[2];
  ylattice010_4.m128_i32[3] = *v47;
  x_idx_4.m128_i32[3] = v47[1];
  v48 = v47[2];
  v49 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + LOBYTE(perm_b[v46]) + 1)]];
  ylattice100_4.m128_i32[3] = v48;
  ylattice000_4.m128_i32[3] = *v49;
  ylattice110_4.m128_i32[3] = v49[1];
  v50 = v72.m128_i8[13] + perm_b[(unsigned __int8)(v46 + 1)];
  xfrac_4.m128_i32[3] = v49[2];
  v51 = (int *)&s_randomGradients[3 * perm_c[v50]];
  zlattice010_4.m128_i32[3] = *v51;
  xlattice101_4.m128_i32[3] = v51[1];
  v52 = perm_a[(unsigned __int8)(y_idx_4.m128_i8[13] + 1)] + z_idx_4.m128_i8[13];
  zfrac_4.m128_i32[3] = v51[2];
  v53 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v50 + 1)]];
  zlattice000_4.m128_i32[3] = *v53;
  yfrac_4.m128_i32[3] = v53[1];
  v54 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + perm_b[v52])]];
  xlattice111_4.m128_i32[3] = v53[2];
  zlattice011_4.m128_i32[3] = *v54;
  zlattice101_4.m128_i32[3] = v54[1];
  v55 = v54[2];
  v56 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + perm_b[v52] + 1)]];
  xlattice011_4.m128_i32[3] = v55;
  ylattice111_4.m128_i32[3] = *v56;
  v57 = (unsigned __int8)(v52 + 1);
  zlattice001_4.m128_i32[3] = v56[1];
  ylattice101_4.m128_i32[3] = v56[2];
  v58 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + perm_b[v57])]];
  ylattice011_4.m128_i32[3] = *v58;
  xlattice000_4.m128_i32[3] = v58[1];
  v59 = v58[2];
  v60 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + perm_b[v57] + 1)]];
  xlattice010_4.m128_i32[3] = v59;
  xlattice001_4.m128_i32[3] = *v60;
  xlattice110_4.m128_i32[3] = v60[1];
  v61 = v60[2];
  xlattice100_4.m128_i32[3] = v61;
  v63 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(zlattice011_4, ylattice010_4), zlattice110_4), ylattice010_4);
  v64 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ylattice111_4, ylattice000_4), zlattice110_4), ylattice000_4);
  v65 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ylattice011_4, zlattice010_4), zlattice110_4), zlattice010_4),
              v63),
            zlattice100_4),
          v63);
  result->x = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice001_4, zlattice000_4), zlattice110_4), zlattice000_4),
                          v64),
                        zlattice100_4),
                      v64),
                    v65),
                  zlattice111_4),
                v65);
  v66 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(zlattice101_4, x_idx_4), zlattice110_4), x_idx_4);
  v67 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(zlattice001_4, ylattice110_4), zlattice110_4), ylattice110_4);
  v68 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice000_4, xlattice101_4), zlattice110_4), xlattice101_4),
              v66),
            zlattice100_4),
          v66);
  v69 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice011_4, ylattice100_4), zlattice110_4), ylattice100_4);
  result->y = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice110_4, yfrac_4), zlattice110_4), yfrac_4),
                          v67),
                        zlattice100_4),
                      v67),
                    v68),
                  zlattice111_4),
                v68);
  v70 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ylattice101_4, xfrac_4), zlattice110_4), xfrac_4);
  v71 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice010_4, zfrac_4), zlattice110_4), zfrac_4), v69),
            zlattice100_4),
          v69);
  result->z = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice100_4, xlattice111_4), zlattice110_4), xlattice111_4),
                          v70),
                        zlattice100_4),
                      v70),
                    v71),
                  zlattice111_4),
                v71);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C5630
// Name: union __m128 NoiseSIMD(class FourVectors const __near &)
// Source: json
//------------------------------------------------------------------------------
__m128 *__cdecl NoiseSIMD(FourVectors *result)
{
  return NoiseSIMD(result: &result->x, x: &result->y, y: &result->z);
}

//------------------------------------------------------------------------------
// Address: 0x104C5650
// Name: class FourVectors DNoiseSIMD(class FourVectors const __near &)
// Source: json
//------------------------------------------------------------------------------
FourVectors *__cdecl DNoiseSIMD(FourVectors *result, const FourVectors *pos)
{
  DNoiseSIMD(result, x: &pos->x, y: &pos->y, z: &pos->z);
  return result;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1040D150
// Name: union __m128 NoiseSIMD(union __m128 const __near &,union __m128 const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
__m128 *__cdecl NoiseSIMD(__m128 *result, const __m128 *x, const __m128 *y)
{
  return (__m128 *)perm_c[(unsigned __int8)(perm_b[(unsigned __int8)(perm_a[(unsigned __int8)(_mm_and_ps(
                                                                                                _mm_add_ps(
                                                                                                  *result,
                                                                                                  Four_MagicNumbers_0),
                                                                                                *(__m128 *)idx_mask).m128_i8[13]
                                                                                            + 1)]
                                                                   + _mm_and_ps(
                                                                       _mm_add_ps(*x, Four_MagicNumbers_0),
                                                                       *(__m128 *)idx_mask).m128_i8[13]
                                                                   + 1)]
                                          + _mm_and_ps(_mm_add_ps(*y, Four_MagicNumbers_0), *(__m128 *)idx_mask).m128_i8[13]
                                          + 1)];
}

//------------------------------------------------------------------------------
// Address: 0x1040D900
// Name: class FourVectors DNoiseSIMD(union __m128 const __near &,union __m128 const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
FourVectors *__cdecl DNoiseSIMD(FourVectors *result, const __m128 *x, const __m128 *y, const __m128 *z)
{
  int v4; // esi
  int v5; // esi
  int v6; // xmm0_4
  float *v7; // esi
  int v8; // xmm0_4
  int *v9; // esi
  unsigned __int8 v10; // di
  int *v11; // esi
  unsigned __int8 v12; // dl
  int *v13; // esi
  int *v14; // ecx
  int v15; // xmm0_4
  int *v16; // ecx
  int v17; // xmm0_4
  int *v18; // eax
  int *v19; // eax
  unsigned __int8 v20; // di
  int *v21; // esi
  int v22; // xmm0_4
  int *v23; // esi
  unsigned __int8 v24; // di
  unsigned __int8 v25; // dl
  int *v26; // ecx
  int *v27; // ecx
  int *v28; // eax
  int v29; // xmm0_4
  int *v30; // eax
  unsigned __int8 v31; // di
  int *v32; // esi
  int v33; // xmm0_4
  int *v34; // esi
  int v35; // xmm0_4
  unsigned __int8 v36; // di
  int *v37; // esi
  int v38; // xmm0_4
  int *v39; // esi
  unsigned __int8 v40; // dl
  int *v41; // ecx
  int *v42; // ecx
  int *v43; // eax
  int v44; // xmm0_4
  int *v45; // eax
  unsigned __int8 v46; // di
  int *v47; // esi
  int v48; // xmm0_4
  int *v49; // esi
  unsigned __int8 v50; // di
  int *v51; // esi
  unsigned __int8 v52; // dl
  int *v53; // esi
  int *v54; // ecx
  int v55; // xmm0_4
  int *v56; // ecx
  int v57; // edx
  int *v58; // eax
  int v59; // xmm0_4
  int *v60; // eax
  int v61; // xmm0_4
  __m128 v63; // xmm2
  __m128 v64; // xmm3
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm1
  __m128 v72; // [esp-Ch] [ebp-1FCh]
  __m128 z_idx_4; // [esp+4h] [ebp-1ECh]
  __m128 y_idx_4; // [esp+14h] [ebp-1DCh]
  __m128 x_idx_4; // [esp+24h] [ebp-1CCh]
  __m128 ylattice000_4; // [esp+34h] [ebp-1BCh]
  __m128 xlattice001_4; // [esp+44h] [ebp-1ACh]
  __m128 xlattice111_4; // [esp+54h] [ebp-19Ch]
  __m128 zlattice011_4; // [esp+64h] [ebp-18Ch]
  __m128 xlattice100_4; // [esp+74h] [ebp-17Ch]
  __m128 zlattice111_4; // [esp+84h] [ebp-16Ch]
  __m128 zfrac_4; // [esp+94h] [ebp-15Ch]
  __m128 zlattice010_4; // [esp+A4h] [ebp-14Ch]
  __m128 xlattice010_4; // [esp+B4h] [ebp-13Ch]
  __m128 zlattice110_4; // [esp+C4h] [ebp-12Ch]
  __m128 xfrac_4; // [esp+D4h] [ebp-11Ch]
  __m128 zlattice001_4; // [esp+E4h] [ebp-10Ch]
  __m128 ylattice101_4; // [esp+F4h] [ebp-FCh]
  __m128 zlattice101_4; // [esp+104h] [ebp-ECh]
  __m128 ylattice100_4; // [esp+114h] [ebp-DCh]
  __m128 zlattice000_4; // [esp+124h] [ebp-CCh]
  __m128 xlattice011_4; // [esp+134h] [ebp-BCh]
  __m128 zlattice100_4; // [esp+144h] [ebp-ACh]
  __m128 yfrac_4; // [esp+154h] [ebp-9Ch]
  __m128 ylattice011_4; // [esp+164h] [ebp-8Ch]
  __m128 xlattice110_4; // [esp+174h] [ebp-7Ch]
  __m128 ylattice111_4; // [esp+184h] [ebp-6Ch]
  __m128 xlattice101_4; // [esp+194h] [ebp-5Ch]
  __m128 ylattice010_4; // [esp+1A4h] [ebp-4Ch]
  __m128 xlattice000_4; // [esp+1B4h] [ebp-3Ch]
  __m128 ylattice110_4; // [esp+1C4h] [ebp-2Ch]
  unsigned int v102; // [esp+1E0h] [ebp-10h]

  y_idx_4 = _mm_and_ps(_mm_add_ps(*x, Four_MagicNumbers_0), *(__m128 *)idx_mask);
  z_idx_4 = _mm_and_ps(_mm_add_ps(*y, Four_MagicNumbers_0), *(__m128 *)idx_mask);
  v72 = _mm_and_ps(_mm_add_ps(*z, Four_MagicNumbers_0), *(__m128 *)idx_mask);
  zlattice110_4.m128_f32[0] = (double)y_idx_4.m128_u8[0] * 0.00390625;
  v4 = perm_b[(unsigned __int8)(z_idx_4.m128_i8[1] + perm_a[y_idx_4.m128_u8[1]])];
  zlattice100_4.m128_f32[0] = (double)z_idx_4.m128_u8[0] * 0.00390625;
  v102 = ((unsigned int)v72.m128_i32[0] >> 8) + v4;
  zlattice111_4.m128_f32[0] = (double)v72.m128_u8[0] * 0.00390625;
  v5 = 3 * perm_c[(unsigned __int8)(v72.m128_i8[1] + v4)];
  v6 = LODWORD(s_randomGradients[v5]);
  v7 = &s_randomGradients[v5];
  ylattice010_4.m128_i32[0] = v6;
  x_idx_4.m128_f32[0] = v7[1];
  v8 = *((_DWORD *)v7 + 2);
  v9 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v102 + 1)]];
  ylattice100_4.m128_i32[0] = v8;
  ylattice000_4.m128_i32[0] = *v9;
  ylattice110_4.m128_i32[0] = v9[1];
  v10 = v72.m128_i8[1] + perm_b[(unsigned __int8)(z_idx_4.m128_i8[1] + perm_a[y_idx_4.m128_u8[1]] + 1)];
  xfrac_4.m128_i32[0] = v9[2];
  v11 = (int *)&s_randomGradients[3 * perm_c[v10]];
  zlattice010_4.m128_i32[0] = *v11;
  xlattice101_4.m128_i32[0] = v11[1];
  v12 = perm_a[(unsigned __int8)(y_idx_4.m128_i8[1] + 1)] + z_idx_4.m128_i8[1];
  zfrac_4.m128_i32[0] = v11[2];
  v13 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v10 + 1)]];
  zlattice000_4.m128_i32[0] = *v13;
  yfrac_4.m128_i32[0] = v13[1];
  v14 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[1] + perm_b[v12])]];
  xlattice111_4.m128_i32[0] = v13[2];
  zlattice011_4.m128_i32[0] = *v14;
  zlattice101_4.m128_i32[0] = v14[1];
  v15 = v14[2];
  v16 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[1] + perm_b[v12] + 1)]];
  xlattice011_4.m128_i32[0] = v15;
  ylattice111_4.m128_i32[0] = *v16;
  zlattice001_4.m128_i32[0] = v16[1];
  v17 = v16[2];
  LOBYTE(v16) = v72.m128_i8[1] + perm_b[(unsigned __int8)(v12 + 1)];
  ylattice101_4.m128_i32[0] = v17;
  v18 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)v16]];
  ylattice011_4.m128_i32[0] = *v18;
  xlattice000_4.m128_i32[0] = v18[1];
  xlattice010_4.m128_i32[0] = v18[2];
  v19 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)((_BYTE)v16 + 1)]];
  xlattice001_4.m128_i32[0] = *v19;
  xlattice110_4.m128_i32[0] = v19[1];
  zlattice110_4.m128_f32[1] = (double)y_idx_4.m128_u8[4] * 0.00390625;
  v20 = z_idx_4.m128_i8[5] + perm_a[y_idx_4.m128_u8[5]];
  zlattice100_4.m128_f32[1] = (double)z_idx_4.m128_u8[4] * 0.00390625;
  zlattice111_4.m128_f32[1] = (double)v72.m128_u8[4] * 0.00390625;
  v21 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[5] + LOBYTE(perm_b[v20]))]];
  xlattice100_4.m128_i32[0] = v19[2];
  ylattice010_4.m128_i32[1] = *v21;
  x_idx_4.m128_i32[1] = v21[1];
  v22 = v21[2];
  v23 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[5] + LOBYTE(perm_b[v20]) + 1)]];
  ylattice100_4.m128_i32[1] = v22;
  ylattice000_4.m128_i32[1] = *v23;
  v24 = v72.m128_i8[5] + perm_b[(unsigned __int8)(v20 + 1)];
  ylattice110_4.m128_i32[1] = v23[1];
  xfrac_4.m128_i32[1] = v23[2];
  zlattice010_4.m128_f32[1] = s_randomGradients[3 * perm_c[v24]];
  xlattice101_4.m128_f32[1] = s_randomGradients[3 * perm_c[v24] + 1];
  v25 = perm_a[(unsigned __int8)(y_idx_4.m128_i8[5] + 1)] + z_idx_4.m128_i8[5];
  zfrac_4.m128_f32[1] = s_randomGradients[3 * perm_c[v24] + 2];
  zlattice000_4.m128_f32[1] = s_randomGradients[3 * perm_c[(unsigned __int8)(v24 + 1)]];
  yfrac_4.m128_f32[1] = s_randomGradients[3 * perm_c[(unsigned __int8)(v24 + 1)] + 1];
  LOBYTE(v23) = v72.m128_i8[5] + perm_b[v25];
  xlattice111_4.m128_f32[1] = s_randomGradients[3 * perm_c[(unsigned __int8)(v24 + 1)] + 2];
  v26 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)v23]];
  zlattice011_4.m128_i32[1] = *v26;
  zlattice101_4.m128_i32[1] = v26[1];
  xlattice011_4.m128_i32[1] = v26[2];
  v27 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)((_BYTE)v23 + 1)]];
  ylattice111_4.m128_i32[1] = *v27;
  zlattice001_4.m128_i32[1] = v27[1];
  v28 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[5] + perm_b[(unsigned __int8)(v25 + 1)])]];
  ylattice101_4.m128_i32[1] = v27[2];
  ylattice011_4.m128_i32[1] = *v28;
  xlattice000_4.m128_i32[1] = v28[1];
  v29 = v28[2];
  v30 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[5] + perm_b[(unsigned __int8)(v25 + 1)] + 1)]];
  xlattice010_4.m128_i32[1] = v29;
  xlattice001_4.m128_i32[1] = *v30;
  xlattice110_4.m128_i32[1] = v30[1];
  zlattice110_4.m128_f32[2] = (double)y_idx_4.m128_u8[8] * 0.00390625;
  xlattice100_4.m128_i32[1] = v30[2];
  zlattice100_4.m128_f32[2] = (double)z_idx_4.m128_u8[8] * 0.00390625;
  v31 = z_idx_4.m128_i8[9] + perm_a[y_idx_4.m128_u8[9]];
  zlattice111_4.m128_f32[2] = (double)v72.m128_u8[8] * 0.00390625;
  v32 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + LOBYTE(perm_b[v31]))]];
  ylattice010_4.m128_i32[2] = *v32;
  x_idx_4.m128_i32[2] = v32[1];
  v33 = v32[2];
  v34 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + LOBYTE(perm_b[v31]) + 1)]];
  ylattice100_4.m128_i32[2] = v33;
  ylattice000_4.m128_i32[2] = *v34;
  ylattice110_4.m128_i32[2] = v34[1];
  v35 = v34[2];
  v36 = v72.m128_i8[9] + perm_b[(unsigned __int8)(v31 + 1)];
  v37 = (int *)&s_randomGradients[3 * perm_c[v36]];
  xfrac_4.m128_i32[2] = v35;
  zlattice010_4.m128_i32[2] = *v37;
  xlattice101_4.m128_i32[2] = v37[1];
  v38 = v37[2];
  v39 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v36 + 1)]];
  v40 = perm_a[(unsigned __int8)(y_idx_4.m128_i8[9] + 1)] + z_idx_4.m128_i8[9];
  zfrac_4.m128_i32[2] = v38;
  zlattice000_4.m128_i32[2] = *v39;
  yfrac_4.m128_i32[2] = v39[1];
  xlattice111_4.m128_i32[2] = v39[2];
  v41 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + perm_b[v40])]];
  zlattice011_4.m128_i32[2] = *v41;
  zlattice101_4.m128_i32[2] = v41[1];
  xlattice011_4.m128_i32[2] = v41[2];
  v42 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + perm_b[v40] + 1)]];
  ylattice111_4.m128_i32[2] = *v42;
  zlattice001_4.m128_i32[2] = v42[1];
  v43 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + perm_b[(unsigned __int8)(v40 + 1)])]];
  ylattice101_4.m128_i32[2] = v42[2];
  ylattice011_4.m128_i32[2] = *v43;
  xlattice000_4.m128_i32[2] = v43[1];
  v44 = v43[2];
  v45 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[9] + perm_b[(unsigned __int8)(v40 + 1)] + 1)]];
  xlattice010_4.m128_i32[2] = v44;
  xlattice001_4.m128_i32[2] = *v45;
  xlattice110_4.m128_i32[2] = v45[1];
  zlattice110_4.m128_f32[3] = (double)y_idx_4.m128_u8[12] * 0.00390625;
  zlattice100_4.m128_f32[3] = (double)z_idx_4.m128_u8[12] * 0.00390625;
  v46 = z_idx_4.m128_i8[13] + perm_a[y_idx_4.m128_u8[13]];
  zlattice111_4.m128_f32[3] = 0.00390625 * (double)v72.m128_u8[12];
  v47 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + LOBYTE(perm_b[v46]))]];
  xlattice100_4.m128_i32[2] = v45[2];
  ylattice010_4.m128_i32[3] = *v47;
  x_idx_4.m128_i32[3] = v47[1];
  v48 = v47[2];
  v49 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + LOBYTE(perm_b[v46]) + 1)]];
  ylattice100_4.m128_i32[3] = v48;
  ylattice000_4.m128_i32[3] = *v49;
  ylattice110_4.m128_i32[3] = v49[1];
  v50 = v72.m128_i8[13] + perm_b[(unsigned __int8)(v46 + 1)];
  xfrac_4.m128_i32[3] = v49[2];
  v51 = (int *)&s_randomGradients[3 * perm_c[v50]];
  zlattice010_4.m128_i32[3] = *v51;
  xlattice101_4.m128_i32[3] = v51[1];
  v52 = perm_a[(unsigned __int8)(y_idx_4.m128_i8[13] + 1)] + z_idx_4.m128_i8[13];
  zfrac_4.m128_i32[3] = v51[2];
  v53 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v50 + 1)]];
  zlattice000_4.m128_i32[3] = *v53;
  yfrac_4.m128_i32[3] = v53[1];
  v54 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + perm_b[v52])]];
  xlattice111_4.m128_i32[3] = v53[2];
  zlattice011_4.m128_i32[3] = *v54;
  zlattice101_4.m128_i32[3] = v54[1];
  v55 = v54[2];
  v56 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + perm_b[v52] + 1)]];
  xlattice011_4.m128_i32[3] = v55;
  ylattice111_4.m128_i32[3] = *v56;
  v57 = (unsigned __int8)(v52 + 1);
  zlattice001_4.m128_i32[3] = v56[1];
  ylattice101_4.m128_i32[3] = v56[2];
  v58 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + perm_b[v57])]];
  ylattice011_4.m128_i32[3] = *v58;
  xlattice000_4.m128_i32[3] = v58[1];
  v59 = v58[2];
  v60 = (int *)&s_randomGradients[3 * perm_c[(unsigned __int8)(v72.m128_i8[13] + perm_b[v57] + 1)]];
  xlattice010_4.m128_i32[3] = v59;
  xlattice001_4.m128_i32[3] = *v60;
  xlattice110_4.m128_i32[3] = v60[1];
  v61 = v60[2];
  xlattice100_4.m128_i32[3] = v61;
  v63 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(zlattice011_4, ylattice010_4), zlattice110_4), ylattice010_4);
  v64 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ylattice111_4, ylattice000_4), zlattice110_4), ylattice000_4);
  v65 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ylattice011_4, zlattice010_4), zlattice110_4), zlattice010_4),
              v63),
            zlattice100_4),
          v63);
  result->x = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice001_4, zlattice000_4), zlattice110_4), zlattice000_4),
                          v64),
                        zlattice100_4),
                      v64),
                    v65),
                  zlattice111_4),
                v65);
  v66 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(zlattice101_4, x_idx_4), zlattice110_4), x_idx_4);
  v67 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(zlattice001_4, ylattice110_4), zlattice110_4), ylattice110_4);
  v68 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice000_4, xlattice101_4), zlattice110_4), xlattice101_4),
              v66),
            zlattice100_4),
          v66);
  v69 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice011_4, ylattice100_4), zlattice110_4), ylattice100_4);
  result->y = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice110_4, yfrac_4), zlattice110_4), yfrac_4),
                          v67),
                        zlattice100_4),
                      v67),
                    v68),
                  zlattice111_4),
                v68);
  v70 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ylattice101_4, xfrac_4), zlattice110_4), xfrac_4);
  v71 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice010_4, zfrac_4), zlattice110_4), zfrac_4), v69),
            zlattice100_4),
          v69);
  result->z = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(xlattice100_4, xlattice111_4), zlattice110_4), xlattice111_4),
                          v70),
                        zlattice100_4),
                      v70),
                    v71),
                  zlattice111_4),
                v71);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040E650
// Name: union __m128 NoiseSIMD(class FourVectors const __near &)
// Source: json
//------------------------------------------------------------------------------
__m128 *__cdecl NoiseSIMD(FourVectors *result)
{
  return NoiseSIMD(result: &result->x, x: &result->y, y: &result->z);
}

//------------------------------------------------------------------------------
// Address: 0x1040E670
// Name: class FourVectors DNoiseSIMD(class FourVectors const __near &)
// Source: json
//------------------------------------------------------------------------------
FourVectors *__cdecl DNoiseSIMD(FourVectors *result, const FourVectors *pos)
{
  DNoiseSIMD(result, x: &pos->x, y: &pos->y, z: &pos->z);
  return result;
}

} // namespace client
