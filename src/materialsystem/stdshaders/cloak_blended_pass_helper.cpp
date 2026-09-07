// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/cloak_blended_pass_helper.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10008B30
// Name: void InitParamsCloakBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct CloakBlendedPassVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsCloakBlendedPass(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        CloakBlendedPassVars_t *info)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x800);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  if ( info->m_nCloakFactor != -1 && !params[info->m_nCloakFactor]->IsDefined(this: params[info->m_nCloakFactor]) )
    ((void (__stdcall *)(_DWORD))params[info->m_nCloakFactor]->SetFloatValue)(a1: 0);
  if ( info->m_nRefractAmount != -1 )
  {
    v5 = params[info->m_nRefractAmount];
    if ( !v5->IsDefined(this: v5) )
      ((void (__stdcall *)(int))params[info->m_nRefractAmount]->SetFloatValue)(a1: 1036831949);
  }
  if ( info->m_nCloakColorTint != -1 )
  {
    v6 = params[info->m_nCloakColorTint];
    if ( !v6->IsDefined(this: v6) )
    {
      v7 = params[info->m_nCloakColorTint];
      ((void (__thiscall *)(IMaterialVar *, int, int, int, int))v7->SetVecValue)(
        a1: v7,
        a2: 1065353216,
        a3: 1065353216,
        a4: 1065353216,
        a5: 1065353216);
    }
  }
  if ( info->m_nBumpFrame != -1 )
  {
    v8 = params[info->m_nBumpFrame];
    if ( !v8->IsDefined(this: v8) )
    {
      v9 = params[info->m_nBumpFrame];
      v9->SetIntValue(this: v9, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008C40
// Name: void InitCloakBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct CloakBlendedPassVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCloakBlendedPass(CBaseVSShader *pShader, IMaterialVar **params, CloakBlendedPassVars_t *info)
{
  IMaterialVar *v3; // ecx

  if ( (g_pConfig->m_Flags & 0x100) == 0 && info->m_nBumpmap != -1 )
  {
    v3 = params[info->m_nBumpmap];
    if ( v3->IsDefined(this: v3) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBumpmap, nAdditionalCreationFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008C90
// Name: void DrawCloakBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct CloakBlendedPassVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawCloakBlendedPass(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        CloakBlendedPassVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  int m_nBumpmap; // eax
  char v7; // bl
  CBaseVSShader *v8; // edi
  BOOL v9; // edi
  int v10; // eax
  BOOL v11; // edi
  BOOL v12; // ebx
  int v13; // eax
  void (__thiscall *GetWorldSpaceCameraPosition)(IShaderDynamicAPI *, float *); // edx
  float x; // xmm0_4
  int m_nCloakFactor; // eax
  bool v17; // sf
  IMaterialVar *v18; // ecx
  float v19; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v21; // ecx
  Vector4D *p_m_VecVal; // eax
  const VMatrix *v23; // eax
  const char *v24; // [esp-4h] [ebp-134h]
  const char *v25; // [esp-4h] [ebp-134h]
  VMatrix result; // [esp+Ch] [ebp-124h] BYREF
  VMatrix mProj; // [esp+4Ch] [ebp-E4h] BYREF
  VMatrix mView; // [esp+8Ch] [ebp-A4h] BYREF
  VMatrix mViewProj; // [esp+CCh] [ebp-64h] BYREF
  float vEyePos[4]; // [esp+10Ch] [ebp-24h] BYREF
  float vPackedConst1[4]; // [esp+11Ch] [ebp-14h] BYREF
  bool bBumpMapping; // [esp+12Fh] [ebp-1h]

  if ( (g_pConfig->m_Flags & 0x100) != 0
    || (m_nBumpmap = info->m_nBumpmap) == -1
    || (*((_BYTE *)params[m_nBumpmap] + 28) & 0xF) != 3 )
  {
    bBumpMapping = false;
    v7 = 0;
  }
  else
  {
    v7 = 1;
    bBumpMapping = true;
  }
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this: pShader);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMAP", v7 != 0, "bBumpMapping ? 1 : 0");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "cloak_blended_pass_vs30", a3: 8 * (v7 != 0));
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", v7 != 0, "bBumpMapping ? 1 : 0");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "cloak_blended_pass_ps30", a3: v7 != 0);
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMAP", v7 != 0, "bBumpMapping ? 1 : 0");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "cloak_blended_pass_vs20", a3: 4 * (v7 != 0));
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", v7 != 0, "bBumpMapping ? 1 : 0");
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "cloak_blended_pass_ps20", a3: v7 != 0);
      }
      else
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", v7 != 0, "bBumpMapping ? 1 : 0");
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "cloak_blended_pass_ps20b", a3: v7 != 0);
      }
    }
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    if ( v7 != 0 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    v8 = pShader;
    CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: true);
  }
  else
  {
    v8 = pShader;
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetDefaultState(this: pShaderAPI);
    if ( v7 != 0 && info->m_nBumpTransform != -1 )
      CBaseVSShader::SetVertexShaderTextureTransform(this: v8, vertexReg: 48, transformVar: info->m_nBumpTransform);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      CBaseVSShader::SetHWMorphVertexShaderState(
        this: v8,
        nDimConst: 54,
        nSubrectConst: 55,
        morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      v11 = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
      v12 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v13 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v13 > 0, v25);
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * (v12 + 2 * v11));
    }
    else
    {
      v9 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v10 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v10 > 0, v24);
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * v9);
      g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER0,
      a3: TEXTURE_BINDFLAGS_SRGBREAD,
      a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    if ( bBumpMapping )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: info->m_nBumpmap,
        nFrameVar: info->m_nBumpFrame);
    GetWorldSpaceCameraPosition = pShaderAPI->GetWorldSpaceCameraPosition;
    memset(vEyePos, 0, sizeof(vEyePos));
    GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 5, a3: vEyePos, a4: 1, a5: false);
    x = 0.0;
    m_nCloakFactor = info->m_nCloakFactor;
    memset(vPackedConst1, 0, sizeof(vPackedConst1));
    if ( m_nCloakFactor >= 0 )
    {
      if ( params[m_nCloakFactor]->IsDefined(this: params[m_nCloakFactor]) )
        x = params[info->m_nCloakFactor]->m_VecVal.x;
      else
        x = 0.0;
    }
    v17 = info->m_nRefractAmount < 0;
    vPackedConst1[0] = x;
    if ( v17 || (v18 = params[info->m_nRefractAmount], !v18->IsDefined(this: v18)) )
      v19 = 0.1;
    else
      v19 = params[info->m_nRefractAmount]->m_VecVal.x;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vPackedConst1[1] = v19;
    SetPixelShaderConstant(this: pShaderAPI, a2: 6, a3: vPackedConst1, a4: 1, a5: false);
    if ( info->m_nCloakColorTint >= 0 && (v21 = params[info->m_nCloakColorTint], v21->IsDefined(this: v21)) )
      p_m_VecVal = &params[info->m_nCloakColorTint]->m_VecVal;
    else
      p_m_VecVal = (Vector4D *)kDefaultCloakColorTint;
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 7, a3: (const float *)p_m_VecVal, a4: 1, a5: false);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&mView);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_PROJECTION, a3: (float *)&mProj);
    VMatrix::operator*(this: &mView, result: &mViewProj, vm: &mProj);
    v23 = VMatrix::Transpose3x3(this: &mViewProj, &result);
    VMatrix::operator=(this: &mViewProj, mOther: v23);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: (const float *)&mViewProj, a4: 2, a5: false);
    v8 = pShader;
  }
  CBaseShader::Draw(this: v8, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100091C0
// Name: bool CloakBlendedPassIsFullyOpaque(class IMaterialVar __near * __near *,struct CloakBlendedPassVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CloakBlendedPassIsFullyOpaque(IMaterialVar **params, CloakBlendedPassVars_t *info)
{
  float x; // xmm1_4
  float v3; // xmm0_4

  if ( info->m_nCloakFactor >= 0 && params[info->m_nCloakFactor]->IsDefined(this: params[info->m_nCloakFactor]) )
  {
    x = params[info->m_nCloakFactor]->m_VecVal.x;
    if ( x >= 0.0 )
    {
      if ( x > 1.0 )
        x = 1.0;
    }
    else
    {
      x = 0.0;
    }
  }
  else
  {
    x = 0.0;
  }
  v3 = 1.0 - (float)(x * 1.35);
  return v3 < 0.0 || v3 <= 1.0 && v3 <= 0.40000001;
}
