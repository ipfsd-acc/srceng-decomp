// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/shadershadowdx8.cpp
// Functions: 34
// ============================================================

#include "materialsystem\shaderapidx9\shadershadowdx8.h"

//------------------------------------------------------------------------------
// Address: 0x10028C80
// Name: class IShaderShadowDX8 __near * ShaderShadow(void)
// Source: json
//------------------------------------------------------------------------------
CShaderShadowDX8 *__cdecl ShaderShadow()
{
  return &g_ShaderShadow;
}

//------------------------------------------------------------------------------
// Address: 0x10028C90
// Name: public: virtual void CShaderShadowDX8::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::Init(CShaderShadowDX8 *this)
{
  CShaderShadowDX8::SamplerState_t *m_SamplerState; // eax
  int i; // ecx

  this->m_pHardwareConfig = g_pHardwareConfig;
  *(_QWORD *)&this->m_ShadowState.m_DepthTestState.m_ZFunc = 0;
  *(_QWORD *)&this->m_ShadowState.m_FogAndMiscState.m_FogMode = 0;
  this->m_ShadowState.m_nAlphaBlendStateAsInt = 0;
  *(_QWORD *)&this->m_ShadowState.m_nFetch4Enable = 0;
  *((_BYTE *)&this->m_ShadowState.m_FogAndMiscState + 1) &= ~2u;
  this->m_ShadowShaderState.m_VertexShader = -1;
  this->m_ShadowShaderState.m_PixelShader = -1;
  this->m_ShadowShaderState.m_nStaticPshIndex = 0;
  this->m_ShadowShaderState.m_nStaticVshIndex = 0;
  this->m_ShadowShaderState.m_VertexUsage = 0;
  this->m_ShadowState.m_nFetch4Enable = 0;
  m_SamplerState = this->m_SamplerState;
  for ( i = 16; i != 0; --i )
    *(_BYTE *)m_SamplerState++ &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x10028CE0
// Name: public: virtual void CShaderShadowDX8::SetDefaultState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::SetDefaultState(CShaderShadowDX8 *this)
{
  Sampler_t v2; // edi
  int v3; // ebx

  this->DepthFunc(this, a2: SHADER_DEPTHFUNC_NEAREROREQUAL);
  this->EnableDepthWrites(this, a2: true);
  this->EnableDepthTest(this, a2: true);
  this->EnableColorWrites(this, a2: true);
  v2 = SHADER_SAMPLER0;
  this->EnableAlphaWrites(this, a2: false);
  this->EnableAlphaTest(this, a2: false);
  this->EnableBlending(this, a2: false);
  this->BlendFunc(this, a2: SHADER_BLEND_ZERO, a3: SHADER_BLEND_ZERO);
  this->BlendOp(this, a2: SHADER_BLEND_OP_ADD);
  this->EnableBlendingSeparateAlpha(this, a2: false);
  this->BlendFuncSeparateAlpha(this, a2: SHADER_BLEND_ZERO, a3: SHADER_BLEND_ZERO);
  this->BlendOpSeparateAlpha(this, a2: SHADER_BLEND_OP_ADD);
  ((void (__thiscall *)(CShaderShadowDX8 *, int, int))this->AlphaFunc)(a1: this, a2: 6, a3: 1060320051);
  this->PolyMode(this, a2: SHADER_POLYMODEFACE_FRONT_AND_BACK, a3: SHADER_POLYMODE_FILL);
  this->EnableCulling(this, a2: true);
  this->EnableAlphaToCoverage(this, a2: false);
  this->EnablePolyOffset(this, a2: SHADER_POLYOFFSET_DISABLE);
  this->EnableSRGBWrite(this, a2: false);
  this->SetVertexShader(this, a2: nullptr, a3: 0);
  this->SetPixelShader(this, a2: nullptr, a3: 0);
  this->FogMode(this, a2: SHADER_FOGMODE_DISABLED, a3: false);
  this->DisableFogGammaCorrection(this, a2: false);
  this->m_ShadowShaderState.m_VertexUsage = 0;
  v3 = g_pMaterialSystemHardwareConfig->GetSamplerCount(this: g_pMaterialSystemHardwareConfig);
  if ( v3 > 0 )
  {
    do
    {
      this->EnableTexture(this, a2: v2, a3: false);
      this->EnableSRGBRead(this, a2: v2++, a3: false);
    }
    while ( v2 < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028E20
// Name: public: virtual struct ShadowState_t const __near & CShaderShadowDX8::GetShadowState(void)
// Source: json
//------------------------------------------------------------------------------
const ShadowState_t *__thiscall CShaderShadowDX8::GetShadowState(CShaderShadowDX8 *this)
{
  return &this->m_ShadowState;
}

//------------------------------------------------------------------------------
// Address: 0x10028E30
// Name: public: virtual struct ShadowShaderState_t const __near & CShaderShadowDX8::GetShadowShaderState(void)
// Source: json
//------------------------------------------------------------------------------
const ShadowShaderState_t *__thiscall CShaderShadowDX8::GetShadowShaderState(CShaderShadowDX8 *this)
{
  return &this->m_ShadowShaderState;
}

//------------------------------------------------------------------------------
// Address: 0x10028E40
// Name: public: virtual void CShaderShadowDX8::DepthFunc(enum ShaderDepthFunc_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::DepthFunc(CShaderShadowDX8 *this, ShaderDepthFunc_t depthFunc)
{
  switch ( depthFunc )
  {
    case SHADER_DEPTHFUNC_NEVER:
      this->m_ShadowState.m_DepthTestState.m_ZFunc = 1;
      break;
    case SHADER_DEPTHFUNC_NEARER:
      this->m_ShadowState.m_DepthTestState.m_ZFunc = g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth
                                                   ? 5
                                                   : 2;
      break;
    case SHADER_DEPTHFUNC_EQUAL:
      this->m_ShadowState.m_DepthTestState.m_ZFunc = 3;
      break;
    case SHADER_DEPTHFUNC_NEAREROREQUAL:
      this->m_ShadowState.m_DepthTestState.m_ZFunc = g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth
                                                   ? 7
                                                   : 4;
      break;
    case SHADER_DEPTHFUNC_FARTHER:
      this->m_ShadowState.m_DepthTestState.m_ZFunc = g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth
                                                   ? 2
                                                   : 5;
      break;
    case SHADER_DEPTHFUNC_NOTEQUAL:
      this->m_ShadowState.m_DepthTestState.m_ZFunc = 6;
      break;
    case SHADER_DEPTHFUNC_FARTHEROREQUAL:
      this->m_ShadowState.m_DepthTestState.m_ZFunc = g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth
                                                   ? 4
                                                   : 7;
      break;
    case SHADER_DEPTHFUNC_ALWAYS:
      this->m_ShadowState.m_DepthTestState.m_ZFunc = 8;
      break;
    default:
      _Warning(a1: "DepthFunc: invalid param\n");
      this->m_ShadowState.m_DepthTestState.m_ZFunc = 8;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028F60
// Name: public: virtual void CShaderShadowDX8::EnableDepthWrites(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableDepthWrites(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState.m_DepthTestState + 3) ^= (bEnable
                                                          ^ *((_BYTE *)&this->m_ShadowState.m_DepthTestState + 3))
                                                         & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028F80
// Name: public: virtual void CShaderShadowDX8::EnableDepthTest(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableDepthTest(CShaderShadowDX8 *this, unsigned __int8 bEnable)
{
  this->m_ShadowState.m_DepthTestState.m_ZEnable = bEnable != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10028FA0
// Name: public: virtual void CShaderShadowDX8::EnablePolyOffset(enum PolygonOffsetMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnablePolyOffset(CShaderShadowDX8 *this, PolygonOffsetMode_t nOffsetMode)
{
  *((_BYTE *)&this->m_ShadowState.m_DepthTestState + 3) ^= (*((_BYTE *)&this->m_ShadowState.m_DepthTestState + 3)
                                                          ^ (2 * nOffsetMode))
                                                         & 6;
}

//------------------------------------------------------------------------------
// Address: 0x10028FC0
// Name: public: virtual void CShaderShadowDX8::EnableColorWrites(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableColorWrites(CShaderShadowDX8 *this, bool bEnable)
{
  if ( bEnable )
    this->m_ShadowState.m_DepthTestState.m_ColorWriteEnable |= 7u;
  else
    this->m_ShadowState.m_DepthTestState.m_ColorWriteEnable &= 0xF8u;
}

//------------------------------------------------------------------------------
// Address: 0x10028FE0
// Name: public: virtual void CShaderShadowDX8::EnableAlphaWrites(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableAlphaWrites(CShaderShadowDX8 *this, bool bEnable)
{
  if ( bEnable )
    this->m_ShadowState.m_DepthTestState.m_ColorWriteEnable |= 8u;
  else
    this->m_ShadowState.m_DepthTestState.m_ColorWriteEnable &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x10029000
// Name: public: virtual void CShaderShadowDX8::EnableBlending(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableBlending(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState.m_AlphaBlendState + 6) = bEnable
                                                         | *((_BYTE *)&this->m_ShadowState.m_AlphaBlendState + 6) & 0xFC;
}

//------------------------------------------------------------------------------
// Address: 0x10029020
// Name: public: virtual void CShaderShadowDX8::EnableBlendingForceOpaque(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableBlendingForceOpaque(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState.m_AlphaBlendState + 6) = bEnable
                                                         | *((_BYTE *)&this->m_ShadowState.m_AlphaBlendState + 6) & 0xFE
                                                         | 2;
}

//------------------------------------------------------------------------------
// Address: 0x10029040
// Name: public: virtual void CShaderShadowDX8::EnableBlendingSeparateAlpha(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableBlendingSeparateAlpha(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState.m_AlphaBlendState + 6) ^= (*((_BYTE *)&this->m_ShadowState.m_AlphaBlendState + 6)
                                                           ^ (4 * bEnable))
                                                          & 4;
}

//------------------------------------------------------------------------------
// Address: 0x10029060
// Name: public: virtual void CShaderShadowDX8::EnableAlphaTest(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableAlphaTest(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState.m_AlphaTestAndMiscState + 3) ^= (bEnable
                                                                 ^ *((_BYTE *)&this->m_ShadowState.m_AlphaTestAndMiscState
                                                                   + 3))
                                                                & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029080
// Name: public: virtual void CShaderShadowDX8::AlphaFunc(enum ShaderAlphaFunc_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::AlphaFunc(CShaderShadowDX8 *this, ShaderAlphaFunc_t alphaFunc, float alphaRef)
{
  _D3DCMPFUNC v3; // eax

  switch ( alphaFunc )
  {
    case SHADER_ALPHAFUNC_NEVER:
      v3 = D3DCMP_NEVER;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_LESS:
      v3 = D3DCMP_LESS;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_EQUAL:
      v3 = D3DCMP_EQUAL;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_LEQUAL:
      v3 = D3DCMP_LESSEQUAL;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_GREATER:
      v3 = D3DCMP_GREATER;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_NOTEQUAL:
      v3 = D3DCMP_NOTEQUAL;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_GEQUAL:
      v3 = D3DCMP_GREATEREQUAL;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_ALWAYS:
      v3 = D3DCMP_ALWAYS;
LABEL_10:
      this->m_AlphaFunc = v3;
      this->m_AlphaRef = (int)(float)(alphaRef * 255.0);
      break;
    default:
      _Warning(a1: "AlphaFunc: invalid param\n");
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029120
// Name: private: enum _D3DBLEND CShaderShadowDX8::BlendFuncValue(enum ShaderBlendFactor_t)const
// Source: json
//------------------------------------------------------------------------------
_D3DBLEND __thiscall CShaderShadowDX8::BlendFuncValue(CShaderShadowDX8 *this, ShaderBlendFactor_t factor)
{
  _D3DBLEND result; // eax

  switch ( factor )
  {
    case SHADER_BLEND_ZERO:
      result = D3DBLEND_ZERO;
      break;
    case SHADER_BLEND_ONE:
      goto $LN10_3;
    case SHADER_BLEND_DST_COLOR:
      result = D3DBLEND_DESTCOLOR;
      break;
    case SHADER_BLEND_ONE_MINUS_DST_COLOR:
      result = D3DBLEND_INVDESTCOLOR;
      break;
    case SHADER_BLEND_SRC_ALPHA:
      result = D3DBLEND_SRCALPHA;
      break;
    case SHADER_BLEND_ONE_MINUS_SRC_ALPHA:
      result = D3DBLEND_INVSRCALPHA;
      break;
    case SHADER_BLEND_DST_ALPHA:
      result = D3DBLEND_DESTALPHA;
      break;
    case SHADER_BLEND_ONE_MINUS_DST_ALPHA:
      result = D3DBLEND_INVDESTALPHA;
      break;
    case SHADER_BLEND_SRC_ALPHA_SATURATE:
      result = D3DBLEND_SRCALPHASAT;
      break;
    case SHADER_BLEND_SRC_COLOR:
      result = D3DBLEND_SRCCOLOR;
      break;
    case SHADER_BLEND_ONE_MINUS_SRC_COLOR:
      result = D3DBLEND_INVSRCCOLOR;
      break;
    default:
      _Warning(a1: "BlendFunc: invalid factor\n");
$LN10_3:
      result = D3DBLEND_ONE;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100291D0
// Name: public: virtual void CShaderShadowDX8::BlendFunc(enum ShaderBlendFactor_t,enum ShaderBlendFactor_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::BlendFunc(
        CShaderShadowDX8 *this,
        ShaderBlendFactor_t srcFactor,
        ShaderBlendFactor_t dstFactor)
{
  _D3DBLEND v4; // edi
  _D3DBLEND v5; // eax

  v4 = CShaderShadowDX8::BlendFuncValue(this, factor: srcFactor);
  v5 = CShaderShadowDX8::BlendFuncValue(this, factor: dstFactor);
  this->m_SrcBlend = v4;
  this->m_DestBlend = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10029200
// Name: public: virtual void CShaderShadowDX8::BlendFuncSeparateAlpha(enum ShaderBlendFactor_t,enum ShaderBlendFactor_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::BlendFuncSeparateAlpha(
        CShaderShadowDX8 *this,
        ShaderBlendFactor_t srcFactor,
        ShaderBlendFactor_t dstFactor)
{
  _D3DBLEND v4; // edi
  _D3DBLEND v5; // eax

  v4 = CShaderShadowDX8::BlendFuncValue(this, factor: srcFactor);
  v5 = CShaderShadowDX8::BlendFuncValue(this, factor: dstFactor);
  this->m_SrcBlendAlpha = v4;
  this->m_DestBlendAlpha = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10029230
// Name: public: virtual void CShaderShadowDX8::BlendOp(enum ShaderBlendOp_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::BlendOp(CShaderShadowDX8 *this, ShaderBlendOp_t blendOp)
{
  switch ( blendOp )
  {
    case SHADER_BLEND_OP_ADD:
      goto $LN7_8;
    case SHADER_BLEND_OP_SUBTRACT:
      this->m_BlendOp = D3DBLENDOP_SUBTRACT;
      break;
    case SHADER_BLEND_OP_REVSUBTRACT:
      this->m_BlendOp = D3DBLENDOP_REVSUBTRACT;
      break;
    case SHADER_BLEND_OP_MIN:
      this->m_BlendOp = D3DBLENDOP_MIN;
      break;
    case SHADER_BLEND_OP_MAX:
      this->m_BlendOp = D3DBLENDOP_MAX;
      break;
    default:
      _Warning(a1: "BlendOp: invalid op\n");
$LN7_8:
      this->m_BlendOp = D3DBLENDOP_ADD;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100292B0
// Name: public: virtual void CShaderShadowDX8::BlendOpSeparateAlpha(enum ShaderBlendOp_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::BlendOpSeparateAlpha(CShaderShadowDX8 *this, ShaderBlendOp_t blendOp)
{
  switch ( blendOp )
  {
    case SHADER_BLEND_OP_ADD:
      goto $LN7_9;
    case SHADER_BLEND_OP_SUBTRACT:
      this->m_BlendOpAlpha = D3DBLENDOP_SUBTRACT;
      break;
    case SHADER_BLEND_OP_REVSUBTRACT:
      this->m_BlendOpAlpha = D3DBLENDOP_REVSUBTRACT;
      break;
    case SHADER_BLEND_OP_MIN:
      this->m_BlendOpAlpha = D3DBLENDOP_MIN;
      break;
    case SHADER_BLEND_OP_MAX:
      this->m_BlendOpAlpha = D3DBLENDOP_MAX;
      break;
    default:
      _Warning(a1: "BlendOp: invalid op\n");
$LN7_9:
      this->m_BlendOpAlpha = D3DBLENDOP_ADD;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029330
// Name: public: virtual void CShaderShadowDX8::PolyMode(enum ShaderPolyModeFace_t,enum ShaderPolyMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::PolyMode(
        CShaderShadowDX8 *this,
        ShaderPolyModeFace_t face,
        ShaderPolyMode_t polyMode)
{
  if ( face != SHADER_POLYMODEFACE_BACK )
  {
    if ( polyMode != SHADER_POLYMODE_POINT )
    {
      if ( polyMode == SHADER_POLYMODE_LINE )
      {
        this->m_ShadowState.m_AlphaTestAndMiscState.m_FillMode = 2;
      }
      else if ( polyMode == SHADER_POLYMODE_FILL )
      {
        this->m_ShadowState.m_AlphaTestAndMiscState.m_FillMode = 3;
      }
      else
      {
        _Warning(a1: "PolyMode: invalid poly mode\n");
      }
    }
    else
    {
      this->m_ShadowState.m_AlphaTestAndMiscState.m_FillMode = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029380
// Name: public: virtual void CShaderShadowDX8::EnableCulling(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableCulling(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState.m_AlphaTestAndMiscState + 3) ^= (*((_BYTE *)&this->m_ShadowState.m_AlphaTestAndMiscState
                                                                   + 3)
                                                                 ^ (4 * bEnable))
                                                                & 4;
}

//------------------------------------------------------------------------------
// Address: 0x100293A0
// Name: public: virtual void CShaderShadowDX8::EnableAlphaToCoverage(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableAlphaToCoverage(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState.m_AlphaTestAndMiscState + 3) ^= (*((_BYTE *)&this->m_ShadowState.m_AlphaTestAndMiscState
                                                                   + 3)
                                                                 ^ (2 * bEnable))
                                                                & 2;
}

//------------------------------------------------------------------------------
// Address: 0x100293C0
// Name: public: virtual void CShaderShadowDX8::EnableSRGBWrite(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableSRGBWrite(CShaderShadowDX8 *this, bool bEnable)
{
  if ( this->m_pHardwareConfig->SupportsSRGB(this: this->m_pHardwareConfig) )
    *((_BYTE *)&this->m_ShadowState.m_FogAndMiscState + 1) ^= (*((_BYTE *)&this->m_ShadowState.m_FogAndMiscState + 1)
                                                             ^ (4 * bEnable))
                                                            & 4;
  else
    *((_BYTE *)&this->m_ShadowState.m_FogAndMiscState + 1) &= ~4u;
}

//------------------------------------------------------------------------------
// Address: 0x10029400
// Name: public: virtual void CShaderShadowDX8::EnableTexture(enum Sampler_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableTexture(CShaderShadowDX8 *this, Sampler_t sampler, bool bEnable)
{
  if ( sampler >= this->m_pHardwareConfig->GetSamplerCount(this: this->m_pHardwareConfig) )
    _Warning(a1: "Attempting to bind a texture to an invalid sampler (%d)!\n", sampler);
  else
    *(_BYTE *)&this->m_SamplerState[sampler] ^= (bEnable ^ *(_BYTE *)&this->m_SamplerState[sampler]) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029440
// Name: public: virtual void CShaderShadowDX8::EnableVertexTexture(enum VertexTextureSampler_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableVertexTexture(
        CShaderShadowDX8 *this,
        VertexTextureSampler_t vtSampler,
        bool bEnable)
{
  if ( vtSampler >= this->m_pHardwareConfig->GetVertexSamplerCount(this: this->m_pHardwareConfig) )
    _Warning(a1: "Attempting to bind a texture to an invalid vertex sampler (%d)!\n", vtSampler);
  else
    *(_BYTE *)&this->m_VertexSamplerState[vtSampler] ^= (bEnable ^ *(_BYTE *)&this->m_VertexSamplerState[vtSampler]) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029480
// Name: public: virtual void CShaderShadowDX8::VertexShaderVertexFormat(unsigned int,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::VertexShaderVertexFormat(
        CShaderShadowDX8 *this,
        unsigned int nFlags,
        int nTexCoordCount,
        int *pTexCoordDimensions,
        int nUserDataSize)
{
  CMeshMgr *v6; // eax
  unsigned __int64 v7; // rax
  CMeshMgr *v8; // eax

  v6 = MeshMgr();
  v7 = v6->ComputeVertexFormat(
         this: v6,
         a2: nFlags & 0xFFFFFF7F,
         a3: nTexCoordCount,
         a4: pTexCoordDimensions,
         a5: 0,
         a6: nUserDataSize);
  this->m_ShadowShaderState.m_VertexUsage = v7;
  if ( (int)CVertexBufferBase::VertexFormatSize(vertexFormat: v7) <= 16 )
  {
    if ( !bComplained )
    {
      _Warning(
        a1: "ERROR: shader asking for a too-narrow vertex format - you will see errors if running with debug D3D DLLs!\n"
        "\tPadding the vertex format with extra texcoords\n"
        "\tWill not warn again.\n");
      bComplained = true;
    }
    v8 = MeshMgr();
    this->m_ShadowShaderState.m_VertexUsage = v8->ComputeVertexFormat(
                                                this: v8,
                                                a2: nFlags & 0xFFFFFF7E | 1,
                                                a3: 1,
                                                a4: nullptr,
                                                a5: 0,
                                                a6: nUserDataSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029510
// Name: public: virtual void CShaderShadowDX8::SetVertexShader(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::SetVertexShader(CShaderShadowDX8 *this, const char *pFileName, int nStaticVshIndex)
{
  int v4; // eax
  char debugLabel[500]; // [esp+Ch] [ebp-1F4h] BYREF

  V_snprintf(pDest: debugLabel, maxLen: 500, pFormat: "vs-file %s vs-index %d", pFileName, nStaticVshIndex);
  v4 = g_pShaderManager->CreateVertexShader(this: g_pShaderManager, a2: pFileName, a3: nStaticVshIndex, a4: debugLabel);
  this->m_ShadowShaderState.m_nStaticVshIndex = nStaticVshIndex;
  this->m_ShadowShaderState.m_VertexShader = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10029570
// Name: public: virtual void CShaderShadowDX8::SetPixelShader(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::SetPixelShader(CShaderShadowDX8 *this, const char *pFileName, int nStaticPshIndex)
{
  int v4; // eax
  char debugLabel[500]; // [esp+Ch] [ebp-1F4h] BYREF

  V_snprintf(pDest: debugLabel, maxLen: 500, pFormat: "ps-file %s ps-index %d", pFileName, nStaticPshIndex);
  v4 = g_pShaderManager->CreatePixelShader(this: g_pShaderManager, a2: pFileName, a3: nStaticPshIndex, a4: debugLabel);
  this->m_ShadowShaderState.m_nStaticPshIndex = nStaticPshIndex;
  this->m_ShadowShaderState.m_PixelShader = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100295D0
// Name: public: virtual float CShaderShadowDX8::GetLightMapScaleFactor(void)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CShaderShadowDX8::GetLightMapScaleFactor(CShaderShadowDX8 *this)
{
  return g_pHardwareConfig->GetLightMapScaleFactor(this: g_pHardwareConfig);
}

//------------------------------------------------------------------------------
// Address: 0x100295E0
// Name: public: virtual void CShaderShadowDX8::FogMode(enum ShaderFogMode_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::FogMode(CShaderShadowDX8 *this, ShaderFogMode_t fogMode, bool bVertexFog)
{
  *((_BYTE *)&this->m_ShadowState.m_FogAndMiscState + 1) ^= (bVertexFog
                                                           ^ *((_BYTE *)&this->m_ShadowState.m_FogAndMiscState + 1))
                                                          & 1;
  this->m_ShadowState.m_FogAndMiscState.m_FogMode = fogMode;
}

//------------------------------------------------------------------------------
// Address: 0x10029600
// Name: public: virtual void CShaderShadowDX8::DisableFogGammaCorrection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::DisableFogGammaCorrection(CShaderShadowDX8 *this, bool bDisable)
{
  *((_BYTE *)&this->m_ShadowState.m_FogAndMiscState + 1) ^= (*((_BYTE *)&this->m_ShadowState.m_FogAndMiscState + 1)
                                                           ^ (2 * bDisable))
                                                          & 2;
}

//------------------------------------------------------------------------------
// Address: 0x10029620
// Name: public: virtual void CShaderShadowDX8::ComputeAggregateShadowState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::ComputeAggregateShadowState(CShaderShadowDX8 *this)
{
  int i; // edi
  char v3; // al
  char v4; // cl
  unsigned __int8 m_DestBlendAlpha; // dl
  unsigned __int8 m_BlendOpAlpha; // al
  char m_nAlphaTestAndMiscStateAsInt_high; // al

  for ( i = 0; i < this->m_pHardwareConfig->GetSamplerCount(this: this->m_pHardwareConfig); ++i )
    ;
  v3 = BYTE6(this->m_ShadowState.m_nAlphaBlendStateAsInt);
  v4 = v3 & 1;
  if ( (v3 & 1) != 0 )
  {
    this->m_ShadowState.m_AlphaBlendState.m_SrcBlend = this->m_SrcBlend;
    this->m_ShadowState.m_AlphaBlendState.m_DestBlend = this->m_DestBlend;
    this->m_ShadowState.m_AlphaBlendState.m_BlendOp = this->m_BlendOp;
  }
  else
  {
    *(_WORD *)&this->m_ShadowState.m_AlphaBlendState.m_SrcBlend = 258;
    this->m_ShadowState.m_AlphaBlendState.m_BlendOp = 1;
  }
  if ( (v3 & 4) != 0 )
  {
    m_DestBlendAlpha = this->m_DestBlendAlpha;
    this->m_ShadowState.m_AlphaBlendState.m_SrcBlendAlpha = this->m_SrcBlendAlpha;
    m_BlendOpAlpha = this->m_BlendOpAlpha;
    this->m_ShadowState.m_AlphaBlendState.m_DestBlendAlpha = m_DestBlendAlpha;
    this->m_ShadowState.m_AlphaBlendState.m_BlendOpAlpha = m_BlendOpAlpha;
  }
  else
  {
    *(_WORD *)((char *)&this->m_ShadowState.m_nAlphaBlendStateAsInt + 3) = 258;
    this->m_ShadowState.m_AlphaBlendState.m_BlendOpAlpha = 1;
  }
  m_nAlphaTestAndMiscStateAsInt_high = HIBYTE(this->m_ShadowState.m_nAlphaTestAndMiscStateAsInt);
  if ( (m_nAlphaTestAndMiscStateAsInt_high & 1) != 0 )
  {
    this->m_ShadowState.m_AlphaTestAndMiscState.m_AlphaFunc = this->m_AlphaFunc;
    this->m_ShadowState.m_AlphaTestAndMiscState.m_AlphaRef = this->m_AlphaRef;
  }
  else
  {
    *(_WORD *)&this->m_ShadowState.m_AlphaTestAndMiscState.m_AlphaFunc = 7;
    if ( v4 != 0
      && this->m_ShadowState.m_AlphaBlendState.m_SrcBlend == 5
      && this->m_ShadowState.m_AlphaBlendState.m_DestBlend == 6 )
    {
      this->m_ShadowState.m_AlphaTestAndMiscState.m_AlphaFunc = 7;
      this->m_ShadowState.m_AlphaTestAndMiscState.m_AlphaRef = 1;
    }
  }
  if ( (m_nAlphaTestAndMiscStateAsInt_high & 2) != 0 && (v4 == 1 || (m_nAlphaTestAndMiscStateAsInt_high & 1) == 0) )
    *((_BYTE *)&this->m_ShadowState.m_AlphaTestAndMiscState + 3) = m_nAlphaTestAndMiscStateAsInt_high & 0xFD;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x1002F350
// Name: class IShaderShadowDX8 __near * ShaderShadow(void)
// Source: json
//------------------------------------------------------------------------------
CShaderShadowDX8 *__cdecl ShaderShadow()
{
  return &g_ShaderShadow;
}

//------------------------------------------------------------------------------
// Address: 0x1002F360
// Name: public: virtual void CShaderShadowDX8::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::Init(CShaderShadowDX8 *this)
{
  int v2; // ecx
  CShaderShadowDX8::SamplerState_t *m_SamplerState; // eax

  this->m_pHardwareConfig = g_pMaterialSystemHardwareConfig;
  memset(dst: (unsigned __int8 *)&this->m_ShadowState, value: 0, count: sizeof(this->m_ShadowState));
  *((_BYTE *)&this->m_ShadowState + 69) &= ~4u;
  this->m_ShadowShaderState.m_nStaticPshIndex = 0;
  this->m_ShadowShaderState.m_nStaticVshIndex = 0;
  this->m_ShadowShaderState.m_VertexUsage = 0;
  this->m_ShadowShaderState.m_VertexShader = -1;
  this->m_ShadowShaderState.m_PixelShader = -1;
  v2 = 16;
  m_SamplerState = this->m_SamplerState;
  do
  {
    *(_BYTE *)&m_SamplerState[-48] &= 0xF8u;
    *(_BYTE *)m_SamplerState++ &= ~1u;
    --v2;
  }
  while ( v2 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1002F3C0
// Name: public: virtual void CShaderShadowDX8::SetDefaultState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::SetDefaultState(CShaderShadowDX8 *this)
{
  int v2; // ebx
  Sampler_t i; // edi

  this->DepthFunc(this, a2: SHADER_DEPTHFUNC_NEAREROREQUAL);
  this->EnableDepthWrites(this, a2: true);
  this->EnableDepthTest(this, a2: true);
  this->EnableColorWrites_2(this, a2: true);
  this->EnableAlphaWrites(this, a2: false);
  this->EnableAlphaTest(this, a2: false);
  this->EnableBlending(this, a2: false);
  this->BlendFunc(this, a2: SHADER_BLEND_ZERO, a3: SHADER_BLEND_ZERO);
  this->BlendOp(this, a2: SHADER_BLEND_OP_ADD);
  this->EnableBlendingSeparateAlpha(this, a2: false);
  this->BlendFuncSeparateAlpha(this, a2: SHADER_BLEND_ZERO, a3: SHADER_BLEND_ZERO);
  this->BlendOpSeparateAlpha(this, a2: SHADER_BLEND_OP_ADD);
  ((void (__thiscall *)(CShaderShadowDX8 *, int, _DWORD))this->AlphaFunc)(a1: this, a2: 6, a3: 0.69999999);
  this->PolyMode(this, a2: SHADER_POLYMODEFACE_FRONT_AND_BACK, a3: SHADER_POLYMODE_FILL);
  this->EnableCulling(this, a2: true);
  this->EnableAlphaToCoverage(this, a2: false);
  this->EnablePolyOffset(this, a2: SHADER_POLYOFFSET_DISABLE);
  this->EnableSRGBWrite(this, a2: false);
  this->SetVertexShader(this, a2: nullptr, a3: 0);
  this->SetPixelShader(this, a2: nullptr, a3: 0);
  this->FogMode(this, a2: SHADER_FOGMODE_DISABLED, a3: false);
  this->DisableFogGammaCorrection(this, a2: false);
  this->m_ShadowShaderState.m_VertexUsage = 0;
  v2 = g_pMaterialSystemHardwareConfig->GetSamplerCount(this: g_pMaterialSystemHardwareConfig);
  for ( i = SHADER_SAMPLER0; i < v2; ++i )
  {
    this->EnableTexture(this, a2: i, a3: false);
    this->EnableSRGBRead(this, a2: i, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F520
// Name: public: virtual struct ShadowState_t const __near & CShaderShadowDX8::GetShadowState(void)
// Source: json
//------------------------------------------------------------------------------
const ShadowState_t *__thiscall CShaderShadowDX8::GetShadowState(CShaderShadowDX8 *this)
{
  return &this->m_ShadowState;
}

//------------------------------------------------------------------------------
// Address: 0x1002F530
// Name: public: virtual struct ShadowShaderState_t const __near & CShaderShadowDX8::GetShadowShaderState(void)
// Source: json
//------------------------------------------------------------------------------
const ShadowShaderState_t *__thiscall CShaderShadowDX8::GetShadowShaderState(CShaderShadowDX8 *this)
{
  return &this->m_ShadowShaderState;
}

//------------------------------------------------------------------------------
// Address: 0x1002F540
// Name: public: virtual void CShaderShadowDX8::DepthFunc(enum ShaderDepthFunc_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::DepthFunc(CShaderShadowDX8 *this, ShaderDepthFunc_t depthFunc)
{
  switch ( depthFunc )
  {
    case SHADER_DEPTHFUNC_NEVER:
      this->m_ShadowState.m_ZFunc = D3DCMP_NEVER;
      break;
    case SHADER_DEPTHFUNC_NEARER:
      this->m_ShadowState.m_ZFunc = g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth
                                  ? D3DCMP_GREATER
                                  : D3DCMP_LESS;
      break;
    case SHADER_DEPTHFUNC_EQUAL:
      this->m_ShadowState.m_ZFunc = D3DCMP_EQUAL;
      break;
    case SHADER_DEPTHFUNC_NEAREROREQUAL:
      this->m_ShadowState.m_ZFunc = g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth
                                  ? D3DCMP_GREATEREQUAL
                                  : D3DCMP_LESSEQUAL;
      break;
    case SHADER_DEPTHFUNC_FARTHER:
      this->m_ShadowState.m_ZFunc = g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth
                                  ? D3DCMP_LESS
                                  : D3DCMP_GREATER;
      break;
    case SHADER_DEPTHFUNC_NOTEQUAL:
      this->m_ShadowState.m_ZFunc = D3DCMP_NOTEQUAL;
      break;
    case SHADER_DEPTHFUNC_FARTHEROREQUAL:
      this->m_ShadowState.m_ZFunc = g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth
                                  ? D3DCMP_LESSEQUAL
                                  : D3DCMP_GREATEREQUAL;
      break;
    case SHADER_DEPTHFUNC_ALWAYS:
      this->m_ShadowState.m_ZFunc = D3DCMP_ALWAYS;
      break;
    default:
      _Warning(a1: "DepthFunc: invalid param\n");
      this->m_ShadowState.m_ZFunc = D3DCMP_ALWAYS;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F660
// Name: public: virtual void CShaderShadowDX8::EnableDepthWrites(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableDepthWrites(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState + 68) ^= (*((_BYTE *)&this->m_ShadowState + 68) ^ (2 * bEnable)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x1002F680
// Name: public: virtual void CShaderShadowDX8::EnableDepthTest(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableDepthTest(CShaderShadowDX8 *this, bool bEnable)
{
  this->m_ShadowState.m_ZEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1002F690
// Name: public: virtual void CShaderShadowDX8::EnablePolyOffset(enum PolygonOffsetMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnablePolyOffset(CShaderShadowDX8 *this, PolygonOffsetMode_t nOffsetMode)
{
  *((_BYTE *)&this->m_ShadowState + 68) ^= (*((_BYTE *)&this->m_ShadowState + 68) ^ (4 * nOffsetMode)) & 0xC;
}

//------------------------------------------------------------------------------
// Address: 0x1002F6B0
// Name: public: virtual void CShaderShadowDX8::EnableColorWrites(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableColorWrites(CShaderShadowDX8 *this, bool bEnable)
{
  if ( bEnable )
    this->m_ShadowState.m_ColorWriteEnable |= 7u;
  else
    this->m_ShadowState.m_ColorWriteEnable &= 0xFFFFFFF8;
}

//------------------------------------------------------------------------------
// Address: 0x1002F6D0
// Name: public: virtual void CShaderShadowDX8::EnableColorWrites(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableColorWrites(
        CShaderShadowDX8 *this,
        bool bRedEnable,
        bool bGreenEnable,
        bool bBlueEnable)
{
  this->m_ShadowState.m_ColorWriteEnable &= 0xFFFFFFF8;
  if ( bRedEnable )
    this->m_ShadowState.m_ColorWriteEnable |= 1u;
  if ( bGreenEnable )
    this->m_ShadowState.m_ColorWriteEnable |= 2u;
  if ( bBlueEnable )
    this->m_ShadowState.m_ColorWriteEnable |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x1002F700
// Name: public: virtual void CShaderShadowDX8::EnableAlphaWrites(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableAlphaWrites(CShaderShadowDX8 *this, bool bEnable)
{
  if ( bEnable )
    this->m_ShadowState.m_ColorWriteEnable |= 8u;
  else
    this->m_ShadowState.m_ColorWriteEnable &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x1002F720
// Name: public: virtual void CShaderShadowDX8::EnableBlending(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableBlending(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState + 68) ^= (*((_BYTE *)&this->m_ShadowState + 68) ^ (32 * bEnable)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x1002F740
// Name: public: virtual void CShaderShadowDX8::EnableBlendingSeparateAlpha(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableBlendingSeparateAlpha(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState + 69) ^= (bEnable ^ *((_BYTE *)&this->m_ShadowState + 69)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F750
// Name: public: virtual void CShaderShadowDX8::EnableAlphaTest(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableAlphaTest(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState + 68) ^= (*((_BYTE *)&this->m_ShadowState + 68) ^ (bEnable << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x1002F770
// Name: public: virtual void CShaderShadowDX8::AlphaFunc(enum ShaderAlphaFunc_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::AlphaFunc(CShaderShadowDX8 *this, ShaderAlphaFunc_t alphaFunc, float alphaRef)
{
  _D3DCMPFUNC v3; // eax

  switch ( alphaFunc )
  {
    case SHADER_ALPHAFUNC_NEVER:
      v3 = D3DCMP_NEVER;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_LESS:
      v3 = D3DCMP_LESS;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_EQUAL:
      v3 = D3DCMP_EQUAL;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_LEQUAL:
      v3 = D3DCMP_LESSEQUAL;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_GREATER:
      v3 = D3DCMP_GREATER;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_NOTEQUAL:
      v3 = D3DCMP_NOTEQUAL;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_GEQUAL:
      v3 = D3DCMP_GREATEREQUAL;
      goto LABEL_10;
    case SHADER_ALPHAFUNC_ALWAYS:
      v3 = D3DCMP_ALWAYS;
LABEL_10:
      this->m_AlphaFunc = v3;
      this->m_AlphaRef = (int)(float)(alphaRef * 255.0);
      break;
    default:
      _Warning(a1: "AlphaFunc: invalid param\n");
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F800
// Name: private: enum _D3DBLEND CShaderShadowDX8::BlendFuncValue(enum ShaderBlendFactor_t)const
// Source: json
//------------------------------------------------------------------------------
_D3DBLEND __thiscall CShaderShadowDX8::BlendFuncValue(CShaderShadowDX8 *this, ShaderBlendFactor_t factor)
{
  _D3DBLEND result; // eax

  switch ( factor )
  {
    case SHADER_BLEND_ZERO:
      result = D3DBLEND_ZERO;
      break;
    case SHADER_BLEND_ONE:
      goto $LN10_2;
    case SHADER_BLEND_DST_COLOR:
      result = D3DBLEND_DESTCOLOR;
      break;
    case SHADER_BLEND_ONE_MINUS_DST_COLOR:
      result = D3DBLEND_INVDESTCOLOR;
      break;
    case SHADER_BLEND_SRC_ALPHA:
      result = D3DBLEND_SRCALPHA;
      break;
    case SHADER_BLEND_ONE_MINUS_SRC_ALPHA:
      result = D3DBLEND_INVSRCALPHA;
      break;
    case SHADER_BLEND_DST_ALPHA:
      result = D3DBLEND_DESTALPHA;
      break;
    case SHADER_BLEND_ONE_MINUS_DST_ALPHA:
      result = D3DBLEND_INVDESTALPHA;
      break;
    case SHADER_BLEND_SRC_ALPHA_SATURATE:
      result = D3DBLEND_SRCALPHASAT;
      break;
    case SHADER_BLEND_SRC_COLOR:
      result = D3DBLEND_SRCCOLOR;
      break;
    case SHADER_BLEND_ONE_MINUS_SRC_COLOR:
      result = D3DBLEND_INVSRCCOLOR;
      break;
    default:
      _Warning(a1: "BlendFunc: invalid factor\n");
$LN10_2:
      result = D3DBLEND_ONE;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002F8B0
// Name: private: enum _D3DBLENDOP CShaderShadowDX8::BlendOpValue(enum ShaderBlendOp_t)const
// Source: json
//------------------------------------------------------------------------------
_D3DBLENDOP __thiscall CShaderShadowDX8::BlendOpValue(CShaderShadowDX8 *this, ShaderBlendOp_t blendOp)
{
  _D3DBLENDOP result; // eax

  switch ( blendOp )
  {
    case SHADER_BLEND_OP_ADD:
      goto $LN5_14;
    case SHADER_BLEND_OP_SUBTRACT:
      result = D3DBLENDOP_SUBTRACT;
      break;
    case SHADER_BLEND_OP_REVSUBTRACT:
      result = D3DBLENDOP_REVSUBTRACT;
      break;
    case SHADER_BLEND_OP_MIN:
      result = D3DBLENDOP_MIN;
      break;
    case SHADER_BLEND_OP_MAX:
      result = D3DBLENDOP_MAX;
      break;
    default:
      _Warning(a1: "BlendOp: invalid op\n");
$LN5_14:
      result = D3DBLENDOP_ADD;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002F910
// Name: public: virtual void CShaderShadowDX8::BlendFunc(enum ShaderBlendFactor_t,enum ShaderBlendFactor_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::BlendFunc(
        CShaderShadowDX8 *this,
        ShaderBlendFactor_t srcFactor,
        ShaderBlendFactor_t dstFactor)
{
  _D3DBLEND v4; // edi
  _D3DBLEND v5; // eax

  v4 = CShaderShadowDX8::BlendFuncValue(this, factor: srcFactor);
  v5 = CShaderShadowDX8::BlendFuncValue(this, factor: dstFactor);
  this->m_SrcBlend = v4;
  this->m_DestBlend = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002F940
// Name: public: virtual void CShaderShadowDX8::BlendFuncSeparateAlpha(enum ShaderBlendFactor_t,enum ShaderBlendFactor_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::BlendFuncSeparateAlpha(
        CShaderShadowDX8 *this,
        ShaderBlendFactor_t srcFactor,
        ShaderBlendFactor_t dstFactor)
{
  _D3DBLEND v4; // edi
  _D3DBLEND v5; // eax

  v4 = CShaderShadowDX8::BlendFuncValue(this, factor: srcFactor);
  v5 = CShaderShadowDX8::BlendFuncValue(this, factor: dstFactor);
  this->m_SrcBlendAlpha = v4;
  this->m_DestBlendAlpha = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002F970
// Name: public: virtual void CShaderShadowDX8::BlendOp(enum ShaderBlendOp_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::BlendOp(CShaderShadowDX8 *this, ShaderBlendOp_t blendOp)
{
  this->m_BlendOp = CShaderShadowDX8::BlendOpValue(this, blendOp);
}

//------------------------------------------------------------------------------
// Address: 0x1002F990
// Name: public: virtual void CShaderShadowDX8::BlendOpSeparateAlpha(enum ShaderBlendOp_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::BlendOpSeparateAlpha(CShaderShadowDX8 *this, ShaderBlendOp_t blendOp)
{
  this->m_BlendOpAlpha = CShaderShadowDX8::BlendOpValue(this, blendOp);
}

//------------------------------------------------------------------------------
// Address: 0x1002F9B0
// Name: public: virtual void CShaderShadowDX8::PolyMode(enum ShaderPolyModeFace_t,enum ShaderPolyMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::PolyMode(
        CShaderShadowDX8 *this,
        ShaderPolyModeFace_t face,
        ShaderPolyMode_t polyMode)
{
  if ( face != SHADER_POLYMODEFACE_BACK )
  {
    if ( polyMode != SHADER_POLYMODE_POINT )
    {
      if ( polyMode == SHADER_POLYMODE_LINE )
      {
        this->m_ShadowState.m_FillMode = D3DFILL_WIREFRAME;
      }
      else if ( polyMode == SHADER_POLYMODE_FILL )
      {
        this->m_ShadowState.m_FillMode = D3DFILL_SOLID;
      }
      else
      {
        _Warning(a1: "PolyMode: invalid poly mode\n");
      }
    }
    else
    {
      this->m_ShadowState.m_FillMode = D3DFILL_POINT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FA00
// Name: public: virtual void CShaderShadowDX8::EnableCulling(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableCulling(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState + 68) ^= (*((_BYTE *)&this->m_ShadowState + 68) ^ (16 * bEnable)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA20
// Name: public: virtual void CShaderShadowDX8::EnableAlphaToCoverage(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableAlphaToCoverage(CShaderShadowDX8 *this, bool bEnable)
{
  *((_BYTE *)&this->m_ShadowState + 69) ^= (*((_BYTE *)&this->m_ShadowState + 69) ^ (8 * bEnable)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA40
// Name: public: virtual void CShaderShadowDX8::EnableSRGBWrite(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableSRGBWrite(CShaderShadowDX8 *this, bool bEnable)
{
  if ( this->m_pHardwareConfig->SupportsSRGB(this: this->m_pHardwareConfig) )
    *((_BYTE *)&this->m_ShadowState + 68) = (bEnable << 7) | *((_BYTE *)&this->m_ShadowState + 68) & 0x7F;
  else
    *((_BYTE *)&this->m_ShadowState + 68) &= ~0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA70
// Name: public: virtual void CShaderShadowDX8::EnableTexture(enum Sampler_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableTexture(CShaderShadowDX8 *this, Sampler_t sampler, bool bEnable)
{
  if ( sampler >= this->m_pHardwareConfig->GetSamplerCount(this: this->m_pHardwareConfig) )
    _Warning(a1: "Attempting to bind a texture to an invalid sampler (%d)!\n", sampler);
  else
    *(_BYTE *)&this->m_SamplerState[sampler] ^= (bEnable ^ *(_BYTE *)&this->m_SamplerState[sampler]) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002FAB0
// Name: public: virtual void CShaderShadowDX8::EnableVertexTexture(enum VertexTextureSampler_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableVertexTexture(
        CShaderShadowDX8 *this,
        VertexTextureSampler_t vtSampler,
        bool bEnable)
{
  if ( vtSampler >= this->m_pHardwareConfig->GetVertexSamplerCount(this: this->m_pHardwareConfig) )
    _Warning(a1: "Attempting to bind a texture to an invalid vertex sampler (%d)!\n", vtSampler);
  else
    *(_BYTE *)&this->m_VertexSamplerState[vtSampler] ^= (bEnable ^ *(_BYTE *)&this->m_VertexSamplerState[vtSampler]) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002FAF0
// Name: public: virtual void CShaderShadowDX8::EnableSRGBRead(enum Sampler_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::EnableSRGBRead(CShaderShadowDX8 *this, Sampler_t sampler, bool bEnable)
{
  if ( this->m_pHardwareConfig->SupportsSRGB(this: this->m_pHardwareConfig) )
  {
    if ( sampler >= this->m_pHardwareConfig->GetSamplerCount(this: this->m_pHardwareConfig) )
      _Warning(a1: "Attempting set SRGBRead state on an invalid sampler (%d)!\n", sampler);
    else
      *(_BYTE *)&this->m_ShadowState.m_SamplerState[sampler] ^= (*(_BYTE *)&this->m_ShadowState.m_SamplerState[sampler]
                                                               ^ (2 * bEnable))
                                                              & 2;
  }
  else
  {
    *(_BYTE *)&this->m_ShadowState.m_SamplerState[sampler] &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FB50
// Name: public: virtual void CShaderShadowDX8::SetShadowDepthFiltering(enum Sampler_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::SetShadowDepthFiltering(CShaderShadowDX8 *this, Sampler_t stage)
{
  if ( this->m_pHardwareConfig->SupportsFetch4(this: this->m_pHardwareConfig) )
  {
    if ( stage >= this->m_pHardwareConfig->GetSamplerCount(this: this->m_pHardwareConfig) )
      _Warning(a1: "Attempting set shadow filtering state on an invalid sampler (%d)!\n", stage);
    else
      *(_BYTE *)&this->m_ShadowState.m_SamplerState[stage] |= 4u;
  }
  else
  {
    *(_BYTE *)&this->m_ShadowState.m_SamplerState[stage] &= ~4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FBA0
// Name: public: virtual void CShaderShadowDX8::VertexShaderVertexFormat(unsigned int,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::VertexShaderVertexFormat(
        CShaderShadowDX8 *this,
        unsigned int nFlags,
        int nTexCoordCount,
        int *pTexCoordDimensions,
        int nUserDataSize)
{
  CMeshMgr *v6; // eax
  __int64 v7; // rax
  CMeshMgr *v8; // eax
  unsigned __int64 v9; // [esp-8h] [ebp-14h]

  v6 = MeshMgr();
  v7 = v6->ComputeVertexFormat(
         this: v6,
         a2: nFlags & 0xFFFFFF7F,
         a3: nTexCoordCount,
         a4: pTexCoordDimensions,
         a5: 0,
         a6: nUserDataSize);
  LODWORD(this->m_ShadowShaderState.m_VertexUsage) = v7;
  HIDWORD(v9) = HIDWORD(v7);
  LODWORD(v9) = this->m_ShadowShaderState.m_VertexUsage;
  HIDWORD(this->m_ShadowShaderState.m_VertexUsage) = HIDWORD(v7);
  if ( CVertexBufferBase::VertexFormatSize(vertexFormat: v9) <= 16 )
  {
    if ( !bComplained )
    {
      _Warning(
        a1: "ERROR: shader asking for a too-narrow vertex format - you will see errors if running with debug D3D DLLs!\n"
        "\tPadding the vertex format with extra texcoords\n"
        "\tWill not warn again.\n");
      bComplained = true;
    }
    v8 = MeshMgr();
    this->m_ShadowShaderState.m_VertexUsage = v8->ComputeVertexFormat(
                                                this: v8,
                                                a2: nFlags & 0xFFFFFF7E | 1,
                                                a3: 1,
                                                a4: nullptr,
                                                a5: 0,
                                                a6: nUserDataSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FC40
// Name: public: virtual void CShaderShadowDX8::SetVertexShader(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::SetVertexShader(CShaderShadowDX8 *this, const char *pFileName, int nStaticVshIndex)
{
  int v4; // eax
  char debugLabel[504]; // [esp+8h] [ebp-1F8h] BYREF

  V_snprintf(pDest: &debugLabel[4], maxLen: 500, pFormat: "vs-file %s vs-index %d", pFileName, nStaticVshIndex);
  v4 = g_pShaderManager->CreateVertexShader(
         this: g_pShaderManager,
         a2: pFileName,
         a3: nStaticVshIndex,
         a4: &debugLabel[4]);
  this->m_ShadowShaderState.m_nStaticVshIndex = nStaticVshIndex;
  this->m_ShadowShaderState.m_VertexShader = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1002FCA0
// Name: public: virtual void CShaderShadowDX8::SetPixelShader(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::SetPixelShader(CShaderShadowDX8 *this, const char *pFileName, int nStaticPshIndex)
{
  int v4; // eax
  char debugLabel[504]; // [esp+8h] [ebp-1F8h] BYREF

  V_snprintf(pDest: &debugLabel[4], maxLen: 500, pFormat: "ps-file %s ps-index %d", pFileName, nStaticPshIndex);
  v4 = g_pShaderManager->CreatePixelShader(
         this: g_pShaderManager,
         a2: pFileName,
         a3: nStaticPshIndex,
         a4: &debugLabel[4]);
  this->m_ShadowShaderState.m_nStaticPshIndex = nStaticPshIndex;
  this->m_ShadowShaderState.m_PixelShader = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1002FD00
// Name: public: virtual float CShaderShadowDX8::GetLightMapScaleFactor(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderShadowDX8::GetLightMapScaleFactor(CShaderShadowDX8 *this)
{
  return CHardwareConfig::GetLightMapScaleFactor(this: g_pHardwareConfig);
}

//------------------------------------------------------------------------------
// Address: 0x1002FD10
// Name: public: virtual void CShaderShadowDX8::FogMode(enum ShaderFogMode_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::FogMode(CShaderShadowDX8 *this, ShaderFogMode_t fogMode, bool bVertexFog)
{
  *((_BYTE *)&this->m_ShadowState + 68) ^= (bVertexFog ^ *((_BYTE *)&this->m_ShadowState + 68)) & 1;
  this->m_ShadowState.m_FogMode = fogMode;
}

//------------------------------------------------------------------------------
// Address: 0x1002FD30
// Name: public: virtual void CShaderShadowDX8::DisableFogGammaCorrection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::DisableFogGammaCorrection(CShaderShadowDX8 *this, bool bDisable)
{
  *((_BYTE *)&this->m_ShadowState + 69) ^= (*((_BYTE *)&this->m_ShadowState + 69) ^ (4 * bDisable)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1002FD50
// Name: public: virtual void CShaderShadowDX8::ComputeAggregateShadowState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowDX8::ComputeAggregateShadowState(CShaderShadowDX8 *this)
{
  SamplerShadowState_t *m_SamplerState; // edi
  char v3; // al
  char v4; // al
  bool v5; // cl
  char v6; // bl
  bool v7; // al

  if ( this->m_pHardwareConfig->GetSamplerCount(this: this->m_pHardwareConfig) > 0 )
  {
    m_SamplerState = this->m_ShadowState.m_SamplerState;
    do
    {
      v3 = *(_BYTE *)m_SamplerState ^ *(_BYTE *)&m_SamplerState[48];
      *(_BYTE *)m_SamplerState++ ^= v3 & 1;
    }
    while ( (int)&m_SamplerState[-88 - (_DWORD)this] < this->m_pHardwareConfig->GetSamplerCount(this: this->m_pHardwareConfig) );
  }
  v4 = *((_BYTE *)&this->m_ShadowState + 68);
  v5 = (v4 & 0x20) != 0;
  if ( (v4 & 0x20) != 0 )
  {
    this->m_ShadowState.m_SrcBlend = this->m_SrcBlend;
    this->m_ShadowState.m_DestBlend = this->m_DestBlend;
    this->m_ShadowState.m_BlendOp = this->m_BlendOp;
  }
  else
  {
    this->m_ShadowState.m_SrcBlend = D3DBLEND_ONE;
    this->m_ShadowState.m_DestBlend = D3DBLEND_ZERO;
    this->m_ShadowState.m_BlendOp = D3DBLENDOP_ADD;
  }
  v6 = *((_BYTE *)&this->m_ShadowState + 69);
  if ( (v6 & 1) != 0 )
  {
    this->m_ShadowState.m_SrcBlendAlpha = this->m_SrcBlendAlpha;
    this->m_ShadowState.m_DestBlendAlpha = this->m_DestBlendAlpha;
    this->m_ShadowState.m_BlendOpAlpha = this->m_BlendOpAlpha;
  }
  else
  {
    this->m_ShadowState.m_SrcBlendAlpha = D3DBLEND_ONE;
    this->m_ShadowState.m_DestBlendAlpha = D3DBLEND_ZERO;
    this->m_ShadowState.m_BlendOpAlpha = D3DBLENDOP_ADD;
  }
  v7 = (v4 & 0x40) != 0;
  if ( v7 )
  {
    this->m_ShadowState.m_AlphaFunc = this->m_AlphaFunc;
    this->m_ShadowState.m_AlphaRef = this->m_AlphaRef;
  }
  else
  {
    this->m_ShadowState.m_AlphaFunc = D3DCMP_GREATEREQUAL;
    this->m_ShadowState.m_AlphaRef = 0;
    if ( v5
      && this->m_ShadowState.m_SrcBlend == D3DBLEND_SRCALPHA
      && this->m_ShadowState.m_DestBlend == D3DBLEND_INVSRCALPHA )
    {
      this->m_ShadowState.m_AlphaFunc = D3DCMP_GREATEREQUAL;
      this->m_ShadowState.m_AlphaRef = 1;
    }
  }
  if ( (v6 & 8) != 0 && (v5 || !v7) )
    *((_BYTE *)&this->m_ShadowState + 69) = v6 & 0xF7;
}

} // namespace shaderapidx10
