// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/vertexlitgeneric_dx9.cpp
// Functions: 145
// ============================================================

#include "materialsystem\stdshaders\vertexlitgeneric_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x100384F0
// Name: public: void VertexLitGeneric::CShader::SetupVars(struct VertexLitGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VertexLitGeneric::CShader::SetupVars(
        VertexLitGeneric::CShader *this,
        VertexLitGeneric_DX9_Vars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nWrinkle = COMPRESS.m_Index;
  info->m_nStretch = STRETCH.m_Index;
  info->m_nBaseTextureFrame = 7;
  info->m_nBaseTextureTransform = 8;
  info->m_nAlbedo = ALBEDO_0.m_Index;
  info->m_nSelfIllumTint = SELFILLUMTINT_1.m_Index;
  info->m_nDetail = DETAIL_2.m_Index;
  info->m_nDetailFrame = DETAILFRAME_1.m_Index;
  info->m_nDetailScale = DETAILSCALE_2.m_Index;
  info->m_nEnvmap = ENVMAP_6.m_Index;
  info->m_nEnvmapFrame = ENVMAPFRAME_3.m_Index;
  info->m_nEnvmapMask = ENVMAPMASK_3.m_Index;
  info->m_nEnvmapMaskFrame = ENVMAPMASKFRAME_3.m_Index;
  info->m_nEnvmapMaskTransform = ENVMAPMASKTRANSFORM_2.m_Index;
  info->m_nEnvmapTint = ENVMAPTINT_4.m_Index;
  info->m_nBumpmap = BUMPMAP_8.m_Index;
  info->m_nNormalWrinkle = BUMPCOMPRESS.m_Index;
  info->m_nNormalStretch = BUMPSTRETCH.m_Index;
  info->m_nBumpFrame = BUMPFRAME_11.m_Index;
  info->m_nBumpTransform = BUMPTRANSFORM_5.m_Index;
  info->m_nEnvmapContrast = ENVMAPCONTRAST_3.m_Index;
  info->m_nEnvmapSaturation = ENVMAPSATURATION_3.m_Index;
  info->m_nAlphaTestReference = ALPHATESTREFERENCE_2.m_Index;
  info->m_nFlashlightNoLambert = FLASHLIGHTNOLAMBERT.m_Index;
  info->m_nLowQualityFlashlightShadows = LOWQUALITYFLASHLIGHTSHADOWS.m_Index;
  info->m_nFlashlightTexture = 9;
  info->m_nFlashlightTextureFrame = 10;
  info->m_nSelfIllumEnvMapMask_Alpha = SELFILLUM_ENVMAPMASK_ALPHA.m_Index;
  info->m_nSelfIllumFresnel = SELFILLUMFRESNEL_0.m_Index;
  info->m_nSelfIllumFresnelMinMaxExp = SELFILLUMFRESNELMINMAXEXP_0.m_Index;
  info->m_nSelfIllumMaskScale = SELFILLUMMASKSCALE.m_Index;
  info->m_nAmbientOnly = AMBIENTONLY.m_Index;
  info->m_nPhongExponent = PHONGEXPONENT_5.m_Index;
  info->m_nPhongExponentTexture = PHONGEXPONENTTEXTURE_1.m_Index;
  info->m_nPhongTint = PHONGTINT_1.m_Index;
  info->m_nPhongAlbedoTint = PHONGALBEDOTINT_1.m_Index;
  info->m_nDiffuseWarpTexture = LIGHTWARPTEXTURE_5.m_Index;
  info->m_nPhongWarpTexture = PHONGWARPTEXTURE_0.m_Index;
  info->m_nPhongBoost = PHONGBOOST_4.m_Index;
  info->m_nPhongFresnelRanges = PHONGFRESNELRANGES_1.m_Index;
  info->m_nPhong = PHONG_0.m_Index;
  info->m_nBaseMapAlphaPhongMask = BASEMAPALPHAPHONGMASK.m_Index;
  info->m_nEnvmapFresnel = ENVMAPFRESNEL.m_Index;
  info->m_nDetailTextureCombineMode = DETAILBLENDMODE_1.m_Index;
  info->m_nDetailTextureBlendFactor = DETAILBLENDFACTOR_1.m_Index;
  info->m_nDetailTextureTransform = DETAILTEXTURETRANSFORM_0.m_Index;
  info->m_nBaseMapLuminancePhongMask = BASEMAPLUMINANCEPHONGMASK.m_Index;
  info->m_nRimLight = RIMLIGHT_0.m_Index;
  info->m_nRimLightPower = RIMLIGHTEXPONENT_3.m_Index;
  info->m_nRimLightBoost = RIMLIGHTBOOST_3.m_Index;
  info->m_nRimMask = RIMMASK_0.m_Index;
  info->m_nSeamlessScale = SEAMLESS_SCALE_0.m_Index;
  info->m_nSeamlessDetail = SEAMLESS_DETAIL.m_Index;
  info->m_nSeamlessBase = SEAMLESS_BASE.m_Index;
  info->m_nSeparateDetailUVs = SEPARATEDETAILUVS_0.m_Index;
  info->m_nLinearWrite = LINEARWRITE_1.m_Index;
  info->m_nDetailTint = DETAILTINT_0.m_Index;
  info->m_nInvertPhongMask = INVERTPHONGMASK.m_Index;
  info->m_nSelfIllumMask = SELFILLUMMASK.m_Index;
  info->m_nShaderSrgbRead360 = SHADERSRGBREAD360_3.m_Index;
  info->m_nAmbientOcclusion = AMBIENTOCCLUSION_0.m_Index;
  info->m_nBlendTintByBaseAlpha = BLENDTINTBYBASEALPHA.m_Index;
  info->m_nDesaturateWithBaseAlpha = DESATURATEWITHBASEALPHA.m_Index;
  info->m_nAllowDiffuseModulation = ALLOWDIFFUSEMODULATION.m_Index;
  info->m_nEnvMapFresnelMinMaxExp = ENVMAPFRESNELMINMAXEXP.m_Index;
  info->m_nBaseAlphaEnvMapMaskMinMaxExp = BASEALPHAENVMAPMASKMINMAXEXP.m_Index;
  info->m_nDisplacementMap = DISPLACEMENTMAP_1.m_Index;
  info->m_nDisplacementWrinkleMap = DISPLACEMENTWRINKLE_0.m_Index;
  info->m_nPhongDisableHalfLambert = PHONGDISABLEHALFLAMBERT.m_Index;
  info->m_nTreeSway = TREESWAY_0.m_Index;
  info->m_nTreeSwayHeight = TREESWAYHEIGHT_0.m_Index;
  info->m_nTreeSwayStartHeight = TREESWAYSTARTHEIGHT_0.m_Index;
  info->m_nTreeSwayRadius = TREESWAYRADIUS_0.m_Index;
  info->m_nTreeSwayStartRadius = TREESWAYSTARTRADIUS_0.m_Index;
  info->m_nTreeSwaySpeed = TREESWAYSPEED_0.m_Index;
  info->m_nTreeSwaySpeedHighWindMultiplier = TREESWAYSPEEDHIGHWINDMULTIPLIER_0.m_Index;
  info->m_nTreeSwayStrength = TREESWAYSTRENGTH_0.m_Index;
  info->m_nTreeSwayScrumbleSpeed = TREESWAYSCRUMBLESPEED_0.m_Index;
  info->m_nTreeSwayScrumbleStrength = TREESWAYSCRUMBLESTRENGTH_0.m_Index;
  info->m_nTreeSwayScrumbleFrequency = TREESWAYSCRUMBLEFREQUENCY_0.m_Index;
  info->m_nTreeSwayFalloffExp = TREESWAYFALLOFFEXP_0.m_Index;
  info->m_nTreeSwayScrumbleFalloffExp = TREESWAYSCRUMBLEFALLOFFEXP_0.m_Index;
  info->m_nTreeSwaySpeedLerpStart = TREESWAYSPEEDLERPSTART_0.m_Index;
  info->m_nTreeSwaySpeedLerpEnd = TREESWAYSPEEDLERPEND_0.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10038890
// Name: public: virtual bool VertexLitGeneric::CShader::NeedsPowerOfTwoFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VertexLitGeneric::CShader::NeedsPowerOfTwoFrameBufferTexture(
        VertexLitGeneric::CShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  float x; // xmm0_4

  return params[CLOAKPASSENABLED_2.m_Index]->m_intVal != 0
      && (!bCheckSpecificToThisFrame || (x = params[CLOAKFACTOR_3.m_Index]->m_VecVal.x) > 0.0 && x < 1.0)
      || (params[2]->m_intVal & 0x4000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100388F0
// Name: public: virtual bool VertexLitGeneric::CShader::IsTranslucent(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VertexLitGeneric::CShader::IsTranslucent(VertexLitGeneric::CShader *this, IMaterialVar **params)
{
  float x; // xmm0_4

  return params[CLOAKPASSENABLED_2.m_Index]->m_intVal != 0
      && (x = params[CLOAKFACTOR_3.m_Index]->m_VecVal.x) > 0.0
      && x < 1.0
      || ((*params)->m_intVal & 0x200000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10038940
// Name: public: void VertexLitGeneric::CShader::SetupVarsFleshInteriorBlendedPass(struct FleshInteriorBlendedPassVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VertexLitGeneric::CShader::SetupVarsFleshInteriorBlendedPass(
        VertexLitGeneric::CShader *this,
        FleshInteriorBlendedPassVars_t *info)
{
  info->m_nFleshTexture = FLESHINTERIORTEXTURE.m_Index;
  info->m_nFleshNoiseTexture = FLESHINTERIORNOISETEXTURE.m_Index;
  info->m_nFleshBorderTexture1D = FLESHBORDERTEXTURE1D.m_Index;
  info->m_nFleshNormalTexture = FLESHNORMALTEXTURE.m_Index;
  info->m_nFleshSubsurfaceTexture = FLESHSUBSURFACETEXTURE.m_Index;
  info->m_nFleshCubeTexture = FLESHCUBETEXTURE.m_Index;
  info->m_nflBorderNoiseScale = FLESHBORDERNOISESCALE.m_Index;
  info->m_nflDebugForceFleshOn = FLESHDEBUGFORCEFLESHON.m_Index;
  info->m_nvEffectCenterRadius1 = FLESHEFFECTCENTERRADIUS1.m_Index;
  info->m_nvEffectCenterRadius2 = FLESHEFFECTCENTERRADIUS2.m_Index;
  info->m_nvEffectCenterRadius3 = FLESHEFFECTCENTERRADIUS3.m_Index;
  info->m_nvEffectCenterRadius4 = FLESHEFFECTCENTERRADIUS4.m_Index;
  info->m_ncSubsurfaceTint = FLESHSUBSURFACETINT.m_Index;
  info->m_nflBorderWidth = FLESHBORDERWIDTH.m_Index;
  info->m_nflBorderSoftness = FLESHBORDERSOFTNESS.m_Index;
  info->m_ncBorderTint = FLESHBORDERTINT.m_Index;
  info->m_nflGlobalOpacity = FLESHGLOBALOPACITY.m_Index;
  info->m_nflGlossBrightness = FLESHGLOSSBRIGHTNESS.m_Index;
  info->m_nflScrollSpeed = FLESHSCROLLSPEED.m_Index;
  info->m_nTime = TIME_4.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10038A00
// Name: public: virtual void VertexLitGeneric::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VertexLitGeneric::CShader::OnInitShaderParams(
        VertexLitGeneric::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  IMaterialSystemHardwareConfig_vtbl *v4; // esi
  bool v5; // al
  VertexLitGeneric_DX9_Vars_t vars; // [esp+Ch] [ebp-228h] BYREF
  FleshInteriorBlendedPassVars_t dst; // [esp+1C8h] [ebp-6Ch] BYREF
  EmissiveScrollBlendedPassVars_t info; // [esp+218h] [ebp-1Ch] BYREF

  v4 = g_pHardwareConfig->__vftable;
  v5 = g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig);
  if ( v4->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: v5) >= NVIDIA_PCF_CHEAP )
    params[TREESWAY_0.m_Index]->SetIntValue(this: params[TREESWAY_0.m_Index], a2: 0);
  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  VertexLitGeneric::CShader::SetupVars(this, info: &vars);
  InitParamsVertexLitGeneric_DX9(pShader: this, params, pMaterialName, bVertexLitGeneric: true, info: &vars);
  if ( params[CLOAKPASSENABLED_2.m_Index]->IsDefined(this: params[CLOAKPASSENABLED_2.m_Index]) )
  {
    if ( params[CLOAKPASSENABLED_2.m_Index]->m_intVal != 0 )
    {
      info.m_nBaseTexture = CLOAKFACTOR_3.m_Index;
      info.m_nEmissiveTint = BUMPMAP_8.m_Index;
      info.m_nFlowTexture = CLOAKCOLORTINT_2.m_Index;
      info.m_nEmissiveTexture = REFRACTAMOUNT_6.m_Index;
      info.m_nEmissiveScrollVector = BUMPFRAME_11.m_Index;
      info.m_nTime = BUMPTRANSFORM_5.m_Index;
      InitParamsCloakBlendedPass(
        pShader: this,
        params,
        pMaterialName,
        info: (CloakBlendedPassVars_t *)&info.m_nBaseTexture);
    }
  }
  else
  {
    params[CLOAKPASSENABLED_2.m_Index]->SetIntValue(this: params[CLOAKPASSENABLED_2.m_Index], a2: 0);
  }
  if ( params[EMISSIVEBLENDENABLED_0.m_Index]->IsDefined(this: params[EMISSIVEBLENDENABLED_0.m_Index]) )
  {
    if ( params[EMISSIVEBLENDENABLED_0.m_Index]->m_intVal != 0 )
    {
      info.m_nBaseTexture = EMISSIVEBLENDBASETEXTURE.m_Index;
      info.m_nEmissiveTint = EMISSIVEBLENDTINT_0.m_Index;
      info.m_nBlendStrength = EMISSIVEBLENDSTRENGTH_0.m_Index;
      info.m_nFlowTexture = EMISSIVEBLENDFLOWTEXTURE_0.m_Index;
      info.m_nEmissiveTexture = EMISSIVEBLENDTEXTURE_0.m_Index;
      info.m_nEmissiveScrollVector = EMISSIVEBLENDSCROLLVECTOR_0.m_Index;
      info.m_nTime = TIME_4.m_Index;
      InitParamsEmissiveScrollBlendedPass(pShader: this, params, pMaterialName, &info);
    }
  }
  else
  {
    params[EMISSIVEBLENDENABLED_0.m_Index]->SetIntValue(this: params[EMISSIVEBLENDENABLED_0.m_Index], a2: 0);
  }
  if ( params[FLESHINTERIORENABLED.m_Index]->IsDefined(this: params[FLESHINTERIORENABLED.m_Index]) )
  {
    if ( params[FLESHINTERIORENABLED.m_Index]->m_intVal != 0 )
    {
      memset((unsigned __int8 *)&dst, value: 0xFFu, count: sizeof(dst));
      VertexLitGeneric::CShader::SetupVarsFleshInteriorBlendedPass(this, info: &dst);
      InitParamsFleshInteriorBlendedPass(pShader: this, params, pMaterialName, info: &dst);
    }
  }
  else
  {
    params[FLESHINTERIORENABLED.m_Index]->SetIntValue(this: params[FLESHINTERIORENABLED.m_Index], a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038C20
// Name: public: virtual char const __near * VertexLitGeneric::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VertexLitGeneric::CShader::GetName(VertexLitGeneric::CShader *this)
{
  return s_Name_122;
}

//------------------------------------------------------------------------------
// Address: 0x10038C30
// Name: public: virtual int VertexLitGeneric::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VertexLitGeneric::CShader::GetFlags(VertexLitGeneric::CShader *this)
{
  return s_nFlags_124;
}

//------------------------------------------------------------------------------
// Address: 0x10038C40
// Name: public: virtual void VertexLitGeneric::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VertexLitGeneric::CShader::OnInitShaderInstance(
        VertexLitGeneric::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  VertexLitGeneric_DX9_Vars_t vars; // [esp+8h] [ebp-228h] BYREF
  FleshInteriorBlendedPassVars_t dst; // [esp+1C4h] [ebp-6Ch] BYREF
  EmissiveScrollBlendedPassVars_t info; // [esp+214h] [ebp-1Ch] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  VertexLitGeneric::CShader::SetupVars(this, info: &vars);
  InitVertexLitGeneric_DX9(pShader: this, params, bVertexLitGeneric: true, info: &vars);
  if ( params[CLOAKPASSENABLED_2.m_Index]->m_intVal != 0 )
  {
    info.m_nBaseTexture = CLOAKFACTOR_3.m_Index;
    info.m_nEmissiveTint = BUMPMAP_8.m_Index;
    info.m_nFlowTexture = CLOAKCOLORTINT_2.m_Index;
    info.m_nEmissiveTexture = REFRACTAMOUNT_6.m_Index;
    info.m_nEmissiveScrollVector = BUMPFRAME_11.m_Index;
    info.m_nTime = BUMPTRANSFORM_5.m_Index;
    InitCloakBlendedPass(pShader: this, params, info: (CloakBlendedPassVars_t *)&info.m_nBaseTexture);
  }
  if ( params[EMISSIVEBLENDENABLED_0.m_Index]->m_intVal != 0 )
  {
    info.m_nBaseTexture = EMISSIVEBLENDBASETEXTURE.m_Index;
    info.m_nEmissiveTint = EMISSIVEBLENDTINT_0.m_Index;
    info.m_nBlendStrength = EMISSIVEBLENDSTRENGTH_0.m_Index;
    info.m_nFlowTexture = EMISSIVEBLENDFLOWTEXTURE_0.m_Index;
    info.m_nEmissiveTexture = EMISSIVEBLENDTEXTURE_0.m_Index;
    info.m_nEmissiveScrollVector = EMISSIVEBLENDSCROLLVECTOR_0.m_Index;
    info.m_nTime = TIME_4.m_Index;
    InitEmissiveScrollBlendedPass(pShader: this, params, &info);
  }
  if ( params[FLESHINTERIORENABLED.m_Index]->m_intVal != 0 )
  {
    memset((unsigned __int8 *)&dst, value: 0xFFu, count: sizeof(dst));
    VertexLitGeneric::CShader::SetupVarsFleshInteriorBlendedPass(this, info: &dst);
    InitFleshInteriorBlendedPass(pShader: this, params, info: &dst);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038DB0
// Name: public: virtual void VertexLitGeneric::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VertexLitGeneric::CShader::OnDrawElements(
        VertexLitGeneric::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  float x; // xmm0_4
  VertexLitGeneric_DX9_Vars_t vars; // [esp+Ch] [ebp-228h] BYREF
  FleshInteriorBlendedPassVars_t dst; // [esp+1C8h] [ebp-6Ch] BYREF
  EmissiveScrollBlendedPassVars_t info; // [esp+218h] [ebp-1Ch] BYREF

  if ( params[CLOAKPASSENABLED_2.m_Index]->m_intVal != 0
    && pShaderShadow == nullptr
    && (info.m_nBaseTexture = CLOAKFACTOR_3.m_Index,
        info.m_nEmissiveTint = BUMPMAP_8.m_Index,
        info.m_nFlowTexture = CLOAKCOLORTINT_2.m_Index,
        info.m_nEmissiveTexture = REFRACTAMOUNT_6.m_Index,
        info.m_nEmissiveScrollVector = BUMPFRAME_11.m_Index,
        info.m_nTime = BUMPTRANSFORM_5.m_Index,
        CloakBlendedPassIsFullyOpaque(params, info: (CloakBlendedPassVars_t *)&info.m_nBaseTexture)) )
  {
    CBaseShader::Draw(this, bMakeActualDrawCall: false);
  }
  else
  {
    memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
    VertexLitGeneric::CShader::SetupVars(this, info: &vars);
    DrawVertexLitGeneric_DX9(
      pShader: this,
      params,
      pShaderAPI,
      pShaderShadow,
      bVertexLitGeneric: 1,
      info: &vars,
      vertexCompression,
      pContextDataPtr);
  }
  if ( params[CLOAKPASSENABLED_2.m_Index]->m_intVal != 0 )
  {
    if ( pShaderShadow != nullptr || (x = params[CLOAKFACTOR_3.m_Index]->m_VecVal.x) > 0.0 && x < 1.0 )
    {
      info.m_nBaseTexture = CLOAKFACTOR_3.m_Index;
      info.m_nFlowTexture = CLOAKCOLORTINT_2.m_Index;
      info.m_nEmissiveTint = BUMPMAP_8.m_Index;
      info.m_nEmissiveTexture = REFRACTAMOUNT_6.m_Index;
      info.m_nEmissiveScrollVector = BUMPFRAME_11.m_Index;
      info.m_nTime = BUMPTRANSFORM_5.m_Index;
      DrawCloakBlendedPass(
        pShader: this,
        params,
        pShaderAPI,
        pShaderShadow,
        info: (CloakBlendedPassVars_t *)&info.m_nBaseTexture,
        vertexCompression);
    }
    else
    {
      CBaseShader::Draw(this, bMakeActualDrawCall: false);
    }
  }
  if ( params[EMISSIVEBLENDENABLED_0.m_Index]->m_intVal != 0 )
  {
    if ( pShaderShadow != nullptr || params[EMISSIVEBLENDSTRENGTH_0.m_Index]->m_VecVal.x > 0.0 )
    {
      info.m_nBlendStrength = EMISSIVEBLENDSTRENGTH_0.m_Index;
      info.m_nBaseTexture = EMISSIVEBLENDBASETEXTURE.m_Index;
      info.m_nFlowTexture = EMISSIVEBLENDFLOWTEXTURE_0.m_Index;
      info.m_nEmissiveTint = EMISSIVEBLENDTINT_0.m_Index;
      info.m_nEmissiveTexture = EMISSIVEBLENDTEXTURE_0.m_Index;
      info.m_nEmissiveScrollVector = EMISSIVEBLENDSCROLLVECTOR_0.m_Index;
      info.m_nTime = TIME_4.m_Index;
      DrawEmissiveScrollBlendedPass(
        a1: (int)pShaderShadow,
        pShader: this,
        params,
        pShaderAPI,
        pShaderShadow,
        &info,
        vertexCompression);
    }
    else
    {
      CBaseShader::Draw(this, bMakeActualDrawCall: false);
    }
  }
  if ( params[FLESHINTERIORENABLED.m_Index]->m_intVal != 0 )
  {
    memset((unsigned __int8 *)&dst, value: 0xFFu, count: sizeof(dst));
    VertexLitGeneric::CShader::SetupVarsFleshInteriorBlendedPass(this, info: &dst);
    DrawFleshInteriorBlendedPass(pShader: this, params, pShaderAPI, pShaderShadow, info: &dst, vertexCompression);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039010
// Name: public: virtual int VertexLitGeneric::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VertexLitGeneric::CShader::GetParamCount(VertexLitGeneric::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_122.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10039020
// Name: public: virtual struct ShaderParamInfo_t const __near & VertexLitGeneric::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *__thiscall VertexLitGeneric::CShader::GetParamInfo(
        VertexLitGeneric::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_122.m_Memory.m_pMemory[param - ParamCount];
  else
    return (VertexLitGeneric::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10039050
// Name: public: VertexLitGeneric::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *__thiscall VertexLitGeneric::CShaderParam::CShaderParam(
        VertexLitGeneric::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  VertexLitGeneric::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  VertexLitGeneric::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_122.m_Size + 13;
  m_Size = s_ShaderParams_122.m_Size;
  v8 = s_ShaderParams_122.m_Size;
  if ( s_ShaderParams_122.m_Size + 1 > s_ShaderParams_122.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_122,
      num: s_ShaderParams_122.m_Size - s_ShaderParams_122.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_122.m_Size;
  }
  m_pMemory = s_ShaderParams_122.m_Memory.m_pMemory;
  s_ShaderParams_122.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_122.m_pElements = s_ShaderParams_122.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_122.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_122.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_122.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068520
// Name: VertexLitGeneric::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int VertexLitGeneric::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: VertexLitGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10068530
// Name: VertexLitGeneric::_dynamic_initializer_for__ALBEDO__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ALBEDO__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ALBEDO_0,
           pName: "$ALBEDO",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "albedo (Base texture with no baked lighting)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068550
// Name: VertexLitGeneric::_dynamic_initializer_for__COMPRESS__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__COMPRESS__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &COMPRESS,
           pName: "$COMPRESS",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "compression wrinklemap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068570
// Name: VertexLitGeneric::_dynamic_initializer_for__STRETCH__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__STRETCH__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &STRETCH,
           pName: "$STRETCH",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "expansion wrinklemap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068590
// Name: VertexLitGeneric::_dynamic_initializer_for__SELFILLUMTINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SELFILLUMTINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SELFILLUMTINT_1,
           pName: "$SELFILLUMTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Self-illumination tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100685B0
// Name: VertexLitGeneric::_dynamic_initializer_for__DETAIL__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DETAIL__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DETAIL_2,
           pName: "$DETAIL",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/detail",
           pHelp: "detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100685D0
// Name: VertexLitGeneric::_dynamic_initializer_for__DETAILFRAME__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DETAILFRAME__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DETAILFRAME_1,
           pName: "$DETAILFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $detail",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100685F0
// Name: VertexLitGeneric::_dynamic_initializer_for__DETAILSCALE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DETAILSCALE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DETAILSCALE_2,
           pName: "$DETAILSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4",
           pHelp: "scale of the detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068610
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAP__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAP_6,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068630
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPFRAME__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPFRAME_3,
           pName: "$ENVMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "envmap frame number",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068650
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPMASK__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPMASK__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASK_3,
           pName: "$ENVMAPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_envmask",
           pHelp: "envmap mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068670
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPMASKFRAME__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPMASKFRAME__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASKFRAME_3,
           pName: "$ENVMAPMASKFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068690
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASKTRANSFORM_2,
           pName: "$ENVMAPMASKTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$envmapmask texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100686B0
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPTINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPTINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPTINT_4,
           pName: "$ENVMAPTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "envmap tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100686D0
// Name: VertexLitGeneric::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BUMPMAP__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BUMPMAP_8,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100686F0
// Name: VertexLitGeneric::_dynamic_initializer_for__BUMPCOMPRESS__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BUMPCOMPRESS__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BUMPCOMPRESS,
           pName: "$BUMPCOMPRESS",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader3_normal",
           pHelp: "compression bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068710
// Name: VertexLitGeneric::_dynamic_initializer_for__BUMPSTRETCH__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BUMPSTRETCH__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BUMPSTRETCH,
           pName: "$BUMPSTRETCH",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "expansion bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068730
// Name: VertexLitGeneric::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BUMPFRAME__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BUMPFRAME_11,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068750
// Name: VertexLitGeneric::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_5,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068770
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPCONTRAST__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPCONTRAST__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPCONTRAST_3,
           pName: "$ENVMAPCONTRAST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "contrast 0 == normal 1 == color*color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068790
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPSATURATION__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPSATURATION__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPSATURATION_3,
           pName: "$ENVMAPSATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "saturation 0 == greyscale 1 == normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100687B0
// Name: VertexLitGeneric::_dynamic_initializer_for__SELFILLUM_ENVMAPMASK_ALPHA__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SELFILLUM_ENVMAPMASK_ALPHA__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SELFILLUM_ENVMAPMASK_ALPHA,
           pName: "$SELFILLUM_ENVMAPMASK_ALPHA",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "defines that self illum value comes from env map mask alpha",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100687D0
// Name: VertexLitGeneric::_dynamic_initializer_for__SELFILLUMFRESNEL__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SELFILLUMFRESNEL__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SELFILLUMFRESNEL_0,
           pName: "$SELFILLUMFRESNEL",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Self illum fresnel",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100687F0
// Name: VertexLitGeneric::_dynamic_initializer_for__SELFILLUMFRESNELMINMAXEXP__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SELFILLUMFRESNELMINMAXEXP__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SELFILLUMFRESNELMINMAXEXP_0,
           pName: "$SELFILLUMFRESNELMINMAXEXP",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "0",
           pHelp: "Self illum fresnel min, max, exp",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068810
// Name: VertexLitGeneric::_dynamic_initializer_for__SELFILLUMMASKSCALE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SELFILLUMMASKSCALE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SELFILLUMMASKSCALE,
           pName: "$SELFILLUMMASKSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Scale self illum effect strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068830
// Name: VertexLitGeneric::_dynamic_initializer_for__ALPHATESTREFERENCE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ALPHATESTREFERENCE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ALPHATESTREFERENCE_2,
           pName: "$ALPHATESTREFERENCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068850
// Name: VertexLitGeneric::_dynamic_initializer_for__FLASHLIGHTNOLAMBERT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLASHLIGHTNOLAMBERT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLASHLIGHTNOLAMBERT,
           pName: "$FLASHLIGHTNOLAMBERT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Flashlight pass sets N.L=1.0",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068870
// Name: VertexLitGeneric::_dynamic_initializer_for__LOWQUALITYFLASHLIGHTSHADOWS__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__LOWQUALITYFLASHLIGHTSHADOWS__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &LOWQUALITYFLASHLIGHTSHADOWS,
           pName: "$LOWQUALITYFLASHLIGHTSHADOWS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Force low quality flashlight shadows (faster)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068890
// Name: VertexLitGeneric::_dynamic_initializer_for__AMBIENTONLY__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__AMBIENTONLY__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &AMBIENTONLY,
           pName: "$AMBIENTONLY",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Control drawing of non-ambient light ()",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100688B0
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONGEXPONENT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT_5,
           pName: "$PHONGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "5.0",
           pHelp: "Phong exponent for local specular lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100688D0
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONGTINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONGTINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONGTINT_1,
           pName: "$PHONGTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "5.0",
           pHelp: "Phong tint for local specular lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100688F0
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONGALBEDOTINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONGALBEDOTINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONGALBEDOTINT_1,
           pName: "$PHONGALBEDOTINT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1.0",
           pHelp: "Apply tint by albedo (controlled by spec exponent texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068910
// Name: VertexLitGeneric::_dynamic_initializer_for__LIGHTWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__LIGHTWARPTEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &LIGHTWARPTEXTURE_5,
           pName: "$LIGHTWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for tinting scalar diffuse term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068930
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONGWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONGWARPTEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONGWARPTEXTURE_0,
           pName: "$PHONGWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "warp the specular term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068950
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONGFRESNELRANGES__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONGFRESNELRANGES__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONGFRESNELRANGES_1,
           pName: "$PHONGFRESNELRANGES",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0  0.5  1]",
           pHelp: "Parameters for remapping fresnel output",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068970
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONGBOOST__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONGBOOST__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONGBOOST_4,
           pName: "$PHONGBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Phong overbrightening factor (specular mask channel should be authored to account for this)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068990
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONGEXPONENTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONGEXPONENTTEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONGEXPONENTTEXTURE_1,
           pName: "$PHONGEXPONENTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Phong Exponent map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100689B0
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONG__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONG__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONG_0,
           pName: "$PHONG",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "enables phong lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100689D0
// Name: VertexLitGeneric::_dynamic_initializer_for__BASEMAPALPHAPHONGMASK__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BASEMAPALPHAPHONGMASK__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BASEMAPALPHAPHONGMASK,
           pName: "$BASEMAPALPHAPHONGMASK",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "indicates that there is no normal map and that the phong mask is in base alpha",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100689F0
// Name: VertexLitGeneric::_dynamic_initializer_for__INVERTPHONGMASK__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__INVERTPHONGMASK__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &INVERTPHONGMASK,
           pName: "$INVERTPHONGMASK",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "invert the phong mask (0=full phong, 1=no phong)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068A10
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPFRESNEL__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPFRESNEL__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPFRESNEL,
           pName: "$ENVMAPFRESNEL",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Degree to which Fresnel should be applied to env map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068A30
// Name: VertexLitGeneric::_dynamic_initializer_for__SELFILLUMMASK__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SELFILLUMMASK__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SELFILLUMMASK,
           pName: "$SELFILLUMMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "If we bind a texture here, it overrides base alpha (if any) for self illum",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068A50
// Name: VertexLitGeneric::_dynamic_initializer_for__BASEMAPLUMINANCEPHONGMASK__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BASEMAPLUMINANCEPHONGMASK__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BASEMAPLUMINANCEPHONGMASK,
           pName: "$BASEMAPLUMINANCEPHONGMASK",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "indicates that the base luminance should be used to mask phong",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068A70
// Name: VertexLitGeneric::_dynamic_initializer_for__DETAILBLENDMODE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DETAILBLENDMODE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DETAILBLENDMODE_1,
           pName: "$DETAILBLENDMODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "mode for combining detail texture with base. 0=normal, 1= additive, 2=alpha blend detail over base, 3=crossfade",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068A90
// Name: VertexLitGeneric::_dynamic_initializer_for__DETAILBLENDFACTOR__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DETAILBLENDFACTOR__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DETAILBLENDFACTOR_1,
           pName: "$DETAILBLENDFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "blend amount for detail texture.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068AB0
// Name: VertexLitGeneric::_dynamic_initializer_for__DETAILTINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DETAILTINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DETAILTINT_0,
           pName: "$DETAILTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "detail texture tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068AD0
// Name: VertexLitGeneric::_dynamic_initializer_for__DETAILTEXTURETRANSFORM__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DETAILTEXTURETRANSFORM__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DETAILTEXTURETRANSFORM_0,
           pName: "$DETAILTEXTURETRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$detail texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068AF0
// Name: VertexLitGeneric::_dynamic_initializer_for__RIMLIGHT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__RIMLIGHT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &RIMLIGHT_0,
           pName: "$RIMLIGHT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "enables rim lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068B10
// Name: VertexLitGeneric::_dynamic_initializer_for__RIMLIGHTEXPONENT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__RIMLIGHTEXPONENT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &RIMLIGHTEXPONENT_3,
           pName: "$RIMLIGHTEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4.0",
           pHelp: "Exponent for rim lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068B30
// Name: VertexLitGeneric::_dynamic_initializer_for__RIMLIGHTBOOST__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__RIMLIGHTBOOST__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &RIMLIGHTBOOST_3,
           pName: "$RIMLIGHTBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Boost for rim lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068B50
// Name: VertexLitGeneric::_dynamic_initializer_for__RIMMASK__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__RIMMASK__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &RIMMASK_0,
           pName: "$RIMMASK",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Indicates whether or not to use alpha channel of exponent texture to mask the rim term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068B70
// Name: VertexLitGeneric::_dynamic_initializer_for__SEAMLESS_BASE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SEAMLESS_BASE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SEAMLESS_BASE,
           pName: "$SEAMLESS_BASE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "whether to apply seamless mapping to the base texture. requires a smooth model.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068B90
// Name: VertexLitGeneric::_dynamic_initializer_for__SEAMLESS_DETAIL__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SEAMLESS_DETAIL__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SEAMLESS_DETAIL,
           pName: "$SEAMLESS_DETAIL",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "where to apply seamless mapping to the detail texture.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068BB0
// Name: VertexLitGeneric::_dynamic_initializer_for__SEAMLESS_SCALE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SEAMLESS_SCALE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SEAMLESS_SCALE_0,
           pName: "$SEAMLESS_SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "the scale for the seamless mapping. # of repetions of texture per inch.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068BD0
// Name: VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDENABLED__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDENABLED__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDENABLED_0,
           pName: "$EMISSIVEBLENDENABLED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable emissive blend pass",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068BF0
// Name: VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDBASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDBASETEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDBASETEXTURE,
           pName: "$EMISSIVEBLENDBASETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "self-illumination map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068C10
// Name: VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDSCROLLVECTOR__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDSCROLLVECTOR__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDSCROLLVECTOR_0,
           pName: "$EMISSIVEBLENDSCROLLVECTOR",
           type: SHADER_PARAM_TYPE_VEC2,
           pDefaultParam: "[0.11 0.124]",
           pHelp: "Emissive scroll vec",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068C30
// Name: VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDSTRENGTH__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDSTRENGTH_0,
           pName: "$EMISSIVEBLENDSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Emissive blend strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068C50
// Name: VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDTEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDTEXTURE_0,
           pName: "$EMISSIVEBLENDTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "self-illumination map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068C70
// Name: VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDTINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDTINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDTINT_0,
           pName: "$EMISSIVEBLENDTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Self-illumination tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068C90
// Name: VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDFLOWTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__EMISSIVEBLENDFLOWTEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDFLOWTEXTURE_0,
           pName: "$EMISSIVEBLENDFLOWTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "flow map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068CB0
// Name: VertexLitGeneric::_dynamic_initializer_for__TIME__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TIME__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TIME_4,
           pName: "$TIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Needs CurrentTime Proxy",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068CD0
// Name: VertexLitGeneric::_dynamic_initializer_for__CLOAKPASSENABLED__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__CLOAKPASSENABLED__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &CLOAKPASSENABLED_2,
           pName: "$CLOAKPASSENABLED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enables cloak render in a second pass",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068CF0
// Name: VertexLitGeneric::_dynamic_initializer_for__CLOAKFACTOR__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__CLOAKFACTOR__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &CLOAKFACTOR_3,
           pName: "$CLOAKFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068D10
// Name: VertexLitGeneric::_dynamic_initializer_for__CLOAKCOLORTINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__CLOAKCOLORTINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &CLOAKCOLORTINT_2,
           pName: "$CLOAKCOLORTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Cloak color tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068D30
// Name: VertexLitGeneric::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_6,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068D50
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHINTERIORENABLED__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHINTERIORENABLED__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHINTERIORENABLED,
           pName: "$FLESHINTERIORENABLED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable Flesh interior blend pass",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068D70
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHINTERIORTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHINTERIORTEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHINTERIORTEXTURE,
           pName: "$FLESHINTERIORTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Flesh color texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068D90
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHINTERIORNOISETEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHINTERIORNOISETEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHINTERIORNOISETEXTURE,
           pName: "$FLESHINTERIORNOISETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Flesh noise texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068DB0
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERTEXTURE1D__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERTEXTURE1D__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHBORDERTEXTURE1D,
           pName: "$FLESHBORDERTEXTURE1D",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Flesh border 1D texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068DD0
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHNORMALTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHNORMALTEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHNORMALTEXTURE,
           pName: "$FLESHNORMALTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Flesh normal texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068DF0
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHSUBSURFACETEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHSUBSURFACETEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHSUBSURFACETEXTURE,
           pName: "$FLESHSUBSURFACETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Flesh subsurface texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068E10
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHCUBETEXTURE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHCUBETEXTURE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHCUBETEXTURE,
           pName: "$FLESHCUBETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Flesh cubemap texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068E30
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERNOISESCALE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERNOISESCALE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHBORDERNOISESCALE,
           pName: "$FLESHBORDERNOISESCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.5",
           pHelp: "Flesh Noise UV scalar for border",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068E50
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHDEBUGFORCEFLESHON__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHDEBUGFORCEFLESHON__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHDEBUGFORCEFLESHON,
           pName: "$FLESHDEBUGFORCEFLESHON",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Flesh Debug full flesh",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068E70
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHEFFECTCENTERRADIUS1__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHEFFECTCENTERRADIUS1__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHEFFECTCENTERRADIUS1,
           pName: "$FLESHEFFECTCENTERRADIUS1",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0.001]",
           pHelp: "Flesh effect center and radius",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068E90
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHEFFECTCENTERRADIUS2__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHEFFECTCENTERRADIUS2__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHEFFECTCENTERRADIUS2,
           pName: "$FLESHEFFECTCENTERRADIUS2",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0.001]",
           pHelp: "Flesh effect center and radius",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068EB0
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHEFFECTCENTERRADIUS3__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHEFFECTCENTERRADIUS3__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHEFFECTCENTERRADIUS3,
           pName: "$FLESHEFFECTCENTERRADIUS3",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0.001]",
           pHelp: "Flesh effect center and radius",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068ED0
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHEFFECTCENTERRADIUS4__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHEFFECTCENTERRADIUS4__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHEFFECTCENTERRADIUS4,
           pName: "$FLESHEFFECTCENTERRADIUS4",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 0 0.001]",
           pHelp: "Flesh effect center and radius",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068EF0
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHSUBSURFACETINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHSUBSURFACETINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHSUBSURFACETINT,
           pName: "$FLESHSUBSURFACETINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Subsurface Color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068F10
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERWIDTH__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERWIDTH__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHBORDERWIDTH,
           pName: "$FLESHBORDERWIDTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.3",
           pHelp: "Flesh border",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068F30
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERSOFTNESS__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERSOFTNESS__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHBORDERSOFTNESS,
           pName: "$FLESHBORDERSOFTNESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.42",
           pHelp: "Flesh border softness (> 0.0 && <= 0.5)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068F50
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERTINT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHBORDERTINT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHBORDERTINT,
           pName: "$FLESHBORDERTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Flesh border Color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068F70
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHGLOBALOPACITY__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHGLOBALOPACITY__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHGLOBALOPACITY,
           pName: "$FLESHGLOBALOPACITY",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Flesh global opacity",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068F90
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHGLOSSBRIGHTNESS__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHGLOSSBRIGHTNESS__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHGLOSSBRIGHTNESS,
           pName: "$FLESHGLOSSBRIGHTNESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.66",
           pHelp: "Flesh gloss brightness",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068FB0
// Name: VertexLitGeneric::_dynamic_initializer_for__FLESHSCROLLSPEED__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__FLESHSCROLLSPEED__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &FLESHSCROLLSPEED,
           pName: "$FLESHSCROLLSPEED",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Flesh scroll speed",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068FD0
// Name: VertexLitGeneric::_dynamic_initializer_for__SEPARATEDETAILUVS__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SEPARATEDETAILUVS__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SEPARATEDETAILUVS_0,
           pName: "$SEPARATEDETAILUVS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Use texcoord1 for detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069000
// Name: VertexLitGeneric::_dynamic_initializer_for__LINEARWRITE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__LINEARWRITE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &LINEARWRITE_1,
           pName: "$LINEARWRITE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Disables SRGB conversion of shader results.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069020
// Name: VertexLitGeneric::_dynamic_initializer_for__SHADERSRGBREAD360__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__SHADERSRGBREAD360__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &SHADERSRGBREAD360_3,
           pName: "$SHADERSRGBREAD360",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Simulate srgb read in shader code",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069040
// Name: VertexLitGeneric::_dynamic_initializer_for__AMBIENTOCCLUSION__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__AMBIENTOCCLUSION__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &AMBIENTOCCLUSION_0,
           pName: "$AMBIENTOCCLUSION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Amount of screen space ambient occlusion to use (0..1 range)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069060
// Name: VertexLitGeneric::_dynamic_initializer_for__DISPLACEMENTMAP__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DISPLACEMENTMAP__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DISPLACEMENTMAP_1,
           pName: "$DISPLACEMENTMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Displacement map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069080
// Name: VertexLitGeneric::_dynamic_initializer_for__DISPLACEMENTWRINKLE__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DISPLACEMENTWRINKLE__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DISPLACEMENTWRINKLE_0,
           pName: "$DISPLACEMENTWRINKLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Displacement map contains wrinkle displacements",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100690A0
// Name: VertexLitGeneric::_dynamic_initializer_for__BLENDTINTBYBASEALPHA__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BLENDTINTBYBASEALPHA__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BLENDTINTBYBASEALPHA,
           pName: "$BLENDTINTBYBASEALPHA",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Use the base alpha to blend in the $color modulation",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100690C0
// Name: VertexLitGeneric::_dynamic_initializer_for__DESATURATEWITHBASEALPHA__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__DESATURATEWITHBASEALPHA__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &DESATURATEWITHBASEALPHA,
           pName: "$DESATURATEWITHBASEALPHA",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Use the base alpha to desaturate the base texture.  Set to non-zero to enable, value gets multiplied into the"
           " alpha channel before desaturating.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100690E0
// Name: VertexLitGeneric::_dynamic_initializer_for__ALLOWDIFFUSEMODULATION__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ALLOWDIFFUSEMODULATION__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ALLOWDIFFUSEMODULATION,
           pName: "$ALLOWDIFFUSEMODULATION",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "Allow per-instance color modulation",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069100
// Name: VertexLitGeneric::_dynamic_initializer_for__ENVMAPFRESNELMINMAXEXP__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__ENVMAPFRESNELMINMAXEXP__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPFRESNELMINMAXEXP,
           pName: "$ENVMAPFRESNELMINMAXEXP",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0.0 1.0 2.0]",
           pHelp: "Min/max fresnel range and exponent for vertexlitgeneric",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069120
// Name: VertexLitGeneric::_dynamic_initializer_for__BASEALPHAENVMAPMASKMINMAXEXP__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__BASEALPHAENVMAPMASKMINMAXEXP__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &BASEALPHAENVMAPMASKMINMAXEXP,
           pName: "$BASEALPHAENVMAPMASKMINMAXEXP",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1.0 0.0 1.0]",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069140
// Name: VertexLitGeneric::_dynamic_initializer_for__PHONGDISABLEHALFLAMBERT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__PHONGDISABLEHALFLAMBERT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &PHONGDISABLEHALFLAMBERT,
           pName: "$PHONGDISABLEHALFLAMBERT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Disable half lambert for phong",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069160
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAY__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAY__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAY_0,
           pName: "$TREESWAY",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069180
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYHEIGHT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYHEIGHT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYHEIGHT_0,
           pName: "$TREESWAYHEIGHT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1000",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100691A0
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSTARTHEIGHT__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSTARTHEIGHT__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSTARTHEIGHT_0,
           pName: "$TREESWAYSTARTHEIGHT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100691C0
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYRADIUS__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYRADIUS__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYRADIUS_0,
           pName: "$TREESWAYRADIUS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "300",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100691E0
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSTARTRADIUS__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSTARTRADIUS__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSTARTRADIUS_0,
           pName: "$TREESWAYSTARTRADIUS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069200
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSPEED__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSPEED__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSPEED_0,
           pName: "$TREESWAYSPEED",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069220
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSPEEDHIGHWINDMULTIPLIER__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSPEEDHIGHWINDMULTIPLIER__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSPEEDHIGHWINDMULTIPLIER_0,
           pName: "$TREESWAYSPEEDHIGHWINDMULTIPLIER",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069240
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSTRENGTH__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSTRENGTH_0,
           pName: "$TREESWAYSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "10",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069260
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSCRUMBLESPEED__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSCRUMBLESPEED__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSCRUMBLESPEED_0,
           pName: "$TREESWAYSCRUMBLESPEED",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069280
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSCRUMBLESTRENGTH__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSCRUMBLESTRENGTH__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSCRUMBLESTRENGTH_0,
           pName: "$TREESWAYSCRUMBLESTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100692A0
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSCRUMBLEFREQUENCY__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSCRUMBLEFREQUENCY__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSCRUMBLEFREQUENCY_0,
           pName: "$TREESWAYSCRUMBLEFREQUENCY",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100692C0
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYFALLOFFEXP__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYFALLOFFEXP__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYFALLOFFEXP_0,
           pName: "$TREESWAYFALLOFFEXP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.5",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100692E0
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSCRUMBLEFALLOFFEXP__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSCRUMBLEFALLOFFEXP__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSCRUMBLEFALLOFFEXP_0,
           pName: "$TREESWAYSCRUMBLEFALLOFFEXP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069300
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSPEEDLERPSTART__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSPEEDLERPSTART__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSPEEDLERPSTART_0,
           pName: "$TREESWAYSPEEDLERPSTART",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "3",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069320
// Name: VertexLitGeneric::_dynamic_initializer_for__TREESWAYSPEEDLERPEND__
// Source: json
//------------------------------------------------------------------------------
VertexLitGeneric::CShaderParam *VertexLitGeneric::_dynamic_initializer_for__TREESWAYSPEEDLERPEND__()
{
  return VertexLitGeneric::CShaderParam::CShaderParam(
           this: &TREESWAYSPEEDLERPEND_0,
           pName: "$TREESWAYSPEEDLERPEND",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "6",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069340
// Name: VertexLitGeneric::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *VertexLitGeneric::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_122);
  s_ShaderInstance_122.__vftable = (VertexLitGeneric::CShader_vtbl *)&VertexLitGeneric::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B860
// Name: VertexLitGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl VertexLitGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_122);
}

//------------------------------------------------------------------------------
// Address: 0x10069360
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069380
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_bump_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100693A0
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100693C0
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100693E0
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_bump_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069400
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_bump_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069420
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069440
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069460
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_bump_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069480
// Name: _dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_vertexlit_and_unlit_generic_bump_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &vertexlit_and_unlit_generic_bump_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100694A0
// Name: _dynamic_initializer_for__r_lightwarpidentity___2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_lightwarpidentity___2()
{
  ConVar::ConVar(this: &r_lightwarpidentity_2, pName: "r_lightwarpidentity", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_lightwarpidentity___2);
}

//------------------------------------------------------------------------------
// Address: 0x100694D0
// Name: _dynamic_initializer_for__mat_phong__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_phong__()
{
  ConVar::ConVar(this: &mat_phong, pName: "mat_phong", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_phong__);
}

//------------------------------------------------------------------------------
// Address: 0x10069500
// Name: _dynamic_initializer_for__mat_displacementmap___4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_displacementmap___4()
{
  ConVar::ConVar(this: &mat_displacementmap_4, pName: "mat_displacementmap", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_displacementmap___4);
}

//------------------------------------------------------------------------------
// Address: 0x10069530
// Name: _dynamic_initializer_for__mat_force_vertexfog___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_vertexfog___0()
{
  ConVar::ConVar(this: &mat_force_vertexfog_0, pName: "mat_force_vertexfog", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_force_vertexfog___0);
}

//------------------------------------------------------------------------------
// Address: 0x1006B870
// Name: _dynamic_atexit_destructor_for__r_lightwarpidentity___2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_lightwarpidentity___2()
{
  ConVar::~ConVar(this: &r_lightwarpidentity_2);
}

//------------------------------------------------------------------------------
// Address: 0x1006B880
// Name: _dynamic_atexit_destructor_for__mat_phong__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_phong__()
{
  ConVar::~ConVar(this: &mat_phong);
}

//------------------------------------------------------------------------------
// Address: 0x1006B890
// Name: _dynamic_atexit_destructor_for__mat_displacementmap___4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_displacementmap___4()
{
  ConVar::~ConVar(this: &mat_displacementmap_4);
}

//------------------------------------------------------------------------------
// Address: 0x1006B8A0
// Name: _dynamic_atexit_destructor_for__mat_force_vertexfog___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_vertexfog___0()
{
  ConVar::~ConVar(this: &mat_force_vertexfog_0);
}
