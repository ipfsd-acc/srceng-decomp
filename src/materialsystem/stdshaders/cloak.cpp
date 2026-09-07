// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/cloak.cpp
// Functions: 62
// ============================================================

#include "materialsystem\stdshaders\cloak.h"

//------------------------------------------------------------------------------
// Address: 0x10008790
// Name: public: virtual char const __near * Cloak::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Cloak::CShader::GetFallbackShader(Cloak::CShader *this, IMaterialVar **params)
{
  return "Cloak_DX90";
}

//------------------------------------------------------------------------------
// Address: 0x100087A0
// Name: public: virtual char const __near * Cloak::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Cloak::CShader::GetName(Cloak::CShader *this)
{
  return s_Name_14;
}

//------------------------------------------------------------------------------
// Address: 0x100087B0
// Name: public: virtual int Cloak::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Cloak::CShader::GetFlags(Cloak::CShader *this)
{
  return s_nFlags_55;
}

//------------------------------------------------------------------------------
// Address: 0x100087C0
// Name: public: virtual int Cloak::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Cloak::CShader::GetParamCount(Cloak::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_14.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100087D0
// Name: public: void Cloak_DX90::CShader::SetupVars(struct Cloak_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cloak_DX90::CShader::SetupVars(Cloak_DX90::CShader *this, Cloak_DX9_Vars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nRefractAmount = REFRACTAMOUNT_0.m_Index;
  info->m_nRefractTint = REFRACTTINT.m_Index;
  info->m_nNormalMap = NORMALMAP_1.m_Index;
  info->m_nBumpFrame = BUMPFRAME_1.m_Index;
  info->m_nBumpTransform = BUMPTRANSFORM_0.m_Index;
  info->m_nRefractTintTexture = REFRACTTINTTEXTURE.m_Index;
  info->m_nRefractTintTextureFrame = REFRACTTINTTEXTUREFRAME.m_Index;
  info->m_nFresnelReflection = FRESNELREFLECTION.m_Index;
  info->m_nMasked = MASKED.m_Index;
  info->m_nCloakFactor = CLOAKFACTOR.m_Index;
  info->m_nDiffuseWarpTexture = LIGHTWARPTEXTURE_0.m_Index;
  info->m_nPhongExponent = PHONGEXPONENT_0.m_Index;
  info->m_nPhongTint = PHONGTINT.m_Index;
  info->m_nPhongAlbedoTint = PHONGALBEDOTINT.m_Index;
  info->m_nPhongExponentTexture = PHONGEXPONENTTEXTURE.m_Index;
  info->m_nPhongBoost = PHONGBOOST_0.m_Index;
  info->m_nPhongFresnelRanges = PHONGFRESNELRANGES.m_Index;
  info->m_nRimLight = RIMLIGHT.m_Index;
  info->m_nRimLightPower = RIMLIGHTEXPONENT_0.m_Index;
  info->m_nRimLightBoost = RIMLIGHTBOOST_0.m_Index;
  info->m_nRimMask = RIMMASK.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x100088A0
// Name: public: virtual bool Cloak_DX90::CShader::NeedsPowerOfTwoFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Cloak_DX90::CShader::NeedsPowerOfTwoFrameBufferTexture(
        Cloak_DX90::CShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  bool result; // al
  float x; // xmm0_4

  result = true;
  if ( bCheckSpecificToThisFrame )
  {
    x = params[CLOAKFACTOR.m_Index]->m_VecVal.x;
    if ( x <= 0.0 || x >= 1.0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100088E0
// Name: public: virtual bool Cloak_DX90::CShader::IsTranslucent(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Cloak_DX90::CShader::IsTranslucent(Cloak_DX90::CShader *this, IMaterialVar **params)
{
  float x; // xmm0_4

  x = params[CLOAKFACTOR.m_Index]->m_VecVal.x;
  return x > 0.0 && x < 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10008920
// Name: public: virtual void Cloak_DX90::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cloak_DX90::CShader::OnInitShaderParams(
        Cloak_DX90::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  Cloak_DX9_Vars_t info; // [esp+4h] [ebp-58h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Cloak_DX90::CShader::SetupVars(this, &info);
  InitParamsCloak_DX9(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10008970
// Name: public: virtual char const __near * Cloak_DX90::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Cloak_DX90::CShader::GetName(Cloak_DX90::CShader *this)
{
  return s_Name_15;
}

//------------------------------------------------------------------------------
// Address: 0x10008980
// Name: public: virtual int Cloak_DX90::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Cloak_DX90::CShader::GetFlags(Cloak_DX90::CShader *this)
{
  return s_nFlags_56;
}

//------------------------------------------------------------------------------
// Address: 0x10008990
// Name: public: virtual void Cloak_DX90::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cloak_DX90::CShader::OnInitShaderInstance(
        Cloak_DX90::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  Cloak_DX9_Vars_t info; // [esp+4h] [ebp-58h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Cloak_DX90::CShader::SetupVars(this, &info);
  InitCloak_DX9(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x100089D0
// Name: public: virtual void Cloak_DX90::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cloak_DX90::CShader::OnDrawElements(
        Cloak_DX90::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  Cloak_DX9_Vars_t info; // [esp+4h] [ebp-58h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Cloak_DX90::CShader::SetupVars(this, &info);
  DrawCloak_DX9(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10008A20
// Name: public: virtual int Cloak_DX90::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Cloak_DX90::CShader::GetParamCount(Cloak_DX90::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_15.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008A30
// Name: public: virtual struct ShaderParamInfo_t const __near & Cloak::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Cloak::CShaderParam *__thiscall Cloak::CShader::GetParamInfo(Cloak::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_14.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Cloak::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10008A60
// Name: public: virtual struct ShaderParamInfo_t const __near & Cloak_DX90::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *__thiscall Cloak_DX90::CShader::GetParamInfo(Cloak_DX90::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_15.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Cloak_DX90::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10008A90
// Name: public: Cloak_DX90::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *__thiscall Cloak_DX90::CShaderParam::CShaderParam(
        Cloak_DX90::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Cloak_DX90::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Cloak_DX90::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_15.m_Size + 13;
  m_Size = s_ShaderParams_15.m_Size;
  v8 = s_ShaderParams_15.m_Size;
  if ( s_ShaderParams_15.m_Size + 1 > s_ShaderParams_15.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_15,
      num: s_ShaderParams_15.m_Size - s_ShaderParams_15.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_15.m_Size;
  }
  m_pMemory = s_ShaderParams_15.m_Memory.m_pMemory;
  s_ShaderParams_15.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_15.m_pElements = s_ShaderParams_15.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_15.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_15.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_15.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005F040
// Name: Cloak::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Cloak::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Cloak::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F050
// Name: Cloak::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Cloak::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_14);
  s_ShaderInstance_14.__vftable = (Cloak::CShader_vtbl *)&Cloak::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005F070
// Name: Cloak_DX90::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Cloak_DX90::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Cloak_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F080
// Name: Cloak_DX90::_dynamic_initializer_for__COLOR__
// Source: json
//------------------------------------------------------------------------------
void Cloak_DX90::_dynamic_initializer_for__COLOR__()
{
  s_pShaderParamOverrides[4] = &COLOR;
}

//------------------------------------------------------------------------------
// Address: 0x1005F090
// Name: Cloak_DX90::_dynamic_initializer_for__ALPHA__
// Source: json
//------------------------------------------------------------------------------
void Cloak_DX90::_dynamic_initializer_for__ALPHA__()
{
  s_pShaderParamOverrides[5] = &ALPHA_0;
}

//------------------------------------------------------------------------------
// Address: 0x1005F0A0
// Name: Cloak_DX90::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_0,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F0C0
// Name: Cloak_DX90::_dynamic_initializer_for__REFRACTTINT__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__REFRACTTINT__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTINT,
           pName: "$REFRACTTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "refraction tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F0E0
// Name: Cloak_DX90::_dynamic_initializer_for__NORMALMAP__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__NORMALMAP__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &NORMALMAP_1,
           pName: "$NORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F100
// Name: Cloak_DX90::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__BUMPFRAME__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &BUMPFRAME_1,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F120
// Name: Cloak_DX90::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_0,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F140
// Name: Cloak_DX90::_dynamic_initializer_for__TIME__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__TIME__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &TIME_0,
           pName: "$TIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0f",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F160
// Name: Cloak_DX90::_dynamic_initializer_for__REFRACTTINTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__REFRACTTINTTEXTURE__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTINTTEXTURE,
           pName: "$REFRACTTINTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shield",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F180
// Name: Cloak_DX90::_dynamic_initializer_for__REFRACTTINTTEXTUREFRAME__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__REFRACTTINTTEXTUREFRAME__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTINTTEXTUREFRAME,
           pName: "$REFRACTTINTTEXTUREFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F1A0
// Name: Cloak_DX90::_dynamic_initializer_for__FRESNELREFLECTION__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__FRESNELREFLECTION__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &FRESNELREFLECTION,
           pName: "$FRESNELREFLECTION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "1.0 == mirror, 0.0 == water",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F1C0
// Name: Cloak_DX90::_dynamic_initializer_for__NOWRITEZ__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__NOWRITEZ__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &NOWRITEZ,
           pName: "$NOWRITEZ",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "0 == write z, 1 = no write z",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F1E0
// Name: Cloak_DX90::_dynamic_initializer_for__MASKED__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__MASKED__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &MASKED,
           pName: "$MASKED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "mask using dest alpha",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F200
// Name: Cloak_DX90::_dynamic_initializer_for__CLOAKFACTOR__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__CLOAKFACTOR__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &CLOAKFACTOR,
           pName: "$CLOAKFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "How cloaked?  Zero is not cloaked, 1 is fully cloaked.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F220
// Name: Cloak_DX90::_dynamic_initializer_for__LIGHTWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__LIGHTWARPTEXTURE__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &LIGHTWARPTEXTURE_0,
           pName: "$LIGHTWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for tinting scalar diffuse term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F240
// Name: Cloak_DX90::_dynamic_initializer_for__PHONGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__PHONGEXPONENT__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT_0,
           pName: "$PHONGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "5.0",
           pHelp: "Phong exponent for local specular lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F260
// Name: Cloak_DX90::_dynamic_initializer_for__PHONGTINT__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__PHONGTINT__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &PHONGTINT,
           pName: "$PHONGTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "5.0",
           pHelp: "Phong tint for local specular lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F280
// Name: Cloak_DX90::_dynamic_initializer_for__PHONGALBEDOTINT__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__PHONGALBEDOTINT__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &PHONGALBEDOTINT,
           pName: "$PHONGALBEDOTINT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1.0",
           pHelp: "Apply tint by albedo (controlled by spec exponent texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F2A0
// Name: Cloak_DX90::_dynamic_initializer_for__PHONGFRESNELRANGES__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__PHONGFRESNELRANGES__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &PHONGFRESNELRANGES,
           pName: "$PHONGFRESNELRANGES",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0  0.5  1]",
           pHelp: "Parameters for remapping fresnel output",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F2C0
// Name: Cloak_DX90::_dynamic_initializer_for__PHONGBOOST__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__PHONGBOOST__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &PHONGBOOST_0,
           pName: "$PHONGBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Phong overbrightening factor (specular mask channel should be authored to account for this)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F2E0
// Name: Cloak_DX90::_dynamic_initializer_for__PHONGEXPONENTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__PHONGEXPONENTTEXTURE__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &PHONGEXPONENTTEXTURE,
           pName: "$PHONGEXPONENTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Phong Exponent map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F300
// Name: Cloak_DX90::_dynamic_initializer_for__RIMLIGHT__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__RIMLIGHT__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &RIMLIGHT,
           pName: "$RIMLIGHT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "enables rim lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F320
// Name: Cloak_DX90::_dynamic_initializer_for__RIMLIGHTEXPONENT__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__RIMLIGHTEXPONENT__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &RIMLIGHTEXPONENT_0,
           pName: "$RIMLIGHTEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4.0",
           pHelp: "Exponent for rim lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F340
// Name: Cloak_DX90::_dynamic_initializer_for__RIMLIGHTBOOST__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__RIMLIGHTBOOST__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &RIMLIGHTBOOST_0,
           pName: "$RIMLIGHTBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Boost for rim lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F360
// Name: Cloak_DX90::_dynamic_initializer_for__RIMMASK__
// Source: json
//------------------------------------------------------------------------------
Cloak_DX90::CShaderParam *Cloak_DX90::_dynamic_initializer_for__RIMMASK__()
{
  return Cloak_DX90::CShaderParam::CShaderParam(
           this: &RIMMASK,
           pName: "$RIMMASK",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Indicates whether or not to use alpha channel of exponent texture to mask the rim term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F380
// Name: Cloak_DX90::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Cloak_DX90::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_15);
  s_ShaderInstance_15.__vftable = (Cloak_DX90::CShader_vtbl *)&Cloak_DX90::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AF50
// Name: Cloak::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cloak::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_14);
}

//------------------------------------------------------------------------------
// Address: 0x1006AF60
// Name: Cloak_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cloak_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_15);
}

//------------------------------------------------------------------------------
// Address: 0x1005F3A0
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_blended_pass_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F3C0
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_blended_pass_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F3E0
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_blended_pass_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F400
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_blended_pass_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F420
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_blended_pass_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_blended_pass_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F440
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F460
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F480
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F4A0
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F4C0
// Name: _dynamic_initializer_for__s_ConstructMe_cloak_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cloak_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cloak_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F4E0
// Name: _dynamic_initializer_for__r_lightwarpidentity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_lightwarpidentity__()
{
  ConVar::ConVar(this: &r_lightwarpidentity, pName: "r_lightwarpidentity", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_lightwarpidentity__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F510
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___2()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_2);
}

//------------------------------------------------------------------------------
// Address: 0x1005F530
// Name: _dynamic_initializer_for__s_ConstructMe_colorcorrection_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_colorcorrection_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &colorcorrection_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F550
// Name: _dynamic_initializer_for__s_ConstructMe_colorcorrection_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_colorcorrection_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &colorcorrection_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006AF70
// Name: _dynamic_atexit_destructor_for__r_lightwarpidentity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_lightwarpidentity__()
{
  ConVar::~ConVar(this: &r_lightwarpidentity);
}
