// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/eyes_dx8_dx9_helper.cpp
// Functions: 7
// ============================================================

#include "materialsystem\stdshaders\eyes_dx8_dx9_helper.h"

//------------------------------------------------------------------------------
// Address: 0x100112C0
// Name: public: eyes_vs30_Dynamic_Index::eyes_vs30_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
eyes_vs30_Dynamic_Index *__thiscall eyes_vs30_Dynamic_Index::eyes_vs30_Dynamic_Index(
        eyes_vs30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  MaterialFogMode_t v3; // eax

  this->m_nCOMPRESSED_VERTS = 0;
  this->m_nSKINNING = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
  this->m_nDYNAMIC_LIGHT = 0;
  this->m_nSTATIC_LIGHT = 0;
  this->m_nDOWATERFOG = v3 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nMORPHING = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011320
// Name: void InitParamsEyes_DX8_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct Eyes_DX8_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsEyes_DX8_DX9(CBaseVSShader *pShader, IMaterialVar **params)
{
  params[9]->SetStringValue(this: params[9], a2: "effects/flashlight001");
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
}

//------------------------------------------------------------------------------
// Address: 0x10011360
// Name: void InitEyes_DX8_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct Eyes_DX8_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitEyes_DX8_DX9(CBaseVSShader *pShader, IMaterialVar **params, Eyes_DX8_DX9_Vars_t *info)
{
  IMaterialVar *v3; // ecx

  CBaseShader::LoadTexture(this: pShader, nTextureVar: 9, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nIris, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nGlint, nAdditionalCreationFlags: 0);
  v3 = params[info->m_nDilation];
  if ( !v3->IsDefined(this: v3) )
    ((void (__stdcall *)(_DWORD))params[info->m_nDilation]->SetFloatValue)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100113E0
// Name: SetDepthFlashlightParams
// Source: json
//------------------------------------------------------------------------------
void __usercall SetDepthFlashlightParams(
        IShaderDynamicAPI *pShaderAPI@<esi>,
        const FlashlightState_t *flashlightState@<edi>,
        CBaseVSShader *pShader,
        const VMatrix *worldToTexture)
{
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v5)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  char v6; // al
  float m_flShadowAtten; // xmm0_4
  void (__thiscall *GetBackBufferDimensions)(IShaderDynamicAPI *, int *, int *); // eax
  void (__thiscall *v9)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float tweaks[4]; // [esp+3Ch] [ebp-50h] BYREF
  float pos[4]; // [esp+4Ch] [ebp-40h] BYREF
  float atten[4]; // [esp+5Ch] [ebp-30h] BYREF
  float vScreenScale[4]; // [esp+6Ch] [ebp-20h] BYREF
  int nTexHeight; // [esp+7Ch] [ebp-10h] BYREF
  int nHeight; // [esp+80h] [ebp-Ch] BYREF
  int nTexWidth; // [esp+84h] [ebp-8h] BYREF
  int nWidth; // [esp+88h] [ebp-4h] BYREF

  SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
  atten[0] = flashlightState->m_fConstantAtten;
  atten[1] = flashlightState->m_fLinearAtten;
  atten[2] = flashlightState->m_fQuadraticAtten;
  atten[3] = flashlightState->m_FarZAtten;
  SetPixelShaderConstant(this: pShaderAPI, a2: 13, a3: atten, a4: 1, a5: false);
  v5 = pShaderAPI->SetPixelShaderConstant;
  *(Vector *)pos = flashlightState->m_vecLightOrigin;
  pos[3] = flashlightState->m_FarZ;
  v5(this: pShaderAPI, a2: 14, a3: pos, a4: 1, a5: false);
  pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 15, a3: (const float *)worldToTexture, a4: 4, a5: false);
  v6 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, _DWORD))g_pHardwareConfig->UsesSRGBCorrectBlending)(
         a1: g_pHardwareConfig,
         a2: flashlightState->m_flShadowFilterSize * 0.0009765625);
  m_flShadowAtten = flashlightState->m_flShadowAtten;
  if ( v6 != 0 )
    m_flShadowAtten = m_flShadowAtten * 0.1;
  tweaks[1] = m_flShadowAtten;
  CBaseVSShader::HashShadow2DJitter(
    this: pShader,
    fJitterSeed: flashlightState->m_flShadowJitterSeed,
    fU: &tweaks[2],
    fV: &tweaks[3]);
  pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 2, a3: tweaks, a4: 1, a5: false);
  GetBackBufferDimensions = pShaderAPI->GetBackBufferDimensions;
  vScreenScale[0] = 40.0;
  vScreenScale[1] = 22.5;
  vScreenScale[2] = 0.0;
  vScreenScale[3] = 0.0;
  GetBackBufferDimensions(this: pShaderAPI, a2: &nWidth, a3: &nHeight);
  pShaderAPI->GetStandardTextureDimensions(
    this: pShaderAPI,
    a2: &nTexWidth,
    a3: &nTexHeight,
    a4: TEXTURE_SHADOW_NOISE_2D);
  v9 = pShaderAPI->SetPixelShaderConstant;
  vScreenScale[0] = (float)nWidth / (float)nTexWidth;
  vScreenScale[1] = (float)nHeight / (float)nTexHeight;
  vScreenScale[2] = 1.0 / flashlightState->m_flShadowMapResolution;
  vScreenScale[3] = vScreenScale[2] * 2.0;
  v9(this: pShaderAPI, a2: 31, a3: vScreenScale, a4: 1, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10011590
// Name: DrawFlashlight
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawFlashlight(
        IShaderShadow *pShaderShadow@<eax>,
        CBaseVSShader *bDX9,
        IMaterialVar **pShader,
        IMaterialVar **params,
        Eyes_DX8_DX9_Vars_t *pShaderAPI,
        Eyes_DX8_DX9_Vars_t *info)
{
  int v7; // eax
  ShadowFilterMode_t v8; // ebx
  BOOL v9; // edi
  int v10; // eax
  int v11; // eax
  CBaseVSShader *v12; // esi
  int *p_m_nBaseTexture; // edi
  bool v14; // zf
  char *v15; // eax
  int v16; // eax
  int m_nUBERLIGHT; // ecx
  int m_nPIXELFOGTYPE; // edx
  float x; // eax
  int v20; // ecx
  char *m_pStringVal; // eax
  int v22; // eax
  bool (__thiscall *GetHDREnabled)(IMaterialSystemHardwareConfig *); // eax
  bool v24; // al
  int v25; // xmm1_4
  float z; // edx
  float v27; // edx
  BOOL v28; // edi
  int v29; // eax
  BOOL v30; // edi
  float v31; // edx
  const char *v32; // [esp-4h] [ebp-220h]
  const char *v33; // [esp-4h] [ebp-220h]
  matrix3x4_t matrix; // [esp+Ch] [ebp-210h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-1E0h] BYREF
  VMatrix worldToTexture; // [esp+6Ch] [ebp-1B0h] BYREF
  FlashlightState_t flashlightState; // [esp+ACh] [ebp-170h] BYREF
  float vEyePos_SpecExponent[4]; // [esp+1A8h] [ebp-74h] BYREF
  float v39[4]; // [esp+1B8h] [ebp-64h] BYREF
  float v40[4]; // [esp+1C8h] [ebp-54h] BYREF
  float v41[4]; // [esp+1D8h] [ebp-44h] BYREF
  float v42[4]; // [esp+1E8h] [ebp-34h] BYREF
  ITexture *pFlashlightDepthTexture; // [esp+1F8h] [ebp-24h] BYREF
  float v44; // [esp+1FCh] [ebp-20h] BYREF
  float v45; // [esp+200h] [ebp-1Ch]
  float m_fCutOff; // [esp+204h] [ebp-18h]
  int v47; // [esp+208h] [ebp-14h]
  eyes_flashlight_ps30_Dynamic_Index _pshIndex; // [esp+210h] [ebp-Ch] BYREF

  if ( pShaderShadow == nullptr )
  {
    flashlightState = *(FlashlightState_t *)(*((int (__thiscall **)(IMaterialVar **, VMatrix *, ITexture **))&(*params)[3]
                                             + 7))(
                                              a1: params,
                                              a2: &worldToTexture,
                                              a3: &pFlashlightDepthTexture);
    v12 = bDX9;
    CBaseShader::BindTexture(
      this: bDX9,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      pTexture: flashlightState.m_pSpotlightTexture,
      nFrame: flashlightState.m_nSpotlightTextureFrame);
    p_m_nBaseTexture = &pShaderAPI->m_nBaseTexture;
    CBaseShader::BindTexture(
      this: bDX9,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: pShaderAPI->m_nBaseTexture,
      nFrameVar: pShaderAPI->m_nFrame);
    ((void (__thiscall *)(IMaterialVar **, int, _DWORD, int))LODWORD((*params)[2].m_VecVal.z))(
      a1: params,
      a2: 2,
      a3: 0,
      a4: 11);
    CBaseShader::BindTexture(
      this: bDX9,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: p_m_nBaseTexture[2],
      nFrameVar: p_m_nBaseTexture[3]);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      CBaseVSShader::SetHWMorphVertexShaderState(
        this: bDX9,
        nDimConst: 14,
        nSubrectConst: 15,
        morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      v14 = ((int (__thiscall *)(IMaterialVar **))(*params)->m_intVal)(a1: params) == 2;
      x = (*params)[4].m_VecVal.x;
      _pshIndex.m_nFLASHLIGHTSHADOWS = v14;
      v20 = ((unsigned __int8 (__thiscall *)(IMaterialVar **))LODWORD(x))(a1: params);
      m_pStringVal = (*params)[1].m_pStringVal;
      _pshIndex.m_nUBERLIGHT = v20;
      _pshIndex.m_nPIXELFOGTYPE = ((int (__thiscall *)(IMaterialVar **))m_pStringVal)(a1: params) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v22 = ((int (__thiscall *)(IMaterialVar **, const char *))(*params)[1].m_pStringVal)(
                a1: params,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v22 > 0, v33);
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", info, "(int)vertexCompression");
      }
      m_nUBERLIGHT = _pshIndex.m_nFLASHLIGHTSHADOWS + 2 * _pshIndex.m_nUBERLIGHT;
      m_nPIXELFOGTYPE = _pshIndex.m_nPIXELFOGTYPE;
    }
    else
    {
      v14 = ((int (__thiscall *)(IMaterialVar **))(*params)->m_intVal)(a1: params) == 2;
      v15 = (*params)[1].m_pStringVal;
      _pshIndex.m_nUBERLIGHT = v14;
      _pshIndex.m_nFLASHLIGHTSHADOWS = ((int (__thiscall *)(IMaterialVar **))v15)(a1: params) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v16 = ((int (__thiscall *)(IMaterialVar **, const char *))(*params)[1].m_pStringVal)(
                a1: params,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v16 > 0, v32);
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", info, "(int)vertexCompression");
      }
      m_nUBERLIGHT = _pshIndex.m_nUBERLIGHT;
      m_nPIXELFOGTYPE = _pshIndex.m_nFLASHLIGHTSHADOWS;
    }
    ((void (__thiscall *)(IMaterialVar **, char *))LODWORD((*params)[1].m_VecVal.x))(
      a1: params,
      a2: (char *)&info->m_nBaseTexture + 4 * m_nUBERLIGHT + 2 * m_nPIXELFOGTYPE);
    GetHDREnabled = g_pHardwareConfig->GetHDREnabled;
    _pshIndex.m_nUBERLIGHT = LODWORD(r_flashlightbrightness.m_pParent->m_Value.m_fValue);
    if ( !GetHDREnabled(this: g_pHardwareConfig) )
      _pshIndex.m_nUBERLIGHT = 0x40000000;
    v24 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
    v25 = _pshIndex.m_nUBERLIGHT;
    if ( v24 )
      *(float *)&v25 = *(float *)&_pshIndex.m_nUBERLIGHT * 2.5;
    z = (*params)->m_VecVal.z;
    v44 = flashlightState.m_Color[0] * (float)(flashlightState.m_fBrightnessScale * *(float *)&v25);
    v45 = flashlightState.m_Color[1] * (float)(flashlightState.m_fBrightnessScale * *(float *)&v25);
    m_fCutOff = flashlightState.m_Color[2] * (float)(flashlightState.m_fBrightnessScale * *(float *)&v25);
    v47 = 0;
    ((void (__thiscall *)(IMaterialVar **, int, float *, int, _DWORD))LODWORD(z))(
      a1: params,
      a2: 28,
      a3: &v44,
      a4: 1,
      a5: 0);
    if ( pFlashlightDepthTexture != nullptr && g_pConfig->m_bShadowDepthTexture && flashlightState.m_bEnableShadows )
    {
      CBaseShader::BindTexture(
        this: bDX9,
        sampler1: SHADER_SAMPLER4,
        nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
        pTexture: pFlashlightDepthTexture,
        nFrame: 0);
      ((void (__thiscall *)(IMaterialVar **, int, _DWORD, int))LODWORD((*params)[2].m_VecVal.z))(
        a1: params,
        a2: 5,
        a3: 0,
        a4: 20);
    }
    ((void (__thiscall *)(IMaterialVar **, int))(*params)[2].m_pStringVal)(a1: params, a2: 12);
    (*((void (__thiscall **)(IMaterialVar **, float *))*params + 7))(a1: params, a2: vEyePos_SpecExponent);
    v27 = (*params)->m_VecVal.z;
    vEyePos_SpecExponent[3] = 0.0;
    ((void (__thiscall *)(IMaterialVar **, int, float *, int, _DWORD))LODWORD(v27))(
      a1: params,
      a2: 11,
      a3: vEyePos_SpecExponent,
      a4: 1,
      a5: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      v30 = ((int (__thiscall *)(IMaterialVar **))(*params)->m_intVal)(a1: params) == 2;
      _pshIndex.m_nFLASHLIGHTSHADOWS = flashlightState.m_bEnableShadows;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "FLASHLIGHTSHADOWS",
          flashlightState.m_bEnableShadows,
          "flashlightState.m_bEnableShadows");
      _pshIndex.m_nUBERLIGHT = flashlightState.m_bUberlight;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "UBERLIGHT",
          flashlightState.m_bUberlight,
          "flashlightState.m_bUberlight");
      ((void (__thiscall *)(IMaterialVar **, int))LODWORD((*params)[1].m_VecVal.y))(
        a1: params,
        a2: v30 + 2 * (_pshIndex.m_nFLASHLIGHTSHADOWS + 2 * _pshIndex.m_nUBERLIGHT));
      SetDepthFlashlightParams(
        pShaderAPI: (IShaderDynamicAPI *)params,
        &flashlightState,
        pShader: bDX9,
        &worldToTexture);
      if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) && flashlightState.m_bUberlight )
      {
        v31 = (*params)->m_VecVal.z;
        v41[1] = flashlightState.m_uberlightState.m_fCutOn;
        v44 = 0.0;
        v45 = flashlightState.m_uberlightState.m_fCutOn - flashlightState.m_uberlightState.m_fNearEdge;
        v41[2] = flashlightState.m_uberlightState.m_fFarEdge + flashlightState.m_uberlightState.m_fCutOff;
        v47 = 0;
        v41[0] = 0.0;
        v41[3] = 0.0;
        v40[0] = 0.0;
        v40[3] = 0.0;
        v42[0] = flashlightState.m_uberlightState.m_fShearx;
        m_fCutOff = flashlightState.m_uberlightState.m_fCutOff;
        v40[2] = 1.0 / flashlightState.m_uberlightState.m_fFarEdge;
        v42[1] = flashlightState.m_uberlightState.m_fSheary;
        v42[2] = 2.0 / flashlightState.m_uberlightState.m_fRoundness;
        v42[3] = flashlightState.m_uberlightState.m_fRoundness * -0.5;
        v39[1] = flashlightState.m_uberlightState.m_fWedge + flashlightState.m_uberlightState.m_fWidth;
        v39[0] = flashlightState.m_uberlightState.m_fWidth;
        v40[1] = 1.0 / flashlightState.m_uberlightState.m_fNearEdge;
        v39[2] = flashlightState.m_uberlightState.m_fHeight;
        v39[3] = flashlightState.m_uberlightState.m_fHedge + flashlightState.m_uberlightState.m_fHeight;
        ((void (__thiscall *)(IMaterialVar **, int, float *, int, _DWORD))LODWORD(v31))(
          a1: params,
          a2: 33,
          a3: &v44,
          a4: 1,
          a5: 0);
        ((void (__thiscall *)(IMaterialVar **, int, float *, int, _DWORD))LODWORD((*params)->m_VecVal.z))(
          a1: params,
          a2: 34,
          a3: v41,
          a4: 1,
          a5: 0);
        ((void (__thiscall *)(IMaterialVar **, int, float *, int, _DWORD))LODWORD((*params)->m_VecVal.z))(
          a1: params,
          a2: 35,
          a3: v40,
          a4: 1,
          a5: 0);
        ((void (__thiscall *)(IMaterialVar **, int, float *, int, _DWORD))LODWORD((*params)->m_VecVal.z))(
          a1: params,
          a2: 36,
          a3: v42,
          a4: 1,
          a5: 0);
        ((void (__thiscall *)(IMaterialVar **, int, float *, int, _DWORD))LODWORD((*params)->m_VecVal.z))(
          a1: params,
          a2: 37,
          a3: v39,
          a4: 1,
          a5: 0);
        QuaternionAngles(q: &flashlightState.m_quatOrientation, angles: (QAngle *)&_pshIndex);
        AngleMatrix(angles: (const QAngle *)&_pshIndex, position: &flashlightState.m_vecLightOrigin, &matrix);
        MatrixInvert(in: &matrix, &out);
        ((void (__thiscall *)(IMaterialVar **, int, matrix3x4_t *, int, _DWORD))LODWORD((*params)->m_VecVal.z))(
          a1: params,
          a2: 38,
          a3: &out,
          a4: 4,
          a5: 0);
      }
    }
    else
    {
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        v29 = ((int (__thiscall *)(IMaterialVar **))(*params)->m_intVal)(a1: params);
        ((void (__thiscall *)(IMaterialVar **, bool))LODWORD((*params)[1].m_VecVal.y))(a1: params, a2: v29 == 2);
LABEL_45:
        CBaseVSShader::SetFlashlightVertexShaderConstants(
          this: v12,
          bBump: false,
          bumpTransformVar: -1,
          bDetail: false,
          detailScaleVar: -1,
          bSetTextureTransforms: false);
        CBaseVSShader::SetVertexShaderConstant(this: v12, vertexReg: 54, constantVar: p_m_nBaseTexture[5]);
        CBaseVSShader::SetVertexShaderConstant(this: v12, vertexReg: 55, constantVar: p_m_nBaseTexture[6]);
        CBaseVSShader::SetVertexShaderConstant(this: v12, vertexReg: 56, constantVar: p_m_nBaseTexture[7]);
        CBaseVSShader::SetVertexShaderConstant(this: v12, vertexReg: 57, constantVar: p_m_nBaseTexture[8]);
        CBaseShader::Draw(this: bDX9, bMakeActualDrawCall: true);
        return;
      }
      v28 = ((int (__thiscall *)(IMaterialVar **))(*params)->m_intVal)(a1: params) == 2;
      _pshIndex.m_nUBERLIGHT = flashlightState.m_bEnableShadows;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "FLASHLIGHTSHADOWS",
          flashlightState.m_bEnableShadows,
          "flashlightState.m_bEnableShadows");
      ((void (__thiscall *)(IMaterialVar **, int))LODWORD((*params)[1].m_VecVal.y))(
        a1: params,
        a2: v28 + 2 * _pshIndex.m_nUBERLIGHT);
      SetDepthFlashlightParams(
        pShaderAPI: (IShaderDynamicAPI *)params,
        &flashlightState,
        pShader: bDX9,
        &worldToTexture);
    }
    v12 = bDX9;
    p_m_nBaseTexture = &pShaderAPI->m_nBaseTexture;
    goto LABEL_45;
  }
  pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
  CBaseShader::EnableAlphaBlending(this: bDX9, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
  pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
  pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
  pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
  pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
  pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
  pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
  v7 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *))g_pHardwareConfig->HasFastVertexTextures)(a1: g_pHardwareConfig);
  LOBYTE(v7) = (_BYTE)v7 != 0;
  v8 = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: v7);
  if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
  {
    ((void (__stdcall *)(int))pShader[2]->SetIntValue)(a1: pShader[2]->m_intVal | 0x20000);
    v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "eyes_flashlight_vs30", a3: 16 * (v11 >= 92));
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHTDEPTHFILTERMODE", v8, "nShadowFilterMode");
    pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "eyes_flashlight_ps30", a3: 8 * v8);
  }
  else
  {
    v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "eyes_flashlight_vs20", a3: 8 * (v9 + 2 * (v10 < 92)));
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "eyes_flashlight_ps20", a3: 0);
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHTDEPTHFILTERMODE", v8, "nShadowFilterMode");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "eyes_flashlight_ps20b", a3: 4 * v8);
    }
  }
  pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
  pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
  pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
  pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
  }
  CBaseShader::FogToBlack(this: bDX9);
  CBaseShader::Draw(this: bDX9, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10011E70
// Name: DrawUsingVertexShader
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawUsingVertexShader(
        IShaderDynamicAPI *pShaderAPI@<esi>,
        IShaderShadow *pShaderShadow@<eax>,
        CBaseVSShader *bDX9,
        IMaterialVar **pShader,
        IMaterialVar **params,
        Eyes_DX8_DX9_Vars_t *info)
{
  bool v7; // al
  int (__thiscall *GetDXSupportLevel)(IMaterialSystemHardwareConfig *); // edx
  int v9; // eax
  BOOL v10; // ebx
  bool v11; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // eax
  int v13; // eax
  BOOL v14; // ebx
  CBaseVSShader *v15; // ebx
  bool v16; // zf
  int (__thiscall *GetCurrentNumBones)(IShaderDynamicAPI *); // eax
  int v18; // eax
  BOOL v19; // eax
  int m_nPIXELFOGTYPE; // eax
  int v21; // eax
  BOOL v22; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v24)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  MaterialFogMode_t (__thiscall *GetSceneFogMode)(IShaderDynamicAPI *); // edx
  MaterialFogMode_t v26; // eax
  int v27; // eax
  BOOL v28; // edi
  unsigned __int8 v29; // al
  const char *v30; // [esp-4h] [ebp-68h]
  const char *v31; // [esp-4h] [ebp-68h]
  const char *v32; // [esp-4h] [ebp-68h]
  int v33; // [esp+0h] [ebp-64h]
  eyes_vs30_Dynamic_Index _vshIndex; // [esp+8h] [ebp-5Ch] BYREF
  float vEyePos_SpecExponent[4]; // [esp+20h] [ebp-44h] BYREF
  float vPSConst[4]; // [esp+30h] [ebp-34h] BYREF
  LightState_t lightState; // [esp+40h] [ebp-24h]
  BOOL v38; // [esp+48h] [ebp-1Ch] BYREF
  BOOL v39; // [esp+4Ch] [ebp-18h]
  eyes_ps30_Dynamic_Index _pshIndex; // [esp+50h] [ebp-14h]
  int v41; // [esp+58h] [ebp-Ch]
  BOOL v42; // [esp+5Ch] [ebp-8h]
  bool bUseStaticControlFlow; // [esp+63h] [ebp-1h]

  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))pShader[2]->SetIntValue)(a1: pShader[2]->m_intVal | 0x20000);
      v13 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v14 = ((*pShader)->m_intVal & 0x8000000) != 0;
      v38 = v13 >= 92;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", v14, "IS_FLAG_SET( MATERIAL_VAR_HALFLAMBERT )");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "eyes_vs30", a3: (v14 + 2 * v38) << 6);
      v33 = 0;
      ((void (__stdcall *)(const char *))pShaderShadow->SetPixelShader)(a1: "eyes_ps30");
    }
    else
    {
      v7 = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
      GetDXSupportLevel = g_pHardwareConfig->GetDXSupportLevel;
      bUseStaticControlFlow = !v7;
      v38 = GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v10 = ((*pShader)->m_intVal & 0x8000000) != 0;
      v39 = v9 < 92;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", v10, "IS_FLAG_SET( MATERIAL_VAR_HALFLAMBERT )");
      *(_DWORD *)&lightState.m_bAmbientLight = bUseStaticControlFlow;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "FLATTEN_STATIC_CONTROL_FLOW",
          bUseStaticControlFlow,
          "bFlattenStaticControlFlow");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "eyes_vs20",
        a3: 96 * (v10 + 2 * (*(_DWORD *)&lightState.m_bAmbientLight + 2 * (v38 + 2 * v39))));
      v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      SetPixelShader = pShaderShadow->SetPixelShader;
      v33 = 0;
      if ( v11 )
        ((void (__stdcall *)(const char *))SetPixelShader)(a1: "eyes_ps20");
      else
        ((void (__stdcall *)(const char *))SetPixelShader)(a1: "eyes_ps20b");
    }
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    v15 = bDX9;
    CBaseShader::FogToFogColor(this: bDX9);
    CBaseShader::PI_BeginCommandBuffer(this: bDX9);
    CBaseShader::PI_SetVertexShaderAmbientLightCube(this: bDX9);
    CBaseShader::PI_SetPixelShaderGlintDamping(this: bDX9, nFirstRegister: 1);
    CBaseShader::PI_EndCommandBuffer(this: bDX9);
  }
  else
  {
    v15 = bDX9;
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseShader::BindTexture(
      this: v15,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: (int)*params,
      nFrameVar: (int)params[1]);
    CBaseShader::BindTexture(
      this: v15,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: (int)params[2],
      nFrameVar: (int)params[3]);
    CBaseShader::BindTexture(
      this: v15,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: (int)params[4],
      nFrameVar: -1);
    CBaseVSShader::SetVertexShaderConstant(this: v15, vertexReg: 48, constantVar: (int)params[5]);
    CBaseVSShader::SetVertexShaderConstant(this: v15, vertexReg: 49, constantVar: (int)params[6]);
    CBaseVSShader::SetVertexShaderConstant(this: v15, vertexReg: 50, constantVar: (int)params[7]);
    CBaseVSShader::SetVertexShaderConstant(this: v15, vertexReg: 51, constantVar: (int)params[8]);
    CBaseVSShader::SetVertexShaderConstant(this: v15, vertexReg: 52, constantVar: (int)params[9]);
    CBaseVSShader::SetVertexShaderConstant(this: v15, vertexReg: 53, constantVar: (int)params[10]);
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: (LightState_t *)&v38);
    if ( ((unsigned __int8 (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->HasFastVertexTextures)(
           a1: g_pHardwareConfig,
           a2: v33) != 0 )
    {
      CBaseVSShader::SetHWMorphVertexShaderState(
        this: v15,
        nDimConst: 55,
        nSubrectConst: 56,
        morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      eyes_vs30_Dynamic_Index::eyes_vs30_Dynamic_Index(this: &_vshIndex, pShaderAPI);
      _vshIndex.m_nSKINNING = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v21 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v21 > 0, v31);
      }
      if ( v39 || (v41 = 0, v38 > 0) )
        v41 = 1;
      if ( g_shaderConfigDumpEnable )
      {
        v22 = v39 || v38 > 0;
        printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", v22, "lightState.HasDynamicLight()");
      }
      v42 = BYTE1(v39) != 0;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "STATIC_LIGHT",
          BYTE1(v39) != 0,
          "lightState.m_bStaticLight ? 1 : 0");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", info, "(int)vertexCompression");
      }
      pShaderAPI->SetVertexShaderIndex(
        this: pShaderAPI,
        a2: (int)info
      + 32 * _vshIndex.m_nMORPHING
      + 16 * v42
      + 8 * v41
      + 4 * _vshIndex.m_nDOWATERFOG
      + 2 * _vshIndex.m_nSKINNING);
    }
    else
    {
      bUseStaticControlFlow = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
      v16 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      GetCurrentNumBones = pShaderAPI->GetCurrentNumBones;
      _vshIndex.m_nDOWATERFOG = v16;
      _vshIndex.m_nSKINNING = GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v18 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v18 > 0, v30);
      }
      if ( v39 || (v41 = 0, v38 > 0) )
        v41 = 1;
      if ( g_shaderConfigDumpEnable )
      {
        v19 = v39 || v38 > 0;
        printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", v19, "lightState.HasDynamicLight()");
      }
      v42 = BYTE1(v39) != 0;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "STATIC_LIGHT",
          BYTE1(v39) != 0,
          "lightState.m_bStaticLight ? 1 : 0");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", info, "(int)vertexCompression");
      }
      m_nPIXELFOGTYPE = !bUseStaticControlFlow && v38;
      _pshIndex.m_nPIXELFOGTYPE = m_nPIXELFOGTYPE;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          !bUseStaticControlFlow && v38,
          "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
        m_nPIXELFOGTYPE = _pshIndex.m_nPIXELFOGTYPE;
      }
      pShaderAPI->SetVertexShaderIndex(
        this: pShaderAPI,
        a2: (int)info + 32 * m_nPIXELFOGTYPE + 16 * v42 + 8 * v41 + 4 * _vshIndex.m_nDOWATERFOG + 2 * _vshIndex.m_nSKINNING);
    }
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    vPSConst[0] = pShader[(_DWORD)params[11]]->m_VecVal.x;
    memset(&vPSConst[1], 0, 12);
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: vPSConst, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
    v24 = pShaderAPI->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    v24(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      v26 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    }
    else
    {
      v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      GetSceneFogMode = pShaderAPI->GetSceneFogMode;
      if ( v11 )
      {
        v27 = GetSceneFogMode(this: pShaderAPI);
        pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v27 == 2);
        CBaseShader::Draw(this: v15, bMakeActualDrawCall: true);
        return;
      }
      v26 = GetSceneFogMode(this: pShaderAPI);
    }
    v28 = v26 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA = pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    if ( g_shaderConfigDumpEnable )
    {
      v29 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->ShouldWriteDepthToDestAlpha)(
              a1: pShaderAPI,
              a2: "pShaderAPI->ShouldWriteDepthToDestAlpha()");
      printf(format: "\n   PS dyn  var %s = %d (%s)", "WRITE_DEPTH_TO_DESTALPHA", v29, v32);
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA + 2 * v28);
  }
  CBaseShader::Draw(this: v15, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10012530
// Name: void DrawEyes_DX8_DX9(bool,class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct Eyes_DX8_DX9_Vars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawEyes_DX8_DX9(
        bool bDX9,
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IMaterialVar **pShaderAPI,
        IShaderShadow *pShaderShadow,
        Eyes_DX8_DX9_Vars_t *info,
        Eyes_DX8_DX9_Vars_t *vertexCompression)
{
  if ( pShaderShadow != nullptr )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  if ( CBaseShader::UsingFlashlight(this: pShader, params) )
    DrawFlashlight(
      pShaderShadow,
      bDX9: pShader,
      pShader: params,
      params: pShaderAPI,
      pShaderAPI: info,
      info: vertexCompression);
  else
    DrawUsingVertexShader(
      (IShaderDynamicAPI *)pShaderAPI,
      pShaderShadow,
      bDX9: pShader,
      pShader: params,
      params: (IMaterialVar **)info,
      info: vertexCompression);
}
