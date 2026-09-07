// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/paintblob_dx9.cpp
// Functions: 60
// ============================================================

#include "materialsystem\stdshaders\paintblob_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x100205D0
// Name: public: virtual char const __near * paintblob::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall paintblob::CShader::GetFallbackShader(paintblob::CShader *this, IMaterialVar **params)
{
  return "paintblob_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x100205E0
// Name: public: virtual char const __near * paintblob::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall paintblob::CShader::GetName(paintblob::CShader *this)
{
  return s_Name_71;
}

//------------------------------------------------------------------------------
// Address: 0x100205F0
// Name: public: virtual int paintblob::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall paintblob::CShader::GetFlags(paintblob::CShader *this)
{
  return s_nFlags_89;
}

//------------------------------------------------------------------------------
// Address: 0x10020600
// Name: public: virtual int paintblob::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall paintblob::CShader::GetParamCount(paintblob::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_71.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10020610
// Name: public: void paintblob_dx9::CShader::SetupVarsIceSurface(struct PaintBlobVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall paintblob_dx9::CShader::SetupVarsIceSurface(paintblob_dx9::CShader *this, PaintBlobVars_t *info)
{
  info->m_nBackSurface = BACKSURFACE_1.m_Index;
  info->m_nBaseTexture = 6;
  info->m_nNormalMap = NORMALMAP_4.m_Index;
  info->m_nSpecMap = SPECMASKTEXTURE_1.m_Index;
  info->m_nLightWarpTexture = LIGHTWARPTEXTURE_3.m_Index;
  info->m_nFresnelWarpTexture = FRESNELWARPTEXTURE_1.m_Index;
  info->m_nOpacityTexture = OPACITYTEXTURE_1.m_Index;
  info->m_nEnvMap = ENVMAP_2.m_Index;
  info->m_nBumpStrength = BUMPSTRENGTH_1.m_Index;
  info->m_nFresnelBumpStrength = FRESNELBUMPSTRENGTH_1.m_Index;
  info->m_nUVScale = UVSCALE_1.m_Index;
  info->m_nInteriorEnable = INTERIOR_1.m_Index;
  info->m_nInteriorFogStrength = INTERIORFOGSTRENGTH_1.m_Index;
  info->m_nInteriorBackgroundBoost = INTERIORBACKGROUNDBOOST_1.m_Index;
  info->m_nInteriorAmbientScale = INTERIORAMBIENTSCALE_1.m_Index;
  info->m_nInteriorBackLightScale = INTERIORBACKLIGHTSCALE_1.m_Index;
  info->m_nInteriorRefractStrength = INTERIORREFRACTSTRENGTH_1.m_Index;
  info->m_nFresnelParams = TRANSLUCENTFRESNELMINMAXEXP_1.m_Index;
  info->m_nDiffuseScale = DIFFUSESCALE_0.m_Index;
  info->m_nSpecExp = PHONGEXPONENT_2.m_Index;
  info->m_nSpecScale = PHONGBOOST_2.m_Index;
  info->m_nSpecExp2 = PHONGEXPONENT2_1.m_Index;
  info->m_nSpecScale2 = PHONGBOOST2_1.m_Index;
  info->m_nRimLightExp = RIMLIGHTEXPONENT_2.m_Index;
  info->m_nRimLightScale = RIMLIGHTBOOST_2.m_Index;
  info->m_nBaseColorTint = BASECOLORTINT_1.m_Index;
  info->m_nUVProjOffset = UVPROJOFFSET_1.m_Index;
  info->m_nBBMin = BBMIN_1.m_Index;
  info->m_nBBMax = BBMAX_1.m_Index;
  info->m_nFlashlightTexture = 9;
  info->m_nFlashlightTextureFrame = 10;
  info->m_nBumpFrame = BUMPFRAME_5.m_Index;
  info->m_nContactShadows = CONTACTSHADOWS_1.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10020740
// Name: public: virtual void paintblob_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall paintblob_dx9::CShader::OnInitShaderParams(
        paintblob_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  PaintBlobVars_t info; // [esp+4h] [ebp-84h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  paintblob_dx9::CShader::SetupVarsIceSurface(this, &info);
  InitParamsPaintBlob(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x100207A0
// Name: public: virtual char const __near * paintblob_dx9::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall paintblob_dx9::CShader::GetFallbackShader(Blob_dx9::CShader *this, IMaterialVar **params)
{
  return g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 90 ? nullptr : "Wireframe";
}

//------------------------------------------------------------------------------
// Address: 0x100207C0
// Name: public: virtual char const __near * paintblob_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall paintblob_dx9::CShader::GetName(paintblob_dx9::CShader *this)
{
  return s_Name_72;
}

//------------------------------------------------------------------------------
// Address: 0x100207D0
// Name: public: virtual int paintblob_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall paintblob_dx9::CShader::GetFlags(paintblob_dx9::CShader *this)
{
  return s_nFlags_90;
}

//------------------------------------------------------------------------------
// Address: 0x100207E0
// Name: public: virtual void paintblob_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall paintblob_dx9::CShader::OnInitShaderInstance(
        paintblob_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  PaintBlobVars_t info; // [esp+4h] [ebp-84h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  paintblob_dx9::CShader::SetupVarsIceSurface(this, &info);
  InitPaintBlob(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10020830
// Name: public: virtual void paintblob_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall paintblob_dx9::CShader::OnDrawElements(
        paintblob_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  PaintBlobVars_t info; // [esp+4h] [ebp-84h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  paintblob_dx9::CShader::SetupVarsIceSurface(this, &info);
  DrawPaintBlob(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10020890
// Name: public: virtual int paintblob_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall paintblob_dx9::CShader::GetParamCount(paintblob_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_72.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100208A0
// Name: public: virtual struct ShaderParamInfo_t const __near & paintblob::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
paintblob::CShaderParam *__thiscall paintblob::CShader::GetParamInfo(paintblob::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_71.m_Memory.m_pMemory[param - ParamCount];
  else
    return (paintblob::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100208D0
// Name: public: virtual struct ShaderParamInfo_t const __near & paintblob_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *__thiscall paintblob_dx9::CShader::GetParamInfo(paintblob_dx9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_72.m_Memory.m_pMemory[param - ParamCount];
  else
    return (paintblob_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10020900
// Name: public: paintblob_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *__thiscall paintblob_dx9::CShaderParam::CShaderParam(
        paintblob_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  paintblob_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  paintblob_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_72.m_Size + 13;
  m_Size = s_ShaderParams_72.m_Size;
  v8 = s_ShaderParams_72.m_Size;
  if ( s_ShaderParams_72.m_Size + 1 > s_ShaderParams_72.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_72,
      num: s_ShaderParams_72.m_Size - s_ShaderParams_72.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_72.m_Size;
  }
  m_pMemory = s_ShaderParams_72.m_Memory.m_pMemory;
  s_ShaderParams_72.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_72.m_pElements = s_ShaderParams_72.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_72.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_72.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_72.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002FED0
// Name: public: virtual void paintblob::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall paintblob::CShader::OnInitShaderInstance(
        Aftershock::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10063B90
// Name: paintblob::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int paintblob::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: paintblob::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063BA0
// Name: paintblob::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *paintblob::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_71);
  s_ShaderInstance_71.__vftable = (paintblob::CShader_vtbl *)&paintblob::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063BC0
// Name: paintblob_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int paintblob_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: paintblob_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063BD0
// Name: paintblob_dx9::_dynamic_initializer_for__BACKSURFACE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__BACKSURFACE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &BACKSURFACE_1,
           pName: "$BACKSURFACE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0.0",
           pHelp: "specify that this is the back surface of the ice",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063BF0
// Name: paintblob_dx9::_dynamic_initializer_for__NORMALMAP__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__NORMALMAP__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &NORMALMAP_4,
           pName: "$NORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063C10
// Name: paintblob_dx9::_dynamic_initializer_for__SPECMASKTEXTURE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__SPECMASKTEXTURE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &SPECMASKTEXTURE_1,
           pName: "$SPECMASKTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "specular reflection mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063C30
// Name: paintblob_dx9::_dynamic_initializer_for__LIGHTWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__LIGHTWARPTEXTURE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &LIGHTWARPTEXTURE_3,
           pName: "$LIGHTWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for tinting scalar diffuse term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063C50
// Name: paintblob_dx9::_dynamic_initializer_for__FRESNELWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__FRESNELWARPTEXTURE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &FRESNELWARPTEXTURE_1,
           pName: "$FRESNELWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for controlling fresnel falloff",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063C70
// Name: paintblob_dx9::_dynamic_initializer_for__OPACITYTEXTURE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__OPACITYTEXTURE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &OPACITYTEXTURE_1,
           pName: "$OPACITYTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for controlling fresnel falloff",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063C90
// Name: paintblob_dx9::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__ENVMAP__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &ENVMAP_2,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "environment map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063CB0
// Name: paintblob_dx9::_dynamic_initializer_for__UVSCALE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__UVSCALE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &UVSCALE_1,
           pName: "$UVSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.02",
           pHelp: "uv projection scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063CD0
// Name: paintblob_dx9::_dynamic_initializer_for__BUMPSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__BUMPSTRENGTH__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &BUMPSTRENGTH_1,
           pName: "$BUMPSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "bump map strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063CF0
// Name: paintblob_dx9::_dynamic_initializer_for__FRESNELBUMPSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__FRESNELBUMPSTRENGTH__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &FRESNELBUMPSTRENGTH_1,
           pName: "$FRESNELBUMPSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "bump map strength for fresnel",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063D10
// Name: paintblob_dx9::_dynamic_initializer_for__TRANSLUCENTFRESNELMINMAXEXP__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__TRANSLUCENTFRESNELMINMAXEXP__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &TRANSLUCENTFRESNELMINMAXEXP_1,
           pName: "$TRANSLUCENTFRESNELMINMAXEXP",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0.8 1.0 1.0]",
           pHelp: "fresnel params",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063D30
// Name: paintblob_dx9::_dynamic_initializer_for__INTERIOR__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__INTERIOR__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &INTERIOR_1,
           pName: "$INTERIOR",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "Enable interior layer",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063D50
// Name: paintblob_dx9::_dynamic_initializer_for__INTERIORFOGSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__INTERIORFOGSTRENGTH__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORFOGSTRENGTH_1,
           pName: "$INTERIORFOGSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.06",
           pHelp: "fog strength (scales with thickness of the interior volume)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063D70
// Name: paintblob_dx9::_dynamic_initializer_for__INTERIORBACKGROUNDBOOST__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__INTERIORBACKGROUNDBOOST__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORBACKGROUNDBOOST_1,
           pName: "$INTERIORBACKGROUNDBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "7",
           pHelp: "boosts the brightness of bright background pixels",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063D90
// Name: paintblob_dx9::_dynamic_initializer_for__INTERIORAMBIENTSCALE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__INTERIORAMBIENTSCALE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORAMBIENTSCALE_1,
           pName: "$INTERIORAMBIENTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.3",
           pHelp: "scales ambient light in the interior volume",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063DB0
// Name: paintblob_dx9::_dynamic_initializer_for__INTERIORBACKLIGHTSCALE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__INTERIORBACKLIGHTSCALE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORBACKLIGHTSCALE_1,
           pName: "$INTERIORBACKLIGHTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.3",
           pHelp: "scales backlighting in the interior volume",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063DD0
// Name: paintblob_dx9::_dynamic_initializer_for__INTERIORREFRACTSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__INTERIORREFRACTSTRENGTH__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &INTERIORREFRACTSTRENGTH_1,
           pName: "$INTERIORREFRACTSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.015",
           pHelp: "strength of bumped refract of the background seen through the interior",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063DF0
// Name: paintblob_dx9::_dynamic_initializer_for__DIFFUSESCALE__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__DIFFUSESCALE__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &DIFFUSESCALE_0,
           pName: "$DIFFUSESCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063E10
// Name: paintblob_dx9::_dynamic_initializer_for__PHONGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__PHONGEXPONENT__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT_2,
           pName: "$PHONGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063E30
// Name: paintblob_dx9::_dynamic_initializer_for__PHONGBOOST__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__PHONGBOOST__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &PHONGBOOST_2,
           pName: "$PHONGBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063E50
// Name: paintblob_dx9::_dynamic_initializer_for__PHONGEXPONENT2__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__PHONGEXPONENT2__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT2_1,
           pName: "$PHONGEXPONENT2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063E70
// Name: paintblob_dx9::_dynamic_initializer_for__PHONGBOOST2__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__PHONGBOOST2__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &PHONGBOOST2_1,
           pName: "$PHONGBOOST2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063E90
// Name: paintblob_dx9::_dynamic_initializer_for__RIMLIGHTEXPONENT__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__RIMLIGHTEXPONENT__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &RIMLIGHTEXPONENT_2,
           pName: "$RIMLIGHTEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "rim light exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063EB0
// Name: paintblob_dx9::_dynamic_initializer_for__RIMLIGHTBOOST__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__RIMLIGHTBOOST__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &RIMLIGHTBOOST_2,
           pName: "$RIMLIGHTBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "rim light boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063ED0
// Name: paintblob_dx9::_dynamic_initializer_for__BASECOLORTINT__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__BASECOLORTINT__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &BASECOLORTINT_1,
           pName: "$BASECOLORTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1.0 1.0 1.0]",
           pHelp: "base texture tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063EF0
// Name: paintblob_dx9::_dynamic_initializer_for__UVPROJOFFSET__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__UVPROJOFFSET__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &UVPROJOFFSET_1,
           pName: "$UVPROJOFFSET",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: "Center for UV projection",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063F10
// Name: paintblob_dx9::_dynamic_initializer_for__BBMIN__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__BBMIN__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &BBMIN_1,
           pName: "$BBMIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063F30
// Name: paintblob_dx9::_dynamic_initializer_for__BBMAX__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__BBMAX__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &BBMAX_1,
           pName: "$BBMAX",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063F50
// Name: paintblob_dx9::_dynamic_initializer_for__CONTACTSHADOWS__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__CONTACTSHADOWS__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &CONTACTSHADOWS_1,
           pName: "$CONTACTSHADOWS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063F70
// Name: paintblob_dx9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
paintblob_dx9::CShaderParam *paintblob_dx9::_dynamic_initializer_for__BUMPFRAME__()
{
  return paintblob_dx9::CShaderParam::CShaderParam(
           this: &BUMPFRAME_5,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063F90
// Name: paintblob_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *paintblob_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_72);
  s_ShaderInstance_72.__vftable = (paintblob_dx9::CShader_vtbl *)&paintblob_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B480
// Name: paintblob::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl paintblob::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_71);
}

//------------------------------------------------------------------------------
// Address: 0x1006B490
// Name: paintblob_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl paintblob_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_72);
}

//------------------------------------------------------------------------------
// Address: 0x10063FB0
// Name: _dynamic_initializer_for__s_ConstructMe_paintblob_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_paintblob_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &paintblob_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063FD0
// Name: _dynamic_initializer_for__s_ConstructMe_paintblob_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_paintblob_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &paintblob_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064000
// Name: _dynamic_initializer_for__s_ConstructMe_parallaxtest_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_parallaxtest_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &parallaxtest_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064020
// Name: _dynamic_initializer_for__s_ConstructMe_parallaxtest_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_parallaxtest_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &parallaxtest_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10064040
// Name: _dynamic_initializer_for__mat_parallaxmapsamplesmin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_parallaxmapsamplesmin__()
{
  ConVar::ConVar(this: &mat_parallaxmapsamplesmin, pName: "mat_parallaxmapsamplesmin", pDefaultValue: "12", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_parallaxmapsamplesmin__);
}

//------------------------------------------------------------------------------
// Address: 0x10064070
// Name: _dynamic_initializer_for__mat_parallaxmapsamplesmax__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_parallaxmapsamplesmax__()
{
  ConVar::ConVar(this: &mat_parallaxmapsamplesmax, pName: "mat_parallaxmapsamplesmax", pDefaultValue: "50", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_parallaxmapsamplesmax__);
}

//------------------------------------------------------------------------------
// Address: 0x1006B4A0
// Name: _dynamic_atexit_destructor_for__mat_parallaxmapsamplesmin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_parallaxmapsamplesmin__()
{
  ConVar::~ConVar(this: &mat_parallaxmapsamplesmin);
}

//------------------------------------------------------------------------------
// Address: 0x1006B4B0
// Name: _dynamic_atexit_destructor_for__mat_parallaxmapsamplesmax__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_parallaxmapsamplesmax__()
{
  ConVar::~ConVar(this: &mat_parallaxmapsamplesmax);
}
