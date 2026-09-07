// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/shatteredglass.cpp
// Functions: 29
// ============================================================

#include "materialsystem\stdshaders\shatteredglass.h"

//------------------------------------------------------------------------------
// Address: 0x1002E870
// Name: public: virtual void ShatteredGlass::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShatteredGlass::CShader::OnInitShaderParams(
        ShatteredGlass::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  if ( !params[DETAILSCALE_0.m_Index]->IsDefined(this: params[DETAILSCALE_0.m_Index]) )
    ((void (__stdcall *)(int))params[DETAILSCALE_0.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[ENVMAPTINT_2.m_Index]->IsDefined(this: params[ENVMAPTINT_2.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, int, int, int))params[ENVMAPTINT_2.m_Index]->SetVecValue_2)(
      a1: params[ENVMAPTINT_2.m_Index],
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216);
  if ( !params[ENVMAPCONTRAST_1.m_Index]->IsDefined(this: params[ENVMAPCONTRAST_1.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[ENVMAPCONTRAST_1.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[ENVMAPSATURATION_1.m_Index]->IsDefined(this: params[ENVMAPSATURATION_1.m_Index]) )
    ((void (__stdcall *)(int))params[ENVMAPSATURATION_1.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[UNLITFACTOR.m_Index]->IsDefined(this: params[UNLITFACTOR.m_Index]) )
    ((void (__stdcall *)(int))params[UNLITFACTOR.m_Index]->SetFloatValue)(a1: 1050253722);
  if ( !params[FRESNELREFLECTION_2.m_Index]->IsDefined(this: params[FRESNELREFLECTION_2.m_Index]) )
    ((void (__stdcall *)(int))params[FRESNELREFLECTION_2.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[ENVMAPMASKFRAME_1.m_Index]->IsDefined(this: params[ENVMAPMASKFRAME_1.m_Index]) )
    params[ENVMAPMASKFRAME_1.m_Index]->SetIntValue(this: params[ENVMAPMASKFRAME_1.m_Index], a2: 0);
  if ( !params[ENVMAPFRAME_1.m_Index]->IsDefined(this: params[ENVMAPFRAME_1.m_Index]) )
    params[ENVMAPFRAME_1.m_Index]->SetIntValue(this: params[ENVMAPFRAME_1.m_Index], a2: 0);
  if ( !params[BASETEXTURE.m_Index]->IsDefined(this: params[BASETEXTURE.m_Index]) )
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
  if ( ((*params)->m_intVal & 0x10000) != 0 )
    (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal | 2);
}

//------------------------------------------------------------------------------
// Address: 0x1002EA40
// Name: public: virtual char const __near * ShatteredGlass::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ShatteredGlass::CShader::GetName(ShatteredGlass::CShader *this)
{
  return s_Name_106;
}

//------------------------------------------------------------------------------
// Address: 0x1002EA50
// Name: public: virtual int ShatteredGlass::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShatteredGlass::CShader::GetFlags(ShatteredGlass::CShader *this)
{
  return s_nFlags_111;
}

//------------------------------------------------------------------------------
// Address: 0x1002EA60
// Name: public: virtual void ShatteredGlass::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShatteredGlass::CShader::OnInitShaderInstance(
        ShatteredGlass::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  int v5; // eax
  int m_Index; // esi
  HDRType_t v7; // eax

  if ( params[BASETEXTURE.m_Index]->IsDefined(this: params[BASETEXTURE.m_Index]) )
  {
    CBaseShader::LoadTexture(this, nTextureVar: BASETEXTURE.m_Index, nAdditionalCreationFlags: 0x80000);
    v5 = params[BASETEXTURE.m_Index]->GetTextureValue(this: params[BASETEXTURE.m_Index]);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 24))(a1: v5) == 0
      && ((*params)->m_intVal & 0x100000) != 0 )
    {
      (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal & 0xFFEFFFFF);
    }
  }
  if ( params[DETAIL_0.m_Index]->IsDefined(this: params[DETAIL_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: DETAIL_0.m_Index, nAdditionalCreationFlags: 0x80000);
  if ( ((*params)->m_intVal & 0x100000) != 0 )
    (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal & 0xFFFFFEFF);
  if ( params[ENVMAP_4.m_Index]->IsDefined(this: params[ENVMAP_4.m_Index]) )
  {
    CBaseShader::LoadCubeMap(this, nTextureVar: ENVMAP_4.m_Index, nAdditionalCreationFlags: 0);
    if ( params[ENVMAPMASK_1.m_Index]->IsDefined(this: params[ENVMAPMASK_1.m_Index]) )
    {
      m_Index = ENVMAPMASK_1.m_Index;
      v7 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      CBaseShader::LoadTexture(this, nTextureVar: m_Index, nAdditionalCreationFlags: v7 != HDR_TYPE_NONE ? 0 : 0x80000);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EB90
// Name: public: virtual void ShatteredGlass::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShatteredGlass::CShader::OnDrawElements(
        ShatteredGlass::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  char v7; // cl
  char v8; // dl
  int m_intVal; // eax
  IMaterialSystemHardwareConfig_vtbl *v10; // edx
  TextureBindFlags_t v12; // edi
  HDRType_t v13; // eax
  void (__thiscall *EnableSRGBRead)(IShaderShadow *, Sampler_t, bool); // edx
  int v15; // eax
  float v16; // ecx
  int v17; // eax
  int v18; // eax
  HDRType_t v19; // eax
  MaterialFogMode_t v20; // eax
  MaterialFogMode_t v21; // eax
  IMaterialVar *v22; // edx
  IShaderDynamicAPI_vtbl *v23; // eax
  int x_low; // xmm1_4
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v26; // eax
  void (__thiscall *v27)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  const char *v28; // [esp-4h] [ebp-4Ch]
  const char *v29; // [esp-4h] [ebp-4Ch]
  float eyePos[4]; // [esp+Ch] [ebp-3Ch] BYREF
  HDRType_t v31; // [esp+1Ch] [ebp-2Ch]
  float overbright[4]; // [esp+20h] [ebp-28h] BYREF
  float v33; // [esp+30h] [ebp-18h] BYREF
  shatteredglass_vs20_Static_Index _vshIndex; // [esp+34h] [ebp-14h] BYREF
  BOOL bSRGBReadEnvMap; // [esp+40h] [ebp-8h]
  bool bHasBaseAlphaEnvmapMask; // [esp+44h] [ebp-4h]
  bool bHasVertexColor; // [esp+45h] [ebp-3h]
  bool bHasEnvmap; // [esp+46h] [ebp-2h]
  bool bHasEnvmapMask; // [esp+47h] [ebp-1h]
  unsigned int flags; // [esp+54h] [ebp+Ch]
  unsigned int flagsa; // [esp+54h] [ebp+Ch]

  v7 = *((_BYTE *)params[ENVMAP_4.m_Index] + 28) & 0xF;
  bHasEnvmapMask = false;
  bHasEnvmap = false;
  if ( v7 == 3 )
  {
    v8 = *((_BYTE *)params[ENVMAPMASK_1.m_Index] + 28) & 0xF;
    bHasEnvmap = true;
    bHasEnvmapMask = v8 == 3;
  }
  m_intVal = (*params)->m_intVal;
  bHasVertexColor = (m_intVal & 0x10) != 0;
  v10 = g_pHardwareConfig->__vftable;
  bHasBaseAlphaEnvmapMask = (m_intVal & 0x100000) != 0;
  v12 = v10->GetHDRType(this: g_pHardwareConfig) != HDR_TYPE_NONE ? TEXTURE_BINDFLAGS_NONE : 0x80000000;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: (*params)->m_intVal & 0x100);
    if ( CBaseShader::TextureIsTranslucent(this, textureVar: DETAIL_0.m_Index, isBaseTexture: false) )
    {
      if ( ((*params)->m_intVal & 0x80) != 0 )
        CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE);
      else
        CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    }
    else
    {
      CBaseShader::SetDefaultBlendingShadowState(this, textureVar: BASETEXTURE.m_Index, isBaseTexture: true);
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    flags = 1;
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: v12 < TEXTURE_BINDFLAGS_NONE);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER3, a3: true);
    if ( bHasEnvmap )
    {
      flags = 3;
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: true);
      v13 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      EnableSRGBRead = pShaderShadow->EnableSRGBRead;
      LOBYTE(bSRGBReadEnvMap) = v13 == HDR_TYPE_NONE;
      EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER2, a3: bSRGBReadEnvMap);
      if ( bHasEnvmapMask )
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER5, a3: true);
    }
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER6, a3: true);
    if ( bHasVertexColor )
      flags |= 4u;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: flags, a3: 3, a4: nullptr, a5: 0);
    _vshIndex.m_nDOPIXELFOG = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    _vshIndex.m_nHARDWAREFOGBLEND = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
    flagsa = bHasEnvmapMask;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "ENVMAP_MASK", bHasEnvmapMask, "bHasEnvmapMask");
    pShaderShadow->SetVertexShader(
      this: pShaderShadow,
      a2: "shatteredglass_vs20",
      a3: 2 * (_vshIndex.m_nDOPIXELFOG + 2 * (_vshIndex.m_nHARDWAREFOGBLEND + 2 * flagsa)));
    v15 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v16 = 0.0;
    if ( v15 < 92 )
    {
      LOBYTE(v16) = bHasEnvmap;
      eyePos[0] = v16;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", bHasEnvmap, "bHasEnvmap");
      LODWORD(eyePos[1]) = bHasVertexColor;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", bHasVertexColor, "bHasVertexColor");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "ENVMAPMASK", bHasEnvmapMask, "bHasEnvmapMask");
      }
      LODWORD(eyePos[3]) = bHasBaseAlphaEnvmapMask;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "BASEALPHAENVMAPMASK",
          bHasBaseAlphaEnvmapMask,
          "bHasBaseAlphaEnvmapMask");
      v31 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      if ( g_shaderConfigDumpEnable )
      {
        v18 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
                a1: g_pHardwareConfig,
                a2: "g_pHardwareConfig->GetHDRType()");
        printf(format: "\n   PS stat var %s = %d (%s)", "HDRTYPE", v18, v29);
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "shatteredglass_ps20",
        a3: 2 * (LODWORD(eyePos[0]) + 2 * (LODWORD(eyePos[1]) + 2 * (flagsa + 2 * (LODWORD(eyePos[3]) + 2 * v31)))));
    }
    else
    {
      LOBYTE(v16) = bHasEnvmap;
      eyePos[0] = v16;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", bHasEnvmap, "bHasEnvmap");
      LODWORD(eyePos[1]) = bHasVertexColor;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", bHasVertexColor, "bHasVertexColor");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "ENVMAPMASK", bHasEnvmapMask, "bHasEnvmapMask");
      }
      LODWORD(eyePos[3]) = bHasBaseAlphaEnvmapMask;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS stat var %s = %d (%s)",
          "BASEALPHAENVMAPMASK",
          bHasBaseAlphaEnvmapMask,
          "bHasBaseAlphaEnvmapMask");
      v31 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      if ( g_shaderConfigDumpEnable )
      {
        v17 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
                a1: g_pHardwareConfig,
                a2: "g_pHardwareConfig->GetHDRType()");
        printf(format: "\n   PS stat var %s = %d (%s)", "HDRTYPE", v17, v28);
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "shatteredglass_ps20b",
        a3: 2 * (LODWORD(eyePos[0]) + 2 * (LODWORD(eyePos[1]) + 2 * (flagsa + 2 * (LODWORD(eyePos[3]) + 2 * v31)))));
    }
    CBaseShader::DefaultFog(this);
    CBaseShader::PI_BeginCommandBuffer(this);
    CBaseShader::PI_SetModulationPixelShaderDynamicState(this, nRegister: 1);
    CBaseShader::PI_EndCommandBuffer(this);
  }
  if ( pShaderAPI != nullptr )
  {
    CBaseVSShader::SetVertexShaderTextureTransform(this, vertexReg: 48, transformVar: 8);
    CBaseVSShader::SetVertexShaderTextureScale(this, vertexReg: 50, scaleVar: DETAILSCALE_0.m_Index);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: BASETEXTURE.m_Index,
      nFrameVar: 7);
    pShaderAPI->BindStandardTexture(this: pShaderAPI, a2: SHADER_SAMPLER1, a3: v12, a4: TEXTURE_LIGHTMAP);
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER3,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: DETAIL_0.m_Index,
      nFrameVar: -1);
    if ( bHasEnvmap )
    {
      v19 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      CBaseShader::BindTexture(
        this,
        sampler1: SHADER_SAMPLER2,
        nBindFlags: v19 == HDR_TYPE_NONE ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
        nTextureVar: ENVMAP_4.m_Index,
        nFrameVar: ENVMAPFRAME_1.m_Index);
      if ( bHasEnvmapMask )
        CBaseShader::BindTexture(
          this,
          sampler1: SHADER_SAMPLER5,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: ENVMAPMASK_1.m_Index,
          nFrameVar: ENVMAPMASKFRAME_1.m_Index);
    }
    pShaderAPI->BindStandardTexture(
      this: pShaderAPI,
      a2: SHADER_SAMPLER6,
      a3: TEXTURE_BINDFLAGS_NONE,
      a4: TEXTURE_NORMALIZATION_CUBEMAP_SIGNED);
    v20 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v20 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v21 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v21 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    CBaseVSShader::SetEnvMapTintPixelShaderDynamicState(
      this,
      pixelReg: 0,
      tintVar: ENVMAPTINT_2.m_Index,
      alphaVar: -1,
      bConvertFromGammaToLinear: false);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 2, constantVar: ENVMAPCONTRAST_1.m_Index);
    CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 3, constantVar: ENVMAPSATURATION_1.m_Index);
    v22 = params[FRESNELREFLECTION_2.m_Index];
    v23 = pShaderAPI->__vftable;
    v33 = 0.0;
    memset(&_vshIndex, 0, sizeof(_vshIndex));
    x_low = SLODWORD(v22->m_VecVal.x);
    SetPixelShaderConstant = v23->SetPixelShaderConstant;
    _vshIndex.m_nENVMAP_MASK = x_low;
    *(float *)&_vshIndex.m_nHARDWAREFOGBLEND = 1.0 - *(float *)&x_low;
    *(float *)&_vshIndex.m_nDOPIXELFOG = 1.0 - *(float *)&x_low;
    v33 = 1.0 - *(float *)&x_low;
    SetPixelShaderConstant(this: pShaderAPI, a2: 4, a3: &v33, a4: 1, a5: false);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: &eyePos[1]);
    pShaderAPI->SetPixelShaderConstant(this: pShaderAPI, a2: 5, a3: &eyePos[1], a4: 1, a5: false);
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    v26 = params[UNLITFACTOR.m_Index];
    v27 = pShaderAPI->SetPixelShaderConstant;
    overbright[0] = 2.0;
    overbright[1] = v26->m_VecVal.x;
    overbright[3] = 1.0 - v26->m_VecVal.x;
    overbright[2] = overbright[3];
    v27(this: pShaderAPI, a2: 6, a3: overbright, a4: 1, a5: false);
  }
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002F290
// Name: public: virtual int ShatteredGlass::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ShatteredGlass::CShader::GetParamCount(ShatteredGlass::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_106.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002F2A0
// Name: public: virtual struct ShaderParamInfo_t const __near & ShatteredGlass::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *__thiscall ShatteredGlass::CShader::GetParamInfo(
        ShatteredGlass::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_106.m_Memory.m_pMemory[param - ParamCount];
  else
    return (ShatteredGlass::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1002F2D0
// Name: public: ShatteredGlass::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *__thiscall ShatteredGlass::CShaderParam::CShaderParam(
        ShatteredGlass::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  ShatteredGlass::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  ShatteredGlass::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_106.m_Size + 13;
  m_Size = s_ShaderParams_106.m_Size;
  v8 = s_ShaderParams_106.m_Size;
  if ( s_ShaderParams_106.m_Size + 1 > s_ShaderParams_106.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_106,
      num: s_ShaderParams_106.m_Size - s_ShaderParams_106.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_106.m_Size;
  }
  m_pMemory = s_ShaderParams_106.m_Memory.m_pMemory;
  s_ShaderParams_106.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_106.m_pElements = s_ShaderParams_106.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_106.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_106.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_106.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100663B0
// Name: ShatteredGlass::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int ShatteredGlass::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: ShatteredGlass::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100663C0
// Name: ShatteredGlass::_dynamic_initializer_for__BASETEXTURE__
// Source: json
//------------------------------------------------------------------------------
void ShatteredGlass::_dynamic_initializer_for__BASETEXTURE__()
{
  s_pShaderParamOverrides_3[6] = &BASETEXTURE;
}

//------------------------------------------------------------------------------
// Address: 0x100663D0
// Name: ShatteredGlass::_dynamic_initializer_for__DETAIL__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__DETAIL__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &DETAIL_0,
           pName: "$DETAIL",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "Glass/glasswindowbreak070b",
           pHelp: "detail",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100663F0
// Name: ShatteredGlass::_dynamic_initializer_for__DETAILSCALE__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__DETAILSCALE__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &DETAILSCALE_0,
           pName: "$DETAILSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "detail scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066410
// Name: ShatteredGlass::_dynamic_initializer_for__ENVMAP__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__ENVMAP__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &ENVMAP_4,
           pName: "$ENVMAP",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/shadertest_env",
           pHelp: "envmap",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066430
// Name: ShatteredGlass::_dynamic_initializer_for__ENVMAPFRAME__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__ENVMAPFRAME__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &ENVMAPFRAME_1,
           pName: "$ENVMAPFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066450
// Name: ShatteredGlass::_dynamic_initializer_for__ENVMAPMASK__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__ENVMAPMASK__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &ENVMAPMASK_1,
           pName: "$ENVMAPMASK",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "glass/glasswindowbreak070b_mask",
           pHelp: "envmap mask",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066470
// Name: ShatteredGlass::_dynamic_initializer_for__ENVMAPMASKFRAME__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__ENVMAPMASKFRAME__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &ENVMAPMASKFRAME_1,
           pName: "$ENVMAPMASKFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066490
// Name: ShatteredGlass::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__ENVMAPMASKTRANSFORM__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &ENVMAPMASKTRANSFORM_0,
           pName: "$ENVMAPMASKTRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$envmapmask texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100664B0
// Name: ShatteredGlass::_dynamic_initializer_for__ENVMAPTINT__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__ENVMAPTINT__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &ENVMAPTINT_2,
           pName: "$ENVMAPTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "envmap tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100664D0
// Name: ShatteredGlass::_dynamic_initializer_for__ENVMAPCONTRAST__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__ENVMAPCONTRAST__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &ENVMAPCONTRAST_1,
           pName: "$ENVMAPCONTRAST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "contrast 0 == normal 1 == color*color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100664F0
// Name: ShatteredGlass::_dynamic_initializer_for__ENVMAPSATURATION__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__ENVMAPSATURATION__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &ENVMAPSATURATION_1,
           pName: "$ENVMAPSATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "saturation 0 == greyscale 1 == normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066510
// Name: ShatteredGlass::_dynamic_initializer_for__FRESNELREFLECTION__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__FRESNELREFLECTION__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &FRESNELREFLECTION_2,
           pName: "$FRESNELREFLECTION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "1.0 == mirror, 0.0 == water",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066530
// Name: ShatteredGlass::_dynamic_initializer_for__UNLITFACTOR__
// Source: json
//------------------------------------------------------------------------------
ShatteredGlass::CShaderParam *ShatteredGlass::_dynamic_initializer_for__UNLITFACTOR__()
{
  return ShatteredGlass::CShaderParam::CShaderParam(
           this: &UNLITFACTOR,
           pName: "$UNLITFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.7",
           pHelp: "0.0 == multiply by lightmap, 1.0 == multiply by 1",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066550
// Name: ShatteredGlass::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *ShatteredGlass::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_106);
  s_ShaderInstance_106.__vftable = (ShatteredGlass::CShader_vtbl *)&ShatteredGlass::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B720
// Name: ShatteredGlass::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShatteredGlass::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_106);
}

//------------------------------------------------------------------------------
// Address: 0x10066570
// Name: _dynamic_initializer_for__s_ConstructMe_showz_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_showz_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &showz_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10066590
// Name: _dynamic_initializer_for__s_ConstructMe_showz_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_showz_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &showz_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100665B0
// Name: _dynamic_initializer_for__s_ConstructMe_showz_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_showz_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &showz_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100665D0
// Name: _dynamic_initializer_for__r_showz_power__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_showz_power__()
{
  ConVar::ConVar(this: &r_showz_power, pName: "r_showz_power", pDefaultValue: "1.0f", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_showz_power__);
}

//------------------------------------------------------------------------------
// Address: 0x1006B730
// Name: _dynamic_atexit_destructor_for__r_showz_power__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_showz_power__()
{
  ConVar::~ConVar(this: &r_showz_power);
}
