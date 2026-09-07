// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/cholesky.cpp
// Functions: 3
// ============================================================

#include "mathlib\cholesky.h"

//------------------------------------------------------------------------------
// Address: 0x006B1AE0
// Name: public: bool Cholesky3x3_t::Init(float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Cholesky3x3_t::Init(
        Cholesky3x3_t *this,
        float a00,
        float a10,
        float a11,
        float a20,
        float a21,
        float a22)
{
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm1_4

  v7 = a00;
  if ( a00 < 0.0 )
    v7 = 0.0;
  v8 = fsqrt(v7);
  this->m_00 = v8;
  if ( v8 <= 0.0000000099999999 )
    v8 = 0.0000000099999999;
  v9 = 1.0 / v8;
  v10 = (float)(1.0 / v8) * a10;
  v11 = a11 - (float)(v10 * v10);
  this->m_inv00 = v9;
  this->m_10 = v10;
  if ( v11 < 0.0 )
    v11 = 0.0;
  v12 = fsqrt(v11);
  this->m_11 = v12;
  if ( v12 <= 0.0000000099999999 )
    v13 = 0.0000000099999999;
  else
    v13 = v12;
  v14 = 1.0 / v13;
  this->m_20 = v9 * a20;
  v15 = (float)(a21 - (float)((float)(v9 * a20) * v10)) * (float)(1.0 / v13);
  this->m_21 = v15;
  v16 = (float)(a22 - (float)((float)(v9 * a20) * (float)(v9 * a20))) - (float)(v15 * v15);
  this->m_inv11 = v14;
  if ( v16 < 0.0 )
    v16 = 0.0;
  v17 = fsqrt(v16);
  this->m_22 = v17;
  if ( v17 <= 0.0000000099999999 )
    v17 = 0.0000000099999999;
  this->m_inv22 = 1.0 / v17;
  return (float)((float)(v14 + v9) + (float)(1.0 / v17)) < 10000000.0;
}

//------------------------------------------------------------------------------
// Address: 0x006B1C00
// Name: public: class Vector const Cholesky3x3_t::SolveLeft(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall Cholesky3x3_t::SolveLeft(Cholesky3x3_t *this, const Vector *result, const Vector *b)
{
  float v3; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4

  v3 = this->m_inv00 * b->x;
  v5 = (float)(b->y - (float)(this->m_10 * v3)) * this->m_inv11;
  v6 = this->m_20 * v3;
  result->x = v3;
  v7 = (float)((float)(b->z - v6) - (float)(this->m_21 * v5)) * this->m_inv22;
  result->y = v5;
  result->z = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B1C60
// Name: public: class Vector const Cholesky3x3_t::SolveRight(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall Cholesky3x3_t::SolveRight(Cholesky3x3_t *this, const Vector *result, const Vector *b)
{
  float v3; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4

  v3 = this->m_inv22 * b->z;
  v5 = (float)(b->y - (float)(this->m_21 * v3)) * this->m_inv11;
  v6 = this->m_20 * v3;
  result->z = v3;
  v7 = (float)((float)(b->x - v6) - (float)(this->m_10 * v5)) * this->m_inv00;
  result->y = v5;
  result->x = v7;
  return result;
}
