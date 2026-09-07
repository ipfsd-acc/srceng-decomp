// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/portal_refract_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10026E40
// Name: void InitParamsPortalRefract(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct PortalRefractVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsPortalRefract(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        PortalRefractVars_t *info)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx

  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x800);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
  if ( info->m_nStage != -1 )
  {
    if ( !params[info->m_nStage]->IsDefined(this: params[info->m_nStage]) )
      params[info->m_nStage]->SetIntValue(this: params[info->m_nStage], a2: 0);
    if ( info->m_nStage != -1 && params[info->m_nStage]->m_intVal == 0 )
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x4000);
  }
  if ( info->m_nPortalOpenAmount != -1 )
  {
    v5 = params[info->m_nPortalOpenAmount];
    if ( !v5->IsDefined(this: v5) )
      ((void (__stdcall *)(_DWORD))params[info->m_nPortalOpenAmount]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nPortalStatic != -1 )
  {
    v6 = params[info->m_nPortalStatic];
    if ( !v6->IsDefined(this: v6) )
      ((void (__stdcall *)(_DWORD))params[info->m_nPortalStatic]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nTime != -1 )
  {
    v7 = params[info->m_nTime];
    if ( !v7->IsDefined(this: v7) )
      ((void (__stdcall *)(_DWORD))params[info->m_nTime]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nUseOnStaticProp != -1 )
  {
    v8 = params[info->m_nUseOnStaticProp];
    if ( !v8->IsDefined(this: v8) )
    {
      v9 = params[info->m_nUseOnStaticProp];
      v9->SetIntValue(this: v9, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026F80
// Name: void InitPortalRefract(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct PortalRefractVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPortalRefract(CBaseVSShader *pShader, IMaterialVar **params, PortalRefractVars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx

  if ( info->m_nStage >= 0
    && params[info->m_nStage]->IsDefined(this: params[info->m_nStage])
    && params[info->m_nStage]->m_intVal == 2 )
  {
    if ( info->m_nPortalMaskTexture != -1 )
    {
      v3 = params[info->m_nPortalMaskTexture];
      if ( v3->IsDefined(this: v3) )
        CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nPortalMaskTexture, nAdditionalCreationFlags: 0);
    }
    if ( info->m_nPortalColorTexture != -1 )
    {
      v4 = params[info->m_nPortalColorTexture];
      if ( v4->IsDefined(this: v4) )
        CBaseShader::LoadTexture(
          this: pShader,
          nTextureVar: info->m_nPortalColorTexture,
          nAdditionalCreationFlags: 0x80000);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027000
// Name: void DrawPortalRefract(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct PortalRefractVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawPortalRefract(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        PortalRefractVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  PortalRefractVars_t *v6; // ebx
  IMaterialVar **v7; // edi
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx
  bool v10; // al
  IShaderShadow *v11; // esi
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  BOOL v13; // edi
  int v14; // edi
  int v15; // edi
  IShaderDynamicAPI *v16; // esi
  IMaterialVar *v17; // ecx
  bool v18; // sf
  IMaterialVar *v19; // ecx
  __m128 x_low; // xmm0
  __m128d v21; // xmm0
  __m128 v22; // xmm2
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  int v29; // eax
  BOOL v30; // edi
  const VMatrix *v31; // eax
  float x; // xmm0_4
  IMaterialVar *v33; // ecx
  IMaterialVar *v34; // ecx
  IMaterialVar *v35; // ecx
  float v36; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *GetWorldSpaceCameraPosition)(IShaderDynamicAPI *, float *); // edx
  IMaterialVar *v39; // ecx
  const float *p_x; // eax
  IMaterialVar *v41; // ecx
  const float *v42; // eax
  void (__thiscall *v43)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v44; // ebx
  bool v45; // cc
  void (__thiscall *v46)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  VMatrix result; // [esp+80h] [ebp-160h] BYREF
  VMatrix mProj; // [esp+C0h] [ebp-120h] BYREF
  VMatrix mView; // [esp+100h] [ebp-E0h] BYREF
  VMatrix mViewProj; // [esp+140h] [ebp-A0h] BYREF
  float vViewportMad[4]; // [esp+180h] [ebp-60h] BYREF
  float vEyePos[4]; // [esp+190h] [ebp-50h] BYREF
  float vPackedVsConst1[4]; // [esp+1A0h] [ebp-40h] BYREF
  int nRtHeight; // [esp+1B0h] [ebp-30h] BYREF
  int nViewportX; // [esp+1B4h] [ebp-2Ch] BYREF
  portal_refract_ps20b_Dynamic_Index _pshIndex; // [esp+1B8h] [ebp-28h]
  int nViewportHeight; // [esp+1C0h] [ebp-20h] BYREF
  int nViewportY; // [esp+1C4h] [ebp-1Ch] BYREF
  float vPackedConst4[4]; // [esp+1C8h] [ebp-18h] BYREF
  int nTinted; // [esp+1D8h] [ebp-8h]
  int nStage; // [esp+1DCh] [ebp-4h]

  v6 = info;
  v7 = params;
  if ( info->m_nStage < 0 || !params[info->m_nStage]->IsDefined(this: params[info->m_nStage]) )
  {
    nStage = 0;
LABEL_8:
    nTinted = 0;
    goto LABEL_9;
  }
  nStage = params[v6->m_nStage]->m_intVal;
  if ( nStage != 2 )
    goto LABEL_8;
  if ( v6->m_nPortalColorTexture >= 0 )
  {
    v8 = params[v6->m_nPortalColorTexture];
    if ( v8->IsDefined(this: v8) )
      goto LABEL_8;
  }
  nTinted = 1;
LABEL_9:
  if ( v6->m_nUseOnStaticProp >= 0 && (v9 = params[v6->m_nUseOnStaticProp], v9->IsDefined(this: v9)) )
  {
    v10 = params[v6->m_nUseOnStaticProp]->m_intVal != 0;
    HIBYTE(info) = v10;
    if ( v10 )
      nStage = 2;
  }
  else
  {
    HIBYTE(info) = 0;
    v10 = false;
  }
  v11 = pShaderShadow;
  if ( pShaderShadow != nullptr )
  {
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    if ( v10 )
      ((void (__stdcall *)(int, int, _DWORD, _DWORD))VertexShaderVertexFormat)(a1: 1025, a2: 1, a3: 0, a4: 0);
    else
      ((void (__stdcall *)(int, int, _DWORD, int))VertexShaderVertexFormat)(a1: 3, a2: 2, a3: 0, a4: 4);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "STAGE", nStage, "nStage");
    v13 = HIBYTE(info) != 0;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "USEONSTATICPROP", HIBYTE(info), "bUseOnStaticProp");
    v11->SetVertexShader(this: v11, a2: "portal_refract_vs20", a3: 2 * (v13 + nStage + 2 * v13));
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      v15 = -((*params)->m_intVal < 0);
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "STAGE", nStage, "nStage");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "TINTED", nTinted, "nTinted");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSRGBRead ? 1 : 0");
        }
      }
      v11->SetPixelShader(
        this: v11,
        a2: "portal_refract_ps20b",
        a3: 4 * (nTinted + 4 * v15 + 4 + nStage + 2 * (nTinted + 4 * v15 + 4)));
      v14 = nStage;
    }
    else
    {
      v14 = nStage;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "STAGE", nStage, "nStage");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "TINTED", nTinted, "nTinted");
      }
      v11->SetPixelShader(this: v11, a2: "portal_refract_ps20", a3: 2 * (nTinted + nStage + 2 * nTinted));
    }
    v11->EnableTexture(this: v11, a2: SHADER_SAMPLER0, a3: true);
    v11->EnableSRGBRead(this: v11, a2: SHADER_SAMPLER0, a3: true);
    v11->EnableTexture(this: v11, a2: SHADER_SAMPLER1, a3: true);
    v11->EnableSRGBRead(this: v11, a2: SHADER_SAMPLER1, a3: false);
    v11->EnableTexture(this: v11, a2: SHADER_SAMPLER2, a3: true);
    v11->EnableSRGBRead(this: v11, a2: SHADER_SAMPLER2, a3: true);
    v11->EnableSRGBWrite(this: v11, a2: true);
    v11->EnableTexture(this: v11, a2: SHADER_SAMPLER3, a3: true);
    v11->EnableSRGBRead(this: v11, a2: SHADER_SAMPLER3, a3: false);
    v11->EnableAlphaTest(this: v11, a2: true);
    ((void (__thiscall *)(IShaderShadow *, int, int))v11->AlphaFunc)(a1: v11, a2: 4, a3: 1056964608);
    if ( v14 == 2 )
    {
      CBaseShader::EnableAlphaBlending(
        this: pShader,
        src: SHADER_BLEND_SRC_ALPHA,
        dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
      ((void (__thiscall *)(IShaderShadow *, int, int))v11->AlphaFunc)(a1: v11, a2: 4, a3: 998277249);
      v11->EnableDepthWrites(this: v11, a2: false);
    }
    else
    {
      v11->EnableDepthWrites(this: v11, a2: v14 == 1);
    }
    v11->EnableAlphaWrites(this: v11, a2: false);
    v11->EnablePolyOffset(this: v11, a2: SHADER_POLYOFFSET_DECAL);
    if ( v14 == 2 )
      CBaseShader::DefaultFog(this: pShader);
    v7 = params;
  }
  v16 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    v16->SetVertexShaderIndex(this: v16, a2: vertexCompression);
    if ( v6->m_nTextureTransform >= 0 )
    {
      v17 = v7[v6->m_nTextureTransform];
      if ( v17->IsDefined(this: v17) )
        CBaseVSShader::SetVertexShaderTextureTransform(
          this: pShader,
          vertexReg: 49,
          transformVar: v6->m_nTextureTransform);
    }
    v18 = v6->m_nTime < 0;
    memset(vPackedVsConst1, 0, sizeof(vPackedVsConst1));
    if ( v18
      || (v19 = v7[v6->m_nTime], !v19->IsDefined(this: v19))
      || (x_low = (__m128)LODWORD(v7[v6->m_nTime]->m_VecVal.x), x_low.m128_f32[0] <= 0.0) )
    {
      *(double *)&_pshIndex = v16->CurrentTime(this: v16);
      v21 = (__m128d)*(unsigned __int64 *)&_pshIndex;
    }
    else
    {
      v21 = _mm_cvtps_pd(x_low);
    }
    v22.m128_i32[0] = 1258291200;
    SetVertexShaderConstant = v16->SetVertexShaderConstant;
    v24 = _mm_cvtpd_ps(v21);
    v25 = v24;
    v25.m128_f32[0] = v24.m128_f32[0] * 0.001;
    v26 = _mm_and_ps((__m128)0x80000000, v25);
    v22.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v25, v26), v22).m128_f32[0]) & 0x4B000000
                    | v26.m128_i32[0];
    v27 = v25;
    v27.m128_f32[0] = (float)((float)(v24.m128_f32[0] * 0.001) + v22.m128_f32[0]) - v22.m128_f32[0];
    v28 = v27;
    v28.m128_f32[0] = v27.m128_f32[0] - (float)(v24.m128_f32[0] * 0.001);
    vPackedVsConst1[0] = v24.m128_f32[0]
                       - (float)((float)(v27.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v28, v26).m128_u32[0] & 0x3F800000))
                               * 1000.0);
    SetVertexShaderConstant(this: v16, a2: 48, a3: vPackedVsConst1, a4: 1, a5: false);
    HIBYTE(info) = v16->IsStereoActiveThisFrame(this: v16);
    if ( HIBYTE(info) != 0 )
      v16->BindStandardTexture(this: v16, a2: SHADER_SAMPLER3, a3: TEXTURE_BINDFLAGS_NONE, a4: TEXTURE_STEREO_PARAM_MAP);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      v30 = v16->GetSceneFogMode(this: v16) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      _pshIndex.m_nD_NVIDIA_STEREO = HIBYTE(info) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "D_NVIDIA_STEREO", HIBYTE(info), "bNvidiaStereoActiveThisFrame");
      v16->SetPixelShaderIndex(this: v16, a2: _pshIndex.m_nD_NVIDIA_STEREO + 2 * v30);
      v7 = params;
    }
    else
    {
      v29 = v16->GetSceneFogMode(this: v16);
      v16->SetPixelShaderIndex(this: v16, a2: v29 == 2);
    }
    if ( nStage != 0 )
    {
      if ( nStage == 2 )
      {
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER1,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: v6->m_nPortalMaskTexture,
          nFrameVar: -1);
        if ( nTinted == 0 )
          CBaseShader::BindTexture(
            this: pShader,
            sampler1: SHADER_SAMPLER2,
            nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
            nTextureVar: v6->m_nPortalColorTexture,
            nFrameVar: -1);
      }
    }
    else
    {
      v16->BindStandardTexture(
        this: v16,
        a2: SHADER_SAMPLER0,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    }
    v16->SetPixelShaderFogParams(this: v16, a2: 6);
    v16->GetMatrix(this: v16, a2: MATERIAL_VIEW, a3: (float *)&mView);
    v16->GetMatrix(this: v16, a2: MATERIAL_PROJECTION, a3: (float *)&mProj);
    VMatrix::operator*(this: &mView, result: &mViewProj, vm: &mProj);
    v31 = VMatrix::Transpose(this: &mViewProj, &result);
    VMatrix::operator=(this: &mViewProj, mOther: v31);
    v16->SetPixelShaderConstant(this: v16, a2: 0, a3: (const float *)&mViewProj, a4: 4, a5: false);
    v18 = v6->m_nPortalOpenAmount < 0;
    x = 0.0;
    memset(vPackedConst4, 0, sizeof(vPackedConst4));
    if ( !v18 )
    {
      v33 = v7[v6->m_nPortalOpenAmount];
      if ( v33->IsDefined(this: v33) )
      {
        vPackedConst4[0] = v7[v6->m_nPortalOpenAmount]->m_VecVal.x;
        x = 0.0;
LABEL_66:
        if ( v6->m_nPortalStatic >= 0 )
        {
          v34 = v7[v6->m_nPortalStatic];
          if ( v34->IsDefined(this: v34) )
            x = v7[v6->m_nPortalStatic]->m_VecVal.x;
          else
            x = 0.0;
        }
        v18 = v6->m_nPortalColorScale < 0;
        vPackedConst4[1] = 1.0 - x;
        if ( v18 || (v35 = v7[v6->m_nPortalColorScale], !v35->IsDefined(this: v35)) )
          v36 = 1.0;
        else
          v36 = v7[v6->m_nPortalColorScale]->m_VecVal.x;
        SetPixelShaderConstant = v16->SetPixelShaderConstant;
        vPackedConst4[2] = v36;
        SetPixelShaderConstant(this: v16, a2: 4, a3: vPackedConst4, a4: 1, a5: false);
        v16->SetVertexShaderConstant(this: v16, a2: 51, a3: vPackedConst4, a4: 1, a5: false);
        GetWorldSpaceCameraPosition = v16->GetWorldSpaceCameraPosition;
        memset(vEyePos, 0, sizeof(vEyePos));
        GetWorldSpaceCameraPosition(this: v16, a2: vEyePos);
        v16->SetPixelShaderConstant(this: v16, a2: 5, a3: vEyePos, a4: 1, a5: false);
        if ( nTinted != 0 )
        {
          if ( v6->m_nPortalColorGradientDark >= 0
            && (v39 = v7[v6->m_nPortalColorGradientDark], v39->IsDefined(this: v39)) )
          {
            p_x = &v7[v6->m_nPortalColorGradientDark]->m_VecVal.x;
          }
          else
          {
            p_x = kDefaultPortalColorGradientDark;
          }
          v16->SetPixelShaderConstant(this: v16, a2: 7, a3: p_x, a4: 1, a5: false);
          if ( v6->m_nPortalColorGradientLight >= 0
            && (v41 = v7[v6->m_nPortalColorGradientLight], v41->IsDefined(this: v41)) )
          {
            v42 = &v7[v6->m_nPortalColorGradientLight]->m_VecVal.x;
          }
          else
          {
            v42 = kDefaultPortalColorGradientLight;
          }
          v16->SetPixelShaderConstant(this: v16, a2: 8, a3: v42, a4: 1, a5: false);
        }
        v16->GetCurrentViewport(
          this: v16,
          a2: &nViewportX,
          a3: &nViewportY,
          a4: (int *)&pShaderAPI,
          a5: &nViewportHeight);
        v16->GetCurrentRenderTargetDimensions(this: v16, a2: (int *)&pShaderShadow, a3: &nRtHeight);
        v43 = v16->SetPixelShaderConstant;
        vViewportMad[0] = (float)(int)pShaderAPI / (float)(int)pShaderShadow;
        vViewportMad[1] = (float)nViewportHeight / (float)nRtHeight;
        vViewportMad[2] = (float)nViewportX / (float)(int)pShaderShadow;
        vViewportMad[3] = (float)nViewportY / (float)nRtHeight;
        v43(this: v16, a2: 9, a3: vViewportMad, a4: 1, a5: false);
        v44 = v16->GetIntRenderingParameter(this: v16, a2: 12);
        if ( g_pHardwareConfig->UseFastClipping(this: g_pHardwareConfig) )
          v45 = v44 <= 0;
        else
          v45 = v44 <= 1;
        if ( v45 )
          vPackedConst4[0] = 0.0;
        else
          vPackedConst4[0] = 1.0;
        v46 = v16->SetVertexShaderConstant;
        memset(&vPackedConst4[1], 0, 12);
        v46(this: v16, a2: 52, a3: vPackedConst4, a4: 1, a5: false);
        goto LABEL_91;
      }
      x = 0.0;
    }
    vPackedConst4[0] = 0.0;
    goto LABEL_66;
  }
LABEL_91:
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
