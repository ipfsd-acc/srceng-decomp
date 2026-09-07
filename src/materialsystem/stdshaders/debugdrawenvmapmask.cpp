// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/debugdrawenvmapmask.cpp
// Functions: 14
// ============================================================

#include "materialsystem\stdshaders\debugdrawenvmapmask.h"

//------------------------------------------------------------------------------
// Address: 0x10001330
// Name: public: virtual void CBaseShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseShader::OnInitShaderParams(
        CBaseShader *this,
        IMaterialVar **ppParams,
        IMaterialVar **pMaterialName)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001340
// Name: public: virtual char const __near * DebugDrawEnvmapMask::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugDrawEnvmapMask::CShader::GetName(DebugDrawEnvmapMask::CShader *this)
{
  return s_Name_0;
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: public: virtual int DebugDrawEnvmapMask::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugDrawEnvmapMask::CShader::GetFlags(DebugDrawEnvmapMask::CShader *this)
{
  return s_nFlags_0;
}

//------------------------------------------------------------------------------
// Address: 0x10001370
// Name: public: virtual void DebugDrawEnvmapMask::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge DebugDrawEnvmapMask::CShader::OnDrawElements(
        DebugDrawEnvmapMask::CShader *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v8; // eax
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int v10; // eax
  BOOL v11; // ebx
  bool v12; // bl
  int v13; // [esp+0h] [ebp-8h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1025u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "debugdrawenvmapmask_vs20", a3: 0);
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    SetPixelShader = pShaderShadow->SetPixelShader;
    v13 = 0;
    if ( v8 < 92 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "debugdrawenvmapmask_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "debugdrawenvmapmask_ps20b");
  }
  if ( pShaderAPI != nullptr )
  {
    v10 = ((int (__thiscall *)(IShaderDynamicAPI *, int, int))CBaseShader::s_pShaderAPI->GetCurrentNumBones)(
            a1: CBaseShader::s_pShaderAPI,
            a2: a3,
            a3: a2);
    v11 = v10 > 0;
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v10 > 0, "numBones > 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    ((void (__thiscall *)(IShaderDynamicAPI *, __int32, int))pShaderAPI->SetVertexShaderIndex)(
      a1: pShaderAPI,
      a2: vertexCompression + 2 * v11,
      a3: v13);
    v12 = params[SHOWALPHA.m_Index]->m_intVal != 0;
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "SHOWALPHA", v12, "bShowAlpha");
    }
    else if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   PS dyn  var %s = %d (%s)", "SHOWALPHA", v12, "bShowAlpha");
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v12);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    CBaseVSShader::SetVertexShaderTextureTransform(this, vertexReg: 48, transformVar: 8);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001520
// Name: public: virtual int DebugDrawEnvmapMask::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugDrawEnvmapMask::CShader::GetParamCount(DebugDrawEnvmapMask::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_0.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001530
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugDrawEnvmapMask::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugDrawEnvmapMask::CShaderParam *__thiscall DebugDrawEnvmapMask::CShader::GetParamInfo(
        DebugDrawEnvmapMask::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_0.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugDrawEnvmapMask::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100015D0
// Name: public: DebugDrawEnvmapMask::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DebugDrawEnvmapMask::CShaderParam *__thiscall DebugDrawEnvmapMask::CShaderParam::CShaderParam(
        DebugDrawEnvmapMask::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  DebugDrawEnvmapMask::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  DebugDrawEnvmapMask::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_0.m_Size + 13;
  m_Size = s_ShaderParams_0.m_Size;
  v8 = s_ShaderParams_0.m_Size;
  if ( s_ShaderParams_0.m_Size + 1 > s_ShaderParams_0.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<DebugDrawEnvmapMask::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_0,
      num: s_ShaderParams_0.m_Size - s_ShaderParams_0.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_0.m_Size;
  }
  m_pMemory = s_ShaderParams_0.m_Memory.m_pMemory;
  s_ShaderParams_0.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_0.m_pElements = s_ShaderParams_0.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_0.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_0.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_0.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016820
// Name: DebugDrawEnvmapMask::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugDrawEnvmapMask::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugDrawEnvmapMask::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10016830
// Name: DebugDrawEnvmapMask::_dynamic_initializer_for__SHOWALPHA__
// Source: json
//------------------------------------------------------------------------------
DebugDrawEnvmapMask::CShaderParam *DebugDrawEnvmapMask::_dynamic_initializer_for__SHOWALPHA__()
{
  return DebugDrawEnvmapMask::CShaderParam::CShaderParam(
           this: &SHOWALPHA,
           pName: "$SHOWALPHA",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: &pHelp,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016850
// Name: DebugDrawEnvmapMask::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugDrawEnvmapMask::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_0);
  s_ShaderInstance_0.__vftable = (DebugDrawEnvmapMask::CShader_vtbl *)&DebugDrawEnvmapMask::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016D40
// Name: DebugDrawEnvmapMask::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugDrawEnvmapMask::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>::~CUtlVector<Fillrate::CShaderParam *,CUtlMemory<Fillrate::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_0);
}

//------------------------------------------------------------------------------
// Address: 0x10016870
// Name: _dynamic_initializer_for__s_ConstructMe_debugluxel_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugluxel_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugluxel_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10016890
// Name: _dynamic_initializer_for__s_ConstructMe_debugluxel_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugluxel_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugluxel_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100168B0
// Name: _dynamic_initializer_for__s_ConstructMe_debugluxel_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_debugluxel_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &debugluxel_vs20_combos);
}
