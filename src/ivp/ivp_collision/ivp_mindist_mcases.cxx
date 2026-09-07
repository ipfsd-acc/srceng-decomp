// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_mindist_mcases.cxx
// Functions: 11
// ============================================================

#include "ivp\ivp_collision\ivp_mindist_mcases.h"

//------------------------------------------------------------------------------
// Address: 0x100A45B0
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_BP(class IVP_Cache_Ball __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_BP@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        int a2@<ebp>,
        IVP_Cache_Ball *m_cache_ball,
        const IVP_Compact_Edge *P,
        IVP_Cache_Ledge_Point *m_cache_P)
{
  bool v5; // sf
  IVP_U_Point *p_vv; // esi
  float v8; // xmm0_4
  float v9; // xmm1_4
  double v10; // st7
  IVP_Mindist_Minimize_Solver *v11; // esi
  IVP_Mindist *mindist; // eax
  float hesse_val; // xmm1_4
  float v14; // xmm2_4
  IVP_Mindist *v15; // eax
  double v16; // st7
  const IVP_Compact_Poly_Point *v17; // esi
  float v18; // xmm0_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  int v24; // eax
  int v25; // ecx
  float v26; // eax
  int v27; // ecx
  int v28; // edi
  const IVP_Compact_Edge *i; // edi
  const IVP_Compact_Poly_Point *v30; // ecx
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  long double v34; // st7
  long double v35; // st7
  const IVP_Compact_Edge *v36; // edi
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v37; // eax
  float v38[3]; // [esp+14h] [ebp-6Ch] BYREF
  IVP_U_Point p_ws; // [esp+20h] [ebp-60h] BYREF
  IVP_U_Point center_ball_Pmos; // [esp+30h] [ebp-50h] BYREF
  IVP_U_Point contact_plane; // [esp+40h] [ebp-40h]
  IVP_U_Point Pm_P_Pmos; // [esp+50h] [ebp-30h] BYREF
  IVP_Unscaled_S_Result sr; // [esp+60h] [ebp-20h]
  IVP_Mindist_Minimize_Solver *dist; // [esp+68h] [ebp-18h]
  const IVP_Compact_Edge *Pm; // [esp+6Ch] [ebp-14h]
  const IVP_Compact_Edge *s_grad_max; // [esp+70h] [ebp-10h]
  int v47; // [esp+74h] [ebp-Ch]
  float grad; // [esp+78h] [ebp-8h]
  float retaddr; // [esp+80h] [ebp+0h]

  v47 = a2;
  grad = retaddr;
  v5 = --this->P_Finish_Counter < 0;
  dist = this;
  if ( v5
    && IVP_Mindist_Minimize_Solver::check_loop_hash(this, i_s0: IVP_ST_BALL, i_e0: nullptr, i_s1: IVP_ST_POINT, i_e1: P) != 0 )
  {
    return IVP_MRC_ENDLESS_LOOP;
  }
  IVP_Compact_Ledge_Solver::give_world_coords_AT(edge: P, clp: m_cache_P, p_ws_out: (IVP_U_Point *)v38);
  p_vv = &m_cache_ball->cache_object->m_world_f_object.vv;
  IVP_Cache_Object::transform_position_to_object_coords(
    this: m_cache_P->clp_cache_object,
    P_world: p_vv,
    P_object_out: (IVP_U_Point *)&p_ws.k[1]);
  v8 = p_vv->k[1] - v38[1];
  v9 = p_vv->k[2] - v38[2];
  center_ball_Pmos.k[1] = p_vv->k[0] - v38[0];
  center_ball_Pmos.k[2] = v8;
  center_ball_Pmos.hesse_val = v9;
  v10 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Point *)&center_ball_Pmos.k[1]);
  v11 = dist;
  mindist = dist->mindist;
  hesse_val = center_ball_Pmos.hesse_val;
  v14 = center_ball_Pmos.k[1];
  mindist->contact_plane.k[1] = center_ball_Pmos.k[2];
  mindist->contact_plane.k[2] = hesse_val;
  mindist->contact_plane.k[0] = v14;
  v15 = v11->mindist;
  v16 = v10 - v11->mindist->sum_extra_radius;
  s_grad_max = nullptr;
  v15->len_numerator = v16;
  v11->mindist->contact_dot_diff_center = (float)((float)(v11->mindist->contact_plane.k[1]
                                                        * (float)(m_cache_ball->cache_object->core_pos.k[1]
                                                                - m_cache_P->clp_cache_object->core_pos.k[1]))
                                                + (float)(v11->mindist->contact_plane.k[0]
                                                        * (float)(m_cache_ball->cache_object->core_pos.k[0]
                                                                - m_cache_P->clp_cache_object->core_pos.k[0])))
                                        + (float)(v11->mindist->contact_plane.k[2]
                                                * (float)(m_cache_ball->cache_object->core_pos.k[2]
                                                        - m_cache_P->clp_cache_object->core_pos.k[2]));
  v17 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)P];
  sr.checks[1] = 0.0;
  v18 = v17->k[0];
  v19 = v17->k[1];
  v20 = v17->k[2];
  v21 = p_ws.k[1] - v17->k[0];
  v22 = p_ws.k[2] - v19;
  v23 = p_ws.hesse_val - v20;
  contact_plane.k[1] = v21;
  contact_plane.k[2] = p_ws.k[2] - v19;
  contact_plane.hesse_val = p_ws.hesse_val - v20;
  v24 = *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)P & 0xC));
  v25 = *(int *)((char *)P + v24);
  LODWORD(v26) = (char *)P + v24;
  v27 = LODWORD(v26) + 4 * ((2 * v25) >> 17);
  v28 = *(int *)((char *)IVP_Compact_Edge::prev_table + (v27 & 0xC));
  Pm_P_Pmos.hesse_val = (float)((float)(v18 * (float)(p_ws.k[1] - v18)) + (float)(v19 * (float)(p_ws.k[2] - v19)))
                      + (float)(v20 * (float)(p_ws.hesse_val - v20));
  sr.checks[0] = v26;
  for ( i = (const IVP_Compact_Edge *)(v27 + v28);
        ;
        i = (const IVP_Compact_Edge *)((char *)v36
                                     + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)v36 & 0xC))) )
  {
    v30 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)i];
    v31 = v30->k[1];
    v32 = v30->k[0];
    v33 = v30->k[2];
    *(float *)&Pm = (float)((float)((float)(v30->k[0] * v21) + (float)(v31 * v22)) + (float)(v33 * v23))
                  - Pm_P_Pmos.hesse_val;
    if ( *(float *)&Pm > 0.0 )
    {
      v34 = IVP_Inline_Math::isqrt_float(
              quad: (float)((float)((float)(v31 - v17->k[1]) * (float)(v31 - v17->k[1]))
                    + (float)((float)(v32 - v17->k[0]) * (float)(v32 - v17->k[0])))
            + (float)((float)(v33 - v17->k[2]) * (float)(v33 - v17->k[2])));
      v35 = v34 * *(float *)&Pm;
      v23 = contact_plane.hesse_val;
      v22 = contact_plane.k[2];
      v21 = contact_plane.k[1];
      *(float *)&Pm = v35;
      v26 = sr.checks[0];
      if ( v35 > sr.checks[1] )
      {
        LODWORD(sr.checks[1]) = Pm;
        s_grad_max = i;
      }
    }
    if ( i == (const IVP_Compact_Edge *)LODWORD(v26) )
      break;
    v36 = &i[(2 * *(_DWORD *)i) >> 17];
  }
  if ( s_grad_max != nullptr
    && (IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(
          c_ledge: m_cache_P->compact_ledge,
          edge: s_grad_max,
          p_object: (IVP_U_Point *)&p_ws.k[1],
          result: (IVP_Unscaled_S_Result *)&Pm_P_Pmos.k[1]),
        Pm_P_Pmos.k[2] > 0.0) )
  {
    if ( Pm_P_Pmos.k[1] >= 0.0 )
      return IVP_Mindist_Minimize_Solver::p_minimize_BK(
               this: dist,
               m_cache_B: m_cache_ball,
               K: s_grad_max,
               m_cache_K: m_cache_P);
    else
      return IVP_Mindist_Minimize_Solver::p_minimize_BP(this: dist, m_cache_ball, P: s_grad_max, m_cache_P);
  }
  else
  {
    v37.synapse = (IVP_Synapse_Real *)m_cache_P->tmp;
    v37.synapse->edge = P;
    v37.synapse->status = 0;
    return IVP_MRC_OK;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A48B0
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_PP(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_PP@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        int a2@<ebp>,
        const IVP_Compact_Edge *A,
        const IVP_Compact_Edge *B,
        IVP_Cache_Ledge_Point *m_cache_A,
        IVP_Cache_Ledge_Point *m_cache_B)
{
  bool v7; // sf
  float v8; // xmm1_4
  float v9; // xmm0_4
  IVP_Mindist *mindist; // eax
  float v11; // xmm2_4
  float v12; // xmm3_4
  int v13; // eax
  float *v14; // esi
  int *v15; // ecx
  IVP_Cache_Ledge_Point *v16; // edx
  int v17; // edi
  float v18; // xmm6_4
  IVP_Cache_Ledge_Point *v19; // ecx
  float *k; // edi
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  const IVP_Compact_Poly_Point **v24; // eax
  const IVP_Compact_Edge *v25; // xmm5_4
  const IVP_Compact_Edge *v26; // xmm4_4
  int v27; // esi
  float v28; // xmm6_4
  IVP_Cache_Ledge_Point *v29; // esi
  float *v30; // eax
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  long double v34; // st7
  long double v35; // st7
  const IVP_U_Point *v36; // edx
  IVP_Cache_Ledge_Point *v37; // edx
  const IVP_Compact_Poly_Point **v38; // esi
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v39; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v40; // eax
  IVP_Mindist_Minimize_Solver *v42; // ecx
  IVP_Mindist *v43; // edx
  IVP_Synapse_Real *v44; // eax
  IVP_Cache_Ledge_Point *v45; // esi
  IVP_Cache_Ledge_Point *v46; // esi
  int v47; // [esp+14h] [ebp-CCh] BYREF
  IVP_U_Point point_other_os[2]; // [esp+20h] [ebp-C0h] BYREF
  float v49; // [esp+40h] [ebp-A0h]
  float v50; // [esp+44h] [ebp-9Ch] BYREF
  IVP_Unscaled_S_Result sr; // [esp+48h] [ebp-98h]
  IVP_U_Point points_ws[2]; // [esp+50h] [ebp-90h] BYREF
  _DWORD v53[2]; // [esp+70h] [ebp-70h]
  const IVP_Compact_Edge *v54; // [esp+78h] [ebp-68h]
  IVP_Cache_Ledge_Point *m_cache[2]; // [esp+7Ch] [ebp-64h]
  const IVP_Compact_Edge *Point[2]; // [esp+84h] [ebp-5Ch]
  float dist; // [esp+8Ch] [ebp-54h]
  IVP_Cache_Ledge_Point *v58; // [esp+A0h] [ebp-40h]
  IVP_Mindist_Minimize_Solver *v59; // [esp+A4h] [ebp-3Ch]
  float v60; // [esp+A8h] [ebp-38h]
  const IVP_Compact_Edge *Pm; // [esp+ACh] [ebp-34h]
  int v62; // [esp+B0h] [ebp-30h]
  IVP_Cache_Ledge_Point *s_grad_max; // [esp+B4h] [ebp-2Ch]
  const IVP_U_Point *P_Pmos_max; // [esp+B8h] [ebp-28h]
  float v65; // [esp+BCh] [ebp-24h]
  IVP_Cache_Ledge_Point *m_cache_Pm; // [esp+C0h] [ebp-20h]
  const IVP_Compact_Edge *Pmax; // [esp+C4h] [ebp-1Ch]
  const IVP_Compact_Edge *grad; // [esp+C8h] [ebp-18h]
  IVP_Cache_Ledge_Point *m_cache_P_max; // [esp+CCh] [ebp-14h]
  IVP_Cache_Ledge_Point *v70; // [esp+D0h] [ebp-10h]
  int v71; // [esp+D4h] [ebp-Ch]
  const IVP_Compact_Edge *Kmax; // [esp+D8h] [ebp-8h]
  const IVP_Compact_Edge *retaddr; // [esp+E0h] [ebp+0h]

  v71 = a2;
  Kmax = retaddr;
  v7 = --this->P_Finish_Counter < 0;
  v59 = this;
  if ( v7
    && IVP_Mindist_Minimize_Solver::check_loop_hash(this, i_s0: IVP_ST_POINT, i_e0: A, i_s1: IVP_ST_POINT, i_e1: B) != 0 )
  {
    return IVP_MRC_ENDLESS_LOOP;
  }
  v54 = A;
  m_cache[0] = (IVP_Cache_Ledge_Point *)B;
  IVP_Compact_Ledge_Solver::give_world_coords_AT(edge: A, clp: m_cache_A, p_ws_out: (IVP_U_Point *)&v50);
  IVP_Compact_Ledge_Solver::give_world_coords_AT(edge: B, clp: m_cache_B, p_ws_out: (IVP_U_Point *)&points_ws[0].k[1]);
  IVP_Cache_Object::transform_position_to_object_coords(
    this: m_cache_B->clp_cache_object,
    P_world: (const IVP_U_Point *)&v50,
    P_object_out: (IVP_U_Point *)&v47);
  IVP_Cache_Object::transform_position_to_object_coords(
    this: m_cache_A->clp_cache_object,
    P_world: (IVP_U_Point *)&points_ws[0].k[1],
    P_object_out: (IVP_U_Point *)&point_other_os[0].k[1]);
  v8 = (float)((float)((float)(sr.checks[0] - points_ws[0].k[2]) * (float)(sr.checks[0] - points_ws[0].k[2]))
             + (float)((float)(v50 - points_ws[0].k[1]) * (float)(v50 - points_ws[0].k[1])))
     + (float)((float)(sr.checks[1] - points_ws[0].hesse_val) * (float)(sr.checks[1] - points_ws[0].hesse_val));
  if ( v8 <= 0.000001 )
    return IVP_MRC_ENDLESS_LOOP;
  v9 = 1.0 / fsqrt(v8);
  this->mindist->len_numerator = (float)(v9 * v8) - this->mindist->sum_extra_radius;
  mindist = this->mindist;
  v11 = sr.checks[1] - points_ws[0].hesse_val;
  v12 = v50 - points_ws[0].k[1];
  mindist->contact_plane.k[1] = (float)(sr.checks[0] - points_ws[0].k[2]) * v9;
  mindist->contact_plane.k[0] = v12 * v9;
  mindist->contact_plane.k[2] = v11 * v9;
  this->mindist->contact_dot_diff_center = (float)((float)(this->mindist->contact_plane.k[1]
                                                         * (float)(m_cache_A->clp_cache_object->core_pos.k[1]
                                                                 - m_cache_B->clp_cache_object->core_pos.k[1]))
                                                 + (float)(this->mindist->contact_plane.k[0]
                                                         * (float)(m_cache_A->clp_cache_object->core_pos.k[0]
                                                                 - m_cache_B->clp_cache_object->core_pos.k[0])))
                                         + (float)(this->mindist->contact_plane.k[2]
                                                 * (float)(m_cache_A->clp_cache_object->core_pos.k[2]
                                                         - m_cache_B->clp_cache_object->core_pos.k[2]));
  v13 = 0;
  v14 = &point_other_os[0].k[1];
  v53[0] = m_cache_A;
  v53[1] = m_cache_B;
  v60 = 0.0;
  Pm = nullptr;
  m_cache_P_max = nullptr;
  P_Pmos_max = nullptr;
  v70 = nullptr;
  m_cache_Pm = nullptr;
  Pmax = (const IVP_Compact_Edge *)4;
  grad = (const IVP_Compact_Edge *)&point_other_os[0].k[1];
  v62 = 0;
  do
  {
    v15 = *(int **)((char *)&m_cache[-1] + v13);
    v16 = *(IVP_Cache_Ledge_Point **)((char *)v53 + v13);
    v17 = *v15;
    v18 = v14[2];
    v19 = (IVP_Cache_Ledge_Point *)((char *)v15
                                  + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)v15 & 0xC)));
    k = v16->compact_poly_points[(unsigned __int16)v17].k;
    v21 = *k;
    v22 = k[1];
    v23 = k[2];
    v24 = &v19->compact_poly_points + ((2 * (int)v19->compact_poly_points) >> 17);
    *(float *)&v25 = v14[1] - v22;
    *(float *)&v26 = *v14 - *k;
    v27 = *(int *)((char *)IVP_Compact_Edge::prev_table
                 + (((_BYTE)v19 + 4 * (unsigned __int8)((2 * (int)v19->compact_poly_points) >> 17)) & 0xC));
    v28 = v18 - v23;
    s_grad_max = v16;
    Point[0] = v26;
    Point[1] = v25;
    dist = v28;
    *(float *)&m_cache[1] = (float)((float)(v22 * *(float *)&v25) + (float)(v21 * *(float *)&v26)) + (float)(v23 * v28);
    v58 = v19;
    v29 = (IVP_Cache_Ledge_Point *)((char *)v24 + v27);
    while ( 1 )
    {
      v30 = v16->compact_poly_points[(unsigned __int16)v29->compact_poly_points].k;
      v31 = v30[1];
      v32 = *v30;
      v33 = v30[2];
      v65 = (float)((float)((float)(v31 * *(float *)&v25) + (float)(*v30 * *(float *)&v26)) + (float)(v33 * v28))
          - *(float *)&m_cache[1];
      if ( v65 > 0.0 )
      {
        v34 = IVP_Inline_Math::isqrt_float(
                quad: (float)((float)((float)((float)(v31 - k[1]) * (float)(v31 - k[1]))
                              + (float)((float)(v32 - *k) * (float)(v32 - *k)))
                      + (float)((float)(v33 - k[2]) * (float)(v33 - k[2])))
              + 1.0e-18);
        v35 = v34 * v65;
        v28 = dist;
        v25 = Point[1];
        v26 = Point[0];
        v65 = v35;
        if ( v35 > v60 )
        {
          v36 = *(const IVP_U_Point **)((char *)&m_cache[-1] + (_DWORD)Pmax);
          Pm = grad;
          P_Pmos_max = v36;
          v37 = *(IVP_Cache_Ledge_Point **)((char *)v53 + (_DWORD)Pmax);
          v60 = v65;
          m_cache_P_max = v29;
          v70 = s_grad_max;
          m_cache_Pm = v37;
        }
        v19 = v58;
      }
      if ( v29 == v19 )
        break;
      v38 = &v29->compact_poly_points + ((2 * (int)v29->compact_poly_points) >> 17);
      v29 = (IVP_Cache_Ledge_Point *)((char *)v38
                                    + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)v38 & 0xC)));
      v16 = s_grad_max;
    }
    --Pmax;
    v13 = v62 + 4;
    v14 = (float *)&grad[-4];
    grad -= 4;
    v62 = v13;
  }
  while ( v13 <= 4 );
  if ( m_cache_P_max != nullptr
    && (IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(
          c_ledge: v70->compact_ledge,
          edge: (const IVP_Compact_Edge *)m_cache_P_max,
          p_object: (const IVP_U_Point *)Pm,
          result: (IVP_Unscaled_S_Result *)&point_other_os[1].hesse_val),
        v49 > 0.0) )
  {
    v42 = v59;
    v43 = v59->mindist;
    v44 = (IVP_Synapse_Real *)&v42->mindist->synapse[(*((_DWORD *)&v42->mindist->IVP_Mindist_Base + 5) >> 8) & 3];
    if ( point_other_os[1].hesse_val >= 0.0 )
    {
      v46 = m_cache_Pm;
      if ( m_cache_Pm->tmp.synapse != v44 )
        *((_DWORD *)&v43->IVP_Mindist_Base + 5) ^= 0x100u;
      return IVP_Mindist_Minimize_Solver::p_minimize_Leave_PK(
               this: v42,
               P: (const IVP_Compact_Edge *)P_Pmos_max,
               K: (const IVP_Compact_Edge *)m_cache_P_max,
               m_cache_P: v46,
               m_cache_K: v70);
    }
    else
    {
      v45 = v70;
      if ( v70->tmp.synapse != v44 )
        *((_DWORD *)&v43->IVP_Mindist_Base + 5) ^= 0x100u;
      return IVP_Mindist_Minimize_Solver::p_minimize_PP(
               this: v42,
               A: (const IVP_Compact_Edge *)m_cache_P_max,
               B: (const IVP_Compact_Edge *)P_Pmos_max,
               m_cache_A: v45,
               m_cache_B: m_cache_Pm);
    }
  }
  else
  {
    v39.synapse = (IVP_Synapse_Real *)m_cache_A->tmp;
    v39.synapse->edge = A;
    v39.synapse->status = 0;
    v40.synapse = (IVP_Synapse_Real *)m_cache_B->tmp;
    v40.synapse->edge = B;
    v40.synapse->status = 0;
    return IVP_MRC_OK;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4D20
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_BK(class IVP_Cache_Ball __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_BK@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        float a2@<ebp>,
        IVP_Cache_Ball *m_cache_B,
        const IVP_Compact_Edge *K,
        IVP_Cache_Ledge_Point *m_cache_K)
{
  _BYTE v6[12]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Point P_Kos; // [esp+0h] [ebp-20h] BYREF
  IVP_Mindist_Minimize_Solver *v8; // [esp+10h] [ebp-10h]
  IVP_Unscaled_S_Result sr; // [esp+14h] [ebp-Ch] BYREF
  float retaddr; // [esp+20h] [ebp+0h]

  sr.checks[0] = a2;
  sr.checks[1] = retaddr;
  v8 = this;
  IVP_Cache_Object::transform_position_to_object_coords(
    this: m_cache_K->clp_cache_object,
    P_world: &m_cache_B->cache_object->m_world_f_object.vv,
    P_object_out: (IVP_U_Point *)v6);
  IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(
    c_ledge: m_cache_K->compact_ledge,
    edge: K,
    p_object: (const IVP_U_Point *)v6,
    result: (IVP_Unscaled_S_Result *)&P_Kos.k[2]);
  if ( P_Kos.k[2] < 0.0 )
    return IVP_Mindist_Minimize_Solver::p_minimize_BP(
             this: v8,
             a2: (int)&sr,
             m_cache_ball: m_cache_B,
             P: K,
             m_cache_P: m_cache_K);
  if ( P_Kos.hesse_val >= 0.0 )
    return IVP_Mindist_Minimize_Solver::p_minimize_Leave_BK(this: v8, m_cache_ball: m_cache_B, K, m_cache_K);
  return IVP_Mindist_Minimize_Solver::p_minimize_BP(
           this: v8,
           a2: (int)&sr,
           m_cache_ball: m_cache_B,
           P: (const IVP_Compact_Edge *)((char *)K
                                    + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC))),
           m_cache_P: m_cache_K);
}

//------------------------------------------------------------------------------
// Address: 0x100A4DE0
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_PK(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_PK@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        float a2@<ebp>,
        const IVP_Compact_Edge *P,
        const IVP_Compact_Edge *K,
        IVP_Cache_Ledge_Point *m_cache_P,
        IVP_Cache_Ledge_Point *m_cache_K)
{
  _BYTE v7[12]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Point P_Kos; // [esp+0h] [ebp-20h] BYREF
  IVP_Mindist_Minimize_Solver *v9; // [esp+10h] [ebp-10h]
  IVP_Unscaled_S_Result sr; // [esp+14h] [ebp-Ch] BYREF
  float retaddr; // [esp+20h] [ebp+0h]

  sr.checks[0] = a2;
  sr.checks[1] = retaddr;
  v9 = this;
  IVP_Compact_Ledge_Solver::calc_pos_other_space(P, m_cache_P, m_cache_other_space: m_cache_K, res: (IVP_U_Point *)v7);
  IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(
    c_ledge: m_cache_K->compact_ledge,
    edge: K,
    p_object: (const IVP_U_Point *)v7,
    result: (IVP_Unscaled_S_Result *)&P_Kos.k[2]);
  if ( P_Kos.k[2] < 0.0 )
    return IVP_Mindist_Minimize_Solver::p_minimize_PP(
             this: v9,
             a2: (int)&sr,
             A: P,
             B: K,
             m_cache_A: m_cache_P,
             m_cache_B: m_cache_K);
  if ( P_Kos.hesse_val >= 0.0 )
    return IVP_Mindist_Minimize_Solver::p_minimize_Leave_PK(this: v9, P, K, m_cache_P, m_cache_K);
  return IVP_Mindist_Minimize_Solver::p_minimize_PP(
           this: v9,
           a2: (int)&sr,
           A: P,
           B: (const IVP_Compact_Edge *)((char *)K
                                    + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC))),
           m_cache_A: m_cache_P,
           m_cache_B: m_cache_K);
}

//------------------------------------------------------------------------------
// Address: 0x100A4EA0
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_BF(class IVP_Cache_Ball __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_BF@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        const IVP_Compact_Edge *a2@<ebp>,
        IVP_Cache_Ball *m_cache_B,
        const IVP_Compact_Edge *F,
        IVP_Cache_Ledge_Point *m_cache_F)
{
  const IVP_Compact_Edge *v5; // esi
  const IVP_Compact_Poly_Point *v6; // esi
  float v7; // xmm1_4
  float v8; // xmm2_4
  IVP_Mindist_Minimize_Solver *v9; // ecx
  IVP_Mindist *mindist; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v11; // eax
  float v12; // xmm0_4
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v13; // edi
  double v15; // st7
  _DWORD v16[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Point contact_plane; // [esp+0h] [ebp-60h] BYREF
  IVP_Unscaled_QR_Result qr; // [esp+10h] [ebp-50h] BYREF
  IVP_U_Point wHesse_vecF_os; // [esp+20h] [ebp-40h] BYREF
  float v20; // [esp+40h] [ebp-20h]
  IVP_Mindist_Minimize_Solver *v21; // [esp+44h] [ebp-1Ch]
  const IVP_Compact_Edge *v22; // [esp+48h] [ebp-18h]
  int dist; // [esp+4Ch] [ebp-14h]
  float v24; // [esp+50h] [ebp-10h]
  const IVP_Compact_Edge *min_edge; // [esp+54h] [ebp-Ch] BYREF
  void *v26; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  min_edge = a2;
  v26 = retaddr;
  v21 = this;
  IVP_Cache_Object::transform_position_to_object_coords(
    this: m_cache_F->clp_cache_object,
    P_world: &m_cache_B->cache_object->m_world_f_object.vv,
    P_object_out: (IVP_U_Point *)&wHesse_vecF_os.k[1]);
  v5 = F;
  IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
    c_ledge: m_cache_F->compact_ledge,
    tri: (int)F,
    p_object: (IVP_U_Point *)&wHesse_vecF_os.k[1],
    result: (IVP_Unscaled_QR_Result *)&contact_plane.k[1]);
  if ( (LODWORD(contact_plane.k[1]) | LODWORD(contact_plane.k[2]) | LODWORD(contact_plane.hesse_val)) < 0 )
  {
    v24 = 1.0e20;
    v22 = nullptr;
    for ( dist = 3; dist != 0; --dist )
    {
      v15 = IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(
              P_in_K_space: (IVP_U_Point *)&wHesse_vecF_os.k[1],
              K_ledge: m_cache_F->compact_ledge,
              K: v5);
      v20 = v15;
      if ( v24 > v15 )
      {
        v24 = v20;
        v22 = v5;
      }
      v5 = (const IVP_Compact_Edge *)((char *)v5
                                    + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v5 & 0xC)));
    }
    return IVP_Mindist_Minimize_Solver::p_minimize_BK(
             this: v21,
             a2: COERCE_FLOAT(&min_edge),
             m_cache_B,
             K: v22,
             m_cache_K: m_cache_F);
  }
  else
  {
    v6 = &m_cache_F->compact_poly_points[(unsigned __int16)*(_DWORD *)F];
    IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
      edge: F,
      ledge: m_cache_F->compact_ledge,
      out_vec: (IVP_U_Float_Point *)&qr.checks[1]);
    IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&qr.checks[1]);
    IVP_Cache_Object::transform_vector_to_world_coords(
      this: m_cache_F->clp_cache_object,
      P_object: (const IVP_U_Float_Point *)&qr.checks[1],
      P_world_out: (IVP_U_Float_Point *)v16);
    v7 = *(float *)&v16[2];
    v8 = *(float *)v16;
    v9 = v21;
    mindist = v21->mindist;
    LODWORD(mindist->contact_plane.k[1]) = v16[1];
    mindist->contact_plane.k[2] = v7;
    mindist->contact_plane.k[0] = v8;
    v11.synapse = (IVP_Synapse_Real *)m_cache_F->tmp;
    v12 = (float)((float)((float)(qr.checks[2] * wHesse_vecF_os.k[2]) + (float)(qr.checks[1] * wHesse_vecF_os.k[1]))
                + (float)(qr.scale * wHesse_vecF_os.hesse_val))
        - (float)((float)((float)(v6->k[1] * qr.checks[2]) + (float)(qr.checks[1] * v6->k[0]))
                + (float)(v6->k[2] * qr.scale));
    v11.synapse->edge = F;
    v11.synapse->status = 2;
    if ( v12 >= 0.0 )
    {
      v9->mindist->len_numerator = v12 - v9->mindist->sum_extra_radius;
      v9->mindist->contact_dot_diff_center = (float)((float)(v9->mindist->contact_plane.k[1]
                                                           * (float)(m_cache_B->cache_object->core_pos.k[1]
                                                                   - m_cache_F->clp_cache_object->core_pos.k[1]))
                                                   + (float)(v9->mindist->contact_plane.k[0]
                                                           * (float)(m_cache_B->cache_object->core_pos.k[0]
                                                                   - m_cache_F->clp_cache_object->core_pos.k[0])))
                                           + (float)(v9->mindist->contact_plane.k[2]
                                                   * (float)(m_cache_B->cache_object->core_pos.k[2]
                                                           - m_cache_F->clp_cache_object->core_pos.k[2]));
      return IVP_MRC_OK;
    }
    else
    {
      v13.synapse = (IVP_Synapse_Real *)m_cache_F->tmp;
      v13.synapse->edge = F;
      v13.synapse->status = 5;
      v9->pos_opposite_BacksideOs.k[0] = wHesse_vecF_os.k[1];
      v9->pos_opposite_BacksideOs.k[1] = wHesse_vecF_os.k[2];
      v9->pos_opposite_BacksideOs.k[2] = wHesse_vecF_os.hesse_val;
      return IVP_MRC_BACKSIDE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A50E0
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_Leave_KK(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_KK_Input const __near &,class IVP_Unscaled_KK_Result const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_Leave_KK@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        const IVP_Compact_Edge *a2@<ebp>,
        const IVP_Compact_Edge *K,
        const IVP_Compact_Edge *L,
        const IVP_KK_Input *kkin,
        const IVP_Unscaled_KK_Result *kkr,
        IVP_Cache_Ledge_Point *m_cache_K,
        IVP_Cache_Ledge_Point *m_cache_L)
{
  bool v8; // sf
  float v10; // xmm3_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  IVP_Cache_Object *clp_cache_object; // ecx
  int v14; // edx
  float *v15; // eax
  IVP_Cache_Object *v16; // ecx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  const IVP_Compact_Edge *v20; // eax
  const IVP_Compact_Edge *v21; // eax
  IVP_U_Float_Point *p_H_Fos; // esi
  const IVP_Compact_Edge *v23; // eax
  int v24; // edx
  float *v25; // esi
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm6_4
  float *v29; // eax
  float *v30; // ecx
  IVP_BOOL v31; // xmm1_4
  IVP_BOOL v32; // xmm3_4
  long double v33; // st7
  long double v34; // st7
  IVP_Cache_Ledge_Point *v35; // edx
  IVP_Leave_KK_Case *v36; // eax
  IVP_Cache_Ledge_Point *v37; // ecx
  __m128i si128; // xmm0
  const IVP_Compact_Edge *v39; // esi
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v40; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v41; // eax
  int v42; // edx
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v43; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v44; // edi
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v45; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v46; // edi
  IVP_Mindist_Minimize_Solver *v47; // edi
  IVP_Cache_Ledge_Point *v48; // ecx
  int v49; // esi
  double v50; // st7
  int v51; // esi
  const IVP_Compact_Edge *v52; // [esp+14h] [ebp-1ACh] BYREF
  const IVP_Compact_Edge *v53; // [esp+18h] [ebp-1A8h]
  float *v54; // [esp+1Ch] [ebp-1A4h]
  IVP_Leave_KK_Case cases[4]; // [esp+20h] [ebp-1A0h] BYREF
  IVP_U_Point H_Kos; // [esp+E0h] [ebp-E0h] BYREF
  IVP_U_Point L_Kos[2]; // [esp+F0h] [ebp-D0h] BYREF
  IVP_Unscaled_QR_Result qr; // [esp+110h] [ebp-B0h] BYREF
  IVP_U_Point H_ws; // [esp+120h] [ebp-A0h] BYREF
  IVP_U_Point H_Los; // [esp+130h] [ebp-90h]
  IVP_BOOL reverse_side_check[4]; // [esp+140h] [ebp-80h]
  float v62; // [esp+160h] [ebp-60h]
  __m128i v63; // [esp+164h] [ebp-5Ch] OVERLAPPED BYREF
  float v64; // [esp+180h] [ebp-40h]
  float v65; // [esp+184h] [ebp-3Ch]
  const IVP_U_Float_Point *K_Los; // [esp+188h] [ebp-38h]
  unsigned int delta_h2; // [esp+18Ch] [ebp-34h]
  float min_grad_pos; // [esp+190h] [ebp-30h]
  IVP_U_Point *v69; // [esp+194h] [ebp-2Ch]
  int side; // [esp+198h] [ebp-28h]
  float grad; // [esp+19Ch] [ebp-24h]
  IVP_Cache_Ledge_Point *dist_next; // [esp+1A0h] [ebp-20h]
  const IVP_Compact_Edge *v73; // [esp+1A4h] [ebp-1Ch]
  IVP_Leave_KK_Case *ce; // [esp+1A8h] [ebp-18h]
  IVP_Cache_Ledge_Point *min_edge_m_cache; // [esp+1ACh] [ebp-14h]
  const IVP_Compact_Edge *min_edge; // [esp+1B0h] [ebp-10h]
  const IVP_Compact_Edge *min_plane; // [esp+1B4h] [ebp-Ch] BYREF
  IVP_Cache_Ledge_Point *min_plane_m_cache; // [esp+1B8h] [ebp-8h]
  IVP_Cache_Ledge_Point *retaddr; // [esp+1C0h] [ebp+0h]

  min_plane = a2;
  min_plane_m_cache = retaddr;
  v8 = --this->P_Finish_Counter < 0;
  side = (int)this;
  if ( v8
    && IVP_Mindist_Minimize_Solver::check_loop_hash(this, i_s0: IVP_ST_EDGE, i_e0: K, i_s1: IVP_ST_EDGE, i_e1: L) != 0 )
  {
    return IVP_MRC_ENDLESS_LOOP;
  }
  v10 = kkin->cross_KL_Los.k[0];
  v11 = kkin->cross_KL_Los.k[1];
  v12 = kkin->cross_KL_Los.k[2];
  *(float *)&min_edge = (float)((float)(v10 * (float)(kkin->L_Los[0]->k[0] - kkin->K_Los[0].k[0]))
                              + (float)((float)(kkin->L_Los[0]->k[1] - kkin->K_Los[0].k[1]) * v11))
                      + (float)((float)(kkin->L_Los[0]->k[2] - kkin->K_Los[0].k[2]) * v12);
  delta_h2 = (unsigned int)min_edge >> 31;
  K_Los = kkin->K_Los;
  clp_cache_object = m_cache_L->clp_cache_object;
  grad = 1.0 / fsqrt((float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v12 * v12));
  H_ws.k[1] = v10;
  H_ws.k[2] = v11;
  H_ws.hesse_val = v12;
  IVP_Cache_Object::transform_vector_to_world_coords(
    this: clp_cache_object,
    P_object: (IVP_U_Point *)&H_ws.k[1],
    P_world_out: (IVP_U_Float_Point *)&qr.checks[1]);
  IVP_Cache_Object::transform_vector_to_object_coords(
    this: m_cache_K->clp_cache_object,
    P_world: (const IVP_U_Float_Point *)&qr.checks[1],
    P_object_out: (IVP_U_Float_Point *)&cases[3].hesse_Fos.k[1]);
  v14 = side;
  *(_DWORD *)(*(_DWORD *)side + 92) = COERCE_UNSIGNED_INT(grad * *(float *)&min_edge) & _mask__AbsFloat_;
  *(float *)(*(_DWORD *)v14 + 92) = *(float *)(*(_DWORD *)v14 + 92) - *(float *)(*(_DWORD *)v14 + 80);
  v15 = *(float **)v14;
  v16 = m_cache_K->clp_cache_object;
  v17 = (float)((float)((float)(int)delta_h2 - 0.5) * 2.0) * grad;
  v18 = qr.checks[2] * v17;
  v19 = qr.scale * v17;
  v15[24] = qr.checks[1] * v17;
  v15[25] = v18;
  v15[26] = v19;
  *(float *)(*(_DWORD *)v14 + 84) = (float)((float)(*(float *)(*(_DWORD *)v14 + 100)
                                                  * (float)(v16->core_pos.k[1]
                                                          - m_cache_L->clp_cache_object->core_pos.k[1]))
                                          + (float)(*(float *)(*(_DWORD *)v14 + 96)
                                                  * (float)(v16->core_pos.k[0]
                                                          - m_cache_L->clp_cache_object->core_pos.k[0])))
                                  + (float)(*(float *)(*(_DWORD *)v14 + 104)
                                          * (float)(v16->core_pos.k[2] - m_cache_L->clp_cache_object->core_pos.k[2]));
  IVP_Compact_Ledge_Solver::transform_pos_other_space(
    pos_in_os: kkin->L_Los[0],
    m_cache_dir: m_cache_L,
    m_cache_other_space: m_cache_K,
    res: (IVP_U_Point *)&H_Kos.k[1]);
  IVP_Compact_Ledge_Solver::transform_pos_other_space(
    pos_in_os: kkin->L_Los[1],
    m_cache_dir: m_cache_L,
    m_cache_other_space: m_cache_K,
    res: (IVP_U_Point *)&L_Kos[0].k[1]);
  v52 = &K[(2 * *(_DWORD *)K) >> 17];
  v53 = kkin->L;
  cases[0].P_Fos = (const IVP_U_Point *)&cases[3].hesse_Fos.k[1];
  LODWORD(cases[0].hesse_Fos.k[1]) = K;
  v54 = &H_Kos.k[1];
  cases[0].P = (const IVP_Compact_Edge *)m_cache_K;
  cases[0].F = (const IVP_Compact_Edge *)m_cache_L;
  LODWORD(cases[0].hesse_Fos.k[2]) = &v53[(2 * *(_DWORD *)v53) >> 17];
  cases[1].P_Fos = (const IVP_U_Point *)&cases[3].hesse_Fos.k[1];
  LODWORD(cases[0].hesse_Fos.hesse_val) = &L_Kos[0].k[1];
  v20 = &L[(2 * *(_DWORD *)L) >> 17];
  LODWORD(cases[1].hesse_Fos.hesse_val) = K_Los;
  cases[2].P_Fos = (IVP_U_Point *)&H_ws.k[1];
  LODWORD(cases[1].hesse_Fos.k[1]) = v20;
  v21 = kkin->K;
  LODWORD(cases[2].hesse_Fos.k[1]) = L;
  LODWORD(cases[1].hesse_Fos.k[2]) = v21;
  cases[1].P = (const IVP_Compact_Edge *)m_cache_K;
  cases[1].F = (const IVP_Compact_Edge *)m_cache_L;
  cases[2].P = (const IVP_Compact_Edge *)m_cache_L;
  cases[2].F = (const IVP_Compact_Edge *)m_cache_K;
  LODWORD(cases[2].hesse_Fos.k[2]) = &v21[(2 * *(_DWORD *)v21) >> 17];
  cases[3].F = (const IVP_Compact_Edge *)m_cache_K;
  v69 = &kkin->K_Los[1];
  LODWORD(cases[2].hesse_Fos.hesse_val) = &kkin->K_Los[1];
  cases[3].P = (const IVP_Compact_Edge *)m_cache_L;
  cases[3].P_Fos = (IVP_U_Point *)&H_ws.k[1];
  *(float *)&min_edge = 0.0;
  p_H_Fos = (IVP_U_Float_Point *)&cases[0].H_Fos;
  do
  {
    IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
      edge: (const IVP_Compact_Edge *)LODWORD(p_H_Fos[-2].k[0]),
      ledge: (const IVP_Compact_Ledge *)((LODWORD(p_H_Fos[-2].k[0]) & 0xFFFFFFF0)
                                - 16 * ((*(_DWORD *)(LODWORD(p_H_Fos[-2].k[0]) & 0xFFFFFFF0) & 0xFFF) + 1)),
      out_vec: p_H_Fos);
    grad = (float)((float)(p_H_Fos->k[1] * *(float *)(LODWORD(p_H_Fos[-1].k[1]) + 4))
                 + (float)(*(float *)LODWORD(p_H_Fos[-1].k[1]) * p_H_Fos->k[0]))
         + (float)(*(float *)(LODWORD(p_H_Fos[-1].k[1]) + 8) * p_H_Fos->k[2]);
    v23 = (const IVP_Compact_Edge *)((char *)min_edge + 1);
    LODWORD(H_Los.k[(_DWORD)v23]) = delta_h2 ^ ((int)min_edge >> 1) ^ (LODWORD(grad) >> 31);
    p_H_Fos += 3;
    min_edge = v23;
  }
  while ( (int)v23 <= 3 );
  *(float *)&v24 = 0.0;
  v65 = -0.000004;
  v73 = nullptr;
  ce = nullptr;
  dist_next = nullptr;
  min_edge_m_cache = nullptr;
  *(float *)&min_edge = 0.0;
  v25 = (float *)(&cases[0].H_Fos + 2);
  do
  {
    v26 = *(v25 - 2);
    v27 = *(v25 - 1);
    v28 = *v25;
    LODWORD(grad) = &(&v52)[12 * (delta_h2 ^ v24 ^ LODWORD(H_Los.k[v24 + 1]))];
    v29 = (&v54)[12 * (delta_h2 ^ v24)];
    v30 = (&v54)[12 * (delta_h2 ^ v24 ^ 1)];
    *(float *)&v31 = *v29 - *v30;
    *(float *)&v32 = v29[2] - v30[2];
    *(float *)&reverse_side_check[2] = v29[1] - v30[1];
    reverse_side_check[3] = v32;
    reverse_side_check[1] = v31;
    v64 = (float)((float)(v26 * *(float *)&v31) + (float)(*(float *)&reverse_side_check[2] * v27))
        + (float)(*(float *)&v32 * v28);
    if ( v64 < 0.0 )
    {
      min_grad_pos = IVP_Inline_Math::isqrt_float(quad: (float)((float)(v26 * v26) + (float)(v27 * v27)) + (float)(v28 * v28));
      v62 = *(float *)&reverse_side_check[2] * *(float *)&reverse_side_check[2];
      v33 = IVP_Inline_Math::isqrt_float(
              quad: (float)((float)(*(float *)&reverse_side_check[2] * *(float *)&reverse_side_check[2])
                    + (float)(*(float *)&reverse_side_check[1] * *(float *)&reverse_side_check[1]))
            + (float)(*(float *)&reverse_side_check[3] * *(float *)&reverse_side_check[3]));
      v34 = v33 * v64 * min_grad_pos;
      min_grad_pos = v34;
      if ( v65 > v34 )
      {
        IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
          c_ledge: *(const IVP_Compact_Ledge **)(*((_DWORD *)v25 - 6) + 4),
          tri: *((_DWORD *)v25 - 10),
          p_object: *(const IVP_U_Point **)(LODWORD(grad) + 8),
          result: (IVP_Unscaled_QR_Result *)&L_Kos[1].k[1]);
        if ( L_Kos[1].k[1] > 0.0 )
        {
          v35 = *(IVP_Cache_Ledge_Point **)(LODWORD(grad) + 12);
          v36 = *((IVP_Leave_KK_Case **)v25 - 10);
          v73 = *(const IVP_Compact_Edge **)(LODWORD(grad) + 4);
          v37 = *((IVP_Cache_Ledge_Point **)v25 - 6);
          v65 = min_grad_pos;
          si128 = _mm_load_si128((const __m128i *)&L_Kos[1].k[1]);
          dist_next = v35;
          ce = v36;
          min_edge_m_cache = v37;
          v63 = si128;
        }
      }
      v24 = (int)min_edge;
    }
    ++v24;
    v25 += 12;
    min_edge = (const IVP_Compact_Edge *)v24;
  }
  while ( v24 <= 3 );
  v39 = v73;
  if ( v73 != nullptr )
  {
    v47 = (IVP_Mindist_Minimize_Solver *)side;
    v48 = dist_next;
    if ( dist_next->tmp.synapse != &v47->mindist->synapse[(*((_DWORD *)&v47->mindist->IVP_Mindist_Base + 5) >> 8) & 3] )
      *(_DWORD *)(*(_DWORD *)side + 20) ^= 0x100u;
    if ( (v63.m128i_i32[0] | v63.m128i_i32[2] | v63.m128i_i32[1]) < 0 )
    {
      if ( *(float *)&v63.m128i_i32[2] < 0.0 )
      {
        if ( *(float *)&v63.m128i_i32[1] < 0.0 )
        {
          v49 = (unsigned __int8)ce & 0xC;
          *(float *)&v69 = IVP_Compact_Ledge_Solver::calc_qlen_KK(
                             a1: COERCE_FLOAT(&min_plane),
                             K: v73,
                             L: (const IVP_Compact_Edge *)((char *)ce + *(int *)((char *)IVP_Compact_Edge::next_table + v49)),
                             m_cache_K: v48,
                             m_cache_L: min_edge_m_cache);
          v50 = IVP_Compact_Ledge_Solver::calc_qlen_KK(
                  a1: COERCE_FLOAT(&min_plane),
                  K: v73,
                  L: (const IVP_Compact_Edge *)((char *)&(&ce->F)[(2
                                                              * *(int *)((char *)&ce->F
                                                                       + *(int *)((char *)IVP_Compact_Edge::prev_table
                                                                                + v49))) >> 17]
                                           + *(int *)((char *)IVP_Compact_Edge::prev_table + v49)),
                  m_cache_K: dist_next,
                  m_cache_L: min_edge_m_cache);
          if ( *(float *)&v69 <= v50 )
            v51 = *(int *)((char *)IVP_Compact_Edge::next_table + v49);
          else
            v51 = *(int *)((char *)IVP_Compact_Edge::prev_table + v49);
          return IVP_Mindist_Minimize_Solver::p_minimize_KK(
                   this: v47,
                   K: v73,
                   L: (const IVP_Compact_Edge *)((char *)ce + v51),
                   m_cache_K: dist_next,
                   m_cache_L: min_edge_m_cache);
        }
        else
        {
          return IVP_Mindist_Minimize_Solver::p_minimize_KK(
                   this: v47,
                   K: v39,
                   L: (const IVP_Compact_Edge *)((char *)ce
                                            + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)ce & 0xC))),
                   m_cache_K: v48,
                   m_cache_L: min_edge_m_cache);
        }
      }
      else
      {
        return IVP_Mindist_Minimize_Solver::p_minimize_KK(
                 this: v47,
                 K: v39,
                 L: (const IVP_Compact_Edge *)((char *)ce
                                          + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)ce & 0xC))),
                 m_cache_K: v48,
                 m_cache_L: min_edge_m_cache);
      }
    }
    else
    {
      IVP_Compact_Ledge_Solver::calc_pos_other_space(
        P: v39,
        m_cache_P: v48,
        m_cache_other_space: min_edge_m_cache,
        res: (IVP_U_Point *)&v63);
      return IVP_Mindist_Minimize_Solver::p_minimize_Leave_PF(
               this: v47,
               P: v73,
               P_Fos: (const IVP_U_Point *)&v63,
               F: (const IVP_Compact_Edge *)ce,
               m_cache_P: dist_next,
               m_cache_F: min_edge_m_cache);
    }
  }
  else
  {
    v40.synapse = (IVP_Synapse_Real *)m_cache_K->tmp;
    v40.synapse->edge = K;
    v40.synapse->status = 1;
    v41.synapse = (IVP_Synapse_Real *)m_cache_L->tmp;
    v41.synapse->status = 1;
    v42 = LODWORD(H_Los.k[1]) + LODWORD(H_Los.k[2]);
    v41.synapse->edge = L;
    if ( v42 == 2 )
    {
      v43.synapse = (IVP_Synapse_Real *)m_cache_K->tmp;
      v43.synapse->edge = K;
      v43.synapse->status = 5;
      v44.synapse = (IVP_Synapse_Real *)m_cache_L->tmp;
      v44.synapse->status = 2;
      v44.synapse->edge = L;
      IVP_U_Float_Point::set_interpolate(
        this: (IVP_U_Float_Point *)(side + 16),
        p0: (IVP_U_Point *)&H_Kos.k[1],
        p1: (IVP_U_Point *)&L_Kos[0].k[1],
        s: kkr->checks_L[0] / (float)(kkr->checks_L[1] + kkr->checks_L[0]));
      return IVP_MRC_BACKSIDE;
    }
    else if ( LODWORD(H_Los.hesse_val) + reverse_side_check[0] == 2 )
    {
      v45.synapse = (IVP_Synapse_Real *)m_cache_K->tmp;
      v45.synapse->edge = K;
      v45.synapse->status = 2;
      IVP_U_Float_Point::set_interpolate(
        this: (IVP_U_Float_Point *)(side + 16),
        p0: K_Los,
        p1: v69,
        s: kkr->checks_K[0] / (float)(kkr->checks_K[1] + kkr->checks_K[0]));
      v46.synapse = (IVP_Synapse_Real *)m_cache_L->tmp;
      v46.synapse->edge = L;
      v46.synapse->status = 5;
      return IVP_MRC_BACKSIDE;
    }
    else
    {
      return IVP_MRC_OK;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5890
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_Leave_BK(class IVP_Cache_Ball __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_Leave_BK@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        IVP_Compact_Edge a2@<ebp>,
        IVP_Cache_Ball *m_cache_ball,
        const IVP_Compact_Edge *K,
        IVP_Cache_Ledge_Point *m_cache_K)
{
  bool v5; // sf
  IVP_MRC_TYPE result; // eax
  const IVP_Compact_Poly_Point *compact_poly_points; // edx
  IVP_Compact_Edge v8; // eax
  float *v9; // eax
  int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  const IVP_Compact_Poly_Point *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  const IVP_Compact_Ledge *compact_ledge; // eax
  IVP_Mindist_Minimize_Solver *v21; // eax
  __int16 v22; // dx
  float v23; // xmm0_4
  IVP_Mindist_Minimize_Solver *v24; // edx
  IVP_Mindist *mindist; // eax
  IVP_Cache_Object *cache_object; // ecx
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  IVP_Cache_Object *clp_cache_object; // eax
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  IVP_Mindist *v34; // eax
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v38; // edi
  float v39; // [esp+14h] [ebp-CCh] BYREF
  IVP_Unscaled_QR_Result qr0; // [esp+20h] [ebp-C0h] BYREF
  IVP_Unscaled_QR_Result qr1; // [esp+30h] [ebp-B0h] BYREF
  IVP_U_Point vec_K_tri; // [esp+40h] [ebp-A0h] BYREF
  IVP_U_Point vec_K_oppo_tri; // [esp+50h] [ebp-90h] BYREF
  IVP_U_Point hesse_oppo_tri_os; // [esp+60h] [ebp-80h] BYREF
  IVP_U_Point hesse_tri_os; // [esp+70h] [ebp-70h] BYREF
  IVP_U_Point vec_K_P; // [esp+80h] [ebp-60h] BYREF
  IVP_U_Point p_ks; // [esp+90h] [ebp-50h] BYREF
  IVP_U_Point vec_K_ks; // [esp+A0h] [ebp-40h] BYREF
  float v49; // [esp+C0h] [ebp-20h]
  float v50; // [esp+C4h] [ebp-1Ch]
  float quad; // [esp+C8h] [ebp-18h]
  float iqK_len; // [esp+CCh] [ebp-14h]
  IVP_Mindist_Minimize_Solver *v53; // [esp+D0h] [ebp-10h]
  IVP_Compact_Edge qdist; // [esp+D4h] [ebp-Ch] BYREF
  float inv_len; // [esp+D8h] [ebp-8h]
  float retaddr; // [esp+E0h] [ebp+0h]

  qdist = a2;
  inv_len = retaddr;
  v5 = --this->P_Finish_Counter < 0;
  v53 = this;
  if ( v5
    && IVP_Mindist_Minimize_Solver::check_loop_hash(this, i_s0: IVP_ST_BALL, i_e0: nullptr, i_s1: IVP_ST_EDGE, i_e1: K) != 0 )
  {
    return IVP_MRC_ENDLESS_LOOP;
  }
  IVP_Cache_Object::transform_position_to_object_coords(
    this: m_cache_K->clp_cache_object,
    P_world: &m_cache_ball->cache_object->m_world_f_object.vv,
    P_object_out: (IVP_U_Point *)&vec_K_P.k[1]);
  compact_poly_points = m_cache_K->compact_poly_points;
  v8 = *K;
  LODWORD(iqK_len) = (unsigned __int8)K & 0xC;
  LODWORD(quad) = &compact_poly_points[(unsigned __int16)*(_DWORD *)((char *)K
                                                                   + *(int *)((char *)IVP_Compact_Edge::next_table
                                                                            + LODWORD(iqK_len)))];
  LODWORD(iqK_len) = &compact_poly_points[(unsigned __int16)*(_DWORD *)((char *)K
                                                                      + *(int *)((char *)IVP_Compact_Edge::prev_table
                                                                               + LODWORD(iqK_len)))];
  v9 = compact_poly_points[*(_WORD *)&v8].k;
  v10 = *(int *)((char *)&K[(2 * *(_DWORD *)K) >> 17]
               + *(int *)((char *)IVP_Compact_Edge::prev_table
                        + (((_BYTE)K + 4 * (unsigned __int8)((2 * *(_DWORD *)K) >> 17)) & 0xC)));
  v11 = *(float *)(LODWORD(quad) + 4) - v9[1];
  v12 = *(float *)(LODWORD(quad) + 8) - v9[2];
  p_ks.k[1] = *(float *)LODWORD(quad) - *v9;
  p_ks.k[2] = v11;
  p_ks.hesse_val = v12;
  v13 = vec_K_P.k[2] - v9[1];
  v14 = vec_K_P.hesse_val - v9[2];
  hesse_tri_os.k[1] = vec_K_P.k[1] - *v9;
  hesse_tri_os.k[2] = v13;
  hesse_tri_os.hesse_val = v14;
  v15 = *(float *)(LODWORD(iqK_len) + 4) - v9[1];
  v16 = *(float *)(LODWORD(iqK_len) + 8) - v9[2];
  qr1.checks[1] = *(float *)LODWORD(iqK_len) - *v9;
  qr1.checks[2] = v15;
  qr1.scale = v16;
  v17 = &m_cache_K->compact_poly_points[(unsigned __int16)v10];
  v18 = v17->k[1] - v9[1];
  v19 = v17->k[2] - v9[2];
  vec_K_tri.k[1] = v17->k[0] - *v9;
  vec_K_tri.k[2] = v18;
  vec_K_tri.hesse_val = v19;
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Point *)&hesse_oppo_tri_os.k[1],
    v1: (IVP_U_Point *)&p_ks.k[1],
    v2: (const IVP_U_Float_Point *)&qr1.checks[1]);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Point *)&vec_K_oppo_tri.k[1],
    v1: (IVP_U_Point *)&vec_K_tri.k[1],
    v2: (IVP_U_Point *)&p_ks.k[1]);
  compact_ledge = m_cache_K->compact_ledge;
  v49 = (float)((float)(hesse_tri_os.k[1] * hesse_oppo_tri_os.k[1]) + (float)(hesse_oppo_tri_os.k[2] * hesse_tri_os.k[2]))
      + (float)(hesse_oppo_tri_os.hesse_val * hesse_tri_os.hesse_val);
  v50 = (float)((float)(vec_K_oppo_tri.k[1] * hesse_tri_os.k[1]) + (float)(vec_K_oppo_tri.k[2] * hesse_tri_os.k[2]))
      + (float)(vec_K_oppo_tri.hesse_val * hesse_tri_os.hesse_val);
  IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
    c_ledge: compact_ledge,
    tri: (int)K,
    p_object: (IVP_U_Point *)&vec_K_P.k[1],
    result: (IVP_Unscaled_QR_Result *)&v39);
  IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
    c_ledge: m_cache_K->compact_ledge,
    tri: (int)&K[(2 * *(_DWORD *)K) >> 17],
    p_object: (IVP_U_Point *)&vec_K_P.k[1],
    result: (IVP_Unscaled_QR_Result *)&qr0.checks[1]);
  if ( v39 <= 0.0 )
  {
    if ( qr0.checks[1] > 0.0 )
      return IVP_Mindist_Minimize_Solver::p_minimize_BF(
               this: v53,
               a2: &qdist,
               m_cache_B: m_cache_ball,
               F: &K[(2 * *(_DWORD *)K) >> 17],
               m_cache_F: m_cache_K);
    if ( v49 >= -1.0e-10 || v50 >= -1.0e-10 )
    {
      IVP_U_Float_Point::calc_cross_product(
        this: (IVP_U_Point *)&vec_K_ks.k[1],
        v1: (IVP_U_Point *)&p_ks.k[1],
        v2: (IVP_U_Point *)&hesse_tri_os.k[1]);
      v50 = 1.0
          / (float)((float)((float)(p_ks.k[1] * p_ks.k[1]) + (float)(p_ks.k[2] * p_ks.k[2]))
                  + (float)(p_ks.hesse_val * p_ks.hesse_val));
      quad = (float)((float)((float)(vec_K_ks.k[1] * vec_K_ks.k[1]) + (float)(vec_K_ks.k[2] * vec_K_ks.k[2]))
                   + (float)(vec_K_ks.hesse_val * vec_K_ks.hesse_val))
           * v50;
      iqK_len = IVP_Inline_Math::isqrt_float(quad);
      v53->mindist->len_numerator = (float)(iqK_len * quad) - v53->mindist->sum_extra_radius;
      IVP_U_Float_Point::calc_cross_product(
        this: (IVP_U_Point *)&vec_K_ks.k[1],
        v1: (IVP_U_Point *)&p_ks.k[1],
        v2: (IVP_U_Point *)&vec_K_ks.k[1]);
      IVP_Cache_Object::transform_vector_to_world_coords(
        this: m_cache_K->clp_cache_object,
        P_object: (IVP_U_Point *)&vec_K_ks.k[1],
        P_world_out: (IVP_U_Point *)&vec_K_ks.k[1]);
      LODWORD(v23) = COERCE_UNSIGNED_INT(iqK_len * v50) ^ _mask__NegFloat_;
      v24 = v53;
      mindist = v53->mindist;
      cache_object = m_cache_ball->cache_object;
      v27 = vec_K_ks.k[2] * v23;
      v28 = vec_K_ks.hesse_val * v23;
      v29 = v23 * vec_K_ks.k[1];
      mindist->contact_plane.k[1] = v27;
      mindist->contact_plane.k[0] = v29;
      mindist->contact_plane.k[2] = v28;
      clp_cache_object = m_cache_K->clp_cache_object;
      v31 = cache_object->core_pos.k[0] - clp_cache_object->core_pos.k[0];
      v32 = cache_object->core_pos.k[1] - clp_cache_object->core_pos.k[1];
      v33 = cache_object->core_pos.k[2] - clp_cache_object->core_pos.k[2];
      v34 = v24->mindist;
      v35 = v24->mindist->contact_plane.k[1] * v32;
      v36 = v24->mindist->contact_plane.k[0] * v31;
      v37 = v24->mindist->contact_plane.k[2] * v33;
      v22 = 1;
      v34->contact_dot_diff_center = (float)(v35 + v36) + v37;
      result = IVP_MRC_OK;
    }
    else
    {
      v21 = v53;
      v53->pos_opposite_BacksideOs.k[0] = vec_K_P.k[1];
      v21->pos_opposite_BacksideOs.k[1] = vec_K_P.k[2];
      v22 = 5;
      v21->pos_opposite_BacksideOs.k[2] = vec_K_P.hesse_val;
      result = IVP_MRC_BACKSIDE;
    }
    v38.synapse = (IVP_Synapse_Real *)m_cache_K->tmp;
    v38.synapse->status = v22;
    v38.synapse->edge = K;
  }
  else
  {
    if ( qr0.checks[1] > 0.0 && v50 > 0.0 )
      return IVP_Mindist_Minimize_Solver::p_minimize_BF(
               this: v53,
               a2: &qdist,
               m_cache_B: m_cache_ball,
               F: &K[(2 * *(_DWORD *)K) >> 17],
               m_cache_F: m_cache_K);
    return IVP_Mindist_Minimize_Solver::p_minimize_BF(
             this: v53,
             a2: &qdist,
             m_cache_B: m_cache_ball,
             F: K,
             m_cache_F: m_cache_K);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A5CF0
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_KK(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_KK@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        const IVP_Compact_Edge *a2@<ebp>,
        const IVP_Compact_Edge *K,
        const IVP_Compact_Edge *L,
        IVP_Cache_Ledge_Point *m_cache_K,
        IVP_Cache_Ledge_Point *m_cache_L)
{
  int v7; // edx
  int v8; // eax
  int v9; // eax
  float v10; // eax
  _BYTE v11[12]; // [esp-Ch] [ebp-DCh] BYREF
  IVP_KK_Input kkin; // [esp+0h] [ebp-D0h] BYREF
  IVP_U_Point plp_Kos; // [esp+70h] [ebp-60h] BYREF
  IVP_Unscaled_S_Result v14; // [esp+90h] [ebp-40h] BYREF
  float v15; // [esp+98h] [ebp-38h] BYREF
  IVP_Unscaled_S_Result sr_lK; // [esp+9Ch] [ebp-34h]
  IVP_Unscaled_S_Result sr_kL; // [esp+A4h] [ebp-2Ch] BYREF
  const IVP_Compact_Edge *pkm; // [esp+ACh] [ebp-24h]
  const IVP_Compact_Edge *plm; // [esp+B0h] [ebp-20h]
  IVP_Unscaled_KK_Result kkr; // [esp+B4h] [ebp-1Ch]
  const IVP_Compact_Edge *plp; // [esp+C4h] [ebp-Ch] BYREF
  const IVP_Compact_Edge *pkp; // [esp+C8h] [ebp-8h]
  const IVP_Compact_Edge *retaddr; // [esp+D0h] [ebp+0h]

  plp = a2;
  pkp = retaddr;
  LODWORD(kkr.checks_L[1]) = this;
  IVP_KK_Input::IVP_KK_Input(this: (IVP_KK_Input *)v11, K_in: K, L_in: L, m_cache_K, m_cache_L);
  IVP_Compact_Ledge_Solver::calc_unscaled_KK_vals(
    a1: (int)&plp,
    in: (const IVP_KK_Input *)v11,
    result: (IVP_Unscaled_KK_Result *)&sr_kL.checks[1]);
  if ( (((unsigned int)plm | LODWORD(kkr.checks_K[0])) & 0x80000000) != 0 )
  {
    if ( ((LODWORD(sr_kL.checks[1]) | (unsigned int)pkm) & 0x80000000) != 0 )
    {
      if ( *(float *)&pkm <= sr_kL.checks[1] )
      {
        LODWORD(kkr.checks_L[0]) = (char *)K
                                 + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC));
        LODWORD(sr_lK.checks[1]) = K;
      }
      else
      {
        v8 = *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC));
        LODWORD(kkr.checks_L[0]) = K;
        LODWORD(sr_lK.checks[1]) = (char *)K + v8;
      }
      if ( kkr.checks_K[0] <= *(float *)&plm )
      {
        LODWORD(kkr.checks_K[1]) = (char *)L
                                 + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)L & 0xC));
        LODWORD(sr_kL.checks[0]) = L;
      }
      else
      {
        v9 = *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)L & 0xC));
        LODWORD(kkr.checks_K[1]) = L;
        LODWORD(sr_kL.checks[0]) = (char *)L + v9;
      }
      IVP_Compact_Ledge_Solver::calc_pos_other_space(
        P: (const IVP_Compact_Edge *)LODWORD(kkr.checks_L[0]),
        m_cache_P: m_cache_K,
        m_cache_other_space: m_cache_L,
        res: (IVP_U_Point *)&plp_Kos.k[1]);
      IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(
        c_ledge: m_cache_L->compact_ledge,
        edge: L,
        p_object: (IVP_U_Point *)&plp_Kos.k[1],
        result: (IVP_Unscaled_S_Result *)&v15);
      if ( (LODWORD(v15) | LODWORD(sr_lK.checks[0])) >= 0 )
        return IVP_Mindist_Minimize_Solver::p_minimize_PK(
                 this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
                 a2: COERCE_FLOAT(&plp),
                 P: (const IVP_Compact_Edge *)LODWORD(kkr.checks_L[0]),
                 K: L,
                 m_cache_P: m_cache_K,
                 m_cache_K: m_cache_L);
      IVP_Compact_Ledge_Solver::calc_pos_other_space(
        P: (const IVP_Compact_Edge *)LODWORD(kkr.checks_K[1]),
        m_cache_P: m_cache_L,
        m_cache_other_space: m_cache_K,
        res: (IVP_U_Point *)&kkin.cross_KL_Los.k[1]);
      IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(
        c_ledge: m_cache_K->compact_ledge,
        edge: K,
        p_object: (const IVP_U_Point *)&kkin.cross_KL_Los.k[1],
        result: &v14);
      if ( (LODWORD(v14.checks[0]) | LODWORD(v14.checks[1])) >= 0 )
      {
        IVP_Mindist_Minimize_Solver::sort_synapses(
          this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
          a: m_cache_L->tmp.synapse,
          __formal: m_cache_K->tmp.synapse);
        return IVP_Mindist_Minimize_Solver::p_minimize_PK(
                 this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
                 a2: COERCE_FLOAT(&plp),
                 P: (const IVP_Compact_Edge *)LODWORD(kkr.checks_K[1]),
                 K,
                 m_cache_P: m_cache_L,
                 m_cache_K);
      }
      if ( (float)(v15 * *(float *)&plm) >= 0.0 )
      {
        if ( (float)(v14.checks[0] * sr_kL.checks[1]) < 0.0 )
        {
          IVP_Mindist_Minimize_Solver::sort_synapses(
            this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
            a: m_cache_L->tmp.synapse,
            __formal: m_cache_K->tmp.synapse);
          return IVP_Mindist_Minimize_Solver::p_minimize_PP(
                   this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
                   a2: (int)&plp,
                   A: (const IVP_Compact_Edge *)LODWORD(kkr.checks_K[1]),
                   B: (const IVP_Compact_Edge *)LODWORD(sr_lK.checks[1]),
                   m_cache_A: m_cache_L,
                   m_cache_B: m_cache_K);
        }
        v10 = kkr.checks_K[1];
      }
      else
      {
        v10 = sr_kL.checks[0];
      }
      return IVP_Mindist_Minimize_Solver::p_minimize_PP(
               this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
               a2: (int)&plp,
               A: (const IVP_Compact_Edge *)LODWORD(kkr.checks_L[0]),
               B: (const IVP_Compact_Edge *)LODWORD(v10),
               m_cache_A: m_cache_K,
               m_cache_B: m_cache_L);
    }
    else
    {
      v7 = *(_DWORD *)LODWORD(kkr.checks_L[1]);
      if ( m_cache_L->tmp.synapse != (IVP_Synapse_Real *)(v7 + 28 * ((*(_DWORD *)(v7 + 20) >> 8) & 3) + 24) )
        *(_DWORD *)(v7 + 20) ^= 0x100u;
      if ( *(float *)&plm >= 0.0 )
        return IVP_Mindist_Minimize_Solver::p_minimize_PK(
                 this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
                 a2: COERCE_FLOAT(&plp),
                 P: (const IVP_Compact_Edge *)((char *)L
                                          + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)L & 0xC))),
                 K,
                 m_cache_P: m_cache_L,
                 m_cache_K);
      else
        return IVP_Mindist_Minimize_Solver::p_minimize_PK(
                 this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
                 a2: COERCE_FLOAT(&plp),
                 P: L,
                 K,
                 m_cache_P: m_cache_L,
                 m_cache_K);
    }
  }
  else if ( sr_kL.checks[1] >= 0.0 )
  {
    if ( *(float *)&pkm >= 0.0 )
      return IVP_Mindist_Minimize_Solver::p_minimize_Leave_KK(
               this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
               a2: (const IVP_Compact_Edge *)&plp,
               K,
               L,
               kkin: (const IVP_KK_Input *)v11,
               kkr: (const IVP_Unscaled_KK_Result *)&sr_kL.checks[1],
               m_cache_K,
               m_cache_L);
    else
      return IVP_Mindist_Minimize_Solver::p_minimize_PK(
               this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
               a2: COERCE_FLOAT(&plp),
               P: (const IVP_Compact_Edge *)((char *)K
                                        + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC))),
               K: L,
               m_cache_P: m_cache_K,
               m_cache_K: m_cache_L);
  }
  else
  {
    return IVP_Mindist_Minimize_Solver::p_minimize_PK(
             this: (IVP_Mindist_Minimize_Solver *)LODWORD(kkr.checks_L[1]),
             a2: COERCE_FLOAT(&plp),
             P: K,
             K: L,
             m_cache_P: m_cache_K,
             m_cache_K: m_cache_L);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5FD0
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_Leave_PF(class IVP_Compact_Edge const __near *,class IVP_U_Point const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_Leave_PF@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        IVP_Compact_Edge a2@<ebp>,
        const IVP_Compact_Edge *P,
        const IVP_U_Point *P_Fos,
        int F,
        IVP_Cache_Ledge_Point *m_cache_P,
        IVP_Cache_Ledge_Point *m_cache_F)
{
  bool v8; // sf
  const IVP_Compact_Poly_Point *v10; // eax
  IVP_Mindist *mindist; // eax
  float v12; // xmm0_4
  float hesse_val; // xmm1_4
  IVP_Mindist *v14; // eax
  const IVP_Compact_Edge *v15; // ecx
  const IVP_Compact_Poly_Point *v16; // esi
  const IVP_Compact_Edge *v17; // eax
  int v18; // edi
  const IVP_Compact_Edge *i; // edi
  const IVP_Compact_Poly_Point *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  long double v24; // st7
  long double v25; // st7
  const IVP_Compact_Edge *v26; // edi
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v27; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v28; // eax
  const IVP_Compact_Edge *v29; // ecx
  float v30; // xmm0_4
  float v31; // xmm1_4
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v32; // eax
  const IVP_Compact_Edge *v33; // esi
  int v34; // eax
  const IVP_Compact_Edge *v35; // eax
  int v36; // ecx
  int v37; // edi
  double v38; // st7
  _BYTE v39[12]; // [esp+14h] [ebp-7Ch] BYREF
  IVP_U_Point P2_Fos; // [esp+20h] [ebp-70h] BYREF
  IVP_U_Point hesse_vec_ws; // [esp+30h] [ebp-60h] BYREF
  IVP_U_Point wHesse_vecF_Fos; // [esp+40h] [ebp-50h] BYREF
  IVP_Unscaled_QR_Result qr; // [esp+50h] [ebp-40h] BYREF
  unsigned __int64 v44; // [esp+70h] [ebp-20h]
  float v45; // [esp+78h] [ebp-18h]
  const IVP_Compact_Edge *Pm; // [esp+7Ch] [ebp-14h]
  const IVP_Compact_Edge *best_edge; // [esp+80h] [ebp-10h]
  IVP_Compact_Edge len; // [esp+84h] [ebp-Ch] BYREF
  void *v49; // [esp+88h] [ebp-8h]
  void *retaddr; // [esp+90h] [ebp+0h]

  len = a2;
  v49 = retaddr;
  v8 = --this->P_Finish_Counter < 0;
  Pm = (const IVP_Compact_Edge *)this;
  if ( v8
    && IVP_Mindist_Minimize_Solver::check_loop_hash(
         this,
         i_s0: IVP_ST_POINT,
         i_e0: P,
         i_s1: IVP_ST_TRIANGLE,
         i_e1: (const IVP_Compact_Edge *)F) != 0 )
  {
    return IVP_MRC_ENDLESS_LOOP;
  }
  IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
    edge: (const IVP_Compact_Edge *)F,
    ledge: m_cache_F->compact_ledge,
    out_vec: (IVP_U_Point *)&hesse_vec_ws.k[1]);
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Point *)&hesse_vec_ws.k[1]);
  IVP_Cache_Object::transform_vector_to_world_coords(
    this: m_cache_F->clp_cache_object,
    P_object: (IVP_U_Point *)&hesse_vec_ws.k[1],
    P_world_out: (IVP_U_Point *)&P2_Fos.k[1]);
  IVP_Cache_Object::transform_vector_to_object_coords(
    this: m_cache_P->clp_cache_object,
    P_world: (IVP_U_Point *)&P2_Fos.k[1],
    P_object_out: (IVP_U_Float_Point *)&qr.checks[1]);
  v10 = &m_cache_F->compact_poly_points[(unsigned __int16)*(_DWORD *)F];
  this->mindist->len_numerator = (float)((float)((float)(P_Fos->k[1] * hesse_vec_ws.k[2])
                                               + (float)(P_Fos->k[0] * hesse_vec_ws.k[1]))
                                       + (float)(P_Fos->k[2] * hesse_vec_ws.hesse_val))
                               - (float)((float)((float)(v10->k[1] * hesse_vec_ws.k[2])
                                               + (float)(v10->k[0] * hesse_vec_ws.k[1]))
                                       + (float)(v10->k[2] * hesse_vec_ws.hesse_val));
  mindist = this->mindist;
  v12 = P2_Fos.k[2];
  hesse_val = P2_Fos.hesse_val;
  mindist->contact_plane.k[0] = P2_Fos.k[1];
  mindist->contact_plane.k[1] = v12;
  mindist->contact_plane.k[2] = hesse_val;
  v14 = this->mindist;
  if ( this->mindist->len_numerator < 0.0 )
  {
    qr.checks[1] = qr.checks[1] * -1.0;
    qr.checks[2] = qr.checks[2] * -1.0;
    qr.scale = qr.scale * -1.0;
  }
  v14->len_numerator = v14->len_numerator - v14->sum_extra_radius;
  this->mindist->contact_dot_diff_center = (float)((float)(this->mindist->contact_plane.k[1]
                                                         * (float)(m_cache_P->clp_cache_object->core_pos.k[1]
                                                                 - m_cache_F->clp_cache_object->core_pos.k[1]))
                                                 + (float)(this->mindist->contact_plane.k[0]
                                                         * (float)(m_cache_P->clp_cache_object->core_pos.k[0]
                                                                 - m_cache_F->clp_cache_object->core_pos.k[0])))
                                         + (float)(this->mindist->contact_plane.k[2]
                                                 * (float)(m_cache_P->clp_cache_object->core_pos.k[2]
                                                         - m_cache_F->clp_cache_object->core_pos.k[2]));
  v15 = (const IVP_Compact_Edge *)((char *)P
                                 + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)P & 0xC)));
  v16 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)P];
  v17 = &v15[(2 * *(_DWORD *)v15) >> 17];
  v18 = *(int *)((char *)IVP_Compact_Edge::prev_table
               + (((_BYTE)v15 + 4 * (unsigned __int8)((2 * *(_DWORD *)v15) >> 17)) & 0xC));
  best_edge = nullptr;
  v44 = (unsigned int)v15;
  for ( i = (const IVP_Compact_Edge *)((char *)v17 + v18);
        ;
        i = (const IVP_Compact_Edge *)((char *)v26
                                     + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)v26 & 0xC))) )
  {
    v20 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)i];
    v21 = v20->k[0] - v16->k[0];
    v22 = v20->k[1] - v16->k[1];
    v23 = v20->k[2] - v16->k[2];
    v45 = (float)((float)(v22 * qr.checks[2]) + (float)(v21 * qr.checks[1])) + (float)(v23 * qr.scale);
    if ( v45 < 0.0 )
    {
      v24 = IVP_Inline_Math::isqrt_float(quad: (float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v23 * v23));
      v25 = v24 * v45;
      v15 = (const IVP_Compact_Edge *)v44;
      v45 = v25;
      if ( *((float *)&v44 + 1) > v25 )
      {
        best_edge = i;
        *((float *)&v44 + 1) = v45;
      }
    }
    if ( i == v15 )
      break;
    v26 = &i[(2 * *(_DWORD *)i) >> 17];
  }
  if ( best_edge != nullptr )
  {
    IVP_Compact_Ledge_Solver::calc_pos_other_space(
      P: best_edge,
      m_cache_P,
      m_cache_other_space: m_cache_F,
      res: (IVP_U_Point *)v39);
    v33 = (const IVP_Compact_Edge *)F;
    IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
      c_ledge: (const IVP_Compact_Ledge *)((F & 0xFFFFFFF0) - 16 * ((*(_DWORD *)(F & 0xFFFFFFF0) & 0xFFF) + 1)),
      tri: F,
      p_object: (const IVP_U_Point *)v39,
      result: (IVP_Unscaled_QR_Result *)&wHesse_vecF_Fos.k[1]);
    if ( (LODWORD(wHesse_vecF_Fos.k[1]) | LODWORD(wHesse_vecF_Fos.k[2]) | LODWORD(wHesse_vecF_Fos.hesse_val)) < 0 )
    {
      v34 = wHesse_vecF_Fos.k[1] < 0.0;
      if ( wHesse_vecF_Fos.k[2] < 0.0 )
        ++v34;
      if ( wHesse_vecF_Fos.hesse_val < 0.0 )
        ++v34;
      if ( v34 == 1 )
      {
        v35 = (const IVP_Compact_Edge *)F;
        v36 = 0;
        while ( wHesse_vecF_Fos.k[v36 + 1] >= 0.0 )
        {
          v35 = (const IVP_Compact_Edge *)((char *)v35
                                         + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v35 & 0xC)));
          if ( ++v36 >= 3 )
            goto LABEL_26;
        }
        return IVP_Mindist_Minimize_Solver::p_minimize_KK(
                 this: (IVP_Mindist_Minimize_Solver *)Pm,
                 a2: &len,
                 K: best_edge,
                 L: v35,
                 m_cache_K: m_cache_P,
                 m_cache_L: m_cache_F);
      }
      else
      {
LABEL_26:
        v37 = 0;
        v44 = 1621981420;
        do
        {
          if ( wHesse_vecF_Fos.k[v37 + 1] <= 0.0 )
          {
            v38 = IVP_Compact_Ledge_Solver::calc_qlen_KK(
                    a1: COERCE_FLOAT(&len),
                    K: best_edge,
                    L: v33,
                    m_cache_K: m_cache_P,
                    m_cache_L: m_cache_F);
            v45 = v38;
            if ( *(float *)&v44 > v38 )
              v44 = __PAIR64__((unsigned int)v33, LODWORD(v45));
          }
          v33 = (const IVP_Compact_Edge *)((char *)v33
                                         + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v33 & 0xC)));
          ++v37;
        }
        while ( v37 < 3 );
        return IVP_Mindist_Minimize_Solver::p_minimize_KK(
                 this: (IVP_Mindist_Minimize_Solver *)Pm,
                 a2: &len,
                 K: best_edge,
                 L: (const IVP_Compact_Edge *)HIDWORD(v44),
                 m_cache_K: m_cache_P,
                 m_cache_L: m_cache_F);
      }
    }
    else
    {
      return IVP_Mindist_Minimize_Solver::p_minimize_Leave_PF(
               this: (IVP_Mindist_Minimize_Solver *)Pm,
               P: best_edge,
               P_Fos: (const IVP_U_Point *)v39,
               (const IVP_Compact_Edge *)F,
               m_cache_P,
               m_cache_F);
    }
  }
  else
  {
    v27.synapse = (IVP_Synapse_Real *)m_cache_P->tmp;
    v27.synapse->edge = P;
    v27.synapse->status = 0;
    v28.synapse = (IVP_Synapse_Real *)m_cache_F->tmp;
    v28.synapse->status = 2;
    v29 = Pm;
    v28.synapse->edge = (const IVP_Compact_Edge *)F;
    if ( (float)(*(float *)(*(_DWORD *)v29 + 92) + *(float *)(*(_DWORD *)v29 + 80)) >= 0.0 )
    {
      return IVP_MRC_OK;
    }
    else
    {
      v30 = P_Fos->k[1];
      v31 = P_Fos->k[2];
      v29[4] = LODWORD(P_Fos->k[0]);
      v32.synapse = (IVP_Synapse_Real *)m_cache_F->tmp;
      *(float *)&v29[5] = v30;
      *(float *)&v29[6] = v31;
      v32.synapse->edge = (const IVP_Compact_Edge *)F;
      v32.synapse->status = 5;
      return IVP_MRC_BACKSIDE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6470
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_PF(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_PF@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        const IVP_Compact_Edge *a2@<ebp>,
        const IVP_Compact_Edge *P,
        const IVP_Compact_Edge *F,
        IVP_Cache_Ledge_Point *m_cache_P,
        IVP_Cache_Ledge_Point *m_cache_F)
{
  const IVP_Compact_Edge *v6; // esi
  double v8; // st7
  _BYTE v9[12]; // [esp-Ch] [ebp-4Ch] BYREF
  _DWORD v10[3]; // [esp+10h] [ebp-30h] BYREF
  IVP_Unscaled_QR_Result qr; // [esp+1Ch] [ebp-24h]
  int dist; // [esp+2Ch] [ebp-14h]
  float v13; // [esp+30h] [ebp-10h]
  const IVP_Compact_Edge *min_edge; // [esp+34h] [ebp-Ch] BYREF
  void *v15; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  min_edge = a2;
  v15 = retaddr;
  LODWORD(qr.checks[2]) = this;
  IVP_Compact_Ledge_Solver::calc_pos_other_space(P, m_cache_P, m_cache_other_space: m_cache_F, res: (IVP_U_Point *)v9);
  v6 = F;
  IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
    c_ledge: m_cache_F->compact_ledge,
    tri: (int)F,
    p_object: (const IVP_U_Point *)v9,
    result: (IVP_Unscaled_QR_Result *)v10);
  if ( (v10[0] | v10[1] | v10[2]) >= 0 )
    return IVP_Mindist_Minimize_Solver::p_minimize_Leave_PF(
             this: (IVP_Mindist_Minimize_Solver *)LODWORD(qr.checks[2]),
             a2: (IVP_Compact_Edge)&min_edge,
             P,
             P_Fos: (const IVP_U_Point *)v9,
             (int)F,
             m_cache_P,
             m_cache_F);
  v13 = 1.0e20;
  qr.scale = 0.0;
  for ( dist = 3; dist != 0; --dist )
  {
    v8 = IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(
           P_in_K_space: (const IVP_U_Point *)v9,
           K_ledge: m_cache_F->compact_ledge,
           K: v6);
    qr.checks[1] = v8;
    if ( v13 > v8 )
    {
      v13 = qr.checks[1];
      LODWORD(qr.scale) = v6;
    }
    v6 = (const IVP_Compact_Edge *)((char *)v6
                                  + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v6 & 0xC)));
  }
  return IVP_Mindist_Minimize_Solver::p_minimize_PK(
           this: (IVP_Mindist_Minimize_Solver *)LODWORD(qr.checks[2]),
           a2: COERCE_FLOAT(&min_edge),
           P,
           K: (const IVP_Compact_Edge *)LODWORD(qr.scale),
           m_cache_P,
           m_cache_K: m_cache_F);
}

//------------------------------------------------------------------------------
// Address: 0x100A6560
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_Leave_PK(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __userpurge IVP_Mindist_Minimize_Solver::p_minimize_Leave_PK@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        IVP_Compact_Edge a2@<ebp>,
        const IVP_Compact_Edge *P,
        const IVP_Compact_Edge *K,
        IVP_Cache_Ledge_Point *m_cache_P,
        IVP_Cache_Ledge_Point *m_cache_K)
{
  bool v6; // sf
  const IVP_Compact_Poly_Point *compact_poly_points; // edi
  IVP_Compact_Edge v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float *v17; // eax
  int v18; // edx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  const IVP_Compact_Poly_Point *v23; // edx
  float v24; // xmm0_4
  float v25; // xmm1_4
  const IVP_Compact_Ledge *compact_ledge; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v27; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v28; // edi
  IVP_Mindist_Minimize_Solver *v29; // eax
  float quad; // xmm0_4
  long double v31; // st7
  float v32; // xmm0_4
  IVP_Mindist *v33; // eax
  float v34; // xmm1_4
  float v35; // xmm2_4
  IVP_Mindist *mindist; // eax
  float v37; // xmm0_4
  const IVP_Compact_Edge *v38; // xmm1_4
  const IVP_Compact_Poly_Point *v39; // edi
  float v40; // ecx
  const IVP_Compact_Edge *v41; // eax
  const IVP_Compact_Poly_Point *v42; // eax
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  long double v46; // st7
  long double v47; // st7
  const IVP_Compact_Edge *v48; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v49; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v50; // eax
  _BYTE v51[12]; // [esp+14h] [ebp-15Ch] BYREF
  IVP_KK_Input kkin; // [esp+20h] [ebp-150h] BYREF
  IVP_Unscaled_QR_Result qr0; // [esp+90h] [ebp-E0h] BYREF
  IVP_Unscaled_QR_Result qr1; // [esp+A0h] [ebp-D0h] BYREF
  IVP_U_Point vec_K_oppo_tri; // [esp+B0h] [ebp-C0h] BYREF
  IVP_U_Point vec_K_tri; // [esp+C0h] [ebp-B0h] BYREF
  IVP_U_Point hesse_oppo_tri_os; // [esp+D0h] [ebp-A0h] BYREF
  IVP_U_Point hesse_tri_os; // [esp+E0h] [ebp-90h] BYREF
  IVP_U_Point vec_K_P; // [esp+F0h] [ebp-80h] BYREF
  IVP_U_Point p_ks; // [esp+100h] [ebp-70h] BYREF
  float v61; // [esp+120h] [ebp-50h]
  float v62[2]; // [esp+124h] [ebp-4Ch] BYREF
  float angle; // [esp+12Ch] [ebp-44h]
  const IVP_Compact_Edge *i; // [esp+140h] [ebp-30h]
  _DWORD v65[2]; // [esp+144h] [ebp-2Ch] BYREF
  const IVP_Compact_Edge *e; // [esp+14Ch] [ebp-24h]
  float v67; // [esp+150h] [ebp-20h]
  float v68; // [esp+158h] [ebp-18h]
  float inv_len; // [esp+15Ch] [ebp-14h]
  IVP_Mindist_Minimize_Solver *v70; // [esp+160h] [ebp-10h]
  IVP_Compact_Edge iqK_len; // [esp+164h] [ebp-Ch] BYREF
  float max_s_val; // [esp+168h] [ebp-8h]
  float retaddr; // [esp+170h] [ebp+0h]

  iqK_len = a2;
  max_s_val = retaddr;
  v6 = --this->P_Finish_Counter < 0;
  v70 = this;
  if ( v6
    && IVP_Mindist_Minimize_Solver::check_loop_hash(this, i_s0: IVP_ST_POINT, i_e0: P, i_s1: IVP_ST_EDGE, i_e1: K) != 0 )
  {
    return IVP_MRC_ENDLESS_LOOP;
  }
  IVP_Compact_Ledge_Solver::calc_pos_other_space(
    P,
    m_cache_P,
    m_cache_other_space: m_cache_K,
    res: (IVP_U_Point *)&vec_K_P.k[1]);
  compact_poly_points = m_cache_K->compact_poly_points;
  v9 = *K;
  v10 = (unsigned __int8)K & 0xC;
  v11 = *(int *)((char *)K + *(int *)((char *)IVP_Compact_Edge::next_table + v10));
  LODWORD(v67) = &m_cache_K->compact_poly_points[(unsigned __int16)*(_DWORD *)((char *)K
                                                                             + *(int *)((char *)IVP_Compact_Edge::prev_table
                                                                                      + v10))];
  v12 = (unsigned __int16)v11;
  v13 = *(_WORD *)&v9;
  v14 = compact_poly_points[v12].k[1] - compact_poly_points[v13].k[1];
  v15 = compact_poly_points[v12].k[2] - compact_poly_points[v13].k[2];
  v16 = compact_poly_points[v12].k[0] - compact_poly_points[v13].k[0];
  v17 = compact_poly_points[v13].k;
  v18 = *(int *)((char *)&K[(2 * *(_DWORD *)K) >> 17]
               + *(int *)((char *)IVP_Compact_Edge::prev_table
                        + (((_BYTE)K + 4 * (unsigned __int8)((2 * *(_DWORD *)K) >> 17)) & 0xC)));
  p_ks.k[1] = v16;
  p_ks.k[2] = v14;
  p_ks.hesse_val = v15;
  v19 = vec_K_P.k[2] - v17[1];
  v20 = vec_K_P.hesse_val - v17[2];
  hesse_tri_os.k[1] = vec_K_P.k[1] - *v17;
  hesse_tri_os.k[2] = v19;
  hesse_tri_os.hesse_val = v20;
  v21 = *(float *)(LODWORD(v67) + 4) - v17[1];
  v22 = *(float *)(LODWORD(v67) + 8) - v17[2];
  vec_K_oppo_tri.k[1] = *(float *)LODWORD(v67) - *v17;
  vec_K_oppo_tri.k[2] = v21;
  vec_K_oppo_tri.hesse_val = v22;
  v23 = &m_cache_K->compact_poly_points[(unsigned __int16)v18];
  v24 = v23->k[1] - v17[1];
  v25 = v23->k[2] - v17[2];
  qr1.checks[1] = v23->k[0] - *v17;
  qr1.checks[2] = v24;
  qr1.scale = v25;
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Point *)&hesse_oppo_tri_os.k[1],
    v1: (IVP_U_Point *)&p_ks.k[1],
    v2: (IVP_U_Point *)&vec_K_oppo_tri.k[1]);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Point *)&vec_K_tri.k[1],
    v1: (const IVP_U_Float_Point *)&qr1.checks[1],
    v2: (IVP_U_Point *)&p_ks.k[1]);
  compact_ledge = m_cache_K->compact_ledge;
  *(float *)&e = (float)((float)(hesse_tri_os.k[1] * hesse_oppo_tri_os.k[1])
                       + (float)(hesse_oppo_tri_os.k[2] * hesse_tri_os.k[2]))
               + (float)(hesse_oppo_tri_os.hesse_val * hesse_tri_os.hesse_val);
  v67 = (float)((float)(vec_K_tri.k[1] * hesse_tri_os.k[1]) + (float)(vec_K_tri.k[2] * hesse_tri_os.k[2]))
      + (float)(vec_K_tri.hesse_val * hesse_tri_os.hesse_val);
  IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
    c_ledge: compact_ledge,
    tri: (int)K,
    p_object: (IVP_U_Point *)&vec_K_P.k[1],
    result: (IVP_Unscaled_QR_Result *)&kkin.cross_KL_Los.k[1]);
  IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
    c_ledge: m_cache_K->compact_ledge,
    tri: (int)&K[(2 * *(_DWORD *)K) >> 17],
    p_object: (IVP_U_Point *)&vec_K_P.k[1],
    result: (IVP_Unscaled_QR_Result *)&qr0.checks[1]);
  if ( kkin.cross_KL_Los.k[1] <= 0.0 )
  {
    if ( qr0.checks[1] > 0.0 )
      return IVP_Mindist_Minimize_Solver::p_minimize_PF(
               this: v70,
               a2: &iqK_len,
               P,
               F: &K[(2 * *(_DWORD *)K) >> 17],
               m_cache_P,
               m_cache_F: m_cache_K);
    if ( *(float *)&e >= 0.0 || v67 >= 0.0 )
    {
      IVP_U_Float_Point::calc_cross_product(
        this: (IVP_U_Float_Point *)v62,
        v1: (IVP_U_Point *)&p_ks.k[1],
        v2: (IVP_U_Point *)&hesse_tri_os.k[1]);
      v67 = p_ks.k[1] * p_ks.k[1];
      quad = (float)((float)((float)(v62[1] * v62[1]) + (float)(v62[0] * v62[0])) + (float)(angle * angle))
           * (float)(1.0
                   / (float)((float)((float)(p_ks.k[1] * p_ks.k[1]) + (float)(p_ks.k[2] * p_ks.k[2]))
                           + (float)(p_ks.hesse_val * p_ks.hesse_val)));
      v68 = 1.0
          / (float)((float)((float)(p_ks.k[1] * p_ks.k[1]) + (float)(p_ks.k[2] * p_ks.k[2]))
                  + (float)(p_ks.hesse_val * p_ks.hesse_val));
      inv_len = quad;
      if ( quad <= 1.0e-10 )
      {
        LODWORD(v70->mindist->len_numerator) = LODWORD(v70->mindist->sum_extra_radius) ^ _mask__NegFloat_;
        IVP_U_Point::calc_an_orthogonal(this: (IVP_U_Point *)v65, ip: (IVP_U_Point *)&p_ks.k[1]);
        IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)v65);
        mindist = v70->mindist;
        v37 = *(float *)&v65[1];
        v38 = e;
        LODWORD(mindist->contact_plane.k[0]) = v65[0];
        mindist->contact_plane.k[1] = v37;
        LODWORD(mindist->contact_plane.k[2]) = v38;
      }
      else
      {
        v31 = IVP_Inline_Math::isqrt_float(quad);
        v67 = v31;
        v70->mindist->len_numerator = v31 * inv_len - v70->mindist->sum_extra_radius;
        IVP_U_Float_Point::calc_cross_product(
          this: (IVP_U_Float_Point *)v62,
          v1: (IVP_U_Point *)&p_ks.k[1],
          v2: (const IVP_U_Float_Point *)v62);
        IVP_Cache_Object::transform_vector_to_world_coords(
          this: m_cache_K->clp_cache_object,
          P_object: (const IVP_U_Float_Point *)v62,
          P_world_out: (IVP_U_Float_Point *)v62);
        LODWORD(v32) = COERCE_UNSIGNED_INT(v67 * v68) ^ _mask__NegFloat_;
        v33 = v70->mindist;
        v34 = v62[1] * v32;
        v35 = angle * v32;
        v33->contact_plane.k[0] = v32 * v62[0];
        v33->contact_plane.k[1] = v34;
        v33->contact_plane.k[2] = v35;
      }
      v70->mindist->contact_dot_diff_center = (float)((float)(v70->mindist->contact_plane.k[1]
                                                            * (float)(m_cache_P->clp_cache_object->core_pos.k[1]
                                                                    - m_cache_K->clp_cache_object->core_pos.k[1]))
                                                    + (float)(v70->mindist->contact_plane.k[0]
                                                            * (float)(m_cache_P->clp_cache_object->core_pos.k[0]
                                                                    - m_cache_K->clp_cache_object->core_pos.k[0])))
                                            + (float)(v70->mindist->contact_plane.k[2]
                                                    * (float)(m_cache_P->clp_cache_object->core_pos.k[2]
                                                            - m_cache_K->clp_cache_object->core_pos.k[2]));
      IVP_Cache_Object::transform_vector_to_object_coords(
        this: m_cache_P->clp_cache_object,
        P_world: (const IVP_U_Float_Point *)v62,
        P_object_out: (IVP_U_Float_Point *)v62);
      v39 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)P];
      LODWORD(v40) = (char *)P + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)P & 0xC));
      v41 = (const IVP_Compact_Edge *)(LODWORD(v40)
                                     + 4 * ((2 * *(_DWORD *)LODWORD(v40)) >> 17)
                                     + *(int *)((char *)IVP_Compact_Edge::prev_table
                                              + ((LOBYTE(v40)
                                                + 4 * (unsigned __int8)((2 * *(_DWORD *)LODWORD(v40)) >> 17))
                                               & 0xC)));
      v68 = 0.0;
      inv_len = inv_len * 0.000001;
      v67 = v40;
      for ( i = v41; ; v41 = i )
      {
        v42 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)v41];
        v43 = v42->k[0] - v39->k[0];
        v44 = v42->k[1] - v39->k[1];
        v45 = v42->k[2] - v39->k[2];
        v61 = (float)((float)(v44 * v62[1]) + (float)(v43 * v62[0])) + (float)(v45 * angle);
        if ( v61 > 0.0 )
        {
          v46 = IVP_Inline_Math::isqrt_float(quad: (float)((float)(v44 * v44) + (float)(v43 * v43)) + (float)(v45 * v45));
          v47 = v46 * v61;
          v40 = v67;
          v61 = v47;
          if ( v47 > inv_len )
          {
            inv_len = v61;
            v68 = *(float *)&i;
          }
        }
        if ( i == (const IVP_Compact_Edge *)LODWORD(v40) )
          break;
        v48 = &i[(2 * *(_DWORD *)i) >> 17];
        i = (const IVP_Compact_Edge *)((char *)v48
                                     + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)v48 & 0xC)));
      }
      if ( v68 == 0.0
        || inv_len < 0.003
        && ((IVP_KK_Input::IVP_KK_Input(
               this: (IVP_KK_Input *)v51,
               K_in: K,
               L_in: (const IVP_Compact_Edge *)LODWORD(v68),
               m_cache_K,
               m_cache_L: m_cache_P),
             IVP_Compact_Ledge_Solver::calc_unscaled_KK_vals(
               a1: (int)&iqK_len,
               in: (const IVP_KK_Input *)v51,
               result: (IVP_Unscaled_KK_Result *)v65) == 0)
         || *(float *)&e < 0.0) )
      {
        v49.synapse = (IVP_Synapse_Real *)m_cache_P->tmp;
        v49.synapse->edge = P;
        v49.synapse->status = 0;
        v50.synapse = (IVP_Synapse_Real *)m_cache_K->tmp;
        v50.synapse->edge = K;
        v50.synapse->status = 1;
        return IVP_MRC_OK;
      }
      else
      {
        return IVP_Mindist_Minimize_Solver::p_minimize_KK(
                 this: v70,
                 a2: &iqK_len,
                 K: (const IVP_Compact_Edge *)LODWORD(v68),
                 L: K,
                 m_cache_K: m_cache_P,
                 m_cache_L: m_cache_K);
      }
    }
    else
    {
      v27.synapse = (IVP_Synapse_Real *)m_cache_P->tmp;
      v27.synapse->edge = P;
      v27.synapse->status = 0;
      v28.synapse = (IVP_Synapse_Real *)m_cache_K->tmp;
      v29 = v70;
      v28.synapse->edge = K;
      v28.synapse->status = 5;
      v29->pos_opposite_BacksideOs.k[0] = vec_K_P.k[1];
      v29->pos_opposite_BacksideOs.k[1] = vec_K_P.k[2];
      v29->pos_opposite_BacksideOs.k[2] = vec_K_P.hesse_val;
      return IVP_MRC_BACKSIDE;
    }
  }
  else
  {
    if ( qr0.checks[1] > 0.0 && v67 > 0.0 )
      return IVP_Mindist_Minimize_Solver::p_minimize_PF(
               this: v70,
               a2: &iqK_len,
               P,
               F: &K[(2 * *(_DWORD *)K) >> 17],
               m_cache_P,
               m_cache_F: m_cache_K);
    return IVP_Mindist_Minimize_Solver::p_minimize_PF(this: v70, a2: &iqK_len, P, F: K, m_cache_P, m_cache_F: m_cache_K);
  }
}
