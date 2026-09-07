// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_math/vector3/vector3.cpp
// Functions: 3
// ============================================================

#include "ivp\havana\havok\hk_math\vector3\vector3.h"

//------------------------------------------------------------------------------
// Address: 0x10044D30
// Name: public: void hk_Vector3::set_transformed_pos(class hk_Transform const __near &,class hk_Vector3 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Vector3::set_transformed_pos(hk_Vector3 *this, const hk_Transform *t, const hk_Vector3 *v)
{
  float y; // xmm2_4
  float z; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  y = v->y;
  z = v->z;
  v5 = (float)((float)((float)(t->m_elems[1] * v->x) + (float)(t->m_elems[5] * y)) + (float)(t->m_elems[9] * z))
     + t->m_translation.y;
  v6 = (float)((float)((float)(t->m_elems[2] * v->x) + (float)(t->m_elems[6] * y)) + (float)(t->m_elems[10] * z))
     + t->m_translation.z;
  this->x = (float)((float)((float)(t->m_elems[4] * y) + (float)(t->m_elems[0] * v->x)) + (float)(t->m_elems[8] * z))
          + t->m_translation.x;
  this->y = v5;
  this->z = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10044DD0
// Name: public: void hk_Vector3::set_rotated_dir(class hk_Rotation const __near &,class hk_Vector3 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Vector3::set_rotated_dir(hk_Vector3 *this, const hk_Rotation *t, const hk_Vector3 *v)
{
  float y; // xmm2_4
  float z; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  y = v->y;
  z = v->z;
  v5 = (float)((float)(t->m_elems[1] * v->x) + (float)(t->m_elems[5] * y)) + (float)(t->m_elems[9] * z);
  v6 = (float)((float)(t->m_elems[2] * v->x) + (float)(t->m_elems[6] * y)) + (float)(t->m_elems[10] * z);
  this->x = (float)((float)(t->m_elems[4] * y) + (float)(t->m_elems[0] * v->x)) + (float)(t->m_elems[8] * z);
  this->y = v5;
  this->z = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10044E70
// Name: public: void hk_Vector3::set_rotated_inv_dir(class hk_Rotation const __near &,class hk_Vector3 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Vector3::set_rotated_inv_dir(hk_Vector3 *this, const hk_Rotation *t, const hk_Vector3 *v)
{
  float y; // xmm2_4
  float z; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  y = v->y;
  z = v->z;
  v5 = (float)((float)(t->m_elems[4] * v->x) + (float)(t->m_elems[5] * y)) + (float)(t->m_elems[6] * z);
  v6 = (float)((float)(t->m_elems[8] * v->x) + (float)(t->m_elems[9] * y)) + (float)(t->m_elems[10] * z);
  this->x = (float)((float)(t->m_elems[1] * y) + (float)(t->m_elems[0] * v->x)) + (float)(t->m_elems[2] * z);
  this->y = v5;
  this->z = v6;
}
