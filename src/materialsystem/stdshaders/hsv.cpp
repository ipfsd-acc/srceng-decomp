// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/hsv.cpp
// Functions: 8
// ============================================================

#include "materialsystem\stdshaders\hsv.h"

//------------------------------------------------------------------------------
// Address: 0x10014F30
// Name: public: virtual char const __near * HSV::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall HSV::CShader::GetName(HSV::CShader *this)
{
  return s_Name_47;
}

//------------------------------------------------------------------------------
// Address: 0x10014F40
// Name: public: virtual int HSV::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall HSV::CShader::GetFlags(HSV::CShader *this)
{
  return s_nFlags_21;
}

//------------------------------------------------------------------------------
// Address: 0x10014F50
// Name: public: virtual void HSV::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall HSV::CShader::OnDrawElements(
        HSV::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v7; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "hsv_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "hsv_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER0,
      a3: TEXTURE_BINDFLAGS_NONE,
      a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10014FF0
// Name: public: virtual int HSV::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall HSV::CShader::GetParamCount(HSV::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_47.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10015000
// Name: public: virtual struct ShaderParamInfo_t const __near & HSV::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
HSV::CShaderParam *__thiscall HSV::CShader::GetParamInfo(HSV::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_47.m_Memory.m_pMemory[param - ParamCount];
  else
    return (HSV::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10061ED0
// Name: HSV::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int HSV::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: HSV::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061EE0
// Name: HSV::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *HSV::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_47);
  s_ShaderInstance_47.__vftable = (HSV::CShader_vtbl *)&HSV::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B290
// Name: HSV::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl HSV::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_47);
}
