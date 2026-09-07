// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/accumbuff4sample.cpp
// Functions: 19
// ============================================================

#include "materialsystem\stdshaders\accumbuff4sample.h"

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: public: bool IMaterialSystemHardwareConfig::SupportsPixelShaders_2_b(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IMaterialSystemHardwareConfig::SupportsPixelShaders_2_b(IMaterialSystemHardwareConfig *this)
{
  return this->GetDXSupportLevel(this) >= 92;
}

//------------------------------------------------------------------------------
// Address: 0x10001120
// Name: public: virtual char const __near * accumbuff4sample::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall accumbuff4sample::CShader::GetName(accumbuff4sample::CShader *this)
{
  return s_Name;
}

//------------------------------------------------------------------------------
// Address: 0x10001130
// Name: public: virtual int accumbuff4sample::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall accumbuff4sample::CShader::GetFlags(accumbuff4sample::CShader *this)
{
  return s_nFlags;
}

//------------------------------------------------------------------------------
// Address: 0x10001140
// Name: public: virtual void accumbuff4sample::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall accumbuff4sample::CShader::OnInitShaderInstance(
        accumbuff4sample::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE0.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE1.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE2.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: TEXTURE3.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001190
// Name: public: virtual void accumbuff4sample::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall accumbuff4sample::CShader::OnDrawElements(
        accumbuff4sample::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v7; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int v9; // [esp+0h] [ebp-8h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "screenspaceeffect_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v9 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "accumbuff4sample_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "accumbuff4sample_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE0.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE1.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE2.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: TEXTURE3.m_Index,
      nFrameVar: -1);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: WEIGHTS.m_Index);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v9);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: public: virtual int accumbuff4sample::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall accumbuff4sample::CShader::GetParamCount(accumbuff4sample::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: public: virtual struct ShaderParamInfo_t const __near & accumbuff4sample::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
accumbuff4sample::CShaderParam *__thiscall accumbuff4sample::CShader::GetParamInfo(
        accumbuff4sample::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams.m_Memory.m_pMemory[param - ParamCount];
  else
    return (accumbuff4sample::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10001340
// Name: public: accumbuff4sample::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
accumbuff4sample::CShaderParam *__thiscall accumbuff4sample::CShaderParam::CShaderParam(
        accumbuff4sample::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  accumbuff4sample::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  accumbuff4sample::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams.m_Size + 13;
  m_Size = s_ShaderParams.m_Size;
  v8 = s_ShaderParams.m_Size;
  if ( s_ShaderParams.m_Size + 1 > s_ShaderParams.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams,
      num: s_ShaderParams.m_Size - s_ShaderParams.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams.m_Size;
  }
  m_pMemory = s_ShaderParams.m_Memory.m_pMemory;
  s_ShaderParams.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams.m_pElements = s_ShaderParams.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005DDA0
// Name: accumbuff4sample::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int accumbuff4sample::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: accumbuff4sample::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005DDB0
// Name: accumbuff4sample::_dynamic_initializer_for__TEXTURE0__
// Source: json
//------------------------------------------------------------------------------
accumbuff4sample::CShaderParam *accumbuff4sample::_dynamic_initializer_for__TEXTURE0__()
{
  return accumbuff4sample::CShaderParam::CShaderParam(
           this: &TEXTURE0,
           pName: "$TEXTURE0",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DDD0
// Name: accumbuff4sample::_dynamic_initializer_for__TEXTURE1__
// Source: json
//------------------------------------------------------------------------------
accumbuff4sample::CShaderParam *accumbuff4sample::_dynamic_initializer_for__TEXTURE1__()
{
  return accumbuff4sample::CShaderParam::CShaderParam(
           this: &TEXTURE1,
           pName: "$TEXTURE1",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DDF0
// Name: accumbuff4sample::_dynamic_initializer_for__TEXTURE2__
// Source: json
//------------------------------------------------------------------------------
accumbuff4sample::CShaderParam *accumbuff4sample::_dynamic_initializer_for__TEXTURE2__()
{
  return accumbuff4sample::CShaderParam::CShaderParam(
           this: &TEXTURE2,
           pName: "$TEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DE10
// Name: accumbuff4sample::_dynamic_initializer_for__TEXTURE3__
// Source: json
//------------------------------------------------------------------------------
accumbuff4sample::CShaderParam *accumbuff4sample::_dynamic_initializer_for__TEXTURE3__()
{
  return accumbuff4sample::CShaderParam::CShaderParam(
           this: &TEXTURE3,
           pName: "$TEXTURE3",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DE30
// Name: accumbuff4sample::_dynamic_initializer_for__WEIGHTS__
// Source: json
//------------------------------------------------------------------------------
accumbuff4sample::CShaderParam *accumbuff4sample::_dynamic_initializer_for__WEIGHTS__()
{
  return accumbuff4sample::CShaderParam::CShaderParam(
           this: &WEIGHTS,
           pName: "$WEIGHTS",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: "Weight for Samples",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DE50
// Name: accumbuff4sample::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *accumbuff4sample::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance);
  s_ShaderInstance.__vftable = (accumbuff4sample::CShader_vtbl *)&accumbuff4sample::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AE40
// Name: accumbuff4sample::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl accumbuff4sample::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams);
}

//------------------------------------------------------------------------------
// Address: 0x1005DE70
// Name: _dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_screenspaceeffect_vs20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &screenspaceeffect_vs20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DE90
// Name: _dynamic_initializer_for__s_ConstructMe_accumbuff5sample_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_accumbuff5sample_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &accumbuff5sample_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005DEB0
// Name: _dynamic_initializer_for__s_ConstructMe_accumbuff5sample_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_accumbuff5sample_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &accumbuff5sample_ps20b_combos);
}
