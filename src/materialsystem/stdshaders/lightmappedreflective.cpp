// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/lightmappedreflective.cpp
// Functions: 32
// ============================================================

#include "materialsystem\stdshaders\lightmappedreflective.h"

//------------------------------------------------------------------------------
// Address: 0x1001BAD0
// Name: public: virtual char const __near * LightmappedReflective::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall LightmappedReflective::CShader::GetFallbackShader(
        LightmappedReflective::CShader *this,
        IMaterialVar **params)
{
  return "LightmappedReflective_DX90";
}

//------------------------------------------------------------------------------
// Address: 0x1001BAE0
// Name: public: virtual char const __near * LightmappedReflective::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall LightmappedReflective::CShader::GetName(LightmappedReflective::CShader *this)
{
  return s_Name_52;
}

//------------------------------------------------------------------------------
// Address: 0x1001BAF0
// Name: public: virtual int LightmappedReflective::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightmappedReflective::CShader::GetFlags(LightmappedReflective::CShader *this)
{
  return s_nFlags_75;
}

//------------------------------------------------------------------------------
// Address: 0x1001BB00
// Name: public: virtual int LightmappedReflective::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightmappedReflective::CShader::GetParamCount(LightmappedReflective::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_53.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001BB10
// Name: public: virtual void LightmappedReflective_DX90::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightmappedReflective_DX90::CShader::OnInitShaderParams(
        LightmappedReflective_DX90::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[REFLECTANCE.m_Index]->IsDefined(this: params[REFLECTANCE.m_Index]) )
    ((void (__stdcall *)(int))params[REFLECTANCE.m_Index]->SetFloatValue)(a1: 1048576000);
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  if ( params[6]->IsDefined(this: params[6]) )
  {
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 4);
    if ( (g_pConfig->m_Flags & 0x100) == 0 && params[NORMALMAP_3.m_Index]->IsDefined(this: params[NORMALMAP_3.m_Index]) )
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BBC0
// Name: public: virtual char const __near * LightmappedReflective_DX90::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall LightmappedReflective_DX90::CShader::GetName(LightmappedReflective_DX90::CShader *this)
{
  return s_Name_53;
}

//------------------------------------------------------------------------------
// Address: 0x1001BBD0
// Name: public: virtual int LightmappedReflective_DX90::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightmappedReflective_DX90::CShader::GetFlags(LightmappedReflective_DX90::CShader *this)
{
  return s_nFlags_76;
}

//------------------------------------------------------------------------------
// Address: 0x1001BBE0
// Name: public: virtual void LightmappedReflective_DX90::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightmappedReflective_DX90::CShader::OnInitShaderInstance(
        LightmappedReflective_DX90::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  HDRType_t v5; // eax
  HDRType_t v6; // eax

  if ( params[REFRACTTEXTURE.m_Index]->IsDefined(this: params[REFRACTTEXTURE.m_Index]) )
  {
    v5 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
    CBaseShader::LoadTexture(
      this,
      nTextureVar: REFRACTTEXTURE.m_Index,
      nAdditionalCreationFlags: v5 != HDR_TYPE_INTEGER ? 0 : 0x80000);
  }
  if ( params[REFLECTTEXTURE.m_Index]->IsDefined(this: params[REFLECTTEXTURE.m_Index]) )
  {
    v6 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
    CBaseShader::LoadTexture(
      this,
      nTextureVar: REFLECTTEXTURE.m_Index,
      nAdditionalCreationFlags: v6 != HDR_TYPE_INTEGER ? 0 : 0x80000);
  }
  if ( params[NORMALMAP_3.m_Index]->IsDefined(this: params[NORMALMAP_3.m_Index]) )
    CBaseShader::LoadBumpMap(this, nTextureVar: NORMALMAP_3.m_Index, nAdditionalCreationFlags: 0);
  if ( params[6]->IsDefined(this: params[6]) )
  {
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
    if ( params[ENVMAPMASK_0.m_Index]->IsDefined(this: params[ENVMAPMASK_0.m_Index]) )
      CBaseShader::LoadTexture(this, nTextureVar: ENVMAPMASK_0.m_Index, nAdditionalCreationFlags: 0);
  }
  else
  {
    params[ENVMAPMASK_0.m_Index]->SetUndefined(this: params[ENVMAPMASK_0.m_Index]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BCF0
// Name: public: virtual int LightmappedReflective_DX90::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall LightmappedReflective_DX90::CShader::GetParamCount(LightmappedReflective_DX90::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_52.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001BD00
// Name: public: void LightmappedReflective_DX90::CShader::DrawReflectionRefraction(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightmappedReflective_DX90::CShader::DrawReflectionRefraction(
        LightmappedReflective_DX90::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        bool bReflection,
        bool bRefraction)
{
  int v7; // eax
  unsigned int v9; // ecx
  HDRType_t v10; // eax
  HDRType_t v11; // eax
  IShaderShadow_vtbl *v12; // edi
  HDRType_t v13; // eax
  IShaderShadow_vtbl *v14; // edi
  HDRType_t v15; // eax
  int v16; // eax
  char v17; // cl
  BOOL v18; // edi
  int v19; // eax
  float v20; // ecx
  char v21; // cl
  char v22; // al
  bool v23; // cl
  BOOL v24; // edi
  BOOL v25; // eax
  char v26; // cl
  char v27; // al
  bool v28; // cl
  BOOL v29; // edi
  BOOL v30; // eax
  TextureBindFlags_t v31; // edi
  CBaseVSShader *v32; // edi
  int v33; // eax
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v35)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float x; // xmm0_4
  void (__thiscall *v37)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v38; // eax
  void (__thiscall *v39)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v40; // xmm0_4
  IMaterialVar *v41; // eax
  void (__thiscall *v42)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v43; // cc
  MaterialFogMode_t (__thiscall *GetSceneFogMode)(IShaderDynamicAPI *); // edx
  int v45; // eax
  bool v46; // bl
  bool v47; // al
  BOOL v48; // edi
  BOOL v49; // eax
  int v50; // eax
  TextureBindFlags_t v51; // [esp-Ch] [ebp-78h]
  float vEyePos_SpecExponent[4]; // [esp+Ch] [ebp-60h] BYREF
  float c5[4]; // [esp+1Ch] [ebp-50h] BYREF
  float c2[4]; // [esp+2Ch] [ebp-40h] BYREF
  float c0[4]; // [esp+3Ch] [ebp-30h] BYREF
  float c3[4]; // [esp+4Ch] [ebp-20h] BYREF
  lightmappedreflective_ps20b_Dynamic_Index _pshIndex; // [esp+5Ch] [ebp-10h]
  BOOL bFullyOpaque; // [esp+64h] [ebp-8h]
  CBaseShader *v59; // [esp+68h] [ebp-4h]
  BOOL paramsa; // [esp+74h] [ebp+8h]
  BOOL paramsb; // [esp+74h] [ebp+8h]
  IMaterialVar **paramsc; // [esp+74h] [ebp+8h]

  v59 = this;
  v7 = CBaseVSShader::EvaluateBlendRequirements(this, textureVar: 6, isBaseTexture: true, detailTextureVar: -1);
  if ( v7 == 3 || v7 == 1 || (v9 = (unsigned int)(*params)->m_intVal >> 8, LOBYTE(bFullyOpaque) = 1, (v9 & 1) != 0) )
    LOBYTE(bFullyOpaque) = 0;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this);
    if ( bRefraction )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
      v10 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      LOBYTE(v10) = v10 == HDR_TYPE_INTEGER;
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: v10);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    }
    if ( bReflection )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
      v11 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      LOBYTE(v11) = v11 == HDR_TYPE_INTEGER;
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: v11);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
      v12 = pShaderShadow->__vftable;
      v13 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      v12->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: v13 == HDR_TYPE_NONE);
    }
    if ( (*((_BYTE *)params[6] + 28) & 0xF) == 3 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
      v14 = pShaderShadow->__vftable;
      v15 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      v14->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: v15 == HDR_TYPE_NONE);
      if ( (*((_BYTE *)params[ENVMAPMASK_0.m_Index] + 28) & 0xF) == 3 )
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    }
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER4, a3: true);
    v16 = 1;
    if ( (*((_BYTE *)params[6] + 28) & 0xF) == 3 )
      v16 = 3;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 51u, a3: v16, a4: nullptr, a5: 0);
    if ( ((*params)->m_intVal & 0x200000) != 0 )
      CBaseShader::EnableAlphaBlending(this: v59, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    v17 = *((_BYTE *)params[6] + 28) & 0xF;
    v18 = v17 == 3;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "BASETEXTURE", v17 == 3, "params[BASETEXTURE]->IsTexture()");
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "lightmappedreflective_vs20", a3: v18);
    v19 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v20 = 0.0;
    if ( v19 < 92 )
    {
      LOBYTE(v20) = bReflection;
      c5[1] = v20;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFLECT", bReflection, "bReflection");
      LODWORD(c5[2]) = bRefraction;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFRACT", bRefraction, "bRefraction");
      v26 = *((_BYTE *)params[6] + 28) & 0xF;
      paramsb = v26 == 3;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE", v26 == 3, "params[BASETEXTURE]->IsTexture()");
      v27 = *((_BYTE *)params[ENVMAPMASK_0.m_Index] + 28) & 0xF;
      v28 = v27 == 3 && (*((_BYTE *)params[6] + 28) & 0xF) == 3;
      v29 = v28;
      if ( g_shaderConfigDumpEnable )
      {
        v30 = v27 == 3 && (*((_BYTE *)params[6] + 28) & 0xF) == 3;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "ENVMAPMASK",
          v30,
          "params[ENVMAPMASK]->IsTexture() && params[BASETEXTURE]->IsTexture()");
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "lightmappedreflective_ps20",
        a3: 2 * (paramsb + 2 * (LODWORD(c5[1]) + 2 * (LODWORD(c5[2]) + 2 * v29))));
    }
    else
    {
      LOBYTE(v20) = bReflection;
      c5[1] = v20;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFLECT", bReflection, "bReflection");
      LODWORD(c5[2]) = bRefraction;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "REFRACT", bRefraction, "bRefraction");
      v21 = *((_BYTE *)params[6] + 28) & 0xF;
      paramsa = v21 == 3;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "BASETEXTURE", v21 == 3, "params[BASETEXTURE]->IsTexture()");
      v22 = *((_BYTE *)params[ENVMAPMASK_0.m_Index] + 28) & 0xF;
      v23 = v22 == 3 && (*((_BYTE *)params[6] + 28) & 0xF) == 3;
      v24 = v23;
      if ( g_shaderConfigDumpEnable )
      {
        v25 = v22 == 3 && (*((_BYTE *)params[6] + 28) & 0xF) == 3;
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "ENVMAPMASK",
          v25,
          "params[ENVMAPMASK]->IsTexture() && params[BASETEXTURE]->IsTexture()");
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "lightmappedreflective_ps20b",
        a3: 4 * (paramsa + 2 * (LODWORD(c5[1]) + 2 * (LODWORD(c5[2]) + 2 * v24))));
    }
    CBaseShader::FogToFogColor(this: v59);
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: bFullyOpaque);
  }
  if ( pShaderAPI == nullptr )
    goto LABEL_86;
  v31 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) != HDR_TYPE_INTEGER ? TEXTURE_BINDFLAGS_NONE : 0x80000000;
  if ( bRefraction )
    CBaseShader::BindTexture(
      this: v59,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: v31,
      nTextureVar: REFRACTTEXTURE.m_Index,
      nFrameVar: -1);
  if ( bReflection )
  {
    v51 = v31;
    v32 = (CBaseVSShader *)v59;
    CBaseShader::BindTexture(
      this: v59,
      sampler1: SHADER_SAMPLER2,
      nBindFlags: v51,
      nTextureVar: REFLECTTEXTURE.m_Index,
      nFrameVar: -1);
  }
  else
  {
    v32 = (CBaseVSShader *)v59;
  }
  CBaseShader::BindTexture(
    this: v32,
    sampler1: SHADER_SAMPLER4,
    nBindFlags: TEXTURE_BINDFLAGS_NONE,
    nTextureVar: NORMALMAP_3.m_Index,
    nFrameVar: BUMPFRAME_4.m_Index);
  if ( (*((_BYTE *)params[6] + 28) & 0xF) == 3 )
  {
    CBaseShader::BindTexture(
      this: v32,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: 6,
      nFrameVar: 7);
    paramsc = (IMaterialVar **)pShaderAPI->__vftable;
    v33 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, _DWORD))g_pHardwareConfig->GetHDRType)(
            a1: g_pHardwareConfig,
            a2: 0);
    ((void (__thiscall *)(IShaderDynamicAPI *, int, unsigned int))paramsc[21])(
      a1: pShaderAPI,
      a2: 3,
      a3: v33 != 0 ? 0 : 0x80000000);
    CBaseVSShader::SetVertexShaderTextureTransform(this: v32, vertexReg: 51, transformVar: 8);
    if ( (*((_BYTE *)params[ENVMAPMASK_0.m_Index] + 28) & 0xF) == 3 )
      CBaseShader::BindTexture(
        this: v32,
        sampler1: SHADER_SAMPLER6,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: ENVMAPMASK_0.m_Index,
        nFrameVar: ENVMAPMASKFRAME_0.m_Index);
  }
  if ( bRefraction )
    CBaseVSShader::SetPixelShaderConstantGammaToLinear(this: v32, pixelReg: 1, constantVar: REFRACTTINT_0.m_Index);
  if ( bReflection )
    CBaseVSShader::SetPixelShaderConstantGammaToLinear(this: v32, pixelReg: 4, constantVar: REFLECTTINT.m_Index);
  CBaseVSShader::SetVertexShaderTextureTransform(this: v32, vertexReg: 49, transformVar: BUMPTRANSFORM_2.m_Index);
  SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
  c0[0] = 0.33333334;
  c0[1] = 0.33333334;
  c0[2] = 0.33333334;
  c0[3] = 0.0;
  SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: c0, a4: 1, a5: false);
  v35 = pShaderAPI->SetPixelShaderConstant;
  c2[0] = 0.5;
  c2[1] = 0.5;
  c2[2] = 0.5;
  c2[3] = 0.5;
  v35(this: pShaderAPI, a2: 2, a3: c2, a4: 1, a5: false);
  x = params[REFLECTANCE.m_Index]->m_VecVal.x;
  if ( x >= 0.0 )
  {
    if ( x <= 1.0 )
      c3[0] = params[REFLECTANCE.m_Index]->m_VecVal.x;
    else
      c3[0] = 1.0;
  }
  else
  {
    c3[0] = 0.0;
  }
  v37 = pShaderAPI->SetPixelShaderConstant;
  memset(&c3[1], 0, 12);
  v37(this: pShaderAPI, a2: 3, a3: c3, a4: 1, a5: false);
  v38 = params[REFLECTAMOUNT.m_Index];
  v39 = pShaderAPI->SetPixelShaderConstant;
  c5[0] = v38->m_VecVal.x;
  v40 = v38->m_VecVal.x;
  v41 = params[REFRACTAMOUNT_2.m_Index];
  c5[1] = v40;
  c5[2] = v41->m_VecVal.x;
  c5[3] = v41->m_VecVal.x;
  v39(this: pShaderAPI, a2: 5, a3: c5, a4: 1, a5: false);
  pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
  pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
  v42 = pShaderAPI->SetPixelShaderConstant;
  vEyePos_SpecExponent[3] = 0.0;
  v42(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
  pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: 0);
  v43 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  GetSceneFogMode = pShaderAPI->GetSceneFogMode;
  if ( v43 )
  {
    v50 = GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v50 == 2);
LABEL_86:
    CBaseShader::Draw(this: v59, bMakeActualDrawCall: true);
    return;
  }
  v45 = GetSceneFogMode(this: pShaderAPI);
  v46 = bFullyOpaque;
  _pshIndex.m_nPIXELFOGTYPE = v45 == 2;
  v47 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
  v48 = v47;
  if ( g_shaderConfigDumpEnable )
  {
    v49 = v46 && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    printf(
      format: "\n   PS dyn  var %s = %d (%s)",
      "WRITE_DEPTH_TO_DESTALPHA",
      v49,
      "bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
  }
  pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: _pshIndex.m_nPIXELFOGTYPE + 2 * v48);
  CBaseShader::Draw(this: v59, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001C4E0
// Name: public: virtual void LightmappedReflective_DX90::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightmappedReflective_DX90::CShader::OnDrawElements(
        LightmappedReflective_DX90::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  LightmappedReflective_DX90::CShader::DrawReflectionRefraction(
    this,
    params,
    pShaderShadow,
    pShaderAPI,
    bReflection: (*((_BYTE *)params[REFLECTTEXTURE.m_Index] + 28) & 0xF) == 3,
    bRefraction: (*((_BYTE *)params[REFRACTTEXTURE.m_Index] + 28) & 0xF) == 3);
}

//------------------------------------------------------------------------------
// Address: 0x1001C530
// Name: public: virtual struct ShaderParamInfo_t const __near & LightmappedReflective::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
LightmappedReflective::CShaderParam *__thiscall LightmappedReflective::CShader::GetParamInfo(
        LightmappedReflective::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_53.m_Memory.m_pMemory[param - ParamCount];
  else
    return (LightmappedReflective::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001C560
// Name: public: virtual struct ShaderParamInfo_t const __near & LightmappedReflective_DX90::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *__thiscall LightmappedReflective_DX90::CShader::GetParamInfo(
        LightmappedReflective_DX90::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_52.m_Memory.m_pMemory[param - ParamCount];
  else
    return (LightmappedReflective_DX90::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001C590
// Name: public: LightmappedReflective_DX90::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *__thiscall LightmappedReflective_DX90::CShaderParam::CShaderParam(
        LightmappedReflective_DX90::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  LightmappedReflective_DX90::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  LightmappedReflective_DX90::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_52.m_Size + 13;
  m_Size = s_ShaderParams_52.m_Size;
  v8 = s_ShaderParams_52.m_Size;
  if ( s_ShaderParams_52.m_Size + 1 > s_ShaderParams_52.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_52,
      num: s_ShaderParams_52.m_Size - s_ShaderParams_52.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_52.m_Size;
  }
  m_pMemory = s_ShaderParams_52.m_Memory.m_pMemory;
  s_ShaderParams_52.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_52.m_pElements = s_ShaderParams_52.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_52.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_52.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_52.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062B90
// Name: LightmappedReflective::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int LightmappedReflective::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: LightmappedReflective::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10062BA0
// Name: LightmappedReflective::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *LightmappedReflective::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_53);
  s_ShaderInstance_53.__vftable = (LightmappedReflective::CShader_vtbl *)&LightmappedReflective::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062BC0
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int LightmappedReflective_DX90::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: LightmappedReflective_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10062BD0
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__REFRACTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__REFRACTTEXTURE__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTEXTURE,
           pName: "$REFRACTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_WaterRefraction",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062BF0
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__REFLECTTEXTURE__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__REFLECTTEXTURE__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &REFLECTTEXTURE,
           pName: "$REFLECTTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "_rt_WaterReflection",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062C10
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_2,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062C30
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__REFRACTTINT__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__REFRACTTINT__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &REFRACTTINT_0,
           pName: "$REFRACTTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "refraction tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062C50
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__REFLECTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__REFLECTAMOUNT__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &REFLECTAMOUNT,
           pName: "$REFLECTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.8",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062C70
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__REFLECTTINT__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__REFLECTTINT__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &REFLECTTINT,
           pName: "$REFLECTTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "reflection tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062C90
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__NORMALMAP__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__NORMALMAP__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &NORMALMAP_3,
           pName: "$NORMALMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "dev/water_normal",
           pHelp: "normal map",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062CB0
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__BUMPFRAME__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__BUMPFRAME__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &BUMPFRAME_4,
           pName: "$BUMPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $bumpmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062CD0
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__BUMPTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__BUMPTRANSFORM__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &BUMPTRANSFORM_2,
           pName: "$BUMPTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$bumpmap texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062CF0
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__ENVMAPMASK__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__ENVMAPMASK__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &ENVMAPMASK_0,
           pName: "$ENVMAPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_envmask",
           pHelp: "envmap mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062D10
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__ENVMAPMASKFRAME__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__ENVMAPMASKFRAME__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &ENVMAPMASKFRAME_0,
           pName: "$ENVMAPMASKFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: pDefaultParam,
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062D30
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__REFLECTANCE__
// Source: json
//------------------------------------------------------------------------------
LightmappedReflective_DX90::CShaderParam *LightmappedReflective_DX90::_dynamic_initializer_for__REFLECTANCE__()
{
  return LightmappedReflective_DX90::CShaderParam::CShaderParam(
           this: &REFLECTANCE,
           pName: "$REFLECTANCE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.25",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10062D50
// Name: LightmappedReflective_DX90::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *LightmappedReflective_DX90::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_52);
  s_ShaderInstance_52.__vftable = (LightmappedReflective_DX90::CShader_vtbl *)&LightmappedReflective_DX90::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B330
// Name: LightmappedReflective::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl LightmappedReflective::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_53);
}

//------------------------------------------------------------------------------
// Address: 0x1006B340
// Name: LightmappedReflective_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl LightmappedReflective_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_52);
}
