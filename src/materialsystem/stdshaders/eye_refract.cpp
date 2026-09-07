// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/eye_refract.cpp
// Functions: 64
// ============================================================

#include "materialsystem\stdshaders\eye_refract.h"

//------------------------------------------------------------------------------
// Address: 0x1000EE30
// Name: public: virtual char const __near * EyeRefract::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall EyeRefract::CShader::GetFallbackShader(EyeRefract::CShader *this, IMaterialVar **params)
{
  return "EyeRefract_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x1000EE40
// Name: public: virtual char const __near * EyeRefract::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall EyeRefract::CShader::GetName(EyeRefract::CShader *this)
{
  return s_Name_30;
}

//------------------------------------------------------------------------------
// Address: 0x1000EE50
// Name: public: virtual int EyeRefract::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall EyeRefract::CShader::GetFlags(EyeRefract::CShader *this)
{
  return s_nFlags_63;
}

//------------------------------------------------------------------------------
// Address: 0x1000EE70
// Name: public: virtual int EyeRefract::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall EyeRefract::CShader::GetParamCount(EyeRefract::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_30.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000EE80
// Name: public: void EyeRefract_dx9::CShader::SetupVarsEyeRefract(struct Eye_Refract_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EyeRefract_dx9::CShader::SetupVarsEyeRefract(EyeRefract_dx9::CShader *this, Eye_Refract_Vars_t *info)
{
  info->m_nFrame = 7;
  info->m_nIris = IRIS.m_Index;
  info->m_nIrisFrame = IRISFRAME.m_Index;
  info->m_nEyeOrigin = EYEORIGIN.m_Index;
  info->m_nIrisU = IRISU.m_Index;
  info->m_nIrisV = IRISV.m_Index;
  info->m_nDilation = DILATION.m_Index;
  info->m_nGlossiness = GLOSSINESS.m_Index;
  info->m_nEntityOrigin = ENTITYORIGIN.m_Index;
  info->m_nWarpParam = WARPPARAM.m_Index;
  info->m_nCorneaTexture = CORNEATEXTURE.m_Index;
  info->m_nAmbientOcclTexture = AMBIENTOCCLTEXTURE.m_Index;
  info->m_nEnvmap = ENVMAP.m_Index;
  info->m_nSphereTexKillCombo = SPHERETEXKILLCOMBO.m_Index;
  info->m_nRaytraceSphere = RAYTRACESPHERE.m_Index;
  info->m_nParallaxStrength = PARALLAXSTRENGTH.m_Index;
  info->m_nCorneaBumpStrength = CORNEABUMPSTRENGTH.m_Index;
  info->m_nAmbientOcclColor = AMBIENTOCCLCOLOR.m_Index;
  info->m_nEyeballRadius = EYEBALLRADIUS.m_Index;
  info->m_nDiffuseWarpTexture = LIGHTWARPTEXTURE_1.m_Index;
  info->m_nAmbientOcclusion = AMBIENTOCCLUSION.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF50
// Name: public: virtual bool EyeRefract_dx9::CShader::NeedsPowerOfTwoFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall EyeRefract_dx9::CShader::NeedsPowerOfTwoFrameBufferTexture(
        EyeRefract_dx9::CShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  float x; // xmm0_4

  return params[CLOAKPASSENABLED.m_Index]->m_intVal != 0
      && (!bCheckSpecificToThisFrame || (x = params[CLOAKFACTOR_0.m_Index]->m_VecVal.x) > 0.0 && x < 1.0)
      || (params[2]->m_intVal & 0x4000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000EFB0
// Name: public: virtual bool EyeRefract_dx9::CShader::IsTranslucent(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall EyeRefract_dx9::CShader::IsTranslucent(EyeRefract_dx9::CShader *this, IMaterialVar **params)
{
  float x; // xmm0_4

  return params[CLOAKPASSENABLED.m_Index]->m_intVal != 0
      && (x = params[CLOAKFACTOR_0.m_Index]->m_VecVal.x) > 0.0
      && x < 1.0
      || ((*params)->m_intVal & 0x200000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F000
// Name: public: virtual void EyeRefract_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EyeRefract_dx9::CShader::OnInitShaderParams(
        EyeRefract_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  Eye_Refract_Vars_t info; // [esp+Ch] [ebp-70h] BYREF
  EmissiveScrollBlendedPassVars_t v5; // [esp+60h] [ebp-1Ch] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  EyeRefract_dx9::CShader::SetupVarsEyeRefract(this, &info);
  InitParams_Eyes_Refract(pShader: this, params, pMaterialName, &info);
  if ( params[CLOAKPASSENABLED.m_Index]->IsDefined(this: params[CLOAKPASSENABLED.m_Index]) )
  {
    if ( params[CLOAKPASSENABLED.m_Index]->m_intVal != 0 )
    {
      memset(&v5.m_nEmissiveTint, 255, 12);
      v5.m_nBaseTexture = CLOAKFACTOR_0.m_Index;
      v5.m_nFlowTexture = CLOAKCOLORTINT.m_Index;
      v5.m_nEmissiveTexture = REFRACTAMOUNT_1.m_Index;
      InitParamsCloakBlendedPass(
        pShader: this,
        params,
        pMaterialName,
        info: (CloakBlendedPassVars_t *)&v5.m_nBaseTexture);
    }
  }
  else
  {
    params[CLOAKPASSENABLED.m_Index]->SetIntValue(this: params[CLOAKPASSENABLED.m_Index], a2: 0);
  }
  if ( params[EMISSIVEBLENDENABLED.m_Index]->IsDefined(this: params[EMISSIVEBLENDENABLED.m_Index]) )
  {
    if ( params[EMISSIVEBLENDENABLED.m_Index]->m_intVal != 0 )
    {
      v5.m_nTime = -1;
      v5.m_nBlendStrength = EMISSIVEBLENDSTRENGTH.m_Index;
      v5.m_nEmissiveTexture = EMISSIVEBLENDTEXTURE.m_Index;
      v5.m_nBaseTexture = IRIS.m_Index;
      v5.m_nFlowTexture = EMISSIVEBLENDFLOWTEXTURE.m_Index;
      v5.m_nEmissiveTint = EMISSIVEBLENDTINT.m_Index;
      v5.m_nEmissiveScrollVector = EMISSIVEBLENDSCROLLVECTOR.m_Index;
      InitParamsEmissiveScrollBlendedPass(pShader: this, params, pMaterialName, info: &v5);
    }
  }
  else
  {
    params[EMISSIVEBLENDENABLED.m_Index]->SetIntValue(this: params[EMISSIVEBLENDENABLED.m_Index], a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F150
// Name: public: virtual char const __near * EyeRefract_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall EyeRefract_dx9::CShader::GetName(EyeRefract_dx9::CShader *this)
{
  return s_Name_31;
}

//------------------------------------------------------------------------------
// Address: 0x1000F160
// Name: public: virtual int EyeRefract_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall EyeRefract_dx9::CShader::GetFlags(EyeRefract_dx9::CShader *this)
{
  return s_nFlags_64;
}

//------------------------------------------------------------------------------
// Address: 0x1000F170
// Name: public: virtual void EyeRefract_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EyeRefract_dx9::CShader::OnInitShaderInstance(
        EyeRefract_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  Eye_Refract_Vars_t info; // [esp+8h] [ebp-70h] BYREF
  EmissiveScrollBlendedPassVars_t v6; // [esp+5Ch] [ebp-1Ch] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  EyeRefract_dx9::CShader::SetupVarsEyeRefract(this, &info);
  Init_Eyes_Refract(pShader: this, params, &info);
  if ( params[CLOAKPASSENABLED.m_Index]->m_intVal != 0 )
  {
    v6.m_nBaseTexture = CLOAKFACTOR_0.m_Index;
    memset(&v6.m_nEmissiveTint, 255, 12);
    v6.m_nFlowTexture = CLOAKCOLORTINT.m_Index;
    v6.m_nEmissiveTexture = REFRACTAMOUNT_1.m_Index;
    InitCloakBlendedPass(pShader: this, params, info: (CloakBlendedPassVars_t *)&v6.m_nBaseTexture);
  }
  if ( params[EMISSIVEBLENDENABLED.m_Index]->m_intVal != 0 )
  {
    v6.m_nBlendStrength = EMISSIVEBLENDSTRENGTH.m_Index;
    v6.m_nEmissiveTexture = EMISSIVEBLENDTEXTURE.m_Index;
    v6.m_nTime = -1;
    v6.m_nBaseTexture = IRIS.m_Index;
    v6.m_nFlowTexture = EMISSIVEBLENDFLOWTEXTURE.m_Index;
    v6.m_nEmissiveTint = EMISSIVEBLENDTINT.m_Index;
    v6.m_nEmissiveScrollVector = EMISSIVEBLENDSCROLLVECTOR.m_Index;
    InitEmissiveScrollBlendedPass(pShader: this, params, info: &v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F270
// Name: public: virtual void EyeRefract_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EyeRefract_dx9::CShader::OnDrawElements(
        EyeRefract_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  float x; // xmm0_4
  Eye_Refract_Vars_t dst; // [esp+Ch] [ebp-70h] BYREF
  EmissiveScrollBlendedPassVars_t info; // [esp+60h] [ebp-1Ch] BYREF

  if ( params[CLOAKPASSENABLED.m_Index]->m_intVal != 0
    && pShaderShadow == nullptr
    && (info.m_nBaseTexture = CLOAKFACTOR_0.m_Index,
        memset(&info.m_nEmissiveTint, 255, 12),
        info.m_nFlowTexture = CLOAKCOLORTINT.m_Index,
        info.m_nEmissiveTexture = REFRACTAMOUNT_1.m_Index,
        CloakBlendedPassIsFullyOpaque(params, info: (CloakBlendedPassVars_t *)&info.m_nBaseTexture)) )
  {
    CBaseShader::Draw(this, bMakeActualDrawCall: false);
  }
  else
  {
    memset((unsigned __int8 *)&dst, value: 0xFFu, count: sizeof(dst));
    EyeRefract_dx9::CShader::SetupVarsEyeRefract(this, info: &dst);
    Draw_Eyes_Refract(pShader: this, params, pShaderAPI, pShaderShadow, info: &dst, vertexCompression);
  }
  if ( params[CLOAKPASSENABLED.m_Index]->m_intVal != 0 )
  {
    if ( pShaderShadow != nullptr || (x = params[CLOAKFACTOR_0.m_Index]->m_VecVal.x) > 0.0 && x < 1.0 )
    {
      memset(&info.m_nEmissiveTint, 255, 12);
      info.m_nBaseTexture = CLOAKFACTOR_0.m_Index;
      info.m_nFlowTexture = CLOAKCOLORTINT.m_Index;
      info.m_nEmissiveTexture = REFRACTAMOUNT_1.m_Index;
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
  if ( params[EMISSIVEBLENDENABLED.m_Index]->m_intVal != 0 )
  {
    if ( pShaderShadow != nullptr || params[EMISSIVEBLENDSTRENGTH.m_Index]->m_VecVal.x > 0.0 )
    {
      info.m_nTime = -1;
      info.m_nBlendStrength = EMISSIVEBLENDSTRENGTH.m_Index;
      info.m_nBaseTexture = IRIS.m_Index;
      info.m_nEmissiveTexture = EMISSIVEBLENDTEXTURE.m_Index;
      info.m_nFlowTexture = EMISSIVEBLENDFLOWTEXTURE.m_Index;
      info.m_nEmissiveTint = EMISSIVEBLENDTINT.m_Index;
      info.m_nEmissiveScrollVector = EMISSIVEBLENDSCROLLVECTOR.m_Index;
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
}

//------------------------------------------------------------------------------
// Address: 0x1000F440
// Name: public: virtual int EyeRefract_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall EyeRefract_dx9::CShader::GetParamCount(EyeRefract_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_31.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000F450
// Name: public: virtual struct ShaderParamInfo_t const __near & EyeRefract::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
EyeRefract::CShaderParam *__thiscall EyeRefract::CShader::GetParamInfo(EyeRefract::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_30.m_Memory.m_pMemory[param - ParamCount];
  else
    return (EyeRefract::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000F480
// Name: public: virtual struct ShaderParamInfo_t const __near & EyeRefract_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *__thiscall EyeRefract_dx9::CShader::GetParamInfo(
        EyeRefract_dx9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_31.m_Memory.m_pMemory[param - ParamCount];
  else
    return (EyeRefract_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000F4B0
// Name: public: EyeRefract_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *__thiscall EyeRefract_dx9::CShaderParam::CShaderParam(
        EyeRefract_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  EyeRefract_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  EyeRefract_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_31.m_Size + 13;
  m_Size = s_ShaderParams_31.m_Size;
  v8 = s_ShaderParams_31.m_Size;
  if ( s_ShaderParams_31.m_Size + 1 > s_ShaderParams_31.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_31,
      num: s_ShaderParams_31.m_Size - s_ShaderParams_31.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_31.m_Size;
  }
  m_pMemory = s_ShaderParams_31.m_Memory.m_pMemory;
  s_ShaderParams_31.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_31.m_pElements = s_ShaderParams_31.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_31.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_31.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_31.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10060AB0
// Name: EyeRefract::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int EyeRefract::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: EyeRefract::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10060AC0
// Name: EyeRefract::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *EyeRefract::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_30);
  s_ShaderInstance_30.__vftable = (EyeRefract::CShader_vtbl *)&EyeRefract::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10060AE0
// Name: EyeRefract_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int EyeRefract_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: EyeRefract_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10060AF0
// Name: EyeRefract_dx9::_dynamic_initializer_for__IRIS__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__IRIS__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &IRIS,
           pName: "$IRIS",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "iris texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060B10
// Name: EyeRefract_dx9::_dynamic_initializer_for__IRISFRAME__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__IRISFRAME__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &IRISFRAME,
           pName: "$IRISFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame for the iris texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060B30
// Name: EyeRefract_dx9::_dynamic_initializer_for__CORNEATEXTURE__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__CORNEATEXTURE__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &CORNEATEXTURE,
           pName: "$CORNEATEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "cornea texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060B50
// Name: EyeRefract_dx9::_dynamic_initializer_for__AMBIENTOCCLTEXTURE__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__AMBIENTOCCLTEXTURE__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &AMBIENTOCCLTEXTURE,
           pName: "$AMBIENTOCCLTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "reflection texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060B70
// Name: EyeRefract_dx9::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__ENVMAP__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &ENVMAP,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060B90
// Name: EyeRefract_dx9::_dynamic_initializer_for__EYEORIGIN__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__EYEORIGIN__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &EYEORIGIN,
           pName: "$EYEORIGIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: "origin for the eyes",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060BB0
// Name: EyeRefract_dx9::_dynamic_initializer_for__IRISU__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__IRISU__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &IRISU,
           pName: "$IRISU",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 1 0 0 ]",
           pHelp: "U projection vector for the iris",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060BD0
// Name: EyeRefract_dx9::_dynamic_initializer_for__IRISV__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__IRISV__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &IRISV,
           pName: "$IRISV",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 1 0]",
           pHelp: "V projection vector for the iris",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060BF0
// Name: EyeRefract_dx9::_dynamic_initializer_for__DILATION__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__DILATION__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &DILATION,
           pName: "$DILATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Pupil dilation (0 is none, 1 is maximal)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060C10
// Name: EyeRefract_dx9::_dynamic_initializer_for__GLOSSINESS__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__GLOSSINESS__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &GLOSSINESS,
           pName: "$GLOSSINESS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Glossiness of eye (1 is default, 0 is not glossy at all)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060C30
// Name: EyeRefract_dx9::_dynamic_initializer_for__SPHERETEXKILLCOMBO__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__SPHERETEXKILLCOMBO__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &SPHERETEXKILLCOMBO,
           pName: "$SPHERETEXKILLCOMBO",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "texkill pixels not on sphere",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060C50
// Name: EyeRefract_dx9::_dynamic_initializer_for__RAYTRACESPHERE__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__RAYTRACESPHERE__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &RAYTRACESPHERE,
           pName: "$RAYTRACESPHERE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "Raytrace sphere",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060C70
// Name: EyeRefract_dx9::_dynamic_initializer_for__PARALLAXSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__PARALLAXSTRENGTH__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &PARALLAXSTRENGTH,
           pName: "$PARALLAXSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Parallax strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060C90
// Name: EyeRefract_dx9::_dynamic_initializer_for__CORNEABUMPSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__CORNEABUMPSTRENGTH__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &CORNEABUMPSTRENGTH,
           pName: "$CORNEABUMPSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Cornea strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060CB0
// Name: EyeRefract_dx9::_dynamic_initializer_for__AMBIENTOCCLCOLOR__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__AMBIENTOCCLCOLOR__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &AMBIENTOCCLCOLOR,
           pName: "$AMBIENTOCCLCOLOR",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1 1 1]",
           pHelp: "Ambient occlusion color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060CD0
// Name: EyeRefract_dx9::_dynamic_initializer_for__AMBIENTOCCLUSION__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__AMBIENTOCCLUSION__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &AMBIENTOCCLUSION,
           pName: "$AMBIENTOCCLUSION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Dynamic ambient occlusion strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060CF0
// Name: EyeRefract_dx9::_dynamic_initializer_for__EYEBALLRADIUS__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__EYEBALLRADIUS__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &EYEBALLRADIUS,
           pName: "$EYEBALLRADIUS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Eyeball radius for ray casting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060D10
// Name: EyeRefract_dx9::_dynamic_initializer_for__ENTITYORIGIN__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__ENTITYORIGIN__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &ENTITYORIGIN,
           pName: "$ENTITYORIGIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "0.0",
           pHelp: "center if the model in world space",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060D30
// Name: EyeRefract_dx9::_dynamic_initializer_for__WARPPARAM__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__WARPPARAM__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &WARPPARAM,
           pName: "$WARPPARAM",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "animation param between 0 and 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060D50
// Name: EyeRefract_dx9::_dynamic_initializer_for__LIGHTWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__LIGHTWARPTEXTURE__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &LIGHTWARPTEXTURE_1,
           pName: "$LIGHTWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for tinting scalar diffuse term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060D70
// Name: EyeRefract_dx9::_dynamic_initializer_for__CLOAKPASSENABLED__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__CLOAKPASSENABLED__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &CLOAKPASSENABLED,
           pName: "$CLOAKPASSENABLED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enables cloak render in a second pass",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060D90
// Name: EyeRefract_dx9::_dynamic_initializer_for__CLOAKFACTOR__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__CLOAKFACTOR__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &CLOAKFACTOR_0,
           pName: "$CLOAKFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060DB0
// Name: EyeRefract_dx9::_dynamic_initializer_for__CLOAKCOLORTINT__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__CLOAKCOLORTINT__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &CLOAKCOLORTINT,
           pName: "$CLOAKCOLORTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Cloak color tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060DD0
// Name: EyeRefract_dx9::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_1,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060DF0
// Name: EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDENABLED__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDENABLED__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDENABLED,
           pName: "$EMISSIVEBLENDENABLED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable emissive blend pass",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060E10
// Name: EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDSCROLLVECTOR__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDSCROLLVECTOR__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDSCROLLVECTOR,
           pName: "$EMISSIVEBLENDSCROLLVECTOR",
           type: SHADER_PARAM_TYPE_VEC2,
           pDefaultParam: "[0.11 0.124]",
           pHelp: "Emissive scroll vec",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060E30
// Name: EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDSTRENGTH__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDSTRENGTH,
           pName: "$EMISSIVEBLENDSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Emissive blend strength",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060E50
// Name: EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDTEXTURE__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDTEXTURE__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDTEXTURE,
           pName: "$EMISSIVEBLENDTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "self-illumination map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060E70
// Name: EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDTINT__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDTINT__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDTINT,
           pName: "$EMISSIVEBLENDTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Self-illumination tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060E90
// Name: EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDFLOWTEXTURE__
// Source: json
//------------------------------------------------------------------------------
EyeRefract_dx9::CShaderParam *EyeRefract_dx9::_dynamic_initializer_for__EMISSIVEBLENDFLOWTEXTURE__()
{
  return EyeRefract_dx9::CShaderParam::CShaderParam(
           this: &EMISSIVEBLENDFLOWTEXTURE,
           pName: "$EMISSIVEBLENDFLOWTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "flow map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060EB0
// Name: EyeRefract_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *EyeRefract_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_31);
  s_ShaderInstance_31.__vftable = (EyeRefract_dx9::CShader_vtbl *)&EyeRefract_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B160
// Name: EyeRefract::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl EyeRefract::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_30);
}

//------------------------------------------------------------------------------
// Address: 0x1006B170
// Name: EyeRefract_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl EyeRefract_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_31);
}

//------------------------------------------------------------------------------
// Address: 0x10060ED0
// Name: _dynamic_initializer_for__s_ConstructMe_eye_refract_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eye_refract_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eye_refract_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060EF0
// Name: _dynamic_initializer_for__s_ConstructMe_eye_refract_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eye_refract_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eye_refract_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060F10
// Name: _dynamic_initializer_for__s_ConstructMe_eye_refract_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eye_refract_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eye_refract_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060F30
// Name: _dynamic_initializer_for__s_ConstructMe_eye_refract_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eye_refract_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eye_refract_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060F50
// Name: _dynamic_initializer_for__s_ConstructMe_eye_refract_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eye_refract_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eye_refract_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060F70
// Name: _dynamic_initializer_for__r_lightwarpidentity___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_lightwarpidentity___0()
{
  ConVar::ConVar(this: &r_lightwarpidentity_0, pName: "r_lightwarpidentity", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_lightwarpidentity___0);
}

//------------------------------------------------------------------------------
// Address: 0x10060FA0
// Name: _dynamic_initializer_for__mat_displacementmap___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_displacementmap___0()
{
  ConVar::ConVar(this: &mat_displacementmap_0, pName: "mat_displacementmap", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_displacementmap___0);
}

//------------------------------------------------------------------------------
// Address: 0x10060FD0
// Name: _dynamic_initializer_for__s_ConstructMe_eyeglint_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyeglint_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyeglint_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061000
// Name: _dynamic_initializer_for__s_ConstructMe_eyeglint_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyeglint_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyeglint_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061020
// Name: _dynamic_initializer_for__s_ConstructMe_eyeglint_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_eyeglint_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &eyeglint_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006B180
// Name: _dynamic_atexit_destructor_for__r_lightwarpidentity___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_lightwarpidentity___0()
{
  ConVar::~ConVar(this: &r_lightwarpidentity_0);
}

//------------------------------------------------------------------------------
// Address: 0x1006B190
// Name: _dynamic_atexit_destructor_for__mat_displacementmap___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_displacementmap___0()
{
  ConVar::~ConVar(this: &mat_displacementmap_0);
}
