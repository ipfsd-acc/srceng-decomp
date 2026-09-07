// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_compact_ledge_solver.cxx
// Functions: 19
// ============================================================

#include "ivp\ivp_collision\ivp_compact_ledge_solver.h"

//------------------------------------------------------------------------------
// Address: 0x10078C00
// Name: public: static void IVP_Compact_Ledge_Solver::calc_bounding_box(class IVP_Compact_Ledge const __near *,class IVP_U_Point __near *,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::calc_bounding_box(
        const IVP_Compact_Ledge *c_ledge_in,
        IVP_U_Point *min_extents_out,
        IVP_U_Point *max_extents_out)
{
  $D94D6EC998D8AC7437E59ECF9B271F0E *v4; // esi
  int c_point_offset; // edi
  int v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  int v13; // eax
  float v14; // xmm3_4
  float v15; // xmm3_4
  float v16; // xmm3_4
  int v17; // ecx
  int v18; // eax
  char *v19; // ecx
  int v20; // eax
  float v21; // xmm3_4
  float v22; // xmm3_4
  float v23; // xmm3_4
  int v24; // eax
  float v25; // xmm3_4
  float v26; // xmm3_4
  float v27; // xmm3_4
  int tri_cnt; // [esp+10h] [ebp+8h]

  v4 = &c_ledge_in[1].___u1;
  c_point_offset = c_ledge_in->c_point_offset;
  v6 = c_ledge_in->c_point_offset + 16 * (unsigned __int16)c_ledge_in[1].ledgetree_node_offset;
  v7 = *(float *)((char *)&c_ledge_in->c_point_offset + v6);
  v8 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v6);
  v9 = *(float *)((char *)c_ledge_in + v6 + 8);
  v10 = v7;
  v11 = v8;
  v12 = v9;
  for ( tri_cnt = c_ledge_in->n_triangles - 1; tri_cnt >= 0; --tri_cnt )
  {
    v13 = c_point_offset + 16 * (unsigned __int16)v4->ledgetree_node_offset;
    v14 = *(float *)((char *)&c_ledge_in->c_point_offset + v13);
    if ( v10 <= v14 )
    {
      if ( v14 > v7 )
        v7 = *(float *)((char *)&c_ledge_in->c_point_offset + v13);
    }
    else
    {
      v10 = *(float *)((char *)&c_ledge_in->c_point_offset + v13);
    }
    v15 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v13);
    if ( v11 <= v15 )
    {
      if ( v15 > v8 )
        v8 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v13);
    }
    else
    {
      v11 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v13);
    }
    v16 = *(float *)((char *)c_ledge_in + v13 + 8);
    if ( v12 <= v16 )
    {
      if ( v16 > v9 )
        v9 = *(float *)((char *)c_ledge_in + v13 + 8);
    }
    else
    {
      v12 = *(float *)((char *)c_ledge_in + v13 + 8);
    }
    v17 = *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v4 & 0xC));
    v18 = *(int *)((char *)&v4->ledgetree_node_offset + v17);
    v19 = (char *)v4 + v17;
    v20 = c_point_offset + 16 * (unsigned __int16)v18;
    v21 = *(float *)((char *)&c_ledge_in->c_point_offset + v20);
    if ( v10 <= v21 )
    {
      if ( v21 > v7 )
        v7 = *(float *)((char *)&c_ledge_in->c_point_offset + v20);
    }
    else
    {
      v10 = *(float *)((char *)&c_ledge_in->c_point_offset + v20);
    }
    v22 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v20);
    if ( v11 <= v22 )
    {
      if ( v22 > v8 )
        v8 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v20);
    }
    else
    {
      v11 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v20);
    }
    v23 = *(float *)((char *)c_ledge_in + v20 + 8);
    if ( v12 <= v23 )
    {
      if ( v23 > v9 )
        v9 = *(float *)((char *)c_ledge_in + v20 + 8);
    }
    else
    {
      v12 = *(float *)((char *)c_ledge_in + v20 + 8);
    }
    v24 = c_point_offset
        + 16
        * (unsigned __int16)*(_DWORD *)&v19[*(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v19 & 0xC))];
    v25 = *(float *)((char *)&c_ledge_in->c_point_offset + v24);
    if ( v10 <= v25 )
    {
      if ( v25 > v7 )
        v7 = *(float *)((char *)&c_ledge_in->c_point_offset + v24);
    }
    else
    {
      v10 = *(float *)((char *)&c_ledge_in->c_point_offset + v24);
    }
    v26 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v24);
    if ( v11 <= v26 )
    {
      if ( v26 > v8 )
        v8 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v24);
    }
    else
    {
      v11 = *(float *)((char *)&c_ledge_in->ledgetree_node_offset + v24);
    }
    v27 = *(float *)((char *)c_ledge_in + v24 + 8);
    if ( v12 <= v27 )
    {
      if ( v27 > v9 )
        v9 = *(float *)((char *)c_ledge_in + v24 + 8);
    }
    else
    {
      v12 = *(float *)((char *)c_ledge_in + v24 + 8);
    }
    v4 += 4;
  }
  min_extents_out->k[0] = v10;
  min_extents_out->k[1] = v11;
  min_extents_out->k[2] = v12;
  max_extents_out->k[0] = v7;
  max_extents_out->k[1] = v8;
  max_extents_out->k[2] = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10078D90
// Name: public: static void IVP_Compact_Ledge_Solver::calc_pos_other_space(class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::calc_pos_other_space(
        const IVP_Compact_Edge *P,
        IVP_Cache_Ledge_Point *m_cache_P,
        IVP_Cache_Ledge_Point *m_cache_other_space,
        IVP_U_Point *res)
{
  const IVP_Compact_Poly_Point *v4; // ecx
  float *k; // eax
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4

  v4 = &m_cache_P->compact_poly_points[(unsigned __int16)*(_DWORD *)P];
  k = m_cache_P->clp_cache_object->core_pos.k;
  v6 = v4->k[1];
  v7 = (float)(k[17] * v6) + (float)(k[16] * v4->k[0]);
  v8 = (float)(k[9] * v6) + (float)(v4->k[0] * k[8]);
  v9 = k[13] * v6;
  v10 = v4->k[2];
  v11 = (float)(k[10] * v10) + v8;
  v12 = k[20];
  v13 = (float)((float)(k[14] * v10) + (float)(v9 + (float)(k[12] * v4->k[0]))) + k[21];
  v14 = (float)((float)(k[18] * v10) + v7) + k[22];
  v15 = m_cache_other_space->clp_cache_object->core_pos.k;
  v16 = v13 - v15[21];
  v17 = (float)(v12 + v11) - v15[20];
  v18 = v14 - v15[22];
  res->k[0] = (float)((float)(v15[12] * v16) + (float)(v15[8] * v17)) + (float)(v15[16] * v18);
  res->k[1] = (float)((float)(v15[13] * v16) + (float)(v15[9] * v17)) + (float)(v15[17] * v18);
  res->k[2] = (float)((float)(v15[14] * v16) + (float)(v15[10] * v17)) + (float)(v15[18] * v18);
}

//------------------------------------------------------------------------------
// Address: 0x10078ED0
// Name: public: static void IVP_Compact_Ledge_Solver::transform_pos_other_space(class IVP_U_Float_Point const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::transform_pos_other_space(
        const IVP_U_Float_Point *pos_in_os,
        IVP_Cache_Ledge_Point *m_cache_dir,
        IVP_Cache_Ledge_Point *m_cache_other_space,
        IVP_U_Point *res)
{
  float v4; // xmm2_4
  float v5; // xmm5_4
  float *k; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4

  v4 = pos_in_os->k[1];
  v5 = pos_in_os->k[2];
  k = m_cache_dir->clp_cache_object->core_pos.k;
  v7 = (float)(k[9] * v4) + (float)(pos_in_os->k[0] * k[8]);
  v8 = (float)(k[13] * v4) + (float)(k[12] * pos_in_os->k[0]);
  v9 = k[17] * v4;
  v10 = k[20];
  v11 = (float)(k[10] * v5) + v7;
  v12 = (float)((float)(k[14] * v5) + v8) + k[21];
  v13 = (float)((float)(k[18] * v5) + (float)(v9 + (float)(k[16] * pos_in_os->k[0]))) + k[22];
  v14 = m_cache_other_space->clp_cache_object->core_pos.k;
  v15 = v12 - v14[21];
  v16 = (float)(v10 + v11) - v14[20];
  v17 = v13 - v14[22];
  res->k[0] = (float)((float)(v14[12] * v15) + (float)(v16 * v14[8])) + (float)(v14[16] * v17);
  res->k[1] = (float)((float)(v14[13] * v15) + (float)(v14[9] * v16)) + (float)(v14[17] * v17);
  res->k[2] = (float)((float)(v14[14] * v15) + (float)(v14[10] * v16)) + (float)(v14[18] * v17);
}

//------------------------------------------------------------------------------
// Address: 0x10079000
// Name: public: static void IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(class IVP_Compact_Ledge const __near *,class IVP_Compact_Edge const __near *,class IVP_U_Point const __near *,class IVP_Unscaled_S_Result __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(
        const IVP_Compact_Ledge *c_ledge,
        const IVP_Compact_Edge *edge,
        const IVP_U_Point *p_object,
        IVP_Unscaled_S_Result *result)
{
  int v4; // eax
  float v5; // xmm0_4
  float v6; // xmm4_4
  float v7; // xmm6_4
  int v8; // ecx
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  float v15; // xmm3_4
  float v16; // [esp-8h] [ebp-38h]
  float v17; // [esp+20h] [ebp-10h]

  v4 = c_ledge->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)edge;
  v5 = *(float *)((char *)&c_ledge->c_point_offset + v4);
  v6 = *(float *)((char *)&c_ledge->ledgetree_node_offset + v4);
  v7 = *(float *)((char *)c_ledge + v4 + 8);
  v8 = c_ledge->c_point_offset
     + 16
     * (unsigned __int16)*(_DWORD *)((char *)edge
                                   + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)edge & 0xC)));
  v9 = *(float *)((char *)&c_ledge->c_point_offset + v8);
  v10 = v9 - p_object->k[0];
  v11 = v9 - v5;
  v12 = *(float *)((char *)&c_ledge->ledgetree_node_offset + v8);
  v13 = v12 - p_object->k[1];
  v14 = v12 - v6;
  v17 = *(float *)((char *)c_ledge + v8 + 8);
  v16 = v13;
  v15 = v17 - p_object->k[2];
  result->checks[0] = COERCE_FLOAT(
                        COERCE_UNSIGNED_INT(
                          (float)((float)((float)(v5 - p_object->k[0]) * v11)
                                + (float)((float)(v6 - p_object->k[1]) * v14))
                        + (float)((float)(v7 - p_object->k[2]) * (float)(v17 - v7)))
                      ^ _mask__NegFloat_)
                    + 1.1754944e-38;
  result->checks[1] = (float)((float)((float)(v10 * v11) + (float)(v16 * v14)) + (float)(v15 * (float)(v17 - v7)))
                    + 1.1754944e-38;
}

//------------------------------------------------------------------------------
// Address: 0x10079110
// Name: public: static void IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(class IVP_Compact_Ledge const __near *,class IVP_Compact_Edge const __near *,class IVP_U_Point const __near *,class IVP_Unscaled_QR_Result __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
        const IVP_Compact_Ledge *c_ledge,
        int tri,
        const IVP_U_Point *p_object,
        IVP_Unscaled_QR_Result *result)
{
  int v4; // ecx
  float *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  int v9; // esi
  float *v10; // edx
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // [esp-8h] [ebp-38h]
  float v21; // [esp-4h] [ebp-34h]
  float R_8; // [esp+8h] [ebp-28h]
  float R_12; // [esp+Ch] [ebp-24h]
  float Pvec_12; // [esp+1Ch] [ebp-14h]
  float v25; // [esp+20h] [ebp-10h]

  v4 = c_ledge->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)((tri & 0xFFFFFFF0) + 4);
  v5 = (float *)((char *)&c_ledge[(unsigned __int16)*(_DWORD *)((tri & 0xFFFFFFF0) + 8)].c_point_offset
               + c_ledge->c_point_offset);
  v6 = *(float *)((char *)&c_ledge->c_point_offset + v4) - *v5;
  v7 = *(float *)((char *)&c_ledge->ledgetree_node_offset + v4) - v5[1];
  v8 = *(float *)((char *)c_ledge + v4 + 8) - v5[2];
  v9 = (tri >> 2) & 3;
  v10 = (float *)((char *)&c_ledge[(unsigned __int16)*(_DWORD *)((tri & 0xFFFFFFF0) + 0xC)].c_point_offset
                + c_ledge->c_point_offset);
  v11 = *v10 - *v5;
  v12 = v10[1] - v5[1];
  Pvec_12 = (float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8);
  v21 = v10[2] - v5[2];
  v13 = p_object->k[0] - *v5;
  v25 = (float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v21 * v21);
  R_8 = p_object->k[1] - v5[1];
  v20 = v12;
  R_12 = p_object->k[2] - v5[2];
  v14 = (float)((float)(v11 * v6) + (float)(v12 * v7)) + (float)(v21 * v8);
  v15 = (float)(v25 * Pvec_12) - (float)(v14 * v14);
  v16 = (float)((float)(v13 * v6) + (float)(R_8 * v7)) + (float)(R_12 * v8);
  result->scale = v15;
  v17 = (float)((float)(v13 * v11) + (float)(R_8 * v20)) + (float)(R_12 * v21);
  v18 = (float)(v17 * Pvec_12) - (float)(v16 * v14);
  *(float *)((char *)result->checks + *((char *)&vec2_invalid_61.y + v9 + 3)) = v18 + 1.1754944e-38;
  v19 = (float)(v16 * v25) - (float)(v17 * v14);
  *(float *)((char *)result->checks + ivp_uqr_mod_table[v9]) = (float)((float)(v15 - v19) - v18) + 1.1754944e-38;
  *(float *)((char *)result->checks + ivp_uqr_mod_table[v9 + 1]) = v19 + 1.1754944e-38;
}

//------------------------------------------------------------------------------
// Address: 0x10079310
// Name: public: IVP_KK_Input::IVP_KK_Input(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_KK_Input *__thiscall IVP_KK_Input::IVP_KK_Input(
        IVP_KK_Input *this,
        const IVP_Compact_Edge *K_in,
        const IVP_Compact_Edge *L_in,
        IVP_Cache_Ledge_Point *m_cache_K,
        IVP_Cache_Ledge_Point *m_cache_L)
{
  const IVP_Compact_Poly_Point *compact_poly_points; // edi
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float *k; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float *v16; // eax
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  int v22; // ecx
  float v23; // xmm0_4
  const IVP_Compact_Poly_Point *v24; // ecx
  float *v25; // eax
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float *v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float *v38; // edx
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  const IVP_Compact_Poly_Point *v46; // edx
  const IVP_U_Float_Point *v47; // eax
  int v48; // ecx
  float v49; // xmm0_4
  const IVP_U_Float_Point *v50; // ecx
  float v51; // xmm1_4
  _DWORD *v53; // [esp+8h] [ebp-8h]
  float v54; // [esp+Ch] [ebp-4h]
  IVP_Cache_Ledge_Point *m_cache_Ka; // [esp+20h] [ebp+10h]

  this->L = L_in;
  this->K = K_in;
  compact_poly_points = m_cache_K->compact_poly_points;
  v53 = (int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K_in & 0xC));
  v7 = compact_poly_points[(unsigned __int16)*(_DWORD *)((char *)K_in + *v53)].k[0]
     - compact_poly_points[(unsigned __int16)*(_DWORD *)K_in].k[0];
  v8 = compact_poly_points[(unsigned __int16)*(_DWORD *)((char *)K_in + *v53)].k[1]
     - compact_poly_points[(unsigned __int16)*(_DWORD *)K_in].k[1];
  v9 = compact_poly_points[(unsigned __int16)*(_DWORD *)((char *)K_in + *v53)].k[2]
     - compact_poly_points[(unsigned __int16)*(_DWORD *)K_in].k[2];
  k = m_cache_K->clp_cache_object->core_pos.k;
  v12 = (float)((float)(k[9] * v8) + (float)(v7 * k[8])) + (float)(k[10] * v9);
  v13 = (float)((float)(k[12] * v7) + (float)(k[13] * v8)) + (float)(k[14] * v9);
  v14 = (float)(k[16] * v7) + (float)(k[17] * v8);
  v15 = k[18];
  v16 = m_cache_L->clp_cache_object->core_pos.k;
  v17 = v14 + (float)(v15 * v9);
  v54 = v16[18];
  v18 = (float)((float)(v16[12] * v13) + (float)(v12 * v16[8])) + (float)(v16[16] * v17);
  v19 = (float)((float)(v16[9] * v12) + (float)(v16[13] * v13)) + (float)(v16[17] * v17);
  v20 = v16[10] * v12;
  v21 = v16[14];
  this->Kvec_Los.k[0] = v18;
  this->Kvec_Los.k[1] = v19;
  this->Kvec_Los.k[2] = (float)(v20 + (float)(v21 * v13)) + (float)(v54 * v17);
  this->cache_L = m_cache_L;
  this->cache_K = m_cache_K;
  v22 = (unsigned __int16)*(_DWORD *)K_in;
  v23 = m_cache_K->compact_poly_points[v22].k[0];
  v24 = &m_cache_K->compact_poly_points[v22];
  m_cache_Ka = (IVP_Cache_Ledge_Point *)m_cache_K->compact_poly_points;
  v25 = m_cache_K->clp_cache_object->core_pos.k;
  v26 = v25[12] * v23;
  v27 = v25[16] * v23;
  v28 = v25[8] * v23;
  v29 = v24->k[1];
  v30 = (float)(v25[9] * v29) + v28;
  v31 = (float)(v25[13] * v29) + v26;
  v32 = (float)(v25[17] * v29) + v27;
  v33 = v24->k[2];
  v34 = m_cache_L->clp_cache_object->core_pos.k;
  v35 = (float)((float)((float)(v25[10] * v33) + v30) + v25[20]) - v34[20];
  v36 = (float)((float)((float)(v25[14] * v33) + v31) + v25[21]) - v34[21];
  v37 = (float)((float)((float)(v25[18] * v33) + v32) + v25[22]) - v34[22];
  this->K_Los[0].k[0] = (float)((float)(v34[12] * v36) + (float)(v35 * v34[8])) + (float)(v34[16] * v37);
  this->K_Los[0].k[1] = (float)((float)(v34[13] * v36) + (float)(v34[9] * v35)) + (float)(v34[17] * v37);
  this->K_Los[0].k[2] = (float)((float)(v34[14] * v36) + (float)(v34[10] * v35)) + (float)(v34[18] * v37);
  v38 = (float *)((char *)m_cache_Ka + 16 * (unsigned __int16)*(_DWORD *)((char *)K_in + *v53));
  v39 = v38[1];
  v40 = (float)(v25[13] * v39) + (float)(v25[12] * *v38);
  v41 = v25[17] * v39;
  v42 = v38[2];
  v43 = (float)((float)((float)(v25[10] * v42) + (float)((float)(v25[9] * v39) + (float)(*v38 * v25[8]))) + v25[20])
      - v34[20];
  v44 = (float)((float)((float)(v25[14] * v42) + v40) + v25[21]) - v34[21];
  v45 = (float)((float)((float)(v25[18] * v42) + (float)(v41 + (float)(v25[16] * *v38))) + v25[22]) - v34[22];
  v46 = m_cache_L->compact_poly_points;
  this->K_Los[1].k[0] = (float)((float)(v34[12] * v44) + (float)(v43 * v34[8])) + (float)(v34[16] * v45);
  this->K_Los[1].k[1] = (float)((float)(v34[13] * v44) + (float)(v34[9] * v43)) + (float)(v34[17] * v45);
  this->K_Los[1].k[2] = (float)((float)(v34[14] * v44) + (float)(v34[10] * v43)) + (float)(v34[18] * v45);
  v47 = &v46[(unsigned __int16)*(_DWORD *)L_in];
  v48 = (unsigned __int16)*(_DWORD *)((char *)L_in
                                    + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)L_in & 0xC)));
  v49 = v46[v48].k[1] - v47->k[1];
  v50 = &v46[v48];
  this->L_Los[0] = v47;
  this->L_Los[1] = v50;
  v51 = v50->k[2] - v47->k[2];
  this->Lvec_Los.k[0] = v50->k[0] - v47->k[0];
  this->Lvec_Los.k[1] = v49;
  this->Lvec_Los.k[2] = v51;
  IVP_U_Float_Point::calc_cross_product(this: &this->cross_KL_Los, v1: &this->Kvec_Los, v2: &this->Lvec_Los);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10079740
// Name: public: static void IVP_Compact_Ledge_Solver::calc_hesse_object(class IVP_Compact_Edge const __near *,class IVP_Compact_Ledge const __near *,class IVP_U_Hesse __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::calc_hesse_object(
        const IVP_Compact_Edge *edge,
        const IVP_Compact_Ledge *ledge,
        IVP_U_Hesse *hesse_out_os)
{
  IVP_U_Hesse::calc_hesse(
    this: hesse_out_os,
    tp0: (const IVP_U_Float_Point *)((char *)&ledge[(unsigned __int16)*(_DWORD *)edge] + ledge->c_point_offset),
    tp1: (const IVP_U_Float_Point *)((char *)&ledge[(unsigned __int16)*(_DWORD *)((char *)edge
                                                                           + *(int *)((char *)IVP_Compact_Edge::prev_table
                                                                                    + ((unsigned __int8)edge & 0xC)))]
                              + ledge->c_point_offset),
    tp2: (const IVP_U_Float_Point *)((char *)&ledge[(unsigned __int16)*(_DWORD *)((char *)edge
                                                                           + *(int *)((char *)IVP_Compact_Edge::next_table
                                                                                    + ((unsigned __int8)edge & 0xC)))]
                              + ledge->c_point_offset));
  IVP_U_Hesse::normize(this: (IVP_U_Float_Hesse *)hesse_out_os);
}

//------------------------------------------------------------------------------
// Address: 0x100797B0
// Name: public: static void IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(class IVP_Compact_Edge const __near *,class IVP_Compact_Ledge const __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
        const IVP_Compact_Edge *edge,
        const IVP_Compact_Ledge *ledge,
        IVP_U_Float_Point *out_vec)
{
  int v3; // ebx
  float *v4; // eax
  int v5; // ecx
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // edx
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4

  v3 = (unsigned __int8)edge & 0xC;
  v4 = (float *)((char *)&ledge[(unsigned __int16)*(_DWORD *)edge].c_point_offset + ledge->c_point_offset);
  v5 = ledge->c_point_offset
     + 16 * (unsigned __int16)*(_DWORD *)((char *)edge + *(int *)((char *)IVP_Compact_Edge::next_table + v3));
  v6 = *(float *)((char *)&ledge->ledgetree_node_offset + v5) - v4[1];
  v7 = *(float *)((char *)ledge + v5 + 8) - v4[2];
  v8 = *(float *)((char *)&ledge->c_point_offset + v5) - *v4;
  v9 = ledge->c_point_offset
     + 16 * (unsigned __int16)*(_DWORD *)((char *)edge + *(int *)((char *)IVP_Compact_Edge::prev_table + v3));
  v10 = *(float *)((char *)&ledge->c_point_offset + v9) - *v4;
  v11 = *(float *)((char *)&ledge->ledgetree_node_offset + v9) - v4[1];
  v12 = *(float *)((char *)ledge + v9 + 8) - v4[2];
  out_vec->k[0] = (float)(v6 * v12) - (float)(v7 * v11);
  out_vec->k[1] = (float)(v7 * v10) - (float)(v8 * v12);
  out_vec->k[2] = (float)(v8 * v11) - (float)(v6 * v10);
}

//------------------------------------------------------------------------------
// Address: 0x10079880
// Name: public: static float IVP_Compact_Ledge_Solver::quad_dist_edge_to_point_K_space(class IVP_Compact_Ledge const __near *,class IVP_Compact_Edge const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IVP_Compact_Ledge_Solver::quad_dist_edge_to_point_K_space(
        const IVP_Compact_Ledge *ledge_K,
        const IVP_Compact_Edge *K,
        const IVP_U_Point *object_pos)
{
  int v3; // ecx
  float v4; // xmm3_4
  int v5; // eax
  float v6; // xmm4_4
  float *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v14; // [esp-8h] [ebp-38h]
  float v15; // [esp+10h] [ebp-20h]
  float v16; // [esp+14h] [ebp-1Ch]
  float v17; // [esp+18h] [ebp-18h]
  float v18; // [esp+1Ch] [ebp-14h]

  v3 = ledge_K->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)K;
  v4 = *(float *)((char *)ledge_K + v3 + 8);
  v5 = ledge_K->c_point_offset
     + 16
     * (unsigned __int16)*(_DWORD *)((char *)K
                                   + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC)));
  v6 = *(float *)((char *)ledge_K + v5 + 8);
  v17 = *(float *)((char *)&ledge_K->c_point_offset + v5);
  v7 = (float *)((char *)&ledge_K->c_point_offset + v5);
  v18 = *(float *)((char *)&ledge_K->c_point_offset + v3);
  v15 = v7[1];
  v16 = *(float *)((char *)&ledge_K->ledgetree_node_offset + v3);
  v8 = object_pos->k[0] - v18;
  v9 = object_pos->k[2] - v4;
  v10 = v6 - v4;
  v11 = object_pos->k[1] - v16;
  v14 = (float)(v9 * (float)(v17 - v18)) - (float)(v8 * v10);
  v12 = (float)(v8 * (float)(v15 - v16)) - (float)(v11 * (float)(v17 - v18));
  return 1.0
       / ((v18 - v17) * (v18 - v17) + (v16 - v15) * (v16 - v15) + (float)(v4 - v7[2]) * (float)(v4 - v7[2]) + 1.0e-18)
       * (v14 * v14
        + (float)((float)(v11 * v10) - (float)(v9 * (float)(v15 - v16)))
        * (float)((float)(v11 * v10) - (float)(v9 * (float)(v15 - v16)))
        + v12 * v12);
}

//------------------------------------------------------------------------------
// Address: 0x100799C0
// Name: public: static float IVP_Compact_Ledge_Solver::calc_qlen_PF_F_space(class IVP_Compact_Ledge const __near *,class IVP_Compact_Triangle const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall IVP_Compact_Ledge_Solver::calc_qlen_PF_F_space@<st0>(
        int a1@<ebp>,
        const IVP_Compact_Ledge *ledge,
        const IVP_Compact_Triangle *tri,
        const IVP_U_Point *object_pos)
{
  IVP_Compact_Edge *c_three_edges; // edi
  int v5; // edx
  int c_point_offset; // ecx
  int v7; // edx
  int v8; // eax
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float *v12; // edx
  int v13; // ecx
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v20; // xmm0_4
  IVP_Compact_Edge *v21; // edi
  int v22; // eax
  int v23; // ecx
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm6_4
  float *v27; // ecx
  float v28; // xmm4_4
  float v29; // xmm2_4
  float v30; // xmm5_4
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  double v36; // st7
  float v37; // [esp-Ch] [ebp-3Ch] BYREF
  float v38; // [esp-8h] [ebp-38h]
  float v39; // [esp-4h] [ebp-34h]
  IVP_U_Point normal; // [esp+0h] [ebp-30h]
  int v41; // [esp+10h] [ebp-20h]
  float qdist; // [esp+14h] [ebp-1Ch]
  float v43; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  float v45; // [esp+20h] [ebp-10h]
  int v46; // [esp+24h] [ebp-Ch]
  void *v47; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  v46 = a1;
  v47 = retaddr;
  c_three_edges = tri->c_three_edges;
  IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
    c_ledge: ledge,
    tri: (int)tri->c_three_edges,
    p_object: object_pos,
    result: (IVP_Unscaled_QR_Result *)&v37);
  if ( (LODWORD(v37) | LODWORD(v38) | LODWORD(v39)) >= 0 )
  {
    v5 = (int)*c_three_edges;
    c_point_offset = ledge->c_point_offset;
    v41 = (unsigned __int8)c_three_edges & 0xC;
    v7 = c_point_offset + 16 * (unsigned __int16)v5;
    v8 = c_point_offset
       + 16
       * (unsigned __int16)*(_DWORD *)((char *)c_three_edges + *(int *)((char *)IVP_Compact_Edge::next_table + v41));
    v9 = *(float *)((char *)&ledge->ledgetree_node_offset + v8) - *(float *)((char *)&ledge->ledgetree_node_offset + v7);
    v10 = *(float *)((char *)ledge + v8 + 8) - *(float *)((char *)ledge + v7 + 8);
    v11 = *(float *)((char *)&ledge->c_point_offset + v8) - *(float *)((char *)&ledge->c_point_offset + v7);
    v12 = (float *)((char *)&ledge->c_point_offset + v7);
    v13 = ledge->c_point_offset
        + 16
        * (unsigned __int16)*(_DWORD *)((char *)c_three_edges + *(int *)((char *)IVP_Compact_Edge::prev_table + v41));
    v14 = *(float *)((char *)&ledge->ledgetree_node_offset + v13) - v12[1];
    v15 = *(float *)((char *)ledge + v13 + 8) - v12[2];
    v16 = *(float *)((char *)&ledge->c_point_offset + v13) - *v12;
    v38 = (float)(v10 * v16) - (float)(v11 * v15);
    v37 = (float)(v9 * v15) - (float)(v10 * v14);
    v17 = (float)(v11 * v14) - (float)(v9 * v16);
    v18 = object_pos->k[1];
    v39 = v17;
    *(float *)&v41 = (float)((float)((float)(v18 * v38) + (float)(v37 * object_pos->k[0]))
                           + (float)(object_pos->k[2] * v17))
                   - (float)((float)((float)(v12[1] * v38) + (float)(*v12 * v37)) + (float)(v12[2] * v17));
    return 1.0 / (v38 * v38 + v37 * v37 + v39 * v39) * (*(float *)&v41 * *(float *)&v41);
  }
  v45 = 1.0e20;
  i = SLODWORD(object_pos->k[0]);
  v43 = object_pos->k[1];
  v20 = object_pos->k[2];
  v41 = 2;
  qdist = v20;
  v21 = &tri->c_three_edges[2];
  do
  {
    v22 = ledge->c_point_offset
        + 16
        * (unsigned __int16)*(_DWORD *)((char *)v21
                                      + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v21 & 0xC)));
    v23 = ledge->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)v21;
    v24 = *(float *)((char *)&ledge->c_point_offset + v23);
    v25 = *(float *)((char *)&ledge->ledgetree_node_offset + v23);
    v26 = *(float *)((char *)ledge + v23 + 8);
    v27 = (float *)((char *)&ledge->c_point_offset + v23);
    v28 = *(float *)((char *)&ledge->c_point_offset + v22);
    v29 = v28 - *(float *)&i;
    v30 = *(float *)((char *)&ledge->ledgetree_node_offset + v22);
    v31 = v30 - v43;
    v32 = v30 - v25;
    v33 = v28 - v24;
    normal.hesse_val = *(float *)((char *)ledge + v22 + 8);
    v34 = (float)((float)((float)(v31 * v32) + (float)(v29 * v33))
                + (float)((float)(normal.hesse_val - qdist) * (float)(normal.hesse_val - v26)))
        + 1.1754944e-38;
    v39 = normal.hesse_val - v26;
    if ( (float)(COERCE_FLOAT(
                   COERCE_UNSIGNED_INT(
                     (float)((float)((float)(v25 - v43) * v32) + (float)((float)(v24 - *(float *)&i) * v33))
                   + (float)((float)(v26 - qdist) * (float)(normal.hesse_val - v26)))
                 ^ _mask__NegFloat_)
               + 1.1754944e-38) < 0.0 )
    {
      v35 = (float)((float)((float)(*(float *)&i - *v27) * (float)(*(float *)&i - *v27))
                  + (float)((float)(v43 - v27[1]) * (float)(v43 - v27[1])))
          + (float)((float)(qdist - v27[2]) * (float)(qdist - v27[2]));
      if ( v45 <= v35 )
        goto LABEL_11;
      goto LABEL_10;
    }
    if ( v34 >= 0.0 )
    {
      v36 = IVP_Compact_Ledge_Solver::quad_dist_edge_to_point_K_space(ledge_K: ledge, K: v21, object_pos);
      normal.k[2] = v36;
      if ( v45 > v36 )
      {
        v35 = normal.k[2];
LABEL_10:
        v45 = v35;
      }
    }
LABEL_11:
    --v21;
    --v41;
  }
  while ( v41 >= 0 );
  return v45;
}

//------------------------------------------------------------------------------
// Address: 0x10079CE0
// Name: public: static float IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(class IVP_U_Point const __near *,class IVP_Compact_Ledge const __near *,class IVP_Compact_Edge const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(
        const IVP_U_Point *P_in_K_space,
        const IVP_Compact_Ledge *K_ledge,
        const IVP_Compact_Edge *K)
{
  int v3; // eax
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm4_4
  int v7; // ecx
  float v8; // xmm7_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float *v11; // ecx
  float *v12; // eax
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm0_4
  double v17; // st7
  double v18; // st7
  double v19; // st6
  double v20; // st5
  float v21; // [esp-20h] [ebp-34h]
  float v22; // [esp-8h] [ebp-1Ch]
  float sr; // [esp+0h] [ebp-14h]

  v3 = K_ledge->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)K;
  v4 = *(float *)((char *)K_ledge + v3 + 8);
  v5 = *(float *)((char *)&K_ledge->c_point_offset + v3);
  v6 = *(float *)((char *)&K_ledge->ledgetree_node_offset + v3);
  v7 = 16
     * (unsigned __int16)*(_DWORD *)((char *)K
                                   + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)K & 0xC)))
     + K_ledge->c_point_offset;
  v8 = *(float *)((char *)K_ledge + v7 + 8);
  v9 = *(float *)((char *)&K_ledge->c_point_offset + v7);
  v10 = *(float *)((char *)&K_ledge->ledgetree_node_offset + v7);
  v11 = (float *)((char *)&K_ledge->c_point_offset + v7);
  v12 = (float *)((char *)&K_ledge->c_point_offset + v3);
  v22 = v8;
  v13 = v9 - v5;
  v21 = v8 - v4;
  sr = P_in_K_space->k[1];
  v14 = P_in_K_space->k[2];
  v15 = COERCE_FLOAT(
          COERCE_UNSIGNED_INT(
            (float)((float)((float)(v5 - P_in_K_space->k[0]) * (float)(v9 - v5))
                  + (float)((float)(v6 - sr) * (float)(v10 - v6)))
          + (float)((float)(v4 - v14) * v21))
        ^ _mask__NegFloat_)
      + 1.1754944e-38;
  if ( ((LODWORD(v15)
       | COERCE_UNSIGNED_INT(
           (float)((float)((float)((float)(v10 - sr) * (float)(v10 - v6))
                         + (float)((float)(v9 - P_in_K_space->k[0]) * v13))
                 + (float)((float)(v22 - v14) * v21))
         + 1.1754944e-38))
      & 0x80000000) == 0 )
    return IVP_Compact_Ledge_Solver::quad_dist_edge_to_point_K_space(ledge_K: K_ledge, K, object_pos: P_in_K_space);
  v17 = P_in_K_space->k[0];
  if ( v15 >= 0.0 )
  {
    v18 = v17 - *v11;
    v19 = sr - v11[1];
    v20 = v14 - v11[2];
  }
  else
  {
    v18 = v17 - *v12;
    v19 = sr - v12[1];
    v20 = v14 - v12[2];
  }
  return v18 * v18 + v19 * v19 + v20 * v20;
}

//------------------------------------------------------------------------------
// Address: 0x10079E60
// Name: public: static void IVP_Compact_Ledge_Solver::give_world_coords_AT(class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::give_world_coords_AT(
        const IVP_Compact_Edge *edge,
        IVP_Cache_Ledge_Point *clp,
        IVP_U_Point *p_ws_out)
{
  IVP_Cache_Object::transform_position_to_world_coords(
    this: clp->clp_cache_object,
    P_object: &clp->compact_poly_points[(unsigned __int16)*(_DWORD *)edge],
    P_world_out: p_ws_out);
}

//------------------------------------------------------------------------------
// Address: 0x10079E90
// Name: public: static void IVP_Compact_Ledge_Solver::calc_radius_to_given_center(class IVP_Compact_Ledge const __near *,class IVP_U_Point const __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::calc_radius_to_given_center(
        const IVP_Compact_Ledge *ledge,
        const IVP_U_Point *center_in,
        float *radius_out,
        float *radius_dev_out)
{
  float v4; // xmm1_4
  const IVP_Compact_Ledge *v5; // edi
  int c_point_offset; // ecx
  $D94D6EC998D8AC7437E59ECF9B271F0E *v7; // esi
  int v8; // edx
  int v9; // eax
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float *v13; // edx
  int v14; // ecx
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm1_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  int v26; // eax
  float v27; // xmm3_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm4_4
  int v31; // eax
  float v32; // xmm3_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm4_4
  float v38; // xmm6_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  int t; // [esp+4h] [ebp-20h]
  float i_hv_len_squared; // [esp+8h] [ebp-1Ch]
  float v44; // [esp+Ch] [ebp-18h]
  float v45; // [esp+10h] [ebp-14h]
  float v46; // [esp+14h] [ebp-10h]
  int v47; // [esp+18h] [ebp-Ch]
  float dev_max; // [esp+1Ch] [ebp-8h]
  float q_max; // [esp+20h] [ebp-4h]

  v4 = 0.0;
  v5 = ledge;
  q_max = 0.0;
  dev_max = 0.0;
  t = ledge->n_triangles - 1;
  if ( t >= 0 )
  {
    c_point_offset = ledge->c_point_offset;
    v46 = center_in->k[0];
    v45 = center_in->k[1];
    v47 = ledge->c_point_offset;
    v44 = center_in->k[2];
    v7 = &ledge[1].___u1;
    do
    {
      v8 = c_point_offset + 16 * (unsigned __int16)v7->ledgetree_node_offset;
      v9 = c_point_offset
         + 16
         * (unsigned __int16)*(int *)((char *)&v7->ledgetree_node_offset
                                    + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v7 & 0xC)));
      v10 = *(float *)((char *)&v5->ledgetree_node_offset + v9) - *(float *)((char *)&v5->ledgetree_node_offset + v8);
      v11 = *(float *)((char *)v5 + v9 + 8) - *(float *)((char *)v5 + v8 + 8);
      v12 = *(float *)((char *)&v5->c_point_offset + v9) - *(float *)((char *)&v5->c_point_offset + v8);
      v13 = (float *)((char *)&v5->c_point_offset + v8);
      v5 = ledge;
      v14 = v47
          + 16
          * (unsigned __int16)*(int *)((char *)&v7->ledgetree_node_offset
                                     + *(int *)((char *)IVP_Compact_Edge::prev_table + ((unsigned __int8)v7 & 0xC)));
      v15 = *(float *)((char *)&ledge->ledgetree_node_offset + v14) - v13[1];
      v16 = *(float *)((char *)ledge + v14 + 8) - v13[2];
      v17 = *(float *)((char *)&ledge->c_point_offset + v14) - *v13;
      v18 = (float)(v10 * v16) - (float)(v11 * v15);
      v19 = (float)(v11 * v17) - (float)(v12 * v16);
      v20 = v12 * v15;
      v21 = v13[1] - v45;
      v22 = v20 - (float)(v10 * v17);
      v23 = v13[2] - v44;
      i_hv_len_squared = 1.0 / (float)((float)((float)(v18 * v18) + (float)(v19 * v19)) + (float)(v22 * v22));
      v24 = *v13 - v46;
      if ( (float)((float)((float)(v21 * v21) + (float)(v24 * v24)) + (float)(v23 * v23)) > q_max )
        q_max = (float)((float)(v21 * v21) + (float)(v24 * v24)) + (float)(v23 * v23);
      v25 = (float)((float)((float)((float)((float)(v23 * v18) - (float)(v24 * v22))
                                  * (float)((float)(v23 * v18) - (float)(v24 * v22)))
                          + (float)((float)((float)(v21 * v22) - (float)(v23 * v19))
                                  * (float)((float)(v21 * v22) - (float)(v23 * v19))))
                  + (float)((float)((float)(v24 * v19) - (float)(v21 * v18))
                          * (float)((float)(v24 * v19) - (float)(v21 * v18))))
          * i_hv_len_squared;
      if ( v25 > dev_max )
        dev_max = v25;
      c_point_offset = ledge->c_point_offset;
      v26 = v47 + 16 * (unsigned __int16)v7[1].ledgetree_node_offset;
      v27 = *(float *)((char *)&ledge->c_point_offset + v26) - v46;
      v28 = *(float *)((char *)&ledge->ledgetree_node_offset + v26) - v45;
      v29 = *(float *)((char *)ledge + v26 + 8) - v44;
      if ( (float)((float)((float)(v28 * v28) + (float)(v27 * v27)) + (float)(v29 * v29)) > q_max )
        q_max = (float)((float)(v28 * v28) + (float)(v27 * v27)) + (float)(v29 * v29);
      v30 = (float)((float)((float)((float)((float)(v29 * v18) - (float)(v27 * v22))
                                  * (float)((float)(v29 * v18) - (float)(v27 * v22)))
                          + (float)((float)((float)(v28 * v22) - (float)(v29 * v19))
                                  * (float)((float)(v28 * v22) - (float)(v29 * v19))))
                  + (float)((float)((float)(v27 * v19) - (float)(v28 * v18))
                          * (float)((float)(v27 * v19) - (float)(v28 * v18))))
          * i_hv_len_squared;
      if ( v30 > dev_max )
        dev_max = v30;
      v31 = v47 + 16 * (unsigned __int16)v7[2].ledgetree_node_offset;
      v32 = *(float *)((char *)&ledge->c_point_offset + v31) - v46;
      v33 = *(float *)((char *)&ledge->ledgetree_node_offset + v31) - v45;
      v34 = *(float *)((char *)ledge + v31 + 8) - v44;
      if ( (float)((float)((float)(v33 * v33) + (float)(v32 * v32)) + (float)(v34 * v34)) > q_max )
        q_max = (float)((float)(v33 * v33) + (float)(v32 * v32)) + (float)(v34 * v34);
      v35 = (float)(v33 * v22) - (float)(v34 * v19);
      v36 = v32 * v22;
      v4 = dev_max;
      v37 = (float)(v34 * v18) - v36;
      v38 = v35 * v35;
      v39 = (float)((float)(v32 * v19) - (float)(v33 * v18)) * (float)((float)(v32 * v19) - (float)(v33 * v18));
      if ( (float)((float)((float)((float)(v37 * v37) + v38) + v39) * i_hv_len_squared) > dev_max )
      {
        v4 = (float)((float)((float)(v37 * v37) + v38) + v39) * i_hv_len_squared;
        dev_max = v4;
      }
      v7 += 4;
      --t;
    }
    while ( t >= 0 );
  }
  v40 = fsqrt(q_max);
  if ( v40 > *radius_out )
    *radius_out = v40;
  if ( radius_dev_out != nullptr )
  {
    v41 = fsqrt(v4);
    if ( v41 > *radius_dev_out )
      *radius_dev_out = v41;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A1F0
// Name: public: float IVP_KK_Input::calc_quad_distance_edge_edge(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_KK_Input::calc_quad_distance_edge_edge(IVP_KK_Input *this)
{
  float v1; // xmm1_4
  float v3; // [esp+4h] [ebp-4h]

  v1 = this->cross_KL_Los.k[0];
  if ( (float)((float)((float)(v1 * v1) + (float)(this->cross_KL_Los.k[1] * this->cross_KL_Los.k[1]))
             + (float)(this->cross_KL_Los.k[2] * this->cross_KL_Los.k[2])) <= 1.0e-12 )
    return IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(
             P_in_K_space: this->K_Los,
             K_ledge: (const IVP_Compact_Ledge *)(((int)this->L & 0xFFFFFFF0)
                                       - 16 * ((*(_DWORD *)((int)this->L & 0xFFFFFFF0) & 0xFFF) + 1)),
             K: this->L);
  v3 = (float)((float)((float)(this->K_Los[0].k[1] * this->cross_KL_Los.k[1]) + (float)(v1 * this->K_Los[0].k[0]))
             + (float)(this->K_Los[0].k[2] * this->cross_KL_Los.k[2]))
     - (float)((float)((float)(this->L_Los[0]->k[1] * this->cross_KL_Los.k[1]) + (float)(v1 * this->L_Los[0]->k[0]))
             + (float)(this->L_Los[0]->k[2] * this->cross_KL_Los.k[2]));
  return v3
       * v3
       / (float)((float)((float)(v1 * v1) + (float)(this->cross_KL_Los.k[1] * this->cross_KL_Los.k[1]))
               + (float)(this->cross_KL_Los.k[2] * this->cross_KL_Los.k[2]));
}

//------------------------------------------------------------------------------
// Address: 0x1007A2C0
// Name: public: static enum IVP_RETURN_TYPE IVP_Compact_Ledge_Solver::calc_unscaled_KK_vals(class IVP_KK_Input const __near &,class IVP_Unscaled_KK_Result __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall IVP_Compact_Ledge_Solver::calc_unscaled_KK_vals@<eax>(
        int a1@<ebp>,
        const IVP_KK_Input *in,
        IVP_Unscaled_KK_Result *result)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  const IVP_Compact_Ledge *compact_ledge; // eax
  const IVP_Compact_Edge *L; // ecx
  const IVP_Compact_Ledge *v15; // eax
  float v16; // xmm5_4
  float v17; // xmm4_4
  const IVP_Compact_Ledge *v18; // ecx
  int c_point_offset; // edx
  float v20; // xmm7_4
  float v21; // xmm0_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  const IVP_Compact_Edge *v26; // ecx
  const IVP_Compact_Ledge *v27; // eax
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm6_4
  int v31; // ecx
  float *v32; // ecx
  float v33; // xmm5_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // xmm4_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  IVP_Cache_Ledge_Point *cache_L; // edx
  float *k; // eax
  IVP_Cache_Ledge_Point *cache_K; // ecx
  float v44; // xmm2_4
  float v45; // xmm6_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float *v49; // eax
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm3_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  const IVP_U_Float_Point *v56; // eax
  float v57; // xmm0_4
  float v58; // xmm4_4
  float v59; // xmm5_4
  float *v60; // eax
  float v61; // xmm6_4
  float v62; // xmm2_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm2_4
  float *v66; // eax
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  const IVP_Compact_Edge *v70; // ecx
  float *v71; // eax
  float v72; // xmm5_4
  float v73; // xmm4_4
  const IVP_Compact_Ledge *v74; // edx
  int v75; // ecx
  float v76; // xmm7_4
  float v77; // xmm6_4
  float v78; // xmm0_4
  float v79; // xmm2_4
  float v80; // xmm0_4
  const IVP_Compact_Edge *v81; // ecx
  int v82; // eax
  float v83; // xmm3_4
  float v84; // xmm0_4
  float v85; // xmm6_4
  int v86; // ecx
  float v87; // xmm1_4
  float v88; // xmm7_4
  float v89; // xmm2_4
  float v90; // xmm5_4
  float v91; // xmm4_4
  float v92; // xmm0_4
  float v93; // xmm3_4
  float v94; // xmm2_4
  float v95; // xmm7_4
  float v96; // xmm1_4
  float v97; // [esp+14h] [ebp-DCh]
  float v98[3]; // [esp+24h] [ebp-CCh] BYREF
  IVP_U_Point L_Kos[2]; // [esp+30h] [ebp-C0h] BYREF
  _DWORD v100[3]; // [esp+50h] [ebp-A0h]
  float check_pos[13]; // [esp+5Ch] [ebp-94h] BYREF
  IVP_U_Point L_area; // [esp+90h] [ebp-60h]
  float v103; // [esp+A0h] [ebp-50h]
  float v104; // [esp+A4h] [ebp-4Ch]
  float v105; // [esp+A8h] [ebp-48h]
  float v106; // [esp+ACh] [ebp-44h]
  float v107; // [esp+B0h] [ebp-40h]
  float v108; // [esp+B4h] [ebp-3Ch]
  float s; // [esp+B8h] [ebp-38h]
  float v110; // [esp+BCh] [ebp-34h]
  float v111; // [esp+C0h] [ebp-30h]
  float pos; // [esp+C4h] [ebp-2Ch] BYREF
  float v113; // [esp+C8h] [ebp-28h]
  float min_qdist; // [esp+CCh] [ebp-24h]
  IVP_U_Point pL_Kos; // [esp+D0h] [ebp-20h]
  const IVP_Compact_Ledge *v116; // [esp+E0h] [ebp-10h]
  int v117; // [esp+E4h] [ebp-Ch]
  int i; // [esp+E8h] [ebp-8h]
  int retaddr; // [esp+F0h] [ebp+0h]

  v117 = a1;
  i = retaddr;
  if ( (float)((float)((float)(in->cross_KL_Los.k[0] * in->cross_KL_Los.k[0])
                     + (float)(in->cross_KL_Los.k[1] * in->cross_KL_Los.k[1]))
             + (float)(in->cross_KL_Los.k[2] * in->cross_KL_Los.k[2])) <= 0.000001 )
  {
    compact_ledge = in->cache_L->compact_ledge;
    v111 = 1.0e20;
    v100[0] = -1082130432;
    v100[1] = 1056964608;
    v100[2] = 0x40000000;
    check_pos[0] = 0.0;
    check_pos[1] = 1.0;
    check_pos[2] = -0.001;
    check_pos[3] = 0.001;
    check_pos[4] = 0.99900001;
    check_pos[7] = 0.000001;
    check_pos[5] = 1.001;
    check_pos[8] = 0.99999899;
    check_pos[6] = -0.000001;
    check_pos[9] = 1.000001;
    v116 = compact_ledge;
    pL_Kos.hesse_val = 0.0;
    do
    {
      s = *(float *)&v100[LODWORD(pL_Kos.hesse_val)];
      IVP_U_Float_Point::set_interpolate(this: (IVP_U_Float_Point *)&pos, p0: &in->K_Los[0], p1: &in->K_Los[1], s);
      L = in->L;
      v15 = &v116[(unsigned __int16)*(_DWORD *)L];
      v16 = *(float *)((char *)&v15->ledgetree_node_offset + v116->c_point_offset);
      v17 = *(float *)((char *)&v15->c_point_offset + v116->c_point_offset);
      v18 = &v116[(unsigned __int16)*(_DWORD *)((char *)L
                                              + *(int *)((char *)IVP_Compact_Edge::next_table
                                                       + ((unsigned __int8)L & 0xC)))];
      c_point_offset = v116->c_point_offset;
      v20 = *(float *)((char *)v18 + v116->c_point_offset + 8);
      v21 = *(float *)((char *)&v18->c_point_offset + v116->c_point_offset);
      v22 = *(float *)((char *)&v18->ledgetree_node_offset + v116->c_point_offset);
      v110 = *(float *)((char *)v15 + v116->c_point_offset + 8);
      v103 = v21;
      pL_Kos.k[2] = v21 - v17;
      v105 = v20;
      v107 = v22;
      v104 = v20 - v110;
      v106 = v22 - v16;
      v23 = (float)((float)(pos - v17) * (float)(v22 - v16)) - (float)((float)(v113 - v16) * (float)(v21 - v17));
      L_area.hesse_val = (float)((float)((float)((float)(v17 - v103) * (float)(v17 - v103))
                                       + (float)((float)(v16 - v107) * (float)(v16 - v107)))
                               + (float)((float)(v110 - v105) * (float)(v110 - v105)))
                       + 1.0e-18;
      v24 = (float)(1.0 / L_area.hesse_val)
          * (float)((float)((float)((float)((float)((float)(v113 - v16) * v104)
                                          - (float)((float)(min_qdist - v110) * (float)(v22 - v16)))
                                  * (float)((float)((float)(v113 - v16) * v104)
                                          - (float)((float)(min_qdist - v110) * (float)(v22 - v16))))
                          + (float)((float)((float)((float)(min_qdist - v110) * pL_Kos.k[2])
                                          - (float)((float)(pos - v17) * v104))
                                  * (float)((float)((float)(min_qdist - v110) * pL_Kos.k[2])
                                          - (float)((float)(pos - v17) * v104))))
                  + (float)(v23 * v23));
      if ( v111 > v24 )
      {
        v25 = s;
        result->checks_K[0] = s;
        result->checks_K[1] = 1.0 - v25;
        v26 = in->L;
        v27 = &v116[(unsigned __int16)*(_DWORD *)v26];
        v28 = *(float *)((char *)&v27->c_point_offset + c_point_offset);
        v29 = *(float *)((char *)&v27->ledgetree_node_offset + c_point_offset);
        v30 = *(float *)((char *)v27 + c_point_offset + 8);
        v31 = (unsigned __int16)*(_DWORD *)((char *)v26
                                          + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v26 & 0xC)));
        v111 = v24;
        v32 = (float *)((char *)&v116[v31].c_point_offset + v116->c_point_offset);
        v33 = v32[1];
        v34 = v33 - v113;
        v35 = v33 - v29;
        v36 = *v32 - v28;
        v97 = *v32 - pos;
        v108 = v32[2];
        v37 = (float)((float)((float)(v34 * v35) + (float)(v97 * v36))
                    + (float)((float)(v108 - min_qdist) * (float)(v108 - v30)))
            + 1.1754944e-38;
        check_pos[12] = v108 - v30;
        result->checks_L[0] = COERCE_FLOAT(
                                COERCE_UNSIGNED_INT(
                                  (float)((float)((float)(v29 - v113) * v35) + (float)((float)(v28 - pos) * v36))
                                + (float)((float)(v30 - min_qdist) * (float)(v108 - v30)))
                              ^ _mask__NegFloat_)
                            + 1.1754944e-38;
        result->checks_L[1] = v37;
      }
      ++LODWORD(pL_Kos.hesse_val);
    }
    while ( SLODWORD(pL_Kos.hesse_val) < 11 );
    v38 = in->L_Los[0]->k[0];
    v39 = in->L_Los[0]->k[1];
    v40 = in->L_Los[0]->k[2];
    cache_L = in->cache_L;
    k = cache_L->clp_cache_object->core_pos.k;
    cache_K = in->cache_K;
    v44 = (float)(k[13] * v39) + (float)(k[12] * v38);
    v45 = k[16] * v38;
    v46 = (float)((float)(k[10] * v40) + (float)((float)(k[9] * v39) + (float)(k[8] * v38))) + k[20];
    v47 = (float)((float)(k[14] * v40) + v44) + k[21];
    v48 = (float)((float)(k[18] * v40) + (float)((float)(k[17] * v39) + v45)) + k[22];
    v49 = cache_K->clp_cache_object->core_pos.k;
    v50 = v47 - v49[21];
    v51 = v46 - v49[20];
    v52 = v48 - v49[22];
    v98[0] = (float)((float)(v49[12] * v50) + (float)(v51 * v49[8])) + (float)(v49[16] * v52);
    v98[1] = (float)((float)(v49[13] * v50) + (float)(v49[9] * v51)) + (float)(v49[17] * v52);
    v53 = v49[14] * v50;
    v54 = v49[10] * v51;
    v55 = v49[18];
    v56 = in->L_Los[1];
    v98[2] = (float)(v53 + v54) + (float)(v55 * v52);
    v57 = v56->k[0];
    v58 = v56->k[1];
    v59 = v56->k[2];
    v60 = cache_L->clp_cache_object->core_pos.k;
    v61 = v60[16] * v57;
    v62 = (float)(v60[13] * v58) + (float)(v60[12] * v57);
    v63 = (float)((float)(v60[10] * v59) + (float)((float)(v60[9] * v58) + (float)(v57 * v60[8]))) + v60[20];
    v64 = (float)((float)(v60[14] * v59) + v62) + v60[21];
    v65 = (float)((float)(v60[18] * v59) + (float)((float)(v60[17] * v58) + v61)) + v60[22];
    v66 = cache_K->clp_cache_object->core_pos.k;
    v67 = v63 - v66[20];
    v68 = v64 - v66[21];
    v69 = v65 - v66[22];
    L_Kos[0].k[1] = (float)((float)(v66[12] * v68) + (float)(v67 * v66[8])) + (float)(v66[16] * v69);
    L_Kos[0].k[2] = (float)((float)(v66[13] * v68) + (float)(v66[9] * v67)) + (float)(v66[17] * v69);
    L_Kos[0].hesse_val = (float)((float)(v66[14] * v68) + (float)(v66[10] * v67)) + (float)(v66[18] * v69);
    v116 = cache_K->compact_ledge;
    pL_Kos.hesse_val = 0.0;
    do
    {
      v106 = *(float *)&v100[LODWORD(pL_Kos.hesse_val)];
      IVP_U_Float_Point::set_interpolate(
        this: (IVP_U_Float_Point *)&pos,
        p0: (const IVP_U_Float_Point *)v98,
        p1: (IVP_U_Point *)&L_Kos[0].k[1],
        s: v106);
      v70 = in->K;
      v71 = (float *)((char *)&v116[(unsigned __int16)*(_DWORD *)v70].c_point_offset + v116->c_point_offset);
      v72 = v71[1];
      v73 = *v71;
      v74 = v116;
      v75 = v116->c_point_offset
          + 16
          * (unsigned __int16)*(_DWORD *)((char *)v70
                                        + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v70 & 0xC)));
      v110 = v71[2];
      v76 = *(float *)((char *)v116 + v75 + 8);
      v77 = *(float *)((char *)&v116->ledgetree_node_offset + v75);
      LODWORD(L_area.hesse_val) = *(int *)((char *)&v116->c_point_offset + v75);
      pL_Kos.k[2] = L_area.hesse_val - v73;
      v107 = v76;
      v105 = v77;
      v108 = v76 - v110;
      s = v77 - v72;
      v78 = (float)((float)(pos - v73) * (float)(v77 - v72))
          - (float)((float)(v113 - v72) * (float)(L_area.hesse_val - v73));
      v103 = (float)((float)((float)((float)(v73 - L_area.hesse_val) * (float)(v73 - L_area.hesse_val))
                           + (float)((float)(v72 - v105) * (float)(v72 - v105)))
                   + (float)((float)(v110 - v107) * (float)(v110 - v107)))
           + 1.0e-18;
      v79 = (float)(1.0 / v103)
          * (float)((float)((float)((float)((float)((float)(v113 - v72) * v108)
                                          - (float)((float)(min_qdist - v110) * (float)(v77 - v72)))
                                  * (float)((float)((float)(v113 - v72) * v108)
                                          - (float)((float)(min_qdist - v110) * (float)(v77 - v72))))
                          + (float)((float)((float)((float)(min_qdist - v110) * pL_Kos.k[2])
                                          - (float)((float)(pos - v73) * v108))
                                  * (float)((float)((float)(min_qdist - v110) * pL_Kos.k[2])
                                          - (float)((float)(pos - v73) * v108))))
                  + (float)(v78 * v78));
      if ( v111 > v79 )
      {
        v80 = v106;
        result->checks_L[0] = v106;
        result->checks_L[1] = 1.0 - v80;
        v81 = in->K;
        v82 = v74->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)v81;
        v83 = *(float *)((char *)&v74->c_point_offset + v82);
        v84 = *(float *)((char *)&v74->ledgetree_node_offset + v82);
        v85 = *(float *)((char *)v74 + v82 + 8);
        v86 = v116->c_point_offset
            + 16
            * (unsigned __int16)*(_DWORD *)((char *)v81
                                          + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v81 & 0xC)));
        v87 = *(float *)((char *)&v116->ledgetree_node_offset + v86);
        v88 = *(float *)((char *)v116 + v86 + 8);
        v111 = v79;
        v89 = *(float *)((char *)&v116->c_point_offset + v86);
        v90 = v87 - v84;
        v91 = v89 - v83;
        check_pos[10] = v89 - pos;
        v92 = (float)((float)(v84 - v113) * (float)(v87 - v84)) + (float)((float)(v83 - pos) * (float)(v89 - v83));
        v93 = v89 - pos;
        v104 = v88;
        v94 = v88;
        v95 = v88 - v85;
        v96 = (float)((float)((float)((float)(v87 - v113) * v90) + (float)(v93 * v91))
                    + (float)((float)(v94 - min_qdist) * v95))
            + 1.1754944e-38;
        result->checks_K[0] = COERCE_FLOAT(COERCE_UNSIGNED_INT(v92 + (float)((float)(v85 - min_qdist) * v95)) ^ _mask__NegFloat_)
                            + 1.1754944e-38;
        result->checks_K[1] = v96;
      }
      ++LODWORD(pL_Kos.hesse_val);
    }
    while ( SLODWORD(pL_Kos.hesse_val) < 9 );
    return 0;
  }
  else
  {
    IVP_U_Float_Point::calc_cross_product(this: (IVP_U_Float_Point *)&pos, v1: &in->Kvec_Los, v2: &in->cross_KL_Los);
    IVP_U_Float_Point::calc_cross_product(
      this: (IVP_U_Float_Point *)&check_pos[10],
      v1: &in->Lvec_Los,
      v2: &in->cross_KL_Los);
    v3 = (float)((float)(in->L_Los[0]->k[1] * v113) + (float)(pos * in->L_Los[0]->k[0]))
       + (float)(in->L_Los[0]->k[2] * min_qdist);
    v4 = (float)((float)(v113 * in->K_Los[0].k[1]) + (float)(pos * in->K_Los[0].k[0]))
       + (float)(min_qdist * in->K_Los[0].k[2]);
    v5 = check_pos[10];
    v6 = (float)((float)(in->L_Los[1]->k[1] * v113) + (float)(in->L_Los[1]->k[0] * pos))
       + (float)(in->L_Los[1]->k[2] * min_qdist);
    v7 = check_pos[12];
    result->checks_L[1] = (float)(v4 - v6) * (float)(v3 - v6);
    v8 = check_pos[11];
    result->checks_L[0] = (float)(v3 - v4) * (float)(v3 - v6);
    v9 = (float)((float)(v8 * in->K_Los[0].k[1]) + (float)(v5 * in->K_Los[0].k[0])) + (float)(v7 * in->K_Los[0].k[2]);
    v10 = (float)((float)(in->K_Los[1].k[1] * v8) + (float)(v5 * in->K_Los[1].k[0])) + (float)(in->K_Los[1].k[2] * v7);
    v11 = (float)((float)(in->L_Los[0]->k[1] * v8) + (float)(in->L_Los[0]->k[0] * v5))
        + (float)(in->L_Los[0]->k[2] * v7);
    result->checks_K[0] = (float)((float)(v9 - v11) * (float)(v9 - v10)) + 1.1754944e-38;
    result->checks_K[1] = (float)((float)(v11 - v10) * (float)(v9 - v10)) + 1.1754944e-38;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AC80
// Name: public: static float IVP_Compact_Ledge_Solver::calc_qlen_KK(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall IVP_Compact_Ledge_Solver::calc_qlen_KK@<st0>(
        float a1@<ebp>,
        const IVP_Compact_Edge *K,
        const IVP_Compact_Edge *L,
        IVP_Cache_Ledge_Point *m_cache_K,
        IVP_Cache_Ledge_Point *m_cache_L)
{
  int v6; // edx
  int v7; // edx
  const IVP_Compact_Poly_Point *compact_poly_points; // eax
  float *v9; // eax
  int v10; // edx
  IVP_Cache_Object *clp_cache_object; // eax
  const IVP_Compact_Ledge *compact_ledge; // ecx
  float v13; // xmm0_4
  const IVP_Compact_Ledge *v14; // edx
  float v15; // xmm0_4
  const IVP_U_Point *v16; // esi
  float *v17; // eax
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  double v22; // st7
  double v23; // st7
  _BYTE v24[12]; // [esp-Ch] [ebp-12Ch] BYREF
  IVP_KK_Input kkin; // [esp+0h] [ebp-120h] BYREF
  float v26; // [esp+70h] [ebp-B0h]
  float v27[3]; // [esp+74h] [ebp-ACh] BYREF
  float v28; // [esp+90h] [ebp-90h]
  float v29; // [esp+94h] [ebp-8Ch]
  float v30; // [esp+98h] [ebp-88h]
  const IVP_Compact_Ledge *v31; // [esp+9Ch] [ebp-84h]
  float v32; // [esp+A0h] [ebp-80h]
  float v33; // [esp+A4h] [ebp-7Ch]
  float v34; // [esp+A8h] [ebp-78h]
  const IVP_Compact_Ledge *v35; // [esp+ACh] [ebp-74h]
  float v36; // [esp+B0h] [ebp-70h]
  float v37; // [esp+B4h] [ebp-6Ch]
  float v38; // [esp+B8h] [ebp-68h]
  float v39; // [esp+BCh] [ebp-64h]
  const IVP_Compact_Poly_Point *v40; // [esp+C0h] [ebp-60h]
  float v41; // [esp+C4h] [ebp-5Ch]
  float v42; // [esp+C8h] [ebp-58h]
  float v43; // [esp+CCh] [ebp-54h]
  float v44; // [esp+D0h] [ebp-50h]
  float v45; // [esp+D4h] [ebp-4Ch]
  float v46; // [esp+D8h] [ebp-48h]
  float v47; // [esp+DCh] [ebp-44h]
  float v48; // [esp+E0h] [ebp-40h]
  float v49; // [esp+E4h] [ebp-3Ch]
  float v50; // [esp+E8h] [ebp-38h]
  float v51; // [esp+ECh] [ebp-34h]
  float v52; // [esp+F0h] [ebp-30h]
  float v53; // [esp+F4h] [ebp-2Ch]
  float v54[2]; // [esp+F8h] [ebp-28h] BYREF
  float v55; // [esp+100h] [ebp-20h]
  const IVP_Compact_Edge *pL[2]; // [esp+104h] [ebp-1Ch]
  int v57; // [esp+10Ch] [ebp-14h]
  float v58; // [esp+110h] [ebp-10h]
  float h_len; // [esp+114h] [ebp-Ch] BYREF
  int i; // [esp+118h] [ebp-8h]
  int retaddr; // [esp+120h] [ebp+0h]

  h_len = a1;
  i = retaddr;
  IVP_KK_Input::IVP_KK_Input(this: (IVP_KK_Input *)v24, K_in: K, L_in: L, m_cache_K, m_cache_L);
  IVP_Compact_Ledge_Solver::calc_unscaled_KK_vals(
    a1: (int)&h_len,
    in: (const IVP_KK_Input *)v24,
    result: (IVP_Unscaled_KK_Result *)v54);
  if ( (LODWORD(v55) | (int)pL[0]) < 0 )
  {
    if ( (LODWORD(v54[0]) | LODWORD(v54[1])) >= 0 )
    {
      if ( v55 <= 0.0 )
      {
        IVP_Compact_Ledge_Solver::calc_pos_other_space(
          P: L,
          m_cache_P: m_cache_L,
          m_cache_other_space: m_cache_K,
          res: (IVP_U_Point *)v27);
        return IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(
                 P_in_K_space: (const IVP_U_Point *)v27,
                 K_ledge: (const IVP_Compact_Ledge *)*(_DWORD *)(v6 + 4),
                 K);
      }
      if ( *(float *)pL <= 0.0 )
      {
        IVP_Compact_Ledge_Solver::calc_pos_other_space(
          P: (const IVP_Compact_Edge *)((char *)L
                                   + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)L & 0xC))),
          m_cache_P: m_cache_L,
          m_cache_other_space: m_cache_K,
          res: (IVP_U_Point *)v27);
        return IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(
                 P_in_K_space: (const IVP_U_Point *)v27,
                 K_ledge: (const IVP_Compact_Ledge *)*(_DWORD *)(v7 + 4),
                 K);
      }
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_compact_ledge_solver.cxx", 674);
    }
    compact_poly_points = m_cache_L->compact_poly_points;
    v58 = 1.0e20;
    v40 = compact_poly_points;
    v9 = m_cache_L->clp_cache_object->core_pos.k;
    v33 = v9[8];
    v29 = v9[12];
    v38 = v9[16];
    v50 = v9[9];
    v28 = v9[13];
    v48 = v9[17];
    v36 = v9[10];
    v46 = v9[20];
    v30 = v9[14];
    v44 = v9[21];
    v34 = v9[18];
    v42 = v9[22];
    v10 = *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)L & 0xC));
    clp_cache_object = m_cache_K->clp_cache_object;
    compact_ledge = m_cache_K->compact_ledge;
    v26 = clp_cache_object->m_world_f_object.vv.k[0];
    v53 = clp_cache_object->m_world_f_object.vv.k[1];
    v32 = clp_cache_object->m_world_f_object.vv.k[2];
    v51 = clp_cache_object->m_world_f_object.rows[1].k[0];
    v52 = clp_cache_object->m_world_f_object.rows[0].k[0];
    v49 = clp_cache_object->m_world_f_object.rows[2].k[0];
    v45 = clp_cache_object->m_world_f_object.rows[1].k[1];
    v47 = clp_cache_object->m_world_f_object.rows[0].k[1];
    v43 = clp_cache_object->m_world_f_object.rows[2].k[1];
    v39 = clp_cache_object->m_world_f_object.rows[1].k[2];
    v13 = clp_cache_object->m_world_f_object.rows[0].k[2];
    pL[0] = (const IVP_Compact_Edge *)((char *)L + v10);
    v14 = m_cache_L->compact_ledge;
    v41 = v13;
    v15 = clp_cache_object->m_world_f_object.rows[2].k[2];
    v55 = *(float *)&L;
    v57 = 0;
    v37 = v15;
    v35 = compact_ledge;
    v31 = v14;
    v16 = (const IVP_U_Point *)&kkin.L_Los[1];
    do
    {
      v17 = v40[(unsigned __int16)*(_DWORD *)pL[v57 - 1]].k;
      v18 = v17[2];
      v19 = (float)((float)((float)((float)(v17[1] * v50) + (float)(*v17 * v33)) + (float)(v18 * v36)) + v46) - v26;
      v20 = (float)((float)((float)(v18 * v30) + (float)((float)(v17[1] * v28) + (float)(*v17 * v29))) + v44) - v53;
      v21 = (float)((float)((float)(v18 * v34) + (float)((float)(v17[1] * v48) + (float)(*v17 * v38))) + v42) - v32;
      v27[0] = (float)((float)(v19 * v52) + (float)(v20 * v51)) + (float)(v21 * v49);
      v27[1] = (float)((float)(v19 * v47) + (float)(v20 * v45)) + (float)(v21 * v43);
      v27[2] = (float)((float)(v19 * v41) + (float)(v20 * v39)) + (float)(v21 * v37);
      v22 = IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(P_in_K_space: (const IVP_U_Point *)v27, K_ledge: v35, K);
      *(float *)&pL[1] = v22;
      if ( v58 > v22 )
        v58 = *(float *)&pL[1];
      v23 = IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(P_in_K_space: v16, K_ledge: v31, K: L);
      *(float *)&pL[1] = v23;
      if ( v58 > v23 )
        v58 = *(float *)&pL[1];
      ++v16;
      ++v57;
    }
    while ( v57 <= 1 );
    return v58;
  }
  else if ( v54[0] > 0.0 )
  {
    if ( v54[1] > 0.0 )
      return IVP_KK_Input::calc_quad_distance_edge_edge(this: (IVP_KK_Input *)v24);
    else
      return IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(
               P_in_K_space: (const IVP_U_Point *)&kkin.K_Los[0].k[1],
               K_ledge: m_cache_L->compact_ledge,
               K: L);
  }
  else
  {
    return IVP_Compact_Ledge_Solver::calc_qlen_PK_K_space(
             P_in_K_space: (const IVP_U_Point *)&kkin.L_Los[1],
             K_ledge: m_cache_L->compact_ledge,
             K: L);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B0A0
// Name: public: static void IVP_Compact_Ledge_Solver::get_all_ledges(class IVP_Compact_Ledgetree_Node const __near *,class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::get_all_ledges(
        const IVP_Compact_Ledgetree_Node *node,
        IVP_U_BigVector<IVP_Compact_Ledge> *ledges_out)
{
  int offset_right_node; // edi
  char *v4; // edi

  while ( 1 )
  {
    offset_right_node = node->offset_right_node;
    if ( node->offset_right_node == 0 )
      break;
    IVP_Compact_Ledge_Solver::get_all_ledges(node: node + 1, ledges_out);
    node = (const IVP_Compact_Ledgetree_Node *)((char *)node + offset_right_node);
  }
  v4 = (char *)node + node->offset_compact_ledge;
  if ( ledges_out->n_elems >= ledges_out->memsize )
    IVP_U_BigVector_Base::increment_mem(this: ledges_out);
  ledges_out->elems[ledges_out->n_elems++] = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1007B0F0
// Name: public: static void IVP_Compact_Ledge_Solver::get_all_ledges(class IVP_Compact_Surface const __near *,class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::get_all_ledges(
        const IVP_Compact_Surface *surface,
        IVP_U_BigVector<IVP_Compact_Ledge> *all_ledges_out)
{
  IVP_Compact_Ledge_Solver::get_all_ledges(
    node: (const IVP_Compact_Ledgetree_Node *)((char *)surface + surface->offset_ledgetree_root),
    ledges_out: all_ledges_out);
}

//------------------------------------------------------------------------------
// Address: 0x1007B110
// Name: public: static void IVP_Compact_Ledge_Solver::calc_radius_to_given_center(class IVP_Compact_Surface const __near *,class IVP_U_Point const __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Compact_Ledge_Solver::calc_radius_to_given_center(
        const IVP_Compact_Surface *c_surface_in,
        const IVP_U_Point *center_in,
        float *radius_out,
        float *radius_dev_out)
{
  int i; // esi
  IVP_U_BigVector<IVP_Compact_Ledge> all_ledges; // [esp+0h] [ebp-Ch] BYREF
  char vars0; // [esp+Ch] [ebp+0h] BYREF

  *radius_out = 0.0;
  *radius_dev_out = 0.0;
  all_ledges.memsize = 1024;
  all_ledges.n_elems = 0;
  all_ledges.elems = (void **)p_malloc(size: 0x1000u);
  IVP_Compact_Ledge_Solver::get_all_ledges(
    node: (const IVP_Compact_Ledgetree_Node *)((char *)c_surface_in + c_surface_in->offset_ledgetree_root),
    ledges_out: &all_ledges);
  for ( i = all_ledges.n_elems - 1; i >= 0; --i )
    IVP_Compact_Ledge_Solver::calc_radius_to_given_center(
      ledge: (const IVP_Compact_Ledge *)all_ledges.elems[i],
      center_in,
      radius_out,
      radius_dev_out);
  if ( (char *)all_ledges.elems != &vars0 && all_ledges.elems != nullptr )
    free(data: all_ledges.elems);
}
