// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_solver_core_reaction.cxx
// Functions: 6
// ============================================================

#include "ivp\ivp_intern\ivp_solver_core_reaction.h"

//------------------------------------------------------------------------------
// Address: 0x10094DA0
// Name: private: void IVP_Solver_Core_Reaction::init_trans_ws(class IVP_U_Point const __near *,class IVP_Core __near *,class IVP_U_Point_4 __near * const,class IVP_U_Point_4 __near * const,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Solver_Core_Reaction::init_trans_ws(
        IVP_Solver_Core_Reaction *this,
        const IVP_U_Point *pos_ws,
        IVP_Core *core,
        IVP_U_Point_4 *cross_direction_position_cs,
        IVP_U_Point_4 *cr_mult_inv,
        float sign)
{
  float *p_m_world_f_core_last_psi; // esi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm2_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm2_4
  float hesse_val; // xmm4_4
  float v25; // xmm3_4
  IVP_U_Float_Point *v26; // ecx
  float v27; // xmm6_4
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm4_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm6_4
  IVP_U_Float_Point *v35; // ecx
  IVP_U_Float_Point *v36; // ecx
  float v37; // xmm4_4
  float v38; // xmm3_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm3_4
  float v42; // xmm5_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm4_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  IVP_U_Float_Point *v49; // esi
  float v50; // [esp+8h] [ebp-14h]
  float v51; // [esp+8h] [ebp-14h]
  float v52; // [esp+Ch] [ebp-10h]
  float v53; // [esp+Ch] [ebp-10h]
  float v54; // [esp+10h] [ebp-Ch]
  float v55; // [esp+14h] [ebp-8h]
  float pos_wsa; // [esp+24h] [ebp+8h]
  float pos_wsb; // [esp+24h] [ebp+8h]
  float pos_wsc; // [esp+24h] [ebp+8h]
  float corea; // [esp+28h] [ebp+Ch]
  float coreb; // [esp+28h] [ebp+Ch]
  float corec; // [esp+28h] [ebp+Ch]
  float cored; // [esp+28h] [ebp+Ch]
  float cross_direction_position_csa; // [esp+2Ch] [ebp+10h]
  float cross_direction_position_csb; // [esp+2Ch] [ebp+10h]
  float cr_mult_inva; // [esp+30h] [ebp+14h]

  p_m_world_f_core_last_psi = (float *)&core->m_world_f_core_last_psi;
  this->m_world_f_core_last_psi[0] = &core->m_world_f_core_last_psi;
  v8 = pos_ws->k[2] - core->m_world_f_core_last_psi.vv.k[2];
  v9 = pos_ws->k[1] - core->m_world_f_core_last_psi.vv.k[1];
  v10 = pos_ws->k[0] - core->m_world_f_core_last_psi.vv.k[0];
  v11 = this->direction_ws[0]->k[2];
  v12 = core->m_world_f_core_last_psi.rows[0].k[0];
  v13 = v11 * v10;
  corea = this->direction_ws[0]->k[0];
  v14 = (float)(v11 * v9) - (float)(v8 * this->direction_ws[0]->k[1]);
  v15 = (float)(v8 * corea) - v13;
  v17 = (float)(v10 * this->direction_ws[0]->k[1]) - (float)(v9 * corea);
  coreb = p_m_world_f_core_last_psi[1];
  pos_wsa = p_m_world_f_core_last_psi[5];
  v55 = p_m_world_f_core_last_psi[9];
  v54 = p_m_world_f_core_last_psi[2];
  v52 = p_m_world_f_core_last_psi[6];
  v50 = p_m_world_f_core_last_psi[10];
  cross_direction_position_cs->k[0] = (float)((float)(v15 * p_m_world_f_core_last_psi[4]) + (float)(v12 * v14))
                                    + (float)(v17 * p_m_world_f_core_last_psi[8]);
  v18 = (float)((float)(coreb * v14) + (float)(v15 * pos_wsa)) + (float)(v17 * v55);
  cross_direction_position_cs->k[1] = v18;
  v19 = v54 * v14;
  v20 = cross_direction_position_cs->k[0];
  cross_direction_position_cs->hesse_val = 1.0;
  v21 = (float)(v19 + (float)(v15 * v52)) + (float)(v17 * v50);
  cross_direction_position_cs->k[2] = v21;
  v22 = v18 * core->inv_rot_inertia.k[1];
  hesse_val = core->inv_rot_inertia.hesse_val;
  v25 = core->inv_rot_inertia.k[2] * v21;
  cr_mult_inv->k[0] = v20 * core->inv_rot_inertia.k[0];
  cr_mult_inv->k[1] = v22;
  cr_mult_inv->k[2] = v25;
  cr_mult_inv->hesse_val = hesse_val;
  this->m_velocity_ds_f_impulse_ds.rows[0].k[0] = (float)((float)((float)((float)(v22 * cross_direction_position_cs->k[1])
                                                                        + (float)(cross_direction_position_cs->k[0]
                                                                                * cr_mult_inv->k[0]))
                                                                + (float)(v25 * cross_direction_position_cs->k[2]))
                                                        + (float)(cross_direction_position_cs->hesse_val * hesse_val))
                                                + this->m_velocity_ds_f_impulse_ds.rows[0].k[0];
  this->delta_velocity_ds.k[0] = (float)((float)((float)((float)((float)(this->direction_ws[0]->k[1] * core->speed.k[1])
                                                               + (float)(core->speed.k[0] * this->direction_ws[0]->k[0]))
                                                       + (float)(this->direction_ws[0]->k[2] * core->speed.k[2]))
                                               + (float)((float)((float)(core->rot_speed.k[1]
                                                                       * cross_direction_position_cs->k[1])
                                                               + (float)(core->rot_speed.k[0]
                                                                       * cross_direction_position_cs->k[0]))
                                                       + (float)(core->rot_speed.k[2] * cross_direction_position_cs->k[2])))
                                       * sign)
                               + this->delta_velocity_ds.k[0];
  v26 = this->direction_ws[1];
  if ( v26 != nullptr )
  {
    v27 = v26->k[2];
    v28 = v26->k[1];
    v29 = (float)(v9 * v27) - (float)(v8 * v28);
    v30 = (float)(v8 * v26->k[0]) - (float)(v27 * v10);
    v31 = (float)(v28 * v10) - (float)(v9 * v26->k[0]);
    corec = p_m_world_f_core_last_psi[1];
    pos_wsb = p_m_world_f_core_last_psi[5];
    cross_direction_position_csa = p_m_world_f_core_last_psi[9];
    cr_mult_inva = p_m_world_f_core_last_psi[2];
    v51 = p_m_world_f_core_last_psi[6];
    v53 = p_m_world_f_core_last_psi[10];
    cross_direction_position_cs[1].k[0] = (float)((float)(*p_m_world_f_core_last_psi * v29)
                                                + (float)(v30 * p_m_world_f_core_last_psi[4]))
                                        + (float)(v31 * p_m_world_f_core_last_psi[8]);
    cross_direction_position_cs[1].k[1] = (float)((float)(corec * v29) + (float)(v30 * pos_wsb))
                                        + (float)(v31 * cross_direction_position_csa);
    cross_direction_position_cs[1].k[2] = (float)((float)(cr_mult_inva * v29) + (float)(v30 * v51)) + (float)(v31 * v53);
    cross_direction_position_cs[1].hesse_val = 1.0;
    v32 = cross_direction_position_cs[1].k[2] * core->inv_rot_inertia.k[2];
    v33 = cross_direction_position_cs[1].hesse_val * core->inv_rot_inertia.hesse_val;
    v34 = core->inv_rot_inertia.k[0] * cross_direction_position_cs[1].k[0];
    cr_mult_inv[1].k[1] = cross_direction_position_cs[1].k[1] * core->inv_rot_inertia.k[1];
    cr_mult_inv[1].k[2] = v32;
    cr_mult_inv[1].k[0] = v34;
    cr_mult_inv[1].hesse_val = v33;
    this->m_velocity_ds_f_impulse_ds.rows[1].k[1] = (float)((float)((float)((float)(v34
                                                                                  * cross_direction_position_cs[1].k[0])
                                                                          + (float)(cr_mult_inv[1].k[1]
                                                                                  * cross_direction_position_cs[1].k[1]))
                                                                  + (float)(cr_mult_inv[1].k[2]
                                                                          * cross_direction_position_cs[1].k[2]))
                                                          + (float)(v33 * cross_direction_position_cs[1].hesse_val))
                                                  + this->m_velocity_ds_f_impulse_ds.rows[1].k[1];
    this->m_velocity_ds_f_impulse_ds.rows[0].k[1] = (float)((float)((float)(cr_mult_inv[1].k[0]
                                                                          * cross_direction_position_cs->k[0])
                                                                  + (float)(cr_mult_inv[1].k[1]
                                                                          * cross_direction_position_cs->k[1]))
                                                          + (float)(cr_mult_inv[1].k[2]
                                                                  * cross_direction_position_cs->k[2]))
                                                  + this->m_velocity_ds_f_impulse_ds.rows[0].k[1];
    v35 = this->direction_ws[1];
    this->delta_velocity_ds.k[1] = (float)((float)((float)((float)((float)(v35->k[1] * core->speed.k[1])
                                                                 + (float)(core->speed.k[0] * v35->k[0]))
                                                         + (float)(v35->k[2] * core->speed.k[2]))
                                                 + (float)((float)((float)(core->rot_speed.k[0]
                                                                         * cross_direction_position_cs[1].k[0])
                                                                 + (float)(cross_direction_position_cs[1].k[1]
                                                                         * core->rot_speed.k[1]))
                                                         + (float)(cross_direction_position_cs[1].k[2]
                                                                 * core->rot_speed.k[2])))
                                         * sign)
                                 + this->delta_velocity_ds.k[1];
    v36 = this->direction_ws[2];
    if ( v36 != nullptr )
    {
      v37 = v36->k[2];
      v38 = v36->k[1];
      v39 = (float)(v9 * v37) - (float)(v8 * v38);
      pos_wsc = p_m_world_f_core_last_psi[6];
      cross_direction_position_csb = p_m_world_f_core_last_psi[10];
      v40 = (float)(v8 * v36->k[0]) - (float)(v37 * v10);
      v41 = v38 * v10;
      v42 = p_m_world_f_core_last_psi[5];
      v43 = v41 - (float)(v9 * v36->k[0]);
      v44 = p_m_world_f_core_last_psi[1] * v39;
      cored = p_m_world_f_core_last_psi[9];
      v45 = p_m_world_f_core_last_psi[2];
      cross_direction_position_cs[2].k[0] = (float)((float)(v40 * p_m_world_f_core_last_psi[4])
                                                  + (float)(*p_m_world_f_core_last_psi * v39))
                                          + (float)(v43 * p_m_world_f_core_last_psi[8]);
      cross_direction_position_cs[2].k[1] = (float)((float)(v40 * v42) + v44) + (float)(v43 * cored);
      cross_direction_position_cs[2].k[2] = (float)((float)(v40 * pos_wsc) + (float)(v45 * v39))
                                          + (float)(v43 * cross_direction_position_csb);
      cross_direction_position_cs[2].hesse_val = 1.0;
      v46 = cross_direction_position_cs[2].k[2] * core->inv_rot_inertia.k[2];
      v47 = core->inv_rot_inertia.hesse_val * cross_direction_position_cs[2].hesse_val;
      v48 = core->inv_rot_inertia.k[0] * cross_direction_position_cs[2].k[0];
      cr_mult_inv[2].k[1] = cross_direction_position_cs[2].k[1] * core->inv_rot_inertia.k[1];
      cr_mult_inv[2].k[2] = v46;
      cr_mult_inv[2].k[0] = v48;
      cr_mult_inv[2].hesse_val = v47;
      this->m_velocity_ds_f_impulse_ds.rows[2].k[2] = (float)((float)((float)((float)(v48
                                                                                    * cross_direction_position_cs[2].k[0])
                                                                            + (float)(cr_mult_inv[2].k[1]
                                                                                    * cross_direction_position_cs[2].k[1]))
                                                                    + (float)(cr_mult_inv[2].k[2]
                                                                            * cross_direction_position_cs[2].k[2]))
                                                            + (float)(v47 * cross_direction_position_cs[2].hesse_val))
                                                    + this->m_velocity_ds_f_impulse_ds.rows[2].k[2];
      this->m_velocity_ds_f_impulse_ds.rows[0].k[2] = (float)((float)((float)(cr_mult_inv[2].k[0]
                                                                            * cross_direction_position_cs->k[0])
                                                                    + (float)(cr_mult_inv[2].k[1]
                                                                            * cross_direction_position_cs->k[1]))
                                                            + (float)(cr_mult_inv[2].k[2]
                                                                    * cross_direction_position_cs->k[2]))
                                                    + this->m_velocity_ds_f_impulse_ds.rows[0].k[2];
      this->m_velocity_ds_f_impulse_ds.rows[1].k[2] = (float)((float)((float)(cr_mult_inv[2].k[0]
                                                                            * cross_direction_position_cs[1].k[0])
                                                                    + (float)(cross_direction_position_cs[1].k[1]
                                                                            * cr_mult_inv[2].k[1]))
                                                            + (float)(cross_direction_position_cs[1].k[2]
                                                                    * cr_mult_inv[2].k[2]))
                                                    + this->m_velocity_ds_f_impulse_ds.rows[1].k[2];
      v49 = this->direction_ws[2];
      this->delta_velocity_ds.k[2] = (float)((float)((float)((float)((float)(v49->k[1] * core->speed.k[1])
                                                                   + (float)(v49->k[0] * core->speed.k[0]))
                                                           + (float)(v49->k[2] * core->speed.k[2]))
                                                   + (float)((float)((float)(core->rot_speed.k[0]
                                                                           * cross_direction_position_cs[2].k[0])
                                                                   + (float)(cross_direction_position_cs[2].k[1]
                                                                           * core->rot_speed.k[1]))
                                                           + (float)(cross_direction_position_cs[2].k[2]
                                                                   * core->rot_speed.k[2])))
                                           * sign)
                                   + this->delta_velocity_ds.k[2];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095440
// Name: private: void IVP_Solver_Core_Reaction::init_rot_ws(class IVP_Core __near *,class IVP_U_Point_4 __near * const,class IVP_U_Point_4 __near * const,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Solver_Core_Reaction::init_rot_ws(
        IVP_Solver_Core_Reaction *this,
        IVP_Core *core,
        IVP_U_Point_4 *cross_direction_position_cs,
        IVP_U_Point_4 *cr_mult_inv,
        float sign)
{
  IVP_U_Float_Point *v6; // edx
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  IVP_U_Float_Point *v16; // edx
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  const IVP_U_Float_Point *v27; // edx
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm2_4

  v6 = this->direction_ws[0];
  this->m_world_f_core_last_psi[0] = &core->m_world_f_core_last_psi;
  v7 = v6->k[1];
  v8 = v6->k[2];
  v9 = (float)((float)(core->m_world_f_core_last_psi.rows[0].k[1] * v6->k[0])
             + (float)(core->m_world_f_core_last_psi.rows[1].k[1] * v7))
     + (float)(core->m_world_f_core_last_psi.rows[2].k[1] * v8);
  v10 = (float)((float)(core->m_world_f_core_last_psi.rows[1].k[2] * v7)
              + (float)(v6->k[0] * core->m_world_f_core_last_psi.rows[0].k[2]))
      + (float)(core->m_world_f_core_last_psi.rows[2].k[2] * v8);
  v11 = (float)((float)(core->m_world_f_core_last_psi.rows[0].k[0] * v6->k[0])
              + (float)(v7 * core->m_world_f_core_last_psi.rows[1].k[0]))
      + (float)(core->m_world_f_core_last_psi.rows[2].k[0] * v8);
  cross_direction_position_cs->k[1] = v9;
  cross_direction_position_cs->k[0] = v11;
  cross_direction_position_cs->k[2] = v10;
  cross_direction_position_cs->hesse_val = 0.0;
  v12 = v10 * core->inv_rot_inertia.k[2];
  v13 = core->inv_rot_inertia.k[0] * cross_direction_position_cs->k[0];
  v14 = core->inv_rot_inertia.k[1] * v9;
  v15 = core->inv_rot_inertia.hesse_val * 0.0;
  cr_mult_inv->k[1] = v14;
  cr_mult_inv->hesse_val = v15;
  cr_mult_inv->k[0] = v13;
  cr_mult_inv->k[2] = v12;
  this->m_velocity_ds_f_impulse_ds.rows[0].k[0] = (float)((float)((float)(v14 * cross_direction_position_cs->k[1])
                                                                + (float)(cross_direction_position_cs->k[0] * v13))
                                                        + (float)(cross_direction_position_cs->k[2] * v12))
                                                + this->m_velocity_ds_f_impulse_ds.rows[0].k[0];
  v16 = this->direction_ws[1];
  this->delta_velocity_ds.k[0] = (float)((float)((float)((float)(cross_direction_position_cs->k[0] * core->rot_speed.k[0])
                                                       + (float)(core->rot_speed.k[1] * cross_direction_position_cs->k[1]))
                                               + (float)(core->rot_speed.k[2] * cross_direction_position_cs->k[2]))
                                       * sign)
                               + this->delta_velocity_ds.k[0];
  if ( v16 != nullptr )
  {
    v17 = v16->k[1];
    v18 = v16->k[2];
    v19 = (float)((float)(core->m_world_f_core_last_psi.rows[0].k[1] * v16->k[0])
                + (float)(core->m_world_f_core_last_psi.rows[1].k[1] * v17))
        + (float)(core->m_world_f_core_last_psi.rows[2].k[1] * v18);
    v20 = (float)((float)(core->m_world_f_core_last_psi.rows[1].k[2] * v17)
                + (float)(v16->k[0] * core->m_world_f_core_last_psi.rows[0].k[2]))
        + (float)(core->m_world_f_core_last_psi.rows[2].k[2] * v18);
    v21 = (float)(core->m_world_f_core_last_psi.rows[0].k[0] * v16->k[0])
        + (float)(v17 * core->m_world_f_core_last_psi.rows[1].k[0]);
    v22 = core->m_world_f_core_last_psi.rows[2].k[0];
    cross_direction_position_cs[1].k[1] = v19;
    cross_direction_position_cs[1].k[2] = v20;
    cross_direction_position_cs[1].k[0] = v21 + (float)(v22 * v18);
    cross_direction_position_cs[1].hesse_val = 0.0;
    v23 = core->inv_rot_inertia.k[1] * cross_direction_position_cs[1].k[1];
    v24 = cross_direction_position_cs[1].k[2] * core->inv_rot_inertia.k[2];
    v25 = core->inv_rot_inertia.k[0] * cross_direction_position_cs[1].k[0];
    v26 = 0.0 * core->inv_rot_inertia.hesse_val;
    cr_mult_inv[1].k[1] = v23;
    cr_mult_inv[1].k[2] = v24;
    cr_mult_inv[1].k[0] = v25;
    cr_mult_inv[1].hesse_val = v26;
    this->m_velocity_ds_f_impulse_ds.rows[1].k[1] = (float)((float)((float)(v23 * cross_direction_position_cs[1].k[1])
                                                                  + (float)(cross_direction_position_cs[1].k[0] * v25))
                                                          + (float)(cr_mult_inv[1].k[2]
                                                                  * cross_direction_position_cs[1].k[2]))
                                                  + this->m_velocity_ds_f_impulse_ds.rows[1].k[1];
    this->m_velocity_ds_f_impulse_ds.rows[0].k[1] = (float)((float)((float)(cr_mult_inv[1].k[1]
                                                                          * cross_direction_position_cs->k[1])
                                                                  + (float)(cross_direction_position_cs->k[0]
                                                                          * cr_mult_inv[1].k[0]))
                                                          + (float)(cross_direction_position_cs->k[2]
                                                                  * cr_mult_inv[1].k[2]))
                                                  + this->m_velocity_ds_f_impulse_ds.rows[0].k[1];
    this->delta_velocity_ds.k[1] = (float)((float)((float)((float)(core->rot_speed.k[1]
                                                                 * cross_direction_position_cs[1].k[1])
                                                         + (float)(cross_direction_position_cs[1].k[0]
                                                                 * core->rot_speed.k[0]))
                                                 + (float)(core->rot_speed.k[2] * cross_direction_position_cs[1].k[2]))
                                         * sign)
                                 + this->delta_velocity_ds.k[1];
  }
  v27 = this->direction_ws[2];
  if ( v27 != nullptr )
  {
    IVP_U_Matrix3::vimult3(this: &core->m_world_f_core_last_psi, p_in: v27, p_out: cross_direction_position_cs + 2);
    cross_direction_position_cs[2].hesse_val = 0.0;
    v28 = cross_direction_position_cs[2].k[2] * core->inv_rot_inertia.k[2];
    v29 = core->inv_rot_inertia.k[0] * cross_direction_position_cs[2].k[0];
    v30 = cross_direction_position_cs[2].hesse_val * core->inv_rot_inertia.hesse_val;
    cr_mult_inv[2].k[1] = core->inv_rot_inertia.k[1] * cross_direction_position_cs[2].k[1];
    cr_mult_inv[2].k[0] = v29;
    cr_mult_inv[2].k[2] = v28;
    cr_mult_inv[2].hesse_val = v30;
    this->m_velocity_ds_f_impulse_ds.rows[2].k[2] = (float)((float)((float)(cross_direction_position_cs[2].k[0] * v29)
                                                                  + (float)(cross_direction_position_cs[2].k[1]
                                                                          * cr_mult_inv[2].k[1]))
                                                          + (float)(cr_mult_inv[2].k[2]
                                                                  * cross_direction_position_cs[2].k[2]))
                                                  + this->m_velocity_ds_f_impulse_ds.rows[2].k[2];
    this->m_velocity_ds_f_impulse_ds.rows[0].k[2] = (float)((float)((float)(cr_mult_inv[2].k[1]
                                                                          * cross_direction_position_cs->k[1])
                                                                  + (float)(cr_mult_inv[2].k[0]
                                                                          * cross_direction_position_cs->k[0]))
                                                          + (float)(cross_direction_position_cs->k[2]
                                                                  * cr_mult_inv[2].k[2]))
                                                  + this->m_velocity_ds_f_impulse_ds.rows[0].k[2];
    this->m_velocity_ds_f_impulse_ds.rows[1].k[2] = (float)((float)((float)(cross_direction_position_cs[1].k[1]
                                                                          * cr_mult_inv[2].k[1])
                                                                  + (float)(cr_mult_inv[2].k[0]
                                                                          * cross_direction_position_cs[1].k[0]))
                                                          + (float)(cross_direction_position_cs[1].k[2]
                                                                  * cr_mult_inv[2].k[2]))
                                                  + this->m_velocity_ds_f_impulse_ds.rows[1].k[2];
    this->delta_velocity_ds.k[2] = (float)((float)((float)((float)(cross_direction_position_cs[2].k[0]
                                                                 * core->rot_speed.k[0])
                                                         + (float)(core->rot_speed.k[1]
                                                                 * cross_direction_position_cs[2].k[1]))
                                                 + (float)(core->rot_speed.k[2] * cross_direction_position_cs[2].k[2]))
                                         * sign)
                                 + this->delta_velocity_ds.k[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095850
// Name: public: void IVP_Solver_Core_Reaction::init_reaction_solver_translation_ws(class IVP_Core __near *,class IVP_Core __near *,class IVP_U_Point __near &,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Solver_Core_Reaction::init_reaction_solver_translation_ws(
        IVP_Solver_Core_Reaction *this,
        IVP_Core *core_0,
        IVP_Core *core_1,
        IVP_U_Point *pos_ws,
        IVP_U_Float_Point *direction_0_ws,
        IVP_U_Float_Point *direction_1_ws,
        IVP_U_Float_Point *direction_2_ws)
{
  this->direction_ws[0] = direction_0_ws;
  this->direction_ws[1] = direction_1_ws;
  this->direction_ws[2] = direction_2_ws;
  if ( direction_1_ws != nullptr )
  {
    memset(
      dst: (unsigned __int8 *)&this->m_velocity_ds_f_impulse_ds,
      value: 0,
      count: sizeof(this->m_velocity_ds_f_impulse_ds));
    *(_QWORD *)&this->delta_velocity_ds.k[1] = 0;
  }
  else
  {
    this->m_velocity_ds_f_impulse_ds.rows[0].k[0] = 0.0;
  }
  this->delta_velocity_ds.k[0] = 0.0;
  if ( core_0 != nullptr )
    IVP_Solver_Core_Reaction::init_trans_ws(
      this,
      pos_ws,
      core: core_0,
      cross_direction_position_cs: this->cross_direction_position_cs0,
      cr_mult_inv: this->cr_mult_inv0,
      sign: 1.0);
  if ( core_1 != nullptr )
    IVP_Solver_Core_Reaction::init_trans_ws(
      this,
      pos_ws,
      core: core_1,
      cross_direction_position_cs: this->cross_direction_position_cs1,
      cr_mult_inv: this->cr_mult_inv1,
      sign: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10095910
// Name: public: void IVP_Solver_Core_Reaction::init_reaction_solver_rotation_ws(class IVP_Core __near *,class IVP_Core __near *,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Solver_Core_Reaction::init_reaction_solver_rotation_ws(
        IVP_Solver_Core_Reaction *this,
        IVP_Core *core_0,
        IVP_Core *core_1,
        IVP_U_Float_Point *direction_0_ws,
        IVP_U_Float_Point *direction_1_ws,
        IVP_U_Float_Point *direction_2_ws)
{
  this->direction_ws[0] = direction_0_ws;
  this->direction_ws[1] = direction_1_ws;
  this->direction_ws[2] = direction_2_ws;
  memset(
    dst: (unsigned __int8 *)&this->m_velocity_ds_f_impulse_ds,
    value: 0,
    count: sizeof(this->m_velocity_ds_f_impulse_ds));
  *(_QWORD *)this->delta_velocity_ds.k = 0;
  *(_QWORD *)&this->delta_velocity_ds.k[2] = 0;
  if ( core_0 != nullptr )
    IVP_Solver_Core_Reaction::init_rot_ws(
      this,
      core: core_0,
      cross_direction_position_cs: this->cross_direction_position_cs0,
      cr_mult_inv: this->cr_mult_inv0,
      sign: 1.0);
  if ( core_1 != nullptr )
    IVP_Solver_Core_Reaction::init_rot_ws(
      this,
      core: core_1,
      cross_direction_position_cs: this->cross_direction_position_cs1,
      cr_mult_inv: this->cr_mult_inv1,
      sign: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x100959B0
// Name: public: void IVP_Solver_Core_Reaction::exert_impulse_dim2(class IVP_Core restrict __near *,class IVP_Core restrict __near *,class IVP_U_Float_Point __near &)restrict
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Solver_Core_Reaction::exert_impulse_dim2(
        IVP_Solver_Core_Reaction *this,
        IVP_Core *core_0,
        IVP_Core *core_1,
        IVP_U_Float_Point *impulse_ds)
{
  IVP_U_Float_Point *v4; // edx
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  IVP_U_Float_Point *v26; // edx
  float v27; // xmm0_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm0_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm0_4
  float v40; // xmm5_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm5_4
  float v45; // xmm4_4
  float v46; // xmm1_4
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm0_4

  if ( core_0 != nullptr )
  {
    v4 = this->direction_ws[1];
    v5 = impulse_ds->k[0] * core_0->inv_rot_inertia.hesse_val;
    v6 = impulse_ds->k[1] * core_0->inv_rot_inertia.hesse_val;
    v7 = this->direction_ws[0]->k[0] * v5;
    v8 = this->direction_ws[0]->k[1] * v5;
    v9 = this->direction_ws[0]->k[2] * v5;
    v10 = v4->k[1] * v6;
    v11 = (float)(v4->k[0] * v6) + v7;
    v12 = v4->k[2] * v6;
    v13 = core_0->speed.k[0];
    v14 = (float)(v10 + v8) + core_0->speed.k[1];
    v15 = impulse_ds->k[1];
    core_0->speed.k[1] = v14;
    v16 = impulse_ds->k[0];
    v17 = v13 + v11;
    v18 = this->cr_mult_inv0[0].k[2];
    core_0->speed.k[0] = v17;
    v19 = this->cr_mult_inv0[0].k[1] * v16;
    core_0->speed.k[2] = (float)(v12 + v9) + core_0->speed.k[2];
    v20 = (float)(this->cr_mult_inv0[1].k[1] * v15) + v19;
    v21 = (float)(this->cr_mult_inv0[1].k[2] * v15) + (float)(v18 * v16);
    v22 = core_0->rot_speed.k[0]
        + (float)((float)(this->cr_mult_inv0[1].k[0] * v15) + (float)(this->cr_mult_inv0[0].k[0] * v16));
    core_0->rot_speed.k[1] = core_0->rot_speed.k[1] + v20;
    v23 = core_0->rot_speed.k[2] + v21;
    core_0->rot_speed.k[0] = v22;
    core_0->rot_speed.k[2] = v23;
  }
  if ( core_1 != nullptr )
  {
    v24 = impulse_ds->k[0];
    v25 = impulse_ds->k[1];
    v26 = this->direction_ws[1];
    v27 = -(float)(impulse_ds->k[0] * core_1->inv_rot_inertia.hesse_val);
    v28 = this->direction_ws[0]->k[0] * v27;
    v29 = this->direction_ws[0]->k[1] * v27;
    v30 = this->direction_ws[0]->k[2] * v27;
    v31 = -(float)(v25 * core_1->inv_rot_inertia.hesse_val);
    v32 = (float)(v26->k[0] * v31) + v28;
    v33 = (float)(v26->k[1] * v31) + v29;
    v34 = v26->k[2] * v31;
    v35 = core_1->speed.k[0] + v32;
    v36 = this->cr_mult_inv1[0].k[0];
    core_1->speed.k[0] = v35;
    v37 = core_1->speed.k[1] + v33;
    v38 = this->cr_mult_inv1[0].k[1];
    core_1->speed.k[1] = v37;
    v39 = core_1->speed.k[2] + (float)(v34 + v30);
    v40 = this->cr_mult_inv1[0].k[2];
    core_1->speed.k[2] = v39;
    v41 = -v24;
    v42 = -v25;
    v43 = (float)(this->cr_mult_inv1[1].k[0] * v42) + (float)(v36 * v41);
    v44 = v40 * v41;
    v45 = v38 * v41;
    v46 = this->cr_mult_inv1[1].k[1] * v42;
    v47 = this->cr_mult_inv1[1].k[2] * v42;
    v48 = core_1->rot_speed.k[0] + v43;
    core_1->rot_speed.k[1] = core_1->rot_speed.k[1] + (float)(v46 + v45);
    v49 = core_1->rot_speed.k[2] + (float)(v47 + v44);
    core_1->rot_speed.k[0] = v48;
    core_1->rot_speed.k[2] = v49;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095C40
// Name: public: void IVP_Solver_Core_Reaction::exert_angular_impulse_dim2(class IVP_Core __near *,class IVP_Core __near *,class IVP_U_Float_Point __near &)restrict
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Solver_Core_Reaction::exert_angular_impulse_dim2(
        IVP_Solver_Core_Reaction *this,
        IVP_Core *core_0,
        IVP_Core *core_1,
        IVP_U_Float_Point *impulse_ds)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( core_0 != nullptr )
  {
    v4 = impulse_ds->k[0];
    core_0->rot_speed.k[0] = (float)(this->cr_mult_inv0[0].k[0] * impulse_ds->k[0]) + core_0->rot_speed.k[0];
    core_0->rot_speed.k[1] = (float)(this->cr_mult_inv0[0].k[1] * v4) + core_0->rot_speed.k[1];
    core_0->rot_speed.k[2] = (float)(this->cr_mult_inv0[0].k[2] * v4) + core_0->rot_speed.k[2];
    v5 = impulse_ds->k[1];
    core_0->rot_speed.k[0] = (float)(this->cr_mult_inv0[1].k[0] * v5) + core_0->rot_speed.k[0];
    core_0->rot_speed.k[1] = (float)(this->cr_mult_inv0[1].k[1] * v5) + core_0->rot_speed.k[1];
    core_0->rot_speed.k[2] = (float)(this->cr_mult_inv0[1].k[2] * v5) + core_0->rot_speed.k[2];
  }
  if ( core_1 != nullptr )
  {
    v6 = -impulse_ds->k[0];
    core_1->rot_speed.k[0] = (float)(this->cr_mult_inv1[0].k[0] * v6) + core_1->rot_speed.k[0];
    core_1->rot_speed.k[1] = (float)(this->cr_mult_inv1[0].k[1] * v6) + core_1->rot_speed.k[1];
    core_1->rot_speed.k[2] = (float)(this->cr_mult_inv1[0].k[2] * v6) + core_1->rot_speed.k[2];
    v7 = -impulse_ds->k[1];
    core_1->rot_speed.k[0] = (float)(this->cr_mult_inv1[1].k[0] * v7) + core_1->rot_speed.k[0];
    core_1->rot_speed.k[1] = (float)(this->cr_mult_inv1[1].k[1] * v7) + core_1->rot_speed.k[1];
    core_1->rot_speed.k[2] = (float)(this->cr_mult_inv1[1].k[2] * v7) + core_1->rot_speed.k[2];
  }
}
