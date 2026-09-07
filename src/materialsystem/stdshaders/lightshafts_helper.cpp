// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/lightshafts_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001C9F0
// Name: void InitParamsLightShafts(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct LightShaftsVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsLightShafts(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        LightShaftsVars_t *info)
{
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx

  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x2000);
  if ( info->m_nCookieFrameNum != -1 )
  {
    v4 = params[info->m_nCookieFrameNum];
    if ( !v4->IsDefined(this: v4) )
    {
      v5 = params[info->m_nCookieFrameNum];
      v5->SetIntValue(this: v5, a2: 0);
    }
  }
  if ( info->m_nTime != -1 )
  {
    v6 = params[info->m_nTime];
    if ( !v6->IsDefined(this: v6) )
      ((void (__stdcall *)(_DWORD))params[info->m_nTime]->SetFloatValue)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CA80
// Name: void InitLightShafts(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct LightShaftsVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitLightShafts(CBaseVSShader *pShader, IMaterialVar **params, LightShaftsVars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx

  if ( info->m_nCookieTexture != -1 )
  {
    v3 = params[info->m_nCookieTexture];
    if ( v3->IsDefined(this: v3) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nCookieTexture, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nShadowDepthTexture != -1
    && params[info->m_nShadowDepthTexture]->IsDefined(this: params[info->m_nShadowDepthTexture]) )
  {
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nShadowDepthTexture, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nNoiseTexture != -1 )
  {
    v4 = params[info->m_nNoiseTexture];
    if ( v4->IsDefined(this: v4) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nNoiseTexture, nAdditionalCreationFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CB00
// Name: void DrawLightShafts(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct LightShaftsVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawLightShafts(
        int a1@<ebx>,
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        float pShaderShadow,
        LightShaftsVars_t *info)
{
  float v6; // esi
  ShadowFilterMode_t v7; // edi
  ShadowFilterMode_t v8; // eax
  IShaderDynamicAPI *v9; // edi
  LightShaftsVars_t *v10; // esi
  IMaterialVar *v11; // ecx
  IMaterialVar *v12; // ecx
  const VMatrix *v13; // eax
  float w; // xmm0_4
  IMaterialVar *v15; // ecx
  IMaterialVar *v16; // eax
  bool v17; // zf
  IMaterialVar *v18; // ecx
  float x; // xmm0_4
  bool (__thiscall *GetHDREnabled)(IMaterialSystemHardwareConfig *); // edx
  bool v21; // al
  float v22; // xmm1_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v24; // ecx
  IMaterialVar *v25; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v28; // xmm3_4
  IMaterialVar *v29; // ecx
  IMaterialVar *v30; // eax
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  IMaterialVar *v34; // ecx
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // ecx
  IMaterialVar *v37; // ecx
  IMaterialVar *v38; // ecx
  IMaterialVar *v39; // ecx
  IMaterialVar *v40; // ecx
  IMaterialVar *v41; // ecx
  IMaterialVar *v42; // ecx
  IMaterialVar *v43; // ecx
  IMaterialVar *v44; // ecx
  ITexture *v45; // eax
  ITexture *v46; // eax
  IMaterialVar *v47; // ecx
  IMaterialVar *v48; // ecx
  ITexture *v49; // eax
  void (__thiscall *v50)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v51)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v52)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  double v53; // st7
  double v54; // st7
  bool v55; // al
  float m_flShadowAtten; // xmm0_4
  IMaterialVar *v57; // ecx
  IMaterialVar *v58; // eax
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  IMaterialVar *v62; // ecx
  IMaterialVar *v63; // eax
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm3_4
  IMaterialVar *v67; // ecx
  void (__thiscall *v68)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const float *p_worldToTexture; // eax
  void (__thiscall *GetBackBufferDimensions)(IShaderDynamicAPI *, int *, int *); // eax
  void (__thiscall *v71)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL m_bEnableShadows; // esi
  BOOL m_bUberlight; // ebx
  matrix3x4_t viewMatrix; // [esp+F0h] [ebp-2D4h] BYREF
  matrix3x4_t out; // [esp+120h] [ebp-2A4h] BYREF
  matrix3x4_t matrix; // [esp+150h] [ebp-274h] BYREF
  VMatrix worldToTexture; // [esp+180h] [ebp-244h] BYREF
  matrix3x4_t identityMatrix; // [esp+1C0h] [ebp-204h] BYREF
  QAngle v79; // [esp+1F0h] [ebp-1D4h] BYREF
  float v80[4]; // [esp+1FCh] [ebp-1C8h] BYREF
  float v81[4]; // [esp+20Ch] [ebp-1B8h] BYREF
  float atten[4]; // [esp+21Ch] [ebp-1A8h] BYREF
  float v83[4]; // [esp+22Ch] [ebp-198h] BYREF
  float packedParams[4]; // [esp+23Ch] [ebp-188h] BYREF
  float noiseScroll[4]; // [esp+24Ch] [ebp-178h] BYREF
  float v86[4]; // [esp+25Ch] [ebp-168h] BYREF
  float pos[4]; // [esp+26Ch] [ebp-158h] BYREF
  float v88[4]; // [esp+27Ch] [ebp-148h] BYREF
  float tweaks[4]; // [esp+28Ch] [ebp-138h] BYREF
  FlashlightState_t flashlightState; // [esp+29Ch] [ebp-128h] BYREF
  float vScreenScale[4]; // [esp+398h] [ebp-2Ch] BYREF
  float v92; // [esp+3A8h] [ebp-1Ch] BYREF
  QAngle angles; // [esp+3ACh] [ebp-18h] BYREF
  int nHeight; // [esp+3B8h] [ebp-Ch] BYREF
  int nTexWidth; // [esp+3BCh] [ebp-8h] BYREF
  int nTexHeight; // [esp+3C0h] [ebp-4h] BYREF

  v6 = pShaderShadow;
  if ( pShaderShadow != 0.0 )
  {
    (*(void (__thiscall **)(_DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(pShaderShadow) + 64))(
      a1: LODWORD(pShaderShadow),
      a2: 1,
      a3: 0,
      a4: 0,
      a5: 0);
    (*(void (__thiscall **)(float, const char *, _DWORD))(*(_DWORD *)LODWORD(v6) + 68))(
      a1: COERCE_FLOAT(LODWORD(v6)),
      a2: "lightshafts_vs30",
      a3: 0);
    v7 = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: true);
    if ( g_shaderConfigDumpEnable )
    {
      v8 = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: true);
      printf(
        format: "\n   PS stat var %s = %d (%s)",
        "FLASHLIGHTDEPTHFILTERMODE",
        v8,
        "IsPC() ? g_pHardwareConfig->GetShadowFilterMode( false , true ) : SHADOWFILTERMODE_DEFAULT");
    }
    (*(void (__thiscall **)(float, const char *, __int32))(*(_DWORD *)LODWORD(v6) + 72))(
      a1: COERCE_FLOAT(LODWORD(v6)),
      a2: "lightshafts_ps30",
      a3: 4 * v7);
    (*(void (__thiscall **)(float, _DWORD, int))(*(_DWORD *)LODWORD(v6) + 84))(
      a1: COERCE_FLOAT(LODWORD(v6)),
      a2: 0,
      a3: 1);
    (*(void (__thiscall **)(float, _DWORD, int))(*(_DWORD *)LODWORD(v6) + 80))(
      a1: COERCE_FLOAT(LODWORD(v6)),
      a2: 0,
      a3: 1);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v6) + 84))(a1: COERCE_FLOAT(LODWORD(v6)), a2: 1, a3: 1);
    (*(void (__thiscall **)(float, int, _DWORD))(*(_DWORD *)LODWORD(v6) + 80))(
      a1: COERCE_FLOAT(LODWORD(v6)),
      a2: 1,
      a3: 0);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v6) + 84))(a1: COERCE_FLOAT(LODWORD(v6)), a2: 2, a3: 1);
    (*(void (__thiscall **)(float, int, _DWORD))(*(_DWORD *)LODWORD(v6) + 80))(
      a1: COERCE_FLOAT(LODWORD(v6)),
      a2: 2,
      a3: 0);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v6) + 84))(a1: COERCE_FLOAT(LODWORD(v6)), a2: 3, a3: 1);
    (*(void (__thiscall **)(float, int, _DWORD))(*(_DWORD *)LODWORD(v6) + 80))(
      a1: COERCE_FLOAT(LODWORD(v6)),
      a2: 3,
      a3: 0);
    (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v6) + 76))(a1: COERCE_FLOAT(LODWORD(v6)), a2: 1);
    CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
    (*(void (__thiscall **)(float, _DWORD))(*(_DWORD *)LODWORD(v6) + 24))(a1: COERCE_FLOAT(LODWORD(v6)), a2: 0);
  }
  v9 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    ((void (__thiscall *)(IShaderDynamicAPI *, _DWORD, int))pShaderAPI->SetVertexShaderIndex)(
      a1: pShaderAPI,
      a2: 0,
      a3: a1);
    FlashlightState_t::FlashlightState_t(this: &flashlightState);
    v10 = info;
    if ( info->m_nWorldToTexture != -1 )
    {
      v11 = params[info->m_nWorldToTexture];
      if ( v11->IsDefined(this: v11) )
      {
        v12 = params[v10->m_nWorldToTexture];
        v13 = v12->GetMatrixValue(this: v12);
        VMatrix::operator=(this: &worldToTexture, mOther: v13);
      }
    }
    w = 1.0;
    if ( v10->m_nFlashlightColor != -1 )
    {
      v15 = params[v10->m_nFlashlightColor];
      if ( v15->IsDefined(this: v15) )
      {
        v16 = params[v10->m_nFlashlightColor];
        flashlightState.m_Color[0] = v16->m_VecVal.x;
        flashlightState.m_Color[1] = v16->m_VecVal.y;
        flashlightState.m_Color[2] = v16->m_VecVal.z;
        w = v16->m_VecVal.w;
        goto LABEL_14;
      }
      w = 1.0;
    }
    flashlightState.m_Color[2] = 1.0;
    flashlightState.m_Color[1] = 1.0;
    flashlightState.m_Color[0] = 1.0;
LABEL_14:
    v17 = v10->m_nVolumetricIntensity == -1;
    flashlightState.m_Color[3] = w;
    if ( !v17 )
    {
      v18 = params[v10->m_nVolumetricIntensity];
      if ( v18->IsDefined(this: v18) )
      {
        x = params[v10->m_nVolumetricIntensity]->m_VecVal.x;
        flashlightState.m_Color[0] = x * flashlightState.m_Color[0];
        flashlightState.m_Color[1] = x * flashlightState.m_Color[1];
        flashlightState.m_Color[2] = x * flashlightState.m_Color[2];
      }
    }
    GetHDREnabled = g_pHardwareConfig->GetHDREnabled;
    pShaderShadow = r_flashlightbrightness.m_pParent->m_Value.m_fValue;
    if ( !GetHDREnabled(this: g_pHardwareConfig) )
      pShaderShadow = 2.0;
    v21 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
    v22 = pShaderShadow;
    if ( v21 )
      v22 = pShaderShadow * 2.5;
    SetPixelShaderConstant = v9->SetPixelShaderConstant;
    v92 = (float)(flashlightState.m_fBrightnessScale * v22) * flashlightState.m_Color[0];
    angles.y = (float)(flashlightState.m_fBrightnessScale * v22) * flashlightState.m_Color[2];
    angles.x = (float)(flashlightState.m_fBrightnessScale * v22) * flashlightState.m_Color[1];
    angles.z = 0.0;
    SetPixelShaderConstant(this: v9, a2: 28, a3: &v92, a4: 1, a5: false);
    if ( v10->m_nAttenFactors != -1 )
    {
      v24 = params[v10->m_nAttenFactors];
      if ( v24->IsDefined(this: v24) )
      {
        v25 = params[v10->m_nAttenFactors];
        y = v25->m_VecVal.y;
        z = v25->m_VecVal.z;
        v28 = v25->m_VecVal.w;
        flashlightState.m_fConstantAtten = v25->m_VecVal.x;
        flashlightState.m_fLinearAtten = y;
        flashlightState.m_fQuadraticAtten = z;
        flashlightState.m_FarZAtten = v28;
      }
    }
    if ( v10->m_nOriginFarZ != -1 )
    {
      v29 = params[v10->m_nOriginFarZ];
      if ( v29->IsDefined(this: v29) )
      {
        v30 = params[v10->m_nOriginFarZ];
        v31 = v30->m_VecVal.y;
        v32 = v30->m_VecVal.z;
        v33 = v30->m_VecVal.w;
        flashlightState.m_vecLightOrigin.x = v30->m_VecVal.x;
        flashlightState.m_vecLightOrigin.y = v31;
        flashlightState.m_vecLightOrigin.z = v32;
        flashlightState.m_FarZ = v33;
      }
    }
    if ( v10->m_nQuatOrientation != -1 )
    {
      v34 = params[v10->m_nQuatOrientation];
      if ( v34->IsDefined(this: v34) )
        flashlightState.m_quatOrientation = (Quaternion)params[v10->m_nQuatOrientation]->m_VecVal;
    }
    if ( v10->m_nShadowFilterSize != -1 )
    {
      v35 = params[v10->m_nShadowFilterSize];
      if ( v35->IsDefined(this: v35) )
        flashlightState.m_flShadowFilterSize = params[v10->m_nShadowFilterSize]->m_VecVal.x;
    }
    if ( v10->m_nShadowAtten != -1 )
    {
      v36 = params[v10->m_nShadowAtten];
      if ( v36->IsDefined(this: v36) )
        flashlightState.m_flShadowAtten = params[v10->m_nShadowAtten]->m_VecVal.x;
    }
    if ( v10->m_nShadowJitterSeed != -1 )
    {
      v37 = params[v10->m_nShadowJitterSeed];
      if ( v37->IsDefined(this: v37) )
        flashlightState.m_flShadowJitterSeed = params[v10->m_nShadowJitterSeed]->m_VecVal.x;
    }
    if ( v10->m_nFlashlightTime != -1 )
    {
      v38 = params[v10->m_nFlashlightTime];
      if ( v38->IsDefined(this: v38) )
        flashlightState.m_flFlashlightTime = params[v10->m_nFlashlightTime]->m_VecVal.x;
    }
    if ( v10->m_nNumPlanes != -1 )
    {
      v39 = params[v10->m_nNumPlanes];
      if ( v39->IsDefined(this: v39) )
        flashlightState.m_nNumPlanes = params[v10->m_nNumPlanes]->m_intVal;
    }
    if ( v10->m_nUberlight != -1 )
    {
      v40 = params[v10->m_nUberlight];
      if ( v40->IsDefined(this: v40) )
        flashlightState.m_bUberlight = params[v10->m_nUberlight]->m_intVal != 0;
    }
    if ( v10->m_nEnableShadows != -1 )
    {
      v41 = params[v10->m_nEnableShadows];
      if ( v41->IsDefined(this: v41) )
        flashlightState.m_bEnableShadows = params[v10->m_nEnableShadows]->m_intVal != 0;
    }
    if ( v10->m_nNoiseStrength != -1 )
    {
      v42 = params[v10->m_nNoiseStrength];
      if ( v42->IsDefined(this: v42) )
        flashlightState.m_flNoiseStrength = params[v10->m_nNoiseStrength]->m_VecVal.x;
    }
    if ( v10->m_nCookieTexture != -1 )
    {
      v43 = params[v10->m_nCookieTexture];
      if ( v43->IsDefined(this: v43) )
      {
        v44 = params[v10->m_nCookieTexture];
        v45 = (ITexture *)v44->GetTextureValue(this: v44);
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER0,
          nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
          pTexture: v45,
          nFrame: params[v10->m_nCookieFrameNum]->m_intVal);
      }
    }
    if ( v10->m_nShadowDepthTexture != -1
      && params[v10->m_nShadowDepthTexture]->IsDefined(this: params[v10->m_nShadowDepthTexture])
      && g_pConfig->m_bShadowDepthTexture
      && flashlightState.m_bEnableShadows )
    {
      v46 = (ITexture *)params[v10->m_nShadowDepthTexture]->GetTextureValue(this: params[v10->m_nShadowDepthTexture]);
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
        pTexture: v46,
        nFrame: 0);
      v9->BindStandardTexture(this: v9, a2: SHADER_SAMPLER2, a3: TEXTURE_BINDFLAGS_NONE, a4: TEXTURE_SHADOW_NOISE_2D);
    }
    if ( v10->m_nNoiseTexture != -1 )
    {
      v47 = params[v10->m_nNoiseTexture];
      if ( v47->IsDefined(this: v47) )
      {
        v48 = params[v10->m_nNoiseTexture];
        v49 = (ITexture *)v48->GetTextureValue(this: v48);
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER3,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          pTexture: v49,
          nFrame: 0);
      }
    }
    v50 = v9->SetPixelShaderConstant;
    atten[0] = flashlightState.m_fConstantAtten;
    atten[1] = flashlightState.m_fLinearAtten;
    atten[2] = flashlightState.m_fQuadraticAtten;
    atten[3] = flashlightState.m_FarZAtten;
    v50(this: v9, a2: 13, a3: atten, a4: 1, a5: false);
    v51 = v9->SetPixelShaderConstant;
    *(Vector *)pos = flashlightState.m_vecLightOrigin;
    pos[3] = flashlightState.m_FarZ;
    v51(this: v9, a2: 14, a3: pos, a4: 1, a5: false);
    v52 = v9->SetPixelShaderConstant;
    packedParams[0] = flashlightState.m_flNoiseStrength;
    packedParams[1] = 64.0 / (float)flashlightState.m_nNumPlanes;
    packedParams[2] = 0.0;
    packedParams[3] = 0.0;
    v52(this: v9, a2: 0, a3: packedParams, a4: 1, a5: false);
    v53 = flashlightState.m_flFlashlightTime * 0.043000001;
    pShaderShadow = v53;
    noiseScroll[0] = fmod(v53 * 0.394, 1.0);
    noiseScroll[1] = fmod(pShaderShadow * 0.919, 1.0);
    v54 = flashlightState.m_flFlashlightTime * 0.039000001;
    pShaderShadow = v54;
    noiseScroll[2] = fmod(v54 * -0.781, 1.0);
    noiseScroll[3] = fmod(pShaderShadow * 0.625, 1.0);
    v9->SetPixelShaderConstant(this: v9, a2: 1, a3: noiseScroll, a4: 1, a5: false);
    tweaks[0] = flashlightState.m_flShadowFilterSize * 0.0009765625;
    v55 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
    m_flShadowAtten = flashlightState.m_flShadowAtten;
    if ( v55 )
      m_flShadowAtten = flashlightState.m_flShadowAtten * 0.1;
    tweaks[1] = m_flShadowAtten;
    CBaseVSShader::HashShadow2DJitter(
      this: pShader,
      fJitterSeed: flashlightState.m_flShadowJitterSeed,
      fU: &tweaks[2],
      fV: &tweaks[3]);
    v9->SetPixelShaderConstant(this: v9, a2: 2, a3: tweaks, a4: 1, a5: false);
    v9->SetVertexShaderConstant(this: v9, a2: 48, a3: (const float *)&worldToTexture, a4: 4, a5: false);
    if ( flashlightState.m_bUberlight )
    {
      v17 = v10->m_nUberNearFar == -1;
      flashlightState.m_uberlightState.m_fShearx = 0.0;
      flashlightState.m_uberlightState.m_fSheary = 0.0;
      if ( !v17 )
      {
        v57 = params[v10->m_nUberNearFar];
        if ( v57->IsDefined(this: v57) )
        {
          v58 = params[v10->m_nUberNearFar];
          v59 = v58->m_VecVal.y;
          v60 = v58->m_VecVal.z;
          v61 = v58->m_VecVal.w;
          flashlightState.m_uberlightState.m_fNearEdge = v58->m_VecVal.x;
          flashlightState.m_uberlightState.m_fFarEdge = v59;
          flashlightState.m_uberlightState.m_fCutOn = v60;
          flashlightState.m_uberlightState.m_fCutOff = v61;
        }
      }
      if ( v10->m_nUberHeightWidth != -1 )
      {
        v62 = params[v10->m_nUberHeightWidth];
        if ( v62->IsDefined(this: v62) )
        {
          v63 = params[v10->m_nUberHeightWidth];
          v64 = v63->m_VecVal.y;
          v65 = v63->m_VecVal.z;
          v66 = v63->m_VecVal.w;
          flashlightState.m_uberlightState.m_fWidth = v63->m_VecVal.x;
          flashlightState.m_uberlightState.m_fWedge = v64;
          flashlightState.m_uberlightState.m_fHeight = v65;
          flashlightState.m_uberlightState.m_fHedge = v66;
        }
      }
      if ( v10->m_nUberRoundness != -1 )
      {
        v67 = params[v10->m_nUberRoundness];
        if ( v67->IsDefined(this: v67) )
          flashlightState.m_uberlightState.m_fRoundness = params[v10->m_nUberRoundness]->m_VecVal.x;
      }
      if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) && flashlightState.m_bUberlight )
      {
        v68 = v9->SetPixelShaderConstant;
        v81[1] = flashlightState.m_uberlightState.m_fCutOn - flashlightState.m_uberlightState.m_fNearEdge;
        v81[2] = flashlightState.m_uberlightState.m_fCutOff;
        v80[2] = flashlightState.m_uberlightState.m_fCutOff + flashlightState.m_uberlightState.m_fFarEdge;
        v81[0] = 0.0;
        v81[3] = 0.0;
        v80[0] = 0.0;
        v80[3] = 0.0;
        v83[0] = 0.0;
        v83[3] = 0.0;
        v88[0] = flashlightState.m_uberlightState.m_fShearx;
        v83[2] = 1.0 / flashlightState.m_uberlightState.m_fFarEdge;
        v88[1] = flashlightState.m_uberlightState.m_fSheary;
        v88[2] = 2.0 / flashlightState.m_uberlightState.m_fRoundness;
        v88[3] = flashlightState.m_uberlightState.m_fRoundness * -0.5;
        v86[1] = flashlightState.m_uberlightState.m_fWedge + flashlightState.m_uberlightState.m_fWidth;
        v86[0] = flashlightState.m_uberlightState.m_fWidth;
        v80[1] = flashlightState.m_uberlightState.m_fCutOn;
        v83[1] = 1.0 / flashlightState.m_uberlightState.m_fNearEdge;
        v86[2] = flashlightState.m_uberlightState.m_fHeight;
        v86[3] = flashlightState.m_uberlightState.m_fHedge + flashlightState.m_uberlightState.m_fHeight;
        v68(this: v9, a2: 33, a3: v81, a4: 1, a5: false);
        v9->SetPixelShaderConstant(this: v9, a2: 34, a3: v80, a4: 1, a5: false);
        v9->SetPixelShaderConstant(this: v9, a2: 35, a3: v83, a4: 1, a5: false);
        v9->SetPixelShaderConstant(this: v9, a2: 36, a3: v88, a4: 1, a5: false);
        v9->SetPixelShaderConstant(this: v9, a2: 37, a3: v86, a4: 1, a5: false);
        QuaternionAngles(q: &flashlightState.m_quatOrientation, angles: &v79);
        AngleMatrix(angles: &v79, position: &flashlightState.m_vecLightOrigin, &matrix);
        MatrixInvert(in: &matrix, &out);
        v9->SetPixelShaderConstant(this: v9, a2: 38, a3: (const float *)&out, a4: 4, a5: false);
      }
      QuaternionAngles(q: &flashlightState.m_quatOrientation, &angles);
      AngleMatrix(&angles, position: &flashlightState.m_vecLightOrigin, matrix: &identityMatrix);
      MatrixInvert(in: &identityMatrix, out: &viewMatrix);
      p_worldToTexture = (const float *)&worldToTexture;
    }
    else
    {
      SetIdentityMatrix(matrix: &identityMatrix);
      p_worldToTexture = (const float *)&identityMatrix;
    }
    v9->SetVertexShaderConstant(this: v9, a2: 52, a3: p_worldToTexture, a4: 4, a5: false);
    GetBackBufferDimensions = v9->GetBackBufferDimensions;
    vScreenScale[0] = 40.0;
    vScreenScale[1] = 22.5;
    vScreenScale[2] = 0.0;
    vScreenScale[3] = 0.0;
    GetBackBufferDimensions(this: v9, a2: (int *)&pShaderAPI, a3: &nHeight);
    v9->GetStandardTextureDimensions(this: v9, a2: &nTexWidth, a3: &nTexHeight, a4: TEXTURE_SHADOW_NOISE_2D);
    v71 = v9->SetPixelShaderConstant;
    vScreenScale[0] = (float)(int)pShaderAPI / (float)nTexWidth;
    vScreenScale[1] = (float)nHeight / (float)nTexHeight;
    v71(this: v9, a2: 31, a3: vScreenScale, a4: 1, a5: false);
    m_bEnableShadows = flashlightState.m_bEnableShadows;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "FLASHLIGHTSHADOWS",
        flashlightState.m_bEnableShadows,
        "flashlightState.m_bEnableShadows");
    m_bUberlight = flashlightState.m_bUberlight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "UBERLIGHT",
        flashlightState.m_bUberlight,
        "flashlightState.m_bUberlight");
    v9->SetPixelShaderIndex(this: v9, a2: m_bEnableShadows + 2 * m_bUberlight);
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
