// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/worldlighting.cpp
// Functions: 11
// ============================================================

#include "utils\vmap\bvh\worldlighting.h"

//------------------------------------------------------------------------------
// Address: 0x0040DFF0
// Name: float VectorLength(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VectorLength(const Vector *v)
{
  return fsqrt((float)((float)(v->x * v->x) + (float)(v->y * v->y)) + (float)(v->z * v->z));
}

//------------------------------------------------------------------------------
// Address: 0x0040E050
// Name: public: float Vector::Length(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::Length(Vector *this)
{
  return fsqrt((float)((float)(this->x * this->x) + (float)(this->y * this->y)) + (float)(this->z * this->z));
}

//------------------------------------------------------------------------------
// Address: 0x0040E0B0
// Name: public: class Vector Vector::operator*(float)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator*(Vector *this, Vector *result, float fl)
{
  result->x = this->x * fl;
  result->y = this->y * fl;
  result->z = this->z * fl;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E0F0
// Name: public: void Vector4D::Init(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector4D::Init(Vector4D *this, float ix, float iy, float iz, float iw)
{
  this->x = ix;
  this->y = iy;
  this->z = iz;
  this->w = iw;
}

//------------------------------------------------------------------------------
// Address: 0x0040E120
// Name: public: bool CUniformSampler::InitSamples(int,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CUniformSampler::InitSamples@<al>(
        CUniformSampler *this@<ecx>,
        float a2@<edi>,
        int SqrtNumSamples,
        int NumVariations)
{
  Vector *v5; // eax
  CUniformSampler *v6; // ecx
  int v7; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // edi
  float v13; // xmm0_4
  float v14; // xmm0_4
  Vector *m_pvDirections; // eax
  float v16; // [esp-4h] [ebp-40h]
  float v17; // [esp-4h] [ebp-40h]
  float v18; // [esp-4h] [ebp-40h]
  float v19; // [esp-4h] [ebp-40h]
  float v20; // [esp-4h] [ebp-40h]
  int i; // [esp+14h] [ebp-28h]
  int v22; // [esp+1Ch] [ebp-20h]
  int v23; // [esp+24h] [ebp-18h]
  int n; // [esp+28h] [ebp-14h]
  float theta; // [esp+2Ch] [ebp-10h]
  int a; // [esp+44h] [ebp+8h]
  float oneoverN; // [esp+48h] [ebp+Ch]

  this->m_NumSamples = SqrtNumSamples * SqrtNumSamples;
  v23 = SqrtNumSamples * SqrtNumSamples;
  this->m_NumVariations = NumVariations;
  v5 = (Vector *)MemAlloc_Alloc(
                   nSize: (12 * (unsigned __int64)(unsigned int)(NumVariations * SqrtNumSamples * SqrtNumSamples)) >> 32 != 0
                 ? -1
                 : 12 * NumVariations * SqrtNumSamples * SqrtNumSamples);
  v6 = this;
  v7 = 0;
  this->m_pvDirections = v5;
  if ( v5 == nullptr )
    return 0;
  oneoverN = 1.0 / (float)SqrtNumSamples;
  n = 0;
  if ( this->m_NumVariations > 0 )
  {
    v16 = a2;
    do
    {
      a = 0;
      if ( SqrtNumSamples > 0 )
      {
        v9 = 12 * SqrtNumSamples;
        v10 = 12 * v7;
        i = v23 + v7;
        while ( 1 )
        {
          v11 = 0;
          v12 = v10;
          v22 = v9 + v10;
          do
          {
            v13 = fsqrt(
                    1.0
                  - (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(rand() - 0x3FFF) * 0.000061038882) & _mask__AbsFloat_)
                                  + (float)a)
                          * oneoverN));
            __libm_sse2_acosf(x: v16);
            theta = v13 * 2.0;
            v14 = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(rand() - 0x3FFF) * 0.000061038882) & _mask__AbsFloat_)
                                + (float)v11)
                        * oneoverN)
                * 6.283185307179586;
            __libm_sse2_sinf(x: v17);
            __libm_sse2_cosf(x: v18);
            __libm_sse2_sinf(x: v19);
            __libm_sse2_cosf(x: v20);
            m_pvDirections = this->m_pvDirections;
            *(float *)((char *)&m_pvDirections->x + v12) = v14 * theta;
            *(float *)((char *)&m_pvDirections->y + v12) = v14 * theta;
            *(float *)((char *)&m_pvDirections->z + v12) = theta;
            ++v11;
            v12 += 12;
          }
          while ( v11 < SqrtNumSamples );
          if ( ++a >= SqrtNumSamples )
            break;
          v9 = 12 * SqrtNumSamples;
          v10 = v22;
        }
        v7 = i;
        v6 = this;
      }
      ++n;
    }
    while ( n < v6->m_NumVariations );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040E320
// Name: float FindFarthestIntersection(class Vector __near &,class CUniformSampler __near &,class RayTracingEnvironment __near &,float,class Vector __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
double __usercall FindFarthestIntersection@<st0>(
        float a1@<ebp>,
        Vector *vPoint,
        CUniformSampler *sampler,
        RayTracingEnvironment *kdTree,
        float flTraceLength,
        Vector *vDirection,
        float flCosAngle,
        bool bUseAngle)
{
  signed int m_NumSamples; // esi
  void *v9; // edi
  float z; // eax
  float v11; // xmm3_4
  int v12; // edi
  __int64 v13; // xmm0_8
  float v14; // xmm4_4
  float x; // xmm2_4
  float v16; // xmm5_4
  float v17; // esi
  int v18; // edi
  float v19; // ecx
  int v20; // edi
  float *v21; // edx
  int v22; // eax
  unsigned int v23; // ecx
  float *v24; // eax
  float v25; // edi
  float v26; // xmm0_4
  int v27; // edx
  unsigned int v28; // eax
  float *v29; // ecx
  float v30; // xmm1_4
  float v31; // xmm1_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  _BYTE v35[12]; // [esp-Ch] [ebp-3ECh] BYREF
  RayStream rayStream; // [esp+0h] [ebp-3E0h] BYREF
  float v37; // [esp+3A0h] [ebp-40h]
  float v38; // [esp+3A4h] [ebp-3Ch]
  Vector vEnd; // [esp+3A8h] [ebp-38h]
  Vector vSampleDirection; // [esp+3B4h] [ebp-2Ch] BYREF
  Vector vShiftedOrigin; // [esp+3C0h] [ebp-20h]
  float *pMinDists; // [esp+3CCh] [ebp-14h]
  float y; // [esp+3D0h] [ebp-10h]
  float flFarthest; // [esp+3D4h] [ebp-Ch]
  void *v45; // [esp+3D8h] [ebp-8h]
  void *retaddr; // [esp+3E0h] [ebp+0h]

  flFarthest = a1;
  v45 = retaddr;
  m_NumSamples = sampler->m_NumSamples;
  vShiftedOrigin.z = -1.0;
  y = *(float *)&m_NumSamples;
  LODWORD(vShiftedOrigin.y) = MemAlloc_Alloc(nSize: (24 * (unsigned __int64)(unsigned int)m_NumSamples) >> 32 != 0 ? -1 : 24 * m_NumSamples);
  v9 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)m_NumSamples >> 30 != 0 ? -1 : 4 * m_NumSamples);
  LODWORD(vShiftedOrigin.x) = v9;
  if ( m_NumSamples > 0 )
    memset32(v9, 2139095039, m_NumSamples);
  z = vPoint->z;
  *(_QWORD *)&vSampleDirection.x = *(_QWORD *)&vPoint->x;
  vSampleDirection.z = z;
  memset(&rayStream.PendingStreamOutputs[7][1], 0, 32);
  if ( bUseAngle )
  {
    if ( m_NumSamples > 0 )
    {
      v11 = flTraceLength;
      v12 = 0;
      y = vShiftedOrigin.y;
      for ( pMinDists = (float *)m_NumSamples; pMinDists != nullptr; pMinDists = (float *)((char *)pMinDists - 1) )
      {
        v13 = *(_QWORD *)&sampler->m_pvDirections[v12].x;
        vEnd.z = sampler->m_pvDirections[v12].z;
        v14 = vDirection->y;
        x = vDirection->x;
        v16 = vDirection->z;
        *(_QWORD *)&vEnd.x = v13;
        if ( (float)((float)((float)(v14 * *((float *)&v13 + 1)) + (float)(x * *(float *)&v13)) + (float)(v16 * vEnd.z)) > flCosAngle )
        {
          rayStream.PendingRays[7].direction.z.m128_f32[3] = vSampleDirection.x + (float)(vEnd.x * v11);
          v37 = vSampleDirection.y + (float)(*((float *)&v13 + 1) * v11);
          v38 = vSampleDirection.z + (float)(vEnd.z * v11);
          RayTracingEnvironment::AddToRayStream(
            this: kdTree,
            s: (RayStream *)v35,
            start: &vSampleDirection,
            end: (const Vector *)&rayStream.PendingRays[7].direction.z.m128_u32[3],
            rslt_out: (RayTracingSingleResult *)LODWORD(y),
            cullMode: RTE_CULL_NONE);
          v11 = flTraceLength;
        }
        LODWORD(y) += 24;
        ++v12;
      }
    }
  }
  else if ( m_NumSamples > 0 )
  {
    v17 = vShiftedOrigin.y;
    v18 = 0;
    pMinDists = (float *)LODWORD(y);
    do
    {
      v19 = sampler->m_pvDirections[v18].z;
      *(_QWORD *)&vEnd.x = *(_QWORD *)&sampler->m_pvDirections[v18].x;
      vEnd.z = v19;
      rayStream.PendingRays[7].direction.z.m128_f32[3] = (float)(vEnd.x * flTraceLength) + vSampleDirection.x;
      v37 = (float)(vEnd.y * flTraceLength) + vSampleDirection.y;
      v38 = (float)(v19 * flTraceLength) + vSampleDirection.z;
      RayTracingEnvironment::AddToRayStream(
        this: kdTree,
        s: (RayStream *)v35,
        start: &vSampleDirection,
        end: (const Vector *)&rayStream.PendingRays[7].direction.z.m128_u32[3],
        rslt_out: (RayTracingSingleResult *)LODWORD(v17),
        cullMode: RTE_CULL_NONE);
      ++v18;
      LODWORD(v17) += 24;
      pMinDists = (float *)((char *)pMinDists - 1);
    }
    while ( pMinDists != nullptr );
    m_NumSamples = LODWORD(y);
  }
  RayTracingEnvironment::FinishRayStream(this: kdTree, s: (RayStream *)v35, cullMode: RTE_CULL_NONE);
  v20 = 0;
  if ( m_NumSamples >= 4 )
  {
    v21 = (float *)(LODWORD(vShiftedOrigin.x) + 8);
    v22 = LODWORD(vShiftedOrigin.y) + 16;
    v23 = ((unsigned int)(m_NumSamples - 4) >> 2) + 1;
    v20 = 4 * v23;
    do
    {
      if ( *(int *)(v22 - 4) > -1 )
        *(v21 - 2) = *(float *)v22;
      if ( *(int *)(v22 + 20) > -1 )
        *(v21 - 1) = *(float *)(v22 + 24);
      if ( *(int *)(v22 + 44) > -1 )
        *v21 = *(float *)(v22 + 48);
      if ( *(int *)(v22 + 68) > -1 )
        v21[1] = *(float *)(v22 + 72);
      v21 += 4;
      v22 += 96;
      --v23;
    }
    while ( v23 != 0 );
  }
  if ( v20 < m_NumSamples )
  {
    v24 = (float *)(LODWORD(vShiftedOrigin.y) + 24 * v20 + 16);
    do
    {
      if ( *((int *)v24 - 1) > -1 )
        *(float *)(LODWORD(vShiftedOrigin.x) + 4 * v20) = *v24;
      ++v20;
      v24 += 6;
    }
    while ( v20 < m_NumSamples );
  }
  v25 = vShiftedOrigin.x;
  v26 = vShiftedOrigin.z;
  v27 = 0;
  if ( m_NumSamples >= 4 )
  {
    v28 = ((unsigned int)(m_NumSamples - 4) >> 2) + 1;
    v29 = (float *)(LODWORD(vShiftedOrigin.x) + 8);
    v27 = 4 * v28;
    do
    {
      v30 = *(v29 - 2);
      if ( v30 < 3.4028235e38 && v26 <= v30 )
        v26 = *(v29 - 2);
      v31 = *(v29 - 1);
      if ( v31 < 3.4028235e38 && v26 <= v31 )
        v26 = *(v29 - 1);
      if ( *v29 < 3.4028235e38 && v26 <= *v29 )
        v26 = *v29;
      v32 = v29[1];
      if ( v32 < 3.4028235e38 && v26 <= v32 )
        v26 = v29[1];
      v29 += 4;
      --v28;
    }
    while ( v28 != 0 );
    vShiftedOrigin.z = v26;
  }
  if ( v27 < m_NumSamples )
  {
    do
    {
      v33 = *(float *)(LODWORD(vShiftedOrigin.x) + 4 * v27);
      if ( v33 < 3.4028235e38 && v26 <= v33 )
        v26 = *(float *)(LODWORD(vShiftedOrigin.x) + 4 * v27);
      ++v27;
    }
    while ( v27 < m_NumSamples );
    vShiftedOrigin.z = v26;
  }
  free(pMem: (void *)LODWORD(vShiftedOrigin.y));
  free(pMem: (void *)LODWORD(v25));
  return vShiftedOrigin.z;
}

//------------------------------------------------------------------------------
// Address: 0x0040E7D0
// Name: public: struct AABB_t CWorldLighting::FindLightBounds(void)
// Source: json
//------------------------------------------------------------------------------
AABB_t *__thiscall CWorldLighting::FindLightBounds(CWorldLighting *this, AABB_t *result)
{
  AABB_t *v2; // eax
  int m_Size; // ebx
  int v4; // esi
  int v5; // edi
  float w; // xmm0_4
  double x; // xmm1_8
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  double y; // xmm1_8
  float z; // xmm2_4
  float v13; // xmm1_4
  double v14; // xmm1_8
  double v15; // xmm2_8
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  double v19; // xmm0_8
  float v20; // xmm0_4
  double v21; // xmm0_8
  float v22; // xmm0_4
  double v23; // xmm0_8
  int v24; // esi
  int i; // edi
  CSpotLight *m_pMemory; // edx
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  double v31; // xmm4_8
  float v32; // xmm6_4
  float v33; // xmm4_4
  double v34; // xmm4_8
  float v35; // xmm5_4
  float v36; // xmm4_4
  double v37; // xmm4_8
  double v38; // xmm5_8
  float v39; // xmm2_4
  float v40; // xmm3_4
  double v41; // xmm0_8
  float v42; // xmm0_4
  double v43; // xmm0_8
  float v44; // xmm0_4
  double v45; // xmm0_8
  int v46; // edi
  int v47; // esi
  CPointLight *v48; // edx
  float v49; // xmm0_4
  double v50; // xmm1_8
  float v51; // xmm2_4
  float v52; // xmm3_4
  float v53; // xmm1_4
  double v54; // xmm1_8
  float v55; // xmm2_4
  float v56; // xmm1_4
  double v57; // xmm1_8
  double v58; // xmm2_8
  float v59; // xmm1_4
  CPointLight *v60; // edx
  float v61; // xmm2_4
  float v62; // xmm3_4
  double v63; // xmm0_8
  float v64; // xmm0_4
  double v65; // xmm0_8
  float v66; // xmm0_4
  double v67; // xmm0_8
  int nVPLs; // [esp+8h] [ebp+8h]

  v2 = result;
  result->m_vMinBounds.x = 3.4028235e38;
  result->m_vMinBounds.y = 3.4028235e38;
  result->m_vMinBounds.z = 3.4028235e38;
  result->m_vMaxBounds.x = -3.4028235e38;
  result->m_vMaxBounds.y = -3.4028235e38;
  result->m_vMaxBounds.z = -3.4028235e38;
  m_Size = this->m_spotLights.m_Size;
  nVPLs = this->m_virtualPointLights.m_Size;
  if ( this->m_pointLights.m_Size > 0 )
  {
    v4 = 0;
    v5 = this->m_pointLights.m_Size;
    do
    {
      w = this->m_pointLights.m_Memory.m_pMemory[v4].m_instData.m_vColorNRadius.w;
      x = (float)(this->m_pointLights.m_Memory.m_pMemory[v4].m_instData.m_vOrigin.x - w);
      v8 = this->m_pointLights.m_Memory.m_pMemory[v4].m_instData.m_vOrigin.y - w;
      v9 = this->m_pointLights.m_Memory.m_pMemory[v4].m_instData.m_vOrigin.z - w;
      if ( x > v2->m_vMinBounds.x )
        x = v2->m_vMinBounds.x;
      v10 = x;
      v2->m_vMinBounds.x = v10;
      y = v8;
      if ( v8 > (double)v2->m_vMinBounds.y )
        y = v2->m_vMinBounds.y;
      z = v2->m_vMinBounds.z;
      v13 = y;
      v2->m_vMinBounds.y = v13;
      v14 = v9;
      v15 = z;
      if ( v9 > v15 )
        v14 = v15;
      v16 = v14;
      v2->m_vMinBounds.z = v16;
      v17 = this->m_pointLights.m_Memory.m_pMemory[v4].m_instData.m_vOrigin.y + w;
      v18 = this->m_pointLights.m_Memory.m_pMemory[v4].m_instData.m_vOrigin.z + w;
      v19 = (float)(this->m_pointLights.m_Memory.m_pMemory[v4].m_instData.m_vOrigin.x + w);
      if ( v19 < v2->m_vMaxBounds.x )
        v19 = v2->m_vMaxBounds.x;
      v20 = v19;
      v2->m_vMaxBounds.x = v20;
      v21 = v17;
      if ( v17 < (double)v2->m_vMaxBounds.y )
        v21 = v2->m_vMaxBounds.y;
      v22 = v21;
      v2->m_vMaxBounds.y = v22;
      v23 = v18;
      if ( v18 < (double)v2->m_vMaxBounds.z )
        v23 = v2->m_vMaxBounds.z;
      ++v4;
      --v5;
      v2->m_vMaxBounds.z = v23;
    }
    while ( v5 != 0 );
  }
  if ( m_Size > 0 )
  {
    v24 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      m_pMemory = this->m_spotLights.m_Memory.m_pMemory;
      v27 = m_pMemory[v24].m_instData.m_vColorNRadius.w;
      v28 = m_pMemory[v24].m_instData.m_vTransform0.w;
      v29 = m_pMemory[v24].m_instData.m_vTransform1.w;
      v30 = m_pMemory[v24].m_instData.m_vTransform2.w;
      v31 = (float)(v28 - v27);
      v32 = v30 - v27;
      if ( v31 > v2->m_vMinBounds.x )
        v31 = v2->m_vMinBounds.x;
      v33 = v31;
      v2->m_vMinBounds.x = v33;
      v34 = (float)(v29 - v27);
      if ( v34 > v2->m_vMinBounds.y )
        v34 = v2->m_vMinBounds.y;
      v35 = v2->m_vMinBounds.z;
      v36 = v34;
      v2->m_vMinBounds.y = v36;
      v37 = v32;
      v38 = v35;
      if ( v32 > v38 )
        v37 = v38;
      v39 = v29 + v27;
      v40 = v30 + v27;
      v41 = (float)(v28 + v27);
      v2->m_vMinBounds.z = v37;
      if ( v41 < v2->m_vMaxBounds.x )
        v41 = v2->m_vMaxBounds.x;
      v42 = v41;
      v2->m_vMaxBounds.x = v42;
      v43 = v39;
      if ( v39 < (double)v2->m_vMaxBounds.y )
        v43 = v2->m_vMaxBounds.y;
      v44 = v43;
      v2->m_vMaxBounds.y = v44;
      v45 = v40;
      if ( v40 < (double)v2->m_vMaxBounds.z )
        v45 = v2->m_vMaxBounds.z;
      ++v24;
      v2->m_vMaxBounds.z = v45;
    }
  }
  v46 = nVPLs;
  if ( nVPLs > 0 )
  {
    v47 = 0;
    do
    {
      v48 = this->m_virtualPointLights.m_Memory.m_pMemory;
      v49 = v48[v47].m_instData.m_vColorNRadius.w;
      v50 = (float)(v48[v47].m_instData.m_vOrigin.x - v49);
      v51 = v48[v47].m_instData.m_vOrigin.y - v49;
      v52 = v48[v47].m_instData.m_vOrigin.z - v49;
      if ( v50 > v2->m_vMinBounds.x )
        v50 = v2->m_vMinBounds.x;
      v53 = v50;
      v2->m_vMinBounds.x = v53;
      v54 = v51;
      if ( v51 > (double)v2->m_vMinBounds.y )
        v54 = v2->m_vMinBounds.y;
      v55 = v2->m_vMinBounds.z;
      v56 = v54;
      v2->m_vMinBounds.y = v56;
      v57 = v52;
      v58 = v55;
      if ( v52 > v58 )
        v57 = v58;
      v59 = v57;
      v2->m_vMinBounds.z = v59;
      v60 = this->m_virtualPointLights.m_Memory.m_pMemory;
      v61 = v60[v47].m_instData.m_vOrigin.y + v49;
      v62 = v60[v47].m_instData.m_vOrigin.z + v49;
      v63 = (float)(v60[v47].m_instData.m_vOrigin.x + v49);
      if ( v63 < v2->m_vMaxBounds.x )
        v63 = v2->m_vMaxBounds.x;
      v64 = v63;
      v2->m_vMaxBounds.x = v64;
      v65 = v61;
      if ( v61 < (double)v2->m_vMaxBounds.y )
        v65 = v2->m_vMaxBounds.y;
      v66 = v65;
      v2->m_vMaxBounds.y = v66;
      v67 = v62;
      if ( v62 < (double)v2->m_vMaxBounds.z )
        v67 = v2->m_vMaxBounds.z;
      ++v47;
      --v46;
      v2->m_vMaxBounds.z = v67;
    }
    while ( v46 != 0 );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040EB80
// Name: public: void CWorldLighting::ShootLights(class Vector __near &,class Vector __near &,class Vector __near &,class CUniformSampler __near &,int,class RayTracingEnvironment __near &,float,float,class Vector __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CWorldLighting::ShootLights(
        CWorldLighting *this@<ecx>,
        int a2@<ebp>,
        Vector *vPoint,
        Vector *vColor,
        Vector *vAttenuation,
        CUniformSampler *sampler,
        int iVariation,
        RayTracingEnvironment *kdTree,
        float flTraceLength,
        float flPushBack,
        Vector *vDirection,
        float flCosAngle,
        bool bUseAngle)
{
  float v13; // esi
  void *v14; // edi
  int z_low; // eax
  float v16; // xmm0_4
  float v17; // ecx
  float y; // xmm4_4
  float x; // xmm3_4
  float z; // xmm5_4
  float v21; // eax
  int v22; // edi
  float v23; // edx
  int v24; // edx
  float v25; // edi
  float *v26; // ecx
  int v27; // eax
  bool v28; // zf
  float *v29; // ecx
  float *v30; // eax
  float v31; // edx
  float v32; // eax
  float v33; // xmm1_4
  float v34; // xmm0_4
  __int64 v35; // xmm2_8
  int v36; // eax
  Vector *m_pvDirections; // ecx
  __int64 v38; // kr00_8
  int v39; // eax
  __int64 v40; // xmm2_8
  float v41; // xmm6_4
  float v42; // eax
  float v43; // xmm5_4
  float v44; // xmm4_4
  float v45; // xmm1_4
  float v46; // xmm5_4
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm1_4
  float v51; // xmm4_4
  float v52; // xmm7_4
  CUtlMemory<CDmeDag::TransformInfo_t,int> *v53; // edi
  CDmeDag::TransformInfo_t *m_pMemory; // esi
  int m_nAllocationCount; // eax
  float v56; // xmm5_4
  float v57; // xmm6_4
  CDmeDag::TransformInfo_t *v58; // ecx
  int v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // ecx
  unsigned int v63; // xmm0_4
  float v64; // ecx
  unsigned __int64 v65; // xmm0_8
  __int64 v66; // xmm0_8
  float v67; // ecx
  _BYTE v68[12]; // [esp-Ch] [ebp-45Ch] BYREF
  _BYTE rayStream_116[820]; // [esp+74h] [ebp-3DCh] OVERLAPPED BYREF
  unsigned __int64 v70; // [esp+3B8h] [ebp-98h]
  float v71; // [esp+3C0h] [ebp-90h]
  Vector v72; // [esp+3C4h] [ebp-8Ch]
  int v73; // [esp+3D0h] [ebp-80h]
  float v74; // [esp+3D4h] [ebp-7Ch]
  float v75; // [esp+3D8h] [ebp-78h]
  CUtlMemory<CDmeDag::TransformInfo_t,int> *v76; // [esp+3DCh] [ebp-74h]
  float v77; // [esp+3E0h] [ebp-70h]
  float flIntensity; // [esp+3E4h] [ebp-6Ch]
  float v79; // [esp+3E8h] [ebp-68h]
  __int64 v80; // [esp+3ECh] [ebp-64h]
  float v81; // [esp+3F4h] [ebp-5Ch]
  Vector vSamplerDir; // [esp+3F8h] [ebp-58h] BYREF
  int nSamples; // [esp+404h] [ebp-4Ch]
  Vector vShiftedOrigin; // [esp+408h] [ebp-48h]
  Vector vHitNormal; // [esp+414h] [ebp-3Ch] BYREF
  Vector vOrigin; // [esp+420h] [ebp-30h]
  __int64 v87; // [esp+42Ch] [ebp-24h] OVERLAPPED
  float v88; // [esp+434h] [ebp-1Ch]
  Vector vNewColor; // [esp+438h] [ebp-18h]
  int v90; // [esp+444h] [ebp-Ch]
  float flNewRadius; // [esp+448h] [ebp-8h]
  float retaddr; // [esp+450h] [ebp+0h]

  v90 = a2;
  flNewRadius = retaddr;
  v13 = *(float *)&sampler->m_NumSamples;
  v76 = (CUtlMemory<CDmeDag::TransformInfo_t,int> *)this;
  vSamplerDir.x = v13;
  LODWORD(vNewColor.x) = MemAlloc_Alloc(nSize: (24 * (unsigned __int64)LODWORD(v13)) >> 32 != 0 ? -1 : 24 * LODWORD(v13));
  v14 = MemAlloc_Alloc(nSize: (unsigned __int64)LODWORD(v13) >> 30 != 0 ? -1 : 4 * LODWORD(v13));
  LODWORD(vOrigin.y) = v14;
  LODWORD(vOrigin.x) = MemAlloc_Alloc(nSize: (12 * (unsigned __int64)LODWORD(v13)) >> 32 != 0 ? -1 : 12 * LODWORD(v13));
  v75 = 1.0 / (float)SLODWORD(v13);
  if ( SLODWORD(v13) > 0 )
    memset32(v14, 2139095039, LODWORD(v13));
  z_low = SLODWORD(vPoint->z);
  *(_QWORD *)&vSamplerDir.y = *(_QWORD *)&vPoint->x;
  nSamples = z_low;
  memset(rayStream_116, 0, 32);
  v16 = flTraceLength;
  if ( bUseAngle )
  {
    v17 = 0.0;
    vNewColor.y = 0.0;
    if ( SLODWORD(v13) > 0 )
    {
      vNewColor.z = vNewColor.x;
      do
      {
        y = vDirection->y;
        x = vDirection->x;
        z = vDirection->z;
        v21 = sampler->m_pvDirections[LODWORD(v17) + iVariation * sampler->m_NumSamples].z;
        v87 = *(_QWORD *)&sampler->m_pvDirections[LODWORD(v17) + iVariation * sampler->m_NumSamples].x;
        v88 = v21;
        if ( (float)((float)((float)(y * *((float *)&v87 + 1)) + (float)(x * *(float *)&v87)) + (float)(z * v21)) > flCosAngle )
        {
          vHitNormal.x = vSamplerDir.y + (float)(*(float *)&v87 * v16);
          vHitNormal.y = vSamplerDir.z + (float)(*((float *)&v87 + 1) * v16);
          vHitNormal.z = *(float *)&nSamples + (float)(v21 * v16);
          RayTracingEnvironment::AddToRayStream(
            this: kdTree,
            s: (RayStream *)v68,
            start: (Vector *)&vSamplerDir.y,
            end: &vHitNormal,
            rslt_out: (RayTracingSingleResult *)LODWORD(vNewColor.z),
            cullMode: RTE_CULL_NONE);
          v16 = flTraceLength;
          v17 = vNewColor.y;
        }
        LODWORD(vNewColor.z) += 24;
        ++LODWORD(v17);
        vNewColor.y = v17;
      }
      while ( SLODWORD(v17) < SLODWORD(v13) );
    }
  }
  else
  {
    v22 = 0;
    if ( SLODWORD(v13) > 0 )
    {
      vNewColor.z = vNewColor.x;
      while ( 1 )
      {
        v23 = sampler->m_pvDirections[v22 + iVariation * sampler->m_NumSamples].z;
        v87 = *(_QWORD *)&sampler->m_pvDirections[v22 + iVariation * sampler->m_NumSamples].x;
        v88 = v23;
        vHitNormal.x = (float)(*(float *)&v87 * v16) + vSamplerDir.y;
        vHitNormal.y = (float)(*((float *)&v87 + 1) * v16) + vSamplerDir.z;
        vHitNormal.z = (float)(v23 * v16) + *(float *)&nSamples;
        RayTracingEnvironment::AddToRayStream(
          this: kdTree,
          s: (RayStream *)v68,
          start: (Vector *)&vSamplerDir.y,
          end: &vHitNormal,
          rslt_out: (RayTracingSingleResult *)LODWORD(vNewColor.z),
          cullMode: RTE_CULL_NONE);
        LODWORD(vNewColor.z) += 24;
        if ( ++v22 >= SLODWORD(v13) )
          break;
        v16 = flTraceLength;
      }
    }
  }
  RayTracingEnvironment::FinishRayStream(this: kdTree, s: (RayStream *)v68, cullMode: RTE_CULL_NONE);
  v24 = 0;
  if ( SLODWORD(v13) >= 4 )
  {
    LODWORD(vNewColor.y) = ((unsigned int)(LODWORD(v13) - 4) >> 2) + 1;
    LODWORD(v25) = LODWORD(vOrigin.y) + 8;
    v26 = (float *)(LODWORD(vOrigin.x) + 20);
    v27 = LODWORD(vNewColor.x) + 32;
    v24 = 4 * LODWORD(vNewColor.y);
    while ( 1 )
    {
      if ( *(int *)(v27 - 20) > -1 )
      {
        *(float *)(LODWORD(v25) - 8) = *(float *)(v27 - 16);
        *(v26 - 5) = *(float *)(v27 - 32);
        *(v26 - 4) = *(float *)(v27 - 28);
        *(v26 - 3) = *(float *)(v27 - 24);
      }
      if ( *(int *)(v27 + 4) > -1 )
      {
        *(float *)(LODWORD(v25) - 4) = *(float *)(v27 + 8);
        *(v26 - 2) = *(float *)(v27 - 8);
        *(v26 - 1) = *(float *)(v27 - 4);
        *v26 = *(float *)v27;
      }
      if ( *(int *)(v27 + 28) > -1 )
      {
        *(float *)LODWORD(v25) = *(float *)(v27 + 32);
        v26[1] = *(float *)(v27 + 16);
        v26[2] = *(float *)(v27 + 20);
        v26[3] = *(float *)(v27 + 24);
      }
      if ( *(int *)(v27 + 52) > -1 )
      {
        *(float *)(LODWORD(v25) + 4) = *(float *)(v27 + 56);
        v26[4] = *(float *)(v27 + 40);
        v26[5] = *(float *)(v27 + 44);
        v26[6] = *(float *)(v27 + 48);
      }
      v26 += 12;
      v27 += 96;
      v28 = LODWORD(vNewColor.y)-- == 1;
      LODWORD(vOrigin.z) = LODWORD(v25) + 16;
      if ( v28 )
        break;
      v25 = vOrigin.z;
    }
  }
  if ( v24 < SLODWORD(v13) )
  {
    v29 = (float *)(LODWORD(vOrigin.x) + 12 * v24 + 8);
    v30 = (float *)(LODWORD(vNewColor.x) + 24 * v24 + 16);
    do
    {
      if ( *((int *)v30 - 1) > -1 )
      {
        *(float *)(LODWORD(vOrigin.y) + 4 * v24) = *v30;
        *(v29 - 2) = *(v30 - 4);
        *(v29 - 1) = *(v30 - 3);
        *v29 = *(v30 - 2);
      }
      ++v24;
      v30 += 6;
      v29 += 3;
    }
    while ( v24 < SLODWORD(v13) );
  }
  v31 = 0.0;
  vNewColor.z = 0.0;
  if ( SLODWORD(v13) > 0 )
  {
    v32 = vOrigin.x;
    v33 = flPushBack;
    vOrigin.z = vOrigin.x;
    do
    {
      v34 = *(float *)(LODWORD(vOrigin.y) + 4 * LODWORD(v31));
      if ( v34 < 3.4028235e38 && v34 > 30.0 )
      {
        v35 = *(_QWORD *)LODWORD(v32);
        vShiftedOrigin.z = *(float *)(LODWORD(v32) + 8);
        v36 = iVariation * sampler->m_NumSamples;
        m_pvDirections = sampler->m_pvDirections;
        *(_QWORD *)&vShiftedOrigin.x = v35;
        v38 = v35;
        v39 = LODWORD(v31) + v36;
        v40 = *(_QWORD *)&m_pvDirections[v39].x;
        v41 = vShiftedOrigin.z * v33;
        v42 = m_pvDirections[v39].z;
        v80 = v40;
        v43 = *((float *)&v38 + 1) * v33;
        v44 = *(float *)&v38 * v33;
        v81 = v42;
        v45 = vPoint->x + (float)(*(float *)&v40 * v34);
        *(float *)&v40 = (float)(vPoint->y + (float)(*((float *)&v40 + 1) * v34)) + v43;
        v46 = vAttenuation->z;
        v47 = (float)(vPoint->z + (float)(v42 * v34)) + v41;
        LODWORD(vHitNormal.y) = v40;
        v48 = flTraceLength - v34;
        vHitNormal.z = v47;
        v49 = vAttenuation->y;
        flIntensity = v46;
        vHitNormal.x = v45 + v44;
        v50 = vAttenuation->x;
        v74 = -*(float *)&v80;
        v51 = 1.0 / (float)((float)((float)(v49 * v34) + v50) + (float)(v46 * (float)(v34 * v34)));
        v77 = -*((float *)&v80 + 1);
        v79 = -v42;
        vNewColor.y = flTraceLength - v34;
        if ( (float)((float)((float)((float)-*((float *)&v80 + 1) * vShiftedOrigin.y)
                           + (float)((float)-*(float *)&v80 * vShiftedOrigin.x))
                   + (float)((float)-v42 * vShiftedOrigin.z)) >= 0.0 )
          v52 = (float)((float)(v77 * vShiftedOrigin.y) + (float)(v74 * vShiftedOrigin.x))
              + (float)(v79 * vShiftedOrigin.z);
        else
          v52 = 0.0;
        v53 = v76;
        m_pMemory = v76[6].m_pMemory;
        m_nAllocationCount = v76[5].m_nAllocationCount;
        v56 = vColor->y * v51;
        v57 = vColor->z * v51;
        *(float *)&v87 = (float)((float)(vColor->x * v51) * v52) * v75;
        v72 = vShiftedOrigin;
        *(Vector *)&rayStream_116[808] = vHitNormal;
        *((float *)&v87 + 1) = (float)(v56 * v52) * v75;
        v88 = (float)(v57 * v52) * v75;
        v70 = __PAIR64__(LODWORD(v49), LODWORD(v50));
        v71 = flIntensity;
        if ( (int)&m_pMemory->m_pTransform + 1 > m_nAllocationCount )
        {
          CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(
            this: v76 + 5,
            num: (int)&m_pMemory->m_pTransform - m_nAllocationCount + 1);
          v48 = vNewColor.y;
          v31 = vNewColor.z;
        }
        ++v53[6].m_pMemory;
        v58 = v53[5].m_pMemory;
        v59 = (char *)v53[6].m_pMemory - (char *)m_pMemory - 1;
        v53[6].m_nAllocationCount = (int)v58;
        if ( v59 > 0 )
        {
          _V_memmove(dest: &v58[(int)m_pMemory + 1], src: &v58[(_DWORD)m_pMemory], count: 56 * v59);
          v48 = vNewColor.y;
          v31 = vNewColor.z;
        }
        v33 = flPushBack;
        v60 = (int)m_pMemory;
        v13 = vSamplerDir.x;
        v61 = (int)&v53[5].m_pMemory[v60];
        if ( v61 != 0 )
        {
          v62 = *(_DWORD *)&rayStream_116[816];
          *(_QWORD *)v61 = *(_QWORD *)&rayStream_116[808];
          v63 = v87;
          *(_DWORD *)(v61 + 8) = v62;
          v64 = v71;
          *(_QWORD *)(v61 + 12) = __PAIR64__(HIDWORD(v87), v63);
          *(float *)(v61 + 20) = v88;
          v65 = v70;
          *(float *)(v61 + 24) = v48;
          *(_QWORD *)(v61 + 28) = v65;
          v66 = *(_QWORD *)&v72.x;
          *(float *)(v61 + 36) = v64;
          v67 = v72.z;
          *(_QWORD *)(v61 + 40) = v66;
          LODWORD(v66) = v73;
          *(float *)(v61 + 48) = v67;
          *(_DWORD *)(v61 + 52) = v66;
        }
      }
      ++LODWORD(v31);
      LODWORD(v32) = LODWORD(vOrigin.z) + 12;
      vNewColor.z = v31;
      LODWORD(vOrigin.z) += 12;
    }
    while ( SLODWORD(v31) < SLODWORD(v13) );
  }
  free(pMem: (void *)LODWORD(vNewColor.x));
  free(pMem: (void *)LODWORD(vOrigin.y));
  free(pMem: (void *)LODWORD(vOrigin.x));
}

//------------------------------------------------------------------------------
// Address: 0x0040F280
// Name: public: void CWorldLighting::ShootVirtualPointLights(int,int,int,int,class RayTracingEnvironment __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWorldLighting::ShootVirtualPointLights(
        CWorldLighting *this@<ecx>,
        float a2@<edi>,
        int nSqrtPointSamples,
        int nSqrtSpotSamples,
        int nSqrtBounceSamples,
        int nBounces,
        RayTracingEnvironment *kdTree,
        float flPushBack)
{
  int v9; // ebx
  int m_Size; // eax
  int v11; // edi
  float v12; // edx
  __int64 v13; // xmm1_8
  char *v14; // eax
  float v15; // ecx
  float v16; // xmm0_4
  __int64 v17; // xmm1_8
  int v18; // edi
  CSpotLight *m_pMemory; // edx
  float v20; // xmm0_4
  float v21; // ecx
  float *v22; // eax
  float v23; // edx
  __int64 v24; // xmm0_8
  int v25; // ecx
  int v26; // edi
  CPointLight *v27; // eax
  __int64 v28; // xmm0_8
  float z; // ecx
  float v30; // edx
  CPointLight *v31; // eax
  __int64 v32; // xmm0_8
  __int64 v33; // xmm0_8
  bool v34; // zf
  float flTraceLength; // [esp+0h] [ebp-7Ch]
  float flCosAngle; // [esp+Ch] [ebp-70h]
  float flCosAnglea; // [esp+Ch] [ebp-70h]
  long double v38; // [esp+14h] [ebp-68h]
  Vector vOrigin; // [esp+20h] [ebp-5Ch] BYREF
  Vector vColor; // [esp+2Ch] [ebp-50h] BYREF
  Vector vAttenuation; // [esp+38h] [ebp-44h] BYREF
  Vector vDirection; // [esp+44h] [ebp-38h] BYREF
  CUniformSampler samplerPoint; // [esp+50h] [ebp-2Ch] BYREF
  CUniformSampler samplerCone; // [esp+5Ch] [ebp-20h] BYREF
  CUniformSampler samplerBounce; // [esp+68h] [ebp-14h] BYREF
  float flCosSpot; // [esp+74h] [ebp-8h]
  float flPassPercent; // [esp+78h] [ebp-4h]
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF
  int nVPLCount; // [esp+84h] [ebp+8h]
  int nVPLCounta; // [esp+84h] [ebp+8h]
  int nVPLCountb; // [esp+84h] [ebp+8h]
  int nBounceVar; // [esp+88h] [ebp+Ch]
  int nVPLStart; // [esp+8Ch] [ebp+10h]
  int nVPLStarta; // [esp+8Ch] [ebp+10h]
  int nBouncesa; // [esp+90h] [ebp+14h]

  v9 = 0;
  this->m_virtualPointLights.m_Memory.m_nGrowSize = 1024;
  memset(&samplerPoint, 0, sizeof(samplerPoint));
  CUniformSampler::InitSamples(this: &samplerPoint, a2, SqrtNumSamples: nSqrtPointSamples, NumVariations: 64);
  memset(&samplerCone, 0, sizeof(samplerCone));
  CUniformSampler::InitSamples(this: &samplerCone, a2, SqrtNumSamples: nSqrtSpotSamples, NumVariations: 64);
  memset(&samplerBounce, 0, sizeof(samplerBounce));
  CUniformSampler::InitSamples(this: &samplerBounce, a2, SqrtNumSamples: nSqrtBounceSamples, NumVariations: 128);
  _Msg(a1: "\nShooting 1st bounce VPLs from point lights\n");
  m_Size = this->m_pointLights.m_Size;
  v11 = 0;
  if ( m_Size > 0 )
  {
    memset(&vDirection, 0, sizeof(vDirection));
    for ( nVPLCount = m_Size; nVPLCount != 0; --nVPLCount )
    {
      v12 = *(float *)((char *)&this->m_pointLights.m_Memory.m_pMemory->m_instData.m_vColorNRadius.z + v9);
      v13 = *(_QWORD *)((char *)&this->m_pointLights.m_Memory.m_pMemory->m_instData.m_vOrigin.x + v9);
      v14 = (char *)this->m_pointLights.m_Memory.m_pMemory + v9;
      vOrigin.z = *((float *)v14 + 2);
      v15 = *((float *)v14 + 9);
      vColor.z = v12;
      v16 = *((float *)v14 + 13);
      *(_QWORD *)&vOrigin.x = v13;
      *(_QWORD *)&vColor.x = *(_QWORD *)(v14 + 12);
      v17 = *(_QWORD *)(v14 + 28);
      vAttenuation.z = v15;
      *(_QWORD *)&vAttenuation.x = v17;
      CWorldLighting::ShootLights(
        this,
        a2: (int)&savedregs,
        vPoint: &vOrigin,
        &vColor,
        &vAttenuation,
        sampler: &samplerPoint,
        iVariation: v11,
        kdTree,
        flTraceLength: v16,
        flPushBack,
        &vDirection,
        flCosAngle: 0.0,
        bUseAngle: false);
      v11 = (v11 + 1) % 64;
      v9 += 56;
    }
    v9 = 0;
  }
  _Msg(a1: "\nShooting 1st bounce VPLs from spot lights\n");
  v18 = 0;
  if ( this->m_spotLights.m_Size > 0 )
  {
    nVPLCounta = this->m_spotLights.m_Size;
    do
    {
      m_pMemory = this->m_spotLights.m_Memory.m_pMemory;
      v20 = *(float *)((char *)&m_pMemory->m_instData.m_vTransform0.w + v9);
      v21 = *(float *)((char *)&m_pMemory->m_instData.m_vColorNRadius.z + v9);
      v22 = (float *)((char *)&m_pMemory->m_instData.m_vTransform0.x + v9);
      v23 = *(float *)((char *)&m_pMemory->m_instData.m_vAttenuationNCosSpot.z + v9);
      vAttenuation.x = v20;
      vAttenuation.y = v22[7];
      vAttenuation.z = v22[11];
      vDirection.x = v22[2];
      vDirection.y = v22[6];
      vDirection.z = v22[10];
      *(_QWORD *)&vColor.x = *((_QWORD *)v22 + 6);
      v24 = *((_QWORD *)v22 + 8);
      vColor.z = v21;
      *(_QWORD *)&vOrigin.x = v24;
      flCosAngle = v22[19];
      flTraceLength = v22[20];
      vOrigin.z = v23;
      CWorldLighting::ShootLights(
        this,
        a2: (int)&savedregs,
        vPoint: &vAttenuation,
        &vColor,
        vAttenuation: &vOrigin,
        sampler: &samplerCone,
        iVariation: v18,
        kdTree,
        flTraceLength,
        flPushBack,
        &vDirection,
        flCosAngle,
        bUseAngle: true);
      v18 = (v18 + 1) % 64;
      v9 += 84;
      --nVPLCounta;
    }
    while ( nVPLCounta != 0 );
    v9 = 0;
  }
  if ( nBounces > 1 )
  {
    _Msg(a1: "\nShooting bounces\n");
    v25 = this->m_virtualPointLights.m_Size;
    flPassPercent = 1.0 / (float)nBounces;
    nVPLCountb = v25;
    __libm_sse2_cos(x: v38);
    flCosSpot = 1.495996594429016;
    nBounceVar = 0;
    nBouncesa = nBounces - 1;
    while ( 1 )
    {
      if ( v9 < nVPLCountb )
      {
        v26 = v9;
        nVPLStart = nVPLCountb - v9;
        do
        {
          if ( flPassPercent > (float)((float)rand() * 0.000030518509) )
          {
            v27 = this->m_virtualPointLights.m_Memory.m_pMemory;
            v28 = *(_QWORD *)&v27[v26].m_instData.m_vOrigin.x;
            z = v27[v26].m_instData.m_vOrigin.z;
            v30 = v27[v26].m_vHitNormal.z;
            v31 = &v27[v26];
            *(_QWORD *)&vDirection.x = v28;
            *(_QWORD *)&vOrigin.x = *(_QWORD *)&v31->m_vHitNormal.x;
            v32 = *(_QWORD *)&v31->m_instData.m_vColorNRadius.x;
            vDirection.z = z;
            flCosAnglea = v31->m_instData.m_vColorNRadius.z;
            *(_QWORD *)&vAttenuation.x = v32;
            v33 = *(_QWORD *)&v31->m_instData.m_vAttenuation.x;
            vAttenuation.z = flCosAnglea;
            *(_QWORD *)&vColor.x = v33;
            *(float *)&v33 = v31->m_instData.m_vColorNRadius.w;
            vOrigin.z = v30;
            vColor.z = v31->m_instData.m_vAttenuation.z;
            CWorldLighting::ShootLights(
              this,
              a2: (int)&savedregs,
              vPoint: &vDirection,
              vColor: &vAttenuation,
              vAttenuation: &vColor,
              sampler: &samplerBounce,
              iVariation: nBounceVar,
              kdTree,
              flTraceLength: *(float *)&v33,
              flPushBack,
              vDirection: &vOrigin,
              flCosAngle: flCosSpot,
              bUseAngle: true);
            nBounceVar = (nBounceVar + 1) % 128;
          }
          ++v26;
          --nVPLStart;
        }
        while ( nVPLStart != 0 );
      }
      v34 = nBouncesa-- == 1;
      nVPLStarta = nVPLCountb;
      nVPLCountb = this->m_virtualPointLights.m_Size;
      if ( v34 )
        break;
      v9 = nVPLStarta;
    }
  }
  if ( samplerBounce.m_pvDirections != nullptr )
    free(pMem: samplerBounce.m_pvDirections);
  if ( samplerCone.m_pvDirections != nullptr )
    free(pMem: samplerCone.m_pvDirections);
  if ( samplerPoint.m_pvDirections != nullptr )
    free(pMem: samplerPoint.m_pvDirections);
}

//------------------------------------------------------------------------------
// Address: 0x0040F640
// Name: public: void CWorldLighting::GridVPLs(float,float,float,class RayTracingEnvironment __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CWorldLighting::GridVPLs(
        CWorldLighting *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        float flGridSize,
        float flMaxRadius,
        float flBounceScale,
        RayTracingEnvironment *kdTree)
{
  float v8; // edi
  double v9; // xmm0_8
  float v10; // xmm6_4
  double v11; // xmm0_8
  float v12; // xmm5_4
  double z; // xmm0_8
  float v14; // xmm4_4
  double v15; // xmm0_8
  float v16; // xmm3_4
  double v17; // xmm0_8
  float v18; // xmm2_4
  double v19; // xmm0_8
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  int v24; // esi
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // edx
  void *v28; // eax
  float v29; // xmm1_4
  int v30; // ecx
  float v31; // eax
  __int128 v32; // xmm0
  float v33; // xmm4_4
  float v34; // xmm2_4
  __int128 v35; // xmm3
  _DWORD *v36; // edx
  _DWORD *v37; // eax
  float v38; // esi
  bool v39; // zf
  int v40; // esi
  int v41; // eax
  float v42; // edx
  float v43; // xmm4_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  int v46; // edx
  float *v47; // eax
  int v48; // ecx
  int v49; // ecx
  int v50; // eax
  float v51; // xmm0_4
  int v52; // edi
  int v53; // ecx
  float *v54; // eax
  float v55; // xmm0_4
  float v56; // ecx
  int v57; // ecx
  float v58; // xmm0_4
  float *v59; // eax
  int v60; // eax
  float v61; // xmm2_4
  int v62; // eax
  float v63; // xmm1_4
  __int64 v64; // xmm0_8
  __int64 v65; // xmm0_8
  int v66; // eax
  float v67; // xmm0_4
  __int128 v68; // xmm2
  double v69; // st7
  float v70; // xmm5_4
  float v71; // xmm6_4
  float v72; // xmm0_4
  int v73; // eax
  float v74; // ecx
  int v75; // edx
  int v76; // eax
  int v77; // ecx
  float v78; // xmm2_4
  int v79; // [esp+10h] [ebp-14Ch]
  int v80; // [esp+14h] [ebp-148h]
  int v81; // [esp+20h] [ebp-13Ch]
  float v82; // [esp+24h] [ebp-138h]
  int v83; // [esp+28h] [ebp-134h]
  float v84; // [esp+30h] [ebp-12Ch]
  float v85; // [esp+34h] [ebp-128h]
  int v86; // [esp+38h] [ebp-124h]
  float v87; // [esp+40h] [ebp-11Ch]
  float v88; // [esp+44h] [ebp-118h]
  int v89; // [esp+48h] [ebp-114h]
  __int64 v90; // [esp+60h] [ebp-FCh]
  Vector v91[2]; // [esp+70h] [ebp-ECh] BYREF
  Vector vAttenuation; // [esp+88h] [ebp-D4h]
  int v93; // [esp+94h] [ebp-C8h]
  int v94; // [esp+98h] [ebp-C4h]
  __int64 v95; // [esp+9Ch] [ebp-C0h]
  float v96; // [esp+A4h] [ebp-B8h]
  Vector vColor; // [esp+A8h] [ebp-B4h] BYREF
  float v98; // [esp+B4h] [ebp-A8h]
  Vector vOrigin; // [esp+B8h] [ebp-A4h] BYREF
  Vector vPos; // [esp+C4h] [ebp-98h]
  _BYTE v101[36]; // [esp+D0h] [ebp-8Ch] OVERLAPPED BYREF
  float v102; // [esp+F4h] [ebp-68h]
  float v103; // [esp+F8h] [ebp-64h]
  int x; // [esp+FCh] [ebp-60h] BYREF
  float v105; // [esp+100h] [ebp-5Ch]
  float flAttenDelta; // [esp+104h] [ebp-58h]
  Vector vStep; // [esp+108h] [ebp-54h] BYREF
  Vector vDelta; // [esp+114h] [ebp-48h]
  float flDrawRad; // [esp+120h] [ebp-3Ch]
  int v110; // [esp+124h] [ebp-38h]
  int nCell; // [esp+128h] [ebp-34h]
  int nLights; // [esp+12Ch] [ebp-30h]
  int i; // [esp+130h] [ebp-2Ch]
  int v114; // [esp+134h] [ebp-28h]
  __int64 v115; // [esp+138h] [ebp-24h] OVERLAPPED BYREF
  int nX; // [esp+140h] [ebp-1Ch]
  Vector vDirection; // [esp+144h] [ebp-18h]
  int y; // [esp+150h] [ebp-Ch] BYREF
  int nZ; // [esp+154h] [ebp-8h]
  int retaddr; // [esp+15Ch] [ebp+0h]

  y = a2;
  nZ = retaddr;
  v80 = a4;
  v79 = a3;
  v8 = *(float *)&this;
  v103 = *(float *)&this;
  CWorldLighting::FindLightBounds(this, result: (AABB_t *)v101);
  v9 = kdTree->m_MinBound.x;
  if ( v9 < *(float *)v101 )
    v9 = *(float *)v101;
  v10 = v9;
  v11 = kdTree->m_MinBound.y;
  *(float *)v101 = v10;
  if ( v11 < *(float *)&v101[4] )
    v11 = *(float *)&v101[4];
  v12 = v11;
  z = kdTree->m_MinBound.z;
  if ( z < *(float *)&v101[8] )
    z = *(float *)&v101[8];
  v14 = z;
  v15 = kdTree->m_MaxBound.x;
  if ( v15 > *(float *)&v101[12] )
    v15 = *(float *)&v101[12];
  v16 = v15;
  v17 = kdTree->m_MaxBound.y;
  if ( v17 > *(float *)&v101[16] )
    v17 = *(float *)&v101[16];
  v18 = v17;
  v19 = kdTree->m_MaxBound.z;
  if ( v19 > *(float *)&v101[20] )
    v19 = *(float *)&v101[20];
  v20 = v19;
  vStep.y = v18 - v12;
  vStep.z = v20 - v14;
  v21 = 1.0 / flGridSize;
  v22 = v16 - v10;
  v23 = (float)(1.0 / flGridSize) * (float)(v16 - v10);
  vStep.x = v22;
  if ( v23 < 1.0 )
    v23 = 1.0;
  v24 = (int)v23;
  v25 = v21 * vStep.y;
  v114 = v24;
  if ( (float)(v21 * vStep.y) < 1.0 )
    v25 = 1.0;
  v26 = v21 * vStep.z;
  LODWORD(vDirection.z) = (int)v25;
  if ( v26 < 1.0 )
    v26 = 1.0;
  v27 = *(float *)(LODWORD(v8) + 72);
  LODWORD(vDirection.y) = (int)v26;
  flDrawRad = v27;
  *(float *)v101 = *(float *)v101 - 0.0099999998;
  *(float *)&v101[4] = v12 - 0.0099999998;
  *(float *)&v101[8] = v14 - 0.0099999998;
  *(float *)&v101[12] = v16 + 0.0099999998;
  *(float *)&v101[16] = v18 + 0.0099999998;
  *(float *)&v101[20] = v20 + 0.0099999998;
  v28 = MemAlloc_Alloc(
          nSize: (336 * (unsigned __int64)(unsigned int)(v24 * LODWORD(vDirection.z) * (int)v26)) >> 32 != 0
        ? -1
        : 336 * v24 * LODWORD(vDirection.z) * (int)v26);
  flAttenDelta = vStep.z / (float)SLODWORD(vDirection.y);
  v105 = vStep.y / (float)SLODWORD(vDirection.z);
  nCell = (int)v28;
  *(float *)&x = vStep.x / (float)v24;
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    vPlaneDirs[0].x = 1.0;
    dword_7866EC = 0;
    dword_7866F0 = 0;
    dword_7866F4 = -1082130432;
    dword_7866F8 = 0;
    dword_7866FC = 0;
    dword_786700 = 0;
    dword_786704 = 1065353216;
    dword_786708 = 0;
    dword_78670C = 0;
    dword_786710 = -1082130432;
    dword_786714 = 0;
    dword_786718 = 0;
    dword_78671C = 0;
    dword_786720 = 1065353216;
    dword_786724 = 0;
    dword_786728 = 0;
    dword_78672C = -1082130432;
  }
  vDelta.z = 0.0;
  v115 = *(_QWORD *)v101;
  nX = *(int *)&v101[8];
  for ( i = 0; i < SLODWORD(vDirection.y); ++i )
  {
    _Msg(a1: ".", v79, v80);
    v29 = *(float *)&v101[4];
    HIDWORD(v115) = *(_DWORD *)&v101[4];
    vDirection.x = 0.0;
    if ( SLODWORD(vDirection.z) > 0 )
    {
      LODWORD(vPos.y) = 28 * v24;
      v93 = 84 * v24;
      v94 = 336 * v24;
      v30 = 336 * LODWORD(vDelta.z);
      nLights = 336 * LODWORD(vDelta.z);
      LODWORD(vPos.x) = 28 * LODWORD(vDelta.z) + 20;
      LODWORD(v31) = 84 * LODWORD(vDelta.z) + 78;
      do
      {
        v32 = *(unsigned int *)v101;
        LODWORD(v115) = *(_DWORD *)v101;
        *(_DWORD *)&v101[32] = 0;
        if ( v24 > 0 )
        {
          v33 = *(float *)&nX + flAttenDelta;
          LODWORD(vDelta.z) += v24;
          v102 = v31;
          vPos.z = vPos.x;
          nLights += v94;
          LODWORD(vDelta.x) = v93 + LODWORD(v31);
          LODWORD(vPos.x) += LODWORD(vPos.y);
          v34 = v29 + v105;
          vColor.z = v29 + v105;
          v98 = *(float *)&nX + flAttenDelta;
          v110 = v30;
          do
          {
            v35 = v32;
            *(float *)&v35 = *(float *)&v32 + *(float *)&x;
            vAttenuation.x = *(float *)&v32 + *(float *)&x;
            vAttenuation.y = v34;
            vAttenuation.z = v33;
            if ( *(_DWORD *)&v101[32] == v114 - 1 )
              vAttenuation.x = *(float *)&v101[12];
            if ( LODWORD(vDirection.x) == LODWORD(vDirection.z) - 1 )
              vAttenuation.y = *(float *)&v101[16];
            if ( i == LODWORD(vDirection.y) - 1 )
              vAttenuation.z = *(float *)&v101[20];
            LODWORD(vColor.x) = nCell + v30 + 312;
            v36 = (_DWORD *)(nCell + v30 + 248);
            v37 = (_DWORD *)(nCell + v30 + 20);
            LODWORD(vDelta.y) = 6;
            do
            {
              v38 = vColor.x;
              *(_DWORD *)LODWORD(vColor.x) = 0;
              *(v36 - 2) = 0;
              *(v36 - 1) = 0;
              *v36 = 0;
              *(v37 - 5) = 0;
              *(v37 - 4) = 0;
              *(v37 - 3) = 0;
              *(v37 - 2) = 0;
              *(v37 - 1) = 0;
              *v37 = 0;
              v37[1] = 0;
              v37[2] = 0;
              v37[3] = 0;
              v37[4] = 0;
              v36 += 3;
              v37 += 10;
              v39 = LODWORD(vDelta.y)-- == 1;
              LODWORD(vColor.x) = LODWORD(v38) + 4;
            }
            while ( !v39 );
            if ( SLODWORD(flDrawRad) > 0 )
            {
              v40 = 0;
              vDelta.y = flDrawRad;
              do
              {
                v41 = v40 + *(_DWORD *)(LODWORD(v8) + 60);
                v42 = *(float *)(v41 + 8);
                *(_QWORD *)&vOrigin.x = *(_QWORD *)v41;
                vOrigin.z = v42;
                if ( vOrigin.x > *(float *)&v32 && vAttenuation.x >= vOrigin.x )
                {
                  v43 = vOrigin.y;
                  if ( vOrigin.y > v29 && vAttenuation.y >= vOrigin.y )
                  {
                    v44 = vOrigin.z;
                    if ( vOrigin.z > *(float *)&nX && vAttenuation.z >= vOrigin.z )
                    {
                      v45 = -1.0;
                      v46 = -1;
                      if ( (float)((float)((float)(*(float *)(v41 + 44) * *(float *)&dword_7866EC)
                                         + (float)(vPlaneDirs[0].x * *(float *)(v41 + 40)))
                                 + (float)(*(float *)(v41 + 48) * *(float *)&dword_7866F0)) > -1.0 )
                      {
                        v45 = (float)((float)(*(float *)(v41 + 44) * *(float *)&dword_7866EC)
                                    + (float)(vPlaneDirs[0].x * *(float *)(v41 + 40)))
                            + (float)(*(float *)(v41 + 48) * *(float *)&dword_7866F0);
                        v46 = 0;
                      }
                      if ( (float)((float)((float)(*(float *)(v41 + 44) * *(float *)&dword_7866F8)
                                         + (float)(*(float *)&dword_7866F4 * *(float *)(v41 + 40)))
                                 + (float)(*(float *)(v41 + 48) * *(float *)&dword_7866FC)) > v45 )
                      {
                        v45 = (float)((float)(*(float *)(v41 + 44) * *(float *)&dword_7866F8)
                                    + (float)(*(float *)&dword_7866F4 * *(float *)(v41 + 40)))
                            + (float)(*(float *)(v41 + 48) * *(float *)&dword_7866FC);
                        v46 = 1;
                      }
                      if ( (float)((float)((float)(*(float *)(v41 + 44) * *(float *)&dword_786704)
                                         + (float)(*(float *)&dword_786700 * *(float *)(v41 + 40)))
                                 + (float)(*(float *)(v41 + 48) * *(float *)&dword_786708)) > v45 )
                      {
                        v45 = (float)((float)(*(float *)(v41 + 44) * *(float *)&dword_786704)
                                    + (float)(*(float *)&dword_786700 * *(float *)(v41 + 40)))
                            + (float)(*(float *)(v41 + 48) * *(float *)&dword_786708);
                        v46 = 2;
                      }
                      if ( (float)((float)((float)(*(float *)(v41 + 44) * *(float *)&dword_786710)
                                         + (float)(*(float *)&dword_78670C * *(float *)(v41 + 40)))
                                 + (float)(*(float *)(v41 + 48) * *(float *)&dword_786714)) > v45 )
                      {
                        v45 = (float)((float)(*(float *)(v41 + 44) * *(float *)&dword_786710)
                                    + (float)(*(float *)&dword_78670C * *(float *)(v41 + 40)))
                            + (float)(*(float *)(v41 + 48) * *(float *)&dword_786714);
                        v46 = 3;
                      }
                      if ( (float)((float)((float)(*(float *)(v41 + 44) * *(float *)&dword_78671C)
                                         + (float)(*(float *)&dword_786718 * *(float *)(v41 + 40)))
                                 + (float)(*(float *)(v41 + 48) * *(float *)&dword_786720)) > v45 )
                      {
                        v45 = (float)((float)(*(float *)(v41 + 44) * *(float *)&dword_78671C)
                                    + (float)(*(float *)&dword_786718 * *(float *)(v41 + 40)))
                            + (float)(*(float *)(v41 + 48) * *(float *)&dword_786720);
                        v46 = 4;
                      }
                      if ( (float)((float)((float)(*(float *)(v41 + 44) * *(float *)&dword_786728)
                                         + (float)(*(float *)&dword_786724 * *(float *)(v41 + 40)))
                                 + (float)(*(float *)(v41 + 48) * *(float *)&dword_78672C)) > v45 )
                        v46 = 5;
                      v47 = (float *)(v30 + 40 * v46 + nCell);
                      *v47 = *v47 + vOrigin.x;
                      v47[1] = v47[1] + v43;
                      v47[2] = v47[2] + v44;
                      v48 = *(_DWORD *)(LODWORD(v8) + 60);
                      v47[3] = v47[3] + *(float *)(v40 + v48 + 12);
                      v47[4] = *(float *)(v40 + v48 + 16) + v47[4];
                      v47[5] = *(float *)(v40 + v48 + 20) + v47[5];
                      v47[6] = *(float *)(v40 + v48 + 24) + v47[6];
                      v49 = *(_DWORD *)(LODWORD(v8) + 60);
                      v47[7] = *(float *)(v40 + v49 + 28) + v47[7];
                      v47[8] = *(float *)(v40 + v49 + 32) + v47[8];
                      v47[9] = *(float *)(v40 + v49 + 36) + v47[9];
                      v50 = *(_DWORD *)(LODWORD(v8) + 60);
                      v51 = *(float *)(v40 + v50 + 40);
                      v52 = nCell;
                      v53 = v40 + v50 + 40;
                      v29 = *((float *)&v115 + 1);
                      v54 = (float *)(nCell + 12 * (v46 + LODWORD(vPos.z)));
                      *v54 = v51 + *v54;
                      v54[1] = *(float *)(v53 + 4) + v54[1];
                      v55 = *(float *)(v53 + 8) + v54[2];
                      v56 = v102;
                      v54[2] = v55;
                      v57 = v46 + LODWORD(v56);
                      v58 = *(float *)(v52 + 4 * v57) + 1.0;
                      v59 = (float *)(v52 + 4 * v57);
                      v8 = v103;
                      v30 = v110;
                      *v59 = v58;
                      LODWORD(v32) = v115;
                    }
                  }
                }
                v40 += 56;
                --LODWORD(vDelta.y);
              }
              while ( LODWORD(vDelta.y) != 0 );
              v34 = vColor.z;
              v33 = v98;
            }
            LODWORD(vPos.z) += 28;
            LODWORD(v102) += 84;
            v30 += 336;
            v32 = v35;
            v110 = v30;
            LODWORD(v115) = v35;
            ++*(_DWORD *)&v101[32];
          }
          while ( *(int *)&v101[32] < v114 );
          v24 = v114;
          v31 = vDelta.x;
          v30 = nLights;
        }
        ++LODWORD(vDirection.x);
        v29 = v29 + v105;
        *((float *)&v115 + 1) = v29;
      }
      while ( SLODWORD(vDirection.x) < SLODWORD(vDirection.z) );
    }
    *(float *)&nX = *(float *)&nX + flAttenDelta;
  }
  _Msg(a1: "\nAdding VPLs to scene\n");
  memset(&vOrigin, 0, sizeof(vOrigin));
  CUniformSampler::InitSamples(this: (CUniformSampler *)&vOrigin, a2: v8, SqrtNumSamples: 64, NumVariations: 1);
  v103 = 256.0 / flBounceScale;
  if ( SLODWORD(vDelta.z) > 0 )
  {
    vDirection.x = 0.0;
    v114 = 20;
    flDrawRad = vDelta.z;
    do
    {
      v60 = 0;
      i = 0;
      v110 = 0;
      nLights = LODWORD(vDirection.x) + nCell + 312;
      do
      {
        v61 = *(float *)nLights;
        if ( *(float *)nLights > 0.0 )
        {
          v62 = nCell + LODWORD(vDirection.x) + v60;
          vColor.y = (float)(1.0 / v61) * *(float *)v62;
          vColor.z = *(float *)(v62 + 4) * (float)(1.0 / v61);
          v98 = *(float *)(v62 + 8) * (float)(1.0 / v61);
          v63 = *(float *)(v62 + 24) * (float)(1.0 / v61);
          v64 = *(_QWORD *)(v62 + 12);
          v96 = *(float *)(v62 + 20);
          v95 = v64;
          v65 = *(_QWORD *)(nCell + 12 * (i + v114));
          v66 = *(int *)(nCell + 12 * (i + v114) + 8);
          vDirection.z = v63;
          v115 = v65;
          nX = v66;
          VectorNormalize(vec: (Vector *)&v115);
          v67 = vDirection.z;
          if ( vDirection.z > 0.0 )
          {
            vDelta.x = *((float *)&v95 + 1) * *((float *)&v95 + 1);
            v68 = 0;
            *(float *)&v68 = fsqrt(
                               (float)((float)(*((float *)&v95 + 1) * *((float *)&v95 + 1)) + (float)(v96 * v96))
                             + (float)(*(float *)&v95 * *(float *)&v95));
            *(_OWORD *)v101 = v68;
            if ( flMaxRadius > 0.0 && vDirection.z > flMaxRadius )
            {
              v67 = flMaxRadius;
              vDirection.z = flMaxRadius;
            }
            vAttenuation.y = (float)(*(float *)v101 * v103) / v67;
            memset(v91, 0, 12);
            v69 = FindFarthestIntersection(
                    a1: COERCE_FLOAT(&y),
                    vPoint: (Vector *)&vColor.y,
                    sampler: (CUniformSampler *)&vOrigin,
                    kdTree,
                    flTraceLength: v67,
                    vDirection: v91,
                    flCosAngle: 0.0,
                    bUseAngle: false)
                + 10.0;
            vDelta.x = v69;
            if ( vDirection.z > v69 )
              vDirection.z = vDelta.x;
            v70 = 1.0;
            vPos.y = *((float *)&v115 + 1) * 0.0;
            v71 = 0.0;
            if ( (float)((float)((float)(*(float *)&v115 * 0.0) + (float)(*((float *)&v115 + 1) * 0.0)) + *(float *)&nX) > 0.94999999 )
            {
              v71 = 1.0;
              v70 = 0.0;
            }
            *(float *)&x = (float)(*((float *)&v115 + 1) * v70) - (float)(*(float *)&nX * v71);
            v105 = (float)(*(float *)&nX * 0.0) - (float)(*(float *)&v115 * v70);
            flAttenDelta = (float)(*(float *)&v115 * v71) - vPos.y;
            vStep.x = (float)(*(float *)&nX * v105) - (float)(*((float *)&v115 + 1) * flAttenDelta);
            vStep.y = (float)(*(float *)&v115 * flAttenDelta) - (float)(*(float *)&nX * *(float *)&x);
            vStep.z = (float)(*((float *)&v115 + 1) * *(float *)&x) - (float)(*(float *)&v115 * v105);
            VectorNormalize(vec: (Vector *)&x);
            VectorNormalize(vec: &vStep);
            VectorNormalize(vec: (Vector *)&v115);
            v72 = vDirection.z;
            *(float *)&v115 = *(float *)&v115 * vDirection.z;
            *(float *)&x = *(float *)&x * vDirection.z;
            *((float *)&v115 + 1) = *((float *)&v115 + 1) * vDirection.z;
            v81 = x;
            v83 = v115;
            v105 = v105 * vDirection.z;
            flAttenDelta = flAttenDelta * vDirection.z;
            vStep.x = vStep.x * vDirection.z;
            vStep.y = vStep.y * vDirection.z;
            vStep.z = vStep.z * vDirection.z;
            *(float *)&nX = *(float *)&nX * vDirection.z;
            v82 = vStep.x;
            v84 = v105;
            v85 = vStep.y;
            v86 = HIDWORD(v115);
            v87 = flAttenDelta;
            v73 = *(_DWORD *)(LODWORD(v8) + 24);
            vDirection.y = *(float *)(LODWORD(v8) + 32);
            v88 = vStep.z;
            v89 = nX;
            LODWORD(v90) = 0;
            HIDWORD(v90) = LODWORD(vAttenuation.y);
            if ( LODWORD(vDirection.y) + 1 > v73 )
            {
              CUtlMemory<CQEMEdge,int>::Grow(
                this: (CUtlMemory<CQEMEdge,int> *)(LODWORD(v8) + 20),
                num: LODWORD(vDirection.y) - v73 + 1);
              v72 = vDirection.z;
            }
            ++*(_DWORD *)(LODWORD(v8) + 32);
            v74 = vDirection.y;
            v75 = *(_DWORD *)(LODWORD(v8) + 20);
            v76 = *(_DWORD *)(LODWORD(v8) + 32) - LODWORD(vDirection.y) - 1;
            *(_DWORD *)(LODWORD(v8) + 36) = v75;
            if ( v76 > 0 )
            {
              _V_memmove(
                dest: (void *)(v75 + 76 * LODWORD(v74) + 76),
                src: (const void *)(v75 + 76 * LODWORD(v74)),
                count: 76 * v76);
              v72 = vDirection.z;
              v74 = vDirection.y;
            }
            v77 = *(_DWORD *)(LODWORD(v8) + 20) + 76 * LODWORD(v74);
            if ( v77 != 0 )
            {
              *(_DWORD *)v77 = v81;
              *(float *)(v77 + 4) = v82;
              *(_DWORD *)(v77 + 8) = v83;
              *(float *)(v77 + 12) = vColor.y;
              *(float *)(v77 + 16) = v84;
              *(float *)(v77 + 20) = v85;
              *(_DWORD *)(v77 + 24) = v86;
              *(float *)(v77 + 28) = vColor.z;
              *(float *)(v77 + 32) = v87;
              *(float *)(v77 + 36) = v88;
              *(_DWORD *)(v77 + 40) = v89;
              *(float *)(v77 + 44) = v98;
              *(_QWORD *)(v77 + 48) = v95;
              v78 = v96;
              *(float *)(v77 + 60) = v72;
              *(float *)(v77 + 56) = v78;
              *(_QWORD *)(v77 + 64) = v90;
              *(_DWORD *)(v77 + 72) = 0;
            }
          }
        }
        ++i;
        nLights += 4;
        v60 = v110 + 40;
        v110 = v60;
      }
      while ( v60 < 240 );
      LODWORD(vDirection.x) += 336;
      v114 += 28;
      --LODWORD(flDrawRad);
    }
    while ( LODWORD(flDrawRad) != 0 );
  }
  free(pMem: (void *)nCell);
  if ( LODWORD(vOrigin.x) != 0 )
    free(pMem: (void *)LODWORD(vOrigin.x));
}

//------------------------------------------------------------------------------
// Address: 0x00410450
// Name: public: void CWorldLighting::CalculateLighting(class CWorldRendererBuilder __near *,class RayTracingEnvironment __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CWorldLighting::CalculateLighting(
        CWorldLighting *this@<ecx>,
        unsigned int a2@<ebp>,
        CWorldRendererBuilder *pWorldBuilder,
        RayTracingEnvironment *kdTree)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  int v8; // xmm2_4
  float v9; // xmm3_4
  const char *String; // eax
  int y_low; // xmm2_4
  float x; // xmm0_4
  __int128 v13; // xmm1
  float v14; // xmm1_4
  const char *v15; // xmm5_4
  float z; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  const char *v22; // eax
  KeyValues *v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm5_4
  __int128 v26; // xmm0
  const char *v27; // xmm0_4
  float v28; // xmm1_4
  double v29; // st7
  int m_Size; // ecx
  int m_nAllocationCount; // eax
  int v32; // eax
  CPointLight *v33; // eax
  float v34; // edx
  float v35; // ecx
  float v36; // xmm0_4
  float v37; // edx
  float v38; // xmm0_4
  int v39; // esi
  const char *v40; // edi
  const char *v41; // esi
  float v42; // xmm2_4
  float v43; // xmm3_4
  int v44; // edi
  KeyValues *v45; // ecx
  const char *v46; // esi
  const char *v47; // eax
  float v48; // xmm2_4
  int m_nGrowSize; // xmm0_4
  __int128 v50; // xmm1
  const char *v51; // xmm1_4
  const char *v52; // xmm5_4
  float v53; // xmm3_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm4_4
  float v58; // xmm0_4
  const char *v59; // esi
  const char *v60; // eax
  KeyValues *v61; // ecx
  const char *v62; // edi
  float v63; // xmm0_4
  float v64; // xmm3_4
  __int128 v65; // xmm0
  const char *v66; // xmm0_4
  const char *v67; // xmm1_4
  float v68; // xmm0_4
  double v69; // st7
  float v70; // xmm0_4
  float v71; // xmm0_4
  float v72; // xmm4_4
  float v73; // xmm2_4
  float v74; // xmm3_4
  float v75; // xmm5_4
  float v76; // xmm0_4
  float v77; // esi
  int v78; // edi
  int v79; // eax
  int v80; // ecx
  int v81; // eax
  int v82; // edi
  void (*v83)(const char *, ...); // esi
  int v84; // edi
  const char *v85; // esi
  const char *v86; // edi
  const char *v87; // eax
  KeyValues *v88; // ecx
  float v89; // xmm1_4
  float v90; // xmm0_4
  float v91; // xmm1_4
  float v92; // xmm0_4
  float v93; // xmm3_4
  float v94; // xmm0_4
  int v95; // xmm4_4
  float v96; // xmm5_4
  float v97; // xmm3_4
  float v98; // xmm0_4
  float v99; // esi
  int v100; // edi
  int v101; // eax
  int v102; // ecx
  int v103; // eax
  int v104; // edi
  const char *v105; // xmm1_4
  float v106; // xmm0_4
  float v107; // edi
  int v108; // eax
  const char *v109; // eax
  bool v110; // cc
  void *v111; // eax
  void *v112; // eax
  char *v113; // eax
  int x_low; // eax
  void *v115; // eax
  char v116; // [esp+30h] [ebp-1E0h] BYREF
  __int128 v117; // [esp+34h] [ebp-1DCh] OVERLAPPED
  CUniformSampler v118; // [esp+48h] [ebp-1C8h] BYREF
  CUniformSampler samplerPoint; // [esp+54h] [ebp-1BCh] BYREF
  CUniformSampler samplerCone; // [esp+60h] [ebp-1B0h] BYREF
  float flAngle; // [esp+6Ch] [ebp-1A4h] BYREF
  float v122; // [esp+70h] [ebp-1A0h] BYREF
  void *v123; // [esp+74h] [ebp-19Ch] BYREF
  int v124; // [esp+78h] [ebp-198h]
  int v125; // [esp+7Ch] [ebp-194h]
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > lightEnvList; // [esp+80h] [ebp-190h] BYREF
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > skyCamList; // [esp+94h] [ebp-17Ch]
  float v128; // [esp+A8h] [ebp-168h]
  float v129; // [esp+ACh] [ebp-164h]
  float v130; // [esp+B0h] [ebp-160h]
  float v131; // [esp+B4h] [ebp-15Ch]
  unsigned __int64 v132; // [esp+B8h] [ebp-158h]
  float v133; // [esp+C0h] [ebp-150h]
  float v134; // [esp+C4h] [ebp-14Ch]
  int v135; // [esp+C8h] [ebp-148h]
  __int64 v136; // [esp+D4h] [ebp-13Ch]
  float v137; // [esp+DCh] [ebp-134h]
  __int64 v138; // [esp+E0h] [ebp-130h]
  float v139; // [esp+E8h] [ebp-128h]
  float v140; // [esp+ECh] [ebp-124h]
  const char *v141; // [esp+F8h] [ebp-118h] BYREF
  float v142; // [esp+FCh] [ebp-114h] BYREF
  float v143; // [esp+100h] [ebp-110h]
  float v144; // [esp+104h] [ebp-10Ch] BYREF
  const char *pInnerCone; // [esp+108h] [ebp-108h] BYREF
  const char *pAngles; // [esp+10Ch] [ebp-104h] BYREF
  const char *pCone; // [esp+110h] [ebp-100h] BYREF
  int v148; // [esp+114h] [ebp-FCh]
  const char *pFarZ; // [esp+118h] [ebp-F8h]
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > light_projected; // [esp+11Ch] [ebp-F4h] BYREF
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > lights; // [esp+130h] [ebp-E0h] BYREF
  QAngle angVector; // [esp+144h] [ebp-CCh] BYREF
  KeyValues **v153; // [esp+150h] [ebp-C0h] BYREF
  int v154; // [esp+154h] [ebp-BCh] BYREF
  Vector vAngles; // [esp+158h] [ebp-B8h] BYREF
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > light_spots; // [esp+164h] [ebp-ACh] BYREF
  float d50; // [esp+178h] [ebp-98h]
  float flMaxDistance; // [esp+17Ch] [ebp-94h]
  Vector vDirection; // [esp+180h] [ebp-90h] BYREF
  Vector vUp; // [esp+18Ch] [ebp-84h] BYREF
  float d0; // [esp+198h] [ebp-78h] BYREF
  int nLights; // [esp+19Ch] [ebp-74h] BYREF
  _BYTE vOrigin[32]; // [esp+1A0h] [ebp-70h] OVERLAPPED BYREF
  Vector vRight; // [esp+1C0h] [ebp-50h] BYREF
  float v165; // [esp+1CCh] [ebp-44h] BYREF
  float v166; // [esp+1D0h] [ebp-40h]
  float y; // [esp+1D4h] [ebp-3Ch]
  float v168; // [esp+1D8h] [ebp-38h]
  _BYTE p50Distance[12]; // [esp+1DCh] [ebp-34h] OVERLAPPED BYREF
  Vector vAttenuation; // [esp+1E8h] [ebp-28h] BYREF
  const char *pLinear; // [esp+1F4h] [ebp-1Ch]
  float flFarZ; // [esp+1F8h] [ebp-18h]
  __int128 vColor; // [esp+1FCh] [ebp-14h] OVERLAPPED BYREF
  unsigned int retaddr; // [esp+210h] [ebp+0h]

  *((_QWORD *)&vColor + 1) = __PAIR64__(retaddr, a2);
  LODWORD(angVector.y) = this;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  _Msg(a1: "\n------------------------------------\n");
  _Msg(a1: "Lighting");
  _Msg(a1: "\n------------------------------------\n");
  _Msg(a1: "\nInitializing sample positions\n");
  memset(&v118, 0, sizeof(v118));
  CUniformSampler::InitSamples(this: &v118, a2: *(float *)&this, SqrtNumSamples: 128, NumVariations: 1);
  memset(&samplerPoint, 0, sizeof(samplerPoint));
  CUniformSampler::InitSamples(this: &samplerPoint, a2: *(float *)&this, SqrtNumSamples: 128, NumVariations: 1);
  _Msg(a1: "\nFinding point lights\n");
  memset(&light_projected.m_Memory.m_nGrowSize, 0, 12);
  lights.m_Memory.m_pMemory = nullptr;
  lights.m_Memory.m_nAllocationCount = 0;
  CWorldRendererBuilder::GetEntities(
    this: pWorldBuilder,
    pEntityName: "light",
    entityList: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&light_projected.m_Memory.m_nGrowSize);
  LODWORD(vUp.y) = lights.m_Memory.m_pMemory;
  DWORD1(vColor) = 0;
  if ( (int)lights.m_Memory.m_pMemory > 0 )
  {
    angVector.z = 0.0;
    v153 = nullptr;
    v154 = 0;
    do
    {
      LODWORD(vAttenuation.y) = KeyValues::GetString(
                                  this: *(KeyValues **)(light_projected.m_Memory.m_nGrowSize + 4 * DWORD1(vColor)),
                                  keyName: "origin",
                                  defaultValue: var);
      LODWORD(vColor) = KeyValues::GetString(
                          this: *(KeyValues **)(light_projected.m_Memory.m_nGrowSize + 4 * DWORD1(vColor)),
                          keyName: "_light",
                          defaultValue: var);
      KeyValues::GetString(
        this: *(KeyValues **)(light_projected.m_Memory.m_nGrowSize + 4 * DWORD1(vColor)),
        keyName: "_lightHDR",
        defaultValue: var);
      sscanf(
        string: (const char *)LODWORD(vAttenuation.y),
        format: "%f %f %f",
        &vOrigin[20],
        &vOrigin[24],
        &vOrigin[28]);
      sscanf(
        string: (const char *)vColor,
        format: "%f %f %f %f",
        &lights.m_Memory.m_nGrowSize,
        &lights.m_Size,
        &lights.m_pElements,
        &angVector);
      *(float *)&lights.m_Memory.m_nGrowSize = *(float *)&lights.m_Memory.m_nGrowSize * 0.0039215689;
      *(float *)&lights.m_Size = *(float *)&lights.m_Size * 0.0039215689;
      *(float *)&lights.m_pElements = *(float *)&lights.m_pElements * 0.0039215689;
      v5 = *(float *)&lights.m_Memory.m_nGrowSize * (float)(angVector.x * 0.0039215689);
      v6 = *(float *)&lights.m_Size * (float)(angVector.x * 0.0039215689);
      v7 = *(float *)&lights.m_pElements * (float)(angVector.x * 0.0039215689);
      angVector.x = angVector.x * 0.0039215689;
      vAttenuation.z = v5;
      *(float *)&pLinear = v6;
      flFarZ = v7;
      if ( LODWORD(vAttenuation.x) != 0 )
      {
        sscanf(string: (const char *)LODWORD(vAttenuation.x), format: "%f %f %f %f", &vUp.z, &d0, &nLights, vOrigin);
        v8 = nLights;
        v9 = d0;
        if ( vUp.z > -1.0 || d0 > -1.0 || *(float *)&nLights > -1.0 )
        {
          vAttenuation.z = (float)(*(float *)vOrigin * 0.0039215689) * (float)(vUp.z * 0.0039215689);
          *(float *)vOrigin = *(float *)vOrigin * 0.0039215689;
          vUp.z = vUp.z * 0.0039215689;
          d0 = d0 * 0.0039215689;
          *(float *)&nLights = *(float *)&nLights * 0.0039215689;
          *(float *)&pLinear = *(float *)vOrigin * (float)(v9 * 0.0039215689);
          flFarZ = *(float *)vOrigin * (float)(*(float *)&v8 * 0.0039215689);
        }
      }
      LODWORD(vAttenuation.x) = KeyValues::GetString(
                                  this: *(KeyValues **)(light_projected.m_Memory.m_nGrowSize + 4 * DWORD1(vColor)),
                                  keyName: "_zero_percent_distance",
                                  defaultValue: var);
      String = KeyValues::GetString(
                 this: *(KeyValues **)(light_projected.m_Memory.m_nGrowSize + 4 * DWORD1(vColor)),
                 keyName: "_fifty_percent_distance",
                 defaultValue: var);
      LODWORD(vColor) = String;
      light_spots.m_Memory.m_nGrowSize = 0;
      vUp.x = 0.0;
      if ( LODWORD(vAttenuation.x) != 0
        && String != nullptr
        && (sscanf(string: (const char *)LODWORD(vAttenuation.x), format: "%f", &vUp),
            sscanf(string: (const char *)vColor, format: "%f", &light_spots.m_Memory.m_nGrowSize),
            y_low = light_spots.m_Memory.m_nGrowSize,
            *(float *)&light_spots.m_Memory.m_nGrowSize != 0.0) )
      {
        x = vUp.x;
        vAttenuation.y = *(float *)&pLinear * *(float *)&pLinear;
        v13 = 0;
        *(float *)&v13 = fsqrt(
                           (float)((float)(*(float *)&pLinear * *(float *)&pLinear) + (float)(flFarZ * flFarZ))
                         + (float)(vAttenuation.z * vAttenuation.z));
        *(_OWORD *)&vOrigin[4] = v13;
        v14 = *(float *)&v13 * 256.0;
        LODWORD(vRight.y) = light_spots.m_Memory.m_nGrowSize;
        v166 = vUp.x;
        v143 = v14;
        if ( *(float *)&light_spots.m_Memory.m_nGrowSize > vUp.x )
        {
          _Warning(
            a1: "light has _fifty_percent_distance of %f but _zero_percent_distance of %f\n",
            *(float *)&light_spots.m_Memory.m_nGrowSize,
            vUp.x);
          y_low = LODWORD(vRight.y);
          v14 = v143;
          x = vRight.y * 2.0;
          v166 = vRight.y * 2.0;
        }
        vRight.z = 0.0;
        v165 = 1.0;
        vRight.x = 0.0;
        if ( !SolveInverseQuadraticMonotonic(
                x1: 0.0,
                y1: 1.0,
                x2: *(float *)&y_low,
                y2: 2.0,
                x3: x,
                y3: v14,
                a: &vRight.z,
                b: &v165,
                c: &vRight.x) )
          _Warning(a1: "can't solve quadratic for light %f %f\n", vRight.y, v166);
        v15 = pLinear;
        z = vAttenuation.z;
        v17 = 2.0 / (float)((float)((float)((float)(vRight.z * vRight.y) + v165) * vRight.y) + vRight.x);
        v18 = v17 * vRight.z;
        v19 = v17 * v165;
        v20 = v17 * vRight.x;
        vRight.x = v20;
        v21 = flFarZ;
        vRight.z = v18;
        v165 = v19;
        *(_QWORD *)p50Distance = __PAIR64__(LODWORD(v19), LODWORD(v20));
        *(float *)&p50Distance[8] = v18;
      }
      else
      {
        v22 = KeyValues::GetString(
                this: *(KeyValues **)(light_projected.m_Memory.m_nGrowSize + 4 * DWORD1(vColor)),
                keyName: "_constant_attn",
                defaultValue: var);
        v23 = *(KeyValues **)(light_projected.m_Memory.m_nGrowSize + 4 * DWORD1(vColor));
        LODWORD(vAttenuation.y) = v22;
        LODWORD(vAttenuation.x) = KeyValues::GetString(this: v23, keyName: "_linear_attn", defaultValue: var);
        KeyValues::GetString(
          this: *(KeyValues **)(light_projected.m_Memory.m_nGrowSize + 4 * DWORD1(vColor)),
          keyName: "_quadratic_attn",
          defaultValue: var);
        sscanf(string: (const char *)LODWORD(vAttenuation.y), format: "%f", p50Distance);
        sscanf(string: (const char *)LODWORD(vAttenuation.x), format: "%f", &p50Distance[4]);
        LODWORD(vAttenuation.x) = &p50Distance[8];
        sscanf(string: (const char *)vColor, format: "%f");
        v19 = *(float *)&p50Distance[4];
        v18 = *(float *)&p50Distance[8];
        v20 = *(float *)p50Distance;
        v24 = (float)((float)(*(float *)&p50Distance[4] * 100.0) + (float)(*(float *)&p50Distance[8] * 10000.0))
            + *(float *)p50Distance;
        z = vAttenuation.z * v24;
        *(float *)&v15 = *(float *)&pLinear * v24;
        v21 = v24 * flFarZ;
        vAttenuation.z = z;
        pLinear = v15;
        flFarZ = v21;
      }
      v25 = (float)((float)(*(float *)&v15 * *(float *)&v15) + (float)(v21 * v21)) + (float)(z * z);
      v26 = 0;
      *(float *)&v26 = fsqrt(v25);
      *(_OWORD *)&vOrigin[4] = v26;
      if ( *(float *)&v26 > 0.0
        && (*(_OWORD *)&vOrigin[4] = v26,
            SolveQuadratic(
              a: (float)(0.00390625 / *(float *)&v26) * v18,
              b: (float)(0.00390625 / *(float *)&v26) * v19,
              c: (float)((float)(0.00390625 / *(float *)&v26) * v20) - 1.0,
              root1: &v142,
              root2: &v144))
        && ((*(float *)&v27 = v142, v142 <= v144) ? (v28 = v144) : (v28 = v142), v28 >= 0.0) )
      {
        if ( v142 <= v144 )
          *(float *)&v27 = v144;
      }
      else
      {
        *(float *)&v27 = 0.0;
      }
      y = *(float *)&v27;
      v168 = *(float *)&v27;
      v29 = FindFarthestIntersection(
              a1: COERCE_FLOAT((__int128 *)((char *)&vColor + 8)),
              vPoint: (Vector *)&vOrigin[20],
              sampler: &v118,
              kdTree,
              flTraceLength: 60000.0,
              vDirection: (Vector *)&angVector.z,
              flCosAngle: 0.0,
              bUseAngle: false)
          + 50.0;
      vAttenuation.y = v29;
      if ( y > v29 )
        y = vAttenuation.y;
      m_Size = this->m_pointLights.m_Size;
      m_nAllocationCount = this->m_pointLights.m_Memory.m_nAllocationCount;
      v138 = 0;
      v139 = 0.0;
      v132 = *(_QWORD *)&vOrigin[20];
      v133 = *(float *)&vOrigin[28];
      v136 = *(_QWORD *)p50Distance;
      v137 = *(float *)&p50Distance[8];
      LODWORD(vColor) = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(
          (CUtlMemory<CDmeDag::TransformInfo_t,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
        m_Size = vColor;
      }
      v32 = ++this->m_pointLights.m_Size - m_Size - 1;
      this->m_pointLights.m_pElements = this->m_pointLights.m_Memory.m_pMemory;
      if ( v32 > 0 )
      {
        _V_memmove(
          dest: &this->m_pointLights.m_Memory.m_pMemory[vColor + 1],
          src: &this->m_pointLights.m_Memory.m_pMemory[vColor],
          count: 56 * v32);
        m_Size = vColor;
      }
      v33 = &this->m_pointLights.m_Memory.m_pMemory[m_Size];
      if ( v33 != nullptr )
      {
        v34 = v133;
        v35 = v137;
        *(_QWORD *)&v33->m_instData.m_vOrigin.x = v132;
        v36 = vAttenuation.z;
        v33->m_instData.m_vOrigin.z = v34;
        v37 = v139;
        v33->m_instData.m_vColorNRadius.x = v36;
        v33->m_instData.m_vColorNRadius.y = *(float *)&pLinear;
        v33->m_instData.m_vColorNRadius.z = flFarZ;
        v33->m_instData.m_vColorNRadius.w = y;
        *(_QWORD *)&v33->m_instData.m_vAttenuation.x = v136;
        *(_QWORD *)&v33->m_vHitNormal.x = v138;
        v38 = v168;
        v33->m_instData.m_vAttenuation.z = v35;
        v33->m_vHitNormal.z = v37;
        v33->m_flMaxDistance = v38;
      }
      ++DWORD1(vColor);
    }
    while ( SDWORD1(vColor) < SLODWORD(vUp.y) );
  }
  _Msg(a1: "\nFinding spot lights\n");
  memset(&vAngles, 0, sizeof(vAngles));
  light_spots.m_Memory.m_pMemory = nullptr;
  light_spots.m_Memory.m_nAllocationCount = 0;
  CWorldRendererBuilder::GetEntities(
    this: pWorldBuilder,
    pEntityName: "light_spot",
    entityList: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&vAngles);
  LODWORD(vUp.y) = light_spots.m_Memory.m_pMemory;
  DWORD1(vColor) = 0;
  if ( (int)light_spots.m_Memory.m_pMemory > 0 )
  {
    __libm_sse2_tan(x: *((long double *)&vColor + 1));
    vAttenuation.x = 1.0 / (float)0.7853981852531433;
    do
    {
      v39 = DWORD1(vColor);
      v40 = KeyValues::GetString(
              this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * DWORD1(vColor)),
              keyName: "origin",
              defaultValue: var);
      v168 = COERCE_FLOAT(
               KeyValues::GetString(
                 this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * v39),
                 keyName: "_light",
                 defaultValue: var));
      v41 = KeyValues::GetString(
              this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * v39),
              keyName: "_lightHDR",
              defaultValue: var);
      v144 = COERCE_FLOAT(
               KeyValues::GetString(
                 this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * DWORD1(vColor)),
                 keyName: "_cone",
                 defaultValue: var));
      v142 = COERCE_FLOAT(
               KeyValues::GetString(
                 this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * DWORD1(vColor)),
                 keyName: "_inner_cone",
                 defaultValue: var));
      v143 = COERCE_FLOAT(
               KeyValues::GetString(
                 this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * DWORD1(vColor)),
                 keyName: "angles",
                 defaultValue: var));
      sscanf(string: v40, format: "%f %f %f", &d0, &nLights, vOrigin);
      sscanf(
        string: (const char *)LODWORD(v168),
        format: "%f %f %f %f",
        &samplerCone.m_NumSamples,
        &samplerCone.m_NumVariations,
        &flAngle,
        &v122);
      *(float *)&samplerCone.m_NumSamples = *(float *)&samplerCone.m_NumSamples * 0.0039215689;
      vAttenuation.z = *(float *)&samplerCone.m_NumSamples * (float)(v122 * 0.0039215689);
      v122 = v122 * 0.0039215689;
      *(float *)&samplerCone.m_NumVariations = *(float *)&samplerCone.m_NumVariations * 0.0039215689;
      flAngle = flAngle * 0.0039215689;
      *(float *)&pLinear = v122 * *(float *)&samplerCone.m_NumVariations;
      flFarZ = v122 * flAngle;
      if ( v41 != nullptr )
      {
        sscanf(string: v41, format: "%f %f %f %f", &vOrigin[4], &vOrigin[8], &vOrigin[12], &vOrigin[16]);
        v42 = *(float *)&vOrigin[12];
        v43 = *(float *)&vOrigin[8];
        if ( *(float *)&vOrigin[4] > -1.0 || *(float *)&vOrigin[8] > -1.0 || *(float *)&vOrigin[12] > -1.0 )
        {
          vAttenuation.z = (float)(*(float *)&vOrigin[16] * 0.0039215689)
                         * (float)(*(float *)&vOrigin[4] * 0.0039215689);
          *(float *)&vOrigin[16] = *(float *)&vOrigin[16] * 0.0039215689;
          *(float *)&vOrigin[4] = *(float *)&vOrigin[4] * 0.0039215689;
          *(float *)&vOrigin[8] = *(float *)&vOrigin[8] * 0.0039215689;
          *(float *)&vOrigin[12] = *(float *)&vOrigin[12] * 0.0039215689;
          *(float *)&pLinear = *(float *)&vOrigin[16] * (float)(v43 * 0.0039215689);
          flFarZ = *(float *)&vOrigin[16] * (float)(v42 * 0.0039215689);
        }
      }
      sscanf(string: (const char *)LODWORD(v144), format: "%f", &samplerCone);
      sscanf(string: (const char *)LODWORD(v142), format: "%f", &v116);
      sscanf(string: (const char *)LODWORD(v143), format: "%f %f %f", &angVector.z, &v153, &v154);
      lights.m_Size = LODWORD(angVector.z) ^ _mask__NegFloat_;
      lights.m_pElements = v153;
      LODWORD(angVector.x) = v154 ^ _mask__NegFloat_;
      AngleVectors(
        angles: (const QAngle *)&lights.m_Size,
        forward: (Vector *)&light_spots.m_pElements,
        right: (Vector *)&vOrigin[20],
        up: &vDirection);
      VectorNormalize(vec: (Vector *)&light_spots.m_pElements);
      VectorNormalize(vec: (Vector *)&vOrigin[20]);
      VectorNormalize(vec: &vDirection);
      v44 = DWORD1(vColor);
      v45 = *(KeyValues **)(LODWORD(vAngles.x) + 4 * DWORD1(vColor));
      y = *(float *)&samplerCone.m_pvDirections * 0.017453292;
      v46 = KeyValues::GetString(this: v45, keyName: "_zero_percent_distance", defaultValue: var);
      *(float *)&v47 = COERCE_FLOAT(
                         KeyValues::GetString(
                           this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * v44),
                           keyName: "_fifty_percent_distance",
                           defaultValue: var));
      v166 = *(float *)&v47;
      vUp.x = 0.0;
      light_spots.m_Memory.m_nGrowSize = 0;
      if ( v46 == nullptr
        || *(float *)&v47 == 0.0
        || (sscanf(string: v46, format: "%f", &light_spots.m_Memory.m_nGrowSize),
            sscanf(string: (const char *)LODWORD(v166), format: "%f", &vUp),
            v48 = vUp.x,
            vUp.x == 0.0) )
      {
        v59 = KeyValues::GetString(
                this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * v44),
                keyName: "_constant_attn",
                defaultValue: var);
        *(float *)&v60 = COERCE_FLOAT(
                           KeyValues::GetString(
                             this: *(KeyValues **)(LODWORD(vAngles.x) + 4 * v44),
                             keyName: "_linear_attn",
                             defaultValue: var));
        v61 = *(KeyValues **)(LODWORD(vAngles.x) + 4 * v44);
        v168 = *(float *)&v60;
        v62 = KeyValues::GetString(this: v61, keyName: "_quadratic_attn", defaultValue: var);
        sscanf(string: v59, format: "%f", p50Distance);
        sscanf(string: (const char *)LODWORD(v168), format: "%f", &p50Distance[4]);
        LODWORD(vAttenuation.x) = &p50Distance[8];
        sscanf(string: v62, format: "%f");
        v56 = *(float *)&p50Distance[4];
        v55 = *(float *)&p50Distance[8];
        v57 = *(float *)p50Distance;
        v63 = (float)((float)(*(float *)&p50Distance[4] * 100.0) + (float)(*(float *)&p50Distance[8] * 10000.0))
            + *(float *)p50Distance;
        v53 = vAttenuation.z * v63;
        *(float *)&v52 = v63 * *(float *)&pLinear;
        v58 = v63 * flFarZ;
        vAttenuation.z = v53;
        pLinear = v52;
        flFarZ = v58;
      }
      else
      {
        m_nGrowSize = light_spots.m_Memory.m_nGrowSize;
        v168 = vAttenuation.z * vAttenuation.z;
        v50 = 0;
        *(float *)&v50 = fsqrt(
                           (float)((float)(vAttenuation.z * vAttenuation.z)
                                 + (float)(*(float *)&pLinear * *(float *)&pLinear))
                         + (float)(flFarZ * flFarZ));
        v117 = v50;
        *(float *)&v51 = *(float *)&v50 * 256.0;
        vRight.x = vUp.x;
        LODWORD(vAttenuation.y) = light_spots.m_Memory.m_nGrowSize;
        pInnerCone = v51;
        if ( vUp.x > *(float *)&light_spots.m_Memory.m_nGrowSize )
        {
          _Warning(
            a1: "light has _fifty_percent_distance of %f but _zero_percent_distance of %f\n",
            vUp.x,
            *(float *)&light_spots.m_Memory.m_nGrowSize);
          v48 = vRight.x;
          v51 = pInnerCone;
          *(float *)&m_nGrowSize = vRight.x * 2.0;
          vAttenuation.y = vRight.x * 2.0;
        }
        v165 = 0.0;
        vRight.z = 1.0;
        vRight.y = 0.0;
        if ( !SolveInverseQuadraticMonotonic(
                x1: 0.0,
                y1: 1.0,
                x2: v48,
                y2: 2.0,
                x3: *(float *)&m_nGrowSize,
                y3: *(float *)&v51,
                a: &v165,
                b: &vRight.z,
                c: &vRight.y) )
          _Warning(a1: "can't solve quadratic for light %f %f\n", vRight.x, vAttenuation.y);
        v52 = pLinear;
        v53 = vAttenuation.z;
        v54 = 2.0 / (float)((float)((float)((float)(v165 * vRight.x) + vRight.z) * vRight.x) + vRight.y);
        v55 = v54 * v165;
        v56 = v54 * vRight.z;
        v57 = v54 * vRight.y;
        vRight.y = v57;
        v58 = flFarZ;
        v165 = v55;
        vRight.z = v56;
        *(_QWORD *)p50Distance = __PAIR64__(LODWORD(v56), LODWORD(v57));
        *(float *)&p50Distance[8] = v55;
      }
      v64 = (float)((float)(v53 * v53) + (float)(*(float *)&v52 * *(float *)&v52)) + (float)(v58 * v58);
      v65 = 0;
      *(float *)&v65 = fsqrt(v64);
      v117 = v65;
      if ( *(float *)&v65 > 0.0
        && (v117 = v65,
            SolveQuadratic(
              a: (float)(0.00390625 / *(float *)&v117) * v55,
              b: (float)(0.00390625 / *(float *)&v65) * v56,
              c: (float)((float)(0.00390625 / *(float *)&v117) * v57) - 1.0,
              root1: (float *)&v141,
              root2: (float *)&pAngles)) )
      {
        v66 = pAngles;
        if ( *(float *)&v141 <= *(float *)&pAngles )
          v67 = pAngles;
        else
          v67 = v141;
        if ( *(float *)&v67 >= 0.0 )
        {
          if ( *(float *)&v141 > *(float *)&pAngles )
            v66 = v141;
        }
        else
        {
          v66 = nullptr;
        }
      }
      else
      {
        v66 = nullptr;
      }
      light_spots.m_Size = (int)v66;
      v68 = y;
      __libm_sse2_cosf(x: COERCE_FLOAT(1));
      v69 = FindFarthestIntersection(
              a1: COERCE_FLOAT((__int128 *)((char *)&vColor + 8)),
              vPoint: (Vector *)&d0,
              sampler: &samplerPoint,
              kdTree,
              flTraceLength: 60000.0,
              vDirection: (Vector *)&light_spots.m_pElements,
              flCosAngle: v68,
              bUseAngle: SBYTE4(vColor))
          + 50.0;
      v168 = v69;
      if ( *(float *)&vColor > v69 )
        *(float *)&vColor = v168;
      v70 = y;
      if ( y > 1.3089969 )
      {
        v70 = 1.3089969;
        y = 1.3089969;
      }
      __libm_sse2_tanf(x: *((float *)&vColor + 2));
      v71 = (float)(v70 * vAttenuation.x) * *(float *)&vColor;
      v72 = vDirection.x * v71;
      v73 = v71 * *(float *)&vOrigin[24];
      v74 = v71 * *(float *)&vOrigin[28];
      v75 = v71 * vDirection.y;
      vDirection.z = v71 * vDirection.z;
      d50 = *(float *)&vColor * d50;
      v131 = d50;
      v132 = __PAIR64__(v71 * *(float *)&vOrigin[28], nLights);
      v133 = vDirection.z;
      v135 = *(_DWORD *)vOrigin;
      v137 = *(float *)p50Distance;
      v138 = *(_QWORD *)&p50Distance[4];
      *(float *)&vOrigin[20] = *(float *)&vOrigin[20] * v71;
      skyCamList.m_Memory.m_nGrowSize = *(_DWORD *)&vOrigin[20];
      v76 = y;
      *(float *)&vOrigin[24] = v73;
      *(float *)&vOrigin[28] = v74;
      vDirection.x = v72;
      vDirection.y = v75;
      *(float *)&light_spots.m_pElements = *(float *)&light_spots.m_pElements * *(float *)&vColor;
      flMaxDistance = *(float *)&vColor * flMaxDistance;
      *(float *)&skyCamList.m_Size = v72;
      skyCamList.m_pElements = light_spots.m_pElements;
      v128 = d0;
      v129 = v73;
      v130 = v75;
      v134 = flMaxDistance;
      __libm_sse2_cosf(x: *((float *)&vColor + 2));
      v77 = angVector.y;
      v78 = *(_DWORD *)(LODWORD(angVector.y) + 52);
      v79 = *(_DWORD *)(LODWORD(angVector.y) + 44);
      v139 = v76;
      if ( v78 + 1 > v79 )
        CUtlMemory<CSpotLight,int>::Grow(
          this: (CUtlMemory<CSpotLight,int> *)(LODWORD(angVector.y) + 40),
          num: v78 - v79 + 1);
      ++*(_DWORD *)(LODWORD(v77) + 52);
      v80 = *(_DWORD *)(LODWORD(v77) + 40);
      v81 = *(_DWORD *)(LODWORD(v77) + 52) - v78 - 1;
      *(_DWORD *)(LODWORD(v77) + 56) = v80;
      if ( v81 > 0 )
        _V_memmove(dest: (void *)(84 * v78 + v80 + 84), src: (const void *)(84 * v78 + v80), count: 84 * v81);
      v82 = *(_DWORD *)(LODWORD(v77) + 40) + 84 * v78;
      if ( v82 != 0 )
      {
        *(_DWORD *)v82 = skyCamList.m_Memory.m_nGrowSize;
        *(_DWORD *)(v82 + 4) = skyCamList.m_Size;
        *(_DWORD *)(v82 + 8) = skyCamList.m_pElements;
        *(float *)(v82 + 12) = v128;
        *(float *)(v82 + 16) = v129;
        *(float *)(v82 + 20) = v130;
        *(float *)(v82 + 24) = v131;
        *(_QWORD *)(v82 + 28) = v132;
        *(float *)(v82 + 36) = v133;
        *(float *)(v82 + 40) = v134;
        *(_DWORD *)(v82 + 44) = v135;
        *(float *)(v82 + 48) = vAttenuation.z;
        *(float *)(v82 + 52) = *(float *)&pLinear;
        *(float *)(v82 + 56) = flFarZ;
        *(_DWORD *)(v82 + 60) = vColor;
        *(float *)(v82 + 64) = v137;
        *(_QWORD *)(v82 + 68) = v138;
        *(float *)(v82 + 76) = v139;
        *(_DWORD *)(v82 + 80) = light_spots.m_Size;
      }
      ++DWORD1(vColor);
    }
    while ( SDWORD1(vColor) < SLODWORD(vUp.y) );
  }
  v83 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "\nFinding env_projectedtexture lights\n");
  pCone = nullptr;
  v148 = 0;
  pFarZ = nullptr;
  light_projected.m_Memory.m_pMemory = nullptr;
  light_projected.m_Memory.m_nAllocationCount = 0;
  CWorldRendererBuilder::GetEntities(
    this: pWorldBuilder,
    pEntityName: "env_projectedtexture",
    entityList: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&pCone);
  LODWORD(vUp.y) = light_projected.m_Memory.m_pMemory;
  DWORD1(vColor) = 0;
  if ( (int)light_projected.m_Memory.m_pMemory > 0 )
  {
    __libm_sse2_tan(x: *((long double *)&vColor + 1));
    vAttenuation.x = 1.0 / (float)0.7853981852531433;
    do
    {
      v84 = DWORD1(vColor);
      v85 = KeyValues::GetString(this: *(KeyValues **)&pCone[4 * DWORD1(vColor)], keyName: "origin", defaultValue: var);
      v86 = KeyValues::GetString(this: *(KeyValues **)&pCone[4 * v84], keyName: "lightcolor", defaultValue: var);
      light_spots.m_Size = (int)KeyValues::GetString(
                                  this: *(KeyValues **)&pCone[4 * DWORD1(vColor)],
                                  keyName: "lightfov",
                                  defaultValue: var);
      *(float *)&v87 = COERCE_FLOAT(
                         KeyValues::GetString(
                           this: *(KeyValues **)&pCone[4 * DWORD1(vColor)],
                           keyName: "angles",
                           defaultValue: var));
      v88 = *(KeyValues **)&pCone[4 * DWORD1(vColor)];
      v141 = v87;
      *(float *)&pAngles = COERCE_FLOAT(KeyValues::GetString(this: v88, keyName: "farz", defaultValue: var));
      sscanf(string: v85, format: "%f %f %f", &d0, &nLights, vOrigin);
      sscanf(string: v86, format: "%f %f %f %f", &vOrigin[4], &vOrigin[8], &vOrigin[12], &vOrigin[16]);
      *(float *)&vOrigin[4] = *(float *)&vOrigin[4] * 0.0039215689;
      *(float *)p50Distance = *(float *)&vOrigin[4] * (float)(*(float *)&vOrigin[16] * 0.0039215689);
      *(float *)&vOrigin[16] = *(float *)&vOrigin[16] * 0.0039215689;
      v89 = *(float *)&vOrigin[16] * (float)(*(float *)&vOrigin[8] * 0.0039215689);
      v90 = *(float *)&vOrigin[16] * (float)(*(float *)&vOrigin[12] * 0.0039215689);
      *(float *)&vOrigin[8] = *(float *)&vOrigin[8] * 0.0039215689;
      *(float *)&vOrigin[12] = *(float *)&vOrigin[12] * 0.0039215689;
      *(float *)&p50Distance[4] = v89;
      *(float *)&p50Distance[8] = v90;
      sscanf(string: (const char *)light_spots.m_Size, format: "%f", &pInnerCone);
      sscanf(string: pAngles, format: "%f", &vAttenuation.y);
      sscanf(string: v141, format: "%f %f %f", &angVector.z, &v153, &v154);
      lights.m_Size = LODWORD(angVector.z) ^ _mask__NegFloat_;
      lights.m_pElements = v153;
      LODWORD(angVector.x) = v154 ^ _mask__NegFloat_;
      AngleVectors(
        angles: (const QAngle *)&lights.m_Size,
        forward: (Vector *)&vOrigin[20],
        right: &vDirection,
        up: (Vector *)&light_spots.m_pElements);
      VectorNormalize(vec: (Vector *)&vOrigin[20]);
      VectorNormalize(vec: &vDirection);
      VectorNormalize(vec: (Vector *)&light_spots.m_pElements);
      v91 = *(float *)&p50Distance[8];
      v92 = *(float *)&pInnerCone * 0.017453292;
      v166 = *(float *)&pInnerCone * 0.017453292;
      if ( *(float *)&p50Distance[4] <= *(float *)&p50Distance[8] )
        v93 = *(float *)&p50Distance[8];
      else
        v93 = *(float *)&p50Distance[4];
      if ( *(float *)p50Distance <= v93 )
      {
        if ( *(float *)&p50Distance[4] > *(float *)&p50Distance[8] )
          v91 = *(float *)&p50Distance[4];
      }
      else
      {
        v91 = *(float *)p50Distance;
      }
      *(float *)&pLinear = v91 / vAttenuation.y;
      if ( v92 > 1.3089969 )
      {
        v92 = 1.3089969;
        v166 = 1.3089969;
      }
      __libm_sse2_tanf(x: *((float *)&vColor + 2));
      v94 = (float)(v92 * vAttenuation.x) * vAttenuation.y;
      *(float *)&v95 = v94 * *(float *)&light_spots.m_pElements;
      v96 = v94 * d50;
      flMaxDistance = v94 * flMaxDistance;
      v97 = v94 * vDirection.y;
      *(float *)&vOrigin[24] = vAttenuation.y * *(float *)&vOrigin[24];
      v131 = *(float *)&vOrigin[24];
      LODWORD(v132) = nLights;
      vDirection.z = v94 * vDirection.z;
      HIDWORD(v132) = LODWORD(vDirection.z);
      v133 = flMaxDistance;
      vDirection.x = v94 * vDirection.x;
      skyCamList.m_Memory.m_nGrowSize = LODWORD(vDirection.x);
      v135 = *(_DWORD *)vOrigin;
      v98 = v166;
      vDirection.y = v97;
      light_spots.m_pElements = (KeyValues **)v95;
      d50 = v96;
      *(float *)&vOrigin[20] = *(float *)&vOrigin[20] * vAttenuation.y;
      *(float *)&vOrigin[28] = vAttenuation.y * *(float *)&vOrigin[28];
      v140 = vAttenuation.y;
      skyCamList.m_Size = v95;
      skyCamList.m_pElements = *(KeyValues ***)&vOrigin[20];
      v128 = d0;
      v129 = v97;
      v130 = v96;
      v134 = *(float *)&vOrigin[28];
      HIDWORD(v136) = LODWORD(vAttenuation.y);
      __libm_sse2_cosf(x: *((float *)&vColor + 2));
      v99 = angVector.y;
      v100 = *(_DWORD *)(LODWORD(angVector.y) + 52);
      v101 = *(_DWORD *)(LODWORD(angVector.y) + 44);
      v139 = v98;
      if ( v100 + 1 > v101 )
        CUtlMemory<CSpotLight,int>::Grow(
          this: (CUtlMemory<CSpotLight,int> *)(LODWORD(angVector.y) + 40),
          num: v100 - v101 + 1);
      ++*(_DWORD *)(LODWORD(v99) + 52);
      v102 = *(_DWORD *)(LODWORD(v99) + 40);
      v103 = *(_DWORD *)(LODWORD(v99) + 52) - v100 - 1;
      *(_DWORD *)(LODWORD(v99) + 56) = v102;
      if ( v103 > 0 )
        _V_memmove(dest: (void *)(84 * v100 + v102 + 84), src: (const void *)(84 * v100 + v102), count: 84 * v103);
      v104 = *(_DWORD *)(LODWORD(v99) + 40) + 84 * v100;
      if ( v104 != 0 )
      {
        *(_DWORD *)v104 = skyCamList.m_Memory.m_nGrowSize;
        *(_DWORD *)(v104 + 4) = skyCamList.m_Size;
        *(_DWORD *)(v104 + 8) = skyCamList.m_pElements;
        *(float *)(v104 + 12) = v128;
        *(float *)(v104 + 16) = v129;
        *(float *)(v104 + 20) = v130;
        *(float *)(v104 + 24) = v131;
        *(_QWORD *)(v104 + 28) = v132;
        *(float *)(v104 + 36) = v133;
        v105 = pLinear;
        *(float *)(v104 + 40) = v134;
        *(_DWORD *)(v104 + 44) = v135;
        *(_QWORD *)(v104 + 48) = *(_QWORD *)p50Distance;
        *(_DWORD *)(v104 + 56) = *(_DWORD *)&p50Distance[8];
        *(_DWORD *)(v104 + 60) = HIDWORD(v136);
        *(_DWORD *)(v104 + 64) = 0;
        *(_DWORD *)(v104 + 72) = 0;
        *(float *)(v104 + 76) = v139;
        v106 = v140;
        *(_DWORD *)(v104 + 68) = v105;
        *(float *)(v104 + 80) = v106;
      }
      ++DWORD1(vColor);
    }
    while ( SDWORD1(vColor) < SLODWORD(vUp.y) );
    v83 = (void (*)(const char *, ...))_Msg;
  }
  v107 = angVector.y;
  v83(a1: "\nShooting VPLs\n");
  CWorldLighting::ShootVirtualPointLights(
    this: (CWorldLighting *)LODWORD(v107),
    a2: v107,
    nSqrtPointSamples: 32,
    nSqrtSpotSamples: 32,
    nSqrtBounceSamples: 4,
    nBounces: 1,
    kdTree,
    flPushBack: 0.0);
  v83(a1: "\nGridding VPLs\n");
  v108 = _CommandLine();
  v109 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v108 + 32))(
                         a1: v108,
                         a2: "-bouncescale",
                         a3: "12.0");
  *(float *)&light_spots.m_Size = atof(nptr: v109);
  CWorldLighting::GridVPLs(
    this: (CWorldLighting *)LODWORD(v107),
    a2: (int)&vColor + 8,
    a3: SLODWORD(v107),
    a4: (int)v83,
    flGridSize: 300.0,
    flMaxRadius: 400.0,
    flBounceScale: *(float *)&light_spots.m_Size,
    kdTree);
  v83(a1: "\nSetting CanSeeSky flags\n");
  v123 = nullptr;
  v124 = 0;
  v125 = 0;
  memset(&lightEnvList, 0, sizeof(lightEnvList));
  skyCamList.m_Memory.m_pMemory = nullptr;
  skyCamList.m_Memory.m_nAllocationCount = 0;
  CWorldRendererBuilder::GetEntities(
    this: pWorldBuilder,
    pEntityName: "light_environment",
    entityList: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&v123);
  CWorldRendererBuilder::GetEntities(
    this: pWorldBuilder,
    pEntityName: "sky_camera",
    entityList: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&lightEnvList.m_Memory.m_nGrowSize);
  v110 = (int)lightEnvList.m_Memory.m_pMemory <= 0;
  *(_BYTE *)(LODWORD(v107) + 80) = 0;
  if ( !v110 && (int)skyCamList.m_Memory.m_pMemory > 0 )
    *(_BYTE *)(LODWORD(v107) + 80) = 1;
  if ( *(_BYTE *)(LODWORD(v107) + 80) != 0 )
    v83(a1: "Can see sky: Yes\n");
  else
    v83(a1: "Can see sky: No\n");
  v111 = (void *)lightEnvList.m_Memory.m_nGrowSize;
  skyCamList.m_Memory.m_pMemory = nullptr;
  if ( (int)lightEnvList.m_pElements >= 0 )
  {
    if ( lightEnvList.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)lightEnvList.m_Memory.m_nGrowSize);
      v111 = nullptr;
      lightEnvList.m_Memory.m_nGrowSize = 0;
    }
    lightEnvList.m_Size = 0;
  }
  skyCamList.m_Memory.m_nAllocationCount = (int)v111;
  if ( (int)lightEnvList.m_pElements >= 0 )
  {
    if ( v111 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v111);
      lightEnvList.m_Memory.m_nGrowSize = 0;
    }
    lightEnvList.m_Size = 0;
  }
  v112 = v123;
  lightEnvList.m_Memory.m_pMemory = nullptr;
  if ( v125 >= 0 )
  {
    if ( v123 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v123);
      v112 = nullptr;
      v123 = nullptr;
    }
    v124 = 0;
  }
  lightEnvList.m_Memory.m_nAllocationCount = (int)v112;
  if ( v125 >= 0 )
  {
    if ( v112 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v112);
      v123 = nullptr;
    }
    v124 = 0;
  }
  v113 = (char *)pCone;
  light_projected.m_Memory.m_pMemory = nullptr;
  if ( (int)pFarZ >= 0 )
  {
    if ( pCone != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pCone);
      v113 = nullptr;
      pCone = nullptr;
    }
    v148 = 0;
  }
  light_projected.m_Memory.m_nAllocationCount = (int)v113;
  if ( (int)pFarZ >= 0 )
  {
    if ( v113 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v113);
      pCone = nullptr;
    }
    v148 = 0;
  }
  x_low = LODWORD(vAngles.x);
  light_spots.m_Memory.m_pMemory = nullptr;
  if ( vAngles.z >= 0.0 )
  {
    if ( LODWORD(vAngles.x) != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(vAngles.x));
      x_low = 0;
      vAngles.x = 0.0;
    }
    vAngles.y = 0.0;
  }
  light_spots.m_Memory.m_nAllocationCount = x_low;
  if ( vAngles.z >= 0.0 )
  {
    if ( x_low != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)x_low);
      vAngles.x = 0.0;
    }
    vAngles.y = 0.0;
  }
  v115 = (void *)light_projected.m_Memory.m_nGrowSize;
  lights.m_Memory.m_pMemory = nullptr;
  if ( (int)light_projected.m_pElements >= 0 )
  {
    if ( light_projected.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)light_projected.m_Memory.m_nGrowSize);
      v115 = nullptr;
      light_projected.m_Memory.m_nGrowSize = 0;
    }
    light_projected.m_Size = 0;
  }
  lights.m_Memory.m_nAllocationCount = (int)v115;
  if ( (int)light_projected.m_pElements >= 0 )
  {
    if ( v115 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v115);
      light_projected.m_Memory.m_nGrowSize = 0;
    }
    light_projected.m_Size = 0;
  }
  if ( samplerPoint.m_pvDirections != nullptr )
    free(pMem: samplerPoint.m_pvDirections);
  if ( v118.m_pvDirections != nullptr )
    free(pMem: v118.m_pvDirections);
}
