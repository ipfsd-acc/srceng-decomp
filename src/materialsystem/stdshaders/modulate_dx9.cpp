// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/modulate_dx9.cpp
// Functions: 31
// ============================================================

#include "materialsystem\stdshaders\modulate_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1001D750
// Name: public: virtual char const __near * Modulate::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Modulate::CShader::GetFallbackShader(Modulate::CShader *this, IMaterialVar **params)
{
  return "Modulate_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x1001D760
// Name: public: virtual char const __near * Modulate::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Modulate::CShader::GetName(Modulate::CShader *this)
{
  return s_Name_56;
}

//------------------------------------------------------------------------------
// Address: 0x1001D770
// Name: public: virtual int Modulate::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Modulate::CShader::GetFlags(Modulate::CShader *this)
{
  return s_nFlags_79;
}

//------------------------------------------------------------------------------
// Address: 0x1001D780
// Name: public: virtual int Modulate::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Modulate::CShader::GetParamCount(Modulate::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_57.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001D790
// Name: public: virtual bool Modulate_DX9::CShader::NeedsPowerOfTwoFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Modulate_DX9::CShader::NeedsPowerOfTwoFrameBufferTexture(
        Modulate_DX9::CShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  float x; // xmm0_4

  return params[CLOAKPASSENABLED_0.m_Index]->m_intVal != 0
      && (!bCheckSpecificToThisFrame || (x = params[CLOAKFACTOR_1.m_Index]->m_VecVal.x) > 0.0 && x < 1.0)
      || (params[2]->m_intVal & 0x4000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D7F0
// Name: public: virtual bool Modulate_DX9::CShader::IsTranslucent(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Modulate_DX9::CShader::IsTranslucent(Modulate_DX9::CShader *this, IMaterialVar **params)
{
  float x; // xmm0_4

  return params[CLOAKPASSENABLED_0.m_Index]->m_intVal != 0
      && (x = params[CLOAKFACTOR_1.m_Index]->m_VecVal.x) > 0.0
      && x < 1.0
      || ((*params)->m_intVal & 0x200000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D840
// Name: public: virtual void Modulate_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Modulate_DX9::CShader::OnInitShaderParams(
        Modulate_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  CloakBlendedPassVars_t info; // [esp+8h] [ebp-18h] BYREF

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  if ( params[CLOAKPASSENABLED_0.m_Index]->IsDefined(this: params[CLOAKPASSENABLED_0.m_Index]) )
  {
    if ( params[CLOAKPASSENABLED_0.m_Index]->m_intVal != 0 )
    {
      memset(&info.m_nBumpmap, 255, 12);
      info.m_nCloakFactor = CLOAKFACTOR_1.m_Index;
      info.m_nCloakColorTint = CLOAKCOLORTINT_0.m_Index;
      info.m_nRefractAmount = REFRACTAMOUNT_3.m_Index;
      InitParamsCloakBlendedPass(pShader: this, params, pMaterialName, &info);
    }
  }
  else
  {
    params[CLOAKPASSENABLED_0.m_Index]->SetIntValue(this: params[CLOAKPASSENABLED_0.m_Index], a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D8F0
// Name: public: virtual char const __near * Modulate_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Modulate_DX9::CShader::GetName(Modulate_DX9::CShader *this)
{
  return s_Name_57;
}

//------------------------------------------------------------------------------
// Address: 0x1001D900
// Name: public: virtual int Modulate_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Modulate_DX9::CShader::GetFlags(Modulate_DX9::CShader *this)
{
  return s_nFlags_80;
}

//------------------------------------------------------------------------------
// Address: 0x1001D910
// Name: public: virtual void Modulate_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Modulate_DX9::CShader::OnInitShaderInstance(
        Modulate_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  CloakBlendedPassVars_t info; // [esp+8h] [ebp-18h] BYREF

  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
  if ( params[CLOAKPASSENABLED_0.m_Index]->m_intVal != 0 )
  {
    info.m_nCloakFactor = CLOAKFACTOR_1.m_Index;
    memset(&info.m_nBumpmap, 255, 12);
    info.m_nCloakColorTint = CLOAKCOLORTINT_0.m_Index;
    info.m_nRefractAmount = REFRACTAMOUNT_3.m_Index;
    InitCloakBlendedPass(pShader: this, params, &info);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D990
// Name: public: virtual int Modulate_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Modulate_DX9::CShader::GetParamCount(Modulate_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_56.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001D9A0
// Name: public: virtual void Modulate_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Modulate_DX9::CShader::OnDrawElements(
        Modulate_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IShaderShadow *v7; // edi
  bool v8; // zf
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  BOOL v13; // ebx
  bool v14; // cc
  void (__thiscall *SetPixelShader)(IShaderShadow *, const char *, int); // edx
  BOOL v16; // ecx
  BOOL v17; // ebx
  BOOL v18; // edi
  CBaseVSShader *v19; // ebx
  BOOL v20; // eax
  CBaseVSShader *v21; // ebx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v24; // ebx
  int v25; // eax
  bool v26; // al
  BOOL v27; // ebx
  BOOL v28; // eax
  CBaseVSShader *v29; // ebx
  MaterialFogMode_t v30; // eax
  double v31; // st7
  void (__thiscall *v32)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v33; // ebx
  BOOL v34; // edi
  int v35; // eax
  MaterialFogMode_t v36; // eax
  bool v37; // bl
  BOOL v38; // edi
  bool v39; // al
  BOOL v40; // eax
  float x; // xmm0_4
  const char *v42; // [esp-4h] [ebp-60h]
  const char *v43; // [esp-4h] [ebp-60h]
  int v44; // [esp+0h] [ebp-5Ch]
  CloakBlendedPassVars_t info; // [esp+Ch] [ebp-50h] BYREF
  float vSubDDimensions[4]; // [esp+24h] [ebp-38h] BYREF
  float vVertexColor[4]; // [esp+34h] [ebp-28h] BYREF
  int v48; // [esp+44h] [ebp-18h] BYREF
  modulate_ps30_Dynamic_Index _pshIndex; // [esp+48h] [ebp-14h] BYREF
  TessellationMode_t nTessellationMode; // [esp+50h] [ebp-Ch]
  CBaseVSShader *pShader; // [esp+54h] [ebp-8h]
  bool bMod2X; // [esp+59h] [ebp-3h]
  bool bWriteZ; // [esp+5Ah] [ebp-2h]
  bool bVertexColorOrAlpha; // [esp+5Bh] [ebp-1h]
  char bFullyOpaque_3; // [esp+6Fh] [ebp+13h]

  pShader = this;
  v7 = pShaderShadow;
  if ( params[CLOAKPASSENABLED_0.m_Index]->m_intVal != 0 && pShaderShadow == nullptr )
  {
    info.m_nCloakFactor = CLOAKFACTOR_1.m_Index;
    memset(&info.m_nBumpmap, 255, 12);
    info.m_nCloakColorTint = CLOAKCOLORTINT_0.m_Index;
    info.m_nRefractAmount = REFRACTAMOUNT_3.m_Index;
    if ( CloakBlendedPassIsFullyOpaque(params, &info) )
    {
      CBaseShader::Draw(this: pShader, bMakeActualDrawCall: false);
      v29 = pShader;
      goto LABEL_91;
    }
  }
  if ( !params[MOD2X.m_Index]->IsDefined(this: params[MOD2X.m_Index])
    || (v8 = params[MOD2X.m_Index]->m_intVal == 0, bMod2X = true, v8) )
  {
    bMod2X = false;
  }
  if ( ((*params)->m_intVal & 0x10) != 0
    || (v9 = (unsigned int)(*params)->m_intVal >> 5, bVertexColorOrAlpha = false, (v9 & 1) != 0) )
  {
    bVertexColorOrAlpha = true;
  }
  bWriteZ = params[WRITEZ.m_Index]->m_intVal != 0;
  v10 = CBaseVSShader::EvaluateBlendRequirements(
          this: pShader,
          textureVar: 6,
          isBaseTexture: true,
          detailTextureVar: -1);
  if ( v10 == 3 || v10 == 1 || (bFullyOpaque_3 = 1, ((*params)->m_intVal & 0x100) != 0) )
    bFullyOpaque_3 = 0;
  if ( pShaderShadow != nullptr )
  {
    if ( bMod2X )
      CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_DST_COLOR, dst: SHADER_BLEND_SRC_COLOR);
    else
      CBaseShader::EnableAlphaBlending(this: pShader, src: SHADER_BLEND_DST_COLOR, dst: SHADER_BLEND_ZERO);
    if ( bWriteZ )
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: true);
    v11 = 0;
    v12 = 1;
    if ( (*((_BYTE *)params[6] + 28) & 0xF) == 3 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      v11 = 1;
    }
    if ( bVertexColorOrAlpha )
      v12 = 5;
    if ( (v12 & 4) == 0 && v11 == 0 )
      v11 = 1;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v12 | 0x400, a3: v11, a4: nullptr, a5: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x800000);
      v16 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
      v17 = bVertexColorOrAlpha;
      v18 = v16;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "VERTEXCOLOR",
          bVertexColorOrAlpha,
          "bVertexColorOrAlpha ? 1 : 0");
      pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "unlitgeneric_vs30", a3: 8 * (v17 + 2 * v18));
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "modulate_ps30", a3: 0);
      v7 = pShaderShadow;
    }
    else
    {
      unlitgeneric_vs20_Static_Index::unlitgeneric_vs20_Static_Index(
        this: (unlitgeneric_vs20_Static_Index *)&_pshIndex,
        pShaderShadow,
        params);
      v13 = bVertexColorOrAlpha;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS stat var %s = %d (%s)",
          "VERTEXCOLOR",
          bVertexColorOrAlpha,
          "bVertexColorOrAlpha ? 1 : 0");
      pShaderShadow->SetVertexShader(
        this: pShaderShadow,
        a2: "unlitgeneric_vs20",
        a3: 8 * (v13 + 2 * (_pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA + 2 * nTessellationMode)));
      v14 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      SetPixelShader = pShaderShadow->SetPixelShader;
      v44 = 0;
      if ( v14 )
        ((void (__thiscall *)(IShaderShadow *, const char *))SetPixelShader)(a1: pShaderShadow, a2: "modulate_ps20");
      else
        ((void (__thiscall *)(IShaderShadow *, const char *))SetPixelShader)(a1: pShaderShadow, a2: "modulate_ps20b");
    }
    v19 = pShader;
    if ( bMod2X )
      CBaseShader::FogToGrey(this: pShader);
    else
      CBaseShader::FogToOOOverbright(this: pShader);
    LOBYTE(v20) = bWriteZ && bFullyOpaque_3 != 0;
    v7->EnableAlphaWrites(this: v7, a2: v20);
    CBaseShader::PI_BeginCommandBuffer(this: v19);
    CBaseShader::PI_SetModulationVertexShaderDynamicState(this: v19);
    CBaseShader::PI_EndCommandBuffer(this: v19);
  }
  if ( pShaderAPI == nullptr )
  {
LABEL_89:
    v29 = pShader;
    CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
    goto LABEL_91;
  }
  if ( (*((_BYTE *)params[6] + 28) & 0xF) == 3 )
  {
    v21 = pShader;
    CBaseShader::BindTexture(
      this: pShader,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: 6,
      nFrameVar: 7);
    CBaseVSShader::SetVertexShaderTextureTransform(this: v21, vertexReg: 48, transformVar: 8);
  }
  v48 = 1056964608;
  _pshIndex.m_nPIXELFOGTYPE = 1056964608;
  _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA = 1056964608;
  nTessellationMode = 1065353216;
  pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: (const float *)&v48, a4: 1, a5: false);
  pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
  pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: (float *)&info.m_nRefractAmount);
  SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
  info.m_nBumpTransform = 0;
  SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: (const float *)&info.m_nRefractAmount, a4: 1, a5: false);
  if ( bVertexColorOrAlpha )
    vVertexColor[0] = 1.0;
  else
    vVertexColor[0] = 0.0;
  SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
  memset(&vVertexColor[1], 0, 12);
  SetVertexShaderConstant(this: pShaderAPI, a2: 54, a3: vVertexColor, a4: 1, a5: false);
  if ( ((unsigned __int8 (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->HasFastVertexTextures)(
         a1: g_pHardwareConfig,
         a2: v44) != 0 )
  {
    nTessellationMode = pShaderAPI->GetTessellationMode(this: pShaderAPI);
    if ( nTessellationMode != TESSELLATION_MODE_DISABLED )
    {
      pShaderAPI->BindStandardVertexTexture(
        this: pShaderAPI,
        a2: SHADER_VERTEXTEXTURE_SAMPLER1,
        a3: TEXTURE_SUBDIVISION_PATCHES);
      v31 = ((double (__thiscall *)(IShaderDynamicAPI *))pShaderAPI->GetSubDHeight)(a1: pShaderAPI);
      v32 = pShaderAPI->SetVertexShaderConstant;
      memset(&vSubDDimensions[1], 0, 12);
      vSubDDimensions[0] = 1.0 / v31;
      v32(this: pShaderAPI, a2: 56, a3: vSubDDimensions, a4: 1, a5: false);
    }
    v33 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v34 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v35 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v35 > 0, v43);
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", nTessellationMode, "nTessellationMode");
      }
    }
    pShaderAPI->SetVertexShaderIndex(
      this: pShaderAPI,
      a2: vertexCompression + 2 * (v34 + 2 * (nTessellationMode + v33)));
    v36 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    v37 = bWriteZ;
    v38 = v36 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v39 = bWriteZ && bFullyOpaque_3 != 0 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    nTessellationMode = v39;
    if ( g_shaderConfigDumpEnable )
    {
      v40 = v37 && bFullyOpaque_3 != 0 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITE_DEPTH_TO_DESTALPHA",
        v40,
        "bWriteZ && bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v38 + 2 * nTessellationMode);
    v7 = pShaderShadow;
    goto LABEL_89;
  }
  v24 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  LODWORD(vSubDDimensions[1]) = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
  if ( g_shaderConfigDumpEnable )
  {
    v25 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
            a1: pShaderAPI,
            a2: "pShaderAPI->GetCurrentNumBones() > 0");
    printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v25 > 0, v42);
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", 0, "0");
    }
  }
  pShaderAPI->SetVertexShaderIndex(
    this: pShaderAPI,
    a2: vertexCompression + 2 * (LODWORD(vSubDDimensions[1]) + 2 * v24));
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
  {
    v30 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v30 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    v29 = pShader;
    CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
  }
  else
  {
    _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
    v26 = bWriteZ && bFullyOpaque_3 != 0 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    v27 = v26;
    if ( g_shaderConfigDumpEnable )
    {
      v28 = bWriteZ && bFullyOpaque_3 != 0 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
      printf(
        format: "\n   PS dyn  var %s = %d (%s)",
        "WRITE_DEPTH_TO_DESTALPHA",
        v28,
        "bWriteZ && bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
    }
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA + 2 * v27);
    v29 = pShader;
    CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
  }
LABEL_91:
  if ( params[CLOAKPASSENABLED_0.m_Index]->m_intVal != 0 )
  {
    if ( v7 != nullptr || (x = params[CLOAKFACTOR_1.m_Index]->m_VecVal.x) > 0.0 && x < 1.0 )
    {
      info.m_nCloakFactor = CLOAKFACTOR_1.m_Index;
      memset(&info.m_nBumpmap, 255, 12);
      info.m_nCloakColorTint = CLOAKCOLORTINT_0.m_Index;
      info.m_nRefractAmount = REFRACTAMOUNT_3.m_Index;
      DrawCloakBlendedPass(pShader: v29, params, pShaderAPI, pShaderShadow: v7, &info, vertexCompression);
    }
    else
    {
      CBaseShader::Draw(this: v29, bMakeActualDrawCall: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E190
// Name: public: virtual struct ShaderParamInfo_t const __near & Modulate::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Modulate::CShaderParam *__thiscall Modulate::CShader::GetParamInfo(Modulate::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_57.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Modulate::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001E1C0
// Name: public: virtual struct ShaderParamInfo_t const __near & Modulate_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Modulate_DX9::CShaderParam *__thiscall Modulate_DX9::CShader::GetParamInfo(Modulate_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_56.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Modulate_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001E1F0
// Name: public: Modulate_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Modulate_DX9::CShaderParam *__thiscall Modulate_DX9::CShaderParam::CShaderParam(
        Modulate_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Modulate_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Modulate_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_56.m_Size + 13;
  m_Size = s_ShaderParams_56.m_Size;
  v8 = s_ShaderParams_56.m_Size;
  if ( s_ShaderParams_56.m_Size + 1 > s_ShaderParams_56.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_56,
      num: s_ShaderParams_56.m_Size - s_ShaderParams_56.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_56.m_Size;
  }
  m_pMemory = s_ShaderParams_56.m_Memory.m_pMemory;
  s_ShaderParams_56.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_56.m_pElements = s_ShaderParams_56.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_56.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_56.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_56.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100357B0
// Name: public: unlitgeneric_vs20_Static_Index::unlitgeneric_vs20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
unlitgeneric_vs20_Static_Index *__thiscall unlitgeneric_vs20_Static_Index::unlitgeneric_vs20_Static_Index(
        unlitgeneric_vs20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  BOOL v4; // ecx

  this->m_nVERTEXCOLOR = 0;
  this->m_nDOPIXELFOG = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
  v4 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  this->m_nHARDWAREFOGBLEND = v4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063190
// Name: Modulate::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Modulate::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Modulate::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100631A0
// Name: Modulate::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Modulate::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_57);
  s_ShaderInstance_57.__vftable = (Modulate::CShader_vtbl *)&Modulate::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100631C0
// Name: Modulate_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Modulate_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Modulate_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100631D0
// Name: Modulate_DX9::_dynamic_initializer_for__WRITEZ__
// Source: json
//------------------------------------------------------------------------------
Modulate_DX9::CShaderParam *Modulate_DX9::_dynamic_initializer_for__WRITEZ__()
{
  return Modulate_DX9::CShaderParam::CShaderParam(
           this: &WRITEZ,
           pName: "$WRITEZ",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Forces z to be written if set",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100631F0
// Name: Modulate_DX9::_dynamic_initializer_for__MOD2X__
// Source: json
//------------------------------------------------------------------------------
Modulate_DX9::CShaderParam *Modulate_DX9::_dynamic_initializer_for__MOD2X__()
{
  return Modulate_DX9::CShaderParam::CShaderParam(
           this: &MOD2X,
           pName: "$MOD2X",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "forces a 2x modulate so that you can brighten and darken things",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063210
// Name: Modulate_DX9::_dynamic_initializer_for__CLOAKPASSENABLED__
// Source: json
//------------------------------------------------------------------------------
Modulate_DX9::CShaderParam *Modulate_DX9::_dynamic_initializer_for__CLOAKPASSENABLED__()
{
  return Modulate_DX9::CShaderParam::CShaderParam(
           this: &CLOAKPASSENABLED_0,
           pName: "$CLOAKPASSENABLED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enables cloak render in a second pass",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063230
// Name: Modulate_DX9::_dynamic_initializer_for__CLOAKFACTOR__
// Source: json
//------------------------------------------------------------------------------
Modulate_DX9::CShaderParam *Modulate_DX9::_dynamic_initializer_for__CLOAKFACTOR__()
{
  return Modulate_DX9::CShaderParam::CShaderParam(
           this: &CLOAKFACTOR_1,
           pName: "$CLOAKFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063250
// Name: Modulate_DX9::_dynamic_initializer_for__CLOAKCOLORTINT__
// Source: json
//------------------------------------------------------------------------------
Modulate_DX9::CShaderParam *Modulate_DX9::_dynamic_initializer_for__CLOAKCOLORTINT__()
{
  return Modulate_DX9::CShaderParam::CShaderParam(
           this: &CLOAKCOLORTINT_0,
           pName: "$CLOAKCOLORTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Cloak color tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063270
// Name: Modulate_DX9::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Modulate_DX9::CShaderParam *Modulate_DX9::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return Modulate_DX9::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_3,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063290
// Name: Modulate_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Modulate_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_56);
  s_ShaderInstance_56.__vftable = (Modulate_DX9::CShader_vtbl *)&Modulate_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B380
// Name: Modulate::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Modulate::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_57);
}

//------------------------------------------------------------------------------
// Address: 0x1006B390
// Name: Modulate_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Modulate_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_56);
}

//------------------------------------------------------------------------------
// Address: 0x100632B0
// Name: _dynamic_initializer_for__s_ConstructMe_unlittwotexture_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_unlittwotexture_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &unlittwotexture_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100632D0
// Name: _dynamic_initializer_for__s_ConstructMe_monitorscreen_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_monitorscreen_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &monitorscreen_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100632F0
// Name: _dynamic_initializer_for__s_ConstructMe_monitorscreen_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_monitorscreen_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &monitorscreen_ps20b_combos);
}
