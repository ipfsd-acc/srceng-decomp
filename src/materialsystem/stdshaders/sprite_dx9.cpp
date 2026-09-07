// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/sprite_dx9.cpp
// Functions: 35
// ============================================================

#include "materialsystem\stdshaders\sprite_dx9.h"

//------------------------------------------------------------------------------
// Address: 0x10032920
// Name: public: virtual char const __near * Sprite::CShader::GetFallbackShader(class IMaterialVar __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Sprite::CShader::GetFallbackShader(Sprite::CShader *this, IMaterialVar **params)
{
  return "Sprite_DX9";
}

//------------------------------------------------------------------------------
// Address: 0x10032930
// Name: public: virtual char const __near * Sprite::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Sprite::CShader::GetName(Sprite::CShader *this)
{
  return s_Name_113;
}

//------------------------------------------------------------------------------
// Address: 0x10032940
// Name: public: virtual int Sprite::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sprite::CShader::GetFlags(Sprite::CShader *this)
{
  return s_nFlags_117;
}

//------------------------------------------------------------------------------
// Address: 0x10032950
// Name: public: virtual int Sprite::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sprite::CShader::GetParamCount(Sprite::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_113.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10032960
// Name: public: sprite_vs20_Dynamic_Index::sprite_vs20_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
sprite_vs20_Dynamic_Index *__thiscall sprite_vs20_Dynamic_Index::sprite_vs20_Dynamic_Index(
        sprite_vs20_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nDOWATERFOG = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10032990
// Name: public: virtual void Sprite_DX9::CShader::OnInitShaderParams(class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge Sprite_DX9::CShader::OnInitShaderParams(
        Sprite_DX9::CShader *this@<ecx>,
        int a2@<edi>,
        IMaterialVar **params,
        const char *pMaterialName)
{
  bool v4; // al
  IMaterialVar_vtbl *v5; // edx
  const char *v6; // edi

  if ( !params[5]->IsDefined(this: params[5]) )
    ((void (__stdcall *)(int))params[5]->SetFloatValue)(a1: 1065353216);
  if ( !params[HDRCOLORSCALE.m_Index]->IsDefined(this: params[HDRCOLORSCALE.m_Index]) )
    ((void (__stdcall *)(int))params[HDRCOLORSCALE.m_Index]->SetFloatValue)(a1: 1065353216);
  if ( !params[NOSRGB.m_Index]->IsDefined(this: params[NOSRGB.m_Index]) )
    params[NOSRGB.m_Index]->SetIntValue(this: params[NOSRGB.m_Index], a2: 1);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 2);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x10);
  ((void (__stdcall *)(int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x20);
  v4 = params[SPRITEORIENTATION.m_Index]->IsDefined(this: params[SPRITEORIENTATION.m_Index]);
  v5 = params[SPRITEORIENTATION.m_Index]->__vftable;
  if ( v4 )
  {
    v6 = (const char *)((int (__stdcall *)(int))v5->GetStringValue)(a1: a2);
    if ( _V_stricmp(s1: v6, s2: "parallel_upright") != 0 )
    {
      if ( _V_stricmp(s1: v6, s2: "facing_upright") == 0 )
      {
        params[SPRITEORIENTATION.m_Index]->SetIntValue(this: params[SPRITEORIENTATION.m_Index], a2: 1);
        return;
      }
      if ( _V_stricmp(s1: v6, s2: "vp_parallel") == 0 )
      {
        params[SPRITEORIENTATION.m_Index]->SetIntValue(this: params[SPRITEORIENTATION.m_Index], a2: 2);
        return;
      }
      if ( _V_stricmp(s1: v6, s2: "oriented") == 0 )
      {
        params[SPRITEORIENTATION.m_Index]->SetIntValue(this: params[SPRITEORIENTATION.m_Index], a2: 3);
        return;
      }
      if ( _V_stricmp(s1: v6, s2: "vp_parallel_oriented") == 0 )
      {
        params[SPRITEORIENTATION.m_Index]->SetIntValue(this: params[SPRITEORIENTATION.m_Index], a2: 4);
        return;
      }
      _Warning(a1: "error with $spriteOrientation\n");
    }
    params[SPRITEORIENTATION.m_Index]->SetIntValue(this: params[SPRITEORIENTATION.m_Index], a2: 0);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v5->SetIntValue)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032B60
// Name: public: virtual char const __near * Sprite_DX9::CShader::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Sprite_DX9::CShader::GetName(Sprite_DX9::CShader *this)
{
  return s_Name_114;
}

//------------------------------------------------------------------------------
// Address: 0x10032B70
// Name: public: virtual int Sprite_DX9::CShader::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sprite_DX9::CShader::GetFlags(Sprite_DX9::CShader *this)
{
  return s_nFlags_118;
}

//------------------------------------------------------------------------------
// Address: 0x10032B80
// Name: public: virtual void Sprite_DX9::CShader::OnInitShaderInstance(class IMaterialVar __near * __near *,class IShaderInit __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sprite_DX9::CShader::OnInitShaderInstance(
        Sprite_DX9::CShader *this,
        IMaterialVar **params,
        IMaterialVar **pShaderInit,
        IShaderInit *pMaterialName)
{
  CBaseShader::LoadTexture(
    this,
    nTextureVar: 6,
    nAdditionalCreationFlags: CBaseShader::s_ppParams[NOSRGB.m_Index]->m_intVal != 0 ? 0 : 0x80000);
}

//------------------------------------------------------------------------------
// Address: 0x10032BB0
// Name: public: void Sprite_DX9::CShader::SetSpriteCommonShadowState(unsigned int,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sprite_DX9::CShader::SetSpriteCommonShadowState(
        Sprite_DX9::CShader *this,
        char shaderFlags,
        IMaterialVar **params)
{
  IShaderShadow *v3; // esi
  unsigned int v5; // eax
  BOOL v6; // edi
  int v7; // esi
  BOOL v8; // ebx
  HDRType_t v9; // edi
  int v10; // eax
  int v11; // eax
  BOOL v12; // ebx
  HDRType_t v13; // edi
  int v14; // eax
  const char *v15; // [esp-4h] [ebp-28h]
  const char *v16; // [esp-4h] [ebp-28h]
  BOOL _vshIndex_12; // [esp+18h] [ebp-Ch]
  IShaderShadow *pShaderShadow; // [esp+1Ch] [ebp-8h]
  bool bSRGB; // [esp+20h] [ebp-4h]
  unsigned int shaderFlagsa; // [esp+2Ch] [ebp+8h]

  v3 = CBaseShader::s_pShaderShadow;
  pShaderShadow = CBaseShader::s_pShaderShadow;
  ((void (__stdcall *)(_DWORD, int))CBaseShader::s_pShaderShadow->EnableTexture)(a1: 0, a2: 1);
  bSRGB = CBaseShader::s_ppParams[NOSRGB.m_Index]->m_intVal == 0;
  v3->EnableSRGBRead(this: v3, a2: SHADER_SAMPLER0, a3: bSRGB);
  v5 = 1;
  if ( (shaderFlags & 1) != 0 )
    v5 = 5;
  CBaseShader::s_pShaderShadow->VertexShaderVertexFormat(
    this: CBaseShader::s_pShaderShadow,
    a2: v5,
    a3: 1,
    a4: nullptr,
    a5: 0);
  v6 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
  v7 = shaderFlags & 1;
  _vshIndex_12 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  if ( g_shaderConfigDumpEnable )
    printf(
      format: "\n   VS stat var %s = %d (%s)",
      "VERTEXCOLOR",
      shaderFlags & 1,
      "( shaderFlags & SHADER_USE_VERTEX_COLOR ) ? true : false");
  shaderFlagsa = bSRGB;
  if ( g_shaderConfigDumpEnable )
    printf(format: "\n   VS stat var %s = %d (%s)", "SRGB", bSRGB, "bSRGB");
  pShaderShadow->SetVertexShader(
    this: pShaderShadow,
    a2: "sprite_vs20",
    a3: 2 * (v7 + 2 * (shaderFlagsa + 2 * (v6 + 2 * _vshIndex_12))));
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
  {
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS stat var %s = %d (%s)",
        "VERTEXCOLOR",
        shaderFlags & 1,
        "( shaderFlags & SHADER_USE_VERTEX_COLOR ) ? true : false");
    v12 = (shaderFlags & 2) != 0;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS stat var %s = %d (%s)",
        "CONSTANTCOLOR",
        v12,
        "( shaderFlags & SHADER_USE_CONSTANT_COLOR ) ? true : false");
    v13 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
    if ( g_shaderConfigDumpEnable )
    {
      v14 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
              a1: g_pHardwareConfig,
              a2: "g_pHardwareConfig->GetHDRType()");
      printf(format: "\n   PS stat var %s = %d (%s)", "HDRTYPE", v14, v16);
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "SRGB", bSRGB, "bSRGB");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "SRGB_OUTPUT_ADAPTER", 0, "bSRGBOutputAdapter");
      }
    }
    v11 = ((int (__thiscall *)(IShaderShadow *, const char *, unsigned __int32))pShaderShadow->SetPixelShader)(
            a1: pShaderShadow,
            a2: "sprite_ps20b",
            a3: 4 * (v7 + 2 * (v12 + 2 * (shaderFlagsa + v13 + 2 * shaderFlagsa))));
  }
  else
  {
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS stat var %s = %d (%s)",
        "VERTEXCOLOR",
        shaderFlags & 1,
        "( shaderFlags & SHADER_USE_VERTEX_COLOR ) ? true : false");
    v8 = (shaderFlags & 2) != 0;
    if ( g_shaderConfigDumpEnable )
      printf(
        format: "\n   PS stat var %s = %d (%s)",
        "CONSTANTCOLOR",
        v8,
        "( shaderFlags & SHADER_USE_CONSTANT_COLOR ) ? true : false");
    v9 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
    if ( g_shaderConfigDumpEnable )
    {
      v10 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetHDRType)(
              a1: g_pHardwareConfig,
              a2: "g_pHardwareConfig->GetHDRType()");
      printf(format: "\n   PS stat var %s = %d (%s)", "HDRTYPE", v10, v15);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SRGB", bSRGB, "bSRGB");
    }
    v11 = ((int (__thiscall *)(IShaderShadow *, const char *, unsigned __int32))pShaderShadow->SetPixelShader)(
            a1: pShaderShadow,
            a2: "sprite_ps20",
            a3: 4 * (v7 + 2 * (v8 + 2 * (shaderFlagsa + v9 + 2 * shaderFlagsa))));
  }
  LOBYTE(v11) = bSRGB;
  CBaseShader::s_pShaderShadow->EnableSRGBWrite(this: CBaseShader::s_pShaderShadow, a2: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10032EC0
// Name: public: void Sprite_DX9::CShader::SetSpriteCommonDynamicState(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sprite_DX9::CShader::SetSpriteCommonDynamicState(Sprite_DX9::CShader *this, char shaderFlags)
{
  IShaderDynamicAPI *v2; // esi
  int v4; // eax
  BOOL v5; // ebx
  bool IsHDREnabled; // al
  float vEyePos_SpecExponent[4]; // [esp+Ch] [ebp-1Ch] BYREF
  sprite_ps20_Dynamic_Index _pshIndex; // [esp+1Ch] [ebp-Ch]
  bool bSRGB; // [esp+27h] [ebp-1h]

  v2 = CBaseShader::s_pShaderAPI;
  bSRGB = CBaseShader::s_ppParams[NOSRGB.m_Index]->m_intVal == 0;
  CBaseShader::BindTexture(
    this,
    sampler1: SHADER_SAMPLER0,
    nBindFlags: bSRGB ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
    nTextureVar: 6,
    nFrameVar: 7);
  v4 = v2->GetSceneFogMode(this: v2);
  v2->SetVertexShaderIndex(this: v2, a2: v4 == 2);
  g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
  v5 = v2->GetSceneFogMode(this: v2) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  _pshIndex.m_nHDRENABLED = CBaseShader::IsHDREnabled(this);
  if ( g_shaderConfigDumpEnable )
  {
    IsHDREnabled = CBaseShader::IsHDREnabled(this);
    printf(format: "\n   PS dyn  var %s = %d (%s)", "HDRENABLED", IsHDREnabled, "IsHDREnabled()");
  }
  v2->SetPixelShaderIndex(this: v2, a2: _pshIndex.m_nHDRENABLED + 2 * v5);
  v2->SetPixelShaderFogParams(this: v2, a2: 12);
  v2->GetWorldSpaceCameraPosition(this: v2, a2: vEyePos_SpecExponent);
  vEyePos_SpecExponent[3] = 0.0;
  v2->SetPixelShaderConstant(this: v2, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
  if ( (shaderFlags & 2) != 0 )
  {
    if ( bSRGB )
      CBaseVSShader::SetPixelShaderConstantGammaToLinear(this, pixelReg: 0, constantVar: 4, constantVar2: 5);
    else
      CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 0, constantVar: 4, constantVar2: 5);
  }
  if ( CBaseShader::IsHDREnabled(this) )
  {
    if ( bSRGB )
      CBaseVSShader::SetPixelShaderConstantGammaToLinear(this, pixelReg: 1, constantVar: HDRCOLORSCALE.m_Index);
    else
      CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 1, constantVar: HDRCOLORSCALE.m_Index);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033020
// Name: public: virtual void Sprite_DX9::CShader::OnDrawElements(class IMaterialVar __near * __near *,class IShaderShadow __near *,class IShaderDynamicAPI __near *,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Sprite_DX9::CShader::OnDrawElements(
        Sprite_DX9::CShader *this,
        IMaterialVar **params,
        IShaderShadow *pShaderShadow,
        IShaderDynamicAPI *pShaderAPI,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  float x; // xmm0_4
  bool v9; // zf
  float v10; // xmm1_4
  IShaderDynamicAPI *v11; // edi
  IMaterialVar *v12; // ecx
  ITexture *(__thiscall *GetTextureValue)(IMaterialVar *); // edx
  ITexture *v14; // eax
  bool IsHDREnabled; // al
  void (__thiscall *SetPixelShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  IMaterialVar *v17; // ecx
  ITexture *(__thiscall *v18)(IMaterialVar *); // edx
  ITexture *v19; // esi
  int v20; // eax
  BOOL v21; // esi
  bool v22; // al
  void (__thiscall *v23)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float vEyePos_SpecExponent[4]; // [esp+74h] [ebp-38h] BYREF
  float color[4]; // [esp+84h] [ebp-28h] BYREF
  sprite_ps20_Dynamic_Index _pshIndex; // [esp+94h] [ebp-18h] BYREF
  float flFrame; // [esp+9Ch] [ebp-10h]
  float frameBlendAlpha; // [esp+A0h] [ebp-Ch]
  unsigned int shaderFlags; // [esp+A4h] [ebp-8h]
  bool bSRGB; // [esp+ABh] [ebp-1h]
  char flags; // [esp+B4h] [ebp+8h]

  bSRGB = params[NOSRGB.m_Index]->m_intVal == 0;
  if ( pShaderShadow != nullptr )
    pShaderShadow->EnableCulling(this: pShaderShadow, a2: false);
  switch ( params[SPRITERENDERMODE.m_Index]->m_intVal )
  {
    case 0:
      if ( pShaderShadow != nullptr )
      {
        CBaseShader::FogToFogColor(this);
        Sprite_DX9::CShader::SetSpriteCommonShadowState(this, shaderFlags: 0, params);
      }
      if ( pShaderAPI != nullptr )
        Sprite_DX9::CShader::SetSpriteCommonDynamicState(this, shaderFlags: 0);
      goto LABEL_59;
    case 1:
    case 2:
      if ( pShaderShadow != nullptr )
      {
        pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
        pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
        pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
        CBaseShader::FogToFogColor(this);
        Sprite_DX9::CShader::SetSpriteCommonShadowState(this, shaderFlags: 1, params);
      }
      if ( pShaderAPI != nullptr )
        goto LABEL_21;
      goto LABEL_59;
    case 3:
    case 9:
      if ( pShaderShadow == nullptr )
        goto LABEL_16;
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
      pShaderShadow->EnableDepthTest(this: pShaderShadow, a2: false);
      pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
      pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE);
      break;
    case 4:
      if ( pShaderShadow != nullptr )
      {
        pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
        pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
        pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
        CBaseShader::FogToFogColor(this);
        Sprite_DX9::CShader::SetSpriteCommonShadowState(this, shaderFlags: 1, params);
      }
      if ( pShaderAPI != nullptr )
        goto LABEL_21;
      goto LABEL_59;
    case 5:
      flags = 2;
      if ( params[IGNOREVERTEXCOLORS.m_Index]->m_intVal == 0 )
        flags = 3;
      if ( pShaderShadow != nullptr )
      {
        pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
        pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
        pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE);
        CBaseShader::FogToBlack(this);
        Sprite_DX9::CShader::SetSpriteCommonShadowState(this, shaderFlags: flags, params);
      }
      if ( pShaderAPI != nullptr )
        Sprite_DX9::CShader::SetSpriteCommonDynamicState(this, shaderFlags: flags);
      goto LABEL_59;
    case 7:
      x = params[7]->m_VecVal.x;
      v9 = params[IGNOREVERTEXCOLORS.m_Index]->m_intVal == 0;
      v10 = params[5]->m_VecVal.x;
      flFrame = x;
      shaderFlags = 2;
      if ( v9 )
        shaderFlags = 3;
      if ( pShaderShadow != nullptr )
      {
        pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
        pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
        pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE);
        CBaseShader::FogToBlack(this);
        Sprite_DX9::CShader::SetSpriteCommonShadowState(this, shaderFlags, params);
        x = flFrame;
      }
      v11 = pShaderAPI;
      if ( pShaderAPI != nullptr )
      {
        v12 = params[6];
        pShaderAPI = (IShaderDynamicAPI *)(int)x;
        GetTextureValue = v12->GetTextureValue;
        frameBlendAlpha = 1.0 - (float)(x - (float)(int)x);
        v14 = GetTextureValue(this: v12);
        CBaseShader::BindTexture(
          this,
          sampler1: SHADER_SAMPLER0,
          nBindFlags: bSRGB ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
          pTexture: v14,
          nFrame: (int)pShaderAPI);
        sprite_vs20_Dynamic_Index::sprite_vs20_Dynamic_Index(
          this: (sprite_vs20_Dynamic_Index *)&pShaderAPI,
          pShaderAPI: v11);
        v11->SetVertexShaderIndex(this: v11, a2: (int)pShaderAPI);
        g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
        sprite_ps20_Dynamic_Index::sprite_ps20_Dynamic_Index(
          this: (sprite_ps20b_Dynamic_Index *)&_pshIndex,
          pShaderAPI: v11);
        _pshIndex.m_nHDRENABLED = CBaseShader::IsHDREnabled(this);
        if ( g_shaderConfigDumpEnable )
        {
          IsHDREnabled = CBaseShader::IsHDREnabled(this);
          printf(format: "\n   PS dyn  var %s = %d (%s)", "HDRENABLED", IsHDREnabled, "IsHDREnabled()");
        }
        v11->SetPixelShaderIndex(this: v11, a2: _pshIndex.m_nHDRENABLED + 2 * _pshIndex.m_nPIXELFOGTYPE);
        v11->SetPixelShaderFogParams(this: v11, a2: 12);
        v11->GetWorldSpaceCameraPosition(this: v11, a2: vEyePos_SpecExponent);
        SetPixelShaderConstant = v11->SetPixelShaderConstant;
        vEyePos_SpecExponent[3] = 0.0;
        SetPixelShaderConstant(this: v11, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
        if ( bSRGB )
        {
          color[2] = GammaToLinear(gamma: frameBlendAlpha * v10);
          color[1] = color[2];
          color[0] = color[2];
        }
        else
        {
          color[2] = frameBlendAlpha * v10;
          color[1] = frameBlendAlpha * v10;
          color[0] = frameBlendAlpha * v10;
        }
        color[3] = 1.0;
        CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
          this: CBaseShader::s_pShaderAPI,
          a2: 0,
          a3: color,
          a4: 1,
          a5: false);
        if ( CBaseShader::IsHDREnabled(this) )
        {
          if ( bSRGB )
            CBaseVSShader::SetPixelShaderConstantGammaToLinear(this, pixelReg: 1, constantVar: HDRCOLORSCALE.m_Index);
          else
            CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 1, constantVar: HDRCOLORSCALE.m_Index);
        }
      }
      CBaseShader::Draw(this, bMakeActualDrawCall: true);
      if ( pShaderShadow != nullptr )
      {
        CBaseShader::FogToBlack(this);
        Sprite_DX9::CShader::SetSpriteCommonShadowState(this, shaderFlags, params);
      }
      if ( v11 != nullptr )
      {
        v17 = params[6];
        pShaderAPI = (IShaderDynamicAPI *)(int)flFrame;
        v18 = v17->GetTextureValue;
        flFrame = flFrame - (float)(int)flFrame;
        v19 = v18(this: v17);
        v20 = v19->GetNumAnimationFrames(this: v19);
        CBaseShader::BindTexture(
          this,
          sampler1: SHADER_SAMPLER0,
          nBindFlags: bSRGB ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
          pTexture: v19,
          nFrame: ((int)&pShaderAPI->__vftable + 1) % v20);
        sprite_vs20_Dynamic_Index::sprite_vs20_Dynamic_Index(
          this: (sprite_vs20_Dynamic_Index *)&pShaderAPI,
          pShaderAPI: v11);
        v11->SetVertexShaderIndex(this: v11, a2: (int)pShaderAPI);
        g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
        sprite_ps20_Dynamic_Index::sprite_ps20_Dynamic_Index(
          this: (sprite_ps20b_Dynamic_Index *)&_pshIndex,
          pShaderAPI: v11);
        v21 = CBaseShader::IsHDREnabled(this);
        if ( g_shaderConfigDumpEnable )
        {
          v22 = CBaseShader::IsHDREnabled(this);
          printf(format: "\n   PS dyn  var %s = %d (%s)", "HDRENABLED", v22, "IsHDREnabled()");
        }
        v11->SetPixelShaderIndex(this: v11, a2: v21 + 2 * _pshIndex.m_nPIXELFOGTYPE);
        v11->SetPixelShaderFogParams(this: v11, a2: 12);
        v11->GetWorldSpaceCameraPosition(this: v11, a2: vEyePos_SpecExponent);
        v23 = v11->SetPixelShaderConstant;
        vEyePos_SpecExponent[3] = 0.0;
        v23(this: v11, a2: 11, a3: vEyePos_SpecExponent, a4: 1, a5: false);
        if ( bSRGB )
        {
          color[2] = GammaToLinear(gamma: flFrame * v10);
          color[1] = color[2];
          color[0] = color[2];
        }
        else
        {
          color[2] = flFrame * v10;
          color[1] = flFrame * v10;
          color[0] = flFrame * v10;
        }
        color[3] = 1.0;
        CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
          this: CBaseShader::s_pShaderAPI,
          a2: 0,
          a3: color,
          a4: 1,
          a5: false);
        if ( CBaseShader::IsHDREnabled(this) )
        {
          if ( bSRGB )
            CBaseVSShader::SetPixelShaderConstantGammaToLinear(this, pixelReg: 1, constantVar: HDRCOLORSCALE.m_Index);
          else
            CBaseVSShader::SetPixelShaderConstant(this, pixelReg: 1, constantVar: HDRCOLORSCALE.m_Index);
        }
      }
      goto LABEL_59;
    case 8:
      if ( pShaderShadow != nullptr )
      {
        pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
        pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
        pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_SRC_ALPHA, a3: SHADER_BLEND_ONE_MINUS_SRC_ALPHA);
        CBaseShader::FogToFogColor(this);
        Sprite_DX9::CShader::SetSpriteCommonShadowState(this, shaderFlags: 1, params);
      }
      if ( pShaderAPI != nullptr )
        Sprite_DX9::CShader::SetSpriteCommonDynamicState(this, shaderFlags: 1);
      CBaseShader::Draw(this, bMakeActualDrawCall: true);
      if ( pShaderShadow == nullptr )
        goto LABEL_16;
      CBaseShader::SetInitialShadowState(this);
      pShaderShadow->EnableDepthWrites(this: pShaderShadow, a2: false);
      pShaderShadow->EnableBlending(this: pShaderShadow, a2: true);
      pShaderShadow->BlendFunc(this: pShaderShadow, a2: SHADER_BLEND_ONE_MINUS_SRC_ALPHA, a3: SHADER_BLEND_ONE);
      break;
    default:
      if ( pShaderShadow != nullptr )
        _Warning(a1: "shader Sprite: Unknown sprite render mode\n");
      return;
  }
  CBaseShader::FogToBlack(this);
  Sprite_DX9::CShader::SetSpriteCommonShadowState(this, shaderFlags: 1, params);
LABEL_16:
  if ( pShaderAPI != nullptr )
LABEL_21:
    Sprite_DX9::CShader::SetSpriteCommonDynamicState(this, shaderFlags: 1);
LABEL_59:
  CBaseShader::Draw(this, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x100336B0
// Name: public: virtual int Sprite_DX9::CShader::GetParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall Sprite_DX9::CShader::GetParamCount(Sprite_DX9::CShader *this)
{
  int m_Size; // esi

  m_Size = s_ShaderParams_114.m_Size;
  return m_Size + CBaseShader::GetParamCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x100336C0
// Name: public: virtual struct ShaderParamInfo_t const __near & Sprite::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Sprite::CShaderParam *__thiscall Sprite::CShader::GetParamInfo(Sprite::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_113.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Sprite::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x100336F0
// Name: public: virtual struct ShaderParamInfo_t const __near & Sprite_DX9::CShader::GetParamInfo(int)const
// Source: rtti_class
//------------------------------------------------------------------------------
Sprite_DX9::CShaderParam *__thiscall Sprite_DX9::CShader::GetParamInfo(Sprite_DX9::CShader *this, int param)
{
  int ParamCount; // eax

  ParamCount = CBaseShader::GetParamCount(this);
  if ( param >= ParamCount )
    return s_ShaderParams_114.m_Memory.m_pMemory[param - ParamCount];
  else
    return (Sprite_DX9::CShaderParam *)CBaseShader::GetParamInfo(this, nParamIndex: param);
}

//------------------------------------------------------------------------------
// Address: 0x10033720
// Name: public: Sprite_DX9::CShaderParam::CShaderParam(char const __near *,enum ShaderParamType_t,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
Sprite_DX9::CShaderParam *__thiscall Sprite_DX9::CShaderParam::CShaderParam(
        Sprite_DX9::CShaderParam *this,
        const char *pName,
        ShaderParamType_t type,
        const char *pDefaultParam,
        const char *pHelp,
        int nFlags)
{
  int m_Size; // eax
  int v8; // edi
  Sprite_DX9::CShaderParam **m_pMemory; // ecx
  int v10; // eax
  Sprite_DX9::CShaderParam **v11; // eax

  this->m_Info.m_pName = pName;
  this->m_Info.m_Type = type;
  this->m_Info.m_pDefaultValue = pDefaultParam;
  this->m_Info.m_pHelp = pHelp;
  this->m_Info.m_nFlags = nFlags;
  this->m_Index = s_ShaderParams_114.m_Size + 13;
  m_Size = s_ShaderParams_114.m_Size;
  v8 = s_ShaderParams_114.m_Size;
  if ( s_ShaderParams_114.m_Size + 1 > s_ShaderParams_114.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&s_ShaderParams_114,
      num: s_ShaderParams_114.m_Size - s_ShaderParams_114.m_Memory.m_nAllocationCount + 1);
    m_Size = s_ShaderParams_114.m_Size;
  }
  m_pMemory = s_ShaderParams_114.m_Memory.m_pMemory;
  s_ShaderParams_114.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  s_ShaderParams_114.m_pElements = s_ShaderParams_114.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &s_ShaderParams_114.m_Memory.m_pMemory[v8 + 1],
      src: &s_ShaderParams_114.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = s_ShaderParams_114.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039340
// Name: public: sprite_ps20_Dynamic_Index::sprite_ps20_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
sprite_ps20b_Dynamic_Index *__thiscall sprite_ps20_Dynamic_Index::sprite_ps20_Dynamic_Index(
        sprite_ps20b_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nHDRENABLED = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067060
// Name: Sprite::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Sprite::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Sprite::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x10067070
// Name: Sprite::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Sprite::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_113);
  s_ShaderInstance_113.__vftable = (Sprite::CShader_vtbl *)&Sprite::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067090
// Name: Sprite_DX9::_dynamic_initializer_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
int Sprite_DX9::_dynamic_initializer_for__s_ShaderParams__()
{
  return atexit(func: Sprite_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__);
}

//------------------------------------------------------------------------------
// Address: 0x100670A0
// Name: Sprite_DX9::_dynamic_initializer_for__SPRITEORIGIN__
// Source: json
//------------------------------------------------------------------------------
Sprite_DX9::CShaderParam *Sprite_DX9::_dynamic_initializer_for__SPRITEORIGIN__()
{
  return Sprite_DX9::CShaderParam::CShaderParam(
           this: &SPRITEORIGIN,
           pName: "$SPRITEORIGIN",
           type: SHADER_PARAM_TYPE_VEC3,
           pDefaultParam: "[0 0 0]",
           pHelp: "sprite origin",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100670C0
// Name: Sprite_DX9::_dynamic_initializer_for__SPRITEORIENTATION__
// Source: json
//------------------------------------------------------------------------------
Sprite_DX9::CShaderParam *Sprite_DX9::_dynamic_initializer_for__SPRITEORIENTATION__()
{
  return Sprite_DX9::CShaderParam::CShaderParam(
           this: &SPRITEORIENTATION,
           pName: "$SPRITEORIENTATION",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "sprite orientation",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100670E0
// Name: Sprite_DX9::_dynamic_initializer_for__SPRITERENDERMODE__
// Source: json
//------------------------------------------------------------------------------
Sprite_DX9::CShaderParam *Sprite_DX9::_dynamic_initializer_for__SPRITERENDERMODE__()
{
  return Sprite_DX9::CShaderParam::CShaderParam(
           this: &SPRITERENDERMODE,
           pName: "$SPRITERENDERMODE",
           type: SHADER_PARAM_TYPE_INTEGER,
           pDefaultParam: "0",
           pHelp: "sprite rendermode",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067100
// Name: Sprite_DX9::_dynamic_initializer_for__IGNOREVERTEXCOLORS__
// Source: json
//------------------------------------------------------------------------------
Sprite_DX9::CShaderParam *Sprite_DX9::_dynamic_initializer_for__IGNOREVERTEXCOLORS__()
{
  return Sprite_DX9::CShaderParam::CShaderParam(
           this: &IGNOREVERTEXCOLORS,
           pName: "$IGNOREVERTEXCOLORS",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "1",
           pHelp: "ignore vertex colors",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067120
// Name: Sprite_DX9::_dynamic_initializer_for__NOSRGB__
// Source: json
//------------------------------------------------------------------------------
Sprite_DX9::CShaderParam *Sprite_DX9::_dynamic_initializer_for__NOSRGB__()
{
  return Sprite_DX9::CShaderParam::CShaderParam(
           this: &NOSRGB,
           pName: "$NOSRGB",
           type: SHADER_PARAM_TYPE_BOOL,
           pDefaultParam: "0",
           pHelp: "do not operate in srgb space",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067140
// Name: Sprite_DX9::_dynamic_initializer_for__HDRCOLORSCALE__
// Source: json
//------------------------------------------------------------------------------
Sprite_DX9::CShaderParam *Sprite_DX9::_dynamic_initializer_for__HDRCOLORSCALE__()
{
  return Sprite_DX9::CShaderParam::CShaderParam(
           this: &HDRCOLORSCALE,
           pName: "$HDRCOLORSCALE",
           type: SHADER_PARAM_TYPE_FLOAT,
           pDefaultParam: "1.0",
           pHelp: "hdr color scale",
           nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10067160
// Name: Sprite_DX9::_dynamic_initializer_for__s_ShaderInstance__
// Source: json
//------------------------------------------------------------------------------
CBaseShader *Sprite_DX9::_dynamic_initializer_for__s_ShaderInstance__()
{
  CBaseShader *result; // eax

  result = CBaseShader::CBaseShader(this: &s_ShaderInstance_114);
  s_ShaderInstance_114.__vftable = (Sprite_DX9::CShader_vtbl *)&Sprite_DX9::CShader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006B7C0
// Name: Sprite::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sprite::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_113);
}

//------------------------------------------------------------------------------
// Address: 0x1006B7D0
// Name: Sprite_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sprite_DX9::_dynamic_atexit_destructor_for__s_ShaderParams__()
{
  CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>::~CUtlVector<PortalRefract::CShaderParam *,CUtlMemory<PortalRefract::CShaderParam *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&s_ShaderParams_114);
}

//------------------------------------------------------------------------------
// Address: 0x10067180
// Name: _dynamic_initializer_for__s_ConstructMe_spritecard_ps20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_spritecard_ps20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &spritecard_ps20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100671A0
// Name: _dynamic_initializer_for__s_ConstructMe_spritecard_ps20b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_spritecard_ps20b__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &spritecard_ps20b_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100671C0
// Name: _dynamic_initializer_for__s_ConstructMe_spritecard_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_spritecard_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &spritecard_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x100671E0
// Name: _dynamic_initializer_for__s_ConstructMe_splinecard_vs20__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ConstructMe_splinecard_vs20__()
{
  IShaderDLL *ShaderDLL; // eax

  ShaderDLL = GetShaderDLL();
  return ((int (__thiscall *)(IShaderDLL *, ShaderComboSemantics_t *))ShaderDLL->AddShaderComboInformation)(
           a1: ShaderDLL,
           a2: &splinecard_vs20_combos);
}

//------------------------------------------------------------------------------
// Address: 0x10067200
// Name: _dynamic_initializer_for__mat_depthfeather_enable___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_depthfeather_enable___0()
{
  ConVar::ConVar(this: &mat_depthfeather_enable_0, pName: "mat_depthfeather_enable", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_depthfeather_enable___0);
}

//------------------------------------------------------------------------------
// Address: 0x1006B7E0
// Name: _dynamic_atexit_destructor_for__mat_depthfeather_enable___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_depthfeather_enable___0()
{
  ConVar::~ConVar(this: &mat_depthfeather_enable_0);
}
