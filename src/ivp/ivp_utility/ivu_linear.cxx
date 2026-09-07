// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_linear.cxx
// Functions: 40
// ============================================================

#include "ivp\ivp_utility\ivu_linear.h"

//------------------------------------------------------------------------------
// Address: 0x10070E40
// Name: public: void IVP_U_Matrix3::inline_mimult3(class IVP_U_Matrix3 const __near *,class IVP_U_Matrix3 __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::inline_mimult3(IVP_U_Matrix3 *this, const IVP_U_Matrix3 *mb, IVP_U_Matrix3 *m_out)
{
  float v3; // xmm3_4
  float v4; // xmm0_4
  float v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm7_4
  float v9; // xmm6_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // [esp-8h] [ebp-58h]
  float v14; // [esp-4h] [ebp-54h]
  float col_8; // [esp+8h] [ebp-48h]
  float col_12; // [esp+Ch] [ebp-44h]
  float col_44; // [esp+2Ch] [ebp-24h]
  float v18; // [esp+30h] [ebp-20h]
  float v19; // [esp+34h] [ebp-1Ch]
  float v20; // [esp+38h] [ebp-18h]

  v3 = mb->rows[1].k[1];
  v4 = mb->rows[0].k[1];
  v5 = mb->rows[2].k[1];
  v19 = mb->rows[2].k[2];
  v20 = mb->rows[1].k[2];
  v6 = mb->rows[0].k[2];
  col_44 = mb->rows[2].k[0];
  v18 = mb->rows[1].k[0];
  v7 = mb->rows[0].k[0];
  v13 = (float)((float)(v4 * this->rows[0].k[0]) + (float)(v3 * this->rows[1].k[0])) + (float)(v5 * this->rows[2].k[0]);
  v14 = (float)((float)(v6 * this->rows[0].k[0]) + (float)(v20 * this->rows[1].k[0]))
      + (float)(v19 * this->rows[2].k[0]);
  v8 = (float)((float)(mb->rows[0].k[0] * this->rows[0].k[1]) + (float)(v18 * this->rows[1].k[1]))
     + (float)(col_44 * this->rows[2].k[1]);
  col_8 = (float)((float)(v4 * this->rows[0].k[1]) + (float)(v3 * this->rows[1].k[1]))
        + (float)(v5 * this->rows[2].k[1]);
  v9 = this->rows[1].k[2];
  col_12 = (float)((float)(v6 * this->rows[0].k[1]) + (float)(v20 * this->rows[1].k[1]))
         + (float)(v19 * this->rows[2].k[1]);
  v10 = this->rows[0].k[2];
  v11 = (float)(v4 * v10) + (float)(v3 * v9);
  v12 = this->rows[2].k[2];
  m_out->rows[0].k[0] = (float)((float)(mb->rows[0].k[0] * this->rows[0].k[0]) + (float)(v18 * this->rows[1].k[0]))
                      + (float)(col_44 * this->rows[2].k[0]);
  m_out->rows[0].k[1] = v13;
  m_out->rows[0].k[2] = v14;
  m_out->rows[1].k[1] = col_8;
  m_out->rows[1].k[0] = v8;
  m_out->rows[1].k[2] = col_12;
  m_out->rows[2].k[0] = (float)((float)(v7 * v10) + (float)(v18 * v9)) + (float)(col_44 * v12);
  m_out->rows[2].k[1] = v11 + (float)(v5 * v12);
  m_out->rows[2].k[2] = (float)((float)(v6 * v10) + (float)(v20 * v9)) + (float)(v19 * v12);
}

//------------------------------------------------------------------------------
// Address: 0x10071070
// Name: public: void IVP_U_Matrix3::inline_mmult3(class IVP_U_Matrix3 const __near *,class IVP_U_Matrix3 __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::inline_mmult3(IVP_U_Matrix3 *this, const IVP_U_Matrix3 *mb, IVP_U_Matrix3 *m_out)
{
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // [esp-4h] [ebp-54h]
  float row_4; // [esp+4h] [ebp-4Ch]
  float row_8; // [esp+8h] [ebp-48h]
  float row_12; // [esp+Ch] [ebp-44h]
  float row_36; // [esp+24h] [ebp-2Ch]
  float row_40; // [esp+28h] [ebp-28h]
  float v18; // [esp+30h] [ebp-20h]
  float v19; // [esp+34h] [ebp-1Ch]
  float v20; // [esp+38h] [ebp-18h]
  float v21; // [esp+3Ch] [ebp-14h]
  float v22; // [esp+40h] [ebp-10h]

  v3 = mb->rows[0].k[1];
  v4 = (float)((float)(this->rows[0].k[0] * v3) + (float)(this->rows[0].k[1] * mb->rows[1].k[1]))
     + (float)(this->rows[0].k[2] * mb->rows[2].k[1]);
  v20 = mb->rows[1].k[2];
  v21 = mb->rows[2].k[1];
  v5 = mb->rows[0].k[2];
  v6 = this->rows[1].k[2];
  v12 = (float)((float)(this->rows[0].k[0] * v5) + (float)(this->rows[0].k[1] * v20))
      + (float)(this->rows[0].k[2] * mb->rows[2].k[2]);
  v18 = mb->rows[1].k[0];
  v19 = mb->rows[2].k[2];
  v7 = this->rows[1].k[1];
  row_40 = mb->rows[2].k[0];
  row_4 = (float)((float)(v7 * v18) + (float)(this->rows[1].k[0] * mb->rows[0].k[0])) + (float)(v6 * row_40);
  row_36 = mb->rows[1].k[1];
  v8 = this->rows[2].k[2];
  row_8 = (float)((float)(v7 * row_36) + (float)(v3 * this->rows[1].k[0])) + (float)(v6 * v21);
  v9 = (float)((float)(v7 * v20) + (float)(v5 * this->rows[1].k[0])) + (float)(v6 * v19);
  v10 = this->rows[2].k[1];
  row_12 = v9;
  v22 = this->rows[2].k[0];
  v11 = (float)((float)(v10 * v18) + (float)(v22 * mb->rows[0].k[0])) + (float)(v8 * row_40);
  m_out->rows[0].k[0] = (float)((float)(this->rows[0].k[0] * mb->rows[0].k[0]) + (float)(this->rows[0].k[1] * v18))
                      + (float)(this->rows[0].k[2] * row_40);
  m_out->rows[0].k[1] = v4;
  m_out->rows[0].k[2] = v12;
  m_out->rows[1].k[0] = row_4;
  m_out->rows[1].k[1] = row_8;
  m_out->rows[1].k[2] = row_12;
  m_out->rows[2].k[0] = v11;
  m_out->rows[2].k[1] = (float)((float)(v10 * row_36) + (float)(v3 * v22)) + (float)(v8 * v21);
  m_out->rows[2].k[2] = (float)((float)(v10 * v20) + (float)(v5 * v22)) + (float)(v8 * v19);
}

//------------------------------------------------------------------------------
// Address: 0x10071290
// Name: public: static float IVP_Inline_Math::isqrt_float(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl IVP_Inline_Math::isqrt_float(float quad)
{
  return 1.0 / sqrt(quad);
}

//------------------------------------------------------------------------------
// Address: 0x100712A0
// Name: public: void IVP_U_Float_Point::set_interpolate(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Float_Point::set_interpolate(
        IVP_U_Float_Point *this,
        const IVP_U_Float_Point *p0,
        const IVP_U_Float_Point *p1,
        float s)
{
  float v4; // xmm2_4
  float v5; // xmm1_4

  v4 = (float)(p0->k[1] * (float)(1.0 - s)) + (float)(p1->k[1] * s);
  v5 = (float)(p1->k[2] * s) + (float)(p0->k[2] * (float)(1.0 - s));
  this->k[0] = (float)(p0->k[0] * (float)(1.0 - s)) + (float)(p1->k[0] * s);
  this->k[1] = v4;
  this->k[2] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10071310
// Name: public: float IVP_U_Float_Point::real_length_plus_normize(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_U_Float_Point::real_length_plus_normize(IVP_U_Float_Point *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm3_4
  float v4; // xmm0_4
  float v6; // xmm4_4

  v1 = this->k[1];
  v2 = this->k[0];
  v3 = this->k[2];
  v4 = (float)((float)(v2 * v2) + (float)(v1 * v1)) + (float)(v3 * v3);
  if ( v4 < 1.0e-10 )
    return 0.0;
  v6 = fsqrt(v4);
  this->k[0] = v2 * (float)(1.0 / v6);
  this->k[1] = v1 * (float)(1.0 / v6);
  this->k[2] = v3 * (float)(1.0 / v6);
  return (float)(1.0 / v6) * (float)((float)((float)(v2 * v2) + (float)(v1 * v1)) + (float)(v3 * v3));
}

//------------------------------------------------------------------------------
// Address: 0x100713A0
// Name: public: enum IVP_RETURN_TYPE IVP_U_Float_Point::fast_normize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_U_Float_Point::fast_normize(IVP_U_Float_Point *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm3_4
  float v4; // xmm0_4
  float v6; // xmm4_4

  v1 = this->k[1];
  v2 = this->k[0];
  v3 = this->k[2];
  v4 = (float)((float)(v2 * v2) + (float)(v1 * v1)) + (float)(v3 * v3);
  if ( v4 < 1.0e-10 )
    return 0;
  v6 = fsqrt(v4);
  this->k[0] = v2 * (float)(1.0 / v6);
  this->k[1] = v1 * (float)(1.0 / v6);
  this->k[2] = v3 * (float)(1.0 / v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10071410
// Name: public: void IVP_U_Float_Point::set_orthogonal_part(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Float_Point::set_orthogonal_part(
        IVP_U_Float_Point *this,
        const IVP_U_Float_Point *vector,
        const IVP_U_Float_Point *normal_v)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm3_4

  LODWORD(v3) = COERCE_UNSIGNED_INT(
                  (float)((float)(normal_v->k[0] * vector->k[0]) + (float)(normal_v->k[1] * vector->k[1]))
                + (float)(normal_v->k[2] * vector->k[2]))
              ^ _mask__NegFloat_;
  v4 = (float)(normal_v->k[1] * v3) + vector->k[1];
  v5 = (float)(normal_v->k[2] * v3) + vector->k[2];
  this->k[0] = (float)(normal_v->k[0] * v3) + vector->k[0];
  this->k[1] = v4;
  this->k[2] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10071480
// Name: public: void IVP_U_Float_Point::calc_cross_product(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Float_Point::calc_cross_product(
        IVP_U_Float_Point *this,
        const IVP_U_Float_Point *v1,
        const IVP_U_Float_Point *v2)
{
  float v3; // xmm3_4
  float v4; // xmm0_4

  v3 = (float)(v1->k[2] * v2->k[0]) - (float)(v2->k[2] * v1->k[0]);
  v4 = (float)(v1->k[0] * v2->k[1]) - (float)(v2->k[0] * v1->k[1]);
  this->k[0] = (float)(v2->k[2] * v1->k[1]) - (float)(v1->k[2] * v2->k[1]);
  this->k[1] = v3;
  this->k[2] = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100714E0
// Name: public: void IVP_U_Point::solve_quadratic_equation_accurate(class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Point::solve_quadratic_equation_accurate(IVP_U_Point *this, const IVP_U_Point *p)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm0_4

  if ( fabs(p->k[0]) >= 1.0e-10 )
  {
    v3 = (float)(p->k[1] * p->k[1]) - (float)((float)(p->k[2] * p->k[0]) * 4.0);
    this->k[0] = v3;
    if ( v3 >= 0.0 )
    {
      v4 = 0.5 / p->k[0];
      v5 = fsqrt(v3);
      v6 = p->k[1];
      this->k[2] = (float)(v5 - v6) * v4;
      this->k[1] = (float)(COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) - v5) * v4;
    }
  }
  else
  {
    this->k[0] = 0.0;
    if ( fabs(p->k[1]) >= 1.0e-10 )
    {
      LODWORD(v2) = COERCE_UNSIGNED_INT(p->k[2] / p->k[1]) ^ _mask__NegFloat_;
      this->k[2] = v2;
      this->k[1] = v2;
    }
    else
    {
      this->k[0] = -1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100715C0
// Name: public: enum IVP_BOOL IVP_U_Point::is_parallel(class IVP_U_Point const __near *,float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_U_Point::is_parallel(IVP_U_Point *this, const IVP_U_Point *v_in, float eps)
{
  float v3; // xmm4_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm1_4

  v3 = this->k[1];
  v4 = v_in->k[1];
  v5 = this->k[0];
  v6 = v_in->k[0];
  v7 = (float)(v_in->k[2] * v3) - (float)(this->k[2] * v4);
  v8 = (float)(this->k[2] * v_in->k[0]) - (float)(v_in->k[2] * this->k[0]);
  return (float)((float)((float)((float)((float)(v3 * v3) + (float)(v5 * v5)) + (float)(this->k[2] * this->k[2]))
                       * (float)(eps * eps))
               * (float)((float)((float)(v4 * v4) + (float)(v6 * v6)) + (float)(v_in->k[2] * v_in->k[2]))) >= (float)((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)((float)((float)(v4 * v5) - (float)(v3 * v6)) * (float)((float)(v4 * v5) - (float)(v3 * v6))));
}

//------------------------------------------------------------------------------
// Address: 0x10071690
// Name: public: float IVP_U_Float_Point::fast_real_length(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall IVP_U_Float_Point::fast_real_length(IVP_U_Float_Point *this)
{
  return sqrt(this->k[1] * this->k[1] + this->k[0] * this->k[0] + this->k[2] * this->k[2]);
}

//------------------------------------------------------------------------------
// Address: 0x100716B0
// Name: public: void IVP_U_Point::line_min(class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Point::line_min(IVP_U_Point *this, const IVP_U_Point *p)
{
  float v2; // xmm0_4
  float v3; // xmm0_4

  v2 = p->k[2];
  if ( this->k[2] > v2 )
    this->k[2] = v2;
  v3 = p->k[1];
  if ( this->k[1] > v3 )
    this->k[1] = v3;
  if ( this->k[0] > p->k[0] )
    this->k[0] = p->k[0];
}

//------------------------------------------------------------------------------
// Address: 0x10071700
// Name: public: void IVP_U_Point::line_max(class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Point::line_max(IVP_U_Point *this, const IVP_U_Point *p)
{
  float v2; // xmm0_4
  float v3; // xmm0_4

  v2 = p->k[2];
  if ( v2 > this->k[2] )
    this->k[2] = v2;
  v3 = p->k[1];
  if ( v3 > this->k[1] )
    this->k[1] = v3;
  if ( p->k[0] > this->k[0] )
    this->k[0] = p->k[0];
}

//------------------------------------------------------------------------------
// Address: 0x10071740
// Name: public: void IVP_U_Float_Point::rotate(enum IVP_COORDINATE_INDEX,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_U_Float_Point::rotate(
        IVP_U_Float_Point *this@<ecx>,
        long double a2@<esi:edi>,
        IVP_COORDINATE_INDEX axis,
        float angle)
{
  int *v5; // edi
  int v6; // eax
  float v7; // xmm1_4
  float *v8; // ecx
  float v9; // xmm2_4
  long double v11; // [esp-8h] [ebp-1Ch]
  int hp[5]; // [esp+0h] [ebp-14h] BYREF

  hp[0] = 0;
  hp[1] = 1;
  hp[2] = 2;
  hp[3] = 0;
  hp[4] = 1;
  v5 = &hp[axis];
  __libm_sse2_cos(x: a2);
  __libm_sse2_sin(x: v11);
  v6 = v5[1];
  v7 = this->k[v6];
  v8 = &this->k[v5[2]];
  v9 = (float)(v7 * angle) - (float)(*v8 * angle);
  *v8 = (float)(*v8 * angle) + (float)(v7 * angle);
  this->k[v6] = v9;
}

//------------------------------------------------------------------------------
// Address: 0x100717E0
// Name: public: void IVP_U_Hesse::proj_on_plane(class IVP_U_Point const __near *,class IVP_U_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Hesse::proj_on_plane(
        IVP_U_Float_Hesse *this,
        const IVP_U_Float_Point *p,
        IVP_U_Float_Point *result)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4

  v3 = this->k[1];
  v4 = this->k[2];
  v5 = (float)(-1.0 / (float)((float)((float)(this->k[0] * this->k[0]) + (float)(v3 * v3)) + (float)(v4 * v4)))
     * (float)((float)((float)((float)(v3 * p->k[1]) + (float)(p->k[0] * this->k[0])) + (float)(v4 * p->k[2]))
             + this->hesse_val);
  v6 = (float)(v3 * v5) + p->k[1];
  v7 = (float)(v4 * v5) + p->k[2];
  result->k[0] = (float)(this->k[0] * v5) + p->k[0];
  result->k[1] = v6;
  result->k[2] = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10071880
// Name: public: void IVP_U_Hesse::calc_hesse(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Hesse::calc_hesse(
        IVP_U_Hesse *this,
        const IVP_U_Float_Point *tp0,
        const IVP_U_Float_Point *tp1,
        const IVP_U_Float_Point *tp2)
{
  float v4; // xmm2_4
  float v5; // xmm7_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float fp0; // [esp+4h] [ebp-4h]
  float fp1; // [esp+10h] [ebp+8h]

  v4 = tp0->k[1];
  v5 = tp0->k[2];
  v6 = tp2->k[0] - tp0->k[0];
  fp0 = tp0->k[0];
  v7 = tp1->k[0] - tp0->k[0];
  v8 = tp2->k[2] - v5;
  v9 = tp1->k[1] - v4;
  fp1 = v4;
  v10 = tp1->k[2] - v5;
  v11 = tp2->k[1] - v4;
  v12 = (float)(v11 * v10) - (float)(v8 * v9);
  v13 = (float)(v8 * v7) - (float)(v6 * v10);
  this->k[1] = v13;
  this->k[0] = v12;
  v14 = (float)(v6 * v9) - (float)(v11 * v7);
  this->k[2] = v14;
  LODWORD(this->hesse_val) = COERCE_UNSIGNED_INT((float)((float)(v13 * fp1) + (float)(v12 * fp0)) + (float)(v14 * v5))
                           ^ _mask__NegFloat_;
}

//------------------------------------------------------------------------------
// Address: 0x10071950
// Name: public: void IVP_U_Float_Hesse::calc_hesse_val(class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Float_Hesse::calc_hesse_val(IVP_U_Float_Hesse *this, const IVP_U_Float_Point *p0)
{
  LODWORD(this->hesse_val) = COERCE_UNSIGNED_INT(
                               (float)((float)(p0->k[1] * this->k[1]) + (float)(p0->k[0] * this->k[0]))
                             + (float)(p0->k[2] * this->k[2]))
                           ^ _mask__NegFloat_;
}

//------------------------------------------------------------------------------
// Address: 0x10071990
// Name: public: void IVP_U_Hesse::normize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Hesse::normize(IVP_U_Float_Hesse *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  v1 = this->k[1];
  v2 = this->k[0];
  v3 = this->k[2];
  v4 = 1.0 / fsqrt((float)((float)(v2 * v2) + (float)(v1 * v1)) + (float)(v3 * v3));
  this->k[1] = v1 * v4;
  v5 = this->hesse_val * v4;
  this->k[0] = v2 * v4;
  this->k[2] = v3 * v4;
  this->hesse_val = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10071A00
// Name: public: void IVP_U_Matrix::init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix::init(IVP_U_Matrix *this)
{
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_U_Matrix));
  this->rows[0].k[0] = 1.0;
  this->rows[1].k[1] = 1.0;
  this->rows[2].k[2] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10071A30
// Name: public: void IVP_U_Matrix3::init3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::init3(IVP_U_Matrix3 *this)
{
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_U_Matrix3));
  this->rows[0].k[0] = 1.0;
  this->rows[1].k[1] = 1.0;
  this->rows[2].k[2] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10071A60
// Name: public: void IVP_U_Matrix3::init_normized3_col(class IVP_U_Point const __near *,enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_U_Matrix3::init_normized3_col(
        IVP_U_Matrix3 *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Point *vp,
        IVP_COORDINATE_INDEX coordinate)
{
  float v4; // xmm6_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [esp-Ch] [ebp-30h]
  _DWORD v19[2]; // [esp-8h] [ebp-2Ch]
  _BYTE p[32]; // [esp+0h] [ebp-24h] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+24h] [ebp+0h]

  *(_DWORD *)&p[24] = a2;
  *(_DWORD *)&p[28] = retaddr;
  *(IVP_U_Point *)&p[8] = *vp;
  v4 = *(float *)&p[8];
  v5 = *(float *)&p[12];
  v6 = *(float *)&p[16];
  v7 = (float)((float)(v4 * v4) + (float)(v5 * v5)) + (float)(v6 * v6);
  if ( v7 >= 1.0e-10 )
  {
    v8 = fsqrt(v7);
    v4 = *(float *)&p[8] * (float)(1.0 / v8);
    v5 = (float)(1.0 / v8) * *(float *)&p[12];
    v6 = (float)(1.0 / v8) * *(float *)&p[16];
  }
  v9 = v6 - v4;
  LODWORD(v10) = LODWORD(v5) ^ _mask__NegFloat_;
  v11 = (float)((float)(v9 * v9) + (float)(v5 * v5)) + (float)(v10 * v10);
  if ( v11 >= 1.0e-10 )
  {
    v12 = 1.0 / fsqrt(v11);
    v13 = v12 * v5;
LABEL_7:
    v10 = v10 * v12;
    v9 = v9 * v12;
    goto LABEL_8;
  }
  LODWORD(v9) = LODWORD(v6) ^ _mask__NegFloat_;
  v10 = v5 - v4;
  v14 = (float)((float)(v9 * v9) + (float)(v6 * v6)) + (float)(v10 * v10);
  v13 = v6;
  if ( v14 >= 1.0e-10 )
  {
    v12 = 1.0 / fsqrt(v14);
    v13 = v12 * v6;
    goto LABEL_7;
  }
LABEL_8:
  v18 = 0;
  *(_DWORD *)p = 0;
  *(float *)&p[8] = (float)(v9 * v6) - (float)(v10 * v5);
  v19[0] = 1;
  v19[1] = 2;
  *(_DWORD *)&p[4] = 1;
  v15 = v19[coordinate - 1];
  this->rows[2].k[v15] = v6;
  this->rows[0].k[v15] = v4;
  this->rows[1].k[v15] = v5;
  v16 = v19[coordinate];
  *(float *)&p[12] = (float)(v10 * v4) - (float)(v13 * v6);
  this->rows[0].k[v16] = *(float *)&p[8];
  this->rows[1].k[v16] = *(float *)&p[12];
  this->rows[2].k[v16] = (float)(v13 * v5) - (float)(v9 * v4);
  v17 = *(_DWORD *)&p[4 * coordinate - 4];
  this->rows[0].k[v17] = v13;
  this->rows[1].k[v17] = v9;
  this->rows[2].k[v17] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x10071C50
// Name: public: void IVP_U_Matrix::init_rot_multiple(class IVP_U_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_U_Matrix::init_rot_multiple(
        IVP_U_Matrix *this@<ecx>,
        double a2@<esi:edi>,
        const IVP_U_Point *angles,
        float factor)
{
  float v5; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  long double v14; // [esp-8h] [ebp-18h]
  long double v15; // [esp-8h] [ebp-18h]
  long double v16; // [esp-8h] [ebp-18h]
  long double v17; // [esp-8h] [ebp-18h]
  float y; // [esp+8h] [ebp-8h]
  float u; // [esp+Ch] [ebp-4h]
  float x; // [esp+18h] [ebp+8h]

  v14 = a2;
  v5 = angles->k[0];
  if ( angles->k[0] == 0.0 )
  {
    v7 = 1.0;
    x = 1.0;
    y = 0.0;
  }
  else
  {
    __libm_sse2_cos(x: v14);
    x = v5 * factor;
    __libm_sse2_sin(x: v15);
    v7 = v5 * factor;
    y = v5 * factor;
  }
  v8 = angles->k[1];
  if ( v8 == 0.0 )
  {
    v9 = 1.0;
    u = 1.0;
    v10 = 0.0;
  }
  else
  {
    __libm_sse2_cos(x: v14);
    u = v8 * factor;
    __libm_sse2_sin(x: v16);
    v9 = v8 * factor;
    v7 = x;
    v10 = v8 * factor;
  }
  v11 = angles->k[2];
  if ( v11 == 0.0 )
  {
    v12 = 1.0;
    v13 = 0.0;
  }
  else
  {
    __libm_sse2_cos(x: v14);
    __libm_sse2_sin(x: v17);
    v9 = u;
    v7 = x;
    v12 = v11 * factor;
    v13 = v11 * factor;
  }
  this->vv.k[2] = 0.0;
  this->vv.k[1] = 0.0;
  this->vv.k[0] = 0.0;
  this->rows[0].k[0] = (float)((float)(v10 * y) * v13) + (float)(v12 * v9);
  this->rows[0].k[1] = (float)((float)(v10 * y) * v12) - (float)(v13 * v9);
  this->rows[0].k[2] = v10 * v7;
  this->rows[1].k[0] = v13 * v7;
  this->rows[1].k[1] = v12 * v7;
  LODWORD(this->rows[1].k[2]) = LODWORD(y) ^ _mask__NegFloat_;
  this->rows[2].k[0] = (float)((float)(v9 * y) * v13) - (float)(v12 * v10);
  this->rows[2].k[1] = (float)((float)(v9 * y) * v12) + (float)(v13 * v10);
  this->rows[2].k[2] = v9 * v7;
}

//------------------------------------------------------------------------------
// Address: 0x10071E40
// Name: public: void IVP_U_Matrix3::mmult3(class IVP_U_Matrix3 const __near *,class IVP_U_Matrix3 __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::mmult3(IVP_U_Matrix3 *this, const IVP_U_Matrix3 *mb, IVP_U_Matrix3 *m_out)
{
  IVP_U_Matrix3::inline_mmult3(this, mb, m_out);
}

//------------------------------------------------------------------------------
// Address: 0x10071E50
// Name: public: void IVP_U_Matrix3::mimult3(class IVP_U_Matrix3 const __near *,class IVP_U_Matrix3 __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::mimult3(IVP_U_Matrix3 *this, const IVP_U_Matrix3 *mb, IVP_U_Matrix3 *m_out)
{
  IVP_U_Matrix3::inline_mimult3(this, mb, m_out);
}

//------------------------------------------------------------------------------
// Address: 0x10071E60
// Name: public: void IVP_U_Matrix3::mi2mult3(class IVP_U_Matrix3 const __near *,class IVP_U_Matrix3 __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::mi2mult3(IVP_U_Matrix3 *this, const IVP_U_Matrix3 *mb, IVP_U_Matrix3 *m_out)
{
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // [esp-4h] [ebp-54h]
  float row_4; // [esp+4h] [ebp-4Ch]
  float row_8; // [esp+8h] [ebp-48h]
  float row_12; // [esp+Ch] [ebp-44h]
  float row_36; // [esp+24h] [ebp-2Ch]
  float row_40; // [esp+28h] [ebp-28h]
  float v18; // [esp+30h] [ebp-20h]
  float v19; // [esp+34h] [ebp-1Ch]
  float v20; // [esp+38h] [ebp-18h]
  float v21; // [esp+3Ch] [ebp-14h]
  float v22; // [esp+40h] [ebp-10h]

  v3 = mb->rows[1].k[0];
  v4 = (float)((float)(this->rows[0].k[0] * v3) + (float)(this->rows[0].k[1] * mb->rows[1].k[1]))
     + (float)(this->rows[0].k[2] * mb->rows[1].k[2]);
  v20 = mb->rows[2].k[1];
  v21 = mb->rows[1].k[2];
  v5 = mb->rows[2].k[0];
  v6 = this->rows[1].k[2];
  v12 = (float)((float)(this->rows[0].k[0] * v5) + (float)(this->rows[0].k[1] * v20))
      + (float)(this->rows[0].k[2] * mb->rows[2].k[2]);
  v18 = mb->rows[0].k[1];
  v19 = mb->rows[2].k[2];
  v7 = this->rows[1].k[1];
  row_40 = mb->rows[0].k[2];
  row_4 = (float)((float)(v7 * v18) + (float)(this->rows[1].k[0] * mb->rows[0].k[0])) + (float)(v6 * row_40);
  row_36 = mb->rows[1].k[1];
  v8 = this->rows[2].k[2];
  row_8 = (float)((float)(v7 * row_36) + (float)(v3 * this->rows[1].k[0])) + (float)(v6 * v21);
  v9 = (float)((float)(v7 * v20) + (float)(v5 * this->rows[1].k[0])) + (float)(v6 * v19);
  v10 = this->rows[2].k[1];
  row_12 = v9;
  v22 = this->rows[2].k[0];
  v11 = (float)((float)(v10 * v18) + (float)(v22 * mb->rows[0].k[0])) + (float)(v8 * row_40);
  m_out->rows[0].k[0] = (float)((float)(this->rows[0].k[0] * mb->rows[0].k[0]) + (float)(this->rows[0].k[1] * v18))
                      + (float)(this->rows[0].k[2] * row_40);
  m_out->rows[0].k[1] = v4;
  m_out->rows[0].k[2] = v12;
  m_out->rows[1].k[0] = row_4;
  m_out->rows[1].k[1] = row_8;
  m_out->rows[1].k[2] = row_12;
  m_out->rows[2].k[0] = v11;
  m_out->rows[2].k[1] = (float)((float)(v10 * row_36) + (float)(v3 * v22)) + (float)(v8 * v21);
  m_out->rows[2].k[2] = (float)((float)(v10 * v20) + (float)(v5 * v22)) + (float)(v8 * v19);
}

//------------------------------------------------------------------------------
// Address: 0x10072080
// Name: public: void IVP_U_Matrix3::transpose3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::transpose3(IVP_U_Matrix3 *this)
{
  int v1; // edi
  float *k; // edx
  float *v3; // eax
  int i; // esi
  float v5; // xmm0_4
  IVP_U_Point *v6; // [esp+Ch] [ebp-4h]

  v1 = 1;
  v6 = &this->rows[1];
  do
  {
    if ( v1 > 0 )
    {
      k = this->rows[v1].k;
      v3 = (float *)((char *)this + 4 * v1);
      for ( i = v1; i != 0; --i )
      {
        v5 = *k;
        *k = *v3;
        *v3 = v5;
        v3 += 4;
        ++k;
      }
    }
    ++v1;
    ++v6;
  }
  while ( v1 < 3 );
}

//------------------------------------------------------------------------------
// Address: 0x10072140
// Name: public: void IVP_U_Matrix3::set_transpose3(class IVP_U_Matrix3 const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::set_transpose3(IVP_U_Matrix3 *this, const IVP_U_Matrix3 *in)
{
  const IVP_U_Matrix3 *v3; // ecx
  int v4; // ebx
  int v5; // edi
  int v6; // ecx
  float *k; // esi
  _DWORD *v8; // edx
  int v9; // xmm0_4
  float *v10; // [esp+10h] [ebp-14h]
  float *v11; // [esp+1Ch] [ebp-8h]

  v3 = in;
  this->rows[0].k[0] = in->rows[0].k[0];
  this->rows[1].k[1] = in->rows[1].k[1];
  v4 = 1;
  this->rows[2].k[2] = in->rows[2].k[2];
  v11 = &this->rows[1].k[1];
  v10 = &in->rows[1].k[2];
  do
  {
    if ( v4 > 0 )
    {
      v5 = (char *)v3 - (char *)this;
      v6 = v4;
      k = this->rows[v4].k;
      v8 = (_DWORD *)((char *)this + 4 * v4);
      do
      {
        v9 = *(_DWORD *)((char *)k + v5);
        *k = *(float *)((char *)v8 + v5);
        *v8 = v9;
        v8 += 4;
        ++k;
        --v6;
      }
      while ( v6 != 0 );
      v3 = in;
    }
    v11 += 4;
    ++v4;
    v10 += 4;
  }
  while ( v4 < 3 );
}

//------------------------------------------------------------------------------
// Address: 0x10072250
// Name: public: void IVP_U_Matrix::vimult4(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix::vimult4(IVP_U_Matrix *this, const IVP_U_Float_Point *p_in, IVP_U_Float_Point *p_out)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v3 = p_in->k[0] - this->vv.k[0];
  v4 = p_in->k[1] - this->vv.k[1];
  v5 = p_in->k[2] - this->vv.k[2];
  p_out->k[0] = (float)((float)(this->rows[1].k[0] * v4) + (float)(this->rows[0].k[0] * v3))
              + (float)(this->rows[2].k[0] * v5);
  p_out->k[1] = (float)((float)(this->rows[1].k[1] * v4) + (float)(this->rows[0].k[1] * v3))
              + (float)(this->rows[2].k[1] * v5);
  p_out->k[2] = (float)((float)(this->rows[1].k[2] * v4) + (float)(this->rows[0].k[2] * v3))
              + (float)(this->rows[2].k[2] * v5);
}

//------------------------------------------------------------------------------
// Address: 0x100722F0
// Name: public: void IVP_U_Matrix::vmult4(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix::vmult4(IVP_U_Matrix *this, const IVP_U_Float_Point *p_in, IVP_U_Float_Point *p_out)
{
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4

  v3 = p_in->k[1];
  v4 = (float)(this->rows[0].k[1] * v3) + (float)(this->rows[0].k[0] * p_in->k[0]);
  v5 = (float)(this->rows[1].k[1] * v3) + (float)(this->rows[1].k[0] * p_in->k[0]);
  v6 = this->rows[2].k[1] * v3;
  v7 = p_in->k[2];
  v8 = (float)(this->rows[0].k[2] * v7) + v4;
  v9 = (float)((float)(this->rows[1].k[2] * v7) + v5) + this->vv.k[1];
  v10 = (float)((float)(this->rows[2].k[2] * v7) + (float)(v6 + (float)(this->rows[2].k[0] * p_in->k[0])))
      + this->vv.k[2];
  p_out->k[0] = this->vv.k[0] + v8;
  p_out->k[1] = v9;
  p_out->k[2] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x100723A0
// Name: public: void IVP_U_Matrix3::vmult3(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::vmult3(IVP_U_Matrix3 *this, const IVP_U_Float_Point *p_in, IVP_U_Float_Point *p_out)
{
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  v3 = p_in->k[1];
  v4 = p_in->k[2];
  v5 = (float)((float)(this->rows[1].k[0] * p_in->k[0]) + (float)(this->rows[1].k[1] * v3))
     + (float)(this->rows[1].k[2] * v4);
  v6 = (float)((float)(this->rows[2].k[0] * p_in->k[0]) + (float)(this->rows[2].k[1] * v3))
     + (float)(this->rows[2].k[2] * v4);
  p_out->k[0] = (float)((float)(this->rows[0].k[1] * v3) + (float)(p_in->k[0] * this->rows[0].k[0]))
              + (float)(this->rows[0].k[2] * v4);
  p_out->k[1] = v5;
  p_out->k[2] = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10072430
// Name: public: void IVP_U_Matrix3::vimult3(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix3::vimult3(IVP_U_Matrix3 *this, const IVP_U_Float_Point *p_in, IVP_U_Float_Point *p_out)
{
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  v3 = p_in->k[1];
  v4 = p_in->k[2];
  v5 = (float)((float)(this->rows[0].k[1] * p_in->k[0]) + (float)(this->rows[1].k[1] * v3))
     + (float)(this->rows[2].k[1] * v4);
  v6 = (float)((float)(this->rows[0].k[2] * p_in->k[0]) + (float)(this->rows[1].k[2] * v3))
     + (float)(this->rows[2].k[2] * v4);
  p_out->k[0] = (float)((float)(this->rows[1].k[0] * v3) + (float)(p_in->k[0] * this->rows[0].k[0]))
              + (float)(this->rows[2].k[0] * v4);
  p_out->k[1] = v5;
  p_out->k[2] = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100724C0
// Name: public: void IVP_U_Matrix::shift_os(class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix::shift_os(IVP_U_Matrix *this, const IVP_U_Point *v_in)
{
  float v2; // xmm3_4
  float v3; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4

  v2 = v_in->k[1];
  v3 = v_in->k[2];
  v4 = (float)((float)(this->rows[1].k[0] * v_in->k[0]) + (float)(this->rows[1].k[1] * v2))
     + (float)(this->rows[1].k[2] * v3);
  v5 = (float)((float)(this->rows[2].k[0] * v_in->k[0]) + (float)(this->rows[2].k[1] * v2))
     + (float)(this->rows[2].k[2] * v3);
  v6 = this->vv.k[0]
     + (float)((float)((float)(this->rows[0].k[1] * v2) + (float)(v_in->k[0] * this->rows[0].k[0]))
             + (float)(this->rows[0].k[2] * v3));
  this->vv.k[1] = this->vv.k[1] + v4;
  v7 = this->vv.k[2] + v5;
  this->vv.k[0] = v6;
  this->vv.k[2] = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10072570
// Name: public: void IVP_U_Point::calc_an_orthogonal(class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Point::calc_an_orthogonal(IVP_U_Point *this, const IVP_U_Point *ip)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  int v5; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  int v9; // esi
  float v10; // xmm3_4
  float v11; // xmm0_4

  v2 = ip->k[1];
  v3 = ip->k[2];
  this->k[0] = ip->k[0];
  this->k[1] = v2;
  this->k[2] = v3;
  v4 = 0.0;
  v5 = 0;
  v6 = fabs(this->k[2]);
  if ( v6 > 0.0 )
  {
    v4 = v6;
    v5 = 2;
  }
  v7 = fabs(this->k[1]);
  if ( v7 > v4 )
  {
    v4 = v7;
    v5 = 1;
  }
  if ( fabs(this->k[0]) > v4 )
    v5 = 0;
  v8 = this->k[v5] * -1.0;
  v9 = v5 - 1;
  this->k[v5] = v8;
  if ( v5 - 1 < 0 )
    v9 = 2;
  this->k[v5] = this->k[v9];
  this->k[v9] = v8;
  v10 = (float)(this->k[2] * ip->k[0]) - (float)(ip->k[2] * this->k[0]);
  v11 = (float)(this->k[0] * ip->k[1]) - (float)(this->k[1] * ip->k[0]);
  this->k[0] = (float)(ip->k[2] * this->k[1]) - (float)(this->k[2] * ip->k[1]);
  this->k[1] = v10;
  this->k[2] = v11;
}

//------------------------------------------------------------------------------
// Address: 0x10072650
// Name: public: enum IVP_RETURN_TYPE IVP_U_Matrix::real_invert(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_U_Matrix::real_invert(IVP_U_Matrix *this, float epsilon)
{
  float v2; // xmm5_4
  float v3; // xmm4_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float r0_4; // [esp+4h] [ebp-3Ch]
  float r0_8; // [esp+8h] [ebp-38h]
  float r0_12; // [esp+Ch] [ebp-34h]
  float r1_4; // [esp+14h] [ebp-2Ch]
  float r1_4a; // [esp+14h] [ebp-2Ch]
  float r1_8; // [esp+18h] [ebp-28h]

  v2 = this->rows[0].k[2];
  v3 = this->rows[2].k[1];
  v4 = (float)(this->rows[2].k[2] * this->rows[1].k[1]) - (float)(v3 * this->rows[1].k[2]);
  v5 = this->rows[2].k[0];
  v6 = (float)(this->rows[1].k[0] * v3) - (float)(v5 * this->rows[1].k[1]);
  v7 = (float)(v5 * this->rows[1].k[2]) - (float)(this->rows[1].k[0] * this->rows[2].k[2]);
  v8 = this->rows[0].k[1];
  r0_4 = (float)(v2 * v3) - (float)(v8 * this->rows[2].k[2]);
  r0_8 = (float)(this->rows[0].k[0] * this->rows[2].k[2]) - (float)(v2 * this->rows[2].k[0]);
  r0_12 = (float)(v8 * this->rows[2].k[0]) - (float)(this->rows[0].k[0] * v3);
  r1_4 = (float)(v8 * this->rows[1].k[2]) - (float)(v2 * this->rows[1].k[1]);
  r1_8 = (float)(v2 * this->rows[1].k[0]) - (float)(this->rows[0].k[0] * this->rows[1].k[2]);
  v9 = (float)(this->rows[0].k[0] * this->rows[1].k[1]) - (float)(v8 * this->rows[1].k[0]);
  v10 = (float)((float)(this->rows[0].k[0] * v4) + (float)(v8 * v7)) + (float)(v2 * v6);
  if ( epsilon > COERCE_FLOAT(LODWORD(v10) & _mask__AbsFloat_) )
    return 0;
  v12 = 1.0 / v10;
  v13 = v4 * (float)(1.0 / v10);
  v14 = v6 * (float)(1.0 / v10);
  this->rows[2].k[0] = v14;
  this->rows[1].k[1] = r0_8 * (float)(1.0 / v10);
  this->rows[0].k[0] = v13;
  v15 = v9 * (float)(1.0 / v10);
  this->rows[2].k[1] = r0_12 * (float)(1.0 / v10);
  this->rows[2].k[2] = v15;
  this->rows[0].k[1] = r0_4 * (float)(1.0 / v10);
  r1_4a = r1_4 * (float)(1.0 / v10);
  this->rows[1].k[0] = v7 * (float)(1.0 / v10);
  this->rows[0].k[2] = r1_4a;
  this->rows[1].k[2] = r1_8 * (float)(1.0 / v10);
  v16 = (float)((float)((float)(r0_8 * v12) * this->vv.k[1]) + (float)(this->vv.k[0] * (float)(v7 * v12)))
      + (float)((float)(r1_8 * v12) * this->vv.k[2]);
  v17 = (float)((float)(v14 * this->vv.k[0]) + (float)((float)(r0_12 * v12) * this->vv.k[1]))
      + (float)(v15 * this->vv.k[2]);
  this->vv.k[0] = -(float)((float)((float)(this->vv.k[1] * (float)(r0_4 * v12)) + (float)(this->vv.k[0] * v13))
                         + (float)(this->vv.k[2] * r1_4a));
  this->vv.k[1] = -v16;
  this->vv.k[2] = -v17;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100728D0
// Name: public: void IVP_U_Matrix3::init_normized3_col(class IVP_U_Point const __near *,enum IVP_COORDINATE_INDEX,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_U_Matrix3::init_normized3_col(
        IVP_U_Matrix3 *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Point *vb,
        IVP_COORDINATE_INDEX index_b,
        const IVP_U_Point *vc)
{
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm3_4
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-Ch] [ebp-30h]
  _DWORD v21[2]; // [esp-8h] [ebp-2Ch]
  _BYTE p[32]; // [esp+0h] [ebp-24h] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+24h] [ebp+0h]

  *(_DWORD *)&p[24] = a2;
  *(_DWORD *)&p[28] = retaddr;
  *(IVP_U_Point *)&p[8] = *vb;
  v5 = *(float *)&p[8];
  v6 = *(float *)&p[12];
  v7 = *(float *)&p[16];
  v8 = (float)((float)(v5 * v5) + (float)(v6 * v6)) + (float)(v7 * v7);
  if ( v8 >= 1.0e-10 )
  {
    v9 = 1.0 / fsqrt(v8);
    v5 = *(float *)&p[8] * v9;
    v6 = v9 * *(float *)&p[12];
    v7 = *(float *)&p[16] * v9;
  }
  v10 = vc->k[2];
  v11 = v10 * v5;
  v12 = (float)(v10 * v6) - (float)(vc->k[1] * v7);
  v13 = (float)(vc->k[0] * v7) - v11;
  v14 = (float)(vc->k[1] * v5) - (float)(vc->k[0] * v6);
  v15 = (float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v15 >= 1.0e-10 )
  {
    v16 = 1.0 / fsqrt(v15);
    v12 = v12 * v16;
    v13 = v13 * v16;
    v14 = v14 * v16;
  }
  v20 = 0;
  *(_DWORD *)p = 0;
  *(float *)&p[8] = (float)(v13 * v7) - (float)(v14 * v6);
  v21[0] = 1;
  v21[1] = 2;
  *(_DWORD *)&p[4] = 1;
  v17 = v21[index_b - 1];
  this->rows[0].k[v17] = v5;
  this->rows[1].k[v17] = v6;
  this->rows[2].k[v17] = v7;
  v18 = v21[index_b];
  *(float *)&p[12] = (float)(v14 * v5) - (float)(v12 * v7);
  this->rows[0].k[v18] = *(float *)&p[8];
  this->rows[1].k[v18] = *(float *)&p[12];
  this->rows[2].k[v18] = (float)(v12 * v6) - (float)(v13 * v5);
  v19 = *(_DWORD *)&p[4 * index_b - 4];
  this->rows[0].k[v19] = v12;
  this->rows[1].k[v19] = v13;
  this->rows[2].k[v19] = v14;
}

//------------------------------------------------------------------------------
// Address: 0x10072A90
// Name: public: void IVP_U_Matrix::mmult4(class IVP_U_Matrix const __near *,class IVP_U_Matrix __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix::mmult4(IVP_U_Matrix *this, const IVP_U_Matrix *mb, IVP_U_Matrix *m_out)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // [esp-10h] [ebp-1Ch]
  float v10; // [esp-Ch] [ebp-18h]
  float v11; // [esp-8h] [ebp-14h]

  v3 = mb->vv.k[0];
  v4 = mb->vv.k[1];
  v5 = mb->vv.k[2];
  v9 = (float)((float)(this->rows[0].k[1] * v4) + (float)(v3 * this->rows[0].k[0])) + (float)(this->rows[0].k[2] * v5);
  v10 = (float)((float)(this->rows[1].k[0] * v3) + (float)(this->rows[1].k[1] * v4)) + (float)(this->rows[1].k[2] * v5);
  v11 = (float)((float)(this->rows[2].k[0] * v3) + (float)(this->rows[2].k[1] * v4)) + (float)(this->rows[2].k[2] * v5);
  IVP_U_Matrix3::inline_mmult3(this, mb, m_out);
  v7 = this->vv.k[1] + v10;
  v8 = this->vv.k[2] + v11;
  m_out->vv.k[0] = this->vv.k[0] + v9;
  m_out->vv.k[1] = v7;
  m_out->vv.k[2] = v8;
}

//------------------------------------------------------------------------------
// Address: 0x10072B80
// Name: public: void IVP_U_Matrix::mimult4(class IVP_U_Matrix const __near *,class IVP_U_Matrix __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix::mimult4(IVP_U_Matrix *this, const IVP_U_Matrix *mb, IVP_U_Matrix *m_out)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // [esp+0h] [ebp-4h]
  float mba; // [esp+Ch] [ebp+8h]

  v4 = mb->vv.k[0] - this->vv.k[0];
  v5 = mb->vv.k[1] - this->vv.k[1];
  v6 = mb->vv.k[2] - this->vv.k[2];
  mba = this->rows[2].k[1];
  v9 = this->rows[2].k[2];
  v7 = (float)(this->rows[0].k[1] * v4) + (float)(this->rows[1].k[1] * v5);
  v8 = (float)(this->rows[0].k[2] * v4) + (float)(this->rows[1].k[2] * v5);
  m_out->vv.k[0] = (float)((float)(this->rows[1].k[0] * v5) + (float)(this->rows[0].k[0] * v4))
                 + (float)(this->rows[2].k[0] * v6);
  m_out->vv.k[1] = v7 + (float)(mba * v6);
  m_out->vv.k[2] = v8 + (float)(v9 * v6);
  IVP_U_Matrix3::inline_mimult3(this, mb, m_out);
}

//------------------------------------------------------------------------------
// Address: 0x10072C50
// Name: public: void IVP_U_Matrix::mi2mult4(class IVP_U_Matrix const __near *,class IVP_U_Matrix __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix::mi2mult4(IVP_U_Matrix *this, const IVP_U_Matrix *mb, IVP_U_Matrix *m_out)
{
  float v3; // xmm4_4
  float v4; // xmm3_4
  float v5; // xmm5_4
  float *v6; // edx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float *v11; // ecx
  float v12; // xmm3_4
  float v13; // xmm1_4

  IVP_U_Matrix3::mi2mult3(this, mb, m_out);
  v3 = mb->vv.k[0];
  v4 = mb->vv.k[1];
  v5 = mb->vv.k[2];
  v7 = (float)((float)(v6[1] * v4) + (float)(v3 * *v6)) + (float)(v6[2] * v5);
  v8 = (float)((float)(v6[4] * v3) + (float)(v6[5] * v4)) + (float)(v6[6] * v5);
  v9 = v6[8] * v3;
  v10 = v6[9] * v4;
  v12 = v11[13] - v8;
  v13 = v11[14] - (float)((float)(v9 + v10) + (float)(v6[10] * v5));
  v6[12] = v11[12] - v7;
  v6[13] = v12;
  v6[14] = v13;
}

//------------------------------------------------------------------------------
// Address: 0x10072D10
// Name: public: void IVP_U_Matrix::set_transpose(class IVP_U_Matrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix::set_transpose(IVP_U_Matrix *this, const IVP_U_Matrix *in)
{
  const IVP_U_Matrix *v2; // esi
  int v3; // eax
  float *k; // esi
  _DWORD *v5; // edx
  int v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float *v11; // [esp+10h] [ebp-18h]
  int v12; // [esp+18h] [ebp-10h]
  float *v13; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+24h] [ebp-4h]

  v2 = in;
  this->rows[0].k[0] = in->rows[0].k[0];
  v3 = 1;
  this->rows[1].k[1] = in->rows[1].k[1];
  this->rows[2].k[2] = in->rows[2].k[2];
  v11 = &this->rows[1].k[1];
  v13 = &in->rows[1].k[2];
  do
  {
    if ( v3 > 0 )
    {
      v14 = (char *)v2 - (char *)this;
      v12 = v3;
      k = this->rows[v3].k;
      v5 = (_DWORD *)this + v3;
      do
      {
        v6 = *(_DWORD *)((char *)k + v14);
        *k = *(float *)((char *)v5 + v14);
        *v5 = v6;
        v5 += 4;
        ++k;
        --v12;
      }
      while ( v12 != 0 );
      v2 = in;
    }
    v13 += 4;
    ++v3;
    v11 += 4;
  }
  while ( v3 < 3 );
  v7 = v2->vv.k[1];
  v8 = v2->vv.k[2];
  v9 = (float)((float)(v2->vv.k[0] * this->rows[1].k[0]) + (float)(v7 * this->rows[1].k[1]))
     + (float)(this->rows[1].k[2] * v8);
  v10 = (float)((float)(this->rows[2].k[0] * v2->vv.k[0]) + (float)(this->rows[2].k[1] * v7))
      + (float)(this->rows[2].k[2] * v8);
  this->vv.k[0] = -(float)((float)((float)(this->rows[0].k[1] * v7) + (float)(v2->vv.k[0] * this->rows[0].k[0]))
                         + (float)(this->rows[0].k[2] * v8));
  this->vv.k[1] = -v9;
  this->vv.k[2] = -v10;
}

//------------------------------------------------------------------------------
// Address: 0x10072EE0
// Name: public: enum IVP_RETURN_TYPE IVP_U_Point::set_crossing(class IVP_U_Hesse __near *,class IVP_U_Hesse __near *,class IVP_U_Hesse __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_RETURN_TYPE __userpurge IVP_U_Point::set_crossing@<eax>(
        IVP_U_Point *this@<ecx>,
        float a2@<ebp>,
        IVP_U_Hesse *h0,
        IVP_U_Hesse *h1,
        IVP_U_Hesse *h2)
{
  IVP_RETURN_TYPE result; // eax
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float *v10; // edx
  float v11; // [esp+14h] [ebp-4Ch] BYREF
  float v12; // [esp+18h] [ebp-48h]
  float v13; // [esp+1Ch] [ebp-44h]
  IVP_U_Matrix lin_equ_matrix; // [esp+20h] [ebp-40h] BYREF
  float retaddr; // [esp+60h] [ebp+0h]

  lin_equ_matrix.vv.k[1] = a2;
  lin_equ_matrix.vv.k[2] = retaddr;
  v11 = h0->k[0];
  v12 = h0->k[1];
  v13 = h0->k[2];
  lin_equ_matrix.rows[0].k[1] = h1->k[0];
  lin_equ_matrix.rows[0].k[2] = h1->k[1];
  lin_equ_matrix.rows[0].hesse_val = h1->k[2];
  lin_equ_matrix.rows[1].k[1] = h2->k[0];
  lin_equ_matrix.rows[1].k[2] = h2->k[1];
  lin_equ_matrix.rows[1].hesse_val = h2->k[2];
  memset(&lin_equ_matrix.rows[2].k[1], 0, 12);
  result = IVP_U_Matrix::real_invert(this: (IVP_U_Matrix *)&v11, epsilon: 1.0e-10);
  v6 = -h0->hesse_val;
  v7 = -h2->hesse_val;
  v8 = -h1->hesse_val;
  v9 = lin_equ_matrix.rows[0].k[1];
  *v10 = (float)((float)(v12 * v8) + (float)(v11 * v6)) + (float)(v7 * v13);
  v10[1] = (float)((float)(lin_equ_matrix.rows[0].k[2] * v8) + (float)(v9 * v6))
         + (float)(lin_equ_matrix.rows[0].hesse_val * v7);
  v10[2] = (float)((float)(lin_equ_matrix.rows[1].k[2] * v8) + (float)(lin_equ_matrix.rows[1].k[1] * v6))
         + (float)(lin_equ_matrix.rows[1].hesse_val * v7);
  return result;
}
