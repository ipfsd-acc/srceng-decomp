// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sfm_downsample.cpp
// Functions: 11
// ============================================================

#include "materialsystem\stdshaders\sfm_downsample.h"

//------------------------------------------------------------------------------
// Address: 0x1002D0A0
// Name: public: virtual char const __near * sfm_downsample_shader::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall sfm_downsample_shader::CShader::GetName(sfm_downsample_shader::CShader *this)
{
  return s_Name_98;
}

//------------------------------------------------------------------------------
// Address: 0x1002D0B0
// Name: public: virtual int sfm_downsample_shader::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_downsample_shader::CShader::GetFlags(sfm_downsample_shader::CShader *this)
{
  return s_nFlags_35;
}

//------------------------------------------------------------------------------
// Address: 0x1002D0C0
// Name: public: virtual void sfm_downsample_shader::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sfm_downsample_shader::CShader::OnDrawElements(
        sfm_downsample_shader::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IShaderShadow *v6; // esi
  IShaderDynamicAPI *v8; // esi
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v10; // xmm0_4
  float v11; // xmm1_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v13)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v[4][4]; // [esp+8h] [ebp-60h] BYREF
  float vPsConst1[4]; // [esp+48h] [ebp-20h] BYREF
  float flPixelShaderParams[4]; // [esp+58h] [ebp-10h] BYREF

  v6 = pShaderShadow;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    v6->EnableAlphaWrites(this: v6, a2: true);
    v6->EnableTexture(this: v6, a2: SHADER_SAMPLER0, a3: true);
    v6->EnableSRGBRead(this: v6, a2: SHADER_SAMPLER0, a3: false);
    v6->EnableSRGBWrite(this: v6, a2: false);
    v6->VertexShaderVertexFormat(this: v6, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    v6->SetVertexShader(this: v6, a2: "downsample_vs20", a3: 0);
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   PS stat var %s = %d (%s)", "BLOOMTYPE", 0, "0");
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "PS3REGCOUNT48", 0, "0");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SRGB_INPUT_ADAPTER", 0, "0");
      }
    }
    v6->SetPixelShader(this: v6, a2: "downsample_nohdr_ps20b", a3: 0);
  }
  v8 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    v8->GetCurrentRenderTargetDimensions(this: v8, a2: (int *)&pShaderShadow, a3: (int *)&pShaderAPI);
    SetVertexShaderConstant = v8->SetVertexShaderConstant;
    v10 = 1.0 / (float)(int)pShaderShadow;
    v11 = 1.0 / (float)(int)pShaderAPI;
    v[0][0] = v10 * 0.5;
    v[0][1] = v11 * 0.5;
    v[1][0] = v10 * 2.5;
    v[1][1] = v11 * 0.5;
    v[2][0] = v10 * 0.5;
    v[2][1] = v11 * 2.5;
    v[3][0] = v10 * 2.5;
    v[3][1] = v11 * 2.5;
    SetVertexShaderConstant(this: v8, a2: 48, a3: v[0], a4: 4, a5: false);
    v8->SetVertexShaderIndex(this: v8, a2: 0);
    SetPixelShaderConstant = v8->SetPixelShaderConstant;
    flPixelShaderParams[0] = 1.0;
    flPixelShaderParams[1] = 1.0;
    flPixelShaderParams[2] = 1.0;
    flPixelShaderParams[3] = 2.2;
    SetPixelShaderConstant(this: v8, a2: 0, a3: flPixelShaderParams, a4: 1, a5: false);
    v13 = v8->SetPixelShaderConstant;
    memset(vPsConst1, 0, sizeof(vPsConst1));
    v13(this: v8, a2: 1, a3: vPsConst1, a4: 1, a5: false);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "FLOAT_BACK_BUFFER", 1, "1");
    v8->SetPixelShaderIndex(this: v8, a2: 1);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002D300
// Name: public: virtual int sfm_downsample_shader::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_downsample_shader::CShader::GetParamCount(sfm_downsample_shader::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_98.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D310
// Name: public: virtual struct ShaderParamInfo_t const __near & sfm_downsample_shader::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
sfm_downsample_shader::CShaderParam *__thiscall sfm_downsample_shader::CShader::GetParamInfo(
        sfm_downsample_shader::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_98.m_Memory.m_pMemory[param - ParamCount];
  else
    return (sfm_downsample_shader::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10065DE0
// Name: sfm_downsample_shader::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int sfm_downsample_shader::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: sfm_downsample_shader::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10065DF0
// Name: sfm_downsample_shader::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *sfm_downsample_shader::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_98);
  s_ShaderInstance_98.__vftable = (sfm_downsample_shader::CShader_vtbl *)&sfm_downsample_shader::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B690
// Name: sfm_downsample_shader::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl sfm_downsample_shader::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_98);
}

//------------------------------------------------------------------------------
// Address: 0x10065E10
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_combine_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_combine_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_combine_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10065E30
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_integercombine_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_integercombine_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_integercombine_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10065E50
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_integercombine_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_integercombine_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_integercombine_ps20b_combos);
}
