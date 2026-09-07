// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/bufferclearobeystencil_dx9.cpp
// Functions: 25
// ============================================================

#include "materialsystem\stdshaders\bufferclearobeystencil_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10007FA0
// Name: public: virtual char const __near * BufferClearObeyStencil::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BufferClearObeyStencil::CShader::GetFallbackShader(
        BufferClearObeyStencil::CShader *this,
        IMaterialVar **params)
{
  return "BufferClearObeyStencil_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10007FB0
// Name: public: virtual char const __near * BufferClearObeyStencil::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BufferClearObeyStencil::CShader::GetName(BufferClearObeyStencil::CShader *this)
{
  return s_Name_10;
}

//------------------------------------------------------------------------------
// Address: 0x10007FC0
// Name: public: virtual int BufferClearObeyStencil::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BufferClearObeyStencil::CShader::GetFlags(BufferClearObeyStencil::CShader *this)
{
  return s_nFlags_52;
}

//------------------------------------------------------------------------------
// Address: 0x10007FD0
// Name: public: virtual int BufferClearObeyStencil::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BufferClearObeyStencil::CShader::GetParamCount(BufferClearObeyStencil::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_10.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10007FF0
// Name: public: virtual char const __near * BufferClearObeyStencil_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BufferClearObeyStencil_DX9::CShader::GetName(BufferClearObeyStencil_DX9::CShader *this)
{
  return s_Name_11;
}

//------------------------------------------------------------------------------
// Address: 0x10008000
// Name: public: virtual int BufferClearObeyStencil_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BufferClearObeyStencil_DX9::CShader::GetFlags(BufferClearObeyStencil_DX9::CShader *this)
{
  return s_nFlags_4;
}

//------------------------------------------------------------------------------
// Address: 0x10008010
// Name: public: virtual void BufferClearObeyStencil_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BufferClearObeyStencil_DX9::CShader::OnInitShaderInstance(
        BufferClearObeyStencil_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( !params[CLEARALPHA.m_Index]->IsDefined(this: params[CLEARALPHA.m_Index]) )
    params[CLEARALPHA.m_Index]->SetIntValue(this: params[CLEARALPHA.m_Index], a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10008050
// Name: public: virtual void BufferClearObeyStencil_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BufferClearObeyStencil_DX9::CShader::OnDrawElements(
        BufferClearObeyStencil_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar **v6; // edi
  int m_intVal; // eax
  bool v8; // cl
  bool v9; // sf
  bool v10; // al
  bool v11; // bl
  bool bEnableColorWrites; // [esp+10h] [ebp-4h]

  v6 = params;
  m_intVal = params[CLEARALPHA.m_Index]->m_intVal;
  v8 = params[CLEARCOLOR_0.m_Index]->m_intVal != 0;
  v9 = m_intVal < 0;
  bEnableColorWrites = v8;
  v10 = m_intVal != 0;
  if ( v9 )
    v10 = params[CLEARCOLOR_0.m_Index]->m_intVal != 0;
  LOBYTE(params) = v10;
  v11 = v8 || v10;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->DepthFunc(this: pShaderShadow, a2: SHADER_DEPTHFUNC_ALWAYS);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: v6[CLEARDEPTH.m_Index]->m_intVal != 0);
    pShaderShadow->EnableColorWrites(this: pShaderShadow, a2: bEnableColorWrites);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: (bool)params);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 5u, a3: 1, a4: nullptr, a5: 0);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "USESCOLOR", v11, "bUsesColor");
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "bufferclearobeystencil_vs20", a3: v11);
    if ( v11 )
    {
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "RELOADZCULL", 0, "bReloadZcull");
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "bufferclearobeystencil_ps20", a3: 0);
      }
      else
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "RELOADZCULL", 0, "bReloadZcull");
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "bufferclearobeystencil_ps20b", a3: 0);
      }
    }
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    if ( v11 )
    {
      g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    }
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100081F0
// Name: public: virtual int BufferClearObeyStencil_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall BufferClearObeyStencil_DX9::CShader::GetParamCount(BufferClearObeyStencil_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_11.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008200
// Name: public: virtual struct ShaderParamInfo_t const __near & BufferClearObeyStencil::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
BufferClearObeyStencil::CShaderParam *__thiscall BufferClearObeyStencil::CShader::GetParamInfo(
        BufferClearObeyStencil::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_10.m_Memory.m_pMemory[param - ParamCount];
  else
    return (BufferClearObeyStencil::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10008230
// Name: public: virtual struct ShaderParamInfo_t const __near & BufferClearObeyStencil_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
BufferClearObeyStencil_DX9::CShaderParam *__thiscall BufferClearObeyStencil_DX9::CShader::GetParamInfo(
        BufferClearObeyStencil_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_11.m_Memory.m_pMemory[param - ParamCount];
  else
    return (BufferClearObeyStencil_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10008260
// Name: public: BufferClearObeyStencil_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BufferClearObeyStencil_DX9::CShaderParam *__thiscall BufferClearObeyStencil_DX9::CShaderParam::CShaderParam(
        BufferClearObeyStencil_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  BufferClearObeyStencil_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  BufferClearObeyStencil_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_11.m_Size + 13;
  m_Size = s_ShaderParams_11.m_Size;
  v8 = s_ShaderParams_11.m_Size;
  if ( s_ShaderParams_11.m_Size + 1 > s_ShaderParams_11.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_11,
      num: s_ShaderParams_11.m_Size - s_ShaderParams_11.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_11.m_Size;
  }
  m_pMemory = s_ShaderParams_11.m_Memory.m_pMemory;
  s_ShaderParams_11.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_11.m_pElements = s_ShaderParams_11.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_11.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_11.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_11.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005EE30
// Name: BufferClearObeyStencil::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int BufferClearObeyStencil::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: BufferClearObeyStencil::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005EE40
// Name: BufferClearObeyStencil::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *BufferClearObeyStencil::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_10);
  s_ShaderInstance_10.__vftable = (BufferClearObeyStencil::CShader_vtbl *)&BufferClearObeyStencil::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005EE60
// Name: BufferClearObeyStencil_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int BufferClearObeyStencil_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: BufferClearObeyStencil_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005EE70
// Name: BufferClearObeyStencil_DX9::_dynamic_initializer_for__CLEARCOLOR__
// Source: json
//------------------------------------------------------------------------------
BufferClearObeyStencil_DX9::CShaderParam *BufferClearObeyStencil_DX9::_dynamic_initializer_for__CLEARCOLOR__()
{
  return BufferClearObeyStencil_DX9::CShaderParam::CShaderParam(
           this: &CLEARCOLOR_0,
           pName: "$CLEARCOLOR",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "1",
           pHelp: "activates clearing of color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EE90
// Name: BufferClearObeyStencil_DX9::_dynamic_initializer_for__CLEARALPHA__
// Source: json
//------------------------------------------------------------------------------
BufferClearObeyStencil_DX9::CShaderParam *BufferClearObeyStencil_DX9::_dynamic_initializer_for__CLEARALPHA__()
{
  return BufferClearObeyStencil_DX9::CShaderParam::CShaderParam(
           this: &CLEARALPHA,
           pName: "$CLEARALPHA",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "-1",
           pHelp: "activates clearing of alpha. -1 == copy CLEARCOLOR setting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EEB0
// Name: BufferClearObeyStencil_DX9::_dynamic_initializer_for__CLEARDEPTH__
// Source: json
//------------------------------------------------------------------------------
BufferClearObeyStencil_DX9::CShaderParam *BufferClearObeyStencil_DX9::_dynamic_initializer_for__CLEARDEPTH__()
{
  return BufferClearObeyStencil_DX9::CShaderParam::CShaderParam(
           this: &CLEARDEPTH,
           pName: "$CLEARDEPTH",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "1",
           pHelp: "activates clearing of depth",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EED0
// Name: BufferClearObeyStencil_DX9::_dynamic_initializer_for__RELOADZCULL__
// Source: json
//------------------------------------------------------------------------------
BufferClearObeyStencil_DX9::CShaderParam *BufferClearObeyStencil_DX9::_dynamic_initializer_for__RELOADZCULL__()
{
  return BufferClearObeyStencil_DX9::CShaderParam::CShaderParam(
           this: &RELOADZCULL,
           pName: "$RELOADZCULL",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "special shader to reload Zcull memory on ps3",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005EEF0
// Name: BufferClearObeyStencil_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *BufferClearObeyStencil_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_11);
  s_ShaderInstance_11.__vftable = (BufferClearObeyStencil_DX9::CShader_vtbl *)&BufferClearObeyStencil_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AF10
// Name: BufferClearObeyStencil::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl BufferClearObeyStencil::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_10);
}

//------------------------------------------------------------------------------
// Address: 0x1006AF20
// Name: BufferClearObeyStencil_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl BufferClearObeyStencil_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_11);
}

//------------------------------------------------------------------------------
// Address: 0x1005EF10
// Name: _dynamic_initializer_for__s_ConstructMe_cable_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cable_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cable_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EF30
// Name: _dynamic_initializer_for__s_ConstructMe_cable_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cable_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cable_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005EF50
// Name: _dynamic_initializer_for__s_ConstructMe_cable_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_cable_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &cable_ps20b_combos);
}
