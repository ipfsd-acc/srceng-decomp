// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/eye_refract_helper.cpp
// Functions: 6
// ============================================================

#include "materialsystem\stdshaders\eye_refract_helper.h"

//------------------------------------------------------------------------------
// Address: 0x1000F550
// Name: public: FlashlightState_t::FlashlightState_t(void)
// Source: json
//------------------------------------------------------------------------------
FlashlightState_t *__thiscall FlashlightState_t::FlashlightState_t(FlashlightState_t *this)
{
  this->m_uberlightState.m_fNearEdge = 2.0;
  this->m_uberlightState.m_fFarEdge = 100.0;
  this->m_uberlightState.m_fCutOn = 10.0;
  this->m_uberlightState.m_fWedge = 0.050000001;
  this->m_uberlightState.m_fHedge = 0.050000001;
  this->m_uberlightState.m_fCutOff = 650.0;
  this->m_uberlightState.m_fWidth = 0.30000001;
  this->m_uberlightState.m_fHeight = 0.30000001;
  this->m_uberlightState.m_fShearx = 0.0;
  this->m_uberlightState.m_fSheary = 0.0;
  this->m_uberlightState.m_fRoundness = 0.80000001;
  this->m_flShadowMapResolution = 1024.0;
  this->m_flShadowFilterSize = 3.0;
  this->m_flShadowSlopeScaleDepthBias = 16.0;
  this->m_flShadowJitterSeed = 0.0;
  this->m_flShadowAtten = 0.0;
  this->m_flAmbientOcclusion = 0.0;
  this->m_flNoiseStrength = 0.80000001;
  this->m_flFlashlightTime = 0.0;
  this->m_flPlaneOffset = 0.0;
  *(_WORD *)&this->m_bEnableShadows = 0;
  this->m_flShadowDepthBias = 0.00050000002;
  this->m_nShadowQuality = 0;
  this->m_bShadowHighRes = false;
  this->m_nLeft = -1;
  this->m_nTop = -1;
  this->m_nRight = -1;
  this->m_nBottom = -1;
  this->m_bUberlight = false;
  this->m_bVolumetric = false;
  this->m_nNumPlanes = 64;
  this->m_flVolumetricIntensity = 1.0;
  this->m_bOrtho = false;
  this->m_fOrthoLeft = -1.0;
  this->m_fOrthoRight = 1.0;
  this->m_fOrthoTop = -1.0;
  this->m_fOrthoBottom = 1.0;
  this->m_fBrightnessScale = 1.0;
  this->m_pSpotlightTexture = nullptr;
  this->m_pProjectedMaterial = nullptr;
  *(_WORD *)&this->m_bShareBetweenSplitscreenPlayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F6E0
// Name: public: int LightState_t::HasDynamicLight(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall LightState_t::HasDynamicLight(LightState_t *this)
{
  return this->m_bAmbientLight || this->m_nNumLights > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F700
// Name: void InitParams_Eyes_Refract(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct Eye_Refract_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParams_Eyes_Refract(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        Eye_Refract_Vars_t *info)
{
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

  params[9]->SetStringValue(this: params[9], a2: "effects/flashlight001");
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  if ( info->m_nDilation >= 0 )
  {
    v5 = params[info->m_nDilation];
    if ( !v5->IsDefined(this: v5) )
      ((void (__stdcall *)(int))params[info->m_nDilation]->SetFloatValue)(a1: 1056964608);
  }
  if ( info->m_nGlossiness >= 0 )
  {
    v6 = params[info->m_nGlossiness];
    if ( !v6->IsDefined(this: v6) )
      ((void (__stdcall *)(int))params[info->m_nGlossiness]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSphereTexKillCombo >= 0 )
  {
    v7 = params[info->m_nSphereTexKillCombo];
    if ( !v7->IsDefined(this: v7) )
    {
      v8 = params[info->m_nSphereTexKillCombo];
      v8->SetIntValue(this: v8, a2: 0);
    }
  }
  if ( info->m_nRaytraceSphere >= 0 )
  {
    v9 = params[info->m_nRaytraceSphere];
    if ( !v9->IsDefined(this: v9) )
    {
      v10 = params[info->m_nRaytraceSphere];
      v10->SetIntValue(this: v10, a2: 0);
    }
  }
  if ( info->m_nAmbientOcclColor >= 0 )
  {
    v11 = params[info->m_nAmbientOcclColor];
    if ( !v11->IsDefined(this: v11) )
    {
      v12 = params[info->m_nAmbientOcclColor];
      v12->SetVecValue_4(this: v12, a2: kDefaultAmbientOcclColor, a3: 4);
    }
  }
  if ( info->m_nEyeballRadius >= 0 )
  {
    v13 = params[info->m_nEyeballRadius];
    if ( !v13->IsDefined(this: v13) )
      ((void (__stdcall *)(int))params[info->m_nEyeballRadius]->SetFloatValue)(a1: 1056964608);
  }
  if ( info->m_nParallaxStrength >= 0 )
  {
    v14 = params[info->m_nParallaxStrength];
    if ( !v14->IsDefined(this: v14) )
      ((void (__stdcall *)(int))params[info->m_nParallaxStrength]->SetFloatValue)(a1: 1048576000);
  }
  if ( info->m_nCorneaBumpStrength >= 0 )
  {
    v15 = params[info->m_nCorneaBumpStrength];
    if ( !v15->IsDefined(this: v15) )
      ((void (__stdcall *)(int))params[info->m_nCorneaBumpStrength]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nAmbientOcclusion >= 0 )
  {
    v16 = params[info->m_nAmbientOcclusion];
    if ( !v16->IsDefined(this: v16) )
      ((void (__stdcall *)(_DWORD))params[info->m_nAmbientOcclusion]->SetFloatValue)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F8F0
// Name: void Init_Eyes_Refract(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct Eye_Refract_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Init_Eyes_Refract(CBaseVSShader *pShader, IMaterialVar **params, Eye_Refract_Vars_t *info)
{
  IMaterialVar *v3; // ecx

  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nCorneaTexture, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nIris, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadCubeMap(this: pShader, nTextureVar: info->m_nEnvmap, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nAmbientOcclTexture, nAdditionalCreationFlags: 0x80000);
  if ( info->m_nDiffuseWarpTexture >= 0 )
  {
    v3 = params[info->m_nDiffuseWarpTexture];
    if ( v3->IsDefined(this: v3) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nDiffuseWarpTexture, nAdditionalCreationFlags: 0);
  }
  CBaseShader::LoadTexture(this: pShader, nTextureVar: 9, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x1000F980
// Name: void Draw_Eyes_Refract_Internal(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,bool,struct Eye_Refract_Vars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Draw_Eyes_Refract_Internal(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        bool bDrawFlashlightAdditivePass,
        int info,
        VertexCompressionType_t vertexCompression)
{
  Eye_Refract_Vars_t *v7; // edi
  IMaterialVar *v8; // ecx
  bool v9; // al
  IShaderShadow *v10; // esi
  int v11; // eax
  int v12; // eax
  BOOL v13; // ebx
  IMaterialVar *v14; // ecx
  IMaterialVar *v15; // ecx
  bool v16; // bl
  BOOL v17; // eax
  BOOL v18; // ebx
  int v19; // eax
  BOOL v20; // ebx
  IMaterialVar *v21; // ecx
  IMaterialVar *v22; // ecx
  bool v23; // bl
  BOOL v24; // ebx
  bool v25; // bl
  CBaseVSShader *v26; // esi
  IShaderDynamicAPI *v27; // ebx
  ITexture *v28; // eax
  bool v29; // zf
  int (__thiscall *v30)(IShaderDynamicAPI *); // eax
  int v31; // eax
  int v32; // eax
  BOOL v33; // eax
  int v34; // esi
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  double v36; // st7
  void (__thiscall *v37)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool (__thiscall *IsHWMorphingEnabled)(IShaderDynamicAPI *); // eax
  float v39; // ecx
  int (__thiscall *GetCurrentNumBones)(IShaderDynamicAPI *); // eax
  int v41; // eax
  int m_nNumLights; // eax
  BOOL v43; // eax
  VertexCompressionType_t v44; // edi
  int v45; // esi
  bool v46; // sf
  IMaterialVar *v47; // ecx
  float x; // xmm0_4
  IMaterialVar *v49; // ecx
  float v50; // xmm0_4
  IMaterialVar *v51; // ecx
  float v52; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v54; // ecx
  Vector4D *p_m_VecVal; // eax
  IMaterialVar *v56; // ecx
  Vector4D *v57; // eax
  IMaterialVar *v58; // ecx
  Vector4D *v59; // eax
  void (__thiscall *GetWorldSpaceCameraPosition)(IShaderDynamicAPI *, float *); // edx
  IMaterialVar *v61; // ecx
  IMaterialVar *v62; // eax
  IMaterialVar *v63; // ecx
  float v64; // xmm0_4
  IMaterialVar *v65; // ecx
  float v66; // xmm0_4
  IMaterialVar *v67; // ecx
  float v68; // xmm0_4
  void (__thiscall *v69)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool (__thiscall *GetHDREnabled)(IMaterialSystemHardwareConfig *); // eax
  bool v71; // al
  float v72; // xmm1_4
  void (__thiscall *v73)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v74)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v75; // cc
  MaterialFogMode_t (__thiscall *GetSceneFogMode)(IShaderDynamicAPI *); // edx
  BOOL v77; // edi
  BOOL v78; // esi
  int v79; // edi
  BOOL v80; // esi
  int v81; // eax
  IShaderDynamicAPI *v82; // edi
  int v83; // esi
  BOOL m_bUberlight; // edi
  void (__thiscall *v85)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v86)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v87)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v88; // al
  float m_flShadowAtten; // xmm0_4
  void (__thiscall *GetBackBufferDimensions)(IShaderDynamicAPI *, int *, int *); // eax
  void (__thiscall *v91)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v92; // xmm0_4
  float v93; // xmm1_4
  const char *v94; // [esp+224h] [ebp-278h]
  const char *v95; // [esp+224h] [ebp-278h]
  VMatrix worldToTexture; // [esp+234h] [ebp-268h] BYREF
  matrix3x4_t matrix; // [esp+274h] [ebp-228h] BYREF
  matrix3x4_t out; // [esp+2A4h] [ebp-1F8h] BYREF
  FlashlightState_t flashlightState; // [esp+2D4h] [ebp-1C8h] BYREF
  float v100[4]; // [esp+3D0h] [ebp-CCh] BYREF
  float v101[4]; // [esp+3E0h] [ebp-BCh] BYREF
  float vEyePos[4]; // [esp+3F0h] [ebp-ACh] BYREF
  float pos[4]; // [esp+400h] [ebp-9Ch] BYREF
  float vPackedConst6[4]; // [esp+410h] [ebp-8Ch] BYREF
  float tweaks[4]; // [esp+420h] [ebp-7Ch] BYREF
  float vPSConst[4]; // [esp+430h] [ebp-6Ch] BYREF
  float vAmbientOcclusion[5]; // [esp+440h] [ebp-5Ch] BYREF
  float atten[4]; // [esp+454h] [ebp-48h] BYREF
  float m_fHeight; // [esp+464h] [ebp-38h]
  float m_FarZAtten; // [esp+468h] [ebp-34h]
  int nTexHeight; // [esp+46Ch] [ebp-30h] BYREF
  TessellationMode_t nTessellationMode; // [esp+470h] [ebp-2Ch]
  ShadowFilterMode_t nShadowFilterMode; // [esp+474h] [ebp-28h]
  float vScreenScale[4]; // [esp+478h] [ebp-24h] BYREF
  bool v115; // [esp+48Bh] [ebp-11h]
  LightState_t lightState; // [esp+48Ch] [ebp-10h] BYREF
  ITexture *pFlashlightDepthTexture; // [esp+494h] [ebp-8h] BYREF
  bool bDiffuseWarp; // [esp+49Bh] [ebp-1h]

  v7 = (Eye_Refract_Vars_t *)info;
  if ( *(int *)(info + 76) < 0
    || (v8 = params[*(_DWORD *)(info + 76)], v9 = v8->IsDefined(this: v8), bDiffuseWarp = true, !v9) )
  {
    bDiffuseWarp = false;
  }
  v10 = pShaderShadow;
  if ( pShaderShadow != nullptr )
  {
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
    v10->EnableTexture(this: v10, a2: SHADER_SAMPLER0, a3: true);
    v10->EnableTexture(this: v10, a2: SHADER_SAMPLER1, a3: true);
    v10->EnableTexture(this: v10, a2: SHADER_SAMPLER2, a3: true);
    v10->EnableTexture(this: v10, a2: SHADER_SAMPLER3, a3: true);
    v10->VertexShaderVertexFormat(this: v10, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    if ( bDiffuseWarp )
      v10->EnableTexture(this: v10, a2: SHADER_SAMPLER4, a3: true);
    HIBYTE(pShaderShadow) = ((params[2]->m_intVal & 0x100000) != 0) + 2 * ((params[2]->m_intVal & 0x200000) != 0) == 3;
    nShadowFilterMode = SHADOWFILTERMODE_DEFAULT;
    if ( bDrawFlashlightAdditivePass )
    {
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
      {
        v11 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *))g_pHardwareConfig->HasFastVertexTextures)(a1: g_pHardwareConfig);
        LOBYTE(v11) = (_BYTE)v11 != 0;
        nShadowFilterMode = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: v11);
      }
      v10->EnableDepthWrites(this: v10, a2: false);
      v10->EnableAlphaWrites(this: v10, a2: false);
      CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
      v10->EnableTexture(this: v10, a2: SHADER_SAMPLER5, a3: true);
    }
    else
    {
      v10->EnableAlphaWrites(this: v10, a2: true);
    }
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      v10->EnableTexture(this: v10, a2: SHADER_SAMPLER8, a3: true);
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x800000);
      v19 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v20 = ((*params)->m_intVal & 0x8000000) != 0;
      LODWORD(m_fHeight) = v19 >= 92;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", v20, "IS_FLAG_SET( MATERIAL_VAR_HALFLAMBERT )");
      pFlashlightDepthTexture = (ITexture *)bDrawFlashlightAdditivePass;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "FLASHLIGHT",
          bDrawFlashlightAdditivePass,
          "bDrawFlashlightAdditivePass ? 1 : 0");
      *(_DWORD *)&lightState.m_bAmbientLight = bDiffuseWarp;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "LIGHTWARPTEXTURE", bDiffuseWarp, "bDiffuseWarp ? 1 : 0");
      nTessellationMode = HIBYTE(pShaderShadow) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "WORLD_NORMAL", HIBYTE(pShaderShadow), "bWorldNormal");
      v10->SetVertexShader(
        this: v10,
        a2: "eye_refract_vs30",
        a3: 160
      * (v20
       + 2
       * ((_DWORD)&pFlashlightDepthTexture[2 * LODWORD(m_fHeight) + nTessellationMode]
        + 2 * *(_DWORD *)&lightState.m_bAmbientLight)));
      v115 = v7->m_nSphereTexKillCombo >= 0
          && (v21 = params[v7->m_nSphereTexKillCombo], v21->IsDefined(this: v21))
          && params[v7->m_nSphereTexKillCombo]->m_intVal != 0;
      v23 = v7->m_nRaytraceSphere >= 0
         && (v22 = params[v7->m_nRaytraceSphere], v22->IsDefined(this: v22))
         && params[v7->m_nRaytraceSphere]->m_intVal != 0;
      nTexHeight = v115;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SPHERETEXKILLCOMBO", v115, "bSphereTexKillCombo ? 1 : 0");
      v24 = v23;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "RAYTRACESPHERE", v24, "bRayTraceSphere ? 1 : 0");
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "FLASHLIGHT",
            pFlashlightDepthTexture,
            "bDrawFlashlightAdditivePass ? 1 : 0");
          if ( g_shaderConfigDumpEnable )
          {
            printf(
              format: "\n   PS stat var %s = %d (%s)",
              "LIGHTWARPTEXTURE",
              *(_DWORD *)&lightState.m_bAmbientLight,
              "bDiffuseWarp ? 1 : 0");
            if ( g_shaderConfigDumpEnable )
            {
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "FLASHLIGHTDEPTHFILTERMODE",
                nShadowFilterMode,
                "nShadowFilterMode");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "WORLD_NORMAL", HIBYTE(pShaderShadow), "bWorldNormal");
            }
          }
        }
      }
      v10->SetPixelShader(
        this: v10,
        a2: "eye_refract_ps30",
        a3: 40
      * ((_DWORD)&pFlashlightDepthTexture[8 * nTessellationMode
                                        + 4 * nTessellationMode
                                        + 4 * nShadowFilterMode
                                        + 2 * v24
                                        + nTexHeight]
       + 2 * *(_DWORD *)&lightState.m_bAmbientLight));
    }
    else
    {
      LODWORD(m_fHeight) = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v12 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v13 = ((*params)->m_intVal & 0x8000000) != 0;
      LODWORD(m_FarZAtten) = v12 < 92;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", v13, "IS_FLAG_SET( MATERIAL_VAR_HALFLAMBERT )");
      pFlashlightDepthTexture = (ITexture *)bDrawFlashlightAdditivePass;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "FLASHLIGHT",
          bDrawFlashlightAdditivePass,
          "bDrawFlashlightAdditivePass ? 1 : 0");
      *(_DWORD *)&lightState.m_bAmbientLight = bDiffuseWarp;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS stat var %s = %d (%s)", "LIGHTWARPTEXTURE", bDiffuseWarp, "bDiffuseWarp ? 1 : 0");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
      }
      v10->SetVertexShader(
        this: v10,
        a2: "eye_refract_vs20",
        a3: 80
      * (v13
       + 2
       * ((_DWORD)&pFlashlightDepthTexture[2 * LODWORD(m_FarZAtten) + LODWORD(m_fHeight)]
        + 2 * *(_DWORD *)&lightState.m_bAmbientLight)));
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "FLASHLIGHT",
            pFlashlightDepthTexture,
            "bDrawFlashlightAdditivePass ? 1 : 0");
          if ( g_shaderConfigDumpEnable )
          {
            printf(
              format: "\n   PS stat var %s = %d (%s)",
              "LIGHTWARPTEXTURE",
              *(_DWORD *)&lightState.m_bAmbientLight,
              "bDiffuseWarp ? 1 : 0");
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
          }
        }
        v10->SetPixelShader(
          this: v10,
          a2: "eye_refract_ps20",
          a3: 6 * ((_DWORD)pFlashlightDepthTexture + 2 * *(_DWORD *)&lightState.m_bAmbientLight));
        goto LABEL_70;
      }
      HIBYTE(pShaderShadow) = v7->m_nSphereTexKillCombo >= 0
                           && (v14 = params[v7->m_nSphereTexKillCombo], v14->IsDefined(this: v14))
                           && params[v7->m_nSphereTexKillCombo]->m_intVal != 0;
      v16 = v7->m_nRaytraceSphere >= 0
         && (v15 = params[v7->m_nRaytraceSphere], v15->IsDefined(this: v15))
         && params[v7->m_nRaytraceSphere]->m_intVal != 0;
      v17 = HIBYTE(pShaderShadow) != 0;
      pShaderShadow = (IShaderShadow *)v17;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SPHERETEXKILLCOMBO", v17, "bSphereTexKillCombo ? 1 : 0");
      v18 = v16;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "RAYTRACESPHERE", v18, "bRayTraceSphere ? 1 : 0");
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "FLASHLIGHT",
            pFlashlightDepthTexture,
            "bDrawFlashlightAdditivePass ? 1 : 0");
          if ( g_shaderConfigDumpEnable )
          {
            printf(
              format: "\n   PS stat var %s = %d (%s)",
              "LIGHTWARPTEXTURE",
              *(_DWORD *)&lightState.m_bAmbientLight,
              "bDiffuseWarp ? 1 : 0");
            if ( g_shaderConfigDumpEnable )
            {
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "FLASHLIGHTDEPTHFILTERMODE",
                nShadowFilterMode,
                "nShadowFilterMode");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
            }
          }
        }
      }
      v10->SetPixelShader(
        this: v10,
        a2: "eye_refract_ps20b",
        a3: 20
      * ((_DWORD)&pFlashlightDepthTexture[(_DWORD)&pShaderShadow[nShadowFilterMode] + 2 * v18]
       + 2 * *(_DWORD *)&lightState.m_bAmbientLight));
    }
    if ( bDrawFlashlightAdditivePass )
    {
      v10->EnableTexture(this: v10, a2: SHADER_SAMPLER6, a3: true);
      v10->EnableTexture(this: v10, a2: SHADER_SAMPLER7, a3: true);
    }
LABEL_70:
    v10->EnableSRGBRead(this: v10, a2: SHADER_SAMPLER1, a3: true);
    v10->EnableSRGBRead(this: v10, a2: SHADER_SAMPLER2, a3: true);
    v10->EnableSRGBRead(this: v10, a2: SHADER_SAMPLER3, a3: true);
    v10->EnableSRGBWrite(this: v10, a2: true);
    v25 = bDrawFlashlightAdditivePass;
    if ( bDrawFlashlightAdditivePass )
    {
      v10->EnableSRGBRead(this: v10, a2: SHADER_SAMPLER5, a3: true);
      v26 = pShader;
      CBaseShader::FogToBlack(this: pShader);
    }
    else
    {
      v26 = pShader;
      CBaseShader::FogToFogColor(this: pShader);
    }
    CBaseShader::PI_BeginCommandBuffer(this: v26);
    if ( !v25 )
      CBaseShader::PI_SetPixelShaderLocalLighting(this: v26, nFirstRegister: 20);
    CBaseShader::PI_SetVertexShaderAmbientLightCube(this: v26);
    CBaseShader::PI_SetPixelShaderAmbientLightCubeLuminance(this: v26, nFirstRegister: 10);
    CBaseShader::PI_EndCommandBuffer(this: v26);
  }
  v27 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    pFlashlightDepthTexture = nullptr;
    FlashlightState_t::FlashlightState_t(this: &flashlightState);
    HIBYTE(pShaderShadow) = 0;
    if ( bDrawFlashlightAdditivePass )
    {
      flashlightState = *v27->GetFlashlightStateEx(this: v27, a2: &worldToTexture, a3: &pFlashlightDepthTexture);
      v7 = (Eye_Refract_Vars_t *)info;
      HIBYTE(pShaderShadow) = flashlightState.m_bEnableShadows;
    }
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: v7->m_nCorneaTexture,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: v7->m_nIris,
      nFrameVar: v7->m_nIrisFrame);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: v7->m_nEnvmap,
      nFrameVar: -1);
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: v7->m_nAmbientOcclTexture,
      nFrameVar: -1);
    if ( bDiffuseWarp )
    {
      if ( r_lightwarpidentity_0.m_pParent != nullptr && r_lightwarpidentity_0.m_pParent->m_Value.m_nValue != 0 )
        v27->BindStandardTexture(
          this: v27,
          a2: SHADER_SAMPLER4,
          a3: TEXTURE_BINDFLAGS_NONE,
          a4: TEXTURE_IDENTITY_LIGHTWARP);
      else
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER4,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: v7->m_nDiffuseWarpTexture,
          nFrameVar: -1);
    }
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      v28 = v27->GetTextureRenderingParameter(this: v27, a2: 0);
      if ( v28 != nullptr )
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER8,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          pTexture: v28,
          nFrame: 0);
      else
        v27->BindStandardTexture(this: v27, a2: SHADER_SAMPLER8, a3: TEXTURE_BINDFLAGS_NONE, a4: TEXTURE_WHITE);
    }
    if ( bDrawFlashlightAdditivePass )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER5,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        pTexture: flashlightState.m_pSpotlightTexture,
        nFrame: flashlightState.m_nSpotlightTextureFrame);
    CBaseVSShader::SetVertexShaderConstant(this: pShader, vertexReg: 48, constantVar: v7->m_nEyeOrigin);
    CBaseVSShader::SetVertexShaderConstant(this: pShader, vertexReg: 50, constantVar: v7->m_nIrisU);
    CBaseVSShader::SetVertexShaderConstant(this: pShader, vertexReg: 51, constantVar: v7->m_nIrisV);
    if ( bDrawFlashlightAdditivePass )
      v27->SetVertexShaderConstant(this: v27, a2: 52, a3: &flashlightState.m_vecLightOrigin.x, a4: 1, a5: false);
    lightState.m_nNumLights = 0;
    *(_WORD *)&lightState.m_bAmbientLight = 0;
    if ( !bDrawFlashlightAdditivePass )
      v27->GetDX9LightState(this: v27, a2: &lightState);
    pShaderAPI = (IShaderDynamicAPI *)v27->GetIntRenderingParameter(this: v27, a2: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      CBaseVSShader::SetHWMorphVertexShaderState(
        this: pShader,
        nDimConst: 14,
        nSubrectConst: 15,
        morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      if ( pShaderAPI == (IShaderDynamicAPI *)3 )
      {
        v27->GetWorldSpaceCameraDirection(this: v27, a2: vScreenScale);
        *(float *)&nTexHeight = v27->GetFarZ(this: v27);
        SetVertexShaderConstant = v27->SetVertexShaderConstant;
        vScreenScale[0] = vScreenScale[0] * (float)(1.0 / *(float *)&nTexHeight);
        vScreenScale[1] = vScreenScale[1] * (float)(1.0 / *(float *)&nTexHeight);
        vScreenScale[2] = vScreenScale[2] * (float)(1.0 / *(float *)&nTexHeight);
        SetVertexShaderConstant(this: v27, a2: 53, a3: vScreenScale, a4: 1, a5: false);
      }
      nTessellationMode = v27->GetTessellationMode(this: v27);
      if ( nTessellationMode != TESSELLATION_MODE_DISABLED )
      {
        v27->BindStandardVertexTexture(this: v27, a2: SHADER_VERTEXTEXTURE_SAMPLER1, a3: TEXTURE_SUBDIVISION_PATCHES);
        v36 = ((double (__thiscall *)(IShaderDynamicAPI *))v27->GetSubDHeight)(a1: v27);
        v37 = v27->SetVertexShaderConstant;
        memset(&vScreenScale[1], 0, 12);
        vScreenScale[0] = 1.0 / v36;
        v37(this: v27, a2: 49, a3: vScreenScale, a4: 1, a5: false);
      }
      v29 = v27->GetSceneFogMode(this: v27) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      IsHWMorphingEnabled = v27->IsHWMorphingEnabled;
      LODWORD(atten[1]) = v29;
      LODWORD(v39) = IsHWMorphingEnabled(this: v27);
      GetCurrentNumBones = v27->GetCurrentNumBones;
      m_FarZAtten = v39;
      LODWORD(atten[0]) = GetCurrentNumBones(this: v27) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v41 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))v27->GetCurrentNumBones)(
                a1: v27,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v41 > 0, v95);
      }
      m_nNumLights = lightState.m_nNumLights;
      if ( lightState.m_bAmbientLight || (nShadowFilterMode = SHADOWFILTERMODE_DEFAULT, lightState.m_nNumLights > 0) )
        nShadowFilterMode = ATI_NO_PCF_FETCH4;
      if ( g_shaderConfigDumpEnable )
      {
        v43 = lightState.m_bAmbientLight || lightState.m_nNumLights > 0;
        printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", v43, "lightState.HasDynamicLight()");
        m_nNumLights = lightState.m_nNumLights;
      }
      v44 = vertexCompression;
      v45 = m_nNumLights;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS dyn  var %s = %d (%s)", "NUM_LIGHTS", m_nNumLights, "lightState.m_nNumLights");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", v44, "(int)vertexCompression");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", nTessellationMode, "nTessellationMode");
        }
      }
      v27->SetVertexShaderIndex(
        this: v27,
        a2: v44
      + 2
      * (LODWORD(atten[0])
       + 2
       * (LODWORD(atten[1])
        + 2
        * (nShadowFilterMode
         + 2 * (LODWORD(m_FarZAtten) + nTessellationMode + v45 + 4 * (LODWORD(m_FarZAtten) + nTessellationMode))))));
      v7 = (Eye_Refract_Vars_t *)info;
    }
    else
    {
      v29 = v27->GetSceneFogMode(this: v27) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v30 = v27->GetCurrentNumBones;
      LODWORD(atten[2]) = v29;
      LODWORD(atten[1]) = v30(this: v27) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v31 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))v27->GetCurrentNumBones)(
                a1: v27,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v31 > 0, v94);
      }
      v32 = lightState.m_nNumLights;
      if ( lightState.m_bAmbientLight || (*(float *)&info = 0.0, lightState.m_nNumLights > 0) )
        info = 1;
      if ( g_shaderConfigDumpEnable )
      {
        v33 = lightState.m_bAmbientLight || lightState.m_nNumLights > 0;
        printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", v33, "lightState.HasDynamicLight()");
        v32 = lightState.m_nNumLights;
      }
      v34 = v32;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS dyn  var %s = %d (%s)", "NUM_LIGHTS", v32, "lightState.m_nNumLights");
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", 0, "0");
        }
      }
      v27->SetVertexShaderIndex(
        this: v27,
        a2: vertexCompression + 2 * (LODWORD(atten[1]) + 2 * (LODWORD(atten[2]) + 2 * (info + 2 * v34))));
    }
    v46 = v7->m_nDilation < 0;
    memset(vPSConst, 0, sizeof(vPSConst));
    if ( v46 || (v47 = params[v7->m_nDilation], !v47->IsDefined(this: v47)) )
      x = 0.5;
    else
      x = params[v7->m_nDilation]->m_VecVal.x;
    v46 = v7->m_nGlossiness < 0;
    vPSConst[0] = x;
    if ( v46 || (v49 = params[v7->m_nGlossiness], !v49->IsDefined(this: v49)) )
      v50 = 1.0;
    else
      v50 = params[v7->m_nGlossiness]->m_VecVal.x;
    v46 = v7->m_nCorneaBumpStrength < 0;
    vPSConst[1] = v50;
    vPSConst[2] = 0.0;
    if ( v46 || (v51 = params[v7->m_nCorneaBumpStrength], !v51->IsDefined(this: v51)) )
      v52 = 1.0;
    else
      v52 = params[v7->m_nCorneaBumpStrength]->m_VecVal.x;
    SetPixelShaderConstant = v27->SetPixelShaderConstant;
    vPSConst[3] = v52;
    SetPixelShaderConstant(this: v27, a2: 0, a3: vPSConst, a4: 1, a5: false);
    if ( v7->m_nEyeOrigin >= 0 && (v54 = params[v7->m_nEyeOrigin], v54->IsDefined(this: v54)) )
      p_m_VecVal = &params[v7->m_nEyeOrigin]->m_VecVal;
    else
      p_m_VecVal = (Vector4D *)kDefaultEyeOrigin;
    v27->SetPixelShaderConstant(this: v27, a2: 1, a3: &p_m_VecVal->x, a4: 1, a5: false);
    if ( v7->m_nIrisU >= 0 && (v56 = params[v7->m_nIrisU], v56->IsDefined(this: v56)) )
      v57 = &params[v7->m_nIrisU]->m_VecVal;
    else
      v57 = (Vector4D *)kDefaultIrisU;
    v27->SetPixelShaderConstant(this: v27, a2: 2, a3: &v57->x, a4: 1, a5: false);
    if ( v7->m_nIrisV >= 0 && (v58 = params[v7->m_nIrisV], v58->IsDefined(this: v58)) )
      v59 = &params[v7->m_nIrisV]->m_VecVal;
    else
      v59 = (Vector4D *)kDefaultIrisV;
    v27->SetPixelShaderConstant(this: v27, a2: 3, a3: &v59->x, a4: 1, a5: false);
    GetWorldSpaceCameraPosition = v27->GetWorldSpaceCameraPosition;
    memset(vEyePos, 0, sizeof(vEyePos));
    GetWorldSpaceCameraPosition(this: v27, a2: vEyePos);
    v27->SetPixelShaderConstant(this: v27, a2: 4, a3: vEyePos, a4: 1, a5: false);
    v46 = v7->m_nAmbientOcclColor < 0;
    vAmbientOcclusion[0] = 0.33000001;
    vAmbientOcclusion[1] = 0.33000001;
    vAmbientOcclusion[2] = 0.33000001;
    vAmbientOcclusion[3] = 0.0;
    if ( !v46 )
    {
      v61 = params[v7->m_nAmbientOcclColor];
      if ( v61->IsDefined(this: v61) )
      {
        v62 = params[v7->m_nAmbientOcclColor];
        vAmbientOcclusion[0] = v62->m_VecVal.x;
        vAmbientOcclusion[1] = v62->m_VecVal.y;
        vAmbientOcclusion[2] = v62->m_VecVal.z;
      }
    }
    if ( v7->m_nAmbientOcclusion >= 0 && (v63 = params[v7->m_nAmbientOcclusion], v63->IsDefined(this: v63)) )
      v64 = params[v7->m_nAmbientOcclusion]->m_VecVal.x;
    else
      v64 = 0.0;
    v46 = v7->m_nEyeballRadius < 0;
    vAmbientOcclusion[3] = v64;
    vPackedConst6[0] = 1.0;
    vPackedConst6[1] = 1.0;
    vPackedConst6[2] = 1.0;
    vPackedConst6[3] = 1.0;
    if ( v46 || (v65 = params[v7->m_nEyeballRadius], !v65->IsDefined(this: v65)) )
      v66 = 0.5;
    else
      v66 = params[v7->m_nEyeballRadius]->m_VecVal.x;
    v46 = v7->m_nParallaxStrength < 0;
    vPackedConst6[1] = v66;
    if ( v46 || (v67 = params[v7->m_nParallaxStrength], !v67->IsDefined(this: v67)) )
      v68 = 0.25;
    else
      v68 = params[v7->m_nParallaxStrength]->m_VecVal.x;
    v69 = v27->SetPixelShaderConstant;
    vPackedConst6[3] = v68;
    v69(this: v27, a2: 6, a3: vPackedConst6, a4: 1, a5: false);
    if ( bDrawFlashlightAdditivePass )
    {
      GetHDREnabled = g_pHardwareConfig->GetHDREnabled;
      info = SLODWORD(r_flashlightbrightness.m_pParent->m_Value.m_fValue);
      if ( !GetHDREnabled(this: g_pHardwareConfig) )
        *(float *)&info = 2.0;
      v71 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
      v72 = *(float *)&info;
      if ( v71 )
        v72 = *(float *)&info * 2.5;
      v73 = v27->SetPixelShaderConstant;
      vScreenScale[0] = flashlightState.m_Color[0] * (float)(flashlightState.m_fBrightnessScale * v72);
      vScreenScale[1] = flashlightState.m_Color[1] * (float)(flashlightState.m_fBrightnessScale * v72);
      vScreenScale[2] = flashlightState.m_Color[2] * (float)(flashlightState.m_fBrightnessScale * v72);
      vScreenScale[3] = 0.0;
      v73(this: v27, a2: 28, a3: vScreenScale, a4: 1, a5: false);
      if ( pFlashlightDepthTexture != nullptr && g_pConfig->m_bShadowDepthTexture && flashlightState.m_bEnableShadows )
      {
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER6,
          nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
          pTexture: pFlashlightDepthTexture,
          nFrame: 0);
        v27->BindStandardTexture(
          this: v27,
          a2: SHADER_SAMPLER7,
          a3: TEXTURE_BINDFLAGS_NONE,
          a4: TEXTURE_SHADOW_NOISE_2D);
      }
    }
    if ( pShaderAPI == (IShaderDynamicAPI *)3 )
    {
      v27->GetWorldSpaceCameraDirection(this: v27, a2: vScreenScale);
      *(float *)&info = v27->GetFarZ(this: v27);
      v74 = v27->SetVertexShaderConstant;
      vScreenScale[0] = vScreenScale[0] * (float)(1.0 / *(float *)&info);
      vScreenScale[1] = vScreenScale[1] * (float)(1.0 / *(float *)&info);
      vScreenScale[2] = vScreenScale[2] * (float)(1.0 / *(float *)&info);
      v74(this: v27, a2: 53, a3: vScreenScale, a4: 1, a5: false);
    }
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      v81 = v27->GetSceneFogMode(this: v27);
      v82 = pShaderAPI;
      v83 = pShaderAPI == nullptr ? lightState.m_nNumLights : 0;
      LODWORD(atten[2]) = v81 == 2;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          pShaderAPI == nullptr ? lightState.m_nNumLights : 0,
          "nFixedLightingMode ? 0 : lightState.m_nNumLights");
      LODWORD(m_fHeight) = (HIBYTE(pShaderShadow) & (unsigned __int8)((v82 != nullptr) - 1)) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "FLASHLIGHTSHADOWS",
          HIBYTE(pShaderShadow) & (unsigned __int8)((v82 != nullptr) - 1),
          "nFixedLightingMode ? false : bFlashlightShadows");
      m_bUberlight = flashlightState.m_bUberlight;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "UBERLIGHT",
          flashlightState.m_bUberlight,
          "flashlightState.m_bUberlight");
      v27->SetPixelShaderIndex(
        this: v27,
        a2: LODWORD(atten[2])
      + 2 * (LODWORD(m_fHeight) + 2 * m_bUberlight + v83 + 4 * (LODWORD(m_fHeight) + 2 * m_bUberlight)));
      v27->SetScreenSizeForVPOS(this: v27, a2: 32);
      if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) && flashlightState.m_bUberlight )
      {
        v85 = v27->SetPixelShaderConstant;
        v100[1] = flashlightState.m_uberlightState.m_fCutOn;
        v101[0] = 0.0;
        v101[1] = flashlightState.m_uberlightState.m_fCutOn - flashlightState.m_uberlightState.m_fNearEdge;
        v100[2] = flashlightState.m_uberlightState.m_fFarEdge + flashlightState.m_uberlightState.m_fCutOff;
        v101[3] = 0.0;
        v100[0] = 0.0;
        v100[3] = 0.0;
        pos[0] = 0.0;
        pos[3] = 0.0;
        tweaks[0] = flashlightState.m_uberlightState.m_fShearx;
        v101[2] = flashlightState.m_uberlightState.m_fCutOff;
        pos[2] = 1.0 / flashlightState.m_uberlightState.m_fFarEdge;
        tweaks[1] = flashlightState.m_uberlightState.m_fSheary;
        tweaks[2] = 2.0 / flashlightState.m_uberlightState.m_fRoundness;
        tweaks[3] = flashlightState.m_uberlightState.m_fRoundness * -0.5;
        atten[3] = flashlightState.m_uberlightState.m_fWedge + flashlightState.m_uberlightState.m_fWidth;
        atten[2] = flashlightState.m_uberlightState.m_fWidth;
        pos[1] = 1.0 / flashlightState.m_uberlightState.m_fNearEdge;
        m_fHeight = flashlightState.m_uberlightState.m_fHeight;
        m_FarZAtten = flashlightState.m_uberlightState.m_fHedge + flashlightState.m_uberlightState.m_fHeight;
        v85(this: v27, a2: 33, a3: v101, a4: 1, a5: false);
        v27->SetPixelShaderConstant(this: v27, a2: 34, a3: v100, a4: 1, a5: false);
        v27->SetPixelShaderConstant(this: v27, a2: 35, a3: pos, a4: 1, a5: false);
        v27->SetPixelShaderConstant(this: v27, a2: 36, a3: tweaks, a4: 1, a5: false);
        v27->SetPixelShaderConstant(this: v27, a2: 37, a3: &atten[2], a4: 1, a5: false);
        QuaternionAngles(q: &flashlightState.m_quatOrientation, angles: (QAngle *)&vScreenScale[1]);
        AngleMatrix(angles: (const QAngle *)&vScreenScale[1], position: &flashlightState.m_vecLightOrigin, &matrix);
        MatrixInvert(in: &matrix, &out);
        v27->SetPixelShaderConstant(this: v27, a2: 38, a3: (const float *)&out, a4: 4, a5: false);
      }
    }
    else
    {
      v75 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      GetSceneFogMode = v27->GetSceneFogMode;
      if ( v75 )
      {
        v29 = GetSceneFogMode(this: v27) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
        v79 = lightState.m_nNumLights;
        v80 = v29;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "NUM_LIGHTS",
            lightState.m_nNumLights,
            "lightState.m_nNumLights");
        v27->SetPixelShaderIndex(this: v27, a2: v80 + 2 * v79);
      }
      else
      {
        v29 = GetSceneFogMode(this: v27) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
        vScreenScale[2] = *(float *)&lightState.m_nNumLights;
        v77 = v29;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "NUM_LIGHTS",
            lightState.m_nNumLights,
            "lightState.m_nNumLights");
        v78 = HIBYTE(pShaderShadow) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "FLASHLIGHTSHADOWS",
            HIBYTE(pShaderShadow),
            "bFlashlightShadows");
        v27->SetPixelShaderIndex(this: v27, a2: v77 + 2 * (v78 + LODWORD(vScreenScale[2]) + 4 * v78));
      }
    }
    v27->SetPixelShaderFogParams(this: v27, a2: 12);
    if ( bDrawFlashlightAdditivePass )
    {
      v86 = v27->SetPixelShaderConstant;
      atten[2] = flashlightState.m_fConstantAtten;
      atten[3] = flashlightState.m_fLinearAtten;
      m_fHeight = flashlightState.m_fQuadraticAtten;
      m_FarZAtten = flashlightState.m_FarZAtten;
      v86(this: v27, a2: 7, a3: &atten[2], a4: 1, a5: false);
      v87 = v27->SetPixelShaderConstant;
      *(Vector *)pos = flashlightState.m_vecLightOrigin;
      v87(this: v27, a2: 8, a3: pos, a4: 1, a5: false);
      v27->SetVertexShaderConstant(this: v27, a2: 54, a3: (const float *)&worldToTexture, a4: 4, a5: false);
      tweaks[0] = flashlightState.m_flShadowFilterSize * 0.0009765625;
      v88 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
      m_flShadowAtten = flashlightState.m_flShadowAtten;
      if ( v88 )
        m_flShadowAtten = flashlightState.m_flShadowAtten * 0.1;
      tweaks[1] = m_flShadowAtten;
      CBaseVSShader::HashShadow2DJitter(
        this: pShader,
        fJitterSeed: flashlightState.m_flShadowJitterSeed,
        fU: &tweaks[2],
        fV: &tweaks[3]);
      v27->SetPixelShaderConstant(this: v27, a2: 9, a3: tweaks, a4: 1, a5: false);
      GetBackBufferDimensions = v27->GetBackBufferDimensions;
      vScreenScale[0] = 40.0;
      vScreenScale[1] = 22.5;
      vScreenScale[2] = 0.0;
      vScreenScale[3] = 0.0;
      GetBackBufferDimensions(this: v27, a2: &info, a3: (int *)&pShaderAPI);
      v27->GetStandardTextureDimensions(
        this: v27,
        a2: (int *)&pShaderShadow,
        a3: &nTexHeight,
        a4: TEXTURE_SHADOW_NOISE_2D);
      v91 = v27->SetPixelShaderConstant;
      vScreenScale[0] = (float)info / (float)(int)pShaderShadow;
      vScreenScale[1] = (float)(int)pShaderAPI / (float)nTexHeight;
      vScreenScale[2] = 1.0 / flashlightState.m_flShadowMapResolution;
      vScreenScale[3] = (float)(1.0 / flashlightState.m_flShadowMapResolution) * 2.0;
      v91(this: v27, a2: 31, a3: vScreenScale, a4: 1, a5: false);
      v92 = flashlightState.m_flAmbientOcclusion * vAmbientOcclusion[3];
      vAmbientOcclusion[3] = flashlightState.m_flAmbientOcclusion * vAmbientOcclusion[3];
    }
    else
    {
      v92 = vAmbientOcclusion[3];
    }
    v93 = 0.0;
    if ( v92 <= 0.0 || (v93 = 1.0, v92 >= 1.0) )
      vAmbientOcclusion[3] = v93;
    v27->SetPixelShaderConstant(this: v27, a2: 5, a3: vAmbientOcclusion, a4: 1, a5: false);
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100110C0
// Name: void Draw_Eyes_Refract(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct Eye_Refract_Vars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Draw_Eyes_Refract(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        Eye_Refract_Vars_t *info,
        VertexCompressionType_t vertexCompression)
{
  bool v6; // al

  v6 = CBaseShader::UsingFlashlight(this: pShader, params);
  Draw_Eyes_Refract_Internal(
    pShader,
    params,
    pShaderAPI,
    pShaderShadow,
    bDrawFlashlightAdditivePass: v6,
    (int)info,
    vertexCompression);
}
