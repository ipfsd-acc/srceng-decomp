// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/treeleaf.cpp
// Functions: 13
// ============================================================

#include "materialsystem\stdshaders\treeleaf.h"

//------------------------------------------------------------------------------
// Address: 0x10007FE0
// Name: public: virtual char const __near * TreeLeaf::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall TreeLeaf::CShader::GetFallbackShader(accumbuff4sample::CShader *this, IMaterialVar **params)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10037270
// Name: public: virtual char const __near * TreeLeaf::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall TreeLeaf::CShader::GetName(TreeLeaf::CShader *this)
{
  return s_Name_118;
}

//------------------------------------------------------------------------------
// Address: 0x10037280
// Name: public: virtual int TreeLeaf::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall TreeLeaf::CShader::GetFlags(TreeLeaf::CShader *this)
{
  return s_nFlags_43;
}

//------------------------------------------------------------------------------
// Address: 0x10037290
// Name: public: virtual void TreeLeaf::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TreeLeaf::CShader::OnInitShaderInstance(
        TreeLeaf::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100372D0
// Name: public: virtual void TreeLeaf::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TreeLeaf::CShader::OnDrawElements(
        TreeLeaf::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  TreeLeaf::CShader *v6; // edi
  bool v7; // bl
  int v8; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  char v10; // bl
  BOOL v11; // eax
  BOOL m_bStaticLight; // edi
  BOOL v13; // ecx
  int v14; // ebx
  int v15; // [esp+10h] [ebp-18h]
  LightState_t lightState; // [esp+1Ch] [ebp-Ch] BYREF
  TreeLeaf::CShader *v17; // [esp+24h] [ebp-4h]
  int pShaderShadowa; // [esp+34h] [ebp+Ch]

  v6 = this;
  v17 = this;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: true);
    ((void (__thiscall *)(IShaderShadow *, int, int))pShaderShadow->AlphaFunc)(a1: pShaderShadow, a2: 4, a3: 1056964608);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 3u, a3: 1, a4: nullptr, a5: 0);
    v7 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", 1, "true");
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "FLATTEN_STATIC_CONTROL_FLOW", v7, "bFlattenStaticControlFlow");
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "treeleaf_vs20", a3: 24 * v7 + 12);
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v15 = 0;
    if ( v8 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "treeleaf_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "treeleaf_ps20b");
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: false);
    v6 = v17;
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v6,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    CBaseVSShader::LoadViewMatrixIntoVertexShaderConstant(this: v6, vertexReg: 17);
    pShaderAPI->SetVertexShaderConstant(
      this: pShaderAPI,
      a2: 48,
      a3: (const float *)&params[LEAFCENTER.m_Index]->m_VecVal,
      a4: 1,
      a5: false);
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: &lightState);
    v10 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->SupportsStaticControlFlow)(
            a1: g_pHardwareConfig,
            a2: v15);
    if ( lightState.m_bAmbientLight || (pShaderShadowa = 0, lightState.m_nNumLights > 0) )
      pShaderShadowa = 1;
    if ( g_shaderConfigDumpEnable )
    {
      v11 = lightState.m_bAmbientLight || lightState.m_nNumLights > 0;
      printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", v11, "lightState.HasDynamicLight()");
    }
    m_bStaticLight = lightState.m_bStaticLight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "STATIC_LIGHT",
        lightState.m_bStaticLight,
        "lightState.m_bStaticLight ? 1 : 0");
    v13 = v10 != 0;
    v14 = v13 ? 0 : lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        v13 ? 0 : lightState.m_nNumLights,
        "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: pShaderShadowa + 2 * (m_bStaticLight + 2 * v14));
    v6 = v17;
  }
  CBaseShader::Draw(this: v6, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10037510
// Name: public: virtual int TreeLeaf::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall TreeLeaf::CShader::GetParamCount(TreeLeaf::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_118.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037520
// Name: public: virtual struct ShaderParamInfo_t const __near & TreeLeaf::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
TreeLeaf::CShaderParam *__thiscall TreeLeaf::CShader::GetParamInfo(TreeLeaf::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_118.m_Memory.m_pMemory[param - ParamCount];
  else
    return (TreeLeaf::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10037550
// Name: public: TreeLeaf::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
TreeLeaf::CShaderParam *__thiscall TreeLeaf::CShaderParam::CShaderParam(
        TreeLeaf::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  TreeLeaf::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  TreeLeaf::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_118.m_Size + 13;
  m_Size = s_ShaderParams_118.m_Size;
  v8 = s_ShaderParams_118.m_Size;
  if ( s_ShaderParams_118.m_Size + 1 > s_ShaderParams_118.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_118,
      num: s_ShaderParams_118.m_Size - s_ShaderParams_118.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_118.m_Size;
  }
  m_pMemory = s_ShaderParams_118.m_Memory.m_pMemory;
  s_ShaderParams_118.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_118.m_pElements = s_ShaderParams_118.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_118.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_118.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_118.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10047080
// Name: public: virtual void TreeLeaf::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TreeLeaf::CShader::OnInitShaderParams(
        CBaseShader *this,
        IMaterialVar **ppParams,
        IMaterialVar **pMaterialName)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10067C20
// Name: TreeLeaf::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int TreeLeaf::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: TreeLeaf::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10067C30
// Name: TreeLeaf::_dynamic_initializer_for__LEAFCENTER__
// Source: json
//------------------------------------------------------------------------------
TreeLeaf::CShaderParam *TreeLeaf::_dynamic_initializer_for__LEAFCENTER__()
{
  return TreeLeaf::CShaderParam::CShaderParam(
           this: &LEAFCENTER,
           pName: "$LEAFCENTER",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: "Center of leaf cluster for lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067C50
// Name: TreeLeaf::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *TreeLeaf::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_118);
  s_ShaderInstance_118.__vftable = (TreeLeaf::CShader_vtbl *)&TreeLeaf::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B820
// Name: TreeLeaf::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl TreeLeaf::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_118);
}
