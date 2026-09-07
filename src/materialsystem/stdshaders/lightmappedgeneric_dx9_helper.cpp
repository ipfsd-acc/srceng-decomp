// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/lightmappedgeneric_dx9_helper.cpp
// Functions: 8
// ============================================================

#include "materialsystem\stdshaders\lightmappedgeneric_dx9_helper.h"

//------------------------------------------------------------------------------
// Address: 0x100172B0
// Name: public: int lightmappedgeneric_ps20_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall lightmappedgeneric_ps20_Static_Index::GetIndex(lightmappedgeneric_ps20_Static_Index *this)
{
  return 16
       * (this->m_nBASETEXTURE2
        + 2
        * (this->m_nBUMPMAP
         + 3
         * (this->m_nBUMPMAP2
          + 2
          * (this->m_nCUBEMAP
           + 3
           * (this->m_nENVMAPMASK
            + 2
            * (this->m_nBASEALPHAENVMAPMASK
             + 2
             * (this->m_nSELFILLUM
              + 2
              * (this->m_nNORMALMAPALPHAENVMAPMASK
               + 2
               * (this->m_nFANCY_BLENDING
                + 2
                * (this->m_nSEAMLESS
                 + 2
                 * (this->m_nBUMPMASK
                  + this->m_nDETAIL_BLEND_MODE
                  + 13 * (this->m_nSHADER_SRGB_READ + this->m_nLIGHTING_PREVIEW + 4 * this->m_nDOPIXELFOG))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10017310
// Name: public: lightmappedgeneric_vs20_Static_Index::lightmappedgeneric_vs20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
lightmappedgeneric_vs20_Static_Index *__thiscall lightmappedgeneric_vs20_Static_Index::lightmappedgeneric_vs20_Static_Index(
        lightmappedgeneric_vs20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  BOOL v4; // edi
  BOOL v5; // ecx

  v4 = false;
  this->m_nENVMAP_MASK = 0;
  this->m_nTANGENTSPACE = 0;
  this->m_nBUMPMAP = 0;
  this->m_nDETAILTEXTURE = 0;
  this->m_nVERTEXCOLOR = 0;
  this->m_nVERTEXALPHATEXBLENDFACTOR = 0;
  this->m_nSEAMLESS = 0;
  this->m_nBUMPMASK = 0;
  this->m_nFANCY_BLENDING = 0;
  this->m_nSELFILLUM = 0;
  this->m_nLIGHTING_PREVIEW = 0;
  this->m_nPAINT = 0;
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    v4 = (*params)->m_intVal >= 0;
  this->m_nDOPIXELFOG = v4;
  v5 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  this->m_nHARDWAREFOGBLEND = v5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017390
// Name: public: int lightmappedgeneric_ps20b_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall lightmappedgeneric_ps20b_Static_Index::GetIndex(lightmappedgeneric_ps20b_Static_Index *this)
{
  return 32
       * (this->m_nBASETEXTURE2
        + 2
        * (this->m_nBUMPMAP
         + 3
         * (this->m_nBUMPMAP2
          + 2
          * (this->m_nCUBEMAP
           + 3
           * (this->m_nENVMAPMASK
            + 2
            * (this->m_nBASEALPHAENVMAPMASK
             + 2
             * (this->m_nSELFILLUM
              + 2
              * (this->m_nNORMALMAPALPHAENVMAPMASK
               + 2
               * (this->m_nFANCY_BLENDING
                + 2
                * (this->m_nSEAMLESS
                 + 2
                 * (this->m_nBUMPMASK
                  + this->m_nDETAIL_BLEND_MODE
                  + 13 * (this->m_nSHADER_SRGB_READ + this->m_nLIGHTING_PREVIEW + 4 * this->m_nDOPIXELFOG))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x100173F0
// Name: public: lightmappedgeneric_ps20b_Dynamic_Index::lightmappedgeneric_ps20b_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
lightmappedgeneric_ps20b_Dynamic_Index *__thiscall lightmappedgeneric_ps20b_Dynamic_Index::lightmappedgeneric_ps20b_Dynamic_Index(
        lightmappedgeneric_ps20b_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nFASTPATHENVMAPCONTRAST = 0;
  this->m_nFASTPATH = 0;
  this->m_nWRITEWATERFOGTODESTALPHA = 0;
  this->m_nWRITE_DEPTH_TO_DESTALPHA = 0;
  this->m_nFLASHLIGHTSHADOWS = 0;
  this->m_nPAINTREFRACT = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017430
// Name: void InitLightmappedGeneric_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct LightmappedGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitLightmappedGeneric_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        LightmappedGeneric_DX9_Vars_t *info)
{
  bool v3; // cl
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  int v8; // eax
  IMaterialVar *v9; // ecx
  IMaterialVar *v10; // ecx
  IMaterialVar *v11; // ecx
  int m_nDetailTextureCombineMode; // eax
  int m_intVal; // eax
  bool v14; // al
  int v15; // eax
  IMaterialVar *v16; // ecx
  HDRType_t v17; // eax
  IMaterialVar *v18; // ecx
  IMaterialVar *v19; // ecx
  IMaterialVar *v20; // ecx
  IMaterialVar *v21; // ecx
  IMaterialVar *v22; // ecx
  IMaterialVar *v23; // ecx
  IMaterialVar *v24; // ecx

  v3 = (g_pConfig->m_Flags & 0x80) == 0 && ((*params)->m_intVal & 0x400000) != 0;
  if ( (g_pConfig->m_Flags & 0x100) == 0 || v3 )
  {
    v4 = params[info->m_nBumpmap];
    if ( v4->IsDefined(this: v4) )
      CBaseShader::LoadBumpMap(this: pShader, nTextureVar: info->m_nBumpmap, nAdditionalCreationFlags: 0);
  }
  if ( (g_pConfig->m_Flags & 0x100) == 0 )
  {
    v5 = params[info->m_nBumpmap2];
    if ( v5->IsDefined(this: v5) )
      CBaseShader::LoadBumpMap(this: pShader, nTextureVar: info->m_nBumpmap2, nAdditionalCreationFlags: 0);
  }
  if ( (g_pConfig->m_Flags & 0x100) == 0 )
  {
    v6 = params[info->m_nBumpMask];
    if ( v6->IsDefined(this: v6) )
      CBaseShader::LoadBumpMap(this: pShader, nTextureVar: info->m_nBumpMask, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nPaintSplatNormal != -1 )
  {
    v7 = params[info->m_nPaintSplatNormal];
    if ( v7->IsDefined(this: v7) )
      CBaseShader::LoadBumpMap(this: pShader, nTextureVar: info->m_nPaintSplatNormal, nAdditionalCreationFlags: 0);
  }
  if ( params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
  {
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0x80000);
    v8 = params[info->m_nBaseTexture]->GetTextureValue(this: params[info->m_nBaseTexture]);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 24))(a1: v8) == 0 )
    {
      ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFFFFFBF);
      ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
    }
  }
  v9 = params[info->m_nBaseTexture2];
  if ( v9->IsDefined(this: v9) )
  {
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture2, nAdditionalCreationFlags: 0x80000);
    if ( info->m_nBlendModulateTexture != -1 )
    {
      v10 = params[info->m_nBlendModulateTexture];
      if ( v10->IsDefined(this: v10) )
        CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBlendModulateTexture, nAdditionalCreationFlags: 0);
    }
  }
  v11 = params[info->m_nDetail];
  if ( v11->IsDefined(this: v11) )
  {
    m_nDetailTextureCombineMode = info->m_nDetailTextureCombineMode;
    v14 = false;
    if ( m_nDetailTextureCombineMode != -1 )
    {
      m_intVal = params[m_nDetailTextureCombineMode]->m_intVal;
      if ( m_intVal == 2 || m_intVal == 3 || m_intVal == 4 )
        v14 = true;
    }
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nDetail, nAdditionalCreationFlags: v14 ? 0x80000 : 0);
  }
  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFlashlightTexture, nAdditionalCreationFlags: 0x80000);
  v15 = (*params)->m_intVal;
  if ( (v15 & 0x40) != 0 || (v15 & 0x100000) != 0 )
    (*params)->SetIntValue(this: *params, a2: v15 & 0xFFFFFEFF);
  if ( (g_pConfig->m_Flags & 0x80) != 0 )
  {
    v19 = params[info->m_nEnvmap];
    v19->SetUndefined(this: v19);
    goto LABEL_41;
  }
  v16 = params[info->m_nEnvmap];
  if ( !v16->IsDefined(this: v16) )
  {
LABEL_41:
    v20 = params[info->m_nEnvmapMask];
    v20->SetUndefined(this: v20);
    goto LABEL_42;
  }
  v17 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
  CBaseShader::LoadCubeMap(
    this: pShader,
    nTextureVar: info->m_nEnvmap,
    nAdditionalCreationFlags: v17 != HDR_TYPE_NONE ? 0 : 0x80000);
  v18 = params[info->m_nEnvmapMask];
  if ( v18->IsDefined(this: v18) )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nEnvmapMask, nAdditionalCreationFlags: 0);
LABEL_42:
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  if ( info->m_nPaintSplatNormal >= 0 )
  {
    v21 = params[info->m_nPaintSplatNormal];
    if ( v21->IsDefined(this: v21) )
      CBaseShader::LoadBumpMap(this: pShader, nTextureVar: info->m_nPaintSplatNormal, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nPaintSplatBubble >= 0 )
  {
    v22 = params[info->m_nPaintSplatBubble];
    if ( v22->IsDefined(this: v22) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nPaintSplatBubble, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nPaintSplatBubbleLayout >= 0 )
  {
    v23 = params[info->m_nPaintSplatBubbleLayout];
    if ( v23->IsDefined(this: v23) )
      CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nPaintSplatBubbleLayout, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nPaintEnvmap >= 0 )
  {
    v24 = params[info->m_nPaintEnvmap];
    if ( v24->IsDefined(this: v24) )
      CBaseShader::LoadCubeMap(this: pShader, nTextureVar: info->m_nPaintEnvmap, nAdditionalCreationFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100177A0
// Name: void InitParamsLightmappedGeneric_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct LightmappedGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitParamsLightmappedGeneric_DX9(
        int a1@<ebx>,
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        LightmappedGeneric_DX9_Vars_t *info)
{
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  const char *v7; // eax
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
  int m_nDetailTextureBlendFactor; // ebx
  int m_nDetailTextureCombineMode; // ebx
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
  int m_nAlphaTestReference; // ebx
  IMaterialVar *v33; // ecx
  IMaterialVar *v34; // ecx
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // ecx
  IMaterialVar *v37; // ecx
  IMaterialVar *v38; // ecx
  IMaterialVar *v39; // ecx
  int m_nShaderSrgbRead360; // ebx
  int m_nEnvMapLightScale; // ebx
  IMaterialVar *v42; // ecx
  IMaterialVar *v43; // ecx
  IMaterialVar *v44; // ecx
  IMaterialVar *v45; // ecx
  IMaterialVar *v46; // ecx
  IMaterialVar *v47; // ecx
  IMaterialVar *v48; // ecx
  IMaterialVar *v49; // ecx
  IMaterialVar *v50; // ecx
  IMaterialVar *v51; // ecx
  IMaterialVar *v52; // ecx
  IMaterialVar *v53; // ecx

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  if ( params[1]->m_intVal >= 0
    && mat_force_vertexfog.m_pParent != nullptr
    && mat_force_vertexfog.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x80000000);
  }
  ((void (__thiscall *)(IMaterialVar *, const char *, int))params[9]->SetStringValue)(
    a1: params[9],
    a2: "effects/flashlight001",
    a3: a1);
  if ( CBaseShader::IsUsingGraphics(this: pShader) )
  {
    v5 = params[info->m_nEnvmap];
    if ( v5->IsDefined(this: v5) && !CBaseShader::CanUseEditorMaterials(this: pShader) )
    {
      v6 = params[info->m_nEnvmap];
      v7 = v6->GetStringValue(this: v6);
      if ( _V_stricmp(s1: v7, s2: "env_cubemap") == 0 )
      {
        _Warning(a1: "env_cubemap used on world geometry without rebuilding map. . ignoring: %s\n", pMaterialName);
        v8 = params[info->m_nEnvmap];
        v8->SetUndefined(this: v8);
      }
    }
  }
  if ( mat_disable_fancy_blending.m_pParent != nullptr
    && mat_disable_fancy_blending.m_pParent->m_Value.m_nValue != 0
    && info->m_nBlendModulateTexture != -1 )
  {
    v9 = params[info->m_nBlendModulateTexture];
    v9->SetUndefined(this: v9);
  }
  v10 = params[info->m_nEnvmapTint];
  if ( !v10->IsDefined(this: v10) )
  {
    v11 = params[info->m_nEnvmapTint];
    ((void (__thiscall *)(IMaterialVar *, int, int, int))v11->SetVecValue_2)(
      a1: v11,
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216);
  }
  v12 = params[info->m_nNoDiffuseBumpLighting];
  if ( !v12->IsDefined(this: v12) )
  {
    v13 = params[info->m_nNoDiffuseBumpLighting];
    v13->SetIntValue(this: v13, a2: 0);
  }
  v14 = params[info->m_nSelfIllumTint];
  if ( !v14->IsDefined(this: v14) )
  {
    v15 = params[info->m_nSelfIllumTint];
    ((void (__thiscall *)(IMaterialVar *, int, int, int))v15->SetVecValue_2)(
      a1: v15,
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216);
  }
  v16 = params[info->m_nDetailScale];
  if ( !v16->IsDefined(this: v16) )
    ((void (__stdcall *)(int))params[info->m_nDetailScale]->SetFloatValue)(a1: 1082130432);
  v17 = params[info->m_nDetailTint];
  if ( !v17->IsDefined(this: v17) )
  {
    v18 = params[info->m_nDetailTint];
    ((void (__thiscall *)(IMaterialVar *, int, int, int, int))v18->SetVecValue)(
      a1: v18,
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216,
      a5: 1065353216);
  }
  m_nDetailTextureBlendFactor = info->m_nDetailTextureBlendFactor;
  if ( m_nDetailTextureBlendFactor != -1
    && !params[m_nDetailTextureBlendFactor]->IsDefined(this: params[m_nDetailTextureBlendFactor]) )
  {
    ((void (__stdcall *)(int))params[m_nDetailTextureBlendFactor]->SetFloatValue)(a1: 1065353216);
  }
  m_nDetailTextureCombineMode = info->m_nDetailTextureCombineMode;
  if ( m_nDetailTextureCombineMode != -1
    && !params[m_nDetailTextureCombineMode]->IsDefined(this: params[m_nDetailTextureCombineMode]) )
  {
    params[m_nDetailTextureCombineMode]->SetIntValue(this: params[m_nDetailTextureCombineMode], a2: 0);
  }
  v21 = params[info->m_nFresnelReflection];
  if ( !v21->IsDefined(this: v21) )
    ((void (__stdcall *)(int))params[info->m_nFresnelReflection]->SetFloatValue)(a1: 1065353216);
  v22 = params[info->m_nEnvmapMaskFrame];
  if ( !v22->IsDefined(this: v22) )
  {
    v23 = params[info->m_nEnvmapMaskFrame];
    v23->SetIntValue(this: v23, a2: 0);
  }
  v24 = params[info->m_nEnvmapFrame];
  if ( !v24->IsDefined(this: v24) )
  {
    v25 = params[info->m_nEnvmapFrame];
    v25->SetIntValue(this: v25, a2: 0);
  }
  v26 = params[info->m_nBumpFrame];
  if ( !v26->IsDefined(this: v26) )
  {
    v27 = params[info->m_nBumpFrame];
    v27->SetIntValue(this: v27, a2: 0);
  }
  v28 = params[info->m_nDetailFrame];
  if ( !v28->IsDefined(this: v28) )
  {
    v29 = params[info->m_nDetailFrame];
    v29->SetIntValue(this: v29, a2: 0);
  }
  v30 = params[info->m_nEnvmapContrast];
  if ( !v30->IsDefined(this: v30) )
    ((void (__stdcall *)(_DWORD))params[info->m_nEnvmapContrast]->SetFloatValue)(a1: 0);
  v31 = params[info->m_nEnvmapSaturation];
  if ( !v31->IsDefined(this: v31) )
    ((void (__stdcall *)(int))params[info->m_nEnvmapSaturation]->SetFloatValue)(a1: 1065353216);
  m_nAlphaTestReference = info->m_nAlphaTestReference;
  if ( m_nAlphaTestReference != -1 && !params[m_nAlphaTestReference]->IsDefined(this: params[m_nAlphaTestReference]) )
    ((void (__stdcall *)(_DWORD))params[m_nAlphaTestReference]->SetFloatValue)(a1: 0);
  if ( !params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
  {
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFFFFFBF);
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
  }
  v33 = params[info->m_nBumpmap];
  if ( v33->IsDefined(this: v33) )
  {
    v34 = params[info->m_nEnvmapMask];
    v34->SetUndefined(this: v34);
  }
  if ( ((*params)->m_intVal & 0x10000) != 0 )
    (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal | 2);
  ((void (__cdecl *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 4);
  if ( (g_pConfig->m_Flags & 0x100) == 0 )
  {
    v35 = params[info->m_nBumpmap];
    if ( v35->IsDefined(this: v35) && params[info->m_nNoDiffuseBumpLighting]->m_intVal == 0 )
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 8);
  }
  if ( (g_pConfig->m_Flags & 0x80) != 0 )
  {
    v36 = params[info->m_nEnvmap];
    if ( v36->IsDefined(this: v36) && params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
    {
      v37 = params[info->m_nEnvmap];
      v37->SetUndefined(this: v37);
    }
  }
  if ( info->m_nSelfShadowedBumpFlag != -1 )
  {
    v38 = params[info->m_nSelfShadowedBumpFlag];
    if ( !v38->IsDefined(this: v38) )
    {
      v39 = params[info->m_nSelfShadowedBumpFlag];
      v39->SetIntValue(this: v39, a2: 0);
    }
  }
  m_nShaderSrgbRead360 = info->m_nShaderSrgbRead360;
  if ( m_nShaderSrgbRead360 != -1 && !params[m_nShaderSrgbRead360]->IsDefined(this: params[m_nShaderSrgbRead360]) )
    params[m_nShaderSrgbRead360]->SetIntValue(this: params[m_nShaderSrgbRead360], a2: 0);
  m_nEnvMapLightScale = info->m_nEnvMapLightScale;
  if ( m_nEnvMapLightScale != -1 && !params[m_nEnvMapLightScale]->IsDefined(this: params[m_nEnvMapLightScale]) )
    ((void (__stdcall *)(_DWORD))params[m_nEnvMapLightScale]->SetFloatValue)(a1: 0);
  if ( g_pConfig->m_bPaintInGame )
  {
    if ( info->m_nPaintSplatNormal != -1 )
    {
      v42 = params[info->m_nPaintSplatNormal];
      if ( !v42->IsDefined(this: v42) )
      {
        v43 = params[info->m_nPaintSplatNormal];
        v43->SetStringValue(this: v43, a2: "paint/splatnormal_default");
      }
    }
    if ( info->m_nPaintSplatBubbleLayout != -1 )
    {
      v44 = params[info->m_nPaintSplatBubbleLayout];
      if ( !v44->IsDefined(this: v44) )
      {
        v45 = params[info->m_nPaintSplatBubbleLayout];
        v45->SetStringValue(this: v45, a2: "paint/bubblelayout");
      }
    }
    if ( info->m_nPaintSplatBubble != -1 )
    {
      v46 = params[info->m_nPaintSplatBubble];
      if ( !v46->IsDefined(this: v46) )
      {
        v47 = params[info->m_nPaintSplatBubble];
        v47->SetStringValue(this: v47, a2: "paint/bubble");
      }
    }
    if ( info->m_nPaintEnvmap != -1 )
    {
      v48 = params[info->m_nPaintEnvmap];
      if ( !v48->IsDefined(this: v48) )
      {
        v49 = params[info->m_nPaintEnvmap];
        v49->SetStringValue(this: v49, a2: "paint/paint_envmap_hdr");
      }
    }
  }
  else
  {
    if ( info->m_nPaintSplatNormal != -1 )
    {
      v50 = params[info->m_nPaintSplatNormal];
      v50->SetUndefined(this: v50);
    }
    if ( info->m_nPaintSplatBubbleLayout != -1 )
    {
      v51 = params[info->m_nPaintSplatBubbleLayout];
      v51->SetUndefined(this: v51);
    }
    if ( info->m_nPaintSplatBubble != -1 )
    {
      v52 = params[info->m_nPaintSplatBubble];
      v52->SetUndefined(this: v52);
    }
    if ( info->m_nPaintEnvmap != -1 )
    {
      v53 = params[info->m_nPaintEnvmap];
      v53->SetUndefined(this: v53);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100180E0
// Name: void DrawLightmappedGeneric_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct LightmappedGeneric_DX9_Vars_t __near &,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawLightmappedGeneric_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        ITexture *pShaderAPI,
        IShaderShadow *pShaderShadow,
        LightmappedGeneric_DX9_Vars_t *info,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar **v6; // esi
  bool v7; // zf
  IMaterialSystemHardwareConfig_vtbl *v8; // eax
  int m_nBaseTexture; // eax
  char v10; // dl
  int v11; // eax
  char v12; // cl
  CBasePerMaterialContextData *v13; // eax
  int m_nSelfShadowedBumpFlag; // eax
  char v15; // dl
  char v16; // al
  char v17; // cl
  int m_intVal; // ecx
  int m_nBlendModulateTexture; // eax
  char v20; // dl
  int m_nBumpmap; // edx
  float x; // xmm0_4
  int m_nFlashlightTextureFrame; // eax
  int m_nBumpTransform; // ecx
  int m_nFlashlightTexture; // edx
  int m_nBaseTexture2Frame; // eax
  int m_nBaseTexture2; // edx
  int m_nBumpTransform2; // eax
  int m_nBumpmap2; // ecx
  int m_nBumpFrame2; // edx
  int m_nDetail; // eax
  int m_nAlphaTestReference; // ecx
  int m_nDetailScale; // eax
  int m_nDetailTextureCombineMode; // ecx
  int m_nDetailTextureBlendFactor; // edx
  int m_nDetailTint; // eax
  int m_nSeamlessMappingScale; // edi
  CBasePerMaterialContextData *v38; // eax
  char v39; // dl
  int v40; // eax
  float v41; // xmm0_4
  IMaterialVar *v42; // eax
  char v43; // cl
  int m_nEnvMapLightScale; // eax
  IMaterialVar *v45; // ecx
  int v46; // eax
  int v47; // eax
  float v48; // xmm0_4
  IMaterialVar *v49; // ecx
  unsigned __int8 *v50; // eax
  _DWORD *v51; // eax
  float v52; // xmm0_4
  unsigned __int8 *v53; // eax
  unsigned __int8 *v54; // ecx
  int v55; // eax
  float v56; // xmm0_4
  int v57; // eax
  IMaterialVar *v58; // ecx
  int v59; // eax
  BOOL v60; // eax
  int v61; // edx
  char v62; // dl
  BOOL v63; // eax
  bool v64; // al
  BOOL v65; // eax
  int Index; // eax
  IShaderShadow *v67; // esi
  CBasePerMaterialContextData *v68; // eax
  unsigned int *p_m_nVarChangeID; // esi
  IMaterialVar *v70; // ecx
  IMaterialVar *v71; // ecx
  IMaterialVar *v72; // ecx
  IMaterialVar *v73; // ecx
  bool v74; // al
  CBasePerMaterialContextData *v75; // eax
  int v76; // eax
  int v77; // eax
  bool v78; // al
  IMaterialVar *v79; // eax
  unsigned int v80; // ecx
  double y; // st7
  _DWORD *v82; // eax
  int v83; // eax
  int x_low; // xmm2_4
  int y_low; // xmm3_4
  int z_low; // xmm4_4
  IMaterialVar *v87; // eax
  float *v88; // eax
  float v89; // xmm2_4
  int *v90; // eax
  int v91; // xmm2_4
  IMaterialVar *v92; // edx
  int m_nEnvmapSaturation; // eax
  float v94; // xmm2_4
  IMaterialVar *v95; // edx
  int m_nFresnelReflection; // eax
  float v97; // xmm2_4
  IMaterialVar *v98; // edx
  IMaterialVar *v99; // ecx
  float v100; // xmm2_4
  int v101; // eax
  bool v102; // dl
  bool v103; // cl
  bool v104; // al
  IMaterialVar *v105; // eax
  int v106; // ecx
  IMaterialVar *v107; // eax
  float *v108; // ecx
  double v109; // st7
  float v110; // xmm2_4
  unsigned int v111; // eax
  IMaterialVar *v112; // eax
  unsigned int v113; // ecx
  double v114; // st7
  int v115; // eax
  float v116; // xmm0_4
  float *v117; // eax
  int ShaderAPITextureBindHandle; // eax
  _DWORD *v119; // eax
  int v120; // eax
  int v121; // eax
  int v122; // eax
  int v123; // eax
  int v124; // eax
  int v125; // eax
  int v126; // eax
  int v127; // eax
  int m_nPaintSplatNormal; // eax
  int v129; // eax
  int v130; // eax
  int m_nEnvmap; // ebx
  unsigned int v132; // esi
  int v133; // eax
  int v134; // eax
  int m_nDETAIL_BLEND_MODE; // xmm1_4
  int m_nSHADER_SRGB_READ; // xmm2_4
  int m_nLIGHTING_PREVIEW; // xmm3_4
  const VMatrix *v138; // eax
  void (__thiscall *GetNumAnimationFrames)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v140; // ebx
  int v141; // ecx
  bool v142; // bl
  __int64 v143; // xmm0_8
  int (__thiscall *GetDXSupportLevel)(IMaterialSystemHardwareConfig *); // edx
  bool v145; // al
  BOOL v146; // eax
  BOOL v147; // edi
  int v148; // ecx
  int v149; // edx
  bool v150; // al
  BOOL v151; // eax
  int m_nDOPIXELFOG; // edx
  void (__thiscall *IsVolumeTexture)(IShaderDynamicAPI *, unsigned __int8 *); // edx
  int scale; // [esp+44h] [ebp-18ACh]
  int scalea; // [esp+44h] [ebp-18ACh]
  unsigned __int8 src[4]; // [esp+54h] [ebp-189Ch] BYREF
  int v157; // [esp+58h] [ebp-1898h]
  _BYTE v158[4992]; // [esp+5Ch] [ebp-1894h] BYREF
  unsigned __int8 *v159; // [esp+13DCh] [ebp-514h]
  _DWORD v160[4]; // [esp+13E0h] [ebp-510h] BYREF
  char v161; // [esp+13F0h] [ebp-500h] BYREF
  char *v162; // [esp+17C8h] [ebp-128h]
  VMatrix v163; // [esp+17CCh] [ebp-124h] BYREF
  CBaseVSShader::DrawFlashlight_dx90_Vars_t dst; // [esp+180Ch] [ebp-E4h] BYREF
  BOOL v165; // [esp+1860h] [ebp-90h]
  BOOL v166; // [esp+1864h] [ebp-8Ch]
  BOOL v167; // [esp+1868h] [ebp-88h]
  BOOL v168; // [esp+186Ch] [ebp-84h]
  lightmappedgeneric_ps20b_Static_Index v169; // [esp+1870h] [ebp-80h] BYREF
  int v170; // [esp+18ACh] [ebp-44h]
  bool isBaseTexture[4]; // [esp+18B0h] [ebp-40h]
  __int64 vec; // [esp+18B4h] [ebp-3Ch] BYREF
  __int64 vec_8; // [esp+18BCh] [ebp-34h]
  int v174; // [esp+18C4h] [ebp-2Ch]
  int v175; // [esp+18C8h] [ebp-28h]
  float v176; // [esp+18CCh] [ebp-24h]
  int v177; // [esp+18D0h] [ebp-20h]
  IShaderShadow_vtbl *v178; // [esp+18D4h] [ebp-1Ch]
  int textureVar; // [esp+18D8h] [ebp-18h]
  bool v180; // [esp+18DDh] [ebp-13h]
  bool v181; // [esp+18DEh] [ebp-12h]
  char v182; // [esp+18DFh] [ebp-11h]
  CBasePerMaterialContextData *v183; // [esp+18E0h] [ebp-10h]
  unsigned __int8 v184; // [esp+18E4h] [ebp-Ch]
  unsigned __int8 v185; // [esp+18E5h] [ebp-Bh]
  bool v186; // [esp+18E6h] [ebp-Ah]
  unsigned __int8 v187; // [esp+18E7h] [ebp-9h]
  bool v188; // [esp+18E8h] [ebp-8h]
  unsigned __int8 v189; // [esp+18E9h] [ebp-7h]
  bool v190; // [esp+18EAh] [ebp-6h]
  bool v191; // [esp+18EBh] [ebp-5h]
  bool v192; // [esp+18ECh] [ebp-4h]
  bool v193; // [esp+18EDh] [ebp-3h]
  bool v194; // [esp+18EEh] [ebp-2h]
  unsigned __int8 v195; // [esp+18EFh] [ebp-1h]
  float pShaderShadowc; // [esp+1904h] [ebp+14h]
  bool pShaderShadowa; // [esp+1904h] [ebp+14h]
  IShaderShadow *pShaderShadowb; // [esp+1904h] [ebp+14h]
  bool pShaderShadow_3; // [esp+1907h] [ebp+17h]
  bool pShaderShadow_3a; // [esp+1907h] [ebp+17h]
  bool pShaderShadow_3b; // [esp+1907h] [ebp+17h]
  bool pShaderShadow_3c; // [esp+1907h] [ebp+17h]
  float v203; // [esp+190Ch] [ebp+1Ch]
  unsigned __int8 v204; // [esp+190Fh] [ebp+1Fh]
  bool v205; // [esp+190Fh] [ebp+1Fh]

  v6 = params;
  v193 = CBaseShader::UsingFlashlight(this: pShader, params);
  if ( pShaderShadow != nullptr || (v7 = !g_pConfig->m_bPaintInMap, v182 = 0, !v7) )
    v182 = 1;
  v8 = g_pHardwareConfig->__vftable;
  v183 = *pContextDataPtr;
  v181 = v8->GetHDRType(this: g_pHardwareConfig) != HDR_TYPE_NONE;
  if ( pShaderShadow == nullptr && v183 != nullptr && !v183->m_bMaterialVarsChanged && !v193 )
    goto LABEL_335;
  m_nBaseTexture = info->m_nBaseTexture;
  v10 = *((_BYTE *)params[info->m_nBaseTexture] + 28) & 0xF;
  isBaseTexture[0] = v10 == 3;
  if ( v10 != 3 )
    m_nBaseTexture = info->m_nEnvmapMask;
  textureVar = m_nBaseTexture;
  v11 = CBaseVSShader::EvaluateBlendRequirements(
          this: pShader,
          textureVar: m_nBaseTexture,
          isBaseTexture: isBaseTexture[0],
          detailTextureVar: -1);
  v12 = BYTE1((*params)->m_intVal) & 1;
  BYTE4(vec_8) = v12;
  if ( v11 == 3 || v11 == 1 || v193 )
  {
    v191 = false;
    goto LABEL_14;
  }
  v191 = true;
  LOBYTE(v174) = 1;
  if ( v12 != 0 )
LABEL_14:
    LOBYTE(v174) = 0;
  if ( v183 == nullptr || (v190 = false, pShaderShadow != nullptr) )
    v190 = true;
  if ( v183 == nullptr )
  {
    v13 = (CBasePerMaterialContextData *)operator new(nSize: 0x39Cu);
    if ( v13 != nullptr )
    {
      v13->m_bMaterialVarsChanged = true;
      v13->m_nVarChangeID = -1;
      v13->__vftable = (CBasePerMaterialContextData_vtbl *)&CLightmappedGeneric_DX9_Context::`vftable';
      v13[76].m_nVarChangeID = (unsigned int)&v13[1].m_nVarChangeID;
      v13[1].__vftable = nullptr;
      v183 = v13;
    }
    else
    {
      v183 = nullptr;
    }
    *pContextDataPtr = v183;
  }
  if ( (*((_BYTE *)params[info->m_nBumpmap] + 28) & 0xF) != 3 || (g_pConfig->m_Flags & 0x100) != 0 )
  {
    v15 = 0;
    v192 = false;
LABEL_28:
    v186 = false;
    goto LABEL_29;
  }
  m_nSelfShadowedBumpFlag = info->m_nSelfShadowedBumpFlag;
  v15 = 1;
  v192 = true;
  if ( m_nSelfShadowedBumpFlag == -1 )
    goto LABEL_28;
  v7 = params[m_nSelfShadowedBumpFlag]->m_intVal == 0;
  v186 = true;
  if ( v7 )
    goto LABEL_28;
LABEL_29:
  if ( !isBaseTexture[0] || (v16 = *((_BYTE *)params[info->m_nBaseTexture2] + 28) & 0xF, v194 = true, v16 != 3) )
    v194 = false;
  if ( v15 == 0 || (v204 = 1, (*((_BYTE *)params[info->m_nBumpmap2] + 28) & 0xF) != 3) )
    v204 = 0;
  if ( (*((_BYTE *)params[info->m_nDetail] + 28) & 0xF) != 3
    || (v17 = ~(unsigned __int8)(g_pConfig->m_Flags >> 18), v195 = 1, (v17 & 1) == 0) )
  {
    v195 = 0;
  }
  m_intVal = (*params)->m_intVal;
  v188 = (m_intVal & 0x40) != 0;
  if ( v15 == 0
    || v204 == 0
    || (*((_BYTE *)params[info->m_nBumpMask] + 28) & 0xF) != 3
    || (m_intVal & 0x40) != 0
    || v195 != 0
    || (v185 = 1, v194) )
  {
    v185 = 0;
  }
  m_nBlendModulateTexture = info->m_nBlendModulateTexture;
  if ( m_nBlendModulateTexture == -1
    || (v20 = *((_BYTE *)params[m_nBlendModulateTexture] + 28) & 0xF, v189 = 1, v20 != 3) )
  {
    v189 = 0;
  }
  if ( (g_pConfig->m_Flags & 0x80) != 0 || (v184 = 1, (m_intVal & 0x400000) == 0) )
    v184 = 0;
  if ( v193 )
  {
    memset((unsigned __int8 *)&dst, value: 0xFFu, count: sizeof(dst));
    m_nBumpmap = info->m_nBumpmap;
    x = 0.0;
    dst.m_nBumpmapFrame = info->m_nBumpFrame;
    m_nFlashlightTextureFrame = info->m_nFlashlightTextureFrame;
    dst.m_bBump = v192;
    m_nBumpTransform = info->m_nBumpTransform;
    dst.m_nBumpmapVar = m_nBumpmap;
    m_nFlashlightTexture = info->m_nFlashlightTexture;
    dst.m_nFlashlightTextureFrameVar = m_nFlashlightTextureFrame;
    m_nBaseTexture2Frame = info->m_nBaseTexture2Frame;
    dst.m_nBumpTransform = m_nBumpTransform;
    dst.m_nFlashlightTextureVar = m_nFlashlightTexture;
    m_nBaseTexture2 = info->m_nBaseTexture2;
    dst.m_nBaseTexture2FrameVar = m_nBaseTexture2Frame;
    m_nBumpTransform2 = info->m_nBumpTransform2;
    dst.m_bWorldVertexTransition = v194;
    m_nBumpmap2 = info->m_nBumpmap2;
    dst.m_nBaseTexture2Var = m_nBaseTexture2;
    m_nBumpFrame2 = info->m_nBumpFrame2;
    dst.m_nBump2Transform = m_nBumpTransform2;
    m_nDetail = info->m_nDetail;
    dst.m_nBumpmap2Var = m_nBumpmap2;
    m_nAlphaTestReference = info->m_nAlphaTestReference;
    dst.m_nBumpmap2Frame = m_nBumpFrame2;
    dst.m_nDetailVar = m_nDetail;
    m_nDetailScale = info->m_nDetailScale;
    dst.m_nAlphaTestReference = m_nAlphaTestReference;
    m_nDetailTextureCombineMode = info->m_nDetailTextureCombineMode;
    dst.m_bSSBump = v186;
    m_nDetailTextureBlendFactor = info->m_nDetailTextureBlendFactor;
    dst.m_nDetailScale = m_nDetailScale;
    m_nDetailTint = info->m_nDetailTint;
    m_nSeamlessMappingScale = info->m_nSeamlessMappingScale;
    dst.m_bTeeth = false;
    dst.m_fSeamlessScale = 0.0;
    dst.m_bLightmappedGeneric = true;
    dst.m_nDetailTextureCombineMode = m_nDetailTextureCombineMode;
    dst.m_nDetailTextureBlendFactor = m_nDetailTextureBlendFactor;
    dst.m_nDetailTint = m_nDetailTint;
    if ( m_nSeamlessMappingScale != -1 )
      x = params[m_nSeamlessMappingScale]->m_VecVal.x;
    dst.m_fSeamlessScale = x;
    CBaseVSShader::DrawFlashlight_dx90(
      this: pShader,
      params,
      pShaderAPI,
      pShaderShadow: *(float *)&pShaderShadow,
      vars: &dst);
    return;
  }
  v38 = v183;
  v39 = v174;
  *(&v183[76].m_bMaterialVarsChanged + 3) = v191;
  *(&v38[76].m_bMaterialVarsChanged + 2) = v39;
  v40 = info->m_nDetailTextureBlendFactor;
  v191 = (*((_BYTE *)params[info->m_nEnvmapMask] + 28) & 0xF) == 3;
  if ( v40 == -1 )
    v41 = 1.0;
  else
    v41 = params[v40]->m_VecVal.x;
  v176 = v41;
  if ( pShaderShadow != nullptr || v190 )
  {
    v42 = params[info->m_nEnvmap];
    v180 = ((*params)->m_intVal & 0x10) != 0;
    v43 = *((_BYTE *)v42 + 28) & 0xF;
    v193 = v43 == 3;
    if ( v43 == 3 )
    {
      m_nEnvMapLightScale = info->m_nEnvMapLightScale;
      if ( m_nEnvMapLightScale == -1
        || params[m_nEnvMapLightScale]->m_VecVal.x <= 0.0
        || g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 && v204 != 0 )
      {
        v170 = 1;
      }
      else
      {
        v170 = 2;
      }
    }
    else
    {
      v170 = 0;
    }
    if ( v195 != 0 )
    {
      v45 = params[info->m_nDetail];
      v46 = v45->GetTextureValue(this: v45);
      (*(void (__thiscall **)(int))(*(_DWORD *)v46 + 108))(a1: v46);
    }
    v47 = info->m_nSeamlessMappingScale;
    if ( v47 == -1 || (v48 = params[v47]->m_VecVal.x, v187 = 1, v48 == 0.0) )
      v187 = 0;
    if ( v190 )
    {
      if ( v183[1].__vftable != nullptr )
      {
        free(pMem: v183[1].__vftable);
        v183[1].__vftable = nullptr;
      }
      v49 = params[2];
      v50 = src;
      v159 = src;
      if ( ((v49->m_intVal & 0x100000) != 0) + 2 * ((v49->m_intVal & 0x200000) != 0) == 3 )
      {
        v50 = v158;
        *(_DWORD *)src = 16;
        v157 = 54;
        v159 = v158;
      }
      if ( !isBaseTexture[0] )
      {
        *(_DWORD *)v50 = 9;
        v159 += 4;
        *(_DWORD *)v159 = 0x80000000;
        v51 = v159 + 4;
        v159 += 4;
        if ( v193 )
          *v51 = 5;
        else
          *v51 = 4;
        v50 = v159 + 4;
        v159 += 4;
      }
      *(_DWORD *)v50 = 9;
      v159 += 4;
      *(_DWORD *)v159 = (v181 ? 0 : 0x80000000) | 1;
      v159 += 4;
      *(_DWORD *)v159 = 0;
      v159 += 4;
      if ( v182 != 0 )
      {
        *(_DWORD *)v159 = 9;
        v159 += 4;
        *(_DWORD *)v159 = -2147483639;
        v159 += 4;
        *(_DWORD *)v159 = 28;
        v159 += 4;
      }
      if ( v187 != 0 )
      {
        v52 = params[info->m_nSeamlessMappingScale]->m_VecVal.x;
        *(_DWORD *)v159 = 4;
        v159 += 4;
        *(_DWORD *)v159 = 48;
        v159 += 4;
        *(_DWORD *)v159 = 1;
        v159 += 4;
        *(float *)v159 = v52;
        v159 += 4;
        *(_DWORD *)v159 = 0;
        v159 += 4;
        *(_DWORD *)v159 = 0;
        v159 += 4;
        *(_DWORD *)v159 = 0;
        v159 += 4;
      }
      *(_DWORD *)v159 = 7;
      v159 += 4;
      *(_DWORD *)v159 = 10;
      v159 += 4;
      *(_DWORD *)v159 = 1065353216;
      v159 += 4;
      *(_DWORD *)v159 = 6;
      v159 += 4;
      *(_DWORD *)v159 = 11;
      v159 += 4;
      *(_DWORD *)v159 = 0;
      v159 += 4;
      v53 = (unsigned __int8 *)operator new(nSize: v159 - src);
      v54 = v159;
      v183[1].__vftable = (CBasePerMaterialContextData_vtbl *)v53;
      memcpy(dst: v53, src, count: v54 - src);
    }
    if ( pShaderShadow != nullptr )
    {
      pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: HIDWORD(vec_8));
      v55 = info->m_nAlphaTestReference;
      if ( v55 != -1 )
      {
        v56 = params[v55]->m_VecVal.x;
        if ( v56 > 0.0 )
          ((void (__stdcall *)(int, _DWORD))pShaderShadow->AlphaFunc)(a1: 6, a2: LODWORD(v56));
      }
      CBaseShader::SetDefaultBlendingShadowState(this: pShader, textureVar, isBaseTexture: isBaseTexture[0]);
      v177 = 1;
      if ( v193 )
        v177 = 51;
      v175 = 12;
      if ( v195 != 0 )
      {
        v57 = info->m_nDetailTextureCombineMode;
        if ( v57 == -1 )
          v175 = 0;
        else
          v175 = params[v57]->m_intVal;
        v58 = params[info->m_nDetail];
        v59 = v58->GetTextureValue(this: v58);
        if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v59 + 108))(a1: v59) & 0x8000000) != 0 )
          v175 = !v192 + 10;
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER12, a3: true);
        v60 = v175 == 2 || v175 == 3 || v175 == 4;
        pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER12, a3: v60);
      }
      if ( v180 || v194 || v204 != 0 )
        v177 |= 4u;
      v61 = 2;
      if ( v192 )
        v61 = 3;
      textureVar = ((params[2]->m_intVal & 0x100000) != 0) + 2 * ((params[2]->m_intVal & 0x200000) != 0);
      pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v177, a3: v61, a4: nullptr, a5: 0);
      v193 = ((*params)->m_intVal & 0x100000) != 0;
      if ( v186 )
        v177 = 2;
      else
        v177 = v192;
      lightmappedgeneric_vs20_Static_Index::lightmappedgeneric_vs20_Static_Index(
        this: (lightmappedgeneric_vs20_Static_Index *)&v169.m_nBUMPMAP,
        pShaderShadow,
        params);
      v165 = v191;
      v169.m_nBUMPMAP = v165;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "ENVMAP_MASK", v191, "hasEnvmapMask");
      v62 = *((_BYTE *)params[info->m_nEnvmap] + 28) & 0xF;
      v169.m_nBUMPMAP2 = v62 == 3;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TANGENTSPACE", v62 == 3, "params[info.m_nEnvmap]->IsTexture()");
      v169.m_nCUBEMAP = v192;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMAP", v192, "hasBump");
      v63 = ((*params)->m_intVal & 0x10) != 0;
      v169.m_nBASEALPHAENVMAPMASK = v63;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v63, "IS_FLAG_SET( MATERIAL_VAR_VERTEXCOLOR )");
      v64 = v194 || v204 != 0;
      v169.m_nSELFILLUM = v64;
      if ( g_shaderConfigDumpEnable )
      {
        v65 = v194 || v204 != 0;
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXALPHATEXBLENDFACTOR", v65, "hasBaseTexture2 || hasBump2");
      }
      v166 = v185 != 0;
      v169.m_nFANCY_BLENDING = v166;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMASK", v185, "hasBumpMask");
      v169.m_nDETAIL_BLEND_MODE = textureVar;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "LIGHTING_PREVIEW", textureVar, "nLightingPreviewMode");
      HIDWORD(vec_8) = v187 != 0;
      v169.m_nNORMALMAPALPHAENVMAPMASK = HIDWORD(vec_8);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS", v187, "bSeamlessMapping");
      v169.m_nENVMAPMASK = v195 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DETAILTEXTURE", v195, "hasDetailTexture");
      v168 = v189 != 0;
      v169.m_nSEAMLESS = v168;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FANCY_BLENDING", v189, "bHasBlendModulateTexture");
      v167 = v188;
      v169.m_nBUMPMASK = v167;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SELFILLUM", v188, "hasSelfIllum");
      v169.m_nSHADER_SRGB_READ = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "PAINT", 0, "0");
      v178 = pShaderShadow->__vftable;
      Index = lightmappedgeneric_vs20_Static_Index::GetIndex(this: (lightmappedgeneric_vs20_Static_Index *)&v169.m_nBUMPMAP);
      v67 = pShaderShadow;
      v178->SetVertexShader(this: pShaderShadow, a2: "lightmappedgeneric_vs20", a3: Index);
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        v169.m_nDOPIXELFOG = 0;
        v169.m_nBASETEXTURE2 = v194;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE2", v194, "hasBaseTexture2");
        v169.m_nBUMPMAP = v177;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", v177, "bumpmap_variant");
        v169.m_nBUMPMAP2 = v204 != 0;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP2", v204, "hasBump2");
        v169.m_nBUMPMASK = v166;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMASK", v185, "hasBumpMask");
        v169.m_nCUBEMAP = v170;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v170, "envmap_variant");
        v169.m_nENVMAPMASK = v165;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "ENVMAPMASK", v191, "hasEnvmapMask");
        v169.m_nBASEALPHAENVMAPMASK = v193;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BASEALPHAENVMAPMASK", v193, "hasBaseAlphaEnvmapMask");
        v169.m_nSELFILLUM = v167;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", v188, "hasSelfIllum");
        v169.m_nNORMALMAPALPHAENVMAPMASK = v184 != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "NORMALMAPALPHAENVMAPMASK",
            v184,
            "hasNormalMapAlphaEnvmapMask");
        v169.m_nFANCY_BLENDING = v168;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FANCY_BLENDING", v189, "bHasBlendModulateTexture");
        v169.m_nSEAMLESS = HIDWORD(vec_8);
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", v187, "bSeamlessMapping");
        v169.m_nDETAIL_BLEND_MODE = v175;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", v175, "nDetailBlendMode");
        v169.m_nSHADER_SRGB_READ = 0;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
        v169.m_nLIGHTING_PREVIEW = textureVar;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "LIGHTING_PREVIEW", textureVar, "nLightingPreviewMode");
        v178 = pShaderShadow->__vftable;
        v67 = pShaderShadow;
        scalea = lightmappedgeneric_ps20_Static_Index::GetIndex(this: (lightmappedgeneric_ps20_Static_Index *)&v169);
        v178->SetPixelShader(this: pShaderShadow, a2: "lightmappedgeneric_ps20", a3: scalea);
      }
      else
      {
        vertexlit_and_unlit_generic_bump_ps20b_Static_Index::vertexlit_and_unlit_generic_bump_ps20b_Static_Index(
          this: &v169,
          pShaderShadow,
          params);
        v169.m_nBASETEXTURE2 = v194;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE2", v194, "hasBaseTexture2");
        v169.m_nBUMPMAP = v177;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", v177, "bumpmap_variant");
        v169.m_nBUMPMAP2 = v204 != 0;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP2", v204, "hasBump2");
        v169.m_nBUMPMASK = v166;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMASK", v185, "hasBumpMask");
        v169.m_nCUBEMAP = v170;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v170, "envmap_variant");
        v169.m_nENVMAPMASK = v165;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "ENVMAPMASK", v191, "hasEnvmapMask");
        v169.m_nBASEALPHAENVMAPMASK = v193;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "BASEALPHAENVMAPMASK", v193, "hasBaseAlphaEnvmapMask");
        v169.m_nSELFILLUM = v167;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", v188, "hasSelfIllum");
        v169.m_nNORMALMAPALPHAENVMAPMASK = v184 != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "NORMALMAPALPHAENVMAPMASK",
            v184,
            "hasNormalMapAlphaEnvmapMask");
        v169.m_nFANCY_BLENDING = v168;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FANCY_BLENDING", v189, "bHasBlendModulateTexture");
        v169.m_nSEAMLESS = HIDWORD(vec_8);
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", v187, "bSeamlessMapping");
        v169.m_nDETAIL_BLEND_MODE = v175;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", v175, "nDetailBlendMode");
        v169.m_nSHADER_SRGB_READ = 0;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
        v169.m_nLIGHTING_PREVIEW = textureVar;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "LIGHTING_PREVIEW", textureVar, "nLightingPreviewMode");
        v178 = pShaderShadow->__vftable;
        scale = lightmappedgeneric_ps20b_Static_Index::GetIndex(this: &v169);
        v178->SetPixelShader(this: pShaderShadow, a2: "lightmappedgeneric_ps20b", a3: scale);
      }
      v67->EnableAlphaWrites(this: v67, a2: v174);
      v67->EnableSRGBWrite(this: v67, a2: true);
      CBaseShader::DefaultFog(this: pShader);
      pShaderShadowc = v67->GetLightMapScaleFactor(this: v67);
      CBaseShader::PI_BeginCommandBuffer(this: pShader);
      CBaseShader::PI_SetModulationPixelShaderDynamicState(this: pShader, nRegister: 21);
      CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearScale_ScaleInW(
        this: pShader,
        nRegister: 12,
        scale: pShaderShadowc);
      CBaseShader::PI_SetModulationVertexShaderDynamicState_LinearScale(this: pShader, flScale: pShaderShadowc);
      CBaseShader::PI_EndCommandBuffer(this: pShader);
      v6 = params;
    }
  }
  if ( pShaderAPI != nullptr )
  {
    v68 = v183;
    if ( v183->m_bMaterialVarsChanged )
    {
      p_m_nVarChangeID = &v183[1].m_nVarChangeID;
      v183[76].m_nVarChangeID = (unsigned int)&v183[1].m_nVarChangeID;
      v68->m_bMaterialVarsChanged = false;
      v70 = params[info->m_nBaseTextureTransform];
      v74 = true;
      if ( v70->MatrixIsIdentity(this: v70) )
      {
        v71 = params[info->m_nBumpTransform];
        if ( v71->MatrixIsIdentity(this: v71) )
        {
          v72 = params[info->m_nBumpTransform2];
          if ( v72->MatrixIsIdentity(this: v72) )
          {
            v73 = params[info->m_nEnvmapMaskTransform];
            if ( v73->MatrixIsIdentity(this: v73) )
              v74 = false;
          }
        }
      }
      v7 = !v74;
      v75 = v183;
      v183[76].m_bMaterialVarsChanged = v7;
      if ( (*((_BYTE *)params[info->m_nDetail] + 28) & 0xF) == 3 )
        v75[76].m_bMaterialVarsChanged = false;
      v76 = -1;
      if ( (v192 || v186) && v195 != 0 && !v188 && v189 == 0 )
        v76 = info->m_nBumpTransform;
      CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
        this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
        vertexReg: 14,
        transformVar: v76);
      if ( !v183[76].m_bMaterialVarsChanged )
      {
        v77 = info->m_nSeamlessMappingScale;
        v78 = v77 != -1 && params[v77]->m_VecVal.x != 0.0;
        pShaderShadow_3 = (*((_BYTE *)params[info->m_nEnvmapMask] + 28) & 0xF) == 3;
        if ( !v78 )
          CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
            this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
            vertexReg: 48,
            transformVar: info->m_nBaseTextureTransform);
        if ( v192 && v195 == 0 )
          CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
            this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
            vertexReg: 50,
            transformVar: info->m_nBumpTransform);
        if ( pShaderShadow_3 )
        {
          CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
            this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
            vertexReg: 52,
            transformVar: info->m_nEnvmapMaskTransform);
        }
        else if ( v204 != 0 )
        {
          CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
            this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
            vertexReg: 52,
            transformVar: info->m_nBumpTransform2);
        }
      }
      if ( !g_pConfig->bShowSpecular || g_pConfig->nFullbright == 2 )
      {
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 0;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v82 = (_DWORD *)p_m_nVarChangeID[225];
        v82[1] = 0;
        v82[2] = 0;
        v82[3] = 0;
        v82[4] = 0;
        p_m_nVarChangeID[225] = (unsigned int)(v82 + 5);
      }
      else
      {
        v79 = CBaseShader::s_ppParams[info->m_nEnvmapTint];
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 0;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v80 = p_m_nVarChangeID[225];
        *(float *)(v80 + 4) = v79->m_VecVal.x;
        v80 += 20;
        y = v79->m_VecVal.y;
        p_m_nVarChangeID[225] = v80;
        *(float *)(v80 - 12) = y;
        *(float *)(v80 - 8) = v79->m_VecVal.z;
        *(float *)(v80 - 4) = v79->m_VecVal.w;
      }
      if ( v195 != 0 )
      {
        v83 = info->m_nDetailTint;
        x_low = 1065353216;
        y_low = 1065353216;
        z_low = 1065353216;
        if ( v83 != -1 )
        {
          v87 = params[v83];
          x_low = LODWORD(v87->m_VecVal.x);
          y_low = LODWORD(v87->m_VecVal.y);
          z_low = LODWORD(v87->m_VecVal.z);
        }
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 8;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v88 = (float *)p_m_nVarChangeID[225];
        *((_DWORD *)v88 + 1) = x_low;
        v89 = v176;
        *((_DWORD *)v88 + 2) = y_low;
        *((_DWORD *)v88 + 3) = z_low;
        v88[4] = v89;
        p_m_nVarChangeID[225] = (unsigned int)(v88 + 5);
      }
      v90 = (int *)params[info->m_nSelfIllumTint];
      v169.m_nDETAIL_BLEND_MODE = v90[3];
      v169.m_nSHADER_SRGB_READ = v90[4];
      v91 = v90[5];
      v92 = params[info->m_nEnvmapContrast];
      m_nEnvmapSaturation = info->m_nEnvmapSaturation;
      v169.m_nLIGHTING_PREVIEW = v91;
      v94 = v92->m_VecVal.x;
      v95 = params[m_nEnvmapSaturation];
      m_nFresnelReflection = info->m_nFresnelReflection;
      *(float *)&v178 = v94;
      v97 = v95->m_VecVal.x;
      v98 = params[m_nFresnelReflection];
      v99 = params[info->m_nEnvmap];
      v176 = v97;
      v100 = v98->m_VecVal.x;
      LOBYTE(v98) = *((_BYTE *)v99 + 28) & 0xF;
      *((float *)&vec_8 + 1) = v100;
      pShaderShadow_3a = (_BYTE)v98 == 3;
      if ( (_BYTE)v98 == 3 )
      {
        v101 = info->m_nEnvMapLightScale;
        if ( v101 == -1
          || params[v101]->m_VecVal.x <= 0.0
          || g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 && v204 != 0 )
        {
          v174 = 1;
        }
        else
        {
          v174 = 2;
        }
      }
      else
      {
        v174 = 0;
      }
      *(&v183[76].m_bMaterialVarsChanged + 1) = true;
      v102 = pShaderShadow_3a && (*(float *)&v178 != 0.0 && *(float *)&v178 != 1.0 || v176 != 1.0);
      v103 = pShaderShadow_3a && *((float *)&vec_8 + 1) != 1.0;
      v104 = ((*params)->m_intVal & 0x40) != 0
          && (*(float *)&v169.m_nDETAIL_BLEND_MODE != 1.0
           || *(float *)&v169.m_nSHADER_SRGB_READ != 1.0
           || *(float *)&v169.m_nLIGHTING_PREVIEW != 1.0);
      if ( v102 || v103 || v104 || !g_pConfig->bShowSpecular )
        *(&v183[76].m_bMaterialVarsChanged + 1) = false;
      if ( !*(&v183[76].m_bMaterialVarsChanged + 1) )
      {
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 2;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        v105 = params[info->m_nEnvmapContrast];
        v106 = p_m_nVarChangeID[225] + 16;
        *(float *)(v106 - 16) = v105->m_VecVal.x;
        p_m_nVarChangeID[225] = v106;
        *(float *)(v106 - 12) = v105->m_VecVal.y;
        *(float *)(v106 - 8) = v105->m_VecVal.z;
        *(float *)(v106 - 4) = v105->m_VecVal.w;
        v107 = params[info->m_nEnvmapSaturation];
        v108 = (float *)p_m_nVarChangeID[225];
        *v108 = v107->m_VecVal.x;
        v108 += 4;
        v109 = v107->m_VecVal.y;
        p_m_nVarChangeID[225] = (unsigned int)v108;
        *(v108 - 3) = v109;
        *(v108 - 2) = v107->m_VecVal.z;
        *(v108 - 1) = v107->m_VecVal.w;
        v110 = params[info->m_nFresnelReflection]->m_VecVal.x;
        v111 = p_m_nVarChangeID[225];
        *(_DWORD *)v111 = 0;
        *(_DWORD *)(v111 + 4) = 0;
        *(float *)(v111 + 8) = 1.0 - v110;
        *(float *)(v111 + 12) = v110;
        p_m_nVarChangeID[225] = v111 + 16;
        v112 = params[info->m_nSelfIllumTint];
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 7;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v113 = p_m_nVarChangeID[225];
        *(float *)(v113 + 4) = v112->m_VecVal.x;
        v113 += 20;
        v114 = v112->m_VecVal.y;
        p_m_nVarChangeID[225] = v113;
        *(float *)(v113 - 12) = v114;
        *(float *)(v113 - 8) = v112->m_VecVal.z;
        *(float *)(v113 - 4) = v112->m_VecVal.w;
      }
      if ( v174 == 2 )
      {
        v115 = info->m_nEnvMapLightScale;
        if ( v115 == -1 )
          v116 = 0.0;
        else
          v116 = params[v115]->m_VecVal.x;
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 20;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v117 = (float *)p_m_nVarChangeID[225];
        v117[1] = 0.0;
        v117[2] = v116;
        v117[3] = 0.0;
        v117[4] = 0.0;
        p_m_nVarChangeID[225] = (unsigned int)(v117 + 5);
      }
      if ( isBaseTexture[0] )
      {
        ShaderAPITextureBindHandle = CBaseShader::GetShaderAPITextureBindHandle(
                                       this: pShader,
                                       nTextureVar: info->m_nBaseTexture,
                                       nFrameVar: info->m_nBaseTextureFrame,
                                       nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 0x80000000;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = ShaderAPITextureBindHandle;
        p_m_nVarChangeID[225] += 4;
      }
      if ( g_pConfig->nFullbright == 2 && ((*params)->m_intVal & 2) == 0 )
      {
        if ( v188 )
        {
          *(_DWORD *)p_m_nVarChangeID[225] = 9;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 0x80000000;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 8;
        }
        else
        {
          *(_DWORD *)p_m_nVarChangeID[225] = 9;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 0x80000000;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 7;
        }
        p_m_nVarChangeID[225] += 4;
        if ( v194 )
        {
          *(_DWORD *)p_m_nVarChangeID[225] = 9;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = -2147483641;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 7;
          p_m_nVarChangeID[225] += 4;
        }
        if ( v195 != 0 )
        {
          *(_DWORD *)p_m_nVarChangeID[225] = 9;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 12;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 7;
          p_m_nVarChangeID[225] += 4;
        }
        *(_DWORD *)p_m_nVarChangeID[225] = 4;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 47;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 1;
        v119 = (_DWORD *)p_m_nVarChangeID[225];
        v119[1] = 0;
        v119[2] = 0;
        v119[3] = 0;
        v119[4] = 0;
        p_m_nVarChangeID[225] = (unsigned int)(v119 + 5);
      }
      if ( v195 != 0 )
        CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureScaledTransform(
          this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *)p_m_nVarChangeID,
          vertexReg: 50,
          transformVar: info->m_nBaseTextureTransform,
          scaleVar: info->m_nDetailScale);
      if ( v194 )
      {
        v120 = CBaseShader::GetShaderAPITextureBindHandle(
                 this: pShader,
                 nTextureVar: info->m_nBaseTexture2,
                 nFrameVar: info->m_nBaseTexture2Frame,
                 nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = -2147483641;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = v120;
        p_m_nVarChangeID[225] += 4;
      }
      if ( v195 != 0 )
      {
        v121 = info->m_nDetailTextureCombineMode;
        pShaderShadowa = false;
        if ( v121 != -1 )
        {
          v122 = params[v121]->m_intVal;
          if ( v122 == 2 || v122 == 3 || v122 == 4 )
            pShaderShadowa = true;
        }
        v123 = CBaseShader::GetShaderAPITextureBindHandle(
                 this: pShader,
                 nTextureVar: info->m_nDetail,
                 nFrameVar: info->m_nDetailFrame,
                 nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = (pShaderShadowa ? 0x80000000 : 0) | 0xC;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = v123;
        p_m_nVarChangeID[225] += 4;
      }
      if ( v192 || v184 != 0 )
      {
        if ( g_pConfig->m_bFastNoBump )
        {
          if ( v186 )
          {
            *(_DWORD *)p_m_nVarChangeID[225] = 9;
            p_m_nVarChangeID[225] += 4;
            *(_DWORD *)p_m_nVarChangeID[225] = 4;
            p_m_nVarChangeID[225] += 4;
            *(_DWORD *)p_m_nVarChangeID[225] = 10;
          }
          else
          {
            *(_DWORD *)p_m_nVarChangeID[225] = 9;
            p_m_nVarChangeID[225] += 4;
            *(_DWORD *)p_m_nVarChangeID[225] = 4;
            p_m_nVarChangeID[225] += 4;
            *(_DWORD *)p_m_nVarChangeID[225] = 9;
          }
        }
        else
        {
          v124 = CBaseShader::GetShaderAPITextureBindHandle(
                   this: pShader,
                   nTextureVar: info->m_nBumpmap,
                   nFrameVar: info->m_nBumpFrame,
                   nTextureChannel: 0);
          *(_DWORD *)p_m_nVarChangeID[225] = 10;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 4;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = v124;
        }
        p_m_nVarChangeID[225] += 4;
      }
      if ( v204 != 0 )
      {
        if ( g_pConfig->m_bFastNoBump )
        {
          if ( v186 )
          {
            *(_DWORD *)p_m_nVarChangeID[225] = 9;
            p_m_nVarChangeID[225] += 4;
            *(_DWORD *)p_m_nVarChangeID[225] = 5;
            p_m_nVarChangeID[225] += 4;
            *(_DWORD *)p_m_nVarChangeID[225] = 9;
          }
          else
          {
            *(_DWORD *)p_m_nVarChangeID[225] = 9;
            p_m_nVarChangeID[225] += 4;
            *(_DWORD *)p_m_nVarChangeID[225] = 5;
            p_m_nVarChangeID[225] += 4;
            *(_DWORD *)p_m_nVarChangeID[225] = 10;
          }
        }
        else
        {
          v125 = CBaseShader::GetShaderAPITextureBindHandle(
                   this: pShader,
                   nTextureVar: info->m_nBumpmap2,
                   nFrameVar: info->m_nBumpFrame2,
                   nTextureChannel: 0);
          *(_DWORD *)p_m_nVarChangeID[225] = 10;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 5;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = v125;
        }
        p_m_nVarChangeID[225] += 4;
      }
      if ( v185 != 0 )
      {
        if ( g_pConfig->m_bFastNoBump )
        {
          *(_DWORD *)p_m_nVarChangeID[225] = 9;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 8;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 9;
        }
        else
        {
          v126 = CBaseShader::GetShaderAPITextureBindHandle(
                   this: pShader,
                   nTextureVar: info->m_nBumpMask,
                   nFrameVar: -1,
                   nTextureChannel: 0);
          *(_DWORD *)p_m_nVarChangeID[225] = 10;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 8;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = v126;
        }
        p_m_nVarChangeID[225] += 4;
      }
      if ( v191 )
      {
        v127 = CBaseShader::GetShaderAPITextureBindHandle(
                 this: pShader,
                 nTextureVar: info->m_nEnvmapMask,
                 nFrameVar: info->m_nEnvmapMaskFrame,
                 nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 5;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = v127;
        p_m_nVarChangeID[225] += 4;
      }
      if ( v182 != 0 )
      {
        m_nPaintSplatNormal = info->m_nPaintSplatNormal;
        if ( m_nPaintSplatNormal != -1 && (*((_BYTE *)params[m_nPaintSplatNormal] + 28) & 0xF) == 3 )
        {
          v129 = CBaseShader::GetShaderAPITextureBindHandle(
                   this: pShader,
                   nTextureVar: m_nPaintSplatNormal,
                   nFrameVar: -1,
                   nTextureChannel: 0);
          *(_DWORD *)p_m_nVarChangeID[225] = 10;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = 6;
          p_m_nVarChangeID[225] += 4;
          *(_DWORD *)p_m_nVarChangeID[225] = v129;
          p_m_nVarChangeID[225] += 4;
        }
      }
      if ( v189 != 0 )
      {
        v130 = CBaseShader::GetShaderAPITextureBindHandle(
                 this: pShader,
                 nTextureVar: info->m_nBlendModulateTexture,
                 nFrameVar: -1,
                 nTextureChannel: 0);
        *(_DWORD *)p_m_nVarChangeID[225] = 10;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = 3;
        p_m_nVarChangeID[225] += 4;
        *(_DWORD *)p_m_nVarChangeID[225] = v130;
        p_m_nVarChangeID[225] += 4;
      }
      *(_DWORD *)p_m_nVarChangeID[225] = 0;
      p_m_nVarChangeID[225] += 4;
      v6 = params;
    }
LABEL_335:
    if ( pShaderAPI != nullptr )
    {
      m_nEnvmap = info->m_nEnvmap;
      v160[1] = v183[1].__vftable;
      v160[0] = 2;
      v160[2] = 2;
      v162 = &v161;
      v160[3] = (char *)v183 + 16;
      if ( (*((_BYTE *)params[m_nEnvmap] + 28) & 0xF) == 3 )
      {
        pShaderShadowb = (IShaderShadow *)info->m_nEnvmapFrame;
        v132 = v181 ? 0 : 0x80000000;
        if ( CBaseShader::s_ppParams[m_nEnvmap]->IsTextureValueInternalEnvCubemap(this: CBaseShader::s_ppParams[m_nEnvmap]) )
        {
          *(_DWORD *)v162 = 9;
          v162 += 4;
          *(_DWORD *)v162 = v132 | 2;
          v162 += 4;
          *(_DWORD *)v162 = 25;
        }
        else
        {
          v133 = CBaseShader::GetShaderAPITextureBindHandle(
                   this: pShader,
                   nTextureVar: m_nEnvmap,
                   nFrameVar: (int)pShaderShadowb,
                   nTextureChannel: 0);
          *(_DWORD *)v162 = 10;
          v162 += 4;
          *(_DWORD *)v162 = v132 | 2;
          v162 += 4;
          *(_DWORD *)v162 = v133;
        }
        v162 += 4;
      }
      pShaderShadow_3b = v183[76].m_bMaterialVarsChanged;
      *(float *)&v134 = COERCE_FLOAT(
                          ((int (__thiscall *)(ITexture *, _DWORD))pShaderAPI->ForceExcludeOverride)(
                            a1: pShaderAPI,
                            a2: 0));
      v178 = (IShaderShadow_vtbl *)v134;
      if ( *(float *)&v134 != 0.0 )
        pShaderShadow_3b = false;
      if ( v134 == 3 )
      {
        ((void (__thiscall *)(ITexture *, int *))pShaderAPI->GetLowResColorSample)(
          a1: pShaderAPI,
          a2: &v169.m_nDETAIL_BLEND_MODE);
        v203 = ((double (__thiscall *)(ITexture *))pShaderAPI->__vftable[1].IsCubeMap)(a1: pShaderAPI);
        m_nDETAIL_BLEND_MODE = v169.m_nDETAIL_BLEND_MODE;
        m_nSHADER_SRGB_READ = v169.m_nSHADER_SRGB_READ;
        m_nLIGHTING_PREVIEW = v169.m_nLIGHTING_PREVIEW;
        *(_DWORD *)v162 = 4;
        v162 += 4;
        *(_DWORD *)v162 = 12;
        v162 += 4;
        *(_DWORD *)v162 = 1;
        v162 += 4;
        *(float *)v162 = *(float *)&m_nDETAIL_BLEND_MODE * (float)(1.0 / v203);
        v162 += 4;
        *(float *)v162 = *(float *)&m_nSHADER_SRGB_READ * (float)(1.0 / v203);
        v162 += 4;
        *(float *)v162 = *(float *)&m_nLIGHTING_PREVIEW * (float)(1.0 / v203);
        v162 += 4;
        *(_DWORD *)v162 = 1065353216;
        v162 += 4;
      }
      if ( v182 != 0 )
      {
        ((void (__thiscall *)(ITexture *, _DWORD, VMatrix *))pShaderAPI->__vftable[1].IncrementReferenceCount)(
          a1: pShaderAPI,
          a2: 0,
          a3: &v163);
        v138 = VMatrix::Transpose3x3(this: &v163, result: (VMatrix *)&dst.m_nFlashlightTextureFrameVar);
        VMatrix::operator=(this: &v163, mOther: v138);
        vec = *(_QWORD *)&v163.m[0][0];
        vec_8 = 0;
        VectorNormalize((Vector *)&vec);
        GetNumAnimationFrames = (void (__thiscall *)(IShaderDynamicAPI *, int, const float *, int, bool))pShaderAPI->GetNumAnimationFrames;
        *(float *)&v169.m_nDETAIL_BLEND_MODE = (float)(*(float *)&vec_8 * 0.0) - *((float *)&vec + 1);
        *(float *)&v169.m_nSHADER_SRGB_READ = *(float *)&vec - (float)(*(float *)&vec_8 * 0.0);
        *(float *)&v169.m_nLIGHTING_PREVIEW = (float)(*((float *)&vec + 1) * 0.0) - (float)(*(float *)&vec * 0.0);
        GetNumAnimationFrames(this: (IShaderDynamicAPI *)pShaderAPI, a2: 22, a3: (const float *)&vec, a4: 1, a5: false);
        ((void (__thiscall *)(ITexture *, int, int *, int, _DWORD))pShaderAPI->GetNumAnimationFrames)(
          a1: pShaderAPI,
          a2: 23,
          a3: &v169.m_nDETAIL_BLEND_MODE,
          a4: 1,
          a5: 0);
      }
      v176 = COERCE_FLOAT(pShaderAPI->GetMappingHeight(this: pShaderAPI));
      v140 = pShaderAPI->GetMappingHeight(this: pShaderAPI) == 2;
      LODWORD(vec_8) = pShaderShadow_3b;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "FASTPATH", pShaderShadow_3b, "bVertexShaderFastPath");
      v141 = vec_8;
      *(_DWORD *)v162 = 12;
      v162 += 4;
      *(_DWORD *)v162 = v141 + 2 * v140;
      v162 += 4;
      v142 = *(&v183[76].m_bMaterialVarsChanged + 1);
      v205 = v142;
      if ( *(float *)&v178 != 0.0 )
        v142 = false;
      if ( *(&v183[76].m_bMaterialVarsChanged + 2) )
      {
        v190 = ((int (__thiscall *)(ITexture *))pShaderAPI->__vftable[1].GetResourceData)(a1: pShaderAPI);
        pShaderShadow_3c = LODWORD(v176) == 2;
      }
      else
      {
        v190 = false;
        pShaderShadow_3c = false;
      }
      v180 = false;
      v181 = false;
      v7 = g_pConfig->nFullbright == 1;
      *(float *)&vec = mat_ambient_light_r.m_pParent->m_Value.m_fValue;
      HIDWORD(vec) = LODWORD(mat_ambient_light_g.m_pParent->m_Value.m_fValue);
      vec_8 = LODWORD(mat_ambient_light_b.m_pParent->m_Value.m_fValue);
      if ( v7 )
      {
        LODWORD(vec_8) = 0;
        vec = 0;
      }
      v143 = vec;
      *(_DWORD *)v162 = 3;
      v162 += 4;
      *(_DWORD *)v162 = 31;
      v162 += 4;
      *(_DWORD *)v162 = 1;
      v162 += 4;
      *(_QWORD *)v162 = v143;
      *((_QWORD *)v162 + 1) = vec_8;
      v162 += 16;
      GetDXSupportLevel = g_pHardwareConfig->GetDXSupportLevel;
      textureVar = SLODWORD(params[info->m_nEnvmapContrast]->m_VecVal.x);
      if ( GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        v169.m_nDOPIXELFOG = pShaderAPI->GetMappingHeight(this: pShaderAPI) == 2;
        v169.m_nSHADER_SRGB_READ = v142;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "FASTPATH", v142, "bPixelShaderFastPath");
        v150 = v142 && *(float *)&textureVar == 1.0;
        v169.m_nDETAIL_BLEND_MODE = v150;
        if ( g_shaderConfigDumpEnable )
        {
          v151 = v142 && *(float *)&textureVar == 1.0;
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "FASTPATHENVMAPCONTRAST",
            v151,
            "bPixelShaderFastPath && envmapContrast == 1.0f");
        }
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            pShaderShadow_3c,
            "bWriteWaterFogToAlpha");
        m_nDOPIXELFOG = v169.m_nDOPIXELFOG;
        *(_DWORD *)v162 = 11;
        v162 += 4;
        *(_DWORD *)v162 = v169.m_nDETAIL_BLEND_MODE
                        + 2 * (v169.m_nSHADER_SRGB_READ + 2 * (pShaderShadow_3c + 2 * m_nDOPIXELFOG));
      }
      else
      {
        lightmappedgeneric_ps20b_Dynamic_Index::lightmappedgeneric_ps20b_Dynamic_Index(
          this: (lightmappedgeneric_ps20b_Dynamic_Index *)&v169.m_nFANCY_BLENDING,
          (IShaderDynamicAPI *)pShaderAPI);
        v169.m_nSEAMLESS = v205;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "FASTPATH", v205, "bFastPath");
        v145 = v142 && *(float *)&textureVar == 1.0;
        v169.m_nFANCY_BLENDING = v145;
        if ( g_shaderConfigDumpEnable )
        {
          v146 = v142 && *(float *)&textureVar == 1.0;
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "FASTPATHENVMAPCONTRAST",
            v146,
            "bPixelShaderFastPath && envmapContrast == 1.0f");
        }
        v169.m_nDETAIL_BLEND_MODE = v190;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "WRITE_DEPTH_TO_DESTALPHA", v190, "bWriteDepthToAlpha");
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            pShaderShadow_3c,
            "bWriteWaterFogToAlpha");
        v147 = v180;
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", v180, "bFlashlightShadows");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS dyn  var %s = %d (%s)", "PAINTREFRACT", 0, "0");
        }
        v148 = v169.m_nDOPIXELFOG;
        v149 = v169.m_nDETAIL_BLEND_MODE;
        *(_DWORD *)v162 = 11;
        v162 += 4;
        *(_DWORD *)v162 = v169.m_nFANCY_BLENDING
                        + 2 * (v169.m_nSEAMLESS + 2 * (pShaderShadow_3c + 2 * (v149 + 2 * (v147 + v148))));
      }
      v162 += 4;
      *(_DWORD *)v162 = 0;
      IsVolumeTexture = (void (__thiscall *)(IShaderDynamicAPI *, unsigned __int8 *))pShaderAPI->__vftable[1].IsVolumeTexture;
      v162 += 4;
      IsVolumeTexture(this: (IShaderDynamicAPI *)pShaderAPI, a2: (unsigned __int8 *)v160);
      v6 = params;
    }
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
  if ( ((*v6)->m_intVal & 0x100) != 0 && *(&v183[76].m_bMaterialVarsChanged + 3) )
    CBaseVSShader::DrawEqualDepthToDestAlpha(this: pShader);
}

//------------------------------------------------------------------------------
// Address: 0x10045020
// Name: public: int lightmappedgeneric_vs20_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall lightmappedgeneric_vs20_Static_Index::GetIndex(lightmappedgeneric_vs20_Static_Index *this)
{
  return 4
       * (this->m_nENVMAP_MASK
        + 2
        * (this->m_nTANGENTSPACE
         + 2
         * (this->m_nBUMPMAP
          + 2
          * (this->m_nDETAILTEXTURE
           + 2
           * (this->m_nVERTEXCOLOR
            + 2
            * (this->m_nVERTEXALPHATEXBLENDFACTOR
             + 2
             * (this->m_nSEAMLESS
              + 2
              * (this->m_nBUMPMASK
               + this->m_nFANCY_BLENDING
               + 2
               * (this->m_nSELFILLUM
                + 2
                * (this->m_nLIGHTING_PREVIEW
                 + 4 * (this->m_nPAINT + 2 * (this->m_nDOPIXELFOG + 2 * this->m_nHARDWAREFOGBLEND))))))))))));
}
