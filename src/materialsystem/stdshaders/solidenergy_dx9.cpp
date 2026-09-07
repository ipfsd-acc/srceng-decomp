// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/solidenergy_dx9.cpp
// Functions: 71
// ============================================================

#include "materialsystem\stdshaders\solidenergy_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1002FEA0
// Name: public: virtual char const __near * SolidEnergy::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SolidEnergy::CShader::GetFallbackShader(SolidEnergy::CShader *this, IMaterialVar **params)
{
  return "SolidEnergy_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1002FEB0
// Name: public: virtual char const __near * SolidEnergy::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SolidEnergy::CShader::GetName(SolidEnergy::CShader *this)
{
  return s_Name_110;
}

//------------------------------------------------------------------------------
// Address: 0x1002FEC0
// Name: public: virtual int SolidEnergy::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SolidEnergy::CShader::GetFlags(SolidEnergy::CShader *this)
{
  return s_nFlags_114;
}

//------------------------------------------------------------------------------
// Address: 0x1002FEE0
// Name: public: virtual int SolidEnergy::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SolidEnergy::CShader::GetParamCount(SolidEnergy::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_110.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002FEF0
// Name: public: void SolidEnergy_dx9::CShader::SetupVarsSolidEnergy(struct SolidEnergyVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SolidEnergy_dx9::CShader::SetupVarsSolidEnergy(SolidEnergy_dx9::CShader *this, SolidEnergyVars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nBaseTextureTransform = 8;
  info->m_nDetail1Texture = DETAIL1.m_Index;
  info->m_nDetail1Scale = DETAIL1SCALE.m_Index;
  info->m_nDetail1Frame = DETAIL1FRAME.m_Index;
  info->m_nDetail1BlendMode = DETAIL1BLENDMODE.m_Index;
  info->m_nDetail1TextureTransform = DETAIL1TEXTURETRANSFORM.m_Index;
  info->m_nDetail2Texture = DETAIL2.m_Index;
  info->m_nDetail2Scale = DETAIL2SCALE.m_Index;
  info->m_nDetail2Frame = DETAIL2FRAME.m_Index;
  info->m_nDetail2BlendMode = DETAIL2BLENDMODE.m_Index;
  info->m_nDetail2TextureTransform = DETAIL2TEXTURETRANSFORM.m_Index;
  info->m_nTangentTOpacityRanges = TANGENTTOPACITYRANGES.m_Index;
  info->m_nTangentSOpacityRanges = TANGENTSOPACITYRANGES.m_Index;
  info->m_nFresnelOpacityRanges = FRESNELOPACITYRANGES.m_Index;
  info->m_nNeedsTangentT = NEEDSTANGENTT.m_Index;
  info->m_nNeedsTangentS = NEEDSTANGENTS.m_Index;
  info->m_nNeedsNormals = NEEDSNORMALS.m_Index;
  info->m_nDepthBlend = DEPTHBLEND_0.m_Index;
  info->m_nDepthBlendScale = DEPTHBLENDSCALE_0.m_Index;
  info->m_nFlowMap = FLOWMAP.m_Index;
  info->m_nFlowMapFrame = FLOWMAPFRAME.m_Index;
  info->m_nFlowMapScrollRate = FLOWMAPSCROLLRATE.m_Index;
  info->m_nFlowNoiseTexture = FLOW_NOISE_TEXTURE.m_Index;
  info->m_nTime = TIME_3.m_Index;
  info->m_nFlowWorldUVScale = FLOW_WORLDUVSCALE.m_Index;
  info->m_nFlowNormalUVScale = FLOW_NORMALUVSCALE.m_Index;
  info->m_nFlowTimeIntervalInSeconds = FLOW_TIMEINTERVALINSECONDS.m_Index;
  info->m_nFlowUVScrollDistance = FLOW_UVSCROLLDISTANCE.m_Index;
  info->m_nFlowNoiseScale = FLOW_NOISE_SCALE.m_Index;
  info->m_nFlowLerpExp = FLOW_LERPEXP.m_Index;
  info->m_nFlowBoundsTexture = FLOWBOUNDS.m_Index;
  info->m_nPowerUp = POWERUP.m_Index;
  info->m_nFlowColorIntensity = FLOW_COLOR_INTENSITY.m_Index;
  info->m_nFlowColor = FLOW_COLOR.m_Index;
  info->m_nFlowVortexColor = FLOW_VORTEX_COLOR.m_Index;
  info->m_nFlowVortexSize = FLOW_VORTEX_SIZE.m_Index;
  info->m_nFlowVortex1 = FLOW_VORTEX1.m_Index;
  info->m_nFlowVortexPos1 = FLOW_VORTEX_POS1.m_Index;
  info->m_nFlowVortex2 = FLOW_VORTEX2.m_Index;
  info->m_nFlowVortexPos2 = FLOW_VORTEX_POS2.m_Index;
  info->m_nFlowCheap = FLOW_CHEAP.m_Index;
  info->m_nModel = MODELFORMAT.m_Index;
  info->m_nOutputIntensity = OUTPUTINTENSITY.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x100300B0
// Name: public: virtual void SolidEnergy_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SolidEnergy_dx9::CShader::OnInitShaderParams(
        SolidEnergy_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  SolidEnergyVars_t info; // [esp+4h] [ebp-B0h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  SolidEnergy_dx9::CShader::SetupVarsSolidEnergy(this, &info);
  InitParamsSolidEnergy(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10030110
// Name: public: virtual char const __near * SolidEnergy_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SolidEnergy_dx9::CShader::GetName(SolidEnergy_dx9::CShader *this)
{
  return s_Name_111;
}

//------------------------------------------------------------------------------
// Address: 0x10030120
// Name: public: virtual int SolidEnergy_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SolidEnergy_dx9::CShader::GetFlags(SolidEnergy_dx9::CShader *this)
{
  return s_nFlags_115;
}

//------------------------------------------------------------------------------
// Address: 0x10030130
// Name: public: virtual void SolidEnergy_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SolidEnergy_dx9::CShader::OnInitShaderInstance(
        SolidEnergy_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  SolidEnergyVars_t info; // [esp+4h] [ebp-B0h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  SolidEnergy_dx9::CShader::SetupVarsSolidEnergy(this, &info);
  InitSolidEnergy(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10030180
// Name: public: virtual void SolidEnergy_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SolidEnergy_dx9::CShader::OnDrawElements(
        SolidEnergy_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  SolidEnergyVars_t info; // [esp+4h] [ebp-B0h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  SolidEnergy_dx9::CShader::SetupVarsSolidEnergy(this, &info);
  DrawSolidEnergy(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression, pContextDataPtr);
}

//------------------------------------------------------------------------------
// Address: 0x100301E0
// Name: public: virtual int SolidEnergy_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SolidEnergy_dx9::CShader::GetParamCount(SolidEnergy_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_111.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100301F0
// Name: public: virtual struct ShaderParamInfo_t const __near & SolidEnergy::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
SolidEnergy::CShaderParam *__thiscall SolidEnergy::CShader::GetParamInfo(SolidEnergy::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_110.m_Memory.m_pMemory[param - ParamCount];
  else
    return (SolidEnergy::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10030220
// Name: public: virtual struct ShaderParamInfo_t const __near & SolidEnergy_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *__thiscall SolidEnergy_dx9::CShader::GetParamInfo(
        SolidEnergy_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_111.m_Memory.m_pMemory[param - ParamCount];
  else
    return (SolidEnergy_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10030250
// Name: public: SolidEnergy_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *__thiscall SolidEnergy_dx9::CShaderParam::CShaderParam(
        SolidEnergy_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  SolidEnergy_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  SolidEnergy_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_111.m_Size + 13;
  m_Size = s_ShaderParams_111.m_Size;
  v8 = s_ShaderParams_111.m_Size;
  if ( s_ShaderParams_111.m_Size + 1 > s_ShaderParams_111.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_111,
      num: s_ShaderParams_111.m_Size - s_ShaderParams_111.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_111.m_Size;
  }
  m_pMemory = s_ShaderParams_111.m_Memory.m_pMemory;
  s_ShaderParams_111.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_111.m_pElements = s_ShaderParams_111.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_111.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_111.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_111.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066870
// Name: SolidEnergy::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int SolidEnergy::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: SolidEnergy::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10066880
// Name: SolidEnergy::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *SolidEnergy::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_110);
  s_ShaderInstance_110.__vftable = (SolidEnergy::CShader_vtbl *)&SolidEnergy::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100668A0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int SolidEnergy_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: SolidEnergy_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100668B0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL1,
           pName: "$DETAIL1",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shader/BaseTexture",
           pHelp: "detail map 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100668D0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1SCALE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1SCALE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL1SCALE,
           pName: "$DETAIL1SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "scale detail1 as multiplier of base UVs",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100668F0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1FRAME__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1FRAME__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL1FRAME,
           pName: "$DETAIL1FRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for detail1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066910
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1BLENDMODE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1BLENDMODE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL1BLENDMODE,
           pName: "$DETAIL1BLENDMODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "detail 1 blend mode: 0=add, 1=mod2x, 2=mul, 3=alphamul (mul masked by base alpha)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066930
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1BLENDFACTOR__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1BLENDFACTOR__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL1BLENDFACTOR,
           pName: "$DETAIL1BLENDFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "detail 1 blend factor",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066950
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1TEXTURETRANSFORM__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL1TEXTURETRANSFORM__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL1TEXTURETRANSFORM,
           pName: "$DETAIL1TEXTURETRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "detail1 texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066970
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL2,
           pName: "$DETAIL2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shader/BaseTexture",
           pHelp: "detail map 2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066990
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2SCALE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2SCALE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL2SCALE,
           pName: "$DETAIL2SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "scale detail1 as multiplier of base UVs",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100669B0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2FRAME__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2FRAME__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL2FRAME,
           pName: "$DETAIL2FRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for detail1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100669D0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2BLENDMODE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2BLENDMODE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL2BLENDMODE,
           pName: "$DETAIL2BLENDMODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "detail 1 blend mode: 0=add, 1=mod2x, 2=mul, 3=detailmul (mul with detail1)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100669F0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2BLENDFACTOR__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2BLENDFACTOR__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL2BLENDFACTOR,
           pName: "$DETAIL2BLENDFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "detail 1 blend factor",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066A10
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2TEXTURETRANSFORM__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DETAIL2TEXTURETRANSFORM__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DETAIL2TEXTURETRANSFORM,
           pName: "$DETAIL2TEXTURETRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "detail1 texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066A30
// Name: SolidEnergy_dx9::_dynamic_initializer_for__TANGENTTOPACITYRANGES__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__TANGENTTOPACITYRANGES__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &TANGENTTOPACITYRANGES,
           pName: "$TANGENTTOPACITYRANGES",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[1 0.9 0 0.6]",
           pHelp: "enables view-based opacity falloff based on tangent t direction, great for cylinders, includes last term for "
           "scaling backface opacity",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066A50
// Name: SolidEnergy_dx9::_dynamic_initializer_for__TANGENTSOPACITYRANGES__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__TANGENTSOPACITYRANGES__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &TANGENTSOPACITYRANGES,
           pName: "$TANGENTSOPACITYRANGES",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[1 0.9 0 0.6]",
           pHelp: "enables view-based opacity falloff based on tangent s direction, great for cylinders, includes last term for "
           "scaling backface opacity",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066A70
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FRESNELOPACITYRANGES__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FRESNELOPACITYRANGES__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FRESNELOPACITYRANGES,
           pName: "$FRESNELOPACITYRANGES",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[1 0.9 0 0.6]",
           pHelp: "enables fresnel-based opacity falloff, includes last term for scaling backface opacity",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066A90
// Name: SolidEnergy_dx9::_dynamic_initializer_for__NEEDSTANGENTT__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__NEEDSTANGENTT__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &NEEDSTANGENTT,
           pName: "$NEEDSTANGENTT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "don't need to set this explicitly, it gets set when tangenttopacityranges is defined",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066AB0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__NEEDSTANGENTS__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__NEEDSTANGENTS__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &NEEDSTANGENTS,
           pName: "$NEEDSTANGENTS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "don't need to set this explicitly, it gets set when tangentSopacityranges is defined",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066AD0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__NEEDSNORMALS__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__NEEDSNORMALS__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &NEEDSNORMALS,
           pName: "$NEEDSNORMALS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "don't need to set this explicitly, it gets set when fresnelopacityranges is defined",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066AF0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DEPTHBLEND__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DEPTHBLEND__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DEPTHBLEND_0,
           pName: "$DEPTHBLEND",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "enables depth-feathering",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066B10
// Name: SolidEnergy_dx9::_dynamic_initializer_for__DEPTHBLENDSCALE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__DEPTHBLENDSCALE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &DEPTHBLENDSCALE_0,
           pName: "$DEPTHBLENDSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "50.0",
           pHelp: "Amplify or reduce DEPTHBLEND fading. Lower values make harder edges.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066B30
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOWMAP__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOWMAP__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOWMAP,
           pName: "$FLOWMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "flowmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066B50
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOWMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOWMAPFRAME__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOWMAPFRAME,
           pName: "$FLOWMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $flowmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066B70
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOWMAPSCROLLRATE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOWMAPSCROLLRATE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOWMAPSCROLLRATE,
           pName: "$FLOWMAPSCROLLRATE",
           type: SHADER_PARAM_TYPE_VEC2,
           pDefaultParam: "[0 0",
           pHelp: "2D rate to scroll $flowmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066B90
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_NOISE_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_NOISE_TEXTURE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_NOISE_TEXTURE,
           pName: "$FLOW_NOISE_TEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "flow noise texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066BB0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__TIME__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__TIME__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &TIME_3,
           pName: "$TIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066BD0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_WORLDUVSCALE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_WORLDUVSCALE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_WORLDUVSCALE,
           pName: "$FLOW_WORLDUVSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066BF0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_NORMALUVSCALE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_NORMALUVSCALE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_NORMALUVSCALE,
           pName: "$FLOW_NORMALUVSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066C10
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_TIMEINTERVALINSECONDS__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_TIMEINTERVALINSECONDS__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_TIMEINTERVALINSECONDS,
           pName: "$FLOW_TIMEINTERVALINSECONDS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066C30
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_UVSCROLLDISTANCE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_UVSCROLLDISTANCE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_UVSCROLLDISTANCE,
           pName: "$FLOW_UVSCROLLDISTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066C50
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_NOISE_SCALE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_NOISE_SCALE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_NOISE_SCALE,
           pName: "$FLOW_NOISE_SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066C70
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_LERPEXP__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_LERPEXP__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_LERPEXP,
           pName: "$FLOW_LERPEXP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066C90
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOWBOUNDS__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOWBOUNDS__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOWBOUNDS,
           pName: "$FLOWBOUNDS",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066CB0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__POWERUP__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__POWERUP__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &POWERUP,
           pName: "$POWERUP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066CD0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_COLOR_INTENSITY__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_COLOR_INTENSITY__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_COLOR_INTENSITY,
           pName: "$FLOW_COLOR_INTENSITY",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066CF0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_COLOR__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_COLOR__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_COLOR,
           pName: "$FLOW_COLOR",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066D10
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX_COLOR__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX_COLOR__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_VORTEX_COLOR,
           pName: "$FLOW_VORTEX_COLOR",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066D30
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX_SIZE__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX_SIZE__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_VORTEX_SIZE,
           pName: "$FLOW_VORTEX_SIZE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066D50
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX1__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX1__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_VORTEX1,
           pName: "$FLOW_VORTEX1",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066D70
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX_POS1__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX_POS1__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_VORTEX_POS1,
           pName: "$FLOW_VORTEX_POS1",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066D90
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX2__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX2__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_VORTEX2,
           pName: "$FLOW_VORTEX2",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066DB0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX_POS2__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_VORTEX_POS2__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_VORTEX_POS2,
           pName: "$FLOW_VORTEX_POS2",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066DD0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__FLOW_CHEAP__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__FLOW_CHEAP__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &FLOW_CHEAP,
           pName: "$FLOW_CHEAP",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066DF0
// Name: SolidEnergy_dx9::_dynamic_initializer_for__MODELFORMAT__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__MODELFORMAT__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &MODELFORMAT,
           pName: "$MODELFORMAT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066E10
// Name: SolidEnergy_dx9::_dynamic_initializer_for__OUTPUTINTENSITY__
// Source: json
//------------------------------------------------------------------------------
SolidEnergy_dx9::CShaderParam *SolidEnergy_dx9::_dynamic_initializer_for__OUTPUTINTENSITY__()
{
  return SolidEnergy_dx9::CShaderParam::CShaderParam(
           this: &OUTPUTINTENSITY,
           pName: "$OUTPUTINTENSITY",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066E30
// Name: SolidEnergy_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *SolidEnergy_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_111);
  s_ShaderInstance_111.__vftable = (SolidEnergy_dx9::CShader_vtbl *)&SolidEnergy_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B780
// Name: SolidEnergy::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl SolidEnergy::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_110);
}

//------------------------------------------------------------------------------
// Address: 0x1006B790
// Name: SolidEnergy_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl SolidEnergy_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_111);
}

//------------------------------------------------------------------------------
// Address: 0x10066E50
// Name: _dynamic_initializer_for__s_ConstructMe_solidenergy_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_solidenergy_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &solidenergy_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066E70
// Name: _dynamic_initializer_for__s_ConstructMe_solidenergy_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_solidenergy_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &solidenergy_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066E90
// Name: _dynamic_initializer_for__s_ConstructMe_solidenergy_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_solidenergy_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &solidenergy_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066EB0
// Name: _dynamic_initializer_for__s_ConstructMe_solidenergy_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_solidenergy_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &solidenergy_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066ED0
// Name: _dynamic_initializer_for__s_ConstructMe_splinerope_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_splinerope_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &splinerope_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066EF0
// Name: _dynamic_initializer_for__s_ConstructMe_splinerope_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_splinerope_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &splinerope_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066F10
// Name: _dynamic_initializer_for__s_ConstructMe_splinerope_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_splinerope_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &splinerope_vs20_combos);
}
