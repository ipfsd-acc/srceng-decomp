// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/downsample_nohdr.cpp
// Functions: 40
// ============================================================

#include "materialsystem\stdshaders\downsample_nohdr.h"

//------------------------------------------------------------------------------
// Address: 0x1000CA70
// Name: public: virtual void Downsample_nohdr::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Downsample_nohdr::CShader::OnInitShaderParams(
        Downsample_nohdr::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( BLOOMEXP.m_Index != -1 && !params[BLOOMEXP.m_Index]->IsDefined(this: params[BLOOMEXP.m_Index]) )
    ((void (__stdcall *)(int))params[BLOOMEXP.m_Index]->SetFloatValue)(a1: 1075838976);
  if ( BLOOMSATURATION.m_Index != -1
    && !params[BLOOMSATURATION.m_Index]->IsDefined(this: params[BLOOMSATURATION.m_Index]) )
  {
    ((void (__stdcall *)(int))params[BLOOMSATURATION.m_Index]->SetFloatValue)(a1: 1065353216);
  }
  if ( BLOOMTINTENABLE.m_Index != -1
    && !params[BLOOMTINTENABLE.m_Index]->IsDefined(this: params[BLOOMTINTENABLE.m_Index]) )
  {
    params[BLOOMTINTENABLE.m_Index]->SetIntValue(this: params[BLOOMTINTENABLE.m_Index], a2: 1);
  }
  if ( !params[BLOOMTYPE.m_Index]->IsDefined(this: params[BLOOMTYPE.m_Index]) )
    params[BLOOMTYPE.m_Index]->SetIntValue(this: params[BLOOMTYPE.m_Index], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000CB40
// Name: public: virtual char const __near * Downsample_nohdr::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Downsample_nohdr::CShader::GetName(Downsample_nohdr::CShader *this)
{
  return s_Name_27;
}

//------------------------------------------------------------------------------
// Address: 0x1000CB50
// Name: public: virtual int Downsample_nohdr::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Downsample_nohdr::CShader::GetFlags(Downsample_nohdr::CShader *this)
{
  return s_nFlags_11;
}

//------------------------------------------------------------------------------
// Address: 0x1000CB60
// Name: public: virtual int Downsample_nohdr::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Downsample_nohdr::CShader::GetParamCount(Downsample_nohdr::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_27.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000CB70
// Name: public: virtual void Downsample_nohdr::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge Downsample_nohdr::CShader::OnDrawElements(
        Downsample_nohdr::CShader *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar **v9; // ebx
  IShaderShadow *v10; // esi
  int v11; // eax
  int m_intVal; // edi
  IShaderDynamicAPI *v13; // esi
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v15; // xmm0_4
  float v16; // xmm1_4
  IMaterialVar *v17; // edx
  IMaterialVar *v18; // ecx
  IMaterialVar *v19; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  HDRType_t v21; // eax
  int v22; // [esp-Ch] [ebp-74h]
  int v23; // [esp-8h] [ebp-70h]
  float v[4][4]; // [esp+0h] [ebp-68h] BYREF
  float vPsConst1[4]; // [esp+40h] [ebp-28h] BYREF
  float m_fValue; // [esp+50h] [ebp-18h] BYREF
  downsample_nohdr_ps20b_Static_Index _pshIndex; // [esp+54h] [ebp-14h]
  CBaseShader *v29; // [esp+60h] [ebp-8h]
  BOOL bForceSRGBReadAndWrite; // [esp+64h] [ebp-4h]

  v29 = this;
  LOBYTE(bForceSRGBReadAndWrite) = r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0;
  v9 = params;
  v23 = a4;
  v10 = pShaderShadow;
  v22 = a3;
  if ( pShaderShadow != nullptr )
  {
    ((void (__thiscall *)(IShaderShadow *, _DWORD, int, int))pShaderShadow->EnableDepthWrites)(
      a1: pShaderShadow,
      a2: 0,
      a3,
      a4: v23);
    v10->EnableAlphaWrites(this: v10, a2: true);
    v10->EnableTexture(this: v10, a2: SHADER_SAMPLER0, a3: true);
    v10->EnableSRGBRead(this: v10, a2: SHADER_SAMPLER0, a3: bForceSRGBReadAndWrite);
    v10->EnableSRGBWrite(this: v10, a2: bForceSRGBReadAndWrite);
    v10->VertexShaderVertexFormat(this: v10, a2: 1u, a3: 1, a4: nullptr, a5: 0);
    v10->SetVertexShader(this: v10, a2: "Downsample_vs20", a3: 0);
    v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    m_intVal = v9[BLOOMTYPE.m_Index]->m_intVal;
    if ( v11 < 92 )
    {
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "BLOOMTYPE", m_intVal, "params[BLOOMTYPE]->GetIntValue()");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "PS3REGCOUNT48", 0, "0");
      }
      v10->SetPixelShader(this: v10, a2: "downsample_nohdr_ps20", a3: m_intVal);
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BLOOMTYPE", m_intVal, "params[BLOOMTYPE]->GetIntValue()");
      _pshIndex.m_nSRGB_INPUT_ADAPTER = bForceSRGBReadAndWrite;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "SRGB_INPUT_ADAPTER",
          bForceSRGBReadAndWrite,
          "bForceSRGBReadAndWrite");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "PS3REGCOUNT48", 0, "0");
      }
      v10->SetPixelShader(
        this: v10,
        a2: "downsample_nohdr_ps20b",
        a3: 2 * (m_intVal + 2 * _pshIndex.m_nSRGB_INPUT_ADAPTER));
    }
  }
  v13 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v29,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: bForceSRGBReadAndWrite ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
      nTextureVar: 6,
      nFrameVar: -1);
    ((void (__thiscall *)(IShaderDynamicAPI *, IShaderShadow **, IMaterialVar ***, int, int, int))v13->GetBackBufferDimensions)(
      a1: v13,
      a2: &pShaderShadow,
      a3: &params,
      a4: v22,
      a5: v23,
      a6: a2);
    SetVertexShaderConstant = v13->SetVertexShaderConstant;
    v15 = 1.0 / (float)(int)pShaderShadow;
    v16 = 1.0 / (float)(int)params;
    v[0][0] = v15 * 0.5;
    v[0][1] = v16 * 0.5;
    v[1][0] = v15 * 2.5;
    v[1][1] = v16 * 0.5;
    v[2][0] = v15 * 0.5;
    v[2][1] = v16 * 2.5;
    v[3][0] = v15 * 2.5;
    v[3][1] = v16 * 2.5;
    SetVertexShaderConstant(this: v13, a2: 48, a3: v[0], a4: 4, a5: false);
    v13->SetVertexShaderIndex(this: v13, a2: 0);
    m_fValue = r_bloomtintr.m_pParent->m_Value.m_fValue;
    _pshIndex.m_nBLOOMTYPE = LODWORD(r_bloomtintg.m_pParent->m_Value.m_fValue);
    v17 = v9[BLOOMTINTENABLE.m_Index];
    _pshIndex.m_nPS3REGCOUNT48 = LODWORD(r_bloomtintb.m_pParent->m_Value.m_fValue);
    _pshIndex.m_nSRGB_INPUT_ADAPTER = LODWORD(r_bloomtintexponent.m_pParent->m_Value.m_fValue);
    if ( v17->m_intVal == 0 )
    {
      m_fValue = 1.0;
      _pshIndex.m_nBLOOMTYPE = 1065353216;
      _pshIndex.m_nPS3REGCOUNT48 = 1065353216;
      _pshIndex.m_nSRGB_INPUT_ADAPTER = 1065353216;
    }
    ((void (__thiscall *)(IShaderDynamicAPI *, _DWORD, float *))v13->SetPixelShaderConstant)(
      a1: v13,
      a2: 0,
      a3: &m_fValue);
    v18 = v9[BLOOMEXP.m_Index];
    v19 = v9[BLOOMSATURATION.m_Index];
    SetPixelShaderConstant = v13->SetPixelShaderConstant;
    memset(vPsConst1, 0, sizeof(vPsConst1));
    vPsConst1[0] = v18->m_VecVal.x;
    vPsConst1[1] = v19->m_VecVal.x;
    SetPixelShaderConstant(this: v13, a2: 1, a3: vPsConst1, a4: 1, a5: false);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      v21 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "FLOAT_BACK_BUFFER", v21 == HDR_TYPE_FLOAT, "floatBackBuffer");
    }
    ((void (__thiscall *)(IShaderDynamicAPI *))v13->SetPixelShaderIndex)(a1: v13);
  }
  CBaseShader::Draw(this: v29, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000CF10
// Name: public: virtual struct ShaderParamInfo_t const __near & Downsample_nohdr::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Downsample_nohdr::CShaderParam *__thiscall Downsample_nohdr::CShader::GetParamInfo(
        Downsample_nohdr::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_27.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Downsample_nohdr::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1000CF40
// Name: public: Downsample_nohdr::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Downsample_nohdr::CShaderParam *__thiscall Downsample_nohdr::CShaderParam::CShaderParam(
        Downsample_nohdr::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Downsample_nohdr::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Downsample_nohdr::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_27.m_Size + 13;
  m_Size = s_ShaderParams_27.m_Size;
  v8 = s_ShaderParams_27.m_Size;
  if ( s_ShaderParams_27.m_Size + 1 > s_ShaderParams_27.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_27,
      num: s_ShaderParams_27.m_Size - s_ShaderParams_27.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_27.m_Size;
  }
  m_pMemory = s_ShaderParams_27.m_Memory.m_pMemory;
  s_ShaderParams_27.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_27.m_pElements = s_ShaderParams_27.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_27.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_27.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_27.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10060110
// Name: Downsample_nohdr::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Downsample_nohdr::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Downsample_nohdr::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10060120
// Name: Downsample_nohdr::_dynamic_initializer_for__BLOOMTYPE__
// Source: json
//------------------------------------------------------------------------------
Downsample_nohdr::CShaderParam *Downsample_nohdr::_dynamic_initializer_for__BLOOMTYPE__()
{
  return Downsample_nohdr::CShaderParam::CShaderParam(
           this: &BLOOMTYPE,
           pName: "$BLOOMTYPE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060140
// Name: Downsample_nohdr::_dynamic_initializer_for__BLOOMEXP__
// Source: json
//------------------------------------------------------------------------------
Downsample_nohdr::CShaderParam *Downsample_nohdr::_dynamic_initializer_for__BLOOMEXP__()
{
  return Downsample_nohdr::CShaderParam::CShaderParam(
           this: &BLOOMEXP,
           pName: "$BLOOMEXP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2.5",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060160
// Name: Downsample_nohdr::_dynamic_initializer_for__BLOOMSATURATION__
// Source: json
//------------------------------------------------------------------------------
Downsample_nohdr::CShaderParam *Downsample_nohdr::_dynamic_initializer_for__BLOOMSATURATION__()
{
  return Downsample_nohdr::CShaderParam::CShaderParam(
           this: &BLOOMSATURATION,
           pName: "$BLOOMSATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060180
// Name: Downsample_nohdr::_dynamic_initializer_for__BLOOMTINTENABLE__
// Source: json
//------------------------------------------------------------------------------
Downsample_nohdr::CShaderParam *Downsample_nohdr::_dynamic_initializer_for__BLOOMTINTENABLE__()
{
  return Downsample_nohdr::CShaderParam::CShaderParam(
           this: &BLOOMTINTENABLE,
           pName: "$BLOOMTINTENABLE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "1",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100601A0
// Name: Downsample_nohdr::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Downsample_nohdr::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_27);
  s_ShaderInstance_27.__vftable = (Downsample_nohdr::CShader_vtbl *)&Downsample_nohdr::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B0A0
// Name: Downsample_nohdr::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Downsample_nohdr::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_27);
}

//------------------------------------------------------------------------------
// Address: 0x100601C0
// Name: _dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &emissive_scroll_blended_pass_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100601E0
// Name: _dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &emissive_scroll_blended_pass_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060200
// Name: _dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &emissive_scroll_blended_pass_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060220
// Name: _dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &emissive_scroll_blended_pass_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060240
// Name: _dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_emissive_scroll_blended_pass_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &emissive_scroll_blended_pass_ps30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060260
// Name: _dynamic_initializer_for__s_ConstructMe_Engine_Post_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Engine_Post_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Engine_Post_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10060280
// Name: _dynamic_initializer_for__s_ConstructMe_Engine_Post_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Engine_Post_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Engine_Post_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100602A0
// Name: _dynamic_initializer_for__s_ConstructMe_Engine_Post_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Engine_Post_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Engine_Post_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100602C0
// Name: _dynamic_initializer_for__mat_screen_blur_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_screen_blur_override__()
{
  ConVar::ConVar(this: &mat_screen_blur_override, pName: "mat_screen_blur_override", pDefaultValue: "-1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_screen_blur_override__);
}

//------------------------------------------------------------------------------
// Address: 0x100602F0
// Name: _dynamic_initializer_for__mat_depth_blur_focal_distance_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_depth_blur_focal_distance_override__()
{
  ConVar::ConVar(
    this: &mat_depth_blur_focal_distance_override,
    pName: "mat_depth_blur_focal_distance_override",
    pDefaultValue: "-1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_depth_blur_focal_distance_override__);
}

//------------------------------------------------------------------------------
// Address: 0x10060320
// Name: _dynamic_initializer_for__mat_depth_blur_strength_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_depth_blur_strength_override__()
{
  ConVar::ConVar(
    this: &mat_depth_blur_strength_override,
    pName: "mat_depth_blur_strength_override",
    pDefaultValue: "-1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_depth_blur_strength_override__);
}

//------------------------------------------------------------------------------
// Address: 0x10060350
// Name: _dynamic_initializer_for__mat_grain_scale_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_grain_scale_override__()
{
  ConVar::ConVar(this: &mat_grain_scale_override, pName: "mat_grain_scale_override", pDefaultValue: "-1.0", flags: 16);
  return atexit(func: dynamic_atexit_destructor_for__mat_grain_scale_override__);
}

//------------------------------------------------------------------------------
// Address: 0x10060380
// Name: _dynamic_initializer_for__mat_local_contrast_scale_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_local_contrast_scale_override__()
{
  ConVar::ConVar(
    this: &mat_local_contrast_scale_override,
    pName: "mat_local_contrast_scale_override",
    pDefaultValue: "0.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_local_contrast_scale_override__);
}

//------------------------------------------------------------------------------
// Address: 0x100603B0
// Name: _dynamic_initializer_for__mat_local_contrast_midtone_mask_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_local_contrast_midtone_mask_override__()
{
  ConVar::ConVar(
    this: &mat_local_contrast_midtone_mask_override,
    pName: "mat_local_contrast_midtone_mask_override",
    pDefaultValue: "-1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_local_contrast_midtone_mask_override__);
}

//------------------------------------------------------------------------------
// Address: 0x100603E0
// Name: _dynamic_initializer_for__mat_local_contrast_vignette_start_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_local_contrast_vignette_start_override__()
{
  ConVar::ConVar(
    this: &mat_local_contrast_vignette_start_override,
    pName: "mat_local_contrast_vignette_start_override",
    pDefaultValue: "-1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_local_contrast_vignette_start_override__);
}

//------------------------------------------------------------------------------
// Address: 0x10060410
// Name: _dynamic_initializer_for__mat_local_contrast_vignette_end_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_local_contrast_vignette_end_override__()
{
  ConVar::ConVar(
    this: &mat_local_contrast_vignette_end_override,
    pName: "mat_local_contrast_vignette_end_override",
    pDefaultValue: "-1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_local_contrast_vignette_end_override__);
}

//------------------------------------------------------------------------------
// Address: 0x10060440
// Name: _dynamic_initializer_for__mat_local_contrast_edge_scale_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_local_contrast_edge_scale_override__()
{
  ConVar::ConVar(
    this: &mat_local_contrast_edge_scale_override,
    pName: "mat_local_contrast_edge_scale_override",
    pDefaultValue: "-1000.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_local_contrast_edge_scale_override__);
}

//------------------------------------------------------------------------------
// Address: 0x1006B0B0
// Name: _dynamic_atexit_destructor_for__mat_screen_blur_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_screen_blur_override__()
{
  ConVar::~ConVar(this: &mat_screen_blur_override);
}

//------------------------------------------------------------------------------
// Address: 0x1006B0C0
// Name: _dynamic_atexit_destructor_for__mat_depth_blur_focal_distance_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_depth_blur_focal_distance_override__()
{
  ConVar::~ConVar(this: &mat_depth_blur_focal_distance_override);
}

//------------------------------------------------------------------------------
// Address: 0x1006B0D0
// Name: _dynamic_atexit_destructor_for__mat_depth_blur_strength_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_depth_blur_strength_override__()
{
  ConVar::~ConVar(this: &mat_depth_blur_strength_override);
}

//------------------------------------------------------------------------------
// Address: 0x1006B0E0
// Name: _dynamic_atexit_destructor_for__mat_grain_scale_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_grain_scale_override__()
{
  ConVar::~ConVar(this: &mat_grain_scale_override);
}

//------------------------------------------------------------------------------
// Address: 0x1006B0F0
// Name: _dynamic_atexit_destructor_for__mat_local_contrast_scale_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_local_contrast_scale_override__()
{
  ConVar::~ConVar(this: &mat_local_contrast_scale_override);
}

//------------------------------------------------------------------------------
// Address: 0x1006B100
// Name: _dynamic_atexit_destructor_for__mat_local_contrast_midtone_mask_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_local_contrast_midtone_mask_override__()
{
  ConVar::~ConVar(this: &mat_local_contrast_midtone_mask_override);
}

//------------------------------------------------------------------------------
// Address: 0x1006B110
// Name: _dynamic_atexit_destructor_for__mat_local_contrast_vignette_start_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_local_contrast_vignette_start_override__()
{
  ConVar::~ConVar(this: &mat_local_contrast_vignette_start_override);
}

//------------------------------------------------------------------------------
// Address: 0x1006B120
// Name: _dynamic_atexit_destructor_for__mat_local_contrast_vignette_end_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_local_contrast_vignette_end_override__()
{
  ConVar::~ConVar(this: &mat_local_contrast_vignette_end_override);
}

//------------------------------------------------------------------------------
// Address: 0x1006B130
// Name: _dynamic_atexit_destructor_for__mat_local_contrast_edge_scale_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_local_contrast_edge_scale_override__()
{
  ConVar::~ConVar(this: &mat_local_contrast_edge_scale_override);
}
