// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/teeth.cpp
// Functions: 33
// ============================================================

#include "materialsystem\stdshaders\teeth.h"

//------------------------------------------------------------------------------
// Address: 0x10035770
// Name: public: virtual char const __near * Teeth::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Teeth::CShader::GetFallbackShader(Teeth::CShader *this, IMaterialVar **params)
{
  return "Teeth_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10035780
// Name: public: virtual char const __near * Teeth::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Teeth::CShader::GetName(Teeth::CShader *this)
{
  return s_Name_116;
}

//------------------------------------------------------------------------------
// Address: 0x10035790
// Name: public: virtual int Teeth::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Teeth::CShader::GetFlags(Teeth::CShader *this)
{
  return s_nFlags_119;
}

//------------------------------------------------------------------------------
// Address: 0x100357A0
// Name: public: virtual int Teeth::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Teeth::CShader::GetParamCount(Teeth::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_116.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100357F0
// Name: public: teeth_bump_ps20b_Dynamic_Index::teeth_bump_ps20b_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
teeth_bump_ps20b_Dynamic_Index *__thiscall teeth_bump_ps20b_Dynamic_Index::teeth_bump_ps20b_Dynamic_Index(
        teeth_bump_ps20b_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nNUM_LIGHTS = 0;
  this->m_nAMBIENT_LIGHT = 0;
  this->m_nWRITE_DEPTH_TO_DESTALPHA = 0;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035820
// Name: public: teeth_vs30_Dynamic_Index::teeth_vs30_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
teeth_vs30_Dynamic_Index *__thiscall teeth_vs30_Dynamic_Index::teeth_vs30_Dynamic_Index(
        teeth_vs30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  MaterialFogMode_t v3; // eax

  this->m_nCOMPRESSED_VERTS = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
  this->m_nSKINNING = 0;
  this->m_nDYNAMIC_LIGHT = 0;
  this->m_nSTATIC_LIGHT = 0;
  this->m_nDOWATERFOG = v3 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nMORPHING = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035880
// Name: public: teeth_bump_vs30_Dynamic_Index::teeth_bump_vs30_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
teeth_bump_vs30_Dynamic_Index *__thiscall teeth_bump_vs30_Dynamic_Index::teeth_bump_vs30_Dynamic_Index(
        teeth_bump_vs30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  MaterialFogMode_t v3; // eax

  this->m_nCOMPRESSED_VERTS = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
  this->m_nSKINNING = 0;
  this->m_nSTATIC_LIGHT = 0;
  this->m_nDOWATERFOG = v3 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nMORPHING = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100358D0
// Name: public: virtual void Teeth_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Teeth_DX9::CShader::OnInitShaderParams(
        Teeth_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  params[9]->SetStringValue(this: params[9], a2: "effects/flashlight001");
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
}

//------------------------------------------------------------------------------
// Address: 0x10035900
// Name: public: virtual char const __near * Teeth_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Teeth_DX9::CShader::GetName(Teeth_DX9::CShader *this)
{
  return s_Name_117;
}

//------------------------------------------------------------------------------
// Address: 0x10035910
// Name: public: virtual int Teeth_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Teeth_DX9::CShader::GetFlags(Teeth_DX9::CShader *this)
{
  return s_nFlags_120;
}

//------------------------------------------------------------------------------
// Address: 0x10035920
// Name: public: virtual void Teeth_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Teeth_DX9::CShader::OnInitShaderInstance(
        Teeth_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  CBaseShader::LoadTexture(this, nTextureVar: 9, nAdditionalCreationFlags: 0x80000);
  CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
  if ( params[BUMPMAP_7.m_Index]->IsDefined(this: params[BUMPMAP_7.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: BUMPMAP_7.m_Index, nAdditionalCreationFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10035970
// Name: public: void Teeth_DX9::CShader::DrawUsingVertexShader(class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Teeth_DX9::CShader::DrawUsingVertexShader(
        Teeth_DX9::CShader *this,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        VertexCompressionType_t vertexCompression)
{
  bool v5; // bl
  int v6; // eax
  unsigned int v7; // edx
  int v8; // eax
  bool v9; // al
  bool v10; // bl
  bool v11; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  int v13; // eax
  bool v14; // bl
  void (__thiscall *v15)(IShaderShadow *, const char *, int); // edx
  int v16; // eax
  CBaseShader *v17; // edi
  CBaseVSShader *v18; // edi
  IMaterialVar *v19; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v21; // ecx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  char v23; // al
  int v24; // eax
  BOOL v25; // ebx
  BOOL v26; // eax
  int v27; // edi
  void (__thiscall *v28)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v29; // ebx
  bool v30; // al
  BOOL v31; // edi
  BOOL v32; // eax
  int v33; // ecx
  BOOL v34; // ebx
  BOOL m_bAmbientLight; // edi
  int v36; // eax
  BOOL m_bStaticLight; // edi
  void (__thiscall *v38)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v39; // zf
  int m_nNumLights; // ebx
  BOOL v41; // edi
  bool v42; // al
  BOOL v43; // eax
  int (__thiscall *GetCurrentNumBones)(IShaderDynamicAPI *); // eax
  int v45; // eax
  BOOL v46; // eax
  BOOL v47; // ebx
  BOOL v48; // eax
  int v49; // edi
  MaterialFogMode_t (__thiscall *GetSceneFogMode)(IShaderDynamicAPI *); // edx
  int v51; // eax
  bool v52; // bl
  bool v53; // al
  BOOL v54; // edi
  BOOL v55; // eax
  int v56; // eax
  int v57; // eax
  BOOL v58; // eax
  BOOL v59; // edi
  MaterialFogMode_t v60; // eax
  bool v61; // bl
  BOOL v62; // edi
  bool v63; // al
  BOOL v64; // eax
  const char *v65; // [esp-4h] [ebp-70h]
  const char *v66; // [esp-4h] [ebp-70h]
  const char *v67; // [esp-4h] [ebp-70h]
  const char *v68; // [esp-4h] [ebp-70h]
  int v69; // [esp+0h] [ebp-6Ch]
  int v70; // [esp+4h] [ebp-68h]
  teeth_vs30_Dynamic_Index v71; // [esp+Ch] [ebp-60h] BYREF
  float vEyePos_SpecExponent[4]; // [esp+24h] [ebp-48h] BYREF
  Vector4D lighting; // [esp+34h] [ebp-38h] BYREF
  teeth_bump_vs30_Dynamic_Index v74; // [esp+44h] [ebp-28h] BYREF
  LightState_t lightState; // [esp+58h] [ebp-14h] BYREF
  CBaseShader *v76; // [esp+60h] [ebp-Ch]
  BOOL bFullyOpaque; // [esp+67h] [ebp-5h]
  bool hasBump; // [esp+6Bh] [ebp-1h]
  int paramsa; // [esp+74h] [ebp+8h]
  bool params_3; // [esp+77h] [ebp+Bh]
  int bUseStaticControlFlow; // [esp+7Ch] [ebp+10h]
  bool bUseStaticControlFlow_3; // [esp+7Fh] [ebp+13h]
  VertexCompressionType_t vertexCompressiona; // [esp+80h] [ebp+14h]

  v5 = (*((_BYTE *)params[BUMPMAP_7.m_Index] + 28) & 0xF) == 3;
  v76 = this;
  hasBump = v5;
  v6 = CBaseVSShader::EvaluateBlendRequirements(this, textureVar: 6, isBaseTexture: true, detailTextureVar: -1);
  if ( v6 == 3 || v6 == 1 || (v7 = (unsigned int)(*params)->m_intVal >> 8, LOBYTE(bFullyOpaque) = 1, (v7 & 1) != 0) )
    LOBYTE(bFullyOpaque) = 0;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    v8 = 0;
    if ( v5 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: false);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: false);
      v8 = 4;
    }
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: v8);
    v9 = g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig);
    if ( v5 )
    {
      if ( v9 )
      {
        ((void (__stdcall *)(int, int, int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000, a2: v69, a3: v70);
        v13 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
        pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "teeth_bump_vs30", a3: 32 * (v13 >= 92));
        pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "teeth_bump_ps30", a3: 0);
      }
      else
      {
        v10 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
        unlitgeneric_vs20_Static_Index::unlitgeneric_vs20_Static_Index(
          this: (unlitgeneric_vs20_Static_Index *)&v74.m_nSKINNING,
          pShaderShadow,
          params);
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS stat var %s = %d (%s)",
            "FLATTEN_STATIC_CONTROL_FLOW",
            v10,
            "bFlattenStaticControlFlow");
        pShaderShadow->SetVertexShader(
          this: pShaderShadow,
          a2: "teeth_bump_vs20",
          a3: 48 * (v10 + 2 * (v74.m_nSTATIC_LIGHT + 2 * v74.m_nMORPHING)));
        v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
        SetPixelShader = pShaderShadow->SetPixelShader;
        v69 = 0;
        if ( v11 )
          ((void (__thiscall *)(IShaderShadow *, const char *))SetPixelShader)(a1: pShaderShadow, a2: "teeth_bump_ps20");
        else
          ((void (__thiscall *)(IShaderShadow *, const char *))SetPixelShader)(
            a1: pShaderShadow,
            a2: "teeth_bump_ps20b");
        v5 = hasBump;
      }
    }
    else if ( v9 )
    {
      ((void (__stdcall *)(int, int, int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000, a2: v69, a3: v70);
      v16 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "teeth_vs30", a3: (v16 >= 92) << 6);
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "teeth_ps30", a3: 0);
    }
    else
    {
      v14 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
      unlitgeneric_vs20_Static_Index::unlitgeneric_vs20_Static_Index(
        this: (unlitgeneric_vs20_Static_Index *)&v74.m_nSKINNING,
        pShaderShadow,
        params);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "FLATTEN_STATIC_CONTROL_FLOW", v14, "bFlattenStaticControlFlow");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "teeth_vs20",
        a3: 96 * (v14 + 2 * (v74.m_nSTATIC_LIGHT + 2 * v74.m_nMORPHING)));
      v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      v15 = pShaderShadow->SetPixelShader;
      v69 = 0;
      if ( v11 )
        ((void (__thiscall *)(IShaderShadow *, const char *))v15)(a1: pShaderShadow, a2: "teeth_ps20");
      else
        ((void (__thiscall *)(IShaderShadow *, const char *))v15)(a1: pShaderShadow, a2: "teeth_ps20b");
      v5 = hasBump;
    }
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    v17 = v76;
    CBaseShader::FogToFogColor(this: v76);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: bFullyOpaque);
    CBaseShader::PI_BeginCommandBuffer(this: v17);
    CBaseShader::PI_SetPixelShaderAmbientLightCube(this: v17, nFirstRegister: 4);
    CBaseShader::PI_SetPixelShaderLocalLighting(this: v17, nFirstRegister: 20);
    if ( !v5 )
      CBaseShader::PI_SetVertexShaderAmbientLightCube(this: v17);
    CBaseShader::PI_EndCommandBuffer(this: v17);
  }
  if ( pShaderAPI == nullptr )
    goto LABEL_137;
  v18 = (CBaseVSShader *)v76;
  CBaseShader::BindTexture(
    this: v76,
    sampler1: SHADER_SAMPLER0,
    nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
    nTextureVar: 6,
    nFrameVar: 7);
  if ( v5 )
    CBaseShader::BindTexture(
      this: v18,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_NONE,
      nTextureVar: BUMPMAP_7.m_Index,
      nFrameVar: -1);
  pShaderAPI->BindStandardTexture(
    this: pShaderAPI,
    a2: SHADER_SAMPLER2,
    a3: TEXTURE_BINDFLAGS_NONE,
    a4: TEXTURE_NORMALIZATION_CUBEMAP_SIGNED);
  v19 = params[FORWARD.m_Index];
  SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
  lighting.x = v19->m_VecVal.x;
  lighting.y = v19->m_VecVal.y;
  v21 = params[ILLUMFACTOR.m_Index];
  lighting.z = v19->m_VecVal.z;
  lighting.w = v21->m_VecVal.x;
  SetVertexShaderConstant(this: pShaderAPI, a2: 48, a3: &lighting.x, a4: 1, a5: false);
  pShaderAPI->GetDX9LightState(this: pShaderAPI, a2: &lightState);
  pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
  pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
  SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
  vEyePos_SpecExponent[3] = 0.0;
  SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
  v23 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->HasFastVertexTextures)(
          a1: g_pHardwareConfig,
          a2: v69);
  if ( v5 )
  {
    if ( v23 != 0 )
    {
      CBaseVSShader::SetHWMorphVertexShaderState(
        this: v18,
        nDimConst: 54,
        nSubrectConst: 55,
        morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      teeth_bump_vs30_Dynamic_Index::teeth_bump_vs30_Dynamic_Index(this: &v74, pShaderAPI);
      v74.m_nSKINNING = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v36 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
                a1: pShaderAPI,
                a2: "pShaderAPI->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v36 > 0, v66);
      }
      m_bStaticLight = lightState.m_bStaticLight;
      if ( g_shaderConfigDumpEnable )
      {
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "STATIC_LIGHT",
          lightState.m_bStaticLight,
          "lightState.m_bStaticLight ? 1 : 0");
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
      }
      pShaderAPI->SetVertexShaderIndex(
        this: pShaderAPI,
        a2: vertexCompression + 2 * (v74.m_nDOWATERFOG + 2 * (v74.m_nSKINNING + 2 * (m_bStaticLight + 2 * v74.m_nMORPHING))));
      v38 = pShaderAPI->SetPixelShaderConstant;
      v71.m_nMORPHING = LODWORD(params[PHONGEXPONENT_3.m_Index]->m_VecVal.x);
      v38(this: pShaderAPI, a2: 11, a3: (const float *)&v71.m_nSKINNING, a4: 1, a5: false);
      v39 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      m_nNumLights = lightState.m_nNumLights;
      v41 = v39;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          lightState.m_nNumLights,
          "lightState.m_nNumLights");
      vertexCompressiona = lightState.m_bAmbientLight;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "AMBIENT_LIGHT",
          lightState.m_bAmbientLight,
          "lightState.m_bAmbientLight ? 1 : 0");
      v42 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
      v74.m_nMORPHING = v42;
      if ( g_shaderConfigDumpEnable )
      {
        v43 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "WRITE_DEPTH_TO_DESTALPHA",
          v43,
          "bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
      }
      pShaderAPI->SetPixelShaderIndex(
        this: pShaderAPI,
        a2: v41
      + 2 * (vertexCompressiona + 2 * v74.m_nMORPHING + m_nNumLights + 4 * (vertexCompressiona + 2 * v74.m_nMORPHING)));
      goto LABEL_137;
    }
    bUseStaticControlFlow_3 = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
    phong_ps20b_Dynamic_Index::phong_ps20b_Dynamic_Index(
      this: (phong_ps20b_Dynamic_Index *)&v71.m_nDOWATERFOG,
      pShaderAPI);
    v71.m_nDYNAMIC_LIGHT = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v24 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v24 > 0, v65);
    }
    v25 = lightState.m_bStaticLight;
    if ( g_shaderConfigDumpEnable )
    {
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "STATIC_LIGHT",
        lightState.m_bStaticLight,
        "lightState.m_bStaticLight ? 1 : 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    v26 = bUseStaticControlFlow_3;
    v27 = v26 ? 0 : lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        v26 ? 0 : lightState.m_nNumLights,
        "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: vertexCompression + 2 * (v71.m_nSKINNING + 2 * (v71.m_nDYNAMIC_LIGHT + 2 * (v25 + 2 * v27))));
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      v34 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
      v74.m_nSTATIC_LIGHT = lightState.m_nNumLights;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          lightState.m_nNumLights,
          "lightState.m_nNumLights");
      m_bAmbientLight = lightState.m_bAmbientLight;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "AMBIENT_LIGHT",
          lightState.m_bAmbientLight,
          "lightState.m_bAmbientLight ? 1 : 0");
      pShaderAPI->SetPixelShaderIndex(
        this: pShaderAPI,
        a2: v34 + 2 * (m_bAmbientLight + v74.m_nSTATIC_LIGHT + 2 * m_bAmbientLight));
      goto LABEL_137;
    }
    v28 = pShaderAPI->SetPixelShaderConstant;
    v71.m_nMORPHING = LODWORD(params[PHONGEXPONENT_3.m_Index]->m_VecVal.x);
    v28(this: pShaderAPI, a2: 11, a3: (const float *)&v71.m_nSKINNING, a4: 1, a5: false);
    teeth_bump_ps20b_Dynamic_Index::teeth_bump_ps20b_Dynamic_Index(
      this: (teeth_bump_ps20b_Dynamic_Index *)&v74.m_nDOWATERFOG,
      pShaderAPI);
    v74.m_nSKINNING = lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", lightState.m_nNumLights, "lightState.m_nNumLights");
    v29 = lightState.m_bAmbientLight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "AMBIENT_LIGHT",
        lightState.m_bAmbientLight,
        "lightState.m_bAmbientLight ? 1 : 0");
    v30 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    v31 = v30;
    if ( g_shaderConfigDumpEnable )
    {
      v32 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITE_DEPTH_TO_DESTALPHA",
        v32,
        "bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
    }
    v33 = v74.m_nDOWATERFOG + 2 * (v29 + 2 * v31 + v74.m_nSKINNING + 4 * (v29 + 2 * v31));
  }
  else if ( v23 != 0 )
  {
    CBaseVSShader::SetHWMorphVertexShaderState(
      this: v18,
      nDimConst: 54,
      nSubrectConst: 55,
      morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
    teeth_vs30_Dynamic_Index::teeth_vs30_Dynamic_Index(this: &v71, pShaderAPI);
    v71.m_nSKINNING = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v57 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v57 > 0, v68);
    }
    if ( lightState.m_bAmbientLight || (paramsa = 0, lightState.m_nNumLights > 0) )
      paramsa = 1;
    if ( g_shaderConfigDumpEnable )
    {
      v58 = lightState.m_bAmbientLight || lightState.m_nNumLights > 0;
      printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", v58, "lightState.HasDynamicLight()");
    }
    v59 = lightState.m_bStaticLight;
    if ( g_shaderConfigDumpEnable )
    {
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "STATIC_LIGHT",
        lightState.m_bStaticLight,
        "lightState.m_bStaticLight ? 1 : 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: vertexCompression
    + 2 * (v71.m_nDOWATERFOG + 2 * (v71.m_nSKINNING + 2 * (paramsa + 2 * (v59 + 2 * v71.m_nMORPHING)))));
    v60 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    v61 = bFullyOpaque;
    v62 = v60 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v63 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    v74.m_nMORPHING = v63;
    if ( g_shaderConfigDumpEnable )
    {
      v64 = v61 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITE_DEPTH_TO_DESTALPHA",
        v64,
        "bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
    }
    v33 = v62 + 2 * v74.m_nMORPHING;
  }
  else
  {
    params_3 = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
    v39 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    GetCurrentNumBones = pShaderAPI->GetCurrentNumBones;
    v71.m_nDOWATERFOG = v39;
    v71.m_nSKINNING = GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v45 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v45 > 0, v67);
    }
    if ( lightState.m_bAmbientLight || (bUseStaticControlFlow = 0, lightState.m_nNumLights > 0) )
      bUseStaticControlFlow = 1;
    if ( g_shaderConfigDumpEnable )
    {
      v46 = lightState.m_bAmbientLight || lightState.m_nNumLights > 0;
      printf(format: "\n   VS dyn  var %s = %d (%s)", "DYNAMIC_LIGHT", v46, "lightState.HasDynamicLight()");
    }
    v47 = lightState.m_bStaticLight;
    if ( g_shaderConfigDumpEnable )
    {
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "STATIC_LIGHT",
        lightState.m_bStaticLight,
        "lightState.m_bStaticLight ? 1 : 0");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    v48 = params_3;
    v49 = v48 ? 0 : lightState.m_nNumLights;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS dyn  var %s = %d (%s)",
        "NUM_LIGHTS",
        v48 ? 0 : lightState.m_nNumLights,
        "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: vertexCompression
    + 2 * (v71.m_nDOWATERFOG + 2 * (v71.m_nSKINNING + 2 * (bUseStaticControlFlow + 2 * (v47 + 2 * v49)))));
    v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    GetSceneFogMode = pShaderAPI->GetSceneFogMode;
    if ( v11 )
    {
      v56 = GetSceneFogMode(this: pShaderAPI);
      pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v56 == 2);
      CBaseShader::Draw(this: v76, bMakeActualDrawCall: true);
      return;
    }
    v51 = GetSceneFogMode(this: pShaderAPI);
    v52 = bFullyOpaque;
    v74.m_nSTATIC_LIGHT = v51 == 2;
    v53 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    v54 = v53;
    if ( g_shaderConfigDumpEnable )
    {
      v55 = v52 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITE_DEPTH_TO_DESTALPHA",
        v55,
        "bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
    }
    v33 = v74.m_nSTATIC_LIGHT + 2 * v54;
  }
  pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v33);
LABEL_137:
  CBaseShader::Draw(this: v76, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100365A0
// Name: public: void Teeth_DX9::CShader::DrawFlashlight(class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Teeth_DX9::CShader::DrawFlashlight(
        Teeth_DX9::CShader *this,
        IMaterialVar **params,
        ITexture *pShaderAPI,
        float pShaderShadow,
        VertexCompressionType_t vertexCompression)
{
  float v5; // esi
  ShadowFilterMode_t v6; // edi
  int v7; // eax
  BOOL v8; // ebx
  int v9; // eax
  int v10; // eax
  ITexture *v11; // ebx
  bool (__thiscall *GetHDREnabled)(IMaterialSystemHardwareConfig *); // eax
  bool v13; // al
  float v14; // xmm1_4
  int (__thiscall *GetNumAnimationFrames)(ITexture *); // edx
  int v16; // eax
  CBaseVSShader *v17; // esi
  IMaterialVar *v18; // eax
  float z; // xmm0_4
  IMaterialVar *v20; // eax
  int (__thiscall *GetActualHeight)(ITexture *); // edx
  float v22; // xmm1_4
  int (__thiscall *v23)(ITexture *); // edx
  int (__thiscall *v24)(ITexture *); // edx
  int (__thiscall *v25)(ITexture *); // edx
  bool v26; // al
  float m_flShadowAtten; // xmm0_4
  void (__thiscall *Download)(ITexture *, Rect_t *, int); // eax
  int (__thiscall *v29)(ITexture *); // edx
  BOOL v30; // esi
  BOOL v31; // edi
  int v32; // eax
  bool v33; // cc
  int (__thiscall *GetMappingHeight)(ITexture *); // edx
  BOOL v35; // esi
  BOOL v36; // edi
  int v37; // eax
  BOOL v38; // esi
  int v39; // edi
  int v40; // eax
  BOOL v41; // esi
  BOOL v42; // edi
  int (__thiscall *v43)(ITexture *); // edx
  const char *v44; // [esp+ECh] [ebp-280h]
  const char *v45; // [esp+ECh] [ebp-280h]
  VMatrix worldToTexture; // [esp+FCh] [ebp-270h] BYREF
  matrix3x4_t out; // [esp+13Ch] [ebp-230h] BYREF
  matrix3x4_t matrix; // [esp+16Ch] [ebp-200h] BYREF
  float vFlashlightPos[4]; // [esp+19Ch] [ebp-1D0h] BYREF
  FlashlightState_t flashlightState; // [esp+1ACh] [ebp-1C0h] BYREF
  float v51[4]; // [esp+2A8h] [ebp-C4h] BYREF
  float v52[4]; // [esp+2B8h] [ebp-B4h] BYREF
  float v53[4]; // [esp+2C8h] [ebp-A4h] BYREF
  float pos[4]; // [esp+2D8h] [ebp-94h] BYREF
  Vector4D lighting; // [esp+2E8h] [ebp-84h] BYREF
  float atten[4]; // [esp+2F8h] [ebp-74h] BYREF
  float v57[4]; // [esp+308h] [ebp-64h] BYREF
  float tweaks[4]; // [esp+318h] [ebp-54h] BYREF
  teeth_flashlight_vs30_Dynamic_Index _vshIndex; // [esp+328h] [ebp-44h] BYREF
  int nTexHeight; // [esp+338h] [ebp-34h] BYREF
  int nTexWidth; // [esp+33Ch] [ebp-30h] BYREF
  int nWidth; // [esp+340h] [ebp-2Ch] BYREF
  int nHeight; // [esp+344h] [ebp-28h] BYREF
  float vScreenScale[4]; // [esp+348h] [ebp-24h] BYREF
  float v65; // [esp+358h] [ebp-14h] BYREF
  teeth_flashlight_ps30_Dynamic_Index _pshIndex; // [esp+35Ch] [ebp-10h] BYREF
  CBaseShader *v67; // [esp+368h] [ebp-4h]
  float paramsa; // [esp+374h] [ebp+8h]

  v5 = pShaderShadow;
  v67 = this;
  if ( pShaderShadow != 0.0 )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(pShaderShadow) + 24))(a1: LODWORD(pShaderShadow), a2: 0);
    (*(void (__thiscall **)(float, _DWORD, int))(*(_DWORD *)LODWORD(v5) + 84))(
      a1: COERCE_FLOAT(LODWORD(v5)),
      a2: 0,
      a3: 1);
    (*(void (__thiscall **)(float, _DWORD, int))(*(_DWORD *)LODWORD(v5) + 80))(
      a1: COERCE_FLOAT(LODWORD(v5)),
      a2: 0,
      a3: 1);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v5) + 84))(a1: COERCE_FLOAT(LODWORD(v5)), a2: 1, a3: 1);
    (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v5) + 80))(a1: COERCE_FLOAT(LODWORD(v5)), a2: 1, a3: 1);
    CBaseShader::s_pShaderShadow->EnableAlphaTest(this: CBaseShader::s_pShaderShadow, a2: false);
    CBaseShader::s_pShaderShadow->BlendFunc(
      this: CBaseShader::s_pShaderShadow,
      a2: SHADER_BLEND_ONE,
      a3: SHADER_BLEND_ONE);
    CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: true);
    (*(void (__thiscall **)(float, int, int, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v5) + 64))(
      a1: COERCE_FLOAT(LODWORD(v5)),
      a2: 1027,
      a3: 1,
      a4: 0,
      a5: 0);
    v6 = SHADOWFILTERMODE_DEFAULT;
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v5) + 84))(
        a1: COERCE_FLOAT(LODWORD(v5)),
        a2: 2,
        a3: 1);
      (*(void (__thiscall **)(float, int, int))(*(_DWORD *)LODWORD(v5) + 84))(
        a1: COERCE_FLOAT(LODWORD(v5)),
        a2: 3,
        a3: 1);
      v7 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *))g_pHardwareConfig->HasFastVertexTextures)(a1: g_pHardwareConfig);
      LOBYTE(v7) = (_BYTE)v7 != 0;
      v6 = g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: v7);
    }
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      (*(void (__thiscall **)(float, const char *, int))(*(_DWORD *)LODWORD(v5) + 68))(
        a1: COERCE_FLOAT(LODWORD(v5)),
        a2: "teeth_flashlight_vs30",
        a3: 16 * (v10 >= 92));
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHTDEPTHFILTERMODE", v6, "nShadowFilterMode");
      (*(void (__thiscall **)(float, const char *, __int32))(*(_DWORD *)LODWORD(v5) + 72))(
        a1: COERCE_FLOAT(LODWORD(v5)),
        a2: "teeth_flashlight_ps30",
        a3: 8 * v6);
    }
    else
    {
      v8 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v9 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      (*(void (__thiscall **)(float, const char *, int))(*(_DWORD *)LODWORD(v5) + 68))(
        a1: COERCE_FLOAT(LODWORD(v5)),
        a2: "teeth_flashlight_vs20",
        a3: 8 * (v8 + 2 * (v9 < 92)));
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
      {
        (*(void (__thiscall **)(float, const char *, _DWORD))(*(_DWORD *)LODWORD(v5) + 72))(
          a1: COERCE_FLOAT(LODWORD(v5)),
          a2: "teeth_flashlight_ps20",
          a3: 0);
      }
      else
      {
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHTDEPTHFILTERMODE", v6, "nShadowFilterMode");
        (*(void (__thiscall **)(float, const char *, __int32))(*(_DWORD *)LODWORD(v5) + 72))(
          a1: COERCE_FLOAT(LODWORD(v5)),
          a2: "teeth_flashlight_ps20b",
          a3: 4 * v6);
      }
    }
    (*(void (__thiscall **)(float, _DWORD, int))(*(_DWORD *)LODWORD(v5) + 80))(
      a1: COERCE_FLOAT(LODWORD(v5)),
      a2: 0,
      a3: 1);
    (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v5) + 76))(a1: COERCE_FLOAT(LODWORD(v5)), a2: 1);
    CBaseShader::FogToFogColor(this: v67);
  }
  v11 = pShaderAPI;
  if ( pShaderAPI == nullptr )
    goto LABEL_49;
  CBaseShader::BindTexture(
    this: v67,
    sampler1: SHADER_SAMPLER0,
    nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
    nTextureVar: 6,
    nFrameVar: 7);
  CBaseVSShader::SetFlashlightVertexShaderConstants(
    this: (CBaseVSShader *)v67,
    bBump: false,
    bumpTransformVar: -1,
    bDetail: false,
    detailScaleVar: -1,
    bSetTextureTransforms: true);
  flashlightState = *(FlashlightState_t *)((int (__thiscall *)(ITexture *, VMatrix *, ITexture **))v11->SetActiveSubTarget)(
                                            a1: v11,
                                            a2: &worldToTexture,
                                            a3: &pShaderAPI);
  GetHDREnabled = g_pHardwareConfig->GetHDREnabled;
  pShaderShadow = r_flashlightbrightness.m_pParent->m_Value.m_fValue;
  if ( !GetHDREnabled(this: g_pHardwareConfig) )
    pShaderShadow = 2.0;
  v13 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
  v14 = pShaderShadow;
  if ( v13 )
    v14 = pShaderShadow * 2.5;
  GetNumAnimationFrames = v11->GetNumAnimationFrames;
  v65 = flashlightState.m_Color[0] * (float)(flashlightState.m_fBrightnessScale * v14);
  *(float *)&_pshIndex.m_nPIXELFOGTYPE = flashlightState.m_Color[1] * (float)(flashlightState.m_fBrightnessScale * v14);
  *(float *)&_pshIndex.m_nFLASHLIGHTSHADOWS = flashlightState.m_Color[2]
                                            * (float)(flashlightState.m_fBrightnessScale * v14);
  _pshIndex.m_nUBERLIGHT = 0;
  ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))GetNumAnimationFrames)(
    a1: v11,
    a2: 28,
    a3: &v65,
    a4: 1,
    a5: 0);
  v16 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
  HIBYTE(pShaderShadow) = v16 >= 92 && flashlightState.m_bEnableShadows;
  if ( pShaderAPI != nullptr && g_pConfig->m_bShadowDepthTexture && flashlightState.m_bEnableShadows )
  {
    v17 = (CBaseVSShader *)v67;
    CBaseShader::BindTexture(
      this: v67,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
      pTexture: pShaderAPI,
      nFrame: 0);
    ((void (__thiscall *)(ITexture *, int, _DWORD, int))v11->IsCubeMap)(a1: v11, a2: 3, a3: 0, a4: 20);
  }
  else
  {
    v17 = (CBaseVSShader *)v67;
  }
  v18 = params[FORWARD.m_Index];
  lighting.x = v18->m_VecVal.x;
  lighting.y = v18->m_VecVal.y;
  z = v18->m_VecVal.z;
  v20 = params[ILLUMFACTOR.m_Index];
  GetActualHeight = v11->GetActualHeight;
  lighting.z = z;
  lighting.w = v20->m_VecVal.x;
  ((void (__thiscall *)(ITexture *, int, Vector4D *, int, _DWORD))GetActualHeight)(
    a1: v11,
    a2: 56,
    a3: &lighting,
    a4: 1,
    a5: 0);
  paramsa = r_flashlightbrightness.m_pParent->m_Value.m_fValue;
  if ( !g_pHardwareConfig->GetHDREnabled(this: g_pHardwareConfig) )
    paramsa = 2.0;
  v22 = paramsa;
  if ( g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig) )
    v22 = paramsa * 2.5;
  v23 = v11->GetNumAnimationFrames;
  v65 = flashlightState.m_Color[0] * (float)(flashlightState.m_fBrightnessScale * v22);
  *(float *)&_pshIndex.m_nPIXELFOGTYPE = flashlightState.m_Color[1] * (float)(flashlightState.m_fBrightnessScale * v22);
  *(float *)&_pshIndex.m_nFLASHLIGHTSHADOWS = flashlightState.m_Color[2]
                                            * (float)(flashlightState.m_fBrightnessScale * v22);
  _pshIndex.m_nUBERLIGHT = 0;
  ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v23)(a1: v11, a2: 28, a3: &v65, a4: 1, a5: 0);
  CBaseShader::BindTexture(
    this: v17,
    sampler1: SHADER_SAMPLER1,
    nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
    pTexture: flashlightState.m_pSpotlightTexture,
    nFrame: flashlightState.m_nSpotlightTextureFrame);
  v24 = v11->GetNumAnimationFrames;
  atten[0] = flashlightState.m_fConstantAtten;
  atten[1] = flashlightState.m_fLinearAtten;
  atten[2] = flashlightState.m_fQuadraticAtten;
  atten[3] = flashlightState.m_FarZAtten;
  ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v24)(a1: v11, a2: 13, a3: atten, a4: 1, a5: 0);
  v25 = v11->GetNumAnimationFrames;
  *(Vector *)pos = flashlightState.m_vecLightOrigin;
  pos[3] = flashlightState.m_FarZ;
  ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v25)(a1: v11, a2: 14, a3: pos, a4: 1, a5: 0);
  ((void (__thiscall *)(ITexture *, int, VMatrix *, int, _DWORD))v11->GetNumAnimationFrames)(
    a1: v11,
    a2: 15,
    a3: &worldToTexture,
    a4: 4,
    a5: 0);
  tweaks[0] = flashlightState.m_flShadowFilterSize * 0.0009765625;
  v26 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
  m_flShadowAtten = flashlightState.m_flShadowAtten;
  if ( v26 )
    m_flShadowAtten = flashlightState.m_flShadowAtten * 0.1;
  tweaks[1] = m_flShadowAtten;
  CBaseVSShader::HashShadow2DJitter(
    this: v17,
    fJitterSeed: flashlightState.m_flShadowJitterSeed,
    fU: &tweaks[2],
    fV: &tweaks[3]);
  ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v11->GetNumAnimationFrames)(
    a1: v11,
    a2: 2,
    a3: tweaks,
    a4: 1,
    a5: 0);
  Download = v11->Download;
  vScreenScale[0] = 40.0;
  vScreenScale[1] = 22.5;
  vScreenScale[2] = 0.0;
  vScreenScale[3] = 0.0;
  Download(this: v11, a2: (Rect_t *)&nWidth, a3: (int)&nHeight);
  ((void (__thiscall *)(ITexture *, int *, int *, int))v11->__vftable[1].GetActualHeight)(
    a1: v11,
    a2: &nTexWidth,
    a3: &nTexHeight,
    a4: 20);
  v29 = v11->GetNumAnimationFrames;
  vScreenScale[0] = (float)nWidth / (float)nTexWidth;
  vScreenScale[1] = (float)nHeight / (float)nTexHeight;
  vScreenScale[2] = 1.0 / flashlightState.m_flShadowMapResolution;
  vScreenScale[3] = (float)(1.0 / flashlightState.m_flShadowMapResolution) * 2.0;
  ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v29)(a1: v11, a2: 31, a3: vScreenScale, a4: 1, a5: 0);
  ((void (__thiscall *)(ITexture *, float *))v11->IsMipmapped)(a1: v11, a2: vFlashlightPos);
  ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v11->GetNumAnimationFrames)(
    a1: v11,
    a2: 14,
    a3: vFlashlightPos,
    a4: 1,
    a5: 0);
  if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
  {
    CBaseVSShader::SetHWMorphVertexShaderState(
      this: v17,
      nDimConst: 54,
      nSubrectConst: 55,
      morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
    v38 = v11->GetMappingHeight(this: v11) == 2;
    v39 = (unsigned __int8)v11->__vftable[1].GetActualWidth(this: v11);
    _vshIndex.m_nSKINNING = ((int (__thiscall *)(ITexture *))v11->GetResourceData)(a1: v11) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v40 = ((int (__thiscall *)(ITexture *, const char *))v11->GetResourceData)(
              a1: v11,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v40 > 0, v45);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
    }
    ((void (__thiscall *)(ITexture *, __int32))v11->DecrementReferenceCount)(
      a1: v11,
      a2: vertexCompression + 2 * (v38 + 2 * (_vshIndex.m_nSKINNING + 2 * v39)));
    v41 = v11->GetMappingHeight(this: v11) == 2;
    v42 = HIBYTE(pShaderShadow) != 0;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", HIBYTE(pShaderShadow), "bFlashlightShadows");
    _pshIndex.m_nUBERLIGHT = flashlightState.m_bUberlight;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "UBERLIGHT",
        flashlightState.m_bUberlight,
        "flashlightState.m_bUberlight");
    ((void (__thiscall *)(ITexture *, int))v11->SetTextureRegenerator)(
      a1: v11,
      a2: v41 + 2 * (v42 + 2 * _pshIndex.m_nUBERLIGHT));
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) && flashlightState.m_bUberlight )
    {
      v43 = v11->GetNumAnimationFrames;
      v52[1] = flashlightState.m_uberlightState.m_fCutOn;
      v51[0] = 0.0;
      v51[1] = flashlightState.m_uberlightState.m_fCutOn - flashlightState.m_uberlightState.m_fNearEdge;
      v52[2] = flashlightState.m_uberlightState.m_fFarEdge + flashlightState.m_uberlightState.m_fCutOff;
      v51[3] = 0.0;
      v52[0] = 0.0;
      v52[3] = 0.0;
      v53[0] = 0.0;
      v53[3] = 0.0;
      v57[0] = flashlightState.m_uberlightState.m_fShearx;
      v51[2] = flashlightState.m_uberlightState.m_fCutOff;
      v53[2] = 1.0 / flashlightState.m_uberlightState.m_fFarEdge;
      v57[1] = flashlightState.m_uberlightState.m_fSheary;
      v57[2] = 2.0 / flashlightState.m_uberlightState.m_fRoundness;
      v57[3] = flashlightState.m_uberlightState.m_fRoundness * -0.5;
      *(float *)&_vshIndex.m_nDOWATERFOG = flashlightState.m_uberlightState.m_fWedge
                                         + flashlightState.m_uberlightState.m_fWidth;
      _vshIndex.m_nCOMPRESSED_VERTS = LODWORD(flashlightState.m_uberlightState.m_fWidth);
      v53[1] = 1.0 / flashlightState.m_uberlightState.m_fNearEdge;
      _vshIndex.m_nSKINNING = LODWORD(flashlightState.m_uberlightState.m_fHeight);
      *(float *)&_vshIndex.m_nMORPHING = flashlightState.m_uberlightState.m_fHedge
                                       + flashlightState.m_uberlightState.m_fHeight;
      ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v43)(a1: v11, a2: 33, a3: v51, a4: 1, a5: 0);
      ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v11->GetNumAnimationFrames)(
        a1: v11,
        a2: 34,
        a3: v52,
        a4: 1,
        a5: 0);
      ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v11->GetNumAnimationFrames)(
        a1: v11,
        a2: 35,
        a3: v53,
        a4: 1,
        a5: 0);
      ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v11->GetNumAnimationFrames)(
        a1: v11,
        a2: 36,
        a3: v57,
        a4: 1,
        a5: 0);
      ((void (__thiscall *)(ITexture *, int, teeth_flashlight_vs30_Dynamic_Index *, int, _DWORD))v11->GetNumAnimationFrames)(
        a1: v11,
        a2: 37,
        a3: &_vshIndex,
        a4: 1,
        a5: 0);
      QuaternionAngles(q: &flashlightState.m_quatOrientation, angles: (QAngle *)&_pshIndex);
      AngleMatrix(angles: (const QAngle *)&_pshIndex, position: &flashlightState.m_vecLightOrigin, &matrix);
      MatrixInvert(in: &matrix, &out);
      ((void (__thiscall *)(ITexture *, int, matrix3x4_t *, int, _DWORD))v11->GetNumAnimationFrames)(
        a1: v11,
        a2: 38,
        a3: &out,
        a4: 4,
        a5: 0);
    }
LABEL_49:
    CBaseShader::Draw(this: v67, bMakeActualDrawCall: true);
    return;
  }
  v30 = v11->GetMappingHeight(this: v11) == 2;
  v31 = ((int (__thiscall *)(ITexture *))v11->GetResourceData)(a1: v11) > 0;
  if ( g_shaderConfigDumpEnable )
  {
    v32 = ((int (__thiscall *)(ITexture *, const char *))v11->GetResourceData)(
            a1: v11,
            a2: "pShaderAPI->GetCurrentNumBones() > 0");
    printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v32 > 0, v44);
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
  }
  ((void (__thiscall *)(ITexture *, __int32))v11->DecrementReferenceCount)(
    a1: v11,
    a2: vertexCompression + 2 * (v30 + 2 * v31));
  v33 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  GetMappingHeight = v11->GetMappingHeight;
  if ( v33 )
  {
    v37 = GetMappingHeight(this: v11);
    ((void (__thiscall *)(ITexture *, bool))v11->SetTextureRegenerator)(a1: v11, a2: v37 == 2);
    CBaseShader::Draw(this: v67, bMakeActualDrawCall: true);
  }
  else
  {
    v35 = GetMappingHeight(this: v11) == 2;
    v36 = HIBYTE(pShaderShadow) != 0;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   PS dyn  var %s = %d (%s)", "FLASHLIGHTSHADOWS", HIBYTE(pShaderShadow), "bFlashlightShadows");
    ((void (__thiscall *)(ITexture *, int))v11->SetTextureRegenerator)(a1: v11, a2: v35 + 2 * v36);
    CBaseShader::Draw(this: v67, bMakeActualDrawCall: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100370F0
// Name: public: virtual void Teeth_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Teeth_DX9::CShader::OnDrawElements(
        Teeth_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        ITexture *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  if ( pShaderShadow != nullptr )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  if ( CBaseShader::UsingFlashlight(this, params) )
  {
    Teeth_DX9::CShader::DrawFlashlight(
      this,
      params,
      pShaderAPI,
      pShaderShadow: *(float *)&pShaderShadow,
      vertexCompression);
  }
  else
  {
    Teeth_DX9::CShader::DrawUsingVertexShader(
      this,
      params,
      (IShaderDynamicAPI *)pShaderAPI,
      pShaderShadow,
      vertexCompression);
    if ( pShaderShadow != nullptr )
      CBaseShader::SetInitialShadowState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037160
// Name: public: virtual int Teeth_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Teeth_DX9::CShader::GetParamCount(Teeth_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_117.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037170
// Name: public: virtual struct ShaderParamInfo_t const __near & Teeth::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Teeth::CShaderParam *__thiscall Teeth::CShader::GetParamInfo(Teeth::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_116.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Teeth::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100371A0
// Name: public: virtual struct ShaderParamInfo_t const __near & Teeth_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Teeth_DX9::CShaderParam *__thiscall Teeth_DX9::CShader::GetParamInfo(Teeth_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_117.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Teeth_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100371D0
// Name: public: Teeth_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Teeth_DX9::CShaderParam *__thiscall Teeth_DX9::CShaderParam::CShaderParam(
        Teeth_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Teeth_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Teeth_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_117.m_Size + 13;
  m_Size = s_ShaderParams_117.m_Size;
  v8 = s_ShaderParams_117.m_Size;
  if ( s_ShaderParams_117.m_Size + 1 > s_ShaderParams_117.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_117,
      num: s_ShaderParams_117.m_Size - s_ShaderParams_117.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_117.m_Size;
  }
  m_pMemory = s_ShaderParams_117.m_Memory.m_pMemory;
  s_ShaderParams_117.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_117.m_pElements = s_ShaderParams_117.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_117.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_117.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_117.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067AA0
// Name: Teeth::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Teeth::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Teeth::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10067AB0
// Name: Teeth::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Teeth::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_116);
  s_ShaderInstance_116.__vftable = (Teeth::CShader_vtbl *)&Teeth::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067AD0
// Name: Teeth_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Teeth_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Teeth_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10067AE0
// Name: Teeth_DX9::_dynamic_initializer_for__ILLUMFACTOR__
// Source: json
//------------------------------------------------------------------------------
Teeth_DX9::CShaderParam *Teeth_DX9::_dynamic_initializer_for__ILLUMFACTOR__()
{
  return Teeth_DX9::CShaderParam::CShaderParam(
           this: &ILLUMFACTOR,
           pName: "$ILLUMFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1",
           pHelp: "Amount to darken or brighten the teeth",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067B00
// Name: Teeth_DX9::_dynamic_initializer_for__FORWARD__
// Source: json
//------------------------------------------------------------------------------
Teeth_DX9::CShaderParam *Teeth_DX9::_dynamic_initializer_for__FORWARD__()
{
  return Teeth_DX9::CShaderParam::CShaderParam(
           this: &FORWARD,
           pName: "$FORWARD",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[1 0 0]",
           pHelp: "Forward direction vector for teeth lighting",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067B20
// Name: Teeth_DX9::_dynamic_initializer_for__BUMPMAP__
// Source: json
//------------------------------------------------------------------------------
Teeth_DX9::CShaderParam *Teeth_DX9::_dynamic_initializer_for__BUMPMAP__()
{
  return Teeth_DX9::CShaderParam::CShaderParam(
           this: &BUMPMAP_7,
           pName: "$BUMPMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "models/shadertest/shader1_normal",
           pHelp: "bump map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067B40
// Name: Teeth_DX9::_dynamic_initializer_for__PHONGEXPONENT__
// Source: json
//------------------------------------------------------------------------------
Teeth_DX9::CShaderParam *Teeth_DX9::_dynamic_initializer_for__PHONGEXPONENT__()
{
  return Teeth_DX9::CShaderParam::CShaderParam(
           this: &PHONGEXPONENT_3,
           pName: "$PHONGEXPONENT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "100",
           pHelp: "phong exponent",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067B60
// Name: Teeth_DX9::_dynamic_initializer_for__ENTITYORIGIN__
// Source: json
//------------------------------------------------------------------------------
Teeth_DX9::CShaderParam *Teeth_DX9::_dynamic_initializer_for__ENTITYORIGIN__()
{
  return Teeth_DX9::CShaderParam::CShaderParam(
           this: &ENTITYORIGIN_1,
           pName: "$ENTITYORIGIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "0.0",
           pHelp: "center if the model in world space",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067B80
// Name: Teeth_DX9::_dynamic_initializer_for__WARPPARAM__
// Source: json
//------------------------------------------------------------------------------
Teeth_DX9::CShaderParam *Teeth_DX9::_dynamic_initializer_for__WARPPARAM__()
{
  return Teeth_DX9::CShaderParam::CShaderParam(
           this: &WARPPARAM_1,
           pName: "$WARPPARAM",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "animation param between 0 and 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067BA0
// Name: Teeth_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Teeth_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_117);
  s_ShaderInstance_117.__vftable = (Teeth_DX9::CShader_vtbl *)&Teeth_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B800
// Name: Teeth::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Teeth::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_116);
}

//------------------------------------------------------------------------------
// Address: 0x1006B810
// Name: Teeth_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Teeth_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_117);
}

//------------------------------------------------------------------------------
// Address: 0x10067BC0
// Name: _dynamic_initializer_for__s_ConstructMe_treeleaf_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_treeleaf_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &treeleaf_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067BE0
// Name: _dynamic_initializer_for__s_ConstructMe_treeleaf_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_treeleaf_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &treeleaf_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067C00
// Name: _dynamic_initializer_for__s_ConstructMe_treeleaf_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_treeleaf_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &treeleaf_vs20_combos);
}
