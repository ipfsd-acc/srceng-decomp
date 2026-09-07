// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sfm_shape.cpp
// Functions: 12
// ============================================================

#include "materialsystem\stdshaders\sfm_shape.h"

//------------------------------------------------------------------------------
// Address: 0x1002C8C0
// Name: public: virtual char const __near * sfm_shape_shader::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall sfm_shape_shader::CShader::GetFallbackShader(
        sfm_blurfilterx_shader::CShader *this,
        IMaterialVar **params)
{
  return g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 95 ? nullptr : "Wireframe";
}

//------------------------------------------------------------------------------
// Address: 0x1002D5E0
// Name: public: virtual char const __near * sfm_shape_shader::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall sfm_shape_shader::CShader::GetName(sfm_shape_shader::CShader *this)
{
  return s_Name_100;
}

//------------------------------------------------------------------------------
// Address: 0x1002D5F0
// Name: public: virtual int sfm_shape_shader::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_shape_shader::CShader::GetFlags(sfm_shape_shader::CShader *this)
{
  return s_nFlags_37;
}

//------------------------------------------------------------------------------
// Address: 0x1002D600
// Name: public: virtual void sfm_shape_shader::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sfm_shape_shader::CShader::OnDrawElements(
        sfm_shape_shader::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "sfm_screenspace_vs30", a3: 0);
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "sfm_shape_ps30", a3: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->SetScreenSizeForVPOS(this: pShaderAPI, a2: 32);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002D6D0
// Name: public: virtual int sfm_shape_shader::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_shape_shader::CShader::GetParamCount(sfm_shape_shader::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_100.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D6E0
// Name: public: virtual struct ShaderParamInfo_t const __near & sfm_shape_shader::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
sfm_shape_shader::CShaderParam *__thiscall sfm_shape_shader::CShader::GetParamInfo(
        sfm_shape_shader::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_100.m_Memory.m_pMemory[param - ParamCount];
  else
    return (sfm_shape_shader::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10065F60
// Name: sfm_shape_shader::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int sfm_shape_shader::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: sfm_shape_shader::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10065F70
// Name: sfm_shape_shader::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *sfm_shape_shader::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_100);
  s_ShaderInstance_100.__vftable = (sfm_shape_shader::CShader_vtbl *)&sfm_shape_shader::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B6B0
// Name: sfm_shape_shader::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl sfm_shape_shader::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_100);
}

//------------------------------------------------------------------------------
// Address: 0x10065F90
// Name: _dynamic_initializer_for__s_ConstructMe_shadow_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_shadow_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &shadow_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10065FB0
// Name: _dynamic_initializer_for__s_ConstructMe_shadow_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_shadow_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &shadow_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10065FD0
// Name: _dynamic_initializer_for__s_ConstructMe_shadow_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_shadow_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &shadow_vs20_combos);
}
