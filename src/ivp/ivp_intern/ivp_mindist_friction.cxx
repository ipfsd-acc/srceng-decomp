// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_mindist_friction.cxx
// Functions: 9
// ============================================================

#include "ivp\ivp_intern\ivp_mindist_friction.h"

//------------------------------------------------------------------------------
// Address: 0x1008A0A0
// Name: private: void IVP_Contact_Point::p_calc_friction_qr_PF(class IVP_U_Point const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Impact_Solver_Long_Term __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Contact_Point::p_calc_friction_qr_PF(
        IVP_Contact_Point *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Point *pp,
        const IVP_Compact_Edge *F,
        IVP_Cache_Ledge_Point *m_cache_F,
        IVP_Impact_Solver_Long_Term *info,
        IVP_U_Float_Point *diff_contact_vec)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float inv_triangle_det; // xmm0_4
  IVP_Cache_Object *clp_cache_object; // ecx
  const IVP_Compact_Poly_Point *v11; // eax
  float v12; // xmm1_4
  const IVP_Compact_Poly_Point *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  IVP_Cache_Object *v17; // ecx
  _DWORD v18[3]; // [esp-Ch] [ebp-5Ch] BYREF
  IVP_U_Float_Point qvec_Fos; // [esp+0h] [ebp-50h] BYREF
  IVP_U_Point hesse_vec_ws; // [esp+10h] [ebp-40h] BYREF
  IVP_U_Point pp_Fos; // [esp+20h] [ebp-30h] BYREF
  IVP_Contact_Point *v22; // [esp+40h] [ebp-10h]
  int v23; // [esp+44h] [ebp-Ch]
  void *v24; // [esp+48h] [ebp-8h]
  void *retaddr; // [esp+50h] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  v7 = pp->k[1];
  v8 = pp->k[2];
  info->contact_point_ws.k[0] = pp->k[0];
  v22 = this;
  info->contact_point_ws.k[1] = v7;
  info->contact_point_ws.k[2] = v8;
  IVP_Cache_Object::transform_position_to_object_coords(
    this: m_cache_F->clp_cache_object,
    P_world: pp,
    P_object_out: (IVP_U_Point *)&hesse_vec_ws.k[1]);
  if ( *((_BYTE *)&v22->IVP_Contact_Point_Fast + 93) == 1 )
  {
    *((_BYTE *)&v22->IVP_Contact_Point_Fast + 93) = 0;
    IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
      c_ledge: m_cache_F->compact_ledge,
      tri: (int)F,
      p_object: (IVP_U_Point *)&hesse_vec_ws.k[1],
      result: (IVP_Unscaled_QR_Result *)&pp_Fos.k[1]);
    if ( (LODWORD(pp_Fos.k[1]) | LODWORD(pp_Fos.hesse_val) | LODWORD(pp_Fos.k[2])) < 0 )
      info->friction_is_broken = 1;
  }
  IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
    edge: F,
    ledge: m_cache_F->compact_ledge,
    out_vec: (IVP_U_Point *)&pp_Fos.k[1]);
  inv_triangle_det = v22->inv_triangle_det;
  pp_Fos.k[1] = pp_Fos.k[1] * inv_triangle_det;
  pp_Fos.k[2] = pp_Fos.k[2] * inv_triangle_det;
  clp_cache_object = m_cache_F->clp_cache_object;
  pp_Fos.hesse_val = pp_Fos.hesse_val * inv_triangle_det;
  IVP_Cache_Object::transform_vector_to_world_coords(
    this: clp_cache_object,
    P_object: (IVP_U_Point *)&pp_Fos.k[1],
    P_world_out: (IVP_U_Float_Point *)&qvec_Fos.k[1]);
  v11 = &m_cache_F->compact_poly_points[(unsigned __int16)*(_DWORD *)F];
  v12 = qvec_Fos.k[1] * -1.0;
  v13 = &m_cache_F->compact_poly_points[(unsigned __int16)*(_DWORD *)((char *)F
                                                                    + *(int *)((char *)IVP_Compact_Edge::next_table
                                                                             + ((unsigned __int8)F & 0xC)))];
  v22->last_gap_len = (float)((float)((float)(hesse_vec_ws.k[2] * pp_Fos.k[2]) + (float)(hesse_vec_ws.k[1] * pp_Fos.k[1]))
                            + (float)(hesse_vec_ws.hesse_val * pp_Fos.hesse_val))
                    - (float)((float)((float)(v11->k[0] * pp_Fos.k[1]) + (float)(v11->k[1] * pp_Fos.k[2]))
                            + (float)(v11->k[2] * pp_Fos.hesse_val));
  info->surf_normal.k[0] = v12;
  info->surf_normal.k[1] = qvec_Fos.k[2] * -1.0;
  info->surf_normal.k[2] = qvec_Fos.hesse_val * -1.0;
  v14 = v13->k[1] - v11->k[1];
  v15 = v13->k[2] - v11->k[2];
  v16 = v13->k[0] - v11->k[0];
  v17 = m_cache_F->clp_cache_object;
  *(float *)v18 = v16;
  *(float *)&v18[1] = v14;
  *(float *)&v18[2] = v15;
  IVP_Cache_Object::transform_vector_to_world_coords(
    this: v17,
    P_object: (const IVP_U_Float_Point *)v18,
    P_world_out: info->span_friction_v);
}

//------------------------------------------------------------------------------
// Address: 0x1008A280
// Name: private: void IVP_Contact_Point::p_calc_friction_s_PK(class IVP_U_Point const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Impact_Solver_Long_Term __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Contact_Point::p_calc_friction_s_PK(
        IVP_Contact_Point *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Point *pp,
        const IVP_Compact_Edge *K,
        IVP_Cache_Ledge_Point *m_cache_K,
        IVP_Impact_Solver_Long_Term *info,
        IVP_U_Float_Point *diff_contact_vec)
{
  float v8; // xmm3_4
  float v9; // xmm3_4
  long double v10; // st7
  long double v11; // st7
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // eax
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22[3]; // [esp+14h] [ebp-6Ch] BYREF
  IVP_U_Point tp; // [esp+20h] [ebp-60h] BYREF
  IVP_U_Point tp_next; // [esp+30h] [ebp-50h]
  IVP_U_Float_Point vec2; // [esp+40h] [ebp-40h]
  IVP_U_Float_Point vec1; // [esp+50h] [ebp-30h] BYREF
  IVP_U_Float_Point vert_12; // [esp+60h] [ebp-20h]
  float v28; // [esp+70h] [ebp-10h]
  int v29; // [esp+74h] [ebp-Ch]
  float distance; // [esp+78h] [ebp-8h]
  float retaddr; // [esp+80h] [ebp+0h]

  v29 = a2;
  distance = retaddr;
  LODWORD(vert_12.k[2]) = this;
  IVP_Compact_Ledge_Solver::give_world_coords_AT(edge: K, clp: m_cache_K, p_ws_out: (IVP_U_Point *)v22);
  IVP_Compact_Ledge_Solver::give_world_coords_AT(
    edge: (const IVP_Compact_Edge *)((char *)K + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC))),
    clp: m_cache_K,
    p_ws_out: (IVP_U_Point *)&tp.k[1]);
  tp_next.k[1] = pp->k[0] - v22[0];
  v8 = pp->k[1] - v22[1];
  vec2.k[2] = tp.k[2] - v22[1];
  vec2.k[1] = tp.k[1] - v22[0];
  tp_next.k[2] = v8;
  v9 = pp->k[2] - v22[2];
  vec2.hesse_val = tp.hesse_val - v22[2];
  tp_next.hesse_val = v9;
  v28 = IVP_Inline_Math::isqrt_float(
          quad: (float)((float)(vec2.k[2] * vec2.k[2]) + (float)(vec2.k[1] * vec2.k[1]))
        + (float)(vec2.hesse_val * vec2.hesse_val));
  vec1.k[1] = (float)(tp_next.hesse_val * vec2.k[2]) - (float)(tp_next.k[2] * vec2.hesse_val);
  vec1.k[2] = (float)(vec2.hesse_val * tp_next.k[1]) - (float)(tp_next.hesse_val * vec2.k[1]);
  vec1.hesse_val = (float)(tp_next.k[2] * vec2.k[1]) - (float)(vec2.k[2] * tp_next.k[1]);
  v10 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&vec1.k[1]);
  v11 = v10 * v28;
  v12 = 0.0;
  vert_12.hesse_val = v11;
  this->last_gap_len = v11;
  if ( v11 * v11 <= 1.0e-10 )
  {
    v13 = 1.0;
    v14 = 0.0;
  }
  else
  {
    v13 = vec1.k[1] * (float)(v28 / vert_12.hesse_val);
    v12 = vec1.k[2] * (float)(v28 / vert_12.hesse_val);
    v14 = vec1.hesse_val * (float)(v28 / vert_12.hesse_val);
  }
  v15 = vec2.k[2];
  info->surf_normal.k[0] = (float)(v14 * vec2.k[2]) - (float)(v12 * vec2.hesse_val);
  vec1.k[2] = v12;
  vec1.hesse_val = v14;
  v16 = (float)(v12 * vec2.k[1]) - (float)(v15 * v13);
  vec1.k[1] = v13;
  info->surf_normal.k[1] = (float)(vec2.hesse_val * v13) - (float)(v14 * vec2.k[1]);
  info->surf_normal.k[2] = v16;
  IVP_U_Float_Point::fast_normize(this: &info->surf_normal);
  v17 = pp->k[1];
  v18 = pp->k[2];
  info->contact_point_ws.k[0] = pp->k[0];
  v19 = vert_12.k[2];
  info->contact_point_ws.k[1] = v17;
  v20 = vec1.k[1];
  info->contact_point_ws.k[2] = v18;
  info->span_friction_v[0].k[0] = v20;
  info->span_friction_v[0].k[1] = vec1.k[2];
  info->span_friction_v[0].k[2] = vec1.hesse_val;
  if ( *(_BYTE *)(LODWORD(v19) + 93) == 1 )
  {
    v21 = (float)((float)((float)(tp_next.k[2] * vec2.k[2]) + (float)(tp_next.k[1] * vec2.k[1]))
                + (float)(tp_next.hesse_val * vec2.hesse_val))
        * (float)(v28 * v28);
    *(_BYTE *)(LODWORD(v19) + 93) = 0;
    if ( v21 < 0.0 || v21 > 1.0 )
      info->friction_is_broken = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A500
// Name: private: void IVP_Contact_Point::p_calc_friction_ss_KK(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Impact_Solver_Long_Term __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Contact_Point::p_calc_friction_ss_KK(
        IVP_Contact_Point *this@<ecx>,
        int a2@<ebp>,
        const IVP_Compact_Edge *K,
        const IVP_Compact_Edge *L,
        IVP_Cache_Ledge_Point *m_cache_K,
        IVP_Cache_Ledge_Point *m_cache_L,
        IVP_Impact_Solver_Long_Term *info,
        IVP_U_Float_Point *diff_contact_vec)
{
  float v9; // xmm0_4
  float v10; // xmm4_4
  float hesse_val; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  long double v14; // st7
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21[3]; // [esp+14h] [ebp-FCh] BYREF
  IVP_U_Point world_edge_space1; // [esp+20h] [ebp-F0h] BYREF
  IVP_U_Point L_area; // [esp+30h] [ebp-E0h] BYREF
  IVP_U_Point K_area; // [esp+40h] [ebp-D0h] BYREF
  IVP_U_Point Lvec; // [esp+50h] [ebp-C0h] BYREF
  IVP_U_Point world_edge_space0; // [esp+60h] [ebp-B0h] BYREF
  IVP_U_Point world_diff_vec; // [esp+70h] [ebp-A0h]
  float v28; // [esp+80h] [ebp-90h]
  float v29; // [esp+84h] [ebp-8Ch] BYREF
  float length; // [esp+88h] [ebp-88h]
  float quad_dist; // [esp+8Ch] [ebp-84h]
  float s; // [esp+A0h] [ebp-70h]
  float v33[2]; // [esp+A4h] [ebp-6Ch] BYREF
  float sk; // [esp+ACh] [ebp-64h]
  IVP_U_Point Lp_next; // [esp+B0h] [ebp-60h] BYREF
  IVP_U_Point norm; // [esp+C0h] [ebp-50h] BYREF
  IVP_U_Point Kvec; // [esp+D0h] [ebp-40h] BYREF
  IVP_U_Point Kp; // [esp+E0h] [ebp-30h] BYREF
  float v39; // [esp+100h] [ebp-10h]
  int v40; // [esp+104h] [ebp-Ch]
  void *v41; // [esp+108h] [ebp-8h]
  void *retaddr; // [esp+110h] [ebp+0h]

  v40 = a2;
  v41 = retaddr;
  IVP_Compact_Ledge_Solver::give_world_coords_AT(edge: K, clp: m_cache_K, p_ws_out: (IVP_U_Point *)&Kvec.k[1]);
  IVP_Compact_Ledge_Solver::give_world_coords_AT(
    edge: (const IVP_Compact_Edge *)((char *)K + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC))),
    clp: m_cache_K,
    p_ws_out: (IVP_U_Point *)&v29);
  IVP_Compact_Ledge_Solver::give_world_coords_AT(edge: L, clp: m_cache_L, p_ws_out: (IVP_U_Point *)&Kp.k[1]);
  IVP_Compact_Ledge_Solver::give_world_coords_AT(
    edge: (const IVP_Compact_Edge *)((char *)L + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)L & 0xC))),
    clp: m_cache_L,
    p_ws_out: (IVP_U_Point *)v33);
  K_area.k[1] = v33[0] - Kp.k[1];
  K_area.k[2] = v33[1] - Kp.k[2];
  K_area.hesse_val = sk - Kp.hesse_val;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Point *)&K_area.k[1]);
  norm.k[1] = v29 - Kvec.k[1];
  norm.k[2] = length - Kvec.k[2];
  norm.hesse_val = quad_dist - Kvec.hesse_val;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Point *)&norm.k[1]);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Point *)&Lp_next.k[1],
    v1: (IVP_U_Point *)&norm.k[1],
    v2: (IVP_U_Point *)&K_area.k[1]);
  v28 = (float)((float)(Lp_next.k[2] * Lp_next.k[2]) + (float)(Lp_next.k[1] * Lp_next.k[1]))
      + (float)(Lp_next.hesse_val * Lp_next.hesse_val);
  if ( v28 <= 1.0e-10
    || (IVP_U_Float_Point::calc_cross_product(
          this: (IVP_U_Point *)&L_area.k[1],
          v1: (IVP_U_Point *)&norm.k[1],
          v2: (IVP_U_Point *)&Lp_next.k[1]),
        IVP_U_Float_Point::calc_cross_product(
          this: (IVP_U_Point *)&world_edge_space1.k[1],
          v1: (IVP_U_Point *)&K_area.k[1],
          v2: (IVP_U_Point *)&Lp_next.k[1]),
        v9 = (float)((float)(L_area.k[1] * Kp.k[1]) + (float)(L_area.k[2] * Kp.k[2]))
           + (float)(L_area.hesse_val * Kp.hesse_val),
        v10 = v9
            - (float)((float)((float)(L_area.k[1] * v33[0]) + (float)(L_area.k[2] * v33[1]))
                    + (float)(L_area.hesse_val * sk)),
        COERCE_FLOAT(LODWORD(v10) & _mask__AbsFloat_) < 1.0e-10) )
  {
    hesse_val = Kvec.hesse_val;
    goto friction_error;
  }
  hesse_val = Kvec.hesse_val;
  v39 = (float)(v9
              - (float)((float)((float)(L_area.k[1] * Kvec.k[1]) + (float)(L_area.k[2] * Kvec.k[2]))
                      + (float)(L_area.hesse_val * Kvec.hesse_val)))
      * (float)(1.0 / v10);
  v12 = (float)((float)(world_edge_space1.k[1] * Kvec.k[1]) + (float)(world_edge_space1.k[2] * Kvec.k[2]))
      + (float)(world_edge_space1.hesse_val * Kvec.hesse_val);
  v13 = v12
      - (float)((float)((float)(world_edge_space1.k[1] * v29) + (float)(world_edge_space1.k[2] * length))
              + (float)(world_edge_space1.hesse_val * quad_dist));
  if ( COERCE_FLOAT(LODWORD(v13) & _mask__AbsFloat_) < 1.0e-10 )
  {
friction_error:
    info->friction_is_broken = 1;
    *(_QWORD *)&diff_contact_vec->k[1] = 0;
    diff_contact_vec->k[0] = 0.0;
    this->last_gap_len = ivp_mindist_settings.keeper_dist;
    info->contact_point_ws.k[0] = Kvec.k[1];
    info->contact_point_ws.k[1] = Kvec.k[2];
    info->contact_point_ws.k[2] = hesse_val;
    info->surf_normal.k[0] = 1.0;
    info->surf_normal.k[1] = 0.0;
    info->surf_normal.k[2] = 0.0;
    info->span_friction_v[0].k[0] = 0.0;
    info->span_friction_v[0].k[1] = 1.0;
    info->span_friction_v[0].k[2] = 0.0;
    return;
  }
  s = (float)(v12
            - (float)((float)((float)(world_edge_space1.k[1] * Kp.k[1]) + (float)(world_edge_space1.k[2] * Kp.k[2]))
                    + (float)(world_edge_space1.hesse_val * Kp.hesse_val)))
    * (float)(1.0 / v13);
  IVP_U_Float_Point::set_interpolate(
    this: (IVP_U_Point *)&Lvec.k[1],
    p0: (IVP_U_Point *)&Kvec.k[1],
    p1: (const IVP_U_Float_Point *)&v29,
    s);
  IVP_U_Float_Point::set_interpolate(
    this: (IVP_U_Float_Point *)v21,
    p0: (IVP_U_Point *)&Kp.k[1],
    p1: (const IVP_U_Float_Point *)v33,
    s: v39);
  world_edge_space0.k[1] = v21[0] - Lvec.k[1];
  world_edge_space0.k[2] = v21[1] - Lvec.k[2];
  world_edge_space0.hesse_val = v21[2] - Lvec.hesse_val;
  v14 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Point *)&world_edge_space0.k[1]);
  world_diff_vec.hesse_val = v14;
  if ( v14 <= 1.0e-10 )
  {
    v16 = 1.0 / fsqrt(v28);
    this->last_gap_len = 0.0;
    info->surf_normal.k[0] = v16 * Lp_next.k[1];
    info->surf_normal.k[1] = Lp_next.k[2] * v16;
    v17 = Lp_next.hesse_val;
  }
  else
  {
    v15 = world_diff_vec.hesse_val;
    this->last_gap_len = world_diff_vec.hesse_val;
    v16 = 1.0 / v15;
    info->surf_normal.k[0] = world_edge_space0.k[1] * (float)(1.0 / v15);
    info->surf_normal.k[1] = world_edge_space0.k[2] * (float)(1.0 / v15);
    v17 = world_edge_space0.hesse_val;
  }
  v18 = v17 * v16;
  v19 = norm.k[1];
  info->surf_normal.k[2] = v18;
  info->span_friction_v[0].k[0] = v19;
  info->span_friction_v[0].k[1] = norm.k[2];
  info->span_friction_v[0].k[2] = norm.hesse_val;
  info->contact_point_ws.k[0] = Lvec.k[1];
  info->contact_point_ws.k[1] = Lvec.k[2];
  info->contact_point_ws.k[2] = Lvec.hesse_val;
  if ( *((_BYTE *)&this->IVP_Contact_Point_Fast + 93) == 1 )
  {
    v20 = v39;
    *((_BYTE *)&this->IVP_Contact_Point_Fast + 93) = 0;
    if ( v20 < 0.0 || v20 > 1.0 || s < 0.0 || s > 1.0 )
      info->friction_is_broken = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AA00
// Name: private: void IVP_Contact_Point::reset_time(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Contact_Point::reset_time(IVP_Contact_Point *this, IVP_Time offset)
{
  this->last_time_of_recalc_friction_s_vals.seconds = this->last_time_of_recalc_friction_s_vals.seconds - offset.seconds;
}

//------------------------------------------------------------------------------
// Address: 0x1008AA20
// Name: public: void IVP_Contact_Point::get_contact_normal(class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Contact_Point::get_contact_normal(IVP_Contact_Point *this, IVP_U_Float_Point *pOut)
{
  *(_QWORD *)pOut->k = *(_QWORD *)this->last_contact_normal;
  pOut->k[2] = this->last_contact_point_ws.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x1008AA50
// Name: public: static class IVP_Contact_Point __near * IVP_Friction_Manager::get_associated_contact_point(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Contact_Point *__cdecl IVP_Friction_Manager::get_associated_contact_point(IVP_Mindist *mindist)
{
  const IVP_Synapse_Real *v1; // eax
  IVP_Real_Object *l_obj; // ebx
  IVP_Synapse_Friction *friction_synapses; // edi
  IVP_Contact_Point *v4; // esi

  v1 = (const IVP_Synapse_Real *)mindist;
  l_obj = mindist->synapse[1].l_obj;
  friction_synapses = mindist->synapse[0].l_obj->friction_synapses;
  if ( friction_synapses == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = (IVP_Contact_Point *)((char *)friction_synapses + friction_synapses->contact_point_offset);
    if ( v4->synapse[0].l_obj == l_obj || v4->synapse[1].l_obj == l_obj )
    {
      if ( IVP_Contact_Point::is_same_as(this: v4, md2: v1) )
        break;
      v1 = (const IVP_Synapse_Real *)mindist;
    }
    friction_synapses = friction_synapses->next;
    if ( friction_synapses == nullptr )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1008AAA0
// Name: public: static class IVP_Contact_Point __near * IVP_Friction_Manager::generate_contact_point(class IVP_Mindist __near *,enum IVP_BOOL __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Contact_Point *__usercall IVP_Friction_Manager::generate_contact_point@<eax>(
        int a1@<edi>,
        IVP_Mindist *mindist,
        IVP_BOOL *successful)
{
  IVP_Contact_Point *result; // eax
  IVP_Contact_Point *v4; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (*((_DWORD *)&mindist->IVP_Mindist_Base + 5) & 0x3C0000) == 0xC0000 )
  {
    result = IVP_Friction_Manager::get_associated_contact_point(mindist);
    if ( result != nullptr )
    {
      *successful = IVP_FALSE;
    }
    else
    {
      v4 = (IVP_Contact_Point *)p_malloc(size: 0xA0u);
      if ( v4 != nullptr )
        result = IVP_Contact_Point::IVP_Contact_Point(
                   this: v4,
                   a2: (int)&savedregs,
                   a3: a1,
                   a4: (int)mindist,
                   md: mindist);
      else
        result = nullptr;
      *successful = IVP_TRUE;
    }
  }
  else
  {
    *successful = IVP_FALSE;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008AB10
// Name: public: void IVP_Contact_Point::recalc_friction_s_vals(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_Contact_Point::recalc_friction_s_vals(
        IVP_Contact_Point *this@<ecx>,
        const IVP_Compact_Edge *a2@<ebp>,
        IVP_Environment *env)
{
  IVP_Environment *v3; // eax
  IVP_U_Memory *sim_unit_mem; // ecx
  char *speicherbeginn; // esi
  unsigned int v7; // edx
  int status; // edx
  IVP_Real_Object *v9; // eax
  IVP_SYNAPSE_POLYGON_STATUS l_obj; // edx
  bool v11; // zf
  IVP_Cache_Object *cache_object; // eax
  IVP_SYNAPSE_POLYGON_STATUS v13; // ecx
  IVP_Cache_Object *v14; // ecx
  IVP_Cache_Object *v15; // edx
  IVP_SYNAPSE_POLYGON_STATUS v16; // edx
  IVP_Cache_Object *v17; // eax
  IVP_SYNAPSE_POLYGON_STATUS v18; // ecx
  IVP_Cache_Object *v19; // ecx
  float *v20; // ecx
  char *v21; // edx
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  IVP_U_Float_Point *v28; // ecx
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  float v36; // xmm1_4
  float extra_radius; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm5_4
  float v43; // xmm0_4
  float v44; // xmm4_4
  float v45; // xmm3_4
  IVP_Core *physical_core; // ecx
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  float v50; // xmm3_4
  float v51; // xmm2_4
  float v52; // xmm4_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm4_4
  float v57; // xmm0_4
  float v58; // xmm3_4
  IVP_SYNAPSE_POLYGON_STATUS v59; // eax
  IVP_Core *v60; // ecx
  float v61; // xmm1_4
  float v62; // xmm0_4
  float v63; // xmm2_4
  float v64; // xmm4_4
  float v65; // xmm5_4
  float v66; // xmm3_4
  float v67; // xmm1_4
  float v68; // xmm2_4
  float v69; // xmm0_4
  float v70; // xmm5_4
  float v71; // xmm4_4
  float v72; // xmm0_4
  float v73; // xmm6_4
  float v74; // xmm5_4
  float v75; // xmm1_4
  float v76; // xmm3_4
  IVP_SYNAPSE_POLYGON_STATUS v77; // eax
  IVP_Environment *environment; // eax
  unsigned int seconds_low; // ecx
  unsigned int seconds_high; // eax
  long double v81; // xmm0_8
  float v82; // xmm1_4
  float v83; // xmm1_4
  char *v84; // [esp-Ch] [ebp-94h] BYREF
  unsigned int v85; // [esp-8h] [ebp-90h]
  float *v86; // [esp-4h] [ebp-8Ch]
  IVP_Cache_Ledge_Point m_cache_0; // [esp+0h] [ebp-88h] BYREF
  IVP_Cache_Ledge_Point m_cache_1; // [esp+14h] [ebp-74h] BYREF
  IVP_U_Point tp2; // [esp+28h] [ebp-60h] BYREF
  IVP_U_Float_Point delta_velocity_ws; // [esp+38h] [ebp-50h] BYREF
  IVP_U_Point point0_position_ws_4; // [esp+4Ch] [ebp-3Ch] OVERLAPPED BYREF
  int v92; // [esp+68h] [ebp-20h]
  _DWORD *v93; // [esp+6Ch] [ebp-1Ch]
  const IVP_Compact_Edge *v94; // [esp+70h] [ebp-18h]
  IVP_SYNAPSE_POLYGON_STATUS stat0; // [esp+74h] [ebp-14h]
  const IVP_Compact_Edge *edge; // [esp+78h] [ebp-10h]
  const IVP_Compact_Edge *e0; // [esp+7Ch] [ebp-Ch] BYREF
  IVP_Core *core1; // [esp+80h] [ebp-8h]
  IVP_Core *retaddr; // [esp+88h] [ebp+0h]

  e0 = a2;
  core1 = retaddr;
  v3 = env;
  sim_unit_mem = env->sim_unit_mem;
  speicherbeginn = sim_unit_mem->speicherbeginn;
  v7 = (unsigned int)(speicherbeginn + 255) & 0xFFFFFFE0;
  if ( (char *)v7 < sim_unit_mem->speicherende )
  {
    sim_unit_mem->speicherbeginn = (char *)v7;
  }
  else
  {
    speicherbeginn = IVP_U_Memory::neuer_sp_block(this: sim_unit_mem, groesse: 0xE0u);
    v3 = env;
  }
  *(_QWORD *)(speicherbeginn + 20) = 0;
  *((_DWORD *)speicherbeginn + 4) = 0;
  *(_DWORD *)(speicherbeginn + 82) = 0;
  *((_WORD *)speicherbeginn + 43) = 0;
  this->tmp_contact_info = (IVP_Impact_Solver_Long_Term *)speicherbeginn;
  ++v3->statistic_manager.processed_fmindists;
  status = this->synapse[0].status;
  LODWORD(point0_position_ws_4.hesse_val) = this->synapse[1].status;
  edge = this->synapse[1].edge;
  v9 = (IVP_Real_Object *)(((unsigned int)edge & 0xFFFFFFF0)
                         - 16 * ((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) + 1));
  v92 = status;
  l_obj = (IVP_SYNAPSE_POLYGON_STATUS)this->synapse[1].l_obj;
  m_cache_0.clp_object = v9;
  v11 = *(_DWORD *)(l_obj + 64) == 0;
  v94 = (const IVP_Compact_Edge *)v9;
  stat0 = l_obj;
  if ( v11 )
  {
    cache_object = IVP_Cache_Object_Manager::get_cache_object(
                     this: *(IVP_Cache_Object_Manager **)(*(_DWORD *)(l_obj + 24) + 144),
                     object: (IVP_Real_Object *)l_obj);
    v13 = stat0;
    *(_DWORD *)(stat0 + 64) = cache_object;
    l_obj = v13;
  }
  ++*(_DWORD *)(*(_DWORD *)(l_obj + 64) + 100);
  if ( *(char *)(l_obj + 68) < 8 )
  {
    v14 = *(IVP_Cache_Object **)(l_obj + 64);
    if ( *(_DWORD *)(*(_DWORD *)(l_obj + 24) + 264) > v14->valid_until_time_code )
    {
      IVP_Cache_Object::update_cache_object(this: v14);
      l_obj = stat0;
    }
  }
  m_cache_0.tmp.synapse = *(IVP_Synapse_Real **)(l_obj + 64);
  m_cache_1.compact_poly_points = (const IVP_Compact_Poly_Point *)l_obj;
  v15 = (IVP_Cache_Object *)((char *)v94 + *(_DWORD *)v94);
  m_cache_1.compact_ledge = (const IVP_Compact_Ledge *)&this->synapse[1];
  v94 = this->synapse[0].edge;
  m_cache_0.clp_cache_object = v15;
  v16 = (IVP_SYNAPSE_POLYGON_STATUS)this->synapse[0].l_obj;
  v85 = ((unsigned int)v94 & 0xFFFFFFF0) - 16 * ((*(_DWORD *)((unsigned int)v94 & 0xFFFFFFF0) & 0xFFF) + 1);
  v11 = *(_DWORD *)(v16 + 64) == 0;
  v93 = (_DWORD *)v85;
  stat0 = v16;
  if ( v11 )
  {
    v17 = IVP_Cache_Object_Manager::get_cache_object(
            this: *(IVP_Cache_Object_Manager **)(*(_DWORD *)(v16 + 24) + 144),
            object: (IVP_Real_Object *)v16);
    v18 = stat0;
    *(_DWORD *)(stat0 + 64) = v17;
    v16 = v18;
  }
  ++*(_DWORD *)(*(_DWORD *)(v16 + 64) + 100);
  if ( *(char *)(v16 + 68) < 8 )
  {
    v19 = *(IVP_Cache_Object **)(v16 + 64);
    if ( *(_DWORD *)(*(_DWORD *)(v16 + 24) + 264) > v19->valid_until_time_code )
    {
      IVP_Cache_Object::update_cache_object(this: v19);
      v16 = stat0;
    }
  }
  v20 = *(float **)(v16 + 64);
  m_cache_0.compact_poly_points = (const IVP_Compact_Poly_Point *)v16;
  v86 = v20;
  v21 = (char *)v93 + *v93;
  m_cache_0.compact_ledge = (const IVP_Compact_Ledge *)this->synapse;
  v84 = v21;
  if ( v92 != 0 )
  {
    if ( v92 == 1 )
    {
      IVP_Contact_Point::p_calc_friction_ss_KK(
        this,
        a2: (int)&e0,
        K: v94,
        L: edge,
        m_cache_K: (IVP_Cache_Ledge_Point *)&v84,
        m_cache_L: (IVP_Cache_Ledge_Point *)&m_cache_0.clp_cache_object,
        info: (IVP_Impact_Solver_Long_Term *)speicherbeginn,
        diff_contact_vec: (IVP_U_Float_Point *)&m_cache_1.clp_cache_object);
      goto LABEL_34;
    }
    if ( v92 != 3 )
    {
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_mindist_friction.cxx", 452);
      goto LABEL_34;
    }
    v22 = v20[21];
    v23 = v20[22];
    delta_velocity_ws.k[1] = v20[20];
    delta_velocity_ws.k[2] = v22;
    delta_velocity_ws.hesse_val = v23;
    *((_BYTE *)&this->IVP_Contact_Point_Fast + 93) = 1;
  }
  else
  {
    IVP_Compact_Ledge_Solver::give_world_coords_AT(
      edge: v94,
      clp: (IVP_Cache_Ledge_Point *)&v84,
      p_ws_out: (IVP_U_Point *)&delta_velocity_ws.k[1]);
  }
  switch ( LODWORD(point0_position_ws_4.hesse_val) )
  {
    case 0:
      IVP_Compact_Ledge_Solver::give_world_coords_AT(
        edge,
        clp: (IVP_Cache_Ledge_Point *)&m_cache_0.clp_cache_object,
        p_ws_out: (IVP_U_Point *)&m_cache_1.clp_cache_object);
      point0_position_ws_4.k[0] = *(float *)&m_cache_1.clp_cache_object - delta_velocity_ws.k[1];
      point0_position_ws_4.k[1] = *(float *)&m_cache_1.clp_object - delta_velocity_ws.k[2];
      point0_position_ws_4.k[2] = *(float *)&m_cache_1.tmp.synapse - delta_velocity_ws.hesse_val;
      this->last_gap_len = IVP_U_Float_Point::real_length_plus_normize(this: &point0_position_ws_4);
      *((_QWORD *)speicherbeginn + 2) = *(_QWORD *)point0_position_ws_4.k;
      *((_DWORD *)speicherbeginn + 6) = LODWORD(point0_position_ws_4.k[2]);
      if ( (float)(*((float *)speicherbeginn + 4) * *((float *)speicherbeginn + 4)) >= 0.89999998 )
      {
        v32 = 1.0;
        v31 = 0.0;
      }
      else
      {
        v31 = 1.0;
        v32 = 0.0;
      }
      v33 = *((float *)speicherbeginn + 4) * 0.0;
      v34 = *((float *)speicherbeginn + 6);
      v35 = v31 * *((float *)speicherbeginn + 5);
      v28 = (IVP_U_Float_Point *)(speicherbeginn + 128);
      v36 = (float)(v31 * v34) - (float)(v32 * *((float *)speicherbeginn + 4));
      *((float *)speicherbeginn + 32) = (float)(v32 * *((float *)speicherbeginn + 5)) - (float)(v34 * 0.0);
      *((float *)speicherbeginn + 33) = v36;
      v30 = v33 - v35;
      goto LABEL_26;
    case 1:
      IVP_Contact_Point::p_calc_friction_s_PK(
        this,
        a2: (int)&e0,
        pp: (const IVP_U_Point *)&delta_velocity_ws.k[1],
        K: edge,
        m_cache_K: (IVP_Cache_Ledge_Point *)&m_cache_0.clp_cache_object,
        info: (IVP_Impact_Solver_Long_Term *)speicherbeginn,
        diff_contact_vec: (IVP_U_Float_Point *)&m_cache_1.clp_cache_object);
      break;
    case 2:
      IVP_Contact_Point::p_calc_friction_qr_PF(
        this,
        a2: (int)&e0,
        pp: (const IVP_U_Point *)&delta_velocity_ws.k[1],
        F: edge,
        m_cache_F: (IVP_Cache_Ledge_Point *)&m_cache_0.clp_cache_object,
        info: (IVP_Impact_Solver_Long_Term *)speicherbeginn,
        diff_contact_vec: (IVP_U_Float_Point *)&m_cache_1.clp_cache_object);
      break;
    case 3:
      point0_position_ws_4.k[0] = *(float *)&m_cache_0.tmp.synapse[2].mindist_offset - delta_velocity_ws.k[1];
      point0_position_ws_4.k[1] = *(float *)&m_cache_0.tmp.synapse[3].__vftable - delta_velocity_ws.k[2];
      point0_position_ws_4.k[2] = *(float *)&m_cache_0.tmp.synapse[3].minlist_index - delta_velocity_ws.hesse_val;
      this->last_gap_len = IVP_U_Float_Point::real_length_plus_normize(this: &point0_position_ws_4);
      *((_QWORD *)speicherbeginn + 2) = *(_QWORD *)point0_position_ws_4.k;
      *((_DWORD *)speicherbeginn + 6) = LODWORD(point0_position_ws_4.k[2]);
      if ( (float)(*((float *)speicherbeginn + 4) * *((float *)speicherbeginn + 4)) >= 0.89999998 )
      {
        v24 = 0.0;
        v25 = 1.0;
      }
      else
      {
        v24 = 1.0;
        v25 = 0.0;
      }
      v26 = *((float *)speicherbeginn + 4);
      v27 = *((float *)speicherbeginn + 6);
      v28 = (IVP_U_Float_Point *)(speicherbeginn + 128);
      v29 = *((float *)speicherbeginn + 5) * v24;
      *((float *)speicherbeginn + 32) = (float)(*((float *)speicherbeginn + 5) * v25) - (float)(v27 * 0.0);
      *((float *)speicherbeginn + 33) = (float)(v27 * v24) - (float)(v26 * v25);
      v30 = (float)(v26 * 0.0) - v29;
LABEL_26:
      v28->k[2] = v30;
      IVP_U_Float_Point::fast_normize(this: v28);
      *(float *)speicherbeginn = delta_velocity_ws.k[1];
      *((_DWORD *)speicherbeginn + 1) = LODWORD(delta_velocity_ws.k[2]);
      *((_DWORD *)speicherbeginn + 2) = LODWORD(delta_velocity_ws.hesse_val);
      break;
    default:
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_mindist_friction.cxx", 442);
      break;
  }
LABEL_34:
  extra_radius = this->synapse[0].l_obj->extra_radius;
  v38 = *((float *)speicherbeginn + 6);
  v39 = *((float *)speicherbeginn + 4);
  *((float *)speicherbeginn + 1) = (float)(*((float *)speicherbeginn + 5) * extra_radius)
                                 + *((float *)speicherbeginn + 1);
  v40 = (float)(v38 * extra_radius) + *((float *)speicherbeginn + 2);
  *(float *)speicherbeginn = (float)(v39 * extra_radius) + *(float *)speicherbeginn;
  *((float *)speicherbeginn + 2) = v40;
  v41 = this->last_gap_len - (float)(this->synapse[1].l_obj->extra_radius + extra_radius);
  this->last_gap_len = v41;
  if ( v41 < 0.0 )
    this->last_gap_len = 0.0;
  --*((_DWORD *)v86 + 25);
  --m_cache_0.tmp.synapse[3].l_obj;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)speicherbeginn + 8);
  v42 = *((float *)speicherbeginn + 33);
  v43 = *((float *)speicherbeginn + 4);
  v44 = *((float *)speicherbeginn + 32) * *((float *)speicherbeginn + 5);
  v45 = (float)(*((float *)speicherbeginn + 6) * *((float *)speicherbeginn + 32))
      - (float)(*((float *)speicherbeginn + 34) * v43);
  *((float *)speicherbeginn + 36) = (float)(*((float *)speicherbeginn + 34) * *((float *)speicherbeginn + 5))
                                  - (float)(*((float *)speicherbeginn + 6) * v42);
  *((float *)speicherbeginn + 37) = v45;
  *((float *)speicherbeginn + 38) = (float)(v43 * v42) - v44;
  physical_core = this->synapse[0].l_obj->physical_core;
  v11 = (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) == 0;
  stat0 = (IVP_SYNAPSE_POLYGON_STATUS)physical_core;
  if ( v11 )
  {
    v47 = *(float *)speicherbeginn - physical_core->m_world_f_core_last_psi.vv.k[0];
    v48 = *((float *)speicherbeginn + 1) - physical_core->m_world_f_core_last_psi.vv.k[1];
    v49 = *((float *)speicherbeginn + 2) - physical_core->m_world_f_core_last_psi.vv.k[2];
    *((float *)speicherbeginn + 40) = (float)((float)(physical_core->m_world_f_core_last_psi.rows[1].k[0] * v48)
                                            + (float)(v47 * physical_core->m_world_f_core_last_psi.rows[0].k[0]))
                                    + (float)(v49 * physical_core->m_world_f_core_last_psi.rows[2].k[0]);
    *((float *)speicherbeginn + 41) = (float)((float)(v48 * physical_core->m_world_f_core_last_psi.rows[1].k[1])
                                            + (float)(v47 * physical_core->m_world_f_core_last_psi.rows[0].k[1]))
                                    + (float)(physical_core->m_world_f_core_last_psi.rows[2].k[1] * v49);
    *((float *)speicherbeginn + 42) = (float)((float)(physical_core->m_world_f_core_last_psi.rows[1].k[2] * v48)
                                            + (float)(v47 * physical_core->m_world_f_core_last_psi.rows[0].k[2]))
                                    + (float)(v49 * physical_core->m_world_f_core_last_psi.rows[2].k[2]);
    v50 = *((float *)speicherbeginn + 5);
    v51 = *((float *)speicherbeginn + 4);
    v52 = *((float *)speicherbeginn + 6);
    v53 = (float)((float)(v51 * physical_core->m_world_f_core_last_psi.rows[0].k[0])
                + (float)(physical_core->m_world_f_core_last_psi.rows[1].k[0] * v50))
        + (float)(physical_core->m_world_f_core_last_psi.rows[2].k[0] * v52);
    v54 = (float)((float)(physical_core->m_world_f_core_last_psi.rows[0].k[1] * v51)
                + (float)(v50 * physical_core->m_world_f_core_last_psi.rows[1].k[1]))
        + (float)(physical_core->m_world_f_core_last_psi.rows[2].k[1] * v52);
    v55 = (float)((float)(v51 * physical_core->m_world_f_core_last_psi.rows[0].k[2])
                + (float)(physical_core->m_world_f_core_last_psi.rows[1].k[2] * v50))
        + (float)(physical_core->m_world_f_core_last_psi.rows[2].k[2] * v52);
    v56 = v53 * *((float *)speicherbeginn + 41);
    point0_position_ws_4.hesse_val = *((float *)speicherbeginn + 42);
    v57 = (float)(v53 * point0_position_ws_4.hesse_val) - (float)(v55 * *((float *)speicherbeginn + 40));
    v58 = (float)(v54 * *((float *)speicherbeginn + 40)) - v56;
    *((float *)speicherbeginn + 48) = (float)(v55 * *((float *)speicherbeginn + 41))
                                    - (float)(v54 * point0_position_ws_4.hesse_val);
    *((float *)speicherbeginn + 49) = v57;
    *((float *)speicherbeginn + 50) = v58;
    IVP_Core::get_surface_speed_on_test(
      this: physical_core,
      point_cs: (const IVP_U_Float_Point *)speicherbeginn + 10,
      center_speed_ws: &physical_core->speed,
      rot_speed_cs: &physical_core->rot_speed,
      speed_out_ws: (IVP_U_Point *)&tp2.k[1]);
    v59 = stat0;
    *((float *)speicherbeginn + 27) = (float)((float)((float)(*((float *)speicherbeginn + 49)
                                                            * (float)(*((float *)speicherbeginn + 49)
                                                                    * *(float *)(stat0 + 52)))
                                                    + (float)((float)(*((float *)speicherbeginn + 48)
                                                                    * *(float *)(stat0 + 48))
                                                            * *((float *)speicherbeginn + 48)))
                                            + (float)(*((float *)speicherbeginn + 50)
                                                    * (float)(*((float *)speicherbeginn + 50) * *(float *)(stat0 + 56))))
                                    + *(float *)(stat0 + 60);
  }
  else
  {
    memset(&tp2.k[1], 0, 12);
    *((_DWORD *)speicherbeginn + 27) = 0;
    *(_QWORD *)(speicherbeginn + 164) = 0;
    *((_DWORD *)speicherbeginn + 40) = 0;
    stat0 = IVP_ST_POINT;
    v59 = IVP_ST_POINT;
    *(_QWORD *)(speicherbeginn + 196) = 0;
    *((_DWORD *)speicherbeginn + 48) = 0;
  }
  *((_DWORD *)speicherbeginn + 28) = v59;
  v60 = this->synapse[1].l_obj->physical_core;
  v11 = (*(_BYTE *)&v60->IVP_Core_Fast_Static & 2) == 0;
  stat0 = (IVP_SYNAPSE_POLYGON_STATUS)v60;
  if ( v11 )
  {
    v61 = *(float *)speicherbeginn - v60->m_world_f_core_last_psi.vv.k[0];
    v62 = *((float *)speicherbeginn + 1) - v60->m_world_f_core_last_psi.vv.k[1];
    v63 = *((float *)speicherbeginn + 2) - v60->m_world_f_core_last_psi.vv.k[2];
    *((float *)speicherbeginn + 44) = (float)((float)(v62 * v60->m_world_f_core_last_psi.rows[1].k[0])
                                            + (float)(v61 * v60->m_world_f_core_last_psi.rows[0].k[0]))
                                    + (float)(v63 * v60->m_world_f_core_last_psi.rows[2].k[0]);
    *((float *)speicherbeginn + 45) = (float)((float)(v61 * v60->m_world_f_core_last_psi.rows[0].k[1])
                                            + (float)(v62 * v60->m_world_f_core_last_psi.rows[1].k[1]))
                                    + (float)(v63 * v60->m_world_f_core_last_psi.rows[2].k[1]);
    *((float *)speicherbeginn + 46) = (float)((float)(v62 * v60->m_world_f_core_last_psi.rows[1].k[2])
                                            + (float)(v61 * v60->m_world_f_core_last_psi.rows[0].k[2]))
                                    + (float)(v63 * v60->m_world_f_core_last_psi.rows[2].k[2]);
    v64 = *((float *)speicherbeginn + 5);
    v65 = *((float *)speicherbeginn + 4);
    v66 = *((float *)speicherbeginn + 6);
    v67 = (float)((float)(v60->m_world_f_core_last_psi.rows[0].k[0] * v65)
                + (float)(v60->m_world_f_core_last_psi.rows[1].k[0] * v64))
        + (float)(v66 * v60->m_world_f_core_last_psi.rows[2].k[0]);
    v68 = (float)((float)(v60->m_world_f_core_last_psi.rows[1].k[1] * v64)
                + (float)(v65 * v60->m_world_f_core_last_psi.rows[0].k[1]))
        + (float)(v60->m_world_f_core_last_psi.rows[2].k[1] * v66);
    v69 = v60->m_world_f_core_last_psi.rows[0].k[2] * v65;
    v70 = v60->m_world_f_core_last_psi.rows[1].k[2] * v64;
    v71 = *((float *)speicherbeginn + 46);
    v72 = (float)(v69 + v70) + (float)(v66 * v60->m_world_f_core_last_psi.rows[2].k[2]);
    point0_position_ws_4.hesse_val = *((float *)speicherbeginn + 45);
    v73 = point0_position_ws_4.hesse_val * v67;
    v74 = v71 * v67;
    v75 = v72 * *((float *)speicherbeginn + 44);
    v76 = (float)(v68 * *((float *)speicherbeginn + 44)) - v73;
    *((float *)speicherbeginn + 52) = (float)(v72 * point0_position_ws_4.hesse_val) - (float)(v71 * v68);
    *((float *)speicherbeginn + 53) = v74 - v75;
    *((float *)speicherbeginn + 54) = v76;
    IVP_Core::get_surface_speed_on_test(
      this: v60,
      point_cs: (const IVP_U_Float_Point *)speicherbeginn + 11,
      center_speed_ws: &v60->speed,
      rot_speed_cs: &v60->rot_speed,
      speed_out_ws: (IVP_U_Float_Point *)&m_cache_1.clp_cache_object);
    v77 = stat0;
    tp2.k[1] = tp2.k[1] - *(float *)&m_cache_1.clp_cache_object;
    tp2.k[2] = tp2.k[2] - *(float *)&m_cache_1.clp_object;
    tp2.hesse_val = tp2.hesse_val - *(float *)&m_cache_1.tmp.synapse;
    *((float *)speicherbeginn + 27) = (float)((float)((float)((float)(*((float *)speicherbeginn + 53)
                                                                    * (float)(*(float *)(stat0 + 52)
                                                                            * *((float *)speicherbeginn + 53)))
                                                            + (float)(*((float *)speicherbeginn + 52)
                                                                    * (float)(*((float *)speicherbeginn + 52)
                                                                            * *(float *)(stat0 + 48))))
                                                    + (float)(*((float *)speicherbeginn + 54)
                                                            * (float)(*(float *)(stat0 + 56)
                                                                    * *((float *)speicherbeginn + 54))))
                                            + *(float *)(stat0 + 60))
                                    + *((float *)speicherbeginn + 27);
  }
  else
  {
    *((_DWORD *)speicherbeginn + 46) = 0;
    *((_DWORD *)speicherbeginn + 45) = 0;
    *((_DWORD *)speicherbeginn + 44) = 0;
    stat0 = IVP_ST_POINT;
    v77 = IVP_ST_POINT;
    *((_DWORD *)speicherbeginn + 54) = 0;
    *((_DWORD *)speicherbeginn + 53) = 0;
    *((_DWORD *)speicherbeginn + 52) = 0;
  }
  *((float *)speicherbeginn + 26) = 1.0 / *((float *)speicherbeginn + 27);
  *((_DWORD *)speicherbeginn + 29) = v77;
  environment = this->synapse[0].l_obj->environment;
  seconds_low = LODWORD(environment->current_time.seconds);
  seconds_high = HIDWORD(environment->current_time.seconds);
  *(_QWORD *)&point0_position_ws_4.k[2] = __PAIR64__(seconds_high, seconds_low);
  v81 = COERCE_DOUBLE(__PAIR64__(seconds_high, seconds_low)) - this->last_time_of_recalc_friction_s_vals.seconds;
  LODWORD(this->last_time_of_recalc_friction_s_vals.seconds) = seconds_low;
  HIDWORD(this->last_time_of_recalc_friction_s_vals.seconds) = seconds_high;
  v82 = v81;
  *(float *)&v81 = tp2.k[1];
  this->span_friction_s[0] = this->span_friction_s[0]
                           - (float)((float)((float)((float)(*((float *)speicherbeginn + 33) * tp2.k[2])
                                                   + (float)(tp2.k[1] * *((float *)speicherbeginn + 32)))
                                           + (float)(*((float *)speicherbeginn + 34) * tp2.hesse_val))
                                   * v82);
  this->span_friction_s[1] = this->span_friction_s[1]
                           - (float)((float)((float)((float)(*((float *)speicherbeginn + 37) * tp2.k[2])
                                                   + (float)(*(float *)&v81 * *((float *)speicherbeginn + 36)))
                                           + (float)(*((float *)speicherbeginn + 38) * tp2.hesse_val))
                                   * v82);
  LODWORD(v81) = *((_DWORD *)speicherbeginn + 1);
  v83 = *((float *)speicherbeginn + 2);
  this->last_contact_point_ws.k[0] = *(float *)speicherbeginn;
  this->last_contact_point_ws.k[1] = *(float *)&v81;
  this->last_contact_point_ws.k[2] = v83;
  this->last_contact_normal[0] = *((float *)speicherbeginn + 4);
  this->last_contact_normal[1] = *((float *)speicherbeginn + 5);
  this->last_contact_point_ws.hesse_val = *((float *)speicherbeginn + 6);
}

//------------------------------------------------------------------------------
// Address: 0x1008B620
// Name: public: void IVP_Contact_Point::recompute_friction(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Contact_Point::recompute_friction(IVP_Contact_Point *this@<ecx>, const IVP_Compact_Edge *a2@<ebp>)
{
  IVP_Environment *environment; // esi
  IVP_U_Memory *sim_unit_mem; // ecx

  environment = this->synapse[0].l_obj->environment;
  ++environment->sim_unit_mem->transaction_in_use;
  IVP_Contact_Point::recalc_friction_s_vals(this, a2, env: environment);
  sim_unit_mem = environment->sim_unit_mem;
  if ( sim_unit_mem->transaction_in_use-- == 1 )
    IVP_U_Memory::free_mem_transaction(this: sim_unit_mem);
}
