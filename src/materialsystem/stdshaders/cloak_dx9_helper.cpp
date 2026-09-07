// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/cloak_dx9_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10009250
// Name: void InitParamsCloak_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct Cloak_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsCloak_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        Cloak_DX9_Vars_t *info)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  v5 = params[info->m_nFresnelReflection];
  if ( !v5->IsDefined(this: v5) )
    ((void (__stdcall *)(int))params[info->m_nFresnelReflection]->SetFloatValue)(a1: 1065353216);
  v6 = params[info->m_nMasked];
  if ( !v6->IsDefined(this: v6) )
  {
    v7 = params[info->m_nMasked];
    v7->SetIntValue(this: v7, a2: 0);
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x4000);
}

//------------------------------------------------------------------------------
// Address: 0x10009300
// Name: void InitCloak_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct Cloak_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCloak_DX9(CBaseVSShader *pShader, IMaterialVar **params, Cloak_DX9_Vars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx

  if ( params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0x80000);
  v3 = params[info->m_nNormalMap];
  if ( v3->IsDefined(this: v3) )
    CBaseShader::LoadBumpMap(this: pShader, nTextureVar: info->m_nNormalMap, nAdditionalCreationFlags: 0);
  if ( info->m_nDiffuseWarpTexture != -1 )
  {
    v4 = params[info->m_nDiffuseWarpTexture];
    if ( v4->IsDefined(this: v4) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nDiffuseWarpTexture, nAdditionalCreationFlags: 0);
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
}

//------------------------------------------------------------------------------
// Address: 0x10009390
// Name: void DrawCloak_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct Cloak_DX9_Vars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawCloak_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        int info,
        VertexCompressionType_t vertexCompression)
{
  IMaterialVar **v6; // ebx
  Cloak_DX9_Vars_t *v7; // edi
  bool v8; // cl
  int v9; // eax
  char v10; // dl
  int v11; // eax
  int v12; // eax
  char v13; // cl
  bool v14; // zf
  int v15; // eax
  bool v16; // al
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  bool v20; // bl
  int v21; // ebx
  BOOL v22; // ebx
  int (__thiscall *GetCurrentNumBones)(IShaderDynamicAPI *); // eax
  int v24; // eax
  int v25; // eax
  float v26; // ecx
  BOOL v27; // edi
  BOOL v28; // ebx
  int v29; // eax
  BOOL v30; // ebx
  void (__thiscall *GetWorldSpaceCameraPosition)(IShaderDynamicAPI *, float *); // edx
  IMaterialVar *v32; // ecx
  float x; // xmm0_4
  IMaterialVar *v34; // ecx
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // ecx
  int m_nRimMask; // edx
  float v38; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v40; // xmm0_4
  IMaterialVar *v41; // ecx
  float *v42; // eax
  IMaterialVar *v43; // ecx
  float v44; // xmm0_4
  void (__thiscall *v45)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const VMatrix *v46; // eax
  int m_nCloakFactor; // edx
  float v48; // xmm0_4
  void (__thiscall *v49)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const char *v50; // [esp-4h] [ebp-180h]
  const char *v51; // [esp-4h] [ebp-180h]
  VMatrix result; // [esp+Ch] [ebp-170h] BYREF
  VMatrix matProj; // [esp+4Ch] [ebp-130h] BYREF
  VMatrix matViewProj; // [esp+8Ch] [ebp-F0h] BYREF
  VMatrix matView; // [esp+CCh] [ebp-B0h] BYREF
  float vEyePos_SpecExponent[4]; // [esp+10Ch] [ebp-70h] BYREF
  float vCloakControls[4]; // [esp+11Ch] [ebp-60h] BYREF
  float vRimBoost[4]; // [esp+12Ch] [ebp-50h] BYREF
  LightState_t lightState; // [esp+13Ch] [ebp-40h] BYREF
  float vFresnelRanges_SpecBoost[4]; // [esp+144h] [ebp-38h] BYREF
  Vector4D vSpecularTint; // [esp+154h] [ebp-28h] BYREF
  float vRimMaskControl[4]; // [esp+164h] [ebp-18h] BYREF
  bool bMasked; // [esp+176h] [ebp-6h]
  bool bHasRimLight; // [esp+177h] [ebp-5h]
  bool hasPhongTintMap; // [esp+178h] [ebp-4h]
  bool bHasRimMaskMap; // [esp+179h] [ebp-3h]
  bool hasDiffuseWarp; // [esp+17Ah] [ebp-2h]
  bool bIsModel; // [esp+17Bh] [ebp-1h]
  int bUseStaticControlFlow; // [esp+188h] [ebp+Ch]
  BOOL bUseStaticControlFlowa; // [esp+188h] [ebp+Ch]
  bool bUseStaticControlFlow_3; // [esp+18Bh] [ebp+Fh]
  MaterialFogMode_t fogType; // [esp+190h] [ebp+14h]
  int nPS20NumLights; // [esp+194h] [ebp+18h]

  v6 = params;
  v7 = (Cloak_DX9_Vars_t *)info;
  v8 = ((*params)->m_intVal & 0x800) != 0;
  v9 = *(_DWORD *)(info + 44);
  bMasked = params[*(_DWORD *)(info + 36)]->m_intVal != 0;
  bIsModel = v8;
  if ( v9 == -1 || (v10 = *((_BYTE *)params[v9] + 28) & 0xF, hasDiffuseWarp = true, v10 != 3) )
    hasDiffuseWarp = false;
  v11 = *(_DWORD *)(info + 60);
  if ( v11 == -1 || (*((_BYTE *)params[v11] + 28) & 0xF) != 3 )
  {
    v13 = 0;
LABEL_8:
    hasPhongTintMap = false;
    goto LABEL_9;
  }
  v12 = *(_DWORD *)(info + 56);
  v13 = 1;
  if ( v12 == -1 )
    goto LABEL_8;
  v14 = params[v12]->m_intVal == 0;
  hasPhongTintMap = true;
  if ( v14 )
    goto LABEL_8;
LABEL_9:
  v15 = *(_DWORD *)(info + 72);
  v16 = v15 != -1 && params[v15]->m_intVal != 0;
  bHasRimLight = v16;
  if ( v13 == 0
    || !v16
    || (v17 = *(_DWORD *)(info + 84)) == -1
    || (v14 = params[v17]->m_intVal == 0, bHasRimMaskMap = true, v14) )
  {
    bHasRimMaskMap = false;
  }
  if ( pShaderShadow != nullptr )
  {
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
    CBaseShader::SetInitialShadowState(this: pShader);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    v18 = 0;
    v19 = 3;
    if ( bIsModel )
      v18 = 4;
    else
      v19 = 51;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v19 | 0x400, a3: 1, a4: nullptr, a5: v18);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      v22 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      LODWORD(vRimMaskControl[1]) = bIsModel;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "MODEL", bIsModel, "bIsModel");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "cloak_vs30",
        a3: 16 * (LODWORD(vRimMaskControl[1]) + 2 * v22));
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "LIGHTWARPTEXTURE", hasDiffuseWarp, "hasDiffuseWarp");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "cloak_ps30", a3: 20 * hasDiffuseWarp);
    }
    else
    {
      v20 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
      LODWORD(vFresnelRanges_SpecBoost[2]) = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      LODWORD(vFresnelRanges_SpecBoost[3]) = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      LODWORD(vFresnelRanges_SpecBoost[0]) = bIsModel;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "MODEL", bIsModel, "bIsModel");
      LODWORD(vFresnelRanges_SpecBoost[1]) = v20;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FLATTEN_STATIC_CONTROL_FLOW", v20, "bFlattenStaticControlFlow");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "cloak_vs20",
        a3: 24
      * (LODWORD(vFresnelRanges_SpecBoost[0])
       + 2
       * (LODWORD(vFresnelRanges_SpecBoost[1])
        + 2 * (LODWORD(vFresnelRanges_SpecBoost[2]) + 2 * LODWORD(vFresnelRanges_SpecBoost[3])))));
      v21 = 0;
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "LIGHTWARPTEXTURE", hasDiffuseWarp, "hasDiffuseWarp");
        LOBYTE(v21) = hasDiffuseWarp;
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "cloak_ps20", a3: 12 * v21);
      }
      else
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "LIGHTWARPTEXTURE", hasDiffuseWarp, "hasDiffuseWarp");
        LOBYTE(v21) = hasDiffuseWarp;
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "cloak_ps20b", a3: 20 * v21);
      }
    }
    CBaseShader::DefaultFog(this: pShader);
    if ( bMasked )
      CBaseShader::EnableAlphaBlending(
        this: pShader,
        src: SHADER_BLEND_ONE_MINUS_SRC_ALPHA,
        dst: SHADER_BLEND_SRC_ALPHA);
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 4);
    CBaseShader::PI_SetPixelShaderLocalLighting(this: pShader, nFirstRegister: 20);
    CBaseShader::PI_EndCommandBuffer(this: pShader);
    v6 = params;
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetDefaultState(this: pShaderAPI);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: *(_DWORD *)info,
      nFrameVar: 0);
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER2,
      a3: TEXTURE_BINDFLAGS_NONE,
      a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: *(_DWORD *)(info + 12),
      nFrameVar: *(_DWORD *)(info + 16));
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER5,
      a3: TEXTURE_BINDFLAGS_NONE,
      a4: TEXTURE_NORMALIZATION_CUBEMAP_SIGNED);
    if ( hasDiffuseWarp )
    {
      if ( r_lightwarpidentity.m_pParent != nullptr && r_lightwarpidentity.m_pParent->m_Value.m_nValue != 0 )
        pShaderAPI->BindStandardTexture(
          this: pShaderAPI,
          a2: SHADER_SAMPLER1,
          a3: TEXTURE_BINDFLAGS_NONE,
          a4: TEXTURE_IDENTITY_LIGHTWARP);
      else
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER1,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: *(_DWORD *)(info + 44),
          nFrameVar: -1);
    }
    fogType = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: &lightState);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      CBaseVSShader::SetHWMorphVertexShaderState(
        this: pShader,
        nDimConst: 54,
        nSubrectConst: 55,
        morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      v27 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v28 = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
      LODWORD(vRimMaskControl[2]) = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v29 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v29 > 0, v51);
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
      }
      pShaderAPI->SetVertexShaderIndex(
        this: pShaderAPI,
        a2: vertexCompression + 2 * (v27 + 2 * (LODWORD(vRimMaskControl[2]) + 2 * v28)));
      v30 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      vRimMaskControl[3] = *(float *)&lightState.m_nNumLights;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          lightState.m_nNumLights,
          "lightState.m_nNumLights");
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "WRITEWATERFOGTODESTALPHA",
          fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z,
          "fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z");
      pShaderAPI->SetPixelShaderIndex(
        this: pShaderAPI,
        a2: v30 + 2 * ((fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z) + 2 * LODWORD(vRimMaskControl[3])));
      v7 = (Cloak_DX9_Vars_t *)info;
      v6 = params;
    }
    else
    {
      bUseStaticControlFlow_3 = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
      v14 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      GetCurrentNumBones = pShaderAPI->GetCurrentNumBones;
      LODWORD(vRimMaskControl[1]) = v14;
      LODWORD(vRimMaskControl[2]) = GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v24 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v24 > 0, v50);
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
      }
      v25 = bUseStaticControlFlow_3 ? 0 : lightState.m_nNumLights;
      bUseStaticControlFlow = v25;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          v25,
          "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
      pShaderAPI->SetVertexShaderIndex(
        this: pShaderAPI,
        a2: vertexCompression
      + 2 * (LODWORD(vRimMaskControl[1]) + 2 * (LODWORD(vRimMaskControl[2]) + 2 * bUseStaticControlFlow)));
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        nPS20NumLights = lightState.m_nNumLights;
        if ( lightState.m_nNumLights <= 1 )
          nPS20NumLights = 1;
        LODWORD(vRimMaskControl[1]) = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", nPS20NumLights, "nPS20NumLights");
        bUseStaticControlFlowa = fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z,
            "fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z");
        v26 = *(float *)&nPS20NumLights;
      }
      else
      {
        v14 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
        vRimMaskControl[3] = *(float *)&lightState.m_nNumLights;
        LODWORD(vRimMaskControl[1]) = v14;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "NUM_LIGHTS",
            lightState.m_nNumLights,
            "lightState.m_nNumLights");
        bUseStaticControlFlowa = fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z,
            "fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z");
        v26 = vRimMaskControl[3];
      }
      pShaderAPI->SetPixelShaderIndex(
        this: pShaderAPI,
        a2: LODWORD(vRimMaskControl[1]) + 2 * (bUseStaticControlFlowa + 2 * LODWORD(v26)));
    }
    CBaseVSShader::SetVertexShaderTextureTransform(this: pShader, vertexReg: 49, transformVar: v7->m_nBumpTransform);
    if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) != HDR_TYPE_NONE )
      CBaseVSShader::SetPixelShaderConstantGammaToLinear(this: pShader, pixelReg: 27, constantVar: v7->m_nRefractTint);
    else
      CBaseVSShader::SetPixelShaderConstant(this: pShader, pixelReg: 27, constantVar: v7->m_nRefractTint);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    GetWorldSpaceCameraPosition = pShaderAPI->GetWorldSpaceCameraPosition;
    vFresnelRanges_SpecBoost[0] = 0.0;
    vFresnelRanges_SpecBoost[1] = 0.5;
    vFresnelRanges_SpecBoost[2] = 1.0;
    vFresnelRanges_SpecBoost[3] = 1.0;
    vSpecularTint.x = 1.0;
    vSpecularTint.y = 1.0;
    vSpecularTint.z = 1.0;
    vSpecularTint.w = 1.0;
    vRimBoost[0] = 1.0;
    vRimBoost[1] = 1.0;
    vRimBoost[2] = 1.0;
    vRimBoost[3] = 1.0;
    GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
    if ( v7->m_nPhongExponent == -1 || (v32 = v6[v7->m_nPhongExponent], !v32->IsDefined(this: v32)) )
      x = 0.0;
    else
      x = v6[v7->m_nPhongExponent]->m_VecVal.x;
    v14 = v7->m_nPhongTint == -1;
    vEyePos_SpecExponent[3] = x;
    if ( !v14 )
    {
      v34 = v6[v7->m_nPhongTint];
      if ( v34->IsDefined(this: v34) )
        vSpecularTint = v6[v7->m_nPhongTint]->m_VecVal;
    }
    if ( bHasRimLight )
    {
      if ( v7->m_nRimLightPower != -1 )
      {
        v35 = v6[v7->m_nRimLightPower];
        if ( v35->IsDefined(this: v35) )
        {
          vSpecularTint.w = v6[v7->m_nRimLightPower]->m_VecVal.x;
          if ( vSpecularTint.w <= 1.0 )
            vSpecularTint.w = 1.0;
        }
      }
      if ( v7->m_nRimLightBoost != -1 )
      {
        v36 = v6[v7->m_nRimLightBoost];
        if ( v36->IsDefined(this: v36) )
          vRimBoost[3] = v6[v7->m_nRimLightBoost]->m_VecVal.x;
      }
    }
    if ( bHasRimMaskMap )
    {
      m_nRimMask = v7->m_nRimMask;
      memset(vRimMaskControl, 0, sizeof(vRimMaskControl));
      v38 = v6[m_nRimMask]->m_VecVal.x;
      SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
      vRimMaskControl[0] = v38;
      SetPixelShaderConstant(this: pShaderAPI, a2: 13, a3: vRimMaskControl, a4: 1, a5: false);
    }
    if ( vSpecularTint.x == 0.0 && vSpecularTint.y == 0.0 && vSpecularTint.z == 0.0 )
    {
      if ( hasPhongTintMap )
      {
        v40 = -1.0;
      }
      else
      {
        v40 = 1.0;
        vSpecularTint.y = 1.0;
        vSpecularTint.z = 1.0;
      }
      vSpecularTint.x = v40;
    }
    if ( v7->m_nPhongFresnelRanges != -1 )
    {
      v41 = v6[v7->m_nPhongFresnelRanges];
      if ( v41->IsDefined(this: v41) )
      {
        v42 = (float *)v6[v7->m_nPhongFresnelRanges];
        vFresnelRanges_SpecBoost[0] = v42[3];
        vFresnelRanges_SpecBoost[1] = v42[4];
        vFresnelRanges_SpecBoost[2] = v42[5];
      }
    }
    if ( v7->m_nPhongBoost == -1 || (v43 = v6[v7->m_nPhongBoost], !v43->IsDefined(this: v43)) )
      v44 = 1.0;
    else
      v44 = v6[v7->m_nPhongBoost]->m_VecVal.x;
    v45 = pShaderAPI->SetPixelShaderConstant;
    vFresnelRanges_SpecBoost[3] = v44;
    v45(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 19, a3: vFresnelRanges_SpecBoost, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 26, a3: (const float *)&vSpecularTint, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 14, a3: vRimBoost, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&matView);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_PROJECTION, a3: (float *)&matProj);
    v46 = VMatrix::operator*(this: &matView, &result, vm: &matProj);
    VMatrix::operator=(this: &matViewProj, mOther: v46);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: (const float *)&matViewProj, a4: 2, a5: false);
    m_nCloakFactor = v7->m_nCloakFactor;
    vCloakControls[0] = v6[v7->m_nRefractAmount]->m_VecVal.x;
    v48 = v6[m_nCloakFactor]->m_VecVal.x;
    v49 = pShaderAPI->SetPixelShaderConstant;
    vCloakControls[1] = v48;
    vCloakControls[2] = 0.0;
    vCloakControls[3] = 0.0;
    v49(this: pShaderAPI, a2: 3, a3: vCloakControls, a4: 1, a5: false);
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
