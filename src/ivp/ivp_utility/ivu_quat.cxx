// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_quat.cxx
// Functions: 10
// ============================================================

#include "ivp\ivp_utility\ivu_quat.h"

//------------------------------------------------------------------------------
// Address: 0x1006D6F0
// Name: public: void IVP_U_Quat::set_very_fast_multiple(class IVP_U_Float_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Quat::set_very_fast_multiple(IVP_U_Quat *this, const IVP_U_Float_Point *angles, float factor)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v3 = (float)(angles->k[0] * (float)(factor * 0.5))
     - (float)((float)((float)((float)(angles->k[0] * (float)(factor * 0.5))
                             * (float)(angles->k[0] * (float)(factor * 0.5)))
                     * (float)(angles->k[0] * (float)(factor * 0.5)))
             * 0.16666667);
  this->x = v3;
  v4 = (float)(angles->k[1] * (float)(factor * 0.5))
     - (float)((float)((float)((float)(angles->k[1] * (float)(factor * 0.5))
                             * (float)(angles->k[1] * (float)(factor * 0.5)))
                     * (float)(angles->k[1] * (float)(factor * 0.5)))
             * 0.16666667);
  this->y = v4;
  v5 = (float)(angles->k[2] * (float)(factor * 0.5))
     - (float)((float)((float)((float)(angles->k[2] * (float)(factor * 0.5))
                             * (float)(angles->k[2] * (float)(factor * 0.5)))
                     * (float)(angles->k[2] * (float)(factor * 0.5)))
             * 0.16666667);
  this->z = v5;
  this->w = fsqrt(1.0 - (float)((float)((float)(v4 * v4) + (float)(v3 * v3)) + (float)(v5 * v5)));
}

//------------------------------------------------------------------------------
// Address: 0x1006D7A0
// Name: public: void IVP_U_Quat::set_fast_multiple_with_clip(class IVP_U_Float_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_U_Quat::set_fast_multiple_with_clip(
        IVP_U_Quat *this@<ecx>,
        long double a2@<esi:edi>,
        const IVP_U_Float_Point *angles,
        float factor)
{
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  float y; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float z; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  long double v17; // [esp-8h] [ebp-8h]
  long double v18; // [esp-8h] [ebp-8h]
  float f; // [esp+Ch] [ebp+Ch]

  f = factor * 0.5;
  v5 = (float)(angles->k[0] * f);
  __libm_sse2_sin(x: a2);
  *(float *)&v5 = v5;
  this->x = *(float *)&v5;
  v6 = (float)(angles->k[1] * f);
  __libm_sse2_sin(x: v17);
  *(float *)&v6 = v6;
  this->y = *(float *)&v6;
  v7 = (float)(angles->k[2] * f);
  __libm_sse2_sin(x: v18);
  y = this->y;
  v9 = v7;
  *(float *)&v7 = this->x;
  this->z = v9;
  v10 = (float)((float)(*(float *)&v7 * *(float *)&v7) + (float)(y * y)) + (float)(v9 * v9);
  if ( v10 > 1.0 )
  {
    z = this->z;
    v12 = 0.99699998 / fsqrt(v10);
    v13 = this->y * v12;
    v14 = this->x * v12;
    this->y = v13;
    v15 = z * v12;
    this->x = v14;
    this->z = v15;
    v10 = (float)((float)(v13 * v13) + (float)(v14 * v14)) + (float)(v15 * v15);
  }
  this->w = fsqrt(1.0 - v10);
}

//------------------------------------------------------------------------------
// Address: 0x1006D8A0
// Name: public: void IVP_U_Quat::set_matrix(class IVP_U_Matrix3 __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Quat::set_matrix(IVP_U_Quat *this, IVP_U_Matrix3 *mat)
{
  float y; // xmm3_4
  float v3; // xmm1_4
  float v4; // xmm4_4
  float v5; // xmm6_4
  float w; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float yz; // [esp+0h] [ebp-Ch]
  float xy; // [esp+4h] [ebp-8h]
  float zz; // [esp+8h] [ebp-4h]

  y = this->y;
  v3 = this->z * 2.0;
  v4 = y * 2.0;
  v5 = this->x * 2.0;
  zz = this->z * v3;
  w = this->w;
  xy = this->x * (float)(y * 2.0);
  v7 = y * (float)(y * 2.0);
  yz = y * v3;
  v8 = this->x * v5;
  v9 = this->x * v3;
  v10 = w * v5;
  v11 = w * v3;
  v12 = this->w * v4;
  mat->rows[0].k[0] = 1.0 - (float)(zz + v7);
  mat->rows[0].k[1] = xy - v11;
  mat->rows[1].k[0] = v11 + xy;
  mat->rows[0].k[2] = v12 + v9;
  mat->rows[1].k[1] = 1.0 - (float)(zz + v8);
  mat->rows[1].k[2] = yz - v10;
  mat->rows[2].k[0] = v9 - v12;
  mat->rows[2].k[1] = v10 + yz;
  mat->rows[2].k[2] = 1.0 - (float)(v7 + v8);
}

//------------------------------------------------------------------------------
// Address: 0x1006D9B0
// Name: public: void IVP_U_Quat::set_interpolate_smoothly(class IVP_U_Quat const __near *,class IVP_U_Quat const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_U_Quat::set_interpolate_smoothly(
        IVP_U_Quat *this@<ecx>,
        int a2@<esi>,
        const IVP_U_Quat *from,
        const IVP_U_Quat *to,
        float t)
{
  float y; // xmm5_4
  float z; // xmm7_4
  float x; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float w; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  long double v22; // [esp-4h] [ebp-2Ch]
  long double v23; // [esp-4h] [ebp-2Ch]
  long double v24; // [esp-4h] [ebp-2Ch]
  float v25; // [esp+0h] [ebp-28h]
  float v26; // [esp+Ch] [ebp-1Ch]
  float scale0; // [esp+10h] [ebp-18h]
  float v28; // [esp+14h] [ebp-14h]
  float v29; // [esp+20h] [ebp-8h]
  float froma; // [esp+30h] [ebp+8h]
  float i_sinom; // [esp+34h] [ebp+Ch]
  float i_sinoma; // [esp+34h] [ebp+Ch]

  y = from->y;
  z = from->z;
  LODWORD(v22) = a2;
  x = to->x;
  v9 = to->y;
  v10 = to->z;
  v29 = from->x;
  froma = from->w;
  w = to->w;
  v26 = v9;
  v28 = to->x;
  *((float *)&v22 + 1) = w;
  i_sinom = (float)((float)((float)(to->x * v29) + (float)(v9 * y)) + (float)(v10 * z)) + (float)(w * froma);
  v12 = i_sinom;
  if ( i_sinom <= 0.0 )
  {
    LODWORD(v12) = LODWORD(i_sinom) ^ _mask__NegFloat_;
    v13 = -1.0;
    LODWORD(i_sinom) ^= _mask__NegFloat_;
  }
  else
  {
    v13 = 1.0;
  }
  if ( v12 >= 0.99900001 )
  {
    v15 = v29 + (float)((float)((float)(x * v13) - v29) * t);
    v16 = y + (float)((float)((float)(v9 * v13) - y) * t);
    v17 = (float)((float)((float)(v10 * v13) - z) * t) + z;
    v18 = (float)((float)((float)(w * v13) - froma) * t) + froma;
    v19 = (float)((float)((float)((float)(v16 * v16) + (float)(v15 * v15)) + (float)(v17 * v17)) + (float)(v18 * v18))
        * 0.5;
    v20 = (float)(0.5 - (float)((float)((float)(1.5 - v19) * (float)(1.5 - v19)) * v19)) + (float)(1.5 - v19);
    v21 = (float)(0.5 - (float)((float)(v20 * v20) * v19)) + v20;
    this->x = v15 * v21;
    this->y = v16 * v21;
    this->z = v17 * v21;
    this->w = v18 * v21;
  }
  else
  {
    __libm_sse2_acos(x: v22);
    i_sinoma = 1.0 / fsqrt(1.0 - (float)(i_sinom * i_sinom));
    __libm_sse2_sin(x: v23);
    scale0 = (float)((float)(1.0 - t) * v12) * i_sinoma;
    __libm_sse2_sin(x: v24);
    v14 = (float)((float)(v12 * t) * i_sinoma) * v13;
    this->x = (float)(v28 * v14) + (float)(v29 * scale0);
    this->y = (float)(v26 * v14) + (float)(y * scale0);
    this->z = (float)(v10 * v14) + (float)(z * scale0);
    this->w = (float)(v25 * v14) + (float)(froma * scale0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006DC60
// Name: public: void IVP_U_Quat::normize_quat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Quat::normize_quat(IVP_U_Quat *this)
{
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float w; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm5_4

  y = this->y;
  x = this->x;
  z = this->z;
  w = this->w;
  v5 = (float)((float)((float)(x * x) + (float)(y * y)) + (float)(z * z)) + (float)(w * w);
  if ( v5 > 1.0e-10 )
  {
    v6 = fsqrt(v5);
    this->x = x * (float)(1.0 / v6);
    this->y = y * (float)(1.0 / v6);
    this->z = z * (float)(1.0 / v6);
    this->w = w * (float)(1.0 / v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006DCE0
// Name: public: void IVP_U_Quat::fast_normize_quat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Quat::fast_normize_quat(IVP_U_Quat *this)
{
  float y; // xmm3_4
  float x; // xmm4_4
  float z; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float w; // [esp+0h] [ebp-4h]

  y = this->y;
  x = this->x;
  z = this->z;
  w = this->w;
  v4 = (float)((float)((float)(x * x) + (float)(y * y)) + (float)(z * z)) + (float)(w * w);
  if ( fabs(1.0 - v4) > 0.000001 )
  {
    v5 = 1.5 - (float)(v4 * 0.5);
    v6 = 1.0 - (float)((float)(v5 * v5) * v4);
    do
    {
      v5 = v5 + (float)(v6 * 0.5);
      v6 = 1.0 - (float)((float)(v5 * v5) * v4);
    }
    while ( COERCE_FLOAT(LODWORD(v6) & _mask__AbsFloat_) > 0.000001 );
    this->x = x * v5;
    this->y = y * v5;
    this->z = z * v5;
    this->w = w * v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006DDF0
// Name: public: void IVP_U_Quat::set_invert_unit_quat(class IVP_U_Quat const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Quat::set_invert_unit_quat(IVP_U_Quat *this, const IVP_U_Quat *q1)
{
  this->x = -q1->x;
  this->y = -q1->y;
  this->z = -q1->z;
  this->w = q1->w;
}

//------------------------------------------------------------------------------
// Address: 0x1006DE30
// Name: public: void IVP_U_Quat::set_div_unit_quat(class IVP_U_Quat const __near *,class IVP_U_Quat const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Quat::set_div_unit_quat(IVP_U_Quat *this, const IVP_U_Quat *q1, const IVP_U_Quat *q2)
{
  float y; // xmm4_4
  float x; // xmm1_4
  float v6; // xmm2_4
  float z; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float w; // xmm0_4
  float v13; // xmm6_4
  float v14; // [esp+0h] [ebp-4h]
  float q1a; // [esp+Ch] [ebp+8h]
  float q2a; // [esp+10h] [ebp+Ch]

  y = q1->y;
  x = q2->x;
  v6 = q2->y;
  z = q2->z;
  v8 = q1->z;
  q2a = q1->x;
  v9 = -x;
  v10 = -v6;
  v11 = -z;
  w = q1->w;
  q1a = (float)((float)((float)(y * q2->w) + (float)(w * v10)) + (float)(v8 * v9)) - (float)(q1->x * v11);
  v14 = (float)((float)((float)(v8 * q2->w) + (float)(w * v11)) + (float)(q2a * v10)) - (float)(y * v9);
  v13 = (float)(w * q2->w) - (float)(q2a * v9);
  this->x = (float)((float)((float)(w * v9) + (float)(q2a * q2->w)) + (float)(y * v11)) - (float)(v8 * v10);
  this->y = q1a;
  this->z = v14;
  this->w = (float)(v13 - (float)(y * v10)) - (float)(v8 * v11);
}

//------------------------------------------------------------------------------
// Address: 0x1006DF50
// Name: public: void IVP_U_Quat::set_invert_mult(class IVP_U_Quat const __near *,class IVP_U_Quat const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Quat::set_invert_mult(IVP_U_Quat *this, const IVP_U_Quat *q1, const IVP_U_Quat *q2)
{
  float y; // xmm4_4
  float x; // xmm1_4
  float v6; // xmm2_4
  float z; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float w; // xmm0_4
  float v13; // xmm6_4
  float v14; // [esp+0h] [ebp-4h]
  float q1a; // [esp+Ch] [ebp+8h]
  float q2a; // [esp+10h] [ebp+Ch]

  y = q2->y;
  x = q1->x;
  v6 = q1->y;
  z = q1->z;
  v8 = q2->x;
  q1a = q2->z;
  v9 = -x;
  v10 = -v6;
  v11 = -z;
  w = q2->w;
  q2a = (float)((float)((float)(y * q1->w) + (float)(w * v10)) + (float)(q2->x * v11)) - (float)(q1a * v9);
  v14 = (float)((float)((float)(q1a * q1->w) + (float)(w * v11)) + (float)(y * v9)) - (float)(v8 * v10);
  v13 = w * q1->w;
  this->x = (float)((float)((float)(w * v9) + (float)(v8 * q1->w)) + (float)(q1a * v10)) - (float)(y * v11);
  this->y = q2a;
  this->z = v14;
  this->w = (float)((float)(v13 - (float)(v8 * v9)) - (float)(y * v10)) - (float)(q1a * v11);
}

//------------------------------------------------------------------------------
// Address: 0x1006E070
// Name: public: void IVP_U_Quat::set_quaternion(class IVP_U_Matrix3 const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Quat::set_quaternion(IVP_U_Quat *this, const IVP_U_Matrix3 *mat)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  int v7; // esi
  int v8; // edi
  float v9; // xmm0_4
  int v10; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float w; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  IVP_U_Quat q; // [esp+0h] [ebp-20h]
  int nxt[3]; // [esp+10h] [ebp-10h]
  IVP_U_Quat *v19; // [esp+1Ch] [ebp-4h]

  v2 = mat->rows[0].k[0];
  v3 = mat->rows[1].k[1];
  v4 = mat->rows[2].k[2];
  v5 = (float)(mat->rows[0].k[0] + v3) + v4;
  v19 = this;
  if ( v5 <= 0.0 )
  {
    nxt[0] = 1;
    nxt[1] = 2;
    nxt[2] = 0;
    v7 = v3 > v2;
    if ( v4 > mat->rows[0].k[5 * v7] )
      v7 = 2;
    v8 = nxt[v7];
    v9 = fsqrt((float)(mat->rows[0].k[5 * v7] - (float)(mat->rows[0].k[5 * nxt[v8]] + mat->rows[0].k[5 * v8])) + 1.0);
    *(&q.x + v7) = v9 * 0.5;
    if ( v9 != 0.0 )
      v9 = 0.5 / v9;
    v10 = nxt[v8];
    q.w = (float)(mat->rows[v10].k[v8] - mat->rows[v8].k[v10]) * v9;
    *(&q.x + v8) = (float)(mat->rows[v8].k[v7] + mat->rows[v7].k[v8]) * v9;
    this = v19;
    *(&q.x + v10) = (float)(mat->rows[v10].k[v7] + mat->rows[v7].k[v10]) * v9;
    *this = q;
  }
  else
  {
    v6 = fsqrt(v5 + 1.0);
    this->w = v6 * 0.5;
    this->x = (float)(mat->rows[2].k[1] - mat->rows[1].k[2]) * (float)(0.5 / v6);
    this->y = (float)(mat->rows[0].k[2] - mat->rows[2].k[0]) * (float)(0.5 / v6);
    this->z = (float)(mat->rows[1].k[0] - mat->rows[0].k[1]) * (float)(0.5 / v6);
  }
  y = this->y;
  x = this->x;
  z = this->z;
  w = this->w;
  v15 = (float)((float)((float)(x * x) + (float)(y * y)) + (float)(z * z)) + (float)(w * w);
  if ( v15 > 1.0e-10 )
  {
    v16 = 1.0 / fsqrt(v15);
    this->x = x * v16;
    this->y = y * v16;
    this->z = z * v16;
    this->w = w * v16;
  }
}
