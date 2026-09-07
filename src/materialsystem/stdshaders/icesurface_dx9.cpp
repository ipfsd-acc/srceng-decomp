// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/icesurface_dx9.cpp
// Functions: 60
// ============================================================

#include "materialsystem\stdshaders\icesurface_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10015030
// Name: public: virtual char const __near * IceSurface::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IceSurface::CShader::GetFallbackShader(IceSurface::CShader *this, IMaterialVar **params)
{
  return "IceSurface_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x10015040
// Name: public: virtual char const __near * IceSurface::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IceSurface::CShader::GetName(IceSurface::CShader *this)
{
  return s_Name_48;
}

//------------------------------------------------------------------------------
// Address: 0x10015050
// Name: public: virtual int IceSurface::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IceSurface::CShader::GetFlags(IceSurface::CShader *this)
{
  return s_nFlags_72;
}

//------------------------------------------------------------------------------
// Address: 0x10015060
// Name: public: virtual int IceSurface::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IceSurface::CShader::GetParamCount(IceSurface::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_48.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10015070
// Name: public: void IceSurface_dx9::CShader::SetupVarsIceSurface(struct IceSurfaceVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceSurface_dx9::CShader::SetupVarsIceSurface(IceSurface_dx9::CShader *this, IceSurfaceVars_t *info)
{
  info->m_nBackSurface = BACKSURFACE_0.m_Index;
  info->m_nBaseTexture = 6;
  info->m_nNormalMap = NORMALMAP_2.m_Index;
  info->m_nSpecMap = SPECMASKTEXTURE_0.m_Index;
  info->m_nLightWarpTexture = LIGHTWARPTEXTURE_2.m_Index;
  info->m_nFresnelWarpTexture = FRESNELWARPTEXTURE_0.m_Index;
  info->m_nOpacityTexture = OPACITYTEXTURE_0.m_Index;
  info->m_nEnvMap = ENVMAP_0.m_Index;
  info->m_nBumpStrength = BUMPSTRENGTH_0.m_Index;
  info->m_nFresnelBumpStrength = FRESNELBUMPSTRENGTH_0.m_Index;
  info->m_nUVScale = UVSCALE_0.m_Index;
  info->m_nInteriorEnable = INTERIOR_0.m_Index;
  info->m_nInteriorFogStrength = INTERIORFOGSTRENGTH_0.m_Index;
  info->m_nInteriorFogLimit = INTERIORFOGLIMIT_0.m_Index;
  info->m_nInteriorFogNormalBoost = INTERIORFOGNORMALBOOST_0.m_Index;
  info->m_nInteriorBackgroundBoost = INTERIORBACKGROUNDBOOST_0.m_Index;
  info->m_nInteriorAmbientScale = INTERIORAMBIENTSCALE_0.m_Index;
  info->m_nInteriorBackLightScale = INTERIORBACKLIGHTSCALE_0.m_Index;
  info->m_nInteriorColor = INTERIORCOLOR_0.m_Index;
  info->m_nInteriorRefractStrength = INTERIORREFRACTSTRENGTH_0.m_Index;
  info->m_nInteriorRefractBlur = INTERIORREFRACTBLUR_0.m_Index;
  info->m_nFresnelParams = TRANSLUCENTFRESNELMINMAXEXP_0.m_Index;
  info->m_nDiffuseScale = DIFFUSESCALE.m_Index;
  info->m_nSpecExp = PHONGEXPONENT_1.m_Index;
  info->m_nSpecScale = PHONGBOOST_1.m_Index;
  info->m_nSpecExp2 = PHONGEXPONENT2_0.m_Index;
  info->m_nSpecScale2 = PHONGBOOST2_0.m_Index;
  info->m_nRimLightExp = RIMLIGHTEXPONENT_1.m_Index;
  info->m_nRimLightScale = RIMLIGHTBOOST_1.m_Index;
  info->m_nBaseColorTint = BASECOLORTINT_0.m_Index;
  info->m_nEnvMapTint = ENVMAPTINT.m_Index;
  info->m_nUVProjOffset = UVPROJOFFSET_0.m_Index;
  info->m_nBBMin = BBMIN_0.m_Index;
  info->m_nBBMax = BBMAX_0.m_Index;
  info->m_nFlashlightTexture = 9;
  info->m_nFlashlightTextureFrame = 10;
  info->m_nBumpFrame = BUMPFRAME_2.m_Index;
  info->m_nContactShadows = CONTACTSHADOWS_0.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x100151E0
// Name: public: virtual void IceSurface_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceSurface_dx9::CShader::OnInitShaderParams(
        IceSurface_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  IceSurfaceVars_t info; // [esp+4h] [ebp-98h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  IceSurface_dx9::CShader::SetupVarsIceSurface(this, &info);
  InitParamsIceSurface(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10015240
// Name: public: virtual char const __near * IceSurface_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IceSurface_dx9::CShader::GetName(IceSurface_dx9::CShader *this)
{
  return s_Name_49;
}

//------------------------------------------------------------------------------
// Address: 0x10015250
// Name: public: virtual int IceSurface_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IceSurface_dx9::CShader::GetFlags(IceSurface_dx9::CShader *this)
{
  return s_nFlags_73;
}

//------------------------------------------------------------------------------
// Address: 0x10015260
// Name: public: virtual void IceSurface_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceSurface_dx9::CShader::OnInitShaderInstance(
        IceSurface_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  IceSurfaceVars_t info; // [esp+4h] [ebp-98h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  IceSurface_dx9::CShader::SetupVarsIceSurface(this, &info);
  InitIceSurface(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x100152B0
// Name: public: virtual void IceSurface_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IceSurface_dx9::CShader::OnDrawElements(
        IceSurface_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IceSurfaceVars_t info; // [esp+4h] [ebp-98h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  IceSurface_dx9::CShader::SetupVarsIceSurface(this, &info);
  DrawIceSurface(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10015310
// Name: public: virtual int IceSurface_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IceSurface_dx9::CShader::GetParamCount(IceSurface_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_49.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10015320
// Name: public: virtual struct ShaderParamInfo_t const __near & IceSurface::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
IceSurface::CShaderParam *__thiscall IceSurface::CShader::GetParamInfo(IceSurface::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_48.m_Memory.m_pMemory[param - ParamCount];
  else
    return (IceSurface::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10015350
// Name: public: virtual struct ShaderParamInfo_t const __near & IceSurface_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *__thiscall IceSurface_dx9::CShader::GetParamInfo(
        IceSurface_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_49.m_Memory.m_pMemory[param - ParamCount];
  else
    return (IceSurface_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10015380
// Name: public: IceSurface_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *__thiscall IceSurface_dx9::CShaderParam::CShaderParam(
        IceSurface_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  IceSurface_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  IceSurface_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_49.m_Size + 13;
  m_Size = s_ShaderParams_49.m_Size;
  v8 = s_ShaderParams_49.m_Size;
  if ( s_ShaderParams_49.m_Size + 1 > s_ShaderParams_49.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_49,
      num: s_ShaderParams_49.m_Size - s_ShaderParams_49.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_49.m_Size;
  }
  m_pMemory = s_ShaderParams_49.m_Memory.m_pMemory;
  s_ShaderParams_49.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_49.m_pElements = s_ShaderParams_49.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_49.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_49.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_49.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061F00
// Name: IceSurface::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int IceSurface::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: IceSurface::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061F10
// Name: IceSurface::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *IceSurface::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_48);
  s_ShaderInstance_48.__vftable = (IceSurface::CShader_vtbl *)&IceSurface::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061F30
// Name: IceSurface_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int IceSurface_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: IceSurface_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061F40
// Name: IceSurface_dx9::_dynamic_initializer_for__BACKSURFACE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__BACKSURFACE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &BACKSURFACE_0,
           pName: "$BACKSURFACE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0.0",
           pHelp: "specify that this is the back surface of the ice",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061F60
// Name: IceSurface_dx9::_dynamic_initializer_for__NORMALMAP__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__NORMALMAP__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &NORMALMAP_2,
           pName: "$NORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061F80
// Name: IceSurface_dx9::_dynamic_initializer_for__SPECMASKTEXTURE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__SPECMASKTEXTURE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &SPECMASKTEXTURE_0,
           pName: "$SPECMASKTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "specular reflection mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061FA0
// Name: IceSurface_dx9::_dynamic_initializer_for__LIGHTWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__LIGHTWARPTEXTURE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &LIGHTWARPTEXTURE_2,
           pName: "$LIGHTWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for tinting scalar diffuse term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061FC0
// Name: IceSurface_dx9::_dynamic_initializer_for__FRESNELWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__FRESNELWARPTEXTURE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &FRESNELWARPTEXTURE_0,
           pName: "$FRESNELWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for controlling fresnel falloff",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061FE0
// Name: IceSurface_dx9::_dynamic_initializer_for__OPACITYTEXTURE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__OPACITYTEXTURE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &OPACITYTEXTURE_0,
           pName: "$OPACITYTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for controlling fresnel falloff",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062000
// Name: IceSurface_dx9::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__ENVMAP__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &ENVMAP_0,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "environment map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062020
// Name: IceSurface_dx9::_dynamic_initializer_for__UVSCALE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__UVSCALE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &UVSCALE_0,
           pName: "$UVSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.02",
           pHelp: "uv projection scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062040
// Name: IceSurface_dx9::_dynamic_initializer_for__BUMPSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__BUMPSTRENGTH__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &BUMPSTRENGTH_0,
           pName: "$BUMPSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "bump map strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062060
// Name: IceSurface_dx9::_dynamic_initializer_for__FRESNELBUMPSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__FRESNELBUMPSTRENGTH__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &FRESNELBUMPSTRENGTH_0,
           pName: "$FRESNELBUMPSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "bump map strength for fresnel",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062080
// Name: IceSurface_dx9::_dynamic_initializer_for__TRANSLUCENTFRESNELMINMAXEXP__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__TRANSLUCENTFRESNELMINMAXEXP__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &TRANSLUCENTFRESNELMINMAXEXP_0,
           pName: "$TRANSLUCENTFRESNELMINMAXEXP",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0.8 1.0 1.0]",
           pHelp: "fresnel params",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100620A0
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIOR__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIOR__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIOR_0,
           pName: "$INTERIOR",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "Enable interior layer",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100620C0
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORFOGSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORFOGSTRENGTH__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORFOGSTRENGTH_0,
           pName: "$INTERIORFOGSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.06",
           pHelp: "fog strength (scales with thickness of the interior volume)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100620E0
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORFOGLIMIT__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORFOGLIMIT__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORFOGLIMIT_0,
           pName: "$INTERIORFOGLIMIT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.8",
           pHelp: "fog opacity beyond the range of destination alpha depth (in low-precision depth mode)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062100
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORFOGNORMALBOOST__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORFOGNORMALBOOST__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORFOGNORMALBOOST_0,
           pName: "$INTERIORFOGNORMALBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "degree to boost interior thickness/fog by 'side-on'ness of vertex normals to the camera",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062120
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORBACKGROUNDBOOST__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORBACKGROUNDBOOST__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORBACKGROUNDBOOST_0,
           pName: "$INTERIORBACKGROUNDBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "7",
           pHelp: "boosts the brightness of bright background pixels",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062140
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORAMBIENTSCALE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORAMBIENTSCALE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORAMBIENTSCALE_0,
           pName: "$INTERIORAMBIENTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.3",
           pHelp: "scales ambient light in the interior volume",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062160
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORBACKLIGHTSCALE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORBACKLIGHTSCALE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORBACKLIGHTSCALE_0,
           pName: "$INTERIORBACKLIGHTSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.3",
           pHelp: "scales backlighting in the interior volume",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062180
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORCOLOR__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORCOLOR__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORCOLOR_0,
           pName: "$INTERIORCOLOR",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0.7 0.5 0.45]",
           pHelp: "tints light in the interior volume",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100621A0
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORREFRACTSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORREFRACTSTRENGTH__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORREFRACTSTRENGTH_0,
           pName: "$INTERIORREFRACTSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.015",
           pHelp: "strength of bumped refract of the background seen through the interior",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100621C0
// Name: IceSurface_dx9::_dynamic_initializer_for__INTERIORREFRACTBLUR__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__INTERIORREFRACTBLUR__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &INTERIORREFRACTBLUR_0,
           pName: "$INTERIORREFRACTBLUR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.2",
           pHelp: "strength of blur applied to the background seen through the interior",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100621E0
// Name: IceSurface_dx9::_dynamic_initializer_for__DIFFUSESCALE__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__DIFFUSESCALE__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &DIFFUSESCALE,
           pName: "$DIFFUSESCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062200
// Name: IceSurface_dx9::_dynamic_initializer_for__PHONGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__PHONGEXPONENT__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT_1,
           pName: "$PHONGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062220
// Name: IceSurface_dx9::_dynamic_initializer_for__PHONGBOOST__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__PHONGBOOST__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &PHONGBOOST_1,
           pName: "$PHONGBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062240
// Name: IceSurface_dx9::_dynamic_initializer_for__PHONGEXPONENT2__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__PHONGEXPONENT2__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT2_0,
           pName: "$PHONGEXPONENT2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062260
// Name: IceSurface_dx9::_dynamic_initializer_for__PHONGBOOST2__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__PHONGBOOST2__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &PHONGBOOST2_0,
           pName: "$PHONGBOOST2",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "specular boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062280
// Name: IceSurface_dx9::_dynamic_initializer_for__RIMLIGHTEXPONENT__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__RIMLIGHTEXPONENT__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &RIMLIGHTEXPONENT_1,
           pName: "$RIMLIGHTEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "rim light exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100622A0
// Name: IceSurface_dx9::_dynamic_initializer_for__RIMLIGHTBOOST__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__RIMLIGHTBOOST__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &RIMLIGHTBOOST_1,
           pName: "$RIMLIGHTBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "rim light boost",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100622C0
// Name: IceSurface_dx9::_dynamic_initializer_for__BASECOLORTINT__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__BASECOLORTINT__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &BASECOLORTINT_0,
           pName: "$BASECOLORTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1.0 1.0 1.0]",
           pHelp: "base texture tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100622E0
// Name: IceSurface_dx9::_dynamic_initializer_for__ENVMAPTINT__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__ENVMAPTINT__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &ENVMAPTINT,
           pName: "$ENVMAPTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1.0 1.0 1.0]",
           pHelp: "tints the environment reflection",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062300
// Name: IceSurface_dx9::_dynamic_initializer_for__UVPROJOFFSET__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__UVPROJOFFSET__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &UVPROJOFFSET_0,
           pName: "$UVPROJOFFSET",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: "Center for UV projection",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062320
// Name: IceSurface_dx9::_dynamic_initializer_for__BBMIN__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__BBMIN__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &BBMIN_0,
           pName: "$BBMIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062340
// Name: IceSurface_dx9::_dynamic_initializer_for__BBMAX__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__BBMAX__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &BBMAX_0,
           pName: "$BBMAX",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062360
// Name: IceSurface_dx9::_dynamic_initializer_for__CONTACTSHADOWS__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__CONTACTSHADOWS__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &CONTACTSHADOWS_0,
           pName: "$CONTACTSHADOWS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062380
// Name: IceSurface_dx9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
IceSurface_dx9::CShaderParam *IceSurface_dx9::_dynamic_initializer_for__BUMPFRAME__()
{
  return IceSurface_dx9::CShaderParam::CShaderParam(
           this: &BUMPFRAME_2,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100623A0
// Name: IceSurface_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *IceSurface_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_49);
  s_ShaderInstance_49.__vftable = (IceSurface_dx9::CShader_vtbl *)&IceSurface_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B2A0
// Name: IceSurface::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl IceSurface::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_48);
}

//------------------------------------------------------------------------------
// Address: 0x1006B2B0
// Name: IceSurface_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl IceSurface_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_49);
}

//------------------------------------------------------------------------------
// Address: 0x100623C0
// Name: _dynamic_initializer_for__s_ConstructMe_icesurface_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_icesurface_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &icesurface_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100623E0
// Name: _dynamic_initializer_for__s_ConstructMe_icesurface_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_icesurface_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &icesurface_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10062400
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___10()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_10);
}

//------------------------------------------------------------------------------
// Address: 0x10062420
// Name: _dynamic_initializer_for__s_ConstructMe_IntroScreenSpaceEffect_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_IntroScreenSpaceEffect_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &IntroScreenSpaceEffect_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10062440
// Name: _dynamic_initializer_for__s_ConstructMe_IntroScreenSpaceEffect_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_IntroScreenSpaceEffect_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &IntroScreenSpaceEffect_ps20b_combos);
}
