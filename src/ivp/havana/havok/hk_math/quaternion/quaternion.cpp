// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_math/quaternion/quaternion.cpp
// Functions: 1
// ============================================================

#include "ivp\havana\havok\hk_math\quaternion\quaternion.h"

//------------------------------------------------------------------------------
// Address: 0x10044110
// Name: public: void hk_Quaternion::set(class hk_Rotation const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Quaternion::set(hk_Quaternion *this, const hk_Rotation *r)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  int v7; // edx
  int v8; // esi
  int v9; // ecx
  float v10; // xmm1_4
  _OWORD *p_x; // eax
  float q[4]; // [esp+0h] [ebp-20h]
  int next[3]; // [esp+10h] [ebp-10h]
  hk_Quaternion *v14; // [esp+1Ch] [ebp-4h]

  v2 = r->m_elems[0];
  v3 = r->m_elems[5];
  v4 = r->m_elems[10];
  v5 = (float)(r->m_elems[0] + v3) + v4;
  v14 = this;
  if ( v5 <= 0.0 )
  {
    next[0] = 1;
    next[1] = 2;
    next[2] = 0;
    v7 = v3 > v2;
    if ( v4 > r->m_elems[5 * v7] )
      v7 = 2;
    v8 = next[v7];
    v9 = next[v8];
    v10 = fsqrt((float)(r->m_elems[5 * v7] - (float)(r->m_elems[5 * v9] + r->m_elems[5 * v8])) + 1.0);
    q[v7] = v10 * 0.5;
    q[3] = (float)(r->m_elems[4 * v8 + v9] - r->m_elems[4 * v9 + v8]) * (float)(0.5 / v10);
    q[v8] = (float)(r->m_elems[4 * v8 + v7] + r->m_elems[4 * v7 + v8]) * (float)(0.5 / v10);
    p_x = (_OWORD *)&v14->x;
    q[v9] = (float)(r->m_elems[4 * v9 + v7] + r->m_elems[4 * v7 + v9]) * (float)(0.5 / v10);
    *p_x = *(_OWORD *)q;
  }
  else
  {
    v6 = fsqrt(v5 + 1.0);
    this->x = (float)(r->m_elems[6] - r->m_elems[9]) * (float)(0.5 / v6);
    this->y = (float)(r->m_elems[8] - r->m_elems[2]) * (float)(0.5 / v6);
    this->z = (float)(r->m_elems[1] - r->m_elems[4]) * (float)(0.5 / v6);
    this->w = v6 * 0.5;
  }
}
