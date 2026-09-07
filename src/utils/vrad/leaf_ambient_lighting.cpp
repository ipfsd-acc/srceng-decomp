// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/leaf_ambient_lighting.cpp
// Functions: 16
// ============================================================

#include "utils\vrad\leaf_ambient_lighting.h"

//------------------------------------------------------------------------------
// Address: 0x100072F0
// Name: public: void Vector::Init(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector::Init(Vector *this, float ix, float iy, float iz)
{
  this->x = ix;
  this->y = iy;
  this->z = iz;
}

//------------------------------------------------------------------------------
// Address: 0x10007320
// Name: void AddEmitSurfaceLights(class Vector const __near &,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall AddEmitSurfaceLights(float a1@<ebp>, const Vector *vStart, Vector *lightBoxColor)
{
  int v4; // edi
  float *v5; // edi
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  double v11; // xmm0_8
  float y; // xmm4_4
  float x; // xmm5_4
  float z; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  _BYTE v44[108]; // [esp-Ch] [ebp-BCh] OVERLAPPED BYREF
  __m128 v45; // [esp+64h] [ebp-4Ch] OVERLAPPED BYREF
  Vector v46; // [esp+80h] [ebp-30h]
  Vector vDelta; // [esp+8Ch] [ebp-24h] BYREF
  Vector vDeltaNorm; // [esp+98h] [ebp-18h]
  float flDistanceScale; // [esp+A4h] [ebp-Ch]
  void *v50; // [esp+A8h] [ebp-8h]
  void *retaddr; // [esp+B0h] [ebp+0h]

  flDistanceScale = a1;
  v50 = retaddr;
  *(__m128 *)v44 = _mm_shuffle_ps((__m128)LODWORD(vStart->x), (__m128)LODWORD(vStart->x), 0);
  *(__m128 *)&v44[16] = _mm_shuffle_ps((__m128)LODWORD(vStart->y), (__m128)LODWORD(vStart->y), 0);
  v4 = 0;
  *(__m128 *)&v44[32] = _mm_shuffle_ps((__m128)LODWORD(vStart->z), (__m128)LODWORD(vStart->z), 0);
  vDeltaNorm.z = 0.0;
  if ( *pNumworldlights > 0 )
  {
    vDeltaNorm.y = 0.0;
    do
    {
      v5 = (float *)((char *)&dworldlights->origin.x + v4);
      if ( ((_BYTE)v5[22] & 1) != 0 )
      {
        *(__m128 *)&v44[48] = _mm_shuffle_ps((__m128)*(unsigned int *)v5, (__m128)*(unsigned int *)v5, 0);
        *(__m128 *)&v44[64] = _mm_shuffle_ps((__m128)*((unsigned int *)v5 + 1), (__m128)*((unsigned int *)v5 + 1), 0);
        *(__m128 *)&v44[80] = _mm_shuffle_ps((__m128)*((unsigned int *)v5 + 2), (__m128)*((unsigned int *)v5 + 2), 0);
        TestLine(
          start: (const FourVectors *)v44,
          stop: (const FourVectors *)&v44[48],
          pFractionVisible: &v45,
          static_prop_index_to_ignore: -1);
        if ( _mm_movemask_ps(_mm_cmplt_ps(Four_Zeros, v45)) != 0 )
        {
          v6 = *v5 - vStart->x;
          v7 = v5[1] - vStart->y;
          v8 = v5[2] - vStart->z;
          v9 = v5[18];
          v46.x = v6;
          v46.y = v7;
          v46.z = v8;
          if ( v9 == 0.0 || (float)((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8)) <= (float)(v9 * v9) )
          {
            v10 = (float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8);
            v11 = v10 >= 1.0 ? v10 : 1.0;
            vDeltaNorm.x = 1.0 / v11;
          }
          else
          {
            vDeltaNorm.x = 0.0;
          }
          vDelta = v46;
          VectorNormalize(vec: &vDelta);
          y = vDelta.y;
          x = vDelta.x;
          z = vDelta.z;
          v15 = (float)((float)(y * y) + (float)(x * x)) + (float)(z * z);
          if ( v15 >= 0.0 )
          {
            LODWORD(v17) = COERCE_UNSIGNED_INT((float)((float)(v5[7] * vDelta.y) + (float)(v5[6] * vDelta.x)) + (float)(v5[8] * vDelta.z))
                         ^ _mask__NegFloat_;
            v16 = v17 > 0.01 ? v17 * v15 : 0.0;
          }
          else
          {
            v16 = 0.0;
          }
          v18 = (float)(v16 * vDeltaNorm.x) * v45.m128_f32[0];
          if ( v18 != 0.0 )
          {
            v19 = (float)((float)(vDelta.y * g_BoxDirections[0].y) + (float)(vDelta.x * g_BoxDirections[0].x))
                + (float)(vDelta.z * g_BoxDirections[0].z);
            if ( v19 > 0.0 )
            {
              v20 = v19 * v18;
              v21 = (float)(v20 * v5[3]) + lightBoxColor->x;
              *(float *)&v44[104] = v5[4] * v20;
              v22 = v5[5] * v20;
              lightBoxColor->y = lightBoxColor->y + *(float *)&v44[104];
              v23 = lightBoxColor->z + v22;
              lightBoxColor->x = v21;
              lightBoxColor->z = v23;
            }
            v24 = (float)((float)(y * g_BoxDirections[1].y) + (float)(x * g_BoxDirections[1].x))
                + (float)(z * g_BoxDirections[1].z);
            if ( v24 > 0.0 )
            {
              v25 = v24 * v18;
              v26 = v5[5] * v25;
              v27 = v5[4] * v25;
              lightBoxColor[1].x = lightBoxColor[1].x + (float)(v25 * v5[3]);
              lightBoxColor[1].y = v27 + lightBoxColor[1].y;
              lightBoxColor[1].z = v26 + lightBoxColor[1].z;
            }
            v28 = (float)((float)(y * g_BoxDirections[2].y) + (float)(x * g_BoxDirections[2].x))
                + (float)(z * g_BoxDirections[2].z);
            if ( v28 > 0.0 )
            {
              v29 = v28 * v18;
              v30 = v5[5] * v29;
              v31 = v5[4] * v29;
              lightBoxColor[2].x = lightBoxColor[2].x + (float)(v29 * v5[3]);
              lightBoxColor[2].y = v31 + lightBoxColor[2].y;
              lightBoxColor[2].z = v30 + lightBoxColor[2].z;
            }
            v32 = (float)((float)(y * g_BoxDirections[3].y) + (float)(x * g_BoxDirections[3].x))
                + (float)(z * g_BoxDirections[3].z);
            if ( v32 > 0.0 )
            {
              v33 = v32 * v18;
              v34 = v5[5] * v33;
              v35 = v5[4] * v33;
              lightBoxColor[3].x = lightBoxColor[3].x + (float)(v33 * v5[3]);
              lightBoxColor[3].y = v35 + lightBoxColor[3].y;
              lightBoxColor[3].z = v34 + lightBoxColor[3].z;
            }
            v36 = (float)((float)(g_BoxDirections[4].y * y) + (float)(g_BoxDirections[4].x * x))
                + (float)(g_BoxDirections[4].z * z);
            if ( v36 > 0.0 )
            {
              v37 = v36 * v18;
              v38 = v5[5] * v37;
              v39 = v5[4] * v37;
              lightBoxColor[4].x = lightBoxColor[4].x + (float)(v37 * v5[3]);
              lightBoxColor[4].y = v39 + lightBoxColor[4].y;
              lightBoxColor[4].z = v38 + lightBoxColor[4].z;
            }
            v40 = (float)((float)(g_BoxDirections[5].y * y) + (float)(g_BoxDirections[5].x * x))
                + (float)(g_BoxDirections[5].z * z);
            if ( v40 > 0.0 )
            {
              v41 = v40 * v18;
              v42 = v5[4] * v41;
              v43 = v5[5] * v41;
              lightBoxColor[5].x = lightBoxColor[5].x + (float)(v41 * v5[3]);
              lightBoxColor[5].y = v42 + lightBoxColor[5].y;
              lightBoxColor[5].z = v43 + lightBoxColor[5].z;
            }
          }
        }
      }
      v4 = LODWORD(vDeltaNorm.y) + 100;
      ++LODWORD(vDeltaNorm.z);
      LODWORD(vDeltaNorm.y) += 100;
    }
    while ( SLODWORD(vDeltaNorm.z) < *pNumworldlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007840
// Name: void ComputeAmbientFromSphericalSamples(int,class Vector const __near &,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeAmbientFromSphericalSamples(
        long double a1@<esi:edi>,
        int iThread,
        const Vector *vStart,
        Vector *lightBoxColor)
{
  int i; // esi
  float x; // xmm2_4
  float z; // xmm1_4
  float v7; // xmm1_4
  TableVector *v8; // edx
  float *p_y; // ecx
  int v10; // esi
  float v11; // xmm0_4
  unsigned int j; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  Vector lightStyleColors[64]; // [esp+10h] [ebp-AA8h] BYREF
  Vector radcolor[162]; // [esp+310h] [ebp-7A8h]
  Vector vEnd; // [esp+AA8h] [ebp-10h] BYREF
  float tanTheta; // [esp+AB4h] [ebp-4h]
  int savedregs; // [esp+AB8h] [ebp+0h] BYREF

  __libm_sse2_tan(x: a1);
  tanTheta = 0.1269727051258087;
  for ( i = 0; i < 162; ++i )
  {
    x = g_anorms[i].x;
    z = g_anorms[i].z;
    vEnd.y = (float)(g_anorms[i].y * 57016.32) + vStart->y;
    v7 = (float)(z * 57016.32) + vStart->z;
    vEnd.x = vStart->x + (float)(x * 57016.32);
    vEnd.z = v7;
    memset(lightStyleColors, 0, 12);
    CalcRayAmbientLighting(iThread, vStart, &vEnd, tanTheta, color: lightStyleColors);
    radcolor[i].x = lightStyleColors[0].x;
    radcolor[i].y = lightStyleColors[0].y;
    radcolor[i].z = lightStyleColors[0].z;
  }
  v8 = &g_BoxDirections[5];
  p_y = &lightBoxColor[5].y;
  v10 = (char *)&g_BoxDirections[0].y - (char *)lightBoxColor;
  do
  {
    v11 = 0.0;
    *(p_y - 1) = 0.0;
    *p_y = 0.0;
    p_y[1] = 0.0;
    for ( j = 0; (int)j < 1944; j += 72 )
    {
      v13 = (float)((float)(g_anorms[j / 0xC].x * v8->x)
                  + (float)(g_anorms[j / 0xC].y * *(float *)((char *)p_y + v10 - 4)))
          + (float)(g_anorms[j / 0xC].z * *(float *)((char *)p_y + v10));
      if ( v13 > 0.0 )
      {
        v11 = v11 + v13;
        v14 = (float)(radcolor[j / 0xC].z * v13) + p_y[1];
        v15 = radcolor[j / 0xC].y * v13;
        *(p_y - 1) = *(p_y - 1) + (float)(radcolor[j / 0xC].x * v13);
        *p_y = *p_y + v15;
        p_y[1] = v14;
      }
      v16 = (float)((float)(*(float *)&dword_10135D28[j / 4] * *(float *)((char *)p_y + v10 - 4))
                  + (float)(g_anorms[j / 0xC + 1].x * v8->x))
          + (float)(*(float *)&dword_10135D2C[j / 4] * *(float *)((char *)p_y + v10));
      if ( v16 > 0.0 )
      {
        v11 = v11 + v16;
        v17 = (float)(radcolor[j / 0xC + 1].z * v16) + p_y[1];
        v18 = radcolor[j / 0xC + 1].y * v16;
        *(p_y - 1) = *(p_y - 1) + (float)(radcolor[j / 0xC + 1].x * v16);
        *p_y = *p_y + v18;
        p_y[1] = v17;
      }
      v19 = (float)((float)(*(float *)&dword_10135D34[j / 4] * *(float *)((char *)p_y + v10 - 4))
                  + (float)(*(float *)&dword_10135D30[j / 4] * v8->x))
          + (float)(*(float *)&dword_10135D38[j / 4] * *(float *)((char *)p_y + v10));
      if ( v19 > 0.0 )
      {
        v11 = v11 + v19;
        v20 = (float)(radcolor[j / 0xC + 2].z * v19) + p_y[1];
        v21 = radcolor[j / 0xC + 2].y * v19;
        *(p_y - 1) = *(p_y - 1) + (float)(radcolor[j / 0xC + 2].x * v19);
        *p_y = *p_y + v21;
        p_y[1] = v20;
      }
      v22 = (float)((float)(*(float *)&dword_10135D40[j / 4] * *(float *)((char *)p_y + v10 - 4))
                  + (float)(*(float *)&dword_10135D3C[j / 4] * v8->x))
          + (float)(*(float *)&dword_10135D44[j / 4] * *(float *)((char *)p_y + v10));
      if ( v22 > 0.0 )
      {
        v11 = v11 + v22;
        v23 = (float)(radcolor[j / 0xC + 3].z * v22) + p_y[1];
        v24 = radcolor[j / 0xC + 3].y * v22;
        *(p_y - 1) = *(p_y - 1) + (float)(radcolor[j / 0xC + 3].x * v22);
        *p_y = *p_y + v24;
        p_y[1] = v23;
      }
      v25 = (float)((float)(*(float *)&dword_10135D4C[j / 4] * *(float *)((char *)p_y + v10 - 4))
                  + (float)(*(float *)&dword_10135D48[j / 4] * v8->x))
          + (float)(*(float *)&dword_10135D50[j / 4] * *(float *)((char *)p_y + v10));
      if ( v25 > 0.0 )
      {
        v11 = v11 + v25;
        v26 = (float)(radcolor[j / 0xC + 4].z * v25) + p_y[1];
        v27 = radcolor[j / 0xC + 4].y * v25;
        *(p_y - 1) = *(p_y - 1) + (float)(radcolor[j / 0xC + 4].x * v25);
        *p_y = *p_y + v27;
        p_y[1] = v26;
      }
      v28 = (float)((float)(*(float *)&dword_10135D58[j / 4] * *(float *)((char *)p_y + v10 - 4))
                  + (float)(*(float *)&dword_10135D54[j / 4] * v8->x))
          + (float)(*(float *)&dword_10135D5C[j / 4] * *(float *)((char *)p_y + v10));
      if ( v28 > 0.0 )
      {
        v11 = v11 + v28;
        v29 = (float)(radcolor[j / 0xC + 5].z * v28) + p_y[1];
        v30 = radcolor[j / 0xC + 5].y * v28;
        *(p_y - 1) = *(p_y - 1) + (float)(radcolor[j / 0xC + 5].x * v28);
        *p_y = *p_y + v30;
        p_y[1] = v29;
      }
    }
    *(p_y - 1) = (float)(1.0 / v11) * *(p_y - 1);
    v31 = (float)(1.0 / v11) * p_y[1];
    *p_y = *p_y * (float)(1.0 / v11);
    p_y[1] = v31;
    --v8;
    p_y -= 3;
  }
  while ( (int)v8 >= (int)g_BoxDirections );
  AddEmitSurfaceLights(a1: COERCE_FLOAT(&savedregs), vStart, lightBoxColor);
}

//------------------------------------------------------------------------------
// Address: 0x10007D00
// Name: int CubeDeltaGammaSpace(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CubeDeltaGammaSpace(Vector *pCube0, Vector *pCube1)
{
  Vector *v2; // edi
  signed int v3; // ebx
  int v4; // eax
  signed int v5; // eax
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  v2 = pCube1;
  v3 = 0;
  for ( i = 6; i != 0; --i )
  {
    for ( j = 3; j != 0; --j )
    {
      v4 = LinearToScreenGamma(f: *(float *)((char *)&v2->x + (char *)pCube0 - (char *)pCube1));
      v5 = abs32(v4 - LinearToScreenGamma(f: v2->x));
      if ( v5 > v3 )
        v3 = v5;
      v2 = (Vector *)((char *)v2 + 4);
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10007EC0
// Name: public: void CLeafSampler::GenerateLeafSamplePosition(int,class CUtlVector<struct dplane_t,class CUtlMemory<struct dplane_t,int>> const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeafSampler::GenerateLeafSamplePosition(
        CLeafSampler *this,
        int leafIndex,
        const CUtlVector<dplane_t,CUtlMemory<dplane_t,int> > *leafPlanes,
        Vector *samplePosition)
{
  dleaf_t *v4; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  float v8; // xmm0_4
  int v9; // eax
  float v10; // xmm0_4
  int v11; // edx
  char v13; // al
  CUniformRandomStream *p_m_random; // edi
  double v15; // st7
  double v16; // st7
  int v17; // eax
  dplane_t *v18; // ecx
  int v19; // edi
  __int64 v20; // xmm0_8
  int v21; // eax
  __int16 v22; // cx
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // [esp+14h] [ebp-44h]
  float v26; // [esp+14h] [ebp-44h]
  Vector normal; // [esp+24h] [ebp-34h] BYREF
  Vector start; // [esp+30h] [ebp-28h] BYREF
  float t; // [esp+3Ch] [ebp-1Ch] BYREF
  float v30; // [esp+40h] [ebp-18h]
  float dz; // [esp+44h] [ebp-14h]
  float dy; // [esp+48h] [ebp-10h]
  float v33; // [esp+4Ch] [ebp-Ch]
  int i; // [esp+50h] [ebp-8h]
  CLeafSampler *v35; // [esp+54h] [ebp-4h]
  char bValid_3; // [esp+6Bh] [ebp+13h]

  v4 = &dleafs[leafIndex];
  v5 = v4->maxs[0];
  v6 = v4->maxs[1];
  v35 = this;
  v7 = v4->maxs[2];
  v8 = (float)(v5 - v4->mins[0]);
  v9 = v4->mins[1];
  v33 = v8;
  v10 = (float)(v6 - v9);
  v11 = v4->mins[2];
  dy = v10;
  dz = (float)(v7 - v11);
  v13 = 0;
  i = 0;
  while ( v13 == 0 )
  {
    p_m_random = &v35->m_random;
    v15 = ((double (__thiscall *)(CUniformRandomStream *, _DWORD, _DWORD))v35->m_random.RandomFloat)(
            a1: &v35->m_random,
            a2: 0,
            a3: LODWORD(v33));
    v25 = dy;
    samplePosition->x = v15 + (double)v4->mins[0];
    v16 = ((double (__thiscall *)(CUniformRandomStream *, _DWORD, _DWORD))p_m_random->RandomFloat)(
            a1: p_m_random,
            a2: 0,
            a3: LODWORD(v25));
    v26 = dz;
    samplePosition->y = v16 + (double)v4->mins[1];
    bValid_3 = 1;
    v30 = ((double (__thiscall *)(CUniformRandomStream *, _DWORD, _DWORD))p_m_random->RandomFloat)(
            a1: p_m_random,
            a2: 0,
            a3: LODWORD(v26))
        + (double)v4->mins[2];
    samplePosition->z = v30;
    v17 = leafPlanes->m_Size - 1;
    if ( v17 < 0 )
    {
LABEL_8:
      v19 = 0;
      while ( 1 )
      {
        v20 = *(_QWORD *)&samplePosition->x;
        start.z = samplePosition->z;
        v21 = v19 % 3;
        *(_QWORD *)&start.x = v20;
        v22 = v19 >= 3 ? v4->maxs[v21] : v4->mins[v21];
        *(&start.x + v21) = (float)v22;
        CastRayInLeaf(
          iThread: v35->m_iThread,
          start: samplePosition,
          end: &start,
          leafIndex,
          pFraction: &t,
          pNormal: &normal);
        if ( t == 0.0
          || t != 1.0
          && (float)((float)((float)(normal.y * (float)(start.y - samplePosition->y))
                           + (float)((float)(start.x - samplePosition->x) * normal.x))
                   + (float)(normal.z * (float)(start.z - samplePosition->z))) > 0.0 )
        {
          break;
        }
        if ( ++v19 >= 6 )
          goto LABEL_12;
      }
    }
    else
    {
      v18 = &leafPlanes->m_Memory.m_pMemory[v17];
      while ( (float)((float)((float)((float)(v18->normal.y * samplePosition->y)
                                    + (float)(samplePosition->x * v18->normal.x))
                            + (float)(v18->normal.z * v30))
                    - v18->dist) >= 0.03125 )
      {
        --v18;
        if ( --v17 < 0 )
          goto LABEL_8;
      }
    }
    bValid_3 = 0;
LABEL_12:
    if ( ++i >= 1000 )
    {
      if ( bValid_3 == 0 )
      {
        v23 = (float)((float)v4->mins[1] + (float)v4->maxs[1]) * 0.5;
        v24 = (float)((float)v4->mins[2] + (float)v4->maxs[2]) * 0.5;
        samplePosition->x = (float)((float)v4->mins[0] + (float)v4->maxs[0]) * 0.5;
        samplePosition->y = v23;
        samplePosition->z = v24;
      }
      return;
    }
    v13 = bValid_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100081A0
// Name: void Mod_LeafAmbientColorAtPos(class Vector __near *,class Vector const __near &,class CUtlVector<struct ambientsample_t,class CUtlMemory<struct ambientsample_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LeafAmbientColorAtPos(
        Vector *pOut,
        const Vector *pos,
        const CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *list,
        int skipIndex)
{
  float v4; // xmm5_4
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float x; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  int i; // [esp+0h] [ebp-4h]

  v4 = 0.0;
  pOut->x = 0.0;
  pOut[1].x = 0.0;
  pOut->y = 0.0;
  pOut->z = 0.0;
  pOut[1].y = 0.0;
  pOut[1].z = 0.0;
  pOut[2].x = 0.0;
  pOut[2].y = 0.0;
  pOut[2].z = 0.0;
  pOut[3].x = 0.0;
  pOut[3].y = 0.0;
  pOut[3].z = 0.0;
  pOut[4].x = 0.0;
  pOut[4].y = 0.0;
  pOut[4].z = 0.0;
  pOut[5].x = 0.0;
  pOut[5].y = 0.0;
  v5 = 0;
  pOut[5].z = 0.0;
  i = 0;
  if ( list->m_Size > 0 )
  {
    v6 = 0;
    v7 = 3;
    do
    {
      if ( v5 != skipIndex )
      {
        v8 = list->m_Memory.m_pMemory[v6].pos.y - pos->y;
        v9 = list->m_Memory.m_pMemory[v6].pos.z - pos->z;
        v10 = list->m_Memory.m_pMemory[v6].pos.x - pos->x;
        v11 = 1.0 / (float)((float)((float)((float)(v8 * v8) + (float)(v10 * v10)) + (float)(v9 * v9)) + 1.0);
        v12 = (float)(*(float *)((char *)list->m_Memory.m_pMemory + v7 * 12 - 16) * v11) + pOut->z;
        v4 = v4 + v11;
        v13 = *(float *)((char *)list->m_Memory.m_pMemory + v7 * 12 - 20);
        pOut->x = pOut->x + (float)(*(float *)((char *)list->m_Memory.m_pMemory + v7 * 12 - 24) * v11);
        x = pOut[1].x;
        pOut->z = v12;
        pOut->y = (float)(v13 * v11) + pOut->y;
        v15 = *(float *)((char *)list->m_Memory.m_pMemory + v7 * 12 - 8);
        v16 = *(float *)((char *)list->m_Memory.m_pMemory + v7 * 12 - 4);
        pOut[1].x = x + (float)(*(float *)((char *)list->m_Memory.m_pMemory + v7 * 12 - 12) * v11);
        pOut[1].y = (float)(v15 * v11) + pOut[1].y;
        pOut[1].z = (float)(v16 * v11) + pOut[1].z;
        v17 = *(float *)((char *)&list->m_Memory.m_pMemory->pos.y + v7 * 12);
        v18 = *(float *)((char *)&list->m_Memory.m_pMemory->pos.z + v7 * 12);
        pOut[2].x = pOut[2].x + (float)(*(float *)((char *)&list->m_Memory.m_pMemory->pos.x + v7 * 12) * v11);
        pOut[2].y = (float)(v17 * v11) + pOut[2].y;
        pOut[2].z = (float)(v18 * v11) + pOut[2].z;
        y = list->m_Memory.m_pMemory->cube[v7].y;
        z = list->m_Memory.m_pMemory->cube[v7].z;
        pOut[3].x = pOut[3].x + (float)(list->m_Memory.m_pMemory->cube[v7].x * v11);
        pOut[3].y = (float)(y * v11) + pOut[3].y;
        pOut[3].z = (float)(z * v11) + pOut[3].z;
        v21 = list->m_Memory.m_pMemory->cube[v7 + 1].y * v11;
        v22 = list->m_Memory.m_pMemory->cube[v7 + 1].z * v11;
        pOut[4].x = pOut[4].x + (float)(list->m_Memory.m_pMemory->cube[v7 + 1].x * v11);
        pOut[4].y = v21 + pOut[4].y;
        pOut[4].z = v22 + pOut[4].z;
        v5 = i;
        v23 = list->m_Memory.m_pMemory->cube[v7 + 2].y * v11;
        v24 = list->m_Memory.m_pMemory->cube[v7 + 2].z * v11;
        pOut[5].x = pOut[5].x + (float)(list->m_Memory.m_pMemory->cube[v7 + 2].x * v11);
        pOut[5].y = v23 + pOut[5].y;
        pOut[5].z = v24 + pOut[5].z;
      }
      ++v5;
      ++v6;
      v7 += 7;
      i = v5;
    }
    while ( v5 < list->m_Size );
  }
  pOut->x = (float)(1.0 / v4) * pOut->x;
  v25 = (float)(1.0 / v4) * pOut->z;
  pOut->y = (float)(1.0 / v4) * pOut->y;
  pOut->z = v25;
  pOut[1].x = (float)(1.0 / v4) * pOut[1].x;
  pOut[1].y = (float)(1.0 / v4) * pOut[1].y;
  pOut[1].z = (float)(1.0 / v4) * pOut[1].z;
  pOut[2].x = (float)(1.0 / v4) * pOut[2].x;
  pOut[2].y = (float)(1.0 / v4) * pOut[2].y;
  pOut[2].z = (float)(1.0 / v4) * pOut[2].z;
  pOut[3].x = (float)(1.0 / v4) * pOut[3].x;
  pOut[3].y = (float)(1.0 / v4) * pOut[3].y;
  pOut[3].z = (float)(1.0 / v4) * pOut[3].z;
  pOut[4].x = (float)(1.0 / v4) * pOut[4].x;
  pOut[4].y = (float)(1.0 / v4) * pOut[4].y;
  pOut[4].z = (float)(1.0 / v4) * pOut[4].z;
  pOut[5].x = (float)(1.0 / v4) * pOut[5].x;
  pOut[5].y = (float)(1.0 / v4) * pOut[5].y;
  pOut[5].z = (float)(1.0 / v4) * pOut[5].z;
}

//------------------------------------------------------------------------------
// Address: 0x10008520
// Name: void CompressAmbientSampleList(class CUtlVector<struct ambientsample_t,class CUtlMemory<struct ambientsample_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CompressAmbientSampleList(CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *list)
{
  int v2; // esi
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *v3; // edi
  int m_Size; // eax
  Vector testCube[6]; // [esp+8h] [ebp-4Ch] BYREF
  int i; // [esp+50h] [ebp-4h]
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *lista; // [esp+5Ch] [ebp+8h]

  v2 = 0;
  i = 0;
  if ( list->m_Size > 0 )
  {
    v3 = nullptr;
    lista = nullptr;
    do
    {
      if ( list->m_Size > 1 )
      {
        Mod_LeafAmbientColorAtPos(
          pOut: testCube,
          pos: (const Vector *)((char *)v3 + (unsigned int)list->m_Memory.m_pMemory),
          list,
          skipIndex: v2);
        if ( CubeDeltaGammaSpace(
               pCube0: testCube,
               pCube1: (Vector *)((char *)&v3->m_Size + (unsigned int)list->m_Memory.m_pMemory)) < 3 )
        {
          m_Size = list->m_Size;
          if ( m_Size > 0 )
          {
            if ( v2 != m_Size - 1 )
            {
              qmemcpy((char *)list->m_Memory.m_pMemory + (unsigned int)v3, &list->m_Memory.m_pMemory[m_Size - 1], 0x54u);
              v2 = i;
              v3 = lista;
            }
            --list->m_Size;
          }
          --v2;
          v3 = (CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *)((char *)v3 - 84);
        }
      }
      ++v2;
      v3 = (CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *)((char *)v3 + 84);
      i = v2;
      lista = v3;
    }
    while ( v2 < list->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100086B0
// Name: void GetLeafBoundaryPlanes(class CUtlVector<struct dplane_t,class CUtlMemory<struct dplane_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetLeafBoundaryPlanes(CUtlVector<dplane_t,CUtlMemory<dplane_t,int> > *list, int leafIndex)
{
  int v3; // edi
  int v4; // edx
  dnode_t *v5; // eax
  const dplane_t *v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  dplane_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  dplane_t *v14; // ecx
  int nodeIndex; // [esp+10h] [ebp+8h]

  list->m_Size = 0;
  v3 = leafparents[leafIndex];
  v4 = -1 - leafIndex;
  nodeIndex = v3;
  if ( v3 >= 0 )
  {
    while ( 1 )
    {
      v5 = &dnodes[v3];
      v6 = (const dplane_t *)((char *)&dplanes + 20 * v5->planenum);
      if ( v5->children[0] == v4 )
      {
        CUtlVector<dplane_t,CUtlMemory<dplane_t,int>>::InsertBefore(this: list, elem: list->m_Size, src: v6);
      }
      else
      {
        m_Size = list->m_Size;
        m_nAllocationCount = list->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<UtlRBTreeNode_t<float,int>,int>::Grow(
            this: (CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> *)list,
            num: m_Size - m_nAllocationCount + 1);
        ++list->m_Size;
        m_pMemory = list->m_Memory.m_pMemory;
        v10 = list->m_Size - m_Size - 1;
        list->m_pElements = list->m_Memory.m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v10);
        v11 = 5 * m_Size;
        v3 = nodeIndex;
        v11 *= 4;
        *(float *)((char *)&list->m_Memory.m_pMemory->dist + v11) = -v6->dist;
        y = v6->normal.y;
        z = v6->normal.z;
        v14 = list->m_Memory.m_pMemory;
        *(float *)((char *)&v14->normal.x + v11) = -v6->normal.x;
        *(float *)((char *)&v14->normal.y + v11) = -y;
        *(float *)((char *)&v14->normal.z + v11) = -z;
        *(int *)((char *)&list->m_Memory.m_pMemory->type + v11) = v6->type;
      }
      v4 = v3;
      nodeIndex = nodeparents[v3];
      if ( nodeIndex < 0 )
        break;
      v3 = nodeparents[v3];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100087E0
// Name: void AddSampleToList(class CUtlVector<struct ambientsample_t,class CUtlMemory<struct ambientsample_t,int>> __near &,class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSampleToList(
        CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *list,
        const Vector *samplePosition,
        Vector *pCube)
{
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *v3; // esi
  int m_nAllocationCount; // eax
  int m_Size; // edi
  ambientsample_t *m_pMemory; // ecx
  int v7; // eax
  unsigned int v8; // ecx
  ambientsample_t *v9; // edi
  int v10; // edx
  float *v11; // edx
  ambientsample_t *v12; // edi
  int v13; // edx
  float *v14; // edx
  ambientsample_t *v15; // edi
  int v16; // edx
  float *v17; // edx
  ambientsample_t *v18; // edi
  int v19; // edx
  float *v20; // edx
  int v21; // edi
  float v22; // xmm4_4
  int v23; // eax
  float v24; // xmm5_4
  int v25; // edx
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float *p_y; // ecx
  float *v30; // eax
  float v31; // xmm0_4
  int i; // edi
  float v33; // xmm1_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  int v37; // ecx
  float v38; // [esp-28h] [ebp-3Ch]
  int v39; // [esp-Ch] [ebp-20h]
  float v40; // [esp-8h] [ebp-1Ch]
  int v41; // [esp-4h] [ebp-18h]
  int nearestNeighborIndex; // [esp+0h] [ebp-14h]
  int nearestNeighborDist; // [esp+4h] [ebp-10h]

  v3 = list;
  m_nAllocationCount = list->m_Memory.m_nAllocationCount;
  m_Size = list->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ambientsample_t,int>::Grow(this: &list->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++list->m_Size;
  m_pMemory = list->m_Memory.m_pMemory;
  v7 = list->m_Size - m_Size - 1;
  list->m_pElements = list->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 84 * v7);
  list->m_Memory.m_pMemory[m_Size].pos = *samplePosition;
  v8 = 7 * m_Size;
  list->m_Memory.m_pMemory[m_Size].cube[0] = *pCube;
  v9 = list->m_Memory.m_pMemory;
  v10 = 3 * v8 + 6;
  *(&v9->pos.x + v10) = pCube[1].x;
  v11 = &v9->pos.x + v10;
  v11[1] = pCube[1].y;
  v11[2] = pCube[1].z;
  v12 = list->m_Memory.m_pMemory;
  v13 = 3 * v8 + 9;
  *(&v12->pos.x + v13) = pCube[2].x;
  v14 = &v12->pos.x + v13;
  v14[1] = pCube[2].y;
  v14[2] = pCube[2].z;
  v15 = list->m_Memory.m_pMemory;
  v16 = 3 * v8 + 12;
  *(&v15->pos.x + v16) = pCube[3].x;
  v17 = &v15->pos.x + v16;
  v17[1] = pCube[3].y;
  v17[2] = pCube[3].z;
  v18 = list->m_Memory.m_pMemory;
  v19 = 3 * v8 + 15;
  *(&v18->pos.x + v19) = pCube[4].x;
  v20 = &v18->pos.x + v19;
  v20[1] = pCube[4].y;
  v20[2] = pCube[4].z;
  list->m_Memory.m_pMemory[v8 / 7].cube[5] = pCube[5];
  if ( list->m_Size > 16 )
  {
    v21 = 0;
    v39 = 0;
    v40 = 3.4028235e38;
    nearestNeighborDist = 0;
    nearestNeighborIndex = 0;
    do
    {
      v22 = 3.4028235e38;
      v23 = 0;
      v24 = 0.0;
      v41 = 0;
      v25 = 0;
      do
      {
        if ( v23 != nearestNeighborDist )
        {
          v26 = *(float *)((char *)&list->m_Memory.m_pMemory->pos.x + v21) - list->m_Memory.m_pMemory[v25].pos.x;
          v27 = *(float *)((char *)&list->m_Memory.m_pMemory->pos.z + v21) - list->m_Memory.m_pMemory[v25].pos.z;
          v28 = *(float *)((char *)&list->m_Memory.m_pMemory->pos.y + v21) - list->m_Memory.m_pMemory[v25].pos.y;
          p_y = &list->m_Memory.m_pMemory[v25].cube[0].y;
          v38 = fsqrt((float)((float)(v27 * v27) + (float)(v28 * v28)) + (float)(v26 * v26));
          v30 = (float *)((char *)&list->m_Memory.m_pMemory->cube[0].y + v21);
          v31 = 0.0;
          for ( i = 6; i != 0; --i )
          {
            v33 = fabs(*(v30 - 1) - *(p_y - 1));
            if ( v31 <= v33 )
              v31 = v33;
            v34 = fabs(*v30 - *p_y);
            if ( v31 <= v34 )
              v31 = v34;
            v35 = fabs(v30[1] - p_y[1]);
            if ( v31 <= v35 )
              v31 = v35;
            v30 += 3;
            p_y += 3;
            v24 = v31 + v24;
          }
          if ( v31 >= 0.000099999997 )
          {
            if ( v31 > 1.0 )
              v31 = 1.0;
          }
          else
          {
            v31 = 0.0;
          }
          v36 = (float)((float)(v31 * 0.89999998) + 0.1) * v38;
          v21 = nearestNeighborIndex;
          if ( v22 > v36 )
            v22 = v36;
        }
        v37 = list->m_Size;
        v23 = v41 + 1;
        ++v25;
        v41 = v23;
      }
      while ( v23 < v37 );
      if ( v40 > v22 || v22 == v40 && v24 < 0.0 )
      {
        v40 = v22;
        v39 = nearestNeighborDist;
      }
      v21 += 84;
      ++nearestNeighborDist;
      nearestNeighborIndex = v21;
    }
    while ( nearestNeighborDist < v37 );
    if ( v37 > 0 )
    {
      if ( v39 != v37 - 1 )
      {
        qmemcpy(
          &list->m_Memory.m_pMemory[v39],
          &list->m_Memory.m_pMemory[v37 - 1],
          sizeof(list->m_Memory.m_pMemory[v39]));
        v3 = list;
      }
      --v3->m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008AD0
// Name: public: virtual bool CLeafList::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLeafList::EnumerateLeaf(CLeafList *this, int leaf, int context)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_list; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v7; // eax
  S3RGBA *v8; // edi
  bool result; // al

  m_nAllocationCount = this->m_list.m_Memory.m_nAllocationCount;
  p_m_list = (CUtlMemory<S3RGBA,int> *)&this->m_list;
  m_Size = this->m_list.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: p_m_list, num: m_Size - m_nAllocationCount + 1);
  ++p_m_list[1].m_pMemory;
  m_pMemory = p_m_list->m_pMemory;
  v7 = (int)p_m_list[1].m_pMemory - m_Size - 1;
  p_m_list[1].m_nAllocationCount = (int)p_m_list->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_list->m_pMemory[m_Size];
  result = true;
  if ( v8 != nullptr )
    *v8 = (S3RGBA)leaf;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008B30
// Name: int NearestNeighborWithLight(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall NearestNeighborWithLight@<eax>(float a1@<ebp>, int a2@<edi>, int a3@<esi>, int leafID)
{
  int v4; // edx
  float v5; // xmm1_4
  int v6; // ecx
  float v7; // xmm3_4
  int v8; // edx
  float v9; // xmm2_4
  int v10; // ecx
  ISpatialQuery *v11; // eax
  float v12; // xmm6_4
  int v13; // edx
  void *v14; // esi
  float v15; // ecx
  float x; // xmm0_4
  float v17; // xmm1_4
  float y; // xmm3_4
  float z; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  __int128 v27; // xmm0
  void **v29; // [esp-Ch] [ebp-74h] BYREF
  void *v30; // [esp-8h] [ebp-70h]
  int v31; // [esp-4h] [ebp-6Ch]
  _BYTE leafList[28]; // [esp+0h] [ebp-68h] OVERLAPPED BYREF
  float v33[5]; // [esp+24h] [ebp-44h] BYREF
  float v34; // [esp+38h] [ebp-30h]
  Vector size; // [esp+3Ch] [ebp-2Ch]
  Vector maxs; // [esp+48h] [ebp-20h]
  Vector mins; // [esp+54h] [ebp-14h]
  void *v38; // [esp+60h] [ebp-8h]
  void *retaddr; // [esp+68h] [ebp+0h]

  mins.z = a1;
  v38 = retaddr;
  v4 = word_1135AAC0[16 * leafID];
  v5 = (float)word_1135AAB8[16 * leafID];
  v6 = word_1135AABA[16 * leafID];
  size.x = (float)word_1135AABE[16 * leafID];
  v7 = (float)v4;
  v8 = word_1135AAC2[16 * leafID];
  v33[3] = size.x - v5;
  v9 = (float)v6;
  v10 = word_1135AABC[16 * leafID];
  v33[4] = v7 - v9;
  maxs.x = v5;
  maxs.y = v9;
  size.y = v7;
  maxs.z = (float)v10;
  size.z = (float)v8;
  v34 = (float)v8 - (float)v10;
  v29 = &CLeafList::`vftable';
  v30 = nullptr;
  v31 = 0;
  memset(leafList, 0, 12);
  v11 = ToolBSPTree();
  v33[2] = v34 + size.z;
  *(float *)&leafList[20] = v9 - (float)(v7 - v9);
  v33[0] = (float)(size.x - v5) + size.x;
  v33[1] = (float)(v7 - v9) + v7;
  *(float *)&leafList[16] = v5 - (float)(size.x - v5);
  *(float *)&leafList[24] = maxs.z - v34;
  ((void (__thiscall *)(ISpatialQuery *, _BYTE *, float *, void ***, _DWORD, int, int))v11->EnumerateLeavesInBox)(
    a1: v11,
    a2: &leafList[16],
    a3: v33,
    a4: &v29,
    a5: 0,
    a6: a2,
    a7: a3);
  v12 = 3.4028235e38;
  v13 = 0;
  LODWORD(mins.y) = leafID;
  v14 = v30;
  if ( *(int *)&leafList[4] > 0 )
  {
    LODWORD(mins.x) = g_pLeafAmbientIndex->m_Memory.m_pMemory;
    do
    {
      v15 = *((float *)v30 + v13);
      if ( *(_WORD *)(LODWORD(mins.x) + 4 * LODWORD(v15)) != 0 )
      {
        x = (float)word_1135AAB8[16 * LODWORD(v15)];
        v17 = (float)word_1135AABE[16 * LODWORD(v15)];
        y = (float)word_1135AABA[16 * LODWORD(v15)];
        z = (float)word_1135AABC[16 * LODWORD(v15)];
        if ( maxs.x > x )
          x = maxs.x;
        if ( v17 > size.x )
          v17 = size.x;
        if ( v17 <= x )
          v20 = v17 - x;
        else
          v20 = 0.0;
        if ( maxs.y > y )
          y = maxs.y;
        v21 = size.y;
        if ( (float)word_1135AAC0[16 * LODWORD(v15)] <= size.y )
          v21 = (float)word_1135AAC0[16 * LODWORD(v15)];
        if ( v21 <= y )
          v22 = v21 - y;
        else
          v22 = 0.0;
        v23 = v22;
        if ( maxs.z > z )
          z = maxs.z;
        v24 = size.z;
        if ( (float)word_1135AAC2[16 * LODWORD(v15)] <= size.z )
          v24 = (float)word_1135AAC2[16 * LODWORD(v15)];
        if ( v24 <= z )
          v25 = v24 - z;
        else
          v25 = 0.0;
        v26 = (float)(v23 * v23) + (float)(v25 * v25);
        v27 = 0;
        *(float *)&v27 = fsqrt(v26 + (float)(v20 * v20));
        *(_OWORD *)&leafList[12] = v27;
        if ( v12 > *(float *)&v27 )
        {
          v12 = *(float *)&leafList[12];
          mins.y = v15;
        }
      }
      ++v13;
    }
    while ( v13 < *(int *)&leafList[4] );
  }
  *(_DWORD *)&leafList[4] = 0;
  if ( *(int *)leafList >= 0 )
  {
    if ( v30 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v30);
      v14 = nullptr;
      v30 = nullptr;
    }
    v31 = 0;
  }
  *(_DWORD *)&leafList[8] = v14;
  if ( *(int *)leafList >= 0 && v14 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
  return LODWORD(mins.y);
}

//------------------------------------------------------------------------------
// Address: 0x10008E10
// Name: void ComputeAmbientForLeaf(int,int,class CUtlVector<struct ambientsample_t,class CUtlMemory<struct ambientsample_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeAmbientForLeaf(
        int iThread,
        int leafID,
        CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *list)
{
  long double v3; // rdi
  int v4; // eax
  int v5; // ecx
  CLeafSampler sampler; // [esp+Ch] [ebp-100h] BYREF
  Vector cube[6]; // [esp+A4h] [ebp-68h] BYREF
  Vector samplePosition; // [esp+ECh] [ebp-20h] BYREF
  CUtlVector<dplane_t,CUtlMemory<dplane_t,int> > leafPlanes; // [esp+F8h] [ebp-14h] BYREF

  memset(&leafPlanes, 0, sizeof(leafPlanes));
  sampler.m_iThread = iThread;
  CUniformRandomStream::CUniformRandomStream(this: &sampler.m_random);
  LODWORD(v3) = leafID;
  GetLeafBoundaryPlanes(list: &leafPlanes, leafIndex: leafID);
  list->m_Size = 0;
  v4 = (word_1135AABE[16 * leafID] - word_1135AAB8[16 * leafID]) / 32;
  if ( v4 <= 1 )
    v4 = 1;
  v5 = v4 * v4 * v4;
  if ( g_bFastAmbient )
  {
    v5 = 1;
  }
  else if ( v5 >= 1 )
  {
    if ( v5 > 128 )
      v5 = 128;
  }
  else
  {
    v5 = 1;
  }
  if ( (dleafs[leafID].contents & 1) != 0 )
  {
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&leafPlanes);
  }
  else
  {
    HIDWORD(v3) = v5;
    do
    {
      CLeafSampler::GenerateLeafSamplePosition(this: &sampler, leafIndex: leafID, &leafPlanes, &samplePosition);
      ComputeAmbientFromSphericalSamples(a1: v3, iThread, vStart: &samplePosition, lightBoxColor: cube);
      AddSampleToList(list, &samplePosition, pCube: cube);
      --HIDWORD(v3);
    }
    while ( HIDWORD(v3) != 0 );
    CompressAmbientSampleList(list);
    if ( leafPlanes.m_Memory.m_nGrowSize >= 0 && leafPlanes.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leafPlanes.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008F40
// Name: void VMPI_ProcessLeafAmbient(int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ProcessLeafAmbient(int iThread, unsigned __int64 iLeaf, MessageBuffer *pBuf)
{
  MessageBuffer *v3; // ebx
  int m_Size; // esi
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > list; // [esp+Ch] [ebp-14h] BYREF

  memset(&list, 0, sizeof(list));
  ComputeAmbientForLeaf(iThread, leafID: iLeaf, &list);
  VMPI_SetCurrentStage(pCurStage: "EncodeLeafAmbientResults");
  v3 = pBuf;
  m_Size = list.m_Size;
  HIDWORD(iLeaf) = list.m_Size;
  MessageBuffer::write(this: pBuf, p: (char *)&iLeaf + 4, bytes: 4);
  if ( HIDWORD(iLeaf) != 0 )
    MessageBuffer::write(this: v3, p: list.m_Memory.m_pMemory, bytes: 84 * m_Size);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&list);
}

//------------------------------------------------------------------------------
// Address: 0x10009060
// Name: ThreadComputeLeafAmbient
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadComputeLeafAmbient(int iThread)
{
  ambientsample_t *v1; // esi
  int ThreadWork; // ebx
  int v3; // ebx
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *v4; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ambientsample_t *m_pMemory; // ecx
  int v8; // eax
  float *p_z; // ecx
  unsigned int v10; // edx
  char *v11; // eax
  float *v12; // eax
  double v13; // st7
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > list; // [esp+Ch] [ebp-14h] BYREF

  v1 = nullptr;
  memset(&list, 0, sizeof(list));
  ThreadWork = GetThreadWork();
  if ( ThreadWork != -1 )
  {
    while ( 1 )
    {
      list.m_Size = 0;
      ComputeAmbientForLeaf(iThread, leafID: ThreadWork, &list);
      v3 = ThreadWork;
      v4 = &g_LeafAmbientSamples.m_Memory.m_pMemory[v3];
      g_LeafAmbientSamples.m_Memory.m_pMemory[v3].m_Size = 0;
      m_Size = list.m_Size;
      if ( list.m_Size != 0 )
      {
        m_nAllocationCount = v4->m_Memory.m_nAllocationCount;
        if ( list.m_Size > m_nAllocationCount )
          CUtlMemory<ambientsample_t,int>::Grow(this: &v4->m_Memory, num: list.m_Size - m_nAllocationCount);
        v4->m_Size += m_Size;
        m_pMemory = v4->m_Memory.m_pMemory;
        v8 = v4->m_Size - m_Size;
        v4->m_pElements = v4->m_Memory.m_pMemory;
        if ( v8 <= 0 )
          goto LABEL_8;
        if ( m_Size > 0 )
          break;
      }
LABEL_11:
      ThreadWork = GetThreadWork();
      if ( ThreadWork == -1 )
      {
        v1 = list.m_Memory.m_pMemory;
        goto LABEL_13;
      }
    }
    _V_memmove(dest: &m_pMemory[m_Size], src: m_pMemory, count: 84 * v8);
LABEL_8:
    if ( m_Size > 0 )
    {
      p_z = &list.m_Memory.m_pMemory->cube[0].z;
      v10 = -20 - (unsigned int)list.m_Memory.m_pMemory;
      do
      {
        v11 = (char *)p_z + (unsigned int)g_LeafAmbientSamples.m_Memory.m_pMemory[v3].m_Memory.m_pMemory;
        *(float *)&v11[v10] = *(p_z - 5);
        v12 = (float *)&v11[v10];
        v13 = *(p_z - 4);
        p_z += 21;
        --m_Size;
        v12[1] = v13;
        v12[2] = *(p_z - 24);
        v12[3] = *(p_z - 23);
        v12[4] = *(p_z - 22);
        v12[5] = *(p_z - 21);
        v12[6] = *(p_z - 20);
        v12[7] = *(p_z - 19);
        v12[8] = *(p_z - 18);
        v12[9] = *(p_z - 17);
        v12[10] = *(p_z - 16);
        v12[11] = *(p_z - 15);
        v12[12] = *(p_z - 14);
        v12[13] = *(p_z - 13);
        v12[14] = *(p_z - 12);
        v12[15] = *(p_z - 11);
        v12[16] = *(p_z - 10);
        v12[17] = *(p_z - 9);
        v12[18] = *(p_z - 8);
        v12[19] = *(p_z - 7);
        v12[20] = *(p_z - 6);
      }
      while ( m_Size != 0 );
    }
    goto LABEL_11;
  }
LABEL_13:
  if ( list.m_Memory.m_nGrowSize >= 0 && v1 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100091F0
// Name: void VMPI_ReceiveLeafAmbientResults(unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveLeafAmbientResults(unsigned __int64 leafID, MessageBuffer *pBuf)
{
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *v2; // ecx
  int v3; // [esp-4h] [ebp-10h]
  int nSamples; // [esp+8h] [ebp-4h] BYREF

  MessageBuffer::read(this: pBuf, p: &nSamples, bytes: 4);
  v3 = nSamples;
  v2 = &g_LeafAmbientSamples.m_Memory.m_pMemory[leafID];
  v2->m_Size = 0;
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int>>::InsertMultipleBefore(this: v2, elem: 0, num: v3);
  if ( nSamples != 0 )
    MessageBuffer::read(
      this: pBuf,
      p: g_LeafAmbientSamples.m_Memory.m_pMemory[leafID].m_Memory.m_pMemory,
      bytes: 84 * nSamples);
}

//------------------------------------------------------------------------------
// Address: 0x100092B0
// Name: void ComputePerLeafAmbientLighting(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputePerLeafAmbientLighting()
{
  int v0; // ebx
  int v1; // edi
  int v2; // esi
  float v3; // xmm2_4
  int v4; // ecx
  dworldlight_t *v5; // eax
  emittype_t type; // edx
  float x; // xmm0_4
  int *p_flags; // eax
  int v9; // eax
  int v10; // esi
  int v11; // esi
  CUtlVector<dleafambientindex_t,CUtlMemory<dleafambientindex_t,int> > *v12; // ebx
  CUtlMemory<S3RGBA,int> *v13; // edi
  int m_nAllocationCount; // edx
  S3RGBA *m_pMemory; // edx
  int v16; // eax
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int> > *v17; // esi
  int v18; // ecx
  dleafambientlighting_t *v19; // edx
  dleafambientlighting_t *v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // ebx
  __int16 *v24; // edx
  char *v25; // ebx
  int m_Size; // esi
  int *p_m_Size; // edi
  int v28; // eax
  dleafambientlighting_t *v29; // ecx
  int v30; // eax
  dleafambientlighting_t *v31; // edi
  float v32; // xmm2_4
  int v33; // ecx
  int v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm2_4
  int v37; // ecx
  int v38; // ecx
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  int v42; // ecx
  float v43; // xmm0_4
  int v44; // esi
  int v45; // esi
  dleaf_t *v46; // edi
  unsigned __int16 v47; // ax
  int v48; // [esp+Ch] [ebp-18h]
  int leafID; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int> > *v51; // [esp+18h] [ebp-Ch]
  int j; // [esp+18h] [ebp-Ch]
  int v53; // [esp+1Ch] [ebp-8h]
  __int16 *v54; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v0 = 0;
  v1 = 0;
  v2 = 0;
  if ( *pNumworldlights <= 0 )
    goto LABEL_21;
  v3 = *(float *)&dword_101451E0;
  v4 = 0;
  do
  {
    v5 = dworldlights;
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      v3 = 0.0000038146973;
    }
    type = dworldlights[v4].type;
    if ( type != emit_surface || dworldlights[v4].style != 0 )
      goto LABEL_13;
    x = dworldlights[v4].intensity.x;
    if ( x <= dworldlights[v4].intensity.y )
      x = dworldlights[v4].intensity.y;
    if ( x <= dworldlights[v4].intensity.z )
      x = dworldlights[v4].intensity.z;
    if ( (float)(v3 * x) >= 0.0049999999 )
    {
LABEL_13:
      dworldlights[v4].flags &= ~1u;
      p_flags = &v5[v4].flags;
    }
    else
    {
      dworldlights[v4].flags |= 1u;
      p_flags = &v5[v4].flags;
    }
    if ( type == emit_surface )
      ++v1;
    if ( (*(_BYTE *)p_flags & 1) != 0 )
      ++v0;
    ++v2;
    ++v4;
  }
  while ( v2 < *pNumworldlights );
  dword_101451E0 = LODWORD(v3);
  if ( v1 != 0 )
    v9 = 100 * v0 / v1;
  else
LABEL_21:
    v9 = 0;
  _Msg(a1: "%d of %d (%d%% of) surface lights went in leaf ambient cubes.\n", v0, v1, v9);
  v10 = numleafs;
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *)&g_LeafAmbientSamples);
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *)&g_LeafAmbientSamples,
    elem: g_LeafAmbientSamples.m_Size,
    num: v10);
  if ( g_bUseMPI )
  {
    VMPI_SetCurrentStage(pCurStage: "ComputeLeafAmbientLighting");
    DistributeWork(
      nWorkUnits: (int)numleafs,
      processFn: VMPI_ProcessLeafAmbient,
      receiveFn: (void (__cdecl *)(unsigned __int64, MessageBuffer *, int))VMPI_ReceiveLeafAmbientResults);
  }
  else
  {
    printf(format: "%-20s ", "ThreadComputeLeafAmbient:");
    RunThreadsOn(
      workcnt: numleafs,
      showpacifier: 1,
      fn: (void (__cdecl *)(int, void *))ThreadComputeLeafAmbient,
      pUserData: nullptr);
  }
  _Msg(a1: "Writing leaf ambient...");
  g_pLeafAmbientIndex->m_Size = 0;
  g_pLeafAmbientLighting->m_Size = 0;
  v11 = numleafs;
  v12 = g_pLeafAmbientIndex;
  v13 = (CUtlMemory<S3RGBA,int> *)g_pLeafAmbientIndex;
  g_pLeafAmbientIndex->m_Size = 0;
  if ( v11 != 0 )
  {
    m_nAllocationCount = v13->m_nAllocationCount;
    if ( v11 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(this: v13, num: v11 - m_nAllocationCount);
    v12->m_Size += v11;
    m_pMemory = v13->m_pMemory;
    v16 = v12->m_Size - v11;
    v13[1].m_nAllocationCount = (int)v13->m_pMemory;
    if ( v16 > 0 && v11 > 0 )
      _V_memmove(dest: &m_pMemory[v11], src: m_pMemory, count: 4 * v16);
  }
  v17 = g_pLeafAmbientLighting;
  v18 = 4 * numleafs;
  if ( g_pLeafAmbientLighting->m_Memory.m_nAllocationCount < 4 * (int)numleafs
    && g_pLeafAmbientLighting->m_Memory.m_nGrowSize >= 0 )
  {
    v19 = g_pLeafAmbientLighting->m_Memory.m_pMemory;
    g_pLeafAmbientLighting->m_Memory.m_nAllocationCount = v18;
    if ( v19 != nullptr )
      v20 = (dleafambientlighting_t *)_g_pMemAlloc->Realloc_2(
                                        this: _g_pMemAlloc,
                                        a2: v19,
                                        a3: 28 * v17->m_Memory.m_nAllocationCount);
    else
      v20 = (dleafambientlighting_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * v18);
    v17->m_Memory.m_pMemory = v20;
  }
  v17->m_pElements = v17->m_Memory.m_pMemory;
  v21 = numleafs;
  v22 = 0;
  leafID = 0;
  if ( (int)numleafs > 0 )
  {
    v23 = 0;
    v24 = word_1135AABE;
    v48 = 0;
    v54 = word_1135AABE;
    do
    {
      v25 = (char *)g_LeafAmbientSamples.m_Memory.m_pMemory + v23;
      g_pLeafAmbientIndex->m_Memory.m_pMemory[v22].ambientSampleCount = *((_WORD *)v25 + 6);
      if ( *((_DWORD *)v25 + 3) != 0 )
      {
        g_pLeafAmbientIndex->m_Memory.m_pMemory[v22].firstAmbientSample = g_pLeafAmbientLighting->m_Size;
        i = 0;
        if ( *((int *)v25 + 3) > 0 )
        {
          v53 = 0;
          do
          {
            m_Size = g_pLeafAmbientLighting->m_Size;
            p_m_Size = &g_pLeafAmbientLighting->m_Size;
            v51 = g_pLeafAmbientLighting;
            v28 = g_pLeafAmbientLighting->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > v28 )
            {
              CUtlMemory<CVradStaticPropMgr::MeshData_t,int>::Grow(
                this: &g_pLeafAmbientLighting->m_Memory,
                num: m_Size - v28 + 1);
              v24 = v54;
            }
            ++*p_m_Size;
            v29 = v51->m_Memory.m_pMemory;
            v30 = *p_m_Size - m_Size - 1;
            v51->m_pElements = v51->m_Memory.m_pMemory;
            if ( v30 > 0 )
            {
              _V_memmove(dest: &v29[m_Size + 1], src: &v29[m_Size], count: 28 * v30);
              v24 = v54;
            }
            v31 = &g_pLeafAmbientLighting->m_Memory.m_pMemory[m_Size];
            v32 = (float)*(v24 - 3);
            v33 = *v24;
            if ( v32 < (float)v33 )
            {
              v35 = (float)(*(float *)(v53 + *(_DWORD *)v25) - v32) / (float)((float)v33 - v32);
              if ( v35 >= 0.0 )
              {
                if ( v35 > 1.0 )
                  v35 = 1.0;
              }
              else
              {
                v35 = 0.0;
              }
              v34 = (int)(float)((float)(v35 * 255.0) + 0.5);
            }
            else
            {
              LOBYTE(v34) = 0;
            }
            v31->x = v34;
            v36 = (float)*(v24 - 2);
            v37 = v24[1];
            if ( v36 < (float)v37 )
            {
              v39 = (float)(*(float *)(*(_DWORD *)v25 + v53 + 4) - v36) / (float)((float)v37 - v36);
              if ( v39 >= 0.0 )
              {
                if ( v39 > 1.0 )
                  v39 = 1.0;
              }
              else
              {
                v39 = 0.0;
              }
              v38 = (int)(float)((float)(v39 * 255.0) + 0.5);
            }
            else
            {
              LOBYTE(v38) = 0;
            }
            v31->y = v38;
            v40 = (float)*(v24 - 1);
            v41 = (float)v24[2];
            if ( v40 < v41 )
            {
              v43 = (float)(*(float *)(*(_DWORD *)v25 + v53 + 8) - v40) / (float)(v41 - v40);
              if ( v43 >= 0.0 )
              {
                if ( v43 > 1.0 )
                  v43 = 1.0;
              }
              else
              {
                v43 = 0.0;
              }
              v42 = (int)(float)((float)(v43 * 255.0) + 0.5);
            }
            else
            {
              LOBYTE(v42) = 0;
            }
            v31->z = v42;
            v31->pad = 0;
            v44 = v53;
            for ( j = 6; j != 0; --j )
            {
              VectorToColorRGBExp32(vin: (const Vector *)(*(_DWORD *)v25 + v44 + 12), c: v31->cube.m_Color);
              v44 += 12;
              v31 = (dleafambientlighting_t *)((char *)v31 + 4);
            }
            v53 += 84;
            v24 = v54;
            ++i;
          }
          while ( i < *((_DWORD *)v25 + 3) );
          v22 = leafID;
        }
      }
      else
      {
        g_pLeafAmbientIndex->m_Memory.m_pMemory[v22].firstAmbientSample = 0;
      }
      v21 = numleafs;
      ++v22;
      v23 = v48 + 20;
      v24 += 16;
      leafID = v22;
      v48 += 20;
      v54 = v24;
    }
    while ( v22 < (int)numleafs );
  }
  v45 = 0;
  if ( v21 > 0 )
  {
    v46 = dleafs;
    do
    {
      if ( g_pLeafAmbientIndex->m_Memory.m_pMemory[v45].ambientSampleCount == 0 )
      {
        if ( (v46->contents & 1) == 0 )
          _Msg(a1: "Bad leaf ambient for leaf %d\n", v45);
        v47 = NearestNeighborWithLight(a1: COERCE_FLOAT(&savedregs), a2: (int)v46, a3: v45, leafID: v45);
        g_pLeafAmbientIndex->m_Memory.m_pMemory[v45].ambientSampleCount = 0;
        g_pLeafAmbientIndex->m_Memory.m_pMemory[v45].firstAmbientSample = v47;
        v21 = numleafs;
      }
      ++v45;
      ++v46;
    }
    while ( v45 < v21 );
  }
  _Msg(a1: "done\n");
}
