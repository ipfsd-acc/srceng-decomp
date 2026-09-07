// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/blurfiltery.cpp
// Functions: 19
// ============================================================

#include "materialsystem\stdshaders\blurfiltery.h"

//------------------------------------------------------------------------------
// Address: 0x100079C0
// Name: public: virtual void BlurFilterY::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlurFilterY::CShader::OnInitShaderParams(
        BlurFilterY::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[BLOOMAMOUNT.m_Index]->IsDefined(this: params[BLOOMAMOUNT.m_Index]) )
    ((void (__stdcall *)(int))params[BLOOMAMOUNT.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[KERNEL_0.m_Index]->IsDefined(this: params[KERNEL_0.m_Index]) )
    params[KERNEL_0.m_Index]->SetIntValue(this: params[KERNEL_0.m_Index], a2: 0);
  if ( !params[ENABLECLEARCOLOR.m_Index]->IsDefined(this: params[ENABLECLEARCOLOR.m_Index]) )
    params[ENABLECLEARCOLOR.m_Index]->SetIntValue(this: params[ENABLECLEARCOLOR.m_Index], a2: 0);
  if ( !params[CLEARCOLOR.m_Index]->IsDefined(this: params[CLEARCOLOR.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD))params[CLEARCOLOR.m_Index]->SetVecValue_2)(
      a1: params[CLEARCOLOR.m_Index],
      a2: 0,
      a3: 0,
      a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10007A90
// Name: public: virtual char const __near * BlurFilterY::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BlurFilterY::CShader::GetName(BlurFilterY::CShader *this)
{
  return s_Name_9;
}

//------------------------------------------------------------------------------
// Address: 0x10007AA0
// Name: public: virtual int BlurFilterY::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlurFilterY::CShader::GetFlags(BlurFilterY::CShader *this)
{
  return s_nFlags_3;
}

//------------------------------------------------------------------------------
// Address: 0x10007AB0
// Name: public: virtual void BlurFilterY::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge BlurFilterY::CShader::OnDrawElements(
        BlurFilterY::CShader *this@<ecx>,
        int a2@<ebx>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  BOOL v7; // ebx
  int v8; // eax
  int v9; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v11)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v12)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v14)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v15)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v16)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v17; // edi
  void (__thiscall *v18)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v[4]; // [esp+8h] [ebp-14h] BYREF
  CBaseShader *v20; // [esp+18h] [ebp-4h]
  float dY; // [esp+28h] [ebp+Ch]

  v20 = this;
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
    v7 = params[KERNEL_0.m_Index]->m_intVal != 0;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "KERNEL", v7, "params[ KERNEL ]->GetIntValue() ? 1 : 0");
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "blurfilter_vs20", a3: v7);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "KERNEL",
          params[KERNEL_0.m_Index]->m_intVal,
          "params[ KERNEL ]->GetIntValue()");
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "CLEAR_COLOR",
          params[ENABLECLEARCOLOR.m_Index]->m_intVal,
          "params[ ENABLECLEARCOLOR ]->GetIntValue()");
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "APPROX_SRGB_ADAPTER",
            0,
            "bForceSRGBReadAndWrite && ( params[ KERNEL ]->GetIntValue() != 0 ) && ( params[ ENABLECLEARCOLOR ]->GetIntValue() == 0 )");
      }
      ((void (__thiscall *)(IShaderShadow *, const char *))pShaderShadow->SetPixelShader)(
        a1: pShaderShadow,
        a2: "blurfilter_ps20b");
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "KERNEL",
          params[KERNEL_0.m_Index]->m_intVal,
          "params[ KERNEL ]->GetIntValue()");
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "CLEAR_COLOR",
          params[ENABLECLEARCOLOR.m_Index]->m_intVal,
          "params[ ENABLECLEARCOLOR ]->GetIntValue()");
      ((void (__thiscall *)(IShaderShadow *, const char *))pShaderShadow->SetPixelShader)(
        a1: pShaderShadow,
        a2: "blurfilter_ps20");
    }
    if ( ((*params)->m_intVal & 0x80) != 0 )
      CBaseShader::EnableAlphaBlending(this: v20, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v20,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    v8 = params[6]->GetTextureValue(this: params[6]);
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 16))(a1: v8);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    dY = 1.0 / (float)v9;
    v[0] = 0.0;
    v[1] = dY * 1.3365999;
    v[2] = 0.0;
    v[3] = 0.0;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: v, a4: 1, a5: false);
    v11 = pShaderAPI->SetVertexShaderConstant;
    v[0] = 0.0;
    v[1] = dY * 3.4295001;
    v11(this: pShaderAPI, a2: 49, a3: v, a4: 1, a5: false);
    v12 = pShaderAPI->SetVertexShaderConstant;
    v[0] = 0.0;
    v[1] = dY * 5.4264002;
    v12(this: pShaderAPI, a2: 50, a3: v, a4: 1, a5: false);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    v[0] = 0.0;
    v[1] = dY * 7.4359002;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: v, a4: 1, a5: false);
    v[0] = 0.0;
    v[1] = dY * 9.4435997;
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 1, a3: v, a4: 1, a5: false);
    v14 = pShaderAPI->SetPixelShaderConstant;
    v[0] = 0.0;
    v[1] = dY * 11.4401;
    v14(this: pShaderAPI, a2: 2, a3: v, a4: 1, a5: false);
    v15 = pShaderAPI->SetPixelShaderConstant;
    v[2] = params[BLOOMAMOUNT.m_Index]->m_VecVal.x;
    v[1] = v[2];
    v[0] = v[2];
    v15(this: pShaderAPI, a2: 3, a3: v, a4: 1, a5: false);
    v16 = pShaderAPI->SetPixelShaderConstant;
    v[3] = 0.0;
    v[2] = 0.0;
    v[0] = 0.0;
    v[1] = dY;
    v16(this: pShaderAPI, a2: 4, a3: v, a4: 1, a5: false);
    v17 = params[CLEARCOLOR.m_Index];
    v18 = pShaderAPI->SetPixelShaderConstant;
    v[0] = v17->m_VecVal.x;
    v[1] = v17->m_VecVal.y;
    v[2] = v17->m_VecVal.z;
    v[3] = 0.0;
    v18(this: pShaderAPI, a2: 5, a3: v, a4: 1, a5: false);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this: v20, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10007EC0
// Name: public: virtual int BlurFilterY::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BlurFilterY::CShader::GetParamCount(BlurFilterY::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_9.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10007ED0
// Name: public: virtual struct ShaderParamInfo_t const __near & BlurFilterY::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
BlurFilterY::CShaderParam *__thiscall BlurFilterY::CShader::GetParamInfo(BlurFilterY::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_9.m_Memory.m_pMemory[param - ParamCount];
  else
    return (BlurFilterY::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10007F00
// Name: public: BlurFilterY::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BlurFilterY::CShaderParam *__thiscall BlurFilterY::CShaderParam::CShaderParam(
        BlurFilterY::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  BlurFilterY::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  BlurFilterY::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_9.m_Size + 13;
  m_Size = s_ShaderParams_9.m_Size;
  v8 = s_ShaderParams_9.m_Size;
  if ( s_ShaderParams_9.m_Size + 1 > s_ShaderParams_9.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_9,
      num: s_ShaderParams_9.m_Size - s_ShaderParams_9.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_9.m_Size;
  }
  m_pMemory = s_ShaderParams_9.m_Memory.m_pMemory;
  s_ShaderParams_9.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_9.m_pElements = s_ShaderParams_9.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_9.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_9.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_9.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001F000
// Name: public: virtual void BlurFilterY::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlurFilterY::CShader::OnInitShaderInstance(
        BlurFilterX::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005ED00
// Name: BlurFilterY::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int BlurFilterY::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: BlurFilterY::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005ED10
// Name: BlurFilterY::_dynamic_initializer_for__BLOOMAMOUNT__
// Source: json
//------------------------------------------------------------------------------
BlurFilterY::CShaderParam *BlurFilterY::_dynamic_initializer_for__BLOOMAMOUNT__()
{
  return BlurFilterY::CShaderParam::CShaderParam(
           this: &BLOOMAMOUNT,
           pName: "$BLOOMAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005ED30
// Name: BlurFilterY::_dynamic_initializer_for__FRAMETEXTURE__
// Source: json
//------------------------------------------------------------------------------
BlurFilterY::CShaderParam *BlurFilterY::_dynamic_initializer_for__FRAMETEXTURE__()
{
  return BlurFilterY::CShaderParam::CShaderParam(
           this: &FRAMETEXTURE,
           pName: "$FRAMETEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_SmallHDR0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005ED50
// Name: BlurFilterY::_dynamic_initializer_for__KERNEL__
// Source: json
//------------------------------------------------------------------------------
BlurFilterY::CShaderParam *BlurFilterY::_dynamic_initializer_for__KERNEL__()
{
  return BlurFilterY::CShaderParam::CShaderParam(
           this: &KERNEL_0,
           pName: "$KERNEL",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Kernel type",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005ED70
// Name: BlurFilterY::_dynamic_initializer_for__ENABLECLEARCOLOR__
// Source: json
//------------------------------------------------------------------------------
BlurFilterY::CShaderParam *BlurFilterY::_dynamic_initializer_for__ENABLECLEARCOLOR__()
{
  return BlurFilterY::CShaderParam::CShaderParam(
           this: &ENABLECLEARCOLOR,
           pName: "$ENABLECLEARCOLOR",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "clear RGB channels to a solid color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005ED90
// Name: BlurFilterY::_dynamic_initializer_for__CLEARCOLOR__
// Source: json
//------------------------------------------------------------------------------
BlurFilterY::CShaderParam *BlurFilterY::_dynamic_initializer_for__CLEARCOLOR__()
{
  return BlurFilterY::CShaderParam::CShaderParam(
           this: &CLEARCOLOR,
           pName: "$CLEARCOLOR",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: "clear color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EDB0
// Name: BlurFilterY::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *BlurFilterY::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_9);
  s_ShaderInstance_9.__vftable = (BlurFilterY::CShader_vtbl *)&BlurFilterY::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AF00
// Name: BlurFilterY::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlurFilterY::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_9);
}

//------------------------------------------------------------------------------
// Address: 0x1005EDD0
// Name: _dynamic_initializer_for__s_ConstructMe_bufferclearobeystencil_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_bufferclearobeystencil_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &bufferclearobeystencil_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EDF0
// Name: _dynamic_initializer_for__s_ConstructMe_bufferclearobeystencil_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_bufferclearobeystencil_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &bufferclearobeystencil_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EE10
// Name: _dynamic_initializer_for__s_ConstructMe_bufferclearobeystencil_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_bufferclearobeystencil_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &bufferclearobeystencil_ps20b_combos);
}
