// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/monitorscreen_dx9.cpp
// Functions: 28
// ============================================================

#include "materialsystem\stdshaders\monitorscreen_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x1001E290
// Name: public: virtual char const __near * MonitorScreen::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MonitorScreen::CShader::GetFallbackShader(MonitorScreen::CShader *this, IMaterialVar **params)
{
  return "MonitorScreen_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x1001E2A0
// Name: public: virtual char const __near * MonitorScreen::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MonitorScreen::CShader::GetName(MonitorScreen::CShader *this)
{
  return s_Name_58;
}

//------------------------------------------------------------------------------
// Address: 0x1001E2B0
// Name: public: virtual int MonitorScreen::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MonitorScreen::CShader::GetFlags(MonitorScreen::CShader *this)
{
  return s_nFlags_81;
}

//------------------------------------------------------------------------------
// Address: 0x1001E2C0
// Name: public: virtual int MonitorScreen::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MonitorScreen::CShader::GetParamCount(MonitorScreen::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_58.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001E2D0
// Name: public: virtual void MonitorScreen_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MonitorScreen_DX9::CShader::OnInitShaderParams(
        MonitorScreen_DX9::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  if ( !params[CONTRAST.m_Index]->IsDefined(this: params[CONTRAST.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[CONTRAST.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[SATURATION.m_Index]->IsDefined(this: params[SATURATION.m_Index]) )
    ((void (__stdcall *)(int))params[SATURATION.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[TINT.m_Index]->IsDefined(this: params[TINT.m_Index]) )
    ((void (__thiscall *)(IMaterialVar *, int, int, int))params[TINT.m_Index]->SetVecValue_2)(
      a1: params[TINT.m_Index],
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216);
  if ( (params[1]->m_intVal & 0x800) == 0 )
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFFFF7FF);
}

//------------------------------------------------------------------------------
// Address: 0x1001E3B0
// Name: public: virtual char const __near * MonitorScreen_DX9::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MonitorScreen_DX9::CShader::GetFallbackShader(
        MonitorScreen_DX9::CShader *this,
        IMaterialVar **params)
{
  if ( params == nullptr || params[6]->IsDefined(this: params[6]) )
    return nullptr;
  else
    return "LightmappedGeneric";
}

//------------------------------------------------------------------------------
// Address: 0x1001E3E0
// Name: public: virtual char const __near * MonitorScreen_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MonitorScreen_DX9::CShader::GetName(MonitorScreen_DX9::CShader *this)
{
  return s_Name_59;
}

//------------------------------------------------------------------------------
// Address: 0x1001E3F0
// Name: public: virtual int MonitorScreen_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MonitorScreen_DX9::CShader::GetFlags(MonitorScreen_DX9::CShader *this)
{
  return s_nFlags_82;
}

//------------------------------------------------------------------------------
// Address: 0x1001E400
// Name: public: virtual void MonitorScreen_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MonitorScreen_DX9::CShader::OnInitShaderInstance(
        MonitorScreen_DX9::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
  if ( params[TEXTURE2_1.m_Index]->IsDefined(this: params[TEXTURE2_1.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: TEXTURE2_1.m_Index, nAdditionalCreationFlags: 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x1001E460
// Name: public: virtual void MonitorScreen_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MonitorScreen_DX9::CShader::OnDrawElements(
        MonitorScreen_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v7; // bl
  int v8; // eax
  unsigned int v9; // ecx
  BOOL v10; // ebx
  int v11; // eax
  int v12; // ebx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v14; // ebx
  int v15; // eax
  bool v16; // al
  BOOL v17; // ebx
  BOOL v18; // eax
  MaterialFogMode_t v19; // eax
  const char *v20; // [esp-4h] [ebp-38h]
  float vEyePos_SpecExponent[4]; // [esp+Ch] [ebp-28h] BYREF
  BOOL v22; // [esp+24h] [ebp-10h]
  BOOL bFullyOpaque; // [esp+2Fh] [ebp-5h]
  bool bHasTexture2; // [esp+33h] [ebp-1h]

  v7 = (*((_BYTE *)params[TEXTURE2_1.m_Index] + 28) & 0xF) == 3;
  bHasTexture2 = v7;
  v8 = CBaseVSShader::EvaluateBlendRequirements(this, textureVar: 6, isBaseTexture: true, detailTextureVar: -1);
  if ( v8 == 3 || v8 == 1 || (v9 = (unsigned int)(*params)->m_intVal >> 8, LOBYTE(bFullyOpaque) = 1, (v9 & 1) != 0) )
    LOBYTE(bFullyOpaque) = 0;
  if ( pShaderShadow != nullptr )
  {
    pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: true);
    if ( v7 )
    {
      pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    }
    pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    if ( CBaseShader::IsAlphaModulating(this)
      || CBaseShader::TextureIsTranslucent(this, textureVar: 6, isBaseTexture: true)
      || CBaseShader::TextureIsTranslucent(this, textureVar: TEXTURE2_1.m_Index, isBaseTexture: true) )
    {
      if ( ((*params)->m_intVal & 0x80) != 0 )
        CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE);
      else
        CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_SRC_ALPHA, dst: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
    }
    else if ( ((*params)->m_intVal & 0x80) != 0 )
    {
      CBaseShader::EnableAlphaBlending(this, src: SHADER_BLEND_ONE, dst: SHADER_BLEND_ONE);
    }
    else
    {
      CBaseShader::DisableAlphaBlending(this);
    }
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: 1027u, a3: 1, a4: nullptr, a5: 0);
    v10 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
    v11 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
    pShaderShadow->SetVertexShader(this: pShaderShadow, a2: "unlittwotexture_vs20", a3: 16 * (v10 + 2 * (v11 < 92)));
    v12 = 0;
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      LOBYTE(v12) = bHasTexture2;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "TEXTURE2", v12, "(bHasTexture2)?(1):(0)");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "monitorscreen_ps20", a3: 2 * v12);
    }
    else
    {
      LOBYTE(v12) = bHasTexture2;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "TEXTURE2", v12, "(bHasTexture2)?(1):(0)");
      pShaderShadow->SetPixelShader(this: pShaderShadow, a2: "monitorscreen_ps20b", a3: 4 * v12);
    }
    CBaseShader::DefaultFog(this);
    pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: bFullyOpaque);
    CBaseShader::PI_BeginCommandBuffer(this);
    CBaseShader::PI_SetModulationVertexShaderDynamicState(this);
    CBaseShader::PI_EndCommandBuffer(this);
    v7 = bHasTexture2;
  }
  if ( pShaderAPI == nullptr )
    goto LABEL_45;
  CBaseShader::BindTexture(
    this,
    sampler1: SHADER_SAMPLER0,
    nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
    nTextureVar: 6,
    nFrameVar: 7);
  if ( v7 )
  {
    CBaseShader::BindTexture(
      this,
      sampler1: SHADER_SAMPLER1,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      nTextureVar: TEXTURE2_1.m_Index,
      nFrameVar: FRAME2_0.m_Index);
    CBaseVSShader::SetVertexShaderTextureTransform(this, vertexReg: 50, transformVar: TEXTURE2TRANSFORM.m_Index);
  }
  CBaseVSShader::SetVertexShaderTextureTransform(this, vertexReg: 48, transformVar: 8);
  CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 1, constantVar: CONTRAST.m_Index);
  CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 2, constantVar: SATURATION.m_Index);
  CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 3, constantVar: TINT.m_Index);
  pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
  pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
  SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
  vEyePos_SpecExponent[3] = 0.0;
  SetPixelShaderConstant(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
  v14 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  v22 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
  if ( g_shaderConfigDumpEnable )
  {
    v15 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
            a1: pShaderAPI,
            a2: "pShaderAPI->GetCurrentNumBones() > 0");
    printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v15 > 0, v20);
    if ( g_shaderConfigDumpEnable )
    {
      printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
    }
  }
  pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: vertexCompression + 2 * (v14 + 2 * v22));
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
  {
    v19 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
    pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v19 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
LABEL_45:
    CBaseShader::Draw(this, bMakeActualDrawCall: true);
    return;
  }
  v22 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  v16 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
  v17 = v16;
  if ( g_shaderConfigDumpEnable )
  {
    v18 = bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha(this: pShaderAPI);
    printf(
      format: "\n   PS dyn  var %s = %d (%s)",
      "WRITE_DEPTH_TO_DESTALPHA",
      v18,
      "bFullyOpaque && pShaderAPI->ShouldWriteDepthToDestAlpha()");
  }
  pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v22 + 2 * v17);
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001E8C0
// Name: public: virtual int MonitorScreen_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall MonitorScreen_DX9::CShader::GetParamCount(MonitorScreen_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_59.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001E8D0
// Name: public: virtual struct ShaderParamInfo_t const __near & MonitorScreen::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
MonitorScreen::CShaderParam *__thiscall MonitorScreen::CShader::GetParamInfo(MonitorScreen::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_58.m_Memory.m_pMemory[param - ParamCount];
  else
    return (MonitorScreen::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001E900
// Name: public: virtual struct ShaderParamInfo_t const __near & MonitorScreen_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
MonitorScreen_DX9::CShaderParam *__thiscall MonitorScreen_DX9::CShader::GetParamInfo(
        MonitorScreen_DX9::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_59.m_Memory.m_pMemory[param - ParamCount];
  else
    return (MonitorScreen_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x1001E930
// Name: public: MonitorScreen_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
MonitorScreen_DX9::CShaderParam *__thiscall MonitorScreen_DX9::CShaderParam::CShaderParam(
        MonitorScreen_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  MonitorScreen_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  MonitorScreen_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_59.m_Size + 13;
  m_Size = s_ShaderParams_59.m_Size;
  v8 = s_ShaderParams_59.m_Size;
  if ( s_ShaderParams_59.m_Size + 1 > s_ShaderParams_59.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_59,
      num: s_ShaderParams_59.m_Size - s_ShaderParams_59.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_59.m_Size;
  }
  m_pMemory = s_ShaderParams_59.m_Memory.m_pMemory;
  s_ShaderParams_59.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_59.m_pElements = s_ShaderParams_59.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_59.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_59.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_59.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063310
// Name: MonitorScreen::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int MonitorScreen::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: MonitorScreen::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063320
// Name: MonitorScreen::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *MonitorScreen::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_58);
  s_ShaderInstance_58.__vftable = (MonitorScreen::CShader_vtbl *)&MonitorScreen::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063340
// Name: MonitorScreen_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int MonitorScreen_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: MonitorScreen_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10063350
// Name: MonitorScreen_DX9::_dynamic_initializer_for__CONTRAST__
// Source: json
//------------------------------------------------------------------------------
MonitorScreen_DX9::CShaderParam *MonitorScreen_DX9::_dynamic_initializer_for__CONTRAST__()
{
  return MonitorScreen_DX9::CShaderParam::CShaderParam(
           this: &CONTRAST,
           pName: "$CONTRAST",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "contrast 0 == normal 1 == color*color",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063370
// Name: MonitorScreen_DX9::_dynamic_initializer_for__SATURATION__
// Source: json
//------------------------------------------------------------------------------
MonitorScreen_DX9::CShaderParam *MonitorScreen_DX9::_dynamic_initializer_for__SATURATION__()
{
  return MonitorScreen_DX9::CShaderParam::CShaderParam(
           this: &SATURATION,
           pName: "$SATURATION",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "saturation 0 == greyscale 1 == normal",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063390
// Name: MonitorScreen_DX9::_dynamic_initializer_for__TINT__
// Source: json
//------------------------------------------------------------------------------
MonitorScreen_DX9::CShaderParam *MonitorScreen_DX9::_dynamic_initializer_for__TINT__()
{
  return MonitorScreen_DX9::CShaderParam::CShaderParam(
           this: &TINT,
           pName: "$TINT",
           type: SHADER_PARAM_TYPE_COLOR,
           pDefaultParam: "[1 1 1]",
           pHelp: "monitor tint",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100633B0
// Name: MonitorScreen_DX9::_dynamic_initializer_for__TEXTURE2__
// Source: json
//------------------------------------------------------------------------------
MonitorScreen_DX9::CShaderParam *MonitorScreen_DX9::_dynamic_initializer_for__TEXTURE2__()
{
  return MonitorScreen_DX9::CShaderParam::CShaderParam(
           this: &TEXTURE2_1,
           pName: "$TEXTURE2",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: "shadertest/lightmappedtexture",
           pHelp: "second texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100633D0
// Name: MonitorScreen_DX9::_dynamic_initializer_for__FRAME2__
// Source: json
//------------------------------------------------------------------------------
MonitorScreen_DX9::CShaderParam *MonitorScreen_DX9::_dynamic_initializer_for__FRAME2__()
{
  return MonitorScreen_DX9::CShaderParam::CShaderParam(
           this: &FRAME2_0,
           pName: "$FRAME2",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "frame number for $texture2",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100633F0
// Name: MonitorScreen_DX9::_dynamic_initializer_for__TEXTURE2TRANSFORM__
// Source: json
//------------------------------------------------------------------------------
MonitorScreen_DX9::CShaderParam *MonitorScreen_DX9::_dynamic_initializer_for__TEXTURE2TRANSFORM__()
{
  return MonitorScreen_DX9::CShaderParam::CShaderParam(
           this: &TEXTURE2TRANSFORM,
           pName: "$TEXTURE2TRANSFORM",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "center .5 .5 scale 1 1 rotate 0 translate 0 0",
           pHelp: "$texture2 texcoord transform",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10063410
// Name: MonitorScreen_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *MonitorScreen_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_59);
  s_ShaderInstance_59.__vftable = (MonitorScreen_DX9::CShader_vtbl *)&MonitorScreen_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B3A0
// Name: MonitorScreen::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MonitorScreen::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_58);
}

//------------------------------------------------------------------------------
// Address: 0x1006B3B0
// Name: MonitorScreen_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MonitorScreen_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_59);
}

//------------------------------------------------------------------------------
// Address: 0x10063430
// Name: _dynamic_initializer_for__s_ConstructMe_morphaccumulate_vs30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_morphaccumulate_vs30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &morphaccumulate_vs30_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10063450
// Name: _dynamic_initializer_for__s_ConstructMe_morphaccumulate_ps30__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_morphaccumulate_ps30__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &morphaccumulate_ps30_combos);
}
