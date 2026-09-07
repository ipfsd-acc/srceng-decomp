// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/hardwareconfig.cpp
// Functions: 70
// ============================================================

#include "materialsystem\shaderapidx9\hardwareconfig.h"

//------------------------------------------------------------------------------
// Address: 0x100033B0
// Name: public: virtual bool CHardwareConfig::GetHDREnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::GetHDREnabled(CHardwareConfig *this)
{
  return this->m_bHDREnabled;
}

//------------------------------------------------------------------------------
// Address: 0x100033C0
// Name: public: virtual void CHardwareConfig::SetHDREnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::SetHDREnabled(CHardwareConfig *this, bool bEnable)
{
  this->m_bHDREnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100033D0
// Name: public: virtual void CHardwareConfig::OverrideStreamOffsetSupport(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::OverrideStreamOffsetSupport(
        CHardwareConfig *this,
        bool bOverrideEnabled,
        bool bEnableSupport)
{
  if ( bOverrideEnabled )
  {
    *((_BYTE *)&this->m_Caps + 717) ^= (*((_BYTE *)&this->m_Caps + 717) ^ (bEnableSupport << 6)) & 0x40;
    if ( (*((_BYTE *)&this->m_ActualCaps + 717) & 0x40) == 0 )
      *((_BYTE *)&this->m_Caps + 717) &= ~0x40u;
  }
  else
  {
    *((_BYTE *)&this->m_Caps + 717) ^= (*((_BYTE *)&this->m_Caps + 717)
                                      ^ *((_BYTE *)&this->m_UnOverriddenCaps + 717))
                                     & 0x40;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003430
// Name: public: virtual bool CHardwareConfig::HasStencilBuffer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::HasStencilBuffer(CHardwareConfig *this)
{
  return this->StencilBufferBits(this) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003450
// Name: public: virtual int CHardwareConfig::GetFrameBufferColorDepth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetFrameBufferColorDepth(CHardwareConfig *this)
{
  IShaderUtil *v2; // esi
  IShaderUtil_vtbl *v3; // edi
  ImageFormat v4; // eax

  if ( g_pShaderDevice == nullptr )
    return 0;
  v2 = g_pShaderUtil;
  v3 = g_pShaderUtil->__vftable;
  v4 = g_pShaderDevice->GetBackBufferFormat(this: g_pShaderDevice);
  return v3->ImageFormatInfo(this: v2, a2: v4)->m_nNumBytes;
}

//------------------------------------------------------------------------------
// Address: 0x10003480
// Name: public: virtual int CHardwareConfig::GetSamplerCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetSamplerCount(CHardwareConfig *this)
{
  return this->m_Caps.m_NumSamplers;
}

//------------------------------------------------------------------------------
// Address: 0x10003490
// Name: public: virtual int CHardwareConfig::GetVertexSamplerCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetVertexSamplerCount(CHardwareConfig *this)
{
  return this->m_Caps.m_NumVertexSamplers;
}

//------------------------------------------------------------------------------
// Address: 0x100034A0
// Name: public: virtual bool CHardwareConfig::HasSetDeviceGammaRamp(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::HasSetDeviceGammaRamp(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 716) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100034B0
// Name: public: virtual enum VertexCompressionType_t CHardwareConfig::SupportsCompressedVertices(void)const
// Source: json
//------------------------------------------------------------------------------
VertexCompressionType_t __thiscall CHardwareConfig::SupportsCompressedVertices(CHardwareConfig *this)
{
  return this->m_Caps.m_SupportsCompressedVertices;
}

//------------------------------------------------------------------------------
// Address: 0x100034C0
// Name: public: virtual bool CHardwareConfig::SupportsBorderColor(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsBorderColor(CHardwareConfig *this)
{
  return *((_BYTE *)&this->m_Caps + 718) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x100034D0
// Name: public: virtual bool CHardwareConfig::SupportsFetch4(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsFetch4(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 718) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100034E0
// Name: public: virtual float CHardwareConfig::GetShadowDepthBias(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHardwareConfig::GetShadowDepthBias(CHardwareConfig *this)
{
  return mat_depthbias_shadowmap.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x100034F0
// Name: public: virtual float CHardwareConfig::GetShadowSlopeScaleDepthBias(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHardwareConfig::GetShadowSlopeScaleDepthBias(CHardwareConfig *this)
{
  return mat_slopescaledepthbias_shadowmap.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10003500
// Name: public: virtual bool CHardwareConfig::PreferZPrepass(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::PreferZPrepass(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003510
// Name: public: virtual bool CHardwareConfig::SuppressPixelShaderCentroidHackFixup(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SuppressPixelShaderCentroidHackFixup(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003520
// Name: public: virtual bool CHardwareConfig::PreferTexturesInHWMemory(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::PreferTexturesInHWMemory(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003530
// Name: public: virtual bool CHardwareConfig::PreferHardwareSync(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::PreferHardwareSync(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003540
// Name: public: virtual bool CHardwareConfig::SupportsStaticControlFlow(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsStaticControlFlow(CHardwareConfig *this)
{
  return *((_BYTE *)&this->m_Caps + 720) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003550
// Name: public: virtual bool CHardwareConfig::IsUnsupported(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::IsUnsupported(CHardwareConfig *this)
{
  return *((_BYTE *)&this->m_Caps + 719) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x10003560
// Name: public: virtual enum ShadowFilterMode_t CHardwareConfig::GetShadowFilterMode(bool,bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetShadowFilterMode(CHardwareConfig *this, bool bForceLowQualityShadows, bool bPS30)
{
  bool v4; // bl
  unsigned int m_VendorID; // eax

  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    ConVarRef::ConVarRef(this: &gpu_level, pName: "gpu_level");
  }
  v4 = gpu_level.m_pConVarState->m_Value.m_nValue < 2 || bForceLowQualityShadows;
  if ( (*((_BYTE *)&this->m_Caps + 718) & 4) != 0
    && g_pShaderUtil->GetConfig(this: g_pShaderUtil)->m_bShadowDepthTexture
    && (unsigned int)(this->m_Caps.m_ShadowDepthTextureFormat - 47) <= 1 )
  {
    m_VendorID = this->m_Caps.m_VendorID;
    if ( m_VendorID == 4318 || m_VendorID == 32902 )
      return v4 ? 2 : 0;
    if ( m_VendorID == 4098 )
    {
      if ( !bPS30 && v4 )
        return 3;
      if ( (*((_BYTE *)&this->m_Caps + 719) & 1) != 0 )
        return v4 ? 2 : 0;
      if ( (*((_BYTE *)&this->m_Caps + 718) & 8) != 0 )
        return 1;
      else
        return 2 * !bPS30 + 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003650
// Name: public: virtual int CHardwareConfig::NeedsShaderSRGBConversion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHardwareConfig::NeedsShaderSRGBConversion(CHardwareConfig *this)
{
  int m_nValue; // eax

  if ( r_shader_srgb.m_pParent != nullptr )
    m_nValue = r_shader_srgb.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( m_nValue == 0 )
    return false;
  if ( m_nValue == 1 )
    return true;
  return (*((_BYTE *)&this->m_ActualCaps + 719) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003680
// Name: public: virtual bool CHardwareConfig::UsesSRGBCorrectBlending(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHardwareConfig::UsesSRGBCorrectBlending(CHardwareConfig *this)
{
  return (r_shader_srgb.m_pParent == nullptr || r_shader_srgb.m_pParent->m_Value.m_nValue == 0)
      && (*((_BYTE *)&this->m_ActualCaps + 719) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100036B0
// Name: public: virtual bool CHardwareConfig::HasFastVertexTextures(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHardwareConfig::HasFastVertexTextures(CHardwareConfig *this)
{
  bool v1; // zf
  int v3; // eax
  int m_nValue; // eax

  v1 = s_bEnableFastVertexTextures == 0;
  if ( s_bEnableFastVertexTextures < 0 )
  {
    s_bEnableFastVertexTextures = 1;
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-disallowhwmorph") != 0 )
      s_bEnableFastVertexTextures = 0;
    if ( mat_disablehwmorph.m_pParent != nullptr )
      m_nValue = mat_disablehwmorph.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    s_bDisableHWMorph = m_nValue != 0;
    v1 = s_bEnableFastVertexTextures == 0;
  }
  return !v1 && !s_bDisableHWMorph && this->GetDXSupportLevel(this) >= 100;
}

//------------------------------------------------------------------------------
// Address: 0x10003730
// Name: public: virtual bool CHardwareConfig::ActualHasFastVertexTextures(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHardwareConfig::ActualHasFastVertexTextures(CHardwareConfig *this)
{
  bool v1; // zf
  int v3; // eax
  int m_nValue; // eax

  v1 = s_bEnableFastVertexTextures == 0;
  if ( s_bEnableFastVertexTextures < 0 )
  {
    s_bEnableFastVertexTextures = 1;
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-disallowhwmorph") != 0 )
      s_bEnableFastVertexTextures = 0;
    if ( mat_disablehwmorph.m_pParent != nullptr )
      m_nValue = mat_disablehwmorph.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    s_bDisableHWMorph = m_nValue != 0;
    v1 = s_bEnableFastVertexTextures == 0;
  }
  return !v1 && !s_bDisableHWMorph && this->GetMaxDXSupportLevel(this) >= 100;
}

//------------------------------------------------------------------------------
// Address: 0x100037B0
// Name: public: virtual int CHardwareConfig::MaxHWMorphBatchCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxHWMorphBatchCount(CHardwareConfig *this)
{
  return g_pShaderUtil->MaxHWMorphBatchCount(this: g_pShaderUtil);
}

//------------------------------------------------------------------------------
// Address: 0x100037C0
// Name: public: virtual int CHardwareConfig::MaximumAnisotropicLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaximumAnisotropicLevel(CHardwareConfig *this)
{
  return this->m_Caps.m_nMaxAnisotropy;
}

//------------------------------------------------------------------------------
// Address: 0x100037D0
// Name: public: virtual int CHardwareConfig::MaxTextureWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxTextureWidth(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxTextureWidth;
}

//------------------------------------------------------------------------------
// Address: 0x100037E0
// Name: public: virtual int CHardwareConfig::MaxTextureHeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxTextureHeight(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxTextureHeight;
}

//------------------------------------------------------------------------------
// Address: 0x100037F0
// Name: public: virtual int CHardwareConfig::TextureMemorySize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::TextureMemorySize(CHardwareConfig *this)
{
  return this->m_Caps.m_TextureMemorySize;
}

//------------------------------------------------------------------------------
// Address: 0x10003800
// Name: public: virtual bool CHardwareConfig::SupportsMipmappedCubemaps(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsMipmappedCubemaps(CHardwareConfig *this)
{
  return *((_BYTE *)&this->m_Caps + 717) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003810
// Name: public: virtual int CHardwareConfig::NumVertexShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumVertexShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumVertexShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003820
// Name: public: virtual int CHardwareConfig::NumBooleanVertexShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumBooleanVertexShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumBooleanVertexShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003830
// Name: public: virtual int CHardwareConfig::NumIntegerVertexShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumIntegerVertexShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumIntegerVertexShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003840
// Name: public: virtual int CHardwareConfig::NumPixelShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumPixelShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumPixelShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003850
// Name: public: virtual int CHardwareConfig::NumBooleanPixelShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumBooleanPixelShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumBooleanPixelShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003860
// Name: public: virtual int CHardwareConfig::NumIntegerPixelShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumIntegerPixelShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumIntegerPixelShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003870
// Name: public: virtual int CHardwareConfig::MaxNumLights(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxNumLights(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxNumLights;
}

//------------------------------------------------------------------------------
// Address: 0x10003880
// Name: public: virtual int CHardwareConfig::MaxTextureAspectRatio(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxTextureAspectRatio(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxTextureAspectRatio;
}

//------------------------------------------------------------------------------
// Address: 0x10003890
// Name: public: virtual int CHardwareConfig::MaxVertexShaderBlendMatrices(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxVertexShaderBlendMatrices(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxVertexShaderBlendMatrices;
}

//------------------------------------------------------------------------------
// Address: 0x100038A0
// Name: public: virtual int CHardwareConfig::MaxTextureDepth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxTextureDepth(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxTextureDepth;
}

//------------------------------------------------------------------------------
// Address: 0x100038B0
// Name: public: virtual int CHardwareConfig::GetDXSupportLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetDXSupportLevel(CHardwareConfig *this)
{
  return this->m_Caps.m_nDXSupportLevel;
}

//------------------------------------------------------------------------------
// Address: 0x100038C0
// Name: public: virtual char const __near * CHardwareConfig::GetShaderDLLName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHardwareConfig::GetShaderDLLName(CHardwareConfig *this)
{
  char *result; // eax

  result = this->m_Caps.m_pShaderDLL;
  if ( this == (CHardwareConfig *)-1364 || *result == 0 )
    return "DEFAULT";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100038F0
// Name: public: virtual bool CHardwareConfig::PreferDynamicTextures(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::PreferDynamicTextures(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 717) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003900
// Name: public: virtual bool CHardwareConfig::SupportsHDRMode(enum HDRType_t)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHardwareConfig::SupportsHDRMode(CHardwareConfig *this, HDRType_t nHDRType)
{
  HDRType_t m_MaxHDRType; // eax

  if ( nHDRType == HDR_TYPE_NONE )
    return 1;
  if ( nHDRType != HDR_TYPE_INTEGER )
    return nHDRType == HDR_TYPE_FLOAT && this->m_Caps.m_MaxHDRType == HDR_TYPE_FLOAT;
  m_MaxHDRType = this->m_Caps.m_MaxHDRType;
  return m_MaxHDRType == HDR_TYPE_INTEGER || m_MaxHDRType == HDR_TYPE_FLOAT;
}

//------------------------------------------------------------------------------
// Address: 0x10003950
// Name: public: virtual bool CHardwareConfig::NeedsATICentroidHack(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::NeedsATICentroidHack(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 717) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003960
// Name: public: virtual int CHardwareConfig::GetMaxDXSupportLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetMaxDXSupportLevel(CHardwareConfig *this)
{
  return this->m_ActualCaps.m_nMaxDXSupportLevel;
}

//------------------------------------------------------------------------------
// Address: 0x10003970
// Name: public: virtual int CHardwareConfig::GetMinDXSupportLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetMinDXSupportLevel(CHardwareConfig *this)
{
  int result; // eax

  if ( developer.m_pParent == nullptr )
    return this->m_ActualCaps.m_nMinDXSupportLevel;
  result = 90;
  if ( developer.m_pParent->m_Value.m_nValue <= 0 )
    return this->m_ActualCaps.m_nMinDXSupportLevel;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003990
// Name: public: virtual bool CHardwareConfig::SpecifiesFogColorInLinearSpace(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SpecifiesFogColorInLinearSpace(CHardwareConfig *this)
{
  return *((_BYTE *)&this->m_Caps + 717) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x100039A0
// Name: public: virtual bool CHardwareConfig::SupportsSRGB(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsSRGB(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 717) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100039B0
// Name: public: virtual bool CHardwareConfig::FakeSRGBWrite(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::FakeSRGBWrite(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 720) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100039C0
// Name: public: virtual bool CHardwareConfig::CanDoSRGBReadFromRTs(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::CanDoSRGBReadFromRTs(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 720) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100039D0
// Name: public: virtual bool CHardwareConfig::SupportsGLMixedSizeTargets(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsGLMixedSizeTargets(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 720) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100039E0
// Name: public: virtual bool CHardwareConfig::IsAAEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::IsAAEnabled(CHardwareConfig *this)
{
  return g_pShaderDevice != nullptr && g_pShaderDevice->IsAAEnabled(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10003A00
// Name: public: virtual int CHardwareConfig::GetMaxVertexTextureDimension(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetMaxVertexTextureDimension(CHardwareConfig *this)
{
  return this->m_Caps.m_nMaxVertexTextureDimension;
}

//------------------------------------------------------------------------------
// Address: 0x10003A10
// Name: public: virtual float CHardwareConfig::GetLightMapScaleFactor(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHardwareConfig::GetLightMapScaleFactor(CHardwareConfig *this)
{
  __int32 v1; // eax

  v1 = this->GetHDRType(this) - 1;
  if ( v1 == 0 )
    return 16.0;
  if ( v1 == 1 )
    return 1.0;
  return GammaToLinearFullRange(gamma: 2.0);
}

//------------------------------------------------------------------------------
// Address: 0x10003A50
// Name: public: virtual enum HDRType_t CHardwareConfig::GetHardwareHDRType(void)const
// Source: json
//------------------------------------------------------------------------------
HDRType_t __thiscall CHardwareConfig::GetHardwareHDRType(CHardwareConfig *this)
{
  return this->m_Caps.m_HDRType;
}

//------------------------------------------------------------------------------
// Address: 0x10003A60
// Name: public: virtual bool CHardwareConfig::SupportsStreamOffset(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsStreamOffset(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 717) & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003A70
// Name: public: virtual int CHardwareConfig::StencilBufferBits(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::StencilBufferBits(CHardwareConfig *this)
{
  if ( g_pShaderDevice != nullptr )
    return g_pShaderDevice->StencilBufferBits(this: g_pShaderDevice);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003A90
// Name: public: virtual int CHardwareConfig::MaxViewports(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxViewports(CHardwareConfig *this)
{
  return this->m_Caps.m_nMaxViewports;
}

//------------------------------------------------------------------------------
// Address: 0x10003AA0
// Name: public: int CHardwareConfig::GetActualSamplerCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetActualSamplerCount(CHardwareConfig *this)
{
  return this->m_ActualCaps.m_NumSamplers;
}

//------------------------------------------------------------------------------
// Address: 0x10003AB0
// Name: public: virtual char const __near * CHardwareConfig::GetHWSpecificShaderDLLName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHardwareConfig::GetHWSpecificShaderDLLName(CHardwareConfig *this)
{
  char *result; // eax

  result = this->m_Caps.m_pShaderDLL;
  if ( this == (CHardwareConfig *)-1364 || *result == 0 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003AD0
// Name: public: virtual bool CHardwareConfig::SupportsShadowDepthTextures(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsShadowDepthTextures(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 718) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003AE0
// Name: public: virtual enum ImageFormat CHardwareConfig::GetShadowDepthTextureFormat(void)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CHardwareConfig::GetShadowDepthTextureFormat(CHardwareConfig *this)
{
  return this->m_Caps.m_ShadowDepthTextureFormat;
}

//------------------------------------------------------------------------------
// Address: 0x10003AF0
// Name: public: virtual enum ImageFormat CHardwareConfig::GetNullTextureFormat(void)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CHardwareConfig::GetNullTextureFormat(CHardwareConfig *this)
{
  return this->m_Caps.m_NullTextureFormat;
}

//------------------------------------------------------------------------------
// Address: 0x10003B00
// Name: protected: void CHardwareConfig::ForceCapsToDXLevel(struct HardwareCaps_t __near *,int,struct HardwareCaps_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::ForceCapsToDXLevel(
        CHardwareConfig *this,
        HardwareCaps_t *pCaps,
        int nDxLevel,
        const HardwareCaps_t *actualCaps)
{
  if ( nDxLevel <= 100 )
  {
    pCaps->m_nDXSupportLevel = nDxLevel;
    if ( nDxLevel == 90 )
    {
      *((_BYTE *)pCaps + 718) &= ~0x80u;
      *((_BYTE *)pCaps + 716) &= 0xB3u;
      pCaps->m_NumVertexSamplers = 0;
    }
    else
    {
      if ( nDxLevel != 92 )
      {
        if ( nDxLevel == 95 )
        {
          *((_BYTE *)pCaps + 719) &= 0xFCu;
          *((_BYTE *)pCaps + 718) &= ~0x80u;
          pCaps->m_MaxNumLights = 4;
          pCaps->m_nMaxViewports = 1;
        }
        return;
      }
      *((_BYTE *)pCaps + 718) &= ~0x80u;
      *((_BYTE *)pCaps + 716) &= 0xB7u;
      pCaps->m_NumVertexSamplers = 0;
      pCaps->m_nMaxVertexTextureDimension = 0;
      if ( r_emulategl.m_pParent == nullptr || r_emulategl.m_pParent->m_Value.m_nValue == 0 )
      {
        pCaps->m_MaxNumLights = 4;
LABEL_12:
        *((_BYTE *)pCaps + 719) &= 0xFCu;
        pCaps->m_MaxPixelShader30InstructionSlots = 0;
        pCaps->m_MaxVertexShader30InstructionSlots = 0;
        pCaps->m_nMaxVertexTextureDimension = 0;
        pCaps->m_NumPixelShaderConstants = 32;
        pCaps->m_nMaxViewports = 1;
        return;
      }
      *((_BYTE *)pCaps + 720) &= ~1u;
      *((_BYTE *)pCaps + 717) &= ~8u;
      pCaps->m_MaxUserClipPlanes = 2;
    }
    pCaps->m_MaxNumLights = 2;
    goto LABEL_12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003C00
// Name: public: void CHardwareConfig::SetupHardwareCaps(int,struct HardwareCaps_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::SetupHardwareCaps(
        CHardwareConfig *this,
        int nDXLevel,
        const HardwareCaps_t *actualCaps)
{
  int v4; // eax
  int v5; // eax
  int m_MaxUserClipPlanes; // eax
  int m_MaxNumLights; // eax

  if ( nDXLevel < actualCaps->m_nMinDXSupportLevel )
    _Warning(
      a1: "Trying to set dxlevel (%d) which is lower than the card can support (%d)!\n",
      nDXLevel,
      actualCaps->m_nMinDXSupportLevel);
  if ( nDXLevel > actualCaps->m_nMaxDXSupportLevel )
    _Warning(
      a1: "Trying to set dxlevel (%d) which is higher than the card can support (%d)!\n",
      nDXLevel,
      actualCaps->m_nMaxDXSupportLevel);
  qmemcpy(&this->m_Caps, actualCaps, sizeof(this->m_Caps));
  qmemcpy(&this->m_UnOverriddenCaps, actualCaps, sizeof(this->m_UnOverriddenCaps));
  v4 = _CommandLine();
  v5 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 28))(a1: v4, a2: "-maxdxlevel", a3: 0);
  if ( v5 >= 90 )
  {
    this->m_Caps.m_nDXSupportLevel = v5;
    CHardwareConfig::ForceCapsToDXLevel(this, pCaps: &this->m_Caps, nDxLevel: v5, actualCaps: &this->m_ActualCaps);
    CShaderDeviceMgrBase::ReadHardwareCaps(
      this: g_pShaderDeviceMgr,
      caps: &this->m_Caps,
      nDxLevel: this->m_Caps.m_nDXSupportLevel);
    m_MaxUserClipPlanes = this->m_ActualCaps.m_MaxUserClipPlanes;
    if ( this->m_Caps.m_MaxUserClipPlanes > m_MaxUserClipPlanes )
      this->m_Caps.m_MaxUserClipPlanes = m_MaxUserClipPlanes;
    if ( this->m_Caps.m_MaxUserClipPlanes == 0 )
      *((_BYTE *)&this->m_Caps + 717) |= 8u;
    if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    {
      *((_BYTE *)&this->m_Caps + 718) |= 4u;
    }
    else if ( (*((_BYTE *)&this->m_Caps + 716) & 4) != 0 )
    {
      this->m_Caps.m_MaxNumLights = 4;
      goto LABEL_14;
    }
    this->m_Caps.m_MaxNumLights = 2;
LABEL_14:
    m_MaxNumLights = this->m_Caps.m_MaxNumLights;
    if ( m_MaxNumLights >= 4 )
      m_MaxNumLights = 4;
    this->m_Caps.m_MaxNumLights = m_MaxNumLights;
    qmemcpy(&this->m_UnOverriddenCaps, &this->m_Caps, sizeof(this->m_UnOverriddenCaps));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D30
// Name: public: void CHardwareConfig::SetupHardwareCaps(struct ShaderDeviceInfo_t const __near &,struct HardwareCaps_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::SetupHardwareCaps(
        CHardwareConfig *this,
        const ShaderDeviceInfo_t *mode,
        const HardwareCaps_t *actualCaps)
{
  qmemcpy(&this->m_ActualCaps, actualCaps, sizeof(this->m_ActualCaps));
  CHardwareConfig::SetupHardwareCaps(this, nDXLevel: mode->m_nDXLevel, actualCaps);
}

//------------------------------------------------------------------------------
// Address: 0x10003D60
// Name: public: virtual int CHardwareConfig::MaxUserClipPlanes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxUserClipPlanes(CHardwareConfig *this)
{
  if ( mat_fastclip.m_pParent != nullptr && mat_fastclip.m_pParent->m_Value.m_nValue != 0 )
    return 0;
  else
    return this->m_Caps.m_MaxUserClipPlanes;
}

//------------------------------------------------------------------------------
// Address: 0x10003D80
// Name: public: virtual bool CHardwareConfig::UseFastClipping(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::UseFastClipping(CHardwareConfig *this)
{
  int m_nValue; // eax

  if ( mat_fastclip.m_pParent != nullptr )
    m_nValue = mat_fastclip.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  return (*((_BYTE *)&this->m_Caps + 717) & 8) != 0 || m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003DB0
// Name: public: virtual enum HDRType_t CHardwareConfig::GetHDRType(void)const
// Source: json
//------------------------------------------------------------------------------
HDRType_t __thiscall CHardwareConfig::GetHDRType(CHardwareConfig *this)
{
  bool m_bHDREnabled; // bl
  BOOL v3; // ecx
  HDRType_t result; // eax

  if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    g_pHardwareConfig->SetHDREnabled(this: g_pHardwareConfig, a2: true);
  m_bHDREnabled = this->m_bHDREnabled;
  v3 = this->GetDXSupportLevel(this) >= 90;
  result = HDR_TYPE_NONE;
  if ( m_bHDREnabled && v3 )
    return this->m_Caps.m_HDRType;
  return result;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10002F80
// Name: public: virtual bool CHardwareConfig::GetHDREnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::GetHDREnabled(CHardwareConfig *this)
{
  return this->m_bHDREnabled;
}

//------------------------------------------------------------------------------
// Address: 0x10002F90
// Name: public: virtual void CHardwareConfig::SetHDREnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::SetHDREnabled(CHardwareConfig *this, bool bEnable)
{
  this->m_bHDREnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10002FA0
// Name: public: virtual void CHardwareConfig::OverrideStreamOffsetSupport(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::OverrideStreamOffsetSupport(
        CHardwareConfig *this,
        bool bOverrideEnabled,
        bool bEnableSupport)
{
  if ( bOverrideEnabled )
  {
    *((_BYTE *)&this->m_Caps + 717) ^= (*((_BYTE *)&this->m_Caps + 717) ^ (bEnableSupport << 6)) & 0x40;
    if ( (*((_BYTE *)&this->m_ActualCaps + 717) & 0x40) == 0 )
      *((_BYTE *)&this->m_Caps + 717) &= ~0x40u;
  }
  else
  {
    *((_BYTE *)&this->m_Caps + 717) ^= (*((_BYTE *)&this->m_Caps + 717)
                                      ^ *((_BYTE *)&this->m_UnOverriddenCaps + 717))
                                     & 0x40;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002FF0
// Name: public: virtual bool CHardwareConfig::HasStencilBuffer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::HasStencilBuffer(CHardwareConfig *this)
{
  return this->StencilBufferBits(this) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003010
// Name: public: virtual int CHardwareConfig::GetFrameBufferColorDepth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetFrameBufferColorDepth(CHardwareConfig *this)
{
  IShaderUtil *v2; // esi
  IShaderUtil_vtbl *v3; // edi
  ImageFormat v4; // eax

  if ( g_pShaderDevice == nullptr )
    return 0;
  v2 = g_pShaderUtil;
  v3 = g_pShaderUtil->__vftable;
  v4 = g_pShaderDevice->GetBackBufferFormat(this: g_pShaderDevice);
  return v3->ImageFormatInfo(this: v2, a2: v4)->m_nNumBytes;
}

//------------------------------------------------------------------------------
// Address: 0x10003040
// Name: public: virtual int CHardwareConfig::GetSamplerCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetSamplerCount(CHardwareConfig *this)
{
  return this->m_Caps.m_NumSamplers;
}

//------------------------------------------------------------------------------
// Address: 0x10003050
// Name: public: virtual int CHardwareConfig::GetVertexSamplerCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetVertexSamplerCount(CHardwareConfig *this)
{
  return this->m_Caps.m_NumVertexSamplers;
}

//------------------------------------------------------------------------------
// Address: 0x10003060
// Name: public: virtual bool CHardwareConfig::HasSetDeviceGammaRamp(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::HasSetDeviceGammaRamp(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 716) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003070
// Name: public: virtual enum VertexCompressionType_t CHardwareConfig::SupportsCompressedVertices(void)const
// Source: json
//------------------------------------------------------------------------------
VertexCompressionType_t __thiscall CHardwareConfig::SupportsCompressedVertices(CHardwareConfig *this)
{
  return this->m_Caps.m_SupportsCompressedVertices;
}

//------------------------------------------------------------------------------
// Address: 0x10003080
// Name: public: virtual bool CHardwareConfig::SupportsBorderColor(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsBorderColor(CHardwareConfig *this)
{
  return *((_BYTE *)&this->m_Caps + 718) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x10003090
// Name: public: virtual bool CHardwareConfig::SupportsFetch4(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsFetch4(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 718) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100030A0
// Name: public: virtual float CHardwareConfig::GetShadowDepthBias(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHardwareConfig::GetShadowDepthBias(CHardwareConfig *this)
{
  return mat_depthbias_shadowmap.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x100030B0
// Name: public: virtual float CHardwareConfig::GetShadowSlopeScaleDepthBias(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHardwareConfig::GetShadowSlopeScaleDepthBias(CHardwareConfig *this)
{
  return mat_slopescaledepthbias_shadowmap.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x100030C0
// Name: public: virtual bool CHardwareConfig::PreferZPrepass(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::PreferZPrepass(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100030D0
// Name: public: virtual bool CHardwareConfig::SuppressPixelShaderCentroidHackFixup(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SuppressPixelShaderCentroidHackFixup(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100030E0
// Name: public: virtual bool CHardwareConfig::PreferTexturesInHWMemory(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::PreferTexturesInHWMemory(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100030F0
// Name: public: virtual bool CHardwareConfig::PreferHardwareSync(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::PreferHardwareSync(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003100
// Name: public: virtual bool CHardwareConfig::SupportsStaticControlFlow(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsStaticControlFlow(CHardwareConfig *this)
{
  return *((_BYTE *)&this->m_Caps + 719) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x10003110
// Name: public: virtual bool CHardwareConfig::IsUnsupported(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::IsUnsupported(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 719) & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003120
// Name: public: virtual int CHardwareConfig::GetShadowFilterMode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetShadowFilterMode(CHardwareConfig *this)
{
  if ( (*((_BYTE *)&this->m_Caps + 718) & 4) != 0
    && g_pShaderUtil->GetConfig(this: g_pShaderUtil)->m_bShadowDepthTexture
    && (unsigned int)(this->m_Caps.m_ShadowDepthTextureFormat - 47) <= 1
    && this->m_Caps.m_VendorID == 4098 )
  {
    return ((*((_BYTE *)&this->m_Caps + 718) & 8) != 0) + 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003180
// Name: public: virtual int CHardwareConfig::NeedsShaderSRGBConversion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NeedsShaderSRGBConversion(CHardwareConfig *this)
{
  int m_nValue; // eax

  m_nValue = r_shader_srgb.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    return 0;
  if ( m_nValue == 1 )
    return 1;
  return *((_BYTE *)&this->m_ActualCaps + 719) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100031B0
// Name: public: virtual bool CHardwareConfig::UsesSRGBCorrectBlending(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::UsesSRGBCorrectBlending(CHardwareConfig *this)
{
  int result; // eax

  if ( r_shader_srgb.m_pParent->m_Value.m_nValue != 0 )
    return 0;
  result = 1;
  if ( (*((_BYTE *)&this->m_ActualCaps + 719) & 1) == 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100031D0
// Name: public: virtual bool CHardwareConfig::HasFastVertexTextures(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHardwareConfig::HasFastVertexTextures(CHardwareConfig *this)
{
  bool v1; // zf
  int v3; // eax

  v1 = s_bEnableFastVertexTextures == 0;
  if ( s_bEnableFastVertexTextures < 0 )
  {
    s_bEnableFastVertexTextures = 1;
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-disallowhwmorph") != 0 )
      s_bEnableFastVertexTextures = 0;
    s_bDisableHWMorph = mat_disablehwmorph.m_pParent->m_Value.m_nValue != 0;
    v1 = s_bEnableFastVertexTextures == 0;
  }
  return !v1 && !s_bDisableHWMorph && this->GetDXSupportLevel(this) >= 100;
}

//------------------------------------------------------------------------------
// Address: 0x10003250
// Name: public: virtual bool CHardwareConfig::ActualHasFastVertexTextures(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHardwareConfig::ActualHasFastVertexTextures(CHardwareConfig *this)
{
  bool v1; // zf
  int v3; // eax

  v1 = s_bEnableFastVertexTextures == 0;
  if ( s_bEnableFastVertexTextures < 0 )
  {
    s_bEnableFastVertexTextures = 1;
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-disallowhwmorph") != 0 )
      s_bEnableFastVertexTextures = 0;
    s_bDisableHWMorph = mat_disablehwmorph.m_pParent->m_Value.m_nValue != 0;
    v1 = s_bEnableFastVertexTextures == 0;
  }
  return !v1 && !s_bDisableHWMorph && this->GetMaxDXSupportLevel(this) >= 100;
}

//------------------------------------------------------------------------------
// Address: 0x100032D0
// Name: public: virtual int CHardwareConfig::MaxHWMorphBatchCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxHWMorphBatchCount(CHardwareConfig *this)
{
  return g_pShaderUtil->MaxHWMorphBatchCount(this: g_pShaderUtil);
}

//------------------------------------------------------------------------------
// Address: 0x100032E0
// Name: public: virtual int CHardwareConfig::MaximumAnisotropicLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaximumAnisotropicLevel(CHardwareConfig *this)
{
  return this->m_Caps.m_nMaxAnisotropy;
}

//------------------------------------------------------------------------------
// Address: 0x100032F0
// Name: public: virtual int CHardwareConfig::MaxTextureWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxTextureWidth(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxTextureWidth;
}

//------------------------------------------------------------------------------
// Address: 0x10003300
// Name: public: virtual int CHardwareConfig::MaxTextureHeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxTextureHeight(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxTextureHeight;
}

//------------------------------------------------------------------------------
// Address: 0x10003310
// Name: public: virtual int CHardwareConfig::TextureMemorySize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::TextureMemorySize(CHardwareConfig *this)
{
  return this->m_Caps.m_TextureMemorySize;
}

//------------------------------------------------------------------------------
// Address: 0x10003320
// Name: public: virtual bool CHardwareConfig::SupportsMipmappedCubemaps(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsMipmappedCubemaps(CHardwareConfig *this)
{
  return *((_BYTE *)&this->m_Caps + 717) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003330
// Name: public: virtual int CHardwareConfig::NumVertexShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumVertexShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumVertexShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003340
// Name: public: virtual int CHardwareConfig::NumBooleanVertexShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumBooleanVertexShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumBooleanVertexShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003350
// Name: public: virtual int CHardwareConfig::NumIntegerVertexShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumIntegerVertexShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumIntegerVertexShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003360
// Name: public: virtual int CHardwareConfig::NumPixelShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumPixelShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumPixelShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003370
// Name: public: virtual int CHardwareConfig::NumBooleanPixelShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumBooleanPixelShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumBooleanPixelShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003380
// Name: public: virtual int CHardwareConfig::NumIntegerPixelShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::NumIntegerPixelShaderConstants(CHardwareConfig *this)
{
  return this->m_Caps.m_NumIntegerPixelShaderConstants;
}

//------------------------------------------------------------------------------
// Address: 0x10003390
// Name: public: virtual int CHardwareConfig::MaxNumLights(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxNumLights(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxNumLights;
}

//------------------------------------------------------------------------------
// Address: 0x100033A0
// Name: public: virtual int CHardwareConfig::MaxTextureAspectRatio(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxTextureAspectRatio(CHardwareConfig *this)
{
  return this->m_Caps.m_MaxTextureAspectRatio;
}

//------------------------------------------------------------------------------
// Address: 0x100033E0
// Name: public: virtual char const __near * CHardwareConfig::GetShaderDLLName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHardwareConfig::GetShaderDLLName(CHardwareConfig *this)
{
  char *result; // eax

  result = this->m_Caps.m_pShaderDLL;
  if ( this == (CHardwareConfig *)-1364 || *result == 0 )
    return "DEFAULT";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003400
// Name: public: virtual bool CHardwareConfig::PreferDynamicTextures(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::PreferDynamicTextures(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 717) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003410
// Name: public: virtual bool CHardwareConfig::SupportsHDRMode(enum HDRType_t)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHardwareConfig::SupportsHDRMode(CHardwareConfig *this, HDRType_t nHDRType)
{
  HDRType_t m_MaxHDRType; // eax

  if ( nHDRType == HDR_TYPE_NONE )
    return 1;
  if ( nHDRType != HDR_TYPE_INTEGER )
    return nHDRType == HDR_TYPE_FLOAT && this->m_Caps.m_MaxHDRType == HDR_TYPE_FLOAT;
  m_MaxHDRType = this->m_Caps.m_MaxHDRType;
  return m_MaxHDRType == HDR_TYPE_INTEGER || m_MaxHDRType == HDR_TYPE_FLOAT;
}

//------------------------------------------------------------------------------
// Address: 0x10003460
// Name: public: virtual bool CHardwareConfig::NeedsATICentroidHack(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::NeedsATICentroidHack(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 717) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003470
// Name: public: virtual int CHardwareConfig::GetMaxDXSupportLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetMaxDXSupportLevel(CHardwareConfig *this)
{
  return this->m_ActualCaps.m_nMaxDXSupportLevel;
}

//------------------------------------------------------------------------------
// Address: 0x10003570
// Name: public: virtual bool CHardwareConfig::SupportsStreamOffset(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsStreamOffset(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 717) & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003580
// Name: public: virtual int CHardwareConfig::StencilBufferBits(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::StencilBufferBits(CHardwareConfig *this)
{
  if ( g_pShaderDevice != nullptr )
    return g_pShaderDevice->StencilBufferBits(this: g_pShaderDevice);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100035A0
// Name: public: virtual int CHardwareConfig::MaxViewports(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::MaxViewports(CHardwareConfig *this)
{
  return this->m_Caps.m_nMaxViewports;
}

//------------------------------------------------------------------------------
// Address: 0x100035B0
// Name: public: int CHardwareConfig::GetActualSamplerCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHardwareConfig::GetActualSamplerCount(CHardwareConfig *this)
{
  return this->m_ActualCaps.m_NumSamplers;
}

//------------------------------------------------------------------------------
// Address: 0x100035C0
// Name: public: virtual char const __near * CHardwareConfig::GetHWSpecificShaderDLLName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHardwareConfig::GetHWSpecificShaderDLLName(CHardwareConfig *this)
{
  char *result; // eax

  result = this->m_Caps.m_pShaderDLL;
  if ( this == (CHardwareConfig *)-1364 || *result == 0 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100035E0
// Name: public: virtual bool CHardwareConfig::SupportsShadowDepthTextures(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHardwareConfig::SupportsShadowDepthTextures(CHardwareConfig *this)
{
  return (*((_BYTE *)&this->m_Caps + 718) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100035F0
// Name: public: virtual enum ImageFormat CHardwareConfig::GetShadowDepthTextureFormat(void)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CHardwareConfig::GetShadowDepthTextureFormat(CHardwareConfig *this)
{
  return this->m_Caps.m_ShadowDepthTextureFormat;
}

//------------------------------------------------------------------------------
// Address: 0x10003600
// Name: public: virtual enum ImageFormat CHardwareConfig::GetNullTextureFormat(void)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CHardwareConfig::GetNullTextureFormat(CHardwareConfig *this)
{
  return this->m_Caps.m_NullTextureFormat;
}

//------------------------------------------------------------------------------
// Address: 0x10003610
// Name: protected: void CHardwareConfig::ForceCapsToDXLevel(struct HardwareCaps_t __near *,int,struct HardwareCaps_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::ForceCapsToDXLevel(
        CHardwareConfig *this,
        HardwareCaps_t *pCaps,
        int nDxLevel,
        const HardwareCaps_t *actualCaps)
{
  if ( nDxLevel <= 100 )
  {
    pCaps->m_nDXSupportLevel = nDxLevel;
    if ( nDxLevel == 90 )
    {
      *((_BYTE *)pCaps + 718) &= ~0x80u;
      *((_BYTE *)pCaps + 716) &= 0xB3u;
      pCaps->m_NumVertexSamplers = 0;
    }
    else
    {
      if ( nDxLevel != 92 )
      {
        if ( nDxLevel == 95 )
        {
          *((_BYTE *)pCaps + 719) &= ~1u;
          *((_BYTE *)pCaps + 718) &= ~0x80u;
          pCaps->m_MaxNumLights = 4;
          pCaps->m_nMaxViewports = 1;
        }
        return;
      }
      *((_BYTE *)pCaps + 716) &= 0xB7u;
      *((_BYTE *)pCaps + 718) &= ~0x80u;
      pCaps->m_NumVertexSamplers = 0;
      pCaps->m_nMaxVertexTextureDimension = 0;
      if ( r_emulategl.m_pParent->m_Value.m_nValue == 0 )
      {
        pCaps->m_MaxNumLights = 4;
LABEL_11:
        *((_BYTE *)pCaps + 719) &= ~1u;
        pCaps->m_MaxPixelShader30InstructionSlots = 0;
        pCaps->m_MaxVertexShader30InstructionSlots = 0;
        pCaps->m_nMaxVertexTextureDimension = 0;
        pCaps->m_NumPixelShaderConstants = 32;
        pCaps->m_nMaxViewports = 1;
        return;
      }
      *((_BYTE *)pCaps + 719) &= ~0x80u;
      *((_BYTE *)pCaps + 717) &= ~8u;
      pCaps->m_MaxUserClipPlanes = 2;
    }
    pCaps->m_MaxNumLights = 2;
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003710
// Name: public: void CHardwareConfig::SetupHardwareCaps(int,struct HardwareCaps_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHardwareConfig::SetupHardwareCaps(
        CHardwareConfig *this,
        int nDXLevel,
        const HardwareCaps_t *actualCaps)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf

  if ( nDXLevel < actualCaps->m_nMinDXSupportLevel )
    _Warning(
      a1: "Trying to set dxlevel (%d) which is lower than the card can support (%d)!\n",
      nDXLevel,
      actualCaps->m_nMinDXSupportLevel);
  if ( nDXLevel > actualCaps->m_nMaxDXSupportLevel )
    _Warning(
      a1: "Trying to set dxlevel (%d) which is higher than the card can support (%d)!\n",
      nDXLevel,
      actualCaps->m_nMaxDXSupportLevel);
  qmemcpy(&this->m_Caps, actualCaps, sizeof(this->m_Caps));
  qmemcpy(&this->m_UnOverriddenCaps, actualCaps, sizeof(this->m_UnOverriddenCaps));
  v4 = _CommandLine();
  v5 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v4 + 28))(a1: v4, a2: "-maxdxlevel", a3: nDXLevel);
  v6 = v5 == this->m_Caps.m_nMaxDXSupportLevel;
  this->m_Caps.m_nDXSupportLevel = v5;
  if ( !v6 )
    CHardwareConfig::ForceCapsToDXLevel(this, pCaps: &this->m_Caps, nDxLevel: v5, actualCaps: &this->m_ActualCaps);
}

} // namespace shaderapidx10
