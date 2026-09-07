// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/emissive_scroll_blended_pass_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000CFE0
// Name: void InitParamsEmissiveScrollBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct EmissiveScrollBlendedPassVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsEmissiveScrollBlendedPass(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        EmissiveScrollBlendedPassVars_t *info)
{
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  if ( info->m_nEmissiveScrollVector != -1 )
  {
    v4 = params[info->m_nEmissiveScrollVector];
    if ( !v4->IsDefined(this: v4) )
    {
      v5 = params[info->m_nEmissiveScrollVector];
      v5->SetVecValue_4(this: v5, a2: kDefaultEmissiveScrollVector, a3: 4);
    }
  }
  if ( info->m_nBlendStrength != -1 && !params[info->m_nBlendStrength]->IsDefined(this: params[info->m_nBlendStrength]) )
    ((void (__stdcall *)(_DWORD))params[info->m_nBlendStrength]->SetFloatValue)(a1: 0);
  if ( info->m_nEmissiveTint != -1 )
  {
    v6 = params[info->m_nEmissiveTint];
    if ( !v6->IsDefined(this: v6) )
    {
      v7 = params[info->m_nEmissiveTint];
      v7->SetVecValue_4(this: v7, a2: kDefaultEmissiveTint, a3: 4);
    }
  }
  if ( info->m_nTime != -1 )
  {
    v8 = params[info->m_nTime];
    if ( !v8->IsDefined(this: v8) )
      ((void (__stdcall *)(_DWORD))params[info->m_nTime]->SetFloatValue)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D0B0
// Name: void InitEmissiveScrollBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct EmissiveScrollBlendedPassVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitEmissiveScrollBlendedPass(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        EmissiveScrollBlendedPassVars_t *info)
{
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFlowTexture, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nEmissiveTexture, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x1000D0F0
// Name: void DrawEmissiveScrollBlendedPass(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct EmissiveScrollBlendedPassVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawEmissiveScrollBlendedPass(
        int a1@<ebx>,
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        EmissiveScrollBlendedPassVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  CBaseVSShader *v7; // edi
  bool v8; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  BOOL v10; // edi
  int v11; // eax
  BOOL v12; // edi
  BOOL v13; // ebx
  int v14; // eax
  int m_nBlendStrength; // eax
  float v16; // xmm1_4
  IMaterialVar *v17; // ecx
  float x; // xmm0_4
  double v19; // xmm0_8
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v21; // xmm0_4
  IMaterialVar *v22; // ecx
  Vector4D *p_m_VecVal; // eax
  IMaterialVar *v24; // ecx
  Vector4D *v25; // eax
  const char *v26; // [esp-4h] [ebp-24h]
  const char *v27; // [esp-4h] [ebp-24h]
  int v28; // [esp+0h] [ebp-20h]
  float vPsConst0[4]; // [esp+8h] [ebp-18h] BYREF
  long double v30; // [esp+18h] [ebp-8h]

  v7 = pShader;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this: pShader);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int, int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000, a2: v28);
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "emissive_scroll_blended_pass_vs30", a3: 0);
      v28 = 0;
      ((void (__stdcall *)(const char *))pShaderShadow->SetPixelShader)(a1: "emissive_scroll_blended_pass_ps30");
    }
    else
    {
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "emissive_scroll_blended_pass_vs20", a3: 0);
      v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      SetPixelShader = pShaderShadow->SetPixelShader;
      v28 = 0;
      if ( v8 )
        ((void (__stdcall *)(const char *))SetPixelShader)(a1: "emissive_scroll_blended_pass_ps20");
      else
        ((void (__stdcall *)(const char *))SetPixelShader)(a1: "emissive_scroll_blended_pass_ps20b");
    }
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
  }
  if ( pShaderAPI != nullptr )
  {
    ((void (__thiscall *)(IShaderDynamicAPI *, int))pShaderAPI->SetDefaultState)(a1: pShaderAPI, a2: a1);
    if ( ((unsigned __int8 (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->HasFastVertexTextures)(
           a1: g_pHardwareConfig,
           a2: v28) != 0 )
    {
      CBaseVSShader::SetHWMorphVertexShaderState(
        this: pShader,
        nDimConst: 54,
        nSubrectConst: 55,
        morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      v12 = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
      v13 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v14 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v14 > 0, v27);
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * (v13 + 2 * v12));
    }
    else
    {
      v10 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v11 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v11 > 0, v26);
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * v10);
      g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nBaseTexture,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nFlowTexture,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nEmissiveTexture,
      nFrameVar: -1);
    m_nBlendStrength = info->m_nBlendStrength;
    memset(vPsConst0, 0, sizeof(vPsConst0));
    if ( m_nBlendStrength >= 0 && params[m_nBlendStrength]->IsDefined(this: params[m_nBlendStrength]) )
    {
      v16 = 0.0;
      vPsConst0[0] = params[info->m_nBlendStrength]->m_VecVal.x;
      if ( vPsConst0[0] < 0.0 || (v16 = 1.0, vPsConst0[0] > 1.0) )
        vPsConst0[0] = v16;
    }
    else
    {
      vPsConst0[0] = 0.0;
    }
    if ( info->m_nTime >= 0
      && (v17 = params[info->m_nTime], v17->IsDefined(this: v17))
      && (x = params[info->m_nTime]->m_VecVal.x) > 0.0 )
    {
      v19 = x;
    }
    else
    {
      v30 = pShaderAPI->CurrentTime(this: pShaderAPI);
      v19 = v30;
    }
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    v21 = v19;
    vPsConst0[1] = v21 - (float)((float)(int)(float)(v21 * 0.001) * 1000.0);
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: vPsConst0, a4: 1, a5: false);
    if ( info->m_nEmissiveScrollVector >= 0 && (v22 = params[info->m_nEmissiveScrollVector], v22->IsDefined(this: v22)) )
      p_m_VecVal = &params[info->m_nEmissiveScrollVector]->m_VecVal;
    else
      p_m_VecVal = (Vector4D *)kDefaultEmissiveScrollVector;
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 1, a3: (const float *)p_m_VecVal, a4: 1, a5: false);
    if ( info->m_nEmissiveTint >= 0 && (v24 = params[info->m_nEmissiveTint], v24->IsDefined(this: v24)) )
      v25 = &params[info->m_nEmissiveTint]->m_VecVal;
    else
      v25 = (Vector4D *)kDefaultEmissiveTint;
    ((void (__thiscall *)(IShaderDynamicAPI *, int, Vector4D *, int))pShaderAPI->SetPixelShaderConstant)(
      a1: pShaderAPI,
      a2: 2,
      a3: v25,
      a4: 1);
    v7 = pShader;
  }
  CBaseShader::Draw(this: v7, bMakeActualDrawCall: true);
}
