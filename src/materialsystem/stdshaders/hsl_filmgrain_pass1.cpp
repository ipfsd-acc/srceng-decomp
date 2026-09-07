// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/hsl_filmgrain_pass1.cpp
// Functions: 17
// ============================================================

#include "materialsystem\stdshaders\hsl_filmgrain_pass1.h"

//------------------------------------------------------------------------------
// Address: 0x10014AB0
// Name: public: virtual char const __near * hsl_filmgrain_pass1::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hsl_filmgrain_pass1::CShader::GetName(hsl_filmgrain_pass1::CShader *this)
{
  return s_Name_45;
}

//------------------------------------------------------------------------------
// Address: 0x10014AC0
// Name: public: virtual int hsl_filmgrain_pass1::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall hsl_filmgrain_pass1::CShader::GetFlags(hsl_filmgrain_pass1::CShader *this)
{
  return s_nFlags_70;
}

//------------------------------------------------------------------------------
// Address: 0x10014AD0
// Name: public: virtual void hsl_filmgrain_pass1::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hsl_filmgrain_pass1::CShader::OnInitShaderInstance(
        hsl_filmgrain_pass1::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: INPUT.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: GRAIN.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10014B00
// Name: public: virtual void hsl_filmgrain_pass1::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hsl_filmgrain_pass1::CShader::OnDrawElements(
        hsl_filmgrain_pass1::CShader *this,
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
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: false);
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "filmgrain_vs20", a3: 0);
    v7 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v9 = 0;
    if ( v7 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "hsl_filmgrain_pass1_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "hsl_filmgrain_pass1_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: INPUT.m_Index,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: GRAIN.m_Index,
      nFrameVar: -1);
    CBaseVSShader::SetVertexShaderConstant(this, vertexReg: 48, constantVar: SCALEBIAS.m_Index);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: HSLNOISESCALE.m_Index);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    ((void (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetDXSupportLevel)(
      a1: g_pHardwareConfig,
      a2: v9);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10014C30
// Name: public: virtual int hsl_filmgrain_pass1::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall hsl_filmgrain_pass1::CShader::GetParamCount(hsl_filmgrain_pass1::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_45.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10014C40
// Name: public: virtual struct ShaderParamInfo_t const __near & hsl_filmgrain_pass1::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
hsl_filmgrain_pass1::CShaderParam *__thiscall hsl_filmgrain_pass1::CShader::GetParamInfo(
        hsl_filmgrain_pass1::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_45.m_Memory.m_pMemory[param - ParamCount];
  else
    return (hsl_filmgrain_pass1::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10014C70
// Name: public: hsl_filmgrain_pass1::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
hsl_filmgrain_pass1::CShaderParam *__thiscall hsl_filmgrain_pass1::CShaderParam::CShaderParam(
        hsl_filmgrain_pass1::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  hsl_filmgrain_pass1::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  hsl_filmgrain_pass1::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_45.m_Size + 13;
  m_Size = s_ShaderParams_45.m_Size;
  v8 = s_ShaderParams_45.m_Size;
  if ( s_ShaderParams_45.m_Size + 1 > s_ShaderParams_45.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_45,
      num: s_ShaderParams_45.m_Size - s_ShaderParams_45.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_45.m_Size;
  }
  m_pMemory = s_ShaderParams_45.m_Memory.m_pMemory;
  s_ShaderParams_45.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_45.m_pElements = s_ShaderParams_45.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_45.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_45.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_45.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061D10
// Name: hsl_filmgrain_pass1::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int hsl_filmgrain_pass1::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: hsl_filmgrain_pass1::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10061D20
// Name: hsl_filmgrain_pass1::_dynamic_initializer_for__INPUT__
// Source: json
//------------------------------------------------------------------------------
hsl_filmgrain_pass1::CShaderParam *hsl_filmgrain_pass1::_dynamic_initializer_for__INPUT__()
{
  return hsl_filmgrain_pass1::CShaderParam::CShaderParam(
           this: &INPUT,
           pName: "$INPUT",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061D40
// Name: hsl_filmgrain_pass1::_dynamic_initializer_for__GRAIN__
// Source: json
//------------------------------------------------------------------------------
hsl_filmgrain_pass1::CShaderParam *hsl_filmgrain_pass1::_dynamic_initializer_for__GRAIN__()
{
  return hsl_filmgrain_pass1::CShaderParam::CShaderParam(
           this: &GRAIN,
           pName: "$GRAIN",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061D60
// Name: hsl_filmgrain_pass1::_dynamic_initializer_for__SCALEBIAS__
// Source: json
//------------------------------------------------------------------------------
hsl_filmgrain_pass1::CShaderParam *hsl_filmgrain_pass1::_dynamic_initializer_for__SCALEBIAS__()
{
  return hsl_filmgrain_pass1::CShaderParam::CShaderParam(
           this: &SCALEBIAS,
           pName: "$SCALEBIAS",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: "Scale and bias for grain placement",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061D80
// Name: hsl_filmgrain_pass1::_dynamic_initializer_for__HSLNOISESCALE__
// Source: json
//------------------------------------------------------------------------------
hsl_filmgrain_pass1::CShaderParam *hsl_filmgrain_pass1::_dynamic_initializer_for__HSLNOISESCALE__()
{
  return hsl_filmgrain_pass1::CShaderParam::CShaderParam(
           this: &HSLNOISESCALE,
           pName: "$HSLNOISESCALE",
           type: SHADER_PARAM_TYPE_VEC4,
           pDefaultParam: pDefaultParam,
           pHelp: "Strength of film grain",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10061DA0
// Name: hsl_filmgrain_pass1::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *hsl_filmgrain_pass1::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_45);
  s_ShaderInstance_45.__vftable = (hsl_filmgrain_pass1::CShader_vtbl *)&hsl_filmgrain_pass1::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B270
// Name: hsl_filmgrain_pass1::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl hsl_filmgrain_pass1::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_45);
}

//------------------------------------------------------------------------------
// Address: 0x10061DC0
// Name: _dynamic_initializer_for__s_ConstructMe_filmgrain_vs20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_filmgrain_vs20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &filmgrain_vs20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x10061DE0
// Name: _dynamic_initializer_for__s_ConstructMe_hsl_filmgrain_pass2_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_hsl_filmgrain_pass2_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &hsl_filmgrain_pass2_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10061E00
// Name: _dynamic_initializer_for__s_ConstructMe_hsl_filmgrain_pass2_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_hsl_filmgrain_pass2_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &hsl_filmgrain_pass2_ps20b_combos);
}
