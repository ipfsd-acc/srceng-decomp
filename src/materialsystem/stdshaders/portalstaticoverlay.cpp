// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/portalstaticoverlay.cpp
// Functions: 20
// ============================================================

#include "materialsystem\stdshaders\portalstaticoverlay.h"

//------------------------------------------------------------------------------
// Address: 0x10027880
// Name: public: virtual void PortalStaticOverlay::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PortalStaticOverlay::CShader::OnInitShaderParams(
        PortalStaticOverlay::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
}

//------------------------------------------------------------------------------
// Address: 0x100278A0
// Name: public: virtual char const __near * PortalStaticOverlay::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall PortalStaticOverlay::CShader::GetName(PortalStaticOverlay::CShader *this)
{
  return s_Name_81;
}

//------------------------------------------------------------------------------
// Address: 0x100278B0
// Name: public: virtual int PortalStaticOverlay::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall PortalStaticOverlay::CShader::GetFlags(PortalStaticOverlay::CShader *this)
{
  return s_nFlags_98;
}

//------------------------------------------------------------------------------
// Address: 0x100278C0
// Name: public: virtual void PortalStaticOverlay::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PortalStaticOverlay::CShader::OnInitShaderInstance(
        PortalStaticOverlay::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  if ( params[STATICBLENDTEXTURE_0.m_Index]->IsDefined(this: params[STATICBLENDTEXTURE_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: STATICBLENDTEXTURE_0.m_Index, nAdditionalCreationFlags: 0x80000);
  if ( params[ALPHAMASKTEXTURE_0.m_Index]->IsDefined(this: params[ALPHAMASKTEXTURE_0.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: ALPHAMASKTEXTURE_0.m_Index, nAdditionalCreationFlags: 0);
  if ( !params[STATICAMOUNT_0.m_Index]->IsDefined(this: params[STATICAMOUNT_0.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[STATICAMOUNT_0.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[STATICBLENDTEXTURE_0.m_Index]->IsDefined(this: params[STATICBLENDTEXTURE_0.m_Index]) )
    params[STATICBLENDTEXTURE_0.m_Index]->SetIntValue(this: params[STATICBLENDTEXTURE_0.m_Index], a2: 0);
  if ( !params[STATICBLENDTEXTUREFRAME_0.m_Index]->IsDefined(this: params[STATICBLENDTEXTUREFRAME_0.m_Index]) )
    params[STATICBLENDTEXTUREFRAME_0.m_Index]->SetIntValue(this: params[STATICBLENDTEXTUREFRAME_0.m_Index], a2: 0);
  if ( !params[ALPHAMASKTEXTURE_0.m_Index]->IsDefined(this: params[ALPHAMASKTEXTURE_0.m_Index]) )
    params[ALPHAMASKTEXTURE_0.m_Index]->SetIntValue(this: params[ALPHAMASKTEXTURE_0.m_Index], a2: 0);
  if ( !params[ALPHAMASKTEXTUREFRAME_0.m_Index]->IsDefined(this: params[ALPHAMASKTEXTUREFRAME_0.m_Index]) )
    params[ALPHAMASKTEXTUREFRAME_0.m_Index]->SetIntValue(this: params[ALPHAMASKTEXTUREFRAME_0.m_Index], a2: 0);
  if ( !params[NOCOLORWRITE.m_Index]->IsDefined(this: params[NOCOLORWRITE.m_Index]) )
    params[NOCOLORWRITE.m_Index]->SetIntValue(this: params[NOCOLORWRITE.m_Index], a2: 0);
  if ( !params[GHOSTOVERLAY.m_Index]->IsDefined(this: params[GHOSTOVERLAY.m_Index]) )
    params[GHOSTOVERLAY.m_Index]->SetIntValue(this: params[GHOSTOVERLAY.m_Index], a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10027A30
// Name: public: virtual void PortalStaticOverlay::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PortalStaticOverlay::CShader::OnDrawElements(
        PortalStaticOverlay::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  bool v7; // bl
  int m_intVal; // edx
  IMaterialVar *v9; // edx
  void (__thiscall *BlendFunc)(IShaderShadow *, ShaderBlendFactor_t, ShaderBlendFactor_t); // eax
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  float v16; // ecx
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v18; // xmm1_4
  CBaseShader *v19; // edi
  void (__thiscall *v20)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v21; // edi
  int v22; // eax
  MaterialFogMode_t v23; // eax
  const char *v24; // [esp+18h] [ebp-3Ch]
  float vEyePos_SpecExponent[4]; // [esp+28h] [ebp-2Ch] BYREF
  float x; // [esp+38h] [ebp-1Ch] BYREF
  float v27; // [esp+3Ch] [ebp-18h]
  portalstaticoverlay_vs20_Static_Index _vshIndex; // [esp+40h] [ebp-14h]
  BOOL bColorWrites; // [esp+48h] [ebp-Ch]
  CBaseShader *v30; // [esp+4Ch] [ebp-8h]
  bool bIsModel; // [esp+51h] [ebp-3h]
  bool bStaticBlendTexture; // [esp+52h] [ebp-2h]
  bool bGhostOverlay; // [esp+53h] [ebp-1h]
  bool bAlphaMaskTexture_3; // [esp+5Fh] [ebp+Bh]

  v30 = this;
  v7 = (*((_BYTE *)params[STATICBLENDTEXTURE_0.m_Index] + 28) & 0xF) == 3;
  m_intVal = (*params)->m_intVal;
  bAlphaMaskTexture_3 = (*((_BYTE *)params[ALPHAMASKTEXTURE_0.m_Index] + 28) & 0xF) == 3;
  bIsModel = (m_intVal & 0x800) != 0;
  v9 = params[GHOSTOVERLAY.m_Index];
  LOBYTE(bColorWrites) = params[NOCOLORWRITE.m_Index]->m_intVal == 0;
  bGhostOverlay = v9->m_intVal != 0;
  bStaticBlendTexture = v7;
  if ( pShaderShadow != nullptr )
  {
    CBaseShader::SetInitialShadowState(this);
    CBaseShader::FogToFogColor(this: v30);
    pShaderShadow->DepthFunc(this: pShaderShadow, a2: SHADER_DEPTHFUNC_NEAREROREQUAL);
    pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: !bGhostOverlay);
    pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
    BlendFunc = pShaderShadow->BlendFunc;
    if ( bGhostOverlay )
    {
      ((void (__thiscall *)(IShaderShadow *, int))BlendFunc)(a1: pShaderShadow, a2: 1);
      pShaderShadow->DepthFunc(this: pShaderShadow, a2: SHADER_DEPTHFUNC_FARTHER);
      pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: true);
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
    }
    else
    {
      ((void (__thiscall *)(IShaderShadow *, int))BlendFunc)(a1: pShaderShadow, a2: 4);
      pShaderShadow->EnableAlphaTest(this: pShaderShadow, a2: true);
      ((void (__thiscall *)(IShaderShadow *, int, _DWORD))pShaderShadow->AlphaFunc)(a1: pShaderShadow, a2: 4, a3: 0);
    }
    pShaderShadow->EnableColorWrites(this: pShaderShadow, a2: bColorWrites);
    if ( v7 || bAlphaMaskTexture_3 )
    {
      v11 = ((int (__thiscall *)(IShaderShadow *, _DWORD, int))pShaderShadow->EnableTexture)(
              a1: pShaderShadow,
              a2: 0,
              a3: 1);
      LOBYTE(v11) = v7;
      pShaderShadow->EnableSRGBRead(this: pShaderShadow, a2: SHADER_SAMPLER0, a3: v11);
      if ( v7 && bAlphaMaskTexture_3 )
        pShaderShadow->EnableTexture(this: pShaderShadow, a2: SHADER_SAMPLER1, a3: true);
    }
    if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pHardwareConfig->GetHDRType)(
           a1: g_pHardwareConfig,
           a2: 5) != 0 )
      pShaderShadow->EnableSRGBWrite(this: pShaderShadow, a2: true);
    v12 = 3;
    if ( bGhostOverlay )
      v12 = 7;
    v13 = 0;
    if ( bIsModel )
      v13 = 4;
    else
      v12 |= 0x30u;
    pShaderShadow->VertexShaderVertexFormat(this: pShaderShadow, a2: v12, a3: 1, a4: nullptr, a5: v13);
    _vshIndex.m_nMODEL = bIsModel;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "MODEL", bIsModel, "bIsModel");
    v14 = params[GHOSTOVERLAY.m_Index]->m_intVal;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "PORTALGHOSTOVERLAY", v14, "params[GHOSTOVERLAY]->GetIntValue()");
    pShaderShadow->SetVertexShader(
      this: pShaderShadow,
      a2: "portalstaticoverlay_vs20",
      a3: 2 * (_vshIndex.m_nMODEL + 2 * v14));
    if ( bColorWrites || bAlphaMaskTexture_3 )
    {
      v15 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v16 = 0.0;
      if ( v15 < 92 )
      {
        LOBYTE(v16) = bAlphaMaskTexture_3;
        v27 = v16;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "HASALPHAMASK", bAlphaMaskTexture_3, "bAlphaMaskTexture");
        _vshIndex.m_nMODEL = bStaticBlendTexture;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "HASSTATICTEXTURE",
            bStaticBlendTexture,
            "bStaticBlendTexture");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "PORTALGHOSTOVERLAY", bGhostOverlay, "bGhostOverlay");
        pShaderShadow->SetPixelShader(
          this: pShaderShadow,
          a2: "portalstaticoverlay_ps20",
          a3: 2 * (LODWORD(v27) + 2 * (_vshIndex.m_nMODEL + 2 * bGhostOverlay)));
      }
      else
      {
        LOBYTE(v16) = bAlphaMaskTexture_3;
        v27 = v16;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "HASALPHAMASK", bAlphaMaskTexture_3, "bAlphaMaskTexture");
        _vshIndex.m_nMODEL = bStaticBlendTexture;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "HASSTATICTEXTURE",
            bStaticBlendTexture,
            "bStaticBlendTexture");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "PORTALGHOSTOVERLAY", bGhostOverlay, "bGhostOverlay");
        pShaderShadow->SetPixelShader(
          this: pShaderShadow,
          a2: "portalstaticoverlay_ps20b",
          a3: 2 * (LODWORD(v27) + 2 * (_vshIndex.m_nMODEL + 2 * bGhostOverlay)));
      }
    }
    v7 = bStaticBlendTexture;
  }
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetDefaultState(this: pShaderAPI);
    SetPixelShaderConstant = pShaderAPI->SetPixelShaderConstant;
    v18 = 1.0 - params[STATICAMOUNT_0.m_Index]->m_VecVal.x;
    x = params[STATICAMOUNT_0.m_Index]->m_VecVal.x;
    v27 = v18;
    _vshIndex.m_nMODEL = 0;
    _vshIndex.m_nPORTALGHOSTOVERLAY = 0;
    SetPixelShaderConstant(this: pShaderAPI, a2: 0, a3: &x, a4: 1, a5: false);
    if ( v7 )
    {
      v19 = v30;
      CBaseShader::BindTexture(
        this: v30,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: STATICBLENDTEXTURE_0.m_Index,
        nFrameVar: STATICBLENDTEXTUREFRAME_0.m_Index);
      if ( bAlphaMaskTexture_3 )
        CBaseShader::BindTexture(
          this: v19,
          sampler1: SHADER_SAMPLER1,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: ALPHAMASKTEXTURE_0.m_Index,
          nFrameVar: ALPHAMASKTEXTUREFRAME_0.m_Index);
    }
    else if ( bAlphaMaskTexture_3 )
    {
      CBaseShader::BindTexture(
        this: v30,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: ALPHAMASKTEXTURE_0.m_Index,
        nFrameVar: ALPHAMASKTEXTUREFRAME_0.m_Index);
    }
    pShaderAPI->SetPixelShaderFogParams(this: pShaderAPI, a2: 12);
    pShaderAPI->GetWorldSpaceCameraPosition(this: pShaderAPI, a2: vEyePos_SpecExponent);
    v20 = pShaderAPI->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    v20(this: pShaderAPI, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    v21 = pShaderAPI->GetCurrentNumBones(this: pShaderAPI) > 0;
    if ( g_shaderConfigDumpEnable )
    {
      v22 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))pShaderAPI->GetCurrentNumBones)(
              a1: pShaderAPI,
              a2: "pShaderAPI->GetCurrentNumBones() > 0");
      printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v22 > 0, v24);
    }
    pShaderAPI->SetVertexShaderIndex(this: pShaderAPI, a2: v21);
    if ( bColorWrites || bAlphaMaskTexture_3 )
    {
      g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
      v23 = pShaderAPI->GetSceneFogMode(this: pShaderAPI);
      pShaderAPI->SetPixelShaderIndex(this: pShaderAPI, a2: v23 == MATERIAL_FOG_LINEAR_BELOW_FOG_Z);
    }
  }
  CBaseShader::Draw(this: v30, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x10027F40
// Name: public: virtual int PortalStaticOverlay::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall PortalStaticOverlay::CShader::GetParamCount(PortalStaticOverlay::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_81.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10027F50
// Name: public: virtual struct ShaderParamInfo_t const __near & PortalStaticOverlay::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *__thiscall PortalStaticOverlay::CShader::GetParamInfo(
        PortalStaticOverlay::CShader *this,
        int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_81.m_Memory.m_pMemory[param - ParamCount];
  else
    return (PortalStaticOverlay::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10027F80
// Name: public: PortalStaticOverlay::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *__thiscall PortalStaticOverlay::CShaderParam::CShaderParam(
        PortalStaticOverlay::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  PortalStaticOverlay::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  PortalStaticOverlay::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_81.m_Size + 13;
  m_Size = s_ShaderParams_81.m_Size;
  v8 = s_ShaderParams_81.m_Size;
  if ( s_ShaderParams_81.m_Size + 1 > s_ShaderParams_81.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_81,
      num: s_ShaderParams_81.m_Size - s_ShaderParams_81.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_81.m_Size;
  }
  m_pMemory = s_ShaderParams_81.m_Memory.m_pMemory;
  s_ShaderParams_81.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_81.m_pElements = s_ShaderParams_81.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_81.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_81.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_81.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064900
// Name: PortalStaticOverlay::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int PortalStaticOverlay::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: PortalStaticOverlay::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064910
// Name: PortalStaticOverlay::_dynamic_initializer_for__COLOR__
// Source: json
//------------------------------------------------------------------------------
void PortalStaticOverlay::_dynamic_initializer_for__COLOR__()
{
  s_pShaderParamOverrides_1[4] = &COLOR_1;
}

//------------------------------------------------------------------------------
// Address: 0x10064920
// Name: PortalStaticOverlay::_dynamic_initializer_for__ALPHA__
// Source: json
//------------------------------------------------------------------------------
void PortalStaticOverlay::_dynamic_initializer_for__ALPHA__()
{
  s_pShaderParamOverrides_1[5] = &ALPHA_2;
}

//------------------------------------------------------------------------------
// Address: 0x10064930
// Name: PortalStaticOverlay::_dynamic_initializer_for__STATICAMOUNT__
// Source: json
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *PortalStaticOverlay::_dynamic_initializer_for__STATICAMOUNT__()
{
  return PortalStaticOverlay::CShaderParam::CShaderParam(
           this: &STATICAMOUNT_0,
           pName: "$STATICAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Amount of the static blend texture to blend into the base texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064950
// Name: PortalStaticOverlay::_dynamic_initializer_for__STATICBLENDTEXTURE__
// Source: json
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *PortalStaticOverlay::_dynamic_initializer_for__STATICBLENDTEXTURE__()
{
  return PortalStaticOverlay::CShaderParam::CShaderParam(
           this: &STATICBLENDTEXTURE_0,
           pName: "$STATICBLENDTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "When adding static, this is the texture that gets blended in",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064970
// Name: PortalStaticOverlay::_dynamic_initializer_for__STATICBLENDTEXTUREFRAME__
// Source: json
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *PortalStaticOverlay::_dynamic_initializer_for__STATICBLENDTEXTUREFRAME__()
{
  return PortalStaticOverlay::CShaderParam::CShaderParam(
           this: &STATICBLENDTEXTUREFRAME_0,
           pName: "$STATICBLENDTEXTUREFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064990
// Name: PortalStaticOverlay::_dynamic_initializer_for__ALPHAMASKTEXTURE__
// Source: json
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *PortalStaticOverlay::_dynamic_initializer_for__ALPHAMASKTEXTURE__()
{
  return PortalStaticOverlay::CShaderParam::CShaderParam(
           this: &ALPHAMASKTEXTURE_0,
           pName: "$ALPHAMASKTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "An alpha mask for odd shaped portals",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100649B0
// Name: PortalStaticOverlay::_dynamic_initializer_for__ALPHAMASKTEXTUREFRAME__
// Source: json
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *PortalStaticOverlay::_dynamic_initializer_for__ALPHAMASKTEXTUREFRAME__()
{
  return PortalStaticOverlay::CShaderParam::CShaderParam(
           this: &ALPHAMASKTEXTUREFRAME_0,
           pName: "$ALPHAMASKTEXTUREFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100649D0
// Name: PortalStaticOverlay::_dynamic_initializer_for__NOCOLORWRITE__
// Source: json
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *PortalStaticOverlay::_dynamic_initializer_for__NOCOLORWRITE__()
{
  return PortalStaticOverlay::CShaderParam::CShaderParam(
           this: &NOCOLORWRITE,
           pName: "$NOCOLORWRITE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100649F0
// Name: PortalStaticOverlay::_dynamic_initializer_for__GHOSTOVERLAY__
// Source: json
//------------------------------------------------------------------------------
PortalStaticOverlay::CShaderParam *PortalStaticOverlay::_dynamic_initializer_for__GHOSTOVERLAY__()
{
  return PortalStaticOverlay::CShaderParam::CShaderParam(
           this: &GHOSTOVERLAY,
           pName: "$GHOSTOVERLAY",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064A10
// Name: PortalStaticOverlay::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *PortalStaticOverlay::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_81);
  s_ShaderInstance_81.__vftable = (PortalStaticOverlay::CShader_vtbl *)&PortalStaticOverlay::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B580
// Name: PortalStaticOverlay::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl PortalStaticOverlay::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_81);
}
