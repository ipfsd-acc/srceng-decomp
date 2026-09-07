// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_math/transform.cpp
// Functions: 1
// ============================================================

#include "ivp\havana\havok\hk_math\transform.h"

//------------------------------------------------------------------------------
// Address: 0x100440C0
// Name: public: void hk_Transform::set_identity_transform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Transform::set_identity_transform(hk_Transform *this)
{
  this->m_elems[0] = 1.0;
  this->m_elems[1] = 0.0;
  this->m_elems[2] = 0.0;
  this->m_elems[4] = 0.0;
  this->m_elems[5] = 1.0;
  this->m_elems[6] = 0.0;
  this->m_elems[8] = 0.0;
  this->m_elems[9] = 0.0;
  this->m_elems[10] = 1.0;
  this->m_translation.x = 0.0;
  this->m_translation.y = 0.0;
  this->m_translation.z = 0.0;
}
