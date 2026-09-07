// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/l_studio.cpp
// Functions: 98
// ============================================================

#include "engine\l_studio.h"

//------------------------------------------------------------------------------
// Address: 0x100DA260
// Name: public: void LightingState_t::CopyLocalLights(struct LightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightingState_t::CopyLocalLights(LightingState_t *this, const LightingState_t *src)
{
  int v2; // edx
  dworldlight_t **locallight; // eax

  v2 = 0;
  this->numlights = src->numlights;
  if ( src->numlights > 0 )
  {
    locallight = this->locallight;
    do
    {
      *locallight = *(dworldlight_t **)((char *)locallight + (char *)src - (char *)this);
      ++v2;
      ++locallight;
    }
    while ( v2 < src->numlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA2D0
// Name: bool WorldLightToMaterialLight(struct dworldlight_t __near *,struct LightDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WorldLightToMaterialLight(dworldlight_t *pWorldLight, LightDesc_t *light)
{
  emittype_t type; // eax
  double radius; // st7
  float linear_attn; // xmm2_4
  float quadratic_attn; // xmm4_4
  float exponent; // xmm0_4
  float constant_attn; // xmm3_4
  float v10; // xmm1_4
  long double v11; // st7
  unsigned int v12; // ecx
  float discrim; // [esp+0h] [ebp-8h]
  float discrima; // [esp+0h] [ebp-8h]
  float discrimb; // [esp+0h] [ebp-8h]
  float flAttenuation2; // [esp+4h] [ebp-4h]
  float flAttenuation1; // [esp+10h] [ebp+8h]
  float flAttenuation1a; // [esp+10h] [ebp+8h]

  type = pWorldLight->type;
  if ( type == emit_surface )
  {
    light->m_Type = MATERIAL_LIGHT_SPOT;
    light->m_Color = pWorldLight->intensity;
    light->m_Position = pWorldLight->origin;
    light->m_Direction = pWorldLight->normal;
    radius = pWorldLight->radius;
    light->m_Falloff = 1.0;
    light->m_Range = radius;
    light->m_Attenuation0 = 0.0;
    light->m_Attenuation1 = 0.0;
    light->m_Attenuation2 = 1.0;
    light->m_Theta = 1.5707964;
    light->m_Phi = 1.5707964;
    light->m_ThetaDot = 0.0;
    light->m_PhiDot = 0.0;
    light->m_OneOverThetaDotMinusPhiDot = 1.0;
    light->m_Flags = 12;
    return 1;
  }
  linear_attn = 0.0;
  quadratic_attn = 0.0;
  flAttenuation1 = 0.0;
  flAttenuation2 = 0.0;
  light->m_OneOverThetaDotMinusPhiDot = 1.0;
  switch ( type )
  {
    case emit_point:
      light->m_Type = MATERIAL_LIGHT_POINT;
      linear_attn = pWorldLight->linear_attn;
      quadratic_attn = pWorldLight->quadratic_attn;
      constant_attn = pWorldLight->constant_attn;
      flAttenuation1 = linear_attn;
      flAttenuation2 = quadratic_attn;
      goto LABEL_7;
    case emit_spotlight:
      light->m_Type = MATERIAL_LIGHT_SPOT;
      discrim = pWorldLight->constant_attn;
      flAttenuation1 = pWorldLight->linear_attn;
      flAttenuation2 = pWorldLight->quadratic_attn;
      light->m_Theta = acos(pWorldLight->stopdot);
      light->m_Phi = acos(pWorldLight->stopdot2);
      light->m_ThetaDot = pWorldLight->stopdot;
      light->m_PhiDot = pWorldLight->stopdot2;
      exponent = pWorldLight->exponent;
      if ( exponent == 0.0 )
        exponent = 1.0;
      light->m_Falloff = exponent;
      LightDesc_t::RecalculateOneOverThetaDotMinusPhiDot(this: light);
      quadratic_attn = flAttenuation2;
      linear_attn = flAttenuation1;
      constant_attn = discrim;
LABEL_7:
      if ( constant_attn == 0.0 && linear_attn == 0.0 && quadratic_attn == 0.0 )
        goto LABEL_10;
      goto LABEL_11;
    case emit_skylight:
      light->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
      goto LABEL_10;
    case emit_quakelight:
    case emit_skyambient:
      return 0;
    default:
LABEL_10:
      constant_attn = 1.0;
LABEL_11:
      light->m_Color = pWorldLight->intensity;
      light->m_Position = pWorldLight->origin;
      light->m_Direction = pWorldLight->normal;
      v10 = pWorldLight->radius;
      if ( v10 != 0.0 )
        goto LABEL_23;
      discrima = sqrt(
                   light->m_Color.x * light->m_Color.x
                 + light->m_Color.y * light->m_Color.y
                 + light->m_Color.z * light->m_Color.z);
      if ( quadratic_attn == 0.0 )
      {
        if ( linear_attn != 0.0 )
        {
          v10 = (float)((float)(discrima * 33.333336) - constant_attn) / linear_attn;
          goto LABEL_23;
        }
        goto LABEL_21;
      }
      discrimb = (float)(linear_attn * linear_attn)
               - (float)((float)(constant_attn - (float)(discrima * 33.333336)) * (float)(quadratic_attn * 4.0));
      if ( discrimb < 0.0 )
      {
LABEL_21:
        flAttenuation1a = sqrt(3.402823466385289e38);
        goto LABEL_22;
      }
      v11 = (sqrt(discrimb) - flAttenuation1) / (flAttenuation2 + flAttenuation2);
      flAttenuation1a = v11;
      if ( v11 < 0.0 )
      {
        v10 = 0.0;
        goto LABEL_23;
      }
LABEL_22:
      v10 = flAttenuation1a;
LABEL_23:
      v12 = 8;
      if ( constant_attn != 0.0 )
        v12 = 9;
      if ( linear_attn != 0.0 )
        v12 |= 2u;
      if ( quadratic_attn != 0.0 )
        v12 |= 4u;
      light->m_Attenuation0 = constant_attn;
      light->m_Attenuation1 = linear_attn;
      light->m_Attenuation2 = quadratic_attn;
      light->m_Range = v10;
      light->m_Flags = v12;
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA5E0
// Name: float Engine_WorldLightDistanceFalloff(struct dworldlight_t const __near *,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Engine_WorldLightDistanceFalloff(const dworldlight_t *wl, const Vector *delta, bool bNoRadiusCheck)
{
  double result; // st7
  float v4; // xmm1_4
  float radius; // xmm0_4
  float v6; // [esp-4h] [ebp-10h]

  switch ( wl->type )
  {
    case emit_surface:
      if ( wl->radius != 0.0
        && (float)((float)((float)(delta->x * delta->x) + (float)(delta->y * delta->y)) + (float)(delta->z * delta->z)) > (float)(wl->radius * wl->radius) )
      {
        goto LABEL_4;
      }
      if ( (float)((float)((float)(delta->y * delta->y) + (float)(delta->x * delta->x)) + (float)(delta->z * delta->z)) >= 1.0 )
        result = 1.0 / (delta->z * delta->z + delta->y * delta->y + (float)(delta->x * delta->x));
      else
        result = 1.0 / 1.0;
      break;
    case emit_point:
    case emit_spotlight:
      v4 = fsqrt((float)((float)(delta->y * delta->y) + (float)(delta->x * delta->x)) + (float)(delta->z * delta->z));
      if ( !bNoRadiusCheck )
      {
        radius = wl->radius;
        if ( radius != 0.0 && v4 > radius )
          goto LABEL_4;
      }
      result = 1.0
             / (wl->linear_attn * v4
              + wl->constant_attn
              + wl->quadratic_attn
              * (float)((float)((float)(delta->y * delta->y) + (float)(delta->x * delta->x))
                      + (float)(delta->z * delta->z)));
      break;
    case emit_quakelight:
      v6 = wl->linear_attn
         - fsqrt((float)((float)(delta->x * delta->x) + (float)(delta->y * delta->y)) + (float)(delta->z * delta->z));
      if ( v6 < 0.0 )
LABEL_4:
        result = 0.0;
      else
        result = v6;
      break;
    default:
      result = 1.0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DA7C0
// Name: float Engine_WorldLightAngle(struct dworldlight_t const __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Engine_WorldLightAngle(
        const dworldlight_t *wl,
        const Vector *lnormal,
        const Vector *snormal,
        const Vector *delta)
{
  double v5; // st7
  double result; // st7
  float y; // xmm2_4
  float z; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float stopdot; // xmm2_4
  float exponent; // xmm3_4
  float dot2; // [esp+8h] [ebp-4h]
  float ratio; // [esp+14h] [ebp+8h]

  switch ( wl->type )
  {
    case emit_surface:
      ratio = (float)((float)(snormal->y * delta->y) + (float)(delta->x * snormal->x)) + (float)(snormal->z * delta->z);
      if ( ratio >= 0.0 )
      {
        v5 = -(lnormal->y * delta->y + lnormal->x * delta->x + lnormal->z * delta->z);
        if ( v5 > 0.01 )
          goto LABEL_13;
      }
      goto LABEL_4;
    case emit_point:
    case emit_quakelight:
      ratio = (float)((float)(snormal->y * delta->y) + (float)(snormal->x * delta->x)) + (float)(snormal->z * delta->z);
      if ( ratio >= 0.0 )
        goto LABEL_6;
      goto LABEL_4;
    case emit_spotlight:
      y = delta->y;
      z = delta->z;
      v9 = (float)((float)(snormal->y * y) + (float)(delta->x * snormal->x)) + (float)(snormal->z * z);
      ratio = v9;
      if ( v9 < 0.0 )
        goto LABEL_4;
      LODWORD(v10) = COERCE_UNSIGNED_INT((float)((float)(lnormal->y * y) + (float)(lnormal->x * delta->x)) + (float)(lnormal->z * z))
                   ^ _mask__NegFloat_;
      if ( wl->stopdot2 >= v10 )
        goto LABEL_4;
      stopdot = wl->stopdot;
      if ( v10 >= stopdot )
      {
LABEL_6:
        result = ratio;
      }
      else
      {
        exponent = wl->exponent;
        if ( exponent == 1.0 || exponent == 0.0 )
        {
          result = (float)((float)((float)(v10 - wl->stopdot2) / (float)(stopdot - wl->stopdot2)) * v9);
        }
        else
        {
          v5 = pow((v10 - wl->stopdot2) / (wl->stopdot - wl->stopdot2), wl->exponent);
LABEL_13:
          result = v5 * ratio;
        }
      }
      break;
    case emit_skylight:
      LODWORD(dot2) = COERCE_UNSIGNED_INT(
                        (float)((float)(lnormal->y * snormal->y) + (float)(lnormal->x * snormal->x))
                      + (float)(lnormal->z * snormal->z))
                    ^ _mask__NegFloat_;
      if ( dot2 < 0.0 )
        goto LABEL_4;
      result = dot2;
      break;
    case emit_skyambient:
      return 1.0;
    default:
LABEL_4:
      result = 0.0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DAA00
// Name: public: virtual void CModelRender::SuppressEngineLighting(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SuppressEngineLighting(CModelRender *this, bool bSuppress)
{
  this->m_bSuppressEngineLighting = bSuppress;
}

//------------------------------------------------------------------------------
// Address: 0x100DAA10
// Name: public: virtual bool CModelRender::GetItemName(unsigned int,void const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelRender::GetItemName(
        CModelRender *this,
        unsigned int clientId,
        char *pItem,
        char *pDest,
        unsigned int nMaxLen)
{
  g_pFileSystem->String(this: g_pFileSystem, a2: (void *const *)(pItem + 24), a3: pDest, a4: nMaxLen);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DAA40
// Name: public: struct LightingState_t __near & LightingState_t::operator=(struct LightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
LightingState_t *__thiscall LightingState_t::operator=(LightingState_t *this, const LightingState_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DAAE0
// Name: public: virtual void CModelRender::SetupLighting(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetupLighting(CModelRender *this, const Vector *vecCenter)
{
  this->SetupLightingEx(this, a2: vecCenter, a3: 0xFFFFu);
}

//------------------------------------------------------------------------------
// Address: 0x100DAB00
// Name: private: void CModelRender::SetFullbrightLightingState(int,struct MaterialLightingState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetFullbrightLightingState(
        CModelRender *this,
        int nCount,
        MaterialLightingState_t *pState)
{
  int v3; // ecx
  float *p_z; // eax

  v3 = nCount;
  if ( nCount > 0 )
  {
    p_z = &pState->m_vecAmbientCube[1].z;
    do
    {
      p_z[16] = 0.0;
      *(p_z - 5) = 1.0;
      *(p_z - 4) = 1.0;
      *(p_z - 3) = 1.0;
      *(p_z - 2) = 1.0;
      *(p_z - 1) = 1.0;
      *p_z = 1.0;
      p_z[1] = 1.0;
      p_z[2] = 1.0;
      p_z[3] = 1.0;
      p_z[4] = 1.0;
      p_z[5] = 1.0;
      p_z[6] = 1.0;
      p_z[7] = 1.0;
      p_z[8] = 1.0;
      p_z[9] = 1.0;
      p_z[10] = 1.0;
      p_z[11] = 1.0;
      p_z[12] = 1.0;
      p_z += 110;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAB90
// Name: public: virtual bool CModelRender::GetBrightestShadowingLightSource(class Vector const __near &,class Vector __near &,class Vector __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelRender::GetBrightestShadowingLightSource(
        CModelRender *this,
        const Vector *vecCenter,
        Vector *lightPos,
        Vector *lightBrightness,
        bool bAllowNonTaggedLights)
{
  float y; // ecx
  float z; // edx
  int v8; // esi
  float v9; // xmm4_4
  int v10; // ebx
  float v11; // xmm5_4
  int v12; // eax
  float v13; // xmm1_4
  double v14; // st7
  double v15; // st7
  float *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  LightcacheGetDynamic_Stats X[5]; // [esp+0h] [ebp-84h] BYREF
  LightcacheGetDynamic_Stats stats; // [esp+14h] [ebp-70h]
  LightingState_t state; // [esp+18h] [ebp-6Ch] BYREF
  Vector delta; // [esp+74h] [ebp-10h] BYREF
  float fBrightness; // [esp+80h] [ebp-4h]
  float vc_4; // [esp+8Ch] [ebp+8h]
  float vc_4a; // [esp+8Ch] [ebp+8h]

  y = vecCenter->y;
  z = vecCenter->z;
  delta.x = vecCenter->x;
  v8 = 0;
  memset(&X[1], 0, 16);
  stats = 0;
  memset(&state, 0, 56);
  delta.y = y;
  delta.z = z;
  delta.x = floor(X: delta.x * 100.0 + 0.5) * 0.0099999998;
  delta.y = floor(X: delta.y * 100.0 + 0.5) * 0.0099999998;
  delta.z = floor(X: delta.z * 100.0 + 0.5) * 0.0099999998;
  LightcacheGetDynamic(
    origin: &delta,
    lightingState: (LightingState_t *)&X[1],
    stats: X,
    pRenderable: nullptr,
    flags: 1u,
    bDebugModel: false);
  v9 = 0.0;
  v10 = -1;
  v11 = 0.0;
  fBrightness = 0.0;
  state.locallight[3] = nullptr;
  if ( (_S5_0 & 1) == 0 )
  {
    _S5_0 |= 1u;
    colorToGray.x = 0.30000001;
    colorToGray.y = 0.58999997;
    colorToGray.z = 0.11;
  }
  if ( SLODWORD(state.r_boxcolor[4].y) <= 0 )
    return 0;
  do
  {
    v12 = *((_DWORD *)&state.r_boxcolor[4].z + v8);
    if ( (*(_BYTE *)(v12 + 88) & 2) != 0 || bAllowNonTaggedLights )
    {
      v13 = vecCenter->z;
      if ( v13 <= (float)(*(float *)(v12 + 44) + *(float *)(v12 + 8)) )
      {
        *(float *)&state.locallight[2] = (float)((float)(*(float *)(v12 + 16) * colorToGray.y)
                                               + (float)(colorToGray.x * *(float *)(v12 + 12)))
                                       + (float)(*(float *)(v12 + 20) * colorToGray.z);
        if ( v11 < *(float *)&state.locallight[2] )
        {
          *(float *)&state.numlights = *(float *)v12 - vecCenter->x;
          *(float *)state.locallight = *(float *)(v12 + 4) - vecCenter->y;
          *(float *)&state.locallight[1] = *(float *)(v12 + 8) - v13;
          v14 = Engine_WorldLightDistanceFalloff(
                  wl: (const dworldlight_t *)v12,
                  delta: (const Vector *)&state.numlights,
                  bNoRadiusCheck: false);
          vc_4 = v14;
          if ( fBrightness < v14 * *(float *)&state.locallight[2] )
          {
            VectorNormalize(vec: (Vector *)&state.numlights);
            v15 = Engine_WorldLightAngle(
                    wl: *((const dworldlight_t **)&state.r_boxcolor[4].z + v8),
                    lnormal: (const Vector *)(*((_DWORD *)&state.r_boxcolor[4].z + v8) + 24),
                    snormal: (const Vector *)&state.numlights,
                    delta: (const Vector *)&state.numlights);
            v11 = fBrightness;
            vc_4a = v15 * vc_4;
            v9 = vc_4a;
            if ( (float)(vc_4a * *(float *)&state.locallight[2]) <= fBrightness )
            {
              v9 = *(float *)&state.locallight[3];
            }
            else
            {
              v11 = vc_4a * *(float *)&state.locallight[2];
              v10 = v8;
              fBrightness = vc_4a * *(float *)&state.locallight[2];
              *(float *)&state.locallight[3] = vc_4a;
            }
          }
        }
      }
    }
    ++v8;
  }
  while ( v8 < SLODWORD(state.r_boxcolor[4].y) );
  if ( v10 <= -1 )
    return 0;
  v16 = *((float **)&state.r_boxcolor[4].z + v10);
  v17 = v16[10] + v16[1];
  v18 = v16[11] + v16[2];
  lightPos->x = v16[9] + *v16;
  lightPos->y = v17;
  lightPos->z = v18;
  v19 = v16[4];
  v20 = v16[5];
  lightBrightness->x = v16[3] * v9;
  lightBrightness->y = v19 * v9;
  lightBrightness->z = v20 * v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DAE80
// Name: public: virtual void CModelRender::ForcedMaterialOverride(class IMaterial __near *,enum OverrideType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ForcedMaterialOverride(
        CModelRender *this,
        IMaterial *newMaterial,
        OverrideType_t nOverrideType)
{
  g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: newMaterial, a3: nOverrideType);
}

//------------------------------------------------------------------------------
// Address: 0x100DAEA0
// Name: public: bool CRobjectLess::Less(struct robject_t const __near &,struct robject_t const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRobjectLess::Less(CRobjectLess *this, const robject_t *lhs, const robject_t *rhs, float *pContext)
{
  __int16 modelIndex; // cx
  __int16 v5; // dx
  __int16 skin; // ax
  __int16 v7; // cx
  float v9; // xmm0_4
  float v10; // xmm1_4

  modelIndex = lhs->modelIndex;
  v5 = rhs->modelIndex;
  if ( modelIndex == v5 )
  {
    skin = lhs->skin;
    v7 = rhs->skin;
    if ( skin == v7 )
      return lhs->lod < rhs->lod;
    else
      return skin < v7;
  }
  else
  {
    v9 = pContext[5 * modelIndex + 3];
    v10 = pContext[5 * v5 + 3];
    if ( v9 == v10 )
      return modelIndex < v5;
    else
      return v9 > v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAF30
// Name: public: virtual void CModelRender::DrawModelShadow(class IClientRenderable __near *,struct DrawModelInfo_t const __near &,class matrix3x4a_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::DrawModelShadow(
        CModelRender *this,
        IClientRenderable *pRenderable,
        const DrawModelInfo_t *info,
        matrix3x4a_t *pBoneToWorld)
{
  IStudioRender_vtbl *v4; // edi
  int v5; // eax
  float varC[4]; // [esp+Ch] [ebp-Ch] BYREF

  g_pStudioRender->SetEyeViewTarget(this: g_pStudioRender, a2: info->m_pStudioHdr, a3: info->m_Body, a4: &vec3_origin);
  varC[0] = 1.0;
  varC[1] = 1.0;
  varC[2] = 1.0;
  g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: varC);
  ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: 1.0);
  if ( (info->m_pStudioHdr->flags & 0x100) == 0 )
    g_pStudioRender->ForcedMaterialOverride(
      this: g_pStudioRender,
      a2: g_pMaterialShadowBuild,
      a3: OVERRIDE_BUILD_SHADOWS);
  v4 = g_pStudioRender->__vftable;
  v5 = ((int (__thiscall *)(IClientRenderable *, int))pRenderable->GetRenderOrigin)(a1: pRenderable, a2: 36);
  ((void (__thiscall *)(IStudioRender *, _DWORD, const DrawModelInfo_t *, matrix3x4a_t *, _DWORD, _DWORD, int))v4->DrawModel)(
    a1: g_pStudioRender,
    a2: 0,
    a3: info,
    a4: pBoneToWorld,
    a5: 0,
    a6: 0,
    a7: v5);
  g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: nullptr, a3: OVERRIDE_NORMAL);
}

//------------------------------------------------------------------------------
// Address: 0x100DB000
// Name: private: void CModelRender::InitColormeshParams(struct CModelRender::ModelInstance_t __near &,struct studiohwdata_t __near *,struct colormeshparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::InitColormeshParams(
        CModelRender *this,
        CModelRender::ModelInstance_t *instance,
        studiohwdata_t *pStudioHWData,
        int pColorMeshParams)
{
  studiohwdata_t *v6; // ebx
  int m_RootLOD; // edx
  int v8; // eax
  int v9; // ecx
  studioloddata_t *v10; // edi
  int *p_m_NumGroup; // eax
  int v12; // edx
  int v13; // ecx
  studioloddata_t *pLOD; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]
  int lodID; // [esp+1Ch] [ebp+8h]
  int meshID; // [esp+24h] [ebp+10h]

  *(_DWORD *)pColorMeshParams = 0;
  *(_DWORD *)(pColorMeshParams + 4) = 0;
  *(_DWORD *)(pColorMeshParams + 8) = 0;
  if ( (instance->m_nFlags & 2) != 0
    && g_pMaterialSystemHardwareConfig->SupportsStreamOffset(this: g_pMaterialSystemHardwareConfig)
    && r_proplightingpooling.m_pParent != nullptr
    && r_proplightingpooling.m_pParent->m_Value.m_nValue == 1 )
  {
    *(_DWORD *)(pColorMeshParams + 8) = &this->m_colorMeshVBAllocator;
  }
  v6 = pStudioHWData;
  m_RootLOD = pStudioHWData->m_RootLOD;
  lodID = pStudioHWData->m_RootLOD;
  if ( pStudioHWData->m_RootLOD < pStudioHWData->m_NumLODs )
  {
    v8 = 32 * m_RootLOD;
    v15 = 32 * m_RootLOD;
    do
    {
      v9 = 0;
      v10 = (studioloddata_t *)((char *)v6->m_pLODs + v8);
      pLOD = v10;
      meshID = 0;
      if ( v6->m_NumStudioMeshes > 0 )
      {
        do
        {
          p_m_NumGroup = &v10->m_pMeshData[v9].m_NumGroup;
          v12 = 0;
          if ( *p_m_NumGroup > 0 )
          {
            v13 = 0;
            do
            {
              *(_DWORD *)(pColorMeshParams + 4 * (*(_DWORD *)pColorMeshParams)++ + 12) = *(_DWORD *)(v13 + p_m_NumGroup[1] + 20);
              *(_DWORD *)(pColorMeshParams + 4) += *(_DWORD *)(v13 + p_m_NumGroup[1] + 20);
              ++v12;
              v13 += 44;
            }
            while ( v12 < *p_m_NumGroup );
            v6 = pStudioHWData;
            v9 = meshID;
            v10 = pLOD;
          }
          meshID = ++v9;
        }
        while ( v9 < v6->m_NumStudioMeshes );
        m_RootLOD = lodID;
        v8 = v15;
      }
      ++m_RootLOD;
      v8 += 32;
      lodID = m_RootLOD;
      v15 = v8;
    }
    while ( m_RootLOD < v6->m_NumLODs );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB0E0
// Name: bool CheckVarRange_r_rootlod(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CheckVarRange_r_rootlod()
{
  return CheckVarRange_Generic(pVar: &r_rootlod, minVal: 0, maxVal: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100DB100
// Name: void r_lod_f(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_lod_f()
{
  CheckVarRange_Generic(pVar: &r_lod, minVal: -1, maxVal: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100DB120
// Name: public: virtual int CPooledVBAllocator_ColorMesh::Allocate(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPooledVBAllocator_ColorMesh::Allocate(CPooledVBAllocator_ColorMesh *this, int numVerts)
{
  int result; // eax
  int m_numVertsAllocated; // esi

  if ( this->m_pMesh != nullptr )
  {
    if ( this->m_bStartedDeallocation )
    {
      _Warning(
        a1: "ERROR: CPooledVBAllocator_ColorMesh::Allocate being called after some (but not all) calls to Deallocate have bee"
        "n called - invalid! (expect visual artifacts)\n");
      return -1;
    }
    else
    {
      m_numVertsAllocated = this->m_numVertsAllocated;
      if ( numVerts <= this->m_totalVerts - m_numVertsAllocated )
      {
        result = this->m_nextFreeOffset;
        ++this->m_numAllocations;
        this->m_numVertsAllocated = numVerts + m_numVertsAllocated;
        this->m_nextFreeOffset = result + numVerts * this->m_vertexSize;
      }
      else
      {
        _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Allocate failing - not enough space left in the vertex buffer!\n");
        return -1;
      }
    }
  }
  else
  {
    _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Allocate cannot be called before Init (expect a crash)\n");
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DB1A0
// Name: public: virtual void CPooledVBAllocator_ColorMesh::Deallocate(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPooledVBAllocator_ColorMesh::Deallocate(CPooledVBAllocator_ColorMesh *this, int offset, int numVerts)
{
  int m_numVertsAllocated; // eax
  int v5; // ecx
  int v6; // eax

  if ( this->m_pMesh != nullptr )
  {
    if ( this->m_numAllocations != 0 )
    {
      m_numVertsAllocated = numVerts;
      if ( numVerts > this->m_numVertsAllocated )
      {
        _Warning(
          a1: "ERROR: CPooledVBAllocator_ColorMesh::Deallocate called with too many verts, trying to free more than were allo"
          "cated (bug in calling code)\n");
        m_numVertsAllocated = this->m_numVertsAllocated;
      }
      v5 = --this->m_numAllocations;
      this->m_numVertsAllocated -= m_numVertsAllocated;
      v6 = this->m_numVertsAllocated;
      this->m_bStartedDeallocation = true;
      this->m_nextFreeOffset = 0;
      if ( v5 == 0 )
      {
        if ( v6 != 0 )
          _Warning(
            a1: "ERROR: CPooledVBAllocator_ColorMesh::Deallocate, after all allocations have been freed too few verts total h"
            "ave been deallocated (bug in calling code)\n");
        this->m_bStartedDeallocation = false;
      }
    }
    else
    {
      _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Deallocate called too many times! (bug in calling code)\n");
    }
  }
  else
  {
    _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Deallocate cannot be called before Init\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB300
// Name: public: int studiohwdata_t::GetLODForMetric(float)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall studiohwdata_t::GetLODForMetric(studiohwdata_t *this, float lodMetric)
{
  int result; // eax
  float m_fValue; // xmm0_4
  studioloddata_t *m_pLODs; // edx
  int m_NumLODs; // ecx
  int v7; // ecx
  float *i; // edx

  if ( (`studiohwdata_t::GetLODForMetric'::`2'::`local static guard' & 1) == 0 )
  {
    `studiohwdata_t::GetLODForMetric'::`2'::`local static guard' |= 1u;
    ConVarRef::ConVarRef(this: &`studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale, pName: "r_lod_switch_scale");
  }
  if ( this->m_NumLODs == 0 )
    return 0;
  if ( ConVarRef::IsValid(this: &`studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale) )
    m_fValue = `studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale.m_pConVarState->m_Value.m_fValue;
  else
    m_fValue = 1.0;
  m_pLODs = this->m_pLODs;
  m_NumLODs = this->m_NumLODs - 1;
  if ( m_pLODs[this->m_NumLODs - 1].m_SwitchPoint >= 0.0 )
    m_NumLODs = this->m_NumLODs;
  result = this->m_RootLOD;
  v7 = m_NumLODs - 1;
  if ( this->m_RootLOD >= v7 )
    return v7;
  for ( i = &m_pLODs[result + 1].m_SwitchPoint; (float)(*i * m_fValue) <= lodMetric; i += 8 )
  {
    if ( ++result >= v7 )
      return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DB3A0
// Name: private: void thinModelVertices_t::GetNormal(int,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall thinModelVertices_t::GetNormal(thinModelVertices_t *this, int vertIndex, Vector *pNormal)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  float v15; // [esp+0h] [ebp-8h]
  float v16; // [esp+4h] [ebp-4h]
  float v17; // [esp+4h] [ebp-4h]
  int vertIndexa; // [esp+10h] [ebp+8h]
  float vertIndexb; // [esp+10h] [ebp+8h]

  v3 = 0.0;
  v4 = (float)(unsigned __int8)this->m_vecNormals[vertIndex] - 128.0;
  v5 = (float)(unsigned __int8)HIBYTE(this->m_vecNormals[vertIndex]) - 128.0;
  if ( v4 >= 0.0 )
    v6 = 0.0;
  else
    v6 = 1.0;
  v16 = v6;
  if ( v5 < 0.0 )
    v3 = 1.0;
  v7 = -(float)((float)(v6 * 2.0) - 1.0);
  v8 = (float)((float)(v7 * v4) - v16) - 64.0;
  v9 = (float)((float)((float)-(float)((float)(v3 * 2.0) - 1.0) * v5) - v3) - 64.0;
  *(float *)&vertIndexa = v9;
  if ( v8 >= 0.0 )
    v17 = 0.0;
  else
    v17 = 1.0;
  if ( v9 >= 0.0 )
    v10 = 0.0;
  else
    v10 = 1.0;
  v11 = -(float)((float)(v17 * 2.0) - 1.0);
  v12 = (float)((float)(v11 * v8) - v17) * 0.015873017;
  v13 = -(float)((float)(v10 * 2.0) - 1.0);
  v14 = (float)((float)(v13 * *(float *)&vertIndexa) - v10) * 0.015873017;
  v15 = (float)(1.0 - v12) - v14;
  vertIndexb = 1.0 / sqrt(v14 * v14 + v12 * v12 + v15 * v15);
  pNormal->x = (float)(vertIndexb * v11) * v12;
  pNormal->y = (float)(vertIndexb * v13) * v14;
  pNormal->z = (float)(vertIndexb * v7) * v15;
}

//------------------------------------------------------------------------------
// Address: 0x100DB530
// Name: public: void LightingState_t::AddAllLocalLights(struct LightingState_t const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightingState_t::AddAllLocalLights(
        LightingState_t *this,
        const LightingState_t *src,
        const Vector *vecLightingOrigin)
{
  int numlights; // ecx
  dworldlight_t *v5; // ebx
  int v6; // eax
  dworldlight_t **v7; // ecx
  int m_nValue; // edi
  int v9; // eax
  int v10; // ecx
  int i; // [esp+4h] [ebp-8h]
  dworldlight_t **locallight; // [esp+8h] [ebp-4h]

  i = 0;
  if ( src->numlights > 0 )
  {
    locallight = src->locallight;
    do
    {
      numlights = this->numlights;
      v5 = *locallight;
      if ( numlights < 4 )
      {
        v6 = 0;
        if ( numlights <= 0 )
        {
LABEL_8:
          if ( r_worldlights.m_pParent != nullptr )
            m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
          else
            m_nValue = 0;
          if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
          {
            if ( r_worldlights.m_pParent != nullptr )
              v9 = r_worldlights.m_pParent->m_Value.m_nValue;
            else
              v9 = 0;
          }
          else
          {
            v9 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
          }
          v10 = this->numlights;
          if ( v10 >= v9 )
          {
            AddWorldLightToAmbientCube(
              pWorldLight: v5,
              vecLightingOrigin,
              ambientCube: (Vector (*)[6])this,
              bNoLightCull: false);
          }
          else
          {
            this->locallight[v10] = v5;
            ++this->numlights;
          }
        }
        else
        {
          v7 = this->locallight;
          while ( *v7 != v5 )
          {
            ++v6;
            ++v7;
            if ( v6 >= this->numlights )
              goto LABEL_8;
          }
        }
      }
      ++locallight;
      ++i;
    }
    while ( i < src->numlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB600
// Name: R_SetNonAmbientLightingState
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetNonAmbientLightingState(
        int numLights,
        dworldlight_t **locallight,
        int *pNumLightDescs,
        LightDesc_t *pLightDescs,
        bool bUpdateStudioRenderLights)
{
  int *v5; // edx
  int v6; // ebx
  long double v7; // st7
  dworldlight_t *v8; // edi
  emittype_t type; // eax
  LightDesc_t *v10; // esi
  double v11; // st6
  float linear_attn; // xmm2_4
  float quadratic_attn; // xmm4_4
  float exponent; // xmm0_4
  float constant_attn; // xmm3_4
  float radius; // xmm1_4
  long double v17; // st6
  int v18; // ecx
  float v19; // xmm1_4
  float v20; // [esp+8h] [ebp-14h]
  float v21; // [esp+Ch] [ebp-10h]
  float v22; // [esp+10h] [ebp-Ch]
  float v23; // [esp+14h] [ebp-8h]
  float v24; // [esp+18h] [ebp-4h]
  float v25; // [esp+18h] [ebp-4h]

  v5 = pNumLightDescs;
  v6 = 0;
  *pNumLightDescs = 0;
  if ( numLights > 0 )
  {
    v7 = 3.402823466385289e38;
    do
    {
      v8 = locallight[v6];
      type = v8->type;
      v10 = &pLightDescs[*v5];
      if ( type != emit_surface )
      {
        linear_attn = 0.0;
        quadratic_attn = 0.0;
        v23 = 0.0;
        v22 = 0.0;
        v10->m_OneOverThetaDotMinusPhiDot = 1.0;
        switch ( type )
        {
          case emit_point:
            v10->m_Type = MATERIAL_LIGHT_POINT;
            linear_attn = v8->linear_attn;
            quadratic_attn = v8->quadratic_attn;
            constant_attn = v8->constant_attn;
            v23 = linear_attn;
            v22 = quadratic_attn;
            goto LABEL_9;
          case emit_spotlight:
            v10->m_Type = MATERIAL_LIGHT_SPOT;
            v21 = v8->constant_attn;
            v23 = v8->linear_attn;
            v22 = v8->quadratic_attn;
            v10->m_Theta = acos(v8->stopdot);
            v10->m_Phi = acos(v8->stopdot2);
            v10->m_ThetaDot = v8->stopdot;
            v10->m_PhiDot = v8->stopdot2;
            exponent = v8->exponent;
            if ( exponent == 0.0 )
              exponent = 1.0;
            v10->m_Falloff = exponent;
            LightDesc_t::RecalculateOneOverThetaDotMinusPhiDot(this: v10);
            v7 = 3.402823466385289e38;
            quadratic_attn = v22;
            constant_attn = v21;
            linear_attn = v23;
            v5 = pNumLightDescs;
LABEL_9:
            if ( constant_attn == 0.0 && linear_attn == 0.0 && quadratic_attn == 0.0 )
              goto LABEL_12;
            goto LABEL_13;
          case emit_skylight:
            v10->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
            goto LABEL_12;
          case emit_quakelight:
          case emit_skyambient:
            goto $LN4_35;
          default:
LABEL_12:
            constant_attn = 1.0;
LABEL_13:
            v10->m_Color.x = v8->intensity.x;
            v10->m_Color.y = v8->intensity.y;
            v10->m_Color.z = v8->intensity.z;
            v10->m_Position.x = v8->origin.x;
            v10->m_Position.y = v8->origin.y;
            v10->m_Position.z = v8->origin.z;
            v10->m_Direction.x = v8->normal.x;
            v10->m_Direction.y = v8->normal.y;
            v10->m_Direction.z = v8->normal.z;
            radius = v8->radius;
            if ( radius != 0.0 )
              goto LABEL_24;
            v24 = sqrt(v10->m_Color.x * v10->m_Color.x + v10->m_Color.y * v10->m_Color.y + v10->m_Color.z
                                                                                         * v10->m_Color.z);
            if ( quadratic_attn == 0.0 )
            {
              if ( linear_attn != 0.0 )
              {
                radius = (float)((float)(v24 * 33.333336) - constant_attn) / linear_attn;
                goto LABEL_24;
              }
LABEL_22:
              v25 = sqrt(v7);
              goto LABEL_23;
            }
            v20 = (float)(linear_attn * linear_attn)
                - (float)((float)(constant_attn - (float)(v24 * 33.333336)) * (float)(quadratic_attn * 4.0));
            if ( v20 < 0.0 )
              goto LABEL_22;
            v17 = (sqrt(v20) - v23) / (v22 + v22);
            v25 = v17;
            if ( v17 < 0.0 )
            {
              radius = 0.0;
              goto LABEL_24;
            }
LABEL_23:
            radius = v25;
LABEL_24:
            v18 = 8;
            if ( constant_attn != 0.0 )
              v18 = 9;
            if ( linear_attn != 0.0 )
              v18 |= 2u;
            if ( quadratic_attn != 0.0 )
              v18 |= 4u;
            v10->m_Attenuation0 = constant_attn;
            v10->m_Attenuation1 = linear_attn;
            v10->m_Attenuation2 = quadratic_attn;
            v10->m_Range = radius;
            v10->m_Flags = v18;
            break;
        }
      }
      else
      {
        v10->m_Type = MATERIAL_LIGHT_SPOT;
        v10->m_Color.x = v8->intensity.x;
        v10->m_Color.y = v8->intensity.y;
        v10->m_Color.z = v8->intensity.z;
        v10->m_Position.x = v8->origin.x;
        v10->m_Position.y = v8->origin.y;
        v10->m_Position.z = v8->origin.z;
        v10->m_Direction.x = v8->normal.x;
        v10->m_Direction.y = v8->normal.y;
        v10->m_Direction.z = v8->normal.z;
        v11 = v8->radius;
        v10->m_Falloff = 1.0;
        v10->m_Range = v11;
        v10->m_Attenuation0 = 0.0;
        v10->m_Attenuation1 = 0.0;
        v10->m_Attenuation2 = 1.0;
        v10->m_Theta = 1.5707964;
        v10->m_Phi = 1.5707964;
        v10->m_ThetaDot = 0.0;
        v10->m_PhiDot = 0.0;
        v10->m_OneOverThetaDotMinusPhiDot = 1.0;
        v10->m_Flags = 12;
      }
      v19 = (float)d_lightstylevalue[locallight[v6]->style] * 0.0037878789;
      v10->m_Color.x = v19 * v10->m_Color.x;
      v10->m_Color.y = v10->m_Color.y * v19;
      v10->m_Color.z = v10->m_Color.z * v19;
      ++*v5;
$LN4_35:
      ++v6;
    }
    while ( v6 < numLights );
  }
  if ( bUpdateStudioRenderLights )
    g_pStudioRender->SetLocalLights(this: g_pStudioRender, a2: *v5, a3: pLightDescs);
}

//------------------------------------------------------------------------------
// Address: 0x100DB9A0
// Name: void R_ComputeLightingOrigin(class IClientRenderable __near *,struct studiohdr_t __near *,struct matrix3x4_t const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_ComputeLightingOrigin(
        IClientRenderable *pRenderable,
        studiohdr_t *pStudioHdr,
        const matrix3x4_t *matrix,
        Vector *center)
{
  int studiohdr2index; // eax
  int v5; // eax
  matrix3x4_t attachment; // [esp+4h] [ebp-30h] BYREF

  studiohdr2index = pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0 )
    v5 = *(int *)((char *)&pStudioHdr->checksum + studiohdr2index);
  else
    v5 = 0;
  if ( v5 > 0 )
  {
    pRenderable->GetAttachment(this: pRenderable, a2: v5, a3: &attachment);
    VectorTransform(in1: &pStudioHdr->illumposition.x, in2: &attachment, out: &center->x);
  }
  else
  {
    VectorTransform(in1: &pStudioHdr->illumposition.x, in2: matrix, out: &center->x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DBA10
// Name: public: void CModelRender::UnlockCacheCacheHandleArray(int,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::UnlockCacheCacheHandleArray(
        CModelRender *this,
        int nCount,
        memhandle_t__ **pColorMeshHandles)
{
  int i; // esi

  for ( i = 0; i < nCount; ++i )
  {
    if ( pColorMeshHandles[i] != nullptr )
      this->m_pCache->Unlock(this: this->m_pCache, a2: pColorMeshHandles[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DBA50
// Name: public: CModelRender::ModelInstance_t::ModelInstance_t(void)
// Source: json
//------------------------------------------------------------------------------
CModelRender::ModelInstance_t *__thiscall CModelRender::ModelInstance_t::ModelInstance_t(
        CModelRender::ModelInstance_t *this)
{
  CModelRender::ModelInstanceLightingState_t *v2; // eax

  v2 = (CModelRender::ModelInstanceLightingState_t *)CUtlMemoryPool::Alloc(
                                                       this: &CModelRender::ModelInstanceLightingState_t::s_Allocator,
                                                       amount: 0xECu);
  if ( v2 != nullptr )
  {
    v2->m_CurrentLightingState.r_boxcolor[0].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[1].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[0].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[0].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[1].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[1].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[2].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[2].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[2].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[3].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[3].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[3].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[4].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[4].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[4].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[5].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[5].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[5].z = 0.0;
    v2->m_CurrentLightingState.numlights = 0;
    v2->m_AmbientLightingState.r_boxcolor[0].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[1].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[0].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[0].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[1].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[1].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[2].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[2].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[2].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[3].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[3].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[3].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[4].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[4].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[4].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[5].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[5].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[5].z = 0.0;
    v2->m_AmbientLightingState.numlights = 0;
    this->m_pLightingState = v2;
  }
  else
  {
    this->m_pLightingState = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DBB60
// Name: private: void CModelRender::SnapCurrentLightingState(struct CModelRender::ModelInstance_t __near &,struct LightingState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SnapCurrentLightingState(
        CModelRender *this,
        CModelRender::ModelInstance_t *inst,
        LightingState_t *pLightingState)
{
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // esi
  dworldlight_t *v4; // eax
  CClientState *BaseLocalClient; // eax

  m_pLightingState = inst->m_pLightingState;
  LightingState_t::operator=(this: &m_pLightingState->m_CurrentLightingState, __that: pLightingState);
  if ( pLightingState->numlights <= 0 )
  {
    m_pLightingState->m_flLightIntensity[0].x = 0.0;
    m_pLightingState->m_flLightIntensity[0].y = 0.0;
    m_pLightingState->m_flLightIntensity[0].z = 0.0;
  }
  else
  {
    v4 = pLightingState->locallight[0];
    m_pLightingState->m_flLightIntensity[0].x = v4->intensity.x;
    m_pLightingState->m_flLightIntensity[0].y = v4->intensity.y;
    m_pLightingState->m_flLightIntensity[0].z = v4->intensity.z;
  }
  if ( pLightingState->numlights <= 1 )
  {
    m_pLightingState->m_flLightIntensity[1].x = 0.0;
    m_pLightingState->m_flLightIntensity[1].y = 0.0;
    m_pLightingState->m_flLightIntensity[1].z = 0.0;
  }
  else
  {
    m_pLightingState->m_flLightIntensity[1] = pLightingState->locallight[1]->intensity;
  }
  if ( pLightingState->numlights <= 2 )
  {
    m_pLightingState->m_flLightIntensity[2].x = 0.0;
    m_pLightingState->m_flLightIntensity[2].y = 0.0;
    m_pLightingState->m_flLightIntensity[2].z = 0.0;
  }
  else
  {
    m_pLightingState->m_flLightIntensity[2] = pLightingState->locallight[2]->intensity;
  }
  if ( pLightingState->numlights <= 3 )
  {
    m_pLightingState->m_flLightIntensity[3].x = 0.0;
    m_pLightingState->m_flLightIntensity[3].y = 0.0;
    m_pLightingState->m_flLightIntensity[3].z = 0.0;
  }
  else
  {
    m_pLightingState->m_flLightIntensity[3] = pLightingState->locallight[3]->intensity;
  }
  BaseLocalClient = GetBaseLocalClient();
  m_pLightingState->m_flLightingTime = CClientState::GetTime(this: BaseLocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x100DBCA0
// Name: private: void CModelRender::TimeAverageAmbientLight(struct LightingState_t __near &,struct CModelRender::ModelInstance_t __near &,float,struct LightingState_t __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::TimeAverageAmbientLight(
        CModelRender *this,
        LightingState_t *actualLightingState,
        CModelRender::ModelInstance_t *inst,
        float flAttenFactor,
        LightingState_t *pLightingState,
        const Vector *pLightingOrigin)
{
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // edi
  float v7; // xmm6_4
  LightingState_t *v8; // ecx
  LightingState_t *p_m_CurrentLightingState; // esi
  char *v10; // edx
  float *v11; // eax
  int i; // edi
  float v13; // xmm3_4
  float v14; // xmm4_4
  int v15; // xmm0_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm0_4

  m_pLightingState = inst->m_pLightingState;
  if ( flAttenFactor >= 0.0 )
  {
    v7 = 1.0;
    if ( flAttenFactor <= 1.0 )
      v7 = flAttenFactor;
  }
  else
  {
    v7 = 0.0;
  }
  v8 = pLightingState;
  p_m_CurrentLightingState = &m_pLightingState->m_CurrentLightingState;
  v10 = (char *)((char *)pLightingState - (char *)m_pLightingState);
  v11 = (float *)&m_pLightingState->m_CurrentLightingState;
  for ( i = 6; i != 0; --i )
  {
    v13 = v8->r_boxcolor[0].x - (float)((float)(v8->r_boxcolor[0].x - *v11) * v7);
    v14 = *(float *)((char *)v11 + (_DWORD)v10) - (float)((float)(*(float *)((char *)v11 + (_DWORD)v10) - v11[1]) * v7);
    v15 = LODWORD(v13);
    v16 = *(float *)((char *)v11 + (_DWORD)v10 + 4)
        - (float)((float)(*(float *)((char *)v11 + (_DWORD)v10 + 4) - v11[2]) * v7);
    *v11 = v13;
    v11[1] = v14;
    v11[2] = v16;
    if ( v13 >= 0.0 )
    {
      if ( v13 > 8.0 )
        v15 = 1090519040;
    }
    else
    {
      v15 = 0;
    }
    *(_DWORD *)v11 = v15;
    v17 = v11[1];
    if ( v17 >= 0.0 )
    {
      if ( v17 > 8.0 )
        v17 = 8.0;
    }
    else
    {
      v17 = 0.0;
    }
    v11[1] = v17;
    v18 = v11[2];
    if ( v18 >= 0.0 )
    {
      if ( v18 > 8.0 )
        v18 = 8.0;
    }
    else
    {
      v18 = 0.0;
    }
    v11[2] = v18;
    v8 = (LightingState_t *)((char *)v8 + 12);
    v11 += 3;
  }
  qmemcpy(actualLightingState, p_m_CurrentLightingState, 0x48u);
}

//------------------------------------------------------------------------------
// Address: 0x100DBDB0
// Name: private: void CModelRender::EngineLightingToMaterialLighting(struct MaterialLightingState_t __near *,class Vector const __near &,struct LightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::EngineLightingToMaterialLighting(
        CModelRender *this,
        MaterialLightingState_t *pLightingState,
        const Vector *vecLightingOrigin,
        const LightingState_t *srcLightingState)
{
  int v5; // edi
  float *p_y; // esi
  int v7; // eax
  float v8; // xmm0_4
  dworldlight_t **pLightingStatea; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  qmemcpy((void *)pLightingState, srcLightingState, 0x48u);
  pLightingState->m_vecLightingOrigin = *vecLightingOrigin;
  v5 = 0;
  i = 0;
  if ( srcLightingState->numlights > 0 )
  {
    pLightingStatea = srcLightingState->locallight;
    p_y = &pLightingState->m_pLocalLightDesc[0].m_Color.y;
    do
    {
      if ( WorldLightToMaterialLight(pWorldLight: *pLightingStatea, light: (LightDesc_t *)(p_y - 2)) )
      {
        v7 = d_lightstylevalue[(*pLightingStatea)->style];
        if ( v7 != 264 )
        {
          v8 = (float)v7 * 0.0037878789;
          *(p_y - 1) = *(p_y - 1) * v8;
          *p_y = v8 * *p_y;
          p_y[1] = p_y[1] * v8;
        }
        ++v5;
        p_y += 22;
        if ( v5 >= 4 )
          break;
      }
      ++pLightingStatea;
      ++i;
    }
    while ( i < srcLightingState->numlights );
  }
  pLightingState->m_nLocalLightCount = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100DBE80
// Name: private: void CModelRender::DebugDrawLightingOrigin(struct DrawModelState_t const __near &,struct ModelRenderInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::DebugDrawLightingOrigin(
        CModelRender *this,
        const DrawModelState_t *state,
        const DrawModelState_t *pInfo)
{
  const Vector *m_pModelToWorld; // eax
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm1_4
  const matrix3x4_t *m_pRenderable; // eax
  studiohdr_t *m_pStudioHdr; // eax
  const matrix3x4_t *v9; // edx
  studiohdr_t *v10; // eax
  studiohdr_t *v11; // eax
  studiohdr_t *v12; // eax
  const matrix3x4_t *v13; // edx
  studiohdr_t *v14; // eax
  studiohdr_t *v15; // eax
  studiohdr_t *v16; // eax
  const matrix3x4_t *v17; // edx
  studiohdr_t *v18; // eax
  const matrix3x4_t *v19; // [esp-28h] [ebp-60h]
  const matrix3x4_t *v20; // [esp-28h] [ebp-60h]
  Vector center; // [esp+8h] [ebp-30h] BYREF
  float out; // [esp+14h] [ebp-24h] BYREF
  Vector lightOrigin; // [esp+18h] [ebp-20h] BYREF
  Vector pt1; // [esp+24h] [ebp-14h] BYREF
  Vector pt0; // [esp+30h] [ebp-8h]

  m_pModelToWorld = (const Vector *)pInfo[1].m_pModelToWorld;
  if ( m_pModelToWorld != nullptr )
  {
    x = m_pModelToWorld->x;
    center.x = x;
    y = m_pModelToWorld->y;
    center.y = y;
    z = m_pModelToWorld->z;
    center.z = z;
    out = x;
    lightOrigin.x = y;
    lightOrigin.y = z;
  }
  else
  {
    R_ComputeLightingOrigin(
      pRenderable: state->m_pRenderable,
      pStudioHdr: state->m_pStudioHdr,
      matrix: state->m_pModelToWorld,
      &center);
    m_pRenderable = (const matrix3x4_t *)pInfo[1].m_pRenderable;
    x = center.x;
    y = center.y;
    z = center.z;
    out = center.x;
    lightOrigin.x = center.y;
    lightOrigin.y = center.z;
    if ( m_pRenderable != nullptr )
    {
      VectorTransform(in1: &center.x, in2: m_pRenderable, &out);
      z = lightOrigin.y;
      y = lightOrigin.x;
      x = out;
    }
  }
  pt0.x = y;
  pt1.x = y;
  pt0.y = z;
  pt1.y = z;
  pt1.z = x - 4.0;
  lightOrigin.z = x + 4.0;
  CDebugOverlay::AddLineOverlay(
    origin: (Vector *)&pt1.z,
    dest: (Vector *)&lightOrigin.z,
    r: 0,
    g: 255,
    b: 0,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  pt1.z = out;
  lightOrigin.z = out;
  pt0.y = lightOrigin.y;
  pt1.y = lightOrigin.y;
  pt0.x = lightOrigin.x - 4.0;
  pt1.x = lightOrigin.x + 4.0;
  CDebugOverlay::AddLineOverlay(
    origin: (Vector *)&pt1.z,
    dest: (Vector *)&lightOrigin.z,
    r: 0,
    g: 255,
    b: 0,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  m_pStudioHdr = state->m_pStudioHdr;
  v9 = state->m_pModelToWorld;
  pt1.z = state->m_pStudioHdr->hull_min.x;
  pt0.x = m_pStudioHdr->hull_min.y;
  pt0.y = m_pStudioHdr->hull_min.z;
  VectorTransform(in1: &pt1.z, in2: v9, out: &lightOrigin.z);
  CDebugOverlay::AddLineOverlay(
    origin: (const Vector *)&out,
    dest: (Vector *)&lightOrigin.z,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v10 = state->m_pStudioHdr;
  pt1.z = state->m_pStudioHdr->hull_min.x;
  pt0.x = v10->hull_max.y;
  pt0.y = v10->hull_min.z;
  VectorTransform(in1: &pt1.z, in2: state->m_pModelToWorld, out: &lightOrigin.z);
  CDebugOverlay::AddLineOverlay(
    origin: (const Vector *)&out,
    dest: (Vector *)&lightOrigin.z,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v11 = state->m_pStudioHdr;
  pt1.z = state->m_pStudioHdr->hull_max.x;
  pt0.x = v11->hull_max.y;
  v19 = state->m_pModelToWorld;
  pt0.y = v11->hull_min.z;
  VectorTransform(in1: &pt1.z, in2: v19, out: &lightOrigin.z);
  CDebugOverlay::AddLineOverlay(
    origin: (const Vector *)&out,
    dest: (Vector *)&lightOrigin.z,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v12 = state->m_pStudioHdr;
  v13 = state->m_pModelToWorld;
  pt1.z = state->m_pStudioHdr->hull_max.x;
  pt0.x = v12->hull_min.y;
  pt0.y = v12->hull_min.z;
  VectorTransform(in1: &pt1.z, in2: v13, out: &lightOrigin.z);
  CDebugOverlay::AddLineOverlay(
    origin: (const Vector *)&out,
    dest: (Vector *)&lightOrigin.z,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v14 = state->m_pStudioHdr;
  pt1.z = state->m_pStudioHdr->hull_min.x;
  pt0.x = v14->hull_min.y;
  pt0.y = v14->hull_max.z;
  VectorTransform(in1: &pt1.z, in2: state->m_pModelToWorld, out: &lightOrigin.z);
  CDebugOverlay::AddLineOverlay(
    origin: (const Vector *)&out,
    dest: (Vector *)&lightOrigin.z,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v15 = state->m_pStudioHdr;
  pt1.z = state->m_pStudioHdr->hull_min.x;
  pt0.x = v15->hull_max.y;
  v20 = state->m_pModelToWorld;
  pt0.y = v15->hull_max.z;
  VectorTransform(in1: &pt1.z, in2: v20, out: &lightOrigin.z);
  CDebugOverlay::AddLineOverlay(
    origin: (const Vector *)&out,
    dest: (Vector *)&lightOrigin.z,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v16 = state->m_pStudioHdr;
  v17 = state->m_pModelToWorld;
  pt1.z = state->m_pStudioHdr->hull_max.x;
  pt0.x = v16->hull_max.y;
  pt0.y = v16->hull_max.z;
  VectorTransform(in1: &pt1.z, in2: v17, out: &lightOrigin.z);
  CDebugOverlay::AddLineOverlay(
    origin: (const Vector *)&out,
    dest: (Vector *)&lightOrigin.z,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v18 = state->m_pStudioHdr;
  pt1.z = state->m_pStudioHdr->hull_max.x;
  pt0.x = v18->hull_min.y;
  pt0.y = v18->hull_max.z;
  VectorTransform(in1: &pt1.z, in2: state->m_pModelToWorld, out: &lightOrigin.z);
  CDebugOverlay::AddLineOverlay(
    origin: (const Vector *)&out,
    dest: (Vector *)&lightOrigin.z,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100DC2A0
// Name: public: virtual int CModelRender::DrawModel(int,class IClientRenderable __near *,unsigned short,int,struct model_t const __near *,class Vector const __near &,class QAngle const __near &,int,int,int,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::DrawModel(
        CModelRender *this,
        int flags,
        IClientRenderable *pRenderable,
        unsigned __int16 instance,
        int entity_index,
        const model_t *pModel,
        const Vector *origin,
        const QAngle *angles,
        int skin,
        int body,
        int hitboxset,
        const matrix3x4_t *pModelToWorld,
        const matrix3x4_t *pLightingOffset)
{
  float z; // xmm0_4
  int m_nValue; // eax
  ModelRenderInfo_t sInfo; // [esp+0h] [ebp-44h] BYREF

  sInfo.flags = flags;
  sInfo.instance = instance;
  sInfo.pModel = pModel;
  sInfo.origin = *origin;
  sInfo.angles.x = angles->x;
  sInfo.angles.y = angles->y;
  z = angles->z;
  sInfo.skin = skin;
  sInfo.body = body;
  sInfo.hitboxset = hitboxset;
  sInfo.pModelToWorld = pModelToWorld;
  sInfo.pLightingOffset = pLightingOffset;
  sInfo.pRenderable = pRenderable;
  sInfo.pLightingOrigin = nullptr;
  sInfo.entity_index = entity_index;
  sInfo.angles.z = z;
  if ( r_entity.m_pParent != nullptr )
  {
    m_nValue = r_entity.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
      return this->DrawModelEx(this, a2: &sInfo);
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue == entity_index )
    return this->DrawModelEx(this, a2: &sInfo);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100DC360
// Name: private: int CModelRender::ComputeLOD(class IMatRenderContext __near *,struct ModelRenderInfo_t const __near &,struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::ComputeLOD(
        CModelRender *this,
        IMatRenderContext *pRenderContext,
        const ModelRenderInfo_t *info,
        studiohwdata_t *pStudioHWData)
{
  int result; // eax
  IMatRenderContext_vtbl *v5; // edi
  int v6; // eax
  double v7; // st7
  float v8; // xmm0_4
  studiohwdata_t *v9; // esi
  int v10; // ecx
  int m_NumLODs; // ecx
  int m_RootLOD; // esi
  float v13; // [esp+18h] [ebp+Ch]

  if ( r_lod.m_pParent != nullptr )
  {
    result = r_lod.m_pParent->m_Value.m_nValue;
    if ( result == -1 )
    {
      v5 = pRenderContext->__vftable;
      v6 = ((int (__stdcall *)(_DWORD))info->pRenderable->GetRenderOrigin)(a1: 0.5);
      v7 = ((double (__thiscall *)(IMatRenderContext *, int))v5->ComputePixelWidthOfSphere)(a1: pRenderContext, a2: v6);
      if ( v7 == 0.0 )
      {
        v8 = 0.0;
      }
      else
      {
        v13 = v7;
        v8 = 100.0 / v13;
      }
      v9 = pStudioHWData;
      result = studiohwdata_t::GetLODForMetric(this: pStudioHWData, lodMetric: v8);
      goto LABEL_19;
    }
  }
  else
  {
    result = 0;
  }
  v9 = pStudioHWData;
  if ( (info->flags & 0x40) == 0 || (v10 = pStudioHWData->m_NumLODs - 2, result <= v10) )
  {
    v10 = pStudioHWData->m_NumLODs - 1;
    if ( result <= v10 )
    {
      if ( result < 0 )
        result = 0;
      goto LABEL_11;
    }
  }
  result = v10;
LABEL_19:
  if ( result < 0 )
  {
    result = 0;
    goto LABEL_13;
  }
LABEL_11:
  m_NumLODs = v9->m_NumLODs;
  if ( result >= m_NumLODs )
    result = m_NumLODs - 1;
LABEL_13:
  m_RootLOD = v9->m_RootLOD;
  if ( result < m_RootLOD )
    return m_RootLOD;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DC420
// Name: public: virtual void CModelRender::SetViewTarget(class CStudioHdr const __near *,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetViewTarget(
        CModelRender *this,
        const CStudioHdr *pStudioHdr,
        int nBodyIndex,
        const Vector *target)
{
  g_pStudioRender->SetEyeViewTarget(this: g_pStudioRender, a2: pStudioHdr->m_pStudioHdr, a3: nBodyIndex, a4: target);
}

//------------------------------------------------------------------------------
// Address: 0x100DC4D0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC710
// Name: public: struct mstudio_modelvertexdata_t const __near * mstudiomodel_t::GetVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
vertexFileHeader_t *__thiscall mstudiomodel_t::GetVertexData(mstudiomodel_t *this, void *pModelData)
{
  vertexFileHeader_t *result; // eax
  int vertexDataStart; // ecx
  char *v5; // edx
  mstudio_modelvertexdata_t *p_vertexdata; // ecx
  int tangentDataStart; // esi

  result = g_pMDLCache->GetVertexData(this: g_pMDLCache, a2: LOWORD(s_ModelRender.m_pStudioHdr->virtualModel));
  if ( result != nullptr )
  {
    if ( result->id == 1448297545 && (vertexDataStart = result->vertexDataStart) != 0 )
      v5 = (char *)result + vertexDataStart;
    else
      v5 = nullptr;
    p_vertexdata = &this->vertexdata;
    this->vertexdata.pVertexData = v5;
    if ( result->id == 1448297545 && (tangentDataStart = result->tangentDataStart) != 0 )
    {
      this->vertexdata.pTangentData = (char *)result + tangentDataStart;
      return v5 != nullptr ? (vertexFileHeader_t *)p_vertexdata : nullptr;
    }
    else
    {
      this->vertexdata.pTangentData = nullptr;
      return v5 != nullptr ? (vertexFileHeader_t *)p_vertexdata : nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DC790
// Name: public: char const __near * studiohdr_t::pszName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall studiohdr_t::pszName(studiohdr_t *this)
{
  int studiohdr2index; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // ecx

  studiohdr2index = this->studiohdr2index;
  if ( studiohdr2index == 0 )
    return this->name;
  v2 = *(_DWORD *)&this->name[studiohdr2index + 8];
  v3 = (char *)this + studiohdr2index;
  if ( v2 == 0 || &v3[v2] == nullptr )
    return this->name;
  v4 = *((_DWORD *)v3 + 5);
  if ( v4 != 0 )
    return &v3[v4];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100DC7C0
// Name: void UpdateStudioRenderConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateStudioRenderConfig()
{
  int m_nValue; // eax
  char v1; // al
  char v2; // al
  int v3; // ecx
  char v4; // al
  int v5; // ecx
  char v6; // al
  int v7; // ecx
  char v8; // al
  int v9; // ecx
  char v10; // al
  int v11; // ecx
  ConVar *m_pParent; // edx
  char v13; // al
  bool IsRptActive; // al
  bool v15; // zf
  ConVar *v16; // esi
  int v17; // ecx
  char v18; // cl
  char v19; // cl
  char v20; // al
  int v21; // ecx
  char v22; // al
  int v23; // ecx
  char v24; // al
  int v25; // ecx

  if ( g_pMaterialSystemConfig == nullptr || g_pStudioRender == nullptr )
    return;
  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig, value: 0, count: sizeof(s_StudioRenderConfig));
  if ( r_eyemove.m_pParent != nullptr )
    m_nValue = r_eyemove.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v1 = (*((_BYTE *)&s_StudioRenderConfig + 36) ^ (m_nValue != 0)) & 1 ^ *((_BYTE *)&s_StudioRenderConfig + 36);
  *((_BYTE *)&s_StudioRenderConfig + 36) = v1;
  s_StudioRenderConfig.fEyeShiftX = r_eyeshift_x.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftY = r_eyeshift_y.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftZ = r_eyeshift_z.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeSize = r_eyesize.m_pParent->m_Value.m_fValue;
  if ( mat_softwareskin.m_pParent == nullptr || mat_softwareskin.m_pParent->m_Value.m_nValue == 0 )
  {
    if ( !ShouldDrawInWireFrameMode()
      && (r_slowpathwireframe.m_pParent == nullptr || r_slowpathwireframe.m_pParent->m_Value.m_nValue == 0) )
    {
      v2 = *((_BYTE *)&s_StudioRenderConfig + 36) & 0xFD;
      goto LABEL_14;
    }
    v1 = *((_BYTE *)&s_StudioRenderConfig + 36);
  }
  v2 = v1 | 2;
LABEL_14:
  *((_BYTE *)&s_StudioRenderConfig + 36) = v2;
  if ( r_nohw.m_pParent != nullptr )
    v3 = r_nohw.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  v4 = (v2 ^ (4 * (v3 != 0))) & 4 ^ v2;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v4;
  if ( r_nosw.m_pParent != nullptr )
    v5 = r_nosw.m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  v6 = (v4 ^ (8 * (v5 != 0))) & 8 ^ v4;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v6;
  if ( r_teeth.m_pParent != nullptr )
    v7 = r_teeth.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  v8 = (v6 ^ (16 * (v7 != 0))) & 0x10 ^ v6;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v8;
  if ( r_drawentities.m_pParent != nullptr )
    s_StudioRenderConfig.drawEntities = r_drawentities.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.drawEntities = 0;
  if ( r_flex.m_pParent != nullptr )
    v9 = r_flex.m_pParent->m_Value.m_nValue;
  else
    v9 = 0;
  v10 = (v8 ^ ((v9 != 0) << 6)) & 0x40 ^ v8;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v10;
  if ( r_eyes.m_pParent != nullptr )
    v11 = r_eyes.m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  m_pParent = sv_cheats.m_pParent;
  v13 = (v10 ^ (32 * (v11 != 0))) & 0x20 ^ v10;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v13;
  if ( sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0
    || (IsRptActive = Cmd_IsRptActive(),
        m_pParent = sv_cheats.m_pParent,
        v15 = !IsRptActive,
        v13 = *((_BYTE *)&s_StudioRenderConfig + 36),
        !v15) )
  {
    v16 = mat_wireframe.m_pParent;
    if ( mat_wireframe.m_pParent != nullptr )
      v17 = mat_wireframe.m_pParent->m_Value.m_nValue;
    else
      v17 = 0;
    if ( v17 != 0 )
      goto LABEL_39;
  }
  else
  {
    v16 = mat_wireframe.m_pParent;
  }
  if ( r_slowpathwireframe.m_pParent != nullptr && r_slowpathwireframe.m_pParent->m_Value.m_nValue != 0 )
  {
LABEL_39:
    v18 = 1;
    goto LABEL_40;
  }
  v18 = 0;
LABEL_40:
  *((_BYTE *)&s_StudioRenderConfig + 36) = v13 & 0x7F | (v18 << 7);
  if ( *((char *)&s_StudioRenderConfig + 36) >= 0 )
    goto LABEL_52;
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
LABEL_45:
    if ( v16 == nullptr || v16->m_Value.m_nValue != 1 )
      goto LABEL_47;
LABEL_52:
    v19 = 0;
    goto LABEL_53;
  }
  if ( Cmd_IsRptActive() )
  {
    v16 = mat_wireframe.m_pParent;
    goto LABEL_45;
  }
LABEL_47:
  v19 = 1;
LABEL_53:
  v20 = (*((_BYTE *)&s_StudioRenderConfig + 37) ^ (4 * v19)) & 4 ^ *((_BYTE *)&s_StudioRenderConfig + 37);
  *((_BYTE *)&s_StudioRenderConfig + 37) = v20;
  if ( mat_normals.m_pParent != nullptr )
    v21 = mat_normals.m_pParent->m_Value.m_nValue;
  else
    v21 = 0;
  v22 = (v20 ^ (v21 != 0)) & 1 ^ v20;
  *((_BYTE *)&s_StudioRenderConfig + 37) = v22;
  if ( r_skin.m_pParent != nullptr )
    s_StudioRenderConfig.skin = r_skin.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.skin = 0;
  if ( r_maxmodeldecal.m_pParent != nullptr )
    s_StudioRenderConfig.maxDecalsPerModel = r_maxmodeldecal.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.maxDecalsPerModel = 0;
  if ( r_modelwireframedecal.m_pParent != nullptr )
    v23 = r_modelwireframedecal.m_pParent->m_Value.m_nValue;
  else
    v23 = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = (v22 ^ (32 * (v23 != 0))) & 0x20 ^ v22;
  s_StudioRenderConfig.fullbright = g_pMaterialSystemConfig->nFullbright;
  v24 = (*((_BYTE *)&s_StudioRenderConfig + 37)
       ^ (8 * g_pMaterialSystemConfig->bSoftwareLighting))
      & 8
      ^ *((_BYTE *)&s_StudioRenderConfig + 37);
  *((_BYTE *)&s_StudioRenderConfig + 37) = v24;
  if ( r_showenvcubemap.m_pParent != nullptr )
    v25 = r_showenvcubemap.m_pParent->m_Value.m_nValue;
  else
    v25 = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = (v24 ^ (16 * (v25 != 0))) & 0x10 ^ v24;
  s_StudioRenderConfig.fEyeGlintPixelWidthLODThreshold = r_eyeglintlodpixels.m_pParent->m_Value.m_fValue;
  g_pStudioRender->UpdateConfig(this: g_pStudioRender, a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x100DCB20
// Name: void InitStudioRender(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitStudioRender()
{
  _DWORD v0[4]; // [esp+0h] [ebp-10h] BYREF

  UpdateStudioRenderConfig();
  v0[0] = -1;
  v0[1] = -1;
  v0[2] = 0;
  v0[3] = 0;
  if ( s_ModelRender.m_pCache == nullptr )
    s_ModelRender.m_pCache = g_pDataCache->AddSection(
                               this: g_pDataCache,
                               a2: &s_ModelRender.CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,
                               a3: "ColorMesh",
                               a4: v0,
                               a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100DCB70
// Name: void ShutdownStudioRender(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownStudioRender()
{
  IDataCacheSection *m_pCache; // esi
  int *v1; // ebx
  int v2; // edi
  int v3; // eax

  if ( s_ModelRender.m_pCache != nullptr )
  {
    m_pCache = s_ModelRender.m_pCache;
    v1 = (int *)((int (*)(void))s_ModelRender.m_pCache->GetSharedCache)();
    if ( m_pCache != nullptr )
    {
      v2 = *v1;
      v3 = ((int (__thiscall *)(IDataCacheSection *, int))m_pCache->GetName)(a1: m_pCache, a2: 1);
      (*(void (__thiscall **)(int *, int))(v2 + 52))(a1: v1, a2: v3);
    }
    s_ModelRender.m_pCache = nullptr;
  }
  s_ModelRender.m_colorMeshVBAllocator.Clear(this: &s_ModelRender.m_colorMeshVBAllocator);
}

//------------------------------------------------------------------------------
// Address: 0x100DCBC0
// Name: unsigned short __near & FirstShadowOnModelInstance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl FirstShadowOnModelInstance(unsigned __int16 handle)
{
  return &s_ModelRender.m_ModelInstances.m_Memory.m_pMemory[handle].m_Element.m_FirstShadow;
}

//------------------------------------------------------------------------------
// Address: 0x100DCBE0
// Name: private: struct LightingState_t __near * CModelRender::TimeAverageLightingState(unsigned short,struct LightingState_t __near *,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
LightingState_t *__thiscall CModelRender::TimeAverageLightingState(
        CModelRender *this,
        unsigned __int16 handle,
        LightingState_t *pLightingState,
        int nEntIndex,
        const Vector *pLightingOrigin)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v7; // ebx
  dworldlight_t *m_pLightingState; // edi
  float x; // xmm0_4
  CClientState *BaseLocalClient; // eax
  double v11; // st7
  CClientState *v12; // eax
  long double v13; // st7
  long double v14; // rt0
  int m_nValue; // esi
  LightingState_t *v16; // esi
  dworldlight_t *numlights; // eax
  float *v18; // ecx
  dworldlight_t **locallight; // esi
  int v20; // eax
  dworldlight_t **p_linear_attn; // edx
  int v22; // eax
  double v23; // st7
  int v24; // eax
  bool v25; // cc
  dworldlight_t *v26; // xmm4_4
  float z; // ecx
  const void **v28; // eax
  dworldlight_t *v29; // edx
  float *v30; // ebx
  float *v31; // eax
  float v32; // ecx
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  int v37; // ecx
  float v38; // esi
  const void **v39; // edx
  float v40; // eax
  dworldlight_t *v41; // ebx
  LightingState_t *v42; // esi
  const void *v43; // ecx
  float v44; // xmm2_4
  float v45; // xmm1_4
  int v46; // edx
  _DWORD *p_quadratic_attn; // esi
  float *p_z; // eax
  float *p_owner; // ecx
  int v50; // ebx
  int v51; // ebx
  int v52; // ebx
  int v53; // ebx
  double v54; // st7
  float *v55; // eax
  int v56; // ebx
  float *v57; // edi
  float *v58; // esi
  int v59; // edx
  double v60; // st7
  _BYTE v61[12]; // [esp+20h] [ebp-50h] BYREF
  Vector pLight[4]; // [esp+2Ch] [ebp-44h] BYREF
  dworldlight_t *pSourceLight[4]; // [esp+5Ch] [ebp-14h]
  float flInterpFactor; // [esp+6Ch] [ebp-4h]
  float pMatch; // [esp+78h] [ebp+8h]
  int pMatcha; // [esp+78h] [ebp+8h]
  LightingState_t *pLightingStatea; // [esp+7Ch] [ebp+Ch]

  if ( r_lightaverage.m_pParent == nullptr )
    return pLightingState;
  if ( r_lightaverage.m_pParent->m_Value.m_nValue == 0 )
    return pLightingState;
  pLight[3].z = r_lightinterp.m_pParent->m_Value.m_fValue;
  if ( pLight[3].z == 0.0 || handle == 0xFFFF )
    return pLightingState;
  v7 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  m_pLightingState = (dworldlight_t *)v7->m_Element.m_pLightingState;
  x = m_pLightingState->origin.x;
  pSourceLight[0] = m_pLightingState;
  if ( x == -999999.0 )
  {
    CModelRender::SnapCurrentLightingState(this, inst: &v7->m_Element, pLightingState);
    return pLightingState;
  }
  BaseLocalClient = GetBaseLocalClient();
  v11 = CClientState::GetTime(this: BaseLocalClient) - m_pLightingState->origin.x;
  pMatch = v11;
  if ( v11 > 0.0 )
  {
    v12 = GetBaseLocalClient();
    m_pLightingState->origin.x = CClientState::GetTime(this: v12);
  }
  else
  {
    pMatch = 0.0;
  }
  if ( (_S3_2 & 1) == 0 )
    _S3_2 |= 1u;
  v13 = -(pMatch * pLight[3].z) * 1.442695040888963407;
  v14 = rint(v13);
  *(float *)&pSourceLight[1] = __FSCALE__(__F2XM1__(v13 - v14) + 1.0, v14);
  CModelRender::TimeAverageAmbientLight(
    this,
    actualLightingState: &actualLightingState,
    inst: &v7->m_Element,
    flAttenFactor: *(float *)&pSourceLight[1],
    pLightingState,
    pLightingOrigin);
  if ( g_pMaterialSystemConfig->bSoftwareLighting )
  {
    if ( r_worldlights.m_pParent != nullptr )
    {
      pMatcha = r_worldlights.m_pParent->m_Value.m_nValue;
      goto LABEL_24;
    }
    goto LABEL_23;
  }
  if ( r_worldlights.m_pParent != nullptr )
    m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
  {
    if ( r_worldlights.m_pParent != nullptr )
    {
      pMatcha = r_worldlights.m_pParent->m_Value.m_nValue;
      goto LABEL_24;
    }
LABEL_23:
    pMatcha = 0;
    goto LABEL_24;
  }
  pMatcha = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
LABEL_24:
  v16 = pLightingState;
  numlights = (dworldlight_t *)pLightingState->numlights;
  pSourceLight[2] = nullptr;
  if ( (int)numlights > 0 )
  {
    v18 = (float *)v61;
    locallight = pLightingState->locallight;
    pSourceLight[3] = numlights;
    do
    {
      v20 = 0;
      *(v18 - 2) = 0.0;
      *(v18 - 1) = 0.0;
      *v18 = 0.0;
      if ( SLODWORD(m_pLightingState->constant_attn) > 0 )
      {
        p_linear_attn = (dworldlight_t **)&m_pLightingState->linear_attn;
        while ( *locallight != *p_linear_attn )
        {
          ++v20;
          ++p_linear_attn;
          if ( v20 >= SLODWORD(m_pLightingState->constant_attn) )
            goto LABEL_32;
        }
        *((_BYTE *)&pSourceLight[2] + v20) = 1;
        v22 = 3 * v20;
        v23 = *((float *)&m_pLightingState[1].flags + v22);
        v24 = (int)(&m_pLightingState[1].flags + v22);
        *(v18 - 2) = v23;
        *(v18 - 1) = *(float *)(v24 + 4);
        *v18 = *(float *)(v24 + 8);
      }
LABEL_32:
      ++locallight;
      v18 += 3;
      --pSourceLight[3];
    }
    while ( pSourceLight[3] != nullptr );
    v16 = pLightingState;
  }
  v25 = v16->numlights <= 0;
  v26 = pSourceLight[1];
  flInterpFactor = 0.0;
  if ( !v25 )
  {
    LODWORD(z) = (char *)&actualLightingState - (char *)pLightingState;
    v28 = (const void **)v16->locallight;
    v29 = s_WorldLights;
    pSourceLight[3] = (dworldlight_t *)v16->locallight;
    v30 = (float *)v61;
    LODWORD(pLight[3].z) = (char *)&actualLightingState - (char *)pLightingState;
    while ( 1 )
    {
      pSourceLight[3] = (dworldlight_t *)((char *)pSourceLight[3] + 4);
      *(const void **)((char *)v28 + LODWORD(z)) = v29;
      qmemcpy(v29, *v28, sizeof(dworldlight_t));
      v31 = (float *)*v28;
      v32 = flInterpFactor;
      v33 = v31[3] - (float)((float)(v31[3] - *(v30 - 2)) * *(float *)&v26);
      v34 = v31[4] - (float)((float)(v31[4] - *(v30 - 1)) * *(float *)&v26);
      v35 = v31[5];
      v36 = (float)(v35 - *v30) * *(float *)&v26;
      *((_DWORD *)&pLight[2].y + LODWORD(flInterpFactor)) = v31;
      v29->intensity.x = v33;
      v29->intensity.y = v34;
      v29->intensity.z = v35 - v36;
      v30 += 3;
      ++v29;
      LODWORD(flInterpFactor) = LODWORD(v32) + 1;
      if ( LODWORD(v32) + 1 >= pLightingState->numlights )
        break;
      v28 = (const void **)pSourceLight[3];
      z = pLight[3].z;
    }
    m_pLightingState = pSourceLight[0];
  }
  v37 = pLightingState->numlights;
  v38 = 0.0;
  pLightingStatea = (LightingState_t *)v37;
  flInterpFactor = 0.0;
  if ( SLODWORD(m_pLightingState->constant_attn) > 0 )
  {
    v39 = (const void **)&m_pLightingState->linear_attn;
    LODWORD(v40) = &m_pLightingState[1].owner;
    v41 = &s_WorldLights[v37];
    pSourceLight[3] = (dworldlight_t *)&m_pLightingState->linear_attn;
    LODWORD(pLight[3].z) = &m_pLightingState[1].owner;
    do
    {
      if ( *((_BYTE *)&pSourceLight[2] + LODWORD(v38)) == 0
        && (float)((float)((float)(*(float *)(LODWORD(v40) - 8) * *(float *)(LODWORD(v40) - 8))
                         + (float)(*(float *)(LODWORD(v40) - 4) * *(float *)(LODWORD(v40) - 4)))
                 + (float)(*(float *)LODWORD(v40) * *(float *)LODWORD(v40))) >= 1.0 )
      {
        if ( (int)v41 >= (int)&_S3_2 )
          break;
        actualLightingState.locallight[v37] = v41;
        qmemcpy(v41, *v39, sizeof(dworldlight_t));
        v42 = pLightingStatea;
        v43 = *v39;
        v44 = *(float *)&v26 * *(float *)LODWORD(v40);
        v45 = *(float *)(LODWORD(v40) - 4) * *(float *)&v26;
        v41->intensity.x = *(float *)&v26 * *(float *)(LODWORD(v40) - 8);
        v41->intensity.y = v45;
        v41->intensity.z = v44;
        *((_DWORD *)&pLight[2].y + (_DWORD)pLightingStatea) = v43;
        if ( (int)pLightingStatea >= pMatcha && pLightingOrigin != nullptr )
        {
          AddWorldLightToAmbientCube(
            pWorldLight: v41,
            vecLightingOrigin: pLightingOrigin,
            ambientCube: (Vector (*)[6])&actualLightingState,
            bNoLightCull: true);
          v26 = pSourceLight[1];
          v40 = pLight[3].z;
          v39 = (const void **)pSourceLight[3];
        }
        m_pLightingState = pSourceLight[0];
        pLightingStatea = (LightingState_t *)((char *)pLightingStatea + 1);
        v37 = (int)&v42->r_boxcolor[0].x + 1;
        v38 = flInterpFactor;
        ++v41;
      }
      ++LODWORD(v38);
      ++v39;
      LODWORD(v40) += 12;
      flInterpFactor = v38;
      pSourceLight[3] = (dworldlight_t *)v39;
      pLight[3].z = v40;
    }
    while ( SLODWORD(v38) < SLODWORD(m_pLightingState->constant_attn) );
  }
  actualLightingState.numlights = v37;
  if ( v37 >= pMatcha )
    actualLightingState.numlights = pMatcha;
  v46 = 0;
  LODWORD(m_pLightingState->constant_attn) = v37;
  if ( v37 >= 4 )
  {
    p_quadratic_attn = (_DWORD *)&m_pLightingState->quadratic_attn;
    p_z = &s_WorldLights[0].intensity.z;
    p_owner = (float *)&m_pLightingState[1].owner;
    do
    {
      v50 = *((_DWORD *)&pLight[2].y + v46);
      *(p_owner - 2) = *(p_z - 2);
      *(p_quadratic_attn - 1) = v50;
      v51 = *((_DWORD *)&pLight[2].z + v46);
      *(p_owner - 1) = *(p_z - 1);
      *p_quadratic_attn = v51;
      v52 = *((_DWORD *)&pLight[3].x + v46);
      *p_owner = *p_z;
      p_quadratic_attn[1] = v52;
      v53 = *((_DWORD *)&pLight[3].y + v46);
      p_owner[1] = p_z[23];
      p_quadratic_attn[2] = v53;
      p_owner[2] = p_z[24];
      v46 += 4;
      p_owner[3] = p_z[25];
      p_quadratic_attn += 4;
      v54 = p_z[48];
      p_z += 100;
      p_owner[4] = v54;
      p_owner += 12;
      *(p_owner - 7) = *(p_z - 51);
      *(p_owner - 6) = *(p_z - 50);
      *(p_owner - 5) = *(p_z - 27);
      *(p_owner - 4) = *(p_z - 26);
      *(p_owner - 3) = *(p_z - 25);
    }
    while ( v46 < (int)&pLightingStatea[-1].locallight[3] + 1 );
    v37 = (int)pLightingStatea;
  }
  if ( v46 < v37 )
  {
    v55 = &s_WorldLights[v46].intensity.z;
    v56 = (int)(&m_pLightingState[1].owner + 3 * v46);
    v57 = &m_pLightingState->linear_attn + v46;
    v58 = &pLight[2].y + v46;
    v59 = v37 - v46;
    qmemcpy(v57, v58, 4 * v59);
    do
    {
      v60 = *(v55 - 2);
      v55 += 25;
      *(float *)(v56 - 8) = v60;
      v56 += 12;
      --v59;
      *(float *)(v56 - 16) = *(v55 - 26);
      *(float *)(v56 - 12) = *(v55 - 25);
    }
    while ( v59 != 0 );
  }
  return &actualLightingState;
}

//------------------------------------------------------------------------------
// Address: 0x100DD0A0
// Name: private: int CModelRender::GetLightingConditions(class Vector const __near &,class Vector __near *,int,struct LightDesc_t __near *,class ITexture __near * __near &,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::GetLightingConditions(
        CModelRender *this,
        const Vector *vecLightingOrigin,
        Vector *pColors,
        int nMaxLocalLights,
        LightDesc_t *pLocalLights,
        ITexture **pEnvCubemapTexture,
        unsigned __int16 handle,
        int bAllowFast)
{
  ITexture **v8; // ebx
  unsigned __int16 v9; // si
  IClientRenderable *m_pRenderable; // eax
  unsigned int v11; // ecx
  LightingState_t *p_state; // ebx
  bool v13; // cc
  float *p_y; // esi
  dworldlight_t **i; // edi
  int v16; // eax
  float v17; // xmm0_4
  int result; // eax
  LightingState_t state; // [esp+0h] [ebp-64h] BYREF
  CModelRender *v20; // [esp+5Ch] [ebp-8h]
  int nLightCount; // [esp+60h] [ebp-4h]

  v8 = pEnvCubemapTexture;
  v9 = handle;
  m_pRenderable = nullptr;
  v20 = this;
  nLightCount = 0;
  memset(&state, 0, 76);
  *pEnvCubemapTexture = nullptr;
  if ( v9 != 0xFFFF )
    m_pRenderable = this->m_ModelInstances.m_Memory.m_pMemory[v9].m_Element.m_pRenderable;
  v11 = 7;
  if ( (_BYTE)bAllowFast != 0 )
    v11 = 15;
  *v8 = LightcacheGetDynamic(
          origin: vecLightingOrigin,
          lightingState: &state,
          stats: (LightcacheGetDynamic_Stats *)&pEnvCubemapTexture,
          pRenderable: m_pRenderable,
          flags: v11,
          bDebugModel: false);
  p_state = &state;
  if ( v9 != 0xFFFF )
    p_state = CModelRender::TimeAverageLightingState(
                this: v20,
                handle: v9,
                pLightingState: &state,
                nEntIndex: 0,
                pLightingOrigin: vecLightingOrigin);
  qmemcpy(pColors, p_state, 0x48u);
  v13 = p_state->numlights <= 0;
  bAllowFast = 0;
  if ( v13 )
    return nLightCount;
  p_y = &pLocalLights->m_Color.y;
  for ( i = p_state->locallight; ; ++i )
  {
    if ( WorldLightToMaterialLight(pWorldLight: *i, light: (LightDesc_t *)(p_y - 2)) )
    {
      v16 = d_lightstylevalue[(*i)->style];
      if ( v16 != 264 )
      {
        v17 = (float)v16 * 0.0037878789;
        *(p_y - 1) = *(p_y - 1) * v17;
        *p_y = *p_y * v17;
        p_y[1] = v17 * p_y[1];
      }
      result = nLightCount + 1;
      p_y += 22;
      nLightCount = result;
      if ( result >= nMaxLocalLights )
        break;
    }
    if ( ++bAllowFast >= p_state->numlights )
      return nLightCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DD230
// Name: private: void CModelRender::ComputeAmbientBoost(int,struct LightingQuery_t const __near *,struct MaterialLightingState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ComputeAmbientBoost(
        CModelRender *this,
        int nCount,
        const LightingQuery_t *pQuery,
        MaterialLightingState_t *pState)
{
  double v4; // st5
  double v5; // st4
  bool *p_m_bAmbientBoost; // edi
  float *p_z; // ecx
  int i; // ebx
  int v9; // esi
  double v10; // st3
  double v11; // st2
  double v12; // st5
  double v13; // rt1
  double v14; // st3
  double v15; // st4
  float v16; // xmm1_4
  double v17; // st3
  double v18; // st2
  double v19; // st5
  double v20; // rtt
  double v21; // st3
  double v22; // st4
  float v23; // xmm0_4
  double v24; // st3
  double v25; // st2
  double v26; // st5
  double v27; // rt1
  double v28; // st3
  double v29; // st4
  float v30; // xmm1_4
  double v31; // st3
  double v32; // st2
  double v33; // st5
  double v34; // rtt
  double v35; // st3
  double v36; // st4
  float v37; // xmm0_4
  double v38; // st3
  double v39; // st2
  double v40; // st5
  double v41; // rt1
  double v42; // st3
  double v43; // st4
  float v44; // xmm1_4
  double v45; // st3
  double v46; // st2
  double v47; // rtt
  double v48; // st3
  float v49; // xmm4_4
  float *v50; // edx
  float v51; // xmm3_4
  long double v52; // st2
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  float m_fValue; // xmm0_4
  float maxCubeLuminance; // [esp+4h] [ebp-8h]
  float avgCubeLuminance; // [esp+8h] [ebp-4h]
  float denom; // [esp+14h] [ebp+8h]
  float denoma; // [esp+14h] [ebp+8h]
  float denomb; // [esp+14h] [ebp+8h]
  float denomc; // [esp+14h] [ebp+8h]
  float denomd; // [esp+14h] [ebp+8h]
  float denome; // [esp+14h] [ebp+8h]
  float denomf; // [esp+14h] [ebp+8h]
  float d2; // [esp+18h] [ebp+Ch]

  if ( r_ambientboost.m_pParent != nullptr && r_ambientboost.m_pParent->m_Value.m_nValue != 0 )
  {
    avgCubeLuminance = 0.0;
    if ( nCount > 0 )
    {
      v4 = 3.4028235e38;
      v5 = 0.0;
      p_m_bAmbientBoost = &pQuery->m_bAmbientBoost;
      p_z = &pState->m_vecAmbientCube[1].z;
      for ( i = nCount; i != 0; --i )
      {
        if ( *p_m_bAmbientBoost )
        {
          v9 = *((_DWORD *)p_z + 16);
          if ( v9 != 0 )
          {
            v10 = *(p_z - 4) * 0.58999997 + *(p_z - 5) * 0.30000001 + *(p_z - 3) * 0.11;
            denom = v10;
            v11 = v4;
            v12 = v10;
            if ( v11 <= v10 )
              v12 = v11;
            v13 = v10;
            v14 = v5;
            v15 = v13;
            if ( v14 >= v13 )
              v15 = v14;
            v16 = denom + avgCubeLuminance;
            v17 = *(p_z - 2) * 0.30000001 + *(p_z - 1) * 0.58999997 + *p_z * 0.11;
            denoma = v17;
            v18 = v12;
            v19 = v17;
            if ( v18 <= v17 )
              v19 = v18;
            v20 = v17;
            v21 = v15;
            v22 = v20;
            if ( v21 >= v20 )
              v22 = v21;
            v23 = denoma + v16;
            v24 = p_z[2] * 0.58999997 + p_z[1] * 0.30000001 + p_z[3] * 0.11;
            denomb = v24;
            v25 = v19;
            v26 = v24;
            if ( v25 <= v24 )
              v26 = v25;
            v27 = v24;
            v28 = v22;
            v29 = v27;
            if ( v28 >= v27 )
              v29 = v28;
            v30 = denomb + v23;
            v31 = p_z[5] * 0.58999997 + p_z[4] * 0.30000001 + p_z[6] * 0.11;
            denomc = v31;
            v32 = v26;
            v33 = v31;
            if ( v32 <= v31 )
              v33 = v32;
            v34 = v31;
            v35 = v29;
            v36 = v34;
            if ( v35 >= v34 )
              v36 = v35;
            v37 = denomc + v30;
            v38 = p_z[8] * 0.58999997 + p_z[7] * 0.30000001 + p_z[9] * 0.11;
            denomd = v38;
            v39 = v33;
            v40 = v38;
            if ( v39 <= v38 )
              v40 = v39;
            v41 = v38;
            v42 = v36;
            v43 = v41;
            if ( v42 >= v41 )
              v43 = v42;
            v44 = denomd + v37;
            v45 = p_z[11] * 0.58999997 + p_z[10] * 0.30000001 + p_z[12] * 0.11;
            denome = v45;
            v46 = v40;
            v4 = v45;
            if ( v46 <= v45 )
              v4 = v46;
            v47 = v45;
            v48 = v43;
            v5 = v47;
            if ( v48 >= v47 )
              v5 = v48;
            avgCubeLuminance = (float)(denome + v44) * 0.16666667;
            v49 = 0.0;
            if ( v9 > 0 )
            {
              v50 = p_z + 23;
              do
              {
                d2 = (float)((float)((float)(*(v50 - 1) - p_z[14]) * (float)(*(v50 - 1) - p_z[14]))
                           + (float)((float)(*(v50 - 2) - p_z[13]) * (float)(*(v50 - 2) - p_z[13])))
                   + (float)((float)(*v50 - p_z[15]) * (float)(*v50 - p_z[15]));
                v51 = 1.0;
                v52 = d2 * v50[8] + sqrt(d2) * v50[7] + v50[6];
                if ( v52 > 0.0000099999997 )
                {
                  denomf = v52;
                  v51 = 1.0 / denomf;
                }
                v53 = *(v50 - 4);
                v54 = (float)(*(v50 - 5) * v51) * 0.30000001;
                v55 = (float)(*(v50 - 3) * v51) * 0.11;
                v50 += 22;
                --v9;
                v49 = (float)((float)((float)((float)(v53 * v51) * 0.58999997) + v54) + v55) + v49;
              }
              while ( v9 != 0 );
            }
            v56 = r_ambientfraction.m_pParent->m_Value.m_fValue * v49;
            if ( r_ambientmin.m_pParent->m_Value.m_fValue > avgCubeLuminance && v56 > avgCubeLuminance )
            {
              maxCubeLuminance = v5;
              m_fValue = v56 / maxCubeLuminance;
              if ( r_ambientfactor.m_pParent->m_Value.m_fValue <= m_fValue )
                m_fValue = r_ambientfactor.m_pParent->m_Value.m_fValue;
              *(p_z - 5) = *(p_z - 5) * m_fValue;
              *(p_z - 4) = *(p_z - 4) * m_fValue;
              *(p_z - 3) = *(p_z - 3) * m_fValue;
              *(p_z - 2) = m_fValue * *(p_z - 2);
              *(p_z - 1) = *(p_z - 1) * m_fValue;
              *p_z = *p_z * m_fValue;
              p_z[1] = m_fValue * p_z[1];
              p_z[2] = p_z[2] * m_fValue;
              p_z[3] = p_z[3] * m_fValue;
              p_z[4] = m_fValue * p_z[4];
              p_z[5] = p_z[5] * m_fValue;
              p_z[6] = p_z[6] * m_fValue;
              p_z[7] = m_fValue * p_z[7];
              p_z[8] = p_z[8] * m_fValue;
              p_z[9] = p_z[9] * m_fValue;
              p_z[10] = m_fValue * p_z[10];
              p_z[11] = p_z[11] * m_fValue;
              p_z[12] = p_z[12] * m_fValue;
            }
          }
        }
        p_z += 110;
        p_m_bAmbientBoost += 16;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD650
// Name: public: virtual void CModelRender::ComputeLightingState(int,struct LightingQuery_t const __near *,struct MaterialLightingState_t __near *,class ITexture __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ComputeLightingState(
        CModelRender *this,
        int nCount,
        const LightingQuery_t *pQuery,
        MaterialLightingState_t *pState,
        ITexture **ppEnvCubemapTexture)
{
  int v5; // ebx
  float *p_y; // edi
  float *p_z; // esi
  float *v8; // ebx
  int LightingConditions; // eax
  bool v10; // zf
  float *v11; // eax
  int v13; // [esp+Ch] [ebp-4h]

  v5 = nCount;
  if ( nCount > 0 )
  {
    p_y = &pQuery->m_LightingOrigin.y;
    p_z = &pState->m_vecLightingOrigin.z;
    v13 = nCount;
    do
    {
      v8 = p_y - 1;
      LightingConditions = CModelRender::GetLightingConditions(
                             this,
                             vecLightingOrigin: (const Vector *)(p_y - 1),
                             pColors: (Vector *)(p_z - 20),
                             nMaxLocalLights: 4,
                             pLocalLights: (LightDesc_t *)(p_z + 2),
                             pEnvCubemapTexture: ppEnvCubemapTexture++,
                             handle: *((_WORD *)p_y + 4),
                             bAllowFast: true);
      *((_DWORD *)p_z + 1) = LightingConditions;
      p_y += 4;
      *(p_z - 2) = *v8;
      p_z += 110;
      v10 = v13-- == 1;
      *(p_z - 111) = *(p_y - 4);
      *(p_z - 110) = *(p_y - 3);
    }
    while ( !v10 );
    v5 = nCount;
  }
  CModelRender::ComputeAmbientBoost(this, nCount: v5, pQuery, pState);
  if ( mat_fullbright.m_pParent != nullptr && mat_fullbright.m_pParent->m_Value.m_nValue == 1 && v5 > 0 )
  {
    v11 = &pState->m_vecAmbientCube[1].z;
    do
    {
      v11[16] = 0.0;
      *(v11 - 5) = 1.0;
      *(v11 - 4) = 1.0;
      *(v11 - 3) = 1.0;
      *(v11 - 2) = 1.0;
      *(v11 - 1) = 1.0;
      *v11 = 1.0;
      v11[1] = 1.0;
      v11[2] = 1.0;
      v11[3] = 1.0;
      v11[4] = 1.0;
      v11[5] = 1.0;
      v11[6] = 1.0;
      v11[7] = 1.0;
      v11[8] = 1.0;
      v11[9] = 1.0;
      v11[10] = 1.0;
      v11[11] = 1.0;
      v11[12] = 1.0;
      v11 += 110;
      --v5;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD770
// Name: public: virtual void CModelRender::GetModelDecalHandles(struct StudioDecalHandle_t__ __near * __near *,int,int,unsigned short const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::GetModelDecalHandles(
        CModelRender *this,
        StudioDecalHandle_t__ **pDecals,
        int nDecalStride,
        int nCount,
        const unsigned __int16 *pHandles)
{
  int i; // eax
  int v7; // edx
  StudioDecalHandle_t__ *m_DecalHandle; // edx

  for ( i = 0; i < nCount; pDecals = (StudioDecalHandle_t__ **)((char *)pDecals + nDecalStride) )
  {
    v7 = pHandles[i];
    if ( (_WORD)v7 == 0xFFFF )
      m_DecalHandle = nullptr;
    else
      m_DecalHandle = this->m_ModelInstances.m_Memory.m_pMemory[v7].m_Element.m_DecalHandle;
    *pDecals = m_DecalHandle;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD7D0
// Name: public: virtual bool CModelRender::DrawModelSetup(class IMatRenderContext __near *,struct ModelRenderInfo_t __near &,struct DrawModelState_t __near *,struct matrix3x4_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CModelRender::DrawModelSetup(
        CModelRender *this,
        IMatRenderContext *pRenderContext,
        ModelRenderInfo_t *pInfo,
        CModelRender *pState,
        matrix3x4a_t **ppBoneToWorldOut)
{
  int studio; // eax
  studiohdr_t *v7; // eax
  int m_nValue; // ecx
  const matrix3x4_t *pModelToWorld; // eax
  studiohwdata_t *v10; // eax
  int v11; // eax
  IClientRenderable *pRenderable; // edi
  IClientRenderable_vtbl *v13; // esi
  CClientState *v14; // eax
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  IClientRenderable_vtbl *v17; // eax
  CClientState *BaseLocalClient; // eax
  int instance; // eax
  int flags; // eax
  float v21; // [esp+0h] [ebp-28h]
  float Time; // [esp+0h] [ebp-28h]
  CMatRenderData<matrix3x4a_t> v23; // [esp+10h] [ebp-18h] BYREF
  IClientRenderable_vtbl *v24; // [esp+20h] [ebp-8h]
  CModelRender *rdBoneToWorld; // [esp+24h] [ebp-4h] OVERLAPPED
  IClientRenderable *rdBoneToWorld_12; // [esp+30h] [ebp+8h]
  ModelRenderInfo_t *info; // [esp+34h] [ebp+Ch]

  *ppBoneToWorldOut = nullptr;
  studio = pInfo->pModel->studio;
  rdBoneToWorld = this;
  v7 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: studio);
  pState->IVModelRender::__vftable = (CModelRender_vtbl *)v7;
  pState->m_pCache = (IDataCacheSection *)pInfo->pRenderable;
  if ( r_entity.m_pParent != nullptr )
  {
    m_nValue = r_entity.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
      goto LABEL_3;
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue != pInfo->entity_index )
    return 0;
LABEL_3:
  if ( v7->numbodyparts == 0 )
    return 0;
  pModelToWorld = pInfo->pModelToWorld;
  if ( pModelToWorld == nullptr )
    return 0;
  pState->m_ModelInstances.m_Memory.m_pMemory = (UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *)pModelToWorld;
  v10 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: pInfo->pModel->studio);
  pState->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)v10;
  if ( v10 == nullptr )
    return 0;
  v11 = CModelRender::ComputeLOD(this: rdBoneToWorld, pRenderContext, info: pInfo, pStudioHWData: v10);
  *(_DWORD *)&pState->m_ModelInstances.m_Head = v11;
  info = (ModelRenderInfo_t *)(1024 << v11);
  if ( (pInfo->flags & 1) != 0 )
  {
    LockRenderData = pRenderContext->LockRenderData;
    v23.m_nCount = (int)pState->IVModelRender::__vftable[1].RemoveAllDecals;
    v23.m_pRenderContext = pRenderContext;
    v23.m_pRenderData = (matrix3x4a_t *)LockRenderData(this: pRenderContext, a2: 48 * v23.m_nCount);
    rdBoneToWorld_12 = pInfo->pRenderable;
    v17 = rdBoneToWorld_12->__vftable;
    v23.m_bNeedsUnlock = true;
    v24 = v17;
    BaseLocalClient = GetBaseLocalClient();
    Time = CClientState::GetTime(this: BaseLocalClient);
    if ( ((unsigned __int8 (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, ModelRenderInfo_t *, _DWORD))v24->SetupBones)(
           a1: rdBoneToWorld_12,
           a2: v23.m_pRenderData,
           a3: v23.m_nCount,
           a4: info,
           a5: LODWORD(Time)) != 0 )
    {
      *ppBoneToWorldOut = v23.m_pRenderData;
      pState->m_ModelInstances.m_Memory.m_nAllocationCount = 0;
      instance = pInfo->instance;
      if ( (_WORD)instance != 0xFFFF )
        pState->m_ModelInstances.m_Memory.m_nAllocationCount = (int)rdBoneToWorld->m_ModelInstances.m_Memory.m_pMemory[instance].m_Element.m_DecalHandle;
      pState->m_ModelInstances.m_Memory.m_nGrowSize = 0;
      flags = pInfo->flags;
      if ( (flags & 8) != 0 )
        pState->m_ModelInstances.m_Memory.m_nGrowSize = (flags < 0) + 1;
      if ( (pInfo->flags & 0x10) != 0 )
        pState->m_ModelInstances.m_Memory.m_nGrowSize |= 8u;
      if ( (pInfo->flags & 0x40) != 0 )
        pState->m_ModelInstances.m_Memory.m_nGrowSize |= 0x100u;
      if ( (pInfo->flags & 0x20) != 0 )
        pState->m_ModelInstances.m_Memory.m_nGrowSize |= 0x80u;
      if ( SLOBYTE(pInfo->flags) < 0 )
        pState->m_ModelInstances.m_Memory.m_nGrowSize |= 0x20u;
      if ( r_drawmodelstatsoverlay.m_pParent != nullptr && r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue == 2 )
        pState->m_ModelInstances.m_Memory.m_nGrowSize |= 0x10u;
      if ( (pInfo->flags & 0x40000000) != 0 )
        pState->m_ModelInstances.m_Memory.m_nGrowSize |= 0x200u;
      CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &v23);
      return 1;
    }
    else
    {
      CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &v23);
      return 0;
    }
  }
  else
  {
    pRenderable = pInfo->pRenderable;
    v13 = pRenderable->__vftable;
    v14 = GetBaseLocalClient();
    v21 = CClientState::GetTime(this: v14);
    return ((int (__thiscall *)(IClientRenderable *, _DWORD, int, ModelRenderInfo_t *, _DWORD))v13->SetupBones)(
             a1: pRenderable,
             a2: 0,
             a3: 256,
             a4: info,
             a5: LODWORD(v21));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD9F0
// Name: private: void CModelRender::ComputeModelVertexLightingOld(struct mstudiomodel_t __near *,struct matrix3x4_t __near &,struct LightingState_t const __near &,struct color24 __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ComputeModelVertexLightingOld(
        CModelRender *this,
        mstudiomodel_t *pModel,
        matrix3x4_t *matrix,
        mstudiomodel_t *lightingState,
        matrix3x4_t *pLighting,
        bool bUseConstDirLighting,
        float flConstDirLightAmount)
{
  int v7; // ebx
  vgui::Splitter *VertexData; // ecx
  unsigned int v9; // edi
  vertexFileHeader_t *v10; // eax
  thinModelVertices_t *v11; // eax
  matrix3x4_t *v12; // eax
  const matrix3x4_t *v13; // edi
  unsigned __int8 *v14; // esi
  int v15; // eax
  Vector *v16; // ecx
  const thinModelVertices_t *v17; // eax
  int v18; // eax
  int v19; // eax
  float x; // xmm0_4
  float z; // xmm3_4
  LightDesc_t pLightDescs; // [esp+10h] [ebp-1D0h] BYREF
  Vector pNormal; // [esp+170h] [ebp-70h] BYREF
  __int64 in1; // [esp+17Ch] [ebp-64h] BYREF
  Vector position; // [esp+184h] [ebp-5Ch]
  float v26; // [esp+190h] [ebp-50h]
  vgui::Splitter *v27; // [esp+194h] [ebp-4Ch]
  float v28; // [esp+198h] [ebp-48h]
  const mstudio_modelvertexdata_t *vertData; // [esp+19Ch] [ebp-44h]
  float v30; // [esp+1A0h] [ebp-40h]
  thinModelVertices_t *v31; // [esp+1A4h] [ebp-3Ch]
  int v32; // [esp+1A8h] [ebp-38h]
  const thinModelVertices_t *thinVertData; // [esp+1ACh] [ebp-34h]
  int pNumLightDescs; // [esp+1B0h] [ebp-30h] BYREF
  int v35; // [esp+1B4h] [ebp-2Ch]
  float nNumLightDesc[2]; // [esp+1B8h] [ebp-28h] BYREF
  Vector worldPos; // [esp+1C0h] [ebp-20h] BYREF
  Vector worldNormal; // [esp+1CCh] [ebp-14h] BYREF
  Vector destColor; // [esp+1D8h] [ebp-8h]
  matrix3x4_t *matrixa; // [esp+1F4h] [ebp+14h]

  v7 = 0;
  R_SetNonAmbientLightingState(
    numLights: lightingState->nummeshes,
    locallight: (dworldlight_t **)&lightingState->meshindex,
    &pNumLightDescs,
    &pLightDescs,
    bUpdateStudioRenderLights: false);
  v31 = nullptr;
  VertexData = (vgui::Splitter *)mstudiomodel_t::GetVertexData(this: pModel, pModelData: nullptr);
  v9 = 0;
  v27 = VertexData;
  if ( VertexData != nullptr )
  {
    v9 = (unsigned int)VertexData->__vftable + 48 * ((unsigned int)VertexData[-1].m_Splitters.m_Memory.m_pMemory / 0x30);
  }
  else
  {
    v10 = g_pMDLCache->GetVertexData(this: g_pMDLCache, a2: LOWORD(s_ModelRender.m_pStudioHdr->virtualModel));
    if ( v10 == nullptr )
      return;
    if ( v10->id == 1447248969 && (VertexData = (vgui::Splitter *)v10->vertexDataStart) != nullptr )
      v11 = (thinModelVertices_t *)((char *)v10 + (_DWORD)VertexData);
    else
      v11 = nullptr;
    v31 = v11;
    if ( v11 == nullptr )
      return;
  }
  HIBYTE(destColor.y) = CBaseServer::ShouldUpdateMasterServer(this: VertexData);
  if ( pModel->numvertices > 0 )
  {
    v12 = (matrix3x4_t *)(v9 + 16);
    v13 = matrix;
    v14 = (unsigned __int8 *)&pLighting->m_flMatVal[0][0] + 2;
    for ( matrixa = v12; ; v12 = matrixa )
    {
      if ( v27 != nullptr )
      {
        if ( HIBYTE(destColor.y) != 0 )
          _mm_prefetch((const char *)v12->m_flMatVal[2], 1);
        VectorTransform(in1: (const float *)v12, in2: v13, out: nNumLightDesc);
        VectorRotate(in1: &matrixa->m_flMatVal[0][3], in2: v13, out: &worldPos.y);
      }
      else
      {
        v15 = pModel->vertexindex / 0x30u + v7;
        v16 = &v31->m_vecPositions[v15];
        in1 = *(_QWORD *)&v16->x;
        position.x = v16->z;
        thinModelVertices_t::GetNormal(this: v31, vertIndex: v15, &pNormal);
        v13 = matrix;
        VectorTransform((const float *)&in1, in2: matrix, out: nNumLightDesc);
        VectorRotate(in1: &pNormal.x, in2: matrix, out: &worldPos.y);
      }
      if ( bUseConstDirLighting )
        ((void (__stdcall *)(mstudiomodel_t *, int, LightDesc_t *, float *, float *, float *, _DWORD))g_pStudioRender->ComputeLightingConstDirectional)(
          a1: lightingState,
          a2: pNumLightDescs,
          a3: &pLightDescs,
          a4: nNumLightDesc,
          a5: &worldPos.y,
          a6: &worldNormal.y,
          a7: LODWORD(flConstDirLightAmount));
      else
        g_pStudioRender->ComputeLighting(
          this: g_pStudioRender,
          a2: (const Vector *)lightingState,
          a3: pNumLightDescs,
          a4: &pLightDescs,
          a5: (const Vector *)nNumLightDesc,
          a6: (Vector *)&worldPos.y,
          a7: (Vector *)&worldNormal.y);
      position.y = worldNormal.y * 1024.0;
      thinVertData = (const thinModelVertices_t *)(int)(float)(worldNormal.y * 1024.0);
      v17 = thinVertData;
      if ( (unsigned int)thinVertData > 0xFFF )
        v17 = (int)thinVertData < 0 ? nullptr : (const thinModelVertices_t *)0xFFF;
      worldNormal.y = lineartovertex[(_DWORD)v17];
      *(float *)&vertData = worldNormal.z * 1024.0;
      v35 = (int)(float)(worldNormal.z * 1024.0);
      v18 = v35;
      if ( (unsigned int)v35 > 0xFFF )
        v18 = v35 < 0 ? 0 : 0xFFF;
      worldNormal.z = lineartovertex[v18];
      v30 = destColor.x * 1024.0;
      v32 = (int)(float)(destColor.x * 1024.0);
      v19 = v32;
      if ( (unsigned int)v32 > 0xFFF )
        v19 = v32 < 0 ? 0 : 0xFFF;
      ++matrixa;
      destColor.x = lineartovertex[v19];
      x = destColor.x;
      v28 = (float)(worldNormal.y * 255.0) + 8388608.0;
      z = worldNormal.z;
      *(v14 - 2) = LOBYTE(v28);
      position.z = (float)(z * 255.0) + 8388608.0;
      *(v14 - 1) = LOBYTE(position.z);
      v26 = (float)(x * 255.0) + 8388608.0;
      *v14 = LOBYTE(v26);
      ++v7;
      v14 += 3;
      if ( v7 >= pModel->numvertices )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDCD0
// Name: public: virtual void CModelRender::SetStaticLighting(unsigned short,struct LightCacheHandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetStaticLighting(
        CModelRender *this,
        unsigned __int16 handle,
        LightCacheHandle_t__ **pCache)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v3; // eax
  LightCacheHandle_t__ *v4; // ecx

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
    if ( pCache != nullptr )
    {
      v4 = *pCache;
      v3->m_Element.m_nFlags |= 1u;
      v3->m_Element.m_LightCacheHandle = v4;
    }
    else
    {
      v3->m_Element.m_nFlags &= ~1u;
      v3->m_Element.m_LightCacheHandle = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDD20
// Name: public: virtual struct LightCacheHandle_t__ __near * CModelRender::GetStaticLighting(unsigned short)
// Source: json
//------------------------------------------------------------------------------
LightCacheHandle_t__ *__thiscall CModelRender::GetStaticLighting(CModelRender *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v2; // eax

  if ( handle == 0xFFFF )
    return nullptr;
  v2 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  if ( (v2->m_Element.m_nFlags & 1) == 0 )
    return nullptr;
  else
    return v2->m_Element.m_LightCacheHandle;
}

//------------------------------------------------------------------------------
// Address: 0x100DDD50
// Name: public: virtual bool CModelRender::ChangeInstance(unsigned short,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelRender::ChangeInstance(CModelRender *this, int handle, IClientRenderable *pRenderable)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v3; // esi

  if ( (_WORD)handle == 0xFFFF || pRenderable == nullptr )
    return 0;
  v3 = &this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)handle];
  if ( v3->m_Element.m_pModel == pRenderable->GetModel(this: pRenderable) )
  {
    g_pShadowMgr->RemoveAllShadowsFromModel(this: g_pShadowMgr, a2: handle);
    v3->m_Element.m_pRenderable = pRenderable;
    return 1;
  }
  else
  {
    DevMsg(a1: "MoveInstanceHandle: models are different!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDDC0
// Name: private: bool CModelRender::IsModelInstanceValid(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelRender::IsModelInstanceValid(CModelRender *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v3; // esi

  if ( handle == 0xFFFF )
    return false;
  v3 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  return v3->m_Element.m_DecalHandle != nullptr
      && v3->m_Element.m_pModel == v3->m_Element.m_pRenderable->GetModel(this: v3->m_Element.m_pRenderable);
}

//------------------------------------------------------------------------------
// Address: 0x100DDE10
// Name: public: virtual void CModelRender::RemoveAllDecals(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::RemoveAllDecals(CModelRender *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v2; // esi

  if ( handle != 0xFFFF )
  {
    v2 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
    if ( v2->m_Element.m_DecalHandle != nullptr
      && v2->m_Element.m_pModel == v2->m_Element.m_pRenderable->GetModel(this: v2->m_Element.m_pRenderable) )
    {
      g_pStudioRender->DestroyDecalList(this: g_pStudioRender, a2: v2->m_Element.m_DecalHandle);
      v2->m_Element.m_DecalHandle = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDE70
// Name: void SetRootLOD_f(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetRootLOD_f(IConVar *pConVar, const char *pOldString)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  if ( !CheckVarRange_Generic(pVar: &r_rootlod, minVal: 0, maxVal: 2) )
  {
    ConVarRef::ConVarRef(this: &var, pConVar);
    UpdateStudioRenderConfig();
    if ( !g_LostVideoMemory && _V_strcmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: pOldString) != 0 )
      modelloader->Studio_ReloadModels(this: modelloader, a2: RELOAD_LOD_CHANGED);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDED0
// Name: void FlushLOD_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FlushLOD_f()
{
  UpdateStudioRenderConfig();
  if ( !g_LostVideoMemory )
    modelloader->Studio_ReloadModels(this: modelloader, a2: RELOAD_EVERYTHING);
}

//------------------------------------------------------------------------------
// Address: 0x100DE310
// Name: public: void CColorMeshData::DestroyResource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorMeshData::DestroyResource(CColorMeshData *this)
{
  IMatRenderContext *m_pObject; // ebx
  int v3; // edi
  ColorMeshInfo_t *m_pMeshInfos; // eax
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
  g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: this->m_hAsyncControl);
  m_pObject = materials->GetRenderContext(this: materials);
  v3 = 0;
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  for ( i = 0; i < this->m_nMeshes; ++i )
  {
    m_pMeshInfos = this->m_pMeshInfos;
    if ( m_pMeshInfos[v3].m_pPooledVBAllocator != nullptr )
    {
      m_pMeshInfos[v3].m_pPooledVBAllocator->Deallocate(
        this: m_pMeshInfos[v3].m_pPooledVBAllocator,
        a2: m_pMeshInfos[v3].m_nVertOffsetInBytes,
        a3: m_pMeshInfos[v3].m_nNumVerts);
      m_pObject = pRenderContext.m_pObject;
    }
    else
    {
      m_pObject->DestroyStaticMesh(this: m_pObject, a2: m_pMeshInfos[v3].m_pMesh);
    }
    ++v3;
  }
  free(pMem: this->m_pMeshInfos);
  free(pMem: this->m_ppTargets);
  free(pMem: this);
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE3F0
// Name: public: static class CColorMeshData __near * CColorMeshData::CreateResource(struct colormeshparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CColorMeshData *__cdecl CColorMeshData::CreateResource(const colormeshparams_t *params)
{
  CColorMeshData *v1; // esi
  ColorMeshInfo_t *v3; // eax
  IMatRenderContext *m_pObject; // ebx
  int v5; // eax
  int v6; // ebx
  ColorMeshInfo_t *m_pMeshInfos; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *v10; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1FCh] BYREF
  unsigned __int64 vertexFormat; // [esp+1F4h] [ebp-14h]
  MaterialLock_t__ *hLock; // [esp+1FCh] [ebp-Ch]
  CMatRenderContextPtr pRenderContext; // [esp+200h] [ebp-8h]
  int numLightingComponents; // [esp+204h] [ebp-4h]
  int i; // [esp+210h] [ebp+8h]

  v1 = (CColorMeshData *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( r_staticlight_streams.m_pParent != nullptr )
    numLightingComponents = r_staticlight_streams.m_pParent->m_Value.m_nValue;
  else
    numLightingComponents = 0;
  *((_DWORD *)v1 + 5) &= 0xFFFFFFFC;
  v1->m_hAsyncControl = nullptr;
  v1->m_fnHandle = params->m_fnHandle;
  v1->m_nTotalSize = 4 * (params->m_nMeshes + numLightingComponents * params->m_nTotalVertexes);
  v1->m_nMeshes = params->m_nMeshes;
  v3 = (ColorMeshInfo_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)params->m_nMeshes >> 28 != 0 ? -1 : 16 * params->m_nMeshes);
  v1->m_pMeshInfos = v3;
  _V_memset(dest: v3, fill: 0, count: 16 * params->m_nMeshes);
  v1->m_ppTargets = (unsigned __int8 **)MemAlloc_Alloc(
                                          nSize: (unsigned __int64)(unsigned int)params->m_nMeshes >> 30 != 0
                                        ? -1
                                        : 4 * params->m_nMeshes);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  hLock = materials->Lock(this: materials);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v5 = 0;
  i = 0;
  if ( params->m_nMeshes <= 0 )
  {
LABEL_34:
    materials->Unlock(this: materials, a2: hLock);
    if ( m_pObject != nullptr )
    {
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
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
    return v1;
  }
  else
  {
    v6 = 0;
    while ( 1 )
    {
      LODWORD(vertexFormat) = 8;
      if ( numLightingComponents > 1 )
        LODWORD(vertexFormat) = 2;
      v1->m_pMeshInfos[v6].m_pMesh = nullptr;
      v1->m_pMeshInfos[v6].m_pPooledVBAllocator = params->m_pPooledVBAllocator;
      v1->m_pMeshInfos[v6].m_nVertOffsetInBytes = 0;
      v1->m_pMeshInfos[v6].m_nNumVerts = params->m_nVertexes[v5];
      if ( params->m_pPooledVBAllocator != nullptr )
      {
        v1->m_pMeshInfos[v6].m_nVertOffsetInBytes = params->m_pPooledVBAllocator->Allocate(
                                                      this: params->m_pPooledVBAllocator,
                                                      a2: params->m_nVertexes[v5]);
        m_pMeshInfos = v1->m_pMeshInfos;
        if ( m_pMeshInfos[v6].m_nVertOffsetInBytes == -1 )
        {
          m_pMeshInfos[v6].m_pPooledVBAllocator = nullptr;
          v1->m_pMeshInfos[v6].m_nVertOffsetInBytes = 0;
        }
        else
        {
          v1->m_pMeshInfos[v6].m_pMesh = params->m_pPooledVBAllocator->GetSharedMesh(this: params->m_pPooledVBAllocator);
          v1->m_ppTargets[i] = (unsigned __int8 *)params->m_pPooledVBAllocator->GetVertexBufferBase(this: params->m_pPooledVBAllocator)
                             + v1->m_pMeshInfos[v6].m_nVertOffsetInBytes;
        }
      }
      if ( v1->m_pMeshInfos[v6].m_pMesh == nullptr )
      {
        if ( g_VBAllocTracker != nullptr )
          g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: "CColorMeshData::CreateResource");
        v1->m_pMeshInfos[v6].m_pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, const char *, _DWORD, _DWORD))pRenderContext.m_pObject->CreateStaticMesh)(
                                                  a1: pRenderContext.m_pObject,
                                                  a2: vertexFormat,
                                                  a3: 0,
                                                  a4: "Lighting Verts",
                                                  a5: 0,
                                                  a6: 0);
        CMeshBuilder::Begin(
          this: &meshBuilder,
          pMesh: v1->m_pMeshInfos[v6].m_pMesh,
          type: MATERIAL_HETEROGENOUS,
          nVertexCount: params->m_nVertexes[i],
          nIndexCount: 0,
          pMeshSettings: nullptr);
        if ( numLightingComponents <= 1 )
          v1->m_ppTargets[i] = &meshBuilder.m_VertexBuilder.m_pSpecular[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                                      * meshBuilder.m_VertexBuilder.m_VertexSize_Specular];
        else
          v1->m_ppTargets[i] = (unsigned __int8 *)meshBuilder.m_VertexBuilder.m_pCurrNormal;
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
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        if ( g_VBAllocTracker != nullptr )
          g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
      }
      if ( v1->m_pMeshInfos[v6].m_pMesh == nullptr )
        break;
      v5 = i + 1;
      ++v6;
      i = v5;
      if ( v5 >= params->m_nMeshes )
      {
        m_pObject = pRenderContext.m_pObject;
        goto LABEL_34;
      }
    }
    CColorMeshData::DestroyResource(this: v1);
    materials->Unlock(this: materials, a2: hLock);
    v10 = pRenderContext.m_pObject;
    if ( pRenderContext.m_pObject != nullptr )
    {
      pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
      v10->Release(this: v10);
    }
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
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE7F0
// Name: private: void CModelRender::StudioSetupLighting(struct DrawModelState_t const __near &,class Vector const __near &,struct LightCacheHandle_t__ __near * __near *,bool,bool,bool __near &,struct DrawModelInfo_t __near &,struct ModelRenderInfo_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::StudioSetupLighting(
        CModelRender *this,
        const DrawModelState_t *state,
        const Vector *absEntCenter,
        LightCacheHandle_t__ **pLightcache,
        bool bVertexLit,
        bool bNeedsEnvCubemap,
        bool *bStaticLighting,
        CModelRender::ModelInstance_t *drawInfo,
        LightCacheHandle_t__ **pInfo,
        __int16 drawFlags)
{
  bool v10; // zf
  float z; // edx
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // eax
  float v14; // eax
  float v15; // edi
  Vector *v16; // eax
  const matrix3x4_t *v17; // ecx
  int v18; // eax
  _DWORD *v19; // edi
  const LightingState_t *v20; // eax
  const LightingState_t *Static; // eax
  float *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *v25; // eax
  float v26; // xmm1_4
  float v27; // xmm2_4
  float *v28; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  float *v31; // eax
  float v32; // xmm1_4
  float v33; // xmm2_4
  float *v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  float *v37; // eax
  float v38; // xmm1_4
  float v39; // xmm2_4
  ITexture *Dynamic; // eax
  int v41; // eax
  char *v42; // ecx
  char *m_pszString; // eax
  int v44; // ebx
  float *p_in1; // edi
  float *v46; // eax
  const matrix3x4_t *v47; // edx
  int v48; // ebx
  float *v49; // edi
  float *v50; // eax
  const matrix3x4_t *v51; // edx
  dworldlight_t **v52; // edi
  float y; // ebx
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm2_4
  float v57; // xmm2_4
  float v58; // xmm2_4
  float v59; // xmm2_4
  float v60; // xmm2_4
  float v61; // xmm2_4
  float v62; // xmm2_4
  float v63; // xmm2_4
  float v64; // xmm2_4
  float v65; // xmm2_4
  float v66; // xmm2_4
  float v67; // xmm2_4
  float v68; // xmm2_4
  float v69; // xmm2_4
  float v70; // xmm2_4
  float v71; // xmm2_4
  int v72; // ecx
  float v73; // xmm4_4
  float v74; // xmm5_4
  float v75; // xmm6_4
  float v76; // xmm0_4
  double v77; // st7
  double v78; // st6
  double v79; // st3
  double v80; // st7
  float v81; // xmm2_4
  double v82; // st2
  double v83; // rt0
  double v84; // st2
  double v85; // st7
  float v86; // xmm1_4
  double v87; // st3
  double v88; // rt1
  double v89; // st3
  double v90; // st7
  float v91; // xmm0_4
  double v92; // st3
  double v93; // rt2
  double v94; // st3
  double v95; // st7
  float v96; // xmm1_4
  double v97; // st6
  double v98; // rt0
  double v99; // st6
  double v100; // st7
  float v101; // xmm7_4
  float **v102; // edx
  int i; // ebx
  float *v104; // ecx
  float v105; // xmm3_4
  long double v106; // st6
  float v107; // xmm0_4
  float v108; // xmm2_4
  float v109; // xmm3_4
  float v110; // xmm1_4
  float v111; // xmm2_4
  float v112; // xmm3_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm3_4
  float v116; // xmm1_4
  float v117; // xmm2_4
  float v118; // xmm3_4
  float v119; // xmm1_4
  float v120; // xmm2_4
  float v121; // xmm3_4
  int v122; // eax
  float v123; // xmm1_4
  float v124; // xmm0_4
  int v125; // edx
  float *v126; // eax
  float *v127; // ecx
  double v128; // st7
  unsigned int v129; // [esp+0h] [ebp-174h]
  float v130; // [esp+0h] [ebp-174h]
  float in1; // [esp+10h] [ebp-164h] BYREF
  char v132; // [esp+18h] [ebp-15Ch] BYREF
  Vector pSaveLightPos[4]; // [esp+24h] [ebp-150h] BYREF
  Vector vFinalAmbientCube[6]; // [esp+54h] [ebp-120h] BYREF
  LightingState_t lightingDecalState; // [esp+9Ch] [ebp-D8h] BYREF
  float v136; // [esp+F8h] [ebp-7Ch]
  LightcacheGetDynamic_Stats stats; // [esp+FCh] [ebp-78h]
  LightingState_t lightingState; // [esp+100h] [ebp-74h] BYREF
  Vector vecDebugLightingOrigin; // [esp+15Ch] [ebp-18h] BYREF
  Vector vecLightingOrigin; // [esp+168h] [ebp-Ch] BYREF
  float vLightingOrigin; // [esp+17Ch] [ebp+8h]
  _DWORD *vLightingOrigin_4; // [esp+180h] [ebp+Ch]
  float m_fValue; // [esp+188h] [ebp+14h]
  float v144; // [esp+188h] [ebp+14h]
  float v145; // [esp+188h] [ebp+14h]
  float v146; // [esp+18Ch] [ebp+18h]
  float v147; // [esp+18Ch] [ebp+18h]
  float v148; // [esp+18Ch] [ebp+18h]
  float v149; // [esp+18Ch] [ebp+18h]
  float v150; // [esp+18Ch] [ebp+18h]
  float v151; // [esp+18Ch] [ebp+18h]
  float v152; // [esp+18Ch] [ebp+18h]
  float v153; // [esp+18Ch] [ebp+18h]
  float avgCubeLuminance; // [esp+190h] [ebp+1Ch]
  bool pModelInst_3; // [esp+197h] [ebp+23h]

  v10 = !this->m_bSuppressEngineLighting;
  lightingState.locallight[2] = (dworldlight_t *)this;
  if ( v10 )
  {
    z = vec3_origin.z;
    lightingState.numlights = LODWORD(vec3_origin.x);
    lightingState.locallight[0] = (dworldlight_t *)LODWORD(vec3_origin.y);
    LOBYTE(drawInfo[1].m_DecalHandle) = *bStaticLighting;
    *(_DWORD *)&drawInfo[4].m_FirstShadow = 0;
    vecDebugLightingOrigin.z = 0.0;
    memset(&lightingDecalState.locallight[1], 0, 12);
    v136 = 0.0;
    *(float *)&stats = 0.0;
    memset(&lightingState, 0, 56);
    *(float *)&lightingState.locallight[1] = z;
    vFinalAmbientCube[4].y = 0.0;
    vFinalAmbientCube[4].z = 0.0;
    memset(&vFinalAmbientCube[5], 0, sizeof(Vector));
    memset(&lightingDecalState, 0, 56);
    memset(&vecLightingOrigin, 0, sizeof(vecLightingOrigin));
    GetRenderContext = materials->GetRenderContext;
    lightingState.locallight[3] = nullptr;
    v14 = COERCE_FLOAT((int)GetRenderContext(this: materials));
    v15 = v14;
    vecDebugLightingOrigin.y = v14;
    if ( v14 != 0.0 )
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v14) + 8))(a1: COERCE_FLOAT(LODWORD(v14)));
    v16 = (Vector *)pInfo[10];
    if ( v16 != nullptr )
    {
      vecLightingOrigin = *v16;
    }
    else
    {
      v17 = (const matrix3x4_t *)pInfo[9];
      vecLightingOrigin = *absEntCenter;
      if ( v17 != nullptr )
        VectorTransform(in1: &absEntCenter->x, in2: v17, out: &vecLightingOrigin.x);
    }
    (*(void (__thiscall **)(float, _DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v15) + 592))(
      a1: COERCE_FLOAT(LODWORD(v15)),
      a2: LODWORD(vecLightingOrigin.x),
      a3: LODWORD(vecLightingOrigin.y),
      a4: LODWORD(vecLightingOrigin.z));
    v18 = *((unsigned __int16 *)pInfo + 32);
    v19 = nullptr;
    vLightingOrigin_4 = nullptr;
    pModelInst_3 = false;
    if ( (_WORD)v18 != 0xFFFF )
    {
      v19 = (_DWORD *)(LODWORD(lightingState.locallight[2]->intensity.x) + 32 * v18);
      vLightingOrigin_4 = v19;
      if ( v19 != nullptr )
        pModelInst_3 = v19[2] != 0;
    }
    if ( pLightcache != nullptr )
    {
      if ( !*bStaticLighting
        || (!StaticLightCacheAffectedByDynamicLight(handle: *pLightcache) ? (v129 = 6) : (v129 = 7),
            v20 = LightcacheGetStatic(
                    cache: *pLightcache,
                    pEnvCubemapTexture: (ITexture **)&vecDebugLightingOrigin.z,
                    flags: v129),
            LightingState_t::operator=(this: (LightingState_t *)&lightingDecalState.locallight[1], __that: v20),
            !*bStaticLighting) )
      {
        Static = LightcacheGetStatic(
                   cache: *pLightcache,
                   pEnvCubemapTexture: (ITexture **)&vecDebugLightingOrigin.z,
                   flags: 7u);
        LightingState_t::operator=(this: (LightingState_t *)&lightingDecalState.locallight[1], __that: Static);
      }
      if ( r_decalstaticprops.m_pParent != nullptr
        && r_decalstaticprops.m_pParent->m_Value.m_nValue != 0
        && v19 != nullptr
        && LOBYTE(drawInfo[1].m_DecalHandle) != 0
        && pModelInst_3 )
      {
        v22 = (float *)v19[6];
        v23 = v22[25] + *(float *)&lightingDecalState.locallight[2];
        v24 = v22[26] + *(float *)&lightingDecalState.locallight[3];
        *(float *)&drawInfo[1].m_FirstShadow = v22[24] + *(float *)&lightingDecalState.locallight[1];
        *(float *)&drawInfo[1].m_LightCacheHandle = v23;
        *(float *)&drawInfo[1].m_ColorMeshHandle = v24;
        v25 = (float *)v19[6];
        v26 = v25[28] + *(float *)&stats;
        v27 = v25[29] + lightingState.r_boxcolor[0].x;
        *(float *)&drawInfo[1].m_pLightingState = v25[27] + v136;
        *(float *)&drawInfo[2].m_pRenderable = v26;
        *(float *)&drawInfo[2].m_pModel = v27;
        v28 = (float *)v19[6];
        v29 = v28[31] + lightingState.r_boxcolor[0].z;
        v30 = v28[32] + lightingState.r_boxcolor[1].x;
        *(float *)&drawInfo[2].m_DecalHandle = v28[30] + lightingState.r_boxcolor[0].y;
        *(float *)&drawInfo[2].m_FirstShadow = v29;
        *(float *)&drawInfo[2].m_LightCacheHandle = v30;
        v31 = (float *)v19[6];
        v32 = v31[34] + lightingState.r_boxcolor[1].z;
        v33 = v31[35] + lightingState.r_boxcolor[2].x;
        *(float *)&drawInfo[2].m_ColorMeshHandle = v31[33] + lightingState.r_boxcolor[1].y;
        *(float *)&drawInfo[2].m_pLightingState = v32;
        *(float *)&drawInfo[3].m_pRenderable = v33;
        v34 = (float *)v19[6];
        v35 = v34[37] + lightingState.r_boxcolor[2].z;
        v36 = v34[38] + lightingState.r_boxcolor[3].x;
        *(float *)&drawInfo[3].m_pModel = v34[36] + lightingState.r_boxcolor[2].y;
        *(float *)&drawInfo[3].m_DecalHandle = v35;
        *(float *)&drawInfo[3].m_FirstShadow = v36;
        v37 = (float *)v19[6];
        v38 = v37[40] + lightingState.r_boxcolor[3].z;
        v39 = v37[41] + lightingState.r_boxcolor[4].x;
        *(float *)&drawInfo[3].m_LightCacheHandle = v37[39] + lightingState.r_boxcolor[3].y;
        *(float *)&drawInfo[3].m_ColorMeshHandle = v38;
        *(float *)&drawInfo[3].m_pLightingState = v39;
        LightingState_t::CopyLocalLights(
          this: (LightingState_t *)&vFinalAmbientCube[4].y,
          src: (const LightingState_t *)(v19[6] + 96));
        LightingState_t::AddAllLocalLights(
          this: (LightingState_t *)&vFinalAmbientCube[4].y,
          src: (const LightingState_t *)&lightingDecalState.locallight[1],
          &vecLightingOrigin);
      }
    }
    else
    {
      v10 = !*bStaticLighting;
      *(Vector *)&lightingState.numlights = vecLightingOrigin;
      lightingState.locallight[3] = (dworldlight_t *)&lightingState.numlights;
      if ( v10
        || (Dynamic = LightcacheGetDynamic(
                        origin: &vecLightingOrigin,
                        lightingState: (LightingState_t *)&lightingDecalState.locallight[1],
                        stats: (LightcacheGetDynamic_Stats *)&vecDebugLightingOrigin,
                        pRenderable: state->m_pRenderable,
                        flags: 6u,
                        bDebugModel: false),
            v10 = !*bStaticLighting,
            LODWORD(vecDebugLightingOrigin.z) = Dynamic,
            v10) )
      {
        LOBYTE(vecDebugLightingOrigin.x) = 0;
        if ( r_drawlightcache.m_pParent != nullptr
          && r_drawlightcache.m_pParent->m_Value.m_nValue == 5
          && v19 != nullptr )
        {
          v41 = v19[1];
          if ( v41 != 0 )
          {
            v42 = (char *)(v41 + 4);
            if ( v41 != -4 )
            {
              if ( (r_lightcachemodel.m_nFlags & 0x1000) != 0 )
              {
                m_pszString = "FCVAR_NEVER_AS_STRING";
              }
              else
              {
                m_pszString = r_lightcachemodel.m_pParent->m_Value.m_pszString;
                if ( m_pszString == nullptr )
                  m_pszString = (char *)defaultValue;
              }
              LOBYTE(vecDebugLightingOrigin.x) = V_stristr(pStr: v42, pSearch: m_pszString) != nullptr;
            }
          }
        }
        LODWORD(vecDebugLightingOrigin.z) = LightcacheGetDynamic(
                                              origin: &vecLightingOrigin,
                                              lightingState: (LightingState_t *)&lightingDecalState.locallight[1],
                                              stats: (LightcacheGetDynamic_Stats *)lightingDecalState.locallight,
                                              pRenderable: state->m_pRenderable,
                                              flags: 0xFu,
                                              bDebugModel: SLOBYTE(vecDebugLightingOrigin.x));
      }
      if ( pInfo[9] != nullptr && pInfo[10] == nullptr )
      {
        v44 = 0;
        if ( SLODWORD(lightingState.r_boxcolor[4].y) > 0 )
        {
          p_in1 = &in1;
          do
          {
            v46 = *((float **)&lightingState.r_boxcolor[4].z + v44);
            v47 = (const matrix3x4_t *)pInfo[9];
            *p_in1 = *v46;
            p_in1[1] = v46[1];
            p_in1[2] = v46[2];
            VectorITransform(in1: p_in1, in2: v47, out: v46);
            ++v44;
            p_in1 += 3;
          }
          while ( v44 < SLODWORD(lightingState.r_boxcolor[4].y) );
          v19 = vLightingOrigin_4;
        }
      }
      if ( v19 != nullptr && LOBYTE(drawInfo[1].m_DecalHandle) != 0 && pModelInst_3 )
      {
        LightcacheGetDynamic(
          origin: &vecLightingOrigin,
          lightingState: (LightingState_t *)&vFinalAmbientCube[4].y,
          stats: (LightcacheGetDynamic_Stats *)lightingDecalState.locallight,
          pRenderable: state->m_pRenderable,
          flags: 0xFu,
          bDebugModel: false);
        *(float *)&drawInfo[1].m_FirstShadow = vFinalAmbientCube[4].y;
        drawInfo[1].m_LightCacheHandle = (LightCacheHandle_t__ *)LODWORD(vFinalAmbientCube[4].z);
        *(Vector *)&drawInfo[1].m_ColorMeshHandle = vFinalAmbientCube[5];
        *(Vector *)&drawInfo[2].m_pModel = lightingDecalState.r_boxcolor[0];
        *(Vector *)&drawInfo[2].m_LightCacheHandle = lightingDecalState.r_boxcolor[1];
        *(Vector *)&drawInfo[3].m_pRenderable = lightingDecalState.r_boxcolor[2];
        *(Vector *)&drawInfo[3].m_FirstShadow = lightingDecalState.r_boxcolor[3];
        drawInfo[3].m_pLightingState = (CModelRender::ModelInstanceLightingState_t *)LODWORD(lightingDecalState.r_boxcolor[4].x);
        if ( pInfo[9] != nullptr && pInfo[10] == nullptr )
        {
          v48 = 0;
          if ( SLODWORD(lightingDecalState.r_boxcolor[4].y) > 0 )
          {
            v49 = &in1;
            do
            {
              v50 = *((float **)&lightingDecalState.r_boxcolor[4].z + v48);
              v51 = (const matrix3x4_t *)pInfo[9];
              *v49 = *v50;
              v49[1] = v50[1];
              v49[2] = v50[2];
              VectorITransform(in1: v49, in2: v51, out: v50);
              ++v48;
              v49 += 3;
            }
            while ( v48 < SLODWORD(lightingDecalState.r_boxcolor[4].y) );
          }
        }
      }
    }
    if ( *bStaticLighting || pLightcache != nullptr )
      v52 = &lightingDecalState.locallight[1];
    else
      v52 = (dworldlight_t **)CModelRender::TimeAverageLightingState(
                                this: (CModelRender *)lightingState.locallight[2],
                                handle: *((_WORD *)pInfo + 32),
                                pLightingState: (LightingState_t *)&lightingDecalState.locallight[1],
                                nEntIndex: (int)pInfo[12],
                                pLightingOrigin: &lightingState.locallight[3]->origin);
    y = vecDebugLightingOrigin.y;
    if ( bNeedsEnvCubemap && LODWORD(vecDebugLightingOrigin.z) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(vecDebugLightingOrigin.y) + 20))(
        a1: LODWORD(vecDebugLightingOrigin.y),
        a2: LODWORD(vecDebugLightingOrigin.z));
    if ( g_pMaterialSystemConfig->nFullbright == 1 )
    {
      if ( (_S4_0 & 1) == 0 )
      {
        _S4_0 |= 1u;
        white[0].x = 1.0;
        dword_105F5744 = 1065353216;
        dword_105F5748 = 1065353216;
        dword_105F574C = 1065353216;
        dword_105F5750 = 1065353216;
        dword_105F5754 = 1065353216;
        dword_105F5758 = 1065353216;
        dword_105F575C = 1065353216;
        dword_105F5760 = 1065353216;
        dword_105F5764 = 1065353216;
        dword_105F5768 = 1065353216;
        dword_105F576C = 1065353216;
        dword_105F5770 = 1065353216;
        dword_105F5774 = 1065353216;
        dword_105F5778 = 1065353216;
        dword_105F577C = 1065353216;
        dword_105F5780 = 1065353216;
        dword_105F5784 = 1065353216;
      }
      g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: white);
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(y) + 504))(a1: COERCE_FLOAT(LODWORD(y)));
    }
    else if ( bVertexLit )
    {
      if ( (drawFlags & 0x100) != 0 )
      {
        m_fValue = r_itemblinkmax.m_pParent->m_Value.m_fValue;
        v146 = r_itemblinkrate.m_pParent->m_Value.m_fValue;
        v130 = _Plat_FloatTime(this: (CStatTime *)r_itemblinkmax.m_pParent) * v146;
        v147 = (FastCos(x: v130) + 1.0) * m_fValue;
        if ( (_S4_0 & 2) == 0 )
          _S4_0 |= 2u;
        v54 = 1.0;
        v55 = *(float *)v52 + v147;
        if ( v55 > 1.0 )
          v55 = 1.0;
        temp[0].x = v55;
        v56 = *((float *)v52 + 1) + v147;
        if ( v56 > 1.0 )
          v56 = 1.0;
        dword_105F56FC = LODWORD(v56);
        v57 = *((float *)v52 + 2) + v147;
        if ( v57 > 1.0 )
          v57 = 1.0;
        dword_105F5700 = LODWORD(v57);
        v58 = *((float *)v52 + 3) + v147;
        if ( v58 > 1.0 )
          v58 = 1.0;
        dword_105F5704 = LODWORD(v58);
        v59 = *((float *)v52 + 4) + v147;
        if ( v59 > 1.0 )
          v59 = 1.0;
        dword_105F5708 = LODWORD(v59);
        v60 = *((float *)v52 + 5) + v147;
        if ( v60 > 1.0 )
          v60 = 1.0;
        dword_105F570C = LODWORD(v60);
        v61 = *((float *)v52 + 6) + v147;
        if ( v61 > 1.0 )
          v61 = 1.0;
        dword_105F5710 = LODWORD(v61);
        v62 = *((float *)v52 + 7) + v147;
        if ( v62 > 1.0 )
          v62 = 1.0;
        dword_105F5714 = LODWORD(v62);
        v63 = *((float *)v52 + 8) + v147;
        if ( v63 > 1.0 )
          v63 = 1.0;
        dword_105F5718 = LODWORD(v63);
        v64 = *((float *)v52 + 9) + v147;
        if ( v64 > 1.0 )
          v64 = 1.0;
        dword_105F571C = LODWORD(v64);
        v65 = *((float *)v52 + 10) + v147;
        if ( v65 > 1.0 )
          v65 = 1.0;
        dword_105F5720 = LODWORD(v65);
        v66 = *((float *)v52 + 11) + v147;
        if ( v66 > 1.0 )
          v66 = 1.0;
        dword_105F5724 = LODWORD(v66);
        v67 = *((float *)v52 + 12) + v147;
        if ( v67 > 1.0 )
          v67 = 1.0;
        dword_105F5728 = LODWORD(v67);
        v68 = *((float *)v52 + 13) + v147;
        if ( v68 > 1.0 )
          v68 = 1.0;
        dword_105F572C = LODWORD(v68);
        v69 = *((float *)v52 + 14) + v147;
        if ( v69 > 1.0 )
          v69 = 1.0;
        dword_105F5730 = LODWORD(v69);
        v70 = *((float *)v52 + 15) + v147;
        if ( v70 > 1.0 )
          v70 = 1.0;
        dword_105F5734 = LODWORD(v70);
        v71 = *((float *)v52 + 16) + v147;
        if ( v71 > 1.0 )
          v71 = 1.0;
        dword_105F5738 = LODWORD(v71);
        if ( (float)(*((float *)v52 + 17) + v147) <= 1.0 )
          v54 = *((float *)v52 + 17) + v147;
        dword_105F573C = LODWORD(v54);
        g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: temp);
      }
      else
      {
        v72 = (int)v52[18];
        if ( v72 > 0
          && ((_DWORD)pInfo[7][69] & 0x800) != 0
          && r_ambientboost.m_pParent != nullptr
          && r_ambientboost.m_pParent->m_Value.m_nValue != 0 )
        {
          v73 = *((float *)v52 + 1);
          v74 = *(float *)v52;
          v75 = *((float *)v52 + 2);
          v76 = (float)((float)(v73 * 0.58999997) + (float)(*(float *)v52 * 0.30000001)) + (float)(v75 * 0.11);
          v77 = v76;
          v78 = v76;
          if ( v76 >= 3.402823466385289e38 )
            v78 = 3.402823466385289e38;
          if ( v77 <= 0.0 )
            v77 = 0.0;
          v144 = v77;
          v79 = *((float *)v52 + 5) * 0.11 + *((float *)v52 + 3) * 0.30000001 + *((float *)v52 + 4) * 0.58999997;
          v148 = v79;
          v80 = v79;
          if ( v78 <= v79 )
            v80 = v78;
          if ( v144 >= v79 )
            v79 = v144;
          v81 = v148 + v76;
          v82 = *((float *)v52 + 7) * 0.58999997 + *((float *)v52 + 6) * 0.30000001 + *((float *)v52 + 8) * 0.11;
          v149 = v82;
          v83 = v82;
          v84 = v80;
          v85 = v83;
          *(double *)&lightingDecalState.numlights = v84;
          if ( v79 >= v83 )
            v85 = v79;
          v86 = v149 + v81;
          v87 = *((float *)v52 + 10) * 0.58999997 + *((float *)v52 + 9) * 0.30000001 + *((float *)v52 + 11) * 0.11;
          v150 = v87;
          v88 = v87;
          v89 = v85;
          v90 = v88;
          if ( v89 >= v88 )
            v90 = v89;
          v91 = v150 + v86;
          v92 = *((float *)v52 + 13) * 0.58999997 + *((float *)v52 + 12) * 0.30000001 + *((float *)v52 + 14) * 0.11;
          v151 = v92;
          v93 = v92;
          v94 = v90;
          v95 = v93;
          if ( v94 >= v93 )
            v95 = v94;
          v96 = v151 + v91;
          v97 = 0.30000001 * *((float *)v52 + 15) + 0.58999997 * *((float *)v52 + 16) + 0.11 * *((float *)v52 + 17);
          v152 = v97;
          v98 = v97;
          v99 = v95;
          v100 = v98;
          if ( v99 >= v98 )
            v100 = v99;
          v101 = 0.0;
          vLightingOrigin = (float)(v152 + v96) * 0.16666667;
          v102 = (float **)(v52 + 19);
          for ( i = v72; i != 0; --i )
          {
            v104 = *v102;
            v153 = (float)((float)((float)((*v102)[1] - vecLightingOrigin.y) * (float)((*v102)[1] - vecLightingOrigin.y))
                         + (float)((float)(**v102 - vecLightingOrigin.x) * (float)(**v102 - vecLightingOrigin.x)))
                 + (float)((float)((*v102)[2] - vecLightingOrigin.z) * (float)((*v102)[2] - vecLightingOrigin.z));
            v105 = 1.0;
            v106 = v153 * (*v102)[21] + sqrt(v153) * v104[20] + v104[19];
            if ( v106 > 0.0000099999997 )
            {
              avgCubeLuminance = v106;
              v105 = 1.0 / avgCubeLuminance;
            }
            ++v102;
            v101 = (float)((float)((float)((float)(v104[4] * v105) * 0.58999997)
                                 + (float)((float)(v104[3] * v105) * 0.30000001))
                         + (float)((float)(v104[5] * v105) * 0.11))
                 + v101;
          }
          if ( r_ambientmin.m_pParent->m_Value.m_fValue <= vLightingOrigin
            || (float)(r_ambientfraction.m_pParent->m_Value.m_fValue * v101) <= vLightingOrigin )
          {
            g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)v52);
          }
          else
          {
            v145 = v100;
            v107 = (float)(r_ambientfraction.m_pParent->m_Value.m_fValue * v101) / v145;
            if ( r_ambientfactor.m_pParent->m_Value.m_fValue <= v107 )
              v107 = r_ambientfactor.m_pParent->m_Value.m_fValue;
            v108 = *((float *)v52 + 4) * v107;
            v109 = *((float *)v52 + 5) * v107;
            pSaveLightPos[3].y = *((float *)v52 + 3) * v107;
            v110 = *((float *)v52 + 6);
            pSaveLightPos[3].z = v108;
            v111 = *((float *)v52 + 7);
            vFinalAmbientCube[0].x = v109;
            v112 = *((float *)v52 + 8) * v107;
            vFinalAmbientCube[0].y = v110 * v107;
            v113 = *((float *)v52 + 9);
            vFinalAmbientCube[0].z = v111 * v107;
            v114 = *((float *)v52 + 10);
            vFinalAmbientCube[1].x = v112;
            v115 = *((float *)v52 + 11) * v107;
            vFinalAmbientCube[1].y = v113 * v107;
            v116 = *((float *)v52 + 12);
            vFinalAmbientCube[1].z = v114 * v107;
            v117 = *((float *)v52 + 13);
            vFinalAmbientCube[2].x = v115;
            v118 = *((float *)v52 + 14) * v107;
            vFinalAmbientCube[2].y = v116 * v107;
            v119 = *((float *)v52 + 15);
            vFinalAmbientCube[2].z = v117 * v107;
            v120 = *((float *)v52 + 16);
            vFinalAmbientCube[3].x = v118;
            v121 = *((float *)v52 + 17) * v107;
            pSaveLightPos[2].y = v74 * v107;
            pSaveLightPos[2].z = v73 * v107;
            pSaveLightPos[3].x = v75 * v107;
            vFinalAmbientCube[3].y = v119 * v107;
            vFinalAmbientCube[3].z = v120 * v107;
            vFinalAmbientCube[4].x = v121;
            g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (Vector *)&pSaveLightPos[2].y);
          }
        }
        else if ( state->m_pStudioHdr != nullptr
               && state->m_pStudioHdr->numbones > 1
               && r_modelAmbientMin.m_pParent->m_Value.m_fValue > 0.0 )
        {
          v122 = 0;
          v123 = r_modelAmbientMin.m_pParent->m_Value.m_fValue;
          do
          {
            v124 = *(float *)((char *)&pSaveLightPos[2].y + 4 * v122 + (char *)v52 - (char *)&pSaveLightPos[2].y);
            if ( v123 <= v124 )
              *(&pSaveLightPos[2].y + v122) = v124;
            else
              *(&pSaveLightPos[2].y + v122) = v123;
            ++v122;
          }
          while ( v122 < 18 );
          ((void (__stdcall *)(float *))g_pStudioRender->SetAmbientLightColors)(a1: &pSaveLightPos[2].y);
        }
        else
        {
          ((void (__stdcall *)(dworldlight_t **))g_pStudioRender->SetAmbientLightColors)(a1: v52);
        }
      }
      R_SetNonAmbientLightingState(
        numLights: (int)v52[18],
        locallight: v52 + 19,
        pNumLightDescs: (int *)&drawInfo[4].m_FirstShadow,
        pLightDescs: (LightDesc_t *)&drawInfo[4].m_LightCacheHandle,
        bUpdateStudioRenderLights: true);
      if ( vLightingOrigin_4 != nullptr && LOBYTE(drawInfo[1].m_DecalHandle) != 0 && pModelInst_3 )
        R_SetNonAmbientLightingState(
          numLights: SLODWORD(lightingDecalState.r_boxcolor[4].y),
          locallight: (dworldlight_t **)&lightingDecalState.r_boxcolor[4].z,
          pNumLightDescs: (int *)&drawInfo[4].m_FirstShadow,
          pLightDescs: (LightDesc_t *)&drawInfo[4].m_LightCacheHandle,
          bUpdateStudioRenderLights: false);
      y = vecDebugLightingOrigin.y;
    }
    if ( pInfo[9] != nullptr && pInfo[10] == nullptr )
    {
      v125 = 0;
      if ( SLODWORD(lightingState.r_boxcolor[4].y) > 0 )
      {
        v126 = (float *)&v132;
        do
        {
          v127 = *((float **)&lightingState.r_boxcolor[4].z + v125);
          *v127 = *(v126 - 2);
          ++v125;
          v128 = *(v126 - 1);
          v126 += 3;
          v127[1] = v128;
          v127[2] = *(v126 - 3);
        }
        while ( v125 < SLODWORD(lightingState.r_boxcolor[4].y) );
      }
    }
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(y) + 12))(a1: COERCE_FLOAT(LODWORD(y)));
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(y) + 4))(a1: COERCE_FLOAT(LODWORD(y)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF7A0
// Name: public: virtual void CModelRender::SetupLightingEx(class Vector const __near &,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetupLightingEx(CModelRender *this, const Vector *vecCenter, unsigned __int16 handle)
{
  IMatRenderContext *v4; // esi
  float z; // xmm0_4
  MaterialLightingState_t state; // [esp+8h] [ebp-1BCh] BYREF
  ITexture *pEnvCubemapTexture; // [esp+1C0h] [ebp-4h] BYREF

  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  state.m_vecLightingOrigin.x = vecCenter->x;
  state.m_vecLightingOrigin.y = vecCenter->y;
  z = vecCenter->z;
  pEnvCubemapTexture = nullptr;
  state.m_vecLightingOrigin.z = z;
  state.m_nLocalLightCount = CModelRender::GetLightingConditions(
                               this,
                               vecLightingOrigin: vecCenter,
                               pColors: state.m_vecAmbientCube,
                               nMaxLocalLights: 4,
                               pLocalLights: state.m_pLocalLightDesc,
                               &pEnvCubemapTexture,
                               handle,
                               bAllowFast: false);
  v4->SetLightingState(this: v4, a2: &state);
  if ( pEnvCubemapTexture != nullptr )
    v4->BindLocalCubemap(this: v4, a2: pEnvCubemapTexture);
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100DF860
// Name: public: virtual int CModelRender::DrawModelEx(struct ModelRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::DrawModelEx(CModelRender *this, matrix3x4_t *pInfo)
{
  matrix3x4_t *v2; // edi
  IMatRenderContext *v4; // esi
  QAngle *v6; // [esp-Ch] [ebp-64h]
  const Vector *v7; // [esp-8h] [ebp-60h]
  matrix3x4_t tmpmat; // [esp+Ch] [ebp-4Ch] BYREF
  DrawModelState_t state; // [esp+3Ch] [ebp-1Ch] BYREF

  v2 = pInfo;
  if ( LODWORD(pInfo->m_flMatVal[2][0]) == 0 )
  {
    v7 = (const Vector *)pInfo;
    v6 = (QAngle *)&pInfo->m_flMatVal[0][3];
    LODWORD(pInfo->m_flMatVal[2][0]) = &tmpmat;
    AngleMatrix(angles: v6, position: v7, matrix: &tmpmat);
  }
  v4 = materials->GetRenderContext(this: materials);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->AddRefRenderData(this: v4);
  if ( this->DrawModelSetup(this, a2: v4, a3: (ModelRenderInfo_t *)v2, a4: &state, a5: &pInfo) )
  {
    if ( (LOBYTE(v2->m_flMatVal[2][3]) & 1) != 0 )
      this->DrawModelExecute(this, a2: v4, a3: &state, a4: (const ModelRenderInfo_t *)v2, a5: pInfo);
    v4->ReleaseRenderData(this: v4);
    v4->EndRender(this: v4);
    v4->Release(this: v4);
    return 1;
  }
  else
  {
    v4->ReleaseRenderData(this: v4);
    v4->EndRender(this: v4);
    v4->Release(this: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF940
// Name: public: virtual class matrix3x4a_t __near * CModelRender::DrawModelShadowSetup(class IClientRenderable __near *,int,int,struct DrawModelInfo_t __near *,class matrix3x4a_t __near *)
// Source: json
//------------------------------------------------------------------------------
matrix3x4a_t *__userpurge CModelRender::DrawModelShadowSetup@<eax>(
        CModelRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IClientRenderable *pRenderable,
        int body,
        CMatRenderContextPtr skin,
        float pInfo,
        matrix3x4a_t *pCustomBoneToWorld)
{
  int v9; // eax
  int v10; // edi
  studiohdr_t *v12; // eax
  DrawModelInfo_t *v13; // esi
  int v14; // eax
  int m_pObject; // eax
  IMatRenderContext *v16; // edi
  int m_nValue; // eax
  studiohdr_t *m_pStudioHdr; // ecx
  float m_fValue; // xmm0_4
  IMatRenderContext_vtbl *v20; // ebx
  int v21; // eax
  double v22; // st7
  int v23; // eax
  studiohwdata_t *m_pHardwareData; // ecx
  int m_NumLODs; // eax
  studiohwdata_t *v26; // edx
  matrix3x4a_t *m_pRenderData; // ebx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  IClientRenderable_vtbl *v29; // edi
  CClientState *BaseLocalClient; // eax
  float v31; // [esp+0h] [ebp-18h]
  float Time; // [esp+4h] [ebp-14h]
  CMatRenderData<matrix3x4a_t> v33; // [esp+8h] [ebp-10h] BYREF

  if ( (_S6_0 & 1) == 0 )
  {
    _S6_0 |= 1u;
    ConVar::ConVar(this: &r_shadowlod, pName: "r_shadowlod", pDefaultValue: "-1", flags: 0);
    atexit(func: CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlod__);
  }
  if ( (_S6_0 & 2) == 0 )
  {
    _S6_0 |= 2u;
    ConVar::ConVar(this: &r_shadowlodbias, pName: "r_shadowlodbias", pDefaultValue: "2", flags: 0);
    atexit(func: CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlodbias__);
  }
  v9 = ((int (__thiscall *)(IClientRenderable *, int, int))pRenderable->GetModel)(a1: pRenderable, a2: a3, a3: a2);
  v10 = v9;
  if ( v9 == 0 || *(_DWORD *)(v9 + 272) != 3 )
    return nullptr;
  v12 = (studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, int))g_pMDLCache->GetStudioHdr)(
                         a1: g_pMDLCache,
                         a2: *(unsigned __int16 *)(v9 + 312),
                         a3: a4);
  v13 = (DrawModelInfo_t *)LODWORD(pInfo);
  *(_DWORD *)LODWORD(pInfo) = v12;
  v13->m_pColorMeshes = nullptr;
  if ( v12->numbodyparts == 0 )
    return nullptr;
  v14 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: *(unsigned __int16 *)(v10 + 312));
  v13->m_pHardwareData = (studiohwdata_t *)v14;
  if ( v14 == 0 )
    return nullptr;
  m_pObject = (int)skin.m_pObject;
  v13->m_Body = body;
  v13->m_Decals = nullptr;
  v13->m_Skin = m_pObject;
  v13->m_pClientEntity = (void *)pRenderable;
  v13->m_HitboxSet = 0;
  v16 = materials->GetRenderContext(this: materials);
  skin.m_pObject = v16;
  if ( v16 != nullptr )
    v16->BeginRender(this: v16);
  if ( r_shadowlod.m_pParent != nullptr )
    m_nValue = r_shadowlod.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_pStudioHdr = v13->m_pStudioHdr;
  v13->m_Lod = m_nValue;
  if ( (m_pStudioHdr->flags & 0x40) != 0 )
  {
    v13->m_Lod = v13->m_pHardwareData->m_NumLODs - 1;
  }
  else if ( m_nValue == -2 )
  {
    v13->m_Lod = v13->m_pHardwareData->m_NumLODs - 1;
  }
  else if ( m_nValue < 0 )
  {
    m_fValue = r_shadowlodbias.m_pParent->m_Value.m_fValue;
    pInfo = m_fValue <= 0.0 ? 1.0 : 1.0 / m_fValue;
    v20 = v16->__vftable;
    v21 = ((int (__thiscall *)(IClientRenderable *, _DWORD))pRenderable->GetRenderOrigin)(a1: pRenderable, a2: 0.5);
    v22 = ((double (__thiscall *)(IMatRenderContext *, int))v20->ComputePixelWidthOfSphere)(a1: v16, a2: v21);
    v31 = v22 * pInfo;
    v23 = ((int (__stdcall *)(studiohwdata_t *, _DWORD, _DWORD))g_pStudioRender->ComputeModelLod)(
            a1: v13->m_pHardwareData,
            a2: LODWORD(v31),
            a3: 0);
    m_pHardwareData = v13->m_pHardwareData;
    v13->m_Lod = v23;
    m_NumLODs = m_pHardwareData->m_NumLODs;
    v13->m_Lod = m_NumLODs - 2;
    if ( m_NumLODs - 2 < 0 )
      v13->m_Lod = 0;
  }
  v26 = v13->m_pHardwareData;
  if ( v13->m_Lod < v26->m_RootLOD )
    v13->m_Lod = v26->m_RootLOD;
  m_pRenderData = pCustomBoneToWorld;
  v33.m_pRenderContext = v16;
  memset(&v33.m_pRenderData, 0, 9);
  if ( pCustomBoneToWorld == nullptr )
  {
    LockRenderData = v16->LockRenderData;
    v33.m_nCount = v13->m_pStudioHdr->numbones;
    v33.m_pRenderData = (matrix3x4a_t *)LockRenderData(this: v16, a2: 48 * v33.m_nCount);
    v33.m_bNeedsUnlock = true;
    m_pRenderData = v33.m_pRenderData;
  }
  v29 = pRenderable->__vftable;
  BaseLocalClient = GetBaseLocalClient();
  Time = CClientState::GetTime(this: BaseLocalClient);
  if ( ((unsigned __int8 (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, int, _DWORD))v29->SetupBones)(
         a1: pRenderable,
         a2: m_pRenderData,
         a3: v13->m_pStudioHdr->numbones,
         a4: 1024 << v13->m_Lod,
         a5: LODWORD(Time)) == 0 )
  {
    CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &v33);
    CMatRenderContextPtr::~CMatRenderContextPtr(this: &skin);
    return nullptr;
  }
  CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &v33);
  CMatRenderContextPtr::~CMatRenderContextPtr(this: &skin);
  return m_pRenderData;
}

//------------------------------------------------------------------------------
// Address: 0x100DFBF0
// Name: public: virtual void CModelRender::AddDecal(unsigned short,struct Ray_t const __near &,class Vector const __near &,int,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelRender::AddDecal(
        CModelRender *this@<ecx>,
        int a2@<edi>,
        int handle,
        const Ray_t *ray,
        const Vector *decalUp,
        int decalIndex,
        int body,
        int noPokeThru,
        IStudioRender_vtbl *maxLODToDecal)
{
  unsigned __int16 v9; // bx
  int v11; // edi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v12; // edi
  studiohwdata_t *v13; // eax
  studiohdr_t *v14; // eax
  int numbones; // ebx
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v17; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  IClientRenderable_vtbl *v19; // eax
  CClientState *BaseLocalClient; // eax
  studiohdr_t *(__thiscall *GetStudioHdr)(IMDLCache *, unsigned __int16); // edx
  int v22; // eax
  int studio; // [esp-14h] [ebp-54h]
  float Time; // [esp+Ch] [ebp-34h]
  IStudioRender_vtbl *v25; // [esp+Ch] [ebp-34h]
  CMatRenderData<matrix3x4a_t> v27; // [esp+1Ch] [ebp-24h] BYREF
  IClientRenderable_vtbl *v28; // [esp+2Ch] [ebp-14h]
  IClientRenderable *m_pRenderable; // [esp+30h] [ebp-10h]
  int v30; // [esp+34h] [ebp-Ch]
  IMaterial *v31; // [esp+38h] [ebp-8h] BYREF
  int v32; // [esp+3Ch] [ebp-4h]

  v9 = handle;
  if ( (_WORD)handle != 0xFFFF )
  {
    v11 = decalIndex;
    R_DecalGetMaterialAndSize(decalIndex, pDecalMaterial: &v31, w: (float *)&handle, h: (float *)&decalIndex);
    if ( v31 != nullptr )
    {
      *(float *)&handle = *(float *)&handle * 0.5;
      *(float *)&decalIndex = *(float *)&decalIndex * 0.5;
      if ( v31->FindVarFast(this: v31, a2: "$decalFadeDuration", a3: &s_DecalFadeVarCache) == nullptr )
      {
        if ( *(float *)&handle <= *(float *)&decalIndex )
          v32 = decalIndex;
        else
          v32 = handle;
        v12 = &this->m_ModelInstances.m_Memory.m_pMemory[v9];
        if ( !CModelRender::IsModelInstanceValid(this, handle: v9) )
        {
          g_pStudioRender->DestroyDecalList(this: g_pStudioRender, a2: v12->m_Element.m_DecalHandle);
          v12->m_Element.m_DecalHandle = nullptr;
        }
        if ( v12->m_Element.m_DecalHandle == nullptr )
        {
          v13 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: v12->m_Element.m_pModel->studio);
          v12->m_Element.m_DecalHandle = g_pStudioRender->CreateDecalList(this: g_pStudioRender, a2: v13);
        }
        v14 = modelinfo->GetStudiomodel(this: modelinfo, a2: v12->m_Element.m_pModel);
        if ( v14->numbodyparts != 0 )
        {
          numbones = v14->numbones;
          GetRenderContext = g_pMaterialSystem->GetRenderContext;
          v30 = numbones;
          v17 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))GetRenderContext)(
                                       a1: g_pMaterialSystem,
                                       a2);
          if ( v17 != nullptr )
            v17->BeginRender(this: v17);
          LockRenderData = v17->LockRenderData;
          v27.m_pRenderContext = v17;
          v27.m_nCount = numbones;
          v27.m_pRenderData = (matrix3x4a_t *)LockRenderData(this: v17, a2: 48 * numbones);
          m_pRenderable = v12->m_Element.m_pRenderable;
          v19 = m_pRenderable->__vftable;
          v27.m_bNeedsUnlock = true;
          v28 = v19;
          BaseLocalClient = GetBaseLocalClient();
          Time = CClientState::GetTime(this: BaseLocalClient);
          ((void (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, int, _DWORD))v28->SetupBones)(
            a1: m_pRenderable,
            a2: v27.m_pRenderData,
            a3: v30,
            a4: 524032,
            a5: LODWORD(Time));
          v25 = maxLODToDecal;
          GetStudioHdr = g_pMDLCache->GetStudioHdr;
          studio = v12->m_Element.m_pModel->studio;
          maxLODToDecal = g_pStudioRender->__vftable;
          v22 = ((int (__thiscall *)(IMDLCache *, int, matrix3x4a_t *, const Ray_t *, const Vector *, IMaterial *, int, int, int, IStudioRender_vtbl *))GetStudioHdr)(
                  a1: g_pMDLCache,
                  a2: studio,
                  a3: v27.m_pRenderData,
                  a4: ray,
                  a5: decalUp,
                  a6: v31,
                  a7: v32,
                  a8: body,
                  a9: noPokeThru,
                  a10: v25);
          ((void (__thiscall *)(IStudioRender *, StudioDecalHandle_t__ *, int))maxLODToDecal->AddDecal)(
            a1: g_pStudioRender,
            a2: v12->m_Element.m_DecalHandle,
            a3: v22);
          CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &v27);
          v17->EndRender(this: v17);
          v17->Release(this: v17);
        }
      }
    }
    else
    {
      DevWarning(a1: "Bad decal index %d\n", v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFE20
// Name: public: virtual void CModelRender::RemoveAllDecalsFromAllModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::RemoveAllDecalsFromAllModels(CModelRender *this)
{
  int i; // esi

  for ( i = this->m_ModelInstances.m_Head;
        (_WORD)i != 0xFFFF;
        i = this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)i].m_Next )
  {
    this->RemoveAllDecals(this, a2: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFE60
// Name: public: virtual bool CPooledVBAllocator_ColorMesh::Init(unsigned __int64,int)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CPooledVBAllocator_ColorMesh::Init@<al>(
        CPooledVBAllocator_ColorMesh *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        unsigned __int64 format,
        int numVerts)
{
  int v7; // esi
  IMesh *v8; // eax
  unsigned __int8 *v9; // edx
  int m_ActualVertexSize; // eax
  int m_nVertexCount; // eax
  bool v12; // bl
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1E8h] BYREF

  if ( this->m_pMesh != nullptr )
  {
    _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh's internal mesh (vertex buffer) should have been freed!\n");
    return false;
  }
  else if ( this->m_numAllocations <= 0 )
  {
    if ( g_VBAllocTracker != nullptr )
      g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: "CPooledVBAllocator_ColorMesh::Init");
    v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    v8 = (IMesh *)(*(int (__thiscall **)(int, _DWORD, _DWORD, const char *))(*(_DWORD *)v7 + 220))(
                    a1: v7,
                    a2: format,
                    a3: HIDWORD(format),
                    a4: "Lighting Verts");
    this->m_pMesh = v8;
    if ( v8 != nullptr )
    {
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh: this->m_pMesh,
        type: MATERIAL_HETEROGENOUS,
        nVertexCount: numVerts,
        nIndexCount: 0,
        pMeshSettings: nullptr);
      v9 = &meshBuilder.m_VertexBuilder.m_pSpecular[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                  * meshBuilder.m_VertexBuilder.m_VertexSize_Specular];
      m_ActualVertexSize = meshBuilder.m_ActualVertexSize;
      this->m_totalVerts = numVerts;
      this->m_pVertexBufferBase = v9;
      this->m_vertexSize = m_ActualVertexSize;
      this->m_nextFreeOffset = 0;
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
      meshBuilder.m_pMesh->UnlockMesh(
        this: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
        a4: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    }
    if ( g_VBAllocTracker != nullptr )
      g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
    v12 = this->m_pMesh != nullptr;
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
    return v12;
  }
  else
  {
    _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh has unfreed allocations!");
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0050
// Name: public: virtual void CPooledVBAllocator_ColorMesh::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPooledVBAllocator_ColorMesh::Clear(CPooledVBAllocator_ColorMesh *this@<ecx>, int a2@<esi>)
{
  int v3; // esi

  if ( this->m_pMesh != nullptr )
  {
    if ( this->m_numAllocations > 0 )
      _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Clear should not be called until all allocations released!\n");
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, IMesh *))(*(_DWORD *)v3 + 224))(a1: v3, a2: this->m_pMesh);
    this->m_pMesh = nullptr;
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
  this->m_pVertexBufferBase = nullptr;
  this->m_totalVerts = 0;
  this->m_vertexSize = 0;
  this->m_numAllocations = 0;
  this->m_numVertsAllocated = 0;
  this->m_bStartedDeallocation = false;
  this->m_nextFreeOffset = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100E00D0
// Name: public: struct memhandle_t__ __near * CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>::CacheCreate(struct colormeshparams_t const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CColorMeshData *__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CacheCreate(
        CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *> *this,
        memhandle_t__ *createParams,
        unsigned int flags)
{
  int m_nValue; // eax
  const colormeshparams_t *v5; // esi
  CColorMeshData *result; // eax

  if ( r_staticlight_streams.m_pParent != nullptr )
    m_nValue = r_staticlight_streams.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v5 = (const colormeshparams_t *)createParams;
  this->m_pCache->EnsureCapacity(
    this: this->m_pCache,
    a2: 4 * (*(_DWORD *)createParams + m_nValue * *((_DWORD *)createParams + 1)),
    a3: 1u);
  result = CColorMeshData::CreateResource(params: v5);
  if ( result != nullptr )
  {
    this->m_pCache->AddEx(
      this: this->m_pCache,
      a2: (unsigned int)result,
      a3: result,
      a4: result->m_nTotalSize,
      a5: flags,
      a6: &createParams);
    return (CColorMeshData *)createParams;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E0140
// Name: public: virtual bool CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>::HandleCacheNotification(struct DataCacheNotification_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::HandleCacheNotification(
        CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *> *this,
        const DataCacheNotification_t *notification)
{
  if ( (unsigned int)(notification->type - 1) > 2 )
    return 0;
  CColorMeshData::DestroyResource(this: (CColorMeshData *)notification->clientId);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E0230
// Name: public: virtual void CMemberFunctor2<class CModelRender __near *,void (CModelRender::*)(int,struct memhandle_t__ __near * __near *),int,struct memhandle_t__ __near * __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CModelRender *,void (__thiscall CModelRender::*)(int,memhandle_t__ * *),int,memhandle_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CModelRender *,void (__thiscall CModelRender::*)(int,memhandle_t__ * *),int,memhandle_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, int, memhandle_t__ **))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + HIDWORD(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x100E0540
// Name: void R_RemoveAllDecalsFromAllModels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_RemoveAllDecalsFromAllModels()
{
  int m_Head; // esi

  m_Head = s_ModelRender.m_ModelInstances.m_Head;
  if ( s_ModelRender.m_ModelInstances.m_Head != 0xFFFF )
  {
    do
    {
      s_ModelRender.RemoveAllDecals(this: &s_ModelRender, a2: m_Head);
      m_Head = s_ModelRender.m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
    }
    while ( (_WORD)m_Head != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0590
// Name: void DrawModelDebugOverlay(struct DrawModelInfo_t const __near &,struct DrawModelResults_t const __near &,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DrawModelDebugOverlay(
        int a1@<ebp>,
        const DrawModelInfo_t *info,
        const DrawModelResults_t *results,
        const Vector *origin,
        float r,
        float g,
        float b)
{
  char *m_pszString; // eax
  const DrawModelInfo_t *v8; // esi
  studiohdr_t *v9; // edx
  int v10; // eax
  int v11; // ecx
  char *v12; // eax
  int v13; // ecx
  char *v14; // eax
  char *v15; // edi
  int v16; // eax
  int v17; // ecx
  char *v18; // eax
  int v19; // ecx
  const char *v20; // eax
  float m_fValue; // xmm3_4
  const Vector *v22; // edi
  __int128 v23; // xmm0
  float v24; // xmm0_4
  __int128 v25; // xmm0
  studiohdr_t *m_pStudioHdr; // ecx
  int studiohdr2index; // eax
  int v28; // edx
  char *v29; // eax
  int v30; // edx
  char *name; // eax
  char *v32; // eax
  const char *v33; // eax
  bool v34; // cc
  __int64 v35; // rdi
  int v36; // eax
  const char *v37; // edx
  const char *v38; // eax
  unsigned int m_Int64; // eax
  int v40; // [esp+10h] [ebp-444h]
  const char *v41; // [esp+14h] [ebp-440h]
  char v42[12]; // [esp+28h] [ebp-42Ch] BYREF
  _BYTE buf_960[40]; // [esp+428h] [ebp-2Ch] OVERLAPPED
  int buf_1004; // [esp+454h] [ebp+0h]

  *(_DWORD *)&buf_960[32] = a1;
  *(_DWORD *)&buf_960[36] = buf_1004;
  *(_DWORD *)&buf_960[28] = 1065353216;
  if ( (r_drawmodelstatsoverlayfilter.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = r_drawmodelstatsoverlayfilter.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  if ( _V_stricmp(s1: m_pszString, s2: "-1") == 0 )
  {
    m_fValue = r_drawmodelstatsoverlaydistance.m_pParent->m_Value.m_fValue;
    if ( m_fValue == 1.0 )
    {
      v22 = origin;
      v23 = 0;
      *(float *)&v23 = fsqrt(
                         (float)((float)((float)(g_CurrentViewOrigin.y - v22->y)
                                       * (float)(g_CurrentViewOrigin.y - v22->y))
                               + (float)((float)(g_CurrentViewOrigin.z - v22->z)
                                       * (float)(g_CurrentViewOrigin.z - v22->z)))
                       + (float)((float)(g_CurrentViewOrigin.x - v22->x) * (float)(g_CurrentViewOrigin.x - v22->x)));
      *(_OWORD *)buf_960 = v23;
      v24 = *(float *)&v23 / m_fValue;
      if ( v24 >= 0.0 )
      {
        if ( v24 > 1.0 )
          v24 = 1.0;
        v8 = info;
        *(float *)&buf_960[28] = 1.0 - v24;
      }
      else
      {
        v8 = info;
        *(float *)&buf_960[28] = 1.0 - 0.0;
      }
LABEL_37:
      m_pStudioHdr = v8->m_pStudioHdr;
      if ( v8->m_pStudioHdr != nullptr )
      {
        studiohdr2index = m_pStudioHdr->studiohdr2index;
        if ( studiohdr2index != 0
          && (v28 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8],
              v29 = (char *)m_pStudioHdr + studiohdr2index,
              v28 != 0)
          && &v29[v28] != nullptr )
        {
          v30 = *((_DWORD *)v29 + 5);
          if ( v30 == 0 )
            goto LABEL_61;
          name = &v29[v30];
        }
        else
        {
          name = m_pStudioHdr->name;
        }
        if ( name != nullptr && v8->m_pHardwareData != nullptr )
        {
          v32 = studiohdr_t::pszName(this: m_pStudioHdr);
          CDebugOverlay::AddTextOverlay(
            textPos: v22,
            line_offset: 0,
            duration: 0.0,
            r,
            g,
            b,
            alpha: *(float *)&buf_960[28],
            text: v32);
          V_snprintf(
            pDest: v42,
            maxLen: 1024,
            pFormat: "lod: %d/%d\n",
            results->m_nLODUsed + 1,
            v8->m_pHardwareData->m_NumLODs);
          CDebugOverlay::AddTextOverlay(
            textPos: v22,
            line_offset: 1,
            duration: 0.0,
            r,
            g,
            b,
            alpha: *(float *)&buf_960[28],
            text: v42);
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "tris: %d\n", results->m_ActualTriCount);
          CDebugOverlay::AddTextOverlay(
            textPos: v22,
            line_offset: 2,
            duration: 0.0,
            r,
            g,
            b,
            alpha: *(float *)&buf_960[28],
            text: v42);
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "hardware bones: %d\n", results->m_NumHardwareBones);
          CDebugOverlay::AddTextOverlay(
            textPos: v22,
            line_offset: 3,
            duration: 0.0,
            r,
            g,
            b,
            alpha: *(float *)&buf_960[28],
            text: v42);
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "num batches: %d\n", results->m_NumBatches);
          CDebugOverlay::AddTextOverlay(
            textPos: v22,
            line_offset: 4,
            duration: 0.0,
            r,
            g,
            b,
            alpha: *(float *)&buf_960[28],
            text: v42);
          v33 = "true";
          if ( (info->m_pStudioHdr->flags & 0x40) == 0 )
            v33 = "false";
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "has shadow lod: %s\n", v33);
          CDebugOverlay::AddTextOverlay(
            textPos: v22,
            line_offset: 5,
            duration: 0.0,
            r,
            g,
            b,
            alpha: *(float *)&buf_960[28],
            text: v42);
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "num materials: %d\n", results->m_NumMaterials);
          CDebugOverlay::AddTextOverlay(
            textPos: v22,
            line_offset: 6,
            duration: 0.0,
            r,
            g,
            b,
            alpha: *(float *)&buf_960[28],
            text: v42);
          v34 = results->m_Materials.m_Size <= 0;
          LODWORD(v35) = 7;
          *(_DWORD *)&buf_960[12] = 0;
          if ( !v34 )
          {
            *(_DWORD *)&buf_960[24] = &results->m_Materials;
            do
            {
              if ( **(_DWORD **)&buf_960[24] != 0 )
              {
                v36 = (*(int (__thiscall **)(_DWORD))(***(_DWORD ***)&buf_960[24] + 140))(a1: **(_DWORD **)&buf_960[24]);
                v37 = "passes";
                if ( v36 <= 1 )
                  v37 = "pass";
                v38 = (const char *)(****(int (__thiscall *****)(_DWORD, int, const char *))&buf_960[24])(
                                      a1: **(_DWORD **)&buf_960[24],
                                      a2: v36,
                                      a3: v37);
                V_snprintf(pDest: v42, maxLen: 1024, pFormat: "\t%s (%d %s)\n", v38, v40, v41);
                CDebugOverlay::AddTextOverlay(
                  textPos: origin,
                  line_offset: v35,
                  duration: 0.0,
                  r,
                  g,
                  b,
                  alpha: *(float *)&buf_960[28],
                  text: v42);
                LODWORD(v35) = v35 + 1;
              }
              *(_DWORD *)&buf_960[24] += 4;
              ++*(_DWORD *)&buf_960[12];
            }
            while ( *(int *)&buf_960[12] < results->m_Materials.m_Size );
          }
          if ( results->m_Materials.m_Size > results->m_NumMaterials )
          {
            CDebugOverlay::AddTextOverlay(
              textPos: origin,
              line_offset: v35,
              duration: 0.0,
              r,
              g,
              b,
              alpha: *(float *)&buf_960[28],
              text: "(Remaining materials not shown)\n");
            LODWORD(v35) = v35 + 1;
          }
          if ( r_drawmodelstatsoverlay.m_pParent != nullptr && r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue == 2 )
          {
            m_Int64 = results->m_RenderTime.m_Duration.m_Int64;
            HIDWORD(v35) = HIDWORD(results->m_RenderTime.m_Duration.m_Int64);
            *(_QWORD *)&buf_960[8] = v35 & 0x8000000000000000uLL;
            V_snprintf(
              pDest: v42,
              maxLen: 1024,
              pFormat: "Render Time: %0.1f ms\n",
              (double)((double)__PAIR64__(HIDWORD(v35), m_Int64) * _g_ClockSpeedMillisecondsMultiplier));
            CDebugOverlay::AddTextOverlay(
              textPos: origin,
              line_offset: v35,
              duration: 0.0,
              r,
              g,
              b,
              alpha: *(float *)&buf_960[28],
              text: v42);
          }
          return;
        }
      }
LABEL_61:
      CDebugOverlay::AddTextOverlay(
        textPos: v22,
        line_offset: 0,
        duration: 0.0,
        r: 1.0,
        g: 0.80000001,
        b: 0.80000001,
        alpha: 1.0,
        text: "This model has problems! See a programmer!");
      return;
    }
    v25 = 0;
    *(float *)&v25 = fsqrt(
                       (float)((float)((float)(g_CurrentViewOrigin.y - origin->y)
                                     * (float)(g_CurrentViewOrigin.y - origin->y))
                             + (float)((float)(g_CurrentViewOrigin.z - origin->z)
                                     * (float)(g_CurrentViewOrigin.z - origin->z)))
                     + (float)((float)(g_CurrentViewOrigin.x - origin->x) * (float)(g_CurrentViewOrigin.x - origin->x)));
    *(_OWORD *)buf_960 = v25;
    if ( *(float *)&v25 < 36.0 || *(float *)buf_960 > m_fValue )
      return;
    v8 = info;
    goto LABEL_36;
  }
  v8 = info;
  v9 = info->m_pStudioHdr;
  if ( info->m_pStudioHdr == nullptr )
  {
    v22 = origin;
    goto LABEL_61;
  }
  v10 = v9->studiohdr2index;
  if ( v10 == 0 || (v11 = *(_DWORD *)&v9->name[v10 + 8], v12 = (char *)v9 + v10, v11 == 0) || &v12[v11] == nullptr )
  {
    v14 = v9->name;
    goto LABEL_13;
  }
  v13 = *((_DWORD *)v12 + 5);
  if ( v13 == 0 )
  {
LABEL_36:
    v22 = origin;
    goto LABEL_37;
  }
  v14 = &v12[v13];
LABEL_13:
  if ( v14 == nullptr )
    goto LABEL_36;
  if ( (r_drawmodelstatsoverlayfilter.m_nFlags & 0x1000) != 0 )
  {
    v15 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v15 = r_drawmodelstatsoverlayfilter.m_pParent->m_Value.m_pszString;
    if ( v15 == nullptr )
      v15 = (char *)defaultValue;
  }
  v16 = v9->studiohdr2index;
  if ( v16 != 0 && (v17 = *(_DWORD *)&v9->name[v16 + 8], v18 = (char *)v9 + v16, v17 != 0) && &v18[v17] != nullptr )
  {
    v19 = *((_DWORD *)v18 + 5);
    v20 = v19 != 0 ? &v18[v19] : nullptr;
  }
  else
  {
    v20 = v9->name;
  }
  if ( V_stristr(pStr: v20, pSearch: v15) != nullptr )
    goto LABEL_36;
}

//------------------------------------------------------------------------------
// Address: 0x100E0ED0
// Name: public: virtual void CModelRender::CleanupStaticLightingState(int,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::CleanupStaticLightingState(
        CModelRender *this,
        int nCount,
        memhandle_t__ **pColorMeshHandles)
{
  IMatRenderContext *v4; // esi
  ICallQueue *v5; // edi
  int i; // edi
  CMatRenderData<memhandle_t__ *> renderData; // [esp+Ch] [ebp-10h] BYREF

  v4 = materials->GetRenderContext(this: materials);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v5 = v4->GetCallQueue(this: v4);
  if ( v5 != nullptr )
  {
    renderData.m_pRenderContext = v4;
    memset(&renderData.m_pRenderData, 0, 9);
    CMatRenderData<memhandle_t__ *>::Lock(this: &renderData, nCount, pSrcData: pColorMeshHandles);
    pColorMeshHandles = renderData.m_pRenderData;
    ICallQueue::QueueCall<CModelRender *,CModelRender,void,int,memhandle_t__ * *,int,memhandle_t__ * *>(
      this: v5,
      pObject: this,
      pfnProxied: (void (__thiscall *__ptr64)(CModelRender *, int, memhandle_t__ **))(unsigned int)CModelRender::UnlockCacheCacheHandleArray,
      arg1: &nCount,
      arg2: &pColorMeshHandles);
    CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: (CMatRenderData<matrix3x4a_t> *)&renderData);
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
  else
  {
    for ( i = 0; i < nCount; ++i )
    {
      if ( pColorMeshHandles[i] != nullptr )
        this->m_pCache->Unlock(this: this->m_pCache, a2: pColorMeshHandles[i]);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0FB0
// Name: private: void CModelRender::ProtectColorDataIfQueued(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ProtectColorDataIfQueued(CModelRender *this, memhandle_t__ *hColorMesh)
{
  IMatRenderContext *v3; // esi
  ICallQueue *v4; // edi

  if ( hColorMesh != nullptr )
  {
    v3 = materials->GetRenderContext(this: materials);
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4 = v3->GetCallQueue(this: v3);
    if ( v4 != nullptr && this->m_pCache->Lock(this: this->m_pCache, a2: hColorMesh) != nullptr )
      ICallQueue::QueueCall<CModelRender *,CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,int,memhandle_t__ *,memhandle_t__ *>(
        this: v4,
        pObject: this,
        pfnProxied: (int (__thiscall *)(CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *> *, memhandle_t__ *))CLoaderMemAlloc::CrtSetReportMode,
        arg1: &hColorMesh);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1030
// Name: public: virtual void CModelRender::DestroyInstance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::DestroyInstance(CModelRender *this, int handle)
{
  unsigned __int16 v2; // bx
  int v4; // esi
  memhandle_t__ *m_ColorMeshHandle; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *handlea; // [esp+14h] [ebp+8h]

  v2 = handle;
  if ( (_WORD)handle != 0xFFFF )
  {
    v4 = (unsigned __int16)handle;
    g_pStudioRender->DestroyDecalList(
      this: g_pStudioRender,
      a2: this->m_ModelInstances.m_Memory.m_pMemory[v4].m_Element.m_DecalHandle);
    g_pShadowMgr->RemoveAllShadowsFromModel(this: g_pShadowMgr, a2: handle);
    m_ColorMeshHandle = this->m_ModelInstances.m_Memory.m_pMemory[v4].m_Element.m_ColorMeshHandle;
    if ( m_ColorMeshHandle != nullptr )
    {
      this->m_pCache->Remove(this: this->m_pCache, a2: m_ColorMeshHandle, a3: nullptr, a4: nullptr, a5: true);
      this->m_ModelInstances.m_Memory.m_pMemory[v4].m_Element.m_ColorMeshHandle = nullptr;
    }
    CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_ModelInstances,
      elem: handle);
    handlea = &this->m_ModelInstances.m_Memory.m_pMemory[v4];
    CUtlMemoryPool::Free(
      this: &CModelRender::ModelInstanceLightingState_t::s_Allocator,
      memBlock: handlea->m_Element.m_pLightingState);
    handlea->m_Next = this->m_ModelInstances.m_FirstFree;
    this->m_ModelInstances.m_FirstFree = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E10E0
// Name: private: virtual bool CResourcePreloadPropLighting::CreateResource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourcePreloadPropLighting::CreateResource(CResourcePreloadPropLighting *this, const char *pName)
{
  char szFilename[260]; // [esp+0h] [ebp-230h] BYREF
  char szBasename[260]; // [esp+104h] [ebp-12Ch] BYREF
  LoaderJob_t loaderJob; // [esp+208h] [ebp-28h] BYREF

  if ( r_proplightingfromdisk.m_pParent != nullptr && r_proplightingfromdisk.m_pParent->m_Value.m_nValue != 0 )
  {
    V_FileBase(in: pName, out: szBasename, maxlen: 260);
    V_snprintf(pDest: szFilename, maxLen: 260, pFormat: "%s%s.vhv", szBasename, defaultValue);
    g_pQueuedLoader->IsSameMapLoading(this: g_pQueuedLoader);
    loaderJob.m_pFilename = szFilename;
    memset(&loaderJob.m_pCallback, 0, 24);
    *(_DWORD *)&loaderJob.m_bPersistTargetData = 0;
    loaderJob.m_pPathID = "GAME";
    loaderJob.m_Priority = LOADERPRIORITY_DURINGPRELOAD;
    g_pQueuedLoader->AddJob(this: g_pQueuedLoader, a2: &loaderJob);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E11A0
// Name: public: virtual int CModelRender::DrawModelExStaticProp(class IMatRenderContext __near *,struct ModelRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::DrawModelExStaticProp(
        CModelRender *this,
        IMatRenderContext *pRenderContext,
        ModelRenderInfo_t *pInfo)
{
  ModelRenderInfo_t *v3; // esi
  studiohdr_t *(__thiscall *GetStudioHdr)(IMDLCache *, unsigned __int16); // edx
  int v6; // ebx
  bool v7; // zf
  IClientRenderable *pRenderable; // eax
  studiohwdata_t *v9; // eax
  int flags; // eax
  int instance; // edx
  int v13; // eax
  int m_nValue; // edi
  bool v15; // bl
  IDataCacheSection *m_pCache; // ecx
  IDataCacheSection_vtbl *v17; // edx
  int v18; // eax
  void *v19; // edi
  int v20; // eax
  LightCacheHandle_t__ **p_m_LightCacheHandle; // edi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v23; // eax
  int skin; // ecx
  int body; // edx
  int hitboxset; // eax
  int studio; // [esp-4h] [ebp-238h]
  DrawModelInfo_t info; // [esp+Ch] [ebp-228h] BYREF
  Vector entOrigin; // [esp+1ECh] [ebp-48h] BYREF
  DrawModelState_t state; // [esp+1F8h] [ebp-3Ch] BYREF
  int lod; // [esp+214h] [ebp-20h]
  StudioDecalHandle_t__ *decalHandle; // [esp+218h] [ebp-1Ch]
  BOOL bVertexLit; // [esp+21Ch] [ebp-18h]
  memhandle_t__ *hColorMeshData; // [esp+220h] [ebp-14h]
  ColorMeshInfo_t *pColorMeshes; // [esp+224h] [ebp-10h]
  BOOL bNeedsEnvCubemap; // [esp+228h] [ebp-Ch]
  CModelRender *v37; // [esp+22Ch] [ebp-8h]
  bool bShadowDepth; // [esp+233h] [ebp-1h]
  int drawFlags; // [esp+23Ch] [ebp+8h]

  v3 = pInfo;
  bShadowDepth = (pInfo->flags & 0x40000000) != 0;
  GetStudioHdr = g_pMDLCache->GetStudioHdr;
  studio = pInfo->pModel->studio;
  v37 = this;
  v6 = ((int (__stdcall *)(int))GetStudioHdr)(a1: studio);
  v7 = *(_DWORD *)(v6 + 232) == 0;
  pRenderable = v3->pRenderable;
  state.m_pStudioHdr = (studiohdr_t *)v6;
  state.m_pRenderable = pRenderable;
  if ( !v7 && !g_bTextMode )
  {
    v9 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: v3->pModel->studio);
    state.m_pStudioHWData = v9;
    if ( v9 != nullptr )
    {
      state.m_pModelToWorld = v3->pModelToWorld;
      lod = CModelRender::ComputeLOD(this, pRenderContext, info: v3, pStudioHWData: v9);
      flags = v3->flags;
      if ( (flags & 1) != 0 )
      {
        instance = v3->instance;
        decalHandle = nullptr;
        if ( (_WORD)instance != 0xFFFF && (flags & 0x40000000) == 0 )
          decalHandle = this->m_ModelInstances.m_Memory.m_pMemory[instance].m_Element.m_DecalHandle;
        drawFlags = 0;
        if ( (flags & 8) != 0 )
          drawFlags = (flags < 0) + 1;
        if ( (flags & 0x10) != 0 )
          drawFlags |= 8u;
        if ( (flags & 0x20) != 0 )
          drawFlags |= 0x80u;
        g_pShadowMgr->SetModelShadowState(this: g_pShadowMgr, a2: instance);
        v13 = v3->pModel->flags;
        if ( r_staticlight_streams.m_pParent != nullptr )
          m_nValue = r_staticlight_streams.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        v15 = (drawFlags & 8) != 0
           && (*(_BYTE *)(v6 + 152) & 0x10) != 0
           && ((v3->pModel->flags & 0x200) == 0 || m_nValue > 1)
           && v3->instance != 0xFFFF;
        LOBYTE(bVertexLit) = (v3->pModel->flags & 4) != 0;
        HIBYTE(pInfo) = v15;
        if ( r_showenvcubemap.m_pParent != nullptr && r_showenvcubemap.m_pParent->m_Value.m_nValue != 0
          || (LOBYTE(bNeedsEnvCubemap) = 0, (v13 & 0x400) != 0) )
        {
          LOBYTE(bNeedsEnvCubemap) = 1;
        }
        if ( r_drawmodellightorigin.m_pParent != nullptr && r_drawmodellightorigin.m_pParent->m_Value.m_nValue != 0 )
          CModelRender::DebugDrawLightingOrigin(this: v37, &state, pInfo: v3);
        pColorMeshes = nullptr;
        hColorMeshData = nullptr;
        if ( !v15 )
          goto LABEL_43;
        m_pCache = v37->m_pCache;
        v17 = m_pCache->__vftable;
        hColorMeshData = v37->m_ModelInstances.m_Memory.m_pMemory[v3->instance].m_Element.m_ColorMeshHandle;
        v18 = (int)v17->Get(this: m_pCache, a2: hColorMeshData, a3: true);
        v19 = (void *)v18;
        if ( v18 != 0 && (*(_BYTE *)(v18 + 20) & 2) == 0 )
          goto LABEL_39;
        if ( ((unsigned __int8 (__stdcall *)(_DWORD))v37->RecomputeStaticLighting)(a1: v3->instance) != 0 )
        {
          v19 = v37->m_pCache->Get(this: v37->m_pCache, a2: hColorMeshData, a3: 1);
          goto LABEL_39;
        }
        if ( v19 != nullptr && (*((_BYTE *)v19 + 20) & 2) != 0 )
        {
LABEL_39:
          if ( v19 != nullptr && (*((_BYTE *)v19 + 20) & 1) != 0 )
            pColorMeshes = *((ColorMeshInfo_t **)v19 + 1);
          else
            HIBYTE(pInfo) = 0;
LABEL_43:
          info.m_bStaticLighting = false;
          if ( (bVertexLit || bNeedsEnvCubemap) && !bShadowDepth )
          {
            v20 = v3->instance;
            p_m_LightCacheHandle = nullptr;
            if ( (_WORD)v20 == 0xFFFF
              || (m_pMemory = v37->m_ModelInstances.m_Memory.m_pMemory,
                  v7 = (m_pMemory[v20].m_Element.m_nFlags & 1) == 0,
                  v23 = &m_pMemory[v20],
                  v7)
              || v23->m_Element.m_LightCacheHandle == nullptr
              || (p_m_LightCacheHandle = &v23->m_Element.m_LightCacheHandle,
                  v23 == (UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *)-16) )
            {
              R_ComputeLightingOrigin(
                pRenderable: state.m_pRenderable,
                pStudioHdr: state.m_pStudioHdr,
                matrix: state.m_pModelToWorld,
                center: &entOrigin);
            }
            CModelRender::StudioSetupLighting(
              this: v37,
              &state,
              absEntCenter: &entOrigin,
              pLightcache: p_m_LightCacheHandle,
              bVertexLit,
              bNeedsEnvCubemap,
              bStaticLighting: (bool *)&pInfo + 3,
              drawInfo: &info,
              pInfo: v3,
              drawFlags);
          }
          info.m_pStudioHdr = state.m_pStudioHdr;
          skin = v3->skin;
          info.m_pHardwareData = state.m_pStudioHWData;
          body = v3->body;
          info.m_Decals = decalHandle;
          hitboxset = v3->hitboxset;
          info.m_Skin = skin;
          info.m_Body = body;
          info.m_HitboxSet = hitboxset;
          info.m_pClientEntity = (void *)state.m_pRenderable;
          info.m_Lod = lod;
          info.m_pColorMeshes = pColorMeshes;
          if ( bShadowDepth )
            drawFlags |= 0x200u;
          g_pStudioRender->DrawModelStaticProp(this: g_pStudioRender, a2: &info, a3: v3->pModelToWorld, a4: drawFlags);
          if ( pColorMeshes != nullptr )
            CModelRender::ProtectColorDataIfQueued(this: v37, hColorMesh: hColorMeshData);
          return 1;
        }
      }
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E1500
// Name: private: class CColorMeshData __near * CModelRender::FindOrCreateStaticPropColorData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
CColorMeshData *__thiscall CModelRender::FindOrCreateStaticPropColorData(CModelRender *this, unsigned __int16 handle)
{
  CColorMeshData *result; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v4; // esi
  studiohwdata_t *v5; // eax
  memhandle_t__ *v6; // eax
  colormeshparams_t params; // [esp+4h] [ebp-514h] BYREF
  char fn[260]; // [esp+414h] [ebp-104h] BYREF

  if ( handle == 0xFFFF )
    return nullptr;
  v4 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  result = (CColorMeshData *)this->m_pCache->Get(this: this->m_pCache, a2: v4->m_Element.m_ColorMeshHandle, a3: 1);
  if ( result == nullptr )
  {
    v5 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: v4->m_Element.m_pModel->studio);
    if ( v5 == nullptr )
    {
      g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)v4->m_Element.m_pModel, a3: fn, a4: 260);
      Sys_Error(error: "g_pMDLCache->GetHardwareData failed for %s\n", fn);
      return nullptr;
    }
    CModelRender::InitColormeshParams(this, instance: &v4->m_Element, pStudioHWData: v5, pColorMeshParams: (int)&params);
    if ( params.m_nMeshes <= 0 )
      return nullptr;
    params.m_fnHandle = v4->m_Element.m_pModel->fnHandle;
    v6 = CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CacheCreate(
           this: &this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,
           createParams: &params,
           flags: 0);
    v4->m_Element.m_ColorMeshHandle = v6;
    CModelRender::ProtectColorDataIfQueued(this, hColorMesh: v6);
    return (CColorMeshData *)this->m_pCache->Get(this: this->m_pCache, a2: v4->m_Element.m_ColorMeshHandle, a3: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1600
// Name: private: void CModelRender::ValidateStaticPropColorData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelRender::ValidateStaticPropColorData(
        CModelRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v4; // esi
  int v5; // edi
  IStaticPropMgrEngine *v6; // eax
  IStaticPropMgrEngine *v7; // eax
  IStaticPropMgrEngine *v8; // eax
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // edx
  int v10; // eax
  int m_nValue; // ecx
  char fileName[260]; // [esp+0h] [ebp-134h] BYREF
  CUtlBuffer utlBuf; // [esp+104h] [ebp-30h] BYREF

  if ( r_proplightingfromdisk.m_pParent != nullptr && r_proplightingfromdisk.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
    v5 = (int)v4->m_Element.m_pRenderable->GetIClientUnknown(this: v4->m_Element.m_pRenderable);
    v6 = StaticPropMgr();
    if ( v6->IsStaticProp_2(this: v6, a2: (IHandleEntity *)v5) && g_bLoadedMapHasBakedPropLighting )
    {
      CUtlBuffer::CUtlBuffer(this: &utlBuf, growSize: 0, initSize: 0, nFlags: 0);
      if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int, int))g_pMaterialSystemHardwareConfig->GetHDRType)(
             a1: g_pMaterialSystemHardwareConfig,
             a2,
             a3) == 0
        || g_bBakedPropLightingNoSeparateHDR )
      {
        v8 = StaticPropMgr();
        *(_DWORD *)&fileName[4] = ((int (__thiscall *)(IStaticPropMgrEngine *, int, const char *, _DWORD, _DWORD))v8->GetStaticPropIndex)(
                                    a1: v8,
                                    a2: v5,
                                    a3: defaultValue,
                                    a4: *(_DWORD *)fileName,
                                    a5: *(_DWORD *)&fileName[4]);
        V_snprintf(pDest: fileName, maxLen: 260, pFormat: "sp_%d%s.vhv");
      }
      else
      {
        v7 = StaticPropMgr();
        *(_DWORD *)&fileName[4] = ((int (__thiscall *)(IStaticPropMgrEngine *, int, const char *, _DWORD, _DWORD))v7->GetStaticPropIndex)(
                                    a1: v7,
                                    a2: v5,
                                    a3: defaultValue,
                                    a4: *(_DWORD *)fileName,
                                    a5: *(_DWORD *)&fileName[4]);
        V_snprintf(pDest: fileName, maxLen: 260, pFormat: "sp_hdr_%d%s.vhv");
      }
      ReadFile = g_pFileSystem->ReadFile;
      *(_DWORD *)&fileName[8] = 0;
      *(_DWORD *)&fileName[4] = 0;
      *(_DWORD *)fileName = 40;
      if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))ReadFile)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: fileName) != 0 )
      {
        v10 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v4->m_Element.m_pModel->studio);
        if ( r_staticlight_streams.m_pParent != nullptr )
          m_nValue = r_staticlight_streams.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( *(_DWORD *)utlBuf.m_Memory.m_pMemory == 2
          && *((_DWORD *)utlBuf.m_Memory.m_pMemory + 1) == *(_DWORD *)(v10 + 8)
          && *((_DWORD *)utlBuf.m_Memory.m_pMemory + 3) == 4 * m_nValue )
        {
          v4->m_Element.m_nFlags = v4->m_Element.m_nFlags & 0xFFF9 | 2;
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &utlBuf);
          return;
        }
        v4->m_Element.m_nFlags |= 4u;
      }
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &utlBuf);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1780
// Name: public: virtual unsigned short CModelRender::CreateInstance(class IClientRenderable __near *,struct LightCacheHandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CModelRender::CreateInstance(
        CModelRender *this,
        IClientRenderable *pRenderable,
        LightCacheHandle_t__ **pCache)
{
  unsigned __int16 v4; // ax
  int v5; // esi
  int v6; // ebx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v7; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v8; // esi
  _DWORD *p_m_flLightingTime; // eax
  _DWORD *v10; // eax
  model_t *pModel; // [esp+10h] [ebp-4h]

  pModel = (model_t *)pRenderable->GetModel(this: pRenderable);
  v4 = CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_ModelInstances,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = 0xFFFF;
  }
  else
  {
    CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_ModelInstances,
      before: 0xFFFFu,
      elem: v4);
    v7 = &this->m_ModelInstances.m_Memory.m_pMemory[v5];
    if ( v7 != nullptr )
      CModelRender::ModelInstance_t::ModelInstance_t(this: &v7->m_Element);
    v6 = v5;
  }
  v8 = &this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)v6];
  p_m_flLightingTime = (_DWORD *)&v8->m_Element.m_pLightingState->m_flLightingTime;
  v8->m_Element.m_pRenderable = pRenderable;
  v8->m_Element.m_DecalHandle = nullptr;
  v8->m_Element.m_pModel = pModel;
  v8->m_Element.m_ColorMeshHandle = nullptr;
  *p_m_flLightingTime = -915135504;
  v10 = (_DWORD *)&v8->m_Element.m_pLightingState->m_flLightingTime;
  v8->m_Element.m_LightCacheHandle = nullptr;
  v8->m_Element.m_nFlags = 0;
  v10[24] = 0;
  v10[27] = 0;
  v10[25] = 0;
  v10[26] = 0;
  v10[28] = 0;
  v10[29] = 0;
  v10[30] = 0;
  v10[31] = 0;
  v10[32] = 0;
  v10[33] = 0;
  v10[34] = 0;
  v10[35] = 0;
  v10[36] = 0;
  v10[37] = 0;
  v10[38] = 0;
  v10[39] = 0;
  v10[40] = 0;
  v10[41] = 0;
  v10[42] = 0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[0].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[1].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[2].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[3].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[4].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[5].x = 1.0;
  v8->m_Element.m_FirstShadow = g_pShadowMgr->InvalidShadowIndex(this: g_pShadowMgr);
  if ( pCache != nullptr )
  {
    this->SetStaticLighting(this, a2: v6, a3: pCache);
    CModelRender::ValidateStaticPropColorData(this, handle: v6);
    this->RecomputeStaticLighting(this, a2: v6);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E19B0
// Name: public: CModelRender::CModelRender(void)
// Source: json
//------------------------------------------------------------------------------
CModelRender *__thiscall CModelRender::CModelRender(CModelRender *this)
{
  this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)&CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::`vftable';
  this->m_pCache = nullptr;
  this->IVModelRender::__vftable = (CModelRender_vtbl *)&CModelRender::`vftable'{for `IVModelRender'};
  this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)&CModelRender::`vftable'{for `CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>'};
  this->m_ModelInstances.m_Memory.m_pMemory = nullptr;
  this->m_ModelInstances.m_Memory.m_nAllocationCount = 0;
  this->m_ModelInstances.m_Memory.m_nGrowSize = 0;
  this->m_ModelInstances.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_ModelInstances.m_FirstFree = 0xFFFF;
  this->m_ModelInstances.m_pElements = this->m_ModelInstances.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_ModelInstances.m_Head = -1;
  this->m_ModelInstances.m_NumAlloced = 0;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Root = -1;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_NumElements = 0;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_pElements = this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_CachedStaticPropMutex.m_ownerID = 0;
  this->m_CachedStaticPropMutex.m_depth = 0;
  this->m_colorMeshVBAllocator.__vftable = (CPooledVBAllocator_ColorMesh_vtbl *)&CPooledVBAllocator_ColorMesh::`vftable';
  this->m_colorMeshVBAllocator.m_pMesh = nullptr;
  CPooledVBAllocator_ColorMesh::Clear(this: &this->m_colorMeshVBAllocator);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E1A50
// Name: public: virtual CModelRender::~CModelRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::~CModelRender(CModelRender *this)
{
  bool v2; // zf
  IDataCacheSection *m_pCache; // esi
  IDataCache *v4; // ebx
  int v5; // eax
  IDataCache_vtbl *v6; // [esp+8h] [ebp-4h]

  v2 = this->m_colorMeshVBAllocator.m_pMesh == nullptr;
  this->m_colorMeshVBAllocator.__vftable = (CPooledVBAllocator_ColorMesh_vtbl *)&CPooledVBAllocator_ColorMesh::`vftable';
  if ( v2 )
  {
    if ( this->m_colorMeshVBAllocator.m_numAllocations > 0 )
      _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh has unfreed allocations!");
  }
  else
  {
    _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh's internal mesh (vertex buffer) should have been freed!\n");
  }
  CPooledVBAllocator_ColorMesh::Clear(this: &this->m_colorMeshVBAllocator);
  this->m_colorMeshVBAllocator.__vftable = (CPooledVBAllocator_ColorMesh_vtbl *)&IPooledVBAllocator::`vftable';
  CUtlDict<memhandle_t__ *,int>::RemoveAll(this: &this->m_CachedStaticPropColorData);
  CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>(this: &this->m_CachedStaticPropColorData.m_Elements.m_Tree);
  CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_ModelInstances);
  if ( this->m_ModelInstances.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ModelInstances.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ModelInstances.m_Memory.m_pMemory);
      this->m_ModelInstances.m_Memory.m_pMemory = nullptr;
    }
    this->m_ModelInstances.m_Memory.m_nAllocationCount = 0;
  }
  m_pCache = this->m_pCache;
  this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)&CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::`vftable';
  if ( m_pCache != nullptr )
  {
    v4 = m_pCache->GetSharedCache(this: m_pCache);
    v6 = v4->__vftable;
    v5 = ((int (__thiscall *)(IDataCacheSection *, int))m_pCache->GetName)(a1: m_pCache, a2: 1);
    ((void (__thiscall *)(IDataCache *, int))v6->RemoveSection)(a1: v4, a2: v5);
    this->m_pCache = nullptr;
  }
  this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)&IDataCacheClient::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100E1B50
// Name: private: virtual void CResourcePreloadPropLighting::PurgeUnreferencedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadPropLighting::PurgeUnreferencedResources(CResourcePreloadPropLighting *this)
{
  g_pQueuedLoader->IsSameMapLoading(this: g_pQueuedLoader);
}

//------------------------------------------------------------------------------
// Address: 0x100E1B60
// Name: public: virtual void CModelRender::ReleaseAllStaticPropColorData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ReleaseAllStaticPropColorData(CModelRender *this)
{
  int i; // ebx
  int v3; // esi
  memhandle_t__ *m_ColorMeshHandle; // eax

  for ( i = this->m_ModelInstances.m_Head;
        i != 0xFFFF;
        i = this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)i].m_Next )
  {
    v3 = (unsigned __int16)i;
    m_ColorMeshHandle = this->m_ModelInstances.m_Memory.m_pMemory[v3].m_Element.m_ColorMeshHandle;
    if ( m_ColorMeshHandle != nullptr )
    {
      this->m_pCache->Remove(this: this->m_pCache, a2: m_ColorMeshHandle, a3: nullptr, a4: nullptr, a5: true);
      this->m_ModelInstances.m_Memory.m_pMemory[v3].m_Element.m_ColorMeshHandle = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1C40
// Name: public: struct DrawModelResults_t __near & DrawModelResults_t::operator=(struct DrawModelResults_t const __near &)
// Source: json
//------------------------------------------------------------------------------
DrawModelResults_t *__thiscall DrawModelResults_t::operator=(
        DrawModelResults_t *this,
        const DrawModelResults_t *__that)
{
  DrawModelResults_t *result; // eax
  int m_Size; // edx
  CUtlVectorFixed<IMaterial *,8> *p_m_Materials; // ecx
  int v5; // esi

  result = this;
  this->m_ActualTriCount = __that->m_ActualTriCount;
  this->m_TextureMemoryBytes = __that->m_TextureMemoryBytes;
  this->m_NumHardwareBones = __that->m_NumHardwareBones;
  this->m_NumBatches = __that->m_NumBatches;
  this->m_NumMaterials = __that->m_NumMaterials;
  this->m_nLODUsed = __that->m_nLODUsed;
  this->m_flLODMetric = __that->m_flLODMetric;
  this->m_RenderTime.m_Duration.m_Int64 = __that->m_RenderTime.m_Duration.m_Int64;
  m_Size = __that->m_Materials.m_Size;
  p_m_Materials = &this->m_Materials;
  p_m_Materials->m_Size = 0;
  if ( m_Size != 0 )
  {
    p_m_Materials->m_Size = m_Size;
    p_m_Materials->m_pElements = (IMaterial **)p_m_Materials;
    if ( m_Size > 0 )
    {
      v5 = (char *)&__that->m_Materials - (char *)p_m_Materials;
      do
      {
        *(_DWORD *)p_m_Materials->m_Memory.m_Memory = *(_DWORD *)&p_m_Materials->m_Memory.m_Memory[v5];
        p_m_Materials = (CUtlVectorFixed<IMaterial *,8> *)((char *)p_m_Materials + 4);
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1CC0
// Name: void DrawSavedModelDebugOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSavedModelDebugOverlays()
{
  int m_Size; // ebx
  float m_fValue; // xmm4_4
  float v2; // xmm2_4
  int v3; // edi
  float v4; // xmm1_4
  int v5; // esi
  unsigned int m_Int64_high; // eax
  int v7; // ecx
  int v8; // edx
  CUtlVectorFixed<IMaterial *,8> *p_m_Materials; // eax
  unsigned int m_Int64; // [esp+Ch] [ebp-20h]
  float v11; // [esp+14h] [ebp-18h]
  float v12; // [esp+18h] [ebp-14h]
  float v13; // [esp+1Ch] [ebp-10h]
  float v14; // [esp+20h] [ebp-Ch]
  float v15; // [esp+24h] [ebp-8h]
  float max; // [esp+28h] [ebp-4h]
  float ooRange; // [esp+2Ch] [ebp+0h] BYREF

  m_Size = s_SavedModelInfo.m_Size;
  if ( s_SavedModelInfo.m_Size != 0 )
  {
    m_fValue = r_drawmodelstatsoverlaymax.m_pParent->m_Value.m_fValue;
    v2 = r_drawmodelstatsoverlaymin.m_pParent->m_Value.m_fValue;
    v3 = 0;
    v4 = 1.0 / (float)(m_fValue - v2);
    v14 = v2;
    v11 = m_fValue;
    v12 = v4;
    if ( s_SavedModelInfo.m_Size > 0 )
    {
      v5 = 0;
      do
      {
        m_Int64_high = HIDWORD(s_SavedModelInfo.m_Memory.m_pMemory[v5].m_ModelResults.m_RenderTime.m_Duration.m_Int64);
        m_Int64 = s_SavedModelInfo.m_Memory.m_pMemory[v5].m_ModelResults.m_RenderTime.m_Duration.m_Int64;
        if ( (double)__PAIR64__(m_Int64_high, m_Int64) * _g_ClockSpeedMillisecondsMultiplier > v14 )
        {
          v13 = (double)__PAIR64__(m_Int64_high, m_Int64) * _g_ClockSpeedMillisecondsMultiplier;
          if ( v13 < m_fValue )
          {
            v15 = (float)(v13 - v2) * v4;
            max = 1.0 - v15;
          }
          else
          {
            v15 = 1.0;
            max = 0.0;
          }
          DrawModelDebugOverlay(
            a1: (int)&ooRange,
            info: &s_SavedModelInfo.m_Memory.m_pMemory[v5].m_ModelInfo,
            results: &s_SavedModelInfo.m_Memory.m_pMemory[v5].m_ModelResults,
            origin: &s_SavedModelInfo.m_Memory.m_pMemory[v5].m_Origin,
            r: v15,
            g: max,
            b: 0.0);
          m_Size = s_SavedModelInfo.m_Size;
          v2 = v14;
          v4 = v12;
          m_fValue = v11;
        }
        ++v3;
        ++v5;
      }
      while ( v3 < m_Size );
    }
    v7 = m_Size - 1;
    if ( m_Size - 1 >= 0 )
    {
      v8 = v7;
      do
      {
        p_m_Materials = &s_SavedModelInfo.m_Memory.m_pMemory[v8--].m_ModelResults.m_Materials;
        --v7;
        p_m_Materials->m_Size = 0;
        p_m_Materials->m_pElements = (IMaterial **)p_m_Materials;
      }
      while ( v7 >= 0 );
    }
    s_SavedModelInfo.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1E40
// Name: public: void CModelRender::StaticPropColorMeshCallback(void __near *,void const __near *,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::StaticPropColorMeshCallback(
        CModelRender *this,
        memhandle_t__ **pContext,
        _DWORD *pData,
        int numReadBytes,
        FSAsyncStatus_t asyncStatus)
{
  int v5; // edi
  int v7; // edx
  int v8; // eax
  memhandle_t__ **v9; // ecx
  _DWORD *v10; // esi
  int v11; // eax
  int meshID; // [esp+8h] [ebp-4h]
  int numLightingComponents; // [esp+18h] [ebp+Ch]
  FSAsyncStatus_t asyncStatusa; // [esp+20h] [ebp+14h]

  v5 = 0;
  if ( asyncStatus == FSASYNC_OK )
  {
    v7 = pData[5];
    v8 = 0;
    if ( v7 > 0 )
    {
      v9 = (memhandle_t__ **)(pData + 10);
      do
      {
        if ( *v9 == pContext[3] )
          break;
        ++v8;
        v9 += 7;
      }
      while ( v8 < v7 );
    }
    if ( r_staticlight_streams.m_pParent != nullptr )
      numLightingComponents = r_staticlight_streams.m_pParent->m_Value.m_nValue;
    else
      numLightingComponents = 0;
    meshID = v8;
    if ( v8 < v7 )
    {
      asyncStatusa = FSASYNC_OK;
      v10 = &pData[7 * v8 + 12];
      do
      {
        v11 = *(v10 - 1);
        if ( v11 != *(_DWORD *)(*((_DWORD *)pContext[1] + 1) + asyncStatusa + 12) )
          break;
        _V_memcpy(
          dest: *(void **)(*((_DWORD *)pContext[1] + 2) + v5),
          src: (char *)pData + *v10,
          count: 4 * numLightingComponents * v11);
        asyncStatusa += 16;
        v5 += 4;
        v10 += 7;
        ++meshID;
      }
      while ( meshID < pData[5] );
    }
  }
  *((_DWORD *)pContext[1] + 5) |= 1u;
  this->m_pCache->Unlock(this: this->m_pCache, a2: *pContext);
  free(pMem: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x100E1F30
// Name: StaticPropColorMeshCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl StaticPropColorMeshCallback(
        const FileAsyncRequest_t *request,
        int numReadBytes,
        FSAsyncStatus_t asyncStatus)
{
  CModelRender::StaticPropColorMeshCallback(
    this: &s_ModelRender,
    pContext: (memhandle_t__ **)request->pContext,
    pData: (_DWORD *)request->pData,
    numReadBytes,
    asyncStatus);
}

//------------------------------------------------------------------------------
// Address: 0x100E1F70
// Name: private: bool CModelRender::LoadStaticPropColorData(class IHandleEntity __near *,struct memhandle_t__ __near *,struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CModelRender::LoadStaticPropColorData@<al>(
        CModelRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        IHandleEntity *pProp,
        memhandle_t__ *colorMeshHandle,
        studiohwdata_t *pStudioHWData)
{
  _DWORD *v6; // edi
  IStaticPropMgrEngine *v8; // eax
  IStaticPropMgrEngine *v9; // eax
  void *v10; // esi
  int v12; // [esp-4h] [ebp-140h]
  int v13; // [esp-4h] [ebp-140h]
  char fileName[260]; // [esp+4h] [ebp-138h] BYREF
  FileAsyncRequest_t fileRequest; // [esp+108h] [ebp-34h] BYREF
  CModelRender *v16; // [esp+134h] [ebp-8h]
  FSAsyncControl_t__ **v17; // [esp+138h] [ebp-4h]

  v16 = this;
  if ( !g_bLoadedMapHasBakedPropLighting
    || r_proplightingfromdisk.m_pParent == nullptr
    || r_proplightingfromdisk.m_pParent->m_Value.m_nValue == 0 )
  {
    return 0;
  }
  v6 = this->m_pCache->Lock(this: this->m_pCache, a2: colorMeshHandle);
  if ( v6 == nullptr )
    return 0;
  v17 = (FSAsyncControl_t__ **)(v6 + 4);
  if ( v6[4] != 0 )
  {
    v16->m_pCache->Unlock(this: v16->m_pCache, a2: colorMeshHandle);
    return 1;
  }
  else
  {
    if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int, int))g_pMaterialSystemHardwareConfig->GetHDRType)(
           a1: g_pMaterialSystemHardwareConfig,
           a2,
           a3) == 0
      || g_bBakedPropLightingNoSeparateHDR )
    {
      v9 = StaticPropMgr();
      v13 = ((int (__thiscall *)(IStaticPropMgrEngine *, IHandleEntity *, const char *))v9->GetStaticPropIndex)(
              a1: v9,
              a2: pProp,
              a3: defaultValue);
      V_snprintf(pDest: fileName, maxLen: 260, pFormat: "sp_%d%s.vhv", v13);
    }
    else
    {
      v8 = StaticPropMgr();
      v12 = ((int (__thiscall *)(IStaticPropMgrEngine *, IHandleEntity *, const char *))v8->GetStaticPropIndex)(
              a1: v8,
              a2: pProp,
              a3: defaultValue);
      V_snprintf(pDest: fileName, maxLen: 260, pFormat: "sp_hdr_%d%s.vhv", v12);
    }
    v6[5] &= ~1u;
    v10 = MemAlloc_Alloc(nSize: 0x114u);
    *((_DWORD *)v10 + 3) = pStudioHWData->m_RootLOD;
    *((_DWORD *)v10 + 2) = *v6;
    *(_DWORD *)v10 = colorMeshHandle;
    *((_DWORD *)v10 + 1) = v6;
    V_strncpy(pDest: (char *)v10 + 16, pSrc: fileName, maxLen: 260);
    memset(dst: (unsigned __int8 *)&fileRequest, value: 0, count: sizeof(fileRequest));
    fileRequest.pszFilename = fileName;
    fileRequest.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
    fileRequest.pContext = v10;
    fileRequest.pfnCallback = StaticPropColorMeshCallback;
    memset(&fileRequest.pData, 0, 12);
    fileRequest.flags = 0;
    fileRequest.priority = -1;
    fileRequest.pszPathID = "GAME";
    g_pFileSystem->AsyncReadMultiple(this: g_pFileSystem, a2: &fileRequest, a3: 1, a4: v17);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2100
// Name: private: bool CModelRender::UpdateStaticPropColorData(class IHandleEntity __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __thiscall CModelRender::UpdateStaticPropColorData(CModelRender *this, IHandleEntity *pProp, int handle)
{
  IMDLCache *v3; // esi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  IUniformRandomStream *v6; // ecx
  int v8; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v9; // esi
  unsigned __int16 m_nFlags; // ax
  int v11; // eax
  int studio; // edx
  studiohwdata_t *v13; // eax
  bool v14; // zf
  IClientRenderable *m_pRenderable; // edi
  const QAngle *v16; // eax
  LightCacheHandle_t__ *m_LightCacheHandle; // eax
  const LightingState_t *Static; // eax
  int v19; // ecx
  float x; // edx
  char *v21; // eax
  int numlights; // eax
  dworldlight_t *v23; // esi
  float linear_attn; // eax
  void *v25; // eax
  int v26; // edi
  _BYTE *v27; // eax
  char v28; // dl
  char v29; // cl
  int v30; // ecx
  mstudiomodel_t *v31; // edx
  int v32; // eax
  char *p_y; // eax
  studiomeshdata_t *v34; // eax
  int m_NumGroup; // edx
  int *v36; // eax
  char *v37; // esi
  int v38; // edi
  int v39; // edi
  int i; // edi
  char *v41; // eax
  int m_nVertexCount; // eax
  int v43; // edx
  int v44; // eax
  const Vector *v45; // [esp+4h] [ebp-2F0h]
  unsigned int v46; // [esp+8h] [ebp-2ECh]
  matrix3x4_t matrix; // [esp+20h] [ebp-2D4h] BYREF
  CMeshBuilder v48; // [esp+50h] [ebp-2A4h] BYREF
  _BYTE v49[20]; // [esp+238h] [ebp-BCh] BYREF
  LightingState_t lightingState; // [esp+24Ch] [ebp-A8h] BYREF
  mstudiobodyparts_t *pBodyPart; // [esp+2A8h] [ebp-4Ch]
  mstudiomodel_t *pModel; // [esp+2ACh] [ebp-48h]
  CModelRender *v53; // [esp+2B0h] [ebp-44h]
  BOOL flConstDirLightingAmount; // [esp+2B4h] [ebp-40h]
  int v55; // [esp+2B8h] [ebp-3Ch]
  studiomeshdata_t *pStudioMeshData; // [esp+2BCh] [ebp-38h]
  int lodID; // [esp+2C0h] [ebp-34h]
  int stripGroupID; // [esp+2C4h] [ebp-30h]
  int bUseConstDirLighting; // [esp+2C8h] [ebp-2Ch]
  int v60; // [esp+2CCh] [ebp-28h]
  mstudiomesh_t *pMesh; // [esp+2D0h] [ebp-24h]
  int bodyPartID; // [esp+2D4h] [ebp-20h]
  int modelID; // [esp+2D8h] [ebp-1Ch]
  int meshID; // [esp+2DCh] [ebp-18h]
  Vector vec; // [esp+2E0h] [ebp-14h] BYREF
  studiohwdata_t *pStudioHWData; // [esp+2ECh] [ebp-8h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+2F0h] [ebp-4h]

  v3 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  lightingState.locallight[1] = (dworldlight_t *)this;
  meshID = (int)g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  bodyPartID = (int)CModelRender::FindOrCreateStaticPropColorData(this, handle);
  if ( bodyPartID != 0 )
  {
    HIBYTE(cacheCriticalSection.m_pCache) = 0;
    if ( r_debugrandomstaticlighting.m_pParent != nullptr
      && r_debugrandomstaticlighting.m_pParent->m_Value.m_nValue != 0 )
    {
      v8 = _RandomInt(this: v6, a2: 1, a3: 6);
      vec.x = (float)((v8 >> 2) & 1);
      vec.y = (float)((v8 >> 1) & 1);
      vec.z = (float)(v8 & 1);
      VectorNormalize(&vec);
      LOBYTE(pStudioHWData) = (int)(float)(vec.x * 255.0);
      BYTE1(pStudioHWData) = (int)(float)(vec.y * 255.0);
      BYTE2(pStudioHWData) = (int)(float)(vec.z * 255.0);
      HIBYTE(cacheCriticalSection.m_pCache) = 1;
    }
    v9 = &this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)handle];
    if ( r_proplightingfromdisk.m_pParent != nullptr && r_proplightingfromdisk.m_pParent->m_Value.m_nValue == 2 )
    {
      m_nFlags = v9->m_Element.m_nFlags;
      if ( (m_nFlags & 4) != 0 )
      {
        LOWORD(pStudioHWData) = 255;
      }
      else
      {
        LOWORD(pStudioHWData) = -256;
        if ( (m_nFlags & 2) == 0 )
          LOWORD(pStudioHWData) = -1;
      }
      BYTE2(pStudioHWData) = 0;
      HIBYTE(cacheCriticalSection.m_pCache) = 1;
    }
    v11 = ((int (__cdecl *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v9->m_Element.m_pModel->studio);
    studio = v9->m_Element.m_pModel->studio;
    handle = v11;
    v13 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: studio);
    v14 = (v9->m_Element.m_nFlags & 1) == 0;
    modelID = (int)v13;
    if ( !v14
      && v9->m_Element.m_LightCacheHandle != nullptr
      && !modelinfo->UsesStaticLighting(this: modelinfo, a2: v9->m_Element.m_pModel) )
    {
      LightcacheGetStatic(cache: v9->m_Element.m_LightCacheHandle, pEnvCubemapTexture: nullptr, flags: 7u);
    }
    if ( HIBYTE(cacheCriticalSection.m_pCache) == 0
      && (v9->m_Element.m_nFlags & 2) != 0
      && CModelRender::LoadStaticPropColorData(
           this,
           a2: (int)this,
           a3: (int)v9,
           pProp,
           colorMeshHandle: v9->m_Element.m_ColorMeshHandle,
           pStudioHWData: (studiohwdata_t *)modelID) != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)meshID + 124))(a1: meshID);
      return 1;
    }
    else
    {
      *(_DWORD *)(bodyPartID + 20) = *(_DWORD *)(bodyPartID + 20) & 0xFFFFFFFC | 2;
      if ( HIBYTE(cacheCriticalSection.m_pCache) != 0
        || ((int (__cdecl *)(_DWORD))g_pMDLCache->GetVertexData)(a1: *(unsigned __int16 *)(handle + 344)) != 0 )
      {
        v9->m_Element.m_nFlags |= 8u;
        this->m_pStudioHdr = (studiohdr_t *)handle;
        m_pRenderable = v9->m_Element.m_pRenderable;
        v45 = v9->m_Element.m_pRenderable->GetRenderOrigin(this: v9->m_Element.m_pRenderable);
        v16 = m_pRenderable->GetRenderAngles(this: m_pRenderable);
        AngleMatrix(angles: v16, position: v45, &matrix);
        memset(v49, 0, sizeof(v49));
        memset(&lightingState, 0, 56);
        if ( (v9->m_Element.m_nFlags & 1) != 0 && (m_LightCacheHandle = v9->m_Element.m_LightCacheHandle) != nullptr )
        {
          Static = LightcacheGetStatic(cache: m_LightCacheHandle, pEnvCubemapTexture: nullptr, flags: 1u);
          LightingState_t::operator=(this: (LightingState_t *)v49, __that: Static);
        }
        else
        {
          R_ComputeLightingOrigin(
            pRenderable: v9->m_Element.m_pRenderable,
            pStudioHdr: (studiohdr_t *)handle,
            &matrix,
            center: &vec);
          LightcacheGetDynamic(
            origin: &vec,
            lightingState: (LightingState_t *)v49,
            stats: (LightcacheGetDynamic_Stats *)&pProp,
            pRenderable: v9->m_Element.m_pRenderable,
            flags: 1u,
            bDebugModel: false);
        }
        v19 = handle;
        v14 = (*(_DWORD *)(handle + 152) & 0x2000) == 0;
        LOBYTE(flConstDirLightingAmount) = 0;
        lightingState.locallight[2] = nullptr;
        if ( !v14 )
        {
          pProp = (IHandleEntity *)*(unsigned __int8 *)(handle + 376);
          LOBYTE(flConstDirLightingAmount) = 1;
          *(float *)&lightingState.locallight[2] = (double)(int)pProp * 0.00392156862745098;
        }
        x = 0.0;
        vec.x = 0.0;
        vec.y = 0.0;
        lodID = 0;
        if ( *(int *)(handle + 232) <= 0 )
        {
LABEL_70:
          *(_DWORD *)(bodyPartID + 20) = *(_DWORD *)(bodyPartID + 20) & 0xFFFFFFFC | 1;
          if ( x != 0.0 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(x));
          (*(void (__thiscall **)(int))(*(_DWORD *)meshID + 124))(a1: meshID);
          return 1;
        }
        else
        {
          pMesh = nullptr;
          while ( 1 )
          {
            v21 = (char *)pMesh + *(_DWORD *)(v19 + 236);
            stripGroupID = 0;
            numlights = (int)&v21[v19];
            lightingState.numlights = numlights;
            if ( *(int *)(numlights + 4) > 0 )
              break;
LABEL_69:
            pMesh = (mstudiomesh_t *)((char *)pMesh + 16);
            if ( ++lodID >= *(_DWORD *)(v19 + 232) )
              goto LABEL_70;
          }
          v60 = 0;
          while ( 1 )
          {
            v23 = (dworldlight_t *)(numlights + v60 + *(_DWORD *)(numlights + 12));
            linear_attn = v23->linear_attn;
            lightingState.locallight[0] = v23;
            if ( SLODWORD(vec.y) < SLODWORD(linear_attn) )
            {
              vec.y = linear_attn;
              v46 = 3 * LODWORD(linear_attn);
              if ( x == 0.0 )
                v25 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v46);
              else
                v25 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: LODWORD(x), a3: v46);
              LODWORD(vec.x) = v25;
            }
            if ( HIBYTE(cacheCriticalSection.m_pCache) != 0 )
            {
              v26 = 0;
              if ( SLODWORD(v23->linear_attn) > 0 )
              {
                v27 = (_BYTE *)(LODWORD(vec.x) + 2);
                do
                {
                  v28 = BYTE1(pStudioHWData);
                  *(v27 - 2) = (_BYTE)pStudioHWData;
                  v29 = BYTE2(pStudioHWData);
                  *(v27 - 1) = v28;
                  *v27 = v29;
                  ++v26;
                  v27 += 3;
                }
                while ( v26 < SLODWORD(v23->linear_attn) );
              }
            }
            else
            {
              CModelRender::ComputeModelVertexLightingOld(
                this: (CModelRender *)lightingState.locallight[1],
                pModel: (mstudiomodel_t *)v23,
                &matrix,
                lightingState: (mstudiomodel_t *)v49,
                pLighting: (matrix3x4_t *)LODWORD(vec.x),
                bUseConstDirLighting: flConstDirLightingAmount,
                flConstDirLightAmount: *(float *)&lightingState.locallight[2]);
            }
            v30 = modelID;
            v31 = *(mstudiomodel_t **)modelID;
            pModel = v31;
            if ( (int)v31 < *(_DWORD *)(modelID + 4) )
              break;
LABEL_67:
            numlights = lightingState.numlights;
            v60 += 148;
            x = vec.x;
            if ( ++stripGroupID >= *(_DWORD *)(lightingState.numlights + 4) )
            {
              v19 = handle;
              goto LABEL_69;
            }
          }
          v32 = 32 * (_DWORD)v31;
          v55 = 32 * (_DWORD)v31;
          while ( 1 )
          {
            pBodyPart = *(mstudiobodyparts_t **)(v32 + *(_DWORD *)(v30 + 8));
            bUseConstDirLighting = 0;
            if ( SLODWORD(v23->radius) > 0 )
              break;
LABEL_66:
            v31 = (mstudiomodel_t *)((char *)v31 + 1);
            v32 += 32;
            pModel = v31;
            v55 = v32;
            if ( (int)v31 >= *(_DWORD *)(v30 + 4) )
              goto LABEL_67;
          }
          p_y = nullptr;
          lightingState.locallight[3] = nullptr;
          while ( 1 )
          {
            v34 = (studiomeshdata_t *)&p_y[(_DWORD)v23 + LODWORD(v23->constant_attn)];
            v53 = nullptr;
            m_NumGroup = v34[4].m_NumGroup;
            pStudioMeshData = v34;
            v36 = &pBodyPart->sznameindex + 2 * m_NumGroup;
            if ( *v36 > 0 )
              break;
LABEL_64:
            p_y = (char *)&lightingState.locallight[3][1].intensity.y;
            ++bUseConstDirLighting;
            lightingState.locallight[3] = (dworldlight_t *)((char *)lightingState.locallight[3] + 116);
            if ( bUseConstDirLighting >= SLODWORD(v23->radius) )
            {
              v32 = v55;
              v31 = pModel;
              goto LABEL_66;
            }
          }
          pProp = nullptr;
          while ( 1 )
          {
            v37 = (char *)pProp + v36[1];
            v38 = *((__int16 *)v37 + 19);
            v48.m_pMesh = nullptr;
            v48.m_bGenerateIndices = false;
            memset(&v48.m_IndexBuilder.m_pIndexBuffer, 0, 12);
            v48.m_IndexBuilder.m_nCurrentIndex = 0;
            v48.m_IndexBuilder.m_nTotalIndexCount = 0;
            v48.m_IndexBuilder.m_nBufferOffset = -1;
            v48.m_IndexBuilder.m_nBufferFirstIndex = 0;
            v48.m_VertexBuilder.m_pVertexBuffer = nullptr;
            v48.m_VertexBuilder.m_nBufferOffset = -1;
            v48.m_VertexBuilder.m_nBufferFirstVertex = 0;
            memset(&v48.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
            v48.m_VertexBuilder.m_nTotalVertexCount = 0;
            v48.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v39 = *(_DWORD *)(bodyPartID + 4) + 16 * v38;
            CMeshBuilder::Begin(
              this: &v48,
              pMesh: *(IMesh **)v39,
              type: MATERIAL_HETEROGENOUS,
              nVertexCount: *((_DWORD *)v37 + 5),
              nIndexCount: 0,
              pMeshSettings: nullptr);
            if ( v48.m_ActualVertexSize == 0 )
              break;
            CVertexBuilder::AdvanceVertices(
              this: &v48.m_VertexBuilder,
              nVerts: *(_DWORD *)(v39 + 8) / v48.m_ActualVertexSize);
            for ( i = 0; i < *((_DWORD *)v37 + 5); ++i )
            {
              v41 = (char *)pStudioMeshData[1].m_pMeshGroup + *(unsigned __int16 *)(*((_DWORD *)v37 + 4) + 2 * i);
              *(_DWORD *)&v48.m_VertexBuilder.m_pSpecular[v48.m_VertexBuilder.m_nCurrentVertex
                                                        * v48.m_VertexBuilder.m_VertexSize_Specular] = (unsigned __int8)v41[2 * (_DWORD)v41 + 2 + LODWORD(vec.x)] | (((unsigned __int8)v41[2 * (_DWORD)v41 + 1 + LODWORD(vec.x)] | (((unsigned __int8)v41[2 * (_DWORD)v41 + LODWORD(vec.x)] | 0xFFFFFF00) << 8)) << 8);
              CVertexBuilder::AdvanceVertex(this: &v48.m_VertexBuilder);
            }
            if ( v48.m_bGenerateIndices )
            {
              switch ( v48.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  m_nVertexCount = 2 * v48.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  m_nVertexCount = 2 * v48.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  m_nVertexCount = 3 * v48.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  m_nVertexCount = 6 * v48.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  m_nVertexCount = 0;
                  break;
                default:
                  m_nVertexCount = v48.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(
                this: &v48.m_IndexBuilder,
                primitiveType: v48.m_Type,
                nIndexCount: m_nVertexCount);
            }
            v48.m_pMesh->UnlockMesh(
              this: v48.m_pMesh,
              a2: v48.m_VertexBuilder.m_nVertexCount,
              a3: v48.m_IndexBuilder.m_nIndexCount,
              a4: &v48);
            v43 = pStudioMeshData[4].m_NumGroup;
            pProp += 11;
            v36 = &pBodyPart->sznameindex + 2 * v43;
            v53 = (CModelRender *)((char *)v53 + 1);
            if ( (int)v53 >= *v36 )
            {
              v23 = lightingState.locallight[0];
              v30 = modelID;
              goto LABEL_64;
            }
          }
          if ( v48.m_bGenerateIndices )
          {
            switch ( v48.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                v44 = 2 * v48.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                v44 = 2 * v48.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                v44 = 3 * v48.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                v44 = 6 * v48.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                v44 = 0;
                break;
              default:
                v44 = v48.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(this: &v48.m_IndexBuilder, primitiveType: v48.m_Type, nIndexCount: v44);
          }
          v48.m_pMesh->UnlockMesh(
            this: v48.m_pMesh,
            a2: v48.m_VertexBuilder.m_nVertexCount,
            a3: v48.m_IndexBuilder.m_nIndexCount,
            a4: &v48);
          v48.m_IndexBuilder.m_pIndexBuffer = nullptr;
          v48.m_IndexBuilder.m_nMaxIndexCount = 0;
          v48.m_VertexBuilder.m_nMaxVertexCount = 0;
          v48.m_VertexBuilder.m_pVertexBuffer = nullptr;
          v48.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          v48.m_pMesh = nullptr;
          if ( LODWORD(vec.x) != 0 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(vec.x));
          (*(void (__thiscall **)(int))(*(_DWORD *)meshID + 124))(a1: meshID);
          return 0;
        }
      }
      else
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)meshID + 124))(a1: meshID);
        return 0;
      }
    }
  }
  else
  {
    v3->EndLock(this: v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2920
// Name: public: virtual void CModelRender::RestoreAllStaticPropColorData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::RestoreAllStaticPropColorData(CModelRender *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // ecx
  int v4; // esi
  IHandleEntity *v5; // eax
  unsigned __int16 v6; // [esp-8h] [ebp-Ch]

  if ( host_state.worldmodel != nullptr )
  {
    InvalidateStaticLightingCache();
    m_Head = this->m_ModelInstances.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_ModelInstances.m_Memory.m_pMemory;
      do
      {
        v4 = (unsigned __int16)m_Head;
        v6 = m_Head;
        v5 = m_pMemory[v4].m_Element.m_pRenderable->GetIClientUnknown(this: m_pMemory[v4].m_Element.m_pRenderable);
        CModelRender::UpdateStaticPropColorData(this, pProp: v5, handle: v6);
        m_pMemory = this->m_ModelInstances.m_Memory.m_pMemory;
        m_Head = m_pMemory[v4].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2970
// Name: public: virtual bool CModelRender::RecomputeStaticLighting(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelRender::RecomputeStaticLighting(CModelRender *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v4; // esi
  LightCacheHandle_t__ *m_LightCacheHandle; // eax
  const LightingState_t *Static; // eax
  IHandleEntity *v7; // eax

  if ( handle == 0xFFFF )
    return false;
  v4 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  if ( (v4->m_Element.m_pModel->flags & 0x2000) == 0 )
    return true;
  if ( r_decalstaticprops.m_pParent != nullptr && r_decalstaticprops.m_pParent->m_Value.m_nValue != 0 )
  {
    m_LightCacheHandle = v4->m_Element.m_LightCacheHandle;
    if ( m_LightCacheHandle != nullptr )
    {
      Static = LightcacheGetStatic(cache: m_LightCacheHandle, pEnvCubemapTexture: nullptr, flags: 1u);
      LightingState_t::operator=(this: &v4->m_Element.m_pLightingState->m_AmbientLightingState, __that: Static);
    }
  }
  if ( ((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: v4->m_Element.m_pModel->studio) == 0 )
    return false;
  v7 = v4->m_Element.m_pRenderable->GetIClientUnknown(this: v4->m_Element.m_pRenderable);
  return CModelRender::UpdateStaticPropColorData(this, pProp: v7, handle);
}

//------------------------------------------------------------------------------
// Address: 0x100E2A20
// Name: public: virtual void CModelRender::ComputeStaticLightingState(int,struct StaticLightingQuery_t const __near *,struct MaterialLightingState_t __near *,struct MaterialLightingState_t __near *,struct ColorMeshInfo_t __near * __near *,class ITexture __near * __near *,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ComputeStaticLightingState(
        CModelRender *this,
        int nCount,
        ITexture *pQuery,
        IClientRenderable *pLightingState,
        MaterialLightingState_t *pDecalState,
        ColorMeshInfo_t **ppStaticLighting,
        ITexture **ppEnvCubemapTexture,
        memhandle_t__ **pColorMeshHandles)
{
  IClientRenderable *v9; // edi
  int v10; // esi
  ITexture *v11; // ecx
  ITexture **v12; // ebx
  float *v13; // esi
  float *v14; // edi
  float *v15; // edx
  int v16; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v17; // ecx
  LightCacheHandle_t__ **p_m_LightCacheHandle; // ecx
  int v19; // esi
  void *v20; // esp
  int v21; // edi
  _BYTE *v22; // ebx
  IClientRenderable **v23; // eax
  MaterialLightingState_t *v24; // edx
  IClientRenderable *v25; // ecx
  IClientRenderable_vtbl *v26; // eax
  const model_t *v27; // eax
  memhandle_t__ *m_ColorMeshHandle; // eax
  memhandle_t__ **v29; // edi
  int v30; // eax
  memhandle_t__ **v31; // edx
  int v32; // edi
  ITexture **v33; // esi
  MaterialLightingState_t *v34; // eax
  bool v35; // zf
  char v36; // cl
  int v37; // eax
  IHandleEntity *v38; // eax
  CModelRender *v39; // esi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v40; // edi
  LightCacheHandle_t__ **v41; // esi
  LightingState_t *Static; // eax
  int v43; // eax
  LightingState_t *p_lightingState; // esi
  float *p_m_flLightingTime; // eax
  float v46; // xmm1_4
  float v47; // xmm2_4
  float *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm2_4
  float *v51; // eax
  float v52; // xmm1_4
  float v53; // xmm2_4
  float *v54; // eax
  float v55; // xmm1_4
  float v56; // xmm2_4
  float *v57; // eax
  float v58; // xmm1_4
  float v59; // xmm2_4
  float *v60; // eax
  float v61; // xmm1_4
  float v62; // xmm2_4
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // edi
  int v64; // eax
  dworldlight_t **locallight; // edx
  dworldlight_t **v66; // ecx
  float v67; // eax
  float v68; // edx
  CModelRender *v69; // edi
  MaterialLightingState_t *v70; // esi
  const IClientRenderable *v71; // [esp-Ch] [ebp-100h]
  unsigned __int16 v72; // [esp-4h] [ebp-F8h]
  const LightingState_t *v73; // [esp-4h] [ebp-F8h]
  _BYTE v74[12]; // [esp+0h] [ebp-F4h] BYREF
  LightcacheGetDynamic_Stats stats; // [esp+Ch] [ebp-E8h] BYREF
  LightcacheGetDynamic_Stats v76; // [esp+10h] [ebp-E4h] BYREF
  Vector vLightingOrigin; // [esp+14h] [ebp-E0h] BYREF
  LightingState_t decalLightingState; // [esp+20h] [ebp-D4h] BYREF
  LightingState_t lightingState; // [esp+7Ch] [ebp-78h] BYREF
  int v80; // [esp+D8h] [ebp-1Ch]
  int v81; // [esp+DCh] [ebp-18h]
  int v82; // [esp+E0h] [ebp-14h]
  int v83; // [esp+E4h] [ebp-10h]
  _BYTE *v84; // [esp+E8h] [ebp-Ch]
  MaterialLightingState_t *hInstance; // [esp+ECh] [ebp-8h]
  CModelRender *v86; // [esp+F0h] [ebp-4h]

  v86 = this;
  if ( mat_fullbright.m_pParent != nullptr && mat_fullbright.m_pParent->m_Value.m_nValue == 1 )
  {
    v9 = pLightingState;
    v10 = nCount;
    CModelRender::SetFullbrightLightingState(this, nCount, pState: (MaterialLightingState_t *)pLightingState);
    CModelRender::SetFullbrightLightingState(this, nCount: v10, pState: pDecalState);
    memset(dst: (unsigned __int8 *)pColorMeshHandles, value: 0, count: 4 * v10);
    if ( v10 > 0 )
    {
      v11 = (ITexture *)((char *)pDecalState - (char *)pLightingState);
      v12 = ppEnvCubemapTexture;
      pColorMeshHandles = (memhandle_t__ **)&pDecalState->m_vecLightingOrigin;
      v13 = (float *)&pQuery[2];
      v14 = (float *)&v9[20];
      pQuery = (ITexture *)((char *)pDecalState - (char *)pLightingState);
      pLightingState = (IClientRenderable *)((char *)ppStaticLighting - (char *)ppEnvCubemapTexture);
      pDecalState = (MaterialLightingState_t *)nCount;
      while ( 1 )
      {
        v15 = (float *)pColorMeshHandles;
        *(v14 - 2) = *(v13 - 2);
        *(v14 - 1) = *(v13 - 1);
        *v14 = *v13;
        *v15 = *(v13 - 2);
        v15[1] = *(v13 - 1);
        *(float *)((char *)v14 + (_DWORD)v11) = *v13;
        *(IClientRenderable_vtbl **)((char *)&pLightingState->__vftable + (_DWORD)v12) = nullptr;
        v16 = *((unsigned __int16 *)v13 + 2);
        if ( (_WORD)v16 == 0xFFFF )
          goto LABEL_11;
        v17 = &v86->m_ModelInstances.m_Memory.m_pMemory[v16];
        if ( (v17->m_Element.m_nFlags & 1) != 0
          && *(p_m_LightCacheHandle = &v17->m_Element.m_LightCacheHandle) != nullptr
          && p_m_LightCacheHandle != nullptr )
        {
          LightcacheGetStatic(cache: *p_m_LightCacheHandle, pEnvCubemapTexture: v12, flags: 7u);
        }
        else
        {
LABEL_11:
          v71 = *((const IClientRenderable **)v13 + 2);
          memset(&lightingState, 0, 76);
          *v12 = LightcacheGetDynamic(
                   origin: (const Vector *)(v13 - 2),
                   &lightingState,
                   stats: (LightcacheGetDynamic_Stats *)&nCount,
                   pRenderable: v71,
                   flags: 0xFu,
                   bDebugModel: false);
        }
        pColorMeshHandles += 110;
        v14 += 110;
        v13 += 5;
        ++v12;
        pDecalState = (MaterialLightingState_t *)((char *)pDecalState - 1);
        if ( pDecalState == nullptr )
          break;
        v11 = pQuery;
      }
    }
    return;
  }
  v19 = nCount;
  v20 = alloca(4 * nCount);
  v21 = 0;
  v22 = v74;
  if ( nCount > 0 )
  {
    v23 = (IClientRenderable **)&pQuery[4];
    for ( nCount = (int)&pQuery[4]; ; v23 = (IClientRenderable **)nCount )
    {
      v24 = (MaterialLightingState_t *)*((unsigned __int16 *)v23 - 2);
      v25 = *v23;
      v26 = (*v23)->__vftable;
      hInstance = v24;
      v27 = v26->GetModel(this: v25);
      if ( (_WORD)hInstance == 0xFFFF || !modelinfo->UsesStaticLighting(this: modelinfo, a2: v27) )
        m_ColorMeshHandle = nullptr;
      else
        m_ColorMeshHandle = v86->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)hInstance].m_Element.m_ColorMeshHandle;
      nCount += 20;
      pColorMeshHandles[v21++] = m_ColorMeshHandle;
      if ( v21 >= v19 )
        break;
    }
  }
  v29 = pColorMeshHandles;
  v86->m_pCache->GetAndLockMultiple(this: v86->m_pCache, a2: (void **)v74, a3: v19, a4: pColorMeshHandles);
  v30 = 0;
  if ( v19 > 0 )
  {
    do
      ++v30;
    while ( v30 < v19 );
    v31 = (memhandle_t__ **)pQuery;
    ppStaticLighting = (ColorMeshInfo_t **)((char *)ppStaticLighting - v74);
    v80 = (char *)ppEnvCubemapTexture - v74;
    v32 = (char *)v29 - v74;
    hInstance = pDecalState;
    pColorMeshHandles = (memhandle_t__ **)pQuery;
    v84 = v74;
    v81 = v32;
    v82 = (char *)pLightingState - (char *)pDecalState;
    v83 = v19;
    while ( 1 )
    {
      v33 = (ITexture **)*((unsigned __int16 *)v31 + 6);
      v34 = (MaterialLightingState_t *)v31[4];
      ppEnvCubemapTexture = v33;
      pLightingState = (IClientRenderable *)v34;
      if ( (_WORD)v33 == 0xFFFF
        || (v35 = v86->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)v33].m_Element.m_DecalHandle == nullptr,
            HIBYTE(pDecalState) = 1,
            v35) )
      {
        HIBYTE(pDecalState) = 0;
      }
      v36 = 0;
      *(_DWORD *)&v22[(_DWORD)ppStaticLighting] = 0;
      if ( *(_DWORD *)&v22[v32] != 0 )
        break;
LABEL_38:
      v40 = nullptr;
      v41 = nullptr;
      pQuery = nullptr;
      if ( (_WORD)ppEnvCubemapTexture != 0xFFFF )
      {
        v40 = &v86->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)ppEnvCubemapTexture];
        if ( (v40->m_Element.m_nFlags & 1) != 0 && v40->m_Element.m_LightCacheHandle != nullptr )
          v41 = &v40->m_Element.m_LightCacheHandle;
      }
      memset(&lightingState, 0, 76);
      memset(&decalLightingState, 0, 76);
      nCount = (int)&decalLightingState;
      if ( v41 != nullptr )
      {
        if ( v36 == 0 || StaticLightCacheAffectedByDynamicLight(handle: *v41) )
          Static = LightcacheGetStatic(cache: *v41, pEnvCubemapTexture: &pQuery, flags: 7u);
        else
          Static = LightcacheGetStatic(cache: *v41, pEnvCubemapTexture: &pQuery, flags: 6u);
        p_lightingState = Static;
        if ( HIBYTE(pDecalState) != 0 )
        {
          p_m_flLightingTime = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v46 = p_m_flLightingTime[25] + p_lightingState->r_boxcolor[0].y;
          v47 = p_m_flLightingTime[26] + p_lightingState->r_boxcolor[0].z;
          decalLightingState.r_boxcolor[0].x = p_lightingState->r_boxcolor[0].x + p_m_flLightingTime[24];
          decalLightingState.r_boxcolor[0].y = v46;
          decalLightingState.r_boxcolor[0].z = v47;
          v48 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v49 = v48[28] + p_lightingState->r_boxcolor[1].y;
          v50 = v48[29] + p_lightingState->r_boxcolor[1].z;
          decalLightingState.r_boxcolor[1].x = p_lightingState->r_boxcolor[1].x + v48[27];
          decalLightingState.r_boxcolor[1].y = v49;
          decalLightingState.r_boxcolor[1].z = v50;
          v51 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v52 = v51[31] + p_lightingState->r_boxcolor[2].y;
          v53 = v51[32] + p_lightingState->r_boxcolor[2].z;
          decalLightingState.r_boxcolor[2].x = p_lightingState->r_boxcolor[2].x + v51[30];
          decalLightingState.r_boxcolor[2].y = v52;
          decalLightingState.r_boxcolor[2].z = v53;
          v54 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v55 = v54[34] + p_lightingState->r_boxcolor[3].y;
          v56 = v54[35] + p_lightingState->r_boxcolor[3].z;
          decalLightingState.r_boxcolor[3].x = p_lightingState->r_boxcolor[3].x + v54[33];
          decalLightingState.r_boxcolor[3].y = v55;
          decalLightingState.r_boxcolor[3].z = v56;
          v57 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v58 = v57[37] + p_lightingState->r_boxcolor[4].y;
          v59 = v57[38] + p_lightingState->r_boxcolor[4].z;
          decalLightingState.r_boxcolor[4].x = p_lightingState->r_boxcolor[4].x + v57[36];
          decalLightingState.r_boxcolor[4].y = v58;
          decalLightingState.r_boxcolor[4].z = v59;
          v60 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v61 = v60[40] + p_lightingState->r_boxcolor[5].y;
          v62 = v60[41] + p_lightingState->r_boxcolor[5].z;
          decalLightingState.r_boxcolor[5].x = p_lightingState->r_boxcolor[5].x + v60[39];
          decalLightingState.r_boxcolor[5].y = v61;
          decalLightingState.r_boxcolor[5].z = v62;
          m_pLightingState = v40->m_Element.m_pLightingState;
          decalLightingState.numlights = m_pLightingState->m_AmbientLightingState.numlights;
          v64 = 0;
          if ( m_pLightingState->m_AmbientLightingState.numlights > 0 )
          {
            locallight = decalLightingState.locallight;
            v66 = m_pLightingState->m_AmbientLightingState.locallight;
            do
            {
              *locallight = *v66;
              ++v64;
              ++v66;
              ++locallight;
            }
            while ( v64 < m_pLightingState->m_AmbientLightingState.numlights );
            v22 = v84;
          }
          LightingState_t::AddAllLocalLights(
            this: &decalLightingState,
            src: p_lightingState,
            vecLightingOrigin: (const Vector *)pColorMeshHandles);
        }
        else
        {
          nCount = (int)Static;
        }
      }
      else
      {
        LODWORD(vLightingOrigin.x) = *v31;
        v67 = *((float *)v31 + 1);
        v68 = *((float *)v31 + 2);
        vLightingOrigin.y = v67;
        vLightingOrigin.z = v68;
        pQuery = LightcacheGetDynamic(
                   origin: &vLightingOrigin,
                   &lightingState,
                   &stats,
                   pRenderable: pLightingState,
                   flags: v36 != 0 ? 6 : 15,
                   bDebugModel: false);
        p_lightingState = &lightingState;
        if ( HIBYTE(pDecalState) != 0 )
          LightcacheGetDynamic(
            origin: &vLightingOrigin,
            lightingState: &decalLightingState,
            stats: &v76,
            pRenderable: pLightingState,
            flags: 0xFu,
            bDebugModel: false);
        else
          nCount = (int)&lightingState;
      }
      v69 = v86;
      v73 = p_lightingState;
      v70 = hInstance;
      CModelRender::EngineLightingToMaterialLighting(
        this: v86,
        pLightingState: (MaterialLightingState_t *)((char *)hInstance + v82),
        vecLightingOrigin: (const Vector *)pColorMeshHandles,
        srcLightingState: v73);
      if ( HIBYTE(pDecalState) != 0 )
        CModelRender::EngineLightingToMaterialLighting(
          this: v69,
          pLightingState: v70,
          vecLightingOrigin: (const Vector *)pColorMeshHandles,
          srcLightingState: (const LightingState_t *)nCount);
      pColorMeshHandles += 5;
      *(_DWORD *)&v22[v80] = pQuery;
      v22 += 4;
      v35 = v83-- == 1;
      hInstance = v70 + 1;
      v84 = v22;
      if ( v35 )
        return;
      v32 = v81;
      v31 = pColorMeshHandles;
    }
    v37 = *(_DWORD *)v22;
    HIBYTE(nCount) = 1;
    if ( v37 == 0 || (*(_BYTE *)(v37 + 20) & 2) != 0 )
    {
      v72 = (unsigned __int16)v33;
      v38 = (IHandleEntity *)pLightingState->GetIClientUnknown(this: pLightingState);
      v39 = v86;
      if ( CModelRender::UpdateStaticPropColorData(this: v86, pProp: v38, handle: v72) )
      {
        *(_DWORD *)v22 = v39->m_pCache->Get(this: v39->m_pCache, a2: *(memhandle_t__ **)&v22[v32], a3: true);
        if ( v39->m_pCache->Lock(this: v39->m_pCache, a2: *(_DWORD *)&v22[v32]) == nullptr )
        {
LABEL_34:
          *(_DWORD *)&v22[v32] = 0;
LABEL_35:
          v31 = pColorMeshHandles;
          *(_DWORD *)v22 = 0;
          goto LABEL_36;
        }
      }
      else
      {
        if ( *(_DWORD *)v22 == 0 )
          goto LABEL_34;
        if ( (*(_BYTE *)(*(_DWORD *)v22 + 20) & 2) == 0 )
          goto LABEL_35;
      }
      v31 = pColorMeshHandles;
    }
    v43 = *(_DWORD *)v22;
    if ( *(_DWORD *)v22 != 0 && (*(_BYTE *)(v43 + 20) & 1) != 0 )
    {
      *(_DWORD *)&v22[(_DWORD)ppStaticLighting] = *(_DWORD *)(v43 + 4);
      goto LABEL_37;
    }
LABEL_36:
    HIBYTE(nCount) = 0;
LABEL_37:
    v36 = HIBYTE(nCount);
    goto LABEL_38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E31C0
// Name: void AddModelDebugOverlay(struct DrawModelInfo_t const __near &,struct DrawModelResults_t const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddModelDebugOverlay(const DrawModelInfo_t *info, const DrawModelResults_t *results, const Vector *origin)
{
  ModelDebugOverlayData_t *v3; // ebx

  v3 = &s_SavedModelInfo.m_Memory.m_pMemory[CUtlVector<ModelDebugOverlayData_t,CUtlMemory<ModelDebugOverlayData_t,int>>::InsertBefore(
                                              this: &s_SavedModelInfo,
                                              elem: s_SavedModelInfo.m_Size)];
  qmemcpy(v3, info, 0x1E0u);
  DrawModelResults_t::operator=(this: &v3->m_ModelResults, __that: results);
  v3->m_Origin = *origin;
}

//------------------------------------------------------------------------------
// Address: 0x100E3220
// Name: private: virtual void CModelRender::DrawModelExecute(class IMatRenderContext __near *,struct DrawModelState_t const __near &,struct ModelRenderInfo_t const __near &,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelRender::DrawModelExecute(
        CModelRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        IMatRenderContext *pRenderContext,
        const DrawModelState_t *state,
        const ModelRenderInfo_t *pInfo,
        __int128 pBoneToWorld)
{
  const ModelRenderInfo_t *v7; // ebx
  unsigned int flags; // eax
  unsigned int v9; // ecx
  unsigned int v10; // edx
  bool v11; // al
  int numflexdesc; // eax
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4a_t *v15; // eax
  IClientRenderable *m_pRenderable; // ecx
  float *v17; // ebx
  bool (__thiscall *UsesFlexDelayedWeights)(IClientRenderable *); // edx
  void *(__thiscall *v19)(IMatRenderContext *, int); // edx
  int v20; // eax
  int m_nValue; // ecx
  CModelRender *v22; // esi
  IDataCacheSection *m_pCache; // ecx
  IDataCacheSection_vtbl *v24; // edx
  int v25; // eax
  void *v26; // esi
  int instance; // eax
  int v28; // eax
  LightCacheHandle_t__ **v29; // eax
  studiohdr_t *m_pStudioHdr; // eax
  int skin; // edx
  int body; // eax
  IClientRenderable *v33; // edx
  int m_lod; // eax
  int v35; // esi
  DrawModelInfo_t drawInfo; // [esp+18h] [ebp-27Ch] BYREF
  DrawModelResults_t v39; // [esp+1F8h] [ebp-9Ch] BYREF
  Vector v40; // [esp+248h] [ebp-4Ch] BYREF
  CMatRenderData<matrix3x4a_t> v41; // [esp+254h] [ebp-40h] BYREF
  CMatRenderData<matrix3x4a_t> v42; // [esp+264h] [ebp-30h] BYREF
  matrix3x4a_t *v43; // [esp+274h] [ebp-20h]
  LightCacheHandle_t__ **v44; // [esp+278h] [ebp-1Ch]
  bool v45; // [esp+27Ch] [ebp-18h]
  memhandle_t__ *m_ColorMeshHandle; // [esp+280h] [ebp-14h]
  matrix3x4a_t *m_pRenderData; // [esp+284h] [ebp-10h]
  char v48; // [esp+28Bh] [ebp-9h]
  CModelRender *v49; // [esp+28Ch] [ebp-8h]
  bool v50; // [esp+292h] [ebp-2h]
  char v51; // [esp+293h] [ebp-1h]
  bool v52; // [esp+29Ch] [ebp+8h]
  ColorMeshInfo_t *v53; // [esp+2A0h] [ebp+Ch]

  v7 = pInfo;
  flags = pInfo->flags;
  v49 = this;
  v9 = flags >> 30;
  v10 = flags >> 28;
  v11 = (flags & 0x400) != 0;
  v51 = v9 & 1;
  v48 = v10 & 1;
  v50 = v11;
  if ( ((v9 & 1) == 0 || (pInfo->pModel->flags & 0x1000) == 0) && !g_bTextMode )
  {
    v43 = nullptr;
    m_pRenderData = nullptr;
    v41.m_pRenderContext = pRenderContext;
    memset(&v41.m_pRenderData, 0, 9);
    v42.m_pRenderContext = pRenderContext;
    memset(&v42.m_pRenderData, 0, 9);
    if ( !v11 )
    {
      numflexdesc = state->m_pStudioHdr->numflexdesc;
      if ( numflexdesc > 0 )
      {
        LockRenderData = pRenderContext->LockRenderData;
        v41.m_nCount = state->m_pStudioHdr->numflexdesc;
        v15 = (matrix3x4a_t *)LockRenderData(this: pRenderContext, a2: 4 * numflexdesc);
        m_pRenderable = state->m_pRenderable;
        v17 = (float *)v15;
        UsesFlexDelayedWeights = m_pRenderable->UsesFlexDelayedWeights;
        v41.m_pRenderData = v15;
        v41.m_bNeedsUnlock = true;
        v43 = v15;
        if ( UsesFlexDelayedWeights(this: m_pRenderable) )
        {
          v19 = pRenderContext->LockRenderData;
          v42.m_nCount = state->m_pStudioHdr->numflexdesc;
          v42.m_pRenderData = (matrix3x4a_t *)v19(this: pRenderContext, a2: 4 * v42.m_nCount);
          v42.m_bNeedsUnlock = true;
          m_pRenderData = v42.m_pRenderData;
        }
        if ( v17 != nullptr )
          state->m_pRenderable->SetupWeights(
            this: state->m_pRenderable,
            a2: (const matrix3x4_t *)pBoneToWorld,
            a3: state->m_pStudioHdr->numflexdesc,
            a4: v17,
            a5: (float *)m_pRenderData);
        v7 = pInfo;
      }
    }
    v53 = nullptr;
    m_ColorMeshHandle = nullptr;
    if ( v51 != 0 || (v7->flags & 0x200) != 0 )
    {
      drawInfo.m_bStaticLighting = false;
      g_pStudioRender->ClearAllShadows(this: g_pStudioRender);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))g_pShadowMgr->SetModelShadowState)(a1: v7->instance);
      v20 = v7->pModel->flags;
      if ( r_staticlight_streams.m_pParent != nullptr )
        m_nValue = r_staticlight_streams.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( (state->m_drawFlags & 8) == 0
        || (state->m_pStudioHdr->flags & 0x10) == 0
        || (v7->pModel->flags & 0x200) != 0 && m_nValue <= 1
        || (HIBYTE(pInfo) = 1, v7->instance == 0xFFFF) )
      {
        HIBYTE(pInfo) = 0;
      }
      v45 = (v20 & 4) != 0;
      if ( r_showenvcubemap.m_pParent != nullptr && r_showenvcubemap.m_pParent->m_Value.m_nValue != 0
        || (v52 = false, (v20 & 0x400) != 0) )
      {
        v52 = true;
      }
      if ( r_drawmodellightorigin.m_pParent != nullptr && r_drawmodellightorigin.m_pParent->m_Value.m_nValue != 0 )
      {
        v22 = v49;
        CModelRender::DebugDrawLightingOrigin(this: v49, state, pInfo: v7);
      }
      else
      {
        v22 = v49;
      }
      if ( HIBYTE(pInfo) != 0 )
      {
        m_pCache = v22->m_pCache;
        v24 = m_pCache->__vftable;
        m_ColorMeshHandle = v22->m_ModelInstances.m_Memory.m_pMemory[v7->instance].m_Element.m_ColorMeshHandle;
        v25 = (int)v24->Get(this: m_pCache, a2: m_ColorMeshHandle, a3: true);
        v26 = (void *)v25;
        if ( v25 == 0 || (*(_BYTE *)(v25 + 20) & 2) != 0 )
        {
          if ( ((unsigned __int8 (__stdcall *)(_DWORD))v49->RecomputeStaticLighting)(a1: v7->instance) != 0 )
          {
            v26 = v49->m_pCache->Get(this: v49->m_pCache, a2: m_ColorMeshHandle, a3: 1);
          }
          else if ( v26 == nullptr || (*((_BYTE *)v26 + 20) & 2) == 0 )
          {
LABEL_64:
            CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &v42);
            CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &v41);
            return;
          }
        }
        if ( v26 != nullptr && (*((_BYTE *)v26 + 20) & 1) != 0 )
          v53 = *((ColorMeshInfo_t **)v26 + 1);
        else
          HIBYTE(pInfo) = 0;
        v22 = v49;
      }
      drawInfo.m_bStaticLighting = false;
      if ( v45 || v52 )
      {
        instance = v7->instance;
        v44 = nullptr;
        if ( (_WORD)instance != 0xFFFF )
        {
          v28 = (int)&v22->m_ModelInstances.m_Memory.m_pMemory[instance];
          if ( (*(_BYTE *)(v28 + 14) & 1) != 0 )
          {
            v29 = (LightCacheHandle_t__ **)(v28 + 16);
            if ( *v29 != nullptr )
              v44 = v29;
          }
        }
        R_ComputeLightingOrigin(
          pRenderable: state->m_pRenderable,
          pStudioHdr: state->m_pStudioHdr,
          matrix: state->m_pModelToWorld,
          center: &v40);
        CModelRender::StudioSetupLighting(
          this: v22,
          state,
          absEntCenter: &v40,
          pLightcache: v44,
          bVertexLit: v45,
          bNeedsEnvCubemap: v52,
          bStaticLighting: (bool *)&pInfo + 3,
          &drawInfo,
          pInfo: v7,
          drawFlags: state->m_drawFlags);
      }
    }
    ((void (__thiscall *)(IStudioRender *, Vector *, Vector *, Vector *, Vector *, int, int))g_pStudioRender->SetViewState)(
      a1: g_pStudioRender,
      a2: &g_CurrentViewOrigin,
      a3: &g_CurrentViewRight,
      a4: &g_CurrentViewUp,
      a5: &g_CurrentViewForward,
      a6: a2,
      a7: a3);
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)&r_colormod);
    ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: LODWORD(r_blend));
    m_pStudioHdr = state->m_pStudioHdr;
    skin = v7->skin;
    drawInfo.m_pHardwareData = state->m_pStudioHWData;
    drawInfo.m_HitboxSet = v7->hitboxset;
    drawInfo.m_pStudioHdr = m_pStudioHdr;
    body = v7->body;
    drawInfo.m_pColorMeshes = v53;
    drawInfo.m_Skin = skin;
    v33 = state->m_pRenderable;
    drawInfo.m_Body = body;
    m_lod = state->m_lod;
    drawInfo.m_pClientEntity = (void *)v33;
    drawInfo.m_Lod = m_lod;
    if ( v51 != 0 )
      drawInfo.m_Decals = nullptr;
    else
      drawInfo.m_Decals = state->m_decals;
    if ( r_drawmodelstatsoverlay.m_pParent != nullptr )
      v35 = r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue;
    else
      v35 = 0;
    v39.m_RenderTime.m_Duration.m_Int64 = 0;
    v39.m_Materials.m_Size = 0;
    v39.m_Materials.m_pElements = (IMaterial **)&v39.m_Materials;
    ((void (__thiscall *)(IStudioRender *, DrawModelResults_t *, DrawModelInfo_t *, _DWORD, matrix3x4a_t *, matrix3x4a_t *))g_pStudioRender->DrawModel)(
      a1: g_pStudioRender,
      a2: &v39,
      a3: &drawInfo,
      a4: pBoneToWorld,
      a5: v43,
      a6: m_pRenderData);
    drawInfo.m_Lod = v39.m_nLODUsed;
    if ( v35 != 0 && v51 == 0 )
    {
      if ( v35 == 2 )
        AddModelDebugOverlay(info: &drawInfo, results: &v39, origin: &v7->origin);
      else
        DrawModelDebugOverlay(info: &drawInfo, results: &v39, origin: &v7->origin, r: 1.0, g: 1.0, b: 1.0);
    }
    if ( v53 != nullptr )
      CModelRender::ProtectColorDataIfQueued(this: v49, hColorMesh: m_ColorMeshHandle);
    v39.m_Materials.m_Size = 0;
    v39.m_Materials.m_pElements = (IMaterial **)&v39.m_Materials;
    goto LABEL_64;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E36E0
// Name: public: virtual int CModelRender::DrawStaticPropArrayFast(struct StaticPropRenderInfo_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::DrawStaticPropArrayFast(
        CModelRender *this,
        StaticPropRenderInfo_t *pProps,
        int count,
        int bShadowDepth)
{
  void (*BeginLock)(void); // edx
  vgui::RichText::TFormatStream *v5; // eax
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int m_nValue; // eax
  const model_t **p_pModel; // ebx
  int v9; // eax
  rmodel_t *v10; // ecx
  const model_t *v11; // edx
  __int16 v12; // cx
  unsigned int v13; // eax
  const model_t *v14; // edx
  unsigned int v15; // esi
  int v16; // eax
  vgui::RichText::TFormatStream *v17; // eax
  int v18; // esi
  const model_t *pModel; // edi
  unsigned int flags; // ebx
  int studio; // edx
  studiohdr_t *v22; // eax
  studiohwdata_t *(__thiscall *GetHardwareData)(IMDLCache *, unsigned __int16); // edx
  __int16 v24; // cx
  int v25; // eax
  bool v26; // al
  char v27; // bl
  int v28; // esi
  int v29; // edi
  vgui::RichText::TFormatStream *v30; // ebx
  float *p_flFadeSustain; // esi
  double v32; // st7
  rmodel_t *v33; // edi
  float v34; // xmm0_4
  __int16 LODForMetric; // ax
  studiohwdata_t *pStudioHWData; // edi
  float maxArea; // xmm0_4
  float *p_maxArea; // eax
  bool v39; // zf
  _WORD *v40; // edx
  unsigned int i; // ebx
  rmodel_t *v42; // ecx
  int lodCount; // eax
  int m_RootLOD; // ecx
  int v45; // eax
  vgui::RichText::TFormatStream *v46; // ebx
  char v47; // al
  LightingState_t *v48; // edi
  int v49; // eax
  int v50; // edi
  unsigned int v51; // esi
  LightingState_t *v52; // ecx
  int v53; // eax
  LightingState_t *v54; // eax
  int v55; // eax
  int v56; // esi
  IMemAlloc_vtbl *v57; // edx
  S3RGBA *v58; // ecx
  int v59; // eax
  rmodel_t **v60; // ecx
  signed int v61; // eax
  unsigned int v62; // esi
  unsigned int v63; // esi
  wchar_t *v64; // ecx
  int v65; // eax
  wchar_t *v66; // ecx
  IDataCacheSection *m_pCache; // ecx
  IDataCacheSection_vtbl *v68; // edx
  int v69; // eax
  _BYTE *v70; // esi
  IHandleEntity *v71; // eax
  int v72; // eax
  void (__thiscall ***v73)(_DWORD, _DWORD *); // esi
  _DWORD *v74; // eax
  CModelRender *v75; // ecx
  int m_nAllocationCount; // edx
  int iOriginalAlpha_low; // eax
  LightCacheHandle_t__ **p_m_LightCacheHandle; // esi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v79; // edx
  int v80; // eax
  LightingState_t *Static; // esi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v82; // eax
  float *p_m_flLightingTime; // ecx
  float v84; // xmm1_4
  float v85; // xmm2_4
  float *v86; // ecx
  float v87; // xmm1_4
  float v88; // xmm2_4
  float *v89; // ecx
  float v90; // xmm1_4
  float v91; // xmm2_4
  float *v92; // ecx
  float v93; // xmm1_4
  float v94; // xmm2_4
  float *v95; // ecx
  float v96; // xmm1_4
  float v97; // xmm2_4
  float *v98; // ecx
  float v99; // xmm1_4
  float v100; // xmm2_4
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // eax
  bool v102; // cc
  int v103; // edx
  dworldlight_t **locallight; // ecx
  float flFadeLength; // eax
  const IClientRenderable *pixelsIndent; // edx
  int v107; // eax
  float *p_z; // ecx
  float v109; // xmm0_4
  float v110; // xmm0_4
  int v111; // eax
  int v112; // edx
  unsigned int v113; // edi
  LightingState_t *v114; // ecx
  int v115; // eax
  LightingState_t *v116; // edi
  int v117; // eax
  int v118; // ebx
  unsigned int v119; // esi
  unsigned __int8 *v120; // edi
  wchar_t *v121; // ecx
  int v122; // eax
  wchar_t *v123; // eax
  vgui::RichText::TFormatStream *v124; // esi
  int v125; // edx
  __int16 *v126; // ebx
  int v127; // eax
  rmodel_t *v128; // ecx
  int v129; // eax
  int v130; // ecx
  int v131; // esi
  unsigned __int8 *v132; // edi
  int v133; // eax
  int v134; // eax
  int v135; // eax
  vgui::RichText::TFormatStream *v136; // esi
  float flFadeStartTime; // eax
  LightingState_t *v138; // edi
  signed int v139; // edi
  vgui::RichText::TFormatStream *v140; // esi
  rmodel_t *v141; // ebx
  int m; // ebx
  LightingState_t *v143; // edi
  vgui::RichText::TFormatStream *v144; // esi
  vgui::RichText::TFormatStream *v145; // esi
  LightingState_t *v146; // eax
  S3RGBA *v147; // eax
  wchar_t *v148; // eax
  wchar_t *v149; // eax
  rmodel_t *v150; // eax
  LightCacheHandle_t__ *v152; // [esp-8h] [ebp-8C3Ch]
  unsigned __int16 iOriginalAlpha; // [esp+0h] [ebp-8C34h]
  unsigned int v154; // [esp+0h] [ebp-8C34h]
  _DWORD v155[9]; // [esp+10h] [ebp-8C24h] BYREF
  CUtlMemoryFixedGrowable<LightingState_t,256,int> v156; // [esp+1310h] [ebp-7924h] BYREF
  int v157; // [esp+6F20h] [ebp-1D14h]
  LightingState_t *m_pMemory; // [esp+6F24h] [ebp-1D10h]
  LightDesc_t pLightDescs; // [esp+6F28h] [ebp-1D0Ch] BYREF
  CUtlVector<rmodel_t,CUtlMemoryFixedGrowable<rmodel_t,256,int> > v160; // [esp+7088h] [ebp-1BACh] BYREF
  _BYTE v161[256]; // [esp+84A0h] [ebp-794h] BYREF
  CUtlMemory<wchar_t,int> v162; // [esp+85A0h] [ebp-694h] BYREF
  int v163; // [esp+85ACh] [ebp-688h]
  _BYTE v164[36]; // [esp+85B0h] [ebp-684h] BYREF
  int v165; // [esp+87B0h] [ebp-484h]
  wchar_t *v166; // [esp+87B4h] [ebp-480h]
  studiohdr_t *pStudioHdr; // [esp+87B8h] [ebp-47Ch] BYREF
  studiohwdata_t *v168; // [esp+87BCh] [ebp-478h]
  StudioDecalHandle_t__ *m_DecalHandle; // [esp+87C0h] [ebp-474h]
  int iOriginalAlpha_high; // [esp+87C4h] [ebp-470h]
  int v171; // [esp+87C8h] [ebp-46Ch]
  int v172; // [esp+87CCh] [ebp-468h]
  int v173; // [esp+87D0h] [ebp-464h]
  int flFadeSustain_high; // [esp+87D4h] [ebp-460h]
  int v175; // [esp+87D8h] [ebp-45Ch]
  char v176; // [esp+87DCh] [ebp-458h]
  _DWORD v177[110]; // [esp+87E0h] [ebp-454h] BYREF
  CUtlMemory<S3RGBA,int> v178; // [esp+8998h] [ebp-29Ch] BYREF
  int v179; // [esp+89A4h] [ebp-290h]
  _BYTE v180[36]; // [esp+89A8h] [ebp-28Ch] BYREF
  int v181; // [esp+8AA8h] [ebp-18Ch]
  S3RGBA *v182; // [esp+8AACh] [ebp-188h]
  LightingState_t lightingState; // [esp+8AB0h] [ebp-184h] BYREF
  CUtlMemory<wchar_t,int> v184; // [esp+8B0Ch] [ebp-128h] BYREF
  int v185; // [esp+8B18h] [ebp-11Ch]
  _BYTE v186[36]; // [esp+8B1Ch] [ebp-118h] BYREF
  signed int v187; // [esp+8B9Ch] [ebp-98h]
  wchar_t *v188; // [esp+8BA0h] [ebp-94h]
  LightcacheGetDynamic_Stats stats; // [esp+8BA4h] [ebp-90h] BYREF
  _DWORD v190[3]; // [esp+8BA8h] [ebp-8Ch] BYREF
  IMDLCache *v191; // [esp+8BB4h] [ebp-80h]
  rmodel_t *v192; // [esp+8BB8h] [ebp-7Ch] BYREF
  LightcacheGetDynamic_Stats v193; // [esp+8BBCh] [ebp-78h] BYREF
  _DWORD v194[8]; // [esp+8BC0h] [ebp-74h] BYREF
  int v195; // [esp+8BE0h] [ebp-54h]
  _DWORD v196[3]; // [esp+8BE4h] [ebp-50h] BYREF
  LightcacheGetDynamic_Stats v197; // [esp+8BF0h] [ebp-44h]
  int v198; // [esp+8BF4h] [ebp-40h]
  CUtlMemory<vgui::RichText::TFormatStream,int> v199; // [esp+8BF8h] [ebp-3Ch] BYREF
  unsigned int v200; // [esp+8C04h] [ebp-30h]
  Vector out; // [esp+8C08h] [ebp-2Ch]
  unsigned int v202; // [esp+8C14h] [ebp-20h]
  rmodel_t *v203; // [esp+8C18h] [ebp-1Ch]
  int v204; // [esp+8C1Ch] [ebp-18h]
  CModelRender *v205; // [esp+8C20h] [ebp-14h]
  int v206; // [esp+8C24h] [ebp-10h]
  int v207; // [esp+8C28h] [ebp-Ch]
  CUtlMemory<vgui::RichText::TFormatStream,int> var3C; // [esp+8C2Ch] [ebp-8h] BYREF
  int v209; // [esp+8C3Ch] [ebp+8h]
  int v210; // [esp+8C3Ch] [ebp+8h]
  int j; // [esp+8C3Ch] [ebp+8h]
  int v212; // [esp+8C3Ch] [ebp+8h]
  unsigned int k; // [esp+8C3Ch] [ebp+8h]
  rmodel_t *v214; // [esp+8C3Ch] [ebp+8h]
  rmodel_t *v215; // [esp+8C3Ch] [ebp+8h]
  bool v216; // [esp+8C3Fh] [ebp+Bh]

  v205 = this;
  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  v191 = g_pMDLCache;
  BeginLock();
  v5 = (vgui::RichText::TFormatStream *)materials->GetRenderContext(this: materials);
  var3C.m_pMemory = v5;
  if ( v5 != nullptr )
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *))(*(_DWORD *)&v5->color + 8))(a1: v5);
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v199.m_nAllocationCount = 1024;
  v199.m_nGrowSize = 0;
  v160.m_Memory.m_pMemory = v160.m_Memory.m_pFixedMemory;
  v160.m_pElements = v160.m_Memory.m_pFixedMemory;
  v162.m_pMemory = (wchar_t *)v164;
  v166 = (wchar_t *)v164;
  v199.m_pMemory = (vgui::RichText::TFormatStream *)Alloc_2(this: _g_pMemAlloc, a2: 0x8000u);
  LODWORD(out.x) = v199.m_pMemory;
  v184.m_pMemory = (wchar_t *)v186;
  v188 = (wchar_t *)v186;
  v160.m_Memory.m_nGrowSize = -1;
  v162.m_nGrowSize = -1;
  v184.m_nGrowSize = -1;
  v178.m_nGrowSize = -1;
  v184.m_nAllocationCount = 64;
  v178.m_nAllocationCount = 64;
  v200 = 0;
  out.y = 0.0;
  LOBYTE(out.z) = 0;
  v160.m_Memory.m_nAllocationCount = 256;
  v160.m_Memory.m_nMallocGrowSize = 0;
  v160.m_Size = 0;
  v162.m_nAllocationCount = 256;
  v163 = 0;
  v165 = 0;
  v185 = 0;
  v187 = 0;
  v178.m_pMemory = (S3RGBA *)v180;
  v179 = 0;
  v181 = 0;
  v182 = (S3RGBA *)v180;
  CUtlMemoryFixedGrowable<LightingState_t,256,int>::CUtlMemoryFixedGrowable<LightingState_t,256,int>(
    this: &v156,
    nGrowSize: 0,
    nInitSize: 256);
  v157 = 0;
  m_pMemory = v156.m_pMemory;
  if ( r_showenvcubemap.m_pParent != nullptr )
    m_nValue = r_showenvcubemap.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  HIBYTE(v204) = m_nValue != 0;
  v195 = 0;
  if ( r_lod.m_pParent != nullptr )
    v207 = r_lod.m_pParent->m_Value.m_nValue;
  else
    v207 = 0;
  if ( r_staticprop_lod.m_pParent != nullptr )
  {
    if ( r_staticprop_lod.m_pParent->m_Value.m_nValue >= 0 )
      v207 = r_staticprop_lod.m_pParent->m_Value.m_nValue;
  }
  else
  {
    v207 = 0;
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "build unique model list",
    a3: 2,
    a4: "Unaccounted",
    a5: false,
    a6: 0);
  if ( count > 0 )
  {
    p_pModel = &pProps->pModel;
    v195 = count;
    do
    {
      v9 = v160.m_Size - 1;
      if ( v160.m_Size - 1 < 0 )
        goto LABEL_21;
      v10 = &v160.m_Memory.m_pMemory[v9];
      while ( v10->pModel != *p_pModel )
      {
        --v9;
        --v10;
        if ( v9 < 0 )
          goto LABEL_21;
      }
      if ( v9 < 0 )
      {
LABEL_21:
        v9 = CUtlVector<rmodel_t,CUtlMemoryFixedGrowable<rmodel_t,256,int>>::InsertBefore(
               this: &v160,
               elem: v160.m_Size);
        v160.m_Memory.m_pMemory[v9].pModel = *p_pModel;
      }
      v11 = p_pModel[1];
      v194[0] = *(p_pModel - 1);
      v12 = *((unsigned __int8 *)p_pModel + 14);
      v194[5] = (unsigned __int16)v9;
      LOWORD(v194[6]) = *((_WORD *)p_pModel + 6);
      HIWORD(v194[6]) = v12;
      v194[1] = v11;
      LOBYTE(v11) = *((_BYTE *)p_pModel + 15);
      v13 = v200;
      LOWORD(v194[7]) = -1;
      BYTE2(v194[7]) = (_BYTE)v11;
      v14 = p_pModel[2];
      v194[2] = 0;
      v194[3] = 0;
      v194[4] = v14;
      LOBYTE(out.z) = 1;
      v15 = v200;
      if ( (int)(v200 + 1) > v199.m_nAllocationCount )
      {
        CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>::Grow(this: &v199, num: v200 - v199.m_nAllocationCount + 1);
        v13 = v200;
      }
      v200 = v13 + 1;
      v16 = v13 - v15;
      LODWORD(out.x) = v199.m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v199.m_pMemory[v15 + 1], src: &v199.m_pMemory[v15], count: 32 * v16);
      v17 = &v199.m_pMemory[v15];
      if ( v17 != nullptr )
        qmemcpy(v17, v194, sizeof(vgui::RichText::TFormatStream));
      p_pModel += 5;
      --count;
    }
    while ( count != 0 );
  }
  count = 0;
  v209 = 0;
  if ( v160.m_Size > 0 )
  {
    v18 = 0;
    do
    {
      pModel = v160.m_Memory.m_pMemory[v18].pModel;
      flags = pModel->flags;
      studio = pModel->studio;
      v203 = &v160.m_Memory.m_pMemory[v18];
      v22 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: studio);
      v203->pStudioHdr = v22;
      GetHardwareData = g_pMDLCache->GetHardwareData;
      v203 = &v160.m_Memory.m_pMemory[v18];
      v203->pStudioHWData = (studiohwdata_t *)((int (__stdcall *)(_DWORD))GetHardwareData)(a1: pModel->studio);
      v24 = count;
      v160.m_Memory.m_pMemory[v18].maxArea = 1.0;
      v160.m_Memory.m_pMemory[v18].lodStart = v24;
      v160.m_Memory.m_pMemory[v18].lodCount = v160.m_Memory.m_pMemory[v18].pStudioHWData->m_NumLODs;
      if ( r_staticlight_streams.m_pParent != nullptr )
        v25 = r_staticlight_streams.m_pParent->m_Value.m_nValue;
      else
        v25 = 0;
      v26 = (v160.m_Memory.m_pMemory[v18].pStudioHdr->flags & 0x10) != 0 && ((flags & 0x200) == 0 || v25 > 1);
      *((_BYTE *)&v160.m_Memory.m_pMemory[v18] + 19) ^= (*((_BYTE *)&v160.m_Memory.m_pMemory[v18] + 19) ^ (4 * v26)) & 4;
      *((_BYTE *)&v160.m_Memory.m_pMemory[v18] + 19) ^= (*((_BYTE *)&v160.m_Memory.m_pMemory[v18] + 19)
                                                       ^ (flags >> 2))
                                                      & 1;
      v27 = *((_BYTE *)&v160.m_Memory.m_pMemory[v18++] + 19) ^ (2 * (flags >> 10));
      *((_BYTE *)&v160.m_Memory.m_pMemory[v18 - 1] + 19) ^= v27 & 2;
      count += v160.m_Memory.m_pMemory[v18 - 1].lodCount;
      ++v209;
    }
    while ( v209 < v160.m_Size );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v28 = v207;
  v29 = v200;
  if ( v207 >= 0 )
  {
    if ( (int)v200 > 0 )
    {
      v40 = (_WORD *)&v199.m_pMemory->fade.flFadeSustain + 1;
      for ( i = v200; i != 0; --i )
      {
        v42 = &v160.m_Memory.m_pMemory[(__int16)*(v40 - 1)];
        lodCount = v42->lodCount;
        m_RootLOD = v42->pStudioHWData->m_RootLOD;
        v45 = lodCount - 1;
        if ( v28 >= m_RootLOD )
        {
          if ( v28 <= v45 )
            LOWORD(v45) = v28;
        }
        else
        {
          LOWORD(v45) = m_RootLOD;
        }
        *v40 = v45;
        v40 += 16;
      }
    }
  }
  else if ( (int)v200 > 0 )
  {
    v30 = var3C.m_pMemory;
    p_flFadeSustain = &v199.m_pMemory->fade.flFadeSustain;
    var3C.m_nAllocationCount = v200;
    do
    {
      MatrixGetColumn(in: *((const matrix3x4_t **)p_flFadeSustain - 5), column: 3, out: (Vector *)&v194[5]);
      v32 = ((double (__thiscall *)(vgui::RichText::TFormatStream *, _DWORD *, _DWORD))*(_DWORD *)(*(_DWORD *)&v30->color
                                                                                                 + 312))(
              a1: v30,
              a2: &v194[5],
              a3: 0.5);
      *(float *)&v210 = v32;
      v33 = &v160.m_Memory.m_pMemory[*(__int16 *)p_flFadeSustain];
      if ( v32 == 0.0 )
        v34 = 0.0;
      else
        v34 = 100.0 / *(float *)&v210;
      count = LODWORD(v34);
      LODForMetric = studiohwdata_t::GetLODForMetric(this: v33->pStudioHWData, lodMetric: v34);
      *((_WORD *)p_flFadeSustain + 1) = LODForMetric;
      pStudioHWData = v33->pStudioHWData;
      if ( LODForMetric < pStudioHWData->m_RootLOD )
        *((_WORD *)p_flFadeSustain + 1) = pStudioHWData->m_RootLOD;
      maxArea = v160.m_Memory.m_pMemory[*(__int16 *)p_flFadeSustain].maxArea;
      p_maxArea = &v160.m_Memory.m_pMemory[*(__int16 *)p_flFadeSustain].maxArea;
      if ( maxArea <= *(float *)&v210 )
        maxArea = v32;
      p_flFadeSustain += 8;
      v39 = var3C.m_nAllocationCount-- == 1;
      *p_maxArea = maxArea;
    }
    while ( !v39 );
    v29 = v200;
LABEL_60:
    if ( v29 > 1 )
    {
      v192 = v160.m_Memory.m_pMemory;
      v193 = (LightcacheGetDynamic_Stats)((char *)&count + 3);
      qsort_s(
        base: v199.m_pMemory,
        num: v29,
        width: 0x20u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<robject_t,CRobjectLess>::CompareHelper,
        context: &v192);
    }
    v198 = (*(int (__thiscall **)(vgui::RichText::TFormatStream *))(*(_DWORD *)&v30->color + 564))(a1: v30);
    if ( (_BYTE)bShadowDepth == 0 )
    {
      v207 = 0;
      if ( (int)v200 > 0 )
      {
        while ( 1 )
        {
          v46 = &v199.m_pMemory[v207];
          v47 = *((_BYTE *)&v160.m_Memory.m_pMemory[SLOWORD(v46->fade.flFadeSustain)] + 19);
          if ( (v47 & 4) == 0 || (HIBYTE(bShadowDepth) = 1, LOWORD(v46->fade.iOriginalAlpha) == 0xFFFF) )
            HIBYTE(bShadowDepth) = 0;
          HIBYTE(v206) = v47 & 1;
          if ( HIBYTE(v204) != 0 || (HIBYTE(count) = 0, (v47 & 2) != 0) )
            HIBYTE(count) = 1;
          v48 = nullptr;
          v216 = v205->m_ModelInstances.m_Memory.m_pMemory[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_DecalHandle != nullptr;
          if ( v205->m_ModelInstances.m_Memory.m_pMemory[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_DecalHandle != nullptr )
          {
            v49 = v157;
            v50 = v157;
            if ( v157 + 1 > v156.m_nAllocationCount )
            {
              v202 = v157 - v156.m_nAllocationCount + 1;
              if ( v156.m_nGrowSize < 0 )
              {
                v156.m_nGrowSize = v156.m_nMallocGrowSize;
                if ( v156.m_nAllocationCount != 0 )
                {
                  v51 = 92 * v156.m_nAllocationCount;
                  var3C.m_nAllocationCount = (int)_g_pMemAlloc->Alloc_2(
                                                    this: _g_pMemAlloc,
                                                    a2: 92 * v156.m_nAllocationCount);
                  memcpy(
                    dst: (unsigned __int8 *)var3C.m_nAllocationCount,
                    src: (unsigned __int8 *)v156.m_pMemory,
                    count: v51);
                  v156.m_pMemory = (LightingState_t *)var3C.m_nAllocationCount;
                }
                else
                {
                  v156.m_pMemory = nullptr;
                }
              }
              CUtlMemory<SoundInfo_t,int>::Grow(this: &v156, num: v202);
              v49 = v157;
            }
            v52 = v156.m_pMemory;
            v157 = v49 + 1;
            v53 = v49 - v50;
            m_pMemory = v156.m_pMemory;
            if ( v53 > 0 )
            {
              _V_memmove(dest: &v156.m_pMemory[v50 + 1], src: &v156.m_pMemory[v50], count: 92 * v53);
              v52 = v156.m_pMemory;
            }
            v54 = &v52[v50];
            if ( v54 != nullptr )
            {
              v54->r_boxcolor[0].x = 0.0;
              v54->r_boxcolor[1].x = 0.0;
              v54->r_boxcolor[0].y = 0.0;
              v54->r_boxcolor[0].z = 0.0;
              v54->r_boxcolor[1].y = 0.0;
              v54->r_boxcolor[1].z = 0.0;
              v54->r_boxcolor[2].x = 0.0;
              v54->r_boxcolor[2].y = 0.0;
              v54->r_boxcolor[2].z = 0.0;
              v54->r_boxcolor[3].x = 0.0;
              v54->r_boxcolor[3].y = 0.0;
              v54->r_boxcolor[3].z = 0.0;
              v54->r_boxcolor[4].x = 0.0;
              v54->r_boxcolor[4].y = 0.0;
              v54->r_boxcolor[4].z = 0.0;
              v54->r_boxcolor[5].x = 0.0;
              v54->r_boxcolor[5].y = 0.0;
              *(_QWORD *)&v54->r_boxcolor[5].z = 0;
              v52 = v156.m_pMemory;
            }
            HIWORD(v203) = v50;
            LOWORD(v203) = v207;
            v55 = v181;
            v48 = &v52[(__int16)v50];
            v56 = v181;
            if ( v181 + 1 > v178.m_nAllocationCount )
            {
              v197 = (LightcacheGetDynamic_Stats)(v181 - v178.m_nAllocationCount + 1);
              if ( v178.m_nGrowSize < 0 )
              {
                v178.m_nGrowSize = v179;
                if ( v178.m_nAllocationCount != 0 )
                {
                  v57 = _g_pMemAlloc->__vftable;
                  v202 = 4 * v178.m_nAllocationCount;
                  var3C.m_nAllocationCount = (int)v57->Alloc_2(this: _g_pMemAlloc, a2: 4 * v178.m_nAllocationCount);
                  memcpy(
                    dst: (unsigned __int8 *)var3C.m_nAllocationCount,
                    src: (unsigned __int8 *)v178.m_pMemory,
                    count: v202);
                  v178.m_pMemory = (S3RGBA *)var3C.m_nAllocationCount;
                }
                else
                {
                  v178.m_pMemory = nullptr;
                }
              }
              CUtlMemory<INetMessage *,int>::Grow(this: &v178, num: *(_DWORD *)&v197);
              v55 = v181;
            }
            v58 = v178.m_pMemory;
            v181 = v55 + 1;
            v59 = v55 - v56;
            v182 = v178.m_pMemory;
            if ( v59 > 0 )
            {
              _V_memmove(dest: &v178.m_pMemory[v56 + 1], src: &v178.m_pMemory[v56], count: 4 * v59);
              v58 = v178.m_pMemory;
            }
            v60 = (rmodel_t **)&v58[v56];
            if ( v60 != nullptr )
              *v60 = v203;
          }
          if ( ((unsigned __int8 (__stdcall *)(_DWORD))g_pShadowMgr->ModelHasShadows)(a1: LOWORD(v46->fade.iOriginalAlpha)) != 0 )
          {
            v61 = v187;
            v62 = v187;
            v202 = v187;
            if ( v187 + 1 > v184.m_nAllocationCount )
            {
              var3C.m_nAllocationCount = v187 - v184.m_nAllocationCount + 1;
              if ( v184.m_nGrowSize < 0 )
              {
                v184.m_nGrowSize = v185;
                if ( v184.m_nAllocationCount != 0 )
                {
                  v63 = 2 * v184.m_nAllocationCount;
                  v197 = (LightcacheGetDynamic_Stats)_g_pMemAlloc->Alloc_2(
                                                       this: _g_pMemAlloc,
                                                       a2: 2 * v184.m_nAllocationCount);
                  memcpy(dst: *(unsigned __int8 **)&v197, src: (unsigned __int8 *)v184.m_pMemory, count: v63);
                  v62 = v202;
                  v184.m_pMemory = (wchar_t *)v197;
                }
                else
                {
                  v184.m_pMemory = nullptr;
                }
              }
              CUtlMemory<wchar_t,int>::Grow(this: &v184, num: var3C.m_nAllocationCount);
              v61 = v187;
            }
            v64 = v184.m_pMemory;
            v187 = v61 + 1;
            v65 = v61 - v62;
            v188 = v184.m_pMemory;
            if ( v65 > 0 )
            {
              _V_memmove(dest: &v184.m_pMemory[v62 + 1], src: &v184.m_pMemory[v62], count: 2 * v65);
              v64 = v184.m_pMemory;
            }
            v66 = &v64[v62];
            if ( v66 != nullptr )
              *v66 = v207;
          }
          if ( HIBYTE(bShadowDepth) == 0 )
            goto LABEL_117;
          m_pCache = v205->m_pCache;
          v68 = m_pCache->__vftable;
          var3C.m_nAllocationCount = (int)v205->m_ModelInstances.m_Memory.m_pMemory[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_ColorMeshHandle;
          v69 = (int)v68->Get(this: m_pCache, a2: (memhandle_t__ *)var3C.m_nAllocationCount, a3: true);
          v70 = (_BYTE *)v69;
          if ( v69 != 0 && (*(_BYTE *)(v69 + 20) & 2) == 0 )
            goto LABEL_109;
          iOriginalAlpha = v46->fade.iOriginalAlpha;
          v71 = (IHandleEntity *)(**(int (__thiscall ***)(int))v46->pixelsIndent)(a1: v46->pixelsIndent);
          if ( CModelRender::UpdateStaticPropColorData(this: v205, pProp: v71, handle: iOriginalAlpha) )
            break;
          if ( v70 != nullptr && (v70[20] & 2) != 0 )
            goto LABEL_109;
LABEL_170:
          if ( ++v207 >= (int)v200 )
            goto LABEL_171;
        }
        v70 = v205->m_pCache->Get(this: v205->m_pCache, a2: var3C.m_nAllocationCount, a3: 1);
LABEL_109:
        if ( v70 != nullptr && (v70[20] & 1) != 0 )
        {
          v72 = *((_DWORD *)v70 + 1);
          v73 = (void (__thiscall ***)(_DWORD, _DWORD *))v198;
          *(_DWORD *)&v46->textClickable = v72;
          if ( v73 != nullptr && v205->m_pCache->Lock(this: v205->m_pCache, a2: var3C.m_nAllocationCount) != nullptr )
          {
            v74 = MemAlloc_Alloc(nSize: 0x1Cu);
            if ( v74 != nullptr )
            {
              v75 = v205;
              m_nAllocationCount = var3C.m_nAllocationCount;
              v74[3] = 1;
              *v74 = &CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
              v74[2] = &CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
              v74[5] = v75;
              v74[4] = CLoaderMemAlloc::CrtSetReportMode;
              v74[6] = m_nAllocationCount;
              (**v73)(a1: v73, a2: v74);
            }
            else
            {
              (**v73)(a1: v73, a2: nullptr);
            }
          }
        }
        else
        {
          HIBYTE(bShadowDepth) = 0;
        }
LABEL_117:
        if ( HIBYTE(v206) != 0 || HIBYTE(count) != 0 )
        {
          iOriginalAlpha_low = LOWORD(v46->fade.iOriginalAlpha);
          p_m_LightCacheHandle = nullptr;
          var3C.m_nAllocationCount = 0;
          if ( (_WORD)iOriginalAlpha_low != 0xFFFF )
          {
            v79 = v205->m_ModelInstances.m_Memory.m_pMemory;
            v80 = iOriginalAlpha_low;
            if ( (v79[v80].m_Element.m_nFlags & 1) != 0 && v79[v80].m_Element.m_LightCacheHandle != nullptr )
              p_m_LightCacheHandle = &v79[v80].m_Element.m_LightCacheHandle;
          }
          memset(&lightingState, 0, 76);
          if ( p_m_LightCacheHandle != nullptr )
          {
            if ( HIBYTE(bShadowDepth) == 0 || StaticLightCacheAffectedByDynamicLight(handle: *p_m_LightCacheHandle) )
            {
              v154 = 7;
              v152 = *p_m_LightCacheHandle;
            }
            else
            {
              v154 = 6;
              v152 = *p_m_LightCacheHandle;
            }
            Static = LightcacheGetStatic(
                       cache: v152,
                       pEnvCubemapTexture: (ITexture **)&var3C.m_nAllocationCount,
                       flags: v154);
            if ( v216 )
            {
              v82 = v205->m_ModelInstances.m_Memory.m_pMemory;
              p_m_flLightingTime = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v84 = Static->r_boxcolor[0].y + p_m_flLightingTime[25];
              v85 = Static->r_boxcolor[0].z + p_m_flLightingTime[26];
              v48->r_boxcolor[0].x = Static->r_boxcolor[0].x + p_m_flLightingTime[24];
              v48->r_boxcolor[0].y = v84;
              v48->r_boxcolor[0].z = v85;
              v86 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v87 = Static->r_boxcolor[1].y + v86[28];
              v88 = Static->r_boxcolor[1].z + v86[29];
              v48->r_boxcolor[1].x = v86[27] + Static->r_boxcolor[1].x;
              v48->r_boxcolor[1].y = v87;
              v48->r_boxcolor[1].z = v88;
              v89 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v90 = Static->r_boxcolor[2].y + v89[31];
              v91 = Static->r_boxcolor[2].z + v89[32];
              v48->r_boxcolor[2].x = v89[30] + Static->r_boxcolor[2].x;
              v48->r_boxcolor[2].y = v90;
              v48->r_boxcolor[2].z = v91;
              v92 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v93 = Static->r_boxcolor[3].y + v92[34];
              v94 = Static->r_boxcolor[3].z + v92[35];
              v48->r_boxcolor[3].x = v92[33] + Static->r_boxcolor[3].x;
              v48->r_boxcolor[3].y = v93;
              v48->r_boxcolor[3].z = v94;
              v95 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v96 = Static->r_boxcolor[4].y + v95[37];
              v97 = Static->r_boxcolor[4].z + v95[38];
              v48->r_boxcolor[4].x = v95[36] + Static->r_boxcolor[4].x;
              v48->r_boxcolor[4].y = v96;
              v48->r_boxcolor[4].z = v97;
              v98 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v99 = Static->r_boxcolor[5].y + v98[40];
              v100 = Static->r_boxcolor[5].z + v98[41];
              v48->r_boxcolor[5].x = v98[39] + Static->r_boxcolor[5].x;
              v48->r_boxcolor[5].y = v99;
              v48->r_boxcolor[5].z = v100;
              m_pLightingState = v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState;
              v48->numlights = m_pLightingState->m_AmbientLightingState.numlights;
              v102 = m_pLightingState->m_AmbientLightingState.numlights <= 0;
              bShadowDepth = 0;
              if ( !v102 )
              {
                v103 = (char *)&m_pLightingState->m_AmbientLightingState - (char *)v48;
                locallight = v48->locallight;
                for ( j = v103; ; v103 = j )
                {
                  *locallight = *(dworldlight_t **)((char *)locallight + v103);
                  ++locallight;
                  if ( ++bShadowDepth >= m_pLightingState->m_AmbientLightingState.numlights )
                    break;
                }
              }
              LightingState_t::AddAllLocalLights(
                this: v48,
                src: Static,
                vecLightingOrigin: (const Vector *)LODWORD(v46->fade.flFadeLength));
            }
          }
          else
          {
            flFadeLength = v46->fade.flFadeLength;
            v194[5] = *(_DWORD *)LODWORD(flFadeLength);
            v194[6] = *(_DWORD *)(LODWORD(flFadeLength) + 4);
            pixelsIndent = (const IClientRenderable *)v46->pixelsIndent;
            v194[7] = *(_DWORD *)(LODWORD(flFadeLength) + 8);
            var3C.m_nAllocationCount = (int)LightcacheGetDynamic(
                                              origin: (const Vector *)&v194[5],
                                              &lightingState,
                                              &stats,
                                              pRenderable: pixelsIndent,
                                              flags: HIBYTE(bShadowDepth) != 0 ? 6 : 15,
                                              bDebugModel: false);
            Static = &lightingState;
            if ( v216 )
              LightcacheGetDynamic(
                origin: (const Vector *)&v194[5],
                lightingState: v48,
                stats: &v193,
                pRenderable: (const IClientRenderable *)v46->pixelsIndent,
                flags: 0xFu,
                bDebugModel: false);
          }
          if ( HIBYTE(count) != 0 && var3C.m_nAllocationCount != 0 )
            LODWORD(v46->fade.flFadeStartTime) = var3C.m_nAllocationCount;
          if ( HIBYTE(v206) != 0 )
          {
            if ( Static->numlights == 0 )
            {
              v107 = 0;
              p_z = &Static->r_boxcolor[0].z;
              while ( 1 )
              {
                v109 = *(p_z - 2);
                if ( v109 <= -0.000099999997 )
                  break;
                if ( v109 >= 0.000099999997 )
                  break;
                v110 = *(p_z - 1);
                if ( v110 <= -0.000099999997
                  || v110 >= 0.000099999997
                  || *p_z <= -0.000099999997
                  || *p_z >= 0.000099999997 )
                {
                  break;
                }
                ++v107;
                p_z += 3;
                if ( v107 >= 6 )
                  goto LABEL_170;
              }
            }
            v111 = v157;
            v112 = v157;
            bShadowDepth = v157;
            if ( v157 + 1 > v156.m_nAllocationCount )
            {
              v212 = v157 - v156.m_nAllocationCount + 1;
              if ( v156.m_nGrowSize < 0 )
              {
                v156.m_nGrowSize = v156.m_nMallocGrowSize;
                if ( v156.m_nAllocationCount != 0 )
                {
                  v113 = 92 * v156.m_nAllocationCount;
                  count = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 92 * v156.m_nAllocationCount);
                  memcpy(dst: (unsigned __int8 *)count, src: (unsigned __int8 *)v156.m_pMemory, count: v113);
                  v156.m_pMemory = (LightingState_t *)count;
                }
                else
                {
                  v156.m_pMemory = nullptr;
                }
              }
              CUtlMemory<SoundInfo_t,int>::Grow(this: &v156, num: v212);
              v111 = v157;
              v112 = bShadowDepth;
            }
            v114 = v156.m_pMemory;
            v157 = v111 + 1;
            v115 = v111 - v112;
            m_pMemory = v156.m_pMemory;
            if ( v115 > 0 )
            {
              _V_memmove(dest: &v156.m_pMemory[bShadowDepth + 1], src: &v156.m_pMemory[bShadowDepth], count: 92 * v115);
              v114 = v156.m_pMemory;
              v112 = bShadowDepth;
            }
            v116 = &v114[v112];
            if ( v116 != nullptr )
              qmemcpy(v116, Static, sizeof(LightingState_t));
            LOWORD(v46->textStreamIndex) = v112;
            v117 = v165;
            v118 = v165;
            if ( v165 + 1 > v162.m_nAllocationCount )
            {
              bShadowDepth = v165 - v162.m_nAllocationCount + 1;
              if ( v162.m_nGrowSize < 0 )
              {
                v162.m_nGrowSize = v163;
                if ( v162.m_nAllocationCount != 0 )
                {
                  v119 = 2 * v162.m_nAllocationCount;
                  v120 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2 * v162.m_nAllocationCount);
                  memcpy(dst: v120, src: (unsigned __int8 *)v162.m_pMemory, count: v119);
                  v162.m_pMemory = (wchar_t *)v120;
                }
                else
                {
                  v162.m_pMemory = nullptr;
                }
              }
              CUtlMemory<wchar_t,int>::Grow(this: &v162, num: bShadowDepth);
              v117 = v165;
            }
            v121 = v162.m_pMemory;
            v165 = v117 + 1;
            v122 = v117 - v118;
            v166 = v162.m_pMemory;
            if ( v122 > 0 )
            {
              _V_memmove(dest: &v162.m_pMemory[v118 + 1], src: &v162.m_pMemory[v118], count: 2 * v122);
              v121 = v162.m_pMemory;
            }
            v123 = &v121[v118];
            if ( v123 != nullptr )
              *v123 = v207;
          }
        }
        goto LABEL_170;
      }
    }
LABEL_171:
    v190[2] = 1065353216;
    v190[1] = 1065353216;
    v190[0] = 1065353216;
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)v190);
    ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: 1.0);
    g_pStudioRender->SetViewState(
      this: g_pStudioRender,
      a2: &g_CurrentViewOrigin,
      a3: &g_CurrentViewRight,
      a4: &g_CurrentViewUp,
      a5: &g_CurrentViewForward);
    v124 = var3C.m_pMemory;
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *, int))(*(_DWORD *)&var3C.m_pMemory->color + 80))(
      a1: var3C.m_pMemory,
      a2: 10);
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *))(*(_DWORD *)&v124->color + 84))(a1: v124);
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *))(*(_DWORD *)&v124->color + 124))(a1: v124);
    g_pStudioRender->ClearAllShadows(this: g_pStudioRender);
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *))(*(_DWORD *)&v124->color + 504))(a1: v124);
    memset(v177, 0, 72);
    g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)v177);
    v177[21] = 0;
    v176 = 0;
    m_DecalHandle = nullptr;
    v171 = 0;
    v172 = 0;
    v194[5] = (*(int (__thiscall **)(vgui::RichText::TFormatStream *, int))(*(_DWORD *)&v124->color + 392))(
                a1: v124,
                a2: 3072);
    v125 = 0;
    count = -1;
    bShadowDepth = 0;
    flFadeSustain_high = 0;
    if ( (int)v200 > 0 )
    {
      v126 = (__int16 *)&v199.m_pMemory->fade.iOriginalAlpha + 1;
      for ( k = v200; k != 0; --k )
      {
        if ( v126[1] < 0 )
        {
          v127 = *(v126 - 3);
          v128 = &v160.m_Memory.m_pMemory[v127];
          v198 = (int)v128;
          if ( count != v127 || iOriginalAlpha_high != *v126 || *(v126 - 2) != flFadeSustain_high || v125 >= 64 )
          {
            if ( v125 > 0 )
            {
              g_pStudioRender->DrawModelArrayStaticProp(
                this: g_pStudioRender,
                a2: (const DrawModelInfo_t *)&pStudioHdr,
                a3: v125,
                a4: (const MeshInstanceData_t *)v155,
                a5: (ColorMeshInfo_t **)v161);
              if ( v194[5] != 0 )
                (*(void (__thiscall **)(vgui::RichText::TFormatStream *, _DWORD))(*(_DWORD *)&v124->color + 396))(
                  a1: v124,
                  a2: v194[5]);
              v129 = (*(int (__thiscall **)(vgui::RichText::TFormatStream *, int))(*(_DWORD *)&v124->color + 392))(
                       a1: v124,
                       a2: 3072);
              v128 = (rmodel_t *)v198;
              v194[5] = v129;
            }
            pStudioHdr = v128->pStudioHdr;
            v168 = v128->pStudioHWData;
            iOriginalAlpha_high = *v126;
            v173 = *(_DWORD *)(v126 - 11);
            flFadeSustain_high = *(v126 - 2);
            v130 = *(v126 - 3);
            bShadowDepth = 0;
            count = v130;
          }
          v131 = bShadowDepth;
          v132 = (unsigned __int8 *)&v155[19 * bShadowDepth];
          memset(dst: v132, value: 0, count: 0x4Cu);
          v133 = v194[5] + 48 * v131;
          *((_DWORD *)v132 + 2) = 1;
          *((_DWORD *)v132 + 4) = v133;
          *((_DWORD *)v132 + 5) = *(_DWORD *)(v126 - 7);
          (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(v126 - 11) + 44))(
            a1: *(_DWORD *)(v126 - 11),
            a2: (_DWORD *)v132 + 14);
          v134 = bShadowDepth;
          *((float *)v132 + 17) = (float)*((unsigned __int8 *)v126 + 4) * 0.0039215689;
          qmemcpy(*((void **)v132 + 4), *(const void **)(v126 - 13), 0x30u);
          v124 = var3C.m_pMemory;
          ++v134;
          *((_DWORD *)&v160.m_pElements + v134) = *(_DWORD *)(v126 - 9);
          bShadowDepth = v134;
          v125 = v134;
        }
        v126 += 16;
      }
      if ( v125 > 0 )
        g_pStudioRender->DrawModelArrayStaticProp(
          this: g_pStudioRender,
          a2: (const DrawModelInfo_t *)&pStudioHdr,
          a3: v125,
          a4: (const MeshInstanceData_t *)v155,
          a5: (ColorMeshInfo_t **)v161);
    }
    if ( v194[5] != 0 )
      (*(void (__thiscall **)(vgui::RichText::TFormatStream *, _DWORD))(*(_DWORD *)&v124->color + 396))(
        a1: v124,
        a2: v194[5]);
    count = 0;
    v196[0] = 1065353216;
    v196[1] = 1065353216;
    v196[2] = 1065353216;
    if ( v165 != 0 )
    {
      v135 = 0;
      for ( bShadowDepth = 0; v135 < v165; bShadowDepth = v135 )
      {
        v136 = &v199.m_pMemory[(__int16)v162.m_pMemory[v135]];
        flFadeStartTime = v136->fade.flFadeStartTime;
        v214 = &v160.m_Memory.m_pMemory[SLOWORD(v136->fade.flFadeSustain)];
        if ( flFadeStartTime != 0.0 )
          (*(void (__thiscall **)(vgui::RichText::TFormatStream *, float))(*(_DWORD *)&var3C.m_pMemory->color + 20))(
            a1: var3C.m_pMemory,
            a2: COERCE_FLOAT(LODWORD(flFadeStartTime)));
        v138 = &v156.m_pMemory[SLOWORD(v136->textStreamIndex)];
        g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)v138);
        (*(void (__thiscall **)(vgui::RichText::TFormatStream *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)&var3C.m_pMemory->color
                                                                                        + 592))(
          a1: var3C.m_pMemory,
          a2: *(_DWORD *)LODWORD(v136->fade.flFadeLength),
          a3: *(_DWORD *)(LODWORD(v136->fade.flFadeLength) + 4),
          a4: *(_DWORD *)(LODWORD(v136->fade.flFadeLength) + 8));
        R_SetNonAmbientLightingState(
          numLights: v138->numlights,
          locallight: v138->locallight,
          pNumLightDescs: &count,
          &pLightDescs,
          bUpdateStudioRenderLights: true);
        (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v136->pixelsIndent + 44))(a1: v136->pixelsIndent, a2: v196);
        g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)v196);
        pStudioHdr = v214->pStudioHdr;
        v168 = v214->pStudioHWData;
        iOriginalAlpha_high = SHIWORD(v136->fade.iOriginalAlpha);
        v173 = v136->pixelsIndent;
        flFadeSustain_high = SHIWORD(v136->fade.flFadeSustain);
        v175 = *(_DWORD *)&v136->textClickable;
        g_pStudioRender->DrawModelStaticProp(
          this: g_pStudioRender,
          a2: (const DrawModelInfo_t *)&pStudioHdr,
          a3: *(const matrix3x4_t **)&v136->color,
          a4: 8);
        v135 = bShadowDepth + 1;
      }
    }
    v139 = 0;
    if ( !g_pShadowMgr->SinglePassFlashlightModeEnabled(this: g_pShadowMgr) && v187 != 0 )
    {
      if ( v187 > 0 )
      {
        do
        {
          v140 = &v199.m_pMemory[(__int16)v184.m_pMemory[v139]];
          v141 = &v160.m_Memory.m_pMemory[SLOWORD(v140->fade.flFadeSustain)];
          ((void (__stdcall *)(_DWORD))g_pShadowMgr->SetModelShadowState)(a1: LOWORD(v140->fade.iOriginalAlpha));
          (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v140->pixelsIndent + 44))(a1: v140->pixelsIndent, a2: v196);
          g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)v196);
          pStudioHdr = v141->pStudioHdr;
          v168 = v141->pStudioHWData;
          iOriginalAlpha_high = SHIWORD(v140->fade.iOriginalAlpha);
          v173 = v140->pixelsIndent;
          flFadeSustain_high = SHIWORD(v140->fade.flFadeSustain);
          v175 = *(_DWORD *)&v140->textClickable;
          g_pStudioRender->DrawStaticPropShadows(
            this: g_pStudioRender,
            a2: (const DrawModelInfo_t *)&pStudioHdr,
            a3: *(const matrix3x4_t **)&v140->color,
            a4: 0);
          ++v139;
        }
        while ( v139 < v187 );
      }
      g_pStudioRender->ClearAllShadows(this: g_pStudioRender);
    }
    for ( m = 0; m < v181; ++m )
    {
      v144 = &v199.m_pMemory[*(__int16 *)&v178.m_pMemory[m].b];
      v143 = &v156.m_pMemory[*(__int16 *)&v178.m_pMemory[m].r];
      v215 = &v160.m_Memory.m_pMemory[SLOWORD(v144->fade.flFadeSustain)];
      g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)v143);
      (*(void (__thiscall **)(vgui::RichText::TFormatStream *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)&var3C.m_pMemory->color
                                                                                      + 592))(
        a1: var3C.m_pMemory,
        a2: *(_DWORD *)LODWORD(v144->fade.flFadeLength),
        a3: *(_DWORD *)(LODWORD(v144->fade.flFadeLength) + 4),
        a4: *(_DWORD *)(LODWORD(v144->fade.flFadeLength) + 8));
      R_SetNonAmbientLightingState(
        numLights: v143->numlights,
        locallight: v143->locallight,
        pNumLightDescs: &count,
        &pLightDescs,
        bUpdateStudioRenderLights: true);
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v144->pixelsIndent + 44))(a1: v144->pixelsIndent, a2: v196);
      g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)v196);
      pStudioHdr = v215->pStudioHdr;
      v168 = v215->pStudioHWData;
      m_DecalHandle = v205->m_ModelInstances.m_Memory.m_pMemory[LOWORD(v144->fade.iOriginalAlpha)].m_Element.m_DecalHandle;
      iOriginalAlpha_high = SHIWORD(v144->fade.iOriginalAlpha);
      v173 = v144->pixelsIndent;
      flFadeSustain_high = SHIWORD(v144->fade.flFadeSustain);
      v175 = *(_DWORD *)&v144->textClickable;
      g_pStudioRender->DrawStaticPropDecals(
        this: g_pStudioRender,
        a2: (const DrawModelInfo_t *)&pStudioHdr,
        a3: *(const matrix3x4_t **)&v144->color);
    }
    v145 = var3C.m_pMemory;
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *, int))(*(_DWORD *)&var3C.m_pMemory->color + 80))(
      a1: var3C.m_pMemory,
      a2: 10);
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *))(*(_DWORD *)&v145->color + 88))(a1: v145);
    v146 = v156.m_pMemory;
    v157 = 0;
    if ( v156.m_nGrowSize >= 0 )
    {
      if ( v156.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v156.m_pMemory);
        v146 = nullptr;
        v156.m_pMemory = nullptr;
      }
      v156.m_nAllocationCount = 0;
    }
    m_pMemory = v146;
    if ( v156.m_nGrowSize >= 0 )
    {
      if ( v146 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v146);
        v156.m_pMemory = nullptr;
      }
      v156.m_nAllocationCount = 0;
    }
    v147 = v178.m_pMemory;
    v181 = 0;
    if ( v178.m_nGrowSize >= 0 )
    {
      if ( v178.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v178.m_pMemory);
        v147 = nullptr;
        v178.m_pMemory = nullptr;
      }
      v178.m_nAllocationCount = 0;
    }
    v182 = v147;
    if ( v178.m_nGrowSize >= 0 )
    {
      if ( v147 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v147);
        v178.m_pMemory = nullptr;
      }
      v178.m_nAllocationCount = 0;
    }
    v148 = v184.m_pMemory;
    v187 = 0;
    if ( v184.m_nGrowSize >= 0 )
    {
      if ( v184.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v184.m_pMemory);
        v148 = nullptr;
        v184.m_pMemory = nullptr;
      }
      v184.m_nAllocationCount = 0;
    }
    v188 = v148;
    if ( v184.m_nGrowSize >= 0 )
    {
      if ( v148 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v148);
        v184.m_pMemory = nullptr;
      }
      v184.m_nAllocationCount = 0;
    }
    v149 = v162.m_pMemory;
    v165 = 0;
    if ( v162.m_nGrowSize >= 0 )
    {
      if ( v162.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v162.m_pMemory);
        v149 = nullptr;
        v162.m_pMemory = nullptr;
      }
      v162.m_nAllocationCount = 0;
    }
    v166 = v149;
    if ( v162.m_nGrowSize >= 0 )
    {
      if ( v149 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v149);
        v162.m_pMemory = nullptr;
      }
      v162.m_nAllocationCount = 0;
    }
    v150 = v160.m_Memory.m_pMemory;
    v160.m_Size = 0;
    if ( v160.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v160.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v160.m_Memory.m_pMemory);
        v150 = nullptr;
        v160.m_Memory.m_pMemory = nullptr;
      }
      v160.m_Memory.m_nAllocationCount = 0;
    }
    v160.m_pElements = v150;
    if ( v160.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v150 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v150);
        v160.m_Memory.m_pMemory = nullptr;
      }
      v160.m_Memory.m_nAllocationCount = 0;
    }
    if ( v199.m_nGrowSize >= 0 && v199.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v199.m_pMemory);
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *))(*(_DWORD *)&v145->color + 12))(a1: v145);
    (*(void (__thiscall **)(vgui::RichText::TFormatStream *))(*(_DWORD *)&v145->color + 4))(a1: v145);
    v191->EndLock(this: v191);
    return v195;
  }
  v30 = var3C.m_pMemory;
  goto LABEL_60;
}

//------------------------------------------------------------------------------
// Address: 0x1019F4F0
// Name: void R_InitStudio(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl R_InitStudio()
{
  R_StudioInitLightingCache();
}

//------------------------------------------------------------------------------
// Address: 0x103155E0
// Name: _dynamic_initializer_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CModelRender::ModelInstanceLightingState_t::s_Allocator,
    blockSize: 236,
    numElements: 100,
    growMode: 2,
    pszAllocOwner: "CModelRender::ModelInstanceLightingState_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x10323400
// Name: _dynamic_atexit_destructor_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CModelRender::ModelInstanceLightingState_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x103234B0
// Name: _CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlodbias__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlodbias__()
{
  ConVar::~ConVar(this: &r_shadowlodbias);
}

//------------------------------------------------------------------------------
// Address: 0x103234C0
// Name: _CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlod__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlod__()
{
  ConVar::~ConVar(this: &r_shadowlod);
}

//------------------------------------------------------------------------------
// Address: 0x100DA9F0
// Name: __CreateCModelRenderIVModelRender_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CModelRender *__cdecl _CreateCModelRenderIVModelRender_interface()
{
  return &s_ModelRender;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100D9E50
// Name: public: void LightingState_t::CopyLocalLights(struct LightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightingState_t::CopyLocalLights(LightingState_t *this, const LightingState_t *src)
{
  int v2; // edx
  dworldlight_t **locallight; // eax

  v2 = 0;
  this->numlights = src->numlights;
  if ( src->numlights > 0 )
  {
    locallight = this->locallight;
    do
    {
      *locallight = *(dworldlight_t **)((char *)locallight + (char *)src - (char *)this);
      ++v2;
      ++locallight;
    }
    while ( v2 < src->numlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9EC0
// Name: bool WorldLightToMaterialLight(struct dworldlight_t __near *,struct LightDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WorldLightToMaterialLight(dworldlight_t *pWorldLight, LightDesc_t *light)
{
  emittype_t type; // eax
  double radius; // st7
  float linear_attn; // xmm2_4
  float quadratic_attn; // xmm4_4
  float exponent; // xmm0_4
  float constant_attn; // xmm3_4
  float v10; // xmm1_4
  long double v11; // st7
  unsigned int v12; // ecx
  float discrim; // [esp+0h] [ebp-8h]
  float discrima; // [esp+0h] [ebp-8h]
  float discrimb; // [esp+0h] [ebp-8h]
  float flAttenuation2; // [esp+4h] [ebp-4h]
  float flAttenuation1; // [esp+10h] [ebp+8h]
  float flAttenuation1a; // [esp+10h] [ebp+8h]

  type = pWorldLight->type;
  if ( type == emit_surface )
  {
    light->m_Type = MATERIAL_LIGHT_SPOT;
    light->m_Color = pWorldLight->intensity;
    light->m_Position = pWorldLight->origin;
    light->m_Direction = pWorldLight->normal;
    radius = pWorldLight->radius;
    light->m_Falloff = 1.0;
    light->m_Range = radius;
    light->m_Attenuation0 = 0.0;
    light->m_Attenuation1 = 0.0;
    light->m_Attenuation2 = 1.0;
    light->m_Theta = 1.5707964;
    light->m_Phi = 1.5707964;
    light->m_ThetaDot = 0.0;
    light->m_PhiDot = 0.0;
    light->m_OneOverThetaDotMinusPhiDot = 1.0;
    light->m_Flags = 12;
    return 1;
  }
  linear_attn = 0.0;
  quadratic_attn = 0.0;
  flAttenuation1 = 0.0;
  flAttenuation2 = 0.0;
  light->m_OneOverThetaDotMinusPhiDot = 1.0;
  switch ( type )
  {
    case emit_point:
      light->m_Type = MATERIAL_LIGHT_POINT;
      linear_attn = pWorldLight->linear_attn;
      quadratic_attn = pWorldLight->quadratic_attn;
      constant_attn = pWorldLight->constant_attn;
      flAttenuation1 = linear_attn;
      flAttenuation2 = quadratic_attn;
      goto LABEL_7;
    case emit_spotlight:
      light->m_Type = MATERIAL_LIGHT_SPOT;
      discrim = pWorldLight->constant_attn;
      flAttenuation1 = pWorldLight->linear_attn;
      flAttenuation2 = pWorldLight->quadratic_attn;
      light->m_Theta = acos(pWorldLight->stopdot);
      light->m_Phi = acos(pWorldLight->stopdot2);
      light->m_ThetaDot = pWorldLight->stopdot;
      light->m_PhiDot = pWorldLight->stopdot2;
      exponent = pWorldLight->exponent;
      if ( exponent == 0.0 )
        exponent = 1.0;
      light->m_Falloff = exponent;
      LightDesc_t::RecalculateOneOverThetaDotMinusPhiDot(this: light);
      quadratic_attn = flAttenuation2;
      linear_attn = flAttenuation1;
      constant_attn = discrim;
LABEL_7:
      if ( constant_attn == 0.0 && linear_attn == 0.0 && quadratic_attn == 0.0 )
        goto LABEL_10;
      goto LABEL_11;
    case emit_skylight:
      light->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
      goto LABEL_10;
    case emit_quakelight:
    case emit_skyambient:
      return 0;
    default:
LABEL_10:
      constant_attn = 1.0;
LABEL_11:
      light->m_Color = pWorldLight->intensity;
      light->m_Position = pWorldLight->origin;
      light->m_Direction = pWorldLight->normal;
      v10 = pWorldLight->radius;
      if ( v10 != 0.0 )
        goto LABEL_23;
      discrima = sqrt(
                   light->m_Color.x * light->m_Color.x
                 + light->m_Color.y * light->m_Color.y
                 + light->m_Color.z * light->m_Color.z);
      if ( quadratic_attn == 0.0 )
      {
        if ( linear_attn != 0.0 )
        {
          v10 = (float)((float)(discrima * 33.333336) - constant_attn) / linear_attn;
          goto LABEL_23;
        }
        goto LABEL_21;
      }
      discrimb = (float)(linear_attn * linear_attn)
               - (float)((float)(constant_attn - (float)(discrima * 33.333336)) * (float)(quadratic_attn * 4.0));
      if ( discrimb < 0.0 )
      {
LABEL_21:
        flAttenuation1a = sqrt(3.402823466385289e38);
        goto LABEL_22;
      }
      v11 = (sqrt(discrimb) - flAttenuation1) / (flAttenuation2 + flAttenuation2);
      flAttenuation1a = v11;
      if ( v11 < 0.0 )
      {
        v10 = 0.0;
        goto LABEL_23;
      }
LABEL_22:
      v10 = flAttenuation1a;
LABEL_23:
      v12 = 8;
      if ( constant_attn != 0.0 )
        v12 = 9;
      if ( linear_attn != 0.0 )
        v12 |= 2u;
      if ( quadratic_attn != 0.0 )
        v12 |= 4u;
      light->m_Attenuation0 = constant_attn;
      light->m_Attenuation1 = linear_attn;
      light->m_Attenuation2 = quadratic_attn;
      light->m_Range = v10;
      light->m_Flags = v12;
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA1D0
// Name: float Engine_WorldLightDistanceFalloff(struct dworldlight_t const __near *,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Engine_WorldLightDistanceFalloff(const dworldlight_t *wl, const Vector *delta, bool bNoRadiusCheck)
{
  double result; // st7
  float v4; // xmm1_4
  float radius; // xmm0_4
  float v6; // [esp-4h] [ebp-10h]

  switch ( wl->type )
  {
    case emit_surface:
      if ( wl->radius != 0.0
        && (float)((float)((float)(delta->x * delta->x) + (float)(delta->y * delta->y)) + (float)(delta->z * delta->z)) > (float)(wl->radius * wl->radius) )
      {
        goto LABEL_4;
      }
      if ( (float)((float)((float)(delta->y * delta->y) + (float)(delta->x * delta->x)) + (float)(delta->z * delta->z)) >= 1.0 )
        result = 1.0 / (delta->z * delta->z + delta->y * delta->y + (float)(delta->x * delta->x));
      else
        result = 1.0 / 1.0;
      break;
    case emit_point:
    case emit_spotlight:
      v4 = fsqrt((float)((float)(delta->y * delta->y) + (float)(delta->x * delta->x)) + (float)(delta->z * delta->z));
      if ( !bNoRadiusCheck )
      {
        radius = wl->radius;
        if ( radius != 0.0 && v4 > radius )
          goto LABEL_4;
      }
      result = 1.0
             / (wl->linear_attn * v4
              + wl->constant_attn
              + wl->quadratic_attn
              * (float)((float)((float)(delta->y * delta->y) + (float)(delta->x * delta->x))
                      + (float)(delta->z * delta->z)));
      break;
    case emit_quakelight:
      v6 = wl->linear_attn
         - fsqrt((float)((float)(delta->x * delta->x) + (float)(delta->y * delta->y)) + (float)(delta->z * delta->z));
      if ( v6 < 0.0 )
LABEL_4:
        result = 0.0;
      else
        result = v6;
      break;
    default:
      result = 1.0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DA3B0
// Name: float Engine_WorldLightAngle(struct dworldlight_t const __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Engine_WorldLightAngle(
        const dworldlight_t *wl,
        const Vector *lnormal,
        const Vector *snormal,
        const Vector *delta)
{
  double v5; // st7
  double result; // st7
  float y; // xmm2_4
  float z; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float stopdot; // xmm2_4
  float exponent; // xmm3_4
  float dot2; // [esp+8h] [ebp-4h]
  float ratio; // [esp+14h] [ebp+8h]

  switch ( wl->type )
  {
    case emit_surface:
      ratio = (float)((float)(snormal->y * delta->y) + (float)(delta->x * snormal->x)) + (float)(snormal->z * delta->z);
      if ( ratio >= 0.0 )
      {
        v5 = -(lnormal->y * delta->y + lnormal->x * delta->x + lnormal->z * delta->z);
        if ( v5 > 0.01 )
          goto LABEL_13;
      }
      goto LABEL_4;
    case emit_point:
    case emit_quakelight:
      ratio = (float)((float)(snormal->y * delta->y) + (float)(snormal->x * delta->x)) + (float)(snormal->z * delta->z);
      if ( ratio >= 0.0 )
        goto LABEL_6;
      goto LABEL_4;
    case emit_spotlight:
      y = delta->y;
      z = delta->z;
      v9 = (float)((float)(snormal->y * y) + (float)(delta->x * snormal->x)) + (float)(snormal->z * z);
      ratio = v9;
      if ( v9 < 0.0 )
        goto LABEL_4;
      LODWORD(v10) = COERCE_UNSIGNED_INT((float)((float)(lnormal->y * y) + (float)(lnormal->x * delta->x)) + (float)(lnormal->z * z))
                   ^ _mask__NegFloat_;
      if ( wl->stopdot2 >= v10 )
        goto LABEL_4;
      stopdot = wl->stopdot;
      if ( v10 >= stopdot )
      {
LABEL_6:
        result = ratio;
      }
      else
      {
        exponent = wl->exponent;
        if ( exponent == 1.0 || exponent == 0.0 )
        {
          result = (float)((float)((float)(v10 - wl->stopdot2) / (float)(stopdot - wl->stopdot2)) * v9);
        }
        else
        {
          v5 = pow((v10 - wl->stopdot2) / (wl->stopdot - wl->stopdot2), wl->exponent);
LABEL_13:
          result = v5 * ratio;
        }
      }
      break;
    case emit_skylight:
      LODWORD(dot2) = COERCE_UNSIGNED_INT(
                        (float)((float)(lnormal->y * snormal->y) + (float)(lnormal->x * snormal->x))
                      + (float)(lnormal->z * snormal->z))
                    ^ _mask__NegFloat_;
      if ( dot2 < 0.0 )
        goto LABEL_4;
      result = dot2;
      break;
    case emit_skyambient:
      return 1.0;
    default:
LABEL_4:
      result = 0.0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DA5F0
// Name: public: virtual void CModelRender::SuppressEngineLighting(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SuppressEngineLighting(CModelRender *this, bool bSuppress)
{
  this->m_bSuppressEngineLighting = bSuppress;
}

//------------------------------------------------------------------------------
// Address: 0x100DA600
// Name: public: virtual bool CModelRender::GetItemName(unsigned int,void const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelRender::GetItemName(
        CModelRender *this,
        unsigned int clientId,
        char *pItem,
        char *pDest,
        unsigned int nMaxLen)
{
  g_pFileSystem->String(this: g_pFileSystem, a2: (void *const *)(pItem + 24), a3: pDest, a4: nMaxLen);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DA630
// Name: public: struct LightingState_t __near & LightingState_t::operator=(struct LightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
LightingState_t *__thiscall LightingState_t::operator=(LightingState_t *this, const LightingState_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DA6D0
// Name: public: virtual void CModelRender::SetupLighting(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetupLighting(CModelRender *this, const Vector *vecCenter)
{
  this->SetupLightingEx(this, a2: vecCenter, a3: 0xFFFFu);
}

//------------------------------------------------------------------------------
// Address: 0x100DA6F0
// Name: private: void CModelRender::SetFullbrightLightingState(int,struct MaterialLightingState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetFullbrightLightingState(
        CModelRender *this,
        int nCount,
        MaterialLightingState_t *pState)
{
  int v3; // ecx
  float *p_z; // eax

  v3 = nCount;
  if ( nCount > 0 )
  {
    p_z = &pState->m_vecAmbientCube[1].z;
    do
    {
      p_z[16] = 0.0;
      *(p_z - 5) = 1.0;
      *(p_z - 4) = 1.0;
      *(p_z - 3) = 1.0;
      *(p_z - 2) = 1.0;
      *(p_z - 1) = 1.0;
      *p_z = 1.0;
      p_z[1] = 1.0;
      p_z[2] = 1.0;
      p_z[3] = 1.0;
      p_z[4] = 1.0;
      p_z[5] = 1.0;
      p_z[6] = 1.0;
      p_z[7] = 1.0;
      p_z[8] = 1.0;
      p_z[9] = 1.0;
      p_z[10] = 1.0;
      p_z[11] = 1.0;
      p_z[12] = 1.0;
      p_z += 110;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA780
// Name: public: virtual bool CModelRender::GetBrightestShadowingLightSource(class Vector const __near &,class Vector __near &,class Vector __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelRender::GetBrightestShadowingLightSource(
        CModelRender *this,
        const Vector *vecCenter,
        Vector *lightPos,
        Vector *lightBrightness,
        bool bAllowNonTaggedLights)
{
  float y; // ecx
  float z; // edx
  int v8; // esi
  float v9; // xmm4_4
  int v10; // ebx
  float v11; // xmm5_4
  dworldlight_t *v12; // eax
  float v13; // xmm1_4
  double v14; // st7
  double v15; // st7
  dworldlight_t *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  LightcacheGetDynamic_Stats stats; // [esp+14h] [ebp-84h] BYREF
  LightingState_t state; // [esp+18h] [ebp-80h] BYREF
  Vector delta; // [esp+74h] [ebp-24h] BYREF
  float fBrightness; // [esp+80h] [ebp-18h]
  float fLightFalloff; // [esp+84h] [ebp-14h]
  Vector vc; // [esp+88h] [ebp-10h] BYREF
  float fMaxBrightness; // [esp+94h] [ebp-4h]
  float fFalloff; // [esp+A0h] [ebp+8h]
  float fFalloffa; // [esp+A0h] [ebp+8h]

  y = vecCenter->y;
  z = vecCenter->z;
  vc.x = vecCenter->x;
  v8 = 0;
  memset(&state, 0, 76);
  vc.y = y;
  vc.z = z;
  vc.x = floor(X: vc.x * 100.0 + 0.5) * 0.0099999998;
  vc.y = floor(X: vc.y * 100.0 + 0.5) * 0.0099999998;
  vc.z = floor(X: vc.z * 100.0 + 0.5) * 0.0099999998;
  LightcacheGetDynamic(
    a1: 0.0,
    origin: &vc,
    lightingState: &state,
    &stats,
    pRenderable: nullptr,
    flags: 1,
    bDebugModel: false);
  v9 = 0.0;
  v10 = -1;
  v11 = 0.0;
  fMaxBrightness = 0.0;
  fLightFalloff = 0.0;
  if ( (_S5_0 & 1) == 0 )
  {
    _S5_0 |= 1u;
    colorToGray.x = 0.30000001;
    colorToGray.y = 0.58999997;
    colorToGray.z = 0.11;
  }
  if ( state.numlights <= 0 )
    return 0;
  do
  {
    v12 = state.locallight[v8];
    if ( (v12->flags & 2) != 0 || bAllowNonTaggedLights )
    {
      v13 = vecCenter->z;
      if ( v13 <= (float)(v12->shadow_cast_offset.z + v12->origin.z) )
      {
        fBrightness = (float)((float)(v12->intensity.y * colorToGray.y) + (float)(colorToGray.x * v12->intensity.x))
                    + (float)(v12->intensity.z * colorToGray.z);
        if ( v11 < fBrightness )
        {
          delta.x = v12->origin.x - vecCenter->x;
          delta.y = v12->origin.y - vecCenter->y;
          delta.z = v12->origin.z - v13;
          v14 = Engine_WorldLightDistanceFalloff(wl: v12, &delta, bNoRadiusCheck: false);
          fFalloff = v14;
          if ( fMaxBrightness < v14 * fBrightness )
          {
            VectorNormalize(vec: &delta);
            v15 = Engine_WorldLightAngle(
                    wl: state.locallight[v8],
                    lnormal: &state.locallight[v8]->normal,
                    snormal: &delta,
                    &delta);
            v11 = fMaxBrightness;
            fFalloffa = v15 * fFalloff;
            v9 = fFalloffa;
            if ( (float)(fFalloffa * fBrightness) <= fMaxBrightness )
            {
              v9 = fLightFalloff;
            }
            else
            {
              v11 = fFalloffa * fBrightness;
              v10 = v8;
              fMaxBrightness = fFalloffa * fBrightness;
              fLightFalloff = fFalloffa;
            }
          }
        }
      }
    }
    ++v8;
  }
  while ( v8 < state.numlights );
  if ( v10 <= -1 )
    return 0;
  v16 = state.locallight[v10];
  v17 = v16->shadow_cast_offset.y + v16->origin.y;
  v18 = v16->shadow_cast_offset.z + v16->origin.z;
  lightPos->x = v16->shadow_cast_offset.x + v16->origin.x;
  lightPos->y = v17;
  lightPos->z = v18;
  v19 = v16->intensity.y;
  v20 = v16->intensity.z;
  lightBrightness->x = v16->intensity.x * v9;
  lightBrightness->y = v19 * v9;
  lightBrightness->z = v20 * v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DAA70
// Name: public: virtual void CModelRender::ForcedMaterialOverride(class IMaterial __near *,enum OverrideType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ForcedMaterialOverride(
        CModelRender *this,
        IMaterial *newMaterial,
        OverrideType_t nOverrideType)
{
  g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: newMaterial, a3: nOverrideType);
}

//------------------------------------------------------------------------------
// Address: 0x100DAA90
// Name: public: bool CRobjectLess::Less(struct robject_t const __near &,struct robject_t const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRobjectLess::Less(CRobjectLess *this, const robject_t *lhs, const robject_t *rhs, float *pContext)
{
  __int16 modelIndex; // cx
  __int16 v5; // dx
  __int16 skin; // ax
  __int16 v7; // cx
  float v9; // xmm0_4
  float v10; // xmm1_4

  modelIndex = lhs->modelIndex;
  v5 = rhs->modelIndex;
  if ( modelIndex == v5 )
  {
    skin = lhs->skin;
    v7 = rhs->skin;
    if ( skin == v7 )
      return lhs->lod < rhs->lod;
    else
      return skin < v7;
  }
  else
  {
    v9 = pContext[5 * modelIndex + 3];
    v10 = pContext[5 * v5 + 3];
    if ( v9 == v10 )
      return modelIndex < v5;
    else
      return v9 > v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAB20
// Name: public: virtual void CModelRender::DrawModelShadow(class IClientRenderable __near *,struct DrawModelInfo_t const __near &,class matrix3x4a_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::DrawModelShadow(
        CModelRender *this,
        IClientRenderable *pRenderable,
        const DrawModelInfo_t *info,
        matrix3x4a_t *pBoneToWorld)
{
  IStudioRender_vtbl *v4; // edi
  int v5; // eax
  Vector white; // [esp+1Ch] [ebp-Ch] BYREF

  g_pStudioRender->SetEyeViewTarget(this: g_pStudioRender, a2: info->m_pStudioHdr, a3: info->m_Body, a4: &vec3_origin);
  white.x = 1.0;
  white.y = 1.0;
  white.z = 1.0;
  g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)&white);
  ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: 1.0);
  if ( (info->m_pStudioHdr->flags & 0x100) == 0 )
    g_pStudioRender->ForcedMaterialOverride(
      this: g_pStudioRender,
      a2: g_pMaterialShadowBuild,
      a3: OVERRIDE_BUILD_SHADOWS);
  v4 = g_pStudioRender->__vftable;
  v5 = ((int (__thiscall *)(IClientRenderable *, int))pRenderable->GetRenderOrigin)(a1: pRenderable, a2: 36);
  ((void (__thiscall *)(IStudioRender *, _DWORD, const DrawModelInfo_t *, matrix3x4a_t *, _DWORD, _DWORD, int))v4->DrawModel)(
    a1: g_pStudioRender,
    a2: 0,
    a3: info,
    a4: pBoneToWorld,
    a5: 0,
    a6: 0,
    a7: v5);
  g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: nullptr, a3: OVERRIDE_NORMAL);
}

//------------------------------------------------------------------------------
// Address: 0x100DABF0
// Name: private: void CModelRender::InitColormeshParams(struct CModelRender::ModelInstance_t __near &,struct studiohwdata_t __near *,struct colormeshparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::InitColormeshParams(
        CModelRender *this,
        CModelRender::ModelInstance_t *instance,
        studiohwdata_t *pStudioHWData,
        int pColorMeshParams)
{
  studiohwdata_t *v6; // ebx
  int m_RootLOD; // edx
  int v8; // eax
  int v9; // ecx
  studioloddata_t *v10; // edi
  int *p_m_NumGroup; // eax
  int v12; // edx
  int v13; // ecx
  studioloddata_t *pLOD; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]
  int lodID; // [esp+1Ch] [ebp+8h]
  int meshID; // [esp+24h] [ebp+10h]

  *(_DWORD *)pColorMeshParams = 0;
  *(_DWORD *)(pColorMeshParams + 4) = 0;
  *(_DWORD *)(pColorMeshParams + 8) = 0;
  if ( (instance->m_nFlags & 2) != 0
    && g_pMaterialSystemHardwareConfig->SupportsStreamOffset(this: g_pMaterialSystemHardwareConfig)
    && r_proplightingpooling.m_pParent != nullptr
    && r_proplightingpooling.m_pParent->m_Value.m_nValue == 1 )
  {
    *(_DWORD *)(pColorMeshParams + 8) = &this->m_colorMeshVBAllocator;
  }
  v6 = pStudioHWData;
  m_RootLOD = pStudioHWData->m_RootLOD;
  lodID = pStudioHWData->m_RootLOD;
  if ( pStudioHWData->m_RootLOD < pStudioHWData->m_NumLODs )
  {
    v8 = 32 * m_RootLOD;
    v15 = 32 * m_RootLOD;
    do
    {
      v9 = 0;
      v10 = (studioloddata_t *)((char *)v6->m_pLODs + v8);
      pLOD = v10;
      meshID = 0;
      if ( v6->m_NumStudioMeshes > 0 )
      {
        do
        {
          p_m_NumGroup = &v10->m_pMeshData[v9].m_NumGroup;
          v12 = 0;
          if ( *p_m_NumGroup > 0 )
          {
            v13 = 0;
            do
            {
              *(_DWORD *)(pColorMeshParams + 4 * (*(_DWORD *)pColorMeshParams)++ + 12) = *(_DWORD *)(v13 + p_m_NumGroup[1] + 20);
              *(_DWORD *)(pColorMeshParams + 4) += *(_DWORD *)(v13 + p_m_NumGroup[1] + 20);
              ++v12;
              v13 += 44;
            }
            while ( v12 < *p_m_NumGroup );
            v6 = pStudioHWData;
            v9 = meshID;
            v10 = pLOD;
          }
          meshID = ++v9;
        }
        while ( v9 < v6->m_NumStudioMeshes );
        m_RootLOD = lodID;
        v8 = v15;
      }
      ++m_RootLOD;
      v8 += 32;
      lodID = m_RootLOD;
      v15 = v8;
    }
    while ( m_RootLOD < v6->m_NumLODs );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DACD0
// Name: bool CheckVarRange_r_rootlod(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CheckVarRange_r_rootlod()
{
  return CheckVarRange_Generic(pVar: &r_rootlod, minVal: 0, maxVal: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100DACF0
// Name: void r_lod_f(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_lod_f()
{
  CheckVarRange_Generic(pVar: &r_lod, minVal: -1, maxVal: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100DAD10
// Name: public: virtual int CPooledVBAllocator_ColorMesh::Allocate(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPooledVBAllocator_ColorMesh::Allocate(CPooledVBAllocator_ColorMesh *this, int numVerts)
{
  int result; // eax
  int m_numVertsAllocated; // esi

  if ( this->m_pMesh != nullptr )
  {
    if ( this->m_bStartedDeallocation )
    {
      _Warning(
        a1: "ERROR: CPooledVBAllocator_ColorMesh::Allocate being called after some (but not all) calls to Deallocate have bee"
        "n called - invalid! (expect visual artifacts)\n");
      return -1;
    }
    else
    {
      m_numVertsAllocated = this->m_numVertsAllocated;
      if ( numVerts <= this->m_totalVerts - m_numVertsAllocated )
      {
        result = this->m_nextFreeOffset;
        ++this->m_numAllocations;
        this->m_numVertsAllocated = numVerts + m_numVertsAllocated;
        this->m_nextFreeOffset = result + numVerts * this->m_vertexSize;
      }
      else
      {
        _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Allocate failing - not enough space left in the vertex buffer!\n");
        return -1;
      }
    }
  }
  else
  {
    _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Allocate cannot be called before Init (expect a crash)\n");
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DAD90
// Name: public: virtual void CPooledVBAllocator_ColorMesh::Deallocate(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPooledVBAllocator_ColorMesh::Deallocate(CPooledVBAllocator_ColorMesh *this, int offset, int numVerts)
{
  int m_numVertsAllocated; // eax
  int v5; // ecx
  int v6; // eax

  if ( this->m_pMesh != nullptr )
  {
    if ( this->m_numAllocations != 0 )
    {
      m_numVertsAllocated = numVerts;
      if ( numVerts > this->m_numVertsAllocated )
      {
        _Warning(
          a1: "ERROR: CPooledVBAllocator_ColorMesh::Deallocate called with too many verts, trying to free more than were allo"
          "cated (bug in calling code)\n");
        m_numVertsAllocated = this->m_numVertsAllocated;
      }
      v5 = --this->m_numAllocations;
      this->m_numVertsAllocated -= m_numVertsAllocated;
      v6 = this->m_numVertsAllocated;
      this->m_bStartedDeallocation = true;
      this->m_nextFreeOffset = 0;
      if ( v5 == 0 )
      {
        if ( v6 != 0 )
          _Warning(
            a1: "ERROR: CPooledVBAllocator_ColorMesh::Deallocate, after all allocations have been freed too few verts total h"
            "ave been deallocated (bug in calling code)\n");
        this->m_bStartedDeallocation = false;
      }
    }
    else
    {
      _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Deallocate called too many times! (bug in calling code)\n");
    }
  }
  else
  {
    _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Deallocate cannot be called before Init\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAEF0
// Name: public: int studiohwdata_t::GetLODForMetric(float)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall studiohwdata_t::GetLODForMetric(studiohwdata_t *this, float lodMetric)
{
  int result; // eax
  float m_fValue; // xmm0_4
  studioloddata_t *m_pLODs; // edx
  int m_NumLODs; // ecx
  int v7; // ecx
  float *i; // edx

  if ( (`studiohwdata_t::GetLODForMetric'::`2'::`local static guard' & 1) == 0 )
  {
    `studiohwdata_t::GetLODForMetric'::`2'::`local static guard' |= 1u;
    ConVarRef::ConVarRef(this: &`studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale, pName: "r_lod_switch_scale");
  }
  if ( this->m_NumLODs == 0 )
    return 0;
  if ( ConVarRef::IsValid(this: &`studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale) )
    m_fValue = `studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale.m_pConVarState->m_Value.m_fValue;
  else
    m_fValue = 1.0;
  m_pLODs = this->m_pLODs;
  m_NumLODs = this->m_NumLODs - 1;
  if ( m_pLODs[this->m_NumLODs - 1].m_SwitchPoint >= 0.0 )
    m_NumLODs = this->m_NumLODs;
  result = this->m_RootLOD;
  v7 = m_NumLODs - 1;
  if ( this->m_RootLOD >= v7 )
    return v7;
  for ( i = &m_pLODs[result + 1].m_SwitchPoint; (float)(*i * m_fValue) <= lodMetric; i += 8 )
  {
    if ( ++result >= v7 )
      return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DAFA0
// Name: private: void thinModelVertices_t::GetNormal(int,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall thinModelVertices_t::GetNormal(thinModelVertices_t *this, int vertIndex, Vector *pNormal)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  float v15; // [esp+0h] [ebp-8h]
  float v16; // [esp+4h] [ebp-4h]
  float v17; // [esp+4h] [ebp-4h]
  int vertIndexa; // [esp+10h] [ebp+8h]
  float vertIndexb; // [esp+10h] [ebp+8h]

  v3 = 0.0;
  v4 = (float)(unsigned __int8)this->m_vecNormals[vertIndex] - 128.0;
  v5 = (float)(unsigned __int8)HIBYTE(this->m_vecNormals[vertIndex]) - 128.0;
  if ( v4 >= 0.0 )
    v6 = 0.0;
  else
    v6 = 1.0;
  v16 = v6;
  if ( v5 < 0.0 )
    v3 = 1.0;
  v7 = -(float)((float)(v6 * 2.0) - 1.0);
  v8 = (float)((float)(v7 * v4) - v16) - 64.0;
  v9 = (float)((float)((float)-(float)((float)(v3 * 2.0) - 1.0) * v5) - v3) - 64.0;
  *(float *)&vertIndexa = v9;
  if ( v8 >= 0.0 )
    v17 = 0.0;
  else
    v17 = 1.0;
  if ( v9 >= 0.0 )
    v10 = 0.0;
  else
    v10 = 1.0;
  v11 = -(float)((float)(v17 * 2.0) - 1.0);
  v12 = (float)((float)(v11 * v8) - v17) * 0.015873017;
  v13 = -(float)((float)(v10 * 2.0) - 1.0);
  v14 = (float)((float)(v13 * *(float *)&vertIndexa) - v10) * 0.015873017;
  v15 = (float)(1.0 - v12) - v14;
  vertIndexb = 1.0 / sqrt(v14 * v14 + v12 * v12 + v15 * v15);
  pNormal->x = (float)(vertIndexb * v11) * v12;
  pNormal->y = (float)(vertIndexb * v13) * v14;
  pNormal->z = (float)(vertIndexb * v7) * v15;
}

//------------------------------------------------------------------------------
// Address: 0x100DB130
// Name: public: void LightingState_t::AddAllLocalLights(struct LightingState_t const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge LightingState_t::AddAllLocalLights(
        LightingState_t *this@<ecx>,
        float a2@<xmm0>,
        const LightingState_t *src,
        const Vector *vecLightingOrigin)
{
  int numlights; // ecx
  dworldlight_t *v6; // ebx
  int v7; // eax
  dworldlight_t **v8; // ecx
  int m_nValue; // edi
  int v10; // eax
  int v11; // ecx
  int i; // [esp+4h] [ebp-8h]
  dworldlight_t **locallight; // [esp+8h] [ebp-4h]

  i = 0;
  if ( src->numlights > 0 )
  {
    locallight = src->locallight;
    do
    {
      numlights = this->numlights;
      v6 = *locallight;
      if ( numlights < 4 )
      {
        v7 = 0;
        if ( numlights <= 0 )
        {
LABEL_8:
          if ( r_worldlights.m_pParent != nullptr )
            m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
          else
            m_nValue = 0;
          if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
          {
            if ( r_worldlights.m_pParent != nullptr )
              v10 = r_worldlights.m_pParent->m_Value.m_nValue;
            else
              v10 = 0;
          }
          else
          {
            v10 = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
          }
          v11 = this->numlights;
          if ( v11 >= v10 )
          {
            AddWorldLightToAmbientCube(
              a1: a2,
              pWorldLight: v6,
              vecLightingOrigin,
              ambientCube: (Vector (*)[6])this,
              bNoLightCull: false);
          }
          else
          {
            this->locallight[v11] = v6;
            ++this->numlights;
          }
        }
        else
        {
          v8 = this->locallight;
          while ( *v8 != v6 )
          {
            ++v7;
            ++v8;
            if ( v7 >= this->numlights )
              goto LABEL_8;
          }
        }
      }
      ++locallight;
      ++i;
    }
    while ( i < src->numlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB200
// Name: R_SetNonAmbientLightingState
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetNonAmbientLightingState(
        int numLights,
        dworldlight_t **locallight,
        int *pNumLightDescs,
        LightDesc_t *pLightDescs,
        bool bUpdateStudioRenderLights)
{
  int *v5; // edx
  int v6; // ebx
  long double v7; // st7
  dworldlight_t *v8; // edi
  emittype_t type; // eax
  LightDesc_t *v10; // esi
  double v11; // st6
  float linear_attn; // xmm2_4
  float quadratic_attn; // xmm4_4
  float exponent; // xmm0_4
  float constant_attn; // xmm3_4
  float radius; // xmm1_4
  long double v17; // st6
  int v18; // ecx
  float v19; // xmm1_4
  float v20; // [esp+8h] [ebp-14h]
  float v21; // [esp+Ch] [ebp-10h]
  float v22; // [esp+10h] [ebp-Ch]
  float v23; // [esp+14h] [ebp-8h]
  float v24; // [esp+18h] [ebp-4h]
  float v25; // [esp+18h] [ebp-4h]

  v5 = pNumLightDescs;
  v6 = 0;
  *pNumLightDescs = 0;
  if ( numLights > 0 )
  {
    v7 = 3.402823466385289e38;
    do
    {
      v8 = locallight[v6];
      type = v8->type;
      v10 = &pLightDescs[*v5];
      if ( type != emit_surface )
      {
        linear_attn = 0.0;
        quadratic_attn = 0.0;
        v23 = 0.0;
        v22 = 0.0;
        v10->m_OneOverThetaDotMinusPhiDot = 1.0;
        switch ( type )
        {
          case emit_point:
            v10->m_Type = MATERIAL_LIGHT_POINT;
            linear_attn = v8->linear_attn;
            quadratic_attn = v8->quadratic_attn;
            constant_attn = v8->constant_attn;
            v23 = linear_attn;
            v22 = quadratic_attn;
            goto LABEL_9;
          case emit_spotlight:
            v10->m_Type = MATERIAL_LIGHT_SPOT;
            v21 = v8->constant_attn;
            v23 = v8->linear_attn;
            v22 = v8->quadratic_attn;
            v10->m_Theta = acos(v8->stopdot);
            v10->m_Phi = acos(v8->stopdot2);
            v10->m_ThetaDot = v8->stopdot;
            v10->m_PhiDot = v8->stopdot2;
            exponent = v8->exponent;
            if ( exponent == 0.0 )
              exponent = 1.0;
            v10->m_Falloff = exponent;
            LightDesc_t::RecalculateOneOverThetaDotMinusPhiDot(this: v10);
            v7 = 3.402823466385289e38;
            quadratic_attn = v22;
            constant_attn = v21;
            linear_attn = v23;
            v5 = pNumLightDescs;
LABEL_9:
            if ( constant_attn == 0.0 && linear_attn == 0.0 && quadratic_attn == 0.0 )
              goto LABEL_12;
            goto LABEL_13;
          case emit_skylight:
            v10->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
            goto LABEL_12;
          case emit_quakelight:
          case emit_skyambient:
            goto $LN4_35;
          default:
LABEL_12:
            constant_attn = 1.0;
LABEL_13:
            v10->m_Color.x = v8->intensity.x;
            v10->m_Color.y = v8->intensity.y;
            v10->m_Color.z = v8->intensity.z;
            v10->m_Position.x = v8->origin.x;
            v10->m_Position.y = v8->origin.y;
            v10->m_Position.z = v8->origin.z;
            v10->m_Direction.x = v8->normal.x;
            v10->m_Direction.y = v8->normal.y;
            v10->m_Direction.z = v8->normal.z;
            radius = v8->radius;
            if ( radius != 0.0 )
              goto LABEL_24;
            v24 = sqrt(v10->m_Color.x * v10->m_Color.x + v10->m_Color.y * v10->m_Color.y + v10->m_Color.z
                                                                                         * v10->m_Color.z);
            if ( quadratic_attn == 0.0 )
            {
              if ( linear_attn != 0.0 )
              {
                radius = (float)((float)(v24 * 33.333336) - constant_attn) / linear_attn;
                goto LABEL_24;
              }
LABEL_22:
              v25 = sqrt(v7);
              goto LABEL_23;
            }
            v20 = (float)(linear_attn * linear_attn)
                - (float)((float)(constant_attn - (float)(v24 * 33.333336)) * (float)(quadratic_attn * 4.0));
            if ( v20 < 0.0 )
              goto LABEL_22;
            v17 = (sqrt(v20) - v23) / (v22 + v22);
            v25 = v17;
            if ( v17 < 0.0 )
            {
              radius = 0.0;
              goto LABEL_24;
            }
LABEL_23:
            radius = v25;
LABEL_24:
            v18 = 8;
            if ( constant_attn != 0.0 )
              v18 = 9;
            if ( linear_attn != 0.0 )
              v18 |= 2u;
            if ( quadratic_attn != 0.0 )
              v18 |= 4u;
            v10->m_Attenuation0 = constant_attn;
            v10->m_Attenuation1 = linear_attn;
            v10->m_Attenuation2 = quadratic_attn;
            v10->m_Range = radius;
            v10->m_Flags = v18;
            break;
        }
      }
      else
      {
        v10->m_Type = MATERIAL_LIGHT_SPOT;
        v10->m_Color.x = v8->intensity.x;
        v10->m_Color.y = v8->intensity.y;
        v10->m_Color.z = v8->intensity.z;
        v10->m_Position.x = v8->origin.x;
        v10->m_Position.y = v8->origin.y;
        v10->m_Position.z = v8->origin.z;
        v10->m_Direction.x = v8->normal.x;
        v10->m_Direction.y = v8->normal.y;
        v10->m_Direction.z = v8->normal.z;
        v11 = v8->radius;
        v10->m_Falloff = 1.0;
        v10->m_Range = v11;
        v10->m_Attenuation0 = 0.0;
        v10->m_Attenuation1 = 0.0;
        v10->m_Attenuation2 = 1.0;
        v10->m_Theta = 1.5707964;
        v10->m_Phi = 1.5707964;
        v10->m_ThetaDot = 0.0;
        v10->m_PhiDot = 0.0;
        v10->m_OneOverThetaDotMinusPhiDot = 1.0;
        v10->m_Flags = 12;
      }
      v19 = (float)d_lightstylevalue[locallight[v6]->style] * 0.0037878789;
      v10->m_Color.x = v19 * v10->m_Color.x;
      v10->m_Color.y = v10->m_Color.y * v19;
      v10->m_Color.z = v10->m_Color.z * v19;
      ++*v5;
$LN4_35:
      ++v6;
    }
    while ( v6 < numLights );
  }
  if ( bUpdateStudioRenderLights )
    g_pStudioRender->SetLocalLights(this: g_pStudioRender, a2: *v5, a3: pLightDescs);
}

//------------------------------------------------------------------------------
// Address: 0x100DB5A0
// Name: void R_ComputeLightingOrigin(class IClientRenderable __near *,struct studiohdr_t __near *,struct matrix3x4_t const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_ComputeLightingOrigin(
        IClientRenderable *pRenderable,
        studiohdr_t *pStudioHdr,
        const matrix3x4_t *matrix,
        Vector *center)
{
  int studiohdr2index; // eax
  int v5; // eax
  matrix3x4_t attachment; // [esp+4h] [ebp-30h] BYREF

  studiohdr2index = pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0 )
    v5 = *(int *)((char *)&pStudioHdr->checksum + studiohdr2index);
  else
    v5 = 0;
  if ( v5 > 0 )
  {
    pRenderable->GetAttachment(this: pRenderable, a2: v5, a3: &attachment);
    VectorTransform(in1: &pStudioHdr->illumposition.x, in2: &attachment, out: &center->x);
  }
  else
  {
    VectorTransform(in1: &pStudioHdr->illumposition.x, in2: matrix, out: &center->x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB610
// Name: public: void CModelRender::UnlockCacheCacheHandleArray(int,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::UnlockCacheCacheHandleArray(
        CModelRender *this,
        int nCount,
        memhandle_t__ **pColorMeshHandles)
{
  int i; // esi

  for ( i = 0; i < nCount; ++i )
  {
    if ( pColorMeshHandles[i] != nullptr )
      this->m_pCache->Unlock(this: this->m_pCache, a2: pColorMeshHandles[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB650
// Name: public: CModelRender::ModelInstance_t::ModelInstance_t(void)
// Source: json
//------------------------------------------------------------------------------
CModelRender::ModelInstance_t *__thiscall CModelRender::ModelInstance_t::ModelInstance_t(
        CModelRender::ModelInstance_t *this)
{
  CModelRender::ModelInstanceLightingState_t *v2; // eax

  v2 = (CModelRender::ModelInstanceLightingState_t *)CUtlMemoryPool::Alloc(
                                                       this: &CModelRender::ModelInstanceLightingState_t::s_Allocator,
                                                       amount: 0xECu);
  if ( v2 != nullptr )
  {
    v2->m_CurrentLightingState.r_boxcolor[0].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[1].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[0].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[0].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[1].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[1].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[2].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[2].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[2].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[3].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[3].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[3].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[4].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[4].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[4].z = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[5].x = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[5].y = 0.0;
    v2->m_CurrentLightingState.r_boxcolor[5].z = 0.0;
    v2->m_CurrentLightingState.numlights = 0;
    v2->m_AmbientLightingState.r_boxcolor[0].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[1].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[0].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[0].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[1].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[1].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[2].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[2].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[2].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[3].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[3].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[3].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[4].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[4].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[4].z = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[5].x = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[5].y = 0.0;
    v2->m_AmbientLightingState.r_boxcolor[5].z = 0.0;
    v2->m_AmbientLightingState.numlights = 0;
    this->m_pLightingState = v2;
  }
  else
  {
    this->m_pLightingState = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DB760
// Name: private: void CModelRender::SnapCurrentLightingState(struct CModelRender::ModelInstance_t __near &,struct LightingState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SnapCurrentLightingState(
        CModelRender *this,
        CModelRender::ModelInstance_t *inst,
        LightingState_t *pLightingState)
{
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // esi
  dworldlight_t *v4; // eax
  CClientState *BaseLocalClient; // eax

  m_pLightingState = inst->m_pLightingState;
  LightingState_t::operator=(this: &m_pLightingState->m_CurrentLightingState, __that: pLightingState);
  if ( pLightingState->numlights <= 0 )
  {
    m_pLightingState->m_flLightIntensity[0].x = 0.0;
    m_pLightingState->m_flLightIntensity[0].y = 0.0;
    m_pLightingState->m_flLightIntensity[0].z = 0.0;
  }
  else
  {
    v4 = pLightingState->locallight[0];
    m_pLightingState->m_flLightIntensity[0].x = v4->intensity.x;
    m_pLightingState->m_flLightIntensity[0].y = v4->intensity.y;
    m_pLightingState->m_flLightIntensity[0].z = v4->intensity.z;
  }
  if ( pLightingState->numlights <= 1 )
  {
    m_pLightingState->m_flLightIntensity[1].x = 0.0;
    m_pLightingState->m_flLightIntensity[1].y = 0.0;
    m_pLightingState->m_flLightIntensity[1].z = 0.0;
  }
  else
  {
    m_pLightingState->m_flLightIntensity[1] = pLightingState->locallight[1]->intensity;
  }
  if ( pLightingState->numlights <= 2 )
  {
    m_pLightingState->m_flLightIntensity[2].x = 0.0;
    m_pLightingState->m_flLightIntensity[2].y = 0.0;
    m_pLightingState->m_flLightIntensity[2].z = 0.0;
  }
  else
  {
    m_pLightingState->m_flLightIntensity[2] = pLightingState->locallight[2]->intensity;
  }
  if ( pLightingState->numlights <= 3 )
  {
    m_pLightingState->m_flLightIntensity[3].x = 0.0;
    m_pLightingState->m_flLightIntensity[3].y = 0.0;
    m_pLightingState->m_flLightIntensity[3].z = 0.0;
  }
  else
  {
    m_pLightingState->m_flLightIntensity[3] = pLightingState->locallight[3]->intensity;
  }
  BaseLocalClient = GetBaseLocalClient();
  m_pLightingState->m_flLightingTime = CClientState::GetTime(this: BaseLocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x100DB8A0
// Name: private: void CModelRender::TimeAverageAmbientLight(struct LightingState_t __near &,struct CModelRender::ModelInstance_t __near &,float,struct LightingState_t __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::TimeAverageAmbientLight(
        CModelRender *this,
        LightingState_t *actualLightingState,
        CModelRender::ModelInstance_t *inst,
        float flAttenFactor,
        LightingState_t *pLightingState,
        const Vector *pLightingOrigin)
{
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // edi
  float v7; // xmm6_4
  LightingState_t *v8; // ecx
  LightingState_t *p_m_CurrentLightingState; // esi
  char *v10; // edx
  float *v11; // eax
  int i; // edi
  float v13; // xmm3_4
  float v14; // xmm4_4
  int v15; // xmm0_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm0_4

  m_pLightingState = inst->m_pLightingState;
  if ( flAttenFactor >= 0.0 )
  {
    v7 = 1.0;
    if ( flAttenFactor <= 1.0 )
      v7 = flAttenFactor;
  }
  else
  {
    v7 = 0.0;
  }
  v8 = pLightingState;
  p_m_CurrentLightingState = &m_pLightingState->m_CurrentLightingState;
  v10 = (char *)((char *)pLightingState - (char *)m_pLightingState);
  v11 = (float *)&m_pLightingState->m_CurrentLightingState;
  for ( i = 6; i != 0; --i )
  {
    v13 = v8->r_boxcolor[0].x - (float)((float)(v8->r_boxcolor[0].x - *v11) * v7);
    v14 = *(float *)((char *)v11 + (_DWORD)v10) - (float)((float)(*(float *)((char *)v11 + (_DWORD)v10) - v11[1]) * v7);
    v15 = LODWORD(v13);
    v16 = *(float *)((char *)v11 + (_DWORD)v10 + 4)
        - (float)((float)(*(float *)((char *)v11 + (_DWORD)v10 + 4) - v11[2]) * v7);
    *v11 = v13;
    v11[1] = v14;
    v11[2] = v16;
    if ( v13 >= 0.0 )
    {
      if ( v13 > 8.0 )
        v15 = 1090519040;
    }
    else
    {
      v15 = 0;
    }
    *(_DWORD *)v11 = v15;
    v17 = v11[1];
    if ( v17 >= 0.0 )
    {
      if ( v17 > 8.0 )
        v17 = 8.0;
    }
    else
    {
      v17 = 0.0;
    }
    v11[1] = v17;
    v18 = v11[2];
    if ( v18 >= 0.0 )
    {
      if ( v18 > 8.0 )
        v18 = 8.0;
    }
    else
    {
      v18 = 0.0;
    }
    v11[2] = v18;
    v8 = (LightingState_t *)((char *)v8 + 12);
    v11 += 3;
  }
  qmemcpy(actualLightingState, p_m_CurrentLightingState, 0x48u);
}

//------------------------------------------------------------------------------
// Address: 0x100DB9B0
// Name: private: void CModelRender::EngineLightingToMaterialLighting(struct MaterialLightingState_t __near *,class Vector const __near &,struct LightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::EngineLightingToMaterialLighting(
        CModelRender *this,
        MaterialLightingState_t *pLightingState,
        const Vector *vecLightingOrigin,
        const LightingState_t *srcLightingState)
{
  int v5; // edi
  float *p_y; // esi
  int v7; // eax
  float v8; // xmm0_4
  dworldlight_t **pLightingStatea; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  qmemcpy((void *)pLightingState, srcLightingState, 0x48u);
  pLightingState->m_vecLightingOrigin = *vecLightingOrigin;
  v5 = 0;
  i = 0;
  if ( srcLightingState->numlights > 0 )
  {
    pLightingStatea = srcLightingState->locallight;
    p_y = &pLightingState->m_pLocalLightDesc[0].m_Color.y;
    do
    {
      if ( WorldLightToMaterialLight(pWorldLight: *pLightingStatea, light: (LightDesc_t *)(p_y - 2)) != 0 )
      {
        v7 = d_lightstylevalue[(*pLightingStatea)->style];
        if ( v7 != 264 )
        {
          v8 = (float)v7 * 0.0037878789;
          *(p_y - 1) = *(p_y - 1) * v8;
          *p_y = v8 * *p_y;
          p_y[1] = p_y[1] * v8;
        }
        ++v5;
        p_y += 22;
        if ( v5 >= 4 )
          break;
      }
      ++pLightingStatea;
      ++i;
    }
    while ( i < srcLightingState->numlights );
  }
  pLightingState->m_nLocalLightCount = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100DBA80
// Name: private: void CModelRender::DebugDrawLightingOrigin(struct DrawModelState_t const __near &,struct ModelRenderInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::DebugDrawLightingOrigin(
        CModelRender *this,
        const DrawModelState_t *state,
        const ModelRenderInfo_t *pInfo)
{
  const Vector *pLightingOrigin; // eax
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm1_4
  const matrix3x4_t *pLightingOffset; // eax
  const matrix3x4_t *m_pModelToWorld; // edx
  studiohdr_t *m_pStudioHdr; // eax
  studiohdr_t *v10; // eax
  studiohdr_t *v11; // eax
  const matrix3x4_t *v12; // edx
  studiohdr_t *v13; // eax
  studiohdr_t *v14; // eax
  const matrix3x4_t *v15; // edx
  studiohdr_t *v16; // eax
  const matrix3x4_t *v17; // [esp-24h] [ebp-60h]
  const matrix3x4_t *v18; // [esp-24h] [ebp-60h]
  Vector illumPosition; // [esp+Ch] [ebp-30h] BYREF
  Vector lightOrigin; // [esp+18h] [ebp-24h] BYREF
  Vector pt1; // [esp+24h] [ebp-18h] BYREF
  Vector pt0; // [esp+30h] [ebp-Ch] BYREF

  pLightingOrigin = pInfo->pLightingOrigin;
  if ( pLightingOrigin != nullptr )
  {
    x = pLightingOrigin->x;
    illumPosition.x = x;
    y = pLightingOrigin->y;
    illumPosition.y = y;
    z = pLightingOrigin->z;
    illumPosition.z = z;
    lightOrigin.x = x;
    lightOrigin.y = y;
    lightOrigin.z = z;
  }
  else
  {
    R_ComputeLightingOrigin(
      pRenderable: state->m_pRenderable,
      pStudioHdr: state->m_pStudioHdr,
      matrix: state->m_pModelToWorld,
      center: &illumPosition);
    pLightingOffset = pInfo->pLightingOffset;
    x = illumPosition.x;
    y = illumPosition.y;
    z = illumPosition.z;
    lightOrigin = illumPosition;
    if ( pLightingOffset != nullptr )
    {
      VectorTransform(in1: &illumPosition.x, in2: pLightingOffset, out: &lightOrigin.x);
      z = lightOrigin.z;
      y = lightOrigin.y;
      x = lightOrigin.x;
    }
  }
  pt0.y = y;
  pt1.y = y;
  pt0.z = z;
  pt1.z = z;
  pt0.x = x - 4.0;
  pt1.x = x + 4.0;
  CDebugOverlay::AddLineOverlay(
    origin: &pt0,
    dest: &pt1,
    r: 0,
    g: 255,
    b: 0,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  pt0.x = lightOrigin.x;
  pt1.x = lightOrigin.x;
  pt0.z = lightOrigin.z;
  pt1.z = lightOrigin.z;
  pt0.y = lightOrigin.y - 4.0;
  pt1.y = lightOrigin.y + 4.0;
  CDebugOverlay::AddLineOverlay(
    origin: &pt0,
    dest: &pt1,
    r: 0,
    g: 255,
    b: 0,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  m_pModelToWorld = state->m_pModelToWorld;
  pt0 = state->m_pStudioHdr->hull_min;
  VectorTransform(in1: &pt0.x, in2: m_pModelToWorld, out: &pt1.x);
  CDebugOverlay::AddLineOverlay(
    origin: &lightOrigin,
    dest: &pt1,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  m_pStudioHdr = state->m_pStudioHdr;
  pt0.x = state->m_pStudioHdr->hull_min.x;
  pt0.y = m_pStudioHdr->hull_max.y;
  pt0.z = m_pStudioHdr->hull_min.z;
  VectorTransform(in1: &pt0.x, in2: state->m_pModelToWorld, out: &pt1.x);
  CDebugOverlay::AddLineOverlay(
    origin: &lightOrigin,
    dest: &pt1,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v10 = state->m_pStudioHdr;
  pt0.x = state->m_pStudioHdr->hull_max.x;
  pt0.y = v10->hull_max.y;
  v17 = state->m_pModelToWorld;
  pt0.z = v10->hull_min.z;
  VectorTransform(in1: &pt0.x, in2: v17, out: &pt1.x);
  CDebugOverlay::AddLineOverlay(
    origin: &lightOrigin,
    dest: &pt1,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v11 = state->m_pStudioHdr;
  v12 = state->m_pModelToWorld;
  pt0.x = state->m_pStudioHdr->hull_max.x;
  pt0.y = v11->hull_min.y;
  pt0.z = v11->hull_min.z;
  VectorTransform(in1: &pt0.x, in2: v12, out: &pt1.x);
  CDebugOverlay::AddLineOverlay(
    origin: &lightOrigin,
    dest: &pt1,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v13 = state->m_pStudioHdr;
  pt0.x = state->m_pStudioHdr->hull_min.x;
  pt0.y = v13->hull_min.y;
  pt0.z = v13->hull_max.z;
  VectorTransform(in1: &pt0.x, in2: state->m_pModelToWorld, out: &pt1.x);
  CDebugOverlay::AddLineOverlay(
    origin: &lightOrigin,
    dest: &pt1,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v14 = state->m_pStudioHdr;
  pt0.x = state->m_pStudioHdr->hull_min.x;
  pt0.y = v14->hull_max.y;
  v18 = state->m_pModelToWorld;
  pt0.z = v14->hull_max.z;
  VectorTransform(in1: &pt0.x, in2: v18, out: &pt1.x);
  CDebugOverlay::AddLineOverlay(
    origin: &lightOrigin,
    dest: &pt1,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v15 = state->m_pModelToWorld;
  pt0 = state->m_pStudioHdr->hull_max;
  VectorTransform(in1: &pt0.x, in2: v15, out: &pt1.x);
  CDebugOverlay::AddLineOverlay(
    origin: &lightOrigin,
    dest: &pt1,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
  v16 = state->m_pStudioHdr;
  pt0.x = state->m_pStudioHdr->hull_max.x;
  pt0.y = v16->hull_min.y;
  pt0.z = v16->hull_max.z;
  VectorTransform(in1: &pt0.x, in2: state->m_pModelToWorld, out: &pt1.x);
  CDebugOverlay::AddLineOverlay(
    origin: &lightOrigin,
    dest: &pt1,
    r: 100,
    g: 100,
    b: 150,
    a: 255,
    noDepthTest: true,
    flDuration: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100DBEA0
// Name: public: virtual int CModelRender::DrawModel(int,class IClientRenderable __near *,unsigned short,int,struct model_t const __near *,class Vector const __near &,class QAngle const __near &,int,int,int,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::DrawModel(
        CModelRender *this,
        int flags,
        IClientRenderable *pRenderable,
        unsigned __int16 instance,
        int entity_index,
        const model_t *pModel,
        const Vector *origin,
        const QAngle *angles,
        int skin,
        int body,
        int hitboxset,
        const matrix3x4_t *pModelToWorld,
        const matrix3x4_t *pLightingOffset)
{
  float z; // xmm0_4
  int m_nValue; // eax
  ModelRenderInfo_t sInfo; // [esp+0h] [ebp-44h] BYREF

  sInfo.flags = flags;
  sInfo.instance = instance;
  sInfo.pModel = pModel;
  sInfo.origin = *origin;
  sInfo.angles.x = angles->x;
  sInfo.angles.y = angles->y;
  z = angles->z;
  sInfo.skin = skin;
  sInfo.body = body;
  sInfo.hitboxset = hitboxset;
  sInfo.pModelToWorld = pModelToWorld;
  sInfo.pLightingOffset = pLightingOffset;
  sInfo.pRenderable = pRenderable;
  sInfo.pLightingOrigin = nullptr;
  sInfo.entity_index = entity_index;
  sInfo.angles.z = z;
  if ( r_entity.m_pParent != nullptr )
  {
    m_nValue = r_entity.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
      return this->DrawModelEx(this, a2: &sInfo);
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue == entity_index )
    return this->DrawModelEx(this, a2: &sInfo);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100DBF60
// Name: private: int CModelRender::ComputeLOD(class IMatRenderContext __near *,struct ModelRenderInfo_t const __near &,struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::ComputeLOD(
        CModelRender *this,
        IMatRenderContext *pRenderContext,
        const ModelRenderInfo_t *info,
        studiohwdata_t *pStudioHWData)
{
  int result; // eax
  IMatRenderContext_vtbl *v5; // edi
  int v6; // eax
  double v7; // st7
  float lodMetric; // xmm0_4
  studiohwdata_t *v9; // esi
  int v10; // ecx
  int m_NumLODs; // ecx
  int m_RootLOD; // esi
  float metric; // [esp+1Ch] [ebp+Ch]

  if ( r_lod.m_pParent != nullptr )
  {
    result = r_lod.m_pParent->m_Value.m_nValue;
    if ( result == -1 )
    {
      v5 = pRenderContext->__vftable;
      v6 = ((int (__stdcall *)(_DWORD))info->pRenderable->GetRenderOrigin)(a1: 0.5);
      v7 = ((double (__thiscall *)(IMatRenderContext *, int))v5->ComputePixelWidthOfSphere)(a1: pRenderContext, a2: v6);
      if ( v7 == 0.0 )
      {
        lodMetric = 0.0;
      }
      else
      {
        metric = v7;
        lodMetric = 100.0 / metric;
      }
      v9 = pStudioHWData;
      result = studiohwdata_t::GetLODForMetric(this: pStudioHWData, lodMetric);
      goto LABEL_19;
    }
  }
  else
  {
    result = 0;
  }
  v9 = pStudioHWData;
  if ( (info->flags & 0x40) == 0 || (v10 = pStudioHWData->m_NumLODs - 2, result <= v10) )
  {
    v10 = pStudioHWData->m_NumLODs - 1;
    if ( result <= v10 )
    {
      if ( result < 0 )
        result = 0;
      goto LABEL_11;
    }
  }
  result = v10;
LABEL_19:
  if ( result < 0 )
  {
    result = 0;
    goto LABEL_13;
  }
LABEL_11:
  m_NumLODs = v9->m_NumLODs;
  if ( result >= m_NumLODs )
    result = m_NumLODs - 1;
LABEL_13:
  m_RootLOD = v9->m_RootLOD;
  if ( result < m_RootLOD )
    return m_RootLOD;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DC020
// Name: public: virtual void CModelRender::SetViewTarget(class CStudioHdr const __near *,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetViewTarget(
        CModelRender *this,
        const CStudioHdr *pStudioHdr,
        int nBodyIndex,
        const Vector *target)
{
  g_pStudioRender->SetEyeViewTarget(this: g_pStudioRender, a2: pStudioHdr->m_pStudioHdr, a3: nBodyIndex, a4: target);
}

//------------------------------------------------------------------------------
// Address: 0x100DC1C0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CModelRender::ModelInstance_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC4A0
// Name: public: struct mstudio_modelvertexdata_t const __near * mstudiomodel_t::GetVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
vertexFileHeader_t *__thiscall mstudiomodel_t::GetVertexData(mstudiomodel_t *this, void *pModelData)
{
  vertexFileHeader_t *result; // eax
  int vertexDataStart; // ecx
  char *v5; // edx
  mstudio_modelvertexdata_t *p_vertexdata; // ecx
  int tangentDataStart; // esi

  result = g_pMDLCache->GetVertexData(this: g_pMDLCache, a2: LOWORD(s_ModelRender.m_pStudioHdr->virtualModel));
  if ( result != nullptr )
  {
    if ( result->id == 1448297545 && (vertexDataStart = result->vertexDataStart) != 0 )
      v5 = (char *)result + vertexDataStart;
    else
      v5 = nullptr;
    p_vertexdata = &this->vertexdata;
    this->vertexdata.pVertexData = v5;
    if ( result->id == 1448297545 && (tangentDataStart = result->tangentDataStart) != 0 )
    {
      this->vertexdata.pTangentData = (char *)result + tangentDataStart;
      return v5 != nullptr ? (vertexFileHeader_t *)p_vertexdata : nullptr;
    }
    else
    {
      this->vertexdata.pTangentData = nullptr;
      return v5 != nullptr ? (vertexFileHeader_t *)p_vertexdata : nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DC520
// Name: public: char const __near * studiohdr_t::pszName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall studiohdr_t::pszName(studiohdr_t *this)
{
  int studiohdr2index; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // ecx

  studiohdr2index = this->studiohdr2index;
  if ( studiohdr2index == 0 )
    return this->name;
  v2 = *(_DWORD *)&this->name[studiohdr2index + 8];
  v3 = (char *)this + studiohdr2index;
  if ( v2 == 0 || &v3[v2] == nullptr )
    return this->name;
  v4 = *((_DWORD *)v3 + 5);
  if ( v4 != 0 )
    return &v3[v4];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100DC550
// Name: void UpdateStudioRenderConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateStudioRenderConfig()
{
  int m_nValue; // eax
  char v1; // al
  char v2; // al
  int v3; // ecx
  char v4; // al
  int v5; // ecx
  char v6; // al
  int v7; // ecx
  char v8; // al
  int v9; // ecx
  char v10; // al
  int v11; // ecx
  ConVar *m_pParent; // edx
  char v13; // al
  bool IsRptActive; // al
  bool v15; // zf
  ConVar *v16; // esi
  int v17; // ecx
  char v18; // cl
  char v19; // cl
  char v20; // al
  int v21; // ecx
  char v22; // al
  int v23; // ecx
  char v24; // al
  int v25; // ecx

  if ( g_pMaterialSystemConfig == nullptr || g_pStudioRender == nullptr )
    return;
  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig, value: 0, count: sizeof(s_StudioRenderConfig));
  if ( r_eyemove.m_pParent != nullptr )
    m_nValue = r_eyemove.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v1 = (*((_BYTE *)&s_StudioRenderConfig + 36) ^ (m_nValue != 0)) & 1 ^ *((_BYTE *)&s_StudioRenderConfig + 36);
  *((_BYTE *)&s_StudioRenderConfig + 36) = v1;
  s_StudioRenderConfig.fEyeShiftX = r_eyeshift_x.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftY = r_eyeshift_y.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftZ = r_eyeshift_z.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeSize = r_eyesize.m_pParent->m_Value.m_fValue;
  if ( mat_softwareskin.m_pParent == nullptr || mat_softwareskin.m_pParent->m_Value.m_nValue == 0 )
  {
    if ( !ShouldDrawInWireFrameMode()
      && (r_slowpathwireframe.m_pParent == nullptr || r_slowpathwireframe.m_pParent->m_Value.m_nValue == 0) )
    {
      v2 = *((_BYTE *)&s_StudioRenderConfig + 36) & 0xFD;
      goto LABEL_14;
    }
    v1 = *((_BYTE *)&s_StudioRenderConfig + 36);
  }
  v2 = v1 | 2;
LABEL_14:
  *((_BYTE *)&s_StudioRenderConfig + 36) = v2;
  if ( r_nohw.m_pParent != nullptr )
    v3 = r_nohw.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  v4 = (v2 ^ (4 * (v3 != 0))) & 4 ^ v2;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v4;
  if ( r_nosw.m_pParent != nullptr )
    v5 = r_nosw.m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  v6 = (v4 ^ (8 * (v5 != 0))) & 8 ^ v4;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v6;
  if ( r_teeth.m_pParent != nullptr )
    v7 = r_teeth.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  v8 = (v6 ^ (16 * (v7 != 0))) & 0x10 ^ v6;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v8;
  if ( r_drawentities.m_pParent != nullptr )
    s_StudioRenderConfig.drawEntities = r_drawentities.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.drawEntities = 0;
  if ( r_flex.m_pParent != nullptr )
    v9 = r_flex.m_pParent->m_Value.m_nValue;
  else
    v9 = 0;
  v10 = (v8 ^ ((v9 != 0) << 6)) & 0x40 ^ v8;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v10;
  if ( r_eyes.m_pParent != nullptr )
    v11 = r_eyes.m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  m_pParent = sv_cheats.m_pParent;
  v13 = (v10 ^ (32 * (v11 != 0))) & 0x20 ^ v10;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v13;
  if ( sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0
    || (IsRptActive = Cmd_IsRptActive(),
        m_pParent = sv_cheats.m_pParent,
        v15 = !IsRptActive,
        v13 = *((_BYTE *)&s_StudioRenderConfig + 36),
        !v15) )
  {
    v16 = mat_wireframe.m_pParent;
    if ( mat_wireframe.m_pParent != nullptr )
      v17 = mat_wireframe.m_pParent->m_Value.m_nValue;
    else
      v17 = 0;
    if ( v17 != 0 )
      goto LABEL_39;
  }
  else
  {
    v16 = mat_wireframe.m_pParent;
  }
  if ( r_slowpathwireframe.m_pParent != nullptr && r_slowpathwireframe.m_pParent->m_Value.m_nValue != 0 )
  {
LABEL_39:
    v18 = 1;
    goto LABEL_40;
  }
  v18 = 0;
LABEL_40:
  *((_BYTE *)&s_StudioRenderConfig + 36) = v13 & 0x7F | (v18 << 7);
  if ( *((char *)&s_StudioRenderConfig + 36) >= 0 )
    goto LABEL_52;
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
LABEL_45:
    if ( v16 == nullptr || v16->m_Value.m_nValue != 1 )
      goto LABEL_47;
LABEL_52:
    v19 = 0;
    goto LABEL_53;
  }
  if ( Cmd_IsRptActive() )
  {
    v16 = mat_wireframe.m_pParent;
    goto LABEL_45;
  }
LABEL_47:
  v19 = 1;
LABEL_53:
  v20 = (*((_BYTE *)&s_StudioRenderConfig + 37) ^ (4 * v19)) & 4 ^ *((_BYTE *)&s_StudioRenderConfig + 37);
  *((_BYTE *)&s_StudioRenderConfig + 37) = v20;
  if ( mat_normals.m_pParent != nullptr )
    v21 = mat_normals.m_pParent->m_Value.m_nValue;
  else
    v21 = 0;
  v22 = (v20 ^ (v21 != 0)) & 1 ^ v20;
  *((_BYTE *)&s_StudioRenderConfig + 37) = v22;
  if ( r_skin.m_pParent != nullptr )
    s_StudioRenderConfig.skin = r_skin.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.skin = 0;
  if ( r_maxmodeldecal.m_pParent != nullptr )
    s_StudioRenderConfig.maxDecalsPerModel = r_maxmodeldecal.m_pParent->m_Value.m_nValue;
  else
    s_StudioRenderConfig.maxDecalsPerModel = 0;
  if ( r_modelwireframedecal.m_pParent != nullptr )
    v23 = r_modelwireframedecal.m_pParent->m_Value.m_nValue;
  else
    v23 = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = (v22 ^ (32 * (v23 != 0))) & 0x20 ^ v22;
  s_StudioRenderConfig.fullbright = g_pMaterialSystemConfig->nFullbright;
  v24 = (*((_BYTE *)&s_StudioRenderConfig + 37)
       ^ (8 * g_pMaterialSystemConfig->bSoftwareLighting))
      & 8
      ^ *((_BYTE *)&s_StudioRenderConfig + 37);
  *((_BYTE *)&s_StudioRenderConfig + 37) = v24;
  if ( r_showenvcubemap.m_pParent != nullptr )
    v25 = r_showenvcubemap.m_pParent->m_Value.m_nValue;
  else
    v25 = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) = (v24 ^ (16 * (v25 != 0))) & 0x10 ^ v24;
  s_StudioRenderConfig.fEyeGlintPixelWidthLODThreshold = r_eyeglintlodpixels.m_pParent->m_Value.m_fValue;
  g_pStudioRender->UpdateConfig(this: g_pStudioRender, a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x100DC8B0
// Name: void InitStudioRender(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitStudioRender()
{
  _DWORD v0[4]; // [esp+0h] [ebp-10h] BYREF

  UpdateStudioRenderConfig();
  v0[0] = -1;
  v0[1] = -1;
  v0[2] = 0;
  v0[3] = 0;
  if ( s_ModelRender.m_pCache == nullptr )
    s_ModelRender.m_pCache = g_pDataCache->AddSection(
                               this: g_pDataCache,
                               a2: &s_ModelRender.CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,
                               a3: "ColorMesh",
                               a4: v0,
                               a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100DC900
// Name: void ShutdownStudioRender(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownStudioRender()
{
  IDataCacheSection *m_pCache; // esi
  int *v1; // ebx
  int v2; // edi
  int v3; // eax

  if ( s_ModelRender.m_pCache != nullptr )
  {
    m_pCache = s_ModelRender.m_pCache;
    v1 = (int *)((int (*)(void))s_ModelRender.m_pCache->GetSharedCache)();
    if ( m_pCache != nullptr )
    {
      v2 = *v1;
      v3 = ((int (__thiscall *)(IDataCacheSection *, int))m_pCache->GetName)(a1: m_pCache, a2: 1);
      (*(void (__thiscall **)(int *, int))(v2 + 52))(a1: v1, a2: v3);
    }
    s_ModelRender.m_pCache = nullptr;
  }
  s_ModelRender.m_colorMeshVBAllocator.Clear(this: &s_ModelRender.m_colorMeshVBAllocator);
}

//------------------------------------------------------------------------------
// Address: 0x100DC950
// Name: unsigned short __near & FirstShadowOnModelInstance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl FirstShadowOnModelInstance(unsigned __int16 handle)
{
  return &s_ModelRender.m_ModelInstances.m_Memory.m_pMemory[handle].m_Element.m_FirstShadow;
}

//------------------------------------------------------------------------------
// Address: 0x100DC970
// Name: private: struct LightingState_t __near * CModelRender::TimeAverageLightingState(unsigned short,struct LightingState_t __near *,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
LightingState_t *__thiscall CModelRender::TimeAverageLightingState(
        CModelRender *this,
        unsigned __int16 handle,
        LightingState_t *pLightingState,
        int nEntIndex,
        const Vector *pLightingOrigin)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v7; // ebx
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // edi
  float m_flLightingTime; // xmm0_4
  CClientState *BaseLocalClient; // eax
  double v11; // st7
  CClientState *v12; // eax
  long double v13; // st7
  long double v14; // rt0
  int m_nValue; // esi
  LightingState_t *v16; // esi
  int numlights; // eax
  float *p_z; // ecx
  dworldlight_t **locallight; // esi
  int v20; // eax
  dworldlight_t **v21; // edx
  int v22; // eax
  double x; // st7
  int v24; // eax
  bool v25; // cc
  float v26; // xmm4_4
  int v27; // ecx
  const void **v28; // eax
  dworldlight_t *v29; // edx
  float *v30; // ebx
  dworldlight_t *v31; // eax
  int v32; // ecx
  float v33; // xmm3_4
  float v34; // xmm0_4
  float z; // xmm1_4
  float v36; // xmm2_4
  int v37; // ecx
  int v38; // esi
  const void **v39; // edx
  float v40; // eax
  dworldlight_t *v41; // ebx
  int v42; // esi
  dworldlight_t *v43; // ecx
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  int v47; // edx
  dworldlight_t **v48; // esi
  float *v49; // eax
  float *v50; // ecx
  dworldlight_t *v51; // ebx
  dworldlight_t *v52; // ebx
  dworldlight_t *v53; // ebx
  dworldlight_t *v54; // ebx
  double v55; // st7
  float *v56; // eax
  int v57; // ebx
  dworldlight_t **v58; // edi
  dworldlight_t **v59; // esi
  int v60; // edx
  double v61; // st7
  Vector pLight[4]; // [esp+18h] [ebp-58h] BYREF
  dworldlight_t *pSourceLight[4]; // [esp+48h] [ebp-28h] BYREF
  float flInterpFactor; // [esp+58h] [ebp-18h]
  CModelRender::ModelInstanceLightingState_t *instanceLightingState; // [esp+5Ch] [ebp-14h]
  float flAttenFactor; // [esp+60h] [ebp-10h]
  bool pMatch[4]; // [esp+64h] [ebp-Ch]
  const void **j; // [esp+68h] [ebp-8h]
  int i; // [esp+6Ch] [ebp-4h]
  float dt; // [esp+78h] [ebp+8h]
  int dta; // [esp+78h] [ebp+8h]
  int nCurrLight; // [esp+7Ch] [ebp+Ch]

  if ( r_lightaverage.m_pParent == nullptr )
    return pLightingState;
  if ( r_lightaverage.m_pParent->m_Value.m_nValue == 0 )
    return pLightingState;
  flInterpFactor = r_lightinterp.m_pParent->m_Value.m_fValue;
  if ( flInterpFactor == 0.0 || handle == 0xFFFF )
    return pLightingState;
  v7 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  m_pLightingState = v7->m_Element.m_pLightingState;
  m_flLightingTime = m_pLightingState->m_flLightingTime;
  instanceLightingState = m_pLightingState;
  if ( m_flLightingTime == -999999.0 )
  {
    CModelRender::SnapCurrentLightingState(this, inst: &v7->m_Element, pLightingState);
    return pLightingState;
  }
  BaseLocalClient = GetBaseLocalClient();
  v11 = CClientState::GetTime(this: BaseLocalClient) - m_pLightingState->m_flLightingTime;
  dt = v11;
  if ( v11 > 0.0 )
  {
    v12 = GetBaseLocalClient();
    m_pLightingState->m_flLightingTime = CClientState::GetTime(this: v12);
  }
  else
  {
    dt = 0.0;
  }
  if ( (_S3_2 & 1) == 0 )
    _S3_2 |= 1u;
  v13 = -(dt * flInterpFactor) * 1.442695040888963407;
  v14 = rint(v13);
  flAttenFactor = __FSCALE__(__F2XM1__(v13 - v14) + 1.0, v14);
  CModelRender::TimeAverageAmbientLight(
    this,
    actualLightingState: &actualLightingState,
    inst: &v7->m_Element,
    flAttenFactor,
    pLightingState,
    pLightingOrigin);
  if ( g_pMaterialSystemConfig->bSoftwareLighting )
  {
    if ( r_worldlights.m_pParent != nullptr )
    {
      dta = r_worldlights.m_pParent->m_Value.m_nValue;
      goto LABEL_24;
    }
    goto LABEL_23;
  }
  if ( r_worldlights.m_pParent != nullptr )
    m_nValue = r_worldlights.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig) >= m_nValue )
  {
    if ( r_worldlights.m_pParent != nullptr )
    {
      dta = r_worldlights.m_pParent->m_Value.m_nValue;
      goto LABEL_24;
    }
LABEL_23:
    dta = 0;
    goto LABEL_24;
  }
  dta = g_pMaterialSystemHardwareConfig->MaxNumLights(this: g_pMaterialSystemHardwareConfig);
LABEL_24:
  v16 = pLightingState;
  numlights = pLightingState->numlights;
  *(_DWORD *)pMatch = 0;
  if ( numlights > 0 )
  {
    p_z = &pLight[0].z;
    locallight = pLightingState->locallight;
    for ( j = (const void **)numlights; j != nullptr; j = (const void **)((char *)j - 1) )
    {
      v20 = 0;
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      if ( m_pLightingState->m_CurrentLightingState.numlights > 0 )
      {
        v21 = m_pLightingState->m_CurrentLightingState.locallight;
        while ( *locallight != *v21 )
        {
          ++v20;
          ++v21;
          if ( v20 >= m_pLightingState->m_CurrentLightingState.numlights )
            goto LABEL_32;
        }
        pMatch[v20] = true;
        v22 = v20;
        x = m_pLightingState->m_flLightIntensity[v22].x;
        v24 = (int)&m_pLightingState->m_flLightIntensity[v22];
        *(p_z - 2) = x;
        *(p_z - 1) = *(float *)(v24 + 4);
        *p_z = *(float *)(v24 + 8);
      }
LABEL_32:
      ++locallight;
      p_z += 3;
    }
    v16 = pLightingState;
  }
  v25 = v16->numlights <= 0;
  v26 = flAttenFactor;
  i = 0;
  if ( !v25 )
  {
    v27 = (char *)&actualLightingState - (char *)pLightingState;
    v28 = (const void **)v16->locallight;
    v29 = s_WorldLights;
    j = (const void **)v16->locallight;
    v30 = &pLight[0].z;
    for ( LODWORD(flInterpFactor) = (char *)&actualLightingState - (char *)pLightingState; ; v27 = LODWORD(flInterpFactor) )
    {
      ++j;
      *(const void **)((char *)v28 + v27) = v29;
      qmemcpy(v29, *v28, sizeof(dworldlight_t));
      v31 = (dworldlight_t *)*v28;
      v32 = i;
      v33 = v31->intensity.x - (float)((float)(v31->intensity.x - *(v30 - 2)) * v26);
      v34 = v31->intensity.y - (float)((float)(v31->intensity.y - *(v30 - 1)) * v26);
      z = v31->intensity.z;
      v36 = (float)(z - *v30) * v26;
      pSourceLight[i] = v31;
      v29->intensity.x = v33;
      v29->intensity.y = v34;
      v29->intensity.z = z - v36;
      v30 += 3;
      ++v29;
      i = v32 + 1;
      if ( v32 + 1 >= pLightingState->numlights )
        break;
      v28 = j;
    }
    m_pLightingState = instanceLightingState;
  }
  v37 = pLightingState->numlights;
  v38 = 0;
  nCurrLight = v37;
  i = 0;
  if ( m_pLightingState->m_CurrentLightingState.numlights > 0 )
  {
    v39 = (const void **)m_pLightingState->m_CurrentLightingState.locallight;
    LODWORD(v40) = &m_pLightingState->m_flLightIntensity[0].z;
    v41 = &s_WorldLights[v37];
    j = (const void **)m_pLightingState->m_CurrentLightingState.locallight;
    LODWORD(flInterpFactor) = &m_pLightingState->m_flLightIntensity[0].z;
    do
    {
      if ( !pMatch[v38]
        && (float)((float)((float)(*(float *)(LODWORD(v40) - 8) * *(float *)(LODWORD(v40) - 8))
                         + (float)(*(float *)(LODWORD(v40) - 4) * *(float *)(LODWORD(v40) - 4)))
                 + (float)(*(float *)LODWORD(v40) * *(float *)LODWORD(v40))) >= 1.0 )
      {
        if ( (int)v41 >= (int)&_S3_2 )
          break;
        actualLightingState.locallight[v37] = v41;
        qmemcpy(v41, *v39, sizeof(dworldlight_t));
        v42 = nCurrLight;
        v43 = (dworldlight_t *)*v39;
        v44 = v26 * *(float *)(LODWORD(v40) - 8);
        v45 = v26 * *(float *)LODWORD(v40);
        v46 = *(float *)(LODWORD(v40) - 4) * v26;
        v41->intensity.x = v44;
        v41->intensity.y = v46;
        v41->intensity.z = v45;
        pSourceLight[nCurrLight] = v43;
        if ( nCurrLight >= dta && pLightingOrigin != nullptr )
        {
          AddWorldLightToAmbientCube(
            a1: v44,
            pWorldLight: v41,
            vecLightingOrigin: pLightingOrigin,
            ambientCube: (Vector (*)[6])&actualLightingState,
            bNoLightCull: true);
          v26 = flAttenFactor;
          v40 = flInterpFactor;
          v39 = j;
        }
        m_pLightingState = instanceLightingState;
        ++nCurrLight;
        v37 = v42 + 1;
        v38 = i;
        ++v41;
      }
      ++v38;
      ++v39;
      LODWORD(v40) += 12;
      i = v38;
      j = v39;
      flInterpFactor = v40;
    }
    while ( v38 < m_pLightingState->m_CurrentLightingState.numlights );
  }
  actualLightingState.numlights = v37;
  if ( v37 >= dta )
    actualLightingState.numlights = dta;
  v47 = 0;
  m_pLightingState->m_CurrentLightingState.numlights = v37;
  if ( v37 >= 4 )
  {
    v48 = &m_pLightingState->m_CurrentLightingState.locallight[1];
    v49 = &s_WorldLights[0].intensity.z;
    v50 = &m_pLightingState->m_flLightIntensity[0].z;
    do
    {
      v51 = pSourceLight[v47];
      *(v50 - 2) = *(v49 - 2);
      *(v48 - 1) = v51;
      v52 = pSourceLight[v47 + 1];
      *(v50 - 1) = *(v49 - 1);
      *v48 = v52;
      v53 = pSourceLight[v47 + 2];
      *v50 = *v49;
      v48[1] = v53;
      v54 = pSourceLight[v47 + 3];
      v50[1] = v49[23];
      v48[2] = v54;
      v50[2] = v49[24];
      v47 += 4;
      v50[3] = v49[25];
      v48 += 4;
      v55 = v49[48];
      v49 += 100;
      v50[4] = v55;
      v50 += 12;
      *(v50 - 7) = *(v49 - 51);
      *(v50 - 6) = *(v49 - 50);
      *(v50 - 5) = *(v49 - 27);
      *(v50 - 4) = *(v49 - 26);
      *(v50 - 3) = *(v49 - 25);
    }
    while ( v47 < nCurrLight - 3 );
    v37 = nCurrLight;
  }
  if ( v47 < v37 )
  {
    v56 = &s_WorldLights[v47].intensity.z;
    v57 = (int)&m_pLightingState->m_flLightIntensity[v47].z;
    v58 = &m_pLightingState->m_CurrentLightingState.locallight[v47];
    v59 = &pSourceLight[v47];
    v60 = v37 - v47;
    qmemcpy(v58, v59, 4 * v60);
    do
    {
      v61 = *(v56 - 2);
      v56 += 25;
      *(float *)(v57 - 8) = v61;
      v57 += 12;
      --v60;
      *(float *)(v57 - 16) = *(v56 - 26);
      *(float *)(v57 - 12) = *(v56 - 25);
    }
    while ( v60 != 0 );
  }
  return &actualLightingState;
}

//------------------------------------------------------------------------------
// Address: 0x100DCE30
// Name: private: int CModelRender::GetLightingConditions(class Vector const __near &,class Vector __near *,int,struct LightDesc_t __near *,class ITexture __near * __near &,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::GetLightingConditions(
        CModelRender *this,
        const Vector *vecLightingOrigin,
        Vector *pColors,
        int nMaxLocalLights,
        LightDesc_t *pLocalLights,
        ITexture **pEnvCubemapTexture,
        unsigned __int16 handle,
        int bAllowFast)
{
  ITexture **v8; // ebx
  unsigned __int16 v9; // si
  IClientRenderable *m_pRenderable; // eax
  char v11; // cl
  LightingState_t *p_state; // ebx
  bool v13; // cc
  float *p_y; // esi
  dworldlight_t **i; // edi
  int v16; // eax
  float v17; // xmm0_4
  int result; // eax
  LightingState_t state; // [esp+0h] [ebp-64h] BYREF
  CModelRender *v20; // [esp+5Ch] [ebp-8h]
  int nLightCount; // [esp+60h] [ebp-4h]

  v8 = pEnvCubemapTexture;
  v9 = handle;
  m_pRenderable = nullptr;
  v20 = this;
  nLightCount = 0;
  memset(&state, 0, 76);
  *pEnvCubemapTexture = nullptr;
  if ( v9 != 0xFFFF )
    m_pRenderable = this->m_ModelInstances.m_Memory.m_pMemory[v9].m_Element.m_pRenderable;
  v11 = 7;
  if ( (_BYTE)bAllowFast != 0 )
    v11 = 15;
  *v8 = LightcacheGetDynamic(
          a1: 0.0,
          origin: vecLightingOrigin,
          lightingState: &state,
          stats: (LightcacheGetDynamic_Stats *)&pEnvCubemapTexture,
          pRenderable: m_pRenderable,
          flags: v11,
          bDebugModel: false);
  p_state = &state;
  if ( v9 != 0xFFFF )
    p_state = CModelRender::TimeAverageLightingState(
                this: v20,
                handle: v9,
                pLightingState: &state,
                nEntIndex: 0,
                pLightingOrigin: vecLightingOrigin);
  qmemcpy(pColors, p_state, 0x48u);
  v13 = p_state->numlights <= 0;
  bAllowFast = 0;
  if ( v13 )
    return nLightCount;
  p_y = &pLocalLights->m_Color.y;
  for ( i = p_state->locallight; ; ++i )
  {
    if ( WorldLightToMaterialLight(pWorldLight: *i, light: (LightDesc_t *)(p_y - 2)) != 0 )
    {
      v16 = d_lightstylevalue[(*i)->style];
      if ( v16 != 264 )
      {
        v17 = (float)v16 * 0.0037878789;
        *(p_y - 1) = *(p_y - 1) * v17;
        *p_y = *p_y * v17;
        p_y[1] = v17 * p_y[1];
      }
      result = nLightCount + 1;
      p_y += 22;
      nLightCount = result;
      if ( result >= nMaxLocalLights )
        break;
    }
    if ( ++bAllowFast >= p_state->numlights )
      return nLightCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DCFC0
// Name: private: void CModelRender::ComputeAmbientBoost(int,struct LightingQuery_t const __near *,struct MaterialLightingState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ComputeAmbientBoost(
        CModelRender *this,
        int nCount,
        const LightingQuery_t *pQuery,
        MaterialLightingState_t *pState)
{
  double v4; // st5
  double v5; // st4
  bool *p_m_bAmbientBoost; // edi
  float *p_z; // ecx
  int i; // ebx
  int v9; // esi
  double v10; // st3
  double v11; // st2
  double v12; // st5
  double v13; // rt1
  double v14; // st3
  double v15; // st4
  float v16; // xmm1_4
  double v17; // st3
  double v18; // st2
  double v19; // st5
  double v20; // rtt
  double v21; // st3
  double v22; // st4
  float v23; // xmm0_4
  double v24; // st3
  double v25; // st2
  double v26; // st5
  double v27; // rt1
  double v28; // st3
  double v29; // st4
  float v30; // xmm1_4
  double v31; // st3
  double v32; // st2
  double v33; // st5
  double v34; // rtt
  double v35; // st3
  double v36; // st4
  float v37; // xmm0_4
  double v38; // st3
  double v39; // st2
  double v40; // st5
  double v41; // rt1
  double v42; // st3
  double v43; // st4
  float v44; // xmm1_4
  double v45; // st3
  double v46; // st2
  double v47; // rtt
  double v48; // st3
  float v49; // xmm4_4
  float *v50; // edx
  float v51; // xmm3_4
  long double v52; // st2
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  float m_fValue; // xmm0_4
  float maxCubeLuminance; // [esp+4h] [ebp-8h]
  float avgCubeLuminance; // [esp+8h] [ebp-4h]
  float denom; // [esp+14h] [ebp+8h]
  float denoma; // [esp+14h] [ebp+8h]
  float denomb; // [esp+14h] [ebp+8h]
  float denomc; // [esp+14h] [ebp+8h]
  float denomd; // [esp+14h] [ebp+8h]
  float denome; // [esp+14h] [ebp+8h]
  float denomf; // [esp+14h] [ebp+8h]
  float d2; // [esp+18h] [ebp+Ch]

  if ( r_ambientboost.m_pParent != nullptr && r_ambientboost.m_pParent->m_Value.m_nValue != 0 )
  {
    avgCubeLuminance = 0.0;
    if ( nCount > 0 )
    {
      v4 = 3.4028235e38;
      v5 = 0.0;
      p_m_bAmbientBoost = &pQuery->m_bAmbientBoost;
      p_z = &pState->m_vecAmbientCube[1].z;
      for ( i = nCount; i != 0; --i )
      {
        if ( *p_m_bAmbientBoost )
        {
          v9 = *((_DWORD *)p_z + 16);
          if ( v9 != 0 )
          {
            v10 = *(p_z - 4) * 0.58999997 + *(p_z - 5) * 0.30000001 + *(p_z - 3) * 0.11;
            denom = v10;
            v11 = v4;
            v12 = v10;
            if ( v11 <= v10 )
              v12 = v11;
            v13 = v10;
            v14 = v5;
            v15 = v13;
            if ( v14 >= v13 )
              v15 = v14;
            v16 = denom + avgCubeLuminance;
            v17 = *(p_z - 2) * 0.30000001 + *(p_z - 1) * 0.58999997 + *p_z * 0.11;
            denoma = v17;
            v18 = v12;
            v19 = v17;
            if ( v18 <= v17 )
              v19 = v18;
            v20 = v17;
            v21 = v15;
            v22 = v20;
            if ( v21 >= v20 )
              v22 = v21;
            v23 = denoma + v16;
            v24 = p_z[2] * 0.58999997 + p_z[1] * 0.30000001 + p_z[3] * 0.11;
            denomb = v24;
            v25 = v19;
            v26 = v24;
            if ( v25 <= v24 )
              v26 = v25;
            v27 = v24;
            v28 = v22;
            v29 = v27;
            if ( v28 >= v27 )
              v29 = v28;
            v30 = denomb + v23;
            v31 = p_z[5] * 0.58999997 + p_z[4] * 0.30000001 + p_z[6] * 0.11;
            denomc = v31;
            v32 = v26;
            v33 = v31;
            if ( v32 <= v31 )
              v33 = v32;
            v34 = v31;
            v35 = v29;
            v36 = v34;
            if ( v35 >= v34 )
              v36 = v35;
            v37 = denomc + v30;
            v38 = p_z[8] * 0.58999997 + p_z[7] * 0.30000001 + p_z[9] * 0.11;
            denomd = v38;
            v39 = v33;
            v40 = v38;
            if ( v39 <= v38 )
              v40 = v39;
            v41 = v38;
            v42 = v36;
            v43 = v41;
            if ( v42 >= v41 )
              v43 = v42;
            v44 = denomd + v37;
            v45 = p_z[11] * 0.58999997 + p_z[10] * 0.30000001 + p_z[12] * 0.11;
            denome = v45;
            v46 = v40;
            v4 = v45;
            if ( v46 <= v45 )
              v4 = v46;
            v47 = v45;
            v48 = v43;
            v5 = v47;
            if ( v48 >= v47 )
              v5 = v48;
            avgCubeLuminance = (float)(denome + v44) * 0.16666667;
            v49 = 0.0;
            if ( v9 > 0 )
            {
              v50 = p_z + 23;
              do
              {
                d2 = (float)((float)((float)(*(v50 - 1) - p_z[14]) * (float)(*(v50 - 1) - p_z[14]))
                           + (float)((float)(*(v50 - 2) - p_z[13]) * (float)(*(v50 - 2) - p_z[13])))
                   + (float)((float)(*v50 - p_z[15]) * (float)(*v50 - p_z[15]));
                v51 = 1.0;
                v52 = d2 * v50[8] + sqrt(d2) * v50[7] + v50[6];
                if ( v52 > 0.0000099999997 )
                {
                  denomf = v52;
                  v51 = 1.0 / denomf;
                }
                v53 = *(v50 - 4);
                v54 = (float)(*(v50 - 5) * v51) * 0.30000001;
                v55 = (float)(*(v50 - 3) * v51) * 0.11;
                v50 += 22;
                --v9;
                v49 = (float)((float)((float)((float)(v53 * v51) * 0.58999997) + v54) + v55) + v49;
              }
              while ( v9 != 0 );
            }
            v56 = r_ambientfraction.m_pParent->m_Value.m_fValue * v49;
            if ( r_ambientmin.m_pParent->m_Value.m_fValue > avgCubeLuminance && v56 > avgCubeLuminance )
            {
              maxCubeLuminance = v5;
              m_fValue = v56 / maxCubeLuminance;
              if ( r_ambientfactor.m_pParent->m_Value.m_fValue <= m_fValue )
                m_fValue = r_ambientfactor.m_pParent->m_Value.m_fValue;
              *(p_z - 5) = *(p_z - 5) * m_fValue;
              *(p_z - 4) = *(p_z - 4) * m_fValue;
              *(p_z - 3) = *(p_z - 3) * m_fValue;
              *(p_z - 2) = m_fValue * *(p_z - 2);
              *(p_z - 1) = *(p_z - 1) * m_fValue;
              *p_z = *p_z * m_fValue;
              p_z[1] = m_fValue * p_z[1];
              p_z[2] = p_z[2] * m_fValue;
              p_z[3] = p_z[3] * m_fValue;
              p_z[4] = m_fValue * p_z[4];
              p_z[5] = p_z[5] * m_fValue;
              p_z[6] = p_z[6] * m_fValue;
              p_z[7] = m_fValue * p_z[7];
              p_z[8] = p_z[8] * m_fValue;
              p_z[9] = p_z[9] * m_fValue;
              p_z[10] = m_fValue * p_z[10];
              p_z[11] = p_z[11] * m_fValue;
              p_z[12] = p_z[12] * m_fValue;
            }
          }
        }
        p_z += 110;
        p_m_bAmbientBoost += 16;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD3E0
// Name: public: virtual void CModelRender::ComputeLightingState(int,struct LightingQuery_t const __near *,struct MaterialLightingState_t __near *,class ITexture __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ComputeLightingState(
        CModelRender *this,
        int nCount,
        const LightingQuery_t *pQuery,
        MaterialLightingState_t *pState,
        ITexture **ppEnvCubemapTexture)
{
  int v5; // ebx
  float *p_y; // edi
  float *p_z; // esi
  float *v8; // ebx
  int LightingConditions; // eax
  bool v10; // zf
  float *v11; // eax
  int v13; // [esp+Ch] [ebp-4h]

  v5 = nCount;
  if ( nCount > 0 )
  {
    p_y = &pQuery->m_LightingOrigin.y;
    p_z = &pState->m_vecLightingOrigin.z;
    v13 = nCount;
    do
    {
      v8 = p_y - 1;
      LightingConditions = CModelRender::GetLightingConditions(
                             this,
                             vecLightingOrigin: (const Vector *)(p_y - 1),
                             pColors: (Vector *)(p_z - 20),
                             nMaxLocalLights: 4,
                             pLocalLights: (LightDesc_t *)(p_z + 2),
                             pEnvCubemapTexture: ppEnvCubemapTexture++,
                             handle: *((_WORD *)p_y + 4),
                             bAllowFast: 1);
      *((_DWORD *)p_z + 1) = LightingConditions;
      p_y += 4;
      *(p_z - 2) = *v8;
      p_z += 110;
      v10 = v13-- == 1;
      *(p_z - 111) = *(p_y - 4);
      *(p_z - 110) = *(p_y - 3);
    }
    while ( !v10 );
    v5 = nCount;
  }
  CModelRender::ComputeAmbientBoost(this, nCount: v5, pQuery, pState);
  if ( mat_fullbright.m_pParent != nullptr && mat_fullbright.m_pParent->m_Value.m_nValue == 1 && v5 > 0 )
  {
    v11 = &pState->m_vecAmbientCube[1].z;
    do
    {
      v11[16] = 0.0;
      *(v11 - 5) = 1.0;
      *(v11 - 4) = 1.0;
      *(v11 - 3) = 1.0;
      *(v11 - 2) = 1.0;
      *(v11 - 1) = 1.0;
      *v11 = 1.0;
      v11[1] = 1.0;
      v11[2] = 1.0;
      v11[3] = 1.0;
      v11[4] = 1.0;
      v11[5] = 1.0;
      v11[6] = 1.0;
      v11[7] = 1.0;
      v11[8] = 1.0;
      v11[9] = 1.0;
      v11[10] = 1.0;
      v11[11] = 1.0;
      v11[12] = 1.0;
      v11 += 110;
      --v5;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD500
// Name: public: virtual void CModelRender::GetModelDecalHandles(struct StudioDecalHandle_t__ __near * __near *,int,int,unsigned short const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::GetModelDecalHandles(
        CModelRender *this,
        StudioDecalHandle_t__ **pDecals,
        int nDecalStride,
        int nCount,
        const unsigned __int16 *pHandles)
{
  int i; // eax
  int v7; // edx
  StudioDecalHandle_t__ *m_DecalHandle; // edx

  for ( i = 0; i < nCount; pDecals = (StudioDecalHandle_t__ **)((char *)pDecals + nDecalStride) )
  {
    v7 = pHandles[i];
    if ( (_WORD)v7 == 0xFFFF )
      m_DecalHandle = nullptr;
    else
      m_DecalHandle = this->m_ModelInstances.m_Memory.m_pMemory[v7].m_Element.m_DecalHandle;
    *pDecals = m_DecalHandle;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD560
// Name: public: virtual bool CModelRender::DrawModelSetup(class IMatRenderContext __near *,struct ModelRenderInfo_t __near &,struct DrawModelState_t __near *,struct matrix3x4_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelRender::DrawModelSetup(
        CModelRender *this,
        IMatRenderContext *pRenderContext,
        ModelRenderInfo_t *pInfo,
        DrawModelState_t *pState,
        matrix3x4_t **ppBoneToWorldOut)
{
  int studio; // eax
  studiohdr_t *v7; // eax
  int m_nValue; // ecx
  const matrix3x4_t *pModelToWorld; // eax
  studiohwdata_t *v10; // eax
  int v11; // eax
  IClientRenderable *pRenderable; // edi
  IClientRenderable_vtbl *v13; // esi
  CClientState *v14; // eax
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  IClientRenderable_vtbl *v17; // eax
  CClientState *BaseLocalClient; // eax
  int instance; // eax
  int flags; // eax
  float v21; // [esp+Ch] [ebp-28h]
  float Time; // [esp+Ch] [ebp-28h]
  CMatRenderData<matrix3x4a_t> rdBoneToWorld; // [esp+1Ch] [ebp-18h] BYREF
  IClientRenderable_vtbl *v24; // [esp+2Ch] [ebp-8h]
  CModelRender *v25; // [esp+30h] [ebp-4h]
  IClientRenderable *pRenderContexta; // [esp+3Ch] [ebp+8h]
  int boneMask; // [esp+40h] [ebp+Ch]

  *ppBoneToWorldOut = nullptr;
  studio = pInfo->pModel->studio;
  v25 = this;
  v7 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: studio);
  pState->m_pStudioHdr = v7;
  pState->m_pRenderable = pInfo->pRenderable;
  if ( r_entity.m_pParent != nullptr )
  {
    m_nValue = r_entity.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
      goto LABEL_3;
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue != pInfo->entity_index )
    return 0;
LABEL_3:
  if ( v7->numbodyparts == 0 )
    return 0;
  pModelToWorld = pInfo->pModelToWorld;
  if ( pModelToWorld == nullptr )
    return 0;
  pState->m_pModelToWorld = pModelToWorld;
  v10 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: pInfo->pModel->studio);
  pState->m_pStudioHWData = v10;
  if ( v10 == nullptr )
    return 0;
  v11 = CModelRender::ComputeLOD(this: v25, pRenderContext, info: pInfo, pStudioHWData: v10);
  pState->m_lod = v11;
  boneMask = 1024 << v11;
  if ( (pInfo->flags & 1) != 0 )
  {
    LockRenderData = pRenderContext->LockRenderData;
    rdBoneToWorld.m_nCount = pState->m_pStudioHdr->numbones;
    rdBoneToWorld.m_pRenderContext = pRenderContext;
    rdBoneToWorld.m_pRenderData = (matrix3x4a_t *)LockRenderData(this: pRenderContext, a2: 48 * rdBoneToWorld.m_nCount);
    pRenderContexta = pInfo->pRenderable;
    v17 = pRenderContexta->__vftable;
    rdBoneToWorld.m_bNeedsUnlock = true;
    v24 = v17;
    BaseLocalClient = GetBaseLocalClient();
    Time = CClientState::GetTime(this: BaseLocalClient);
    if ( ((unsigned __int8 (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, int, _DWORD))v24->SetupBones)(
           a1: pRenderContexta,
           a2: rdBoneToWorld.m_pRenderData,
           a3: rdBoneToWorld.m_nCount,
           a4: boneMask,
           a5: LODWORD(Time)) != 0 )
    {
      *ppBoneToWorldOut = rdBoneToWorld.m_pRenderData;
      pState->m_decals = nullptr;
      instance = pInfo->instance;
      if ( (_WORD)instance != 0xFFFF )
        pState->m_decals = v25->m_ModelInstances.m_Memory.m_pMemory[instance].m_Element.m_DecalHandle;
      pState->m_drawFlags = 0;
      flags = pInfo->flags;
      if ( (flags & 8) != 0 )
        pState->m_drawFlags = (flags < 0) + 1;
      if ( (pInfo->flags & 0x10) != 0 )
        pState->m_drawFlags |= 8u;
      if ( (pInfo->flags & 0x40) != 0 )
        pState->m_drawFlags |= 0x100u;
      if ( (pInfo->flags & 0x20) != 0 )
        pState->m_drawFlags |= 0x80u;
      if ( SLOBYTE(pInfo->flags) < 0 )
        pState->m_drawFlags |= 0x20u;
      if ( r_drawmodelstatsoverlay.m_pParent != nullptr && r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue == 2 )
        pState->m_drawFlags |= 0x10u;
      if ( (pInfo->flags & 0x40000000) != 0 )
        pState->m_drawFlags |= 0x200u;
      CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &rdBoneToWorld);
      return 1;
    }
    else
    {
      CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &rdBoneToWorld);
      return 0;
    }
  }
  else
  {
    pRenderable = pInfo->pRenderable;
    v13 = pRenderable->__vftable;
    v14 = GetBaseLocalClient();
    v21 = CClientState::GetTime(this: v14);
    return ((int (__thiscall *)(IClientRenderable *, _DWORD, int, int, _DWORD))v13->SetupBones)(
             a1: pRenderable,
             a2: 0,
             a3: 256,
             a4: boneMask,
             a5: LODWORD(v21));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD780
// Name: private: void CModelRender::ComputeModelVertexLightingOld(struct mstudiomodel_t __near *,struct matrix3x4_t __near &,struct LightingState_t const __near &,struct color24 __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ComputeModelVertexLightingOld(
        CModelRender *this,
        mstudiomodel_t *pModel,
        matrix3x4_t *matrix,
        const LightingState_t *lightingState,
        color24 *pLighting,
        bool bUseConstDirLighting,
        float flConstDirLightAmount)
{
  int v7; // ebx
  vertexFileHeader_t *VertexData; // ecx
  unsigned int v9; // edi
  vertexFileHeader_t *v10; // eax
  const thinModelVertices_t *v11; // eax
  color24 *v12; // eax
  const matrix3x4_t *v13; // edi
  unsigned __int8 *p_b; // esi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  float z; // xmm0_4
  float y; // xmm3_4
  LightDesc_t lightDesc[4]; // [esp+14h] [ebp-1D0h] BYREF
  Vector normal; // [esp+174h] [ebp-70h] BYREF
  Vector position; // [esp+180h] [ebp-64h] BYREF
  float v24; // [esp+18Ch] [ebp-58h]
  float v25; // [esp+190h] [ebp-54h]
  float v26; // [esp+194h] [ebp-50h]
  const mstudio_modelvertexdata_t *vertData; // [esp+198h] [ebp-4Ch]
  float v28; // [esp+19Ch] [ebp-48h]
  float v29; // [esp+1A0h] [ebp-44h]
  float v30; // [esp+1A4h] [ebp-40h]
  const thinModelVertices_t *thinVertData; // [esp+1A8h] [ebp-3Ch]
  int v32; // [esp+1ACh] [ebp-38h]
  int v33; // [esp+1B0h] [ebp-34h]
  int nNumLightDesc; // [esp+1B4h] [ebp-30h] BYREF
  int v35; // [esp+1B8h] [ebp-2Ch]
  Vector worldPos; // [esp+1BCh] [ebp-28h] BYREF
  Vector worldNormal; // [esp+1C8h] [ebp-1Ch] BYREF
  Vector destColor; // [esp+1D4h] [ebp-10h] BYREF
  bool bHasSSE; // [esp+1E3h] [ebp-1h]
  color24 *pLightinga; // [esp+1F8h] [ebp+14h]

  v7 = 0;
  R_SetNonAmbientLightingState(
    numLights: lightingState->numlights,
    locallight: lightingState->locallight,
    pNumLightDescs: &nNumLightDesc,
    pLightDescs: lightDesc,
    bUpdateStudioRenderLights: false);
  thinVertData = nullptr;
  VertexData = mstudiomodel_t::GetVertexData(this: pModel, pModelData: nullptr);
  v9 = 0;
  vertData = (const mstudio_modelvertexdata_t *)VertexData;
  if ( VertexData != nullptr )
  {
    v9 = VertexData->id + 48 * (VertexData[-1].numLODVertexes[6] / 0x30u);
  }
  else
  {
    v10 = g_pMDLCache->GetVertexData(this: g_pMDLCache, a2: LOWORD(s_ModelRender.m_pStudioHdr->virtualModel));
    if ( v10 == nullptr )
      return;
    if ( v10->id == 1447248969 && (VertexData = (vertexFileHeader_t *)v10->vertexDataStart) != nullptr )
      v11 = (const thinModelVertices_t *)((char *)v10 + (_DWORD)VertexData);
    else
      v11 = nullptr;
    thinVertData = v11;
    if ( v11 == nullptr )
      return;
  }
  bHasSSE = CBaseServer::ShouldUpdateMasterServer(this: (vgui::Splitter *)VertexData);
  if ( pModel->numvertices > 0 )
  {
    v12 = (color24 *)(v9 + 16);
    v13 = matrix;
    p_b = &pLighting->b;
    for ( pLightinga = v12; ; v12 = pLightinga )
    {
      if ( vertData != nullptr )
      {
        if ( bHasSSE )
          _mm_prefetch((const char *)&v12[10].b, 1);
        VectorTransform(in1: (const float *)&v12->r, in2: v13, out: &worldPos.x);
        VectorRotate(in1: (const float *)&pLightinga[4].r, in2: v13, out: &worldNormal.x);
      }
      else
      {
        v15 = pModel->vertexindex / 0x30u + v7;
        position = thinVertData->m_vecPositions[v15];
        thinModelVertices_t::GetNormal(this: (thinModelVertices_t *)thinVertData, vertIndex: v15, pNormal: &normal);
        v13 = matrix;
        VectorTransform(in1: &position.x, in2: matrix, out: &worldPos.x);
        VectorRotate(in1: &normal.x, in2: matrix, out: &worldNormal.x);
      }
      if ( bUseConstDirLighting )
        ((void (__stdcall *)(const LightingState_t *, int, LightDesc_t *, Vector *, Vector *, Vector *, _DWORD))g_pStudioRender->ComputeLightingConstDirectional)(
          a1: lightingState,
          a2: nNumLightDesc,
          a3: lightDesc,
          a4: &worldPos,
          a5: &worldNormal,
          a6: &destColor,
          a7: LODWORD(flConstDirLightAmount));
      else
        g_pStudioRender->ComputeLighting(
          this: g_pStudioRender,
          a2: (const Vector *)lightingState,
          a3: nNumLightDesc,
          a4: lightDesc,
          a5: &worldPos,
          a6: &worldNormal,
          a7: &destColor);
      v24 = destColor.x * 1024.0;
      v33 = (int)(float)(destColor.x * 1024.0);
      v16 = v33;
      if ( (unsigned int)v33 > 0xFFF )
        v16 = v33 < 0 ? 0 : 0xFFF;
      destColor.x = lineartovertex[v16];
      v29 = destColor.y * 1024.0;
      v35 = (int)(float)(destColor.y * 1024.0);
      v17 = v35;
      if ( (unsigned int)v35 > 0xFFF )
        v17 = v35 < 0 ? 0 : 0xFFF;
      destColor.y = lineartovertex[v17];
      v30 = destColor.z * 1024.0;
      v32 = (int)(float)(destColor.z * 1024.0);
      v18 = v32;
      if ( (unsigned int)v32 > 0xFFF )
        v18 = v32 < 0 ? 0 : 0xFFF;
      pLightinga += 16;
      destColor.z = lineartovertex[v18];
      z = destColor.z;
      v28 = (float)(destColor.x * 255.0) + 8388608.0;
      y = destColor.y;
      *(p_b - 2) = LOBYTE(v28);
      v25 = (float)(y * 255.0) + 8388608.0;
      *(p_b - 1) = LOBYTE(v25);
      v26 = (float)(z * 255.0) + 8388608.0;
      *p_b = LOBYTE(v26);
      ++v7;
      p_b += 3;
      if ( v7 >= pModel->numvertices )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDA60
// Name: public: virtual void CModelRender::SetStaticLighting(unsigned short,struct LightCacheHandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetStaticLighting(
        CModelRender *this,
        unsigned __int16 handle,
        LightCacheHandle_t__ **pCache)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v3; // eax
  LightCacheHandle_t__ *v4; // ecx

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
    if ( pCache != nullptr )
    {
      v4 = *pCache;
      v3->m_Element.m_nFlags |= 1u;
      v3->m_Element.m_LightCacheHandle = v4;
    }
    else
    {
      v3->m_Element.m_nFlags &= ~1u;
      v3->m_Element.m_LightCacheHandle = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDAB0
// Name: public: virtual struct LightCacheHandle_t__ __near * CModelRender::GetStaticLighting(unsigned short)
// Source: json
//------------------------------------------------------------------------------
LightCacheHandle_t__ *__thiscall CModelRender::GetStaticLighting(CModelRender *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v2; // eax

  if ( handle == 0xFFFF )
    return nullptr;
  v2 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  if ( (v2->m_Element.m_nFlags & 1) == 0 )
    return nullptr;
  else
    return v2->m_Element.m_LightCacheHandle;
}

//------------------------------------------------------------------------------
// Address: 0x100DDAE0
// Name: public: virtual bool CModelRender::ChangeInstance(unsigned short,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelRender::ChangeInstance(CModelRender *this, int handle, IClientRenderable *pRenderable)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v3; // esi

  if ( (_WORD)handle == 0xFFFF || pRenderable == nullptr )
    return 0;
  v3 = &this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)handle];
  if ( v3->m_Element.m_pModel == pRenderable->GetModel(this: pRenderable) )
  {
    g_pShadowMgr->RemoveAllShadowsFromModel(this: g_pShadowMgr, a2: handle);
    v3->m_Element.m_pRenderable = pRenderable;
    return 1;
  }
  else
  {
    DevMsg(a1: "MoveInstanceHandle: models are different!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDB50
// Name: private: bool CModelRender::IsModelInstanceValid(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelRender::IsModelInstanceValid(CModelRender *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v3; // esi

  if ( handle == 0xFFFF )
    return false;
  v3 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  return v3->m_Element.m_DecalHandle != nullptr
      && v3->m_Element.m_pModel == v3->m_Element.m_pRenderable->GetModel(this: v3->m_Element.m_pRenderable);
}

//------------------------------------------------------------------------------
// Address: 0x100DDBA0
// Name: public: virtual void CModelRender::RemoveAllDecals(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::RemoveAllDecals(CModelRender *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v2; // esi

  if ( handle != 0xFFFF )
  {
    v2 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
    if ( v2->m_Element.m_DecalHandle != nullptr
      && v2->m_Element.m_pModel == v2->m_Element.m_pRenderable->GetModel(this: v2->m_Element.m_pRenderable) )
    {
      g_pStudioRender->DestroyDecalList(this: g_pStudioRender, a2: v2->m_Element.m_DecalHandle);
      v2->m_Element.m_DecalHandle = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDC00
// Name: void SetRootLOD_f(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetRootLOD_f(IConVar *pConVar, const char *pOldString)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  if ( CheckVarRange_Generic(pVar: &r_rootlod, minVal: 0, maxVal: 2) == 0 )
  {
    ConVarRef::ConVarRef(this: &var, pConVar);
    UpdateStudioRenderConfig();
    if ( !g_LostVideoMemory && _V_strcmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: pOldString) != 0 )
      modelloader->Studio_ReloadModels(this: modelloader, a2: RELOAD_LOD_CHANGED);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDC60
// Name: void FlushLOD_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FlushLOD_f()
{
  UpdateStudioRenderConfig();
  if ( !g_LostVideoMemory )
    modelloader->Studio_ReloadModels(this: modelloader, a2: RELOAD_EVERYTHING);
}

//------------------------------------------------------------------------------
// Address: 0x100DE0A0
// Name: public: void CColorMeshData::DestroyResource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorMeshData::DestroyResource(CColorMeshData *this)
{
  IMatRenderContext *m_pObject; // ebx
  int v3; // edi
  ColorMeshInfo_t *m_pMeshInfos; // eax
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
  g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: this->m_hAsyncControl);
  m_pObject = materials->GetRenderContext(this: materials);
  v3 = 0;
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  for ( i = 0; i < this->m_nMeshes; ++i )
  {
    m_pMeshInfos = this->m_pMeshInfos;
    if ( m_pMeshInfos[v3].m_pPooledVBAllocator != nullptr )
    {
      m_pMeshInfos[v3].m_pPooledVBAllocator->Deallocate(
        this: m_pMeshInfos[v3].m_pPooledVBAllocator,
        a2: m_pMeshInfos[v3].m_nVertOffsetInBytes,
        a3: m_pMeshInfos[v3].m_nNumVerts);
      m_pObject = pRenderContext.m_pObject;
    }
    else
    {
      m_pObject->DestroyStaticMesh(this: m_pObject, a2: m_pMeshInfos[v3].m_pMesh);
    }
    ++v3;
  }
  free(pMem: this->m_pMeshInfos);
  free(pMem: this->m_ppTargets);
  free(pMem: this);
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE180
// Name: public: static class CColorMeshData __near * CColorMeshData::CreateResource(struct colormeshparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CColorMeshData *__cdecl CColorMeshData::CreateResource(const colormeshparams_t *params)
{
  CColorMeshData *v1; // esi
  ColorMeshInfo_t *v3; // eax
  IMatRenderContext *m_pObject; // ebx
  int v5; // eax
  int v6; // ebx
  ColorMeshInfo_t *m_pMeshInfos; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *v10; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1FCh] BYREF
  unsigned __int64 vertexFormat; // [esp+1F4h] [ebp-14h]
  MaterialLock_t__ *hLock; // [esp+1FCh] [ebp-Ch]
  CMatRenderContextPtr pRenderContext; // [esp+200h] [ebp-8h]
  int numLightingComponents; // [esp+204h] [ebp-4h]
  int i; // [esp+210h] [ebp+8h]

  v1 = (CColorMeshData *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( r_staticlight_streams.m_pParent != nullptr )
    numLightingComponents = r_staticlight_streams.m_pParent->m_Value.m_nValue;
  else
    numLightingComponents = 0;
  *((_DWORD *)v1 + 5) &= 0xFFFFFFFC;
  v1->m_hAsyncControl = nullptr;
  v1->m_fnHandle = params->m_fnHandle;
  v1->m_nTotalSize = 4 * (params->m_nMeshes + numLightingComponents * params->m_nTotalVertexes);
  v1->m_nMeshes = params->m_nMeshes;
  v3 = (ColorMeshInfo_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)params->m_nMeshes >> 28 != 0 ? -1 : 16 * params->m_nMeshes);
  v1->m_pMeshInfos = v3;
  _V_memset(dest: v3, fill: 0, count: 16 * params->m_nMeshes);
  v1->m_ppTargets = (unsigned __int8 **)MemAlloc_Alloc(
                                          nSize: (unsigned __int64)(unsigned int)params->m_nMeshes >> 30 != 0
                                        ? -1
                                        : 4 * params->m_nMeshes);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  hLock = materials->Lock(this: materials);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v5 = 0;
  i = 0;
  if ( params->m_nMeshes <= 0 )
  {
LABEL_34:
    materials->Unlock(this: materials, a2: hLock);
    if ( m_pObject != nullptr )
    {
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
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
    return v1;
  }
  else
  {
    v6 = 0;
    while ( 1 )
    {
      LODWORD(vertexFormat) = 8;
      if ( numLightingComponents > 1 )
        LODWORD(vertexFormat) = 2;
      v1->m_pMeshInfos[v6].m_pMesh = nullptr;
      v1->m_pMeshInfos[v6].m_pPooledVBAllocator = params->m_pPooledVBAllocator;
      v1->m_pMeshInfos[v6].m_nVertOffsetInBytes = 0;
      v1->m_pMeshInfos[v6].m_nNumVerts = params->m_nVertexes[v5];
      if ( params->m_pPooledVBAllocator != nullptr )
      {
        v1->m_pMeshInfos[v6].m_nVertOffsetInBytes = params->m_pPooledVBAllocator->Allocate(
                                                      this: params->m_pPooledVBAllocator,
                                                      a2: params->m_nVertexes[v5]);
        m_pMeshInfos = v1->m_pMeshInfos;
        if ( m_pMeshInfos[v6].m_nVertOffsetInBytes == -1 )
        {
          m_pMeshInfos[v6].m_pPooledVBAllocator = nullptr;
          v1->m_pMeshInfos[v6].m_nVertOffsetInBytes = 0;
        }
        else
        {
          v1->m_pMeshInfos[v6].m_pMesh = params->m_pPooledVBAllocator->GetSharedMesh(this: params->m_pPooledVBAllocator);
          v1->m_ppTargets[i] = (unsigned __int8 *)params->m_pPooledVBAllocator->GetVertexBufferBase(this: params->m_pPooledVBAllocator)
                             + v1->m_pMeshInfos[v6].m_nVertOffsetInBytes;
        }
      }
      if ( v1->m_pMeshInfos[v6].m_pMesh == nullptr )
      {
        if ( g_VBAllocTracker != nullptr )
          g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: "CColorMeshData::CreateResource");
        v1->m_pMeshInfos[v6].m_pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, const char *, _DWORD, _DWORD))pRenderContext.m_pObject->CreateStaticMesh)(
                                                  a1: pRenderContext.m_pObject,
                                                  a2: vertexFormat,
                                                  a3: 0,
                                                  a4: "Lighting Verts",
                                                  a5: 0,
                                                  a6: 0);
        CMeshBuilder::Begin(
          this: &meshBuilder,
          pMesh: v1->m_pMeshInfos[v6].m_pMesh,
          type: MATERIAL_HETEROGENOUS,
          nVertexCount: params->m_nVertexes[i],
          nIndexCount: 0,
          pMeshSettings: nullptr);
        if ( numLightingComponents <= 1 )
          v1->m_ppTargets[i] = &meshBuilder.m_VertexBuilder.m_pSpecular[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                                      * meshBuilder.m_VertexBuilder.m_VertexSize_Specular];
        else
          v1->m_ppTargets[i] = (unsigned __int8 *)meshBuilder.m_VertexBuilder.m_pCurrNormal;
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
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        if ( g_VBAllocTracker != nullptr )
          g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
      }
      if ( v1->m_pMeshInfos[v6].m_pMesh == nullptr )
        break;
      v5 = i + 1;
      ++v6;
      i = v5;
      if ( v5 >= params->m_nMeshes )
      {
        m_pObject = pRenderContext.m_pObject;
        goto LABEL_34;
      }
    }
    CColorMeshData::DestroyResource(this: v1);
    materials->Unlock(this: materials, a2: hLock);
    v10 = pRenderContext.m_pObject;
    if ( pRenderContext.m_pObject != nullptr )
    {
      pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
      v10->Release(this: v10);
    }
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
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE580
// Name: private: void CModelRender::StudioSetupLighting(struct DrawModelState_t const __near &,class Vector const __near &,struct LightCacheHandle_t__ __near * __near *,bool,bool,bool __near &,struct DrawModelInfo_t __near &,struct ModelRenderInfo_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CModelRender::StudioSetupLighting(
        CModelRender *this,
        const DrawModelState_t *state,
        const Vector *absEntCenter,
        LightCacheHandle_t__ **pLightcache,
        bool bVertexLit,
        bool bNeedsEnvCubemap,
        bool *bStaticLighting,
        DrawModelInfo_t *drawInfo,
        const ModelRenderInfo_t *pInfo,
        __int16 drawFlags)
{
  bool v10; // zf
  float z; // edx
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // eax
  IMatRenderContext *v14; // eax
  IMatRenderContext *v15; // edi
  Vector *pLightingOrigin; // eax
  const matrix3x4_t *pLightingOffset; // ecx
  int instance; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v19; // edi
  LightCacheHandle_t__ *v20; // eax
  LightCacheHandle_t__ *Static; // eax
  float *p_m_flLightingTime; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *v25; // eax
  float v26; // xmm1_4
  float v27; // xmm2_4
  float *v28; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  float *v31; // eax
  float v32; // xmm1_4
  float v33; // xmm2_4
  float *v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  float *v37; // eax
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  ITexture *Dynamic; // eax
  model_t *m_pModel; // eax
  char *szPathName; // ecx
  char *m_pszString; // eax
  int v46; // ebx
  Vector *v47; // edi
  dworldlight_t *v48; // eax
  const matrix3x4_t *v49; // edx
  int v50; // ebx
  Vector *v51; // edi
  dworldlight_t *v52; // eax
  const matrix3x4_t *v53; // edx
  LightingState_t *p_lightingState; // edi
  IMatRenderContext *m_pObject; // ebx
  float v56; // xmm0_4
  float v57; // xmm2_4
  float v58; // xmm2_4
  float v59; // xmm2_4
  float v60; // xmm2_4
  float v61; // xmm2_4
  float v62; // xmm2_4
  float v63; // xmm2_4
  float v64; // xmm2_4
  float v65; // xmm2_4
  float v66; // xmm2_4
  float v67; // xmm2_4
  float v68; // xmm2_4
  float v69; // xmm2_4
  float v70; // xmm2_4
  float v71; // xmm2_4
  float v72; // xmm2_4
  float v73; // xmm2_4
  int numlights; // ecx
  float y; // xmm4_4
  float v76; // xmm5_4
  float v77; // xmm6_4
  float v78; // xmm0_4
  double v79; // st7
  double v80; // st6
  double v81; // st3
  double v82; // st7
  float v83; // xmm2_4
  double v84; // st2
  double v85; // rt0
  double v86; // st2
  double v87; // st7
  float v88; // xmm1_4
  double v89; // st3
  double v90; // rt1
  double v91; // st3
  double v92; // st7
  float v93; // xmm0_4
  double v94; // st3
  double v95; // rt2
  double v96; // st3
  double v97; // st7
  float v98; // xmm1_4
  double v99; // st6
  double v100; // rt0
  double v101; // st6
  double v102; // st7
  float v103; // xmm7_4
  float **locallight; // edx
  int i; // ebx
  float *v106; // ecx
  float v107; // xmm3_4
  long double v108; // st6
  float m_fValue; // xmm0_4
  float v110; // xmm2_4
  float v111; // xmm3_4
  float v112; // xmm1_4
  float v113; // xmm2_4
  float v114; // xmm3_4
  float v115; // xmm1_4
  float v116; // xmm2_4
  float v117; // xmm3_4
  float v118; // xmm1_4
  float v119; // xmm2_4
  float v120; // xmm3_4
  float v121; // xmm1_4
  float v122; // xmm2_4
  float v123; // xmm3_4
  int v124; // eax
  float v125; // xmm1_4
  float v126; // xmm0_4
  int v127; // edx
  float *p_z; // eax
  dworldlight_t *v129; // ecx
  double v130; // st7
  unsigned int x; // [esp+10h] [ebp-174h]
  float xa; // [esp+10h] [ebp-174h]
  Vector pSaveLightPos[4]; // [esp+20h] [ebp-164h] BYREF
  Vector vFinalAmbientCube[6]; // [esp+50h] [ebp-134h] BYREF
  LightingState_t lightingDecalState; // [esp+98h] [ebp-ECh] BYREF
  double v136; // [esp+F4h] [ebp-90h] OVERLAPPED BYREF
  LightingState_t lightingState; // [esp+FCh] [ebp-88h] BYREF
  Vector vecDebugLightingOrigin; // [esp+158h] [ebp-2Ch] BYREF
  CModelRender *v139; // [esp+164h] [ebp-20h]
  Vector *pDebugLightingOrigin; // [esp+168h] [ebp-1Ch]
  LightcacheGetDynamic_Stats bDebugModel; // [esp+16Ch] [ebp-18h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+170h] [ebp-14h]
  ITexture *pEnvCubemapTexture; // [esp+174h] [ebp-10h] BYREF
  Vector vLightingOrigin; // [esp+178h] [ebp-Ch] BYREF
  float avgCubeLuminance; // [esp+18Ch] [ebp+8h]
  CModelRender::ModelInstance_t *pModelInst; // [esp+190h] [ebp+Ch]
  float maxCubeLuminancea; // [esp+198h] [ebp+14h]
  float maxCubeLuminance; // [esp+198h] [ebp+14h]
  float maxCubeLuminanceb; // [esp+198h] [ebp+14h]
  float d2f; // [esp+19Ch] [ebp+18h]
  float d2; // [esp+19Ch] [ebp+18h]
  float d2a; // [esp+19Ch] [ebp+18h]
  float d2b; // [esp+19Ch] [ebp+18h]
  float d2c; // [esp+19Ch] [ebp+18h]
  float d2d; // [esp+19Ch] [ebp+18h]
  float d2e; // [esp+19Ch] [ebp+18h]
  float d2g; // [esp+19Ch] [ebp+18h]
  float denom; // [esp+1A0h] [ebp+1Ch]
  bool bHasDecals_3; // [esp+1A7h] [ebp+23h]

  v10 = !this->m_bSuppressEngineLighting;
  v139 = this;
  if ( v10 )
  {
    z = vec3_origin.z;
    vecDebugLightingOrigin.x = vec3_origin.x;
    vecDebugLightingOrigin.y = vec3_origin.y;
    drawInfo->m_bStaticLighting = *bStaticLighting;
    drawInfo->m_LightingState.m_nLocalLightCount = 0;
    pEnvCubemapTexture = nullptr;
    memset(&lightingState, 0, 76);
    vecDebugLightingOrigin.z = z;
    memset(&lightingDecalState, 0, 76);
    memset(&vLightingOrigin, 0, sizeof(vLightingOrigin));
    GetRenderContext = materials->GetRenderContext;
    pDebugLightingOrigin = nullptr;
    v14 = GetRenderContext(this: materials);
    v15 = v14;
    pRenderContext.m_pObject = v14;
    if ( v14 != nullptr )
      v14->BeginRender(this: v14);
    pLightingOrigin = (Vector *)pInfo->pLightingOrigin;
    if ( pLightingOrigin != nullptr )
    {
      vLightingOrigin = *pLightingOrigin;
    }
    else
    {
      pLightingOffset = pInfo->pLightingOffset;
      vLightingOrigin = *absEntCenter;
      if ( pLightingOffset != nullptr )
        VectorTransform(in1: &absEntCenter->x, in2: pLightingOffset, out: &vLightingOrigin.x);
    }
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))v15->SetLightingOrigin)(
      a1: v15,
      a2: LODWORD(vLightingOrigin.x),
      a3: LODWORD(vLightingOrigin.y),
      a4: LODWORD(vLightingOrigin.z));
    instance = pInfo->instance;
    v19 = nullptr;
    pModelInst = nullptr;
    bHasDecals_3 = false;
    if ( (_WORD)instance != 0xFFFF )
    {
      v19 = &v139->m_ModelInstances.m_Memory.m_pMemory[instance];
      pModelInst = &v19->m_Element;
      if ( v19 != nullptr )
        bHasDecals_3 = v19->m_Element.m_DecalHandle != nullptr;
    }
    if ( pLightcache != nullptr )
    {
      if ( !*bStaticLighting
        || (!StaticLightCacheAffectedByDynamicLight(handle: *pLightcache) ? (x = 6) : (x = 7),
            v20 = LightcacheGetStatic(cache: (PropLightcache_t *)*pLightcache, &pEnvCubemapTexture, flags: x),
            LightingState_t::operator=(this: &lightingState, __that: (const LightingState_t *)v20),
            !*bStaticLighting) )
      {
        Static = LightcacheGetStatic(cache: (PropLightcache_t *)*pLightcache, &pEnvCubemapTexture, flags: 7u);
        LightingState_t::operator=(this: &lightingState, __that: (const LightingState_t *)Static);
      }
      if ( r_decalstaticprops.m_pParent != nullptr
        && r_decalstaticprops.m_pParent->m_Value.m_nValue != 0
        && v19 != nullptr
        && drawInfo->m_bStaticLighting
        && bHasDecals_3 )
      {
        p_m_flLightingTime = &v19->m_Element.m_pLightingState->m_flLightingTime;
        v23 = p_m_flLightingTime[25] + lightingState.r_boxcolor[0].y;
        v24 = p_m_flLightingTime[26] + lightingState.r_boxcolor[0].z;
        drawInfo->m_LightingState.m_vecAmbientCube[0].x = p_m_flLightingTime[24] + lightingState.r_boxcolor[0].x;
        drawInfo->m_LightingState.m_vecAmbientCube[0].y = v23;
        drawInfo->m_LightingState.m_vecAmbientCube[0].z = v24;
        v25 = &v19->m_Element.m_pLightingState->m_flLightingTime;
        v26 = v25[28] + lightingState.r_boxcolor[1].y;
        v27 = v25[29] + lightingState.r_boxcolor[1].z;
        drawInfo->m_LightingState.m_vecAmbientCube[1].x = v25[27] + lightingState.r_boxcolor[1].x;
        drawInfo->m_LightingState.m_vecAmbientCube[1].y = v26;
        drawInfo->m_LightingState.m_vecAmbientCube[1].z = v27;
        v28 = &v19->m_Element.m_pLightingState->m_flLightingTime;
        v29 = v28[31] + lightingState.r_boxcolor[2].y;
        v30 = v28[32] + lightingState.r_boxcolor[2].z;
        drawInfo->m_LightingState.m_vecAmbientCube[2].x = v28[30] + lightingState.r_boxcolor[2].x;
        drawInfo->m_LightingState.m_vecAmbientCube[2].y = v29;
        drawInfo->m_LightingState.m_vecAmbientCube[2].z = v30;
        v31 = &v19->m_Element.m_pLightingState->m_flLightingTime;
        v32 = v31[34] + lightingState.r_boxcolor[3].y;
        v33 = v31[35] + lightingState.r_boxcolor[3].z;
        drawInfo->m_LightingState.m_vecAmbientCube[3].x = v31[33] + lightingState.r_boxcolor[3].x;
        drawInfo->m_LightingState.m_vecAmbientCube[3].y = v32;
        drawInfo->m_LightingState.m_vecAmbientCube[3].z = v33;
        v34 = &v19->m_Element.m_pLightingState->m_flLightingTime;
        v35 = v34[37] + lightingState.r_boxcolor[4].y;
        v36 = v34[38] + lightingState.r_boxcolor[4].z;
        drawInfo->m_LightingState.m_vecAmbientCube[4].x = v34[36] + lightingState.r_boxcolor[4].x;
        drawInfo->m_LightingState.m_vecAmbientCube[4].y = v35;
        drawInfo->m_LightingState.m_vecAmbientCube[4].z = v36;
        v37 = &v19->m_Element.m_pLightingState->m_flLightingTime;
        v38 = v37[39] + lightingState.r_boxcolor[5].x;
        v39 = v37[40] + lightingState.r_boxcolor[5].y;
        v40 = v37[41] + lightingState.r_boxcolor[5].z;
        drawInfo->m_LightingState.m_vecAmbientCube[5].x = v38;
        drawInfo->m_LightingState.m_vecAmbientCube[5].y = v39;
        drawInfo->m_LightingState.m_vecAmbientCube[5].z = v40;
        LightingState_t::CopyLocalLights(
          this: &lightingDecalState,
          src: &v19->m_Element.m_pLightingState->m_AmbientLightingState);
        LightingState_t::AddAllLocalLights(
          this: &lightingDecalState,
          a2: v38,
          src: &lightingState,
          vecLightingOrigin: &vLightingOrigin);
      }
    }
    else
    {
      v10 = !*bStaticLighting;
      vecDebugLightingOrigin = vLightingOrigin;
      v41 = vLightingOrigin.z;
      pDebugLightingOrigin = &vecDebugLightingOrigin;
      if ( v10
        || (Dynamic = LightcacheGetDynamic(
                        a1: vLightingOrigin.z,
                        origin: &vLightingOrigin,
                        &lightingState,
                        stats: &bDebugModel,
                        pRenderable: state->m_pRenderable,
                        flags: 6,
                        bDebugModel: false),
            v10 = !*bStaticLighting,
            pEnvCubemapTexture = Dynamic,
            v10) )
      {
        bDebugModel.m_bHasNonSwitchableLightStyles = false;
        if ( r_drawlightcache.m_pParent != nullptr
          && r_drawlightcache.m_pParent->m_Value.m_nValue == 5
          && v19 != nullptr )
        {
          m_pModel = v19->m_Element.m_pModel;
          if ( m_pModel != nullptr )
          {
            szPathName = m_pModel->szPathName;
            if ( m_pModel != (model_t *)-4 )
            {
              if ( (r_lightcachemodel.m_nFlags & 0x1000) != 0 )
              {
                m_pszString = "FCVAR_NEVER_AS_STRING";
              }
              else
              {
                m_pszString = r_lightcachemodel.m_pParent->m_Value.m_pszString;
                if ( m_pszString == nullptr )
                  m_pszString = (char *)defaultValue;
              }
              bDebugModel.m_bHasNonSwitchableLightStyles = V_stristr(pStr: szPathName, pSearch: m_pszString) != nullptr;
            }
          }
        }
        pEnvCubemapTexture = LightcacheGetDynamic(
                               a1: v41,
                               origin: &vLightingOrigin,
                               &lightingState,
                               stats: (LightcacheGetDynamic_Stats *)&v136 + 1,
                               pRenderable: state->m_pRenderable,
                               flags: 15,
                               bDebugModel: bDebugModel.m_bHasNonSwitchableLightStyles);
      }
      if ( pInfo->pLightingOffset != nullptr && pInfo->pLightingOrigin == nullptr )
      {
        v46 = 0;
        if ( lightingState.numlights > 0 )
        {
          v47 = pSaveLightPos;
          do
          {
            v48 = lightingState.locallight[v46];
            v49 = pInfo->pLightingOffset;
            v47->x = v48->origin.x;
            v47->y = v48->origin.y;
            v47->z = v48->origin.z;
            VectorITransform(in1: &v47->x, in2: v49, out: &v48->origin.x);
            ++v46;
            ++v47;
          }
          while ( v46 < lightingState.numlights );
          v19 = (UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *)pModelInst;
        }
      }
      if ( v19 != nullptr && drawInfo->m_bStaticLighting && bHasDecals_3 )
      {
        LightcacheGetDynamic(
          a1: v41,
          origin: &vLightingOrigin,
          lightingState: &lightingDecalState,
          stats: (LightcacheGetDynamic_Stats *)&v136 + 1,
          pRenderable: state->m_pRenderable,
          flags: 15,
          bDebugModel: false);
        drawInfo->m_LightingState.m_vecAmbientCube[0] = lightingDecalState.r_boxcolor[0];
        drawInfo->m_LightingState.m_vecAmbientCube[1] = lightingDecalState.r_boxcolor[1];
        drawInfo->m_LightingState.m_vecAmbientCube[2] = lightingDecalState.r_boxcolor[2];
        drawInfo->m_LightingState.m_vecAmbientCube[3] = lightingDecalState.r_boxcolor[3];
        drawInfo->m_LightingState.m_vecAmbientCube[4] = lightingDecalState.r_boxcolor[4];
        drawInfo->m_LightingState.m_vecAmbientCube[5] = lightingDecalState.r_boxcolor[5];
        if ( pInfo->pLightingOffset != nullptr && pInfo->pLightingOrigin == nullptr )
        {
          v50 = 0;
          if ( lightingDecalState.numlights > 0 )
          {
            v51 = pSaveLightPos;
            do
            {
              v52 = lightingDecalState.locallight[v50];
              v53 = pInfo->pLightingOffset;
              v51->x = v52->origin.x;
              v51->y = v52->origin.y;
              v51->z = v52->origin.z;
              VectorITransform(in1: &v51->x, in2: v53, out: &v52->origin.x);
              ++v50;
              ++v51;
            }
            while ( v50 < lightingDecalState.numlights );
          }
        }
      }
    }
    if ( *bStaticLighting || pLightcache != nullptr )
      p_lightingState = &lightingState;
    else
      p_lightingState = CModelRender::TimeAverageLightingState(
                          this: v139,
                          handle: pInfo->instance,
                          pLightingState: &lightingState,
                          nEntIndex: pInfo->entity_index,
                          pLightingOrigin: pDebugLightingOrigin);
    m_pObject = pRenderContext.m_pObject;
    if ( bNeedsEnvCubemap && pEnvCubemapTexture != nullptr )
      pRenderContext.m_pObject->BindLocalCubemap(this: pRenderContext.m_pObject, a2: pEnvCubemapTexture);
    if ( g_pMaterialSystemConfig->nFullbright == 1 )
    {
      if ( (_S4_0 & 1) == 0 )
      {
        _S4_0 |= 1u;
        white[0].x = 1.0;
        dword_105F5744 = 1065353216;
        dword_105F5748 = 1065353216;
        dword_105F574C = 1065353216;
        dword_105F5750 = 1065353216;
        dword_105F5754 = 1065353216;
        dword_105F5758 = 1065353216;
        dword_105F575C = 1065353216;
        dword_105F5760 = 1065353216;
        dword_105F5764 = 1065353216;
        dword_105F5768 = 1065353216;
        dword_105F576C = 1065353216;
        dword_105F5770 = 1065353216;
        dword_105F5774 = 1065353216;
        dword_105F5778 = 1065353216;
        dword_105F577C = 1065353216;
        dword_105F5780 = 1065353216;
        dword_105F5784 = 1065353216;
      }
      g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: white);
      m_pObject->DisableAllLocalLights(this: m_pObject);
    }
    else if ( bVertexLit )
    {
      if ( (drawFlags & 0x100) != 0 )
      {
        maxCubeLuminancea = r_itemblinkmax.m_pParent->m_Value.m_fValue;
        d2f = r_itemblinkrate.m_pParent->m_Value.m_fValue;
        xa = _Plat_FloatTime(a1: r_itemblinkmax.m_pParent) * d2f;
        d2 = (FastCos(x: xa) + 1.0) * maxCubeLuminancea;
        if ( (_S4_0 & 2) == 0 )
          _S4_0 |= 2u;
        v56 = 1.0;
        v57 = p_lightingState->r_boxcolor[0].x + d2;
        if ( v57 > 1.0 )
          v57 = 1.0;
        temp[0].x = v57;
        v58 = p_lightingState->r_boxcolor[0].y + d2;
        if ( v58 > 1.0 )
          v58 = 1.0;
        dword_105F56FC = LODWORD(v58);
        v59 = p_lightingState->r_boxcolor[0].z + d2;
        if ( v59 > 1.0 )
          v59 = 1.0;
        dword_105F5700 = LODWORD(v59);
        v60 = p_lightingState->r_boxcolor[1].x + d2;
        if ( v60 > 1.0 )
          v60 = 1.0;
        dword_105F5704 = LODWORD(v60);
        v61 = p_lightingState->r_boxcolor[1].y + d2;
        if ( v61 > 1.0 )
          v61 = 1.0;
        dword_105F5708 = LODWORD(v61);
        v62 = p_lightingState->r_boxcolor[1].z + d2;
        if ( v62 > 1.0 )
          v62 = 1.0;
        dword_105F570C = LODWORD(v62);
        v63 = p_lightingState->r_boxcolor[2].x + d2;
        if ( v63 > 1.0 )
          v63 = 1.0;
        dword_105F5710 = LODWORD(v63);
        v64 = p_lightingState->r_boxcolor[2].y + d2;
        if ( v64 > 1.0 )
          v64 = 1.0;
        dword_105F5714 = LODWORD(v64);
        v65 = p_lightingState->r_boxcolor[2].z + d2;
        if ( v65 > 1.0 )
          v65 = 1.0;
        dword_105F5718 = LODWORD(v65);
        v66 = p_lightingState->r_boxcolor[3].x + d2;
        if ( v66 > 1.0 )
          v66 = 1.0;
        dword_105F571C = LODWORD(v66);
        v67 = p_lightingState->r_boxcolor[3].y + d2;
        if ( v67 > 1.0 )
          v67 = 1.0;
        dword_105F5720 = LODWORD(v67);
        v68 = p_lightingState->r_boxcolor[3].z + d2;
        if ( v68 > 1.0 )
          v68 = 1.0;
        dword_105F5724 = LODWORD(v68);
        v69 = p_lightingState->r_boxcolor[4].x + d2;
        if ( v69 > 1.0 )
          v69 = 1.0;
        dword_105F5728 = LODWORD(v69);
        v70 = p_lightingState->r_boxcolor[4].y + d2;
        if ( v70 > 1.0 )
          v70 = 1.0;
        dword_105F572C = LODWORD(v70);
        v71 = p_lightingState->r_boxcolor[4].z + d2;
        if ( v71 > 1.0 )
          v71 = 1.0;
        dword_105F5730 = LODWORD(v71);
        v72 = p_lightingState->r_boxcolor[5].x + d2;
        if ( v72 > 1.0 )
          v72 = 1.0;
        dword_105F5734 = LODWORD(v72);
        v73 = p_lightingState->r_boxcolor[5].y + d2;
        if ( v73 > 1.0 )
          v73 = 1.0;
        dword_105F5738 = LODWORD(v73);
        if ( (float)(p_lightingState->r_boxcolor[5].z + d2) <= 1.0 )
          v56 = p_lightingState->r_boxcolor[5].z + d2;
        dword_105F573C = LODWORD(v56);
        g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: temp);
      }
      else
      {
        numlights = p_lightingState->numlights;
        if ( numlights > 0
          && (pInfo->pModel->flags & 0x800) != 0
          && r_ambientboost.m_pParent != nullptr
          && r_ambientboost.m_pParent->m_Value.m_nValue != 0 )
        {
          y = p_lightingState->r_boxcolor[0].y;
          v76 = p_lightingState->r_boxcolor[0].x;
          v77 = p_lightingState->r_boxcolor[0].z;
          v78 = (float)((float)(y * 0.58999997) + (float)(p_lightingState->r_boxcolor[0].x * 0.30000001))
              + (float)(v77 * 0.11);
          v79 = v78;
          v80 = v78;
          if ( v78 >= 3.402823466385289e38 )
            v80 = 3.402823466385289e38;
          if ( v79 <= 0.0 )
            v79 = 0.0;
          maxCubeLuminance = v79;
          v81 = p_lightingState->r_boxcolor[1].z * 0.11
              + p_lightingState->r_boxcolor[1].x * 0.30000001
              + p_lightingState->r_boxcolor[1].y * 0.58999997;
          d2a = v81;
          v82 = v81;
          if ( v80 <= v81 )
            v82 = v80;
          if ( maxCubeLuminance >= v81 )
            v81 = maxCubeLuminance;
          v83 = d2a + v78;
          v84 = p_lightingState->r_boxcolor[2].y * 0.58999997
              + p_lightingState->r_boxcolor[2].x * 0.30000001
              + p_lightingState->r_boxcolor[2].z * 0.11;
          d2b = v84;
          v85 = v84;
          v86 = v82;
          v87 = v85;
          v136 = v86;
          if ( v81 >= v85 )
            v87 = v81;
          v88 = d2b + v83;
          v89 = p_lightingState->r_boxcolor[3].y * 0.58999997
              + p_lightingState->r_boxcolor[3].x * 0.30000001
              + p_lightingState->r_boxcolor[3].z * 0.11;
          d2c = v89;
          v90 = v89;
          v91 = v87;
          v92 = v90;
          if ( v91 >= v90 )
            v92 = v91;
          v93 = d2c + v88;
          v94 = p_lightingState->r_boxcolor[4].y * 0.58999997
              + p_lightingState->r_boxcolor[4].x * 0.30000001
              + p_lightingState->r_boxcolor[4].z * 0.11;
          d2d = v94;
          v95 = v94;
          v96 = v92;
          v97 = v95;
          if ( v96 >= v95 )
            v97 = v96;
          v98 = d2d + v93;
          v99 = 0.30000001 * p_lightingState->r_boxcolor[5].x
              + 0.58999997 * p_lightingState->r_boxcolor[5].y
              + 0.11 * p_lightingState->r_boxcolor[5].z;
          d2e = v99;
          v100 = v99;
          v101 = v97;
          v102 = v100;
          if ( v101 >= v100 )
            v102 = v101;
          v103 = 0.0;
          avgCubeLuminance = (float)(d2e + v98) * 0.16666667;
          locallight = (float **)p_lightingState->locallight;
          for ( i = numlights; i != 0; --i )
          {
            v106 = *locallight;
            d2g = (float)((float)((float)((*locallight)[1] - vLightingOrigin.y)
                                * (float)((*locallight)[1] - vLightingOrigin.y))
                        + (float)((float)(**locallight - vLightingOrigin.x) * (float)(**locallight - vLightingOrigin.x)))
                + (float)((float)((*locallight)[2] - vLightingOrigin.z) * (float)((*locallight)[2] - vLightingOrigin.z));
            v107 = 1.0;
            v108 = d2g * (*locallight)[21] + sqrt(d2g) * v106[20] + v106[19];
            if ( v108 > 0.0000099999997 )
            {
              denom = v108;
              v107 = 1.0 / denom;
            }
            ++locallight;
            v103 = (float)((float)((float)((float)(v106[4] * v107) * 0.58999997)
                                 + (float)((float)(v106[3] * v107) * 0.30000001))
                         + (float)((float)(v106[5] * v107) * 0.11))
                 + v103;
          }
          if ( r_ambientmin.m_pParent->m_Value.m_fValue <= avgCubeLuminance
            || (float)(r_ambientfraction.m_pParent->m_Value.m_fValue * v103) <= avgCubeLuminance )
          {
            g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)p_lightingState);
          }
          else
          {
            maxCubeLuminanceb = v102;
            m_fValue = (float)(r_ambientfraction.m_pParent->m_Value.m_fValue * v103) / maxCubeLuminanceb;
            if ( r_ambientfactor.m_pParent->m_Value.m_fValue <= m_fValue )
              m_fValue = r_ambientfactor.m_pParent->m_Value.m_fValue;
            v110 = p_lightingState->r_boxcolor[1].y * m_fValue;
            v111 = p_lightingState->r_boxcolor[1].z * m_fValue;
            vFinalAmbientCube[1].x = p_lightingState->r_boxcolor[1].x * m_fValue;
            v112 = p_lightingState->r_boxcolor[2].x;
            vFinalAmbientCube[1].y = v110;
            v113 = p_lightingState->r_boxcolor[2].y;
            vFinalAmbientCube[1].z = v111;
            v114 = p_lightingState->r_boxcolor[2].z * m_fValue;
            vFinalAmbientCube[2].x = v112 * m_fValue;
            v115 = p_lightingState->r_boxcolor[3].x;
            vFinalAmbientCube[2].y = v113 * m_fValue;
            v116 = p_lightingState->r_boxcolor[3].y;
            vFinalAmbientCube[2].z = v114;
            v117 = p_lightingState->r_boxcolor[3].z * m_fValue;
            vFinalAmbientCube[3].x = v115 * m_fValue;
            v118 = p_lightingState->r_boxcolor[4].x;
            vFinalAmbientCube[3].y = v116 * m_fValue;
            v119 = p_lightingState->r_boxcolor[4].y;
            vFinalAmbientCube[3].z = v117;
            v120 = p_lightingState->r_boxcolor[4].z * m_fValue;
            vFinalAmbientCube[4].x = v118 * m_fValue;
            v121 = p_lightingState->r_boxcolor[5].x;
            vFinalAmbientCube[4].y = v119 * m_fValue;
            v122 = p_lightingState->r_boxcolor[5].y;
            vFinalAmbientCube[4].z = v120;
            v123 = p_lightingState->r_boxcolor[5].z * m_fValue;
            vFinalAmbientCube[0].x = v76 * m_fValue;
            vFinalAmbientCube[0].y = y * m_fValue;
            vFinalAmbientCube[0].z = v77 * m_fValue;
            vFinalAmbientCube[5].x = v121 * m_fValue;
            vFinalAmbientCube[5].y = v122 * m_fValue;
            vFinalAmbientCube[5].z = v123;
            g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: vFinalAmbientCube);
          }
        }
        else if ( state->m_pStudioHdr != nullptr
               && state->m_pStudioHdr->numbones > 1
               && r_modelAmbientMin.m_pParent->m_Value.m_fValue > 0.0 )
        {
          v124 = 0;
          v125 = r_modelAmbientMin.m_pParent->m_Value.m_fValue;
          do
          {
            v126 = *(float *)((char *)&vFinalAmbientCube[0].x
                            + 4 * v124
                            + (char *)p_lightingState
                            - (char *)vFinalAmbientCube);
            if ( v125 <= v126 )
              *(&vFinalAmbientCube[0].x + v124) = v126;
            else
              *(&vFinalAmbientCube[0].x + v124) = v125;
            ++v124;
          }
          while ( v124 < 18 );
          ((void (__stdcall *)(Vector *))g_pStudioRender->SetAmbientLightColors)(a1: vFinalAmbientCube);
        }
        else
        {
          ((void (__stdcall *)(LightingState_t *))g_pStudioRender->SetAmbientLightColors)(a1: p_lightingState);
        }
      }
      R_SetNonAmbientLightingState(
        numLights: p_lightingState->numlights,
        locallight: p_lightingState->locallight,
        pNumLightDescs: &drawInfo->m_LightingState.m_nLocalLightCount,
        pLightDescs: drawInfo->m_LightingState.m_pLocalLightDesc,
        bUpdateStudioRenderLights: true);
      if ( pModelInst != nullptr && drawInfo->m_bStaticLighting && bHasDecals_3 )
        R_SetNonAmbientLightingState(
          numLights: lightingDecalState.numlights,
          locallight: lightingDecalState.locallight,
          pNumLightDescs: &drawInfo->m_LightingState.m_nLocalLightCount,
          pLightDescs: drawInfo->m_LightingState.m_pLocalLightDesc,
          bUpdateStudioRenderLights: false);
      m_pObject = pRenderContext.m_pObject;
    }
    if ( pInfo->pLightingOffset != nullptr && pInfo->pLightingOrigin == nullptr )
    {
      v127 = 0;
      if ( lightingState.numlights > 0 )
      {
        p_z = &pSaveLightPos[0].z;
        do
        {
          v129 = lightingState.locallight[v127];
          v129->origin.x = *(p_z - 2);
          ++v127;
          v130 = *(p_z - 1);
          p_z += 3;
          v129->origin.y = v130;
          v129->origin.z = *(p_z - 3);
        }
        while ( v127 < lightingState.numlights );
      }
    }
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF530
// Name: public: virtual void CModelRender::SetupLightingEx(class Vector const __near &,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::SetupLightingEx(CModelRender *this, const Vector *vecCenter, unsigned __int16 handle)
{
  IMatRenderContext *v4; // esi
  float z; // xmm0_4
  MaterialLightingState_t state; // [esp+8h] [ebp-1BCh] BYREF
  ITexture *pEnvCubemapTexture; // [esp+1C0h] [ebp-4h] BYREF

  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  state.m_vecLightingOrigin.x = vecCenter->x;
  state.m_vecLightingOrigin.y = vecCenter->y;
  z = vecCenter->z;
  pEnvCubemapTexture = nullptr;
  state.m_vecLightingOrigin.z = z;
  state.m_nLocalLightCount = CModelRender::GetLightingConditions(
                               this,
                               vecLightingOrigin: vecCenter,
                               pColors: state.m_vecAmbientCube,
                               nMaxLocalLights: 4,
                               pLocalLights: state.m_pLocalLightDesc,
                               &pEnvCubemapTexture,
                               handle,
                               bAllowFast: 0);
  v4->SetLightingState(this: v4, a2: &state);
  if ( pEnvCubemapTexture != nullptr )
    v4->BindLocalCubemap(this: v4, a2: pEnvCubemapTexture);
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100DF5F0
// Name: public: virtual int CModelRender::DrawModelEx(struct ModelRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::DrawModelEx(CModelRender *this, matrix3x4_t *pInfo)
{
  matrix3x4_t *v2; // edi
  IMatRenderContext *v4; // esi
  QAngle *v6; // [esp-Ch] [ebp-64h]
  const Vector *v7; // [esp-8h] [ebp-60h]
  matrix3x4_t tmpmat; // [esp+Ch] [ebp-4Ch] BYREF
  DrawModelState_t state; // [esp+3Ch] [ebp-1Ch] BYREF

  v2 = pInfo;
  if ( LODWORD(pInfo->m_flMatVal[2][0]) == 0 )
  {
    v7 = (const Vector *)pInfo;
    v6 = (QAngle *)&pInfo->m_flMatVal[0][3];
    LODWORD(pInfo->m_flMatVal[2][0]) = &tmpmat;
    AngleMatrix(angles: v6, position: v7, matrix: &tmpmat);
  }
  v4 = materials->GetRenderContext(this: materials);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->AddRefRenderData(this: v4);
  if ( this->DrawModelSetup(this, a2: v4, a3: (ModelRenderInfo_t *)v2, a4: &state, a5: &pInfo) )
  {
    if ( (LOBYTE(v2->m_flMatVal[2][3]) & 1) != 0 )
      this->DrawModelExecute(this, a2: v4, a3: &state, a4: (const ModelRenderInfo_t *)v2, a5: pInfo);
    v4->ReleaseRenderData(this: v4);
    v4->EndRender(this: v4);
    v4->Release(this: v4);
    return 1;
  }
  else
  {
    v4->ReleaseRenderData(this: v4);
    v4->EndRender(this: v4);
    v4->Release(this: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF6D0
// Name: public: virtual class matrix3x4a_t __near * CModelRender::DrawModelShadowSetup(class IClientRenderable __near *,int,int,struct DrawModelInfo_t __near *,class matrix3x4a_t __near *)
// Source: json
//------------------------------------------------------------------------------
matrix3x4a_t *__userpurge CModelRender::DrawModelShadowSetup@<eax>(
        CModelRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IClientRenderable *pRenderable,
        int body,
        CMatRenderContextPtr skin,
        float pInfo,
        matrix3x4a_t *pCustomBoneToWorld)
{
  int v9; // eax
  int v10; // edi
  studiohdr_t *v12; // eax
  DrawModelInfo_t *v13; // esi
  int v14; // eax
  int m_pObject; // eax
  IMatRenderContext *v16; // edi
  int m_nValue; // eax
  studiohdr_t *m_pStudioHdr; // ecx
  float m_fValue; // xmm0_4
  IMatRenderContext_vtbl *v20; // ebx
  int v21; // eax
  double v22; // st7
  int v23; // eax
  studiohwdata_t *m_pHardwareData; // ecx
  int m_NumLODs; // eax
  studiohwdata_t *v26; // edx
  matrix3x4a_t *m_pRenderData; // ebx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  IClientRenderable_vtbl *v29; // edi
  CClientState *BaseLocalClient; // eax
  float v31; // [esp+28h] [ebp-18h]
  float Time; // [esp+2Ch] [ebp-14h]
  CMatRenderData<matrix3x4a_t> rdBoneToWorld; // [esp+30h] [ebp-10h] BYREF

  if ( (_S6_0 & 1) == 0 )
  {
    _S6_0 |= 1u;
    ConVar::ConVar(this: &r_shadowlod, pName: "r_shadowlod", pDefaultValue: "-1", flags: 0);
    atexit(func: CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlod__);
  }
  if ( (_S6_0 & 2) == 0 )
  {
    _S6_0 |= 2u;
    ConVar::ConVar(this: &r_shadowlodbias, pName: "r_shadowlodbias", pDefaultValue: "2", flags: 0);
    atexit(func: CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlodbias__);
  }
  v9 = ((int (__thiscall *)(IClientRenderable *, int, int))pRenderable->GetModel)(a1: pRenderable, a2: a3, a3: a2);
  v10 = v9;
  if ( v9 == 0 || *(_DWORD *)(v9 + 272) != 3 )
    return nullptr;
  v12 = (studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, int))g_pMDLCache->GetStudioHdr)(
                         a1: g_pMDLCache,
                         a2: *(unsigned __int16 *)(v9 + 312),
                         a3: a4);
  v13 = (DrawModelInfo_t *)LODWORD(pInfo);
  *(_DWORD *)LODWORD(pInfo) = v12;
  v13->m_pColorMeshes = nullptr;
  if ( v12->numbodyparts == 0 )
    return nullptr;
  v14 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: *(unsigned __int16 *)(v10 + 312));
  v13->m_pHardwareData = (studiohwdata_t *)v14;
  if ( v14 == 0 )
    return nullptr;
  m_pObject = (int)skin.m_pObject;
  v13->m_Body = body;
  v13->m_Decals = nullptr;
  v13->m_Skin = m_pObject;
  v13->m_pClientEntity = (void *)pRenderable;
  v13->m_HitboxSet = 0;
  v16 = materials->GetRenderContext(this: materials);
  skin.m_pObject = v16;
  if ( v16 != nullptr )
    v16->BeginRender(this: v16);
  if ( r_shadowlod.m_pParent != nullptr )
    m_nValue = r_shadowlod.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_pStudioHdr = v13->m_pStudioHdr;
  v13->m_Lod = m_nValue;
  if ( (m_pStudioHdr->flags & 0x40) != 0 )
  {
    v13->m_Lod = v13->m_pHardwareData->m_NumLODs - 1;
  }
  else if ( m_nValue == -2 )
  {
    v13->m_Lod = v13->m_pHardwareData->m_NumLODs - 1;
  }
  else if ( m_nValue < 0 )
  {
    m_fValue = r_shadowlodbias.m_pParent->m_Value.m_fValue;
    pInfo = m_fValue <= 0.0 ? 1.0 : 1.0 / m_fValue;
    v20 = v16->__vftable;
    v21 = ((int (__thiscall *)(IClientRenderable *, _DWORD))pRenderable->GetRenderOrigin)(a1: pRenderable, a2: 0.5);
    v22 = ((double (__thiscall *)(IMatRenderContext *, int))v20->ComputePixelWidthOfSphere)(a1: v16, a2: v21);
    v31 = v22 * pInfo;
    v23 = ((int (__stdcall *)(studiohwdata_t *, _DWORD, _DWORD))g_pStudioRender->ComputeModelLod)(
            a1: v13->m_pHardwareData,
            a2: LODWORD(v31),
            a3: 0);
    m_pHardwareData = v13->m_pHardwareData;
    v13->m_Lod = v23;
    m_NumLODs = m_pHardwareData->m_NumLODs;
    v13->m_Lod = m_NumLODs - 2;
    if ( m_NumLODs - 2 < 0 )
      v13->m_Lod = 0;
  }
  v26 = v13->m_pHardwareData;
  if ( v13->m_Lod < v26->m_RootLOD )
    v13->m_Lod = v26->m_RootLOD;
  m_pRenderData = pCustomBoneToWorld;
  rdBoneToWorld.m_pRenderContext = v16;
  memset(&rdBoneToWorld.m_pRenderData, 0, 9);
  if ( pCustomBoneToWorld == nullptr )
  {
    LockRenderData = v16->LockRenderData;
    rdBoneToWorld.m_nCount = v13->m_pStudioHdr->numbones;
    rdBoneToWorld.m_pRenderData = (matrix3x4a_t *)LockRenderData(this: v16, a2: 48 * rdBoneToWorld.m_nCount);
    rdBoneToWorld.m_bNeedsUnlock = true;
    m_pRenderData = rdBoneToWorld.m_pRenderData;
  }
  v29 = pRenderable->__vftable;
  BaseLocalClient = GetBaseLocalClient();
  Time = CClientState::GetTime(this: BaseLocalClient);
  if ( ((unsigned __int8 (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, int, _DWORD))v29->SetupBones)(
         a1: pRenderable,
         a2: m_pRenderData,
         a3: v13->m_pStudioHdr->numbones,
         a4: 1024 << v13->m_Lod,
         a5: LODWORD(Time)) == 0 )
  {
    CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &rdBoneToWorld);
    CMatRenderContextPtr::~CMatRenderContextPtr(this: &skin);
    return nullptr;
  }
  CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &rdBoneToWorld);
  CMatRenderContextPtr::~CMatRenderContextPtr(this: &skin);
  return m_pRenderData;
}

//------------------------------------------------------------------------------
// Address: 0x100DF980
// Name: public: virtual void CModelRender::AddDecal(unsigned short,struct Ray_t const __near &,class Vector const __near &,int,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelRender::AddDecal(
        CModelRender *this@<ecx>,
        int a2@<edi>,
        float handle,
        const Ray_t *ray,
        const Vector *decalUp,
        int decalIndex,
        int body,
        int noPokeThru,
        IStudioRender_vtbl *maxLODToDecal)
{
  unsigned __int16 v9; // bx
  int v11; // edi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v12; // edi
  studiohwdata_t *v13; // eax
  studiohdr_t *v14; // eax
  int numbones; // ebx
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v17; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  IClientRenderable_vtbl *v19; // eax
  CClientState *BaseLocalClient; // eax
  studiohdr_t *(__thiscall *GetStudioHdr)(IMDLCache *, unsigned __int16); // edx
  int v22; // eax
  int studio; // [esp+18h] [ebp-54h]
  float Time; // [esp+38h] [ebp-34h]
  IStudioRender_vtbl *v25; // [esp+38h] [ebp-34h]
  CMatRenderData<matrix3x4a_t> rdBoneToWorld; // [esp+48h] [ebp-24h] BYREF
  IClientRenderable_vtbl *v28; // [esp+58h] [ebp-14h]
  IClientRenderable *m_pRenderable; // [esp+5Ch] [ebp-10h]
  int nBoneCount; // [esp+60h] [ebp-Ch]
  IMaterial *pDecalMaterial; // [esp+64h] [ebp-8h] BYREF
  int radius; // [esp+68h] [ebp-4h]

  v9 = LOWORD(handle);
  if ( LOWORD(handle) != 0xFFFF )
  {
    v11 = decalIndex;
    R_DecalGetMaterialAndSize(decalIndex, &pDecalMaterial, w: &handle, h: (float *)&decalIndex);
    if ( pDecalMaterial != nullptr )
    {
      handle = handle * 0.5;
      *(float *)&decalIndex = *(float *)&decalIndex * 0.5;
      if ( pDecalMaterial->FindVarFast(this: pDecalMaterial, a2: "$decalFadeDuration", a3: &s_DecalFadeVarCache) == nullptr )
      {
        if ( handle <= *(float *)&decalIndex )
          radius = decalIndex;
        else
          radius = LODWORD(handle);
        v12 = &this->m_ModelInstances.m_Memory.m_pMemory[v9];
        if ( !CModelRender::IsModelInstanceValid(this, handle: v9) )
        {
          g_pStudioRender->DestroyDecalList(this: g_pStudioRender, a2: v12->m_Element.m_DecalHandle);
          v12->m_Element.m_DecalHandle = nullptr;
        }
        if ( v12->m_Element.m_DecalHandle == nullptr )
        {
          v13 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: v12->m_Element.m_pModel->studio);
          v12->m_Element.m_DecalHandle = g_pStudioRender->CreateDecalList(this: g_pStudioRender, a2: v13);
        }
        v14 = modelinfo->GetStudiomodel(this: modelinfo, a2: v12->m_Element.m_pModel);
        if ( v14->numbodyparts != 0 )
        {
          numbones = v14->numbones;
          GetRenderContext = g_pMaterialSystem->GetRenderContext;
          nBoneCount = numbones;
          v17 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))GetRenderContext)(
                                       a1: g_pMaterialSystem,
                                       a2);
          if ( v17 != nullptr )
            v17->BeginRender(this: v17);
          LockRenderData = v17->LockRenderData;
          rdBoneToWorld.m_pRenderContext = v17;
          rdBoneToWorld.m_nCount = numbones;
          rdBoneToWorld.m_pRenderData = (matrix3x4a_t *)LockRenderData(this: v17, a2: 48 * numbones);
          m_pRenderable = v12->m_Element.m_pRenderable;
          v19 = m_pRenderable->__vftable;
          rdBoneToWorld.m_bNeedsUnlock = true;
          v28 = v19;
          BaseLocalClient = GetBaseLocalClient();
          Time = CClientState::GetTime(this: BaseLocalClient);
          ((void (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, int, _DWORD))v28->SetupBones)(
            a1: m_pRenderable,
            a2: rdBoneToWorld.m_pRenderData,
            a3: nBoneCount,
            a4: 524032,
            a5: LODWORD(Time));
          v25 = maxLODToDecal;
          GetStudioHdr = g_pMDLCache->GetStudioHdr;
          studio = v12->m_Element.m_pModel->studio;
          maxLODToDecal = g_pStudioRender->__vftable;
          v22 = ((int (__thiscall *)(IMDLCache *, int, matrix3x4a_t *, const Ray_t *, const Vector *, IMaterial *, int, int, int, IStudioRender_vtbl *))GetStudioHdr)(
                  a1: g_pMDLCache,
                  a2: studio,
                  a3: rdBoneToWorld.m_pRenderData,
                  a4: ray,
                  a5: decalUp,
                  a6: pDecalMaterial,
                  a7: radius,
                  a8: body,
                  a9: noPokeThru,
                  a10: v25);
          ((void (__thiscall *)(IStudioRender *, StudioDecalHandle_t__ *, int))maxLODToDecal->AddDecal)(
            a1: g_pStudioRender,
            a2: v12->m_Element.m_DecalHandle,
            a3: v22);
          CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &rdBoneToWorld);
          v17->EndRender(this: v17);
          v17->Release(this: v17);
        }
      }
    }
    else
    {
      DevWarning(a1: "Bad decal index %d\n", v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFBB0
// Name: public: virtual void CModelRender::RemoveAllDecalsFromAllModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::RemoveAllDecalsFromAllModels(CModelRender *this)
{
  int i; // esi

  for ( i = this->m_ModelInstances.m_Head;
        (_WORD)i != 0xFFFF;
        i = this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)i].m_Next )
  {
    this->RemoveAllDecals(this, a2: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFDE0
// Name: public: virtual void CPooledVBAllocator_ColorMesh::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPooledVBAllocator_ColorMesh::Clear(CPooledVBAllocator_ColorMesh *this@<ecx>, int a2@<esi>)
{
  int v3; // esi

  if ( this->m_pMesh != nullptr )
  {
    if ( this->m_numAllocations > 0 )
      _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh::Clear should not be called until all allocations released!\n");
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, IMesh *))(*(_DWORD *)v3 + 224))(a1: v3, a2: this->m_pMesh);
    this->m_pMesh = nullptr;
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
  this->m_pVertexBufferBase = nullptr;
  this->m_totalVerts = 0;
  this->m_vertexSize = 0;
  this->m_numAllocations = 0;
  this->m_numVertsAllocated = 0;
  this->m_bStartedDeallocation = false;
  this->m_nextFreeOffset = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100DFED0
// Name: public: virtual bool CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>::HandleCacheNotification(struct DataCacheNotification_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::HandleCacheNotification(
        CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *> *this,
        const DataCacheNotification_t *notification)
{
  if ( (unsigned int)(notification->type - 1) > 2 )
    return 0;
  CColorMeshData::DestroyResource(this: (CColorMeshData *)notification->clientId);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DFFC0
// Name: public: virtual void CMemberFunctor2<class CModelRender __near *,void (CModelRender::*)(int,struct memhandle_t__ __near * __near *),int,struct memhandle_t__ __near * __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CModelRender *,void (__thiscall CModelRender::*)(int,memhandle_t__ * *),int,memhandle_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CModelRender *,void (__thiscall CModelRender::*)(int,memhandle_t__ * *),int,memhandle_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, int, memhandle_t__ **))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + HIDWORD(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x100E02D0
// Name: void R_RemoveAllDecalsFromAllModels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_RemoveAllDecalsFromAllModels()
{
  int m_Head; // esi

  m_Head = s_ModelRender.m_ModelInstances.m_Head;
  if ( s_ModelRender.m_ModelInstances.m_Head != 0xFFFF )
  {
    do
    {
      s_ModelRender.RemoveAllDecals(this: &s_ModelRender, a2: m_Head);
      m_Head = s_ModelRender.m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
    }
    while ( (_WORD)m_Head != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0320
// Name: void DrawModelDebugOverlay(struct DrawModelInfo_t const __near &,struct DrawModelResults_t const __near &,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DrawModelDebugOverlay(
        int a1@<ebp>,
        const DrawModelInfo_t *info,
        const DrawModelResults_t *results,
        const Vector *origin,
        float r,
        float g,
        float b)
{
  char *m_pszString; // eax
  const DrawModelInfo_t *v8; // esi
  studiohdr_t *v9; // edx
  int v10; // eax
  int v11; // ecx
  char *v12; // eax
  int v13; // ecx
  char *v14; // eax
  char *v15; // edi
  int v16; // eax
  int v17; // ecx
  char *v18; // eax
  int v19; // ecx
  const char *v20; // eax
  float m_fValue; // xmm3_4
  const Vector *v22; // edi
  __int128 v23; // xmm0
  float v24; // xmm0_4
  __int128 v25; // xmm0
  studiohdr_t *m_pStudioHdr; // ecx
  int studiohdr2index; // eax
  int v28; // edx
  char *v29; // eax
  int v30; // edx
  char *name; // eax
  char *v32; // eax
  const char *v33; // eax
  bool v34; // cc
  __int64 v35; // rdi
  int v36; // eax
  const char *v37; // edx
  const char *v38; // eax
  unsigned int m_Int64; // eax
  int v40; // [esp+10h] [ebp-444h]
  const char *v41; // [esp+14h] [ebp-440h]
  char v42[12]; // [esp+28h] [ebp-42Ch] BYREF
  __int128 buf_1012; // [esp+428h] [ebp-2Ch] OVERLAPPED
  int i; // [esp+440h] [ebp-14h]
  float v45; // [esp+444h] [ebp-10h]
  int v46; // [esp+448h] [ebp-Ch]
  void *v47; // [esp+44Ch] [ebp-8h]
  void *retaddr; // [esp+454h] [ebp+0h]

  v46 = a1;
  v47 = retaddr;
  v45 = 1.0;
  if ( (r_drawmodelstatsoverlayfilter.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = r_drawmodelstatsoverlayfilter.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  if ( _V_stricmp(s1: m_pszString, s2: "-1") == 0 )
  {
    m_fValue = r_drawmodelstatsoverlaydistance.m_pParent->m_Value.m_fValue;
    if ( m_fValue == 1.0 )
    {
      v22 = origin;
      v23 = 0;
      *(float *)&v23 = fsqrt(
                         (float)((float)((float)(g_CurrentViewOrigin.y - v22->y)
                                       * (float)(g_CurrentViewOrigin.y - v22->y))
                               + (float)((float)(g_CurrentViewOrigin.z - v22->z)
                                       * (float)(g_CurrentViewOrigin.z - v22->z)))
                       + (float)((float)(g_CurrentViewOrigin.x - v22->x) * (float)(g_CurrentViewOrigin.x - v22->x)));
      buf_1012 = v23;
      v24 = *(float *)&v23 / m_fValue;
      if ( v24 >= 0.0 )
      {
        if ( v24 > 1.0 )
          v24 = 1.0;
        v8 = info;
        v45 = 1.0 - v24;
      }
      else
      {
        v8 = info;
        v45 = 1.0 - 0.0;
      }
LABEL_37:
      m_pStudioHdr = v8->m_pStudioHdr;
      if ( v8->m_pStudioHdr != nullptr )
      {
        studiohdr2index = m_pStudioHdr->studiohdr2index;
        if ( studiohdr2index != 0
          && (v28 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8],
              v29 = (char *)m_pStudioHdr + studiohdr2index,
              v28 != 0)
          && &v29[v28] != nullptr )
        {
          v30 = *((_DWORD *)v29 + 5);
          if ( v30 == 0 )
            goto LABEL_61;
          name = &v29[v30];
        }
        else
        {
          name = m_pStudioHdr->name;
        }
        if ( name != nullptr && v8->m_pHardwareData != nullptr )
        {
          v32 = studiohdr_t::pszName(this: m_pStudioHdr);
          CDebugOverlay::AddTextOverlay(textPos: v22, line_offset: 0, duration: 0.0, r, g, b, alpha: v45, text: v32);
          V_snprintf(
            pDest: v42,
            maxLen: 1024,
            pFormat: "lod: %d/%d\n",
            results->m_nLODUsed + 1,
            v8->m_pHardwareData->m_NumLODs);
          CDebugOverlay::AddTextOverlay(textPos: v22, line_offset: 1, duration: 0.0, r, g, b, alpha: v45, text: v42);
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "tris: %d\n", results->m_ActualTriCount);
          CDebugOverlay::AddTextOverlay(textPos: v22, line_offset: 2, duration: 0.0, r, g, b, alpha: v45, text: v42);
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "hardware bones: %d\n", results->m_NumHardwareBones);
          CDebugOverlay::AddTextOverlay(textPos: v22, line_offset: 3, duration: 0.0, r, g, b, alpha: v45, text: v42);
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "num batches: %d\n", results->m_NumBatches);
          CDebugOverlay::AddTextOverlay(textPos: v22, line_offset: 4, duration: 0.0, r, g, b, alpha: v45, text: v42);
          v33 = "true";
          if ( (info->m_pStudioHdr->flags & 0x40) == 0 )
            v33 = "false";
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "has shadow lod: %s\n", v33);
          CDebugOverlay::AddTextOverlay(textPos: v22, line_offset: 5, duration: 0.0, r, g, b, alpha: v45, text: v42);
          V_snprintf(pDest: v42, maxLen: 1024, pFormat: "num materials: %d\n", results->m_NumMaterials);
          CDebugOverlay::AddTextOverlay(textPos: v22, line_offset: 6, duration: 0.0, r, g, b, alpha: v45, text: v42);
          v34 = results->m_Materials.m_Size <= 0;
          LODWORD(v35) = 7;
          HIDWORD(buf_1012) = 0;
          if ( !v34 )
          {
            i = (int)&results->m_Materials;
            do
            {
              if ( *(_DWORD *)i != 0 )
              {
                v36 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)i + 140))(a1: *(_DWORD *)i);
                v37 = "passes";
                if ( v36 <= 1 )
                  v37 = "pass";
                v38 = (const char *)(***(int (__thiscall ****)(_DWORD, int, const char *))i)(
                                      a1: *(_DWORD *)i,
                                      a2: v36,
                                      a3: v37);
                V_snprintf(pDest: v42, maxLen: 1024, pFormat: "\t%s (%d %s)\n", v38, v40, v41);
                CDebugOverlay::AddTextOverlay(
                  textPos: origin,
                  line_offset: v35,
                  duration: 0.0,
                  r,
                  g,
                  b,
                  alpha: v45,
                  text: v42);
                LODWORD(v35) = v35 + 1;
              }
              i += 4;
              ++HIDWORD(buf_1012);
            }
            while ( SHIDWORD(buf_1012) < results->m_Materials.m_Size );
          }
          if ( results->m_Materials.m_Size > results->m_NumMaterials )
          {
            CDebugOverlay::AddTextOverlay(
              textPos: origin,
              line_offset: v35,
              duration: 0.0,
              r,
              g,
              b,
              alpha: v45,
              text: "(Remaining materials not shown)\n");
            LODWORD(v35) = v35 + 1;
          }
          if ( r_drawmodelstatsoverlay.m_pParent != nullptr && r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue == 2 )
          {
            m_Int64 = results->m_RenderTime.m_Duration.m_Int64;
            HIDWORD(v35) = HIDWORD(results->m_RenderTime.m_Duration.m_Int64);
            *((_QWORD *)&buf_1012 + 1) = v35 & 0x8000000000000000uLL;
            V_snprintf(
              pDest: v42,
              maxLen: 1024,
              pFormat: "Render Time: %0.1f ms\n",
              (double)((double)__PAIR64__(HIDWORD(v35), m_Int64) * _g_ClockSpeedMillisecondsMultiplier));
            CDebugOverlay::AddTextOverlay(
              textPos: origin,
              line_offset: v35,
              duration: 0.0,
              r,
              g,
              b,
              alpha: v45,
              text: v42);
          }
          return;
        }
      }
LABEL_61:
      CDebugOverlay::AddTextOverlay(
        textPos: v22,
        line_offset: 0,
        duration: 0.0,
        r: 1.0,
        g: 0.80000001,
        b: 0.80000001,
        alpha: 1.0,
        text: "This model has problems! See a programmer!");
      return;
    }
    v25 = 0;
    *(float *)&v25 = fsqrt(
                       (float)((float)((float)(g_CurrentViewOrigin.y - origin->y)
                                     * (float)(g_CurrentViewOrigin.y - origin->y))
                             + (float)((float)(g_CurrentViewOrigin.z - origin->z)
                                     * (float)(g_CurrentViewOrigin.z - origin->z)))
                     + (float)((float)(g_CurrentViewOrigin.x - origin->x) * (float)(g_CurrentViewOrigin.x - origin->x)));
    buf_1012 = v25;
    if ( *(float *)&v25 < 36.0 || *(float *)&buf_1012 > m_fValue )
      return;
    v8 = info;
    goto LABEL_36;
  }
  v8 = info;
  v9 = info->m_pStudioHdr;
  if ( info->m_pStudioHdr == nullptr )
  {
    v22 = origin;
    goto LABEL_61;
  }
  v10 = v9->studiohdr2index;
  if ( v10 == 0 || (v11 = *(_DWORD *)&v9->name[v10 + 8], v12 = (char *)v9 + v10, v11 == 0) || &v12[v11] == nullptr )
  {
    v14 = v9->name;
    goto LABEL_13;
  }
  v13 = *((_DWORD *)v12 + 5);
  if ( v13 == 0 )
  {
LABEL_36:
    v22 = origin;
    goto LABEL_37;
  }
  v14 = &v12[v13];
LABEL_13:
  if ( v14 == nullptr )
    goto LABEL_36;
  if ( (r_drawmodelstatsoverlayfilter.m_nFlags & 0x1000) != 0 )
  {
    v15 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v15 = r_drawmodelstatsoverlayfilter.m_pParent->m_Value.m_pszString;
    if ( v15 == nullptr )
      v15 = (char *)defaultValue;
  }
  v16 = v9->studiohdr2index;
  if ( v16 != 0 && (v17 = *(_DWORD *)&v9->name[v16 + 8], v18 = (char *)v9 + v16, v17 != 0) && &v18[v17] != nullptr )
  {
    v19 = *((_DWORD *)v18 + 5);
    v20 = v19 != 0 ? &v18[v19] : nullptr;
  }
  else
  {
    v20 = v9->name;
  }
  if ( V_stristr(pStr: v20, pSearch: v15) != nullptr )
    goto LABEL_36;
}

//------------------------------------------------------------------------------
// Address: 0x100E0C60
// Name: public: virtual void CModelRender::CleanupStaticLightingState(int,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::CleanupStaticLightingState(
        CModelRender *this,
        int nCount,
        memhandle_t__ **pColorMeshHandles)
{
  IMatRenderContext *v4; // esi
  ICallQueue *v5; // edi
  int i; // edi
  CMatRenderData<memhandle_t__ *> renderData; // [esp+Ch] [ebp-10h] BYREF

  v4 = materials->GetRenderContext(this: materials);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v5 = v4->GetCallQueue(this: v4);
  if ( v5 != nullptr )
  {
    renderData.m_pRenderContext = v4;
    memset(&renderData.m_pRenderData, 0, 9);
    CMatRenderData<memhandle_t__ *>::Lock(this: &renderData, nCount, pSrcData: pColorMeshHandles);
    pColorMeshHandles = renderData.m_pRenderData;
    ICallQueue::QueueCall<CModelRender *,CModelRender,void,int,memhandle_t__ * *,int,memhandle_t__ * *>(
      this: v5,
      pObject: (CFunctor_vtbl *)this,
      pfnProxied: (void (__thiscall *__ptr64)(CModelRender *, int, memhandle_t__ **))(unsigned int)CModelRender::UnlockCacheCacheHandleArray,
      arg1: (CFunctor_vtbl **)&nCount,
      arg2: &pColorMeshHandles);
    CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: (CMatRenderData<matrix3x4a_t> *)&renderData);
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
  else
  {
    for ( i = 0; i < nCount; ++i )
    {
      if ( pColorMeshHandles[i] != nullptr )
        this->m_pCache->Unlock(this: this->m_pCache, a2: pColorMeshHandles[i]);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0D40
// Name: private: void CModelRender::ProtectColorDataIfQueued(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ProtectColorDataIfQueued(CModelRender *this, memhandle_t__ *hColorMesh)
{
  IMatRenderContext *v3; // esi
  ICallQueue *v4; // edi

  if ( hColorMesh != nullptr )
  {
    v3 = materials->GetRenderContext(this: materials);
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4 = v3->GetCallQueue(this: v3);
    if ( v4 != nullptr && this->m_pCache->Lock(this: this->m_pCache, a2: hColorMesh) != nullptr )
      ICallQueue::QueueCall<CModelRender *,CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,int,memhandle_t__ *,memhandle_t__ *>(
        this: v4,
        pObject: this,
        pfnProxied: (int (__thiscall *)(CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *> *, memhandle_t__ *))CLoaderMemAlloc::CrtSetReportMode,
        arg1: (CFunctor_vtbl **)&hColorMesh);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0DC0
// Name: public: virtual void CModelRender::DestroyInstance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::DestroyInstance(CModelRender *this, int handle)
{
  unsigned __int16 v2; // bx
  int v4; // esi
  memhandle_t__ *m_ColorMeshHandle; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *handlea; // [esp+14h] [ebp+8h]

  v2 = handle;
  if ( (_WORD)handle != 0xFFFF )
  {
    v4 = (unsigned __int16)handle;
    g_pStudioRender->DestroyDecalList(
      this: g_pStudioRender,
      a2: this->m_ModelInstances.m_Memory.m_pMemory[v4].m_Element.m_DecalHandle);
    g_pShadowMgr->RemoveAllShadowsFromModel(this: g_pShadowMgr, a2: handle);
    m_ColorMeshHandle = this->m_ModelInstances.m_Memory.m_pMemory[v4].m_Element.m_ColorMeshHandle;
    if ( m_ColorMeshHandle != nullptr )
    {
      this->m_pCache->Remove(this: this->m_pCache, a2: m_ColorMeshHandle, a3: nullptr, a4: nullptr, a5: true);
      this->m_ModelInstances.m_Memory.m_pMemory[v4].m_Element.m_ColorMeshHandle = nullptr;
    }
    CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_ModelInstances,
      elem: handle);
    handlea = &this->m_ModelInstances.m_Memory.m_pMemory[v4];
    CUtlMemoryPool::Free(
      this: &CModelRender::ModelInstanceLightingState_t::s_Allocator,
      memBlock: handlea->m_Element.m_pLightingState);
    handlea->m_Next = this->m_ModelInstances.m_FirstFree;
    this->m_ModelInstances.m_FirstFree = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0E70
// Name: private: virtual bool CResourcePreloadPropLighting::CreateResource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourcePreloadPropLighting::CreateResource(CResourcePreloadPropLighting *this, const char *pName)
{
  char szFilename[260]; // [esp+0h] [ebp-230h] BYREF
  char szBasename[260]; // [esp+104h] [ebp-12Ch] BYREF
  LoaderJob_t loaderJob; // [esp+208h] [ebp-28h] BYREF

  if ( r_proplightingfromdisk.m_pParent != nullptr && r_proplightingfromdisk.m_pParent->m_Value.m_nValue != 0 )
  {
    V_FileBase(in: pName, out: szBasename, maxlen: 260);
    V_snprintf(pDest: szFilename, maxLen: 260, pFormat: "%s%s.vhv", szBasename, defaultValue);
    g_pQueuedLoader->IsSameMapLoading(this: g_pQueuedLoader);
    loaderJob.m_pFilename = szFilename;
    memset(&loaderJob.m_pCallback, 0, 24);
    *(_DWORD *)&loaderJob.m_bPersistTargetData = 0;
    loaderJob.m_pPathID = "GAME";
    loaderJob.m_Priority = LOADERPRIORITY_DURINGPRELOAD;
    g_pQueuedLoader->AddJob(this: g_pQueuedLoader, a2: &loaderJob);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E0F30
// Name: public: virtual int CModelRender::DrawModelExStaticProp(class IMatRenderContext __near *,struct ModelRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::DrawModelExStaticProp(
        CModelRender *this,
        IMatRenderContext *pRenderContext,
        ModelRenderInfo_t *pInfo)
{
  ModelRenderInfo_t *v3; // esi
  studiohdr_t *(__thiscall *GetStudioHdr)(IMDLCache *, unsigned __int16); // edx
  int v6; // ebx
  bool v7; // zf
  IClientRenderable *pRenderable; // eax
  studiohwdata_t *v9; // eax
  int flags; // eax
  int instance; // edx
  int v13; // eax
  int m_nValue; // edi
  bool v15; // bl
  IDataCacheSection *m_pCache; // ecx
  IDataCacheSection_vtbl *v17; // edx
  int v18; // eax
  void *v19; // edi
  int v20; // eax
  LightCacheHandle_t__ **p_m_LightCacheHandle; // edi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v23; // eax
  int skin; // ecx
  int body; // edx
  int hitboxset; // eax
  int studio; // [esp-4h] [ebp-238h]
  DrawModelInfo_t info; // [esp+Ch] [ebp-228h] BYREF
  Vector entOrigin; // [esp+1ECh] [ebp-48h] BYREF
  DrawModelState_t state; // [esp+1F8h] [ebp-3Ch] BYREF
  int lod; // [esp+214h] [ebp-20h]
  StudioDecalHandle_t__ *decalHandle; // [esp+218h] [ebp-1Ch]
  BOOL bVertexLit; // [esp+21Ch] [ebp-18h]
  memhandle_t__ *hColorMeshData; // [esp+220h] [ebp-14h]
  ColorMeshInfo_t *pColorMeshes; // [esp+224h] [ebp-10h]
  BOOL bNeedsEnvCubemap; // [esp+228h] [ebp-Ch]
  CModelRender *v37; // [esp+22Ch] [ebp-8h]
  bool bShadowDepth; // [esp+233h] [ebp-1h]
  int drawFlags; // [esp+23Ch] [ebp+8h]

  v3 = pInfo;
  bShadowDepth = (pInfo->flags & 0x40000000) != 0;
  GetStudioHdr = g_pMDLCache->GetStudioHdr;
  studio = pInfo->pModel->studio;
  v37 = this;
  v6 = ((int (__stdcall *)(int))GetStudioHdr)(a1: studio);
  v7 = *(_DWORD *)(v6 + 232) == 0;
  pRenderable = v3->pRenderable;
  state.m_pStudioHdr = (studiohdr_t *)v6;
  state.m_pRenderable = pRenderable;
  if ( !v7 && !g_bTextMode )
  {
    v9 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: v3->pModel->studio);
    state.m_pStudioHWData = v9;
    if ( v9 != nullptr )
    {
      state.m_pModelToWorld = v3->pModelToWorld;
      lod = CModelRender::ComputeLOD(this, pRenderContext, info: v3, pStudioHWData: v9);
      flags = v3->flags;
      if ( (flags & 1) != 0 )
      {
        instance = v3->instance;
        decalHandle = nullptr;
        if ( (_WORD)instance != 0xFFFF && (flags & 0x40000000) == 0 )
          decalHandle = this->m_ModelInstances.m_Memory.m_pMemory[instance].m_Element.m_DecalHandle;
        drawFlags = 0;
        if ( (flags & 8) != 0 )
          drawFlags = (flags < 0) + 1;
        if ( (flags & 0x10) != 0 )
          drawFlags |= 8u;
        if ( (flags & 0x20) != 0 )
          drawFlags |= 0x80u;
        g_pShadowMgr->SetModelShadowState(this: g_pShadowMgr, a2: instance);
        v13 = v3->pModel->flags;
        if ( r_staticlight_streams.m_pParent != nullptr )
          m_nValue = r_staticlight_streams.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        v15 = (drawFlags & 8) != 0
           && (*(_BYTE *)(v6 + 152) & 0x10) != 0
           && ((v3->pModel->flags & 0x200) == 0 || m_nValue > 1)
           && v3->instance != 0xFFFF;
        LOBYTE(bVertexLit) = (v3->pModel->flags & 4) != 0;
        HIBYTE(pInfo) = v15;
        if ( r_showenvcubemap.m_pParent != nullptr && r_showenvcubemap.m_pParent->m_Value.m_nValue != 0
          || (LOBYTE(bNeedsEnvCubemap) = 0, (v13 & 0x400) != 0) )
        {
          LOBYTE(bNeedsEnvCubemap) = 1;
        }
        if ( r_drawmodellightorigin.m_pParent != nullptr && r_drawmodellightorigin.m_pParent->m_Value.m_nValue != 0 )
          CModelRender::DebugDrawLightingOrigin(this: v37, &state, pInfo: v3);
        pColorMeshes = nullptr;
        hColorMeshData = nullptr;
        if ( !v15 )
          goto LABEL_43;
        m_pCache = v37->m_pCache;
        v17 = m_pCache->__vftable;
        hColorMeshData = v37->m_ModelInstances.m_Memory.m_pMemory[v3->instance].m_Element.m_ColorMeshHandle;
        v18 = (int)v17->Get(this: m_pCache, a2: hColorMeshData, a3: true);
        v19 = (void *)v18;
        if ( v18 != 0 && (*(_BYTE *)(v18 + 20) & 2) == 0 )
          goto LABEL_39;
        if ( ((unsigned __int8 (__stdcall *)(_DWORD))v37->RecomputeStaticLighting)(a1: v3->instance) != 0 )
        {
          v19 = v37->m_pCache->Get(this: v37->m_pCache, a2: hColorMeshData, a3: 1);
          goto LABEL_39;
        }
        if ( v19 != nullptr && (*((_BYTE *)v19 + 20) & 2) != 0 )
        {
LABEL_39:
          if ( v19 != nullptr && (*((_BYTE *)v19 + 20) & 1) != 0 )
            pColorMeshes = *((ColorMeshInfo_t **)v19 + 1);
          else
            HIBYTE(pInfo) = 0;
LABEL_43:
          info.m_bStaticLighting = false;
          if ( (bVertexLit || bNeedsEnvCubemap) && !bShadowDepth )
          {
            v20 = v3->instance;
            p_m_LightCacheHandle = nullptr;
            if ( (_WORD)v20 == 0xFFFF
              || (m_pMemory = v37->m_ModelInstances.m_Memory.m_pMemory,
                  v7 = (m_pMemory[v20].m_Element.m_nFlags & 1) == 0,
                  v23 = &m_pMemory[v20],
                  v7)
              || v23->m_Element.m_LightCacheHandle == nullptr
              || (p_m_LightCacheHandle = &v23->m_Element.m_LightCacheHandle,
                  v23 == (UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *)-16) )
            {
              R_ComputeLightingOrigin(
                pRenderable: state.m_pRenderable,
                pStudioHdr: state.m_pStudioHdr,
                matrix: state.m_pModelToWorld,
                center: &entOrigin);
            }
            CModelRender::StudioSetupLighting(
              this: v37,
              &state,
              absEntCenter: &entOrigin,
              pLightcache: p_m_LightCacheHandle,
              bVertexLit,
              bNeedsEnvCubemap,
              bStaticLighting: (bool *)&pInfo + 3,
              drawInfo: &info,
              pInfo: v3,
              drawFlags);
          }
          info.m_pStudioHdr = state.m_pStudioHdr;
          skin = v3->skin;
          info.m_pHardwareData = state.m_pStudioHWData;
          body = v3->body;
          info.m_Decals = decalHandle;
          hitboxset = v3->hitboxset;
          info.m_Skin = skin;
          info.m_Body = body;
          info.m_HitboxSet = hitboxset;
          info.m_pClientEntity = (void *)state.m_pRenderable;
          info.m_Lod = lod;
          info.m_pColorMeshes = pColorMeshes;
          if ( bShadowDepth )
            drawFlags |= 0x200u;
          g_pStudioRender->DrawModelStaticProp(this: g_pStudioRender, a2: &info, a3: v3->pModelToWorld, a4: drawFlags);
          if ( pColorMeshes != nullptr )
            CModelRender::ProtectColorDataIfQueued(this: v37, hColorMesh: hColorMeshData);
          return 1;
        }
      }
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E1290
// Name: private: class CColorMeshData __near * CModelRender::FindOrCreateStaticPropColorData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
CColorMeshData *__thiscall CModelRender::FindOrCreateStaticPropColorData(CModelRender *this, unsigned __int16 handle)
{
  CColorMeshData *result; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v4; // esi
  studiohwdata_t *v5; // eax
  memhandle_t__ *v6; // eax
  colormeshparams_t params; // [esp+4h] [ebp-514h] BYREF
  char fn[260]; // [esp+414h] [ebp-104h] BYREF

  if ( handle == 0xFFFF )
    return nullptr;
  v4 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
  result = (CColorMeshData *)this->m_pCache->Get(this: this->m_pCache, a2: v4->m_Element.m_ColorMeshHandle, a3: 1);
  if ( result == nullptr )
  {
    v5 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: v4->m_Element.m_pModel->studio);
    if ( v5 == nullptr )
    {
      g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)v4->m_Element.m_pModel, a3: fn, a4: 260);
      Sys_Error(error: "g_pMDLCache->GetHardwareData failed for %s\n", fn);
      return nullptr;
    }
    CModelRender::InitColormeshParams(this, instance: &v4->m_Element, pStudioHWData: v5, pColorMeshParams: (int)&params);
    if ( params.m_nMeshes <= 0 )
      return nullptr;
    params.m_fnHandle = v4->m_Element.m_pModel->fnHandle;
    v6 = CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CacheCreate(
           this: &this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,
           createParams: &params,
           flags: 0);
    v4->m_Element.m_ColorMeshHandle = v6;
    CModelRender::ProtectColorDataIfQueued(this, hColorMesh: v6);
    return (CColorMeshData *)this->m_pCache->Get(this: this->m_pCache, a2: v4->m_Element.m_ColorMeshHandle, a3: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1390
// Name: private: void CModelRender::ValidateStaticPropColorData(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelRender::ValidateStaticPropColorData(
        CModelRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned __int16 handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v4; // esi
  int v5; // edi
  CStaticPropMgr *v6; // eax
  CStaticPropMgr *v7; // eax
  CStaticPropMgr *v8; // eax
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // edx
  int v10; // eax
  int m_nValue; // ecx
  char fileName[260]; // [esp+0h] [ebp-134h] BYREF
  CUtlBuffer utlBuf; // [esp+104h] [ebp-30h] BYREF

  if ( r_proplightingfromdisk.m_pParent != nullptr && r_proplightingfromdisk.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = &this->m_ModelInstances.m_Memory.m_pMemory[handle];
    v5 = (int)v4->m_Element.m_pRenderable->GetIClientUnknown(this: v4->m_Element.m_pRenderable);
    v6 = StaticPropMgr();
    if ( v6->IsStaticProp_2(this: v6, a2: (IHandleEntity *)v5) && g_bLoadedMapHasBakedPropLighting )
    {
      CUtlBuffer::CUtlBuffer(this: &utlBuf, growSize: 0, initSize: 0, nFlags: 0);
      if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int, int))g_pMaterialSystemHardwareConfig->GetHDRType)(
             a1: g_pMaterialSystemHardwareConfig,
             a2,
             a3) == 0
        || g_bBakedPropLightingNoSeparateHDR )
      {
        v8 = StaticPropMgr();
        *(_DWORD *)&fileName[4] = ((int (__thiscall *)(CStaticPropMgr *, int, const char *, _DWORD, _DWORD))v8->GetStaticPropIndex)(
                                    a1: v8,
                                    a2: v5,
                                    a3: defaultValue,
                                    a4: *(_DWORD *)fileName,
                                    a5: *(_DWORD *)&fileName[4]);
        V_snprintf(pDest: fileName, maxLen: 260, pFormat: "sp_%d%s.vhv");
      }
      else
      {
        v7 = StaticPropMgr();
        *(_DWORD *)&fileName[4] = ((int (__thiscall *)(CStaticPropMgr *, int, const char *, _DWORD, _DWORD))v7->GetStaticPropIndex)(
                                    a1: v7,
                                    a2: v5,
                                    a3: defaultValue,
                                    a4: *(_DWORD *)fileName,
                                    a5: *(_DWORD *)&fileName[4]);
        V_snprintf(pDest: fileName, maxLen: 260, pFormat: "sp_hdr_%d%s.vhv");
      }
      ReadFile = g_pFileSystem->ReadFile;
      *(_DWORD *)&fileName[8] = 0;
      *(_DWORD *)&fileName[4] = 0;
      *(_DWORD *)fileName = 40;
      if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))ReadFile)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: fileName) != 0 )
      {
        v10 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v4->m_Element.m_pModel->studio);
        if ( r_staticlight_streams.m_pParent != nullptr )
          m_nValue = r_staticlight_streams.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( *(_DWORD *)utlBuf.m_Memory.m_pMemory == 2
          && *((_DWORD *)utlBuf.m_Memory.m_pMemory + 1) == *(_DWORD *)(v10 + 8)
          && *((_DWORD *)utlBuf.m_Memory.m_pMemory + 3) == 4 * m_nValue )
        {
          v4->m_Element.m_nFlags = v4->m_Element.m_nFlags & 0xFFF9 | 2;
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &utlBuf);
          return;
        }
        v4->m_Element.m_nFlags |= 4u;
      }
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &utlBuf);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1510
// Name: public: virtual unsigned short CModelRender::CreateInstance(class IClientRenderable __near *,struct LightCacheHandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CModelRender::CreateInstance(
        CModelRender *this,
        IClientRenderable *pRenderable,
        LightCacheHandle_t__ **pCache)
{
  unsigned __int16 v4; // ax
  int v5; // esi
  int v6; // ebx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v7; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v8; // esi
  _DWORD *p_m_flLightingTime; // eax
  _DWORD *v10; // eax
  CModelRender *v11; // esi
  model_t *pModel; // [esp+10h] [ebp-4h]

  pModel = (model_t *)pRenderable->GetModel(this: pRenderable);
  v4 = CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_ModelInstances,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = 0xFFFF;
  }
  else
  {
    CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_ModelInstances,
      before: 0xFFFFu,
      elem: v4);
    v7 = &this->m_ModelInstances.m_Memory.m_pMemory[v5];
    if ( v7 != nullptr )
      CModelRender::ModelInstance_t::ModelInstance_t(this: &v7->m_Element);
    v6 = v5;
  }
  v8 = &this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)v6];
  p_m_flLightingTime = (_DWORD *)&v8->m_Element.m_pLightingState->m_flLightingTime;
  v8->m_Element.m_pRenderable = pRenderable;
  v8->m_Element.m_DecalHandle = nullptr;
  v8->m_Element.m_pModel = pModel;
  v8->m_Element.m_ColorMeshHandle = nullptr;
  *p_m_flLightingTime = -915135504;
  v10 = (_DWORD *)&v8->m_Element.m_pLightingState->m_flLightingTime;
  v8->m_Element.m_LightCacheHandle = nullptr;
  v8->m_Element.m_nFlags = 0;
  v10[24] = 0;
  v10[27] = 0;
  v10[25] = 0;
  v10[26] = 0;
  v10[28] = 0;
  v10[29] = 0;
  v10[30] = 0;
  v10[31] = 0;
  v10[32] = 0;
  v10[33] = 0;
  v10[34] = 0;
  v10[35] = 0;
  v10[36] = 0;
  v10[37] = 0;
  v10[38] = 0;
  v10[39] = 0;
  v10[40] = 0;
  v10[41] = 0;
  v10[42] = 0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[0].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[1].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[2].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[3].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[4].x = 1.0;
  v8->m_Element.m_pLightingState->m_AmbientLightingState.r_boxcolor[5].x = 1.0;
  v8->m_Element.m_FirstShadow = g_pShadowMgr->InvalidShadowIndex(this: g_pShadowMgr);
  if ( pCache != nullptr )
  {
    v11 = this;
    this->SetStaticLighting(this, a2: v6, a3: pCache);
    CModelRender::ValidateStaticPropColorData(this: v11, a2: 0, a3: (int)v11, handle: v6);
    v11->RecomputeStaticLighting(this: v11, a2: v6);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E1740
// Name: public: CModelRender::CModelRender(void)
// Source: json
//------------------------------------------------------------------------------
CModelRender *__thiscall CModelRender::CModelRender(CModelRender *this)
{
  this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)&CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::`vftable';
  this->m_pCache = nullptr;
  this->IVModelRender::__vftable = (CModelRender_vtbl *)&CModelRender::`vftable'{for `IVModelRender'};
  this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)&CModelRender::`vftable'{for `CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>'};
  this->m_ModelInstances.m_Memory.m_pMemory = nullptr;
  this->m_ModelInstances.m_Memory.m_nAllocationCount = 0;
  this->m_ModelInstances.m_Memory.m_nGrowSize = 0;
  this->m_ModelInstances.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_ModelInstances.m_FirstFree = 0xFFFF;
  this->m_ModelInstances.m_pElements = this->m_ModelInstances.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_ModelInstances.m_Head = -1;
  this->m_ModelInstances.m_NumAlloced = 0;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Root = -1;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_NumElements = 0;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_pElements = this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_CachedStaticPropColorData.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_CachedStaticPropMutex.m_ownerID = 0;
  this->m_CachedStaticPropMutex.m_depth = 0;
  this->m_colorMeshVBAllocator.__vftable = (CPooledVBAllocator_ColorMesh_vtbl *)&CPooledVBAllocator_ColorMesh::`vftable';
  this->m_colorMeshVBAllocator.m_pMesh = nullptr;
  CPooledVBAllocator_ColorMesh::Clear(this: &this->m_colorMeshVBAllocator, a2: (int)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E17E0
// Name: public: virtual CModelRender::~CModelRender(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CModelRender::~CModelRender(CModelRender *this@<ecx>, int a2@<esi>)
{
  bool v3; // zf
  IDataCacheSection *m_pCache; // esi
  IDataCache *v5; // ebx
  int v6; // eax
  IDataCache_vtbl *v7; // [esp+8h] [ebp-4h]

  v3 = this->m_colorMeshVBAllocator.m_pMesh == nullptr;
  this->m_colorMeshVBAllocator.__vftable = (CPooledVBAllocator_ColorMesh_vtbl *)&CPooledVBAllocator_ColorMesh::`vftable';
  if ( v3 )
  {
    if ( this->m_colorMeshVBAllocator.m_numAllocations > 0 )
      _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh has unfreed allocations!");
  }
  else
  {
    _Warning(a1: "ERROR: CPooledVBAllocator_ColorMesh's internal mesh (vertex buffer) should have been freed!\n");
  }
  CPooledVBAllocator_ColorMesh::Clear(this: &this->m_colorMeshVBAllocator, a2);
  this->m_colorMeshVBAllocator.__vftable = (CPooledVBAllocator_ColorMesh_vtbl *)&IPooledVBAllocator::`vftable';
  CUtlDict<memhandle_t__ *,int>::RemoveAll(this: &this->m_CachedStaticPropColorData);
  CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int,CUtlMap<char const *,memhandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,memhandle_t__ *,int>::Node_t,int>,int>>(this: &this->m_CachedStaticPropColorData.m_Elements.m_Tree);
  CUtlLinkedList<CModelRender::ModelInstance_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_ModelInstances);
  if ( this->m_ModelInstances.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ModelInstances.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ModelInstances.m_Memory.m_pMemory);
      this->m_ModelInstances.m_Memory.m_pMemory = nullptr;
    }
    this->m_ModelInstances.m_Memory.m_nAllocationCount = 0;
  }
  m_pCache = this->m_pCache;
  this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)&CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::`vftable';
  if ( m_pCache != nullptr )
  {
    v5 = m_pCache->GetSharedCache(this: m_pCache);
    v7 = v5->__vftable;
    v6 = ((int (__thiscall *)(IDataCacheSection *, int))m_pCache->GetName)(a1: m_pCache, a2: 1);
    ((void (__thiscall *)(IDataCache *, int))v7->RemoveSection)(a1: v5, a2: v6);
    this->m_pCache = nullptr;
  }
  this->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::CDefaultDataCacheClient::IDataCacheClient::__vftable = (CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>_vtbl *)&IDataCacheClient::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100E18E0
// Name: private: virtual void CResourcePreloadPropLighting::PurgeUnreferencedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadPropLighting::PurgeUnreferencedResources(CResourcePreloadPropLighting *this)
{
  g_pQueuedLoader->IsSameMapLoading(this: g_pQueuedLoader);
}

//------------------------------------------------------------------------------
// Address: 0x100E18F0
// Name: public: virtual void CModelRender::ReleaseAllStaticPropColorData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ReleaseAllStaticPropColorData(CModelRender *this)
{
  int i; // ebx
  int v3; // esi
  memhandle_t__ *m_ColorMeshHandle; // eax

  for ( i = this->m_ModelInstances.m_Head;
        i != 0xFFFF;
        i = this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)i].m_Next )
  {
    v3 = (unsigned __int16)i;
    m_ColorMeshHandle = this->m_ModelInstances.m_Memory.m_pMemory[v3].m_Element.m_ColorMeshHandle;
    if ( m_ColorMeshHandle != nullptr )
    {
      this->m_pCache->Remove(this: this->m_pCache, a2: m_ColorMeshHandle, a3: nullptr, a4: nullptr, a5: true);
      this->m_ModelInstances.m_Memory.m_pMemory[v3].m_Element.m_ColorMeshHandle = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E19D0
// Name: public: struct DrawModelResults_t __near & DrawModelResults_t::operator=(struct DrawModelResults_t const __near &)
// Source: json
//------------------------------------------------------------------------------
DrawModelResults_t *__thiscall DrawModelResults_t::operator=(
        DrawModelResults_t *this,
        const DrawModelResults_t *__that)
{
  DrawModelResults_t *result; // eax
  int m_Size; // edx
  CUtlVectorFixed<IMaterial *,8> *p_m_Materials; // ecx
  int v5; // esi

  result = this;
  this->m_ActualTriCount = __that->m_ActualTriCount;
  this->m_TextureMemoryBytes = __that->m_TextureMemoryBytes;
  this->m_NumHardwareBones = __that->m_NumHardwareBones;
  this->m_NumBatches = __that->m_NumBatches;
  this->m_NumMaterials = __that->m_NumMaterials;
  this->m_nLODUsed = __that->m_nLODUsed;
  this->m_flLODMetric = __that->m_flLODMetric;
  this->m_RenderTime.m_Duration.m_Int64 = __that->m_RenderTime.m_Duration.m_Int64;
  m_Size = __that->m_Materials.m_Size;
  p_m_Materials = &this->m_Materials;
  p_m_Materials->m_Size = 0;
  if ( m_Size != 0 )
  {
    p_m_Materials->m_Size = m_Size;
    p_m_Materials->m_pElements = (IMaterial **)p_m_Materials;
    if ( m_Size > 0 )
    {
      v5 = (char *)&__that->m_Materials - (char *)p_m_Materials;
      do
      {
        *(_DWORD *)p_m_Materials->m_Memory.m_Memory = *(_DWORD *)&p_m_Materials->m_Memory.m_Memory[v5];
        p_m_Materials = (CUtlVectorFixed<IMaterial *,8> *)((char *)p_m_Materials + 4);
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1BD0
// Name: public: void CModelRender::StaticPropColorMeshCallback(void __near *,void const __near *,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::StaticPropColorMeshCallback(
        CModelRender *this,
        memhandle_t__ **pContext,
        _DWORD *pData,
        int numReadBytes,
        FSAsyncStatus_t asyncStatus)
{
  int v5; // edi
  int v7; // edx
  int v8; // eax
  memhandle_t__ **v9; // ecx
  _DWORD *v10; // esi
  int v11; // eax
  int meshID; // [esp+8h] [ebp-4h]
  int numLightingComponents; // [esp+18h] [ebp+Ch]
  FSAsyncStatus_t asyncStatusa; // [esp+20h] [ebp+14h]

  v5 = 0;
  if ( asyncStatus == FSASYNC_OK )
  {
    v7 = pData[5];
    v8 = 0;
    if ( v7 > 0 )
    {
      v9 = (memhandle_t__ **)(pData + 10);
      do
      {
        if ( *v9 == pContext[3] )
          break;
        ++v8;
        v9 += 7;
      }
      while ( v8 < v7 );
    }
    if ( r_staticlight_streams.m_pParent != nullptr )
      numLightingComponents = r_staticlight_streams.m_pParent->m_Value.m_nValue;
    else
      numLightingComponents = 0;
    meshID = v8;
    if ( v8 < v7 )
    {
      asyncStatusa = FSASYNC_OK;
      v10 = &pData[7 * v8 + 12];
      do
      {
        v11 = *(v10 - 1);
        if ( v11 != *(_DWORD *)(*((_DWORD *)pContext[1] + 1) + asyncStatusa + 12) )
          break;
        _V_memcpy(
          dest: *(void **)(*((_DWORD *)pContext[1] + 2) + v5),
          src: (char *)pData + *v10,
          count: 4 * numLightingComponents * v11);
        asyncStatusa += 16;
        v5 += 4;
        v10 += 7;
        ++meshID;
      }
      while ( meshID < pData[5] );
    }
  }
  *((_DWORD *)pContext[1] + 5) |= 1u;
  this->m_pCache->Unlock(this: this->m_pCache, a2: *pContext);
  free(pMem: pContext);
}

//------------------------------------------------------------------------------
// Address: 0x100E1CF0
// Name: private: bool CModelRender::LoadStaticPropColorData(class IHandleEntity __near *,struct memhandle_t__ __near *,struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CModelRender::LoadStaticPropColorData@<al>(
        CModelRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        IHandleEntity *pProp,
        memhandle_t__ *colorMeshHandle,
        studiohwdata_t *pStudioHWData)
{
  _DWORD *v6; // edi
  CStaticPropMgr *v8; // eax
  CStaticPropMgr *v9; // eax
  void *v10; // esi
  int v12; // [esp-4h] [ebp-140h]
  int v13; // [esp-4h] [ebp-140h]
  char fileName[260]; // [esp+4h] [ebp-138h] BYREF
  FileAsyncRequest_t fileRequest; // [esp+108h] [ebp-34h] BYREF
  CModelRender *v16; // [esp+134h] [ebp-8h]
  FSAsyncControl_t__ **v17; // [esp+138h] [ebp-4h]

  v16 = this;
  if ( !g_bLoadedMapHasBakedPropLighting
    || r_proplightingfromdisk.m_pParent == nullptr
    || r_proplightingfromdisk.m_pParent->m_Value.m_nValue == 0 )
  {
    return 0;
  }
  v6 = this->m_pCache->Lock(this: this->m_pCache, a2: colorMeshHandle);
  if ( v6 == nullptr )
    return 0;
  v17 = (FSAsyncControl_t__ **)(v6 + 4);
  if ( v6[4] != 0 )
  {
    v16->m_pCache->Unlock(this: v16->m_pCache, a2: colorMeshHandle);
    return 1;
  }
  else
  {
    if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int, int))g_pMaterialSystemHardwareConfig->GetHDRType)(
           a1: g_pMaterialSystemHardwareConfig,
           a2,
           a3) == 0
      || g_bBakedPropLightingNoSeparateHDR )
    {
      v9 = StaticPropMgr();
      v13 = ((int (__thiscall *)(CStaticPropMgr *, IHandleEntity *, const char *))v9->GetStaticPropIndex)(
              a1: v9,
              a2: pProp,
              a3: defaultValue);
      V_snprintf(pDest: fileName, maxLen: 260, pFormat: "sp_%d%s.vhv", v13);
    }
    else
    {
      v8 = StaticPropMgr();
      v12 = ((int (__thiscall *)(CStaticPropMgr *, IHandleEntity *, const char *))v8->GetStaticPropIndex)(
              a1: v8,
              a2: pProp,
              a3: defaultValue);
      V_snprintf(pDest: fileName, maxLen: 260, pFormat: "sp_hdr_%d%s.vhv", v12);
    }
    v6[5] &= ~1u;
    v10 = MemAlloc_Alloc(nSize: 0x114u);
    *((_DWORD *)v10 + 3) = pStudioHWData->m_RootLOD;
    *((_DWORD *)v10 + 2) = *v6;
    *(_DWORD *)v10 = colorMeshHandle;
    *((_DWORD *)v10 + 1) = v6;
    V_strncpy(pDest: (char *)v10 + 16, pSrc: fileName, maxLen: 260);
    memset(dst: (unsigned __int8 *)&fileRequest, value: 0, count: sizeof(fileRequest));
    fileRequest.pszFilename = fileName;
    fileRequest.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
    fileRequest.pContext = v10;
    fileRequest.pfnCallback = StaticPropColorMeshCallback;
    memset(&fileRequest.pData, 0, 12);
    fileRequest.flags = 0;
    fileRequest.priority = -1;
    fileRequest.pszPathID = "GAME";
    g_pFileSystem->AsyncReadMultiple(this: g_pFileSystem, a2: &fileRequest, a3: 1, a4: v17);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1E80
// Name: private: bool CModelRender::UpdateStaticPropColorData(class IHandleEntity __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __thiscall CModelRender::UpdateStaticPropColorData(
        CModelRender *this,
        LightcacheGetDynamic_Stats pProp,
        studiohdr_t *handle)
{
  IMDLCache *v3; // esi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  IUniformRandomStream *v6; // ecx
  int v8; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v9; // esi
  unsigned __int16 m_nFlags; // ax
  int v11; // eax
  int studio; // edx
  studiohwdata_t *v13; // eax
  bool v14; // zf
  IClientRenderable *m_pRenderable; // edi
  const QAngle *v16; // eax
  PropLightcache_t *m_LightCacheHandle; // eax
  LightCacheHandle_t__ *Static; // eax
  studiohdr_t *v19; // ecx
  float x; // edx
  int v21; // eax
  mstudiobodyparts_t *v22; // eax
  mstudiomodel_t *v23; // esi
  float v24; // eax
  void *v25; // eax
  int v26; // edi
  unsigned __int8 *v27; // eax
  unsigned __int8 v28; // dl
  unsigned __int8 v29; // cl
  studiohwdata_t *v30; // ecx
  int m_RootLOD; // edx
  int v32; // eax
  int v33; // eax
  mstudiomesh_t *v34; // eax
  int v35; // edx
  studiomeshdata_t *v36; // eax
  char *v37; // esi
  int v38; // edi
  ColorMeshInfo_t *v39; // edi
  int i; // edi
  int v41; // eax
  int m_nVertexCount; // eax
  int v43; // edx
  int v44; // eax
  const Vector *v45; // [esp+4h] [ebp-2F0h]
  unsigned int v46; // [esp+8h] [ebp-2ECh]
  matrix3x4_t matrix; // [esp+20h] [ebp-2D4h] BYREF
  CMeshBuilder meshBuilder; // [esp+50h] [ebp-2A4h] BYREF
  LightingState_t lightingState; // [esp+238h] [ebp-BCh] BYREF
  mstudiobodyparts_t *pBodyPart; // [esp+294h] [ebp-60h]
  mstudiomodel_t *pModel; // [esp+298h] [ebp-5Ch]
  CModelRender *v52; // [esp+29Ch] [ebp-58h]
  float flConstDirLightingAmount; // [esp+2A0h] [ebp-54h]
  int v54; // [esp+2A4h] [ebp-50h]
  studiomeshdata_t *pStudioMeshData; // [esp+2A8h] [ebp-4Ch]
  int lodID; // [esp+2ACh] [ebp-48h]
  int stripGroupID; // [esp+2B0h] [ebp-44h]
  BOOL bUseConstDirLighting; // [esp+2B4h] [ebp-40h]
  int v59; // [esp+2B8h] [ebp-3Ch]
  mstudiomesh_t *pMesh; // [esp+2BCh] [ebp-38h]
  int bodyPartID; // [esp+2C0h] [ebp-34h]
  int modelID; // [esp+2C4h] [ebp-30h]
  int meshID; // [esp+2C8h] [ebp-2Ch]
  int v64; // [esp+2CCh] [ebp-28h]
  int v65; // [esp+2D0h] [ebp-24h]
  CColorMeshData *pColorMeshData; // [esp+2D4h] [ebp-20h]
  studiohwdata_t *pStudioHWData; // [esp+2D8h] [ebp-1Ch]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+2DCh] [ebp-18h]
  Vector entOrigin; // [esp+2E0h] [ebp-14h] BYREF
  unsigned __int8 debugColor[7]; // [esp+2ECh] [ebp-8h]
  bool bDebugColor; // [esp+2F3h] [ebp-1h]

  v3 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  v52 = this;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  pColorMeshData = CModelRender::FindOrCreateStaticPropColorData(this, (unsigned __int16)handle);
  if ( pColorMeshData != nullptr )
  {
    bDebugColor = false;
    if ( r_debugrandomstaticlighting.m_pParent != nullptr
      && r_debugrandomstaticlighting.m_pParent->m_Value.m_nValue != 0 )
    {
      v8 = _RandomInt(this: v6, a2: 1, a3: 6);
      entOrigin.x = (float)((v8 >> 2) & 1);
      entOrigin.y = (float)((v8 >> 1) & 1);
      entOrigin.z = (float)(v8 & 1);
      VectorNormalize(vec: &entOrigin);
      debugColor[0] = (int)(float)(entOrigin.x * 255.0);
      debugColor[1] = (int)(float)(entOrigin.y * 255.0);
      debugColor[2] = (int)(float)(entOrigin.z * 255.0);
      bDebugColor = true;
    }
    v9 = &this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)handle];
    if ( r_proplightingfromdisk.m_pParent != nullptr && r_proplightingfromdisk.m_pParent->m_Value.m_nValue == 2 )
    {
      m_nFlags = v9->m_Element.m_nFlags;
      if ( (m_nFlags & 4) != 0 )
      {
        *(_WORD *)debugColor = 255;
      }
      else
      {
        *(_WORD *)debugColor = -256;
        if ( (m_nFlags & 2) == 0 )
          *(_WORD *)debugColor = -1;
      }
      debugColor[2] = 0;
      bDebugColor = true;
    }
    v11 = ((int (__cdecl *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v9->m_Element.m_pModel->studio);
    studio = v9->m_Element.m_pModel->studio;
    handle = (studiohdr_t *)v11;
    v13 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: studio);
    v14 = (v9->m_Element.m_nFlags & 1) == 0;
    pStudioHWData = v13;
    if ( !v14
      && v9->m_Element.m_LightCacheHandle != nullptr
      && !modelinfo->UsesStaticLighting(this: modelinfo, a2: v9->m_Element.m_pModel) )
    {
      LightcacheGetStatic(
        cache: (PropLightcache_t *)v9->m_Element.m_LightCacheHandle,
        pEnvCubemapTexture: nullptr,
        flags: 7u);
    }
    if ( !bDebugColor
      && (v9->m_Element.m_nFlags & 2) != 0
      && CModelRender::LoadStaticPropColorData(
           this,
           a2: (int)this,
           a3: (int)v9,
           pProp: *(IHandleEntity **)&pProp,
           colorMeshHandle: v9->m_Element.m_ColorMeshHandle,
           pStudioHWData) != 0 )
    {
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return 1;
    }
    else
    {
      *((_DWORD *)pColorMeshData + 5) = *((_DWORD *)pColorMeshData + 5) & 0xFFFFFFFC | 2;
      if ( bDebugColor || ((int (__cdecl *)(_DWORD))g_pMDLCache->GetVertexData)(a1: LOWORD(handle->virtualModel)) != 0 )
      {
        v9->m_Element.m_nFlags |= 8u;
        this->m_pStudioHdr = handle;
        m_pRenderable = v9->m_Element.m_pRenderable;
        v45 = v9->m_Element.m_pRenderable->GetRenderOrigin(this: v9->m_Element.m_pRenderable);
        v16 = m_pRenderable->GetRenderAngles(this: m_pRenderable);
        AngleMatrix(angles: v16, position: v45, &matrix);
        memset(&lightingState, 0, 76);
        if ( (v9->m_Element.m_nFlags & 1) != 0
          && (m_LightCacheHandle = (PropLightcache_t *)v9->m_Element.m_LightCacheHandle) != nullptr )
        {
          Static = LightcacheGetStatic(cache: m_LightCacheHandle, pEnvCubemapTexture: nullptr, flags: 1u);
          LightingState_t::operator=(this: &lightingState, __that: (const LightingState_t *)Static);
        }
        else
        {
          R_ComputeLightingOrigin(
            pRenderable: v9->m_Element.m_pRenderable,
            pStudioHdr: handle,
            &matrix,
            center: &entOrigin);
          LightcacheGetDynamic(
            a1: 0.0,
            origin: &entOrigin,
            &lightingState,
            stats: &pProp,
            pRenderable: v9->m_Element.m_pRenderable,
            flags: 1,
            bDebugModel: false);
        }
        v19 = handle;
        v14 = (handle->flags & 0x2000) == 0;
        LOBYTE(bUseConstDirLighting) = 0;
        flConstDirLightingAmount = 0.0;
        if ( !v14 )
        {
          pProp = (LightcacheGetDynamic_Stats)handle->constdirectionallightdot;
          LOBYTE(bUseConstDirLighting) = 1;
          flConstDirLightingAmount = (double)*(int *)&pProp * 0.00392156862745098;
        }
        x = 0.0;
        entOrigin.x = 0.0;
        entOrigin.y = 0.0;
        bodyPartID = 0;
        if ( handle->numbodyparts <= 0 )
        {
LABEL_70:
          *((_DWORD *)pColorMeshData + 5) = *((_DWORD *)pColorMeshData + 5) & 0xFFFFFFFC | 1;
          if ( x != 0.0 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(x));
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
        else
        {
          v65 = 0;
          while ( 1 )
          {
            v21 = v65 + v19->bodypartindex;
            modelID = 0;
            v22 = (mstudiobodyparts_t *)((char *)v19 + v21);
            pBodyPart = v22;
            if ( v22->nummodels > 0 )
              break;
LABEL_69:
            v65 += 16;
            if ( ++bodyPartID >= v19->numbodyparts )
              goto LABEL_70;
          }
          v64 = 0;
          while ( 1 )
          {
            v23 = (mstudiomodel_t *)((char *)v22 + v64 + v22->modelindex);
            v24 = *(float *)&v23->numvertices;
            pModel = v23;
            if ( SLODWORD(entOrigin.y) < SLODWORD(v24) )
            {
              entOrigin.y = v24;
              v46 = 3 * LODWORD(v24);
              if ( x == 0.0 )
                v25 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v46);
              else
                v25 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: LODWORD(x), a3: v46);
              LODWORD(entOrigin.x) = v25;
            }
            if ( bDebugColor )
            {
              v26 = 0;
              if ( v23->numvertices > 0 )
              {
                v27 = (unsigned __int8 *)(LODWORD(entOrigin.x) + 2);
                do
                {
                  v28 = debugColor[1];
                  *(v27 - 2) = debugColor[0];
                  v29 = debugColor[2];
                  *(v27 - 1) = v28;
                  *v27 = v29;
                  ++v26;
                  v27 += 3;
                }
                while ( v26 < v23->numvertices );
              }
            }
            else
            {
              CModelRender::ComputeModelVertexLightingOld(
                this: v52,
                pModel: v23,
                &matrix,
                &lightingState,
                pLighting: (color24 *)LODWORD(entOrigin.x),
                bUseConstDirLighting,
                flConstDirLightAmount: flConstDirLightingAmount);
            }
            v30 = pStudioHWData;
            m_RootLOD = pStudioHWData->m_RootLOD;
            lodID = m_RootLOD;
            if ( m_RootLOD < pStudioHWData->m_NumLODs )
              break;
LABEL_67:
            v22 = pBodyPart;
            v64 += 148;
            x = entOrigin.x;
            if ( ++modelID >= pBodyPart->nummodels )
            {
              v19 = handle;
              goto LABEL_69;
            }
          }
          v32 = 32 * m_RootLOD;
          v59 = 32 * m_RootLOD;
          while ( 1 )
          {
            pStudioMeshData = *(studiomeshdata_t **)((char *)&v30->m_pLODs->m_pMeshData + v32);
            meshID = 0;
            if ( v23->nummeshes > 0 )
              break;
LABEL_66:
            ++m_RootLOD;
            v32 += 32;
            lodID = m_RootLOD;
            v59 = v32;
            if ( m_RootLOD >= v30->m_NumLODs )
              goto LABEL_67;
          }
          v33 = 0;
          v54 = 0;
          while ( 1 )
          {
            v34 = (mstudiomesh_t *)&v23->name[v33 + v23->meshindex];
            stripGroupID = 0;
            v35 = v34->meshid;
            pMesh = v34;
            v36 = &pStudioMeshData[v35];
            if ( v36->m_NumGroup > 0 )
              break;
LABEL_64:
            v33 = v54 + 116;
            ++meshID;
            v54 += 116;
            if ( meshID >= v23->nummeshes )
            {
              v32 = v59;
              m_RootLOD = lodID;
              goto LABEL_66;
            }
          }
          pProp = 0;
          while ( 1 )
          {
            v37 = (char *)v36->m_pMeshGroup + *(_DWORD *)&pProp;
            v38 = *((__int16 *)v37 + 19);
            meshBuilder.m_pMesh = nullptr;
            meshBuilder.m_bGenerateIndices = false;
            memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
            meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
            meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
            memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
            meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v39 = &pColorMeshData->m_pMeshInfos[v38];
            CMeshBuilder::Begin(
              this: &meshBuilder,
              pMesh: v39->m_pMesh,
              type: MATERIAL_HETEROGENOUS,
              nVertexCount: *((_DWORD *)v37 + 5),
              nIndexCount: 0,
              pMeshSettings: nullptr);
            if ( meshBuilder.m_ActualVertexSize == 0 )
              break;
            CVertexBuilder::AdvanceVertices(
              this: &meshBuilder.m_VertexBuilder,
              nVerts: v39->m_nVertOffsetInBytes / meshBuilder.m_ActualVertexSize);
            for ( i = 0; i < *((_DWORD *)v37 + 5); ++i )
            {
              v41 = pMesh->vertexoffset + *(unsigned __int16 *)(*((_DWORD *)v37 + 4) + 2 * i);
              *(_DWORD *)&meshBuilder.m_VertexBuilder.m_pSpecular[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                                * meshBuilder.m_VertexBuilder.m_VertexSize_Specular] = *(unsigned __int8 *)(LODWORD(entOrigin.x) + 2 * v41 + v41 + 2) | ((*(unsigned __int8 *)(LODWORD(entOrigin.x) + 2 * v41 + v41 + 1) | ((*(unsigned __int8 *)(v41 + LODWORD(entOrigin.x) + 2 * v41) | 0xFFFFFF00) << 8)) << 8);
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
            meshBuilder.m_pMesh->UnlockMesh(
              this: meshBuilder.m_pMesh,
              a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
              a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
              a4: &meshBuilder);
            v43 = pMesh->meshid;
            *(_DWORD *)&pProp += 44;
            v36 = &pStudioMeshData[v43];
            if ( ++stripGroupID >= v36->m_NumGroup )
            {
              v23 = pModel;
              v30 = pStudioHWData;
              goto LABEL_64;
            }
          }
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                v44 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                v44 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                v44 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                v44 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                v44 = 0;
                break;
              default:
                v44 = meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: v44);
          }
          meshBuilder.m_pMesh->UnlockMesh(
            this: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
            a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
            a4: &meshBuilder);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          meshBuilder.m_pMesh = nullptr;
          if ( LODWORD(entOrigin.x) != 0 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(entOrigin.x));
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 0;
        }
      }
      else
      {
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return 0;
      }
    }
  }
  else
  {
    v3->EndLock(this: v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E26A0
// Name: public: virtual void CModelRender::RestoreAllStaticPropColorData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::RestoreAllStaticPropColorData(CModelRender *this)
{
  studiohdr_t *m_Head; // eax
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *m_pMemory; // ecx
  int v4; // esi
  LightcacheGetDynamic_Stats v5; // eax
  studiohdr_t *v6; // [esp-8h] [ebp-Ch]

  if ( host_state.worldmodel != nullptr )
  {
    InvalidateStaticLightingCache();
    m_Head = (studiohdr_t *)this->m_ModelInstances.m_Head;
    if ( m_Head != (studiohdr_t *)0xFFFF )
    {
      m_pMemory = this->m_ModelInstances.m_Memory.m_pMemory;
      do
      {
        v4 = (unsigned __int16)m_Head;
        v6 = m_Head;
        v5 = (LightcacheGetDynamic_Stats)m_pMemory[v4].m_Element.m_pRenderable->GetIClientUnknown(this: m_pMemory[v4].m_Element.m_pRenderable);
        CModelRender::UpdateStaticPropColorData(this, pProp: v5, handle: v6);
        m_pMemory = this->m_ModelInstances.m_Memory.m_pMemory;
        m_Head = (studiohdr_t *)m_pMemory[v4].m_Next;
      }
      while ( m_Head != (studiohdr_t *)0xFFFF );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E26F0
// Name: public: virtual bool CModelRender::RecomputeStaticLighting(unsigned short)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelRender::RecomputeStaticLighting(CModelRender *this, studiohdr_t *handle)
{
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v4; // esi
  PropLightcache_t *m_LightCacheHandle; // eax
  LightCacheHandle_t__ *Static; // eax
  LightcacheGetDynamic_Stats v7; // eax

  if ( (_WORD)handle == 0xFFFF )
    return 0;
  v4 = &this->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)handle];
  if ( (v4->m_Element.m_pModel->flags & 0x2000) == 0 )
    return 1;
  if ( r_decalstaticprops.m_pParent != nullptr && r_decalstaticprops.m_pParent->m_Value.m_nValue != 0 )
  {
    m_LightCacheHandle = (PropLightcache_t *)v4->m_Element.m_LightCacheHandle;
    if ( m_LightCacheHandle != nullptr )
    {
      Static = LightcacheGetStatic(cache: m_LightCacheHandle, pEnvCubemapTexture: nullptr, flags: 1u);
      LightingState_t::operator=(
        this: &v4->m_Element.m_pLightingState->m_AmbientLightingState,
        __that: (const LightingState_t *)Static);
    }
  }
  if ( ((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: v4->m_Element.m_pModel->studio) == 0 )
    return 0;
  v7 = (LightcacheGetDynamic_Stats)v4->m_Element.m_pRenderable->GetIClientUnknown(this: v4->m_Element.m_pRenderable);
  return CModelRender::UpdateStaticPropColorData(this, pProp: v7, handle);
}

//------------------------------------------------------------------------------
// Address: 0x100E27A0
// Name: public: virtual void CModelRender::ComputeStaticLightingState(int,struct StaticLightingQuery_t const __near *,struct MaterialLightingState_t __near *,struct MaterialLightingState_t __near *,struct ColorMeshInfo_t __near * __near *,class ITexture __near * __near *,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRender::ComputeStaticLightingState(
        CModelRender *this,
        int nCount,
        ITexture *pQuery,
        IClientRenderable *pLightingState,
        MaterialLightingState_t *pDecalState,
        ColorMeshInfo_t **ppStaticLighting,
        ITexture **ppEnvCubemapTexture,
        memhandle_t__ **pColorMeshHandles)
{
  IClientRenderable *v9; // edi
  int v10; // esi
  ITexture *v11; // ecx
  ITexture **v12; // ebx
  float *v13; // esi
  float *v14; // edi
  float *v15; // edx
  int v16; // ecx
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v17; // ecx
  PropLightcache_t **p_m_LightCacheHandle; // ecx
  int v19; // esi
  void *v20; // esp
  int v21; // edi
  _BYTE *v22; // ebx
  IClientRenderable **v23; // eax
  MaterialLightingState_t *v24; // edx
  IClientRenderable *v25; // ecx
  IClientRenderable_vtbl *v26; // eax
  const model_t *v27; // eax
  memhandle_t__ *m_ColorMeshHandle; // eax
  memhandle_t__ **v29; // edi
  int v30; // eax
  memhandle_t__ **v31; // edx
  int v32; // edi
  ITexture **v33; // esi
  MaterialLightingState_t *v34; // eax
  bool v35; // zf
  char v36; // cl
  int v37; // eax
  LightcacheGetDynamic_Stats v38; // eax
  CModelRender *v39; // esi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v40; // edi
  PropLightcache_t **v41; // esi
  LightCacheHandle_t__ *Static; // eax
  int v43; // eax
  LightingState_t *p_lightingState; // esi
  float *p_m_flLightingTime; // eax
  float v46; // xmm1_4
  float v47; // xmm2_4
  float *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm2_4
  float *v51; // eax
  float v52; // xmm1_4
  float v53; // xmm2_4
  float *v54; // eax
  float v55; // xmm1_4
  float v56; // xmm2_4
  float *v57; // eax
  float v58; // xmm1_4
  float v59; // xmm2_4
  float *v60; // eax
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm2_4
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // edi
  int v65; // eax
  dworldlight_t **locallight; // edx
  dworldlight_t **v67; // ecx
  float v68; // eax
  float v69; // edx
  float v70; // xmm0_4
  CModelRender *v71; // edi
  MaterialLightingState_t *v72; // esi
  const IClientRenderable *v73; // [esp-Ch] [ebp-100h]
  studiohdr_t *v74; // [esp-4h] [ebp-F8h]
  const LightingState_t *v75; // [esp-4h] [ebp-F8h]
  _BYTE v76[12]; // [esp+0h] [ebp-F4h] BYREF
  LightcacheGetDynamic_Stats stats; // [esp+Ch] [ebp-E8h] BYREF
  LightcacheGetDynamic_Stats v78; // [esp+10h] [ebp-E4h] BYREF
  Vector vLightingOrigin; // [esp+14h] [ebp-E0h] BYREF
  LightingState_t decalLightingState; // [esp+20h] [ebp-D4h] BYREF
  LightingState_t lightingState; // [esp+7Ch] [ebp-78h] BYREF
  int v82; // [esp+D8h] [ebp-1Ch]
  int v83; // [esp+DCh] [ebp-18h]
  int v84; // [esp+E0h] [ebp-14h]
  int v85; // [esp+E4h] [ebp-10h]
  _BYTE *v86; // [esp+E8h] [ebp-Ch]
  MaterialLightingState_t *hInstance; // [esp+ECh] [ebp-8h]
  CModelRender *v88; // [esp+F0h] [ebp-4h]

  v88 = this;
  if ( mat_fullbright.m_pParent != nullptr && mat_fullbright.m_pParent->m_Value.m_nValue == 1 )
  {
    v9 = pLightingState;
    v10 = nCount;
    CModelRender::SetFullbrightLightingState(this, nCount, pState: (MaterialLightingState_t *)pLightingState);
    CModelRender::SetFullbrightLightingState(this, nCount: v10, pState: pDecalState);
    memset(dst: (unsigned __int8 *)pColorMeshHandles, value: 0, count: 4 * v10);
    if ( v10 > 0 )
    {
      v11 = (ITexture *)((char *)pDecalState - (char *)pLightingState);
      v12 = ppEnvCubemapTexture;
      pColorMeshHandles = (memhandle_t__ **)&pDecalState->m_vecLightingOrigin;
      v13 = (float *)&pQuery[2];
      v14 = (float *)&v9[20];
      pQuery = (ITexture *)((char *)pDecalState - (char *)pLightingState);
      pLightingState = (IClientRenderable *)((char *)ppStaticLighting - (char *)ppEnvCubemapTexture);
      pDecalState = (MaterialLightingState_t *)nCount;
      while ( 1 )
      {
        v15 = (float *)pColorMeshHandles;
        *(v14 - 2) = *(v13 - 2);
        *(v14 - 1) = *(v13 - 1);
        *v14 = *v13;
        *v15 = *(v13 - 2);
        v15[1] = *(v13 - 1);
        *(float *)((char *)v14 + (_DWORD)v11) = *v13;
        *(IClientRenderable_vtbl **)((char *)&pLightingState->__vftable + (_DWORD)v12) = nullptr;
        v16 = *((unsigned __int16 *)v13 + 2);
        if ( (_WORD)v16 == 0xFFFF )
          goto LABEL_11;
        v17 = &v88->m_ModelInstances.m_Memory.m_pMemory[v16];
        if ( (v17->m_Element.m_nFlags & 1) != 0
          && *(p_m_LightCacheHandle = (PropLightcache_t **)&v17->m_Element.m_LightCacheHandle) != nullptr
          && p_m_LightCacheHandle != nullptr )
        {
          LightcacheGetStatic(cache: *p_m_LightCacheHandle, pEnvCubemapTexture: v12, flags: 7u);
        }
        else
        {
LABEL_11:
          v73 = *((const IClientRenderable **)v13 + 2);
          memset(&lightingState, 0, 76);
          *v12 = LightcacheGetDynamic(
                   a1: 0.0,
                   origin: (const Vector *)(v13 - 2),
                   &lightingState,
                   stats: (LightcacheGetDynamic_Stats *)&nCount,
                   pRenderable: v73,
                   flags: 15,
                   bDebugModel: false);
        }
        pColorMeshHandles += 110;
        v14 += 110;
        v13 += 5;
        ++v12;
        pDecalState = (MaterialLightingState_t *)((char *)pDecalState - 1);
        if ( pDecalState == nullptr )
          break;
        v11 = pQuery;
      }
    }
    return;
  }
  v19 = nCount;
  v20 = alloca(4 * nCount);
  v21 = 0;
  v22 = v76;
  if ( nCount > 0 )
  {
    v23 = (IClientRenderable **)&pQuery[4];
    for ( nCount = (int)&pQuery[4]; ; v23 = (IClientRenderable **)nCount )
    {
      v24 = (MaterialLightingState_t *)*((unsigned __int16 *)v23 - 2);
      v25 = *v23;
      v26 = (*v23)->__vftable;
      hInstance = v24;
      v27 = v26->GetModel(this: v25);
      if ( (_WORD)hInstance == 0xFFFF || !modelinfo->UsesStaticLighting(this: modelinfo, a2: v27) )
        m_ColorMeshHandle = nullptr;
      else
        m_ColorMeshHandle = v88->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)hInstance].m_Element.m_ColorMeshHandle;
      nCount += 20;
      pColorMeshHandles[v21++] = m_ColorMeshHandle;
      if ( v21 >= v19 )
        break;
    }
  }
  v29 = pColorMeshHandles;
  v88->m_pCache->GetAndLockMultiple(this: v88->m_pCache, a2: (void **)v76, a3: v19, a4: pColorMeshHandles);
  v30 = 0;
  if ( v19 > 0 )
  {
    do
      ++v30;
    while ( v30 < v19 );
    v31 = (memhandle_t__ **)pQuery;
    ppStaticLighting = (ColorMeshInfo_t **)((char *)ppStaticLighting - v76);
    v82 = (char *)ppEnvCubemapTexture - v76;
    v32 = (char *)v29 - v76;
    hInstance = pDecalState;
    pColorMeshHandles = (memhandle_t__ **)pQuery;
    v86 = v76;
    v83 = v32;
    v84 = (char *)pLightingState - (char *)pDecalState;
    v85 = v19;
    while ( 1 )
    {
      v33 = (ITexture **)*((unsigned __int16 *)v31 + 6);
      v34 = (MaterialLightingState_t *)v31[4];
      ppEnvCubemapTexture = v33;
      pLightingState = (IClientRenderable *)v34;
      if ( (_WORD)v33 == 0xFFFF
        || (v35 = v88->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)v33].m_Element.m_DecalHandle == nullptr,
            HIBYTE(pDecalState) = 1,
            v35) )
      {
        HIBYTE(pDecalState) = 0;
      }
      v36 = 0;
      *(_DWORD *)&v22[(_DWORD)ppStaticLighting] = 0;
      if ( *(_DWORD *)&v22[v32] != 0 )
        break;
LABEL_38:
      v40 = nullptr;
      v41 = nullptr;
      pQuery = nullptr;
      if ( (_WORD)ppEnvCubemapTexture != 0xFFFF )
      {
        v40 = &v88->m_ModelInstances.m_Memory.m_pMemory[(unsigned __int16)ppEnvCubemapTexture];
        if ( (v40->m_Element.m_nFlags & 1) != 0 && v40->m_Element.m_LightCacheHandle != nullptr )
          v41 = (PropLightcache_t **)&v40->m_Element.m_LightCacheHandle;
      }
      memset(&lightingState, 0, 76);
      memset(&decalLightingState, 0, 76);
      nCount = (int)&decalLightingState;
      if ( v41 != nullptr )
      {
        if ( v36 == 0 || StaticLightCacheAffectedByDynamicLight(handle: (LightCacheHandle_t__ *)*v41) )
          Static = LightcacheGetStatic(cache: *v41, pEnvCubemapTexture: &pQuery, flags: 7u);
        else
          Static = LightcacheGetStatic(cache: *v41, pEnvCubemapTexture: &pQuery, flags: 6u);
        p_lightingState = (LightingState_t *)Static;
        if ( HIBYTE(pDecalState) != 0 )
        {
          p_m_flLightingTime = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v46 = p_m_flLightingTime[25] + p_lightingState->r_boxcolor[0].y;
          v47 = p_m_flLightingTime[26] + p_lightingState->r_boxcolor[0].z;
          decalLightingState.r_boxcolor[0].x = p_lightingState->r_boxcolor[0].x + p_m_flLightingTime[24];
          decalLightingState.r_boxcolor[0].y = v46;
          decalLightingState.r_boxcolor[0].z = v47;
          v48 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v49 = v48[28] + p_lightingState->r_boxcolor[1].y;
          v50 = v48[29] + p_lightingState->r_boxcolor[1].z;
          decalLightingState.r_boxcolor[1].x = p_lightingState->r_boxcolor[1].x + v48[27];
          decalLightingState.r_boxcolor[1].y = v49;
          decalLightingState.r_boxcolor[1].z = v50;
          v51 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v52 = v51[31] + p_lightingState->r_boxcolor[2].y;
          v53 = v51[32] + p_lightingState->r_boxcolor[2].z;
          decalLightingState.r_boxcolor[2].x = p_lightingState->r_boxcolor[2].x + v51[30];
          decalLightingState.r_boxcolor[2].y = v52;
          decalLightingState.r_boxcolor[2].z = v53;
          v54 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v55 = v54[34] + p_lightingState->r_boxcolor[3].y;
          v56 = v54[35] + p_lightingState->r_boxcolor[3].z;
          decalLightingState.r_boxcolor[3].x = p_lightingState->r_boxcolor[3].x + v54[33];
          decalLightingState.r_boxcolor[3].y = v55;
          decalLightingState.r_boxcolor[3].z = v56;
          v57 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v58 = v57[37] + p_lightingState->r_boxcolor[4].y;
          v59 = v57[38] + p_lightingState->r_boxcolor[4].z;
          decalLightingState.r_boxcolor[4].x = p_lightingState->r_boxcolor[4].x + v57[36];
          decalLightingState.r_boxcolor[4].y = v58;
          decalLightingState.r_boxcolor[4].z = v59;
          v60 = &v40->m_Element.m_pLightingState->m_flLightingTime;
          v61 = p_lightingState->r_boxcolor[5].x + v60[39];
          v62 = v60[40] + p_lightingState->r_boxcolor[5].y;
          v63 = v60[41] + p_lightingState->r_boxcolor[5].z;
          decalLightingState.r_boxcolor[5].x = v61;
          decalLightingState.r_boxcolor[5].y = v62;
          decalLightingState.r_boxcolor[5].z = v63;
          m_pLightingState = v40->m_Element.m_pLightingState;
          decalLightingState.numlights = m_pLightingState->m_AmbientLightingState.numlights;
          v65 = 0;
          if ( m_pLightingState->m_AmbientLightingState.numlights > 0 )
          {
            locallight = decalLightingState.locallight;
            v67 = m_pLightingState->m_AmbientLightingState.locallight;
            do
            {
              *locallight = *v67;
              ++v65;
              ++v67;
              ++locallight;
            }
            while ( v65 < m_pLightingState->m_AmbientLightingState.numlights );
            v22 = v86;
          }
          LightingState_t::AddAllLocalLights(
            this: &decalLightingState,
            a2: v61,
            src: p_lightingState,
            vecLightingOrigin: (const Vector *)pColorMeshHandles);
        }
        else
        {
          nCount = (int)Static;
        }
      }
      else
      {
        LODWORD(vLightingOrigin.x) = *v31;
        v68 = *((float *)v31 + 1);
        v69 = *((float *)v31 + 2);
        vLightingOrigin.y = v68;
        vLightingOrigin.z = v69;
        pQuery = LightcacheGetDynamic(
                   a1: 0.0,
                   origin: &vLightingOrigin,
                   &lightingState,
                   &stats,
                   pRenderable: pLightingState,
                   flags: v36 != 0 ? 6 : 15,
                   bDebugModel: false);
        p_lightingState = &lightingState;
        if ( HIBYTE(pDecalState) != 0 )
          LightcacheGetDynamic(
            a1: v70,
            origin: &vLightingOrigin,
            lightingState: &decalLightingState,
            stats: &v78,
            pRenderable: pLightingState,
            flags: 15,
            bDebugModel: false);
        else
          nCount = (int)&lightingState;
      }
      v71 = v88;
      v75 = p_lightingState;
      v72 = hInstance;
      CModelRender::EngineLightingToMaterialLighting(
        this: v88,
        pLightingState: (MaterialLightingState_t *)((char *)hInstance + v84),
        vecLightingOrigin: (const Vector *)pColorMeshHandles,
        srcLightingState: v75);
      if ( HIBYTE(pDecalState) != 0 )
        CModelRender::EngineLightingToMaterialLighting(
          this: v71,
          pLightingState: v72,
          vecLightingOrigin: (const Vector *)pColorMeshHandles,
          srcLightingState: (const LightingState_t *)nCount);
      pColorMeshHandles += 5;
      *(_DWORD *)&v22[v82] = pQuery;
      v22 += 4;
      v35 = v85-- == 1;
      hInstance = v72 + 1;
      v86 = v22;
      if ( v35 )
        return;
      v32 = v83;
      v31 = pColorMeshHandles;
    }
    v37 = *(_DWORD *)v22;
    HIBYTE(nCount) = 1;
    if ( v37 == 0 || (*(_BYTE *)(v37 + 20) & 2) != 0 )
    {
      v74 = (studiohdr_t *)v33;
      v38 = (LightcacheGetDynamic_Stats)pLightingState->GetIClientUnknown(this: pLightingState);
      v39 = v88;
      if ( CModelRender::UpdateStaticPropColorData(this: v88, pProp: v38, handle: v74) != 0 )
      {
        *(_DWORD *)v22 = v39->m_pCache->Get(this: v39->m_pCache, a2: *(memhandle_t__ **)&v22[v32], a3: true);
        if ( v39->m_pCache->Lock(this: v39->m_pCache, a2: *(_DWORD *)&v22[v32]) == nullptr )
        {
LABEL_34:
          *(_DWORD *)&v22[v32] = 0;
LABEL_35:
          v31 = pColorMeshHandles;
          *(_DWORD *)v22 = 0;
          goto LABEL_36;
        }
      }
      else
      {
        if ( *(_DWORD *)v22 == 0 )
          goto LABEL_34;
        if ( (*(_BYTE *)(*(_DWORD *)v22 + 20) & 2) == 0 )
          goto LABEL_35;
      }
      v31 = pColorMeshHandles;
    }
    v43 = *(_DWORD *)v22;
    if ( *(_DWORD *)v22 != 0 && (*(_BYTE *)(v43 + 20) & 1) != 0 )
    {
      *(_DWORD *)&v22[(_DWORD)ppStaticLighting] = *(_DWORD *)(v43 + 4);
      goto LABEL_37;
    }
LABEL_36:
    HIBYTE(nCount) = 0;
LABEL_37:
    v36 = HIBYTE(nCount);
    goto LABEL_38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2F40
// Name: void AddModelDebugOverlay(struct DrawModelInfo_t const __near &,struct DrawModelResults_t const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddModelDebugOverlay(const DrawModelInfo_t *info, const DrawModelResults_t *results, const Vector *origin)
{
  ModelDebugOverlayData_t *v3; // ebx

  v3 = &s_SavedModelInfo.m_Memory.m_pMemory[CUtlVector<ModelDebugOverlayData_t,CUtlMemory<ModelDebugOverlayData_t,int>>::InsertBefore(
                                              this: &s_SavedModelInfo,
                                              elem: s_SavedModelInfo.m_Size)];
  qmemcpy(v3, info, 0x1E0u);
  DrawModelResults_t::operator=(this: &v3->m_ModelResults, __that: results);
  v3->m_Origin = *origin;
}

//------------------------------------------------------------------------------
// Address: 0x100E2FA0
// Name: private: virtual void CModelRender::DrawModelExecute(class IMatRenderContext __near *,struct DrawModelState_t const __near &,struct ModelRenderInfo_t const __near &,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelRender::DrawModelExecute(
        CModelRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        IMatRenderContext *pRenderContext,
        ColorMeshInfo_t *state,
        const ModelRenderInfo_t *pInfo,
        matrix3x4_t *pBoneToWorld)
{
  const ModelRenderInfo_t *v7; // ebx
  unsigned int flags; // eax
  unsigned int v9; // ecx
  unsigned int v10; // edx
  bool v11; // al
  int v13; // eax
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  float *v15; // eax
  IClientRenderable *m_nVertOffsetInBytes; // ecx
  float *v17; // ebx
  bool (__thiscall *UsesFlexDelayedWeights)(IClientRenderable *); // edx
  void *(__thiscall *v19)(IMatRenderContext *, int); // edx
  int v20; // eax
  int m_nValue; // ecx
  CModelRender *v22; // esi
  IDataCacheSection *m_pCache; // ecx
  IDataCacheSection_vtbl *v24; // edx
  int v25; // eax
  void *v26; // esi
  int instance; // eax
  int v28; // eax
  LightCacheHandle_t__ **v29; // eax
  studiohdr_t *m_pMesh; // eax
  int skin; // edx
  int body; // eax
  IClientRenderable *v33; // edx
  int v34; // eax
  int v35; // esi
  DrawModelInfo_t info; // [esp+64h] [ebp-27Ch] BYREF
  DrawModelResults_t results; // [esp+244h] [ebp-9Ch] BYREF
  Vector entOrigin; // [esp+294h] [ebp-4Ch] BYREF
  CMatRenderData<float> rdFlexWeights; // [esp+2A0h] [ebp-40h] BYREF
  CMatRenderData<float> rdDelayedFlexWeights; // [esp+2B0h] [ebp-30h] BYREF
  float *pFlexWeights; // [esp+2C0h] [ebp-20h]
  LightCacheHandle_t__ **pLightCache; // [esp+2C4h] [ebp-1Ch]
  BOOL bVertexLit; // [esp+2C8h] [ebp-18h]
  memhandle_t__ *hColorMeshData; // [esp+2CCh] [ebp-14h]
  float *pFlexDelayedWeights; // [esp+2D0h] [ebp-10h]
  bool bSkipDecals; // [esp+2D7h] [ebp-9h]
  CModelRender *v49; // [esp+2D8h] [ebp-8h]
  bool bSkipFlexes; // [esp+2DEh] [ebp-2h]
  bool bShadowDepth; // [esp+2DFh] [ebp-1h]
  int savedregs; // [esp+2E0h] [ebp+0h] BYREF
  bool bNeedsEnvCubemap; // [esp+2E8h] [ebp+8h]
  ColorMeshInfo_t *pColorMeshes; // [esp+2ECh] [ebp+Ch]

  v7 = pInfo;
  flags = pInfo->flags;
  v49 = this;
  v9 = flags >> 30;
  v10 = flags >> 28;
  v11 = (flags & 0x400) != 0;
  bShadowDepth = v9 & 1;
  bSkipDecals = v10 & 1;
  bSkipFlexes = v11;
  if ( ((v9 & 1) == 0 || (pInfo->pModel->flags & 0x1000) == 0) && !g_bTextMode )
  {
    pFlexWeights = nullptr;
    pFlexDelayedWeights = nullptr;
    rdFlexWeights.m_pRenderContext = pRenderContext;
    memset(&rdFlexWeights.m_pRenderData, 0, 9);
    rdDelayedFlexWeights.m_pRenderContext = pRenderContext;
    memset(&rdDelayedFlexWeights.m_pRenderData, 0, 9);
    if ( !v11 )
    {
      v13 = (int)state->m_pMesh[32].IIndexBuffer::__vftable;
      if ( v13 > 0 )
      {
        LockRenderData = pRenderContext->LockRenderData;
        rdFlexWeights.m_nCount = (int)state->m_pMesh[32].IIndexBuffer::__vftable;
        v15 = (float *)LockRenderData(this: pRenderContext, a2: 4 * v13);
        m_nVertOffsetInBytes = (IClientRenderable *)state->m_nVertOffsetInBytes;
        v17 = v15;
        UsesFlexDelayedWeights = m_nVertOffsetInBytes->UsesFlexDelayedWeights;
        rdFlexWeights.m_pRenderData = v15;
        rdFlexWeights.m_bNeedsUnlock = true;
        pFlexWeights = v15;
        if ( UsesFlexDelayedWeights(this: m_nVertOffsetInBytes) )
        {
          v19 = pRenderContext->LockRenderData;
          rdDelayedFlexWeights.m_nCount = (int)state->m_pMesh[32].IIndexBuffer::__vftable;
          rdDelayedFlexWeights.m_pRenderData = (float *)v19(this: pRenderContext, a2: 4 * rdDelayedFlexWeights.m_nCount);
          rdDelayedFlexWeights.m_bNeedsUnlock = true;
          pFlexDelayedWeights = rdDelayedFlexWeights.m_pRenderData;
        }
        if ( v17 != nullptr )
          (*(void (__thiscall **)(int, matrix3x4_t *, IIndexBuffer_vtbl *, float *, float *))(*(_DWORD *)state->m_nVertOffsetInBytes
                                                                                            + 56))(
            a1: state->m_nVertOffsetInBytes,
            a2: pBoneToWorld,
            a3: state->m_pMesh[32].IIndexBuffer::__vftable,
            a4: v17,
            a5: pFlexDelayedWeights);
        v7 = pInfo;
      }
    }
    pColorMeshes = nullptr;
    hColorMeshData = nullptr;
    if ( bShadowDepth || (v7->flags & 0x200) != 0 )
    {
      info.m_bStaticLighting = false;
      g_pStudioRender->ClearAllShadows(this: g_pStudioRender);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))g_pShadowMgr->SetModelShadowState)(a1: v7->instance);
      v20 = v7->pModel->flags;
      if ( r_staticlight_streams.m_pParent != nullptr )
        m_nValue = r_staticlight_streams.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( ((int)state[1].m_pPooledVBAllocator & 8) == 0
        || ((int)state->m_pMesh[19].IVertexBuffer::__vftable & 0x10) == 0
        || (v7->pModel->flags & 0x200) != 0 && m_nValue <= 1
        || (HIBYTE(pInfo) = 1, v7->instance == 0xFFFF) )
      {
        HIBYTE(pInfo) = 0;
      }
      LOBYTE(bVertexLit) = (v20 & 4) != 0;
      if ( r_showenvcubemap.m_pParent != nullptr && r_showenvcubemap.m_pParent->m_Value.m_nValue != 0
        || (bNeedsEnvCubemap = false, (v20 & 0x400) != 0) )
      {
        bNeedsEnvCubemap = true;
      }
      if ( r_drawmodellightorigin.m_pParent != nullptr && r_drawmodellightorigin.m_pParent->m_Value.m_nValue != 0 )
      {
        v22 = v49;
        CModelRender::DebugDrawLightingOrigin(this: v49, (const DrawModelState_t *)state, pInfo: v7);
      }
      else
      {
        v22 = v49;
      }
      if ( HIBYTE(pInfo) != 0 )
      {
        m_pCache = v22->m_pCache;
        v24 = m_pCache->__vftable;
        hColorMeshData = v22->m_ModelInstances.m_Memory.m_pMemory[v7->instance].m_Element.m_ColorMeshHandle;
        v25 = (int)v24->Get(this: m_pCache, a2: hColorMeshData, a3: true);
        v26 = (void *)v25;
        if ( v25 == 0 || (*(_BYTE *)(v25 + 20) & 2) != 0 )
        {
          if ( ((unsigned __int8 (__stdcall *)(_DWORD))v49->RecomputeStaticLighting)(a1: v7->instance) != 0 )
          {
            v26 = v49->m_pCache->Get(this: v49->m_pCache, a2: hColorMeshData, a3: 1);
          }
          else if ( v26 == nullptr || (*((_BYTE *)v26 + 20) & 2) == 0 )
          {
LABEL_64:
            CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: (CMatRenderData<matrix3x4a_t> *)&rdDelayedFlexWeights);
            CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: (CMatRenderData<matrix3x4a_t> *)&rdFlexWeights);
            return;
          }
        }
        if ( v26 != nullptr && (*((_BYTE *)v26 + 20) & 1) != 0 )
          pColorMeshes = *((ColorMeshInfo_t **)v26 + 1);
        else
          HIBYTE(pInfo) = 0;
        v22 = v49;
      }
      info.m_bStaticLighting = false;
      if ( bVertexLit || bNeedsEnvCubemap )
      {
        instance = v7->instance;
        pLightCache = nullptr;
        if ( (_WORD)instance != 0xFFFF )
        {
          v28 = (int)&v22->m_ModelInstances.m_Memory.m_pMemory[instance];
          if ( (*(_BYTE *)(v28 + 14) & 1) != 0 )
          {
            v29 = (LightCacheHandle_t__ **)(v28 + 16);
            if ( *v29 != nullptr )
              pLightCache = v29;
          }
        }
        R_ComputeLightingOrigin(
          pRenderable: (IClientRenderable *)state->m_nVertOffsetInBytes,
          pStudioHdr: (studiohdr_t *)state->m_pMesh,
          matrix: (const matrix3x4_t *)state->m_nNumVerts,
          center: &entOrigin);
        CModelRender::StudioSetupLighting(
          this: v22,
          (const DrawModelState_t *)state,
          absEntCenter: &entOrigin,
          pLightcache: pLightCache,
          bVertexLit,
          bNeedsEnvCubemap,
          bStaticLighting: (bool *)&pInfo + 3,
          drawInfo: &info,
          pInfo: v7,
          drawFlags: (__int16)state[1].m_pPooledVBAllocator);
      }
    }
    ((void (__thiscall *)(IStudioRender *, Vector *, Vector *, Vector *, Vector *, int, int))g_pStudioRender->SetViewState)(
      a1: g_pStudioRender,
      a2: &g_CurrentViewOrigin,
      a3: &g_CurrentViewRight,
      a4: &g_CurrentViewUp,
      a5: &g_CurrentViewForward,
      a6: a2,
      a7: a3);
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)&r_colormod);
    ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: LODWORD(r_blend));
    m_pMesh = (studiohdr_t *)state->m_pMesh;
    skin = v7->skin;
    info.m_pHardwareData = (studiohwdata_t *)state->m_pPooledVBAllocator;
    info.m_HitboxSet = v7->hitboxset;
    info.m_pStudioHdr = m_pMesh;
    body = v7->body;
    info.m_pColorMeshes = pColorMeshes;
    info.m_Skin = skin;
    v33 = (IClientRenderable *)state->m_nVertOffsetInBytes;
    info.m_Body = body;
    v34 = state[1].m_nVertOffsetInBytes;
    info.m_pClientEntity = (void *)v33;
    info.m_Lod = v34;
    if ( bShadowDepth )
      info.m_Decals = nullptr;
    else
      info.m_Decals = (StudioDecalHandle_t__ *)state[1].m_pMesh;
    if ( r_drawmodelstatsoverlay.m_pParent != nullptr )
      v35 = r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue;
    else
      v35 = 0;
    results.m_RenderTime.m_Duration.m_Int64 = 0;
    results.m_Materials.m_Size = 0;
    results.m_Materials.m_pElements = (IMaterial **)&results.m_Materials;
    ((void (__thiscall *)(IStudioRender *, DrawModelResults_t *, DrawModelInfo_t *, matrix3x4_t *, float *, float *))g_pStudioRender->DrawModel)(
      a1: g_pStudioRender,
      a2: &results,
      a3: &info,
      a4: pBoneToWorld,
      a5: pFlexWeights,
      a6: pFlexDelayedWeights);
    info.m_Lod = results.m_nLODUsed;
    if ( v35 != 0 && !bShadowDepth )
    {
      if ( v35 == 2 )
        AddModelDebugOverlay(&info, &results, origin: &v7->origin);
      else
        DrawModelDebugOverlay(a1: (int)&savedregs, &info, &results, origin: &v7->origin, r: 1.0, g: 1.0, b: 1.0);
    }
    if ( pColorMeshes != nullptr )
      CModelRender::ProtectColorDataIfQueued(this: v49, hColorMesh: hColorMeshData);
    results.m_Materials.m_Size = 0;
    results.m_Materials.m_pElements = (IMaterial **)&results.m_Materials;
    goto LABEL_64;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3460
// Name: public: virtual int CModelRender::DrawStaticPropArrayFast(struct StaticPropRenderInfo_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRender::DrawStaticPropArrayFast(
        CModelRender *this,
        StaticPropRenderInfo_t *pProps,
        int count,
        int bShadowDepth)
{
  void (*BeginLock)(void); // edx
  IMatRenderContext *v5; // eax
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int m_nValue; // eax
  const model_t **p_pModel; // ebx
  int v9; // eax
  rmodel_t *v10; // ecx
  const model_t *v11; // edx
  __int16 v12; // cx
  unsigned int v13; // eax
  const model_t *v14; // edx
  unsigned int v15; // esi
  int v16; // eax
  vgui::RichText::TFormatStream *v17; // eax
  int v18; // esi
  const model_t *pModel; // edi
  unsigned int flags; // ebx
  int studio; // edx
  studiohdr_t *v22; // eax
  studiohwdata_t *(__thiscall *GetHardwareData)(IMDLCache *, unsigned __int16); // edx
  __int16 v24; // cx
  int v25; // eax
  bool v26; // al
  char v27; // bl
  int v28; // esi
  int v29; // edi
  IMatRenderContext *v30; // ebx
  float *p_flFadeSustain; // esi
  double v32; // st7
  rmodel_t *v33; // edi
  float v34; // xmm0_4
  __int16 LODForMetric; // ax
  studiohwdata_t *pStudioHWData; // edi
  float maxArea; // xmm0_4
  float *p_maxArea; // eax
  bool v39; // zf
  _WORD *v40; // edx
  unsigned int i; // ebx
  rmodel_t *v42; // ecx
  int lodCount; // eax
  int m_RootLOD; // ecx
  int v45; // eax
  vgui::RichText::TFormatStream *v46; // ebx
  char v47; // al
  LightingState_t *v48; // edi
  int v49; // eax
  int v50; // edi
  unsigned int v51; // esi
  LightingState_t *v52; // ecx
  int v53; // eax
  LightingState_t *v54; // eax
  int v55; // eax
  int v56; // esi
  IMemAlloc_vtbl *v57; // edx
  S3RGBA *v58; // ecx
  int v59; // eax
  rmodel_t **v60; // ecx
  signed int v61; // eax
  unsigned int v62; // esi
  unsigned int v63; // esi
  wchar_t *v64; // ecx
  int v65; // eax
  wchar_t *v66; // ecx
  IDataCacheSection *m_pCache; // ecx
  IDataCacheSection_vtbl *v68; // edx
  int v69; // eax
  _BYTE *v70; // esi
  LightcacheGetDynamic_Stats v71; // eax
  int v72; // eax
  void (__thiscall ***v73)(_DWORD, _DWORD *); // esi
  _DWORD *v74; // eax
  CModelRender *v75; // ecx
  ITexture *v76; // edx
  int iOriginalAlpha_low; // eax
  LightCacheHandle_t__ **p_m_LightCacheHandle; // esi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v79; // edx
  int v80; // eax
  const LightingState_t *Static; // esi
  UtlLinkedListElem_t<CModelRender::ModelInstance_t,unsigned short> *v82; // eax
  float *p_m_flLightingTime; // ecx
  float v84; // xmm1_4
  float v85; // xmm2_4
  float *v86; // ecx
  float v87; // xmm1_4
  float v88; // xmm2_4
  float *v89; // ecx
  float v90; // xmm1_4
  float v91; // xmm2_4
  float *v92; // ecx
  float v93; // xmm1_4
  float v94; // xmm2_4
  float *v95; // ecx
  float v96; // xmm1_4
  float v97; // xmm2_4
  float *v98; // ecx
  float v99; // xmm1_4
  float v100; // xmm2_4
  float v101; // xmm0_4
  CModelRender::ModelInstanceLightingState_t *m_pLightingState; // eax
  bool v103; // cc
  int v104; // edx
  dworldlight_t **locallight; // ecx
  float flFadeLength; // eax
  const IClientRenderable *pixelsIndent; // edx
  float v108; // xmm0_4
  int v109; // eax
  float *p_z; // ecx
  float v111; // xmm0_4
  float v112; // xmm0_4
  int v113; // eax
  int v114; // edx
  unsigned int v115; // edi
  LightingState_t *v116; // ecx
  int v117; // eax
  LightingState_t *v118; // edi
  int v119; // eax
  int v120; // ebx
  unsigned int v121; // esi
  unsigned __int8 *v122; // edi
  wchar_t *v123; // ecx
  int v124; // eax
  wchar_t *v125; // eax
  IMatRenderContext *v126; // esi
  int v127; // edx
  __int16 *v128; // ebx
  int v129; // eax
  rmodel_t *v130; // ecx
  int v131; // eax
  int v132; // ecx
  int v133; // esi
  unsigned __int8 *v134; // edi
  int v135; // eax
  int v136; // eax
  int v137; // eax
  vgui::RichText::TFormatStream *v138; // esi
  float flFadeStartTime; // eax
  LightingState_t *v140; // edi
  signed int v141; // edi
  vgui::RichText::TFormatStream *v142; // esi
  rmodel_t *v143; // ebx
  int m; // ebx
  LightingState_t *v145; // edi
  vgui::RichText::TFormatStream *v146; // esi
  IMatRenderContext *v147; // esi
  LightingState_t *v148; // eax
  S3RGBA *v149; // eax
  wchar_t *v150; // eax
  wchar_t *v151; // eax
  rmodel_t *v152; // eax
  LightCacheHandle_t__ *v154; // [esp+28h] [ebp-8C3Ch]
  studiohdr_t *lodMetrica; // [esp+30h] [ebp-8C34h]
  unsigned int lodMetric; // [esp+30h] [ebp-8C34h]
  _DWORD dst[1216]; // [esp+40h] [ebp-8C24h] BYREF
  CUtlMemoryFixedGrowable<LightingState_t,256,int> v158; // [esp+1340h] [ebp-7924h] BYREF
  int v159; // [esp+6F50h] [ebp-1D14h]
  LightingState_t *v160; // [esp+6F54h] [ebp-1D10h]
  LightDesc_t pLightDescs; // [esp+6F58h] [ebp-1D0Ch] BYREF
  CUtlVector<rmodel_t,CUtlMemoryFixedGrowable<rmodel_t,256,int> > v162; // [esp+70B8h] [ebp-1BACh] BYREF
  _BYTE v163[256]; // [esp+84D0h] [ebp-794h] BYREF
  CUtlMemory<wchar_t,int> v164; // [esp+85D0h] [ebp-694h] BYREF
  int v165; // [esp+85DCh] [ebp-688h]
  _BYTE v166[512]; // [esp+85E0h] [ebp-684h] BYREF
  int v167; // [esp+87E0h] [ebp-484h]
  wchar_t *v168; // [esp+87E4h] [ebp-480h]
  studiohdr_t *pStudioHdr; // [esp+87E8h] [ebp-47Ch] BYREF
  studiohwdata_t *v170; // [esp+87ECh] [ebp-478h]
  StudioDecalHandle_t__ *m_DecalHandle; // [esp+87F0h] [ebp-474h]
  int iOriginalAlpha_high; // [esp+87F4h] [ebp-470h]
  int v173; // [esp+87F8h] [ebp-46Ch]
  int v174; // [esp+87FCh] [ebp-468h]
  int v175; // [esp+8800h] [ebp-464h]
  int flFadeSustain_high; // [esp+8804h] [ebp-460h]
  int v177; // [esp+8808h] [ebp-45Ch]
  char v178; // [esp+880Ch] [ebp-458h]
  _DWORD v179[110]; // [esp+8810h] [ebp-454h] BYREF
  CUtlMemory<S3RGBA,int> src; // [esp+89C8h] [ebp-29Ch] BYREF
  int v181; // [esp+89D4h] [ebp-290h]
  _BYTE v182[256]; // [esp+89D8h] [ebp-28Ch] BYREF
  int v183; // [esp+8AD8h] [ebp-18Ch]
  S3RGBA *v184; // [esp+8ADCh] [ebp-188h]
  LightingState_t lightingState; // [esp+8AE0h] [ebp-184h] BYREF
  CUtlMemory<wchar_t,int> v186; // [esp+8B3Ch] [ebp-128h] BYREF
  int v187; // [esp+8B48h] [ebp-11Ch]
  _BYTE v188[128]; // [esp+8B4Ch] [ebp-118h] BYREF
  signed int v189; // [esp+8BCCh] [ebp-98h]
  wchar_t *v190; // [esp+8BD0h] [ebp-94h]
  LightcacheGetDynamic_Stats stats; // [esp+8BD4h] [ebp-90h] BYREF
  _DWORD v192[3]; // [esp+8BD8h] [ebp-8Ch] BYREF
  IMDLCache *v193; // [esp+8BE4h] [ebp-80h]
  rmodel_t *context; // [esp+8BE8h] [ebp-7Ch] BYREF
  LightcacheGetDynamic_Stats v195; // [esp+8BECh] [ebp-78h] BYREF
  _DWORD v196[8]; // [esp+8BF0h] [ebp-74h] BYREF
  int v197; // [esp+8C10h] [ebp-54h]
  _DWORD v198[3]; // [esp+8C14h] [ebp-50h] BYREF
  int v199; // [esp+8C20h] [ebp-44h]
  int v200; // [esp+8C24h] [ebp-40h]
  CUtlMemory<vgui::RichText::TFormatStream,int> v201; // [esp+8C28h] [ebp-3Ch] BYREF
  unsigned int num; // [esp+8C34h] [ebp-30h]
  vgui::RichText::TFormatStream *m_pMemory; // [esp+8C38h] [ebp-2Ch]
  int v204; // [esp+8C3Ch] [ebp-28h]
  char v205; // [esp+8C40h] [ebp-24h]
  unsigned int counta; // [esp+8C44h] [ebp-20h]
  rmodel_t *v207; // [esp+8C48h] [ebp-1Ch]
  bool v208; // [esp+8C4Fh] [ebp-15h]
  CModelRender *v209; // [esp+8C50h] [ebp-14h]
  char v210; // [esp+8C57h] [ebp-Dh]
  int v211; // [esp+8C58h] [ebp-Ch]
  IMatRenderContext *v212; // [esp+8C5Ch] [ebp-8h]
  ITexture *pEnvCubemapTexture; // [esp+8C60h] [ebp-4h] BYREF
  int v214; // [esp+8C6Ch] [ebp+8h]
  int v215; // [esp+8C6Ch] [ebp+8h]
  int j; // [esp+8C6Ch] [ebp+8h]
  int v217; // [esp+8C6Ch] [ebp+8h]
  unsigned int k; // [esp+8C6Ch] [ebp+8h]
  rmodel_t *v219; // [esp+8C6Ch] [ebp+8h]
  rmodel_t *v220; // [esp+8C6Ch] [ebp+8h]
  bool v221; // [esp+8C6Fh] [ebp+Bh]

  v209 = this;
  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  v193 = g_pMDLCache;
  BeginLock();
  v5 = materials->GetRenderContext(this: materials);
  v212 = v5;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v201.m_nAllocationCount = 1024;
  v201.m_nGrowSize = 0;
  v162.m_Memory.m_pMemory = v162.m_Memory.m_pFixedMemory;
  v162.m_pElements = v162.m_Memory.m_pFixedMemory;
  v164.m_pMemory = (wchar_t *)v166;
  v168 = (wchar_t *)v166;
  v201.m_pMemory = (vgui::RichText::TFormatStream *)Alloc_2(this: _g_pMemAlloc, a2: 0x8000u);
  m_pMemory = v201.m_pMemory;
  v186.m_pMemory = (wchar_t *)v188;
  v190 = (wchar_t *)v188;
  v162.m_Memory.m_nGrowSize = -1;
  v164.m_nGrowSize = -1;
  v186.m_nGrowSize = -1;
  src.m_nGrowSize = -1;
  v186.m_nAllocationCount = 64;
  src.m_nAllocationCount = 64;
  num = 0;
  v204 = 0;
  v205 = 0;
  v162.m_Memory.m_nAllocationCount = 256;
  v162.m_Memory.m_nMallocGrowSize = 0;
  v162.m_Size = 0;
  v164.m_nAllocationCount = 256;
  v165 = 0;
  v167 = 0;
  v187 = 0;
  v189 = 0;
  src.m_pMemory = (S3RGBA *)v182;
  v181 = 0;
  v183 = 0;
  v184 = (S3RGBA *)v182;
  CUtlMemoryFixedGrowable<LightingState_t,256,int>::CUtlMemoryFixedGrowable<LightingState_t,256,int>(
    this: &v158,
    nGrowSize: 0,
    nInitSize: 256);
  v159 = 0;
  v160 = v158.m_pMemory;
  if ( r_showenvcubemap.m_pParent != nullptr )
    m_nValue = r_showenvcubemap.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v208 = m_nValue != 0;
  v197 = 0;
  if ( r_lod.m_pParent != nullptr )
    v211 = r_lod.m_pParent->m_Value.m_nValue;
  else
    v211 = 0;
  if ( r_staticprop_lod.m_pParent != nullptr )
  {
    if ( r_staticprop_lod.m_pParent->m_Value.m_nValue >= 0 )
      v211 = r_staticprop_lod.m_pParent->m_Value.m_nValue;
  }
  else
  {
    v211 = 0;
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "build unique model list",
    a3: 2,
    a4: "Unaccounted",
    a5: false,
    a6: 0);
  if ( count > 0 )
  {
    p_pModel = &pProps->pModel;
    v197 = count;
    do
    {
      v9 = v162.m_Size - 1;
      if ( v162.m_Size - 1 < 0 )
        goto LABEL_21;
      v10 = &v162.m_Memory.m_pMemory[v9];
      while ( v10->pModel != *p_pModel )
      {
        --v9;
        --v10;
        if ( v9 < 0 )
          goto LABEL_21;
      }
      if ( v9 < 0 )
      {
LABEL_21:
        v9 = CUtlVector<rmodel_t,CUtlMemoryFixedGrowable<rmodel_t,256,int>>::InsertBefore(
               this: &v162,
               elem: v162.m_Size);
        v162.m_Memory.m_pMemory[v9].pModel = *p_pModel;
      }
      v11 = p_pModel[1];
      v196[0] = *(p_pModel - 1);
      v12 = *((unsigned __int8 *)p_pModel + 14);
      v196[5] = (unsigned __int16)v9;
      LOWORD(v196[6]) = *((_WORD *)p_pModel + 6);
      HIWORD(v196[6]) = v12;
      v196[1] = v11;
      LOBYTE(v11) = *((_BYTE *)p_pModel + 15);
      v13 = num;
      LOWORD(v196[7]) = -1;
      BYTE2(v196[7]) = (_BYTE)v11;
      v14 = p_pModel[2];
      v196[2] = 0;
      v196[3] = 0;
      v196[4] = v14;
      v205 = 1;
      v15 = num;
      if ( (int)(num + 1) > v201.m_nAllocationCount )
      {
        CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>::Grow(this: &v201, num: num - v201.m_nAllocationCount + 1);
        v13 = num;
      }
      num = v13 + 1;
      v16 = v13 - v15;
      m_pMemory = v201.m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v201.m_pMemory[v15 + 1], src: &v201.m_pMemory[v15], count: 32 * v16);
      v17 = &v201.m_pMemory[v15];
      if ( v17 != nullptr )
        qmemcpy(v17, v196, sizeof(vgui::RichText::TFormatStream));
      p_pModel += 5;
      --count;
    }
    while ( count != 0 );
  }
  count = 0;
  v214 = 0;
  if ( v162.m_Size > 0 )
  {
    v18 = 0;
    do
    {
      pModel = v162.m_Memory.m_pMemory[v18].pModel;
      flags = pModel->flags;
      studio = pModel->studio;
      v207 = &v162.m_Memory.m_pMemory[v18];
      v22 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: studio);
      v207->pStudioHdr = v22;
      GetHardwareData = g_pMDLCache->GetHardwareData;
      v207 = &v162.m_Memory.m_pMemory[v18];
      v207->pStudioHWData = (studiohwdata_t *)((int (__stdcall *)(_DWORD))GetHardwareData)(a1: pModel->studio);
      v24 = count;
      v162.m_Memory.m_pMemory[v18].maxArea = 1.0;
      v162.m_Memory.m_pMemory[v18].lodStart = v24;
      v162.m_Memory.m_pMemory[v18].lodCount = v162.m_Memory.m_pMemory[v18].pStudioHWData->m_NumLODs;
      if ( r_staticlight_streams.m_pParent != nullptr )
        v25 = r_staticlight_streams.m_pParent->m_Value.m_nValue;
      else
        v25 = 0;
      v26 = (v162.m_Memory.m_pMemory[v18].pStudioHdr->flags & 0x10) != 0 && ((flags & 0x200) == 0 || v25 > 1);
      *((_BYTE *)&v162.m_Memory.m_pMemory[v18] + 19) ^= (*((_BYTE *)&v162.m_Memory.m_pMemory[v18] + 19) ^ (4 * v26)) & 4;
      *((_BYTE *)&v162.m_Memory.m_pMemory[v18] + 19) ^= (*((_BYTE *)&v162.m_Memory.m_pMemory[v18] + 19)
                                                       ^ (flags >> 2))
                                                      & 1;
      v27 = *((_BYTE *)&v162.m_Memory.m_pMemory[v18++] + 19) ^ (2 * (flags >> 10));
      *((_BYTE *)&v162.m_Memory.m_pMemory[v18 - 1] + 19) ^= v27 & 2;
      count += v162.m_Memory.m_pMemory[v18 - 1].lodCount;
      ++v214;
    }
    while ( v214 < v162.m_Size );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v28 = v211;
  v29 = num;
  if ( v211 >= 0 )
  {
    if ( (int)num > 0 )
    {
      v40 = (_WORD *)&v201.m_pMemory->fade.flFadeSustain + 1;
      for ( i = num; i != 0; --i )
      {
        v42 = &v162.m_Memory.m_pMemory[(__int16)*(v40 - 1)];
        lodCount = v42->lodCount;
        m_RootLOD = v42->pStudioHWData->m_RootLOD;
        v45 = lodCount - 1;
        if ( v28 >= m_RootLOD )
        {
          if ( v28 <= v45 )
            LOWORD(v45) = v28;
        }
        else
        {
          LOWORD(v45) = m_RootLOD;
        }
        *v40 = v45;
        v40 += 16;
      }
    }
  }
  else if ( (int)num > 0 )
  {
    v30 = v212;
    p_flFadeSustain = &v201.m_pMemory->fade.flFadeSustain;
    pEnvCubemapTexture = (ITexture *)num;
    do
    {
      MatrixGetColumn(in: *((const matrix3x4_t **)p_flFadeSustain - 5), column: 3, out: (Vector *)&v196[5]);
      v32 = ((double (__thiscall *)(IMatRenderContext *, _DWORD *, _DWORD))v30->ComputePixelWidthOfSphere)(
              a1: v30,
              a2: &v196[5],
              a3: 0.5);
      *(float *)&v215 = v32;
      v33 = &v162.m_Memory.m_pMemory[*(__int16 *)p_flFadeSustain];
      if ( v32 == 0.0 )
        v34 = 0.0;
      else
        v34 = 100.0 / *(float *)&v215;
      count = LODWORD(v34);
      LODForMetric = studiohwdata_t::GetLODForMetric(this: v33->pStudioHWData, lodMetric: v34);
      *((_WORD *)p_flFadeSustain + 1) = LODForMetric;
      pStudioHWData = v33->pStudioHWData;
      if ( LODForMetric < pStudioHWData->m_RootLOD )
        *((_WORD *)p_flFadeSustain + 1) = pStudioHWData->m_RootLOD;
      maxArea = v162.m_Memory.m_pMemory[*(__int16 *)p_flFadeSustain].maxArea;
      p_maxArea = &v162.m_Memory.m_pMemory[*(__int16 *)p_flFadeSustain].maxArea;
      if ( maxArea <= *(float *)&v215 )
        maxArea = v32;
      p_flFadeSustain += 8;
      v39 = pEnvCubemapTexture == (ITexture *)1;
      pEnvCubemapTexture = (ITexture *)((char *)pEnvCubemapTexture - 1);
      *p_maxArea = maxArea;
    }
    while ( !v39 );
    v29 = num;
LABEL_60:
    if ( v29 > 1 )
    {
      context = v162.m_Memory.m_pMemory;
      v195 = (LightcacheGetDynamic_Stats)((char *)&count + 3);
      qsort_s(
        base: (char *)v201.m_pMemory,
        num: v29,
        width: 0x20u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<robject_t,CRobjectLess>::CompareHelper,
        &context);
    }
    v200 = (int)v30->GetCallQueue(this: v30);
    if ( (_BYTE)bShadowDepth == 0 )
    {
      v211 = 0;
      if ( (int)num > 0 )
      {
        while ( 1 )
        {
          v46 = &v201.m_pMemory[v211];
          v47 = *((_BYTE *)&v162.m_Memory.m_pMemory[SLOWORD(v46->fade.flFadeSustain)] + 19);
          if ( (v47 & 4) == 0 || (HIBYTE(bShadowDepth) = 1, LOWORD(v46->fade.iOriginalAlpha) == 0xFFFF) )
            HIBYTE(bShadowDepth) = 0;
          v210 = v47 & 1;
          if ( v208 || (HIBYTE(count) = 0, (v47 & 2) != 0) )
            HIBYTE(count) = 1;
          v48 = nullptr;
          v221 = v209->m_ModelInstances.m_Memory.m_pMemory[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_DecalHandle != nullptr;
          if ( v209->m_ModelInstances.m_Memory.m_pMemory[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_DecalHandle != nullptr )
          {
            v49 = v159;
            v50 = v159;
            if ( v159 + 1 > v158.m_nAllocationCount )
            {
              counta = v159 - v158.m_nAllocationCount + 1;
              if ( v158.m_nGrowSize < 0 )
              {
                v158.m_nGrowSize = v158.m_nMallocGrowSize;
                if ( v158.m_nAllocationCount != 0 )
                {
                  v51 = 92 * v158.m_nAllocationCount;
                  pEnvCubemapTexture = (ITexture *)_g_pMemAlloc->Alloc_2(
                                                     this: _g_pMemAlloc,
                                                     a2: 92 * v158.m_nAllocationCount);
                  memcpy(dst: (unsigned __int8 *)pEnvCubemapTexture, src: (unsigned __int8 *)v158.m_pMemory, count: v51);
                  v158.m_pMemory = (LightingState_t *)pEnvCubemapTexture;
                }
                else
                {
                  v158.m_pMemory = nullptr;
                }
              }
              CUtlMemory<SoundInfo_t,int>::Grow(this: &v158, num: counta);
              v49 = v159;
            }
            v52 = v158.m_pMemory;
            v159 = v49 + 1;
            v53 = v49 - v50;
            v160 = v158.m_pMemory;
            if ( v53 > 0 )
            {
              _V_memmove(dest: &v158.m_pMemory[v50 + 1], src: &v158.m_pMemory[v50], count: 92 * v53);
              v52 = v158.m_pMemory;
            }
            v54 = &v52[v50];
            if ( v54 != nullptr )
            {
              v54->r_boxcolor[0].x = 0.0;
              v54->r_boxcolor[1].x = 0.0;
              v54->r_boxcolor[0].y = 0.0;
              v54->r_boxcolor[0].z = 0.0;
              v54->r_boxcolor[1].y = 0.0;
              v54->r_boxcolor[1].z = 0.0;
              v54->r_boxcolor[2].x = 0.0;
              v54->r_boxcolor[2].y = 0.0;
              v54->r_boxcolor[2].z = 0.0;
              v54->r_boxcolor[3].x = 0.0;
              v54->r_boxcolor[3].y = 0.0;
              v54->r_boxcolor[3].z = 0.0;
              v54->r_boxcolor[4].x = 0.0;
              v54->r_boxcolor[4].y = 0.0;
              v54->r_boxcolor[4].z = 0.0;
              v54->r_boxcolor[5].x = 0.0;
              v54->r_boxcolor[5].y = 0.0;
              *(_QWORD *)&v54->r_boxcolor[5].z = 0;
              v52 = v158.m_pMemory;
            }
            HIWORD(v207) = v50;
            LOWORD(v207) = v211;
            v55 = v183;
            v48 = &v52[(__int16)v50];
            v56 = v183;
            if ( v183 + 1 > src.m_nAllocationCount )
            {
              v199 = v183 - src.m_nAllocationCount + 1;
              if ( src.m_nGrowSize < 0 )
              {
                src.m_nGrowSize = v181;
                if ( src.m_nAllocationCount != 0 )
                {
                  v57 = _g_pMemAlloc->__vftable;
                  counta = 4 * src.m_nAllocationCount;
                  pEnvCubemapTexture = (ITexture *)v57->Alloc_2(this: _g_pMemAlloc, a2: 4 * src.m_nAllocationCount);
                  memcpy(
                    dst: (unsigned __int8 *)pEnvCubemapTexture,
                    src: (unsigned __int8 *)src.m_pMemory,
                    count: counta);
                  src.m_pMemory = (S3RGBA *)pEnvCubemapTexture;
                }
                else
                {
                  src.m_pMemory = nullptr;
                }
              }
              CUtlMemory<INetMessage *,int>::Grow(this: &src, num: v199);
              v55 = v183;
            }
            v58 = src.m_pMemory;
            v183 = v55 + 1;
            v59 = v55 - v56;
            v184 = src.m_pMemory;
            if ( v59 > 0 )
            {
              _V_memmove(dest: &src.m_pMemory[v56 + 1], src: &src.m_pMemory[v56], count: 4 * v59);
              v58 = src.m_pMemory;
            }
            v60 = (rmodel_t **)&v58[v56];
            if ( v60 != nullptr )
              *v60 = v207;
          }
          if ( ((unsigned __int8 (__stdcall *)(_DWORD))g_pShadowMgr->ModelHasShadows)(a1: LOWORD(v46->fade.iOriginalAlpha)) != 0 )
          {
            v61 = v189;
            v62 = v189;
            counta = v189;
            if ( v189 + 1 > v186.m_nAllocationCount )
            {
              pEnvCubemapTexture = (ITexture *)(v189 - v186.m_nAllocationCount + 1);
              if ( v186.m_nGrowSize < 0 )
              {
                v186.m_nGrowSize = v187;
                if ( v186.m_nAllocationCount != 0 )
                {
                  v63 = 2 * v186.m_nAllocationCount;
                  v199 = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2 * v186.m_nAllocationCount);
                  memcpy(dst: (unsigned __int8 *)v199, src: (unsigned __int8 *)v186.m_pMemory, count: v63);
                  v62 = counta;
                  v186.m_pMemory = (wchar_t *)v199;
                }
                else
                {
                  v186.m_pMemory = nullptr;
                }
              }
              CUtlMemory<wchar_t,int>::Grow(this: &v186, num: (int)pEnvCubemapTexture);
              v61 = v189;
            }
            v64 = v186.m_pMemory;
            v189 = v61 + 1;
            v65 = v61 - v62;
            v190 = v186.m_pMemory;
            if ( v65 > 0 )
            {
              _V_memmove(dest: &v186.m_pMemory[v62 + 1], src: &v186.m_pMemory[v62], count: 2 * v65);
              v64 = v186.m_pMemory;
            }
            v66 = &v64[v62];
            if ( v66 != nullptr )
              *v66 = v211;
          }
          if ( HIBYTE(bShadowDepth) == 0 )
            goto LABEL_117;
          m_pCache = v209->m_pCache;
          v68 = m_pCache->__vftable;
          pEnvCubemapTexture = (ITexture *)v209->m_ModelInstances.m_Memory.m_pMemory[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_ColorMeshHandle;
          v69 = (int)v68->Get(this: m_pCache, a2: (memhandle_t__ *)pEnvCubemapTexture, a3: true);
          v70 = (_BYTE *)v69;
          if ( v69 != 0 && (*(_BYTE *)(v69 + 20) & 2) == 0 )
            goto LABEL_109;
          lodMetrica = (studiohdr_t *)LOWORD(v46->fade.iOriginalAlpha);
          v71 = (LightcacheGetDynamic_Stats)(**(int (__thiscall ***)(int))v46->pixelsIndent)(a1: v46->pixelsIndent);
          if ( CModelRender::UpdateStaticPropColorData(this: v209, pProp: v71, handle: lodMetrica) != 0 )
            break;
          if ( v70 != nullptr && (v70[20] & 2) != 0 )
            goto LABEL_109;
LABEL_170:
          if ( ++v211 >= (int)num )
            goto LABEL_171;
        }
        v70 = v209->m_pCache->Get(this: v209->m_pCache, a2: pEnvCubemapTexture, a3: 1);
LABEL_109:
        if ( v70 != nullptr && (v70[20] & 1) != 0 )
        {
          v72 = *((_DWORD *)v70 + 1);
          v73 = (void (__thiscall ***)(_DWORD, _DWORD *))v200;
          *(_DWORD *)&v46->textClickable = v72;
          if ( v73 != nullptr && v209->m_pCache->Lock(this: v209->m_pCache, a2: pEnvCubemapTexture) != nullptr )
          {
            v74 = MemAlloc_Alloc(nSize: 0x1Cu);
            if ( v74 != nullptr )
            {
              v75 = v209;
              v76 = pEnvCubemapTexture;
              v74[3] = 1;
              *v74 = &CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
              v74[2] = &CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
              v74[5] = v75;
              v74[4] = CLoaderMemAlloc::CrtSetReportMode;
              v74[6] = v76;
              (**v73)(a1: v73, a2: v74);
            }
            else
            {
              (**v73)(a1: v73, a2: nullptr);
            }
          }
        }
        else
        {
          HIBYTE(bShadowDepth) = 0;
        }
LABEL_117:
        if ( v210 != 0 || HIBYTE(count) != 0 )
        {
          iOriginalAlpha_low = LOWORD(v46->fade.iOriginalAlpha);
          p_m_LightCacheHandle = nullptr;
          pEnvCubemapTexture = nullptr;
          if ( (_WORD)iOriginalAlpha_low != 0xFFFF )
          {
            v79 = v209->m_ModelInstances.m_Memory.m_pMemory;
            v80 = iOriginalAlpha_low;
            if ( (v79[v80].m_Element.m_nFlags & 1) != 0 && v79[v80].m_Element.m_LightCacheHandle != nullptr )
              p_m_LightCacheHandle = &v79[v80].m_Element.m_LightCacheHandle;
          }
          memset(&lightingState, 0, 76);
          if ( p_m_LightCacheHandle != nullptr )
          {
            if ( HIBYTE(bShadowDepth) == 0 || StaticLightCacheAffectedByDynamicLight(handle: *p_m_LightCacheHandle) )
            {
              lodMetric = 7;
              v154 = *p_m_LightCacheHandle;
            }
            else
            {
              lodMetric = 6;
              v154 = *p_m_LightCacheHandle;
            }
            Static = (const LightingState_t *)LightcacheGetStatic(
                                                cache: (PropLightcache_t *)v154,
                                                &pEnvCubemapTexture,
                                                flags: lodMetric);
            if ( v221 )
            {
              v82 = v209->m_ModelInstances.m_Memory.m_pMemory;
              p_m_flLightingTime = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v84 = Static->r_boxcolor[0].y + p_m_flLightingTime[25];
              v85 = Static->r_boxcolor[0].z + p_m_flLightingTime[26];
              v48->r_boxcolor[0].x = Static->r_boxcolor[0].x + p_m_flLightingTime[24];
              v48->r_boxcolor[0].y = v84;
              v48->r_boxcolor[0].z = v85;
              v86 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v87 = Static->r_boxcolor[1].y + v86[28];
              v88 = Static->r_boxcolor[1].z + v86[29];
              v48->r_boxcolor[1].x = v86[27] + Static->r_boxcolor[1].x;
              v48->r_boxcolor[1].y = v87;
              v48->r_boxcolor[1].z = v88;
              v89 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v90 = Static->r_boxcolor[2].y + v89[31];
              v91 = Static->r_boxcolor[2].z + v89[32];
              v48->r_boxcolor[2].x = v89[30] + Static->r_boxcolor[2].x;
              v48->r_boxcolor[2].y = v90;
              v48->r_boxcolor[2].z = v91;
              v92 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v93 = Static->r_boxcolor[3].y + v92[34];
              v94 = Static->r_boxcolor[3].z + v92[35];
              v48->r_boxcolor[3].x = v92[33] + Static->r_boxcolor[3].x;
              v48->r_boxcolor[3].y = v93;
              v48->r_boxcolor[3].z = v94;
              v95 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v96 = Static->r_boxcolor[4].y + v95[37];
              v97 = Static->r_boxcolor[4].z + v95[38];
              v48->r_boxcolor[4].x = v95[36] + Static->r_boxcolor[4].x;
              v48->r_boxcolor[4].y = v96;
              v48->r_boxcolor[4].z = v97;
              v98 = &v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState->m_flLightingTime;
              v99 = Static->r_boxcolor[5].y + v98[40];
              v100 = Static->r_boxcolor[5].z + v98[41];
              v101 = v98[39] + Static->r_boxcolor[5].x;
              v48->r_boxcolor[5].x = v101;
              v48->r_boxcolor[5].y = v99;
              v48->r_boxcolor[5].z = v100;
              m_pLightingState = v82[LOWORD(v46->fade.iOriginalAlpha)].m_Element.m_pLightingState;
              v48->numlights = m_pLightingState->m_AmbientLightingState.numlights;
              v103 = m_pLightingState->m_AmbientLightingState.numlights <= 0;
              bShadowDepth = 0;
              if ( !v103 )
              {
                v104 = (char *)&m_pLightingState->m_AmbientLightingState - (char *)v48;
                locallight = v48->locallight;
                for ( j = v104; ; v104 = j )
                {
                  *locallight = *(dworldlight_t **)((char *)locallight + v104);
                  ++locallight;
                  if ( ++bShadowDepth >= m_pLightingState->m_AmbientLightingState.numlights )
                    break;
                }
              }
              LightingState_t::AddAllLocalLights(
                this: v48,
                a2: v101,
                src: Static,
                vecLightingOrigin: (const Vector *)LODWORD(v46->fade.flFadeLength));
            }
          }
          else
          {
            flFadeLength = v46->fade.flFadeLength;
            v196[5] = *(_DWORD *)LODWORD(flFadeLength);
            v196[6] = *(_DWORD *)(LODWORD(flFadeLength) + 4);
            pixelsIndent = (const IClientRenderable *)v46->pixelsIndent;
            v196[7] = *(_DWORD *)(LODWORD(flFadeLength) + 8);
            pEnvCubemapTexture = LightcacheGetDynamic(
                                   a1: 0.0,
                                   origin: (const Vector *)&v196[5],
                                   &lightingState,
                                   &stats,
                                   pRenderable: pixelsIndent,
                                   flags: HIBYTE(bShadowDepth) != 0 ? 6 : 15,
                                   bDebugModel: false);
            Static = &lightingState;
            if ( v221 )
              LightcacheGetDynamic(
                a1: v108,
                origin: (const Vector *)&v196[5],
                lightingState: v48,
                stats: &v195,
                pRenderable: (const IClientRenderable *)v46->pixelsIndent,
                flags: 15,
                bDebugModel: false);
          }
          if ( HIBYTE(count) != 0 && pEnvCubemapTexture != nullptr )
            LODWORD(v46->fade.flFadeStartTime) = pEnvCubemapTexture;
          if ( v210 != 0 )
          {
            if ( Static->numlights == 0 )
            {
              v109 = 0;
              p_z = &Static->r_boxcolor[0].z;
              while ( 1 )
              {
                v111 = *(p_z - 2);
                if ( v111 <= -0.000099999997 )
                  break;
                if ( v111 >= 0.000099999997 )
                  break;
                v112 = *(p_z - 1);
                if ( v112 <= -0.000099999997
                  || v112 >= 0.000099999997
                  || *p_z <= -0.000099999997
                  || *p_z >= 0.000099999997 )
                {
                  break;
                }
                ++v109;
                p_z += 3;
                if ( v109 >= 6 )
                  goto LABEL_170;
              }
            }
            v113 = v159;
            v114 = v159;
            bShadowDepth = v159;
            if ( v159 + 1 > v158.m_nAllocationCount )
            {
              v217 = v159 - v158.m_nAllocationCount + 1;
              if ( v158.m_nGrowSize < 0 )
              {
                v158.m_nGrowSize = v158.m_nMallocGrowSize;
                if ( v158.m_nAllocationCount != 0 )
                {
                  v115 = 92 * v158.m_nAllocationCount;
                  count = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 92 * v158.m_nAllocationCount);
                  memcpy(dst: (unsigned __int8 *)count, src: (unsigned __int8 *)v158.m_pMemory, count: v115);
                  v158.m_pMemory = (LightingState_t *)count;
                }
                else
                {
                  v158.m_pMemory = nullptr;
                }
              }
              CUtlMemory<SoundInfo_t,int>::Grow(this: &v158, num: v217);
              v113 = v159;
              v114 = bShadowDepth;
            }
            v116 = v158.m_pMemory;
            v159 = v113 + 1;
            v117 = v113 - v114;
            v160 = v158.m_pMemory;
            if ( v117 > 0 )
            {
              _V_memmove(dest: &v158.m_pMemory[bShadowDepth + 1], src: &v158.m_pMemory[bShadowDepth], count: 92 * v117);
              v116 = v158.m_pMemory;
              v114 = bShadowDepth;
            }
            v118 = &v116[v114];
            if ( v118 != nullptr )
              qmemcpy(v118, Static, sizeof(LightingState_t));
            LOWORD(v46->textStreamIndex) = v114;
            v119 = v167;
            v120 = v167;
            if ( v167 + 1 > v164.m_nAllocationCount )
            {
              bShadowDepth = v167 - v164.m_nAllocationCount + 1;
              if ( v164.m_nGrowSize < 0 )
              {
                v164.m_nGrowSize = v165;
                if ( v164.m_nAllocationCount != 0 )
                {
                  v121 = 2 * v164.m_nAllocationCount;
                  v122 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2 * v164.m_nAllocationCount);
                  memcpy(dst: v122, src: (unsigned __int8 *)v164.m_pMemory, count: v121);
                  v164.m_pMemory = (wchar_t *)v122;
                }
                else
                {
                  v164.m_pMemory = nullptr;
                }
              }
              CUtlMemory<wchar_t,int>::Grow(this: &v164, num: bShadowDepth);
              v119 = v167;
            }
            v123 = v164.m_pMemory;
            v167 = v119 + 1;
            v124 = v119 - v120;
            v168 = v164.m_pMemory;
            if ( v124 > 0 )
            {
              _V_memmove(dest: &v164.m_pMemory[v120 + 1], src: &v164.m_pMemory[v120], count: 2 * v124);
              v123 = v164.m_pMemory;
            }
            v125 = &v123[v120];
            if ( v125 != nullptr )
              *v125 = v211;
          }
        }
        goto LABEL_170;
      }
    }
LABEL_171:
    v192[2] = 1065353216;
    v192[1] = 1065353216;
    v192[0] = 1065353216;
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)v192);
    ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: 1.0);
    g_pStudioRender->SetViewState(
      this: g_pStudioRender,
      a2: &g_CurrentViewOrigin,
      a3: &g_CurrentViewRight,
      a4: &g_CurrentViewUp,
      a5: &g_CurrentViewForward);
    v126 = v212;
    v212->MatrixMode(this: v212, a2: MATERIAL_MODEL);
    v126->PushMatrix(this: v126);
    v126->LoadIdentity(this: v126);
    g_pStudioRender->ClearAllShadows(this: g_pStudioRender);
    v126->DisableAllLocalLights(this: v126);
    memset(v179, 0, 72);
    g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)v179);
    v179[21] = 0;
    v178 = 0;
    m_DecalHandle = nullptr;
    v173 = 0;
    v174 = 0;
    v196[5] = v126->LockRenderData(this: v126, a2: 3072);
    v127 = 0;
    count = -1;
    bShadowDepth = 0;
    flFadeSustain_high = 0;
    if ( (int)num > 0 )
    {
      v128 = (__int16 *)&v201.m_pMemory->fade.iOriginalAlpha + 1;
      for ( k = num; k != 0; --k )
      {
        if ( v128[1] < 0 )
        {
          v129 = *(v128 - 3);
          v130 = &v162.m_Memory.m_pMemory[v129];
          v200 = (int)v130;
          if ( count != v129 || iOriginalAlpha_high != *v128 || *(v128 - 2) != flFadeSustain_high || v127 >= 64 )
          {
            if ( v127 > 0 )
            {
              g_pStudioRender->DrawModelArrayStaticProp(
                this: g_pStudioRender,
                a2: (const DrawModelInfo_t *)&pStudioHdr,
                a3: v127,
                a4: (const MeshInstanceData_t *)dst,
                a5: (ColorMeshInfo_t **)v163);
              if ( v196[5] != 0 )
                v126->UnlockRenderData(this: v126, a2: (void *)v196[5]);
              v131 = (int)v126->LockRenderData(this: v126, a2: 3072);
              v130 = (rmodel_t *)v200;
              v196[5] = v131;
            }
            pStudioHdr = v130->pStudioHdr;
            v170 = v130->pStudioHWData;
            iOriginalAlpha_high = *v128;
            v175 = *(_DWORD *)(v128 - 11);
            flFadeSustain_high = *(v128 - 2);
            v132 = *(v128 - 3);
            bShadowDepth = 0;
            count = v132;
          }
          v133 = bShadowDepth;
          v134 = (unsigned __int8 *)&dst[19 * bShadowDepth];
          memset(dst: v134, value: 0, count: 0x4Cu);
          v135 = v196[5] + 48 * v133;
          *((_DWORD *)v134 + 2) = 1;
          *((_DWORD *)v134 + 4) = v135;
          *((_DWORD *)v134 + 5) = *(_DWORD *)(v128 - 7);
          (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(v128 - 11) + 44))(
            a1: *(_DWORD *)(v128 - 11),
            a2: (_DWORD *)v134 + 14);
          v136 = bShadowDepth;
          *((float *)v134 + 17) = (float)*((unsigned __int8 *)v128 + 4) * 0.0039215689;
          qmemcpy(*((void **)v134 + 4), *(const void **)(v128 - 13), 0x30u);
          v126 = v212;
          ++v136;
          *((_DWORD *)&v162.m_pElements + v136) = *(_DWORD *)(v128 - 9);
          bShadowDepth = v136;
          v127 = v136;
        }
        v128 += 16;
      }
      if ( v127 > 0 )
        g_pStudioRender->DrawModelArrayStaticProp(
          this: g_pStudioRender,
          a2: (const DrawModelInfo_t *)&pStudioHdr,
          a3: v127,
          a4: (const MeshInstanceData_t *)dst,
          a5: (ColorMeshInfo_t **)v163);
    }
    if ( v196[5] != 0 )
      v126->UnlockRenderData(this: v126, a2: (void *)v196[5]);
    count = 0;
    v198[0] = 1065353216;
    v198[1] = 1065353216;
    v198[2] = 1065353216;
    if ( v167 != 0 )
    {
      v137 = 0;
      for ( bShadowDepth = 0; v137 < v167; bShadowDepth = v137 )
      {
        v138 = &v201.m_pMemory[(__int16)v164.m_pMemory[v137]];
        flFadeStartTime = v138->fade.flFadeStartTime;
        v219 = &v162.m_Memory.m_pMemory[SLOWORD(v138->fade.flFadeSustain)];
        if ( flFadeStartTime != 0.0 )
          ((void (__thiscall *)(IMatRenderContext *, float))v212->BindLocalCubemap)(
            a1: v212,
            a2: COERCE_FLOAT(LODWORD(flFadeStartTime)));
        v140 = &v158.m_pMemory[SLOWORD(v138->textStreamIndex)];
        g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)v140);
        ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))v212->SetLightingOrigin)(
          a1: v212,
          a2: *(_DWORD *)LODWORD(v138->fade.flFadeLength),
          a3: *(_DWORD *)(LODWORD(v138->fade.flFadeLength) + 4),
          a4: *(_DWORD *)(LODWORD(v138->fade.flFadeLength) + 8));
        R_SetNonAmbientLightingState(
          numLights: v140->numlights,
          locallight: v140->locallight,
          pNumLightDescs: &count,
          &pLightDescs,
          bUpdateStudioRenderLights: true);
        (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v138->pixelsIndent + 44))(a1: v138->pixelsIndent, a2: v198);
        g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)v198);
        pStudioHdr = v219->pStudioHdr;
        v170 = v219->pStudioHWData;
        iOriginalAlpha_high = SHIWORD(v138->fade.iOriginalAlpha);
        v175 = v138->pixelsIndent;
        flFadeSustain_high = SHIWORD(v138->fade.flFadeSustain);
        v177 = *(_DWORD *)&v138->textClickable;
        g_pStudioRender->DrawModelStaticProp(
          this: g_pStudioRender,
          a2: (const DrawModelInfo_t *)&pStudioHdr,
          a3: *(const matrix3x4_t **)&v138->color,
          a4: 8);
        v137 = bShadowDepth + 1;
      }
    }
    v141 = 0;
    if ( !g_pShadowMgr->SinglePassFlashlightModeEnabled(this: g_pShadowMgr) && v189 != 0 )
    {
      if ( v189 > 0 )
      {
        do
        {
          v142 = &v201.m_pMemory[(__int16)v186.m_pMemory[v141]];
          v143 = &v162.m_Memory.m_pMemory[SLOWORD(v142->fade.flFadeSustain)];
          ((void (__stdcall *)(_DWORD))g_pShadowMgr->SetModelShadowState)(a1: LOWORD(v142->fade.iOriginalAlpha));
          (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v142->pixelsIndent + 44))(a1: v142->pixelsIndent, a2: v198);
          g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)v198);
          pStudioHdr = v143->pStudioHdr;
          v170 = v143->pStudioHWData;
          iOriginalAlpha_high = SHIWORD(v142->fade.iOriginalAlpha);
          v175 = v142->pixelsIndent;
          flFadeSustain_high = SHIWORD(v142->fade.flFadeSustain);
          v177 = *(_DWORD *)&v142->textClickable;
          g_pStudioRender->DrawStaticPropShadows(
            this: g_pStudioRender,
            a2: (const DrawModelInfo_t *)&pStudioHdr,
            a3: *(const matrix3x4_t **)&v142->color,
            a4: 0);
          ++v141;
        }
        while ( v141 < v189 );
      }
      g_pStudioRender->ClearAllShadows(this: g_pStudioRender);
    }
    for ( m = 0; m < v183; ++m )
    {
      v146 = &v201.m_pMemory[*(__int16 *)&src.m_pMemory[m].b];
      v145 = &v158.m_pMemory[*(__int16 *)&src.m_pMemory[m].r];
      v220 = &v162.m_Memory.m_pMemory[SLOWORD(v146->fade.flFadeSustain)];
      g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: (const Vector *)v145);
      ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))v212->SetLightingOrigin)(
        a1: v212,
        a2: *(_DWORD *)LODWORD(v146->fade.flFadeLength),
        a3: *(_DWORD *)(LODWORD(v146->fade.flFadeLength) + 4),
        a4: *(_DWORD *)(LODWORD(v146->fade.flFadeLength) + 8));
      R_SetNonAmbientLightingState(
        numLights: v145->numlights,
        locallight: v145->locallight,
        pNumLightDescs: &count,
        &pLightDescs,
        bUpdateStudioRenderLights: true);
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v146->pixelsIndent + 44))(a1: v146->pixelsIndent, a2: v198);
      g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)v198);
      pStudioHdr = v220->pStudioHdr;
      v170 = v220->pStudioHWData;
      m_DecalHandle = v209->m_ModelInstances.m_Memory.m_pMemory[LOWORD(v146->fade.iOriginalAlpha)].m_Element.m_DecalHandle;
      iOriginalAlpha_high = SHIWORD(v146->fade.iOriginalAlpha);
      v175 = v146->pixelsIndent;
      flFadeSustain_high = SHIWORD(v146->fade.flFadeSustain);
      v177 = *(_DWORD *)&v146->textClickable;
      g_pStudioRender->DrawStaticPropDecals(
        this: g_pStudioRender,
        a2: (const DrawModelInfo_t *)&pStudioHdr,
        a3: *(const matrix3x4_t **)&v146->color);
    }
    v147 = v212;
    v212->MatrixMode(this: v212, a2: MATERIAL_MODEL);
    v147->PopMatrix(this: v147);
    v148 = v158.m_pMemory;
    v159 = 0;
    if ( v158.m_nGrowSize >= 0 )
    {
      if ( v158.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v158.m_pMemory);
        v148 = nullptr;
        v158.m_pMemory = nullptr;
      }
      v158.m_nAllocationCount = 0;
    }
    v160 = v148;
    if ( v158.m_nGrowSize >= 0 )
    {
      if ( v148 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v148);
        v158.m_pMemory = nullptr;
      }
      v158.m_nAllocationCount = 0;
    }
    v149 = src.m_pMemory;
    v183 = 0;
    if ( src.m_nGrowSize >= 0 )
    {
      if ( src.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_pMemory);
        v149 = nullptr;
        src.m_pMemory = nullptr;
      }
      src.m_nAllocationCount = 0;
    }
    v184 = v149;
    if ( src.m_nGrowSize >= 0 )
    {
      if ( v149 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v149);
        src.m_pMemory = nullptr;
      }
      src.m_nAllocationCount = 0;
    }
    v150 = v186.m_pMemory;
    v189 = 0;
    if ( v186.m_nGrowSize >= 0 )
    {
      if ( v186.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v186.m_pMemory);
        v150 = nullptr;
        v186.m_pMemory = nullptr;
      }
      v186.m_nAllocationCount = 0;
    }
    v190 = v150;
    if ( v186.m_nGrowSize >= 0 )
    {
      if ( v150 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v150);
        v186.m_pMemory = nullptr;
      }
      v186.m_nAllocationCount = 0;
    }
    v151 = v164.m_pMemory;
    v167 = 0;
    if ( v164.m_nGrowSize >= 0 )
    {
      if ( v164.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v164.m_pMemory);
        v151 = nullptr;
        v164.m_pMemory = nullptr;
      }
      v164.m_nAllocationCount = 0;
    }
    v168 = v151;
    if ( v164.m_nGrowSize >= 0 )
    {
      if ( v151 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v151);
        v164.m_pMemory = nullptr;
      }
      v164.m_nAllocationCount = 0;
    }
    v152 = v162.m_Memory.m_pMemory;
    v162.m_Size = 0;
    if ( v162.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v162.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v162.m_Memory.m_pMemory);
        v152 = nullptr;
        v162.m_Memory.m_pMemory = nullptr;
      }
      v162.m_Memory.m_nAllocationCount = 0;
    }
    v162.m_pElements = v152;
    if ( v162.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v152 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v152);
        v162.m_Memory.m_pMemory = nullptr;
      }
      v162.m_Memory.m_nAllocationCount = 0;
    }
    if ( v201.m_nGrowSize >= 0 && v201.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v201.m_pMemory);
    v147->EndRender(this: v147);
    v147->Release(this: v147);
    v193->EndLock(this: v193);
    return v197;
  }
  v30 = v212;
  goto LABEL_60;
}

//------------------------------------------------------------------------------
// Address: 0x1019F930
// Name: void R_InitStudio(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl R_InitStudio()
{
  R_StudioInitLightingCache();
}

//------------------------------------------------------------------------------
// Address: 0x103157B0
// Name: _dynamic_initializer_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CModelRender::ModelInstanceLightingState_t::s_Allocator,
    blockSize: 236,
    numElements: 100,
    growMode: 2,
    pszAllocOwner: "CModelRender::ModelInstanceLightingState_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x103235E0
// Name: _dynamic_atexit_destructor_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CModelRender::ModelInstanceLightingState_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CModelRender::ModelInstanceLightingState_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x10323690
// Name: _CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlodbias__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlodbias__()
{
  ConVar::~ConVar(this: &r_shadowlodbias);
}

//------------------------------------------------------------------------------
// Address: 0x103236A0
// Name: _CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlod__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CModelRender::DrawModelShadowSetup_::_2_::_dynamic_atexit_destructor_for__r_shadowlod__()
{
  ConVar::~ConVar(this: &r_shadowlod);
}

} // namespace engine_xlsp
