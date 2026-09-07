// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/vortwarp_dx9.cpp
// Functions: 61
// ============================================================

#include "materialsystem\stdshaders\vortwarp_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x100406C0
// Name: public: virtual char const __near * VortWarp::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VortWarp::CShader::GetFallbackShader(VortWarp::CShader *this, IMaterialVar **params)
{
  return "VortWarp_dx9";
}

//------------------------------------------------------------------------------
// Address: 0x100406D0
// Name: public: virtual char const __near * VortWarp::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VortWarp::CShader::GetName(VortWarp::CShader *this)
{
  return s_Name_125;
}

//------------------------------------------------------------------------------
// Address: 0x100406E0
// Name: public: virtual int VortWarp::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VortWarp::CShader::GetFlags(VortWarp::CShader *this)
{
  return s_nFlags_127;
}

//------------------------------------------------------------------------------
// Address: 0x100406F0
// Name: void DrawVortWarp_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,bool,bool,struct VortWarp_DX9_Vars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawVortWarp_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        bool bVertexLitGeneric,
        bool hasFlashlight,
        VortWarp_DX9_Vars_t *info,
        VertexCompressionType_t vertexCompression)
{
  VortWarp_DX9_Vars_t *v8; // edi
  int m_nBumpmap; // eax
  char v10; // cl
  int m_intVal; // eax
  int m_nSelfIllumEnvMapMask_Alpha; // eax
  float x; // xmm0_4
  int m_nFlowMap; // eax
  char v15; // cl
  int m_nSelfIllumMap; // eax
  char v17; // al
  bool v18; // zf
  int m_nBaseTexture; // eax
  char v20; // dl
  BlendType_t v21; // eax
  bool v22; // al
  char v23; // dl
  int m_nAlphaTestReference; // eax
  float v25; // xmm0_4
  int v26; // eax
  char v27; // dl
  int v28; // ebx
  void (__thiscall *EnableTexture)(IShaderShadow *, Sampler_t, bool); // edx
  bool v30; // bl
  BOOL v31; // edi
  int v32; // eax
  float v33; // ecx
  MaterialFogMode_t v34; // eax
  MaterialFogMode_t v35; // eax
  BOOL v36; // ebx
  MaterialFogMode_t v37; // eax
  IShaderShadow_vtbl *v38; // eax
  IShaderShadow *v39; // ecx
  char v40; // cl
  bool (__thiscall *GetHDREnabled)(IMaterialSystemHardwareConfig *); // eax
  bool v42; // al
  float v43; // xmm1_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v45; // esi
  BOOL v46; // esi
  int v47; // ecx
  bool v48; // al
  __int32 v49; // eax
  float v50; // xmm0_4
  bool v51; // al
  BOOL v52; // esi
  BOOL v53; // eax
  BOOL v54; // edi
  BOOL v55; // esi
  bool v56; // al
  __int32 v57; // eax
  float v58; // xmm0_4
  bool v59; // al
  BOOL v60; // esi
  BOOL v61; // eax
  CBaseVSShader *v62; // esi
  float v63; // xmm1_4
  int m_nEntityOrigin; // ecx
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v66; // eax
  IShaderDynamicAPI_vtbl *v67; // eax
  void (__thiscall *v68)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const FlashlightState_t *v69; // esi
  void (__thiscall *v70)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v71)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int scale; // [esp+A4h] [ebp-1C4h]
  VMatrix worldToTexture; // [esp+1B0h] [ebp-B8h] BYREF
  float atten[4]; // [esp+1F0h] [ebp-78h] BYREF
  float eyePos[7]; // [esp+200h] [ebp-68h] BYREF
  float timeVec[4]; // [esp+21Ch] [ebp-4Ch] BYREF
  ITexture *pFlashlightDepthTexture; // [esp+22Ch] [ebp-3Ch] BYREF
  LightState_t lightState; // [esp+230h] [ebp-38h] BYREF
  phong_ps20b_Dynamic_Index v80; // [esp+238h] [ebp-30h] BYREF
  BlendType_t blendType; // [esp+24Ch] [ebp-1Ch]
  bool hasVertexColor; // [esp+251h] [ebp-17h]
  bool bHasNormal; // [esp+252h] [ebp-16h]
  bool hasVertexAlpha; // [esp+253h] [ebp-15h]
  BOOL bIsAlphaTested; // [esp+254h] [ebp-14h]
  bool bHasFlowMap; // [esp+25Ah] [ebp-Eh]
  bool bHasSelfIllumMap; // [esp+25Bh] [ebp-Dh]
  MaterialFogMode_t fogType; // [esp+25Ch] [ebp-Ch]
  bool hasDetailTexture; // [esp+262h] [ebp-6h]
  bool hasEnvmap; // [esp+263h] [ebp-5h]
  bool hasBaseTexture; // [esp+264h] [ebp-4h]
  bool hasBump; // [esp+265h] [ebp-3h]
  bool hasNormalMapAlphaEnvmapMask; // [esp+266h] [ebp-2h]
  bool hasEnvmapMask; // [esp+267h] [ebp-1h]
  int bVertexLitGenerica; // [esp+280h] [ebp+18h]
  BOOL bVertexLitGenericb; // [esp+280h] [ebp+18h]
  BOOL bVertexLitGenericc; // [esp+280h] [ebp+18h]
  bool bVertexLitGeneric_3; // [esp+283h] [ebp+1Bh]
  bool bVertexLitGeneric_3a; // [esp+283h] [ebp+1Bh]
  FlashlightState_t state; // 0:^B4.252

  v8 = info;
  m_nBumpmap = info->m_nBumpmap;
  hasBaseTexture = (*((_BYTE *)params[info->m_nBaseTexture] + 28) & 0xF) == 3;
  if ( m_nBumpmap == -1 || (*((_BYTE *)params[m_nBumpmap] + 28) & 0xF) != 3 )
  {
    v10 = *((_BYTE *)params[info->m_nDetail] + 28) & 0xF;
    hasBump = false;
    hasDetailTexture = true;
    if ( v10 == 3 )
      goto LABEL_6;
  }
  else
  {
    hasBump = true;
  }
  hasDetailTexture = false;
LABEL_6:
  m_intVal = (*params)->m_intVal;
  hasNormalMapAlphaEnvmapMask = (m_intVal & 0x400000) != 0;
  if ( bVertexLitGeneric )
  {
    hasVertexColor = false;
    hasVertexAlpha = false;
  }
  else
  {
    hasVertexColor = (m_intVal & 0x10) != 0;
    hasVertexAlpha = (m_intVal & 0x20) != 0;
  }
  LOBYTE(bIsAlphaTested) = BYTE1(m_intVal) & 1;
  m_nSelfIllumEnvMapMask_Alpha = info->m_nSelfIllumEnvMapMask_Alpha;
  if ( m_nSelfIllumEnvMapMask_Alpha == -1
    || (x = params[m_nSelfIllumEnvMapMask_Alpha]->m_VecVal.x, hasEnvmapMask = true, x == 0.0) )
  {
    hasEnvmapMask = false;
  }
  m_nFlowMap = info->m_nFlowMap;
  if ( m_nFlowMap == -1 || (v15 = *((_BYTE *)params[m_nFlowMap] + 28) & 0xF, bHasFlowMap = true, v15 != 3) )
    bHasFlowMap = false;
  m_nSelfIllumMap = info->m_nSelfIllumMap;
  if ( m_nSelfIllumMap == -1
    || (v17 = *((_BYTE *)params[m_nSelfIllumMap] + 28) & 0xF, bHasSelfIllumMap = true, v17 != 3) )
  {
    bHasSelfIllumMap = false;
  }
  v18 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_NONE;
  m_nBaseTexture = info->m_nBaseTexture;
  v20 = *((_BYTE *)params[info->m_nBaseTexture] + 28);
  LOBYTE(pFlashlightDepthTexture) = v18;
  if ( (v20 & 0xF) == 3 )
    v21 = CBaseVSShader::EvaluateBlendRequirements(
            this: pShader,
            textureVar: m_nBaseTexture,
            isBaseTexture: true,
            detailTextureVar: -1);
  else
    v21 = CBaseVSShader::EvaluateBlendRequirements(
            this: pShader,
            textureVar: info->m_nEnvmapMask,
            isBaseTexture: false,
            detailTextureVar: -1);
  blendType = v21;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    v22 = !hasFlashlight && (*((_BYTE *)params[info->m_nEnvmap] + 28) & 0xF) == 3;
    hasEnvmap = v22;
    if ( !hasEnvmapMask && hasFlashlight
      || (v23 = *((_BYTE *)params[info->m_nEnvmapMask] + 28) & 0xF, hasEnvmapMask = true, v23 != 3) )
    {
      hasEnvmapMask = false;
    }
    if ( bVertexLitGeneric || (bHasNormal = false, v22) )
      bHasNormal = true;
    if ( hasFlashlight )
      hasEnvmapMask = false;
    bVertexLitGeneric_3 = ((*params)->m_intVal & 0x8000000) != 0;
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: bIsAlphaTested);
    m_nAlphaTestReference = info->m_nAlphaTestReference;
    if ( m_nAlphaTestReference != -1 )
    {
      v25 = params[m_nAlphaTestReference]->m_VecVal.x;
      if ( v25 > 0.0 )
        ((void (__thiscall *)(IShaderShadow *, int, _DWORD))pShaderShadow->AlphaFunc)(
          a1: pShaderShadow,
          a2: 6,
          a3: LODWORD(v25));
    }
    v26 = info->m_nBaseTexture;
    v27 = *((_BYTE *)params[info->m_nBaseTexture] + 28) & 0xF;
    if ( hasFlashlight )
    {
      if ( v27 == 3 )
        CBaseShader::SetAdditiveBlendingShadowState(this: pShader, textureVar: v26, isBaseTexture: true);
      else
        CBaseShader::SetAdditiveBlendingShadowState(
          this: pShader,
          textureVar: info->m_nEnvmapMask,
          isBaseTexture: false);
      if ( bIsAlphaTested )
      {
        pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: false);
        pShaderShadow->DepthFunc(this: pShaderShadow, a2: SHADER_DEPTHFUNC_EQUAL);
      }
      pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    }
    else if ( v27 == 3 )
    {
      CBaseShader::SetDefaultBlendingShadowState(this: pShader, textureVar: v26, isBaseTexture: true);
    }
    else
    {
      CBaseShader::SetDefaultBlendingShadowState(this: pShader, textureVar: info->m_nEnvmapMask, isBaseTexture: false);
    }
    v28 = 1;
    *(float *)&fogType = 0.0;
    if ( bHasNormal )
      v28 = 3;
    if ( hasBaseTexture )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    }
    if ( hasEnvmap )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: (bool)pFlashlightDepthTexture);
    }
    if ( hasFlashlight )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: true);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
      fogType = 4;
    }
    if ( hasDetailTexture )
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    if ( hasBump )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
      EnableTexture = pShaderShadow->EnableTexture;
      fogType = 4;
      EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
    }
    if ( hasEnvmapMask )
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    if ( hasVertexColor || hasVertexAlpha )
      v28 |= 4u;
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    if ( bHasSelfIllumMap )
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    if ( bHasFlowMap )
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v28 | 0x400, a3: 1, a4: nullptr, a5: fogType);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      v36 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      bIsAlphaTested = bVertexLitGeneric_3;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", bVertexLitGeneric_3, "bHalfLambert");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "vortwarp_vs30", a3: 16 * (bIsAlphaTested + 2 * v36));
      LODWORD(eyePos[0]) = hasBaseTexture;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE", hasBaseTexture, "hasBaseTexture");
      LODWORD(eyePos[1]) = hasEnvmap;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", hasEnvmap, "hasEnvmap");
      v37 = params[info->m_nUnlit]->m_intVal == 0;
      fogType = v37;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DIFFUSELIGHTING", v37, "!params[info.m_nUnlit]->GetIntValue()");
      LODWORD(eyePos[3]) = hasNormalMapAlphaEnvmapMask;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "NORMALMAPALPHAENVMAPMASK",
          hasNormalMapAlphaEnvmapMask,
          "hasNormalMapAlphaEnvmapMask");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "HALFLAMBERT", bVertexLitGeneric_3, "bHalfLambert");
      }
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", hasFlashlight, "hasFlashlight");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "TRANSLUCENT", blendType == BT_BLEND, "blendType == BT_BLEND");
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "vortwarp_ps30",
        a3: 80
      * (LODWORD(eyePos[0])
       + 2
       * (LODWORD(eyePos[1])
        + 2
        * (fogType + 2 * (LODWORD(eyePos[3]) + 2 * (bIsAlphaTested + 2 * (hasFlashlight + 2 * (blendType == BT_BLEND))))))));
    }
    else
    {
      v30 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
      v31 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v80.m_nFLASHLIGHTSHADOWS = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      bIsAlphaTested = bVertexLitGeneric_3;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", bVertexLitGeneric_3, "bHalfLambert");
      v80.m_nNUM_LIGHTS = v30;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FLATTEN_STATIC_CONTROL_FLOW", v30, "bFlattenStaticControlFlow");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "vortwarp_vs20",
        a3: 24 * (bIsAlphaTested + 2 * (v80.m_nNUM_LIGHTS + 2 * (v31 + 2 * v80.m_nFLASHLIGHTSHADOWS))));
      v32 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v33 = 0.0;
      if ( v32 < 92 )
      {
        LOBYTE(v33) = hasBaseTexture;
        eyePos[0] = v33;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE", hasBaseTexture, "hasBaseTexture");
        LODWORD(eyePos[1]) = hasEnvmap;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", hasEnvmap, "hasEnvmap");
        v35 = params[info->m_nUnlit]->m_intVal == 0;
        fogType = v35;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "DIFFUSELIGHTING",
            v35,
            "!params[info.m_nUnlit]->GetIntValue()");
        LODWORD(eyePos[3]) = hasNormalMapAlphaEnvmapMask;
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "NORMALMAPALPHAENVMAPMASK",
            hasNormalMapAlphaEnvmapMask,
            "hasNormalMapAlphaEnvmapMask");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS stat var %s = %d (%s)", "HALFLAMBERT", bVertexLitGeneric_3, "bHalfLambert");
        }
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", hasFlashlight, "hasFlashlight");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "TRANSLUCENT", blendType == BT_BLEND, "blendType == BT_BLEND");
        pShaderShadow->SetPixelShader(
          this: pShaderShadow,
          a2: "vortwarp_ps20",
          a3: 48
        * (LODWORD(eyePos[0])
         + 2
         * (LODWORD(eyePos[1])
          + 2
          * (fogType
           + 2 * (LODWORD(eyePos[3]) + 2 * (bIsAlphaTested + 2 * (hasFlashlight + 2 * (blendType == BT_BLEND))))))));
      }
      else
      {
        LOBYTE(v33) = hasBaseTexture;
        eyePos[0] = v33;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE", hasBaseTexture, "hasBaseTexture");
        LODWORD(eyePos[1]) = hasEnvmap;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", hasEnvmap, "hasEnvmap");
        v34 = params[info->m_nUnlit]->m_intVal == 0;
        fogType = v34;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "DIFFUSELIGHTING",
            v34,
            "!params[info.m_nUnlit]->GetIntValue()");
        LODWORD(eyePos[3]) = hasNormalMapAlphaEnvmapMask;
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "NORMALMAPALPHAENVMAPMASK",
            hasNormalMapAlphaEnvmapMask,
            "hasNormalMapAlphaEnvmapMask");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS stat var %s = %d (%s)", "HALFLAMBERT", bVertexLitGeneric_3, "bHalfLambert");
        }
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", hasFlashlight, "hasFlashlight");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "TRANSLUCENT", blendType == BT_BLEND, "blendType == BT_BLEND");
        pShaderShadow->SetPixelShader(
          this: pShaderShadow,
          a2: "vortwarp_ps20b",
          a3: 80
        * (LODWORD(eyePos[0])
         + 2
         * (LODWORD(eyePos[1])
          + 2
          * (fogType
           + 2 * (LODWORD(eyePos[3]) + 2 * (bIsAlphaTested + 2 * (hasFlashlight + 2 * (blendType == BT_BLEND))))))));
      }
    }
    if ( hasFlashlight )
      CBaseShader::FogToBlack(this: pShader);
    else
      CBaseShader::DefaultFog(this: pShader);
    v38 = pShaderShadow->__vftable;
    scale = 1;
    v39 = pShaderShadow;
    if ( blendType == BT_BLEND )
    {
      v38->EnableBlending(this: pShaderShadow, a2: true);
      pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
      v38 = pShaderShadow->__vftable;
      scale = 0;
      v39 = pShaderShadow;
    }
    v38->EnableAlphaWrites(this: v39, a2: scale);
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    if ( hasBump )
    {
      CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 5);
      CBaseShader::PI_SetPixelShaderLocalLighting(this: pShader, nFirstRegister: 13);
    }
    CBaseShader::PI_SetVertexShaderAmbientLightCube(this: pShader);
    if ( info->m_nHDRColorScale == -1 || !CBaseShader::IsHDREnabled(this: pShader) )
    {
      CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace(this: pShader, nRegister: 1);
      CBaseShader::PI_EndCommandBuffer(this: pShader);
      CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
    }
    else
    {
      CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace_LinearScale(
        this: pShader,
        nRegister: 1,
        scale: params[info->m_nHDRColorScale]->m_VecVal.x);
      CBaseShader::PI_EndCommandBuffer(this: pShader);
      CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
    }
    return;
  }
  if ( hasFlashlight || (*((_BYTE *)params[info->m_nEnvmap] + 28) & 0xF) != 3 )
  {
    hasEnvmapMask = false;
    if ( hasFlashlight )
    {
LABEL_135:
      hasNormalMapAlphaEnvmapMask = false;
      goto LABEL_136;
    }
  }
  else
  {
    hasEnvmapMask = true;
  }
  v40 = *((_BYTE *)params[info->m_nEnvmapMask] + 28) & 0xF;
  hasNormalMapAlphaEnvmapMask = true;
  if ( v40 != 3 )
    goto LABEL_135;
LABEL_136:
  if ( hasBaseTexture )
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: info->m_nBaseTexture,
      nFrameVar: info->m_nBaseTextureFrame);
  if ( hasEnvmapMask )
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: (unsigned __int8)pFlashlightDepthTexture != 0 ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nEnvmap,
      nFrameVar: info->m_nEnvmapFrame);
  if ( hasDetailTexture )
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nDetail,
      nFrameVar: info->m_nDetailFrame);
  if ( g_pConfig->m_bFastNoBump )
  {
    if ( hasBump )
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER3,
        a3: TEXTURE_BINDFLAGS_NONE,
        a4: TEXTURE_NORMALMAP_FLAT);
  }
  else if ( hasBump )
  {
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nBumpmap,
      nFrameVar: info->m_nBumpFrame);
  }
  if ( hasNormalMapAlphaEnvmapMask )
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER4,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nEnvmapMask,
      nFrameVar: info->m_nEnvmapMaskFrame);
  if ( hasFlashlight )
  {
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER7,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: info->m_nFlashlightTexture,
      nFrameVar: info->m_nFlashlightTextureFrame);
    state = *pShaderAPI->GetFlashlightStateEx(this: pShaderAPI, a2: &worldToTexture, a3: &pFlashlightDepthTexture);
    GetHDREnabled = g_pHardwareConfig->GetHDREnabled;
    fogType = SLODWORD(r_flashlightbrightness.m_pParent->m_Value.m_fValue);
    if ( !GetHDREnabled(this: g_pHardwareConfig) )
      *(float *)&fogType = 2.0;
    v42 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
    v43 = *(float *)&fogType;
    if ( v42 )
      v43 = *(float *)&fogType * 2.5;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    atten[0] = state.m_Color[0] * (float)(state.m_fBrightnessScale * v43);
    atten[1] = state.m_Color[1] * (float)(state.m_fBrightnessScale * v43);
    atten[2] = state.m_Color[2] * (float)(state.m_fBrightnessScale * v43);
    atten[3] = 0.0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 28, a3: atten, a4: 1, a5: false);
    v8 = info;
  }
  lightState.m_nNumLights = 0;
  *(_WORD *)&lightState.m_bAmbientLight = 0;
  if ( bVertexLitGeneric && !hasFlashlight )
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: &lightState);
  *(float *)&fogType = COERCE_FLOAT(pShaderAPI->GetSceneFogMode(this: pShaderAPI));
  v45 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI);
  if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
  {
    CBaseVSShader::SetHWMorphVertexShaderState(
      this: pShader,
      nDimConst: 54,
      nSubrectConst: 55,
      morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
    v54 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v80.m_nFLASHLIGHTSHADOWS = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
    v55 = v45 > 0;
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v55, "numBones > 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: vertexCompression + 2 * (v54 + 2 * (v55 + 2 * v80.m_nFLASHLIGHTSHADOWS)));
    v18 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v80.m_nFLASHLIGHTSHADOWS = lightState.m_nNumLights;
    v80.m_nPIXELFOGTYPE = v18;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", lightState.m_nNumLights, "lightState.m_nNumLights");
    bVertexLitGenericc = lightState.m_bAmbientLight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "AMBIENT_LIGHT",
        lightState.m_bAmbientLight,
        "lightState.m_bAmbientLight ? 1 : 0");
    v56 = fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z
       && blendType != BT_BLENDADD
       && blendType != BT_BLEND
       && !bIsAlphaTested;
    v80.m_nWRITEWATERFOGTODESTALPHA = v56;
    if ( g_shaderConfigDumpEnable )
    {
      if ( fogType != MATERIAL_FOG_LINEAR_BELOW_FOG_Z
        || blendType == BT_BLENDADD
        || blendType == BT_BLEND
        || bIsAlphaTested )
      {
        v57 = 0;
      }
      else
      {
        v57 = fogType - 1;
      }
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITEWATERFOGTODESTALPHA",
        v57,
        "fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z && blendType != BT_BLENDADD && blendType != BT_BLEND && !bIsAlphaTested");
    }
    v58 = params[info->m_nWarpParam]->m_VecVal.x;
    v59 = v58 > 0.0 && v58 < 1.0;
    v60 = v59;
    if ( g_shaderConfigDumpEnable )
    {
      v61 = (float)(int)v58 > 0.0 && v58 < 1.0;
      printf(format: "\n   PS dyn  var %s = %d (%s)", "WARPINGIN", v61, "warpParam > 0.0f && warpParam < 1.0f");
    }
    pShaderAPI->SetPixelShaderIndex(
      this: pShaderAPI,
      a2: v80.m_nWRITEWATERFOGTODESTALPHA
    + 2 * (v80.m_nPIXELFOGTYPE + 2 * (v60 + 2 * (bVertexLitGenericc + 2 * v80.m_nFLASHLIGHTSHADOWS))));
    v8 = info;
  }
  else
  {
    bVertexLitGeneric_3a = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
    v80.m_nNUM_LIGHTS = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v46 = v45 > 0;
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v46, "numBones > 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    v47 = bVertexLitGeneric_3a ? 0 : lightState.m_nNumLights;
    bVertexLitGenerica = v47;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        v47,
        "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: vertexCompression + 2 * (v80.m_nNUM_LIGHTS + 2 * (v46 + 2 * bVertexLitGenerica)));
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    phong_ps20b_Dynamic_Index::phong_ps20b_Dynamic_Index(this: &v80, pShaderAPI);
    v80.m_nFLASHLIGHTSHADOWS = lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", lightState.m_nNumLights, "lightState.m_nNumLights");
    bVertexLitGenericb = lightState.m_bAmbientLight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "AMBIENT_LIGHT",
        lightState.m_bAmbientLight,
        "lightState.m_bAmbientLight ? 1 : 0");
    v48 = fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z
       && blendType != BT_BLENDADD
       && blendType != BT_BLEND
       && !bIsAlphaTested;
    v80.m_nWRITEWATERFOGTODESTALPHA = v48;
    if ( g_shaderConfigDumpEnable )
    {
      if ( fogType != MATERIAL_FOG_LINEAR_BELOW_FOG_Z
        || blendType == BT_BLENDADD
        || blendType == BT_BLEND
        || bIsAlphaTested )
      {
        v49 = 0;
      }
      else
      {
        v49 = fogType - 1;
      }
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITEWATERFOGTODESTALPHA",
        v49,
        "fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z && blendType != BT_BLENDADD && blendType != BT_BLEND && !bIsAlphaTested");
    }
    v50 = params[v8->m_nWarpParam]->m_VecVal.x;
    v51 = v50 > 0.0 && v50 < 1.0;
    v52 = v51;
    if ( g_shaderConfigDumpEnable )
    {
      v53 = (float)(int)v50 > 0.0 && v50 < 1.0;
      printf(format: "\n   PS dyn  var %s = %d (%s)", "WARPINGIN", v53, "warpParam > 0.0f && warpParam < 1.0f");
    }
    pShaderAPI->SetPixelShaderIndex(
      this: pShaderAPI,
      a2: v80.m_nWRITEWATERFOGTODESTALPHA
    + 2 * (v80.m_nPIXELFOGTYPE + 2 * (v52 + 2 * (bVertexLitGenericb + 2 * v80.m_nFLASHLIGHTSHADOWS))));
  }
  v62 = pShader;
  CBaseVSShader::SetVertexShaderTextureTransform(
    this: pShader,
    vertexReg: 48,
    transformVar: v8->m_nBaseTextureTransform);
  if ( hasDetailTexture )
    CBaseVSShader::SetVertexShaderTextureScaledTransform(
      this: pShader,
      a2: (int)pShader,
      vertexReg: 50,
      transformVar: v8->m_nBaseTextureTransform,
      scaleVar: v8->m_nDetailScale);
  if ( hasBump )
    CBaseVSShader::SetVertexShaderTextureTransform(this: pShader, vertexReg: 50, transformVar: v8->m_nBumpTransform);
  if ( hasNormalMapAlphaEnvmapMask )
    CBaseVSShader::SetVertexShaderTextureTransform(
      this: pShader,
      vertexReg: 52,
      transformVar: v8->m_nEnvmapMaskTransform);
  if ( hasEnvmapMask )
    CBaseVSShader::SetEnvMapTintPixelShaderDynamicState(
      this: pShader,
      pixelReg: 0,
      tintVar: v8->m_nEnvmapTint,
      alphaVar: -1,
      bConvertFromGammaToLinear: true);
  CBaseVSShader::SetPixelShaderConstant(this: pShader, pixelReg: 2, constantVar: v8->m_nEnvmapContrast);
  CBaseVSShader::SetPixelShaderConstant(this: pShader, pixelReg: 3, constantVar: v8->m_nEnvmapSaturation);
  CBaseVSShader::SetPixelShaderConstant(this: pShader, pixelReg: 4, constantVar: v8->m_nSelfIllumTint);
  if ( hasBump )
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER5,
      a3: TEXTURE_BINDFLAGS_NONE,
      a4: TEXTURE_NORMALIZATION_CUBEMAP_SIGNED);
  if ( bHasSelfIllumMap )
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER6,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: v8->m_nSelfIllumMap,
      nFrameVar: -1);
  if ( bHasFlowMap )
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: v8->m_nFlowMap,
      nFrameVar: -1);
  pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: &eyePos[3]);
  pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 20, a3: &eyePos[3], a4: 1, a5: false);
  pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 21);
  v63 = params[v8->m_nWarpParam]->m_VecVal.x;
  m_nEntityOrigin = v8->m_nEntityOrigin;
  SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
  memset(timeVec, 0, 12);
  timeVec[3] = v63;
  v66 = params[m_nEntityOrigin];
  timeVec[0] = v66->m_VecVal.x;
  timeVec[1] = v66->m_VecVal.y;
  timeVec[2] = v66->m_VecVal.z;
  SetVertexShaderConstant(this: pShaderAPI, a2: 52, a3: timeVec, a4: 1, a5: false);
  timeVec[0] = pShaderAPI->CurrentTime(this: pShaderAPI);
  v67 = pShaderAPI->__vftable;
  timeVec[1] = timeVec[0];
  v68 = v67->SetPixelShaderConstant;
  timeVec[2] = timeVec[0];
  timeVec[3] = timeVec[0];
  v68(this: pShaderAPI, a2: 22, a3: timeVec, a4: 1, a5: false);
  if ( hasFlashlight )
  {
    v69 = pShaderAPI->GetFlashlightState(this: pShaderAPI, a2: &worldToTexture);
    v70 = pShaderAPI->SetPixelShaderConstant;
    atten[0] = v69->m_fConstantAtten;
    atten[1] = v69->m_fLinearAtten;
    atten[2] = v69->m_fQuadraticAtten;
    atten[3] = v69->m_FarZAtten;
    v70(this: pShaderAPI, a2: 22, a3: atten, a4: 1, a5: false);
    v71 = pShaderAPI->SetPixelShaderConstant;
    v80.m_nPIXELFOGTYPE = LODWORD(v69->m_vecLightOrigin.x);
    v80.m_nNUM_LIGHTS = LODWORD(v69->m_vecLightOrigin.y);
    v80.m_nWRITE_DEPTH_TO_DESTALPHA = LODWORD(v69->m_vecLightOrigin.z);
    v80.m_nFLASHLIGHTSHADOWS = LODWORD(v69->m_FarZ);
    v71(this: pShaderAPI, a2: 23, a3: (const float *)&v80.m_nPIXELFOGTYPE, a4: 1, a5: false);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 24, a3: (const float *)&worldToTexture, a4: 4, a5: false);
    v62 = pShader;
  }
  CBaseShader::Draw(this: v62, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10041A00
// Name: public: virtual int VortWarp::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VortWarp::CShader::GetParamCount(VortWarp::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_125.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10041A10
// Name: public: void VortWarp_DX9::CShader::SetupVars(struct VortWarp_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VortWarp_DX9::CShader::SetupVars(VortWarp_DX9::CShader *this, VortWarp_DX9_Vars_t *info)
{
  info->m_nBaseTexture = 6;
  info->m_nBaseTextureFrame = 7;
  info->m_nBaseTextureTransform = 8;
  info->m_nAlbedo = ALBEDO_1.m_Index;
  info->m_nSelfIllumTint = SELFILLUMTINT_2.m_Index;
  info->m_nDetail = DETAIL_3.m_Index;
  info->m_nDetailFrame = DETAILFRAME_2.m_Index;
  info->m_nDetailScale = DETAILSCALE_3.m_Index;
  info->m_nEnvmap = ENVMAP_7.m_Index;
  info->m_nEnvmapFrame = ENVMAPFRAME_4.m_Index;
  info->m_nEnvmapMask = ENVMAPMASK_4.m_Index;
  info->m_nEnvmapMaskFrame = ENVMAPMASKFRAME_4.m_Index;
  info->m_nEnvmapMaskTransform = ENVMAPMASKTRANSFORM_3.m_Index;
  info->m_nEnvmapTint = ENVMAPTINT_5.m_Index;
  info->m_nBumpmap = BUMPMAP_9.m_Index;
  info->m_nBumpFrame = BUMPFRAME_12.m_Index;
  info->m_nBumpTransform = BUMPTRANSFORM_6.m_Index;
  info->m_nEnvmapContrast = ENVMAPCONTRAST_4.m_Index;
  info->m_nEnvmapSaturation = ENVMAPSATURATION_4.m_Index;
  info->m_nAlphaTestReference = -1;
  info->m_nFlashlightTexture = 9;
  info->m_nFlashlightTextureFrame = 10;
  info->m_nSelfIllumEnvMapMask_Alpha = SELFILLUM_ENVMAPMASK_ALPHA_0.m_Index;
  info->m_nAmbientOnly = AMBIENTONLY_0.m_Index;
  info->m_nEntityOrigin = ENTITYORIGIN_2.m_Index;
  info->m_nWarpParam = WARPPARAM_2.m_Index;
  info->m_nFlowMap = FLOWMAP_0.m_Index;
  info->m_nSelfIllumMap = SELFILLUMMAP.m_Index;
  info->m_nUnlit = UNLIT.m_Index;
  info->m_nPhongExponent = PHONGEXPONENT_6.m_Index;
  info->m_nPhongExponentTexture = PHONGEXPONENTTEXTURE_2.m_Index;
  info->m_nDiffuseWarpTexture = LIGHTWARPTEXTURE_6.m_Index;
  info->m_nPhongWarpTexture = PHONGWARPTEXTURE_1.m_Index;
  info->m_nPhongBoost = PHONGBOOST_5.m_Index;
  info->m_nPhongFresnelRanges = PHONGFRESNELRANGES_2.m_Index;
  info->m_nPhong = PHONG_1.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10041B80
// Name: public: virtual void VortWarp_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VortWarp_DX9::CShader::OnInitShaderParams(
        VortWarp_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  VortWarp_DX9_Vars_t vars; // [esp+20h] [ebp-1D0h] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  if ( !params[BUMPMAP_9.m_Index]->IsDefined(this: params[BUMPMAP_9.m_Index]) )
    params[BUMPMAP_9.m_Index]->SetStringValue(this: params[BUMPMAP_9.m_Index], a2: "dev/flat_normal");
  VortWarp_DX9::CShader::SetupVars(this, info: &vars);
  if ( !params[UNLIT.m_Index]->IsDefined(this: params[UNLIT.m_Index]) )
    params[UNLIT.m_Index]->SetIntValue(this: params[UNLIT.m_Index], a2: 0);
  if ( !params[SELFILLUMTINT_2.m_Index]->IsDefined(this: params[SELFILLUMTINT_2.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD, _DWORD))params[SELFILLUMTINT_2.m_Index]->SetVecValue)(
      a1: params[SELFILLUMTINT_2.m_Index],
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0);
  InitParamsVertexLitGeneric_DX9(pShader: this, params, pMaterialName, bVertexLitGeneric: true, info: &vars);
}

//------------------------------------------------------------------------------
// Address: 0x10041C70
// Name: public: virtual char const __near * VortWarp_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VortWarp_DX9::CShader::GetName(VortWarp_DX9::CShader *this)
{
  return s_Name_126;
}

//------------------------------------------------------------------------------
// Address: 0x10041C80
// Name: public: virtual int VortWarp_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VortWarp_DX9::CShader::GetFlags(VortWarp_DX9::CShader *this)
{
  return s_nFlags_128;
}

//------------------------------------------------------------------------------
// Address: 0x10041C90
// Name: public: virtual void VortWarp_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VortWarp_DX9::CShader::OnInitShaderInstance(
        VortWarp_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  VortWarp_DX9_Vars_t vars; // [esp+8h] [ebp-1D0h] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  VortWarp_DX9::CShader::SetupVars(this, info: &vars);
  InitVertexLitGeneric_DX9(pShader: this, params, bVertexLitGeneric: true, info: &vars);
  if ( params[FLOWMAP_0.m_Index]->IsDefined(this: params[FLOWMAP_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: FLOWMAP_0.m_Index, nAdditionalCreationFlags: 0);
  if ( params[SELFILLUMMAP.m_Index]->IsDefined(this: params[SELFILLUMMAP.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: SELFILLUMMAP.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10041D30
// Name: public: virtual void VortWarp_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VortWarp_DX9::CShader::OnDrawElements(
        VortWarp_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v7; // al
  VortWarp_DX9_Vars_t vars; // [esp+8h] [ebp-1D0h] BYREF

  memset(dst: (unsigned __int8 *)&vars, value: 0xFFu, count: sizeof(vars));
  VortWarp_DX9::CShader::SetupVars(this, info: &vars);
  v7 = CBaseShader::UsingFlashlight(this, params);
  DrawVortWarp_DX9(
    pShader: this,
    params,
    pShaderAPI,
    pShaderShadow,
    bVertexLitGeneric: true,
    hasFlashlight: v7,
    info: &vars,
    vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10041DA0
// Name: public: virtual int VortWarp_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall VortWarp_DX9::CShader::GetParamCount(VortWarp_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_126.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10041DB0
// Name: public: virtual struct ShaderParamInfo_t const __near & VortWarp::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
VortWarp::CShaderParam *__thiscall VortWarp::CShader::GetParamInfo(VortWarp::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_125.m_Memory.m_pMemory[param - ParamCount];
  else
    return (VortWarp::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10041DE0
// Name: public: virtual struct ShaderParamInfo_t const __near & VortWarp_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *__thiscall VortWarp_DX9::CShader::GetParamInfo(VortWarp_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_126.m_Memory.m_pMemory[param - ParamCount];
  else
    return (VortWarp_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10041E10
// Name: public: VortWarp_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *__thiscall VortWarp_DX9::CShaderParam::CShaderParam(
        VortWarp_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  VortWarp_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  VortWarp_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_126.m_Size + 13;
  m_Size = s_ShaderParams_126.m_Size;
  v8 = s_ShaderParams_126.m_Size;
  if ( s_ShaderParams_126.m_Size + 1 > s_ShaderParams_126.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_126,
      num: s_ShaderParams_126.m_Size - s_ShaderParams_126.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_126.m_Size;
  }
  m_pMemory = s_ShaderParams_126.m_Memory.m_pMemory;
  s_ShaderParams_126.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_126.m_pElements = s_ShaderParams_126.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_126.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_126.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_126.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10069760
// Name: VortWarp::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int VortWarp::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: VortWarp::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10069770
// Name: VortWarp::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *VortWarp::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_125);
  s_ShaderInstance_125.__vftable = (VortWarp::CShader_vtbl *)&VortWarp::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10069790
// Name: VortWarp_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int VortWarp_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: VortWarp_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100697A0
// Name: VortWarp_DX9::_dynamic_initializer_for__ALBEDO__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ALBEDO__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ALBEDO_1,
           pName: "$ALBEDO",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "albedo (Base texture with no baked lighting)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100697C0
// Name: VortWarp_DX9::_dynamic_initializer_for__SELFILLUMTINT__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__SELFILLUMTINT__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &SELFILLUMTINT_2,
           pName: "$SELFILLUMTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Self-illumination tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100697E0
// Name: VortWarp_DX9::_dynamic_initializer_for__DETAIL__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__DETAIL__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &DETAIL_3,
           pName: "$DETAIL",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/detail",
           pHelp: "detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069800
// Name: VortWarp_DX9::_dynamic_initializer_for__DETAILFRAME__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__DETAILFRAME__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &DETAILFRAME_2,
           pName: "$DETAILFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $detail",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069820
// Name: VortWarp_DX9::_dynamic_initializer_for__DETAILSCALE__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__DETAILSCALE__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &DETAILSCALE_3,
           pName: "$DETAILSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "4",
           pHelp: "scale of the detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069840
// Name: VortWarp_DX9::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENVMAP__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENVMAP_7,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069860
// Name: VortWarp_DX9::_dynamic_initializer_for__ENVMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENVMAPFRAME__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPFRAME_4,
           pName: "$ENVMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "envmap frame number",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069880
// Name: VortWarp_DX9::_dynamic_initializer_for__ENVMAPMASK__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENVMAPMASK__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPMASK_4,
           pName: "$ENVMAPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_envmask",
           pHelp: "envmap mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100698A0
// Name: VortWarp_DX9::_dynamic_initializer_for__ENVMAPMASKFRAME__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENVMAPMASKFRAME__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPMASKFRAME_4,
           pName: "$ENVMAPMASKFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100698C0
// Name: VortWarp_DX9::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPMASKTRANSFORM_3,
           pName: "$ENVMAPMASKTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$envmapmask texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100698E0
// Name: VortWarp_DX9::_dynamic_initializer_for__ENVMAPTINT__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENVMAPTINT__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPTINT_5,
           pName: "$ENVMAPTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "envmap tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069900
// Name: VortWarp_DX9::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__BUMPMAP__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &BUMPMAP_9,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069920
// Name: VortWarp_DX9::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__BUMPFRAME__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &BUMPFRAME_12,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069940
// Name: VortWarp_DX9::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_6,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069960
// Name: VortWarp_DX9::_dynamic_initializer_for__ENVMAPCONTRAST__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENVMAPCONTRAST__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPCONTRAST_4,
           pName: "$ENVMAPCONTRAST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "contrast 0 == normal 1 == color*color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069980
// Name: VortWarp_DX9::_dynamic_initializer_for__ENVMAPSATURATION__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENVMAPSATURATION__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENVMAPSATURATION_4,
           pName: "$ENVMAPSATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "saturation 0 == greyscale 1 == normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100699A0
// Name: VortWarp_DX9::_dynamic_initializer_for__SELFILLUM_ENVMAPMASK_ALPHA__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__SELFILLUM_ENVMAPMASK_ALPHA__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &SELFILLUM_ENVMAPMASK_ALPHA_0,
           pName: "$SELFILLUM_ENVMAPMASK_ALPHA",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "defines that self illum value comes from env map mask alpha",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100699C0
// Name: VortWarp_DX9::_dynamic_initializer_for__AMBIENTONLY__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__AMBIENTONLY__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &AMBIENTONLY_0,
           pName: "$AMBIENTONLY",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Control drawing of non-ambient light ()",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100699E0
// Name: VortWarp_DX9::_dynamic_initializer_for__ENTITYORIGIN__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__ENTITYORIGIN__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &ENTITYORIGIN_2,
           pName: "$ENTITYORIGIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "0.0",
           pHelp: "center if the model in world space",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069A00
// Name: VortWarp_DX9::_dynamic_initializer_for__WARPPARAM__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__WARPPARAM__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &WARPPARAM_2,
           pName: "$WARPPARAM",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "animation param between 0 and 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069A20
// Name: VortWarp_DX9::_dynamic_initializer_for__FLOWMAP__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__FLOWMAP__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &FLOWMAP_0,
           pName: "$FLOWMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "flow map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069A40
// Name: VortWarp_DX9::_dynamic_initializer_for__SELFILLUMMAP__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__SELFILLUMMAP__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &SELFILLUMMAP,
           pName: "$SELFILLUMMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "self-illumination map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069A60
// Name: VortWarp_DX9::_dynamic_initializer_for__UNLIT__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__UNLIT__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &UNLIT,
           pName: "$UNLIT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069A80
// Name: VortWarp_DX9::_dynamic_initializer_for__PHONGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__PHONGEXPONENT__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT_6,
           pName: "$PHONGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "5.0",
           pHelp: "Phong exponent for local specular lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069AA0
// Name: VortWarp_DX9::_dynamic_initializer_for__PHONGTINT__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__PHONGTINT__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &PHONGTINT_2,
           pName: "$PHONGTINT",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "5.0",
           pHelp: "Phong tint for local specular lights",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069AC0
// Name: VortWarp_DX9::_dynamic_initializer_for__PHONGALBEDOTINT__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__PHONGALBEDOTINT__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &PHONGALBEDOTINT_2,
           pName: "$PHONGALBEDOTINT",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1.0",
           pHelp: "Apply tint by albedo (controlled by spec exponent texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069AE0
// Name: VortWarp_DX9::_dynamic_initializer_for__LIGHTWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__LIGHTWARPTEXTURE__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &LIGHTWARPTEXTURE_6,
           pName: "$LIGHTWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "1D ramp texture for tinting scalar diffuse term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069B00
// Name: VortWarp_DX9::_dynamic_initializer_for__PHONGWARPTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__PHONGWARPTEXTURE__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &PHONGWARPTEXTURE_1,
           pName: "$PHONGWARPTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "warp specular term",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069B20
// Name: VortWarp_DX9::_dynamic_initializer_for__PHONGFRESNELRANGES__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__PHONGFRESNELRANGES__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &PHONGFRESNELRANGES_2,
           pName: "$PHONGFRESNELRANGES",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0  0.5  1]",
           pHelp: "Parameters for remapping fresnel output",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069B40
// Name: VortWarp_DX9::_dynamic_initializer_for__PHONGBOOST__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__PHONGBOOST__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &PHONGBOOST_5,
           pName: "$PHONGBOOST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "Phong overbrightening factor (specular mask channel should be authored to account for this)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069B60
// Name: VortWarp_DX9::_dynamic_initializer_for__PHONGEXPONENTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__PHONGEXPONENTTEXTURE__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENTTEXTURE_2,
           pName: "$PHONGEXPONENTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "Phong Exponent map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069B80
// Name: VortWarp_DX9::_dynamic_initializer_for__PHONG__
// Source: json
//------------------------------------------------------------------------------
VortWarp_DX9::CShaderParam *VortWarp_DX9::_dynamic_initializer_for__PHONG__()
{
  return VortWarp_DX9::CShaderParam::CShaderParam(
           this: &PHONG_1,
           pName: "$PHONG",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "enables phong lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069BA0
// Name: VortWarp_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *VortWarp_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_126);
  s_ShaderInstance_126.__vftable = (VortWarp_DX9::CShader_vtbl *)&VortWarp_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B8D0
// Name: VortWarp::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl VortWarp::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_125);
}

//------------------------------------------------------------------------------
// Address: 0x1006B8E0
// Name: VortWarp_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl VortWarp_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_126);
}

//------------------------------------------------------------------------------
// Address: 0x10069BC0
// Name: _dynamic_initializer_for__r_buildingmapforworld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_buildingmapforworld__()
{
  ConVar::ConVar(this: &r_buildingmapforworld, pName: "r_buildingmapforworld", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_buildingmapforworld__);
}

//------------------------------------------------------------------------------
// Address: 0x10069BF0
// Name: _dynamic_initializer_for__s_ConstructMe_WaterCheap_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_WaterCheap_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &WaterCheap_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069C10
// Name: _dynamic_initializer_for__s_ConstructMe_WaterCheap_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_WaterCheap_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &WaterCheap_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069C30
// Name: _dynamic_initializer_for__s_ConstructMe_WaterCheap_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_WaterCheap_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &WaterCheap_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069C50
// Name: _dynamic_initializer_for__s_ConstructMe_Water_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Water_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Water_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069C70
// Name: _dynamic_initializer_for__s_ConstructMe_Water_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Water_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Water_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10069C90
// Name: _dynamic_initializer_for__s_ConstructMe_Water_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_Water_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &Water_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x1006B8F0
// Name: _dynamic_atexit_destructor_for__r_buildingmapforworld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_buildingmapforworld__()
{
  ConVar::~ConVar(this: &r_buildingmapforworld);
}
