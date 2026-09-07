// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/worldtwotextureblend.cpp
// Functions: 26
// ============================================================

#include "materialsystem\stdshaders\worldtwotextureblend.h"

//------------------------------------------------------------------------------
// Address: 0x10044FB0
// Name: public: lightmappedgeneric_vs30_Static_Index::lightmappedgeneric_vs30_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
lightmappedgeneric_vs30_Static_Index *__thiscall lightmappedgeneric_vs30_Static_Index::lightmappedgeneric_vs30_Static_Index(
        lightmappedgeneric_vs30_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
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
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 || (*params)->m_intVal < 0 )
  {
    this->m_nHARDWAREFOGBLEND = 0;
    this->m_nDOPIXELFOG = 0;
    return this;
  }
  else
  {
    this->m_nHARDWAREFOGBLEND = 0;
    this->m_nDOPIXELFOG = 1;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045080
// Name: public: virtual void WorldTwoTextureBlend::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorldTwoTextureBlend::CShader::OnInitShaderParams(
        WorldTwoTextureBlend::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  IMaterialVar *v3; // ebx
  IMaterialVar_vtbl *v4; // edi
  const char *v5; // eax
  int m_Index; // edi

  if ( !params[DETAIL_ALPHA_MASK_BASE_TEXTURE.m_Index]->IsDefined(this: params[DETAIL_ALPHA_MASK_BASE_TEXTURE.m_Index]) )
    params[DETAIL_ALPHA_MASK_BASE_TEXTURE.m_Index]->SetIntValue(
      this: params[DETAIL_ALPHA_MASK_BASE_TEXTURE.m_Index],
      a2: 0);
  params[9]->SetStringValue(this: params[9], a2: "effects/flashlight001");
  if ( (g_pConfig->m_Flags & 0x100) == 0
    && params[BUMPMAP_10.m_Index]->IsDefined(this: params[BUMPMAP_10.m_Index])
    && params[ALBEDO_3.m_Index]->IsDefined(this: params[ALBEDO_3.m_Index])
    && params[BASETEXTURE_0.m_Index]->IsDefined(this: params[BASETEXTURE_0.m_Index])
    && (!params[NODIFFUSEBUMPLIGHTING_0.m_Index]->IsDefined(this: params[NODIFFUSEBUMPLIGHTING_0.m_Index])
     || params[NODIFFUSEBUMPLIGHTING_0.m_Index]->m_intVal == 0) )
  {
    v3 = params[BASETEXTURE_0.m_Index];
    v4 = v3->__vftable;
    v5 = params[ALBEDO_3.m_Index]->GetStringValue(this: params[ALBEDO_3.m_Index]);
    v4->SetStringValue(this: v3, a2: v5);
  }
  if ( !params[NODIFFUSEBUMPLIGHTING_0.m_Index]->IsDefined(this: params[NODIFFUSEBUMPLIGHTING_0.m_Index]) )
    params[NODIFFUSEBUMPLIGHTING_0.m_Index]->SetIntValue(this: params[NODIFFUSEBUMPLIGHTING_0.m_Index], a2: 0);
  if ( !params[SELFILLUMTINT_3.m_Index]->IsDefined(this: params[SELFILLUMTINT_3.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, int, int, int))params[SELFILLUMTINT_3.m_Index]->SetVecValue_2)(
      a1: params[SELFILLUMTINT_3.m_Index],
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216);
  if ( !params[DETAILSCALE_4.m_Index]->IsDefined(this: params[DETAILSCALE_4.m_Index]) )
    ((void (__stdcall *)(int))params[DETAILSCALE_4.m_Index]->SetFloatValue)(a1: 1082130432);
  if ( !params[BUMPFRAME_14.m_Index]->IsDefined(this: params[BUMPFRAME_14.m_Index]) )
    params[BUMPFRAME_14.m_Index]->SetIntValue(this: params[BUMPFRAME_14.m_Index], a2: 0);
  if ( !params[DETAILFRAME_3.m_Index]->IsDefined(this: params[DETAILFRAME_3.m_Index]) )
    params[DETAILFRAME_3.m_Index]->SetIntValue(this: params[DETAILFRAME_3.m_Index], a2: 0);
  if ( !params[BASETEXTURE_0.m_Index]->IsDefined(this: params[BASETEXTURE_0.m_Index]) )
  {
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFFFFFBF);
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
  }
  if ( ((*params)->m_intVal & 0x10000) != 0 )
    (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal | 2);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 4);
  if ( (g_pConfig->m_Flags & 0x100) == 0
    && params[BUMPMAP_10.m_Index]->IsDefined(this: params[BUMPMAP_10.m_Index])
    && params[NODIFFUSEBUMPLIGHTING_0.m_Index]->m_intVal == 0 )
  {
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 8);
  }
  if ( SHADERSRGBREAD360_4.m_Index != -1 )
  {
    m_Index = SHADERSRGBREAD360_4.m_Index;
    if ( !params[SHADERSRGBREAD360_4.m_Index]->IsDefined(this: params[SHADERSRGBREAD360_4.m_Index]) )
      params[m_Index]->SetIntValue(this: params[m_Index], a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045320
// Name: public: virtual char const __near * WorldTwoTextureBlend::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall WorldTwoTextureBlend::CShader::GetName(WorldTwoTextureBlend::CShader *this)
{
  return s_Name_135;
}

//------------------------------------------------------------------------------
// Address: 0x10045330
// Name: public: virtual int WorldTwoTextureBlend::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WorldTwoTextureBlend::CShader::GetFlags(WorldTwoTextureBlend::CShader *this)
{
  return s_nFlags_137;
}

//------------------------------------------------------------------------------
// Address: 0x10045340
// Name: public: virtual void WorldTwoTextureBlend::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorldTwoTextureBlend::CShader::OnInitShaderInstance(
        WorldTwoTextureBlend::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  int v5; // eax
  int m_intVal; // eax

  if ( (g_pConfig->m_Flags & 0x100) == 0 && params[BUMPMAP_10.m_Index]->IsDefined(this: params[BUMPMAP_10.m_Index]) )
    CBaseShader::LoadBumpMap(this, nTextureVar: BUMPMAP_10.m_Index, nAdditionalCreationFlags: 0);
  if ( params[BASETEXTURE_0.m_Index]->IsDefined(this: params[BASETEXTURE_0.m_Index]) )
  {
    CBaseShader::LoadTexture(this, nTextureVar: BASETEXTURE_0.m_Index, nAdditionalCreationFlags: 0x80000);
    v5 = params[BASETEXTURE_0.m_Index]->GetTextureValue(this: params[BASETEXTURE_0.m_Index]);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 24))(a1: v5) == 0 )
    {
      ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFFFFFBF);
      ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
    }
  }
  if ( params[DETAIL_4.m_Index]->IsDefined(this: params[DETAIL_4.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: DETAIL_4.m_Index, nAdditionalCreationFlags: 0);
  CBaseShader::LoadTexture(this, nTextureVar: 9, nAdditionalCreationFlags: 0x80000);
  m_intVal = (*params)->m_intVal;
  if ( (m_intVal & 0x40) != 0 || (m_intVal & 0x100000) != 0 )
    (*params)->SetIntValue(this: *params, a2: m_intVal & 0xFFFFFEFF);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
}

//------------------------------------------------------------------------------
// Address: 0x10045470
// Name: public: void WorldTwoTextureBlend::CShader::DrawPass(class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,bool,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorldTwoTextureBlend::CShader::DrawPass(
        WorldTwoTextureBlend::CShader *this,
        IMaterialVar **params,
        float pShaderAPI,
        float pShaderShadow,
        bool hasFlashlight,
        VertexCompressionType_t vertexCompression)
{
  char v7; // dl
  bool v8; // zf
  char v9; // al
  IMaterialVar *v10; // edx
  int m_intVal; // eax
  BlendType_t v12; // eax
  unsigned int v13; // ecx
  IShaderShadow *v14; // edi
  void (__thiscall *v15)(IShaderShadow *, bool); // edx
  int v16; // eax
  IShaderShadow_vtbl *v17; // ebx
  HDRType_t v18; // eax
  int v19; // ebx
  int v20; // eax
  IShaderShadow_vtbl *v21; // eax
  IMaterialSystemHardwareConfig_vtbl *v22; // eax
  bool v23; // bl
  IShaderShadow v24; // esi
  int Index; // eax
  int v26; // esi
  IShaderShadow v27; // ebx
  int v28; // eax
  BOOL v29; // ebx
  BOOL v30; // ebx
  BOOL v31; // ebx
  CBaseShader *v32; // esi
  float v33; // ebx
  int v34; // esi
  int v35; // eax
  FlashlightState_t *v36; // esi
  float m_fValue; // xmm0_4
  bool (__thiscall *GetHDREnabled)(IMaterialSystemHardwareConfig *); // eax
  bool v39; // al
  float v40; // xmm0_4
  float v41; // xmm0_4
  void (__thiscall *v42)(_DWORD, int, float *, int, _DWORD); // edx
  CBaseVSShader *v43; // edi
  bool v44; // al
  char v45; // al
  MaterialFogMode_t v46; // eax
  int v47; // edx
  void (__thiscall *v48)(_DWORD, int, float *, int, _DWORD); // edx
  BOOL v49; // esi
  BOOL v50; // edi
  char v51; // al
  MaterialFogMode_t v52; // edi
  BOOL v53; // edi
  int v54; // esi
  bool v55; // cc
  int (__thiscall *v56)(_DWORD); // edx
  BOOL v57; // edi
  int v58; // eax
  bool v59; // al
  BOOL v60; // eax
  void (__thiscall *v61)(_DWORD, int, float *, int, _DWORD); // edx
  int v62; // esi
  void (__thiscall *v63)(_DWORD, int, float *, int, _DWORD); // edx
  void (__thiscall *v64)(_DWORD, int, float *, int, _DWORD); // edx
  float v65; // eax
  int v66; // edx
  void (__thiscall *v67)(_DWORD, int, float *, int, _DWORD); // edx
  __int64 v68; // xmm0_8
  const char *v69; // [esp-8h] [ebp-2ACh]
  __int32 v70; // [esp-4h] [ebp-2A8h]
  matrix3x4_t matrix; // [esp+108h] [ebp-19Ch] BYREF
  VMatrix worldToTexture; // [esp+138h] [ebp-16Ch] BYREF
  float eyePos[4]; // [esp+178h] [ebp-12Ch] BYREF
  float v76[4]; // [esp+188h] [ebp-11Ch] BYREF
  float atten[4]; // [esp+198h] [ebp-10Ch] BYREF
  __int64 v78; // [esp+1A8h] [ebp-FCh] BYREF
  float v79; // [esp+1B0h] [ebp-F4h]
  float v80; // [esp+1B4h] [ebp-F0h]
  float v81[4]; // [esp+1B8h] [ebp-ECh] BYREF
  float v82[4]; // [esp+1C8h] [ebp-DCh] BYREF
  float pos[4]; // [esp+1D8h] [ebp-CCh] BYREF
  __int64 v84; // [esp+1E8h] [ebp-BCh]
  __int64 v85; // [esp+1F0h] [ebp-B4h]
  __int64 v86; // [esp+1F8h] [ebp-ACh]
  __int64 v87; // [esp+200h] [ebp-A4h]
  __int64 v88; // [esp+208h] [ebp-9Ch]
  float v89; // [esp+210h] [ebp-94h]
  lightmappedgeneric_vs20_Static_Index _vshIndex; // [esp+214h] [ebp-90h] BYREF
  worldtwotextureblend_ps20b_Dynamic_Index _pshIndex; // [esp+24Ch] [ebp-58h] BYREF
  float v92; // [esp+25Ch] [ebp-48h]
  BlendType_t nBlendType; // [esp+260h] [ebp-44h]
  BOOL bFullyOpaque; // [esp+264h] [ebp-40h]
  BOOL bIsAlphaTested; // [esp+268h] [ebp-3Ch]
  int v96; // [esp+26Ch] [ebp-38h]
  BOOL v97; // [esp+270h] [ebp-34h]
  BOOL v98; // [esp+274h] [ebp-30h]
  BOOL v99; // [esp+278h] [ebp-2Ch]
  BOOL v100; // [esp+27Ch] [ebp-28h]
  ShadowFilterMode_t nShadowFilterMode; // [esp+280h] [ebp-24h]
  MaterialFogMode_t fogType; // [esp+284h] [ebp-20h]
  float map_scale[4]; // [esp+288h] [ebp-1Ch] BYREF
  CBaseShader *v104; // [esp+298h] [ebp-Ch]
  bool bHasDetailAlpha; // [esp+29Eh] [ebp-6h]
  bool bUberlight; // [esp+29Fh] [ebp-5h]
  bool hasDetailTexture; // [esp+2A0h] [ebp-4h]
  bool bSeamlessMapping; // [esp+2A1h] [ebp-3h]
  bool hasBump; // [esp+2A2h] [ebp-2h]
  bool bFlashlightShadows; // [esp+2A3h] [ebp-1h]
  FlashlightState_t state; // 0:^28.252

  v104 = this;
  v7 = *((_BYTE *)params[BASETEXTURE_0.m_Index] + 28);
  hasBump = (*((_BYTE *)params[BUMPMAP_10.m_Index] + 28) & 0xF) == 3;
  v8 = (v7 & 0xF) == 3;
  v9 = *((_BYTE *)params[DETAIL_4.m_Index] + 28);
  v10 = *params;
  bUberlight = v8;
  v8 = (v9 & 0xF) == 3;
  m_intVal = v10->m_intVal;
  hasDetailTexture = v8;
  bFlashlightShadows = (m_intVal & 0x10) != 0;
  bHasDetailAlpha = params[DETAIL_ALPHA_MASK_BASE_TEXTURE.m_Index]->m_intVal != 0;
  LOBYTE(bIsAlphaTested) = BYTE1(m_intVal) & 1;
  v12 = CBaseVSShader::EvaluateBlendRequirements(
          this,
          textureVar: BASETEXTURE_0.m_Index,
          isBaseTexture: true,
          detailTextureVar: -1);
  nBlendType = v12;
  if ( v12 == BT_BLENDADD
    || v12 == BT_BLEND
    || (v13 = (unsigned int)(*params)->m_intVal >> 8, LOBYTE(bFullyOpaque) = 1, (v13 & 1) != 0) )
  {
    LOBYTE(bFullyOpaque) = 0;
  }
  bSeamlessMapping = params[SEAMLESS_SCALE_1.m_Index]->m_VecVal.x != 0.0;
  v14 = (IShaderShadow *)LODWORD(pShaderShadow);
  if ( pShaderShadow != 0.0 )
  {
    v15 = *(void (__thiscall **)(IShaderShadow *, bool))(*(_DWORD *)LODWORD(pShaderShadow) + 48);
    nShadowFilterMode = SHADOWFILTERMODE_DEFAULT;
    v15(this: (IShaderShadow *)LODWORD(pShaderShadow), a2: bIsAlphaTested);
    if ( hasFlashlight )
    {
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
      {
        v16 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *))g_pHardwareConfig->HasFastVertexTextures)(a1: g_pHardwareConfig);
        LOBYTE(v16) = (_BYTE)v16 != 0;
        nShadowFilterMode = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: v16);
      }
      CBaseShader::SetAdditiveBlendingShadowState(this, textureVar: BASETEXTURE_0.m_Index, isBaseTexture: true);
      v14->EnableDepthWrites(this: v14, a2: false);
      v14->EnableAlphaWrites(this: v14, a2: false);
    }
    else
    {
      CBaseShader::SetDefaultBlendingShadowState(this, textureVar: BASETEXTURE_0.m_Index, isBaseTexture: true);
    }
    LODWORD(pShaderShadow) = 1;
    if ( bUberlight )
    {
      v14->EnableTexture(this: v14, a2: SHADER_SAMPLER0, a3: true);
      v14->EnableSRGBRead(this: v14, a2: SHADER_SAMPLER0, a3: true);
    }
    v14->EnableTexture(this: v14, a2: SHADER_SAMPLER1, a3: true);
    v17 = v14->__vftable;
    v18 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
    v17->EnableSRGBRead(this: v14, a2: SHADER_SAMPLER1, a3: v18 == HDR_TYPE_NONE);
    if ( hasFlashlight )
    {
      v14->EnableTexture(this: v14, a2: SHADER_SAMPLER2, a3: true);
      v14->EnableTexture(this: v14, a2: SHADER_SAMPLER7, a3: true);
      v19 = 51;
    }
    else
    {
      v19 = LODWORD(pShaderShadow);
    }
    if ( hasDetailTexture )
      v14->EnableTexture(this: v14, a2: SHADER_SAMPLER3, a3: true);
    if ( hasBump )
      v14->EnableTexture(this: v14, a2: SHADER_SAMPLER4, a3: true);
    if ( bFlashlightShadows )
      v19 |= 4u;
    v14->EnableTexture(this: v14, a2: SHADER_SAMPLER6, a3: true);
    v20 = 2;
    if ( hasBump )
      v20 = 3;
    v14->VertexShaderVertexFormat(this: v14, a2: v19, a3: v20, a4: nullptr, a5: 0);
    v21 = v14->__vftable;
    HIBYTE(pShaderShadow) = ((*params)->m_intVal & 0x40) != 0;
    v21->EnableSRGBWrite(this: v14, a2: true);
    v22 = g_pHardwareConfig->__vftable;
    fogType = ((params[2]->m_intVal & 0x100000) != 0) + 2 * ((params[2]->m_intVal & 0x200000) != 0);
    if ( v22->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      lightmappedgeneric_vs30_Static_Index::lightmappedgeneric_vs30_Static_Index(
        this: (lightmappedgeneric_vs30_Static_Index *)&_vshIndex,
        pShaderShadow: v14,
        params);
      _vshIndex.m_nENVMAP_MASK = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "ENVMAP_MASK", 0, "false");
      _vshIndex.m_nBUMPMASK = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMASK", 0, "false");
      v96 = hasFlashlight;
      _vshIndex.m_nTANGENTSPACE = v96;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TANGENTSPACE", hasFlashlight, "hasFlashlight");
      v100 = hasBump;
      _vshIndex.m_nBUMPMAP = v100;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMAP", hasBump, "hasBump");
      v98 = bFlashlightShadows;
      _vshIndex.m_nVERTEXCOLOR = v98;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", bFlashlightShadows, "hasVertexColor");
      _vshIndex.m_nVERTEXALPHATEXBLENDFACTOR = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXALPHATEXBLENDFACTOR", 0, "false");
      v97 = bSeamlessMapping;
      _vshIndex.m_nSEAMLESS = v97;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS", bSeamlessMapping, "bSeamlessMapping");
      v23 = hasDetailTexture;
      v99 = hasDetailTexture;
      _vshIndex.m_nDETAILTEXTURE = v99;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DETAILTEXTURE", hasDetailTexture, "hasDetailTexture");
      LODWORD(map_scale[3]) = HIBYTE(pShaderShadow) != 0;
      *(float *)&_vshIndex.m_nSELFILLUM = map_scale[3];
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SELFILLUM", HIBYTE(pShaderShadow), "hasSelfIllum");
      _vshIndex.m_nFANCY_BLENDING = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FANCY_BLENDING", 0, "false");
      _vshIndex.m_nLIGHTING_PREVIEW = fogType != MATERIAL_FOG_NONE;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "LIGHTING_PREVIEW",
          fogType != MATERIAL_FOG_NONE,
          "nLightingPreviewMode != 0");
      _vshIndex.m_nPAINT = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "PAINT", 0, "0");
      v24.__vftable = v14->__vftable;
      Index = lightmappedgeneric_vs20_Static_Index::GetIndex(this: &_vshIndex);
      v24.SetVertexShader(this: v14, a2: "lightmappedgeneric_vs30", a3: Index);
      v26 = LODWORD(map_scale[3]);
    }
    else
    {
      lightmappedgeneric_vs20_Static_Index::lightmappedgeneric_vs20_Static_Index(
        this: &_vshIndex,
        pShaderShadow: v14,
        params);
      _vshIndex.m_nENVMAP_MASK = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "ENVMAP_MASK", 0, "false");
      _vshIndex.m_nBUMPMASK = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMASK", 0, "false");
      v96 = hasFlashlight;
      _vshIndex.m_nTANGENTSPACE = v96;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TANGENTSPACE", hasFlashlight, "hasFlashlight");
      v100 = hasBump;
      _vshIndex.m_nBUMPMAP = v100;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "BUMPMAP", hasBump, "hasBump");
      v98 = bFlashlightShadows;
      _vshIndex.m_nVERTEXCOLOR = v98;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", bFlashlightShadows, "hasVertexColor");
      _vshIndex.m_nVERTEXALPHATEXBLENDFACTOR = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXALPHATEXBLENDFACTOR", 0, "false");
      v97 = bSeamlessMapping;
      _vshIndex.m_nSEAMLESS = v97;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS", bSeamlessMapping, "bSeamlessMapping");
      v99 = hasDetailTexture;
      _vshIndex.m_nDETAILTEXTURE = v99;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "DETAILTEXTURE", hasDetailTexture, "hasDetailTexture");
      v26 = HIBYTE(pShaderShadow) != 0;
      _vshIndex.m_nSELFILLUM = v26;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "SELFILLUM", HIBYTE(pShaderShadow), "hasSelfIllum");
      _vshIndex.m_nFANCY_BLENDING = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FANCY_BLENDING", 0, "false");
      _vshIndex.m_nLIGHTING_PREVIEW = fogType != MATERIAL_FOG_NONE;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "LIGHTING_PREVIEW",
          fogType != MATERIAL_FOG_NONE,
          "nLightingPreviewMode != 0");
      _vshIndex.m_nPAINT = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "PAINT", 0, "0");
      v27.__vftable = v14->__vftable;
      v28 = lightmappedgeneric_vs20_Static_Index::GetIndex(this: &_vshIndex);
      v27.SetVertexShader(this: v14, a2: "lightmappedgeneric_vs20", a3: v28);
      v23 = hasDetailTexture;
    }
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", v23, "hasDetailTexture");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", hasBump, "hasBump");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", bFlashlightShadows, "hasVertexColor");
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", HIBYTE(pShaderShadow), "hasSelfIllum");
          }
        }
      }
      v29 = bHasDetailAlpha;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "DETAIL_ALPHA_MASK_BASE_TEXTURE",
          bHasDetailAlpha,
          "bHasDetailAlpha");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", hasFlashlight, "hasFlashlight");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", bSeamlessMapping, "bSeamlessMapping");
            if ( g_shaderConfigDumpEnable )
            {
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "FLASHLIGHTDEPTHFILTERMODE",
                nShadowFilterMode,
                "nShadowFilterMode");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
            }
          }
        }
      }
      v14->SetPixelShader(
        this: v14,
        a2: "worldtwotextureblend_ps30",
        a3: 32 * (v99 + 2 * (v100 + 2 * (v98 + 2 * (v26 + 2 * (v29 + 2 * (v96 + 2 * (v97 + 2 * nShadowFilterMode))))))));
    }
    else
    {
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", v23, "hasDetailTexture");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", hasBump, "hasBump");
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", bFlashlightShadows, "hasVertexColor");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", HIBYTE(pShaderShadow), "hasSelfIllum");
            }
          }
        }
        v31 = bHasDetailAlpha;
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "DETAIL_ALPHA_MASK_BASE_TEXTURE",
            bHasDetailAlpha,
            "bHasDetailAlpha");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", hasFlashlight, "hasFlashlight");
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", bSeamlessMapping, "bSeamlessMapping");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
            }
          }
        }
        v70 = 4 * (v99 + 2 * (v100 + 2 * (v98 + 2 * (v26 + 2 * (v31 + 2 * (v96 + 2 * v97))))));
        v69 = "worldtwotextureblend_ps20";
      }
      else
      {
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", v23, "hasDetailTexture");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "BUMPMAP", hasBump, "hasBump");
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", bFlashlightShadows, "hasVertexColor");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", HIBYTE(pShaderShadow), "hasSelfIllum");
            }
          }
        }
        v30 = bHasDetailAlpha;
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "DETAIL_ALPHA_MASK_BASE_TEXTURE",
            bHasDetailAlpha,
            "bHasDetailAlpha");
          if ( g_shaderConfigDumpEnable )
          {
            printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", hasFlashlight, "hasFlashlight");
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", bSeamlessMapping, "bSeamlessMapping");
              if ( g_shaderConfigDumpEnable )
              {
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "FLASHLIGHTDEPTHFILTERMODE",
                  nShadowFilterMode,
                  "nShadowFilterMode");
                if ( g_shaderConfigDumpEnable )
                  printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
              }
            }
          }
        }
        v70 = 16
            * (v99 + 2 * (v100 + 2 * (v98 + 2 * (v26 + 2 * (v30 + 2 * (v96 + 2 * (v97 + 2 * nShadowFilterMode)))))));
        v69 = "worldtwotextureblend_ps20b";
      }
      v14->SetPixelShader(this: v14, a2: v69, a3: v70);
    }
    v14->EnableAlphaWrites(this: v14, a2: bFullyOpaque);
    v32 = v104;
    if ( hasFlashlight )
      CBaseShader::FogToBlack(this: v104);
    else
      CBaseShader::DefaultFog(this: v104);
    CBaseShader::PI_BeginCommandBuffer(this: v32);
    CBaseShader::PI_SetModulationVertexShaderDynamicState(this: v32);
    CBaseShader::PI_EndCommandBuffer(this: v32);
  }
  v33 = pShaderAPI;
  if ( pShaderAPI != 0.0 )
  {
    if ( bUberlight )
      CBaseShader::BindTexture(
        this: v104,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: BASETEXTURE_0.m_Index,
        nFrameVar: 7);
    else
      (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, int))(*(_DWORD *)LODWORD(pShaderAPI) + 84))(
        a1: LODWORD(pShaderAPI),
        a2: 0,
        a3: 0x80000000,
        a4: 4);
    v34 = *(_DWORD *)LODWORD(v33);
    v35 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, _DWORD))g_pHardwareConfig->GetHDRType)(
            a1: g_pHardwareConfig,
            a2: 0);
    (*(void (__thiscall **)(float, int, unsigned int))(v34 + 84))(
      a1: COERCE_FLOAT(LODWORD(v33)),
      a2: 1,
      a3: v35 != 0 ? 0 : 0x80000000);
    bFlashlightShadows = false;
    bUberlight = false;
    if ( hasFlashlight )
    {
      v36 = (FlashlightState_t *)(*(int (__thiscall **)(float, VMatrix *, float *))(*(_DWORD *)LODWORD(v33) + 124))(
                                   a1: COERCE_FLOAT(LODWORD(v33)),
                                   a2: &worldToTexture,
                                   a3: &pShaderAPI);
      m_fValue = r_flashlightbrightness.m_pParent->m_Value.m_fValue;
      state = *v36;
      bFlashlightShadows = state.m_bEnableShadows;
      bUberlight = state.m_bUberlight;
      GetHDREnabled = g_pHardwareConfig->GetHDREnabled;
      pShaderShadow = m_fValue;
      if ( !GetHDREnabled(this: g_pHardwareConfig) )
        pShaderShadow = 2.0;
      v39 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
      v40 = pShaderShadow;
      if ( v39 )
        v40 = pShaderShadow * 2.5;
      v41 = v40 * state.m_fBrightnessScale;
      v42 = *(void (__thiscall **)(_DWORD, int, float *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20);
      map_scale[0] = v41 * state.m_Color[0];
      map_scale[2] = v41 * state.m_Color[2];
      map_scale[1] = v41 * state.m_Color[1];
      map_scale[3] = 0.0;
      v42(a1: LODWORD(v33), a2: 28, a3: map_scale, a4: 1, a5: 0);
      CBaseShader::BindTexture(
        this: v104,
        sampler1: SHADER_SAMPLER2,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        pTexture: state.m_pSpotlightTexture,
        nFrame: state.m_nSpotlightTextureFrame);
      if ( pShaderAPI != 0.0 && g_pConfig->m_bShadowDepthTexture )
        CBaseShader::BindTexture(
          this: v104,
          sampler1: SHADER_SAMPLER7,
          nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
          pTexture: (ITexture *)LODWORD(pShaderAPI),
          nFrame: 0);
    }
    if ( hasDetailTexture )
      CBaseShader::BindTexture(
        this: v104,
        sampler1: SHADER_SAMPLER3,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: DETAIL_4.m_Index,
        nFrameVar: DETAILFRAME_3.m_Index);
    v43 = (CBaseVSShader *)v104;
    if ( hasBump )
    {
      if ( g_pConfig->m_bFastNoBump )
        (*(void (__thiscall **)(float, int, _DWORD, int))(*(_DWORD *)LODWORD(v33) + 84))(
          a1: COERCE_FLOAT(LODWORD(v33)),
          a2: 4,
          a3: 0,
          a4: 9);
      else
        CBaseShader::BindTexture(
          this: v104,
          sampler1: SHADER_SAMPLER4,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: BUMPMAP_10.m_Index,
          nFrameVar: BUMPFRAME_14.m_Index);
    }
    (*(void (__thiscall **)(float, int, _DWORD, int))(*(_DWORD *)LODWORD(v33) + 84))(
      a1: COERCE_FLOAT(LODWORD(v33)),
      a2: 6,
      a3: 0,
      a4: 12);
    v44 = !params[8]->MatrixIsIdentity(this: params[8])
       || !params[BUMPTRANSFORM_8.m_Index]->MatrixIsIdentity(this: params[BUMPTRANSFORM_8.m_Index]);
    v8 = !v44;
    v45 = *((_BYTE *)params[DETAIL_4.m_Index] + 28);
    HIBYTE(pShaderShadow) = v8;
    if ( (v45 & 0xF) == 3 )
      HIBYTE(pShaderShadow) = 0;
    if ( (*(int (__thiscall **)(float, _DWORD))(*(_DWORD *)LODWORD(v33) + 116))(a1: COERCE_FLOAT(LODWORD(v33)), a2: 0) != 0 )
    {
      HIBYTE(pShaderShadow) = 0;
    }
    else if ( HIBYTE(pShaderShadow) != 0 )
    {
LABEL_149:
      v46 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v33) + 8))(a1: COERCE_FLOAT(LODWORD(v33)));
      v47 = *(_DWORD *)LODWORD(v33);
      fogType = v46;
      if ( (*(int (__thiscall **)(float, _DWORD))(v47 + 116))(a1: COERCE_FLOAT(LODWORD(v33)), a2: 0) == 3 )
      {
        (*(void (__thiscall **)(float, float *))(*(_DWORD *)LODWORD(v33) + 32))(
          a1: COERCE_FLOAT(LODWORD(v33)),
          a2: map_scale);
        pShaderAPI = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v33) + 212))(a1: LODWORD(v33));
        v48 = *(void (__thiscall **)(_DWORD, int, float *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 16);
        map_scale[0] = (float)(1.0 / pShaderAPI) * map_scale[0];
        map_scale[1] = (float)(1.0 / pShaderAPI) * map_scale[1];
        map_scale[2] = (float)(1.0 / pShaderAPI) * map_scale[2];
        v48(a1: LODWORD(v33), a2: 12, a3: map_scale, a4: 1, a5: 0);
      }
      g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig);
      v49 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v33) + 8))(a1: COERCE_FLOAT(LODWORD(v33))) == 2;
      v50 = HIBYTE(pShaderShadow) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "FASTPATH", HIBYTE(pShaderShadow), "bVertexShaderFastPath");
      (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v33) + 44))(
        a1: COERCE_FLOAT(LODWORD(v33)),
        a2: v50 + 2 * v49);
      if ( bFullyOpaque )
      {
        v51 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v33) + 164))(a1: COERCE_FLOAT(LODWORD(v33)));
        v52 = fogType;
        HIBYTE(pShaderAPI) = v51;
        HIBYTE(pShaderShadow) = fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      }
      else
      {
        v52 = fogType;
        HIBYTE(pShaderAPI) = 0;
        HIBYTE(pShaderShadow) = 0;
      }
      if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
      {
        _pshIndex.m_nPIXELFOGTYPE = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v33) + 8))(a1: COERCE_FLOAT(LODWORD(v33))) == 2;
        _pshIndex.m_nWRITEWATERFOGTODESTALPHA = HIBYTE(pShaderShadow) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            HIBYTE(pShaderShadow),
            "bWriteWaterFogToAlpha");
        _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA = HIBYTE(pShaderAPI) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITE_DEPTH_TO_DESTALPHA",
            HIBYTE(pShaderAPI),
            "bWriteDepthToAlpha");
        v53 = bFlashlightShadows;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", bFlashlightShadows, "bFlashlightShadows");
        v54 = bUberlight;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "UBERLIGHT", bUberlight, "bUberlight");
        (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v33) + 48))(
          a1: COERCE_FLOAT(LODWORD(v33)),
          a2: _pshIndex.m_nWRITEWATERFOGTODESTALPHA
        + 2 * (_pshIndex.m_nPIXELFOGTYPE + 2 * (_pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA + 2 * (v53 + 2 * v54))));
      }
      else
      {
        v55 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
        v56 = *(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(v33) + 8);
        if ( v55 )
        {
          v58 = v56(a1: LODWORD(v33));
          v54 = nBlendType;
          LODWORD(map_scale[3]) = v58 == 2;
          v59 = v52 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z
             && nBlendType != BT_BLENDADD
             && nBlendType != BT_BLEND
             && !bIsAlphaTested;
          LODWORD(map_scale[2]) = v59;
          if ( g_shaderConfigDumpEnable )
          {
            v60 = v52 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z
               && nBlendType != BT_BLENDADD
               && nBlendType != BT_BLEND
               && !bIsAlphaTested;
            printf(
              format: "\n   PS dyn  var %s = %d (%s)",
              "WRITEWATERFOGTODESTALPHA",
              v60,
              "(fogType == MATERIAL_FOG_LINEAR_BELOW_FOG_Z) && (nBlendType != BT_BLENDADD) && (nBlendType != BT_BLEND) &&"
              " !bIsAlphaTested");
          }
          (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v33) + 48))(
            a1: COERCE_FLOAT(LODWORD(v33)),
            a2: LODWORD(map_scale[2]) + 2 * LODWORD(map_scale[3]));
        }
        else
        {
          v57 = v56(a1: LODWORD(v33)) == 2;
          _pshIndex.m_nPIXELFOGTYPE = HIBYTE(pShaderShadow) != 0;
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS dyn  var %s = %d (%s)",
              "WRITEWATERFOGTODESTALPHA",
              HIBYTE(pShaderShadow),
              "bWriteWaterFogToAlpha");
          _pshIndex.m_nFLASHLIGHTSHADOWS = HIBYTE(pShaderAPI) != 0;
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS dyn  var %s = %d (%s)",
              "WRITE_DEPTH_TO_DESTALPHA",
              HIBYTE(pShaderAPI),
              "bWriteDepthToAlpha");
          v54 = bFlashlightShadows;
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS dyn  var %s = %d (%s)",
              "FLASHLIGHTSHADOWS",
              bFlashlightShadows,
              "bFlashlightShadows");
          (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v33) + 48))(
            a1: COERCE_FLOAT(LODWORD(v33)),
            a2: _pshIndex.m_nPIXELFOGTYPE + 2 * (v57 + 2 * (_pshIndex.m_nFLASHLIGHTSHADOWS + 2 * v54)));
        }
      }
      if ( hasDetailTexture )
        CBaseVSShader::SetVertexShaderTextureScaledTransform(
          this: (CBaseVSShader *)v104,
          a2: v54,
          vertexReg: 50,
          transformVar: 8,
          scaleVar: DETAILSCALE_4.m_Index);
      CBaseVSShader::SetPixelShaderConstantGammaToLinear(
        this: (CBaseVSShader *)v104,
        pixelReg: 7,
        constantVar: SELFILLUMTINT_3.m_Index);
      (*(void (__thiscall **)(float, float *))(*(_DWORD *)LODWORD(v33) + 28))(
        a1: COERCE_FLOAT(LODWORD(v33)),
        a2: eyePos);
      (*(void (__thiscall **)(float, int, float *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20))(
        a1: COERCE_FLOAT(LODWORD(v33)),
        a2: 10,
        a3: eyePos,
        a4: 1,
        a5: 0);
      (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v33) + 68))(a1: COERCE_FLOAT(LODWORD(v33)), a2: 11);
      if ( bSeamlessMapping )
      {
        v61 = *(void (__thiscall **)(_DWORD, int, float *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 16);
        map_scale[0] = params[SEAMLESS_SCALE_1.m_Index]->m_VecVal.x;
        memset(&map_scale[1], 0, 12);
        v61(a1: LODWORD(v33), a2: 48, a3: map_scale, a4: 1, a5: 0);
      }
      if ( hasFlashlight )
      {
        v62 = (*(int (__thiscall **)(float, VMatrix *))(*(_DWORD *)LODWORD(v33) + 76))(
                a1: COERCE_FLOAT(LODWORD(v33)),
                a2: &worldToTexture);
        v63 = *(void (__thiscall **)(_DWORD, int, float *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20);
        atten[0] = *(float *)(v62 + 72);
        atten[1] = *(float *)(v62 + 68);
        atten[2] = *(float *)(v62 + 64);
        atten[3] = *(float *)(v62 + 76);
        v63(a1: LODWORD(v33), a2: 20, a3: atten, a4: 1, a5: 0);
        v64 = *(void (__thiscall **)(_DWORD, int, float *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20);
        pos[0] = *(float *)v62;
        pos[1] = *(float *)(v62 + 4);
        pos[2] = *(float *)(v62 + 8);
        pos[3] = *(float *)(v62 + 32);
        v64(a1: LODWORD(v33), a2: 15, a3: pos, a4: 1, a5: 0);
        (*(void (__thiscall **)(float, int, VMatrix *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20))(
          a1: COERCE_FLOAT(LODWORD(v33)),
          a2: 16,
          a3: &worldToTexture,
          a4: 4,
          a5: 0);
        if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig)
          && g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig)
          && *(_BYTE *)(v62 + 160) != 0 )
        {
          v65 = *(float *)(v62 + 204);
          v84 = *(_QWORD *)(v62 + 164);
          v66 = *(_DWORD *)LODWORD(v33);
          v85 = *(_QWORD *)(v62 + 172);
          v67 = *(void (__thiscall **)(_DWORD, int, float *, int, _DWORD))(v66 + 20);
          v86 = *(_QWORD *)(v62 + 180);
          v87 = *(_QWORD *)(v62 + 188);
          v68 = *(_QWORD *)(v62 + 196);
          LODWORD(v76[1]) = v85;
          v88 = v68;
          v82[0] = 0.0;
          v82[1] = *(float *)&v85 - *(float *)&v84;
          v76[2] = *((float *)&v84 + 1) + *((float *)&v85 + 1);
          v82[3] = 0.0;
          v76[0] = 0.0;
          v76[3] = 0.0;
          v81[0] = 0.0;
          v81[3] = 0.0;
          v78 = v86;
          v82[2] = *((float *)&v85 + 1);
          v81[2] = 1.0 / *((float *)&v84 + 1);
          v89 = v65;
          v79 = 2.0 / v65;
          v80 = v65 * -0.5;
          *(float *)&_pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA = *((float *)&v87 + 1) + *(float *)&v87;
          _pshIndex.m_nPIXELFOGTYPE = v87;
          v81[1] = 1.0 / *(float *)&v84;
          _pshIndex.m_nFLASHLIGHTSHADOWS = v68;
          v92 = *((float *)&v68 + 1) + *(float *)&v68;
          v67(a1: LODWORD(v33), a2: 33, a3: v82, a4: 1, a5: 0);
          (*(void (__thiscall **)(float, int, float *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20))(
            a1: COERCE_FLOAT(LODWORD(v33)),
            a2: 34,
            a3: v76,
            a4: 1,
            a5: 0);
          (*(void (__thiscall **)(float, int, float *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20))(
            a1: COERCE_FLOAT(LODWORD(v33)),
            a2: 35,
            a3: v81,
            a4: 1,
            a5: 0);
          (*(void (__thiscall **)(float, int, __int64 *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20))(
            a1: COERCE_FLOAT(LODWORD(v33)),
            a2: 36,
            a3: &v78,
            a4: 1,
            a5: 0);
          (*(void (__thiscall **)(float, int, int *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20))(
            a1: COERCE_FLOAT(LODWORD(v33)),
            a2: 37,
            a3: &_pshIndex.m_nPIXELFOGTYPE,
            a4: 1,
            a5: 0);
          QuaternionAngles(q: (const Quaternion *)(v62 + 12), angles: (QAngle *)&map_scale[1]);
          AngleMatrix(angles: (const QAngle *)&map_scale[1], position: (const Vector *)v62, &matrix);
          MatrixInvert(in: &matrix, out: (matrix3x4_t *)&_vshIndex.m_nBUMPMAP);
          (*(void (__thiscall **)(float, int, int *, int, _DWORD))(*(_DWORD *)LODWORD(v33) + 20))(
            a1: COERCE_FLOAT(LODWORD(v33)),
            a2: 38,
            a3: &_vshIndex.m_nBUMPMAP,
            a4: 4,
            a5: 0);
        }
      }
      goto LABEL_198;
    }
    if ( !bSeamlessMapping )
      CBaseVSShader::SetVertexShaderTextureTransform(this: v43, vertexReg: 48, transformVar: 8);
    if ( hasBump && !bHasDetailAlpha )
      CBaseVSShader::SetVertexShaderTextureTransform(this: v43, vertexReg: 50, transformVar: BUMPTRANSFORM_8.m_Index);
    goto LABEL_149;
  }
LABEL_198:
  CBaseShader::Draw(this: v104, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10046A70
// Name: public: virtual void WorldTwoTextureBlend::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorldTwoTextureBlend::CShader::OnDrawElements(
        WorldTwoTextureBlend::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v7; // al

  v7 = CBaseShader::UsingFlashlight(this, params);
  WorldTwoTextureBlend::CShader::DrawPass(
    this,
    params,
    pShaderAPI: *(float *)&pShaderAPI,
    pShaderShadow: *(float *)&pShaderShadow,
    hasFlashlight: v7,
    vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10046AB0
// Name: public: virtual int WorldTwoTextureBlend::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WorldTwoTextureBlend::CShader::GetParamCount(WorldTwoTextureBlend::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_134.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10046B50
// Name: public: virtual struct ShaderParamInfo_t const __near & WorldTwoTextureBlend::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *__thiscall WorldTwoTextureBlend::CShader::GetParamInfo(
        WorldTwoTextureBlend::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_134.m_Memory.m_pMemory[param - ParamCount];
  else
    return (WorldTwoTextureBlend::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10046B80
// Name: public: WorldTwoTextureBlend::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *__thiscall WorldTwoTextureBlend::CShaderParam::CShaderParam(
        WorldTwoTextureBlend::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  WorldTwoTextureBlend::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  WorldTwoTextureBlend::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_134.m_Size + 13;
  m_Size = s_ShaderParams_134.m_Size;
  v8 = s_ShaderParams_134.m_Size;
  if ( s_ShaderParams_134.m_Size + 1 > s_ShaderParams_134.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_134,
      num: s_ShaderParams_134.m_Size - s_ShaderParams_134.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_134.m_Size;
  }
  m_pMemory = s_ShaderParams_134.m_Memory.m_pMemory;
  s_ShaderParams_134.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_134.m_pElements = s_ShaderParams_134.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_134.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_134.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_134.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006A630
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int WorldTwoTextureBlend::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: WorldTwoTextureBlend::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1006A640
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
void WorldTwoTextureBlend::_dynamic_initializer_for__BASETEXTURE__()
{
  s_pShaderParamOverrides_5[6] = &BASETEXTURE_0;
}

//------------------------------------------------------------------------------
// Address: 0x1006A650
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__ALBEDO__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__ALBEDO__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &ALBEDO_3,
           pName: "$ALBEDO",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/WorldTwoTextureBlend",
           pHelp: "albedo (Base texture with no baked lighting)",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A670
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__SELFILLUMTINT__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__SELFILLUMTINT__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &SELFILLUMTINT_3,
           pName: "$SELFILLUMTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Self-illumination tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A690
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__DETAIL__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__DETAIL__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &DETAIL_4,
           pName: "$DETAIL",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/WorldTwoTextureBlend_detail",
           pHelp: "detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A6B0
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__DETAILFRAME__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__DETAILFRAME__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &DETAILFRAME_3,
           pName: "$DETAILFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $detail",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A6D0
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__DETAILSCALE__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__DETAILSCALE__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &DETAILSCALE_4,
           pName: "$DETAILSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "scale of the detail texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A6F0
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__DETAIL_ALPHA_MASK_BASE_TEXTURE__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__DETAIL_ALPHA_MASK_BASE_TEXTURE__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &DETAIL_ALPHA_MASK_BASE_TEXTURE,
           pName: "$DETAIL_ALPHA_MASK_BASE_TEXTURE",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "If this is 1, then when detail alpha=0, no base texture is blended and when detail alpha=1, you get detail*base*lightmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A710
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__BUMPMAP__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &BUMPMAP_10,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A730
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__BUMPFRAME__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &BUMPFRAME_14,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A750
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_8,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A770
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__NODIFFUSEBUMPLIGHTING__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__NODIFFUSEBUMPLIGHTING__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &NODIFFUSEBUMPLIGHTING_0,
           pName: "$NODIFFUSEBUMPLIGHTING",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "0 == Use diffuse bump lighting, 1 = No diffuse bump lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A790
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__SEAMLESS_SCALE__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__SEAMLESS_SCALE__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &SEAMLESS_SCALE_1,
           pName: "$SEAMLESS_SCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: "Scale factor for 'seamless' texture mapping. 0 means to use ordinary mapping",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A7B0
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__SHADERSRGBREAD360__
// Source: json
//------------------------------------------------------------------------------
WorldTwoTextureBlend::CShaderParam *WorldTwoTextureBlend::_dynamic_initializer_for__SHADERSRGBREAD360__()
{
  return WorldTwoTextureBlend::CShaderParam::CShaderParam(
           this: &SHADERSRGBREAD360_4,
           pName: "$SHADERSRGBREAD360",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Simulate srgb read in shader code",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006A7D0
// Name: WorldTwoTextureBlend::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *WorldTwoTextureBlend::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_135);
  s_ShaderInstance_135.__vftable = (WorldTwoTextureBlend::CShader_vtbl *)&WorldTwoTextureBlend::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B970
// Name: WorldTwoTextureBlend::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldTwoTextureBlend::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_134);
}
