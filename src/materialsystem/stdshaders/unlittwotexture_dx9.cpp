// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/unlittwotexture_dx9.cpp
// Functions: 28
// ============================================================

#include "materialsystem\stdshaders\unlittwotexture_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10037AE0
// Name: public: virtual char const __near * UnlitTwoTexture::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall UnlitTwoTexture::CShader::GetFallbackShader(
        UnlitTwoTexture::CShader *this,
        IMaterialVar **params)
{
  return "UnlitTwoTexture_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10037AF0
// Name: public: virtual char const __near * UnlitTwoTexture::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall UnlitTwoTexture::CShader::GetName(UnlitTwoTexture::CShader *this)
{
  return s_Name_120;
}

//------------------------------------------------------------------------------
// Address: 0x10037B00
// Name: public: virtual int UnlitTwoTexture::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall UnlitTwoTexture::CShader::GetFlags(UnlitTwoTexture::CShader *this)
{
  return s_nFlags_122;
}

//------------------------------------------------------------------------------
// Address: 0x10037B10
// Name: public: virtual int UnlitTwoTexture::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall UnlitTwoTexture::CShader::GetParamCount(UnlitTwoTexture::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_120.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037B20
// Name: public: virtual bool UnlitTwoTexture_DX9::CShader::NeedsPowerOfTwoFrameBufferTexture(class IMaterialVar __near * __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall UnlitTwoTexture_DX9::CShader::NeedsPowerOfTwoFrameBufferTexture(
        UnlitTwoTexture_DX9::CShader *this,
        IMaterialVar **params,
        bool bCheckSpecificToThisFrame)
{
  float x; // xmm0_4

  return params[CLOAKPASSENABLED_1.m_Index]->m_intVal != 0
      && (!bCheckSpecificToThisFrame || (x = params[CLOAKFACTOR_2.m_Index]->m_VecVal.x) > 0.0 && x < 1.0)
      || (params[2]->m_intVal & 0x4000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10037B80
// Name: public: virtual bool UnlitTwoTexture_DX9::CShader::IsTranslucent(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall UnlitTwoTexture_DX9::CShader::IsTranslucent(UnlitTwoTexture_DX9::CShader *this, IMaterialVar **params)
{
  float x; // xmm0_4

  return params[CLOAKPASSENABLED_1.m_Index]->m_intVal != 0
      && (x = params[CLOAKFACTOR_2.m_Index]->m_VecVal.x) > 0.0
      && x < 1.0
      || ((*params)->m_intVal & 0x200000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10037BD0
// Name: public: virtual void UnlitTwoTexture_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall UnlitTwoTexture_DX9::CShader::OnInitShaderParams(
        UnlitTwoTexture_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  CloakBlendedPassVars_t info; // [esp+8h] [ebp-18h] BYREF

  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  if ( params[CLOAKPASSENABLED_1.m_Index]->IsDefined(this: params[CLOAKPASSENABLED_1.m_Index]) )
  {
    if ( params[CLOAKPASSENABLED_1.m_Index]->m_intVal != 0 )
    {
      memset(&info.m_nBumpmap, 255, 12);
      info.m_nCloakFactor = CLOAKFACTOR_2.m_Index;
      info.m_nCloakColorTint = CLOAKCOLORTINT_1.m_Index;
      info.m_nRefractAmount = REFRACTAMOUNT_5.m_Index;
      InitParamsCloakBlendedPass(pShader: this, params, pMaterialName, &info);
    }
  }
  else
  {
    params[CLOAKPASSENABLED_1.m_Index]->SetIntValue(this: params[CLOAKPASSENABLED_1.m_Index], a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037C80
// Name: public: virtual char const __near * UnlitTwoTexture_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall UnlitTwoTexture_DX9::CShader::GetName(UnlitTwoTexture_DX9::CShader *this)
{
  return s_Name_121;
}

//------------------------------------------------------------------------------
// Address: 0x10037C90
// Name: public: virtual int UnlitTwoTexture_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall UnlitTwoTexture_DX9::CShader::GetFlags(UnlitTwoTexture_DX9::CShader *this)
{
  return s_nFlags_123;
}

//------------------------------------------------------------------------------
// Address: 0x10037CA0
// Name: public: virtual void UnlitTwoTexture_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall UnlitTwoTexture_DX9::CShader::OnInitShaderInstance(
        UnlitTwoTexture_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  CloakBlendedPassVars_t info; // [esp+8h] [ebp-18h] BYREF

  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
  if ( params[TEXTURE2_3.m_Index]->IsDefined(this: params[TEXTURE2_3.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: TEXTURE2_3.m_Index, nAdditionalCreationFlags: 0x80000);
  if ( params[CLOAKPASSENABLED_1.m_Index]->m_intVal != 0 )
  {
    info.m_nCloakFactor = CLOAKFACTOR_2.m_Index;
    memset(&info.m_nBumpmap, 255, 12);
    info.m_nCloakColorTint = CLOAKCOLORTINT_1.m_Index;
    info.m_nRefractAmount = REFRACTAMOUNT_5.m_Index;
    InitCloakBlendedPass(pShader: this, params, &info);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037D50
// Name: public: virtual void UnlitTwoTexture_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall UnlitTwoTexture_DX9::CShader::OnDrawElements(
        UnlitTwoTexture_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  float x; // xmm0_4
  int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v17; // eax
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v19; // cc
  MaterialFogMode_t (__thiscall *GetSceneFogMode)(IShaderDynamicAPI *); // edx
  bool v21; // al
  BOOL v22; // eax
  int v23; // eax
  ShaderBlendFactor_t v24; // [esp-4h] [ebp-44h]
  CloakBlendedPassVars_t info; // [esp+Ch] [ebp-34h] BYREF
  float vEyeDir[4]; // [esp+24h] [ebp-1Ch] BYREF
  unlittwotexture_ps20b_Dynamic_Index _pshIndex; // [esp+34h] [ebp-Ch]
  BOOL bFullyOpaque; // [esp+3Ch] [ebp-4h]
  unsigned __int8 bTranslucent_3; // [esp+4Fh] [ebp+Fh]
  bool bTranslucent_3a; // [esp+4Fh] [ebp+Fh]
  int flFarZ; // [esp+50h] [ebp+10h]
  float flFarZb; // [esp+50h] [ebp+10h]
  BOOL flFarZa; // [esp+50h] [ebp+10h]

  if ( params[CLOAKPASSENABLED_1.m_Index]->m_intVal != 0 )
  {
    if ( pShaderShadow != nullptr )
      goto LABEL_13;
    memset(&info.m_nBumpmap, 255, 12);
    info.m_nCloakColorTint = CLOAKCOLORTINT_1.m_Index;
    info.m_nCloakFactor = CLOAKFACTOR_2.m_Index;
    info.m_nRefractAmount = REFRACTAMOUNT_5.m_Index;
    if ( CloakBlendedPassIsFullyOpaque(params, &info) )
    {
LABEL_4:
      CBaseShader::Draw(this, bMakeActualDrawCall: false);
      goto LABEL_5;
    }
  }
  else if ( pShaderShadow != nullptr )
  {
    goto LABEL_13;
  }
  if ( pShaderAPI != nullptr && pShaderAPI->InFlashlightMode(this: pShaderAPI) )
    goto LABEL_4;
LABEL_13:
  v10 = CBaseVSShader::EvaluateBlendRequirements(this, textureVar: 6, isBaseTexture: true, detailTextureVar: -1);
  if ( v10 == 3 || v10 == 1 || (v11 = (unsigned int)(*params)->m_intVal >> 8, LOBYTE(bFullyOpaque) = 1, (v11 & 1) != 0) )
    LOBYTE(bFullyOpaque) = 0;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    CBaseShader::s_pShaderShadow->EnableSRGBWrite(this: CBaseShader::s_pShaderShadow, a2: true);
    if ( CBaseShader::IsAlphaModulating(this)
      || ((*params)->m_intVal & 0x200000) != 0
      || CBaseShader::TextureIsTranslucent(this, textureVar: 6, isBaseTexture: true)
      || CBaseShader::TextureIsTranslucent(this, textureVar: TEXTURE2_3.m_Index, isBaseTexture: true) )
    {
      if ( ((*params)->m_intVal & 0x80) != 0 )
        v24 = SHADER_BLEND_ONE;
      else
        v24 = SHADER_BLEND_ONE_MINUS_SRC_ALPHA;
      CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: v24);
    }
    else if ( ((*params)->m_intVal & 0x80) != 0 )
    {
      CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
    }
    else
    {
      CBaseShader::DisableAlphaBlending(this);
    }
    v12 = 1027;
    if ( ((*params)->m_intVal & 0x10) != 0 )
      v12 = 1031;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v12, a3: 1, a4: nullptr, a5: 0);
    if ( CBaseShader::IsAlphaModulating(this)
      || ((*params)->m_intVal & 0x200000) != 0
      || CBaseShader::TextureIsTranslucent(this, textureVar: 6, isBaseTexture: true)
      || (bTranslucent_3 = 0,
          CBaseShader::TextureIsTranslucent(this, textureVar: TEXTURE2_3.m_Index, isBaseTexture: true)) )
    {
      bTranslucent_3 = 1;
    }
    flFarZ = ((params[2]->m_intVal & 0x100000) != 0) + 2 * ((params[2]->m_intVal & 0x200000) != 0);
    _pshIndex.m_nPIXELFOGTYPE = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v13 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(
      this: pShaderShadow,
      a2: "unlittwotexture_vs20",
      a3: 16 * (_pshIndex.m_nPIXELFOGTYPE + 2 * (v13 < 92)));
    v14 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    v15 = 0;
    if ( v14 < 92 )
    {
      LOBYTE(v15) = bTranslucent_3 != 0;
      _pshIndex.m_nPIXELFOGTYPE = v15;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "TRANSLUCENT", bTranslucent_3, "bTranslucent");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "LIGHTING_PREVIEW", flFarZ, "nLightingPreviewMode");
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "unlittwotexture_ps20",
        a3: 2 * (_pshIndex.m_nPIXELFOGTYPE + 2 * flFarZ));
    }
    else
    {
      LOBYTE(v15) = bTranslucent_3 != 0;
      _pshIndex.m_nPIXELFOGTYPE = v15;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "TRANSLUCENT", bTranslucent_3, "bTranslucent");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "LIGHTING_PREVIEW", flFarZ, "nLightingPreviewMode");
      }
      pShaderShadow->SetPixelShader(
        this: pShaderShadow,
        a2: "unlittwotexture_ps20b",
        a3: 4 * (_pshIndex.m_nPIXELFOGTYPE + 2 * flFarZ));
    }
    CBaseShader::DefaultFog(this);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: bFullyOpaque);
    CBaseShader::PI_BeginCommandBuffer(this);
    CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace(this, nRegister: 1);
    CBaseShader::PI_EndCommandBuffer(this);
  }
  if ( pShaderAPI == nullptr )
    goto LABEL_67;
  CBaseShader::BindTexture(
    this,
    sampler1: SHADER_SAMPLER0,
    nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
    nTextureVar: 6,
    nFrameVar: 7);
  CBaseShader::BindTexture(
    this,
    sampler1: SHADER_SAMPLER1,
    nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
    nTextureVar: TEXTURE2_3.m_Index,
    nFrameVar: FRAME2_1.m_Index);
  CBaseVSShader::SetVertexShaderTextureTransform(this, vertexReg: 48, transformVar: 8);
  CBaseVSShader::SetVertexShaderTextureTransform(this, vertexReg: 50, transformVar: TEXTURE2TRANSFORM_0.m_Index);
  pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
  pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: (float *)&info.m_nRefractAmount);
  SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
  info.m_nBumpTransform = 0;
  SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: (const float *)&info.m_nRefractAmount, a4: 1, a5: false);
  _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA = pShaderAPI->GetCurrentNumBones(this: pShaderAPI);
  v17 = pShaderAPI->GetIntRenderingParameter(this: pShaderAPI, a2: 0);
  bTranslucent_3a = v17 == 3;
  if ( v17 == 3 )
  {
    pShaderAPI->GetWorldSpaceCameraDirection(this: pShaderAPI, a2: vEyeDir);
    flFarZb = pShaderAPI->GetFarZ(this: pShaderAPI);
    SetVertexShaderConstant = pShaderAPI->SetVertexShaderConstant;
    vEyeDir[0] = vEyeDir[0] * (float)(1.0 / flFarZb);
    vEyeDir[1] = vEyeDir[1] * (float)(1.0 / flFarZb);
    vEyeDir[2] = vEyeDir[2] * (float)(1.0 / flFarZb);
    SetVertexShaderConstant(this: pShaderAPI, a2: 52, a3: vEyeDir, a4: 1, a5: false);
  }
  LODWORD(vEyeDir[1]) = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  flFarZa = _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA > 0;
  if ( g_shaderConfigDumpEnable )
  {
    printf(
      format: "\n   VS dyn  var %s = %d (%s)",
      "SKINNING",
      _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA > 0,
      "numBones > 0");
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
  }
  LODWORD(vEyeDir[3]) = bTranslucent_3a;
  if ( g_shaderConfigDumpEnable )
    printf(format: "\n   VS dyn  var %s = %d (%s)", "WORLD_NORMAL", bTranslucent_3a, "bWorldNormal");
  pShaderAPI->SetVertexShaderIndex(
    this: pShaderAPI,
    a2: vertexCompression + 2 * (LODWORD(vEyeDir[1]) + 2 * (flFarZa + 2 * LODWORD(vEyeDir[3]))));
  v19 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  GetSceneFogMode = pShaderAPI->GetSceneFogMode;
  if ( v19 )
  {
    v23 = GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v23 == 2);
LABEL_67:
    CBaseShader::Draw(this, bMakeActualDrawCall: true);
    goto LABEL_5;
  }
  _pshIndex.m_nPIXELFOGTYPE = GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  v21 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
  _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA = v21;
  if ( g_shaderConfigDumpEnable )
  {
    v22 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    printf(
      format: "\n   PS dyn  var %s = %d (%s)",
      "WRITE_DEPTH_TO_DESTALPHA",
      v22,
      "bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
  }
  pShaderAPI->SetPixelShaderIndex(
    this: pShaderAPI,
    a2: _pshIndex.m_nPIXELFOGTYPE + 2 * _pshIndex.m_nWRITE_DEPTH_TO_DESTALPHA);
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
LABEL_5:
  if ( params[CLOAKPASSENABLED_1.m_Index]->m_intVal != 0 )
  {
    if ( pShaderShadow != nullptr || (x = params[CLOAKFACTOR_2.m_Index]->m_VecVal.x) > 0.0 && x < 1.0 )
    {
      info.m_nCloakFactor = CLOAKFACTOR_2.m_Index;
      memset(&info.m_nBumpmap, 255, 12);
      info.m_nCloakColorTint = CLOAKCOLORTINT_1.m_Index;
      info.m_nRefractAmount = REFRACTAMOUNT_5.m_Index;
      DrawCloakBlendedPass(pShader: this, params, pShaderAPI, pShaderShadow, &info, vertexCompression);
    }
    else
    {
      CBaseShader::Draw(this, bMakeActualDrawCall: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100383E0
// Name: public: virtual int UnlitTwoTexture_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall UnlitTwoTexture_DX9::CShader::GetParamCount(UnlitTwoTexture_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_121.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100383F0
// Name: public: virtual struct ShaderParamInfo_t const __near & UnlitTwoTexture::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
UnlitTwoTexture::CShaderParam *__thiscall UnlitTwoTexture::CShader::GetParamInfo(
        UnlitTwoTexture::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_120.m_Memory.m_pMemory[param - ParamCount];
  else
    return (UnlitTwoTexture::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10038420
// Name: public: virtual struct ShaderParamInfo_t const __near & UnlitTwoTexture_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *__thiscall UnlitTwoTexture_DX9::CShader::GetParamInfo(
        UnlitTwoTexture_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_121.m_Memory.m_pMemory[param - ParamCount];
  else
    return (UnlitTwoTexture_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10038450
// Name: public: UnlitTwoTexture_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *__thiscall UnlitTwoTexture_DX9::CShaderParam::CShaderParam(
        UnlitTwoTexture_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  UnlitTwoTexture_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  UnlitTwoTexture_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_121.m_Size + 13;
  m_Size = s_ShaderParams_121.m_Size;
  v8 = s_ShaderParams_121.m_Size;
  if ( s_ShaderParams_121.m_Size + 1 > s_ShaderParams_121.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_121,
      num: s_ShaderParams_121.m_Size - s_ShaderParams_121.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_121.m_Size;
  }
  m_pMemory = s_ShaderParams_121.m_Memory.m_pMemory;
  s_ShaderParams_121.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_121.m_pElements = s_ShaderParams_121.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_121.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_121.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_121.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100683E0
// Name: UnlitTwoTexture::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int UnlitTwoTexture::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: UnlitTwoTexture::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100683F0
// Name: UnlitTwoTexture::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *UnlitTwoTexture::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_120);
  s_ShaderInstance_120.__vftable = (UnlitTwoTexture::CShader_vtbl *)&UnlitTwoTexture::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068410
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int UnlitTwoTexture_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: UnlitTwoTexture_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10068420
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__TEXTURE2__
// Source: json
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *UnlitTwoTexture_DX9::_dynamic_initializer_for__TEXTURE2__()
{
  return UnlitTwoTexture_DX9::CShaderParam::CShaderParam(
           this: &TEXTURE2_3,
           pName: "$TEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/BaseTexture",
           pHelp: "second texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068440
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__FRAME2__
// Source: json
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *UnlitTwoTexture_DX9::_dynamic_initializer_for__FRAME2__()
{
  return UnlitTwoTexture_DX9::CShaderParam::CShaderParam(
           this: &FRAME2_1,
           pName: "$FRAME2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $texture2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068460
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__TEXTURE2TRANSFORM__
// Source: json
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *UnlitTwoTexture_DX9::_dynamic_initializer_for__TEXTURE2TRANSFORM__()
{
  return UnlitTwoTexture_DX9::CShaderParam::CShaderParam(
           this: &TEXTURE2TRANSFORM_0,
           pName: "$TEXTURE2TRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$texture2 texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068480
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__CLOAKPASSENABLED__
// Source: json
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *UnlitTwoTexture_DX9::_dynamic_initializer_for__CLOAKPASSENABLED__()
{
  return UnlitTwoTexture_DX9::CShaderParam::CShaderParam(
           this: &CLOAKPASSENABLED_1,
           pName: "$CLOAKPASSENABLED",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "Enables cloak render in a second pass",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100684A0
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__CLOAKFACTOR__
// Source: json
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *UnlitTwoTexture_DX9::_dynamic_initializer_for__CLOAKFACTOR__()
{
  return UnlitTwoTexture_DX9::CShaderParam::CShaderParam(
           this: &CLOAKFACTOR_2,
           pName: "$CLOAKFACTOR",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100684C0
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__CLOAKCOLORTINT__
// Source: json
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *UnlitTwoTexture_DX9::_dynamic_initializer_for__CLOAKCOLORTINT__()
{
  return UnlitTwoTexture_DX9::CShaderParam::CShaderParam(
           this: &CLOAKCOLORTINT_1,
           pName: "$CLOAKCOLORTINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "Cloak color tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100684E0
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__REFRACTAMOUNT__
// Source: json
//------------------------------------------------------------------------------
UnlitTwoTexture_DX9::CShaderParam *UnlitTwoTexture_DX9::_dynamic_initializer_for__REFRACTAMOUNT__()
{
  return UnlitTwoTexture_DX9::CShaderParam::CShaderParam(
           this: &REFRACTAMOUNT_5,
           pName: "$REFRACTAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "2",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068500
// Name: UnlitTwoTexture_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *UnlitTwoTexture_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_121);
  s_ShaderInstance_121.__vftable = (UnlitTwoTexture_DX9::CShader_vtbl *)&UnlitTwoTexture_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B840
// Name: UnlitTwoTexture::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnlitTwoTexture::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_120);
}

//------------------------------------------------------------------------------
// Address: 0x1006B850
// Name: UnlitTwoTexture_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnlitTwoTexture_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_121);
}
