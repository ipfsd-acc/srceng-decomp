// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_geometry.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_utility\ivu_geometry.h"

//------------------------------------------------------------------------------
// Address: 0x1008DBC0
// Name: public: enum IVP_RETURN_TYPE IVP_U_Hesse::calc_intersect_with(class IVP_U_Straight const __near *,class IVP_U_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_U_Hesse::calc_intersect_with(
        IVP_U_Hesse *this,
        const IVP_U_Straight *straight,
        IVP_U_Point *point_out)
{
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float hp_8; // [esp+8h] [ebp-18h]
  float hp_12; // [esp+Ch] [ebp-14h]
  float v15; // [esp+10h] [ebp-10h]

  v3 = this->k[1];
  v4 = this->k[2];
  v15 = straight->start_point.k[1];
  hp_8 = straight->start_point.k[0];
  hp_12 = straight->start_point.k[2];
  v5 = (float)((float)((float)(hp_8 * this->k[0]) + (float)(v15 * v3)) + (float)(hp_12 * v4)) + this->hesse_val;
  v6 = straight->vec.k[1];
  v7 = straight->vec.k[2];
  v8 = (float)((float)((float)((float)(v3 * (float)(v6 + v15)) + (float)(this->k[0] * (float)(straight->vec.k[0] + hp_8)))
                     + (float)(v4 * (float)(v7 + hp_12)))
             + this->hesse_val)
     - v5;
  if ( COERCE_FLOAT(LODWORD(v8) & _mask__AbsFloat_) >= 1.0e-10 )
  {
    LODWORD(v12) = COERCE_UNSIGNED_INT(v5 / v8) ^ _mask__NegFloat_;
    point_out->k[0] = (float)(straight->vec.k[0] * v12) + hp_8;
    point_out->k[1] = (float)(v6 * v12) + v15;
    point_out->k[2] = (float)(v7 * v12) + hp_12;
    return 1;
  }
  else if ( v5 < 1.0e-10 )
  {
    *point_out = straight->start_point;
    v10 = straight->start_point.k[1];
    v11 = straight->start_point.k[2];
    point_out->k[0] = straight->start_point.k[0];
    point_out->k[1] = v10;
    point_out->k[2] = v11;
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DD40
// Name: public: IVP_U_Plain::IVP_U_Plain(class IVP_U_Hesse const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Plain *__userpurge IVP_U_Plain::IVP_U_Plain@<eax>(
        IVP_U_Plain *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Hesse *i_hesse)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  _BYTE v7[12]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Point hp; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  hp.k[1] = a2;
  hp.k[2] = retaddr;
  v3 = i_hesse->k[1];
  v4 = i_hesse->k[2];
  this->k[0] = i_hesse->k[0];
  this->k[1] = v3;
  this->k[2] = v4;
  this->hesse_val = i_hesse->hesse_val;
  memset(v7, 0, sizeof(v7));
  IVP_U_Hesse::proj_on_plane((IVP_U_Float_Hesse *)this, p: (const IVP_U_Float_Point *)v7, result: &this->start_point);
  IVP_U_Point::calc_an_orthogonal(this: &this->vec1, ip: this);
  IVP_U_Float_Point::calc_cross_product(this: &this->vec2, v1: &this->vec1, v2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DDD0
// Name: public: enum IVP_RETURN_TYPE IVP_U_Plain::calc_intersect_with(class IVP_U_Hesse const __near *,class IVP_U_Straight __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge IVP_U_Plain::calc_intersect_with@<eax>(
        IVP_U_Plain *this@<ecx>,
        float a2@<ebp>,
        IVP_U_Hesse *plane2,
        IVP_U_Straight *straight_out)
{
  float v6[3]; // [esp+14h] [ebp-4Ch] BYREF
  IVP_U_Straight straight; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Point hp; // [esp+40h] [ebp-20h] BYREF
  IVP_U_Point hp2; // [esp+50h] [ebp-10h]
  float retaddr; // [esp+60h] [ebp+0h]

  hp2.k[1] = a2;
  hp2.k[2] = retaddr;
  if ( IVP_U_Point::is_parallel(this, v_in: plane2, eps: 9.9999997e-10) )
    return false;
  IVP_U_Float_Point::calc_cross_product(this: &straight_out->vec, v1: this, v2: plane2);
  IVP_U_Float_Point::fast_normize(this: &straight_out->vec);
  IVP_U_Hesse::proj_on_plane(
    this: (IVP_U_Float_Hesse *)plane2,
    p: &this->start_point,
    result: (IVP_U_Float_Point *)&straight.start_point.k[1]);
  IVP_U_Hesse::proj_on_plane(
    (IVP_U_Float_Hesse *)this,
    p: (const IVP_U_Float_Point *)&straight.start_point.k[1],
    result: (IVP_U_Point *)&hp.k[1]);
  *(_QWORD *)&straight.vec.k[1] = *(_QWORD *)this->start_point.k;
  *(_QWORD *)&straight.vec.hesse_val = *(_QWORD *)&this->start_point.k[2];
  v6[0] = hp.k[1] - this->start_point.k[0];
  v6[1] = hp.k[2] - this->start_point.k[1];
  v6[2] = hp.hesse_val - this->start_point.k[2];
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)v6);
  return IVP_U_Hesse::calc_intersect_with(
           this: plane2,
           straight: (const IVP_U_Straight *)v6,
           point_out: &straight_out->start_point) != 0;
}
