// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/multiblend_dx9_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001F700
// Name: void InitParamsMultiblend_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct Multiblend_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsMultiblend_DX9(CBaseVSShader *pShader, IMaterialVar **params)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 4);
}

//------------------------------------------------------------------------------
// Address: 0x1001F720
// Name: void InitMultiblend_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct Multiblend_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMultiblend_DX9(CBaseVSShader *pShader, IMaterialVar **params, Multiblend_DX9_Vars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx
  IMaterialVar *v10; // ecx

  v3 = params[info->m_nBaseTexture];
  if ( v3->IsDefined(this: v3) )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0);
  if ( info->m_nSpecTexture != -1 )
  {
    v4 = params[info->m_nSpecTexture];
    if ( v4->IsDefined(this: v4) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nSpecTexture, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nBaseTexture2 != -1 )
  {
    v5 = params[info->m_nBaseTexture2];
    if ( v5->IsDefined(this: v5) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture2, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nSpecTexture2 != -1 )
  {
    v6 = params[info->m_nSpecTexture2];
    if ( v6->IsDefined(this: v6) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nSpecTexture2, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nBaseTexture3 != -1 )
  {
    v7 = params[info->m_nBaseTexture3];
    if ( v7->IsDefined(this: v7) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture3, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nSpecTexture3 != -1 )
  {
    v8 = params[info->m_nSpecTexture3];
    if ( v8->IsDefined(this: v8) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nSpecTexture3, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nBaseTexture4 != -1 )
  {
    v9 = params[info->m_nBaseTexture4];
    if ( v9->IsDefined(this: v9) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture4, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nSpecTexture4 != -1 )
  {
    v10 = params[info->m_nSpecTexture4];
    if ( v10->IsDefined(this: v10) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nSpecTexture4, nAdditionalCreationFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F850
// Name: void DrawMultiblend_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct Multiblend_DX9_Vars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawMultiblend_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        Multiblend_DX9_Vars_t *info)
{
  int m_intVal; // eax
  IMaterialVar *v7; // ecx
  bool v8; // al
  IMaterialVar *v9; // ecx
  bool v10; // al
  IMaterialVar *v11; // ecx
  bool v12; // al
  IMaterialVar *v13; // ecx
  bool v14; // al
  BOOL v15; // ecx
  BOOL v16; // eax
  BOOL v17; // ecx
  BOOL v18; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float x; // xmm0_4
  IMaterialVar *v24; // edx
  float v25; // xmm4_4
  IMaterialVar *v26; // edx
  float v27; // xmm3_4
  float v28; // xmm1_4
  void (__thiscall *v29)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  Vector *v30; // eax
  float (__thiscall *GetFloatRenderingParameter)(IShaderDynamicAPI *, int); // edx
  bool v32; // zf
  int (__thiscall *v33)(IShaderDynamicAPI *); // eax
  int v34; // eax
  IShaderDynamicAPI *v35; // ecx
  bool (__thiscall *IsHWMorphingEnabled)(IShaderDynamicAPI *); // eax
  BOOL v37; // ecx
  int (__thiscall *GetCurrentNumBones)(IShaderDynamicAPI *); // eax
  int v39; // eax
  MaterialFogMode_t v40; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const VMatrix *v42; // eax
  const char *scale; // [esp+BCh] [ebp-16Ch]
  const char *scalea; // [esp+BCh] [ebp-16Ch]
  VMatrix result; // [esp+CCh] [ebp-15Ch] BYREF
  VMatrix matView; // [esp+10Ch] [ebp-11Ch] BYREF
  VMatrix matViewProj; // [esp+14Ch] [ebp-DCh] BYREF
  VMatrix matProj; // [esp+18Ch] [ebp-9Ch] BYREF
  float vEyePos_SpecExponent[4]; // [esp+1CCh] [ebp-5Ch] BYREF
  Vector4D vScales; // [esp+1DCh] [ebp-4Ch] BYREF
  Vector4D vLightDir; // [esp+1ECh] [ebp-3Ch] BYREF
  Vector4D vRotations; // [esp+1FCh] [ebp-2Ch] BYREF
  _BYTE v53[4]; // [esp+20Ch] [ebp-1Ch] BYREF
  int nLightingPreviewMode; // [esp+210h] [ebp-18h]
  BOOL v55; // [esp+214h] [ebp-14h] BYREF
  BOOL v56; // [esp+218h] [ebp-10h]
  BOOL bSRGBLightMaps; // [esp+21Ch] [ebp-Ch]
  bool bHasSpec1; // [esp+223h] [ebp-5h]
  bool bHasSpec2; // [esp+224h] [ebp-4h]
  bool bHasSpec4; // [esp+225h] [ebp-3h]
  bool bIsModel; // [esp+226h] [ebp-2h]
  bool bHasSpec3; // [esp+227h] [ebp-1h]
  BOOL flLScale; // [esp+240h] [ebp+18h]
  BOOL flLScalea; // [esp+240h] [ebp+18h]
  float flLScaleb; // [esp+240h] [ebp+18h]
  bool flLScale_3; // [esp+243h] [ebp+1Bh]

  m_intVal = params[2]->m_intVal;
  bIsModel = ((*params)->m_intVal & 0x800) != 0;
  nLightingPreviewMode = ((m_intVal & 0x100000) != 0) + 2 * ((m_intVal & 0x200000) != 0);
  if ( info->m_nSpecTexture == -1
    || (v7 = params[info->m_nSpecTexture], v8 = v7->IsDefined(this: v7), bHasSpec1 = true, !v8) )
  {
    bHasSpec1 = false;
  }
  if ( info->m_nSpecTexture2 == -1
    || (v9 = params[info->m_nSpecTexture2], v10 = v9->IsDefined(this: v9), bHasSpec2 = true, !v10) )
  {
    bHasSpec2 = false;
  }
  if ( info->m_nSpecTexture3 == -1
    || (v11 = params[info->m_nSpecTexture3], v12 = v11->IsDefined(this: v11), bHasSpec3 = true, !v12) )
  {
    bHasSpec3 = false;
  }
  if ( info->m_nSpecTexture4 == -1
    || (v13 = params[info->m_nSpecTexture4], v14 = v13->IsDefined(this: v13), bHasSpec4 = true, !v14) )
  {
    bHasSpec4 = false;
  }
  flLScale_3 = CBaseShader::CanUseEditorMaterials(this: pShader);
  LOBYTE(bSRGBLightMaps) = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_NONE;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this: pShader);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER8, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER9, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER8, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER9, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: bSRGBLightMaps);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 3u, a3: 8, a4: s_TexCoordSize, a5: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      v17 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v18 = !flLScale_3;
      LODWORD(vLightDir.y) = v17;
      flLScalea = v18;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SPECULAR", v18, "!bUsingEditor");
      LODWORD(vLightDir.x) = bIsModel;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "MODEL", bIsModel, "bIsModel");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "multiblend_vs30",
        a3: 8 * (LODWORD(vLightDir.x) + 2 * (LODWORD(vLightDir.y) + 2 * flLScalea)));
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "LIGHTING_PREVIEW",
          nLightingPreviewMode,
          "nLightingPreviewMode");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "multiblend_ps30", a3: 2 * nLightingPreviewMode);
    }
    else
    {
      LODWORD(vRotations.y) = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v15 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      v16 = !flLScale_3;
      LODWORD(vRotations.z) = v15;
      flLScale = v16;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SPECULAR", v16, "!bUsingEditor");
      LODWORD(vRotations.x) = bIsModel;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "MODEL", bIsModel, "bIsModel");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "multiblend_vs20",
        a3: 4 * (LODWORD(vRotations.x) + 2 * (LODWORD(vRotations.y) + 2 * (LODWORD(vRotations.z) + 2 * flLScale))));
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "LIGHTING_PREVIEW",
            nLightingPreviewMode,
            "nLightingPreviewMode");
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "multiblend_ps20", a3: 2 * nLightingPreviewMode);
      }
      else
      {
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "LIGHTING_PREVIEW",
            nLightingPreviewMode,
            "nLightingPreviewMode");
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "multiblend_ps20b", a3: 2 * nLightingPreviewMode);
      }
    }
    CBaseShader::DefaultFog(this: pShader);
    flLScaleb = pShaderShadow->GetLightMapScaleFactor(this: pShaderShadow);
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 4);
    CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearScale_ScaleInW(
      this: pShader,
      nRegister: 2,
      scale: flLScaleb);
    CBaseShader::PI_EndCommandBuffer(this: pShader);
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetDefaultState(this: pShaderAPI);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nBaseTexture,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nBaseTexture2,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nBaseTexture3,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER4,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nBaseTexture4,
      nFrameVar: -1);
    if ( bHasSpec1 )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER6,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: info->m_nSpecTexture,
        nFrameVar: -1);
    else
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER6,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_BLACK);
    if ( bHasSpec2 )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER7,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: info->m_nSpecTexture2,
        nFrameVar: -1);
    else
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER7,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_BLACK);
    if ( bHasSpec3 )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER8,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: info->m_nSpecTexture3,
        nFrameVar: -1);
    else
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER8,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_BLACK);
    if ( bHasSpec4 )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER9,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: info->m_nSpecTexture4,
        nFrameVar: -1);
    else
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER9,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_BLACK);
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER5,
      a3: bSRGBLightMaps ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
      a4: TEXTURE_LIGHTMAP);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    v20 = params[info->m_nRotation2]->m_VecVal.x * 0.017453292;
    v21 = params[info->m_nRotation3]->m_VecVal.x * 0.017453292;
    v22 = params[info->m_nRotation4]->m_VecVal.x * 0.017453292;
    vRotations.x = params[info->m_nRotation]->m_VecVal.x * 0.017453292;
    vRotations.y = v20;
    vRotations.z = v21;
    vRotations.w = v22;
    SetVertexShaderConstant(this: pShaderAPI, a2: 27, a3: &vRotations.x, a4: 1, a5: false);
    x = params[info->m_nScale4]->m_VecVal.x;
    if ( x <= 0.0 )
      x = 1.0;
    v24 = params[info->m_nScale3];
    if ( v24->m_VecVal.x <= 0.0 )
      v25 = 1.0;
    else
      v25 = v24->m_VecVal.x;
    v26 = params[info->m_nScale2];
    if ( v26->m_VecVal.x <= 0.0 )
      v27 = 1.0;
    else
      v27 = v26->m_VecVal.x;
    v28 = params[info->m_nScale]->m_VecVal.x;
    if ( v28 <= 0.0 )
      v28 = 1.0;
    v29 = pShaderAPI->SetVertexShaderConstant;
    vScales.x = v28;
    vScales.y = v27;
    vScales.z = v25;
    vScales.w = x;
    v29(this: pShaderAPI, a2: 28, a3: &vScales.x, a4: 1, a5: false);
    v30 = pShaderAPI->GetVectorRenderingParameter(this: pShaderAPI, result: &v55, a3: 0);
    vLightDir.x = v30->x;
    vLightDir.y = v30->y;
    GetFloatRenderingParameter = pShaderAPI->GetFloatRenderingParameter;
    vLightDir.z = v30->z;
    vLightDir.w = GetFloatRenderingParameter(this: pShaderAPI, a2: 1);
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 29, a3: (const float *)&vLightDir, a4: 1, a5: false);
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: (LightState_t *)v53);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      v32 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      IsHWMorphingEnabled = pShaderAPI->IsHWMorphingEnabled;
      v55 = v32;
      v37 = IsHWMorphingEnabled(this: pShaderAPI);
      GetCurrentNumBones = pShaderAPI->GetCurrentNumBones;
      bSRGBLightMaps = v37;
      v56 = GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v39 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v39 > 0, scalea);
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v55 + 2 * (v56 + 2 * bSRGBLightMaps));
      v35 = pShaderAPI;
    }
    else
    {
      v32 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v33 = pShaderAPI->GetCurrentNumBones;
      v56 = v32;
      bSRGBLightMaps = v33(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v34 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v34 > 0, scale);
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v56 + 2 * bSRGBLightMaps);
      g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v35 = pShaderAPI;
    }
    v40 = pShaderAPI->GetSceneFogMode(this: v35);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v40 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    CBaseVSShader::SetVertexShaderTextureTransform(
      this: pShader,
      vertexReg: 54,
      transformVar: info->m_nBaseTextureTransform);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&matView);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_PROJECTION, a3: (float *)&matProj);
    v42 = VMatrix::operator*(this: &matView, &result, vm: &matProj);
    VMatrix::operator=(this: &matViewProj, mOther: v42);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: (const float *)&matViewProj, a4: 2, a5: false);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
