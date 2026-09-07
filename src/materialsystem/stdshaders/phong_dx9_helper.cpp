// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/phong_dx9_helper.cpp
// Functions: 11
// ============================================================

#include "materialsystem\stdshaders\phong_dx9_helper.h"

//------------------------------------------------------------------------------
// Address: 0x10022940
// Name: void ClampDetailBlendModeAndWarn(int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClampDetailBlendModeAndWarn(int *nDetailBlendMode, int nMin, int nMax)
{
  if ( *nDetailBlendMode < nMin || *nDetailBlendMode > nMax )
  {
    _Warning(a1: "========================================================================\n");
    _Warning(a1: "========================================================================\n");
    _Warning(a1: "========================================================================\n");
    _Warning(
      a1: "Material uses an out of range $detailblendmode of %d. Should be in [%d,%d].\n"
      "Give a programmer a repro case, or look at your modified vmt files\n",
      *nDetailBlendMode,
      nMin,
      nMax);
    _Warning(a1: "========================================================================\n");
    _Warning(a1: "========================================================================\n");
    _Warning(a1: "========================================================================\n");
    *nDetailBlendMode = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100229B0
// Name: public: phong_vs20_Static_Index::phong_vs20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
phong_vs20_Static_Index *__thiscall phong_vs20_Static_Index::phong_vs20_Static_Index(
        phong_vs20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  BOOL v4; // eax
  BOOL v5; // ecx

  this->m_nWORLD_NORMAL = 0;
  this->m_nFLATTEN_STATIC_CONTROL_FLOW = 0;
  v4 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 && (*params)->m_intVal >= 0;
  this->m_nDOPIXELFOG = v4;
  v5 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  this->m_nHARDWAREFOGBLEND = v5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10022A10
// Name: public: int phong_ps20b_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall phong_ps20b_Static_Index::GetIndex(phong_ps20b_Static_Index *this)
{
  return 80
       * (this->m_nCUBEMAP
        + 2
        * (this->m_nSELFILLUM
         + 2
         * (this->m_nSELFILLUMFRESNEL
          + 2
          * (this->m_nFLASHLIGHT
           + 2
           * (this->m_nLIGHTWARPTEXTURE
            + 2
            * (this->m_nPHONGWARPTEXTURE
             + 2
             * (this->m_nWRINKLEMAP
              + 2
              * (this->m_nDETAIL_BLEND_MODE
               + 8
               * (this->m_nDETAILTEXTURE
                + 2
                * (this->m_nRIMLIGHT
                 + 2
                 * (this->m_nFLASHLIGHTDEPTHFILTERMODE
                  + 4 * (this->m_nSHADER_SRGB_READ + this->m_nWORLD_NORMAL + this->m_nPHONG_HALFLAMBERT))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10022A70
// Name: public: phong_vs30_Static_Index::phong_vs30_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
phong_vs30_Static_Index *__thiscall phong_vs30_Static_Index::phong_vs30_Static_Index(
        phong_vs30_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nDECAL = 0;
  this->m_nWORLD_NORMAL = 0;
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 || (*params)->m_intVal < 0 )
  {
    this->m_nDOPIXELFOG = 0;
    this->m_nHARDWAREFOGBLEND = 0;
    return this;
  }
  else
  {
    this->m_nDOPIXELFOG = 1;
    this->m_nHARDWAREFOGBLEND = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022B20
// Name: public: int phong_ps30_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall phong_ps30_Static_Index::GetIndex(phong_ps30_Static_Index *this)
{
  return 160
       * (this->m_nCUBEMAP
        + 2
        * (this->m_nSELFILLUM
         + 2
         * (this->m_nSELFILLUMFRESNEL
          + 2
          * (this->m_nFLASHLIGHT
           + 2
           * (this->m_nLIGHTWARPTEXTURE
            + 2
            * (this->m_nPHONGWARPTEXTURE
             + 2
             * (this->m_nWRINKLEMAP
              + 2
              * (this->m_nDETAIL_BLEND_MODE
               + 8
               * (this->m_nDETAILTEXTURE
                + 2
                * (this->m_nRIMLIGHT
                 + 2
                 * (this->m_nFLASHLIGHTDEPTHFILTERMODE
                  + 3 * (this->m_nSHADER_SRGB_READ + this->m_nWORLD_NORMAL + 2 * this->m_nPHONG_HALFLAMBERT))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10022B80
// Name: public: phong_ps30_Dynamic_Index::phong_ps30_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
phong_ps30_Dynamic_Index *__thiscall phong_ps30_Dynamic_Index::phong_ps30_Dynamic_Index(
        phong_ps30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nWRITEWATERFOGTODESTALPHA = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nNUM_LIGHTS = 0;
  this->m_nWRITE_DEPTH_TO_DESTALPHA = 0;
  this->m_nFLASHLIGHTSHADOWS = 0;
  this->m_nUBERLIGHT = 0;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10022BC0
// Name: void InitParamsPhong_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,struct VertexLitGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsPhong_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        VertexLitGeneric_DX9_Vars_t *info)
{
  IMaterialVar *v6; // ecx
  IMaterialVar *v7; // ecx
  IMaterialVar *v8; // ecx
  IMaterialVar_vtbl *v9; // ebx
  int v10; // eax
  IMaterialVar *v11; // ecx
  IMaterialVar *v12; // ecx
  IMaterialVar *v13; // ecx
  bool v14; // bl
  IMaterialVar *v15; // ecx
  bool v16; // al
  IMaterialVar *v17; // ecx
  IMaterialVar *v18; // ecx
  int m_nEnvmapFresnel; // ebx
  int m_nAmbientOcclusion; // ebx
  int m_nDisplacementWrinkleMap; // ebx
  int m_nSelfIllumFresnel; // ebx
  int m_nBaseMapAlphaPhongMask; // ebx
  int m_nBaseMapLuminancePhongMask; // ebx
  int m_nShaderSrgbRead360; // ebx
  int m_nAllowDiffuseModulation; // ebx
  int m_nPhongDisableHalfLambert; // edi
  char bBump_3; // [esp+53h] [ebp+Fh]
  char bEnvMap_3; // [esp+5Bh] [ebp+17h]

  params[9]->SetStringValue(this: params[9], a2: "effects/flashlight001");
  if ( info->m_nAlbedo != -1 && (g_pConfig->m_Flags & 0x100) == 0 && info->m_nBumpmap != -1 )
  {
    v6 = params[info->m_nBumpmap];
    if ( v6->IsDefined(this: v6) )
    {
      v7 = params[info->m_nAlbedo];
      if ( v7->IsDefined(this: v7) && params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
      {
        v8 = params[info->m_nAlbedo];
        v9 = params[info->m_nBaseTexture]->__vftable;
        v10 = (int)v8->GetStringValue(this: v8);
        v9->SetStringValue(this: params[info->m_nBaseTexture], a2: (const char *)v10);
      }
    }
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  if ( !params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
  if ( ((*params)->m_intVal & 0x10000) != 0 )
    (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal | 2);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  if ( info->m_nBumpmap == -1
    || (g_pConfig->m_Flags & 0x100) != 0
    || (v11 = params[info->m_nBumpmap], bBump_3 = 1, !v11->IsDefined(this: v11)) )
  {
    bBump_3 = 0;
  }
  if ( info->m_nEnvmap == -1 || (v12 = params[info->m_nEnvmap], bEnvMap_3 = 1, !v12->IsDefined(this: v12)) )
    bEnvMap_3 = 0;
  v14 = false;
  if ( info->m_nDiffuseWarpTexture != -1 )
  {
    v13 = params[info->m_nDiffuseWarpTexture];
    if ( v13->IsDefined(this: v13) )
      v14 = true;
  }
  v16 = false;
  if ( info->m_nPhong != -1 )
  {
    v15 = params[info->m_nPhong];
    if ( v15->IsDefined(this: v15) )
      v16 = true;
  }
  if ( bBump_3 == 0 && bEnvMap_3 == 0 && !v14 && !v16 )
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFBFFFFF);
  if ( info->m_nSelfIllumFresnelMinMaxExp != -1 )
  {
    v17 = params[info->m_nSelfIllumFresnelMinMaxExp];
    if ( !v17->IsDefined(this: v17) )
    {
      v18 = params[info->m_nSelfIllumFresnelMinMaxExp];
      ((void (__thiscall *)(IMaterialVar *, _DWORD, int, int))v18->SetVecValue_2)(
        a1: v18,
        a2: 0,
        a3: 1065353216,
        a4: 1065353216);
    }
  }
  m_nEnvmapFresnel = info->m_nEnvmapFresnel;
  if ( m_nEnvmapFresnel != -1 && !params[m_nEnvmapFresnel]->IsDefined(this: params[m_nEnvmapFresnel]) )
    ((void (__stdcall *)(_DWORD))params[m_nEnvmapFresnel]->SetFloatValue)(a1: 0);
  m_nAmbientOcclusion = info->m_nAmbientOcclusion;
  if ( m_nAmbientOcclusion != -1 && !params[m_nAmbientOcclusion]->IsDefined(this: params[m_nAmbientOcclusion]) )
    ((void (__stdcall *)(_DWORD))params[m_nAmbientOcclusion]->SetFloatValue)(a1: 0);
  m_nDisplacementWrinkleMap = info->m_nDisplacementWrinkleMap;
  if ( m_nDisplacementWrinkleMap != -1
    && !params[m_nDisplacementWrinkleMap]->IsDefined(this: params[m_nDisplacementWrinkleMap]) )
  {
    ((void (__stdcall *)(_DWORD))params[m_nDisplacementWrinkleMap]->SetFloatValue)(a1: 0);
  }
  m_nSelfIllumFresnel = info->m_nSelfIllumFresnel;
  if ( m_nSelfIllumFresnel != -1 && !params[m_nSelfIllumFresnel]->IsDefined(this: params[m_nSelfIllumFresnel]) )
    params[m_nSelfIllumFresnel]->SetIntValue(this: params[m_nSelfIllumFresnel], a2: 0);
  m_nBaseMapAlphaPhongMask = info->m_nBaseMapAlphaPhongMask;
  if ( m_nBaseMapAlphaPhongMask != -1
    && !params[m_nBaseMapAlphaPhongMask]->IsDefined(this: params[m_nBaseMapAlphaPhongMask]) )
  {
    params[m_nBaseMapAlphaPhongMask]->SetIntValue(this: params[m_nBaseMapAlphaPhongMask], a2: 0);
  }
  m_nBaseMapLuminancePhongMask = info->m_nBaseMapLuminancePhongMask;
  if ( m_nBaseMapLuminancePhongMask != -1
    && !params[m_nBaseMapLuminancePhongMask]->IsDefined(this: params[m_nBaseMapLuminancePhongMask]) )
  {
    params[m_nBaseMapLuminancePhongMask]->SetIntValue(this: params[m_nBaseMapLuminancePhongMask], a2: 0);
  }
  m_nShaderSrgbRead360 = info->m_nShaderSrgbRead360;
  if ( m_nShaderSrgbRead360 != -1 && !params[m_nShaderSrgbRead360]->IsDefined(this: params[m_nShaderSrgbRead360]) )
    params[m_nShaderSrgbRead360]->SetIntValue(this: params[m_nShaderSrgbRead360], a2: 0);
  m_nAllowDiffuseModulation = info->m_nAllowDiffuseModulation;
  if ( m_nAllowDiffuseModulation != -1
    && !params[m_nAllowDiffuseModulation]->IsDefined(this: params[m_nAllowDiffuseModulation]) )
  {
    params[m_nAllowDiffuseModulation]->SetIntValue(this: params[m_nAllowDiffuseModulation], a2: 1);
  }
  m_nPhongDisableHalfLambert = info->m_nPhongDisableHalfLambert;
  if ( m_nPhongDisableHalfLambert != -1
    && !params[m_nPhongDisableHalfLambert]->IsDefined(this: params[m_nPhongDisableHalfLambert]) )
  {
    params[m_nPhongDisableHalfLambert]->SetIntValue(this: params[m_nPhongDisableHalfLambert], a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022F30
// Name: void InitPhong_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,struct VertexLitGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPhong_DX9(CBaseVSShader *pShader, IMaterialVar **params, VertexLitGeneric_DX9_Vars_t *info)
{
  int v4; // eax
  IMaterialVar *v5; // ecx
  IMaterialVar *v6; // ecx
  int m_nSelfIllumFresnel; // eax
  IMaterialVar *v8; // ecx
  IMaterialVar *v9; // ecx
  CBaseVSShader *v10; // ebx
  IMaterialVar *v11; // ecx
  IMaterialVar *v12; // ecx
  IMaterialVar *v13; // ecx
  IMaterialVar *v14; // ecx
  IMaterialVar *v15; // ecx
  int m_nDetailTextureCombineMode; // eax
  int m_intVal; // eax
  bool v18; // al
  IMaterialVar *v19; // ecx
  IMaterialVar *v20; // ecx
  IMaterialVar *v21; // ecx
  IMaterialVar *v22; // ecx
  HDRType_t v23; // eax
  IMaterialVar *v24; // ecx
  bool bIsBaseTextureTranslucent; // [esp+Fh] [ebp-1h]
  char bHasSelfIllumMask_3; // [esp+23h] [ebp+13h]

  CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nFlashlightTexture, nAdditionalCreationFlags: 0x80000);
  bIsBaseTextureTranslucent = false;
  if ( params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
  {
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: 0x80000);
    v4 = params[info->m_nBaseTexture]->GetTextureValue(this: params[info->m_nBaseTexture]);
    bIsBaseTextureTranslucent = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 24))(a1: v4) != 0;
    if ( info->m_nWrinkle != -1 && info->m_nStretch != -1 )
    {
      v5 = params[info->m_nWrinkle];
      if ( v5->IsDefined(this: v5) )
      {
        v6 = params[info->m_nStretch];
        if ( v6->IsDefined(this: v6) )
        {
          CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nWrinkle, nAdditionalCreationFlags: 0x80000);
          CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nStretch, nAdditionalCreationFlags: 0x80000);
        }
      }
    }
  }
  if ( ((*params)->m_intVal & 0x40) == 0 || (bHasSelfIllumMask_3 = 1, (params[2]->m_intVal & 0x400000) == 0) )
    bHasSelfIllumMask_3 = 0;
  if ( !bIsBaseTextureTranslucent )
  {
    if ( (((*params)->m_intVal & 0x40) == 0
       || (m_nSelfIllumFresnel = info->m_nSelfIllumFresnel) == -1
       || params[m_nSelfIllumFresnel]->m_intVal == 0)
      && bHasSelfIllumMask_3 == 0 )
    {
      (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal & 0xFFFFFFBF);
    }
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
  }
  if ( info->m_nPhongExponentTexture == -1
    || (v8 = params[info->m_nPhongExponentTexture], !v8->IsDefined(this: v8))
    || info->m_nPhong == -1
    || (v9 = params[info->m_nPhong], !v9->IsDefined(this: v9)) )
  {
    v10 = pShader;
  }
  else
  {
    v10 = pShader;
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nPhongExponentTexture, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nDiffuseWarpTexture != -1 )
  {
    v11 = params[info->m_nDiffuseWarpTexture];
    if ( v11->IsDefined(this: v11) && info->m_nPhong != -1 )
    {
      v12 = params[info->m_nPhong];
      if ( v12->IsDefined(this: v12) )
        CBaseShader::LoadTexture(this: v10, nTextureVar: info->m_nDiffuseWarpTexture, nAdditionalCreationFlags: 0);
    }
  }
  if ( info->m_nPhongWarpTexture != -1 )
  {
    v13 = params[info->m_nPhongWarpTexture];
    if ( v13->IsDefined(this: v13) && info->m_nPhong != -1 )
    {
      v14 = params[info->m_nPhong];
      if ( v14->IsDefined(this: v14) )
        CBaseShader::LoadTexture(this: v10, nTextureVar: info->m_nPhongWarpTexture, nAdditionalCreationFlags: 0);
    }
  }
  if ( info->m_nDetail != -1 )
  {
    v15 = params[info->m_nDetail];
    if ( v15->IsDefined(this: v15) )
    {
      m_nDetailTextureCombineMode = info->m_nDetailTextureCombineMode;
      v18 = false;
      if ( m_nDetailTextureCombineMode != -1 )
      {
        m_intVal = params[m_nDetailTextureCombineMode]->m_intVal;
        if ( m_intVal == 2 || m_intVal == 3 || m_intVal == 4 )
          v18 = true;
      }
      CBaseShader::LoadTexture(this: v10, nTextureVar: info->m_nDetail, nAdditionalCreationFlags: v18 ? 0x80000 : 0);
    }
  }
  if ( (g_pConfig->m_Flags & 0x100) == 0 && info->m_nBumpmap != -1 )
  {
    v19 = params[info->m_nBumpmap];
    if ( v19->IsDefined(this: v19) )
    {
      CBaseShader::LoadBumpMap(this: v10, nTextureVar: info->m_nBumpmap, nAdditionalCreationFlags: 0);
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x10);
      if ( info->m_nNormalWrinkle != -1 && info->m_nNormalStretch != -1 )
      {
        v20 = params[info->m_nNormalWrinkle];
        if ( v20->IsDefined(this: v20) )
        {
          v21 = params[info->m_nNormalStretch];
          if ( v21->IsDefined(this: v21) )
          {
            CBaseShader::LoadTexture(this: v10, nTextureVar: info->m_nNormalWrinkle, nAdditionalCreationFlags: 0);
            CBaseShader::LoadTexture(this: v10, nTextureVar: info->m_nNormalStretch, nAdditionalCreationFlags: 0);
          }
        }
      }
    }
  }
  v22 = params[info->m_nEnvmap];
  if ( v22->IsDefined(this: v22) )
  {
    v23 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
    CBaseShader::LoadCubeMap(
      this: v10,
      nTextureVar: info->m_nEnvmap,
      nAdditionalCreationFlags: v23 != HDR_TYPE_NONE ? 0 : 0x80000);
  }
  if ( bHasSelfIllumMask_3 != 0 )
    CBaseShader::LoadTexture(this: v10, nTextureVar: info->m_nSelfIllumMask, nAdditionalCreationFlags: 0);
  v24 = params[info->m_nDisplacementMap];
  if ( v24->IsDefined(this: v24) )
    CBaseShader::LoadTexture(this: v10, nTextureVar: info->m_nDisplacementMap, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10023290
// Name: ComputePhongShaderInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputePhongShaderInfo(
        IMaterialVar **params@<edx>,
        VertexLitGeneric_DX9_Vars_t *info@<ecx>,
        PhongShaderInfo_t *pInfo@<esi>,
        CBaseVSShader *pShader)
{
  bool v4; // al
  int m_nWrinkle; // eax
  int m_nStretch; // eax
  bool v7; // al
  int m_nBumpmap; // eax
  int m_nNormalWrinkle; // eax
  int m_nNormalStretch; // eax
  bool v11; // al
  bool v12; // al
  bool v13; // zf
  int m_nSelfIllumFresnel; // eax
  bool v15; // al
  int m_nPhong; // eax
  bool v17; // bl
  int m_nPhongWarpTexture; // eax
  bool v19; // al
  int m_nDiffuseWarpTexture; // eax
  bool v21; // al
  int m_nDetail; // eax
  bool v23; // al
  int m_nRimLight; // eax

  v4 = info->m_nBaseTexture != -1 && (*((_BYTE *)params[info->m_nBaseTexture] + 28) & 0xF) == 3;
  pInfo->m_bHasBaseTexture = v4;
  v7 = false;
  if ( v4 )
  {
    m_nWrinkle = info->m_nWrinkle;
    if ( m_nWrinkle != -1 && (*((_BYTE *)params[m_nWrinkle] + 28) & 0xF) == 3 )
    {
      m_nStretch = info->m_nStretch;
      if ( m_nStretch != -1 && (*((_BYTE *)params[m_nStretch] + 28) & 0xF) == 3 )
        v7 = true;
    }
  }
  pInfo->m_bHasBaseTextureWrinkle = v7;
  m_nBumpmap = info->m_nBumpmap;
  v11 = false;
  if ( m_nBumpmap != -1 && (*((_BYTE *)params[m_nBumpmap] + 28) & 0xF) == 3 )
  {
    m_nNormalWrinkle = info->m_nNormalWrinkle;
    if ( m_nNormalWrinkle != -1 && (*((_BYTE *)params[m_nNormalWrinkle] + 28) & 0xF) == 3 )
    {
      m_nNormalStretch = info->m_nNormalStretch;
      if ( m_nNormalStretch != -1 && (*((_BYTE *)params[m_nNormalStretch] + 28) & 0xF) == 3 )
        v11 = true;
    }
  }
  pInfo->m_bHasBumpWrinkle = v11;
  v12 = (_BYTE)pShader == 0 && (*((_BYTE *)params[info->m_nEnvmap] + 28) & 0xF) == 3;
  pInfo->m_bHasEnvmap = v12;
  v13 = ((*params)->m_intVal & 0x40) == 0;
  pInfo->m_bHasSelfIllum = ((*params)->m_intVal & 0x40) != 0;
  v15 = false;
  if ( !v13 )
  {
    m_nSelfIllumFresnel = info->m_nSelfIllumFresnel;
    if ( m_nSelfIllumFresnel != -1 && params[m_nSelfIllumFresnel]->m_intVal != 0 )
      v15 = true;
  }
  pInfo->m_bHasSelfIllumFresnel = v15;
  m_nPhong = info->m_nPhong;
  v17 = m_nPhong != -1 && params[m_nPhong]->m_intVal != 0;
  pInfo->m_bHasPhong = v17;
  m_nPhongWarpTexture = info->m_nPhongWarpTexture;
  v19 = m_nPhongWarpTexture != -1 && (*((_BYTE *)params[m_nPhongWarpTexture] + 28) & 0xF) == 3;
  pInfo->m_bHasPhongWarp = v19;
  m_nDiffuseWarpTexture = info->m_nDiffuseWarpTexture;
  v21 = m_nDiffuseWarpTexture != -1 && (*((_BYTE *)params[m_nDiffuseWarpTexture] + 28) & 0xF) == 3;
  pInfo->m_bHasDiffuseWarp = v21;
  m_nDetail = info->m_nDetail;
  v23 = m_nDetail != -1 && (*((_BYTE *)params[m_nDetail] + 28) & 0xF) == 3;
  pInfo->m_bHasDetailTexture = v23;
  pInfo->m_bHasRimLight = r_rimlight.m_pParent != nullptr
                       && r_rimlight.m_pParent->m_Value.m_nValue != 0
                       && v17
                       && (m_nRimLight = info->m_nRimLight) != -1
                       && params[m_nRimLight]->m_intVal != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10023730
// Name: void DrawPhong_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct VertexLitGeneric_DX9_Vars_t __near &,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawPhong_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        VertexLitGeneric_DX9_Vars_t *info,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar **v7; // edi
  bool v8; // al
  IMaterialVar *v9; // edx
  int m_intVal; // eax
  int m_nBaseTexture; // edx
  int v12; // eax
  int m_nDisplacementMap; // eax
  char v14; // cl
  int m_nDisplacementWrinkleMap; // eax
  int m_nDetailTextureCombineMode; // eax
  bool v17; // al
  int m_nAlphaTestReference; // eax
  float x; // xmm0_4
  int v20; // eax
  int v21; // ebx
  void (__thiscall *EnableTexture)(IShaderShadow *, Sampler_t, bool); // eax
  BOOL v23; // eax
  IMaterialVar *v24; // ecx
  BOOL v25; // edi
  bool v26; // al
  BOOL v27; // eax
  bool v28; // al
  BOOL v29; // eax
  bool v30; // al
  BOOL v31; // eax
  bool v32; // al
  BOOL v33; // eax
  IShaderShadow_vtbl *v34; // edi
  int v35; // eax
  BOOL v36; // edi
  bool v37; // al
  BOOL v38; // eax
  bool v39; // al
  BOOL v40; // eax
  bool v41; // al
  BOOL v42; // eax
  bool v43; // al
  BOOL v44; // eax
  IShaderShadow_vtbl *v45; // edi
  int Index; // eax
  CBaseVSShader *v47; // edi
  int m_nAllowDiffuseModulation; // eax
  CBasePerMaterialContextData *v49; // eax
  TessellationMode_t v50; // eax
  __int32 v51; // edi
  int v52; // edx
  int v53; // eax
  int m_nBumpmap; // eax
  unsigned int v55; // edx
  int m_nSelfIllumMask; // eax
  char v57; // dl
  int m_nDetailTextureBlendFactor; // eax
  float v59; // xmm0_4
  int m_nPhongExponentTexture; // eax
  int m_nPhongAlbedoTint; // eax
  char v62; // dl
  int m_nRimMask; // eax
  int ShaderAPITextureBindHandle; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  int v71; // eax
  int v72; // eax
  int v73; // eax
  int v74; // eax
  int v75; // eax
  int v76; // edx
  int v77; // eax
  int v78; // eax
  unsigned int v79; // edx
  IMaterialVar *v80; // ecx
  int m_nSelfIllumTint; // eax
  IMaterialVar *v82; // eax
  float v83; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float *v86; // eax
  int v87; // xmm0_4
  int m_nInvertPhongMask; // eax
  bool v89; // al
  int m_nBaseMapAlphaPhongMask; // eax
  float v91; // xmm1_4
  bool v92; // al
  bool v93; // zf
  int m_nBlendTintByBaseAlpha; // eax
  bool v95; // al
  BOOL v96; // ecx
  _DWORD *v97; // eax
  _QWORD *v98; // eax
  IMaterialVar *v99; // ecx
  float v100; // xmm0_4
  bool v101; // sf
  IMaterialVar *v102; // ecx
  float v103; // xmm0_4
  IMaterialVar *v104; // ecx
  float v105; // xmm2_4
  float v106; // xmm1_4
  _QWORD *v107; // eax
  IMaterialVar *v108; // ecx
  IMaterialVar *v109; // eax
  __int64 v110; // xmm0_8
  _QWORD *v111; // eax
  IMaterialVar *v112; // ecx
  IMaterialVar *v113; // eax
  IMaterialVar *v114; // ecx
  IMaterialVar *v115; // ecx
  __int64 v116; // xmm1_8
  _QWORD *v117; // eax
  float v118; // xmm1_4
  ShadowFilterMode_t v119; // eax
  IMaterialVar *v120; // ecx
  IMaterialVar *v121; // eax
  IMaterialVar *v122; // ecx
  float v123; // xmm0_4
  int m_nBaseMapLuminancePhongMask; // eax
  bool v125; // al
  IMaterialVar *v126; // ecx
  IMaterialVar *v127; // ecx
  float v128; // xmm0_4
  float v129; // xmm0_4
  _OWORD *v130; // eax
  __int64 v131; // xmm0_8
  _QWORD *v132; // eax
  __int64 v133; // xmm0_8
  _QWORD *v134; // eax
  __int64 v135; // xmm0_8
  _QWORD *v136; // eax
  ITexture *v137; // eax
  int v138; // eax
  int m_nAmbientOcclusion; // eax
  float v140; // xmm0_4
  MaterialFogMode_t (__thiscall *GetSceneFogMode)(IShaderDynamicAPI *); // eax
  int v142; // edi
  BOOL v143; // ecx
  BOOL v144; // edx
  BOOL v145; // edi
  BOOL v146; // edi
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v148)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v149; // al
  BOOL v150; // eax
  bool v151; // al
  BOOL v152; // edi
  BOOL v153; // eax
  int v154; // edi
  bool (__thiscall *IsHWMorphingEnabled)(IShaderDynamicAPI *); // edx
  void (__thiscall *ExecuteCommandBuffer)(IShaderDynamicAPI *, unsigned __int8 *); // edx
  CBaseVSShader *v157; // [esp+4h] [ebp-4DCh]
  CCommandBufferBuilder<CFixedCommandStorageBuffer<1000> > DynamicCmdsOut; // [esp+14h] [ebp-4CCh] BYREF
  int nFrameVar; // [esp+400h] [ebp-E0h]
  phong_ps30_Static_Index _pshIndex; // [esp+404h] [ebp-DCh] BYREF
  float vFresnelRanges_SpecBoost[4]; // [esp+43Ch] [ebp-A4h]
  phong_vs30_Static_Index vEyePos_AmbientOcclusion; // [esp+44Ch] [ebp-94h] BYREF
  LightState_t lightState; // [esp+45Ch] [ebp-84h] BYREF
  int v164; // [esp+464h] [ebp-7Ch]
  float flFarZ; // [esp+468h] [ebp-78h]
  phong_ps30_Dynamic_Index v166; // [esp+46Ch] [ebp-74h] BYREF
  float vEyeDir[4]; // [esp+484h] [ebp-5Ch] BYREF
  bool bHDR; // [esp+497h] [ebp-49h]
  ShadowFilterMode_t nShadowFilterMode; // [esp+498h] [ebp-48h]
  bool bHasNormalMapAlphaEnvmapMask; // [esp+49Fh] [ebp-41h]
  int nLightingPreviewMode; // [esp+4A0h] [ebp-40h]
  float vEnvMapTint_MaskControl[4]; // [esp+4A4h] [ebp-3Ch] BYREF
  int fBlendFactor; // [esp+4B4h] [ebp-2Ch]
  bool bHasPhongTintMap; // [esp+4BAh] [ebp-26h]
  bool bUseStaticControlFlow; // [esp+4BBh] [ebp-25h]
  bool bHasSpecularExponentTexture; // [esp+4BCh] [ebp-24h]
  bool bHasRimMaskMap; // [esp+4BDh] [ebp-23h]
  bool bFlashlightShadows; // [esp+4BEh] [ebp-22h] BYREF
  bool bHasSelfIllumMask; // [esp+4BFh] [ebp-21h]
  PhongShaderInfo_t phongInfo; // [esp+4C0h] [ebp-20h] BYREF
  bool bHasVertexAlpha; // [esp+4CDh] [ebp-13h]
  bool bIsDecal; // [esp+4CEh] [ebp-12h]
  bool bUberlight; // [esp+4CFh] [ebp-11h] BYREF
  TessellationMode_t nTessellationMode; // [esp+4D0h] [ebp-10h] BYREF
  unsigned int flMin; // [esp+4D4h] [ebp-Ch]
  CBaseVSShader *bUnusedTexCoords; // [esp+4D8h] [ebp-8h] BYREF
  bool bLightingOnly; // [esp+4DDh] [ebp-3h]
  bool bHasFlashlight; // [esp+4DEh] [ebp-2h]
  bool bPhongHalfLambert; // [esp+4DFh] [ebp-1h]
  int flAmbientOcclusionStrength; // [esp+4ECh] [ebp+Ch]
  bool flAmbientOcclusionStrength_3; // [esp+4EFh] [ebp+Fh]
  VertexLitGeneric_DX9_Vars_t *infoa; // [esp+4F8h] [ebp+18h]
  unsigned __int8 flMax_3; // [esp+503h] [ebp+23h]
  char flMax_3a; // [esp+503h] [ebp+23h]
  bool flMax_3b; // [esp+503h] [ebp+23h]

  v7 = params;
  nTessellationMode = (TessellationMode_t)*pContextDataPtr;
  v8 = CBaseShader::UsingFlashlight(this: pShader, params);
  v9 = *params;
  v93 = !v8;
  bHasFlashlight = v8;
  m_intVal = v9->m_intVal;
  m_nBaseTexture = info->m_nBaseTexture;
  LOBYTE(bUnusedTexCoords) = !v93;
  bIsDecal = BYTE2(m_intVal) & 1;
  LOBYTE(fBlendFactor) = BYTE1(m_intVal) & 1;
  v12 = CBaseVSShader::EvaluateBlendRequirements(
          this: pShader,
          textureVar: m_nBaseTexture,
          isBaseTexture: true,
          detailTextureVar: -1);
  if ( v12 == 3
    || v12 == 1
    || (_BYTE)fBlendFactor != 0
    || (LOBYTE(nLightingPreviewMode) = 1, (_BYTE)bUnusedTexCoords != 0) )
  {
    LOBYTE(nLightingPreviewMode) = 0;
  }
  m_nDisplacementMap = info->m_nDisplacementMap;
  if ( m_nDisplacementMap == -1
    || (v14 = *((_BYTE *)params[m_nDisplacementMap] + 28) & 0xF, bPhongHalfLambert = true, v14 != 3) )
  {
    bPhongHalfLambert = false;
  }
  bUseStaticControlFlow = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
  m_nDisplacementWrinkleMap = info->m_nDisplacementWrinkleMap;
  if ( m_nDisplacementWrinkleMap == -1
    || (v93 = params[m_nDisplacementWrinkleMap]->m_intVal == 0, bHasVertexAlpha = true, v93) )
  {
    bHasVertexAlpha = false;
  }
  bHDR = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) != HDR_TYPE_NONE;
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    ComputePhongShaderInfo(params, info, pInfo: &phongInfo, pShader: bUnusedTexCoords);
    m_nDetailTextureCombineMode = info->m_nDetailTextureCombineMode;
    if ( m_nDetailTextureCombineMode == -1 )
      nTessellationMode = TESSELLATION_MODE_DISABLED;
    else
      nTessellationMode = params[m_nDetailTextureCombineMode]->m_intVal;
    v17 = ((*params)->m_intVal & 0x20) != 0;
    bUberlight = ((*params)->m_intVal & 0x10) != 0;
    bHasVertexAlpha = v17;
    if ( (_BYTE)bUnusedTexCoords != 0 || (flMax_3 = 1, (*((_BYTE *)params[info->m_nEnvmap] + 28) & 0xF) != 3) )
      flMax_3 = 0;
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: fBlendFactor);
    m_nAlphaTestReference = info->m_nAlphaTestReference;
    if ( m_nAlphaTestReference != -1 )
    {
      x = params[m_nAlphaTestReference]->m_VecVal.x;
      if ( x > 0.0 )
        ((void (__thiscall *)(IShaderShadow *, int, _DWORD))pShaderShadow->AlphaFunc)(
          a1: pShaderShadow,
          a2: 6,
          a3: LODWORD(x));
    }
    if ( bHasFlashlight )
    {
      v20 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *))g_pHardwareConfig->HasFastVertexTextures)(a1: g_pHardwareConfig);
      LOBYTE(v20) = (_BYTE)v20 != 0;
      nShadowFilterMode = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: v20);
    }
    else
    {
      nShadowFilterMode = SHADOWFILTERMODE_DEFAULT;
    }
    v21 = info->m_nBaseTexture;
    if ( (_BYTE)bUnusedTexCoords != 0 )
    {
      if ( (*((_BYTE *)params[v21] + 28) & 0xF) == 3 )
        CBaseShader::SetAdditiveBlendingShadowState(this: pShader, textureVar: v21, isBaseTexture: true);
      if ( (_BYTE)fBlendFactor != 0 )
      {
        pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: false);
        pShaderShadow->DepthFunc(this: pShaderShadow, a2: SHADER_DEPTHFUNC_EQUAL);
      }
      pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
      pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: false);
    }
    else if ( (*((_BYTE *)params[v21] + 28) & 0xF) == 3 )
    {
      CBaseShader::SetDefaultBlendingShadowState(this: pShader, textureVar: v21, isBaseTexture: true);
    }
    EnableTexture = pShaderShadow->EnableTexture;
    flMin = 3;
    EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    if ( bHasFlashlight )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: false);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    }
    v23 = nTessellationMode == TESSELLATION_MODE_ACC_PATCHES_REG
       || nTessellationMode == (TESSELLATION_MODE_ACC_PATCHES_REG|TESSELLATION_MODE_ACC_PATCHES_EXTRA)
       || nTessellationMode == 4;
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER13, a3: v23);
    if ( phongInfo.m_bHasSelfIllum )
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER14, a3: true);
    if ( bUberlight || bHasVertexAlpha )
      flMin = 7;
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER15, a3: true);
    if ( bPhongHalfLambert && g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
      pShaderShadow->EnableVertexTexture(this: pShaderShadow, a2: SHADER_VERTEXTEXTURE_SAMPLER2, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    lightState.m_nNumLights = 2;
    *(_DWORD *)&lightState.m_bAmbientLight = 0;
    v164 = 3;
    fBlendFactor = 1;
    if ( bIsDecal && g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
      fBlendFactor = 3;
    pShaderShadow->VertexShaderVertexFormat(
      this: pShaderShadow,
      a2: flMin | 0x400,
      a3: fBlendFactor,
      a4: (int *)&lightState,
      a5: 4);
    bLightingOnly = ((params[2]->m_intVal & 0x100000) != 0) + 2 * ((params[2]->m_intVal & 0x200000) != 0) == 3;
    bPhongHalfLambert = info->m_nPhongDisableHalfLambert < 0
                     || (v24 = params[info->m_nPhongDisableHalfLambert], !v24->IsDefined(this: v24))
                     || params[info->m_nPhongDisableHalfLambert]->m_intVal == 0;
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x800000);
      phong_vs30_Static_Index::phong_vs30_Static_Index(this: &vEyePos_AmbientOcclusion, pShaderShadow, params);
      flMin = bLightingOnly;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "WORLD_NORMAL", bLightingOnly, "bWorldNormal");
      v36 = bIsDecal;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DECAL", bIsDecal, "bIsDecal");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "phong_vs30",
        a3: 16
      * (v36
       + 2 * (flMin + 2 * (vEyePos_AmbientOcclusion.m_nDOPIXELFOG + 2 * vEyePos_AmbientOcclusion.m_nHARDWAREFOGBLEND))));
      _pshIndex.m_nFLASHLIGHT = bHasFlashlight;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", bHasFlashlight, "bHasFlashlight");
      v37 = phongInfo.m_bHasSelfIllum && (_BYTE)bUnusedTexCoords == 0;
      _pshIndex.m_nSELFILLUM = v37;
      if ( g_shaderConfigDumpEnable )
      {
        v38 = phongInfo.m_bHasSelfIllum && (_BYTE)bUnusedTexCoords == 0;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "SELFILLUM",
          v38,
          "phongInfo.m_bHasSelfIllum && !bHasFlashlightOnly");
      }
      v39 = phongInfo.m_bHasSelfIllumFresnel && (_BYTE)bUnusedTexCoords == 0;
      _pshIndex.m_nSELFILLUMFRESNEL = v39;
      if ( g_shaderConfigDumpEnable )
      {
        v40 = phongInfo.m_bHasSelfIllumFresnel && (_BYTE)bUnusedTexCoords == 0;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "SELFILLUMFRESNEL",
          v40,
          "phongInfo.m_bHasSelfIllumFresnel && !bHasFlashlightOnly");
      }
      v41 = phongInfo.m_bHasDiffuseWarp && phongInfo.m_bHasPhong;
      _pshIndex.m_nLIGHTWARPTEXTURE = v41;
      if ( g_shaderConfigDumpEnable )
      {
        v42 = phongInfo.m_bHasDiffuseWarp && phongInfo.m_bHasPhong;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "LIGHTWARPTEXTURE",
          v42,
          "phongInfo.m_bHasDiffuseWarp && phongInfo.m_bHasPhong");
      }
      v43 = phongInfo.m_bHasPhongWarp && phongInfo.m_bHasPhong;
      _pshIndex.m_nPHONGWARPTEXTURE = v43;
      if ( g_shaderConfigDumpEnable )
      {
        v44 = phongInfo.m_bHasPhongWarp && phongInfo.m_bHasPhong;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "PHONGWARPTEXTURE",
          v44,
          "phongInfo.m_bHasPhongWarp && phongInfo.m_bHasPhong");
      }
      _pshIndex.m_nWRINKLEMAP = phongInfo.m_bHasBaseTextureWrinkle;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "WRINKLEMAP",
          phongInfo.m_bHasBaseTextureWrinkle,
          "phongInfo.m_bHasBaseTextureWrinkle");
      _pshIndex.m_nDETAILTEXTURE = phongInfo.m_bHasDetailTexture;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "DETAILTEXTURE",
          phongInfo.m_bHasDetailTexture,
          "phongInfo.m_bHasDetailTexture");
      ClampDetailBlendModeAndWarn(nDetailBlendMode: (int *)&nTessellationMode, nMin: 0, nMax: 7);
      _pshIndex.m_nDETAIL_BLEND_MODE = nTessellationMode;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", nTessellationMode, "nDetailBlendMode");
      _pshIndex.m_nRIMLIGHT = phongInfo.m_bHasRimLight;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "RIMLIGHT",
          phongInfo.m_bHasRimLight,
          "phongInfo.m_bHasRimLight");
      _pshIndex.m_nCUBEMAP = flMax_3 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", flMax_3, "bHasEnvmap");
      _pshIndex.m_nFLASHLIGHTDEPTHFILTERMODE = nShadowFilterMode;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FLASHLIGHTDEPTHFILTERMODE",
          nShadowFilterMode,
          "nShadowFilterMode");
      _pshIndex.m_nSHADER_SRGB_READ = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
      _pshIndex.m_nWORLD_NORMAL = flMin;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "WORLD_NORMAL", bLightingOnly, "bWorldNormal");
      _pshIndex.m_nPHONG_HALFLAMBERT = bPhongHalfLambert;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "PHONG_HALFLAMBERT", bPhongHalfLambert, "bPhongHalfLambert");
      v45 = pShaderShadow->__vftable;
      Index = phong_ps30_Static_Index::GetIndex(this: &_pshIndex);
      v45->SetPixelShader(this: pShaderShadow, a2: "phong_ps30", a3: Index);
    }
    else
    {
      phong_vs20_Static_Index::phong_vs20_Static_Index(
        this: (phong_vs20_Static_Index *)&vEyePos_AmbientOcclusion,
        pShaderShadow,
        params);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
      v25 = !bUseStaticControlFlow;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "FLATTEN_STATIC_CONTROL_FLOW",
          !bUseStaticControlFlow,
          "!bUseStaticControlFlow");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "phong_vs20",
        a3: 24 * (v25 + 2 * (vEyePos_AmbientOcclusion.m_nDOPIXELFOG + 2 * vEyePos_AmbientOcclusion.m_nHARDWAREFOGBLEND)));
      _pshIndex.m_nFLASHLIGHT = bHasFlashlight;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", bHasFlashlight, "bHasFlashlight");
      v26 = phongInfo.m_bHasSelfIllum && (_BYTE)bUnusedTexCoords == 0;
      _pshIndex.m_nSELFILLUM = v26;
      if ( g_shaderConfigDumpEnable )
      {
        v27 = phongInfo.m_bHasSelfIllum && (_BYTE)bUnusedTexCoords == 0;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "SELFILLUM",
          v27,
          "phongInfo.m_bHasSelfIllum && !bHasFlashlightOnly");
      }
      v28 = phongInfo.m_bHasSelfIllumFresnel && (_BYTE)bUnusedTexCoords == 0;
      _pshIndex.m_nSELFILLUMFRESNEL = v28;
      if ( g_shaderConfigDumpEnable )
      {
        v29 = phongInfo.m_bHasSelfIllumFresnel && (_BYTE)bUnusedTexCoords == 0;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "SELFILLUMFRESNEL",
          v29,
          "phongInfo.m_bHasSelfIllumFresnel && !bHasFlashlightOnly");
      }
      v30 = phongInfo.m_bHasDiffuseWarp && phongInfo.m_bHasPhong;
      _pshIndex.m_nLIGHTWARPTEXTURE = v30;
      if ( g_shaderConfigDumpEnable )
      {
        v31 = phongInfo.m_bHasDiffuseWarp && phongInfo.m_bHasPhong;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "LIGHTWARPTEXTURE",
          v31,
          "phongInfo.m_bHasDiffuseWarp && phongInfo.m_bHasPhong");
      }
      v32 = phongInfo.m_bHasPhongWarp && phongInfo.m_bHasPhong;
      _pshIndex.m_nPHONGWARPTEXTURE = v32;
      if ( g_shaderConfigDumpEnable )
      {
        v33 = phongInfo.m_bHasPhongWarp && phongInfo.m_bHasPhong;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "PHONGWARPTEXTURE",
          v33,
          "phongInfo.m_bHasPhongWarp && phongInfo.m_bHasPhong");
      }
      _pshIndex.m_nWRINKLEMAP = phongInfo.m_bHasBaseTextureWrinkle;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "WRINKLEMAP",
          phongInfo.m_bHasBaseTextureWrinkle,
          "phongInfo.m_bHasBaseTextureWrinkle");
      _pshIndex.m_nDETAILTEXTURE = phongInfo.m_bHasDetailTexture;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "DETAILTEXTURE",
          phongInfo.m_bHasDetailTexture,
          "phongInfo.m_bHasDetailTexture");
      ClampDetailBlendModeAndWarn(nDetailBlendMode: (int *)&nTessellationMode, nMin: 0, nMax: 7);
      _pshIndex.m_nDETAIL_BLEND_MODE = nTessellationMode;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", nTessellationMode, "nDetailBlendMode");
      _pshIndex.m_nRIMLIGHT = phongInfo.m_bHasRimLight;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "RIMLIGHT",
          phongInfo.m_bHasRimLight,
          "phongInfo.m_bHasRimLight");
      _pshIndex.m_nCUBEMAP = flMax_3 != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", flMax_3, "bHasEnvmap");
      _pshIndex.m_nFLASHLIGHTDEPTHFILTERMODE = nShadowFilterMode;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "FLASHLIGHTDEPTHFILTERMODE",
          nShadowFilterMode,
          "nShadowFilterMode");
      _pshIndex.m_nSHADER_SRGB_READ = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
      _pshIndex.m_nWORLD_NORMAL = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
      _pshIndex.m_nPHONG_HALFLAMBERT = bPhongHalfLambert;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "PHONG_HALFLAMBERT", bPhongHalfLambert, "bPhongHalfLambert");
      v34 = pShaderShadow->__vftable;
      v35 = phong_ps20b_Static_Index::GetIndex(this: (phong_ps20b_Static_Index *)&_pshIndex);
      v34->SetPixelShader(this: pShaderShadow, a2: "phong_ps20b", a3: v35);
    }
    if ( (_BYTE)bUnusedTexCoords != 0 )
    {
      v47 = pShader;
      CBaseShader::FogToBlack(this: pShader);
    }
    else
    {
      CBaseShader::DefaultFog(this: pShader);
      v47 = pShader;
    }
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: nLightingPreviewMode);
    CBaseShader::PI_BeginCommandBuffer(this: v47);
    CBaseShader::PI_SetPixelShaderAmbientLightCube(this: v47, nFirstRegister: 4);
    CBaseShader::PI_SetPixelShaderLocalLighting(this: v47, nFirstRegister: 20);
    CBaseShader::PI_SetVertexShaderAmbientLightCube(this: v47);
    m_nAllowDiffuseModulation = info->m_nAllowDiffuseModulation;
    if ( m_nAllowDiffuseModulation == -1 || params[m_nAllowDiffuseModulation]->m_intVal != 0 )
    {
      CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace(this: v47, nRegister: 1);
      CBaseShader::PI_EndCommandBuffer(this: v47);
      CBaseShader::Draw(this: v47, bMakeActualDrawCall: true);
    }
    else
    {
      CBaseShader::PI_SetModulationPixelShaderDynamicState_Identity(this: v47, nRegister: 1);
      CBaseShader::PI_EndCommandBuffer(this: v47);
      CBaseShader::Draw(this: v47, bMakeActualDrawCall: true);
    }
    return;
  }
  if ( nTessellationMode == TESSELLATION_MODE_DISABLED )
  {
    v49 = (CBasePerMaterialContextData *)operator new(nSize: 0x330u);
    if ( v49 != nullptr )
    {
      v49->m_bMaterialVarsChanged = true;
      v49->m_nVarChangeID = -1;
      v49->__vftable = (CBasePerMaterialContextData_vtbl *)&CPhong_DX9_Context::`vftable';
      *(_DWORD *)&v49[67].m_bMaterialVarsChanged = v49 + 1;
    }
    else
    {
      v49 = nullptr;
    }
    nTessellationMode = (TessellationMode_t)v49;
    *pContextDataPtr = v49;
LABEL_202:
    v50 = nTessellationMode;
    v51 = nTessellationMode + 12;
    v157 = bUnusedTexCoords;
    *(_DWORD *)(nTessellationMode + 812) = nTessellationMode + 12;
    *(_BYTE *)(v50 + 8) = 0;
    ComputePhongShaderInfo(params, info, pInfo: &phongInfo, pShader: v157);
    v53 = info->m_nDetailTextureCombineMode;
    if ( v53 == -1 )
      nShadowFilterMode = SHADOWFILTERMODE_DEFAULT;
    else
      nShadowFilterMode = *(_DWORD *)(*(_DWORD *)(v52 + 4 * v53) + 8);
    m_nBumpmap = info->m_nBumpmap;
    if ( m_nBumpmap == -1 || (flMax_3a = 1, (*((_BYTE *)params[m_nBumpmap] + 28) & 0xF) != 3) )
      flMax_3a = 0;
    if ( g_pConfig->nFullbright != 2
      || (v55 = (unsigned int)(*params)->m_intVal >> 1, bLightingOnly = true, (v55 & 1) != 0) )
    {
      bLightingOnly = false;
    }
    if ( !phongInfo.m_bHasSelfIllum
      || (m_nSelfIllumMask = info->m_nSelfIllumMask) == -1
      || (v57 = *((_BYTE *)params[m_nSelfIllumMask] + 28) & 0xF, bHasSelfIllumMask = true, v57 != 3) )
    {
      bHasSelfIllumMask = false;
    }
    m_nDetailTextureBlendFactor = info->m_nDetailTextureBlendFactor;
    if ( m_nDetailTextureBlendFactor == -1 )
      v59 = 1.0;
    else
      v59 = params[m_nDetailTextureBlendFactor]->m_VecVal.x;
    m_nPhongExponentTexture = info->m_nPhongExponentTexture;
    fBlendFactor = LODWORD(v59);
    if ( m_nPhongExponentTexture == -1 || (*((_BYTE *)params[m_nPhongExponentTexture] + 28) & 0xF) != 3 )
    {
      v62 = 0;
      bHasSpecularExponentTexture = false;
    }
    else
    {
      m_nPhongAlbedoTint = info->m_nPhongAlbedoTint;
      v62 = 1;
      bHasSpecularExponentTexture = true;
      if ( m_nPhongAlbedoTint != -1 )
      {
        v93 = params[m_nPhongAlbedoTint]->m_intVal == 0;
        bHasPhongTintMap = true;
        if ( !v93 )
        {
LABEL_223:
          bHasNormalMapAlphaEnvmapMask = ((*params)->m_intVal & 0x400000) != 0;
          if ( v62 == 0
            || !phongInfo.m_bHasRimLight
            || (m_nRimMask = info->m_nRimMask) == -1
            || (v93 = params[m_nRimMask]->m_intVal == 0, bHasRimMaskMap = true, v93) )
          {
            bHasRimMaskMap = false;
          }
          if ( phongInfo.m_bHasBaseTexture )
          {
            ShaderAPITextureBindHandle = CBaseShader::GetShaderAPITextureBindHandle(
                                           this: pShader,
                                           nTextureVar: info->m_nBaseTexture,
                                           nFrameVar: info->m_nBaseTextureFrame,
                                           nTextureChannel: 0);
            **(_DWORD **)(v51 + 800) = 10;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = 0x80000000;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = ShaderAPITextureBindHandle;
          }
          else
          {
            **(_DWORD **)(v51 + 800) = 9;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = 0x80000000;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = 4;
          }
          *(_DWORD *)(v51 + 800) += 4;
          if ( phongInfo.m_bHasBaseTextureWrinkle )
          {
            v65 = CBaseShader::GetShaderAPITextureBindHandle(
                    this: pShader,
                    nTextureVar: info->m_nWrinkle,
                    nFrameVar: info->m_nBaseTextureFrame,
                    nTextureChannel: 0);
            **(_DWORD **)(v51 + 800) = 10;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = -2147483639;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = v65;
            *(_DWORD *)(v51 + 800) += 4;
            v66 = CBaseShader::GetShaderAPITextureBindHandle(
                    this: pShader,
                    nTextureVar: info->m_nStretch,
                    nFrameVar: info->m_nBaseTextureFrame,
                    nTextureChannel: 0);
            **(_DWORD **)(v51 + 800) = 10;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = -2147483638;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = v66;
            *(_DWORD *)(v51 + 800) += 4;
          }
          if ( phongInfo.m_bHasDiffuseWarp && phongInfo.m_bHasPhong )
          {
            if ( r_lightwarpidentity_1.m_pParent != nullptr && r_lightwarpidentity_1.m_pParent->m_Value.m_nValue != 0 )
            {
              **(_DWORD **)(v51 + 800) = 9;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = -2147483646;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 24;
            }
            else
            {
              v67 = CBaseShader::GetShaderAPITextureBindHandle(
                      this: pShader,
                      nTextureVar: info->m_nDiffuseWarpTexture,
                      nFrameVar: -1,
                      nTextureChannel: 0);
              **(_DWORD **)(v51 + 800) = 10;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = -2147483646;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = v67;
            }
            *(_DWORD *)(v51 + 800) += 4;
          }
          if ( phongInfo.m_bHasPhongWarp )
          {
            v68 = CBaseShader::GetShaderAPITextureBindHandle(
                    this: pShader,
                    nTextureVar: info->m_nPhongWarpTexture,
                    nFrameVar: -1,
                    nTextureChannel: 0);
            **(_DWORD **)(v51 + 800) = 10;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = 1;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = v68;
            *(_DWORD *)(v51 + 800) += 4;
          }
          if ( bHasSpecularExponentTexture && phongInfo.m_bHasPhong )
          {
            v69 = CBaseShader::GetShaderAPITextureBindHandle(
                    this: pShader,
                    nTextureVar: info->m_nPhongExponentTexture,
                    nFrameVar: -1,
                    nTextureChannel: 0);
            **(_DWORD **)(v51 + 800) = 10;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = 7;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = v69;
          }
          else
          {
            **(_DWORD **)(v51 + 800) = 9;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = 7;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = 4;
          }
          *(_DWORD *)(v51 + 800) += 4;
          if ( g_pConfig->m_bFastNoBump )
          {
            if ( flMax_3a != 0 )
            {
              **(_DWORD **)(v51 + 800) = 9;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 3;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 9;
              *(_DWORD *)(v51 + 800) += 4;
            }
            if ( !phongInfo.m_bHasBaseTextureWrinkle && !phongInfo.m_bHasBumpWrinkle )
            {
LABEL_261:
              if ( phongInfo.m_bHasDetailTexture )
              {
                if ( nShadowFilterMode == NVIDIA_PCF_CHEAP
                  || nShadowFilterMode == ATI_NOPCF
                  || (*(float *)&flMin = 0.0, nShadowFilterMode == 4) )
                {
                  flMin = 1;
                }
                v75 = CBaseShader::GetShaderAPITextureBindHandle(
                        this: pShader,
                        nTextureVar: info->m_nDetail,
                        nFrameVar: info->m_nDetailFrame,
                        nTextureChannel: 0);
                v76 = (unsigned __int8)flMin;
                **(_DWORD **)(v51 + 800) = 10;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = (v76 != 0 ? 0x80000000 : 0) | 0xD;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = v75;
                *(_DWORD *)(v51 + 800) += 4;
              }
              if ( phongInfo.m_bHasSelfIllum )
              {
                if ( bHasSelfIllumMask )
                {
                  v77 = CBaseShader::GetShaderAPITextureBindHandle(
                          this: pShader,
                          nTextureVar: info->m_nSelfIllumMask,
                          nFrameVar: -1,
                          nTextureChannel: 0);
                  **(_DWORD **)(v51 + 800) = 10;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 14;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = v77;
                }
                else
                {
                  **(_DWORD **)(v51 + 800) = 9;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 14;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 5;
                }
                *(_DWORD *)(v51 + 800) += 4;
              }
              if ( (_BYTE)bUnusedTexCoords == 0 && phongInfo.m_bHasEnvmap )
              {
                nFrameVar = info->m_nEnvmapFrame;
                flFarZ = *(float *)&info->m_nEnvmap;
                flMin = bHDR ? 0 : 0x80000000;
                if ( CBaseShader::s_ppParams[LODWORD(flFarZ)]->IsTextureValueInternalEnvCubemap(this: CBaseShader::s_ppParams[LODWORD(flFarZ)]) )
                {
                  **(_DWORD **)(v51 + 800) = 9;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = flMin | 8;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 25;
                }
                else
                {
                  v78 = CBaseShader::GetShaderAPITextureBindHandle(
                          this: pShader,
                          nTextureVar: SLODWORD(flFarZ),
                          nFrameVar,
                          nTextureChannel: 0);
                  v79 = flMin;
                  **(_DWORD **)(v51 + 800) = 10;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = v79 | 8;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = v78;
                }
                *(_DWORD *)(v51 + 800) += 4;
              }
              CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureTransform(
                this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *)v51,
                vertexReg: 48,
                transformVar: info->m_nBaseTextureTransform);
              if ( flMax_3a != 0 )
                CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureTransform(
                  this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *)v51,
                  vertexReg: 50,
                  transformVar: info->m_nBumpTransform);
              if ( phongInfo.m_bHasDetailTexture )
              {
                if ( info->m_nDetailTextureTransform >= 0
                  && (v80 = params[info->m_nDetailTextureTransform], v80->IsDefined(this: v80)) )
                {
                  CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
                    this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *)v51,
                    vertexReg: 52,
                    transformVar: info->m_nDetailTextureTransform,
                    scaleVar: info->m_nDetailScale);
                }
                else
                {
                  CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
                    this: (CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *)v51,
                    vertexReg: 52,
                    transformVar: info->m_nBaseTextureTransform,
                    scaleVar: info->m_nDetailScale);
                }
              }
              m_nSelfIllumTint = info->m_nSelfIllumTint;
              if ( m_nSelfIllumTint != -1 )
              {
                v82 = CBaseShader::s_ppParams[m_nSelfIllumTint];
                v83 = v82->m_VecVal.x;
                y = v82->m_VecVal.y;
                z = v82->m_VecVal.z;
                **(_DWORD **)(v51 + 800) = 3;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 0;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 1;
                v86 = *(float **)(v51 + 800);
                v86[1] = v83;
                v87 = fBlendFactor;
                v86[2] = y;
                v86[3] = z;
                *((_DWORD *)v86 + 4) = v87;
                *(_DWORD *)(v51 + 800) = v86 + 5;
              }
              m_nInvertPhongMask = info->m_nInvertPhongMask;
              v89 = m_nInvertPhongMask != -1 && params[m_nInvertPhongMask]->m_intVal != 0;
              v93 = !v89;
              m_nBaseMapAlphaPhongMask = info->m_nBaseMapAlphaPhongMask;
              v91 = (float)!v93;
              v92 = m_nBaseMapAlphaPhongMask != -1 && params[m_nBaseMapAlphaPhongMask]->m_intVal != 0;
              v93 = !v92;
              m_nBlendTintByBaseAlpha = info->m_nBlendTintByBaseAlpha;
              v95 = m_nBlendTintByBaseAlpha != -1 && params[m_nBlendTintByBaseAlpha]->m_intVal != 0;
              **(_DWORD **)(v51 + 800) = 3;
              v96 = v95;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 27;
              *(_DWORD *)(v51 + 800) += 4;
              v97 = *(_DWORD **)(v51 + 800);
              *(float *)&v166.m_nNUM_LIGHTS = (float)!v93;
              *v97 = 1;
              *(_DWORD *)(v51 + 800) += 4;
              v98 = *(_QWORD **)(v51 + 800);
              v166.m_nWRITE_DEPTH_TO_DESTALPHA = 0;
              *v98 = (unsigned int)v166.m_nNUM_LIGHTS;
              *(float *)&v166.m_nFLASHLIGHTSHADOWS = 1.0 - (float)v96;
              *(float *)&v166.m_nUBERLIGHT = v91;
              v98[1] = *(_QWORD *)&v166.m_nFLASHLIGHTSHADOWS;
              *(_DWORD *)(v51 + 800) += 16;
              if ( phongInfo.m_bHasSelfIllumFresnel )
              {
                if ( (_BYTE)bUnusedTexCoords != 0 )
                  goto LABEL_328;
                if ( info->m_nSelfIllumFresnelMinMaxExp >= 0
                  && (v99 = params[info->m_nSelfIllumFresnelMinMaxExp], v99->IsDefined(this: v99)) )
                {
                  v100 = params[info->m_nSelfIllumFresnelMinMaxExp]->m_VecVal.x;
                }
                else
                {
                  v100 = 0.0;
                }
                v101 = info->m_nSelfIllumFresnelMinMaxExp < 0;
                *(float *)&flMin = v100;
                if ( v101 || (v102 = params[info->m_nSelfIllumFresnelMinMaxExp], !v102->IsDefined(this: v102)) )
                  v103 = 1.0;
                else
                  v103 = params[info->m_nSelfIllumFresnelMinMaxExp]->m_VecVal.y;
                if ( info->m_nSelfIllumFresnelMinMaxExp >= 0
                  && (v104 = params[info->m_nSelfIllumFresnelMinMaxExp], v104->IsDefined(this: v104)) )
                {
                  v105 = params[info->m_nSelfIllumFresnelMinMaxExp]->m_VecVal.z;
                }
                else
                {
                  v105 = 1.0;
                }
                if ( v103 == 0.0 )
                  v106 = 0.0;
                else
                  v106 = *(float *)&flMin / v103;
                **(_DWORD **)(v51 + 800) = 3;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 3;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 1;
                *(_DWORD *)(v51 + 800) += 4;
                v107 = *(_QWORD **)(v51 + 800);
                vEyeDir[3] = v103;
                vEyeDir[1] = v106;
                vEyeDir[0] = 1.0 - v106;
                *v107 = *(_QWORD *)vEyeDir;
                vEyeDir[2] = v105;
                v107[1] = *(_QWORD *)&vEyeDir[2];
                *(_DWORD *)(v51 + 800) += 16;
              }
              else if ( (_BYTE)bUnusedTexCoords != 0 )
              {
                goto LABEL_328;
              }
              **(_DWORD **)(v51 + 800) = 9;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 5;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 12;
              *(_DWORD *)(v51 + 800) += 4;
              if ( phongInfo.m_bHasEnvmap )
              {
                v93 = info->m_nEnvmapTint == -1;
                vEnvMapTint_MaskControl[0] = 1.0;
                vEnvMapTint_MaskControl[1] = 1.0;
                vEnvMapTint_MaskControl[2] = 1.0;
                if ( !v93 )
                {
                  v108 = params[info->m_nEnvmapTint];
                  if ( v108->IsDefined(this: v108) )
                  {
                    v109 = params[info->m_nEnvmapTint];
                    vEnvMapTint_MaskControl[0] = v109->m_VecVal.x;
                    vEnvMapTint_MaskControl[1] = v109->m_VecVal.y;
                    vEnvMapTint_MaskControl[2] = v109->m_VecVal.z;
                  }
                }
                if ( bHasNormalMapAlphaEnvmapMask )
                  vEnvMapTint_MaskControl[3] = 1.0;
                else
                  vEnvMapTint_MaskControl[3] = 0.0;
                if ( bLightingOnly )
                  memset(vEnvMapTint_MaskControl, 0, 12);
                v110 = *(_QWORD *)vEnvMapTint_MaskControl;
                **(_DWORD **)(v51 + 800) = 3;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 2;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 1;
                *(_DWORD *)(v51 + 800) += 4;
                v111 = *(_QWORD **)(v51 + 800);
                *v111 = v110;
                v111[1] = *(_QWORD *)&vEnvMapTint_MaskControl[2];
                *(_DWORD *)(v51 + 800) += 16;
              }
LABEL_328:
              v93 = info->m_nPhongTint == -1;
              vEnvMapTint_MaskControl[3] = 4.0;
              vEnvMapTint_MaskControl[0] = 1.0;
              vEnvMapTint_MaskControl[1] = 1.0;
              vEnvMapTint_MaskControl[2] = 1.0;
              vFresnelRanges_SpecBoost[0] = 0.0;
              vFresnelRanges_SpecBoost[1] = 0.5;
              vFresnelRanges_SpecBoost[2] = 1.0;
              v166.m_nNUM_LIGHTS = 1065353216;
              v166.m_nWRITE_DEPTH_TO_DESTALPHA = 1065353216;
              v166.m_nFLASHLIGHTSHADOWS = 1065353216;
              v166.m_nUBERLIGHT = 1065353216;
              if ( !v93 )
              {
                v112 = params[info->m_nPhongTint];
                if ( v112->IsDefined(this: v112) )
                {
                  v113 = params[info->m_nPhongTint];
                  vEnvMapTint_MaskControl[0] = v113->m_VecVal.x;
                  vEnvMapTint_MaskControl[1] = v113->m_VecVal.y;
                  vEnvMapTint_MaskControl[2] = v113->m_VecVal.z;
                }
              }
              if ( phongInfo.m_bHasRimLight )
              {
                if ( info->m_nRimLightPower != -1 )
                {
                  v114 = params[info->m_nRimLightPower];
                  if ( v114->IsDefined(this: v114) )
                  {
                    vEnvMapTint_MaskControl[3] = params[info->m_nRimLightPower]->m_VecVal.x;
                    if ( vEnvMapTint_MaskControl[3] <= 1.0 )
                      vEnvMapTint_MaskControl[3] = 1.0;
                  }
                }
                if ( info->m_nRimLightBoost != -1 )
                {
                  v115 = params[info->m_nRimLightBoost];
                  if ( v115->IsDefined(this: v115) )
                    v166.m_nUBERLIGHT = LODWORD(params[info->m_nRimLightBoost]->m_VecVal.x);
                }
                if ( !bHasFlashlight )
                {
                  memset(&vEyeDir[1], 0, 12);
                  if ( bHasRimMaskMap )
                    vEyeDir[0] = params[info->m_nRimMask]->m_VecVal.x;
                  else
                    vEyeDir[0] = 0.0;
                  v116 = *(_QWORD *)vEyeDir;
                  **(_DWORD **)(v51 + 800) = 3;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 13;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 1;
                  *(_DWORD *)(v51 + 800) += 4;
                  v117 = *(_QWORD **)(v51 + 800);
                  *v117 = v116;
                  v117[1] = *(_QWORD *)&vEyeDir[2];
                  *(_DWORD *)(v51 + 800) += 16;
                }
              }
              if ( vEnvMapTint_MaskControl[0] == 0.0
                && vEnvMapTint_MaskControl[1] == 0.0
                && vEnvMapTint_MaskControl[2] == 0.0 )
              {
                if ( bHasPhongTintMap )
                {
                  v118 = -1.0;
                }
                else
                {
                  v118 = 1.0;
                  vEnvMapTint_MaskControl[1] = 1.0;
                  vEnvMapTint_MaskControl[2] = 1.0;
                }
                vEnvMapTint_MaskControl[0] = v118;
              }
              if ( !bLightingOnly )
                goto LABEL_364;
              if ( !phongInfo.m_bHasSelfIllum || (_BYTE)bUnusedTexCoords != 0 )
              {
                **(_DWORD **)(v51 + 800) = 9;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 0x80000000;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 7;
                *(_DWORD *)(v51 + 800) += 4;
                if ( !phongInfo.m_bHasBaseTextureWrinkle && !phongInfo.m_bHasBumpWrinkle )
                  goto LABEL_361;
                **(_DWORD **)(v51 + 800) = 9;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = -2147483639;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 7;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 9;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = -2147483638;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 7;
              }
              else
              {
                **(_DWORD **)(v51 + 800) = 9;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 0x80000000;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 8;
                *(_DWORD *)(v51 + 800) += 4;
                if ( !phongInfo.m_bHasBaseTextureWrinkle && !phongInfo.m_bHasBumpWrinkle )
                  goto LABEL_361;
                **(_DWORD **)(v51 + 800) = 9;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = -2147483639;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 8;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 9;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = -2147483638;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 8;
              }
              *(_DWORD *)(v51 + 800) += 4;
LABEL_361:
              if ( phongInfo.m_bHasDetailTexture )
              {
                v119 = nShadowFilterMode;
                **(_DWORD **)(v51 + 800) = 9;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = (v119 != SHADOWFILTERMODE_DEFAULT ? 0x80000000 : 0) | 0xD;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 7;
                *(_DWORD *)(v51 + 800) += 4;
              }
              memset(vEnvMapTint_MaskControl, 0, 12);
LABEL_364:
              if ( info->m_nPhongFresnelRanges != -1 )
              {
                v120 = params[info->m_nPhongFresnelRanges];
                if ( v120->IsDefined(this: v120) )
                {
                  v121 = params[info->m_nPhongFresnelRanges];
                  vFresnelRanges_SpecBoost[0] = v121->m_VecVal.x;
                  vFresnelRanges_SpecBoost[1] = v121->m_VecVal.y;
                  vFresnelRanges_SpecBoost[2] = v121->m_VecVal.z;
                }
              }
              if ( info->m_nPhongBoost == -1 || (v122 = params[info->m_nPhongBoost], !v122->IsDefined(this: v122)) )
                v123 = 1.0;
              else
                v123 = params[info->m_nPhongBoost]->m_VecVal.x;
              m_nBaseMapLuminancePhongMask = info->m_nBaseMapLuminancePhongMask;
              vFresnelRanges_SpecBoost[3] = v123;
              v125 = m_nBaseMapLuminancePhongMask != -1 && params[m_nBaseMapLuminancePhongMask]->m_intVal != 0;
              vEyeDir[0] = 0.0;
              vEyeDir[1] = (float)v125;
              if ( (_BYTE)bUnusedTexCoords == 0 && phongInfo.m_bHasEnvmap && info->m_nEnvmapFresnel != -1 )
              {
                v126 = params[info->m_nEnvmapFresnel];
                if ( v126->IsDefined(this: v126) )
                  vEyeDir[0] = params[info->m_nEnvmapFresnel]->m_VecVal.x;
              }
              if ( info->m_nPhongExponent == -1 || (v127 = params[info->m_nPhongExponent], !v127->IsDefined(this: v127)) )
                v128 = 0.0;
              else
                v128 = params[info->m_nPhongExponent]->m_VecVal.x;
              vEyeDir[2] = v128;
              if ( bHasSelfIllumMask )
                v129 = 1.0;
              else
                v129 = 0.0;
              **(_DWORD **)(v51 + 800) = 3;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 19;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 1;
              *(_DWORD *)(v51 + 800) += 4;
              v130 = *(_OWORD **)(v51 + 800);
              vEyeDir[3] = v129;
              *v130 = *(_OWORD *)vFresnelRanges_SpecBoost;
              v131 = *(_QWORD *)&v166.m_nNUM_LIGHTS;
              *(_DWORD *)(v51 + 800) += 16;
              **(_DWORD **)(v51 + 800) = 3;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 14;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 1;
              *(_DWORD *)(v51 + 800) += 4;
              v132 = *(_QWORD **)(v51 + 800);
              *v132 = v131;
              v132[1] = *(_QWORD *)&v166.m_nFLASHLIGHTSHADOWS;
              *(_DWORD *)(v51 + 800) += 16;
              **(_DWORD **)(v51 + 800) = 3;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 26;
              *(_DWORD *)(v51 + 800) += 4;
              v133 = *(_QWORD *)vEnvMapTint_MaskControl;
              **(_DWORD **)(v51 + 800) = 1;
              *(_DWORD *)(v51 + 800) += 4;
              v134 = *(_QWORD **)(v51 + 800);
              *v134 = v133;
              v134[1] = *(_QWORD *)&vEnvMapTint_MaskControl[2];
              *(_DWORD *)(v51 + 800) += 16;
              v135 = *(_QWORD *)vEyeDir;
              **(_DWORD **)(v51 + 800) = 3;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 10;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 1;
              *(_DWORD *)(v51 + 800) += 4;
              v136 = *(_QWORD **)(v51 + 800);
              *v136 = v135;
              v136[1] = *(_QWORD *)&vEyeDir[2];
              *(_DWORD *)(v51 + 800) += 16;
              **(_DWORD **)(v51 + 800) = 6;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 12;
              *(_DWORD *)(v51 + 800) += 4;
              if ( bHasFlashlight )
              {
                **(_DWORD **)(v51 + 800) = 14;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 6;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 4;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 5;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 28;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 13;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 14;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 2;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 31;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 15;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 0;
                *(_DWORD *)(v51 + 800) += 4;
                **(_DWORD **)(v51 + 800) = 0;
                *(_DWORD *)(v51 + 800) += 4;
                if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) > 92 )
                {
                  **(_DWORD **)(v51 + 800) = 15;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 33;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 34;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 35;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 36;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 37;
                  *(_DWORD *)(v51 + 800) += 4;
                  **(_DWORD **)(v51 + 800) = 38;
                  *(_DWORD *)(v51 + 800) += 4;
                }
              }
              **(_DWORD **)(v51 + 800) = 0;
              *(_DWORD *)(v51 + 800) += 4;
              v7 = params;
              goto LABEL_391;
            }
            v74 = CBaseShader::GetShaderAPITextureBindHandle(
                    this: pShader,
                    nTextureVar: 9,
                    nFrameVar: -1,
                    nTextureChannel: 0);
            **(_DWORD **)(v51 + 800) = 10;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = 11;
            *(_DWORD *)(v51 + 800) += 4;
            **(_DWORD **)(v51 + 800) = v74;
            *(_DWORD *)(v51 + 800) += 4;
            v72 = CBaseShader::GetShaderAPITextureBindHandle(
                    this: pShader,
                    nTextureVar: 9,
                    nFrameVar: -1,
                    nTextureChannel: 0);
          }
          else
          {
            if ( flMax_3a != 0 )
            {
              v70 = CBaseShader::GetShaderAPITextureBindHandle(
                      this: pShader,
                      nTextureVar: info->m_nBumpmap,
                      nFrameVar: info->m_nBumpFrame,
                      nTextureChannel: 0);
              **(_DWORD **)(v51 + 800) = 10;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 3;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = v70;
            }
            else
            {
              **(_DWORD **)(v51 + 800) = 9;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 3;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 9;
            }
            *(_DWORD *)(v51 + 800) += 4;
            if ( phongInfo.m_bHasBumpWrinkle )
            {
              v71 = CBaseShader::GetShaderAPITextureBindHandle(
                      this: pShader,
                      nTextureVar: info->m_nNormalWrinkle,
                      nFrameVar: info->m_nBumpFrame,
                      nTextureChannel: 0);
              **(_DWORD **)(v51 + 800) = 10;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 11;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = v71;
              *(_DWORD *)(v51 + 800) += 4;
              v72 = CBaseShader::GetShaderAPITextureBindHandle(
                      this: pShader,
                      nTextureVar: info->m_nNormalStretch,
                      nFrameVar: info->m_nBumpFrame,
                      nTextureChannel: 0);
            }
            else
            {
              if ( !phongInfo.m_bHasBaseTextureWrinkle )
                goto LABEL_261;
              v73 = CBaseShader::GetShaderAPITextureBindHandle(
                      this: pShader,
                      nTextureVar: info->m_nBumpmap,
                      nFrameVar: info->m_nBumpFrame,
                      nTextureChannel: 0);
              **(_DWORD **)(v51 + 800) = 10;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = 11;
              *(_DWORD *)(v51 + 800) += 4;
              **(_DWORD **)(v51 + 800) = v73;
              *(_DWORD *)(v51 + 800) += 4;
              v72 = CBaseShader::GetShaderAPITextureBindHandle(
                      this: pShader,
                      nTextureVar: info->m_nBumpmap,
                      nFrameVar: info->m_nBumpFrame,
                      nTextureChannel: 0);
            }
          }
          **(_DWORD **)(v51 + 800) = 10;
          *(_DWORD *)(v51 + 800) += 4;
          **(_DWORD **)(v51 + 800) = 12;
          *(_DWORD *)(v51 + 800) += 4;
          **(_DWORD **)(v51 + 800) = v72;
          *(_DWORD *)(v51 + 800) += 4;
          goto LABEL_261;
        }
      }
    }
    bHasPhongTintMap = false;
    goto LABEL_223;
  }
  if ( *(_BYTE *)(nTessellationMode + 8) != 0 )
    goto LABEL_202;
LABEL_391:
  *(_DWORD *)&DynamicCmdsOut.m_Storage.m_Data[4] = nTessellationMode + 12;
  DynamicCmdsOut.m_Storage.m_pDataOut = &DynamicCmdsOut.m_Storage.m_Data[8];
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_Data = 2;
  if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
  {
    v137 = pShaderAPI->GetTextureRenderingParameter(this: pShaderAPI, a2: 0);
    if ( v137 != nullptr )
    {
      v138 = CBaseShader::GetShaderAPITextureBindHandle(this: pShader, pTexture: v137, nFrame: 0, nTextureChannel: 0);
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 10;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 15;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v138;
    }
    else
    {
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 9;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 15;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 4;
    }
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  }
  m_nAmbientOcclusion = info->m_nAmbientOcclusion;
  bFlashlightShadows = false;
  bUberlight = false;
  if ( m_nAmbientOcclusion == -1 )
    v140 = 0.0;
  else
    v140 = v7[m_nAmbientOcclusion]->m_VecVal.x;
  *(float *)&flAmbientOcclusionStrength = v140;
  if ( bHasFlashlight )
  {
    pShaderAPI->GetFlashlightShaderInfo(this: pShaderAPI, a2: &bFlashlightShadows, a3: &bUberlight);
    *(float *)&flAmbientOcclusionStrength = ((double (__thiscall *)(IShaderDynamicAPI *))pShaderAPI->GetFlashlightAmbientOcclusion)(a1: pShaderAPI)
                                          * v140;
  }
  pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: (float *)&vEyePos_AmbientOcclusion);
  if ( *(float *)&flAmbientOcclusionStrength >= 0.0 )
  {
    if ( *(float *)&flAmbientOcclusionStrength <= 1.0 )
      vEyePos_AmbientOcclusion.m_nHARDWAREFOGBLEND = flAmbientOcclusionStrength;
    else
      vEyePos_AmbientOcclusion.m_nHARDWAREFOGBLEND = 1065353216;
  }
  else
  {
    vEyePos_AmbientOcclusion.m_nHARDWAREFOGBLEND = 0;
  }
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 3;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 11;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = *(_QWORD *)&vEyePos_AmbientOcclusion.m_nDECAL;
  *((_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut + 1) = *(_QWORD *)&vEyePos_AmbientOcclusion.m_nDOPIXELFOG;
  GetSceneFogMode = pShaderAPI->GetSceneFogMode;
  DynamicCmdsOut.m_Storage.m_pDataOut += 16;
  v142 = GetSceneFogMode(this: pShaderAPI);
  *(float *)&flMin = COERCE_FLOAT(pShaderAPI->GetCurrentNumBones(this: pShaderAPI));
  flAmbientOcclusionStrength_3 = false;
  flMax_3b = false;
  if ( (_BYTE)nLightingPreviewMode != 0 )
  {
    flAmbientOcclusionStrength_3 = pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    flMax_3b = v142 == 2;
  }
  *(_DWORD *)&lightState.m_bAmbientLight = 0;
  LOWORD(v164) = 0;
  if ( (_BYTE)bUnusedTexCoords == 0 )
    pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: (LightState_t *)&lightState.m_bAmbientLight);
  if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
  {
    CBaseVSShader::SetHWMorphVertexShaderState(
      this: pShader,
      nDimConst: 54,
      nSubrectConst: 55,
      morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
    nLightingPreviewMode = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 0);
    if ( nLightingPreviewMode == 3 )
    {
      pShaderAPI->GetWorldSpaceCameraDirection(this: pShaderAPI, a2: vEyeDir);
      flFarZ = pShaderAPI->GetFarZ(this: pShaderAPI);
      SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
      vEyeDir[0] = (float)(1.0 / flFarZ) * vEyeDir[0];
      vEyeDir[1] = (float)(1.0 / flFarZ) * vEyeDir[1];
      vEyeDir[2] = (float)(1.0 / flFarZ) * vEyeDir[2];
      SetVertexShaderConstant(this: pShaderAPI, a2: 56, a3: vEyeDir, a4: 1, a5: false);
    }
    nTessellationMode = pShaderAPI->GetTessellationMode(this: pShaderAPI);
    if ( nTessellationMode != TESSELLATION_MODE_DISABLED )
    {
      pShaderAPI->BindStandardVertexTexture(
        this: pShaderAPI,
        a2: SHADER_VERTEXTEXTURE_SAMPLER1,
        a3: TEXTURE_SUBDIVISION_PATCHES);
      *(float *)&v166.m_nNUM_LIGHTS = 1.0
                                    / ((double (__thiscall *)(IShaderDynamicAPI *))pShaderAPI->GetSubDHeight)(a1: pShaderAPI);
      if ( bPhongHalfLambert
        && mat_displacementmap_2.m_pParent != nullptr
        && mat_displacementmap_2.m_pParent->m_Value.m_nValue != 0 )
      {
        v166.m_nWRITE_DEPTH_TO_DESTALPHA = 1065353216;
      }
      else
      {
        v166.m_nWRITE_DEPTH_TO_DESTALPHA = 0;
      }
      if ( bHasVertexAlpha
        && mat_displacementmap_2.m_pParent != nullptr
        && mat_displacementmap_2.m_pParent->m_Value.m_nValue != 0 )
      {
        v166.m_nFLASHLIGHTSHADOWS = 1065353216;
      }
      else
      {
        v166.m_nFLASHLIGHTSHADOWS = 0;
      }
      v148 = pShaderAPI->SetVertexShaderConstant;
      v166.m_nUBERLIGHT = 0;
      v148(this: pShaderAPI, a2: 57, a3: (const float *)&v166.m_nNUM_LIGHTS, a4: 1, a5: false);
      if ( bPhongHalfLambert )
        CBaseShader::BindVertexTexture(
          this: pShader,
          vtSampler: SHADER_VERTEXTEXTURE_SAMPLER2,
          nTextureVar: info->m_nDisplacementMap,
          nFrame: 0);
      else
        pShaderAPI->BindStandardVertexTexture(this: pShaderAPI, a2: SHADER_VERTEXTEXTURE_SAMPLER2, a3: TEXTURE_BLACK);
    }
    vertexlit_and_unlit_generic_bump_vs30_Dynamic_Index::vertexlit_and_unlit_generic_bump_vs30_Dynamic_Index(
      this: (phong_vs30_Dynamic_Index *)&v166.m_nPIXELFOGTYPE,
      pShaderAPI);
    v149 = (int)flMin > 0 && nTessellationMode == TESSELLATION_MODE_DISABLED;
    v166.m_nNUM_LIGHTS = v149;
    if ( g_shaderConfigDumpEnable )
    {
      v150 = (int)flMin > 0 && nTessellationMode == TESSELLATION_MODE_DISABLED;
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "SKINNING",
        v150,
        "( numBones > 0) && ( nTessellationMode == TESSELLATION_MODE_DISABLED )");
    }
    v151 = vertexCompression != VERTEX_COMPRESSION_NONE && nTessellationMode == TESSELLATION_MODE_DISABLED;
    v152 = v151;
    if ( g_shaderConfigDumpEnable )
    {
      v153 = vertexCompression != VERTEX_COMPRESSION_NONE && nTessellationMode == TESSELLATION_MODE_DISABLED;
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "COMPRESSED_VERTS",
        v153,
        "(int)vertexCompression && ( nTessellationMode == TESSELLATION_MODE_DISABLED )");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", nTessellationMode, "nTessellationMode");
    }
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: v152
    + 2 * (v166.m_nNUM_LIGHTS + 2 * (v166.m_nWRITE_DEPTH_TO_DESTALPHA + 2 * (nTessellationMode + v166.m_nUBERLIGHT))));
    phong_ps30_Dynamic_Index::phong_ps30_Dynamic_Index(this: &v166, pShaderAPI);
    v154 = nLightingPreviewMode == 0 ? *(_DWORD *)&lightState.m_bAmbientLight : 0;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        nLightingPreviewMode == 0 ? *(_DWORD *)&lightState.m_bAmbientLight : 0,
        "nLightingPreviewMode ? 0 : lightState.m_nNumLights");
    v166.m_nWRITEWATERFOGTODESTALPHA = (flMax_3b & (unsigned __int8)((nLightingPreviewMode != 0) - 1)) != 0;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITEWATERFOGTODESTALPHA",
        flMax_3b & (unsigned __int8)((nLightingPreviewMode != 0) - 1),
        "nLightingPreviewMode ? false : bWriteWaterFogToAlpha");
    v166.m_nWRITE_DEPTH_TO_DESTALPHA = flAmbientOcclusionStrength_3;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITE_DEPTH_TO_DESTALPHA",
        flAmbientOcclusionStrength_3,
        "bWriteDepthToAlpha");
    v166.m_nFLASHLIGHTSHADOWS = (bFlashlightShadows & (unsigned __int8)((nLightingPreviewMode != 0) - 1)) != 0;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "FLASHLIGHTSHADOWS",
        bFlashlightShadows & (unsigned __int8)((nLightingPreviewMode != 0) - 1),
        "nLightingPreviewMode ? false : bFlashlightShadows");
    v166.m_nUBERLIGHT = bUberlight;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "UBERLIGHT", bUberlight, "bUberlight");
    pShaderAPI->SetPixelShaderIndex(
      this: pShaderAPI,
      a2: v166.m_nWRITEWATERFOGTODESTALPHA
    + 2
    * (v166.m_nPIXELFOGTYPE
     + 2
     * (v166.m_nWRITE_DEPTH_TO_DESTALPHA
      + 2 * (v166.m_nFLASHLIGHTSHADOWS + 2 * v166.m_nUBERLIGHT)
      + v154
      + 4 * (v166.m_nWRITE_DEPTH_TO_DESTALPHA + 2 * (v166.m_nFLASHLIGHTSHADOWS + 2 * v166.m_nUBERLIGHT)))));
    IsHWMorphingEnabled = pShaderAPI->IsHWMorphingEnabled;
    LOWORD(bUnusedTexCoords) = 0;
    if ( !IsHWMorphingEnabled(this: pShaderAPI) || (BYTE2(bUnusedTexCoords) = 0, !bIsDecal) )
      BYTE2(bUnusedTexCoords) = 1;
    pShaderAPI->MarkUnusedVertexFields(this: pShaderAPI, a2: 0, a3: 3, a4: (bool *)&bUnusedTexCoords);
    pShaderAPI->SetScreenSizeForVPOS(this: pShaderAPI, a2: 32);
  }
  else
  {
    v143 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v144 = (int)flMin > 0;
    v145 = v143;
    flMin = v144;
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v144, "numBones > 0");
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", 0, "0");
      }
    }
    infoa = bUseStaticControlFlow ? nullptr : *(VertexLitGeneric_DX9_Vars_t **)&lightState.m_bAmbientLight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        bUseStaticControlFlow ? 0 : *(_DWORD *)&lightState.m_bAmbientLight,
        "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: vertexCompression + 2 * (flMin + 2 * ((_DWORD)infoa + 2 * v145 + v145)));
    phong_ps20b_Dynamic_Index::phong_ps20b_Dynamic_Index(
      this: (phong_ps20b_Dynamic_Index *)&v166.m_nPIXELFOGTYPE,
      pShaderAPI);
    v166.m_nWRITE_DEPTH_TO_DESTALPHA = *(_DWORD *)&lightState.m_bAmbientLight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        *(_DWORD *)&lightState.m_bAmbientLight,
        "lightState.m_nNumLights");
    v166.m_nPIXELFOGTYPE = flMax_3b;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "WRITEWATERFOGTODESTALPHA", flMax_3b, "bWriteWaterFogToAlpha");
    v166.m_nFLASHLIGHTSHADOWS = flAmbientOcclusionStrength_3;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITE_DEPTH_TO_DESTALPHA",
        flAmbientOcclusionStrength_3,
        "bWriteDepthToAlpha");
    v146 = bFlashlightShadows;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", bFlashlightShadows, "bFlashlightShadows");
    pShaderAPI->SetPixelShaderIndex(
      this: pShaderAPI,
      a2: v166.m_nPIXELFOGTYPE
    + 2
    * (v166.m_nNUM_LIGHTS
     + 2
     * (v166.m_nFLASHLIGHTSHADOWS
      + 2 * v146
      + v166.m_nWRITE_DEPTH_TO_DESTALPHA
      + 4 * (v166.m_nFLASHLIGHTSHADOWS + 2 * v146))));
  }
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 0;
  ExecuteCommandBuffer = pShaderAPI->ExecuteCommandBuffer;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  ExecuteCommandBuffer(this: pShaderAPI, a2: DynamicCmdsOut.m_Storage.m_Data);
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10040680
// Name: public: phong_ps20b_Dynamic_Index::phong_ps20b_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
phong_ps20b_Dynamic_Index *__thiscall phong_ps20b_Dynamic_Index::phong_ps20b_Dynamic_Index(
        phong_ps20b_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nWRITEWATERFOGTODESTALPHA = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nNUM_LIGHTS = 0;
  this->m_nWRITE_DEPTH_TO_DESTALPHA = 0;
  this->m_nFLASHLIGHTSHADOWS = 0;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}
