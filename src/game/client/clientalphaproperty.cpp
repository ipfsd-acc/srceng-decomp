// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/clientalphaproperty.cpp
// Functions: 12
// ============================================================

#include "game\client\clientalphaproperty.h"

//------------------------------------------------------------------------------
// Address: 0x100A3380
// Name: public: void CClientAlphaProperty::SetShadowHandle(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientAlphaProperty::SetShadowHandle(CClientAlphaProperty *this, unsigned __int16 hShadowHandle)
{
  this->m_hShadowHandle = hShadowHandle;
}

//------------------------------------------------------------------------------
// Address: 0x100A3390
// Name: public: virtual void CClientAlphaProperty::SetAlphaModulation(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientAlphaProperty::SetAlphaModulation(CClientAlphaProperty *this, unsigned __int8 a)
{
  this->m_nAlpha = a;
}

//------------------------------------------------------------------------------
// Address: 0x100A33A0
// Name: public: virtual void CClientAlphaProperty::EnableAlphaModulationOverride(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientAlphaProperty::EnableAlphaModulationOverride(CClientAlphaProperty *this, bool bEnable)
{
  *((_WORD *)this + 5) = *((_WORD *)this + 5) & 0xFDFF | (bEnable << 9);
}

//------------------------------------------------------------------------------
// Address: 0x100A33D0
// Name: public: virtual void CClientAlphaProperty::EnableShadowAlphaModulationOverride(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientAlphaProperty::EnableShadowAlphaModulationOverride(CClientAlphaProperty *this, bool bEnable)
{
  *((_WORD *)this + 5) = *((_WORD *)this + 5) & 0xFBFF | (bEnable << 10);
}

//------------------------------------------------------------------------------
// Address: 0x100A3400
// Name: public: virtual void CClientAlphaProperty::SetRenderFX(enum RenderFx_t,enum RenderMode_t,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientAlphaProperty::SetRenderFX(
        CClientAlphaProperty *this,
        RenderFx_t nRenderFx,
        RenderMode_t nRenderMode,
        float flStartTime,
        float flDuration)
{
  float v5; // xmm0_4
  __int16 v6; // ax

  v5 = flStartTime;
  v6 = *((_WORD *)this + 5);
  switch ( nRenderFx )
  {
    case kRenderFxFadeSlow:
    case kRenderFxSolidSlow:
      if ( flStartTime == 3.4028235e38 )
        v5 = *(float *)(gpGlobals.m_Index + 12);
      flDuration = 4.0;
      break;
    case kRenderFxFadeFast:
    case kRenderFxSolidFast:
      if ( flStartTime == 3.4028235e38 )
        v5 = *(float *)(gpGlobals.m_Index + 12);
      flDuration = 1.0;
      break;
    case kRenderFxFadeOut:
    case kRenderFxFadeIn:
      if ( flStartTime == 3.4028235e38 )
        v5 = *(float *)(gpGlobals.m_Index + 12);
      break;
    default:
      break;
  }
  *((_WORD *)this + 5) = nRenderFx & 0x1F | v6 & 0xFE00 | (32 * (nRenderMode & 0xF));
  if ( (v6 & 0x1F) != nRenderFx || flStartTime != 3.4028235e38 )
  {
    this->m_flRenderFxStartTime = v5;
    this->m_flRenderFxDuration = flDuration;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A34E0
// Name: public: virtual void CClientAlphaProperty::SetDesyncOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientAlphaProperty::SetDesyncOffset(CClientAlphaProperty *this, unsigned __int16 nOffset)
{
  this->m_nDesyncOffset = nOffset;
}

//------------------------------------------------------------------------------
// Address: 0x100A34F0
// Name: public: virtual void CClientAlphaProperty::SetDistanceFadeMode(enum ClientAlphaDistanceFadeMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientAlphaProperty::SetDistanceFadeMode(
        CClientAlphaProperty *this,
        ClientAlphaDistanceFadeMode_t nFadeMode)
{
  *((_WORD *)this + 5) ^= (*((_WORD *)this + 5) ^ ((_WORD)nFadeMode << 11)) & 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x100A3510
// Name: public: CClientAlphaProperty::CClientAlphaProperty(void)
// Source: json
//------------------------------------------------------------------------------
CClientAlphaProperty *__thiscall CClientAlphaProperty::CClientAlphaProperty(CClientAlphaProperty *this)
{
  this->m_nDesyncOffset = 0;
  *(_DWORD *)&this->m_nDistFadeStart = 0;
  *((_WORD *)this + 5) &= 0xF000u;
  this->__vftable = (CClientAlphaProperty_vtbl *)&CClientAlphaProperty::`vftable';
  this->m_hShadowHandle = -1;
  this->m_nAlpha = -1;
  this->m_flFadeScale = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A3540
// Name: public: virtual void CClientAlphaProperty::SetFade(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientAlphaProperty::SetFade(
        CClientAlphaProperty *this,
        float flGlobalFadeScale,
        float flDistFadeStart,
        float flDistFadeEnd)
{
  float v4; // xmm0_4
  float v5; // xmm1_4

  v4 = flDistFadeStart;
  v5 = flDistFadeEnd;
  if ( flDistFadeStart > flDistFadeEnd )
  {
    v4 = flDistFadeEnd;
    v5 = flDistFadeStart;
  }
  if ( v4 < 0.0 )
  {
    v4 = v4 + v5;
    if ( v4 < 0.0 )
      v4 = 0.0;
  }
  this->m_nDistFadeStart = (int)v4;
  this->m_nDistFadeEnd = (int)v5;
  this->m_flFadeScale = flGlobalFadeScale;
}

//------------------------------------------------------------------------------
// Address: 0x100A3590
// Name: private: int CClientAlphaProperty::ComputeRenderEffectBlend(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientAlphaProperty::ComputeRenderEffectBlend(CClientAlphaProperty *this, int nRenderEffect)
{
  float v3; // xmm0_4
  __m128 v4; // xmm1
  double v5; // xmm0_8
  int result; // eax
  __m128 v7; // xmm1
  double v8; // xmm0_8
  float v9; // xmm0_4
  float v10; // xmm0_4
  __m128 v11; // xmm1
  double v12; // xmm0_8
  __m128 v13; // xmm1
  double v14; // xmm0_8
  __m128 v15; // xmm1
  double v16; // xmm0_8
  double v17; // st7
  __m128 v18; // xmm1
  double v19; // xmm0_8
  __m128 v20; // xmm1
  double v21; // xmm0_8
  __m128 v22; // xmm1
  double v23; // xmm0_8
  __m128 v24; // xmm1
  double v25; // xmm0_8
  __m128 v26; // xmm0
  double v27; // xmm0_8
  __m128 v28; // xmm1
  double v29; // xmm0_8
  __m128 v30; // xmm0
  double v31; // xmm0_8
  float v32; // [esp+18h] [ebp-4h]
  float v33; // [esp+18h] [ebp-4h]
  float flVal; // [esp+24h] [ebp+8h]
  float flVala; // [esp+24h] [ebp+8h]
  float flValb; // [esp+24h] [ebp+8h]

  v3 = (double)this->m_nDesyncOffset * 363.0;
  switch ( nRenderEffect )
  {
    case 1:
      v13 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * 2.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v13));
      *(float *)&v14 = v14;
      v9 = *(float *)&v14 * 16.0;
      return (int)(float)(v9 + (float)this->m_nAlpha);
    case 2:
      v15 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v15.m128_f32[0] = (float)(v15.m128_f32[0] * 8.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v15));
      *(float *)&v16 = v16;
      return (int)(float)((float)(*(float *)&v16 * 16.0) + (float)this->m_nAlpha);
    case 3:
      v4 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v4.m128_f32[0] = (float)(v4.m128_f32[0] * 2.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v5 = v5;
      return (int)(float)((float)(*(float *)&v5 * 64.0) + (float)this->m_nAlpha);
    case 4:
      v7 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v7.m128_f32[0] = (float)(v7.m128_f32[0] * 8.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v7));
      *(float *)&v8 = v8;
      v9 = *(float *)&v8 * 64.0;
      return (int)(float)(v9 + (float)this->m_nAlpha);
    case 5:
    case 6:
    case 15:
      v17 = RemapValClamped(
              val: *(float *)(gpGlobals.m_Index + 12) - this->m_flRenderFxStartTime,
              A: 0.0,
              B: this->m_flRenderFxDuration,
              C: (float)this->m_nAlpha,
              D: 0.0);
      goto LABEL_10;
    case 7:
    case 8:
    case 16:
      v17 = RemapValClamped(
              val: *(float *)(gpGlobals.m_Index + 12) - this->m_flRenderFxStartTime,
              A: 0.0,
              B: this->m_flRenderFxDuration,
              C: 0.0,
              D: (float)this->m_nAlpha);
LABEL_10:
      if ( v17 < 0.0 )
        return (int)0.0;
      v10 = v17;
      flVal = v17;
      if ( flVal <= 255.0 )
        return (int)v10;
      else
        return (int)255.0;
    case 9:
      v18 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v18.m128_f32[0] = (float)(v18.m128_f32[0] * 4.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v18));
      *(float *)&v19 = v19;
      if ( (int)(float)(*(float *)&v19 * 20.0) >= 0 )
        goto LABEL_26;
      result = 0;
      break;
    case 10:
      v20 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v20.m128_f32[0] = (float)(v20.m128_f32[0] * 16.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v20));
      *(float *)&v21 = v21;
      if ( (int)(float)(*(float *)&v21 * 20.0) >= 0 )
        goto LABEL_26;
      result = 0;
      break;
    case 11:
      v22 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v22.m128_f32[0] = (float)(v22.m128_f32[0] * 36.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v22));
      *(float *)&v23 = v23;
      if ( (int)(float)(*(float *)&v23 * 20.0) >= 0 )
        goto LABEL_26;
      result = 0;
      break;
    case 12:
      v24 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      flVala = v24.m128_f32[0];
      v24.m128_f32[0] = (float)(v24.m128_f32[0] * 17.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v24));
      *(float *)&v25 = v25;
      v32 = *(float *)&v25;
      v26 = (__m128)LODWORD(flVala);
      v26.m128_f32[0] = flVala * 2.0;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v26));
      *(float *)&v27 = v27;
      if ( (int)(float)((float)(v32 + *(float *)&v27) * 20.0) >= 0 )
        goto LABEL_26;
      result = 0;
      break;
    case 13:
      v28 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      flValb = v28.m128_f32[0];
      v28.m128_f32[0] = (float)(v28.m128_f32[0] * 23.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v28));
      *(float *)&v29 = v29;
      v33 = *(float *)&v29;
      v30 = (__m128)LODWORD(flValb);
      v30.m128_f32[0] = flValb * 16.0;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v30));
      *(float *)&v31 = v31;
      if ( (int)(float)((float)(v33 + *(float *)&v31) * 20.0) >= 0 )
        goto LABEL_26;
      result = 0;
      break;
    case 17:
      v11 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v11.m128_f32[0] = (float)(v11.m128_f32[0] * 12.0) + v3;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v11));
      *(float *)&v12 = v12;
      return (int)(float)(COERCE_FLOAT(LODWORD(v12) & _mask__AbsFloat_) * 255.0);
    default:
      result = 255;
      if ( (*((_WORD *)this + 5) & 0x1E0) != 0 )
LABEL_26:
        result = this->m_nAlpha;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A39C0
// Name: public: unsigned char CClientAlphaProperty::ComputeRenderAlpha(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CClientAlphaProperty::ComputeRenderAlpha(CClientAlphaProperty *this)
{
  unsigned __int16 v2; // di
  int v3; // ecx
  unsigned int v4; // eax
  int m_nAlpha; // eax
  IClientRenderable *v6; // eax

  v2 = *((_WORD *)this + 5);
  v3 = (v2 >> 5) & 0xF;
  if ( v3 == 10 || v3 == 6 )
  {
    LOBYTE(m_nAlpha) = 0;
  }
  else
  {
    v4 = v2 & 0x1F;
    if ( v4 <= 0xA || v4 >= 0x13 )
    {
      m_nAlpha = 255;
      if ( (_WORD)v3 != 0 )
        m_nAlpha = this->m_nAlpha;
    }
    else
    {
      m_nAlpha = CClientAlphaProperty::ComputeRenderEffectBlend(this, nRenderEffect: v2 & 0x1F);
    }
    if ( (v2 & 0x200) != 0 )
    {
      v6 = this->m_pOuter->GetClientRenderable(this: this->m_pOuter);
      m_nAlpha = v6->OverrideAlphaModulation(this: v6, a2: this->m_nAlpha);
    }
    if ( m_nAlpha >= 0 )
    {
      if ( m_nAlpha > 255 )
        LOBYTE(m_nAlpha) = -1;
    }
    else
    {
      LOBYTE(m_nAlpha) = 0;
    }
  }
  return m_nAlpha;
}

//------------------------------------------------------------------------------
// Address: 0x100A3A50
// Name: __CreateCClientEntityListIClientEntityList_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientEntityList *__cdecl _CreateCClientEntityListIClientEntityList_interface()
{
  return &s_EntityList.IClientEntityList;
}
