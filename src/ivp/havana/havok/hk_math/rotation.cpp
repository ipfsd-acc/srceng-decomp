// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_math/rotation.cpp
// Functions: 1
// ============================================================

#include "ivp\havana\havok\hk_math\rotation.h"

//------------------------------------------------------------------------------
// Address: 0x10043F90
// Name: public: void hk_Rotation::set(class hk_Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Rotation::set(hk_Rotation *this, const hk_Quaternion *q)
{
  float v2; // xmm1_4
  float v3; // xmm5_4
  float v4; // xmm7_4
  float y; // xmm3_4
  float w; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float wx; // [esp+0h] [ebp-10h]
  float xx; // [esp+4h] [ebp-Ch]
  float xz; // [esp+8h] [ebp-8h]
  float zz; // [esp+Ch] [ebp-4h]

  v2 = q->z * 2.0;
  v3 = q->y * 2.0;
  v4 = q->x * 2.0;
  xx = q->x * v4;
  y = q->y;
  zz = q->z * v2;
  w = q->w;
  xz = q->x * v2;
  v7 = y * v2;
  v8 = q->x * v3;
  wx = w * v4;
  v9 = w * v2;
  v10 = y * v3;
  v11 = q->w * v3;
  this->m_elems[0] = 1.0 - (float)(zz + v10);
  this->m_elems[1] = v9 + v8;
  this->m_elems[2] = xz - v11;
  this->m_elems[4] = v8 - v9;
  this->m_elems[5] = 1.0 - (float)(zz + xx);
  this->m_elems[6] = wx + v7;
  this->m_elems[8] = v11 + xz;
  this->m_elems[9] = v7 - wx;
  this->m_elems[10] = 1.0 - (float)(v10 + xx);
}
