// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_math/vector3/vector3_util.cpp
// Functions: 1
// ============================================================

#include "ivp\havana\havok\hk_math\vector3\vector3_util.h"

//------------------------------------------------------------------------------
// Address: 0x10044F10
// Name: public: static class hk_Vector3 hk_Vector3_Util::perp_vec(class hk_Vector3 const __near &)
// Source: json
//------------------------------------------------------------------------------
hk_Vector3 *__cdecl hk_Vector3_Util::perp_vec(hk_Vector3 *result, const hk_Vector3 *dir)
{
  float y; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm0_4
  float z; // xmm2_4
  float v9; // xmm0_4
  float x; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm0_4

  y = dir->y;
  v3 = 0.0;
  if ( COERCE_FLOAT(LODWORD(dir->x) & _mask__AbsFloat_) >= 0.56999999 )
  {
    z = dir->z;
    v9 = y * 0.0;
    result->x = z - v9;
    v6 = (float)(dir->x * 0.0) - (float)(z * 0.0);
    v7 = v9 - dir->x;
  }
  else
  {
    v4 = dir->z;
    result->x = (float)(v4 * 0.0) - (float)(y * 0.0);
    v5 = dir->x * 0.0;
    v6 = v5 - v4;
    v7 = y - v5;
  }
  x = result->x;
  result->z = v7;
  v11 = v6;
  result->y = v6;
  v12 = v7;
  v13 = (float)((float)(x * x) + (float)(v11 * v11)) + (float)(v12 * v12);
  if ( v13 != 0.0 )
    v3 = 1.0 / fsqrt(v13);
  result->x = x * v3;
  result->y = v11 * v3;
  result->z = v12 * v3;
  return result;
}
