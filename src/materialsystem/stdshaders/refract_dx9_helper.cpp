// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/refract_dx9_helper.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10029AD0
// Name: void InitParamsRefract_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct Refract_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsRefract_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        Refract_DX9_Vars_t *info)
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

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  v4 = params[info->m_nEnvmapTint];
  if ( !v4->IsDefined(this: v4) )
  {
    v5 = params[info->m_nEnvmapTint];
    ((void (__thiscall *)(IMaterialVar *, int, int, int))v5->SetVecValue_2)(
      a1: v5,
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216);
  }
  v6 = params[info->m_nEnvmapContrast];
  if ( !v6->IsDefined(this: v6) )
    ((void (__stdcall *)(_DWORD))params[info->m_nEnvmapContrast]->SetFloatValue)(a1: 0);
  v7 = params[info->m_nEnvmapSaturation];
  if ( !v7->IsDefined(this: v7) )
    ((void (__stdcall *)(int))params[info->m_nEnvmapSaturation]->SetFloatValue)(a1: 1065353216);
  v8 = params[info->m_nEnvmapFrame];
  if ( !v8->IsDefined(this: v8) )
  {
    v9 = params[info->m_nEnvmapFrame];
    v9->SetIntValue(this: v9, a2: 0);
  }
  v10 = params[info->m_nFresnelReflection];
  if ( !v10->IsDefined(this: v10) )
    ((void (__stdcall *)(int))params[info->m_nFresnelReflection]->SetFloatValue)(a1: 1065353216);
  v11 = params[info->m_nMasked];
  if ( !v11->IsDefined(this: v11) )
  {
    v12 = params[info->m_nMasked];
    v12->SetIntValue(this: v12, a2: 0);
  }
  v13 = params[info->m_nBlurAmount];
  if ( !v13->IsDefined(this: v13) )
  {
    v14 = params[info->m_nBlurAmount];
    v14->SetIntValue(this: v14, a2: 0);
  }
  v15 = params[info->m_nFadeOutOnSilhouette];
  if ( !v15->IsDefined(this: v15) )
  {
    v16 = params[info->m_nFadeOutOnSilhouette];
    v16->SetIntValue(this: v16, a2: 0);
  }
  v17 = params[info->m_nNoViewportFixup];
  if ( !v17->IsDefined(this: v17) )
  {
    v18 = params[info->m_nNoViewportFixup];
    v18->SetIntValue(this: v18, a2: 0);
  }
  v19 = params[info->m_nMirrorAboutViewportEdges];
  if ( !v19->IsDefined(this: v19) )
  {
    v20 = params[info->m_nMirrorAboutViewportEdges];
    v20->SetIntValue(this: v20, a2: 0);
  }
  v21 = params[info->m_nMagnifyEnable];
  if ( !v21->IsDefined(this: v21) )
  {
    v22 = params[info->m_nMagnifyEnable];
    v22->SetIntValue(this: v22, a2: 0);
  }
  v23 = params[info->m_nMagnifyCenter];
  if ( !v23->IsDefined(this: v23) )
  {
    v24 = params[info->m_nMagnifyCenter];
    ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD, _DWORD))v24->SetVecValue)(
      a1: v24,
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0);
  }
  v25 = params[info->m_nMagnifyScale];
  if ( !v25->IsDefined(this: v25) )
  {
    v26 = params[info->m_nMagnifyScale];
    v26->SetIntValue(this: v26, a2: 0);
  }
  v27 = params[info->m_nLocalRefract];
  if ( !v27->IsDefined(this: v27) )
  {
    v28 = params[info->m_nLocalRefract];
    v28->SetIntValue(this: v28, a2: 0);
  }
  v29 = params[info->m_nLocalRefractDepth];
  if ( !v29->IsDefined(this: v29) )
    ((void (__stdcall *)(int))params[info->m_nLocalRefractDepth]->SetFloatValue)(a1: 1028443341);
  if ( params[info->m_nLocalRefract]->m_intVal == 0 )
  {
    ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x4000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029D80
// Name: void InitRefract_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct Refract_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitRefract_DX9(CBaseVSShader *pShader, IMaterialVar **params, Refract_DX9_Vars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx

  if ( params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0x80000);
  v3 = params[info->m_nNormalMap];
  if ( v3->IsDefined(this: v3) )
    CBaseShader::LoadBumpMap(this: pShader, nTextureVar: info->m_nNormalMap, nAdditionalCreationFlags: 0);
  v4 = params[info->m_nNormalMap2];
  if ( v4->IsDefined(this: v4) )
    CBaseShader::LoadBumpMap(this: pShader, nTextureVar: info->m_nNormalMap2, nAdditionalCreationFlags: 0);
  v5 = params[info->m_nEnvmap];
  if ( v5->IsDefined(this: v5) )
    CBaseShader::LoadCubeMap(this: pShader, nTextureVar: info->m_nEnvmap, nAdditionalCreationFlags: 0x80000);
  v6 = params[info->m_nRefractTintTexture];
  if ( v6->IsDefined(this: v6) )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nRefractTintTexture, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x10029E40
// Name: void DrawRefract_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct Refract_DX9_Vars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawRefract_DX9(
        CBaseVSShader *pShader,
        int params,
        IShaderDynamicAPI *pShaderAPI,
        int pShaderShadow,
        Refract_DX9_Vars_t *info,
        VertexCompressionType_t vertexCompression)
{
  int v6; // ebx
  Refract_DX9_Vars_t *v7; // edi
  IMaterialVar *v8; // eax
  int m_nRefractTintTexture; // edx
  bool v10; // zf
  char v11; // cl
  IMaterialVar *v12; // eax
  int v13; // ecx
  IMaterialVar *v14; // edx
  int m_nNormalMap2; // eax
  char v16; // dl
  int m_nVertexColorModulate; // eax
  IMaterialVar *v18; // eax
  int v19; // eax
  int v20; // edx
  bool IsTranslucent; // al
  IShaderShadow *v22; // esi
  int m_nNormalMap; // eax
  int v24; // ecx
  int v25; // eax
  BOOL v26; // ecx
  BOOL v27; // ecx
  IShaderDynamicAPI *v28; // esi
  int v29; // ebx
  IShaderShadow *v30; // eax
  int v31; // edx
  int v32; // eax
  int m_nLocalRefractDepth; // ecx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v35; // ecx
  IShaderDynamicAPI_vtbl *v36; // eax
  void (__thiscall *v37)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v38; // eax
  int v39; // eax
  bool v40; // al
  BOOL v41; // eax
  void (__thiscall *v42)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int m_nRefractAmount; // ecx
  IShaderDynamicAPI_vtbl *v44; // edx
  long double (__thiscall *CurrentTime)(IShaderDynamicAPI *); // eax
  long double v46; // st7
  IShaderDynamicAPI_vtbl *v47; // edx
  int v48; // eax
  int m_nMagnifyScale; // ecx
  float v50; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int m_nNoViewportFixup; // eax
  const char *v53; // [esp-4h] [ebp-C4h]
  float vEyePos_SpecExponent[4]; // [esp+Ch] [ebp-B4h] BYREF
  float c6[4]; // [esp+1Ch] [ebp-A4h] BYREF
  float cVs3[4]; // [esp+2Ch] [ebp-94h] BYREF
  int nViewportY; // [esp+3Ch] [ebp-84h]
  int v58; // [esp+40h] [ebp-80h] BYREF
  int nViewportHeight; // [esp+44h] [ebp-7Ch] BYREF
  int nViewportX; // [esp+48h] [ebp-78h] BYREF
  refract_ps20_Static_Index _pshIndex; // [esp+4Ch] [ebp-74h]
  float c5[4]; // [esp+78h] [ebp-48h] BYREF
  float vViewportMad[4]; // [esp+88h] [ebp-38h] BYREF
  BOOL bWriteZ; // [esp+98h] [ebp-28h]
  float v65; // [esp+9Ch] [ebp-24h] BYREF
  int v66; // [esp+A0h] [ebp-20h]
  refract_vs20_Dynamic_Index _vshIndex; // [esp+A4h] [ebp-1Ch]
  int nViewportWidth; // [esp+ACh] [ebp-14h] BYREF
  BOOL bFullyOpaque; // [esp+B0h] [ebp-10h]
  int nRtHeight; // [esp+B4h] [ebp-Ch] BYREF
  bool bIsModel; // [esp+B9h] [ebp-7h]
  bool bFadeOutOnSilhouette; // [esp+BAh] [ebp-6h]
  bool bUseMagnification; // [esp+BBh] [ebp-5h]
  bool bRefractTintTexture; // [esp+BCh] [ebp-4h]
  bool bMasked; // [esp+BDh] [ebp-3h]
  bool bColorModulate; // [esp+BEh] [ebp-2h]
  bool bHasEnvmap; // [esp+BFh] [ebp-1h]

  v6 = params;
  v7 = info;
  v8 = *(IMaterialVar **)(params + 4 * info->m_nEnvmap);
  m_nRefractTintTexture = info->m_nRefractTintTexture;
  bIsModel = (*(_DWORD *)(*(_DWORD *)params + 8) & 0x800) != 0;
  v10 = (*((_BYTE *)v8 + 28) & 0xF) == 3;
  v11 = *(_BYTE *)(*(_DWORD *)(params + 4 * m_nRefractTintTexture) + 28);
  v12 = *(IMaterialVar **)(params + 4 * info->m_nFadeOutOnSilhouette);
  bHasEnvmap = v10;
  v10 = (v11 & 0xF) == 3;
  v13 = *(_DWORD *)(*(_DWORD *)(params + 4 * info->m_nBlurAmount) + 8);
  bRefractTintTexture = v10;
  v10 = v12->m_intVal == 0;
  v14 = *(IMaterialVar **)(params + 4 * info->m_nMasked);
  m_nNormalMap2 = info->m_nNormalMap2;
  bFadeOutOnSilhouette = !v10;
  v10 = v14->m_intVal == 0;
  nRtHeight = v13;
  bMasked = !v10;
  if ( m_nNormalMap2 == -1
    || (v16 = *(_BYTE *)(*(_DWORD *)(params + 4 * m_nNormalMap2) + 28) & 0xF, HIBYTE(info) = 1, v16 != 3) )
  {
    HIBYTE(info) = 0;
  }
  m_nVertexColorModulate = v7->m_nVertexColorModulate;
  if ( m_nVertexColorModulate == -1
    || (v10 = *(_DWORD *)(*(_DWORD *)(params + 4 * m_nVertexColorModulate) + 8) == 0, bColorModulate = true, v10) )
  {
    bColorModulate = false;
  }
  v18 = *(IMaterialVar **)(params + 4 * v7->m_nMagnifyEnable);
  LOBYTE(bWriteZ) = *(_DWORD *)(*(_DWORD *)(params + 4 * v7->m_nNoWriteZ) + 8) == 0;
  bUseMagnification = v18->m_intVal != 0;
  if ( v13 >= 0 )
  {
    if ( v13 > 1 )
      nRtHeight = 1;
  }
  else
  {
    nRtHeight = 0;
  }
  v19 = CBaseVSShader::EvaluateBlendRequirements(
          this: pShader,
          textureVar: 6,
          isBaseTexture: true,
          detailTextureVar: -1);
  if ( v19 == 3 || v19 == 1 || (v20 = *(_DWORD *)(*(_DWORD *)v6 + 8) >> 8, LOBYTE(bFullyOpaque) = 1, (v20 & 1) != 0) )
    LOBYTE(bFullyOpaque) = 0;
  IsTranslucent = CBaseShader::TextureIsTranslucent(this: pShader, textureVar: v7->m_nNormalMap, isBaseTexture: false);
  v22 = (IShaderShadow *)pShaderShadow;
  LOBYTE(bFullyOpaque) = !bMasked && !IsTranslucent && bFullyOpaque;
  if ( pShaderShadow != 0 )
  {
    CBaseShader::SetInitialShadowState(this: pShader);
    v22->EnableDepthWrites(this: v22, a2: bWriteZ);
    v22->EnableAlphaTest(this: v22, a2: *(_DWORD *)(*(_DWORD *)v6 + 8) & 0x100);
    m_nNormalMap = v7->m_nNormalMap;
    if ( (*(_BYTE *)(*(_DWORD *)(v6 + 4 * m_nNormalMap) + 28) & 0xF) == 3 && !bHasEnvmap )
      CBaseShader::SetDefaultBlendingShadowState(this: pShader, textureVar: m_nNormalMap, isBaseTexture: false);
    v22->EnableTexture(this: v22, a2: SHADER_SAMPLER2, a3: true);
    v22->EnableSRGBRead(this: v22, a2: SHADER_SAMPLER2, a3: true);
    v22->EnableTexture(this: v22, a2: SHADER_SAMPLER3, a3: true);
    if ( HIBYTE(info) != 0 )
      v22->EnableTexture(this: v22, a2: SHADER_SAMPLER1, a3: true);
    if ( bHasEnvmap )
    {
      v22->EnableTexture(this: v22, a2: SHADER_SAMPLER4, a3: true);
      v22->EnableSRGBRead(this: v22, a2: SHADER_SAMPLER4, a3: true);
    }
    if ( bRefractTintTexture )
    {
      v22->EnableTexture(this: v22, a2: SHADER_SAMPLER5, a3: true);
      v22->EnableSRGBRead(this: v22, a2: SHADER_SAMPLER5, a3: true);
    }
    v22->EnableTexture(this: v22, a2: SHADER_SAMPLER6, a3: true);
    v22->EnableSRGBRead(this: v22, a2: SHADER_SAMPLER6, a3: false);
    v22->EnableSRGBWrite(this: v22, a2: true);
    v24 = 0;
    v25 = 3;
    if ( bIsModel )
      v24 = 4;
    else
      v25 = 51;
    if ( bColorModulate )
      v25 |= 4u;
    v22->VertexShaderVertexFormat(this: v22, a2: v25 | 0x400, a3: 1, a4: nullptr, a5: v24);
    nViewportY = bIsModel;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "MODEL", bIsModel, "bIsModel");
    nViewportWidth = bColorModulate;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "COLORMODULATE", bColorModulate, "bColorModulate");
    v22->SetVertexShader(this: v22, a2: "refract_vs20", a3: 4 * (nViewportY + 2 * nViewportWidth));
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BLUR", nRtHeight, "blurAmount");
      _pshIndex.m_nFADEOUTONSILHOUETTE = bFadeOutOnSilhouette;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FADEOUTONSILHOUETTE",
          bFadeOutOnSilhouette,
          "bFadeOutOnSilhouette");
      _pshIndex.m_nCUBEMAP = bHasEnvmap;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", bHasEnvmap, "bHasEnvmap");
      _pshIndex.m_nREFRACTTINTTEXTURE = bRefractTintTexture;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "REFRACTTINTTEXTURE",
          bRefractTintTexture,
          "bRefractTintTexture");
      _pshIndex.m_nMASKED = bMasked;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "MASKED", bMasked, "bMasked");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "COLORMODULATE", bColorModulate, "bColorModulate");
      }
      _pshIndex.m_nSECONDARY_NORMAL = HIBYTE(info) != 0;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "SECONDARY_NORMAL", HIBYTE(info), "bSecondaryNormal");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "MIRRORABOUTVIEWPORTEDGES", 0, "bMirrorAboutViewportEdges");
      }
      _pshIndex.m_nMAGNIFY = bUseMagnification;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "MAGNIFY", bUseMagnification, "bUseMagnification");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSRGBConvert");
      }
      v27 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * v7->m_nLocalRefract) + 8) != 0;
      pShaderShadow = v27;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "LOCALREFRACT",
          v27,
          "( params[info.m_nLocalRefract]->GetIntValue() != 0 )");
      v22->SetPixelShader(
        this: v22,
        a2: "refract_ps20b",
        a3: 8
      * (_pshIndex.m_nMAGNIFY
       + 2
       * (nRtHeight
        + 2
        * (_pshIndex.m_nFADEOUTONSILHOUETTE
         + 2
         * (_pshIndex.m_nCUBEMAP
          + 2
          * (_pshIndex.m_nREFRACTTINTTEXTURE
           + 2 * (_pshIndex.m_nMASKED + 2 * (nViewportWidth + 2 * (_pshIndex.m_nSECONDARY_NORMAL + 4 * pShaderShadow)))))))));
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BLUR", nRtHeight, "blurAmount");
      _pshIndex.m_nCUBEMAP = bFadeOutOnSilhouette;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FADEOUTONSILHOUETTE",
          bFadeOutOnSilhouette,
          "bFadeOutOnSilhouette");
      _pshIndex.m_nREFRACTTINTTEXTURE = bHasEnvmap;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", bHasEnvmap, "bHasEnvmap");
      _pshIndex.m_nMASKED = bRefractTintTexture;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "REFRACTTINTTEXTURE",
          bRefractTintTexture,
          "bRefractTintTexture");
      _pshIndex.m_nCOLORMODULATE = bMasked;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "MASKED", bMasked, "bMasked");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "COLORMODULATE", bColorModulate, "bColorModulate");
      }
      _pshIndex.m_nMIRRORABOUTVIEWPORTEDGES = HIBYTE(info) != 0;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "SECONDARY_NORMAL", HIBYTE(info), "bSecondaryNormal");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "MIRRORABOUTVIEWPORTEDGES", 0, "bMirrorAboutViewportEdges");
      }
      _pshIndex.m_nBLUR = bUseMagnification;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MAGNIFY", bUseMagnification, "bUseMagnification");
      v26 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * v7->m_nLocalRefract) + 8) != 0;
      pShaderShadow = v26;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "LOCALREFRACT",
          v26,
          "( params[info.m_nLocalRefract]->GetIntValue() != 0 )");
      v22->SetPixelShader(
        this: v22,
        a2: "refract_ps20",
        a3: 2
      * (_pshIndex.m_nBLUR
       + 2
       * (nRtHeight
        + 2
        * (_pshIndex.m_nCUBEMAP
         + 2
         * (_pshIndex.m_nREFRACTTINTTEXTURE
          + 2
          * (_pshIndex.m_nMASKED
           + 2
           * (_pshIndex.m_nCOLORMODULATE
            + 2 * (nViewportWidth + 2 * (_pshIndex.m_nMIRRORABOUTVIEWPORTEDGES + 2 * pShaderShadow)))))))));
    }
    CBaseShader::DefaultFog(this: pShader);
    if ( bMasked )
      CBaseShader::EnableAlphaBlending(
        this: pShader,
        src: SHADER_BLEND_ONE_MINUS_SRC_ALPHA,
        dst: SHADER_BLEND_SRC_ALPHA);
    v22->EnableAlphaWrites(this: v22, a2: bFullyOpaque);
  }
  v28 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetDefaultState(this: pShaderAPI);
    if ( (*(_BYTE *)(*(_DWORD *)(v6 + 4 * v7->m_nBaseTexture) + 28) & 0xF) == 3 )
    {
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER2,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: v7->m_nBaseTexture,
        nFrameVar: v7->m_nFrame);
      v29 = (***(int (__thiscall ****)(_DWORD))(v6 + 4 * v7->m_nBaseTexture))(a1: *(_DWORD *)(v6 + 4
                                                                                                 * v7->m_nBaseTexture));
      v30 = (IShaderShadow *)(*(int (__thiscall **)(int))(*(_DWORD *)v29 + 12))(a1: v29);
      v31 = *(_DWORD *)v29;
      pShaderShadow = (int)v30;
      v32 = (*(int (__thiscall **)(int))(v31 + 16))(a1: v29);
      m_nLocalRefractDepth = v7->m_nLocalRefractDepth;
      v65 = (float)(v32 / pShaderShadow);
      v66 = 1065353216;
      SetPixelShaderConstant = v28->SetPixelShaderConstant;
      _vshIndex.m_nCOMPRESSED_VERTS = *(_DWORD *)(*(_DWORD *)(params + 4 * m_nLocalRefractDepth) + 12);
      _vshIndex.m_nSKINNING = 0;
      SetPixelShaderConstant(this: v28, a2: 7, a3: &v65, a4: 1, a5: false);
      v6 = params;
    }
    else
    {
      v28->BindStandardTexture(
        this: v28,
        a2: SHADER_SAMPLER2,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
      pShaderShadow = 0;
      params = 0;
      v28->GetStandardTextureDimensions(
        this: v28,
        a2: &pShaderShadow,
        a3: &params,
        a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
      v35 = v7->m_nLocalRefractDepth;
      v36 = v28->__vftable;
      v65 = (float)(params / pShaderShadow);
      v66 = 1065353216;
      v37 = v36->SetPixelShaderConstant;
      _vshIndex.m_nCOMPRESSED_VERTS = *(_DWORD *)(*(_DWORD *)(v6 + 4 * v35) + 12);
      _vshIndex.m_nSKINNING = 0;
      v37(this: v28, a2: 7, a3: &v65, a4: 1, a5: false);
    }
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: v7->m_nNormalMap,
      nFrameVar: v7->m_nBumpFrame);
    if ( HIBYTE(info) != 0 )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: v7->m_nNormalMap2,
        nFrameVar: v7->m_nBumpFrame2);
    if ( bHasEnvmap )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER4,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: v7->m_nEnvmap,
        nFrameVar: v7->m_nEnvmapFrame);
    if ( bRefractTintTexture )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER5,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: v7->m_nRefractTintTexture,
        nFrameVar: v7->m_nRefractTintTextureFrame);
    HIBYTE(params) = v28->IsStereoActiveThisFrame(this: v28);
    if ( HIBYTE(params) != 0 )
      v28->BindStandardTexture(this: v28, a2: SHADER_SAMPLER6, a3: TEXTURE_BINDFLAGS_NONE, a4: TEXTURE_STEREO_PARAM_MAP);
    _vshIndex.m_nSKINNING = v28->GetCurrentNumBones(this: v28) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v38 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))v28->GetCurrentNumBones)(
              a1: v28,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v38 > 0, v53);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    v28->SetVertexShaderIndex(this: v28, a2: vertexCompression + 2 * _vshIndex.m_nSKINNING);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      v66 = v28->GetSceneFogMode(this: v28) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v40 = bWriteZ && bFullyOpaque && v28->ShouldWriteDepthToDestAlpha(this: v28);
      _vshIndex.m_nCOMPRESSED_VERTS = v40;
      if ( g_shaderConfigDumpEnable )
      {
        v41 = bWriteZ && bFullyOpaque && v28->ShouldWriteDepthToDestAlpha(this: v28);
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "WRITE_DEPTH_TO_DESTALPHA",
          v41,
          "bWriteZ && bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
      }
      _vshIndex.m_nSKINNING = HIBYTE(params) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "D_NVIDIA_STEREO",
          HIBYTE(params),
          "bNvidiaStereoActiveThisFrame");
      v28->SetPixelShaderIndex(this: v28, a2: v66 + 2 * (_vshIndex.m_nCOMPRESSED_VERTS + 2 * _vshIndex.m_nSKINNING));
    }
    else
    {
      v39 = v28->GetSceneFogMode(this: v28);
      v28->SetPixelShaderIndex(this: v28, a2: v39 == 2);
    }
    CBaseVSShader::SetVertexShaderTextureTransform(this: pShader, vertexReg: 49, transformVar: v7->m_nBumpTransform);
    CBaseVSShader::SetVertexShaderTextureTransform(this: pShader, vertexReg: 51, transformVar: v7->m_nBumpTransform2);
    v28->SetPixelShaderFogParams(this: v28, a2: 12);
    v28->GetWorldSpaceCameraPosition(this: v28, a2: vEyePos_SpecExponent);
    v42 = v28->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    v42(this: v28, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    CBaseVSShader::SetPixelShaderConstantGammaToLinear(this: pShader, pixelReg: 0, constantVar: v7->m_nEnvmapTint);
    CBaseVSShader::SetPixelShaderConstantGammaToLinear(this: pShader, pixelReg: 1, constantVar: v7->m_nRefractTint);
    CBaseVSShader::SetPixelShaderConstant(this: pShader, pixelReg: 2, constantVar: v7->m_nEnvmapContrast);
    CBaseVSShader::SetPixelShaderConstant(this: pShader, pixelReg: 3, constantVar: v7->m_nEnvmapSaturation);
    m_nRefractAmount = v7->m_nRefractAmount;
    v44 = v28->__vftable;
    c5[0] = *(float *)(*(_DWORD *)(v6 + 4 * m_nRefractAmount) + 12);
    CurrentTime = v44->CurrentTime;
    c5[1] = *(float *)(*(_DWORD *)(v6 + 4 * m_nRefractAmount) + 12);
    c5[2] = 0.0;
    c5[3] = 0.0;
    v46 = CurrentTime(this: v28);
    c5[3] = v46;
    v47 = v28->__vftable;
    params = (int)(float)(c5[3] * 0.001);
    c5[3] = v46 - (double)params * 1000.0;
    v47->SetPixelShaderConstant(this: v28, a2: 5, a3: c5, a4: 1, a5: false);
    v48 = *(_DWORD *)(v6 + 4 * v7->m_nMagnifyCenter);
    m_nMagnifyScale = v7->m_nMagnifyScale;
    c6[0] = *(float *)(v48 + 12);
    c6[1] = *(float *)(v48 + 16);
    v50 = *(float *)(*(_DWORD *)(v6 + 4 * m_nMagnifyScale) + 12);
    c6[2] = v50;
    if ( v50 != 0.0 )
      c6[2] = 1.0 / v50;
    v28->SetPixelShaderConstant(this: v28, a2: 6, a3: c6, a4: 1, a5: false);
    SetVertexShaderConstant = v28->SetVertexShaderConstant;
    cVs3[0] = c5[3];
    memset(&cVs3[1], 0, 12);
    SetVertexShaderConstant(this: v28, a2: 53, a3: cVs3, a4: 1, a5: false);
    v28->GetCurrentViewport(this: v28, a2: &nViewportX, a3: &v58, a4: &nViewportWidth, a5: &nViewportHeight);
    v28->GetCurrentRenderTargetDimensions(this: v28, a2: (int *)&pShaderAPI, a3: &nRtHeight);
    m_nNoViewportFixup = v7->m_nNoViewportFixup;
    vViewportMad[0] = 1.0;
    vViewportMad[1] = 1.0;
    vViewportMad[2] = 0.0;
    vViewportMad[3] = 0.0;
    if ( *(_DWORD *)(*(_DWORD *)(v6 + 4 * m_nNoViewportFixup) + 8) == 0 )
    {
      vViewportMad[0] = (float)nViewportWidth / (float)(int)pShaderAPI;
      vViewportMad[1] = (float)nViewportHeight / (float)nRtHeight;
      vViewportMad[2] = (float)nViewportX / (float)(int)pShaderAPI;
      vViewportMad[3] = (float)v58 / (float)nRtHeight;
    }
    v28->SetVertexShaderConstant(this: v28, a2: 54, a3: vViewportMad, a4: 1, a5: false);
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}
