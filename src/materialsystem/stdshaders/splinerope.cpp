// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/splinerope.cpp
// Functions: 19
// ============================================================

#include "materialsystem\stdshaders\splinerope.h"

//------------------------------------------------------------------------------
// Address: 0x100323B0
// Name: public: virtual void SplineRope::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SplineRope::CShader::OnInitShaderParams(
        SplineRope::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  int m_Index; // edi
  int v4; // edi

  if ( SHADERSRGBREAD360_0.m_Index != -1 )
  {
    m_Index = SHADERSRGBREAD360_0.m_Index;
    if ( !params[SHADERSRGBREAD360_0.m_Index]->IsDefined(this: params[SHADERSRGBREAD360_0.m_Index]) )
      params[m_Index]->SetIntValue(this: params[m_Index], a2: 0);
  }
  if ( SHADOWDEPTH.m_Index != -1 )
  {
    v4 = SHADOWDEPTH.m_Index;
    if ( !params[SHADOWDEPTH.m_Index]->IsDefined(this: params[SHADOWDEPTH.m_Index]) )
      params[v4]->SetIntValue(this: params[v4], a2: 0);
  }
  if ( !params[BUMPMAP_6.m_Index]->IsDefined(this: params[BUMPMAP_6.m_Index]) )
    params[BUMPMAP_6.m_Index]->SetStringValue(this: params[BUMPMAP_6.m_Index], a2: "cable/cablenormalmap");
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x10000);
}

//------------------------------------------------------------------------------
// Address: 0x10032450
// Name: public: virtual char const __near * SplineRope::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SplineRope::CShader::GetName(SplineRope::CShader *this)
{
  return s_Name_112;
}

//------------------------------------------------------------------------------
// Address: 0x10032460
// Name: public: virtual int SplineRope::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SplineRope::CShader::GetFlags(SplineRope::CShader *this)
{
  return s_nFlags_116;
}

//------------------------------------------------------------------------------
// Address: 0x10032470
// Name: public: virtual void SplineRope::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SplineRope::CShader::OnInitShaderInstance(
        SplineRope::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadBumpMap(this, nTextureVar: BUMPMAP_6.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100324B0
// Name: public: virtual void SplineRope::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SplineRope::CShader::OnDrawElements(
        SplineRope::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IShaderShadow *v6; // esi
  SplineRope::CShader *v7; // edi
  bool v8; // zf
  bool v9; // bl
  IShaderShadow_vtbl *v10; // eax
  IShaderDynamicAPI *v11; // esi
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v13; // cc
  MaterialFogMode_t (__thiscall *GetSceneFogMode)(IShaderDynamicAPI *); // edx
  BOOL v15; // ebx
  BOOL v16; // edi
  unsigned __int8 v17; // al
  BOOL v18; // ebx
  BOOL v19; // edi
  unsigned __int8 v20; // al
  const char *v21; // [esp-4h] [ebp-3Ch]
  const char *v22; // [esp-4h] [ebp-3Ch]
  float vEyePos[4]; // [esp+Ch] [ebp-2Ch] BYREF
  float c7[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  BOOL v25; // [esp+30h] [ebp-8h] BYREF
  SplineRope::CShader *v26; // [esp+34h] [ebp-4h]

  v6 = pShaderShadow;
  v7 = this;
  v8 = params[SHADOWDEPTH.m_Index]->m_intVal == 0;
  v26 = this;
  v9 = !v8;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
    v10 = v6->__vftable;
    if ( v9 )
    {
      v10->EnableColorWrites(this: v6, a2: false);
      v6->EnableAlphaWrites(this: v6, a2: false);
      v6->EnablePolyOffset(this: v6, a2: SHADER_POLYOFFSET_SHADOW_BIAS);
    }
    else
    {
      v10->EnableAlphaWrites(this: v6, a2: true);
      v6->EnableTexture(this: v6, a2: SHADER_SAMPLER0, a3: true);
      v6->EnableSRGBRead(this: v6, a2: SHADER_SAMPLER0, a3: true);
      v6->EnableTexture(this: v6, a2: SHADER_SAMPLER1, a3: true);
      v6->EnableSRGBWrite(this: v6, a2: true);
      CBaseShader::FogToFogColor(this: v7);
    }
    v6->VertexShaderVertexFormat(
      this: v6,
      a2: 5u,
      a3: 4,
      a4: `SplineRope::CShader::OnDrawElements'::`10'::s_TexCoordSize,
      a5: 0);
    v6->SetVertexShader(this: v6, a2: "splinerope_vs20", a3: 0);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
      v25 = v9;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHADOWDEPTH", v9, "bShadowDepth");
      v6->SetPixelShader(this: v6, a2: "splinerope_ps20", a3: 2 * v25);
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
      v25 = v9;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHADOWDEPTH", v9, "bShadowDepth");
      v6->SetPixelShader(this: v6, a2: "splinerope_ps20b", a3: 4 * v25);
    }
  }
  v11 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    CBaseVSShader::LoadModelViewMatrixIntoVertexShaderConstant(this: v7, vertexReg: 48);
    CBaseVSShader::LoadProjectionMatrixIntoVertexShaderConstant(this: v7, vertexReg: 51);
    v11->GetCurrentViewport(this: v11, a2: &v25, a3: (int *)&pShaderAPI, a4: (int *)&params, a5: (int *)&pShaderShadow);
    memset(c7, 0, sizeof(c7));
    if ( !g_pHardwareConfig->IsAAEnabled(this: g_pHardwareConfig) )
    {
      c7[3] = rope_min_pixel_diameter.m_pParent->m_Value.m_fValue / (float)(int)params;
      c7[2] = c7[3];
      c7[1] = c7[3];
      c7[0] = c7[3];
    }
    v11->SetVertexShaderConstant(this: v11, a2: 55, a3: c7, a4: 1, a5: false);
    CBaseShader::BindTexture(
      this: v7,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: 6,
      nFrameVar: 7);
    CBaseShader::BindTexture(
      this: v7,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BUMPMAP_6.m_Index,
      nFrameVar: -1);
    if ( !v9 )
    {
      v11->SetPixelShaderFogParams(this: v11, a2: 0);
      v11->GetWorldSpaceCameraPosition(this: v11, a2: vEyePos);
      SetPixelShaderConstant = v11->SetPixelShaderConstant;
      vEyePos[3] = 0.0;
      SetPixelShaderConstant(this: v11, a2: 1, a3: vEyePos, a4: 1, a5: false);
    }
    v11->SetVertexShaderIndex(this: v11, a2: 0);
    v13 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    GetSceneFogMode = v11->GetSceneFogMode;
    if ( v13 )
    {
      v18 = GetSceneFogMode(this: v11) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v19 = v11->ShouldWriteDepthToDestAlpha(this: v11);
      if ( g_shaderConfigDumpEnable )
      {
        v20 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))v11->ShouldWriteDepthToDestAlpha)(
                a1: v11,
                a2: "pShaderAPI->ShouldWriteDepthToDestAlpha()");
        printf(format: "\n   PS dyn  var %s = %d (%s)", "WRITE_DEPTH_TO_DESTALPHA", v20, v22);
      }
      v11->SetPixelShaderIndex(this: v11, a2: v19 + v18);
    }
    else
    {
      v15 = GetSceneFogMode(this: v11) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v16 = v11->ShouldWriteDepthToDestAlpha(this: v11);
      if ( g_shaderConfigDumpEnable )
      {
        v17 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))v11->ShouldWriteDepthToDestAlpha)(
                a1: v11,
                a2: "pShaderAPI->ShouldWriteDepthToDestAlpha()");
        printf(format: "\n   PS dyn  var %s = %d (%s)", "WRITE_DEPTH_TO_DESTALPHA", v17, v21);
      }
      v11->SetPixelShaderIndex(this: v11, a2: v16 + 2 * v15);
    }
    v7 = v26;
  }
  CBaseShader::Draw(this: v7, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10032840
// Name: public: virtual int SplineRope::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SplineRope::CShader::GetParamCount(SplineRope::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_112.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10032850
// Name: public: virtual struct ShaderParamInfo_t const __near & SplineRope::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
SplineRope::CShaderParam *__thiscall SplineRope::CShader::GetParamInfo(SplineRope::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_112.m_Memory.m_pMemory[param - ParamCount];
  else
    return (SplineRope::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10032880
// Name: public: SplineRope::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
SplineRope::CShaderParam *__thiscall SplineRope::CShaderParam::CShaderParam(
        SplineRope::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  SplineRope::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  SplineRope::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_112.m_Size + 13;
  m_Size = s_ShaderParams_112.m_Size;
  v8 = s_ShaderParams_112.m_Size;
  if ( s_ShaderParams_112.m_Size + 1 > s_ShaderParams_112.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_112,
      num: s_ShaderParams_112.m_Size - s_ShaderParams_112.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_112.m_Size;
  }
  m_pMemory = s_ShaderParams_112.m_Memory.m_pMemory;
  s_ShaderParams_112.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_112.m_pElements = s_ShaderParams_112.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_112.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_112.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_112.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066F30
// Name: _dynamic_initializer_for__rope_min_pixel_diameter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_min_pixel_diameter__()
{
  ConVar::ConVar(this: &rope_min_pixel_diameter, pName: "rope_min_pixel_diameter", pDefaultValue: "2.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__rope_min_pixel_diameter__);
}

//------------------------------------------------------------------------------
// Address: 0x10066F60
// Name: SplineRope::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int SplineRope::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: SplineRope::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10066F70
// Name: SplineRope::_dynamic_initializer_for__SHADERSRGBREAD360__
// Source: json
//------------------------------------------------------------------------------
SplineRope::CShaderParam *SplineRope::_dynamic_initializer_for__SHADERSRGBREAD360__()
{
  return SplineRope::CShaderParam::CShaderParam(
           this: &SHADERSRGBREAD360_0,
           pName: "$SHADERSRGBREAD360",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Simulate srgb read in shader code",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066F90
// Name: SplineRope::_dynamic_initializer_for__SHADOWDEPTH__
// Source: json
//------------------------------------------------------------------------------
SplineRope::CShaderParam *SplineRope::_dynamic_initializer_for__SHADOWDEPTH__()
{
  return SplineRope::CShaderParam::CShaderParam(
           this: &SHADOWDEPTH,
           pName: "$SHADOWDEPTH",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "writing to a shadow depth buffer",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066FB0
// Name: SplineRope::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
SplineRope::CShaderParam *SplineRope::_dynamic_initializer_for__BUMPMAP__()
{
  return SplineRope::CShaderParam::CShaderParam(
           this: &BUMPMAP_6,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "cable/cablenormalmap",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066FD0
// Name: SplineRope::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *SplineRope::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_112);
  s_ShaderInstance_112.__vftable = (SplineRope::CShader_vtbl *)&SplineRope::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B7A0
// Name: _dynamic_atexit_destructor_for__rope_min_pixel_diameter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_min_pixel_diameter__()
{
  ConVar::~ConVar(this: &rope_min_pixel_diameter);
}

//------------------------------------------------------------------------------
// Address: 0x1006B7B0
// Name: SplineRope::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplineRope::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_112);
}

//------------------------------------------------------------------------------
// Address: 0x10067000
// Name: _dynamic_initializer_for__s_ConstructMe_sprite_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sprite_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sprite_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067020
// Name: _dynamic_initializer_for__s_ConstructMe_sprite_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sprite_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sprite_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067040
// Name: _dynamic_initializer_for__s_ConstructMe_sprite_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_sprite_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &sprite_ps20b_combos);
}
