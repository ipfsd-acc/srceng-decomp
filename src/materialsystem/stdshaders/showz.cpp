// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/showz.cpp
// Functions: 20
// ============================================================

#include "materialsystem\stdshaders\showz.h"

//------------------------------------------------------------------------------
// Address: 0x1002F370
// Name: public: virtual void showz::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall showz::CShader::OnInitShaderParams(
        showz::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[ALPHADEPTH.m_Index]->IsDefined(this: params[ALPHADEPTH.m_Index]) )
    params[ALPHADEPTH.m_Index]->SetIntValue(this: params[ALPHADEPTH.m_Index], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002F3B0
// Name: public: virtual char const __near * showz::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall showz::CShader::GetName(showz::CShader *this)
{
  return s_Name_107;
}

//------------------------------------------------------------------------------
// Address: 0x1002F3C0
// Name: public: virtual int showz::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall showz::CShader::GetFlags(showz::CShader *this)
{
  return s_nFlags_41;
}

//------------------------------------------------------------------------------
// Address: 0x1002F3D0
// Name: public: virtual void showz::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge showz::CShader::OnDrawElements(
        showz::CShader *this@<ecx>,
        int a2@<edi>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  showz::CShader *v7; // ebx
  ShadowFilterMode_t v8; // edi
  int v9; // ebx
  int m_intVal; // edi
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  Vector4D C0; // [esp+8h] [ebp-14h] BYREF
  showz::CShader *v13; // [esp+18h] [ebp-4h]

  v7 = this;
  v13 = this;
  if ( pShaderShadow != nullptr )
  {
    ((void (__thiscall *)(IShaderShadow *, _DWORD, int, int))pShaderShadow->EnableTexture)(
      a1: pShaderShadow,
      a2: 0,
      a3: 1,
      a4: a2);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "showz_vs20", a3: 0);
    v8 = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: false);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      m_intVal = params[ALPHADEPTH.m_Index]->m_intVal;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTH_IN_ALPHA", m_intVal, "params[ALPHADEPTH]->GetIntValue()");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "showz_ps20", a3: m_intVal);
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHTDEPTHFILTERMODE", v8, "nShadowFilterMode");
      v9 = params[ALPHADEPTH.m_Index]->m_intVal;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DEPTH_IN_ALPHA", v9, "params[ALPHADEPTH]->GetIntValue()");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "showz_ps20b", a3: v8 + 4 * v9);
      v7 = v13;
    }
    ((void (__thiscall *)(IShaderShadow *, int, int, _DWORD))pShaderShadow->VertexShaderVertexFormat)(
      a1: pShaderShadow,
      a2: 1,
      a3: 1,
      a4: 0);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v7,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: 7);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    C0.x = r_showz_power.m_pParent->m_Value.m_fValue;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: &C0.x, a4: 1, a5: false);
  }
  CBaseShader::Draw(this: v7, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002F570
// Name: public: virtual int showz::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall showz::CShader::GetParamCount(showz::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_107.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002F580
// Name: public: virtual struct ShaderParamInfo_t const __near & showz::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
showz::CShaderParam *__thiscall showz::CShader::GetParamInfo(showz::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_107.m_Memory.m_pMemory[param - ParamCount];
  else
    return (showz::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002F5B0
// Name: public: showz::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
showz::CShaderParam *__thiscall showz::CShaderParam::CShaderParam(
        showz::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  showz::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  showz::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_107.m_Size + 13;
  m_Size = s_ShaderParams_107.m_Size;
  v8 = s_ShaderParams_107.m_Size;
  if ( s_ShaderParams_107.m_Size + 1 > s_ShaderParams_107.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_107,
      num: s_ShaderParams_107.m_Size - s_ShaderParams_107.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_107.m_Size;
  }
  m_pMemory = s_ShaderParams_107.m_Memory.m_pMemory;
  s_ShaderParams_107.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_107.m_pElements = s_ShaderParams_107.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_107.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_107.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_107.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066600
// Name: showz::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int showz::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: showz::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10066610
// Name: showz::_dynamic_initializer_for__ALPHADEPTH__
// Source: json
//------------------------------------------------------------------------------
showz::CShaderParam *showz::_dynamic_initializer_for__ALPHADEPTH__()
{
  return showz::CShaderParam::CShaderParam(
           this: &ALPHADEPTH,
           pName: "$ALPHADEPTH",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Depth is stored in alpha channel",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066630
// Name: showz::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *showz::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_107);
  s_ShaderInstance_107.__vftable = (showz::CShader_vtbl *)&showz::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B740
// Name: showz::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl showz::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_107);
}

//------------------------------------------------------------------------------
// Address: 0x10066650
// Name: _dynamic_initializer_for__s_ConstructMe_sky_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sky_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sky_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066670
// Name: _dynamic_initializer_for__s_ConstructMe_sky_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sky_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sky_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066690
// Name: _dynamic_initializer_for__s_ConstructMe_sky_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sky_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sky_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100666B0
// Name: _dynamic_initializer_for__s_ConstructMe_sky_hdr_compressed_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sky_hdr_compressed_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sky_hdr_compressed_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100666D0
// Name: _dynamic_initializer_for__s_ConstructMe_sky_hdr_compressed_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sky_hdr_compressed_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sky_hdr_compressed_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100666F0
// Name: _dynamic_initializer_for__s_ConstructMe_sky_hdr_compressed_rgbs_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sky_hdr_compressed_rgbs_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sky_hdr_compressed_rgbs_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066710
// Name: _dynamic_initializer_for__s_ConstructMe_sky_hdr_compressed_rgbs_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sky_hdr_compressed_rgbs_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sky_hdr_compressed_rgbs_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066730
// Name: _dynamic_initializer_for__mat_use_compressed_hdr_textures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_use_compressed_hdr_textures__()
{
  ConVar::ConVar(
    this: &mat_use_compressed_hdr_textures,
    pName: "mat_use_compressed_hdr_textures",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_use_compressed_hdr_textures__);
}

//------------------------------------------------------------------------------
// Address: 0x1006B750
// Name: _dynamic_atexit_destructor_for__mat_use_compressed_hdr_textures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_use_compressed_hdr_textures__()
{
  ConVar::~ConVar(this: &mat_use_compressed_hdr_textures);
}
