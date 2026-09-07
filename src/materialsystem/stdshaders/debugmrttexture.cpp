// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/debugmrttexture.cpp
// Functions: 13
// ============================================================

#include "materialsystem\stdshaders\debugmrttexture.h"

//------------------------------------------------------------------------------
// Address: 0x1000A4D0
// Name: public: virtual char const __near * DebugMRTTexture::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DebugMRTTexture::CShader::GetName(DebugMRTTexture::CShader *this)
{
  return s_Name_18;
}

//------------------------------------------------------------------------------
// Address: 0x1000A4E0
// Name: public: virtual int DebugMRTTexture::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugMRTTexture::CShader::GetFlags(DebugMRTTexture::CShader *this)
{
  return s_nFlags_7;
}

//------------------------------------------------------------------------------
// Address: 0x1000A4F0
// Name: public: virtual void DebugMRTTexture::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge DebugMRTTexture::CShader::OnDrawElements(
        DebugMRTTexture::CShader *this@<ecx>,
        int a2@<edi>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int v8; // eax
  int m_intVal; // edi

  if ( pShaderShadow != nullptr )
  {
    ((void (__thiscall *)(IShaderShadow *, _DWORD, int, int))pShaderShadow->EnableTexture)(
      a1: pShaderShadow,
      a2: 0,
      a3: 1,
      a4: a2);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "debugmrttexture_vs20", a3: 0);
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    m_intVal = params[MRTINDEX.m_Index]->m_intVal;
    if ( v8 < 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MRTINDEX", m_intVal, "params[MRTINDEX]->GetIntValue()");
      ((void (__thiscall *)(IShaderShadow *, const char *))pShaderShadow->SetPixelShader)(
        a1: pShaderShadow,
        a2: "debugmrttexture_ps20");
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MRTINDEX", m_intVal, "params[MRTINDEX]->GetIntValue()");
      ((void (__thiscall *)(IShaderShadow *, const char *))pShaderShadow->SetPixelShader)(
        a1: pShaderShadow,
        a2: "debugmrttexture_ps20b");
    }
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1u, a3: 2, a4: nullptr, a5: 0);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000A610
// Name: public: virtual int DebugMRTTexture::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall DebugMRTTexture::CShader::GetParamCount(DebugMRTTexture::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_18.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A620
// Name: public: virtual struct ShaderParamInfo_t const __near & DebugMRTTexture::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
DebugMRTTexture::CShaderParam *__thiscall DebugMRTTexture::CShader::GetParamInfo(
        DebugMRTTexture::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_18.m_Memory.m_pMemory[param - ParamCount];
  else
    return (DebugMRTTexture::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000A650
// Name: public: DebugMRTTexture::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DebugMRTTexture::CShaderParam *__thiscall DebugMRTTexture::CShaderParam::CShaderParam(
        DebugMRTTexture::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  DebugMRTTexture::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  DebugMRTTexture::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_18.m_Size + 13;
  m_Size = s_ShaderParams_18.m_Size;
  v8 = s_ShaderParams_18.m_Size;
  if ( s_ShaderParams_18.m_Size + 1 > s_ShaderParams_18.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_18,
      num: s_ShaderParams_18.m_Size - s_ShaderParams_18.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_18.m_Size;
  }
  m_pMemory = s_ShaderParams_18.m_Memory.m_pMemory;
  s_ShaderParams_18.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_18.m_pElements = s_ShaderParams_18.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_18.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_18.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_18.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005F770
// Name: DebugMRTTexture::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int DebugMRTTexture::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: DebugMRTTexture::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1005F780
// Name: DebugMRTTexture::_dynamic_initializer_for__MRTINDEX__
// Source: json
//------------------------------------------------------------------------------
DebugMRTTexture::CShaderParam *DebugMRTTexture::_dynamic_initializer_for__MRTINDEX__()
{
  return DebugMRTTexture::CShaderParam::CShaderParam(
           this: &MRTINDEX,
           pName: "$MRTINDEX",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005F7A0
// Name: DebugMRTTexture::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *DebugMRTTexture::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_18);
  s_ShaderInstance_18.__vftable = (DebugMRTTexture::CShader_vtbl *)&DebugMRTTexture::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AFA0
// Name: DebugMRTTexture::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugMRTTexture::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_18);
}

//------------------------------------------------------------------------------
// Address: 0x1005F7C0
// Name: _dynamic_initializer_for__s_ConstructMe_DebugTextureView_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_DebugTextureView_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &DebugTextureView_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F7E0
// Name: _dynamic_initializer_for__s_ConstructMe_DebugTextureView_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_DebugTextureView_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &DebugTextureView_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1005F800
// Name: _dynamic_initializer_for__s_ConstructMe_DebugTextureView_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_DebugTextureView_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &DebugTextureView_ps20b_combos);
}
