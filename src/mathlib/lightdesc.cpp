// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/lightdesc.cpp
// Functions: 1
// ============================================================

#include "mathlib\lightdesc.h"

//------------------------------------------------------------------------------
// Address: 0x102617A0
// Name: public: void LightDesc_t::RecalculateOneOverThetaDotMinusPhiDot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateOneOverThetaDotMinusPhiDot(LightDesc_t *this)
{
  float v1; // xmm0_4

  v1 = this->m_ThetaDot - this->m_PhiDot;
  if ( v1 <= 1.0e-10 )
    this->m_OneOverThetaDotMinusPhiDot = 1.0;
  else
    this->m_OneOverThetaDotMinusPhiDot = 1.0 / v1;
}

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D1D20
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double m_Theta; // xmm0_8
  double m_Phi; // xmm0_8
  float v8; // xmm1_4
  long double v9; // [esp-8h] [ebp-Ch]
  long double v10; // [esp-8h] [ebp-Ch]
  float v11; // [esp+0h] [ebp-4h]

  HIDWORD(v9) = a3;
  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  LODWORD(v9) = a2;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    m_Theta = this->m_Theta;
    __libm_sse2_cos(x: v9);
    *(float *)&m_Theta = m_Theta;
    v11 = *(float *)&m_Theta;
    this->m_ThetaDot = *(float *)&m_Theta;
    m_Phi = this->m_Phi;
    __libm_sse2_cos(x: v10);
    v8 = m_Phi;
    this->m_PhiDot = v8;
    if ( (float)(v11 - v8) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v11 - v8);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace shaderapidx9

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x005A6550
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00676210
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102617D0
// Name: public: void LightDesc_t::RecalculateOneOverThetaDotMinusPhiDot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateOneOverThetaDotMinusPhiDot(LightDesc_t *this)
{
  float v1; // xmm0_4

  v1 = this->m_ThetaDot - this->m_PhiDot;
  if ( v1 <= 1.0e-10 )
    this->m_OneOverThetaDotMinusPhiDot = 1.0;
  else
    this->m_OneOverThetaDotMinusPhiDot = 1.0 / v1;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102052D0
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double m_Theta; // xmm0_8
  double m_Phi; // xmm0_8
  float v8; // xmm1_4
  long double v9; // [esp-8h] [ebp-Ch]
  long double v10; // [esp-8h] [ebp-Ch]
  float v11; // [esp+0h] [ebp-4h]

  HIDWORD(v9) = a3;
  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  LODWORD(v9) = a2;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    m_Theta = this->m_Theta;
    __libm_sse2_cos(x: v9);
    *(float *)&m_Theta = m_Theta;
    v11 = *(float *)&m_Theta;
    this->m_ThetaDot = *(float *)&m_Theta;
    m_Phi = this->m_Phi;
    __libm_sse2_cos(x: v10);
    v8 = m_Phi;
    this->m_PhiDot = v8;
    if ( (float)(v11 - v8) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v11 - v8);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

//------------------------------------------------------------------------------
// Address: 0x102053F0
// Name: public: void LightDesc_t::ComputeLightAtPointsForDirectional(class FourVectors const __near &,class FourVectors const __near &,class FourVectors __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::ComputeLightAtPointsForDirectional(
        LightDesc_t *this,
        const FourVectors *pos,
        const FourVectors *normal,
        FourVectors *color,
        bool DoHalfLambert)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm0

  v5 = _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.x), (__m128)LODWORD(this->m_Direction.x), 0);
  v6 = _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.y), (__m128)LODWORD(this->m_Direction.y), 0);
  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.z), (__m128)LODWORD(this->m_Direction.z), 0);
  if ( DoHalfLambert )
    v8 = _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(normal->y, v6), _mm_mul_ps(normal->x, v5)), _mm_mul_ps(normal->z, v7)),
             Four_PointFives),
           Four_PointFives);
  else
    v8 = _mm_max_ps(
           Four_Zeros,
           _mm_add_ps(_mm_add_ps(_mm_mul_ps(normal->y, v6), _mm_mul_ps(normal->x, v5)), _mm_mul_ps(normal->z, v7)));
  color->x = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.x), (__m128)LODWORD(this->m_Color.x), 0), v8),
               color->x);
  color->y = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.y), (__m128)LODWORD(this->m_Color.y), 0), v8),
               color->y);
  color->z = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.z), (__m128)LODWORD(this->m_Color.z), 0), v8),
               color->z);
}

//------------------------------------------------------------------------------
// Address: 0x102054B0
// Name: public: float LightDesc_t::DistanceAtWhichBrightnessIsLessThan(float)const
// Source: json
//------------------------------------------------------------------------------
double __userpurge LightDesc_t::DistanceAtWhichBrightnessIsLessThan@<st0>(
        LightDesc_t *this@<ecx>,
        float a2@<ebp>,
        float flAmount)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v6; // [esp+14h] [ebp-2Ch]
  float v7; // [esp+2Ch] [ebp-14h] BYREF
  float v8[3]; // [esp+30h] [ebp-10h] BYREF
  float vars0; // [esp+40h] [ebp+0h]

  v8[1] = a2;
  v8[2] = vars0;
  v3 = this->m_Color.x * this->m_Color.x;
  if ( fsqrt((float)((float)(this->m_Color.y * this->m_Color.y) + (float)(this->m_Color.z * this->m_Color.z)) + v3) <= 0.0 )
    return 0.0;
  v6 = fsqrt((float)((float)(this->m_Color.y * this->m_Color.y) + (float)(this->m_Color.z * this->m_Color.z)) + v3);
  if ( SolveQuadratic(
         a: this->m_Attenuation2 * (float)(flAmount / v6),
         b: this->m_Attenuation1 * (float)(flAmount / v6),
         c: (float)(this->m_Attenuation0 * (float)(flAmount / v6)) - 1.0,
         root1: v8,
         root2: &v7) == 0 )
    return 0.0;
  if ( v8[0] <= v7 )
    v4 = v7;
  else
    v4 = v8[0];
  if ( v4 < 0.0 )
    return 0.0;
  if ( v8[0] <= v7 )
    v8[0] = v7;
  return v8[0];
}

//------------------------------------------------------------------------------
// Address: 0x102055F0
// Name: public: void LightDesc_t::ComputeLightAtPoints(class FourVectors const __near &,class FourVectors const __near &,class FourVectors __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge LightDesc_t::ComputeLightAtPoints(
        LightDesc_t *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        const FourVectors *pos,
        const FourVectors *normal,
        FourVectors *color,
        bool DoHalfLambert)
{
  LightType_t m_Type; // ecx
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  unsigned int m_Flags; // eax
  __m128 v13; // xmm0
  __m128 v14; // xmm3
  __m128 v15; // xmm5
  __m128 v16; // xmm7
  float m_Range; // xmm5_4
  __m128 v18; // xmm3
  __m128 v19; // xmm6
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  float m_Falloff; // xmm1_4
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  __m128 v28; // [esp-Ch] [ebp-7Ch]
  __m128 delta_4; // [esp+4h] [ebp-6Ch]
  __m128 delta_20; // [esp+14h] [ebp-5Ch]
  _BYTE dot2_4[56]; // [esp+34h] [ebp-3Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  *(_DWORD *)&dot2_4[48] = a2;
  *(_DWORD *)&dot2_4[52] = retaddr;
  m_Type = this->m_Type;
  switch ( m_Type )
  {
    case MATERIAL_LIGHT_POINT:
      goto LABEL_6;
    case MATERIAL_LIGHT_DIRECTIONAL:
      LightDesc_t::ComputeLightAtPointsForDirectional(this, pos, normal, color, DoHalfLambert);
      return;
    case MATERIAL_LIGHT_SPOT:
LABEL_6:
      v10 = _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Position.y), (__m128)LODWORD(this->m_Position.y), 0),
              pos->y);
      v9 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.z), (__m128)LODWORD(this->m_Position.z), 0),
             pos->z);
      v11 = _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Position.x), (__m128)LODWORD(this->m_Position.x), 0),
              pos->x);
      break;
    default:
      v9 = delta_20;
      v10 = delta_4;
      v11 = v28;
      break;
  }
  m_Flags = this->m_Flags;
  v13 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v11, v11), _mm_mul_ps(v10, v10)), _mm_mul_ps(v9, v9));
  v14 = _mm_max_ps(Four_Ones, v13);
  if ( (m_Flags & 1) != 0 )
    v15 = _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation0), (__m128)LODWORD(this->m_Attenuation0), 0);
  else
    v15 = Four_Epsilons;
  if ( (m_Flags & 2) != 0 )
    v15 = _mm_add_ps(
            v15,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation1), (__m128)LODWORD(this->m_Attenuation1), 0),
              _mm_sqrt_ps(v14)));
  if ( (m_Flags & 4) != 0 )
    v15 = _mm_add_ps(
            v15,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation2), (__m128)LODWORD(this->m_Attenuation2), 0),
              v14));
  v16 = _mm_rcp_ps(v15);
  m_Range = this->m_Range;
  *(__m128 *)&dot2_4[16] = v16;
  if ( m_Range != 0.0 )
  {
    v16 = _mm_and_ps(
            v16,
            _mm_cmplt_ps(
              v14,
              _mm_shuffle_ps((__m128)LODWORD(this->m_RangeSquared), (__m128)LODWORD(this->m_RangeSquared), 0)));
    *(__m128 *)&dot2_4[16] = v16;
  }
  v18 = _mm_rsqrt_ps(v13);
  v19 = _mm_mul_ps(v10, v18);
  v20 = _mm_mul_ps(v9, v18);
  v21 = _mm_mul_ps(v18, v11);
  if ( DoHalfLambert )
    v22 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(normal->y, v19), _mm_mul_ps(normal->x, v21)), _mm_mul_ps(normal->z, v20)),
              Four_PointFives),
            Four_PointFives);
  else
    v22 = _mm_max_ps(
            Four_Zeros,
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(normal->y, v19), _mm_mul_ps(normal->x, v21)), _mm_mul_ps(normal->z, v20)));
  *(__m128 *)&dot2_4[32] = v22;
  if ( m_Type == MATERIAL_LIGHT_SPOT )
  {
    v23 = _mm_sub_ps(
            Four_Zeros,
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.y), (__m128)LODWORD(this->m_Direction.y), 0),
                  v19),
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.x), (__m128)LODWORD(this->m_Direction.x), 0),
                  v21)),
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.z), (__m128)LODWORD(this->m_Direction.z), 0),
                v20)));
    m_Falloff = this->m_Falloff;
    v25 = _mm_min_ps(
            _mm_mul_ps(
              _mm_sub_ps(v23, _mm_shuffle_ps((__m128)LODWORD(this->m_PhiDot), (__m128)LODWORD(this->m_PhiDot), 0)),
              _mm_shuffle_ps(
                (__m128)LODWORD(this->m_OneOverThetaDotMinusPhiDot),
                (__m128)LODWORD(this->m_OneOverThetaDotMinusPhiDot),
                0)),
            Four_Ones);
    *(__m128 *)dot2_4 = v25;
    if ( m_Falloff != 0.0 && m_Falloff != 1.0 )
    {
      Pow_FixedPoint_Exponent_SIMD(
        result: (__m128 *)dot2_4,
        x: (const __m128 *)(int)(float)(m_Falloff * 4.0),
        exponent: a3);
      v22 = *(__m128 *)&dot2_4[32];
    }
    v16 = *(__m128 *)&dot2_4[16];
    v22 = _mm_and_ps(
            _mm_mul_ps(v22, v25),
            _mm_cmplt_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_PhiDot), (__m128)LODWORD(this->m_PhiDot), 0), v23));
  }
  v26 = _mm_mul_ps(v22, v16);
  color->x = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.x), (__m128)LODWORD(this->m_Color.x), 0), v26),
               color->x);
  color->y = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.y), (__m128)LODWORD(this->m_Color.y), 0), v26),
               color->y);
  color->z = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.z), (__m128)LODWORD(this->m_Color.z), 0), v26),
               color->z);
}

//------------------------------------------------------------------------------
// Address: 0x10205880
// Name: public: void LightDesc_t::ComputeNonincidenceLightAtPoints(class FourVectors const __near &,class FourVectors __near &)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge LightDesc_t::ComputeNonincidenceLightAtPoints(
        LightDesc_t *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        const FourVectors *pos,
        FourVectors *color)
{
  LightType_t m_Type; // ecx
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm0
  unsigned int m_Flags; // eax
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm5
  __m128 v14; // xmm7
  float m_Range; // xmm5_4
  __m128 v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 m_OneOverThetaDotMinusPhiDot_low; // xmm2
  __m128 v23; // xmm4
  __m128 m_PhiDot_low; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  float m_Falloff; // xmm1_4
  __m128 v28; // xmm0
  __m128 v29; // xmm6
  __m128 v31; // [esp-Ch] [ebp-7Ch]
  __m128 delta_4; // [esp+4h] [ebp-6Ch]
  __m128 delta_20; // [esp+14h] [ebp-5Ch]
  _BYTE dot2_4[40]; // [esp+44h] [ebp-2Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  *(_DWORD *)&dot2_4[32] = a2;
  *(_DWORD *)&dot2_4[36] = retaddr;
  m_Type = this->m_Type;
  switch ( m_Type )
  {
    case MATERIAL_LIGHT_POINT:
      goto LABEL_4;
    case MATERIAL_LIGHT_DIRECTIONAL:
      return;
    case MATERIAL_LIGHT_SPOT:
LABEL_4:
      v7 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.y), (__m128)LODWORD(this->m_Position.y), 0),
             pos->y);
      v8 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.x), (__m128)LODWORD(this->m_Position.x), 0),
             pos->x);
      v9 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.z), (__m128)LODWORD(this->m_Position.z), 0),
             pos->z);
      break;
    default:
      v9 = delta_20;
      v7 = delta_4;
      v8 = v31;
      break;
  }
  m_Flags = this->m_Flags;
  v11 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v7, v7), _mm_mul_ps(v8, v8)), _mm_mul_ps(v9, v9));
  v12 = _mm_max_ps(Four_Ones, v11);
  if ( (m_Flags & 1) != 0 )
    v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation0), (__m128)LODWORD(this->m_Attenuation0), 0);
  else
    v13 = Four_Epsilons;
  if ( (m_Flags & 2) != 0 )
    v13 = _mm_add_ps(
            v13,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation1), (__m128)LODWORD(this->m_Attenuation1), 0),
              _mm_sqrt_ps(v12)));
  if ( (m_Flags & 4) != 0 )
    v13 = _mm_add_ps(
            v13,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation2), (__m128)LODWORD(this->m_Attenuation2), 0),
              v12));
  v14 = _mm_rcp_ps(v13);
  m_Range = this->m_Range;
  *(__m128 *)&dot2_4[16] = v14;
  if ( m_Range != 0.0 )
  {
    v14 = _mm_and_ps(
            v14,
            _mm_cmplt_ps(
              v12,
              _mm_shuffle_ps((__m128)LODWORD(this->m_RangeSquared), (__m128)LODWORD(this->m_RangeSquared), 0)));
    *(__m128 *)&dot2_4[16] = v14;
  }
  v16 = Four_Ones;
  v17 = _mm_rsqrt_ps(v11);
  v18 = _mm_mul_ps(v17, v8);
  v19 = _mm_mul_ps(v7, v17);
  v20 = _mm_mul_ps(v9, v17);
  if ( m_Type == MATERIAL_LIGHT_SPOT )
  {
    v21 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Direction.x), (__m128)LODWORD(this->m_Direction.x), 0), v18);
    m_OneOverThetaDotMinusPhiDot_low = (__m128)LODWORD(this->m_OneOverThetaDotMinusPhiDot);
    v23 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Direction.y), (__m128)LODWORD(this->m_Direction.y), 0), v19);
    m_PhiDot_low = (__m128)LODWORD(this->m_PhiDot);
    *(__m128 *)dot2_4 = _mm_add_ps(
                          _mm_add_ps(v21, v23),
                          _mm_mul_ps(
                            _mm_shuffle_ps(
                              (__m128)LODWORD(this->m_Direction.z),
                              (__m128)LODWORD(this->m_Direction.z),
                              0),
                            v20));
    v25 = _mm_sub_ps(Four_Zeros, *(__m128 *)dot2_4);
    v26 = _mm_sub_ps(v25, _mm_shuffle_ps(m_PhiDot_low, m_PhiDot_low, 0));
    m_Falloff = this->m_Falloff;
    v28 = _mm_min_ps(
            _mm_mul_ps(v26, _mm_shuffle_ps(m_OneOverThetaDotMinusPhiDot_low, m_OneOverThetaDotMinusPhiDot_low, 0)),
            Four_Ones);
    *(__m128 *)dot2_4 = v28;
    if ( m_Falloff != 0.0 && m_Falloff != 1.0 )
    {
      Pow_FixedPoint_Exponent_SIMD(
        result: (__m128 *)dot2_4,
        x: (const __m128 *)(int)(float)(m_Falloff * 4.0),
        exponent: a3);
      v16 = Four_Ones;
    }
    v14 = *(__m128 *)&dot2_4[16];
    v16 = _mm_and_ps(
            _mm_mul_ps(v16, v28),
            _mm_cmplt_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_PhiDot), (__m128)LODWORD(this->m_PhiDot), 0), v25));
  }
  v29 = _mm_mul_ps(v16, v14);
  color->x = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.x), (__m128)LODWORD(this->m_Color.x), 0), v29),
               color->x);
  color->y = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.y), (__m128)LODWORD(this->m_Color.y), 0), v29),
               color->y);
  color->z = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.z), (__m128)LODWORD(this->m_Color.z), 0), v29),
               color->z);
}

//------------------------------------------------------------------------------
// Address: 0x10205AB0
// Name: public: void LightDesc_t::SetupOldStyleAttenuation(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::SetupOldStyleAttenuation(
        LightDesc_t *this,
        float fQuadraticAttn,
        float fLinearAttn,
        float fConstantAttn)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4

  v4 = fQuadraticAttn;
  if ( fQuadraticAttn < 0.001 )
    v4 = 0.0;
  v5 = fLinearAttn;
  if ( fLinearAttn < 0.001 )
    v5 = 0.0;
  v6 = fConstantAttn;
  if ( fConstantAttn < 0.001 )
    v6 = 0.0;
  if ( v6 < 0.001 && v5 < 0.001 && v4 < 0.001 )
    v6 = 1.0;
  this->m_Attenuation2 = v4;
  this->m_Attenuation1 = v5;
  v7 = (float)((float)(v4 * 10000.0) + (float)(v5 * 100.0)) + v6;
  this->m_Attenuation0 = v6;
  if ( v7 > 0.0 )
  {
    this->m_Color.x = this->m_Color.x * v7;
    this->m_Color.y = this->m_Color.y * v7;
    this->m_Color.z = this->m_Color.z * v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205B80
// Name: public: void LightDesc_t::SetupNewStyleAttenuation(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::SetupNewStyleAttenuation(
        LightDesc_t *this,
        float fFiftyPercentDistance,
        float fZeroPercentDistance)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float x1; // [esp+0h] [ebp-Ch] BYREF
  float y1; // [esp+4h] [ebp-8h] BYREF
  float x2; // [esp+8h] [ebp-4h] BYREF

  v3 = fZeroPercentDistance;
  v4 = fFiftyPercentDistance;
  if ( fFiftyPercentDistance > fZeroPercentDistance )
  {
    _Warning(a1: "light has _fifty_percent_distance of %f but no zero_percent_distance\n", fFiftyPercentDistance);
    v4 = fFiftyPercentDistance;
    v3 = fFiftyPercentDistance * 2.0;
    fZeroPercentDistance = fFiftyPercentDistance * 2.0;
  }
  x2 = 0.0;
  y1 = 1.0;
  x1 = 0.0;
  if ( SolveInverseQuadraticMonotonic(
         x1: 0x3F80000000000000uLL,
         x2: LODWORD(v4) | 0x4000000000000000LL,
         x3: LODWORD(v3),
         y3: 256.0,
         a: &x2,
         b: &y1,
         c: &x1) == 0 )
    _Warning(a1: "can't solve quadratic for light %f %f\n", fFiftyPercentDistance, fZeroPercentDistance);
  v6 = 2.0 / (float)((float)((float)((float)(x2 * fFiftyPercentDistance) + y1) * fFiftyPercentDistance) + x1);
  v7 = v6 * x2;
  v8 = v6 * y1;
  v9 = v6 * x1;
  this->m_Attenuation2 = v7;
  this->m_Attenuation1 = v8;
  this->m_Attenuation0 = v9;
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B3C90
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00565040
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x005758D0
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006A50B0
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005778B0
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace sfmgen

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x100421A0
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double m_Theta; // xmm0_8
  double m_Phi; // xmm0_8
  float v8; // xmm1_4
  long double v9; // [esp-8h] [ebp-Ch]
  long double v10; // [esp-8h] [ebp-Ch]
  float v11; // [esp+0h] [ebp-4h]

  HIDWORD(v9) = a3;
  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  LODWORD(v9) = a2;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    m_Theta = this->m_Theta;
    __libm_sse2_cos(x: v9);
    *(float *)&m_Theta = m_Theta;
    v11 = *(float *)&m_Theta;
    this->m_ThetaDot = *(float *)&m_Theta;
    m_Phi = this->m_Phi;
    __libm_sse2_cos(x: v10);
    v8 = m_Phi;
    this->m_PhiDot = v8;
    if ( (float)(v11 - v8) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v11 - v8);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace shaderapidx10

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00575200
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x006B1CC0
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

} // namespace vmap

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1040C660
// Name: public: void LightDesc_t::RecalculateDerivedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::RecalculateDerivedValues(LightDesc_t *this)
{
  float m_Attenuation0; // xmm1_4
  LightType_t m_Type; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-4h]

  m_Attenuation0 = this->m_Attenuation0;
  this->m_Flags = 8;
  if ( m_Attenuation0 != 0.0 )
    this->m_Flags = 9;
  if ( this->m_Attenuation1 != 0.0 )
    this->m_Flags |= 2u;
  if ( this->m_Attenuation2 != 0.0 )
    this->m_Flags |= 4u;
  m_Type = this->m_Type;
  if ( this->m_Type == MATERIAL_LIGHT_SPOT )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Theta)));
    *(float *)&v4 = v4;
    v7 = *(float *)&v4;
    this->m_ThetaDot = *(float *)&v4;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_Phi)));
    v6 = v5;
    this->m_PhiDot = v6;
    if ( (float)(v7 - v6) <= 1.0e-10 )
      this->m_OneOverThetaDotMinusPhiDot = 1.0;
    else
      this->m_OneOverThetaDotMinusPhiDot = 1.0 / (float)(v7 - v6);
  }
  if ( m_Type == MATERIAL_LIGHT_DIRECTIONAL )
  {
    this->m_Position.x = this->m_Direction.x;
    this->m_Position.y = this->m_Direction.y;
    this->m_Position.z = this->m_Direction.z;
    this->m_Position.x = this->m_Position.x * 2000000.0;
    this->m_Position.y = this->m_Position.y * 2000000.0;
    this->m_Position.z = this->m_Position.z * 2000000.0;
  }
  this->m_RangeSquared = this->m_Range * this->m_Range;
}

//------------------------------------------------------------------------------
// Address: 0x1040C780
// Name: public: void LightDesc_t::ComputeLightAtPointsForDirectional(class FourVectors const __near &,class FourVectors const __near &,class FourVectors __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::ComputeLightAtPointsForDirectional(
        LightDesc_t *this,
        const FourVectors *pos,
        const FourVectors *normal,
        FourVectors *color,
        bool DoHalfLambert)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm0

  v5 = _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.x), (__m128)LODWORD(this->m_Direction.x), 0);
  v6 = _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.y), (__m128)LODWORD(this->m_Direction.y), 0);
  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.z), (__m128)LODWORD(this->m_Direction.z), 0);
  if ( DoHalfLambert )
    v8 = _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(normal->y, v6), _mm_mul_ps(normal->x, v5)), _mm_mul_ps(normal->z, v7)),
             Four_PointFives),
           Four_PointFives);
  else
    v8 = _mm_max_ps(
           Four_Zeros,
           _mm_add_ps(_mm_add_ps(_mm_mul_ps(normal->y, v6), _mm_mul_ps(normal->x, v5)), _mm_mul_ps(normal->z, v7)));
  color->x = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.x), (__m128)LODWORD(this->m_Color.x), 0), v8),
               color->x);
  color->y = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.y), (__m128)LODWORD(this->m_Color.y), 0), v8),
               color->y);
  color->z = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.z), (__m128)LODWORD(this->m_Color.z), 0), v8),
               color->z);
}

//------------------------------------------------------------------------------
// Address: 0x1040C840
// Name: public: void LightDesc_t::ComputeLightAtPoints(class FourVectors const __near &,class FourVectors const __near &,class FourVectors __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge LightDesc_t::ComputeLightAtPoints(
        LightDesc_t *this@<ecx>,
        int a2@<ebp>,
        const FourVectors *pos,
        const FourVectors *normal,
        FourVectors *color,
        bool DoHalfLambert)
{
  LightType_t m_Type; // ecx
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  unsigned int m_Flags; // eax
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm5
  __m128 v15; // xmm7
  float m_Range; // xmm5_4
  __m128 v17; // xmm3
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  float m_Falloff; // xmm1_4
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // [esp-Ch] [ebp-7Ch]
  __m128 delta_4; // [esp+4h] [ebp-6Ch]
  __m128 delta_20; // [esp+14h] [ebp-5Ch]
  _BYTE dot2_4[56]; // [esp+34h] [ebp-3Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  *(_DWORD *)&dot2_4[48] = a2;
  *(_DWORD *)&dot2_4[52] = retaddr;
  m_Type = this->m_Type;
  switch ( m_Type )
  {
    case MATERIAL_LIGHT_POINT:
      goto LABEL_6;
    case MATERIAL_LIGHT_DIRECTIONAL:
      LightDesc_t::ComputeLightAtPointsForDirectional(this, pos, normal, color, DoHalfLambert);
      return;
    case MATERIAL_LIGHT_SPOT:
LABEL_6:
      v9 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.y), (__m128)LODWORD(this->m_Position.y), 0),
             pos->y);
      v8 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.z), (__m128)LODWORD(this->m_Position.z), 0),
             pos->z);
      v10 = _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Position.x), (__m128)LODWORD(this->m_Position.x), 0),
              pos->x);
      break;
    default:
      v8 = delta_20;
      v9 = delta_4;
      v10 = v26;
      break;
  }
  m_Flags = this->m_Flags;
  v12 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, v10), _mm_mul_ps(v9, v9)), _mm_mul_ps(v8, v8));
  v13 = _mm_max_ps(Four_Ones, v12);
  if ( (m_Flags & 1) != 0 )
    v14 = _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation0), (__m128)LODWORD(this->m_Attenuation0), 0);
  else
    v14 = Four_Epsilons;
  if ( (m_Flags & 2) != 0 )
    v14 = _mm_add_ps(
            v14,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation1), (__m128)LODWORD(this->m_Attenuation1), 0),
              _mm_sqrt_ps(v13)));
  if ( (m_Flags & 4) != 0 )
    v14 = _mm_add_ps(
            v14,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation2), (__m128)LODWORD(this->m_Attenuation2), 0),
              v13));
  v15 = _mm_rcp_ps(v14);
  m_Range = this->m_Range;
  *(__m128 *)&dot2_4[16] = v15;
  if ( m_Range != 0.0 )
  {
    v15 = _mm_and_ps(
            v15,
            _mm_cmplt_ps(
              v13,
              _mm_shuffle_ps((__m128)LODWORD(this->m_RangeSquared), (__m128)LODWORD(this->m_RangeSquared), 0)));
    *(__m128 *)&dot2_4[16] = v15;
  }
  v17 = _mm_rsqrt_ps(v12);
  v18 = _mm_mul_ps(v9, v17);
  v19 = _mm_mul_ps(v8, v17);
  v20 = _mm_mul_ps(v17, v10);
  if ( DoHalfLambert )
    v21 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(normal->y, v18), _mm_mul_ps(normal->x, v20)), _mm_mul_ps(normal->z, v19)),
              Four_PointFives),
            Four_PointFives);
  else
    v21 = _mm_max_ps(
            Four_Zeros,
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(normal->y, v18), _mm_mul_ps(normal->x, v20)), _mm_mul_ps(normal->z, v19)));
  *(__m128 *)&dot2_4[32] = v21;
  if ( m_Type == MATERIAL_LIGHT_SPOT )
  {
    v22 = _mm_sub_ps(
            Four_Zeros,
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.y), (__m128)LODWORD(this->m_Direction.y), 0),
                  v18),
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.x), (__m128)LODWORD(this->m_Direction.x), 0),
                  v20)),
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(this->m_Direction.z), (__m128)LODWORD(this->m_Direction.z), 0),
                v19)));
    m_Falloff = this->m_Falloff;
    v24 = _mm_min_ps(
            _mm_mul_ps(
              _mm_sub_ps(v22, _mm_shuffle_ps((__m128)LODWORD(this->m_PhiDot), (__m128)LODWORD(this->m_PhiDot), 0)),
              _mm_shuffle_ps(
                (__m128)LODWORD(this->m_OneOverThetaDotMinusPhiDot),
                (__m128)LODWORD(this->m_OneOverThetaDotMinusPhiDot),
                0)),
            Four_Ones);
    *(__m128 *)dot2_4 = v24;
    if ( m_Falloff != 0.0 && m_Falloff != 1.0 )
    {
      v24 = Pow_FixedPoint_Exponent_SIMD(result: (__m128 *)dot2_4, x: (const __m128 *)(int)(float)(m_Falloff * 4.0));
      v21 = *(__m128 *)&dot2_4[32];
    }
    v15 = *(__m128 *)&dot2_4[16];
    v21 = _mm_and_ps(
            _mm_mul_ps(v21, v24),
            _mm_cmplt_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_PhiDot), (__m128)LODWORD(this->m_PhiDot), 0), v22));
  }
  v25 = _mm_mul_ps(v21, v15);
  color->x = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.x), (__m128)LODWORD(this->m_Color.x), 0), v25),
               color->x);
  color->y = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.y), (__m128)LODWORD(this->m_Color.y), 0), v25),
               color->y);
  color->z = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.z), (__m128)LODWORD(this->m_Color.z), 0), v25),
               color->z);
}

//------------------------------------------------------------------------------
// Address: 0x1040CAD0
// Name: public: void LightDesc_t::ComputeNonincidenceLightAtPoints(class FourVectors const __near &,class FourVectors __near &)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge LightDesc_t::ComputeNonincidenceLightAtPoints(
        LightDesc_t *this@<ecx>,
        int a2@<ebp>,
        const FourVectors *pos,
        FourVectors *color)
{
  LightType_t m_Type; // ecx
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  __m128 v8; // xmm0
  unsigned int m_Flags; // eax
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm5
  __m128 v13; // xmm7
  float m_Range; // xmm5_4
  __m128 v15; // xmm6
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __m128 m_OneOverThetaDotMinusPhiDot_low; // xmm2
  __m128 v22; // xmm4
  __m128 m_PhiDot_low; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  float m_Falloff; // xmm1_4
  __m128 v27; // xmm0
  __m128 v28; // xmm6
  __m128 v29; // [esp-Ch] [ebp-7Ch]
  __m128 delta_4; // [esp+4h] [ebp-6Ch]
  __m128 delta_20; // [esp+14h] [ebp-5Ch]
  _BYTE dot2_4[40]; // [esp+44h] [ebp-2Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  *(_DWORD *)&dot2_4[32] = a2;
  *(_DWORD *)&dot2_4[36] = retaddr;
  m_Type = this->m_Type;
  switch ( m_Type )
  {
    case MATERIAL_LIGHT_POINT:
      goto LABEL_4;
    case MATERIAL_LIGHT_DIRECTIONAL:
      return;
    case MATERIAL_LIGHT_SPOT:
LABEL_4:
      v6 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.y), (__m128)LODWORD(this->m_Position.y), 0),
             pos->y);
      v7 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.x), (__m128)LODWORD(this->m_Position.x), 0),
             pos->x);
      v8 = _mm_sub_ps(
             _mm_shuffle_ps((__m128)LODWORD(this->m_Position.z), (__m128)LODWORD(this->m_Position.z), 0),
             pos->z);
      break;
    default:
      v8 = delta_20;
      v6 = delta_4;
      v7 = v29;
      break;
  }
  m_Flags = this->m_Flags;
  v10 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v6, v6), _mm_mul_ps(v7, v7)), _mm_mul_ps(v8, v8));
  v11 = _mm_max_ps(Four_Ones, v10);
  if ( (m_Flags & 1) != 0 )
    v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation0), (__m128)LODWORD(this->m_Attenuation0), 0);
  else
    v12 = Four_Epsilons;
  if ( (m_Flags & 2) != 0 )
    v12 = _mm_add_ps(
            v12,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation1), (__m128)LODWORD(this->m_Attenuation1), 0),
              _mm_sqrt_ps(v11)));
  if ( (m_Flags & 4) != 0 )
    v12 = _mm_add_ps(
            v12,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(this->m_Attenuation2), (__m128)LODWORD(this->m_Attenuation2), 0),
              v11));
  v13 = _mm_rcp_ps(v12);
  m_Range = this->m_Range;
  *(__m128 *)&dot2_4[16] = v13;
  if ( m_Range != 0.0 )
  {
    v13 = _mm_and_ps(
            v13,
            _mm_cmplt_ps(
              v11,
              _mm_shuffle_ps((__m128)LODWORD(this->m_RangeSquared), (__m128)LODWORD(this->m_RangeSquared), 0)));
    *(__m128 *)&dot2_4[16] = v13;
  }
  v15 = Four_Ones;
  v16 = _mm_rsqrt_ps(v10);
  v17 = _mm_mul_ps(v16, v7);
  v18 = _mm_mul_ps(v6, v16);
  v19 = _mm_mul_ps(v8, v16);
  if ( m_Type == MATERIAL_LIGHT_SPOT )
  {
    v20 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Direction.x), (__m128)LODWORD(this->m_Direction.x), 0), v17);
    m_OneOverThetaDotMinusPhiDot_low = (__m128)LODWORD(this->m_OneOverThetaDotMinusPhiDot);
    v22 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Direction.y), (__m128)LODWORD(this->m_Direction.y), 0), v18);
    m_PhiDot_low = (__m128)LODWORD(this->m_PhiDot);
    *(__m128 *)dot2_4 = _mm_add_ps(
                          _mm_add_ps(v20, v22),
                          _mm_mul_ps(
                            _mm_shuffle_ps(
                              (__m128)LODWORD(this->m_Direction.z),
                              (__m128)LODWORD(this->m_Direction.z),
                              0),
                            v19));
    v24 = _mm_sub_ps(Four_Zeros, *(__m128 *)dot2_4);
    v25 = _mm_sub_ps(v24, _mm_shuffle_ps(m_PhiDot_low, m_PhiDot_low, 0));
    m_Falloff = this->m_Falloff;
    v27 = _mm_min_ps(
            _mm_mul_ps(v25, _mm_shuffle_ps(m_OneOverThetaDotMinusPhiDot_low, m_OneOverThetaDotMinusPhiDot_low, 0)),
            Four_Ones);
    *(__m128 *)dot2_4 = v27;
    if ( m_Falloff != 0.0 && m_Falloff != 1.0 )
    {
      v27 = Pow_FixedPoint_Exponent_SIMD(result: (__m128 *)dot2_4, x: (const __m128 *)(int)(float)(m_Falloff * 4.0));
      v15 = Four_Ones;
    }
    v13 = *(__m128 *)&dot2_4[16];
    v15 = _mm_and_ps(
            _mm_mul_ps(v15, v27),
            _mm_cmplt_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_PhiDot), (__m128)LODWORD(this->m_PhiDot), 0), v24));
  }
  v28 = _mm_mul_ps(v15, v13);
  color->x = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.x), (__m128)LODWORD(this->m_Color.x), 0), v28),
               color->x);
  color->y = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.y), (__m128)LODWORD(this->m_Color.y), 0), v28),
               color->y);
  color->z = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_Color.z), (__m128)LODWORD(this->m_Color.z), 0), v28),
               color->z);
}

//------------------------------------------------------------------------------
// Address: 0x1040CD00
// Name: public: void LightDesc_t::SetupNewStyleAttenuation(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LightDesc_t::SetupNewStyleAttenuation(
        LightDesc_t *this,
        float fFiftyPercentDistance,
        float fZeroPercentDistance)
{
  float x3; // xmm0_4
  float v4; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float c; // [esp+2Ch] [ebp-Ch] BYREF
  float b; // [esp+30h] [ebp-8h] BYREF
  float a; // [esp+34h] [ebp-4h] BYREF

  x3 = fZeroPercentDistance;
  v4 = fFiftyPercentDistance;
  if ( fFiftyPercentDistance > fZeroPercentDistance )
  {
    _Warning(a1: "light has _fifty_percent_distance of %f but no zero_percent_distance\n", fFiftyPercentDistance);
    v4 = fFiftyPercentDistance;
    x3 = fFiftyPercentDistance * 2.0;
    fZeroPercentDistance = fFiftyPercentDistance * 2.0;
  }
  a = 0.0;
  b = 1.0;
  c = 0.0;
  if ( SolveInverseQuadraticMonotonic(
         x1: 0,
         y1: 0x3F800000u,
         x2: LODWORD(v4) | 0x4000000000000000LL,
         x3: LODWORD(x3),
         y3: 256.0,
         &a,
         &b,
         &c) == 0 )
    _Warning(a1: "can't solve quadratic for light %f %f\n", fFiftyPercentDistance, fZeroPercentDistance);
  v6 = 2.0 / (float)((float)((float)((float)(a * fFiftyPercentDistance) + b) * fFiftyPercentDistance) + c);
  v7 = v6 * a;
  v8 = v6 * b;
  v9 = v6 * c;
  this->m_Attenuation2 = v7;
  this->m_Attenuation1 = v8;
  this->m_Attenuation0 = v9;
}

} // namespace client
