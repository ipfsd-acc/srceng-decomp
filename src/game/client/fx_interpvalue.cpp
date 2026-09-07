// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_interpvalue.cpp
// Functions: 3
// ============================================================

#include "game\client\fx_interpvalue.h"

//------------------------------------------------------------------------------
// Address: 0x100DD7B0
// Name: public: CInterpolatedValue::CInterpolatedValue(void)
// Source: json
//------------------------------------------------------------------------------
CInterpolatedValue *__thiscall CInterpolatedValue::CInterpolatedValue(CInterpolatedValue *this)
{
  this->m_flStartTime = 0.0;
  this->m_flEndTime = 0.0;
  this->m_flStartValue = 0.0;
  *(_QWORD *)&this->m_flEndValue = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DD7D0
// Name: public: void CInterpolatedValue::Init(float,float,float,enum InterpType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedValue::Init(
        CInterpolatedValue *this,
        float startValue,
        float endValue,
        float dt,
        InterpType_t type)
{
  float v5; // xmm0_4
  float v6; // xmm1_4

  if ( dt > 0.0 )
  {
    v6 = *(float *)(gpGlobals.m_Index + 12);
    this->m_flEndTime = v6 + dt;
    this->m_flStartValue = startValue;
    this->m_flStartTime = v6;
    this->m_flEndValue = endValue;
    this->m_nInterpType = type;
  }
  else
  {
    this->m_flEndValue = endValue;
    this->m_flStartValue = endValue;
    v5 = *(float *)(gpGlobals.m_Index + 12);
    this->m_flEndTime = v5;
    this->m_flStartTime = v5;
    this->m_nInterpType = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD850
// Name: public: float CInterpolatedValue::Interp(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInterpolatedValue::Interp(CInterpolatedValue *this, float curTime)
{
  int m_nInterpType; // eax
  float B; // xmm2_4
  float m_flEndTime; // xmm2_4

  m_nInterpType = this->m_nInterpType;
  if ( m_nInterpType != 0 )
  {
    if ( m_nInterpType != 1 )
      return -1.0;
    B = this->m_flEndTime;
    if ( curTime < B )
    {
      if ( this->m_flStartTime < curTime )
        return SimpleSplineRemapVal(
                 val: curTime,
                 A: this->m_flStartTime,
                 B,
                 C: this->m_flStartValue,
                 D: this->m_flEndValue);
      return this->m_flStartValue;
    }
    return this->m_flEndValue;
  }
  m_flEndTime = this->m_flEndTime;
  if ( curTime >= m_flEndTime )
    return this->m_flEndValue;
  if ( this->m_flStartTime >= curTime )
    return this->m_flStartValue;
  return RemapVal(val: curTime, A: this->m_flStartTime, B: m_flEndTime, C: this->m_flStartValue, D: this->m_flEndValue);
}
