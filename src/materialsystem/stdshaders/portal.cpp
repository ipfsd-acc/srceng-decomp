// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/portal.cpp
// Functions: 29
// ============================================================

#include "materialsystem\stdshaders\portal.h"

//------------------------------------------------------------------------------
// Address: 0x10026020
// Name: public: virtual char const __near * Portal::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Portal::CShader::GetFallbackShader(Portal::CShader *this, IMaterialVar **params)
{
  return "Portal_DX90";
}

//------------------------------------------------------------------------------
// Address: 0x10026030
// Name: public: virtual char const __near * Portal::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Portal::CShader::GetName(Portal::CShader *this)
{
  return s_Name_77;
}

//------------------------------------------------------------------------------
// Address: 0x10026040
// Name: public: virtual int Portal::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Portal::CShader::GetFlags(Portal::CShader *this)
{
  return s_nFlags_94;
}

//------------------------------------------------------------------------------
// Address: 0x10026050
// Name: public: virtual int Portal::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Portal::CShader::GetParamCount(Portal::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_78.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10026060
// Name: public: virtual void Portal_DX90::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Portal_DX90::CShader::OnInitShaderParams(
        Portal_DX90::CShader *this,
        IMaterialVar **params,
        const char *pMaterialName)
{
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x200000);
  if ( !params[6]->IsDefined(this: params[6]) )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x4000);
}

//------------------------------------------------------------------------------
// Address: 0x100260A0
// Name: public: virtual char const __near * Portal_DX90::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Portal_DX90::CShader::GetName(Portal_DX90::CShader *this)
{
  return s_Name_78;
}

//------------------------------------------------------------------------------
// Address: 0x100260B0
// Name: public: virtual int Portal_DX90::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Portal_DX90::CShader::GetFlags(Portal_DX90::CShader *this)
{
  return s_nFlags_95;
}

//------------------------------------------------------------------------------
// Address: 0x100260C0
// Name: public: virtual void Portal_DX90::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Portal_DX90::CShader::OnInitShaderInstance(
        Portal_DX90::CShader *this,
        IMaterialVar **params,
        IShaderInit *pShaderInit,
        const char *pMaterialName)
{
  VMatrix matIdentity; // [esp+10h] [ebp-40h] BYREF

  if ( params[6]->IsDefined(this: params[6]) )
    CBaseShader::LoadTexture(this, nTextureVar: 6, nAdditionalCreationFlags: 0x80000);
  if ( params[STATICBLENDTEXTURE.m_Index]->IsDefined(this: params[STATICBLENDTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: STATICBLENDTEXTURE.m_Index, nAdditionalCreationFlags: 0);
  if ( params[ALPHAMASKTEXTURE.m_Index]->IsDefined(this: params[ALPHAMASKTEXTURE.m_Index]) )
    CBaseShader::LoadTexture(this, nTextureVar: ALPHAMASKTEXTURE.m_Index, nAdditionalCreationFlags: 0);
  if ( !params[STATICAMOUNT.m_Index]->IsDefined(this: params[STATICAMOUNT.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[STATICAMOUNT.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[STATICAMOUNT.m_Index]->IsDefined(this: params[STATICAMOUNT.m_Index]) )
    ((void (__stdcall *)(_DWORD))params[STATICAMOUNT.m_Index]->SetFloatValue)(a1: 0);
  if ( !params[STATICBLENDTEXTURE.m_Index]->IsDefined(this: params[STATICBLENDTEXTURE.m_Index]) )
    params[STATICBLENDTEXTURE.m_Index]->SetIntValue(this: params[STATICBLENDTEXTURE.m_Index], a2: 0);
  if ( !params[STATICBLENDTEXTUREFRAME.m_Index]->IsDefined(this: params[STATICBLENDTEXTUREFRAME.m_Index]) )
    params[STATICBLENDTEXTUREFRAME.m_Index]->SetIntValue(this: params[STATICBLENDTEXTUREFRAME.m_Index], a2: 0);
  if ( !params[ALPHAMASKTEXTURE.m_Index]->IsDefined(this: params[ALPHAMASKTEXTURE.m_Index]) )
    params[ALPHAMASKTEXTURE.m_Index]->SetIntValue(this: params[ALPHAMASKTEXTURE.m_Index], a2: 0);
  if ( !params[ALPHAMASKTEXTUREFRAME.m_Index]->IsDefined(this: params[ALPHAMASKTEXTUREFRAME.m_Index]) )
    params[ALPHAMASKTEXTUREFRAME.m_Index]->SetIntValue(this: params[ALPHAMASKTEXTUREFRAME.m_Index], a2: 0);
  if ( !params[RENDERFIXZ.m_Index]->IsDefined(this: params[RENDERFIXZ.m_Index]) )
    params[RENDERFIXZ.m_Index]->SetIntValue(this: params[RENDERFIXZ.m_Index], a2: 0);
  if ( !params[USEALTERNATEVIEWMATRIX.m_Index]->IsDefined(this: params[USEALTERNATEVIEWMATRIX.m_Index]) )
    params[USEALTERNATEVIEWMATRIX.m_Index]->SetIntValue(this: params[USEALTERNATEVIEWMATRIX.m_Index], a2: 0);
  if ( !params[ALTERNATEVIEWMATRIX.m_Index]->IsDefined(this: params[ALTERNATEVIEWMATRIX.m_Index]) )
  {
    MatrixSetIdentity(dst: &matIdentity);
    params[ALTERNATEVIEWMATRIX.m_Index]->SetMatrixValue(this: params[ALTERNATEVIEWMATRIX.m_Index], a2: &matIdentity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100262B0
// Name: public: virtual void Portal_DX90::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Portal_DX90::CShader::OnDrawElements(
        Portal_DX90::CShader *this,
        IMaterialVar **params,
        BOOL pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  IMaterialVar **v6; // ebx
  int *v7; // esi
  Portal_DX90::CShader *v8; // edi
  char v9; // dl
  int x_low; // xmm0_4
  int v11; // edx
  void (__thiscall *v12)(int *, int); // eax
  int v13; // eax
  int v14; // ecx
  BOOL v15; // edi
  BOOL v16; // ebx
  IShaderDynamicAPI *v17; // esi
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  void (__thiscall *v19)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  bool v20; // bl
  const VMatrix *v21; // edi
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v23; // edi
  float v24; // xmm0_4
  void (__thiscall *v25)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  int v26; // eax
  unsigned __int8 v27; // bl
  BOOL v28; // edi
  bool v29; // cc
  MaterialFogMode_t (__thiscall *GetSceneFogMode)(IShaderDynamicAPI *); // edx
  BOOL v31; // edi
  BOOL v32; // ebx
  BOOL v33; // edi
  const char *v34; // [esp-4h] [ebp-ECh]
  VMatrix matFinal; // [esp+Ch] [ebp-DCh] BYREF
  VMatrix matProj; // [esp+4Ch] [ebp-9Ch] BYREF
  float vEyePos_SpecExponent[4]; // [esp+8Ch] [ebp-5Ch] BYREF
  float pc0[4]; // [esp+9Ch] [ebp-4Ch] BYREF
  float vViewportMad[4]; // [esp+ACh] [ebp-3Ch] BYREF
  int nViewportX; // [esp+BCh] [ebp-2Ch] BYREF
  int nViewportY; // [esp+C0h] [ebp-28h]
  int v42; // [esp+C4h] [ebp-24h] BYREF
  float vPackedConst4[4]; // [esp+C8h] [ebp-20h] BYREF
  int nRtHeight; // [esp+D8h] [ebp-10h] BYREF
  int nViewportHeight; // [esp+DCh] [ebp-Ch] BYREF
  Portal_DX90::CShader *v46; // [esp+E0h] [ebp-8h]
  bool bStaticBlendTexture; // [esp+E6h] [ebp-2h]
  bool bAlphaMaskTexture; // [esp+E7h] [ebp-1h]

  v6 = params;
  v7 = (int *)pShaderShadow;
  v8 = this;
  v9 = *((_BYTE *)params[ALPHAMASKTEXTURE.m_Index] + 28);
  x_low = SLODWORD(params[STATICAMOUNT.m_Index]->m_VecVal.x);
  bStaticBlendTexture = (*((_BYTE *)params[STATICBLENDTEXTURE.m_Index] + 28) & 0xF) == 3;
  bAlphaMaskTexture = (v9 & 0xF) == 3;
  v46 = this;
  nViewportHeight = x_low;
  if ( pShaderShadow )
  {
    CBaseShader::SetInitialShadowState(this);
    CBaseShader::FogToFogColor(this: v8);
    v11 = *v7;
    if ( v6[RENDERFIXZ.m_Index]->m_intVal != 0 )
    {
      (*(void (__thiscall **)(int *, _DWORD))(v11 + 16))(a1: v7, a2: 0);
      (*(void (__thiscall **)(int *, int))(*v7 + 4))(a1: v7, a2: 7);
      (*(void (__thiscall **)(int *, _DWORD))(*v7 + 12))(a1: v7, a2: 0);
      (*(void (__stdcall **)(_DWORD))(*v7 + 8))(a1: 0);
    }
    else
    {
      (*(void (__stdcall **)(int))(v11 + 4))(a1: 3);
    }
    (*(void (__thiscall **)(int *, int))(*v7 + 48))(a1: v7, a2: 1);
    v12 = *(void (__thiscall **)(int *, int))(*v7 + 28);
    if ( bAlphaMaskTexture )
    {
      v12(a1: v7, a2: 1);
      (*(void (__thiscall **)(int *, int, int))(*v7 + 36))(a1: v7, a2: 4, a3: 5);
    }
    else
    {
      v12(a1: v7, a2: 0);
    }
    (*(void (__thiscall **)(int *, int))(*v7 + 76))(a1: v7, a2: 1);
    v13 = 0;
    v14 = 3;
    if ( ((*v6)->m_intVal & 0x800) != 0 )
      v13 = 4;
    else
      v14 = 51;
    (*(void (__thiscall **)(int *, int, int, _DWORD, int))(*v7 + 64))(a1: v7, a2: v14, a3: 2, a4: 0, a5: v13);
    (*(void (__thiscall **)(int *, _DWORD, int))(*v7 + 84))(a1: v7, a2: 0, a3: 1);
    (*(void (__thiscall **)(int *, _DWORD, int))(*v7 + 80))(a1: v7, a2: 0, a3: 1);
    if ( bStaticBlendTexture || bAlphaMaskTexture )
    {
      (*(void (__thiscall **)(int *, int, int))(*v7 + 84))(a1: v7, a2: 1, a3: 1);
      if ( bStaticBlendTexture && bAlphaMaskTexture )
        (*(void (__thiscall **)(int *, int, int))(*v7 + 84))(a1: v7, a2: 2, a3: 1);
    }
    (*(void (__thiscall **)(int *, int, int))(*v7 + 84))(a1: v7, a2: 3, a3: 1);
    (*(void (__thiscall **)(int *, int, _DWORD))(*v7 + 80))(a1: v7, a2: 3, a3: 0);
    nRtHeight = bAlphaMaskTexture;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "HASALPHAMASK", bAlphaMaskTexture, "bAlphaMaskTexture");
    pShaderShadow = bStaticBlendTexture;
    if ( g_shaderConfigDumpEnable )
      printf(format: "\n   VS stat var %s = %d (%s)", "HASSTATICTEXTURE", bStaticBlendTexture, "bStaticBlendTexture");
    v15 = v6[USEALTERNATEVIEWMATRIX.m_Index]->m_intVal != 0;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   VS stat var %s = %d (%s)",
        "USEALTERNATEVIEW",
        v15,
        "(params[USEALTERNATEVIEWMATRIX]->GetIntValue() != 0)");
    v16 = pShaderShadow;
    (*(void (__thiscall **)(int *, const char *, int))(*v7 + 68))(
      a1: v7,
      a2: "portal_vs20",
      a3: 4 * (nRtHeight + 2 * (pShaderShadow + 2 * v15)));
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "HASALPHAMASK", bAlphaMaskTexture, "bAlphaMaskTexture");
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "HASSTATICTEXTURE",
            bStaticBlendTexture,
            "bStaticBlendTexture");
      }
      (*(void (__thiscall **)(int *, const char *, int))(*v7 + 72))(
        a1: v7,
        a2: "portal_ps20",
        a3: 4 * (nRtHeight + 2 * v16));
    }
    else
    {
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "HASALPHAMASK", bAlphaMaskTexture, "bAlphaMaskTexture");
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS stat var %s = %d (%s)",
            "HASSTATICTEXTURE",
            bStaticBlendTexture,
            "bStaticBlendTexture");
      }
      (*(void (__thiscall **)(int *, const char *, int))(*v7 + 72))(
        a1: v7,
        a2: "portal_ps20b",
        a3: 8 * (nRtHeight + 2 * v16));
    }
    v6 = params;
    v8 = v46;
  }
  v17 = pShaderAPI;
  if ( pShaderAPI != nullptr )
  {
    pShaderAPI->SetDefaultState(this: pShaderAPI);
    SetPixelShaderConstant = v17->SetPixelShaderConstant;
    LODWORD(pc0[0]) = nViewportHeight;
    pc0[1] = 1.0 - *(float *)&nViewportHeight;
    pc0[2] = 0.0;
    pc0[3] = 0.0;
    SetPixelShaderConstant(this: v17, a2: 0, a3: pc0, a4: 1, a5: false);
    v17->SetPixelShaderFogParams(this: v17, a2: 12);
    v17->GetWorldSpaceCameraPosition(this: v17, a2: vEyePos_SpecExponent);
    v19 = v17->SetPixelShaderConstant;
    vEyePos_SpecExponent[3] = 0.0;
    v19(this: v17, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
    if ( (*((_BYTE *)v6[6] + 28) & 0xF) == 3 )
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER0,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: 6,
        nFrameVar: 7);
    else
      v17->BindStandardTexture(
        this: v17,
        a2: SHADER_SAMPLER0,
        a3: TEXTURE_BINDFLAGS_SRGBREAD,
        a4: TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0);
    HIBYTE(pShaderShadow) = *(float *)&nViewportHeight > 0.0;
    v20 = bStaticBlendTexture && HIBYTE(pShaderShadow) != 0;
    if ( bAlphaMaskTexture )
    {
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: ALPHAMASKTEXTURE.m_Index,
        nFrameVar: ALPHAMASKTEXTUREFRAME.m_Index);
      if ( v20 )
        CBaseShader::BindTexture(
          this: v8,
          sampler1: SHADER_SAMPLER2,
          nBindFlags: TEXTURE_BINDFLAGS_NONE,
          nTextureVar: STATICBLENDTEXTURE.m_Index,
          nFrameVar: STATICBLENDTEXTUREFRAME.m_Index);
    }
    else if ( v20 )
    {
      CBaseShader::BindTexture(
        this: v8,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: STATICBLENDTEXTURE.m_Index,
        nFrameVar: STATICBLENDTEXTUREFRAME.m_Index);
    }
    if ( params[USEALTERNATEVIEWMATRIX.m_Index]->m_intVal != 0 )
    {
      v21 = params[ALTERNATEVIEWMATRIX.m_Index]->GetMatrixValue(this: params[ALTERNATEVIEWMATRIX.m_Index]);
      v17->GetMatrix(this: v17, a2: MATERIAL_PROJECTION, a3: (float *)&matProj);
      MatrixTranspose(src: &matProj, dst: &matProj);
      MatrixMultiply(src1: &matProj, src2: v21, dst: &matFinal);
      v17->SetVertexShaderConstant(this: v17, a2: 48, a3: (const float *)&matFinal, a4: 4, a5: false);
    }
    v17->GetCurrentViewport(this: v17, a2: &nViewportX, a3: &v42, a4: (int *)&pShaderAPI, a5: &nViewportHeight);
    v17->GetCurrentRenderTargetDimensions(this: v17, a2: (int *)&params, a3: &nRtHeight);
    SetVertexShaderConstant = v17->SetVertexShaderConstant;
    vViewportMad[0] = (float)(int)pShaderAPI / (float)(int)params;
    vViewportMad[1] = (float)nViewportHeight / (float)nRtHeight;
    vViewportMad[2] = (float)nViewportX / (float)(int)params;
    vViewportMad[3] = (float)v42 / (float)nRtHeight;
    SetVertexShaderConstant(this: v17, a2: 52, a3: vViewportMad, a4: 1, a5: false);
    v23 = v17->GetIntRenderingParameter(this: v17, a2: 12);
    memset(vPackedConst4, 0, sizeof(vPackedConst4));
    if ( g_pHardwareConfig->UseFastClipping(this: g_pHardwareConfig) )
    {
      if ( v23 > 0 )
      {
        v24 = 1.0;
LABEL_53:
        v25 = v17->SetVertexShaderConstant;
        vPackedConst4[0] = v24;
        v25(this: v17, a2: 53, a3: vPackedConst4, a4: 1, a5: false);
        HIBYTE(params) = v17->IsStereoActiveThisFrame(this: v17);
        if ( HIBYTE(params) != 0 )
          v17->BindStandardTexture(
            this: v17,
            a2: SHADER_SAMPLER3,
            a3: TEXTURE_BINDFLAGS_NONE,
            a4: TEXTURE_STEREO_PARAM_MAP);
        nViewportY = v17->GetCurrentNumBones(this: v17) > 0;
        if ( g_shaderConfigDumpEnable )
        {
          v26 = ((int (__thiscall *)(IShaderDynamicAPI *, const char *))v17->GetCurrentNumBones)(
                  a1: v17,
                  a2: "pShaderAPI->GetCurrentNumBones() > 0");
          printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v26 > 0, v34);
        }
        v27 = HIBYTE(pShaderShadow);
        v28 = HIBYTE(pShaderShadow) != 0;
        pShaderShadow = v28;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "ADDSTATIC", v27, "bHasStatic");
        v17->SetVertexShaderIndex(this: v17, a2: nViewportY + 2 * v28);
        v29 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
        GetSceneFogMode = v17->GetSceneFogMode;
        if ( v29 )
        {
          v33 = GetSceneFogMode(this: v17) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS dyn  var %s = %d (%s)", "ADDSTATIC", v27, "bHasStatic");
          v17->SetPixelShaderIndex(this: v17, a2: pShaderShadow + 2 * v33);
        }
        else
        {
          v31 = GetSceneFogMode(this: v17) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   PS dyn  var %s = %d (%s)", "ADDSTATIC", v27, "bHasStatic");
          v32 = HIBYTE(params) != 0;
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS dyn  var %s = %d (%s)",
              "D_NVIDIA_STEREO",
              HIBYTE(params),
              "bNvidiaStereoActiveThisFrame");
          v17->SetPixelShaderIndex(this: v17, a2: pShaderShadow + 2 * (v32 + 2 * v31));
        }
        v8 = v46;
        goto LABEL_69;
      }
    }
    else if ( v23 > 1 )
    {
      v24 = 1.0;
      goto LABEL_53;
    }
    v24 = 0.0;
    goto LABEL_53;
  }
LABEL_69:
  CBaseShader::Draw(this: v8, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100269F0
// Name: public: virtual int Portal_DX90::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Portal_DX90::CShader::GetParamCount(Portal_DX90::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_77.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10026A00
// Name: public: virtual struct ShaderParamInfo_t const __near & Portal::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Portal::CShaderParam *__thiscall Portal::CShader::GetParamInfo(Portal::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_78.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Portal::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10026A30
// Name: public: virtual struct ShaderParamInfo_t const __near & Portal_DX90::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *__thiscall Portal_DX90::CShader::GetParamInfo(Portal_DX90::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_77.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Portal_DX90::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10026A60
// Name: public: Portal_DX90::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *__thiscall Portal_DX90::CShaderParam::CShaderParam(
        Portal_DX90::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Portal_DX90::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Portal_DX90::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_77.m_Size + 13;
  m_Size = s_ShaderParams_77.m_Size;
  v8 = s_ShaderParams_77.m_Size;
  if ( s_ShaderParams_77.m_Size + 1 > s_ShaderParams_77.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_77,
      num: s_ShaderParams_77.m_Size - s_ShaderParams_77.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_77.m_Size;
  }
  m_pMemory = s_ShaderParams_77.m_Memory.m_pMemory;
  s_ShaderParams_77.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_77.m_pElements = s_ShaderParams_77.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_77.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_77.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_77.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10064500
// Name: Portal::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Portal::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Portal::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064510
// Name: Portal::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Portal::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_78);
  s_ShaderInstance_78.__vftable = (Portal::CShader_vtbl *)&Portal::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064530
// Name: Portal_DX90::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Portal_DX90::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Portal_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10064540
// Name: Portal_DX90::_dynamic_initializer_for__COLOR__
// Source: json
//------------------------------------------------------------------------------
void Portal_DX90::_dynamic_initializer_for__COLOR__()
{
  s_pShaderParamOverrides_0[4] = &COLOR_0;
}

//------------------------------------------------------------------------------
// Address: 0x10064550
// Name: Portal_DX90::_dynamic_initializer_for__ALPHA__
// Source: json
//------------------------------------------------------------------------------
void Portal_DX90::_dynamic_initializer_for__ALPHA__()
{
  s_pShaderParamOverrides_0[5] = &ALPHA_1;
}

//------------------------------------------------------------------------------
// Address: 0x10064560
// Name: Portal_DX90::_dynamic_initializer_for__STATICAMOUNT__
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *Portal_DX90::_dynamic_initializer_for__STATICAMOUNT__()
{
  return Portal_DX90::CShaderParam::CShaderParam(
           this: &STATICAMOUNT,
           pName: "$STATICAMOUNT",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "0.0",
           pHelp: "Amount of the static blend texture to blend into the base texture",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064580
// Name: Portal_DX90::_dynamic_initializer_for__STATICBLENDTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *Portal_DX90::_dynamic_initializer_for__STATICBLENDTEXTURE__()
{
  return Portal_DX90::CShaderParam::CShaderParam(
           this: &STATICBLENDTEXTURE,
           pName: "$STATICBLENDTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "When adding static, this is the texture that gets blended in",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100645A0
// Name: Portal_DX90::_dynamic_initializer_for__STATICBLENDTEXTUREFRAME__
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *Portal_DX90::_dynamic_initializer_for__STATICBLENDTEXTUREFRAME__()
{
  return Portal_DX90::CShaderParam::CShaderParam(
           this: &STATICBLENDTEXTUREFRAME,
           pName: "$STATICBLENDTEXTUREFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100645C0
// Name: Portal_DX90::_dynamic_initializer_for__ALPHAMASKTEXTURE__
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *Portal_DX90::_dynamic_initializer_for__ALPHAMASKTEXTURE__()
{
  return Portal_DX90::CShaderParam::CShaderParam(
           this: &ALPHAMASKTEXTURE,
           pName: "$ALPHAMASKTEXTURE",
           type: SHADER_PARAM_TYPE_TEXTURE,
           pDefaultParam: pDefaultParam,
           pHelp: "An alpha mask for odd shaped portals",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100645E0
// Name: Portal_DX90::_dynamic_initializer_for__ALPHAMASKTEXTUREFRAME__
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *Portal_DX90::_dynamic_initializer_for__ALPHAMASKTEXTUREFRAME__()
{
  return Portal_DX90::CShaderParam::CShaderParam(
           this: &ALPHAMASKTEXTUREFRAME,
           pName: "$ALPHAMASKTEXTUREFRAME",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: pDefaultParam,
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064600
// Name: Portal_DX90::_dynamic_initializer_for__RENDERFIXZ__
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *Portal_DX90::_dynamic_initializer_for__RENDERFIXZ__()
{
  return Portal_DX90::CShaderParam::CShaderParam(
           this: &RENDERFIXZ,
           pName: "$RENDERFIXZ",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "Special depth handling, intended for rendering bug workarounds for extremely close polygons",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064620
// Name: Portal_DX90::_dynamic_initializer_for__USEALTERNATEVIEWMATRIX__
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *Portal_DX90::_dynamic_initializer_for__USEALTERNATEVIEWMATRIX__()
{
  return Portal_DX90::CShaderParam::CShaderParam(
           this: &USEALTERNATEVIEWMATRIX,
           pName: "$USEALTERNATEVIEWMATRIX",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "1",
           pHelp: "Use the alternate view matrix instead of the current view matrix",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064640
// Name: Portal_DX90::_dynamic_initializer_for__ALTERNATEVIEWMATRIX__
// Source: json
//------------------------------------------------------------------------------
Portal_DX90::CShaderParam *Portal_DX90::_dynamic_initializer_for__ALTERNATEVIEWMATRIX__()
{
  return Portal_DX90::CShaderParam::CShaderParam(
           this: &ALTERNATEVIEWMATRIX,
           pName: "$ALTERNATEVIEWMATRIX",
           type: SHADER_PARAM_TYPE_MATRIX,
           pDefaultParam: "0",
           pHelp: "The alternate view matrix to use when $usealternateviewmatrix is enabled",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064660
// Name: Portal_DX90::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Portal_DX90::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_77);
  s_ShaderInstance_77.__vftable = (Portal_DX90::CShader_vtbl *)&Portal_DX90::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B540
// Name: Portal::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Portal::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_78);
}

//------------------------------------------------------------------------------
// Address: 0x1006B550
// Name: Portal_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Portal_DX90::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_77);
}
