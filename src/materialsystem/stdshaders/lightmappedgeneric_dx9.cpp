// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/lightmappedgeneric_dx9.cpp
// Functions: 67
// ============================================================

#include "materialsystem\stdshaders\lightmappedgeneric_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10016F70
// Name: public: void LightmappedGeneric::CShader::SetupVars(struct LightmappedGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightmappedGeneric::CShader::SetupVars(
        LightmappedGeneric::CShader *this,
        LightmappedGeneric_DX9_Vars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nBaseTextureFrame = 7;
  info->m_nBaseTextureTransform = 8;
  info->m_nSelfIllumTint = SELFILLUMTINT_0.m_Index;
  info->m_nDetail = DETAIL.m_Index;
  info->m_nDetailFrame = DETAILFRAME.m_Index;
  info->m_nDetailScale = DETAILSCALE.m_Index;
  info->m_nDetailTextureCombineMode = DETAILBLENDMODE.m_Index;
  info->m_nDetailTextureBlendFactor = DETAILBLENDFACTOR.m_Index;
  info->m_nDetailTint = DETAILTINT.m_Index;
  info->m_nEnvmap = ENVMAP_1.m_Index;
  info->m_nEnvmapFrame = ENVMAPFRAME.m_Index;
  info->m_nEnvmapMask = ENVMAPMASK.m_Index;
  info->m_nEnvmapMaskFrame = ENVMAPMASKFRAME.m_Index;
  info->m_nEnvmapMaskTransform = ENVMAPMASKTRANSFORM.m_Index;
  info->m_nEnvmapTint = ENVMAPTINT_0.m_Index;
  info->m_nBumpmap = BUMPMAP_0.m_Index;
  info->m_nBumpFrame = BUMPFRAME_3.m_Index;
  info->m_nBumpTransform = BUMPTRANSFORM_1.m_Index;
  info->m_nEnvmapContrast = ENVMAPCONTRAST.m_Index;
  info->m_nEnvmapSaturation = ENVMAPSATURATION.m_Index;
  info->m_nFresnelReflection = FRESNELREFLECTION_0.m_Index;
  info->m_nNoDiffuseBumpLighting = NODIFFUSEBUMPLIGHTING.m_Index;
  info->m_nBumpmap2 = BUMPMAP2.m_Index;
  info->m_nBumpFrame2 = BUMPFRAME2.m_Index;
  info->m_nBumpTransform2 = BUMPTRANSFORM2.m_Index;
  info->m_nBumpMask = BUMPMASK.m_Index;
  info->m_nBaseTexture2 = BASETEXTURE2.m_Index;
  info->m_nBaseTexture2Frame = FRAME2.m_Index;
  info->m_nFlashlightTexture = 9;
  info->m_nFlashlightTextureFrame = 10;
  info->m_nBlendModulateTexture = BLENDMODULATETEXTURE.m_Index;
  info->m_nSelfShadowedBumpFlag = SSBUMP.m_Index;
  info->m_nSeamlessMappingScale = SEAMLESS_SCALE.m_Index;
  info->m_nAlphaTestReference = ALPHATESTREFERENCE_0.m_Index;
  info->m_nShaderSrgbRead360 = SHADERSRGBREAD360.m_Index;
  info->m_nEnvMapLightScale = ENVMAPLIGHTSCALE.m_Index;
  info->m_nPaintSplatNormal = PAINTSPLATNORMALMAP.m_Index;
  info->m_nPaintSplatBubbleLayout = PAINTSPLATBUBBLELAYOUT.m_Index;
  info->m_nPaintSplatBubble = PAINTSPLATBUBBLE.m_Index;
  info->m_nPaintEnvmap = PAINTENVMAP.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10017100
// Name: public: virtual void LightmappedGeneric::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightmappedGeneric::CShader::OnInitShaderParams(
        LightmappedGeneric::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  LightmappedGeneric::CShader::SetupVars(this, info: &s_info);
  InitParamsLightmappedGeneric_DX9(pShader: this, params, pMaterialName, info: &s_info);
}

//------------------------------------------------------------------------------
// Address: 0x10017130
// Name: public: virtual char const __near * LightmappedGeneric::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall LightmappedGeneric::CShader::GetName(LightmappedGeneric::CShader *this)
{
  return s_Name_51;
}

//------------------------------------------------------------------------------
// Address: 0x10017140
// Name: public: virtual int LightmappedGeneric::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightmappedGeneric::CShader::GetFlags(LightmappedGeneric::CShader *this)
{
  return s_nFlags_74;
}

//------------------------------------------------------------------------------
// Address: 0x10017150
// Name: public: virtual void LightmappedGeneric::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightmappedGeneric::CShader::OnInitShaderInstance(
        LightmappedGeneric::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  LightmappedGeneric::CShader::SetupVars(this, info: &s_info);
  InitLightmappedGeneric_DX9(pShader: this, params, info: &s_info);
}

//------------------------------------------------------------------------------
// Address: 0x10017180
// Name: public: virtual void LightmappedGeneric::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightmappedGeneric::CShader::OnDrawElements(
        LightmappedGeneric::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  if ( CBaseShader::IsRenderingPaint(this, params) )
    DrawLightmappedPaint_DX9(pShader: this, params, pShaderAPI, pShaderShadow, info: &s_info, pContextDataPtr);
  else
    DrawLightmappedGeneric_DX9(pShader: this, params, pShaderAPI, pShaderShadow, info: &s_info, pContextDataPtr);
}

//------------------------------------------------------------------------------
// Address: 0x100171D0
// Name: public: virtual int LightmappedGeneric::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightmappedGeneric::CShader::GetParamCount(LightmappedGeneric::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_51.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100171E0
// Name: public: virtual struct ShaderParamInfo_t const __near & LightmappedGeneric::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *__thiscall LightmappedGeneric::CShader::GetParamInfo(
        LightmappedGeneric::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_51.m_Memory.m_pMemory[param - ParamCount];
  else
    return (LightmappedGeneric::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10017210
// Name: public: LightmappedGeneric::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *__thiscall LightmappedGeneric::CShaderParam::CShaderParam(
        LightmappedGeneric::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  LightmappedGeneric::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  LightmappedGeneric::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_51.m_Size + 13;
  m_Size = s_ShaderParams_51.m_Size;
  v8 = s_ShaderParams_51.m_Size;
  if ( s_ShaderParams_51.m_Size + 1 > s_ShaderParams_51.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_51,
      num: s_ShaderParams_51.m_Size - s_ShaderParams_51.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_51.m_Size;
  }
  m_pMemory = s_ShaderParams_51.m_Memory.m_pMemory;
  s_ShaderParams_51.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_51.m_pElements = s_ShaderParams_51.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_51.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_51.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_51.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100624D0
// Name: LightmappedGeneric::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int LightmappedGeneric::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: LightmappedGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100624E0
// Name: LightmappedGeneric::_dynamic_initializer_for__SELFILLUMTINT__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__SELFILLUMTINT__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &SELFILLUMTINT_0,
           pName: "$SELFILLUMTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Self-illumination tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062500
// Name: LightmappedGeneric::_dynamic_initializer_for__DETAIL__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__DETAIL__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &DETAIL,
           pName: "$DETAIL",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/detail",
           pHelp: "detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062520
// Name: LightmappedGeneric::_dynamic_initializer_for__DETAILFRAME__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__DETAILFRAME__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &DETAILFRAME,
           pName: "$DETAILFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $detail",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062540
// Name: LightmappedGeneric::_dynamic_initializer_for__DETAILSCALE__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__DETAILSCALE__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &DETAILSCALE,
           pName: "$DETAILSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4",
           pHelp: "scale of the detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062560
// Name: LightmappedGeneric::_dynamic_initializer_for__DETAILBLENDMODE__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__DETAILBLENDMODE__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &DETAILBLENDMODE,
           pName: "$DETAILBLENDMODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "mode for combining detail texture with base. 0=normal, 1= additive, 2=alpha blend detail over base, 3=crossfade",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062580
// Name: LightmappedGeneric::_dynamic_initializer_for__DETAILBLENDFACTOR__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__DETAILBLENDFACTOR__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &DETAILBLENDFACTOR,
           pName: "$DETAILBLENDFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "blend amount for detail texture.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100625A0
// Name: LightmappedGeneric::_dynamic_initializer_for__DETAILTINT__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__DETAILTINT__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &DETAILTINT,
           pName: "$DETAILTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "detail texture tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100625C0
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAP__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAP_1,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100625E0
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAPFRAME__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPFRAME,
           pName: "$ENVMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062600
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAPMASK__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAPMASK__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASK,
           pName: "$ENVMAPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_envmask",
           pHelp: "envmap mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062620
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAPMASKFRAME__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAPMASKFRAME__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASKFRAME,
           pName: "$ENVMAPMASKFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062640
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPMASKTRANSFORM,
           pName: "$ENVMAPMASKTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$envmapmask texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062660
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAPTINT__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAPTINT__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPTINT_0,
           pName: "$ENVMAPTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "envmap tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062680
// Name: LightmappedGeneric::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BUMPMAP__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BUMPMAP_0,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100626A0
// Name: LightmappedGeneric::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BUMPFRAME__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BUMPFRAME_3,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100626C0
// Name: LightmappedGeneric::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_1,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100626E0
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAPCONTRAST__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAPCONTRAST__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPCONTRAST,
           pName: "$ENVMAPCONTRAST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "contrast 0 == normal 1 == color*color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062700
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAPSATURATION__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAPSATURATION__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPSATURATION,
           pName: "$ENVMAPSATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "saturation 0 == greyscale 1 == normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062720
// Name: LightmappedGeneric::_dynamic_initializer_for__FRESNELREFLECTION__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__FRESNELREFLECTION__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &FRESNELREFLECTION_0,
           pName: "$FRESNELREFLECTION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "1.0 == mirror, 0.0 == water",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062740
// Name: LightmappedGeneric::_dynamic_initializer_for__NODIFFUSEBUMPLIGHTING__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__NODIFFUSEBUMPLIGHTING__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &NODIFFUSEBUMPLIGHTING,
           pName: "$NODIFFUSEBUMPLIGHTING",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "0 == Use diffuse bump lighting, 1 = No diffuse bump lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062760
// Name: LightmappedGeneric::_dynamic_initializer_for__BUMPMAP2__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BUMPMAP2__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BUMPMAP2,
           pName: "$BUMPMAP2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader3_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062780
// Name: LightmappedGeneric::_dynamic_initializer_for__BUMPFRAME2__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BUMPFRAME2__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BUMPFRAME2,
           pName: "$BUMPFRAME2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100627A0
// Name: LightmappedGeneric::_dynamic_initializer_for__BUMPTRANSFORM2__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BUMPTRANSFORM2__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM2,
           pName: "$BUMPTRANSFORM2",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100627C0
// Name: LightmappedGeneric::_dynamic_initializer_for__BUMPMASK__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BUMPMASK__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BUMPMASK,
           pName: "$BUMPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader3_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100627E0
// Name: LightmappedGeneric::_dynamic_initializer_for__BASETEXTURE2__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BASETEXTURE2__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BASETEXTURE2,
           pName: "$BASETEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/lightmappedtexture",
           pHelp: "Blended texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062800
// Name: LightmappedGeneric::_dynamic_initializer_for__FRAME2__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__FRAME2__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &FRAME2,
           pName: "$FRAME2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $basetexture2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062820
// Name: LightmappedGeneric::_dynamic_initializer_for__BLENDMODULATETEXTURE__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__BLENDMODULATETEXTURE__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &BLENDMODULATETEXTURE,
           pName: "$BLENDMODULATETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "texture to use r/g channels for blend range for",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062840
// Name: LightmappedGeneric::_dynamic_initializer_for__SSBUMP__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__SSBUMP__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &SSBUMP,
           pName: "$SSBUMP",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "whether or not to use alternate bumpmap format with height",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062860
// Name: LightmappedGeneric::_dynamic_initializer_for__SEAMLESS_SCALE__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__SEAMLESS_SCALE__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &SEAMLESS_SCALE,
           pName: "$SEAMLESS_SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Scale factor for 'seamless' texture mapping. 0 means to use ordinary mapping",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062880
// Name: LightmappedGeneric::_dynamic_initializer_for__ALPHATESTREFERENCE__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ALPHATESTREFERENCE__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ALPHATESTREFERENCE_0,
           pName: "$ALPHATESTREFERENCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100628A0
// Name: LightmappedGeneric::_dynamic_initializer_for__SHADERSRGBREAD360__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__SHADERSRGBREAD360__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &SHADERSRGBREAD360,
           pName: "$SHADERSRGBREAD360",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Simulate srgb read in shader code",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100628C0
// Name: LightmappedGeneric::_dynamic_initializer_for__ENVMAPLIGHTSCALE__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__ENVMAPLIGHTSCALE__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &ENVMAPLIGHTSCALE,
           pName: "$ENVMAPLIGHTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "How much the lightmap effects environment map reflection, 0.0 is off, 1.0 will allow complete blackness of th"
           "e environment map if the lightmap is black",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100628E0
// Name: LightmappedGeneric::_dynamic_initializer_for__PAINTSPLATNORMALMAP__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__PAINTSPLATNORMALMAP__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &PAINTSPLATNORMALMAP,
           pName: "$PAINTSPLATNORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "paint/splatnormal_default",
           pHelp: "The paint splat normal map to use when paint is enabled on the surface",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062900
// Name: LightmappedGeneric::_dynamic_initializer_for__PAINTSPLATBUBBLELAYOUT__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__PAINTSPLATBUBBLELAYOUT__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &PAINTSPLATBUBBLELAYOUT,
           pName: "$PAINTSPLATBUBBLELAYOUT",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "paint/bubblelayout",
           pHelp: "The layout texture which defines the distribution of bubbles in the paint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062920
// Name: LightmappedGeneric::_dynamic_initializer_for__PAINTSPLATBUBBLE__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__PAINTSPLATBUBBLE__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &PAINTSPLATBUBBLE,
           pName: "$PAINTSPLATBUBBLE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "paint/bubble",
           pHelp: "The normal mapped texture of a single bubble",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062940
// Name: LightmappedGeneric::_dynamic_initializer_for__PAINTENVMAP__
// Source: json
//------------------------------------------------------------------------------
LightmappedGeneric::CShaderParam *LightmappedGeneric::_dynamic_initializer_for__PAINTENVMAP__()
{
  return LightmappedGeneric::CShaderParam::CShaderParam(
           this: &PAINTENVMAP,
           pName: "$PAINTENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "paint/paint_envmap_hdr",
           pHelp: "Envmap that is consistent across all surfaces",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062960
// Name: LightmappedGeneric::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *LightmappedGeneric::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_51);
  s_ShaderInstance_51.__vftable = (LightmappedGeneric::CShader_vtbl *)&LightmappedGeneric::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B2D0
// Name: LightmappedGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl LightmappedGeneric::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_51);
}

//------------------------------------------------------------------------------
// Address: 0x10062980
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedgeneric_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100629A0
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedgeneric_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100629C0
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedgeneric_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100629E0
// Name: _dynamic_initializer_for__mat_disable_fancy_blending__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_disable_fancy_blending__()
{
  ConVar::ConVar(this: &mat_disable_fancy_blending, pName: "mat_disable_fancy_blending", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_disable_fancy_blending__);
}

//------------------------------------------------------------------------------
// Address: 0x10062A10
// Name: _dynamic_initializer_for__mat_ambient_light_r__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_r__()
{
  ConVar::ConVar(this: &mat_ambient_light_r, pName: "mat_ambient_light_r", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_r__);
}

//------------------------------------------------------------------------------
// Address: 0x10062A40
// Name: _dynamic_initializer_for__mat_ambient_light_g__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_g__()
{
  ConVar::ConVar(this: &mat_ambient_light_g, pName: "mat_ambient_light_g", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_g__);
}

//------------------------------------------------------------------------------
// Address: 0x10062A70
// Name: _dynamic_initializer_for__mat_ambient_light_b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_b__()
{
  ConVar::ConVar(this: &mat_ambient_light_b, pName: "mat_ambient_light_b", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_b__);
}

//------------------------------------------------------------------------------
// Address: 0x10062AA0
// Name: _dynamic_initializer_for__mat_force_vertexfog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_vertexfog__()
{
  ConVar::ConVar(this: &mat_force_vertexfog, pName: "mat_force_vertexfog", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_force_vertexfog__);
}

//------------------------------------------------------------------------------
// Address: 0x10062AD0
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_vs20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedgeneric_vs20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedgeneric_vs20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x10062AF0
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedpaint_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedpaint_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedpaint_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10062B10
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedpaint_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedpaint_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedpaint_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10062B30
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedreflective_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedreflective_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedreflective_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10062B50
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedreflective_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedreflective_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedreflective_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10062B70
// Name: _dynamic_initializer_for__s_ConstructMe_lightmappedreflective_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightmappedreflective_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightmappedreflective_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006B2E0
// Name: _dynamic_atexit_destructor_for__mat_disable_fancy_blending__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_disable_fancy_blending__()
{
  ConVar::~ConVar(this: &mat_disable_fancy_blending);
}

//------------------------------------------------------------------------------
// Address: 0x1006B2F0
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_r__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_r__()
{
  ConVar::~ConVar(this: &mat_ambient_light_r);
}

//------------------------------------------------------------------------------
// Address: 0x1006B300
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_g__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_g__()
{
  ConVar::~ConVar(this: &mat_ambient_light_g);
}

//------------------------------------------------------------------------------
// Address: 0x1006B310
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_b__()
{
  ConVar::~ConVar(this: &mat_ambient_light_b);
}

//------------------------------------------------------------------------------
// Address: 0x1006B320
// Name: _dynamic_atexit_destructor_for__mat_force_vertexfog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_vertexfog__()
{
  ConVar::~ConVar(this: &mat_force_vertexfog);
}
