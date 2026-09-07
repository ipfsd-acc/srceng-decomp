// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/refract.cpp
// Functions: 54
// ============================================================

#include "materialsystem\stdshaders\refract.h"

//------------------------------------------------------------------------------
// Address: 0x10029720
// Name: public: virtual char const __near * Refract::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Refract::CShader::GetFallbackShader(Refract::CShader *this, IMaterialVar **params)
{
  return "Refract_DX90";
}

//------------------------------------------------------------------------------
// Address: 0x10029730
// Name: public: virtual char const __near * Refract::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Refract::CShader::GetName(Refract::CShader *this)
{
  return s_Name_88;
}

//------------------------------------------------------------------------------
// Address: 0x10029740
// Name: public: virtual int Refract::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Refract::CShader::GetFlags(Refract::CShader *this)
{
  return s_nFlags_105;
}

//------------------------------------------------------------------------------
// Address: 0x10029750
// Name: public: virtual int Refract::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Refract::CShader::GetParamCount(Refract::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_88.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10029760
// Name: public: void Refract_DX90::CShader::SetupVars(struct Refract_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Refract_DX90::CShader::SetupVars(Refract_DX90::CShader *this, Refract_DX9_Vars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nFrame = 7;
  info->m_nRefractAmount = REFRACTAMOUNT_4.m_Index;
  info->m_nRefractTint = REFRACTTINT_1.m_Index;
  info->m_nNormalMap = NORMALMAP_5.m_Index;
  info->m_nNormalMap2 = NORMALMAP2.m_Index;
  info->m_nBumpFrame = BUMPFRAME_10.m_Index;
  info->m_nBumpFrame2 = BUMPFRAME2_0.m_Index;
  info->m_nBumpTransform = BUMPTRANSFORM_4.m_Index;
  info->m_nBumpTransform2 = BUMPTRANSFORM2_0.m_Index;
  info->m_nBlurAmount = BLURAMOUNT_0.m_Index;
  info->m_nFadeOutOnSilhouette = FADEOUTONSILHOUETTE.m_Index;
  info->m_nEnvmap = ENVMAP_3.m_Index;
  info->m_nEnvmapFrame = ENVMAPFRAME_0.m_Index;
  info->m_nEnvmapTint = ENVMAPTINT_1.m_Index;
  info->m_nEnvmapContrast = ENVMAPCONTRAST_0.m_Index;
  info->m_nEnvmapSaturation = ENVMAPSATURATION_0.m_Index;
  info->m_nRefractTintTexture = REFRACTTINTTEXTURE_0.m_Index;
  info->m_nRefractTintTextureFrame = REFRACTTINTTEXTUREFRAME_0.m_Index;
  info->m_nFresnelReflection = FRESNELREFLECTION_1.m_Index;
  info->m_nNoWriteZ = NOWRITEZ_0.m_Index;
  info->m_nMasked = MASKED_0.m_Index;
  info->m_nVertexColorModulate = VERTEXCOLORMODULATE.m_Index;
  info->m_nNoViewportFixup = NOVIEWPORTFIXUP.m_Index;
  info->m_nMirrorAboutViewportEdges = MIRRORABOUTVIEWPORTEDGES.m_Index;
  info->m_nMagnifyEnable = MAGNIFYENABLE.m_Index;
  info->m_nMagnifyCenter = MAGNIFYCENTER.m_Index;
  info->m_nMagnifyScale = MAGNIFYSCALE.m_Index;
  info->m_nLocalRefract = LOCALREFRACT.m_Index;
  info->m_nLocalRefractDepth = LOCALREFRACTDEPTH.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10029880
// Name: public: virtual void Refract_DX90::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Refract_DX90::CShader::OnInitShaderParams(
        Refract_DX90::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  Refract_DX9_Vars_t info; // [esp+4h] [ebp-78h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Refract_DX90::CShader::SetupVars(this, &info);
  InitParamsRefract_DX9(pShader: this, params, pMaterialName, &info);
}

//------------------------------------------------------------------------------
// Address: 0x100298D0
// Name: public: virtual char const __near * Refract_DX90::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Refract_DX90::CShader::GetName(Refract_DX90::CShader *this)
{
  return s_Name_89;
}

//------------------------------------------------------------------------------
// Address: 0x100298E0
// Name: public: virtual int Refract_DX90::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Refract_DX90::CShader::GetFlags(Refract_DX90::CShader *this)
{
  return s_nFlags_106;
}

//------------------------------------------------------------------------------
// Address: 0x100298F0
// Name: public: virtual void Refract_DX90::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Refract_DX90::CShader::OnInitShaderInstance(
        Refract_DX90::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  Refract_DX9_Vars_t info; // [esp+4h] [ebp-78h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Refract_DX90::CShader::SetupVars(this, &info);
  InitRefract_DX9(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10029930
// Name: public: virtual void Refract_DX90::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Refract_DX90::CShader::OnDrawElements(
        Refract_DX90::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v8; // al
  Refract_DX9_Vars_t info; // [esp+Ch] [ebp-78h] BYREF
  bool bHasFlashlight_3; // [esp+8Fh] [ebp+Bh]

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Refract_DX90::CShader::SetupVars(this, &info);
  bHasFlashlight_3 = CBaseShader::UsingFlashlight(this, params);
  v8 = pShaderAPI != nullptr && pShaderAPI->SinglePassFlashlightModeEnabled(this: pShaderAPI);
  if ( pShaderShadow != nullptr || !bHasFlashlight_3 || v8 )
    DrawRefract_DX9(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
  else
    CBaseShader::Draw(this, bMakeActualDrawCall: false);
}

//------------------------------------------------------------------------------
// Address: 0x100299C0
// Name: public: virtual int Refract_DX90::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Refract_DX90::CShader::GetParamCount(Refract_DX90::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_89.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100299D0
// Name: public: virtual struct ShaderParamInfo_t const __near & Refract::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Refract::CShaderParam *__thiscall Refract::CShader::GetParamInfo(Refract::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_88.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Refract::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10029A00
// Name: public: virtual struct ShaderParamInfo_t const __near & Refract_DX90::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *__thiscall Refract_DX90::CShader::GetParamInfo(Refract_DX90::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_89.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Refract_DX90::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10029A30
// Name: public: Refract_DX90::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *__thiscall Refract_DX90::CShaderParam::CShaderParam(
        Refract_DX90::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Refract_DX90::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Refract_DX90::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_89.m_Size + 13;
  m_Size = s_ShaderParams_89.m_Size;
  v8 = s_ShaderParams_89.m_Size;
  if ( s_ShaderParams_89.m_Size + 1 > s_ShaderParams_89.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_89,
      num: s_ShaderParams_89.m_Size - s_ShaderParams_89.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_89.m_Size;
  }
  m_pMemory = s_ShaderParams_89.m_Memory.m_pMemory;
  s_ShaderParams_89.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_89.m_pElements = s_ShaderParams_89.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_89.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_89.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_89.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064D30
// Name: Refract::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Refract::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Refract::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064D40
// Name: Refract::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Refract::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_88);
  s_ShaderInstance_88.__vftable = (Refract::CShader_vtbl *)&Refract::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064D60
// Name: Refract_DX90::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Refract_DX90::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Refract_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064D70
// Name: Refract_DX90::_dynamic_initializer_for__COLOR__
// Source: json
//------------------------------------------------------------------------------
void Refract_DX90::_dynamic_initializer_for__COLOR__()
{
  s_pShaderParamOverrides_2[4] = &COLOR_2;
}

//------------------------------------------------------------------------------
// Address: 0x10064D80
// Name: Refract_DX90::_dynamic_initializer_for__ALPHA__
// Source: json
//------------------------------------------------------------------------------
void Refract_DX90::_dynamic_initializer_for__ALPHA__()
{
  s_pShaderParamOverrides_2[5] = &ALPHA_3;
}

//------------------------------------------------------------------------------
// Address: 0x10064D90
// Name: Refract_DX90::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_4,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064DB0
// Name: Refract_DX90::_dynamic_initializer_for__REFRACTTINT__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__REFRACTTINT__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTINT_1,
           pName: "$REFRACTTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "refraction tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064DD0
// Name: Refract_DX90::_dynamic_initializer_for__NORMALMAP__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__NORMALMAP__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &NORMALMAP_5,
           pName: "$NORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064DF0
// Name: Refract_DX90::_dynamic_initializer_for__NORMALMAP2__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__NORMALMAP2__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &NORMALMAP2,
           pName: "$NORMALMAP2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064E10
// Name: Refract_DX90::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__BUMPFRAME__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &BUMPFRAME_10,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $normalmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064E30
// Name: Refract_DX90::_dynamic_initializer_for__BUMPFRAME2__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__BUMPFRAME2__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &BUMPFRAME2_0,
           pName: "$BUMPFRAME2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $normalmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064E50
// Name: Refract_DX90::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_4,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$normalmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064E70
// Name: Refract_DX90::_dynamic_initializer_for__BUMPTRANSFORM2__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__BUMPTRANSFORM2__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM2_0,
           pName: "$BUMPTRANSFORM2",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$normalmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064E90
// Name: Refract_DX90::_dynamic_initializer_for__TIME__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__TIME__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &TIME_2,
           pName: "$TIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0f",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064EB0
// Name: Refract_DX90::_dynamic_initializer_for__BLURAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__BLURAMOUNT__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &BLURAMOUNT_0,
           pName: "$BLURAMOUNT",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "1",
           pHelp: "0, 1, or 2 for how much blur you want",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064ED0
// Name: Refract_DX90::_dynamic_initializer_for__FADEOUTONSILHOUETTE__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__FADEOUTONSILHOUETTE__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &FADEOUTONSILHOUETTE,
           pName: "$FADEOUTONSILHOUETTE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "0 for no fade out on silhouette, 1 for fade out on sillhouette",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064EF0
// Name: Refract_DX90::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__ENVMAP__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &ENVMAP_3,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064F10
// Name: Refract_DX90::_dynamic_initializer_for__ENVMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__ENVMAPFRAME__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &ENVMAPFRAME_0,
           pName: "$ENVMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "envmap frame number",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064F30
// Name: Refract_DX90::_dynamic_initializer_for__ENVMAPTINT__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__ENVMAPTINT__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &ENVMAPTINT_1,
           pName: "$ENVMAPTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "envmap tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064F50
// Name: Refract_DX90::_dynamic_initializer_for__ENVMAPCONTRAST__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__ENVMAPCONTRAST__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &ENVMAPCONTRAST_0,
           pName: "$ENVMAPCONTRAST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "contrast 0 == normal 1 == color*color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064F70
// Name: Refract_DX90::_dynamic_initializer_for__ENVMAPSATURATION__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__ENVMAPSATURATION__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &ENVMAPSATURATION_0,
           pName: "$ENVMAPSATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "saturation 0 == greyscale 1 == normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064F90
// Name: Refract_DX90::_dynamic_initializer_for__REFRACTTINTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__REFRACTTINTTEXTURE__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTINTTEXTURE_0,
           pName: "$REFRACTTINTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shield",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064FB0
// Name: Refract_DX90::_dynamic_initializer_for__REFRACTTINTTEXTUREFRAME__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__REFRACTTINTTEXTUREFRAME__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTINTTEXTUREFRAME_0,
           pName: "$REFRACTTINTTEXTUREFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064FD0
// Name: Refract_DX90::_dynamic_initializer_for__FRESNELREFLECTION__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__FRESNELREFLECTION__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &FRESNELREFLECTION_1,
           pName: "$FRESNELREFLECTION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "1.0 == mirror, 0.0 == water",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065000
// Name: Refract_DX90::_dynamic_initializer_for__NOWRITEZ__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__NOWRITEZ__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &NOWRITEZ_0,
           pName: "$NOWRITEZ",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "0 == write z, 1 = no write z",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065020
// Name: Refract_DX90::_dynamic_initializer_for__MASKED__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__MASKED__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &MASKED_0,
           pName: "$MASKED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "mask using dest alpha",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065040
// Name: Refract_DX90::_dynamic_initializer_for__VERTEXCOLORMODULATE__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__VERTEXCOLORMODULATE__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &VERTEXCOLORMODULATE,
           pName: "$VERTEXCOLORMODULATE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Use the vertex color to effect refract color. alpha will adjust refract amount",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065060
// Name: Refract_DX90::_dynamic_initializer_for__NOVIEWPORTFIXUP__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__NOVIEWPORTFIXUP__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &NOVIEWPORTFIXUP,
           pName: "$NOVIEWPORTFIXUP",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Don't adjust uv's for current viewport",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065080
// Name: Refract_DX90::_dynamic_initializer_for__MIRRORABOUTVIEWPORTEDGES__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__MIRRORABOUTVIEWPORTEDGES__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &MIRRORABOUTVIEWPORTEDGES,
           pName: "$MIRRORABOUTVIEWPORTEDGES",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "don't sample outside of the viewport",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100650A0
// Name: Refract_DX90::_dynamic_initializer_for__MAGNIFYENABLE__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__MAGNIFYENABLE__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &MAGNIFYENABLE,
           pName: "$MAGNIFYENABLE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enable magnification of refracted image around the $magnifyCenter screen position by $magnifyScale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100650C0
// Name: Refract_DX90::_dynamic_initializer_for__MAGNIFYCENTER__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__MAGNIFYCENTER__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &MAGNIFYCENTER,
           pName: "$MAGNIFYCENTER",
           type: SHADER_PARAM_TYPE_VEC2,
           pDefaultParam: "[0 0]",
           pHelp: "Magnify refracted image around this screen position",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100650E0
// Name: Refract_DX90::_dynamic_initializer_for__MAGNIFYSCALE__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__MAGNIFYSCALE__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &MAGNIFYSCALE,
           pName: "$MAGNIFYSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Magnify refracted image by this factor",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065100
// Name: Refract_DX90::_dynamic_initializer_for__LOCALREFRACT__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__LOCALREFRACT__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &LOCALREFRACT,
           pName: "$LOCALREFRACT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065120
// Name: Refract_DX90::_dynamic_initializer_for__LOCALREFRACTDEPTH__
// Source: json
//------------------------------------------------------------------------------
Refract_DX90::CShaderParam *Refract_DX90::_dynamic_initializer_for__LOCALREFRACTDEPTH__()
{
  return Refract_DX90::CShaderParam::CShaderParam(
           this: &LOCALREFRACTDEPTH,
           pName: "$LOCALREFRACTDEPTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065140
// Name: Refract_DX90::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Refract_DX90::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_89);
  s_ShaderInstance_89.__vftable = (Refract_DX90::CShader_vtbl *)&Refract_DX90::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B5F0
// Name: Refract::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Refract::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_88);
}

//------------------------------------------------------------------------------
// Address: 0x1006B600
// Name: Refract_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Refract_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_89);
}

//------------------------------------------------------------------------------
// Address: 0x10065160
// Name: _dynamic_initializer_for__s_ConstructMe_Refract_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Refract_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Refract_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10065180
// Name: _dynamic_initializer_for__s_ConstructMe_Refract_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Refract_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Refract_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100651A0
// Name: _dynamic_initializer_for__s_ConstructMe_Refract_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Refract_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Refract_ps20b_combos);
}
