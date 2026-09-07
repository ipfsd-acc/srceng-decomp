// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/unlitgeneric_dx9.cpp
// Functions: 70
// ============================================================

#include "materialsystem\stdshaders\unlitgeneric_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x100375F0
// Name: public: void UnlitGeneric::CShader::SetupVars(struct VertexLitGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall UnlitGeneric::CShader::SetupVars(UnlitGeneric::CShader *this, VertexLitGeneric_DX9_Vars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nBaseTextureFrame = 7;
  info->m_nBaseTextureTransform = 8;
  info->m_nAlbedo = ALBEDO.m_Index;
  info->m_nSelfIllumTint = -1;
  info->m_nDetail = DETAIL_1.m_Index;
  info->m_nDetailFrame = DETAILFRAME_0.m_Index;
  info->m_nDetailScale = DETAILSCALE_1.m_Index;
  info->m_nDetailTextureCombineMode = DETAILBLENDMODE_0.m_Index;
  info->m_nDetailTextureBlendFactor = DETAILBLENDFACTOR_0.m_Index;
  info->m_nDetailTextureTransform = DETAILTEXTURETRANSFORM.m_Index;
  info->m_nEnvmap = ENVMAP_5.m_Index;
  info->m_nEnvmapFrame = ENVMAPFRAME_2.m_Index;
  info->m_nEnvmapMask = ENVMAPMASK_2.m_Index;
  info->m_nEnvmapMaskFrame = ENVMAPMASKFRAME_2.m_Index;
  info->m_nEnvmapMaskTransform = ENVMAPMASKTRANSFORM_1.m_Index;
  info->m_nEnvmapTint = ENVMAPTINT_3.m_Index;
  info->m_nBumpmap = -1;
  info->m_nBumpFrame = -1;
  info->m_nBumpTransform = -1;
  info->m_nEnvmapContrast = ENVMAPCONTRAST_2.m_Index;
  info->m_nEnvmapSaturation = ENVMAPSATURATION_2.m_Index;
  info->m_nAlphaTestReference = ALPHATESTREFERENCE_1.m_Index;
  info->m_nVertexAlphaTest = VERTEXALPHATEST.m_Index;
  info->m_nFlashlightTexture = 9;
  info->m_nFlashlightTextureFrame = 10;
  info->m_nHDRColorScale = HDRCOLORSCALE_0.m_Index;
  info->m_nPhongExponent = -1;
  info->m_nPhongExponentTexture = -1;
  info->m_nDiffuseWarpTexture = -1;
  info->m_nPhongWarpTexture = -1;
  info->m_nPhongBoost = -1;
  info->m_nPhongFresnelRanges = -1;
  info->m_nPhong = -1;
  info->m_nPhongTint = -1;
  info->m_nPhongAlbedoTint = -1;
  info->m_nSelfIllumEnvMapMask_Alpha = -1;
  info->m_nAmbientOnly = -1;
  info->m_nBaseMapAlphaPhongMask = -1;
  info->m_nEnvmapFresnel = -1;
  info->m_nSelfIllumMask = -1;
  info->m_nAmbientOcclusion = -1;
  info->m_nBaseMapLuminancePhongMask = -1;
  info->m_nDistanceAlpha = DISTANCEALPHA_0.m_Index;
  info->m_nDistanceAlphaFromDetail = DISTANCEALPHAFROMDETAIL.m_Index;
  info->m_nSoftEdges = SOFTEDGES_0.m_Index;
  info->m_nEdgeSoftnessStart = EDGESOFTNESSSTART_0.m_Index;
  info->m_nEdgeSoftnessEnd = EDGESOFTNESSEND_0.m_Index;
  info->m_nScaleEdgeSoftnessBasedOnScreenRes = SCALEEDGESOFTNESSBASEDONSCREENRES.m_Index;
  info->m_nGlow = GLOW.m_Index;
  info->m_nGlowColor = GLOWCOLOR.m_Index;
  info->m_nGlowAlpha = GLOWALPHA.m_Index;
  info->m_nGlowStart = GLOWSTART.m_Index;
  info->m_nGlowEnd = GLOWEND.m_Index;
  info->m_nGlowX = GLOWX.m_Index;
  info->m_nGlowY = GLOWY.m_Index;
  info->m_nOutline = OUTLINE_0.m_Index;
  info->m_nOutlineColor = OUTLINECOLOR_0.m_Index;
  info->m_nOutlineAlpha = OUTLINEALPHA_0.m_Index;
  info->m_nOutlineStart0 = OUTLINESTART0_0.m_Index;
  info->m_nOutlineStart1 = OUTLINESTART1_0.m_Index;
  info->m_nOutlineEnd0 = OUTLINEEND0_0.m_Index;
  info->m_nOutlineEnd1 = OUTLINEEND1_0.m_Index;
  info->m_nScaleOutlineSoftnessBasedOnScreenRes = SCALEOUTLINESOFTNESSBASEDONSCREENRES.m_Index;
  info->m_nSeparateDetailUVs = SEPARATEDETAILUVS.m_Index;
  info->m_nLinearWrite = LINEARWRITE_0.m_Index;
  info->m_nGammaColorRead = GAMMACOLORREAD.m_Index;
  info->m_nReceiveFlashlight = RECEIVEFLASHLIGHT.m_Index;
  info->m_nSinglePassFlashlight = SINGLEPASSFLASHLIGHT.m_Index;
  info->m_nShaderSrgbRead360 = SHADERSRGBREAD360_2.m_Index;
  info->m_nDisplacementMap = DISPLACEMENTMAP_0.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10037890
// Name: public: virtual void UnlitGeneric::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall UnlitGeneric::CShader::OnInitShaderParams(
        UnlitGeneric::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  VertexLitGeneric_DX9_Vars_t vars; // [esp+4h] [ebp-1BCh] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  UnlitGeneric::CShader::SetupVars(this, info: &vars);
  InitParamsVertexLitGeneric_DX9(pShader: this, params, pMaterialName, bVertexLitGeneric: false, info: &vars);
}

//------------------------------------------------------------------------------
// Address: 0x100378F0
// Name: public: virtual char const __near * UnlitGeneric::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall UnlitGeneric::CShader::GetName(UnlitGeneric::CShader *this)
{
  return s_Name_119;
}

//------------------------------------------------------------------------------
// Address: 0x10037900
// Name: public: virtual int UnlitGeneric::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall UnlitGeneric::CShader::GetFlags(UnlitGeneric::CShader *this)
{
  return s_nFlags_121;
}

//------------------------------------------------------------------------------
// Address: 0x10037910
// Name: public: virtual void UnlitGeneric::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall UnlitGeneric::CShader::OnInitShaderInstance(
        UnlitGeneric::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  VertexLitGeneric_DX9_Vars_t vars; // [esp+4h] [ebp-1BCh] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  UnlitGeneric::CShader::SetupVars(this, info: &vars);
  InitVertexLitGeneric_DX9(pShader: this, params, bVertexLitGeneric: false, info: &vars);
}

//------------------------------------------------------------------------------
// Address: 0x10037960
// Name: public: virtual void UnlitGeneric::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall UnlitGeneric::CShader::OnDrawElements(
        UnlitGeneric::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  VertexLitGeneric_DX9_Vars_t vars; // [esp+Ch] [ebp-1BCh] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  UnlitGeneric::CShader::SetupVars(this, info: &vars);
  if ( pShaderShadow != nullptr
    || pShaderAPI == nullptr
    || params[RECEIVEFLASHLIGHT.m_Index]->m_intVal != 0
    || !pShaderAPI->InFlashlightMode(this: pShaderAPI) )
  {
    DrawVertexLitGeneric_DX9(
      pShader: this,
      params,
      pShaderAPI,
      pShaderShadow,
      bVertexLitGeneric: 0,
      info: &vars,
      vertexCompression,
      pContextDataPtr);
  }
  else
  {
    CBaseShader::Draw(this, bMakeActualDrawCall: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037A00
// Name: public: virtual int UnlitGeneric::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall UnlitGeneric::CShader::GetParamCount(UnlitGeneric::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_119.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037A10
// Name: public: virtual struct ShaderParamInfo_t const __near & UnlitGeneric::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *__thiscall UnlitGeneric::CShader::GetParamInfo(UnlitGeneric::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_119.m_Memory.m_pMemory[param - ParamCount];
  else
    return (UnlitGeneric::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10037A40
// Name: public: UnlitGeneric::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *__thiscall UnlitGeneric::CShaderParam::CShaderParam(
        UnlitGeneric::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  UnlitGeneric::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  UnlitGeneric::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_119.m_Size + 13;
  m_Size = s_ShaderParams_119.m_Size;
  v8 = s_ShaderParams_119.m_Size;
  if ( s_ShaderParams_119.m_Size + 1 > s_ShaderParams_119.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_119,
      num: s_ShaderParams_119.m_Size - s_ShaderParams_119.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_119.m_Size;
  }
  m_pMemory = s_ShaderParams_119.m_Memory.m_pMemory;
  s_ShaderParams_119.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_119.m_pElements = s_ShaderParams_119.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_119.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_119.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_119.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067C70
// Name: UnlitGeneric::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int UnlitGeneric::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: UnlitGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10067C80
// Name: UnlitGeneric::_dynamic_initializer_for__ALBEDO__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ALBEDO__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ALBEDO,
           pName: "$ALBEDO",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "albedo (Base texture with no baked lighting)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067CA0
// Name: UnlitGeneric::_dynamic_initializer_for__DETAIL__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DETAIL__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DETAIL_1,
           pName: "$DETAIL",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/detail",
           pHelp: "detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067CC0
// Name: UnlitGeneric::_dynamic_initializer_for__DETAILFRAME__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DETAILFRAME__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DETAILFRAME_0,
           pName: "$DETAILFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $detail",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067CE0
// Name: UnlitGeneric::_dynamic_initializer_for__DETAILSCALE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DETAILSCALE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DETAILSCALE_1,
           pName: "$DETAILSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4",
           pHelp: "scale of the detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067D00
// Name: UnlitGeneric::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ENVMAP__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAP_5,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067D20
// Name: UnlitGeneric::_dynamic_initializer_for__ENVMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ENVMAPFRAME__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPFRAME_2,
           pName: "$ENVMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: "envmap frame number",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067D40
// Name: UnlitGeneric::_dynamic_initializer_for__ENVMAPMASK__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ENVMAPMASK__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASK_2,
           pName: "$ENVMAPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_envmask",
           pHelp: "envmap mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067D60
// Name: UnlitGeneric::_dynamic_initializer_for__ENVMAPMASKFRAME__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ENVMAPMASKFRAME__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASKFRAME_2,
           pName: "$ENVMAPMASKFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067D80
// Name: UnlitGeneric::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASKTRANSFORM_1,
           pName: "$ENVMAPMASKTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$envmapmask texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067DA0
// Name: UnlitGeneric::_dynamic_initializer_for__ENVMAPTINT__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ENVMAPTINT__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPTINT_3,
           pName: "$ENVMAPTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "envmap tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067DC0
// Name: UnlitGeneric::_dynamic_initializer_for__ENVMAPCONTRAST__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ENVMAPCONTRAST__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPCONTRAST_2,
           pName: "$ENVMAPCONTRAST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "contrast 0 == normal 1 == color*color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067DE0
// Name: UnlitGeneric::_dynamic_initializer_for__ENVMAPSATURATION__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ENVMAPSATURATION__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPSATURATION_2,
           pName: "$ENVMAPSATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "saturation 0 == greyscale 1 == normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067E00
// Name: UnlitGeneric::_dynamic_initializer_for__ALPHATESTREFERENCE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__ALPHATESTREFERENCE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &ALPHATESTREFERENCE_1,
           pName: "$ALPHATESTREFERENCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.7",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067E20
// Name: UnlitGeneric::_dynamic_initializer_for__VERTEXALPHATEST__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__VERTEXALPHATEST__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &VERTEXALPHATEST,
           pName: "$VERTEXALPHATEST",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067E40
// Name: UnlitGeneric::_dynamic_initializer_for__HDRCOLORSCALE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__HDRCOLORSCALE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &HDRCOLORSCALE_0,
           pName: "$HDRCOLORSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "hdr color scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067E60
// Name: UnlitGeneric::_dynamic_initializer_for__PHONGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__PHONGEXPONENT__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT_4,
           pName: "$PHONGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "5.0",
           pHelp: "Phong exponent for local specular lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067E80
// Name: UnlitGeneric::_dynamic_initializer_for__PHONGTINT__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__PHONGTINT__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &PHONGTINT_0,
           pName: "$PHONGTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "5.0",
           pHelp: "Phong tint for local specular lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067EA0
// Name: UnlitGeneric::_dynamic_initializer_for__PHONGALBEDOTINT__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__PHONGALBEDOTINT__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &PHONGALBEDOTINT_0,
           pName: "$PHONGALBEDOTINT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1.0",
           pHelp: "Apply tint by albedo (controlled by spec exponent texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067EC0
// Name: UnlitGeneric::_dynamic_initializer_for__LIGHTWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__LIGHTWARPTEXTURE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &LIGHTWARPTEXTURE_4,
           pName: "$LIGHTWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for tinting scalar diffuse term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067EE0
// Name: UnlitGeneric::_dynamic_initializer_for__PHONGWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__PHONGWARPTEXTURE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &PHONGWARPTEXTURE,
           pName: "$PHONGWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "2D map for warping specular",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067F00
// Name: UnlitGeneric::_dynamic_initializer_for__PHONGFRESNELRANGES__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__PHONGFRESNELRANGES__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &PHONGFRESNELRANGES_0,
           pName: "$PHONGFRESNELRANGES",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0  0.5  1]",
           pHelp: "Parameters for remapping fresnel output",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067F20
// Name: UnlitGeneric::_dynamic_initializer_for__PHONGBOOST__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__PHONGBOOST__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &PHONGBOOST_3,
           pName: "$PHONGBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Phong overbrightening factor (specular mask channel should be authored to account for this)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067F40
// Name: UnlitGeneric::_dynamic_initializer_for__PHONGEXPONENTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__PHONGEXPONENTTEXTURE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &PHONGEXPONENTTEXTURE_0,
           pName: "$PHONGEXPONENTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Phong Exponent map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067F60
// Name: UnlitGeneric::_dynamic_initializer_for__PHONG__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__PHONG__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &PHONG,
           pName: "$PHONG",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "enables phong lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067F80
// Name: UnlitGeneric::_dynamic_initializer_for__DETAILBLENDMODE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DETAILBLENDMODE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DETAILBLENDMODE_0,
           pName: "$DETAILBLENDMODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "mode for combining detail texture with base. 0=normal, 1= additive, 2=alpha blend detail over base, 3=crossfade",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067FA0
// Name: UnlitGeneric::_dynamic_initializer_for__DETAILBLENDFACTOR__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DETAILBLENDFACTOR__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DETAILBLENDFACTOR_0,
           pName: "$DETAILBLENDFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "blend amount for detail texture.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067FC0
// Name: UnlitGeneric::_dynamic_initializer_for__DETAILTEXTURETRANSFORM__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DETAILTEXTURETRANSFORM__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DETAILTEXTURETRANSFORM,
           pName: "$DETAILTEXTURETRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$detail texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067FE0
// Name: UnlitGeneric::_dynamic_initializer_for__DISTANCEALPHA__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DISTANCEALPHA__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DISTANCEALPHA_0,
           pName: "$DISTANCEALPHA",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Use distance-coded alpha generated from hi-res texture by vtex.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068000
// Name: UnlitGeneric::_dynamic_initializer_for__DISTANCEALPHAFROMDETAIL__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DISTANCEALPHAFROMDETAIL__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DISTANCEALPHAFROMDETAIL,
           pName: "$DISTANCEALPHAFROMDETAIL",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Take the distance-coded alpha mask from the detail texture.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068020
// Name: UnlitGeneric::_dynamic_initializer_for__SOFTEDGES__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__SOFTEDGES__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &SOFTEDGES_0,
           pName: "$SOFTEDGES",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable soft edges to distance coded textures.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068040
// Name: UnlitGeneric::_dynamic_initializer_for__SCALEEDGESOFTNESSBASEDONSCREENRES__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__SCALEEDGESOFTNESSBASEDONSCREENRES__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &SCALEEDGESOFTNESSBASEDONSCREENRES,
           pName: "$SCALEEDGESOFTNESSBASEDONSCREENRES",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Scale the size of the soft edges based upon resolution. 1024x768 = nominal.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068060
// Name: UnlitGeneric::_dynamic_initializer_for__EDGESOFTNESSSTART__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__EDGESOFTNESSSTART__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &EDGESOFTNESSSTART_0,
           pName: "$EDGESOFTNESSSTART",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.6",
           pHelp: "Start value for soft edges for distancealpha.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068080
// Name: UnlitGeneric::_dynamic_initializer_for__EDGESOFTNESSEND__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__EDGESOFTNESSEND__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &EDGESOFTNESSEND_0,
           pName: "$EDGESOFTNESSEND",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.5",
           pHelp: "End value for soft edges for distancealpha.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100680A0
// Name: UnlitGeneric::_dynamic_initializer_for__GLOW__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__GLOW__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &GLOW,
           pName: "$GLOW",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable glow/shadow for distance coded textures.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100680C0
// Name: UnlitGeneric::_dynamic_initializer_for__GLOWCOLOR__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__GLOWCOLOR__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &GLOWCOLOR,
           pName: "$GLOWCOLOR",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "color of outter glow for distance coded line art.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100680E0
// Name: UnlitGeneric::_dynamic_initializer_for__GLOWALPHA__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__GLOWALPHA__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &GLOWALPHA,
           pName: "$GLOWALPHA",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Base glow alpha amount for glows/shadows with distance alpha.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068100
// Name: UnlitGeneric::_dynamic_initializer_for__GLOWSTART__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__GLOWSTART__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &GLOWSTART,
           pName: "$GLOWSTART",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.7",
           pHelp: "start value for glow/shadow",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068120
// Name: UnlitGeneric::_dynamic_initializer_for__GLOWEND__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__GLOWEND__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &GLOWEND,
           pName: "$GLOWEND",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.5",
           pHelp: "end value for glow/shadow",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068140
// Name: UnlitGeneric::_dynamic_initializer_for__GLOWX__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__GLOWX__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &GLOWX,
           pName: "$GLOWX",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "texture offset x for glow mask.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068160
// Name: UnlitGeneric::_dynamic_initializer_for__GLOWY__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__GLOWY__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &GLOWY,
           pName: "$GLOWY",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "texture offset y for glow mask.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068180
// Name: UnlitGeneric::_dynamic_initializer_for__OUTLINE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__OUTLINE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &OUTLINE_0,
           pName: "$OUTLINE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable outline for distance coded textures.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100681A0
// Name: UnlitGeneric::_dynamic_initializer_for__OUTLINECOLOR__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__OUTLINECOLOR__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &OUTLINECOLOR_0,
           pName: "$OUTLINECOLOR",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "color of outline for distance coded images.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100681C0
// Name: UnlitGeneric::_dynamic_initializer_for__OUTLINEALPHA__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__OUTLINEALPHA__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &OUTLINEALPHA_0,
           pName: "$OUTLINEALPHA",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "alpha value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100681E0
// Name: UnlitGeneric::_dynamic_initializer_for__OUTLINESTART0__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__OUTLINESTART0__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &OUTLINESTART0_0,
           pName: "$OUTLINESTART0",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "outer start value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068200
// Name: UnlitGeneric::_dynamic_initializer_for__OUTLINESTART1__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__OUTLINESTART1__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &OUTLINESTART1_0,
           pName: "$OUTLINESTART1",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "inner start value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068220
// Name: UnlitGeneric::_dynamic_initializer_for__OUTLINEEND0__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__OUTLINEEND0__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &OUTLINEEND0_0,
           pName: "$OUTLINEEND0",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "inner end value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068240
// Name: UnlitGeneric::_dynamic_initializer_for__OUTLINEEND1__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__OUTLINEEND1__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &OUTLINEEND1_0,
           pName: "$OUTLINEEND1",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "outer end value for outline",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068260
// Name: UnlitGeneric::_dynamic_initializer_for__SCALEOUTLINESOFTNESSBASEDONSCREENRES__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__SCALEOUTLINESOFTNESSBASEDONSCREENRES__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &SCALEOUTLINESOFTNESSBASEDONSCREENRES,
           pName: "$SCALEOUTLINESOFTNESSBASEDONSCREENRES",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Scale the size of the soft part of the outline based upon resolution. 1024x768 = nominal.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068280
// Name: UnlitGeneric::_dynamic_initializer_for__SEPARATEDETAILUVS__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__SEPARATEDETAILUVS__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &SEPARATEDETAILUVS,
           pName: "$SEPARATEDETAILUVS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Use texcoord1 for detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100682A0
// Name: UnlitGeneric::_dynamic_initializer_for__GAMMACOLORREAD__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__GAMMACOLORREAD__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &GAMMACOLORREAD,
           pName: "$GAMMACOLORREAD",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Disables SRGB conversion of color texture read.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100682C0
// Name: UnlitGeneric::_dynamic_initializer_for__LINEARWRITE__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__LINEARWRITE__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &LINEARWRITE_0,
           pName: "$LINEARWRITE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Disables SRGB conversion of shader results.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100682E0
// Name: UnlitGeneric::_dynamic_initializer_for__RECEIVEFLASHLIGHT__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__RECEIVEFLASHLIGHT__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &RECEIVEFLASHLIGHT,
           pName: "$RECEIVEFLASHLIGHT",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Forces this material to receive flashlights.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068300
// Name: UnlitGeneric::_dynamic_initializer_for__SINGLEPASSFLASHLIGHT__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__SINGLEPASSFLASHLIGHT__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &SINGLEPASSFLASHLIGHT,
           pName: "$SINGLEPASSFLASHLIGHT",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Flags this material as possibly being run through single pass flashlight code",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068320
// Name: UnlitGeneric::_dynamic_initializer_for__DISPLACEMENTMAP__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__DISPLACEMENTMAP__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &DISPLACEMENTMAP_0,
           pName: "$DISPLACEMENTMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Displacement map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068340
// Name: UnlitGeneric::_dynamic_initializer_for__SHADERSRGBREAD360__
// Source: json
//------------------------------------------------------------------------------
UnlitGeneric::CShaderParam *UnlitGeneric::_dynamic_initializer_for__SHADERSRGBREAD360__()
{
  return UnlitGeneric::CShaderParam::CShaderParam(
           this: &SHADERSRGBREAD360_2,
           pName: "$SHADERSRGBREAD360",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Simulate srgb read in shader code",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068360
// Name: UnlitGeneric::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *UnlitGeneric::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_119);
  s_ShaderInstance_119.__vftable = (UnlitGeneric::CShader_vtbl *)&UnlitGeneric::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B830
// Name: UnlitGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnlitGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_119);
}

//------------------------------------------------------------------------------
// Address: 0x10068380
// Name: _dynamic_initializer_for__s_ConstructMe_unlittwotexture_vs20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlittwotexture_vs20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlittwotexture_vs20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x100683A0
// Name: _dynamic_initializer_for__s_ConstructMe_unlittwotexture_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlittwotexture_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlittwotexture_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100683C0
// Name: _dynamic_initializer_for__s_ConstructMe_unlittwotexture_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlittwotexture_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlittwotexture_ps20b_combos);
}
