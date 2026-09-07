// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/r_studioflex.cpp
// Functions: 17
// ============================================================

#include "studiorender\r_studioflex.h"

//------------------------------------------------------------------------------
// Address: 0x10011740
// Name: private: void CStudioRender::R_StudioEyeballPosition(struct mstudioeyeball_t const __near *,struct eyeballstate_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioEyeballPosition(
        CStudioRender *this,
        const mstudioeyeball_t *peyeball,
        eyeballstate_t *pstate)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  int v6; // eax
  StudioRenderContext_t *m_pRC; // edx
  int v8; // eax
  int v9; // eax
  Vector *p_up; // edi
  float *p_fEyeShiftX; // eax
  Vector *p_forward; // esi
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  const matrix3x4_t *v16; // [esp-14h] [ebp-24h]
  Vector tmp; // [esp+0h] [ebp-10h] BYREF
  CStudioRender *v18; // [esp+Ch] [ebp-4h]

  pstate->peyeball = peyeball;
  x = peyeball->org.x;
  y = peyeball->org.y;
  z = peyeball->org.z;
  v18 = this;
  tmp.x = x;
  tmp.y = y;
  tmp.z = z;
  if ( x >= 0.0 )
    v6 = x > 0.0;
  else
    v6 = -1;
  m_pRC = this->m_pRC;
  tmp.x = (float)((float)v6 * m_pRC->m_Config.fEyeShiftX) + x;
  if ( y >= 0.0 )
    v8 = y > 0.0;
  else
    v8 = -1;
  tmp.y = (float)((float)v8 * m_pRC->m_Config.fEyeShiftY) + y;
  if ( z >= 0.0 )
    v9 = z > 0.0;
  else
    v9 = -1;
  v16 = &this->m_pBoneToWorld[peyeball->bone];
  tmp.z = (float)((float)v9 * m_pRC->m_Config.fEyeShiftZ) + z;
  VectorTransform(in1: &tmp.x, in2: v16, out: &pstate->org.x);
  p_up = &pstate->up;
  VectorRotate(in1: &peyeball->up.x, in2: &v18->m_pBoneToWorld[peyeball->bone], out: &pstate->up.x);
  p_fEyeShiftX = &v18->m_pRC->m_Config.fEyeShiftX;
  p_forward = &pstate->forward;
  pstate->forward.x = p_fEyeShiftX[15] - pstate->org.x;
  pstate->forward.y = p_fEyeShiftX[16] - pstate->org.y;
  pstate->forward.z = p_fEyeShiftX[17] - pstate->org.z;
  VectorNormalize(vec: &pstate->forward);
  if ( (*((_BYTE *)&v18->m_pRC->m_Config.StudioRenderConfig_t + 36) & 1) == 0 )
  {
    VectorRotate(in1: &peyeball->forward.x, in2: &v18->m_pBoneToWorld[peyeball->bone], out: &p_forward->x);
    p_forward->x = p_forward->x * -1.0;
    pstate->forward.y = pstate->forward.y * -1.0;
    pstate->forward.z = pstate->forward.z * -1.0;
  }
  pstate->right.x = (float)(pstate->forward.y * pstate->up.z) - (float)(pstate->forward.z * pstate->up.y);
  pstate->right.y = (float)(pstate->up.x * pstate->forward.z) - (float)(pstate->forward.x * pstate->up.z);
  pstate->right.z = (float)(pstate->up.y * pstate->forward.x) - (float)(pstate->forward.y * pstate->up.x);
  VectorNormalize(vec: &pstate->right);
  v13 = peyeball->zoffset * 2.0;
  p_forward->x = (float)(pstate->right.x * v13) + p_forward->x;
  pstate->forward.y = (float)(v13 * pstate->right.y) + pstate->forward.y;
  pstate->forward.z = (float)(pstate->right.z * v13) + pstate->forward.z;
  VectorNormalize(vec: p_forward);
  pstate->right.x = (float)(pstate->forward.y * pstate->up.z) - (float)(pstate->forward.z * pstate->up.y);
  pstate->right.y = (float)(pstate->up.x * pstate->forward.z) - (float)(pstate->forward.x * pstate->up.z);
  pstate->right.z = (float)(pstate->up.y * pstate->forward.x) - (float)(pstate->forward.y * pstate->up.x);
  VectorNormalize(vec: &pstate->right);
  p_up->x = (float)(pstate->forward.z * pstate->right.y) - (float)(pstate->forward.y * pstate->right.z);
  pstate->up.y = (float)(pstate->right.z * pstate->forward.x) - (float)(pstate->forward.z * pstate->right.x);
  pstate->up.z = (float)(pstate->forward.y * pstate->right.x) - (float)(pstate->forward.x * pstate->right.y);
  VectorNormalize(vec: p_up);
  v14 = 1.0 / peyeball->iris_scale + v18->m_pRC->m_Config.fEyeSize;
  if ( v14 > 0.0 )
    v14 = 1.0 / v14;
  LODWORD(v15) = LODWORD(v14) ^ _mask__NegFloat_;
  pstate->mat.m_flMatVal[0][0] = v15 * pstate->right.x;
  pstate->mat.m_flMatVal[0][1] = v15 * pstate->right.y;
  pstate->mat.m_flMatVal[0][2] = v15 * pstate->right.z;
  pstate->mat.m_flMatVal[1][0] = p_up->x * v15;
  pstate->mat.m_flMatVal[1][1] = v15 * pstate->up.y;
  pstate->mat.m_flMatVal[1][2] = v15 * pstate->up.z;
  pstate->mat.m_flMatVal[0][3] = 0.5
                               - (float)((float)((float)(pstate->org.x * pstate->mat.m_flMatVal[0][0])
                                               + (float)(pstate->mat.m_flMatVal[0][1] * pstate->org.y))
                                       + (float)(pstate->org.z * pstate->mat.m_flMatVal[0][2]));
  pstate->mat.m_flMatVal[1][3] = 0.5
                               - (float)((float)((float)(pstate->mat.m_flMatVal[1][1] * pstate->org.y)
                                               + (float)(pstate->mat.m_flMatVal[1][0] * pstate->org.x))
                                       + (float)(pstate->org.z * pstate->mat.m_flMatVal[1][2]));
}

//------------------------------------------------------------------------------
// Address: 0x10011B50
// Name: private: float CStudioRender::RampFlexWeight(struct mstudioflex_t __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CStudioRender::RampFlexWeight(CStudioRender *this, mstudioflex_t *flex, float w)
{
  float target1; // xmm1_4
  float target2; // xmm2_4

  if ( flex->target0 >= w || w >= flex->target3 )
    return 0.0;
  target1 = flex->target1;
  if ( target1 > w )
    return (float)((float)(w - flex->target0) / (float)(target1 - flex->target0));
  target2 = flex->target2;
  if ( w <= target2 )
    return 1.0;
  else
    return (float)((float)(flex->target3 - w) / (float)(flex->target3 - target2));
}

//------------------------------------------------------------------------------
// Address: 0x10011BE0
// Name: public: void CStudioRender::PrecacheGlint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::PrecacheGlint(CStudioRender *this)
{
  ITexture *v2; // eax
  ITexture *v3; // eax
  ITexture v4; // edx
  ITexture *v5; // eax

  if ( this->m_pGlintTexture == nullptr )
  {
    v2 = materials->FindTexture(this: materials, a2: "_rt_eyeglint", a3: "RenderTargets", a4: 1, a5: 0);
    this->m_pGlintTexture = v2;
    if ( v2 == nullptr || v2->IsError(this: v2) )
    {
      g_pMaterialSystem->BeginRenderTargetAllocation(this: g_pMaterialSystem);
      this->m_pGlintTexture = g_pMaterialSystem->CreateNamedRenderTargetTextureEx2(
                                this: g_pMaterialSystem,
                                a2: "_rt_eyeglint",
                                a3: 32,
                                a4: 32,
                                a5: 0,
                                a6: 12,
                                a7: 2,
                                a8: 12,
                                a9: 0);
      g_pMaterialSystem->EndRenderTargetAllocation(this: g_pMaterialSystem);
    }
    this->m_pGlintTexture->IncrementReferenceCount(this: this->m_pGlintTexture);
    v3 = g_pMaterialSystem->CreateProceduralTexture(
           this: g_pMaterialSystem,
           a2: "proc_eyeglint",
           a3: "Model textures",
           a4: 32,
           a5: 32,
           a6: 12,
           a7: 768);
    v4.__vftable = v3->__vftable;
    s_pProcGlint = v3;
    v4.SetTextureRegenerator(this: v3, a2: &s_GlintTextureRegen, a3: true);
    v5 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "vgui/black", a3: 0, a4: 0, a5: 0);
    this->m_pGlintLODTexture = v5;
    v5->IncrementReferenceCount(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011CF0
// Name: public: void CStudioRender::UncacheGlint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::UncacheGlint(CStudioRender *this)
{
  ITexture *m_pGlintLODTexture; // ecx

  if ( this->m_pGlintTexture != nullptr )
  {
    if ( s_pProcGlint != nullptr )
    {
      s_pProcGlint->SetTextureRegenerator(this: s_pProcGlint, a2: nullptr, a3: true);
      s_pProcGlint->DecrementReferenceCount(this: s_pProcGlint);
      s_pProcGlint = nullptr;
    }
    this->m_pGlintTexture->DecrementReferenceCount(this: this->m_pGlintTexture);
    m_pGlintLODTexture = this->m_pGlintLODTexture;
    this->m_pGlintTexture = nullptr;
    m_pGlintLODTexture->DecrementReferenceCount(this: m_pGlintLODTexture);
    this->m_pGlintLODTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011D60
// Name: private: int CStudioRender::BuildGlintRenderData(struct CStudioRender::GlintRenderData_t __near *,int,struct eyeballstate_t const __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CStudioRender::BuildGlintRenderData@<eax>(
        CStudioRender *this@<ecx>,
        int a2@<ebp>,
        CStudioRender::GlintRenderData_t *pData,
        int nMaxGlints,
        const eyeballstate_t *pState,
        const Vector *vright,
        const Vector *vup,
        const Vector *r_origin)
{
  float v8; // xmm0_4
  const mstudioeyeball_t *peyeball; // eax
  float radius; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float y; // xmm0_4
  float v21; // xmm0_4
  float x; // xmm2_4
  float v23; // ecx
  float z; // xmm1_4
  int result; // eax
  float v26; // xmm4_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  const mstudioeyeball_t *v31; // eax
  float v32; // ecx
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm3_4
  float v36; // [esp-28h] [ebp-7Ch]
  Vector v37; // [esp-Ch] [ebp-60h] BYREF
  Vector cornea; // [esp+0h] [ebp-54h] BYREF
  Vector viewdelta; // [esp+Ch] [ebp-48h] BYREF
  Vector intensity; // [esp+18h] [ebp-3Ch] BYREF
  Vector reflection; // [esp+24h] [ebp-30h] BYREF
  Vector delta; // [esp+30h] [ebp-24h]
  CStudioRender *dy; // [esp+3Ch] [ebp-18h]
  float v44; // [esp+40h] [ebp-14h]
  float cornea_radius; // [esp+44h] [ebp-10h]
  int v46; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int retaddr; // [esp+54h] [ebp+0h]

  v46 = a2;
  i = retaddr;
  cornea.x = r_origin->x - pState->org.x;
  cornea.y = r_origin->y - pState->org.y;
  v8 = r_origin->z - pState->org.z;
  dy = this;
  cornea.z = v8;
  VectorNormalize(vec: &cornea);
  peyeball = pState->peyeball;
  radius = pState->peyeball->radius;
  v11 = radius * 0.6666666666666666;
  v12 = radius * 0.5;
  v44 = (float)(v12 / radius) * (float)(v12 / radius);
  v36 = fsqrt(1.0 - v44);
  v13 = (float)(peyeball->radius * v36) - (float)(fsqrt(1.0 - (float)((float)(v12 / v11) * (float)(v12 / v11))) * v11);
  v14 = pState->forward.x * v13;
  v15 = pState->forward.y * v13;
  delta.z = v11;
  v16 = pState->forward.z * v13;
  delta.y = (float)((float)(vright->y * v15) + (float)(vright->x * v14)) + (float)(vright->z * v16);
  v17 = vup->x * v14;
  v18 = v14 + pState->org.x;
  delta.x = (float)(v17 + (float)(v15 * vup->y)) + (float)(v16 * vup->z);
  y = pState->org.y;
  v37.x = v18;
  v37.y = y + v15;
  v37.z = pState->org.z + v16;
  cornea_radius = 0.0;
  v44 = 0.0;
  if ( CStudioRender::R_LightGlintPosition(this: dy, index: 0, org: &v37, delta: &reflection, intensity: &viewdelta) == 0 )
    return LODWORD(cornea_radius);
  while ( 1 )
  {
    VectorNormalize(vec: &reflection);
    if ( (float)((float)((float)(pState->forward.y * reflection.y) + (float)(pState->forward.x * reflection.x))
               + (float)(pState->forward.z * reflection.z)) > 0.0 )
    {
      intensity.x = reflection.x + cornea.x;
      intensity.y = reflection.y + cornea.y;
      intensity.z = reflection.z + cornea.z;
      VectorNormalize(vec: &intensity);
      v21 = intensity.y;
      x = intensity.x;
      v23 = cornea_radius;
      z = intensity.z;
      pData->m_vecPosition.x = (float)((float)((float)((float)(vright->y * intensity.y)
                                                     + (float)(vright->x * intensity.x))
                                             + (float)(vright->z * intensity.z))
                                     * delta.z)
                             + delta.y;
      result = nMaxGlints;
      v26 = (float)(vup->x * x) + (float)(v21 * vup->y);
      v27 = viewdelta.x;
      pData->m_vecPosition.y = (float)((float)(v26 + (float)(z * vup->z)) * delta.z) + delta.x;
      pData->m_vecIntensity.x = v27;
      pData->m_vecIntensity.y = viewdelta.y;
      pData->m_vecIntensity.z = viewdelta.z;
      ++pData;
      LODWORD(cornea_radius) = LODWORD(v23) + 1;
      if ( LODWORD(v23) + 1 >= nMaxGlints )
        break;
      if ( CStudioRender::R_LightGlintPosition(
             this: dy,
             index: SLODWORD(v44),
             org: &pState->org,
             delta: &reflection,
             intensity: &viewdelta) != 0 )
      {
        VectorNormalize(vec: &reflection);
        if ( (float)((float)((float)(pState->forward.y * reflection.y) + (float)(pState->forward.x * reflection.x))
                   + (float)(pState->forward.z * reflection.z)) < v36 )
        {
          v28 = intensity.y;
          v29 = intensity.x;
          v30 = intensity.z;
          v31 = pState->peyeball;
          pData->m_vecPosition.x = (float)((float)((float)(vright->y * intensity.y) + (float)(vright->x * intensity.x))
                                         + (float)(vright->z * intensity.z))
                                 * pState->peyeball->radius;
          v32 = cornea_radius;
          v33 = (float)(vup->x * v29) + (float)(v28 * vup->y);
          v34 = viewdelta.x;
          v35 = (float)(v33 + (float)(v30 * vup->z)) * v31->radius;
          result = nMaxGlints;
          pData->m_vecPosition.y = v35;
          pData->m_vecIntensity.x = v34;
          pData->m_vecIntensity.y = viewdelta.y;
          pData->m_vecIntensity.z = viewdelta.z;
          ++pData;
          LODWORD(cornea_radius) = LODWORD(v32) + 1;
          if ( LODWORD(v32) + 1 >= nMaxGlints )
            break;
        }
      }
    }
    ++LODWORD(v44);
    if ( CStudioRender::R_LightGlintPosition(
           this: dy,
           index: SLODWORD(v44),
           org: &v37,
           delta: &reflection,
           intensity: &viewdelta) == 0 )
      return LODWORD(cornea_radius);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012150
// Name: private: void CStudioRender::ComputeGlintTextureProjection(struct eyeballstate_t const __near *,class Vector const __near &,class Vector const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::ComputeGlintTextureProjection(
        CStudioRender *this,
        const eyeballstate_t *pState,
        const Vector *vright,
        const Vector *vup,
        matrix3x4_t *mat)
{
  float v5; // xmm0_4

  v5 = 1.0 / (float)(pState->peyeball->radius * 2.0);
  mat->m_flMatVal[0][0] = vright->x * v5;
  mat->m_flMatVal[0][1] = vright->y * v5;
  mat->m_flMatVal[0][2] = vright->z * v5;
  mat->m_flMatVal[1][0] = vup->x * v5;
  mat->m_flMatVal[1][1] = vup->y * v5;
  mat->m_flMatVal[1][2] = vup->z * v5;
  mat->m_flMatVal[0][3] = 0.5
                        - (float)((float)((float)(pState->org.y * mat->m_flMatVal[0][1])
                                        + (float)(pState->org.x * mat->m_flMatVal[0][0]))
                                + (float)(pState->org.z * mat->m_flMatVal[0][2]));
  mat->m_flMatVal[1][3] = 0.5
                        - (float)((float)((float)(pState->org.x * mat->m_flMatVal[1][0])
                                        + (float)(pState->org.y * mat->m_flMatVal[1][1]))
                                + (float)(pState->org.z * mat->m_flMatVal[1][2]));
}

//------------------------------------------------------------------------------
// Address: 0x10012240
// Name: public: void CStudioRender::R_MouthComputeLightingValues(float __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_MouthComputeLightingValues(CStudioRender *this, float *fIllum, Vector *forward)
{
  int v3; // xmm1_4
  char *v5; // esi
  float v6; // xmm0_4

  v3 = 0;
  v5 = (char *)this->m_pStudioHdr + this->m_pStudioHdr->mouthindex;
  v6 = this->m_pFlexWeights[*((_DWORD *)v5 + 4)];
  *fIllum = v6;
  if ( v6 < 0.0 || (v3 = 1065353216, v6 > 1.0) )
    *(_DWORD *)fIllum = v3;
  *fIllum = (double)LinearToTexture(f: *fIllum) * 0.00392156862745098;
  VectorRotate(in1: (const float *)v5 + 1, in2: &this->m_pBoneToWorld[*(_DWORD *)v5], out: &forward->x);
}

//------------------------------------------------------------------------------
// Address: 0x100122D0
// Name: private: void CStudioRender::R_MouthSetupVertexShader(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_MouthSetupVertexShader(CStudioRender *this, IMaterial *pMaterial)
{
  int v3; // xmm1_4
  char *v4; // eax
  float v5; // xmm0_4
  IMaterialVar *(__thiscall *FindVarFast)(IMaterial *, const char *, unsigned int *); // edx
  int v7; // eax
  IMaterialVar *v8; // eax
  Vector forward; // [esp+10h] [ebp-Ch] BYREF
  float fIllum; // [esp+24h] [ebp+8h]

  if ( pMaterial != nullptr )
  {
    v3 = 0;
    v4 = (char *)this->m_pStudioHdr + this->m_pStudioHdr->mouthindex;
    v5 = this->m_pFlexWeights[*((_DWORD *)v4 + 4)];
    fIllum = v5;
    if ( v5 < 0.0 || (v3 = 1065353216, v5 > 1.0) )
      fIllum = *(float *)&v3;
    VectorRotate(in1: (const float *)v4 + 1, in2: &this->m_pBoneToWorld[*(_DWORD *)v4], out: &forward.x);
    FindVarFast = pMaterial->FindVarFast;
    forward.x = forward.x * -1.0;
    forward.y = forward.y * -1.0;
    forward.z = forward.z * -1.0;
    v7 = (int)FindVarFast(this: pMaterial, a2: "$illumfactor", a3: &illumVarCache);
    if ( v7 != 0 )
      (*(void (__thiscall **)(int, float))(*(_DWORD *)v7 + 16))(a1: v7, a2: COERCE_FLOAT(LODWORD(fIllum)));
    v8 = pMaterial->FindVarFast(this: pMaterial, a2: "$forward", a3: &forwardVarCache);
    if ( v8 != nullptr )
      v8->SetVecValue_4(this: v8, a2: &forward.x, a3: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100123D0
// Name: private: void CStudioRender::R_StudioEyelidFACS(struct mstudioeyeball_t const __near *,struct eyeballstate_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::R_StudioEyelidFACS(
        CStudioRender *this@<ecx>,
        int a2@<edi>,
        float peyeball,
        const eyeballstate_t *pstate)
{
  const mstudioeyeball_t *v4; // esi
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float *m_pFlexWeights; // edi
  double v12; // xmm0_8
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  double v17; // xmm0_8
  const eyeballstate_t *v18; // edi
  float *v19; // ebx
  long double v20; // [esp-4h] [ebp-40h]
  long double v21; // [esp-4h] [ebp-40h]
  long double v22; // [esp-4h] [ebp-40h]
  long double v23; // [esp-4h] [ebp-40h]
  long double v24; // [esp-4h] [ebp-40h]
  long double v25; // [esp-4h] [ebp-40h]
  Vector headforward; // [esp+8h] [ebp-34h] BYREF
  Vector headup; // [esp+14h] [ebp-28h] BYREF
  float lowerlid; // [esp+20h] [ebp-1Ch]
  float upperlid; // [esp+24h] [ebp-18h]
  float *p_coslower; // [esp+28h] [ebp-14h]
  float *p_peyeball; // [esp+2Ch] [ebp-10h]
  float coslower; // [esp+30h] [ebp-Ch] BYREF
  float sinlower; // [esp+34h] [ebp-8h] BYREF
  float cosupper; // [esp+38h] [ebp-4h]

  v4 = (const mstudioeyeball_t *)LODWORD(peyeball);
  if ( *(_BYTE *)(LODWORD(peyeball) + 140) == 0 )
  {
    v6 = *(float *)(LODWORD(peyeball) + 100);
    v7 = 1.0 / *(float *)(LODWORD(peyeball) + 24);
    v8 = v7 * *(float *)(LODWORD(peyeball) + 92);
    v9 = v7 * *(float *)(LODWORD(peyeball) + 96);
    cosupper = v7;
    v10 = v7 * v6;
    if ( v8 >= -1.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
    }
    else
    {
      v8 = -1.0;
    }
    if ( v9 >= -1.0 )
    {
      if ( v9 <= 1.0 )
        peyeball = v9;
      else
        peyeball = 1.0;
    }
    else
    {
      peyeball = -1.0;
    }
    if ( v10 >= -1.0 )
    {
      if ( v10 <= 1.0 )
        coslower = v10;
      else
        coslower = 1.0;
    }
    else
    {
      coslower = -1.0;
    }
    LODWORD(v20) = a2;
    m_pFlexWeights = this->m_pFlexWeights;
    __libm_sse2_asin(x: v20);
    sinlower = v8 * m_pFlexWeights[v4->upperflexdesc[0]];
    v12 = peyeball;
    __libm_sse2_asin(x: v21);
    *(float *)&v12 = v12;
    peyeball = sinlower + (float)(*(float *)&v12 * m_pFlexWeights[v4->upperflexdesc[1]]);
    __libm_sse2_asin(x: v22);
    v13 = v4->lowertarget[2];
    upperlid = peyeball + (float)(coslower * m_pFlexWeights[v4->upperflexdesc[2]]);
    v14 = cosupper * v4->lowertarget[0];
    v15 = cosupper * v4->lowertarget[1];
    v16 = cosupper * v13;
    if ( v14 >= -1.0 )
    {
      if ( v14 > 1.0 )
        v14 = 1.0;
    }
    else
    {
      v14 = -1.0;
    }
    if ( v15 >= -1.0 )
    {
      if ( v15 <= 1.0 )
        peyeball = cosupper * v4->lowertarget[1];
      else
        peyeball = 1.0;
    }
    else
    {
      peyeball = -1.0;
    }
    if ( v16 >= -1.0 )
    {
      if ( v16 <= 1.0 )
        coslower = cosupper * v13;
      else
        coslower = 1.0;
    }
    else
    {
      coslower = -1.0;
    }
    __libm_sse2_asin(x: v23);
    sinlower = v14 * m_pFlexWeights[v4->lowerflexdesc[0]];
    v17 = peyeball;
    __libm_sse2_asin(x: v24);
    *(float *)&v17 = v17;
    peyeball = sinlower + (float)(*(float *)&v17 * m_pFlexWeights[v4->lowerflexdesc[1]]);
    __libm_sse2_asin(x: v25);
    lowerlid = peyeball + (float)(coslower * m_pFlexWeights[v4->lowerflexdesc[2]]);
    p_peyeball = &peyeball;
    cosupper = cos(upperlid);
    peyeball = sin(upperlid);
    p_coslower = &coslower;
    upperlid = COERCE_FLOAT(&sinlower);
    coslower = cos(lowerlid);
    sinlower = sin(lowerlid);
    v18 = pstate;
    VectorIRotate(in1: &pstate->up.x, in2: &this->m_pBoneToWorld[v4->bone], out: &headup.x);
    VectorIRotate(in1: &v18->forward.x, in2: &this->m_pBoneToWorld[v4->bone], out: &headforward.x);
    v19 = this->m_pFlexWeights;
    v19[v4->upperlidflexdesc] = (float)((float)(v4->up.y
                                              * (float)((float)(headforward.y * (float)(v4->radius * cosupper))
                                                      + (float)(headup.y * (float)(v4->radius * peyeball))))
                                      + (float)((float)((float)(headforward.x * (float)(v4->radius * cosupper))
                                                      + (float)(headup.x * (float)(v4->radius * peyeball)))
                                              * v4->up.x))
                              + (float)(v4->up.z
                                      * (float)((float)(headforward.z * (float)(v4->radius * cosupper))
                                              + (float)(headup.z * (float)(v4->radius * peyeball))));
    *(float *)&v17 = v4->radius * sinlower;
    v19[v4->lowerlidflexdesc] = (float)((float)(v4->up.y
                                              * (float)((float)(headforward.y * (float)(v4->radius * coslower))
                                                      + (float)(headup.y * *(float *)&v17)))
                                      + (float)((float)((float)(headforward.x * (float)(v4->radius * coslower))
                                                      + (float)(headup.x * *(float *)&v17))
                                              * v4->up.x))
                              + (float)(v4->up.z
                                      * (float)((float)(headforward.z * (float)(v4->radius * coslower))
                                              + (float)(headup.z * *(float *)&v17)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012740
// Name: private: void CStudioRender::R_StudioFlexVerts(struct mstudiomesh_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioFlexVerts(CStudioRender *this, mstudiomesh_t *pmesh, int lod, bool bQuadList)
{
  studiohdr_t *m_pStudioHdr; // eax
  int flVertAnimFixedPointScale_low; // xmm0_4
  mstudiomesh_t *v7; // edi
  const mstudio_modelvertexdata_t *v8; // eax
  mstudio_meshvertexdata_t *p_vertexdata; // ebx
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  int vertexoffset; // esi
  int flexindex; // esi
  float v14; // xmm4_4
  char *v15; // edx
  float *m_pFlexWeights; // ecx
  float v17; // xmm7_4
  int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float *m_pFlexDelayedWeights; // esi
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  int v28; // eax
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm7_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  char v39; // al
  char *v40; // ebx
  int v41; // esi
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // eax
  float *weight; // edi
  CachedPosNormTan_t *FlexVertex; // eax
  double v45; // st7
  double v46; // st7
  Vector4D *v47; // edi
  int v48; // esi
  double x; // st7
  float *p_x; // esi
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  int v55; // ecx
  float v56; // xmm7_4
  float v57; // xmm1_4
  bool v58; // zf
  float v59; // xmm2_4
  float v60; // xmm3_4
  int nVAnimSizeBytes; // [esp+8h] [ebp-38h]
  mstudiovertex_t *pVertices; // [esp+Ch] [ebp-34h]
  int i; // [esp+14h] [ebp-2Ch]
  int j; // [esp+18h] [ebp-28h]
  float w3; // [esp+1Ch] [ebp-24h]
  float w4; // [esp+20h] [ebp-20h]
  CCachedRenderData *p_m_VertexCache; // [esp+24h] [ebp-1Ch]
  Vector4D *pStudioTangentS; // [esp+28h] [ebp-18h]
  char *v70; // [esp+2Ch] [ebp-14h]
  float flVertAnimFixedPointScale; // [esp+30h] [ebp-10h]
  float v72; // [esp+34h] [ebp-Ch]
  float v73; // [esp+38h] [ebp-8h]
  bool bWrinkleFlex; // [esp+3Fh] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStudioRender::R_StudioFlexVerts",
    a3: 0,
    a4: "Other_Model_Rendering",
    a5: false,
    a6: 4);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( (m_pStudioHdr->flags & 0x200000) != 0 )
    flVertAnimFixedPointScale_low = SLODWORD(m_pStudioHdr->flVertAnimFixedPointScale);
  else
    *(float *)&flVertAnimFixedPointScale_low = 0.00024414062;
  flVertAnimFixedPointScale = *(float *)&flVertAnimFixedPointScale_low;
  p_m_VertexCache = &this->m_VertexCache;
  if ( CCachedRenderData::IsFlexComputationDone(this: &this->m_VertexCache) )
    goto LABEL_82;
  v7 = pmesh;
  if ( mstudiomodel_t::CacheVertexData(
         this: (mstudiomodel_t *)((char *)pmesh + pmesh->modelindex),
         pModelData: this->m_pStudioHdr) == nullptr )
    goto LABEL_82;
  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pmesh + pmesh->modelindex),
    pModelData: this->m_pStudioHdr);
  v8 = (const mstudio_modelvertexdata_t *)((char *)&pmesh->unused[6] + pmesh->modelindex);
  p_vertexdata = &pmesh->vertexdata;
  pmesh->vertexdata.modelvertexdata = v8;
  if ( v8->pVertexData != nullptr && pmesh != (mstudiomesh_t *)-48 )
  {
    if ( (this->m_pStudioHdr->flags & 0x4000) == 0 )
    {
      v11 = flexConversionTimesWarned++;
      if ( v11 < 6 )
        _Warning(a1: "ERROR: flex verts have not been converted (queued loader refcount bug?) - expect to see 'exploded' faces");
    }
    vertexoffset = pmesh->vertexoffset;
    pVertices = (mstudiovertex_t *)((char *)p_vertexdata->modelvertexdata->pVertexData
                                  + 48 * vertexoffset
                                  + 48 * ((unsigned int)p_vertexdata->modelvertexdata[-3].pVertexData / 0x30));
    if ( p_vertexdata->modelvertexdata->pTangentData != nullptr )
      pStudioTangentS = (Vector4D *)((char *)p_vertexdata->modelvertexdata->pTangentData
                                   + 16 * vertexoffset
                                   + 16 * ((unsigned int)p_vertexdata->modelvertexdata[-3].pTangentData >> 4));
    else
      pStudioTangentS = nullptr;
    flexindex = pmesh->flexindex;
    CCachedRenderData::SetupComputation(this: p_m_VertexCache, pMesh: pmesh, flexComputation: true);
    i = 0;
    if ( pmesh->numflexes <= 0 )
      goto LABEL_81;
    v14 = *(float *)&flVertAnimFixedPointScale_low;
    v15 = (char *)&pmesh->modelindex + flexindex;
    v70 = v15;
    while ( 1 )
    {
      m_pFlexWeights = this->m_pFlexWeights;
      v17 = *(float *)v15;
      v18 = *((_DWORD *)v15 - 1);
      v19 = m_pFlexWeights[v18];
      if ( *(float *)v15 >= v19 || v19 >= *((float *)v15 + 3) )
      {
        v21 = 0.0;
      }
      else
      {
        v20 = *((float *)v15 + 1);
        if ( v20 <= v19 )
        {
          v22 = *((float *)v15 + 2);
          if ( v19 <= v22 )
            v73 = 1.0;
          else
            v73 = (float)(*((float *)v15 + 3) - v19) / (float)(*((float *)v15 + 3) - v22);
          goto LABEL_28;
        }
        v21 = (float)(v19 - v17) / (float)(v20 - v17);
      }
      v73 = v21;
LABEL_28:
      m_pFlexDelayedWeights = this->m_pFlexDelayedWeights;
      v24 = m_pFlexDelayedWeights[v18];
      if ( v17 >= v24 || v24 >= *((float *)v15 + 3) )
      {
        v26 = 0.0;
      }
      else
      {
        v25 = *((float *)v15 + 1);
        if ( v25 <= v24 )
        {
          v27 = *((float *)v15 + 2);
          if ( v24 <= v27 )
            v26 = 1.0;
          else
            v26 = (float)(*((float *)v15 + 3) - v24) / (float)(*((float *)v15 + 3) - v27);
        }
        else
        {
          v26 = (float)(v24 - *(float *)v15) / (float)(v25 - *(float *)v15);
        }
      }
      v28 = *((_DWORD *)v15 + 6);
      v72 = v26;
      if ( v28 != 0 )
      {
        v29 = m_pFlexWeights[v28];
        if ( v17 >= v29 || v29 >= *((float *)v15 + 3) )
        {
          v31 = 0.0;
        }
        else
        {
          v30 = *((float *)v15 + 1);
          if ( v30 <= v29 )
          {
            v32 = *((float *)v15 + 2);
            if ( v29 <= v32 )
              v31 = 1.0;
            else
              v31 = (float)(*((float *)v15 + 3) - v29) / (float)(*((float *)v15 + 3) - v32);
          }
          else
          {
            v31 = (float)(v29 - *(float *)v15) / (float)(v30 - *(float *)v15);
          }
        }
        v33 = m_pFlexDelayedWeights[v28];
        v34 = v31;
        w3 = v31;
        if ( *(float *)v15 >= v33 || v33 >= *((float *)v15 + 3) )
        {
          v37 = 0.0;
          v36 = v73;
        }
        else
        {
          v35 = *((float *)v15 + 1);
          if ( v35 <= v33 )
          {
            v38 = *((float *)v15 + 2);
            if ( v33 <= v38 )
            {
              v36 = v73;
              v37 = 1.0;
            }
            else
            {
              v37 = (float)(*((float *)v15 + 3) - v33) / (float)(*((float *)v15 + 3) - v38);
              v36 = v73;
            }
          }
          else
          {
            v36 = v73;
            v37 = (float)(v33 - *(float *)v15) / (float)(v35 - *(float *)v15);
          }
        }
      }
      else
      {
        v36 = v73;
        v34 = v73;
        w3 = v73;
        v37 = v26;
      }
      w4 = v37;
      if ( v36 <= -0.001
        || v36 >= 0.001
        || v26 <= -0.001
        || v26 >= 0.001
        || v34 <= -0.001
        || v34 >= 0.001
        || v37 <= -0.001
        || v37 >= 0.001 )
      {
        v39 = v15[28];
        bWrinkleFlex = v39 == 1;
        j = 0;
        nVAnimSizeBytes = 2 * (v39 != 0) + 16;
        if ( *((int *)v15 + 4) > 0 )
        {
          v40 = &v15[*((_DWORD *)v15 + 5) - 1];
          do
          {
            v41 = *(unsigned __int16 *)(v40 - 3);
            if ( v41 < v7->vertexdata.numLODVertexes[lod] )
            {
              m_pFirstFlexIndex = p_m_VertexCache->m_pFirstFlexIndex;
              weight = pVertices[v41].m_BoneWeights.weight;
              if ( m_pFirstFlexIndex != nullptr && m_pFirstFlexIndex[v41].m_Tag == p_m_VertexCache->m_CurrentTag )
              {
                v47 = pStudioTangentS;
                FlexVertex = &p_m_VertexCache->m_pFlexVerts[p_m_VertexCache->m_pFirstFlexIndex[v41].m_VertexIndex];
LABEL_71:
                v51 = (float)(unsigned __int8)*(v40 - 1) * 0.0039215689;
                v52 = (float)((float)((float)(v26 * (float)(1.0 - v51)) + (float)(v73 * v51))
                            * (float)(1.0 - (float)((float)(unsigned __int8)*v40 * 0.0039215689)))
                    + (float)((float)((float)((float)(1.0 - v51) * w4) + (float)(v51 * w3))
                            * (float)((float)(unsigned __int8)*v40 * 0.0039215689));
                v53 = (float)((float)((float)*(__int16 *)(v40 + 3) * v14) * v52) + FlexVertex->m_Position.y;
                v54 = (float)((float)((float)*(__int16 *)(v40 + 5) * v14) * v52) + FlexVertex->m_Position.z;
                FlexVertex->m_Position.x = FlexVertex->m_Position.x
                                         + (float)((float)((float)*(__int16 *)(v40 + 1) * v14) * v52);
                FlexVertex->m_Position.y = v53;
                FlexVertex->m_Position.z = v54;
                if ( bWrinkleFlex )
                  FlexVertex->m_Position.w = (float)((float)((float)*(__int16 *)(v40 + 13) * v14) * v52)
                                           + FlexVertex->m_Position.w;
                if ( !bQuadList )
                {
                  v55 = *(__int16 *)(v40 + 11);
                  v56 = FlexVertex->m_Normal.x + (float)((float)((float)*(__int16 *)(v40 + 7) * v14) * v52);
                  FlexVertex->m_Normal.y = FlexVertex->m_Normal.y
                                         + (float)((float)((float)*(__int16 *)(v40 + 9) * v14) * v52);
                  v57 = FlexVertex->m_Normal.z + (float)((float)((float)v55 * v14) * v52);
                  FlexVertex->m_Normal.x = v56;
                  FlexVertex->m_Normal.z = v57;
                }
                v58 = v47 == nullptr;
                v7 = pmesh;
                if ( !v58 )
                {
                  v59 = (float)((float)*(__int16 *)(v40 + 9) * v14) * v52;
                  v60 = (float)((float)*(__int16 *)(v40 + 11) * v14) * v52;
                  FlexVertex->m_TangentS.x = FlexVertex->m_TangentS.x
                                           + (float)((float)((float)*(__int16 *)(v40 + 7) * v14) * v52);
                  FlexVertex->m_TangentS.y = FlexVertex->m_TangentS.y + v59;
                  FlexVertex->m_TangentS.z = FlexVertex->m_TangentS.z + v60;
                }
                goto LABEL_78;
              }
              FlexVertex = CCachedRenderData::CreateFlexVertex(
                             this: p_m_VertexCache,
                             vertex: *(unsigned __int16 *)(v40 - 3));
              v26 = v72;
              v14 = flVertAnimFixedPointScale;
              v15 = v70;
              if ( FlexVertex != nullptr )
              {
                FlexVertex->m_Position.x = weight[4];
                FlexVertex->m_Position.y = weight[5];
                v45 = weight[6];
                FlexVertex->m_Position.w = 0.0;
                FlexVertex->m_Position.z = v45;
                FlexVertex->m_Normal.x = weight[7];
                FlexVertex->m_Normal.y = weight[8];
                v46 = weight[9];
                v47 = pStudioTangentS;
                FlexVertex->m_Normal.z = v46;
                if ( pStudioTangentS != nullptr )
                {
                  v48 = v41;
                  x = pStudioTangentS[v48].x;
                  p_x = &pStudioTangentS[v48].x;
                  FlexVertex->m_TangentS.x = x;
                  FlexVertex->m_TangentS.y = p_x[1];
                  FlexVertex->m_TangentS.z = p_x[2];
                  FlexVertex->m_TangentS.w = p_x[3];
                }
                goto LABEL_71;
              }
              v7 = pmesh;
            }
LABEL_78:
            v40 += nVAnimSizeBytes;
            ++j;
          }
          while ( j < *((_DWORD *)v15 + 4) );
        }
      }
      v15 += 60;
      ++i;
      v70 = v15;
      if ( i >= v7->numflexes )
      {
        p_vertexdata = &pmesh->vertexdata;
LABEL_81:
        CCachedRenderData::RenormalizeFlexVertices(
          this: p_m_VertexCache,
          bHasTangentData: p_vertexdata->modelvertexdata->pTangentData != nullptr,
          bQuadList);
        goto LABEL_82;
      }
    }
  }
  v10 = warnCount++;
  if ( v10 < 0x14 )
    _Warning(a1: "ERROR: model verts have been compressed, cannot render! (use \"-no_compressed_vvds\")");
LABEL_82:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10012E20
// Name: private: void CStudioRender::AddGlint(class CPixelWriter __near &,float,float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::AddGlint(
        CStudioRender *this@<ecx>,
        double a2@<esi:edi>,
        CPixelWriter *pixelWriter,
        float x,
        float y,
        const Vector *color)
{
  int m_GlintWidth; // edx
  int m_GlintHeight; // ebx
  float v8; // xmm0_4
  float v9; // xmm1_4
  int v10; // edi
  float v11; // xmm4_4
  int v12; // eax
  int v13; // esi
  int v14; // edx
  int v15; // ecx
  unsigned __int8 m_Size; // bl
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm4_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm5_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  unsigned __int8 *m_pBits; // ecx
  float v35; // xmm0_4
  int v36; // eax
  unsigned int v37; // edi
  unsigned int v38; // ebx
  int v39; // edi
  int v40; // eax
  unsigned __int8 v41; // bl
  unsigned int v42; // edx
  unsigned int v43; // eax
  __int16 v44; // cx
  unsigned int v45; // edx
  unsigned int v46; // eax
  int v47; // edx
  unsigned __int64 v48; // kr00_8
  unsigned __int64 v49; // rax
  __int16 m_BShift; // cx
  int v51; // ebx
  int v52; // edi
  __int64 v53; // rax
  __int64 v54; // rax
  unsigned __int64 v55; // rax
  int v56; // ebx
  int v57; // edi
  long double v58; // [esp+4h] [ebp-60h]
  float outColor; // [esp+10h] [ebp-54h]
  float outColora; // [esp+10h] [ebp-54h]
  float outColor_4; // [esp+14h] [ebp-50h]
  float outColor_4a; // [esp+14h] [ebp-50h]
  float outColor_8; // [esp+18h] [ebp-4Ch]
  float outColor_8a; // [esp+18h] [ebp-4Ch]
  __int64 v65; // [esp+1Ch] [ebp-48h]
  float v66; // [esp+2Ch] [ebp-38h]
  float v67; // [esp+30h] [ebp-34h]
  float i; // [esp+38h] [ebp-2Ch]
  int x0; // [esp+3Ch] [ebp-28h]
  int u; // [esp+40h] [ebp-24h]
  float v71; // [esp+48h] [ebp-1Ch]
  int y1; // [esp+50h] [ebp-14h]
  int v; // [esp+54h] [ebp-10h]
  int x1; // [esp+58h] [ebp-Ch]
  int v75; // [esp+5Ch] [ebp-8h]
  float v76; // [esp+60h] [ebp-4h]
  float fv; // [esp+6Ch] [ebp+8h]
  float xa; // [esp+70h] [ebp+Ch]
  float ya; // [esp+74h] [ebp+10h]

  m_GlintWidth = this->m_GlintWidth;
  m_GlintHeight = this->m_GlintHeight;
  v8 = (float)(x + 0.5) * (float)m_GlintWidth;
  v9 = (float)(y + 0.5) * (float)m_GlintHeight;
  v58 = a2;
  v10 = (int)(float)((float)(int)v8 + 1.0);
  v11 = (float)(int)v9;
  y1 = (int)(float)(v11 + 1.0);
  v12 = (int)(float)((float)(int)v8 - 1.0);
  xa = v8;
  ya = v9;
  x1 = v10;
  x0 = v12;
  v13 = (int)(float)(v11 - 1.0);
  if ( v12 < m_GlintWidth && v10 >= 0 && v13 < m_GlintHeight )
  {
    v14 = (int)(float)(v11 + 1.0);
    if ( y1 >= 0 )
    {
      if ( v12 < 0 )
      {
        x0 = 0;
        v12 = 0;
      }
      if ( v13 < 0 )
        v13 = 0;
      v15 = this->m_GlintWidth;
      if ( v10 >= v15 )
      {
        x1 = v15 - 1;
        v10 = v15 - 1;
      }
      if ( y1 >= m_GlintHeight )
      {
        y1 = m_GlintHeight - 1;
        v14 = m_GlintHeight - 1;
      }
      v = v13;
      if ( v13 <= v14 )
      {
        do
        {
          m_Size = pixelWriter->m_Size;
          u = v12;
          pixelWriter->m_pBits = &pixelWriter->m_pBase[v * pixelWriter->m_BytesPerRow + v12 * m_Size];
          if ( v12 <= v10 )
          {
            v18 = (float)v - v9;
            v19 = v18 - 0.25;
            fv = v18;
            for ( i = v18 - 0.25; ; v19 = i )
            {
              v20 = (float)u - v8;
              v21 = v20 - 0.25;
              v22 = (float)(v21 * v21) + (float)(v19 * v19);
              if ( v22 > 1.0 )
              {
                v23 = 0.0;
              }
              else
              {
                __libm_sse2_exp(x: v58);
                v18 = fv;
                v21 = v20 - 0.25;
                v19 = i;
                v23 = v22 * -25.0;
              }
              v67 = v23;
              v24 = v20 + 0.25;
              v25 = (float)(v24 * v24) + (float)(v19 * v19);
              v71 = v20 + 0.25;
              if ( v25 > 1.0 )
              {
                v26 = 0.0;
              }
              else
              {
                __libm_sse2_exp(x: v58);
                v18 = fv;
                v24 = v20 + 0.25;
                v21 = v20 - 0.25;
                v26 = v25 * -25.0;
              }
              v27 = (float)(v18 * v18) + (float)(v20 * v20);
              v76 = v26;
              if ( v27 > 1.0 )
              {
                v28 = 0.0;
              }
              else
              {
                __libm_sse2_exp(x: v58);
                v18 = fv;
                v24 = v20 + 0.25;
                v21 = v20 - 0.25;
                v28 = v27 * -25.0;
              }
              v29 = v18 + 0.25;
              v30 = (float)(v21 * v21) + (float)(v29 * v29);
              if ( v30 > 1.0 )
              {
                v66 = 0.0;
              }
              else
              {
                __libm_sse2_exp(x: v58);
                v24 = v71;
                v31 = v30 * -25.0;
                v66 = v31;
                v26 = v76;
              }
              v32 = (float)(v24 * v24) + (float)(v29 * v29);
              if ( v32 > 1.0 )
              {
                v33 = 0.0;
              }
              else
              {
                __libm_sse2_exp(x: v58);
                v33 = v32 * -25.0;
                v26 = v76;
              }
              m_pBits = pixelWriter->m_pBits;
              v35 = (float)((float)((float)((float)(v26 + v67) + (float)(v28 * 5.0)) + v66) + v33) * 0.44444445;
              outColor_4 = color->y * v35;
              v36 = *m_pBits;
              outColor_8 = color->z * v35;
              if ( m_Size > 1u )
              {
                v36 = *(unsigned __int16 *)m_pBits;
                if ( m_Size > 2u )
                {
                  v36 |= m_pBits[2] << 16;
                  if ( m_Size > 3u )
                    v36 |= m_pBits[3] << 24;
                }
              }
              v37 = pixelWriter->m_GMask & (v36 >> LOBYTE(pixelWriter->m_GShift));
              v38 = pixelWriter->m_BMask & (v36 >> LOBYTE(pixelWriter->m_BShift));
              outColor = color->x * v35;
              outColora = TextureToLinear(c: pixelWriter->m_RMask & (v36 >> LOBYTE(pixelWriter->m_RShift))) + outColor;
              outColor_4a = TextureToLinear(c: v37) + outColor_4;
              outColor_8a = TextureToLinear(c: v38) + outColor_8;
              v75 = LinearToTexture(f: outColor_8a);
              v39 = LinearToTexture(f: outColor_4a);
              v40 = LinearToTexture(f: outColora);
              v41 = pixelWriter->m_Size;
              if ( v41 != 0 )
              {
                if ( v41 >= 5u )
                {
                  v48 = (unsigned __int64)(pixelWriter->m_GMask & v39) << pixelWriter->m_GShift;
                  v49 = (unsigned __int64)(v40 & pixelWriter->m_RMask) << pixelWriter->m_RShift;
                  m_BShift = pixelWriter->m_BShift;
                  v51 = v49 | v48;
                  LODWORD(v53) = v75 & pixelWriter->m_BMask;
                  v52 = HIDWORD(v49) | HIDWORD(v48);
                  HIDWORD(v53) = 0;
                  if ( m_BShift <= 0 )
                    v54 = v53 >> -(char)m_BShift;
                  else
                    v54 = v53 << m_BShift;
                  v65 = v54;
                  v55 = (unsigned __int64)LOBYTE(pixelWriter->m_AMask) << pixelWriter->m_AShift;
                  v56 = v65 | v55 | v51;
                  v57 = HIDWORD(v65) | HIDWORD(v55) | v52;
                  if ( pixelWriter->m_Size == 6 )
                  {
                    *(_DWORD *)pixelWriter->m_pBits = v56;
                    *((_WORD *)pixelWriter->m_pBits + 2) = v57;
                  }
                  else if ( pixelWriter->m_Size == 8 )
                  {
                    *(_DWORD *)pixelWriter->m_pBits = v56;
                    *((_DWORD *)pixelWriter->m_pBits + 1) = v57;
                  }
                }
                else
                {
                  v42 = v40 & pixelWriter->m_RMask;
                  v43 = v75 & pixelWriter->m_BMask;
                  v44 = pixelWriter->m_BShift;
                  v45 = ((pixelWriter->m_GMask & v39) << LOBYTE(pixelWriter->m_GShift))
                      | (v42 << LOBYTE(pixelWriter->m_RShift));
                  if ( v44 <= 0 )
                    v46 = v43 >> -(char)v44;
                  else
                    v46 = v43 << v44;
                  v47 = v46 | (LOBYTE(pixelWriter->m_AMask) << LOBYTE(pixelWriter->m_AShift)) | v45;
                  switch ( v41 )
                  {
                    case 1u:
                      *pixelWriter->m_pBits = v47;
                      break;
                    case 2u:
                      *(_WORD *)pixelWriter->m_pBits = v47;
                      break;
                    case 3u:
                      *(_WORD *)pixelWriter->m_pBits = v47;
                      pixelWriter->m_pBits[2] = BYTE2(v47);
                      break;
                    case 4u:
                      *(_DWORD *)pixelWriter->m_pBits = v47;
                      break;
                  }
                }
              }
              m_Size = pixelWriter->m_Size;
              v8 = xa;
              pixelWriter->m_pBits += m_Size;
              if ( ++u > x1 )
                break;
              v18 = fv;
            }
            v9 = ya;
            v12 = x0;
            v10 = x1;
          }
          ++v;
        }
        while ( v <= y1 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100133D0
// Name: public: virtual void CGlintTextureRegenerator::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGlintTextureRegenerator::RegenerateTextureBits(
        CGlintTextureRegenerator *this@<ecx>,
        double a2@<esi:edi>,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  unsigned __int8 *v5; // ebx
  unsigned __int16 v6; // ax
  int v7; // edx
  int (__thiscall *v8)(_DWORD); // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  int v11; // ebx
  int v12; // [esp+24h] [ebp-16Ch]
  CStudioRender::GlintRenderData_t pRenderData[16]; // [esp+2Ch] [ebp-164h] BYREF
  CPixelWriter pixelWriter; // [esp+16Ch] [ebp-24h] BYREF
  int savedregs; // [esp+190h] [ebp+0h] BYREF
  int nGlintCount; // [esp+19Ch] [ebp+Ch]

  LODWORD(a2) = this;
  if ( this->m_pStudioRender != nullptr )
  {
    v12 = HIDWORD(a2);
    HIDWORD(a2) = pVTFTexture;
    if ( this->m_pStudioRender->m_GlintWidth != ((int (__thiscall *)(IVTFTexture *, int))pVTFTexture->Width)(
                                                  a1: pVTFTexture,
                                                  a2: v12)
      || *(__int16 *)(*(_DWORD *)(LODWORD(a2) + 20) + 2078) != pVTFTexture->Height(this: pVTFTexture) )
    {
      *(_WORD *)(*(_DWORD *)(LODWORD(a2) + 20) + 2076) = pVTFTexture->Width(this: pVTFTexture);
      *(_WORD *)(*(_DWORD *)(LODWORD(a2) + 20) + 2078) = pVTFTexture->Height(this: pVTFTexture);
    }
    nGlintCount = CStudioRender::BuildGlintRenderData(
                    this: *(CStudioRender **)(LODWORD(a2) + 20),
                    a2: (int)&savedregs,
                    pData: pRenderData,
                    nMaxGlints: 16,
                    pState: *(const eyeballstate_t **)(LODWORD(a2) + 4),
                    vright: *(const Vector **)(LODWORD(a2) + 8),
                    vup: *(const Vector **)(LODWORD(a2) + 12),
                    r_origin: *(const Vector **)(LODWORD(a2) + 16));
    v5 = (unsigned __int8 *)(*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)HIDWORD(a2) + 152))(
                              a1: HIDWORD(a2),
                              a2: 0,
                              a3: 0,
                              a4: 0);
    v6 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)HIDWORD(a2) + 72))(a1: HIDWORD(a2), a2: 0);
    v7 = *(_DWORD *)HIDWORD(a2);
    pixelWriter.m_BytesPerRow = v6;
    v8 = *(int (__thiscall **)(_DWORD))(v7 + 80);
    pixelWriter.m_pBits = v5;
    pixelWriter.m_pBase = v5;
    pixelWriter.m_nFlags = 0;
    switch ( v8(a1: HIDWORD(a2)) )
    {
      case 0:
      case 23:
        v9 = 255;
        pixelWriter.m_Size = 4;
        *(_DWORD *)&pixelWriter.m_RShift = 0x80000;
        *(_DWORD *)&pixelWriter.m_BShift = 1572880;
        pixelWriter.m_RMask = 255;
        goto LABEL_23;
      case 3:
        *(_DWORD *)&pixelWriter.m_BShift = 0;
        v9 = 255;
        pixelWriter.m_Size = 3;
        *(_DWORD *)&pixelWriter.m_RShift = 524304;
        pixelWriter.m_RMask = 255;
        pixelWriter.m_AMask = 0;
        goto LABEL_24;
      case 5:
        pixelWriter.m_Size = 1;
        *(_DWORD *)&pixelWriter.m_RShift = 0;
        *(_DWORD *)&pixelWriter.m_BShift = 0;
        goto LABEL_21;
      case 8:
        v9 = 0;
        pixelWriter.m_Size = 1;
        memset(&pixelWriter.m_RShift, 0, 12);
        pixelWriter.m_AMask = 255;
        goto LABEL_24;
      case 12:
        v9 = 255;
        pixelWriter.m_Size = 4;
        *(_DWORD *)&pixelWriter.m_RShift = 524304;
        *(_DWORD *)&pixelWriter.m_BShift = 1572864;
        pixelWriter.m_RMask = 255;
        goto LABEL_23;
      case 16:
        v9 = 255;
        pixelWriter.m_Size = 4;
        *(_DWORD *)&pixelWriter.m_RShift = 524304;
        *(_DWORD *)&pixelWriter.m_BShift = 1572864;
        pixelWriter.m_RMask = 255;
        pixelWriter.m_AMask = 0;
        goto LABEL_24;
      case 17:
        v9 = 248;
        pixelWriter.m_Size = 2;
        *(_DWORD *)&pixelWriter.m_RShift = 196616;
        *(_DWORD *)&pixelWriter.m_BShift = 65533;
        pixelWriter.m_RMask = 248;
        pixelWriter.m_GMask = 252;
        pixelWriter.m_AMask = 0;
        goto LABEL_25;
      case 18:
      case 21:
        v9 = 248;
        pixelWriter.m_Size = 2;
        *(_DWORD *)&pixelWriter.m_RShift = 131079;
        *(_DWORD *)&pixelWriter.m_BShift = 589821;
        pixelWriter.m_RMask = 248;
        pixelWriter.m_AMask = 128;
        goto LABEL_24;
      case 19:
        v9 = 240;
        pixelWriter.m_Size = 2;
        *(_DWORD *)&pixelWriter.m_RShift = 4;
        *(_DWORD *)&pixelWriter.m_BShift = 589820;
        pixelWriter.m_RMask = 240;
        goto LABEL_23;
      case 24:
        v9 = 0xFFFF;
        *(_DWORD *)&pixelWriter.m_RShift = 0x100000;
        *(_DWORD *)&pixelWriter.m_BShift = 3145760;
        pixelWriter.m_RMask = 0xFFFF;
        *(_WORD *)&pixelWriter.m_Size = 776;
        goto LABEL_23;
      case 25:
        v9 = 0xFFFF;
        pixelWriter.m_Size = 8;
        *(_DWORD *)&pixelWriter.m_RShift = 0x100000;
        *(_DWORD *)&pixelWriter.m_BShift = 3145760;
        pixelWriter.m_RMask = 0xFFFF;
        goto LABEL_23;
      case 27:
        *(_DWORD *)&pixelWriter.m_RShift = 0;
        *(_DWORD *)&pixelWriter.m_BShift = 0;
        pixelWriter.m_RMask = -1;
        *(_WORD *)&pixelWriter.m_Size = 260;
        goto LABEL_22;
      case 29:
        v9 = -1;
        *(_DWORD *)&pixelWriter.m_RShift = 0x200000;
        *(_DWORD *)&pixelWriter.m_BShift = 6291520;
        pixelWriter.m_RMask = -1;
        *(_WORD *)&pixelWriter.m_Size = 272;
        goto LABEL_23;
      case 37:
        v9 = 1023;
        pixelWriter.m_Size = 4;
        *(_DWORD *)&pixelWriter.m_RShift = 655380;
        *(_DWORD *)&pixelWriter.m_BShift = 1966080;
        pixelWriter.m_RMask = 1023;
        pixelWriter.m_AMask = 3;
        goto LABEL_24;
      default:
        *(_DWORD *)&pixelWriter.m_Size = 2048;
        *(_DWORD *)&pixelWriter.m_GShift = 0;
        pixelWriter.m_AShift = 0;
LABEL_21:
        pixelWriter.m_RMask = 255;
LABEL_22:
        v9 = 0;
LABEL_23:
        pixelWriter.m_AMask = v9;
LABEL_24:
        pixelWriter.m_GMask = v9;
LABEL_25:
        pixelWriter.m_BMask = v9;
        v10 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)HIDWORD(a2) + 132))(a1: HIDWORD(a2), a2: 0);
        memset(dst: v5, value: 0, count: v10);
        v11 = nGlintCount;
        if ( nGlintCount > 0 )
        {
          HIDWORD(a2) = &pRenderData[0].m_vecPosition.y;
          do
          {
            CStudioRender::AddGlint(
              this: *(CStudioRender **)(LODWORD(a2) + 20),
              a2,
              &pixelWriter,
              x: *(float *)(HIDWORD(a2) - 4),
              y: *(float *)HIDWORD(a2),
              color: (const Vector *)(HIDWORD(a2) + 4));
            HIDWORD(a2) += 20;
            --v11;
          }
          while ( v11 != 0 );
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013760
// Name: private: class ITexture __near * CStudioRender::RenderGlintTexture(struct eyeballstate_t const __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
ITexture *__userpurge CStudioRender::RenderGlintTexture@<eax>(
        CStudioRender *this@<ecx>,
        int a2@<esi>,
        const eyeballstate_t *pState,
        const Vector *vright,
        const Vector *vup,
        const Vector *r_origin)
{
  CStudioRender *v6; // ebx
  int v7; // edi
  int v9; // eax
  int v10; // esi
  float *p_y; // edi
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  float m_GlintWidth; // xmm1_4
  float m_GlintHeight; // xmm4_4
  float v16; // xmm5_4
  __m128 v17; // xmm1
  float v18; // xmm6_4
  __m128 v19; // xmm4
  int v20; // eax
  __m128 v21; // xmm1
  int v22; // ebx
  float v23; // xmm7_4
  int v24; // ecx
  float *m_pCurrPosition; // eax
  float v26; // xmm5_4
  float *v27; // eax
  float v28; // xmm0_4
  float *v29; // eax
  float *v30; // eax
  const Vector *v31; // xmm0_4
  const eyeballstate_t *v32; // xmm0_4
  int v33; // xmm0_4
  float *v34; // eax
  float *v35; // eax
  float *v36; // eax
  float *v37; // eax
  float *v38; // eax
  float *v39; // eax
  float v40; // xmm0_4
  float *v41; // eax
  float *v42; // eax
  float *v43; // eax
  float *v44; // eax
  float *v45; // eax
  float *v46; // eax
  __int16 v47; // ax
  bool v48; // zf
  int m_nVertexCount; // eax
  ITexture *m_pGlintTexture; // ebx
  CStudioRender::GlintRenderData_t pRenderData[16]; // [esp+8h] [ebp-38Ch] BYREF
  CMeshBuilder meshBuilder; // [esp+148h] [ebp-24Ch] BYREF
  Vector4D white; // [esp+330h] [ebp-64h] BYREF
  IMesh *pMesh; // [esp+340h] [ebp-54h]
  float v55; // [esp+344h] [ebp-50h]
  float v56; // [esp+348h] [ebp-4Ch]
  int bInFlashlightMode; // [esp+34Ch] [ebp-48h]
  void *pPrevProxy; // [esp+350h] [ebp-44h]
  int bPrevClippingEnabled; // [esp+354h] [ebp-40h]
  float v60; // [esp+358h] [ebp-3Ch]
  MaterialHeightClipMode_t nPrevClipMode; // [esp+35Ch] [ebp-38h]
  float screenY0; // [esp+360h] [ebp-34h]
  int nPrevBoneCount; // [esp+364h] [ebp-30h]
  float v64; // [esp+368h] [ebp-2Ch]
  IMaterial *pPrevMaterial; // [esp+36Ch] [ebp-28h]
  float screenX0; // [esp+370h] [ebp-24h]
  float screenY1; // [esp+374h] [ebp-20h]
  int v68; // [esp+378h] [ebp-1Ch]
  CStudioRender *v69; // [esp+37Ch] [ebp-18h]
  float screenX1; // [esp+380h] [ebp-14h]
  int v71; // [esp+384h] [ebp-10h]
  int nIndex; // [esp+388h] [ebp-Ch]
  int y1; // [esp+38Ch] [ebp-8h]
  int y0; // [esp+390h] [ebp-4h]
  int savedregs; // [esp+394h] [ebp+0h] BYREF
  const eyeballstate_t *pStatea; // [esp+39Ch] [ebp+8h]
  const Vector *vrighta; // [esp+3A0h] [ebp+Ch]
  int x; // [esp+3A8h] [ebp+14h]

  v6 = this;
  v69 = this;
  v7 = CStudioRender::BuildGlintRenderData(
         this,
         a2: (int)&savedregs,
         pData: pRenderData,
         nMaxGlints: 16,
         pState,
         vright,
         vup,
         r_origin);
  x = v7;
  if ( v7 == 0 )
    return v6->m_pGlintLODTexture;
  v9 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
  v10 = v9;
  if ( v9 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
  (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v10 + 436))(a1: v10, a2: v6->m_pGlintTexture);
  pPrevMaterial = (IMaterial *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 644))(a1: v10);
  pPrevProxy = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 652))(a1: v10);
  nPrevBoneCount = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 648))(a1: v10);
  nPrevClipMode = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 344))(a1: v10);
  LOBYTE(bPrevClippingEnabled) = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 528))(a1: v10, a2: 0);
  LOBYTE(bInFlashlightMode) = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 360))(a1: v10);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v10 + 296))(
    a1: v10,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0);
  (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v10 + 48))(a1: v10, a2: 1, a3: 0, a4: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 336))(a1: v10, a2: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 168))(a1: v10, a2: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 216))(a1: v10, a2: 0);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v10 + 36))(
    a1: v10,
    a2: v6->m_pGlintBuildMaterial,
    a3: 0);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 80))(a1: v10, a2: 10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 84))(a1: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 124))(a1: v10);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 80))(a1: v10, a2: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 84))(a1: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 124))(a1: v10);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 80))(a1: v10, a2: 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 84))(a1: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 124))(a1: v10);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  pMesh = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v10 + 228))(
                     a1: v10,
                     a2: 1,
                     a3: 0,
                     a4: 0,
                     a5: 0);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLES,
    nVertexCount: 4 * v7,
    nIndexCount: 6 * v7,
    pMeshSettings: nullptr);
  white.x = 1.0;
  white.y = 1.0;
  white.z = 1.0;
  white.w = 1.0;
  nIndex = 0;
  if ( v7 > 0 )
  {
    p_y = &pRenderData[0].m_vecIntensity.y;
    v68 = x;
    do
    {
      v12 = (__m128)*((unsigned int *)p_y - 3);
      v13 = (__m128)*((unsigned int *)p_y - 2);
      m_GlintWidth = (float)v6->m_GlintWidth;
      m_GlintHeight = (float)v6->m_GlintHeight;
      v12.m128_f32[0] = (float)(v12.m128_f32[0] + 0.5) * m_GlintWidth;
      v13.m128_f32[0] = (float)(v13.m128_f32[0] + 0.5) * m_GlintHeight;
      v16 = 1.0 / m_GlintWidth;
      v17 = _mm_and_ps((__m128)0x80000000, v12);
      v18 = 1.0 / m_GlintHeight;
      y0 = v17.m128_i32[0];
      v19.m128_i32[0] = 1258291200;
      v17.m128_f32[0] = _mm_cmplt_ss(_mm_xor_ps(v12, v17), v19).m128_f32[0];
      v17.m128_f32[0] = (float)(v12.m128_f32[0] + COERCE_FLOAT(v17.m128_i32[0] & 0x4B000000 | y0))
                      - COERCE_FLOAT(v17.m128_i32[0] & 0x4B000000 | y0);
      v20 = (int)(float)(v17.m128_f32[0]
                       - COERCE_FLOAT((float)(v17.m128_f32[0] - v12.m128_f32[0]) > *(float *)&y0 ? 0x3F800000 : 0));
      v21 = _mm_and_ps((__m128)0x80000000, v13);
      y0 = v21.m128_i32[0];
      v19.m128_i32[0] = 1258291200;
      v21.m128_f32[0] = _mm_cmplt_ss(_mm_xor_ps(v13, v21), v19).m128_f32[0];
      v21.m128_f32[0] = (float)(v13.m128_f32[0] + COERCE_FLOAT(y0 | v21.m128_i32[0] & 0x4B000000))
                      - COERCE_FLOAT(y0 | v21.m128_i32[0] & 0x4B000000);
      v22 = (int)(float)((float)v20 + 1.0);
      v23 = (float)(int)(float)(v21.m128_f32[0]
                              - COERCE_FLOAT((float)(v21.m128_f32[0] - v13.m128_f32[0]) > *(float *)&y0 ? 0x3F800000 : 0));
      v24 = (int)(float)((float)v20 - 2.0);
      y0 = (int)(float)(v23 - 2.0);
      y1 = (int)(float)(v23 + 1.0);
      v19.m128_f32[0] = (float)(2 * v24) * v16;
      screenX1 = (float)((float)((float)(2 * v22) * v16) + 0.015625) - 1.0;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v21.m128_i32[0] = COERCE_UNSIGNED_INT((float)((float)((float)(2 * y0) * v18) + 0.015625) - 1.0) ^ _mask__NegFloat_;
      v26 = (float)((float)((float)(2 * y1) * v18) + 0.015625) - 1.0;
      v19.m128_f32[0] = (float)(v19.m128_f32[0] + 0.015625) - 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v19.m128_i32[0];
      m_pCurrPosition[1] = v21.m128_f32[0];
      m_pCurrPosition[2] = 0.0;
      v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)v24;
      v56 = (float)v24;
      v28 = (float)y0;
      v27[1] = (float)y0;
      v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v12.m128_i32[0];
      v29[1] = v13.m128_f32[0];
      v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      v64 = v28;
      v31 = *((const Vector **)p_y - 1);
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v31;
      vrighta = v31;
      v32 = *(const eyeballstate_t **)p_y;
      v30[1] = *p_y;
      pStatea = v32;
      v33 = *((_DWORD *)p_y + 1);
      screenX0 = v19.m128_f32[0];
      screenY0 = v21.m128_f32[0];
      LODWORD(screenY1) = LODWORD(v26) ^ _mask__NegFloat_;
      v71 = v33;
      *((_DWORD *)v30 + 2) = v33;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v34 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = screenX1;
      v34[1] = screenY0;
      v34[2] = 0.0;
      v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)v22;
      v55 = (float)v22;
      v35[1] = v64;
      v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v12.m128_i32[0];
      v36[1] = v13.m128_f32[0];
      v37 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = vrighta;
      *((_DWORD *)v37 + 1) = pStatea;
      *((_DWORD *)v37 + 2) = v71;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v38 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = screenX1;
      v38[1] = screenY1;
      v38[2] = 0.0;
      v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v55;
      v40 = (float)y1;
      v39[1] = (float)y1;
      v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v60 = v40;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v12.m128_i32[0];
      v41[1] = v13.m128_f32[0];
      v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = vrighta;
      *((_DWORD *)v42 + 1) = pStatea;
      *((_DWORD *)v42 + 2) = v71;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = screenX0;
      v43[1] = screenY1;
      v43[2] = 0.0;
      v44 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v56;
      v44[1] = v60;
      v45 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v12.m128_i32[0];
      v45[1] = v13.m128_f32[0];
      v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = vrighta;
      *((_DWORD *)v46 + 1) = pStatea;
      *((_DWORD *)v46 + 2) = v71;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v47 = nIndex;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nIndex
                                                                                        + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + v47
                                                                                        + 1;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + v47
                                                                                        + 2;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      nIndex += 4;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = v47
                                                                                        + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + v47
                                                                                        + 2;
      v6 = v69;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + v47
                                                                                        + 3;
      p_y += 5;
      v48 = v68-- == 1;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    }
    while ( !v48 );
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  pMesh->DrawModulated(this: pMesh, a2: &white, a3: -1, a4: 0);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 80))(a1: v10, a2: 10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 88))(a1: v10);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 80))(a1: v10, a2: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 88))(a1: v10);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 80))(a1: v10, a2: 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 88))(a1: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 444))(a1: v10);
  (*(void (__thiscall **)(int, IMaterial *, void *))(*(_DWORD *)v10 + 36))(a1: v10, a2: pPrevMaterial, a3: pPrevProxy);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 216))(a1: v10, a2: nPrevBoneCount);
  (*(void (__thiscall **)(int, MaterialHeightClipMode_t))(*(_DWORD *)v10 + 168))(a1: v10, a2: nPrevClipMode);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 528))(a1: v10, a2: bPrevClippingEnabled);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 336))(a1: v10, a2: bInFlashlightMode);
  m_pGlintTexture = v6->m_pGlintTexture;
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 12))(a1: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
  return m_pGlintTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10014050
// Name: private: void CStudioRender::R_StudioEyeballGlint(struct eyeballstate_t const __near *,class IMaterialVar __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioEyeballGlint(
        CStudioRender *this,
        const eyeballstate_t *pstate,
        IMaterialVar *pGlintVar,
        const Vector *vright,
        const Vector *vup,
        const Vector *r_origin)
{
  IMatRenderContext *v7; // edi
  __int16 v8; // ax
  ITexture *m_pGlintTexture; // ecx
  ITexture *v10; // [esp+4h] [ebp-Ch]

  v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  if ( this->m_pGlintLODTexture == nullptr
    || r_glint_alwaysdraw.m_pParent != nullptr && r_glint_alwaysdraw.m_pParent->m_Value.m_nValue != 0
    || this->m_pRC->m_Config.fEyeGlintPixelWidthLODThreshold <= ((double (__thiscall *)(IMatRenderContext *, Vector *, _DWORD))v7->ComputePixelWidthOfSphere)(
                                                                  a1: v7,
                                                                  a2: &pstate->org,
                                                                  a3: LODWORD(pstate->peyeball->radius)) )
  {
    if ( r_glint_procedural.m_pParent != nullptr && r_glint_procedural.m_pParent->m_Value.m_nValue != 0 )
    {
      s_GlintTextureRegen.m_pVUp = vup;
      s_GlintTextureRegen.m_pROrigin = r_origin;
      s_GlintTextureRegen.m_pVRight = vright;
      s_GlintTextureRegen.m_pState = pstate;
      s_GlintTextureRegen.m_pStudioRender = this;
      s_pProcGlint->Download(this: s_pProcGlint, a2: nullptr, a3: 0);
      s_GlintTextureRegen.m_pStudioRender = nullptr;
      ((void (__cdecl *)(ITexture *))pGlintVar->SetTextureValue)(a1: s_pProcGlint);
    }
    else
    {
      v8 = this->m_pGlintTexture->GetActualWidth(this: this->m_pGlintTexture);
      m_pGlintTexture = this->m_pGlintTexture;
      this->m_GlintWidth = v8;
      this->m_GlintHeight = m_pGlintTexture->GetActualHeight(this: m_pGlintTexture);
      v10 = CStudioRender::RenderGlintTexture(this, a2: (int)this, pState: pstate, vright, vup, r_origin);
      ((void (__cdecl *)(ITexture *))pGlintVar->SetTextureValue)(a1: v10);
    }
    if ( v7 != nullptr )
    {
      v7->EndRender(this: v7);
      v7->Release(this: v7);
    }
  }
  else
  {
    pGlintVar->SetTextureValue(this: pGlintVar, a2: this->m_pGlintLODTexture);
    v7->EndRender(this: v7);
    v7->Release(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BAB0
// Name: __heap_term
// Source: rtti_class
//------------------------------------------------------------------------------
void __cdecl _heap_term()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10057E90
// Name: public: virtual class IVTFTexture __near * ITextureRegenerator::GetPreallocatedScratchTexture(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ITextureRegenerator::GetPreallocatedScratchTexture(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057EA0
// Name: public: virtual bool ITextureRegenerator::HasPreallocatedScratchTexture(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ITextureRegenerator::HasPreallocatedScratchTexture(ConVar *this)
{
  return false;
}
