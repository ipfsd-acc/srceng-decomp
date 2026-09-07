// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/r_studiosubd_patches.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10046140
// Name: void set_ShowACCGeometryTangents(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_ShowACCGeometryTangents(bool v)
{
  sShowACCGeometryTangents = v;
}

//------------------------------------------------------------------------------
// Address: 0x10046150
// Name: void set_UseCornerTangents(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_UseCornerTangents(bool v)
{
  sUseCornerTangents = v;
}

//------------------------------------------------------------------------------
// Address: 0x10046160
// Name: ComputeCatmullClarkLimitTanStencil
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeCatmullClarkLimitTanStencil(
        __m128 *stencilBuffer1@<eax>,
        int a2@<ebp>,
        char a3,
        char a4,
        int a5,
        __m128 *a6)
{
  int v7; // eax
  int v8; // edx
  __m128 *v9; // eax
  double v10; // xmm0_8
  float v11; // xmm1_4
  __m128 *v12; // edi
  float v13; // xmm0_4
  __m128 v14; // xmm1
  int v15; // esi
  float v16; // xmm0_4
  __m128 v17; // xmm1
  float v18; // xmm0_4
  __m128 v19; // xmm1
  float v20; // xmm0_4
  __m128 v21; // xmm1
  int v22; // edi
  float v23; // xmm0_4
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  float v26; // xmm0_4
  __m128 v27; // xmm2
  float v28; // xmm3_4
  __m128 v29; // xmm1
  float v30; // xmm0_4
  int v31; // edi
  float v32; // xmm0_4
  __m128 v33; // xmm2
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __m128 v37; // xmm4
  __m128 v38; // xmm0
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  int v41; // eax
  __m128 v42; // xmm0
  __m128 v43; // xmm0
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 v46; // xmm0
  int v47; // edi
  double v48; // xmm0_8
  float v49; // xmm1_4
  __m128 *v50; // eax
  __m128 v51; // xmm1
  int v52; // esi
  float v53; // xmm0_4
  __m128 v54; // xmm1
  float v55; // xmm0_4
  __m128 v56; // xmm1
  __m128 v57; // xmm0
  __m128 v58; // xmm0
  double v59; // [esp-44h] [ebp-6Ch]
  double v60; // [esp-44h] [ebp-6Ch]
  double v61; // [esp-3Ch] [ebp-64h]
  double v62; // [esp-34h] [ebp-5Ch]
  int v63; // [esp-30h] [ebp-58h]
  int v64; // [esp-24h] [ebp-4Ch]
  double v65; // [esp-24h] [ebp-4Ch]
  float v66; // [esp-20h] [ebp-48h]
  float v67; // [esp-Ch] [ebp-34h]
  float v68; // [esp-Ch] [ebp-34h]
  float v69; // [esp-Ch] [ebp-34h]
  float v70; // [esp-8h] [ebp-30h]
  float v71; // [esp-8h] [ebp-30h]
  float v72; // [esp-8h] [ebp-30h]
  __m128 *v73; // [esp-4h] [ebp-2Ch]
  int v74; // [esp-4h] [ebp-2Ch]
  __m128 *v75; // [esp-4h] [ebp-2Ch]
  long double v76; // [esp+18h] [ebp-10h]
  long double v77; // [esp+18h] [ebp-10h]
  long double v78; // [esp+18h] [ebp-10h]
  long double v79; // [esp+18h] [ebp-10h]
  long double v80; // [esp+18h] [ebp-10h]
  long double v81; // [esp+18h] [ebp-10h]
  long double v82; // [esp+18h] [ebp-10h]
  long double v83; // [esp+18h] [ebp-10h]
  long double v84; // [esp+18h] [ebp-10h]
  long double v85; // [esp+18h] [ebp-10h]

  HIDWORD(v76) = a2;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitTanStencil",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  v7 = a5;
  v8 = 2 * a5;
  if ( 2 * a5 > 0 )
  {
    v9 = a6;
    do
    {
      *(__m128 *)((char *)v9 + (char *)stencilBuffer1 - (char *)a6) = Four_Zeros;
      *v9++ = Four_Zeros;
      --v8;
    }
    while ( v8 != 0 );
    v7 = a5;
  }
  if ( a3 != 0 )
  {
    if ( a4 != 0 )
    {
      if ( v7 > 2 )
      {
        v22 = v7 - 1;
        v68 = (float)(v7 - 1);
        v63 = v7 - 1;
        __libm_sse2_sin(x: v76);
        v23 = 0.0 / v68;
        *(float *)&v81 = v23;
        v24 = 0;
        v24.m128_f32[0] = v23 * 0.5;
        stencilBuffer1[1] = _mm_add_ps(_mm_shuffle_ps(v24, v24, 0), stencilBuffer1[1]);
        v25 = 0;
        v25.m128_f32[0] = v23 * -0.5;
        *stencilBuffer1 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 0), *stencilBuffer1);
        __libm_sse2_sin(x: v81);
        v26 = (double)v22 * 3.14159265 / v68;
        v27 = 0;
        v27.m128_f32[0] = v26 * 0.5;
        v28 = v26 + *(float *)&v82;
        stencilBuffer1[2 * a5 - 1] = _mm_add_ps(_mm_shuffle_ps(v27, v27, 0), stencilBuffer1[2 * a5 - 1]);
        v29 = 0;
        v29.m128_f32[0] = v26 * -0.5;
        *(float *)&v82 = v26 + *(float *)&v82;
        *stencilBuffer1 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 0), *stencilBuffer1);
        v74 = 1;
        if ( v22 > 1 )
        {
          v30 = (float)a5 * 2.0;
          v71 = 1.0 / (float)(v30 + 10.0);
          v66 = (float)(v30 * v71) - 1.0;
          v31 = 2;
          do
          {
            __libm_sse2_sin(x: v82);
            v32 = (double)v74 * 3.14159265 / v68;
            v28 = v32 + *(float *)&v82;
            v33 = 0;
            v33.m128_f32[0] = v66 * v32;
            *stencilBuffer1 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 0), *stencilBuffer1);
            v34 = 0;
            v34.m128_f32[0] = (float)(v32 * 2.0) * v71;
            v35 = v34;
            stencilBuffer1[v31 - 1] = _mm_add_ps(_mm_shuffle_ps(v34, v34, 0), stencilBuffer1[v31 - 1]);
            v36 = 0;
            v36.m128_f32[0] = v71 * v32;
            v37 = 0;
            v37.m128_f32[0] = (float)(v32 * 4.0) * v71;
            v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 0), stencilBuffer1[v31 + 1]);
            v39 = _mm_add_ps(_mm_shuffle_ps(v36, v36, 0), stencilBuffer1[v31 + 2]);
            v40 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 0), stencilBuffer1[v31 + 3]);
            stencilBuffer1[v31] = _mm_add_ps(_mm_shuffle_ps(v36, v36, 0), stencilBuffer1[v31]);
            stencilBuffer1[v31 + 1] = v38;
            stencilBuffer1[v31 + 2] = v39;
            stencilBuffer1[v31 + 3] = v40;
            v31 += 2;
            *(float *)&v82 = v28;
            ++v74;
          }
          while ( v74 < v63 );
        }
        v41 = 2 * a5;
        v42 = 0;
        v42.m128_f32[0] = v28;
        v43 = _mm_shuffle_ps(v42, v42, 0);
        if ( 2 * a5 > 0 )
        {
          do
          {
            *stencilBuffer1 = _mm_div_ps(*stencilBuffer1, v43);
            ++stencilBuffer1;
            --v41;
          }
          while ( v41 != 0 );
        }
      }
    }
    else if ( v7 == 2 )
    {
      stencilBuffer1[1] = _mm_shuffle_ps((__m128)0x3F000000u, (__m128)0x3F000000u, 0);
      v44 = _mm_shuffle_ps((__m128)0xBF000000, (__m128)0xBF000000, 0);
      stencilBuffer1[3] = v44;
      a6[1] = v44;
      a6[3] = _mm_shuffle_ps((__m128)0x3F000000u, (__m128)0x3F000000u, 0);
      *stencilBuffer1 = _mm_add_ps(_mm_shuffle_ps((__m128)0xB90BCF65, (__m128)0xB90BCF65, 0), *stencilBuffer1);
      stencilBuffer1[1] = _mm_add_ps(_mm_shuffle_ps((__m128)0x3851B717u, (__m128)0x3851B717u, 0), stencilBuffer1[1]);
      stencilBuffer1[2] = _mm_add_ps(_mm_shuffle_ps((__m128)0x380BCF65u, (__m128)0x380BCF65u, 0), stencilBuffer1[2]);
      stencilBuffer1[3] = _mm_add_ps(_mm_shuffle_ps((__m128)0x3851B717u, (__m128)0x3851B717u, 0), stencilBuffer1[3]);
      *a6 = _mm_add_ps(_mm_shuffle_ps((__m128)0xB90BCF65, (__m128)0xB90BCF65, 0), *a6);
      v45 = _mm_add_ps(_mm_shuffle_ps((__m128)0x380BCF65u, (__m128)0x380BCF65u, 0), a6[2]);
      v46 = _mm_add_ps(_mm_shuffle_ps((__m128)0x3851B717u, (__m128)0x3851B717u, 0), a6[3]);
      a6[1] = _mm_add_ps(_mm_shuffle_ps((__m128)0x3851B717u, (__m128)0x3851B717u, 0), a6[1]);
      a6[2] = v45;
      a6[3] = v46;
    }
    else
    {
      v47 = v7 - 1;
      v48 = 3.14159265 / (double)(v7 - 1);
      v65 = (double)(v7 - 1);
      __libm_sse2_cos(x: v76);
      v49 = v48;
      v72 = v49;
      stencilBuffer1[1] = _mm_shuffle_ps((__m128)0x3F000000u, (__m128)0x3F000000u, 0);
      stencilBuffer1[2 * v47 + 1] = _mm_shuffle_ps((__m128)0xBF000000, (__m128)0xBF000000, 0);
      v69 = (float)((float)v47 * 3.0) + v49;
      __libm_sse2_sin(x: v83);
      v50 = a6;
      *(float *)&v48 = v48;
      v51 = 0;
      v51.m128_f32[0] = (float)(*(float *)&v48 * -4.0) / v69;
      v52 = 0;
      *a6 = _mm_shuffle_ps(v51, v51, 0);
      if ( v47 > 0 )
      {
        v75 = a6 + 2;
        do
        {
          __libm_sse2_sin(x: v84);
          v60 = (double)v52 * 3.14159265 / v65;
          v53 = v60 * 4.0 / (float)((float)(3 * v47) + v72);
          v54 = 0;
          v54.m128_f32[0] = v53;
          v75[-1] = _mm_shuffle_ps(v54, v54, 0);
          ++v52;
          __libm_sse2_sin(x: v85);
          v55 = ((double)v52 * 3.14159265 / v65 + v60) / v69;
          v56 = 0;
          v56.m128_f32[0] = v55;
          *v75 = _mm_shuffle_ps(v56, v56, 0);
          v75 += 2;
        }
        while ( v52 < v47 );
        v50 = a6;
      }
      v57 = 0;
      v57.m128_i32[0] = COERCE_UNSIGNED_INT(
                          (float)(fsqrt(v72 + 1.0) * (float)((float)(v72 * 2.0) + 1.0))
                        / (float)(fsqrt(1.0 - v72) * (float)((float)(3 * v47) + v72)))
                      ^ _mask__NegFloat_;
      v58 = _mm_shuffle_ps(v57, v57, 0);
      v50[2 * v47 + 1] = v58;
      v50[1] = v58;
    }
  }
  else
  {
    v61 = (double)v7;
    v10 = 3.14159265 / (double)v7;
    __libm_sse2_cos(x: v76);
    v11 = v10 * v10 + 4.0;
    v67 = 1.0 / (float)(fsqrt(v11) * (float)a5);
    *(float *)&v10 = v67 * v10 + (float)(1.0 / (float)a5);
    v70 = *(float *)&v10;
    LODWORD(v77) = 0;
    if ( a5 > 0 )
    {
      v73 = a6 + 1;
      v12 = stencilBuffer1 + 2;
      v64 = (char *)a6 - (char *)stencilBuffer1;
      do
      {
        v62 = (double)SLODWORD(v77) * 6.2831853;
        __libm_sse2_cos(x: v77);
        v13 = v62 / v61 * v70;
        v14 = 0;
        v14.m128_f32[0] = v13;
        v12[-1] = _mm_shuffle_ps(v14, v14, 0);
        __libm_sse2_cos(x: v78);
        v15 = LODWORD(v79);
        v16 = (v62 + 3.14159265) / v61 * v67;
        v17 = 0;
        v17.m128_f32[0] = v16;
        *v12 = _mm_shuffle_ps(v17, v17, 0);
        v59 = (double)((LODWORD(v79) - 1) % a5) * 6.2831853;
        __libm_sse2_cos(x: v79);
        v18 = v59 / v61 * v70;
        v19 = 0;
        v19.m128_f32[0] = v18;
        *v73 = _mm_shuffle_ps(v19, v19, 0);
        __libm_sse2_cos(x: v80);
        v73 += 2;
        v20 = (v59 + 3.14159265) / v61 * v67;
        v21 = 0;
        v21.m128_f32[0] = v20;
        *(__m128 *)((char *)v12 + v64) = _mm_shuffle_ps(v21, v21, 0);
        v12 += 2;
        LODWORD(v77) = v15 + 1;
      }
      while ( v15 + 1 < a5 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100468A0
// Name: ComputeACCEdgePosStencils
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeACCEdgePosStencils(
        __m128 *stencilBuffer1@<edi>,
        __m128 *stencilBuffer2@<esi>,
        unsigned __int8 boundary,
        unsigned __int8 corner,
        int n)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm2

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePosStencils",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  *stencilBuffer1 = Four_Zeros;
  *stencilBuffer2 = Four_Zeros;
  stencilBuffer1[1] = Four_Zeros;
  stencilBuffer2[1] = Four_Zeros;
  stencilBuffer1[2] = Four_Zeros;
  stencilBuffer2[2] = Four_Zeros;
  stencilBuffer1[3] = Four_Zeros;
  stencilBuffer2[3] = Four_Zeros;
  stencilBuffer1[4] = Four_Zeros;
  stencilBuffer2[4] = Four_Zeros;
  stencilBuffer1[5] = Four_Zeros;
  stencilBuffer2[5] = Four_Zeros;
  if ( boundary != 0 )
  {
    *stencilBuffer1 = _mm_shuffle_ps((__m128)0x3F2AAAABu, (__m128)0x3F2AAAABu, 0);
    v12 = _mm_shuffle_ps((__m128)0x3EAAAAABu, (__m128)0x3EAAAAABu, 0);
    *stencilBuffer2 = v12;
    stencilBuffer1[3] = v12;
    stencilBuffer2[3] = _mm_shuffle_ps((__m128)0x3F2AAAABu, (__m128)0x3F2AAAABu, 0);
  }
  else
  {
    v5 = (float)n * 2.0;
    v6 = 1.0 / (float)(v5 + 10.0);
    v7 = 0;
    v7.m128_f32[0] = v5 * v6;
    *stencilBuffer1 = _mm_shuffle_ps(v7, v7, 0);
    v8 = 0;
    v9 = 0;
    v9.m128_f32[0] = v6 * 4.0;
    *stencilBuffer2 = _mm_shuffle_ps(v9, v9, 0);
    v8.m128_f32[0] = v6 * 2.0;
    v10 = v8;
    stencilBuffer1[1] = _mm_shuffle_ps(v8, v8, 0);
    v11 = 0;
    v11.m128_f32[0] = v6;
    stencilBuffer2[1] = _mm_shuffle_ps(v11, v11, 0);
    stencilBuffer1[2] = _mm_shuffle_ps(v11, v11, 0);
    stencilBuffer2[2] = _mm_shuffle_ps(v10, v10, 0);
    stencilBuffer1[3] = _mm_shuffle_ps(v9, v9, 0);
    stencilBuffer2[3] = _mm_shuffle_ps(v7, v7, 0);
    stencilBuffer1[4] = _mm_shuffle_ps(v11, v11, 0);
    stencilBuffer2[4] = _mm_shuffle_ps(v10, v10, 0);
    stencilBuffer1[5] = _mm_shuffle_ps(v10, v10, 0);
    stencilBuffer2[5] = _mm_shuffle_ps(v11, v11, 0);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10046A70
// Name: ComputeACCSinCosPITables
// Source: json
//------------------------------------------------------------------------------
int *ComputeACCSinCosPITables()
{
  int v0; // edi
  __m128 v1; // xmm2
  int v2; // ecx
  __m128 v3; // xmm1
  int v4; // esi
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  int *result; // eax
  __m128 v8; // [esp-Ch] [ebp-3Ch]

  v0 = 0;
  v1 = _mm_shuffle_ps((__m128)0x40490FDBu, (__m128)0x40490FDBu, 0);
  v2 = 0;
  do
  {
    v3 = 0;
    v3.m128_f32[0] = (float)v0;
    v4 = 0;
    v5 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v1);
    do
    {
      v6 = 0;
      v6.m128_f32[0] = (float)v4;
      v8 = _mm_div_ps(v5, _mm_shuffle_ps(v6, v6, 0));
      sCCCosPI[0][v2].m128_f32[0] = cos(v8.m128_f32[0]);
      sCCSinPI[0][v2].m128_f32[0] = sin(v8.m128_f32[0]);
      sCCCosPI[0][v2].m128_f32[1] = cos(v8.m128_f32[1]);
      sCCSinPI[0][v2].m128_f32[1] = sin(v8.m128_f32[1]);
      sCCCosPI[0][v2].m128_f32[2] = cos(v8.m128_f32[2]);
      sCCSinPI[0][v2].m128_f32[2] = sin(v8.m128_f32[2]);
      result = &sCCSinPI[0][v2].m128_i32[3];
      sCCCosPI[0][v2].m128_f32[3] = cos(v8.m128_f32[3]);
      sCCSinPI[0][v2].m128_f32[3] = sin(v8.m128_f32[3]);
      ++v4;
      ++v2;
    }
    while ( v4 < 19 );
    ++v0;
  }
  while ( v2 < 722 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10046BC0
// Name: void FillTables(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall FillTables(int a1@<ebp>)
{
  __m128 v1; // xmm0
  int v2; // ecx
  __m128 *v3; // eax
  __m128 v4; // xmm1
  int v5; // eax
  int v6; // ecx
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  int v9; // edi
  __m128 *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm0_4
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 *v19; // eax
  int v20; // edi
  float v21; // xmm1_4
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  __m128 v29; // xmm1
  int v30; // ecx
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // [esp-B0h] [ebp-BCh]
  __m128 v36; // [esp-A0h] [ebp-ACh]
  __m128 v37; // [esp-90h] [ebp-9Ch]
  __m128 v38; // [esp-80h] [ebp-8Ch]
  float v39; // [esp-68h] [ebp-74h]
  float v40; // [esp-64h] [ebp-70h]
  int v41; // [esp-60h] [ebp-6Ch]
  int v42; // [esp-50h] [ebp-5Ch]
  int v43; // [esp-40h] [ebp-4Ch]
  int v44; // [esp-24h] [ebp-30h]
  __m128 *v45; // [esp-20h] [ebp-2Ch]
  int v46; // [esp-8h] [ebp-14h]
  int v47; // [esp-4h] [ebp-10h]
  _DWORD v48[2]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v48[0] = a1;
  v48[1] = retaddr;
  if ( !sTableInited )
  {
    Four_TwoPI = _mm_shuffle_ps((__m128)0x40C90FDBu, (__m128)0x40C90FDBu, 0);
    Four_Tens = _mm_shuffle_ps((__m128)0x41200000u, (__m128)0x41200000u, 0);
    v1 = 0;
    v1.m128_f32[0] = 5.0;
    Four_Fives = _mm_shuffle_ps(v1, v1, 0);
    Four_NegativeThirds = _mm_shuffle_ps((__m128)0xBEAAAAAB, (__m128)0xBEAAAAAB, 0);
    v2 = 0;
    v3 = Four_N;
    do
    {
      v4 = 0;
      v4.m128_f32[0] = (float)v2;
      *v3++ = _mm_shuffle_ps(v4, v4, 0);
      ++v2;
    }
    while ( (int)v3 < (int)sCCCosPI[0] );
    v5 = 0;
    v6 = 0;
    do
    {
      v7 = 0;
      v7.m128_f32[0] = (float)v5;
      Four_Valence[v6] = _mm_shuffle_ps(v7, v7, 0);
      v8 = 0;
      v8.m128_f32[0] = (float)v5 + 5.0;
      Four_ValencePlus5[v6] = _mm_shuffle_ps(v8, v8, 0);
      Valence_MinusOne[v5] = (float)(v5 - 1);
      ++v5;
      ++v6;
    }
    while ( v5 < 19 );
    v36 = (__m128)0x3E2AAAABu;
    v35 = _mm_shuffle_ps((__m128)0x3E2AAAABu, (__m128)0x3E2AAAABu, 0);
    v9 = 0;
    v10 = sPosCornerStencil[0];
    v47 = 0;
    v43 = 0;
    v44 = 0;
    v45 = sPosCornerStencil[0];
    v42 = 0;
    v46 = 0;
    while ( 1 )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeCatmullClarkLimitPosStencil",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      if ( v44 > 0 )
      {
        *v10 = Four_Zeros;
        qmemcpy(&v10[1], v10, 4 * ((unsigned int)(16 * v44 - 13) >> 2));
        v9 = v47;
        v10 = v45;
      }
      v11 = (float)(v9 * v9);
      v12 = 1.0 / (float)((float)((float)v9 * 5.0) + v11);
      v13 = 0;
      v13.m128_f32[0] = v11 * v12;
      *v10 = _mm_shuffle_ps(v13, v13, 0);
      if ( v9 > 0 )
      {
        v14 = 0;
        v14.m128_f32[0] = v12 * 4.0;
        v15 = v14;
        v16 = 0;
        v16.m128_f32[0] = v12;
        v17 = _mm_shuffle_ps(v15, v15, 0);
        v18 = _mm_shuffle_ps(v16, v16, 0);
        v19 = v10 + 2;
        do
        {
          v19[-1] = v17;
          *v19 = v18;
          v19 += 2;
          --v9;
        }
        while ( v9 != 0 );
      }
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      ComputeACCEdgePosStencils(
        stencilBuffer1: sPosEdge1Stencil[v42],
        stencilBuffer2: sPosEdge2Stencil[v42],
        boundary: 0,
        corner: 0,
        n: v47);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeACCInteriorPosStencil",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      v20 = v41;
      v21 = 1.0 / (float)(v40 + 5.0);
      v22 = 0;
      v22.m128_f32[0] = v40 * v21;
      *(__m128 *)((char *)&sPosInteriorStencil[0][0] + v41) = _mm_shuffle_ps(v22, v22, 0);
      v23 = 0;
      v23.m128_f32[0] = v21 * 2.0;
      v24 = v23;
      *(__m128 *)((char *)&sPosInteriorStencil[0][1] + v41) = _mm_shuffle_ps(v23, v23, 0);
      v39 = v21;
      v25 = 0;
      v25.m128_f32[0] = v21;
      *(__m128 *)((char *)&sPosInteriorStencil[0][2] + v41) = _mm_shuffle_ps(v25, v25, 0);
      *(__m128 *)((char *)&sPosInteriorStencil[0][3] + v41) = _mm_shuffle_ps(v24, v24, 0);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeCatmullClarkLimitPosStencil",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      if ( v44 > 0 )
      {
        sPosCornerBndStencil[v46][0] = Four_Zeros;
        qmemcpy(&sPosCornerBndStencil[v46][1], sPosCornerBndStencil[v46], 4 * ((unsigned int)(16 * v44 - 13) >> 2));
        v20 = v41;
      }
      sPosCornerBndStencil[v46][0] = _mm_shuffle_ps(v38, v38, 0);
      sPosCornerBndStencil[v46][1] = _mm_shuffle_ps(v36, v36, 0);
      sCCLimitTanCornerStencil2[v46 + 19][v43 + 40] = v35;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeACCEdgePosStencils",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      sPosEdge2BndStencil[v42][0] = Four_Zeros;
      sPosEdge2BndStencil[v42][1].m128_i32[0] = sPosEdge2BndStencil[v42][0].m128_i32[0];
      sPosEdge2BndStencil[v42][1].m128_i32[1] = sPosEdge2BndStencil[v42][0].m128_i32[1];
      sPosEdge2BndStencil[v42][1].m128_i32[2] = sPosEdge2BndStencil[v42][0].m128_i32[2];
      sPosEdge2BndStencil[v42][1].m128_i32[3] = sPosEdge2BndStencil[v42][0].m128_i32[3];
      sPosEdge2BndStencil[v42][2].m128_i32[0] = sPosEdge2BndStencil[v42][1].m128_i32[0];
      sPosEdge2BndStencil[v42][2].m128_i32[1] = sPosEdge2BndStencil[v42][1].m128_i32[1];
      sPosEdge2BndStencil[v42][2].m128_i32[2] = sPosEdge2BndStencil[v42][1].m128_i32[2];
      sPosEdge2BndStencil[v42][2].m128_i32[3] = sPosEdge2BndStencil[v42][1].m128_i32[3];
      sPosEdge2BndStencil[v42][3].m128_i32[0] = sPosEdge2BndStencil[v42][2].m128_i32[0];
      sPosEdge2BndStencil[v42][3].m128_i32[1] = sPosEdge2BndStencil[v42][2].m128_i32[1];
      sPosEdge2BndStencil[v42][3].m128_i32[2] = sPosEdge2BndStencil[v42][2].m128_i32[2];
      sPosEdge2BndStencil[v42][3].m128_i32[3] = sPosEdge2BndStencil[v42][2].m128_i32[3];
      sPosEdge2BndStencil[v42][4].m128_i32[0] = sPosEdge2BndStencil[v42][3].m128_i32[0];
      sPosEdge2BndStencil[v42][4].m128_i32[1] = sPosEdge2BndStencil[v42][3].m128_i32[1];
      sPosEdge2BndStencil[v42][4].m128_i32[2] = sPosEdge2BndStencil[v42][3].m128_i32[2];
      v26 = sPosEdge2BndStencil[v42][3].m128_i32[3];
      sPosEdge1BndStencil[v42][0] = Four_Zeros;
      sPosEdge2BndStencil[v42][4].m128_i32[3] = v26;
      sPosEdge2BndStencil[v42][5].m128_i32[0] = sPosEdge2BndStencil[v42][4].m128_i32[0];
      sPosEdge2BndStencil[v42][5].m128_i32[1] = sPosEdge2BndStencil[v42][4].m128_i32[1];
      v27 = sPosEdge2BndStencil[v42][4].m128_i32[2];
      sPosEdge1BndStencil[v42][1].m128_i32[0] = sPosEdge1BndStencil[v42][0].m128_i32[0];
      sPosEdge2BndStencil[v42][5].m128_i32[2] = v27;
      v28 = sPosEdge2BndStencil[v42][4].m128_i32[3];
      sPosEdge1BndStencil[v42][1].m128_i32[1] = sPosEdge1BndStencil[v42][0].m128_i32[1];
      sPosEdge2BndStencil[v42][5].m128_i32[3] = v28;
      sPosEdge1BndStencil[v42][1].m128_i32[2] = sPosEdge1BndStencil[v42][0].m128_i32[2];
      sPosEdge1BndStencil[v42][1].m128_i32[3] = sPosEdge1BndStencil[v42][0].m128_i32[3];
      sPosEdge1BndStencil[v42][2].m128_i32[0] = sPosEdge1BndStencil[v42][1].m128_i32[0];
      sPosEdge1BndStencil[v42][2].m128_i32[1] = sPosEdge1BndStencil[v42][1].m128_i32[1];
      sPosEdge1BndStencil[v42][2].m128_i32[2] = sPosEdge1BndStencil[v42][1].m128_i32[2];
      sPosEdge1BndStencil[v42][2].m128_i32[3] = sPosEdge1BndStencil[v42][1].m128_i32[3];
      sPosEdge1BndStencil[v42][3].m128_i32[0] = sPosEdge1BndStencil[v42][2].m128_i32[0];
      sPosEdge1BndStencil[v42][3].m128_i32[1] = sPosEdge1BndStencil[v42][2].m128_i32[1];
      sPosEdge1BndStencil[v42][3].m128_i32[2] = sPosEdge1BndStencil[v42][2].m128_i32[2];
      sPosEdge1BndStencil[v42][3].m128_i32[3] = sPosEdge1BndStencil[v42][2].m128_i32[3];
      sPosEdge1BndStencil[v42][4].m128_i32[0] = sPosEdge1BndStencil[v42][3].m128_i32[0];
      sPosEdge1BndStencil[v42][4].m128_i32[1] = sPosEdge1BndStencil[v42][3].m128_i32[1];
      sPosEdge1BndStencil[v42][4].m128_i32[2] = sPosEdge1BndStencil[v42][3].m128_i32[2];
      sPosEdge1BndStencil[v42][4].m128_i32[3] = sPosEdge1BndStencil[v42][3].m128_i32[3];
      sPosEdge1BndStencil[v42][5].m128_i32[0] = sPosEdge1BndStencil[v42][4].m128_i32[0];
      sPosEdge1BndStencil[v42][5].m128_i32[1] = sPosEdge1BndStencil[v42][4].m128_i32[1];
      sPosEdge1BndStencil[v42][5].m128_i32[2] = sPosEdge1BndStencil[v42][4].m128_i32[2];
      sPosEdge1BndStencil[v42][5].m128_i32[3] = sPosEdge1BndStencil[v42][4].m128_i32[3];
      sPosEdge1BndStencil[v42][0] = _mm_shuffle_ps(v38, v38, 0);
      v29 = _mm_shuffle_ps(v37, v37, 0);
      sPosEdge2BndStencil[v42][0] = v29;
      sPosEdge1BndStencil[v42][3] = v29;
      sPosEdge2BndStencil[v42][3] = _mm_shuffle_ps(v38, v38, 0);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeACCEdgePosStencils",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      sPosEdge2CornerStencil[v42][0] = Four_Zeros;
      sPosEdge2CornerStencil[v42][1].m128_i32[0] = sPosEdge2CornerStencil[v42][0].m128_i32[0];
      sPosEdge2CornerStencil[v42][1].m128_i32[1] = sPosEdge2CornerStencil[v42][0].m128_i32[1];
      sPosEdge2CornerStencil[v42][1].m128_i32[2] = sPosEdge2CornerStencil[v42][0].m128_i32[2];
      sPosEdge2CornerStencil[v42][1].m128_i32[3] = sPosEdge2CornerStencil[v42][0].m128_i32[3];
      sPosEdge2CornerStencil[v42][2].m128_i32[0] = sPosEdge2CornerStencil[v42][1].m128_i32[0];
      sPosEdge2CornerStencil[v42][2].m128_i32[1] = sPosEdge2CornerStencil[v42][1].m128_i32[1];
      sPosEdge2CornerStencil[v42][2].m128_i32[2] = sPosEdge2CornerStencil[v42][1].m128_i32[2];
      sPosEdge2CornerStencil[v42][2].m128_i32[3] = sPosEdge2CornerStencil[v42][1].m128_i32[3];
      sPosEdge2CornerStencil[v42][3].m128_i32[0] = sPosEdge2CornerStencil[v42][2].m128_i32[0];
      sPosEdge2CornerStencil[v42][3].m128_i32[1] = sPosEdge2CornerStencil[v42][2].m128_i32[1];
      sPosEdge2CornerStencil[v42][3].m128_i32[2] = sPosEdge2CornerStencil[v42][2].m128_i32[2];
      sPosEdge2CornerStencil[v42][3].m128_i32[3] = sPosEdge2CornerStencil[v42][2].m128_i32[3];
      sPosEdge2CornerStencil[v42][4].m128_i32[0] = sPosEdge2CornerStencil[v42][3].m128_i32[0];
      sPosEdge2CornerStencil[v42][4].m128_i32[1] = sPosEdge2CornerStencil[v42][3].m128_i32[1];
      sPosEdge2CornerStencil[v42][4].m128_i32[2] = sPosEdge2CornerStencil[v42][3].m128_i32[2];
      sPosEdge2CornerStencil[v42][4].m128_i32[3] = sPosEdge2CornerStencil[v42][3].m128_i32[3];
      sPosEdge2CornerStencil[v42][5].m128_i32[0] = sPosEdge2CornerStencil[v42][4].m128_i32[0];
      sPosEdge2CornerStencil[v42][5].m128_i32[1] = sPosEdge2CornerStencil[v42][4].m128_i32[1];
      v30 = sPosEdge2CornerStencil[v42][4].m128_i32[2];
      sPosEdge1CornerStencil[v42][0] = Four_Zeros;
      sPosEdge1CornerStencil[v42][1].m128_i32[0] = sPosEdge1CornerStencil[v42][0].m128_i32[0];
      sPosEdge2CornerStencil[v42][5].m128_i32[2] = v30;
      sPosEdge1CornerStencil[v42][1].m128_i32[1] = sPosEdge1CornerStencil[v42][0].m128_i32[1];
      sPosEdge2CornerStencil[v42][5].m128_i32[3] = sPosEdge2CornerStencil[v42][4].m128_i32[3];
      sPosEdge1CornerStencil[v42][1].m128_i32[2] = sPosEdge1CornerStencil[v42][0].m128_i32[2];
      sPosEdge1CornerStencil[v42][1].m128_i32[3] = sPosEdge1CornerStencil[v42][0].m128_i32[3];
      sPosEdge1CornerStencil[v42][2].m128_i32[0] = sPosEdge1CornerStencil[v42][1].m128_i32[0];
      sPosEdge1CornerStencil[v42][2].m128_i32[1] = sPosEdge1CornerStencil[v42][1].m128_i32[1];
      sPosEdge1CornerStencil[v42][2].m128_i32[2] = sPosEdge1CornerStencil[v42][1].m128_i32[2];
      sPosEdge1CornerStencil[v42][2].m128_i32[3] = sPosEdge1CornerStencil[v42][1].m128_i32[3];
      sPosEdge1CornerStencil[v42][3].m128_i32[0] = sPosEdge1CornerStencil[v42][2].m128_i32[0];
      sPosEdge1CornerStencil[v42][3].m128_i32[1] = sPosEdge1CornerStencil[v42][2].m128_i32[1];
      sPosEdge1CornerStencil[v42][3].m128_i32[2] = sPosEdge1CornerStencil[v42][2].m128_i32[2];
      sPosEdge1CornerStencil[v42][3].m128_i32[3] = sPosEdge1CornerStencil[v42][2].m128_i32[3];
      sPosEdge1CornerStencil[v42][4].m128_i32[0] = sPosEdge1CornerStencil[v42][3].m128_i32[0];
      sPosEdge1CornerStencil[v42][4].m128_i32[1] = sPosEdge1CornerStencil[v42][3].m128_i32[1];
      sPosEdge1CornerStencil[v42][4].m128_i32[2] = sPosEdge1CornerStencil[v42][3].m128_i32[2];
      sPosEdge1CornerStencil[v42][4].m128_i32[3] = sPosEdge1CornerStencil[v42][3].m128_i32[3];
      sPosEdge1CornerStencil[v42][5].m128_i32[0] = sPosEdge1CornerStencil[v42][4].m128_i32[0];
      sPosEdge1CornerStencil[v42][5].m128_i32[1] = sPosEdge1CornerStencil[v42][4].m128_i32[1];
      sPosEdge1CornerStencil[v42][5].m128_i32[2] = sPosEdge1CornerStencil[v42][4].m128_i32[2];
      sPosEdge1CornerStencil[v42][5].m128_i32[3] = sPosEdge1CornerStencil[v42][4].m128_i32[3];
      sPosEdge1CornerStencil[v42][0] = _mm_shuffle_ps(v38, v38, 0);
      sPosEdge2CornerStencil[v42][0] = v29;
      sPosEdge1CornerStencil[v42][3] = v29;
      sPosEdge2CornerStencil[v42][3] = _mm_shuffle_ps(v38, v38, 0);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeACCInteriorPosStencil",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      v31 = 0;
      v31.m128_f32[0] = v39 * v40;
      *(__m128 *)((char *)&sPosInteriorBndStencil[0][0] + v20) = _mm_shuffle_ps(v31, v31, 0);
      v32 = 0;
      v32.m128_f32[0] = v39 * 2.0;
      v33 = v32;
      *(__m128 *)((char *)&sPosInteriorBndStencil[0][1] + v20) = _mm_shuffle_ps(v32, v32, 0);
      v34 = 0;
      v34.m128_f32[0] = v39;
      *(__m128 *)((char *)&sPosInteriorBndStencil[0][2] + v20) = _mm_shuffle_ps(v34, v34, 0);
      *(__m128 *)((char *)&sPosInteriorBndStencil[0][3] + v20) = _mm_shuffle_ps(v33, v33, 0);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      ComputeCatmullClarkLimitTanStencil(
        stencilBuffer1: sCCLimitTanStencil1[v46],
        a2: (int)v48,
        a3: 0,
        a4: 0,
        a5: v47,
        a6: sCCLimitTanStencil2[v46]);
      ComputeCatmullClarkLimitTanStencil(
        stencilBuffer1: sCCLimitTanBndStencil1[v46],
        a2: (int)v48,
        a3: 1,
        a4: 0,
        a5: v47,
        a6: sCCLimitTanBndStencil2[v46]);
      ComputeCatmullClarkLimitTanStencil(
        stencilBuffer1: sCCLimitTanCornerStencil1[v46],
        a2: (int)v48,
        a3: 1,
        a4: 1,
        a5: v47++,
        a6: sCCLimitTanCornerStencil2[v46]);
      v45 += 40;
      v44 += 2;
      v43 += 2;
      ++v46;
      if ( ++v42 > 19 )
        break;
      v9 = v47;
      v10 = v45;
    }
    ComputeACCSinCosPITables();
    sTableInited = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047520
// Name: void ComputeACCAllPatches(union __m128 __near *,struct TopologyIndexStruct __near *,class Vector4D __near *,class Vector4D __near *,class Vector4D __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
void __usercall ComputeACCAllPatches(
        int a1@<ebp>,
        __m128 *pPos,
        TopologyIndexStruct *quad,
        Vector4D *Pos,
        Vector4D *TanU,
        Vector4D *TanV)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  unsigned __int16 *v11; // ecx
  __int16 v12; // si
  unsigned __int16 *v13; // eax
  int v14; // edx
  float v15; // ecx
  __m128 *v16; // eax
  __m128 *v17; // esi
  __m128 *v18; // eax
  __m128 v19; // xmm1
  int v20; // eax
  int v21; // edx
  bool v22; // zf
  int v23; // edx
  float v24; // ecx
  int v25; // eax
  __m128 *v26; // edx
  __m128 *v27; // ecx
  int v28; // eax
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  int v31; // eax
  int v32; // edx
  int v33; // edx
  float v34; // ecx
  int v35; // eax
  __m128 *v36; // edx
  __m128 *v37; // ecx
  int v38; // eax
  __m128 v39; // xmm1
  __m128 v40; // xmm1
  int v41; // eax
  int v42; // edx
  int v43; // edx
  float v44; // ecx
  int v45; // eax
  __m128 *v46; // edx
  __m128 *v47; // ecx
  int v48; // eax
  __m128 v49; // xmm1
  __m128 v50; // xmm1
  int v51; // eax
  int v52; // edx
  unsigned __int16 *v53; // eax
  __m128 *v54; // ecx
  __m128 *v55; // edx
  int v56; // eax
  int v57; // ecx
  int v58; // edx
  unsigned __int16 *v59; // eax
  int v60; // ecx
  __m128 *v61; // edx
  unsigned __int16 *v62; // eax
  float v63; // ecx
  int v64; // edx
  unsigned __int16 v65; // ax
  unsigned __int16 v66; // cx
  __int16 v67; // dx
  int v68; // eax
  __m128 *v69; // eax
  int v70; // eax
  __m128 *v71; // eax
  int v72; // ecx
  int v73; // eax
  int v74; // edx
  __m128 v75; // xmm1
  __m128 v76; // xmm2
  int v77; // eax
  int v78; // edx
  int v79; // eax
  __m128 v80; // xmm0
  __m128 v81; // xmm1
  __m128 v82; // xmm0
  __m128 v83; // xmm5
  __m128 v84; // xmm0
  __m128 v85; // xmm3
  __m128 v86; // xmm6
  __m128 v87; // xmm7
  __m128 v88; // xmm2
  __m128 v89; // xmm0
  __m128 v90; // xmm2
  __m128 v91; // xmm6
  __m128 v92; // xmm4
  __m128 v93; // xmm3
  float v94; // ecx
  unsigned __int16 *v95; // eax
  unsigned __int16 *v96; // edx
  unsigned __int16 *v97; // eax
  int v98; // ecx
  unsigned __int16 *v99; // edx
  unsigned __int16 *v100; // eax
  __m128 *v101; // ecx
  __m128 *v102; // edx
  unsigned __int16 *v103; // eax
  int v104; // ecx
  unsigned __int16 *v105; // edx
  unsigned __int16 *v106; // eax
  int v107; // ecx
  float v108; // eax
  unsigned __int16 v109; // ax
  unsigned __int16 v110; // cx
  int v111; // eax
  __m128 *v112; // eax
  int v113; // eax
  __m128 *v114; // eax
  unsigned __int16 *v115; // ecx
  int v116; // eax
  int v117; // edx
  __m128 v118; // xmm1
  __m128 v119; // xmm2
  int v120; // eax
  int v121; // edx
  int v122; // eax
  __m128 v123; // xmm0
  __m128 v124; // xmm1
  __m128 v125; // xmm0
  __m128 v126; // xmm5
  __m128 v127; // xmm4
  __m128 v128; // xmm0
  __m128 v129; // xmm2
  __m128 v130; // xmm6
  __m128 v131; // xmm0
  __m128 v132; // xmm7
  __m128 v133; // xmm2
  __m128 v134; // xmm0
  __m128 v135; // xmm2
  __m128 v136; // xmm4
  float v137; // ecx
  int v138; // eax
  float v139; // edx
  int v140; // eax
  unsigned __int16 *v141; // ecx
  float v142; // edx
  int v143; // eax
  int v144; // ecx
  int v145; // edx
  int v146; // eax
  unsigned __int16 *v147; // ecx
  float v148; // edx
  int v149; // eax
  unsigned __int16 *v150; // ecx
  int v151; // eax
  unsigned __int16 v152; // ax
  unsigned __int16 v153; // cx
  int v154; // eax
  __m128 *v155; // eax
  int v156; // eax
  __m128 *v157; // eax
  float v158; // ecx
  int v159; // eax
  int v160; // edx
  __m128 v161; // xmm1
  __m128 v162; // xmm2
  int v163; // eax
  int v164; // edx
  int v165; // eax
  __m128 v166; // xmm0
  __m128 v167; // xmm1
  __m128 v168; // xmm0
  __m128 v169; // xmm5
  __m128 v170; // xmm4
  __m128 v171; // xmm0
  __m128 v172; // xmm2
  __m128 v173; // xmm6
  __m128 v174; // xmm0
  __m128 v175; // xmm7
  __m128 v176; // xmm2
  __m128 v177; // xmm0
  __m128 v178; // xmm3
  __m128 v179; // xmm2
  int v180; // ecx
  int v181; // eax
  float v182; // edx
  int v183; // eax
  unsigned __int16 *v184; // ecx
  int v185; // edx
  int v186; // eax
  unsigned __int16 *v187; // ecx
  unsigned __int16 *v188; // edx
  int v189; // eax
  float v190; // ecx
  float v191; // edx
  int v192; // eax
  float v193; // ecx
  int v194; // eax
  unsigned __int16 v195; // ax
  unsigned __int16 v196; // cx
  int v197; // eax
  __m128 *v198; // eax
  int v199; // eax
  __m128 *v200; // eax
  float v201; // ecx
  int v202; // eax
  int v203; // edx
  __m128 v204; // xmm1
  __m128 v205; // xmm2
  int v206; // eax
  int v207; // edx
  int v208; // eax
  __m128 v209; // xmm0
  __m128 v210; // xmm1
  __m128 v211; // xmm0
  __m128 v212; // xmm5
  __m128 v213; // xmm0
  __m128 v214; // xmm3
  __m128 v215; // xmm6
  __m128 v216; // xmm7
  __m128 v217; // xmm2
  __m128 v218; // xmm0
  __m128 v219; // xmm2
  __m128 v220; // xmm6
  __m128 v221; // xmm0
  __m128 v222; // xmm4
  __m128 v223; // xmm3
  __m128 *v224; // ecx
  int v225; // eax
  __m128 *v226; // eax
  __m128 v227; // xmm1
  __m128 *v228; // edx
  unsigned __int16 *v229; // ecx
  __m128 v230; // xmm0
  __m128 *v231; // eax
  int v232; // edx
  __m128 *v233; // eax
  __m128 v234; // xmm1
  __m128 *v235; // edx
  unsigned __int16 *v236; // ecx
  __m128 v237; // xmm0
  __m128 *v238; // eax
  int v239; // edx
  __m128 *v240; // eax
  __m128 v241; // xmm1
  __m128 *v242; // edx
  unsigned __int16 *v243; // ecx
  __m128 v244; // xmm0
  __m128 *v245; // eax
  float v246; // edx
  __m128 *v247; // eax
  __m128 v248; // xmm1
  __m128 *v249; // edx
  unsigned __int16 *v250; // ecx
  __m128 v251; // xmm0
  Vector4D v252; // xmm5
  unsigned __int16 *v253; // eax
  int v254; // ecx
  float v255; // xmm0_4
  int v256; // edx
  int v257; // eax
  float v258; // ecx
  float v259; // eax
  float v260; // edx
  int v261; // eax
  __int16 v262; // ax
  __m128 v263; // xmm1
  int v264; // eax
  int v265; // ecx
  __m128 v266; // xmm0
  __m128 *v267; // eax
  __m128 *v268; // edx
  __m128 v269; // xmm2
  int v270; // edx
  __m128 v271; // xmm1
  unsigned __int16 *v272; // edx
  __m128 *v273; // eax
  __m128 v274; // xmm3
  __m128 v275; // xmm2
  __m128 v276; // xmm0
  __m128 v277; // xmm4
  int v278; // ecx
  int v279; // eax
  __m128 v280; // xmm3
  __m128 v281; // xmm0
  __m128 v282; // xmm5
  __m128 v283; // xmm3
  __m128 v284; // xmm6
  __m128 v285; // xmm4
  __m128 v286; // xmm3
  __m128 v287; // xmm0
  __m128 v288; // xmm4
  __m128 v289; // xmm5
  __m128 v290; // xmm1
  __m128 v291; // xmm2
  __m128 v292; // xmm4
  __m128 v293; // xmm5
  __m128 v294; // xmm1
  __m128 v295; // xmm4
  __m128 v296; // xmm3
  __m128 v297; // xmm4
  __m128 v298; // xmm2
  int v299; // kr00_4
  __m128 v300; // xmm1
  __int128 v301; // xmm1
  __m128 v302; // xmm1
  __m128 v303; // xmm1
  __m128 v304; // xmm0
  int v305; // eax
  __m128 v306; // xmm2
  __m128 *v307; // ecx
  int v308; // eax
  __m128 v309; // xmm3
  __m128 v310; // xmm0
  int v311; // eax
  int v312; // ecx
  float v313; // eax
  float v314; // edx
  float v315; // ecx
  __m128 *v316; // eax
  int v317; // eax
  __m128 v318; // xmm4
  __int16 v319; // ax
  int v320; // eax
  __m128 v321; // xmm1
  int v322; // ecx
  __m128 v323; // xmm0
  __m128 *v324; // eax
  __m128 *v325; // edx
  __m128 v326; // xmm2
  unsigned __int16 *v327; // edx
  __m128 v328; // xmm1
  int v329; // ecx
  __m128 *v330; // eax
  __m128 v331; // xmm0
  __m128 v332; // xmm2
  __m128 v333; // xmm0
  __m128 v334; // xmm5
  int v335; // ecx
  int v336; // eax
  __m128 v337; // xmm3
  __m128 v338; // xmm0
  __m128 v339; // xmm4
  __m128 v340; // xmm3
  __m128 v341; // xmm6
  __m128 v342; // xmm4
  __m128 v343; // xmm3
  __m128 v344; // xmm0
  __m128 v345; // xmm4
  __m128 v346; // xmm5
  __m128 v347; // xmm1
  __m128 v348; // xmm2
  __m128 v349; // xmm4
  __m128 v350; // xmm4
  __m128 v351; // xmm1
  __m128 v352; // xmm5
  __m128 v353; // xmm3
  __m128 v354; // xmm2
  __m128 v355; // xmm3
  int v356; // kr08_4
  __m128 v357; // xmm1
  __int128 v358; // xmm1
  __m128 v359; // xmm1
  __m128 v360; // xmm1
  __m128 v361; // xmm0
  int v362; // eax
  __m128 v363; // xmm2
  __m128 *v364; // ecx
  int v365; // eax
  __m128 v366; // xmm3
  __m128 v367; // xmm0
  int v368; // eax
  int v369; // ecx
  float v370; // eax
  float v371; // edx
  float v372; // ecx
  __m128 *v373; // eax
  int v374; // eax
  __int16 v375; // ax
  int v376; // ecx
  __m128 v377; // xmm1
  __m128 *v378; // eax
  int v379; // ecx
  __m128 v380; // xmm0
  __m128 *v381; // edx
  __m128 v382; // xmm2
  int v383; // edx
  __m128 v384; // xmm1
  unsigned __int16 *v385; // edx
  __m128 *v386; // eax
  __m128 v387; // xmm3
  __m128 v388; // xmm2
  __m128 v389; // xmm0
  __m128 v390; // xmm4
  int v391; // ecx
  int v392; // eax
  __m128 v393; // xmm3
  __m128 v394; // xmm0
  __m128 v395; // xmm5
  __m128 v396; // xmm3
  __m128 v397; // xmm6
  __m128 v398; // xmm4
  __m128 v399; // xmm3
  __m128 v400; // xmm0
  __m128 v401; // xmm4
  __m128 v402; // xmm5
  __m128 v403; // xmm1
  __m128 v404; // xmm2
  __m128 v405; // xmm4
  __m128 v406; // xmm4
  __m128 v407; // xmm1
  __m128 v408; // xmm5
  __m128 v409; // xmm3
  __m128 v410; // xmm2
  __m128 v411; // xmm3
  int v412; // kr10_4
  __m128 v413; // xmm1
  __int128 v414; // xmm1
  __m128 v415; // xmm1
  __m128 v416; // xmm1
  __m128 v417; // xmm0
  int v418; // eax
  __m128 v419; // xmm2
  __m128 *v420; // ecx
  int v421; // eax
  __m128 v422; // xmm3
  __m128 v423; // xmm0
  int v424; // eax
  int v425; // ecx
  float v426; // eax
  float v427; // edx
  float v428; // ecx
  __m128 *v429; // eax
  int v430; // eax
  __int16 v431; // ax
  int v432; // ecx
  __m128 v433; // xmm1
  __m128 *v434; // eax
  int v435; // ecx
  __m128 v436; // xmm0
  __m128 *v437; // edx
  __m128 v438; // xmm2
  int v439; // edx
  __m128 v440; // xmm1
  unsigned __int16 *v441; // edx
  __m128 *v442; // eax
  __m128 v443; // xmm3
  __m128 v444; // xmm2
  __m128 v445; // xmm0
  __m128 v446; // xmm4
  int v447; // ecx
  int v448; // eax
  __m128 v449; // xmm3
  __m128 v450; // xmm0
  __m128 v451; // xmm5
  __m128 v452; // xmm3
  __m128 v453; // xmm6
  __m128 v454; // xmm4
  __m128 v455; // xmm3
  __m128 v456; // xmm0
  __m128 v457; // xmm4
  __m128 v458; // xmm5
  __m128 v459; // xmm1
  __m128 v460; // xmm2
  __m128 v461; // xmm4
  __m128 v462; // xmm5
  __m128 v463; // xmm1
  __m128 v464; // xmm4
  __m128 v465; // xmm3
  __m128 v466; // xmm4
  __m128 v467; // xmm2
  int v468; // eax
  int v469; // esi
  __m128 v470; // xmm1
  __m128 v471; // xmm1
  __m128 v472; // xmm1
  __m128 v473; // xmm1
  unsigned __int16 v474; // cx
  __m128 v475; // xmm2
  int v476; // eax
  int v477; // eax
  __m128 v478; // xmm3
  __m128 *v479; // ecx
  __m128 v480; // xmm0
  int v481; // eax
  int v482; // esi
  unsigned __int16 *v483; // eax
  int v484; // esi
  int v485; // ecx
  _WORD *v486; // eax
  double v487; // xmm0_8
  __m128 v488; // xmm1
  double v489; // xmm0_8
  int v490; // edx
  __m128 v491; // xmm1
  __m128 v492; // xmm1
  __m128 v493; // xmm2
  int v494; // eax
  int v495; // ecx
  int v496; // esi
  int v497; // eax
  double v498; // xmm0_8
  __m128 v499; // xmm1
  double v500; // xmm0_8
  int v501; // ecx
  __m128 v502; // xmm1
  int v503; // edx
  __m128 v504; // xmm1
  __m128 v505; // xmm2
  int v506; // eax
  int v507; // ecx
  int v508; // esi
  int v509; // eax
  double v510; // xmm0_8
  __m128 v511; // xmm1
  double v512; // xmm0_8
  __m128 v513; // xmm1
  __m128 v514; // xmm1
  int v515; // ecx
  __m128 v516; // xmm2
  __m128 v517; // xmm4
  __m128 v518; // xmm1
  unsigned __int16 *v519; // eax
  _WORD *v520; // edi
  int v521; // esi
  __m128 v522; // xmm0
  int v523; // ecx
  double v524; // xmm0_8
  __m128 v525; // xmm1
  double v526; // xmm0_8
  __m128 v527; // xmm1
  __m128 v528; // xmm0
  __m128 v529; // xmm1
  __m128 v530; // [esp-70h] [ebp-710h]
  __m128 v531; // [esp-50h] [ebp-6F0h]
  __m128 v532; // [esp-10h] [ebp-6B0h]
  __m128 OutTanU[16]; // [esp+0h] [ebp-6A0h]
  __m128 OutTanV[16]; // [esp+100h] [ebp-5A0h]
  __m128 v535; // [esp+200h] [ebp-4A0h]
  __m128 v536; // [esp+210h] [ebp-490h]
  __m128 v537; // [esp+220h] [ebp-480h]
  __m128 v538; // [esp+230h] [ebp-470h]
  __m128 v539; // [esp+240h] [ebp-460h]
  __m128 v540; // [esp+250h] [ebp-450h]
  __m128 v541; // [esp+260h] [ebp-440h]
  __m128 v542; // [esp+270h] [ebp-430h]
  __m128 v543; // [esp+280h] [ebp-420h]
  __m128 v544; // [esp+290h] [ebp-410h]
  __m128 v545; // [esp+2A0h] [ebp-400h]
  __m128 v546; // [esp+2B0h] [ebp-3F0h]
  __m128 v547; // [esp+2C0h] [ebp-3E0h]
  __m128 v548; // [esp+2D0h] [ebp-3D0h]
  __m128 v549; // [esp+2E0h] [ebp-3C0h]
  __m128 v550; // [esp+2F0h] [ebp-3B0h]
  __m128 v551; // [esp+300h] [ebp-3A0h]
  __m128 v552; // [esp+310h] [ebp-390h]
  __m128 v553; // [esp+320h] [ebp-380h]
  __m128 v554; // [esp+330h] [ebp-370h]
  __m128 v555; // [esp+340h] [ebp-360h]
  __m128 v556; // [esp+350h] [ebp-350h]
  __m128 v557; // [esp+360h] [ebp-340h]
  __m128 v558; // [esp+370h] [ebp-330h]
  __m128 v559; // [esp+380h] [ebp-320h]
  __m128 v560; // [esp+390h] [ebp-310h]
  __m128 v561; // [esp+3A0h] [ebp-300h]
  __m128 v562; // [esp+3B0h] [ebp-2F0h]
  __m128 v563; // [esp+3C0h] [ebp-2E0h]
  _DWORD v564[6]; // [esp+3D0h] [ebp-2D0h] BYREF
  _DWORD v565[6]; // [esp+3E8h] [ebp-2B8h] BYREF
  _DWORD v566[6]; // [esp+400h] [ebp-2A0h] BYREF
  _DWORD v567[6]; // [esp+418h] [ebp-288h] BYREF
  __m128 v568; // [esp+430h] [ebp-270h]
  __m128 OutPos[16]; // [esp+440h] [ebp-260h]
  __m128 v570; // [esp+540h] [ebp-160h]
  __m128 v571; // [esp+550h] [ebp-150h]
  __m128 v572; // [esp+560h] [ebp-140h]
  __m128 c0; // [esp+570h] [ebp-130h]
  __m128 v574; // [esp+580h] [ebp-120h]
  __m128 u10; // [esp+590h] [ebp-110h]
  __m128 u00; // [esp+5A0h] [ebp-100h]
  __m128 u20; // [esp+5B0h] [ebp-F0h]
  float v578; // [esp+5CCh] [ebp-D4h]
  float v579; // [esp+5D0h] [ebp-D0h]
  float v580; // [esp+5D4h] [ebp-CCh]
  float v581; // [esp+5D8h] [ebp-C8h]
  unsigned __int16 flLoopGap[14]; // [esp+5DCh] [ebp-C4h] OVERLAPPED
  int v583; // [esp+5F8h] [ebp-A8h]
  unsigned __int16 *v584; // [esp+5FCh] [ebp-A4h]
  unsigned __int16 *v585; // [esp+600h] [ebp-A0h]
  unsigned __int16 *v586; // [esp+604h] [ebp-9Ch]
  unsigned __int16 *v587; // [esp+608h] [ebp-98h]
  unsigned __int16 *pOneRing[4]; // [esp+60Ch] [ebp-94h]
  unsigned __int16 *v589; // [esp+62Ch] [ebp-74h]
  __m128 *v590; // [esp+630h] [ebp-70h]
  int v591; // [esp+634h] [ebp-6Ch]
  __m128 *v592; // [esp+638h] [ebp-68h]
  float v593; // [esp+63Ch] [ebp-64h]
  __m128 *v594; // [esp+640h] [ebp-60h]
  __m128 *v595; // [esp+658h] [ebp-48h]
  int v596; // [esp+65Ch] [ebp-44h]
  __m128 *v597; // [esp+660h] [ebp-40h]
  __m128 *v598; // [esp+67Ch] [ebp-24h]
  __m128 *v599; // [esp+680h] [ebp-20h]
  const char *v600; // [esp+684h] [ebp-1Ch]
  int v601; // [esp+688h] [ebp-18h]
  _BYTE v602[20]; // [esp+68Ch] [ebp-14h]
  __m128 *retaddr; // [esp+6A0h] [ebp+0h]

  *(_DWORD *)&v602[4] = a1;
  *(_DWORD *)&v602[8] = *(_DWORD *)&v602[16];
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCAllPatches (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  v6 = *(unsigned __int16 *)pPos->m128_i32[0];
  v584 = (unsigned __int16 *)pPos[2].m128_i32[2];
  v7 = *(unsigned __int16 *)(pPos->m128_i32[0] + 2);
  v585 = (unsigned __int16 *)(pPos[2].m128_i32[2] + 2 * v6);
  v8 = v7 + v6;
  v9 = *(unsigned __int16 *)(pPos->m128_i32[0] + 4);
  v10 = pPos[2].m128_i32[2];
  *(_DWORD *)v602 = 4;
  v601 = 0;
  v600 = "SubD Rendering";
  v586 = (unsigned __int16 *)(v10 + 2 * v8);
  v587 = (unsigned __int16 *)(pPos[2].m128_i32[2] + 2 * (v9 + v8));
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCAllPatches - Geometry Control Points (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  v11 = (unsigned __int16 *)pPos[1].m128_i32[0];
  v12 = *(_WORD *)pPos[1].m128_i32[2];
  v13 = (unsigned __int16 *)pPos->m128_i32[3];
  v597 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[2];
  v14 = *v11;
  LODWORD(v15) = *v13;
  *(_DWORD *)v602 = 4;
  v601 = 0;
  v596 = v14;
  v16 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[0];
  v593 = v15;
  v592 = v16;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( v12 != 0 )
  {
    v17 = retaddr;
    v568 = retaddr[*v584];
  }
  else
  {
    if ( (_WORD)v596 != 0 )
      v18 = sPosCornerBndStencil[(unsigned __int16)v597];
    else
      v18 = sPosCornerStencil[(unsigned __int16)v597];
    v17 = retaddr;
    v19 = _mm_mul_ps(*v18, retaddr[*v584]);
    v597 = v18;
    v568 = v19;
    if ( (_WORD)v592 != 0 )
    {
      v20 = LOWORD(v593);
      v598 = (__m128 *)LOWORD(v593);
      v595 = (__m128 *)(unsigned __int16)v592;
      do
      {
        v21 = v20 % (unsigned __int16)v592;
        if ( v21 != 0 )
        {
          v19 = _mm_add_ps(v19, _mm_mul_ps(v597[v21], retaddr[v584[v21]]));
          v568 = v19;
        }
        v20 = (int)v598->m128_i32 + 1;
        v22 = v595 == (__m128 *)1;
        v595 = (__m128 *)((char *)v595 - 1);
        v598 = (__m128 *)((char *)v598 + 1);
      }
      while ( !v22 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v23 = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 2);
  v597 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 2);
  LODWORD(v24) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 2);
  *(_DWORD *)v602 = 4;
  v596 = v23;
  v25 = *(unsigned __int16 *)(pPos->m128_i32[3] + 2);
  v601 = 0;
  v593 = v24;
  v26 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 2);
  v591 = v25;
  v592 = v26;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v596 != 0 )
  {
    OutPos[2] = v17[*v585];
  }
  else
  {
    if ( LOWORD(v593) != 0 )
      v27 = sPosCornerBndStencil[(unsigned __int16)v597];
    else
      v27 = sPosCornerStencil[(unsigned __int16)v597];
    v28 = *v585;
    v29 = *v27;
    v597 = v27;
    v30 = _mm_mul_ps(v29, v17[v28]);
    OutPos[2] = v30;
    if ( (_WORD)v592 != 0 )
    {
      v31 = (unsigned __int16)v591;
      v598 = (__m128 *)(unsigned __int16)v591;
      v595 = (__m128 *)(unsigned __int16)v592;
      do
      {
        v32 = v31 % (unsigned __int16)v592;
        if ( v32 != 0 )
        {
          v30 = _mm_add_ps(v30, _mm_mul_ps(v597[v32], v17[v585[v32]]));
          OutPos[2] = v30;
        }
        v31 = (int)v598->m128_i32 + 1;
        v22 = v595 == (__m128 *)1;
        v595 = (__m128 *)((char *)v595 - 1);
        v598 = (__m128 *)((char *)v598 + 1);
      }
      while ( !v22 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v33 = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 4);
  v597 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 4);
  LODWORD(v34) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 4);
  *(_DWORD *)v602 = 4;
  v596 = v33;
  v35 = *(unsigned __int16 *)(pPos->m128_i32[3] + 4);
  v601 = 0;
  v593 = v34;
  v36 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 4);
  v591 = v35;
  v592 = v36;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v596 != 0 )
  {
    OutPos[14] = v17[*v586];
  }
  else
  {
    if ( LOWORD(v593) != 0 )
      v37 = sPosCornerBndStencil[(unsigned __int16)v597];
    else
      v37 = sPosCornerStencil[(unsigned __int16)v597];
    v38 = *v586;
    v39 = *v37;
    v597 = v37;
    v40 = _mm_mul_ps(v39, v17[v38]);
    OutPos[14] = v40;
    if ( (_WORD)v592 != 0 )
    {
      v41 = (unsigned __int16)v591;
      v598 = (__m128 *)(unsigned __int16)v591;
      v595 = (__m128 *)(unsigned __int16)v592;
      do
      {
        v42 = v41 % (unsigned __int16)v592;
        if ( v42 != 0 )
        {
          v40 = _mm_add_ps(v40, _mm_mul_ps(v597[v42], v17[v586[v42]]));
          OutPos[14] = v40;
        }
        v41 = (int)v598->m128_i32 + 1;
        v22 = v595 == (__m128 *)1;
        v595 = (__m128 *)((char *)v595 - 1);
        v598 = (__m128 *)((char *)v598 + 1);
      }
      while ( !v22 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v43 = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 6);
  v597 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 6);
  LODWORD(v44) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 6);
  *(_DWORD *)v602 = 4;
  v596 = v43;
  v45 = *(unsigned __int16 *)(pPos->m128_i32[3] + 6);
  v601 = 0;
  v593 = v44;
  v46 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 6);
  v591 = v45;
  v592 = v46;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v596 != 0 )
  {
    OutPos[11] = v17[*v587];
  }
  else
  {
    if ( LOWORD(v593) != 0 )
      v47 = sPosCornerBndStencil[(unsigned __int16)v597];
    else
      v47 = sPosCornerStencil[(unsigned __int16)v597];
    v48 = *v587;
    v49 = *v47;
    v597 = v47;
    v50 = _mm_mul_ps(v49, v17[v48]);
    OutPos[11] = v50;
    if ( (_WORD)v592 != 0 )
    {
      v51 = (unsigned __int16)v591;
      v598 = (__m128 *)(unsigned __int16)v591;
      v595 = (__m128 *)(unsigned __int16)v592;
      do
      {
        v52 = v51 % (unsigned __int16)v592;
        if ( v52 != 0 )
        {
          v50 = _mm_add_ps(v50, _mm_mul_ps(v597[v52], v17[v587[v52]]));
          OutPos[11] = v50;
        }
        v51 = (int)v598->m128_i32 + 1;
        v22 = v595 == (__m128 *)1;
        v595 = (__m128 *)((char *)v595 - 1);
        v598 = (__m128 *)((char *)v598 + 1);
      }
      while ( !v22 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  pOneRing[0] = (unsigned __int16 *)*(unsigned __int16 *)pPos->m128_i32[3];
  v53 = (unsigned __int16 *)pPos->m128_i32[2];
  v54 = (__m128 *)v53[3];
  v55 = (__m128 *)*v53;
  v56 = pPos[2].m128_i32[0];
  v592 = v54;
  v57 = *(unsigned __int16 *)(v56 + 14);
  v597 = v55;
  v58 = *(unsigned __int16 *)(v56 + 12);
  v59 = (unsigned __int16 *)pPos[1].m128_i32[2];
  v591 = v57;
  v60 = v59[3];
  *(_DWORD *)flLoopGap = v58;
  v61 = (__m128 *)*v59;
  v62 = (unsigned __int16 *)pPos[1].m128_i32[0];
  v583 = v60;
  LODWORD(v63) = v62[3];
  v595 = v61;
  v64 = *v62;
  *(_DWORD *)v602 = 4;
  v601 = 0;
  v593 = v63;
  v596 = v64;
  v589 = (unsigned __int16 *)*(unsigned __int16 *)pPos->m128_i32[1];
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePositions (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v596 != 0 )
    v65 = 2 * (_WORD)v597 - 2;
  else
    v65 = (unsigned __int16)v597;
  v66 = (unsigned __int16)v592;
  if ( LOWORD(v593) != 0 )
    v66 = 2 * (_WORD)v592 - 2;
  v67 = (__int16)v598;
  v592 = (__m128 *)v65;
  v68 = v65;
  if ( (_WORD)v598 != 0 )
  {
    if ( (_WORD)v595 != 0 )
      v69 = sPosEdge1CornerStencil[v68];
    else
      v69 = sPosEdge1BndStencil[v68];
    v598 = v69;
    v597 = (__m128 *)v66;
    v70 = v66;
    if ( (_WORD)v583 != 0 )
      v71 = sPosEdge2CornerStencil[v70];
    else
      v71 = sPosEdge2BndStencil[v70];
  }
  else
  {
    v598 = sPosEdge1Stencil[v68];
    v597 = (__m128 *)v66;
    v71 = sPosEdge2Stencil[v66];
  }
  v595 = v71;
  v72 = 2 * (v67 == 0) + 4;
  v583 = v72;
  if ( flLoopGap[0] == 0x4000 && (_WORD)v591 == 0x4000 )
  {
    v73 = 1;
    memset(v567, 0, sizeof(v567));
    if ( 2 * (unsigned int)(v67 == 0) + 4 > 1 )
    {
      v74 = (unsigned __int16)v589;
      do
        v567[v73++] = v74++;
      while ( v73 < v72 );
    }
    v75 = Four_Zeros;
    v76 = Four_Zeros;
    OutPos[7] = Four_Zeros;
    OutPos[3] = Four_Zeros;
    if ( v72 > 0 )
    {
      v77 = LOWORD(pOneRing[0]);
      v597 = (__m128 *)LOWORD(pOneRing[0]);
      v592 = (__m128 *)v72;
      while ( 1 )
      {
        v78 = v77 % v72;
        v79 = v584[v567[v77 % v72]];
        v78 *= 2;
        v76 = _mm_add_ps(v76, _mm_mul_ps(*(__m128 *)((char *)v598 + 8 * v78), v17[v79]));
        OutPos[3] = v76;
        v80 = _mm_mul_ps(*(__m128 *)((char *)v595 + 8 * v78), v17[v79]);
        v77 = (int)v597->m128_i32 + 1;
        v22 = v592 == (__m128 *)1;
        v592 = (__m128 *)((char *)v592 - 1);
        v75 = _mm_add_ps(v75, v80);
        OutPos[7] = v75;
        v597 = (__m128 *)((char *)v597 + 1);
        if ( v22 )
          break;
        v72 = v583;
      }
    }
  }
  else
  {
    v81 = 0;
    v81.m128_f32[0] = (float)flLoopGap[0] * 0.000030517578;
    v82 = _mm_shuffle_ps(v81, v81, 0);
    u20 = _mm_mul_ps(_mm_mul_ps(v82, Four_Twos), v17[v584[(unsigned __int16)v589 + 4]]);
    v83 = _mm_mul_ps(v17[v584[(unsigned __int16)v589 + 3]], v82);
    v84 = _mm_sub_ps(Four_Ones, v82);
    v85 = v17[v584[(unsigned __int16)v589 + 2]];
    v86 = _mm_mul_ps(v17[v584[(unsigned __int16)v589 + 1]], v84);
    *(__m128 *)&flLoopGap[2] = _mm_mul_ps(_mm_mul_ps(v84, Four_Twos), v17[v584[(unsigned __int16)v589]]);
    pOneRing[0] = (unsigned __int16 *)&v17[*v584];
    v87 = Four_ValencePlus5[(_DWORD)v592];
    OutPos[3] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(Four_Valence[(_DWORD)v592], *(__m128 *)pOneRing[0]),
                            *(__m128 *)&flLoopGap[2]),
                          v86),
                        _mm_mul_ps(v85, Four_Twos)),
                      v83),
                    u20),
                  v87);
    v88 = 0;
    v88.m128_f32[0] = (float)(unsigned __int16)v591 * 0.000030517578;
    v89 = _mm_shuffle_ps(v88, v88, 0);
    v90 = _mm_mul_ps(v89, v17[v584[(unsigned __int16)v589 + 4]]);
    v91 = v17[v584[(unsigned __int16)v589 + 3]];
    pOneRing[0] = (unsigned __int16 *)&v17[v584[(unsigned __int16)v589 + 2]];
    v92 = _mm_sub_ps(Four_Ones, v89);
    v93 = _mm_mul_ps(Four_Valence[(_DWORD)v597], *(__m128 *)pOneRing[0]);
    *(__m128 *)&flLoopGap[2] = _mm_mul_ps(_mm_mul_ps(v92, Four_Twos), v17[v584[(unsigned __int16)v589 + 1]]);
    OutPos[7] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(v17[*v584], Four_Twos),
                            _mm_mul_ps(v17[v584[(unsigned __int16)v589]], v92)),
                          *(__m128 *)&flLoopGap[2]),
                        v93),
                      _mm_mul_ps(v91, _mm_mul_ps(v89, Four_Twos))),
                    v90),
                  v87);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  LODWORD(v94) = *(unsigned __int16 *)(pPos->m128_i32[3] + 2);
  v95 = (unsigned __int16 *)pPos->m128_i32[2];
  v96 = (unsigned __int16 *)*v95;
  v591 = v95[1];
  v97 = (unsigned __int16 *)pPos[2].m128_i32[0];
  *(float *)&v590 = v94;
  v98 = v97[1];
  v589 = v96;
  v99 = (unsigned __int16 *)*v97;
  v100 = (unsigned __int16 *)pPos[1].m128_i32[2];
  v596 = v98;
  v101 = (__m128 *)*v100;
  pOneRing[1] = v99;
  v102 = (__m128 *)v100[1];
  v103 = (unsigned __int16 *)pPos[1].m128_i32[0];
  v592 = v101;
  v104 = *v103;
  v597 = v102;
  v105 = (unsigned __int16 *)v103[1];
  v106 = (unsigned __int16 *)pPos[1].m128_i32[1];
  *(_DWORD *)v602 = 4;
  v601 = 0;
  *(_DWORD *)flLoopGap = v104;
  v107 = *v106;
  pOneRing[0] = v105;
  LODWORD(v108) = *(unsigned __int16 *)(pPos->m128_i32[1] + 2);
  v583 = v107;
  v593 = v108;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePositions (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( LOWORD(pOneRing[0]) != 0 )
    v109 = 2 * v591 - 2;
  else
    v109 = v591;
  v110 = (unsigned __int16)v589;
  if ( flLoopGap[0] != 0 )
    v110 = 2 * (_WORD)v589 - 2;
  v598 = (__m128 *)v109;
  v111 = v109;
  if ( (_WORD)v583 != 0 )
  {
    if ( (_WORD)v597 != 0 )
      v112 = sPosEdge1CornerStencil[v111];
    else
      v112 = sPosEdge1BndStencil[v111];
    v597 = v112;
    v595 = (__m128 *)v110;
    v113 = v110;
    if ( (_WORD)v592 != 0 )
      v114 = sPosEdge2CornerStencil[v113];
    else
      v114 = sPosEdge2BndStencil[v113];
  }
  else
  {
    v597 = sPosEdge1Stencil[v111];
    v595 = (__m128 *)v110;
    v114 = sPosEdge2Stencil[v110];
  }
  v592 = v114;
  v115 = (unsigned __int16 *)(2 * ((_WORD)v583 == 0) + 4);
  pOneRing[0] = v115;
  if ( LOWORD(pOneRing[1]) == 0x4000 && (_WORD)v596 == 0x4000 )
  {
    v116 = 1;
    memset(v565, 0, sizeof(v565));
    if ( 2 * (unsigned int)((_WORD)v583 == 0) + 4 > 1 )
    {
      v117 = LOWORD(v593);
      do
        v565[v116++] = v117++;
      while ( v116 < (int)v115 );
    }
    v118 = Four_Zeros;
    v119 = Four_Zeros;
    OutPos[0] = Four_Zeros;
    OutPos[1] = Four_Zeros;
    if ( (int)v115 > 0 )
    {
      v120 = (unsigned __int16)v590;
      v591 = (unsigned __int16)v590;
      v589 = v115;
      while ( 1 )
      {
        v121 = v120 % (int)v115;
        v122 = v585[v565[v120 % (int)v115]];
        v121 *= 2;
        v119 = _mm_add_ps(v119, _mm_mul_ps(*(__m128 *)((char *)v597 + 8 * v121), v17[v122]));
        OutPos[1] = v119;
        v123 = _mm_mul_ps(*(__m128 *)((char *)v592 + 8 * v121), v17[v122]);
        v120 = v591 + 1;
        v22 = v589 == (unsigned __int16 *)1;
        v589 = (unsigned __int16 *)((char *)v589 - 1);
        v118 = _mm_add_ps(v118, v123);
        OutPos[0] = v118;
        ++v591;
        if ( v22 )
          break;
        v115 = pOneRing[0];
      }
    }
  }
  else
  {
    v124 = 0;
    v124.m128_f32[0] = (float)LOWORD(pOneRing[1]) * 0.000030517578;
    v125 = _mm_shuffle_ps(v124, v124, 0);
    v126 = _mm_mul_ps(v17[v585[LOWORD(v593) + 4]], _mm_mul_ps(v125, Four_Twos));
    v127 = _mm_mul_ps(v17[v585[LOWORD(v593) + 3]], v125);
    v128 = _mm_sub_ps(Four_Ones, v125);
    v129 = v17[v585[LOWORD(v593) + 2]];
    v130 = _mm_mul_ps(v17[v585[LOWORD(v593) + 1]], v128);
    *(__m128 *)&flLoopGap[2] = _mm_mul_ps(v17[v585[LOWORD(v593)]], _mm_mul_ps(v128, Four_Twos));
    v590 = &v17[*v585];
    v131 = Four_Valence[(_DWORD)v598];
    pOneRing[1] = (unsigned __int16 *)(16 * (_DWORD)v598);
    v132 = Four_ValencePlus5[(_DWORD)v598];
    OutPos[1] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_add_ps(_mm_mul_ps(v131, *v590), *(__m128 *)&flLoopGap[2]), v130),
                        _mm_mul_ps(v129, Four_Twos)),
                      v127),
                    v126),
                  v132);
    v133 = 0;
    v133.m128_f32[0] = (float)(unsigned __int16)v596 * 0.000030517578;
    v134 = _mm_shuffle_ps(v133, v133, 0);
    *(__m128 *)&flLoopGap[2] = _mm_sub_ps(Four_Ones, v134);
    v135 = _mm_mul_ps(v17[v585[LOWORD(v593) + 4]], v134);
    v136 = _mm_mul_ps(v17[v585[LOWORD(v593) + 3]], _mm_mul_ps(v134, Four_Twos));
    v590 = &v17[v585[LOWORD(v593) + 2]];
    OutPos[0] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(v17[*v585], Four_Twos),
                            _mm_mul_ps(v17[v585[LOWORD(v593)]], *(__m128 *)&flLoopGap[2])),
                          _mm_mul_ps(v17[v585[LOWORD(v593) + 1]], _mm_mul_ps(*(__m128 *)&flLoopGap[2], Four_Twos))),
                        _mm_mul_ps(Four_Valence[(_DWORD)v595], *v590)),
                      v136),
                    v135),
                  v132);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  LODWORD(v137) = *(unsigned __int16 *)(pPos->m128_i32[3] + 4);
  v138 = pPos->m128_i32[2];
  LODWORD(v139) = *(unsigned __int16 *)(v138 + 2);
  v596 = *(unsigned __int16 *)(v138 + 4);
  v140 = pPos[2].m128_i32[0];
  *(float *)&v599 = v137;
  v141 = (unsigned __int16 *)*(unsigned __int16 *)(v140 + 6);
  v593 = v139;
  LODWORD(v142) = *(unsigned __int16 *)(v140 + 4);
  v143 = pPos[1].m128_i32[2];
  v589 = v141;
  v144 = *(unsigned __int16 *)(v143 + 2);
  *(float *)&v594 = v142;
  v145 = *(unsigned __int16 *)(v143 + 4);
  v146 = pPos[1].m128_i32[0];
  v583 = v144;
  v147 = (unsigned __int16 *)*(unsigned __int16 *)(v146 + 2);
  *(_DWORD *)flLoopGap = v145;
  LODWORD(v148) = *(unsigned __int16 *)(v146 + 4);
  v149 = pPos[1].m128_i32[1];
  *(_DWORD *)v602 = 4;
  v601 = 0;
  pOneRing[1] = v147;
  v150 = (unsigned __int16 *)*(unsigned __int16 *)(v149 + 2);
  *(float *)&v590 = v148;
  v151 = *(unsigned __int16 *)(pPos->m128_i32[1] + 4);
  pOneRing[0] = v150;
  v591 = v151;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePositions (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v590 != 0 )
    v152 = 2 * v596 - 2;
  else
    v152 = v596;
  v153 = LOWORD(v593);
  if ( LOWORD(pOneRing[1]) != 0 )
    v153 = 2 * LOWORD(v593) - 2;
  v598 = (__m128 *)v152;
  v154 = v152;
  if ( LOWORD(pOneRing[0]) != 0 )
  {
    if ( flLoopGap[0] != 0 )
      v155 = sPosEdge1CornerStencil[v154];
    else
      v155 = sPosEdge1BndStencil[v154];
    v597 = v155;
    v595 = (__m128 *)v153;
    v156 = v153;
    if ( (_WORD)v583 != 0 )
      v157 = sPosEdge2CornerStencil[v156];
    else
      v157 = sPosEdge2BndStencil[v156];
  }
  else
  {
    v597 = sPosEdge1Stencil[v154];
    v595 = (__m128 *)v153;
    v157 = sPosEdge2Stencil[v153];
  }
  v592 = v157;
  LODWORD(v158) = 2 * (LOWORD(pOneRing[0]) == 0) + 4;
  *(float *)&v590 = v158;
  if ( (_WORD)v594 == 0x4000 && (_WORD)v589 == 0x4000 )
  {
    v159 = 1;
    memset(v566, 0, sizeof(v566));
    if ( 2 * (unsigned int)(LOWORD(pOneRing[0]) == 0) + 4 > 1 )
    {
      v160 = (unsigned __int16)v591;
      do
        v566[v159++] = v160++;
      while ( v159 < SLODWORD(v158) );
    }
    v161 = Four_Zeros;
    v162 = Four_Zeros;
    OutPos[6] = Four_Zeros;
    OutPos[10] = Four_Zeros;
    if ( SLODWORD(v158) > 0 )
    {
      v163 = (unsigned __int16)v599;
      v596 = (unsigned __int16)v599;
      v593 = v158;
      while ( 1 )
      {
        v164 = v163 % SLODWORD(v158);
        v165 = v586[v566[v163 % SLODWORD(v158)]];
        v164 *= 2;
        v162 = _mm_add_ps(v162, _mm_mul_ps(*(__m128 *)((char *)v597 + 8 * v164), v17[v165]));
        OutPos[10] = v162;
        v166 = _mm_mul_ps(*(__m128 *)((char *)v592 + 8 * v164), v17[v165]);
        v163 = v596 + 1;
        v22 = LODWORD(v593)-- == 1;
        v161 = _mm_add_ps(v161, v166);
        OutPos[6] = v161;
        ++v596;
        if ( v22 )
          break;
        v158 = *(float *)&v590;
      }
    }
  }
  else
  {
    v167 = 0;
    v167.m128_f32[0] = (float)(unsigned __int16)v594 * 0.000030517578;
    v168 = _mm_shuffle_ps(v167, v167, 0);
    v169 = _mm_mul_ps(v17[v586[(unsigned __int16)v591 + 4]], _mm_mul_ps(v168, Four_Twos));
    v170 = _mm_mul_ps(v17[v586[(unsigned __int16)v591 + 3]], v168);
    v171 = _mm_sub_ps(Four_Ones, v168);
    v172 = v17[v586[(unsigned __int16)v591 + 2]];
    v173 = _mm_mul_ps(v17[v586[(unsigned __int16)v591 + 1]], v171);
    *(__m128 *)&flLoopGap[2] = _mm_mul_ps(v17[v586[(unsigned __int16)v591]], _mm_mul_ps(v171, Four_Twos));
    v599 = &v17[*v586];
    v174 = Four_Valence[(_DWORD)v598];
    v594 = (__m128 *)(16 * (_DWORD)v598);
    v175 = Four_ValencePlus5[(_DWORD)v598];
    OutPos[10] = _mm_div_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_add_ps(_mm_mul_ps(v174, *v599), *(__m128 *)&flLoopGap[2]), v173),
                         _mm_mul_ps(v172, Four_Twos)),
                       v170),
                     v169),
                   v175);
    v176 = 0;
    v176.m128_f32[0] = (float)(unsigned __int16)v589 * 0.000030517578;
    v177 = _mm_shuffle_ps(v176, v176, 0);
    v178 = _mm_sub_ps(Four_Ones, v177);
    v179 = _mm_mul_ps(v17[v586[(unsigned __int16)v591 + 4]], v177);
    *(__m128 *)&flLoopGap[2] = _mm_mul_ps(_mm_mul_ps(v177, Four_Twos), v17[v586[(unsigned __int16)v591 + 3]]);
    v599 = &v17[v586[(unsigned __int16)v591 + 2]];
    OutPos[6] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(v17[*v586], Four_Twos),
                            _mm_mul_ps(v17[v586[(unsigned __int16)v591]], v178)),
                          _mm_mul_ps(v17[v586[(unsigned __int16)v591 + 1]], _mm_mul_ps(v178, Four_Twos))),
                        _mm_mul_ps(Four_Valence[(_DWORD)v595], *v599)),
                      *(__m128 *)&flLoopGap[2]),
                    v179),
                  v175);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v180 = *(unsigned __int16 *)(pPos->m128_i32[3] + 6);
  v181 = pPos->m128_i32[2];
  LODWORD(v182) = *(unsigned __int16 *)(v181 + 4);
  v596 = *(unsigned __int16 *)(v181 + 6);
  v183 = pPos[2].m128_i32[0];
  v583 = v180;
  v184 = (unsigned __int16 *)*(unsigned __int16 *)(v183 + 10);
  v593 = v182;
  v185 = *(unsigned __int16 *)(v183 + 8);
  v186 = pPos[1].m128_i32[2];
  v589 = v184;
  v187 = (unsigned __int16 *)*(unsigned __int16 *)(v186 + 4);
  *(_DWORD *)flLoopGap = v185;
  v188 = (unsigned __int16 *)*(unsigned __int16 *)(v186 + 6);
  v189 = pPos[1].m128_i32[0];
  pOneRing[0] = v187;
  LODWORD(v190) = *(unsigned __int16 *)(v189 + 4);
  pOneRing[1] = v188;
  LODWORD(v191) = *(unsigned __int16 *)(v189 + 6);
  v192 = pPos[1].m128_i32[1];
  *(_DWORD *)v602 = 4;
  v601 = 0;
  *(float *)&v594 = v190;
  LODWORD(v193) = *(unsigned __int16 *)(v192 + 4);
  *(float *)&v599 = v191;
  v194 = *(unsigned __int16 *)(pPos->m128_i32[1] + 6);
  *(float *)&v590 = v193;
  v591 = v194;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePositions (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v599 != 0 )
    v195 = 2 * v596 - 2;
  else
    v195 = v596;
  v196 = LOWORD(v593);
  if ( (_WORD)v594 != 0 )
    v196 = 2 * LOWORD(v593) - 2;
  v598 = (__m128 *)v195;
  v197 = v195;
  if ( (_WORD)v590 != 0 )
  {
    if ( LOWORD(pOneRing[1]) != 0 )
      v198 = sPosEdge1CornerStencil[v197];
    else
      v198 = sPosEdge1BndStencil[v197];
    v597 = v198;
    v595 = (__m128 *)v196;
    v199 = v196;
    if ( LOWORD(pOneRing[0]) != 0 )
      v200 = sPosEdge2CornerStencil[v199];
    else
      v200 = sPosEdge2BndStencil[v199];
  }
  else
  {
    v597 = sPosEdge1Stencil[v197];
    v595 = (__m128 *)v196;
    v200 = sPosEdge2Stencil[v196];
  }
  v592 = v200;
  LODWORD(v201) = 2 * ((_WORD)v590 == 0) + 4;
  *(float *)&v599 = v201;
  if ( flLoopGap[0] == 0x4000 && (_WORD)v589 == 0x4000 )
  {
    v202 = 1;
    memset(v564, 0, sizeof(v564));
    if ( 2 * (unsigned int)((_WORD)v590 == 0) + 4 > 1 )
    {
      v203 = (unsigned __int16)v591;
      do
        v564[v202++] = v203++;
      while ( v202 < SLODWORD(v201) );
    }
    v204 = Four_Zeros;
    v205 = Four_Zeros;
    OutPos[13] = Four_Zeros;
    OutPos[12] = Four_Zeros;
    if ( SLODWORD(v201) > 0 )
    {
      v206 = (unsigned __int16)v583;
      v596 = (unsigned __int16)v583;
      v593 = v201;
      while ( 1 )
      {
        v207 = v206 % SLODWORD(v201);
        v208 = v587[v564[v206 % SLODWORD(v201)]];
        v207 *= 2;
        v205 = _mm_add_ps(v205, _mm_mul_ps(*(__m128 *)((char *)v597 + 8 * v207), v17[v208]));
        OutPos[12] = v205;
        v209 = _mm_mul_ps(*(__m128 *)((char *)v592 + 8 * v207), v17[v208]);
        v206 = v596 + 1;
        v22 = LODWORD(v593)-- == 1;
        v204 = _mm_add_ps(v204, v209);
        OutPos[13] = v204;
        ++v596;
        if ( v22 )
          break;
        v201 = *(float *)&v599;
      }
    }
  }
  else
  {
    v210 = 0;
    v210.m128_f32[0] = (float)flLoopGap[0] * 0.000030517578;
    v211 = _mm_shuffle_ps(v210, v210, 0);
    u20 = _mm_mul_ps(_mm_mul_ps(v211, Four_Twos), v17[v587[(unsigned __int16)v591 + 4]]);
    v212 = _mm_mul_ps(v17[v587[(unsigned __int16)v591 + 3]], v211);
    v213 = _mm_sub_ps(Four_Ones, v211);
    v214 = v17[v587[(unsigned __int16)v591 + 2]];
    v215 = _mm_mul_ps(v17[v587[(unsigned __int16)v591 + 1]], v213);
    *(__m128 *)&flLoopGap[2] = _mm_mul_ps(_mm_mul_ps(v213, Four_Twos), v17[v587[(unsigned __int16)v591]]);
    v599 = &v17[*v587];
    v216 = Four_ValencePlus5[(_DWORD)v598];
    OutPos[12] = _mm_div_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_mul_ps(Four_Valence[(_DWORD)v598], *v599), *(__m128 *)&flLoopGap[2]),
                           v215),
                         _mm_mul_ps(v214, Four_Twos)),
                       v212),
                     u20),
                   v216);
    v217 = 0;
    v217.m128_f32[0] = (float)(unsigned __int16)v589 * 0.000030517578;
    v218 = v217;
    v219 = v17[v587[(unsigned __int16)v591 + 4]];
    v220 = v17[v587[(unsigned __int16)v591 + 3]];
    v599 = &v17[v587[(unsigned __int16)v591 + 2]];
    v221 = _mm_shuffle_ps(v218, v218, 0);
    v222 = _mm_sub_ps(Four_Ones, v221);
    v223 = _mm_mul_ps(Four_Valence[(_DWORD)v595], *v599);
    *(__m128 *)&flLoopGap[2] = _mm_mul_ps(_mm_mul_ps(v222, Four_Twos), v17[v587[(unsigned __int16)v591 + 1]]);
    OutPos[13] = _mm_div_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(v17[*v587], Four_Twos),
                             _mm_mul_ps(v17[v587[(unsigned __int16)v591]], v222)),
                           *(__m128 *)&flLoopGap[2]),
                         v223),
                       _mm_mul_ps(v220, _mm_mul_ps(v221, Four_Twos))),
                     _mm_mul_ps(v219, v221)),
                   v216);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v224 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[2];
  v225 = *(unsigned __int16 *)pPos[1].m128_i32[0];
  *(_DWORD *)v602 = 4;
  v601 = 0;
  v598 = v224;
  v594 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[1];
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCInteriorPosition (SIMD)",
    a3: v225,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v599 != 0 )
  {
    if ( (unsigned __int16)v598 <= 2u )
      v598 = (__m128 *)(unsigned __int16)(4 * (_WORD)v598 - 4);
    else
      v598 = (__m128 *)(unsigned __int16)(2 * (_WORD)v598 - 2);
  }
  v226 = sPosInteriorStencil[(unsigned __int16)v598];
  v227 = _mm_mul_ps(v17[*v584], *v226);
  v228 = v226 + 1;
  OutPos[4] = v227;
  v229 = &v584[(unsigned __int16)v594];
  v596 = 3;
  do
  {
    v230 = _mm_mul_ps(*v228++, v17[*v229++]);
    v22 = v596-- == 1;
    v227 = _mm_add_ps(v227, v230);
    OutPos[4] = v227;
  }
  while ( !v22 );
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v231 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 2);
  v232 = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 2);
  *(_DWORD *)v602 = 4;
  v598 = v231;
  v594 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[1] + 2);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCInteriorPosition (SIMD)",
    a3: v232,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v599 != 0 )
  {
    if ( (unsigned __int16)v598 <= 2u )
      v598 = (__m128 *)(unsigned __int16)(4 * (_WORD)v598 - 4);
    else
      v598 = (__m128 *)(unsigned __int16)(2 * (_WORD)v598 - 2);
  }
  v233 = sPosInteriorStencil[(unsigned __int16)v598];
  v234 = _mm_mul_ps(v17[*v585], *v233);
  v235 = v233 + 1;
  OutPos[5] = v234;
  v236 = &v585[(unsigned __int16)v594];
  v596 = 3;
  do
  {
    v237 = _mm_mul_ps(v17[*v236++], *v235++);
    v22 = v596-- == 1;
    v234 = _mm_add_ps(v234, v237);
    OutPos[5] = v234;
  }
  while ( !v22 );
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v238 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 4);
  v239 = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 4);
  *(_DWORD *)v602 = 4;
  v598 = v238;
  v594 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[1] + 4);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCInteriorPosition (SIMD)",
    a3: v239,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v599 != 0 )
  {
    if ( (unsigned __int16)v598 <= 2u )
      v598 = (__m128 *)(unsigned __int16)(4 * (_WORD)v598 - 4);
    else
      v598 = (__m128 *)(unsigned __int16)(2 * (_WORD)v598 - 2);
  }
  v240 = sPosInteriorStencil[(unsigned __int16)v598];
  v241 = _mm_mul_ps(*v240, v17[*v586]);
  v242 = v240 + 1;
  OutPos[9] = v241;
  v243 = &v586[(unsigned __int16)v594];
  v596 = 3;
  do
  {
    v244 = _mm_mul_ps(v17[*v243++], *v242++);
    v22 = v596-- == 1;
    v241 = _mm_add_ps(v241, v244);
    OutPos[9] = v241;
  }
  while ( !v22 );
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v245 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 6);
  LODWORD(v246) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 6);
  *(_DWORD *)&v602[16] = 4;
  v598 = v245;
  v594 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[1] + 6);
  *(float *)&v599 = v246;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCInteriorPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v599 != 0 )
  {
    if ( (unsigned __int16)v598 <= 2u )
      v598 = (__m128 *)(unsigned __int16)(4 * (_WORD)v598 - 4);
    else
      v598 = (__m128 *)(unsigned __int16)(2 * (_WORD)v598 - 2);
  }
  v247 = sPosInteriorStencil[(unsigned __int16)v598];
  v248 = _mm_mul_ps(*v247, v17[*v587]);
  v249 = v247 + 1;
  OutPos[8] = v248;
  v250 = &v587[(unsigned __int16)v594];
  v596 = 3;
  do
  {
    v251 = _mm_mul_ps(v17[*v250++], *v249++);
    v22 = v596-- == 1;
    v248 = _mm_add_ps(v248, v251);
    OutPos[8] = v248;
  }
  while ( !v22 );
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  if ( (_BYTE)TanV == 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeACCAllPatches - Tangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    OutTanU[15] = _mm_mul_ps(_mm_sub_ps(OutPos[3], v568), Four_Threes);
    OutTanV[0] = _mm_mul_ps(_mm_sub_ps(OutPos[4], OutPos[0]), Four_Threes);
    OutTanU[5] = _mm_mul_ps(_mm_sub_ps(OutPos[8], OutPos[7]), Four_Threes);
    OutTanV[1] = _mm_mul_ps(_mm_sub_ps(OutPos[5], OutPos[1]), Four_Threes);
    OutTanU[2] = _mm_mul_ps(_mm_sub_ps(OutPos[4], OutPos[3]), Four_Threes);
    OutTanU[8] = _mm_mul_ps(_mm_sub_ps(OutPos[12], OutPos[11]), Four_Threes);
    OutTanV[2] = _mm_mul_ps(_mm_sub_ps(OutPos[6], OutPos[2]), Four_Threes);
    OutTanU[0] = _mm_mul_ps(_mm_sub_ps(OutPos[1], OutPos[0]), Four_Threes);
    OutTanV[3] = _mm_mul_ps(_mm_sub_ps(OutPos[7], OutPos[3]), Four_Threes);
    OutTanU[3] = _mm_mul_ps(_mm_sub_ps(OutPos[5], OutPos[4]), Four_Threes);
    OutTanU[6] = _mm_mul_ps(_mm_sub_ps(OutPos[9], OutPos[8]), Four_Threes);
    OutTanV[4] = _mm_mul_ps(_mm_sub_ps(OutPos[8], OutPos[4]), Four_Threes);
    OutTanV[5] = _mm_mul_ps(_mm_sub_ps(OutPos[9], OutPos[5]), Four_Threes);
    OutTanU[9] = _mm_mul_ps(_mm_sub_ps(OutPos[13], OutPos[12]), Four_Threes);
    v252 = (Vector4D)_mm_mul_ps(_mm_sub_ps(OutPos[0], v568), Four_Threes);
    v532 = (__m128)v252;
    OutTanV[6] = _mm_mul_ps(_mm_sub_ps(OutPos[10], OutPos[6]), Four_Threes);
    OutTanV[7] = _mm_mul_ps(_mm_sub_ps(OutPos[11], OutPos[7]), Four_Threes);
    OutTanU[4] = _mm_mul_ps(_mm_sub_ps(OutPos[6], OutPos[5]), Four_Threes);
    OutTanU[7] = _mm_mul_ps(_mm_sub_ps(OutPos[10], OutPos[9]), Four_Threes);
    OutTanV[8] = _mm_mul_ps(_mm_sub_ps(OutPos[12], OutPos[8]), Four_Threes);
    OutTanV[9] = _mm_mul_ps(_mm_sub_ps(OutPos[13], OutPos[9]), Four_Threes);
    OutTanV[10] = _mm_mul_ps(_mm_sub_ps(OutPos[14], OutPos[10]), Four_Threes);
    OutTanU[1] = _mm_mul_ps(_mm_sub_ps(OutPos[2], OutPos[1]), Four_Threes);
    OutTanU[10] = _mm_mul_ps(_mm_sub_ps(OutPos[14], OutPos[13]), Four_Threes);
    v253 = (unsigned __int16 *)pPos[1].m128_i32[3];
    v254 = v253[1];
    v255 = (float)*v253;
    v256 = v253[2];
    v257 = v253[3];
    v578 = (float)(v255 * 6.2831855) * 0.000015259022;
    v579 = (float)((float)v254 * 6.2831855) * 0.000015259022;
    v580 = (float)((float)v256 * 6.2831855) * 0.000015259022;
    v581 = (float)((float)v257 * 6.2831855) * 0.000015259022;
    if ( sShowACCGeometryTangents )
    {
LABEL_288:
      *Pos = v252;
      Pos[1] = (Vector4D)OutTanU[0];
      Pos[2] = (Vector4D)OutTanU[1];
      Pos[3] = (Vector4D)OutTanU[2];
      Pos[4] = (Vector4D)OutTanU[3];
      Pos[5] = (Vector4D)OutTanU[4];
      Pos[6] = (Vector4D)OutTanU[5];
      Pos[7] = (Vector4D)OutTanU[6];
      Pos[8] = (Vector4D)OutTanU[7];
      Pos[9] = (Vector4D)OutTanU[8];
      Pos[10] = (Vector4D)OutTanU[9];
      Pos[11] = (Vector4D)OutTanU[10];
      *TanU = (Vector4D)OutTanU[15];
      TanU[1] = (Vector4D)OutTanV[0];
      TanU[2] = (Vector4D)OutTanV[1];
      TanU[3] = (Vector4D)OutTanV[2];
      TanU[4] = (Vector4D)OutTanV[3];
      TanU[5] = (Vector4D)OutTanV[4];
      TanU[6] = (Vector4D)OutTanV[5];
      TanU[7] = (Vector4D)OutTanV[6];
      TanU[8] = (Vector4D)OutTanV[7];
      TanU[9] = (Vector4D)OutTanV[8];
      TanU[10] = (Vector4D)OutTanV[9];
      TanU[11] = (Vector4D)OutTanV[10];
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      goto LABEL_289;
    }
    LODWORD(v258) = *(unsigned __int16 *)pPos[1].m128_i32[2];
    v598 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[2];
    LODWORD(v259) = *(unsigned __int16 *)pPos[1].m128_i32[0];
    *(float *)&v599 = v258;
    LODWORD(v260) = *(unsigned __int16 *)pPos->m128_i32[1];
    v601 = 4;
    *(float *)&v594 = v259;
    v595 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[0];
    v593 = v260;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeCatmullClarkLimitTangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v261 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard';
    if ( (`ComputeCatmullClarkLimitTangents'::`2'::`local static guard' & 1) == 0 )
    {
      v261 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' | 1;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' |= 1u;
      `ComputeCatmullClarkLimitTangents'::`2'::tanUSign = (__int128)Four_Ones;
      xmmword_100B0470 = (__int128)Four_NegativeOnes;
      xmmword_100B0480 = (__int128)Four_NegativeOnes;
      xmmword_100B0490 = (__int128)Four_Ones;
    }
    if ( (v261 & 2) == 0 )
    {
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' = v261 | 2;
      `ComputeCatmullClarkLimitTangents'::`2'::tanVSign = (__int128)Four_Ones;
      xmmword_100B0430 = (__int128)Four_Ones;
      xmmword_100B0440 = (__int128)Four_NegativeOnes;
      xmmword_100B0450 = (__int128)Four_NegativeOnes;
    }
    if ( sUseCornerTangents )
      v262 = (__int16)v599;
    else
      v262 = 0;
    if ( (_WORD)v594 != 0 )
    {
      if ( v262 == 0 || v262 == 2 )
      {
        v305 = (unsigned __int16)v598;
        v306 = Four_Zeros;
        v599 = sCCLimitTanBndStencil1[v305];
        v307 = sCCLimitTanBndStencil2[v305];
        v308 = 0;
        v309 = Four_Zeros;
        if ( (_WORD)v595 != 0 )
        {
          v599 = (__m128 *)((char *)v599 - (int)v307);
          do
          {
            v594 = &v17[v584[v308]];
            v306 = _mm_add_ps(v306, _mm_mul_ps(*(__m128 *)((char *)v307 + (_DWORD)v599), *v594));
            v310 = _mm_mul_ps(*v594, *v307);
            ++v308;
            ++v307;
            v309 = _mm_add_ps(v309, v310);
          }
          while ( v308 < (unsigned __int16)v595 );
        }
        v311 = (LOWORD(v593) - 1) / 2;
        v312 = (unsigned __int16)v598 - 1;
        if ( (_WORD)v598 == 2 )
        {
          v266 = v306;
          v263 = v309;
        }
        else
        {
          v266 = _mm_add_ps(_mm_mul_ps(sCCSinPI[v311][v312], v309), _mm_mul_ps(sCCCosPI[v311][v312], v306));
          v263 = _mm_add_ps(_mm_mul_ps(sCCSinPI[v311 + 1][v312], v309), _mm_mul_ps(sCCCosPI[v311 + 1][v312], v306));
        }
      }
      else
      {
        if ( (_WORD)v598 == 2 )
          goto LABEL_189;
        v270 = *v584;
        v271 = _mm_sub_ps(v17[v584[1]], v17[v270]);
        v594 = (__m128 *)(unsigned __int16)v598;
        v599 = &v17[v270];
        v272 = v584;
        v273 = sPosEdge1Stencil[(unsigned __int16)v598];
        v274 = *v273;
        v275 = _mm_sub_ps(v17[v584[(unsigned __int16)v595 - 1]], *v599);
        v597 = v273 + 1;
        v276 = _mm_mul_ps(*v599, _mm_sub_ps(v274, Four_Ones));
        v277 = v276;
        v278 = 1;
        v596 = (int)&v584[(unsigned __int16)v595 - 5];
        while ( 1 )
        {
          v279 = v272[v278];
          v280 = *v597++;
          v276 = _mm_add_ps(v276, _mm_mul_ps(v280, v17[v279]));
          ++v278;
          v277 = _mm_add_ps(v277, _mm_mul_ps(v17[*(unsigned __int16 *)v596], v280));
          v596 += 2;
          if ( v278 >= 6 )
            break;
          v272 = v584;
        }
        v281 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v276, v276, 210), _mm_shuffle_ps(v271, v271, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v276, v276, 201), _mm_shuffle_ps(v271, v271, 210)));
        v537 = _mm_mul_ps(v281, v281);
        v282 = 0;
        v282.m128_f32[0] = (float)(v537.m128_f32[1] + v537.m128_f32[0]) + v537.m128_f32[2];
        v283 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v277, v277, 201), _mm_shuffle_ps(v275, v275, 210)),
                 _mm_mul_ps(_mm_shuffle_ps(v277, v277, 210), _mm_shuffle_ps(v275, v275, 201)));
        v561 = _mm_mul_ps(v283, v283);
        v284 = 0;
        v284.m128_f32[0] = (float)(v561.m128_f32[1] + v561.m128_f32[0]) + v561.m128_f32[2];
        v285 = _mm_add_ps(
                 _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v284, v284, 0)), v283),
                 _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v282, v282, 0)), v281));
        v562 = _mm_mul_ps(v285, v285);
        v286 = 0;
        v286.m128_f32[0] = (float)(v562.m128_f32[1] + v562.m128_f32[0]) + v562.m128_f32[2];
        v287 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v286, v286, 0)), v285);
        v288 = 0;
        v558 = _mm_mul_ps(v287, v271);
        v288.m128_f32[0] = (float)(v558.m128_f32[1] + v558.m128_f32[0]) + v558.m128_f32[2];
        v556 = _mm_mul_ps(v287, v275);
        v289 = 0;
        v289.m128_f32[0] = (float)(v556.m128_f32[1] + v556.m128_f32[0]) + v556.m128_f32[2];
        v290 = _mm_sub_ps(v271, _mm_mul_ps(_mm_shuffle_ps(v288, v288, 0), v287));
        v291 = _mm_sub_ps(v275, _mm_mul_ps(_mm_shuffle_ps(v289, v289, 0), v287));
        v554 = _mm_mul_ps(v290, v290);
        v292 = 0;
        v292.m128_f32[0] = (float)(v554.m128_f32[1] + v554.m128_f32[0]) + v554.m128_f32[2];
        v293 = _mm_rsqrt_ps(_mm_shuffle_ps(v292, v292, 0));
        v552 = _mm_mul_ps(v291, v291);
        v294 = _mm_div_ps(v290, v293);
        v295 = 0;
        v295.m128_f32[0] = (float)(v552.m128_f32[1] + v552.m128_f32[0]) + v552.m128_f32[2];
        v296 = _mm_rsqrt_ps(_mm_shuffle_ps(v295, v295, 0));
        v297 = _mm_div_ps(v291, v296);
        OutPos[15] = _mm_mul_ps(_mm_add_ps(v296, v293), Four_PointFives);
        u20 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v287, v287, 201), _mm_shuffle_ps(v294, v294, 210)),
                _mm_mul_ps(_mm_shuffle_ps(v287, v287, 210), _mm_shuffle_ps(v294, v294, 201)));
        v548 = _mm_mul_ps(u20, v297);
        v298 = 0;
        v298.m128_f32[0] = (float)(v548.m128_f32[1] + v548.m128_f32[0]) + v548.m128_f32[2];
        v570 = v294;
        v546 = _mm_mul_ps(v297, v294);
        __libm_sse2_atan2(y: *(long double *)&v602[4], x: *(long double *)&v602[12]);
        v299 = LOWORD(v593) - 1;
        v298.m128_f32[0] = 3.14159265 - _mm_shuffle_ps(v298, v298, 0).m128_f32[0];
        pOneRing[1] = (unsigned __int16 *)v298.m128_i32[0];
        v578 = v298.m128_f32[0];
        v590 = (__m128 *)(v299 / 2 + 1);
        v294.m128_f32[0] = 1.0 / *(&vec4_invalid_8.w + (_DWORD)v594);
        *(float *)&v599 = (float)((float)(v299 / 2) * v298.m128_f32[0]) * v294.m128_f32[0];
        v594 = (__m128 *)v294.m128_i32[0];
        __libm_sse2_cos(x: *(long double *)&v602[4]);
        v287.m128_f32[0] = (float)((float)(v299 / 2) * v298.m128_f32[0]) * v294.m128_f32[0];
        v300 = 0;
        v300.m128_f32[0] = v287.m128_f32[0];
        c0 = v300;
        *(double *)v287.m128_u64 = *(float *)&v599;
        __libm_sse2_sin(x: *(long double *)&v602[4]);
        v287.m128_f32[0] = *(double *)v287.m128_u64;
        v301 = 0;
        *(float *)&v301 = v287.m128_f32[0];
        *(float *)&v599 = (float)((float)(int)v590 * *(float *)&pOneRing[1]) * *(float *)&v594;
        *(_OWORD *)&flLoopGap[2] = v301;
        *(double *)v287.m128_u64 = *(float *)&v599;
        __libm_sse2_cos(x: *(long double *)&v602[4]);
        v287.m128_f32[0] = *(double *)v287.m128_u64;
        v302 = 0;
        v302.m128_f32[0] = v287.m128_f32[0];
        v571 = _mm_shuffle_ps(v302, v302, 0);
        *(double *)v287.m128_u64 = *(float *)&v599;
        __libm_sse2_sin(x: *(long double *)&v602[4]);
        v287.m128_f32[0] = *(double *)v287.m128_u64;
        v303 = 0;
        v303.m128_f32[0] = v287.m128_f32[0];
        v304 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&flLoopGap[2], *(__m128 *)&flLoopGap[2], 0), u20);
        *(__m128 *)&flLoopGap[2] = _mm_shuffle_ps(c0, c0, 0);
        v266 = _mm_mul_ps(_mm_add_ps(v304, _mm_mul_ps(*(__m128 *)&flLoopGap[2], v570)), OutPos[15]);
        v263 = _mm_mul_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v303, v303, 0), u20), _mm_mul_ps(v571, v570)),
                 OutPos[15]);
      }
    }
    else
    {
      v263 = Four_Zeros;
      v264 = (unsigned __int16)v598;
      v599 = sCCLimitTanStencil1[v264];
      v265 = 0;
      v266 = Four_Zeros;
      v267 = sCCLimitTanStencil2[v264];
      OutTanU[15] = Four_Zeros;
      v532 = Four_Zeros;
      v596 = 0;
      if ( (_WORD)v595 != 0 )
      {
        v599 = (__m128 *)((char *)v599 - (int)v267);
        v268 = v267;
        do
        {
          v266 = _mm_add_ps(v266, _mm_mul_ps(*(__m128 *)((char *)v268 + (_DWORD)v599), v17[v584[v265]]));
          v532 = v266;
          v269 = _mm_mul_ps(*v268, v17[v584[v596]]);
          v265 = v596 + 1;
          ++v268;
          v263 = _mm_add_ps(v263, v269);
          OutTanU[15] = v263;
          v596 = v265;
        }
        while ( v265 < (unsigned __int16)v595 );
      }
    }
    v532 = _mm_mul_ps(v266, (__m128)`ComputeCatmullClarkLimitTangents'::`2'::tanUSign);
    OutTanU[15] = _mm_mul_ps(v263, (__m128)`ComputeCatmullClarkLimitTangents'::`2'::tanVSign);
LABEL_189:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    LODWORD(v313) = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 2);
    v598 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 2);
    LODWORD(v314) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 2);
    *(_DWORD *)v602 = 4;
    *(float *)&v599 = v313;
    LODWORD(v315) = *(unsigned __int16 *)(pPos->m128_i32[1] + 2);
    v601 = 0;
    *(float *)&v594 = v314;
    v316 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 2);
    v593 = v315;
    v595 = v316;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeCatmullClarkLimitTangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v317 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard';
    if ( (`ComputeCatmullClarkLimitTangents'::`2'::`local static guard' & 1) != 0 )
    {
      v318 = (__m128)xmmword_100B0470;
    }
    else
    {
      v317 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' | 1;
      v318 = Four_NegativeOnes;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' |= 1u;
      `ComputeCatmullClarkLimitTangents'::`2'::tanUSign = (__int128)Four_Ones;
      xmmword_100B0470 = (__int128)Four_NegativeOnes;
      xmmword_100B0480 = (__int128)Four_NegativeOnes;
      xmmword_100B0490 = (__int128)Four_Ones;
    }
    if ( (v317 & 2) == 0 )
    {
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' = v317 | 2;
      `ComputeCatmullClarkLimitTangents'::`2'::tanVSign = (__int128)Four_Ones;
      xmmword_100B0430 = (__int128)Four_Ones;
      xmmword_100B0440 = (__int128)Four_NegativeOnes;
      xmmword_100B0450 = (__int128)Four_NegativeOnes;
    }
    if ( sUseCornerTangents )
      v319 = (__int16)v599;
    else
      v319 = 0;
    if ( (_WORD)v594 != 0 )
    {
      if ( v319 == 0 || v319 == 2 )
      {
        v362 = (unsigned __int16)v598;
        v363 = Four_Zeros;
        v599 = sCCLimitTanBndStencil1[v362];
        v364 = sCCLimitTanBndStencil2[v362];
        v365 = 0;
        v366 = Four_Zeros;
        if ( (_WORD)v595 != 0 )
        {
          v599 = (__m128 *)((char *)v599 - (int)v364);
          do
          {
            v594 = &v17[v585[v365]];
            v363 = _mm_add_ps(v363, _mm_mul_ps(*(__m128 *)((char *)v364 + (_DWORD)v599), *v594));
            v367 = _mm_mul_ps(*v594, *v364);
            ++v365;
            ++v364;
            v366 = _mm_add_ps(v366, v367);
          }
          while ( v365 < (unsigned __int16)v595 );
        }
        v368 = (LOWORD(v593) - 1) / 2;
        v369 = (unsigned __int16)v598 - 1;
        if ( (_WORD)v598 == 2 )
        {
          v323 = v363;
          v321 = v366;
        }
        else
        {
          v323 = _mm_add_ps(_mm_mul_ps(sCCSinPI[v368][v369], v366), _mm_mul_ps(sCCCosPI[v368][v369], v363));
          v321 = _mm_add_ps(_mm_mul_ps(sCCSinPI[v368 + 1][v369], v366), _mm_mul_ps(sCCCosPI[v368 + 1][v369], v363));
        }
      }
      else
      {
        if ( (_WORD)v598 == 2 )
          goto LABEL_216;
        v327 = v585;
        v596 = (int)&v17[*v585];
        v328 = _mm_sub_ps(v17[v585[1]], *(__m128 *)v596);
        v329 = v585[(unsigned __int16)v595 - 1];
        v599 = (__m128 *)(unsigned __int16)v598;
        v330 = sPosEdge1Stencil[(unsigned __int16)v598];
        v331 = *v330;
        v332 = _mm_sub_ps(v17[v329], *(__m128 *)v596);
        v597 = v330 + 1;
        v333 = _mm_mul_ps(_mm_sub_ps(v331, Four_Ones), *(__m128 *)v596);
        v334 = v333;
        v335 = 1;
        v596 = (int)&v585[(unsigned __int16)v595 - 5];
        while ( 1 )
        {
          v336 = v327[v335];
          v337 = *v597++;
          v333 = _mm_add_ps(v333, _mm_mul_ps(v17[v336], v337));
          ++v335;
          v334 = _mm_add_ps(v334, _mm_mul_ps(v17[*(unsigned __int16 *)v596], v337));
          v596 += 2;
          if ( v335 >= 6 )
            break;
          v327 = v585;
        }
        v338 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v333, v333, 210), _mm_shuffle_ps(v328, v328, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v333, v333, 201), _mm_shuffle_ps(v328, v328, 210)));
        v544 = _mm_mul_ps(v338, v338);
        v339 = 0;
        v339.m128_f32[0] = (float)(v544.m128_f32[1] + v544.m128_f32[0]) + v544.m128_f32[2];
        v340 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v334, v334, 201), _mm_shuffle_ps(v332, v332, 210)),
                 _mm_mul_ps(_mm_shuffle_ps(v334, v334, 210), _mm_shuffle_ps(v332, v332, 201)));
        v542 = _mm_mul_ps(v340, v340);
        v341 = 0;
        v341.m128_f32[0] = (float)(v542.m128_f32[1] + v542.m128_f32[0]) + v542.m128_f32[2];
        v342 = _mm_add_ps(
                 _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v339, v339, 0)), v338),
                 _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v341, v341, 0)), v340));
        v540 = _mm_mul_ps(v342, v342);
        v343 = 0;
        v343.m128_f32[0] = (float)(v540.m128_f32[1] + v540.m128_f32[0]) + v540.m128_f32[2];
        v344 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v343, v343, 0)), v342);
        v345 = 0;
        v538 = _mm_mul_ps(v344, v328);
        v345.m128_f32[0] = (float)(v538.m128_f32[1] + v538.m128_f32[0]) + v538.m128_f32[2];
        v536 = _mm_mul_ps(v344, v332);
        v346 = 0;
        v346.m128_f32[0] = (float)(v536.m128_f32[1] + v536.m128_f32[0]) + v536.m128_f32[2];
        v347 = _mm_sub_ps(v328, _mm_mul_ps(_mm_shuffle_ps(v345, v345, 0), v344));
        v348 = _mm_sub_ps(v332, _mm_mul_ps(_mm_shuffle_ps(v346, v346, 0), v344));
        OutTanV[15] = _mm_mul_ps(v347, v347);
        v349 = 0;
        v349.m128_f32[0] = (float)(OutTanV[15].m128_f32[1] + OutTanV[15].m128_f32[0]) + OutTanV[15].m128_f32[2];
        v350 = _mm_rsqrt_ps(_mm_shuffle_ps(v349, v349, 0));
        v547 = _mm_mul_ps(v348, v348);
        v351 = _mm_div_ps(v347, v350);
        v352 = 0;
        v352.m128_f32[0] = (float)(v547.m128_f32[1] + v547.m128_f32[0]) + v547.m128_f32[2];
        v353 = _mm_rsqrt_ps(_mm_shuffle_ps(v352, v352, 0));
        v354 = _mm_div_ps(v348, v353);
        OutPos[15] = _mm_mul_ps(_mm_add_ps(v353, v350), Four_PointFives);
        u20 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v344, v344, 201), _mm_shuffle_ps(v351, v351, 210)),
                _mm_mul_ps(_mm_shuffle_ps(v344, v344, 210), _mm_shuffle_ps(v351, v351, 201)));
        v550 = _mm_mul_ps(u20, v354);
        v355 = 0;
        v355.m128_f32[0] = (float)(v550.m128_f32[1] + v550.m128_f32[0]) + v550.m128_f32[2];
        v570 = v351;
        v560 = _mm_mul_ps(v354, v351);
        __libm_sse2_atan2(y: *(long double *)&v602[4], x: *(long double *)&v602[12]);
        v356 = LOWORD(v593) - 1;
        v354.m128_f32[0] = 3.14159265 - _mm_shuffle_ps(v355, v355, 0).m128_f32[0];
        v351.m128_f32[0] = 1.0 / *(&vec4_invalid_8.w + (_DWORD)v599);
        v590 = (__m128 *)v354.m128_i32[0];
        v579 = v354.m128_f32[0];
        v594 = (__m128 *)(v356 / 2 + 1);
        *(float *)&v599 = (float)((float)(v356 / 2) * v354.m128_f32[0]) * v351.m128_f32[0];
        pOneRing[1] = (unsigned __int16 *)v351.m128_i32[0];
        __libm_sse2_cos(x: *(long double *)&v602[4]);
        v344.m128_f32[0] = (float)((float)(v356 / 2) * v354.m128_f32[0]) * v351.m128_f32[0];
        v357 = 0;
        v357.m128_f32[0] = v344.m128_f32[0];
        c0 = v357;
        *(double *)v344.m128_u64 = *(float *)&v599;
        __libm_sse2_sin(x: *(long double *)&v602[4]);
        v344.m128_f32[0] = *(double *)v344.m128_u64;
        v358 = 0;
        *(float *)&v358 = v344.m128_f32[0];
        *(float *)&v599 = (float)((float)(int)v594 * *(float *)&v590) * *(float *)&pOneRing[1];
        *(_OWORD *)&flLoopGap[2] = v358;
        *(double *)v344.m128_u64 = *(float *)&v599;
        __libm_sse2_cos(x: *(long double *)&v602[4]);
        v344.m128_f32[0] = *(double *)v344.m128_u64;
        v359 = 0;
        v359.m128_f32[0] = v344.m128_f32[0];
        v571 = _mm_shuffle_ps(v359, v359, 0);
        *(double *)v344.m128_u64 = *(float *)&v599;
        __libm_sse2_sin(x: *(long double *)&v602[4]);
        v344.m128_f32[0] = *(double *)v344.m128_u64;
        v360 = 0;
        v360.m128_f32[0] = v344.m128_f32[0];
        v361 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&flLoopGap[2], *(__m128 *)&flLoopGap[2], 0), u20);
        *(__m128 *)&flLoopGap[2] = _mm_shuffle_ps(c0, c0, 0);
        v323 = _mm_mul_ps(_mm_add_ps(v361, _mm_mul_ps(*(__m128 *)&flLoopGap[2], v570)), OutPos[15]);
        v318 = (__m128)xmmword_100B0470;
        v321 = _mm_mul_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v360, v360, 0), u20), _mm_mul_ps(v571, v570)),
                 OutPos[15]);
      }
    }
    else
    {
      v320 = (unsigned __int16)v598;
      v321 = Four_Zeros;
      v599 = sCCLimitTanStencil1[v320];
      v322 = 0;
      v323 = Four_Zeros;
      v324 = sCCLimitTanStencil2[v320];
      OutTanV[2] = Four_Zeros;
      OutTanU[1] = Four_Zeros;
      v596 = 0;
      if ( (_WORD)v595 != 0 )
      {
        v599 = (__m128 *)((char *)v599 - (int)v324);
        v325 = v324;
        do
        {
          v323 = _mm_add_ps(v323, _mm_mul_ps(*(__m128 *)((char *)v325 + (_DWORD)v599), v17[v585[v322]]));
          OutTanU[1] = v323;
          v326 = _mm_mul_ps(*v325, v17[v585[v596]]);
          v322 = v596 + 1;
          ++v325;
          v321 = _mm_add_ps(v321, v326);
          OutTanV[2] = v321;
          v596 = v322;
        }
        while ( v322 < (unsigned __int16)v595 );
      }
    }
    OutTanU[1] = _mm_mul_ps(v318, v321);
    OutTanV[2] = _mm_mul_ps(v323, (__m128)xmmword_100B0430);
LABEL_216:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    LODWORD(v370) = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 4);
    v598 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 4);
    LODWORD(v371) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 4);
    *(_DWORD *)v602 = 4;
    *(float *)&v599 = v370;
    LODWORD(v372) = *(unsigned __int16 *)(pPos->m128_i32[1] + 4);
    v601 = 0;
    *(float *)&v594 = v371;
    v373 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 4);
    v593 = v372;
    v595 = v373;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeCatmullClarkLimitTangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v374 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard';
    if ( (`ComputeCatmullClarkLimitTangents'::`2'::`local static guard' & 1) == 0 )
    {
      v374 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' | 1;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' |= 1u;
      `ComputeCatmullClarkLimitTangents'::`2'::tanUSign = (__int128)Four_Ones;
      xmmword_100B0470 = (__int128)Four_NegativeOnes;
      xmmword_100B0480 = (__int128)Four_NegativeOnes;
      xmmword_100B0490 = (__int128)Four_Ones;
    }
    if ( (v374 & 2) == 0 )
    {
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' = v374 | 2;
      `ComputeCatmullClarkLimitTangents'::`2'::tanVSign = (__int128)Four_Ones;
      xmmword_100B0430 = (__int128)Four_Ones;
      xmmword_100B0440 = (__int128)Four_NegativeOnes;
      xmmword_100B0450 = (__int128)Four_NegativeOnes;
    }
    if ( sUseCornerTangents )
      v375 = (__int16)v599;
    else
      v375 = 0;
    if ( (_WORD)v594 != 0 )
    {
      if ( v375 == 0 || v375 == 2 )
      {
        v418 = (unsigned __int16)v598;
        v419 = Four_Zeros;
        v599 = sCCLimitTanBndStencil1[v418];
        v420 = sCCLimitTanBndStencil2[v418];
        v421 = 0;
        v422 = Four_Zeros;
        if ( (_WORD)v595 != 0 )
        {
          v599 = (__m128 *)((char *)v599 - (int)v420);
          do
          {
            v594 = &v17[v586[v421]];
            v419 = _mm_add_ps(v419, _mm_mul_ps(*(__m128 *)((char *)v420 + (_DWORD)v599), *v594));
            v423 = _mm_mul_ps(*v594, *v420);
            ++v421;
            ++v420;
            v422 = _mm_add_ps(v422, v423);
          }
          while ( v421 < (unsigned __int16)v595 );
        }
        v424 = (LOWORD(v593) - 1) / 2;
        v425 = (unsigned __int16)v598 - 1;
        if ( (_WORD)v598 == 2 )
        {
          v380 = v419;
          v377 = v422;
        }
        else
        {
          v380 = _mm_add_ps(_mm_mul_ps(sCCSinPI[v424][v425], v422), _mm_mul_ps(sCCCosPI[v424][v425], v419));
          v377 = _mm_add_ps(_mm_mul_ps(sCCSinPI[v424 + 1][v425], v422), _mm_mul_ps(sCCCosPI[v424 + 1][v425], v419));
        }
      }
      else
      {
        if ( (_WORD)v598 == 2 )
          goto LABEL_242;
        v383 = *v586;
        v384 = _mm_sub_ps(v17[v586[1]], v17[v383]);
        v594 = (__m128 *)(unsigned __int16)v598;
        v599 = &v17[v383];
        v385 = v586;
        v386 = sPosEdge1Stencil[(unsigned __int16)v598];
        v387 = *v386;
        v388 = _mm_sub_ps(v17[v586[(unsigned __int16)v595 - 1]], *v599);
        v597 = v386 + 1;
        v389 = _mm_mul_ps(*v599, _mm_sub_ps(v387, Four_Ones));
        v390 = v389;
        v391 = 1;
        v596 = (int)&v586[(unsigned __int16)v595 - 5];
        while ( 1 )
        {
          v392 = v385[v391];
          v393 = *v597++;
          ++v391;
          v389 = _mm_add_ps(v389, _mm_mul_ps(v17[v392], v393));
          v390 = _mm_add_ps(v390, _mm_mul_ps(v393, v17[*(unsigned __int16 *)v596]));
          v596 += 2;
          if ( v391 >= 6 )
            break;
          v385 = v586;
        }
        v394 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v389, v389, 210), _mm_shuffle_ps(v384, v384, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v389, v389, 201), _mm_shuffle_ps(v384, v384, 210)));
        v559 = _mm_mul_ps(v394, v394);
        v395 = 0;
        v395.m128_f32[0] = (float)(v559.m128_f32[1] + v559.m128_f32[0]) + v559.m128_f32[2];
        v396 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v390, v390, 201), _mm_shuffle_ps(v388, v388, 210)),
                 _mm_mul_ps(_mm_shuffle_ps(v390, v390, 210), _mm_shuffle_ps(v388, v388, 201)));
        v563 = _mm_mul_ps(v396, v396);
        v397 = 0;
        v397.m128_f32[0] = (float)(v563.m128_f32[1] + v563.m128_f32[0]) + v563.m128_f32[2];
        v398 = _mm_add_ps(
                 _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v397, v397, 0)), v396),
                 _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v395, v395, 0)), v394));
        v557 = _mm_mul_ps(v398, v398);
        v399 = 0;
        v399.m128_f32[0] = (float)(v557.m128_f32[1] + v557.m128_f32[0]) + v557.m128_f32[2];
        v400 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v399, v399, 0)), v398);
        v401 = 0;
        v545 = _mm_mul_ps(v400, v384);
        v401.m128_f32[0] = (float)(v545.m128_f32[1] + v545.m128_f32[0]) + v545.m128_f32[2];
        v555 = _mm_mul_ps(v400, v388);
        v402 = 0;
        v402.m128_f32[0] = (float)(v555.m128_f32[1] + v555.m128_f32[0]) + v555.m128_f32[2];
        v403 = _mm_sub_ps(v384, _mm_mul_ps(_mm_shuffle_ps(v401, v401, 0), v400));
        v404 = _mm_sub_ps(v388, _mm_mul_ps(_mm_shuffle_ps(v402, v402, 0), v400));
        v539 = _mm_mul_ps(v403, v403);
        v405 = 0;
        v405.m128_f32[0] = (float)(v539.m128_f32[1] + v539.m128_f32[0]) + v539.m128_f32[2];
        v406 = _mm_rsqrt_ps(_mm_shuffle_ps(v405, v405, 0));
        v553 = _mm_mul_ps(v404, v404);
        v407 = _mm_div_ps(v403, v406);
        v408 = 0;
        v408.m128_f32[0] = (float)(v553.m128_f32[1] + v553.m128_f32[0]) + v553.m128_f32[2];
        v409 = _mm_rsqrt_ps(_mm_shuffle_ps(v408, v408, 0));
        v410 = _mm_div_ps(v404, v409);
        OutPos[15] = _mm_mul_ps(_mm_add_ps(v409, v406), Four_PointFives);
        u20 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v400, v400, 201), _mm_shuffle_ps(v407, v407, 210)),
                _mm_mul_ps(_mm_shuffle_ps(v400, v400, 210), _mm_shuffle_ps(v407, v407, 201)));
        v543 = _mm_mul_ps(u20, v410);
        v411 = 0;
        v411.m128_f32[0] = (float)(v543.m128_f32[1] + v543.m128_f32[0]) + v543.m128_f32[2];
        v570 = v407;
        v551 = _mm_mul_ps(v410, v407);
        __libm_sse2_atan2(y: *(long double *)&v602[4], x: *(long double *)&v602[12]);
        v412 = LOWORD(v593) - 1;
        v410.m128_f32[0] = 3.14159265 - _mm_shuffle_ps(v411, v411, 0).m128_f32[0];
        v407.m128_f32[0] = 1.0 / *(&vec4_invalid_8.w + (_DWORD)v594);
        pOneRing[1] = (unsigned __int16 *)v410.m128_i32[0];
        v580 = v410.m128_f32[0];
        v590 = (__m128 *)(v412 / 2 + 1);
        *(float *)&v599 = (float)((float)(v412 / 2) * v410.m128_f32[0]) * v407.m128_f32[0];
        v594 = (__m128 *)v407.m128_i32[0];
        __libm_sse2_cos(x: *(long double *)&v602[4]);
        v400.m128_f32[0] = (float)((float)(v412 / 2) * v410.m128_f32[0]) * v407.m128_f32[0];
        v413 = 0;
        v413.m128_f32[0] = v400.m128_f32[0];
        c0 = v413;
        *(double *)v400.m128_u64 = *(float *)&v599;
        __libm_sse2_sin(x: *(long double *)&v602[4]);
        v400.m128_f32[0] = *(double *)v400.m128_u64;
        v414 = 0;
        *(float *)&v414 = v400.m128_f32[0];
        *(float *)&v599 = (float)((float)(int)v590 * *(float *)&pOneRing[1]) * *(float *)&v594;
        *(_OWORD *)&flLoopGap[2] = v414;
        *(double *)v400.m128_u64 = *(float *)&v599;
        __libm_sse2_cos(x: *(long double *)&v602[4]);
        v400.m128_f32[0] = *(double *)v400.m128_u64;
        v415 = 0;
        v415.m128_f32[0] = v400.m128_f32[0];
        v571 = _mm_shuffle_ps(v415, v415, 0);
        *(double *)v400.m128_u64 = *(float *)&v599;
        __libm_sse2_sin(x: *(long double *)&v602[4]);
        v400.m128_f32[0] = *(double *)v400.m128_u64;
        v416 = 0;
        v416.m128_f32[0] = v400.m128_f32[0];
        v417 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&flLoopGap[2], *(__m128 *)&flLoopGap[2], 0), u20);
        *(__m128 *)&flLoopGap[2] = _mm_shuffle_ps(c0, c0, 0);
        v380 = _mm_mul_ps(_mm_add_ps(v417, _mm_mul_ps(*(__m128 *)&flLoopGap[2], v570)), OutPos[15]);
        v377 = _mm_mul_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v416, v416, 0), u20), _mm_mul_ps(v571, v570)),
                 OutPos[15]);
      }
    }
    else
    {
      v376 = (unsigned __int16)v598;
      v377 = Four_Zeros;
      v378 = sCCLimitTanStencil1[v376];
      v596 = (int)sCCLimitTanStencil2[v376];
      *(float *)&v379 = 0.0;
      v380 = Four_Zeros;
      OutTanV[10] = Four_Zeros;
      OutTanU[10] = Four_Zeros;
      v593 = 0.0;
      if ( (_WORD)v595 != 0 )
      {
        v381 = (__m128 *)v596;
        v599 = (__m128 *)((char *)v378 - v596);
        do
        {
          v380 = _mm_add_ps(v380, _mm_mul_ps(*(__m128 *)((char *)v381 + (_DWORD)v599), v17[v586[v379]]));
          OutTanU[10] = v380;
          v382 = _mm_mul_ps(v17[v586[LODWORD(v593)]], *v381);
          v379 = LODWORD(v593) + 1;
          ++v381;
          v377 = _mm_add_ps(v377, v382);
          OutTanV[10] = v377;
          v593 = *(float *)&v379;
        }
        while ( v379 < (unsigned __int16)v595 );
      }
    }
    OutTanU[10] = _mm_mul_ps(v380, (__m128)xmmword_100B0480);
    OutTanV[10] = _mm_mul_ps(v377, (__m128)xmmword_100B0440);
LABEL_242:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    LODWORD(v426) = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 6);
    v598 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 6);
    LODWORD(v427) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 6);
    *(_DWORD *)&v602[16] = 4;
    *(float *)&v599 = v426;
    LODWORD(v428) = *(unsigned __int16 *)(pPos->m128_i32[1] + 6);
    *(_DWORD *)&v602[12] = 0;
    *(float *)&v594 = v427;
    v429 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 6);
    v593 = v428;
    v595 = v429;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeCatmullClarkLimitTangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v430 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard';
    if ( (`ComputeCatmullClarkLimitTangents'::`2'::`local static guard' & 1) == 0 )
    {
      v430 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' | 1;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' |= 1u;
      `ComputeCatmullClarkLimitTangents'::`2'::tanUSign = (__int128)Four_Ones;
      xmmword_100B0470 = (__int128)Four_NegativeOnes;
      xmmword_100B0480 = (__int128)Four_NegativeOnes;
      xmmword_100B0490 = (__int128)Four_Ones;
    }
    if ( (v430 & 2) == 0 )
    {
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' = v430 | 2;
      `ComputeCatmullClarkLimitTangents'::`2'::tanVSign = (__int128)Four_Ones;
      xmmword_100B0430 = (__int128)Four_Ones;
      xmmword_100B0440 = (__int128)Four_NegativeOnes;
      xmmword_100B0450 = (__int128)Four_NegativeOnes;
    }
    if ( sUseCornerTangents )
      v431 = (__int16)v599;
    else
      v431 = 0;
    if ( (_WORD)v594 != 0 )
    {
      if ( v431 == 0 || v431 == 2 )
      {
        v474 = (unsigned __int16)v598;
        v475 = Four_Zeros;
        v476 = (unsigned __int16)v598;
        v594 = sCCLimitTanBndStencil1[v476];
        v599 = sCCLimitTanBndStencil2[v476];
        v477 = 0;
        v478 = Four_Zeros;
        if ( (_WORD)v595 != 0 )
        {
          v594 = (__m128 *)((char *)v594 - (int)v599);
          v479 = v599;
          do
          {
            v599 = &v17[v587[v477]];
            v475 = _mm_add_ps(v475, _mm_mul_ps(*(__m128 *)((char *)v479 + (_DWORD)v594), *v599));
            v480 = _mm_mul_ps(*v479, *v599);
            ++v477;
            ++v479;
            v478 = _mm_add_ps(v478, v480);
          }
          while ( v477 < (unsigned __int16)v595 );
          v474 = (unsigned __int16)v598;
        }
        v481 = (LOWORD(v593) - 1) / 2;
        v482 = v474 - 1;
        if ( v474 == 2 )
        {
          v436 = v475;
          v433 = v478;
        }
        else
        {
          v436 = _mm_add_ps(_mm_mul_ps(sCCSinPI[v481][v482], v478), _mm_mul_ps(sCCCosPI[v481][v482], v475));
          v433 = _mm_add_ps(_mm_mul_ps(sCCSinPI[v481 + 1][v482], v478), _mm_mul_ps(sCCCosPI[v481 + 1][v482], v475));
        }
      }
      else
      {
        if ( (_WORD)v598 == 2 )
        {
LABEL_269:
          CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
          if ( (_S1_0 & 1) == 0 )
          {
            _S1_0 |= 1u;
            CB_sign[0] = Four_Ones;
            xmmword_100B04C0 = (__int128)Four_NegativeOnes;
            xmmword_100B04D0 = (__int128)Four_Ones;
            xmmword_100B04E0 = (__int128)Four_NegativeOnes;
          }
          u10 = *(&v532 + CB_CornerIdx[0]);
          v483 = (unsigned __int16 *)pPos->m128_i32[2];
          v484 = v483[1];
          v574 = _mm_mul_ps(*(&v532 + dword_100893B0), Four_Twos);
          v485 = *v483;
          v486 = (_WORD *)pPos[1].m128_i32[0];
          v22 = *v486 == 0;
          u00 = *(&v532 + dword_100893B4);
          if ( !v22 )
            --v485;
          if ( v486[1] != 0 )
            --v484;
          v487 = (float)(v578 / (float)v485);
          __libm_sse2_cos(x: *(long double *)v602);
          *(float *)&v487 = v487;
          v488 = 0;
          v488.m128_f32[0] = *(float *)&v487;
          v572 = _mm_shuffle_ps(v488, v488, 0);
          v489 = (float)(v579 / (float)v484);
          __libm_sse2_cos(x: *(long double *)v602);
          *(float *)&v489 = v489;
          v490 = dword_100893B8;
          v491 = 0;
          v491.m128_f32[0] = *(float *)&v489;
          v492 = _mm_shuffle_ps(v491, v491, 0);
          v493 = _mm_sub_ps(_mm_mul_ps(v572, u00), _mm_mul_ps(v492, v574));
          OutTanU[CB_InteriorIdx[0] + 15] = _mm_add_ps(
                                              OutTanU[CB_InteriorIdx[0] + 15],
                                              _mm_div_ps(
                                                _mm_sub_ps(_mm_mul_ps(v572, v574), _mm_mul_ps(v492, u10)),
                                                Four_Threes));
          OutTanU[dword_10089390 + 15] = _mm_add_ps(OutTanU[dword_10089390 + 15], _mm_div_ps(v493, Four_Threes));
          u10 = OutTanU[v490 + 15];
          v574 = _mm_mul_ps(OutTanU[dword_100893BC + 15], Four_Twos);
          v494 = pPos->m128_i32[2];
          v495 = *(unsigned __int16 *)(v494 + 2);
          v496 = *(unsigned __int16 *)(v494 + 4);
          v497 = pPos[1].m128_i32[0];
          v22 = *(_WORD *)(v497 + 2) == 0;
          u00 = OutTanU[dword_100893C0 + 15];
          if ( !v22 )
            --v495;
          if ( *(_WORD *)(v497 + 4) != 0 )
            --v496;
          v498 = (float)(v579 / (float)v495);
          __libm_sse2_cos(x: *(long double *)v602);
          *(float *)&v498 = v498;
          v499 = 0;
          v499.m128_f32[0] = *(float *)&v498;
          v572 = _mm_shuffle_ps(v499, v499, 0);
          v500 = (float)(v580 / (float)v496);
          __libm_sse2_cos(x: *(long double *)v602);
          *(float *)&v500 = v500;
          v501 = dword_100893C4;
          v502 = 0;
          v502.m128_f32[0] = *(float *)&v500;
          v503 = dword_100893CC;
          v504 = _mm_shuffle_ps(v502, v502, 0);
          v505 = _mm_sub_ps(_mm_mul_ps(v572, u00), _mm_mul_ps(v504, v574));
          *(&v532 + dword_10089394) = _mm_sub_ps(
                                        *(&v532 + dword_10089394),
                                        _mm_div_ps(
                                          _mm_sub_ps(_mm_mul_ps(v572, v574), _mm_mul_ps(v504, u10)),
                                          Four_Threes));
          *(&v532 + dword_10089398) = _mm_sub_ps(*(&v532 + dword_10089398), _mm_div_ps(v505, Four_Threes));
          u10 = *(&v532 + v501);
          v506 = pPos->m128_i32[2];
          v507 = *(unsigned __int16 *)(v506 + 4);
          v508 = *(unsigned __int16 *)(v506 + 6);
          v509 = pPos[1].m128_i32[0];
          v22 = *(_WORD *)(v509 + 4) == 0;
          v574 = _mm_mul_ps(*(&v532 + dword_100893C8), Four_Twos);
          u00 = *(&v532 + v503);
          if ( !v22 )
            --v507;
          if ( *(_WORD *)(v509 + 6) != 0 )
            --v508;
          v510 = (float)(v580 / (float)v507);
          __libm_sse2_cos(x: *(long double *)v602);
          *(float *)&v510 = v510;
          v511 = 0;
          v511.m128_f32[0] = *(float *)&v510;
          v572 = _mm_shuffle_ps(v511, v511, 0);
          v512 = (float)(v581 / (float)v508);
          __libm_sse2_cos(x: *(long double *)v602);
          *(float *)&v512 = v512;
          v513 = 0;
          v513.m128_f32[0] = *(float *)&v512;
          v514 = _mm_shuffle_ps(v513, v513, 0);
          v515 = dword_100893D8;
          v516 = _mm_mul_ps(v572, u00);
          v517 = _mm_mul_ps(v514, u10);
          v518 = _mm_mul_ps(v514, v574);
          OutTanU[dword_1008939C + 15] = _mm_add_ps(
                                           _mm_div_ps(_mm_sub_ps(_mm_mul_ps(v572, v574), v517), Four_Threes),
                                           OutTanU[dword_1008939C + 15]);
          OutTanU[dword_100893A0 + 15] = _mm_add_ps(
                                           OutTanU[dword_100893A0 + 15],
                                           _mm_div_ps(_mm_sub_ps(v516, v518), Four_Threes));
          v572 = OutTanU[dword_100893D0 + 15];
          v519 = (unsigned __int16 *)pPos->m128_i32[2];
          v520 = (_WORD *)pPos[1].m128_i32[0];
          v521 = *v519;
          v22 = v520[3] == 0;
          u10 = _mm_mul_ps(OutTanU[dword_100893D4 + 15], Four_Twos);
          v522 = OutTanU[v515 + 15];
          v523 = v519[3];
          u00 = v522;
          if ( !v22 )
            --v523;
          if ( *v520 != 0 )
            --v521;
          v524 = (float)(v581 / (float)v523);
          __libm_sse2_cos(x: *(long double *)v602);
          *(float *)&v524 = v524;
          v525 = 0;
          v525.m128_f32[0] = *(float *)&v524;
          v574 = _mm_shuffle_ps(v525, v525, 0);
          v526 = (float)(v578 / (float)v521);
          __libm_sse2_cos(x: *(long double *)v602);
          *(float *)&v526 = v526;
          v527 = 0;
          v527.m128_f32[0] = *(float *)&v526;
          v528 = _mm_shuffle_ps(v527, v527, 0);
          v529 = _mm_sub_ps(_mm_mul_ps(v574, u00), _mm_mul_ps(v528, u10));
          *(&v532 + dword_100893A4) = _mm_sub_ps(
                                        *(&v532 + dword_100893A4),
                                        _mm_div_ps(
                                          _mm_sub_ps(_mm_mul_ps(v574, u10), _mm_mul_ps(v528, v572)),
                                          Four_Threes));
          *(&v532 + dword_100893A8) = _mm_sub_ps(*(&v532 + dword_100893A8), _mm_div_ps(v529, Four_Threes));
          v252 = (Vector4D)v532;
          goto LABEL_288;
        }
        v439 = *v587;
        v440 = _mm_sub_ps(v17[v587[1]], v17[v439]);
        v594 = (__m128 *)(unsigned __int16)v598;
        v599 = &v17[v439];
        v441 = v587;
        v442 = sPosEdge1Stencil[(unsigned __int16)v598];
        v443 = *v442;
        v444 = _mm_sub_ps(v17[v587[(unsigned __int16)v595 - 1]], *v599);
        v597 = v442 + 1;
        v445 = _mm_mul_ps(*v599, _mm_sub_ps(v443, Four_Ones));
        v446 = v445;
        v447 = 1;
        v596 = (int)&v587[(unsigned __int16)v595 - 5];
        while ( 1 )
        {
          v448 = v441[v447];
          v449 = *v597++;
          v445 = _mm_add_ps(v445, _mm_mul_ps(v17[v448], v449));
          ++v447;
          v446 = _mm_add_ps(v446, _mm_mul_ps(v17[*(unsigned __int16 *)v596], v449));
          v596 += 2;
          if ( v447 >= 6 )
            break;
          v441 = v587;
        }
        v450 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v445, v445, 210), _mm_shuffle_ps(v440, v440, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v445, v445, 201), _mm_shuffle_ps(v440, v440, 210)));
        v535 = _mm_mul_ps(v450, v450);
        v451 = 0;
        v451.m128_f32[0] = (float)(v535.m128_f32[1] + v535.m128_f32[0]) + v535.m128_f32[2];
        v452 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v446, v446, 201), _mm_shuffle_ps(v444, v444, 210)),
                 _mm_mul_ps(_mm_shuffle_ps(v446, v446, 210), _mm_shuffle_ps(v444, v444, 201)));
        v549 = _mm_mul_ps(v452, v452);
        v453 = 0;
        v453.m128_f32[0] = (float)(v549.m128_f32[1] + v549.m128_f32[0]) + v549.m128_f32[2];
        v454 = _mm_add_ps(
                 _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v453, v453, 0)), v452),
                 _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v451, v451, 0)), v450));
        v541 = _mm_mul_ps(v454, v454);
        v455 = 0;
        v455.m128_f32[0] = (float)(v541.m128_f32[1] + v541.m128_f32[0]) + v541.m128_f32[2];
        v456 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v455, v455, 0)), v454);
        v457 = 0;
        v571 = _mm_mul_ps(v456, v440);
        v457.m128_f32[0] = (float)(v571.m128_f32[1] + v571.m128_f32[0]) + v571.m128_f32[2];
        OutPos[15] = _mm_mul_ps(v456, v444);
        v458 = 0;
        v458.m128_f32[0] = (float)(OutPos[15].m128_f32[1] + OutPos[15].m128_f32[0]) + OutPos[15].m128_f32[2];
        v459 = _mm_sub_ps(v440, _mm_mul_ps(_mm_shuffle_ps(v457, v457, 0), v456));
        v460 = _mm_sub_ps(v444, _mm_mul_ps(_mm_shuffle_ps(v458, v458, 0), v456));
        v570 = _mm_mul_ps(v459, v459);
        v461 = 0;
        v461.m128_f32[0] = (float)(v570.m128_f32[1] + v570.m128_f32[0]) + v570.m128_f32[2];
        v462 = _mm_rsqrt_ps(_mm_shuffle_ps(v461, v461, 0));
        c0 = _mm_mul_ps(v460, v460);
        v463 = _mm_div_ps(v459, v462);
        v464 = 0;
        v464.m128_f32[0] = (float)(c0.m128_f32[1] + c0.m128_f32[0]) + c0.m128_f32[2];
        v465 = _mm_rsqrt_ps(_mm_shuffle_ps(v464, v464, 0));
        v466 = _mm_div_ps(v460, v465);
        v574 = _mm_mul_ps(_mm_add_ps(v465, v462), Four_PointFives);
        v530 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v456, v456, 201), _mm_shuffle_ps(v463, v463, 210)),
                 _mm_mul_ps(_mm_shuffle_ps(v456, v456, 210), _mm_shuffle_ps(v463, v463, 201)));
        u20 = _mm_mul_ps(v530, v466);
        v467 = 0;
        v467.m128_f32[0] = (float)(u20.m128_f32[1] + u20.m128_f32[0]) + u20.m128_f32[2];
        u10 = v463;
        *(__m128 *)&flLoopGap[2] = _mm_mul_ps(v466, v463);
        __libm_sse2_atan2(y: *(long double *)v602, x: *(long double *)&v602[8]);
        v468 = (LOWORD(v593) - 1) / 2;
        v463.m128_f32[0] = 3.14159265 - _mm_shuffle_ps(v467, v467, 0).m128_f32[0];
        v590 = (__m128 *)v463.m128_i32[0];
        v581 = v463.m128_f32[0];
        v469 = v468 + 1;
        v467.m128_f32[0] = 1.0 / *(&vec4_invalid_8.w + (_DWORD)v594);
        *(float *)&v599 = (float)((float)v468 * v463.m128_f32[0]) * v467.m128_f32[0];
        v594 = (__m128 *)v467.m128_i32[0];
        *(double *)v456.m128_u64 = *(float *)&v599;
        __libm_sse2_cos(x: *(long double *)v602);
        v456.m128_f32[0] = *(double *)v456.m128_u64;
        v470 = 0;
        v470.m128_f32[0] = v456.m128_f32[0];
        u00 = v470;
        *(double *)v456.m128_u64 = *(float *)&v599;
        __libm_sse2_sin(x: *(long double *)v602);
        v456.m128_f32[0] = *(double *)v456.m128_u64;
        v471 = 0;
        v471.m128_f32[0] = v456.m128_f32[0];
        *(float *)&v599 = (float)((float)v469 * *(float *)&v590) * *(float *)&v594;
        v531 = v471;
        *(double *)v456.m128_u64 = *(float *)&v599;
        __libm_sse2_cos(x: *(long double *)v602);
        v456.m128_f32[0] = *(double *)v456.m128_u64;
        v472 = 0;
        v472.m128_f32[0] = v456.m128_f32[0];
        v572 = _mm_shuffle_ps(v472, v472, 0);
        *(double *)v456.m128_u64 = *(float *)&v599;
        __libm_sse2_sin(x: *(long double *)v602);
        v456.m128_f32[0] = *(double *)v456.m128_u64;
        v473 = 0;
        v473.m128_f32[0] = v456.m128_f32[0];
        u00 = _mm_shuffle_ps(u00, u00, 0);
        v436 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v531, v531, 0), v530), _mm_mul_ps(u00, u10)), v574);
        v433 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v473, v473, 0), v530), _mm_mul_ps(v572, u10)), v574);
      }
    }
    else
    {
      v432 = (unsigned __int16)v598;
      v433 = Four_Zeros;
      v434 = sCCLimitTanStencil1[v432];
      v596 = (int)sCCLimitTanStencil2[v432];
      *(float *)&v435 = 0.0;
      v436 = Four_Zeros;
      OutTanV[7] = Four_Zeros;
      OutTanU[8] = Four_Zeros;
      v593 = 0.0;
      if ( (_WORD)v595 != 0 )
      {
        v437 = (__m128 *)v596;
        v599 = (__m128 *)((char *)v434 - v596);
        do
        {
          v436 = _mm_add_ps(v436, _mm_mul_ps(*(__m128 *)((char *)v437 + (_DWORD)v599), v17[v587[v435]]));
          OutTanU[8] = v436;
          v438 = _mm_mul_ps(v17[v587[LODWORD(v593)]], *v437);
          v435 = LODWORD(v593) + 1;
          ++v437;
          v433 = _mm_add_ps(v433, v438);
          OutTanV[7] = v433;
          v593 = *(float *)&v435;
        }
        while ( v435 < (unsigned __int16)v595 );
      }
    }
    OutTanU[8] = _mm_mul_ps(v433, (__m128)xmmword_100B0490);
    OutTanV[7] = _mm_mul_ps(v436, (__m128)xmmword_100B0450);
    goto LABEL_269;
  }
LABEL_289:
  *(__m128 *)&quad->vtx1RingSize = v568;
  *(__m128 *)&quad->bndVtx = OutPos[0];
  *(__m128 *)&quad->edgeBias = OutPos[1];
  *(__m128 *)&quad->vUV1 = OutPos[2];
  *(__m128 *)&quad[1].vtx1RingCenterQuadOffset = OutPos[3];
  *(__m128 *)&quad[1].bndEdge = OutPos[4];
  *(__m128 *)&quad[1].nbCornerVtx = OutPos[5];
  *(__m128 *)&quad[1].vUV2 = OutPos[6];
  *(__m128 *)&quad[2].valences = OutPos[7];
  *(__m128 *)&quad[2].cornerVtx = OutPos[8];
  *(__m128 *)&quad[2].oneRing = OutPos[9];
  *(__m128 *)&quad[2].vUV3 = OutPos[10];
  *(__m128 *)&quad[3].minOneRingOffset = OutPos[11];
  *(__m128 *)&quad[3].loopGapAngle = OutPos[12];
  *(__m128 *)&quad[3].vUV0 = OutPos[13];
  *(__m128 *)&quad[4].vtx1RingSize = OutPos[14];
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

// ============================================================
// Overlay from subdbaker (Missing functions)
// ============================================================
namespace subdbaker {

//------------------------------------------------------------------------------
// Address: 0x00402DC0
// Name: public: CVProfScope::~CVProfScope(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfScope::~CVProfScope(CVProfScope *this)
{
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00402DD0
// Name: void set_ShowACCGeometryTangents(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_ShowACCGeometryTangents(bool v)
{
  sShowACCGeometryTangents = v;
}

//------------------------------------------------------------------------------
// Address: 0x00402DE0
// Name: void set_CornerCorrection(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_CornerCorrection(bool v)
{
  sCornerCorrection = v;
}

//------------------------------------------------------------------------------
// Address: 0x00402DF0
// Name: ComputeCatmullClarkLimitTanStencil
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeCatmullClarkLimitTanStencil(
        __m128 *stencilBuffer1@<ecx>,
        int a2@<ebp>,
        char a3,
        char a4,
        int a5,
        __m128 *a6)
{
  int v7; // eax
  int v8; // edx
  __m128 *v9; // eax
  double v10; // xmm0_8
  float v11; // xmm1_4
  __m128 *v12; // edi
  float v13; // xmm0_4
  __m128 v14; // xmm1
  float v15; // xmm0_4
  __m128 v16; // xmm1
  float v17; // xmm0_4
  __m128 v18; // xmm1
  float v19; // xmm0_4
  __m128 v20; // xmm1
  int v21; // edi
  float v22; // xmm0_4
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  float v25; // xmm0_4
  __m128 v26; // xmm2
  float v27; // xmm5_4
  __m128 v28; // xmm1
  float v29; // xmm0_4
  int v30; // edi
  float v31; // xmm0_4
  __m128 v32; // xmm2
  __m128 v33; // xmm6
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm6
  __m128 v39; // xmm3
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm0
  int v43; // eax
  __m128 v44; // xmm0
  __m128 v45; // xmm0
  __m128 v46; // xmm2
  __m128 v47; // xmm4
  __m128 v48; // xmm3
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  int v51; // edi
  double v52; // xmm0_8
  float v53; // xmm2_4
  __m128 *v54; // ecx
  float v55; // xmm1_4
  int v56; // eax
  __m128 v57; // xmm0
  int v58; // esi
  float v59; // xmm0_4
  __m128 v60; // xmm1
  float v61; // xmm0_4
  __m128 v62; // xmm1
  __m128 v63; // xmm0
  __m128 v64; // xmm0
  double v65; // [esp-Ah] [ebp-74h]
  double v66; // [esp-Ah] [ebp-74h]
  double v67; // [esp-Ah] [ebp-74h]
  double v68; // [esp-2h] [ebp-6Ch]
  double v69; // [esp+6h] [ebp-64h]
  int v70; // [esp+Ah] [ebp-60h]
  float v71; // [esp+Ah] [ebp-60h]
  float v72; // [esp+Eh] [ebp-5Ch]
  float v73; // [esp+22h] [ebp-48h]
  float v74; // [esp+22h] [ebp-48h]
  float v75; // [esp+22h] [ebp-48h]
  double v76; // [esp+26h] [ebp-44h]
  float v77; // [esp+2Ah] [ebp-40h]
  float v78; // [esp+2Ah] [ebp-40h]
  __m128 *c; // [esp+2Eh] [ebp-3Ch]
  int ca; // [esp+2Eh] [ebp-3Ch]
  __m128 *cb; // [esp+2Eh] [ebp-3Ch]
  int v82; // [esp+4Ah] [ebp-20h]
  float v83; // [esp+4Ah] [ebp-20h]
  float v84; // [esp+4Ah] [ebp-20h]
  long double v85; // [esp+5Ah] [ebp-10h]
  long double v86; // [esp+5Ah] [ebp-10h]
  long double v87; // [esp+5Ah] [ebp-10h]
  long double v88; // [esp+5Ah] [ebp-10h]
  long double v89; // [esp+5Ah] [ebp-10h]
  long double v90; // [esp+5Ah] [ebp-10h]
  long double v91; // [esp+5Ah] [ebp-10h]
  long double v92; // [esp+5Ah] [ebp-10h]
  long double v93; // [esp+5Ah] [ebp-10h]
  long double v94; // [esp+5Ah] [ebp-10h]

  HIDWORD(v85) = a2;
  LODWORD(v85) = -1;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitTanStencil",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  v7 = a5;
  v8 = 2 * a5;
  if ( 2 * a5 > 0 )
  {
    v9 = a6;
    do
    {
      *(__m128 *)((char *)v9 + (char *)stencilBuffer1 - (char *)a6) = Four_Zeros;
      *v9++ = Four_Zeros;
      --v8;
    }
    while ( v8 != 0 );
    v7 = a5;
  }
  if ( a3 != 0 )
  {
    if ( a4 != 0 )
    {
      if ( v7 > 2 )
      {
        v21 = v7 - 1;
        v74 = (float)(v7 - 1);
        v70 = v7 - 1;
        __libm_sse2_sin(x: v85);
        v22 = 0.0 / v74;
        v83 = v22;
        v23 = 0;
        v23.m128_f32[0] = v22 * 0.5;
        stencilBuffer1[1] = _mm_add_ps(_mm_shuffle_ps(v23, v23, 0), stencilBuffer1[1]);
        v24 = 0;
        v24.m128_f32[0] = v22 * -0.5;
        *stencilBuffer1 = _mm_add_ps(*stencilBuffer1, _mm_shuffle_ps(v24, v24, 0));
        __libm_sse2_sin(x: v90);
        v25 = (double)v21 * 3.14159265 / v74;
        v26 = 0;
        v26.m128_f32[0] = v25 * 0.5;
        v27 = v25 + v83;
        v28 = 0;
        v28.m128_f32[0] = v25 * -0.5;
        stencilBuffer1[2 * a5 - 1] = _mm_add_ps(stencilBuffer1[2 * a5 - 1], _mm_shuffle_ps(v26, v26, 0));
        v84 = v25 + v83;
        *stencilBuffer1 = _mm_add_ps(*stencilBuffer1, _mm_shuffle_ps(v28, v28, 0));
        ca = 1;
        if ( v21 > 1 )
        {
          v29 = (float)a5 * 2.0;
          v78 = 1.0 / (float)(v29 + 10.0);
          v72 = (float)(v29 * v78) - 1.0;
          v30 = 2;
          do
          {
            __libm_sse2_sin(x: v91);
            v31 = (double)ca * 3.14159265 / v74;
            v27 = v31 + v84;
            v32 = 0;
            v32.m128_f32[0] = v72 * v31;
            *stencilBuffer1 = _mm_add_ps(*stencilBuffer1, _mm_shuffle_ps(v32, v32, 0));
            v33 = stencilBuffer1[v30];
            v34 = 0;
            v34.m128_f32[0] = (float)(v31 * 2.0) * v78;
            v35 = v34;
            stencilBuffer1[v30 - 1] = _mm_add_ps(stencilBuffer1[v30 - 1], _mm_shuffle_ps(v34, v34, 0));
            v36 = 0;
            v36.m128_f32[0] = v78 * v31;
            v37 = v36;
            v38 = _mm_add_ps(v33, _mm_shuffle_ps(v36, v36, 0));
            v39 = 0;
            v39.m128_f32[0] = (float)(v31 * 4.0) * v78;
            v40 = _mm_add_ps(stencilBuffer1[v30 + 1], _mm_shuffle_ps(v39, v39, 0));
            v41 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 0), stencilBuffer1[v30 + 2]);
            v42 = _mm_add_ps(stencilBuffer1[v30 + 3], _mm_shuffle_ps(v35, v35, 0));
            stencilBuffer1[v30] = v38;
            stencilBuffer1[v30 + 1] = v40;
            stencilBuffer1[v30 + 2] = v41;
            stencilBuffer1[v30 + 3] = v42;
            v30 += 2;
            v84 = v27;
            ++ca;
          }
          while ( ca < v70 );
        }
        v43 = 2 * a5;
        v44 = 0;
        v44.m128_f32[0] = v27;
        v45 = _mm_shuffle_ps(v44, v44, 0);
        if ( 2 * a5 > 0 )
        {
          do
          {
            *stencilBuffer1 = _mm_div_ps(*stencilBuffer1, v45);
            ++stencilBuffer1;
            --v43;
          }
          while ( v43 != 0 );
        }
      }
    }
    else if ( v7 == 2 )
    {
      stencilBuffer1[1] = _mm_shuffle_ps((__m128)0x3F000000u, (__m128)0x3F000000u, 0);
      v46 = _mm_shuffle_ps((__m128)0xBF000000, (__m128)0xBF000000, 0);
      stencilBuffer1[3] = v46;
      a6[1] = v46;
      a6[3] = _mm_shuffle_ps((__m128)0x3F000000u, (__m128)0x3F000000u, 0);
      v47 = stencilBuffer1[3];
      *stencilBuffer1 = _mm_add_ps(*stencilBuffer1, _mm_shuffle_ps((__m128)0xB90BCF65, (__m128)0xB90BCF65, 0));
      stencilBuffer1[1] = _mm_add_ps(_mm_shuffle_ps((__m128)0x3851B717u, (__m128)0x3851B717u, 0), stencilBuffer1[1]);
      stencilBuffer1[2] = _mm_add_ps(_mm_shuffle_ps((__m128)0x380BCF65u, (__m128)0x380BCF65u, 0), stencilBuffer1[2]);
      stencilBuffer1[3] = _mm_add_ps(v47, _mm_shuffle_ps((__m128)0x3851B717u, (__m128)0x3851B717u, 0));
      v48 = a6[1];
      *a6 = _mm_add_ps(_mm_shuffle_ps((__m128)0xB90BCF65, (__m128)0xB90BCF65, 0), *a6);
      v49 = _mm_add_ps(_mm_shuffle_ps((__m128)0x3851B717u, (__m128)0x3851B717u, 0), a6[3]);
      v50 = _mm_add_ps(a6[2], _mm_shuffle_ps((__m128)0x380BCF65u, (__m128)0x380BCF65u, 0));
      a6[1] = _mm_add_ps(v48, _mm_shuffle_ps((__m128)0x3851B717u, (__m128)0x3851B717u, 0));
      a6[2] = v50;
      a6[3] = v49;
    }
    else
    {
      v51 = v7 - 1;
      v52 = 3.14159265 / (double)(v7 - 1);
      v76 = (double)(v7 - 1);
      v66 = v52;
      __libm_sse2_cos(x: v85);
      *(float *)&v52 = v52;
      v75 = *(float *)&v52;
      __libm_sse2_sin(x: v92);
      v53 = *(float *)&v52;
      v54 = a6;
      v55 = v66;
      stencilBuffer1[1] = _mm_shuffle_ps((__m128)0x3F000000u, (__m128)0x3F000000u, 0);
      v56 = 2 * v51;
      stencilBuffer1[2 * v51 + 1] = _mm_shuffle_ps((__m128)0xBF000000, (__m128)0xBF000000, 0);
      v71 = (float)((float)v51 * 3.0) + *(float *)&v52;
      v57 = 0;
      v57.m128_f32[0] = (float)(v55 * -4.0) / v71;
      v58 = 0;
      *a6 = _mm_shuffle_ps(v57, v57, 0);
      if ( v51 > 0 )
      {
        cb = a6 + 2;
        do
        {
          __libm_sse2_sin(x: v93);
          v67 = (double)v58 * 3.14159265 / v76;
          v59 = v67 * 4.0 / (float)((float)(3 * v51) + v53);
          v60 = 0;
          v60.m128_f32[0] = v59;
          cb[-1] = _mm_shuffle_ps(v60, v60, 0);
          ++v58;
          __libm_sse2_sin(x: v94);
          v61 = ((double)v58 * 3.14159265 / v76 + v67) / v71;
          v62 = 0;
          v62.m128_f32[0] = v61;
          *cb = _mm_shuffle_ps(v62, v62, 0);
          cb += 2;
        }
        while ( v58 < v51 );
        v53 = v75;
        v56 = 2 * v51;
        v54 = a6;
      }
      v63 = 0;
      v63.m128_i32[0] = COERCE_UNSIGNED_INT(
                          (float)((float)((float)(v53 * 2.0) + 1.0) * fsqrt(v53 + 1.0))
                        / (float)((float)((float)(3 * v51) + v53) * fsqrt(1.0 - v53)))
                      ^ _mask__NegFloat_;
      v64 = _mm_shuffle_ps(v63, v63, 0);
      v54[v56 + 1] = v64;
      v54[1] = v64;
    }
  }
  else
  {
    v68 = (double)v7;
    v10 = 3.14159265 / (double)v7;
    __libm_sse2_cos(x: v85);
    v11 = v10 * v10 + 4.0;
    v73 = 1.0 / (float)(fsqrt(v11) * (float)a5);
    *(float *)&v10 = v73 * v10 + (float)(1.0 / (float)a5);
    v77 = *(float *)&v10;
    v82 = 0;
    if ( a5 > 0 )
    {
      c = a6 + 1;
      v12 = stencilBuffer1 + 2;
      do
      {
        v69 = (double)v82 * 6.2831853;
        __libm_sse2_cos(x: v86);
        v13 = v69 / v68 * v77;
        v14 = 0;
        v14.m128_f32[0] = v13;
        v12[-1] = _mm_shuffle_ps(v14, v14, 0);
        __libm_sse2_cos(x: v87);
        v15 = (v69 + 3.14159265) / v68 * v73;
        v16 = 0;
        v16.m128_f32[0] = v15;
        *v12 = _mm_shuffle_ps(v16, v16, 0);
        v65 = (double)((v82 - 1) % a5) * 6.2831853;
        __libm_sse2_cos(x: v88);
        v17 = v65 / v68 * v77;
        v18 = 0;
        v18.m128_f32[0] = v17;
        *c = _mm_shuffle_ps(v18, v18, 0);
        __libm_sse2_cos(x: v89);
        c += 2;
        v19 = (v65 + 3.14159265) / v68 * v73;
        v20 = 0;
        v20.m128_f32[0] = v19;
        *(__m128 *)((char *)v12 + (char *)a6 - (char *)stencilBuffer1) = _mm_shuffle_ps(v20, v20, 0);
        v12 += 2;
        ++v82;
      }
      while ( v82 < a5 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00403580
// Name: ComputeACCEdgePosStencils
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeACCEdgePosStencils(
        __m128 *stencilBuffer1@<edi>,
        __m128 *stencilBuffer2@<esi>,
        unsigned __int8 boundary,
        unsigned __int8 corner,
        int n)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm2

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePosStencils",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  *stencilBuffer1 = Four_Zeros;
  *stencilBuffer2 = Four_Zeros;
  stencilBuffer1[1] = Four_Zeros;
  stencilBuffer2[1] = Four_Zeros;
  stencilBuffer1[2] = Four_Zeros;
  stencilBuffer2[2] = Four_Zeros;
  stencilBuffer1[3] = Four_Zeros;
  stencilBuffer2[3] = Four_Zeros;
  stencilBuffer1[4] = Four_Zeros;
  stencilBuffer2[4] = Four_Zeros;
  stencilBuffer1[5] = Four_Zeros;
  stencilBuffer2[5] = Four_Zeros;
  if ( boundary != 0 )
  {
    *stencilBuffer1 = _mm_shuffle_ps((__m128)0x3F2AAAABu, (__m128)0x3F2AAAABu, 0);
    v12 = _mm_shuffle_ps((__m128)0x3EAAAAABu, (__m128)0x3EAAAAABu, 0);
    *stencilBuffer2 = v12;
    stencilBuffer1[3] = v12;
    stencilBuffer2[3] = _mm_shuffle_ps((__m128)0x3F2AAAABu, (__m128)0x3F2AAAABu, 0);
  }
  else
  {
    v5 = (float)n * 2.0;
    v6 = 1.0 / (float)(v5 + 10.0);
    v7 = 0;
    v7.m128_f32[0] = v5 * v6;
    *stencilBuffer1 = _mm_shuffle_ps(v7, v7, 0);
    v8 = 0;
    v9 = 0;
    v9.m128_f32[0] = v6 * 4.0;
    *stencilBuffer2 = _mm_shuffle_ps(v9, v9, 0);
    v8.m128_f32[0] = v6 * 2.0;
    v10 = v8;
    stencilBuffer1[1] = _mm_shuffle_ps(v8, v8, 0);
    v11 = 0;
    v11.m128_f32[0] = v6;
    stencilBuffer2[1] = _mm_shuffle_ps(v11, v11, 0);
    stencilBuffer1[2] = _mm_shuffle_ps(v11, v11, 0);
    stencilBuffer2[2] = _mm_shuffle_ps(v10, v10, 0);
    stencilBuffer1[3] = _mm_shuffle_ps(v9, v9, 0);
    stencilBuffer2[3] = _mm_shuffle_ps(v7, v7, 0);
    stencilBuffer1[4] = _mm_shuffle_ps(v11, v11, 0);
    stencilBuffer2[4] = _mm_shuffle_ps(v10, v10, 0);
    stencilBuffer1[5] = _mm_shuffle_ps(v10, v10, 0);
    stencilBuffer2[5] = _mm_shuffle_ps(v11, v11, 0);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00403750
// Name: ComputeACCSinCosPITables
// Source: json
//------------------------------------------------------------------------------
int *ComputeACCSinCosPITables()
{
  int v0; // edi
  __m128 v1; // xmm2
  int v2; // ecx
  __m128 v3; // xmm1
  int v4; // esi
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  int *result; // eax
  __m128 v8; // [esp-Ch] [ebp-3Ch]

  v0 = 0;
  v1 = _mm_shuffle_ps((__m128)0x40490FDBu, (__m128)0x40490FDBu, 0);
  v2 = 0;
  do
  {
    v3 = 0;
    v3.m128_f32[0] = (float)v0;
    v4 = 0;
    v5 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v1);
    do
    {
      v6 = 0;
      v6.m128_f32[0] = (float)v4;
      v8 = _mm_div_ps(v5, _mm_shuffle_ps(v6, v6, 0));
      sCCCosPI[0][v2].m128_f32[0] = cos(v8.m128_f32[0]);
      sCCSinPI[0][v2].m128_f32[0] = sin(v8.m128_f32[0]);
      sCCCosPI[0][v2].m128_f32[1] = cos(v8.m128_f32[1]);
      sCCSinPI[0][v2].m128_f32[1] = sin(v8.m128_f32[1]);
      sCCCosPI[0][v2].m128_f32[2] = cos(v8.m128_f32[2]);
      sCCSinPI[0][v2].m128_f32[2] = sin(v8.m128_f32[2]);
      result = &sCCSinPI[0][v2].m128_i32[3];
      sCCCosPI[0][v2].m128_f32[3] = cos(v8.m128_f32[3]);
      sCCSinPI[0][v2].m128_f32[3] = sin(v8.m128_f32[3]);
      ++v4;
      ++v2;
    }
    while ( v4 < 19 );
    ++v0;
  }
  while ( v2 < 722 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004038A0
// Name: void FillTables(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall FillTables(int a1@<ebp>)
{
  __m128 v1; // xmm0
  int v2; // ecx
  __m128 *v3; // eax
  __m128 v4; // xmm1
  int v5; // eax
  int v6; // ecx
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  int v9; // edi
  __m128 *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm0_4
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 *v19; // eax
  int v20; // edi
  float v21; // xmm1_4
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  __m128 v29; // xmm1
  int v30; // ecx
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // [esp-B0h] [ebp-BCh]
  __m128 v36; // [esp-A0h] [ebp-ACh]
  __m128 v37; // [esp-90h] [ebp-9Ch]
  __m128 v38; // [esp-80h] [ebp-8Ch]
  float v39; // [esp-68h] [ebp-74h]
  float v40; // [esp-64h] [ebp-70h]
  int v41; // [esp-60h] [ebp-6Ch]
  int v42; // [esp-50h] [ebp-5Ch]
  int v43; // [esp-40h] [ebp-4Ch]
  int v44; // [esp-24h] [ebp-30h]
  __m128 *v45; // [esp-20h] [ebp-2Ch]
  int v46; // [esp-8h] [ebp-14h]
  int v47; // [esp-4h] [ebp-10h]
  _DWORD v48[2]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v48[0] = a1;
  v48[1] = retaddr;
  if ( !sTableInited )
  {
    Four_TwoPI = _mm_shuffle_ps((__m128)0x40C90FDBu, (__m128)0x40C90FDBu, 0);
    Four_Tens = _mm_shuffle_ps((__m128)0x41200000u, (__m128)0x41200000u, 0);
    v1 = 0;
    v1.m128_f32[0] = 5.0;
    Four_Fives = _mm_shuffle_ps(v1, v1, 0);
    Four_NegativeThirds = _mm_shuffle_ps((__m128)0xBEAAAAAB, (__m128)0xBEAAAAAB, 0);
    v2 = 0;
    v3 = Four_N;
    do
    {
      v4 = 0;
      v4.m128_f32[0] = (float)v2;
      *v3++ = _mm_shuffle_ps(v4, v4, 0);
      ++v2;
    }
    while ( (int)v3 < (int)sCCCosPI[0] );
    v5 = 0;
    v6 = 0;
    do
    {
      v7 = 0;
      v7.m128_f32[0] = (float)v5;
      Four_Valence[v6] = _mm_shuffle_ps(v7, v7, 0);
      v8 = 0;
      v8.m128_f32[0] = (float)v5 + 5.0;
      Four_ValencePlus5[v6] = _mm_shuffle_ps(v8, v8, 0);
      Valence_MinusOne[v5] = (float)(v5 - 1);
      ++v5;
      ++v6;
    }
    while ( v5 < 19 );
    v36 = (__m128)0x3E2AAAABu;
    v35 = _mm_shuffle_ps((__m128)0x3E2AAAABu, (__m128)0x3E2AAAABu, 0);
    v9 = 0;
    v10 = sPosCornerStencil[0];
    v47 = 0;
    v43 = 0;
    v44 = 0;
    v45 = sPosCornerStencil[0];
    v42 = 0;
    v46 = 0;
    while ( 1 )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeCatmullClarkLimitPosStencil",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      if ( v44 > 0 )
      {
        *v10 = Four_Zeros;
        qmemcpy(&v10[1], v10, 4 * ((unsigned int)(16 * v44 - 13) >> 2));
        v9 = v47;
        v10 = v45;
      }
      v11 = (float)(v9 * v9);
      v12 = 1.0 / (float)((float)((float)v9 * 5.0) + v11);
      v13 = 0;
      v13.m128_f32[0] = v11 * v12;
      *v10 = _mm_shuffle_ps(v13, v13, 0);
      if ( v9 > 0 )
      {
        v14 = 0;
        v14.m128_f32[0] = v12 * 4.0;
        v15 = v14;
        v16 = 0;
        v16.m128_f32[0] = v12;
        v17 = _mm_shuffle_ps(v15, v15, 0);
        v18 = _mm_shuffle_ps(v16, v16, 0);
        v19 = v10 + 2;
        do
        {
          v19[-1] = v17;
          *v19 = v18;
          v19 += 2;
          --v9;
        }
        while ( v9 != 0 );
      }
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      ComputeACCEdgePosStencils(
        stencilBuffer1: sPosEdge1Stencil[v42],
        stencilBuffer2: sPosEdge2Stencil[v42],
        boundary: 0,
        corner: 0,
        n: v47);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeACCInteriorPosStencil",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      v20 = v41;
      v21 = 1.0 / (float)(v40 + 5.0);
      v22 = 0;
      v22.m128_f32[0] = v40 * v21;
      *(__m128 *)((char *)&sPosInteriorStencil[0][0] + v41) = _mm_shuffle_ps(v22, v22, 0);
      v23 = 0;
      v23.m128_f32[0] = v21 * 2.0;
      v24 = v23;
      *(__m128 *)((char *)&sPosInteriorStencil[0][1] + v41) = _mm_shuffle_ps(v23, v23, 0);
      v39 = v21;
      v25 = 0;
      v25.m128_f32[0] = v21;
      *(__m128 *)((char *)&sPosInteriorStencil[0][2] + v41) = _mm_shuffle_ps(v25, v25, 0);
      *(__m128 *)((char *)&sPosInteriorStencil[0][3] + v41) = _mm_shuffle_ps(v24, v24, 0);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeCatmullClarkLimitPosStencil",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      if ( v44 > 0 )
      {
        sPosCornerBndStencil[v46][0] = Four_Zeros;
        qmemcpy(&sPosCornerBndStencil[v46][1], sPosCornerBndStencil[v46], 4 * ((unsigned int)(16 * v44 - 13) >> 2));
        v20 = v41;
      }
      sPosCornerBndStencil[v46][0] = _mm_shuffle_ps(v38, v38, 0);
      sPosCornerBndStencil[v46][1] = _mm_shuffle_ps(v36, v36, 0);
      sCCLimitTanCornerStencil2[v46 + 19][v43 + 40] = v35;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeACCEdgePosStencils",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      sPosEdge2BndStencil[v42][0] = Four_Zeros;
      sPosEdge2BndStencil[v42][1].m128_i32[0] = sPosEdge2BndStencil[v42][0].m128_i32[0];
      sPosEdge2BndStencil[v42][1].m128_i32[1] = sPosEdge2BndStencil[v42][0].m128_i32[1];
      sPosEdge2BndStencil[v42][1].m128_i32[2] = sPosEdge2BndStencil[v42][0].m128_i32[2];
      sPosEdge2BndStencil[v42][1].m128_i32[3] = sPosEdge2BndStencil[v42][0].m128_i32[3];
      sPosEdge2BndStencil[v42][2].m128_i32[0] = sPosEdge2BndStencil[v42][1].m128_i32[0];
      sPosEdge2BndStencil[v42][2].m128_i32[1] = sPosEdge2BndStencil[v42][1].m128_i32[1];
      sPosEdge2BndStencil[v42][2].m128_i32[2] = sPosEdge2BndStencil[v42][1].m128_i32[2];
      sPosEdge2BndStencil[v42][2].m128_i32[3] = sPosEdge2BndStencil[v42][1].m128_i32[3];
      sPosEdge2BndStencil[v42][3].m128_i32[0] = sPosEdge2BndStencil[v42][2].m128_i32[0];
      sPosEdge2BndStencil[v42][3].m128_i32[1] = sPosEdge2BndStencil[v42][2].m128_i32[1];
      sPosEdge2BndStencil[v42][3].m128_i32[2] = sPosEdge2BndStencil[v42][2].m128_i32[2];
      sPosEdge2BndStencil[v42][3].m128_i32[3] = sPosEdge2BndStencil[v42][2].m128_i32[3];
      sPosEdge2BndStencil[v42][4].m128_i32[0] = sPosEdge2BndStencil[v42][3].m128_i32[0];
      sPosEdge2BndStencil[v42][4].m128_i32[1] = sPosEdge2BndStencil[v42][3].m128_i32[1];
      sPosEdge2BndStencil[v42][4].m128_i32[2] = sPosEdge2BndStencil[v42][3].m128_i32[2];
      v26 = sPosEdge2BndStencil[v42][3].m128_i32[3];
      sPosEdge1BndStencil[v42][0] = Four_Zeros;
      sPosEdge2BndStencil[v42][4].m128_i32[3] = v26;
      sPosEdge2BndStencil[v42][5].m128_i32[0] = sPosEdge2BndStencil[v42][4].m128_i32[0];
      sPosEdge2BndStencil[v42][5].m128_i32[1] = sPosEdge2BndStencil[v42][4].m128_i32[1];
      v27 = sPosEdge2BndStencil[v42][4].m128_i32[2];
      sPosEdge1BndStencil[v42][1].m128_i32[0] = sPosEdge1BndStencil[v42][0].m128_i32[0];
      sPosEdge2BndStencil[v42][5].m128_i32[2] = v27;
      v28 = sPosEdge2BndStencil[v42][4].m128_i32[3];
      sPosEdge1BndStencil[v42][1].m128_i32[1] = sPosEdge1BndStencil[v42][0].m128_i32[1];
      sPosEdge2BndStencil[v42][5].m128_i32[3] = v28;
      sPosEdge1BndStencil[v42][1].m128_i32[2] = sPosEdge1BndStencil[v42][0].m128_i32[2];
      sPosEdge1BndStencil[v42][1].m128_i32[3] = sPosEdge1BndStencil[v42][0].m128_i32[3];
      sPosEdge1BndStencil[v42][2].m128_i32[0] = sPosEdge1BndStencil[v42][1].m128_i32[0];
      sPosEdge1BndStencil[v42][2].m128_i32[1] = sPosEdge1BndStencil[v42][1].m128_i32[1];
      sPosEdge1BndStencil[v42][2].m128_i32[2] = sPosEdge1BndStencil[v42][1].m128_i32[2];
      sPosEdge1BndStencil[v42][2].m128_i32[3] = sPosEdge1BndStencil[v42][1].m128_i32[3];
      sPosEdge1BndStencil[v42][3].m128_i32[0] = sPosEdge1BndStencil[v42][2].m128_i32[0];
      sPosEdge1BndStencil[v42][3].m128_i32[1] = sPosEdge1BndStencil[v42][2].m128_i32[1];
      sPosEdge1BndStencil[v42][3].m128_i32[2] = sPosEdge1BndStencil[v42][2].m128_i32[2];
      sPosEdge1BndStencil[v42][3].m128_i32[3] = sPosEdge1BndStencil[v42][2].m128_i32[3];
      sPosEdge1BndStencil[v42][4].m128_i32[0] = sPosEdge1BndStencil[v42][3].m128_i32[0];
      sPosEdge1BndStencil[v42][4].m128_i32[1] = sPosEdge1BndStencil[v42][3].m128_i32[1];
      sPosEdge1BndStencil[v42][4].m128_i32[2] = sPosEdge1BndStencil[v42][3].m128_i32[2];
      sPosEdge1BndStencil[v42][4].m128_i32[3] = sPosEdge1BndStencil[v42][3].m128_i32[3];
      sPosEdge1BndStencil[v42][5].m128_i32[0] = sPosEdge1BndStencil[v42][4].m128_i32[0];
      sPosEdge1BndStencil[v42][5].m128_i32[1] = sPosEdge1BndStencil[v42][4].m128_i32[1];
      sPosEdge1BndStencil[v42][5].m128_i32[2] = sPosEdge1BndStencil[v42][4].m128_i32[2];
      sPosEdge1BndStencil[v42][5].m128_i32[3] = sPosEdge1BndStencil[v42][4].m128_i32[3];
      sPosEdge1BndStencil[v42][0] = _mm_shuffle_ps(v38, v38, 0);
      v29 = _mm_shuffle_ps(v37, v37, 0);
      sPosEdge2BndStencil[v42][0] = v29;
      sPosEdge1BndStencil[v42][3] = v29;
      sPosEdge2BndStencil[v42][3] = _mm_shuffle_ps(v38, v38, 0);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeACCEdgePosStencils",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      sPosEdge2CornerStencil[v42][0] = Four_Zeros;
      sPosEdge2CornerStencil[v42][1].m128_i32[0] = sPosEdge2CornerStencil[v42][0].m128_i32[0];
      sPosEdge2CornerStencil[v42][1].m128_i32[1] = sPosEdge2CornerStencil[v42][0].m128_i32[1];
      sPosEdge2CornerStencil[v42][1].m128_i32[2] = sPosEdge2CornerStencil[v42][0].m128_i32[2];
      sPosEdge2CornerStencil[v42][1].m128_i32[3] = sPosEdge2CornerStencil[v42][0].m128_i32[3];
      sPosEdge2CornerStencil[v42][2].m128_i32[0] = sPosEdge2CornerStencil[v42][1].m128_i32[0];
      sPosEdge2CornerStencil[v42][2].m128_i32[1] = sPosEdge2CornerStencil[v42][1].m128_i32[1];
      sPosEdge2CornerStencil[v42][2].m128_i32[2] = sPosEdge2CornerStencil[v42][1].m128_i32[2];
      sPosEdge2CornerStencil[v42][2].m128_i32[3] = sPosEdge2CornerStencil[v42][1].m128_i32[3];
      sPosEdge2CornerStencil[v42][3].m128_i32[0] = sPosEdge2CornerStencil[v42][2].m128_i32[0];
      sPosEdge2CornerStencil[v42][3].m128_i32[1] = sPosEdge2CornerStencil[v42][2].m128_i32[1];
      sPosEdge2CornerStencil[v42][3].m128_i32[2] = sPosEdge2CornerStencil[v42][2].m128_i32[2];
      sPosEdge2CornerStencil[v42][3].m128_i32[3] = sPosEdge2CornerStencil[v42][2].m128_i32[3];
      sPosEdge2CornerStencil[v42][4].m128_i32[0] = sPosEdge2CornerStencil[v42][3].m128_i32[0];
      sPosEdge2CornerStencil[v42][4].m128_i32[1] = sPosEdge2CornerStencil[v42][3].m128_i32[1];
      sPosEdge2CornerStencil[v42][4].m128_i32[2] = sPosEdge2CornerStencil[v42][3].m128_i32[2];
      sPosEdge2CornerStencil[v42][4].m128_i32[3] = sPosEdge2CornerStencil[v42][3].m128_i32[3];
      sPosEdge2CornerStencil[v42][5].m128_i32[0] = sPosEdge2CornerStencil[v42][4].m128_i32[0];
      sPosEdge2CornerStencil[v42][5].m128_i32[1] = sPosEdge2CornerStencil[v42][4].m128_i32[1];
      v30 = sPosEdge2CornerStencil[v42][4].m128_i32[2];
      sPosEdge1CornerStencil[v42][0] = Four_Zeros;
      sPosEdge1CornerStencil[v42][1].m128_i32[0] = sPosEdge1CornerStencil[v42][0].m128_i32[0];
      sPosEdge2CornerStencil[v42][5].m128_i32[2] = v30;
      sPosEdge1CornerStencil[v42][1].m128_i32[1] = sPosEdge1CornerStencil[v42][0].m128_i32[1];
      sPosEdge2CornerStencil[v42][5].m128_i32[3] = sPosEdge2CornerStencil[v42][4].m128_i32[3];
      sPosEdge1CornerStencil[v42][1].m128_i32[2] = sPosEdge1CornerStencil[v42][0].m128_i32[2];
      sPosEdge1CornerStencil[v42][1].m128_i32[3] = sPosEdge1CornerStencil[v42][0].m128_i32[3];
      sPosEdge1CornerStencil[v42][2].m128_i32[0] = sPosEdge1CornerStencil[v42][1].m128_i32[0];
      sPosEdge1CornerStencil[v42][2].m128_i32[1] = sPosEdge1CornerStencil[v42][1].m128_i32[1];
      sPosEdge1CornerStencil[v42][2].m128_i32[2] = sPosEdge1CornerStencil[v42][1].m128_i32[2];
      sPosEdge1CornerStencil[v42][2].m128_i32[3] = sPosEdge1CornerStencil[v42][1].m128_i32[3];
      sPosEdge1CornerStencil[v42][3].m128_i32[0] = sPosEdge1CornerStencil[v42][2].m128_i32[0];
      sPosEdge1CornerStencil[v42][3].m128_i32[1] = sPosEdge1CornerStencil[v42][2].m128_i32[1];
      sPosEdge1CornerStencil[v42][3].m128_i32[2] = sPosEdge1CornerStencil[v42][2].m128_i32[2];
      sPosEdge1CornerStencil[v42][3].m128_i32[3] = sPosEdge1CornerStencil[v42][2].m128_i32[3];
      sPosEdge1CornerStencil[v42][4].m128_i32[0] = sPosEdge1CornerStencil[v42][3].m128_i32[0];
      sPosEdge1CornerStencil[v42][4].m128_i32[1] = sPosEdge1CornerStencil[v42][3].m128_i32[1];
      sPosEdge1CornerStencil[v42][4].m128_i32[2] = sPosEdge1CornerStencil[v42][3].m128_i32[2];
      sPosEdge1CornerStencil[v42][4].m128_i32[3] = sPosEdge1CornerStencil[v42][3].m128_i32[3];
      sPosEdge1CornerStencil[v42][5].m128_i32[0] = sPosEdge1CornerStencil[v42][4].m128_i32[0];
      sPosEdge1CornerStencil[v42][5].m128_i32[1] = sPosEdge1CornerStencil[v42][4].m128_i32[1];
      sPosEdge1CornerStencil[v42][5].m128_i32[2] = sPosEdge1CornerStencil[v42][4].m128_i32[2];
      sPosEdge1CornerStencil[v42][5].m128_i32[3] = sPosEdge1CornerStencil[v42][4].m128_i32[3];
      sPosEdge1CornerStencil[v42][0] = _mm_shuffle_ps(v38, v38, 0);
      sPosEdge2CornerStencil[v42][0] = v29;
      sPosEdge1CornerStencil[v42][3] = v29;
      sPosEdge2CornerStencil[v42][3] = _mm_shuffle_ps(v38, v38, 0);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "ComputeACCInteriorPosStencil",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      v31 = 0;
      v31.m128_f32[0] = v39 * v40;
      *(__m128 *)((char *)&sPosInteriorBndStencil[0][0] + v20) = _mm_shuffle_ps(v31, v31, 0);
      v32 = 0;
      v32.m128_f32[0] = v39 * 2.0;
      v33 = v32;
      *(__m128 *)((char *)&sPosInteriorBndStencil[0][1] + v20) = _mm_shuffle_ps(v32, v32, 0);
      v34 = 0;
      v34.m128_f32[0] = v39;
      *(__m128 *)((char *)&sPosInteriorBndStencil[0][2] + v20) = _mm_shuffle_ps(v34, v34, 0);
      *(__m128 *)((char *)&sPosInteriorBndStencil[0][3] + v20) = _mm_shuffle_ps(v33, v33, 0);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      ComputeCatmullClarkLimitTanStencil(
        stencilBuffer1: sCCLimitTanStencil1[v46],
        a2: (int)v48,
        a3: 0,
        a4: 0,
        a5: v47,
        a6: sCCLimitTanStencil2[v46]);
      ComputeCatmullClarkLimitTanStencil(
        stencilBuffer1: sCCLimitTanBndStencil1[v46],
        a2: (int)v48,
        a3: 1,
        a4: 0,
        a5: v47,
        a6: sCCLimitTanBndStencil2[v46]);
      ComputeCatmullClarkLimitTanStencil(
        stencilBuffer1: sCCLimitTanCornerStencil1[v46],
        a2: (int)v48,
        a3: 1,
        a4: 1,
        a5: v47++,
        a6: sCCLimitTanCornerStencil2[v46]);
      v45 += 40;
      v44 += 2;
      v43 += 2;
      ++v46;
      if ( ++v42 > 19 )
        break;
      v9 = v47;
      v10 = v45;
    }
    ComputeACCSinCosPITables();
    sTableInited = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404210
// Name: void ComputeACCAllPatches(union __m128 __near *,struct TopologyIndexStruct __near *,class Vector4D __near *,class Vector4D __near *,class Vector4D __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall ComputeACCAllPatches(
        int a1@<ebp>,
        __m128 *pPos,
        TopologyIndexStruct *quad,
        Vector4D *Pos,
        Vector4D *TanU,
        Vector4D *TanV)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  unsigned __int16 *v11; // ecx
  __int16 v12; // si
  unsigned __int16 *v13; // eax
  int v14; // edx
  float v15; // ecx
  __m128 *v16; // eax
  __m128 *v17; // esi
  __m128 *v18; // eax
  __m128 v19; // xmm1
  int v20; // eax
  int v21; // edx
  bool v22; // zf
  int v23; // edx
  float v24; // ecx
  int v25; // eax
  __m128 *v26; // edx
  __m128 *v27; // ecx
  int v28; // eax
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  int v31; // eax
  int v32; // edx
  int v33; // edx
  float v34; // ecx
  int v35; // eax
  __m128 *v36; // edx
  __m128 *v37; // ecx
  int v38; // eax
  __m128 v39; // xmm1
  __m128 v40; // xmm1
  int v41; // eax
  int v42; // edx
  int v43; // edx
  float v44; // ecx
  int v45; // eax
  __m128 *v46; // edx
  __m128 *v47; // ecx
  int v48; // eax
  __m128 v49; // xmm1
  __m128 v50; // xmm1
  int v51; // eax
  int v52; // edx
  unsigned __int16 *v53; // eax
  __m128 *v54; // ecx
  __m128 *v55; // edx
  int v56; // eax
  int v57; // ecx
  int v58; // edx
  unsigned __int16 *v59; // eax
  int v60; // ecx
  __m128 *v61; // edx
  unsigned __int16 *v62; // eax
  float v63; // ecx
  int v64; // edx
  int v65; // eax
  __m128 *v66; // ecx
  unsigned __int16 *v67; // eax
  unsigned __int16 v68; // ax
  unsigned __int16 v69; // cx
  __int16 v70; // dx
  int v71; // eax
  __m128 *v72; // eax
  int v73; // eax
  __m128 *v74; // eax
  int v75; // ecx
  int v76; // eax
  int v77; // edx
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  int v80; // eax
  int v81; // edx
  int v82; // eax
  __m128 v83; // xmm0
  __m128 v84; // xmm1
  __m128 v85; // xmm3
  __m128 v86; // xmm2
  __m128 v87; // xmm0
  __m128 v88; // xmm5
  __m128 v89; // xmm3
  __m128 v90; // xmm6
  __m128 v91; // xmm0
  __m128 v92; // xmm7
  __m128 v93; // xmm2
  __m128 v94; // xmm0
  __m128 v95; // xmm3
  __m128 v96; // xmm4
  __m128 v97; // xmm4
  __m128 v98; // xmm0
  float v99; // ecx
  unsigned __int16 *v100; // eax
  unsigned __int16 *v101; // edx
  unsigned __int16 *v102; // eax
  int v103; // ecx
  unsigned __int16 *v104; // edx
  unsigned __int16 *v105; // eax
  __m128 *v106; // ecx
  __m128 *v107; // edx
  unsigned __int16 *v108; // eax
  int v109; // ecx
  unsigned __int16 *v110; // edx
  unsigned __int16 *v111; // eax
  int v112; // ecx
  float v113; // eax
  unsigned __int16 v114; // ax
  unsigned __int16 v115; // cx
  int v116; // eax
  __m128 *v117; // eax
  int v118; // eax
  __m128 *v119; // eax
  unsigned __int16 *v120; // ecx
  int v121; // eax
  int v122; // edx
  __m128 v123; // xmm1
  __m128 v124; // xmm2
  int v125; // eax
  int v126; // edx
  int v127; // eax
  __m128 v128; // xmm0
  __m128 v129; // xmm1
  __m128 v130; // xmm0
  __m128 v131; // xmm5
  __m128 v132; // xmm4
  __m128 v133; // xmm0
  __m128 v134; // xmm2
  __m128 v135; // xmm6
  __m128 v136; // xmm0
  __m128 v137; // xmm7
  __m128 v138; // xmm2
  __m128 v139; // xmm0
  __m128 v140; // xmm2
  __m128 v141; // xmm4
  float v142; // ecx
  int v143; // eax
  float v144; // edx
  int v145; // eax
  unsigned __int16 *v146; // ecx
  float v147; // edx
  int v148; // eax
  int v149; // ecx
  int v150; // edx
  int v151; // eax
  unsigned __int16 *v152; // ecx
  float v153; // edx
  int v154; // eax
  unsigned __int16 *v155; // ecx
  int v156; // eax
  unsigned __int16 v157; // ax
  unsigned __int16 v158; // cx
  int v159; // eax
  __m128 *v160; // eax
  int v161; // eax
  __m128 *v162; // eax
  float v163; // ecx
  int v164; // eax
  int v165; // edx
  __m128 v166; // xmm1
  __m128 v167; // xmm2
  int v168; // eax
  int v169; // edx
  int v170; // eax
  __m128 v171; // xmm0
  __m128 v172; // xmm1
  __m128 v173; // xmm0
  __m128 v174; // xmm5
  __m128 v175; // xmm4
  __m128 v176; // xmm0
  __m128 v177; // xmm2
  __m128 v178; // xmm6
  __m128 v179; // xmm0
  __m128 v180; // xmm7
  __m128 v181; // xmm2
  __m128 v182; // xmm0
  __m128 v183; // xmm3
  __m128 v184; // xmm2
  int v185; // ecx
  int v186; // eax
  float v187; // edx
  int v188; // eax
  unsigned __int16 *v189; // ecx
  int v190; // edx
  int v191; // eax
  unsigned __int16 *v192; // ecx
  unsigned __int16 *v193; // edx
  int v194; // eax
  float v195; // ecx
  float v196; // edx
  int v197; // eax
  float v198; // ecx
  int v199; // eax
  unsigned __int16 v200; // ax
  unsigned __int16 v201; // cx
  int v202; // eax
  __m128 *v203; // eax
  int v204; // eax
  __m128 *v205; // eax
  float v206; // ecx
  int v207; // eax
  int v208; // edx
  __m128 v209; // xmm1
  __m128 v210; // xmm2
  int v211; // eax
  int v212; // edx
  int v213; // eax
  __m128 v214; // xmm0
  __m128 v215; // xmm1
  __m128 v216; // xmm3
  __m128 v217; // xmm2
  __m128 v218; // xmm0
  __m128 v219; // xmm5
  __m128 v220; // xmm3
  __m128 v221; // xmm6
  __m128 v222; // xmm0
  __m128 v223; // xmm7
  __m128 v224; // xmm3
  __m128 v225; // xmm2
  __m128 v226; // xmm0
  __m128 v227; // xmm4
  __m128 v228; // xmm3
  __m128 v229; // xmm4
  __m128 v230; // xmm0
  __m128 *v231; // ecx
  float v232; // eax
  float v233; // edx
  __m128 *v234; // eax
  __m128 v235; // xmm1
  __m128 *v236; // edx
  unsigned __int16 *v237; // ecx
  __m128 v238; // xmm0
  __m128 *v239; // eax
  float v240; // edx
  __m128 *v241; // eax
  __m128 v242; // xmm1
  __m128 *v243; // edx
  unsigned __int16 *v244; // ecx
  __m128 v245; // xmm0
  __m128 *v246; // eax
  float v247; // edx
  __m128 *v248; // eax
  __m128 v249; // xmm1
  __m128 *v250; // edx
  unsigned __int16 *v251; // ecx
  __m128 v252; // xmm0
  __m128 *v253; // eax
  float v254; // edx
  __m128 *v255; // eax
  __m128 v256; // xmm1
  __m128 *v257; // edx
  unsigned __int16 *v258; // ecx
  __m128 v259; // xmm0
  unsigned __int16 *v260; // eax
  int v261; // ecx
  float v262; // xmm0_4
  int v263; // edx
  int v264; // eax
  float v265; // ecx
  float v266; // eax
  float v267; // edx
  int v268; // eax
  __m128 v269; // xmm5
  __m128 v270; // xmm4
  __int16 v271; // ax
  __m128 v272; // xmm2
  int v273; // eax
  int v274; // ecx
  __m128 v275; // xmm1
  __m128 *v276; // eax
  __m128 *v277; // edx
  __m128 v278; // xmm0
  int v279; // edx
  __m128 v280; // xmm1
  unsigned __int16 *v281; // edx
  __m128 *v282; // eax
  __m128 v283; // xmm3
  __m128 v284; // xmm2
  __m128 v285; // xmm0
  __m128 v286; // xmm3
  int v287; // ecx
  int v288; // eax
  __m128 v289; // xmm5
  __m128 v290; // xmm4
  __m128 v291; // xmm5
  __m128 v292; // xmm5
  __m128 v293; // xmm3
  __m128 v294; // xmm4
  __m128 v295; // xmm3
  __m128 v296; // xmm4
  __m128 v297; // xmm0
  __m128 v298; // xmm4
  __m128 v299; // xmm5
  __m128 v300; // xmm1
  __m128 v301; // xmm2
  __m128 v302; // xmm4
  __m128 v303; // xmm4
  __m128 v304; // xmm1
  __m128 v305; // xmm5
  __m128 v306; // xmm3
  __m128 v307; // xmm2
  __m128 v308; // xmm3
  int v309; // kr00_4
  __m128 v310; // xmm1
  __m128 v311; // xmm1
  __m128 v312; // xmm1
  __m128 v313; // xmm1
  __m128 v314; // xmm0
  int v315; // eax
  __m128 *v316; // ecx
  int v317; // eax
  __m128 v318; // xmm3
  __m128 v319; // xmm0
  int v320; // eax
  int v321; // ecx
  float v322; // eax
  float v323; // edx
  float v324; // ecx
  __m128 *v325; // eax
  int v326; // eax
  __m128 v327; // xmm4
  __int16 v328; // ax
  int v329; // eax
  __m128 v330; // xmm2
  int v331; // ecx
  __m128 v332; // xmm1
  __m128 *v333; // eax
  __m128 *v334; // edx
  __m128 v335; // xmm0
  unsigned __int16 *v336; // edx
  __m128 v337; // xmm1
  int v338; // ecx
  __m128 *v339; // eax
  __m128 v340; // xmm0
  __m128 v341; // xmm2
  __m128 v342; // xmm0
  __m128 v343; // xmm3
  int v344; // ecx
  int v345; // eax
  __m128 v346; // xmm5
  __m128 v347; // xmm4
  __m128 v348; // xmm5
  __m128 v349; // xmm5
  __m128 v350; // xmm3
  __m128 v351; // xmm4
  __m128 v352; // xmm3
  __m128 v353; // xmm4
  __m128 v354; // xmm0
  __m128 v355; // xmm4
  __m128 v356; // xmm5
  __m128 v357; // xmm1
  __m128 v358; // xmm2
  __m128 v359; // xmm4
  __m128 v360; // xmm4
  __m128 v361; // xmm1
  __m128 v362; // xmm5
  __m128 v363; // xmm3
  __m128 v364; // xmm2
  __m128 v365; // xmm3
  int v366; // kr08_4
  __m128 v367; // xmm1
  __m128 v368; // xmm1
  __m128 v369; // xmm1
  __m128 v370; // xmm1
  __m128 v371; // xmm0
  int v372; // eax
  __m128 *v373; // ecx
  int v374; // eax
  __m128 v375; // xmm3
  __m128 v376; // xmm0
  int v377; // eax
  int v378; // ecx
  float v379; // eax
  float v380; // edx
  float v381; // ecx
  __m128 *v382; // eax
  int v383; // eax
  __int16 v384; // ax
  int v385; // ecx
  __m128 v386; // xmm2
  __m128 *v387; // eax
  int v388; // ecx
  __m128 v389; // xmm1
  __m128 *v390; // edx
  __m128 v391; // xmm0
  int v392; // edx
  __m128 v393; // xmm1
  unsigned __int16 *v394; // edx
  __m128 *v395; // eax
  __m128 v396; // xmm3
  __m128 v397; // xmm2
  __m128 v398; // xmm0
  __m128 v399; // xmm3
  int v400; // ecx
  int v401; // eax
  __m128 v402; // xmm5
  __m128 v403; // xmm4
  __m128 v404; // xmm5
  __m128 v405; // xmm5
  __m128 v406; // xmm3
  __m128 v407; // xmm4
  __m128 v408; // xmm3
  __m128 v409; // xmm4
  __m128 v410; // xmm0
  __m128 v411; // xmm4
  __m128 v412; // xmm5
  __m128 v413; // xmm1
  __m128 v414; // xmm2
  __m128 v415; // xmm4
  __m128 v416; // xmm4
  __m128 v417; // xmm1
  __m128 v418; // xmm5
  __m128 v419; // xmm3
  __m128 v420; // xmm2
  __m128 v421; // xmm3
  int v422; // kr10_4
  __m128 v423; // xmm1
  __m128 v424; // xmm1
  __m128 v425; // xmm1
  __m128 v426; // xmm1
  __m128 v427; // xmm0
  int v428; // eax
  __m128 *v429; // ecx
  int v430; // eax
  __m128 v431; // xmm3
  __m128 v432; // xmm0
  int v433; // eax
  int v434; // ecx
  float v435; // eax
  float v436; // edx
  float v437; // ecx
  __m128 *v438; // eax
  int v439; // eax
  __int16 v440; // ax
  int v441; // ecx
  __m128 v442; // xmm2
  __m128 *v443; // eax
  int v444; // ecx
  __m128 v445; // xmm1
  __m128 *v446; // edx
  __m128 v447; // xmm0
  int v448; // edx
  __m128 v449; // xmm1
  unsigned __int16 *v450; // edx
  __m128 *v451; // eax
  __m128 v452; // xmm3
  __m128 v453; // xmm2
  __m128 v454; // xmm0
  __m128 v455; // xmm3
  int v456; // ecx
  int v457; // eax
  __m128 v458; // xmm5
  __m128 v459; // xmm4
  __m128 v460; // xmm5
  __m128 v461; // xmm5
  __m128 v462; // xmm3
  __m128 v463; // xmm4
  __m128 v464; // xmm3
  __m128 v465; // xmm4
  __m128 v466; // xmm0
  __m128 v467; // xmm4
  __m128 v468; // xmm5
  __m128 v469; // xmm1
  __m128 v470; // xmm2
  __m128 v471; // xmm4
  __m128 v472; // xmm4
  __m128 v473; // xmm1
  __m128 v474; // xmm5
  __m128 v475; // xmm3
  __m128 v476; // xmm2
  __m128 v477; // xmm3
  int v478; // eax
  int v479; // esi
  __m128 v480; // xmm1
  __m128 v481; // xmm1
  __m128 v482; // xmm1
  __m128 v483; // xmm1
  __m128 v484; // xmm0
  unsigned __int16 v485; // cx
  int v486; // eax
  int v487; // eax
  __m128 v488; // xmm3
  __m128 *v489; // ecx
  __m128 v490; // xmm0
  int v491; // eax
  int v492; // esi
  unsigned __int16 *v493; // eax
  int v494; // esi
  int v495; // ecx
  _WORD *v496; // eax
  double v497; // xmm0_8
  __m128 v498; // xmm1
  double v499; // xmm0_8
  int v500; // edx
  __m128 v501; // xmm1
  __m128 v502; // xmm1
  __m128 v503; // xmm3
  int v504; // eax
  int v505; // ecx
  int v506; // esi
  int v507; // eax
  double v508; // xmm0_8
  __m128 v509; // xmm1
  double v510; // xmm0_8
  int v511; // ecx
  __m128 v512; // xmm1
  int v513; // edx
  __m128 v514; // xmm1
  __m128 v515; // xmm3
  int v516; // eax
  int v517; // ecx
  int v518; // esi
  int v519; // eax
  double v520; // xmm0_8
  __m128 v521; // xmm1
  double v522; // xmm0_8
  __m128 v523; // xmm1
  __m128 v524; // xmm1
  int v525; // ecx
  __m128 v526; // xmm3
  __m128 v527; // xmm2
  __m128 v528; // xmm1
  unsigned __int16 *v529; // eax
  _WORD *v530; // edi
  int v531; // esi
  __m128 v532; // xmm0
  int v533; // ecx
  double v534; // xmm0_8
  __m128 v535; // xmm1
  double v536; // xmm0_8
  __m128 v537; // xmm1
  __m128 v538; // xmm1
  __m128 v539; // xmm3
  __m128 v540; // [esp+34h] [ebp-730h]
  __m128 v541; // [esp+54h] [ebp-710h]
  Vector4D v542; // [esp+94h] [ebp-6D0h]
  __m128 OutTanU[16]; // [esp+A4h] [ebp-6C0h]
  __m128 OutTanV[16]; // [esp+1A4h] [ebp-5C0h]
  __m128 v545; // [esp+2A4h] [ebp-4C0h]
  __m128 v546; // [esp+2B4h] [ebp-4B0h]
  __m128 v547; // [esp+2C4h] [ebp-4A0h]
  __m128 v548; // [esp+2D4h] [ebp-490h]
  __m128 v549; // [esp+2E4h] [ebp-480h]
  __m128 v550; // [esp+2F4h] [ebp-470h]
  __m128 v551; // [esp+304h] [ebp-460h]
  __m128 v552; // [esp+314h] [ebp-450h]
  __m128 v553; // [esp+324h] [ebp-440h]
  __m128 v554; // [esp+334h] [ebp-430h]
  __m128 v555; // [esp+344h] [ebp-420h]
  __m128 v556; // [esp+354h] [ebp-410h]
  __m128 v557; // [esp+364h] [ebp-400h]
  __m128 v558; // [esp+374h] [ebp-3F0h]
  __m128 v559; // [esp+384h] [ebp-3E0h]
  __m128 v560; // [esp+394h] [ebp-3D0h]
  __m128 v561; // [esp+3A4h] [ebp-3C0h]
  __m128 v562; // [esp+3B4h] [ebp-3B0h]
  __m128 v563; // [esp+3C4h] [ebp-3A0h]
  __m128 v564; // [esp+3D4h] [ebp-390h]
  __m128 v565; // [esp+3E4h] [ebp-380h]
  __m128 v566; // [esp+3F4h] [ebp-370h]
  __m128 v567; // [esp+404h] [ebp-360h]
  __m128 v568; // [esp+414h] [ebp-350h]
  __m128 v569; // [esp+424h] [ebp-340h]
  __m128 v570; // [esp+434h] [ebp-330h]
  __m128 v571; // [esp+444h] [ebp-320h]
  __m128 v572; // [esp+454h] [ebp-310h]
  __m128 v573; // [esp+464h] [ebp-300h]
  _DWORD v574[6]; // [esp+474h] [ebp-2F0h] BYREF
  _DWORD v575[6]; // [esp+48Ch] [ebp-2D8h] BYREF
  _DWORD v576[6]; // [esp+4A4h] [ebp-2C0h] BYREF
  _DWORD v577[6]; // [esp+4BCh] [ebp-2A8h] BYREF
  __m128 v578; // [esp+4D4h] [ebp-290h]
  __m128 OutPos[16]; // [esp+4E4h] [ebp-280h]
  __m128 v580; // [esp+5E4h] [ebp-180h]
  __m128 u20; // [esp+5F4h] [ebp-170h]
  __m128 v582; // [esp+604h] [ebp-160h]
  __m128 c0; // [esp+614h] [ebp-150h]
  __m128 v584; // [esp+624h] [ebp-140h]
  __m128 u10; // [esp+634h] [ebp-130h]
  __m128 v586; // [esp+644h] [ebp-120h]
  __m128 u00; // [esp+654h] [ebp-110h]
  float v588; // [esp+664h] [ebp-100h]
  float v589; // [esp+668h] [ebp-FCh]
  float v590; // [esp+66Ch] [ebp-F8h]
  float v591; // [esp+670h] [ebp-F4h]
  __m128 flLoopGap; // [esp+674h] [ebp-F0h]
  int v593; // [esp+690h] [ebp-D4h]
  int v594; // [esp+694h] [ebp-D0h]
  unsigned __int16 *v595; // [esp+6B0h] [ebp-B4h]
  unsigned __int16 *v596; // [esp+6B4h] [ebp-B0h]
  unsigned __int16 *v597; // [esp+6B8h] [ebp-ACh]
  unsigned __int16 *v598; // [esp+6BCh] [ebp-A8h]
  unsigned __int16 *pOneRing[4]; // [esp+6C0h] [ebp-A4h]
  unsigned __int16 *v600; // [esp+6E0h] [ebp-84h]
  __m128 *v601; // [esp+6E4h] [ebp-80h]
  int v602; // [esp+6E8h] [ebp-7Ch]
  __m128 *v603; // [esp+6ECh] [ebp-78h]
  float v604; // [esp+6F0h] [ebp-74h]
  __m128 *v605; // [esp+6F4h] [ebp-70h]
  __m128 *v606; // [esp+70Ch] [ebp-58h]
  int v607; // [esp+710h] [ebp-54h]
  __m128 *v608; // [esp+714h] [ebp-50h]
  __m128 *v609; // [esp+730h] [ebp-34h]
  __m128 *v610; // [esp+734h] [ebp-30h]
  _BYTE *v611; // [esp+744h] [ebp-20h]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+748h] [ebp-1Ch]
  int v613; // [esp+74Ch] [ebp-18h]
  _BYTE v614[20]; // [esp+750h] [ebp-14h] BYREF
  __m128 *retaddr; // [esp+764h] [ebp+0h]

  *(_DWORD *)&v614[4] = a1;
  *(_DWORD *)&v614[8] = *(_DWORD *)&v614[16];
  *(_DWORD *)v614 = -1;
  v613 = (int)&_ehhandler__ComputeACCAllPatches__YAXPAT__m128__PAUTopologyIndexStruct__PAVVector4D__22_N_Z;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v611 = &v614[12];
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCAllPatches (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  *(_DWORD *)v614 = 0;
  v6 = *(unsigned __int16 *)pPos->m128_i32[0];
  v595 = (unsigned __int16 *)pPos[2].m128_i32[2];
  v7 = *(unsigned __int16 *)(pPos->m128_i32[0] + 2);
  v596 = (unsigned __int16 *)(pPos[2].m128_i32[2] + 2 * v6);
  v8 = v7 + v6;
  v9 = *(unsigned __int16 *)(pPos->m128_i32[0] + 4);
  v10 = pPos[2].m128_i32[2];
  *(_DWORD *)v614 = 4;
  v613 = 0;
  ExceptionList = (_EXCEPTION_REGISTRATION_RECORD *)"SubD Rendering";
  v597 = (unsigned __int16 *)(v10 + 2 * v8);
  v598 = (unsigned __int16 *)(pPos[2].m128_i32[2] + 2 * (v9 + v8));
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCAllPatches - Geometry Control Points (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  v614[0] = 1;
  v11 = (unsigned __int16 *)pPos[1].m128_i32[0];
  v12 = *(_WORD *)pPos[1].m128_i32[2];
  v13 = (unsigned __int16 *)pPos->m128_i32[3];
  v608 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[2];
  v14 = *v11;
  LODWORD(v15) = *v13;
  *(_DWORD *)v614 = 4;
  v613 = 0;
  v607 = v14;
  v16 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[0];
  v604 = v15;
  v603 = v16;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( v12 != 0 )
  {
    v17 = retaddr;
    v578 = retaddr[*v595];
  }
  else
  {
    if ( (_WORD)v607 != 0 )
      v18 = sPosCornerBndStencil[(unsigned __int16)v608];
    else
      v18 = sPosCornerStencil[(unsigned __int16)v608];
    v17 = retaddr;
    v19 = _mm_mul_ps(*v18, retaddr[*v595]);
    v608 = v18;
    v578 = v19;
    if ( (_WORD)v603 != 0 )
    {
      v20 = LOWORD(v604);
      v609 = (__m128 *)LOWORD(v604);
      v606 = (__m128 *)(unsigned __int16)v603;
      do
      {
        v21 = v20 % (unsigned __int16)v603;
        if ( v21 != 0 )
        {
          v19 = _mm_add_ps(v19, _mm_mul_ps(v608[v21], retaddr[v595[v21]]));
          v578 = v19;
        }
        v20 = (int)v609->m128_i32 + 1;
        v22 = v606 == (__m128 *)1;
        v606 = (__m128 *)((char *)v606 - 1);
        v609 = (__m128 *)((char *)v609 + 1);
      }
      while ( !v22 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v23 = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 2);
  v608 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 2);
  LODWORD(v24) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 2);
  *(_DWORD *)v614 = 4;
  v607 = v23;
  v25 = *(unsigned __int16 *)(pPos->m128_i32[3] + 2);
  v613 = 0;
  v604 = v24;
  v26 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 2);
  v602 = v25;
  v603 = v26;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v607 != 0 )
  {
    OutPos[2] = v17[*v596];
  }
  else
  {
    if ( LOWORD(v604) != 0 )
      v27 = sPosCornerBndStencil[(unsigned __int16)v608];
    else
      v27 = sPosCornerStencil[(unsigned __int16)v608];
    v28 = *v596;
    v29 = *v27;
    v608 = v27;
    v30 = _mm_mul_ps(v29, v17[v28]);
    OutPos[2] = v30;
    if ( (_WORD)v603 != 0 )
    {
      v31 = (unsigned __int16)v602;
      v609 = (__m128 *)(unsigned __int16)v602;
      v606 = (__m128 *)(unsigned __int16)v603;
      do
      {
        v32 = v31 % (unsigned __int16)v603;
        if ( v32 != 0 )
        {
          v30 = _mm_add_ps(v30, _mm_mul_ps(v608[v32], v17[v596[v32]]));
          OutPos[2] = v30;
        }
        v31 = (int)v609->m128_i32 + 1;
        v22 = v606 == (__m128 *)1;
        v606 = (__m128 *)((char *)v606 - 1);
        v609 = (__m128 *)((char *)v609 + 1);
      }
      while ( !v22 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v33 = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 4);
  v608 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 4);
  LODWORD(v34) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 4);
  *(_DWORD *)v614 = 4;
  v607 = v33;
  v35 = *(unsigned __int16 *)(pPos->m128_i32[3] + 4);
  v613 = 0;
  v604 = v34;
  v36 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 4);
  v602 = v35;
  v603 = v36;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v607 != 0 )
  {
    OutPos[14] = v17[*v597];
  }
  else
  {
    if ( LOWORD(v604) != 0 )
      v37 = sPosCornerBndStencil[(unsigned __int16)v608];
    else
      v37 = sPosCornerStencil[(unsigned __int16)v608];
    v38 = *v597;
    v39 = *v37;
    v608 = v37;
    v40 = _mm_mul_ps(v39, v17[v38]);
    OutPos[14] = v40;
    if ( (_WORD)v603 != 0 )
    {
      v41 = (unsigned __int16)v602;
      v609 = (__m128 *)(unsigned __int16)v602;
      v606 = (__m128 *)(unsigned __int16)v603;
      do
      {
        v42 = v41 % (unsigned __int16)v603;
        if ( v42 != 0 )
        {
          v40 = _mm_add_ps(v40, _mm_mul_ps(v608[v42], v17[v597[v42]]));
          OutPos[14] = v40;
        }
        v41 = (int)v609->m128_i32 + 1;
        v22 = v606 == (__m128 *)1;
        v606 = (__m128 *)((char *)v606 - 1);
        v609 = (__m128 *)((char *)v609 + 1);
      }
      while ( !v22 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v43 = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 6);
  v608 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 6);
  LODWORD(v44) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 6);
  *(_DWORD *)v614 = 4;
  v607 = v43;
  v45 = *(unsigned __int16 *)(pPos->m128_i32[3] + 6);
  v613 = 0;
  v604 = v44;
  v46 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 6);
  v602 = v45;
  v603 = v46;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeCatmullClarkLimitPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v607 != 0 )
  {
    OutPos[11] = v17[*v598];
  }
  else
  {
    if ( LOWORD(v604) != 0 )
      v47 = sPosCornerBndStencil[(unsigned __int16)v608];
    else
      v47 = sPosCornerStencil[(unsigned __int16)v608];
    v48 = *v598;
    v49 = *v47;
    v608 = v47;
    v50 = _mm_mul_ps(v49, v17[v48]);
    OutPos[11] = v50;
    if ( (_WORD)v603 != 0 )
    {
      v51 = (unsigned __int16)v602;
      v609 = (__m128 *)(unsigned __int16)v602;
      v606 = (__m128 *)(unsigned __int16)v603;
      do
      {
        v52 = v51 % (unsigned __int16)v603;
        if ( v52 != 0 )
        {
          v50 = _mm_add_ps(v50, _mm_mul_ps(v608[v52], v17[v598[v52]]));
          OutPos[11] = v50;
        }
        v51 = (int)v609->m128_i32 + 1;
        v22 = v606 == (__m128 *)1;
        v606 = (__m128 *)((char *)v606 - 1);
        v609 = (__m128 *)((char *)v609 + 1);
      }
      while ( !v22 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  pOneRing[0] = (unsigned __int16 *)*(unsigned __int16 *)pPos->m128_i32[3];
  v53 = (unsigned __int16 *)pPos->m128_i32[2];
  v54 = (__m128 *)v53[3];
  v55 = (__m128 *)*v53;
  v56 = pPos[2].m128_i32[0];
  v603 = v54;
  v57 = *(unsigned __int16 *)(v56 + 14);
  v608 = v55;
  v58 = *(unsigned __int16 *)(v56 + 12);
  v59 = (unsigned __int16 *)pPos[1].m128_i32[2];
  v602 = v57;
  v60 = v59[3];
  v594 = v58;
  v61 = (__m128 *)*v59;
  v62 = (unsigned __int16 *)pPos[1].m128_i32[0];
  v593 = v60;
  LODWORD(v63) = v62[3];
  v606 = v61;
  v64 = *v62;
  v65 = pPos[1].m128_i32[1];
  *(_DWORD *)v614 = 4;
  v613 = 0;
  v604 = v63;
  v66 = (__m128 *)*(unsigned __int16 *)(v65 + 6);
  v607 = v64;
  v67 = (unsigned __int16 *)*(unsigned __int16 *)pPos->m128_i32[1];
  v609 = v66;
  v600 = v67;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePositions (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v607 != 0 )
    v68 = 2 * (_WORD)v608 - 2;
  else
    v68 = (unsigned __int16)v608;
  v69 = (unsigned __int16)v603;
  if ( LOWORD(v604) != 0 )
    v69 = 2 * (_WORD)v603 - 2;
  v70 = (__int16)v609;
  v603 = (__m128 *)v68;
  v71 = v68;
  if ( (_WORD)v609 != 0 )
  {
    if ( (_WORD)v606 != 0 )
      v72 = sPosEdge1CornerStencil[v71];
    else
      v72 = sPosEdge1BndStencil[v71];
    v609 = v72;
    v608 = (__m128 *)v69;
    v73 = v69;
    if ( (_WORD)v593 != 0 )
      v74 = sPosEdge2CornerStencil[v73];
    else
      v74 = sPosEdge2BndStencil[v73];
  }
  else
  {
    v609 = sPosEdge1Stencil[v71];
    v608 = (__m128 *)v69;
    v74 = sPosEdge2Stencil[v69];
  }
  v606 = v74;
  v75 = 2 * (v70 == 0) + 4;
  v593 = v75;
  if ( (_WORD)v594 == 0x4000 && (_WORD)v602 == 0x4000 )
  {
    v76 = 1;
    memset(v577, 0, sizeof(v577));
    if ( 2 * (unsigned int)(v70 == 0) + 4 > 1 )
    {
      v77 = (unsigned __int16)v600;
      do
        v577[v76++] = v77++;
      while ( v76 < v75 );
    }
    v78 = Four_Zeros;
    v79 = Four_Zeros;
    OutPos[7] = Four_Zeros;
    OutPos[3] = Four_Zeros;
    if ( v75 > 0 )
    {
      v80 = LOWORD(pOneRing[0]);
      v608 = (__m128 *)LOWORD(pOneRing[0]);
      v603 = (__m128 *)v75;
      while ( 1 )
      {
        v81 = v80 % v75;
        v82 = v595[v577[v80 % v75]];
        v81 *= 2;
        v79 = _mm_add_ps(v79, _mm_mul_ps(*(__m128 *)((char *)v609 + 8 * v81), v17[v82]));
        OutPos[3] = v79;
        v83 = _mm_mul_ps(*(__m128 *)((char *)v606 + 8 * v81), v17[v82]);
        v80 = (int)v608->m128_i32 + 1;
        v22 = v603 == (__m128 *)1;
        v603 = (__m128 *)((char *)v603 - 1);
        v78 = _mm_add_ps(v78, v83);
        OutPos[7] = v78;
        v608 = (__m128 *)((char *)v608 + 1);
        if ( v22 )
          break;
        v75 = v593;
      }
    }
  }
  else
  {
    v84 = 0;
    v84.m128_f32[0] = (float)(unsigned __int16)v594 * 0.000030517578;
    v85 = _mm_shuffle_ps(v84, v84, 0);
    v86 = _mm_mul_ps(_mm_mul_ps(v85, Four_Twos), v17[v595[(unsigned __int16)v600 + 4]]);
    v87 = _mm_sub_ps(Four_Ones, v85);
    v88 = _mm_mul_ps(v17[v595[(unsigned __int16)v600 + 3]], v85);
    v89 = v17[v595[(unsigned __int16)v600 + 2]];
    v90 = _mm_mul_ps(v17[v595[(unsigned __int16)v600 + 1]], v87);
    flLoopGap = _mm_mul_ps(_mm_mul_ps(v87, Four_Twos), v17[v595[(unsigned __int16)v600]]);
    pOneRing[0] = (unsigned __int16 *)&v17[*v595];
    v91 = Four_Valence[(_DWORD)v603];
    v594 = 16 * (_DWORD)v603;
    v92 = Four_ValencePlus5[(_DWORD)v603];
    OutPos[3] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_add_ps(_mm_mul_ps(v91, *(__m128 *)pOneRing[0]), flLoopGap), v90),
                        _mm_mul_ps(v89, Four_Twos)),
                      v88),
                    v86),
                  v92);
    v93 = 0;
    v93.m128_f32[0] = (float)(unsigned __int16)v602 * 0.000030517578;
    v94 = _mm_shuffle_ps(v93, v93, 0);
    v95 = _mm_mul_ps(v94, v17[v595[(unsigned __int16)v600 + 4]]);
    v96 = v17[v595[(unsigned __int16)v600 + 3]];
    pOneRing[0] = (unsigned __int16 *)&v17[v595[(unsigned __int16)v600 + 2]];
    v97 = _mm_mul_ps(v96, _mm_mul_ps(v94, Four_Twos));
    v98 = _mm_sub_ps(Four_Ones, v94);
    OutPos[7] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(v17[*v595], Four_Twos),
                            _mm_mul_ps(v17[v595[(unsigned __int16)v600]], v98)),
                          _mm_mul_ps(_mm_mul_ps(v98, Four_Twos), v17[v595[(unsigned __int16)v600 + 1]])),
                        _mm_mul_ps(Four_Valence[(_DWORD)v608], *(__m128 *)pOneRing[0])),
                      v97),
                    v95),
                  v92);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  LODWORD(v99) = *(unsigned __int16 *)(pPos->m128_i32[3] + 2);
  v100 = (unsigned __int16 *)pPos->m128_i32[2];
  v101 = (unsigned __int16 *)*v100;
  v602 = v100[1];
  v102 = (unsigned __int16 *)pPos[2].m128_i32[0];
  *(float *)&v601 = v99;
  v103 = v102[1];
  v600 = v101;
  v104 = (unsigned __int16 *)*v102;
  v105 = (unsigned __int16 *)pPos[1].m128_i32[2];
  v607 = v103;
  v106 = (__m128 *)*v105;
  pOneRing[1] = v104;
  v107 = (__m128 *)v105[1];
  v108 = (unsigned __int16 *)pPos[1].m128_i32[0];
  v603 = v106;
  v109 = *v108;
  v608 = v107;
  v110 = (unsigned __int16 *)v108[1];
  v111 = (unsigned __int16 *)pPos[1].m128_i32[1];
  *(_DWORD *)v614 = 4;
  v613 = 0;
  v594 = v109;
  v112 = *v111;
  pOneRing[0] = v110;
  LODWORD(v113) = *(unsigned __int16 *)(pPos->m128_i32[1] + 2);
  v593 = v112;
  v604 = v113;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePositions (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( LOWORD(pOneRing[0]) != 0 )
    v114 = 2 * v602 - 2;
  else
    v114 = v602;
  v115 = (unsigned __int16)v600;
  if ( (_WORD)v594 != 0 )
    v115 = 2 * (_WORD)v600 - 2;
  v609 = (__m128 *)v114;
  v116 = v114;
  if ( (_WORD)v593 != 0 )
  {
    if ( (_WORD)v608 != 0 )
      v117 = sPosEdge1CornerStencil[v116];
    else
      v117 = sPosEdge1BndStencil[v116];
    v608 = v117;
    v606 = (__m128 *)v115;
    v118 = v115;
    if ( (_WORD)v603 != 0 )
      v119 = sPosEdge2CornerStencil[v118];
    else
      v119 = sPosEdge2BndStencil[v118];
  }
  else
  {
    v608 = sPosEdge1Stencil[v116];
    v606 = (__m128 *)v115;
    v119 = sPosEdge2Stencil[v115];
  }
  v603 = v119;
  v120 = (unsigned __int16 *)(2 * ((_WORD)v593 == 0) + 4);
  pOneRing[0] = v120;
  if ( LOWORD(pOneRing[1]) == 0x4000 && (_WORD)v607 == 0x4000 )
  {
    v121 = 1;
    memset(v575, 0, sizeof(v575));
    if ( 2 * (unsigned int)((_WORD)v593 == 0) + 4 > 1 )
    {
      v122 = LOWORD(v604);
      do
        v575[v121++] = v122++;
      while ( v121 < (int)v120 );
    }
    v123 = Four_Zeros;
    v124 = Four_Zeros;
    OutPos[0] = Four_Zeros;
    OutPos[1] = Four_Zeros;
    if ( (int)v120 > 0 )
    {
      v125 = (unsigned __int16)v601;
      v602 = (unsigned __int16)v601;
      v600 = v120;
      while ( 1 )
      {
        v126 = v125 % (int)v120;
        v127 = v596[v575[v125 % (int)v120]];
        v126 *= 2;
        v124 = _mm_add_ps(v124, _mm_mul_ps(*(__m128 *)((char *)v608 + 8 * v126), v17[v127]));
        OutPos[1] = v124;
        v128 = _mm_mul_ps(*(__m128 *)((char *)v603 + 8 * v126), v17[v127]);
        v125 = v602 + 1;
        v22 = v600 == (unsigned __int16 *)1;
        v600 = (unsigned __int16 *)((char *)v600 - 1);
        v123 = _mm_add_ps(v123, v128);
        OutPos[0] = v123;
        ++v602;
        if ( v22 )
          break;
        v120 = pOneRing[0];
      }
    }
  }
  else
  {
    v129 = 0;
    v129.m128_f32[0] = (float)LOWORD(pOneRing[1]) * 0.000030517578;
    v130 = _mm_shuffle_ps(v129, v129, 0);
    v131 = _mm_mul_ps(v17[v596[LOWORD(v604) + 4]], _mm_mul_ps(v130, Four_Twos));
    v132 = _mm_mul_ps(v17[v596[LOWORD(v604) + 3]], v130);
    v133 = _mm_sub_ps(Four_Ones, v130);
    v134 = v17[v596[LOWORD(v604) + 2]];
    v135 = _mm_mul_ps(v17[v596[LOWORD(v604) + 1]], v133);
    flLoopGap = _mm_mul_ps(v17[v596[LOWORD(v604)]], _mm_mul_ps(v133, Four_Twos));
    v601 = &v17[*v596];
    v136 = Four_Valence[(_DWORD)v609];
    pOneRing[1] = (unsigned __int16 *)(16 * (_DWORD)v609);
    v137 = Four_ValencePlus5[(_DWORD)v609];
    OutPos[1] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_add_ps(_mm_mul_ps(v136, *v601), flLoopGap), v135),
                        _mm_mul_ps(v134, Four_Twos)),
                      v132),
                    v131),
                  v137);
    v138 = 0;
    v138.m128_f32[0] = (float)(unsigned __int16)v607 * 0.000030517578;
    v139 = _mm_shuffle_ps(v138, v138, 0);
    flLoopGap = _mm_sub_ps(Four_Ones, v139);
    v140 = _mm_mul_ps(v17[v596[LOWORD(v604) + 4]], v139);
    v141 = _mm_mul_ps(v17[v596[LOWORD(v604) + 3]], _mm_mul_ps(v139, Four_Twos));
    v601 = &v17[v596[LOWORD(v604) + 2]];
    OutPos[0] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(v17[*v596], Four_Twos), _mm_mul_ps(v17[v596[LOWORD(v604)]], flLoopGap)),
                          _mm_mul_ps(v17[v596[LOWORD(v604) + 1]], _mm_mul_ps(flLoopGap, Four_Twos))),
                        _mm_mul_ps(Four_Valence[(_DWORD)v606], *v601)),
                      v141),
                    v140),
                  v137);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  LODWORD(v142) = *(unsigned __int16 *)(pPos->m128_i32[3] + 4);
  v143 = pPos->m128_i32[2];
  LODWORD(v144) = *(unsigned __int16 *)(v143 + 2);
  v607 = *(unsigned __int16 *)(v143 + 4);
  v145 = pPos[2].m128_i32[0];
  *(float *)&v610 = v142;
  v146 = (unsigned __int16 *)*(unsigned __int16 *)(v145 + 6);
  v604 = v144;
  LODWORD(v147) = *(unsigned __int16 *)(v145 + 4);
  v148 = pPos[1].m128_i32[2];
  v600 = v146;
  v149 = *(unsigned __int16 *)(v148 + 2);
  *(float *)&v605 = v147;
  v150 = *(unsigned __int16 *)(v148 + 4);
  v151 = pPos[1].m128_i32[0];
  v593 = v149;
  v152 = (unsigned __int16 *)*(unsigned __int16 *)(v151 + 2);
  v594 = v150;
  LODWORD(v153) = *(unsigned __int16 *)(v151 + 4);
  v154 = pPos[1].m128_i32[1];
  *(_DWORD *)v614 = 4;
  v613 = 0;
  pOneRing[1] = v152;
  v155 = (unsigned __int16 *)*(unsigned __int16 *)(v154 + 2);
  *(float *)&v601 = v153;
  v156 = *(unsigned __int16 *)(pPos->m128_i32[1] + 4);
  pOneRing[0] = v155;
  v602 = v156;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePositions (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v601 != 0 )
    v157 = 2 * v607 - 2;
  else
    v157 = v607;
  v158 = LOWORD(v604);
  if ( LOWORD(pOneRing[1]) != 0 )
    v158 = 2 * LOWORD(v604) - 2;
  v609 = (__m128 *)v157;
  v159 = v157;
  if ( LOWORD(pOneRing[0]) != 0 )
  {
    if ( (_WORD)v594 != 0 )
      v160 = sPosEdge1CornerStencil[v159];
    else
      v160 = sPosEdge1BndStencil[v159];
    v608 = v160;
    v606 = (__m128 *)v158;
    v161 = v158;
    if ( (_WORD)v593 != 0 )
      v162 = sPosEdge2CornerStencil[v161];
    else
      v162 = sPosEdge2BndStencil[v161];
  }
  else
  {
    v608 = sPosEdge1Stencil[v159];
    v606 = (__m128 *)v158;
    v162 = sPosEdge2Stencil[v158];
  }
  v603 = v162;
  LODWORD(v163) = 2 * (LOWORD(pOneRing[0]) == 0) + 4;
  *(float *)&v601 = v163;
  if ( (_WORD)v605 == 0x4000 && (_WORD)v600 == 0x4000 )
  {
    v164 = 1;
    memset(v576, 0, sizeof(v576));
    if ( 2 * (unsigned int)(LOWORD(pOneRing[0]) == 0) + 4 > 1 )
    {
      v165 = (unsigned __int16)v602;
      do
        v576[v164++] = v165++;
      while ( v164 < SLODWORD(v163) );
    }
    v166 = Four_Zeros;
    v167 = Four_Zeros;
    OutPos[6] = Four_Zeros;
    OutPos[10] = Four_Zeros;
    if ( SLODWORD(v163) > 0 )
    {
      v168 = (unsigned __int16)v610;
      v607 = (unsigned __int16)v610;
      v604 = v163;
      while ( 1 )
      {
        v169 = v168 % SLODWORD(v163);
        v170 = v597[v576[v168 % SLODWORD(v163)]];
        v169 *= 2;
        v167 = _mm_add_ps(v167, _mm_mul_ps(*(__m128 *)((char *)v608 + 8 * v169), v17[v170]));
        OutPos[10] = v167;
        v171 = _mm_mul_ps(*(__m128 *)((char *)v603 + 8 * v169), v17[v170]);
        v168 = v607 + 1;
        v22 = LODWORD(v604)-- == 1;
        v166 = _mm_add_ps(v166, v171);
        OutPos[6] = v166;
        ++v607;
        if ( v22 )
          break;
        v163 = *(float *)&v601;
      }
    }
  }
  else
  {
    v172 = 0;
    v172.m128_f32[0] = (float)(unsigned __int16)v605 * 0.000030517578;
    v173 = _mm_shuffle_ps(v172, v172, 0);
    v174 = _mm_mul_ps(v17[v597[(unsigned __int16)v602 + 4]], _mm_mul_ps(v173, Four_Twos));
    v175 = _mm_mul_ps(v17[v597[(unsigned __int16)v602 + 3]], v173);
    v176 = _mm_sub_ps(Four_Ones, v173);
    v177 = v17[v597[(unsigned __int16)v602 + 2]];
    v178 = _mm_mul_ps(v17[v597[(unsigned __int16)v602 + 1]], v176);
    flLoopGap = _mm_mul_ps(v17[v597[(unsigned __int16)v602]], _mm_mul_ps(v176, Four_Twos));
    v610 = &v17[*v597];
    v179 = Four_Valence[(_DWORD)v609];
    v605 = (__m128 *)(16 * (_DWORD)v609);
    v180 = Four_ValencePlus5[(_DWORD)v609];
    OutPos[10] = _mm_div_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_add_ps(_mm_mul_ps(v179, *v610), flLoopGap), v178),
                         _mm_mul_ps(v177, Four_Twos)),
                       v175),
                     v174),
                   v180);
    v181 = 0;
    v181.m128_f32[0] = (float)(unsigned __int16)v600 * 0.000030517578;
    v182 = _mm_shuffle_ps(v181, v181, 0);
    v183 = _mm_sub_ps(Four_Ones, v182);
    v184 = _mm_mul_ps(v17[v597[(unsigned __int16)v602 + 4]], v182);
    flLoopGap = _mm_mul_ps(_mm_mul_ps(v182, Four_Twos), v17[v597[(unsigned __int16)v602 + 3]]);
    v610 = &v17[v597[(unsigned __int16)v602 + 2]];
    OutPos[6] = _mm_div_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(v17[*v597], Four_Twos),
                            _mm_mul_ps(v17[v597[(unsigned __int16)v602]], v183)),
                          _mm_mul_ps(v17[v597[(unsigned __int16)v602 + 1]], _mm_mul_ps(v183, Four_Twos))),
                        _mm_mul_ps(Four_Valence[(_DWORD)v606], *v610)),
                      flLoopGap),
                    v184),
                  v180);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v185 = *(unsigned __int16 *)(pPos->m128_i32[3] + 6);
  v186 = pPos->m128_i32[2];
  LODWORD(v187) = *(unsigned __int16 *)(v186 + 4);
  v607 = *(unsigned __int16 *)(v186 + 6);
  v188 = pPos[2].m128_i32[0];
  v593 = v185;
  v189 = (unsigned __int16 *)*(unsigned __int16 *)(v188 + 10);
  v604 = v187;
  v190 = *(unsigned __int16 *)(v188 + 8);
  v191 = pPos[1].m128_i32[2];
  v600 = v189;
  v192 = (unsigned __int16 *)*(unsigned __int16 *)(v191 + 4);
  v594 = v190;
  v193 = (unsigned __int16 *)*(unsigned __int16 *)(v191 + 6);
  v194 = pPos[1].m128_i32[0];
  pOneRing[0] = v192;
  LODWORD(v195) = *(unsigned __int16 *)(v194 + 4);
  pOneRing[1] = v193;
  LODWORD(v196) = *(unsigned __int16 *)(v194 + 6);
  v197 = pPos[1].m128_i32[1];
  *(_DWORD *)v614 = 4;
  v613 = 0;
  *(float *)&v605 = v195;
  LODWORD(v198) = *(unsigned __int16 *)(v197 + 4);
  *(float *)&v610 = v196;
  v199 = *(unsigned __int16 *)(pPos->m128_i32[1] + 6);
  *(float *)&v601 = v198;
  v602 = v199;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCEdgePositions (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v610 != 0 )
    v200 = 2 * v607 - 2;
  else
    v200 = v607;
  v201 = LOWORD(v604);
  if ( (_WORD)v605 != 0 )
    v201 = 2 * LOWORD(v604) - 2;
  v609 = (__m128 *)v200;
  v202 = v200;
  if ( (_WORD)v601 != 0 )
  {
    if ( LOWORD(pOneRing[1]) != 0 )
      v203 = sPosEdge1CornerStencil[v202];
    else
      v203 = sPosEdge1BndStencil[v202];
    v608 = v203;
    v606 = (__m128 *)v201;
    v204 = v201;
    if ( LOWORD(pOneRing[0]) != 0 )
      v205 = sPosEdge2CornerStencil[v204];
    else
      v205 = sPosEdge2BndStencil[v204];
  }
  else
  {
    v608 = sPosEdge1Stencil[v202];
    v606 = (__m128 *)v201;
    v205 = sPosEdge2Stencil[v201];
  }
  v603 = v205;
  LODWORD(v206) = 2 * ((_WORD)v601 == 0) + 4;
  *(float *)&v610 = v206;
  if ( (_WORD)v594 == 0x4000 && (_WORD)v600 == 0x4000 )
  {
    v207 = 1;
    memset(v574, 0, sizeof(v574));
    if ( 2 * (unsigned int)((_WORD)v601 == 0) + 4 > 1 )
    {
      v208 = (unsigned __int16)v602;
      do
        v574[v207++] = v208++;
      while ( v207 < SLODWORD(v206) );
    }
    v209 = Four_Zeros;
    v210 = Four_Zeros;
    OutPos[13] = Four_Zeros;
    OutPos[12] = Four_Zeros;
    if ( SLODWORD(v206) > 0 )
    {
      v211 = (unsigned __int16)v593;
      v607 = (unsigned __int16)v593;
      v604 = v206;
      while ( 1 )
      {
        v212 = v211 % SLODWORD(v206);
        v213 = v598[v574[v211 % SLODWORD(v206)]];
        v212 *= 2;
        v210 = _mm_add_ps(v210, _mm_mul_ps(*(__m128 *)((char *)v608 + 8 * v212), v17[v213]));
        OutPos[12] = v210;
        v214 = _mm_mul_ps(*(__m128 *)((char *)v603 + 8 * v212), v17[v213]);
        v211 = v607 + 1;
        v22 = LODWORD(v604)-- == 1;
        v209 = _mm_add_ps(v209, v214);
        OutPos[13] = v209;
        ++v607;
        if ( v22 )
          break;
        v206 = *(float *)&v610;
      }
    }
  }
  else
  {
    v215 = 0;
    v215.m128_f32[0] = (float)(unsigned __int16)v594 * 0.000030517578;
    v216 = _mm_shuffle_ps(v215, v215, 0);
    v217 = _mm_mul_ps(_mm_mul_ps(v216, Four_Twos), v17[v598[(unsigned __int16)v602 + 4]]);
    v218 = _mm_sub_ps(Four_Ones, v216);
    v219 = _mm_mul_ps(v17[v598[(unsigned __int16)v602 + 3]], v216);
    v220 = v17[v598[(unsigned __int16)v602 + 2]];
    v221 = _mm_mul_ps(v17[v598[(unsigned __int16)v602 + 1]], v218);
    flLoopGap = _mm_mul_ps(_mm_mul_ps(v218, Four_Twos), v17[v598[(unsigned __int16)v602]]);
    v610 = &v17[*v598];
    v222 = Four_Valence[(_DWORD)v609];
    v605 = (__m128 *)(16 * (_DWORD)v609);
    v223 = Four_ValencePlus5[(_DWORD)v609];
    OutPos[12] = _mm_div_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_add_ps(_mm_mul_ps(v222, *v610), flLoopGap), v221),
                         _mm_mul_ps(v220, Four_Twos)),
                       v219),
                     v217),
                   v223);
    v224 = v17[v598[(unsigned __int16)v602 + 4]];
    v225 = 0;
    v225.m128_f32[0] = (float)(unsigned __int16)v600 * 0.000030517578;
    v226 = _mm_shuffle_ps(v225, v225, 0);
    v227 = v17[v598[(unsigned __int16)v602 + 3]];
    v610 = &v17[v598[(unsigned __int16)v602 + 2]];
    v228 = _mm_mul_ps(v224, v226);
    v229 = _mm_mul_ps(v227, _mm_mul_ps(v226, Four_Twos));
    v230 = _mm_sub_ps(Four_Ones, v226);
    OutPos[13] = _mm_div_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(v17[*v598], Four_Twos),
                             _mm_mul_ps(v17[v598[(unsigned __int16)v602]], v230)),
                           _mm_mul_ps(_mm_mul_ps(v230, Four_Twos), v17[v598[(unsigned __int16)v602 + 1]])),
                         _mm_mul_ps(Four_Valence[(_DWORD)v606], *v610)),
                       v229),
                     v228),
                   v223);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v231 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[2];
  LODWORD(v232) = *(unsigned __int16 *)pPos[1].m128_i32[0];
  *(_DWORD *)v614 = 4;
  v613 = 0;
  v609 = v231;
  LODWORD(v233) = *(unsigned __int16 *)pPos->m128_i32[1];
  *(float *)&v610 = v232;
  *(float *)&v605 = v233;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCInteriorPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v610 != 0 )
  {
    if ( (unsigned __int16)v609 <= 2u )
      v609 = (__m128 *)(unsigned __int16)(4 * (_WORD)v609 - 4);
    else
      v609 = (__m128 *)(unsigned __int16)(2 * (_WORD)v609 - 2);
  }
  v234 = sPosInteriorStencil[(unsigned __int16)v609];
  v235 = _mm_mul_ps(v17[*v595], *v234);
  v236 = v234 + 1;
  OutPos[4] = v235;
  v237 = &v595[(unsigned __int16)v605];
  v607 = 3;
  do
  {
    v238 = _mm_mul_ps(*v236++, v17[*v237++]);
    v22 = v607-- == 1;
    v235 = _mm_add_ps(v235, v238);
    OutPos[4] = v235;
  }
  while ( !v22 );
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v239 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 2);
  LODWORD(v240) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 2);
  *(_DWORD *)v614 = 4;
  v609 = v239;
  v605 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[1] + 2);
  *(float *)&v610 = v240;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCInteriorPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v610 != 0 )
  {
    if ( (unsigned __int16)v609 <= 2u )
      v609 = (__m128 *)(unsigned __int16)(4 * (_WORD)v609 - 4);
    else
      v609 = (__m128 *)(unsigned __int16)(2 * (_WORD)v609 - 2);
  }
  v241 = sPosInteriorStencil[(unsigned __int16)v609];
  v242 = _mm_mul_ps(v17[*v596], *v241);
  v243 = v241 + 1;
  OutPos[5] = v242;
  v244 = &v596[(unsigned __int16)v605];
  v607 = 3;
  do
  {
    v245 = _mm_mul_ps(v17[*v244++], *v243++);
    v22 = v607-- == 1;
    v242 = _mm_add_ps(v242, v245);
    OutPos[5] = v242;
  }
  while ( !v22 );
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v246 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 4);
  LODWORD(v247) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 4);
  *(_DWORD *)v614 = 4;
  v609 = v246;
  v605 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[1] + 4);
  *(float *)&v610 = v247;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCInteriorPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v610 != 0 )
  {
    if ( (unsigned __int16)v609 <= 2u )
      v609 = (__m128 *)(unsigned __int16)(4 * (_WORD)v609 - 4);
    else
      v609 = (__m128 *)(unsigned __int16)(2 * (_WORD)v609 - 2);
  }
  v248 = sPosInteriorStencil[(unsigned __int16)v609];
  v249 = _mm_mul_ps(*v248, v17[*v597]);
  v250 = v248 + 1;
  OutPos[9] = v249;
  v251 = &v597[(unsigned __int16)v605];
  v607 = 3;
  do
  {
    v252 = _mm_mul_ps(v17[*v251++], *v250++);
    v22 = v607-- == 1;
    v249 = _mm_add_ps(v249, v252);
    OutPos[9] = v249;
  }
  while ( !v22 );
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v253 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 6);
  LODWORD(v254) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 6);
  *(_DWORD *)&v614[16] = 4;
  v609 = v253;
  v605 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[1] + 6);
  *(float *)&v610 = v254;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeACCInteriorPosition (SIMD)",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( (_WORD)v610 != 0 )
  {
    if ( (unsigned __int16)v609 <= 2u )
      v609 = (__m128 *)(unsigned __int16)(4 * (_WORD)v609 - 4);
    else
      v609 = (__m128 *)(unsigned __int16)(2 * (_WORD)v609 - 2);
  }
  v255 = sPosInteriorStencil[(unsigned __int16)v609];
  v256 = _mm_mul_ps(*v255, v17[*v598]);
  v257 = v255 + 1;
  OutPos[8] = v256;
  v258 = &v598[(unsigned __int16)v605];
  v607 = 3;
  do
  {
    v259 = _mm_mul_ps(v17[*v258++], *v257++);
    v22 = v607-- == 1;
    v256 = _mm_add_ps(v256, v259);
    OutPos[8] = v256;
  }
  while ( !v22 );
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v614[0] = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  if ( (_BYTE)TanV == 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeACCAllPatches - Tangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v542 = (Vector4D)_mm_mul_ps(_mm_sub_ps(OutPos[0], v578), Four_Threes);
    OutTanU[15] = _mm_mul_ps(_mm_sub_ps(OutPos[3], v578), Four_Threes);
    OutTanU[2] = _mm_mul_ps(_mm_sub_ps(OutPos[4], OutPos[3]), Four_Threes);
    OutTanV[0] = _mm_mul_ps(_mm_sub_ps(OutPos[4], OutPos[0]), Four_Threes);
    OutTanU[5] = _mm_mul_ps(_mm_sub_ps(OutPos[8], OutPos[7]), Four_Threes);
    OutTanV[1] = _mm_mul_ps(_mm_sub_ps(OutPos[5], OutPos[1]), Four_Threes);
    OutTanU[8] = _mm_mul_ps(_mm_sub_ps(OutPos[12], OutPos[11]), Four_Threes);
    OutTanV[2] = _mm_mul_ps(_mm_sub_ps(OutPos[6], OutPos[2]), Four_Threes);
    OutTanU[0] = _mm_mul_ps(_mm_sub_ps(OutPos[1], OutPos[0]), Four_Threes);
    OutTanV[3] = _mm_mul_ps(_mm_sub_ps(OutPos[7], OutPos[3]), Four_Threes);
    OutTanU[3] = _mm_mul_ps(_mm_sub_ps(OutPos[5], OutPos[4]), Four_Threes);
    OutTanV[4] = _mm_mul_ps(_mm_sub_ps(OutPos[8], OutPos[4]), Four_Threes);
    OutTanU[6] = _mm_mul_ps(_mm_sub_ps(OutPos[9], OutPos[8]), Four_Threes);
    OutTanV[5] = _mm_mul_ps(_mm_sub_ps(OutPos[9], OutPos[5]), Four_Threes);
    OutTanU[9] = _mm_mul_ps(_mm_sub_ps(OutPos[13], OutPos[12]), Four_Threes);
    v614[0] = 2;
    OutTanV[6] = _mm_mul_ps(_mm_sub_ps(OutPos[10], OutPos[6]), Four_Threes);
    OutTanU[1] = _mm_mul_ps(_mm_sub_ps(OutPos[2], OutPos[1]), Four_Threes);
    OutTanV[7] = _mm_mul_ps(_mm_sub_ps(OutPos[11], OutPos[7]), Four_Threes);
    OutTanU[7] = _mm_mul_ps(_mm_sub_ps(OutPos[10], OutPos[9]), Four_Threes);
    OutTanU[4] = _mm_mul_ps(_mm_sub_ps(OutPos[6], OutPos[5]), Four_Threes);
    OutTanV[8] = _mm_mul_ps(_mm_sub_ps(OutPos[12], OutPos[8]), Four_Threes);
    OutTanV[9] = _mm_mul_ps(_mm_sub_ps(OutPos[13], OutPos[9]), Four_Threes);
    OutTanV[10] = _mm_mul_ps(Four_Threes, _mm_sub_ps(OutPos[14], OutPos[10]));
    OutTanU[10] = _mm_mul_ps(_mm_sub_ps(OutPos[14], OutPos[13]), Four_Threes);
    v260 = (unsigned __int16 *)pPos[1].m128_i32[3];
    v261 = v260[1];
    v262 = (float)*v260;
    v263 = v260[2];
    v264 = v260[3];
    v588 = (float)(v262 * 6.2831855) * 0.000015259022;
    v589 = (float)((float)v261 * 6.2831855) * 0.000015259022;
    v590 = (float)((float)v263 * 6.2831855) * 0.000015259022;
    v591 = (float)((float)v264 * 6.2831855) * 0.000015259022;
    if ( sShowACCGeometryTangents )
    {
LABEL_290:
      *Pos = v542;
      Pos[1] = (Vector4D)OutTanU[0];
      Pos[2] = (Vector4D)OutTanU[1];
      Pos[3] = (Vector4D)OutTanU[2];
      Pos[4] = (Vector4D)OutTanU[3];
      Pos[5] = (Vector4D)OutTanU[4];
      Pos[6] = (Vector4D)OutTanU[5];
      Pos[7] = (Vector4D)OutTanU[6];
      Pos[8] = (Vector4D)OutTanU[7];
      Pos[9] = (Vector4D)OutTanU[8];
      Pos[10] = (Vector4D)OutTanU[9];
      Pos[11] = (Vector4D)OutTanU[10];
      *TanU = (Vector4D)OutTanU[15];
      TanU[1] = (Vector4D)OutTanV[0];
      TanU[2] = (Vector4D)OutTanV[1];
      TanU[3] = (Vector4D)OutTanV[2];
      TanU[4] = (Vector4D)OutTanV[3];
      TanU[5] = (Vector4D)OutTanV[4];
      TanU[6] = (Vector4D)OutTanV[5];
      TanU[7] = (Vector4D)OutTanV[6];
      TanU[8] = (Vector4D)OutTanV[7];
      TanU[9] = (Vector4D)OutTanV[8];
      TanU[10] = (Vector4D)OutTanV[9];
      TanU[11] = (Vector4D)OutTanV[10];
      v614[0] = 0;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      goto LABEL_291;
    }
    LODWORD(v265) = *(unsigned __int16 *)pPos[1].m128_i32[2];
    v609 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[2];
    LODWORD(v266) = *(unsigned __int16 *)pPos[1].m128_i32[0];
    *(float *)&v610 = v265;
    LODWORD(v267) = *(unsigned __int16 *)pPos->m128_i32[1];
    v613 = 4;
    *(float *)&v605 = v266;
    v606 = (__m128 *)*(unsigned __int16 *)pPos->m128_i32[0];
    v604 = v267;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeCatmullClarkLimitTangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v268 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard';
    v614[0] = 3;
    if ( (`ComputeCatmullClarkLimitTangents'::`2'::`local static guard' & 1) != 0 )
    {
      v269 = (__m128)`ComputeCatmullClarkLimitTangents'::`2'::tanUSign;
    }
    else
    {
      v268 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' | 1;
      v269 = Four_Ones;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' |= 1u;
      `ComputeCatmullClarkLimitTangents'::`2'::tanUSign = (__int128)Four_Ones;
      xmmword_552640 = (__int128)Four_NegativeOnes;
      xmmword_552650 = (__int128)Four_NegativeOnes;
      xmmword_552660 = (__int128)Four_Ones;
    }
    if ( (v268 & 2) != 0 )
    {
      v270 = (__m128)`ComputeCatmullClarkLimitTangents'::`2'::tanVSign;
    }
    else
    {
      v270 = Four_Ones;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' = v268 | 2;
      `ComputeCatmullClarkLimitTangents'::`2'::tanVSign = (__int128)Four_Ones;
      xmmword_552600 = (__int128)Four_Ones;
      xmmword_552610 = (__int128)Four_NegativeOnes;
      xmmword_552620 = (__int128)Four_NegativeOnes;
    }
    if ( sUseCornerTangents )
      v271 = (__int16)v610;
    else
      v271 = 0;
    if ( (_WORD)v605 != 0 )
    {
      if ( v271 == 0 || v271 == 2 )
      {
        v315 = (unsigned __int16)v609;
        v272 = Four_Zeros;
        v610 = sCCLimitTanBndStencil1[v315];
        v316 = sCCLimitTanBndStencil2[v315];
        v317 = 0;
        v318 = Four_Zeros;
        if ( (_WORD)v606 != 0 )
        {
          v610 = (__m128 *)((char *)v610 - (int)v316);
          do
          {
            v605 = &v17[v595[v317]];
            v318 = _mm_add_ps(v318, _mm_mul_ps(*(__m128 *)((char *)v316 + (_DWORD)v610), *v605));
            v319 = _mm_mul_ps(*v605, *v316);
            ++v317;
            ++v316;
            v272 = _mm_add_ps(v272, v319);
          }
          while ( v317 < (unsigned __int16)v606 );
        }
        v320 = (LOWORD(v604) - 1) / 2;
        v321 = (unsigned __int16)v609 - 1;
        if ( (_WORD)v609 == 2 )
        {
          v275 = v318;
        }
        else
        {
          v275 = _mm_add_ps(_mm_mul_ps(sCCCosPI[v320][v321], v318), _mm_mul_ps(sCCSinPI[v320][v321], v272));
          v272 = _mm_add_ps(_mm_mul_ps(sCCCosPI[v320 + 1][v321], v318), _mm_mul_ps(sCCSinPI[v320 + 1][v321], v272));
        }
      }
      else
      {
        if ( (_WORD)v609 == 2 )
          goto LABEL_191;
        v279 = *v595;
        v280 = _mm_sub_ps(v17[v595[1]], v17[v279]);
        v605 = (__m128 *)(unsigned __int16)v609;
        v610 = &v17[v279];
        v281 = v595;
        v282 = sPosEdge1Stencil[(unsigned __int16)v609];
        v283 = *v282;
        v284 = _mm_sub_ps(v17[v595[(unsigned __int16)v606 - 1]], *v610);
        v608 = v282 + 1;
        v285 = _mm_mul_ps(*v610, _mm_sub_ps(v283, Four_Ones));
        v286 = v285;
        v287 = 1;
        v607 = (int)&v595[(unsigned __int16)v606 - 5];
        while ( 1 )
        {
          v288 = v281[v287];
          v289 = *v608++;
          ++v287;
          v285 = _mm_add_ps(v285, _mm_mul_ps(v289, v17[v288]));
          v286 = _mm_add_ps(v286, _mm_mul_ps(v289, v17[*(unsigned __int16 *)v607]));
          v607 += 2;
          if ( v287 >= 6 )
            break;
          v281 = v595;
        }
        v290 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v285, v285, 210), _mm_shuffle_ps(v280, v280, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v285, v285, 201), _mm_shuffle_ps(v280, v280, 210)));
        v547 = _mm_mul_ps(v290, v290);
        v291 = 0;
        v291.m128_f32[0] = (float)(v547.m128_f32[1] + v547.m128_f32[0]) + v547.m128_f32[2];
        v292 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v291, v291, 0)), v290);
        v293 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v284, v284, 210), _mm_shuffle_ps(v286, v286, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v284, v284, 201), _mm_shuffle_ps(v286, v286, 210)));
        v571 = _mm_mul_ps(v293, v293);
        v294 = 0;
        v294.m128_f32[0] = (float)(v571.m128_f32[1] + v571.m128_f32[0]) + v571.m128_f32[2];
        v295 = _mm_add_ps(_mm_mul_ps(v293, _mm_rsqrt_ps(_mm_shuffle_ps(v294, v294, 0))), v292);
        v572 = _mm_mul_ps(v295, v295);
        v296 = 0;
        v296.m128_f32[0] = (float)(v572.m128_f32[1] + v572.m128_f32[0]) + v572.m128_f32[2];
        v297 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v296, v296, 0)), v295);
        v568 = _mm_mul_ps(v297, v280);
        v298 = 0;
        v298.m128_f32[0] = (float)(v568.m128_f32[1] + v568.m128_f32[0]) + v568.m128_f32[2];
        v566 = _mm_mul_ps(v297, v284);
        v299 = 0;
        v299.m128_f32[0] = (float)(v566.m128_f32[1] + v566.m128_f32[0]) + v566.m128_f32[2];
        v300 = _mm_sub_ps(v280, _mm_mul_ps(_mm_shuffle_ps(v298, v298, 0), v297));
        v301 = _mm_sub_ps(v284, _mm_mul_ps(_mm_shuffle_ps(v299, v299, 0), v297));
        v564 = _mm_mul_ps(v300, v300);
        v302 = 0;
        v302.m128_f32[0] = (float)(v564.m128_f32[1] + v564.m128_f32[0]) + v564.m128_f32[2];
        v303 = _mm_rsqrt_ps(_mm_shuffle_ps(v302, v302, 0));
        v562 = _mm_mul_ps(v301, v301);
        v304 = _mm_div_ps(v300, v303);
        v305 = 0;
        v305.m128_f32[0] = (float)(v562.m128_f32[1] + v562.m128_f32[0]) + v562.m128_f32[2];
        v306 = _mm_rsqrt_ps(_mm_shuffle_ps(v305, v305, 0));
        v307 = _mm_div_ps(v301, v306);
        u10 = _mm_mul_ps(_mm_add_ps(v306, v303), Four_PointFives);
        u00 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v304, v304, 210), _mm_shuffle_ps(v297, v297, 201)),
                _mm_mul_ps(_mm_shuffle_ps(v304, v304, 201), _mm_shuffle_ps(v297, v297, 210)));
        v558 = _mm_mul_ps(u00, v307);
        v308 = 0;
        v308.m128_f32[0] = (float)(v558.m128_f32[1] + v558.m128_f32[0]) + v558.m128_f32[2];
        OutPos[15] = v304;
        v556 = _mm_mul_ps(v307, v304);
        __libm_sse2_atan2(y: *(long double *)&v614[4], x: *(long double *)&v614[12]);
        v309 = LOWORD(v604) - 1;
        *(float *)&pOneRing[1] = 3.14159265 - _mm_shuffle_ps(v308, v308, 0).m128_f32[0];
        v588 = *(float *)&pOneRing[1];
        v601 = (__m128 *)(v309 / 2 + 1);
        v304.m128_f32[0] = 1.0 / *(float *)&dword_5200B4[(_DWORD)v605];
        *(float *)&v610 = (float)((float)(v309 / 2) * *(float *)&pOneRing[1]) * v304.m128_f32[0];
        v605 = (__m128 *)v304.m128_i32[0];
        *(double *)v297.m128_u64 = *(float *)&v610;
        __libm_sse2_cos(x: *(long double *)&v614[4]);
        v297.m128_f32[0] = *(double *)v297.m128_u64;
        v310 = 0;
        v310.m128_f32[0] = v297.m128_f32[0];
        c0 = _mm_shuffle_ps(v310, v310, 0);
        *(double *)v297.m128_u64 = *(float *)&v610;
        __libm_sse2_sin(x: *(long double *)&v614[4]);
        v297.m128_f32[0] = *(double *)v297.m128_u64;
        v311 = 0;
        v311.m128_f32[0] = v297.m128_f32[0];
        flLoopGap = _mm_shuffle_ps(v311, v311, 0);
        *(float *)&v610 = (float)((float)(int)v601 * *(float *)&pOneRing[1]) * *(float *)&v605;
        *(double *)v297.m128_u64 = *(float *)&v610;
        __libm_sse2_cos(x: *(long double *)&v614[4]);
        v297.m128_f32[0] = *(double *)v297.m128_u64;
        v312 = 0;
        v312.m128_f32[0] = v297.m128_f32[0];
        u20 = _mm_shuffle_ps(v312, v312, 0);
        *(double *)v297.m128_u64 = *(float *)&v610;
        __libm_sse2_sin(x: *(long double *)&v614[4]);
        v269 = (__m128)`ComputeCatmullClarkLimitTangents'::`2'::tanUSign;
        v313 = 0;
        v297.m128_f32[0] = *(double *)v297.m128_u64;
        v313.m128_f32[0] = v297.m128_f32[0];
        v314 = v313;
        v275 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(c0, OutPos[15]), _mm_mul_ps(flLoopGap, u00)), u10);
        v270 = (__m128)`ComputeCatmullClarkLimitTangents'::`2'::tanVSign;
        v272 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(u20, OutPos[15]), _mm_mul_ps(_mm_shuffle_ps(v314, v314, 0), u00)), u10);
      }
    }
    else
    {
      v272 = Four_Zeros;
      v273 = (unsigned __int16)v609;
      v610 = sCCLimitTanStencil1[v273];
      v274 = 0;
      v275 = Four_Zeros;
      v276 = sCCLimitTanStencil2[v273];
      OutTanU[15] = Four_Zeros;
      v542 = (Vector4D)Four_Zeros;
      v607 = 0;
      if ( (_WORD)v606 != 0 )
      {
        v610 = (__m128 *)((char *)v610 - (int)v276);
        v277 = v276;
        do
        {
          v275 = _mm_add_ps(v275, _mm_mul_ps(*(__m128 *)((char *)v277 + (_DWORD)v610), v17[v595[v274]]));
          v542 = (Vector4D)v275;
          v278 = _mm_mul_ps(*v277, v17[v595[v607]]);
          v274 = v607 + 1;
          ++v277;
          v272 = _mm_add_ps(v272, v278);
          OutTanU[15] = v272;
          v607 = v274;
        }
        while ( v274 < (unsigned __int16)v606 );
      }
    }
    v542 = (Vector4D)_mm_mul_ps(v269, v275);
    OutTanU[15] = _mm_mul_ps(v270, v272);
LABEL_191:
    v614[0] = 2;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    LODWORD(v322) = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 2);
    v609 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 2);
    LODWORD(v323) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 2);
    *(_DWORD *)v614 = 4;
    *(float *)&v610 = v322;
    LODWORD(v324) = *(unsigned __int16 *)(pPos->m128_i32[1] + 2);
    v613 = 0;
    *(float *)&v605 = v323;
    v325 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 2);
    v604 = v324;
    v606 = v325;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeCatmullClarkLimitTangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v326 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard';
    v614[0] = 4;
    if ( (`ComputeCatmullClarkLimitTangents'::`2'::`local static guard' & 1) != 0 )
    {
      v327 = (__m128)xmmword_552640;
    }
    else
    {
      v326 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' | 1;
      v327 = Four_NegativeOnes;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' |= 1u;
      `ComputeCatmullClarkLimitTangents'::`2'::tanUSign = (__int128)Four_Ones;
      xmmword_552640 = (__int128)Four_NegativeOnes;
      xmmword_552650 = (__int128)Four_NegativeOnes;
      xmmword_552660 = (__int128)Four_Ones;
    }
    if ( (v326 & 2) == 0 )
    {
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' = v326 | 2;
      `ComputeCatmullClarkLimitTangents'::`2'::tanVSign = (__int128)Four_Ones;
      xmmword_552600 = (__int128)Four_Ones;
      xmmword_552610 = (__int128)Four_NegativeOnes;
      xmmword_552620 = (__int128)Four_NegativeOnes;
    }
    if ( sUseCornerTangents )
      v328 = (__int16)v610;
    else
      v328 = 0;
    if ( (_WORD)v605 != 0 )
    {
      if ( v328 == 0 || v328 == 2 )
      {
        v372 = (unsigned __int16)v609;
        v330 = Four_Zeros;
        v610 = sCCLimitTanBndStencil1[v372];
        v373 = sCCLimitTanBndStencil2[v372];
        v374 = 0;
        v375 = Four_Zeros;
        if ( (_WORD)v606 != 0 )
        {
          v610 = (__m128 *)((char *)v610 - (int)v373);
          do
          {
            v605 = &v17[v596[v374]];
            v375 = _mm_add_ps(v375, _mm_mul_ps(*(__m128 *)((char *)v610 + (_DWORD)v373), *v605));
            v376 = _mm_mul_ps(*v373, *v605);
            ++v374;
            ++v373;
            v330 = _mm_add_ps(v330, v376);
          }
          while ( v374 < (unsigned __int16)v606 );
        }
        v377 = (LOWORD(v604) - 1) / 2;
        v378 = (unsigned __int16)v609 - 1;
        if ( (_WORD)v609 == 2 )
        {
          v332 = v375;
        }
        else
        {
          v332 = _mm_add_ps(_mm_mul_ps(sCCCosPI[v377][v378], v375), _mm_mul_ps(sCCSinPI[v377][v378], v330));
          v330 = _mm_add_ps(_mm_mul_ps(sCCCosPI[v377 + 1][v378], v375), _mm_mul_ps(sCCSinPI[v377 + 1][v378], v330));
        }
      }
      else
      {
        if ( (_WORD)v609 == 2 )
          goto LABEL_218;
        v336 = v596;
        v607 = (int)&v17[*v596];
        v337 = _mm_sub_ps(v17[v596[1]], *(__m128 *)v607);
        v338 = v596[(unsigned __int16)v606 - 1];
        v610 = (__m128 *)(unsigned __int16)v609;
        v339 = sPosEdge1Stencil[(unsigned __int16)v609];
        v340 = *v339;
        v341 = _mm_sub_ps(v17[v338], *(__m128 *)v607);
        v608 = v339 + 1;
        v342 = _mm_mul_ps(_mm_sub_ps(v340, Four_Ones), *(__m128 *)v607);
        v343 = v342;
        v344 = 1;
        v607 = (int)&v596[(unsigned __int16)v606 - 5];
        while ( 1 )
        {
          v345 = v336[v344];
          v346 = *v608++;
          ++v344;
          v342 = _mm_add_ps(v342, _mm_mul_ps(v346, v17[v345]));
          v343 = _mm_add_ps(v343, _mm_mul_ps(v346, v17[*(unsigned __int16 *)v607]));
          v607 += 2;
          if ( v344 >= 6 )
            break;
          v336 = v596;
        }
        v347 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v342, v342, 210), _mm_shuffle_ps(v337, v337, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v342, v342, 201), _mm_shuffle_ps(v337, v337, 210)));
        v554 = _mm_mul_ps(v347, v347);
        v348 = 0;
        v348.m128_f32[0] = (float)(v554.m128_f32[1] + v554.m128_f32[0]) + v554.m128_f32[2];
        v349 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v348, v348, 0)), v347);
        v350 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v341, v341, 210), _mm_shuffle_ps(v343, v343, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v341, v341, 201), _mm_shuffle_ps(v343, v343, 210)));
        v552 = _mm_mul_ps(v350, v350);
        v351 = 0;
        v351.m128_f32[0] = (float)(v552.m128_f32[1] + v552.m128_f32[0]) + v552.m128_f32[2];
        v352 = _mm_add_ps(_mm_mul_ps(v350, _mm_rsqrt_ps(_mm_shuffle_ps(v351, v351, 0))), v349);
        v550 = _mm_mul_ps(v352, v352);
        v353 = 0;
        v353.m128_f32[0] = (float)(v550.m128_f32[1] + v550.m128_f32[0]) + v550.m128_f32[2];
        v354 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v353, v353, 0)), v352);
        v548 = _mm_mul_ps(v354, v337);
        v355 = 0;
        v355.m128_f32[0] = (float)(v548.m128_f32[1] + v548.m128_f32[0]) + v548.m128_f32[2];
        v546 = _mm_mul_ps(v354, v341);
        v356 = 0;
        v356.m128_f32[0] = (float)(v546.m128_f32[1] + v546.m128_f32[0]) + v546.m128_f32[2];
        v357 = _mm_sub_ps(v337, _mm_mul_ps(_mm_shuffle_ps(v355, v355, 0), v354));
        v358 = _mm_sub_ps(v341, _mm_mul_ps(_mm_shuffle_ps(v356, v356, 0), v354));
        OutTanV[15] = _mm_mul_ps(v357, v357);
        v359 = 0;
        v359.m128_f32[0] = (float)(OutTanV[15].m128_f32[1] + OutTanV[15].m128_f32[0]) + OutTanV[15].m128_f32[2];
        v360 = _mm_rsqrt_ps(_mm_shuffle_ps(v359, v359, 0));
        v557 = _mm_mul_ps(v358, v358);
        v361 = _mm_div_ps(v357, v360);
        v362 = 0;
        v362.m128_f32[0] = (float)(v557.m128_f32[1] + v557.m128_f32[0]) + v557.m128_f32[2];
        v363 = _mm_rsqrt_ps(_mm_shuffle_ps(v362, v362, 0));
        v364 = _mm_div_ps(v358, v363);
        u10 = _mm_mul_ps(_mm_add_ps(v363, v360), Four_PointFives);
        u00 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v361, v361, 210), _mm_shuffle_ps(v354, v354, 201)),
                _mm_mul_ps(_mm_shuffle_ps(v361, v361, 201), _mm_shuffle_ps(v354, v354, 210)));
        v560 = _mm_mul_ps(u00, v364);
        v365 = 0;
        v365.m128_f32[0] = (float)(v560.m128_f32[1] + v560.m128_f32[0]) + v560.m128_f32[2];
        OutPos[15] = v361;
        v570 = _mm_mul_ps(v364, v361);
        __libm_sse2_atan2(y: *(long double *)&v614[4], x: *(long double *)&v614[12]);
        v366 = LOWORD(v604) - 1;
        *(float *)&v601 = 3.14159265 - _mm_shuffle_ps(v365, v365, 0).m128_f32[0];
        v589 = *(float *)&v601;
        v605 = (__m128 *)(v366 / 2 + 1);
        v361.m128_f32[0] = 1.0 / *(float *)&dword_5200B4[(_DWORD)v610];
        *(float *)&v610 = (float)((float)(v366 / 2) * *(float *)&v601) * v361.m128_f32[0];
        pOneRing[1] = (unsigned __int16 *)v361.m128_i32[0];
        *(double *)v354.m128_u64 = *(float *)&v610;
        __libm_sse2_cos(x: *(long double *)&v614[4]);
        v354.m128_f32[0] = *(double *)v354.m128_u64;
        v367 = 0;
        v367.m128_f32[0] = v354.m128_f32[0];
        c0 = _mm_shuffle_ps(v367, v367, 0);
        *(double *)v354.m128_u64 = *(float *)&v610;
        __libm_sse2_sin(x: *(long double *)&v614[4]);
        v354.m128_f32[0] = *(double *)v354.m128_u64;
        v368 = 0;
        v368.m128_f32[0] = v354.m128_f32[0];
        flLoopGap = _mm_shuffle_ps(v368, v368, 0);
        *(float *)&v610 = (float)((float)(int)v605 * *(float *)&v601) * *(float *)&pOneRing[1];
        *(double *)v354.m128_u64 = *(float *)&v610;
        __libm_sse2_cos(x: *(long double *)&v614[4]);
        v354.m128_f32[0] = *(double *)v354.m128_u64;
        v369 = 0;
        v369.m128_f32[0] = v354.m128_f32[0];
        u20 = _mm_shuffle_ps(v369, v369, 0);
        *(double *)v354.m128_u64 = *(float *)&v610;
        __libm_sse2_sin(x: *(long double *)&v614[4]);
        v370 = 0;
        v354.m128_f32[0] = *(double *)v354.m128_u64;
        v370.m128_f32[0] = v354.m128_f32[0];
        v371 = v370;
        v332 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(c0, OutPos[15]), _mm_mul_ps(flLoopGap, u00)), u10);
        v327 = (__m128)xmmword_552640;
        v330 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(u20, OutPos[15]), _mm_mul_ps(_mm_shuffle_ps(v371, v371, 0), u00)), u10);
      }
    }
    else
    {
      v329 = (unsigned __int16)v609;
      v330 = Four_Zeros;
      v610 = sCCLimitTanStencil1[v329];
      v331 = 0;
      v332 = Four_Zeros;
      v333 = sCCLimitTanStencil2[v329];
      OutTanV[2] = Four_Zeros;
      OutTanU[1] = Four_Zeros;
      v607 = 0;
      if ( (_WORD)v606 != 0 )
      {
        v610 = (__m128 *)((char *)v610 - (int)v333);
        v334 = v333;
        do
        {
          v332 = _mm_add_ps(v332, _mm_mul_ps(*(__m128 *)((char *)v334 + (_DWORD)v610), v17[v596[v331]]));
          OutTanU[1] = v332;
          v335 = _mm_mul_ps(*v334, v17[v596[v607]]);
          v331 = v607 + 1;
          ++v334;
          v330 = _mm_add_ps(v330, v335);
          OutTanV[2] = v330;
          v607 = v331;
        }
        while ( v331 < (unsigned __int16)v606 );
      }
    }
    OutTanU[1] = _mm_mul_ps(v327, v330);
    OutTanV[2] = _mm_mul_ps(v332, (__m128)xmmword_552600);
LABEL_218:
    v614[0] = 2;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    LODWORD(v379) = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 4);
    v609 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 4);
    LODWORD(v380) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 4);
    *(_DWORD *)v614 = 4;
    *(float *)&v610 = v379;
    LODWORD(v381) = *(unsigned __int16 *)(pPos->m128_i32[1] + 4);
    v613 = 0;
    *(float *)&v605 = v380;
    v382 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 4);
    v604 = v381;
    v606 = v382;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeCatmullClarkLimitTangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v383 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard';
    v614[0] = 5;
    if ( (`ComputeCatmullClarkLimitTangents'::`2'::`local static guard' & 1) == 0 )
    {
      v383 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' | 1;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' |= 1u;
      `ComputeCatmullClarkLimitTangents'::`2'::tanUSign = (__int128)Four_Ones;
      xmmword_552640 = (__int128)Four_NegativeOnes;
      xmmword_552650 = (__int128)Four_NegativeOnes;
      xmmword_552660 = (__int128)Four_Ones;
    }
    if ( (v383 & 2) == 0 )
    {
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' = v383 | 2;
      `ComputeCatmullClarkLimitTangents'::`2'::tanVSign = (__int128)Four_Ones;
      xmmword_552600 = (__int128)Four_Ones;
      xmmword_552610 = (__int128)Four_NegativeOnes;
      xmmword_552620 = (__int128)Four_NegativeOnes;
    }
    if ( sUseCornerTangents )
      v384 = (__int16)v610;
    else
      v384 = 0;
    if ( (_WORD)v605 != 0 )
    {
      if ( v384 == 0 || v384 == 2 )
      {
        v428 = (unsigned __int16)v609;
        v386 = Four_Zeros;
        v610 = sCCLimitTanBndStencil1[v428];
        v429 = sCCLimitTanBndStencil2[v428];
        v430 = 0;
        v431 = Four_Zeros;
        if ( (_WORD)v606 != 0 )
        {
          v610 = (__m128 *)((char *)v610 - (int)v429);
          do
          {
            v605 = &v17[v597[v430]];
            v431 = _mm_add_ps(v431, _mm_mul_ps(*(__m128 *)((char *)v429 + (_DWORD)v610), *v605));
            v432 = _mm_mul_ps(*v429, *v605);
            ++v430;
            ++v429;
            v386 = _mm_add_ps(v386, v432);
          }
          while ( v430 < (unsigned __int16)v606 );
        }
        v433 = (LOWORD(v604) - 1) / 2;
        v434 = (unsigned __int16)v609 - 1;
        if ( (_WORD)v609 == 2 )
        {
          v389 = v431;
        }
        else
        {
          v389 = _mm_add_ps(_mm_mul_ps(sCCCosPI[v433][v434], v431), _mm_mul_ps(sCCSinPI[v433][v434], v386));
          v386 = _mm_add_ps(_mm_mul_ps(sCCCosPI[v433 + 1][v434], v431), _mm_mul_ps(sCCSinPI[v433 + 1][v434], v386));
        }
      }
      else
      {
        if ( (_WORD)v609 == 2 )
          goto LABEL_244;
        v392 = *v597;
        v393 = _mm_sub_ps(v17[v597[1]], v17[v392]);
        v605 = (__m128 *)(unsigned __int16)v609;
        v610 = &v17[v392];
        v394 = v597;
        v395 = sPosEdge1Stencil[(unsigned __int16)v609];
        v396 = *v395;
        v397 = _mm_sub_ps(v17[v597[(unsigned __int16)v606 - 1]], *v610);
        v608 = v395 + 1;
        v398 = _mm_mul_ps(*v610, _mm_sub_ps(v396, Four_Ones));
        v399 = v398;
        v400 = 1;
        v607 = (int)&v597[(unsigned __int16)v606 - 5];
        while ( 1 )
        {
          v401 = v394[v400];
          v402 = *v608++;
          ++v400;
          v398 = _mm_add_ps(v398, _mm_mul_ps(v17[v401], v402));
          v399 = _mm_add_ps(v399, _mm_mul_ps(v402, v17[*(unsigned __int16 *)v607]));
          v607 += 2;
          if ( v400 >= 6 )
            break;
          v394 = v597;
        }
        v403 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v398, v398, 210), _mm_shuffle_ps(v393, v393, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v398, v398, 201), _mm_shuffle_ps(v393, v393, 210)));
        v569 = _mm_mul_ps(v403, v403);
        v404 = 0;
        v404.m128_f32[0] = (float)(v569.m128_f32[1] + v569.m128_f32[0]) + v569.m128_f32[2];
        v405 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v404, v404, 0)), v403);
        v406 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v397, v397, 210), _mm_shuffle_ps(v399, v399, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v397, v397, 201), _mm_shuffle_ps(v399, v399, 210)));
        v573 = _mm_mul_ps(v406, v406);
        v407 = 0;
        v407.m128_f32[0] = (float)(v573.m128_f32[1] + v573.m128_f32[0]) + v573.m128_f32[2];
        v408 = _mm_add_ps(_mm_mul_ps(v406, _mm_rsqrt_ps(_mm_shuffle_ps(v407, v407, 0))), v405);
        v567 = _mm_mul_ps(v408, v408);
        v409 = 0;
        v409.m128_f32[0] = (float)(v567.m128_f32[1] + v567.m128_f32[0]) + v567.m128_f32[2];
        v410 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v409, v409, 0)), v408);
        v555 = _mm_mul_ps(v410, v393);
        v411 = 0;
        v411.m128_f32[0] = (float)(v555.m128_f32[1] + v555.m128_f32[0]) + v555.m128_f32[2];
        v565 = _mm_mul_ps(v410, v397);
        v412 = 0;
        v412.m128_f32[0] = (float)(v565.m128_f32[1] + v565.m128_f32[0]) + v565.m128_f32[2];
        v413 = _mm_sub_ps(v393, _mm_mul_ps(_mm_shuffle_ps(v411, v411, 0), v410));
        v414 = _mm_sub_ps(v397, _mm_mul_ps(_mm_shuffle_ps(v412, v412, 0), v410));
        v549 = _mm_mul_ps(v413, v413);
        v415 = 0;
        v415.m128_f32[0] = (float)(v549.m128_f32[1] + v549.m128_f32[0]) + v549.m128_f32[2];
        v416 = _mm_rsqrt_ps(_mm_shuffle_ps(v415, v415, 0));
        v563 = _mm_mul_ps(v414, v414);
        v417 = _mm_div_ps(v413, v416);
        v418 = 0;
        v418.m128_f32[0] = (float)(v563.m128_f32[1] + v563.m128_f32[0]) + v563.m128_f32[2];
        v419 = _mm_rsqrt_ps(_mm_shuffle_ps(v418, v418, 0));
        v420 = _mm_div_ps(v414, v419);
        u10 = _mm_mul_ps(_mm_add_ps(v419, v416), Four_PointFives);
        u00 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v417, v417, 210), _mm_shuffle_ps(v410, v410, 201)),
                _mm_mul_ps(_mm_shuffle_ps(v417, v417, 201), _mm_shuffle_ps(v410, v410, 210)));
        v553 = _mm_mul_ps(u00, v420);
        v421 = 0;
        v421.m128_f32[0] = (float)(v553.m128_f32[1] + v553.m128_f32[0]) + v553.m128_f32[2];
        OutPos[15] = v417;
        v561 = _mm_mul_ps(v420, v417);
        __libm_sse2_atan2(y: *(long double *)&v614[4], x: *(long double *)&v614[12]);
        v422 = LOWORD(v604) - 1;
        *(float *)&pOneRing[1] = 3.14159265 - _mm_shuffle_ps(v421, v421, 0).m128_f32[0];
        v590 = *(float *)&pOneRing[1];
        v601 = (__m128 *)(v422 / 2 + 1);
        v417.m128_f32[0] = 1.0 / *(float *)&dword_5200B4[(_DWORD)v605];
        *(float *)&v610 = (float)((float)(v422 / 2) * *(float *)&pOneRing[1]) * v417.m128_f32[0];
        v605 = (__m128 *)v417.m128_i32[0];
        *(double *)v410.m128_u64 = *(float *)&v610;
        __libm_sse2_cos(x: *(long double *)&v614[4]);
        v410.m128_f32[0] = *(double *)v410.m128_u64;
        v423 = 0;
        v423.m128_f32[0] = v410.m128_f32[0];
        c0 = _mm_shuffle_ps(v423, v423, 0);
        *(double *)v410.m128_u64 = *(float *)&v610;
        __libm_sse2_sin(x: *(long double *)&v614[4]);
        v410.m128_f32[0] = *(double *)v410.m128_u64;
        v424 = 0;
        v424.m128_f32[0] = v410.m128_f32[0];
        flLoopGap = _mm_shuffle_ps(v424, v424, 0);
        *(float *)&v610 = (float)((float)(int)v601 * *(float *)&pOneRing[1]) * *(float *)&v605;
        *(double *)v410.m128_u64 = *(float *)&v610;
        __libm_sse2_cos(x: *(long double *)&v614[4]);
        v410.m128_f32[0] = *(double *)v410.m128_u64;
        v425 = 0;
        v425.m128_f32[0] = v410.m128_f32[0];
        u20 = _mm_shuffle_ps(v425, v425, 0);
        *(double *)v410.m128_u64 = *(float *)&v610;
        __libm_sse2_sin(x: *(long double *)&v614[4]);
        v426 = 0;
        v410.m128_f32[0] = *(double *)v410.m128_u64;
        v426.m128_f32[0] = v410.m128_f32[0];
        v427 = v426;
        v389 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(c0, OutPos[15]), _mm_mul_ps(flLoopGap, u00)), u10);
        v386 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(u20, OutPos[15]), _mm_mul_ps(_mm_shuffle_ps(v427, v427, 0), u00)), u10);
      }
    }
    else
    {
      v385 = (unsigned __int16)v609;
      v386 = Four_Zeros;
      v387 = sCCLimitTanStencil1[v385];
      v607 = (int)sCCLimitTanStencil2[v385];
      *(float *)&v388 = 0.0;
      v389 = Four_Zeros;
      OutTanV[10] = Four_Zeros;
      OutTanU[10] = Four_Zeros;
      v604 = 0.0;
      if ( (_WORD)v606 != 0 )
      {
        v390 = (__m128 *)v607;
        v610 = (__m128 *)((char *)v387 - v607);
        do
        {
          v389 = _mm_add_ps(v389, _mm_mul_ps(*(__m128 *)((char *)v390 + (_DWORD)v610), v17[v597[v388]]));
          OutTanU[10] = v389;
          v391 = _mm_mul_ps(v17[v597[LODWORD(v604)]], *v390);
          v388 = LODWORD(v604) + 1;
          ++v390;
          v386 = _mm_add_ps(v386, v391);
          OutTanV[10] = v386;
          v604 = *(float *)&v388;
        }
        while ( v388 < (unsigned __int16)v606 );
      }
    }
    OutTanU[10] = _mm_mul_ps(v389, (__m128)xmmword_552650);
    OutTanV[10] = _mm_mul_ps(v386, (__m128)xmmword_552610);
LABEL_244:
    v614[0] = 2;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    LODWORD(v435) = *(unsigned __int16 *)(pPos[1].m128_i32[2] + 6);
    v609 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[2] + 6);
    LODWORD(v436) = *(unsigned __int16 *)(pPos[1].m128_i32[0] + 6);
    *(_DWORD *)&v614[16] = 4;
    *(float *)&v610 = v435;
    LODWORD(v437) = *(unsigned __int16 *)(pPos->m128_i32[1] + 6);
    *(_DWORD *)&v614[12] = 0;
    *(float *)&v605 = v436;
    v438 = (__m128 *)*(unsigned __int16 *)(pPos->m128_i32[0] + 6);
    v604 = v437;
    v606 = v438;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "ComputeCatmullClarkLimitTangents (SIMD)",
      a3: 0,
      a4: "SubD Rendering",
      a5: false,
      a6: 4);
    v439 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard';
    v614[0] = 6;
    if ( (`ComputeCatmullClarkLimitTangents'::`2'::`local static guard' & 1) == 0 )
    {
      v439 = `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' | 1;
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' |= 1u;
      `ComputeCatmullClarkLimitTangents'::`2'::tanUSign = (__int128)Four_Ones;
      xmmword_552640 = (__int128)Four_NegativeOnes;
      xmmword_552650 = (__int128)Four_NegativeOnes;
      xmmword_552660 = (__int128)Four_Ones;
    }
    if ( (v439 & 2) == 0 )
    {
      `ComputeCatmullClarkLimitTangents'::`2'::`local static guard' = v439 | 2;
      `ComputeCatmullClarkLimitTangents'::`2'::tanVSign = (__int128)Four_Ones;
      xmmword_552600 = (__int128)Four_Ones;
      xmmword_552610 = (__int128)Four_NegativeOnes;
      xmmword_552620 = (__int128)Four_NegativeOnes;
    }
    if ( sUseCornerTangents )
      v440 = (__int16)v610;
    else
      v440 = 0;
    if ( (_WORD)v605 != 0 )
    {
      if ( v440 == 0 || v440 == 2 )
      {
        v485 = (unsigned __int16)v609;
        v442 = Four_Zeros;
        v486 = (unsigned __int16)v609;
        v605 = sCCLimitTanBndStencil1[v486];
        v610 = sCCLimitTanBndStencil2[v486];
        v487 = 0;
        v488 = Four_Zeros;
        if ( (_WORD)v606 != 0 )
        {
          v605 = (__m128 *)((char *)v605 - (int)v610);
          v489 = v610;
          do
          {
            v610 = &v17[v598[v487]];
            v488 = _mm_add_ps(v488, _mm_mul_ps(*(__m128 *)((char *)v489 + (_DWORD)v605), *v610));
            v490 = _mm_mul_ps(*v610, *v489);
            ++v487;
            ++v489;
            v442 = _mm_add_ps(v442, v490);
          }
          while ( v487 < (unsigned __int16)v606 );
          v485 = (unsigned __int16)v609;
        }
        v491 = (LOWORD(v604) - 1) / 2;
        v492 = v485 - 1;
        if ( v485 == 2 )
        {
          v445 = v488;
        }
        else
        {
          v445 = _mm_add_ps(_mm_mul_ps(sCCCosPI[v491][v492], v488), _mm_mul_ps(sCCSinPI[v491][v492], v442));
          v442 = _mm_add_ps(_mm_mul_ps(sCCCosPI[v491 + 1][v492], v488), _mm_mul_ps(sCCSinPI[v491 + 1][v492], v442));
        }
      }
      else
      {
        if ( (_WORD)v609 == 2 )
        {
LABEL_271:
          v614[0] = 2;
          CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
          if ( (_S1 & 1) == 0 )
          {
            _S1 |= 1u;
            CB_sign[0] = Four_Ones;
            xmmword_552690 = (__int128)Four_NegativeOnes;
            xmmword_5526A0 = (__int128)Four_Ones;
            xmmword_5526B0 = (__int128)Four_NegativeOnes;
          }
          v586 = *((__m128 *)&v542 + CB_CornerIdx[0]);
          v493 = (unsigned __int16 *)pPos->m128_i32[2];
          v494 = v493[1];
          v584 = _mm_mul_ps(*((__m128 *)&v542 + dword_520128), Four_Twos);
          v495 = *v493;
          v496 = (_WORD *)pPos[1].m128_i32[0];
          v22 = *v496 == 0;
          v580 = *((__m128 *)&v542 + dword_52012C);
          if ( !v22 )
            --v495;
          if ( v496[1] != 0 )
            --v494;
          v497 = (float)(v588 / (float)v495);
          __libm_sse2_cos(x: *(long double *)v614);
          *(float *)&v497 = v497;
          v498 = 0;
          v498.m128_f32[0] = *(float *)&v497;
          v582 = _mm_shuffle_ps(v498, v498, 0);
          v499 = (float)(v589 / (float)v494);
          __libm_sse2_cos(x: *(long double *)v614);
          *(float *)&v499 = v499;
          v500 = dword_520130;
          v501 = 0;
          v501.m128_f32[0] = *(float *)&v499;
          v502 = _mm_shuffle_ps(v501, v501, 0);
          v503 = _mm_sub_ps(_mm_mul_ps(v582, v580), _mm_mul_ps(v502, v584));
          OutTanU[CB_InteriorIdx[0] + 15] = _mm_add_ps(
                                              OutTanU[CB_InteriorIdx[0] + 15],
                                              _mm_div_ps(
                                                _mm_sub_ps(_mm_mul_ps(v582, v584), _mm_mul_ps(v502, v586)),
                                                Four_Threes));
          OutTanU[dword_520108 + 15] = _mm_add_ps(OutTanU[dword_520108 + 15], _mm_div_ps(v503, Four_Threes));
          v586 = OutTanU[v500 + 15];
          v584 = _mm_mul_ps(OutTanU[dword_520134 + 15], Four_Twos);
          v504 = pPos->m128_i32[2];
          v505 = *(unsigned __int16 *)(v504 + 2);
          v506 = *(unsigned __int16 *)(v504 + 4);
          v507 = pPos[1].m128_i32[0];
          v22 = *(_WORD *)(v507 + 2) == 0;
          v580 = OutTanU[dword_520138 + 15];
          if ( !v22 )
            --v505;
          if ( *(_WORD *)(v507 + 4) != 0 )
            --v506;
          v508 = (float)(v589 / (float)v505);
          __libm_sse2_cos(x: *(long double *)v614);
          *(float *)&v508 = v508;
          v509 = 0;
          v509.m128_f32[0] = *(float *)&v508;
          v582 = _mm_shuffle_ps(v509, v509, 0);
          v510 = (float)(v590 / (float)v506);
          __libm_sse2_cos(x: *(long double *)v614);
          *(float *)&v510 = v510;
          v511 = dword_52013C;
          v512 = 0;
          v512.m128_f32[0] = *(float *)&v510;
          v513 = dword_520144;
          v514 = _mm_shuffle_ps(v512, v512, 0);
          v515 = _mm_sub_ps(_mm_mul_ps(v582, v580), _mm_mul_ps(v514, v584));
          *((__m128 *)&v542 + dword_52010C) = _mm_sub_ps(
                                                *((__m128 *)&v542 + dword_52010C),
                                                _mm_div_ps(
                                                  _mm_sub_ps(_mm_mul_ps(v582, v584), _mm_mul_ps(v514, v586)),
                                                  Four_Threes));
          *((__m128 *)&v542 + dword_520110) = _mm_sub_ps(
                                                *((__m128 *)&v542 + dword_520110),
                                                _mm_div_ps(v515, Four_Threes));
          v586 = *((__m128 *)&v542 + v511);
          v516 = pPos->m128_i32[2];
          v517 = *(unsigned __int16 *)(v516 + 4);
          v518 = *(unsigned __int16 *)(v516 + 6);
          v519 = pPos[1].m128_i32[0];
          v22 = *(_WORD *)(v519 + 4) == 0;
          v584 = _mm_mul_ps(*((__m128 *)&v542 + dword_520140), Four_Twos);
          v580 = *((__m128 *)&v542 + v513);
          if ( !v22 )
            --v517;
          if ( *(_WORD *)(v519 + 6) != 0 )
            --v518;
          v520 = (float)(v590 / (float)v517);
          __libm_sse2_cos(x: *(long double *)v614);
          *(float *)&v520 = v520;
          v521 = 0;
          v521.m128_f32[0] = *(float *)&v520;
          v582 = _mm_shuffle_ps(v521, v521, 0);
          v522 = (float)(v591 / (float)v518);
          __libm_sse2_cos(x: *(long double *)v614);
          *(float *)&v522 = v522;
          v523 = 0;
          v523.m128_f32[0] = *(float *)&v522;
          v524 = _mm_shuffle_ps(v523, v523, 0);
          v525 = dword_520150;
          v526 = _mm_mul_ps(v582, v580);
          v527 = _mm_mul_ps(v524, v586);
          v528 = _mm_mul_ps(v524, v584);
          OutTanU[dword_520114 + 15] = _mm_add_ps(
                                         _mm_div_ps(_mm_sub_ps(_mm_mul_ps(v582, v584), v527), Four_Threes),
                                         OutTanU[dword_520114 + 15]);
          OutTanU[dword_520118 + 15] = _mm_add_ps(
                                         OutTanU[dword_520118 + 15],
                                         _mm_div_ps(_mm_sub_ps(v526, v528), Four_Threes));
          v586 = OutTanU[dword_520148 + 15];
          v529 = (unsigned __int16 *)pPos->m128_i32[2];
          v530 = (_WORD *)pPos[1].m128_i32[0];
          v531 = *v529;
          v22 = v530[3] == 0;
          v584 = _mm_mul_ps(OutTanU[dword_52014C + 15], Four_Twos);
          v532 = OutTanU[v525 + 15];
          v533 = v529[3];
          v580 = v532;
          if ( !v22 )
            --v533;
          if ( *v530 != 0 )
            --v531;
          v534 = (float)(v591 / (float)v533);
          __libm_sse2_cos(x: *(long double *)v614);
          *(float *)&v534 = v534;
          v535 = 0;
          v535.m128_f32[0] = *(float *)&v534;
          v582 = _mm_shuffle_ps(v535, v535, 0);
          v536 = (float)(v588 / (float)v531);
          __libm_sse2_cos(x: *(long double *)v614);
          *(float *)&v536 = v536;
          v537 = 0;
          v537.m128_f32[0] = *(float *)&v536;
          v538 = _mm_shuffle_ps(v537, v537, 0);
          v539 = _mm_sub_ps(_mm_mul_ps(v582, v580), _mm_mul_ps(v538, v584));
          *((__m128 *)&v542 + dword_52011C) = _mm_sub_ps(
                                                *((__m128 *)&v542 + dword_52011C),
                                                _mm_div_ps(
                                                  _mm_sub_ps(_mm_mul_ps(v582, v584), _mm_mul_ps(v538, v586)),
                                                  Four_Threes));
          *((__m128 *)&v542 + dword_520120) = _mm_sub_ps(
                                                *((__m128 *)&v542 + dword_520120),
                                                _mm_div_ps(v539, Four_Threes));
          goto LABEL_290;
        }
        v448 = *v598;
        v449 = _mm_sub_ps(v17[v598[1]], v17[v448]);
        v605 = (__m128 *)(unsigned __int16)v609;
        v610 = &v17[v448];
        v450 = v598;
        v451 = sPosEdge1Stencil[(unsigned __int16)v609];
        v452 = *v451;
        v453 = _mm_sub_ps(v17[v598[(unsigned __int16)v606 - 1]], *v610);
        v608 = v451 + 1;
        v454 = _mm_mul_ps(*v610, _mm_sub_ps(v452, Four_Ones));
        v455 = v454;
        v456 = 1;
        v607 = (int)&v598[(unsigned __int16)v606 - 5];
        while ( 1 )
        {
          v457 = v450[v456];
          v458 = *v608++;
          ++v456;
          v454 = _mm_add_ps(v454, _mm_mul_ps(v458, v17[v457]));
          v455 = _mm_add_ps(v455, _mm_mul_ps(v458, v17[*(unsigned __int16 *)v607]));
          v607 += 2;
          if ( v456 >= 6 )
            break;
          v450 = v598;
        }
        v459 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v454, v454, 210), _mm_shuffle_ps(v449, v449, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v454, v454, 201), _mm_shuffle_ps(v449, v449, 210)));
        v545 = _mm_mul_ps(v459, v459);
        v460 = 0;
        v460.m128_f32[0] = (float)(v545.m128_f32[1] + v545.m128_f32[0]) + v545.m128_f32[2];
        v461 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v460, v460, 0)), v459);
        v462 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v453, v453, 210), _mm_shuffle_ps(v455, v455, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v453, v453, 201), _mm_shuffle_ps(v455, v455, 210)));
        v559 = _mm_mul_ps(v462, v462);
        v463 = 0;
        v463.m128_f32[0] = (float)(v559.m128_f32[1] + v559.m128_f32[0]) + v559.m128_f32[2];
        v464 = _mm_add_ps(_mm_mul_ps(v462, _mm_rsqrt_ps(_mm_shuffle_ps(v463, v463, 0))), v461);
        v551 = _mm_mul_ps(v464, v464);
        v465 = 0;
        v465.m128_f32[0] = (float)(v551.m128_f32[1] + v551.m128_f32[0]) + v551.m128_f32[2];
        v466 = _mm_mul_ps(_mm_rsqrt_ps(_mm_shuffle_ps(v465, v465, 0)), v464);
        u20 = _mm_mul_ps(v466, v449);
        v467 = 0;
        v467.m128_f32[0] = (float)(u20.m128_f32[1] + u20.m128_f32[0]) + u20.m128_f32[2];
        u10 = _mm_mul_ps(v466, v453);
        v468 = 0;
        v468.m128_f32[0] = (float)(u10.m128_f32[1] + u10.m128_f32[0]) + u10.m128_f32[2];
        v469 = _mm_sub_ps(v449, _mm_mul_ps(_mm_shuffle_ps(v467, v467, 0), v466));
        v470 = _mm_sub_ps(v453, _mm_mul_ps(_mm_shuffle_ps(v468, v468, 0), v466));
        OutPos[15] = _mm_mul_ps(v469, v469);
        v471 = 0;
        v471.m128_f32[0] = (float)(OutPos[15].m128_f32[1] + OutPos[15].m128_f32[0]) + OutPos[15].m128_f32[2];
        v472 = _mm_rsqrt_ps(_mm_shuffle_ps(v471, v471, 0));
        c0 = _mm_mul_ps(v470, v470);
        v473 = _mm_div_ps(v469, v472);
        v474 = 0;
        v474.m128_f32[0] = (float)(c0.m128_f32[1] + c0.m128_f32[0]) + c0.m128_f32[2];
        v475 = _mm_rsqrt_ps(_mm_shuffle_ps(v474, v474, 0));
        v476 = _mm_div_ps(v470, v475);
        v584 = _mm_mul_ps(_mm_add_ps(v475, v472), Four_PointFives);
        v540 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v473, v473, 210), _mm_shuffle_ps(v466, v466, 201)),
                 _mm_mul_ps(_mm_shuffle_ps(v473, v473, 201), _mm_shuffle_ps(v466, v466, 210)));
        u00 = _mm_mul_ps(v540, v476);
        v477 = 0;
        v477.m128_f32[0] = (float)(u00.m128_f32[1] + u00.m128_f32[0]) + u00.m128_f32[2];
        v586 = v473;
        flLoopGap = _mm_mul_ps(v476, v473);
        __libm_sse2_atan2(y: *(long double *)v614, x: *(long double *)&v614[8]);
        v478 = (LOWORD(v604) - 1) / 2;
        *(float *)&v601 = 3.14159265 - _mm_shuffle_ps(v477, v477, 0).m128_f32[0];
        v591 = *(float *)&v601;
        v479 = v478 + 1;
        v476.m128_f32[0] = 1.0 / *(float *)&dword_5200B4[(_DWORD)v605];
        *(float *)&v610 = (float)((float)v478 * *(float *)&v601) * v476.m128_f32[0];
        v605 = (__m128 *)v476.m128_i32[0];
        *(double *)v466.m128_u64 = *(float *)&v610;
        __libm_sse2_cos(x: *(long double *)v614);
        v466.m128_f32[0] = *(double *)v466.m128_u64;
        v480 = 0;
        v480.m128_f32[0] = v466.m128_f32[0];
        v580 = _mm_shuffle_ps(v480, v480, 0);
        *(double *)v466.m128_u64 = *(float *)&v610;
        __libm_sse2_sin(x: *(long double *)v614);
        v466.m128_f32[0] = *(double *)v466.m128_u64;
        v481 = 0;
        v481.m128_f32[0] = v466.m128_f32[0];
        v541 = _mm_shuffle_ps(v481, v481, 0);
        *(float *)&v610 = (float)((float)v479 * *(float *)&v601) * *(float *)&v605;
        *(double *)v466.m128_u64 = *(float *)&v610;
        __libm_sse2_cos(x: *(long double *)v614);
        v466.m128_f32[0] = *(double *)v466.m128_u64;
        v482 = 0;
        v482.m128_f32[0] = v466.m128_f32[0];
        v582 = _mm_shuffle_ps(v482, v482, 0);
        *(double *)v466.m128_u64 = *(float *)&v610;
        __libm_sse2_sin(x: *(long double *)v614);
        v483 = 0;
        v466.m128_f32[0] = *(double *)v466.m128_u64;
        v483.m128_f32[0] = v466.m128_f32[0];
        v484 = v483;
        v445 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v580, v586), _mm_mul_ps(v541, v540)), v584);
        v442 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v582, v586), _mm_mul_ps(_mm_shuffle_ps(v484, v484, 0), v540)), v584);
      }
    }
    else
    {
      v441 = (unsigned __int16)v609;
      v442 = Four_Zeros;
      v443 = sCCLimitTanStencil1[v441];
      v607 = (int)sCCLimitTanStencil2[v441];
      *(float *)&v444 = 0.0;
      v445 = Four_Zeros;
      OutTanV[7] = Four_Zeros;
      OutTanU[8] = Four_Zeros;
      v604 = 0.0;
      if ( (_WORD)v606 != 0 )
      {
        v446 = (__m128 *)v607;
        v610 = (__m128 *)((char *)v443 - v607);
        do
        {
          v445 = _mm_add_ps(v445, _mm_mul_ps(*(__m128 *)((char *)v446 + (_DWORD)v610), v17[v598[v444]]));
          OutTanU[8] = v445;
          v447 = _mm_mul_ps(v17[v598[LODWORD(v604)]], *v446);
          v444 = LODWORD(v604) + 1;
          ++v446;
          v442 = _mm_add_ps(v442, v447);
          OutTanV[7] = v442;
          v604 = *(float *)&v444;
        }
        while ( v444 < (unsigned __int16)v606 );
      }
    }
    OutTanU[8] = _mm_mul_ps(v442, (__m128)xmmword_552660);
    OutTanV[7] = _mm_mul_ps(v445, (__m128)xmmword_552620);
    goto LABEL_271;
  }
LABEL_291:
  *(__m128 *)&quad->vtx1RingSize = v578;
  *(__m128 *)&quad->bndVtx = OutPos[0];
  *(__m128 *)&quad->edgeBias = OutPos[1];
  *(__m128 *)&quad->vUV1 = OutPos[2];
  *(__m128 *)&quad[1].vtx1RingCenterQuadOffset = OutPos[3];
  *(__m128 *)&quad[1].bndEdge = OutPos[4];
  *(__m128 *)&quad[1].nbCornerVtx = OutPos[5];
  *(__m128 *)&quad[1].vUV2 = OutPos[6];
  *(__m128 *)&quad[2].valences = OutPos[7];
  *(__m128 *)&quad[2].cornerVtx = OutPos[8];
  *(__m128 *)&quad[2].oneRing = OutPos[9];
  *(__m128 *)&quad[2].vUV3 = OutPos[10];
  *(__m128 *)&quad[3].minOneRingOffset = OutPos[11];
  *(__m128 *)&quad[3].loopGapAngle = OutPos[12];
  *(__m128 *)&quad[3].vUV0 = OutPos[13];
  *(__m128 *)&quad[4].vtx1RingSize = OutPos[14];
  *(_DWORD *)v614 = -1;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

} // namespace subdbaker
