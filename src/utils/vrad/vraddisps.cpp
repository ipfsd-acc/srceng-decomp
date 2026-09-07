// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/vraddisps.cpp
// Functions: 47
// ============================================================

#include "utils\vrad\vraddisps.h"

//------------------------------------------------------------------------------
// Address: 0x10026A90
// Name: public: void CCoreDispSurface::GetNormal(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::GetNormal(CCoreDispSurface *this, Vector *normal)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm3_4
  float v7; // xmm0_4

  v2 = this->m_Points[3].y - this->m_Points[0].y;
  v3 = this->m_Points[3].z - this->m_Points[0].z;
  v4 = this->m_Points[1].y - this->m_Points[0].y;
  v5 = this->m_Points[1].z - this->m_Points[0].z;
  v6 = this->m_Points[1].x - this->m_Points[0].x;
  v7 = this->m_Points[3].x - this->m_Points[0].x;
  normal->x = (float)(v2 * v5) - (float)(v3 * v4);
  normal->y = (float)(v3 * v6) - (float)(v7 * v5);
  normal->z = (float)(v7 * v4) - (float)(v2 * v6);
  VectorNormalize(vec: normal);
}

//------------------------------------------------------------------------------
// Address: 0x10026B20
// Name: class IVRadDispMgr __near * StaticDispMgr(void)
// Source: json
//------------------------------------------------------------------------------
CVRadDispMgr *__cdecl StaticDispMgr()
{
  return &s_DispMgr;
}

//------------------------------------------------------------------------------
// Address: 0x10026B30
// Name: public: virtual bool CVRadDispMgr::ClipRayToDisp(struct DispTested_t __near &,struct Ray_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRadDispMgr::ClipRayToDisp(CVRadDispMgr *this, DispTested_t *dispTested, const Ray_t *ray)
{
  IBSPTreeData *m_pBSPTreeData; // ecx
  CVRadDispMgr::EnumContext_t ctx; // [esp+8h] [ebp-8h] BYREF

  this->StartRayTest(this, a2: dispTested);
  m_pBSPTreeData = this->m_pBSPTreeData;
  ctx.m_pDispTested = dispTested;
  ctx.m_pRay = ray;
  return !m_pBSPTreeData->EnumerateLeavesAlongRay(
            this: m_pBSPTreeData,
            a2: ray,
            a3: &this->m_EnumDispRay,
            a4: (int)&ctx);
}

//------------------------------------------------------------------------------
// Address: 0x10026B70
// Name: public: virtual bool CVRadDispMgr::ClipRayToDispInLeaf(struct DispTested_t __near &,struct Ray_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRadDispMgr::ClipRayToDispInLeaf(
        CVRadDispMgr *this,
        DispTested_t *dispTested,
        const Ray_t *ray,
        int ndxLeaf)
{
  IBSPTreeDataEnumerator *v4; // eax
  CVRadDispMgr::EnumContext_t ctx; // [esp+0h] [ebp-8h] BYREF

  ctx.m_pRay = ray;
  ctx.m_pDispTested = dispTested;
  if ( this == (CVRadDispMgr *)-28 )
    v4 = nullptr;
  else
    v4 = &this->m_EnumDispRay.IBSPTreeDataEnumerator;
  return !this->m_pBSPTreeData->EnumerateElementsInLeaf(this: this->m_pBSPTreeData, a2: ndxLeaf, a3: v4, a4: (int)&ctx);
}

//------------------------------------------------------------------------------
// Address: 0x10026BC0
// Name: public: virtual void CVRadDispMgr::ClipRayToDispInLeaf(struct DispTested_t __near &,struct Ray_t const __near &,int,float __near &,struct dface_t __near * __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::ClipRayToDispInLeaf(
        CVRadDispMgr *this,
        DispTested_t *dispTested,
        const Ray_t *ray,
        int ndxLeaf,
        float *dist,
        dface_t **pFace,
        Vector2D *luxelCoord)
{
  IBSPTreeData *m_pBSPTreeData; // ecx
  dface_t *m_pSurface; // eax
  CBSPDispRayDistanceEnumerator rayTestEnum; // [esp+0h] [ebp-28h] BYREF

  m_pBSPTreeData = this->m_pBSPTreeData;
  rayTestEnum.m_pDispTested = dispTested;
  rayTestEnum.m_pRay = ray;
  rayTestEnum.__vftable = (CBSPDispRayDistanceEnumerator_vtbl *)&CBSPDispRayDistanceEnumerator::`vftable';
  rayTestEnum.m_Distance = 1.0;
  rayTestEnum.m_pSurface = nullptr;
  m_pBSPTreeData->EnumerateElementsInLeaf(this: m_pBSPTreeData, a2: ndxLeaf, a3: &rayTestEnum, a4: 0);
  m_pSurface = rayTestEnum.m_pSurface;
  *dist = rayTestEnum.m_Distance;
  *pFace = m_pSurface;
  if ( m_pSurface != nullptr )
    *luxelCoord = rayTestEnum.m_LuxelCoord;
}

//------------------------------------------------------------------------------
// Address: 0x10026C40
// Name: public: virtual void CVRadDispMgr::ClipRayToDispInLeaf(struct DispTested_t __near &,struct Ray_t const __near &,int,float __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::ClipRayToDispInLeaf(
        CVRadDispMgr *this,
        DispTested_t *dispTested,
        const Ray_t *ray,
        int ndxLeaf,
        float *dist,
        Vector *pNormal)
{
  IBSPTreeData *m_pBSPTreeData; // ecx
  bool v7; // zf
  CBSPDispRayDistanceEnumerator rayTestEnum; // [esp+0h] [ebp-28h] BYREF

  m_pBSPTreeData = this->m_pBSPTreeData;
  rayTestEnum.m_pDispTested = dispTested;
  rayTestEnum.m_pRay = ray;
  rayTestEnum.__vftable = (CBSPDispRayDistanceEnumerator_vtbl *)&CBSPDispRayDistanceEnumerator::`vftable';
  rayTestEnum.m_Distance = 1.0;
  rayTestEnum.m_pSurface = nullptr;
  m_pBSPTreeData->EnumerateElementsInLeaf(this: m_pBSPTreeData, a2: ndxLeaf, a3: &rayTestEnum, a4: 0);
  v7 = rayTestEnum.m_pSurface == nullptr;
  *dist = rayTestEnum.m_Distance;
  if ( !v7 )
    *pNormal = rayTestEnum.m_Normal;
}

//------------------------------------------------------------------------------
// Address: 0x10026CC0
// Name: void AddSampleLightToRadial(class Vector const __near &,class Vector const __near &,struct LightingValue_t __near *,float,class Vector const __near &,class Vector const __near &,struct radial_s __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSampleLightToRadial(
        const Vector *samplePos,
        const Vector *sampleNormal,
        LightingValue_t *pSampleLight,
        float sampleRadius2,
        const Vector *luxelPos,
        const Vector *luxelNormal,
        radial_s *pRadial,
        int ndxRadial,
        bool bBumped,
        bool bNeighborBumped)
{
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  int v17; // ecx
  float v18; // xmm4_4
  float *v19; // ecx
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  int v23; // ecx
  float v24; // xmm1_4
  float *v25; // ecx
  float v26; // xmm2_4
  float v27; // xmm3_4
  int v28; // ecx
  float v29; // xmm1_4
  float *v30; // ecx
  float v31; // xmm2_4
  float v32; // xmm3_4
  int v33; // ecx
  float v34; // xmm4_4
  float *v35; // ecx
  float m_flDirectSunAmount; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  int v40; // ecx
  float v41; // xmm4_4
  float *v42; // ecx
  float v43; // xmm2_4
  float v44; // xmm3_4
  int v45; // ecx
  float v46; // xmm4_4
  float *v47; // ecx
  float v48; // xmm2_4
  float v49; // xmm3_4
  int v50; // ecx
  float v51; // xmm4_4
  float v52; // xmm2_4
  float v53; // xmm3_4
  float *p_x; // eax

  v10 = (float)((float)(sampleNormal->y * luxelNormal->y) + (float)(luxelNormal->x * sampleNormal->x))
      + (float)(sampleNormal->z * luxelNormal->z);
  if ( v10 >= 0.15000001 )
  {
    v11 = samplePos->y - luxelPos->y;
    v12 = fsqrt(
            (float)((float)((float)(samplePos->z - luxelPos->z) * (float)(samplePos->z - luxelPos->z))
                  + (float)(v11 * v11))
          + (float)((float)(samplePos->x - luxelPos->x) * (float)(samplePos->x - luxelPos->x)));
    v13 = 1.0 - (float)((float)(v12 * v12) / sampleRadius2);
    if ( v13 > 0.0 )
    {
      v14 = v13 * v10;
      if ( bBumped )
      {
        y = pSampleLight->m_vecLighting.y;
        z = pSampleLight->m_vecLighting.z;
        v17 = 16 * (ndxRadial + 4104);
        v18 = *(float *)((char *)&pRadial->facenum + v17);
        v19 = (float *)((char *)&pRadial->facenum + v17);
        if ( bNeighborBumped )
        {
          v20 = v19[1];
          *v19 = v18 + (float)(v14 * pSampleLight->m_vecLighting.x);
          v19[1] = v20 + (float)(y * v14);
          v19[2] = v19[2] + (float)(z * v14);
          v19[3] = (float)(pSampleLight->m_flDirectSunAmount * v14) + v19[3];
          v21 = pSampleLight[1].m_vecLighting.y;
          v22 = pSampleLight[1].m_vecLighting.z;
          v23 = 16 * (ndxRadial + 20488);
          *(float *)((char *)&pRadial->facenum + v23) = *(float *)((char *)&pRadial->facenum + v23)
                                                      + (float)(pSampleLight[1].m_vecLighting.x * v14);
          v24 = *(float *)((char *)&pRadial->l.facedist + v23);
          v25 = (float *)((char *)&pRadial->facenum + v23);
          v25[1] = v24 + (float)(v21 * v14);
          v25[2] = v25[2] + (float)(v22 * v14);
          v25[3] = (float)(pSampleLight[1].m_flDirectSunAmount * v14) + v25[3];
          v26 = pSampleLight[2].m_vecLighting.y;
          v27 = pSampleLight[2].m_vecLighting.z;
          v28 = 16 * (ndxRadial + 36872);
          *(float *)((char *)&pRadial->facenum + v28) = *(float *)((char *)&pRadial->facenum + v28)
                                                      + (float)(pSampleLight[2].m_vecLighting.x * v14);
          v29 = *(float *)((char *)&pRadial->l.facedist + v28);
          v30 = (float *)((char *)&pRadial->facenum + v28);
          v30[1] = v29 + (float)(v26 * v14);
          v30[2] = v30[2] + (float)(v27 * v14);
          v30[3] = (float)(pSampleLight[2].m_flDirectSunAmount * v14) + v30[3];
          v31 = pSampleLight[3].m_vecLighting.y;
          v32 = pSampleLight[3].m_vecLighting.z;
          v33 = 16 * (ndxRadial + 53256);
          v34 = *(float *)((char *)&pRadial->facenum + v33);
          v35 = (float *)((char *)&pRadial->facenum + v33);
          *v35 = v34 + (float)(pSampleLight[3].m_vecLighting.x * v14);
          v35[1] = v35[1] + (float)(v31 * v14);
          v35[2] = v35[2] + (float)(v32 * v14);
          m_flDirectSunAmount = pSampleLight[3].m_flDirectSunAmount;
        }
        else
        {
          v14 = v14 * 0.050000001;
          v37 = v19[1];
          *v19 = v18 + (float)(v14 * pSampleLight->m_vecLighting.x);
          v19[1] = v37 + (float)(y * v14);
          v19[2] = v19[2] + (float)(z * v14);
          v19[3] = (float)(pSampleLight->m_flDirectSunAmount * v14) + v19[3];
          v38 = pSampleLight->m_vecLighting.y;
          v39 = pSampleLight->m_vecLighting.z;
          v40 = 16 * (ndxRadial + 20488);
          v41 = *(float *)((char *)&pRadial->facenum + v40);
          v42 = (float *)((char *)&pRadial->facenum + v40);
          *v42 = v41 + (float)(v14 * pSampleLight->m_vecLighting.x);
          v42[1] = v42[1] + (float)(v38 * v14);
          v42[2] = v42[2] + (float)(v39 * v14);
          v42[3] = (float)(pSampleLight->m_flDirectSunAmount * v14) + v42[3];
          v43 = pSampleLight->m_vecLighting.y;
          v44 = pSampleLight->m_vecLighting.z;
          v45 = 16 * (ndxRadial + 36872);
          v46 = *(float *)((char *)&pRadial->facenum + v45);
          v47 = (float *)((char *)&pRadial->facenum + v45);
          *v47 = v46 + (float)(v14 * pSampleLight->m_vecLighting.x);
          v47[1] = v47[1] + (float)(v43 * v14);
          v47[2] = v47[2] + (float)(v44 * v14);
          v47[3] = (float)(pSampleLight->m_flDirectSunAmount * v14) + v47[3];
          v48 = pSampleLight->m_vecLighting.y;
          v49 = pSampleLight->m_vecLighting.z;
          v50 = 16 * (ndxRadial + 53256);
          v51 = *(float *)((char *)&pRadial->facenum + v50);
          v35 = (float *)((char *)&pRadial->facenum + v50);
          *v35 = v51 + (float)(v14 * pSampleLight->m_vecLighting.x);
          v35[1] = v35[1] + (float)(v48 * v14);
          v35[2] = v35[2] + (float)(v49 * v14);
          m_flDirectSunAmount = pSampleLight->m_flDirectSunAmount;
        }
        v35[3] = (float)(m_flDirectSunAmount * v14) + v35[3];
      }
      else
      {
        v52 = pSampleLight->m_vecLighting.y;
        v53 = pSampleLight->m_vecLighting.z;
        p_x = &pRadial->light[0][ndxRadial].m_vecLighting.x;
        *p_x = (float)(v14 * pSampleLight->m_vecLighting.x) + *p_x;
        p_x[1] = p_x[1] + (float)(v52 * v14);
        p_x[2] = p_x[2] + (float)(v53 * v14);
        p_x[3] = (float)(pSampleLight->m_flDirectSunAmount * v14) + p_x[3];
      }
      pRadial->weight[ndxRadial] = v14 + pRadial->weight[ndxRadial];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027120
// Name: public: virtual bool CVRadDispMgr::SampleRadial(int,struct radial_s __near *,class Vector const __near &,int,struct LightingValue_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRadDispMgr::SampleRadial(
        CVRadDispMgr *this,
        int ndxFace,
        radial_s *pRadial,
        const Vector *vPos,
        int ndxLxl,
        LightingValue_t *pLightSample,
        int sampleCount,
        bool bPatch)
{
  int v8; // eax
  int v9; // edx
  LightingValue_t *v10; // ecx
  float v11; // xmm1_4
  int v12; // esi
  float v13; // xmm5_4
  float v14; // xmm2_4
  float *v15; // esi
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  int v19; // esi
  float v20; // xmm5_4
  float v21; // xmm2_4
  float *v22; // esi
  float v23; // xmm0_4
  float v24; // xmm1_4
  LightingValue_t *v25; // ecx
  float v26; // xmm1_4
  int v27; // esi
  float v28; // xmm2_4
  float v29; // xmm5_4
  float *v30; // esi
  LightingValue_t *v31; // ecx
  float v32; // xmm1_4
  int v33; // esi
  float v34; // xmm2_4
  float v35; // xmm5_4
  float *v36; // esi
  LightingValue_t *v37; // ecx
  float v38; // xmm1_4
  int v39; // esi
  float v40; // xmm5_4
  float v41; // xmm2_4
  float *v42; // esi
  float v43; // xmm2_4
  char bGoodSample; // [esp+1h] [ebp-1h]

  v8 = sampleCount;
  v9 = 0;
  bGoodSample = 1;
  if ( sampleCount >= 4 )
  {
    do
    {
      v10 = &pLightSample[v9];
      v10->m_vecLighting.x = 0.0;
      v10->m_vecLighting.y = 0.0;
      v10->m_vecLighting.z = 0.0;
      v10->m_flDirectSunAmount = 0.0;
      v11 = pRadial->weight[ndxLxl];
      if ( v11 <= 0.0 )
      {
        if ( !bPatch && v9 == 0 )
          bGoodSample = 0;
      }
      else
      {
        v12 = 16 * ((v9 << 14) + ndxLxl + 4104);
        v13 = *(float *)((char *)&pRadial->facenum + v12);
        v14 = *(float *)((char *)&pRadial->l.facenormal.x + v12);
        v15 = (float *)((char *)&pRadial->facenum + v12);
        v16 = 1.0 / v11;
        v17 = v15[1] * (float)(1.0 / v11);
        v10->m_vecLighting.x = v10->m_vecLighting.x + (float)(v13 * v16);
        v10->m_vecLighting.y = v17 + v10->m_vecLighting.y;
        v10->m_vecLighting.z = (float)(v14 * v16) + v10->m_vecLighting.z;
        v10->m_flDirectSunAmount = (float)(v15[3] * v16) + v10->m_flDirectSunAmount;
      }
      v10[1].m_vecLighting.x = 0.0;
      v10[1].m_vecLighting.y = 0.0;
      v10[1].m_vecLighting.z = 0.0;
      v10[1].m_flDirectSunAmount = 0.0;
      v18 = pRadial->weight[ndxLxl];
      if ( v18 <= 0.0 )
      {
        if ( !bPatch && v9 == -1 )
          bGoodSample = v9 + 1;
      }
      else
      {
        v19 = 16 * ((v9 << 14) + ndxLxl + 20488);
        v20 = *(float *)((char *)&pRadial->facenum + v19);
        v21 = *(float *)((char *)&pRadial->l.facenormal.x + v19);
        v22 = (float *)((char *)&pRadial->facenum + v19);
        v23 = 1.0 / v18;
        v24 = v22[1] * (float)(1.0 / v18);
        v10[1].m_vecLighting.x = v10[1].m_vecLighting.x + (float)(v20 * v23);
        v10[1].m_vecLighting.y = v24 + v10[1].m_vecLighting.y;
        v10[1].m_vecLighting.z = (float)(v21 * v23) + v10[1].m_vecLighting.z;
        v10[1].m_flDirectSunAmount = (float)(v22[3] * v23) + v10[1].m_flDirectSunAmount;
      }
      v25 = &pLightSample[v9 + 2];
      v25->m_vecLighting.x = 0.0;
      v25->m_vecLighting.y = 0.0;
      v25->m_vecLighting.z = 0.0;
      v25->m_flDirectSunAmount = 0.0;
      v26 = pRadial->weight[ndxLxl];
      if ( v26 <= 0.0 )
      {
        if ( !bPatch && v9 == -2 )
          bGoodSample = 0;
      }
      else
      {
        v27 = 16 * ((v9 << 14) + ndxLxl + 36872);
        v28 = *(float *)((char *)&pRadial->l.facedist + v27);
        v29 = *(float *)((char *)&pRadial->l.facenormal.x + v27);
        v30 = (float *)((char *)&pRadial->facenum + v27);
        v25->m_vecLighting.x = v25->m_vecLighting.x + (float)(*v30 * (float)(1.0 / v26));
        v25->m_vecLighting.y = v25->m_vecLighting.y + (float)(v28 * (float)(1.0 / v26));
        v25->m_vecLighting.z = v25->m_vecLighting.z + (float)(v29 * (float)(1.0 / v26));
        v25->m_flDirectSunAmount = (float)(v30[3] * (float)(1.0 / v26)) + v25->m_flDirectSunAmount;
      }
      v31 = &pLightSample[v9 + 3];
      v31->m_vecLighting.x = 0.0;
      v31->m_vecLighting.y = 0.0;
      v31->m_vecLighting.z = 0.0;
      v31->m_flDirectSunAmount = 0.0;
      v32 = pRadial->weight[ndxLxl];
      if ( v32 <= 0.0 )
      {
        if ( !bPatch && v9 == -3 )
          bGoodSample = 0;
      }
      else
      {
        v33 = 16 * ((v9 << 14) + ndxLxl + 53256);
        v34 = *(float *)((char *)&pRadial->l.facedist + v33);
        v35 = *(float *)((char *)&pRadial->l.facenormal.x + v33);
        v36 = (float *)((char *)&pRadial->facenum + v33);
        v31->m_vecLighting.x = v31->m_vecLighting.x + (float)(*v36 * (float)(1.0 / v32));
        v31->m_vecLighting.y = v31->m_vecLighting.y + (float)(v34 * (float)(1.0 / v32));
        v31->m_vecLighting.z = v31->m_vecLighting.z + (float)(v35 * (float)(1.0 / v32));
        v31->m_flDirectSunAmount = (float)(v36[3] * (float)(1.0 / v32)) + v31->m_flDirectSunAmount;
      }
      v8 = sampleCount;
      v9 += 4;
    }
    while ( v9 < sampleCount - 3 );
  }
  for ( ; v9 < v8; ++v9 )
  {
    v37 = &pLightSample[v9];
    v37->m_vecLighting.x = 0.0;
    v37->m_vecLighting.y = 0.0;
    v37->m_vecLighting.z = 0.0;
    v37->m_flDirectSunAmount = 0.0;
    v38 = pRadial->weight[ndxLxl];
    if ( v38 <= 0.0 )
    {
      if ( !bPatch && v9 == 0 )
        bGoodSample = 0;
    }
    else
    {
      v39 = 16 * ((v9 << 14) + ndxLxl + 4104);
      v40 = *(float *)((char *)&pRadial->facenum + v39);
      v41 = *(float *)((char *)&pRadial->l.facenormal.x + v39);
      v42 = (float *)((char *)&pRadial->facenum + v39);
      v43 = (float)(v41 * (float)(1.0 / v38)) + v37->m_vecLighting.z;
      v37->m_vecLighting.y = (float)(v42[1] * (float)(1.0 / v38)) + v37->m_vecLighting.y;
      v37->m_vecLighting.x = (float)(v40 * (float)(1.0 / v38)) + 0.0;
      v37->m_vecLighting.z = v43;
      v37->m_flDirectSunAmount = (float)(v42[3] * (float)(1.0 / v38)) + v37->m_flDirectSunAmount;
    }
  }
  return bGoodSample;
}

//------------------------------------------------------------------------------
// Address: 0x100274C0
// Name: public: virtual void CVRadDispMgr::StartTimer(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::StartTimer(CVRadDispMgr *this, const char *name)
{
  _Msg(a1: name);
  this->m_Timer.m_Duration.m_Int64 = __rdtsc();
}

//------------------------------------------------------------------------------
// Address: 0x100274F0
// Name: public: virtual bool CBSPDispRayEnumerator::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBSPDispRayEnumerator::EnumerateLeaf(CBSPDispRayEnumerator *this, int ndxLeaf, int context)
{
  return s_DispMgr.m_pBSPTreeData->EnumerateElementsInLeaf(
           this: s_DispMgr.m_pBSPTreeData,
           a2: ndxLeaf,
           a3: &s_DispMgr.m_EnumDispRay.IBSPTreeDataEnumerator,
           a4: context);
}

//------------------------------------------------------------------------------
// Address: 0x10027520
// Name: public: virtual void CVRadDispMgr::StartRayTest(struct DispTested_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::StartRayTest(CVRadDispMgr *this, DispTested_t *dispTested)
{
  int m_Size; // eax
  int *v4; // eax

  m_Size = this->m_DispTrees.m_Size;
  if ( m_Size > 0 )
  {
    if ( dispTested->m_pTested == nullptr )
    {
      v4 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)m_Size >> 30 != 0 ? -1 : 4 * m_Size);
      dispTested->m_pTested = v4;
      memset(dst: (unsigned __int8 *)v4, value: 0, count: 4 * this->m_DispTrees.m_Size);
      dispTested->m_Enum = 0;
    }
    ++dispTested->m_Enum;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027580
// Name: void GetSampleLight(struct facelight_t __near *,int,bool,int,struct LightingValue_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSampleLight(
        facelight_t *pFaceLight,
        int ndxStyle,
        bool bBumped,
        int ndxSample,
        LightingValue_t *pSampleLight)
{
  LightingValue_t *v5; // edx
  double x; // st7
  float *p_x; // edx
  double v8; // st7
  LightingValue_t *v9; // edx
  Vector *p_m_vecLighting; // edx
  double v11; // st7
  LightingValue_t *v12; // edx
  Vector *v13; // edx
  double v14; // st7
  LightingValue_t *v15; // edx

  if ( bBumped )
  {
    v5 = pFaceLight->light[ndxStyle][0];
    x = v5[ndxSample].m_vecLighting.x;
    p_x = &v5[ndxSample].m_vecLighting.x;
    pSampleLight->m_vecLighting.x = x;
    pSampleLight->m_vecLighting.y = p_x[1];
    pSampleLight->m_vecLighting.z = p_x[2];
    v8 = p_x[3];
    v9 = pFaceLight->light[ndxStyle][1];
    pSampleLight->m_flDirectSunAmount = v8;
    p_m_vecLighting = &v9[ndxSample].m_vecLighting;
    pSampleLight[1].m_vecLighting = *p_m_vecLighting;
    v11 = p_m_vecLighting[1].x;
    v12 = pFaceLight->light[ndxStyle][2];
    pSampleLight[1].m_flDirectSunAmount = v11;
    v13 = &v12[ndxSample].m_vecLighting;
    pSampleLight[2].m_vecLighting = *v13;
    v14 = v13[1].x;
    v15 = pFaceLight->light[ndxStyle][3];
    pSampleLight[2].m_flDirectSunAmount = v14;
    pSampleLight[3] = v15[ndxSample];
  }
  else
  {
    *pSampleLight = pFaceLight->light[ndxStyle][0][ndxSample];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027650
// Name: public: virtual void CVRadDispMgr::EndTimer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::EndTimer(CVRadDispMgr *this)
{
  __int64 v1; // rax
  unsigned int v2; // kr00_4
  unsigned __int64 v3; // [esp+Ch] [ebp-Ch] BYREF
  unsigned __int64 *v4; // [esp+14h] [ebp-4h]

  v4 = &v3;
  v3 = __rdtsc();
  HIDWORD(v1) = (v3 - this->m_Timer.m_Duration.m_Int64) >> 32;
  LODWORD(v3) = v3 - LODWORD(this->m_Timer.m_Duration.m_Int64);
  LODWORD(this->m_Timer.m_Duration.m_Int64) = v3;
  v2 = v3;
  v3 = v1 & 0x8000000000000000uLL;
  HIDWORD(this->m_Timer.m_Duration.m_Int64) = HIDWORD(v1);
  _Msg(a1: "Done<%1.4lf sec>\n", (double)__PAIR64__(HIDWORD(v1), v2) * _g_ClockSpeedSecondsMultiplier);
}

//------------------------------------------------------------------------------
// Address: 0x100276D0
// Name: private: void CVRadDispMgr::DispBuilderInit(class CCoreDispInfo __near *,struct dface_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVRadDispMgr::DispBuilderInit(
        CVRadDispMgr *this@<ecx>,
        float a2@<ebp>,
        CCoreDispInfo *pBuilderDisp,
        dface_t *pFace,
        int ndxFace)
{
  ddispinfo_t *v5; // edi
  CCoreDispSurface *p_m_Surf; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  double x; // st7
  dvertex_t *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  double v15; // st7
  dvertex_t *v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  double v20; // st7
  dvertex_t *v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  double v25; // st7
  dvertex_t *v26; // eax
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  texinfo_s *v42; // eax
  float v43; // xmm1_4
  float v44; // xmm2_4
  Vector v45; // [esp+40h] [ebp-30h] BYREF
  Vector vecU; // [esp+4Ch] [ebp-24h] BYREF
  Vector vecV; // [esp+58h] [ebp-18h] BYREF
  Vector vFaceNormal; // [esp+64h] [ebp-Ch]
  float retaddr; // [esp+70h] [ebp+0h]

  vFaceNormal.x = a2;
  vFaceNormal.y = retaddr;
  v5 = &g_dispinfo.m_Memory.m_pMemory[pFace->dispinfo];
  if ( v5 != nullptr )
  {
    p_m_Surf = &pBuilderDisp->m_Surf;
    pBuilderDisp->m_Surf.m_PointCount = 4;
    pBuilderDisp->m_Surf.m_Index = ndxFace;
    pBuilderDisp->m_Surf.m_Contents = v5->contents;
    v7 = dsurfedges[pFace->firstedge];
    if ( v7 >= 0 )
      v8 = dedges[v7].v[0];
    else
      v8 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v7);
    v9 = v8;
    x = dvertexes[v9].point.x;
    v11 = &dvertexes[v9];
    pBuilderDisp->m_Surf.m_Points[0].x = x;
    pBuilderDisp->m_Surf.m_Points[0].y = v11->point.y;
    pBuilderDisp->m_Surf.m_Points[0].z = v11->point.z;
    v12 = dword_11ECD51C[pFace->firstedge];
    if ( v12 >= 0 )
      v13 = dedges[v12].v[0];
    else
      v13 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v12);
    v14 = v13;
    v15 = dvertexes[v14].point.x;
    v16 = &dvertexes[v14];
    pBuilderDisp->m_Surf.m_Points[1].x = v15;
    pBuilderDisp->m_Surf.m_Points[1].y = v16->point.y;
    pBuilderDisp->m_Surf.m_Points[1].z = v16->point.z;
    v17 = dword_11ECD520[pFace->firstedge];
    if ( v17 >= 0 )
      v18 = dedges[v17].v[0];
    else
      v18 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v17);
    v19 = v18;
    v20 = dvertexes[v19].point.x;
    v21 = &dvertexes[v19];
    pBuilderDisp->m_Surf.m_Points[2].x = v20;
    pBuilderDisp->m_Surf.m_Points[2].y = v21->point.y;
    pBuilderDisp->m_Surf.m_Points[2].z = v21->point.z;
    v22 = dword_11ECD524[pFace->firstedge];
    if ( v22 >= 0 )
      v23 = dedges[v22].v[0];
    else
      v23 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v22);
    v24 = v23;
    v25 = dvertexes[v24].point.x;
    v26 = &dvertexes[v24];
    pBuilderDisp->m_Surf.m_Points[3].x = v25;
    pBuilderDisp->m_Surf.m_Points[3].y = v26->point.y;
    pBuilderDisp->m_Surf.m_Points[3].z = v26->point.z;
    v27 = pBuilderDisp->m_Surf.m_Points[3].y - pBuilderDisp->m_Surf.m_Points[0].y;
    v28 = pBuilderDisp->m_Surf.m_Points[3].z - pBuilderDisp->m_Surf.m_Points[0].z;
    v29 = pBuilderDisp->m_Surf.m_Points[1].y - pBuilderDisp->m_Surf.m_Points[0].y;
    v30 = pBuilderDisp->m_Surf.m_Points[1].z - pBuilderDisp->m_Surf.m_Points[0].z;
    v31 = pBuilderDisp->m_Surf.m_Points[3].x - pBuilderDisp->m_Surf.m_Points[0].x;
    v32 = pBuilderDisp->m_Surf.m_Points[1].x - pBuilderDisp->m_Surf.m_Points[0].x;
    vecV.x = (float)(v27 * v30) - (float)(v28 * v29);
    vecV.y = (float)(v28 * v32) - (float)(v31 * v30);
    vecV.z = (float)(v31 * v29) - (float)(v27 * v32);
    VectorNormalize(vec: &vecV);
    v33 = vecV.x;
    y = vecV.y;
    z = vecV.z;
    pBuilderDisp->m_Surf.m_Normals[0].x = vecV.x;
    pBuilderDisp->m_Surf.m_Normals[1].x = v33;
    pBuilderDisp->m_Surf.m_Normals[0].y = y;
    pBuilderDisp->m_Surf.m_Normals[0].z = z;
    pBuilderDisp->m_Surf.m_Normals[1].y = y;
    pBuilderDisp->m_Surf.m_Normals[1].z = z;
    pBuilderDisp->m_Surf.m_Normals[2].x = v33;
    pBuilderDisp->m_Surf.m_Normals[2].y = y;
    pBuilderDisp->m_Surf.m_Normals[2].z = z;
    pBuilderDisp->m_Surf.m_Normals[3].x = v33;
    pBuilderDisp->m_Surf.m_Normals[3].y = y;
    pBuilderDisp->m_Surf.m_Normals[3].z = z;
    pBuilderDisp->m_Surf.m_PointStart = v5->startPosition;
    CCoreDispSurface::FindSurfPointStartIndex(this: p_m_Surf);
    CCoreDispSurface::AdjustSurfPointData(this: p_m_Surf);
    v36 = texinfo.m_Memory.m_pMemory[pFace->texinfo].lightmapVecsLuxelsPerWorldUnits[0][0];
    v37 = texinfo.m_Memory.m_pMemory[pFace->texinfo].lightmapVecsLuxelsPerWorldUnits[0][1];
    v38 = texinfo.m_Memory.m_pMemory[pFace->texinfo].lightmapVecsLuxelsPerWorldUnits[0][2];
    v39 = fsqrt((float)((float)(v37 * v37) + (float)(v38 * v38)) + (float)(v36 * v36));
    v40 = v38;
    v41 = texinfo.m_Memory.m_pMemory[pFace->texinfo].lightmapVecsLuxelsPerWorldUnits[0][0];
    v42 = &texinfo.m_Memory.m_pMemory[pFace->texinfo];
    v45.y = v42->lightmapVecsLuxelsPerWorldUnits[0][1];
    v45.x = v41;
    v45.z = v40;
    v43 = v42->lightmapVecsLuxelsPerWorldUnits[1][2];
    v44 = v42->lightmapVecsLuxelsPerWorldUnits[1][0];
    vecU.y = v42->lightmapVecsLuxelsPerWorldUnits[1][1];
    vecU.x = v44;
    vecU.z = v43;
    CCoreDispSurface::CalcLuxelCoords(
      this: p_m_Surf,
      nLuxels: (int)(float)(1.0 / v39),
      bAdjust: false,
      vecU: &v45,
      vecV: &vecU);
    CCoreDispSurface::SetNeighborData(
      this: p_m_Surf,
      edgeNeighbors: v5->m_EdgeNeighbors,
      cornerNeighbors: v5->m_CornerNeighbors);
    CCoreDispInfo::InitDispInfo(
      this: pBuilderDisp,
      power: v5->power,
      minTess: v5->minTess,
      smoothingAngle: v5->smoothingAngle,
      pVerts: &g_DispVerts.m_Memory.m_pMemory[v5->m_iDispVertStart],
      pTris: &g_DispTris.m_Memory.m_pMemory[v5->m_iDispTriStart],
      nFlags: 0,
      pvMultiBlends: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027A40
// Name: public: virtual void CVRadDispMgr::MakePatches(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::MakePatches(CVRadDispMgr *this)
{
  int m_Size; // ebx
  int v3; // esi
  CVRADDispColl *m_pDispTree; // ecx
  float flTotalArea; // [esp+14h] [ebp-4h]

  m_Size = this->m_DispTrees.m_Size;
  v3 = 0;
  for ( flTotalArea = 0.0; v3 < m_Size; ++v3 )
  {
    m_pDispTree = this->m_DispTrees.m_Memory.m_pMemory[v3].m_pDispTree;
    if ( m_pDispTree != nullptr )
      flTotalArea = CVRADDispColl::CreateParentPatches(this: m_pDispTree) + flTotalArea;
  }
  qprintf(format: "%i Displacements\n", m_Size);
  qprintf(format: "%i Square Feet [%.2f Square Inches]\n", (int)(float)(flTotalArea * 0.0069444445), flTotalArea);
}

//------------------------------------------------------------------------------
// Address: 0x10027AC0
// Name: public: virtual void CVRadDispMgr::SubdividePatch(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::SubdividePatch(CVRadDispMgr *this, int iPatch)
{
  CPatch *v2; // eax
  CVRADDispColl *m_pDispTree; // ecx
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  v2 = &g_Patches.m_Memory.m_pMemory[iPatch];
  if ( v2 != nullptr )
  {
    m_pDispTree = this->m_DispTrees.m_Memory.m_pMemory[g_pFaces[v2->faceNumber].dispinfo].m_pDispTree;
    if ( m_pDispTree != nullptr )
      CVRADDispColl::CreateChildPatches(this: m_pDispTree, a2: (int)&savedregs, iParentPatch: iPatch, nLevel: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027B10
// Name: public: virtual void CVRadDispMgr::AddPolysForRayTrace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::AddPolysForRayTrace(CVRadDispMgr *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_DispTrees.m_Size;
  for ( i = 0; i < m_Size; ++i )
    CVRADDispColl::AddPolysForRayTrace(this: this->m_DispTrees.m_Memory.m_pMemory[i].m_pDispTree);
}

//------------------------------------------------------------------------------
// Address: 0x10027B40
// Name: public: virtual void CVRadDispMgr::GetDispSurfNormal(int,class Vector __near &,class Vector __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::GetDispSurfNormal(
        CVRadDispMgr *this,
        int ndxFace,
        Vector *pt,
        Vector *ptNormal,
        bool bInside)
{
  CVRADDispColl *m_pDispTree; // esi
  float x; // xmm1_4
  float y; // xmm0_4
  Vector2D uv; // [esp+14h] [ebp-8h] BYREF

  m_pDispTree = this->m_DispTrees.m_Memory.m_pMemory[g_pFaces[ndxFace].dispinfo].m_pDispTree;
  CVRADDispColl::BaseFacePlaneToDispUV(this: m_pDispTree, vecPlanePt: pt, dispUV: &uv);
  x = uv.x;
  if ( !bInside )
    goto LABEL_8;
  if ( uv.x < 0.0 || uv.x > 1.0 )
  {
    _Msg(a1: "Disp UV (%f) outside bounds!\n", uv.x);
    x = uv.x;
  }
  y = uv.y;
  if ( uv.y < 0.0 || uv.y > 1.0 )
  {
    _Msg(a1: "Disp UV (%f) outside bounds!\n", uv.y);
    x = uv.x;
LABEL_8:
    y = uv.y;
  }
  if ( x >= 0.0 )
  {
    if ( x > 1.0 )
      uv.x = 1.0;
  }
  else
  {
    uv.x = 0.0;
  }
  if ( y >= 0.0 )
  {
    if ( y > 1.0 )
      uv.y = 1.0;
  }
  else
  {
    uv.y = 0.0;
  }
  CVRADDispColl::DispUVToSurfNormal(this: m_pDispTree, dispUV: &uv, vecNormal: ptNormal);
  CVRADDispColl::DispUVToSurfPoint(this: m_pDispTree, dispUV: &uv, vecPoint: pt, flPushEps: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10027C60
// Name: public: virtual void CVRadDispMgr::GetDispSurf(int,class CVRADDispColl __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::GetDispSurf(CVRadDispMgr *this, int ndxFace, CVRADDispColl **ppDispTree)
{
  *ppDispTree = this->m_DispTrees.m_Memory.m_pMemory[g_pFaces[ndxFace].dispinfo].m_pDispTree;
}

//------------------------------------------------------------------------------
// Address: 0x10027C90
// Name: public: bool CVRadDispMgr::DispRay_EnumerateElement(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRadDispMgr::DispRay_EnumerateElement(CVRadDispMgr *this, int userId, int context)
{
  CVRadDispMgr::DispCollTree_t *m_pMemory; // eax
  const Ray_t *v5; // ecx
  float x; // xmm1_4
  float y; // xmm1_4
  float z; // xmm1_4
  CBaseTrace trace; // [esp+8h] [ebp-44h] BYREF
  Vector vecInvDelta; // [esp+40h] [ebp-Ch] BYREF

  m_pMemory = this->m_DispTrees.m_Memory.m_pMemory;
  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)context + 4) + 4 * userId) == **(_DWORD **)context )
    return true;
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)context + 4) + 4 * userId) = **(_DWORD **)context;
  v5 = *(const Ray_t **)(context + 4);
  trace.fraction = 1.0;
  x = v5->m_Delta.x;
  if ( x == 0.0 )
    vecInvDelta.x = 3.4028235e38;
  else
    vecInvDelta.x = 1.0 / x;
  y = v5->m_Delta.y;
  if ( y == 0.0 )
    vecInvDelta.y = 3.4028235e38;
  else
    vecInvDelta.y = 1.0 / y;
  z = v5->m_Delta.z;
  if ( z == 0.0 )
    vecInvDelta.z = 3.4028235e38;
  else
    vecInvDelta.z = 1.0 / z;
  return CDispCollTree::AABBTree_Ray(
           this: m_pMemory[userId].m_pDispTree,
           ray: v5,
           &vecInvDelta,
           pTrace: &trace,
           bSide: true) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10027D60
// Name: public: bool CVRadDispMgr::DispRayDistance_EnumerateElement(int,class CBSPDispRayDistanceEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRadDispMgr::DispRayDistance_EnumerateElement(
        CVRadDispMgr *this,
        int userId,
        CBSPDispRayDistanceEnumerator *pCtx)
{
  CVRadDispMgr::DispCollTree_t *v3; // edi
  DispTested_t *m_pDispTested; // eax
  const Ray_t *m_pRay; // eax
  float v; // xmm0_4
  Vector *m_pMemory; // eax
  float *p_x; // ecx
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  RayDispOutput_t output; // [esp+14h] [ebp-20h] BYREF
  Vector e0; // [esp+28h] [ebp-Ch]

  v3 = &this->m_DispTrees.m_Memory.m_pMemory[userId];
  m_pDispTested = pCtx->m_pDispTested;
  if ( m_pDispTested->m_pTested[userId] != m_pDispTested->m_Enum )
  {
    m_pDispTested->m_pTested[userId] = m_pDispTested->m_Enum;
    output.ndxVerts[1] = -1;
    output.ndxVerts[0] = -1;
    output.ndxVerts[2] = -1;
    m_pRay = pCtx->m_pRay;
    output.u = -1.0;
    output.v = -1.0;
    output.ndxVerts[3] = -1;
    output.dist = 3.4028235e38;
    if ( CDispCollTree::AABBTree_Ray(this: v3->m_pDispTree, ray: m_pRay, &output) != 0 && pCtx->m_Distance > output.dist )
    {
      pCtx->m_Distance = output.dist;
      v = output.v;
      pCtx->m_pSurface = &g_pFaces[v3->m_pDispTree->m_iParent];
      ComputePointFromBarycentric(
        v0: &v3->m_pDispTree->m_aLuxelCoords.m_Memory.m_pMemory[output.ndxVerts[0]],
        v1: &v3->m_pDispTree->m_aLuxelCoords.m_Memory.m_pMemory[output.ndxVerts[1]],
        v2: &v3->m_pDispTree->m_aLuxelCoords.m_Memory.m_pMemory[output.ndxVerts[2]],
        u: output.u,
        v,
        pt: &pCtx->m_LuxelCoord);
      m_pMemory = v3->m_pDispTree->m_aVerts.m_Memory.m_pMemory;
      p_x = &m_pMemory[output.ndxVerts[0]].x;
      v9 = m_pMemory[output.ndxVerts[1]].z - p_x[2];
      v10 = m_pMemory[output.ndxVerts[1]].y - p_x[1];
      v11 = m_pMemory[output.ndxVerts[2]].y - p_x[1];
      v12 = m_pMemory[output.ndxVerts[2]].z - p_x[2];
      v13 = m_pMemory[output.ndxVerts[2]].x - *p_x;
      e0.x = m_pMemory[output.ndxVerts[1]].x - *p_x;
      v14 = (float)(v12 * v10) - (float)(v11 * v9);
      v15 = (float)(v9 * v13) - (float)(v12 * e0.x);
      v16 = (float)(v11 * e0.x) - (float)(v10 * v13);
      pCtx->m_Normal.x = v14;
      pCtx->m_Normal.y = v15;
      pCtx->m_Normal.z = v16;
      VectorNormalize(vec: &pCtx->m_Normal);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027F10
// Name: void AddPatchLightToRadial(class Vector const __near &,class Vector const __near &,class Vector __near *,float,class Vector const __near &,class Vector const __near &,struct radial_s __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall AddPatchLightToRadial(
        float a1@<ebp>,
        const Vector *patchOrigin,
        const Vector *patchNormal,
        Vector *pPatchLight,
        float patchRadius2,
        const Vector *luxelPos,
        const Vector *luxelNormal,
        radial_s *pRadial,
        int ndxRadial,
        bool bBump,
        bool bNeighborBump)
{
  float v11; // xmm1_4
  float v12; // xmm2_4
  __int128 v13; // xmm0
  float v14; // xmm1_4
  int facenum; // eax
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // edx
  int v19; // ecx
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float *v23; // ecx
  float v24; // xmm3_4
  float y; // xmm1_4
  float z; // xmm2_4
  int v27; // ecx
  float v28; // xmm4_4
  float *v29; // ecx
  float v30; // xmm1_4
  float v31; // xmm2_4
  int v32; // ecx
  float v33; // xmm4_4
  float *v34; // ecx
  float v35; // xmm1_4
  float v36; // xmm2_4
  int v37; // ecx
  float v38; // xmm4_4
  float *v39; // ecx
  float v40; // xmm3_4
  int v41; // ecx
  float v42; // xmm4_4
  float *v43; // ecx
  float v44; // xmm2_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm3_4
  int v48; // ecx
  float v49; // xmm4_4
  float *v50; // ecx
  float v51; // xmm2_4
  float v52; // xmm3_4
  int v53; // ecx
  float v54; // xmm4_4
  float *v55; // ecx
  float v56; // xmm2_4
  float v57; // xmm3_4
  int v58; // ecx
  float v59; // xmm4_4
  float *v60; // ecx
  float v61; // xmm0_4
  float v62; // xmm0_4
  int v63; // eax
  float v64; // xmm4_4
  float *v65; // eax
  float v66; // xmm1_4
  float v67; // xmm2_4
  Vector v68; // [esp-Ch] [ebp-5Ch] BYREF
  _BYTE normals[52]; // [esp+0h] [ebp-50h] OVERLAPPED BYREF
  Vector vecTexU; // [esp+34h] [ebp-1Ch] BYREF
  Vector vecTexV; // [esp+40h] [ebp-10h]
  float retaddr; // [esp+50h] [ebp+0h]

  vecTexV.y = a1;
  vecTexV.z = retaddr;
  v11 = patchOrigin->y - luxelPos->y;
  v12 = patchOrigin->z - luxelPos->z;
  v13 = 0;
  *(float *)&v13 = fsqrt(
                     (float)((float)(v12 * v12) + (float)(v11 * v11))
                   + (float)((float)(patchOrigin->x - luxelPos->x) * (float)(patchOrigin->x - luxelPos->x)));
  *(_OWORD *)&normals[36] = v13;
  v14 = 1.0 - (float)((float)(*(float *)&v13 * *(float *)&v13) / patchRadius2);
  vecTexV.x = v14;
  if ( v14 > 0.0 )
  {
    if ( bBump )
    {
      v68.x = luxelNormal->x;
      v68.y = luxelNormal->y;
      facenum = pRadial->facenum;
      v68.z = luxelNormal->z;
      PreGetBumpNormalsForDisp(
        pTexinfo: &texinfo.m_Memory.m_pMemory[g_pFaces[facenum].texinfo],
        vecU: (Vector *)&normals[40],
        vecV: &vecTexU,
        vecNormal: &v68);
      GetBumpNormals(
        sVect: (const Vector *)&normals[40],
        tVect: &vecTexU,
        flatNormal: &v68,
        phongNormal: &v68,
        bumpNormals: (Vector *)normals);
      v16 = (float)((float)(patchNormal->y * v68.y) + (float)(patchNormal->x * v68.x)) + (float)(patchNormal->z * v68.z);
      if ( bNeighborBump )
      {
        if ( v16 < 0.0 )
          v16 = 0.0;
        v17 = v16 * vecTexV.x;
        v18 = ndxRadial;
        v19 = 16 * (ndxRadial + 4104);
        v20 = (float)(pPatchLight->y * v17) + *(float *)((char *)&pRadial->l.facedist + v19);
        v21 = (float)(pPatchLight->z * v17) + *(float *)((char *)&pRadial->l.facenormal.x + v19);
        v22 = *(float *)((char *)&pRadial->facenum + v19);
        v23 = (float *)((char *)&pRadial->facenum + v19);
        v24 = v17 * pPatchLight->x;
        v23[1] = v20;
        v23[2] = v21;
        *v23 = v22 + v24;
        y = pPatchLight[1].y;
        z = pPatchLight[1].z;
        v27 = 16 * (ndxRadial + 20488);
        v28 = *(float *)((char *)&pRadial->facenum + v27);
        v29 = (float *)((char *)&pRadial->facenum + v27);
        *v29 = v28 + (float)(pPatchLight[1].x * v17);
        v29[1] = (float)(y * v17) + v29[1];
        v29[2] = (float)(z * v17) + v29[2];
        v30 = pPatchLight[2].y;
        v31 = pPatchLight[2].z;
        v32 = 16 * (ndxRadial + 36872);
        v33 = *(float *)((char *)&pRadial->facenum + v32);
        v34 = (float *)((char *)&pRadial->facenum + v32);
        *v34 = v33 + (float)(pPatchLight[2].x * v17);
        v34[1] = (float)(v30 * v17) + v34[1];
        v34[2] = (float)(v31 * v17) + v34[2];
        v35 = pPatchLight[3].y;
        v36 = pPatchLight[3].z;
        v37 = 16 * (ndxRadial + 53256);
        v38 = *(float *)((char *)&pRadial->facenum + v37);
        v39 = (float *)((char *)&pRadial->facenum + v37);
        *v39 = v38 + (float)(pPatchLight[3].x * v17);
        v39[1] = (float)(v35 * v17) + v39[1];
        v39[2] = (float)(v36 * v17) + v39[2];
      }
      else
      {
        if ( v16 < 0.0 )
          v16 = 0.0;
        v18 = ndxRadial;
        v40 = pPatchLight->z;
        v17 = (float)(v16 * vecTexV.x) * 0.050000001;
        v41 = 16 * (ndxRadial + 4104);
        v42 = *(float *)((char *)&pRadial->facenum + v41);
        v43 = (float *)((char *)&pRadial->facenum + v41);
        v44 = pPatchLight->y * v17;
        v45 = v43[1];
        *v43 = v42 + (float)(v17 * pPatchLight->x);
        v43[1] = v45 + v44;
        v43[2] = v43[2] + (float)(v40 * v17);
        v46 = pPatchLight->y;
        v47 = pPatchLight->z;
        v48 = 16 * (ndxRadial + 20488);
        v49 = *(float *)((char *)&pRadial->facenum + v48);
        v50 = (float *)((char *)&pRadial->facenum + v48);
        *v50 = v49 + (float)(v17 * pPatchLight->x);
        v50[1] = v50[1] + (float)(v46 * v17);
        v50[2] = v50[2] + (float)(v47 * v17);
        v51 = pPatchLight->y;
        v52 = pPatchLight->z;
        v53 = 16 * (ndxRadial + 36872);
        v54 = *(float *)((char *)&pRadial->facenum + v53);
        v55 = (float *)((char *)&pRadial->facenum + v53);
        *v55 = v54 + (float)(v17 * pPatchLight->x);
        v55[1] = v55[1] + (float)(v51 * v17);
        v55[2] = v55[2] + (float)(v52 * v17);
        v56 = pPatchLight->y;
        v57 = pPatchLight->z;
        v58 = 16 * (ndxRadial + 53256);
        v59 = *(float *)((char *)&pRadial->facenum + v58);
        v60 = (float *)((char *)&pRadial->facenum + v58);
        *v60 = v59 + (float)(v17 * pPatchLight->x);
        v60[1] = v60[1] + (float)(v56 * v17);
        v60[2] = v60[2] + (float)(v57 * v17);
      }
      pRadial->weight[v18] = v17 + pRadial->weight[v18];
    }
    else
    {
      v61 = (float)((float)(patchNormal->y * luxelNormal->y) + (float)(luxelNormal->x * patchNormal->x))
          + (float)(patchNormal->z * luxelNormal->z);
      if ( v61 < 0.0 )
        v61 = 0.0;
      v62 = v61 * v14;
      v63 = 16 * (ndxRadial + 4104);
      v64 = *(float *)((char *)&pRadial->facenum + v63);
      v65 = (float *)((char *)&pRadial->facenum + v63);
      v66 = (float)(pPatchLight->y * v62) + v65[1];
      v67 = (float)(pPatchLight->z * v62) + v65[2];
      *v65 = v64 + (float)(v62 * pPatchLight->x);
      v65[1] = v66;
      v65[2] = v67;
      pRadial->weight[ndxRadial] = v62 + pRadial->weight[ndxRadial];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028390
// Name: private: void CVRadDispMgr::RadialLuxelAddPatch(int,class Vector const __near &,class Vector const __near &,float,struct radial_s __near *,int,bool,class CUtlVector<struct CPatch __near *,class CUtlMemory<struct CPatch __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::RadialLuxelAddPatch(
        CVRadDispMgr *this,
        int ndxFace,
        const Vector *luxelPt,
        const Vector *luxelNormal,
        float radius,
        radial_s *pRadial,
        int ndxRadial,
        bool bBump,
        CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *interestingPatches)
{
  int v9; // esi
  float patchRadius2; // xmm0_4
  CPatch *v11; // eax
  unsigned int v12; // edx
  Vector patchLight[4]; // [esp+24h] [ebp-30h] BYREF
  int savedregs; // [esp+54h] [ebp+0h] BYREF

  v9 = 0;
  if ( interestingPatches->m_Size > 0 )
  {
    for ( patchRadius2 = radius * radius; ; patchRadius2 = radius * radius )
    {
      v11 = interestingPatches->m_Memory.m_pMemory[v9];
      v12 = (unsigned int)texinfo.m_Memory.m_pMemory[g_pFaces[v11->faceNumber].texinfo].flags >> 11;
      patchLight[0] = v11->totallight.light[0];
      if ( bBump )
      {
        patchLight[1] = v11->totallight.light[1];
        patchLight[2] = v11->totallight.light[2];
        patchLight[3] = v11->totallight.light[3];
      }
      AddPatchLightToRadial(
        a1: COERCE_FLOAT(&savedregs),
        patchOrigin: &v11->origin,
        patchNormal: &v11->normal,
        pPatchLight: patchLight,
        patchRadius2,
        luxelPos: luxelPt,
        luxelNormal,
        pRadial,
        ndxRadial,
        bBump,
        bNeighborBump: v12 & 1);
      if ( ++v9 >= interestingPatches->m_Size )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100284D0
// Name: public: virtual void CVRadDispMgr::InsertSamplesDataIntoHashTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::InsertSamplesDataIntoHashTable(CVRadDispMgr *this)
{
  int v1; // ecx
  int v2; // eax
  facelight_t *v3; // edi
  char *v4; // eax
  int v5; // esi
  int v6; // ebx
  sample_t *v7; // eax
  int v8; // [esp+0h] [ebp-8h]
  int ndxFace; // [esp+4h] [ebp-4h]

  v1 = 0;
  ndxFace = 0;
  if ( (int)numfaces > 0 )
  {
    v2 = 0;
    v8 = 0;
    v3 = facelight;
    do
    {
      v4 = (char *)g_pFaces + v2;
      if ( v4 != nullptr && v3 != nullptr && (texinfo.m_Memory.m_pMemory[*((__int16 *)v4 + 5)].flags & 0x404) == 0 )
      {
        v5 = 0;
        if ( v3->numsamples > 0 )
        {
          v6 = 0;
          do
          {
            v7 = &v3->sample[v6];
            if ( v7 != nullptr )
            {
              SampleData_AddSample(pSample: v7, sampleHandle: v5 | (v1 << 16));
              v1 = ndxFace;
            }
            ++v5;
            ++v6;
          }
          while ( v5 < v3->numsamples );
        }
      }
      ++v1;
      v2 = v8 + 56;
      ++v3;
      ndxFace = v1;
      v8 += 56;
    }
    while ( v1 < (int)numfaces );
  }
  SampleData_Log();
}

//------------------------------------------------------------------------------
// Address: 0x10028570
// Name: public: virtual void CVRadDispMgr::InsertPatchSampleDataIntoHashTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::InsertPatchSampleDataIntoHashTable(CVRadDispMgr *this)
{
  int v1; // ebx
  int v2; // eax
  CPatch *m_pMemory; // edi
  char *v4; // eax
  int v5; // ecx
  CPatch *v6; // ecx
  int ndxNext; // eax
  CPatch *v8; // esi
  int v9; // [esp+0h] [ebp-8h]
  facelight_t *v10; // [esp+4h] [ebp-4h]

  if ( numbounce != 0 )
  {
    v1 = 0;
    if ( (int)numfaces > 0 )
    {
      v2 = 0;
      m_pMemory = g_Patches.m_Memory.m_pMemory;
      v9 = 0;
      v10 = facelight;
      do
      {
        v4 = (char *)g_pFaces + v2;
        if ( v4 != nullptr && v10 != nullptr && (texinfo.m_Memory.m_pMemory[*((__int16 *)v4 + 5)].flags & 0x404) == 0 )
        {
          v5 = g_FacePatches.m_Memory.m_pMemory[v1];
          if ( v5 != -1 )
          {
            v6 = &m_pMemory[v5];
            if ( v6 != nullptr )
            {
              do
              {
                ndxNext = v6->ndxNext;
                v8 = nullptr;
                if ( ndxNext != -1 )
                  v8 = &m_pMemory[ndxNext];
                if ( v6->child1 == -1 )
                {
                  PatchSampleData_AddSample(pPatch: v6, ndxPatch: v6 - m_pMemory);
                  m_pMemory = g_Patches.m_Memory.m_pMemory;
                }
                v6 = v8;
              }
              while ( v8 != nullptr );
            }
          }
        }
        ++v10;
        ++v1;
        v2 = v9 + 56;
        v9 += 56;
      }
      while ( v1 < (int)numfaces );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028660
// Name: public: virtual bool CVRadDispMgr::BuildDispSamples(struct lightinfo_t __near *,struct facelight_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRadDispMgr::BuildDispSamples(
        CVRadDispMgr *this,
        lightinfo_t *pLightInfo,
        facelight_t *pFaceLight,
        int ndxFace)
{
  dface_t *face; // eax
  int v6; // edi
  int v7; // esi
  int v8; // ebx
  int v9; // eax
  int v10; // edx
  int v11; // edi
  Vector *v12; // esi
  float v13; // xmm0_4
  int v14; // edi
  winding_t *v15; // eax
  winding_t *v16; // esi
  char *v17; // ecx
  int v18; // edx
  char *v19; // edx
  float *v20; // eax
  float *p_x; // ecx
  double v22; // st7
  float *v23; // ecx
  float *v24; // edx
  float *v25; // edx
  float *v26; // ecx
  double v27; // st7
  unsigned __int8 *v28; // ecx
  int v29; // eax
  int v30; // eax
  Vector *v31; // ecx
  int v32; // edi
  float v33; // esi
  float v34; // xmm0_4
  CVRADDispColl *v35; // ecx
  int v36; // esi
  unsigned __int8 *v37; // eax
  unsigned __int8 *v38; // esi
  unsigned int flPushEps; // [esp+0h] [ebp-29E38h]
  char v40; // [esp+10h] [ebp-29E28h] BYREF
  char v41; // [esp+26490h] [ebp-39A8h] BYREF
  Vector2D dispUV; // [esp+29DFCh] [ebp-3Ch] BYREF
  float v43; // [esp+29E04h] [ebp-34h]
  float v44; // [esp+29E08h] [ebp-30h]
  float v45; // [esp+29E0Ch] [ebp-2Ch]
  float v46; // [esp+29E10h] [ebp-28h]
  int v47; // [esp+29E14h] [ebp-24h]
  CVRADDispColl *m_pDispTree; // [esp+29E18h] [ebp-20h]
  unsigned __int8 *src; // [esp+29E1Ch] [ebp-1Ch]
  void *pMem; // [esp+29E20h] [ebp-18h]
  int v51; // [esp+29E24h] [ebp-14h]
  int v52; // [esp+29E28h] [ebp-10h]
  Vector *vecPoint; // [esp+29E2Ch] [ebp-Ch]
  float i; // [esp+29E30h] [ebp-8h]
  int v55; // [esp+29E34h] [ebp-4h]
  bool v56; // [esp+29E4Bh] [ebp+13h]

  m_pDispTree = this->m_DispTrees.m_Memory.m_pMemory[g_pFaces[ndxFace].dispinfo].m_pDispTree;
  if ( m_pDispTree == nullptr )
    return 0;
  face = pLightInfo->face;
  v6 = face->m_LightmapTextureSizeInLuxels[0] + 1;
  v7 = face->m_LightmapTextureSizeInLuxels[1] + 1;
  v8 = face->m_LightmapTextureSizeInLuxels[0] + 2;
  v46 = 1.0 / (float)v7;
  v52 = v6;
  v47 = v7;
  v45 = 1.0 / (float)v6;
  v43 = v45 * 0.5;
  v44 = v46 * 0.5;
  v56 = (v7 + 1) * v8 > 1225;
  pMem = &v41;
  src = (unsigned __int8 *)&v40;
  if ( (v7 + 1) * v8 > 1225 )
  {
    pMem = MemAlloc_Alloc(nSize: 0x30000u);
    src = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x100000u);
  }
  v9 = 0;
  v55 = 0;
  if ( v7 + 1 > 0 )
  {
    v10 = 12 * v8;
    v51 = 12 * v8;
    vecPoint = (Vector *)pMem;
    do
    {
      v11 = 0;
      if ( v8 > 0 )
      {
        v12 = vecPoint;
        v13 = (float)v9 * v46;
        for ( i = v13; ; v13 = i )
        {
          dispUV.y = v13;
          dispUV.x = (float)v11 * v45;
          CVRADDispColl::DispUVToSurfPoint(this: m_pDispTree, &dispUV, vecPoint: v12, flPushEps: 0.0);
          ++v11;
          ++v12;
          if ( v11 >= v8 )
            break;
        }
        v7 = v47;
        v10 = v51;
        v9 = v55;
      }
      vecPoint = (Vector *)((char *)vecPoint + v10);
      v55 = ++v9;
    }
    while ( v9 < v7 + 1 );
    v6 = v52;
  }
  v55 = 0;
  if ( v7 > 0 )
  {
    i = 0.0;
    v51 = 12;
    do
    {
      v14 = 0;
      if ( v52 > 0 )
      {
        vecPoint = nullptr;
        do
        {
          v15 = AllocWinding(points: 4);
          v16 = v15;
          if ( v15 != nullptr )
          {
            v17 = (char *)pMem;
            v18 = v51;
            v15->numpoints = 4;
            v19 = (char *)vecPoint + v8 * v18;
            v20 = (float *)&v17[12 * v14 + 12 * v55 * v8];
            p_x = &v16->p->x;
            *p_x = *v20;
            p_x[1] = v20[1];
            p_x[2] = v20[2];
            v22 = *(float *)&v19[(_DWORD)pMem];
            v23 = (float *)((char *)pMem + (_DWORD)v19);
            v24 = &v16->p->x;
            v24[3] = v22;
            v24[4] = v23[1];
            v24[5] = v23[2];
            v25 = &v16->p->x;
            v25[6] = v23[3];
            v25[7] = v23[4];
            v25[8] = v23[5];
            v26 = &v16->p->x;
            v26[9] = v20[3];
            v26[10] = v20[4];
            v26[11] = v20[5];
            v27 = WindingArea(w: v16);
            v28 = src;
            v29 = (LODWORD(i) + v14) << 6;
            *(float *)&src[v29 + 60] = v27;
            *(_DWORD *)&v28[v29] = v16;
          }
          else
          {
            _Msg(a1: "BuildDispSamples: WARNING - failed winding allocation\n");
          }
          ++vecPoint;
          ++v14;
        }
        while ( v14 < v52 );
        v7 = v47;
      }
      v51 += 12;
      LODWORD(i) += v52;
      ++v55;
    }
    while ( v55 < v7 );
    v6 = v52;
  }
  v30 = 0;
  v55 = 0;
  if ( v7 > 0 )
  {
    v31 = (Vector *)(v6 << 6);
    vecPoint = (Vector *)(v6 << 6);
    LODWORD(i) = src + 8;
    do
    {
      v32 = 0;
      if ( v52 > 0 )
      {
        v33 = i;
        v34 = (float)((float)v30 * v46) + v44;
        for ( *(float *)&v51 = v34; ; v34 = *(float *)&v51 )
        {
          *(_DWORD *)LODWORD(v33) = v30;
          v35 = m_pDispTree;
          *(_DWORD *)(LODWORD(v33) - 4) = v32;
          *(float *)(LODWORD(v33) + 8) = v34;
          *(float *)(LODWORD(v33) + 4) = (float)((float)v32 * v45) + v43;
          CVRADDispColl::DispUVToSurfPoint(
            this: v35,
            dispUV: (const Vector2D *)(LODWORD(v33) + 4),
            vecPoint: (Vector *)(LODWORD(v33) + 28),
            flPushEps: 1.0);
          CVRADDispColl::DispUVToSurfNormal(
            this: m_pDispTree,
            dispUV: (const Vector2D *)(LODWORD(v33) + 4),
            vecNormal: (Vector *)(LODWORD(v33) + 40));
          v30 = v55;
          ++v32;
          LODWORD(v33) += 64;
          if ( v32 >= v52 )
            break;
        }
        v31 = vecPoint;
        v7 = v47;
      }
      LODWORD(i) += v31;
      v55 = ++v30;
    }
    while ( v30 < v7 );
    v6 = v52;
  }
  v36 = v6 * v7;
  pFaceLight->numsamples = v36;
  v37 = calloc(count: v36, size: 0x40u);
  pFaceLight->sample = (sample_t *)v37;
  if ( v37 != nullptr )
  {
    flPushEps = v36 << 6;
    v38 = src;
    memcpy(dst: v37, src, count: flPushEps);
    if ( pFaceLight->numsamples == 0 )
      _Msg(a1: "BuildDispSamples: WARNING - no samples %d\n", pLightInfo->face - g_pFaces);
    if ( v56 )
    {
      free(pMem);
      free(pMem: v38);
    }
    return 1;
  }
  else
  {
    if ( v56 )
    {
      free(pMem);
      free(pMem: src);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028A40
// Name: public: virtual bool CVRadDispMgr::BuildDispLuxels(struct lightinfo_t __near *,struct facelight_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRadDispMgr::BuildDispLuxels(
        CVRadDispMgr *this,
        lightinfo_t *pLightInfo,
        facelight_t *pFaceLight,
        int ndxFace)
{
  dface_t *face; // eax
  int v6; // esi
  int v7; // ebx
  unsigned __int8 *v8; // eax
  int v9; // eax
  float v10; // xmm1_4
  int v11; // ecx
  int v12; // edi
  int v13; // esi
  float v14; // xmm0_4
  Vector *luxel; // eax
  Vector2D uv; // [esp+10h] [ebp-20h] BYREF
  int v17; // [esp+18h] [ebp-18h]
  int height; // [esp+1Ch] [ebp-14h]
  float stepV; // [esp+20h] [ebp-10h]
  float stepU; // [esp+24h] [ebp-Ch]
  float i; // [esp+28h] [ebp-8h]
  CVRADDispColl *pDispTree; // [esp+2Ch] [ebp-4h]
  int ndxV; // [esp+38h] [ebp+8h]
  unsigned __int8 *ndxFaceb; // [esp+40h] [ebp+10h]
  int ndxFacea; // [esp+40h] [ebp+10h]

  pDispTree = this->m_DispTrees.m_Memory.m_pMemory[g_pFaces[ndxFace].dispinfo].m_pDispTree;
  if ( pDispTree == nullptr )
    return 0;
  face = pLightInfo->face;
  v7 = face->m_LightmapTextureSizeInLuxels[0] + 1;
  height = face->m_LightmapTextureSizeInLuxels[1] + 1;
  v6 = height;
  pFaceLight->numluxels = v7 * height;
  ndxFaceb = calloc(count: v7 * v6, size: 0xCu);
  pFaceLight->luxel = (Vector *)ndxFaceb;
  v8 = calloc(count: v7 * v6, size: 0xCu);
  pFaceLight->luxelNormals = (Vector *)v8;
  if ( ndxFaceb == nullptr || v8 == nullptr )
    return 0;
  stepU = 1.0 / (float)(v7 - 1);
  v9 = 0;
  v10 = 1.0 / (float)(v6 - 1);
  stepV = v10;
  ndxV = 0;
  if ( v6 > 0 )
  {
    v11 = 12 * v7;
    ndxFacea = 0;
    v17 = 12 * v7;
    do
    {
      v12 = 0;
      if ( v7 > 0 )
      {
        v13 = ndxFacea;
        v14 = (float)v9 * v10;
        for ( i = v14; ; v14 = i )
        {
          luxel = pFaceLight->luxel;
          uv.y = v14;
          uv.x = (float)v12 * stepU;
          CVRADDispColl::DispUVToSurfPoint(
            this: pDispTree,
            dispUV: &uv,
            vecPoint: (Vector *)((char *)luxel + v13),
            flPushEps: 1.0);
          CVRADDispColl::DispUVToSurfNormal(
            this: pDispTree,
            dispUV: &uv,
            vecNormal: (Vector *)((char *)pFaceLight->luxelNormals + v13));
          ++v12;
          v13 += 12;
          if ( v12 >= v7 )
            break;
        }
        v10 = stepV;
        v9 = ndxV;
        v6 = height;
        v11 = v17;
      }
      ndxFacea += v11;
      ndxV = ++v9;
    }
    while ( v9 < v6 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028BC0
// Name: public: virtual bool CVRadDispMgr::BuildDispSamplesAndLuxels_DoFast(struct lightinfo_t __near *,struct facelight_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRadDispMgr::BuildDispSamplesAndLuxels_DoFast(
        CVRadDispMgr *this,
        lightinfo_t *pLightInfo,
        facelight_t *pFaceLight,
        int ndxFace)
{
  dface_t *face; // eax
  int v7; // edi
  int v8; // ebx
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // eax
  float v14; // xmm3_4
  int v15; // ecx
  int v16; // edx
  int v17; // ebx
  facelight_t *v18; // edi
  float v19; // xmm0_4
  sample_t *sample; // edx
  Vector *luxel; // eax
  sample_t *v22; // eax
  double v23; // st7
  int v24; // ecx
  Vector *luxelNormals; // eax
  int v26; // [esp+10h] [ebp-2Ch]
  int v27; // [esp+14h] [ebp-28h]
  float halfStepV; // [esp+18h] [ebp-24h]
  float halfStepU; // [esp+20h] [ebp-1Ch]
  float v30; // [esp+24h] [ebp-18h]
  int height; // [esp+28h] [ebp-14h]
  int width; // [esp+2Ch] [ebp-10h]
  float stepU; // [esp+30h] [ebp-Ch]
  lightinfo_t *v34; // [esp+34h] [ebp-8h]
  CVRADDispColl *pDispTree; // [esp+38h] [ebp-4h]
  lightinfo_t *pLightInfoa; // [esp+44h] [ebp+8h]
  facelight_t *pFaceLighta; // [esp+48h] [ebp+Ch]
  unsigned __int8 *ndxVa; // [esp+4Ch] [ebp+10h]
  int ndxV; // [esp+4Ch] [ebp+10h]

  pDispTree = this->m_DispTrees.m_Memory.m_pMemory[g_pFaces[ndxFace].dispinfo].m_pDispTree;
  if ( pDispTree == nullptr )
    return 0;
  face = pLightInfo->face;
  v7 = face->m_LightmapTextureSizeInLuxels[0] + 1;
  height = face->m_LightmapTextureSizeInLuxels[1] + 1;
  v8 = v7 * height;
  width = v7;
  pFaceLight->numsamples = v7 * height;
  v9 = calloc(count: v7 * height, size: 0x40u);
  pFaceLight->sample = (sample_t *)v9;
  if ( v9 == nullptr )
    return 0;
  pFaceLight->numluxels = v8;
  ndxVa = calloc(count: v8, size: 0xCu);
  pFaceLight->luxel = (Vector *)ndxVa;
  v10 = calloc(count: v8, size: 0xCu);
  pFaceLight->luxelNormals = (Vector *)v10;
  if ( ndxVa == nullptr || v10 == nullptr )
    return 0;
  v11 = 1.0 / (float)(v7 - 1);
  v12 = 1.0 / (float)(height - 1);
  halfStepU = v11 * 0.5;
  v13 = 0;
  v14 = v12 * 0.5;
  stepU = v11;
  halfStepV = v12 * 0.5;
  ndxV = 0;
  if ( height > 0 )
  {
    pFaceLighta = nullptr;
    pLightInfoa = nullptr;
    v15 = v7 << 6;
    v16 = 12 * v7;
    v27 = v7 << 6;
    v26 = 12 * v7;
    do
    {
      v17 = 0;
      if ( v7 > 0 )
      {
        v18 = pFaceLighta;
        v19 = (float)((float)v13 * v12) + v14;
        v30 = v19;
        v34 = pLightInfoa;
        while ( 1 )
        {
          *(sample_t **)((char *)&v18->sample + (unsigned int)pFaceLight->sample) = (sample_t *)v17;
          *(LightingValue_t **)((char *)v18->light[0] + (unsigned int)pFaceLight->sample) = (LightingValue_t *)v13;
          *(float *)((char *)&v18->light[0][1] + (unsigned int)pFaceLight->sample) = (float)((float)v17 * v11)
                                                                                   + halfStepU;
          *(float *)((char *)&v18->light[0][2] + (unsigned int)pFaceLight->sample) = v19;
          CVRADDispColl::DispUVToSurfPoint(
            this: pDispTree,
            dispUV: (const Vector2D *)((char *)&v18->light[0][1] + (unsigned int)pFaceLight->sample),
            vecPoint: (Vector *)((char *)&v18->light[1][3] + (unsigned int)pFaceLight->sample),
            flPushEps: 1.0);
          CVRADDispColl::DispUVToSurfNormal(
            this: pDispTree,
            dispUV: (const Vector2D *)((char *)&v18->light[0][1] + (unsigned int)pFaceLight->sample),
            vecNormal: (Vector *)((char *)&v18->light[2][2] + (unsigned int)pFaceLight->sample));
          sample = pFaceLight->sample;
          luxel = pFaceLight->luxel;
          *(float *)((char *)&v34->facedist + (_DWORD)luxel) = *(float *)((char *)&sample->pos.x + (_DWORD)v18);
          v11 = stepU;
          ++v17;
          *(float *)((char *)&v34->facenormal.x + (_DWORD)luxel) = *(float *)((char *)&sample->pos.y + (_DWORD)v18);
          v34 = (lightinfo_t *)((char *)v34 + 12);
          *(float *)((char *)v34 + (_DWORD)luxel - 4) = *(float *)((char *)&sample->pos.z + (_DWORD)v18);
          v22 = pFaceLight->sample;
          v23 = *(float *)((char *)&v22->normal.x + (_DWORD)v18);
          v24 = (int)&v22->normal + (_DWORD)v18;
          luxelNormals = pFaceLight->luxelNormals;
          *(float *)((char *)v34 + (_DWORD)luxelNormals - 12) = v23;
          v18 = (facelight_t *)((char *)v18 + 64);
          *(float *)((char *)v34 + (_DWORD)luxelNormals - 8) = *(float *)(v24 + 4);
          *(float *)((char *)v34 + (_DWORD)luxelNormals - 4) = *(float *)(v24 + 8);
          v13 = ndxV;
          if ( v17 >= width )
            break;
          v19 = v30;
        }
        v12 = 1.0 / (float)(height - 1);
        v14 = halfStepV;
        v7 = width;
        v15 = v27;
        v16 = v26;
      }
      pLightInfoa = (lightinfo_t *)((char *)pLightInfoa + v16);
      pFaceLighta = (facelight_t *)((char *)pFaceLighta + v15);
      ndxV = ++v13;
    }
    while ( v13 < height );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028E10
// Name: public: virtual bool CBSPDispRayEnumerator::EnumerateElement(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall CBSPDispRayEnumerator::EnumerateElement(CBSPDispRayEnumerator *this, int userId, int context)
{
  return CVRadDispMgr::DispRay_EnumerateElement(this: &s_DispMgr, userId, context);
}

//------------------------------------------------------------------------------
// Address: 0x10028E30
// Name: public: virtual bool CBSPDispRayDistanceEnumerator::EnumerateElement(int,int)
// Source: json
//------------------------------------------------------------------------------
char __fastcall CBSPDispRayDistanceEnumerator::EnumerateElement(
        CBSPDispRayDistanceEnumerator *this,
        int userId,
        int context)
{
  return CVRadDispMgr::DispRayDistance_EnumerateElement(this: &s_DispMgr, userId, pCtx: this);
}

//------------------------------------------------------------------------------
// Address: 0x10028E40
// Name: public: virtual void CVRadDispMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::Shutdown(CVRadDispMgr *this)
{
  int i; // edi
  bool v3; // sf
  CVRadDispMgr::DispCollTree_t *m_pMemory; // ecx

  for ( i = this->m_DispTrees.m_Size; i >= 0; --i )
  {
    if ( this->m_DispTrees.m_Memory.m_pMemory[i].m_Handle != 0xFFFF )
    {
      this->m_pBSPTreeData->Remove(this: this->m_pBSPTreeData, a2: this->m_DispTrees.m_Memory.m_pMemory[i].m_Handle);
      this->m_DispTrees.m_Memory.m_pMemory[i].m_Handle = -1;
    }
  }
  this->m_pBSPTreeData->Shutdown(this: this->m_pBSPTreeData);
  v3 = this->m_DispTrees.m_Memory.m_nGrowSize < 0;
  this->m_DispTrees.m_Size = 0;
  if ( v3 )
  {
    this->m_DispTrees.m_pElements = this->m_DispTrees.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_DispTrees.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DispTrees.m_Memory.m_pMemory);
      this->m_DispTrees.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_DispTrees.m_Memory.m_pMemory;
    this->m_DispTrees.m_Memory.m_nAllocationCount = 0;
    this->m_DispTrees.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028ED0
// Name: public: virtual CBSPDispFaceListEnumerator::~CBSPDispFaceListEnumerator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPDispFaceListEnumerator::~CBSPDispFaceListEnumerator(CBSPDispFaceListEnumerator *this)
{
  this->ISpatialLeafEnumerator::__vftable = (CBSPDispFaceListEnumerator_vtbl *)&CBSPDispFaceListEnumerator::`vftable'{for `ISpatialLeafEnumerator'};
  this->IBSPTreeDataEnumerator::__vftable = (IBSPTreeDataEnumerator_vtbl *)&CBSPDispFaceListEnumerator::`vftable'{for `IBSPTreeDataEnumerator'};
  this->m_DispList.m_Size = 0;
  if ( this->m_DispList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DispList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DispList.m_Memory.m_pMemory);
      this->m_DispList.m_Memory.m_pMemory = nullptr;
    }
    this->m_DispList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DispList.m_pElements = this->m_DispList.m_Memory.m_pMemory;
  this->m_FaceList.m_Size = 0;
  if ( this->m_FaceList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FaceList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FaceList.m_Memory.m_pMemory);
      this->m_FaceList.m_Memory.m_pMemory = nullptr;
    }
    this->m_FaceList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FaceList.m_pElements = this->m_FaceList.m_Memory.m_pMemory;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_FaceList);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_DispList);
}

//------------------------------------------------------------------------------
// Address: 0x10028F80
// Name: public: CVRadDispMgr::CVRadDispMgr(void)
// Source: json
//------------------------------------------------------------------------------
CVRadDispMgr *__thiscall CVRadDispMgr::CVRadDispMgr(CVRadDispMgr *this)
{
  this->__vftable = (CVRadDispMgr_vtbl *)&CVRadDispMgr::`vftable';
  this->m_DispTrees.m_Memory.m_pMemory = nullptr;
  this->m_DispTrees.m_Memory.m_nAllocationCount = 0;
  this->m_DispTrees.m_Memory.m_nGrowSize = 0;
  this->m_DispTrees.m_Size = 0;
  this->m_DispTrees.m_pElements = nullptr;
  this->m_EnumDispRay.__vftable = (CBSPDispRayEnumerator_vtbl *)&CBSPDispRayEnumerator::`vftable'{for `ISpatialLeafEnumerator'};
  this->m_EnumDispRay.__vftable = (IBSPTreeDataEnumerator_vtbl *)&CBSPDispRayEnumerator::`vftable'{for `IBSPTreeDataEnumerator'};
  this->m_EnumDispFaceList.__vftable = (CBSPDispFaceListEnumerator_vtbl *)&CBSPDispFaceListEnumerator::`vftable'{for `ISpatialLeafEnumerator'};
  this->m_EnumDispFaceList.__vftable = (IBSPTreeDataEnumerator_vtbl *)&CBSPDispFaceListEnumerator::`vftable'{for `IBSPTreeDataEnumerator'};
  this->m_EnumDispFaceList.m_DispList.m_Memory.m_pMemory = nullptr;
  this->m_EnumDispFaceList.m_DispList.m_Memory.m_nAllocationCount = 0;
  this->m_EnumDispFaceList.m_DispList.m_Memory.m_nGrowSize = 0;
  this->m_EnumDispFaceList.m_DispList.m_Size = 0;
  this->m_EnumDispFaceList.m_DispList.m_pElements = nullptr;
  this->m_EnumDispFaceList.m_FaceList.m_Memory.m_pMemory = nullptr;
  this->m_EnumDispFaceList.m_FaceList.m_Memory.m_nAllocationCount = 0;
  this->m_EnumDispFaceList.m_FaceList.m_Memory.m_nGrowSize = 0;
  this->m_EnumDispFaceList.m_FaceList.m_Size = 0;
  this->m_EnumDispFaceList.m_FaceList.m_pElements = nullptr;
  this->m_Timer.m_Duration.m_Int64 = 0;
  this->m_pBSPTreeData = CreateBSPTreeData();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028FF0
// Name: private: void CVRadDispMgr::UnserializeDisps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::UnserializeDisps(CVRadDispMgr *this)
{
  int m_Size; // eax
  int v2; // esi
  CCoreDispInfo **v3; // edi
  CCoreDispInfo *v4; // eax
  CCoreDispInfo *v5; // ecx
  int v6; // ebx
  int v7; // esi
  int v8; // esi
  int v9; // ebx
  dface_t *v10; // eax
  __int16 dispinfo; // cx
  int v12; // esi
  int v13; // ebx
  int v14; // ecx
  int *v15; // eax
  int v16; // eax
  int v17; // ebx
  CVRADDispColl *v18; // esi
  int m_nGrowSize; // esi
  IMemAlloc *v20; // ecx
  CCoreDispInfo *v21; // ecx
  CVRadDispMgr *v22; // ebx
  int v23; // esi
  int m_nAllocationCount; // eax
  CVRadDispMgr::DispCollTree_t *m_pMemory; // edx
  int v26; // eax
  int v27; // esi
  CCoreDispInfo *v28; // ecx
  int v29; // eax
  CVRadDispMgr::DispCollTree_t *v30; // edi
  _DWORD *v31; // eax
  IBSPTreeData *m_pBSPTreeData; // ecx
  unsigned __int16 v33; // ax
  CUtlVector<CCoreDispInfo *,CUtlMemory<CCoreDispInfo *,int> > builderDisps; // [esp+Ch] [ebp-38h] BYREF
  _DWORD v35[3]; // [esp+20h] [ebp-24h] BYREF
  _DWORD v36[3]; // [esp+2Ch] [ebp-18h] BYREF
  int iDisp; // [esp+38h] [ebp-Ch]
  CVRadDispMgr *v38; // [esp+3Ch] [ebp-8h]
  CCoreDispInfo *pDisp; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  m_Size = g_dispinfo.m_Size;
  v2 = 0;
  v3 = nullptr;
  v38 = this;
  memset(&builderDisps, 0, sizeof(builderDisps));
  iDisp = 0;
  if ( g_dispinfo.m_Size <= 0 )
  {
LABEL_9:
    v7 = 0;
    if ( m_Size > 0 )
    {
      do
      {
        CCoreDispInfo::SetDispUtilsHelperInfo(this: v3[v7], ppListBase: v3, listSize: m_Size);
        m_Size = g_dispinfo.m_Size;
        ++v7;
      }
      while ( v7 < g_dispinfo.m_Size );
    }
    v8 = 0;
    if ( (int)numfaces > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &g_pFaces[v9];
        if ( &g_pFaces[v9] != nullptr )
        {
          dispinfo = v10->dispinfo;
          if ( dispinfo != -1 && v10->numedges == 4 )
            CVRadDispMgr::DispBuilderInit(
              this: v38,
              a2: COERCE_FLOAT(&savedregs),
              pBuilderDisp: v3[dispinfo],
              pFace: &g_pFaces[v9],
              ndxFace: v8);
        }
        ++v8;
        ++v9;
      }
      while ( v8 < (int)numfaces );
      m_Size = g_dispinfo.m_Size;
    }
    v12 = 0;
    if ( m_Size > 0 )
    {
      do
      {
        CCoreDispInfo::Create(this: v3[v12]);
        m_Size = g_dispinfo.m_Size;
        ++v12;
      }
      while ( v12 < g_dispinfo.m_Size );
    }
    SmoothNeighboringDispSurfNormals(ppListBase: v3, listSize: m_Size);
    v13 = g_dispinfo.m_Size;
    v14 = (316 * (unsigned __int64)(unsigned int)g_dispinfo.m_Size) >> 32 != 0 ? -1 : 316 * g_dispinfo.m_Size;
    v15 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v14, 4) ? -1 : v14 + 4);
    if ( v15 == nullptr )
      goto LABEL_26;
    *v15 = v13;
    v16 = (int)(v15 + 1);
    v17 = v13 - 1;
    iDisp = v16;
    v18 = (CVRADDispColl *)v16;
    if ( v17 >= 0 )
    {
      do
      {
        CVRADDispColl::CVRADDispColl(this: v18++);
        --v17;
      }
      while ( v17 >= 0 );
      v16 = iDisp;
    }
    if ( v16 == 0 )
    {
LABEL_26:
      if ( builderDisps.m_Memory.m_nGrowSize < 0 )
        return;
LABEL_47:
      if ( v3 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
      return;
    }
    v21 = (CCoreDispInfo *)g_dispinfo.m_Size;
    v22 = v38;
    v23 = v38->m_DispTrees.m_Size;
    pDisp = (CCoreDispInfo *)g_dispinfo.m_Size;
    if ( g_dispinfo.m_Size != 0 )
    {
      m_nAllocationCount = v38->m_DispTrees.m_Memory.m_nAllocationCount;
      if ( v23 + g_dispinfo.m_Size > m_nAllocationCount )
      {
        CUtlMemory<CacheOptimizedKDNode,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)&v38->m_DispTrees,
          num: g_dispinfo.m_Size + v23 - m_nAllocationCount);
        v21 = pDisp;
      }
      v22->m_DispTrees.m_Size += (int)v21;
      m_pMemory = v22->m_DispTrees.m_Memory.m_pMemory;
      v26 = v22->m_DispTrees.m_Size - v23 - (_DWORD)v21;
      v22->m_DispTrees.m_pElements = m_pMemory;
      if ( v26 > 0 && (int)v21 > 0 )
        _V_memmove(dest: &m_pMemory[(int)v21 + v23], src: &m_pMemory[v23], count: 8 * v26);
      v21 = (CCoreDispInfo *)g_dispinfo.m_Size;
    }
    v27 = 0;
    if ( (int)v21 > 0 )
    {
      v28 = (CCoreDispInfo *)iDisp;
      for ( pDisp = (CCoreDispInfo *)iDisp; ; v28 = pDisp )
      {
        ((void (__thiscall *)(CCoreDispInfo *, CCoreDispInfo *))v28->GetPowerInfo)(a1: v28, a2: v3[v27]);
        v29 = v27;
        v22->m_DispTrees.m_Memory.m_pMemory[v29].m_pDispTree = (CVRADDispColl *)pDisp;
        v22->m_DispTrees.m_Memory.m_pMemory[v29].m_Handle = -1;
        v30 = &v22->m_DispTrees.m_Memory.m_pMemory[v27];
        v31 = &v30->m_pDispTree->__vftable;
        v35[0] = LODWORD(v30->m_pDispTree->m_mins.x);
        v35[1] = v31[2];
        v35[2] = v31[3];
        v36[0] = v31[5];
        v36[1] = v31[6];
        m_pBSPTreeData = v22->m_pBSPTreeData;
        v36[2] = v31[7];
        v33 = m_pBSPTreeData->Insert(this: m_pBSPTreeData, a2: v27, a3: (const Vector *)v35, a4: (const Vector *)v36);
        pDisp = (CCoreDispInfo *)((char *)pDisp + 316);
        v30->m_Handle = v33;
        v3 = builderDisps.m_Memory.m_pMemory;
        if ( ++v27 >= g_dispinfo.m_Size )
          break;
      }
    }
    m_nGrowSize = builderDisps.m_Memory.m_nGrowSize;
    if ( builderDisps.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v3 != nullptr )
      {
        v20 = _g_pMemAlloc;
LABEL_45:
        v20->Free_2(this: v20, a2: v3);
        builderDisps.m_Memory.m_pMemory = nullptr;
        v3 = nullptr;
      }
LABEL_46:
      if ( m_nGrowSize < 0 )
        return;
      goto LABEL_47;
    }
  }
  else
  {
    while ( 1 )
    {
      v4 = (CCoreDispInfo *)MemAlloc_Alloc(nSize: 0x34Cu);
      if ( v4 == nullptr )
        break;
      v5 = CCoreDispInfo::CCoreDispInfo(this: v4);
      pDisp = v5;
      if ( v5 == nullptr )
        break;
      v6 = v2;
      if ( v2 + 1 > builderDisps.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&builderDisps,
          num: v2 - builderDisps.m_Memory.m_nAllocationCount + 1);
        v2 = builderDisps.m_Size;
        v3 = builderDisps.m_Memory.m_pMemory;
        v5 = pDisp;
      }
      builderDisps.m_Size = ++v2;
      builderDisps.m_pElements = v3;
      if ( v2 - v6 - 1 > 0 )
      {
        _V_memmove(dest: &v3[v6 + 1], src: &v3[v6], count: 4 * (v2 - v6 - 1));
        v5 = pDisp;
      }
      v5->m_nListIndex = v6;
      v3[v6] = v5;
      m_Size = g_dispinfo.m_Size;
      if ( ++iDisp >= g_dispinfo.m_Size )
        goto LABEL_9;
    }
    m_nGrowSize = builderDisps.m_Memory.m_nGrowSize;
    if ( builderDisps.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v3 == nullptr )
        goto LABEL_46;
      v20 = _g_pMemAlloc;
      goto LABEL_45;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029330
// Name: public: bool CVRadDispMgr::DispFaceList_EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRadDispMgr::DispFaceList_EnumerateLeaf(CVRadDispMgr *this, int ndxLeaf, int context)
{
  CVRadDispMgr *v3; // esi
  dleaf_t *v4; // edi
  int v5; // eax
  int m_Size; // ecx
  int v7; // ebx
  int v8; // eax
  int *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v11; // edi
  int *v12; // ecx
  int v13; // eax
  int *v14; // eax
  IBSPTreeDataEnumerator *v15; // eax
  dleaf_t *pLeaf; // [esp+8h] [ebp-Ch]
  int ndxFace; // [esp+10h] [ebp-4h]

  v3 = this;
  v4 = &dleafs[ndxLeaf];
  v5 = 0;
  pLeaf = v4;
  ndxFace = 0;
  if ( v4->numleaffaces != 0 )
  {
    do
    {
      m_Size = v3->m_EnumDispFaceList.m_FaceList.m_Size;
      v7 = v5 + v4->firstleafface;
      v8 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = v3->m_EnumDispFaceList.m_FaceList.m_Memory.m_pMemory;
        do
        {
          if ( *m_pMemory == v7 )
            break;
          ++v8;
          ++m_pMemory;
        }
        while ( v8 < m_Size );
      }
      if ( v8 == m_Size )
      {
        m_nAllocationCount = v3->m_EnumDispFaceList.m_FaceList.m_Memory.m_nAllocationCount;
        v11 = v3->m_EnumDispFaceList.m_FaceList.m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&v3->m_EnumDispFaceList.m_FaceList,
            num: m_Size - m_nAllocationCount + 1);
        ++v3->m_EnumDispFaceList.m_FaceList.m_Size;
        v12 = v3->m_EnumDispFaceList.m_FaceList.m_Memory.m_pMemory;
        v13 = v3->m_EnumDispFaceList.m_FaceList.m_Size - v11 - 1;
        v3->m_EnumDispFaceList.m_FaceList.m_pElements = v12;
        if ( v13 > 0 )
          _V_memmove(dest: &v12[v11 + 1], src: &v12[v11], count: 4 * v13);
        v14 = v3->m_EnumDispFaceList.m_FaceList.m_Memory.m_pMemory;
        v3 = this;
        v14[v11] = v7;
        v4 = pLeaf;
      }
      v5 = ndxFace + 1;
      ndxFace = v5;
    }
    while ( v5 < v4->numleaffaces );
  }
  if ( v3 == (CVRadDispMgr *)-36 )
    v15 = nullptr;
  else
    v15 = &v3->m_EnumDispFaceList.IBSPTreeDataEnumerator;
  return v3->m_pBSPTreeData->EnumerateElementsInLeaf(this: v3->m_pBSPTreeData, a2: ndxLeaf, a3: v15, a4: context);
}

//------------------------------------------------------------------------------
// Address: 0x10029410
// Name: public: bool CVRadDispMgr::DispFaceList_EnumerateElement(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRadDispMgr::DispFaceList_EnumerateElement(CVRadDispMgr *this, int userId, int context)
{
  CVRADDispColl *m_pDispTree; // ebx
  int m_Size; // edx
  int v6; // eax
  CVRADDispColl **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_DispList; // esi
  int v10; // edi
  S3RGBA *v11; // ecx
  int v12; // eax

  m_pDispTree = this->m_DispTrees.m_Memory.m_pMemory[userId].m_pDispTree;
  if ( m_pDispTree == nullptr )
    return 0;
  m_Size = this->m_EnumDispFaceList.m_DispList.m_Size;
  v6 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_EnumDispFaceList.m_DispList.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == m_pDispTree )
        break;
      ++v6;
      ++m_pMemory;
    }
    while ( v6 < m_Size );
  }
  if ( v6 == m_Size )
  {
    m_nAllocationCount = this->m_EnumDispFaceList.m_DispList.m_Memory.m_nAllocationCount;
    p_m_DispList = (CUtlMemory<S3RGBA,int> *)&this->m_EnumDispFaceList.m_DispList;
    v10 = this->m_EnumDispFaceList.m_DispList.m_Size;
    if ( v10 + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(this: p_m_DispList, num: v10 - m_nAllocationCount + 1);
    ++p_m_DispList[1].m_pMemory;
    v11 = p_m_DispList->m_pMemory;
    v12 = (int)p_m_DispList[1].m_pMemory - v10 - 1;
    p_m_DispList[1].m_nAllocationCount = (int)p_m_DispList->m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[v10 + 1], src: &v11[v10], count: 4 * v12);
    p_m_DispList->m_pMemory[v10] = (S3RGBA)m_pDispTree;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100294A0
// Name: private: void CVRadDispMgr::RadialLuxelAddSamples(int,class Vector const __near &,class Vector const __near &,float,struct radial_s __near *,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::RadialLuxelAddSamples(
        CVRadDispMgr *this,
        int ndxFace,
        const Vector *luxelPt,
        const Vector *luxelNormal,
        float radius,
        radial_s *pRadial,
        int ndxRadial,
        bool bBump,
        int lightStyle)
{
  const Vector *v9; // eax
  int i; // esi
  float x; // xmm0_4
  int v12; // esi
  unsigned int *v13; // eax
  int v14; // ebx
  int v15; // edi
  int v16; // edx
  int v17; // eax
  int v18; // esi
  unsigned __int16 v19; // di
  SampleData_t *v20; // eax
  int m_Size; // edx
  int v22; // ecx
  unsigned int *m_pMemory; // edx
  unsigned int v24; // eax
  int v25; // esi
  facelight_t *v26; // edi
  int numneighbors; // edx
  int v28; // ecx
  int *neighbor; // ebx
  dface_t *v30; // eax
  int v31; // ecx
  bool v32; // bl
  LightingValue_t sampleLight[4]; // [esp+28h] [ebp-A0h] BYREF
  int voxelMin[3]; // [esp+68h] [ebp-60h] BYREF
  int voxelMax[3]; // [esp+74h] [ebp-54h] BYREF
  int v36; // [esp+80h] [ebp-48h]
  SampleData_t *pSampleData; // [esp+84h] [ebp-44h]
  unsigned int pBucket; // [esp+88h] [ebp-40h] BYREF
  int v39; // [esp+8Ch] [ebp-3Ch]
  BOOL bNeighborBump; // [esp+90h] [ebp-38h]
  int v41; // [esp+94h] [ebp-34h]
  int count; // [esp+98h] [ebp-30h]
  SampleData_t sampleData; // [esp+9Ch] [ebp-2Ch] BYREF
  int ndxX; // [esp+B8h] [ebp-10h]
  int ndxZ; // [esp+BCh] [ebp-Ch]
  int ndxY; // [esp+C0h] [ebp-8h]
  int ndx; // [esp+C4h] [ebp-4h] BYREF

  v9 = luxelPt;
  for ( i = 3; i != 0; --i )
  {
    x = v9->x;
    *(_DWORD *)((char *)&v9->x + (char *)voxelMin - (char *)luxelPt) = (int)(float)((float)(v9->x - radius) * 0.015625);
    *(_DWORD *)((char *)&v9->x + (char *)voxelMax - (char *)luxelPt) = 1 - (int)(float)((float)(x + radius) * -0.015625);
    v9 = (const Vector *)((char *)v9 + 4);
  }
  v12 = voxelMax[2] + 1;
  v13 = nullptr;
  v14 = voxelMin[2];
  memset(&sampleData.m_Samples, 0, sizeof(sampleData.m_Samples));
  ndxZ = voxelMin[2];
  v41 = voxelMax[2] + 1;
  if ( voxelMin[2] < voxelMax[2] + 1 )
  {
    v15 = voxelMax[1] + 1;
    v39 = voxelMax[1] + 1;
    do
    {
      v16 = voxelMin[1];
      ndxY = voxelMin[1];
      if ( voxelMin[1] < v15 )
      {
        v17 = voxelMax[0] + 1;
        do
        {
          v18 = voxelMin[0];
          ndxX = voxelMin[0];
          if ( voxelMin[0] < v17 )
          {
            v19 = 10 * v16;
            v36 = 10 * v16;
            do
            {
              sampleData.x = 100 * v18;
              sampleData.y = v19;
              sampleData.z = v14;
              ndx = 0;
              if ( CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::DoFind(
                     this: (CUtlHash<PatchSampleData_t,bool (__cdecl*)(PatchSampleData_t const &,PatchSampleData_t const &),unsigned int (__cdecl*)(PatchSampleData_t const &)> *)&g_SampleHashTable,
                     src: (const PatchSampleData_t *)&sampleData,
                     &pBucket,
                     pIndex: &ndx) != 0
                && (ndx | (pBucket << 16)) != 0xFFFFFFFF )
              {
                v20 = &g_SampleHashTable.m_Buckets.m_Memory.m_pMemory[(ndx | (pBucket << 16)) >> 16].m_Memory.m_pMemory[(unsigned __int16)ndx];
                m_Size = v20->m_Samples.m_Size;
                v22 = 0;
                pSampleData = v20;
                count = m_Size;
                ndx = 0;
                if ( m_Size > 0 )
                {
                  while ( 1 )
                  {
                    m_pMemory = v20->m_Samples.m_Memory.m_pMemory;
                    v24 = HIWORD(m_pMemory[v22]);
                    v25 = (unsigned __int16)m_pMemory[v22];
                    v26 = &facelight[v24];
                    if ( v26 == nullptr )
                      goto LABEL_28;
                    if ( ndxFace != v24 )
                    {
                      numneighbors = faceneighbor[ndxFace].numneighbors;
                      v28 = 0;
                      if ( numneighbors <= 0 )
                        goto LABEL_28;
                      neighbor = faceneighbor[ndxFace].neighbor;
                      while ( *neighbor != v24 )
                      {
                        ++v28;
                        ++neighbor;
                        if ( v28 >= numneighbors )
                          goto LABEL_28;
                      }
                    }
                    v30 = &g_pFaces[v24];
                    if ( v30 != nullptr )
                    {
                      v31 = 0;
                      while ( v30->styles[v31] != lightStyle )
                      {
                        if ( ++v31 >= 4 )
                          goto LABEL_28;
                      }
                      if ( v31 != -1 )
                      {
                        LOBYTE(bNeighborBump) = (texinfo.m_Memory.m_pMemory[v30->texinfo].flags & 0x800) != 0;
                        v32 = bNeighborBump;
                        GetSampleLight(
                          pFaceLight: v26,
                          ndxStyle: v31,
                          bBumped: bNeighborBump,
                          ndxSample: v25,
                          pSampleLight: sampleLight);
                        AddSampleLightToRadial(
                          samplePos: &v26->sample[v25].pos,
                          sampleNormal: &v26->sample[v25].normal,
                          pSampleLight: sampleLight,
                          sampleRadius2: radius * radius,
                          luxelPos: luxelPt,
                          luxelNormal,
                          pRadial,
                          ndxRadial,
                          bBumped: bBump,
                          bNeighborBumped: v32);
                      }
                    }
LABEL_28:
                    v22 = ndx + 1;
                    ndx = v22;
                    if ( v22 >= count )
                    {
                      v19 = v36;
                      v18 = ndxX;
                      v14 = ndxZ;
                      break;
                    }
                    v20 = pSampleData;
                  }
                }
              }
              ++v18;
              v17 = voxelMax[0] + 1;
              ndxX = v18;
            }
            while ( v18 < voxelMax[0] + 1 );
            v16 = ndxY;
            v15 = v39;
          }
          ndxY = ++v16;
        }
        while ( v16 < v15 );
        v12 = v41;
      }
      ndxZ = ++v14;
    }
    while ( v14 < v12 );
    v13 = sampleData.m_Samples.m_Memory.m_pMemory;
  }
  sampleData.m_Samples.m_Size = 0;
  if ( sampleData.m_Samples.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      v13 = nullptr;
      sampleData.m_Samples.m_Memory.m_pMemory = nullptr;
    }
    sampleData.m_Samples.m_Memory.m_nAllocationCount = 0;
  }
  sampleData.m_Samples.m_pElements = v13;
  if ( sampleData.m_Samples.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x100297A0
// Name: private: void CVRadDispMgr::RadialLuxelBuild(class CVRADDispColl __near *,struct radial_s __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::RadialLuxelBuild(
        CVRadDispMgr *this,
        CVRADDispColl *pDispTree,
        radial_s *pRadial,
        int ndxStyle,
        bool bBump)
{
  int m_iParent; // eax
  float v6; // xmm0_4
  facelight_t *v7; // esi
  int v8; // edi
  int v9; // ebx
  int radialSize; // [esp+20h] [ebp-10h]
  dface_t *pFace; // [esp+2Ch] [ebp-4h]
  int ndxFace; // [esp+38h] [ebp+8h]

  m_iParent = pDispTree->m_iParent;
  v6 = fsqrt(pDispTree->m_flSampleRadius2);
  pFace = &g_pFaces[m_iParent];
  v7 = &facelight[m_iParent];
  v8 = 0;
  ndxFace = m_iParent;
  radialSize = pRadial->w * pRadial->h;
  if ( radialSize > 0 )
  {
    v9 = 0;
    while ( 1 )
    {
      CVRadDispMgr::RadialLuxelAddSamples(
        this,
        ndxFace: m_iParent,
        luxelPt: &v7->luxel[v9],
        luxelNormal: &v7->luxelNormals[v9],
        radius: v6,
        pRadial,
        ndxRadial: v8++,
        bBump,
        lightStyle: pFace->styles[ndxStyle]);
      ++v9;
      if ( v8 >= radialSize )
        break;
      m_iParent = ndxFace;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029850
// Name: public: virtual struct radial_s __near * CVRadDispMgr::BuildLuxelRadial(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
radial_s *__thiscall CVRadDispMgr::BuildLuxelRadial(CVRadDispMgr *this, int ndxFace, int ndxStyle, bool bBump)
{
  radial_s *Radial; // edi
  CVRADDispColl *m_pDispTree; // eax

  Radial = AllocateRadial(facenum: ndxFace);
  if ( Radial == nullptr )
    return nullptr;
  m_pDispTree = this->m_DispTrees.m_Memory.m_pMemory[g_pFaces[ndxFace].dispinfo].m_pDispTree;
  if ( m_pDispTree == nullptr )
    return nullptr;
  CVRadDispMgr::RadialLuxelBuild(this, pDispTree: m_pDispTree, pRadial: Radial, ndxStyle, bBump);
  return Radial;
}

//------------------------------------------------------------------------------
// Address: 0x100298B0
// Name: public: virtual bool CBSPDispFaceListEnumerator::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBSPDispFaceListEnumerator::EnumerateLeaf(CBSPDispFaceListEnumerator *this, int ndxLeaf, int context)
{
  return CVRadDispMgr::DispFaceList_EnumerateLeaf(this: &s_DispMgr, ndxLeaf, context);
}

//------------------------------------------------------------------------------
// Address: 0x100298C0
// Name: public: virtual bool CBSPDispFaceListEnumerator::EnumerateElement(int,int)
// Source: json
//------------------------------------------------------------------------------
char __fastcall CBSPDispFaceListEnumerator::EnumerateElement(CBSPDispFaceListEnumerator *this, int userId, int context)
{
  return CVRadDispMgr::DispFaceList_EnumerateElement(this: &s_DispMgr, userId, context);
}

//------------------------------------------------------------------------------
// Address: 0x10029920
// Name: public: virtual void CVRadDispMgr::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::Init(CVRadDispMgr *this)
{
  IBSPTreeData_vtbl *v2; // edi
  ISpatialQuery *v3; // eax

  v2 = this->m_pBSPTreeData->__vftable;
  v3 = ToolBSPTree();
  v2->Init(this: this->m_pBSPTreeData, a2: v3);
  CVRadDispMgr::UnserializeDisps(this);
}

//------------------------------------------------------------------------------
// Address: 0x10029940
// Name: private: void CVRadDispMgr::GetInterestingPatchesForLuxels(int,class CUtlVector<struct CPatch __near *,class CUtlMemory<struct CPatch __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::GetInterestingPatchesForLuxels(
        CVRadDispMgr *this,
        int ndxFace,
        CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *interestingPatches,
        float patchSampleRadius)
{
  facelight_t *v4; // eax
  int numluxels; // ecx
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float *p_x; // eax
  float v10; // xmm4_4
  double v11; // xmm0_8
  float v12; // xmm3_4
  float v13; // xmm0_4
  double v14; // xmm0_8
  float v15; // xmm2_4
  int v16; // xmm0_4
  double v17; // xmm0_8
  double v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  int i; // eax
  float v22; // xmm3_4
  int v23; // eax
  unsigned int m_Size; // edi
  unsigned __int8 *m_pMemory; // ebx
  int v26; // esi
  bool v27; // cc
  float *v29; // ecx
  int j; // eax
  float v31; // xmm0_4
  int v32; // esi
  int v33; // ecx
  int v34; // edx
  int v35; // eax
  int v36; // edi
  int v37; // eax
  int v38; // esi
  unsigned __int8 *v39; // edx
  char v40; // bl
  unsigned __int16 v41; // ax
  int v42; // ecx
  CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *v43; // edx
  int v45; // eax
  int v46; // ebx
  int v47; // edx
  int v48; // eax
  unsigned int v49; // eax
  PatchSampleData_t *v50; // eax
  int v51; // ecx
  CPatch *v52; // ebx
  int faceNumber; // esi
  int numneighbors; // ecx
  int v55; // eax
  int *neighbor; // edx
  int v57; // esi
  int m_nAllocationCount; // eax
  CPatch **v59; // ecx
  int v60; // eax
  CPatch **v61; // esi
  int *v62; // eax
  PatchSampleData_t patchData; // [esp+0h] [ebp-80h] BYREF
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > voxelBits; // [esp+1Ch] [ebp-64h] BYREF
  int voxelMin[3]; // [esp+30h] [ebp-50h]
  int voxelMax[3]; // [esp+3Ch] [ebp-44h]
  int allVoxelMin[3]; // [esp+48h] [ebp-38h]
  int allVoxelSize[3]; // [esp+54h] [ebp-2Ch]
  int v69; // [esp+60h] [ebp-20h]
  PatchSampleData_t *pPatchData; // [esp+64h] [ebp-1Ch]
  unsigned int pBucket; // [esp+68h] [ebp-18h] BYREF
  CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *v72; // [esp+6Ch] [ebp-14h]
  int ndx; // [esp+70h] [ebp-10h] BYREF
  int x; // [esp+74h] [ebp-Ch]
  CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *v75; // [esp+78h] [ebp-8h]
  int z; // [esp+7Ch] [ebp-4h]
  CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *interestingPatchesa; // [esp+8Ch] [ebp+Ch]
  int y; // [esp+90h] [ebp+10h]
  int ya; // [esp+90h] [ebp+10h]

  v4 = &facelight[ndxFace];
  numluxels = v4->numluxels;
  v6 = 3.4028235e38;
  allVoxelSize[0] = 2139095039;
  allVoxelSize[1] = 2139095039;
  v7 = -3.4028235e38;
  v8 = -3.4028235e38;
  z = (int)v4;
  allVoxelSize[2] = 2139095039;
  voxelMax[0] = -8388609;
  voxelMax[1] = -8388609;
  voxelMax[2] = -8388609;
  if ( numluxels > 0 )
  {
    p_x = &v4->luxel->x;
    do
    {
      v10 = *p_x;
      v11 = *p_x;
      if ( v11 > *(float *)allVoxelSize )
        v11 = *(float *)allVoxelSize;
      v12 = p_x[1];
      v13 = v11;
      *(float *)allVoxelSize = v13;
      v14 = v12;
      if ( v12 > (double)*(float *)&allVoxelSize[1] )
        v14 = *(float *)&allVoxelSize[1];
      v15 = p_x[2];
      *(float *)&v16 = v14;
      allVoxelSize[1] = v16;
      v17 = v15;
      if ( v15 > (double)v6 )
        v17 = v6;
      v6 = v17;
      v18 = v10;
      if ( v10 < (double)v7 )
        v18 = v7;
      v7 = v18;
      v19 = v12;
      if ( v12 < (double)v8 )
        v19 = v8;
      v8 = v19;
      v20 = v15;
      if ( v15 < (double)*(float *)&voxelMax[2] )
        v20 = *(float *)&voxelMax[2];
      p_x += 3;
      --numluxels;
      *(float *)&voxelMax[2] = v20;
    }
    while ( numluxels != 0 );
    *(float *)&voxelMax[1] = v8;
    *(float *)voxelMax = v7;
    *(float *)&allVoxelSize[2] = v6;
  }
  for ( i = 0; i < 3; ++i )
  {
    v22 = *(float *)&voxelMax[i];
    allVoxelMin[i] = (int)(float)((float)(*(float *)&allVoxelSize[i] - patchSampleRadius) * 0.015625);
    voxelMin[i] = 1 - (int)(float)((float)(v22 + patchSampleRadius) * -0.015625);
  }
  allVoxelSize[2] = voxelMin[2] - allVoxelMin[2];
  allVoxelSize[1] = voxelMin[1] - allVoxelMin[1];
  v23 = (voxelMin[0] - allVoxelMin[0]) * (voxelMin[1] - allVoxelMin[1]) * (voxelMin[2] - allVoxelMin[2]) + 7;
  m_Size = 0;
  m_pMemory = nullptr;
  v26 = v23 / 8;
  allVoxelSize[0] = voxelMin[0] - allVoxelMin[0];
  memset(&voxelBits, 0, sizeof(voxelBits));
  if ( v23 / 8 != 0 )
  {
    if ( v23 / 8 > 0 )
    {
      CUtlMemory<char,int>::Grow(this: &voxelBits.m_Memory, num: v23 / 8);
      m_Size = voxelBits.m_Size;
      m_pMemory = voxelBits.m_Memory.m_pMemory;
    }
    m_Size += v26;
    if ( (int)(m_Size - v26) > 0 && v26 > 0 )
      _V_memmove(dest: &m_pMemory[v26], src: m_pMemory, count: m_Size - v26);
  }
  memset(dst: m_pMemory, value: 0, count: m_Size);
  v27 = *(_DWORD *)(z + 72) <= 0;
  ndx = 0;
  if ( !v27 )
  {
    v75 = nullptr;
    do
    {
      v29 = (float *)((char *)v75 + *(_DWORD *)(z + 76));
      for ( j = 0; j < 3; ++j )
      {
        v31 = *v29;
        voxelMin[j] = (int)(float)((float)(*v29 - patchSampleRadius) * 0.015625);
        voxelMax[j] = 1 - (int)(float)((float)(v31 + patchSampleRadius) * -0.015625);
        ++v29;
      }
      v32 = voxelMin[0];
      x = voxelMin[0];
      if ( voxelMin[0] < voxelMax[0] )
      {
        v33 = voxelMin[2];
        v34 = voxelMin[1];
        v35 = voxelMax[1];
        do
        {
          y = v34;
          if ( v34 < v35 )
          {
            do
            {
              if ( v33 < voxelMax[2] )
              {
                v36 = allVoxelSize[0] * allVoxelSize[1];
                v37 = v32
                    + allVoxelSize[0] * (v34 + allVoxelSize[1] * (v33 - allVoxelMin[2]) - allVoxelMin[1])
                    - allVoxelMin[0];
                v38 = voxelMax[2] - v33;
                do
                {
                  v39 = &voxelBits.m_Memory.m_pMemory[v37 >> 3];
                  v40 = 1 << (v37 & 7);
                  v37 += v36;
                  *v39 |= v40;
                  --v38;
                }
                while ( v38 != 0 );
                v32 = x;
                v34 = y;
                v35 = voxelMax[1];
                v33 = voxelMin[2];
              }
              y = ++v34;
            }
            while ( v34 < v35 );
            v34 = voxelMin[1];
          }
          x = ++v32;
        }
        while ( v32 < voxelMax[0] );
      }
      v75 = (CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *)((char *)v75 + 12);
      ++ndx;
    }
    while ( ndx < *(_DWORD *)(z + 72) );
  }
  v41 = IncrementPatchIterationKey();
  v42 = allVoxelSize[0];
  x = v41;
  v43 = nullptr;
  v75 = nullptr;
  if ( allVoxelSize[0] > 0 )
  {
    v45 = allVoxelSize[1];
    v46 = allVoxelSize[2];
    do
    {
      ya = 0;
      if ( v45 > 0 )
      {
        interestingPatchesa = v43;
        do
        {
          LOWORD(v47) = 0;
          z = 0;
          if ( v46 > 0 )
          {
            v69 = v42 * v45;
            v48 = (int)interestingPatchesa;
            v72 = interestingPatchesa;
            do
            {
              if ( ((unsigned __int8)(1 << (v48 & 7)) & voxelBits.m_Memory.m_pMemory[v48 >> 3]) != 0 )
              {
                patchData.x = 100 * ((_WORD)v75 + LOWORD(allVoxelMin[0]));
                patchData.y = 10 * (ya + LOWORD(allVoxelMin[1]));
                patchData.z = v47 + LOWORD(allVoxelMin[2]);
                memset(&patchData.m_ndxPatches, 0, sizeof(patchData.m_ndxPatches));
                ndx = 0;
                if ( CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::DoFind(
                       this: &g_PatchSampleHashTable,
                       src: &patchData,
                       &pBucket,
                       pIndex: &ndx) != 0 )
                {
                  v49 = ndx | (pBucket << 16);
                  if ( v49 != -1 )
                  {
                    v50 = &g_PatchSampleHashTable.m_Buckets.m_Memory.m_pMemory[HIWORD(v49)].m_Memory.m_pMemory[(unsigned __int16)ndx];
                    v51 = 0;
                    pPatchData = v50;
                    ndx = 0;
                    if ( v50->m_ndxPatches.m_Size > 0 )
                    {
                      while ( 1 )
                      {
                        v52 = &g_Patches.m_Memory.m_pMemory[v50->m_ndxPatches.m_Memory.m_pMemory[v51]];
                        if ( v52 != nullptr && v52->m_IterationKey != (_WORD)x )
                        {
                          faceNumber = v52->faceNumber;
                          v52->m_IterationKey = x;
                          if ( ndxFace == faceNumber )
                            goto LABEL_58;
                          numneighbors = faceneighbor[ndxFace].numneighbors;
                          v55 = 0;
                          if ( numneighbors > 0 )
                            break;
                        }
LABEL_64:
                        v50 = pPatchData;
                        v51 = ndx + 1;
                        ndx = v51;
                        if ( v51 >= pPatchData->m_ndxPatches.m_Size )
                          goto LABEL_65;
                      }
                      neighbor = faceneighbor[ndxFace].neighbor;
                      while ( *neighbor != faceNumber )
                      {
                        ++v55;
                        ++neighbor;
                        if ( v55 >= numneighbors )
                          goto LABEL_64;
                      }
LABEL_58:
                      v57 = interestingPatches->m_Size;
                      m_nAllocationCount = interestingPatches->m_Memory.m_nAllocationCount;
                      if ( v57 + 1 > m_nAllocationCount )
                        CUtlMemory<int,int>::Grow(
                          this: (CUtlMemory<S3RGBA,int> *)interestingPatches,
                          num: v57 - m_nAllocationCount + 1);
                      ++interestingPatches->m_Size;
                      v59 = interestingPatches->m_Memory.m_pMemory;
                      v60 = interestingPatches->m_Size - v57 - 1;
                      interestingPatches->m_pElements = interestingPatches->m_Memory.m_pMemory;
                      if ( v60 > 0 )
                        _V_memmove(dest: &v59[v57 + 1], src: &v59[v57], count: 4 * v60);
                      v61 = &interestingPatches->m_Memory.m_pMemory[v57];
                      if ( v61 != nullptr )
                        *v61 = v52;
                      goto LABEL_64;
                    }
                  }
                }
LABEL_65:
                v62 = patchData.m_ndxPatches.m_Memory.m_pMemory;
                patchData.m_ndxPatches.m_Size = 0;
                if ( patchData.m_ndxPatches.m_Memory.m_nGrowSize >= 0 )
                {
                  if ( patchData.m_ndxPatches.m_Memory.m_pMemory != nullptr )
                  {
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: patchData.m_ndxPatches.m_Memory.m_pMemory);
                    v62 = nullptr;
                    patchData.m_ndxPatches.m_Memory.m_pMemory = nullptr;
                  }
                  patchData.m_ndxPatches.m_Memory.m_nAllocationCount = 0;
                }
                patchData.m_ndxPatches.m_pElements = v62;
                if ( patchData.m_ndxPatches.m_Memory.m_nGrowSize >= 0 && v62 != nullptr )
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v62);
              }
              v48 = (int)v72 + v69;
              v46 = allVoxelSize[2];
              v47 = z + 1;
              z = v47;
              v72 = (CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *)((char *)v72 + v69);
            }
            while ( v47 < allVoxelSize[2] );
            v45 = allVoxelSize[1];
            v42 = allVoxelSize[0];
          }
          ++ya;
          interestingPatchesa = (CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *)((char *)interestingPatchesa + v42);
        }
        while ( ya < v45 );
        v43 = v75;
      }
      v43 = (CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > *)((char *)v43 + 1);
      v75 = v43;
    }
    while ( (int)v43 < v42 );
  }
  if ( voxelBits.m_Memory.m_nGrowSize >= 0 && voxelBits.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: voxelBits.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10029F00
// Name: private: void CVRadDispMgr::RadialPatchBuild(class CVRADDispColl __near *,struct radial_s __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRadDispMgr::RadialPatchBuild(
        CVRadDispMgr *this,
        CVRADDispColl *pDispTree,
        radial_s *pRadial,
        bool bBump)
{
  float patchSampleRadius; // xmm0_4
  int v5; // edi
  facelight_t *v6; // esi
  radial_s *v7; // ecx
  int v8; // ebx
  int m_iParent; // [esp+Ch] [ebp-34h]
  CUtlVector<CPatch *,CUtlMemory<CPatch *,int> > interestingPatches; // [esp+20h] [ebp-20h] BYREF
  int radialSize; // [esp+34h] [ebp-Ch]
  CVRadDispMgr *v12; // [esp+38h] [ebp-8h]
  int ndxFace; // [esp+3Ch] [ebp-4h]

  patchSampleRadius = fsqrt(pDispTree->m_flPatchSampleRadius2);
  v5 = 0;
  m_iParent = pDispTree->m_iParent;
  v12 = this;
  ndxFace = m_iParent;
  v6 = &facelight[m_iParent];
  memset(&interestingPatches, 0, sizeof(interestingPatches));
  CVRadDispMgr::GetInterestingPatchesForLuxels(this, ndxFace: m_iParent, &interestingPatches, patchSampleRadius);
  v7 = pRadial;
  radialSize = pRadial->w * pRadial->h;
  if ( radialSize > 0 )
  {
    v8 = 0;
    while ( 1 )
    {
      CVRadDispMgr::RadialLuxelAddPatch(
        this: v12,
        ndxFace,
        luxelPt: &v6->luxel[v8],
        luxelNormal: &v6->luxelNormals[v8],
        radius: patchSampleRadius,
        pRadial: v7,
        ndxRadial: v5++,
        bBump,
        &interestingPatches);
      ++v8;
      if ( v5 >= radialSize )
        break;
      v7 = pRadial;
    }
  }
  if ( interestingPatches.m_Memory.m_nGrowSize >= 0 && interestingPatches.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: interestingPatches.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10029FD0
// Name: public: virtual struct radial_s __near * CVRadDispMgr::BuildPatchRadial(int,bool)
// Source: json
//------------------------------------------------------------------------------
radial_s *__thiscall CVRadDispMgr::BuildPatchRadial(CVRadDispMgr *this, int ndxFace, bool bBump)
{
  radial_s *Radial; // edi
  CVRADDispColl *m_pDispTree; // eax

  Radial = AllocateRadial(facenum: ndxFace);
  if ( Radial == nullptr )
    return nullptr;
  m_pDispTree = this->m_DispTrees.m_Memory.m_pMemory[g_pFaces[ndxFace].dispinfo].m_pDispTree;
  if ( m_pDispTree == nullptr )
    return nullptr;
  CVRadDispMgr::RadialPatchBuild(this, pDispTree: m_pDispTree, pRadial: Radial, bBump);
  return Radial;
}

//------------------------------------------------------------------------------
// Address: 0x1002A030
// Name: __CreateCVRadDLLIVRadDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVRadDLL *__cdecl _CreateCVRadDLLIVRadDLL_interface()
{
  return &g_VRadDLL;
}

//------------------------------------------------------------------------------
// Address: 0x1002A040
// Name: __CreateCVRadDLLILaunchableDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ILaunchableDLL *__cdecl _CreateCVRadDLLILaunchableDLL_interface()
{
  return &g_VRadDLL.ILaunchableDLL;
}
