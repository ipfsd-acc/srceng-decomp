// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_mindist_event.cxx
// Functions: 23
// ============================================================

#include "ivp\ivp_collision\ivp_mindist_event.h"

//------------------------------------------------------------------------------
// Address: 0x100974C0
// Name: private: void IVP_U_Matrix_Cache::p_init(class IVP_Cache_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Matrix_Cache::p_init(IVP_U_Matrix_Cache *this, IVP_Cache_Object *co)
{
  IVP_Real_Object *object; // eax
  IVP_Real_Object *v3; // edx
  bool v4; // cc
  int v5; // eax
  IVP_U_Matrix **v6; // edx

  object = co->object;
  this->object = object;
  v3 = this->object;
  this->core = object->physical_core;
  v4 = *(_BYTE *)&v3->flags < 8;
  v5 = 20;
  v6 = &this->m_world_f_object[20];
  if ( v4 )
  {
    do
    {
      *v6 = nullptr;
      --v5;
      --v6;
    }
    while ( v5 > 0 );
    this->m_world_f_object[0] = &co->m_world_f_object;
    this->base_time_code = co->valid_until_time_code;
  }
  else
  {
    do
    {
      *v6-- = &co->m_world_f_object;
      --v5;
    }
    while ( v5 >= 0 );
    this->base_time_code = co->valid_until_time_code;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097530
// Name: public: virtual float IVP_3D_Solver_PF_COLL::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge IVP_3D_Solver_PF_COLL::get_value@<st0>(
        IVP_3D_Solver_PF_COLL *this@<ecx>,
        int a2@<ebp>,
        IVP_U_Matrix *A_w_f_c,
        IVP_U_Matrix *B_w_f_c)
{
  float v5; // xmm0_4
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  double v19; // st7
  float v20; // xmm0_4
  IVP_U_Point point_minus_area_world; // [esp+0h] [ebp-50h] BYREF
  IVP_U_Point hesse_of_area_world; // [esp+20h] [ebp-30h]
  float v24; // [esp+30h] [ebp-20h]
  float v25; // [esp+34h] [ebp-1Ch]
  float v26; // [esp+38h] [ebp-18h]
  float v27; // [esp+3Ch] [ebp-14h]
  float v28; // [esp+40h] [ebp-10h]
  int v29; // [esp+44h] [ebp-Ch]
  void *v30; // [esp+48h] [ebp-8h]
  void *retaddr; // [esp+50h] [ebp+0h]

  v29 = a2;
  v30 = retaddr;
  IVP_U_Matrix::vmult4(this: A_w_f_c, p_in: &this->point_object, p_out: (IVP_U_Point *)&point_minus_area_world.k[1]);
  v5 = this->point_of_area_object.k[0];
  v6 = this->point_of_area_object.k[1];
  v7 = B_w_f_c->rows[1].k[1];
  v8 = B_w_f_c->rows[2].k[0];
  v9 = B_w_f_c->rows[0].k[0] * v5;
  v26 = B_w_f_c->rows[1].k[0];
  v27 = v7;
  v10 = (float)(v7 * v6) + (float)(v26 * v5);
  v11 = B_w_f_c->rows[2].k[1];
  hesse_of_area_world.hesse_val = v8;
  v12 = v8 * v5;
  v13 = (float)(B_w_f_c->rows[0].k[1] * v6) + v9;
  v14 = B_w_f_c->rows[0].k[2];
  v24 = v11;
  v15 = (float)(v11 * v6) + v12;
  v16 = this->point_of_area_object.k[2];
  v28 = v14;
  v17 = B_w_f_c->vv.k[0] + (float)((float)(v14 * v16) + v13);
  v25 = B_w_f_c->rows[1].k[2];
  v18 = (float)((float)(v25 * v16) + v10) + B_w_f_c->vv.k[1];
  v19 = point_minus_area_world.k[1] - v17;
  v20 = this->hesse_of_area_object.k[1];
  hesse_of_area_world.k[2] = B_w_f_c->rows[2].k[2];
  return v19
       * (float)((float)((float)(v20 * B_w_f_c->rows[0].k[1])
                       + (float)(this->hesse_of_area_object.k[0] * B_w_f_c->rows[0].k[0]))
               + (float)(this->hesse_of_area_object.k[2] * v28))
       + (float)(point_minus_area_world.k[2] - v18)
       * (float)((float)((float)(v20 * v27) + (float)(this->hesse_of_area_object.k[0] * v26))
               + (float)(this->hesse_of_area_object.k[2] * v25))
       + (float)(point_minus_area_world.hesse_val
               - (float)((float)((float)(hesse_of_area_world.k[2] * v16) + v15) + B_w_f_c->vv.k[2]))
       * (float)((float)((float)(v20 * v24) + (float)(this->hesse_of_area_object.k[0] * hesse_of_area_world.hesse_val))
               + (float)(this->hesse_of_area_object.k[2] * hesse_of_area_world.k[2]));
}

//------------------------------------------------------------------------------
// Address: 0x100976D0
// Name: public: virtual float IVP_3D_Solver_VEC_PARALLEL_AREA::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge IVP_3D_Solver_VEC_PARALLEL_AREA::get_value@<st0>(
        IVP_3D_Solver_VEC_PARALLEL_AREA *this@<ecx>,
        float a2@<ebp>,
        IVP_U_Matrix *A_w_f_c,
        IVP_U_Matrix *B_w_f_c)
{
  float v6[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Point vec_world; // [esp+0h] [ebp-20h] BYREF
  IVP_U_Point hesse_of_area_world; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  hesse_of_area_world.k[1] = a2;
  hesse_of_area_world.k[2] = retaddr;
  IVP_U_Matrix3::vmult3(this: A_w_f_c, p_in: &this->vec_object, p_out: (IVP_U_Float_Point *)v6);
  IVP_U_Matrix3::vmult3(this: B_w_f_c, p_in: &this->hesse_of_area_object, p_out: (IVP_U_Point *)&vec_world.k[1]);
  return vec_world.k[1] * v6[0] + v6[1] * vec_world.k[2] + vec_world.hesse_val * v6[2];
}

//------------------------------------------------------------------------------
// Address: 0x10097730
// Name: public: virtual float IVP_3D_Solver_DISTANCE_OF_TWO_POINTS::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
long double __userpurge IVP_3D_Solver_DISTANCE_OF_TWO_POINTS::get_value@<st0>(
        IVP_3D_Solver_DISTANCE_OF_TWO_POINTS *this@<ecx>,
        int a2@<ebp>,
        IVP_U_Matrix *A_w_f_c,
        IVP_U_Matrix *B_w_f_c)
{
  float v5; // xmm0_4
  float v7[3]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Point A_world; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Point B_world; // [esp+10h] [ebp-20h]
  float v10; // [esp+20h] [ebp-10h]
  int v11; // [esp+24h] [ebp-Ch]
  float res; // [esp+28h] [ebp-8h]
  float retaddr; // [esp+30h] [ebp+0h]

  v11 = a2;
  res = retaddr;
  IVP_U_Matrix::vmult4(this: A_w_f_c, p_in: &this->A_object, p_out: (IVP_U_Float_Point *)v7);
  IVP_U_Matrix::vmult4(this: B_w_f_c, p_in: &this->B_object, p_out: (IVP_U_Point *)&A_world.k[1]);
  v5 = (float)((float)((float)(this->normized_direction_world_at_t0.k[1] * (float)(A_world.k[2] - v7[1]))
                     + (float)(this->normized_direction_world_at_t0.k[0] * (float)(A_world.k[1] - v7[0])))
             + (float)(this->normized_direction_world_at_t0.k[2] * (float)(A_world.hesse_val - v7[2])))
     * 1.2;
  B_world.hesse_val = (float)((float)((float)(A_world.k[2] - v7[1]) * (float)(A_world.k[2] - v7[1]))
                            + (float)((float)(A_world.k[1] - v7[0]) * (float)(A_world.k[1] - v7[0])))
                    + (float)((float)(A_world.hesse_val - v7[2]) * (float)(A_world.hesse_val - v7[2]));
  v10 = v5;
  if ( B_world.hesse_val <= (float)(COERCE_FLOAT(LODWORD(v5) & _mask__AbsFloat_) * v5) )
    return sqrt(B_world.hesse_val);
  else
    return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10097810
// Name: public: virtual float IVP_3D_Solver_S_VALS::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge IVP_3D_Solver_S_VALS::get_value@<st0>(
        IVP_3D_Solver_S_VALS *this@<ecx>,
        float a2@<ebp>,
        IVP_U_Matrix *A_w_f_c,
        IVP_U_Matrix *B_w_f_c)
{
  float v6[3]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Point K_vec_world; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Point P_world; // [esp+10h] [ebp-20h] BYREF
  IVP_U_Point K_world; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  K_world.k[1] = a2;
  K_world.k[2] = retaddr;
  IVP_U_Matrix::vmult4(this: A_w_f_c, p_in: &this->P_object, p_out: (IVP_U_Point *)&K_vec_world.k[1]);
  IVP_U_Matrix::vmult4(this: B_w_f_c, p_in: &this->K_object, p_out: (IVP_U_Point *)&P_world.k[1]);
  IVP_U_Matrix3::vmult3(this: B_w_f_c, p_in: &this->K_vec_object, p_out: (IVP_U_Float_Point *)v6);
  return (P_world.hesse_val - K_vec_world.hesse_val) * v6[2]
       + (P_world.k[2] - K_vec_world.k[2]) * v6[1]
       + (P_world.k[1] - K_vec_world.k[1]) * v6[0];
}

//------------------------------------------------------------------------------
// Address: 0x10097890
// Name: public: virtual float IVP_3D_Solver_PK_KK::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge IVP_3D_Solver_PK_KK::get_value@<st0>(
        IVP_3D_Solver_PK_KK *this@<ecx>,
        float a2@<ebp>,
        IVP_U_Matrix *A_w_f_c,
        IVP_U_Matrix *B_w_f_c)
{
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v9[3]; // [esp-Ch] [ebp-5Ch] BYREF
  IVP_U_Point P_ne_vec_world; // [esp+0h] [ebp-50h] BYREF
  IVP_U_Point K_vec_world; // [esp+10h] [ebp-40h] BYREF
  IVP_U_Point K_world; // [esp+20h] [ebp-30h] BYREF
  IVP_U_Point P_world; // [esp+30h] [ebp-20h] BYREF
  IVP_U_Point Lot; // [esp+40h] [ebp-10h]
  float retaddr; // [esp+50h] [ebp+0h]

  Lot.k[1] = a2;
  Lot.k[2] = retaddr;
  IVP_U_Matrix::vmult4(this: A_w_f_c, p_in: &this->P_object, p_out: (IVP_U_Point *)&K_world.k[1]);
  IVP_U_Matrix3::vmult3(this: A_w_f_c, p_in: &this->P_ne_vec_object, p_out: (IVP_U_Float_Point *)v9);
  IVP_U_Matrix::vmult4(this: B_w_f_c, p_in: &this->K_object, p_out: (IVP_U_Point *)&K_vec_world.k[1]);
  IVP_U_Matrix3::vmult3(this: B_w_f_c, p_in: &this->K_vec_object, p_out: (IVP_U_Point *)&P_ne_vec_world.k[1]);
  v5 = (float)(P_ne_vec_world.k[2] * (float)(K_world.hesse_val - K_vec_world.hesse_val))
     - (float)(P_ne_vec_world.hesse_val * (float)(K_world.k[2] - K_vec_world.k[2]));
  v6 = (float)(P_ne_vec_world.hesse_val * (float)(K_world.k[1] - K_vec_world.k[1]))
     - (float)((float)(K_world.hesse_val - K_vec_world.hesse_val) * P_ne_vec_world.k[1]);
  v7 = (float)((float)(K_world.k[2] - K_vec_world.k[2]) * P_ne_vec_world.k[1])
     - (float)(P_ne_vec_world.k[2] * (float)(K_world.k[1] - K_vec_world.k[1]));
  P_world.k[1] = (float)(v6 * P_ne_vec_world.hesse_val) - (float)(v7 * P_ne_vec_world.k[2]);
  P_world.k[2] = (float)(v7 * P_ne_vec_world.k[1]) - (float)(P_ne_vec_world.hesse_val * v5);
  P_world.hesse_val = (float)(P_ne_vec_world.k[2] * v5) - (float)(v6 * P_ne_vec_world.k[1]);
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Point *)&P_world.k[1]);
  return v9[1] * P_world.k[2] + P_world.k[1] * v9[0] + v9[2] * P_world.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x100979C0
// Name: public: virtual float IVP_3D_Solver_PK_COLL::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
long double __userpurge IVP_3D_Solver_PK_COLL::get_value@<st0>(
        IVP_3D_Solver_PK_COLL *this@<ecx>,
        int a2@<ebp>,
        IVP_U_Matrix *A_w_f_c,
        IVP_U_Matrix *B_w_f_c)
{
  long double result; // st7
  _BYTE v6[12]; // [esp-Ch] [ebp-7Ch] BYREF
  IVP_U_Point K_vec_world; // [esp+0h] [ebp-70h] BYREF
  IVP_U_Point K_Lot_world; // [esp+10h] [ebp-60h] BYREF
  IVP_U_Point PK; // [esp+20h] [ebp-50h] BYREF
  IVP_U_Point P_world; // [esp+30h] [ebp-40h] BYREF
  IVP_U_Point K_world; // [esp+40h] [ebp-30h] BYREF
  IVP_U_Point H; // [esp+50h] [ebp-20h]
  float v13; // [esp+60h] [ebp-10h]
  int v14; // [esp+64h] [ebp-Ch]
  float res2; // [esp+68h] [ebp-8h]
  float retaddr; // [esp+70h] [ebp+0h]

  v14 = a2;
  res2 = retaddr;
  IVP_U_Matrix::vmult4(this: A_w_f_c, p_in: &this->P_object, p_out: (IVP_U_Point *)&PK.k[1]);
  IVP_U_Matrix::vmult4(this: B_w_f_c, p_in: &this->K_object, p_out: (IVP_U_Point *)&P_world.k[1]);
  IVP_U_Matrix3::vmult3(this: B_w_f_c, p_in: &this->K_vec_object, p_out: (IVP_U_Float_Point *)v6);
  IVP_U_Matrix3::vmult3(this: B_w_f_c, p_in: &this->K_Lot_object, p_out: (IVP_U_Point *)&K_vec_world.k[1]);
  K_Lot_world.k[1] = P_world.k[1] - PK.k[1];
  K_Lot_world.k[2] = P_world.k[2] - PK.k[2];
  K_Lot_world.hesse_val = P_world.hesse_val - PK.hesse_val;
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Point *)&K_world.k[1],
    v1: (IVP_U_Point *)&K_Lot_world.k[1],
    v2: (const IVP_U_Float_Point *)v6);
  result = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Point *)&K_world.k[1]);
  v13 = result;
  H.hesse_val = (float)((float)((float)(K_vec_world.k[2] * K_world.k[2]) + (float)(K_vec_world.k[1] * K_world.k[1]))
                      + (float)(K_vec_world.hesse_val * K_world.hesse_val))
              + this->plane_offset;
  if ( v13 > H.hesse_val )
    return H.hesse_val;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097AB0
// Name: public: virtual float IVP_3D_Solver_PF_NPF::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge IVP_3D_Solver_PF_NPF::get_value@<st0>(
        IVP_3D_Solver_PF_NPF *this@<ecx>,
        float a2@<ebp>,
        IVP_U_Matrix *A_w_f_c,
        IVP_U_Matrix *B_w_f_c)
{
  _BYTE v6[12]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Point hesse_world; // [esp+0h] [ebp-20h] BYREF
  IVP_U_Point hesse_other_object; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  hesse_other_object.k[1] = a2;
  hesse_other_object.k[2] = retaddr;
  IVP_U_Matrix3::vmult3(this: B_w_f_c, p_in: &this->hesse_of_area_object, p_out: (IVP_U_Float_Point *)v6);
  IVP_U_Matrix3::vimult3(this: A_w_f_c, p_in: (const IVP_U_Float_Point *)v6, p_out: (IVP_U_Point *)&hesse_world.k[1]);
  return this->vec_object.k[1] * hesse_world.k[2]
       + hesse_world.k[1] * this->vec_object.k[0]
       + this->vec_object.k[2] * hesse_world.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x10097B10
// Name: public: virtual float IVP_3D_Solver_KK_COLL::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
long double __userpurge IVP_3D_Solver_KK_COLL::get_value@<st0>(
        IVP_3D_Solver_KK_COLL *this@<ecx>,
        int a2@<ebp>,
        IVP_U_Matrix *K_w_f_c,
        IVP_U_Matrix *L_w_f_c)
{
  long double v5; // st7
  _BYTE v7[12]; // [esp+14h] [ebp-6Ch] BYREF
  IVP_U_Point k_vec_world; // [esp+20h] [ebp-60h] BYREF
  IVP_U_Point l_vec_world; // [esp+30h] [ebp-50h] BYREF
  IVP_U_Point l_point_world; // [esp+40h] [ebp-40h] BYREF
  IVP_U_Point k_point_world; // [esp+50h] [ebp-30h] BYREF
  IVP_U_Point H; // [esp+60h] [ebp-20h]
  float v13; // [esp+70h] [ebp-10h]
  int v14; // [esp+74h] [ebp-Ch]
  void *v15; // [esp+78h] [ebp-8h]
  void *retaddr; // [esp+80h] [ebp+0h]

  v14 = a2;
  v15 = retaddr;
  IVP_U_Matrix3::vmult3(this: K_w_f_c, p_in: &this->k_vec_object, p_out: (IVP_U_Float_Point *)v7);
  IVP_U_Matrix::vmult4(this: K_w_f_c, p_in: &this->k_point_object, p_out: (IVP_U_Point *)&l_point_world.k[1]);
  IVP_U_Matrix3::vmult3(this: L_w_f_c, p_in: &this->l_vec_object, p_out: (IVP_U_Point *)&k_vec_world.k[1]);
  IVP_U_Matrix::vmult4(this: L_w_f_c, p_in: &this->l_point_object, p_out: (IVP_U_Point *)&l_vec_world.k[1]);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Point *)&k_point_world.k[1],
    v1: (const IVP_U_Float_Point *)v7,
    v2: (IVP_U_Point *)&k_vec_world.k[1]);
  v13 = l_point_world.hesse_val * k_point_world.hesse_val
      + l_point_world.k[1] * k_point_world.k[1]
      + l_point_world.k[2] * k_point_world.k[2];
  H.hesse_val = k_point_world.k[1] * l_vec_world.k[1]
              + k_point_world.k[2] * l_vec_world.k[2]
              + k_point_world.hesse_val * l_vec_world.hesse_val;
  v5 = IVP_Inline_Math::isqrt_float(
         quad: (float)((float)(k_point_world.k[2] * k_point_world.k[2]) + (float)(k_point_world.k[1] * k_point_world.k[1]))
       + (float)(k_point_world.hesse_val * k_point_world.hesse_val));
  return v5 * (v13 - H.hesse_val) * this->side;
}

//------------------------------------------------------------------------------
// Address: 0x10097C00
// Name: public: virtual float IVP_3D_Solver_KK_PARALLEL::get_value(class IVP_U_Matrix __near *,class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge IVP_3D_Solver_KK_PARALLEL::get_value@<st0>(
        IVP_3D_Solver_KK_PARALLEL *this@<ecx>,
        float a2@<ebp>,
        IVP_U_Matrix *K_w_f_c,
        IVP_U_Matrix *L_w_f_c)
{
  _BYTE v6[12]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Point k_vec_world; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Point l_vec_world; // [esp+10h] [ebp-20h] BYREF
  IVP_U_Point H; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  H.k[1] = a2;
  H.k[2] = retaddr;
  IVP_U_Matrix3::vmult3(this: K_w_f_c, p_in: &this->k_vec_object, p_out: (IVP_U_Float_Point *)v6);
  IVP_U_Matrix3::vmult3(this: L_w_f_c, p_in: &this->l_vec_object, p_out: (IVP_U_Point *)&k_vec_world.k[1]);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Point *)&l_vec_world.k[1],
    v1: (const IVP_U_Float_Point *)v6,
    v2: (IVP_U_Point *)&k_vec_world.k[1]);
  return l_vec_world.k[1] * l_vec_world.k[1]
       + l_vec_world.k[2] * l_vec_world.k[2]
       + l_vec_world.hesse_val * l_vec_world.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x10097C70
// Name: protected: static void IVP_Mindist_Event_Solver::next_event_illegal(class IVP_Mindist_Event_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Event_Solver::next_event_illegal()
{
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_event.cxx", 1258);
}

//------------------------------------------------------------------------------
// Address: 0x10097C90
// Name: protected: void IVP_Mindist_Event_Solver::calc_next_event_PF(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mindist_Event_Solver::calc_next_event_PF(
        IVP_Mindist_Event_Solver *this@<ecx>,
        const IVP_U_Float_Point *a2@<ebp>,
        const IVP_Compact_Edge *P,
        const IVP_Compact_Edge *F,
        IVP_Cache_Ledge_Point *m_cache_P,
        IVP_Cache_Ledge_Point *m_cache_F)
{
  float v7; // xmm0_4
  int seconds_high; // edx
  IVP_Time *p_event_time_out; // edi
  const IVP_Compact_Poly_Point *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  const IVP_Compact_Poly_Point *v14; // eax
  const IVP_Compact_Ledge *compact_ledge; // edx
  float v16; // xmm0_4
  float v17; // xmm1_4
  IVP_Mindist *mindist; // eax
  float sum_extra_radius; // xmm1_4
  float v20; // xmm2_4
  IVP_Mindist *v21; // ecx
  IVP_U_Point si128; // xmm0
  float len_numerator; // xmm2_4
  int v24; // eax
  float v25; // xmm1_4
  float v26; // xmm3_4
  IVP_Cache_Object *clp_cache_object; // ecx
  const IVP_Compact_Poly_Point *v28; // ecx
  int v29; // eax
  long double v30; // xmm1_8
  float v31; // edx
  const IVP_Compact_Poly_Point *v32; // eax
  float v33; // xmm0_4
  float v34; // xmm2_4
  unsigned int seconds_low; // ecx
  unsigned int v36; // edx
  int v37; // eax
  __int128 value2; // [esp+4h] [ebp-C80h]
  _DWORD v39[3]; // [esp+38h] [ebp-C4Ch] BYREF
  IVP_U_Matrix_Cache cache_P; // [esp+44h] [ebp-C40h] BYREF
  IVP_U_Matrix_Cache cache_F; // [esp+5F4h] [ebp-690h] BYREF
  IVP_U_Point wHesseF; // [esp+BA4h] [ebp-E0h] BYREF
  IVP_3D_Solver_PF_NPF pf_npf_solver; // [esp+BB4h] [ebp-D0h] BYREF
  IVP_3D_Solver_PF_COLL pf_coll_solver; // [esp+BF4h] [ebp-90h] BYREF
  IVP_U_Point hesse_in_P_object; // [esp+C44h] [ebp-40h]
  IVP_U_Point vec_object; // [esp+C54h] [ebp-30h]
  float v47; // [esp+C64h] [ebp-20h]
  int sec_dist; // [esp+C68h] [ebp-1Ch]
  const IVP_Compact_Poly_Point *ilen; // [esp+C6Ch] [ebp-18h]
  float max_grad_change; // [esp+C70h] [ebp-14h] BYREF
  float v51; // [esp+C74h] [ebp-10h] BYREF
  const IVP_U_Float_Point *p_object; // [esp+C78h] [ebp-Ch]
  const IVP_Compact_Edge *e; // [esp+C7Ch] [ebp-8h]
  const IVP_Compact_Edge *retaddr; // [esp+C84h] [ebp+0h]

  p_object = a2;
  e = retaddr;
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)v39, co: m_cache_P->clp_cache_object);
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1], co: m_cache_F->clp_cache_object);
  v7 = *(float *)(LODWORD(cache_P.matrizes[20].vv.k[2]) + 92) + *(float *)(v39[1] + 92);
  seconds_high = HIDWORD(this->t_max.seconds);
  LODWORD(this->event_time_out.seconds) = LODWORD(this->t_max.seconds);
  HIDWORD(this->event_time_out.seconds) = seconds_high;
  p_event_time_out = &this->event_time_out;
  v10 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)P];
  LODWORD(pf_npf_solver.hesse_of_area_object.k[1]) = &IVP_3D_Solver_PF_COLL::`vftable';
  v11 = v10->k[2];
  v12 = v10->k[0];
  v51 = v7;
  v13 = v10->k[1];
  v14 = &m_cache_F->compact_poly_points[(unsigned __int16)*(_DWORD *)F];
  compact_ledge = m_cache_F->compact_ledge;
  *((float *)&pf_coll_solver.IVP_3D_Solver + 5) = v12;
  *((float *)&pf_coll_solver.IVP_3D_Solver + 6) = v13;
  *((float *)&pf_coll_solver.IVP_3D_Solver + 7) = v11;
  v16 = v14->k[1];
  v17 = v14->k[2];
  pf_coll_solver.hesse_of_area_object.k[1] = v14->k[0];
  pf_coll_solver.hesse_of_area_object.k[2] = v16;
  pf_coll_solver.hesse_of_area_object.hesse_val = v17;
  IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
    edge: F,
    ledge: compact_ledge,
    out_vec: (IVP_U_Float_Point *)&pf_coll_solver.point_object.k[1]);
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&pf_coll_solver.point_object.k[1]);
  mindist = this->mindist;
  pf_npf_solver.hesse_of_area_object.k[2] = this->max_coll_speed;
  pf_npf_solver.hesse_of_area_object.hesse_val = 1.0 / pf_npf_solver.hesse_of_area_object.k[2];
  sum_extra_radius = mindist->sum_extra_radius;
  v20 = ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 22)];
  max_grad_change = mindist->len_numerator + sum_extra_radius;
  if ( IVP_3D_Solver::find_first_t_for_value_coll(
         this: (IVP_3D_Solver_PF_NPF *)&pf_npf_solver.hesse_of_area_object.k[1],
         value: v20 + sum_extra_radius,
         value2: (float)(sum_extra_radius * 0.5) + ivp_mindist_settings.real_coll_dist,
         t_now: this->t_now,
         t_max: this->event_time_out,
         mc_A: (IVP_U_Matrix_Cache *)v39,
         mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
         opt_val_at_t_now: &max_grad_change,
         t_out: &this->event_time_out) != IVP_FALSE )
    this->event_type_out = IVP_COLL_PF_COLL;
  v21 = this->mindist;
  si128 = (IVP_U_Point)_mm_load_si128((const __m128i *)&pf_coll_solver.point_object.k[1]);
  LODWORD(wHesseF.k[1]) = &IVP_3D_Solver_PF_NPF::`vftable';
  *(IVP_U_Point *)((char *)&pf_npf_solver.vec_object + 4) = si128;
  len_numerator = v21->len_numerator;
  v24 = (unsigned __int8)(*((_DWORD *)&v21->IVP_Mindist_Base + 5) >> 22);
  v25 = ivp_mindist_settings.coll_dists[v24];
  if ( len_numerator > v25 )
    len_numerator = ivp_mindist_settings.coll_dists[v24];
  v26 = v21->sum_extra_radius;
  clp_cache_object = m_cache_F->clp_cache_object;
  vec_object.k[2] = (float)(COERCE_FLOAT(
                              COERCE_UNSIGNED_INT(
                                m_cache_F->clp_object->physical_core->inv_object_diameter
                              * ivp_mindist_settings.mindist_change_force_dist)
                            ^ _mask__NegFloat_)
                          * (float)((float)(v26 * 0.1) + len_numerator))
                  / v25;
  IVP_U_Matrix3::vmult3(
    this: &clp_cache_object->m_world_f_object,
    p_in: (const IVP_U_Float_Point *)&pf_npf_solver.vec_object.k[1],
    p_out: (IVP_U_Float_Point *)&cache_F.matrizes[20].vv.k[1]);
  IVP_U_Matrix3::vimult3(
    this: &m_cache_P->clp_cache_object->m_world_f_object,
    p_in: (const IVP_U_Float_Point *)&cache_F.matrizes[20].vv.k[1],
    p_out: (IVP_U_Float_Point *)&pf_coll_solver.point_of_area_object.k[1]);
  v28 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)P];
  v29 = *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)P & 0xC));
  wHesseF.hesse_val = 1.0 / (float)(v51 + 1.0e-10);
  v30 = p_event_time_out->seconds - this->t_now.seconds;
  wHesseF.k[2] = v51 + 1.0e-10;
  LODWORD(v31) = (char *)&P[(2 * *(_DWORD *)((char *)P + v29)) >> 17] + v29;
  v47 = (float)v30 * (float)(v51 + 1.0e-10);
  ilen = v28;
  for ( max_grad_change = v31; ; max_grad_change = v31 )
  {
    sec_dist = LOBYTE(v31) & 0xC;
    v32 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)(LODWORD(v31)
                                                                      + *(int *)((char *)IVP_Compact_Edge::next_table
                                                                               + sec_dist))];
    v33 = v32->k[0] - v28->k[0];
    v34 = v32->k[2] - v28->k[2];
    hesse_in_P_object.k[2] = v32->k[1] - v28->k[1];
    hesse_in_P_object.k[1] = v33;
    hesse_in_P_object.hesse_val = v34;
    v51 = (float)((float)(pf_coll_solver.point_of_area_object.k[2] * hesse_in_P_object.k[2])
                + (float)(v33 * pf_coll_solver.point_of_area_object.k[1]))
        + (float)(pf_coll_solver.point_of_area_object.hesse_val * v34);
    vec_object.hesse_val = IVP_Inline_Math::isqrt_float(
                             quad: (float)((float)(hesse_in_P_object.k[2] * hesse_in_P_object.k[2]) + (float)(v33 * v33))
                           + (float)(v34 * v34));
    v51 = vec_object.hesse_val * v51;
    if ( v47 > v51 )
    {
      seconds_low = LODWORD(p_event_time_out->seconds);
      v36 = HIDWORD(this->t_now.seconds);
      HIDWORD(value2) = HIDWORD(this->event_time_out.seconds);
      v37 = LODWORD(this->t_now.seconds);
      *((float *)&pf_npf_solver.IVP_3D_Solver + 5) = hesse_in_P_object.k[1] * vec_object.hesse_val;
      *((float *)&pf_npf_solver.IVP_3D_Solver + 6) = hesse_in_P_object.k[2] * vec_object.hesse_val;
      *(_QWORD *)((char *)&value2 + 4) = __PAIR64__(seconds_low, v36);
      LODWORD(value2) = v37;
      *((float *)&pf_npf_solver.IVP_3D_Solver + 7) = hesse_in_P_object.hesse_val * vec_object.hesse_val;
      if ( IVP_3D_Solver::find_first_t_for_value_max_dev(
             this: (IVP_3D_Solver *)&wHesseF.k[1],
             value: vec_object.k[2],
             t_now: (IVP_Time)value2,
             t_max: *((IVP_Time *)&value2 + 1),
             t_now_cache_index: 0,
             mc_A: (IVP_U_Matrix_Cache *)v39,
             mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
             opt_val_at_t_now: &v51,
             t_out: &this->event_time_out) != IVP_FALSE )
        this->event_type_out = IVP_COLL_PF_NPF;
    }
    if ( (const IVP_Compact_Edge *)LODWORD(max_grad_change) == P )
      break;
    LODWORD(v31) = LODWORD(max_grad_change)
                 + *(int *)((char *)IVP_Compact_Edge::prev_table + sec_dist)
                 + 4
                 * ((2
                   * *(_DWORD *)(LODWORD(max_grad_change) + *(int *)((char *)IVP_Compact_Edge::prev_table + sec_dist))) >> 17);
    v28 = ilen;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100980A0
// Name: protected: void IVP_Mindist_Event_Solver::calc_next_event_BF(class IVP_Compact_Edge const __near *,class IVP_Cache_Object __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mindist_Event_Solver::calc_next_event_BF(
        IVP_Mindist_Event_Solver *this@<ecx>,
        float a2@<ebp>,
        const IVP_Compact_Edge *F,
        IVP_Cache_Object *m_cache_B,
        IVP_Cache_Ledge_Point *m_cache_F)
{
  const IVP_Compact_Poly_Point *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  const IVP_Compact_Ledge *compact_ledge; // eax
  IVP_Mindist *mindist; // eax
  float sum_extra_radius; // xmm1_4
  float len_numerator; // xmm3_4
  float v14; // xmm2_4
  _BYTE v15[12]; // [esp+38h] [ebp-BCCh] BYREF
  IVP_U_Matrix_Cache cache_P; // [esp+44h] [ebp-BC0h] BYREF
  IVP_U_Matrix_Cache cache_F; // [esp+5F4h] [ebp-610h] BYREF
  IVP_3D_Solver_PF_COLL pf_coll_solver; // [esp+BA4h] [ebp-60h] BYREF
  float v19[3]; // [esp+BF4h] [ebp-10h] BYREF
  float retaddr; // [esp+C04h] [ebp+0h]
  IVP_Time v21; // 0:^10.8
  IVP_Time v22; // 0:rax.8

  v19[1] = a2;
  v19[2] = retaddr;
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)v15, co: m_cache_B);
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1], co: m_cache_F->clp_cache_object);
  v6 = &m_cache_F->compact_poly_points[(unsigned __int16)*(_DWORD *)F];
  LODWORD(cache_F.matrizes[20].vv.k[1]) = &IVP_3D_Solver_PF_COLL::`vftable';
  memset(&pf_coll_solver.IVP_3D_Solver + 1, 0, 12);
  v7 = v6->k[1];
  v8 = v6->k[2];
  v9 = v6->k[0];
  compact_ledge = m_cache_F->compact_ledge;
  pf_coll_solver.hesse_of_area_object.k[1] = v9;
  pf_coll_solver.hesse_of_area_object.k[2] = v7;
  pf_coll_solver.hesse_of_area_object.hesse_val = v8;
  IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
    edge: F,
    ledge: compact_ledge,
    out_vec: (IVP_U_Float_Point *)&pf_coll_solver.point_object.k[1]);
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&pf_coll_solver.point_object.k[1]);
  mindist = this->mindist;
  cache_F.matrizes[20].vv.k[2] = this->max_coll_speed;
  cache_F.matrizes[20].vv.hesse_val = 1.0 / cache_F.matrizes[20].vv.k[2];
  sum_extra_radius = mindist->sum_extra_radius;
  len_numerator = mindist->len_numerator;
  v14 = ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 22)];
  v22.seconds = this->t_now.seconds;
  v21.seconds = this->t_max.seconds;
  v19[0] = len_numerator + sum_extra_radius;
  if ( IVP_3D_Solver::find_first_t_for_value_coll(
         this: (IVP_3D_Solver *)&cache_F.matrizes[20].vv.k[1],
         value: v14 + sum_extra_radius,
         value2: (float)(sum_extra_radius * 0.5) + ivp_mindist_settings.real_coll_dist,
         t_now: v22,
         t_max: v21,
         mc_A: (IVP_U_Matrix_Cache *)v15,
         mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
         opt_val_at_t_now: v19,
         t_out: &this->event_time_out) != IVP_FALSE )
    this->event_type_out = IVP_COLL_PF_COLL;
}

//------------------------------------------------------------------------------
// Address: 0x100981F0
// Name: protected: void IVP_Mindist_Event_Solver::calc_next_event_KK(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mindist_Event_Solver::calc_next_event_KK(
        IVP_Mindist_Event_Solver *this@<ecx>,
        int a2@<ebp>,
        const IVP_Compact_Edge *K,
        const IVP_Compact_Edge *L,
        IVP_Cache_Ledge_Point *m_cache_K,
        IVP_Cache_Ledge_Point *m_cache_L)
{
  IVP_Real_Object *clp_object; // ecx
  float v8; // xmm0_4
  int v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  const IVP_Compact_Poly_Point *v12; // eax
  int v13; // esi
  float v14; // xmm1_4
  float v15; // xmm2_4
  const IVP_Compact_Poly_Point *v16; // esi
  int v17; // edi
  float *v18; // edi
  IVP_U_Point *v19; // ecx
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  IVP_Time *v26; // esi
  float v27; // xmm0_4
  float v28; // xmm2_4
  IVP_Cache_Object *v29; // ecx
  float max_coll_speed; // xmm0_4
  int seconds_low; // eax
  float v32; // xmm0_4
  int seconds_high; // ecx
  __int64 v34; // rax
  int v35; // ecx
  const IVP_Compact_Edge *v36; // ecx
  int v37; // edx
  int v38; // edi
  IVP_U_Matrix_Cache *v39; // eax
  float v40; // xmm0_4
  float v41; // xmm1_4
  int v42; // eax
  const IVP_Compact_Edge *v43; // edx
  __int64 v44; // rax
  __int128 value2; // [esp+4h] [ebp-D00h]
  __int128 value2a; // [esp+4h] [ebp-D00h]
  IVP_Cache_Object *clp_cache_object; // [esp+24h] [ebp-CE0h]
  _BYTE v48[12]; // [esp+38h] [ebp-CCCh] BYREF
  IVP_U_Matrix_Cache cache_K; // [esp+44h] [ebp-CC0h] BYREF
  IVP_U_Matrix_Cache cache_L; // [esp+5F4h] [ebp-710h] BYREF
  IVP_3D_Solver_KK_PARALLEL solver_kk_parallel; // [esp+BA4h] [ebp-160h] BYREF
  IVP_3D_Solver_VEC_PARALLEL_AREA solver_KK_PF; // [esp+BE4h] [ebp-120h] BYREF
  IVP_3D_Solver_KK_COLL solver_kk_coll; // [esp+C24h] [ebp-E0h] BYREF
  IVP_U_Matrix_Cache *cache_tab[4]; // [esp+C94h] [ebp-70h]
  IVP_U_Point *edge_object[4]; // [esp+CA4h] [ebp-60h] BYREF
  IVP_U_Point k_vec_world_now; // [esp+CB4h] [ebp-50h] BYREF
  IVP_U_Point l_vec_world_now; // [esp+CC4h] [ebp-40h]
  IVP_Mindist_Event_Solver *v58; // [esp+CD4h] [ebp-30h]
  const IVP_Compact_Edge *v59; // [esp+CD8h] [ebp-2Ch] BYREF
  const IVP_Compact_Edge *v60; // [esp+CDCh] [ebp-28h]
  const IVP_Compact_Edge *v61; // [esp+CE0h] [ebp-24h]
  IVP_U_Point H; // [esp+CE4h] [ebp-20h]
  int compact_poly_points; // [esp+CF4h] [ebp-10h]
  int v64; // [esp+CF8h] [ebp-Ch]
  float sum_abs_omega; // [esp+CFCh] [ebp-8h]
  float retaddr; // [esp+D04h] [ebp+0h]

  v64 = a2;
  sum_abs_omega = retaddr;
  clp_cache_object = m_cache_K->clp_cache_object;
  v58 = this;
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)v48, co: clp_cache_object);
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)&cache_K.matrizes[20].vv.k[1], co: m_cache_L->clp_cache_object);
  clp_object = m_cache_K->clp_object;
  LODWORD(solver_KK_PF.hesse_of_area_object.k[1]) = &IVP_3D_Solver_KK_COLL::`vftable';
  v8 = clp_object->physical_core->abs_omega + m_cache_L->clp_object->physical_core->abs_omega;
  this->event_time_out = this->t_max;
  v9 = (unsigned __int16)*(_DWORD *)((char *)K
                                   + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC)));
  v10 = m_cache_K->compact_poly_points[v9].k[2];
  v11 = m_cache_K->compact_poly_points[v9].k[0];
  v12 = &m_cache_K->compact_poly_points[v9];
  v13 = (unsigned __int16)*(_DWORD *)K;
  v14 = v10 - m_cache_K->compact_poly_points[v13].k[2];
  v15 = v11 - m_cache_K->compact_poly_points[v13].k[0];
  v16 = &m_cache_K->compact_poly_points[v13];
  v17 = (int)*L;
  compact_poly_points = (int)m_cache_L->compact_poly_points;
  v18 = (float *)(compact_poly_points + 16 * (unsigned __int16)v17);
  v19 = (IVP_U_Point *)(compact_poly_points
                      + 16
                      * (unsigned __int16)*(_DWORD *)((char *)L
                                                    + *(int *)((char *)IVP_Compact_Edge::next_table
                                                             + ((unsigned __int8)L & 0xC))));
  H.hesse_val = v8;
  v20 = v12->k[1] - v16->k[1];
  compact_poly_points = (int)v19;
  solver_kk_coll.k_point_object.k[1] = v15;
  solver_kk_coll.k_point_object.k[2] = v20;
  solver_kk_coll.k_point_object.hesse_val = v14;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_kk_coll.k_point_object.k[1]);
  v21 = *(float *)(compact_poly_points + 4) - v18[1];
  v22 = *(float *)(compact_poly_points + 8) - v18[2];
  solver_kk_coll.l_point_object.k[1] = *(float *)compact_poly_points - *v18;
  solver_kk_coll.l_point_object.k[2] = v21;
  solver_kk_coll.l_point_object.hesse_val = v22;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_kk_coll.l_point_object.k[1]);
  v23 = v16->k[1];
  v24 = v16->k[2];
  v25 = v16->k[0];
  v26 = (IVP_Time *)v58;
  *((float *)&solver_kk_coll.IVP_3D_Solver + 7) = v24;
  *((float *)&solver_kk_coll.IVP_3D_Solver + 6) = v23;
  *((float *)&solver_kk_coll.IVP_3D_Solver + 5) = v25;
  v27 = v18[1];
  v28 = *v18;
  v29 = m_cache_L->clp_cache_object;
  solver_kk_coll.k_vec_object.hesse_val = v18[2];
  solver_kk_coll.k_vec_object.k[2] = v27;
  max_coll_speed = v58->max_coll_speed;
  solver_kk_coll.k_vec_object.k[1] = v28;
  solver_KK_PF.hesse_of_area_object.k[2] = max_coll_speed;
  solver_KK_PF.hesse_of_area_object.hesse_val = 1.0 / max_coll_speed;
  IVP_U_Matrix3::vmult3(
    this: &v29->m_world_f_object,
    p_in: (const IVP_U_Float_Point *)&solver_kk_coll.l_point_object.k[1],
    p_out: (IVP_U_Point *)&k_vec_world_now.k[1]);
  IVP_U_Matrix3::vmult3(
    this: &m_cache_K->clp_cache_object->m_world_f_object,
    p_in: (const IVP_U_Float_Point *)&solver_kk_coll.k_point_object.k[1],
    p_out: (IVP_U_Float_Point *)&edge_object[1]);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)&v59,
    v1: (const IVP_U_Float_Point *)&edge_object[1],
    v2: (IVP_U_Point *)&k_vec_world_now.k[1]);
  seconds_low = LODWORD(v26[2].seconds);
  if ( COERCE_FLOAT(
         COERCE_UNSIGNED_INT(
           (float)((float)(*(float *)(seconds_low + 100) * *(float *)&v60)
                 + (float)(*(float *)(seconds_low + 96) * *(float *)&v59))
         + (float)(*(float *)(seconds_low + 104) * *(float *)&v61))
       ^ _mask__NegFloat_) <= 0.0 )
  {
    v32 = 1.0;
    compact_poly_points = 1;
  }
  else
  {
    v32 = -1.0;
    compact_poly_points = 0;
  }
  solver_kk_coll.l_vec_object.k[1] = v32;
  if ( (float)IVP_3D_Solver::find_first_t_for_value_coll(
                this: (IVP_3D_Solver_VEC_PARALLEL_AREA *)&solver_KK_PF.hesse_of_area_object.k[1],
                value: ivp_mindist_settings.coll_dists[(unsigned __int8)(*(_DWORD *)(seconds_low + 20) >> 22)],
                value2: ivp_mindist_settings.real_coll_dist,
                t_now: v26[3],
                t_max: v26[6],
                mc_A: (IVP_U_Matrix_Cache *)v48,
                mc_B: (IVP_U_Matrix_Cache *)&cache_K.matrizes[20].vv.k[1],
                opt_val_at_t_now: nullptr,
                t_out: v26 + 6) != 0.0 )
    LODWORD(v26[5].seconds) = 64;
  *((_DWORD *)&solver_kk_parallel.IVP_3D_Solver + 5) = LODWORD(solver_kk_coll.k_point_object.k[1]);
  *((_DWORD *)&solver_kk_parallel.IVP_3D_Solver + 6) = LODWORD(solver_kk_coll.k_point_object.k[2]);
  seconds_high = HIDWORD(v26[6].seconds);
  *((_DWORD *)&solver_kk_parallel.IVP_3D_Solver + 7) = LODWORD(solver_kk_coll.k_point_object.hesse_val);
  HIDWORD(v34) = LODWORD(v26[6].seconds);
  LODWORD(v34) = HIDWORD(v26[3].seconds);
  HIDWORD(value2) = seconds_high;
  v35 = LODWORD(v26[3].seconds);
  solver_kk_parallel.k_vec_object.k[1] = solver_kk_coll.l_point_object.k[1];
  solver_kk_parallel.k_vec_object.k[2] = solver_kk_coll.l_point_object.k[2];
  solver_kk_parallel.k_vec_object.hesse_val = solver_kk_coll.l_point_object.hesse_val;
  *(_QWORD *)((char *)&value2 + 4) = v34;
  LODWORD(value2) = v35;
  LODWORD(cache_L.matrizes[20].vv.k[1]) = &IVP_3D_Solver_KK_PARALLEL::`vftable';
  cache_L.matrizes[20].vv.k[2] = (float)(H.hesse_val * 2.0) + 1.0e-10;
  cache_L.matrizes[20].vv.hesse_val = 1.0 / cache_L.matrizes[20].vv.k[2];
  if ( (float)IVP_3D_Solver::find_first_t_for_value_max_dev(
                this: (IVP_3D_Solver *)&cache_L.matrizes[20].vv.k[1],
                value: 1.0e-10,
                t_now: (IVP_Time)value2,
                t_max: *((IVP_Time *)&value2 + 1),
                t_now_cache_index: 0,
                mc_A: (IVP_U_Matrix_Cache *)v48,
                mc_B: (IVP_U_Matrix_Cache *)&cache_K.matrizes[20].vv.k[1],
                opt_val_at_t_now: nullptr,
                t_out: v26 + 6) != 0.0 )
    LODWORD(v26[5].seconds) = 65;
  v36 = &K[(2 * *(_DWORD *)K) >> 17];
  v60 = K;
  v37 = (2 * *(_DWORD *)L) >> 17;
  v59 = v36;
  LODWORD(H.k[0]) = L;
  v61 = &L[v37];
  cache_tab[2] = (IVP_U_Matrix_Cache *)&solver_kk_coll.l_point_object.k[1];
  cache_tab[1] = (IVP_U_Matrix_Cache *)&solver_kk_coll.l_point_object.k[1];
  cache_tab[3] = (IVP_U_Matrix_Cache *)&solver_kk_coll.k_point_object.k[1];
  edge_object[2] = (IVP_U_Point *)(1 - compact_poly_points);
  LODWORD(k_vec_world_now.k[0]) = 1 - compact_poly_points;
  edge_object[0] = (IVP_U_Point *)&solver_kk_coll.k_point_object.k[1];
  edge_object[1] = (IVP_U_Point *)compact_poly_points;
  edge_object[3] = (IVP_U_Point *)compact_poly_points;
  *((_DWORD *)&solver_kk_coll.side + 1) = &cache_K.matrizes[20].vv.k[1];
  cache_tab[0] = (IVP_U_Matrix_Cache *)v48;
  LODWORD(k_vec_world_now.hesse_val) = m_cache_K;
  LODWORD(l_vec_world_now.k[0]) = m_cache_K;
  v38 = 0;
  *((_DWORD *)&solver_kk_coll.side + 2) = &cache_K.matrizes[20].vv.k[1];
  *((_DWORD *)&solver_kk_coll.side + 3) = v48;
  LODWORD(k_vec_world_now.k[1]) = m_cache_L;
  LODWORD(k_vec_world_now.k[2]) = m_cache_L;
  LODWORD(solver_kk_parallel.l_vec_object.k[1]) = &IVP_3D_Solver_VEC_PARALLEL_AREA::`vftable';
  solver_kk_parallel.l_vec_object.k[2] = H.hesse_val + 1.0e-10;
  solver_kk_parallel.l_vec_object.hesse_val = 1.0 / (float)(H.hesse_val + 1.0e-10);
  for ( compact_poly_points = 0; compact_poly_points >= -12; compact_poly_points -= 4 )
  {
    v39 = cache_tab[v38 + 1];
    v40 = *(float *)&v39->core;
    v41 = *(float *)&v39->base_time.seconds;
    if ( edge_object[v38 + 1] != nullptr )
    {
      *((_DWORD *)&solver_KK_PF.IVP_3D_Solver + 5) = v39->object;
    }
    else
    {
      v40 = v40 * -1.0;
      v41 = v41 * -1.0;
      *((float *)&solver_KK_PF.IVP_3D_Solver + 5) = *(float *)&v39->object * -1.0;
    }
    v42 = *(_DWORD *)((char *)l_vec_world_now.k + compact_poly_points);
    v43 = (&v59)[v38];
    *((float *)&solver_KK_PF.IVP_3D_Solver + 7) = v41;
    *((float *)&solver_KK_PF.IVP_3D_Solver + 6) = v40;
    IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
      edge: v43,
      ledge: *(const IVP_Compact_Ledge **)(v42 + 4),
      out_vec: (IVP_U_Float_Point *)&solver_KK_PF.vec_object.k[1]);
    IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_KK_PF.vec_object.k[1]);
    HIDWORD(v44) = LODWORD(v26[6].seconds);
    LODWORD(v44) = HIDWORD(v26[3].seconds);
    HIDWORD(value2a) = HIDWORD(v26[6].seconds);
    *(_QWORD *)((char *)&value2a + 4) = v44;
    LODWORD(value2a) = LODWORD(v26[3].seconds);
    if ( IVP_3D_Solver::find_first_t_for_value_max_dev(
           this: (IVP_3D_Solver_KK_PARALLEL *)&solver_kk_parallel.l_vec_object.k[1],
           value: COERCE_FLOAT(
             COERCE_UNSIGNED_INT(
               *(float *)(*(_DWORD *)(*(_DWORD *)((char *)&solver_kk_coll.side + v38 * 4 + 4) + 4) + 68)
             * ivp_mindist_settings.mindist_change_force_dist)
           ^ _mask__NegFloat_),
           t_now: (IVP_Time)value2a,
           t_max: *((IVP_Time *)&value2a + 1),
           t_now_cache_index: 0,
           mc_A: *(IVP_U_Matrix_Cache **)((char *)&solver_kk_coll.side + v38 * 4 + 4),
           mc_B: *(IVP_U_Matrix_Cache **)((char *)cache_tab + compact_poly_points),
           opt_val_at_t_now: nullptr,
           t_out: v26 + 6) != IVP_FALSE )
      LODWORD(v26[5].seconds) = 66;
    ++v38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098780
// Name: protected: void IVP_Mindist_Event_Solver::calc_next_event_PP(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mindist_Event_Solver::calc_next_event_PP(
        IVP_Mindist_Event_Solver *this@<ecx>,
        const IVP_U_Float_Point *a2@<ebp>,
        IVP_Cache_Ledge_Point *P,
        const IVP_Compact_Edge *P2,
        IVP_Cache_Ledge_Point *m_cache_P,
        IVP_Cache_Ledge_Point *m_cache_P2)
{
  IVP_Real_Object *clp_object; // ecx
  int seconds_low; // eax
  float v9; // edx
  int v10; // eax
  const IVP_Compact_Poly_Point *v11; // edi
  const IVP_Compact_Poly_Point *v12; // eax
  IVP_Mindist *mindist; // eax
  float v14; // xmm3_4
  float v15; // xmm1_4
  float max_coll_speed; // xmm0_4
  float sum_extra_radius; // xmm1_4
  float v18; // xmm0_4
  int seconds_high; // eax
  long double v20; // st7
  float v21; // edi
  long double v22; // st7
  long double v23; // st7
  IVP_Core *physical_core; // edx
  float upper_limit_radius; // xmm0_4
  IVP_Core *v26; // edx
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  int v30; // edx
  int *v31; // eax
  float *v32; // edi
  IVP_Core *v33; // ecx
  int v34; // xmm0_4
  int v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  _DWORD *v39; // eax
  IVP_Core *v40; // ecx
  IVP_U_Matrix_Cache *v41; // eax
  IVP_U_Matrix_Cache *v42; // edx
  const IVP_U_Float_Point *v43; // edx
  float *v44; // eax
  float v45; // xmm0_4
  float v46; // xmm1_4
  int v47; // edx
  int v48; // eax
  unsigned int v49; // ecx
  unsigned int v50; // edx
  IVP_Time v51; // [esp+Ch] [ebp-C48h]
  IVP_Time v52; // [esp+10h] [ebp-C44h]
  _BYTE v53[12]; // [esp+38h] [ebp-C1Ch] BYREF
  IVP_U_Matrix_Cache cache_P2; // [esp+44h] [ebp-C10h] BYREF
  IVP_U_Matrix_Cache cache_P; // [esp+5F4h] [ebp-660h]
  IVP_Cache_Ledge_Point *v56; // [esp+BA4h] [ebp-B0h]
  float v57; // [esp+BA8h] [ebp-ACh]
  IVP_Cache_Ledge_Point *mcache[2]; // [esp+BACh] [ebp-A8h]
  float deviation[2]; // [esp+BB4h] [ebp-A0h] BYREF
  const IVP_Compact_Edge *Point[2]; // [esp+BBCh] [ebp-98h]
  IVP_3D_Solver_S_VALS solver_pp_pk; // [esp+BC4h] [ebp-90h]
  IVP_U_Matrix_Cache *v62; // [esp+C14h] [ebp-40h]
  const IVP_Compact_Poly_Point *neg_maximal_safe_s_value; // [esp+C18h] [ebp-3Ch]
  const IVP_Compact_Poly_Point *qlen; // [esp+C1Ch] [ebp-38h]
  int v65; // [esp+C20h] [ebp-34h]
  const IVP_U_Float_Point *points_object[2]; // [esp+C24h] [ebp-30h]
  _BYTE *v67; // [esp+C2Ch] [ebp-28h]
  IVP_Core *v68; // [esp+C30h] [ebp-24h]
  IVP_U_Matrix_Cache *cache[2]; // [esp+C34h] [ebp-20h]
  const IVP_Compact_Edge *point2; // [esp+C3Ch] [ebp-18h]
  IVP_Core *max_dist_PP; // [esp+C40h] [ebp-14h]
  int inv_len; // [esp+C44h] [ebp-10h]
  const IVP_U_Float_Point *p2_object; // [esp+C48h] [ebp-Ch]
  const IVP_Compact_Edge *e; // [esp+C4Ch] [ebp-8h]
  const IVP_Compact_Edge *retaddr; // [esp+C54h] [ebp+0h]

  p2_object = a2;
  e = retaddr;
  IVP_U_Matrix_Cache::p_init(
    this: (IVP_U_Matrix_Cache *)&cache_P2.matrizes[20].vv.k[1],
    co: m_cache_P->clp_cache_object);
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)v53, co: m_cache_P2->clp_cache_object);
  clp_object = m_cache_P2->clp_object;
  seconds_low = LODWORD(this->t_max.seconds);
  max_dist_PP = m_cache_P->clp_object->physical_core;
  v9 = *(float *)&clp_object->physical_core;
  LODWORD(this->event_time_out.seconds) = seconds_low;
  *(float *)&inv_len = v9;
  HIDWORD(this->event_time_out.seconds) = HIDWORD(this->t_max.seconds);
  v10 = (unsigned __int16)*(_DWORD *)P2;
  v11 = &m_cache_P->compact_poly_points[(unsigned __int16)P->compact_poly_points];
  *((_DWORD *)&solver_pp_pk.IVP_3D_Solver + 5) = LODWORD(v11->k[0]);
  *((_DWORD *)&solver_pp_pk.IVP_3D_Solver + 6) = LODWORD(v11->k[1]);
  *((_DWORD *)&solver_pp_pk.IVP_3D_Solver + 7) = LODWORD(v11->k[2]);
  v12 = &m_cache_P2->compact_poly_points[v10];
  LODWORD(deviation[1]) = &IVP_3D_Solver_DISTANCE_OF_TWO_POINTS::`vftable';
  solver_pp_pk.P_object.k[1] = v12->k[0];
  solver_pp_pk.P_object.k[2] = v12->k[1];
  solver_pp_pk.P_object.hesse_val = v12->k[2];
  point2 = (const IVP_Compact_Edge *)v12;
  qlen = v12;
  mindist = this->mindist;
  v14 = mindist->contact_plane.k[0];
  v15 = mindist->contact_plane.k[2] * -1.0;
  solver_pp_pk.K_object.k[2] = mindist->contact_plane.k[1] * -1.0;
  max_coll_speed = this->max_coll_speed;
  solver_pp_pk.K_object.hesse_val = v15;
  Point[0] = (const IVP_Compact_Edge *)LODWORD(max_coll_speed);
  solver_pp_pk.K_object.k[1] = v14 * -1.0;
  *(float *)&Point[1] = 1.0 / max_coll_speed;
  sum_extra_radius = mindist->sum_extra_radius;
  v18 = ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 22)];
  seconds_high = HIDWORD(this->t_max.seconds);
  neg_maximal_safe_s_value = v11;
  HIDWORD(v52.seconds) = seconds_high;
  LODWORD(v52.seconds) = LODWORD(this->t_max.seconds);
  if ( IVP_3D_Solver::find_first_t_for_value_coll(
         this: (IVP_3D_Solver *)&deviation[1],
         value: v18 + sum_extra_radius,
         value2: (float)(sum_extra_radius * 0.5) + ivp_mindist_settings.real_coll_dist,
         t_now: this->t_now,
         t_max: v52,
         mc_A: (IVP_U_Matrix_Cache *)&cache_P2.matrizes[20].vv.k[1],
         mc_B: (IVP_U_Matrix_Cache *)v53,
         opt_val_at_t_now: nullptr,
         t_out: &this->event_time_out) != IVP_FALSE )
    this->event_type_out = IVP_COLL_PP_COLL;
  *(float *)cache = (float)((float)(this->event_time_out.seconds - this->t_now.seconds) * this->worst_case_speed)
                  + this->mindist->len_numerator;
  v20 = IVP_U_Float_Point::fast_real_length(this: &v11->IVP_U_Float_Hesse);
  v21 = *(float *)&max_dist_PP;
  v22 = v20 * *(float *)(LODWORD(v21) + 92) + *(float *)(LODWORD(v21) + 316);
  max_dist_PP = *(IVP_Core **)(inv_len + 92);
  *(float *)&cache[1] = v22;
  v23 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)point2);
  physical_core = m_cache_P->clp_object->physical_core;
  *(float *)&inv_len = v23 * *(float *)&max_dist_PP + *(float *)(inv_len + 316);
  v57 = (float)(*(float *)&max_dist_PP * *(float *)cache) + (float)(*(float *)&inv_len + *(float *)&cache[1]);
  *(float *)mcache = (float)(*(float *)(LODWORD(v21) + 92) * *(float *)cache)
                   + (float)(*(float *)&inv_len + *(float *)&cache[1]);
  upper_limit_radius = physical_core->upper_limit_radius;
  v26 = m_cache_P2->clp_object->physical_core;
  if ( upper_limit_radius <= v26->upper_limit_radius )
    v27 = v26->upper_limit_radius;
  else
    v27 = upper_limit_radius;
  v28 = ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&this->mindist->IVP_Mindist_Base + 5) >> 22)];
  v29 = v28 * v28;
  if ( v29 > (float)(*(float *)cache * *(float *)cache) )
    v29 = *(float *)cache * *(float *)cache;
  points_object[1] = (const IVP_U_Float_Point *)&cache_P2.matrizes[20].vv.k[1];
  v67 = v53;
  LODWORD(cache_P.matrizes[20].vv.hesse_val) = m_cache_P;
  v56 = m_cache_P2;
  v30 = 0;
  solver_pp_pk.K_vec_object.k[2] = (float)(v29 * -0.5) / v27;
  mcache[1] = P;
  LODWORD(deviation[0]) = P2;
  *(float *)&inv_len = 0.0;
  point2 = nullptr;
  while ( 1 )
  {
    v31 = *(int **)((char *)&neg_maximal_safe_s_value + (_DWORD)point2);
    v32 = *(float **)((char *)&qlen + v30);
    v33 = *(IVP_Core **)((char *)deviation + v30);
    LODWORD(deviation[1]) = &IVP_3D_Solver_S_VALS::`vftable';
    v34 = v31[1];
    v35 = *v31;
    *((_DWORD *)&solver_pp_pk.IVP_3D_Solver + 7) = v31[2];
    *((_DWORD *)&solver_pp_pk.IVP_3D_Solver + 6) = v34;
    *((_DWORD *)&solver_pp_pk.IVP_3D_Solver + 5) = v35;
    v36 = v32[2];
    v37 = *v32;
    solver_pp_pk.P_object.k[2] = v32[1];
    v38 = *(float *)((char *)&mcache[-1] + (_DWORD)point2);
    v39 = (_DWORD *)((char *)v33 + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)v33 & 0xC)));
    solver_pp_pk.P_object.hesse_val = v36;
    v68 = v33;
    solver_pp_pk.P_object.k[1] = v37;
    Point[0] = (const IVP_Compact_Edge *)LODWORD(v38);
    *(float *)&Point[1] = 1.0 / v38;
    v40 = (IVP_Core *)&v39[(2 * *v39) >> 17];
    v41 = *(IVP_U_Matrix_Cache **)((char *)&v56 + v30);
    v42 = *(IVP_U_Matrix_Cache **)((char *)&v67 + v30);
    cache[0] = v41;
    v62 = v42;
    v43 = *(const IVP_U_Float_Point **)((char *)&points_object[1] + (_DWORD)point2);
    max_dist_PP = v40;
    points_object[0] = v43;
    while ( 1 )
    {
      v65 = (unsigned __int8)v40 & 0xC;
      v44 = (float *)((char *)cache[0]->object
                    + 16
                    * (unsigned __int16)*(_DWORD *)((char *)&v40->IVP_Core_Fast_Static
                                                  + *(int *)((char *)IVP_Compact_Edge::next_table + v65)));
      v45 = v44[1] - v32[1];
      v46 = v44[2] - v32[2];
      solver_pp_pk.K_object.k[1] = *v44 - *v32;
      solver_pp_pk.K_object.k[2] = v45;
      solver_pp_pk.K_object.hesse_val = v46;
      solver_pp_pk.K_vec_object.hesse_val = (float)((float)(solver_pp_pk.K_object.k[1] * solver_pp_pk.K_object.k[1])
                                                  + (float)(v45 * v45))
                                          + (float)(v46 * v46);
      *(float *)&cache[1] = IVP_Inline_Math::isqrt_float(quad: solver_pp_pk.K_vec_object.hesse_val);
      v47 = HIDWORD(this->event_time_out.seconds);
      v48 = LODWORD(this->event_time_out.seconds);
      v49 = HIDWORD(this->t_now.seconds);
      solver_pp_pk.K_object.k[1] = solver_pp_pk.K_object.k[1] * *(float *)&cache[1];
      HIDWORD(v51.seconds) = v47;
      v50 = LODWORD(this->t_now.seconds);
      solver_pp_pk.K_object.k[2] = solver_pp_pk.K_object.k[2] * *(float *)&cache[1];
      LODWORD(v51.seconds) = v48;
      solver_pp_pk.K_object.hesse_val = solver_pp_pk.K_object.hesse_val * *(float *)&cache[1];
      if ( IVP_3D_Solver::find_first_t_for_value_max_dev(
             this: (IVP_3D_Solver *)&deviation[1],
             value: (float)(solver_pp_pk.K_vec_object.hesse_val * solver_pp_pk.K_vec_object.k[2]) * *(float *)&cache[1],
             t_now: (IVP_Time)__PAIR64__(v49, v50),
             t_max: v51,
             t_now_cache_index: 0,
             mc_A: (IVP_U_Matrix_Cache *)points_object[0],
             mc_B: v62,
             opt_val_at_t_now: nullptr,
             t_out: &this->event_time_out) != IVP_FALSE )
        this->event_type_out = IVP_COLL_PP_PK;
      if ( max_dist_PP == v68 )
        break;
      max_dist_PP = (IVP_Core *)((char *)max_dist_PP
                               + 4
                               * ((2
                                 * *(_DWORD *)((char *)&max_dist_PP->IVP_Core_Fast_Static
                                             + *(int *)((char *)IVP_Compact_Edge::prev_table + v65))) >> 17)
                               + *(int *)((char *)IVP_Compact_Edge::prev_table + v65));
      v40 = max_dist_PP;
    }
    ++point2;
    inv_len -= 4;
    if ( inv_len <= -8 )
      break;
    v30 = inv_len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098C60
// Name: protected: void IVP_Mindist_Event_Solver::calc_next_event_BP(class IVP_Ball __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Object __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mindist_Event_Solver::calc_next_event_BP(
        IVP_Mindist_Event_Solver *this@<ecx>,
        float a2@<ebp>,
        IVP_Ball *ball,
        const IVP_Compact_Edge *P2,
        IVP_Cache_Object *m_cache_B,
        IVP_Cache_Ledge_Point *m_cache_P2)
{
  IVP_Core *physical_core; // edx
  IVP_Core *v8; // ecx
  int v9; // edi
  const IVP_Compact_Poly_Point *v10; // edi
  IVP_Mindist *mindist; // eax
  float v12; // xmm3_4
  float v13; // xmm1_4
  float max_coll_speed; // xmm0_4
  float v15; // xmm0_4
  long double v16; // st7
  IVP_Core *v17; // eax
  unsigned int v18; // edx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  int v22; // eax
  const IVP_Compact_Edge *v23; // ecx
  int v24; // edx
  const IVP_Compact_Poly_Point *v25; // eax
  float v26; // xmm0_4
  float v27; // xmm1_4
  int seconds_high; // edx
  int seconds_low; // eax
  unsigned int v30; // ecx
  unsigned int v31; // edx
  IVP_Time v32; // [esp+Ch] [ebp-C08h]
  _BYTE v33[12]; // [esp+38h] [ebp-BDCh] BYREF
  IVP_U_Matrix_Cache cache_P; // [esp+44h] [ebp-BD0h] BYREF
  IVP_U_Matrix_Cache cache_P2; // [esp+5F4h] [ebp-620h] BYREF
  IVP_3D_Solver_S_VALS solver_pp_pk; // [esp+BA4h] [ebp-70h] BYREF
  int v37; // [esp+BF4h] [ebp-20h]
  float quad; // [esp+BF8h] [ebp-1Ch]
  float v39; // [esp+BFCh] [ebp-18h]
  float v40; // [esp+C00h] [ebp-14h]
  const IVP_Compact_Edge *qlen; // [esp+C04h] [ebp-10h]
  float inv_len; // [esp+C08h] [ebp-Ch]
  float neg_maximal_safe_s_value; // [esp+C0Ch] [ebp-8h]
  float retaddr; // [esp+C14h] [ebp+0h]

  inv_len = a2;
  neg_maximal_safe_s_value = retaddr;
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)v33, co: m_cache_B);
  IVP_U_Matrix_Cache::p_init(
    this: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
    co: m_cache_P2->clp_cache_object);
  physical_core = ball->physical_core;
  v8 = m_cache_P2->clp_object->physical_core;
  HIDWORD(this->event_time_out.seconds) = HIDWORD(this->t_max.seconds);
  v40 = *(float *)&physical_core;
  LODWORD(this->event_time_out.seconds) = LODWORD(this->t_max.seconds);
  v9 = (int)*P2;
  qlen = (const IVP_Compact_Edge *)v8;
  memset(&solver_pp_pk.IVP_3D_Solver + 1, 0, 12);
  v10 = &m_cache_P2->compact_poly_points[(unsigned __int16)v9];
  mindist = this->mindist;
  solver_pp_pk.P_object.k[1] = v10->k[0];
  solver_pp_pk.P_object.k[2] = v10->k[1];
  solver_pp_pk.P_object.hesse_val = v10->k[2];
  LODWORD(cache_P2.matrizes[20].vv.k[1]) = &IVP_3D_Solver_DISTANCE_OF_TWO_POINTS::`vftable';
  v12 = mindist->contact_plane.k[0];
  v13 = mindist->contact_plane.k[2] * -1.0;
  solver_pp_pk.K_object.k[2] = mindist->contact_plane.k[1] * -1.0;
  max_coll_speed = this->max_coll_speed;
  solver_pp_pk.K_object.hesse_val = v13;
  cache_P2.matrizes[20].vv.k[2] = max_coll_speed;
  solver_pp_pk.K_object.k[1] = v12 * -1.0;
  cache_P2.matrizes[20].vv.hesse_val = 1.0 / max_coll_speed;
  if ( IVP_3D_Solver::find_first_t_for_value_coll(
         this: (IVP_3D_Solver *)&cache_P2.matrizes[20].vv.k[1],
         value: ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 22)]
       + mindist->sum_extra_radius,
         value2: (float)(mindist->sum_extra_radius * 0.5) + ivp_mindist_settings.real_coll_dist,
         t_now: this->t_now,
         t_max: this->t_max,
         mc_A: (IVP_U_Matrix_Cache *)v33,
         mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
         opt_val_at_t_now: nullptr,
         t_out: &this->event_time_out) != IVP_FALSE )
    this->event_type_out = IVP_COLL_PP_COLL;
  v15 = this->event_time_out.seconds - this->t_now.seconds;
  quad = (float)(v15 * this->worst_case_speed) + this->mindist->len_numerator;
  v39 = *(float *)(LODWORD(v40) + 316);
  v40 = *(float *)&qlen[23];
  v16 = IVP_U_Float_Point::fast_real_length(this: &v10->IVP_U_Float_Hesse);
  v17 = m_cache_P2->clp_object->physical_core;
  v18 = *((_DWORD *)&this->mindist->IVP_Mindist_Base + 5);
  *(float *)&qlen = v16 * v40 + *(float *)&qlen[79];
  v19 = (float)(v40 * quad) + (float)(*(float *)&qlen + v39);
  v20 = ivp_mindist_settings.coll_dists[(unsigned __int8)(v18 >> 22)];
  v21 = v20 * v20;
  if ( v21 > (float)(quad * quad) )
    v21 = quad * quad;
  LODWORD(v40) = COERCE_UNSIGNED_INT(v21 * v17->inv_object_diameter) ^ _mask__NegFloat_;
  memset(&solver_pp_pk.IVP_3D_Solver + 1, 0, 12);
  solver_pp_pk.P_object.k[1] = v10->k[0];
  solver_pp_pk.P_object.k[2] = v10->k[1];
  v22 = *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)P2 & 0xC));
  solver_pp_pk.P_object.hesse_val = v10->k[2];
  LODWORD(cache_P2.matrizes[20].vv.k[1]) = &IVP_3D_Solver_S_VALS::`vftable';
  cache_P2.matrizes[20].vv.k[2] = v19;
  cache_P2.matrizes[20].vv.hesse_val = 1.0 / v19;
  v23 = (const IVP_Compact_Edge *)((char *)&P2[(2 * *(_DWORD *)((char *)P2 + v22)) >> 17] + v22);
  for ( qlen = v23; ; v23 = qlen )
  {
    v24 = *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v23 & 0xC));
    v37 = (unsigned __int8)v23 & 0xC;
    v25 = &m_cache_P2->compact_poly_points[(unsigned __int16)*(_DWORD *)((char *)v23 + v24)];
    v26 = v25->k[1] - v10->k[1];
    v27 = v25->k[2] - v10->k[2];
    solver_pp_pk.K_object.k[1] = v25->k[0] - v10->k[0];
    solver_pp_pk.K_object.k[2] = v26;
    solver_pp_pk.K_object.hesse_val = v27;
    quad = (float)((float)(solver_pp_pk.K_object.k[1] * solver_pp_pk.K_object.k[1]) + (float)(v26 * v26))
         + (float)(v27 * v27);
    v39 = IVP_Inline_Math::isqrt_float(quad);
    seconds_high = HIDWORD(this->event_time_out.seconds);
    seconds_low = LODWORD(this->event_time_out.seconds);
    solver_pp_pk.K_object.k[1] = solver_pp_pk.K_object.k[1] * v39;
    v30 = HIDWORD(this->t_now.seconds);
    HIDWORD(v32.seconds) = seconds_high;
    v31 = LODWORD(this->t_now.seconds);
    solver_pp_pk.K_object.k[2] = solver_pp_pk.K_object.k[2] * v39;
    LODWORD(v32.seconds) = seconds_low;
    solver_pp_pk.K_object.hesse_val = solver_pp_pk.K_object.hesse_val * v39;
    if ( IVP_3D_Solver::find_first_t_for_value_max_dev(
           this: (IVP_3D_Solver *)&cache_P2.matrizes[20].vv.k[1],
           value: (float)(quad * v40) * v39,
           t_now: (IVP_Time)__PAIR64__(v30, v31),
           t_max: v32,
           t_now_cache_index: 0,
           mc_A: (IVP_U_Matrix_Cache *)v33,
           mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
           opt_val_at_t_now: nullptr,
           t_out: &this->event_time_out) != IVP_FALSE )
      this->event_type_out = IVP_COLL_PP_PK;
    if ( qlen == P2 )
      break;
    qlen = (const IVP_Compact_Edge *)((char *)qlen
                                    + 4
                                    * ((2
                                      * *(_DWORD *)((char *)qlen + *(int *)((char *)IVP_Compact_Edge::prev_table + v37))) >> 17)
                                    + *(int *)((char *)IVP_Compact_Edge::prev_table + v37));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099020
// Name: protected: void IVP_Mindist_Event_Solver::calc_next_event_BB(class IVP_Cache_Object __near *,class IVP_Cache_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mindist_Event_Solver::calc_next_event_BB(
        IVP_Mindist_Event_Solver *this@<ecx>,
        float a2@<ebp>,
        IVP_Cache_Object *m_cache_A,
        IVP_Cache_Object *m_cache_B)
{
  int seconds_high; // edx
  float v6; // xmm0_4
  IVP_Mindist *mindist; // eax
  _BYTE v8[12]; // [esp+38h] [ebp-BBCh] BYREF
  IVP_U_Matrix_Cache cache_A; // [esp+44h] [ebp-BB0h] BYREF
  IVP_U_Matrix_Cache cache_B; // [esp+5F4h] [ebp-600h] BYREF
  IVP_3D_Solver_DISTANCE_OF_TWO_POINTS solver_pp_coll; // [esp+BA4h] [ebp-50h] BYREF
  float retaddr; // [esp+BF4h] [ebp+0h]

  solver_pp_coll.normized_direction_world_at_t0.k[1] = a2;
  solver_pp_coll.normized_direction_world_at_t0.k[2] = retaddr;
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)v8, co: m_cache_A);
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)&cache_A.matrizes[20].vv.k[1], co: m_cache_B);
  seconds_high = HIDWORD(this->t_max.seconds);
  LODWORD(this->event_time_out.seconds) = LODWORD(this->t_max.seconds);
  HIDWORD(this->event_time_out.seconds) = seconds_high;
  memset(&solver_pp_coll.IVP_3D_Solver + 1, 0, 12);
  memset(&solver_pp_coll.A_object.k[1], 0, 12);
  solver_pp_coll.B_object.k[1] = m_cache_B->m_world_f_object.vv.k[0] - m_cache_A->m_world_f_object.vv.k[0];
  solver_pp_coll.B_object.k[2] = m_cache_B->m_world_f_object.vv.k[1] - m_cache_A->m_world_f_object.vv.k[1];
  v6 = m_cache_B->m_world_f_object.vv.k[2] - m_cache_A->m_world_f_object.vv.k[2];
  LODWORD(cache_B.matrizes[20].vv.k[1]) = &IVP_3D_Solver_DISTANCE_OF_TWO_POINTS::`vftable';
  solver_pp_coll.B_object.hesse_val = v6;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pp_coll.B_object.k[1]);
  mindist = this->mindist;
  cache_B.matrizes[20].vv.k[2] = this->max_coll_speed;
  cache_B.matrizes[20].vv.hesse_val = 1.0 / cache_B.matrizes[20].vv.k[2];
  if ( IVP_3D_Solver::find_first_t_for_value_coll(
         this: (IVP_3D_Solver *)&cache_B.matrizes[20].vv.k[1],
         value: ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 22)]
       + mindist->sum_extra_radius,
         value2: (float)(mindist->sum_extra_radius * 0.5) + ivp_mindist_settings.real_coll_dist,
         t_now: this->t_now,
         t_max: this->t_max,
         mc_A: (IVP_U_Matrix_Cache *)v8,
         mc_B: (IVP_U_Matrix_Cache *)&cache_A.matrizes[20].vv.k[1],
         opt_val_at_t_now: nullptr,
         t_out: &this->event_time_out) != IVP_FALSE )
    this->event_type_out = IVP_COLL_PP_COLL;
}

//------------------------------------------------------------------------------
// Address: 0x10099170
// Name: protected: void IVP_Mindist_Event_Solver::calc_next_event_PK(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mindist_Event_Solver::calc_next_event_PK(
        IVP_Mindist_Event_Solver *this@<ecx>,
        float a2@<ebp>,
        const IVP_Compact_Edge *P,
        const IVP_Compact_Edge *K,
        IVP_Cache_Ledge_Point *m_cache_P,
        IVP_Cache_Ledge_Point *m_cache_K)
{
  IVP_Core *physical_core; // eax
  IVP_Core *v8; // ecx
  float v9; // xmm0_4
  const IVP_Compact_Poly_Point *v10; // esi
  const IVP_Compact_Poly_Point *v11; // eax
  float v12; // xmm0_4
  int v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm1_4
  const IVP_Compact_Poly_Point *v16; // ecx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  IVP_Mindist *mindist; // eax
  float v21; // xmm1_4
  IVP_Cache_Object *clp_cache_object; // ecx
  int v23; // edx
  IVP_3D_SOLVER_TYPE v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  int *v27; // ecx
  int v28; // esi
  const IVP_Compact_Poly_Point *compact_poly_points; // edx
  int v30; // eax
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float *v34; // eax
  int v35; // esi
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float *v39; // esi
  int v40; // ecx
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float *v44; // ecx
  float v45; // xmm4_4
  float v46; // xmm5_4
  float v47; // xmm3_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm1_4
  float v51; // xmm1_4
  IVP_U_Float_Point *v52; // esi
  long double v53; // st7
  IVP_Core *v54; // eax
  long double v55; // st7
  float v56; // xmm0_4
  double v57; // st6
  const IVP_Compact_Poly_Point *v58; // edx
  double v59; // st6
  const IVP_Compact_Poly_Point *v60; // eax
  int v61; // ecx
  float v62; // xmm0_4
  float v63; // xmm1_4
  const IVP_Compact_Poly_Point *v64; // ecx
  float v65; // xmm0_4
  float v66; // xmm1_4
  IVP_Mindist *v67; // eax
  float v68; // xmm0_4
  float v69; // ecx
  int v70; // edx
  const IVP_Compact_Poly_Point *v71; // eax
  float v72; // xmm0_4
  float v73; // xmm1_4
  _BYTE v74[12]; // [esp+38h] [ebp-C5Ch] BYREF
  IVP_U_Matrix_Cache cache_P; // [esp+44h] [ebp-C50h] BYREF
  IVP_U_Matrix_Cache cache_K; // [esp+5F4h] [ebp-6A0h] BYREF
  IVP_U_Point H; // [esp+BA4h] [ebp-F0h] BYREF
  IVP_U_Point K_vec_world; // [esp+BB4h] [ebp-E0h] BYREF
  const IVP_Compact_Edge *FF[2]; // [esp+BC4h] [ebp-D0h]
  IVP_Core *v80; // [esp+BD4h] [ebp-C0h]
  float v81[2]; // [esp+BD8h] [ebp-BCh] BYREF
  IVP_Core *solver_K; // [esp+BE0h] [ebp-B4h]
  IVP_U_Point fhesse_vec; // [esp+BE4h] [ebp-B0h]
  const IVP_Compact_Poly_Point *v84; // [esp+BF4h] [ebp-A0h]
  float v85; // [esp+BF8h] [ebp-9Ch] BYREF
  IVP_Core *solver_P; // [esp+BFCh] [ebp-98h]
  const IVP_U_Float_Point *p_object; // [esp+C00h] [ebp-94h]
  IVP_U_Point v0; // [esp+C04h] [ebp-90h] BYREF
  IVP_3D_Solver_PK_KK solver_pk_kk; // [esp+C14h] [ebp-80h] BYREF
  IVP_Core *v90; // [esp+C74h] [ebp-20h]
  float len_numerator; // [esp+C78h] [ebp-1Ch]
  float value; // [esp+C7Ch] [ebp-18h]
  float v93; // [esp+C80h] [ebp-14h]
  float dist_PK_now; // [esp+C84h] [ebp-10h]
  float sec_dist; // [esp+C88h] [ebp-Ch]
  float sum_abs_omega; // [esp+C8Ch] [ebp-8h]
  float retaddr; // [esp+C94h] [ebp+0h]

  sec_dist = a2;
  sum_abs_omega = retaddr;
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)v74, co: m_cache_P->clp_cache_object);
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1], co: m_cache_K->clp_cache_object);
  physical_core = m_cache_P->clp_object->physical_core;
  v8 = m_cache_K->clp_object->physical_core;
  v9 = physical_core->abs_omega + v8->abs_omega;
  LODWORD(this->event_time_out.seconds) = LODWORD(this->t_max.seconds);
  LODWORD(fhesse_vec.hesse_val) = physical_core;
  HIDWORD(this->event_time_out.seconds) = HIDWORD(this->t_max.seconds);
  v80 = v8;
  v10 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)P];
  v11 = &m_cache_K->compact_poly_points[(unsigned __int16)*(_DWORD *)K];
  LODWORD(v0.k[1]) = &IVP_3D_Solver_PK_COLL::`vftable';
  v93 = v9;
  v12 = v10->k[0];
  LODWORD(value) = (char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC);
  v13 = *(int *)((char *)K + *(_DWORD *)LODWORD(value));
  *((float *)&solver_pk_kk.IVP_3D_Solver + 5) = v12;
  *((_DWORD *)&solver_pk_kk.IVP_3D_Solver + 6) = LODWORD(v10->k[1]);
  *((_DWORD *)&solver_pk_kk.IVP_3D_Solver + 7) = LODWORD(v10->k[2]);
  v14 = v11->k[1];
  v15 = v11->k[2];
  v16 = &m_cache_K->compact_poly_points[(unsigned __int16)v13];
  solver_pk_kk.P_object.k[1] = v11->k[0];
  solver_pk_kk.P_object.k[2] = v14;
  solver_pk_kk.P_object.hesse_val = v15;
  v17 = v16->k[1] - v11->k[1];
  v18 = v16->k[2] - v11->k[2];
  v19 = v16->k[0] - v11->k[0];
  v84 = v10;
  solver_pk_kk.P_ne_vec_object.k[1] = v19;
  solver_pk_kk.P_ne_vec_object.k[2] = v17;
  solver_pk_kk.P_ne_vec_object.hesse_val = v18;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pk_kk.P_ne_vec_object.k[1]);
  mindist = this->mindist;
  v0.k[2] = this->max_coll_speed;
  v0.hesse_val = 1.0 / v0.k[2];
  v21 = ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 22)];
  clp_cache_object = m_cache_P->clp_cache_object;
  dist_PK_now = mindist->sum_extra_radius;
  solver_pk_kk.inv_max_deviation = (float)(v21 + dist_PK_now) * 0.5;
  IVP_Cache_Object::transform_position_to_world_coords(
    this: clp_cache_object,
    P_object: (const IVP_U_Float_Point *)(&solver_pk_kk.IVP_3D_Solver + 1),
    P_world_out: (IVP_U_Point *)&v85);
  IVP_Cache_Object::transform_position_to_world_coords(
    this: m_cache_K->clp_cache_object,
    P_object: (const IVP_U_Float_Point *)&solver_pk_kk.P_object.k[1],
    P_world_out: (IVP_U_Point *)&K_vec_world.k[1]);
  IVP_Cache_Object::transform_vector_to_world_coords(
    this: m_cache_K->clp_cache_object,
    P_object: (const IVP_U_Float_Point *)&solver_pk_kk.P_ne_vec_object.k[1],
    P_world_out: (IVP_U_Point *)&H.k[1]);
  v81[0] = K_vec_world.k[1] - v85;
  v81[1] = K_vec_world.k[2] - *(float *)&solver_P;
  *(float *)&solver_K = K_vec_world.hesse_val - *(float *)&p_object;
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)&cache_K.matrizes[20].vv.k[1],
    v1: (const IVP_U_Float_Point *)v81,
    v2: (IVP_U_Point *)&H.k[1]);
  IVP_Cache_Object::transform_vector_to_object_coords(
    this: m_cache_K->clp_cache_object,
    P_world: (const IVP_U_Float_Point *)&cache_K.matrizes[20].vv.k[1],
    P_object_out: (IVP_U_Float_Point *)&solver_pk_kk.K_object.k[1]);
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pk_kk.K_object.k[1]);
  if ( IVP_3D_Solver::find_first_t_for_value_coll(
         this: (IVP_3D_Solver *)&v0.k[1],
         value: ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&this->mindist->IVP_Mindist_Base + 5) >> 22)]
       + dist_PK_now,
         value2: (float)(dist_PK_now * 0.89999998) + ivp_mindist_settings.real_coll_dist,
         t_now: this->t_now,
         t_max: this->t_max,
         mc_A: (IVP_U_Matrix_Cache *)v74,
         mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
         opt_val_at_t_now: nullptr,
         t_out: &this->event_time_out) != IVP_FALSE )
    this->event_type_out = IVP_COLL_PK_COLL;
  v23 = (int)*K;
  *(float *)&v24 = 1.0 / this->worst_case_speed;
  solver_pk_kk.inv_max_deviation = this->worst_case_speed;
  solver_pk_kk.P_object.k[1] = v10->k[0];
  v25 = v10->k[1];
  LODWORD(K_vec_world.hesse_val) = K;
  solver_pk_kk.P_object.k[2] = v25;
  v26 = v10->k[2];
  LODWORD(solver_pk_kk.max_deviation) = &IVP_3D_Solver_PF_COLL::`vftable';
  solver_pk_kk.type = v24;
  solver_pk_kk.P_object.hesse_val = v26;
  FF[0] = &K[(2 * v23) >> 17];
  dist_PK_now = 0.0;
  do
  {
    v27 = *((int **)&K_vec_world.hesse_val + LODWORD(dist_PK_now));
    v28 = *v27;
    compact_poly_points = m_cache_K->compact_poly_points;
    LODWORD(len_numerator) = (unsigned __int8)v27 & 0xC;
    v30 = (unsigned __int16)*(int *)((char *)v27
                                   + *(int *)((char *)IVP_Compact_Edge::next_table + LODWORD(len_numerator)));
    v31 = compact_poly_points[v30].k[1];
    v32 = compact_poly_points[v30].k[2];
    v33 = compact_poly_points[v30].k[0];
    v34 = compact_poly_points[v30].k;
    v90 = (IVP_Core *)compact_poly_points;
    v35 = (unsigned __int16)v28;
    v36 = v31 - compact_poly_points[v35].k[1];
    v37 = v32 - compact_poly_points[v35].k[2];
    v38 = v33 - compact_poly_points[v35].k[0];
    v39 = compact_poly_points[v35].k;
    v40 = *(int *)((char *)v27 + *(int *)((char *)IVP_Compact_Edge::prev_table + LODWORD(len_numerator)));
    *(float *)&solver_P = v36;
    *(float *)&p_object = v37;
    v85 = v38;
    v41 = v34[2] - v39[2];
    v42 = v34[1] - v39[1];
    v43 = *v34 - *v39;
    v44 = compact_poly_points[(unsigned __int16)v40].k;
    v45 = v44[1] - v39[1];
    v46 = v44[2] - v39[2];
    v47 = *v44 - *v39;
    v81[0] = (float)(v42 * v46) - (float)(v41 * v45);
    v81[1] = (float)(v41 * v47) - (float)(v43 * v46);
    *(float *)&solver_K = (float)(v43 * v45) - (float)(v42 * v47);
    IVP_U_Float_Point::calc_cross_product(
      this: (IVP_U_Float_Point *)&solver_pk_kk.P_ne_vec_object.k[1],
      v1: (const IVP_U_Float_Point *)&v85,
      v2: (const IVP_U_Float_Point *)v81);
    IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pk_kk.P_ne_vec_object.k[1]);
    v48 = v39[2];
    v49 = *v39;
    solver_pk_kk.K_object.k[2] = v39[1];
    solver_pk_kk.K_object.k[1] = v49;
    solver_pk_kk.K_object.hesse_val = v48;
    if ( IVP_3D_Solver::find_first_t_for_value_max_dev(
           this: (IVP_3D_Solver_PK_KK *)&solver_pk_kk.max_deviation,
           value: COERCE_FLOAT(LODWORD(ivp_mindist_settings.mindist_change_force_dist) ^ _mask__NegFloat_),
           t_now: this->t_now,
           t_max: this->event_time_out,
           t_now_cache_index: 0,
           mc_A: (IVP_U_Matrix_Cache *)v74,
           mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
           opt_val_at_t_now: nullptr,
           t_out: &this->event_time_out) != IVP_FALSE )
      this->event_type_out = IVP_COLL_PK_PF;
    ++LODWORD(dist_PK_now);
  }
  while ( SLODWORD(dist_PK_now) <= 1 );
  v50 = this->event_time_out.seconds - this->t_now.seconds;
  v51 = v50 * this->worst_case_speed;
  len_numerator = this->mindist->len_numerator;
  dist_PK_now = len_numerator - v51;
  if ( (float)(len_numerator - v51) < 0.003 )
    dist_PK_now = 0.003;
  v52 = &v84->IVP_U_Float_Hesse;
  v90 = m_cache_P->clp_object->physical_core;
  v53 = IVP_U_Float_Point::fast_real_length(this: &v84->IVP_U_Float_Hesse);
  v54 = m_cache_K->clp_object->physical_core;
  v55 = v53 * *(float *)(LODWORD(fhesse_vec.hesse_val) + 92) + v90->current_speed;
  v56 = v52->k[0];
  v57 = v54->max_surface_rot_speed * v80->abs_omega;
  v58 = m_cache_K->compact_poly_points;
  LODWORD(v0.k[1]) = &IVP_3D_Solver_PK_KK::`vftable';
  v59 = v57 + v54->current_speed;
  v60 = &v58[(unsigned __int16)*(_DWORD *)K];
  v61 = *(int *)((char *)K + *(_DWORD *)LODWORD(value));
  *((float *)&solver_pk_kk.IVP_3D_Solver + 5) = v56;
  *((_DWORD *)&solver_pk_kk.IVP_3D_Solver + 6) = LODWORD(v52->k[1]);
  *((_DWORD *)&solver_pk_kk.IVP_3D_Solver + 7) = LODWORD(v52->k[2]);
  v62 = v60->k[1];
  v63 = v60->k[2];
  v64 = &m_cache_K->compact_poly_points[(unsigned __int16)v61];
  solver_pk_kk.P_ne_vec_object.k[1] = v60->k[0];
  solver_pk_kk.P_ne_vec_object.k[2] = v62;
  solver_pk_kk.P_ne_vec_object.hesse_val = v63;
  v65 = v64->k[1] - v60->k[1];
  v66 = v64->k[2] - v60->k[2];
  solver_pk_kk.K_object.k[1] = v64->k[0] - v60->k[0];
  solver_pk_kk.K_object.k[2] = v65;
  solver_pk_kk.K_object.hesse_val = v66;
  v93 = (v55 + v59) / dist_PK_now + v93;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pk_kk.K_object.k[1]);
  v67 = this->mindist;
  v0.k[2] = v93;
  v0.hesse_val = 1.0 / v93;
  v68 = ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&v67->IVP_Mindist_Base + 5) >> 22)];
  if ( v68 > len_numerator )
    v68 = len_numerator;
  LODWORD(v69) = (char *)&P[(2
                           * *(_DWORD *)((char *)P
                                       + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)P & 0xC)))) >> 17]
               + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)P & 0xC));
  value = (float)(m_cache_K->clp_object->physical_core->inv_object_diameter * 2.0) * (float)(v68 * -0.30000001);
  for ( dist_PK_now = v69; ; v69 = dist_PK_now )
  {
    v70 = *(int *)((char *)IVP_Compact_Edge::next_table + (LOBYTE(v69) & 0xC));
    LODWORD(v93) = LOBYTE(v69) & 0xC;
    v71 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)(LODWORD(v69) + v70)];
    v72 = v71->k[1] - v52->k[1];
    v73 = v71->k[2] - v52->k[2];
    solver_pk_kk.P_object.k[1] = v71->k[0] - v52->k[0];
    solver_pk_kk.P_object.k[2] = v72;
    solver_pk_kk.P_object.hesse_val = v73;
    IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pk_kk.P_object.k[1]);
    if ( IVP_3D_Solver::find_first_t_for_value_max_dev(
           this: (IVP_3D_Solver *)&v0.k[1],
           value,
           t_now: this->t_now,
           t_max: this->event_time_out,
           t_now_cache_index: 0,
           mc_A: (IVP_U_Matrix_Cache *)v74,
           mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
           opt_val_at_t_now: nullptr,
           t_out: &this->event_time_out) != IVP_FALSE )
      this->event_type_out = IVP_COLL_PK_KK;
    if ( (const IVP_Compact_Edge *)LODWORD(dist_PK_now) == P )
      break;
    LODWORD(dist_PK_now) += *(int *)((char *)IVP_Compact_Edge::prev_table + LODWORD(v93))
                          + 4
                          * ((2
                            * *(_DWORD *)(LODWORD(dist_PK_now)
                                        + *(int *)((char *)IVP_Compact_Edge::prev_table + LODWORD(v93)))) >> 17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100998C0
// Name: protected: void IVP_Mindist_Event_Solver::calc_next_event_BK(class IVP_Ball __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Object __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mindist_Event_Solver::calc_next_event_BK(
        IVP_Mindist_Event_Solver *this@<ecx>,
        int a2@<ebp>,
        IVP_Ball *ball,
        const IVP_Compact_Edge *K,
        IVP_Cache_Object *m_cache_B,
        IVP_Cache_Ledge_Point *m_cache_K)
{
  IVP_Cache_Ledge_Point *v7; // esi
  int seconds_high; // edx
  int v9; // eax
  int v10; // ecx
  const IVP_Compact_Poly_Point *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  const IVP_Compact_Poly_Point *v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float max_coll_speed; // xmm0_4
  IVP_Mindist *mindist; // eax
  float v19; // xmm1_4
  IVP_Cache_Object *clp_cache_object; // ecx
  float worst_case_speed; // xmm1_4
  int v22; // edx
  int *v23; // ecx
  const IVP_Compact_Poly_Point *compact_poly_points; // edx
  int v25; // esi
  int v26; // eax
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float *v30; // eax
  int v31; // esi
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float *v35; // esi
  int v36; // ecx
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  const IVP_Compact_Poly_Point *v40; // ecx
  float v41; // xmm4_4
  float v42; // xmm5_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  _BYTE v46[12]; // [esp+38h] [ebp-C1Ch] BYREF
  IVP_U_Matrix_Cache cache_P; // [esp+44h] [ebp-C10h] BYREF
  IVP_U_Matrix_Cache cache_K; // [esp+5F4h] [ebp-660h] BYREF
  IVP_U_Point H; // [esp+BA4h] [ebp-B0h] BYREF
  IVP_3D_Solver_PF_COLL solver_pk_pf; // [esp+BB4h] [ebp-A0h] BYREF
  _DWORD v51[3]; // [esp+C08h] [ebp-4Ch] BYREF
  IVP_U_Point v0; // [esp+C14h] [ebp-40h] BYREF
  const IVP_Compact_Edge *FF[2]; // [esp+C24h] [ebp-30h] BYREF
  float v54; // [esp+C2Ch] [ebp-28h]
  float v55; // [esp+C30h] [ebp-24h]
  IVP_U_Point fhesse_vec; // [esp+C34h] [ebp-20h]
  int sum_extra_radius_low; // [esp+C44h] [ebp-10h]
  int v58; // [esp+C48h] [ebp-Ch]
  void *v59; // [esp+C4Ch] [ebp-8h]
  void *retaddr; // [esp+C54h] [ebp+0h]

  v58 = a2;
  v59 = retaddr;
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)v46, co: m_cache_B);
  v7 = m_cache_K;
  IVP_U_Matrix_Cache::p_init(this: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1], co: m_cache_K->clp_cache_object);
  seconds_high = HIDWORD(this->t_max.seconds);
  LODWORD(this->event_time_out.seconds) = LODWORD(this->t_max.seconds);
  HIDWORD(this->event_time_out.seconds) = seconds_high;
  v9 = (int)*K;
  LODWORD(H.k[1]) = &IVP_3D_Solver_PK_COLL::`vftable';
  v10 = *(int *)((char *)K + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC)));
  memset(&solver_pk_pf.IVP_3D_Solver + 1, 0, 12);
  v11 = &m_cache_K->compact_poly_points[(unsigned __int16)v9];
  v12 = v11->k[1];
  v13 = v11->k[2];
  v14 = &m_cache_K->compact_poly_points[(unsigned __int16)v10];
  solver_pk_pf.point_object.k[1] = v11->k[0];
  solver_pk_pf.point_object.k[2] = v12;
  solver_pk_pf.point_object.hesse_val = v13;
  v15 = v14->k[1] - v11->k[1];
  v16 = v14->k[2] - v11->k[2];
  solver_pk_pf.hesse_of_area_object.k[1] = v14->k[0] - v11->k[0];
  solver_pk_pf.hesse_of_area_object.k[2] = v15;
  solver_pk_pf.hesse_of_area_object.hesse_val = v16;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pk_pf.hesse_of_area_object.k[1]);
  max_coll_speed = this->max_coll_speed;
  mindist = this->mindist;
  H.hesse_val = 1.0 / max_coll_speed;
  H.k[2] = max_coll_speed;
  v19 = ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 22)];
  clp_cache_object = m_cache_K->clp_cache_object;
  sum_extra_radius_low = SLODWORD(mindist->sum_extra_radius);
  solver_pk_pf.inv_max_deviation = (float)(v19 + *(float *)&sum_extra_radius_low) * 0.5;
  IVP_Cache_Object::transform_position_to_world_coords(
    this: clp_cache_object,
    P_object: (const IVP_U_Float_Point *)&solver_pk_pf.point_object.k[1],
    P_world_out: (IVP_U_Point *)&v0.k[1]);
  IVP_Cache_Object::transform_vector_to_world_coords(
    this: m_cache_K->clp_cache_object,
    P_object: (const IVP_U_Float_Point *)&solver_pk_pf.hesse_of_area_object.k[1],
    P_world_out: (IVP_U_Float_Point *)v51);
  *(float *)&FF[1] = v0.k[1] - m_cache_B->m_world_f_object.vv.k[0];
  v54 = v0.k[2] - m_cache_B->m_world_f_object.vv.k[1];
  v55 = v0.hesse_val - m_cache_B->m_world_f_object.vv.k[2];
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)&cache_K.matrizes[20].vv.k[1],
    v1: (const IVP_U_Float_Point *)&FF[1],
    v2: (const IVP_U_Float_Point *)v51);
  IVP_Cache_Object::transform_vector_to_object_coords(
    this: m_cache_K->clp_cache_object,
    P_world: (const IVP_U_Float_Point *)&cache_K.matrizes[20].vv.k[1],
    P_object_out: (IVP_U_Float_Point *)&solver_pk_pf.point_of_area_object.k[1]);
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pk_pf.point_of_area_object.k[1]);
  if ( IVP_3D_Solver::find_first_t_for_value_coll(
         this: (IVP_3D_Solver *)&H.k[1],
         value: ivp_mindist_settings.coll_dists[(unsigned __int8)(*((_DWORD *)&this->mindist->IVP_Mindist_Base + 5) >> 22)]
       + *(float *)&sum_extra_radius_low,
         value2: (float)(*(float *)&sum_extra_radius_low * 0.89999998) + ivp_mindist_settings.real_coll_dist,
         t_now: this->t_now,
         t_max: this->t_max,
         mc_A: (IVP_U_Matrix_Cache *)v46,
         mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
         opt_val_at_t_now: nullptr,
         t_out: &this->event_time_out) != IVP_FALSE )
    this->event_type_out = IVP_COLL_PK_COLL;
  worst_case_speed = this->worst_case_speed;
  v22 = (2 * *(_DWORD *)K) >> 17;
  LODWORD(v0.hesse_val) = K;
  *(float *)&solver_pk_pf.type = 1.0 / worst_case_speed;
  LODWORD(solver_pk_pf.max_deviation) = &IVP_3D_Solver_PF_COLL::`vftable';
  solver_pk_pf.inv_max_deviation = worst_case_speed;
  memset(&solver_pk_pf.point_object.k[1], 0, 12);
  FF[0] = &K[v22];
  *(float *)&sum_extra_radius_low = 0.0;
  while ( 1 )
  {
    v23 = *((int **)&v0.hesse_val + sum_extra_radius_low);
    compact_poly_points = v7->compact_poly_points;
    v25 = *v23;
    LODWORD(fhesse_vec.hesse_val) = (unsigned __int8)v23 & 0xC;
    v26 = (unsigned __int16)*(int *)((char *)v23
                                   + *(int *)((char *)IVP_Compact_Edge::next_table + LODWORD(fhesse_vec.hesse_val)));
    v27 = compact_poly_points[v26].k[1];
    v28 = compact_poly_points[v26].k[2];
    v29 = compact_poly_points[v26].k[0];
    v30 = compact_poly_points[v26].k;
    v31 = (unsigned __int16)v25;
    v32 = v27 - compact_poly_points[v31].k[1];
    v33 = v28 - compact_poly_points[v31].k[2];
    v34 = v29 - compact_poly_points[v31].k[0];
    v35 = compact_poly_points[v31].k;
    v36 = *(int *)((char *)v23 + *(int *)((char *)IVP_Compact_Edge::prev_table + LODWORD(fhesse_vec.hesse_val)));
    *(float *)&v51[1] = v32;
    *(float *)&v51[2] = v33;
    *(float *)v51 = v34;
    v37 = v30[2] - v35[2];
    v38 = v30[1] - v35[1];
    v39 = *v30 - *v35;
    v40 = &m_cache_K->compact_poly_points[(unsigned __int16)v36];
    v41 = v40->k[1] - v35[1];
    v42 = v40->k[2] - v35[2];
    v43 = v40->k[0] - *v35;
    *(float *)&FF[1] = (float)(v38 * v42) - (float)(v37 * v41);
    v54 = (float)(v37 * v43) - (float)(v39 * v42);
    v55 = (float)(v39 * v41) - (float)(v38 * v43);
    IVP_U_Float_Point::calc_cross_product(
      this: (IVP_U_Float_Point *)&solver_pk_pf.hesse_of_area_object.k[1],
      v1: (const IVP_U_Float_Point *)v51,
      v2: (const IVP_U_Float_Point *)&FF[1]);
    IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&solver_pk_pf.hesse_of_area_object.k[1]);
    v44 = v35[2];
    v45 = *v35;
    solver_pk_pf.point_of_area_object.k[2] = v35[1];
    solver_pk_pf.point_of_area_object.k[1] = v45;
    solver_pk_pf.point_of_area_object.hesse_val = v44;
    if ( IVP_3D_Solver::find_first_t_for_value_max_dev(
           this: (IVP_3D_Solver_PF_COLL *)&solver_pk_pf.max_deviation,
           value: COERCE_FLOAT(LODWORD(ivp_mindist_settings.mindist_change_force_dist) ^ _mask__NegFloat_),
           t_now: this->t_now,
           t_max: this->event_time_out,
           t_now_cache_index: 0,
           mc_A: (IVP_U_Matrix_Cache *)v46,
           mc_B: (IVP_U_Matrix_Cache *)&cache_P.matrizes[20].vv.k[1],
           opt_val_at_t_now: nullptr,
           t_out: &this->event_time_out) != IVP_FALSE )
      this->event_type_out = IVP_COLL_PK_PF;
    if ( ++sum_extra_radius_low > 1 )
      break;
    v7 = m_cache_K;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099CF0
// Name: protected: static void IVP_Mindist_Event_Solver::next_event_B_POLY(class IVP_Mindist_Event_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Event_Solver::next_event_B_POLY(IVP_Mindist_Event_Solver *mim)
{
  IVP_Mindist *mindist; // esi
  const IVP_Compact_Edge *edge; // ebx
  IVP_Real_Object *l_obj; // edi
  bool v4; // zf
  IVP_Cache_Object *cache_object; // ecx
  IVP_Real_Object *v6; // esi
  IVP_Cache_Object *v7; // edx
  const IVP_Compact_Ledge *v8; // ebx
  IVP_Cache_Object *v9; // eax
  IVP_Cache_Object *v10; // ecx
  IVP_Cache_Object *v11; // ecx
  IVP_Mindist *v12; // eax
  int status; // eax
  int v14; // eax
  IVP_Cache_Ledge_Point m_cache_1; // [esp+Ch] [ebp-20h] BYREF
  IVP_Mindist *v16; // [esp+20h] [ebp-Ch]
  IVP_Cache_Object *m_cache_0; // [esp+24h] [ebp-8h]
  const IVP_Compact_Edge *e1; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  mindist = mim->mindist;
  edge = mindist->synapse[1].edge;
  l_obj = mindist->synapse[0].l_obj;
  v4 = l_obj->cache_object == nullptr;
  v16 = mindist;
  e1 = edge;
  if ( v4 )
    l_obj->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                            this: l_obj->environment->cache_object_manager,
                            object: l_obj);
  ++l_obj->cache_object->reference_count;
  if ( *(_BYTE *)&l_obj->flags < 8 )
  {
    cache_object = l_obj->cache_object;
    if ( l_obj->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v6 = mindist->synapse[1].l_obj;
  v7 = l_obj->cache_object;
  v8 = (const IVP_Compact_Ledge *)(((unsigned int)edge & 0xFFFFFFF0)
                                 - 16 * ((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) + 1));
  v4 = v6->cache_object == nullptr;
  m_cache_0 = v7;
  m_cache_1.compact_ledge = v8;
  if ( v4 )
  {
    v9 = IVP_Cache_Object_Manager::get_cache_object(this: v6->environment->cache_object_manager, object: v6);
    v7 = m_cache_0;
    v6->cache_object = v9;
  }
  ++v6->cache_object->reference_count;
  if ( *(_BYTE *)&v6->flags < 8 )
  {
    v10 = v6->cache_object;
    if ( v6->environment->current_time_code > v10->valid_until_time_code )
    {
      IVP_Cache_Object::update_cache_object(this: v10);
      v7 = m_cache_0;
    }
  }
  v11 = v6->cache_object;
  m_cache_1.compact_poly_points = (const IVP_Compact_Poly_Point *)((char *)v8 + v8->c_point_offset);
  v12 = v16;
  m_cache_1.clp_cache_object = v11;
  mim->event_type_out = IVP_COLL_NONE;
  status = v12->synapse[1].status;
  m_cache_1.clp_object = v6;
  if ( status != 0 )
  {
    v14 = status - 1;
    if ( v14 != 0 )
    {
      if ( v14 == 1 )
        IVP_Mindist_Event_Solver::calc_next_event_BF(
          this: mim,
          a2: COERCE_FLOAT(&savedregs),
          F: e1,
          m_cache_B: v7,
          m_cache_F: &m_cache_1);
      else
        _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_event.cxx", 1165);
    }
    else
    {
      IVP_Mindist_Event_Solver::calc_next_event_BK(
        this: mim,
        a2: (int)&savedregs,
        ball: (IVP_Ball *)l_obj,
        K: e1,
        m_cache_B: v7,
        m_cache_K: &m_cache_1);
    }
  }
  else
  {
    IVP_Mindist_Event_Solver::calc_next_event_BP(
      this: mim,
      a2: COERCE_FLOAT(&savedregs),
      ball: (IVP_Ball *)l_obj,
      P2: e1,
      m_cache_B: v7,
      m_cache_P2: &m_cache_1);
  }
  --m_cache_0->reference_count;
  --m_cache_1.clp_cache_object->reference_count;
}

//------------------------------------------------------------------------------
// Address: 0x10099E30
// Name: protected: static void IVP_Mindist_Event_Solver::next_event_BB(class IVP_Mindist_Event_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Event_Solver::next_event_BB(IVP_Mindist_Event_Solver *mim)
{
  IVP_Mindist *mindist; // eax
  IVP_Real_Object *l_obj; // esi
  IVP_Real_Object *v3; // edi
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v5; // esi
  IVP_Cache_Object *v6; // ecx
  IVP_Cache_Object *v7; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  mindist = mim->mindist;
  l_obj = mindist->synapse[0].l_obj;
  v3 = mindist->synapse[1].l_obj;
  if ( l_obj->cache_object == nullptr )
    l_obj->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                            this: l_obj->environment->cache_object_manager,
                            object: l_obj);
  ++l_obj->cache_object->reference_count;
  if ( *(_BYTE *)&l_obj->flags < 8 )
  {
    cache_object = l_obj->cache_object;
    if ( l_obj->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v5 = l_obj->cache_object;
  if ( v3->cache_object == nullptr )
    v3->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                         this: v3->environment->cache_object_manager,
                         object: v3);
  ++v3->cache_object->reference_count;
  if ( *(_BYTE *)&v3->flags < 8 )
  {
    v6 = v3->cache_object;
    if ( v3->environment->current_time_code > v6->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: v6);
  }
  v7 = v3->cache_object;
  mim->event_type_out = IVP_COLL_NONE;
  IVP_Mindist_Event_Solver::calc_next_event_BB(this: mim, a2: COERCE_FLOAT(&savedregs), m_cache_A: v5, m_cache_B: v7);
  --v5->reference_count;
  --v7->reference_count;
}

//------------------------------------------------------------------------------
// Address: 0x10099EE0
// Name: protected: static void IVP_Mindist_Event_Solver::next_event_default_poly_poly(class IVP_Mindist_Event_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Event_Solver::next_event_default_poly_poly(IVP_Mindist_Event_Solver *mim)
{
  IVP_Mindist *mindist; // ecx
  int v2; // ebx
  const IVP_Compact_Edge *edge; // eax
  IVP_Synapse_Real *v4; // ecx
  int v5; // edx
  int v6; // esi
  const IVP_Compact_Edge *v7; // ecx
  const IVP_Compact_Edge *v8; // edi
  bool v9; // zf
  IVP_Cache_Object *cache_object; // eax
  IVP_Cache_Object *v11; // eax
  IVP_Real_Object *l_obj; // esi
  const IVP_Compact_Ledge *v13; // edi
  IVP_Cache_Object *v14; // eax
  IVP_Cache_Object *v15; // eax
  IVP_Cache_Ledge_Point m_cache_1; // [esp+Ch] [ebp-34h] BYREF
  IVP_Cache_Ledge_Point m_cache_0; // [esp+20h] [ebp-20h] BYREF
  IVP_Synapse_Real *syn1; // [esp+34h] [ebp-Ch]
  const IVP_Compact_Edge *e0; // [esp+38h] [ebp-8h]
  const IVP_Compact_Edge *e1; // [esp+3Ch] [ebp-4h]
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  mindist = mim->mindist;
  v2 = (int)&mindist->synapse[(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 8) & 3];
  edge = mindist->synapse[(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 8) & 3].edge;
  v4 = (IVP_Synapse_Real *)&mindist->synapse[((*((_DWORD *)&mindist->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3];
  e0 = edge;
  edge = (const IVP_Compact_Edge *)((unsigned int)edge & 0xFFFFFFF0);
  v5 = 16 * ((*(_DWORD *)edge & 0xFFF) + 1);
  v6 = *(_DWORD *)(v2 + 16);
  syn1 = v4;
  v7 = v4->edge;
  v8 = &edge[v5 / 0xFFFFFFFC];
  m_cache_0.compact_ledge = (const IVP_Compact_Ledge *)&edge[v5 / 0xFFFFFFFC];
  v9 = *(_DWORD *)(v6 + 64) == 0;
  e1 = v7;
  if ( v9 )
  {
    cache_object = IVP_Cache_Object_Manager::get_cache_object(
                     this: *(IVP_Cache_Object_Manager **)(*(_DWORD *)(v6 + 24) + 144),
                     object: (IVP_Real_Object *)v6);
    v7 = e1;
    *(_DWORD *)(v6 + 64) = cache_object;
  }
  ++*(_DWORD *)(*(_DWORD *)(v6 + 64) + 100);
  if ( *(char *)(v6 + 68) < 8 )
  {
    v11 = *(IVP_Cache_Object **)(v6 + 64);
    if ( *(_DWORD *)(*(_DWORD *)(v6 + 24) + 264) > v11->valid_until_time_code )
    {
      IVP_Cache_Object::update_cache_object(this: v11);
      v7 = e1;
    }
  }
  m_cache_0.clp_cache_object = *(IVP_Cache_Object **)(v6 + 64);
  m_cache_0.clp_object = (IVP_Real_Object *)v6;
  m_cache_0.compact_poly_points = (const IVP_Compact_Poly_Point *)((char *)v8 + *(_DWORD *)v8);
  l_obj = syn1->l_obj;
  v13 = (const IVP_Compact_Ledge *)(((unsigned int)v7 & 0xFFFFFFF0)
                                  - 16 * ((*(_DWORD *)((unsigned int)v7 & 0xFFFFFFF0) & 0xFFF) + 1));
  m_cache_1.compact_ledge = v13;
  if ( l_obj->cache_object == nullptr )
  {
    v14 = IVP_Cache_Object_Manager::get_cache_object(this: l_obj->environment->cache_object_manager, object: l_obj);
    v7 = e1;
    l_obj->cache_object = v14;
  }
  ++l_obj->cache_object->reference_count;
  if ( *(_BYTE *)&l_obj->flags < 8 )
  {
    v15 = l_obj->cache_object;
    if ( l_obj->environment->current_time_code > v15->valid_until_time_code )
    {
      IVP_Cache_Object::update_cache_object(this: v15);
      v7 = e1;
    }
  }
  m_cache_1.clp_cache_object = l_obj->cache_object;
  m_cache_1.clp_object = l_obj;
  m_cache_1.compact_poly_points = (const IVP_Compact_Poly_Point *)((char *)v13 + v13->c_point_offset);
  mim->event_type_out = IVP_COLL_NONE;
  if ( *(_WORD *)(v2 + 26) != 0 )
  {
    if ( *(_WORD *)(v2 + 26) == 1 )
    {
      if ( syn1->status == 1 )
      {
        IVP_Mindist_Event_Solver::calc_next_event_KK(
          this: mim,
          a2: (int)&savedregs,
          K: e0,
          L: v7,
          m_cache_K: &m_cache_0,
          m_cache_L: &m_cache_1);
        --m_cache_0.clp_cache_object->reference_count;
        --m_cache_1.clp_cache_object->reference_count;
        return;
      }
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_event.cxx", 1242);
    }
    else
    {
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_event.cxx", 1247);
    }
    goto LABEL_21;
  }
  if ( syn1->status != 0 )
  {
    if ( syn1->status == 1 )
    {
      IVP_Mindist_Event_Solver::calc_next_event_PK(
        this: mim,
        a2: COERCE_FLOAT(&savedregs),
        P: e0,
        K: v7,
        m_cache_P: &m_cache_0,
        m_cache_K: &m_cache_1);
      --m_cache_0.clp_cache_object->reference_count;
      --m_cache_1.clp_cache_object->reference_count;
    }
    else
    {
      if ( syn1->status != 2 )
      {
        _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_event.cxx", 1231);
LABEL_21:
        --m_cache_0.clp_cache_object->reference_count;
        --m_cache_1.clp_cache_object->reference_count;
        return;
      }
      IVP_Mindist_Event_Solver::calc_next_event_PF(
        this: mim,
        a2: (const IVP_U_Float_Point *)&savedregs,
        P: e0,
        F: v7,
        m_cache_P: &m_cache_0,
        m_cache_F: &m_cache_1);
      --m_cache_0.clp_cache_object->reference_count;
      --m_cache_1.clp_cache_object->reference_count;
    }
  }
  else
  {
    IVP_Mindist_Event_Solver::calc_next_event_PP(
      this: mim,
      a2: (const IVP_U_Float_Point *)&savedregs,
      P: (IVP_Cache_Ledge_Point *)e0,
      P2: v7,
      m_cache_P: &m_cache_0,
      m_cache_P2: &m_cache_1);
    --m_cache_0.clp_cache_object->reference_count;
    --m_cache_1.clp_cache_object->reference_count;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A120
// Name: public: static void IVP_Mindist_Event_Solver::init_mim_function_table(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IVP_Mindist_Event_Solver::init_mim_function_table()
{
  int *v0; // eax

  v0 = &dword_100FEF5C;
  do
  {
    *(v0 - 1) = (int)IVP_Mindist_Event_Solver::next_event_illegal;
    *v0 = (int)IVP_Mindist_Event_Solver::next_event_illegal;
    v0[1] = (int)IVP_Mindist_Event_Solver::next_event_illegal;
    v0[2] = (int)IVP_Mindist_Event_Solver::next_event_illegal;
    v0 += 4;
  }
  while ( (int)v0 < (int)&vec2_origin_106.y );
  IVP_Mindist_Event_Solver::mim_function_table[0][0] = IVP_Mindist_Event_Solver::next_event_default_poly_poly;
  dword_100FEF5C = (int)IVP_Mindist_Event_Solver::next_event_default_poly_poly;
  dword_100FEF60 = (int)IVP_Mindist_Event_Solver::next_event_default_poly_poly;
  dword_100FEF6C = (int)IVP_Mindist_Event_Solver::next_event_default_poly_poly;
  dword_100FEF64 = (int)IVP_Mindist_Event_Solver::next_event_illegal;
  dword_100FEF68 = (int)IVP_Mindist_Event_Solver::next_event_illegal;
  dword_100FEF70 = (int)IVP_Mindist_Event_Solver::next_event_illegal;
  dword_100FEF74 = (int)IVP_Mindist_Event_Solver::next_event_illegal;
  dword_100FEF78 = (int)IVP_Mindist_Event_Solver::next_event_illegal;
  dword_100FEF7C = (int)IVP_Mindist_Event_Solver::next_event_illegal;
  dword_100FEF80 = (int)IVP_Mindist_Event_Solver::next_event_illegal;
  dword_100FEF84 = (int)IVP_Mindist_Event_Solver::next_event_illegal;
  dword_100FEF88 = (int)IVP_Mindist_Event_Solver::next_event_B_POLY;
  dword_100FEF8C = (int)IVP_Mindist_Event_Solver::next_event_B_POLY;
  dword_100FEF90 = (int)IVP_Mindist_Event_Solver::next_event_B_POLY;
  dword_100FEF94 = (int)IVP_Mindist_Event_Solver::next_event_BB;
}
