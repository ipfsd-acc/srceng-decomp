// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/blurfilterx.cpp
// Functions: 14
// ============================================================

#include "materialsystem\stdshaders\blurfilterx.h"

//------------------------------------------------------------------------------
// Address: 0x100074D0
// Name: public: virtual void BlurFilterX::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlurFilterX::CShader::OnInitShaderParams(
        BlurFilterX::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[KERNEL.m_Index]->IsDefined(this: params[KERNEL.m_Index]) )
    params[KERNEL.m_Index]->SetIntValue(this: params[KERNEL.m_Index], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10007510
// Name: public: virtual char const __near * BlurFilterX::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BlurFilterX::CShader::GetName(BlurFilterX::CShader *this)
{
  return s_Name_8;
}

//------------------------------------------------------------------------------
// Address: 0x10007520
// Name: public: virtual int BlurFilterX::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlurFilterX::CShader::GetFlags(BlurFilterX::CShader *this)
{
  return s_nFlags_2;
}

//------------------------------------------------------------------------------
// Address: 0x10007530
// Name: public: virtual void BlurFilterX::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge BlurFilterX::CShader::OnDrawElements(
        BlurFilterX::CShader *this@<ecx>,
        int a2@<edi>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  BOOL v7; // edi
  int v8; // eax
  int v9; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v11)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v12)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v14)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v15)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v16)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v[4]; // [esp+8h] [ebp-14h] BYREF
  CBaseShader *v18; // [esp+18h] [ebp-4h]
  float pShaderShadowa; // [esp+28h] [ebp+Ch]

  v18 = this;
  if ( pShaderShadow != nullptr )
  {
    ((void (__thiscall *)(IShaderShadow *, _DWORD, int))pShaderShadow->EnableDepthWrites)(
      a1: pShaderShadow,
      a2: 0,
      a3: a2);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    v7 = params[KERNEL.m_Index]->m_intVal != 0;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "KERNEL", v7, "params[ KERNEL ]->GetIntValue() ? 1 : 0");
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "blurfilter_vs20", a3: v7);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "KERNEL",
          params[KERNEL.m_Index]->m_intVal,
          "params[ KERNEL ]->GetIntValue()");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "CLEAR_COLOR", 0, "false");
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS stat var %s = %d (%s)",
              "APPROX_SRGB_ADAPTER",
              0,
              "bForceSRGBReadAndWrite && ( params[ KERNEL ]->GetIntValue() != 0 )");
        }
      }
      ((void (__thiscall *)(IShaderShadow *, const char *))pShaderShadow->SetPixelShader)(
        a1: pShaderShadow,
        a2: "blurfilter_ps20b");
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "KERNEL",
          params[KERNEL.m_Index]->m_intVal,
          "params[ KERNEL ]->GetIntValue()");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "CLEAR_COLOR", 0, "false");
      }
      ((void (__thiscall *)(IShaderShadow *, const char *))pShaderShadow->SetPixelShader)(
        a1: pShaderShadow,
        a2: "blurfilter_ps20");
    }
    if ( ((*params)->m_intVal & 0x80) != 0 )
      CBaseShader::EnableAlphaBlending(this: v18, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v18,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    v8 = params[6]->GetTextureValue(this: params[6]);
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    pShaderShadowa = 1.0 / (float)v9;
    v[0] = pShaderShadowa * 1.3365999;
    memset(&v[1], 0, 12);
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: v, a4: 1, a5: false);
    v11 = pShaderAPI->SetVertexShaderConstant;
    v[0] = pShaderShadowa * 3.4295001;
    v[1] = 0.0;
    v11(this: pShaderAPI, a2: 49, a3: v, a4: 1, a5: false);
    v12 = pShaderAPI->SetVertexShaderConstant;
    v[0] = pShaderShadowa * 5.4264002;
    v[1] = 0.0;
    v12(this: pShaderAPI, a2: 50, a3: v, a4: 1, a5: false);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    v[0] = pShaderShadowa * 7.4359002;
    v[1] = 0.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: v, a4: 1, a5: false);
    v[0] = pShaderShadowa * 9.4435997;
    v[1] = 0.0;
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 1, a3: v, a4: 1, a5: false);
    v14 = pShaderAPI->SetPixelShaderConstant;
    v[0] = pShaderShadowa * 11.4401;
    v[1] = 0.0;
    v14(this: pShaderAPI, a2: 2, a3: v, a4: 1, a5: false);
    v15 = pShaderAPI->SetPixelShaderConstant;
    v[3] = 1.0;
    v[2] = 1.0;
    v[1] = 1.0;
    v[0] = 1.0;
    v15(this: pShaderAPI, a2: 3, a3: v, a4: 1, a5: false);
    v16 = pShaderAPI->SetPixelShaderConstant;
    memset(&v[1], 0, 12);
    v[0] = pShaderShadowa;
    v16(this: pShaderAPI, a2: 4, a3: v, a4: 1, a5: false);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this: v18, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100078E0
// Name: public: virtual int BlurFilterX::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlurFilterX::CShader::GetParamCount(BlurFilterX::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_8.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100078F0
// Name: public: virtual struct ShaderParamInfo_t const __near & BlurFilterX::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
BlurFilterX::CShaderParam *__thiscall BlurFilterX::CShader::GetParamInfo(BlurFilterX::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_8.m_Memory.m_pMemory[param - ParamCount];
  else
    return (BlurFilterX::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10007920
// Name: public: BlurFilterX::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BlurFilterX::CShaderParam *__thiscall BlurFilterX::CShaderParam::CShaderParam(
        BlurFilterX::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  BlurFilterX::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  BlurFilterX::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_8.m_Size + 13;
  m_Size = s_ShaderParams_8.m_Size;
  v8 = s_ShaderParams_8.m_Size;
  if ( s_ShaderParams_8.m_Size + 1 > s_ShaderParams_8.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_8,
      num: s_ShaderParams_8.m_Size - s_ShaderParams_8.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_8.m_Size;
  }
  m_pMemory = s_ShaderParams_8.m_Memory.m_pMemory;
  s_ShaderParams_8.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_8.m_pElements = s_ShaderParams_8.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_8.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_8.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_8.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005EC50
// Name: BlurFilterX::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int BlurFilterX::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: BlurFilterX::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005EC60
// Name: BlurFilterX::_dynamic_initializer_for__KERNEL__
// Source: json
//------------------------------------------------------------------------------
BlurFilterX::CShaderParam *BlurFilterX::_dynamic_initializer_for__KERNEL__()
{
  return BlurFilterX::CShaderParam::CShaderParam(
           this: &KERNEL,
           pName: "$KERNEL",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Kernel type",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EC80
// Name: BlurFilterX::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *BlurFilterX::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_8);
  s_ShaderInstance_8.__vftable = (BlurFilterX::CShader_vtbl *)&BlurFilterX::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AEF0
// Name: BlurFilterX::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlurFilterX::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_8);
}

//------------------------------------------------------------------------------
// Address: 0x1005ECA0
// Name: _dynamic_initializer_for__s_ConstructMe_BlurFilter_vs20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_BlurFilter_vs20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &BlurFilter_vs20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x1005ECC0
// Name: _dynamic_initializer_for__s_ConstructMe_BlurFilter_ps20___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_BlurFilter_ps20___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &BlurFilter_ps20_combos_0);
}

//------------------------------------------------------------------------------
// Address: 0x1005ECE0
// Name: _dynamic_initializer_for__s_ConstructMe_BlurFilter_ps20b___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_BlurFilter_ps20b___0()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &BlurFilter_ps20b_combos_0);
}
