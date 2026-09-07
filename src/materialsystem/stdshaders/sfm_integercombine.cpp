// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sfm_integercombine.cpp
// Functions: 16
// ============================================================

#include "materialsystem\stdshaders\sfm_integercombine.h"

//------------------------------------------------------------------------------
// Address: 0x1002D340
// Name: public: virtual char const __near * sfm_integercombine_shader::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall sfm_integercombine_shader::CShader::GetName(sfm_integercombine_shader::CShader *this)
{
  return s_Name_99;
}

//------------------------------------------------------------------------------
// Address: 0x1002D350
// Name: public: virtual int sfm_integercombine_shader::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_integercombine_shader::CShader::GetFlags(sfm_integercombine_shader::CShader *this)
{
  return s_nFlags_36;
}

//------------------------------------------------------------------------------
// Address: 0x1002D360
// Name: public: virtual void sfm_integercombine_shader::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sfm_integercombine_shader::CShader::OnInitShaderInstance(
        sfm_integercombine_shader::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: ORIGINALTEXTURE.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: BLURREDTEXTURE.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002D390
// Name: public: virtual void sfm_integercombine_shader::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge sfm_integercombine_shader::CShader::OnDrawElements(
        sfm_integercombine_shader::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v8; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  bool v10; // bl
  int v12; // [esp+0h] [ebp-8h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "sfm_combine_vs20", a3: 0);
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v12 = 0;
    if ( v8 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "sfm_integercombine_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "sfm_integercombine_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: ORIGINALTEXTURE.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BLURREDTEXTURE.m_Index,
      nFrameVar: -1);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: BLOOMAMOUNT_3.m_Index);
    v10 = params[ISFLOAT.m_Index]->m_intVal != 0;
    ((void (__thiscall *)(IShaderDynamicAPI *, _DWORD, int))pShaderAPI->SetVertexShaderIndex)(
      a1: pShaderAPI,
      a2: 0,
      a3: a2);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v12);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "ISFLOAT", v10, "bIsFloat");
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v10);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002D500
// Name: public: virtual int sfm_integercombine_shader::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall sfm_integercombine_shader::CShader::GetParamCount(sfm_integercombine_shader::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_99.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D510
// Name: public: virtual struct ShaderParamInfo_t const __near & sfm_integercombine_shader::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
sfm_integercombine_shader::CShaderParam *__thiscall sfm_integercombine_shader::CShader::GetParamInfo(
        sfm_integercombine_shader::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_99.m_Memory.m_pMemory[param - ParamCount];
  else
    return (sfm_integercombine_shader::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002D540
// Name: public: sfm_integercombine_shader::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
sfm_integercombine_shader::CShaderParam *__thiscall sfm_integercombine_shader::CShaderParam::CShaderParam(
        sfm_integercombine_shader::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  sfm_integercombine_shader::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  sfm_integercombine_shader::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_99.m_Size + 13;
  m_Size = s_ShaderParams_99.m_Size;
  v8 = s_ShaderParams_99.m_Size;
  if ( s_ShaderParams_99.m_Size + 1 > s_ShaderParams_99.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_99,
      num: s_ShaderParams_99.m_Size - s_ShaderParams_99.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_99.m_Size;
  }
  m_pMemory = s_ShaderParams_99.m_Memory.m_pMemory;
  s_ShaderParams_99.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_99.m_pElements = s_ShaderParams_99.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_99.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_99.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_99.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10065E70
// Name: sfm_integercombine_shader::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int sfm_integercombine_shader::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: sfm_integercombine_shader::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10065E80
// Name: sfm_integercombine_shader::_dynamic_initializer_for__ORIGINALTEXTURE__
// Source: json
//------------------------------------------------------------------------------
sfm_integercombine_shader::CShaderParam *sfm_integercombine_shader::_dynamic_initializer_for__ORIGINALTEXTURE__()
{
  return sfm_integercombine_shader::CShaderParam::CShaderParam(
           this: &ORIGINALTEXTURE,
           pName: "$ORIGINALTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065EA0
// Name: sfm_integercombine_shader::_dynamic_initializer_for__BLURREDTEXTURE__
// Source: json
//------------------------------------------------------------------------------
sfm_integercombine_shader::CShaderParam *sfm_integercombine_shader::_dynamic_initializer_for__BLURREDTEXTURE__()
{
  return sfm_integercombine_shader::CShaderParam::CShaderParam(
           this: &BLURREDTEXTURE,
           pName: "$BLURREDTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065EC0
// Name: sfm_integercombine_shader::_dynamic_initializer_for__BLOOMAMOUNT__
// Source: json
//------------------------------------------------------------------------------
sfm_integercombine_shader::CShaderParam *sfm_integercombine_shader::_dynamic_initializer_for__BLOOMAMOUNT__()
{
  return sfm_integercombine_shader::CShaderParam::CShaderParam(
           this: &BLOOMAMOUNT_3,
           pName: "$BLOOMAMOUNT",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065EE0
// Name: sfm_integercombine_shader::_dynamic_initializer_for__ISFLOAT__
// Source: json
//------------------------------------------------------------------------------
sfm_integercombine_shader::CShaderParam *sfm_integercombine_shader::_dynamic_initializer_for__ISFLOAT__()
{
  return sfm_integercombine_shader::CShaderParam::CShaderParam(
           this: &ISFLOAT,
           pName: "$ISFLOAT",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065F00
// Name: sfm_integercombine_shader::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *sfm_integercombine_shader::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_99);
  s_ShaderInstance_99.__vftable = (sfm_integercombine_shader::CShader_vtbl *)&sfm_integercombine_shader::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B6A0
// Name: sfm_integercombine_shader::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl sfm_integercombine_shader::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_99);
}

//------------------------------------------------------------------------------
// Address: 0x10065F20
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_screenspace_vs30___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_screenspace_vs30___1()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_screenspace_vs30_combos_1);
}

//------------------------------------------------------------------------------
// Address: 0x10065F40
// Name: _dynamic_initializer_for__s_ConstructMe_sfm_shape_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sfm_shape_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sfm_shape_ps30_combos);
}
