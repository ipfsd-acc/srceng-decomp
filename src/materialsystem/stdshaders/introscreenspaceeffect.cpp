// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/introscreenspaceeffect.cpp
// Functions: 12
// ============================================================

#include "materialsystem\stdshaders\introscreenspaceeffect.h"

//------------------------------------------------------------------------------
// Address: 0x10016C60
// Name: public: virtual void IntroScreenSpaceEffect::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IntroScreenSpaceEffect::CShader::OnInitShaderParams(
        IntroScreenSpaceEffect::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x8000);
  if ( !params[ENABLESRGB.m_Index]->IsDefined(this: params[ENABLESRGB.m_Index]) )
    params[ENABLESRGB.m_Index]->SetIntValue(this: params[ENABLESRGB.m_Index], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016CB0
// Name: public: virtual char const __near * IntroScreenSpaceEffect::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IntroScreenSpaceEffect::CShader::GetName(IntroScreenSpaceEffect::CShader *this)
{
  return s_Name_50;
}

//------------------------------------------------------------------------------
// Address: 0x10016CC0
// Name: public: virtual int IntroScreenSpaceEffect::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IntroScreenSpaceEffect::CShader::GetFlags(IntroScreenSpaceEffect::CShader *this)
{
  return s_nFlags_22;
}

//------------------------------------------------------------------------------
// Address: 0x10016CD0
// Name: public: virtual void IntroScreenSpaceEffect::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IntroScreenSpaceEffect::CShader::OnDrawElements(
        IntroScreenSpaceEffect::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int m_intVal; // edi

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    if ( params[ENABLESRGB.m_Index]->m_intVal != 0 )
    {
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    }
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "LINEAR_TO_SRGB", 0, "bNeedsSRGBAdapter");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "introscreenspaceeffect_ps20b", a3: 0);
    }
    else
    {
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "introscreenspaceeffect_ps20", a3: 0);
    }
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE);
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER0,
      a3: TEXTURE_BINDFLAGS_SRGBREAD,
      a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER1,
      a3: TEXTURE_BINDFLAGS_SRGBREAD,
      a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      m_intVal = params[MODE.m_Index]->m_intVal;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "MODE", m_intVal, "params[MODE]->GetIntValue()");
    }
    else
    {
      m_intVal = params[MODE.m_Index]->m_intVal;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "MODE", m_intVal, "params[MODE]->GetIntValue()");
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: m_intVal);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: 5);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10016E90
// Name: public: virtual int IntroScreenSpaceEffect::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IntroScreenSpaceEffect::CShader::GetParamCount(IntroScreenSpaceEffect::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_50.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10016EA0
// Name: public: virtual struct ShaderParamInfo_t const __near & IntroScreenSpaceEffect::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
IntroScreenSpaceEffect::CShaderParam *__thiscall IntroScreenSpaceEffect::CShader::GetParamInfo(
        IntroScreenSpaceEffect::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_50.m_Memory.m_pMemory[param - ParamCount];
  else
    return (IntroScreenSpaceEffect::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10016ED0
// Name: public: IntroScreenSpaceEffect::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
IntroScreenSpaceEffect::CShaderParam *__thiscall IntroScreenSpaceEffect::CShaderParam::CShaderParam(
        IntroScreenSpaceEffect::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  IntroScreenSpaceEffect::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  IntroScreenSpaceEffect::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_50.m_Size + 13;
  m_Size = s_ShaderParams_50.m_Size;
  v8 = s_ShaderParams_50.m_Size;
  if ( s_ShaderParams_50.m_Size + 1 > s_ShaderParams_50.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_50,
      num: s_ShaderParams_50.m_Size - s_ShaderParams_50.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_50.m_Size;
  }
  m_pMemory = s_ShaderParams_50.m_Memory.m_pMemory;
  s_ShaderParams_50.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_50.m_pElements = s_ShaderParams_50.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_50.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_50.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_50.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062460
// Name: IntroScreenSpaceEffect::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int IntroScreenSpaceEffect::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: IntroScreenSpaceEffect::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10062470
// Name: IntroScreenSpaceEffect::_dynamic_initializer_for__MODE__
// Source: json
//------------------------------------------------------------------------------
IntroScreenSpaceEffect::CShaderParam *IntroScreenSpaceEffect::_dynamic_initializer_for__MODE__()
{
  return IntroScreenSpaceEffect::CShaderParam::CShaderParam(
           this: &MODE,
           pName: "$MODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062490
// Name: IntroScreenSpaceEffect::_dynamic_initializer_for__ENABLESRGB__
// Source: json
//------------------------------------------------------------------------------
IntroScreenSpaceEffect::CShaderParam *IntroScreenSpaceEffect::_dynamic_initializer_for__ENABLESRGB__()
{
  return IntroScreenSpaceEffect::CShaderParam::CShaderParam(
           this: &ENABLESRGB,
           pName: "$ENABLESRGB",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100624B0
// Name: IntroScreenSpaceEffect::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *IntroScreenSpaceEffect::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_50);
  s_ShaderInstance_50.__vftable = (IntroScreenSpaceEffect::CShader_vtbl *)&IntroScreenSpaceEffect::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B2C0
// Name: IntroScreenSpaceEffect::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl IntroScreenSpaceEffect::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_50);
}
