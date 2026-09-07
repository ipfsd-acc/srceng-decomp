// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/flesh_interior_blended_pass_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10012C10
// Name: void InitParamsFleshInteriorBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct FleshInteriorBlendedPassVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsFleshInteriorBlendedPass(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        FleshInteriorBlendedPassVars_t *info)
{
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx
  IMaterialVar *v10; // ecx
  IMaterialVar *v11; // ecx
  IMaterialVar *v12; // ecx
  IMaterialVar *v13; // ecx
  IMaterialVar *v14; // ecx
  IMaterialVar *v15; // ecx
  IMaterialVar *v16; // ecx
  IMaterialVar *v17; // ecx
  IMaterialVar *v18; // ecx
  IMaterialVar *v19; // ecx
  IMaterialVar *v20; // ecx
  IMaterialVar *v21; // ecx
  IMaterialVar *v22; // ecx
  IMaterialVar *v23; // ecx
  IMaterialVar *v24; // ecx
  IMaterialVar *v25; // ecx

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  if ( info->m_nFleshCubeTexture != -1 )
  {
    v4 = params[info->m_nFleshCubeTexture];
    if ( !v4->IsDefined(this: v4) )
    {
      v5 = params[info->m_nFleshCubeTexture];
      v5->SetStringValue(this: v5, a2: "env_cubemap");
    }
  }
  if ( info->m_nflBorderNoiseScale != -1 )
  {
    v6 = params[info->m_nflBorderNoiseScale];
    if ( !v6->IsDefined(this: v6) )
      ((void (__stdcall *)(int))params[info->m_nflBorderNoiseScale]->SetFloatValue)(a1: 1069547520);
  }
  if ( info->m_nflDebugForceFleshOn != -1 )
  {
    v7 = params[info->m_nflDebugForceFleshOn];
    if ( !v7->IsDefined(this: v7) )
      ((void (__stdcall *)(_DWORD))params[info->m_nflDebugForceFleshOn]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nvEffectCenterRadius1 != -1 )
  {
    v8 = params[info->m_nvEffectCenterRadius1];
    if ( !v8->IsDefined(this: v8) )
    {
      v9 = params[info->m_nvEffectCenterRadius1];
      v9->SetVecValue_4(this: v9, a2: kDefaultEffectCenterRadius, a3: 4);
    }
  }
  if ( info->m_nvEffectCenterRadius2 != -1 )
  {
    v10 = params[info->m_nvEffectCenterRadius2];
    if ( !v10->IsDefined(this: v10) )
    {
      v11 = params[info->m_nvEffectCenterRadius2];
      v11->SetVecValue_4(this: v11, a2: kDefaultEffectCenterRadius, a3: 4);
    }
  }
  if ( info->m_nvEffectCenterRadius3 != -1 )
  {
    v12 = params[info->m_nvEffectCenterRadius3];
    if ( !v12->IsDefined(this: v12) )
    {
      v13 = params[info->m_nvEffectCenterRadius3];
      v13->SetVecValue_4(this: v13, a2: kDefaultEffectCenterRadius, a3: 4);
    }
  }
  if ( info->m_nvEffectCenterRadius4 != -1 )
  {
    v14 = params[info->m_nvEffectCenterRadius4];
    if ( !v14->IsDefined(this: v14) )
    {
      v15 = params[info->m_nvEffectCenterRadius4];
      v15->SetVecValue_4(this: v15, a2: kDefaultEffectCenterRadius, a3: 4);
    }
  }
  if ( info->m_ncSubsurfaceTint != -1 )
  {
    v16 = params[info->m_ncSubsurfaceTint];
    if ( !v16->IsDefined(this: v16) )
    {
      v17 = params[info->m_ncSubsurfaceTint];
      v17->SetVecValue_4(this: v17, a2: kDefaultSubsurfaceTint, a3: 4);
    }
  }
  if ( info->m_nflBorderWidth != -1 )
  {
    v18 = params[info->m_nflBorderWidth];
    if ( !v18->IsDefined(this: v18) )
      ((void (__stdcall *)(int))params[info->m_nflBorderWidth]->SetFloatValue)(a1: 1050253722);
  }
  if ( info->m_nflBorderSoftness != -1 )
  {
    v19 = params[info->m_nflBorderSoftness];
    if ( !v19->IsDefined(this: v19) )
      ((void (__stdcall *)(int))params[info->m_nflBorderSoftness]->SetFloatValue)(a1: 1054280253);
  }
  if ( info->m_ncBorderTint != -1 )
  {
    v20 = params[info->m_ncBorderTint];
    if ( !v20->IsDefined(this: v20) )
    {
      v21 = params[info->m_ncBorderTint];
      v21->SetVecValue_4(this: v21, a2: kDefaultBorderTint, a3: 4);
    }
  }
  if ( info->m_nflGlobalOpacity != -1 )
  {
    v22 = params[info->m_nflGlobalOpacity];
    if ( !v22->IsDefined(this: v22) )
      ((void (__stdcall *)(int))params[info->m_nflGlobalOpacity]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nflGlossBrightness != -1 )
  {
    v23 = params[info->m_nflGlossBrightness];
    if ( !v23->IsDefined(this: v23) )
      ((void (__stdcall *)(int))params[info->m_nflGlossBrightness]->SetFloatValue)(a1: 1059648963);
  }
  if ( info->m_nflScrollSpeed != -1 )
  {
    v24 = params[info->m_nflScrollSpeed];
    if ( !v24->IsDefined(this: v24) )
      ((void (__stdcall *)(int))params[info->m_nflScrollSpeed]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nTime != -1 )
  {
    v25 = params[info->m_nTime];
    if ( !v25->IsDefined(this: v25) )
      ((void (__stdcall *)(_DWORD))params[info->m_nTime]->SetFloatValue)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012EE0
// Name: void InitFleshInteriorBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct FleshInteriorBlendedPassVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitFleshInteriorBlendedPass(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        FleshInteriorBlendedPassVars_t *info)
{
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFleshTexture, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFleshNoiseTexture, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFleshBorderTexture1D, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFleshNormalTexture, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(
    this: pShader,
    nTextureVar: info->m_nFleshSubsurfaceTexture,
    nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadCubeMap(this: pShader, nTextureVar: info->m_nFleshCubeTexture, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x10012F50
// Name: void DrawFleshInteriorBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct FleshInteriorBlendedPassVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawFleshInteriorBlendedPass(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        FleshInteriorBlendedPassVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  IMaterialVar **v6; // ebx
  bool v7; // bl
  int v8; // eax
  BOOL v9; // edi
  bool v10; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  void (__thiscall *GetDX9LightState)(IShaderDynamicAPI *, LightState_t *); // edx
  int v14; // eax
  BOOL v15; // eax
  BOOL v16; // eax
  int v17; // esi
  IMaterialVar *v18; // ecx
  float x; // xmm0_4
  double v20; // xmm0_8
  IMaterialVar *v21; // ecx
  float v22; // xmm0_4
  bool v23; // sf
  float v24; // xmm0_4
  IMaterialVar *v25; // ecx
  float v26; // xmm0_4
  IMaterialVar *v27; // ecx
  float v28; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v30; // ecx
  float *v31; // eax
  float v32; // xmm0_4
  IMaterialVar *v33; // ecx
  float *v34; // eax
  float v35; // xmm0_4
  IMaterialVar *v36; // ecx
  float *v37; // eax
  float v38; // xmm0_4
  IMaterialVar *v39; // ecx
  float *v40; // eax
  float v41; // xmm0_4
  IMaterialVar *v42; // ecx
  const float *p_x; // eax
  IMaterialVar *v44; // ecx
  float v45; // xmm2_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v47; // ecx
  float v48; // xmm1_4
  IMaterialVar *v49; // ecx
  const float *v50; // eax
  IMaterialVar *v51; // ecx
  float v52; // xmm0_4
  void (__thiscall *v53)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v54; // ecx
  float v55; // xmm0_4
  void (__thiscall *v56)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const char *v57; // [esp+88h] [ebp-C8h]
  int v58; // [esp+8Ch] [ebp-C4h]
  BOOL v59; // [esp+9Ch] [ebp-B4h]
  BOOL v60; // [esp+A0h] [ebp-B0h]
  float vPsConst4[4]; // [esp+B0h] [ebp-A0h] BYREF
  float vPsConst1[4]; // [esp+C0h] [ebp-90h] BYREF
  long double v63; // [esp+D0h] [ebp-80h]
  float vVsConst0[4]; // [esp+D8h] [ebp-78h] BYREF
  float vVsConst2[4]; // [esp+E8h] [ebp-68h] BYREF
  float vVsConst4[4]; // [esp+F8h] [ebp-58h] BYREF
  float vVsConst1[4]; // [esp+108h] [ebp-48h] BYREF
  float vPsConst2[4]; // [esp+118h] [ebp-38h] BYREF
  float vVsConst3[4]; // [esp+128h] [ebp-28h] BYREF
  float vPsConst5[4]; // [esp+138h] [ebp-18h] BYREF
  LightState_t lightState; // [esp+148h] [ebp-8h] BYREF
  int pShaderAPIa; // [esp+160h] [ebp+10h]
  float flCurrentTime; // [esp+164h] [ebp+14h]
  bool flCurrentTime_3; // [esp+167h] [ebp+17h]

  v6 = params;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this: pShader);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    v7 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
    LODWORD(vPsConst5[2]) = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v9 = ((*params)->m_intVal & 0x8000000) != 0;
    LODWORD(vPsConst5[3]) = v8 < 92;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", v9, "IS_FLAG_SET( MATERIAL_VAR_HALFLAMBERT )");
    LODWORD(vPsConst5[1]) = v7;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "FLATTEN_STATIC_CONTROL_FLOW", v7, "bFlattenStaticControlFlow");
    pShaderShadow->SetVertexShader(
      this: pShaderShadow,
      a2: "flesh_interior_blended_pass_vs20",
      a3: 96 * (v9 + 2 * (LODWORD(vPsConst5[1]) + 2 * (LODWORD(vPsConst5[2]) + 2 * LODWORD(vPsConst5[3])))));
    v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    SetPixelShader = pShaderShadow->SetPixelShader;
    v58 = 0;
    if ( v10 )
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "flesh_interior_blended_pass_ps20");
    else
      ((void (__stdcall *)(const char *))SetPixelShader)(a1: "flesh_interior_blended_pass_ps20b");
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: true);
    ((void (__thiscall *)(IShaderShadow *, int, _DWORD))pShaderShadow->AlphaFunc)(a1: pShaderShadow, a2: 4, a3: 0);
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    CBaseShader::PI_SetVertexShaderAmbientLightCube(this: pShader);
    CBaseShader::PI_EndCommandBuffer(this: pShader);
    v6 = params;
  }
  if ( pShaderAPI != nullptr )
  {
    ((void (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->SetDefaultState)(a1: pShaderAPI, a2: v58);
    flCurrentTime_3 = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
    GetDX9LightState = pShaderAPI->GetDX9LightState;
    lightState.m_nNumLights = 0;
    *(_WORD *)&lightState.m_bAmbientLight = 0;
    GetDX9LightState(this: pShaderAPI, a2: &lightState);
    v60 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v59 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v14 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v14 > 0, v57);
    }
    if ( lightState.m_bAmbientLight || (pShaderAPIa = 0, lightState.m_nNumLights > 0) )
      pShaderAPIa = 1;
    if ( g_shaderConfigDumpEnable )
    {
      v15 = lightState.m_bAmbientLight || lightState.m_nNumLights > 0;
      printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", v15, "lightState.HasDynamicLight()");
    }
    HIDWORD(v63) = lightState.m_bStaticLight;
    if ( g_shaderConfigDumpEnable )
    {
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "STATIC_LIGHT",
        lightState.m_bStaticLight,
        "lightState.m_bStaticLight ? 1 : 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    v16 = flCurrentTime_3;
    v17 = v16 ? 0 : lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        v16 ? 0 : lightState.m_nNumLights,
        "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: vertexCompression + 2 * (v59 + 2 * (v60 + 2 * (pShaderAPIa + 2 * (HIDWORD(v63) + 2 * v17)))));
    if ( info->m_nTime >= 0
      && (v18 = v6[info->m_nTime], v18->IsDefined(this: v18))
      && (x = v6[info->m_nTime]->m_VecVal.x) > 0.0 )
    {
      v20 = x;
    }
    else
    {
      v63 = pShaderAPI->CurrentTime(this: pShaderAPI);
      v20 = v63;
    }
    flCurrentTime = v20;
    if ( info->m_nflScrollSpeed >= 0 && (v21 = v6[info->m_nflScrollSpeed], v21->IsDefined(this: v21)) )
      v22 = v6[info->m_nflScrollSpeed]->m_VecVal.x;
    else
      v22 = 1.0;
    v23 = info->m_nflBorderNoiseScale < 0;
    v24 = v22 * flCurrentTime;
    vVsConst0[2] = 0.0;
    vVsConst0[3] = 0.0;
    vVsConst0[0] = v24 - (float)((float)(int)(float)(v24 * 0.001) * 1000.0);
    vVsConst0[1] = (float)(v24 * 0.0099999998) - (float)(int)(float)(v24 * 0.0099999998);
    if ( v23 || (v25 = v6[info->m_nflBorderNoiseScale], !v25->IsDefined(this: v25)) )
      v26 = 1.5;
    else
      v26 = v6[info->m_nflBorderNoiseScale]->m_VecVal.x;
    v23 = info->m_nflDebugForceFleshOn < 0;
    vVsConst0[2] = v26;
    if ( v23 || (v27 = v6[info->m_nflDebugForceFleshOn], !v27->IsDefined(this: v27)) )
      v28 = 0.0;
    else
      v28 = v6[info->m_nflDebugForceFleshOn]->m_VecVal.x;
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    vVsConst0[3] = v28;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: vVsConst0, a4: 1, a5: false);
    v23 = info->m_nvEffectCenterRadius1 < 0;
    memset(vVsConst1, 0, 12);
    vVsConst1[3] = 0.000099999997;
    if ( !v23 )
    {
      v30 = v6[info->m_nvEffectCenterRadius1];
      if ( v30->IsDefined(this: v30) )
      {
        v31 = (float *)v6[info->m_nvEffectCenterRadius1];
        vVsConst1[0] = v31[3];
        vVsConst1[1] = v31[4];
        vVsConst1[2] = v31[5];
        v32 = v31[6];
        if ( v32 < 0.001 )
          v32 = 0.001;
        vVsConst1[3] = 1.0 / v32;
      }
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 49, a3: vVsConst1, a4: 1, a5: false);
    v23 = info->m_nvEffectCenterRadius2 < 0;
    memset(vVsConst2, 0, 12);
    vVsConst2[3] = 0.000099999997;
    if ( !v23 )
    {
      v33 = v6[info->m_nvEffectCenterRadius2];
      if ( v33->IsDefined(this: v33) )
      {
        v34 = (float *)v6[info->m_nvEffectCenterRadius2];
        vVsConst2[0] = v34[3];
        vVsConst2[1] = v34[4];
        vVsConst2[2] = v34[5];
        v35 = v34[6];
        if ( v35 < 0.001 )
          v35 = 0.001;
        vVsConst2[3] = 1.0 / v35;
      }
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 50, a3: vVsConst2, a4: 2, a5: false);
    v23 = info->m_nvEffectCenterRadius3 < 0;
    memset(vVsConst3, 0, 12);
    vVsConst3[3] = 0.000099999997;
    if ( !v23 )
    {
      v36 = v6[info->m_nvEffectCenterRadius3];
      if ( v36->IsDefined(this: v36) )
      {
        v37 = (float *)v6[info->m_nvEffectCenterRadius3];
        vVsConst3[0] = v37[3];
        vVsConst3[1] = v37[4];
        vVsConst3[2] = v37[5];
        v38 = v37[6];
        if ( v38 < 0.001 )
          v38 = 0.001;
        vVsConst3[3] = 1.0 / v38;
      }
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 51, a3: vVsConst3, a4: 3, a5: false);
    v23 = info->m_nvEffectCenterRadius4 < 0;
    memset(vVsConst4, 0, 12);
    vVsConst4[3] = 0.000099999997;
    if ( !v23 )
    {
      v39 = v6[info->m_nvEffectCenterRadius4];
      if ( v39->IsDefined(this: v39) )
      {
        v40 = (float *)v6[info->m_nvEffectCenterRadius4];
        vVsConst4[0] = v40[3];
        vVsConst4[1] = v40[4];
        vVsConst4[2] = v40[5];
        v41 = v40[6];
        if ( v41 < 0.001 )
          v41 = 0.001;
        vVsConst4[3] = 1.0 / v41;
      }
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 52, a3: vVsConst4, a4: 4, a5: false);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nFleshTexture,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nFleshNoiseTexture,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nFleshBorderTexture1D,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nFleshNormalTexture,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER4,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nFleshSubsurfaceTexture,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER5,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nFleshCubeTexture,
      nFrameVar: -1);
    if ( info->m_ncSubsurfaceTint >= 0 && (v42 = v6[info->m_ncSubsurfaceTint], v42->IsDefined(this: v42)) )
      p_x = &v6[info->m_ncSubsurfaceTint]->m_VecVal.x;
    else
      p_x = kDefaultSubsurfaceTint;
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: p_x, a4: 1, a5: false);
    v23 = info->m_nflBorderWidth < 0;
    memset(vPsConst1, 0, sizeof(vPsConst1));
    if ( v23 || (v44 = v6[info->m_nflBorderWidth], !v44->IsDefined(this: v44)) )
      v45 = 0.30000001;
    else
      v45 = v6[info->m_nflBorderWidth]->m_VecVal.x;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vPsConst1[0] = 1.0 / v45;
    vPsConst1[1] = (float)(1.0 / v45) - 1.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 1, a3: vPsConst1, a4: 1, a5: false);
    v23 = info->m_nflBorderSoftness < 0;
    memset(vPsConst2, 0, sizeof(vPsConst2));
    if ( v23 || (v47 = v6[info->m_nflBorderSoftness], !v47->IsDefined(this: v47)) )
    {
      vPsConst2[0] = 0.41999999;
    }
    else
    {
      v48 = 0.0099999998;
      vPsConst2[0] = v6[info->m_nflBorderSoftness]->m_VecVal.x;
      if ( vPsConst2[0] < 0.0099999998 || (v48 = 0.5, vPsConst2[0] > 0.5) )
        vPsConst2[0] = v48;
    }
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 2, a3: vPsConst2, a4: 1, a5: false);
    if ( info->m_ncBorderTint >= 0 && (v49 = v6[info->m_ncBorderTint], v49->IsDefined(this: v49)) )
      v50 = &v6[info->m_ncBorderTint]->m_VecVal.x;
    else
      v50 = kDefaultBorderTint;
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 3, a3: v50, a4: 1, a5: false);
    v23 = info->m_nflGlobalOpacity < 0;
    memset(vPsConst4, 0, sizeof(vPsConst4));
    if ( v23 || (v51 = v6[info->m_nflGlobalOpacity], !v51->IsDefined(this: v51)) )
      v52 = 1.0;
    else
      v52 = v6[info->m_nflGlobalOpacity]->m_VecVal.x;
    v53 = pShaderAPI->SetPixelShaderConstant;
    vPsConst4[0] = v52;
    v53(this: pShaderAPI, a2: 4, a3: vPsConst4, a4: 1, a5: false);
    v23 = info->m_nflGlossBrightness < 0;
    memset(vPsConst5, 0, sizeof(vPsConst5));
    if ( v23 || (v54 = v6[info->m_nflGlossBrightness], !v54->IsDefined(this: v54)) )
      v55 = 0.66000003;
    else
      v55 = v6[info->m_nflGlossBrightness]->m_VecVal.x;
    v56 = pShaderAPI->SetPixelShaderConstant;
    vPsConst5[0] = v55;
    v56(this: pShaderAPI, a2: 5, a3: vPsConst5, a4: 1, a5: false);
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
