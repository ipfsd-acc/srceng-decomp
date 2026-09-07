// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/lightshafts.cpp
// Functions: 51
// ============================================================

#include "materialsystem\stdshaders\lightshafts.h"

//------------------------------------------------------------------------------
// Address: 0x1001C630
// Name: public: virtual char const __near * LightShafts::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall LightShafts::CShader::GetFallbackShader(LightShafts::CShader *this, IMaterialVar **params)
{
  return "LightShafts_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1001C640
// Name: public: virtual char const __near * LightShafts::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall LightShafts::CShader::GetName(LightShafts::CShader *this)
{
  return s_Name_54;
}

//------------------------------------------------------------------------------
// Address: 0x1001C650
// Name: public: virtual int LightShafts::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightShafts::CShader::GetFlags(LightShafts::CShader *this)
{
  return s_nFlags_77;
}

//------------------------------------------------------------------------------
// Address: 0x1001C660
// Name: public: virtual int LightShafts::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightShafts::CShader::GetParamCount(LightShafts::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_55.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001C670
// Name: public: void LightShafts_dx9::CShader::SetupVarsLightShafts(struct LightShaftsVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightShafts_dx9::CShader::SetupVarsLightShafts(LightShafts_dx9::CShader *this, LightShaftsVars_t *info)
{
  info->m_nCookieTexture = COOKIETEXTURE.m_Index;
  info->m_nCookieFrameNum = COOKIEFRAMENUM.m_Index;
  info->m_nShadowDepthTexture = SHADOWDEPTHTEXTURE.m_Index;
  info->m_nNoiseTexture = NOISETEXTURE_0.m_Index;
  info->m_nNoiseStrength = NOISESTRENGTH.m_Index;
  info->m_nWorldToTexture = WORLDTOTEXTURE.m_Index;
  info->m_nFlashlightColor = FLASHLIGHTCOLOR.m_Index;
  info->m_nAttenFactors = ATTENFACTORS.m_Index;
  info->m_nOriginFarZ = ORIGINFARZ.m_Index;
  info->m_nQuatOrientation = QUATORIENTATION.m_Index;
  info->m_nShadowFilterSize = SHADOWFILTERSIZE.m_Index;
  info->m_nShadowAtten = SHADOWATTEN.m_Index;
  info->m_nShadowJitterSeed = SHADOWJITTERSEED.m_Index;
  info->m_nUberlight = UBERLIGHT.m_Index;
  info->m_nEnableShadows = ENABLESHADOWS.m_Index;
  info->m_nFlashlightTime = FLASHLIGHTTIME.m_Index;
  info->m_nNumPlanes = NUMPLANES.m_Index;
  info->m_nUberNearFar = UBERNEARFAR.m_Index;
  info->m_nUberHeightWidth = UBERHEIGHTWIDTH.m_Index;
  info->m_nUberRoundness = UBERROUNDNESS.m_Index;
  info->m_nVolumetricIntensity = VOLUMETRICINTENSITY.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x1001C740
// Name: public: virtual void LightShafts_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightShafts_dx9::CShader::OnInitShaderParams(
        LightShafts_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  LightShaftsVars_t info; // [esp+4h] [ebp-58h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  LightShafts_dx9::CShader::SetupVarsLightShafts(this, &info);
  InitParamsLightShafts(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x1001C790
// Name: public: virtual char const __near * LightShafts_dx9::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall LightShafts_dx9::CShader::GetFallbackShader(LightShafts_dx9::CShader *this, IMaterialVar **params)
{
  return !g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) ? "Wireframe" : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001C7C0
// Name: public: virtual char const __near * LightShafts_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall LightShafts_dx9::CShader::GetName(LightShafts_dx9::CShader *this)
{
  return s_Name_55;
}

//------------------------------------------------------------------------------
// Address: 0x1001C7D0
// Name: public: virtual int LightShafts_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightShafts_dx9::CShader::GetFlags(LightShafts_dx9::CShader *this)
{
  return s_nFlags_78;
}

//------------------------------------------------------------------------------
// Address: 0x1001C7E0
// Name: public: virtual void LightShafts_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightShafts_dx9::CShader::OnInitShaderInstance(
        LightShafts_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  LightShaftsVars_t info; // [esp+4h] [ebp-58h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  LightShafts_dx9::CShader::SetupVarsLightShafts(this, &info);
  InitLightShafts(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x1001C820
// Name: public: virtual void LightShafts_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightShafts_dx9::CShader::OnDrawElements(
        LightShafts_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  LightShaftsVars_t info; // [esp+4h] [ebp-58h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  LightShafts_dx9::CShader::SetupVarsLightShafts(this, &info);
  DrawLightShafts(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x1001C870
// Name: public: virtual int LightShafts_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightShafts_dx9::CShader::GetParamCount(LightShafts_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_54.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001C880
// Name: public: virtual struct ShaderParamInfo_t const __near & LightShafts::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
LightShafts::CShaderParam *__thiscall LightShafts::CShader::GetParamInfo(LightShafts::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_55.m_Memory.m_pMemory[param - ParamCount];
  else
    return (LightShafts::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001C8B0
// Name: public: virtual struct ShaderParamInfo_t const __near & LightShafts_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *__thiscall LightShafts_dx9::CShader::GetParamInfo(
        LightShafts_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_54.m_Memory.m_pMemory[param - ParamCount];
  else
    return (LightShafts_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001C950
// Name: public: LightShafts_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *__thiscall LightShafts_dx9::CShaderParam::CShaderParam(
        LightShafts_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  LightShafts_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  LightShafts_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_54.m_Size + 13;
  m_Size = s_ShaderParams_54.m_Size;
  v8 = s_ShaderParams_54.m_Size;
  if ( s_ShaderParams_54.m_Size + 1 > s_ShaderParams_54.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_54,
      num: s_ShaderParams_54.m_Size - s_ShaderParams_54.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_54.m_Size;
  }
  m_pMemory = s_ShaderParams_54.m_Memory.m_pMemory;
  s_ShaderParams_54.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_54.m_pElements = s_ShaderParams_54.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_54.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_54.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_54.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062D70
// Name: LightShafts::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int LightShafts::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: LightShafts::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10062D80
// Name: LightShafts::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *LightShafts::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_55);
  s_ShaderInstance_55.__vftable = (LightShafts::CShader_vtbl *)&LightShafts::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062DA0
// Name: LightShafts_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int LightShafts_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: LightShafts_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10062DB0
// Name: LightShafts_dx9::_dynamic_initializer_for__SHADOWDEPTHTEXTURE__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__SHADOWDEPTHTEXTURE__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &SHADOWDEPTHTEXTURE,
           pName: "$SHADOWDEPTHTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Shadow Depth Texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062DD0
// Name: LightShafts_dx9::_dynamic_initializer_for__NOISETEXTURE__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__NOISETEXTURE__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &NOISETEXTURE_0,
           pName: "$NOISETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Noise texture for non-uniform density",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062DF0
// Name: LightShafts_dx9::_dynamic_initializer_for__COOKIETEXTURE__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__COOKIETEXTURE__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &COOKIETEXTURE,
           pName: "$COOKIETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "Cookie Texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062E10
// Name: LightShafts_dx9::_dynamic_initializer_for__COOKIEFRAMENUM__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__COOKIEFRAMENUM__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &COOKIEFRAMENUM,
           pName: "$COOKIEFRAMENUM",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: "Cookie Frame number for animated cookies",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062E30
// Name: LightShafts_dx9::_dynamic_initializer_for__WORLDTOTEXTURE__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__WORLDTOTEXTURE__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &WORLDTOTEXTURE,
           pName: "$WORLDTOTEXTURE",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "1",
           pHelp: "World to Texture Matrix",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062E50
// Name: LightShafts_dx9::_dynamic_initializer_for__FLASHLIGHTCOLOR__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__FLASHLIGHTCOLOR__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &FLASHLIGHTCOLOR,
           pName: "$FLASHLIGHTCOLOR",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "1",
           pHelp: "Flashlight color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062E70
// Name: LightShafts_dx9::_dynamic_initializer_for__ATTENFACTORS__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__ATTENFACTORS__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &ATTENFACTORS,
           pName: "$ATTENFACTORS",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "1",
           pHelp: "Packed attenuation factors",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062E90
// Name: LightShafts_dx9::_dynamic_initializer_for__ORIGINFARZ__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__ORIGINFARZ__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &ORIGINFARZ,
           pName: "$ORIGINFARZ",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "1",
           pHelp: "Light origin packed with farz",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062EB0
// Name: LightShafts_dx9::_dynamic_initializer_for__QUATORIENTATION__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__QUATORIENTATION__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &QUATORIENTATION,
           pName: "$QUATORIENTATION",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "1",
           pHelp: "Light orientation (quaternion)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062ED0
// Name: LightShafts_dx9::_dynamic_initializer_for__SHADOWFILTERSIZE__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__SHADOWFILTERSIZE__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &SHADOWFILTERSIZE,
           pName: "$SHADOWFILTERSIZE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "3",
           pHelp: "Shadow filter size",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062EF0
// Name: LightShafts_dx9::_dynamic_initializer_for__SHADOWATTEN__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__SHADOWATTEN__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &SHADOWATTEN,
           pName: "$SHADOWATTEN",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Shadow Attenuation",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062F10
// Name: LightShafts_dx9::_dynamic_initializer_for__SHADOWJITTERSEED__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__SHADOWJITTERSEED__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &SHADOWJITTERSEED,
           pName: "$SHADOWJITTERSEED",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Shadow jitter seed",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062F30
// Name: LightShafts_dx9::_dynamic_initializer_for__UBERLIGHT__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__UBERLIGHT__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &UBERLIGHT,
           pName: "$UBERLIGHT",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "1",
           pHelp: "Is this an uberlight?",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062F50
// Name: LightShafts_dx9::_dynamic_initializer_for__ENABLESHADOWS__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__ENABLESHADOWS__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &ENABLESHADOWS,
           pName: "$ENABLESHADOWS",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "1",
           pHelp: "Are shadows enabled?",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062F70
// Name: LightShafts_dx9::_dynamic_initializer_for__NOISESTRENGTH__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__NOISESTRENGTH__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &NOISESTRENGTH,
           pName: "$NOISESTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Strength of noise in volumetrics",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062F90
// Name: LightShafts_dx9::_dynamic_initializer_for__UBERNEARFAR__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__UBERNEARFAR__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &UBERNEARFAR,
           pName: "$UBERNEARFAR",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "1",
           pHelp: "Packed uberlight near and far parameters",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062FB0
// Name: LightShafts_dx9::_dynamic_initializer_for__UBERHEIGHTWIDTH__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__UBERHEIGHTWIDTH__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &UBERHEIGHTWIDTH,
           pName: "$UBERHEIGHTWIDTH",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "1",
           pHelp: "Packed uberlight height and width parameters",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062FD0
// Name: LightShafts_dx9::_dynamic_initializer_for__UBERROUNDNESS__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__UBERROUNDNESS__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &UBERROUNDNESS,
           pName: "$UBERROUNDNESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Uberlight roundness",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063000
// Name: LightShafts_dx9::_dynamic_initializer_for__FLASHLIGHTTIME__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__FLASHLIGHTTIME__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &FLASHLIGHTTIME,
           pName: "$FLASHLIGHTTIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Typically driven by SFM, similar to jitter seed",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063020
// Name: LightShafts_dx9::_dynamic_initializer_for__NUMPLANES__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__NUMPLANES__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &NUMPLANES,
           pName: "$NUMPLANES",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Need to know this to normalize intensity",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063040
// Name: LightShafts_dx9::_dynamic_initializer_for__VOLUMETRICINTENSITY__
// Source: json
//------------------------------------------------------------------------------
LightShafts_dx9::CShaderParam *LightShafts_dx9::_dynamic_initializer_for__VOLUMETRICINTENSITY__()
{
  return LightShafts_dx9::CShaderParam::CShaderParam(
           this: &VOLUMETRICINTENSITY,
           pName: "$VOLUMETRICINTENSITY",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Intensity of volumetrics",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063060
// Name: LightShafts_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *LightShafts_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_54);
  s_ShaderInstance_54.__vftable = (LightShafts_dx9::CShader_vtbl *)&LightShafts_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B350
// Name: LightShafts::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl LightShafts::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_55);
}

//------------------------------------------------------------------------------
// Address: 0x1006B360
// Name: LightShafts_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl LightShafts_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_54);
}

//------------------------------------------------------------------------------
// Address: 0x10063080
// Name: _dynamic_initializer_for__s_ConstructMe_lightshafts_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightshafts_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightshafts_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100630A0
// Name: _dynamic_initializer_for__s_ConstructMe_lightshafts_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_lightshafts_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &lightshafts_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100630C0
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100630E0
// Name: _dynamic_initializer_for__s_ConstructMe_modulate_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_modulate_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &modulate_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063100
// Name: _dynamic_initializer_for__s_ConstructMe_modulate_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_modulate_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &modulate_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063120
// Name: _dynamic_initializer_for__s_ConstructMe_modulate_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_modulate_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &modulate_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063140
// Name: _dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlitgeneric_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlitgeneric_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063160
// Name: _dynamic_initializer_for__mat_displacementmap___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_displacementmap___1()
{
  ConVar::ConVar(this: &mat_displacementmap_1, pName: "mat_displacementmap", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_displacementmap___1);
}

//------------------------------------------------------------------------------
// Address: 0x1006B370
// Name: _dynamic_atexit_destructor_for__mat_displacementmap___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_displacementmap___1()
{
  ConVar::~ConVar(this: &mat_displacementmap_1);
}
