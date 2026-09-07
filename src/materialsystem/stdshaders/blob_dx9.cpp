// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/blob_dx9.cpp
// Functions: 73
// ============================================================

#include "materialsystem\stdshaders\blob_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10004A20
// Name: public: virtual char const __near * Blob::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Blob::CShader::GetFallbackShader(Blob::CShader *this, IMaterialVar **params)
{
  return "Blob_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x10004A30
// Name: public: virtual char const __near * Blob::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Blob::CShader::GetName(Blob::CShader *this)
{
  return s_Name_5;
}

//------------------------------------------------------------------------------
// Address: 0x10004A40
// Name: public: virtual int Blob::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Blob::CShader::GetFlags(Blob::CShader *this)
{
  return s_nFlags_50;
}

//------------------------------------------------------------------------------
// Address: 0x10004A50
// Name: public: virtual int Blob::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Blob::CShader::GetParamCount(Blob::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_5.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10004A60
// Name: public: void Blob_dx9::CShader::SetupVarsBlob(struct BlobVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Blob_dx9::CShader::SetupVarsBlob(Blob_dx9::CShader *this, BlobVars_t *info)
{
  info->m_nBackSurface = BACKSURFACE.m_Index;
  info->m_nBaseTexture = 6;
  info->m_nNormalMap = NORMALMAP_0.m_Index;
  info->m_nSpecMap = SPECMASKTEXTURE.m_Index;
  info->m_nLightWarpTexture = LIGHTWARPTEXTURE.m_Index;
  info->m_nFresnelWarpTexture = FRESNELWARPTEXTURE.m_Index;
  info->m_nOpacityTexture = OPACITYTEXTURE.m_Index;
  info->m_nBumpStrength = BUMPSTRENGTH.m_Index;
  info->m_nFresnelBumpStrength = FRESNELBUMPSTRENGTH.m_Index;
  info->m_nUVScale = UVSCALE.m_Index;
  info->m_nInteriorEnable = INTERIOR.m_Index;
  info->m_nInteriorFogStrength = INTERIORFOGSTRENGTH.m_Index;
  info->m_nInteriorFogLimit = INTERIORFOGLIMIT.m_Index;
  info->m_nInteriorFogNormalBoost = INTERIORFOGNORMALBOOST.m_Index;
  info->m_nInteriorBackgroundBoost = INTERIORBACKGROUNDBOOST.m_Index;
  info->m_nInteriorAmbientScale = INTERIORAMBIENTSCALE.m_Index;
  info->m_nInteriorBackLightScale = INTERIORBACKLIGHTSCALE.m_Index;
  info->m_nInteriorColor = INTERIORCOLOR.m_Index;
  info->m_nInteriorRefractStrength = INTERIORREFRACTSTRENGTH.m_Index;
  info->m_nInteriorRefractBlur = INTERIORREFRACTBLUR.m_Index;
  info->m_nFresnelParams = TRANSLUCENTFRESNELMINMAXEXP.m_Index;
  info->m_nDiffuseScale = DIFFUSEBOOST.m_Index;
  info->m_nSpecExp = PHONGEXPONENT.m_Index;
  info->m_nSpecScale = PHONGBOOST.m_Index;
  info->m_nSpecExp2 = PHONGEXPONENT2.m_Index;
  info->m_nSpecScale2 = PHONGBOOST2.m_Index;
  info->m_nRimLightExp = RIMLIGHTEXPONENT.m_Index;
  info->m_nRimLightScale = RIMLIGHTBOOST.m_Index;
  info->m_nBaseColorTint = BASECOLORTINT.m_Index;
  info->m_nSelfIllumFresnelEnable = SELFILLUMFRESNEL.m_Index;
  info->m_nSelfIllumFresnelParams = SELFILLUMFRESNELMINMAXEXP.m_Index;
  info->m_nSelfIllumTint = SELFILLUMTINT.m_Index;
  info->m_nUVProjOffset = UVPROJOFFSET.m_Index;
  info->m_nBBMin = BBMIN.m_Index;
  info->m_nBBMax = BBMAX.m_Index;
  info->m_nArmature = ARMATURE.m_Index;
  info->m_nFlashlightTexture = 9;
  info->m_nFlashlightTextureFrame = 10;
  info->m_nArmColorTint = ARMCOLOR.m_Index;
  info->m_nArmWiden = ARMWIDEN.m_Index;
  info->m_nArmWidthExp = ARMWIDTHEXP.m_Index;
  info->m_nArmWidthScale = ARMWIDTHSCALE.m_Index;
  info->m_nArmWidthBias = ARMWIDTHBIAS.m_Index;
  info->m_nAnimateArmPulses = ANIMATEARMPULSES.m_Index;
  info->m_nVolumeTex = VOLUMETEXTURETEST.m_Index;
  info->m_nBumpFrame = BUMPFRAME_0.m_Index;
  info->m_nGlowScale = GLOWSCALE.m_Index;
  info->m_nPulse = PULSE.m_Index;
  info->m_nContactShadows = CONTACTSHADOWS.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10004C50
// Name: public: virtual void Blob_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Blob_dx9::CShader::OnInitShaderParams(
        Blob_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  BlobVars_t info; // [esp+4h] [ebp-C4h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Blob_dx9::CShader::SetupVarsBlob(this, &info);
  InitParamsBlob(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10004CB0
// Name: public: virtual char const __near * Blob_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Blob_dx9::CShader::GetName(Blob_dx9::CShader *this)
{
  return s_Name_6;
}

//------------------------------------------------------------------------------
// Address: 0x10004CC0
// Name: public: virtual int Blob_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Blob_dx9::CShader::GetFlags(Blob_dx9::CShader *this)
{
  return s_nFlags_51;
}

//------------------------------------------------------------------------------
// Address: 0x10004CD0
// Name: public: virtual void Blob_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Blob_dx9::CShader::OnInitShaderInstance(
        Blob_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  BlobVars_t info; // [esp+4h] [ebp-C4h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Blob_dx9::CShader::SetupVarsBlob(this, &info);
  InitBlob(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10004D20
// Name: public: virtual void Blob_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Blob_dx9::CShader::OnDrawElements(
        Blob_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  BlobVars_t info; // [esp+4h] [ebp-C4h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Blob_dx9::CShader::SetupVarsBlob(this, &info);
  DrawBlob(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10004D80
// Name: public: virtual int Blob_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Blob_dx9::CShader::GetParamCount(Blob_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_6.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10004D90
// Name: public: virtual struct ShaderParamInfo_t const __near & Blob::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Blob::CShaderParam *__thiscall Blob::CShader::GetParamInfo(Blob::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_5.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Blob::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10004DC0
// Name: public: virtual struct ShaderParamInfo_t const __near & Blob_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *__thiscall Blob_dx9::CShader::GetParamInfo(Blob_dx9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_6.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Blob_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10004DF0
// Name: public: Blob_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *__thiscall Blob_dx9::CShaderParam::CShaderParam(
        Blob_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Blob_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Blob_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_6.m_Size + 13;
  m_Size = s_ShaderParams_6.m_Size;
  v8 = s_ShaderParams_6.m_Size;
  if ( s_ShaderParams_6.m_Size + 1 > s_ShaderParams_6.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_6,
      num: s_ShaderParams_6.m_Size - s_ShaderParams_6.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_6.m_Size;
  }
  m_pMemory = s_ShaderParams_6.m_Memory.m_pMemory;
  s_ShaderParams_6.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_6.m_pElements = s_ShaderParams_6.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_6.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_6.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_6.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005E480
// Name: Blob::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Blob::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Blob::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005E490
// Name: Blob::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Blob::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_5);
  s_ShaderInstance_5.__vftable = (Blob::CShader_vtbl *)&Blob::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005E4B0
// Name: Blob_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Blob_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Blob_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005E4C0
// Name: Blob_dx9::_dynamic_initializer_for__BACKSURFACE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__BACKSURFACE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &BACKSURFACE,
           pName: "$BACKSURFACE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0.0",
           pHelp: "specify that this is the back surface of the blob",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E4E0
// Name: Blob_dx9::_dynamic_initializer_for__NORMALMAP__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__NORMALMAP__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &NORMALMAP_0,
           pName: "$NORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E500
// Name: Blob_dx9::_dynamic_initializer_for__SPECMASKTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__SPECMASKTEXTURE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &SPECMASKTEXTURE,
           pName: "$SPECMASKTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "specular reflection mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E520
// Name: Blob_dx9::_dynamic_initializer_for__LIGHTWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__LIGHTWARPTEXTURE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &LIGHTWARPTEXTURE,
           pName: "$LIGHTWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for tinting scalar diffuse term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E540
// Name: Blob_dx9::_dynamic_initializer_for__FRESNELWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__FRESNELWARPTEXTURE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &FRESNELWARPTEXTURE,
           pName: "$FRESNELWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for controlling fresnel falloff",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E560
// Name: Blob_dx9::_dynamic_initializer_for__OPACITYTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__OPACITYTEXTURE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &OPACITYTEXTURE,
           pName: "$OPACITYTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for controlling fresnel falloff",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E580
// Name: Blob_dx9::_dynamic_initializer_for__UVSCALE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__UVSCALE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &UVSCALE,
           pName: "$UVSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.02",
           pHelp: "uv projection scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E5A0
// Name: Blob_dx9::_dynamic_initializer_for__BUMPSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__BUMPSTRENGTH__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &BUMPSTRENGTH,
           pName: "$BUMPSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "bump map strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E5C0
// Name: Blob_dx9::_dynamic_initializer_for__FRESNELBUMPSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__FRESNELBUMPSTRENGTH__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &FRESNELBUMPSTRENGTH,
           pName: "$FRESNELBUMPSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "bump map strength for fresnel",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E5E0
// Name: Blob_dx9::_dynamic_initializer_for__TRANSLUCENTFRESNELMINMAXEXP__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__TRANSLUCENTFRESNELMINMAXEXP__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &TRANSLUCENTFRESNELMINMAXEXP,
           pName: "$TRANSLUCENTFRESNELMINMAXEXP",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0.8 1.0 1.0]",
           pHelp: "fresnel params",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E600
// Name: Blob_dx9::_dynamic_initializer_for__INTERIOR__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIOR__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIOR,
           pName: "$INTERIOR",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "Enable interior layer",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E620
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORFOGSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORFOGSTRENGTH__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORFOGSTRENGTH,
           pName: "$INTERIORFOGSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.06",
           pHelp: "fog strength (scales with thickness of the interior volume)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E640
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORFOGLIMIT__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORFOGLIMIT__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORFOGLIMIT,
           pName: "$INTERIORFOGLIMIT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.8",
           pHelp: "fog opacity beyond the range of destination alpha depth (in low-precision depth mode)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E660
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORFOGNORMALBOOST__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORFOGNORMALBOOST__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORFOGNORMALBOOST,
           pName: "$INTERIORFOGNORMALBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "degree to boost interior thickness/fog by 'side-on'ness of vertex normals to the camera",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E680
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORBACKGROUNDBOOST__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORBACKGROUNDBOOST__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORBACKGROUNDBOOST,
           pName: "$INTERIORBACKGROUNDBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "7",
           pHelp: "boosts the brightness of bright background pixels",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E6A0
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORAMBIENTSCALE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORAMBIENTSCALE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORAMBIENTSCALE,
           pName: "$INTERIORAMBIENTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.3",
           pHelp: "scales ambient light in the interior volume",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E6C0
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORBACKLIGHTSCALE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORBACKLIGHTSCALE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORBACKLIGHTSCALE,
           pName: "$INTERIORBACKLIGHTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.3",
           pHelp: "scales backlighting in the interior volume",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E6E0
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORCOLOR__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORCOLOR__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORCOLOR,
           pName: "$INTERIORCOLOR",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0.7 0.5 0.45]",
           pHelp: "tints light in the interior volume",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E700
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORREFRACTSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORREFRACTSTRENGTH__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORREFRACTSTRENGTH,
           pName: "$INTERIORREFRACTSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.015",
           pHelp: "strength of bumped refract of the background seen through the interior",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E720
// Name: Blob_dx9::_dynamic_initializer_for__INTERIORREFRACTBLUR__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__INTERIORREFRACTBLUR__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORREFRACTBLUR,
           pName: "$INTERIORREFRACTBLUR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.2",
           pHelp: "strength of blur applied to the background seen through the interior",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E740
// Name: Blob_dx9::_dynamic_initializer_for__DIFFUSEBOOST__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__DIFFUSEBOOST__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &DIFFUSEBOOST,
           pName: "$DIFFUSEBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E760
// Name: Blob_dx9::_dynamic_initializer_for__PHONGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__PHONGEXPONENT__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT,
           pName: "$PHONGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E780
// Name: Blob_dx9::_dynamic_initializer_for__PHONGBOOST__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__PHONGBOOST__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &PHONGBOOST,
           pName: "$PHONGBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E7A0
// Name: Blob_dx9::_dynamic_initializer_for__PHONGEXPONENT2__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__PHONGEXPONENT2__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT2,
           pName: "$PHONGEXPONENT2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E7C0
// Name: Blob_dx9::_dynamic_initializer_for__PHONGBOOST2__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__PHONGBOOST2__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &PHONGBOOST2,
           pName: "$PHONGBOOST2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E7E0
// Name: Blob_dx9::_dynamic_initializer_for__RIMLIGHTEXPONENT__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__RIMLIGHTEXPONENT__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &RIMLIGHTEXPONENT,
           pName: "$RIMLIGHTEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "rim light exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E800
// Name: Blob_dx9::_dynamic_initializer_for__RIMLIGHTBOOST__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__RIMLIGHTBOOST__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &RIMLIGHTBOOST,
           pName: "$RIMLIGHTBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "rim light boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E820
// Name: Blob_dx9::_dynamic_initializer_for__BASECOLORTINT__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__BASECOLORTINT__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &BASECOLORTINT,
           pName: "$BASECOLORTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1.0 1.0 1.0]",
           pHelp: "base texture tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E840
// Name: Blob_dx9::_dynamic_initializer_for__SELFILLUMFRESNEL__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__SELFILLUMFRESNEL__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &SELFILLUMFRESNEL,
           pName: "$SELFILLUMFRESNEL",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "enable self illum fresnel term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E860
// Name: Blob_dx9::_dynamic_initializer_for__SELFILLUMFRESNELMINMAXEXP__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__SELFILLUMFRESNELMINMAXEXP__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &SELFILLUMFRESNELMINMAXEXP,
           pName: "$SELFILLUMFRESNELMINMAXEXP",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0.7 0.5 0.45]",
           pHelp: "min max exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E880
// Name: Blob_dx9::_dynamic_initializer_for__SELFILLUMTINT__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__SELFILLUMTINT__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &SELFILLUMTINT,
           pName: "$SELFILLUMTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0.7 0.5 0.45]",
           pHelp: "selfillum color tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E8A0
// Name: Blob_dx9::_dynamic_initializer_for__UVPROJOFFSET__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__UVPROJOFFSET__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &UVPROJOFFSET,
           pName: "$UVPROJOFFSET",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: "Center for UV projection",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E8C0
// Name: Blob_dx9::_dynamic_initializer_for__BBMIN__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__BBMIN__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &BBMIN,
           pName: "$BBMIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E8E0
// Name: Blob_dx9::_dynamic_initializer_for__BBMAX__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__BBMAX__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &BBMAX,
           pName: "$BBMAX",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E900
// Name: Blob_dx9::_dynamic_initializer_for__ARMATURE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__ARMATURE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &ARMATURE,
           pName: "$ARMATURE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "armature",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E920
// Name: Blob_dx9::_dynamic_initializer_for__ARMCOLOR__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__ARMCOLOR__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &ARMCOLOR,
           pName: "$ARMCOLOR",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1 1 1]",
           pHelp: "arm color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E940
// Name: Blob_dx9::_dynamic_initializer_for__ARMWIDEN__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__ARMWIDEN__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &ARMWIDEN,
           pName: "$ARMWIDEN",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "widen arms at end instead of taper",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E960
// Name: Blob_dx9::_dynamic_initializer_for__ARMWIDTHEXP__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__ARMWIDTHEXP__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &ARMWIDTHEXP,
           pName: "$ARMWIDTHEXP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E980
// Name: Blob_dx9::_dynamic_initializer_for__ARMWIDTHSCALE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__ARMWIDTHSCALE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &ARMWIDTHSCALE,
           pName: "$ARMWIDTHSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E9A0
// Name: Blob_dx9::_dynamic_initializer_for__ARMWIDTHBIAS__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__ARMWIDTHBIAS__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &ARMWIDTHBIAS,
           pName: "$ARMWIDTHBIAS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E9C0
// Name: Blob_dx9::_dynamic_initializer_for__ANIMATEARMPULSES__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__ANIMATEARMPULSES__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &ANIMATEARMPULSES,
           pName: "$ANIMATEARMPULSES",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005E9E0
// Name: Blob_dx9::_dynamic_initializer_for__GLOWSCALE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__GLOWSCALE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &GLOWSCALE,
           pName: "$GLOWSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4",
           pHelp: "Scale value applied to self-illum vertex colours",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EA00
// Name: Blob_dx9::_dynamic_initializer_for__PULSE__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__PULSE__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &PULSE,
           pName: "$PULSE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EA20
// Name: Blob_dx9::_dynamic_initializer_for__CONTACTSHADOWS__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__CONTACTSHADOWS__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &CONTACTSHADOWS,
           pName: "$CONTACTSHADOWS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EA40
// Name: Blob_dx9::_dynamic_initializer_for__VOLUMETEXTURETEST__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__VOLUMETEXTURETEST__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &VOLUMETEXTURETEST,
           pName: "$VOLUMETEXTURETEST",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EA60
// Name: Blob_dx9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
Blob_dx9::CShaderParam *Blob_dx9::_dynamic_initializer_for__BUMPFRAME__()
{
  return Blob_dx9::CShaderParam::CShaderParam(
           this: &BUMPFRAME_0,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EA80
// Name: Blob_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Blob_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_6);
  s_ShaderInstance_6.__vftable = (Blob_dx9::CShader_vtbl *)&Blob_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AEC0
// Name: Blob::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Blob::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_5);
}

//------------------------------------------------------------------------------
// Address: 0x1006AED0
// Name: Blob_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Blob_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_6);
}

//------------------------------------------------------------------------------
// Address: 0x1005EAA0
// Name: _dynamic_initializer_for__s_ConstructMe_blob_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_blob_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &blob_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EAC0
// Name: _dynamic_initializer_for__s_ConstructMe_blob_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_blob_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &blob_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EAE0
// Name: _dynamic_initializer_for__s_ConstructMe_blob_arm_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_blob_arm_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &blob_arm_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EB00
// Name: _dynamic_initializer_for__s_ConstructMe_blob_arm_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_blob_arm_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &blob_arm_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EB20
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___1()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_1);
}

//------------------------------------------------------------------------------
// Address: 0x1005EB40
// Name: _dynamic_initializer_for__s_ConstructMe_Bloom_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Bloom_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Bloom_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EB60
// Name: _dynamic_initializer_for__s_ConstructMe_Bloom_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Bloom_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Bloom_ps20b_combos);
}
