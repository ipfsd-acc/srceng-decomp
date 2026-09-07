// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/paintblob_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100209A0
// Name: void InitParamsPaintBlob(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct PaintBlobVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsPaintBlob(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        PaintBlobVars_t *info)
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
  IMaterialVar *v26; // ecx
  IMaterialVar *v27; // ecx
  IMaterialVar *v28; // ecx
  IMaterialVar *v29; // ecx
  IMaterialVar *v30; // ecx
  bool v31; // zf
  void (__thiscall *SetStringValue)(IMaterialVar *, const char *); // eax
  IMaterialVar *v33; // ecx
  IMaterialVar *v34; // ecx
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // ecx
  IMaterialVar *v37; // ecx
  IMaterialVar *v38; // ecx
  IMaterialVar *v39; // ecx

  if ( info->m_nBackSurface != -1 && !params[info->m_nBackSurface]->IsDefined(this: params[info->m_nBackSurface]) )
    params[info->m_nBackSurface]->SetIntValue(this: params[info->m_nBackSurface], a2: 0);
  if ( info->m_nUVScale != -1 )
  {
    v4 = params[info->m_nUVScale];
    if ( !v4->IsDefined(this: v4) )
      ((void (__stdcall *)(int))params[info->m_nUVScale]->SetFloatValue)(a1: 1017370378);
  }
  if ( info->m_nBumpStrength != -1 )
  {
    v5 = params[info->m_nBumpStrength];
    if ( !v5->IsDefined(this: v5) )
      ((void (__stdcall *)(int))params[info->m_nBumpStrength]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nFresnelBumpStrength != -1 )
  {
    v6 = params[info->m_nFresnelBumpStrength];
    if ( !v6->IsDefined(this: v6) )
      ((void (__stdcall *)(int))params[info->m_nFresnelBumpStrength]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nInteriorEnable != -1 )
  {
    v7 = params[info->m_nInteriorEnable];
    if ( !v7->IsDefined(this: v7) )
    {
      v8 = params[info->m_nInteriorEnable];
      v8->SetIntValue(this: v8, a2: 1);
    }
  }
  if ( info->m_nInteriorFogStrength != -1 )
  {
    v9 = params[info->m_nInteriorFogStrength];
    if ( !v9->IsDefined(this: v9) )
      ((void (__stdcall *)(int))params[info->m_nInteriorFogStrength]->SetFloatValue)(a1: 1031127695);
  }
  if ( info->m_nInteriorBackgroundBoost != -1 )
  {
    v10 = params[info->m_nInteriorBackgroundBoost];
    if ( !v10->IsDefined(this: v10) )
      ((void (__stdcall *)(_DWORD))params[info->m_nInteriorBackgroundBoost]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nInteriorAmbientScale != -1 )
  {
    v11 = params[info->m_nInteriorAmbientScale];
    if ( !v11->IsDefined(this: v11) )
      ((void (__stdcall *)(int))params[info->m_nInteriorAmbientScale]->SetFloatValue)(a1: 1050253722);
  }
  if ( info->m_nInteriorBackLightScale != -1 )
  {
    v12 = params[info->m_nInteriorBackLightScale];
    if ( !v12->IsDefined(this: v12) )
      ((void (__stdcall *)(int))params[info->m_nInteriorBackLightScale]->SetFloatValue)(a1: 1050253722);
  }
  if ( info->m_nInteriorRefractStrength != -1 )
  {
    v13 = params[info->m_nInteriorRefractStrength];
    if ( !v13->IsDefined(this: v13) )
      ((void (__stdcall *)(int))params[info->m_nInteriorRefractStrength]->SetFloatValue)(a1: 1014350479);
  }
  if ( info->m_nFresnelParams != -1 )
  {
    v14 = params[info->m_nFresnelParams];
    if ( !v14->IsDefined(this: v14) )
    {
      v15 = params[info->m_nFresnelParams];
      v15->SetVecValue_4(this: v15, a2: kDefaultFresnelParams_1, a3: 3);
    }
  }
  if ( info->m_nBaseColorTint != -1 )
  {
    v16 = params[info->m_nBaseColorTint];
    if ( !v16->IsDefined(this: v16) )
    {
      v17 = params[info->m_nBaseColorTint];
      v17->SetVecValue_4(this: v17, a2: kDefaultBaseColorTint_1, a3: 3);
    }
  }
  if ( info->m_nDiffuseScale != -1 )
  {
    v18 = params[info->m_nDiffuseScale];
    if ( !v18->IsDefined(this: v18) )
      ((void (__stdcall *)(int))params[info->m_nDiffuseScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecExp != -1 )
  {
    v19 = params[info->m_nSpecExp];
    if ( !v19->IsDefined(this: v19) )
      ((void (__stdcall *)(int))params[info->m_nSpecExp]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecScale != -1 )
  {
    v20 = params[info->m_nSpecScale];
    if ( !v20->IsDefined(this: v20) )
      ((void (__stdcall *)(int))params[info->m_nSpecScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecExp2 != -1 )
  {
    v21 = params[info->m_nSpecExp2];
    if ( !v21->IsDefined(this: v21) )
      ((void (__stdcall *)(int))params[info->m_nSpecExp2]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecScale2 != -1 )
  {
    v22 = params[info->m_nSpecScale2];
    if ( !v22->IsDefined(this: v22) )
      ((void (__stdcall *)(int))params[info->m_nSpecScale2]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nRimLightExp != -1 )
  {
    v23 = params[info->m_nRimLightExp];
    if ( !v23->IsDefined(this: v23) )
      ((void (__stdcall *)(int))params[info->m_nRimLightExp]->SetFloatValue)(a1: 1092616192);
  }
  if ( info->m_nRimLightScale != -1 )
  {
    v24 = params[info->m_nRimLightScale];
    if ( !v24->IsDefined(this: v24) )
      ((void (__stdcall *)(int))params[info->m_nRimLightScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nUVProjOffset != -1 )
  {
    v25 = params[info->m_nUVProjOffset];
    if ( !v25->IsDefined(this: v25) )
    {
      v26 = params[info->m_nUVProjOffset];
      v26->SetVecValue_4(this: v26, a2: kDefaultUVProjOffset_1, a3: 3);
    }
  }
  if ( info->m_nBBMin != -1 )
  {
    v27 = params[info->m_nBBMin];
    if ( !v27->IsDefined(this: v27) )
    {
      v28 = params[info->m_nBBMin];
      v28->SetVecValue_4(this: v28, a2: kDefaultBB_1, a3: 3);
    }
  }
  if ( info->m_nBBMax != -1 )
  {
    v29 = params[info->m_nBBMax];
    if ( !v29->IsDefined(this: v29) )
    {
      v30 = params[info->m_nBBMax];
      v30->SetVecValue_4(this: v30, a2: kDefaultBB_1, a3: 3);
    }
  }
  v31 = !g_pHardwareConfig->SupportsBorderColor(this: g_pHardwareConfig);
  SetStringValue = params[info->m_nFlashlightTexture]->SetStringValue;
  if ( v31 )
    ((void (__stdcall *)(const char *))SetStringValue)(a1: "effects/flashlight001");
  else
    ((void (__stdcall *)(const char *))SetStringValue)(a1: "effects/flashlight_border");
  if ( info->m_nFlashlightTextureFrame != -1 )
  {
    v33 = params[info->m_nFlashlightTextureFrame];
    if ( !v33->IsDefined(this: v33) )
    {
      v34 = params[info->m_nFlashlightTextureFrame];
      v34->SetIntValue(this: v34, a2: 0);
    }
  }
  if ( info->m_nBumpFrame != -1 )
  {
    v35 = params[info->m_nBumpFrame];
    if ( !v35->IsDefined(this: v35) )
    {
      v36 = params[info->m_nBumpFrame];
      v36->SetIntValue(this: v36, a2: 0);
    }
  }
  if ( info->m_nContactShadows != -1 )
  {
    v37 = params[info->m_nContactShadows];
    if ( !v37->IsDefined(this: v37) )
    {
      v38 = params[info->m_nContactShadows];
      v38->SetIntValue(this: v38, a2: 0);
    }
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  v39 = params[info->m_nInteriorEnable];
  if ( v39->IsDefined(this: v39) && params[info->m_nInteriorEnable]->m_intVal != 0 )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x8000);
}

//------------------------------------------------------------------------------
// Address: 0x10020EB0
// Name: void InitPaintBlob(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct PaintBlobVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPaintBlob(CBaseVSShader *pShader, IMaterialVar **params, PaintBlobVars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx
  IMaterialVar *v10; // ecx

  if ( info->m_nBaseTexture != -1 )
  {
    v3 = params[info->m_nBaseTexture];
    if ( v3->IsDefined(this: v3) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0x80000);
  }
  if ( info->m_nNormalMap != -1 )
  {
    v4 = params[info->m_nNormalMap];
    if ( v4->IsDefined(this: v4) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nNormalMap, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nSpecMap != -1 )
  {
    v5 = params[info->m_nSpecMap];
    if ( v5->IsDefined(this: v5) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nSpecMap, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nLightWarpTexture != -1 )
  {
    v6 = params[info->m_nLightWarpTexture];
    if ( v6->IsDefined(this: v6) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nLightWarpTexture, nAdditionalCreationFlags: 0x80000);
  }
  if ( info->m_nFresnelWarpTexture != -1 )
  {
    v7 = params[info->m_nFresnelWarpTexture];
    if ( v7->IsDefined(this: v7) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFresnelWarpTexture, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nOpacityTexture != -1 )
  {
    v8 = params[info->m_nOpacityTexture];
    if ( v8->IsDefined(this: v8) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nOpacityTexture, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nEnvMap != -1 )
  {
    v9 = params[info->m_nEnvMap];
    if ( v9->IsDefined(this: v9) )
      CBaseShader::LoadCubeMap(this: pShader, nTextureVar: info->m_nEnvMap, nAdditionalCreationFlags: 0x80000);
  }
  if ( info->m_nFlashlightTexture != -1 )
  {
    v10 = params[info->m_nFlashlightTexture];
    if ( v10->IsDefined(this: v10) )
      CBaseShader::LoadTexture(
        this: pShader,
        nTextureVar: info->m_nFlashlightTexture,
        nAdditionalCreationFlags: 0x80000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020FF0
// Name: void DrawPaintBlob(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct PaintBlobVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawPaintBlob(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        PaintBlobVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  PaintBlobVars_t *v6; // edi
  bool v7; // cc
  IMaterialVar *v8; // ecx
  bool v9; // al
  IMaterialVar *v10; // ecx
  bool v11; // al
  IMaterialVar *v12; // ecx
  bool v13; // al
  int m_nInteriorEnable; // eax
  int m_nContactShadows; // eax
  IMaterialVar *v16; // ecx
  bool v17; // al
  IMaterialVar *v18; // ecx
  bool v19; // al
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  int v22; // eax
  void (__thiscall *GetDX9LightState)(IShaderDynamicAPI *, LightState_t *); // edx
  int v25; // eax
  int v26; // esi
  bool v27; // sf
  IMaterialVar **v28; // esi
  IMaterialVar *v29; // ecx
  float x; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v32; // ecx
  IMaterialVar *v33; // eax
  IMaterialVar *v34; // ecx
  IMaterialVar *v35; // eax
  IMaterialVar *v36; // ecx
  IMaterialVar *v37; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v39; // xmm0_4
  void (__thiscall *v40)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v41)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v42; // al
  float m_flShadowAtten; // xmm0_4
  void (__thiscall *GetBackBufferDimensions)(IShaderDynamicAPI *, int *, int *); // eax
  void (__thiscall *v45)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v46; // ecx
  float v47; // xmm0_4
  float v48; // xmm0_4
  IMaterialVar *v49; // ecx
  float v50; // xmm0_4
  IMaterialVar *v51; // ecx
  float v52; // xmm0_4
  void (__thiscall *v53)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v54; // ecx
  float *v55; // eax
  void (__thiscall *v56)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v57; // ecx
  float v58; // xmm0_4
  IMaterialVar *v59; // ecx
  float v60; // xmm0_4
  IMaterialVar *v61; // ecx
  float v62; // xmm0_4
  IMaterialVar *v63; // ecx
  float v64; // xmm0_4
  void (__thiscall *v65)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v66; // ecx
  float v67; // xmm0_4
  IMaterialVar *v68; // ecx
  float v69; // xmm0_4
  IMaterialVar *v70; // ecx
  float v71; // xmm0_4
  IMaterialVar *v72; // ecx
  float v73; // xmm0_4
  void (__thiscall *v74)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v75; // ecx
  float v76; // xmm0_4
  void (__thiscall *v77)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v78; // xmm0_4
  void (__thiscall *v79)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v80; // ecx
  float *v81; // eax
  IMaterialVar *v82; // ecx
  float v83; // xmm0_4
  void (__thiscall *v84)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v85; // edi
  const char *v86; // [esp+1A8h] [ebp-1E8h]
  const char *v87; // [esp+1A8h] [ebp-1E8h]
  VMatrix worldToTexture; // [esp+1B8h] [ebp-1D8h] BYREF
  FlashlightState_t state; // [esp+1F8h] [ebp-198h]
  float pos[4]; // [esp+2F4h] [ebp-9Ch] BYREF
  float v91[4]; // [esp+304h] [ebp-8Ch] BYREF
  float atten[4]; // [esp+314h] [ebp-7Ch] BYREF
  ITexture *pFlashlightDepthTexture; // [esp+324h] [ebp-6Ch] BYREF
  int nTexHeight; // [esp+328h] [ebp-68h] BYREF
  int nHeight; // [esp+32Ch] [ebp-64h] BYREF
  int nTexWidth; // [esp+330h] [ebp-60h] BYREF
  int nWidth; // [esp+334h] [ebp-5Ch] BYREF
  float tweaks[4]; // [esp+338h] [ebp-58h]
  float v99; // [esp+348h] [ebp-48h] BYREF
  BOOL v100; // [esp+34Ch] [ebp-44h]
  float fU; // [esp+350h] [ebp-40h] BYREF
  float fV; // [esp+354h] [ebp-3Ch] BYREF
  LightState_t lightState; // [esp+358h] [ebp-38h] BYREF
  float v104; // [esp+360h] [ebp-30h] BYREF
  paintblob_ps20b_Dynamic_Index _pshIndex; // [esp+364h] [ebp-2Ch]
  bool bEnvMap; // [esp+373h] [ebp-1Dh]
  bool bInteriorLayer; // [esp+374h] [ebp-1Ch]
  bool bSpecMap; // [esp+375h] [ebp-1Bh]
  bool bBackSurface; // [esp+376h] [ebp-1Ah]
  bool bLightWarp; // [esp+377h] [ebp-19h]
  bool bFlattenStaticControlFlow; // [esp+378h] [ebp-18h]
  bool bContactShadows; // [esp+379h] [ebp-17h]
  bool bFresnelWarp; // [esp+37Ah] [ebp-16h]
  bool bOpacityTexture; // [esp+37Bh] [ebp-15h]
  float flConsts[4]; // [esp+37Ch] [ebp-14h] BYREF
  bool bHasFlashlight; // [esp+38Fh] [ebp-1h]
  float pShaderAPIa; // [esp+3A0h] [ebp+10h]
  ShadowFilterMode_t bFlashlightShadows; // [esp+3A4h] [ebp+14h]
  bool bFlashlightShadows_3; // [esp+3A7h] [ebp+17h]

  v6 = info;
  bHasFlashlight = CBaseShader::UsingFlashlight(this: pShader, params);
  if ( info->m_nBackSurface == -1 || (v7 = params[info->m_nBackSurface]->m_intVal <= 0, bBackSurface = true, v7) )
    bBackSurface = false;
  if ( info->m_nLightWarpTexture == -1
    || (v8 = params[info->m_nLightWarpTexture], v9 = v8->IsDefined(this: v8), bLightWarp = true, !v9) )
  {
    bLightWarp = false;
  }
  if ( info->m_nFresnelWarpTexture == -1
    || (v10 = params[info->m_nFresnelWarpTexture], v11 = v10->IsDefined(this: v10), bFresnelWarp = true, !v11) )
  {
    bFresnelWarp = false;
  }
  if ( info->m_nOpacityTexture == -1
    || (v12 = params[info->m_nOpacityTexture], v13 = v12->IsDefined(this: v12), bOpacityTexture = true, !v13) )
  {
    bOpacityTexture = false;
  }
  m_nInteriorEnable = info->m_nInteriorEnable;
  if ( m_nInteriorEnable == -1 || (v7 = params[m_nInteriorEnable]->m_intVal <= 0, bInteriorLayer = true, v7) )
    bInteriorLayer = false;
  m_nContactShadows = info->m_nContactShadows;
  if ( m_nContactShadows == -1 || (v7 = params[m_nContactShadows]->m_intVal <= 0, bContactShadows = true, v7) )
    bContactShadows = false;
  if ( info->m_nSpecMap == -1
    || (v16 = params[info->m_nSpecMap], v17 = v16->IsDefined(this: v16), bSpecMap = true, !v17) )
  {
    bSpecMap = false;
  }
  if ( info->m_nEnvMap == -1 || (v18 = params[info->m_nEnvMap], v19 = v18->IsDefined(this: v18), bEnvMap = true, !v19) )
    bEnvMap = false;
  bFlattenStaticControlFlow = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
  if ( pShaderShadow != nullptr )
  {
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    LODWORD(flConsts[0]) = 4;
    LODWORD(flConsts[1]) = 4;
    LODWORD(flConsts[2]) = 4;
    LODWORD(flConsts[3]) = 4;
    VertexShaderVertexFormat(this: pShaderShadow, a2: 3u, a3: 1, a4: (int *)flConsts, a5: 0);
    bFlashlightShadows = SHADOWFILTERMODE_DEFAULT;
    if ( bHasFlashlight )
      bFlashlightShadows = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: true);
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS stat var %s = %d (%s)",
        "FLATTEN_STATIC_CONTROL_FLOW",
        bFlattenStaticControlFlow,
        "bFlattenStaticControlFlow");
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "paintblob_vs20", a3: 12 * bFlattenStaticControlFlow);
    LODWORD(tweaks[0]) = bBackSurface;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "BACK_SURFACE", bBackSurface, "bBackSurface");
    LODWORD(tweaks[1]) = bLightWarp;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "LIGHT_WARP", bLightWarp, "bLightWarp");
    LODWORD(tweaks[2]) = bFresnelWarp;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "FRESNEL_WARP", bFresnelWarp, "bFresnelWarp");
    v100 = bOpacityTexture;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "OPACITY_TEXTURE", bOpacityTexture, "bOpacityTexture");
    LODWORD(v99) = bInteriorLayer;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "INTERIOR_LAYER", bInteriorLayer, "bInteriorLayer");
    LODWORD(tweaks[3]) = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_FLOAT;
    if ( g_shaderConfigDumpEnable )
    {
      v22 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
              a1: g_pHardwareConfig,
              a2: "(g_pHardwareConfig->GetHDRType() == HDR_TYPE_FLOAT) ? true : false");
      printf(format: "\n   PS stat var %s = %d (%s)", "HIGH_PRECISION_DEPTH", v22 == 2, v86);
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FLASHLIGHTDEPTHFILTERMODE",
          bFlashlightShadows,
          "nShadowFilterMode");
    }
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "CONTACT_SHADOW", bContactShadows, "bContactShadows");
    pShaderShadow->SetPixelShader(
      this: pShaderShadow,
      a2: "paintblob_ps20b",
      a3: 20
    * (LODWORD(tweaks[0])
     + 2
     * (LODWORD(tweaks[1])
      + 2
      * (LODWORD(tweaks[2])
       + 2 * (LODWORD(tweaks[3]) + 2 * (LODWORD(v99) + 2 * (v100 + 2 * (bFlashlightShadows + 4 * bContactShadows))))))));
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
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: false);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: true);
    if ( bHasFlashlight )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER8, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER8, a3: false);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER9, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER9, a3: false);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER10, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER10, a3: true);
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    CBaseShader::PI_SetVertexShaderAmbientLightCube(this: pShader);
    CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 4);
    CBaseShader::PI_SetPixelShaderLocalLighting(this: pShader, nFirstRegister: 20);
    CBaseShader::PI_EndCommandBuffer(this: pShader);
  }
  if ( pShaderAPI != nullptr )
  {
    GetDX9LightState = pShaderAPI->GetDX9LightState;
    lightState.m_nNumLights = 0;
    *(_WORD *)&lightState.m_bAmbientLight = 0;
    GetDX9LightState(this: pShaderAPI, a2: &lightState);
    _pshIndex.m_nFLASHLIGHT = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v25 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v25 > 0, v87);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    v26 = bFlattenStaticControlFlow ? lightState.m_nNumLights : 0;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        bFlattenStaticControlFlow ? lightState.m_nNumLights : 0,
        "bFlattenStaticControlFlow ? lightState.m_nNumLights : 0");
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * (_pshIndex.m_nFLASHLIGHT + 2 * v26));
    v27 = info->m_nUVScale < 0;
    v28 = params;
    memset(flConsts, 0, sizeof(flConsts));
    if ( v27 || (v29 = params[info->m_nUVScale], !v29->IsDefined(this: v29)) )
      x = 0.02;
    else
      x = params[info->m_nUVScale]->m_VecVal.x;
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    flConsts[0] = x;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: flConsts, a4: 1, a5: false);
    if ( info->m_nUVProjOffset >= 0 && (v32 = params[info->m_nUVProjOffset], v32->IsDefined(this: v32)) )
    {
      v33 = params[info->m_nUVProjOffset];
      flConsts[0] = v33->m_VecVal.x;
      flConsts[1] = v33->m_VecVal.y;
      flConsts[2] = v33->m_VecVal.z;
    }
    else
    {
      memset(flConsts, 0, 12);
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 49, a3: flConsts, a4: 1, a5: false);
    if ( info->m_nBBMin >= 0 && (v34 = params[info->m_nBBMin], v34->IsDefined(this: v34)) )
    {
      v35 = params[info->m_nBBMin];
      flConsts[0] = v35->m_VecVal.x;
      flConsts[1] = v35->m_VecVal.y;
      flConsts[2] = v35->m_VecVal.z;
    }
    else
    {
      memset(flConsts, 0, 12);
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 50, a3: flConsts, a4: 1, a5: false);
    if ( info->m_nBBMax >= 0 && (v36 = params[info->m_nBBMax], v36->IsDefined(this: v36)) )
    {
      v37 = params[info->m_nBBMax];
      flConsts[0] = v37->m_VecVal.x;
      flConsts[1] = v37->m_VecVal.y;
      flConsts[2] = v37->m_VecVal.z;
    }
    else
    {
      memset(flConsts, 0, 12);
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 51, a3: flConsts, a4: 1, a5: false);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: 6,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nNormalMap,
      nFrameVar: info->m_nBumpFrame);
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER2,
      a3: TEXTURE_BINDFLAGS_SRGBREAD,
      a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    if ( bSpecMap )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER3,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: info->m_nSpecMap,
        nFrameVar: -1);
    else
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER3,
        a3: TEXTURE_BINDFLAGS_NONE,
        a4: TEXTURE_WHITE);
    if ( bLightWarp )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER4,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: info->m_nLightWarpTexture,
        nFrameVar: -1);
    if ( bFresnelWarp )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER5,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: info->m_nFresnelWarpTexture,
        nFrameVar: -1);
    if ( bOpacityTexture )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER6,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: info->m_nOpacityTexture,
        nFrameVar: -1);
    if ( bEnvMap )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER7,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: info->m_nEnvMap,
        nFrameVar: -1);
    else
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER7,
        a3: TEXTURE_BINDFLAGS_NONE,
        a4: TEXTURE_BLACK);
    bFlashlightShadows_3 = false;
    if ( bHasFlashlight )
    {
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER10,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: info->m_nFlashlightTexture,
        nFrameVar: info->m_nFlashlightTextureFrame);
      state = *pShaderAPI->GetFlashlightStateEx(this: pShaderAPI, a2: &worldToTexture, a3: &pFlashlightDepthTexture);
      bFlashlightShadows_3 = state.m_bEnableShadows;
      pShaderAPIa = r_flashlightbrightness.m_pParent->m_Value.m_fValue;
      if ( !g_pHardwareConfig->GetHDREnabled(this: g_pHardwareConfig) )
        pShaderAPIa = 2.0;
      g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
      SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
      v39 = state.m_fBrightnessScale * (float)(pShaderAPIa * 2.5);
      v91[0] = state.m_Color[0] * v39;
      v91[1] = state.m_Color[1] * v39;
      v91[2] = state.m_Color[2] * v39;
      v91[3] = 0.0;
      SetPixelShaderConstant(this: pShaderAPI, a2: 28, a3: v91, a4: 1, a5: false);
      if ( pFlashlightDepthTexture != nullptr && g_pConfig->m_bShadowDepthTexture && state.m_bEnableShadows )
      {
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER8,
          nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
          pTexture: pFlashlightDepthTexture,
          nFrame: 0);
        pShaderAPI->BindStandardTexture(
          this: pShaderAPI,
          a2: SHADER_SAMPLER9,
          a3: TEXTURE_BINDFLAGS_NONE,
          a4: TEXTURE_SHADOW_NOISE_2D);
      }
      v40 = pShaderAPI->SetPixelShaderConstant;
      atten[0] = state.m_fConstantAtten;
      atten[1] = state.m_fLinearAtten;
      atten[2] = state.m_fQuadraticAtten;
      atten[3] = state.m_FarZAtten;
      v40(this: pShaderAPI, a2: 13, a3: atten, a4: 1, a5: false);
      v41 = pShaderAPI->SetPixelShaderConstant;
      *(Vector *)pos = state.m_vecLightOrigin;
      pos[3] = state.m_FarZ;
      v41(this: pShaderAPI, a2: 14, a3: pos, a4: 1, a5: false);
      pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 15, a3: (const float *)&worldToTexture, a4: 4, a5: false);
      v99 = state.m_flShadowFilterSize * 0.0009765625;
      v42 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
      m_flShadowAtten = state.m_flShadowAtten;
      if ( v42 )
        m_flShadowAtten = state.m_flShadowAtten * 0.1;
      v100 = LODWORD(m_flShadowAtten);
      CBaseVSShader::HashShadow2DJitter(this: pShader, fJitterSeed: state.m_flShadowJitterSeed, &fU, &fV);
      pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 2, a3: &v99, a4: 1, a5: false);
      GetBackBufferDimensions = pShaderAPI->GetBackBufferDimensions;
      v104 = 40.0;
      _pshIndex.m_nNUM_LIGHTS = 1102315520;
      _pshIndex.m_nFLASHLIGHT = 0;
      _pshIndex.m_nFLASHLIGHTSHADOWS = 0;
      GetBackBufferDimensions(this: pShaderAPI, a2: &nWidth, a3: &nHeight);
      pShaderAPI->GetStandardTextureDimensions(
        this: pShaderAPI,
        a2: &nTexWidth,
        a3: &nTexHeight,
        a4: TEXTURE_SHADOW_NOISE_2D);
      v45 = pShaderAPI->SetPixelShaderConstant;
      v104 = (float)nWidth / (float)nTexWidth;
      *(float *)&_pshIndex.m_nNUM_LIGHTS = (float)nHeight / (float)nTexHeight;
      *(float *)&_pshIndex.m_nFLASHLIGHT = 1.0 / state.m_flShadowMapResolution;
      *(float *)&_pshIndex.m_nFLASHLIGHTSHADOWS = (float)(1.0 / state.m_flShadowMapResolution) * 2.0;
      v45(this: pShaderAPI, a2: 31, a3: &v104, a4: 1, a5: false);
      v6 = info;
      v28 = params;
    }
    if ( v6->m_nBumpStrength >= 0 && (v46 = v28[v6->m_nBumpStrength], v46->IsDefined(this: v46)) )
      v47 = v28[v6->m_nBumpStrength]->m_VecVal.x;
    else
      v47 = 1.0;
    flConsts[0] = v47;
    if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_FLOAT )
      v48 = 8192.0;
    else
      v48 = 192.0;
    v27 = v6->m_nInteriorFogStrength < 0;
    flConsts[1] = v48;
    if ( v27 || (v49 = v28[v6->m_nInteriorFogStrength], !v49->IsDefined(this: v49)) )
      v50 = 0.059999999;
    else
      v50 = v28[v6->m_nInteriorFogStrength]->m_VecVal.x;
    v27 = v6->m_nInteriorRefractStrength < 0;
    flConsts[2] = v50;
    if ( v27 || (v51 = v28[v6->m_nInteriorRefractStrength], !v51->IsDefined(this: v51)) )
      v52 = 0.015;
    else
      v52 = v28[v6->m_nInteriorRefractStrength]->m_VecVal.x;
    v53 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v52;
    v53(this: pShaderAPI, a2: 0, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nFresnelParams >= 0 && (v54 = v28[v6->m_nFresnelParams], v54->IsDefined(this: v54)) )
    {
      v55 = (float *)v28[v6->m_nFresnelParams];
      flConsts[0] = v55[3];
      flConsts[1] = v55[4];
      flConsts[2] = v55[5];
    }
    else
    {
      *(_QWORD *)flConsts = *(_QWORD *)kDefaultFresnelParams_1;
      flConsts[2] = 2.0;
    }
    v56 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v28[v6->m_nInteriorBackgroundBoost]->m_VecVal.x;
    v56(this: pShaderAPI, a2: 1, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nRimLightExp >= 0 && (v57 = v28[v6->m_nRimLightExp], v57->IsDefined(this: v57)) )
      v58 = v28[v6->m_nRimLightExp]->m_VecVal.x;
    else
      v58 = 10.0;
    v27 = v6->m_nRimLightScale < 0;
    flConsts[0] = v58;
    if ( v27 || (v59 = v28[v6->m_nRimLightScale], !v59->IsDefined(this: v59)) )
      v60 = 1.0;
    else
      v60 = v28[v6->m_nRimLightScale]->m_VecVal.x;
    v27 = v6->m_nSpecScale < 0;
    flConsts[1] = v60;
    if ( v27 || (v61 = v28[v6->m_nSpecScale], !v61->IsDefined(this: v61)) )
      v62 = 1.0;
    else
      v62 = v28[v6->m_nSpecScale]->m_VecVal.x;
    v27 = v6->m_nSpecExp2 < 0;
    flConsts[2] = v62;
    if ( v27 || (v63 = v28[v6->m_nSpecExp2], !v63->IsDefined(this: v63)) )
      v64 = 1.0;
    else
      v64 = v28[v6->m_nSpecExp2]->m_VecVal.x;
    v65 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v64;
    v65(this: pShaderAPI, a2: 3, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nSpecScale2 >= 0 && (v66 = v28[v6->m_nSpecScale2], v66->IsDefined(this: v66)) )
      v67 = v28[v6->m_nSpecScale2]->m_VecVal.x;
    else
      v67 = 1.0;
    v27 = v6->m_nFresnelBumpStrength < 0;
    flConsts[0] = v67;
    if ( v27 || (v68 = v28[v6->m_nFresnelBumpStrength], !v68->IsDefined(this: v68)) )
      v69 = 1.0;
    else
      v69 = v28[v6->m_nFresnelBumpStrength]->m_VecVal.x;
    v27 = v6->m_nDiffuseScale < 0;
    flConsts[1] = v69;
    if ( v27 || (v70 = v28[v6->m_nDiffuseScale], !v70->IsDefined(this: v70)) )
      v71 = 1.0;
    else
      v71 = v28[v6->m_nDiffuseScale]->m_VecVal.x;
    v27 = v6->m_nInteriorAmbientScale < 0;
    flConsts[2] = v71;
    if ( v27 || (v72 = v28[v6->m_nInteriorAmbientScale], !v72->IsDefined(this: v72)) )
      v73 = 0.30000001;
    else
      v73 = v28[v6->m_nInteriorAmbientScale]->m_VecVal.x;
    v74 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v73;
    v74(this: pShaderAPI, a2: 10, a3: flConsts, a4: 1, a5: false);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: flConsts);
    if ( v6->m_nSpecExp >= 0 && (v75 = v28[v6->m_nSpecExp], v75->IsDefined(this: v75)) )
      v76 = v28[v6->m_nSpecExp]->m_VecVal.x;
    else
      v76 = 1.0;
    v77 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v76;
    v77(this: pShaderAPI, a2: 11, a3: flConsts, a4: 1, a5: false);
    if ( pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI) )
      v78 = 1.0;
    else
      v78 = 0.0;
    v79 = pShaderAPI->SetPixelShaderConstant;
    flConsts[0] = v78;
    v79(this: pShaderAPI, a2: 12, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nBaseColorTint >= 0 && (v80 = v28[v6->m_nBaseColorTint], v80->IsDefined(this: v80)) )
    {
      v81 = (float *)v28[v6->m_nBaseColorTint];
      flConsts[0] = v81[3];
      flConsts[1] = v81[4];
      flConsts[2] = v81[5];
    }
    else
    {
      *(_QWORD *)flConsts = *(_QWORD *)kDefaultBaseColorTint_1;
      flConsts[2] = 1.0;
    }
    if ( v6->m_nInteriorBackLightScale >= 0 && (v82 = v28[v6->m_nInteriorBackLightScale], v82->IsDefined(this: v82)) )
      v83 = v28[v6->m_nInteriorBackLightScale]->m_VecVal.x;
    else
      v83 = 0.30000001;
    v84 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v83;
    v84(this: pShaderAPI, a2: 19, a3: flConsts, a4: 1, a5: false);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      _pshIndex.m_nNUM_LIGHTS = lightState.m_nNumLights;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          lightState.m_nNumLights,
          "lightState.m_nNumLights");
      v85 = bHasFlashlight;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHT", bHasFlashlight, "bHasFlashlight");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", bFlashlightShadows_3, "bFlashlightShadows");
      pShaderAPI->SetPixelShaderIndex(
        this: pShaderAPI,
        a2: v85 + 2 * bFlashlightShadows_3 + _pshIndex.m_nNUM_LIGHTS + 4 * (v85 + 2 * bFlashlightShadows_3));
    }
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
