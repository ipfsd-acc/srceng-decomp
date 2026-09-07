// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/blob_helper.cpp
// Functions: 5
// ============================================================

#include "materialsystem\stdshaders\blob_helper.h"

//------------------------------------------------------------------------------
// Address: 0x10004E90
// Name: public: int blob_ps30_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall blob_ps30_Static_Index::GetIndex(blob_ps30_Static_Index *this)
{
  return 20
       * (this->m_nBACK_SURFACE
        + 2
        * (this->m_nLIGHT_WARP
         + 2
         * (this->m_nFRESNEL_WARP
          + 2
          * (this->m_nHIGH_PRECISION_DEPTH
           + 2
           * (this->m_nINTERIOR_LAYER
            + 2
            * (this->m_nSELF_ILLUM_FRESNEL
             + 2
             * (this->m_nOPACITY_TEXTURE
              + 2
              * (this->m_nFLASHLIGHTDEPTHFILTERMODE
               + 3 * (this->m_nCONTACT_SHADOW + 2 * (this->m_nSELF_ILLUM_PULSE + 2 * this->m_nVOLUME_TEXTURE))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10004EE0
// Name: void InitParamsBlob(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct BlobVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsBlob(CBaseVSShader *pShader, IMaterialVar **params, const char *pMaterialName, BlobVars_t *info)
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
  IMaterialVar *v38; // ecx
  IMaterialVar *v39; // ecx
  IMaterialVar *v40; // ecx
  IMaterialVar *v41; // ecx
  IMaterialVar *v42; // ecx
  IMaterialVar *v43; // ecx
  bool v44; // zf
  void (__thiscall *SetStringValue)(IMaterialVar *, const char *); // eax
  IMaterialVar *v46; // ecx
  IMaterialVar *v47; // ecx
  IMaterialVar *v48; // ecx
  IMaterialVar *v49; // ecx
  IMaterialVar *v50; // ecx
  IMaterialVar *v51; // ecx
  IMaterialVar *v52; // ecx
  IMaterialVar *v53; // ecx
  IMaterialVar *v54; // ecx
  IMaterialVar *v55; // ecx
  IMaterialVar *v56; // ecx
  IMaterialVar *v57; // ecx
  IMaterialVar *v58; // ecx
  IMaterialVar *v59; // ecx
  IMaterialVar *v60; // ecx
  IMaterialVar *v61; // ecx
  IMaterialVar *v62; // ecx
  IMaterialVar *v63; // ecx
  IMaterialVar *v64; // ecx
  IMaterialVar *v65; // ecx
  IMaterialVar *v66; // ecx
  IMaterialVar *v67; // ecx
  IMaterialVar *v68; // ecx
  IMaterialVar *v69; // ecx
  IMaterialVar *v70; // ecx

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
      v16->SetVecValue_4(this: v16, a2: kDefaultInteriorColor, a3: 3);
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
      v20->SetVecValue_4(this: v20, a2: kDefaultFresnelParams, a3: 3);
    }
  }
  if ( info->m_nBaseColorTint != -1 )
  {
    v21 = params[info->m_nBaseColorTint];
    if ( !v21->IsDefined(this: v21) )
    {
      v22 = params[info->m_nBaseColorTint];
      v22->SetVecValue_4(this: v22, a2: kDefaultBaseColorTint, a3: 3);
    }
  }
  if ( info->m_nDiffuseScale != -1 )
  {
    v23 = params[info->m_nDiffuseScale];
    if ( !v23->IsDefined(this: v23) )
      ((void (__stdcall *)(int))params[info->m_nDiffuseScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecExp != -1 )
  {
    v24 = params[info->m_nSpecExp];
    if ( !v24->IsDefined(this: v24) )
      ((void (__stdcall *)(int))params[info->m_nSpecExp]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecScale != -1 )
  {
    v25 = params[info->m_nSpecScale];
    if ( !v25->IsDefined(this: v25) )
      ((void (__stdcall *)(int))params[info->m_nSpecScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecExp2 != -1 )
  {
    v26 = params[info->m_nSpecExp2];
    if ( !v26->IsDefined(this: v26) )
      ((void (__stdcall *)(int))params[info->m_nSpecExp2]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSpecScale2 != -1 )
  {
    v27 = params[info->m_nSpecScale2];
    if ( !v27->IsDefined(this: v27) )
      ((void (__stdcall *)(int))params[info->m_nSpecScale2]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nRimLightExp != -1 )
  {
    v28 = params[info->m_nRimLightExp];
    if ( !v28->IsDefined(this: v28) )
      ((void (__stdcall *)(int))params[info->m_nRimLightExp]->SetFloatValue)(a1: 1092616192);
  }
  if ( info->m_nRimLightScale != -1 )
  {
    v29 = params[info->m_nRimLightScale];
    if ( !v29->IsDefined(this: v29) )
      ((void (__stdcall *)(int))params[info->m_nRimLightScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nSelfIllumFresnelEnable != -1 )
  {
    v30 = params[info->m_nSelfIllumFresnelEnable];
    if ( !v30->IsDefined(this: v30) )
    {
      v31 = params[info->m_nSelfIllumFresnelEnable];
      v31->SetIntValue(this: v31, a2: 0);
    }
  }
  if ( info->m_nSelfIllumFresnelParams != -1 )
  {
    v32 = params[info->m_nSelfIllumFresnelParams];
    if ( !v32->IsDefined(this: v32) )
    {
      v33 = params[info->m_nSelfIllumFresnelParams];
      v33->SetVecValue_4(this: v33, a2: kDefaultSelfIllumFresnelParams, a3: 3);
    }
  }
  if ( info->m_nSelfIllumTint != -1 )
  {
    v34 = params[info->m_nSelfIllumTint];
    if ( !v34->IsDefined(this: v34) )
    {
      v35 = params[info->m_nSelfIllumTint];
      v35->SetVecValue_4(this: v35, a2: kDefaultSelfIllumTint, a3: 3);
    }
  }
  if ( info->m_nUVProjOffset != -1 )
  {
    v36 = params[info->m_nUVProjOffset];
    if ( !v36->IsDefined(this: v36) )
    {
      v37 = params[info->m_nUVProjOffset];
      v37->SetVecValue_4(this: v37, a2: kDefaultUVProjOffset, a3: 3);
    }
  }
  if ( info->m_nBBMin != -1 )
  {
    v38 = params[info->m_nBBMin];
    if ( !v38->IsDefined(this: v38) )
    {
      v39 = params[info->m_nBBMin];
      v39->SetVecValue_4(this: v39, a2: kDefaultBB, a3: 3);
    }
  }
  if ( info->m_nBBMax != -1 )
  {
    v40 = params[info->m_nBBMax];
    if ( !v40->IsDefined(this: v40) )
    {
      v41 = params[info->m_nBBMax];
      v41->SetVecValue_4(this: v41, a2: kDefaultBB, a3: 3);
    }
  }
  if ( info->m_nArmature != -1 )
  {
    v42 = params[info->m_nArmature];
    if ( !v42->IsDefined(this: v42) )
    {
      v43 = params[info->m_nArmature];
      v43->SetIntValue(this: v43, a2: 0);
    }
  }
  v44 = !g_pHardwareConfig->SupportsBorderColor(this: g_pHardwareConfig);
  SetStringValue = params[info->m_nFlashlightTexture]->SetStringValue;
  if ( v44 )
    ((void (__stdcall *)(const char *))SetStringValue)(a1: "effects/flashlight001");
  else
    ((void (__stdcall *)(const char *))SetStringValue)(a1: "effects/flashlight_border");
  if ( info->m_nFlashlightTextureFrame != -1 )
  {
    v46 = params[info->m_nFlashlightTextureFrame];
    if ( !v46->IsDefined(this: v46) )
    {
      v47 = params[info->m_nFlashlightTextureFrame];
      v47->SetIntValue(this: v47, a2: 0);
    }
  }
  if ( info->m_nArmColorTint != -1 )
  {
    v48 = params[info->m_nArmColorTint];
    if ( !v48->IsDefined(this: v48) )
    {
      v49 = params[info->m_nArmColorTint];
      v49->SetVecValue_4(this: v49, a2: kDefaultArmColorTint, a3: 3);
    }
  }
  if ( info->m_nArmWiden != -1 )
  {
    v50 = params[info->m_nArmWiden];
    if ( !v50->IsDefined(this: v50) )
    {
      v51 = params[info->m_nArmWiden];
      v51->SetIntValue(this: v51, a2: 0);
    }
  }
  if ( info->m_nArmWidthExp != -1 )
  {
    v52 = params[info->m_nArmWidthExp];
    if ( !v52->IsDefined(this: v52) )
      ((void (__stdcall *)(int))params[info->m_nArmWidthExp]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nArmWidthScale != -1 )
  {
    v53 = params[info->m_nArmWidthScale];
    if ( !v53->IsDefined(this: v53) )
      ((void (__stdcall *)(int))params[info->m_nArmWidthScale]->SetFloatValue)(a1: 1065353216);
  }
  if ( info->m_nArmWidthBias != -1 )
  {
    v54 = params[info->m_nArmWidthBias];
    if ( !v54->IsDefined(this: v54) )
      ((void (__stdcall *)(_DWORD))params[info->m_nArmWidthBias]->SetFloatValue)(a1: 0);
  }
  if ( info->m_nAnimateArmPulses != -1 )
  {
    v55 = params[info->m_nAnimateArmPulses];
    if ( !v55->IsDefined(this: v55) )
    {
      v56 = params[info->m_nAnimateArmPulses];
      v56->SetIntValue(this: v56, a2: 1);
    }
  }
  if ( info->m_nVolumeTex != -1 )
  {
    v57 = params[info->m_nVolumeTex];
    if ( !v57->IsDefined(this: v57) )
    {
      v58 = params[info->m_nVolumeTex];
      v58->SetIntValue(this: v58, a2: 0);
    }
  }
  if ( info->m_nBumpFrame != -1 )
  {
    v59 = params[info->m_nBumpFrame];
    if ( !v59->IsDefined(this: v59) )
    {
      v60 = params[info->m_nBumpFrame];
      v60->SetIntValue(this: v60, a2: 0);
    }
  }
  if ( info->m_nGlowScale != -1 )
  {
    v61 = params[info->m_nGlowScale];
    if ( !v61->IsDefined(this: v61) )
    {
      v62 = params[info->m_nGlowScale];
      v62->SetIntValue(this: v62, a2: 1);
    }
  }
  if ( info->m_nPulse != -1 )
  {
    v63 = params[info->m_nPulse];
    if ( !v63->IsDefined(this: v63) )
    {
      v64 = params[info->m_nPulse];
      v64->SetIntValue(this: v64, a2: 0);
    }
  }
  if ( info->m_nContactShadows != -1 )
  {
    v65 = params[info->m_nContactShadows];
    if ( !v65->IsDefined(this: v65) )
    {
      v66 = params[info->m_nContactShadows];
      v66->SetIntValue(this: v66, a2: 0);
    }
  }
  if ( info->m_nPulse >= 0 )
  {
    v67 = params[info->m_nPulse];
    if ( v67->IsDefined(this: v67) && params[info->m_nPulse]->m_intVal != 0 && info->m_nContactShadows >= 0 )
    {
      v68 = params[info->m_nContactShadows];
      if ( v68->IsDefined(this: v68) && params[info->m_nContactShadows]->m_intVal != 0 )
      {
        _Warning(
          a1: "ERROR: material (%s) has invalid settings - contactShadows and pulse cannot both be set to 1\n",
          pMaterialName);
        v69 = params[info->m_nContactShadows];
        v69->SetIntValue(this: v69, a2: 0);
      }
    }
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  v70 = params[info->m_nInteriorEnable];
  if ( v70->IsDefined(this: v70) && params[info->m_nInteriorEnable]->m_intVal != 0 )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x8000);
}

//------------------------------------------------------------------------------
// Address: 0x100057B0
// Name: void InitBlob(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct BlobVars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitBlob(CBaseVSShader *pShader, IMaterialVar **params, BlobVars_t *info)
{
  IMaterialVar *v3; // ecx
  IMaterialVar *v4; // ecx
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx

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
  if ( info->m_nFlashlightTexture != -1 )
  {
    v9 = params[info->m_nFlashlightTexture];
    if ( v9->IsDefined(this: v9) )
      CBaseShader::LoadTexture(
        this: pShader,
        nTextureVar: info->m_nFlashlightTexture,
        nAdditionalCreationFlags: 0x80000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100058E0
// Name: void DrawArmature(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct BlobVars_t __near &,enum VertexCompressionType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawArmature(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        BlobVars_t *info,
        VertexCompressionType_t vertexCompression,
        int nPassIdx)
{
  IMaterialVar **v7; // ebx
  int m_nSelfIllumFresnelEnable; // eax
  bool v10; // cc
  int m_nArmWiden; // eax
  IMaterialVar *v12; // ecx
  int m_nAnimateArmPulses; // eax
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  BOOL v15; // ebx
  void (__thiscall *GetDX9LightState)(IShaderDynamicAPI *, LightState_t *); // edx
  bool v17; // sf
  IMaterialVar *v18; // ecx
  float x; // xmm0_4
  IMaterialVar *v20; // ecx
  float v21; // xmm0_4
  IMaterialVar *v22; // ecx
  float v23; // xmm0_4
  IMaterialVar *v24; // ecx
  float v25; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v27; // ecx
  float v28; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v30; // ecx
  float *v31; // eax
  IMaterialVar *v32; // ecx
  float *v33; // eax
  IMaterialVar *v34; // ecx
  float *v35; // eax
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  void (__thiscall *v39)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v40; // ecx
  float *v41; // ebx
  int texCoordDims[5]; // [esp+5Ch] [ebp-30h] BYREF
  float flConsts[4]; // [esp+70h] [ebp-1Ch] BYREF
  LightState_t lightState; // [esp+80h] [ebp-Ch] BYREF
  bool bBaseMap; // [esp+88h] [ebp-4h]
  bool bAnimatedPulses; // [esp+89h] [ebp-3h]
  bool bArmWiden; // [esp+8Ah] [ebp-2h]
  bool bSelfIllumFresnel; // [esp+8Bh] [ebp-1h]
  unsigned __int8 bNormalMap_3; // [esp+A7h] [ebp+1Bh]

  v7 = params;
  m_nSelfIllumFresnelEnable = info->m_nSelfIllumFresnelEnable;
  if ( m_nSelfIllumFresnelEnable == -1
    || (v10 = params[m_nSelfIllumFresnelEnable]->m_intVal <= 0, bSelfIllumFresnel = true, v10) )
  {
    bSelfIllumFresnel = false;
  }
  m_nArmWiden = info->m_nArmWiden;
  if ( m_nArmWiden == -1 || (v10 = params[m_nArmWiden]->m_intVal <= 0, bArmWiden = true, v10) )
    bArmWiden = false;
  if ( info->m_nNormalMap == -1 || (v12 = params[info->m_nNormalMap], bNormalMap_3 = 1, !v12->IsDefined(this: v12)) )
    bNormalMap_3 = 0;
  bBaseMap = params[6]->IsDefined(this: params[6]);
  m_nAnimateArmPulses = info->m_nAnimateArmPulses;
  if ( m_nAnimateArmPulses == -1 || (v10 = params[m_nAnimateArmPulses]->m_intVal <= 0, bAnimatedPulses = true, v10) )
    bAnimatedPulses = false;
  if ( pShaderShadow != nullptr )
  {
    if ( nPassIdx != 0 )
      CBaseShader::SetInitialShadowState(this: pShader);
    VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
    texCoordDims[0] = 4;
    texCoordDims[1] = 4;
    texCoordDims[2] = 4;
    texCoordDims[3] = 4;
    texCoordDims[4] = 4;
    VertexShaderVertexFormat(this: pShaderShadow, a2: 4u, a3: 5, a4: texCoordDims, a5: 0);
    v15 = bArmWiden;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "WIDEN_TIPS", bArmWiden, "bArmWiden");
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "blob_arm_vs20", a3: 2 * v15);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      LODWORD(flConsts[0]) = bSelfIllumFresnel;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SELF_ILLUM_FRESNEL", bSelfIllumFresnel, "bSelfIllumFresnel");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "PRE_PASS", nPassIdx == 0, "( nPassIdx == 0 )");
      LODWORD(flConsts[2]) = bNormalMap_3 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "NORMALMAP", bNormalMap_3, "bNormalMap");
      v15 = bAnimatedPulses;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "MOVING_PULSES", bAnimatedPulses, "bAnimatedPulses");
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "blob_arm_ps20b",
        a3: LODWORD(flConsts[0]) + 2 * ((nPassIdx == 0) + 2 * (LODWORD(flConsts[2]) + 2 * v15)));
    }
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    LOBYTE(v15) = nPassIdx == 0;
    pShaderShadow->EnableAlphaToCoverage(this: pShaderShadow, a2: v15);
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: v15);
    ((void (__thiscall *)(IShaderShadow *, int, int))pShaderShadow->AlphaFunc)(a1: pShaderShadow, a2: 6, a3: 1056964608);
    pShaderShadow->EnableColorWrites(this: pShaderShadow, a2: nPassIdx > 0);
    if ( nPassIdx != 0 )
      pShaderShadow->DepthFunc(this: pShaderShadow, a2: SHADER_DEPTHFUNC_EQUAL);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: true);
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    CBaseShader::PI_SetVertexShaderAmbientLightCube(this: pShader);
    CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 4);
    CBaseShader::PI_SetPixelShaderLocalLighting(this: pShader, nFirstRegister: 20);
    CBaseShader::PI_EndCommandBuffer(this: pShader);
    v7 = params;
  }
  if ( pShaderAPI != nullptr )
  {
    if ( nPassIdx != 0 )
      pShaderAPI->SetDefaultState(this: pShaderAPI);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression);
    GetDX9LightState = pShaderAPI->GetDX9LightState;
    lightState.m_nNumLights = 0;
    *(_WORD *)&lightState.m_bAmbientLight = 0;
    GetDX9LightState(this: pShaderAPI, a2: &lightState);
    v17 = info->m_nArmWidthExp < 0;
    memset(flConsts, 0, sizeof(flConsts));
    if ( v17 || (v18 = v7[info->m_nArmWidthExp], !v18->IsDefined(this: v18)) )
      x = 1.0;
    else
      x = v7[info->m_nArmWidthExp]->m_VecVal.x;
    v17 = info->m_nArmWidthScale < 0;
    flConsts[0] = x;
    if ( v17 || (v20 = v7[info->m_nArmWidthScale], !v20->IsDefined(this: v20)) )
      v21 = 1.0;
    else
      v21 = v7[info->m_nArmWidthScale]->m_VecVal.x;
    v17 = info->m_nArmWidthBias < 0;
    flConsts[1] = v21;
    if ( v17 || (v22 = v7[info->m_nArmWidthBias], !v22->IsDefined(this: v22)) )
      v23 = 0.0;
    else
      v23 = v7[info->m_nArmWidthBias]->m_VecVal.x;
    v17 = info->m_nUVScale < 0;
    flConsts[2] = v23;
    if ( v17 || (v24 = v7[info->m_nUVScale], !v24->IsDefined(this: v24)) )
      v25 = 0.02;
    else
      v25 = v7[info->m_nUVScale]->m_VecVal.x;
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    flConsts[3] = v25;
    SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: flConsts, a4: 1, a5: false);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: flConsts);
    pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 49, a3: flConsts, a4: 1, a5: false);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
      pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: 0);
    if ( bBaseMap )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: 6,
        nFrameVar: -1);
    else
      pShaderAPI->BindStandardTexture(
        this: pShaderAPI,
        a2: SHADER_SAMPLER0,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_WHITE);
    if ( bNormalMap_3 != 0 )
      CBaseShader::BindTexture(
        this: pShader,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: info->m_nNormalMap,
        nFrameVar: -1);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: flConsts);
    if ( info->m_nSpecExp >= 0 && (v27 = v7[info->m_nSpecExp], v27->IsDefined(this: v27)) )
      v28 = v7[info->m_nSpecExp]->m_VecVal.x;
    else
      v28 = 1.0;
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    flConsts[3] = v28;
    SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: flConsts, a4: 1, a5: false);
    if ( info->m_nArmColorTint >= 0 && (v30 = v7[info->m_nArmColorTint], v30->IsDefined(this: v30)) )
    {
      v31 = (float *)v7[info->m_nArmColorTint];
      flConsts[0] = v31[3];
      flConsts[1] = v31[4];
      flConsts[2] = v31[5];
    }
    else
    {
      *(_QWORD *)flConsts = *(_QWORD *)kDefaultArmColorTint;
      flConsts[2] = 1.0;
    }
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 19, a3: flConsts, a4: 1, a5: false);
    if ( info->m_nSelfIllumTint >= 0 && (v32 = v7[info->m_nSelfIllumTint], v32->IsDefined(this: v32)) )
    {
      v33 = (float *)v7[info->m_nSelfIllumTint];
      flConsts[0] = v33[3];
      flConsts[1] = v33[4];
      flConsts[2] = v33[5];
    }
    else
    {
      *(_QWORD *)flConsts = 0x3F8000003F800000LL;
      *(_QWORD *)&flConsts[2] = *(_QWORD *)&kDefaultSelfIllumTint[2];
    }
    if ( bSelfIllumFresnel )
    {
      if ( info->m_nSelfIllumFresnelParams >= 0
        && (v34 = v7[info->m_nSelfIllumFresnelParams], v34->IsDefined(this: v34)) )
      {
        v35 = (float *)v7[info->m_nSelfIllumFresnelParams];
        v36 = v35[3];
        flConsts[0] = v36;
        v37 = v35[4];
        flConsts[1] = v37;
        flConsts[2] = v35[5];
      }
      else
      {
        *(_QWORD *)flConsts = 0x3F8000003F800000LL;
        v36 = 1.0;
        *(_QWORD *)&flConsts[2] = *(_QWORD *)&kDefaultSelfIllumTint[2];
        v37 = 1.0;
      }
      if ( v37 == 0.0 )
        v38 = 0.0;
      else
        v38 = v36 / v37;
      v39 = pShaderAPI->SetPixelShaderConstant;
      flConsts[1] = v38;
      flConsts[0] = 1.0 - v38;
      flConsts[3] = v37;
      v39(this: pShaderAPI, a2: 26, a3: flConsts, a4: 1, a5: false);
      if ( info->m_nSelfIllumTint >= 0 && (v40 = v7[info->m_nSelfIllumTint], v40->IsDefined(this: v40)) )
      {
        v41 = (float *)v7[info->m_nSelfIllumTint];
        flConsts[0] = v41[3];
        flConsts[1] = v41[4];
        flConsts[2] = v41[5];
      }
      else
      {
        *(_QWORD *)flConsts = 0x3F8000003F800000LL;
        *(_QWORD *)&flConsts[2] = *(_QWORD *)&kDefaultSelfIllumTint[2];
      }
      pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 27, a3: flConsts, a4: 1, a5: false);
    }
  }
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10005FE0
// Name: void DrawBlob(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct BlobVars_t __near &,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawBlob(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        BlobVars_t *info,
        VertexCompressionType_t vertexCompression)
{
  BlobVars_t *v6; // edi
  int m_nArmature; // eax
  bool v8; // cc
  IMaterialVar *v9; // ecx
  bool v10; // al
  IMaterialVar *v11; // ecx
  bool v12; // al
  IMaterialVar *v13; // ecx
  bool v14; // al
  int m_nInteriorEnable; // eax
  int m_nSelfIllumFresnelEnable; // eax
  int m_nVolumeTex; // eax
  int m_nContactShadows; // eax
  int m_nPulse; // eax
  int v20; // eax
  IShaderShadow_vtbl *v21; // ebx
  int Index; // eax
  BOOL v23; // esi
  int v24; // eax
  void (__thiscall *GetDX9LightState)(IShaderDynamicAPI *, LightState_t *); // edx
  bool v26; // sf
  IMaterialVar **v27; // esi
  IMaterialVar *v28; // ecx
  float x; // xmm0_4
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v31; // ecx
  IMaterialVar *v32; // eax
  IMaterialVar *v33; // ecx
  IMaterialVar *v34; // eax
  IMaterialVar *v35; // ecx
  IMaterialVar *v36; // eax
  IMaterialVar *v37; // ecx
  float m_fValue; // xmm0_4
  bool (__thiscall *GetHDREnabled)(IMaterialSystemHardwareConfig *); // edx
  float v40; // xmm0_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v42)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v43)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
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
  float v88; // xmm1_4
  float v89; // xmm0_4
  float v90; // xmm1_4
  void (__thiscall *v91)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v92; // ecx
  float *v93; // eax
  IMaterialVar *v94; // ecx
  float *v95; // eax
  void (__thiscall *v96)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v97; // ecx
  float v98; // xmm0_4
  int m_nInteriorFogNormalBoost; // eax
  int m_nGlowScale; // edx
  float v101; // xmm0_4
  void (__thiscall *v102)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int m_nNumLights; // edi
  BOOL v104; // esi
  const char *v105; // [esp+18Ch] [ebp-21Ch]
  const char *v106; // [esp+18Ch] [ebp-21Ch]
  float mView[16]; // [esp+19Ch] [ebp-20Ch] BYREF
  FlashlightState_t state; // [esp+1DCh] [ebp-1CCh]
  _BYTE v109[20]; // [esp+2D8h] [ebp-D0h] BYREF
  blob_ps30_Static_Index _pshIndex; // [esp+2ECh] [ebp-BCh] BYREF
  float v111[4]; // [esp+318h] [ebp-90h] BYREF
  float pos[4]; // [esp+328h] [ebp-80h] BYREF
  float tweaks[4]; // [esp+338h] [ebp-70h] BYREF
  float atten[4]; // [esp+348h] [ebp-60h] BYREF
  int nTexHeight; // [esp+358h] [ebp-50h] BYREF
  int nTexWidth; // [esp+35Ch] [ebp-4Ch] BYREF
  int nHeight; // [esp+360h] [ebp-48h] BYREF
  int nWidth; // [esp+364h] [ebp-44h] BYREF
  float vScreenScale[4]; // [esp+368h] [ebp-40h] BYREF
  LightState_t lightState; // [esp+378h] [ebp-30h] BYREF
  float v121; // [esp+380h] [ebp-28h]
  ITexture *pFlashlightDepthTexture; // [esp+384h] [ebp-24h] BYREF
  bool bInteriorLayer; // [esp+38Bh] [ebp-1Dh]
  bool bBackSurface; // [esp+38Ch] [ebp-1Ch]
  bool bLightWarp; // [esp+38Dh] [ebp-1Bh]
  bool bOpacityTexture; // [esp+38Eh] [ebp-1Ah]
  bool bVolumeTex; // [esp+38Fh] [ebp-19h]
  bool bContactShadows; // [esp+390h] [ebp-18h]
  bool bSelfIllumFresnel; // [esp+391h] [ebp-17h]
  bool bFresnelWarp; // [esp+392h] [ebp-16h]
  bool bHasFlashlight; // [esp+393h] [ebp-15h]
  float flConsts[4]; // [esp+394h] [ebp-14h] BYREF
  bool bFlashlightShadows; // [esp+3A7h] [ebp-1h]

  v6 = info;
  m_nArmature = info->m_nArmature;
  if ( m_nArmature == -1 || params[m_nArmature]->m_intVal <= 0 )
  {
    bHasFlashlight = CBaseShader::UsingFlashlight(this: pShader, params);
    if ( info->m_nBackSurface == -1 || (v8 = params[info->m_nBackSurface]->m_intVal <= 0, bBackSurface = true, v8) )
      bBackSurface = false;
    if ( info->m_nLightWarpTexture == -1
      || (v9 = params[info->m_nLightWarpTexture], v10 = v9->IsDefined(this: v9), bLightWarp = true, !v10) )
    {
      bLightWarp = false;
    }
    if ( info->m_nFresnelWarpTexture == -1
      || (v11 = params[info->m_nFresnelWarpTexture], v12 = v11->IsDefined(this: v11), bFresnelWarp = true, !v12) )
    {
      bFresnelWarp = false;
    }
    if ( info->m_nOpacityTexture == -1
      || (v13 = params[info->m_nOpacityTexture], v14 = v13->IsDefined(this: v13), bOpacityTexture = true, !v14) )
    {
      bOpacityTexture = false;
    }
    m_nInteriorEnable = info->m_nInteriorEnable;
    if ( m_nInteriorEnable == -1 || (v8 = params[m_nInteriorEnable]->m_intVal <= 0, bInteriorLayer = true, v8) )
      bInteriorLayer = false;
    m_nSelfIllumFresnelEnable = info->m_nSelfIllumFresnelEnable;
    if ( m_nSelfIllumFresnelEnable == -1
      || (v8 = params[m_nSelfIllumFresnelEnable]->m_intVal <= 0, bSelfIllumFresnel = true, v8) )
    {
      bSelfIllumFresnel = false;
    }
    m_nVolumeTex = info->m_nVolumeTex;
    if ( m_nVolumeTex == -1 || (v8 = params[m_nVolumeTex]->m_intVal <= 0, bVolumeTex = true, v8) )
      bVolumeTex = false;
    m_nContactShadows = info->m_nContactShadows;
    if ( m_nContactShadows == -1 || (v8 = params[m_nContactShadows]->m_intVal <= 0, bContactShadows = true, v8) )
      bContactShadows = false;
    m_nPulse = info->m_nPulse;
    if ( m_nPulse == -1 || (v8 = params[m_nPulse]->m_intVal <= 0, bFlashlightShadows = true, v8) )
      bFlashlightShadows = false;
    if ( pShaderShadow != nullptr )
    {
      LODWORD(flConsts[0]) = 4;
      LODWORD(flConsts[1]) = 4;
      LODWORD(flConsts[2]) = 4;
      LODWORD(flConsts[3]) = 4;
      pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 3u, a3: 1, a4: (int *)flConsts, a5: 0);
      pFlashlightDepthTexture = nullptr;
      if ( bHasFlashlight )
        pFlashlightDepthTexture = (ITexture *)g_pHardwareConfig->GetShadowFilterMode(
                                                this: g_pHardwareConfig,
                                                a2: false,
                                                a3: true);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "CONTACT_SHADOW", bContactShadows, "bContactShadows");
      LODWORD(v121) = bVolumeTex;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VOLUME_TEXTURE", bVolumeTex, "bVolumeTex");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "blob_vs30",
        a3: 4 * (bContactShadows + 2 * LODWORD(v121)));
      _pshIndex.m_nBACK_SURFACE = bBackSurface;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BACK_SURFACE", bBackSurface, "bBackSurface");
      _pshIndex.m_nLIGHT_WARP = bLightWarp;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "LIGHT_WARP", bLightWarp, "bLightWarp");
      _pshIndex.m_nFRESNEL_WARP = bFresnelWarp;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FRESNEL_WARP", bFresnelWarp, "bFresnelWarp");
      _pshIndex.m_nOPACITY_TEXTURE = bOpacityTexture;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "OPACITY_TEXTURE", bOpacityTexture, "bOpacityTexture");
      _pshIndex.m_nINTERIOR_LAYER = bInteriorLayer;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "INTERIOR_LAYER", bInteriorLayer, "bInteriorLayer");
      _pshIndex.m_nHIGH_PRECISION_DEPTH = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_FLOAT;
      if ( g_shaderConfigDumpEnable )
      {
        v20 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
                a1: g_pHardwareConfig,
                a2: "(g_pHardwareConfig->GetHDRType() == HDR_TYPE_FLOAT) ? true : false");
        printf(format: "\n   PS stat var %s = %d (%s)", "HIGH_PRECISION_DEPTH", v20 == 2, v105);
      }
      _pshIndex.m_nSELF_ILLUM_FRESNEL = bSelfIllumFresnel;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SELF_ILLUM_FRESNEL", bSelfIllumFresnel, "bSelfIllumFresnel");
      _pshIndex.m_nFLASHLIGHTDEPTHFILTERMODE = (int)pFlashlightDepthTexture;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FLASHLIGHTDEPTHFILTERMODE",
          pFlashlightDepthTexture,
          "nShadowFilterMode");
      _pshIndex.m_nCONTACT_SHADOW = bContactShadows;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "CONTACT_SHADOW", bContactShadows, "bContactShadows");
      _pshIndex.m_nSELF_ILLUM_PULSE = bFlashlightShadows;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SELF_ILLUM_PULSE", bFlashlightShadows, "bPulse");
      *(float *)&_pshIndex.m_nVOLUME_TEXTURE = v121;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "VOLUME_TEXTURE", bVolumeTex, "bVolumeTex");
      v21 = pShaderShadow->__vftable;
      Index = blob_ps30_Static_Index::GetIndex(this: &_pshIndex);
      v21->SetPixelShader(this: pShaderShadow, a2: "blob_ps30", a3: Index);
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
      if ( bHasFlashlight )
      {
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: true);
        pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER7, a3: false);
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER8, a3: true);
        pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER8, a3: false);
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER9, a3: true);
        pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER9, a3: true);
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
      v23 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v24 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v24 > 0, v106);
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
      }
      pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * v23);
      GetDX9LightState = pShaderAPI->GetDX9LightState;
      lightState.m_nNumLights = 0;
      *(_WORD *)&lightState.m_bAmbientLight = 0;
      GetDX9LightState(this: pShaderAPI, a2: &lightState);
      v26 = info->m_nUVScale < 0;
      v27 = params;
      memset(flConsts, 0, sizeof(flConsts));
      if ( v26 || (v28 = params[info->m_nUVScale], !v28->IsDefined(this: v28)) )
        x = 0.02;
      else
        x = params[info->m_nUVScale]->m_VecVal.x;
      SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
      flConsts[0] = x;
      SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: flConsts, a4: 1, a5: false);
      if ( info->m_nUVProjOffset >= 0 && (v31 = params[info->m_nUVProjOffset], v31->IsDefined(this: v31)) )
      {
        v32 = params[info->m_nUVProjOffset];
        flConsts[0] = v32->m_VecVal.x;
        flConsts[1] = v32->m_VecVal.y;
        flConsts[2] = v32->m_VecVal.z;
      }
      else
      {
        memset(flConsts, 0, 12);
      }
      pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 49, a3: flConsts, a4: 1, a5: false);
      if ( info->m_nBBMin >= 0 && (v33 = params[info->m_nBBMin], v33->IsDefined(this: v33)) )
      {
        v34 = params[info->m_nBBMin];
        flConsts[0] = v34->m_VecVal.x;
        flConsts[1] = v34->m_VecVal.y;
        flConsts[2] = v34->m_VecVal.z;
      }
      else
      {
        memset(flConsts, 0, 12);
      }
      pShaderAPI->SetVertexShaderConstant(this: pShaderAPI, a2: 50, a3: flConsts, a4: 1, a5: false);
      if ( info->m_nBBMax >= 0 && (v35 = params[info->m_nBBMax], v35->IsDefined(this: v35)) )
      {
        v36 = params[info->m_nBBMax];
        flConsts[0] = v36->m_VecVal.x;
        flConsts[1] = v36->m_VecVal.y;
        flConsts[2] = v36->m_VecVal.z;
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
      if ( info->m_nSpecMap == -1 || (v37 = params[info->m_nSpecMap], !v37->IsDefined(this: v37)) )
        pShaderAPI->BindStandardTexture(
          this: pShaderAPI,
          a2: SHADER_SAMPLER3,
          a3: TEXTURE_BINDFLAGS_NONE,
          a4: TEXTURE_WHITE);
      else
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER3,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: info->m_nSpecMap,
          nFrameVar: -1);
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
      bFlashlightShadows = false;
      if ( bHasFlashlight )
      {
        CBaseShader::BindTexture(
          this: pShader,
          sampler1: SHADER_SAMPLER9,
          nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
          nTextureVar: info->m_nFlashlightTexture,
          nFrameVar: info->m_nFlashlightTextureFrame);
        state = *pShaderAPI->GetFlashlightStateEx(this: pShaderAPI, a2: v109, a3: &pFlashlightDepthTexture);
        m_fValue = r_flashlightbrightness.m_pParent->m_Value.m_fValue;
        bFlashlightShadows = state.m_bEnableShadows;
        GetHDREnabled = g_pHardwareConfig->GetHDREnabled;
        v121 = m_fValue;
        if ( !GetHDREnabled(this: g_pHardwareConfig) )
          v121 = 2.0;
        g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
        v40 = (float)(v121 * 2.5) * state.m_fBrightnessScale;
        SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
        v111[0] = v40 * state.m_Color[0];
        v111[2] = v40 * state.m_Color[2];
        v111[1] = v40 * state.m_Color[1];
        v111[3] = 0.0;
        SetPixelShaderConstant(this: pShaderAPI, a2: 28, a3: v111, a4: 1, a5: false);
        if ( pFlashlightDepthTexture != nullptr && g_pConfig->m_bShadowDepthTexture && state.m_bEnableShadows )
        {
          CBaseShader::BindTexture(
            this: pShader,
            sampler1: SHADER_SAMPLER7,
            nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
            pTexture: pFlashlightDepthTexture,
            nFrame: 0);
          pShaderAPI->BindStandardTexture(
            this: pShaderAPI,
            a2: SHADER_SAMPLER8,
            a3: TEXTURE_BINDFLAGS_NONE,
            a4: TEXTURE_SHADOW_NOISE_2D);
        }
        v42 = pShaderAPI->SetPixelShaderConstant;
        atten[0] = state.m_fConstantAtten;
        atten[1] = state.m_fLinearAtten;
        atten[2] = state.m_fQuadraticAtten;
        atten[3] = state.m_FarZAtten;
        v42(this: pShaderAPI, a2: 13, a3: atten, a4: 1, a5: false);
        v43 = pShaderAPI->SetPixelShaderConstant;
        *(Vector *)pos = state.m_vecLightOrigin;
        pos[3] = state.m_FarZ;
        v43(this: pShaderAPI, a2: 14, a3: pos, a4: 1, a5: false);
        pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 15, a3: (const float *)v109, a4: 4, a5: false);
        tweaks[0] = state.m_flShadowFilterSize * 0.0009765625;
        m_flShadowAtten = state.m_flShadowAtten;
        if ( g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig) )
          m_flShadowAtten = state.m_flShadowAtten * 0.1;
        tweaks[1] = m_flShadowAtten;
        CBaseVSShader::HashShadow2DJitter(
          this: pShader,
          fJitterSeed: state.m_flShadowJitterSeed,
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
        v46 = pShaderAPI->SetPixelShaderConstant;
        vScreenScale[0] = (float)nWidth / (float)nTexWidth;
        vScreenScale[1] = (float)nHeight / (float)nTexHeight;
        v46(this: pShaderAPI, a2: 31, a3: vScreenScale, a4: 1, a5: false);
        v6 = info;
        v27 = params;
      }
      if ( v6->m_nBumpStrength >= 0 && (v47 = v27[v6->m_nBumpStrength], v47->IsDefined(this: v47)) )
        v48 = v27[v6->m_nBumpStrength]->m_VecVal.x;
      else
        v48 = 1.0;
      flConsts[0] = v48;
      if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_FLOAT )
        v49 = 8192.0;
      else
        v49 = 192.0;
      v26 = v6->m_nInteriorFogStrength < 0;
      flConsts[1] = v49;
      if ( v26 || (v50 = v27[v6->m_nInteriorFogStrength], !v50->IsDefined(this: v50)) )
        v51 = 0.059999999;
      else
        v51 = v27[v6->m_nInteriorFogStrength]->m_VecVal.x;
      v26 = v6->m_nInteriorRefractStrength < 0;
      flConsts[2] = v51;
      if ( v26 || (v52 = v27[v6->m_nInteriorRefractStrength], !v52->IsDefined(this: v52)) )
        v53 = 0.015;
      else
        v53 = v27[v6->m_nInteriorRefractStrength]->m_VecVal.x;
      v54 = pShaderAPI->SetPixelShaderConstant;
      flConsts[3] = v53;
      v54(this: pShaderAPI, a2: 0, a3: flConsts, a4: 1, a5: false);
      if ( v6->m_nFresnelParams >= 0 && (v55 = v27[v6->m_nFresnelParams], v55->IsDefined(this: v55)) )
      {
        v56 = (float *)v27[v6->m_nFresnelParams];
        flConsts[0] = v56[3];
        flConsts[1] = v56[4];
        flConsts[2] = v56[5];
      }
      else
      {
        *(_QWORD *)flConsts = *(_QWORD *)kDefaultFresnelParams;
        flConsts[2] = 2.0;
      }
      v57 = pShaderAPI->SetPixelShaderConstant;
      flConsts[3] = v27[v6->m_nInteriorBackgroundBoost]->m_VecVal.x;
      v57(this: pShaderAPI, a2: 1, a3: flConsts, a4: 1, a5: false);
      if ( v6->m_nRimLightExp >= 0 && (v58 = v27[v6->m_nRimLightExp], v58->IsDefined(this: v58)) )
        v59 = v27[v6->m_nRimLightExp]->m_VecVal.x;
      else
        v59 = 10.0;
      v26 = v6->m_nRimLightScale < 0;
      flConsts[0] = v59;
      if ( v26 || (v60 = v27[v6->m_nRimLightScale], !v60->IsDefined(this: v60)) )
        v61 = 1.0;
      else
        v61 = v27[v6->m_nRimLightScale]->m_VecVal.x;
      v26 = v6->m_nSpecScale < 0;
      flConsts[1] = v61;
      if ( v26 || (v62 = v27[v6->m_nSpecScale], !v62->IsDefined(this: v62)) )
        v63 = 1.0;
      else
        v63 = v27[v6->m_nSpecScale]->m_VecVal.x;
      v26 = v6->m_nSpecExp2 < 0;
      flConsts[2] = v63;
      if ( v26 || (v64 = v27[v6->m_nSpecExp2], !v64->IsDefined(this: v64)) )
        v65 = 1.0;
      else
        v65 = v27[v6->m_nSpecExp2]->m_VecVal.x;
      v66 = pShaderAPI->SetPixelShaderConstant;
      flConsts[3] = v65;
      v66(this: pShaderAPI, a2: 3, a3: flConsts, a4: 1, a5: false);
      if ( v6->m_nSpecScale2 >= 0 && (v67 = v27[v6->m_nSpecScale2], v67->IsDefined(this: v67)) )
        v68 = v27[v6->m_nSpecScale2]->m_VecVal.x;
      else
        v68 = 1.0;
      v26 = v6->m_nFresnelBumpStrength < 0;
      flConsts[0] = v68;
      if ( v26 || (v69 = v27[v6->m_nFresnelBumpStrength], !v69->IsDefined(this: v69)) )
        v70 = 1.0;
      else
        v70 = v27[v6->m_nFresnelBumpStrength]->m_VecVal.x;
      v26 = v6->m_nDiffuseScale < 0;
      flConsts[1] = v70;
      if ( v26 || (v71 = v27[v6->m_nDiffuseScale], !v71->IsDefined(this: v71)) )
        v72 = 1.0;
      else
        v72 = v27[v6->m_nDiffuseScale]->m_VecVal.x;
      v26 = v6->m_nInteriorAmbientScale < 0;
      flConsts[2] = v72;
      if ( v26 || (v73 = v27[v6->m_nInteriorAmbientScale], !v73->IsDefined(this: v73)) )
        v74 = 0.30000001;
      else
        v74 = v27[v6->m_nInteriorAmbientScale]->m_VecVal.x;
      v75 = pShaderAPI->SetPixelShaderConstant;
      flConsts[3] = v74;
      v75(this: pShaderAPI, a2: 10, a3: flConsts, a4: 1, a5: false);
      pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: flConsts);
      if ( v6->m_nSpecExp >= 0 && (v76 = v27[v6->m_nSpecExp], v76->IsDefined(this: v76)) )
        v77 = v27[v6->m_nSpecExp]->m_VecVal.x;
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
      if ( v6->m_nBaseColorTint >= 0 && (v81 = v27[v6->m_nBaseColorTint], v81->IsDefined(this: v81)) )
      {
        v82 = (float *)v27[v6->m_nBaseColorTint];
        flConsts[0] = v82[3];
        flConsts[1] = v82[4];
        flConsts[2] = v82[5];
      }
      else
      {
        *(_QWORD *)flConsts = *(_QWORD *)kDefaultBaseColorTint;
        flConsts[2] = 1.0;
      }
      if ( v6->m_nInteriorBackLightScale >= 0 && (v83 = v27[v6->m_nInteriorBackLightScale], v83->IsDefined(this: v83)) )
        v84 = v27[v6->m_nInteriorBackLightScale]->m_VecVal.x;
      else
        v84 = 0.30000001;
      v85 = pShaderAPI->SetPixelShaderConstant;
      flConsts[3] = v84;
      v85(this: pShaderAPI, a2: 19, a3: flConsts, a4: 1, a5: false);
      if ( bSelfIllumFresnel )
      {
        if ( v6->m_nSelfIllumFresnelParams >= 0 && (v86 = v27[v6->m_nSelfIllumFresnelParams], v86->IsDefined(this: v86)) )
        {
          v87 = (float *)v27[v6->m_nSelfIllumFresnelParams];
          v88 = v87[3];
          flConsts[0] = v88;
          v89 = v87[4];
          flConsts[1] = v89;
          flConsts[2] = v87[5];
        }
        else
        {
          *(_QWORD *)flConsts = 0x3F80000000000000LL;
          v89 = 1.0;
          v88 = 0.0;
          flConsts[2] = 1.0;
        }
        if ( v89 == 0.0 )
          v90 = 0.0;
        else
          v90 = v88 / v89;
        v91 = pShaderAPI->SetPixelShaderConstant;
        flConsts[1] = v90;
        flConsts[0] = 1.0 - v90;
        flConsts[3] = v89;
        v91(this: pShaderAPI, a2: 26, a3: flConsts, a4: 1, a5: false);
        if ( v6->m_nSelfIllumTint >= 0 && (v92 = v27[v6->m_nSelfIllumTint], v92->IsDefined(this: v92)) )
        {
          v93 = (float *)v27[v6->m_nSelfIllumTint];
          flConsts[0] = v93[3];
          flConsts[1] = v93[4];
          flConsts[2] = v93[5];
        }
        else
        {
          *(_QWORD *)flConsts = *(_QWORD *)kDefaultSelfIllumTint;
          flConsts[2] = 1.0;
        }
        pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 27, a3: flConsts, a4: 1, a5: false);
      }
      if ( v6->m_nInteriorColor >= 0 && (v94 = v27[v6->m_nInteriorColor], v94->IsDefined(this: v94)) )
      {
        v95 = (float *)v27[v6->m_nInteriorColor];
        flConsts[0] = v95[3];
        flConsts[1] = v95[4];
        flConsts[2] = v95[5];
      }
      else
      {
        *(_QWORD *)flConsts = *(_QWORD *)kDefaultInteriorColor;
        flConsts[2] = 0.5;
      }
      v96 = pShaderAPI->SetPixelShaderConstant;
      flConsts[3] = v27[v6->m_nInteriorRefractBlur]->m_VecVal.x;
      v96(this: pShaderAPI, a2: 32, a3: flConsts, a4: 1, a5: false);
      pShaderAPI->GetMatrix(this: pShaderAPI, a2: MATERIAL_VIEW, a3: mView);
      pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 33, a3: mView, a4: 3, a5: false);
      if ( v6->m_nInteriorFogLimit >= 0 && (v97 = v27[v6->m_nInteriorFogLimit], v97->IsDefined(this: v97)) )
        v98 = v27[v6->m_nInteriorFogLimit]->m_VecVal.x;
      else
        v98 = 0.80000001;
      m_nInteriorFogNormalBoost = v6->m_nInteriorFogNormalBoost;
      m_nGlowScale = v6->m_nGlowScale;
      flConsts[0] = 1.0 - v98;
      flConsts[1] = v27[m_nInteriorFogNormalBoost]->m_VecVal.x;
      v101 = v27[m_nGlowScale]->m_VecVal.x;
      v102 = pShaderAPI->SetPixelShaderConstant;
      flConsts[2] = v101;
      v102(this: pShaderAPI, a2: 36, a3: flConsts, a4: 1, a5: false);
      m_nNumLights = lightState.m_nNumLights;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          lightState.m_nNumLights,
          "lightState.m_nNumLights");
      LODWORD(vScreenScale[2]) = bHasFlashlight;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHT", bHasFlashlight, "bHasFlashlight");
      v104 = bFlashlightShadows;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", bFlashlightShadows, "bFlashlightShadows");
      pShaderAPI->SetPixelShaderIndex(
        this: pShaderAPI,
        a2: LODWORD(vScreenScale[2]) + 2 * v104 + m_nNumLights + 4 * (LODWORD(vScreenScale[2]) + 2 * v104));
    }
    CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
  }
  else
  {
    DrawArmature(pShader, params, pShaderAPI, pShaderShadow, info, vertexCompression, nPassIdx: 0);
    DrawArmature(pShader, params, pShaderAPI, pShaderShadow, info, vertexCompression, nPassIdx: 1);
  }
}
