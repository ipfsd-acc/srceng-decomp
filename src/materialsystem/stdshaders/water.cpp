// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/water.cpp
// Functions: 76
// ============================================================

#include "materialsystem\stdshaders\water.h"

//------------------------------------------------------------------------------
// Address: 0x10041EB0
// Name: public: virtual char const __near * Water::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Water::CShader::GetFallbackShader(Water::CShader *this, IMaterialVar **params)
{
  return "Water_DX9_HDR";
}

//------------------------------------------------------------------------------
// Address: 0x10041EC0
// Name: public: virtual char const __near * Water::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Water::CShader::GetName(Water::CShader *this)
{
  return s_Name_127;
}

//------------------------------------------------------------------------------
// Address: 0x10041ED0
// Name: public: virtual int Water::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Water::CShader::GetFlags(Water::CShader *this)
{
  return s_nFlags_129;
}

//------------------------------------------------------------------------------
// Address: 0x10041EE0
// Name: public: virtual int Water::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Water::CShader::GetParamCount(Water::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_127.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10041EF0
// Name: public: virtual void Water_DX90::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Water_DX90::CShader::OnInitShaderParams(
        Water_DX90::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  int m_Index; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi

  if ( !params[ABOVEWATER.m_Index]->IsDefined(this: params[ABOVEWATER.m_Index]) )
  {
    _Warning(a1: "***need to set $abovewater for material %s\n", pMaterialName);
    params[ABOVEWATER.m_Index]->SetIntValue(this: params[ABOVEWATER.m_Index], a2: 1);
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  if ( !params[CHEAPWATERSTARTDISTANCE.m_Index]->IsDefined(this: params[CHEAPWATERSTARTDISTANCE.m_Index]) )
    ((void (__stdcall *)(int))params[CHEAPWATERSTARTDISTANCE.m_Index]->SetFloatValue)(a1: 1140457472);
  if ( !params[CHEAPWATERENDDISTANCE.m_Index]->IsDefined(this: params[CHEAPWATERENDDISTANCE.m_Index]) )
    ((void (__stdcall *)(int))params[CHEAPWATERENDDISTANCE.m_Index]->SetFloatValue)(a1: 1148846080);
  if ( !params[SCROLL1.m_Index]->IsDefined(this: params[SCROLL1.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD))params[SCROLL1.m_Index]->SetVecValue_2)(
      a1: params[SCROLL1.m_Index],
      a2: 0,
      a3: 0,
      a4: 0);
  if ( !params[SCROLL2.m_Index]->IsDefined(this: params[SCROLL2.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD))params[SCROLL2.m_Index]->SetVecValue_2)(
      a1: params[SCROLL2.m_Index],
      a2: 0,
      a3: 0,
      a4: 0);
  if ( !params[FOGCOLOR.m_Index]->IsDefined(this: params[FOGCOLOR.m_Index]) )
  {
    ((void (__thiscall *)(IMaterialVar *, int, _DWORD, _DWORD))params[FOGCOLOR.m_Index]->SetVecValue_2)(
      a1: params[FOGCOLOR.m_Index],
      a2: 1065353216,
      a3: 0,
      a4: 0);
    _Warning(a1: "material %s needs to have a $fogcolor.\n", pMaterialName);
  }
  if ( !params[REFLECTENTITIES.m_Index]->IsDefined(this: params[REFLECTENTITIES.m_Index]) )
    params[REFLECTENTITIES.m_Index]->SetIntValue(this: params[REFLECTENTITIES.m_Index], a2: 0);
  if ( !params[WATERBLENDFACTOR.m_Index]->IsDefined(this: params[WATERBLENDFACTOR.m_Index]) )
    ((void (__stdcall *)(int))params[WATERBLENDFACTOR.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[ENVMAP_8.m_Index]->IsDefined(this: params[ENVMAP_8.m_Index])
    && !params[REFLECTTEXTURE_0.m_Index]->IsDefined(this: params[REFLECTTEXTURE_0.m_Index]) )
  {
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD, _DWORD))params[REFLECTTINT_0.m_Index]->SetVecValue)(
      a1: params[REFLECTTINT_0.m_Index],
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0);
  }
  if ( FLOW_WORLDUVSCALE_0.m_Index != -1 )
  {
    m_Index = FLOW_WORLDUVSCALE_0.m_Index;
    if ( !params[FLOW_WORLDUVSCALE_0.m_Index]->IsDefined(this: params[FLOW_WORLDUVSCALE_0.m_Index]) )
      ((void (__stdcall *)(int))params[m_Index]->SetFloatValue)(a1: 1065353216);
  }
  if ( FLOW_NORMALUVSCALE_0.m_Index != -1 )
  {
    v4 = FLOW_NORMALUVSCALE_0.m_Index;
    if ( !params[FLOW_NORMALUVSCALE_0.m_Index]->IsDefined(this: params[FLOW_NORMALUVSCALE_0.m_Index]) )
      ((void (__stdcall *)(int))params[v4]->SetFloatValue)(a1: 1065353216);
  }
  if ( FLOW_TIMEINTERVALINSECONDS_0.m_Index != -1 )
  {
    v5 = FLOW_TIMEINTERVALINSECONDS_0.m_Index;
    if ( !params[FLOW_TIMEINTERVALINSECONDS_0.m_Index]->IsDefined(this: params[FLOW_TIMEINTERVALINSECONDS_0.m_Index]) )
      ((void (__stdcall *)(int))params[v5]->SetFloatValue)(a1: 1053609165);
  }
  if ( FLOW_UVSCROLLDISTANCE_0.m_Index != -1 )
  {
    v6 = FLOW_UVSCROLLDISTANCE_0.m_Index;
    if ( !params[FLOW_UVSCROLLDISTANCE_0.m_Index]->IsDefined(this: params[FLOW_UVSCROLLDISTANCE_0.m_Index]) )
      ((void (__stdcall *)(int))params[v6]->SetFloatValue)(a1: 1045220557);
  }
  if ( FLOW_BUMPSTRENGTH.m_Index != -1 )
  {
    v7 = FLOW_BUMPSTRENGTH.m_Index;
    if ( !params[FLOW_BUMPSTRENGTH.m_Index]->IsDefined(this: params[FLOW_BUMPSTRENGTH.m_Index]) )
      ((void (__stdcall *)(int))params[v7]->SetFloatValue)(a1: 1065353216);
  }
  if ( FLOW_NOISE_SCALE_0.m_Index != -1 )
  {
    v8 = FLOW_NOISE_SCALE_0.m_Index;
    if ( !params[FLOW_NOISE_SCALE_0.m_Index]->IsDefined(this: params[FLOW_NOISE_SCALE_0.m_Index]) )
      ((void (__stdcall *)(int))params[v8]->SetFloatValue)(a1: 961656599);
  }
  if ( COLOR_FLOW_UVSCALE.m_Index != -1 )
  {
    v9 = COLOR_FLOW_UVSCALE.m_Index;
    if ( !params[COLOR_FLOW_UVSCALE.m_Index]->IsDefined(this: params[COLOR_FLOW_UVSCALE.m_Index]) )
      ((void (__stdcall *)(int))params[v9]->SetFloatValue)(a1: 1065353216);
  }
  if ( COLOR_FLOW_TIMEINTERVALINSECONDS.m_Index != -1 )
  {
    v10 = COLOR_FLOW_TIMEINTERVALINSECONDS.m_Index;
    if ( !params[COLOR_FLOW_TIMEINTERVALINSECONDS.m_Index]->IsDefined(this: params[COLOR_FLOW_TIMEINTERVALINSECONDS.m_Index]) )
      ((void (__stdcall *)(int))params[v10]->SetFloatValue)(a1: 1053609165);
  }
  if ( COLOR_FLOW_UVSCROLLDISTANCE.m_Index != -1 )
  {
    v11 = COLOR_FLOW_UVSCROLLDISTANCE.m_Index;
    if ( !params[COLOR_FLOW_UVSCROLLDISTANCE.m_Index]->IsDefined(this: params[COLOR_FLOW_UVSCROLLDISTANCE.m_Index]) )
      ((void (__stdcall *)(int))params[v11]->SetFloatValue)(a1: 1045220557);
  }
  if ( COLOR_FLOW_LERPEXP.m_Index != -1 )
  {
    v12 = COLOR_FLOW_LERPEXP.m_Index;
    if ( !params[COLOR_FLOW_LERPEXP.m_Index]->IsDefined(this: params[COLOR_FLOW_LERPEXP.m_Index]) )
      ((void (__stdcall *)(int))params[v12]->SetFloatValue)(a1: 1065353216);
  }
  if ( COLOR_FLOW_DISPLACEBYNORMALSTRENGTH.m_Index != -1 )
  {
    v13 = COLOR_FLOW_DISPLACEBYNORMALSTRENGTH.m_Index;
    if ( !params[COLOR_FLOW_DISPLACEBYNORMALSTRENGTH.m_Index]->IsDefined(this: params[COLOR_FLOW_DISPLACEBYNORMALSTRENGTH.m_Index]) )
      ((void (__stdcall *)(int))params[v13]->SetFloatValue)(a1: 992204554);
  }
  if ( FORCEENVMAP.m_Index != -1 )
  {
    v14 = FORCEENVMAP.m_Index;
    if ( !params[FORCEENVMAP.m_Index]->IsDefined(this: params[FORCEENVMAP.m_Index]) )
      params[v14]->SetIntValue(this: params[v14], a2: 0);
  }
  if ( FORCECHEAP.m_Index != -1 )
  {
    v15 = FORCECHEAP.m_Index;
    if ( !params[FORCECHEAP.m_Index]->IsDefined(this: params[FORCECHEAP.m_Index]) )
      params[v15]->SetIntValue(this: params[v15], a2: 0);
  }
  if ( FLASHLIGHTTINT.m_Index != -1 )
  {
    v16 = FLASHLIGHTTINT.m_Index;
    if ( !params[FLASHLIGHTTINT.m_Index]->IsDefined(this: params[FLASHLIGHTTINT.m_Index]) )
      ((void (__stdcall *)(int))params[v16]->SetFloatValue)(a1: 1065353216);
  }
  if ( LIGHTMAPWATERFOG.m_Index != -1 )
  {
    v17 = LIGHTMAPWATERFOG.m_Index;
    if ( !params[LIGHTMAPWATERFOG.m_Index]->IsDefined(this: params[LIGHTMAPWATERFOG.m_Index]) )
      params[v17]->SetIntValue(this: params[v17], a2: 0);
  }
  if ( FORCEFRESNEL.m_Index != -1 )
  {
    v18 = FORCEFRESNEL.m_Index;
    if ( !params[FORCEFRESNEL.m_Index]->IsDefined(this: params[FORCEFRESNEL.m_Index]) )
      ((void (__stdcall *)(int))params[v18]->SetFloatValue)(a1: -1082130432);
  }
  if ( params[6]->IsDefined(this: params[6]) || params[LIGHTMAPWATERFOG.m_Index]->m_intVal != 0 )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 4);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 4);
  if ( params[6]->IsDefined(this: params[6])
    && (g_pConfig->m_Flags & 0x100) == 0
    && params[NORMALMAP_6.m_Index]->IsDefined(this: params[NORMALMAP_6.m_Index]) )
  {
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 8);
  }
  if ( !params[DEPTH_FEATHER.m_Index]->IsDefined(this: params[DEPTH_FEATHER.m_Index]) )
    params[DEPTH_FEATHER.m_Index]->SetIntValue(this: params[DEPTH_FEATHER.m_Index], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10042520
// Name: public: virtual char const __near * Water_DX90::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Water_DX90::CShader::GetName(Water_DX90::CShader *this)
{
  return s_Name_128;
}

//------------------------------------------------------------------------------
// Address: 0x10042530
// Name: public: virtual int Water_DX90::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Water_DX90::CShader::GetFlags(Water_DX90::CShader *this)
{
  return s_nFlags_130;
}

//------------------------------------------------------------------------------
// Address: 0x10042540
// Name: public: virtual void Water_DX90::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Water_DX90::CShader::OnInitShaderInstance(
        Water_DX90::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[REFRACTTEXTURE_0.m_Index]->IsDefined(this: params[REFRACTTEXTURE_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: REFRACTTEXTURE_0.m_Index, nAdditionalCreationFlags: 0x80000);
  if ( params[SCENEDEPTH_1.m_Index]->IsDefined(this: params[SCENEDEPTH_1.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: SCENEDEPTH_1.m_Index, nAdditionalCreationFlags: 0);
  if ( params[REFLECTTEXTURE_0.m_Index]->IsDefined(this: params[REFLECTTEXTURE_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: REFLECTTEXTURE_0.m_Index, nAdditionalCreationFlags: 0x80000);
  if ( params[ENVMAP_8.m_Index]->IsDefined(this: params[ENVMAP_8.m_Index]) )
    CBaseShader::LoadCubeMap(this, nTextureVar: ENVMAP_8.m_Index, nAdditionalCreationFlags: 0x80000);
  if ( params[NORMALMAP_6.m_Index]->IsDefined(this: params[NORMALMAP_6.m_Index]) )
    CBaseShader::LoadBumpMap(this, nTextureVar: NORMALMAP_6.m_Index, nAdditionalCreationFlags: 0);
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
  if ( params[FLOWMAP_1.m_Index]->IsDefined(this: params[FLOWMAP_1.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: FLOWMAP_1.m_Index, nAdditionalCreationFlags: 0);
  if ( params[FLOW_NOISE_TEXTURE_0.m_Index]->IsDefined(this: params[FLOW_NOISE_TEXTURE_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: FLOW_NOISE_TEXTURE_0.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10042670
// Name: public: virtual int Water_DX90::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Water_DX90::CShader::GetParamCount(Water_DX90::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_128.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10042680
// Name: public: void Water_DX90::CShader::DrawCheapWater(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Water_DX90::CShader::DrawCheapWater(
        Water_DX90::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        bool bBlend,
        bool bRefraction)
{
  Water_DX90::CShader *v8; // ebx
  bool v9; // al
  BOOL v10; // ebx
  BOOL v11; // eax
  int v12; // eax
  IMaterialVar *v13; // ecx
  int v14; // eax
  float v15; // xmm0_4
  IMaterialVar *v16; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  float v20; // xmm0_4
  IMaterialVar *v21; // ecx
  int m_intVal; // eax
  int v23; // ebx
  IMaterialVar *v24; // edx
  IMaterialVar *v25; // ecx
  float v26; // xmm1_4
  IMaterialVar *v27; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v29; // ecx
  IMaterialVar *v30; // eax
  IMaterialVar *v31; // edx
  float x; // xmm0_4
  IShaderDynamicAPI_vtbl *v33; // eax
  float v34; // xmm0_4
  void (__thiscall *v35)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  long double (__thiscall *CurrentTime)(IShaderDynamicAPI *); // edx
  float v37; // xmm0_4
  void (__thiscall *v38)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v39; // ecx
  void (__thiscall *v40)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v41)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v42; // eax
  float v43; // xmm0_4
  float y; // xmm1_4
  IMaterialVar *v45; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v47; // xmm1_4
  BOOL v48; // edi
  BOOL IsHDREnabled; // ebx
  bool v50; // al
  const char *v51; // [esp-4h] [ebp-70h]
  const char *v52; // [esp-4h] [ebp-70h]
  float vEyePos_SpecExponent[4]; // [esp+Ch] [ebp-60h] BYREF
  HDRType_t v54; // [esp+1Ch] [ebp-50h]
  BOOL v55; // [esp+20h] [ebp-4Ch]
  int v56; // [esp+24h] [ebp-48h]
  float cheapWaterParams[4]; // [esp+28h] [ebp-44h] BYREF
  float vc0[4]; // [esp+38h] [ebp-34h] BYREF
  float vFlowConst2[4]; // [esp+48h] [ebp-24h] BYREF
  float vFlowConst1[4]; // [esp+58h] [ebp-14h] BYREF
  CBaseShader *v61; // [esp+68h] [ebp-4h]
  bool bHasFlowmap_3; // [esp+77h] [ebp+Bh]
  BOOL pShaderShadowa; // [esp+78h] [ebp+Ch]
  BOOL pShaderShadowb; // [esp+78h] [ebp+Ch]
  float curtime; // [esp+80h] [ebp+14h]

  v8 = this;
  bHasFlowmap_3 = (*((_BYTE *)params[FLOWMAP_1.m_Index] + 28) & 0xF) == 3;
  v61 = this;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this);
    if ( CBaseShader::UsingEditor(this: v8, params) )
      CBaseShader::s_pShaderShadow->EnableCulling(this: CBaseShader::s_pShaderShadow, a2: false);
    if ( bBlend )
      CBaseShader::EnableAlphaBlending(this: v8, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    if ( bRefraction && bBlend )
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    if ( bHasFlowmap_3 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    }
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 51u, a3: 1, a4: nullptr, a5: 0);
    v9 = bBlend && bRefraction;
    v10 = v9;
    if ( g_shaderConfigDumpEnable )
    {
      v11 = bBlend && bRefraction;
      printf(format: "\n   VS stat var %s = %d (%s)", "BLEND", v11, "bBlend && bRefraction");
    }
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "watercheap_vs20", a3: v10);
    v12 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v13 = params[NOFRESNEL.m_Index];
    if ( v12 < 92 )
    {
      pShaderShadowb = v13->m_intVal == 0;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FRESNEL",
          v13->m_intVal == 0,
          "params[NOFRESNEL]->GetIntValue() == 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BLEND", bBlend, "bBlend");
      LODWORD(vEyePos_SpecExponent[3]) = bRefraction;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFRACTALPHA", bRefraction, "bRefraction");
      v54 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      if ( g_shaderConfigDumpEnable )
      {
        v19 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
                a1: g_pHardwareConfig,
                a2: "g_pHardwareConfig->GetHDRType()");
        printf(format: "\n   PS stat var %s = %d (%s)", "HDRTYPE", v19, v52);
      }
      LODWORD(v20) = LODWORD(params[SCROLL1.m_Index]->m_VecVal.x) & _mask__AbsFloat_;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MULTITEXTURE", (double)(int)v20 > 0.0, "fabs(Scroll1.x) > 0.0");
      v55 = bHasFlowmap_3;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLOWMAP", bHasFlowmap_3, "bHasFlowmap");
      v21 = params[FLOW_DEBUG.m_Index];
      m_intVal = v21->m_intVal;
      if ( m_intVal >= 0 )
      {
        v23 = 2;
        if ( m_intVal <= 2 )
          v23 = v21->m_intVal;
      }
      else
      {
        v23 = 0;
      }
      if ( g_shaderConfigDumpEnable )
      {
        if ( m_intVal >= 0 )
        {
          if ( m_intVal > 2 )
            m_intVal = 2;
        }
        else
        {
          m_intVal = 0;
        }
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FLOW_DEBUG",
          m_intVal,
          "clamp( params[ FLOW_DEBUG ]->GetIntValue(), 0, 2 )");
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "watercheap_ps20",
        a3: 4
      * ((v20 > 0.0)
       + 2
       * (pShaderShadowb
        + 2 * (bBlend + 2 * (LODWORD(vEyePos_SpecExponent[3]) + 2 * (v55 + 2 * v23 + v54 + 2 * (v55 + 2 * v23)))))));
    }
    else
    {
      pShaderShadowa = v13->m_intVal == 0;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FRESNEL",
          v13->m_intVal == 0,
          "params[NOFRESNEL]->GetIntValue() == 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BLEND", bBlend, "bBlend");
      LODWORD(vEyePos_SpecExponent[3]) = bRefraction;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFRACTALPHA", bRefraction, "bRefraction");
      v54 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      if ( g_shaderConfigDumpEnable )
      {
        v14 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
                a1: g_pHardwareConfig,
                a2: "g_pHardwareConfig->GetHDRType()");
        printf(format: "\n   PS stat var %s = %d (%s)", "HDRTYPE", v14, v51);
      }
      LODWORD(v15) = LODWORD(params[SCROLL1.m_Index]->m_VecVal.x) & _mask__AbsFloat_;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MULTITEXTURE", (double)(int)v15 > 0.0, "fabs(Scroll1.x) > 0.0");
      v55 = bHasFlowmap_3;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLOWMAP", bHasFlowmap_3, "bHasFlowmap");
      v16 = params[FLOW_DEBUG.m_Index];
      v17 = v16->m_intVal;
      if ( v17 >= 0 )
      {
        v18 = 2;
        if ( v17 <= 2 )
          v18 = v16->m_intVal;
      }
      else
      {
        v18 = 0;
      }
      if ( g_shaderConfigDumpEnable )
      {
        if ( v17 >= 0 )
        {
          if ( v17 > 2 )
            v17 = 2;
        }
        else
        {
          v17 = 0;
        }
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FLOW_DEBUG",
          v17,
          "clamp( params[ FLOW_DEBUG ]->GetIntValue(), 0, 2 )");
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "watercheap_ps20b",
        a3: 4
      * ((v15 > 0.0)
       + 2
       * (pShaderShadowa
        + 2 * (bBlend + 2 * (LODWORD(vEyePos_SpecExponent[3]) + 2 * (v55 + 2 * v18 + v54 + 2 * (v55 + 2 * v18)))))));
    }
    if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) != HDR_TYPE_NONE )
      pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    CBaseShader::FogToFogColor(this: v61);
    v8 = (Water_DX90::CShader *)v61;
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetDefaultState(this: pShaderAPI);
    CBaseShader::BindTexture(
      this: v8,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: ENVMAP_8.m_Index,
      nFrameVar: ENVMAPFRAME_5.m_Index);
    CBaseShader::BindTexture(
      this: v8,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: NORMALMAP_6.m_Index,
      nFrameVar: BUMPFRAME_13.m_Index);
    if ( bRefraction && bBlend )
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER2,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: REFRACTTEXTURE_0.m_Index,
        nFrameVar: -1);
    if ( bHasFlowmap_3 )
    {
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER3,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: FLOWMAP_1.m_Index,
        nFrameVar: -1);
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER4,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: FLOW_NOISE_TEXTURE_0.m_Index,
        nFrameVar: -1);
      v24 = params[FLOW_WORLDUVSCALE_0.m_Index];
      v25 = params[FLOW_NORMALUVSCALE_0.m_Index];
      memset(vFlowConst1, 0, sizeof(vFlowConst1));
      v26 = 1.0 / v24->m_VecVal.x;
      v27 = params[FLOW_BUMPSTRENGTH.m_Index];
      SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
      vFlowConst1[0] = v26;
      vFlowConst1[1] = 1.0 / v25->m_VecVal.x;
      vFlowConst1[2] = v27->m_VecVal.x;
      SetPixelShaderConstant(this: pShaderAPI, a2: 13, a3: vFlowConst1, a4: 1, a5: false);
      v29 = params[FLOW_TIMEINTERVALINSECONDS_0.m_Index];
      v30 = params[FLOW_UVSCROLLDISTANCE_0.m_Index];
      memset(vFlowConst2, 0, sizeof(vFlowConst2));
      v31 = params[FLOW_NOISE_SCALE_0.m_Index];
      vFlowConst2[0] = v29->m_VecVal.x;
      x = v30->m_VecVal.x;
      v33 = pShaderAPI->__vftable;
      vFlowConst2[1] = x;
      v34 = v31->m_VecVal.x;
      v35 = v33->SetPixelShaderConstant;
      vFlowConst2[2] = v34;
      v35(this: pShaderAPI, a2: 14, a3: vFlowConst2, a4: 1, a5: false);
      CurrentTime = pShaderAPI->CurrentTime;
      memset(&vc0[1], 0, 12);
      vc0[0] = CurrentTime(this: pShaderAPI);
      pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 10, a3: vc0, a4: 1, a5: false);
    }
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER6,
      a3: TEXTURE_BINDFLAGS_NONE,
      a4: TEXTURE_NORMALIZATION_CUBEMAP_SIGNED);
    CBaseVSShader::SetPixelShaderConstant(this: v8, pixelReg: 0, constantVar: FOGCOLOR.m_Index);
    v37 = params[CHEAPWATERSTARTDISTANCE.m_Index]->m_VecVal.x;
    v38 = pShaderAPI->SetPixelShaderConstant;
    cheapWaterParams[1] = params[CHEAPWATERENDDISTANCE.m_Index]->m_VecVal.x;
    cheapWaterParams[0] = v37;
    cheapWaterParams[2] = 1.0 / (float)(cheapWaterParams[1] - v37);
    cheapWaterParams[3] = v37 / (float)(cheapWaterParams[1] - v37);
    v38(this: pShaderAPI, a2: 1, a3: cheapWaterParams, a4: 1, a5: false);
    if ( g_pConfig->bShowSpecular )
    {
      CBaseVSShader::SetPixelShaderConstant(
        this: v8,
        pixelReg: 2,
        constantVar: REFLECTTINT_0.m_Index,
        constantVar2: WATERBLENDFACTOR.m_Index);
    }
    else
    {
      v39 = params[WATERBLENDFACTOR.m_Index];
      v40 = pShaderAPI->SetPixelShaderConstant;
      memset(vc0, 0, 12);
      vc0[3] = v39->m_VecVal.x;
      v40(this: pShaderAPI, a2: 2, a3: vc0, a4: 1, a5: false);
    }
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: &vEyePos_SpecExponent[3]);
    v41 = pShaderAPI->SetPixelShaderConstant;
    v56 = 0;
    v41(this: pShaderAPI, a2: 11, a3: &vEyePos_SpecExponent[3], a4: 1, a5: false);
    if ( params[SCROLL1.m_Index]->IsDefined(this: params[SCROLL1.m_Index]) )
    {
      curtime = pShaderAPI->CurrentTime(this: pShaderAPI);
      v42 = params[SCROLL1.m_Index];
      v43 = v42->m_VecVal.x;
      y = v42->m_VecVal.y;
      v45 = params[SCROLL2.m_Index];
      vc0[0] = v43 * curtime;
      vc0[1] = y * curtime;
      SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
      v47 = v45->m_VecVal.y * curtime;
      vc0[2] = v45->m_VecVal.x * curtime;
      vc0[3] = v47;
      SetVertexShaderConstant(this: pShaderAPI, a2: 51, a3: vc0, a4: 1, a5: false);
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v48 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    IsHDREnabled = CBaseShader::IsHDREnabled(this: v61);
    if ( g_shaderConfigDumpEnable )
    {
      v50 = CBaseShader::IsHDREnabled(this: v61);
      printf(format: "\n   PS dyn  var %s = %d (%s)", "HDRENABLED", v50, "IsHDREnabled()");
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: IsHDREnabled + 2 * v48);
    v8 = (Water_DX90::CShader *)v61;
  }
  CBaseShader::Draw(this: v8, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10042FA0
// Name: public: virtual char const __near * Water_DX90::Water_DX9_HDR::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Water_DX90::Water_DX9_HDR::CShader::GetName(Water_DX90::Water_DX9_HDR::CShader *this)
{
  return s_Name_129;
}

//------------------------------------------------------------------------------
// Address: 0x10042FB0
// Name: public: virtual int Water_DX90::Water_DX9_HDR::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Water_DX90::Water_DX9_HDR::CShader::GetFlags(Water_DX90::Water_DX9_HDR::CShader *this)
{
  return s_nFlags_131;
}

//------------------------------------------------------------------------------
// Address: 0x10042FC0
// Name: public: virtual char const __near * Water_DX90::Water_DX9_HDR::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall Water_DX90::Water_DX9_HDR::CShader::GetFallbackShader(
        Water_DX90::Water_DX9_HDR::CShader *this,
        IMaterialVar **params)
{
  return g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_NONE ? "WATER_DX90" : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10042FE0
// Name: public: virtual struct ShaderParamInfo_t const __near & Water::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Water::CShaderParam *__thiscall Water::CShader::GetParamInfo(Water::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_127.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Water::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10043010
// Name: public: virtual struct ShaderParamInfo_t const __near & Water_DX90::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *__thiscall Water_DX90::CShader::GetParamInfo(Water_DX90::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_128.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Water_DX90::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10043040
// Name: public: Water_DX90::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *__thiscall Water_DX90::CShaderParam::CShaderParam(
        Water_DX90::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Water_DX90::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Water_DX90::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_128.m_Size + 13;
  m_Size = s_ShaderParams_128.m_Size;
  v8 = s_ShaderParams_128.m_Size;
  if ( s_ShaderParams_128.m_Size + 1 > s_ShaderParams_128.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_128,
      num: s_ShaderParams_128.m_Size - s_ShaderParams_128.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_128.m_Size;
  }
  m_pMemory = s_ShaderParams_128.m_Memory.m_pMemory;
  s_ShaderParams_128.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_128.m_pElements = s_ShaderParams_128.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_128.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_128.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_128.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100430E0
// Name: public: void Water_DX90::CShader::DrawReflectionRefraction(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Water_DX90::CShader::DrawReflectionRefraction(
        Water_DX90::CShader *this,
        IMaterialVar **params,
        int pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        float bReflection,
        bool bRefraction)
{
  float x; // xmm0_4
  Water_DX90::CShader *v8; // ebx
  char v9; // al
  bool v10; // al
  float v11; // xmm0_4
  bool v12; // cl
  IShaderShadow *v13; // esi
  int v14; // eax
  int v15; // eax
  float v16; // ecx
  int v17; // eax
  int v18; // eax
  int m_intVal; // eax
  int v20; // eax
  IShaderDynamicAPI *v21; // esi
  IMaterialVar *v22; // ecx
  IMaterialVar *v23; // eax
  IMaterialVar *v24; // edx
  IMaterialVar *v25; // ecx
  float v26; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v28; // ecx
  IMaterialVar *v29; // eax
  IMaterialVar *v30; // edx
  float v31; // xmm0_4
  IShaderDynamicAPI_vtbl *v32; // eax
  float v33; // xmm0_4
  void (__thiscall *v34)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // eax
  IMaterialVar *v37; // edx
  IMaterialVar *v38; // ecx
  float v39; // xmm0_4
  void (__thiscall *v40)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  long double (__thiscall *CurrentTime)(IShaderDynamicAPI *); // edx
  const VMatrix *v42; // eax
  void (__thiscall *v43)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v44; // eax
  float v45; // xmm0_4
  double v46; // st7
  IMaterialVar *v47; // eax
  void (__thiscall *v48)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v49; // eax
  float v50; // xmm0_4
  float y; // xmm1_4
  IMaterialVar *v52; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v54; // xmm1_4
  void (__thiscall *v55)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v56)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v57)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v58; // eax
  void (__thiscall *v59)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v60; // xmm0_4
  IMaterialVar *v61; // eax
  IMaterialVar *v62; // eax
  IMaterialVar *v63; // eax
  IMaterialVar *v64; // edx
  void (__thiscall *v65)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v66; // eax
  float v67; // xmm1_4
  float v68; // xmm2_4
  __m128i v69; // xmm0
  int v70; // eax
  BOOL v71; // edi
  int m_nValue; // eax
  void (__thiscall *ExecuteCommandBuffer)(IShaderDynamicAPI *, unsigned __int8 *); // edx
  int gamma; // [esp+17Ch] [ebp-580h]
  VMatrix result; // [esp+18Ch] [ebp-570h] BYREF
  CCommandBufferBuilder<CFixedCommandStorageBuffer<1000> > DynamicCmdsOut; // [esp+1CCh] [ebp-530h] BYREF
  VMatrix v77; // [esp+5B8h] [ebp-144h] BYREF
  Vector4D vCameraForward; // [esp+5F8h] [ebp-104h] BYREF
  float c0[4]; // [esp+608h] [ebp-F4h] BYREF
  float vc0[4]; // [esp+618h] [ebp-E4h] BYREF
  float c5[4]; // [esp+628h] [ebp-D4h] BYREF
  float vEyePos_SpecExponent[4]; // [esp+638h] [ebp-C4h] BYREF
  float c3[4]; // [esp+648h] [ebp-B4h] BYREF
  float c2[4]; // [esp+658h] [ebp-A4h] BYREF
  float c7[4]; // [esp+668h] [ebp-94h] BYREF
  float vTimeConst[4]; // [esp+678h] [ebp-84h] BYREF
  Vector4D vCameraRight; // [esp+688h] [ebp-74h] BYREF
  float vColorFlowConst1[4]; // [esp+698h] [ebp-64h] BYREF
  float fogColorConstant[4]; // [esp+6A8h] [ebp-54h] BYREF
  int v90; // [esp+6B8h] [ebp-44h]
  int nRtWidth; // [esp+6BCh] [ebp-40h] BYREF
  float gammaReflectTint[3]; // [esp+6C0h] [ebp-3Ch] BYREF
  float z; // [esp+6CCh] [ebp-30h]
  float linearReflectTint[4]; // [esp+6D0h] [ebp-2Ch] BYREF
  int nViewportHeight; // [esp+6E0h] [ebp-1Ch] BYREF
  int nViewportWidth; // [esp+6E4h] [ebp-18h] BYREF
  int nRtHeight; // [esp+6E8h] [ebp-14h] BYREF
  int nViewportX; // [esp+6ECh] [ebp-10h] BYREF
  int nViewportY; // [esp+6F0h] [ebp-Ch] BYREF
  bool bLightmapWaterFog; // [esp+6F6h] [ebp-6h]
  bool bUsingLightmap; // [esp+6F7h] [ebp-5h]
  bool hasFlashlight; // [esp+6F8h] [ebp-4h]
  bool bHasMultiTexture; // [esp+6F9h] [ebp-3h]
  bool bForceFresnel; // [esp+6FAh] [ebp-2h]
  bool bHasFlowmap; // [esp+6FBh] [ebp-1h]
  bool bHasBaseTexture_3; // [esp+707h] [ebp+Bh]

  x = params[SCROLL1.m_Index]->m_VecVal.x;
  v8 = this;
  v9 = *((_BYTE *)params[FLOWMAP_1.m_Index] + 28) & 0xF;
  nViewportWidth = (int)this;
  vEyePos_SpecExponent[0] = x;
  bHasFlowmap = v9 == 3;
  v10 = CBaseShader::UsingFlashlight(this, params);
  bHasBaseTexture_3 = (*((_BYTE *)params[6] + 28) & 0xF) == 3;
  hasFlashlight = v10;
  bHasMultiTexture = COERCE_FLOAT(LODWORD(x) & _mask__AbsFloat_) > 0.0;
  v11 = params[FORCEFRESNEL.m_Index]->m_VecVal.x;
  v12 = params[LIGHTMAPWATERFOG.m_Index]->m_intVal != 0;
  bLightmapWaterFog = v12;
  bForceFresnel = v11 != -1.0;
  if ( bHasFlowmap )
    bHasMultiTexture = false;
  bUsingLightmap = v12 || LOBYTE(bReflection) != 0 && bHasBaseTexture_3;
  v13 = (IShaderShadow *)pShaderShadow;
  if ( pShaderShadow != 0 )
  {
    CBaseShader::SetInitialShadowState(this: v8);
    if ( bRefraction )
    {
      v13->EnableTexture(this: v13, a2: SHADER_SAMPLER0, a3: true);
      v13->EnableSRGBRead(this: v13, a2: SHADER_SAMPLER0, a3: true);
    }
    v13->EnableTexture(this: v13, a2: SHADER_SAMPLER1, a3: true);
    ((void (__stdcall *)(int, bool))v13->EnableSRGBRead)(a1: 1, a2: LOBYTE(bReflection) != 0);
    if ( bHasBaseTexture_3 )
    {
      v13->EnableTexture(this: v13, a2: SHADER_SAMPLER10, a3: true);
      v13->EnableSRGBRead(this: v13, a2: SHADER_SAMPLER10, a3: true);
    }
    v13->EnableTexture(this: v13, a2: SHADER_SAMPLER2, a3: true);
    if ( bUsingLightmap )
    {
      v13->EnableTexture(this: v13, a2: SHADER_SAMPLER3, a3: true);
      v13->EnableSRGBRead(this: v13, a2: SHADER_SAMPLER3, a3: false);
    }
    if ( bHasFlowmap )
    {
      v13->EnableTexture(this: v13, a2: SHADER_SAMPLER4, a3: true);
      v13->EnableSRGBRead(this: v13, a2: SHADER_SAMPLER4, a3: false);
      v13->EnableTexture(this: v13, a2: SHADER_SAMPLER5, a3: true);
      v13->EnableSRGBRead(this: v13, a2: SHADER_SAMPLER5, a3: false);
    }
    if ( hasFlashlight )
    {
      v13->EnableTexture(this: v13, a2: SHADER_SAMPLER6, a3: true);
      v13->EnableTexture(this: v13, a2: SHADER_SAMPLER7, a3: true);
      v13->EnableTexture(this: v13, a2: SHADER_SAMPLER8, a3: true);
    }
    if ( ((*params)->m_intVal & 0x200) != 0 )
    {
      CBaseShader::s_pShaderShadow->EnableBlendingForceOpaque(this: CBaseShader::s_pShaderShadow, a2: true);
      CBaseShader::s_pShaderShadow->BlendFunc(
        this: CBaseShader::s_pShaderShadow,
        a2: SHADER_BLEND_SRC_ALPHA,
        a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
      CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: true);
    }
    v14 = 1;
    if ( bLightmapWaterFog || bHasBaseTexture_3 )
      v14 = 3;
    v13->VertexShaderVertexFormat(this: v13, a2: 51u, a3: v14, a4: nullptr, a5: 0);
    nViewportY = bHasMultiTexture;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "MULTITEXTURE", bHasMultiTexture, "bHasMultiTexture");
    nViewportX = bHasBaseTexture_3;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "BASETEXTURE", bHasBaseTexture_3, "bHasBaseTexture");
    nRtHeight = hasFlashlight;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "FLASHLIGHT", hasFlashlight, "hasFlashlight");
    nViewportHeight = bLightmapWaterFog;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "LIGHTMAPWATERFOG", bLightmapWaterFog, "bLightmapWaterFog");
    nRtWidth = bHasFlowmap;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "FLOWMAP", bHasFlowmap, "bHasFlowmap");
    v13->SetVertexShader(
      this: v13,
      a2: "water_vs20",
      a3: nViewportX + 2 * (nViewportY + 2 * (nRtHeight + 2 * (nViewportHeight + 2 * bHasFlowmap))));
    v15 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v16 = 0.0;
    if ( v15 < 92 )
    {
      LOBYTE(v16) = LOBYTE(bReflection) != 0;
      v77.m[2][0] = v16;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFLECT", LOBYTE(bReflection), "bReflection");
      LODWORD(v77.m[2][1]) = bRefraction;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFRACT", bRefraction, "bRefraction");
      m_intVal = params[ABOVEWATER.m_Index]->m_intVal;
      v90 = m_intVal;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "ABOVEWATER", m_intVal, "params[ABOVEWATER]->GetIntValue()");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "MULTITEXTURE", bHasMultiTexture, "bHasMultiTexture");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE", bHasBaseTexture_3, "bHasBaseTexture");
        }
      }
      v20 = params[FLOW_DEBUG.m_Index]->m_intVal;
      if ( v20 >= 0 )
      {
        pShaderShadow = 2;
        if ( v20 <= 2 )
          pShaderShadow = v20;
      }
      else
      {
        pShaderShadow = 0;
      }
      if ( g_shaderConfigDumpEnable )
      {
        if ( v20 >= 0 )
        {
          if ( v20 > 2 )
            v20 = 2;
        }
        else
        {
          v20 = 0;
        }
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FLOW_DEBUG",
          v20,
          "clamp( params[ FLOW_DEBUG ]->GetIntValue(), 0, 2 )");
      }
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FORCEFRESNEL", bForceFresnel, "bForceFresnel");
      v13->SetPixelShader(
        this: v13,
        a2: "water_ps20",
        a3: 4
      * (nViewportX
       + 2
       * (nViewportY
        + 2
        * (LODWORD(v77.m[2][0])
         + 2 * (LODWORD(v77.m[2][1]) + 2 * (v90 + 2 * (bForceFresnel + pShaderShadow + 2 * bForceFresnel)))))));
    }
    else
    {
      LOBYTE(v16) = LOBYTE(bReflection) != 0;
      v77.m[2][0] = v16;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFLECT", LOBYTE(bReflection), "bReflection");
      LODWORD(v77.m[2][1]) = bRefraction;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFRACT", bRefraction, "bRefraction");
      v17 = params[ABOVEWATER.m_Index]->m_intVal;
      v90 = v17;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "ABOVEWATER", v17, "params[ABOVEWATER]->GetIntValue()");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "MULTITEXTURE", bHasMultiTexture, "bHasMultiTexture");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE", bHasBaseTexture_3, "bHasBaseTexture");
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "FLOWMAP", bHasFlowmap, "bHasFlowmap");
          }
        }
      }
      v18 = params[FLOW_DEBUG.m_Index]->m_intVal;
      if ( v18 >= 0 )
      {
        pShaderShadow = 2;
        if ( v18 <= 2 )
          pShaderShadow = v18;
      }
      else
      {
        pShaderShadow = 0;
      }
      if ( g_shaderConfigDumpEnable )
      {
        if ( v18 >= 0 )
        {
          if ( v18 > 2 )
            v18 = 2;
        }
        else
        {
          v18 = 0;
        }
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FLOW_DEBUG",
          v18,
          "clamp( params[ FLOW_DEBUG ]->GetIntValue(), 0, 2 )");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", hasFlashlight, "hasFlashlight");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS stat var %s = %d (%s)", "LIGHTMAPWATERFOG", bLightmapWaterFog, "bLightmapWaterFog");
        }
      }
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FORCEFRESNEL", bForceFresnel, "bForceFresnel");
      v13->SetPixelShader(
        this: v13,
        a2: "water_ps20b",
        a3: 8
      * (nViewportX
       + 2
       * (nViewportY
        + 2
        * (LODWORD(v77.m[2][0])
         + 2
         * (LODWORD(v77.m[2][1])
          + 2
          * (v90
           + 2
           * (nRtWidth
            + 2
            * (nRtHeight
             + 2 * (nViewportHeight + 2 * bForceFresnel)
             + pShaderShadow
             + 2 * (nRtHeight + 2 * (nViewportHeight + 2 * bForceFresnel))))))))));
    }
    CBaseShader::FogToFogColor(this: (CBaseShader *)nViewportWidth);
    v13->EnableSRGBWrite(this: v13, a2: true);
    v13->EnableAlphaWrites(this: v13, a2: true);
    v8 = (Water_DX90::CShader *)nViewportWidth;
  }
  v21 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetDefaultState(this: pShaderAPI);
    if ( bRefraction )
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: REFRACTTEXTURE_0.m_Index,
        nFrameVar: -1);
    if ( LOBYTE(bReflection) != 0 )
    {
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: REFLECTTEXTURE_0.m_Index,
        nFrameVar: -1);
    }
    else if ( params[ENVMAP_8.m_Index]->IsDefined(this: params[ENVMAP_8.m_Index]) )
    {
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: ENVMAP_8.m_Index,
        nFrameVar: -1);
    }
    CBaseShader::BindTexture(
      this: v8,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: NORMALMAP_6.m_Index,
      nFrameVar: BUMPFRAME_13.m_Index);
    if ( bUsingLightmap )
      v21->BindStandardTexture(this: v21, a2: SHADER_SAMPLER3, a3: TEXTURE_BINDFLAGS_NONE, a4: TEXTURE_LIGHTMAP);
    if ( bHasBaseTexture_3 )
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER10,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: 6,
        nFrameVar: 7);
    if ( bHasFlowmap )
    {
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER4,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: FLOWMAP_1.m_Index,
        nFrameVar: FLOWMAPFRAME_0.m_Index);
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER5,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: FLOW_NOISE_TEXTURE_0.m_Index,
        nFrameVar: -1);
      v22 = params[FLOW_WORLDUVSCALE_0.m_Index];
      v23 = params[FLOW_NORMALUVSCALE_0.m_Index];
      memset(gammaReflectTint, 0, sizeof(gammaReflectTint));
      z = 0.0;
      v24 = params[FLOW_BUMPSTRENGTH.m_Index];
      gammaReflectTint[0] = 1.0 / v22->m_VecVal.x;
      v25 = params[COLOR_FLOW_DISPLACEBYNORMALSTRENGTH.m_Index];
      gammaReflectTint[1] = 1.0 / v23->m_VecVal.x;
      v26 = v24->m_VecVal.x;
      SetPixelShaderConstant = v21->SetPixelShaderConstant;
      gammaReflectTint[2] = v26;
      z = v25->m_VecVal.x;
      SetPixelShaderConstant(this: v21, a2: 13, a3: gammaReflectTint, a4: 1, a5: false);
      v28 = params[FLOW_TIMEINTERVALINSECONDS_0.m_Index];
      v29 = params[FLOW_UVSCROLLDISTANCE_0.m_Index];
      memset(linearReflectTint, 0, sizeof(linearReflectTint));
      v30 = params[FLOW_NOISE_SCALE_0.m_Index];
      linearReflectTint[0] = v28->m_VecVal.x;
      v31 = v29->m_VecVal.x;
      v32 = v21->__vftable;
      linearReflectTint[1] = v31;
      v33 = v30->m_VecVal.x;
      v34 = v32->SetPixelShaderConstant;
      linearReflectTint[2] = v33;
      v34(this: v21, a2: 14, a3: linearReflectTint, a4: 1, a5: false);
      v35 = params[COLOR_FLOW_UVSCALE.m_Index];
      memset(vColorFlowConst1, 0, sizeof(vColorFlowConst1));
      v36 = params[COLOR_FLOW_TIMEINTERVALINSECONDS.m_Index];
      v37 = params[COLOR_FLOW_UVSCROLLDISTANCE.m_Index];
      vColorFlowConst1[0] = 1.0 / v35->m_VecVal.x;
      v38 = params[COLOR_FLOW_LERPEXP.m_Index];
      vColorFlowConst1[1] = v36->m_VecVal.x;
      v39 = v37->m_VecVal.x;
      v40 = v21->SetPixelShaderConstant;
      vColorFlowConst1[2] = v39;
      vColorFlowConst1[3] = v38->m_VecVal.x;
      v40(this: v21, a2: 26, a3: vColorFlowConst1, a4: 1, a5: false);
    }
    CurrentTime = v21->CurrentTime;
    memset(&vTimeConst[1], 0, 12);
    vTimeConst[0] = CurrentTime(this: v21);
    v21->SetPixelShaderConstant(this: v21, a2: 8, a3: vTimeConst, a4: 1, a5: false);
    v21->GetMatrix(this: v21, a2: MATERIAL_VIEW, a3: (float *)&v77);
    v42 = VMatrix::Transpose3x3(this: &v77, &result);
    VMatrix::operator=(this: &v77, mOther: v42);
    *(_QWORD *)&vCameraRight.x = *(_QWORD *)&v77.m[0][0];
    vCameraRight.w = 0.0;
    vCameraRight.z = 0.0;
    VectorNormalize(vec: (Vector *)&vCameraRight);
    v43 = v21->SetPixelShaderConstant;
    vCameraForward.x = (float)(vCameraRight.z * 0.0) - vCameraRight.y;
    vCameraForward.y = vCameraRight.x - (float)(vCameraRight.z * 0.0);
    vCameraForward.z = (float)(vCameraRight.y * 0.0) - (float)(vCameraRight.x * 0.0);
    v43(this: v21, a2: 22, a3: &vCameraRight.x, a4: 1, a5: false);
    v21->SetPixelShaderConstant(this: v21, a2: 23, a3: &vCameraForward.x, a4: 1, a5: false);
    CBaseVSShader::SetPixelShaderConstant(this: v8, pixelReg: 25, constantVar: FORCEFRESNEL.m_Index);
    if ( bRefraction )
      CBaseVSShader::SetPixelShaderConstantGammaToLinear(this: v8, pixelReg: 1, constantVar: REFRACTTINT_2.m_Index);
    if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_INTEGER )
    {
      v44 = params[REFLECTTINT_0.m_Index];
      v45 = v44->m_VecVal.x;
      gammaReflectTint[2] = v44->m_VecVal.y;
      z = v44->m_VecVal.z;
      linearReflectTint[0] = GammaToLinear(gamma: v45) * 4.0;
      linearReflectTint[1] = GammaToLinear(gamma: gammaReflectTint[2]) * 4.0;
      v46 = GammaToLinear(gamma: z);
      v47 = params[WATERBLENDFACTOR.m_Index];
      v48 = v21->SetPixelShaderConstant;
      linearReflectTint[2] = v46 * 4.0;
      linearReflectTint[3] = v47->m_VecVal.x;
      v48(this: v21, a2: 4, a3: linearReflectTint, a4: 1, a5: false);
    }
    else
    {
      CBaseVSShader::SetPixelShaderConstantGammaToLinear(
        this: v8,
        pixelReg: 4,
        constantVar: REFLECTTINT_0.m_Index,
        constantVar2: WATERBLENDFACTOR.m_Index);
    }
    CBaseVSShader::SetVertexShaderTextureTransform(this: v8, vertexReg: 49, transformVar: BUMPTRANSFORM_7.m_Index);
    bReflection = v21->CurrentTime(this: v21);
    v49 = params[SCROLL1.m_Index];
    v50 = v49->m_VecVal.x;
    y = v49->m_VecVal.y;
    v52 = params[SCROLL2.m_Index];
    SetVertexShaderConstant = v21->SetVertexShaderConstant;
    vc0[0] = v50 * bReflection;
    vc0[1] = y * bReflection;
    v54 = v52->m_VecVal.y * bReflection;
    vc0[2] = v52->m_VecVal.x * bReflection;
    vc0[3] = v54;
    SetVertexShaderConstant(this: v21, a2: 51, a3: vc0, a4: 1, a5: false);
    v55 = v21->SetPixelShaderConstant;
    c0[0] = 0.33333334;
    c0[1] = 0.33333334;
    c0[2] = 0.33333334;
    c0[3] = 0.0;
    v55(this: v21, a2: 0, a3: c0, a4: 1, a5: false);
    v56 = v21->SetPixelShaderConstant;
    c2[0] = 0.5;
    c2[1] = 0.5;
    c2[2] = 0.5;
    c2[3] = 0.5;
    v56(this: v21, a2: 2, a3: c2, a4: 1, a5: false);
    v57 = v21->SetPixelShaderConstant;
    c3[0] = 1.0;
    memset(&c3[1], 0, 12);
    v57(this: v21, a2: 3, a3: c3, a4: 1, a5: false);
    v58 = params[REFLECTAMOUNT_0.m_Index];
    v59 = v21->SetPixelShaderConstant;
    c5[0] = v58->m_VecVal.x;
    v60 = v58->m_VecVal.x;
    v61 = params[REFRACTAMOUNT_8.m_Index];
    c5[1] = v60;
    c5[2] = v61->m_VecVal.x;
    c5[3] = v61->m_VecVal.x;
    v59(this: v21, a2: 5, a3: c5, a4: 1, a5: false);
    v62 = params[FOGCOLOR.m_Index];
    fogColorConstant[0] = v62->m_VecVal.x;
    fogColorConstant[1] = v62->m_VecVal.y;
    fogColorConstant[2] = v62->m_VecVal.z;
    fogColorConstant[3] = 0.0;
    fogColorConstant[0] = SrgbGammaToLinear(flSrgbGammaValue: fogColorConstant[0]);
    fogColorConstant[1] = SrgbGammaToLinear(flSrgbGammaValue: fogColorConstant[1]);
    fogColorConstant[2] = SrgbGammaToLinear(flSrgbGammaValue: fogColorConstant[2]);
    v21->SetPixelShaderConstant(this: v21, a2: 6, a3: fogColorConstant, a4: 1, a5: false);
    v63 = params[FOGSTART.m_Index];
    v64 = params[FOGEND.m_Index];
    c7[0] = v63->m_VecVal.x;
    c7[1] = v64->m_VecVal.x - v63->m_VecVal.x;
    c7[2] = 1.0;
    c7[3] = 0.0;
    if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_INTEGER )
      c7[2] = 4.0;
    v21->SetPixelShaderConstant(this: v21, a2: 7, a3: c7, a4: 1, a5: false);
    v21->SetPixelShaderFogParams(this: v21, a2: 12);
    v21->GetWorldSpaceCameraPosition(this: v21, a2: vEyePos_SpecExponent);
    v65 = v21->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    v65(this: v21, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    if ( bHasFlowmap )
      CBaseVSShader::SetPixelShaderConstant(this: v8, pixelReg: 9, constantVar: FLOWMAPSCROLLRATE_0.m_Index);
    v21->SetVertexShaderIndex(this: v21, a2: 0);
    DynamicCmdsOut.m_Storage.m_pDataOut = (unsigned __int8 *)&DynamicCmdsOut;
    HIBYTE(pShaderShadow) = 0;
    HIBYTE(pShaderAPI) = 0;
    if ( hasFlashlight )
    {
      v21->GetFlashlightShaderInfo(this: v21, a2: (bool *)&pShaderShadow + 3, a3: (bool *)&pShaderAPI + 3);
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 13;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 52;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 14;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 6;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 7;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 8;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 28;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 15;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 16;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 21;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 31;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = -1;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 0;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      v66 = CBaseShader::s_ppParams[FLASHLIGHTTINT.m_Index];
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 3;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 10;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(float *)DynamicCmdsOut.m_Storage.m_pDataOut = v66->m_VecVal.x;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(float *)DynamicCmdsOut.m_Storage.m_pDataOut = v66->m_VecVal.y;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(float *)DynamicCmdsOut.m_Storage.m_pDataOut = v66->m_VecVal.z;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(float *)DynamicCmdsOut.m_Storage.m_pDataOut = v66->m_VecVal.w;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    }
    v21->GetCurrentViewport(this: v21, a2: &nViewportX, a3: &nViewportY, a4: &nViewportWidth, a5: &nViewportHeight);
    v21->GetCurrentRenderTargetDimensions(this: v21, a2: &nRtWidth, a3: &nRtHeight);
    linearReflectTint[0] = (float)nViewportWidth / (float)nRtWidth;
    v67 = (float)nRtHeight;
    linearReflectTint[1] = (float)nViewportHeight / (float)nRtHeight;
    v68 = (float)nViewportX / (float)nRtWidth;
    v69 = _mm_cvtsi32_si128(nViewportY);
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 3;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 24;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    linearReflectTint[3] = _mm_cvtepi32_ps(v69).m128_f32[0] / v67;
    *(_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = *(_QWORD *)linearReflectTint;
    linearReflectTint[2] = v68;
    *((_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut + 1) = *(_QWORD *)&linearReflectTint[2];
    DynamicCmdsOut.m_Storage.m_pDataOut += 16;
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      if ( r_buildingmapforworld.m_pParent != nullptr )
        m_nValue = r_buildingmapforworld.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      gamma = (m_nValue != 0) + 2 * (v21->GetSceneFogMode(this: v21) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
      v21->SetPixelShaderIndex(this: v21, a2: gamma);
    }
    else
    {
      if ( r_buildingmapforworld.m_pParent != nullptr )
        v70 = r_buildingmapforworld.m_pParent->m_Value.m_nValue;
      else
        v70 = 0;
      v71 = v70 != 0;
      LODWORD(z) = v21->GetSceneFogMode(this: v21) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      LODWORD(gammaReflectTint[1]) = HIBYTE(pShaderShadow) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "FLASHLIGHTSHADOWS",
          HIBYTE(pShaderShadow),
          "bFlashlightShadows");
      v21->SetPixelShaderIndex(this: v21, a2: LODWORD(gammaReflectTint[1]) + 2 * (v71 + 2 * LODWORD(z)));
    }
    *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 0;
    ExecuteCommandBuffer = v21->ExecuteCommandBuffer;
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
    ExecuteCommandBuffer(this: v21, a2: DynamicCmdsOut.m_Storage.m_Data);
  }
  CBaseShader::Draw(this: v8, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10044340
// Name: public: virtual void Water_DX90::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Water_DX90::CShader::OnDrawElements(
        Water_DX90::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v8; // cl
  bool v9; // al
  char v10; // dl
  char v11; // dl
  bool v12; // bl
  float bReflection; // [esp+Ch] [ebp-4h]
  bool bRefraction; // [esp+18h] [ebp+8h]

  v8 = (*((_BYTE *)params[REFRACTTEXTURE_0.m_Index] + 28) & 0xF) == 3;
  v9 = (*((_BYTE *)params[REFLECTTEXTURE_0.m_Index] + 28) & 0xF) == 3;
  v10 = *((_BYTE *)params[ENVMAP_8.m_Index] + 28) & 0xF;
  bRefraction = v8;
  LOBYTE(bReflection) = v9;
  if ( v10 != 3 || (v11 = 1, params[FORCEENVMAP.m_Index]->m_intVal != 1) )
    v11 = 0;
  v12 = params[FORCECHEAP.m_Index]->m_intVal != 0;
  if ( (v9 || v8 || v11 != 0) && !CBaseShader::UsingEditor(this, params) && !v12 )
    Water_DX90::CShader::DrawReflectionRefraction(
      this,
      params,
      (int)pShaderShadow,
      pShaderAPI,
      bReflection,
      bRefraction);
  else
    Water_DX90::CShader::DrawCheapWater(this, params, pShaderShadow, pShaderAPI, bBlend: false, bRefraction);
}

//------------------------------------------------------------------------------
// Address: 0x10069CB0
// Name: Water::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Water::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Water::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10069CC0
// Name: Water::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Water::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_127);
  s_ShaderInstance_127.__vftable = (Water::CShader_vtbl *)&Water::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10069CE0
// Name: Water_DX90::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Water_DX90::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Water_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10069CF0
// Name: Water_DX90::_dynamic_initializer_for__REFRACTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__REFRACTTEXTURE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTEXTURE_0,
           pName: "$REFRACTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_WaterRefraction",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069D10
// Name: Water_DX90::_dynamic_initializer_for__SCENEDEPTH__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__SCENEDEPTH__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &SCENEDEPTH_1,
           pName: "$SCENEDEPTH",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069D30
// Name: Water_DX90::_dynamic_initializer_for__REFLECTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__REFLECTTEXTURE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &REFLECTTEXTURE_0,
           pName: "$REFLECTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_WaterReflection",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069D50
// Name: Water_DX90::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_8,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069D70
// Name: Water_DX90::_dynamic_initializer_for__REFRACTTINT__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__REFRACTTINT__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTINT_2,
           pName: "$REFRACTTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "refraction tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069D90
// Name: Water_DX90::_dynamic_initializer_for__REFLECTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__REFLECTAMOUNT__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &REFLECTAMOUNT_0,
           pName: "$REFLECTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.8",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069DB0
// Name: Water_DX90::_dynamic_initializer_for__REFLECTTINT__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__REFLECTTINT__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &REFLECTTINT_0,
           pName: "$REFLECTTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "reflection tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069DD0
// Name: Water_DX90::_dynamic_initializer_for__NORMALMAP__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__NORMALMAP__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &NORMALMAP_6,
           pName: "$NORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "dev/water_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069DF0
// Name: Water_DX90::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__BUMPFRAME__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &BUMPFRAME_13,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069E10
// Name: Water_DX90::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_7,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069E30
// Name: Water_DX90::_dynamic_initializer_for__TIME__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__TIME__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &TIME_6,
           pName: "$TIME",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069E50
// Name: Water_DX90::_dynamic_initializer_for__WATERDEPTH__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__WATERDEPTH__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &WATERDEPTH,
           pName: "$WATERDEPTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069E70
// Name: Water_DX90::_dynamic_initializer_for__CHEAPWATERSTARTDISTANCE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__CHEAPWATERSTARTDISTANCE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &CHEAPWATERSTARTDISTANCE,
           pName: "$CHEAPWATERSTARTDISTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: "This is the distance from the eye in inches that the shader should start transitioning to a cheaper water shader.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069E90
// Name: Water_DX90::_dynamic_initializer_for__CHEAPWATERENDDISTANCE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__CHEAPWATERENDDISTANCE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &CHEAPWATERENDDISTANCE,
           pName: "$CHEAPWATERENDDISTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: "This is the distance from the eye in inches that the shader should finish transitioning to a cheaper water shader.",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069EB0
// Name: Water_DX90::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__ENVMAP__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &ENVMAP_8,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "env_cubemap",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069ED0
// Name: Water_DX90::_dynamic_initializer_for__ENVMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__ENVMAPFRAME__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &ENVMAPFRAME_5,
           pName: "$ENVMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069EF0
// Name: Water_DX90::_dynamic_initializer_for__FOGCOLOR__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FOGCOLOR__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FOGCOLOR,
           pName: "$FOGCOLOR",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069F10
// Name: Water_DX90::_dynamic_initializer_for__FORCECHEAP__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FORCECHEAP__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FORCECHEAP,
           pName: "$FORCECHEAP",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069F30
// Name: Water_DX90::_dynamic_initializer_for__REFLECTENTITIES__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__REFLECTENTITIES__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &REFLECTENTITIES,
           pName: "$REFLECTENTITIES",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069F50
// Name: Water_DX90::_dynamic_initializer_for__FOGSTART__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FOGSTART__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FOGSTART,
           pName: "$FOGSTART",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069F70
// Name: Water_DX90::_dynamic_initializer_for__FOGEND__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FOGEND__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FOGEND,
           pName: "$FOGEND",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069F90
// Name: Water_DX90::_dynamic_initializer_for__ABOVEWATER__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__ABOVEWATER__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &ABOVEWATER,
           pName: "$ABOVEWATER",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069FB0
// Name: Water_DX90::_dynamic_initializer_for__WATERBLENDFACTOR__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__WATERBLENDFACTOR__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &WATERBLENDFACTOR,
           pName: "$WATERBLENDFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069FD0
// Name: Water_DX90::_dynamic_initializer_for__NOFRESNEL__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__NOFRESNEL__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &NOFRESNEL,
           pName: "$NOFRESNEL",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A000
// Name: Water_DX90::_dynamic_initializer_for__NOLOWENDLIGHTMAP__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__NOLOWENDLIGHTMAP__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &NOLOWENDLIGHTMAP,
           pName: "$NOLOWENDLIGHTMAP",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A020
// Name: Water_DX90::_dynamic_initializer_for__SCROLL1__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__SCROLL1__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &SCROLL1,
           pName: "$SCROLL1",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A040
// Name: Water_DX90::_dynamic_initializer_for__SCROLL2__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__SCROLL2__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &SCROLL2,
           pName: "$SCROLL2",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A060
// Name: Water_DX90::_dynamic_initializer_for__FLASHLIGHTTINT__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLASHLIGHTTINT__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLASHLIGHTTINT,
           pName: "$FLASHLIGHTTINT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A080
// Name: Water_DX90::_dynamic_initializer_for__LIGHTMAPWATERFOG__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__LIGHTMAPWATERFOG__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &LIGHTMAPWATERFOG,
           pName: "$LIGHTMAPWATERFOG",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A0A0
// Name: Water_DX90::_dynamic_initializer_for__FORCEFRESNEL__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FORCEFRESNEL__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FORCEFRESNEL,
           pName: "$FORCEFRESNEL",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A0C0
// Name: Water_DX90::_dynamic_initializer_for__FORCEENVMAP__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FORCEENVMAP__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FORCEENVMAP,
           pName: "$FORCEENVMAP",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A0E0
// Name: Water_DX90::_dynamic_initializer_for__DEPTH_FEATHER__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__DEPTH_FEATHER__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &DEPTH_FEATHER,
           pName: "$DEPTH_FEATHER",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A100
// Name: Water_DX90::_dynamic_initializer_for__FLOWMAP__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOWMAP__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOWMAP_1,
           pName: "$FLOWMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "flowmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A120
// Name: Water_DX90::_dynamic_initializer_for__FLOWMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOWMAPFRAME__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOWMAPFRAME_0,
           pName: "$FLOWMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $flowmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A140
// Name: Water_DX90::_dynamic_initializer_for__FLOWMAPSCROLLRATE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOWMAPSCROLLRATE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOWMAPSCROLLRATE_0,
           pName: "$FLOWMAPSCROLLRATE",
           type: SHADER_PARAM_TYPE_VEC2,
           pDefaultParam: "[0 0",
           pHelp: "2D rate to scroll $flowmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A160
// Name: Water_DX90::_dynamic_initializer_for__FLOW_NOISE_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOW_NOISE_TEXTURE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOW_NOISE_TEXTURE_0,
           pName: "$FLOW_NOISE_TEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "flow noise texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A180
// Name: Water_DX90::_dynamic_initializer_for__FLOW_WORLDUVSCALE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOW_WORLDUVSCALE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOW_WORLDUVSCALE_0,
           pName: "$FLOW_WORLDUVSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A1A0
// Name: Water_DX90::_dynamic_initializer_for__FLOW_NORMALUVSCALE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOW_NORMALUVSCALE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOW_NORMALUVSCALE_0,
           pName: "$FLOW_NORMALUVSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A1C0
// Name: Water_DX90::_dynamic_initializer_for__FLOW_TIMEINTERVALINSECONDS__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOW_TIMEINTERVALINSECONDS__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOW_TIMEINTERVALINSECONDS_0,
           pName: "$FLOW_TIMEINTERVALINSECONDS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A1E0
// Name: Water_DX90::_dynamic_initializer_for__FLOW_UVSCROLLDISTANCE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOW_UVSCROLLDISTANCE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOW_UVSCROLLDISTANCE_0,
           pName: "$FLOW_UVSCROLLDISTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A200
// Name: Water_DX90::_dynamic_initializer_for__FLOW_BUMPSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOW_BUMPSTRENGTH__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOW_BUMPSTRENGTH,
           pName: "$FLOW_BUMPSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A220
// Name: Water_DX90::_dynamic_initializer_for__FLOW_NOISE_SCALE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOW_NOISE_SCALE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOW_NOISE_SCALE_0,
           pName: "$FLOW_NOISE_SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A240
// Name: Water_DX90::_dynamic_initializer_for__FLOW_DEBUG__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__FLOW_DEBUG__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &FLOW_DEBUG,
           pName: "$FLOW_DEBUG",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A260
// Name: Water_DX90::_dynamic_initializer_for__COLOR_FLOW_UVSCALE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__COLOR_FLOW_UVSCALE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &COLOR_FLOW_UVSCALE,
           pName: "$COLOR_FLOW_UVSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A280
// Name: Water_DX90::_dynamic_initializer_for__COLOR_FLOW_TIMEINTERVALINSECONDS__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__COLOR_FLOW_TIMEINTERVALINSECONDS__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &COLOR_FLOW_TIMEINTERVALINSECONDS,
           pName: "$COLOR_FLOW_TIMEINTERVALINSECONDS",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A2A0
// Name: Water_DX90::_dynamic_initializer_for__COLOR_FLOW_UVSCROLLDISTANCE__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__COLOR_FLOW_UVSCROLLDISTANCE__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &COLOR_FLOW_UVSCROLLDISTANCE,
           pName: "$COLOR_FLOW_UVSCROLLDISTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A2C0
// Name: Water_DX90::_dynamic_initializer_for__COLOR_FLOW_LERPEXP__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__COLOR_FLOW_LERPEXP__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &COLOR_FLOW_LERPEXP,
           pName: "$COLOR_FLOW_LERPEXP",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A2E0
// Name: Water_DX90::_dynamic_initializer_for__COLOR_FLOW_DISPLACEBYNORMALSTRENGTH__
// Source: json
//------------------------------------------------------------------------------
Water_DX90::CShaderParam *Water_DX90::_dynamic_initializer_for__COLOR_FLOW_DISPLACEBYNORMALSTRENGTH__()
{
  return Water_DX90::CShaderParam::CShaderParam(
           this: &COLOR_FLOW_DISPLACEBYNORMALSTRENGTH,
           pName: "$COLOR_FLOW_DISPLACEBYNORMALSTRENGTH",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A300
// Name: Water_DX90::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Water_DX90::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_129);
  s_ShaderInstance_129.__vftable = (Water_DX90::CShader_vtbl *)&Water_DX90::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006A320
// Name: Water_DX90::Water_DX9_HDR::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Water_DX90::Water_DX9_HDR::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_128);
  s_ShaderInstance_128.__vftable = (Water_DX90::Water_DX9_HDR::CShader_vtbl *)&Water_DX90::Water_DX9_HDR::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B900
// Name: Water::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Water::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_127);
}

//------------------------------------------------------------------------------
// Address: 0x1006B910
// Name: Water_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Water_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_128);
}

//------------------------------------------------------------------------------
// Address: 0x1006A340
// Name: _dynamic_initializer_for__s_ConstructMe_windowimposter_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_windowimposter_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &windowimposter_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006A360
// Name: _dynamic_initializer_for__s_ConstructMe_windowimposter_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_windowimposter_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &windowimposter_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006A380
// Name: _dynamic_initializer_for__s_ConstructMe_windowimposter_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_windowimposter_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &windowimposter_ps20b_combos);
}
