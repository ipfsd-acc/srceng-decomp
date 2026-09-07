// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: particles/particle_sort.cpp
// Functions: 31
// ============================================================

#include "particles\particle_sort.h"

//------------------------------------------------------------------------------
// Address: 0x102A00C0
// Name: void s_GenerateData<1,0>(void __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateData<1,0>(
        __m128 *pOutData,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 *v7; // esi
  __m128 v8; // xmm7
  unsigned int v9; // ecx
  __m128 *v10; // eax
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 EyePos_4; // [esp+4h] [ebp-8Ch]
  __m128 EyePos_36; // [esp+24h] [ebp-6Ch]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-5Ch]
  __m128 fl4AlphaScale_4; // [esp+44h] [ebp-4Ch]
  unsigned int fl4AlphaVis_8; // [esp+58h] [ebp-38h]
  unsigned int fl4AlphaVis_12; // [esp+5Ch] [ebp-34h]
  __m128 *pXYZ; // [esp+60h] [ebp-30h]
  unsigned int v31; // [esp+68h] [ebp-28h]
  __m128 *pAlpha; // [esp+6Ch] [ebp-24h]
  float *v33; // [esp+74h] [ebp-1Ch]
  int pAlpha2_4; // [esp+7Ch] [ebp-14h]
  bool pRadius_3; // [esp+83h] [ebp-Dh]

  v5 = _mm_add_ps(Four_2ToThe23s, g_SIMD_0123);
  pXYZ = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  v6 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  v7 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  pAlpha2_4 = pParticles->m_nActiveParticles;
  v8 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  fl4AlphaVis_12 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  fl4AlphaScale_4 = _mm_shuffle_ps(
                      (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                      (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                      0);
  v33 = pParticles->m_ParticleAttributes.m_pAttributes[3];
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  fl4AlphaVis_8 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v9 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  pRadius_3 = pVisibilityData->m_bUseVisibility;
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v31 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  v10 = pOutData + 2;
  do
  {
    v11 = _mm_mul_ps(*pXYZ, *pAlpha);
    v12 = *(__m128 *)v33;
    if ( pRadius_3 )
    {
      v12 = _mm_mul_ps(v12, EyePos_36);
      v11 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, fl4AlphaScale_4)));
    }
    v13 = _mm_sub_ps(v7[1], EyePos_4);
    pAlpha = (__m128 *)((char *)pAlpha + v31);
    pAlpha2_4 -= 4;
    v33 = (float *)((char *)v33 + fl4AlphaVis_8);
    v14 = _mm_add_ps(_mm_mul_ps(v11, fl4RadVis_4), Four_2ToThe23s);
    v15 = _mm_sub_ps(*v7, v6);
    v16 = _mm_sub_ps(v7[2], v8);
    v17 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, v16), _mm_mul_ps(v13, v13)), _mm_mul_ps(v15, v15));
    v18 = _mm_and_ps(*(__m128 *)g_SIMD_Low16BitsMask, v5);
    v19 = _mm_shuffle_ps(v17, v18, 68);
    v20 = _mm_shuffle_ps(v17, v18, 238);
    v21 = v12;
    v22 = _mm_shuffle_ps(v12, v14, 238);
    v23 = _mm_shuffle_ps(v21, v14, 68);
    v10[-1] = _mm_shuffle_ps(v19, v23, 221);
    v10[-2] = _mm_shuffle_ps(v19, v23, 136);
    *v10 = _mm_shuffle_ps(v20, v22, 136);
    v10[1] = _mm_shuffle_ps(v20, v22, 221);
    v5 = _mm_add_ps(v5, Four_Fours);
    v10 += 4;
    v7 = (__m128 *)((char *)v7 + v9);
    pXYZ = (__m128 *)((char *)pXYZ + fl4AlphaVis_12);
  }
  while ( pAlpha2_4 > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102A02A0
// Name: void s_GenerateData<0,0>(void __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateData<0,0>(
        __m128 *pOutData,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  int m_nActiveParticles; // edx
  unsigned int v8; // esi
  __m128 v9; // xmm7
  __m128 v10; // xmm4
  __m128 *v11; // eax
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // [esp-Ch] [ebp-5Ch]
  __m128 fl4RadVis_4; // [esp+4h] [ebp-4Ch]
  float *v22; // [esp+20h] [ebp-30h]
  __m128 *v23; // [esp+28h] [ebp-28h]
  __m128 *pRadius_4; // [esp+30h] [ebp-20h]
  unsigned int pAlpha2_4; // [esp+38h] [ebp-18h]
  unsigned int pAlpha; // [esp+3Ch] [ebp-14h]
  bool pAlpha_7; // [esp+43h] [ebp-Dh]

  v5 = Four_Zeros;
  v6 = _mm_add_ps(Four_2ToThe23s, g_SIMD_0123);
  pRadius_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  v23 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  v22 = pParticles->m_ParticleAttributes.m_pAttributes[3];
  m_nActiveParticles = pParticles->m_nActiveParticles;
  fl4RadVis_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  v20 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          0);
  pAlpha_7 = pVisibilityData->m_bUseVisibility;
  v8 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  v9 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v10 = Four_Zeros;
  pAlpha = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  pAlpha2_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v11 = pOutData + 2;
  while ( 1 )
  {
    v12 = _mm_mul_ps(*pRadius_4, *v23);
    v13 = *(__m128 *)v22;
    if ( pAlpha_7 )
    {
      v13 = _mm_mul_ps(v13, v20);
      v12 = _mm_max_ps(v5, _mm_min_ps(Four_Ones, _mm_mul_ps(v12, fl4RadVis_4)));
    }
    v23 = (__m128 *)((char *)v23 + v8);
    v22 = (float *)((char *)v22 + pAlpha2_4);
    v14 = _mm_add_ps(_mm_mul_ps(v12, v9), Four_2ToThe23s);
    v15 = _mm_and_ps(*(__m128 *)g_SIMD_Low16BitsMask, v6);
    v16 = _mm_shuffle_ps(v10, v15, 238);
    v17 = _mm_shuffle_ps(v10, v15, 68);
    v18 = _mm_shuffle_ps(v13, v14, 68);
    v11[-1] = _mm_shuffle_ps(v17, v18, 221);
    v19 = _mm_shuffle_ps(v13, v14, 238);
    v10 = _mm_shuffle_ps(v17, v18, 136);
    v11[-2] = v10;
    *v11 = _mm_shuffle_ps(v16, v19, 136);
    v11[1] = _mm_shuffle_ps(v16, v19, 221);
    v6 = _mm_add_ps(v6, Four_Fours);
    m_nActiveParticles -= 4;
    v11 += 4;
    pRadius_4 = (__m128 *)((char *)pRadius_4 + pAlpha);
    if ( m_nActiveParticles <= 0 )
      break;
    v5 = Four_Zeros;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A0420
// Name: void s_GenerateData<1,1>(void __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateData<1,1>(
        __m128 *pOutData,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 *v5; // esi
  unsigned int v8; // ecx
  __m128 *v9; // eax
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm5
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // [esp-Ch] [ebp-DCh]
  __m128 v4Fwd_4; // [esp+4h] [ebp-CCh]
  __m128 v4Fwd_20; // [esp+14h] [ebp-BCh]
  __m128 v4Fwd_36; // [esp+24h] [ebp-ACh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-9Ch]
  __m128 EyePos_4; // [esp+44h] [ebp-8Ch]
  __m128 EyePos_20; // [esp+54h] [ebp-7Ch]
  __m128 EyePos_36; // [esp+64h] [ebp-6Ch]
  __m128 fl4AlphaVis_4; // [esp+74h] [ebp-5Ch]
  __m128 fl4AlphaScale_4; // [esp+84h] [ebp-4Ch]
  __m128 *fl4OutIdx_4; // [esp+94h] [ebp-3Ch]
  unsigned int pAlpha2; // [esp+A0h] [ebp-30h]
  unsigned int pAlpha2_4; // [esp+A4h] [ebp-2Ch]
  unsigned int pXYZ; // [esp+A8h] [ebp-28h]
  __m128 *pXYZ_4; // [esp+ACh] [ebp-24h]
  float *v41; // [esp+B4h] [ebp-1Ch]
  int pAlpha_4; // [esp+BCh] [ebp-14h]
  bool pRadius_3; // [esp+C3h] [ebp-Dh]

  fl4RadVis_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  pXYZ_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4OutIdx_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  v5 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  pAlpha_4 = pParticles->m_nActiveParticles;
  v26 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->x), (__m128)LODWORD(pCameraFwd->x), 0);
  v4Fwd_4 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->y), (__m128)LODWORD(pCameraFwd->y), 0);
  v4Fwd_20 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->z), (__m128)LODWORD(pCameraFwd->z), 0);
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                0);
  pXYZ = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  v4Fwd_36 = _mm_shuffle_ps(
               (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
               (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
               0);
  v41 = pParticles->m_ParticleAttributes.m_pAttributes[3];
  fl4AlphaScale_4 = _mm_add_ps(Four_2ToThe23s, g_SIMD_0123);
  pAlpha2 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v8 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  pRadius_3 = pVisibilityData->m_bUseVisibility;
  fl4AlphaVis_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  pAlpha2_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  v9 = pOutData + 2;
  do
  {
    v10 = _mm_mul_ps(*pXYZ_4, *fl4OutIdx_4);
    v11 = *(__m128 *)v41;
    if ( pRadius_3 )
    {
      v11 = _mm_mul_ps(v11, v4Fwd_36);
      v10 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v10, EyePos_36)));
    }
    v12 = _mm_sub_ps(v5[2], EyePos_20);
    v13 = _mm_sub_ps(v5[1], EyePos_4);
    v14 = _mm_sub_ps(*v5, fl4RadVis_4);
    fl4OutIdx_4 = (__m128 *)((char *)fl4OutIdx_4 + pAlpha2_4);
    pAlpha_4 -= 4;
    v41 = (float *)((char *)v41 + pAlpha2);
    v15 = _mm_add_ps(_mm_mul_ps(v4Fwd_20, v12), _mm_mul_ps(v4Fwd_4, v13));
    v16 = _mm_mul_ps(v26, v14);
    v17 = _mm_add_ps(_mm_mul_ps(v12, v12), _mm_mul_ps(v13, v13));
    v18 = _mm_and_ps(*(__m128 *)g_SIMD_Low16BitsMask, fl4AlphaScale_4);
    v19 = _mm_add_ps(v17, _mm_mul_ps(v14, v14));
    v20 = _mm_shuffle_ps(v19, v18, 68);
    v21 = _mm_shuffle_ps(v19, v18, 238);
    v22 = _mm_and_ps(
            _mm_cmple_ps(Four_Zeros, _mm_add_ps(v15, v16)),
            _mm_add_ps(_mm_mul_ps(v10, fl4AlphaVis_4), Four_2ToThe23s));
    v23 = v11;
    v24 = _mm_shuffle_ps(v11, v22, 238);
    v25 = _mm_shuffle_ps(v23, v22, 68);
    v9[-1] = _mm_shuffle_ps(v20, v25, 221);
    v9[1] = _mm_shuffle_ps(v21, v24, 221);
    v9[-2] = _mm_shuffle_ps(v20, v25, 136);
    *v9 = _mm_shuffle_ps(v21, v24, 136);
    v9 += 4;
    v5 = (__m128 *)((char *)v5 + v8);
    fl4AlphaScale_4 = _mm_add_ps(Four_Fours, fl4AlphaScale_4);
    pXYZ_4 = (__m128 *)((char *)pXYZ_4 + pXYZ);
  }
  while ( pAlpha_4 > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102A0680
// Name: void s_GenerateData<0,1>(void __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateData<0,1>(
        __m128 *pOutData,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 *v7; // esi
  unsigned int v9; // ecx
  __m128 v10; // xmm5
  __m128 *v11; // eax
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // [esp-Ch] [ebp-CCh]
  __m128 v4Fwd_4; // [esp+4h] [ebp-BCh]
  __m128 v4Fwd_20; // [esp+14h] [ebp-ACh]
  __m128 v4Fwd_36; // [esp+24h] [ebp-9Ch]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-8Ch]
  __m128 EyePos_4; // [esp+44h] [ebp-7Ch]
  __m128 EyePos_20; // [esp+54h] [ebp-6Ch]
  __m128 EyePos_36; // [esp+64h] [ebp-5Ch]
  __m128 fl4AlphaScale_4; // [esp+74h] [ebp-4Ch]
  __m128 *fl4AlphaVis_4; // [esp+84h] [ebp-3Ch]
  unsigned int pAlpha2; // [esp+90h] [ebp-30h]
  unsigned int pAlpha2_4; // [esp+94h] [ebp-2Ch]
  unsigned int pXYZ; // [esp+98h] [ebp-28h]
  __m128 *pXYZ_4; // [esp+9Ch] [ebp-24h]
  float *v34; // [esp+A4h] [ebp-1Ch]
  int pAlpha_4; // [esp+ACh] [ebp-14h]
  bool pRadius_3; // [esp+B3h] [ebp-Dh]

  fl4RadVis_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  pXYZ_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4AlphaVis_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  v5 = Four_Zeros;
  v6 = _mm_add_ps(Four_2ToThe23s, g_SIMD_0123);
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  v7 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  pAlpha_4 = pParticles->m_nActiveParticles;
  v20 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->x), (__m128)LODWORD(pCameraFwd->x), 0);
  v4Fwd_4 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->y), (__m128)LODWORD(pCameraFwd->y), 0);
  v4Fwd_20 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->z), (__m128)LODWORD(pCameraFwd->z), 0);
  pXYZ = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  fl4AlphaScale_4 = _mm_shuffle_ps(
                      (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                      (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                      0);
  v34 = pParticles->m_ParticleAttributes.m_pAttributes[3];
  v4Fwd_36 = _mm_shuffle_ps(
               (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
               (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
               0);
  pAlpha2 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v9 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  pRadius_3 = pVisibilityData->m_bUseVisibility;
  EyePos_36 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v10 = Four_Zeros;
  pAlpha2_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  v11 = pOutData + 2;
  while ( 1 )
  {
    v12 = _mm_mul_ps(*pXYZ_4, *fl4AlphaVis_4);
    v13 = *(__m128 *)v34;
    if ( pRadius_3 )
    {
      v13 = _mm_mul_ps(v13, v4Fwd_36);
      v12 = _mm_max_ps(v5, _mm_min_ps(Four_Ones, _mm_mul_ps(v12, fl4AlphaScale_4)));
    }
    fl4AlphaVis_4 = (__m128 *)((char *)fl4AlphaVis_4 + pAlpha2_4);
    pAlpha_4 -= 4;
    v34 = (float *)((char *)v34 + pAlpha2);
    v14 = _mm_and_ps(
            _mm_cmple_ps(
              v5,
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_sub_ps(v7[2], EyePos_20), v4Fwd_20),
                  _mm_mul_ps(_mm_sub_ps(v7[1], EyePos_4), v4Fwd_4)),
                _mm_mul_ps(_mm_sub_ps(*v7, fl4RadVis_4), v20))),
            _mm_add_ps(_mm_mul_ps(v12, EyePos_36), Four_2ToThe23s));
    v15 = _mm_and_ps(*(__m128 *)g_SIMD_Low16BitsMask, v6);
    v16 = _mm_shuffle_ps(v10, v15, 238);
    v17 = _mm_shuffle_ps(v10, v15, 68);
    v18 = _mm_shuffle_ps(v13, v14, 68);
    v11[-1] = _mm_shuffle_ps(v17, v18, 221);
    v19 = _mm_shuffle_ps(v13, v14, 238);
    v10 = _mm_shuffle_ps(v17, v18, 136);
    v11[-2] = v10;
    *v11 = _mm_shuffle_ps(v16, v19, 136);
    v11[1] = _mm_shuffle_ps(v16, v19, 221);
    v6 = _mm_add_ps(v6, Four_Fours);
    v11 += 4;
    v7 = (__m128 *)((char *)v7 + v9);
    pXYZ_4 = (__m128 *)((char *)pXYZ_4 + pXYZ);
    if ( pAlpha_4 <= 0 )
      break;
    v5 = Four_Zeros;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A09E0
// Name: void GenerateExtendedData<1,0,1,struct ParticleFullRenderData_SIMD_View,0,0,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,1,ParticleFullRenderData_SIMD_View,0,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  unsigned int v7; // esi
  __m128 v8; // xmm0
  __m128 *v9; // esi
  __m128 *v10; // edi
  char *v11; // eax
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // [esp-Ch] [ebp-1FCh]
  __m128 EyePos_4; // [esp+4h] [ebp-1ECh]
  __m128 EyePos_20; // [esp+14h] [ebp-1DCh]
  __m128 EyePos_36; // [esp+24h] [ebp-1CCh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-1BCh]
  __m128 Four_256s_4; // [esp+44h] [ebp-1ACh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-19Ch]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-18Ch]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+74h] [ebp-17Ch]
  __m128 fl4AlphaScale_4; // [esp+84h] [ebp-16Ch]
  __m128 fl4FinalRadius_4; // [esp+94h] [ebp-15Ch]
  unsigned int v37; // [esp+C4h] [ebp-12Ch]
  float *v38; // [esp+C8h] [ebp-128h]
  unsigned int v39; // [esp+D0h] [ebp-120h]
  int v40; // [esp+ECh] [ebp-104h]
  int v41; // [esp+12Ch] [ebp-C4h]
  int v42; // [esp+130h] [ebp-C0h]
  __m128 *v43; // [esp+158h] [ebp-98h]
  int v44; // [esp+160h] [ebp-90h]
  __m128 *pYaw; // [esp+164h] [ebp-8Ch]
  __m128 *pYaw_8; // [esp+16Ch] [ebp-84h]
  unsigned int pSeq; // [esp+170h] [ebp-80h]
  int pSeq_4; // [esp+174h] [ebp-7Ch]
  __m128 *pRadius; // [esp+178h] [ebp-78h]
  unsigned int pRadius_4; // [esp+17Ch] [ebp-74h]
  int pRadius_8; // [esp+180h] [ebp-70h]
  __m128 *pRot; // [esp+184h] [ebp-6Ch]
  unsigned int pRot_4; // [esp+188h] [ebp-68h]
  int pRot_8; // [esp+18Ch] [ebp-64h]
  __m128 *pAlpha; // [esp+190h] [ebp-60h]
  unsigned int pAlpha_4; // [esp+194h] [ebp-5Ch]
  int pAlpha_8; // [esp+198h] [ebp-58h]
  __m128 *pAlpha2; // [esp+19Ch] [ebp-54h]
  unsigned int pAlpha2_4; // [esp+1A0h] [ebp-50h]
  __m128 *pAlpha2_8; // [esp+1A4h] [ebp-4Ch]
  unsigned int pSeq1; // [esp+1A8h] [ebp-48h]
  int pSeq1_4; // [esp+1ACh] [ebp-44h]
  ParticleFullRenderData_Scalar_View **pXYZ; // [esp+1B0h] [ebp-40h]
  __m128 *pXYZ_4; // [esp+1B4h] [ebp-3Ch]
  unsigned int pXYZ_8; // [esp+1B8h] [ebp-38h]
  int v66; // [esp+1BCh] [ebp-34h]
  int pRGB; // [esp+1C0h] [ebp-30h]
  bool m_bUseVisibility; // [esp+1E3h] [ebp-Dh]

  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    pSeq1_4 = 0;
  pXYZ_8 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pXYZ_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pXYZ_8 != 0 )
    v66 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
        - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    v66 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pRot_8 = 0;
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pAlpha_4 != 0 )
    pAlpha_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
             - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pAlpha_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  pYaw_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pRadius_8 = 0;
  v7 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  v43 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( v7 != 0 )
    v44 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
        - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    v44 = 0;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v38 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pRGB = pParticles->m_nActiveParticles;
  v41 = 48 * pSeq1;
  v26 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4AlphaVis_4 = _mm_shuffle_ps(
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    0);
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  m_bUseVisibility = pVisibilityData->m_bUseVisibility;
  v42 = 48 * pXYZ_8;
  v39 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v8 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v40 = 16 * v7;
  v37 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v9 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  v10 = (__m128 *)((char *)pXYZ_4 + v66 + 16);
  pXYZ = pIndexBuffer + 2;
  v11 = pOutbuf + 8;
  do
  {
    *(pXYZ - 2) = (ParticleFullRenderData_Scalar_View *)(v11 - 8);
    *pXYZ = (ParticleFullRenderData_Scalar_View *)v11;
    *(pXYZ - 1) = (ParticleFullRenderData_Scalar_View *)(v11 - 4);
    pXYZ[1] = (ParticleFullRenderData_Scalar_View *)(v11 + 4);
    v12 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pAlpha, *(__m128 *)((char *)pAlpha + pAlpha_8)), v8),
              *(__m128 *)((char *)pAlpha + pAlpha_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v8),
              *(__m128 *)((char *)pRot + pRot_8)));
    v13 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*pYaw_8, *(__m128 *)((char *)pYaw_8 + pSeq_4)), v8),
            *(__m128 *)((char *)pYaw_8 + pSeq_4));
    fl4FinalRadius_4 = v12;
    fl4AlphaScale_4 = v13;
    if ( m_bUseVisibility )
    {
      fl4FinalRadius_4 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v12, Four_256s_4)));
      fl4AlphaScale_4 = _mm_mul_ps(v13, EyePos_36);
    }
    v14 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, v9[-1]), v8), v9[-1]);
    v15 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 + 32 - (pSeq1_4 + 16)), v9[1]), v8), v9[1]);
    v16 = _mm_sub_ps(v14, v26);
    v17 = _mm_sub_ps(v15, EyePos_20);
    v18 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 - pSeq1_4), *v9), v8), *v9);
    *(__m128 *)(v11 + 8) = v14;
    v19 = _mm_sub_ps(v18, EyePos_4);
    *(__m128 *)(v11 + 40) = v15;
    v20 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v17, v17), _mm_mul_ps(v19, v19)), _mm_mul_ps(v16, v16));
    v21 = *(__m128 *)v38;
    *(__m128 *)(v11 + 24) = v18;
    *(__m128 *)(v11 + 72) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pXYZ_4, v10[-1]), v8), v10[-1]),
                                fl4MaximumCreationTimeToDraw_4),
                              Four_2ToThe23s);
    *(__m128 *)(v11 + 88) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v10 - v66), *v10), v8), *v10),
                                fl4MaximumCreationTimeToDraw_4),
                              Four_2ToThe23s);
    v22 = _mm_mul_ps(
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v10 + 32 - (v66 + 16)), v10[1]), v8), v10[1]),
            fl4MaximumCreationTimeToDraw_4);
    v23 = _mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v11 + 56) = _mm_and_ps(
                              _mm_add_ps(_mm_mul_ps(fl4FinalRadius_4, fl4MaximumCreationTimeToDraw_4), Four_2ToThe23s),
                              _mm_cmplt_ps(v21, fl4CurTime_4));
    *(__m128 *)(v11 + 120) = fl4AlphaScale_4;
    v24 = _mm_add_ps(_mm_mul_ps(v23, v8), *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v11 - 8) = v20;
    *(__m128 *)(v11 + 104) = _mm_add_ps(v22, Four_2ToThe23s);
    *(__m128 *)(v11 + 136) = _mm_sub_ps(fl4AlphaVis_4, v21);
    *(__m128 *)(v11 + 168) = v24;
    *(__m128 *)(v11 + 184) = _mm_add_ps(
                               _mm_mul_ps(_mm_sub_ps(*v43, *(__m128 *)((char *)v43 + v44)), v8),
                               *(__m128 *)((char *)v43 + v44));
    if ( pAlpha2_4 != 0 )
      v25 = _mm_add_ps(_mm_mul_ps(*pAlpha2, fl4RadVis_4), *pYaw);
    else
      v25 = *pYaw;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v41);
    pRot += pRot_4;
    pYaw_8 += pSeq;
    pRadius += pRadius_4;
    pRGB -= 4;
    pXYZ += 4;
    pAlpha2 += pAlpha2_4;
    v9 = (__m128 *)((char *)v9 + v41);
    pAlpha += pAlpha_4;
    pXYZ_4 = (__m128 *)((char *)pXYZ_4 + v42);
    v10 = (__m128 *)((char *)v10 + v42);
    v43 = (__m128 *)((char *)v43 + v40);
    pYaw = (__m128 *)((char *)pYaw + v39);
    v38 = (float *)((char *)v38 + v37);
    *(__m128 *)(v11 + 152) = _mm_add_ps(v25, Four_2ToThe23s);
    v11 += 208;
  }
  while ( pRGB > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102A0FE0
// Name: void GenerateExtendedData<1,0,0,struct ParticleFullRenderData_SIMD_View,0,0,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,0,ParticleFullRenderData_SIMD_View,0,0,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 v6; // xmm4
  ParticleFullRenderData_Scalar_View **v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // edi
  char *v10; // eax
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __int128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // [esp-Ch] [ebp-10Ch]
  __m128 EyePos_4; // [esp+4h] [ebp-FCh]
  __m128 EyePos_20; // [esp+14h] [ebp-ECh]
  __m128 EyePos_36; // [esp+24h] [ebp-DCh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-CCh]
  __m128 Four_256s_4; // [esp+44h] [ebp-BCh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-ACh]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-9Ch]
  unsigned int fl4FinalRadius_12; // [esp+7Ch] [ebp-84h]
  unsigned int v30; // [esp+80h] [ebp-80h]
  unsigned int v31; // [esp+84h] [ebp-7Ch]
  unsigned int v32; // [esp+88h] [ebp-78h]
  unsigned int v33; // [esp+8Ch] [ebp-74h]
  __m128 *v34; // [esp+90h] [ebp-70h]
  unsigned int v35; // [esp+98h] [ebp-68h]
  __m128 *pRadius; // [esp+9Ch] [ebp-64h]
  __m128 *v37; // [esp+A4h] [ebp-5Ch]
  unsigned int pAlpha2_4; // [esp+ACh] [ebp-54h]
  float *pAlpha; // [esp+B0h] [ebp-50h]
  float *v40; // [esp+B8h] [ebp-48h]
  float *pXYZ_4; // [esp+C0h] [ebp-40h]
  __m128 *pRot_4; // [esp+C8h] [ebp-38h]
  __m128 *pYaw_4; // [esp+D0h] [ebp-30h]
  __m128 *pCreationTimeStamp_4; // [esp+D8h] [ebp-28h]
  unsigned int pRGB; // [esp+DCh] [ebp-24h]
  __m128 *pRGB_4; // [esp+E0h] [ebp-20h]
  ParticleFullRenderData_Scalar_View **pSeq1_4; // [esp+E8h] [ebp-18h]
  int pSeq; // [esp+ECh] [ebp-14h]
  bool pSeq_7; // [esp+F3h] [ebp-Dh]

  pAlpha = pParticles->m_ParticleAttributes.m_pAttributes[0];
  pYaw_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  v37 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  v34 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  v40 = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pXYZ_4 = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  fl4AlphaVis_4 = pParticles->m_fl4CurTime;
  pRGB = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  pCreationTimeStamp_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v21 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  pRot_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  pSeq_7 = pVisibilityData->m_bUseVisibility;
  pSeq = pParticles->m_nActiveParticles;
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  v6 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v32 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  pAlpha2_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2);
  v31 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2);
  v33 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v30 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  fl4FinalRadius_12 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v7 = pIndexBuffer + 2;
  v8 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  v9 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC);
  v35 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  pSeq1_4 = pIndexBuffer + 2;
  v10 = pOutbuf + 8;
  while ( 1 )
  {
    *(v7 - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *(v7 - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    *v7 = (ParticleFullRenderData_Scalar_View *)v10;
    v7[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v11 = _mm_mul_ps(*v37, *pRadius);
    fl4CurTime_4 = *v34;
    if ( pSeq_7 )
    {
      v11 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, Four_256s_4)));
      fl4CurTime_4 = _mm_mul_ps(*v34, EyePos_36);
    }
    v12 = *(__m128 *)(pAlpha + 4);
    v13 = *(__m128 *)pAlpha;
    v14 = _mm_sub_ps(*(__m128 *)(pAlpha + 8), EyePos_20);
    v15 = _mm_sub_ps(v12, EyePos_4);
    v16 = _mm_sub_ps(*(__m128 *)pAlpha, v21);
    v17 = _mm_add_ps(_mm_mul_ps(v14, v14), _mm_mul_ps(v15, v15));
    v18 = _mm_mul_ps(*pYaw_4, v6);
    *(_OWORD *)(v10 + 40) = *((_OWORD *)pAlpha + 2);
    *(__m128 *)(v10 + 72) = _mm_add_ps(v18, Four_2ToThe23s);
    *(__m128 *)(v10 + 88) = _mm_add_ps(_mm_mul_ps(pYaw_4[1], v6), Four_2ToThe23s);
    *(__m128 *)(v10 + 104) = _mm_add_ps(_mm_mul_ps(pYaw_4[2], v6), Four_2ToThe23s);
    *(__m128 *)(v10 + 120) = fl4CurTime_4;
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4AlphaVis_4, *pRot_4);
    *(_OWORD *)(v10 + 168) = *(_OWORD *)v40;
    v19 = *(_OWORD *)pXYZ_4;
    *(__m128 *)(v10 - 8) = _mm_add_ps(v17, _mm_mul_ps(v16, v16));
    *(__m128 *)(v10 + 8) = v13;
    *(__m128 *)(v10 + 24) = v12;
    *(__m128 *)(v10 + 56) = _mm_add_ps(_mm_mul_ps(v11, v6), Four_2ToThe23s);
    *(_OWORD *)(v10 + 184) = v19;
    if ( pRGB != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pCreationTimeStamp_4, fl4RadVis_4), *pRGB_4);
    else
      v20 = *pRGB_4;
    pSeq -= 4;
    pSeq1_4 += 4;
    pYaw_4 = (__m128 *)((char *)pYaw_4 + v9);
    pAlpha = (float *)((char *)pAlpha + v8);
    v37 = (__m128 *)((char *)v37 + v32);
    pRadius = (__m128 *)((char *)pRadius + v35);
    v34 = (__m128 *)((char *)v34 + v30);
    pXYZ_4 = (float *)((char *)pXYZ_4 + pAlpha2_4);
    v40 = (float *)((char *)v40 + v31);
    pRGB_4 = (__m128 *)((char *)pRGB_4 + v33);
    pCreationTimeStamp_4 += pRGB;
    pRot_4 = (__m128 *)((char *)pRot_4 + fl4FinalRadius_12);
    *(__m128 *)(v10 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    v10 += 208;
    if ( pSeq <= 0 )
      break;
    v7 = pSeq1_4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1370
// Name: void GenerateExtendedData<0,0,1,struct ParticleFullRenderData_SIMD_View,0,0,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,1,ParticleFullRenderData_SIMD_View,0,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  int v7; // edx
  int v8; // edx
  char *v9; // eax
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 *v12; // esi
  __m128 *v13; // ecx
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm6
  __m128 v17; // xmm7
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // [esp-Ch] [ebp-1BCh]
  __m128 Four_256s_4; // [esp+4h] [ebp-1ACh]
  __m128 fl4RadVis_4; // [esp+14h] [ebp-19Ch]
  __m128 fl4CurTime_4; // [esp+24h] [ebp-18Ch]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+34h] [ebp-17Ch]
  unsigned int fl4AlphaVis_8; // [esp+48h] [ebp-168h]
  unsigned int fl4AlphaVis_12; // [esp+4Ch] [ebp-164h]
  int v30; // [esp+6Ch] [ebp-144h]
  int v31; // [esp+F0h] [ebp-C0h]
  float *v32; // [esp+128h] [ebp-88h]
  __m128 *pCreationTimeStamp; // [esp+134h] [ebp-7Ch]
  __m128 *v34; // [esp+13Ch] [ebp-74h]
  unsigned int pSeq; // [esp+140h] [ebp-70h]
  int pSeq_4; // [esp+144h] [ebp-6Ch]
  __m128 *pRadius; // [esp+148h] [ebp-68h]
  unsigned int pRadius_4; // [esp+14Ch] [ebp-64h]
  int pRadius_8; // [esp+150h] [ebp-60h]
  __m128 *pYaw; // [esp+154h] [ebp-5Ch]
  unsigned int pYaw_4; // [esp+158h] [ebp-58h]
  int pYaw_8; // [esp+15Ch] [ebp-54h]
  __m128 *pAlpha; // [esp+160h] [ebp-50h]
  unsigned int pAlpha_4; // [esp+164h] [ebp-4Ch]
  int pAlpha_8; // [esp+168h] [ebp-48h]
  __m128 *pRot; // [esp+16Ch] [ebp-44h]
  unsigned int pRot_4; // [esp+170h] [ebp-40h]
  int pRot_8; // [esp+174h] [ebp-3Ch]
  __m128 *pAlpha2; // [esp+178h] [ebp-38h]
  unsigned int pAlpha2_4; // [esp+17Ch] [ebp-34h]
  int pAlpha2_8; // [esp+180h] [ebp-30h]
  __m128 *pRGB; // [esp+184h] [ebp-2Ch]
  unsigned int pRGB_4; // [esp+188h] [ebp-28h]
  __m128 *pRGB_8; // [esp+18Ch] [ebp-24h]
  unsigned int pSeq1; // [esp+190h] [ebp-20h]
  int pSeq1_4; // [esp+194h] [ebp-1Ch]
  int pXYZ; // [esp+198h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pXYZ_4; // [esp+19Ch] [ebp-14h]
  bool pXYZ_11; // [esp+1A3h] [ebp-Dh]

  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    pSeq1_4 = 0;
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pAlpha2_4 != 0 )
    v7 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
       - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    v7 = 0;
  pAlpha2_8 = v7;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v34 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pAlpha_4 != 0 )
    pAlpha_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
             - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pAlpha_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  v32 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pXYZ = pParticles->m_nActiveParticles;
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  fl4RadVis_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  0);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps(
                                     (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                                     (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                                     0);
  v30 = 48 * pSeq1;
  fl4AlphaVis_8 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v31 = 48 * pAlpha2_4;
  fl4AlphaVis_12 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  v8 = v7 + 16;
  pXYZ_11 = pVisibilityData->m_bUseVisibility;
  pXYZ_4 = pIndexBuffer + 2;
  v23 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v9 = pOutbuf + 8;
  v10 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  0);
  v11 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v12 = (__m128 *)((char *)pRGB_8 + pSeq1_4 + 16);
  v13 = (__m128 *)((char *)pAlpha2 + v8);
  do
  {
    *(pXYZ_4 - 2) = (ParticleFullRenderData_Scalar_View *)(v9 - 8);
    *pXYZ_4 = (ParticleFullRenderData_Scalar_View *)v9;
    *(pXYZ_4 - 1) = (ParticleFullRenderData_Scalar_View *)(v9 - 4);
    pXYZ_4[1] = (ParticleFullRenderData_Scalar_View *)(v9 + 4);
    v14 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v34, *(__m128 *)((char *)v34 + pSeq_4)), v10),
            *(__m128 *)((char *)v34 + pSeq_4));
    v15 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v10),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v10),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    if ( pXYZ_11 )
    {
      v14 = _mm_mul_ps(v14, Four_256s_4);
      v15 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v15, fl4MaximumCreationTimeToDraw_4)));
    }
    v16 = v12[1];
    v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB_8, v12[-1]), v10), v12[-1]);
    *(__m128 *)(v9 + 24) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v12 - pSeq1_4), *v12), v10), *v12);
    v18 = *(__m128 *)v32;
    *(__m128 *)(v9 + 40) = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v12 + 32 - (pSeq1_4 + 16)), v16), v10),
                             v16);
    *(__m128 *)(v9 + 56) = _mm_and_ps(_mm_add_ps(_mm_mul_ps(v15, v11), Four_2ToThe23s), _mm_cmplt_ps(v18, fl4CurTime_4));
    *(__m128 *)(v9 + 72) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_sub_ps(*pAlpha2, *(__m128 *)((char *)v13 + pAlpha2_8 - v8)), v10),
                                 *(__m128 *)((char *)v13 + pAlpha2_8 - v8)),
                               v11),
                             Four_2ToThe23s);
    v19 = *(__m128 *)((char *)v13 + pAlpha2_8 - v8 + 32);
    *(__m128 *)(v9 + 88) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v13 + 16 - v8), *v13), v10), *v13),
                               v11),
                             Four_2ToThe23s);
    v20 = *(__m128 *)((char *)v13 + 32 - v8);
    *(__m128 *)(v9 + 120) = v14;
    *(__m128 *)(v9 + 168) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(*pAlpha, *(__m128 *)((char *)pAlpha + pAlpha_8)), v10),
                              *(__m128 *)((char *)pAlpha + pAlpha_8));
    v21 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v10),
            *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v9 + 8) = v17;
    *(__m128 *)(v9 + 104) = _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(v20, v19), v10), v19), v11),
                              Four_2ToThe23s);
    *(__m128 *)(v9 + 136) = _mm_sub_ps(fl4RadVis_4, v18);
    *(__m128 *)(v9 + 184) = v21;
    if ( pRGB_4 != 0 )
      v22 = _mm_add_ps(_mm_mul_ps(*pRGB, v23), *pCreationTimeStamp);
    else
      v22 = *pCreationTimeStamp;
    pRGB_8 = (__m128 *)((char *)pRGB_8 + v30);
    v12 = (__m128 *)((char *)v12 + v30);
    pYaw += pYaw_4;
    pRot += pRot_4;
    v34 += pSeq;
    pAlpha2 = (__m128 *)((char *)pAlpha2 + v31);
    pXYZ -= 4;
    pXYZ_4 += 4;
    v13 = (__m128 *)((char *)v13 + v31);
    pRadius += pRadius_4;
    pAlpha += pAlpha_4;
    pCreationTimeStamp = (__m128 *)((char *)pCreationTimeStamp + fl4AlphaVis_8);
    pRGB += pRGB_4;
    v32 = (float *)((char *)v32 + fl4AlphaVis_12);
    *(__m128 *)(v9 + 152) = _mm_add_ps(v22, Four_2ToThe23s);
    v9 += 208;
  }
  while ( pXYZ > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102A18D0
// Name: void GenerateExtendedData<0,0,0,struct ParticleFullRenderData_SIMD_View,0,0,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,0,ParticleFullRenderData_SIMD_View,0,0,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  unsigned int v6; // eax
  __m128 m_fl4CurTime; // xmm4
  unsigned int v8; // esi
  unsigned int v9; // edi
  __m128 v10; // xmm7
  int m_nActiveParticles; // edx
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  ParticleFullRenderData_Scalar_View **v15; // edx
  char *v16; // eax
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __int128 v19; // xmm0
  __m128 v20; // xmm0
  float *pRadius; // [esp+8h] [ebp-74h]
  __m128 *pAlpha2; // [esp+10h] [ebp-6Ch]
  __m128 *pAlpha; // [esp+18h] [ebp-64h]
  float *pXYZ; // [esp+20h] [ebp-5Ch]
  unsigned int pXYZ_4; // [esp+24h] [ebp-58h]
  __m128 *pCreationTimeStamp; // [esp+28h] [ebp-54h]
  unsigned int pCreationTimeStamp_4; // [esp+2Ch] [ebp-50h]
  float *pRot; // [esp+30h] [ebp-4Ch]
  unsigned int pRot_4; // [esp+34h] [ebp-48h]
  float *pYaw; // [esp+38h] [ebp-44h]
  unsigned int pYaw_4; // [esp+3Ch] [ebp-40h]
  __m128 *pRGB; // [esp+40h] [ebp-3Ch]
  unsigned int pRGB_4; // [esp+44h] [ebp-38h]
  __m128 *pSeq1; // [esp+48h] [ebp-34h]
  unsigned int pSeq1_4; // [esp+4Ch] [ebp-30h]
  __m128 *pSeq; // [esp+50h] [ebp-2Ch]
  unsigned int pSeq_4; // [esp+54h] [ebp-28h]
  int v38; // [esp+74h] [ebp-8h]
  int nParticles; // [esp+78h] [ebp-4h]
  CParticleVisibilityData *pVisibilityDataa; // [esp+9Ch] [ebp+20h]
  bool bUseVis_3; // [esp+A3h] [ebp+27h]

  pXYZ_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pXYZ = pParticles->m_ParticleAttributes.m_pAttributes[0];
  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  pRadius = pParticles->m_ParticleAttributes.m_pAttributes[3];
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pRot = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  v6 = pParticles->m_ParticleAttributes.m_nFloatStrides[7];
  m_fl4CurTime = pParticles->m_fl4CurTime;
  pYaw = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pSeq_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2;
  pSeq = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pSeq1_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pSeq1 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v8 = pParticles->m_ParticleAttributes.m_nFloatStrides[16];
  v9 = pParticles->m_ParticleAttributes.m_nFloatStrides[3];
  pCreationTimeStamp_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2;
  v10 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v12 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
          (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
          0);
  bUseVis_3 = pVisibilityData->m_bUseVisibility;
  v13 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          0);
  nParticles = m_nActiveParticles;
  v14 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v38 = 16 * (v6 >> 2);
  v15 = pIndexBuffer + 2;
  pVisibilityDataa = (CParticleVisibilityData *)(pIndexBuffer + 2);
  v16 = pOutbuf + 8;
  while ( 1 )
  {
    *(v15 - 2) = (ParticleFullRenderData_Scalar_View *)(v16 - 8);
    *(v15 - 1) = (ParticleFullRenderData_Scalar_View *)(v16 - 4);
    *v15 = (ParticleFullRenderData_Scalar_View *)v16;
    v15[1] = (ParticleFullRenderData_Scalar_View *)(v16 + 4);
    v17 = _mm_mul_ps(*pAlpha, *pAlpha2);
    v18 = *(__m128 *)pRadius;
    if ( bUseVis_3 )
    {
      v17 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v17, v12)));
      v18 = _mm_mul_ps(v18, v13);
    }
    *(_OWORD *)(v16 + 8) = *(_OWORD *)pXYZ;
    *(_OWORD *)(v16 + 24) = *((_OWORD *)pXYZ + 1);
    *(_OWORD *)(v16 + 40) = *((_OWORD *)pXYZ + 2);
    *(__m128 *)(v16 + 56) = _mm_add_ps(_mm_mul_ps(v17, v14), Four_2ToThe23s);
    *(__m128 *)(v16 + 72) = _mm_add_ps(_mm_mul_ps(*pRGB, v14), Four_2ToThe23s);
    *(__m128 *)(v16 + 88) = _mm_add_ps(_mm_mul_ps(pRGB[1], v14), Four_2ToThe23s);
    *(__m128 *)(v16 + 104) = _mm_add_ps(_mm_mul_ps(pRGB[2], v14), Four_2ToThe23s);
    *(__m128 *)(v16 + 136) = _mm_sub_ps(m_fl4CurTime, *pCreationTimeStamp);
    *(_OWORD *)(v16 + 168) = *(_OWORD *)pRot;
    v19 = *(_OWORD *)pYaw;
    *(__m128 *)(v16 + 120) = v18;
    *(_OWORD *)(v16 + 184) = v19;
    if ( pSeq1_4 != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pSeq1, v10), *pSeq);
    else
      v20 = *pSeq;
    nParticles -= 4;
    pVisibilityDataa = (CParticleVisibilityData *)((char *)pVisibilityDataa + 16);
    pRGB += 3 * pRGB_4;
    pXYZ += 12 * pXYZ_4;
    pAlpha = (__m128 *)((char *)pAlpha + v38);
    pAlpha2 += v8 >> 2;
    pRadius += 4 * (v9 >> 2);
    pYaw += 4 * pYaw_4;
    pRot += 4 * pRot_4;
    pSeq += pSeq_4;
    pSeq1 += pSeq1_4;
    pCreationTimeStamp += pCreationTimeStamp_4;
    *(__m128 *)(v16 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    v16 += 208;
    if ( nParticles <= 0 )
      break;
    v15 = (ParticleFullRenderData_Scalar_View **)pVisibilityDataa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1C80
// Name: void GenerateExtendedData<1,0,1,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  int v7; // eax
  __m128 v8; // xmm0
  __m128 *v9; // esi
  char *v10; // eax
  __m128 *v11; // edi
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __int128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // [esp-Ch] [ebp-2CCh]
  __m128 EyePos_4; // [esp+4h] [ebp-2BCh]
  __m128 EyePos_20; // [esp+14h] [ebp-2ACh]
  __m128 EyePos_36; // [esp+24h] [ebp-29Ch]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-28Ch]
  __m128 Four_256s_4; // [esp+44h] [ebp-27Ch]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-26Ch]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-25Ch]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+74h] [ebp-24Ch]
  __m128 fl4AlphaScale_4; // [esp+84h] [ebp-23Ch]
  __m128 fl4FinalRadius_4; // [esp+94h] [ebp-22Ch]
  unsigned int v44; // [esp+D8h] [ebp-1E8h]
  unsigned int v45; // [esp+E0h] [ebp-1E0h]
  float *v46; // [esp+100h] [ebp-1C0h]
  float *v47; // [esp+108h] [ebp-1B8h]
  unsigned int pCreationTimeStamp; // [esp+10Ch] [ebp-1B4h]
  int v49; // [esp+180h] [ebp-140h]
  int v50; // [esp+1C0h] [ebp-100h]
  int v51; // [esp+1E0h] [ebp-E0h]
  int v52; // [esp+1F4h] [ebp-CCh]
  __m128 *v53; // [esp+21Ch] [ebp-A4h]
  __m128 *v54; // [esp+224h] [ebp-9Ch]
  unsigned int pSeq; // [esp+228h] [ebp-98h]
  int pSeq_4; // [esp+22Ch] [ebp-94h]
  __m128 *pRadius; // [esp+230h] [ebp-90h]
  unsigned int pRadius_4; // [esp+234h] [ebp-8Ch]
  int pRadius_8; // [esp+238h] [ebp-88h]
  __m128 *pYaw; // [esp+23Ch] [ebp-84h]
  unsigned int pYaw_4; // [esp+240h] [ebp-80h]
  int pYaw_8; // [esp+244h] [ebp-7Ch]
  __m128 *pAlpha; // [esp+248h] [ebp-78h]
  unsigned int pAlpha_4; // [esp+24Ch] [ebp-74h]
  int pAlpha_8; // [esp+250h] [ebp-70h]
  __m128 *pRGB2; // [esp+254h] [ebp-6Ch]
  unsigned int pRGB2_4; // [esp+258h] [ebp-68h]
  int pRGB2_8; // [esp+25Ch] [ebp-64h]
  __m128 *pRot; // [esp+260h] [ebp-60h]
  unsigned int pRot_4; // [esp+264h] [ebp-5Ch]
  int pRot_8; // [esp+268h] [ebp-58h]
  __m128 *pAlpha2; // [esp+26Ch] [ebp-54h]
  unsigned int pAlpha2_4; // [esp+270h] [ebp-50h]
  __m128 *pAlpha2_8; // [esp+274h] [ebp-4Ch]
  unsigned int pSeq1; // [esp+278h] [ebp-48h]
  int pSeq1_4; // [esp+27Ch] [ebp-44h]
  __m128 *pRGB; // [esp+280h] [ebp-40h]
  unsigned int pRGB_4; // [esp+284h] [ebp-3Ch]
  int pRGB_8; // [esp+288h] [ebp-38h]
  int pXYZ; // [esp+28Ch] [ebp-34h]
  ParticleFullRenderData_Scalar_View **pXYZ_4; // [esp+290h] [ebp-30h]
  __m128 *pXYZ_8; // [esp+294h] [ebp-2Ch]
  bool m_bUseVisibility; // [esp+2B3h] [ebp-Dh]

  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pRGB_4 != 0 )
    pRGB_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    pRGB_8 = 0;
  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    pSeq1_4 = 0;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v54 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pRGB2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pRGB2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pRGB2_4 != 0 )
    pRGB2_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pRGB2_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  v53 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v46 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pCreationTimeStamp = pParticles->m_ParticleAttributes.m_nFloatStrides[23] >> 2;
  v47 = pParticles->m_ParticleAttributes.m_pAttributes[23];
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[22] / 0xC;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[22];
  if ( pAlpha_4 != 0 )
    v7 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[22]
       - (char *)pParticles->m_ParticleAttributes.m_pAttributes[22];
  else
    v7 = 0;
  pAlpha_8 = v7;
  v51 = 48 * pAlpha_4;
  v50 = 48 * pRGB_4;
  v33 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  v49 = 48 * pSeq1;
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4AlphaVis_4 = _mm_shuffle_ps(
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    0);
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  pXYZ = pParticles->m_nActiveParticles;
  m_bUseVisibility = pVisibilityData->m_bUseVisibility;
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v8 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v45 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v44 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  pXYZ_4 = pIndexBuffer + 2;
  v9 = (__m128 *)((char *)pAlpha + v7 + 16);
  pXYZ_8 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  v52 = -v7;
  v10 = pOutbuf + 8;
  v11 = (__m128 *)((char *)pRGB + pRGB_8 + 16);
  do
  {
    *(pXYZ_4 - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *pXYZ_4 = (ParticleFullRenderData_Scalar_View *)v10;
    *(pXYZ_4 - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    pXYZ_4[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v12 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v8),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v8),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    v13 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v54, *(__m128 *)((char *)v54 + pSeq_4)), v8),
            *(__m128 *)((char *)v54 + pSeq_4));
    fl4FinalRadius_4 = v12;
    fl4AlphaScale_4 = v13;
    if ( m_bUseVisibility )
    {
      fl4FinalRadius_4 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v12, Four_256s_4)));
      fl4AlphaScale_4 = _mm_mul_ps(v13, EyePos_36);
    }
    v14 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB, v11[-1]), v8), v11[-1]);
    v15 = _mm_sub_ps(*(__m128 *)((char *)v11 - pRGB_8), *v11);
    v16 = _mm_sub_ps(v14, v33);
    v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v11 + 32 - (pRGB_8 + 16)), v11[1]), v8), v11[1]);
    *(__m128 *)(v10 + 8) = v14;
    v18 = _mm_add_ps(_mm_mul_ps(v15, v8), *v11);
    v19 = _mm_sub_ps(v17, EyePos_20);
    v20 = _mm_sub_ps(v18, EyePos_4);
    *(__m128 *)(v10 + 40) = v17;
    v21 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v19, v19), _mm_mul_ps(v20, v20)), _mm_mul_ps(v16, v16));
    v22 = *(__m128 *)v46;
    *(__m128 *)(v10 + 24) = v18;
    *(__m128 *)(v10 + 56) = _mm_and_ps(
                              _mm_add_ps(_mm_mul_ps(fl4FinalRadius_4, fl4MaximumCreationTimeToDraw_4), Four_2ToThe23s),
                              _mm_cmplt_ps(v22, fl4CurTime_4));
    *(__m128 *)(v10 + 72) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, pXYZ_8[-1]), v8), pXYZ_8[-1]),
                                fl4MaximumCreationTimeToDraw_4),
                              Four_2ToThe23s);
    v23 = pXYZ_8[1];
    *(__m128 *)(v10 + 88) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)pXYZ_8 - pSeq1_4), *pXYZ_8), v8),
                                  *pXYZ_8),
                                fl4MaximumCreationTimeToDraw_4),
                              Four_2ToThe23s);
    v24 = _mm_mul_ps(
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)pXYZ_8 + 32 - (pSeq1_4 + 16)), v23), v8), v23),
            fl4MaximumCreationTimeToDraw_4);
    v25 = _mm_sub_ps(*pRGB2, *(__m128 *)((char *)pRGB2 + pRGB2_8));
    *(__m128 *)(v10 + 120) = fl4AlphaScale_4;
    *(__m128 *)(v10 - 8) = v21;
    *(__m128 *)(v10 + 104) = _mm_add_ps(v24, Four_2ToThe23s);
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4AlphaVis_4, v22);
    *(__m128 *)(v10 + 168) = _mm_add_ps(_mm_mul_ps(v25, v8), *(__m128 *)((char *)pRGB2 + pRGB2_8));
    *(__m128 *)(v10 + 184) = _mm_add_ps(
                               _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v8),
                               *(__m128 *)((char *)pRadius + pRadius_8));
    if ( pAlpha2_4 != 0 )
      v26 = _mm_add_ps(_mm_mul_ps(*pAlpha2, fl4RadVis_4), *v53);
    else
      v26 = *v53;
    v27 = v9[-1];
    v28 = _mm_sub_ps(*pAlpha, v27);
    *(__m128 *)(v10 + 152) = _mm_add_ps(v26, Four_2ToThe23s);
    v29 = _mm_add_ps(_mm_mul_ps(v28, v8), v27);
    pXYZ -= 4;
    pXYZ_4 += 4;
    v30 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 + 32 - (pAlpha_8 + 16)), v9[1]), v8), v9[1]);
    v31 = *(_OWORD *)v47;
    pAlpha = (__m128 *)((char *)pAlpha + v51);
    v47 += 4 * pCreationTimeStamp;
    pRGB = (__m128 *)((char *)pRGB + v50);
    v11 = (__m128 *)((char *)v11 + v50);
    pRot += pRot_4;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v49);
    pXYZ_8 = (__m128 *)((char *)pXYZ_8 + v49);
    pRadius += pRadius_4;
    v53 = (__m128 *)((char *)v53 + v45);
    v46 = (float *)((char *)v46 + v44);
    v32 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 + v52), *v9), v8), *v9);
    v9 = (__m128 *)((char *)v9 + v51);
    pYaw += pYaw_4;
    v54 += pSeq;
    pRGB2 += pRGB2_4;
    pAlpha2 += pAlpha2_4;
    *(__m128 *)(v10 + 200) = v29;
    *(__m128 *)(v10 + 216) = v32;
    *(__m128 *)(v10 + 232) = v30;
    *(_OWORD *)(v10 + 248) = v31;
    v10 += 272;
  }
  while ( pXYZ > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102A23F0
// Name: void GenerateExtendedData<1,0,0,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  unsigned int v6; // kr04_4
  float *v7; // edx
  ParticleFullRenderData_Scalar_View **v8; // ecx
  __m128 v9; // xmm4
  char *v10; // eax
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __int128 v19; // xmm1
  __m128 v20; // xmm1
  __int128 v21; // xmm0
  __int128 v22; // xmm0
  __m128 v23; // [esp-Ch] [ebp-12Ch]
  __m128 EyePos_4; // [esp+4h] [ebp-11Ch]
  __m128 EyePos_20; // [esp+14h] [ebp-10Ch]
  __m128 EyePos_36; // [esp+24h] [ebp-FCh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-ECh]
  __m128 Four_256s_4; // [esp+44h] [ebp-DCh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-CCh]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-BCh]
  unsigned int v31; // [esp+80h] [ebp-A0h]
  unsigned int v32; // [esp+88h] [ebp-98h]
  unsigned int v33; // [esp+8Ch] [ebp-94h]
  unsigned int pRGB2; // [esp+90h] [ebp-90h]
  unsigned int pRGB2_4; // [esp+94h] [ebp-8Ch]
  unsigned int v36; // [esp+98h] [ebp-88h]
  __m128 *v37; // [esp+9Ch] [ebp-84h]
  unsigned int v38; // [esp+A4h] [ebp-7Ch]
  __m128 *pAlpha2; // [esp+A8h] [ebp-78h]
  unsigned int v40; // [esp+B0h] [ebp-70h]
  unsigned int pAlpha_4; // [esp+B8h] [ebp-68h]
  unsigned int v42; // [esp+BCh] [ebp-64h]
  float *v43; // [esp+C0h] [ebp-60h]
  float *v44; // [esp+C8h] [ebp-58h]
  __m128 *pGlowAlpha_4; // [esp+D0h] [ebp-50h]
  __m128 *pXYZ_4; // [esp+D8h] [ebp-48h]
  float *pRadius_4; // [esp+E0h] [ebp-40h]
  float *pCreationTimeStamp_4; // [esp+E8h] [ebp-38h]
  __m128 *pRot_4; // [esp+F0h] [ebp-30h]
  __m128 *pYaw_4; // [esp+F8h] [ebp-28h]
  __m128 *pRGB_4; // [esp+100h] [ebp-20h]
  unsigned int pSeq; // [esp+104h] [ebp-1Ch]
  int pSeq_4; // [esp+108h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pSeq1; // [esp+10Ch] [ebp-14h]
  bool pSeq1_7; // [esp+113h] [ebp-Dh]

  v44 = pParticles->m_ParticleAttributes.m_pAttributes[0];
  v6 = pParticles->m_ParticleAttributes.m_nFloatStrides[6];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pGlowAlpha_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  pCreationTimeStamp_4 = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pRot_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  v37 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  pRadius_4 = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pYaw_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  v43 = pParticles->m_ParticleAttributes.m_pAttributes[23];
  fl4AlphaVis_4 = pParticles->m_fl4CurTime;
  pXYZ_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v23 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  pSeq_4 = pParticles->m_nActiveParticles;
  v7 = pParticles->m_ParticleAttributes.m_pAttributes[22];
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  pRGB2_4 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[22] / 0xC);
  v33 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[23] >> 2);
  v40 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  v38 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v31 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2);
  pRGB2 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2);
  pAlpha_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v36 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  pSeq1_7 = pVisibilityData->m_bUseVisibility;
  v32 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v8 = pIndexBuffer + 2;
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  v9 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v42 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  pSeq1 = pIndexBuffer + 2;
  v10 = pOutbuf + 8;
  while ( 1 )
  {
    *(v8 - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *(v8 - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    *v8 = (ParticleFullRenderData_Scalar_View *)v10;
    v8[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v11 = _mm_mul_ps(*pAlpha2, *v37);
    fl4CurTime_4 = *pGlowAlpha_4;
    if ( pSeq1_7 )
    {
      v11 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, Four_256s_4)));
      fl4CurTime_4 = _mm_mul_ps(*pGlowAlpha_4, EyePos_36);
    }
    v12 = *(__m128 *)(v44 + 4);
    v13 = *(__m128 *)v44;
    v14 = _mm_sub_ps(*(__m128 *)(v44 + 8), EyePos_20);
    v15 = _mm_sub_ps(v12, EyePos_4);
    v16 = _mm_sub_ps(*(__m128 *)v44, v23);
    v17 = _mm_add_ps(_mm_mul_ps(v14, v14), _mm_mul_ps(v15, v15));
    v18 = _mm_mul_ps(*pRot_4, v9);
    *(_OWORD *)(v10 + 40) = *((_OWORD *)v44 + 2);
    *(__m128 *)(v10 + 72) = _mm_add_ps(v18, Four_2ToThe23s);
    *(__m128 *)(v10 + 88) = _mm_add_ps(_mm_mul_ps(pRot_4[1], v9), Four_2ToThe23s);
    *(__m128 *)(v10 + 104) = _mm_add_ps(_mm_mul_ps(pRot_4[2], v9), Four_2ToThe23s);
    *(__m128 *)(v10 + 120) = fl4CurTime_4;
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4AlphaVis_4, *pXYZ_4);
    *(_OWORD *)(v10 + 168) = *(_OWORD *)pRadius_4;
    v19 = *(_OWORD *)pCreationTimeStamp_4;
    *(__m128 *)(v10 - 8) = _mm_add_ps(v17, _mm_mul_ps(v16, v16));
    *(__m128 *)(v10 + 8) = v13;
    *(__m128 *)(v10 + 24) = v12;
    *(__m128 *)(v10 + 56) = _mm_add_ps(_mm_mul_ps(v11, v9), Four_2ToThe23s);
    *(_OWORD *)(v10 + 184) = v19;
    if ( pSeq != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pRGB_4, fl4RadVis_4), *pYaw_4);
    else
      v20 = *pYaw_4;
    pSeq_4 -= 4;
    pSeq1 += 4;
    pRot_4 += 3 * (v6 / 0xC);
    v44 = (float *)((char *)v44 + v40);
    pAlpha2 = (__m128 *)((char *)pAlpha2 + v42);
    v37 = (__m128 *)((char *)v37 + v36);
    pGlowAlpha_4 = (__m128 *)((char *)pGlowAlpha_4 + v38);
    pCreationTimeStamp_4 = (float *)((char *)pCreationTimeStamp_4 + v31);
    pRadius_4 = (float *)((char *)pRadius_4 + pRGB2);
    pYaw_4 = (__m128 *)((char *)pYaw_4 + pAlpha_4);
    pRGB_4 += pSeq;
    pXYZ_4 = (__m128 *)((char *)pXYZ_4 + v32);
    *(_OWORD *)(v10 + 200) = *(_OWORD *)v7;
    *(_OWORD *)(v10 + 216) = *((_OWORD *)v7 + 1);
    v21 = *((_OWORD *)v7 + 2);
    v7 = (float *)((char *)v7 + pRGB2_4);
    *(_OWORD *)(v10 + 232) = v21;
    v22 = *(_OWORD *)v43;
    *(__m128 *)(v10 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    *(_OWORD *)(v10 + 248) = v22;
    v10 += 272;
    v43 = (float *)((char *)v43 + v33);
    if ( pSeq_4 <= 0 )
      break;
    v8 = pSeq1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A2820
// Name: void GenerateExtendedData<0,0,1,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  int v7; // eax
  __m128 *v8; // esi
  char *v9; // eax
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 *v12; // edi
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm6
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm5
  __m128 v25; // xmm2
  __int128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // [esp-Ch] [ebp-26Ch]
  __m128 Four_256s_4; // [esp+4h] [ebp-25Ch]
  __m128 fl4RadVis_4; // [esp+14h] [ebp-24Ch]
  __m128 fl4CurTime_4; // [esp+24h] [ebp-23Ch]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+34h] [ebp-22Ch]
  unsigned int v33; // [esp+50h] [ebp-210h]
  unsigned int v34; // [esp+74h] [ebp-1ECh]
  float *v35; // [esp+78h] [ebp-1E8h]
  unsigned int v36; // [esp+7Ch] [ebp-1E4h]
  int v37; // [esp+130h] [ebp-130h]
  int v38; // [esp+170h] [ebp-F0h]
  int v39; // [esp+188h] [ebp-D8h]
  float *v40; // [esp+18Ch] [ebp-D4h]
  __m128 *v41; // [esp+1BCh] [ebp-A4h]
  __m128 *v42; // [esp+1C4h] [ebp-9Ch]
  unsigned int pSeq; // [esp+1C8h] [ebp-98h]
  int pSeq_4; // [esp+1CCh] [ebp-94h]
  __m128 *pRadius; // [esp+1D0h] [ebp-90h]
  unsigned int pRadius_4; // [esp+1D4h] [ebp-8Ch]
  int pRadius_8; // [esp+1D8h] [ebp-88h]
  __m128 *pYaw; // [esp+1DCh] [ebp-84h]
  unsigned int pYaw_4; // [esp+1E0h] [ebp-80h]
  int pYaw_8; // [esp+1E4h] [ebp-7Ch]
  __m128 *pAlpha; // [esp+1E8h] [ebp-78h]
  unsigned int pAlpha_4; // [esp+1ECh] [ebp-74h]
  int pAlpha_8; // [esp+1F0h] [ebp-70h]
  __m128 *pRGB2; // [esp+1F4h] [ebp-6Ch]
  unsigned int pRGB2_4; // [esp+1F8h] [ebp-68h]
  int pRGB2_8; // [esp+1FCh] [ebp-64h]
  __m128 *pRot; // [esp+200h] [ebp-60h]
  unsigned int pRot_4; // [esp+204h] [ebp-5Ch]
  int pRot_8; // [esp+208h] [ebp-58h]
  __m128 *pAlpha2; // [esp+20Ch] [ebp-54h]
  unsigned int pAlpha2_4; // [esp+210h] [ebp-50h]
  __m128 *pAlpha2_8; // [esp+214h] [ebp-4Ch]
  unsigned int pSeq1; // [esp+218h] [ebp-48h]
  int pSeq1_4; // [esp+21Ch] [ebp-44h]
  __m128 *pRGB; // [esp+220h] [ebp-40h]
  unsigned int pRGB_4; // [esp+224h] [ebp-3Ch]
  int pRGB_8; // [esp+228h] [ebp-38h]
  int pXYZ; // [esp+22Ch] [ebp-34h]
  ParticleFullRenderData_Scalar_View **pXYZ_4; // [esp+230h] [ebp-30h]
  __m128 *pXYZ_8; // [esp+234h] [ebp-2Ch]
  bool m_bUseVisibility; // [esp+253h] [ebp-Dh]

  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pRGB_4 != 0 )
    pRGB_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    pRGB_8 = 0;
  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    pSeq1_4 = 0;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v42 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pRGB2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pRGB2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pRGB2_4 != 0 )
    pRGB2_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pRGB2_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  v41 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v40 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v36 = pParticles->m_ParticleAttributes.m_nFloatStrides[23] >> 2;
  v35 = pParticles->m_ParticleAttributes.m_pAttributes[23];
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[22] / 0xC;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[22];
  if ( pAlpha_4 != 0 )
    v7 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[22]
       - (char *)pParticles->m_ParticleAttributes.m_pAttributes[22];
  else
    v7 = 0;
  pAlpha_8 = v7;
  v39 = 48 * pAlpha_4;
  v38 = 48 * pRGB_4;
  v37 = 48 * pSeq1;
  fl4RadVis_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  0);
  pXYZ = pParticles->m_nActiveParticles;
  v34 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps(
                                     (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                                     (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                                     0);
  v33 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v8 = (__m128 *)((char *)pAlpha + v7 + 16);
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  m_bUseVisibility = pVisibilityData->m_bUseVisibility;
  pXYZ_4 = pIndexBuffer + 2;
  pXYZ_8 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  v28 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v9 = pOutbuf + 8;
  v10 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  0);
  v11 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v12 = (__m128 *)((char *)pRGB + pRGB_8 + 16);
  do
  {
    *(pXYZ_4 - 2) = (ParticleFullRenderData_Scalar_View *)(v9 - 8);
    *pXYZ_4 = (ParticleFullRenderData_Scalar_View *)v9;
    *(pXYZ_4 - 1) = (ParticleFullRenderData_Scalar_View *)(v9 - 4);
    pXYZ_4[1] = (ParticleFullRenderData_Scalar_View *)(v9 + 4);
    v13 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v42, *(__m128 *)((char *)v42 + pSeq_4)), v10),
            *(__m128 *)((char *)v42 + pSeq_4));
    v14 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v10),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v10),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    if ( m_bUseVisibility )
    {
      v13 = _mm_mul_ps(v13, Four_256s_4);
      v14 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v14, fl4MaximumCreationTimeToDraw_4)));
    }
    v15 = v12[1];
    v16 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB, v12[-1]), v10), v12[-1]);
    v17 = *(__m128 *)v40;
    *(__m128 *)(v9 + 24) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v12 - pRGB_8), *v12), v10), *v12);
    *(__m128 *)(v9 + 40) = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v12 + 32 - (pRGB_8 + 16)), v15), v10),
                             v15);
    *(__m128 *)(v9 + 56) = _mm_and_ps(_mm_add_ps(_mm_mul_ps(v14, v11), Four_2ToThe23s), _mm_cmplt_ps(v17, fl4CurTime_4));
    *(__m128 *)(v9 + 72) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, pXYZ_8[-1]), v10), pXYZ_8[-1]),
                               v11),
                             Four_2ToThe23s);
    v18 = pXYZ_8[1];
    *(__m128 *)(v9 + 88) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)pXYZ_8 - pSeq1_4), *pXYZ_8), v10),
                                 *pXYZ_8),
                               v11),
                             Four_2ToThe23s);
    v19 = *(__m128 *)((char *)pXYZ_8 + 32 - (pSeq1_4 + 16));
    *(__m128 *)(v9 + 120) = v13;
    *(__m128 *)(v9 + 168) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(*pRGB2, *(__m128 *)((char *)pRGB2 + pRGB2_8)), v10),
                              *(__m128 *)((char *)pRGB2 + pRGB2_8));
    v20 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v10),
            *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v9 + 8) = v16;
    *(__m128 *)(v9 + 104) = _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(v19, v18), v10), v18), v11),
                              Four_2ToThe23s);
    *(__m128 *)(v9 + 136) = _mm_sub_ps(fl4RadVis_4, v17);
    *(__m128 *)(v9 + 184) = v20;
    if ( pAlpha2_4 != 0 )
      v21 = _mm_add_ps(_mm_mul_ps(*pAlpha2, v28), *v41);
    else
      v21 = *v41;
    v22 = v8[-1];
    v23 = _mm_sub_ps(*pAlpha, v22);
    *(__m128 *)(v9 + 152) = _mm_add_ps(v21, Four_2ToThe23s);
    v24 = _mm_add_ps(_mm_mul_ps(v23, v10), v22);
    pXYZ -= 4;
    pXYZ_4 += 4;
    v25 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v8 + 32 - (pAlpha_8 + 16)), v8[1]), v10), v8[1]);
    v26 = *(_OWORD *)v35;
    pAlpha = (__m128 *)((char *)pAlpha + v39);
    v35 += 4 * v36;
    pRGB = (__m128 *)((char *)pRGB + v38);
    v12 = (__m128 *)((char *)v12 + v38);
    pRot += pRot_4;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v37);
    pXYZ_8 = (__m128 *)((char *)pXYZ_8 + v37);
    pRadius += pRadius_4;
    v41 = (__m128 *)((char *)v41 + v34);
    v40 = (float *)((char *)v40 + v33);
    v27 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v8 - pAlpha_8), *v8), v10), *v8);
    v8 = (__m128 *)((char *)v8 + v39);
    pYaw += pYaw_4;
    v42 += pSeq;
    pRGB2 += pRGB2_4;
    pAlpha2 += pAlpha2_4;
    *(__m128 *)(v9 + 200) = v24;
    *(__m128 *)(v9 + 216) = v27;
    *(__m128 *)(v9 + 232) = v25;
    *(_OWORD *)(v9 + 248) = v26;
    v9 += 272;
  }
  while ( pXYZ > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102A2F00
// Name: void GenerateExtendedData<0,0,0,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 m_fl4CurTime; // xmm4
  float *v7; // esi
  __m128 v8; // xmm7
  __m128 v9; // xmm5
  __m128 v10; // xmm6
  unsigned int v11; // edi
  unsigned int v12; // eax
  ParticleFullRenderData_Scalar_View **v13; // edx
  int v14; // ecx
  __m128 v15; // xmm2
  char *v16; // eax
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __int128 v19; // xmm0
  __m128 v20; // xmm0
  __int128 v21; // xmm0
  __m128 *pAlpha; // [esp+8h] [ebp-88h]
  float *pGlowAlpha; // [esp+3Ch] [ebp-54h]
  unsigned int pGlowAlpha_4; // [esp+40h] [ebp-50h]
  __m128 *pCreationTimeStamp; // [esp+44h] [ebp-4Ch]
  unsigned int pCreationTimeStamp_4; // [esp+48h] [ebp-48h]
  float *pRot; // [esp+4Ch] [ebp-44h]
  unsigned int pRot_4; // [esp+50h] [ebp-40h]
  float *pRadius; // [esp+54h] [ebp-3Ch]
  unsigned int pRadius_4; // [esp+58h] [ebp-38h]
  float *pYaw; // [esp+5Ch] [ebp-34h]
  unsigned int pYaw_4; // [esp+60h] [ebp-30h]
  float *pXYZ; // [esp+64h] [ebp-2Ch]
  unsigned int pXYZ_4; // [esp+68h] [ebp-28h]
  __m128 *pRGB; // [esp+6Ch] [ebp-24h]
  unsigned int pRGB_4; // [esp+70h] [ebp-20h]
  __m128 *pAlpha2; // [esp+74h] [ebp-1Ch]
  unsigned int pAlpha2_4; // [esp+78h] [ebp-18h]
  __m128 *pSeq; // [esp+7Ch] [ebp-14h]
  unsigned int pSeq_4; // [esp+80h] [ebp-10h]
  __m128 *pSeq1; // [esp+84h] [ebp-Ch]
  unsigned int pSeq1_4; // [esp+88h] [ebp-8h]
  int nParticles; // [esp+8Ch] [ebp-4h]
  CParticleVisibilityData *pVisibilityDataa; // [esp+B0h] [ebp+20h]
  bool bUseVis_3; // [esp+B7h] [ebp+27h]

  pXYZ = pParticles->m_ParticleAttributes.m_pAttributes[0];
  pXYZ_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  pRadius = pParticles->m_ParticleAttributes.m_pAttributes[3];
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pYaw = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pSeq_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2;
  pSeq1_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pSeq1 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  m_fl4CurTime = pParticles->m_fl4CurTime;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  pCreationTimeStamp_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2;
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  pRot = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pGlowAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[23] >> 2;
  pSeq = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pGlowAlpha = pParticles->m_ParticleAttributes.m_pAttributes[23];
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  v7 = pParticles->m_ParticleAttributes.m_pAttributes[22];
  v8 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v9 = _mm_shuffle_ps(
         (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
         (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
         0);
  v10 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          0);
  v11 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  v12 = pParticles->m_ParticleAttributes.m_nFloatStrides[22] / 0xC;
  nParticles = pParticles->m_nActiveParticles;
  bUseVis_3 = pVisibilityData->m_bUseVisibility;
  v13 = pIndexBuffer + 2;
  v14 = 48 * v12;
  v15 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  pVisibilityDataa = (CParticleVisibilityData *)(pIndexBuffer + 2);
  v16 = pOutbuf + 8;
  while ( 1 )
  {
    *(v13 - 2) = (ParticleFullRenderData_Scalar_View *)(v16 - 8);
    *(v13 - 1) = (ParticleFullRenderData_Scalar_View *)(v16 - 4);
    *v13 = (ParticleFullRenderData_Scalar_View *)v16;
    v13[1] = (ParticleFullRenderData_Scalar_View *)(v16 + 4);
    v17 = _mm_mul_ps(*pAlpha, *pAlpha2);
    v18 = *(__m128 *)pRadius;
    if ( bUseVis_3 )
    {
      v17 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v17, v9)));
      v18 = _mm_mul_ps(v18, v10);
    }
    *(_OWORD *)(v16 + 8) = *(_OWORD *)pXYZ;
    *(_OWORD *)(v16 + 24) = *((_OWORD *)pXYZ + 1);
    *(_OWORD *)(v16 + 40) = *((_OWORD *)pXYZ + 2);
    *(__m128 *)(v16 + 56) = _mm_add_ps(_mm_mul_ps(v17, v15), Four_2ToThe23s);
    *(__m128 *)(v16 + 72) = _mm_add_ps(_mm_mul_ps(*pRGB, v15), Four_2ToThe23s);
    *(__m128 *)(v16 + 88) = _mm_add_ps(_mm_mul_ps(pRGB[1], v15), Four_2ToThe23s);
    *(__m128 *)(v16 + 104) = _mm_add_ps(_mm_mul_ps(pRGB[2], v15), Four_2ToThe23s);
    *(__m128 *)(v16 + 136) = _mm_sub_ps(m_fl4CurTime, *pCreationTimeStamp);
    *(_OWORD *)(v16 + 168) = *(_OWORD *)pRot;
    v19 = *(_OWORD *)pYaw;
    *(__m128 *)(v16 + 120) = v18;
    *(_OWORD *)(v16 + 184) = v19;
    if ( pSeq1_4 != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pSeq1, v8), *pSeq);
    else
      v20 = *pSeq;
    *(__m128 *)(v16 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    *(_OWORD *)(v16 + 200) = *(_OWORD *)v7;
    *(_OWORD *)(v16 + 216) = *((_OWORD *)v7 + 1);
    *(_OWORD *)(v16 + 232) = *((_OWORD *)v7 + 2);
    v21 = *(_OWORD *)pGlowAlpha;
    nParticles -= 4;
    pGlowAlpha += 4 * pGlowAlpha_4;
    pXYZ += 12 * pXYZ_4;
    pAlpha += v11;
    pAlpha2 += pAlpha2_4;
    pRadius += 4 * pRadius_4;
    pRGB += 3 * pRGB_4;
    pYaw += 4 * pYaw_4;
    pRot += 4 * pRot_4;
    pSeq += pSeq_4;
    pSeq1 += pSeq1_4;
    pVisibilityDataa = (CParticleVisibilityData *)((char *)pVisibilityDataa + 16);
    pCreationTimeStamp += pCreationTimeStamp_4;
    *(_OWORD *)(v16 + 248) = v21;
    v7 = (float *)((char *)v7 + v14);
    v16 += 272;
    if ( nParticles <= 0 )
      break;
    v13 = (ParticleFullRenderData_Scalar_View **)pVisibilityDataa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A3270
// Name: void GenerateExtendedData<1,0,1,struct ParticleRenderDataWithNormal_SIMD_View,0,1,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,1,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  __m128 v7; // xmm0
  __m128 *v8; // edi
  char *v9; // eax
  __m128 *v10; // edx
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm6
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __int128 v26; // xmm1
  __m128 v27; // [esp-Ch] [ebp-24Ch]
  __m128 EyePos_4; // [esp+4h] [ebp-23Ch]
  __m128 EyePos_20; // [esp+14h] [ebp-22Ch]
  __m128 EyePos_36; // [esp+24h] [ebp-21Ch]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-20Ch]
  __m128 Four_256s_4; // [esp+44h] [ebp-1FCh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-1ECh]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-1DCh]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+74h] [ebp-1CCh]
  __m128 fl4AlphaScale_4; // [esp+84h] [ebp-1BCh]
  __m128 fl4FinalRadius_4; // [esp+94h] [ebp-1ACh]
  float *fl4FinalAlpha_12; // [esp+ACh] [ebp-194h]
  float *v39; // [esp+C8h] [ebp-178h]
  int v40; // [esp+E8h] [ebp-158h]
  int v41; // [esp+F0h] [ebp-150h]
  unsigned int v42; // [esp+10Ch] [ebp-134h]
  unsigned int v43; // [esp+110h] [ebp-130h]
  unsigned int v44; // [esp+130h] [ebp-110h]
  __m128 *v45; // [esp+1C4h] [ebp-7Ch]
  __m128 *v46; // [esp+1CCh] [ebp-74h]
  unsigned int pSeq; // [esp+1D0h] [ebp-70h]
  int pSeq_4; // [esp+1D4h] [ebp-6Ch]
  __m128 *pRadius; // [esp+1D8h] [ebp-68h]
  unsigned int pRadius_4; // [esp+1DCh] [ebp-64h]
  int pRadius_8; // [esp+1E0h] [ebp-60h]
  __m128 *pYaw; // [esp+1E4h] [ebp-5Ch]
  unsigned int pYaw_4; // [esp+1E8h] [ebp-58h]
  int pYaw_8; // [esp+1ECh] [ebp-54h]
  float *pAlpha; // [esp+1F0h] [ebp-50h]
  unsigned int pAlpha_4; // [esp+1F4h] [ebp-4Ch]
  int pAlpha_8; // [esp+1F8h] [ebp-48h]
  __m128 *pRot; // [esp+1FCh] [ebp-44h]
  unsigned int pRot_4; // [esp+200h] [ebp-40h]
  int pRot_8; // [esp+204h] [ebp-3Ch]
  __m128 *pAlpha2; // [esp+208h] [ebp-38h]
  unsigned int pAlpha2_4; // [esp+20Ch] [ebp-34h]
  __m128 *pAlpha2_8; // [esp+210h] [ebp-30h]
  unsigned int pSeq1; // [esp+214h] [ebp-2Ch]
  int pSeq1_4; // [esp+218h] [ebp-28h]
  int pRGB; // [esp+21Ch] [ebp-24h]
  __m128 *pRGB_4; // [esp+220h] [ebp-20h]
  unsigned int pRGB_8; // [esp+224h] [ebp-1Ch]
  int nParticles; // [esp+228h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pXYZ; // [esp+22Ch] [ebp-14h]
  bool pXYZ_7; // [esp+233h] [ebp-Dh]

  pRGB_8 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pRGB_8 != 0 )
    nParticles = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
               - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    nParticles = 0;
  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    pSeq1_4 = 0;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v46 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pAlpha = pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pAlpha_4 != 0 )
    pAlpha_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
             - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pAlpha_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  v45 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v39 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v42 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[21] / 0xC);
  v40 = 48 * pRGB_8;
  v27 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4AlphaVis_4 = _mm_shuffle_ps(
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    0);
  fl4FinalAlpha_12 = pParticles->m_ParticleAttributes.m_pAttributes[21];
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  pRGB = pParticles->m_nActiveParticles;
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  pXYZ_7 = pVisibilityData->m_bUseVisibility;
  v41 = 48 * pSeq1;
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v7 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v44 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v43 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v8 = (__m128 *)((char *)pRGB_4 + nParticles + 16);
  pXYZ = pIndexBuffer + 2;
  v9 = pOutbuf + 8;
  v10 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  do
  {
    *(pXYZ - 2) = (ParticleFullRenderData_Scalar_View *)(v9 - 8);
    *pXYZ = (ParticleFullRenderData_Scalar_View *)v9;
    *(pXYZ - 1) = (ParticleFullRenderData_Scalar_View *)(v9 - 4);
    pXYZ[1] = (ParticleFullRenderData_Scalar_View *)(v9 + 4);
    v11 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v7),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v7),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    v12 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v46, *(__m128 *)((char *)v46 + pSeq_4)), v7),
            *(__m128 *)((char *)v46 + pSeq_4));
    fl4FinalRadius_4 = v11;
    fl4AlphaScale_4 = v12;
    if ( pXYZ_7 )
    {
      fl4FinalRadius_4 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, Four_256s_4)));
      fl4AlphaScale_4 = _mm_mul_ps(v12, EyePos_36);
    }
    v13 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB_4, v8[-1]), v7), v8[-1]);
    v14 = _mm_sub_ps(*(__m128 *)((char *)v8 - nParticles), *v8);
    v15 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v8 + 32 - (nParticles + 16)), v8[1]), v7), v8[1]);
    v16 = _mm_sub_ps(v13, v27);
    *(__m128 *)(v9 + 8) = v13;
    v17 = _mm_add_ps(_mm_mul_ps(v14, v7), *v8);
    v18 = _mm_sub_ps(v15, EyePos_20);
    v19 = _mm_sub_ps(v17, EyePos_4);
    v20 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v18, v18), _mm_mul_ps(v19, v19)), _mm_mul_ps(v16, v16));
    v21 = *(__m128 *)v39;
    *(__m128 *)(v9 + 40) = v15;
    *(__m128 *)(v9 + 24) = v17;
    *(__m128 *)(v9 + 56) = _mm_and_ps(
                             _mm_add_ps(_mm_mul_ps(fl4FinalRadius_4, fl4MaximumCreationTimeToDraw_4), Four_2ToThe23s),
                             _mm_cmplt_ps(v21, fl4CurTime_4));
    *(__m128 *)(v9 + 72) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, v10[-1]), v7), v10[-1]),
                               fl4MaximumCreationTimeToDraw_4),
                             Four_2ToThe23s);
    v22 = v10[1];
    *(__m128 *)(v9 + 88) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v10 - pSeq1_4), *v10), v7), *v10),
                               fl4MaximumCreationTimeToDraw_4),
                             Four_2ToThe23s);
    v23 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v10 + 32 - (pSeq1_4 + 16)), v22), v7), v22);
    *(__m128 *)(v9 + 120) = fl4AlphaScale_4;
    v24 = *(__m128 *)pAlpha;
    *(__m128 *)(v9 - 8) = v20;
    *(__m128 *)(v9 + 104) = _mm_add_ps(_mm_mul_ps(v23, fl4MaximumCreationTimeToDraw_4), Four_2ToThe23s);
    *(__m128 *)(v9 + 136) = _mm_sub_ps(fl4AlphaVis_4, v21);
    *(__m128 *)(v9 + 168) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(v24, *(__m128 *)((char *)pAlpha + pAlpha_8)), v7),
                              *(__m128 *)((char *)pAlpha + pAlpha_8));
    *(__m128 *)(v9 + 184) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v7),
                              *(__m128 *)((char *)pRadius + pRadius_8));
    if ( pAlpha2_4 != 0 )
      v25 = _mm_add_ps(_mm_mul_ps(*pAlpha2, fl4RadVis_4), *v45);
    else
      v25 = *v45;
    *(__m128 *)(v9 + 152) = _mm_add_ps(v25, Four_2ToThe23s);
    *(_OWORD *)(v9 + 200) = *(_OWORD *)fl4FinalAlpha_12;
    *(_OWORD *)(v9 + 216) = *((_OWORD *)fl4FinalAlpha_12 + 1);
    v26 = *((_OWORD *)fl4FinalAlpha_12 + 2);
    pRGB -= 4;
    fl4FinalAlpha_12 = (float *)((char *)fl4FinalAlpha_12 + v42);
    pRGB_4 = (__m128 *)((char *)pRGB_4 + v40);
    v8 = (__m128 *)((char *)v8 + v40);
    pYaw += pYaw_4;
    pRot += pRot_4;
    v46 += pSeq;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v41);
    pXYZ += 4;
    v10 = (__m128 *)((char *)v10 + v41);
    pRadius += pRadius_4;
    pAlpha += 4 * pAlpha_4;
    v45 = (__m128 *)((char *)v45 + v44);
    pAlpha2 += pAlpha2_4;
    v39 = (float *)((char *)v39 + v43);
    *(_OWORD *)(v9 + 232) = v26;
    v9 += 256;
  }
  while ( pRGB > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102A38E0
// Name: void GenerateExtendedData<1,0,0,struct ParticleRenderDataWithNormal_SIMD_View,0,1,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,0,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  unsigned int v6; // kr04_4
  float *v7; // edx
  ParticleFullRenderData_Scalar_View **v8; // ecx
  __m128 v9; // xmm4
  char *v10; // eax
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __int128 v19; // xmm1
  __m128 v20; // xmm1
  __int128 v21; // xmm0
  __m128 v22; // [esp-Ch] [ebp-11Ch]
  __m128 EyePos_4; // [esp+4h] [ebp-10Ch]
  __m128 EyePos_20; // [esp+14h] [ebp-FCh]
  __m128 EyePos_36; // [esp+24h] [ebp-ECh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-DCh]
  __m128 Four_256s_4; // [esp+44h] [ebp-CCh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-BCh]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-ACh]
  unsigned int fl4FinalRadius_12; // [esp+7Ch] [ebp-94h]
  unsigned int v31; // [esp+80h] [ebp-90h]
  unsigned int v32; // [esp+84h] [ebp-8Ch]
  unsigned int v33; // [esp+88h] [ebp-88h]
  unsigned int v34; // [esp+8Ch] [ebp-84h]
  unsigned int v35; // [esp+90h] [ebp-80h]
  __m128 *v36; // [esp+94h] [ebp-7Ch]
  unsigned int v37; // [esp+9Ch] [ebp-74h]
  __m128 *pAlpha2; // [esp+A0h] [ebp-70h]
  unsigned int pAlpha; // [esp+ACh] [ebp-64h]
  unsigned int pNormal; // [esp+B4h] [ebp-5Ch]
  float *pNormal_4; // [esp+B8h] [ebp-58h]
  __m128 *v42; // [esp+C0h] [ebp-50h]
  float *pXYZ_4; // [esp+C8h] [ebp-48h]
  __m128 *pCreationTimeStamp_4; // [esp+D0h] [ebp-40h]
  float *pRot_4; // [esp+D8h] [ebp-38h]
  __m128 *pRadius_4; // [esp+E0h] [ebp-30h]
  __m128 *pYaw_4; // [esp+E8h] [ebp-28h]
  __m128 *pRGB_4; // [esp+F0h] [ebp-20h]
  unsigned int pSeq; // [esp+F4h] [ebp-1Ch]
  int pSeq_4; // [esp+F8h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pSeq1; // [esp+FCh] [ebp-14h]
  bool pSeq1_7; // [esp+103h] [ebp-Dh]

  pNormal_4 = pParticles->m_ParticleAttributes.m_pAttributes[0];
  v6 = pParticles->m_ParticleAttributes.m_nFloatStrides[6];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pCreationTimeStamp_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  pRot_4 = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pRadius_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v36 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  fl4AlphaVis_4 = pParticles->m_fl4CurTime;
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pXYZ_4 = pParticles->m_ParticleAttributes.m_pAttributes[4];
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  pYaw_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  v22 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  v42 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  pSeq_4 = pParticles->m_nActiveParticles;
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  v7 = pParticles->m_ParticleAttributes.m_pAttributes[21];
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  v37 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[21] / 0xC);
  v35 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  fl4FinalRadius_12 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v32 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2);
  v33 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2);
  v31 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  pNormal = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  pSeq1_7 = pVisibilityData->m_bUseVisibility;
  pAlpha = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v8 = pIndexBuffer + 2;
  v9 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v34 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  pSeq1 = pIndexBuffer + 2;
  v10 = pOutbuf + 8;
  while ( 1 )
  {
    *(v8 - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *(v8 - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    *v8 = (ParticleFullRenderData_Scalar_View *)v10;
    v8[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v11 = _mm_mul_ps(*pAlpha2, *v36);
    fl4CurTime_4 = *pCreationTimeStamp_4;
    if ( pSeq1_7 )
    {
      v11 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, Four_256s_4)));
      fl4CurTime_4 = _mm_mul_ps(*pCreationTimeStamp_4, EyePos_36);
    }
    v12 = *(__m128 *)(pNormal_4 + 4);
    v13 = *(__m128 *)pNormal_4;
    v14 = _mm_sub_ps(*(__m128 *)(pNormal_4 + 8), EyePos_20);
    v15 = _mm_sub_ps(v12, EyePos_4);
    v16 = _mm_sub_ps(*(__m128 *)pNormal_4, v22);
    v17 = _mm_add_ps(_mm_mul_ps(v14, v14), _mm_mul_ps(v15, v15));
    v18 = _mm_mul_ps(*pRadius_4, v9);
    *(_OWORD *)(v10 + 40) = *((_OWORD *)pNormal_4 + 2);
    *(__m128 *)(v10 + 72) = _mm_add_ps(v18, Four_2ToThe23s);
    *(__m128 *)(v10 + 88) = _mm_add_ps(_mm_mul_ps(pRadius_4[1], v9), Four_2ToThe23s);
    *(__m128 *)(v10 + 104) = _mm_add_ps(_mm_mul_ps(pRadius_4[2], v9), Four_2ToThe23s);
    *(__m128 *)(v10 + 120) = fl4CurTime_4;
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4AlphaVis_4, *v42);
    *(_OWORD *)(v10 + 168) = *(_OWORD *)pXYZ_4;
    v19 = *(_OWORD *)pRot_4;
    *(__m128 *)(v10 - 8) = _mm_add_ps(v17, _mm_mul_ps(v16, v16));
    *(__m128 *)(v10 + 8) = v13;
    *(__m128 *)(v10 + 24) = v12;
    *(__m128 *)(v10 + 56) = _mm_add_ps(_mm_mul_ps(v11, v9), Four_2ToThe23s);
    *(_OWORD *)(v10 + 184) = v19;
    if ( pSeq != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pRGB_4, fl4RadVis_4), *pYaw_4);
    else
      v20 = *pYaw_4;
    pSeq_4 -= 4;
    pSeq1 += 4;
    pRadius_4 += 3 * (v6 / 0xC);
    pNormal_4 = (float *)((char *)pNormal_4 + v35);
    pAlpha2 = (__m128 *)((char *)pAlpha2 + v34);
    v36 = (__m128 *)((char *)v36 + pNormal);
    pCreationTimeStamp_4 = (__m128 *)((char *)pCreationTimeStamp_4 + fl4FinalRadius_12);
    pRot_4 = (float *)((char *)pRot_4 + v32);
    pXYZ_4 = (float *)((char *)pXYZ_4 + v33);
    pYaw_4 = (__m128 *)((char *)pYaw_4 + v31);
    pRGB_4 += pSeq;
    v42 = (__m128 *)((char *)v42 + pAlpha);
    *(_OWORD *)(v10 + 200) = *(_OWORD *)v7;
    *(_OWORD *)(v10 + 216) = *((_OWORD *)v7 + 1);
    v21 = *((_OWORD *)v7 + 2);
    v7 = (float *)((char *)v7 + v37);
    *(__m128 *)(v10 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    *(_OWORD *)(v10 + 232) = v21;
    v10 += 256;
    if ( pSeq_4 <= 0 )
      break;
    v8 = pSeq1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A3CC0
// Name: void GenerateExtendedData<0,0,1,struct ParticleRenderDataWithNormal_SIMD_View,0,1,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,1,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  __m128 v7; // xmm0
  __m128 v8; // xmm3
  __m128 *v9; // edi
  char *v10; // eax
  __m128 *v11; // edx
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm7
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm6
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __int128 v21; // xmm1
  __m128 v22; // [esp-Ch] [ebp-1ECh]
  __m128 Four_256s_4; // [esp+4h] [ebp-1DCh]
  __m128 fl4RadVis_4; // [esp+14h] [ebp-1CCh]
  __m128 fl4CurTime_4; // [esp+24h] [ebp-1BCh]
  __m128 fl4AlphaVis_4; // [esp+34h] [ebp-1ACh]
  float *fl4MaximumCreationTimeToDraw_12; // [esp+4Ch] [ebp-194h]
  int v28; // [esp+D0h] [ebp-110h]
  unsigned int v29; // [esp+F0h] [ebp-F0h]
  unsigned int v30; // [esp+110h] [ebp-D0h]
  int v31; // [esp+11Ch] [ebp-C4h]
  unsigned int v32; // [esp+140h] [ebp-A0h]
  float *v33; // [esp+158h] [ebp-88h]
  __m128 *pCreationTimeStamp; // [esp+164h] [ebp-7Ch]
  __m128 *v35; // [esp+16Ch] [ebp-74h]
  unsigned int pSeq; // [esp+170h] [ebp-70h]
  int pSeq_4; // [esp+174h] [ebp-6Ch]
  __m128 *pRadius; // [esp+178h] [ebp-68h]
  unsigned int pRadius_4; // [esp+17Ch] [ebp-64h]
  int pRadius_8; // [esp+180h] [ebp-60h]
  __m128 *pYaw; // [esp+184h] [ebp-5Ch]
  unsigned int pYaw_4; // [esp+188h] [ebp-58h]
  int pYaw_8; // [esp+18Ch] [ebp-54h]
  __m128 *pAlpha; // [esp+190h] [ebp-50h]
  unsigned int pAlpha_4; // [esp+194h] [ebp-4Ch]
  int pAlpha_8; // [esp+198h] [ebp-48h]
  __m128 *pRot; // [esp+19Ch] [ebp-44h]
  unsigned int pRot_4; // [esp+1A0h] [ebp-40h]
  int pRot_8; // [esp+1A4h] [ebp-3Ch]
  __m128 *pAlpha2; // [esp+1A8h] [ebp-38h]
  unsigned int pAlpha2_4; // [esp+1ACh] [ebp-34h]
  __m128 *pAlpha2_8; // [esp+1B0h] [ebp-30h]
  unsigned int pSeq1; // [esp+1B4h] [ebp-2Ch]
  int pSeq1_4; // [esp+1B8h] [ebp-28h]
  int pRGB; // [esp+1BCh] [ebp-24h]
  __m128 *pRGB_4; // [esp+1C0h] [ebp-20h]
  unsigned int pRGB_8; // [esp+1C4h] [ebp-1Ch]
  int nParticles; // [esp+1C8h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pXYZ; // [esp+1CCh] [ebp-14h]
  bool pXYZ_7; // [esp+1D3h] [ebp-Dh]

  pRGB_8 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pRGB_8 != 0 )
    nParticles = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
               - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    nParticles = 0;
  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    pSeq1_4 = 0;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v35 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pAlpha_4 != 0 )
    pAlpha_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
             - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pAlpha_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v33 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v32 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[21] / 0xC);
  v31 = 48 * pRGB_8;
  v28 = 48 * pSeq1;
  fl4RadVis_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  0);
  fl4MaximumCreationTimeToDraw_12 = pParticles->m_ParticleAttributes.m_pAttributes[21];
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                   (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                   0);
  fl4AlphaVis_4 = _mm_shuffle_ps(
                    (__m128)LODWORD(pParticles->m_flPrevSimTime),
                    (__m128)LODWORD(pParticles->m_flPrevSimTime),
                    0);
  pRGB = pParticles->m_nActiveParticles;
  pXYZ_7 = pVisibilityData->m_bUseVisibility;
  v22 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v7 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  0);
  v8 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v30 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v29 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v9 = (__m128 *)((char *)pRGB_4 + nParticles + 16);
  pXYZ = pIndexBuffer + 2;
  v10 = pOutbuf + 8;
  v11 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  do
  {
    *(pXYZ - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *pXYZ = (ParticleFullRenderData_Scalar_View *)v10;
    *(pXYZ - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    pXYZ[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v12 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v35, *(__m128 *)((char *)v35 + pSeq_4)), v7),
            *(__m128 *)((char *)v35 + pSeq_4));
    v13 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v7),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v7),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    if ( pXYZ_7 )
    {
      v12 = _mm_mul_ps(v12, Four_256s_4);
      v13 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v13, fl4CurTime_4)));
    }
    v14 = v9[1];
    v15 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB_4, v9[-1]), v7), v9[-1]);
    *(__m128 *)(v10 + 24) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 - nParticles), *v9), v7), *v9);
    v16 = *(__m128 *)v33;
    *(__m128 *)(v10 + 40) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 + 32 - (nParticles + 16)), v14), v7),
                              v14);
    *(__m128 *)(v10 + 56) = _mm_and_ps(
                              _mm_add_ps(_mm_mul_ps(v13, v8), Four_2ToThe23s),
                              _mm_cmplt_ps(v16, fl4AlphaVis_4));
    *(__m128 *)(v10 + 72) = _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, v11[-1]), v7), v11[-1]), v8),
                              Four_2ToThe23s);
    v17 = v11[1];
    *(__m128 *)(v10 + 88) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v11 - pSeq1_4), *v11), v7), *v11),
                                v8),
                              Four_2ToThe23s);
    v18 = *(__m128 *)((char *)v11 + 32 - (pSeq1_4 + 16));
    *(__m128 *)(v10 + 120) = v12;
    *(__m128 *)(v10 + 168) = _mm_add_ps(
                               _mm_mul_ps(_mm_sub_ps(*pAlpha, *(__m128 *)((char *)pAlpha + pAlpha_8)), v7),
                               *(__m128 *)((char *)pAlpha + pAlpha_8));
    v19 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v7),
            *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v10 + 8) = v15;
    *(__m128 *)(v10 + 104) = _mm_add_ps(
                               _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(v18, v17), v7), v17), v8),
                               Four_2ToThe23s);
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4RadVis_4, v16);
    *(__m128 *)(v10 + 184) = v19;
    if ( pAlpha2_4 != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pAlpha2, v22), *pCreationTimeStamp);
    else
      v20 = *pCreationTimeStamp;
    *(__m128 *)(v10 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    *(_OWORD *)(v10 + 200) = *(_OWORD *)fl4MaximumCreationTimeToDraw_12;
    *(_OWORD *)(v10 + 216) = *((_OWORD *)fl4MaximumCreationTimeToDraw_12 + 1);
    v21 = *((_OWORD *)fl4MaximumCreationTimeToDraw_12 + 2);
    pRGB -= 4;
    fl4MaximumCreationTimeToDraw_12 = (float *)((char *)fl4MaximumCreationTimeToDraw_12 + v32);
    pRGB_4 = (__m128 *)((char *)pRGB_4 + v31);
    v9 = (__m128 *)((char *)v9 + v31);
    pYaw += pYaw_4;
    pRot += pRot_4;
    v35 += pSeq;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v28);
    pXYZ += 4;
    v11 = (__m128 *)((char *)v11 + v28);
    pRadius += pRadius_4;
    pAlpha += pAlpha_4;
    pCreationTimeStamp = (__m128 *)((char *)pCreationTimeStamp + v30);
    pAlpha2 += pAlpha2_4;
    v33 = (float *)((char *)v33 + v29);
    *(_OWORD *)(v10 + 232) = v21;
    v10 += 256;
  }
  while ( pRGB > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102A4280
// Name: void GenerateExtendedData<0,0,0,struct ParticleRenderDataWithNormal_SIMD_View,0,1,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,0,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 m_fl4CurTime; // xmm4
  float *v7; // esi
  __m128 v8; // xmm7
  unsigned int v9; // edi
  int m_nActiveParticles; // edx
  __m128 v11; // xmm5
  unsigned int v12; // eax
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  int v15; // ecx
  ParticleFullRenderData_Scalar_View **v16; // edx
  char *v17; // eax
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __int128 v20; // xmm0
  __m128 v21; // xmm0
  __m128 *pAlpha; // [esp+8h] [ebp-7Ch]
  float *pXYZ; // [esp+10h] [ebp-74h]
  unsigned int pXYZ_4; // [esp+14h] [ebp-70h]
  __m128 *pCreationTimeStamp; // [esp+18h] [ebp-6Ch]
  unsigned int pCreationTimeStamp_4; // [esp+1Ch] [ebp-68h]
  float *pRot; // [esp+20h] [ebp-64h]
  unsigned int pRot_4; // [esp+24h] [ebp-60h]
  float *pYaw; // [esp+28h] [ebp-5Ch]
  unsigned int pYaw_4; // [esp+2Ch] [ebp-58h]
  __m128 *pRGB; // [esp+30h] [ebp-54h]
  unsigned int pRGB_4; // [esp+34h] [ebp-50h]
  float *pRadius; // [esp+38h] [ebp-4Ch]
  unsigned int pRadius_4; // [esp+3Ch] [ebp-48h]
  __m128 *pAlpha2; // [esp+40h] [ebp-44h]
  unsigned int pAlpha2_4; // [esp+44h] [ebp-40h]
  __m128 *pSeq1; // [esp+48h] [ebp-3Ch]
  unsigned int pSeq1_4; // [esp+4Ch] [ebp-38h]
  __m128 *pSeq; // [esp+50h] [ebp-34h]
  unsigned int pSeq_4; // [esp+54h] [ebp-30h]
  int nParticles; // [esp+80h] [ebp-4h]
  CParticleVisibilityData *pVisibilityDataa; // [esp+A4h] [ebp+20h]
  bool bUseVis_3; // [esp+ABh] [ebp+27h]

  pXYZ = pParticles->m_ParticleAttributes.m_pAttributes[0];
  pXYZ_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  pRadius = pParticles->m_ParticleAttributes.m_pAttributes[3];
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pYaw = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pSeq_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2;
  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  m_fl4CurTime = pParticles->m_fl4CurTime;
  pSeq1_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  pSeq1 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  pRot = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pCreationTimeStamp_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2;
  pSeq = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  v7 = pParticles->m_ParticleAttributes.m_pAttributes[21];
  v8 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v9 = pParticles->m_ParticleAttributes.m_nFloatStrides[7];
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v11 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
          (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
          0);
  v12 = pParticles->m_ParticleAttributes.m_nFloatStrides[21] / 0xC;
  bUseVis_3 = pVisibilityData->m_bUseVisibility;
  v13 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          0);
  nParticles = m_nActiveParticles;
  v14 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v15 = 48 * v12;
  v16 = pIndexBuffer + 2;
  pVisibilityDataa = (CParticleVisibilityData *)(pIndexBuffer + 2);
  v17 = pOutbuf + 8;
  while ( 1 )
  {
    *(v16 - 2) = (ParticleFullRenderData_Scalar_View *)(v17 - 8);
    *(v16 - 1) = (ParticleFullRenderData_Scalar_View *)(v17 - 4);
    *v16 = (ParticleFullRenderData_Scalar_View *)v17;
    v16[1] = (ParticleFullRenderData_Scalar_View *)(v17 + 4);
    v18 = _mm_mul_ps(*pAlpha, *pAlpha2);
    v19 = *(__m128 *)pRadius;
    if ( bUseVis_3 )
    {
      v18 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v18, v11)));
      v19 = _mm_mul_ps(v19, v13);
    }
    *(_OWORD *)(v17 + 8) = *(_OWORD *)pXYZ;
    *(_OWORD *)(v17 + 24) = *((_OWORD *)pXYZ + 1);
    *(_OWORD *)(v17 + 40) = *((_OWORD *)pXYZ + 2);
    *(__m128 *)(v17 + 56) = _mm_add_ps(_mm_mul_ps(v18, v14), Four_2ToThe23s);
    *(__m128 *)(v17 + 72) = _mm_add_ps(_mm_mul_ps(*pRGB, v14), Four_2ToThe23s);
    *(__m128 *)(v17 + 88) = _mm_add_ps(_mm_mul_ps(pRGB[1], v14), Four_2ToThe23s);
    *(__m128 *)(v17 + 104) = _mm_add_ps(_mm_mul_ps(pRGB[2], v14), Four_2ToThe23s);
    *(__m128 *)(v17 + 136) = _mm_sub_ps(m_fl4CurTime, *pCreationTimeStamp);
    *(_OWORD *)(v17 + 168) = *(_OWORD *)pRot;
    v20 = *(_OWORD *)pYaw;
    *(__m128 *)(v17 + 120) = v19;
    *(_OWORD *)(v17 + 184) = v20;
    if ( pSeq1_4 != 0 )
      v21 = _mm_add_ps(_mm_mul_ps(*pSeq1, v8), *pSeq);
    else
      v21 = *pSeq;
    nParticles -= 4;
    pXYZ += 12 * pXYZ_4;
    pAlpha += v9 >> 2;
    pAlpha2 += pAlpha2_4;
    pRadius += 4 * pRadius_4;
    pRGB += 3 * pRGB_4;
    pYaw += 4 * pYaw_4;
    pRot += 4 * pRot_4;
    pSeq += pSeq_4;
    pSeq1 += pSeq1_4;
    pVisibilityDataa = (CParticleVisibilityData *)((char *)pVisibilityDataa + 16);
    pCreationTimeStamp += pCreationTimeStamp_4;
    *(__m128 *)(v17 + 152) = _mm_add_ps(v21, Four_2ToThe23s);
    *(_OWORD *)(v17 + 200) = *(_OWORD *)v7;
    *(_OWORD *)(v17 + 216) = *((_OWORD *)v7 + 1);
    *(_OWORD *)(v17 + 232) = *((_OWORD *)v7 + 2);
    v7 = (float *)((char *)v7 + v15);
    v17 += 256;
    if ( nParticles <= 0 )
      break;
    v16 = (ParticleFullRenderData_Scalar_View **)pVisibilityDataa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4920
// Name: void s_GenerateExtendedData<0,1,struct ParticleFullRenderData_SIMD_View,0,0>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,1,ParticleFullRenderData_SIMD_View,0,0>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,1,ParticleFullRenderData_SIMD_View,0,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,1,ParticleFullRenderData_SIMD_View,0,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x102A49A0
// Name: void s_GenerateExtendedData<0,0,struct ParticleFullRenderData_SIMD_View,0,0>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,0,ParticleFullRenderData_SIMD_View,0,0>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,0,ParticleFullRenderData_SIMD_View,0,0,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles);
  else
    GenerateExtendedData<0,0,0,ParticleFullRenderData_SIMD_View,0,0,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles);
}

//------------------------------------------------------------------------------
// Address: 0x102A4A20
// Name: void s_GenerateExtendedData<0,1,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x102A4AA0
// Name: void s_GenerateExtendedData<0,0,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles);
  else
    GenerateExtendedData<0,0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles);
}

//------------------------------------------------------------------------------
// Address: 0x102A4B20
// Name: void s_GenerateExtendedData<0,1,struct ParticleRenderDataWithNormal_SIMD_View,0,1>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,1,ParticleRenderDataWithNormal_SIMD_View,0,1>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,1,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,1,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x102A4BA0
// Name: void s_GenerateExtendedData<0,0,struct ParticleRenderDataWithNormal_SIMD_View,0,1>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,0,ParticleRenderDataWithNormal_SIMD_View,0,1>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,0,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles);
  else
    GenerateExtendedData<0,0,0,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      (CParticleVisibilityData *)pVisibilityData,
      pParticles);
}

//------------------------------------------------------------------------------
// Address: 0x102A4D60
// Name: public: int CParticleCollection::GenerateSortedIndexList(struct ParticleRenderData_t __near *,class Vector,struct CParticleVisibilityData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleCollection::GenerateSortedIndexList(
        CParticleCollection *this,
        __m128 *pOut,
        Vector vecCamera,
        CParticleVisibilityData *pVisibilityData,
        bool bSorted)
{
  int m_nActiveParticles; // ebx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CParticleCollection::GenerateSortedIndexList",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  m_nActiveParticles = this->m_nActiveParticles;
  if ( bSorted )
  {
    s_GenerateData<1,0>(pOutData: pOut, CameraPos: vecCamera, pCameraFwd: nullptr, pVisibilityData, pParticles: this);
    if ( 16 * m_nActiveParticles > 16 )
      std::_Make_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        _First: (ParticleRenderData_t *)pOut,
        _Last: (ParticleRenderData_t *)&pOut[m_nActiveParticles],
        _Pred: (bool (__cdecl *)(const ParticleRenderData_t *, const ParticleRenderData_t *))CDefOps<DmeTime_t>::LessFunc);
    std::_Sort_heap<ParticleRenderData_t *,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
      _First: (ParticleRenderData_t *)pOut,
      _Last: (ParticleRenderData_t *)&pOut[m_nActiveParticles],
      _Pred: (bool (__cdecl *)(const ParticleRenderData_t *, const ParticleRenderData_t *))CDefOps<DmeTime_t>::LessFunc);
  }
  else
  {
    s_GenerateData<0,0>(pOutData: pOut, CameraPos: vecCamera, pCameraFwd: nullptr, pVisibilityData, pParticles: this);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return m_nActiveParticles;
}

//------------------------------------------------------------------------------
// Address: 0x102A4E20
// Name: public: int CParticleCollection::GenerateCulledSortedIndexList(struct ParticleRenderData_t __near *,class Vector,class Vector,struct CParticleVisibilityData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleCollection::GenerateCulledSortedIndexList(
        CParticleCollection *this,
        __m128 *pOut,
        Vector vecCamera,
        Vector vecFwd,
        CParticleVisibilityData *pVisibilityData,
        bool bSorted)
{
  int m_nActiveParticles; // ebx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CParticleCollection::GenerateSortedIndexList",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  m_nActiveParticles = this->m_nActiveParticles;
  if ( bSorted )
  {
    s_GenerateData<1,1>(pOutData: pOut, CameraPos: vecCamera, pCameraFwd: &vecFwd, pVisibilityData, pParticles: this);
    if ( 16 * m_nActiveParticles > 16 )
      std::_Make_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        _First: (ParticleRenderData_t *)pOut,
        _Last: (ParticleRenderData_t *)&pOut[m_nActiveParticles],
        _Pred: (bool (__cdecl *)(const ParticleRenderData_t *, const ParticleRenderData_t *))CDefOps<DmeTime_t>::LessFunc);
    std::_Sort_heap<ParticleRenderData_t *,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
      _First: (ParticleRenderData_t *)pOut,
      _Last: (ParticleRenderData_t *)&pOut[m_nActiveParticles],
      _Pred: (bool (__cdecl *)(const ParticleRenderData_t *, const ParticleRenderData_t *))CDefOps<DmeTime_t>::LessFunc);
  }
  else
  {
    s_GenerateData<0,1>(pOutData: pOut, CameraPos: vecCamera, pCameraFwd: &vecFwd, pVisibilityData, pParticles: this);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return m_nActiveParticles;
}

//------------------------------------------------------------------------------
// Address: 0x102A4ED0
// Name: public: struct ParticleRenderData_t const __near * CParticleCollection::GetRenderList(class IMatRenderContext __near *,bool,int __near *,struct CParticleVisibilityData __near *)
// Source: json
//------------------------------------------------------------------------------
const ParticleRenderData_t *__thiscall CParticleCollection::GetRenderList(
        CParticleCollection *this,
        IMatRenderContext *pRenderContext,
        bool bSorted,
        int *pNparticles,
        CParticleVisibilityData *pVisibilityData)
{
  int SortedIndexList; // eax
  Vector vecRight; // [esp+8h] [ebp-30h] BYREF
  Vector vecUp; // [esp+14h] [ebp-24h] BYREF
  Vector vecFwd; // [esp+20h] [ebp-18h] BYREF
  Vector vecCamera; // [esp+2Ch] [ebp-Ch] BYREF

  if ( bSorted )
    bSorted = this->m_pDef.m_pObject->m_bShouldSort;
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &vecCamera);
  if ( vecCamera.x < this->m_MinBounds.x
    || this->m_MaxBounds.x < vecCamera.x
    || vecCamera.y < this->m_MinBounds.y
    || this->m_MaxBounds.y < vecCamera.y
    || vecCamera.z < this->m_MinBounds.z
    || this->m_MaxBounds.z < vecCamera.z )
  {
    SortedIndexList = CParticleCollection::GenerateSortedIndexList(
                        this,
                        pOut: (__m128 *)&s_SortBuffer,
                        vecCamera,
                        pVisibilityData,
                        bSorted);
  }
  else
  {
    pRenderContext->GetWorldSpaceCameraVectors(this: pRenderContext, a2: &vecFwd, a3: &vecRight, a4: &vecUp);
    SortedIndexList = CParticleCollection::GenerateCulledSortedIndexList(
                        this,
                        pOut: (__m128 *)&s_SortBuffer,
                        vecCamera,
                        vecFwd,
                        pVisibilityData,
                        bSorted);
  }
  *pNparticles = SortedIndexList;
  return &s_SortBuffer + SortedIndexList;
}

//------------------------------------------------------------------------------
// Address: 0x102A4FF0
// Name: int GenerateExtendedSortedIndexList(class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,bool,void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GenerateExtendedSortedIndexList(
        Vector vecCamera,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        Vector *pParticles,
        bool bSorted,
        char *pOutBuf,
        ParticleFullRenderData_Scalar_View **pParticlePtrs)
{
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  bool v10; // bl
  ParticleFullRenderData_Scalar_View **v11; // esi
  int x_low; // edi
  Vector v14; // [esp-20h] [ebp-2Ch]
  Vector v15; // [esp-20h] [ebp-2Ch]

  z = pParticles[3].z;
  x = pParticles[3].x;
  if ( x <= z || (y = pParticles[3].y, z < y) || LODWORD(pParticles[17].y) == 0 || LOBYTE(pParticles[7].y) != 0 )
  {
    v10 = bSorted;
    v11 = pParticlePtrs;
    *(_QWORD *)&v15.x = *(_QWORD *)&vecCamera.x;
    v15.z = vecCamera.z;
    s_GenerateExtendedData<0,0,ParticleFullRenderData_SIMD_View,0,0>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: v15,
      pCameraFwd: nullptr,
      pVisibilityData,
      (CParticleCollection *)pParticles,
      flInterpT: 0.0,
      bSort: bSorted);
  }
  else
  {
    v10 = bSorted;
    v11 = pParticlePtrs;
    *(_QWORD *)&v14.x = *(_QWORD *)&vecCamera.x;
    v14.z = vecCamera.z;
    s_GenerateExtendedData<0,1,ParticleFullRenderData_SIMD_View,0,0>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: v14,
      pCameraFwd: nullptr,
      pVisibilityData,
      (CParticleCollection *)pParticles,
      flInterpT: COERCE_UNSIGNED_INT((float)(z - y) / (float)(x - y)),
      bSort: bSorted);
  }
  x_low = LODWORD(pParticles[4].x);
  if ( v10 )
  {
    if ( 4 * x_low > 4 )
      std::_Make_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First: v11,
        _Last: &v11[x_low],
        _Pred: ActiveLayer_t<Color>::PriorityLessFunc);
    std::_Sort_heap<ParticleFullRenderData_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
      _First: v11,
      _Last: &v11[x_low],
      _Pred: ActiveLayer_t<Color>::PriorityLessFunc);
  }
  return x_low;
}

//------------------------------------------------------------------------------
// Address: 0x102A50E0
// Name: int GenerateExtendedSortedIndexListWithPerParticleGlow(class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,bool,void __near *,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GenerateExtendedSortedIndexListWithPerParticleGlow(
        Vector vecCamera,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        Vector *pParticles,
        bool bSorted,
        char *pOutBuf,
        ParticleFullRenderData_Scalar_View **pParticlePtrs)
{
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  bool v10; // bl
  ParticleRenderDataWithNormal_Scalar_View **v11; // esi
  int x_low; // edi
  Vector v14; // [esp-20h] [ebp-2Ch]
  Vector v15; // [esp-20h] [ebp-2Ch]

  z = pParticles[3].z;
  x = pParticles[3].x;
  if ( x <= z || (y = pParticles[3].y, z < y) || LODWORD(pParticles[17].y) == 0 || LOBYTE(pParticles[7].y) != 0 )
  {
    v10 = bSorted;
    v11 = (ParticleRenderDataWithNormal_Scalar_View **)pParticlePtrs;
    *(_QWORD *)&v15.x = *(_QWORD *)&vecCamera.x;
    v15.z = vecCamera.z;
    s_GenerateExtendedData<0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: v15,
      pCameraFwd: nullptr,
      pVisibilityData,
      (CParticleCollection *)pParticles,
      flInterpT: 0.0,
      bSort: bSorted);
  }
  else
  {
    v10 = bSorted;
    v11 = (ParticleRenderDataWithNormal_Scalar_View **)pParticlePtrs;
    *(_QWORD *)&v14.x = *(_QWORD *)&vecCamera.x;
    v14.z = vecCamera.z;
    s_GenerateExtendedData<0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: v14,
      pCameraFwd: nullptr,
      pVisibilityData,
      (CParticleCollection *)pParticles,
      flInterpT: COERCE_UNSIGNED_INT((float)(z - y) / (float)(x - y)),
      bSort: bSorted);
  }
  x_low = LODWORD(pParticles[4].x);
  if ( v10 )
  {
    if ( 4 * x_low > 4 )
      std::_Make_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First: v11,
        _Last: &v11[x_low],
        _Pred: ActiveLayer_t<Color>::PriorityLessFunc);
    std::_Sort_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
      _First: v11,
      _Last: &v11[x_low],
      _Pred: ActiveLayer_t<Color>::PriorityLessFunc);
  }
  return x_low;
}

//------------------------------------------------------------------------------
// Address: 0x102A51D0
// Name: int GenerateExtendedSortedIndexListWithNormals(class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,bool,void __near *,struct ParticleRenderDataWithNormal_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GenerateExtendedSortedIndexListWithNormals(
        Vector vecCamera,
        Vector *pCameraFwd,
        Vector *pVisibilityData,
        Vector *pParticles,
        bool bSorted,
        char *pOutBuf,
        ParticleFullRenderData_Scalar_View **pParticlePtrs)
{
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  bool v10; // bl
  ParticleRenderDataWithNormal_Scalar_View **v11; // esi
  int x_low; // edi
  Vector v14; // [esp-20h] [ebp-2Ch]
  Vector v15; // [esp-20h] [ebp-2Ch]

  z = pParticles[3].z;
  x = pParticles[3].x;
  if ( x <= z || (y = pParticles[3].y, z < y) || LODWORD(pParticles[17].y) == 0 || LOBYTE(pParticles[7].y) != 0 )
  {
    v10 = bSorted;
    v11 = (ParticleRenderDataWithNormal_Scalar_View **)pParticlePtrs;
    *(_QWORD *)&v15.x = *(_QWORD *)&vecCamera.x;
    v15.z = vecCamera.z;
    s_GenerateExtendedData<0,0,ParticleRenderDataWithNormal_SIMD_View,0,1>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: v15,
      pCameraFwd: nullptr,
      pVisibilityData,
      (CParticleCollection *)pParticles,
      flInterpT: 0.0,
      bSort: bSorted);
  }
  else
  {
    v10 = bSorted;
    v11 = (ParticleRenderDataWithNormal_Scalar_View **)pParticlePtrs;
    *(_QWORD *)&v14.x = *(_QWORD *)&vecCamera.x;
    v14.z = vecCamera.z;
    s_GenerateExtendedData<0,1,ParticleRenderDataWithNormal_SIMD_View,0,1>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: v14,
      pCameraFwd: nullptr,
      pVisibilityData,
      (CParticleCollection *)pParticles,
      flInterpT: COERCE_UNSIGNED_INT((float)(z - y) / (float)(x - y)),
      bSort: bSorted);
  }
  x_low = LODWORD(pParticles[4].x);
  if ( v10 )
  {
    if ( 4 * x_low > 4 )
      std::_Make_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First: v11,
        _Last: &v11[x_low],
        _Pred: ActiveLayer_t<Color>::PriorityLessFunc);
    std::_Sort_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
      _First: v11,
      _Last: &v11[x_low],
      _Pred: ActiveLayer_t<Color>::PriorityLessFunc);
  }
  return x_low;
}

//------------------------------------------------------------------------------
// Address: 0x102A52C0
// Name: struct ParticleFullRenderData_Scalar_View __near * __near * GetExtendedRenderList(class CParticleCollection __near *,class IMatRenderContext __near *,bool,int __near *,struct CParticleVisibilityData __near *)
// Source: json
//------------------------------------------------------------------------------
ParticleFullRenderData_Scalar_View **__cdecl GetExtendedRenderList(
        Vector *pParticles,
        IMatRenderContext *pRenderContext,
        bool bSorted,
        int *pNparticles,
        Vector *pVisibilityData)
{
  int ExtendedSortedIndexList; // eax
  Vector vecCamera; // [esp+4h] [ebp-Ch] BYREF

  if ( bSorted )
    bSorted = *(_BYTE *)(LODWORD(pParticles[6].x) + 624);
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &vecCamera);
  ExtendedSortedIndexList = GenerateExtendedSortedIndexList(
                              vecCamera,
                              pCameraFwd: nullptr,
                              pVisibilityData,
                              pParticles,
                              bSorted,
                              pOutBuf: (char *)&s_SortBuffer,
                              pParticlePtrs: s_pParticlePtrs);
  *pNparticles = ExtendedSortedIndexList;
  return &s_pParticlePtrs[ExtendedSortedIndexList];
}

//------------------------------------------------------------------------------
// Address: 0x102A5330
// Name: struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near * GetExtendedRenderListWithPerParticleGlow(class CParticleCollection __near *,class IMatRenderContext __near *,bool,int __near *,struct CParticleVisibilityData __near *)
// Source: json
//------------------------------------------------------------------------------
ParticleFullRenderData_Scalar_View **__cdecl GetExtendedRenderListWithPerParticleGlow(
        Vector *pParticles,
        IMatRenderContext *pRenderContext,
        bool bSorted,
        int *pNparticles,
        Vector *pVisibilityData)
{
  int ExtendedSortedIndexListWithPerParticleGlow; // eax
  Vector vecCamera; // [esp+4h] [ebp-Ch] BYREF

  if ( bSorted )
    bSorted = *(_BYTE *)(LODWORD(pParticles[6].x) + 624);
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &vecCamera);
  ExtendedSortedIndexListWithPerParticleGlow = GenerateExtendedSortedIndexListWithPerParticleGlow(
                                                 vecCamera,
                                                 pCameraFwd: nullptr,
                                                 pVisibilityData,
                                                 pParticles,
                                                 bSorted,
                                                 pOutBuf: (char *)&s_SortBuffer,
                                                 pParticlePtrs: s_pParticlePtrs);
  *pNparticles = ExtendedSortedIndexListWithPerParticleGlow;
  return &s_pParticlePtrs[ExtendedSortedIndexListWithPerParticleGlow];
}

//------------------------------------------------------------------------------
// Address: 0x102A53A0
// Name: struct ParticleRenderDataWithNormal_Scalar_View __near * __near * GetExtendedRenderListWithNormals(class CParticleCollection __near *,class IMatRenderContext __near *,bool,int __near *,struct CParticleVisibilityData __near *)
// Source: json
//------------------------------------------------------------------------------
ParticleFullRenderData_Scalar_View **__cdecl GetExtendedRenderListWithNormals(
        Vector *pParticles,
        IMatRenderContext *pRenderContext,
        bool bSorted,
        int *pNparticles,
        Vector *pVisibilityData)
{
  int ExtendedSortedIndexListWithNormals; // eax
  Vector vecCamera; // [esp+4h] [ebp-Ch] BYREF

  if ( bSorted )
    bSorted = *(_BYTE *)(LODWORD(pParticles[6].x) + 624);
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &vecCamera);
  ExtendedSortedIndexListWithNormals = GenerateExtendedSortedIndexListWithNormals(
                                         vecCamera,
                                         pCameraFwd: nullptr,
                                         pVisibilityData,
                                         pParticles,
                                         bSorted,
                                         pOutBuf: (char *)&s_SortBuffer,
                                         pParticlePtrs: s_pParticlePtrs);
  *pNparticles = ExtendedSortedIndexListWithNormals;
  return &s_pParticlePtrs[ExtendedSortedIndexListWithNormals];
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10358890
// Name: SortLessFuncExtended
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SortLessFuncExtended(
        ParticleFullRenderData_Scalar_View *const *left,
        const ParticleFullRenderData_Scalar_View *const *right)
{
  return **(_DWORD **)left < **(_DWORD **)right;
}

//------------------------------------------------------------------------------
// Address: 0x103588B0
// Name: void std::_Push_heap<struct ParticleRenderData_t __near *,int,struct ParticleRenderData_t,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &)>(struct ParticleRenderData_t __near *,int,int,struct ParticleRenderData_t __near &&,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        ParticleRenderData_t *_First,
        int _Hole,
        int _Top,
        ParticleRenderData_t *_Val,
        bool (__cdecl *_Pred)(const ParticleRenderData_t *, const ParticleRenderData_t *))
{
  int v5; // edi
  int i; // esi
  ParticleRenderData_t *v7; // ebx
  ParticleRenderData_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    *(_QWORD *)&v8->m_flSortKey = *(_QWORD *)&v7->m_flSortKey;
    *(_QWORD *)&v8->m_flRadius = *(_QWORD *)&v7->m_flRadius;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10358930
// Name: void std::_Push_heap<struct ParticleFullRenderData_Scalar_View __near * __near *,int,struct ParticleFullRenderData_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleFullRenderData_Scalar_View __near * __near *,int,int,struct ParticleFullRenderData_Scalar_View __near * __near &&,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleFullRenderData_Scalar_View **_First,
        int _Hole,
        int _Top,
        const ParticleFullRenderData_Scalar_View *const *_Val,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v5; // edi
  int v6; // esi
  bool v7; // zf
  ParticleFullRenderData_Scalar_View **v8; // eax

  v5 = _Hole;
  v6 = (_Hole - 1) / 2;
  if ( _Top >= _Hole )
  {
    _First[_Hole] = (ParticleFullRenderData_Scalar_View *)*_Val;
  }
  else
  {
    while ( 1 )
    {
      v7 = !_Pred(a1: &_First[v6], a2: _Val);
      v8 = _First;
      if ( v7 )
        break;
      _First[v5] = _First[v6];
      v5 = v6;
      v6 = (v6 - 1) / 2;
      if ( _Top >= v5 )
      {
        v8 = _First;
        break;
      }
    }
    v8[v5] = (ParticleFullRenderData_Scalar_View *)*_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103589A0
// Name: void std::_Push_heap<struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,int,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,int,int,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near &&,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleRenderDataWithNormal_Scalar_View **_First,
        int _Hole,
        int _Top,
        ParticleRenderDataWithNormal_Scalar_View **_Val,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v5; // edi
  int v6; // esi
  ParticleRenderDataWithNormal_Scalar_View **v7; // ebx
  int v8; // edx

  v5 = _Hole;
  v6 = (_Hole - 1) / 2;
  if ( _Top >= _Hole )
  {
    _First[_Hole] = *_Val;
  }
  else
  {
    v7 = _First;
    while ( 1 )
    {
      v8 = (int)v7[v6];
      _First = (ParticleRenderDataWithNormal_Scalar_View **)*_Val;
      _Hole = v8;
      if ( !_Pred(
              a1: (ParticleFullRenderData_Scalar_View *const *)&_Hole,
              a2: (const ParticleFullRenderData_Scalar_View *const *)&_First) )
        break;
      v7[v5] = v7[v6];
      v5 = v6;
      v6 = (v6 - 1) / 2;
      if ( _Top >= v5 )
      {
        v7[v5] = *_Val;
        return;
      }
    }
    v7[v5] = *_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10358A20
// Name: void s_GenerateData<1,0>(void __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateData<1,0>(
        __m128 *pOutData,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 *v7; // esi
  __m128 v8; // xmm7
  unsigned int v9; // ecx
  __m128 *v10; // eax
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 EyePos_4; // [esp+4h] [ebp-8Ch]
  __m128 EyePos_36; // [esp+24h] [ebp-6Ch]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-5Ch]
  __m128 fl4AlphaScale_4; // [esp+44h] [ebp-4Ch]
  unsigned int fl4AlphaVis_8; // [esp+58h] [ebp-38h]
  unsigned int fl4AlphaVis_12; // [esp+5Ch] [ebp-34h]
  __m128 *pXYZ; // [esp+60h] [ebp-30h]
  unsigned int v31; // [esp+68h] [ebp-28h]
  __m128 *pAlpha; // [esp+6Ch] [ebp-24h]
  float *v33; // [esp+74h] [ebp-1Ch]
  int pAlpha2_4; // [esp+7Ch] [ebp-14h]
  bool pRadius_3; // [esp+83h] [ebp-Dh]

  v5 = _mm_add_ps(Four_2ToThe23s, g_SIMD_0123);
  pXYZ = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  v6 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  v7 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  pAlpha2_4 = pParticles->m_nActiveParticles;
  v8 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  fl4AlphaVis_12 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  fl4AlphaScale_4 = _mm_shuffle_ps(
                      (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                      (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                      0);
  v33 = pParticles->m_ParticleAttributes.m_pAttributes[3];
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  fl4AlphaVis_8 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v9 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  pRadius_3 = pVisibilityData->m_bUseVisibility;
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v31 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  v10 = pOutData + 2;
  do
  {
    v11 = _mm_mul_ps(*pXYZ, *pAlpha);
    v12 = *(__m128 *)v33;
    if ( pRadius_3 )
    {
      v12 = _mm_mul_ps(v12, EyePos_36);
      v11 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, fl4AlphaScale_4)));
    }
    v13 = _mm_sub_ps(v7[1], EyePos_4);
    pAlpha = (__m128 *)((char *)pAlpha + v31);
    pAlpha2_4 -= 4;
    v33 = (float *)((char *)v33 + fl4AlphaVis_8);
    v14 = _mm_add_ps(_mm_mul_ps(v11, fl4RadVis_4), Four_2ToThe23s);
    v15 = _mm_sub_ps(*v7, v6);
    v16 = _mm_sub_ps(v7[2], v8);
    v17 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, v16), _mm_mul_ps(v13, v13)), _mm_mul_ps(v15, v15));
    v18 = _mm_and_ps(*(__m128 *)g_SIMD_Low16BitsMask, v5);
    v19 = _mm_shuffle_ps(v17, v18, 68);
    v20 = _mm_shuffle_ps(v17, v18, 238);
    v21 = v12;
    v22 = _mm_shuffle_ps(v12, v14, 238);
    v23 = _mm_shuffle_ps(v21, v14, 68);
    v10[-1] = _mm_shuffle_ps(v19, v23, 221);
    v10[-2] = _mm_shuffle_ps(v19, v23, 136);
    *v10 = _mm_shuffle_ps(v20, v22, 136);
    v10[1] = _mm_shuffle_ps(v20, v22, 221);
    v5 = _mm_add_ps(v5, Four_Fours);
    v10 += 4;
    v7 = (__m128 *)((char *)v7 + v9);
    pXYZ = (__m128 *)((char *)pXYZ + fl4AlphaVis_12);
  }
  while ( pAlpha2_4 > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10358C00
// Name: void s_GenerateData<0,0>(void __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateData<0,0>(
        __m128 *pOutData,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  int m_nActiveParticles; // edx
  unsigned int v8; // esi
  __m128 v9; // xmm7
  __m128 v10; // xmm4
  __m128 *v11; // eax
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // [esp-Ch] [ebp-5Ch]
  __m128 fl4RadVis_4; // [esp+4h] [ebp-4Ch]
  float *v22; // [esp+20h] [ebp-30h]
  __m128 *v23; // [esp+28h] [ebp-28h]
  __m128 *pRadius_4; // [esp+30h] [ebp-20h]
  unsigned int pAlpha2_4; // [esp+38h] [ebp-18h]
  unsigned int pAlpha; // [esp+3Ch] [ebp-14h]
  bool pAlpha_7; // [esp+43h] [ebp-Dh]

  v5 = Four_Zeros;
  v6 = _mm_add_ps(Four_2ToThe23s, g_SIMD_0123);
  pRadius_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  v23 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  v22 = pParticles->m_ParticleAttributes.m_pAttributes[3];
  m_nActiveParticles = pParticles->m_nActiveParticles;
  fl4RadVis_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  v20 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          0);
  pAlpha_7 = pVisibilityData->m_bUseVisibility;
  v8 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  v9 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v10 = Four_Zeros;
  pAlpha = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  pAlpha2_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v11 = pOutData + 2;
  while ( 1 )
  {
    v12 = _mm_mul_ps(*pRadius_4, *v23);
    v13 = *(__m128 *)v22;
    if ( pAlpha_7 )
    {
      v13 = _mm_mul_ps(v13, v20);
      v12 = _mm_max_ps(v5, _mm_min_ps(Four_Ones, _mm_mul_ps(v12, fl4RadVis_4)));
    }
    v23 = (__m128 *)((char *)v23 + v8);
    v22 = (float *)((char *)v22 + pAlpha2_4);
    v14 = _mm_add_ps(_mm_mul_ps(v12, v9), Four_2ToThe23s);
    v15 = _mm_and_ps(*(__m128 *)g_SIMD_Low16BitsMask, v6);
    v16 = _mm_shuffle_ps(v10, v15, 238);
    v17 = _mm_shuffle_ps(v10, v15, 68);
    v18 = _mm_shuffle_ps(v13, v14, 68);
    v11[-1] = _mm_shuffle_ps(v17, v18, 221);
    v19 = _mm_shuffle_ps(v13, v14, 238);
    v10 = _mm_shuffle_ps(v17, v18, 136);
    v11[-2] = v10;
    *v11 = _mm_shuffle_ps(v16, v19, 136);
    v11[1] = _mm_shuffle_ps(v16, v19, 221);
    v6 = _mm_add_ps(v6, Four_Fours);
    m_nActiveParticles -= 4;
    v11 += 4;
    pRadius_4 = (__m128 *)((char *)pRadius_4 + pAlpha);
    if ( m_nActiveParticles <= 0 )
      break;
    v5 = Four_Zeros;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10358D80
// Name: void s_GenerateData<1,1>(void __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateData<1,1>(
        __m128 *pOutData,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 *v5; // esi
  unsigned int v8; // ecx
  __m128 *v9; // eax
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm5
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // [esp-Ch] [ebp-DCh]
  __m128 v4Fwd_4; // [esp+4h] [ebp-CCh]
  __m128 v4Fwd_20; // [esp+14h] [ebp-BCh]
  __m128 v4Fwd_36; // [esp+24h] [ebp-ACh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-9Ch]
  __m128 EyePos_4; // [esp+44h] [ebp-8Ch]
  __m128 EyePos_20; // [esp+54h] [ebp-7Ch]
  __m128 EyePos_36; // [esp+64h] [ebp-6Ch]
  __m128 fl4AlphaVis_4; // [esp+74h] [ebp-5Ch]
  __m128 fl4AlphaScale_4; // [esp+84h] [ebp-4Ch]
  __m128 *fl4OutIdx_4; // [esp+94h] [ebp-3Ch]
  unsigned int pAlpha2; // [esp+A0h] [ebp-30h]
  unsigned int pAlpha2_4; // [esp+A4h] [ebp-2Ch]
  unsigned int pXYZ; // [esp+A8h] [ebp-28h]
  __m128 *pXYZ_4; // [esp+ACh] [ebp-24h]
  float *v41; // [esp+B4h] [ebp-1Ch]
  int pAlpha_4; // [esp+BCh] [ebp-14h]
  bool pRadius_3; // [esp+C3h] [ebp-Dh]

  fl4RadVis_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  pXYZ_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4OutIdx_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  v5 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  pAlpha_4 = pParticles->m_nActiveParticles;
  v26 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->x), (__m128)LODWORD(pCameraFwd->x), 0);
  v4Fwd_4 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->y), (__m128)LODWORD(pCameraFwd->y), 0);
  v4Fwd_20 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->z), (__m128)LODWORD(pCameraFwd->z), 0);
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                0);
  pXYZ = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  v4Fwd_36 = _mm_shuffle_ps(
               (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
               (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
               0);
  v41 = pParticles->m_ParticleAttributes.m_pAttributes[3];
  fl4AlphaScale_4 = _mm_add_ps(Four_2ToThe23s, g_SIMD_0123);
  pAlpha2 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v8 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  pRadius_3 = pVisibilityData->m_bUseVisibility;
  fl4AlphaVis_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  pAlpha2_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  v9 = pOutData + 2;
  do
  {
    v10 = _mm_mul_ps(*pXYZ_4, *fl4OutIdx_4);
    v11 = *(__m128 *)v41;
    if ( pRadius_3 )
    {
      v11 = _mm_mul_ps(v11, v4Fwd_36);
      v10 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v10, EyePos_36)));
    }
    v12 = _mm_sub_ps(v5[2], EyePos_20);
    v13 = _mm_sub_ps(v5[1], EyePos_4);
    v14 = _mm_sub_ps(*v5, fl4RadVis_4);
    fl4OutIdx_4 = (__m128 *)((char *)fl4OutIdx_4 + pAlpha2_4);
    pAlpha_4 -= 4;
    v41 = (float *)((char *)v41 + pAlpha2);
    v15 = _mm_add_ps(_mm_mul_ps(v4Fwd_20, v12), _mm_mul_ps(v4Fwd_4, v13));
    v16 = _mm_mul_ps(v26, v14);
    v17 = _mm_add_ps(_mm_mul_ps(v12, v12), _mm_mul_ps(v13, v13));
    v18 = _mm_and_ps(*(__m128 *)g_SIMD_Low16BitsMask, fl4AlphaScale_4);
    v19 = _mm_add_ps(v17, _mm_mul_ps(v14, v14));
    v20 = _mm_shuffle_ps(v19, v18, 68);
    v21 = _mm_shuffle_ps(v19, v18, 238);
    v22 = _mm_and_ps(
            _mm_cmple_ps(Four_Zeros, _mm_add_ps(v15, v16)),
            _mm_add_ps(_mm_mul_ps(v10, fl4AlphaVis_4), Four_2ToThe23s));
    v23 = v11;
    v24 = _mm_shuffle_ps(v11, v22, 238);
    v25 = _mm_shuffle_ps(v23, v22, 68);
    v9[-1] = _mm_shuffle_ps(v20, v25, 221);
    v9[1] = _mm_shuffle_ps(v21, v24, 221);
    v9[-2] = _mm_shuffle_ps(v20, v25, 136);
    *v9 = _mm_shuffle_ps(v21, v24, 136);
    v9 += 4;
    v5 = (__m128 *)((char *)v5 + v8);
    fl4AlphaScale_4 = _mm_add_ps(Four_Fours, fl4AlphaScale_4);
    pXYZ_4 = (__m128 *)((char *)pXYZ_4 + pXYZ);
  }
  while ( pAlpha_4 > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10358FE0
// Name: void s_GenerateData<0,1>(void __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateData<0,1>(
        __m128 *pOutData,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 *v7; // esi
  unsigned int v9; // ecx
  __m128 v10; // xmm5
  __m128 *v11; // eax
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // [esp-Ch] [ebp-CCh]
  __m128 v4Fwd_4; // [esp+4h] [ebp-BCh]
  __m128 v4Fwd_20; // [esp+14h] [ebp-ACh]
  __m128 v4Fwd_36; // [esp+24h] [ebp-9Ch]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-8Ch]
  __m128 EyePos_4; // [esp+44h] [ebp-7Ch]
  __m128 EyePos_20; // [esp+54h] [ebp-6Ch]
  __m128 EyePos_36; // [esp+64h] [ebp-5Ch]
  __m128 fl4AlphaScale_4; // [esp+74h] [ebp-4Ch]
  __m128 *fl4AlphaVis_4; // [esp+84h] [ebp-3Ch]
  unsigned int pAlpha2; // [esp+90h] [ebp-30h]
  unsigned int pAlpha2_4; // [esp+94h] [ebp-2Ch]
  unsigned int pXYZ; // [esp+98h] [ebp-28h]
  __m128 *pXYZ_4; // [esp+9Ch] [ebp-24h]
  float *v34; // [esp+A4h] [ebp-1Ch]
  int pAlpha_4; // [esp+ACh] [ebp-14h]
  bool pRadius_3; // [esp+B3h] [ebp-Dh]

  fl4RadVis_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  pXYZ_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4AlphaVis_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  v5 = Four_Zeros;
  v6 = _mm_add_ps(Four_2ToThe23s, g_SIMD_0123);
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  v7 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  pAlpha_4 = pParticles->m_nActiveParticles;
  v20 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->x), (__m128)LODWORD(pCameraFwd->x), 0);
  v4Fwd_4 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->y), (__m128)LODWORD(pCameraFwd->y), 0);
  v4Fwd_20 = _mm_shuffle_ps((__m128)LODWORD(pCameraFwd->z), (__m128)LODWORD(pCameraFwd->z), 0);
  pXYZ = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  fl4AlphaScale_4 = _mm_shuffle_ps(
                      (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                      (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                      0);
  v34 = pParticles->m_ParticleAttributes.m_pAttributes[3];
  v4Fwd_36 = _mm_shuffle_ps(
               (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
               (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
               0);
  pAlpha2 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v9 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  pRadius_3 = pVisibilityData->m_bUseVisibility;
  EyePos_36 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v10 = Four_Zeros;
  pAlpha2_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  v11 = pOutData + 2;
  while ( 1 )
  {
    v12 = _mm_mul_ps(*pXYZ_4, *fl4AlphaVis_4);
    v13 = *(__m128 *)v34;
    if ( pRadius_3 )
    {
      v13 = _mm_mul_ps(v13, v4Fwd_36);
      v12 = _mm_max_ps(v5, _mm_min_ps(Four_Ones, _mm_mul_ps(v12, fl4AlphaScale_4)));
    }
    fl4AlphaVis_4 = (__m128 *)((char *)fl4AlphaVis_4 + pAlpha2_4);
    pAlpha_4 -= 4;
    v34 = (float *)((char *)v34 + pAlpha2);
    v14 = _mm_and_ps(
            _mm_cmple_ps(
              v5,
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_sub_ps(v7[2], EyePos_20), v4Fwd_20),
                  _mm_mul_ps(_mm_sub_ps(v7[1], EyePos_4), v4Fwd_4)),
                _mm_mul_ps(_mm_sub_ps(*v7, fl4RadVis_4), v20))),
            _mm_add_ps(_mm_mul_ps(v12, EyePos_36), Four_2ToThe23s));
    v15 = _mm_and_ps(*(__m128 *)g_SIMD_Low16BitsMask, v6);
    v16 = _mm_shuffle_ps(v10, v15, 238);
    v17 = _mm_shuffle_ps(v10, v15, 68);
    v18 = _mm_shuffle_ps(v13, v14, 68);
    v11[-1] = _mm_shuffle_ps(v17, v18, 221);
    v19 = _mm_shuffle_ps(v13, v14, 238);
    v10 = _mm_shuffle_ps(v17, v18, 136);
    v11[-2] = v10;
    *v11 = _mm_shuffle_ps(v16, v19, 136);
    v11[1] = _mm_shuffle_ps(v16, v19, 221);
    v6 = _mm_add_ps(v6, Four_Fours);
    v11 += 4;
    v7 = (__m128 *)((char *)v7 + v9);
    pXYZ_4 = (__m128 *)((char *)pXYZ_4 + pXYZ);
    if ( pAlpha_4 <= 0 )
      break;
    v5 = Four_Zeros;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10359230
// Name: void std::_Adjust_heap<struct ParticleRenderData_t __near *,int,struct ParticleRenderData_t,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &)>(struct ParticleRenderData_t __near *,int,int,struct ParticleRenderData_t __near &&,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        ParticleRenderData_t *_First,
        int _Hole,
        int _Bottom,
        ParticleRenderData_t *_Val,
        bool (__cdecl *_Pred)(const ParticleRenderData_t *, const ParticleRenderData_t *))
{
  int v5; // ecx
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  int v9; // ecx
  __int64 v10; // xmm0_8
  int v11; // esi
  const ParticleRenderData_t *v12; // ebx
  int _Holea; // [esp+1Ch] [ebp+Ch]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = v6;
      v6 = v7;
      *(_QWORD *)&_First[v9].m_flSortKey = *(_QWORD *)&_First[v7].m_flSortKey;
      v10 = *(_QWORD *)&_First[v7].m_flRadius;
      v7 = 2 * v7 + 2;
      *(_QWORD *)&_First[v9].m_flRadius = v10;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  v11 = (v6 - 1) / 2;
  _Holea = v6;
  if ( _Hole < v6 )
  {
    do
    {
      v12 = &_First[v11];
      if ( !_Pred(a1: v12, a2: _Val) )
        break;
      _First[_Holea] = *v12;
      _Holea = v11;
      v11 = (v11 - 1) / 2;
    }
    while ( _Hole < _Holea );
    v6 = _Holea;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10359340
// Name: void GenerateExtendedData<1,0,1,struct ParticleFullRenderData_SIMD_View,0,0,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,1,ParticleFullRenderData_SIMD_View,0,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  unsigned int v7; // esi
  __m128 v8; // xmm0
  __m128 *v9; // esi
  __m128 *v10; // edi
  char *v11; // eax
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // [esp-Ch] [ebp-1FCh]
  __m128 EyePos_4; // [esp+4h] [ebp-1ECh]
  __m128 EyePos_20; // [esp+14h] [ebp-1DCh]
  __m128 EyePos_36; // [esp+24h] [ebp-1CCh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-1BCh]
  __m128 Four_256s_4; // [esp+44h] [ebp-1ACh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-19Ch]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-18Ch]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+74h] [ebp-17Ch]
  __m128 fl4AlphaScale_4; // [esp+84h] [ebp-16Ch]
  __m128 fl4FinalRadius_4; // [esp+94h] [ebp-15Ch]
  unsigned int v37; // [esp+C4h] [ebp-12Ch]
  float *v38; // [esp+C8h] [ebp-128h]
  unsigned int v39; // [esp+D0h] [ebp-120h]
  int v40; // [esp+ECh] [ebp-104h]
  int v41; // [esp+12Ch] [ebp-C4h]
  int v42; // [esp+130h] [ebp-C0h]
  __m128 *v43; // [esp+158h] [ebp-98h]
  int v44; // [esp+160h] [ebp-90h]
  __m128 *pYaw; // [esp+164h] [ebp-8Ch]
  __m128 *pYaw_8; // [esp+16Ch] [ebp-84h]
  unsigned int pSeq; // [esp+170h] [ebp-80h]
  int pSeq_4; // [esp+174h] [ebp-7Ch]
  __m128 *pRadius; // [esp+178h] [ebp-78h]
  unsigned int pRadius_4; // [esp+17Ch] [ebp-74h]
  int pRadius_8; // [esp+180h] [ebp-70h]
  __m128 *pRot; // [esp+184h] [ebp-6Ch]
  unsigned int pRot_4; // [esp+188h] [ebp-68h]
  int pRot_8; // [esp+18Ch] [ebp-64h]
  __m128 *pAlpha; // [esp+190h] [ebp-60h]
  unsigned int pAlpha_4; // [esp+194h] [ebp-5Ch]
  int pAlpha_8; // [esp+198h] [ebp-58h]
  __m128 *pAlpha2; // [esp+19Ch] [ebp-54h]
  unsigned int pAlpha2_4; // [esp+1A0h] [ebp-50h]
  __m128 *pAlpha2_8; // [esp+1A4h] [ebp-4Ch]
  unsigned int pSeq1; // [esp+1A8h] [ebp-48h]
  int pSeq1_4; // [esp+1ACh] [ebp-44h]
  ParticleFullRenderData_Scalar_View **pXYZ; // [esp+1B0h] [ebp-40h]
  __m128 *pXYZ_4; // [esp+1B4h] [ebp-3Ch]
  unsigned int pXYZ_8; // [esp+1B8h] [ebp-38h]
  int v66; // [esp+1BCh] [ebp-34h]
  int pRGB; // [esp+1C0h] [ebp-30h]
  bool m_bUseVisibility; // [esp+1E3h] [ebp-Dh]

  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    pSeq1_4 = 0;
  pXYZ_8 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pXYZ_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pXYZ_8 != 0 )
    v66 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
        - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    v66 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pRot_8 = 0;
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pAlpha_4 != 0 )
    pAlpha_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
             - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pAlpha_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  pYaw_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pRadius_8 = 0;
  v7 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  v43 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( v7 != 0 )
    v44 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
        - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    v44 = 0;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v38 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pRGB = pParticles->m_nActiveParticles;
  v41 = 48 * pSeq1;
  v26 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4AlphaVis_4 = _mm_shuffle_ps(
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    0);
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  m_bUseVisibility = pVisibilityData->m_bUseVisibility;
  v42 = 48 * pXYZ_8;
  v39 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v8 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v40 = 16 * v7;
  v37 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v9 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  v10 = (__m128 *)((char *)pXYZ_4 + v66 + 16);
  pXYZ = pIndexBuffer + 2;
  v11 = pOutbuf + 8;
  do
  {
    *(pXYZ - 2) = (ParticleFullRenderData_Scalar_View *)(v11 - 8);
    *pXYZ = (ParticleFullRenderData_Scalar_View *)v11;
    *(pXYZ - 1) = (ParticleFullRenderData_Scalar_View *)(v11 - 4);
    pXYZ[1] = (ParticleFullRenderData_Scalar_View *)(v11 + 4);
    v12 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pAlpha, *(__m128 *)((char *)pAlpha + pAlpha_8)), v8),
              *(__m128 *)((char *)pAlpha + pAlpha_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v8),
              *(__m128 *)((char *)pRot + pRot_8)));
    v13 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*pYaw_8, *(__m128 *)((char *)pYaw_8 + pSeq_4)), v8),
            *(__m128 *)((char *)pYaw_8 + pSeq_4));
    fl4FinalRadius_4 = v12;
    fl4AlphaScale_4 = v13;
    if ( m_bUseVisibility )
    {
      fl4FinalRadius_4 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v12, Four_256s_4)));
      fl4AlphaScale_4 = _mm_mul_ps(v13, EyePos_36);
    }
    v14 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, v9[-1]), v8), v9[-1]);
    v15 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 + 32 - (pSeq1_4 + 16)), v9[1]), v8), v9[1]);
    v16 = _mm_sub_ps(v14, v26);
    v17 = _mm_sub_ps(v15, EyePos_20);
    v18 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 - pSeq1_4), *v9), v8), *v9);
    *(__m128 *)(v11 + 8) = v14;
    v19 = _mm_sub_ps(v18, EyePos_4);
    *(__m128 *)(v11 + 40) = v15;
    v20 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v17, v17), _mm_mul_ps(v19, v19)), _mm_mul_ps(v16, v16));
    v21 = *(__m128 *)v38;
    *(__m128 *)(v11 + 24) = v18;
    *(__m128 *)(v11 + 72) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pXYZ_4, v10[-1]), v8), v10[-1]),
                                fl4MaximumCreationTimeToDraw_4),
                              Four_2ToThe23s);
    *(__m128 *)(v11 + 88) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v10 - v66), *v10), v8), *v10),
                                fl4MaximumCreationTimeToDraw_4),
                              Four_2ToThe23s);
    v22 = _mm_mul_ps(
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v10 + 32 - (v66 + 16)), v10[1]), v8), v10[1]),
            fl4MaximumCreationTimeToDraw_4);
    v23 = _mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v11 + 56) = _mm_and_ps(
                              _mm_add_ps(_mm_mul_ps(fl4FinalRadius_4, fl4MaximumCreationTimeToDraw_4), Four_2ToThe23s),
                              _mm_cmplt_ps(v21, fl4CurTime_4));
    *(__m128 *)(v11 + 120) = fl4AlphaScale_4;
    v24 = _mm_add_ps(_mm_mul_ps(v23, v8), *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v11 - 8) = v20;
    *(__m128 *)(v11 + 104) = _mm_add_ps(v22, Four_2ToThe23s);
    *(__m128 *)(v11 + 136) = _mm_sub_ps(fl4AlphaVis_4, v21);
    *(__m128 *)(v11 + 168) = v24;
    *(__m128 *)(v11 + 184) = _mm_add_ps(
                               _mm_mul_ps(_mm_sub_ps(*v43, *(__m128 *)((char *)v43 + v44)), v8),
                               *(__m128 *)((char *)v43 + v44));
    if ( pAlpha2_4 != 0 )
      v25 = _mm_add_ps(_mm_mul_ps(*pAlpha2, fl4RadVis_4), *pYaw);
    else
      v25 = *pYaw;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v41);
    pRot += pRot_4;
    pYaw_8 += pSeq;
    pRadius += pRadius_4;
    pRGB -= 4;
    pXYZ += 4;
    pAlpha2 += pAlpha2_4;
    v9 = (__m128 *)((char *)v9 + v41);
    pAlpha += pAlpha_4;
    pXYZ_4 = (__m128 *)((char *)pXYZ_4 + v42);
    v10 = (__m128 *)((char *)v10 + v42);
    v43 = (__m128 *)((char *)v43 + v40);
    pYaw = (__m128 *)((char *)pYaw + v39);
    v38 = (float *)((char *)v38 + v37);
    *(__m128 *)(v11 + 152) = _mm_add_ps(v25, Four_2ToThe23s);
    v11 += 208;
  }
  while ( pRGB > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10359940
// Name: void GenerateExtendedData<1,0,0,struct ParticleFullRenderData_SIMD_View,0,0,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,0,ParticleFullRenderData_SIMD_View,0,0,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 v6; // xmm4
  ParticleFullRenderData_Scalar_View **v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // edi
  char *v10; // eax
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __int128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // [esp-Ch] [ebp-10Ch]
  __m128 EyePos_4; // [esp+4h] [ebp-FCh]
  __m128 EyePos_20; // [esp+14h] [ebp-ECh]
  __m128 EyePos_36; // [esp+24h] [ebp-DCh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-CCh]
  __m128 Four_256s_4; // [esp+44h] [ebp-BCh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-ACh]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-9Ch]
  unsigned int fl4FinalRadius_12; // [esp+7Ch] [ebp-84h]
  unsigned int v30; // [esp+80h] [ebp-80h]
  unsigned int v31; // [esp+84h] [ebp-7Ch]
  unsigned int v32; // [esp+88h] [ebp-78h]
  unsigned int v33; // [esp+8Ch] [ebp-74h]
  __m128 *v34; // [esp+90h] [ebp-70h]
  unsigned int v35; // [esp+98h] [ebp-68h]
  __m128 *pRadius; // [esp+9Ch] [ebp-64h]
  __m128 *v37; // [esp+A4h] [ebp-5Ch]
  unsigned int pAlpha2_4; // [esp+ACh] [ebp-54h]
  float *pAlpha; // [esp+B0h] [ebp-50h]
  float *v40; // [esp+B8h] [ebp-48h]
  float *pXYZ_4; // [esp+C0h] [ebp-40h]
  __m128 *pRot_4; // [esp+C8h] [ebp-38h]
  __m128 *pYaw_4; // [esp+D0h] [ebp-30h]
  __m128 *pCreationTimeStamp_4; // [esp+D8h] [ebp-28h]
  unsigned int pRGB; // [esp+DCh] [ebp-24h]
  __m128 *pRGB_4; // [esp+E0h] [ebp-20h]
  ParticleFullRenderData_Scalar_View **pSeq1_4; // [esp+E8h] [ebp-18h]
  int pSeq; // [esp+ECh] [ebp-14h]
  bool pSeq_7; // [esp+F3h] [ebp-Dh]

  pAlpha = pParticles->m_ParticleAttributes.m_pAttributes[0];
  pYaw_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  v37 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  v34 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  v40 = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pXYZ_4 = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  fl4AlphaVis_4 = pParticles->m_fl4CurTime;
  pRGB = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  pCreationTimeStamp_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v21 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  pRot_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  pSeq_7 = pVisibilityData->m_bUseVisibility;
  pSeq = pParticles->m_nActiveParticles;
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  v6 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v32 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  pAlpha2_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2);
  v31 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2);
  v33 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v30 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  fl4FinalRadius_12 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v7 = pIndexBuffer + 2;
  v8 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  v9 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC);
  v35 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  pSeq1_4 = pIndexBuffer + 2;
  v10 = pOutbuf + 8;
  while ( 1 )
  {
    *(v7 - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *(v7 - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    *v7 = (ParticleFullRenderData_Scalar_View *)v10;
    v7[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v11 = _mm_mul_ps(*v37, *pRadius);
    fl4CurTime_4 = *v34;
    if ( pSeq_7 )
    {
      v11 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, Four_256s_4)));
      fl4CurTime_4 = _mm_mul_ps(*v34, EyePos_36);
    }
    v12 = *(__m128 *)(pAlpha + 4);
    v13 = *(__m128 *)pAlpha;
    v14 = _mm_sub_ps(*(__m128 *)(pAlpha + 8), EyePos_20);
    v15 = _mm_sub_ps(v12, EyePos_4);
    v16 = _mm_sub_ps(*(__m128 *)pAlpha, v21);
    v17 = _mm_add_ps(_mm_mul_ps(v14, v14), _mm_mul_ps(v15, v15));
    v18 = _mm_mul_ps(*pYaw_4, v6);
    *(_OWORD *)(v10 + 40) = *((_OWORD *)pAlpha + 2);
    *(__m128 *)(v10 + 72) = _mm_add_ps(v18, Four_2ToThe23s);
    *(__m128 *)(v10 + 88) = _mm_add_ps(_mm_mul_ps(pYaw_4[1], v6), Four_2ToThe23s);
    *(__m128 *)(v10 + 104) = _mm_add_ps(_mm_mul_ps(pYaw_4[2], v6), Four_2ToThe23s);
    *(__m128 *)(v10 + 120) = fl4CurTime_4;
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4AlphaVis_4, *pRot_4);
    *(_OWORD *)(v10 + 168) = *(_OWORD *)v40;
    v19 = *(_OWORD *)pXYZ_4;
    *(__m128 *)(v10 - 8) = _mm_add_ps(v17, _mm_mul_ps(v16, v16));
    *(__m128 *)(v10 + 8) = v13;
    *(__m128 *)(v10 + 24) = v12;
    *(__m128 *)(v10 + 56) = _mm_add_ps(_mm_mul_ps(v11, v6), Four_2ToThe23s);
    *(_OWORD *)(v10 + 184) = v19;
    if ( pRGB != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pCreationTimeStamp_4, fl4RadVis_4), *pRGB_4);
    else
      v20 = *pRGB_4;
    pSeq -= 4;
    pSeq1_4 += 4;
    pYaw_4 = (__m128 *)((char *)pYaw_4 + v9);
    pAlpha = (float *)((char *)pAlpha + v8);
    v37 = (__m128 *)((char *)v37 + v32);
    pRadius = (__m128 *)((char *)pRadius + v35);
    v34 = (__m128 *)((char *)v34 + v30);
    pXYZ_4 = (float *)((char *)pXYZ_4 + pAlpha2_4);
    v40 = (float *)((char *)v40 + v31);
    pRGB_4 = (__m128 *)((char *)pRGB_4 + v33);
    pCreationTimeStamp_4 += pRGB;
    pRot_4 = (__m128 *)((char *)pRot_4 + fl4FinalRadius_12);
    *(__m128 *)(v10 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    v10 += 208;
    if ( pSeq <= 0 )
      break;
    v7 = pSeq1_4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10359CD0
// Name: void GenerateExtendedData<0,0,1,struct ParticleFullRenderData_SIMD_View,0,0,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,1,ParticleFullRenderData_SIMD_View,0,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  int v7; // edx
  int v8; // edx
  char *v9; // eax
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 *v12; // esi
  __m128 *v13; // ecx
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm6
  __m128 v17; // xmm7
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // [esp-Ch] [ebp-1BCh]
  __m128 Four_256s_4; // [esp+4h] [ebp-1ACh]
  __m128 fl4RadVis_4; // [esp+14h] [ebp-19Ch]
  __m128 fl4CurTime_4; // [esp+24h] [ebp-18Ch]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+34h] [ebp-17Ch]
  unsigned int fl4AlphaVis_8; // [esp+48h] [ebp-168h]
  unsigned int fl4AlphaVis_12; // [esp+4Ch] [ebp-164h]
  int v30; // [esp+6Ch] [ebp-144h]
  int v31; // [esp+F0h] [ebp-C0h]
  float *v32; // [esp+128h] [ebp-88h]
  __m128 *pCreationTimeStamp; // [esp+134h] [ebp-7Ch]
  __m128 *v34; // [esp+13Ch] [ebp-74h]
  unsigned int pSeq; // [esp+140h] [ebp-70h]
  int pSeq_4; // [esp+144h] [ebp-6Ch]
  __m128 *pRadius; // [esp+148h] [ebp-68h]
  unsigned int pRadius_4; // [esp+14Ch] [ebp-64h]
  int pRadius_8; // [esp+150h] [ebp-60h]
  __m128 *pYaw; // [esp+154h] [ebp-5Ch]
  unsigned int pYaw_4; // [esp+158h] [ebp-58h]
  int pYaw_8; // [esp+15Ch] [ebp-54h]
  __m128 *pAlpha; // [esp+160h] [ebp-50h]
  unsigned int pAlpha_4; // [esp+164h] [ebp-4Ch]
  int pAlpha_8; // [esp+168h] [ebp-48h]
  __m128 *pRot; // [esp+16Ch] [ebp-44h]
  unsigned int pRot_4; // [esp+170h] [ebp-40h]
  int pRot_8; // [esp+174h] [ebp-3Ch]
  __m128 *pAlpha2; // [esp+178h] [ebp-38h]
  unsigned int pAlpha2_4; // [esp+17Ch] [ebp-34h]
  int pAlpha2_8; // [esp+180h] [ebp-30h]
  __m128 *pRGB; // [esp+184h] [ebp-2Ch]
  unsigned int pRGB_4; // [esp+188h] [ebp-28h]
  __m128 *pRGB_8; // [esp+18Ch] [ebp-24h]
  unsigned int pSeq1; // [esp+190h] [ebp-20h]
  int pSeq1_4; // [esp+194h] [ebp-1Ch]
  int pXYZ; // [esp+198h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pXYZ_4; // [esp+19Ch] [ebp-14h]
  bool pXYZ_11; // [esp+1A3h] [ebp-Dh]

  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    pSeq1_4 = 0;
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pAlpha2_4 != 0 )
    v7 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
       - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    v7 = 0;
  pAlpha2_8 = v7;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v34 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pAlpha_4 != 0 )
    pAlpha_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
             - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pAlpha_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  v32 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pXYZ = pParticles->m_nActiveParticles;
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  fl4RadVis_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  0);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps(
                                     (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                                     (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                                     0);
  v30 = 48 * pSeq1;
  fl4AlphaVis_8 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v31 = 48 * pAlpha2_4;
  fl4AlphaVis_12 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  v8 = v7 + 16;
  pXYZ_11 = pVisibilityData->m_bUseVisibility;
  pXYZ_4 = pIndexBuffer + 2;
  v23 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v9 = pOutbuf + 8;
  v10 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  0);
  v11 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v12 = (__m128 *)((char *)pRGB_8 + pSeq1_4 + 16);
  v13 = (__m128 *)((char *)pAlpha2 + v8);
  do
  {
    *(pXYZ_4 - 2) = (ParticleFullRenderData_Scalar_View *)(v9 - 8);
    *pXYZ_4 = (ParticleFullRenderData_Scalar_View *)v9;
    *(pXYZ_4 - 1) = (ParticleFullRenderData_Scalar_View *)(v9 - 4);
    pXYZ_4[1] = (ParticleFullRenderData_Scalar_View *)(v9 + 4);
    v14 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v34, *(__m128 *)((char *)v34 + pSeq_4)), v10),
            *(__m128 *)((char *)v34 + pSeq_4));
    v15 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v10),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v10),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    if ( pXYZ_11 )
    {
      v14 = _mm_mul_ps(v14, Four_256s_4);
      v15 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v15, fl4MaximumCreationTimeToDraw_4)));
    }
    v16 = v12[1];
    v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB_8, v12[-1]), v10), v12[-1]);
    *(__m128 *)(v9 + 24) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v12 - pSeq1_4), *v12), v10), *v12);
    v18 = *(__m128 *)v32;
    *(__m128 *)(v9 + 40) = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v12 + 32 - (pSeq1_4 + 16)), v16), v10),
                             v16);
    *(__m128 *)(v9 + 56) = _mm_and_ps(_mm_add_ps(_mm_mul_ps(v15, v11), Four_2ToThe23s), _mm_cmplt_ps(v18, fl4CurTime_4));
    *(__m128 *)(v9 + 72) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_sub_ps(*pAlpha2, *(__m128 *)((char *)v13 + pAlpha2_8 - v8)), v10),
                                 *(__m128 *)((char *)v13 + pAlpha2_8 - v8)),
                               v11),
                             Four_2ToThe23s);
    v19 = *(__m128 *)((char *)v13 + pAlpha2_8 - v8 + 32);
    *(__m128 *)(v9 + 88) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v13 + 16 - v8), *v13), v10), *v13),
                               v11),
                             Four_2ToThe23s);
    v20 = *(__m128 *)((char *)v13 + 32 - v8);
    *(__m128 *)(v9 + 120) = v14;
    *(__m128 *)(v9 + 168) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(*pAlpha, *(__m128 *)((char *)pAlpha + pAlpha_8)), v10),
                              *(__m128 *)((char *)pAlpha + pAlpha_8));
    v21 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v10),
            *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v9 + 8) = v17;
    *(__m128 *)(v9 + 104) = _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(v20, v19), v10), v19), v11),
                              Four_2ToThe23s);
    *(__m128 *)(v9 + 136) = _mm_sub_ps(fl4RadVis_4, v18);
    *(__m128 *)(v9 + 184) = v21;
    if ( pRGB_4 != 0 )
      v22 = _mm_add_ps(_mm_mul_ps(*pRGB, v23), *pCreationTimeStamp);
    else
      v22 = *pCreationTimeStamp;
    pRGB_8 = (__m128 *)((char *)pRGB_8 + v30);
    v12 = (__m128 *)((char *)v12 + v30);
    pYaw += pYaw_4;
    pRot += pRot_4;
    v34 += pSeq;
    pAlpha2 = (__m128 *)((char *)pAlpha2 + v31);
    pXYZ -= 4;
    pXYZ_4 += 4;
    v13 = (__m128 *)((char *)v13 + v31);
    pRadius += pRadius_4;
    pAlpha += pAlpha_4;
    pCreationTimeStamp = (__m128 *)((char *)pCreationTimeStamp + fl4AlphaVis_8);
    pRGB += pRGB_4;
    v32 = (float *)((char *)v32 + fl4AlphaVis_12);
    *(__m128 *)(v9 + 152) = _mm_add_ps(v22, Four_2ToThe23s);
    v9 += 208;
  }
  while ( pXYZ > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1035A230
// Name: void GenerateExtendedData<0,0,0,struct ParticleFullRenderData_SIMD_View,0,0,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,0,ParticleFullRenderData_SIMD_View,0,0,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  unsigned int v6; // eax
  __m128 m_fl4CurTime; // xmm4
  unsigned int v8; // esi
  unsigned int v9; // edi
  __m128 v10; // xmm7
  int m_nActiveParticles; // edx
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  ParticleFullRenderData_Scalar_View **v15; // edx
  char *v16; // eax
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __int128 v19; // xmm0
  __m128 v20; // xmm0
  float *pRadius; // [esp+8h] [ebp-74h]
  __m128 *pAlpha2; // [esp+10h] [ebp-6Ch]
  __m128 *pAlpha; // [esp+18h] [ebp-64h]
  float *pXYZ; // [esp+20h] [ebp-5Ch]
  unsigned int pXYZ_4; // [esp+24h] [ebp-58h]
  __m128 *pCreationTimeStamp; // [esp+28h] [ebp-54h]
  unsigned int pCreationTimeStamp_4; // [esp+2Ch] [ebp-50h]
  float *pRot; // [esp+30h] [ebp-4Ch]
  unsigned int pRot_4; // [esp+34h] [ebp-48h]
  float *pYaw; // [esp+38h] [ebp-44h]
  unsigned int pYaw_4; // [esp+3Ch] [ebp-40h]
  __m128 *pRGB; // [esp+40h] [ebp-3Ch]
  unsigned int pRGB_4; // [esp+44h] [ebp-38h]
  __m128 *pSeq1; // [esp+48h] [ebp-34h]
  unsigned int pSeq1_4; // [esp+4Ch] [ebp-30h]
  __m128 *pSeq; // [esp+50h] [ebp-2Ch]
  unsigned int pSeq_4; // [esp+54h] [ebp-28h]
  int v38; // [esp+74h] [ebp-8h]
  int nParticles; // [esp+78h] [ebp-4h]
  CParticleVisibilityData *pVisibilityDataa; // [esp+9Ch] [ebp+20h]
  bool bUseVis_3; // [esp+A3h] [ebp+27h]

  pXYZ_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pXYZ = pParticles->m_ParticleAttributes.m_pAttributes[0];
  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  pRadius = pParticles->m_ParticleAttributes.m_pAttributes[3];
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pRot = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  v6 = pParticles->m_ParticleAttributes.m_nFloatStrides[7];
  m_fl4CurTime = pParticles->m_fl4CurTime;
  pYaw = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pSeq_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2;
  pSeq = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pSeq1_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pSeq1 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v8 = pParticles->m_ParticleAttributes.m_nFloatStrides[16];
  v9 = pParticles->m_ParticleAttributes.m_nFloatStrides[3];
  pCreationTimeStamp_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2;
  v10 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v12 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
          (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
          0);
  bUseVis_3 = pVisibilityData->m_bUseVisibility;
  v13 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          0);
  nParticles = m_nActiveParticles;
  v14 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v38 = 16 * (v6 >> 2);
  v15 = pIndexBuffer + 2;
  pVisibilityDataa = (CParticleVisibilityData *)(pIndexBuffer + 2);
  v16 = pOutbuf + 8;
  while ( 1 )
  {
    *(v15 - 2) = (ParticleFullRenderData_Scalar_View *)(v16 - 8);
    *(v15 - 1) = (ParticleFullRenderData_Scalar_View *)(v16 - 4);
    *v15 = (ParticleFullRenderData_Scalar_View *)v16;
    v15[1] = (ParticleFullRenderData_Scalar_View *)(v16 + 4);
    v17 = _mm_mul_ps(*pAlpha, *pAlpha2);
    v18 = *(__m128 *)pRadius;
    if ( bUseVis_3 )
    {
      v17 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v17, v12)));
      v18 = _mm_mul_ps(v18, v13);
    }
    *(_OWORD *)(v16 + 8) = *(_OWORD *)pXYZ;
    *(_OWORD *)(v16 + 24) = *((_OWORD *)pXYZ + 1);
    *(_OWORD *)(v16 + 40) = *((_OWORD *)pXYZ + 2);
    *(__m128 *)(v16 + 56) = _mm_add_ps(_mm_mul_ps(v17, v14), Four_2ToThe23s);
    *(__m128 *)(v16 + 72) = _mm_add_ps(_mm_mul_ps(*pRGB, v14), Four_2ToThe23s);
    *(__m128 *)(v16 + 88) = _mm_add_ps(_mm_mul_ps(pRGB[1], v14), Four_2ToThe23s);
    *(__m128 *)(v16 + 104) = _mm_add_ps(_mm_mul_ps(pRGB[2], v14), Four_2ToThe23s);
    *(__m128 *)(v16 + 136) = _mm_sub_ps(m_fl4CurTime, *pCreationTimeStamp);
    *(_OWORD *)(v16 + 168) = *(_OWORD *)pRot;
    v19 = *(_OWORD *)pYaw;
    *(__m128 *)(v16 + 120) = v18;
    *(_OWORD *)(v16 + 184) = v19;
    if ( pSeq1_4 != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pSeq1, v10), *pSeq);
    else
      v20 = *pSeq;
    nParticles -= 4;
    pVisibilityDataa = (CParticleVisibilityData *)((char *)pVisibilityDataa + 16);
    pRGB += 3 * pRGB_4;
    pXYZ += 12 * pXYZ_4;
    pAlpha = (__m128 *)((char *)pAlpha + v38);
    pAlpha2 += v8 >> 2;
    pRadius += 4 * (v9 >> 2);
    pYaw += 4 * pYaw_4;
    pRot += 4 * pRot_4;
    pSeq += pSeq_4;
    pSeq1 += pSeq1_4;
    pCreationTimeStamp += pCreationTimeStamp_4;
    *(__m128 *)(v16 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    v16 += 208;
    if ( nParticles <= 0 )
      break;
    v15 = (ParticleFullRenderData_Scalar_View **)pVisibilityDataa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035A510
// Name: void std::_Adjust_heap<struct ParticleFullRenderData_Scalar_View __near * __near *,int,struct ParticleFullRenderData_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleFullRenderData_Scalar_View __near * __near *,int,int,struct ParticleFullRenderData_Scalar_View __near * __near &&,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleFullRenderData_Scalar_View **_First,
        int _Hole,
        int _Bottom,
        const ParticleFullRenderData_Scalar_View *const *_Val,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  ParticleFullRenderData_Scalar_View *v9; // edx
  int v10; // esi
  int v11; // ecx
  int _Holeb; // [esp+1Ch] [ebp+Ch]
  int _Holea; // [esp+1Ch] [ebp+Ch]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: (const ParticleFullRenderData_Scalar_View *const *)&_First[v7 - 1]) )
        --v7;
      v9 = _First[v7];
      _Holeb = v7;
      v7 = 2 * v7 + 2;
      _First[v6] = v9;
      v6 = _Holeb;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  v10 = (v6 - 1) / 2;
  _Holea = v6;
  if ( _Hole >= v6 )
  {
    _First[v6] = (ParticleFullRenderData_Scalar_View *)*_Val;
  }
  else
  {
    while ( _Pred(a1: &_First[v10], a2: _Val) )
    {
      _First[_Holea] = _First[v10];
      v11 = v10;
      _Holea = v10;
      v10 = (v10 - 1) / 2;
      if ( _Hole >= _Holea )
      {
        _First[v11] = (ParticleFullRenderData_Scalar_View *)*_Val;
        return;
      }
    }
    _First[_Holea] = (ParticleFullRenderData_Scalar_View *)*_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035A5E0
// Name: void GenerateExtendedData<1,0,1,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  int v7; // eax
  __m128 v8; // xmm0
  __m128 *v9; // esi
  char *v10; // eax
  __m128 *v11; // edi
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __int128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // [esp-Ch] [ebp-2CCh]
  __m128 EyePos_4; // [esp+4h] [ebp-2BCh]
  __m128 EyePos_20; // [esp+14h] [ebp-2ACh]
  __m128 EyePos_36; // [esp+24h] [ebp-29Ch]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-28Ch]
  __m128 Four_256s_4; // [esp+44h] [ebp-27Ch]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-26Ch]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-25Ch]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+74h] [ebp-24Ch]
  __m128 fl4AlphaScale_4; // [esp+84h] [ebp-23Ch]
  __m128 fl4FinalRadius_4; // [esp+94h] [ebp-22Ch]
  unsigned int v44; // [esp+D8h] [ebp-1E8h]
  unsigned int v45; // [esp+E0h] [ebp-1E0h]
  float *v46; // [esp+100h] [ebp-1C0h]
  float *v47; // [esp+108h] [ebp-1B8h]
  unsigned int pCreationTimeStamp; // [esp+10Ch] [ebp-1B4h]
  int v49; // [esp+180h] [ebp-140h]
  int v50; // [esp+1C0h] [ebp-100h]
  int v51; // [esp+1E0h] [ebp-E0h]
  int v52; // [esp+1F4h] [ebp-CCh]
  __m128 *v53; // [esp+21Ch] [ebp-A4h]
  __m128 *v54; // [esp+224h] [ebp-9Ch]
  unsigned int pSeq; // [esp+228h] [ebp-98h]
  int pSeq_4; // [esp+22Ch] [ebp-94h]
  __m128 *pRadius; // [esp+230h] [ebp-90h]
  unsigned int pRadius_4; // [esp+234h] [ebp-8Ch]
  int pRadius_8; // [esp+238h] [ebp-88h]
  __m128 *pYaw; // [esp+23Ch] [ebp-84h]
  unsigned int pYaw_4; // [esp+240h] [ebp-80h]
  int pYaw_8; // [esp+244h] [ebp-7Ch]
  __m128 *pAlpha; // [esp+248h] [ebp-78h]
  unsigned int pAlpha_4; // [esp+24Ch] [ebp-74h]
  int pAlpha_8; // [esp+250h] [ebp-70h]
  __m128 *pRGB2; // [esp+254h] [ebp-6Ch]
  unsigned int pRGB2_4; // [esp+258h] [ebp-68h]
  int pRGB2_8; // [esp+25Ch] [ebp-64h]
  __m128 *pRot; // [esp+260h] [ebp-60h]
  unsigned int pRot_4; // [esp+264h] [ebp-5Ch]
  int pRot_8; // [esp+268h] [ebp-58h]
  __m128 *pAlpha2; // [esp+26Ch] [ebp-54h]
  unsigned int pAlpha2_4; // [esp+270h] [ebp-50h]
  __m128 *pAlpha2_8; // [esp+274h] [ebp-4Ch]
  unsigned int pSeq1; // [esp+278h] [ebp-48h]
  int pSeq1_4; // [esp+27Ch] [ebp-44h]
  __m128 *pRGB; // [esp+280h] [ebp-40h]
  unsigned int pRGB_4; // [esp+284h] [ebp-3Ch]
  int pRGB_8; // [esp+288h] [ebp-38h]
  int pXYZ; // [esp+28Ch] [ebp-34h]
  ParticleFullRenderData_Scalar_View **pXYZ_4; // [esp+290h] [ebp-30h]
  __m128 *pXYZ_8; // [esp+294h] [ebp-2Ch]
  bool m_bUseVisibility; // [esp+2B3h] [ebp-Dh]

  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pRGB_4 != 0 )
    pRGB_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    pRGB_8 = 0;
  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    pSeq1_4 = 0;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v54 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pRGB2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pRGB2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pRGB2_4 != 0 )
    pRGB2_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pRGB2_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  v53 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v46 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pCreationTimeStamp = pParticles->m_ParticleAttributes.m_nFloatStrides[23] >> 2;
  v47 = pParticles->m_ParticleAttributes.m_pAttributes[23];
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[22] / 0xC;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[22];
  if ( pAlpha_4 != 0 )
    v7 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[22]
       - (char *)pParticles->m_ParticleAttributes.m_pAttributes[22];
  else
    v7 = 0;
  pAlpha_8 = v7;
  v51 = 48 * pAlpha_4;
  v50 = 48 * pRGB_4;
  v33 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  v49 = 48 * pSeq1;
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4AlphaVis_4 = _mm_shuffle_ps(
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    0);
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  pXYZ = pParticles->m_nActiveParticles;
  m_bUseVisibility = pVisibilityData->m_bUseVisibility;
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v8 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v45 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v44 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  pXYZ_4 = pIndexBuffer + 2;
  v9 = (__m128 *)((char *)pAlpha + v7 + 16);
  pXYZ_8 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  v52 = -v7;
  v10 = pOutbuf + 8;
  v11 = (__m128 *)((char *)pRGB + pRGB_8 + 16);
  do
  {
    *(pXYZ_4 - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *pXYZ_4 = (ParticleFullRenderData_Scalar_View *)v10;
    *(pXYZ_4 - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    pXYZ_4[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v12 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v8),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v8),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    v13 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v54, *(__m128 *)((char *)v54 + pSeq_4)), v8),
            *(__m128 *)((char *)v54 + pSeq_4));
    fl4FinalRadius_4 = v12;
    fl4AlphaScale_4 = v13;
    if ( m_bUseVisibility )
    {
      fl4FinalRadius_4 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v12, Four_256s_4)));
      fl4AlphaScale_4 = _mm_mul_ps(v13, EyePos_36);
    }
    v14 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB, v11[-1]), v8), v11[-1]);
    v15 = _mm_sub_ps(*(__m128 *)((char *)v11 - pRGB_8), *v11);
    v16 = _mm_sub_ps(v14, v33);
    v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v11 + 32 - (pRGB_8 + 16)), v11[1]), v8), v11[1]);
    *(__m128 *)(v10 + 8) = v14;
    v18 = _mm_add_ps(_mm_mul_ps(v15, v8), *v11);
    v19 = _mm_sub_ps(v17, EyePos_20);
    v20 = _mm_sub_ps(v18, EyePos_4);
    *(__m128 *)(v10 + 40) = v17;
    v21 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v19, v19), _mm_mul_ps(v20, v20)), _mm_mul_ps(v16, v16));
    v22 = *(__m128 *)v46;
    *(__m128 *)(v10 + 24) = v18;
    *(__m128 *)(v10 + 56) = _mm_and_ps(
                              _mm_add_ps(_mm_mul_ps(fl4FinalRadius_4, fl4MaximumCreationTimeToDraw_4), Four_2ToThe23s),
                              _mm_cmplt_ps(v22, fl4CurTime_4));
    *(__m128 *)(v10 + 72) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, pXYZ_8[-1]), v8), pXYZ_8[-1]),
                                fl4MaximumCreationTimeToDraw_4),
                              Four_2ToThe23s);
    v23 = pXYZ_8[1];
    *(__m128 *)(v10 + 88) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)pXYZ_8 - pSeq1_4), *pXYZ_8), v8),
                                  *pXYZ_8),
                                fl4MaximumCreationTimeToDraw_4),
                              Four_2ToThe23s);
    v24 = _mm_mul_ps(
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)pXYZ_8 + 32 - (pSeq1_4 + 16)), v23), v8), v23),
            fl4MaximumCreationTimeToDraw_4);
    v25 = _mm_sub_ps(*pRGB2, *(__m128 *)((char *)pRGB2 + pRGB2_8));
    *(__m128 *)(v10 + 120) = fl4AlphaScale_4;
    *(__m128 *)(v10 - 8) = v21;
    *(__m128 *)(v10 + 104) = _mm_add_ps(v24, Four_2ToThe23s);
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4AlphaVis_4, v22);
    *(__m128 *)(v10 + 168) = _mm_add_ps(_mm_mul_ps(v25, v8), *(__m128 *)((char *)pRGB2 + pRGB2_8));
    *(__m128 *)(v10 + 184) = _mm_add_ps(
                               _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v8),
                               *(__m128 *)((char *)pRadius + pRadius_8));
    if ( pAlpha2_4 != 0 )
      v26 = _mm_add_ps(_mm_mul_ps(*pAlpha2, fl4RadVis_4), *v53);
    else
      v26 = *v53;
    v27 = v9[-1];
    v28 = _mm_sub_ps(*pAlpha, v27);
    *(__m128 *)(v10 + 152) = _mm_add_ps(v26, Four_2ToThe23s);
    v29 = _mm_add_ps(_mm_mul_ps(v28, v8), v27);
    pXYZ -= 4;
    pXYZ_4 += 4;
    v30 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 + 32 - (pAlpha_8 + 16)), v9[1]), v8), v9[1]);
    v31 = *(_OWORD *)v47;
    pAlpha = (__m128 *)((char *)pAlpha + v51);
    v47 += 4 * pCreationTimeStamp;
    pRGB = (__m128 *)((char *)pRGB + v50);
    v11 = (__m128 *)((char *)v11 + v50);
    pRot += pRot_4;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v49);
    pXYZ_8 = (__m128 *)((char *)pXYZ_8 + v49);
    pRadius += pRadius_4;
    v53 = (__m128 *)((char *)v53 + v45);
    v46 = (float *)((char *)v46 + v44);
    v32 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 + v52), *v9), v8), *v9);
    v9 = (__m128 *)((char *)v9 + v51);
    pYaw += pYaw_4;
    v54 += pSeq;
    pRGB2 += pRGB2_4;
    pAlpha2 += pAlpha2_4;
    *(__m128 *)(v10 + 200) = v29;
    *(__m128 *)(v10 + 216) = v32;
    *(__m128 *)(v10 + 232) = v30;
    *(_OWORD *)(v10 + 248) = v31;
    v10 += 272;
  }
  while ( pXYZ > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1035AD50
// Name: void GenerateExtendedData<1,0,0,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  unsigned int v6; // kr04_4
  float *v7; // edx
  ParticleFullRenderData_Scalar_View **v8; // ecx
  __m128 v9; // xmm4
  char *v10; // eax
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __int128 v19; // xmm1
  __m128 v20; // xmm1
  __int128 v21; // xmm0
  __int128 v22; // xmm0
  __m128 v23; // [esp-Ch] [ebp-12Ch]
  __m128 EyePos_4; // [esp+4h] [ebp-11Ch]
  __m128 EyePos_20; // [esp+14h] [ebp-10Ch]
  __m128 EyePos_36; // [esp+24h] [ebp-FCh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-ECh]
  __m128 Four_256s_4; // [esp+44h] [ebp-DCh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-CCh]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-BCh]
  unsigned int v31; // [esp+80h] [ebp-A0h]
  unsigned int v32; // [esp+88h] [ebp-98h]
  unsigned int v33; // [esp+8Ch] [ebp-94h]
  unsigned int pRGB2; // [esp+90h] [ebp-90h]
  unsigned int pRGB2_4; // [esp+94h] [ebp-8Ch]
  unsigned int v36; // [esp+98h] [ebp-88h]
  __m128 *v37; // [esp+9Ch] [ebp-84h]
  unsigned int v38; // [esp+A4h] [ebp-7Ch]
  __m128 *pAlpha2; // [esp+A8h] [ebp-78h]
  unsigned int v40; // [esp+B0h] [ebp-70h]
  unsigned int pAlpha_4; // [esp+B8h] [ebp-68h]
  unsigned int v42; // [esp+BCh] [ebp-64h]
  float *v43; // [esp+C0h] [ebp-60h]
  float *v44; // [esp+C8h] [ebp-58h]
  __m128 *pGlowAlpha_4; // [esp+D0h] [ebp-50h]
  __m128 *pXYZ_4; // [esp+D8h] [ebp-48h]
  float *pRadius_4; // [esp+E0h] [ebp-40h]
  float *pCreationTimeStamp_4; // [esp+E8h] [ebp-38h]
  __m128 *pRot_4; // [esp+F0h] [ebp-30h]
  __m128 *pYaw_4; // [esp+F8h] [ebp-28h]
  __m128 *pRGB_4; // [esp+100h] [ebp-20h]
  unsigned int pSeq; // [esp+104h] [ebp-1Ch]
  int pSeq_4; // [esp+108h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pSeq1; // [esp+10Ch] [ebp-14h]
  bool pSeq1_7; // [esp+113h] [ebp-Dh]

  v44 = pParticles->m_ParticleAttributes.m_pAttributes[0];
  v6 = pParticles->m_ParticleAttributes.m_nFloatStrides[6];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pGlowAlpha_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  pCreationTimeStamp_4 = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pRot_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  v37 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  pRadius_4 = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pYaw_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  v43 = pParticles->m_ParticleAttributes.m_pAttributes[23];
  fl4AlphaVis_4 = pParticles->m_fl4CurTime;
  pXYZ_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v23 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  pSeq_4 = pParticles->m_nActiveParticles;
  v7 = pParticles->m_ParticleAttributes.m_pAttributes[22];
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  pRGB2_4 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[22] / 0xC);
  v33 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[23] >> 2);
  v40 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  v38 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v31 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2);
  pRGB2 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2);
  pAlpha_4 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v36 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  pSeq1_7 = pVisibilityData->m_bUseVisibility;
  v32 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v8 = pIndexBuffer + 2;
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  v9 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v42 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  pSeq1 = pIndexBuffer + 2;
  v10 = pOutbuf + 8;
  while ( 1 )
  {
    *(v8 - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *(v8 - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    *v8 = (ParticleFullRenderData_Scalar_View *)v10;
    v8[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v11 = _mm_mul_ps(*pAlpha2, *v37);
    fl4CurTime_4 = *pGlowAlpha_4;
    if ( pSeq1_7 )
    {
      v11 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, Four_256s_4)));
      fl4CurTime_4 = _mm_mul_ps(*pGlowAlpha_4, EyePos_36);
    }
    v12 = *(__m128 *)(v44 + 4);
    v13 = *(__m128 *)v44;
    v14 = _mm_sub_ps(*(__m128 *)(v44 + 8), EyePos_20);
    v15 = _mm_sub_ps(v12, EyePos_4);
    v16 = _mm_sub_ps(*(__m128 *)v44, v23);
    v17 = _mm_add_ps(_mm_mul_ps(v14, v14), _mm_mul_ps(v15, v15));
    v18 = _mm_mul_ps(*pRot_4, v9);
    *(_OWORD *)(v10 + 40) = *((_OWORD *)v44 + 2);
    *(__m128 *)(v10 + 72) = _mm_add_ps(v18, Four_2ToThe23s);
    *(__m128 *)(v10 + 88) = _mm_add_ps(_mm_mul_ps(pRot_4[1], v9), Four_2ToThe23s);
    *(__m128 *)(v10 + 104) = _mm_add_ps(_mm_mul_ps(pRot_4[2], v9), Four_2ToThe23s);
    *(__m128 *)(v10 + 120) = fl4CurTime_4;
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4AlphaVis_4, *pXYZ_4);
    *(_OWORD *)(v10 + 168) = *(_OWORD *)pRadius_4;
    v19 = *(_OWORD *)pCreationTimeStamp_4;
    *(__m128 *)(v10 - 8) = _mm_add_ps(v17, _mm_mul_ps(v16, v16));
    *(__m128 *)(v10 + 8) = v13;
    *(__m128 *)(v10 + 24) = v12;
    *(__m128 *)(v10 + 56) = _mm_add_ps(_mm_mul_ps(v11, v9), Four_2ToThe23s);
    *(_OWORD *)(v10 + 184) = v19;
    if ( pSeq != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pRGB_4, fl4RadVis_4), *pYaw_4);
    else
      v20 = *pYaw_4;
    pSeq_4 -= 4;
    pSeq1 += 4;
    pRot_4 += 3 * (v6 / 0xC);
    v44 = (float *)((char *)v44 + v40);
    pAlpha2 = (__m128 *)((char *)pAlpha2 + v42);
    v37 = (__m128 *)((char *)v37 + v36);
    pGlowAlpha_4 = (__m128 *)((char *)pGlowAlpha_4 + v38);
    pCreationTimeStamp_4 = (float *)((char *)pCreationTimeStamp_4 + v31);
    pRadius_4 = (float *)((char *)pRadius_4 + pRGB2);
    pYaw_4 = (__m128 *)((char *)pYaw_4 + pAlpha_4);
    pRGB_4 += pSeq;
    pXYZ_4 = (__m128 *)((char *)pXYZ_4 + v32);
    *(_OWORD *)(v10 + 200) = *(_OWORD *)v7;
    *(_OWORD *)(v10 + 216) = *((_OWORD *)v7 + 1);
    v21 = *((_OWORD *)v7 + 2);
    v7 = (float *)((char *)v7 + pRGB2_4);
    *(_OWORD *)(v10 + 232) = v21;
    v22 = *(_OWORD *)v43;
    *(__m128 *)(v10 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    *(_OWORD *)(v10 + 248) = v22;
    v10 += 272;
    v43 = (float *)((char *)v43 + v33);
    if ( pSeq_4 <= 0 )
      break;
    v8 = pSeq1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035B180
// Name: void GenerateExtendedData<0,0,1,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  int v7; // eax
  __m128 *v8; // esi
  char *v9; // eax
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 *v12; // edi
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm6
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm5
  __m128 v25; // xmm2
  __int128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // [esp-Ch] [ebp-26Ch]
  __m128 Four_256s_4; // [esp+4h] [ebp-25Ch]
  __m128 fl4RadVis_4; // [esp+14h] [ebp-24Ch]
  __m128 fl4CurTime_4; // [esp+24h] [ebp-23Ch]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+34h] [ebp-22Ch]
  unsigned int v33; // [esp+50h] [ebp-210h]
  unsigned int v34; // [esp+74h] [ebp-1ECh]
  float *v35; // [esp+78h] [ebp-1E8h]
  unsigned int v36; // [esp+7Ch] [ebp-1E4h]
  int v37; // [esp+130h] [ebp-130h]
  int v38; // [esp+170h] [ebp-F0h]
  int v39; // [esp+188h] [ebp-D8h]
  float *v40; // [esp+18Ch] [ebp-D4h]
  __m128 *v41; // [esp+1BCh] [ebp-A4h]
  __m128 *v42; // [esp+1C4h] [ebp-9Ch]
  unsigned int pSeq; // [esp+1C8h] [ebp-98h]
  int pSeq_4; // [esp+1CCh] [ebp-94h]
  __m128 *pRadius; // [esp+1D0h] [ebp-90h]
  unsigned int pRadius_4; // [esp+1D4h] [ebp-8Ch]
  int pRadius_8; // [esp+1D8h] [ebp-88h]
  __m128 *pYaw; // [esp+1DCh] [ebp-84h]
  unsigned int pYaw_4; // [esp+1E0h] [ebp-80h]
  int pYaw_8; // [esp+1E4h] [ebp-7Ch]
  __m128 *pAlpha; // [esp+1E8h] [ebp-78h]
  unsigned int pAlpha_4; // [esp+1ECh] [ebp-74h]
  int pAlpha_8; // [esp+1F0h] [ebp-70h]
  __m128 *pRGB2; // [esp+1F4h] [ebp-6Ch]
  unsigned int pRGB2_4; // [esp+1F8h] [ebp-68h]
  int pRGB2_8; // [esp+1FCh] [ebp-64h]
  __m128 *pRot; // [esp+200h] [ebp-60h]
  unsigned int pRot_4; // [esp+204h] [ebp-5Ch]
  int pRot_8; // [esp+208h] [ebp-58h]
  __m128 *pAlpha2; // [esp+20Ch] [ebp-54h]
  unsigned int pAlpha2_4; // [esp+210h] [ebp-50h]
  __m128 *pAlpha2_8; // [esp+214h] [ebp-4Ch]
  unsigned int pSeq1; // [esp+218h] [ebp-48h]
  int pSeq1_4; // [esp+21Ch] [ebp-44h]
  __m128 *pRGB; // [esp+220h] [ebp-40h]
  unsigned int pRGB_4; // [esp+224h] [ebp-3Ch]
  int pRGB_8; // [esp+228h] [ebp-38h]
  int pXYZ; // [esp+22Ch] [ebp-34h]
  ParticleFullRenderData_Scalar_View **pXYZ_4; // [esp+230h] [ebp-30h]
  __m128 *pXYZ_8; // [esp+234h] [ebp-2Ch]
  bool m_bUseVisibility; // [esp+253h] [ebp-Dh]

  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pRGB_4 != 0 )
    pRGB_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    pRGB_8 = 0;
  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    pSeq1_4 = 0;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v42 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pRGB2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pRGB2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pRGB2_4 != 0 )
    pRGB2_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pRGB2_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  v41 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v40 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v36 = pParticles->m_ParticleAttributes.m_nFloatStrides[23] >> 2;
  v35 = pParticles->m_ParticleAttributes.m_pAttributes[23];
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[22] / 0xC;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[22];
  if ( pAlpha_4 != 0 )
    v7 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[22]
       - (char *)pParticles->m_ParticleAttributes.m_pAttributes[22];
  else
    v7 = 0;
  pAlpha_8 = v7;
  v39 = 48 * pAlpha_4;
  v38 = 48 * pRGB_4;
  v37 = 48 * pSeq1;
  fl4RadVis_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  0);
  pXYZ = pParticles->m_nActiveParticles;
  v34 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps(
                                     (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                                     (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                                     0);
  v33 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v8 = (__m128 *)((char *)pAlpha + v7 + 16);
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  m_bUseVisibility = pVisibilityData->m_bUseVisibility;
  pXYZ_4 = pIndexBuffer + 2;
  pXYZ_8 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  v28 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v9 = pOutbuf + 8;
  v10 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  0);
  v11 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v12 = (__m128 *)((char *)pRGB + pRGB_8 + 16);
  do
  {
    *(pXYZ_4 - 2) = (ParticleFullRenderData_Scalar_View *)(v9 - 8);
    *pXYZ_4 = (ParticleFullRenderData_Scalar_View *)v9;
    *(pXYZ_4 - 1) = (ParticleFullRenderData_Scalar_View *)(v9 - 4);
    pXYZ_4[1] = (ParticleFullRenderData_Scalar_View *)(v9 + 4);
    v13 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v42, *(__m128 *)((char *)v42 + pSeq_4)), v10),
            *(__m128 *)((char *)v42 + pSeq_4));
    v14 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v10),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v10),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    if ( m_bUseVisibility )
    {
      v13 = _mm_mul_ps(v13, Four_256s_4);
      v14 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v14, fl4MaximumCreationTimeToDraw_4)));
    }
    v15 = v12[1];
    v16 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB, v12[-1]), v10), v12[-1]);
    v17 = *(__m128 *)v40;
    *(__m128 *)(v9 + 24) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v12 - pRGB_8), *v12), v10), *v12);
    *(__m128 *)(v9 + 40) = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v12 + 32 - (pRGB_8 + 16)), v15), v10),
                             v15);
    *(__m128 *)(v9 + 56) = _mm_and_ps(_mm_add_ps(_mm_mul_ps(v14, v11), Four_2ToThe23s), _mm_cmplt_ps(v17, fl4CurTime_4));
    *(__m128 *)(v9 + 72) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, pXYZ_8[-1]), v10), pXYZ_8[-1]),
                               v11),
                             Four_2ToThe23s);
    v18 = pXYZ_8[1];
    *(__m128 *)(v9 + 88) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)pXYZ_8 - pSeq1_4), *pXYZ_8), v10),
                                 *pXYZ_8),
                               v11),
                             Four_2ToThe23s);
    v19 = *(__m128 *)((char *)pXYZ_8 + 32 - (pSeq1_4 + 16));
    *(__m128 *)(v9 + 120) = v13;
    *(__m128 *)(v9 + 168) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(*pRGB2, *(__m128 *)((char *)pRGB2 + pRGB2_8)), v10),
                              *(__m128 *)((char *)pRGB2 + pRGB2_8));
    v20 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v10),
            *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v9 + 8) = v16;
    *(__m128 *)(v9 + 104) = _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(v19, v18), v10), v18), v11),
                              Four_2ToThe23s);
    *(__m128 *)(v9 + 136) = _mm_sub_ps(fl4RadVis_4, v17);
    *(__m128 *)(v9 + 184) = v20;
    if ( pAlpha2_4 != 0 )
      v21 = _mm_add_ps(_mm_mul_ps(*pAlpha2, v28), *v41);
    else
      v21 = *v41;
    v22 = v8[-1];
    v23 = _mm_sub_ps(*pAlpha, v22);
    *(__m128 *)(v9 + 152) = _mm_add_ps(v21, Four_2ToThe23s);
    v24 = _mm_add_ps(_mm_mul_ps(v23, v10), v22);
    pXYZ -= 4;
    pXYZ_4 += 4;
    v25 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v8 + 32 - (pAlpha_8 + 16)), v8[1]), v10), v8[1]);
    v26 = *(_OWORD *)v35;
    pAlpha = (__m128 *)((char *)pAlpha + v39);
    v35 += 4 * v36;
    pRGB = (__m128 *)((char *)pRGB + v38);
    v12 = (__m128 *)((char *)v12 + v38);
    pRot += pRot_4;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v37);
    pXYZ_8 = (__m128 *)((char *)pXYZ_8 + v37);
    pRadius += pRadius_4;
    v41 = (__m128 *)((char *)v41 + v34);
    v40 = (float *)((char *)v40 + v33);
    v27 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v8 - pAlpha_8), *v8), v10), *v8);
    v8 = (__m128 *)((char *)v8 + v39);
    pYaw += pYaw_4;
    v42 += pSeq;
    pRGB2 += pRGB2_4;
    pAlpha2 += pAlpha2_4;
    *(__m128 *)(v9 + 200) = v24;
    *(__m128 *)(v9 + 216) = v27;
    *(__m128 *)(v9 + 232) = v25;
    *(_OWORD *)(v9 + 248) = v26;
    v9 += 272;
  }
  while ( pXYZ > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1035B860
// Name: void GenerateExtendedData<0,0,0,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 m_fl4CurTime; // xmm4
  float *v7; // esi
  __m128 v8; // xmm7
  __m128 v9; // xmm5
  __m128 v10; // xmm6
  unsigned int v11; // edi
  unsigned int v12; // eax
  ParticleFullRenderData_Scalar_View **v13; // edx
  int v14; // ecx
  __m128 v15; // xmm2
  char *v16; // eax
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __int128 v19; // xmm0
  __m128 v20; // xmm0
  __int128 v21; // xmm0
  __m128 *pAlpha; // [esp+8h] [ebp-88h]
  float *pGlowAlpha; // [esp+3Ch] [ebp-54h]
  unsigned int pGlowAlpha_4; // [esp+40h] [ebp-50h]
  __m128 *pCreationTimeStamp; // [esp+44h] [ebp-4Ch]
  unsigned int pCreationTimeStamp_4; // [esp+48h] [ebp-48h]
  float *pRot; // [esp+4Ch] [ebp-44h]
  unsigned int pRot_4; // [esp+50h] [ebp-40h]
  float *pRadius; // [esp+54h] [ebp-3Ch]
  unsigned int pRadius_4; // [esp+58h] [ebp-38h]
  float *pYaw; // [esp+5Ch] [ebp-34h]
  unsigned int pYaw_4; // [esp+60h] [ebp-30h]
  float *pXYZ; // [esp+64h] [ebp-2Ch]
  unsigned int pXYZ_4; // [esp+68h] [ebp-28h]
  __m128 *pRGB; // [esp+6Ch] [ebp-24h]
  unsigned int pRGB_4; // [esp+70h] [ebp-20h]
  __m128 *pAlpha2; // [esp+74h] [ebp-1Ch]
  unsigned int pAlpha2_4; // [esp+78h] [ebp-18h]
  __m128 *pSeq; // [esp+7Ch] [ebp-14h]
  unsigned int pSeq_4; // [esp+80h] [ebp-10h]
  __m128 *pSeq1; // [esp+84h] [ebp-Ch]
  unsigned int pSeq1_4; // [esp+88h] [ebp-8h]
  int nParticles; // [esp+8Ch] [ebp-4h]
  CParticleVisibilityData *pVisibilityDataa; // [esp+B0h] [ebp+20h]
  bool bUseVis_3; // [esp+B7h] [ebp+27h]

  pXYZ = pParticles->m_ParticleAttributes.m_pAttributes[0];
  pXYZ_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  pRadius = pParticles->m_ParticleAttributes.m_pAttributes[3];
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pYaw = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pSeq_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2;
  pSeq1_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pSeq1 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  m_fl4CurTime = pParticles->m_fl4CurTime;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  pCreationTimeStamp_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2;
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  pRot = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pGlowAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[23] >> 2;
  pSeq = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pGlowAlpha = pParticles->m_ParticleAttributes.m_pAttributes[23];
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  v7 = pParticles->m_ParticleAttributes.m_pAttributes[22];
  v8 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v9 = _mm_shuffle_ps(
         (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
         (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
         0);
  v10 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          0);
  v11 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  v12 = pParticles->m_ParticleAttributes.m_nFloatStrides[22] / 0xC;
  nParticles = pParticles->m_nActiveParticles;
  bUseVis_3 = pVisibilityData->m_bUseVisibility;
  v13 = pIndexBuffer + 2;
  v14 = 48 * v12;
  v15 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  pVisibilityDataa = (CParticleVisibilityData *)(pIndexBuffer + 2);
  v16 = pOutbuf + 8;
  while ( 1 )
  {
    *(v13 - 2) = (ParticleFullRenderData_Scalar_View *)(v16 - 8);
    *(v13 - 1) = (ParticleFullRenderData_Scalar_View *)(v16 - 4);
    *v13 = (ParticleFullRenderData_Scalar_View *)v16;
    v13[1] = (ParticleFullRenderData_Scalar_View *)(v16 + 4);
    v17 = _mm_mul_ps(*pAlpha, *pAlpha2);
    v18 = *(__m128 *)pRadius;
    if ( bUseVis_3 )
    {
      v17 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v17, v9)));
      v18 = _mm_mul_ps(v18, v10);
    }
    *(_OWORD *)(v16 + 8) = *(_OWORD *)pXYZ;
    *(_OWORD *)(v16 + 24) = *((_OWORD *)pXYZ + 1);
    *(_OWORD *)(v16 + 40) = *((_OWORD *)pXYZ + 2);
    *(__m128 *)(v16 + 56) = _mm_add_ps(_mm_mul_ps(v17, v15), Four_2ToThe23s);
    *(__m128 *)(v16 + 72) = _mm_add_ps(_mm_mul_ps(*pRGB, v15), Four_2ToThe23s);
    *(__m128 *)(v16 + 88) = _mm_add_ps(_mm_mul_ps(pRGB[1], v15), Four_2ToThe23s);
    *(__m128 *)(v16 + 104) = _mm_add_ps(_mm_mul_ps(pRGB[2], v15), Four_2ToThe23s);
    *(__m128 *)(v16 + 136) = _mm_sub_ps(m_fl4CurTime, *pCreationTimeStamp);
    *(_OWORD *)(v16 + 168) = *(_OWORD *)pRot;
    v19 = *(_OWORD *)pYaw;
    *(__m128 *)(v16 + 120) = v18;
    *(_OWORD *)(v16 + 184) = v19;
    if ( pSeq1_4 != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pSeq1, v8), *pSeq);
    else
      v20 = *pSeq;
    *(__m128 *)(v16 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    *(_OWORD *)(v16 + 200) = *(_OWORD *)v7;
    *(_OWORD *)(v16 + 216) = *((_OWORD *)v7 + 1);
    *(_OWORD *)(v16 + 232) = *((_OWORD *)v7 + 2);
    v21 = *(_OWORD *)pGlowAlpha;
    nParticles -= 4;
    pGlowAlpha += 4 * pGlowAlpha_4;
    pXYZ += 12 * pXYZ_4;
    pAlpha += v11;
    pAlpha2 += pAlpha2_4;
    pRadius += 4 * pRadius_4;
    pRGB += 3 * pRGB_4;
    pYaw += 4 * pYaw_4;
    pRot += 4 * pRot_4;
    pSeq += pSeq_4;
    pSeq1 += pSeq1_4;
    pVisibilityDataa = (CParticleVisibilityData *)((char *)pVisibilityDataa + 16);
    pCreationTimeStamp += pCreationTimeStamp_4;
    *(_OWORD *)(v16 + 248) = v21;
    v7 = (float *)((char *)v7 + v14);
    v16 += 272;
    if ( nParticles <= 0 )
      break;
    v13 = (ParticleFullRenderData_Scalar_View **)pVisibilityDataa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035BBD0
// Name: void GenerateExtendedData<1,0,1,struct ParticleRenderDataWithNormal_SIMD_View,0,1,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,1,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  __m128 v7; // xmm0
  __m128 *v8; // edi
  char *v9; // eax
  __m128 *v10; // edx
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm6
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __int128 v26; // xmm1
  __m128 v27; // [esp-Ch] [ebp-24Ch]
  __m128 EyePos_4; // [esp+4h] [ebp-23Ch]
  __m128 EyePos_20; // [esp+14h] [ebp-22Ch]
  __m128 EyePos_36; // [esp+24h] [ebp-21Ch]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-20Ch]
  __m128 Four_256s_4; // [esp+44h] [ebp-1FCh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-1ECh]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-1DCh]
  __m128 fl4MaximumCreationTimeToDraw_4; // [esp+74h] [ebp-1CCh]
  __m128 fl4AlphaScale_4; // [esp+84h] [ebp-1BCh]
  __m128 fl4FinalRadius_4; // [esp+94h] [ebp-1ACh]
  float *fl4FinalAlpha_12; // [esp+ACh] [ebp-194h]
  float *v39; // [esp+C8h] [ebp-178h]
  int v40; // [esp+E8h] [ebp-158h]
  int v41; // [esp+F0h] [ebp-150h]
  unsigned int v42; // [esp+10Ch] [ebp-134h]
  unsigned int v43; // [esp+110h] [ebp-130h]
  unsigned int v44; // [esp+130h] [ebp-110h]
  __m128 *v45; // [esp+1C4h] [ebp-7Ch]
  __m128 *v46; // [esp+1CCh] [ebp-74h]
  unsigned int pSeq; // [esp+1D0h] [ebp-70h]
  int pSeq_4; // [esp+1D4h] [ebp-6Ch]
  __m128 *pRadius; // [esp+1D8h] [ebp-68h]
  unsigned int pRadius_4; // [esp+1DCh] [ebp-64h]
  int pRadius_8; // [esp+1E0h] [ebp-60h]
  __m128 *pYaw; // [esp+1E4h] [ebp-5Ch]
  unsigned int pYaw_4; // [esp+1E8h] [ebp-58h]
  int pYaw_8; // [esp+1ECh] [ebp-54h]
  float *pAlpha; // [esp+1F0h] [ebp-50h]
  unsigned int pAlpha_4; // [esp+1F4h] [ebp-4Ch]
  int pAlpha_8; // [esp+1F8h] [ebp-48h]
  __m128 *pRot; // [esp+1FCh] [ebp-44h]
  unsigned int pRot_4; // [esp+200h] [ebp-40h]
  int pRot_8; // [esp+204h] [ebp-3Ch]
  __m128 *pAlpha2; // [esp+208h] [ebp-38h]
  unsigned int pAlpha2_4; // [esp+20Ch] [ebp-34h]
  __m128 *pAlpha2_8; // [esp+210h] [ebp-30h]
  unsigned int pSeq1; // [esp+214h] [ebp-2Ch]
  int pSeq1_4; // [esp+218h] [ebp-28h]
  int pRGB; // [esp+21Ch] [ebp-24h]
  __m128 *pRGB_4; // [esp+220h] [ebp-20h]
  unsigned int pRGB_8; // [esp+224h] [ebp-1Ch]
  int nParticles; // [esp+228h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pXYZ; // [esp+22Ch] [ebp-14h]
  bool pXYZ_7; // [esp+233h] [ebp-Dh]

  pRGB_8 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pRGB_8 != 0 )
    nParticles = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
               - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    nParticles = 0;
  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    pSeq1_4 = 0;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v46 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pAlpha = pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pAlpha_4 != 0 )
    pAlpha_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
             - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pAlpha_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  v45 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v39 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v42 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[21] / 0xC);
  v40 = 48 * pRGB_8;
  v27 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  fl4AlphaVis_4 = _mm_shuffle_ps(
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                    0);
  fl4FinalAlpha_12 = pParticles->m_ParticleAttributes.m_pAttributes[21];
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  pRGB = pParticles->m_nActiveParticles;
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   (__m128)LODWORD(pParticles->m_flPrevSimTime),
                   0);
  pXYZ_7 = pVisibilityData->m_bUseVisibility;
  v41 = 48 * pSeq1;
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v7 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  fl4MaximumCreationTimeToDraw_4 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v44 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v43 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v8 = (__m128 *)((char *)pRGB_4 + nParticles + 16);
  pXYZ = pIndexBuffer + 2;
  v9 = pOutbuf + 8;
  v10 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  do
  {
    *(pXYZ - 2) = (ParticleFullRenderData_Scalar_View *)(v9 - 8);
    *pXYZ = (ParticleFullRenderData_Scalar_View *)v9;
    *(pXYZ - 1) = (ParticleFullRenderData_Scalar_View *)(v9 - 4);
    pXYZ[1] = (ParticleFullRenderData_Scalar_View *)(v9 + 4);
    v11 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v7),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v7),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    v12 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v46, *(__m128 *)((char *)v46 + pSeq_4)), v7),
            *(__m128 *)((char *)v46 + pSeq_4));
    fl4FinalRadius_4 = v11;
    fl4AlphaScale_4 = v12;
    if ( pXYZ_7 )
    {
      fl4FinalRadius_4 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, Four_256s_4)));
      fl4AlphaScale_4 = _mm_mul_ps(v12, EyePos_36);
    }
    v13 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB_4, v8[-1]), v7), v8[-1]);
    v14 = _mm_sub_ps(*(__m128 *)((char *)v8 - nParticles), *v8);
    v15 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v8 + 32 - (nParticles + 16)), v8[1]), v7), v8[1]);
    v16 = _mm_sub_ps(v13, v27);
    *(__m128 *)(v9 + 8) = v13;
    v17 = _mm_add_ps(_mm_mul_ps(v14, v7), *v8);
    v18 = _mm_sub_ps(v15, EyePos_20);
    v19 = _mm_sub_ps(v17, EyePos_4);
    v20 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v18, v18), _mm_mul_ps(v19, v19)), _mm_mul_ps(v16, v16));
    v21 = *(__m128 *)v39;
    *(__m128 *)(v9 + 40) = v15;
    *(__m128 *)(v9 + 24) = v17;
    *(__m128 *)(v9 + 56) = _mm_and_ps(
                             _mm_add_ps(_mm_mul_ps(fl4FinalRadius_4, fl4MaximumCreationTimeToDraw_4), Four_2ToThe23s),
                             _mm_cmplt_ps(v21, fl4CurTime_4));
    *(__m128 *)(v9 + 72) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, v10[-1]), v7), v10[-1]),
                               fl4MaximumCreationTimeToDraw_4),
                             Four_2ToThe23s);
    v22 = v10[1];
    *(__m128 *)(v9 + 88) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v10 - pSeq1_4), *v10), v7), *v10),
                               fl4MaximumCreationTimeToDraw_4),
                             Four_2ToThe23s);
    v23 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v10 + 32 - (pSeq1_4 + 16)), v22), v7), v22);
    *(__m128 *)(v9 + 120) = fl4AlphaScale_4;
    v24 = *(__m128 *)pAlpha;
    *(__m128 *)(v9 - 8) = v20;
    *(__m128 *)(v9 + 104) = _mm_add_ps(_mm_mul_ps(v23, fl4MaximumCreationTimeToDraw_4), Four_2ToThe23s);
    *(__m128 *)(v9 + 136) = _mm_sub_ps(fl4AlphaVis_4, v21);
    *(__m128 *)(v9 + 168) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(v24, *(__m128 *)((char *)pAlpha + pAlpha_8)), v7),
                              *(__m128 *)((char *)pAlpha + pAlpha_8));
    *(__m128 *)(v9 + 184) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v7),
                              *(__m128 *)((char *)pRadius + pRadius_8));
    if ( pAlpha2_4 != 0 )
      v25 = _mm_add_ps(_mm_mul_ps(*pAlpha2, fl4RadVis_4), *v45);
    else
      v25 = *v45;
    *(__m128 *)(v9 + 152) = _mm_add_ps(v25, Four_2ToThe23s);
    *(_OWORD *)(v9 + 200) = *(_OWORD *)fl4FinalAlpha_12;
    *(_OWORD *)(v9 + 216) = *((_OWORD *)fl4FinalAlpha_12 + 1);
    v26 = *((_OWORD *)fl4FinalAlpha_12 + 2);
    pRGB -= 4;
    fl4FinalAlpha_12 = (float *)((char *)fl4FinalAlpha_12 + v42);
    pRGB_4 = (__m128 *)((char *)pRGB_4 + v40);
    v8 = (__m128 *)((char *)v8 + v40);
    pYaw += pYaw_4;
    pRot += pRot_4;
    v46 += pSeq;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v41);
    pXYZ += 4;
    v10 = (__m128 *)((char *)v10 + v41);
    pRadius += pRadius_4;
    pAlpha += 4 * pAlpha_4;
    v45 = (__m128 *)((char *)v45 + v44);
    pAlpha2 += pAlpha2_4;
    v39 = (float *)((char *)v39 + v43);
    *(_OWORD *)(v9 + 232) = v26;
    v9 += 256;
  }
  while ( pRGB > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1035C240
// Name: void GenerateExtendedData<1,0,0,struct ParticleRenderDataWithNormal_SIMD_View,0,1,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<1,0,0,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  unsigned int v6; // kr04_4
  float *v7; // edx
  ParticleFullRenderData_Scalar_View **v8; // ecx
  __m128 v9; // xmm4
  char *v10; // eax
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __int128 v19; // xmm1
  __m128 v20; // xmm1
  __int128 v21; // xmm0
  __m128 v22; // [esp-Ch] [ebp-11Ch]
  __m128 EyePos_4; // [esp+4h] [ebp-10Ch]
  __m128 EyePos_20; // [esp+14h] [ebp-FCh]
  __m128 EyePos_36; // [esp+24h] [ebp-ECh]
  __m128 fl4RadVis_4; // [esp+34h] [ebp-DCh]
  __m128 Four_256s_4; // [esp+44h] [ebp-CCh]
  __m128 fl4AlphaVis_4; // [esp+54h] [ebp-BCh]
  __m128 fl4CurTime_4; // [esp+64h] [ebp-ACh]
  unsigned int fl4FinalRadius_12; // [esp+7Ch] [ebp-94h]
  unsigned int v31; // [esp+80h] [ebp-90h]
  unsigned int v32; // [esp+84h] [ebp-8Ch]
  unsigned int v33; // [esp+88h] [ebp-88h]
  unsigned int v34; // [esp+8Ch] [ebp-84h]
  unsigned int v35; // [esp+90h] [ebp-80h]
  __m128 *v36; // [esp+94h] [ebp-7Ch]
  unsigned int v37; // [esp+9Ch] [ebp-74h]
  __m128 *pAlpha2; // [esp+A0h] [ebp-70h]
  unsigned int pAlpha; // [esp+ACh] [ebp-64h]
  unsigned int pNormal; // [esp+B4h] [ebp-5Ch]
  float *pNormal_4; // [esp+B8h] [ebp-58h]
  __m128 *v42; // [esp+C0h] [ebp-50h]
  float *pXYZ_4; // [esp+C8h] [ebp-48h]
  __m128 *pCreationTimeStamp_4; // [esp+D0h] [ebp-40h]
  float *pRot_4; // [esp+D8h] [ebp-38h]
  __m128 *pRadius_4; // [esp+E0h] [ebp-30h]
  __m128 *pYaw_4; // [esp+E8h] [ebp-28h]
  __m128 *pRGB_4; // [esp+F0h] [ebp-20h]
  unsigned int pSeq; // [esp+F4h] [ebp-1Ch]
  int pSeq_4; // [esp+F8h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pSeq1; // [esp+FCh] [ebp-14h]
  bool pSeq1_7; // [esp+103h] [ebp-Dh]

  pNormal_4 = pParticles->m_ParticleAttributes.m_pAttributes[0];
  v6 = pParticles->m_ParticleAttributes.m_nFloatStrides[6];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pCreationTimeStamp_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  pRot_4 = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pRadius_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v36 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  fl4AlphaVis_4 = pParticles->m_fl4CurTime;
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pXYZ_4 = pParticles->m_ParticleAttributes.m_pAttributes[4];
  fl4RadVis_4 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  pYaw_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  v22 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.x), (__m128)LODWORD(CameraPos.x), 0);
  v42 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  EyePos_4 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.y), (__m128)LODWORD(CameraPos.y), 0);
  EyePos_20 = _mm_shuffle_ps((__m128)LODWORD(CameraPos.z), (__m128)LODWORD(CameraPos.z), 0);
  pSeq_4 = pParticles->m_nActiveParticles;
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                  0);
  v7 = pParticles->m_ParticleAttributes.m_pAttributes[21];
  EyePos_36 = _mm_shuffle_ps(
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                0);
  v37 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[21] / 0xC);
  v35 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
  fl4FinalRadius_12 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2);
  v32 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2);
  v33 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2);
  v31 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  pNormal = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2);
  pSeq1_7 = pVisibilityData->m_bUseVisibility;
  pAlpha = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v8 = pIndexBuffer + 2;
  v9 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v34 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2);
  pSeq1 = pIndexBuffer + 2;
  v10 = pOutbuf + 8;
  while ( 1 )
  {
    *(v8 - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *(v8 - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    *v8 = (ParticleFullRenderData_Scalar_View *)v10;
    v8[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v11 = _mm_mul_ps(*pAlpha2, *v36);
    fl4CurTime_4 = *pCreationTimeStamp_4;
    if ( pSeq1_7 )
    {
      v11 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v11, Four_256s_4)));
      fl4CurTime_4 = _mm_mul_ps(*pCreationTimeStamp_4, EyePos_36);
    }
    v12 = *(__m128 *)(pNormal_4 + 4);
    v13 = *(__m128 *)pNormal_4;
    v14 = _mm_sub_ps(*(__m128 *)(pNormal_4 + 8), EyePos_20);
    v15 = _mm_sub_ps(v12, EyePos_4);
    v16 = _mm_sub_ps(*(__m128 *)pNormal_4, v22);
    v17 = _mm_add_ps(_mm_mul_ps(v14, v14), _mm_mul_ps(v15, v15));
    v18 = _mm_mul_ps(*pRadius_4, v9);
    *(_OWORD *)(v10 + 40) = *((_OWORD *)pNormal_4 + 2);
    *(__m128 *)(v10 + 72) = _mm_add_ps(v18, Four_2ToThe23s);
    *(__m128 *)(v10 + 88) = _mm_add_ps(_mm_mul_ps(pRadius_4[1], v9), Four_2ToThe23s);
    *(__m128 *)(v10 + 104) = _mm_add_ps(_mm_mul_ps(pRadius_4[2], v9), Four_2ToThe23s);
    *(__m128 *)(v10 + 120) = fl4CurTime_4;
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4AlphaVis_4, *v42);
    *(_OWORD *)(v10 + 168) = *(_OWORD *)pXYZ_4;
    v19 = *(_OWORD *)pRot_4;
    *(__m128 *)(v10 - 8) = _mm_add_ps(v17, _mm_mul_ps(v16, v16));
    *(__m128 *)(v10 + 8) = v13;
    *(__m128 *)(v10 + 24) = v12;
    *(__m128 *)(v10 + 56) = _mm_add_ps(_mm_mul_ps(v11, v9), Four_2ToThe23s);
    *(_OWORD *)(v10 + 184) = v19;
    if ( pSeq != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pRGB_4, fl4RadVis_4), *pYaw_4);
    else
      v20 = *pYaw_4;
    pSeq_4 -= 4;
    pSeq1 += 4;
    pRadius_4 += 3 * (v6 / 0xC);
    pNormal_4 = (float *)((char *)pNormal_4 + v35);
    pAlpha2 = (__m128 *)((char *)pAlpha2 + v34);
    v36 = (__m128 *)((char *)v36 + pNormal);
    pCreationTimeStamp_4 = (__m128 *)((char *)pCreationTimeStamp_4 + fl4FinalRadius_12);
    pRot_4 = (float *)((char *)pRot_4 + v32);
    pXYZ_4 = (float *)((char *)pXYZ_4 + v33);
    pYaw_4 = (__m128 *)((char *)pYaw_4 + v31);
    pRGB_4 += pSeq;
    v42 = (__m128 *)((char *)v42 + pAlpha);
    *(_OWORD *)(v10 + 200) = *(_OWORD *)v7;
    *(_OWORD *)(v10 + 216) = *((_OWORD *)v7 + 1);
    v21 = *((_OWORD *)v7 + 2);
    v7 = (float *)((char *)v7 + v37);
    *(__m128 *)(v10 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    *(_OWORD *)(v10 + 232) = v21;
    v10 += 256;
    if ( pSeq_4 <= 0 )
      break;
    v8 = pSeq1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035C620
// Name: void GenerateExtendedData<0,0,1,struct ParticleRenderDataWithNormal_SIMD_View,0,1,class C4VInterpolatedAttributeIterator,class CM128InterpolatedAttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,1,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        unsigned int flInterpT)
{
  __m128 v7; // xmm0
  __m128 v8; // xmm3
  __m128 *v9; // edi
  char *v10; // eax
  __m128 *v11; // edx
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm7
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm6
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __int128 v21; // xmm1
  __m128 v22; // [esp-Ch] [ebp-1ECh]
  __m128 Four_256s_4; // [esp+4h] [ebp-1DCh]
  __m128 fl4RadVis_4; // [esp+14h] [ebp-1CCh]
  __m128 fl4CurTime_4; // [esp+24h] [ebp-1BCh]
  __m128 fl4AlphaVis_4; // [esp+34h] [ebp-1ACh]
  float *fl4MaximumCreationTimeToDraw_12; // [esp+4Ch] [ebp-194h]
  int v28; // [esp+D0h] [ebp-110h]
  unsigned int v29; // [esp+F0h] [ebp-F0h]
  unsigned int v30; // [esp+110h] [ebp-D0h]
  int v31; // [esp+11Ch] [ebp-C4h]
  unsigned int v32; // [esp+140h] [ebp-A0h]
  float *v33; // [esp+158h] [ebp-88h]
  __m128 *pCreationTimeStamp; // [esp+164h] [ebp-7Ch]
  __m128 *v35; // [esp+16Ch] [ebp-74h]
  unsigned int pSeq; // [esp+170h] [ebp-70h]
  int pSeq_4; // [esp+174h] [ebp-6Ch]
  __m128 *pRadius; // [esp+178h] [ebp-68h]
  unsigned int pRadius_4; // [esp+17Ch] [ebp-64h]
  int pRadius_8; // [esp+180h] [ebp-60h]
  __m128 *pYaw; // [esp+184h] [ebp-5Ch]
  unsigned int pYaw_4; // [esp+188h] [ebp-58h]
  int pYaw_8; // [esp+18Ch] [ebp-54h]
  __m128 *pAlpha; // [esp+190h] [ebp-50h]
  unsigned int pAlpha_4; // [esp+194h] [ebp-4Ch]
  int pAlpha_8; // [esp+198h] [ebp-48h]
  __m128 *pRot; // [esp+19Ch] [ebp-44h]
  unsigned int pRot_4; // [esp+1A0h] [ebp-40h]
  int pRot_8; // [esp+1A4h] [ebp-3Ch]
  __m128 *pAlpha2; // [esp+1A8h] [ebp-38h]
  unsigned int pAlpha2_4; // [esp+1ACh] [ebp-34h]
  __m128 *pAlpha2_8; // [esp+1B0h] [ebp-30h]
  unsigned int pSeq1; // [esp+1B4h] [ebp-2Ch]
  int pSeq1_4; // [esp+1B8h] [ebp-28h]
  int pRGB; // [esp+1BCh] [ebp-24h]
  __m128 *pRGB_4; // [esp+1C0h] [ebp-20h]
  unsigned int pRGB_8; // [esp+1C4h] [ebp-1Ch]
  int nParticles; // [esp+1C8h] [ebp-18h]
  ParticleFullRenderData_Scalar_View **pXYZ; // [esp+1CCh] [ebp-14h]
  bool pXYZ_7; // [esp+1D3h] [ebp-Dh]

  pRGB_8 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pRGB_4 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  if ( pRGB_8 != 0 )
    nParticles = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[0]
               - (char *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  else
    nParticles = 0;
  pSeq1 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  pAlpha2_8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  if ( pSeq1 != 0 )
    pSeq1_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[6]
            - (char *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  else
    pSeq1_4 = 0;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[7] >> 2;
  pYaw = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  if ( pYaw_4 != 0 )
    pYaw_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[7]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  else
    pYaw_8 = 0;
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRot = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  if ( pRot_4 != 0 )
    pRot_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[16]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  else
    pRot_8 = 0;
  pSeq = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  v35 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  if ( pSeq != 0 )
    pSeq_4 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[3]
           - (char *)pParticles->m_ParticleAttributes.m_pAttributes[3];
  else
    pSeq_4 = 0;
  pAlpha_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  if ( pAlpha_4 != 0 )
    pAlpha_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[4]
             - (char *)pParticles->m_ParticleAttributes.m_pAttributes[4];
  else
    pAlpha_8 = 0;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pRadius = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  if ( pRadius_4 != 0 )
    pRadius_8 = (char *)pParticles->m_PreviousFrameAttributes.m_pAttributes[12]
              - (char *)pParticles->m_ParticleAttributes.m_pAttributes[12];
  else
    pRadius_8 = 0;
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  v33 = pParticles->m_ParticleAttributes.m_pAttributes[8];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  v32 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[21] / 0xC);
  v31 = 48 * pRGB_8;
  v28 = 48 * pSeq1;
  fl4RadVis_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  (__m128)LODWORD(pParticles->m_flTargetDrawTime),
                  0);
  fl4MaximumCreationTimeToDraw_12 = pParticles->m_ParticleAttributes.m_pAttributes[21];
  fl4CurTime_4 = _mm_shuffle_ps(
                   (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                   (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
                   0);
  fl4AlphaVis_4 = _mm_shuffle_ps(
                    (__m128)LODWORD(pParticles->m_flPrevSimTime),
                    (__m128)LODWORD(pParticles->m_flPrevSimTime),
                    0);
  pRGB = pParticles->m_nActiveParticles;
  pXYZ_7 = pVisibilityData->m_bUseVisibility;
  v22 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v7 = _mm_shuffle_ps((__m128)flInterpT, (__m128)flInterpT, 0);
  Four_256s_4 = _mm_shuffle_ps(
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
                  0);
  v8 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v30 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2);
  v29 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
  v9 = (__m128 *)((char *)pRGB_4 + nParticles + 16);
  pXYZ = pIndexBuffer + 2;
  v10 = pOutbuf + 8;
  v11 = (__m128 *)((char *)pAlpha2_8 + pSeq1_4 + 16);
  do
  {
    *(pXYZ - 2) = (ParticleFullRenderData_Scalar_View *)(v10 - 8);
    *pXYZ = (ParticleFullRenderData_Scalar_View *)v10;
    *(pXYZ - 1) = (ParticleFullRenderData_Scalar_View *)(v10 - 4);
    pXYZ[1] = (ParticleFullRenderData_Scalar_View *)(v10 + 4);
    v12 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*v35, *(__m128 *)((char *)v35 + pSeq_4)), v7),
            *(__m128 *)((char *)v35 + pSeq_4));
    v13 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pRot, *(__m128 *)((char *)pRot + pRot_8)), v7),
              *(__m128 *)((char *)pRot + pRot_8)),
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(*pYaw, *(__m128 *)((char *)pYaw + pYaw_8)), v7),
              *(__m128 *)((char *)pYaw + pYaw_8)));
    if ( pXYZ_7 )
    {
      v12 = _mm_mul_ps(v12, Four_256s_4);
      v13 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v13, fl4CurTime_4)));
    }
    v14 = v9[1];
    v15 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pRGB_4, v9[-1]), v7), v9[-1]);
    *(__m128 *)(v10 + 24) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 - nParticles), *v9), v7), *v9);
    v16 = *(__m128 *)v33;
    *(__m128 *)(v10 + 40) = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v9 + 32 - (nParticles + 16)), v14), v7),
                              v14);
    *(__m128 *)(v10 + 56) = _mm_and_ps(
                              _mm_add_ps(_mm_mul_ps(v13, v8), Four_2ToThe23s),
                              _mm_cmplt_ps(v16, fl4AlphaVis_4));
    *(__m128 *)(v10 + 72) = _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(*pAlpha2_8, v11[-1]), v7), v11[-1]), v8),
                              Four_2ToThe23s);
    v17 = v11[1];
    *(__m128 *)(v10 + 88) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v11 - pSeq1_4), *v11), v7), *v11),
                                v8),
                              Four_2ToThe23s);
    v18 = *(__m128 *)((char *)v11 + 32 - (pSeq1_4 + 16));
    *(__m128 *)(v10 + 120) = v12;
    *(__m128 *)(v10 + 168) = _mm_add_ps(
                               _mm_mul_ps(_mm_sub_ps(*pAlpha, *(__m128 *)((char *)pAlpha + pAlpha_8)), v7),
                               *(__m128 *)((char *)pAlpha + pAlpha_8));
    v19 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(*pRadius, *(__m128 *)((char *)pRadius + pRadius_8)), v7),
            *(__m128 *)((char *)pRadius + pRadius_8));
    *(__m128 *)(v10 + 8) = v15;
    *(__m128 *)(v10 + 104) = _mm_add_ps(
                               _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(v18, v17), v7), v17), v8),
                               Four_2ToThe23s);
    *(__m128 *)(v10 + 136) = _mm_sub_ps(fl4RadVis_4, v16);
    *(__m128 *)(v10 + 184) = v19;
    if ( pAlpha2_4 != 0 )
      v20 = _mm_add_ps(_mm_mul_ps(*pAlpha2, v22), *pCreationTimeStamp);
    else
      v20 = *pCreationTimeStamp;
    *(__m128 *)(v10 + 152) = _mm_add_ps(v20, Four_2ToThe23s);
    *(_OWORD *)(v10 + 200) = *(_OWORD *)fl4MaximumCreationTimeToDraw_12;
    *(_OWORD *)(v10 + 216) = *((_OWORD *)fl4MaximumCreationTimeToDraw_12 + 1);
    v21 = *((_OWORD *)fl4MaximumCreationTimeToDraw_12 + 2);
    pRGB -= 4;
    fl4MaximumCreationTimeToDraw_12 = (float *)((char *)fl4MaximumCreationTimeToDraw_12 + v32);
    pRGB_4 = (__m128 *)((char *)pRGB_4 + v31);
    v9 = (__m128 *)((char *)v9 + v31);
    pYaw += pYaw_4;
    pRot += pRot_4;
    v35 += pSeq;
    pAlpha2_8 = (__m128 *)((char *)pAlpha2_8 + v28);
    pXYZ += 4;
    v11 = (__m128 *)((char *)v11 + v28);
    pRadius += pRadius_4;
    pAlpha += pAlpha_4;
    pCreationTimeStamp = (__m128 *)((char *)pCreationTimeStamp + v30);
    pAlpha2 += pAlpha2_4;
    v33 = (float *)((char *)v33 + v29);
    *(_OWORD *)(v10 + 232) = v21;
    v10 += 256;
  }
  while ( pRGB > 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1035CBE0
// Name: void GenerateExtendedData<0,0,0,struct ParticleRenderDataWithNormal_SIMD_View,0,1,class C4VAttributeIterator,class CM128AttributeIterator>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateExtendedData<0,0,0,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VAttributeIterator,CM128AttributeIterator>(
        char *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles)
{
  __m128 m_fl4CurTime; // xmm4
  float *v7; // esi
  __m128 v8; // xmm7
  unsigned int v9; // edi
  int m_nActiveParticles; // edx
  __m128 v11; // xmm5
  unsigned int v12; // eax
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  int v15; // ecx
  ParticleFullRenderData_Scalar_View **v16; // edx
  char *v17; // eax
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __int128 v20; // xmm0
  __m128 v21; // xmm0
  __m128 *pAlpha; // [esp+8h] [ebp-7Ch]
  float *pXYZ; // [esp+10h] [ebp-74h]
  unsigned int pXYZ_4; // [esp+14h] [ebp-70h]
  __m128 *pCreationTimeStamp; // [esp+18h] [ebp-6Ch]
  unsigned int pCreationTimeStamp_4; // [esp+1Ch] [ebp-68h]
  float *pRot; // [esp+20h] [ebp-64h]
  unsigned int pRot_4; // [esp+24h] [ebp-60h]
  float *pYaw; // [esp+28h] [ebp-5Ch]
  unsigned int pYaw_4; // [esp+2Ch] [ebp-58h]
  __m128 *pRGB; // [esp+30h] [ebp-54h]
  unsigned int pRGB_4; // [esp+34h] [ebp-50h]
  float *pRadius; // [esp+38h] [ebp-4Ch]
  unsigned int pRadius_4; // [esp+3Ch] [ebp-48h]
  __m128 *pAlpha2; // [esp+40h] [ebp-44h]
  unsigned int pAlpha2_4; // [esp+44h] [ebp-40h]
  __m128 *pSeq1; // [esp+48h] [ebp-3Ch]
  unsigned int pSeq1_4; // [esp+4Ch] [ebp-38h]
  __m128 *pSeq; // [esp+50h] [ebp-34h]
  unsigned int pSeq_4; // [esp+54h] [ebp-30h]
  int nParticles; // [esp+80h] [ebp-4h]
  CParticleVisibilityData *pVisibilityDataa; // [esp+A4h] [ebp+20h]
  bool bUseVis_3; // [esp+ABh] [ebp+27h]

  pXYZ = pParticles->m_ParticleAttributes.m_pAttributes[0];
  pXYZ_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pAlpha = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[7];
  pAlpha2_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[16] >> 2;
  pRadius_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[3] >> 2;
  pRadius = pParticles->m_ParticleAttributes.m_pAttributes[3];
  pRot_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[4] >> 2;
  pYaw_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[12] >> 2;
  pYaw = pParticles->m_ParticleAttributes.m_pAttributes[12];
  pSeq_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[9] >> 2;
  pRGB_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[6] / 0xC;
  m_fl4CurTime = pParticles->m_fl4CurTime;
  pSeq1_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[13] >> 2;
  pRGB = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[6];
  pSeq1 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[13];
  pAlpha2 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[16];
  pRot = pParticles->m_ParticleAttributes.m_pAttributes[4];
  pCreationTimeStamp_4 = pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2;
  pSeq = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[9];
  pCreationTimeStamp = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  v7 = pParticles->m_ParticleAttributes.m_pAttributes[21];
  v8 = _mm_shuffle_ps((__m128)0x43800000u, (__m128)0x43800000u, 0);
  v9 = pParticles->m_ParticleAttributes.m_nFloatStrides[7];
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v11 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
          (__m128)LODWORD(pVisibilityData->m_flAlphaVisibility),
          0);
  v12 = pParticles->m_ParticleAttributes.m_nFloatStrides[21] / 0xC;
  bUseVis_3 = pVisibilityData->m_bUseVisibility;
  v13 = _mm_shuffle_ps(
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          (__m128)LODWORD(pVisibilityData->m_flRadiusVisibility),
          0);
  nParticles = m_nActiveParticles;
  v14 = _mm_shuffle_ps((__m128)0x437F0000u, (__m128)0x437F0000u, 0);
  v15 = 48 * v12;
  v16 = pIndexBuffer + 2;
  pVisibilityDataa = (CParticleVisibilityData *)(pIndexBuffer + 2);
  v17 = pOutbuf + 8;
  while ( 1 )
  {
    *(v16 - 2) = (ParticleFullRenderData_Scalar_View *)(v17 - 8);
    *(v16 - 1) = (ParticleFullRenderData_Scalar_View *)(v17 - 4);
    *v16 = (ParticleFullRenderData_Scalar_View *)v17;
    v16[1] = (ParticleFullRenderData_Scalar_View *)(v17 + 4);
    v18 = _mm_mul_ps(*pAlpha, *pAlpha2);
    v19 = *(__m128 *)pRadius;
    if ( bUseVis_3 )
    {
      v18 = _mm_max_ps(Four_Zeros, _mm_min_ps(Four_Ones, _mm_mul_ps(v18, v11)));
      v19 = _mm_mul_ps(v19, v13);
    }
    *(_OWORD *)(v17 + 8) = *(_OWORD *)pXYZ;
    *(_OWORD *)(v17 + 24) = *((_OWORD *)pXYZ + 1);
    *(_OWORD *)(v17 + 40) = *((_OWORD *)pXYZ + 2);
    *(__m128 *)(v17 + 56) = _mm_add_ps(_mm_mul_ps(v18, v14), Four_2ToThe23s);
    *(__m128 *)(v17 + 72) = _mm_add_ps(_mm_mul_ps(*pRGB, v14), Four_2ToThe23s);
    *(__m128 *)(v17 + 88) = _mm_add_ps(_mm_mul_ps(pRGB[1], v14), Four_2ToThe23s);
    *(__m128 *)(v17 + 104) = _mm_add_ps(_mm_mul_ps(pRGB[2], v14), Four_2ToThe23s);
    *(__m128 *)(v17 + 136) = _mm_sub_ps(m_fl4CurTime, *pCreationTimeStamp);
    *(_OWORD *)(v17 + 168) = *(_OWORD *)pRot;
    v20 = *(_OWORD *)pYaw;
    *(__m128 *)(v17 + 120) = v19;
    *(_OWORD *)(v17 + 184) = v20;
    if ( pSeq1_4 != 0 )
      v21 = _mm_add_ps(_mm_mul_ps(*pSeq1, v8), *pSeq);
    else
      v21 = *pSeq;
    nParticles -= 4;
    pXYZ += 12 * pXYZ_4;
    pAlpha += v9 >> 2;
    pAlpha2 += pAlpha2_4;
    pRadius += 4 * pRadius_4;
    pRGB += 3 * pRGB_4;
    pYaw += 4 * pYaw_4;
    pRot += 4 * pRot_4;
    pSeq += pSeq_4;
    pSeq1 += pSeq1_4;
    pVisibilityDataa = (CParticleVisibilityData *)((char *)pVisibilityDataa + 16);
    pCreationTimeStamp += pCreationTimeStamp_4;
    *(__m128 *)(v17 + 152) = _mm_add_ps(v21, Four_2ToThe23s);
    *(_OWORD *)(v17 + 200) = *(_OWORD *)v7;
    *(_OWORD *)(v17 + 216) = *((_OWORD *)v7 + 1);
    *(_OWORD *)(v17 + 232) = *((_OWORD *)v7 + 2);
    v7 = (float *)((char *)v7 + v15);
    v17 += 256;
    if ( nParticles <= 0 )
      break;
    v16 = (ParticleFullRenderData_Scalar_View **)pVisibilityDataa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035CF10
// Name: void std::_Adjust_heap<struct ParticleRenderDataWithNormal_Scalar_View __near * __near *,int,struct ParticleRenderDataWithNormal_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleRenderDataWithNormal_Scalar_View __near * __near *,int,int,struct ParticleRenderDataWithNormal_Scalar_View __near * __near &&,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<ParticleRenderDataWithNormal_Scalar_View * *,int,ParticleRenderDataWithNormal_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleRenderDataWithNormal_Scalar_View **_First,
        ParticleRenderDataWithNormal_Scalar_View *_Hole,
        int _Bottom,
        ParticleRenderDataWithNormal_Scalar_View **_Val,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  ParticleRenderDataWithNormal_Scalar_View **v8; // edi
  bool v9; // zf
  ParticleRenderDataWithNormal_Scalar_View **v10; // ecx
  ParticleRenderDataWithNormal_Scalar_View *v11; // ecx
  int v12; // esi
  int v13; // edx
  int _Top; // [esp+Ch] [ebp-4h]

  v5 = _Bottom;
  v6 = (int)_Hole;
  v7 = 2 * (_DWORD)_Hole + 2;
  v8 = _First;
  _Top = (int)_Hole;
  v9 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      v10 = (ParticleRenderDataWithNormal_Scalar_View **)v8[v7];
      _Hole = v8[v7 - 1];
      _First = v10;
      if ( _Pred(
             a1: (ParticleFullRenderData_Scalar_View *const *)&_First,
             a2: (const ParticleFullRenderData_Scalar_View *const *)&_Hole) )
      {
        --v7;
      }
      v11 = v8[v7];
      _Hole = (ParticleRenderDataWithNormal_Scalar_View *)v7;
      v7 = 2 * v7 + 2;
      v8[v6] = v11;
      v6 = (int)_Hole;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v9 = v7 == _Bottom;
  }
  if ( v9 )
  {
    v8[v6] = v8[v5 - 1];
    _Hole = (ParticleRenderDataWithNormal_Scalar_View *)(v5 - 1);
    v6 = v5 - 1;
  }
  v12 = (v6 - 1) / 2;
  if ( _Top < v6 )
  {
    while ( 1 )
    {
      v13 = (int)v8[v12];
      _Hole = *_Val;
      _Bottom = v13;
      if ( !_Pred(
              a1: (ParticleFullRenderData_Scalar_View *const *)&_Bottom,
              a2: (const ParticleFullRenderData_Scalar_View *const *)&_Hole) )
        break;
      v8[v6] = v8[v12];
      _Hole = (ParticleRenderDataWithNormal_Scalar_View *)v12;
      v12 = (v12 - 1) / 2;
      if ( _Top >= (int)_Hole )
      {
        v8[(_DWORD)_Hole] = *_Val;
        return;
      }
      v6 = (int)_Hole;
    }
    v8[v6] = *_Val;
  }
  else
  {
    v8[v6] = *_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D000
// Name: void std::_Make_heap<struct ParticleRenderData_t __near *,int,struct ParticleRenderData_t,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &)>(struct ParticleRenderData_t __near *,struct ParticleRenderData_t __near *,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &),int __near *,struct ParticleRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        ParticleRenderData_t *_First,
        ParticleRenderData_t *_Last,
        bool (__cdecl *_Pred)(const ParticleRenderData_t *, const ParticleRenderData_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  ParticleRenderData_t *i; // edx
  __int64 v8; // xmm0_8
  ParticleRenderData_t *v9; // edx
  int v10; // eax
  int v11; // esi
  __int64 v12; // xmm0_8
  int v13; // ebx
  bool v14; // zf
  int v15; // ecx
  __int64 v16; // xmm0_8
  int v17; // ebx
  ParticleRenderData_t _Val; // [esp+4h] [ebp-18h] BYREF
  int v19; // [esp+14h] [ebp-8h]
  ParticleRenderData_t *v20; // [esp+18h] [ebp-4h]
  int _Hole; // [esp+24h] [ebp+8h]
  int _Bottom; // [esp+28h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v20 )
    {
      v8 = *(_QWORD *)&i[-1].m_flSortKey;
      v9 = i - 1;
      v10 = v5 - 1;
      v11 = v6 - 2;
      *(_QWORD *)&_Val.m_flSortKey = v8;
      v12 = *(_QWORD *)&v9->m_flRadius;
      _Hole = v10;
      v20 = v9;
      v19 = v11;
      *(_QWORD *)&_Val.m_flRadius = v12;
      v13 = v10;
      v14 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v11], a2: &_First[v11 - 1]) )
            --v11;
          v15 = v13;
          v13 = v11;
          *(_QWORD *)&_First[v15].m_flSortKey = *(_QWORD *)&_First[v11].m_flSortKey;
          v16 = *(_QWORD *)&_First[v11].m_flRadius;
          v11 = 2 * v11 + 2;
          *(_QWORD *)&_First[v15].m_flRadius = v16;
        }
        while ( v11 < _Bottom );
        v4 = _Bottom;
        v10 = _Hole;
        v14 = v11 == _Bottom;
      }
      if ( v14 )
      {
        v17 = v13;
        *(_QWORD *)&_First[v17].m_flSortKey = *(_QWORD *)&_First[v4 - 1].m_flSortKey;
        *(_QWORD *)&_First[v17].m_flRadius = *(_QWORD *)&_First[v4 - 1].m_flRadius;
        v13 = v4 - 1;
      }
      std::_Push_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        _First,
        _Hole: v13,
        _Top: v10,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D110
// Name: void std::_Make_heap<struct ParticleFullRenderData_Scalar_View __near * __near *,int,struct ParticleFullRenderData_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleFullRenderData_Scalar_View __near * __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &),int __near *,struct ParticleFullRenderData_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleFullRenderData_Scalar_View **_First,
        ParticleFullRenderData_Scalar_View **_Last,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v4; // ecx
  int v5; // ebx
  int i; // esi
  ParticleFullRenderData_Scalar_View *v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // eax
  ParticleFullRenderData_Scalar_View *v11; // edx
  ParticleFullRenderData_Scalar_View *_Val; // [esp+8h] [ebp-8h] BYREF
  int v13; // [esp+Ch] [ebp-4h]
  int _Bottom; // [esp+18h] [ebp+8h]
  int _Lasta; // [esp+1Ch] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    for ( i = 2 * v5 + 2; ; i = v13 )
    {
      v7 = _First[--v5];
      v8 = i - 2;
      v13 = v8;
      _Val = v7;
      _Lasta = v5;
      v9 = v8 == v4;
      if ( v8 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v8], a2: (const ParticleFullRenderData_Scalar_View *const *)&_First[v8 - 1]) )
            --v8;
          v10 = _Lasta;
          v11 = _First[v8];
          _Lasta = v8;
          v8 = 2 * v8 + 2;
          _First[v10] = v11;
        }
        while ( v8 < _Bottom );
        v4 = _Bottom;
        v9 = v8 == _Bottom;
      }
      if ( v9 )
      {
        _First[_Lasta] = _First[v4 - 1];
        _Lasta = v4 - 1;
      }
      std::_Push_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First,
        _Hole: _Lasta,
        _Top: v5,
        (const ParticleFullRenderData_Scalar_View *const *)&_Val,
        _Pred);
      if ( v5 <= 0 )
        break;
      v4 = _Bottom;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D1C0
// Name: void std::_Make_heap<struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,int,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &),int __near *,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleRenderDataWithNormal_Scalar_View **_First,
        ParticleRenderDataWithNormal_Scalar_View **_Last,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v4; // ecx
  int v5; // ebx
  int i; // esi
  ParticleRenderDataWithNormal_Scalar_View *v7; // eax
  int v8; // esi
  bool v9; // zf
  ParticleRenderDataWithNormal_Scalar_View *v10; // edx
  int v11; // eax
  ParticleRenderDataWithNormal_Scalar_View *v12; // edx
  ParticleRenderDataWithNormal_Scalar_View *_Val; // [esp+8h] [ebp-10h] BYREF
  ParticleFullRenderData_Scalar_View *v14; // [esp+Ch] [ebp-Ch] BYREF
  ParticleFullRenderData_Scalar_View *v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]
  int _Bottom; // [esp+20h] [ebp+8h]
  int _Lasta; // [esp+24h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    for ( i = 2 * v5 + 2; ; i = v16 )
    {
      v7 = _First[--v5];
      v8 = i - 2;
      v16 = v8;
      _Val = v7;
      _Lasta = v5;
      v9 = v8 == v4;
      if ( v8 < v4 )
      {
        do
        {
          v10 = _First[v8];
          v15 = _First[v8 - 1];
          v14 = v10;
          if ( _Pred(a1: &v14, a2: (const ParticleFullRenderData_Scalar_View *const *)&v15) )
            --v8;
          v11 = _Lasta;
          v12 = _First[v8];
          _Lasta = v8;
          v8 = 2 * v8 + 2;
          _First[v11] = v12;
        }
        while ( v8 < _Bottom );
        v4 = _Bottom;
        v9 = v8 == _Bottom;
      }
      if ( v9 )
      {
        _First[_Lasta] = _First[v4 - 1];
        _Lasta = v4 - 1;
      }
      std::_Push_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First,
        _Hole: _Lasta,
        _Top: v5,
        &_Val,
        _Pred);
      if ( v5 <= 0 )
        break;
      v4 = _Bottom;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D280
// Name: void s_GenerateExtendedData<0,1,struct ParticleFullRenderData_SIMD_View,0,0>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,1,ParticleFullRenderData_SIMD_View,0,0>(
        void *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,1,ParticleFullRenderData_SIMD_View,0,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,1,ParticleFullRenderData_SIMD_View,0,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x1035D300
// Name: void s_GenerateExtendedData<0,0,struct ParticleFullRenderData_SIMD_View,0,0>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,0,ParticleFullRenderData_SIMD_View,0,0>(
        void *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,0,ParticleFullRenderData_SIMD_View,0,0,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,0,ParticleFullRenderData_SIMD_View,0,0,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x1035D380
// Name: void s_GenerateExtendedData<0,1,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(
        void *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x1035D400
// Name: void s_GenerateExtendedData<0,0,struct ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(
        void *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x1035D480
// Name: void s_GenerateExtendedData<0,1,struct ParticleRenderDataWithNormal_SIMD_View,0,1>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,1,ParticleRenderDataWithNormal_SIMD_View,0,1>(
        void *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,1,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,1,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VInterpolatedAttributeIterator,CM128InterpolatedAttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x1035D500
// Name: void s_GenerateExtendedData<0,0,struct ParticleRenderDataWithNormal_SIMD_View,0,1>(void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_GenerateExtendedData<0,0,ParticleRenderDataWithNormal_SIMD_View,0,1>(
        void *pOutbuf,
        ParticleFullRenderData_Scalar_View **pIndexBuffer,
        Vector CameraPos,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        float flInterpT,
        bool bSort)
{
  if ( bSort )
    GenerateExtendedData<1,0,0,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
  else
    GenerateExtendedData<0,0,0,ParticleRenderDataWithNormal_SIMD_View,0,1,C4VAttributeIterator,CM128AttributeIterator>(
      pOutbuf,
      pIndexBuffer,
      CameraPos,
      pCameraFwd,
      pVisibilityData,
      pParticles,
      flInterpT);
}

//------------------------------------------------------------------------------
// Address: 0x1035D580
// Name: void std::_Sort_heap<struct ParticleRenderData_t __near *,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &)>(struct ParticleRenderData_t __near *,struct ParticleRenderData_t __near *,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<ParticleRenderData_t *,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        ParticleRenderData_t *_First,
        ParticleRenderData_t *_Last,
        bool (__cdecl *_Pred)(const ParticleRenderData_t *, const ParticleRenderData_t *))
{
  int v3; // eax
  ParticleRenderData_t *v4; // esi
  ParticleRenderData_t _Val; // [esp+4h] [ebp-10h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF0) > 16 )
  {
    v4 = _Last - 1;
    do
    {
      _Val = *v4;
      *v4 = *_First;
      std::_Adjust_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 16) >> 4,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 16;
    }
    while ( (int)(v3 & 0xFFFFFFF0) > 16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D600
// Name: void std::_Sort_heap<struct ParticleFullRenderData_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleFullRenderData_Scalar_View __near * __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<ParticleFullRenderData_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleFullRenderData_Scalar_View **_First,
        ParticleFullRenderData_Scalar_View **_Last,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v3; // eax
  bool (__cdecl *v4)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *); // ebx
  ParticleFullRenderData_Scalar_View **v5; // edx
  int v6; // edi

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFFC) > 4 )
  {
    v4 = _Pred;
    do
    {
      v5 = *(ParticleFullRenderData_Scalar_View ***)((char *)_First + v3 - 4);
      v6 = v3 - 4;
      *(ParticleFullRenderData_Scalar_View **)((char *)_First + v3 - 4) = *_First;
      _Last = v5;
      std::_Adjust_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 4) >> 2,
        _Val: (const ParticleFullRenderData_Scalar_View *const *)&_Last,
        _Pred: v4);
      v3 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D660
// Name: void std::_Sort_heap<struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleRenderDataWithNormal_Scalar_View **_First,
        ParticleRenderDataWithNormal_Scalar_View **_Last,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v3; // eax
  bool (__cdecl *v4)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *); // ebx
  ParticleRenderDataWithNormal_Scalar_View **v5; // edx
  int v6; // edi

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFFC) > 4 )
  {
    v4 = _Pred;
    do
    {
      v5 = *(ParticleRenderDataWithNormal_Scalar_View ***)((char *)_First + v3 - 4);
      v6 = v3 - 4;
      *(ParticleRenderDataWithNormal_Scalar_View **)((char *)_First + v3 - 4) = *_First;
      _Last = v5;
      std::_Adjust_heap<ParticleRenderDataWithNormal_Scalar_View * *,int,ParticleRenderDataWithNormal_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First,
        _Hole: nullptr,
        _Bottom: (v3 - 4) >> 2,
        _Val: (ParticleRenderDataWithNormal_Scalar_View **)&_Last,
        _Pred: v4);
      v3 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D6C0
// Name: public: int CParticleCollection::GenerateSortedIndexList(struct ParticleRenderData_t __near *,class Vector,struct CParticleVisibilityData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleCollection::GenerateSortedIndexList(
        CParticleCollection *this,
        __m128 *pOut,
        Vector vecCamera,
        CParticleVisibilityData *pVisibilityData,
        bool bSorted)
{
  int m_nActiveParticles; // ebx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CParticleCollection::GenerateSortedIndexList",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  m_nActiveParticles = this->m_nActiveParticles;
  if ( bSorted )
  {
    s_GenerateData<1,0>(pOutData: pOut, CameraPos: vecCamera, pCameraFwd: nullptr, pVisibilityData, pParticles: this);
    if ( 16 * m_nActiveParticles > 16 )
      std::_Make_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        _First: (ParticleRenderData_t *)pOut,
        _Last: (ParticleRenderData_t *)&pOut[m_nActiveParticles],
        _Pred: (bool (__cdecl *)(const ParticleRenderData_t *, const ParticleRenderData_t *))lessFunc,
        __formal: nullptr,
        __formal: nullptr);
    std::_Sort_heap<ParticleRenderData_t *,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
      _First: (ParticleRenderData_t *)pOut,
      _Last: (ParticleRenderData_t *)&pOut[m_nActiveParticles],
      _Pred: (bool (__cdecl *)(const ParticleRenderData_t *, const ParticleRenderData_t *))lessFunc);
  }
  else
  {
    s_GenerateData<0,0>(pOutData: pOut, CameraPos: vecCamera, pCameraFwd: nullptr, pVisibilityData, pParticles: this);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return m_nActiveParticles;
}

//------------------------------------------------------------------------------
// Address: 0x1035D780
// Name: public: int CParticleCollection::GenerateCulledSortedIndexList(struct ParticleRenderData_t __near *,class Vector,class Vector,struct CParticleVisibilityData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleCollection::GenerateCulledSortedIndexList(
        CParticleCollection *this,
        __m128 *pOut,
        Vector vecCamera,
        Vector vecFwd,
        CParticleVisibilityData *pVisibilityData,
        bool bSorted)
{
  int m_nActiveParticles; // ebx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CParticleCollection::GenerateSortedIndexList",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  m_nActiveParticles = this->m_nActiveParticles;
  if ( bSorted )
  {
    s_GenerateData<1,1>(pOutData: pOut, CameraPos: vecCamera, pCameraFwd: &vecFwd, pVisibilityData, pParticles: this);
    if ( 16 * m_nActiveParticles > 16 )
      std::_Make_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        _First: (ParticleRenderData_t *)pOut,
        _Last: (ParticleRenderData_t *)&pOut[m_nActiveParticles],
        _Pred: (bool (__cdecl *)(const ParticleRenderData_t *, const ParticleRenderData_t *))lessFunc,
        __formal: nullptr,
        __formal: nullptr);
    std::_Sort_heap<ParticleRenderData_t *,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
      _First: (ParticleRenderData_t *)pOut,
      _Last: (ParticleRenderData_t *)&pOut[m_nActiveParticles],
      _Pred: (bool (__cdecl *)(const ParticleRenderData_t *, const ParticleRenderData_t *))lessFunc);
  }
  else
  {
    s_GenerateData<0,1>(pOutData: pOut, CameraPos: vecCamera, pCameraFwd: &vecFwd, pVisibilityData, pParticles: this);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return m_nActiveParticles;
}

//------------------------------------------------------------------------------
// Address: 0x1035D830
// Name: public: struct ParticleRenderData_t const __near * CParticleCollection::GetRenderList(class IMatRenderContext __near *,bool,int __near *,struct CParticleVisibilityData __near *)
// Source: json
//------------------------------------------------------------------------------
const ParticleRenderData_t *__thiscall CParticleCollection::GetRenderList(
        CParticleCollection *this,
        IMatRenderContext *pRenderContext,
        bool bSorted,
        int *pNparticles,
        CParticleVisibilityData *pVisibilityData)
{
  int SortedIndexList; // eax
  Vector vecRight; // [esp+8h] [ebp-30h] BYREF
  Vector vecUp; // [esp+14h] [ebp-24h] BYREF
  Vector vecFwd; // [esp+20h] [ebp-18h] BYREF
  Vector vecCamera; // [esp+2Ch] [ebp-Ch] BYREF

  if ( bSorted )
    bSorted = this->m_pDef.m_pObject->m_bShouldSort;
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &vecCamera);
  if ( vecCamera.x < this->m_MinBounds.x
    || this->m_MaxBounds.x < vecCamera.x
    || vecCamera.y < this->m_MinBounds.y
    || this->m_MaxBounds.y < vecCamera.y
    || vecCamera.z < this->m_MinBounds.z
    || this->m_MaxBounds.z < vecCamera.z )
  {
    SortedIndexList = CParticleCollection::GenerateSortedIndexList(
                        this,
                        pOut: (__m128 *)&s_SortBuffer,
                        vecCamera,
                        pVisibilityData,
                        bSorted);
  }
  else
  {
    pRenderContext->GetWorldSpaceCameraVectors(this: pRenderContext, a2: &vecFwd, a3: &vecRight, a4: &vecUp);
    SortedIndexList = CParticleCollection::GenerateCulledSortedIndexList(
                        this,
                        pOut: (__m128 *)&s_SortBuffer,
                        vecCamera,
                        vecFwd,
                        pVisibilityData,
                        bSorted);
  }
  *pNparticles = SortedIndexList;
  return &s_SortBuffer + SortedIndexList;
}

//------------------------------------------------------------------------------
// Address: 0x1035D950
// Name: int GenerateExtendedSortedIndexList(class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,bool,void __near *,struct ParticleFullRenderData_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GenerateExtendedSortedIndexList(
        Vector vecCamera,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        bool bSorted,
        void *pOutBuf,
        ParticleFullRenderData_Scalar_View **pParticlePtrs)
{
  CParticleCollection *v7; // edi
  float m_flTargetDrawTime; // xmm0_4
  float m_flCurTime; // xmm1_4
  float m_flPrevSimTime; // xmm2_4
  bool v11; // bl
  ParticleFullRenderData_Scalar_View **v12; // esi
  int m_nActiveParticles; // edi

  v7 = pParticles;
  m_flTargetDrawTime = pParticles->m_flTargetDrawTime;
  m_flCurTime = pParticles->m_flCurTime;
  if ( m_flCurTime <= m_flTargetDrawTime
    || (m_flPrevSimTime = pParticles->m_flPrevSimTime, m_flTargetDrawTime < m_flPrevSimTime)
    || pParticles->m_pPreviousAttributeMemory == nullptr
    || pParticles->m_bFrozen )
  {
    v11 = bSorted;
    v12 = pParticlePtrs;
    s_GenerateExtendedData<0,0,ParticleFullRenderData_SIMD_View,0,0>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: vecCamera,
      pCameraFwd: nullptr,
      pVisibilityData,
      pParticles,
      flInterpT: 0.0,
      bSort: bSorted);
  }
  else
  {
    v11 = bSorted;
    v12 = pParticlePtrs;
    s_GenerateExtendedData<0,1,ParticleFullRenderData_SIMD_View,0,0>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: vecCamera,
      pCameraFwd: nullptr,
      pVisibilityData,
      pParticles,
      flInterpT: (float)(m_flTargetDrawTime - m_flPrevSimTime) / (float)(m_flCurTime - m_flPrevSimTime),
      bSort: bSorted);
  }
  m_nActiveParticles = v7->m_nActiveParticles;
  if ( v11 )
  {
    if ( 4 * m_nActiveParticles > 4 )
      std::_Make_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First: v12,
        _Last: &v12[m_nActiveParticles],
        _Pred: SortLessFuncExtended,
        __formal: nullptr,
        __formal: nullptr);
    std::_Sort_heap<ParticleFullRenderData_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
      _First: v12,
      _Last: &v12[m_nActiveParticles],
      _Pred: SortLessFuncExtended);
  }
  return m_nActiveParticles;
}

//------------------------------------------------------------------------------
// Address: 0x1035DA40
// Name: int GenerateExtendedSortedIndexListWithPerParticleGlow(class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,bool,void __near *,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GenerateExtendedSortedIndexListWithPerParticleGlow(
        Vector vecCamera,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        bool bSorted,
        void *pOutBuf,
        ParticleFullRenderData_Scalar_View **pParticlePtrs)
{
  CParticleCollection *v7; // edi
  float m_flTargetDrawTime; // xmm0_4
  float m_flCurTime; // xmm1_4
  float m_flPrevSimTime; // xmm2_4
  bool v11; // bl
  ParticleRenderDataWithNormal_Scalar_View **v12; // esi
  int m_nActiveParticles; // edi

  v7 = pParticles;
  m_flTargetDrawTime = pParticles->m_flTargetDrawTime;
  m_flCurTime = pParticles->m_flCurTime;
  if ( m_flCurTime <= m_flTargetDrawTime
    || (m_flPrevSimTime = pParticles->m_flPrevSimTime, m_flTargetDrawTime < m_flPrevSimTime)
    || pParticles->m_pPreviousAttributeMemory == nullptr
    || pParticles->m_bFrozen )
  {
    v11 = bSorted;
    v12 = (ParticleRenderDataWithNormal_Scalar_View **)pParticlePtrs;
    s_GenerateExtendedData<0,0,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: vecCamera,
      pCameraFwd: nullptr,
      pVisibilityData,
      pParticles,
      flInterpT: 0.0,
      bSort: bSorted);
  }
  else
  {
    v11 = bSorted;
    v12 = (ParticleRenderDataWithNormal_Scalar_View **)pParticlePtrs;
    s_GenerateExtendedData<0,1,ParticleRenderDataWithOutlineInformation_SIMD_View,1,0>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: vecCamera,
      pCameraFwd: nullptr,
      pVisibilityData,
      pParticles,
      flInterpT: (float)(m_flTargetDrawTime - m_flPrevSimTime) / (float)(m_flCurTime - m_flPrevSimTime),
      bSort: bSorted);
  }
  m_nActiveParticles = v7->m_nActiveParticles;
  if ( v11 )
  {
    if ( 4 * m_nActiveParticles > 4 )
      std::_Make_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First: v12,
        _Last: &v12[m_nActiveParticles],
        _Pred: SortLessFuncExtended,
        __formal: nullptr,
        __formal: nullptr);
    std::_Sort_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
      _First: v12,
      _Last: &v12[m_nActiveParticles],
      _Pred: SortLessFuncExtended);
  }
  return m_nActiveParticles;
}

//------------------------------------------------------------------------------
// Address: 0x1035DB30
// Name: int GenerateExtendedSortedIndexListWithNormals(class Vector,class Vector __near *,struct CParticleVisibilityData __near *,class CParticleCollection __near *,bool,void __near *,struct ParticleRenderDataWithNormal_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GenerateExtendedSortedIndexListWithNormals(
        Vector vecCamera,
        Vector *pCameraFwd,
        CParticleVisibilityData *pVisibilityData,
        CParticleCollection *pParticles,
        bool bSorted,
        void *pOutBuf,
        ParticleFullRenderData_Scalar_View **pParticlePtrs)
{
  CParticleCollection *v7; // edi
  float m_flTargetDrawTime; // xmm0_4
  float m_flCurTime; // xmm1_4
  float m_flPrevSimTime; // xmm2_4
  bool v11; // bl
  ParticleRenderDataWithNormal_Scalar_View **v12; // esi
  int m_nActiveParticles; // edi

  v7 = pParticles;
  m_flTargetDrawTime = pParticles->m_flTargetDrawTime;
  m_flCurTime = pParticles->m_flCurTime;
  if ( m_flCurTime <= m_flTargetDrawTime
    || (m_flPrevSimTime = pParticles->m_flPrevSimTime, m_flTargetDrawTime < m_flPrevSimTime)
    || pParticles->m_pPreviousAttributeMemory == nullptr
    || pParticles->m_bFrozen )
  {
    v11 = bSorted;
    v12 = (ParticleRenderDataWithNormal_Scalar_View **)pParticlePtrs;
    s_GenerateExtendedData<0,0,ParticleRenderDataWithNormal_SIMD_View,0,1>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: vecCamera,
      pCameraFwd: nullptr,
      pVisibilityData,
      pParticles,
      flInterpT: 0.0,
      bSort: bSorted);
  }
  else
  {
    v11 = bSorted;
    v12 = (ParticleRenderDataWithNormal_Scalar_View **)pParticlePtrs;
    s_GenerateExtendedData<0,1,ParticleRenderDataWithNormal_SIMD_View,0,1>(
      pOutbuf: pOutBuf,
      pIndexBuffer: pParticlePtrs,
      CameraPos: vecCamera,
      pCameraFwd: nullptr,
      pVisibilityData,
      pParticles,
      flInterpT: (float)(m_flTargetDrawTime - m_flPrevSimTime) / (float)(m_flCurTime - m_flPrevSimTime),
      bSort: bSorted);
  }
  m_nActiveParticles = v7->m_nActiveParticles;
  if ( v11 )
  {
    if ( 4 * m_nActiveParticles > 4 )
      std::_Make_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First: v12,
        _Last: &v12[m_nActiveParticles],
        _Pred: SortLessFuncExtended,
        __formal: nullptr,
        __formal: nullptr);
    std::_Sort_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
      _First: v12,
      _Last: &v12[m_nActiveParticles],
      _Pred: SortLessFuncExtended);
  }
  return m_nActiveParticles;
}

//------------------------------------------------------------------------------
// Address: 0x1035DC20
// Name: struct ParticleFullRenderData_Scalar_View __near * __near * GetExtendedRenderList(class CParticleCollection __near *,class IMatRenderContext __near *,bool,int __near *,struct CParticleVisibilityData __near *)
// Source: json
//------------------------------------------------------------------------------
ParticleFullRenderData_Scalar_View **__cdecl GetExtendedRenderList(
        CParticleCollection *pParticles,
        IMatRenderContext *pRenderContext,
        bool bSorted,
        int *pNparticles,
        CParticleVisibilityData *pVisibilityData)
{
  int ExtendedSortedIndexList; // eax
  Vector vecCamera; // [esp+4h] [ebp-Ch] BYREF

  if ( bSorted )
    bSorted = pParticles->m_pDef.m_pObject->m_bShouldSort;
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &vecCamera);
  ExtendedSortedIndexList = GenerateExtendedSortedIndexList(
                              vecCamera,
                              pCameraFwd: nullptr,
                              pVisibilityData,
                              pParticles,
                              bSorted,
                              pOutBuf: &s_SortBuffer,
                              pParticlePtrs: s_pParticlePtrs);
  *pNparticles = ExtendedSortedIndexList;
  return &s_pParticlePtrs[ExtendedSortedIndexList];
}

//------------------------------------------------------------------------------
// Address: 0x1035DC90
// Name: struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near * GetExtendedRenderListWithPerParticleGlow(class CParticleCollection __near *,class IMatRenderContext __near *,bool,int __near *,struct CParticleVisibilityData __near *)
// Source: json
//------------------------------------------------------------------------------
ParticleFullRenderData_Scalar_View **__cdecl GetExtendedRenderListWithPerParticleGlow(
        CParticleCollection *pParticles,
        IMatRenderContext *pRenderContext,
        bool bSorted,
        int *pNparticles,
        CParticleVisibilityData *pVisibilityData)
{
  int ExtendedSortedIndexListWithPerParticleGlow; // eax
  Vector vecCamera; // [esp+4h] [ebp-Ch] BYREF

  if ( bSorted )
    bSorted = pParticles->m_pDef.m_pObject->m_bShouldSort;
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &vecCamera);
  ExtendedSortedIndexListWithPerParticleGlow = GenerateExtendedSortedIndexListWithPerParticleGlow(
                                                 vecCamera,
                                                 pCameraFwd: nullptr,
                                                 pVisibilityData,
                                                 pParticles,
                                                 bSorted,
                                                 pOutBuf: &s_SortBuffer,
                                                 pParticlePtrs: s_pParticlePtrs);
  *pNparticles = ExtendedSortedIndexListWithPerParticleGlow;
  return &s_pParticlePtrs[ExtendedSortedIndexListWithPerParticleGlow];
}

//------------------------------------------------------------------------------
// Address: 0x1035DD00
// Name: struct ParticleRenderDataWithNormal_Scalar_View __near * __near * GetExtendedRenderListWithNormals(class CParticleCollection __near *,class IMatRenderContext __near *,bool,int __near *,struct CParticleVisibilityData __near *)
// Source: json
//------------------------------------------------------------------------------
ParticleFullRenderData_Scalar_View **__cdecl GetExtendedRenderListWithNormals(
        CParticleCollection *pParticles,
        IMatRenderContext *pRenderContext,
        bool bSorted,
        int *pNparticles,
        CParticleVisibilityData *pVisibilityData)
{
  int ExtendedSortedIndexListWithNormals; // eax
  Vector vecCamera; // [esp+4h] [ebp-Ch] BYREF

  if ( bSorted )
    bSorted = pParticles->m_pDef.m_pObject->m_bShouldSort;
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &vecCamera);
  ExtendedSortedIndexListWithNormals = GenerateExtendedSortedIndexListWithNormals(
                                         vecCamera,
                                         pCameraFwd: nullptr,
                                         pVisibilityData,
                                         pParticles,
                                         bSorted,
                                         pOutBuf: &s_SortBuffer,
                                         pParticlePtrs: s_pParticlePtrs);
  *pNparticles = ExtendedSortedIndexListWithNormals;
  return &s_pParticlePtrs[ExtendedSortedIndexListWithNormals];
}

} // namespace client
