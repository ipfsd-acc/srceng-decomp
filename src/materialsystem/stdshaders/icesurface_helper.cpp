// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/icesurface_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10015420
// Name: void InitParamsIceSurface(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct IceSurfaceVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsIceSurface(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        IceSurfaceVars_t *info)
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
  IMaterialVar *v31; // ecx
  IMaterialVar *v32; // ecx
  IMaterialVar *v33; // ecx
  IMaterialVar *v34; // ecx
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // ecx
  IMaterialVar *v37; // ecx
  bool v38; // zf
  void (__thiscall *SetStringValue)(IMaterialVar *, const char *); // eax
  IMaterialVar *v40; // ecx
  IMaterialVar *v41; // ecx
  IMaterialVar *v42; // ecx
  IMaterialVar *v43; // ecx
  IMaterialVar *v44; // ecx
  IMaterialVar *v45; // ecx
  IMaterialVar *v46; // ecx

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
  if ( info->m_nInteriorFogLimit != -1 )
  {
    v10 = params[info->m_nInteriorFogLimit];
    if ( !v10->IsDefined(this: v10) )
      ((void (__stdcall *)(int))params[info->m_nInteriorFogLimit]->SetFloatValue)(a1: 1061997773);
  }
  if ( info->m_nInteriorFogNormalBoost != -1 )
  {
    v11 = params[info->m_nInteriorFogNormalBoost];
    if ( !v11->IsDefined(this: v11) )
      ((void (__stdcall *)(_DWORD))params[info->m_nInteriorFogNormalBoost]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nInteriorBackgroundBoost != -1 )
  {
    v12 = params[info->m_nInteriorBackgroundBoost];
    if ( !v12->IsDefined(this: v12) )
      ((void (__stdcall *)(_DWORD))params[info->m_nInteriorBackgroundBoost]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nInteriorAmbientScale != -1 )
  {
    v13 = params[info->m_nInteriorAmbientScale];
    if ( !v13->IsDefined(this: v13) )
      ((void (__stdcall *)(int))params[info->m_nInteriorAmbientScale]->SetFloatValue)(a1: 1050253722);
  }
  if ( info->m_nInteriorBackLightScale != -1 )
  {
    v14 = params[info->m_nInteriorBackLightScale];
    if ( !v14->IsDefined(this: v14) )
      ((void (__stdcall *)(int))params[info->m_nInteriorBackLightScale]->SetFloatValue)(a1: 1050253722);
  }
  if ( info->m_nInteriorColor != -1 )
  {
    v15 = params[info->m_nInteriorColor];
    if ( !v15->IsDefined(this: v15) )
    {
      v16 = params[info->m_nInteriorColor];
      v16->SetVecValue_4(this: v16, a2: kDefaultInteriorColor_0, a3: 3);
    }
  }
  if ( info->m_nInteriorRefractStrength != -1 )
  {
    v17 = params[info->m_nInteriorRefractStrength];
    if ( !v17->IsDefined(this: v17) )
      ((void (__stdcall *)(int))params[info->m_nInteriorRefractStrength]->SetFloatValue)(a1: 1014350479);
  }
  if ( info->m_nInteriorRefractBlur != -1 )
  {
    v18 = params[info->m_nInteriorRefractBlur];
    if ( !v18->IsDefined(this: v18) )
      ((void (__stdcall *)(int))params[info->m_nInteriorRefractBlur]->SetFloatValue)(a1: 1045220557);
  }
  if ( info->m_nFresnelParams != -1 )
  {
    v19 = params[info->m_nFresnelParams];
    if ( !v19->IsDefined(this: v19) )
    {
      v20 = params[info->m_nFresnelParams];
      v20->SetVecValue_4(this: v20, a2: kDefaultFresnelParams_0, a3: 3);
    }
  }
  if ( info->m_nBaseColorTint != -1 )
  {
    v21 = params[info->m_nBaseColorTint];
    if ( !v21->IsDefined(this: v21) )
    {
      v22 = params[info->m_nBaseColorTint];
      v22->SetVecValue_4(this: v22, a2: kDefaultBaseColorTint_0, a3: 3);
    }
  }
  if ( info->m_nEnvMapTint != -1 )
  {
    v23 = params[info->m_nEnvMapTint];
    if ( !v23->IsDefined(this: v23) )
    {
      v24 = params[info->m_nEnvMapTint];
      v24->SetVecValue_4(this: v24, a2: kDefaultEnvMapTint, a3: 3);
    }
  }
  if ( info->m_nDiffuseScale != -1 )
  {
    v25 = params[info->m_nDiffuseScale];
    if ( !v25->IsDefined(this: v25) )
      ((void (__stdcall *)(int))params[info->m_nDiffuseScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecExp != -1 )
  {
    v26 = params[info->m_nSpecExp];
    if ( !v26->IsDefined(this: v26) )
      ((void (__stdcall *)(int))params[info->m_nSpecExp]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecScale != -1 )
  {
    v27 = params[info->m_nSpecScale];
    if ( !v27->IsDefined(this: v27) )
      ((void (__stdcall *)(int))params[info->m_nSpecScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecExp2 != -1 )
  {
    v28 = params[info->m_nSpecExp2];
    if ( !v28->IsDefined(this: v28) )
      ((void (__stdcall *)(int))params[info->m_nSpecExp2]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecScale2 != -1 )
  {
    v29 = params[info->m_nSpecScale2];
    if ( !v29->IsDefined(this: v29) )
      ((void (__stdcall *)(int))params[info->m_nSpecScale2]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nRimLightExp != -1 )
  {
    v30 = params[info->m_nRimLightExp];
    if ( !v30->IsDefined(this: v30) )
      ((void (__stdcall *)(int))params[info->m_nRimLightExp]->SetFloatValue)(a1: 1092616192);
  }
  if ( info->m_nRimLightScale != -1 )
  {
    v31 = params[info->m_nRimLightScale];
    if ( !v31->IsDefined(this: v31) )
      ((void (__stdcall *)(int))params[info->m_nRimLightScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nUVProjOffset != -1 )
  {
    v32 = params[info->m_nUVProjOffset];
    if ( !v32->IsDefined(this: v32) )
    {
      v33 = params[info->m_nUVProjOffset];
      v33->SetVecValue_4(this: v33, a2: kDefaultUVProjOffset_0, a3: 3);
    }
  }
  if ( info->m_nBBMin != -1 )
  {
    v34 = params[info->m_nBBMin];
    if ( !v34->IsDefined(this: v34) )
    {
      v35 = params[info->m_nBBMin];
      v35->SetVecValue_4(this: v35, a2: kDefaultBB_0, a3: 3);
    }
  }
  if ( info->m_nBBMax != -1 )
  {
    v36 = params[info->m_nBBMax];
    if ( !v36->IsDefined(this: v36) )
    {
      v37 = params[info->m_nBBMax];
      v37->SetVecValue_4(this: v37, a2: kDefaultBB_0, a3: 3);
    }
  }
  v38 = !g_pHardwareConfig->SupportsBorderColor(this: g_pHardwareConfig);
  SetStringValue = params[info->m_nFlashlightTexture]->SetStringValue;
  if ( v38 )
    ((void (__stdcall *)(const char *))SetStringValue)(a1: "effects/flashlight001");
  else
    ((void (__stdcall *)(const char *))SetStringValue)(a1: "effects/flashlight_border");
  if ( info->m_nFlashlightTextureFrame != -1 )
  {
    v40 = params[info->m_nFlashlightTextureFrame];
    if ( !v40->IsDefined(this: v40) )
    {
      v41 = params[info->m_nFlashlightTextureFrame];
      v41->SetIntValue(this: v41, a2: 0);
    }
  }
  if ( info->m_nBumpFrame != -1 )
  {
    v42 = params[info->m_nBumpFrame];
    if ( !v42->IsDefined(this: v42) )
    {
      v43 = params[info->m_nBumpFrame];
      v43->SetIntValue(this: v43, a2: 0);
    }
  }
  if ( info->m_nContactShadows != -1 )
  {
    v44 = params[info->m_nContactShadows];
    if ( !v44->IsDefined(this: v44) )
    {
      v45 = params[info->m_nContactShadows];
      v45->SetIntValue(this: v45, a2: 0);
    }
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  v46 = params[info->m_nInteriorEnable];
  if ( v46->IsDefined(this: v46) && params[info->m_nInteriorEnable]->m_intVal != 0 )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x8000);
}

//------------------------------------------------------------------------------
// Address: 0x10015A30
// Name: void InitIceSurface(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct IceSurfaceVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitIceSurface(CBaseVSShader *pShader, IMaterialVar **params, IceSurfaceVars_t *info)
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
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0);
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
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nLightWarpTexture, nAdditionalCreationFlags: 0);
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
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nEnvMap, nAdditionalCreationFlags: 0);
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
// Address: 0x10015B70
// Name: void DrawIceSurface(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct IceSurfaceVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawIceSurface(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        IceSurfaceVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  IceSurfaceVars_t *v6; // edi
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
  ShadowFilterMode_t v22; // ebx
  int v23; // eax
  BOOL v25; // esi
  int v26; // eax
  void (__thiscall *GetDX9LightState)(IShaderDynamicAPI *, LightState_t *); // edx
  bool v28; // sf
  IMaterialVar **v29; // esi
  IMaterialVar *v30; // ecx
  float x; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v33; // ecx
  IMaterialVar *v34; // eax
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // eax
  IMaterialVar *v37; // ecx
  IMaterialVar *v38; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v40; // xmm0_4
  void (__thiscall *v41)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v42)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v43; // al
  float m_flShadowAtten; // xmm0_4
  void (__thiscall *GetBackBufferDimensions)(IShaderDynamicAPI *, int *, int *); // eax
  void (__thiscall *v46)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v47; // ecx
  float v48; // xmm0_4
  float v49; // xmm0_4
  IMaterialVar *v50; // ecx
  float v51; // xmm0_4
  IMaterialVar *v52; // ecx
  float v53; // xmm0_4
  void (__thiscall *v54)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v55; // ecx
  float *v56; // eax
  void (__thiscall *v57)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v58; // ecx
  float v59; // xmm0_4
  IMaterialVar *v60; // ecx
  float v61; // xmm0_4
  IMaterialVar *v62; // ecx
  float v63; // xmm0_4
  IMaterialVar *v64; // ecx
  float v65; // xmm0_4
  void (__thiscall *v66)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v67; // ecx
  float v68; // xmm0_4
  IMaterialVar *v69; // ecx
  float v70; // xmm0_4
  IMaterialVar *v71; // ecx
  float v72; // xmm0_4
  IMaterialVar *v73; // ecx
  float v74; // xmm0_4
  void (__thiscall *v75)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v76; // ecx
  float v77; // xmm0_4
  void (__thiscall *v78)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v79; // xmm0_4
  void (__thiscall *v80)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v81; // ecx
  float *v82; // eax
  IMaterialVar *v83; // ecx
  float v84; // xmm0_4
  void (__thiscall *v85)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v86; // ecx
  float *v87; // eax
  void (__thiscall *v88)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v89; // ecx
  float v90; // xmm0_4
  int m_nInteriorFogNormalBoost; // eax
  void (__thiscall *v92)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v93; // ecx
  float *v94; // esi
  BOOL v95; // edi
  const char *v96; // [esp+1A8h] [ebp-224h]
  const char *v97; // [esp+1A8h] [ebp-224h]
  float mView[16]; // [esp+1B8h] [ebp-214h] BYREF
  VMatrix worldToTexture; // [esp+1F8h] [ebp-1D4h] BYREF
  FlashlightState_t state; // [esp+238h] [ebp-194h]
  float pos[4]; // [esp+334h] [ebp-98h] BYREF
  float v102[4]; // [esp+344h] [ebp-88h] BYREF
  float atten[4]; // [esp+354h] [ebp-78h] BYREF
  int nWidth; // [esp+364h] [ebp-68h] BYREF
  int nTexHeight; // [esp+368h] [ebp-64h] BYREF
  int nHeight; // [esp+36Ch] [ebp-60h] BYREF
  ITexture *pFlashlightDepthTexture; // [esp+370h] [ebp-5Ch] BYREF
  int nTexWidth; // [esp+374h] [ebp-58h] BYREF
  float tweaks[4]; // [esp+378h] [ebp-54h]
  float v110; // [esp+388h] [ebp-44h] BYREF
  BOOL v111; // [esp+38Ch] [ebp-40h]
  float fU; // [esp+390h] [ebp-3Ch] BYREF
  float fV; // [esp+394h] [ebp-38h] BYREF
  icesurface_ps30_Dynamic_Index _pshIndex; // [esp+398h] [ebp-34h] BYREF
  int v115; // [esp+3A4h] [ebp-28h]
  LightState_t lightState; // [esp+3A8h] [ebp-24h] BYREF
  bool bEnvMap; // [esp+3B0h] [ebp-1Ch]
  bool bSpecMap; // [esp+3B1h] [ebp-1Bh]
  bool bInteriorLayer; // [esp+3B2h] [ebp-1Ah]
  bool bBackSurface; // [esp+3B3h] [ebp-19h]
  bool bContactShadows; // [esp+3B4h] [ebp-18h]
  bool bLightWarp; // [esp+3B5h] [ebp-17h]
  bool bOpacityTexture; // [esp+3B6h] [ebp-16h]
  bool bFresnelWarp; // [esp+3B7h] [ebp-15h]
  float flConsts[4]; // [esp+3B8h] [ebp-14h] BYREF
  bool bHasFlashlight; // [esp+3CBh] [ebp-1h]
  float pShaderAPIa; // [esp+3DCh] [ebp+10h]
  ShadowFilterMode_t bFlashlightShadows; // [esp+3E0h] [ebp+14h]
  bool bFlashlightShadows_3; // [esp+3E3h] [ebp+17h]

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
  if ( pShaderShadow != nullptr )
  {
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    LODWORD(flConsts[0]) = 4;
    LODWORD(flConsts[1]) = 4;
    LODWORD(flConsts[2]) = 4;
    LODWORD(flConsts[3]) = 4;
    VertexShaderVertexFormat(this: pShaderShadow, a2: 3u, a3: 1, a4: (int *)flConsts, a5: 0);
    v22 = SHADOWFILTERMODE_DEFAULT;
    bFlashlightShadows = SHADOWFILTERMODE_DEFAULT;
    if ( bHasFlashlight )
    {
      v22 = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: true);
      bFlashlightShadows = v22;
    }
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "icesurface_vs30", a3: 0);
    LODWORD(tweaks[0]) = bBackSurface;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "BACK_SURFACE", bBackSurface, "bBackSurface");
    LODWORD(tweaks[1]) = bLightWarp;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "LIGHT_WARP", bLightWarp, "bLightWarp");
    LODWORD(tweaks[2]) = bFresnelWarp;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "FRESNEL_WARP", bFresnelWarp, "bFresnelWarp");
    v111 = bOpacityTexture;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "OPACITY_TEXTURE", bOpacityTexture, "bOpacityTexture");
    LODWORD(v110) = bInteriorLayer;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "INTERIOR_LAYER", bInteriorLayer, "bInteriorLayer");
    LODWORD(tweaks[3]) = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_FLOAT;
    if ( g_shaderConfigDumpEnable )
    {
      v23 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
              a1: g_pHardwareConfig,
              a2: "(g_pHardwareConfig->GetHDRType() == HDR_TYPE_FLOAT) ? true : false");
      printf(format: "\n   PS stat var %s = %d (%s)", "HIGH_PRECISION_DEPTH", v23 == 2, v96);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHTDEPTHFILTERMODE", v22, "nShadowFilterMode");
    }
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS stat var %s = %d (%s)", "CONTACT_SHADOW", bContactShadows, "bContactShadows");
    pShaderShadow->SetPixelShader(
      this: pShaderShadow,
      a2: "icesurface_ps30",
      a3: 20
    * (LODWORD(tweaks[0])
     + 2
     * (LODWORD(tweaks[1])
      + 2
      * (LODWORD(tweaks[2])
       + 2
       * (LODWORD(tweaks[3])
        + 2 * (LODWORD(v110) + 2 * (v111 + 2 * (bContactShadows + bFlashlightShadows + 2 * bContactShadows))))))));
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
    v25 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v26 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v26 > 0, v97);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * v25);
    GetDX9LightState = pShaderAPI->GetDX9LightState;
    lightState.m_nNumLights = 0;
    *(_WORD *)&lightState.m_bAmbientLight = 0;
    GetDX9LightState(this: pShaderAPI, a2: &lightState);
    v28 = info->m_nUVScale < 0;
    v29 = params;
    memset(flConsts, 0, sizeof(flConsts));
    if ( v28 || (v30 = params[info->m_nUVScale], !v30->IsDefined(this: v30)) )
      x = 0.02;
    else
      x = params[info->m_nUVScale]->m_VecVal.x;
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    flConsts[0] = x;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: flConsts, a4: 1, a5: false);
    if ( info->m_nUVProjOffset >= 0 && (v33 = params[info->m_nUVProjOffset], v33->IsDefined(this: v33)) )
    {
      v34 = params[info->m_nUVProjOffset];
      flConsts[0] = v34->m_VecVal.x;
      flConsts[1] = v34->m_VecVal.y;
      flConsts[2] = v34->m_VecVal.z;
    }
    else
    {
      memset(flConsts, 0, 12);
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 49, a3: flConsts, a4: 1, a5: false);
    if ( info->m_nBBMin >= 0 && (v35 = params[info->m_nBBMin], v35->IsDefined(this: v35)) )
    {
      v36 = params[info->m_nBBMin];
      flConsts[0] = v36->m_VecVal.x;
      flConsts[1] = v36->m_VecVal.y;
      flConsts[2] = v36->m_VecVal.z;
    }
    else
    {
      memset(flConsts, 0, 12);
    }
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 50, a3: flConsts, a4: 1, a5: false);
    if ( info->m_nBBMax >= 0 && (v37 = params[info->m_nBBMax], v37->IsDefined(this: v37)) )
    {
      v38 = params[info->m_nBBMax];
      flConsts[0] = v38->m_VecVal.x;
      flConsts[1] = v38->m_VecVal.y;
      flConsts[2] = v38->m_VecVal.z;
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
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
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
      v40 = state.m_fBrightnessScale * (float)(pShaderAPIa * 2.5);
      v102[0] = state.m_Color[0] * v40;
      v102[1] = state.m_Color[1] * v40;
      v102[2] = state.m_Color[2] * v40;
      v102[3] = 0.0;
      SetPixelShaderConstant(this: pShaderAPI, a2: 28, a3: v102, a4: 1, a5: false);
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
      v41 = pShaderAPI->SetPixelShaderConstant;
      atten[0] = state.m_fConstantAtten;
      atten[1] = state.m_fLinearAtten;
      atten[2] = state.m_fQuadraticAtten;
      atten[3] = state.m_FarZAtten;
      v41(this: pShaderAPI, a2: 13, a3: atten, a4: 1, a5: false);
      v42 = pShaderAPI->SetPixelShaderConstant;
      *(Vector *)pos = state.m_vecLightOrigin;
      pos[3] = state.m_FarZ;
      v42(this: pShaderAPI, a2: 14, a3: pos, a4: 1, a5: false);
      pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 15, a3: (const float *)&worldToTexture, a4: 4, a5: false);
      v110 = state.m_flShadowFilterSize * 0.0009765625;
      v43 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
      m_flShadowAtten = state.m_flShadowAtten;
      if ( v43 )
        m_flShadowAtten = state.m_flShadowAtten * 0.1;
      v111 = LODWORD(m_flShadowAtten);
      CBaseVSShader::HashShadow2DJitter(this: pShader, fJitterSeed: state.m_flShadowJitterSeed, &fU, &fV);
      pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 2, a3: &v110, a4: 1, a5: false);
      GetBackBufferDimensions = pShaderAPI->GetBackBufferDimensions;
      _pshIndex.m_nNUM_LIGHTS = 1109393408;
      _pshIndex.m_nFLASHLIGHT = 1102315520;
      _pshIndex.m_nFLASHLIGHTSHADOWS = 0;
      v115 = 0;
      GetBackBufferDimensions(this: pShaderAPI, a2: &nWidth, a3: &nHeight);
      pShaderAPI->GetStandardTextureDimensions(
        this: pShaderAPI,
        a2: &nTexWidth,
        a3: &nTexHeight,
        a4: TEXTURE_SHADOW_NOISE_2D);
      v46 = pShaderAPI->SetPixelShaderConstant;
      *(float *)&_pshIndex.m_nNUM_LIGHTS = (float)nWidth / (float)nTexWidth;
      *(float *)&_pshIndex.m_nFLASHLIGHT = (float)nHeight / (float)nTexHeight;
      v46(this: pShaderAPI, a2: 31, a3: (const float *)&_pshIndex.m_nNUM_LIGHTS, a4: 1, a5: false);
      v6 = info;
      v29 = params;
    }
    if ( v6->m_nBumpStrength >= 0 && (v47 = v29[v6->m_nBumpStrength], v47->IsDefined(this: v47)) )
      v48 = v29[v6->m_nBumpStrength]->m_VecVal.x;
    else
      v48 = 1.0;
    flConsts[0] = v48;
    if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_FLOAT )
      v49 = 8192.0;
    else
      v49 = 192.0;
    v28 = v6->m_nInteriorFogStrength < 0;
    flConsts[1] = v49;
    if ( v28 || (v50 = v29[v6->m_nInteriorFogStrength], !v50->IsDefined(this: v50)) )
      v51 = 0.059999999;
    else
      v51 = v29[v6->m_nInteriorFogStrength]->m_VecVal.x;
    v28 = v6->m_nInteriorRefractStrength < 0;
    flConsts[2] = v51;
    if ( v28 || (v52 = v29[v6->m_nInteriorRefractStrength], !v52->IsDefined(this: v52)) )
      v53 = 0.015;
    else
      v53 = v29[v6->m_nInteriorRefractStrength]->m_VecVal.x;
    v54 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v53;
    v54(this: pShaderAPI, a2: 0, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nFresnelParams >= 0 && (v55 = v29[v6->m_nFresnelParams], v55->IsDefined(this: v55)) )
    {
      v56 = (float *)v29[v6->m_nFresnelParams];
      flConsts[0] = v56[3];
      flConsts[1] = v56[4];
      flConsts[2] = v56[5];
    }
    else
    {
      *(_QWORD *)flConsts = *(_QWORD *)kDefaultFresnelParams_0;
      flConsts[2] = 2.0;
    }
    v57 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v29[v6->m_nInteriorBackgroundBoost]->m_VecVal.x;
    v57(this: pShaderAPI, a2: 1, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nRimLightExp >= 0 && (v58 = v29[v6->m_nRimLightExp], v58->IsDefined(this: v58)) )
      v59 = v29[v6->m_nRimLightExp]->m_VecVal.x;
    else
      v59 = 10.0;
    v28 = v6->m_nRimLightScale < 0;
    flConsts[0] = v59;
    if ( v28 || (v60 = v29[v6->m_nRimLightScale], !v60->IsDefined(this: v60)) )
      v61 = 1.0;
    else
      v61 = v29[v6->m_nRimLightScale]->m_VecVal.x;
    v28 = v6->m_nSpecScale < 0;
    flConsts[1] = v61;
    if ( v28 || (v62 = v29[v6->m_nSpecScale], !v62->IsDefined(this: v62)) )
      v63 = 1.0;
    else
      v63 = v29[v6->m_nSpecScale]->m_VecVal.x;
    v28 = v6->m_nSpecExp2 < 0;
    flConsts[2] = v63;
    if ( v28 || (v64 = v29[v6->m_nSpecExp2], !v64->IsDefined(this: v64)) )
      v65 = 1.0;
    else
      v65 = v29[v6->m_nSpecExp2]->m_VecVal.x;
    v66 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v65;
    v66(this: pShaderAPI, a2: 3, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nSpecScale2 >= 0 && (v67 = v29[v6->m_nSpecScale2], v67->IsDefined(this: v67)) )
      v68 = v29[v6->m_nSpecScale2]->m_VecVal.x;
    else
      v68 = 1.0;
    v28 = v6->m_nFresnelBumpStrength < 0;
    flConsts[0] = v68;
    if ( v28 || (v69 = v29[v6->m_nFresnelBumpStrength], !v69->IsDefined(this: v69)) )
      v70 = 1.0;
    else
      v70 = v29[v6->m_nFresnelBumpStrength]->m_VecVal.x;
    v28 = v6->m_nDiffuseScale < 0;
    flConsts[1] = v70;
    if ( v28 || (v71 = v29[v6->m_nDiffuseScale], !v71->IsDefined(this: v71)) )
      v72 = 1.0;
    else
      v72 = v29[v6->m_nDiffuseScale]->m_VecVal.x;
    v28 = v6->m_nInteriorAmbientScale < 0;
    flConsts[2] = v72;
    if ( v28 || (v73 = v29[v6->m_nInteriorAmbientScale], !v73->IsDefined(this: v73)) )
      v74 = 0.30000001;
    else
      v74 = v29[v6->m_nInteriorAmbientScale]->m_VecVal.x;
    v75 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v74;
    v75(this: pShaderAPI, a2: 10, a3: flConsts, a4: 1, a5: false);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: flConsts);
    if ( v6->m_nSpecExp >= 0 && (v76 = v29[v6->m_nSpecExp], v76->IsDefined(this: v76)) )
      v77 = v29[v6->m_nSpecExp]->m_VecVal.x;
    else
      v77 = 1.0;
    v78 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v77;
    v78(this: pShaderAPI, a2: 11, a3: flConsts, a4: 1, a5: false);
    if ( pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI) )
      v79 = 1.0;
    else
      v79 = 0.0;
    v80 = pShaderAPI->SetPixelShaderConstant;
    flConsts[0] = v79;
    v80(this: pShaderAPI, a2: 12, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nBaseColorTint >= 0 && (v81 = v29[v6->m_nBaseColorTint], v81->IsDefined(this: v81)) )
    {
      v82 = (float *)v29[v6->m_nBaseColorTint];
      flConsts[0] = v82[3];
      flConsts[1] = v82[4];
      flConsts[2] = v82[5];
    }
    else
    {
      *(_QWORD *)flConsts = *(_QWORD *)kDefaultBaseColorTint_0;
      flConsts[2] = 1.0;
    }
    if ( v6->m_nInteriorBackLightScale >= 0 && (v83 = v29[v6->m_nInteriorBackLightScale], v83->IsDefined(this: v83)) )
      v84 = v29[v6->m_nInteriorBackLightScale]->m_VecVal.x;
    else
      v84 = 0.30000001;
    v85 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v84;
    v85(this: pShaderAPI, a2: 19, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nInteriorColor >= 0 && (v86 = v29[v6->m_nInteriorColor], v86->IsDefined(this: v86)) )
    {
      v87 = (float *)v29[v6->m_nInteriorColor];
      flConsts[0] = v87[3];
      flConsts[1] = v87[4];
      flConsts[2] = v87[5];
    }
    else
    {
      *(_QWORD *)flConsts = *(_QWORD *)kDefaultInteriorColor_0;
      flConsts[2] = 0.5;
    }
    v88 = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v29[v6->m_nInteriorRefractBlur]->m_VecVal.x;
    v88(this: pShaderAPI, a2: 32, a3: flConsts, a4: 1, a5: false);
    pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: mView);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 33, a3: mView, a4: 3, a5: false);
    if ( v6->m_nInteriorFogLimit >= 0 && (v89 = v29[v6->m_nInteriorFogLimit], v89->IsDefined(this: v89)) )
      v90 = v29[v6->m_nInteriorFogLimit]->m_VecVal.x;
    else
      v90 = 0.80000001;
    m_nInteriorFogNormalBoost = v6->m_nInteriorFogNormalBoost;
    v92 = pShaderAPI->SetPixelShaderConstant;
    flConsts[0] = 1.0 - v90;
    flConsts[1] = v29[m_nInteriorFogNormalBoost]->m_VecVal.x;
    v92(this: pShaderAPI, a2: 36, a3: flConsts, a4: 1, a5: false);
    if ( v6->m_nEnvMapTint >= 0 && (v93 = v29[v6->m_nEnvMapTint], v93->IsDefined(this: v93)) )
    {
      v94 = (float *)v29[v6->m_nEnvMapTint];
      flConsts[0] = v94[3];
      flConsts[1] = v94[4];
      flConsts[2] = v94[5];
    }
    else
    {
      *(_QWORD *)flConsts = *(_QWORD *)kDefaultEnvMapTint;
      flConsts[2] = 1.0;
    }
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 37, a3: flConsts, a4: 1, a5: false);
    _pshIndex.m_nFLASHLIGHT = lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", lightState.m_nNumLights, "lightState.m_nNumLights");
    v95 = bHasFlashlight;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHT", bHasFlashlight, "bHasFlashlight");
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", bFlashlightShadows_3, "bFlashlightShadows");
    pShaderAPI->SetPixelShaderIndex(
      this: pShaderAPI,
      a2: v95 + 2 * bFlashlightShadows_3 + _pshIndex.m_nFLASHLIGHT + 4 * (v95 + 2 * bFlashlightShadows_3));
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
