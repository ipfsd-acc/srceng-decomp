// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/eyes_dx9.cpp
// Functions: 34
// ============================================================

#include "materialsystem\stdshaders\eyes_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x100125A0
// Name: public: virtual char const __near * eyes::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall eyes::CShader::GetFallbackShader(eyes::CShader *this, IMaterialVar **params)
{
  return "Eyes_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x100125B0
// Name: public: virtual char const __near * eyes::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall eyes::CShader::GetName(eyes::CShader *this)
{
  return s_Name_34;
}

//------------------------------------------------------------------------------
// Address: 0x100125C0
// Name: public: virtual int eyes::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall eyes::CShader::GetFlags(eyes::CShader *this)
{
  return s_nFlags_67;
}

//------------------------------------------------------------------------------
// Address: 0x100125D0
// Name: public: virtual int eyes::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall eyes::CShader::GetParamCount(eyes::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_34.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100125E0
// Name: public: void Eyes_dx9::CShader::SetupVars(struct Eyes_DX8_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Eyes_dx9::CShader::SetupVars(Eyes_dx9::CShader *this, Eyes_DX8_DX9_Vars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nFrame = 7;
  info->m_nIris = IRIS_0.m_Index;
  info->m_nIrisFrame = IRISFRAME_0.m_Index;
  info->m_nGlint = GLINT.m_Index;
  info->m_nEyeOrigin = EYEORIGIN_0.m_Index;
  info->m_nEyeUp = EYEUP.m_Index;
  info->m_nIrisU = IRISU_0.m_Index;
  info->m_nIrisV = IRISV_0.m_Index;
  info->m_nGlintU = GLINTU.m_Index;
  info->m_nGlintV = GLINTV.m_Index;
  info->m_nDilation = DILATION_0.m_Index;
  info->m_nEntityOrigin = ENTITYORIGIN_0.m_Index;
  info->m_nWarpParam = WARPPARAM_0.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10012670
// Name: public: virtual void Eyes_dx9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Eyes_dx9::CShader::OnInitShaderParams(
        Eyes_dx9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  Eyes_DX8_DX9_Vars_t info; // [esp+4h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Eyes_dx9::CShader::SetupVars(this, &info);
  InitParamsEyes_DX8_DX9(pShader: this, params);
}

//------------------------------------------------------------------------------
// Address: 0x100126C0
// Name: public: virtual char const __near * Eyes_dx9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Eyes_dx9::CShader::GetName(Eyes_dx9::CShader *this)
{
  return s_Name_35;
}

//------------------------------------------------------------------------------
// Address: 0x100126D0
// Name: public: virtual int Eyes_dx9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Eyes_dx9::CShader::GetFlags(Eyes_dx9::CShader *this)
{
  return s_nFlags_68;
}

//------------------------------------------------------------------------------
// Address: 0x100126E0
// Name: public: virtual void Eyes_dx9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Eyes_dx9::CShader::OnInitShaderInstance(
        Eyes_dx9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  Eyes_DX8_DX9_Vars_t info; // [esp+4h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Eyes_dx9::CShader::SetupVars(this, &info);
  InitEyes_DX8_DX9(pShader: this, params, &info);
}

//------------------------------------------------------------------------------
// Address: 0x10012720
// Name: public: virtual void Eyes_dx9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Eyes_dx9::CShader::OnDrawElements(
        Eyes_dx9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IMaterialVar **pShaderAPI,
        Eyes_DX8_DX9_Vars_t *vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  Eyes_DX8_DX9_Vars_t info; // [esp+4h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&info, value: 0xFFu, count: sizeof(info));
  Eyes_dx9::CShader::SetupVars(this, &info);
  DrawEyes_DX8_DX9(bDX9: true, pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10012770
// Name: public: virtual int Eyes_dx9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Eyes_dx9::CShader::GetParamCount(Eyes_dx9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_35.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10012780
// Name: public: virtual struct ShaderParamInfo_t const __near & eyes::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
eyes::CShaderParam *__thiscall eyes::CShader::GetParamInfo(eyes::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_34.m_Memory.m_pMemory[param - ParamCount];
  else
    return (eyes::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100127B0
// Name: public: virtual struct ShaderParamInfo_t const __near & Eyes_dx9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *__thiscall Eyes_dx9::CShader::GetParamInfo(Eyes_dx9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_35.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Eyes_dx9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100127E0
// Name: public: Eyes_dx9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *__thiscall Eyes_dx9::CShaderParam::CShaderParam(
        Eyes_dx9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Eyes_dx9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Eyes_dx9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_35.m_Size + 13;
  m_Size = s_ShaderParams_35.m_Size;
  v8 = s_ShaderParams_35.m_Size;
  if ( s_ShaderParams_35.m_Size + 1 > s_ShaderParams_35.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_35,
      num: s_ShaderParams_35.m_Size - s_ShaderParams_35.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_35.m_Size;
  }
  m_pMemory = s_ShaderParams_35.m_Memory.m_pMemory;
  s_ShaderParams_35.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_35.m_pElements = s_ShaderParams_35.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_35.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_35.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_35.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100611E0
// Name: eyes::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int eyes::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: eyes::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100611F0
// Name: eyes::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *eyes::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_34);
  s_ShaderInstance_34.__vftable = (eyes::CShader_vtbl *)&eyes::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061210
// Name: Eyes_dx9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Eyes_dx9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Eyes_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061220
// Name: Eyes_dx9::_dynamic_initializer_for__IRIS__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__IRIS__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &IRIS_0,
           pName: "$IRIS",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "iris texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061240
// Name: Eyes_dx9::_dynamic_initializer_for__IRISFRAME__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__IRISFRAME__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &IRISFRAME_0,
           pName: "$IRISFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame for the iris texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061260
// Name: Eyes_dx9::_dynamic_initializer_for__GLINT__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__GLINT__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &GLINT,
           pName: "$GLINT",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "glint texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061280
// Name: Eyes_dx9::_dynamic_initializer_for__EYEORIGIN__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__EYEORIGIN__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &EYEORIGIN_0,
           pName: "$EYEORIGIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: "origin for the eyes",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100612A0
// Name: Eyes_dx9::_dynamic_initializer_for__EYEUP__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__EYEUP__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &EYEUP,
           pName: "$EYEUP",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 1]",
           pHelp: "up vector for the eyes",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100612C0
// Name: Eyes_dx9::_dynamic_initializer_for__IRISU__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__IRISU__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &IRISU_0,
           pName: "$IRISU",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 1 0 0 ]",
           pHelp: "U projection vector for the iris",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100612E0
// Name: Eyes_dx9::_dynamic_initializer_for__IRISV__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__IRISV__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &IRISV_0,
           pName: "$IRISV",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 1 0]",
           pHelp: "V projection vector for the iris",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061300
// Name: Eyes_dx9::_dynamic_initializer_for__GLINTU__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__GLINTU__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &GLINTU,
           pName: "$GLINTU",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 1 0 0]",
           pHelp: "U projection vector for the glint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061320
// Name: Eyes_dx9::_dynamic_initializer_for__GLINTV__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__GLINTV__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &GLINTV,
           pName: "$GLINTV",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: "[0 0 1 0]",
           pHelp: "V projection vector for the glint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061340
// Name: Eyes_dx9::_dynamic_initializer_for__DILATION__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__DILATION__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &DILATION_0,
           pName: "$DILATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Pupil dilation (0 is none, 1 is maximal)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061360
// Name: Eyes_dx9::_dynamic_initializer_for__ENTITYORIGIN__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__ENTITYORIGIN__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &ENTITYORIGIN_0,
           pName: "$ENTITYORIGIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "0.0",
           pHelp: "center if the model in world space",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061380
// Name: Eyes_dx9::_dynamic_initializer_for__WARPPARAM__
// Source: json
//------------------------------------------------------------------------------
Eyes_dx9::CShaderParam *Eyes_dx9::_dynamic_initializer_for__WARPPARAM__()
{
  return Eyes_dx9::CShaderParam::CShaderParam(
           this: &WARPPARAM_0,
           pName: "$WARPPARAM",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "animation param between 0 and 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100613A0
// Name: Eyes_dx9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Eyes_dx9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_35);
  s_ShaderInstance_35.__vftable = (Eyes_dx9::CShader_vtbl *)&Eyes_dx9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B1C0
// Name: eyes::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl eyes::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_34);
}

//------------------------------------------------------------------------------
// Address: 0x1006B1D0
// Name: Eyes_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Eyes_dx9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_35);
}

//------------------------------------------------------------------------------
// Address: 0x100613C0
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___3()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_3);
}

//------------------------------------------------------------------------------
// Address: 0x100613E0
// Name: _dynamic_initializer_for__s_ConstructMe_filmdust_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_filmdust_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &filmdust_ps20_combos);
}
