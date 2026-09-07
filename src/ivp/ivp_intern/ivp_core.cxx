// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_core.cxx
// Functions: 55
// ============================================================

#include "ivp\ivp_intern\ivp_core.h"

//------------------------------------------------------------------------------
// Address: 0x10073030
// Name: public: float IVP_U_Quat::inline_estimate_q_diff_to(class IVP_U_Float_Quat const __near *)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_U_Quat::inline_estimate_q_diff_to(IVP_U_Quat *this, const IVP_U_Float_Quat *to)
{
  double v2; // st7

  v2 = to->y * this->y + to->x * this->x + to->z * this->z + to->w * this->w;
  return 1.0 - v2 * v2 + 1.0 - v2 * v2;
}

//------------------------------------------------------------------------------
// Address: 0x10073060
// Name: public: void IVP_Core::get_surface_speed_on_test(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::get_surface_speed_on_test(
        IVP_Core *this,
        const IVP_U_Float_Point *point_cs,
        const IVP_U_Float_Point *center_speed_ws,
        const IVP_U_Float_Point *rot_speed_cs,
        IVP_U_Float_Point *speed_out_ws)
{
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float point_csa; // [esp+Ch] [ebp+8h]

  v5 = (float)(rot_speed_cs->k[1] * point_cs->k[2]) - (float)(rot_speed_cs->k[2] * point_cs->k[1]);
  v6 = (float)(rot_speed_cs->k[0] * point_cs->k[1]) - (float)(point_cs->k[0] * rot_speed_cs->k[1]);
  v7 = (float)(point_cs->k[0] * rot_speed_cs->k[2]) - (float)(rot_speed_cs->k[0] * point_cs->k[2]);
  point_csa = this->m_world_f_core_last_psi.rows[1].k[2];
  v8 = (float)(this->m_world_f_core_last_psi.rows[0].k[1] * v7)
     + (float)(v5 * this->m_world_f_core_last_psi.rows[0].k[0]);
  v9 = this->m_world_f_core_last_psi.rows[0].k[2];
  v10 = (float)(this->m_world_f_core_last_psi.rows[1].k[0] * v5)
      + (float)(this->m_world_f_core_last_psi.rows[1].k[1] * v7);
  v11 = (float)((float)(this->m_world_f_core_last_psi.rows[2].k[0] * v5)
              + (float)(this->m_world_f_core_last_psi.rows[2].k[1] * v7))
      + (float)(this->m_world_f_core_last_psi.rows[2].k[2] * v6);
  speed_out_ws->k[2] = v11;
  v12 = v8 + (float)(v9 * v6);
  speed_out_ws->k[0] = v12;
  v13 = v10 + (float)(point_csa * v6);
  speed_out_ws->k[1] = v13;
  v14 = center_speed_ws->k[1] + v13;
  v15 = center_speed_ws->k[2] + v11;
  speed_out_ws->k[0] = center_speed_ws->k[0] + v12;
  speed_out_ws->k[1] = v14;
  speed_out_ws->k[2] = v15;
}

//------------------------------------------------------------------------------
// Address: 0x10073180
// Name: public: void IVP_Core::get_surface_speed_ws(class IVP_U_Point const __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Core::get_surface_speed_ws(
        IVP_Core *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Point *position_ws_in,
        IVP_U_Float_Point *speed_ws_out)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12[3]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Float_Point av_ws; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  av_ws.k[1] = a2;
  av_ws.k[2] = retaddr;
  IVP_U_Matrix3::vmult3(this: &this->m_world_f_core_last_psi, p_in: &this->rot_speed, p_out: (IVP_U_Float_Point *)v12);
  v5 = position_ws_in->k[1] - this->m_world_f_core_last_psi.vv.k[1];
  v6 = position_ws_in->k[2] - this->m_world_f_core_last_psi.vv.k[2];
  v7 = position_ws_in->k[0] - this->m_world_f_core_last_psi.vv.k[0];
  v8 = (float)(v12[1] * v6) - (float)(v12[2] * v5);
  v9 = v12[1] * v7;
  v10 = this->speed.k[1] + (float)((float)(v12[2] * v7) - (float)(v12[0] * v6));
  v11 = this->speed.k[2] + (float)((float)(v12[0] * v5) - v9);
  speed_ws_out->k[0] = this->speed.k[0] + v8;
  speed_ws_out->k[1] = v10;
  speed_ws_out->k[2] = v11;
}

//------------------------------------------------------------------------------
// Address: 0x10073260
// Name: public: static void IVP_Core::get_diff_surface_speed_of_two_cores(class IVP_Core const __near *,class IVP_Core const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Core::get_diff_surface_speed_of_two_cores(
        const IVP_Core *this_core,
        const IVP_Core *other_core,
        const IVP_U_Float_Point *obj_point_this,
        const IVP_U_Float_Point *obj_point_other,
        IVP_U_Float_Point *delta_velocity_ws)
{
  float v6; // xmm4_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  IVP_U_Float_Point *v9; // esi
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // [esp+4h] [ebp-8h]
  float v36; // [esp+8h] [ebp-4h]
  float this_corea; // [esp+14h] [ebp+8h]

  if ( this_core == nullptr || (*(_WORD *)&this_core->IVP_Core_Fast_Static & 0x12) != 0 )
  {
    v9 = delta_velocity_ws;
    v22 = 0.0;
    delta_velocity_ws->k[2] = 0.0;
    delta_velocity_ws->k[0] = 0.0;
  }
  else
  {
    v6 = this_core->rot_speed.k[1];
    v7 = this_core->rot_speed.k[2];
    v8 = this_core->m_world_f_core_last_psi.rows[1].k[1];
    v9 = delta_velocity_ws;
    v10 = (float)(obj_point_this->k[2] * v6) - (float)(obj_point_this->k[1] * v7);
    v11 = (float)(obj_point_this->k[0] * v7) - (float)(this_core->rot_speed.k[0] * obj_point_this->k[2]);
    v12 = (float)(this_core->rot_speed.k[0] * obj_point_this->k[1]) - (float)(obj_point_this->k[0] * v6);
    v13 = this_core->m_world_f_core_last_psi.rows[1].k[0];
    v14 = this_core->m_world_f_core_last_psi.rows[0].k[0] * v10;
    v36 = this_core->m_world_f_core_last_psi.rows[2].k[1];
    v15 = this_core->m_world_f_core_last_psi.rows[2].k[2];
    this_corea = this_core->m_world_f_core_last_psi.rows[1].k[2];
    v35 = v15;
    v16 = (float)(this_core->m_world_f_core_last_psi.rows[0].k[1] * v11) + v14;
    v17 = this_core->m_world_f_core_last_psi.rows[0].k[2] * v12;
    v18 = (float)((float)(this_core->m_world_f_core_last_psi.rows[2].k[0] * v10) + (float)(v36 * v11))
        + (float)(v35 * v12);
    delta_velocity_ws->k[2] = v18;
    v19 = v16 + v17;
    delta_velocity_ws->k[0] = v19;
    v20 = (float)((float)(v13 * v10) + (float)(v8 * v11)) + (float)(this_corea * v12);
    delta_velocity_ws->k[1] = v20;
    v21 = this_core->speed.k[2] + v18;
    v22 = this_core->speed.k[1] + v20;
    delta_velocity_ws->k[0] = this_core->speed.k[0] + v19;
    delta_velocity_ws->k[2] = v21;
  }
  v9->k[1] = v22;
  if ( other_core != nullptr && (*(_WORD *)&other_core->IVP_Core_Fast_Static & 0x12) == 0 )
  {
    v23 = other_core->rot_speed.k[1];
    v24 = (float)(obj_point_other->k[2] * v23) - (float)(other_core->rot_speed.k[2] * obj_point_other->k[1]);
    v25 = other_core->rot_speed.k[0];
    v26 = (float)(other_core->rot_speed.k[2] * obj_point_other->k[0]) - (float)(obj_point_other->k[2] * v25);
    v27 = (float)(v25 * obj_point_other->k[1]) - (float)(v23 * obj_point_other->k[0]);
    v28 = (float)((float)(other_core->m_world_f_core_last_psi.rows[0].k[1] * v26)
                + (float)(other_core->m_world_f_core_last_psi.rows[0].k[0] * v24))
        + (float)(other_core->m_world_f_core_last_psi.rows[0].k[2] * v27);
    v29 = (float)((float)(other_core->m_world_f_core_last_psi.rows[1].k[0] * v24)
                + (float)(other_core->m_world_f_core_last_psi.rows[1].k[1] * v26))
        + (float)(other_core->m_world_f_core_last_psi.rows[1].k[2] * v27);
    v30 = (float)(other_core->m_world_f_core_last_psi.rows[2].k[0] * v24)
        + (float)(other_core->m_world_f_core_last_psi.rows[2].k[1] * v26);
    v31 = other_core->m_world_f_core_last_psi.rows[2].k[2] * v27;
    v32 = other_core->speed.k[2];
    v33 = v9->k[0] - (float)(other_core->speed.k[0] + v28);
    v9->k[1] = v9->k[1] - (float)(other_core->speed.k[1] + v29);
    v34 = v9->k[2] - (float)(v32 + (float)(v30 + v31));
    v9->k[0] = v33;
    v9->k[2] = v34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100734E0
// Name: public: static void IVP_Core::get_diff_surface_speed_of_two_cores_on_test(class IVP_Core const __near *,class IVP_Core const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Core::get_diff_surface_speed_of_two_cores_on_test(
        const IVP_Core *this_core,
        const IVP_Core *other_core,
        const IVP_U_Float_Point *obj_point_this,
        const IVP_U_Float_Point *obj_point_other,
        const IVP_U_Float_Point *trans_speed0,
        const IVP_U_Float_Point *rot_speed0,
        const IVP_U_Float_Point *trans_speed1,
        const IVP_U_Float_Point *rot_speed1,
        IVP_U_Float_Point *diff_speed_this_minus_other_out)
{
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm6_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // [esp-Ch] [ebp-1Ch]

  if ( (*(_WORD *)&this_core->IVP_Core_Fast_Static & 0x12) != 0 )
  {
    v18 = 0.0;
    v22 = 0.0;
    v21 = 0.0;
    v36 = 0.0;
    v20 = 0.0;
  }
  else
  {
    v11 = (float)(rot_speed0->k[1] * obj_point_this->k[2]) - (float)(rot_speed0->k[2] * obj_point_this->k[1]);
    v12 = (float)(rot_speed0->k[0] * obj_point_this->k[1]) - (float)(obj_point_this->k[0] * rot_speed0->k[1]);
    v13 = (float)(obj_point_this->k[0] * rot_speed0->k[2]) - (float)(rot_speed0->k[0] * obj_point_this->k[2]);
    v14 = (float)((float)(this_core->m_world_f_core_last_psi.rows[0].k[1] * v13)
                + (float)(this_core->m_world_f_core_last_psi.rows[0].k[0] * v11))
        + (float)(this_core->m_world_f_core_last_psi.rows[0].k[2] * v12);
    v15 = (float)((float)(this_core->m_world_f_core_last_psi.rows[1].k[0] * v11)
                + (float)(this_core->m_world_f_core_last_psi.rows[1].k[1] * v13))
        + (float)(this_core->m_world_f_core_last_psi.rows[1].k[2] * v12);
    v16 = this_core->m_world_f_core_last_psi.rows[2].k[0] * v11;
    v17 = this_core->m_world_f_core_last_psi.rows[2].k[1] * v13;
    v18 = 0.0;
    v19 = (float)(v16 + v17) + (float)(this_core->m_world_f_core_last_psi.rows[2].k[2] * v12);
    v20 = trans_speed0->k[0] + v14;
    v36 = v20;
    v21 = trans_speed0->k[1] + v15;
    v22 = trans_speed0->k[2] + v19;
  }
  if ( (*(_WORD *)&other_core->IVP_Core_Fast_Static & 0x12) != 0 )
  {
    v35 = 0.0;
    v33 = 0.0;
  }
  else
  {
    v25 = (float)(rot_speed1->k[1] * obj_point_other->k[2]) - (float)(rot_speed1->k[2] * obj_point_other->k[1]);
    v26 = (float)(obj_point_other->k[0] * rot_speed1->k[2]) - (float)(rot_speed1->k[0] * obj_point_other->k[2]);
    v27 = (float)(rot_speed1->k[0] * obj_point_other->k[1]) - (float)(obj_point_other->k[0] * rot_speed1->k[1]);
    v28 = (float)((float)(other_core->m_world_f_core_last_psi.rows[0].k[1] * v26)
                + (float)(other_core->m_world_f_core_last_psi.rows[0].k[0] * v25))
        + (float)(other_core->m_world_f_core_last_psi.rows[0].k[2] * v27);
    v29 = (float)((float)(other_core->m_world_f_core_last_psi.rows[1].k[1] * v26)
                + (float)(other_core->m_world_f_core_last_psi.rows[1].k[0] * v25))
        + (float)(other_core->m_world_f_core_last_psi.rows[1].k[2] * v27);
    v30 = other_core->m_world_f_core_last_psi.rows[2].k[1] * v26;
    v31 = other_core->m_world_f_core_last_psi.rows[2].k[0] * v25;
    v32 = other_core->m_world_f_core_last_psi.rows[2].k[2] * v27;
    v33 = trans_speed1->k[0] + v28;
    v34 = (float)(v30 + v31) + v32;
    v20 = v36;
    v35 = trans_speed1->k[1] + v29;
    v18 = trans_speed1->k[2] + v34;
  }
  diff_speed_this_minus_other_out->k[0] = v20 - v33;
  diff_speed_this_minus_other_out->k[1] = v21 - v35;
  diff_speed_this_minus_other_out->k[2] = v22 - v18;
}

//------------------------------------------------------------------------------
// Address: 0x10073720
// Name: public: float IVP_Core::calc_virt_mass_worst_case(class IVP_U_Float_Point const __near *)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Core::calc_virt_mass_worst_case(IVP_Core *this, const IVP_U_Float_Point *core_point)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4

  v2 = core_point->k[2] * core_point->k[2];
  v3 = core_point->k[0] * core_point->k[0];
  v4 = this->inv_rot_inertia.k[1] * (float)(v3 + v2);
  v5 = this->inv_rot_inertia.k[2] * (float)(v3 + (float)(core_point->k[1] * core_point->k[1]));
  v6 = this->inv_rot_inertia.k[0] * (float)((float)(core_point->k[1] * core_point->k[1]) + v2);
  if ( v4 > v6 )
    v6 = v4;
  if ( v5 > v6 )
    v6 = v5;
  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 0x10) != 0 )
    return 1.0 / (float)(v6 + 1.0);
  else
    return 1.0 / (float)(this->inv_rot_inertia.hesse_val + v6);
}

//------------------------------------------------------------------------------
// Address: 0x100737C0
// Name: public: float IVP_Core::calc_virt_mass(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)const
// Source: json
//------------------------------------------------------------------------------
long double __userpurge IVP_Core::calc_virt_mass@<st0>(
        IVP_Core *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Float_Point *core_point,
        IVP_U_Float_Point *direction)
{
  long double v5; // st7
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v12; // [esp-Ch] [ebp-2Ch] BYREF
  float v13; // [esp-8h] [ebp-28h]
  float v14; // [esp-4h] [ebp-24h]
  float v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  void *v17; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v16 = a2;
  v17 = retaddr;
  if ( direction != nullptr )
  {
    v5 = IVP_U_Float_Point::fast_real_length(this: direction);
    v15 = v5;
    if ( v5 <= 1.0e-10 )
    {
      v6 = 0.0;
      v8 = 0.0;
      v7 = 0.0;
    }
    else
    {
      v15 = 1.0 / v15;
      IVP_U_Float_Point::calc_cross_product(this: (IVP_U_Float_Point *)&v12, v1: direction, v2: core_point);
      v6 = v15 * v13;
      v7 = v12 * v15;
      v8 = v15 * v14;
    }
    v9 = this->inv_rot_inertia.k[0] * (float)(v7 * v7);
    v13 = this->inv_rot_inertia.k[1] * (float)(v6 * v6);
  }
  else
  {
    v8 = core_point->k[2];
    v9 = this->inv_rot_inertia.k[0] * (float)(core_point->k[0] * core_point->k[0]);
    v13 = this->inv_rot_inertia.k[1] * (float)(core_point->k[1] * core_point->k[1]);
  }
  v10 = this->inv_rot_inertia.k[2] * (float)(v8 * v8);
  v12 = v9;
  v14 = v10;
  return 1.0 / (IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&v12) + this->inv_rot_inertia.hesse_val);
}

//------------------------------------------------------------------------------
// Address: 0x100738D0
// Name: public: float IVP_Core::get_energy_on_test(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Core::get_energy_on_test(
        IVP_Core *this,
        const IVP_U_Float_Point *speed_vec,
        const IVP_U_Float_Point *rot_speed_vec)
{
  return ((speed_vec->k[1] * speed_vec->k[1] + speed_vec->k[0] * speed_vec->k[0] + speed_vec->k[2] * speed_vec->k[2])
        * this->rot_inertia.hesse_val
        + this->rot_inertia.k[1] * (float)(rot_speed_vec->k[1] * rot_speed_vec->k[1])
        + this->rot_inertia.k[0] * (float)(rot_speed_vec->k[0] * rot_speed_vec->k[0])
        + this->rot_inertia.k[2] * (float)(rot_speed_vec->k[2] * rot_speed_vec->k[2]))
       * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x10073960
// Name: public: void IVP_Core::set_radius(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::set_radius(IVP_Core *this, float upper_limit, float max_dev)
{
  this->upper_limit_radius = upper_limit;
  this->max_surface_deviation = max_dev;
}

//------------------------------------------------------------------------------
// Address: 0x10073980
// Name: public: void IVP_Core::calc_at_matrix(class IVP_Time,class IVP_U_Matrix __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Core::calc_at_matrix(
        IVP_Core *this@<ecx>,
        int a2@<ebp>,
        IVP_Time current_time,
        IVP_U_Matrix *m_world_f_core_out)
{
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  _BYTE v8[12]; // [esp+14h] [ebp-2Ch] BYREF
  float v9; // [esp+30h] [ebp-10h]
  int v10; // [esp+34h] [ebp-Ch]
  void *v11; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  v10 = a2;
  v11 = retaddr;
  if ( *((_BYTE *)&this->IVP_Core_Fast_Static + 1) >= 8u
    || (v5 = current_time.seconds - this->time_of_last_psi.seconds, v9 = v5, v5 == 0.0) )
  {
    *m_world_f_core_out = this->m_world_f_core_last_psi;
  }
  else
  {
    IVP_U_Quat::set_interpolate_smoothly(
      this: (IVP_U_Quat *)v8,
      a2: (int)this,
      from: &this->q_world_f_core_last_psi,
      to: &this->q_world_f_core_next_psi,
      t: this->i_delta_time * v5);
    IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)v8, mat: m_world_f_core_out);
    v6 = (float)(this->delta_world_f_core_psis.k[1] * v9) + this->pos_world_f_core_last_psi.k[1];
    v7 = (float)(this->delta_world_f_core_psis.k[2] * v9) + this->pos_world_f_core_last_psi.k[2];
    m_world_f_core_out->vv.k[0] = (float)(this->delta_world_f_core_psis.k[0] * v9)
                                + this->pos_world_f_core_last_psi.k[0];
    m_world_f_core_out->vv.k[1] = v6;
    m_world_f_core_out->vv.k[2] = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073A80
// Name: public: void IVP_Core::abort_all_async_pushes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::abort_all_async_pushes(IVP_Core *this)
{
  *(_QWORD *)&this->rot_speed_change.k[1] = 0;
  this->rot_speed_change.k[0] = 0.0;
  *(_QWORD *)&this->speed_change.k[1] = 0;
  this->speed_change.k[0] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10073AC0
// Name: public: void IVP_Core::center_push_core_multiple_ws(class IVP_U_Float_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::center_push_core_multiple_ws(
        IVP_Core *this,
        const IVP_U_Float_Point *delta_speed,
        float factor)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v3 = this->inv_rot_inertia.hesse_val * factor;
  v4 = (float)(delta_speed->k[1] * v3) + this->speed.k[1];
  v5 = (float)(delta_speed->k[2] * v3) + this->speed.k[2];
  this->speed.k[0] = (float)(delta_speed->k[0] * v3) + this->speed.k[0];
  this->speed.k[1] = v4;
  this->speed.k[2] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10073B20
// Name: public: void IVP_Core::damp_object(float,class IVP_U_Float_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Core::damp_object(
        IVP_Core *this@<ecx>,
        int a2@<esi>,
        float delta_time_,
        const IVP_U_Float_Point *rotation_factor,
        float speed_factor)
{
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  long double v17; // [esp-1Ch] [ebp-3Ch]
  long double v18; // [esp-1Ch] [ebp-3Ch]
  long double v19; // [esp-1Ch] [ebp-3Ch]
  float rot_4; // [esp+4h] [ebp-1Ch]
  float rot_8; // [esp+8h] [ebp-18h]

  LODWORD(v17) = a2;
  v6 = delta_time_;
  v7 = rotation_factor->k[1] * delta_time_;
  v8 = rotation_factor->k[0] * delta_time_;
  v9 = rotation_factor->k[2] * delta_time_;
  if ( (float)((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9)) >= 0.5 )
  {
    __libm_sse2_exp(x: v17);
    LODWORD(rot_4) = LODWORD(v8) ^ _mask__NegFloat_;
    __libm_sse2_exp(x: v18);
    LODWORD(rot_8) = LODWORD(v7) ^ _mask__NegFloat_;
    __libm_sse2_exp(x: v19);
    LODWORD(v10) = LODWORD(v8) ^ _mask__NegFloat_;
    v6 = delta_time_;
    LODWORD(v11) = LODWORD(v7) ^ _mask__NegFloat_;
    LODWORD(v12) = LODWORD(v9) ^ _mask__NegFloat_;
  }
  else
  {
    v10 = 1.0 - v8;
    v11 = 1.0 - v7;
    rot_4 = 1.0 - v8;
    rot_8 = 1.0 - v7;
    v12 = 1.0 - v9;
  }
  v13 = v6 * speed_factor;
  if ( v13 >= 0.25 )
  {
    __libm_sse2_exp(x: v17);
    v10 = rot_4;
    v11 = rot_8;
    LODWORD(v14) = LODWORD(v13) ^ _mask__NegFloat_;
  }
  else
  {
    v14 = 1.0 - v13;
  }
  v15 = this->rot_speed.k[1];
  v16 = this->rot_speed.k[2] * v12;
  this->rot_speed.k[0] = this->rot_speed.k[0] * v10;
  this->rot_speed.k[2] = v16;
  this->rot_speed.k[1] = v15 * v11;
  this->speed.k[0] = this->speed.k[0] * v14;
  this->speed.k[1] = this->speed.k[1] * v14;
  this->speed.k[2] = this->speed.k[2] * v14;
}

//------------------------------------------------------------------------------
// Address: 0x10073CF0
// Name: public: void IVP_Core::get_surface_speed(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::get_surface_speed(
        IVP_Core *this,
        const IVP_U_Float_Point *point_core,
        IVP_U_Float_Point *speed_world_out)
{
  float v3; // xmm4_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float point_corea; // [esp+10h] [ebp+8h]

  v3 = this->rot_speed.k[1];
  v4 = this->rot_speed.k[2];
  v5 = (float)(point_core->k[2] * v3) - (float)(point_core->k[1] * v4);
  v6 = (float)(point_core->k[0] * v4) - (float)(this->rot_speed.k[0] * point_core->k[2]);
  v7 = (float)(this->rot_speed.k[0] * point_core->k[1]) - (float)(point_core->k[0] * v3);
  point_corea = this->m_world_f_core_last_psi.rows[1].k[2];
  v8 = (float)(this->m_world_f_core_last_psi.rows[0].k[1] * v6)
     + (float)(this->m_world_f_core_last_psi.rows[0].k[0] * v5);
  v9 = (float)(this->m_world_f_core_last_psi.rows[1].k[0] * v5)
     + (float)(this->m_world_f_core_last_psi.rows[1].k[1] * v6);
  v10 = this->m_world_f_core_last_psi.rows[0].k[2] * v7;
  v11 = (float)((float)(this->m_world_f_core_last_psi.rows[2].k[0] * v5)
              + (float)(this->m_world_f_core_last_psi.rows[2].k[1] * v6))
      + (float)(this->m_world_f_core_last_psi.rows[2].k[2] * v7);
  speed_world_out->k[2] = v11;
  v12 = v8 + v10;
  speed_world_out->k[0] = v12;
  v13 = v9 + (float)(point_corea * v7);
  speed_world_out->k[1] = v13;
  v14 = this->speed.k[1] + v13;
  v15 = this->speed.k[2] + v11;
  speed_world_out->k[0] = this->speed.k[0] + v12;
  speed_world_out->k[1] = v14;
  speed_world_out->k[2] = v15;
}

//------------------------------------------------------------------------------
// Address: 0x10073E30
// Name: public: void IVP_Core::push_core_ws(class IVP_U_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Core::push_core_ws(
        IVP_Core *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Point *world_point,
        const IVP_U_Float_Point *impulse_in_world)
{
  float v5; // xmm2_4
  float v6; // xmm0_4
  float hesse_val; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point cross_point_dir; // [esp+0h] [ebp-20h] BYREF
  IVP_U_Float_Point point_d_ws; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  point_d_ws.k[1] = a2;
  point_d_ws.k[2] = retaddr;
  cross_point_dir.k[1] = world_point->k[0] - this->m_world_f_core_last_psi.vv.k[0];
  cross_point_dir.k[2] = world_point->k[1] - this->m_world_f_core_last_psi.vv.k[1];
  cross_point_dir.hesse_val = world_point->k[2] - this->m_world_f_core_last_psi.vv.k[2];
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)v10,
    v1: (IVP_U_Float_Point *)&cross_point_dir.k[1],
    v2: impulse_in_world);
  v5 = this->inv_rot_inertia.k[1]
     * (float)((float)((float)(this->m_world_f_core_last_psi.rows[1].k[1] * v10[1])
                     + (float)(this->m_world_f_core_last_psi.rows[0].k[1] * v10[0]))
             + (float)(this->m_world_f_core_last_psi.rows[2].k[1] * v10[2]));
  v6 = this->inv_rot_inertia.k[2]
     * (float)((float)((float)(this->m_world_f_core_last_psi.rows[1].k[2] * v10[1])
                     + (float)(this->m_world_f_core_last_psi.rows[0].k[2] * v10[0]))
             + (float)(this->m_world_f_core_last_psi.rows[2].k[2] * v10[2]));
  this->rot_speed.k[0] = this->rot_speed.k[0]
                       + (float)(this->inv_rot_inertia.k[0]
                               * (float)((float)((float)(this->m_world_f_core_last_psi.rows[1].k[0] * v10[1])
                                               + (float)(this->m_world_f_core_last_psi.rows[0].k[0] * v10[0]))
                                       + (float)(this->m_world_f_core_last_psi.rows[2].k[0] * v10[2])));
  this->rot_speed.k[1] = this->rot_speed.k[1] + v5;
  this->rot_speed.k[2] = this->rot_speed.k[2] + v6;
  hesse_val = this->inv_rot_inertia.hesse_val;
  v8 = (float)(impulse_in_world->k[1] * hesse_val) + this->speed.k[1];
  v9 = (float)(impulse_in_world->k[2] * hesse_val) + this->speed.k[2];
  this->speed.k[0] = (float)(impulse_in_world->k[0] * hesse_val) + this->speed.k[0];
  this->speed.k[1] = v8;
  this->speed.k[2] = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10073FD0
// Name: public: void IVP_Core::async_push_core_ws(class IVP_U_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Core::async_push_core_ws(
        IVP_Core *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Point *world_point,
        const IVP_U_Float_Point *impulse_in_world)
{
  float v5; // xmm2_4
  float v6; // xmm0_4
  float hesse_val; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point cross_point_dir; // [esp+0h] [ebp-20h] BYREF
  IVP_U_Float_Point point_d_ws; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  point_d_ws.k[1] = a2;
  point_d_ws.k[2] = retaddr;
  cross_point_dir.k[1] = world_point->k[0] - this->m_world_f_core_last_psi.vv.k[0];
  cross_point_dir.k[2] = world_point->k[1] - this->m_world_f_core_last_psi.vv.k[1];
  cross_point_dir.hesse_val = world_point->k[2] - this->m_world_f_core_last_psi.vv.k[2];
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)v10,
    v1: (IVP_U_Float_Point *)&cross_point_dir.k[1],
    v2: impulse_in_world);
  v5 = this->inv_rot_inertia.k[1]
     * (float)((float)((float)(this->m_world_f_core_last_psi.rows[1].k[1] * v10[1])
                     + (float)(this->m_world_f_core_last_psi.rows[0].k[1] * v10[0]))
             + (float)(this->m_world_f_core_last_psi.rows[2].k[1] * v10[2]));
  v6 = this->inv_rot_inertia.k[2]
     * (float)((float)((float)(this->m_world_f_core_last_psi.rows[1].k[2] * v10[1])
                     + (float)(this->m_world_f_core_last_psi.rows[0].k[2] * v10[0]))
             + (float)(this->m_world_f_core_last_psi.rows[2].k[2] * v10[2]));
  this->rot_speed_change.k[0] = this->rot_speed_change.k[0]
                              + (float)(this->inv_rot_inertia.k[0]
                                      * (float)((float)((float)(this->m_world_f_core_last_psi.rows[1].k[0] * v10[1])
                                                      + (float)(this->m_world_f_core_last_psi.rows[0].k[0] * v10[0]))
                                              + (float)(this->m_world_f_core_last_psi.rows[2].k[0] * v10[2])));
  this->rot_speed_change.k[1] = this->rot_speed_change.k[1] + v5;
  this->rot_speed_change.k[2] = this->rot_speed_change.k[2] + v6;
  hesse_val = this->inv_rot_inertia.hesse_val;
  v8 = (float)(impulse_in_world->k[1] * hesse_val) + this->speed_change.k[1];
  v9 = (float)(impulse_in_world->k[2] * hesse_val) + this->speed_change.k[2];
  this->speed_change.k[0] = (float)(impulse_in_world->k[0] * hesse_val) + this->speed_change.k[0];
  this->speed_change.k[1] = v8;
  this->speed_change.k[2] = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10074170
// Name: public: void IVP_Core::async_rot_push_core_multiple_ws(class IVP_U_Float_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Core::async_rot_push_core_multiple_ws(
        IVP_Core *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Float_Point *angular_impulse_ws,
        float factor)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7[3]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Float_Point angular_impulse_cs; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  angular_impulse_cs.k[1] = a2;
  angular_impulse_cs.k[2] = retaddr;
  IVP_U_Matrix3::vimult3(this: &this->m_world_f_core_last_psi, p_in: angular_impulse_ws, p_out: (IVP_U_Float_Point *)v7);
  v5 = (float)((float)(this->inv_rot_inertia.k[1] * v7[1]) * factor) + this->rot_speed_change.k[1];
  v6 = (float)((float)(this->inv_rot_inertia.k[2] * v7[2]) * factor) + this->rot_speed_change.k[2];
  this->rot_speed_change.k[0] = (float)((float)(v7[0] * this->inv_rot_inertia.k[0]) * factor)
                              + this->rot_speed_change.k[0];
  this->rot_speed_change.k[1] = v5;
  this->rot_speed_change.k[2] = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10074210
// Name: public: void IVP_Core::test_push_core(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::test_push_core(
        IVP_Core *this,
        const IVP_U_Float_Point *point_cs,
        const IVP_U_Float_Point *impulse_in_core,
        const IVP_U_Float_Point *impulse_in_world,
        IVP_U_Float_Point *speed_out,
        IVP_U_Float_Point *rot_out)
{
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float hesse_val; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4

  v6 = (float)(impulse_in_core->k[2] * point_cs->k[1]) - (float)(impulse_in_core->k[1] * point_cs->k[2]);
  v7 = this->inv_rot_inertia.k[2]
     * (float)((float)(point_cs->k[0] * impulse_in_core->k[1]) - (float)(impulse_in_core->k[0] * point_cs->k[1]));
  v8 = this->inv_rot_inertia.k[0];
  rot_out->k[1] = this->inv_rot_inertia.k[1]
                * (float)((float)(impulse_in_core->k[0] * point_cs->k[2])
                        - (float)(point_cs->k[0] * impulse_in_core->k[2]));
  rot_out->k[2] = v7;
  rot_out->k[0] = v8 * v6;
  hesse_val = this->inv_rot_inertia.hesse_val;
  v10 = impulse_in_world->k[1] * hesse_val;
  v11 = impulse_in_world->k[2] * hesse_val;
  speed_out->k[0] = impulse_in_world->k[0] * hesse_val;
  speed_out->k[1] = v10;
  speed_out->k[2] = v11;
}

//------------------------------------------------------------------------------
// Address: 0x100742C0
// Name: public: void IVP_Core::test_rot_push_core_multiple_cs(class IVP_U_Float_Point const __near *,float,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::test_rot_push_core_multiple_cs(
        IVP_Core *this,
        const IVP_U_Float_Point *normized_core_axis,
        float rot_impulse,
        IVP_U_Float_Point *delta_rot_speed_out)
{
  float v4; // xmm1_4
  float v5; // xmm2_4

  v4 = (float)(this->inv_rot_inertia.k[1] * normized_core_axis->k[1]) * rot_impulse;
  v5 = (float)(this->inv_rot_inertia.k[2] * normized_core_axis->k[2]) * rot_impulse;
  delta_rot_speed_out->k[0] = (float)(this->inv_rot_inertia.k[0] * normized_core_axis->k[0]) * rot_impulse;
  delta_rot_speed_out->k[1] = v4;
  delta_rot_speed_out->k[2] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10074310
// Name: public: float IVP_Core::get_rot_speed_cs(class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Core::get_rot_speed_cs(IVP_Core *this, const IVP_U_Float_Point *normized_core_axis)
{
  return this->rot_speed.k[1] * normized_core_axis->k[1]
       + this->rot_speed.k[0] * normized_core_axis->k[0]
       + this->rot_speed.k[2] * normized_core_axis->k[2];
}

//------------------------------------------------------------------------------
// Address: 0x10074340
// Name: public: void IVP_Core::async_rot_push_core_multiple_cs(class IVP_U_Float_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::async_rot_push_core_multiple_cs(
        IVP_Core *this,
        const IVP_U_Float_Point *normized_core_axis,
        float rot_impulse)
{
  float v3; // xmm1_4
  float v4; // xmm2_4

  v3 = (float)((float)(this->inv_rot_inertia.k[1] * normized_core_axis->k[1]) * rot_impulse)
     + this->rot_speed_change.k[1];
  v4 = (float)((float)(this->inv_rot_inertia.k[2] * normized_core_axis->k[2]) * rot_impulse)
     + this->rot_speed_change.k[2];
  this->rot_speed_change.k[0] = (float)((float)(this->inv_rot_inertia.k[0] * normized_core_axis->k[0]) * rot_impulse)
                              + this->rot_speed_change.k[0];
  this->rot_speed_change.k[1] = v3;
  this->rot_speed_change.k[2] = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100743B0
// Name: public: void IVP_Core::rot_push_core_multiple_cs(class IVP_U_Float_Point const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::rot_push_core_multiple_cs(
        IVP_Core *this,
        const IVP_U_Float_Point *normized_core_axis,
        float rot_impulse)
{
  float v3; // xmm1_4
  float v4; // xmm2_4

  v3 = (float)((float)(this->inv_rot_inertia.k[1] * normized_core_axis->k[1]) * rot_impulse) + this->rot_speed.k[1];
  v4 = (float)((float)(this->inv_rot_inertia.k[2] * normized_core_axis->k[2]) * rot_impulse) + this->rot_speed.k[2];
  this->rot_speed.k[0] = (float)((float)(this->inv_rot_inertia.k[0] * normized_core_axis->k[0]) * rot_impulse)
                       + this->rot_speed.k[0];
  this->rot_speed.k[1] = v3;
  this->rot_speed.k[2] = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10074420
// Name: public: void IVP_Core::rot_push_core_cs(class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::rot_push_core_cs(IVP_Core *this, const IVP_U_Float_Point *rot_impulse_cs)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = (float)(this->inv_rot_inertia.k[1] * rot_impulse_cs->k[1]) + this->rot_speed.k[1];
  v3 = (float)(this->inv_rot_inertia.k[2] * rot_impulse_cs->k[2]) + this->rot_speed.k[2];
  this->rot_speed.k[0] = this->rot_speed.k[0] + (float)(this->inv_rot_inertia.k[0] * rot_impulse_cs->k[0]);
  this->rot_speed.k[1] = v2;
  this->rot_speed.k[2] = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10074480
// Name: public: void IVP_Core::calc_next_PSI_matrix_zero_speed(class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::calc_next_PSI_matrix_zero_speed(IVP_Core *this, IVP_Event_Sim *es)
{
  double i_delta_time; // st7

  i_delta_time = es->i_delta_time;
  *(_QWORD *)&this->q_world_f_core_next_psi.x = *(_QWORD *)&this->q_world_f_core_last_psi.x;
  this->i_delta_time = i_delta_time;
  *(_QWORD *)&this->q_world_f_core_next_psi.z = *(_QWORD *)&this->q_world_f_core_last_psi.z;
  this->abs_omega = 0.0;
  *(_QWORD *)&this->speed.k[1] = 0;
  this->speed.k[0] = 0.0;
  *(_QWORD *)&this->delta_world_f_core_psis.k[1] = 0;
  this->delta_world_f_core_psis.k[0] = 0.0;
  this->current_speed = 0.0;
  this->max_surface_rot_speed = 0.0;
  this->rotation_axis_world_space.k[0] = 1.0;
  this->rotation_axis_world_space.k[1] = 0.0;
  this->rotation_axis_world_space.k[2] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10074520
// Name: public: void IVP_Core::stop_movement_without_collision_recheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::stop_movement_without_collision_recheck(IVP_Core *this)
{
  double inv_delta_PSI_time; // st7

  *((_BYTE *)&this->IVP_Core_Fast_Static + 1) = 8;
  *(_QWORD *)&this->speed.k[1] = 0;
  this->speed.k[0] = 0.0;
  *(_QWORD *)&this->rot_speed.k[1] = 0;
  this->rot_speed.k[0] = 0.0;
  *(_QWORD *)&this->speed_change.k[1] = 0;
  this->speed_change.k[0] = 0.0;
  *(_QWORD *)&this->rot_speed_change.k[1] = 0;
  this->rot_speed_change.k[0] = 0.0;
  *(_QWORD *)&this->delta_world_f_core_psis.k[1] = 0;
  this->delta_world_f_core_psis.k[0] = 0.0;
  inv_delta_PSI_time = this->environment->inv_delta_PSI_time;
  *(_QWORD *)&this->q_world_f_core_next_psi.x = *(_QWORD *)&this->q_world_f_core_last_psi.x;
  this->i_delta_time = inv_delta_PSI_time;
  *(_QWORD *)&this->q_world_f_core_next_psi.z = *(_QWORD *)&this->q_world_f_core_last_psi.z;
  this->abs_omega = 0.0;
  *(_QWORD *)&this->speed.k[1] = 0;
  this->speed.k[0] = 0.0;
  *(_QWORD *)&this->delta_world_f_core_psis.k[1] = 0;
  this->delta_world_f_core_psis.k[0] = 0.0;
  this->current_speed = 0.0;
  this->max_surface_rot_speed = 0.0;
  this->rotation_axis_world_space.k[0] = 1.0;
  this->rotation_axis_world_space.k[1] = 0.0;
  this->rotation_axis_world_space.k[2] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10074640
// Name: public: void IVP_Core::reset_freeze_check_values(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::reset_freeze_check_values(IVP_Core *this)
{
  long double seconds; // xmm0_8

  seconds = this->environment->current_time.seconds;
  this->time_of_calm_reference[0].seconds = seconds;
  this->time_of_calm_reference[1].seconds = seconds;
}

//------------------------------------------------------------------------------
// Address: 0x100746A0
// Name: public: void IVP_Core::synchronize_with_rot_z(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall IVP_Core::synchronize_with_rot_z(IVP_Core *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  IVP_U_Memory *sim_unit_mem; // ecx
  char *speicherbeginn; // edx
  unsigned int v7; // eax
  char *v8; // eax
  IVP_Environment *environment; // eax
  unsigned int seconds_low; // ecx
  unsigned int seconds_high; // edx
  IVP_Core::<unnamed_type_tmp_null> v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  IVP_Core::<unnamed_type_tmp_null> v15; // eax
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  double v19; // xmm0_8
  double v20; // xmm0_8
  double v21; // xmm0_8
  long double v22; // [esp+4h] [ebp-3Ch]
  long double v23; // [esp+4h] [ebp-3Ch]
  long double v24; // [esp+4h] [ebp-3Ch]
  float v25[3]; // [esp+14h] [ebp-2Ch] BYREF
  double q_core_f_core_12; // [esp+2Ch] [ebp-14h] OVERLAPPED
  int v27; // [esp+34h] [ebp-Ch]
  float f; // [esp+38h] [ebp-8h]
  float retaddr; // [esp+40h] [ebp+0h]

  v27 = a2;
  f = retaddr;
  HIDWORD(v22) = a4;
  sim_unit_mem = this->environment->sim_unit_mem;
  speicherbeginn = sim_unit_mem->speicherbeginn;
  v7 = (unsigned int)(speicherbeginn + 79) & 0xFFFFFFE0;
  LODWORD(v22) = a3;
  if ( (char *)v7 < sim_unit_mem->speicherende )
  {
    sim_unit_mem->speicherbeginn = (char *)v7;
    v8 = speicherbeginn;
  }
  else
  {
    v8 = IVP_U_Memory::neuer_sp_block(this: sim_unit_mem, groesse: 0x30u);
  }
  this->tmp_null.old_sync_info = (IVP_Old_Sync_Rot_Z *)v8;
  *((_DWORD *)v8 + 8) = 0;
  environment = this->environment;
  seconds_low = LODWORD(environment->current_time.seconds);
  seconds_high = HIDWORD(environment->current_time.seconds);
  v12.old_sync_info = (IVP_Old_Sync_Rot_Z *)this->tmp_null;
  v13 = this->rot_speed.k[1];
  v14 = this->rot_speed.k[2];
  v12.old_sync_info->old_sync_rot_speed.k[0] = this->rot_speed.k[0];
  v12.old_sync_info->old_sync_rot_speed.k[1] = v13;
  v12.old_sync_info->old_sync_rot_speed.k[2] = v14;
  v15.old_sync_info = (IVP_Old_Sync_Rot_Z *)this->tmp_null;
  *(_QWORD *)&v15.old_sync_info->old_sync_q_world_f_core_next_psi.x = *(_QWORD *)&this->q_world_f_core_next_psi.x;
  *(_QWORD *)&v15.old_sync_info->old_sync_q_world_f_core_next_psi.z = *(_QWORD *)&this->q_world_f_core_next_psi.z;
  q_core_f_core_12 = COERCE_DOUBLE(__PAIR64__(seconds_high, seconds_low));
  IVP_U_Quat::set_invert_mult(
    this: (IVP_U_Quat *)v25,
    q1: &this->q_world_f_core_last_psi,
    q2: &this->q_world_f_core_next_psi);
  IVP_U_Quat::set_interpolate_smoothly(
    this: &this->q_world_f_core_next_psi,
    a2: (int)this,
    from: &this->q_world_f_core_last_psi,
    to: &this->q_world_f_core_next_psi,
    t: (float)(q_core_f_core_12 - this->time_of_last_psi.seconds) * this->i_delta_time);
  IVP_U_Quat::set_matrix(this: &this->q_world_f_core_next_psi, mat: &this->m_world_f_core_last_psi);
  v16 = q_core_f_core_12 - this->time_of_last_psi.seconds;
  v17 = (float)(this->delta_world_f_core_psis.k[1] * v16) + this->pos_world_f_core_last_psi.k[1];
  v18 = (float)(this->delta_world_f_core_psis.k[2] * v16) + this->pos_world_f_core_last_psi.k[2];
  this->m_world_f_core_last_psi.vv.k[0] = (float)(this->delta_world_f_core_psis.k[0] * v16)
                                        + this->pos_world_f_core_last_psi.k[0];
  this->m_world_f_core_last_psi.vv.k[1] = v17;
  this->m_world_f_core_last_psi.vv.k[2] = v18;
  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 8) == 0 )
  {
    *((float *)&q_core_f_core_12 + 1) = this->i_delta_time * 2.0;
    v19 = v25[0];
    __libm_sse2_asin(x: v22);
    *(float *)&v19 = v19;
    this->rot_speed.k[0] = *(float *)&v19 * *((float *)&q_core_f_core_12 + 1);
    v20 = v25[1];
    __libm_sse2_asin(x: v23);
    *(float *)&v20 = v20;
    this->rot_speed.k[1] = *(float *)&v20 * *((float *)&q_core_f_core_12 + 1);
    v21 = v25[2];
    __libm_sse2_asin(x: v24);
    *(float *)&v21 = v21;
    this->rot_speed.k[2] = *(float *)&v21 * *((float *)&q_core_f_core_12 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074880
// Name: public: void IVP_Core::undo_synchronize_rot_z(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::undo_synchronize_rot_z(IVP_Core *this)
{
  IVP_Core::<unnamed_type_tmp_null> v1; // eax
  float v2; // xmm0_4
  float v3; // xmm1_4

  v1.old_sync_info = (IVP_Old_Sync_Rot_Z *)this->tmp_null;
  v2 = v1.old_sync_info->old_sync_rot_speed.k[1];
  v3 = v1.old_sync_info->old_sync_rot_speed.k[2];
  this->rot_speed.k[0] = v1.old_sync_info->old_sync_rot_speed.k[0];
  this->rot_speed.k[1] = v2;
  this->rot_speed.k[2] = v3;
  this->q_world_f_core_next_psi = this->tmp_null.old_sync_info->old_sync_q_world_f_core_next_psi;
  this->tmp_null.old_sync_info = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100748E0
// Name: public: void IVP_Core::calc_calc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::calc_calc(IVP_Core *this)
{
  IVP_U_Float_Hesse *p_rot_inertia; // esi
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  int i; // [esp+10h] [ebp-4h]

  p_rot_inertia = &this->rot_inertia;
  for ( i = 3; i != 0; --i )
  {
    if ( _finite(x: p_rot_inertia->k[0]) != 0 && p_rot_inertia->k[0] <= 9.9999998e17 )
    {
      if ( p_rot_inertia->k[0] < -9.9999998e17 )
        p_rot_inertia->k[0] = -9.9999998e17;
    }
    else
    {
      p_rot_inertia->k[0] = 9.9999998e17;
    }
    p_rot_inertia = (IVP_U_Float_Hesse *)((char *)p_rot_inertia + 4);
  }
  v3 = 1.0 / this->rot_inertia.k[1];
  v4 = 1.0 / this->rot_inertia.k[2];
  v5 = 1.0 / this->rot_inertia.k[0];
  this->inv_rot_inertia.k[0] = v5;
  this->inv_rot_inertia.k[1] = v3;
  this->inv_rot_inertia.k[2] = v4;
  this->inv_rot_inertia.hesse_val = 1.0 / this->rot_inertia.hesse_val;
  if ( (float)((float)((float)((float)(v5 * v5) + (float)(v3 * v3)) + (float)(v4 * v4)) * 0.010000001) <= (float)((float)((float)((float)(v3 - v4) * (float)(v3 - v4)) + (float)((float)(v4 - v5) * (float)(v4 - v5))) + (float)((float)(v5 - v3) * (float)(v5 - v3))) )
    *(_WORD *)&this->IVP_Core_Fast_Static &= ~8u;
  else
    *(_WORD *)&this->IVP_Core_Fast_Static |= 8u;
  this->inv_object_diameter = 0.5 / this->upper_limit_radius;
}

//------------------------------------------------------------------------------
// Address: 0x100749F0
// Name: public: void IVP_Core::transform_PSI_matrizes_core(class IVP_U_Matrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::transform_PSI_matrizes_core(IVP_Core *this, const IVP_U_Matrix *m_core_f_core)
{
  IVP_U_Matrix *p_m_world_f_core_last_psi; // edi
  float v4; // xmm0_4
  float v5; // xmm1_4

  p_m_world_f_core_last_psi = &this->m_world_f_core_last_psi;
  IVP_U_Matrix::mmult4(this: &this->m_world_f_core_last_psi, mb: m_core_f_core, m_out: &this->m_world_f_core_last_psi);
  v4 = this->m_world_f_core_last_psi.vv.k[1];
  v5 = this->m_world_f_core_last_psi.vv.k[2];
  this->pos_world_f_core_last_psi.k[0] = this->m_world_f_core_last_psi.vv.k[0];
  this->pos_world_f_core_last_psi.k[1] = v4;
  this->pos_world_f_core_last_psi.k[2] = v5;
  IVP_U_Quat::set_quaternion(this: &this->q_world_f_core_last_psi, mat: p_m_world_f_core_last_psi);
  this->q_world_f_core_next_psi = this->q_world_f_core_last_psi;
}

//------------------------------------------------------------------------------
// Address: 0x10074A70
// Name: public: enum IVP_Movement_Type IVP_Core::calc_movement_state(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge IVP_Core::calc_movement_state@<eax>(IVP_Core *this@<ecx>, int a2@<ebp>, IVP_Time psi_time)
{
  double seconds; // xmm4_8
  float y; // xmm0_4
  IVP_U_Quat *p_q_world_f_core_next_psi; // ecx
  float v7; // xmm0_4
  float v8; // xmm2_4
  float freeze_check_dtime; // xmm1_4
  double v10; // st7
  double x; // st7
  int v12; // ecx
  float v13; // xmm0_4
  double v14; // st7
  float v15; // xmm0_4
  double v16; // st7
  int v17; // eax
  float v18; // xmm0_4
  float v19; // xmm1_4
  _DWORD v21[3]; // [esp-Ch] [ebp-2Ch] BYREF
  _BYTE tmp[20]; // [esp+0h] [ebp-20h] OVERLAPPED
  int v23; // [esp+14h] [ebp-Ch]
  void *v24; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  seconds = psi_time.seconds;
  if ( (float)((float)((float)((float)(this->pos_world_f_core_last_psi.k[1]
                                     - this->position_world_f_core_calm_reference[0].k[1])
                             * (float)(this->pos_world_f_core_last_psi.k[1]
                                     - this->position_world_f_core_calm_reference[0].k[1]))
                     + (float)((float)(this->pos_world_f_core_last_psi.k[0]
                                     - this->position_world_f_core_calm_reference[0].k[0])
                             * (float)(this->pos_world_f_core_last_psi.k[0]
                                     - this->position_world_f_core_calm_reference[0].k[0])))
             + (float)((float)(this->pos_world_f_core_last_psi.k[2] - this->position_world_f_core_calm_reference[0].k[2])
                     * (float)(this->pos_world_f_core_last_psi.k[2] - this->position_world_f_core_calm_reference[0].k[2]))) > 0.000099999997 )
    goto LABEL_7;
  y = this->q_world_f_core_next_psi.y;
  p_q_world_f_core_next_psi = &this->q_world_f_core_next_psi;
  v7 = (float)((float)((float)(y * this->q_world_f_core_calm_reference[0].y)
                     + (float)(this->q_world_f_core_calm_reference[0].x * this->q_world_f_core_next_psi.x))
             + (float)(this->q_world_f_core_next_psi.z * this->q_world_f_core_calm_reference[0].z))
     + (float)(this->q_world_f_core_next_psi.w * this->q_world_f_core_calm_reference[0].w);
  v8 = (float)((float)((float)(1.0 - (float)(v7 * v7)) * 2.0) * this->upper_limit_radius) * this->upper_limit_radius;
  *(float *)&tmp[16] = this->upper_limit_radius;
  if ( v8 > 0.000024999999 )
    goto LABEL_7;
  freeze_check_dtime = this->environment->freeze_manager.freeze_check_dtime;
  if ( (float)(psi_time.seconds - this->time_of_calm_reference[0].seconds) > freeze_check_dtime )
  {
    if ( (float)((float)((float)(this->rot_speed.k[0] * this->rot_speed.k[0])
                       + (float)(this->rot_speed.k[1] * this->rot_speed.k[1]))
               + (float)(this->rot_speed.k[2] * this->rot_speed.k[2])) <= (float)((float)((float)(3.1415927
                                                                                                / freeze_check_dtime)
                                                                                        * 0.75)
                                                                                * (float)((float)(3.1415927
                                                                                                / freeze_check_dtime)
                                                                                        * 0.75)) )
      return 3;
    v21[0] = LODWORD(this->q_world_f_core_last_psi.x);
    v21[1] = LODWORD(this->q_world_f_core_last_psi.y);
    v21[2] = LODWORD(this->q_world_f_core_last_psi.z);
    *(float *)tmp = this->q_world_f_core_last_psi.w;
    v10 = IVP_U_Quat::inline_estimate_q_diff_to(this: p_q_world_f_core_next_psi, to: (const IVP_U_Float_Quat *)v21);
    if ( v10 * *(float *)&tmp[16] * *(float *)&tmp[16] <= 0.000024999999 )
      return 3;
    seconds = psi_time.seconds;
LABEL_7:
    x = this->q_world_f_core_next_psi.x;
    *(double *)&tmp[12] = seconds;
    this->q_world_f_core_calm_reference[0].x = x;
    v12 = *(_DWORD *)&tmp[16];
    this->q_world_f_core_calm_reference[0].y = this->q_world_f_core_next_psi.y;
    this->q_world_f_core_calm_reference[0].z = this->q_world_f_core_next_psi.z;
    this->q_world_f_core_calm_reference[0].w = this->q_world_f_core_next_psi.w;
    v13 = this->pos_world_f_core_last_psi.k[1];
    v14 = this->pos_world_f_core_last_psi.k[0];
    this->position_world_f_core_calm_reference[0].k[2] = this->pos_world_f_core_last_psi.k[2];
    this->position_world_f_core_calm_reference[0].k[0] = v14;
    this->position_world_f_core_calm_reference[0].k[1] = v13;
    LODWORD(this->time_of_calm_reference[0].seconds) = LODWORD(seconds);
    HIDWORD(this->time_of_calm_reference[0].seconds) = v12;
    if ( (float)((float)((float)((float)(this->pos_world_f_core_last_psi.k[1]
                                       - this->position_world_f_core_calm_reference[1].k[1])
                               * (float)(this->pos_world_f_core_last_psi.k[1]
                                       - this->position_world_f_core_calm_reference[1].k[1]))
                       + (float)((float)(this->pos_world_f_core_last_psi.k[0]
                                       - this->position_world_f_core_calm_reference[1].k[0])
                               * (float)(this->pos_world_f_core_last_psi.k[0]
                                       - this->position_world_f_core_calm_reference[1].k[0])))
               + (float)((float)(this->pos_world_f_core_last_psi.k[2]
                               - this->position_world_f_core_calm_reference[1].k[2])
                       * (float)(this->pos_world_f_core_last_psi.k[2]
                               - this->position_world_f_core_calm_reference[1].k[2]))) > 0.010000001
      || (v15 = (float)((float)((float)(this->q_world_f_core_calm_reference[1].y * this->q_world_f_core_last_psi.y)
                              + (float)(this->q_world_f_core_last_psi.x * this->q_world_f_core_calm_reference[1].x))
                      + (float)(this->q_world_f_core_calm_reference[1].z * this->q_world_f_core_last_psi.z))
              + (float)(this->q_world_f_core_calm_reference[1].w * this->q_world_f_core_last_psi.w),
          (float)((float)((float)((float)(1.0 - (float)(v15 * v15)) * 2.0) * this->upper_limit_radius)
                * this->upper_limit_radius) > 0.040000003) )
    {
      v16 = this->q_world_f_core_last_psi.x;
      *(double *)&tmp[12] = seconds;
      this->q_world_f_core_calm_reference[1].x = v16;
      v17 = *(_DWORD *)&tmp[16];
      this->q_world_f_core_calm_reference[1].y = this->q_world_f_core_last_psi.y;
      this->q_world_f_core_calm_reference[1].z = this->q_world_f_core_last_psi.z;
      this->q_world_f_core_calm_reference[1].w = this->q_world_f_core_last_psi.w;
      v18 = this->pos_world_f_core_last_psi.k[1];
      v19 = this->pos_world_f_core_last_psi.k[2];
      this->position_world_f_core_calm_reference[1].k[0] = this->pos_world_f_core_last_psi.k[0];
      this->position_world_f_core_calm_reference[1].k[1] = v18;
      this->position_world_f_core_calm_reference[1].k[2] = v19;
      LODWORD(this->time_of_calm_reference[1].seconds) = LODWORD(seconds);
      HIDWORD(this->time_of_calm_reference[1].seconds) = v17;
      return 1;
    }
    if ( (float)(seconds - this->time_of_calm_reference[1].seconds) <= 4.0 )
      return 1;
    return 3;
  }
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10074E20
// Name: public: void IVP_Core::set_mass(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::set_mass(IVP_Core *this, float new_mass)
{
  float v2; // xmm0_4

  v2 = new_mass / this->rot_inertia.hesse_val;
  this->rot_inertia.k[0] = this->rot_inertia.k[0] * v2;
  this->rot_inertia.k[1] = this->rot_inertia.k[1] * v2;
  this->rot_inertia.k[2] = this->rot_inertia.k[2] * v2;
  this->rot_inertia.hesse_val = new_mass;
  IVP_Core::calc_calc(this);
}

//------------------------------------------------------------------------------
// Address: 0x10074E70
// Name: public: void IVP_Core::apply_velocity_limit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::apply_velocity_limit(IVP_Core *this)
{
  IVP_Anomaly_Limits *anomaly_limits; // edi
  float max_velocity; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  long double v11; // st7
  IVP_Environment *maxSpeed; // [esp+Ch] [ebp-8h]
  float maxSpeeda; // [esp+Ch] [ebp-8h]
  float rotSpeed; // [esp+10h] [ebp-4h]
  float rotSpeeda; // [esp+10h] [ebp-4h]
  float rotSpeedb; // [esp+10h] [ebp-4h]
  float rotSpeedc; // [esp+10h] [ebp-4h]

  anomaly_limits = this->environment->anomaly_limits;
  maxSpeed = this->environment;
  if ( anomaly_limits->max_velocity > 0.0 )
  {
    rotSpeed = IVP_U_Float_Point::fast_real_length(this: &this->speed);
    max_velocity = anomaly_limits->max_velocity;
    if ( rotSpeed > max_velocity )
    {
      v4 = max_velocity / rotSpeed;
      this->speed.k[0] = this->speed.k[0] * v4;
      this->speed.k[1] = this->speed.k[1] * v4;
      this->speed.k[2] = this->speed.k[2] * v4;
    }
    rotSpeeda = IVP_U_Float_Point::fast_real_length(this: &this->speed_change);
    v5 = anomaly_limits->max_velocity;
    if ( rotSpeeda > v5 )
    {
      v6 = v5 / rotSpeeda;
      this->speed_change.k[0] = this->speed_change.k[0] * v6;
      this->speed_change.k[1] = this->speed_change.k[1] * v6;
      this->speed_change.k[2] = this->speed_change.k[2] * v6;
    }
  }
  if ( anomaly_limits->max_angular_velocity_per_psi > 0.0 )
  {
    rotSpeedb = IVP_U_Float_Point::fast_real_length(this: &this->rot_speed);
    v7 = maxSpeed->inv_delta_PSI_time * anomaly_limits->max_angular_velocity_per_psi;
    maxSpeeda = v7;
    if ( rotSpeedb > v7 )
    {
      v8 = v7 / rotSpeedb;
      this->rot_speed.k[0] = this->rot_speed.k[0] * v8;
      v9 = v8 * this->rot_speed.k[1];
      v10 = v8 * this->rot_speed.k[2];
      this->rot_speed.k[1] = v9;
      this->rot_speed.k[2] = v10;
    }
    v11 = IVP_U_Float_Point::fast_real_length(this: &this->speed_change);
    rotSpeedc = v11;
    if ( v11 > maxSpeeda )
    {
      this->rot_speed_change.k[0] = (float)(maxSpeeda / rotSpeedc) * this->rot_speed_change.k[0];
      this->rot_speed_change.k[1] = this->rot_speed_change.k[1] * (float)(maxSpeeda / rotSpeedc);
      this->rot_speed_change.k[2] = this->rot_speed_change.k[2] * (float)(maxSpeeda / rotSpeedc);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075030
// Name: public: class IVP_Friction_Info_For_Core __near * IVP_Core::get_friction_info(class IVP_Friction_System __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Friction_Info_For_Core *__thiscall IVP_Core::get_friction_info(IVP_Core *this, IVP_Friction_System *my_fr_system)
{
  IVP_Friction_Hash *l_friction_info_hash; // ecx
  IVP_Friction_Info_For_Core *result; // eax

  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 2) != 0 )
  {
    l_friction_info_hash = this->core_friction_info.for_unmoveables.l_friction_info_hash;
    if ( l_friction_info_hash != nullptr )
      return (IVP_Friction_Info_For_Core *)IVP_VHash_Store::find_elem(
                                             this: l_friction_info_hash,
                                             key_elem: my_fr_system);
    return nullptr;
  }
  result = this->core_friction_info.for_moveables.moveable_core_friction_info;
  if ( result == nullptr || result->l_friction_system != my_fr_system )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10075060
// Name: public: class IVP_Friction_Info_For_Core __near * IVP_Core::moveable_core_has_friction_info(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Friction_Info_For_Core *__thiscall IVP_Core::moveable_core_has_friction_info(IVP_Core *this)
{
  return this->core_friction_info.for_moveables.moveable_core_friction_info;
}

//------------------------------------------------------------------------------
// Address: 0x10075070
// Name: public: void IVP_Core::add_friction_info(class IVP_Friction_Info_For_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::add_friction_info(IVP_Core *this, IVP_Friction_Hash *my_fr_info)
{
  IVP_VHash_Store *v3; // eax
  IVP_Friction_Hash *v4; // esi

  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 2) != 0 )
  {
    if ( this->core_friction_info.for_unmoveables.l_friction_info_hash == nullptr )
    {
      v3 = (IVP_VHash_Store *)p_malloc(size: 0x14u);
      v4 = (IVP_Friction_Hash *)v3;
      if ( v3 != nullptr )
        IVP_VHash_Store::IVP_VHash_Store(this: v3, size_i: 2);
      else
        v4 = nullptr;
      this->core_friction_info.for_unmoveables.l_friction_info_hash = v4;
    }
    IVP_VHash_Store::add_elem(
      this: this->core_friction_info.for_unmoveables.l_friction_info_hash,
      key_elem: (void *)my_fr_info->nelems,
      elem: my_fr_info);
  }
  else
  {
    this->core_friction_info.for_unmoveables.l_friction_info_hash = my_fr_info;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100750D0
// Name: public: void IVP_Core::unlink_friction_info(class IVP_Friction_Info_For_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::unlink_friction_info(IVP_Core *this, IVP_Friction_Info_For_Core *my_fr_info)
{
  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 2) != 0 )
    IVP_VHash_Store::remove_elem(
      this: this->core_friction_info.for_unmoveables.l_friction_info_hash,
      key_elem: my_fr_info->l_friction_system);
  else
    this->core_friction_info.for_unmoveables.l_friction_info_hash = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10075100
// Name: public: void IVP_Core::ensure_core_to_be_in_simulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::ensure_core_to_be_in_simulation(IVP_Core *this)
{
  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 2) == 0 )
  {
    if ( *((_BYTE *)&this->IVP_Core_Fast_Static + 1) == 8 )
      IVP_Simulation_Unit::sim_unit_revive_for_simulation(this: this->sim_unit_of_core, env: this->environment);
    else
      IVP_Simulation_Unit::sim_unit_ensure_cores_movement(this: this->sim_unit_of_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075130
// Name: public: float IVP_Core::calc_correct_virt_mass(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)const
// Source: json
//------------------------------------------------------------------------------
long double __userpurge IVP_Core::calc_correct_virt_mass@<st0>(
        IVP_Core *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Float_Point *core_point,
        const IVP_U_Float_Point *direction_core,
        const IVP_U_Float_Point *direction_world)
{
  float v7; // xmm0_4
  float v8; // xmm7_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float hesse_val; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm3_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v23[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point ret_world_speed; // [esp+0h] [ebp-20h]
  IVP_U_Float_Point ret_center_speed; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  ret_center_speed.k[1] = a2;
  ret_center_speed.k[2] = retaddr;
  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 0x10) != 0 )
    return 1.0;
  v7 = core_point->k[0];
  v8 = core_point->k[2];
  v9 = (float)(core_point->k[0] * direction_core->k[1]) - (float)(direction_core->k[0] * core_point->k[1]);
  v10 = this->inv_rot_inertia.k[0]
      * (float)((float)(direction_core->k[2] * core_point->k[1]) - (float)(direction_core->k[1] * core_point->k[2]));
  hesse_val = this->inv_rot_inertia.hesse_val;
  v12 = this->inv_rot_inertia.k[2];
  v13 = this->inv_rot_inertia.k[1]
      * (float)((float)(direction_core->k[0] * v8) - (float)(core_point->k[0] * direction_core->k[2]));
  ret_world_speed.k[1] = direction_world->k[0] * hesse_val;
  ret_world_speed.k[2] = direction_world->k[1] * hesse_val;
  v14 = direction_world->k[2] * hesse_val;
  v15 = core_point->k[1];
  ret_world_speed.hesse_val = v14;
  v16 = v12 * v9;
  v17 = (float)(v8 * v13) - (float)(v15 * v16);
  v18 = (float)(v15 * v10) - (float)(v7 * v13);
  v19 = (float)(v7 * v16) - (float)(v8 * v10);
  v20 = (float)((float)((float)(this->m_world_f_core_last_psi.rows[1].k[0] * v17)
                      + (float)(this->m_world_f_core_last_psi.rows[1].k[1] * v19))
              + (float)(this->m_world_f_core_last_psi.rows[1].k[2] * v18))
      + ret_world_speed.k[2];
  v21 = (float)((float)((float)(this->m_world_f_core_last_psi.rows[2].k[0] * v17)
                      + (float)(this->m_world_f_core_last_psi.rows[2].k[1] * v19))
              + (float)(this->m_world_f_core_last_psi.rows[2].k[2] * v18))
      + ret_world_speed.hesse_val;
  v23[0] = (float)((float)((float)(this->m_world_f_core_last_psi.rows[0].k[1] * v19)
                         + (float)(v17 * this->m_world_f_core_last_psi.rows[0].k[0]))
                 + (float)(this->m_world_f_core_last_psi.rows[0].k[2] * v18))
         + ret_world_speed.k[1];
  v23[1] = v20;
  v23[2] = v21;
  return 1.0 / IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)v23);
}

//------------------------------------------------------------------------------
// Address: 0x100752E0
// Name: public: void IVP_Core::global_damp_core(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Core::global_damp_core(IVP_Core *this@<ecx>, float a2@<ebp>, int a3@<esi>, float d_time)
{
  IVP_U_Float_Point *p_rot_speed_damp_factor; // [esp+4h] [ebp-24h]
  float speed_factor; // [esp+8h] [ebp-20h]
  float v6[3]; // [esp+Ch] [ebp-1Ch] BYREF
  IVP_U_Float_Point rot_damp_factor; // [esp+18h] [ebp-10h]
  float retaddr; // [esp+28h] [ebp+0h]

  rot_damp_factor.k[1] = a2;
  rot_damp_factor.k[2] = retaddr;
  if ( *((_BYTE *)&this->IVP_Core_Fast_Static + 1) < 2u )
  {
    speed_factor = this->speed_damp_factor;
    p_rot_speed_damp_factor = &this->rot_speed_damp_factor;
  }
  else
  {
    v6[0] = this->rot_speed_damp_factor.k[0] + 0.1;
    v6[1] = this->rot_speed_damp_factor.k[1] + 0.1;
    v6[2] = this->rot_speed_damp_factor.k[2] + 0.1;
    speed_factor = this->speed_damp_factor + 0.1;
    p_rot_speed_damp_factor = (IVP_U_Float_Point *)v6;
  }
  IVP_Core::damp_object(this, a2: a3, delta_time_: d_time, rotation_factor: p_rot_speed_damp_factor, speed_factor);
}

//------------------------------------------------------------------------------
// Address: 0x10075370
// Name: public: void IVP_Core::set_rotation_inertia(class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::set_rotation_inertia(IVP_Core *this, const IVP_U_Float_Point *r)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = r->k[1];
  v3 = r->k[2];
  this->rot_inertia.k[0] = r->k[0];
  this->rot_inertia.k[1] = v2;
  this->rot_inertia.k[2] = v3;
  IVP_Core::calc_calc(this);
}

//------------------------------------------------------------------------------
// Address: 0x100753A0
// Name: public: void IVP_Core::async_push_core(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::async_push_core(
        IVP_Core *this,
        const IVP_U_Float_Point *point_cs,
        const IVP_U_Float_Point *impulse_in_core,
        const IVP_U_Float_Point *impulse_in_world)
{
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float hesse_val; // xmm1_4

  v4 = impulse_in_world->k[0];
  v5 = impulse_in_world->k[1];
  v6 = impulse_in_world->k[2];
  v7 = this->inv_rot_inertia.k[1]
     * (float)((float)(impulse_in_core->k[0] * point_cs->k[2]) - (float)(point_cs->k[0] * impulse_in_core->k[2]));
  v8 = this->inv_rot_inertia.k[2]
     * (float)((float)(point_cs->k[0] * impulse_in_core->k[1]) - (float)(impulse_in_core->k[0] * point_cs->k[1]));
  hesse_val = this->inv_rot_inertia.hesse_val;
  this->rot_speed_change.k[0] = (float)((float)((float)(impulse_in_core->k[2] * point_cs->k[1])
                                              - (float)(impulse_in_core->k[1] * point_cs->k[2]))
                                      * this->inv_rot_inertia.k[0])
                              + this->rot_speed_change.k[0];
  this->rot_speed_change.k[1] = this->rot_speed_change.k[1] + v7;
  this->rot_speed_change.k[2] = this->rot_speed_change.k[2] + v8;
  this->speed_change.k[0] = this->speed_change.k[0] + (float)(v4 * hesse_val);
  this->speed_change.k[1] = this->speed_change.k[1] + (float)(v5 * hesse_val);
  this->speed_change.k[2] = this->speed_change.k[2] + (float)(v6 * hesse_val);
}

//------------------------------------------------------------------------------
// Address: 0x100754A0
// Name: public: void IVP_Core::push_core(class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::push_core(
        IVP_Core *this,
        const IVP_U_Float_Point *point_cs,
        const IVP_U_Float_Point *impulse_in_core,
        const IVP_U_Float_Point *impulse_in_world)
{
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float hesse_val; // xmm1_4

  v4 = impulse_in_world->k[0];
  v5 = impulse_in_world->k[1];
  v6 = impulse_in_world->k[2];
  v7 = this->inv_rot_inertia.k[1]
     * (float)((float)(impulse_in_core->k[0] * point_cs->k[2]) - (float)(point_cs->k[0] * impulse_in_core->k[2]));
  v8 = this->inv_rot_inertia.k[2]
     * (float)((float)(point_cs->k[0] * impulse_in_core->k[1]) - (float)(impulse_in_core->k[0] * point_cs->k[1]));
  hesse_val = this->inv_rot_inertia.hesse_val;
  this->rot_speed.k[0] = (float)((float)((float)(impulse_in_core->k[2] * point_cs->k[1])
                                       - (float)(impulse_in_core->k[1] * point_cs->k[2]))
                               * this->inv_rot_inertia.k[0])
                       + this->rot_speed.k[0];
  this->rot_speed.k[1] = this->rot_speed.k[1] + v7;
  this->rot_speed.k[2] = this->rot_speed.k[2] + v8;
  this->speed.k[0] = this->speed.k[0] + (float)(v4 * hesse_val);
  this->speed.k[1] = this->speed.k[1] + (float)(v5 * hesse_val);
  this->speed.k[2] = this->speed.k[2] + (float)(v6 * hesse_val);
}

//------------------------------------------------------------------------------
// Address: 0x100755A0
// Name: public: void IVP_Core::commit_all_async_pushes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::commit_all_async_pushes(IVP_Core *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  v1 = this->rot_speed_change.k[2] + this->rot_speed.k[2];
  v2 = this->rot_speed.k[0] + this->rot_speed_change.k[0];
  this->rot_speed.k[1] = this->rot_speed.k[1] + this->rot_speed_change.k[1];
  this->rot_speed.k[0] = v2;
  this->rot_speed.k[2] = v1;
  v3 = this->speed.k[2] + this->speed_change.k[2];
  v4 = this->speed.k[0] + this->speed_change.k[0];
  this->speed.k[1] = this->speed_change.k[1] + this->speed.k[1];
  this->speed.k[0] = v4;
  this->speed.k[2] = v3;
  *(_QWORD *)&this->speed_change.k[1] = 0;
  this->speed_change.k[0] = 0.0;
  *(_QWORD *)&this->rot_speed_change.k[1] = 0;
  this->rot_speed_change.k[0] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10075670
// Name: public: void IVP_Core::reset_time(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::reset_time(IVP_Core *this, IVP_Time offset)
{
  int v3; // esi

  this->time_of_last_psi.seconds = this->time_of_last_psi.seconds - offset.seconds;
  v3 = this->objects.n_elems - 1;
  if ( this->objects.n_elems != 0 )
  {
    do
      IVP_Real_Object::reset_time(this: (IVP_Real_Object *)this->objects.elems[v3--], offset);
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100756B0
// Name: public: void IVP_Core::stop_physical_movement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::stop_physical_movement(IVP_Core *this)
{
  int v2; // ebx
  char *v3; // esi
  float v4; // xmm0_4
  float v5; // xmm1_4
  IVP_Time time; // [esp+8h] [ebp-8h]

  IVP_Core::stop_movement_without_collision_recheck(this);
  v2 = this->objects.n_elems - 1;
  *(IVP_Time *)&time.seconds = this->environment->current_time;
  if ( this->objects.n_elems != 0 )
  {
    do
    {
      v3 = (char *)this->objects.elems[v2];
      v3[68] = 8;
      IVP_Mindist_Manager::recheck_ov_element(this: this->environment->mindist_manager, object: (IVP_Real_Object *)v3);
      v4 = time.seconds - *((double *)v3 + 9);
      v5 = (float)(v4 * *((float *)v3 + 20)) + *((float *)v3 + 22);
      *((float *)v3 + 23) = (float)(v4 * *((float *)v3 + 21)) + *((float *)v3 + 23);
      *((float *)v3 + 22) = v5;
      *((_DWORD *)v3 + 20) = 0;
      *((_DWORD *)v3 + 21) = 0;
      IVP_Hull_Manager::reset_times(this: (IVP_Hull_Manager *)(v3 + 72));
      if ( *((_DWORD *)v3 + 16) != 0 )
        IVP_Cache_Object_Manager::invalid_cache_object(object: (IVP_Real_Object *)v3);
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075760
// Name: public: void IVP_Core::init_core_for_simulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::init_core_for_simulation(IVP_Core *this)
{
  IVP_Environment *environment; // eax
  int seconds_low; // ecx
  int seconds_high; // edx
  float v5; // xmm0_4
  bool v6; // sf
  int v7; // edi
  IVP_Real_Object *v8; // ecx
  IVP_Time last_time; // [esp+4h] [ebp-8h]

  environment = this->environment;
  *((_BYTE *)&this->IVP_Core_Fast_Static + 1) = 1;
  seconds_high = HIDWORD(environment->current_time.seconds);
  seconds_low = LODWORD(environment->current_time.seconds);
  v5 = environment->current_time.seconds - environment->delta_PSI_time;
  this->time_of_last_psi.seconds = v5;
  last_time.seconds = environment->current_time.seconds;
  v7 = this->objects.n_elems - 1;
  v6 = this->objects.n_elems == 0;
  this->time_of_calm_reference[0] = last_time;
  this->time_of_calm_reference[1] = last_time;
  LODWORD(this->time_of_last_psi.seconds) = seconds_low;
  HIDWORD(this->time_of_last_psi.seconds) = seconds_high;
  if ( !v6 )
  {
    do
    {
      v8 = (IVP_Real_Object *)this->objects.elems[v7];
      *(_BYTE *)&v8->flags = 1;
      IVP_Real_Object::get_all_near_mindists(this: v8);
      --v7;
    }
    while ( v7 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075830
// Name: public: void IVP_Core::update_exact_mindist_events_of_core(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::update_exact_mindist_events_of_core(IVP_Core *this)
{
  bool v2; // sf
  int v3; // esi

  v3 = this->objects.n_elems - 1;
  v2 = this->objects.n_elems == 0;
  this->mindist_event_already_done = this->environment->mindist_event_timestamp_reference;
  if ( !v2 )
  {
    do
      IVP_Real_Object::update_exact_mindist_events_of_object(this: (IVP_Real_Object *)this->objects.elems[v3--]);
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100758B0
// Name: public: void IVP_Core::revive_adjacent_to_unmoveable(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Core::revive_adjacent_to_unmoveable(IVP_Core *this@<ecx>, int a2@<ebp>)
{
  int v2; // edx
  float v3; // eax
  float v4; // edx
  int v5; // esi
  IVP_Core *v6; // edi
  bool v7; // sf
  IVP_Synapse_Friction *v8; // eax
  IVP_U_Memory *sim_unit_mem; // ecx
  int v11; // [esp-Ch] [ebp-FCh] BYREF
  IVP_Impact_Solver_Long_Term info; // [esp+0h] [ebp-F0h] BYREF
  IVP_Synapse_Friction *next_syn; // [esp+E0h] [ebp-10h]
  int d; // [esp+E4h] [ebp-Ch]
  void *v15; // [esp+E8h] [ebp-8h]
  void *retaddr; // [esp+F0h] [ebp+0h]

  d = a2;
  v15 = retaddr;
  ++this->environment->sim_unit_mem->transaction_in_use;
  v2 = this->objects.n_elems - 1;
  LODWORD(info.contact_cross_nomal_cs[1].hesse_val) = this;
  for ( LODWORD(info.contact_cross_nomal_cs[1].k[2]) = v2; v2 >= 0; LODWORD(info.contact_cross_nomal_cs[1].k[2]) = v2 )
  {
    v3 = *((float *)this->objects.elems[v2] + 10);
    if ( v3 != 0.0 )
    {
      do
      {
        v4 = *(float *)LODWORD(v3);
        v5 = LODWORD(v3) + *(__int16 *)(LODWORD(v3) + 12);
        *(_BYTE *)(*(_DWORD *)(v5 + 144) + 68) = 1;
        info.contact_cross_nomal_cs[1].k[1] = v4;
        v6 = *(IVP_Core **)(*(_DWORD *)(v5 + 16) + 148);
        if ( v6 == this )
          v6 = *(IVP_Core **)(*(_DWORD *)(v5 + 36) + 148);
        if ( (*(_BYTE *)&v6->IVP_Core_Fast_Static & 2) != 0 )
        {
          IVP_Contact_Point::~IVP_Contact_Point(this: (IVP_Contact_Point *)v5);
          free(data: (void *)v5);
        }
        else
        {
          v8 = (IVP_Synapse_Friction *)(v6->objects.n_elems - 1);
          v7 = v6->objects.n_elems == 0;
          next_syn = v8;
          if ( !v7 )
          {
            while ( 1 )
            {
              IVP_Real_Object::ensure_in_simulation(this: (IVP_Real_Object *)v6->objects.elems[(_DWORD)v8]);
              next_syn = (IVP_Synapse_Friction *)((char *)next_syn - 1);
              if ( (int)next_syn < 0 )
                break;
              v8 = next_syn;
            }
            this = (IVP_Core *)LODWORD(info.contact_cross_nomal_cs[1].hesse_val);
          }
          IVP_Contact_Point::recalc_friction_s_vals(this: (IVP_Contact_Point *)v5, env: this->environment);
          *(IVP_Material **)((char *)&info.materials[1] + 2) = nullptr;
          memset(&info.contact_point_ws.k[1], 0, 12);
          HIWORD(info.materials[2]) = 0;
          IVP_Contact_Point::read_materials_for_contact_situation(
            this: (IVP_Contact_Point *)v5,
            info: (IVP_Impact_Solver_Long_Term *)&v11);
          IVP_Contact_Point::calc_virtual_mass_of_mindist(this: (IVP_Contact_Point *)v5);
        }
        v3 = info.contact_cross_nomal_cs[1].k[1];
        this = (IVP_Core *)LODWORD(info.contact_cross_nomal_cs[1].hesse_val);
      }
      while ( LODWORD(info.contact_cross_nomal_cs[1].k[1]) != 0 );
      v2 = LODWORD(info.contact_cross_nomal_cs[1].k[2]);
    }
    --v2;
  }
  sim_unit_mem = this->environment->sim_unit_mem;
  if ( sim_unit_mem->transaction_in_use-- == 1 )
    IVP_U_Memory::free_mem_transaction(this: sim_unit_mem);
}

//------------------------------------------------------------------------------
// Address: 0x100759F0
// Name: public: void IVP_Core::values_changed_recalc_redundants(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Core::values_changed_recalc_redundants(IVP_Core *this@<ecx>, IVP_Friction_System *a2@<ebp>)
{
  float hesse_val; // esi
  IVP_U_Memory *v3; // ecx
  bool v4; // zf
  char v5; // cl
  int v6; // eax
  IVP_Simulation_Unit *v7; // ecx
  bool v8; // sf
  int v9; // eax
  int **v10; // edi
  float v11; // ecx
  int v12; // esi
  IVP_Friction_System *v13; // eax
  IVP_Contact_Point *v14; // esi
  IVP_U_Memory *v15; // ecx
  IVP_Core *v16; // ecx
  int v17; // ecx
  int v18; // edx
  _DWORD *i; // eax
  IVP_Environment *v20; // [esp-20h] [ebp-110h]
  int v21; // [esp-Ch] [ebp-FCh] BYREF
  IVP_Impact_Solver_Long_Term info; // [esp+0h] [ebp-F0h] BYREF
  int v23; // [esp+E0h] [ebp-10h]
  IVP_Friction_System *v24; // [esp+E4h] [ebp-Ch] BYREF
  void *v25; // [esp+E8h] [ebp-8h]
  void *retaddr; // [esp+F0h] [ebp+0h]

  v24 = a2;
  v25 = retaddr;
  hesse_val = *(float *)&this;
  ++this->environment->sim_unit_mem->transaction_in_use;
  LODWORD(info.contact_cross_nomal_cs[1].hesse_val) = this;
  IVP_Core::calc_calc(this);
  v3 = *(IVP_U_Memory **)(*(_DWORD *)(LODWORD(hesse_val) + 12) + 160);
  v4 = v3->transaction_in_use-- == 1;
  if ( v4 )
    IVP_U_Memory::free_mem_transaction(this: v3);
  if ( (*(_BYTE *)LODWORD(hesse_val) & 2) != 0 )
  {
    v5 = 16;
    *(_BYTE *)(LODWORD(hesse_val) + 1) = 8;
  }
  else
  {
    if ( *(_BYTE *)(LODWORD(hesse_val) + 1) > 8u )
      *(_BYTE *)(LODWORD(hesse_val) + 1) = 8;
    v5 = *(_BYTE *)(LODWORD(hesse_val) + 1);
  }
  v6 = *(unsigned __int16 *)(LODWORD(hesse_val) + 82) - 1;
  if ( *(_WORD *)(LODWORD(hesse_val) + 82) != 0 )
  {
    do
    {
      --v6;
      *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(LODWORD(hesse_val) + 84) + 4 * v6 + 4) + 68) = v5;
    }
    while ( v6 >= 0 );
  }
  if ( (*(_BYTE *)LODWORD(hesse_val) & 2) != 0 )
  {
    IVP_Core::stop_movement_without_collision_recheck(this: (IVP_Core *)LODWORD(hesse_val));
    IVP_Core::revive_adjacent_to_unmoveable(this: v16, a2: (int)&v24);
    v17 = *(unsigned __int16 *)(LODWORD(hesse_val) + 82) - 1;
    if ( *(_WORD *)(LODWORD(hesse_val) + 82) != 0 )
    {
      v18 = *(_DWORD *)(LODWORD(hesse_val) + 84) + 4 * v17;
      do
      {
        for ( i = *(_DWORD **)(*(_DWORD *)v18 + 40); i != nullptr; i = (_DWORD *)*i )
          ;
        v18 -= 4;
        --v17;
      }
      while ( v17 >= 0 );
    }
  }
  else
  {
    v7 = *(IVP_Simulation_Unit **)(LODWORD(hesse_val) + 332);
    if ( *(_BYTE *)(LODWORD(hesse_val) + 1) == 8 )
      IVP_Simulation_Unit::sim_unit_revive_for_simulation(this: v7, env: *(IVP_Environment **)(LODWORD(hesse_val) + 12));
    else
      IVP_Simulation_Unit::sim_unit_ensure_cores_movement(this: v7);
    ++*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(hesse_val) + 12) + 160) + 16);
    v9 = *(unsigned __int16 *)(LODWORD(hesse_val) + 82) - 1;
    v8 = *(unsigned __int16 *)(LODWORD(hesse_val) + 82) == 0;
    v23 = v9;
    if ( !v8 )
    {
      do
      {
        v10 = *(int ***)(*(_DWORD *)(*(_DWORD *)(LODWORD(hesse_val) + 84) + 4 * v9) + 40);
        if ( v10 != nullptr )
        {
          v11 = *(float *)((char *)v10 + *((__int16 *)v10 + 6) + 144);
          for ( info.contact_cross_nomal_cs[1].k[2] = v11; ; v11 = info.contact_cross_nomal_cs[1].k[2] )
          {
            v12 = *((__int16 *)v10 + 6);
            v13 = *(IVP_Friction_System **)((char *)v10 + v12 + 144);
            v14 = (IVP_Contact_Point *)((char *)v10 + v12);
            if ( v13 != (IVP_Friction_System *)LODWORD(v11) )
              IVP_Friction_System::fusion_friction_systems(this: (IVP_Friction_System *)LODWORD(v11), second_sys: v13);
            *(IVP_Material **)((char *)&info.materials[1] + 2) = nullptr;
            v20 = *(IVP_Environment **)(LODWORD(info.contact_cross_nomal_cs[1].hesse_val) + 12);
            memset(&info.contact_point_ws.k[1], 0, 12);
            HIWORD(info.materials[2]) = 0;
            IVP_Contact_Point::recalc_friction_s_vals(this: v14, env: v20);
            IVP_Contact_Point::read_materials_for_contact_situation(
              this: v14,
              info: (IVP_Impact_Solver_Long_Term *)&v21);
            IVP_Contact_Point::calc_virtual_mass_of_mindist(this: v14);
            v10 = (int **)*v10;
            if ( v10 == nullptr )
              break;
          }
          v9 = v23;
          hesse_val = info.contact_cross_nomal_cs[1].hesse_val;
        }
        v23 = --v9;
      }
      while ( v9 >= 0 );
    }
    v15 = *(IVP_U_Memory **)(*(_DWORD *)(LODWORD(hesse_val) + 12) + 160);
    v4 = v15->transaction_in_use-- == 1;
    if ( v4 )
      IVP_U_Memory::free_mem_transaction(this: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075BB0
// Name: protected: void IVP_Core::init(class IVP_Real_Object __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::init(IVP_Core *this, IVP_Real_Object *io, bool hasGravity)
{
  IVP_Simulation_Unit *v4; // eax
  IVP_Simulation_Unit *v5; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Core));
  this->objects.elems = (void **)this->objects.elem_buffer;
  this->objects.memsize = 1;
  if ( this->objects.n_elems != 0 )
    IVP_U_Vector_Base::increment_mem(this: &this->objects);
  this->objects.elems[this->objects.n_elems++] = io;
  this->environment = io->environment;
  v4 = (IVP_Simulation_Unit *)p_malloc(size: 0x24u);
  if ( v4 != nullptr )
    v5 = IVP_Simulation_Unit::IVP_Simulation_Unit(this: v4);
  else
    v5 = nullptr;
  this->sim_unit_of_core = v5;
  IVP_Controller_Phantom::add_listener_phantom(this: v5, add_core: this);
  *(_BYTE *)this->sim_unit_of_core = 8;
  if ( hasGravity )
    IVP_Core::add_core_controller(this, add_cntrl: this->environment->standard_gravity_controller);
  *((_BYTE *)&this->IVP_Core_Fast_Static + 1) = 8;
}

//------------------------------------------------------------------------------
// Address: 0x10075C50
// Name: public: IVP_Core::IVP_Core(class IVP_Real_Object __near *,class IVP_U_Quat const __near *,class IVP_U_Point const __near *,enum IVP_BOOL,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
IVP_Core *__thiscall IVP_Core::IVP_Core(
        IVP_Core *this,
        IVP_Real_Object *io,
        const IVP_U_Quat *q_world_f_object_init,
        const IVP_U_Point *position,
        IVP_BOOL physical_unmoveable_,
        IVP_BOOL enable_piling_optimization)
{
  IVP_Environment *environment; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  IVP_Simulation_Unit *sim_unit_of_core; // [esp-4h] [ebp-10h]

  this->objects.elems = (void **)this->objects.elem_buffer;
  *(_DWORD *)&this->objects.memsize = 1;
  *(_DWORD *)&this->controllers_of_core.memsize = 0;
  this->controllers_of_core.elems = nullptr;
  IVP_Core::init(this, io, hasGravity: physical_unmoveable_ == IVP_FALSE);
  environment = this->environment;
  sim_unit_of_core = this->sim_unit_of_core;
  *(_WORD *)&this->IVP_Core_Fast_Static ^= (*(_WORD *)&this->IVP_Core_Fast_Static ^ (2 * physical_unmoveable_)) & 2;
  IVP_Sim_Units_Manager::add_sim_unit_to_manager(this: environment->sim_units_manager, sim_u: sim_unit_of_core);
  this->q_world_f_core_last_psi = *q_world_f_object_init;
  IVP_U_Quat::normize_quat(this: &this->q_world_f_core_last_psi);
  this->q_world_f_core_next_psi = this->q_world_f_core_last_psi;
  v8 = position->k[1];
  v9 = position->k[2];
  this->pos_world_f_core_last_psi.k[0] = position->k[0];
  this->pos_world_f_core_last_psi.k[1] = v8;
  this->pos_world_f_core_last_psi.k[2] = v9;
  *(_QWORD *)&this->delta_world_f_core_psis.k[1] = 0;
  this->delta_world_f_core_psis.k[0] = 0.0;
  IVP_U_Quat::set_matrix(this: &this->q_world_f_core_last_psi, mat: &this->m_world_f_core_last_psi);
  v10 = position->k[1];
  v11 = position->k[2];
  this->m_world_f_core_last_psi.vv.k[0] = position->k[0];
  this->m_world_f_core_last_psi.vv.k[1] = v10;
  this->m_world_f_core_last_psi.vv.k[2] = v11;
  *(_WORD *)&this->IVP_Core_Fast_Static ^= ((unsigned __int8)enable_piling_optimization
                                          ^ (unsigned __int8)*(_WORD *)&this->IVP_Core_Fast_Static)
                                         & 1;
  this->upper_limit_radius = 1000.0;
  this->max_surface_deviation = 1000.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10075D90
// Name: public: IVP_Core::~IVP_Core(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::~IVP_Core(IVP_Core *this)
{
  IVP_Friction_Hash *l_friction_info_hash; // edi
  int v3; // edi
  void (__thiscall ***v4)(void *, IVP_Core *); // ecx
  IVP_Simulation_Unit *sim_unit_of_core; // ecx
  void **elems; // eax
  void **v7; // eax

  IVP_Environment::remove_revive_core(this: this->environment, c: this);
  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 2) != 0 )
  {
    l_friction_info_hash = this->core_friction_info.for_unmoveables.l_friction_info_hash;
    if ( l_friction_info_hash != nullptr )
    {
      IVP_Friction_Hash::~IVP_Friction_Hash(this: this->core_friction_info.for_unmoveables.l_friction_info_hash);
      free(data: l_friction_info_hash);
      this->core_friction_info.for_unmoveables.l_friction_info_hash = nullptr;
    }
  }
  else
  {
    v3 = this->controllers_of_core.n_elems - 1;
    if ( this->controllers_of_core.n_elems != 0 )
    {
      do
      {
        v4 = (void (__thiscall ***)(void *, IVP_Core *))this->controllers_of_core.elems[v3];
        (**v4)(a1: v4, a2: this);
        --v3;
      }
      while ( v3 >= 0 );
    }
  }
  sim_unit_of_core = this->sim_unit_of_core;
  if ( sim_unit_of_core != nullptr )
    IVP_Simulation_Unit::sim_unit_remove_core(this: sim_unit_of_core, del_core: this);
  elems = this->controllers_of_core.elems;
  if ( elems != (void **)&this->merged_core_which_replace_this_core )
  {
    if ( elems != nullptr )
      free(data: this->controllers_of_core.elems);
    this->controllers_of_core.elems = nullptr;
    this->controllers_of_core.memsize = 0;
  }
  this->controllers_of_core.n_elems = 0;
  v7 = this->objects.elems;
  if ( v7 == (void **)this->objects.elem_buffer )
  {
    this->objects.n_elems = 0;
  }
  else
  {
    if ( v7 != nullptr )
      free(data: this->objects.elems);
    this->objects.elems = nullptr;
    *(_DWORD *)&this->objects.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075E60
// Name: public: void IVP_Core::delete_friction_info(class IVP_Friction_Info_For_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::delete_friction_info(IVP_Core *this, IVP_Friction_Info_For_Core *my_fr_info)
{
  void **elems; // eax

  if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 2) != 0 )
    IVP_VHash_Store::remove_elem(
      this: this->core_friction_info.for_unmoveables.l_friction_info_hash,
      key_elem: my_fr_info->l_friction_system);
  else
    this->core_friction_info.for_unmoveables.l_friction_info_hash = nullptr;
  if ( my_fr_info != nullptr )
  {
    elems = my_fr_info->friction_springs.elems;
    if ( elems != (void **)&my_fr_info->l_friction_system )
    {
      if ( elems != nullptr )
        free(data: my_fr_info->friction_springs.elems);
      my_fr_info->friction_springs.elems = nullptr;
      my_fr_info->friction_springs.memsize = 0;
    }
    my_fr_info->friction_springs.n_elems = 0;
    free(data: my_fr_info);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075EC0
// Name: public: void IVP_Core::unlink_obj_from_core_and_maybe_destroy(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::unlink_obj_from_core_and_maybe_destroy(IVP_Core *this, IVP_Real_Object *remove_obj)
{
  unsigned __int16 n_elems; // dx
  int v4; // eax
  IVP_Real_Object **v5; // ecx

  n_elems = this->objects.n_elems;
  v4 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v5 = (IVP_Real_Object **)&this->objects.elems[v4];
    do
    {
      if ( *v5 == remove_obj )
        break;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  for ( this->objects.n_elems = n_elems - 1; v4 < this->objects.n_elems; ++v4 )
    this->objects.elems[v4] = this->objects.elems[v4 + 1];
  if ( this->objects.n_elems == 0 )
  {
    if ( *((_BYTE *)&this->IVP_Core_Fast_Static + 1) < 8u )
      IVP_Core::stop_physical_movement(this);
    IVP_Core::~IVP_Core(this);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)this & 0xFFFFFFFC) - 4));
  }
}
