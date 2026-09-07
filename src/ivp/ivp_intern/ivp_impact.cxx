// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_impact.cxx
// Functions: 27
// ============================================================

#include "ivp\ivp_intern\ivp_impact.h"

//------------------------------------------------------------------------------
// Address: 0x10086FF0
// Name: private: void IVP_Impact_Solver::get_relative_speed_vector(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Impact_Solver::get_relative_speed_vector(IVP_Impact_Solver *this@<ecx>, float a2@<ebp>)
{
  float v3[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point world_speed0; // [esp+0h] [ebp-20h] BYREF
  IVP_U_Float_Point world_speed1; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  world_speed1.k[1] = a2;
  world_speed1.k[2] = retaddr;
  IVP_Core::get_surface_speed_on_test(
    this: this->core[0],
    point_cs: this->obj_point[0],
    center_speed_ws: this->trans_speed,
    rot_speed_cs: this->rot_speed,
    speed_out_ws: (IVP_U_Float_Point *)v3);
  IVP_Core::get_surface_speed_on_test(
    this: this->core[1],
    point_cs: this->obj_point[1],
    center_speed_ws: &this->trans_speed[1],
    rot_speed_cs: &this->rot_speed[1],
    speed_out_ws: (IVP_U_Float_Point *)&world_speed0.k[1]);
  this->relative_world_speed.k[0] = world_speed0.k[1] - v3[0];
  this->relative_world_speed.k[1] = world_speed0.k[2] - v3[1];
  this->relative_world_speed.k[2] = world_speed0.hesse_val - v3[2];
}

//------------------------------------------------------------------------------
// Address: 0x10087090
// Name: private: void IVP_Impact_Solver::get_world_push_direction_two_friction(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Impact_Solver::get_world_push_direction_two_friction(
        IVP_Impact_Solver *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        float part_direction_surf_normal)
{
  IVP_U_Float_Point *surf_normal; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  double v8; // xmm0_8
  float v9; // xmm0_4
  double hesse_val; // xmm0_8
  IVP_U_Float_Point *v11; // eax
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  long double v17; // [esp-1Ch] [ebp-3Ch]
  long double v18; // [esp-1Ch] [ebp-3Ch]
  float v19; // [esp-Ch] [ebp-2Ch] BYREF
  float v20; // [esp-8h] [ebp-28h]
  float v21; // [esp-4h] [ebp-24h]
  IVP_U_Float_Point part_in_direction_surf; // [esp+0h] [ebp-20h]
  float v23; // [esp+10h] [ebp-10h]
  int v24; // [esp+14h] [ebp-Ch]
  float allowed_len; // [esp+18h] [ebp-8h]
  float retaddr; // [esp+20h] [ebp+0h]

  v24 = a2;
  allowed_len = retaddr;
  LODWORD(v17) = a3;
  surf_normal = this->surf_normal;
  v6 = (float)(surf_normal->k[1] * COERCE_FLOAT(LODWORD(part_direction_surf_normal) ^ _mask__NegFloat_))
     + this->world_push_direction.k[1];
  v7 = (float)(surf_normal->k[2] * COERCE_FLOAT(LODWORD(part_direction_surf_normal) ^ _mask__NegFloat_))
     + this->world_push_direction.k[2];
  v19 = (float)(surf_normal->k[0] * COERCE_FLOAT(LODWORD(part_direction_surf_normal) ^ _mask__NegFloat_))
      + this->world_push_direction.k[0];
  v20 = v6;
  v21 = v7;
  part_in_direction_surf.hesse_val = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&v19);
  LODWORD(v23) = COERCE_UNSIGNED_INT(
                   (float)((float)(this->world_direction_second_friction.k[1] * v20)
                         + (float)(v19 * this->world_direction_second_friction.k[0]))
                 + (float)(this->world_direction_second_friction.k[2] * v21))
               & _mask__AbsFloat_;
  v8 = v23;
  __libm_sse2_asin(x: v17);
  *(float *)&v8 = v8;
  *(float *)&v8 = *(float *)&v8 * *(float *)&v8;
  v9 = (float)((float)((float)(v23 * v23) * this->sin_second_friction) * this->sin_second_friction)
     + (float)((float)((float)((float)((float)(1.0 - (float)(*(float *)&v8 * 0.5))
                                     + (float)((float)(*(float *)&v8 * 0.041666668) * *(float *)&v8))
                             * (float)((float)(1.0 - (float)(*(float *)&v8 * 0.5))
                                     + (float)((float)(*(float *)&v8 * 0.041666668) * *(float *)&v8)))
                     * this->sin_friction)
             * this->sin_friction);
  if ( (float)(part_in_direction_surf.hesse_val * part_in_direction_surf.hesse_val) > v9 )
  {
    part_in_direction_surf.hesse_val = fsqrt(v9);
    hesse_val = part_in_direction_surf.hesse_val;
    __libm_sse2_asin(x: v18);
    v11 = this->surf_normal;
    v12 = v11->k[2];
    *(float *)&hesse_val = hesse_val;
    LODWORD(v13) = COERCE_UNSIGNED_INT(
                     (float)(1.0 - (float)((float)(*(float *)&hesse_val * *(float *)&hesse_val) * 0.5))
                   + (float)((float)((float)(*(float *)&hesse_val * *(float *)&hesse_val) * 0.041666668)
                           * (float)(*(float *)&hesse_val * *(float *)&hesse_val)))
                 ^ _mask__NegFloat_;
    v14 = v11->k[1];
    this->world_push_direction.k[0] = v11->k[0] * v13;
    *(float *)&hesse_val = v19;
    this->world_push_direction.k[1] = v14 * v13;
    v15 = v12 * v13;
    v16 = part_in_direction_surf.hesse_val;
    this->world_push_direction.k[2] = v15;
    this->world_push_direction.k[0] = (float)(*(float *)&hesse_val * v16) + this->world_push_direction.k[0];
    this->world_push_direction.k[1] = (float)(v20 * v16) + this->world_push_direction.k[1];
    this->world_push_direction.k[2] = (float)(v21 * v16) + this->world_push_direction.k[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100872A0
// Name: private: void IVP_Impact_Solver::confirm_impact(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_Solver::confirm_impact(IVP_Impact_Solver *this, int core_nr)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  IVP_Core *v4; // esi
  float v5; // xmm0_4
  float v6; // xmm1_4
  IVP_Environment *environment; // eax
  IVP_Anomaly_Limits *anomaly_limits; // edx

  v2 = this->trans_speed[core_nr].k[1];
  v3 = this->trans_speed[core_nr].k[2];
  v4 = this->core[core_nr];
  v4->speed.k[0] = this->trans_speed[core_nr].k[0];
  v4->speed.k[1] = v2;
  v4->speed.k[2] = v3;
  v5 = this->rot_speed[core_nr].k[1];
  v6 = this->rot_speed[core_nr].k[2];
  v4->rot_speed.k[0] = this->rot_speed[core_nr].k[0];
  v4->rot_speed.k[1] = v5;
  v4->rot_speed.k[2] = v6;
  environment = v4->environment;
  anomaly_limits = environment->anomaly_limits;
  if ( v4->impacts_since_last_PSI > anomaly_limits->max_collisions_per_psi )
    *(_WORD *)&v4->IVP_Core_Fast_Static ^= (*(_WORD *)&v4->IVP_Core_Fast_Static
                                          ^ ((unsigned __int16)environment->anomaly_manager->max_collisions_exceeded_check_freezing(
                                                                 this: environment->anomaly_manager,
                                                                 a2: anomaly_limits,
                                                                 a3: v4) << 6))
                                         & 0xC0;
}

//------------------------------------------------------------------------------
// Address: 0x10087340
// Name: private: void IVP_Impact_Solver::undo_push(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_Solver::undo_push(IVP_Impact_Solver *this)
{
  float v1; // xmm0_4
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4

  if ( (*(_BYTE *)&this->core[0]->IVP_Core_Fast_Static & 2) == 0 )
  {
    v1 = this->rot_speed[0].k[1] - this->rot_speed_change[0].k[1];
    v2 = this->rot_speed[0].k[2] - this->rot_speed_change[0].k[2];
    this->rot_speed[0].k[0] = this->rot_speed[0].k[0] - this->rot_speed_change[0].k[0];
    this->rot_speed[0].k[1] = v1;
    this->rot_speed[0].k[2] = v2;
    v3 = this->trans_speed[0].k[1] - this->trans_speed_change[0].k[1];
    v4 = this->trans_speed[0].k[2] - this->trans_speed_change[0].k[2];
    this->trans_speed[0].k[0] = this->trans_speed[0].k[0] - this->trans_speed_change[0].k[0];
    this->trans_speed[0].k[1] = v3;
    this->trans_speed[0].k[2] = v4;
  }
  if ( (*(_BYTE *)&this->core[1]->IVP_Core_Fast_Static & 2) == 0 )
  {
    v5 = this->rot_speed[1].k[1] - this->rot_speed_change[1].k[1];
    v6 = this->rot_speed[1].k[2] - this->rot_speed_change[1].k[2];
    this->rot_speed[1].k[0] = this->rot_speed[1].k[0] - this->rot_speed_change[1].k[0];
    this->rot_speed[1].k[1] = v5;
    this->rot_speed[1].k[2] = v6;
    v7 = this->trans_speed[1].k[1] - this->trans_speed_change[1].k[1];
    v8 = this->trans_speed[1].k[2] - this->trans_speed_change[1].k[2];
    this->trans_speed[1].k[0] = this->trans_speed[1].k[0] - this->trans_speed_change[1].k[0];
    this->trans_speed[1].k[1] = v7;
    this->trans_speed[1].k[2] = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087430
// Name: private: void IVP_Impact_Solver::do_rescue_push(class IVP_U_Float_Point __near *,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Impact_Solver::do_rescue_push(
        IVP_Impact_Solver *this@<ecx>,
        int a2@<ebp>,
        IVP_U_Float_Point *push_dir_norm,
        IVP_BOOL panic_mode)
{
  float v5; // xmm1_4
  IVP_U_Float_Point *v6; // ecx
  float v7; // xmm0_4
  IVP_Core *v8; // ecx
  const IVP_U_Float_Point *v9; // edx
  IVP_Core *v10; // ecx
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm7_4
  IVP_Core *v16; // eax
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float hesse_val; // xmm6_4
  bool v21; // zf
  IVP_U_Matrix *v22; // ecx
  float v23; // xmm7_4
  float v24; // xmm0_4
  IVP_U_Matrix *v25; // ecx
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  IVP_U_Matrix *v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  const IVP_U_Float_Point *v35; // [esp-2Ch] [ebp-12Ch]
  int v36; // [esp-Ch] [ebp-10Ch] BYREF
  IVP_U_Point world_point_obj1; // [esp+0h] [ebp-100h] BYREF
  IVP_U_Point world_point_obj0; // [esp+10h] [ebp-F0h] BYREF
  IVP_U_Float_Point world_speed1; // [esp+20h] [ebp-E0h] BYREF
  IVP_U_Float_Point rotation_vec; // [esp+30h] [ebp-D0h] BYREF
  IVP_U_Float_Point obj_push; // [esp+40h] [ebp-C0h] BYREF
  IVP_U_Float_Point world_speed0; // [esp+50h] [ebp-B0h] BYREF
  IVP_U_Float_Point translation_vec; // [esp+60h] [ebp-A0h] BYREF
  IVP_U_Float_Point push_vec_obj; // [esp+70h] [ebp-90h] BYREF
  IVP_U_Float_Point rotation; // [esp+80h] [ebp-80h] BYREF
  IVP_U_Float_Point translation; // [esp+90h] [ebp-70h] BYREF
  IVP_U_Float_Point speed_change_vec; // [esp+A0h] [ebp-60h] BYREF
  float v48; // [esp+C0h] [ebp-40h]
  float v49; // [esp+C4h] [ebp-3Ch]
  float v50; // [esp+C8h] [ebp-38h]
  float speed_change_scalar; // [esp+CCh] [ebp-34h]
  IVP_U_Float_Point diff_vec_world; // [esp+D0h] [ebp-30h] BYREF
  float v53; // [esp+F0h] [ebp-10h]
  int v54; // [esp+F4h] [ebp-Ch]
  void *v55; // [esp+F8h] [ebp-8h]
  void *retaddr; // [esp+100h] [ebp+0h]

  v54 = a2;
  v55 = retaddr;
  IVP_U_Matrix::vmult4(
    this: this->m_world_f_core[0],
    p_in: this->obj_point[0],
    p_out: (IVP_U_Point *)&world_point_obj1.k[1]);
  IVP_U_Matrix::vmult4(this: this->m_world_f_core[1], p_in: this->obj_point[1], p_out: (IVP_U_Float_Point *)&v36);
  v49 = push_dir_norm->k[0] * -1.0;
  v50 = push_dir_norm->k[1] * -1.0;
  v5 = push_dir_norm->k[2] * -1.0;
  push_vec_obj.k[1] = this->rot_speed[0].k[0];
  push_vec_obj.k[2] = this->rot_speed[0].k[1];
  v6 = this->obj_point[0];
  push_vec_obj.hesse_val = this->rot_speed[0].k[2];
  rotation.k[1] = this->trans_speed[0].k[0];
  rotation.k[2] = this->trans_speed[0].k[1];
  v7 = this->trans_speed[0].k[2];
  v35 = v6;
  v8 = this->core[0];
  speed_change_scalar = v5;
  rotation.hesse_val = v7;
  IVP_Core::get_surface_speed_on_test(
    this: v8,
    point_cs: v35,
    center_speed_ws: (IVP_U_Float_Point *)&rotation.k[1],
    rot_speed_cs: (IVP_U_Float_Point *)&push_vec_obj.k[1],
    speed_out_ws: (IVP_U_Float_Point *)&obj_push.k[1]);
  push_vec_obj.k[1] = this->rot_speed[1].k[0];
  push_vec_obj.k[2] = this->rot_speed[1].k[1];
  v9 = this->obj_point[1];
  push_vec_obj.hesse_val = this->rot_speed[1].k[2];
  rotation.k[1] = this->trans_speed[1].k[0];
  v10 = this->core[1];
  rotation.k[2] = this->trans_speed[1].k[1];
  rotation.hesse_val = this->trans_speed[1].k[2];
  IVP_Core::get_surface_speed_on_test(
    this: v10,
    point_cs: v9,
    center_speed_ws: (IVP_U_Float_Point *)&rotation.k[1],
    rot_speed_cs: (IVP_U_Float_Point *)&push_vec_obj.k[1],
    speed_out_ws: (IVP_U_Point *)&world_point_obj0.k[1]);
  v11 = v50;
  v12 = v49;
  v13 = speed_change_scalar;
  v14 = (float)((float)((float)(world_point_obj0.k[2] - obj_push.k[2]) * v50)
              + (float)((float)(world_point_obj0.k[1] - obj_push.k[1]) * v49))
      + (float)((float)(world_point_obj0.hesse_val - obj_push.hesse_val) * speed_change_scalar);
  if ( panic_mode == IVP_TRUE && v14 > 0.0 )
    v14 = 0.0;
  v15 = this->rescue_speed_impact_solver - v14;
  v53 = v15;
  if ( v15 >= 0.0 )
  {
    v16 = this->core[1];
    v17 = 0.0;
    v18 = v49;
    v19 = v50;
    hesse_val = speed_change_scalar;
    diff_vec_world.k[1] = v49;
    diff_vec_world.k[2] = v50;
    diff_vec_world.hesse_val = speed_change_scalar;
    v21 = (*(_BYTE *)&v16->IVP_Core_Fast_Static & 2) == 0;
    v48 = 0.0;
    if ( v21 )
    {
      IVP_U_Matrix3::vimult3(
        this: this->m_world_f_core[1],
        p_in: (IVP_U_Float_Point *)&diff_vec_world.k[1],
        p_out: (IVP_U_Float_Point *)&translation_vec.k[1]);
      IVP_Core::test_push_core(
        this: this->core[1],
        point_cs: this->obj_point[1],
        impulse_in_core: (IVP_U_Float_Point *)&translation_vec.k[1],
        impulse_in_world: (IVP_U_Float_Point *)&diff_vec_world.k[1],
        speed_out: (IVP_U_Float_Point *)&world_speed0.k[1],
        rot_out: (IVP_U_Float_Point *)&world_speed1.k[1]);
      IVP_Core::get_surface_speed_on_test(
        this: this->core[1],
        point_cs: this->obj_point[1],
        center_speed_ws: (IVP_U_Float_Point *)&world_speed0.k[1],
        rot_speed_cs: (IVP_U_Float_Point *)&world_speed1.k[1],
        speed_out_ws: (IVP_U_Float_Point *)&translation.k[1]);
      v18 = diff_vec_world.k[1];
      v19 = diff_vec_world.k[2];
      hesse_val = diff_vec_world.hesse_val;
      v15 = v53;
      v11 = v50;
      v12 = v49;
      v17 = (float)((float)(translation.k[1] * diff_vec_world.k[1]) + (float)(translation.k[2] * diff_vec_world.k[2]))
          + (float)(translation.hesse_val * diff_vec_world.hesse_val);
      v13 = speed_change_scalar;
      v48 = v17;
    }
    if ( (*(_BYTE *)&this->core[0]->IVP_Core_Fast_Static & 2) == 0 )
    {
      v22 = this->m_world_f_core[0];
      diff_vec_world.k[1] = v18 * -1.0;
      diff_vec_world.k[2] = v19 * -1.0;
      diff_vec_world.hesse_val = hesse_val * -1.0;
      IVP_U_Matrix3::vimult3(
        this: v22,
        p_in: (IVP_U_Float_Point *)&diff_vec_world.k[1],
        p_out: (IVP_U_Float_Point *)&translation_vec.k[1]);
      IVP_Core::test_push_core(
        this: this->core[0],
        point_cs: this->obj_point[0],
        impulse_in_core: (IVP_U_Float_Point *)&translation_vec.k[1],
        impulse_in_world: (IVP_U_Float_Point *)&diff_vec_world.k[1],
        speed_out: (IVP_U_Float_Point *)&world_speed0.k[1],
        rot_out: (IVP_U_Float_Point *)&world_speed1.k[1]);
      IVP_Core::get_surface_speed_on_test(
        this: this->core[0],
        point_cs: this->obj_point[0],
        center_speed_ws: (IVP_U_Float_Point *)&world_speed0.k[1],
        rot_speed_cs: (IVP_U_Float_Point *)&world_speed1.k[1],
        speed_out_ws: (IVP_U_Float_Point *)&translation.k[1]);
      v15 = v53;
      v11 = v50;
      v12 = v49;
      v17 = (float)((float)((float)(translation.k[1] * diff_vec_world.k[1])
                          + (float)(translation.k[2] * diff_vec_world.k[2]))
                  + (float)(translation.hesse_val * diff_vec_world.hesse_val))
          + v48;
      v13 = speed_change_scalar;
    }
    v23 = v15 / (float)(v17 + 1.0e-15);
    v24 = v23;
    v53 = v23;
    if ( v23 >= 0.0 )
    {
      if ( (*(_BYTE *)&this->core[0]->IVP_Core_Fast_Static & 2) == 0 )
      {
        v25 = this->m_world_f_core[0];
        speed_change_vec.k[1] = COERCE_FLOAT(LODWORD(v23) ^ _mask__NegFloat_) * v12;
        speed_change_vec.k[2] = v11 * COERCE_FLOAT(LODWORD(v23) ^ _mask__NegFloat_);
        speed_change_vec.hesse_val = v13 * COERCE_FLOAT(LODWORD(v23) ^ _mask__NegFloat_);
        IVP_U_Matrix3::vimult3(
          this: v25,
          p_in: (IVP_U_Float_Point *)&speed_change_vec.k[1],
          p_out: (IVP_U_Float_Point *)&rotation_vec.k[1]);
        IVP_Core::test_push_core(
          this: this->core[0],
          point_cs: this->obj_point[0],
          impulse_in_core: (IVP_U_Float_Point *)&rotation_vec.k[1],
          impulse_in_world: (IVP_U_Float_Point *)&speed_change_vec.k[1],
          speed_out: this->trans_speed_change,
          rot_out: this->rot_speed_change);
        v26 = this->rot_speed_change[0].k[2] + this->rot_speed[0].k[2];
        v27 = this->rot_speed[0].k[0] + this->rot_speed_change[0].k[0];
        v11 = v50;
        v12 = v49;
        this->rot_speed[0].k[1] = this->rot_speed_change[0].k[1] + this->rot_speed[0].k[1];
        this->rot_speed[0].k[2] = v26;
        this->rot_speed[0].k[0] = v27;
        v28 = this->trans_speed_change[0].k[2] + this->trans_speed[0].k[2];
        v29 = this->trans_speed_change[0].k[0] + this->trans_speed[0].k[0];
        this->trans_speed[0].k[1] = this->trans_speed_change[0].k[1] + this->trans_speed[0].k[1];
        v24 = v53;
        this->trans_speed[0].k[2] = v28;
        v13 = speed_change_scalar;
        this->trans_speed[0].k[0] = v29;
      }
      if ( (*(_BYTE *)&this->core[1]->IVP_Core_Fast_Static & 2) == 0 )
      {
        v30 = this->m_world_f_core[1];
        speed_change_vec.k[1] = v12 * v24;
        speed_change_vec.k[2] = v11 * v24;
        speed_change_vec.hesse_val = v13 * v24;
        IVP_U_Matrix3::vimult3(
          this: v30,
          p_in: (IVP_U_Float_Point *)&speed_change_vec.k[1],
          p_out: (IVP_U_Float_Point *)&rotation_vec.k[1]);
        IVP_Core::test_push_core(
          this: this->core[1],
          point_cs: this->obj_point[1],
          impulse_in_core: (IVP_U_Float_Point *)&rotation_vec.k[1],
          impulse_in_world: (IVP_U_Float_Point *)&speed_change_vec.k[1],
          speed_out: &this->trans_speed_change[1],
          rot_out: &this->rot_speed_change[1]);
        v31 = this->rot_speed_change[1].k[1] + this->rot_speed[1].k[1];
        v32 = this->rot_speed_change[1].k[2] + this->rot_speed[1].k[2];
        this->rot_speed[1].k[0] = this->rot_speed_change[1].k[0] + this->rot_speed[1].k[0];
        this->rot_speed[1].k[1] = v31;
        this->rot_speed[1].k[2] = v32;
        v33 = this->trans_speed_change[1].k[1] + this->trans_speed[1].k[1];
        v34 = this->trans_speed_change[1].k[2] + this->trans_speed[1].k[2];
        this->trans_speed[1].k[0] = this->trans_speed_change[1].k[0] + this->trans_speed[1].k[0];
        this->trans_speed[1].k[1] = v33;
        this->trans_speed[1].k[2] = v34;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087970
// Name: private: void IVP_Impact_Solver::delay_of_impact(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_Solver::delay_of_impact(IVP_Impact_Solver *this, int delayed_core_nr)
{
  IVP_Core *v2; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v2 = this->core[delayed_core_nr];
  v3 = this->trans_speed[delayed_core_nr].k[1] - v2->speed.k[1];
  v4 = this->trans_speed[delayed_core_nr].k[2] - v2->speed.k[2];
  v2->speed_change.k[0] = this->trans_speed[delayed_core_nr].k[0] - v2->speed.k[0];
  v2->speed_change.k[1] = v3;
  v2->speed_change.k[2] = v4;
  v5 = this->rot_speed[delayed_core_nr].k[1] - v2->rot_speed.k[1];
  v6 = this->rot_speed[delayed_core_nr].k[2] - v2->rot_speed.k[2];
  v2->rot_speed_change.k[0] = this->rot_speed[delayed_core_nr].k[0] - v2->rot_speed.k[0];
  v2->rot_speed_change.k[1] = v5;
  v2->rot_speed_change.k[2] = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10087A10
// Name: private: void IVP_Impact_Solver::clear_change_values_cores(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_Solver::clear_change_values_cores(IVP_Impact_Solver *this)
{
  IVP_Core *v1; // eax
  IVP_Core *v2; // eax

  v1 = this->core[0];
  *(_QWORD *)&v1->rot_speed_change.k[1] = 0;
  v1->rot_speed_change.k[0] = 0.0;
  *(_QWORD *)&v1->speed_change.k[1] = 0;
  v1->speed_change.k[0] = 0.0;
  v2 = this->core[1];
  *(_QWORD *)&v2->rot_speed_change.k[1] = 0;
  v2->rot_speed_change.k[0] = 0.0;
  *(_QWORD *)&v2->speed_change.k[1] = 0;
  v2->speed_change.k[0] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10087A80
// Name: private: void IVP_Impact_Solver::do_push(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Impact_Solver::do_push(IVP_Impact_Solver *this@<ecx>, int a2@<ebp>, float impulse_val)
{
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  IVP_Core *v7; // ecx
  float v8; // xmm2_4
  float v9; // xmm0_4
  float hesse_val; // xmm1_4
  IVP_U_Matrix *v11; // eax
  float v12; // xmm4_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  IVP_Core *v23; // ecx
  IVP_U_Matrix *v24; // eax
  float v25; // xmm4_4
  float v26; // xmm7_4
  float v27; // xmm3_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  const IVP_U_Float_Point *v36; // [esp-30h] [ebp-60h]
  const IVP_U_Float_Point *v37; // [esp-30h] [ebp-60h]
  float v38[3]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Float_Point obj_push; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Float_Point world_push; // [esp+10h] [ebp-20h]
  float v41; // [esp+20h] [ebp-10h]
  int v42; // [esp+24h] [ebp-Ch]
  void *v43; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  v42 = a2;
  v43 = retaddr;
  v4 = this->world_push_direction.k[0];
  v5 = this->world_push_direction.k[1];
  v6 = this->world_push_direction.k[2];
  v7 = this->core[0];
  v8 = v4 * impulse_val;
  v9 = v5 * impulse_val;
  hesse_val = v6 * impulse_val;
  obj_push.k[1] = v8;
  obj_push.k[2] = v9;
  obj_push.hesse_val = hesse_val;
  if ( (*(_BYTE *)&v7->IVP_Core_Fast_Static & 2) == 0 )
  {
    v11 = this->m_world_f_core[0];
    v12 = v11->rows[2].k[1];
    v13 = v11->rows[0].k[0];
    v14 = v11->rows[0].k[1];
    v15 = v11->rows[1].k[1];
    world_push.hesse_val = v11->rows[1].k[2];
    world_push.k[2] = v11->rows[2].k[2];
    v16 = (float)(v11->rows[1].k[0] * v9) + (float)(v13 * v8);
    v17 = v11->rows[2].k[0];
    v41 = v12;
    v18 = v11->rows[0].k[2];
    v38[0] = v16 + (float)(v17 * hesse_val);
    v36 = this->obj_point[0];
    v38[1] = (float)((float)(v9 * v15) + (float)(v14 * v8)) + (float)(hesse_val * v41);
    v38[2] = (float)((float)(v9 * world_push.hesse_val) + (float)(v18 * v8)) + (float)(hesse_val * world_push.k[2]);
    IVP_Core::test_push_core(
      this: v7,
      point_cs: v36,
      impulse_in_core: (const IVP_U_Float_Point *)v38,
      impulse_in_world: (IVP_U_Float_Point *)&obj_push.k[1],
      speed_out: this->trans_speed_change,
      rot_out: this->rot_speed_change);
    v19 = this->rot_speed_change[0].k[1] + this->rot_speed[0].k[1];
    v20 = this->rot_speed_change[0].k[2] + this->rot_speed[0].k[2];
    this->rot_speed[0].k[0] = this->rot_speed[0].k[0] + this->rot_speed_change[0].k[0];
    this->rot_speed[0].k[1] = v19;
    this->rot_speed[0].k[2] = v20;
    v21 = this->trans_speed_change[0].k[1] + this->trans_speed[0].k[1];
    v22 = this->trans_speed_change[0].k[2] + this->trans_speed[0].k[2];
    this->trans_speed[0].k[0] = this->trans_speed[0].k[0] + this->trans_speed_change[0].k[0];
    v8 = obj_push.k[1];
    this->trans_speed[0].k[1] = v21;
    v9 = obj_push.k[2];
    this->trans_speed[0].k[2] = v22;
    hesse_val = obj_push.hesse_val;
  }
  v23 = this->core[1];
  if ( (*(_BYTE *)&v23->IVP_Core_Fast_Static & 2) == 0 )
  {
    v24 = this->m_world_f_core[1];
    obj_push.k[2] = v9 * -1.0;
    obj_push.k[1] = v8 * -1.0;
    obj_push.hesse_val = hesse_val * -1.0;
    v25 = v24->rows[2].k[1];
    v26 = v24->rows[0].k[0];
    v27 = v24->rows[0].k[1];
    v28 = v24->rows[1].k[1];
    world_push.hesse_val = v24->rows[1].k[2];
    v41 = v24->rows[2].k[2];
    v29 = (float)(v24->rows[1].k[0] * (float)(v9 * -1.0)) + (float)(v26 * (float)(v8 * -1.0));
    v30 = v24->rows[2].k[0];
    world_push.k[2] = v25;
    v31 = v24->rows[0].k[2];
    v38[0] = v29 + (float)(v30 * (float)(hesse_val * -1.0));
    v37 = this->obj_point[1];
    v38[1] = (float)((float)((float)(v9 * -1.0) * v28) + (float)(v27 * (float)(v8 * -1.0)))
           + (float)((float)(hesse_val * -1.0) * world_push.k[2]);
    v38[2] = (float)((float)((float)(v9 * -1.0) * world_push.hesse_val) + (float)(v31 * (float)(v8 * -1.0)))
           + (float)((float)(hesse_val * -1.0) * v41);
    IVP_Core::test_push_core(
      this: v23,
      point_cs: v37,
      impulse_in_core: (const IVP_U_Float_Point *)v38,
      impulse_in_world: (IVP_U_Float_Point *)&obj_push.k[1],
      speed_out: &this->trans_speed_change[1],
      rot_out: &this->rot_speed_change[1]);
    v32 = this->rot_speed_change[1].k[1] + this->rot_speed[1].k[1];
    v33 = this->rot_speed_change[1].k[2] + this->rot_speed[1].k[2];
    this->rot_speed[1].k[0] = this->rot_speed[1].k[0] + this->rot_speed_change[1].k[0];
    this->rot_speed[1].k[1] = v32;
    this->rot_speed[1].k[2] = v33;
    v34 = this->trans_speed_change[1].k[1] + this->trans_speed[1].k[1];
    v35 = this->trans_speed_change[1].k[2] + this->trans_speed[1].k[2];
    this->trans_speed[1].k[0] = this->trans_speed_change[1].k[0] + this->trans_speed[1].k[0];
    this->trans_speed[1].k[1] = v34;
    this->trans_speed[1].k[2] = v35;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087D60
// Name: private: void IVP_Impact_Solver::calc_virt_masses_impact_solver(class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Impact_Solver::calc_virt_masses_impact_solver(
        IVP_Impact_Solver *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Float_Point *world_direction_normal)
{
  float v3; // xmm0_4
  int v4; // edi
  const IVP_U_Float_Point **v5; // esi
  IVP_Impact_Solver *v6; // eax
  _BYTE v7[12]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Float_Point direction_obj; // [esp+0h] [ebp-30h] BYREF
  IVP_Impact_Solver *v9; // [esp+20h] [ebp-10h]
  _DWORD v10[3]; // [esp+24h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h]

  v10[0] = a2;
  v10[1] = retaddr;
  direction_obj.k[1] = world_direction_normal->k[0];
  direction_obj.k[2] = world_direction_normal->k[1];
  v3 = world_direction_normal->k[2];
  v9 = this;
  direction_obj.hesse_val = v3;
  v4 = 1;
  v5 = (const IVP_U_Float_Point **)&this->obj_point[1];
  do
  {
    IVP_U_Matrix3::vimult3(
      this: (IVP_U_Matrix3 *)*(v5 - 59),
      p_in: (IVP_U_Float_Point *)&direction_obj.k[1],
      p_out: (IVP_U_Float_Point *)v7);
    *((float *)v5 - 65) = IVP_Core::calc_correct_virt_mass(
                            this: (IVP_Core *)*(v5 - 2),
                            a2: COERCE_FLOAT(v10),
                            core_point: *v5,
                            direction_core: (const IVP_U_Float_Point *)v7,
                            direction_world: (IVP_U_Float_Point *)&direction_obj.k[1]);
    direction_obj.k[1] = direction_obj.k[1] * -1.0;
    direction_obj.k[2] = direction_obj.k[2] * -1.0;
    --v5;
    --v4;
    direction_obj.hesse_val = direction_obj.hesse_val * -1.0;
  }
  while ( v4 >= 0 );
  v6 = v9;
  if ( (*(_BYTE *)&v9->core[0]->IVP_Core_Fast_Static & 2) != 0 )
    v9->virt_mass[0] = v9->virt_mass[1] * 100000.0;
  if ( (*(_BYTE *)&v6->core[1]->IVP_Core_Fast_Static & 2) != 0 )
    v6->virt_mass[1] = v6->virt_mass[0] * 100000.0;
}

//------------------------------------------------------------------------------
// Address: 0x10087E60
// Name: private: float IVP_Impact_Solver::estimate_push_impulse(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall IVP_Impact_Solver::estimate_push_impulse@<st0>(IVP_Impact_Solver *this@<ecx>, int a2@<ebp>)
{
  IVP_U_Float_Point *surf_normal; // eax

  IVP_Impact_Solver::calc_virt_masses_impact_solver(this, a2, world_direction_normal: this->surf_normal);
  surf_normal = this->surf_normal;
  return 1.0
       / (this->virt_mass[1] + this->virt_mass[0])
       * (-(surf_normal->k[1] * this->relative_world_speed.k[1]
          + surf_normal->k[0] * this->relative_world_speed.k[0]
          + surf_normal->k[2] * this->relative_world_speed.k[2])
        * (this->virt_mass[1] + this->virt_mass[1])
        + (this->virt_mass[0] - this->virt_mass[1]) * 0.0)
       * this->virt_mass[0];
}

//------------------------------------------------------------------------------
// Address: 0x10087EC0
// Name: public: void IVP_Contact_Point::get_material_info(class IVP_Material __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Contact_Point::get_material_info(IVP_Contact_Point *this, IVP_Material **mtl)
{
  IVP_Real_Object **p_l_obj; // edi
  int v4; // esi
  IVP_Material_Manager *l_material_manager; // ecx
  IVP_Real_Object **v6; // [esp+Ch] [ebp-4h]
  int mat_index; // [esp+18h] [ebp+8h]

  p_l_obj = &this->synapse[0].l_obj;
  v4 = 0;
  v6 = &this->synapse[0].l_obj;
  do
  {
    mat_index = IVP_Synapse_Friction::get_material_index(this: (IVP_Synapse_Friction *)(p_l_obj - 2));
    if ( mat_index != 0 )
    {
      l_material_manager = (*v6)->environment->l_material_manager;
      mtl[v4] = l_material_manager->get_material_by_index(
                  this: l_material_manager,
                  a2: *p_l_obj,
                  a3: nullptr,
                  a4: mat_index);
    }
    else
    {
      mtl[v4] = (*p_l_obj)->l_default_material;
    }
    ++v4;
    p_l_obj += 5;
  }
  while ( v4 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x10087F20
// Name: private: void IVP_Contact_Point::read_materials_for_contact_situation(class IVP_Impact_Solver_Long_Term __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Contact_Point::read_materials_for_contact_situation(
        IVP_Contact_Point *this,
        IVP_Impact_Solver_Long_Term *info)
{
  IVP_Real_Object *l_obj; // ebx
  IVP_Environment *environment; // eax
  IVP_Material_Manager *l_material_manager; // ebx
  IVP_Real_Object *obj1; // [esp+Ch] [ebp-4h]

  l_obj = this->synapse[0].l_obj;
  obj1 = this->synapse[1].l_obj;
  IVP_Contact_Point::get_material_info(this, mtl: info->materials);
  environment = l_obj->environment;
  info->objects[1] = obj1;
  info->objects[0] = l_obj;
  info->compact_edges[0] = this->synapse[0].edge;
  info->compact_edges[1] = this->synapse[1].edge;
  l_material_manager = environment->l_material_manager;
  info->impact.percent_energy_conservation = l_material_manager->get_elasticity(this: l_material_manager, a2: info);
  this->real_friction_factor = l_material_manager->get_friction_factor(this: l_material_manager, a2: info);
}

//------------------------------------------------------------------------------
// Address: 0x10087F90
// Name: public: void IVP_Impact_Solver::get_world_direction_second_friction(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Impact_Solver::get_world_direction_second_friction(
        IVP_Impact_Solver *this@<ecx>,
        float a2@<ebp>,
        double a3@<esi:edi>,
        IVP_Contact_Point *cp)
{
  int v4; // eax
  float v5; // esi
  _DWORD *v6; // eax
  IVP_Impact_Solver_Long_Term *tmp_contact_info; // edx
  double v8; // st7
  float real_friction_factor; // xmm0_4
  IVP_Impact_Solver *v10; // esi
  double v11; // xmm0_8
  long double v12; // [esp-1Ch] [ebp-6Ch]
  _DWORD v13[3]; // [esp-Ch] [ebp-5Ch] BYREF
  IVP_U_Float_Point x_direction; // [esp+0h] [ebp-50h] BYREF
  IVP_U_Float_Point x_in_surface; // [esp+10h] [ebp-40h] BYREF
  float v16; // [esp+20h] [ebp-30h]
  IVP_Material *mtl[2]; // [esp+24h] [ebp-2Ch]
  int v18; // [esp+2Ch] [ebp-24h]
  IVP_Impact_Solver *effective_friction_second; // [esp+30h] [ebp-20h]
  int second_friction_val; // [esp+34h] [ebp-1Ch]
  IVP_BOOL use_second_friction; // [esp+38h] [ebp-18h]
  float *p_hesse_val; // [esp+3Ch] [ebp-14h]
  int i; // [esp+40h] [ebp-10h]
  float relevance_factor; // [esp+44h] [ebp-Ch]
  void *v25; // [esp+48h] [ebp-8h]
  void *retaddr; // [esp+50h] [ebp+0h]

  relevance_factor = a2;
  v25 = retaddr;
  v12 = a3;
  effective_friction_second = this;
  IVP_Contact_Point::get_material_info(this: cp, mtl: (IVP_Material **)&x_in_surface.k[2]);
  v4 = 0;
  v18 = 0;
  second_friction_val = 0;
  p_hesse_val = &x_in_surface.hesse_val;
  i = (int)&cp->synapse[0].l_obj;
  do
  {
    v5 = x_in_surface.k[v4 + 2];
    if ( *(_DWORD *)(LODWORD(v5) + 8) != 0 )
    {
      v6 = *(_DWORD **)(*(_DWORD *)i + 152);
      tmp_contact_info = cp->tmp_contact_info;
      v13[0] = v6[24];
      v13[1] = v6[28];
      v13[2] = v6[32];
      IVP_U_Float_Point::set_orthogonal_part(
        this: (IVP_U_Float_Point *)&x_direction.k[1],
        vector: (const IVP_U_Float_Point *)v13,
        normal_v: &tmp_contact_info->surf_normal);
      *(float *)&use_second_friction = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&x_direction.k[1]);
      *(float *)&mtl[1] = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v5) + 8))(a1: LODWORD(v5));
      v8 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)p_hesse_val + 4))(a1: *(_DWORD *)p_hesse_val);
      real_friction_factor = cp->real_friction_factor;
      *(float *)&mtl[1] = v8 * *(float *)&mtl[1];
      *(float *)mtl = real_friction_factor
                    - (float)((float)(real_friction_factor - *(float *)&mtl[1]) * *(float *)&use_second_friction);
      if ( *(float *)&use_second_friction >= 1.0e-10 )
      {
        v18 = 1;
        IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&x_direction.k[1]);
        v10 = effective_friction_second;
        effective_friction_second->world_direction_second_friction.k[0] = x_direction.k[1];
        v10->world_direction_second_friction.k[1] = x_direction.k[2];
        v10->world_direction_second_friction.k[2] = x_direction.hesse_val;
        v16 = (float)(fsqrt(v10->percent_energy_conservation) + 1.0) * *(float *)mtl;
        v11 = v16;
        __libm_sse2_atan(x: v12);
        *(float *)&v11 = v11;
        v10->sin_second_friction = (float)((float)(1.0 - (float)((float)(*(float *)&v11 * *(float *)&v11) * 0.5))
                                         + (float)((float)((float)(*(float *)&v11 * *(float *)&v11) * 0.041666668)
                                                 * (float)(*(float *)&v11 * *(float *)&v11)))
                                 * v16;
      }
    }
    i += 20;
    --p_hesse_val;
    v4 = second_friction_val + 1;
    second_friction_val = v4;
  }
  while ( v4 < 2 );
  effective_friction_second->two_friction_values = v18;
}

//------------------------------------------------------------------------------
// Address: 0x10088140
// Name: private: float IVP_Contact_Point::get_rot_speed_uncertainty(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall IVP_Contact_Point::get_rot_speed_uncertainty@<st0>(
        IVP_Contact_Point *this@<ecx>,
        double a2@<esi:edi>)
{
  __int16 *p_status; // ebx
  IVP_Core **contact_core; // esi
  IVP_Core *v4; // edi
  float v5; // xmm0_4
  long double v7; // [esp-Ch] [ebp-14h]
  int i; // [esp+0h] [ebp-8h]
  float rot_uncertainty; // [esp+4h] [ebp-4h]

  v7 = a2;
  rot_uncertainty = 0.0;
  p_status = &this->synapse[0].status;
  contact_core = this->tmp_contact_info->contact_core;
  for ( i = 2; i != 0; --i )
  {
    v4 = *contact_core;
    if ( *contact_core != nullptr && *p_status != 3 )
    {
      v5 = (float)((float)((float)((float)(v4->rot_speed.k[0] * v4->rot_speed.k[0])
                                 + (float)(v4->rot_speed.k[1] * v4->rot_speed.k[1]))
                         + (float)(v4->rot_speed.k[2] * v4->rot_speed.k[2]))
                 * 0.0049999999)
         * 0.0049999999;
      if ( v5 > 0.25 )
        v5 = 0.25;
      __libm_sse2_cos(x: v7);
      rot_uncertainty = (float)((float)((float)(1.0 - fsqrt(v5)) * v4->upper_limit_radius)
                              * v4->environment->inv_delta_PSI_time)
                      + rot_uncertainty;
    }
    ++contact_core;
    p_status += 10;
  }
  return rot_uncertainty;
}

//------------------------------------------------------------------------------
// Address: 0x10088220
// Name: private: void IVP_Impact_Solver::get_world_push_direction(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Impact_Solver::get_world_push_direction(IVP_Impact_Solver *this@<ecx>, float a2@<ebp>)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  IVP_U_Float_Point *p_world_push_direction; // esi
  IVP_U_Float_Point *surf_normal; // eax
  float v7; // xmm2_4
  float v8; // xmm4_4
  float part_direction_surf_normal; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float sin_friction; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float cos_friction; // xmm0_4
  IVP_U_Float_Point *v20; // edi
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // [esp+14h] [ebp-1Ch] BYREF
  float v25; // [esp+18h] [ebp-18h]
  float v26; // [esp+1Ch] [ebp-14h]
  IVP_U_Float_Point part_in_direction_surf; // [esp+20h] [ebp-10h] BYREF
  float retaddr; // [esp+30h] [ebp+0h]

  part_in_direction_surf.k[1] = a2;
  part_in_direction_surf.k[2] = retaddr;
  v3 = this->relative_world_speed.k[1];
  v4 = this->relative_world_speed.k[2];
  this->world_push_direction.k[0] = this->relative_world_speed.k[0];
  p_world_push_direction = &this->world_push_direction;
  this->world_push_direction.k[1] = v3;
  this->world_push_direction.k[2] = v4;
  IVP_U_Float_Point::fast_normize(this: &this->world_push_direction);
  surf_normal = this->surf_normal;
  v7 = p_world_push_direction->k[1];
  v8 = p_world_push_direction->k[2];
  part_direction_surf_normal = (float)((float)(surf_normal->k[1] * v7)
                                     + (float)(surf_normal->k[0] * p_world_push_direction->k[0]))
                             + (float)(surf_normal->k[2] * v8);
  if ( part_direction_surf_normal <= 0.0 )
  {
    if ( this->two_friction_values != IVP_FALSE )
    {
      IVP_Impact_Solver::get_world_push_direction_two_friction(
        this,
        a2: (int)&part_in_direction_surf.k[1],
        a3: (int)p_world_push_direction,
        part_direction_surf_normal);
    }
    else if ( part_direction_surf_normal > (float)-this->cos_friction )
    {
      v12 = -part_direction_surf_normal;
      v13 = (float)(surf_normal->k[1] * v12) + v7;
      v14 = (float)(surf_normal->k[2] * v12) + v8;
      v24 = (float)(surf_normal->k[0] * v12) + p_world_push_direction->k[0];
      v25 = v13;
      v26 = v14;
      IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&v24);
      sin_friction = this->sin_friction;
      v16 = v25 * sin_friction;
      v17 = v26 * sin_friction;
      v18 = v24 * sin_friction;
      cos_friction = this->cos_friction;
      v20 = this->surf_normal;
      LODWORD(v21) = LODWORD(cos_friction) ^ _mask__NegFloat_;
      v25 = v16;
      v26 = v17;
      v24 = v18;
      v22 = (float)(v20->k[1] * v21) + v16;
      v23 = (float)(v20->k[2] * v21) + v17;
      p_world_push_direction->k[0] = (float)(v20->k[0] * v21) + v18;
      p_world_push_direction->k[1] = v22;
      p_world_push_direction->k[2] = v23;
    }
  }
  else
  {
    v10 = this->integral_pushes_world.k[1];
    v11 = this->integral_pushes_world.k[2];
    p_world_push_direction->k[0] = this->integral_pushes_world.k[0];
    p_world_push_direction->k[1] = v10;
    p_world_push_direction->k[2] = v11;
    IVP_U_Float_Point::fast_normize(this: p_world_push_direction);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100883F0
// Name: private: void IVP_Impact_Solver::delay_decision(class IVP_Core __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Impact_Solver::delay_decision(
        IVP_Impact_Solver *this@<ecx>,
        int a2@<ebp>,
        IVP_Core **pushed_cores)
{
  int v4; // edi
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  IVP_U_Float_Point *v8; // edx
  int v9; // eax
  const IVP_Core *v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  IVP_Core *v14; // eax
  const IVP_U_Float_Point *v15; // edx
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  IVP_Core *v21; // eax
  IVP_Core *v22; // eax
  IVP_Core *v23; // eax
  IVP_Core *v24; // eax
  IVP_Core *v25; // edi
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  IVP_Environment *environment; // eax
  IVP_Anomaly_Limits *anomaly_limits; // edx
  IVP_Core *v32; // edi
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  IVP_Environment *v37; // eax
  IVP_Anomaly_Limits *v38; // edx
  const IVP_U_Float_Point *v39; // [esp-34h] [ebp-94h]
  float v40[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Float_Point rel_world_speed; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Float_Point delayer_trans_speed; // [esp+10h] [ebp-50h] BYREF
  IVP_U_Float_Point delayer_rot_speed; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Float_Point other_trans_speed; // [esp+30h] [ebp-30h] BYREF
  int v45; // [esp+54h] [ebp-Ch]
  void *v46; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v45 = a2;
  v46 = retaddr;
  this->core[0]->impacts_since_last_PSI += (*(_WORD *)&this->core[0]->IVP_Core_Fast_Static & 2) == 0;
  this->core[1]->impacts_since_last_PSI += (*(_WORD *)&this->core[1]->IVP_Core_Fast_Static & 2) == 0;
  if ( this->delaying_is_allowed == IVP_FALSE )
    goto no_delaying;
  if ( this->virt_mass[0] <= this->virt_mass[1] )
  {
    v4 = 1;
    v5 = 0;
  }
  else
  {
    v4 = 0;
    v5 = 1;
  }
  if ( (*(_BYTE *)&pushed_cores[v4]->IVP_Core_Fast_Static & 2) != 0 )
    goto no_delaying;
  v6 = this->rot_speed[v5].k[1];
  v7 = this->rot_speed[v5].k[2];
  other_trans_speed.k[1] = this->rot_speed[v5].k[0];
  other_trans_speed.k[2] = v6;
  other_trans_speed.hesse_val = v7;
  v8 = this->obj_point[v5];
  v9 = v5 + 5;
  v10 = this->core[v5];
  v9 *= 2;
  v11 = this->virt_mass[2 * v9];
  v12 = this->virt_mass[2 * v9 + 1];
  v13 = *(&this->rescue_speed_impact_solver + 2 * v9);
  v14 = this->core[v4];
  v39 = v8;
  v15 = this->obj_point[v4];
  delayer_rot_speed.k[1] = v13;
  delayer_rot_speed.k[2] = v11;
  delayer_rot_speed.hesse_val = v12;
  v16 = v14->rot_speed.k[1];
  v17 = v14->rot_speed.k[2];
  delayer_trans_speed.k[1] = v14->rot_speed.k[0];
  delayer_trans_speed.k[2] = v16;
  delayer_trans_speed.hesse_val = v17;
  v18 = v14->speed.k[1];
  v19 = v14->speed.k[2];
  rel_world_speed.k[1] = v14->speed.k[0];
  rel_world_speed.k[2] = v18;
  rel_world_speed.hesse_val = v19;
  IVP_Core::get_diff_surface_speed_of_two_cores_on_test(
    this_core: v14,
    other_core: v10,
    obj_point_this: v15,
    obj_point_other: v39,
    trans_speed0: (IVP_U_Float_Point *)&rel_world_speed.k[1],
    rot_speed0: (IVP_U_Float_Point *)&delayer_trans_speed.k[1],
    trans_speed1: (IVP_U_Float_Point *)&delayer_rot_speed.k[1],
    rot_speed1: (IVP_U_Float_Point *)&other_trans_speed.k[1],
    diff_speed_this_minus_other_out: (IVP_U_Float_Point *)v40);
  v20 = (float)((float)(this->surf_normal->k[1] * v40[1]) + (float)(this->surf_normal->k[0] * v40[0]))
      + (float)(this->surf_normal->k[2] * v40[2]);
  if ( v4 != 0 )
    v20 = v20 * -1.0;
  if ( (float)(this->rescue_speed_impact_solver * -0.83333331) <= v20 )
  {
no_delaying:
    v21 = this->core[0];
    v21->rot_speed_change.k[2] = 0.0;
    v21->rot_speed_change.k[1] = 0.0;
    v21->rot_speed_change.k[0] = 0.0;
    v22 = this->core[0];
    v22->speed_change.k[2] = 0.0;
    v22->speed_change.k[1] = 0.0;
    v22->speed_change.k[0] = 0.0;
    v23 = this->core[1];
    v23->rot_speed_change.k[2] = 0.0;
    v23->rot_speed_change.k[1] = 0.0;
    v23->rot_speed_change.k[0] = 0.0;
    v24 = this->core[1];
    v24->speed_change.k[2] = 0.0;
    v24->speed_change.k[1] = 0.0;
    v24->speed_change.k[0] = 0.0;
    v25 = this->core[0];
    v26 = this->trans_speed[0].k[1];
    v27 = this->trans_speed[0].k[2];
    v25->speed.k[0] = this->trans_speed[0].k[0];
    v25->speed.k[1] = v26;
    v25->speed.k[2] = v27;
    v28 = this->rot_speed[0].k[1];
    v29 = this->rot_speed[0].k[2];
    v25->rot_speed.k[0] = this->rot_speed[0].k[0];
    v25->rot_speed.k[1] = v28;
    v25->rot_speed.k[2] = v29;
    environment = v25->environment;
    anomaly_limits = environment->anomaly_limits;
    if ( v25->impacts_since_last_PSI > anomaly_limits->max_collisions_per_psi )
      *(_WORD *)&v25->IVP_Core_Fast_Static ^= (*(_WORD *)&v25->IVP_Core_Fast_Static
                                             ^ ((unsigned __int16)environment->anomaly_manager->max_collisions_exceeded_check_freezing(
                                                                    this: environment->anomaly_manager,
                                                                    a2: anomaly_limits,
                                                                    a3: v25) << 6))
                                            & 0xC0;
    v32 = this->core[1];
    v33 = this->trans_speed[1].k[1];
    v34 = this->trans_speed[1].k[2];
    v32->speed.k[0] = this->trans_speed[1].k[0];
    v32->speed.k[1] = v33;
    v32->speed.k[2] = v34;
    v35 = this->rot_speed[1].k[1];
    v36 = this->rot_speed[1].k[2];
    v32->rot_speed.k[0] = this->rot_speed[1].k[0];
    v32->rot_speed.k[1] = v35;
    v32->rot_speed.k[2] = v36;
    v37 = v32->environment;
    v38 = v37->anomaly_limits;
    if ( v32->impacts_since_last_PSI > v38->max_collisions_per_psi )
      *(_WORD *)&v32->IVP_Core_Fast_Static ^= (*(_WORD *)&v32->IVP_Core_Fast_Static
                                             ^ ((unsigned __int16)v37->anomaly_manager->max_collisions_exceeded_check_freezing(
                                                                    this: v37->anomaly_manager,
                                                                    a2: v38,
                                                                    a3: v32) << 6))
                                            & 0xC0;
  }
  else
  {
    ++this->core[0]->environment->statistic_manager.impact_delayed_counter;
    pushed_cores[v4] = nullptr;
    IVP_Impact_Solver::clear_change_values_cores(this);
    IVP_Impact_Solver::confirm_impact(this, core_nr: 1 - v4);
    IVP_Impact_Solver::delay_of_impact(this, delayed_core_nr: v4);
    --this->core[v4]->impacts_since_last_PSI;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088760
// Name: private: void IVP_Impact_System::impact_system_check_start_pair(class IVP_Friction_Core_Pair __near *,class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_System::impact_system_check_start_pair(
        IVP_Impact_System *this,
        IVP_Friction_Core_Pair *start_pair,
        IVP_Contact_Point *mdfr)
{
  int v3; // eax
  IVP_Contact_Point *v4; // edi
  IVP_Impact_Solver_Long_Term *tmp_contact_info; // esi
  IVP_Real_Object *l_obj; // ebx
  IVP_Environment *environment; // eax
  IVP_Material_Manager *l_material_manager; // ebx
  IVP_Real_Object *v9; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  v3 = start_pair->fr_dists.n_elems - 1;
  i = v3;
  if ( start_pair->fr_dists.n_elems != 0 )
  {
    do
    {
      v4 = (IVP_Contact_Point *)start_pair->fr_dists.elems[v3];
      if ( mdfr != v4 )
      {
        IVP_Contact_Point::recalc_friction_s_vals(this: v4, env: this->l_environment);
        tmp_contact_info = v4->tmp_contact_info;
        l_obj = v4->synapse[0].l_obj;
        v9 = v4->synapse[1].l_obj;
        IVP_Contact_Point::get_material_info(this: v4, mtl: tmp_contact_info->materials);
        environment = l_obj->environment;
        tmp_contact_info->objects[1] = v9;
        tmp_contact_info->objects[0] = l_obj;
        tmp_contact_info->compact_edges[0] = v4->synapse[0].edge;
        tmp_contact_info->compact_edges[1] = v4->synapse[1].edge;
        l_material_manager = environment->l_material_manager;
        tmp_contact_info->impact.percent_energy_conservation = l_material_manager->get_elasticity(
                                                                 this: l_material_manager,
                                                                 a2: tmp_contact_info);
        v4->real_friction_factor = l_material_manager->get_friction_factor(
                                     this: l_material_manager,
                                     a2: tmp_contact_info);
        if ( tmp_contact_info->friction_is_broken == 1 )
          IVP_Friction_System::delete_friction_distance(this: this->associated_fs_system, old_dist: v4);
      }
      v3 = --i;
    }
    while ( i >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088820
// Name: public: void IVP_Impact_Solver::do_impact(class IVP_Core __near * __near * const,enum IVP_BOOL,int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Impact_Solver::do_impact(
        IVP_Impact_Solver *this@<ecx>,
        float a2@<ebp>,
        IVP_Core **pushed_cores,
        IVP_BOOL allow_delaying,
        int pushes_while_system,
        float rescue_speed_addon)
{
  float v7; // xmm1_4
  IVP_Core *v8; // ecx
  float min_vertical_speed_at_collision; // xmm0_4
  IVP_Core *v10; // eax
  IVP_Core *v11; // edx
  float v12; // xmm1_4
  float v13; // xmm2_4
  IVP_Core *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  IVP_Core *v17; // eax
  float v18; // xmm1_4
  float v19; // xmm2_4
  IVP_Core *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  IVP_U_Float_Point *speed; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  double v26; // st7
  IVP_U_Float_Point *surf_normal; // eax
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  IVP_U_Float_Point *v32; // eax
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm5_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  IVP_Impact_Solver *v39; // ecx
  float v40; // edx
  bool v41; // zf
  float v42; // ecx
  int v43; // eax
  IVP_Core *v44; // edi
  float *environment; // ecx
  float v46; // edx
  IVP_Core *v47; // eax
  IVP_Core *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  IVP_Core *v53; // esi
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // [esp+14h] [ebp-4Ch] BYREF
  float v59; // [esp+18h] [ebp-48h]
  float v60; // [esp+1Ch] [ebp-44h]
  IVP_U_Float_Point push_dir; // [esp+20h] [ebp-40h] BYREF
  float impulse_val; // [esp+40h] [ebp-20h]
  float v63; // [esp+44h] [ebp-1Ch]
  float v64; // [esp+48h] [ebp-18h]
  float impulse; // [esp+4Ch] [ebp-14h]
  int v66; // [esp+50h] [ebp-10h]
  float virtual_speed; // [esp+54h] [ebp-Ch] BYREF
  float give_back_speed; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  virtual_speed = a2;
  give_back_speed = retaddr;
  v63 = (float)pushes_while_system;
  v7 = 1.0 - this->percent_energy_conservation;
  v8 = this->core[0];
  impulse = 1.0 - (float)((float)(1.0 / (float)((float)((float)pushes_while_system * 0.5) + 1.0)) * v7);
  min_vertical_speed_at_collision = ivp_mindist_settings.min_vertical_speed_at_collision;
  this->delaying_is_allowed = allow_delaying;
  this->rescue_speed_impact_solver = (float)(min_vertical_speed_at_collision + rescue_speed_addon) * 1.2;
  *pushed_cores = v8;
  pushed_cores[1] = this->core[1];
  ++this->core[0]->environment->statistic_manager.impact_counter;
  v10 = this->core[0];
  v11 = this->core[1];
  this->m_world_f_core[0] = &v10->m_world_f_core_last_psi;
  this->m_world_f_core[1] = &v11->m_world_f_core_last_psi;
  v12 = v10->rot_speed.k[2] + v10->rot_speed_change.k[2];
  v13 = v10->rot_speed.k[0] + v10->rot_speed_change.k[0];
  this->rot_speed[0].k[1] = v10->rot_speed.k[1] + v10->rot_speed_change.k[1];
  this->rot_speed[0].k[0] = v13;
  this->rot_speed[0].k[2] = v12;
  v14 = this->core[0];
  v15 = v14->speed.k[2] + v14->speed_change.k[2];
  v16 = v14->speed.k[0] + v14->speed_change.k[0];
  this->trans_speed[0].k[1] = v14->speed.k[1] + v14->speed_change.k[1];
  this->trans_speed[0].k[0] = v16;
  this->trans_speed[0].k[2] = v15;
  v17 = this->core[1];
  v18 = v17->rot_speed.k[2] + v17->rot_speed_change.k[2];
  v19 = v17->rot_speed_change.k[0] + v17->rot_speed.k[0];
  this->rot_speed[1].k[1] = v17->rot_speed.k[1] + v17->rot_speed_change.k[1];
  this->rot_speed[1].k[0] = v19;
  this->rot_speed[1].k[2] = v18;
  v20 = this->core[1];
  v21 = v20->speed.k[2] + v20->speed_change.k[2];
  v22 = v20->speed.k[0] + v20->speed_change.k[0];
  this->trans_speed[1].k[1] = v20->speed.k[1] + v20->speed_change.k[1];
  this->trans_speed[1].k[0] = v22;
  this->trans_speed[1].k[2] = v21;
  this->energy_deformation = 0.0;
  IVP_Core::get_surface_speed_on_test(
    this: this->core[0],
    point_cs: this->obj_point[0],
    center_speed_ws: this->trans_speed,
    rot_speed_cs: this->rot_speed,
    speed_out_ws: (IVP_U_Float_Point *)&v58);
  IVP_Core::get_surface_speed_on_test(
    this: this->core[1],
    point_cs: this->obj_point[1],
    center_speed_ws: &this->trans_speed[1],
    rot_speed_cs: &this->rot_speed[1],
    speed_out_ws: (IVP_U_Float_Point *)&push_dir.k[1]);
  this->relative_world_speed.k[0] = push_dir.k[1] - v58;
  this->relative_world_speed.k[1] = push_dir.k[2] - v59;
  this->relative_world_speed.k[2] = push_dir.hesse_val - v60;
  speed = this->speed;
  v24 = this->relative_world_speed.k[1];
  v25 = this->relative_world_speed.k[2];
  speed->k[0] = this->relative_world_speed.k[0];
  speed->k[1] = v24;
  speed->k[2] = v25;
  v66 = 0;
  v26 = IVP_Impact_Solver::estimate_push_impulse(this, a2: (int)&virtual_speed);
  surf_normal = this->surf_normal;
  v28 = surf_normal->k[1] * this->relative_world_speed.k[1];
  impulse_val = v26 * 0.1;
  if ( (float)((float)(v28 + (float)(surf_normal->k[0] * this->relative_world_speed.k[0]))
             + (float)(surf_normal->k[2] * this->relative_world_speed.k[2])) <= -0.000099999997 )
  {
    IVP_Impact_Solver::get_world_push_direction(this, a2: COERCE_FLOAT(&virtual_speed));
    v29 = fsqrt(v63) * 0.0099999998;
    *(_QWORD *)&this->integral_pushes_world.k[1] = 0;
    this->integral_pushes_world.k[0] = 0.0;
    LODWORD(v30) = COERCE_UNSIGNED_INT(
                     (float)((float)(this->surf_normal->k[1] * this->relative_world_speed.k[1])
                           + (float)(this->surf_normal->k[0] * this->relative_world_speed.k[0]))
                   + (float)(this->surf_normal->k[2] * this->relative_world_speed.k[2]))
                 ^ _mask__NegFloat_;
    v31 = (float)(fsqrt(impulse) * v30) + v29;
    v64 = v30;
    for ( impulse = v31; v64 > 0.0; v31 = impulse )
    {
      if ( v66 >= 100 )
        break;
      ++v66;
      IVP_Impact_Solver::do_push(this, a2: (int)&virtual_speed, impulse_val);
      IVP_Core::get_surface_speed_on_test(
        this: this->core[0],
        point_cs: this->obj_point[0],
        center_speed_ws: this->trans_speed,
        rot_speed_cs: this->rot_speed,
        speed_out_ws: (IVP_U_Float_Point *)&push_dir.k[1]);
      IVP_Core::get_surface_speed_on_test(
        this: this->core[1],
        point_cs: this->obj_point[1],
        center_speed_ws: &this->trans_speed[1],
        rot_speed_cs: &this->rot_speed[1],
        speed_out_ws: (IVP_U_Float_Point *)&v58);
      this->relative_world_speed.k[0] = v58 - push_dir.k[1];
      this->relative_world_speed.k[1] = v59 - push_dir.k[2];
      this->relative_world_speed.k[2] = v60 - push_dir.hesse_val;
      v64 = -(float)((float)((float)(this->surf_normal->k[1] * this->relative_world_speed.k[1])
                           + (float)(this->relative_world_speed.k[0] * this->surf_normal->k[0]))
                   + (float)(this->surf_normal->k[2] * this->relative_world_speed.k[2]));
      IVP_Impact_Solver::get_world_push_direction(this, a2: COERCE_FLOAT(&virtual_speed));
      v30 = v64;
    }
    v32 = this->surf_normal;
    v33 = v30 + v31;
    v34 = v32->k[1] * -1.0;
    v35 = v32->k[2] * -1.0;
    v36 = v32->k[0] * -1.0;
    impulse = v33;
    this->world_push_direction.k[0] = v36;
    this->world_push_direction.k[1] = v34;
    this->world_push_direction.k[2] = v35;
    if ( v33 > 0.0 && v66 != 100 )
    {
      IVP_Impact_Solver::do_push(this, a2: (int)&virtual_speed, impulse_val: 1.0);
      IVP_Impact_Solver::get_relative_speed_vector(this, a2: COERCE_FLOAT(&virtual_speed));
      v37 = (float)((float)((float)(this->surf_normal->k[1] * this->relative_world_speed.k[1])
                          + (float)(this->relative_world_speed.k[0] * this->surf_normal->k[0]))
                  + (float)(this->surf_normal->k[2] * this->relative_world_speed.k[2]))
          + v64;
      if ( COERCE_FLOAT(LODWORD(v37) & _mask__AbsFloat_) <= 0.000099999997 )
        v38 = 0.0;
      else
        v38 = impulse / v37;
      IVP_Impact_Solver::undo_push(this);
      IVP_Impact_Solver::do_push(this: v39, a2: (int)&virtual_speed, impulse_val: v38);
    }
    IVP_Impact_Solver::do_rescue_push(
      this,
      a2: (int)&virtual_speed,
      push_dir_norm: &this->world_push_direction,
      panic_mode: IVP_FALSE);
  }
  else
  {
    v58 = -surf_normal->k[0];
    v59 = -surf_normal->k[1];
    v60 = -surf_normal->k[2];
    IVP_Impact_Solver::do_rescue_push(
      this,
      a2: (int)&virtual_speed,
      push_dir_norm: (IVP_U_Float_Point *)&v58,
      panic_mode: IVP_TRUE);
    if ( pushes_while_system > 10 )
      this->delaying_is_allowed = IVP_FALSE;
  }
  v40 = *(float *)this->core;
  v41 = *(_DWORD *)(LODWORD(v40) + 72) == 0;
  v42 = *(float *)(*(_DWORD *)(LODWORD(v40) + 12) + 36);
  v64 = v40;
  v63 = v42;
  if ( v41 || *(float *)(LODWORD(v40) + 8) != 0.0 )
  {
    v43 = *(_DWORD *)(LODWORD(v40) + 12);
    if ( (float)((float)((float)(this->rot_speed[0].k[0] * this->rot_speed[0].k[0])
                       + (float)(this->rot_speed[0].k[1] * this->rot_speed[0].k[1]))
               + (float)(this->rot_speed[0].k[2] * this->rot_speed[0].k[2])) > (float)((float)(*(float *)(v43 + 172)
                                                                                             * *(float *)(LODWORD(v42) + 16))
                                                                                     * (float)(*(float *)(v43 + 172)
                                                                                             * *(float *)(LODWORD(v42) + 16))) )
    {
      impulse_val = *(float *)(v43 + 32);
      (*(void (__thiscall **)(float, float, float, IVP_U_Float_Point *))(*(_DWORD *)LODWORD(impulse_val) + 4))(
        a1: COERCE_FLOAT(LODWORD(impulse_val)),
        a2: COERCE_FLOAT(LODWORD(v42)),
        a3: COERCE_FLOAT(LODWORD(v40)),
        a4: this->rot_speed);
      v42 = v63;
      v40 = v64;
    }
  }
  if ( (float)((float)((float)(this->trans_speed[0].k[0] * this->trans_speed[0].k[0])
                     + (float)(this->trans_speed[0].k[1] * this->trans_speed[0].k[1]))
             + (float)(this->trans_speed[0].k[2] * this->trans_speed[0].k[2])) > (float)(*(float *)(LODWORD(v42) + 8)
                                                                                       * *(float *)(LODWORD(v42) + 8)) )
  {
    impulse_val = *(float *)(*(_DWORD *)(LODWORD(v40) + 12) + 32);
    (**(void (__thiscall ***)(float, float, float, IVP_U_Float_Point *))LODWORD(impulse_val))(
      a1: COERCE_FLOAT(LODWORD(impulse_val)),
      a2: COERCE_FLOAT(LODWORD(v42)),
      a3: COERCE_FLOAT(LODWORD(v40)),
      a4: this->trans_speed);
  }
  v44 = this->core[1];
  v41 = v44->car_wheel == nullptr;
  environment = (float *)v44->environment;
  v46 = environment[9];
  v64 = v46;
  if ( (v41 || v44->max_surface_deviation != 0.0)
    && (float)((float)((float)(this->rot_speed[1].k[0] * this->rot_speed[1].k[0])
                     + (float)(this->rot_speed[1].k[1] * this->rot_speed[1].k[1]))
             + (float)(this->rot_speed[1].k[2] * this->rot_speed[1].k[2])) > (float)((float)(environment[43]
                                                                                           * *(float *)(LODWORD(v46) + 16))
                                                                                   * (float)(environment[43]
                                                                                           * *(float *)(LODWORD(v46) + 16))) )
  {
    impulse_val = environment[8];
    (*(void (__thiscall **)(float, float, IVP_Core *, IVP_U_Float_Point *))(*(_DWORD *)LODWORD(impulse_val) + 4))(
      a1: COERCE_FLOAT(LODWORD(impulse_val)),
      a2: COERCE_FLOAT(LODWORD(v46)),
      a3: v44,
      a4: &this->rot_speed[1]);
    v46 = v64;
  }
  if ( (float)((float)((float)(this->trans_speed[1].k[0] * this->trans_speed[1].k[0])
                     + (float)(this->trans_speed[1].k[1] * this->trans_speed[1].k[1]))
             + (float)(this->trans_speed[1].k[2] * this->trans_speed[1].k[2])) > (float)(*(float *)(LODWORD(v46) + 8)
                                                                                       * *(float *)(LODWORD(v46) + 8)) )
  {
    impulse_val = *(float *)&v44->environment->anomaly_manager;
    (**(void (__thiscall ***)(float, float, IVP_Core *, IVP_U_Float_Point *))LODWORD(impulse_val))(
      a1: COERCE_FLOAT(LODWORD(impulse_val)),
      a2: COERCE_FLOAT(LODWORD(v46)),
      a3: v44,
      a4: &this->trans_speed[1]);
  }
  IVP_Impact_Solver::delay_decision(this, a2: (int)&virtual_speed, pushed_cores);
  v47 = this->core[0];
  if ( ((*(_BYTE *)&v47->IVP_Core_Fast_Static | *(_BYTE *)&this->core[1]->IVP_Core_Fast_Static) & 0xC0) != 0 )
  {
    ++v47->environment->statistic_manager.impact_unmov;
    v48 = this->core[0];
    *(_WORD *)&v48->IVP_Core_Fast_Static ^= ((unsigned __int8)*(_WORD *)&v48->IVP_Core_Fast_Static
                                           ^ (((*(_WORD *)&v48->IVP_Core_Fast_Static & 2) == 0) << 6))
                                          & 0xC0;
    v49 = v48->speed.k[2] + v48->speed_change.k[2];
    v50 = v48->speed.k[0] + v48->speed_change.k[0];
    v48->speed_change.k[1] = v48->speed_change.k[1] + v48->speed.k[1];
    v48->speed_change.k[0] = v50;
    v48->speed_change.k[2] = v49;
    v51 = v48->rot_speed.k[2] + v48->rot_speed_change.k[2];
    v52 = v48->rot_speed_change.k[0] + v48->rot_speed.k[0];
    v48->rot_speed_change.k[1] = v48->rot_speed_change.k[1] + v48->rot_speed.k[1];
    v48->rot_speed_change.k[0] = v52;
    v48->rot_speed_change.k[2] = v51;
    *(_QWORD *)&v48->speed.k[1] = 0;
    v48->speed.k[0] = 0.0;
    *(_QWORD *)&v48->rot_speed.k[1] = 0;
    v48->rot_speed.k[0] = 0.0;
    *pushed_cores = v48;
    v53 = this->core[1];
    *(_WORD *)&v53->IVP_Core_Fast_Static ^= ((unsigned __int8)*(_WORD *)&v53->IVP_Core_Fast_Static
                                           ^ (((*(_WORD *)&v53->IVP_Core_Fast_Static & 2) == 0) << 6))
                                          & 0xC0;
    v54 = v53->speed_change.k[1] + v53->speed.k[1];
    v55 = v53->speed_change.k[2] + v53->speed.k[2];
    v53->speed_change.k[0] = v53->speed_change.k[0] + v53->speed.k[0];
    v53->speed_change.k[1] = v54;
    v53->speed_change.k[2] = v55;
    v56 = v53->rot_speed_change.k[2] + v53->rot_speed.k[2];
    v57 = v53->rot_speed.k[1] + v53->rot_speed_change.k[1];
    v53->rot_speed_change.k[0] = v53->rot_speed.k[0] + v53->rot_speed_change.k[0];
    v53->rot_speed_change.k[1] = v57;
    v53->rot_speed_change.k[2] = v56;
    *(_QWORD *)&v53->speed.k[1] = 0;
    v53->speed.k[0] = 0.0;
    *(_QWORD *)&v53->rot_speed.k[1] = 0;
    v53->rot_speed.k[0] = 0.0;
    pushed_cores[1] = v53;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089140
// Name: public: IVP_Impact_System::~IVP_Impact_System(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_System::~IVP_Impact_System(IVP_Impact_System *this)
{
  IVP_Impact_System *elems; // eax
  IVP_Impact_System *v3; // eax
  IVP_Impact_System *v4; // eax

  elems = (IVP_Impact_System *)this->i_s_pairs.elems;
  if ( elems != (IVP_Impact_System *)&this->associated_fs_system )
  {
    if ( elems != nullptr )
      free(data: elems);
    this->i_s_pairs.elems = nullptr;
    this->i_s_pairs.memsize = 0;
  }
  this->i_s_pairs.n_elems = 0;
  v3 = (IVP_Impact_System *)this->i_s_known_cores.elems;
  if ( v3 != (IVP_Impact_System *)&this->i_s_pairs )
  {
    if ( v3 != nullptr )
      free(data: this->i_s_known_cores.elems);
    this->i_s_known_cores.elems = nullptr;
    this->i_s_known_cores.memsize = 0;
  }
  this->i_s_known_cores.n_elems = 0;
  v4 = (IVP_Impact_System *)this->i_s_pushed_cores.elems;
  if ( v4 == (IVP_Impact_System *)&this->i_s_known_cores )
  {
    this->i_s_pushed_cores.n_elems = 0;
  }
  else
  {
    if ( v4 != nullptr )
      free(data: this->i_s_pushed_cores.elems);
    this->i_s_pushed_cores.elems = nullptr;
    *(_DWORD *)&this->i_s_pushed_cores.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100891D0
// Name: public: void IVP_Impact_Solver_Long_Term::do_impact_long_term(class IVP_Core __near * __near * const,float,class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Impact_Solver_Long_Term::do_impact_long_term(
        IVP_Impact_Solver_Long_Term *this@<ecx>,
        int a2@<ebp>,
        double a3@<esi:edi>,
        IVP_Core **pushed_cores,
        float rescue_speed_val,
        IVP_Contact_Point *cp)
{
  IVP_Core *v6; // edx
  IVP_Core *physical_core; // eax
  float v8; // xmm1_4
  float v9; // xmm1_4
  IVP_U_Float_Point *p_surf_normal; // ecx
  IVP_Core *v11; // xmm0_4
  float v12; // xmm0_4
  bool v13; // zf
  float v14; // xmm0_4
  long double v15; // [esp+4h] [ebp-16Ch]
  _BYTE v16[12]; // [esp+14h] [ebp-15Ch] BYREF
  IVP_Impact_Solver imp_solver_stack; // [esp+20h] [ebp-150h] BYREF
  float v18; // [esp+160h] [ebp-10h]
  _DWORD v19[3]; // [esp+164h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+170h] [ebp+0h]

  v19[0] = a2;
  v19[1] = retaddr;
  v15 = a3;
  HIDWORD(a3) = this;
  v6 = this->contact_core[1];
  if ( v6 != nullptr )
  {
    physical_core = this->contact_core[0];
    LODWORD(imp_solver_stack.world_direction_second_friction.k[1]) = physical_core;
    if ( physical_core == nullptr )
    {
      physical_core = this->objects[0]->physical_core;
      LODWORD(imp_solver_stack.world_direction_second_friction.k[1]) = physical_core;
    }
    LODWORD(imp_solver_stack.world_direction_second_friction.hesse_val) = this->contact_point_cs;
    imp_solver_stack.core[0] = (IVP_Core *)&this->contact_point_cs[1];
    p_surf_normal = &this->surf_normal;
  }
  else
  {
    physical_core = this->objects[1]->physical_core;
    v6 = this->contact_core[0];
    *((float *)&imp_solver_stack.speed + 1) = -this->surf_normal.k[0];
    v8 = -this->surf_normal.k[1];
    LODWORD(imp_solver_stack.world_direction_second_friction.hesse_val) = this->contact_point_cs[1].k;
    *((float *)&imp_solver_stack.speed + 2) = v8;
    v9 = this->surf_normal.k[2];
    imp_solver_stack.core[0] = (IVP_Core *)this->contact_point_cs;
    LODWORD(imp_solver_stack.world_direction_second_friction.k[1]) = physical_core;
    *((float *)&imp_solver_stack.speed + 3) = -v9;
    p_surf_normal = (IVP_U_Float_Point *)(&imp_solver_stack.speed + 1);
  }
  v11 = *(IVP_Core **)(HIDWORD(a3) + 96);
  LODWORD(imp_solver_stack.percent_energy_conservation) = p_surf_normal;
  LODWORD(imp_solver_stack.world_direction_second_friction.k[2]) = v6;
  LODWORD(imp_solver_stack.cos_friction) = HIDWORD(a3) + 32;
  imp_solver_stack.core[1] = v11;
  imp_solver_stack.integral_pushes_world.k[1] = 0.0;
  if ( physical_core->car_wheel != nullptr || v6->car_wheel != nullptr )
  {
    v14 = (float)(fsqrt(*(float *)&v11) + 1.0) * 0.0;
    v18 = v14;
    __libm_sse2_atan(x: v15);
    *(float *)imp_solver_stack.obj_point = (float)((float)(v14 * v14) * (float)((float)(v14 * v14) * 0.041666668))
                                         + (float)(1.0 - (float)((float)(v14 * v14) * 0.5));
    *(float *)&imp_solver_stack.obj_point[1] = *(float *)imp_solver_stack.obj_point * v18;
  }
  else
  {
    LODWORD(a3) = cp;
    v12 = (float)(fsqrt(*(float *)&v11) + 1.0) * cp->real_friction_factor;
    v18 = v12;
    __libm_sse2_atan(x: v15);
    v13 = *((_BYTE *)&cp->IVP_Contact_Point_Fast_Static + 52) == 0;
    *(float *)imp_solver_stack.obj_point = (float)((float)(v12 * v12) * (float)((float)(v12 * v12) * 0.041666668))
                                         + (float)(1.0 - (float)((float)(v12 * v12) * 0.5));
    *(float *)&imp_solver_stack.obj_point[1] = *(float *)imp_solver_stack.obj_point * v18;
    if ( !v13 )
      IVP_Impact_Solver::get_world_direction_second_friction(
        this: (IVP_Impact_Solver *)v16,
        a2: COERCE_FLOAT(v19),
        a3,
        cp: (IVP_Contact_Point *)LODWORD(a3));
  }
  IVP_Impact_Solver::do_impact(
    this: (IVP_Impact_Solver *)v16,
    a2: COERCE_FLOAT(v19),
    pushed_cores,
    allow_delaying: IVP_TRUE,
    pushes_while_system: *(__int16 *)(HIDWORD(a3) + 82),
    rescue_speed_addon: rescue_speed_val);
}

//------------------------------------------------------------------------------
// Address: 0x100893B0
// Name: private: void IVP_Impact_System::add_pushed_core_with_pairs_except(class IVP_Core __near *,class IVP_Friction_Core_Pair __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_System::add_pushed_core_with_pairs_except(
        IVP_Impact_System *this,
        IVP_Core *new_core,
        IVP_Friction_Core_Pair *start_pair)
{
  IVP_Core *v4; // edx
  IVP_Friction_System *associated_fs_system; // eax
  int v6; // esi
  IVP_Friction_Core_Pair *v7; // edi
  int v8; // eax
  void **v9; // ecx
  int i; // [esp+8h] [ebp-4h]

  if ( this->i_s_pushed_cores.n_elems >= this->i_s_pushed_cores.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->i_s_pushed_cores);
  v4 = new_core;
  this->i_s_pushed_cores.elems[this->i_s_pushed_cores.n_elems++] = new_core;
  new_core->tmp_null.old_sync_info->was_pushed_during_i_s = IVP_TRUE;
  associated_fs_system = this->associated_fs_system;
  v6 = associated_fs_system->fr_pairs_of_objs.n_elems - 1;
  i = v6;
  if ( associated_fs_system->fr_pairs_of_objs.n_elems != 0 )
  {
    do
    {
      v7 = (IVP_Friction_Core_Pair *)this->associated_fs_system->fr_pairs_of_objs.elems[v6];
      if ( (v7->objs[0] == v4 || v7->objs[1] == v4) && v7 != start_pair )
      {
        v8 = this->i_s_pairs.n_elems - 1;
        if ( this->i_s_pairs.n_elems != 0 )
        {
          v9 = &this->i_s_pairs.elems[v8];
          while ( *v9 != v7 )
          {
            --v9;
            if ( --v8 < 0 )
              goto LABEL_11;
          }
        }
        else
        {
LABEL_11:
          if ( IVP_Friction_Core_Pair::check_all_fr_mindists_to_be_valid(this: v7, my_fs: this->associated_fs_system) > 0 )
          {
            if ( this->i_s_pairs.n_elems >= this->i_s_pairs.memsize )
              IVP_U_Vector_Base::increment_mem(this: &this->i_s_pairs);
            v6 = i;
            this->i_s_pairs.elems[this->i_s_pairs.n_elems++] = v7;
          }
          v4 = new_core;
        }
      }
      i = --v6;
    }
    while ( v6 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089470
// Name: private: enum IVP_BOOL IVP_Impact_System::test_loop_all_pairs(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall IVP_Impact_System::test_loop_all_pairs@<eax>(IVP_Impact_System *this@<ecx>, double a2@<esi:edi>)
{
  int v2; // eax
  IVP_Friction_Core_Pair *v3; // ecx
  __int16 v4; // ax
  IVP_Friction_Core_Pair *v5; // edx
  int v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // ebx
  double rot_speed_uncertainty; // st7
  float *v11; // eax
  float v12; // xmm0_4
  float *v13; // eax
  int v14; // eax
  IVP_Contact_Point *v15; // edx
  int j; // ebx
  int m; // esi
  IVP_Core *v18; // ecx
  IVP_Core::<unnamed_type_tmp_null> v19; // eax
  IVP_Friction_Info_For_Core *friction_info; // eax
  int v21; // ecx
  int v22; // edx
  IVP_Core *impacting_cores[2]; // [esp+14h] [ebp-28h] BYREF
  IVP_Friction_Core_Pair *associated_pair; // [esp+1Ch] [ebp-20h]
  int i; // [esp+20h] [ebp-1Ch]
  int k; // [esp+24h] [ebp-18h]
  float smallest_distance; // [esp+28h] [ebp-14h]
  IVP_Friction_Core_Pair *my_pair; // [esp+2Ch] [ebp-10h]
  float v30; // [esp+30h] [ebp-Ch]
  IVP_Contact_Point *worst_impact_dist; // [esp+34h] [ebp-8h]
  IVP_Impact_System *v32; // [esp+38h] [ebp-4h]
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  worst_impact_dist = nullptr;
  associated_pair = nullptr;
  v2 = this->i_s_pairs.n_elems - 1;
  v32 = this;
  smallest_distance = ivp_mindist_settings.minimum_friction_dist;
  i = v2;
  if ( v2 < 0 )
    return 0;
  while ( 1 )
  {
    v3 = (IVP_Friction_Core_Pair *)this->i_s_pairs.elems[v2];
    v4 = (__int16)v3->objs[1]->IVP_Core_Fast_Static;
    my_pair = v3;
    if ( ((v4 & 2 | ((unsigned __int8)v4 >> 5))
        & (*(_WORD *)&v3->objs[0]->IVP_Core_Fast_Static & 2
         | ((unsigned __int8)*(_WORD *)&v3->objs[0]->IVP_Core_Fast_Static >> 5))
        & 6) == 0 )
    {
      v5 = my_pair;
      v6 = my_pair->fr_dists.n_elems - 1;
      for ( k = v6; v6 >= 0; k = v6 )
      {
        LODWORD(a2) = v5->fr_dists.elems[v6];
        if ( *(_WORD *)(*(_DWORD *)(LODWORD(a2) + 64) + 84) != 1 )
        {
          ++v32->l_environment->statistic_manager.impact_coll_checks;
          HIDWORD(a2) = *(_DWORD *)(LODWORD(a2) + 64);
          *(_WORD *)(HIDWORD(a2) + 84) = 1;
          v7 = *(float *)(LODWORD(a2) + 88);
          if ( v7 <= ivp_mindist_settings.max_distance_for_impact_system )
          {
            v9 = *(_DWORD *)(*(_DWORD *)(LODWORD(a2) + 16) + 24);
            v30 = 0.0;
            if ( ivp_mindist_settings.min_coll_dists <= v7 )
              *(_DWORD *)(*(_DWORD *)(LODWORD(a2) + 64) + 88) = 0;
            else
              v30 = (float)(ivp_mindist_settings.min_coll_dists - v7) * *(float *)(v9 + 172);
            rot_speed_uncertainty = IVP_Contact_Point::get_rot_speed_uncertainty(
                                      this: (IVP_Contact_Point *)LODWORD(a2),
                                      a2);
            v11 = *(float **)(HIDWORD(a2) + 112);
            v12 = 0.0;
            *(float *)&impacting_cores[1] = rot_speed_uncertainty + v30 + rot_speed_uncertainty + v30;
            *(float *)(HIDWORD(a2) + 88) = *(float *)&impacting_cores[1];
            if ( v11 != nullptr )
              v12 = (float)((float)((float)(*(float *)(HIDWORD(a2) + 196) * v11[49])
                                  + (float)(*(float *)(HIDWORD(a2) + 192) * v11[48]))
                          + (float)(*(float *)(HIDWORD(a2) + 200) * v11[50]))
                  + (float)((float)((float)(*(float *)(HIDWORD(a2) + 20) * v11[53])
                                  + (float)(*(float *)(HIDWORD(a2) + 16) * v11[52]))
                          + (float)(*(float *)(HIDWORD(a2) + 24) * v11[54]));
            v13 = *(float **)(HIDWORD(a2) + 116);
            if ( v13 != nullptr )
              v12 = v12
                  - (float)((float)((float)((float)(*(float *)(HIDWORD(a2) + 212) * v13[49])
                                          + (float)(*(float *)(HIDWORD(a2) + 208) * v13[48]))
                                  + (float)(*(float *)(HIDWORD(a2) + 216) * v13[50]))
                          + (float)((float)((float)(*(float *)(HIDWORD(a2) + 20) * v13[53])
                                          + (float)(*(float *)(HIDWORD(a2) + 16) * v13[52]))
                                  + (float)(*(float *)(HIDWORD(a2) + 24) * v13[54])));
            v5 = my_pair;
            v6 = k;
            v8 = *(float *)(LODWORD(a2) + 88)
               - (float)((float)((float)(*(float *)&impacting_cores[1] * 0.5) + v12) * *(float *)(v9 + 168));
          }
          else
          {
            v8 = 1.0e20;
          }
          *(float *)(HIDWORD(a2) + 92) = v8;
        }
        v14 = *(_DWORD *)(LODWORD(a2) + 64);
        if ( smallest_distance > *(float *)(v14 + 92) )
        {
          smallest_distance = *(float *)(v14 + 92);
          worst_impact_dist = (IVP_Contact_Point *)LODWORD(a2);
          associated_pair = v5;
        }
        --v6;
      }
    }
    v2 = --i;
    if ( i < 0 )
      break;
    this = v32;
  }
  v15 = worst_impact_dist;
  if ( worst_impact_dist == nullptr )
    return 0;
  for ( j = 29; j >= 28; --j )
  {
    *(float *)&a2 = v15->tmp_contact_info->contact_point_ws.k[j];
    if ( LODWORD(a2) != 0 && *(_DWORD *)(LODWORD(a2) + 428) == 0 )
    {
      HIDWORD(a2) = v32;
      if ( v32->i_s_known_cores.n_elems >= v32->i_s_known_cores.memsize )
      {
        IVP_U_Vector_Base::increment_mem(this: &v32->i_s_known_cores);
        v15 = worst_impact_dist;
      }
      v32->i_s_known_cores.elems[v32->i_s_known_cores.n_elems] = (void *)LODWORD(a2);
      ++*(_WORD *)(HIDWORD(a2) + 18);
      if ( *(_BYTE *)(LODWORD(a2) + 1) < 8u && (*(_BYTE *)LODWORD(a2) & 0x10) == 0 )
      {
        IVP_Core::synchronize_with_rot_z(
          this: (IVP_Core *)LODWORD(a2),
          a2: (int)&savedregs,
          a3: SLODWORD(a2),
          a4: SHIDWORD(a2));
        v15 = worst_impact_dist;
      }
    }
  }
  ++v15->tmp_contact_info->impacts_while_system;
  IVP_Impact_Solver_Long_Term::do_impact_long_term(
    this: v15->tmp_contact_info,
    a2: (int)&savedregs,
    a3: a2,
    pushed_cores: impacting_cores,
    rescue_speed_val: v15->tmp_contact_info->impact.rescue_speed_addon,
    cp: v15);
  for ( m = 1; m >= 0; --m )
  {
    v18 = impacting_cores[m];
    if ( v18 != nullptr && (*(_WORD *)&v18->IVP_Core_Fast_Static & 0x12) == 0 )
    {
      v19.old_sync_info = (IVP_Old_Sync_Rot_Z *)v18->tmp_null;
      if ( v19.old_sync_info == nullptr || v19.old_sync_info->was_pushed_during_i_s != IVP_FALSE )
      {
        friction_info = IVP_Core::get_friction_info(this: v18, my_fr_system: v32->associated_fs_system);
        v21 = friction_info->friction_springs.n_elems - 1;
        if ( friction_info->friction_springs.n_elems != 0 )
        {
          do
          {
            v22 = *((_DWORD *)friction_info->friction_springs.elems[v21--] + 16);
            *(_WORD *)(v22 + 84) = 0;
          }
          while ( v21 >= 0 );
        }
      }
      else
      {
        IVP_Impact_System::add_pushed_core_with_pairs_except(this: v32, new_core: v18, start_pair: associated_pair);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100897D0
// Name: public: class IVP_Contact_Point __near * IVP_Mindist::try_to_generate_managed_friction(class IVP_Friction_System __near * __near *,enum IVP_BOOL __near *,class IVP_Simulation_Unit __near *,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
IVP_Contact_Point *__thiscall IVP_Mindist::try_to_generate_managed_friction(
        IVP_Mindist *this,
        IVP_Friction_System **associated_fs,
        IVP_BOOL *having_new,
        IVP_Simulation_Unit *sim_unit_not_destroy,
        IVP_BOOL call_recalc_svals)
{
  IVP_Real_Object *l_obj; // ebx
  IVP_Core *friction_core; // edi
  bool v8; // zf
  IVP_Core *v9; // eax
  IVP_Friction_Info_For_Core *v10; // eax
  IVP_Environment *environment; // edx
  IVP_Contact_Point *v12; // eax
  IVP_Contact_Point *v13; // edi
  IVP_Environment *v15; // esi
  IVP_Contact_Situation *tmp_contact_info; // eax
  IVP_Friction_Info_For_Core *v17; // eax
  IVP_Friction_System *l_friction_system; // ebx
  IVP_Friction_Info_For_Core *friction_info; // esi
  IVP_Friction_Info_For_Core *v20; // eax
  IVP_Core *v21; // ecx
  IVP_Core *v22; // eax
  IVP_Friction_Info_For_Core *v23; // eax
  IVP_Core *v24; // ecx
  IVP_Friction_System *v25; // eax
  IVP_Friction_Info_For_Core *v26; // eax
  IVP_Core *v27; // ecx
  IVP_Simulation_Unit *sim_unit_of_core; // esi
  IVP_Simulation_Unit *v29; // ebx
  IVP_Friction_Hash *v30; // [esp-4h] [ebp-34h]
  IVP_Event_Friction event_friction; // [esp+Ch] [ebp-24h] BYREF
  IVP_Real_Object *obj1; // [esp+18h] [ebp-18h]
  IVP_BOOL gen_success; // [esp+1Ch] [ebp-14h] BYREF
  IVP_Environment *my_env; // [esp+20h] [ebp-10h]
  IVP_Core *core0; // [esp+24h] [ebp-Ch]
  IVP_Friction_Info_For_Core *fr_info0; // [esp+28h] [ebp-8h]
  IVP_Core *core1; // [esp+2Ch] [ebp-4h]

  l_obj = this->synapse[(*((_DWORD *)&this->IVP_Mindist_Base + 5) >> 8) & 3].l_obj;
  friction_core = l_obj->friction_core;
  v8 = (*(_BYTE *)&friction_core->IVP_Core_Fast_Static & 2) == 0;
  obj1 = this->synapse[((*((_DWORD *)&this->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].l_obj;
  v9 = obj1->friction_core;
  core0 = friction_core;
  core1 = v9;
  if ( !v8 )
  {
    core1 = friction_core;
    core0 = v9;
    friction_core = v9;
  }
  v10 = IVP_Core::moveable_core_has_friction_info(this: friction_core);
  environment = friction_core->environment;
  fr_info0 = v10;
  my_env = environment;
  v12 = IVP_Friction_Manager::generate_contact_point(mindist: this, successful: &gen_success);
  v13 = v12;
  if ( gen_success != IVP_TRUE )
  {
    *associated_fs = fr_info0->l_friction_system;
    *having_new = IVP_FALSE;
    if ( call_recalc_svals != IVP_FALSE && v12 != nullptr )
    {
      IVP_Contact_Point::recalc_friction_s_vals(this: v12, env: my_env);
      IVP_Contact_Point::read_materials_for_contact_situation(this: v13, info: v13->tmp_contact_info);
      return v13;
    }
    return v13;
  }
  if ( call_recalc_svals != IVP_FALSE )
  {
    IVP_Contact_Point::recalc_friction_s_vals(this: v12, env: my_env);
    IVP_Contact_Point::read_materials_for_contact_situation(this: v13, info: v13->tmp_contact_info);
  }
  tmp_contact_info = v13->tmp_contact_info;
  event_friction.environment = l_obj->environment;
  v15 = event_friction.environment;
  event_friction.contact_situation = tmp_contact_info;
  event_friction.friction_handle = v13;
  IVP_Environment::fire_event_friction_created(this: event_friction.environment, coll: &event_friction);
  if ( (*(_DWORD *)&l_obj->flags & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_friction_created(this: v15->cluster_manager, real_object: l_obj, &event_friction);
  if ( (*(_DWORD *)&obj1->flags & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_friction_created(this: v15->cluster_manager, real_object: obj1, &event_friction);
  v17 = fr_info0;
  *having_new = IVP_TRUE;
  if ( v17 != nullptr )
  {
    l_friction_system = v17->l_friction_system;
    friction_info = IVP_Core::get_friction_info(this: core1, my_fr_system: l_friction_system);
    if ( friction_info != nullptr )
    {
add_second_to_first_dist_only:
      IVP_Friction_System::add_dist_to_system(this: l_friction_system, new_dist: v13);
      IVP_Friction_System::dist_added_update_pair_info(this: l_friction_system, new_dist: v13);
      goto LABEL_35;
    }
    if ( (*(_BYTE *)&core1->IVP_Core_Fast_Static & 2) == 0 )
    {
      friction_info = IVP_Core::moveable_core_has_friction_info(this: core1);
      if ( friction_info != nullptr )
      {
        IVP_Friction_System::fusion_friction_systems(
          this: l_friction_system,
          second_sys: friction_info->l_friction_system);
        goto add_second_to_first_dist_only;
      }
    }
    v20 = (IVP_Friction_Info_For_Core *)p_malloc(size: 0xCu);
    friction_info = nullptr;
    if ( v20 != nullptr )
    {
      v20->friction_springs.elems = nullptr;
      *(_DWORD *)&v20->friction_springs.memsize = 0;
      friction_info = v20;
    }
    v21 = core1;
    friction_info->l_friction_system = l_friction_system;
    IVP_Core::add_friction_info(this: v21, my_fr_info: (IVP_Friction_Hash *)friction_info);
    v22 = core1;
LABEL_27:
    IVP_Friction_System::add_core_to_system(this: l_friction_system, new_obj: v22);
    goto add_second_to_first_dist_only;
  }
  v23 = (IVP_Friction_Info_For_Core *)p_malloc(size: 0xCu);
  if ( v23 != nullptr )
  {
    *(_DWORD *)&v23->friction_springs.memsize = 0;
    v23->friction_springs.elems = nullptr;
    fr_info0 = v23;
  }
  else
  {
    fr_info0 = nullptr;
  }
  if ( (*(_BYTE *)&core1->IVP_Core_Fast_Static & 2) == 0 )
  {
    friction_info = IVP_Core::moveable_core_has_friction_info(this: core1);
    if ( friction_info != nullptr )
    {
      l_friction_system = friction_info->l_friction_system;
      v24 = core0;
      v30 = (IVP_Friction_Hash *)fr_info0;
      fr_info0->l_friction_system = l_friction_system;
      IVP_Core::add_friction_info(this: v24, my_fr_info: v30);
      v22 = core0;
      goto LABEL_27;
    }
  }
  v25 = (IVP_Friction_System *)p_malloc(size: 0x4Cu);
  if ( v25 != nullptr )
    l_friction_system = IVP_Friction_System::IVP_Friction_System(this: v25, env: my_env);
  else
    l_friction_system = nullptr;
  v26 = (IVP_Friction_Info_For_Core *)p_malloc(size: 0xCu);
  friction_info = nullptr;
  if ( v26 != nullptr )
  {
    v26->friction_springs.elems = nullptr;
    *(_DWORD *)&v26->friction_springs.memsize = 0;
    friction_info = v26;
  }
  v27 = core1;
  fr_info0->l_friction_system = l_friction_system;
  friction_info->l_friction_system = l_friction_system;
  IVP_Core::add_friction_info(this: v27, my_fr_info: (IVP_Friction_Hash *)friction_info);
  IVP_Core::add_friction_info(this: core0, my_fr_info: (IVP_Friction_Hash *)fr_info0);
  IVP_Friction_System::add_dist_to_system(this: l_friction_system, new_dist: v13);
  IVP_Friction_System::dist_added_update_pair_info(this: l_friction_system, new_dist: v13);
  IVP_Friction_System::add_core_to_system(this: l_friction_system, new_obj: core0);
  IVP_Friction_System::add_core_to_system(this: l_friction_system, new_obj: core1);
LABEL_35:
  IVP_Compact_Recursive::add_compact_ledge(this: (IVP_Friction_Core_Pair *)fr_info0, dist: v13);
  IVP_Compact_Recursive::add_compact_ledge(this: (IVP_Friction_Core_Pair *)friction_info, dist: v13);
  *associated_fs = l_friction_system;
  IVP_Contact_Point::calc_virtual_mass_of_mindist(this: v13);
  sim_unit_of_core = core1->sim_unit_of_core;
  v29 = core0->sim_unit_of_core;
  if ( ((*(_BYTE *)&core0->IVP_Core_Fast_Static | *(_BYTE *)&core1->IVP_Core_Fast_Static) & 2) == 0
    && v29 != sim_unit_of_core )
  {
    if ( sim_unit_of_core == sim_unit_not_destroy )
    {
      IVP_Simulation_Unit::fusion_simulation_unities(this: sim_unit_of_core, second_unit: core0->sim_unit_of_core);
      if ( v29 != nullptr )
      {
        IVP_Simulation_Unit::~IVP_Simulation_Unit(this: v29);
        free(data: v29);
        return v13;
      }
    }
    else
    {
      IVP_Simulation_Unit::fusion_simulation_unities(this: v29, second_unit: core1->sim_unit_of_core);
      if ( sim_unit_of_core != nullptr )
      {
        IVP_Simulation_Unit::~IVP_Simulation_Unit(this: sim_unit_of_core);
        free(data: sim_unit_of_core);
      }
    }
  }
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x10089AE0
// Name: private: void IVP_Impact_System::recalc_all_affected_cores(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_System::recalc_all_affected_cores(IVP_Impact_System *this)
{
  int v2; // ebx
  _DWORD *v3; // esi
  int v4; // eax
  IVP_Environment *l_environment; // eax
  int seconds_low; // ecx
  bool v7; // sf
  int v8; // ebx
  float v9; // xmm0_4
  IVP_Core *v10; // esi
  IVP_Friction_Info_For_Core *friction_info; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // esi
  IVP_Core *v15; // ecx
  IVP_Vector_of_Hull_Managers_256 active_hull_managers; // [esp+Ch] [ebp-420h] BYREF
  IVP_Event_Sim event_sim; // [esp+414h] [ebp-18h] BYREF
  double v18; // [esp+424h] [ebp-8h]

  v2 = this->i_s_known_cores.n_elems - 1;
  if ( this->i_s_known_cores.n_elems != 0 )
  {
    do
    {
      v3 = this->i_s_known_cores.elems[v2];
      v4 = v3[107];
      if ( v4 != 0 && *(_DWORD *)(v4 + 32) == 0 )
        IVP_Core::undo_synchronize_rot_z(this: (IVP_Core *)this->i_s_known_cores.elems[v2]);
      --v2;
      v3[107] = 0;
    }
    while ( v2 >= 0 );
  }
  l_environment = this->l_environment;
  seconds_low = LODWORD(this->l_environment->time_of_next_psi.seconds);
  v8 = this->i_s_pushed_cores.n_elems - 1;
  v7 = this->i_s_pushed_cores.n_elems == 0;
  HIDWORD(v18) = HIDWORD(this->l_environment->time_of_next_psi.seconds);
  LODWORD(v18) = seconds_low;
  v9 = v18 - l_environment->current_time.seconds;
  *((float *)&v18 + 1) = v9;
  active_hull_managers.elems = active_hull_managers.elem_buffer;
  *(_DWORD *)&active_hull_managers.memsize = 256;
  if ( !v7 )
  {
    do
    {
      v10 = (IVP_Core *)this->i_s_pushed_cores.elems[v8];
      if ( (*(_BYTE *)&v10->IVP_Core_Fast_Static & 2) == 0 )
      {
        event_sim.environment = this->l_environment;
        event_sim.delta_time = v9;
        if ( v9 <= 1.0e-10 )
          event_sim.i_delta_time = 1.0e10;
        else
          event_sim.i_delta_time = 1.0 / v9;
        IVP_Calc_Next_PSI_Solver::calc_next_PSI_matrix(
          core: v10,
          &event_sim,
          active_hull_managers_out: &active_hull_managers);
        v10->tmp_null.old_sync_info = nullptr;
        friction_info = IVP_Core::get_friction_info(this: v10, my_fr_system: this->associated_fs_system);
        v12 = friction_info->friction_springs.n_elems - 1;
        if ( friction_info->friction_springs.n_elems != 0 )
        {
          do
          {
            v13 = *((_DWORD *)friction_info->friction_springs.elems[v12--] + 16);
            *(_WORD *)(v13 + 84) = 0;
          }
          while ( v12 >= 0 );
        }
        v9 = *((float *)&v18 + 1);
      }
      --v8;
    }
    while ( v8 >= 0 );
  }
  IVP_Calc_Next_PSI_Solver::commit_all_hull_managers(env: this->l_environment, &active_hull_managers);
  if ( active_hull_managers.elems != active_hull_managers.elem_buffer && active_hull_managers.elems != nullptr )
    free(data: active_hull_managers.elems);
  v14 = this->i_s_pushed_cores.n_elems - 1;
  if ( this->i_s_pushed_cores.n_elems != 0 )
  {
    do
    {
      v15 = (IVP_Core *)this->i_s_pushed_cores.elems[v14];
      if ( (*(_BYTE *)&v15->IVP_Core_Fast_Static & 2) == 0 )
        IVP_Core::update_exact_mindist_events_of_core(this: v15);
      --v14;
    }
    while ( v14 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089C60
// Name: public: void IVP_Impact_System::init_and_solve_impact_system(class IVP_Mindist __near *,class IVP_Friction_System __near *,class IVP_Friction_Core_Pair __near *,class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Impact_System::init_and_solve_impact_system(
        IVP_Impact_System *this,
        IVP_Mindist *mindist,
        IVP_Core *fs_system,
        IVP_Friction_Core_Pair *start_pair,
        IVP_Contact_Point *start_fr_dist)
{
  IVP_Core *physical_core; // eax
  double v6; // rdi
  IVP_Core *v7; // eax
  IVP_Core *v8; // eax
  IVP_Core *core0; // [esp+1Ch] [ebp+Ch]
  IVP_Core *core0a; // [esp+1Ch] [ebp+Ch]

  HIDWORD(v6) = this;
  physical_core = start_fr_dist->synapse[0].l_obj->physical_core;
  LODWORD(v6) = start_fr_dist->synapse[1].l_obj->physical_core;
  this->sum_of_pushes = 0;
  this->associated_fs_system = (IVP_Friction_System *)fs_system;
  this->l_environment = start_pair->objs[0]->environment;
  if ( physical_core != nullptr && (*(_WORD *)&physical_core->IVP_Core_Fast_Static & 0x12) == 0 )
    IVP_Impact_System::add_pushed_core_with_pairs_except(this, new_core: physical_core, start_pair);
  v7 = start_pair->objs[0];
  core0 = v7;
  if ( (*(_WORD *)&v7->IVP_Core_Fast_Static & 0x12) == 0 )
  {
    if ( *(_WORD *)(HIDWORD(v6) + 18) >= *(_WORD *)(HIDWORD(v6) + 16) )
    {
      IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)(HIDWORD(v6) + 16));
      v7 = core0;
    }
    *(_DWORD *)(*(_DWORD *)(HIDWORD(v6) + 20) + 4 * (unsigned __int16)(*(_WORD *)(HIDWORD(v6) + 18))++) = v7;
  }
  if ( LODWORD(v6) != 0 && (*(_WORD *)LODWORD(v6) & 0x12) == 0 )
    IVP_Impact_System::add_pushed_core_with_pairs_except(
      this: (IVP_Impact_System *)HIDWORD(v6),
      new_core: (IVP_Core *)LODWORD(v6),
      start_pair);
  v8 = start_pair->objs[1];
  core0a = v8;
  if ( (*(_WORD *)&v8->IVP_Core_Fast_Static & 0x12) == 0 )
  {
    if ( *(_WORD *)(HIDWORD(v6) + 18) >= *(_WORD *)(HIDWORD(v6) + 16) )
    {
      IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)(HIDWORD(v6) + 16));
      v8 = core0a;
    }
    *(_DWORD *)(*(_DWORD *)(HIDWORD(v6) + 20) + 4 * (unsigned __int16)(*(_WORD *)(HIDWORD(v6) + 18))++) = v8;
  }
  if ( *(_WORD *)(HIDWORD(v6) + 26) >= *(_WORD *)(HIDWORD(v6) + 24) )
    IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)(HIDWORD(v6) + 24));
  *(_DWORD *)(*(_DWORD *)(HIDWORD(v6) + 28) + 4 * (unsigned __int16)(*(_WORD *)(HIDWORD(v6) + 26))++) = start_pair;
  IVP_Impact_System::impact_system_check_start_pair(
    this: (IVP_Impact_System *)HIDWORD(v6),
    start_pair,
    mdfr: start_fr_dist);
  LODWORD(v6) = 0;
  if ( IVP_Impact_System::test_loop_all_pairs(this: (IVP_Impact_System *)HIDWORD(v6), a2: v6) == 1 )
  {
    while ( 1 )
    {
      ++*(_DWORD *)(HIDWORD(v6) + 4);
      ++LODWORD(v6);
      if ( *(int *)(HIDWORD(v6) + 4) > 5000 )
        break;
      if ( IVP_Impact_System::test_loop_all_pairs(this: (IVP_Impact_System *)HIDWORD(v6), a2: v6) != 1 )
        goto LABEL_23;
    }
    if ( mindist != nullptr )
      ((void (__thiscall *)(IVP_Mindist *, int))mindist->dtr_IVP_Collision)(a1: mindist, a2: 1);
  }
LABEL_23:
  *(_DWORD *)(*(_DWORD *)HIDWORD(v6) + 88) += LODWORD(v6) + 1;
  IVP_Impact_System::recalc_all_affected_cores(this: (IVP_Impact_System *)HIDWORD(v6));
}

//------------------------------------------------------------------------------
// Address: 0x10089DB0
// Name: public: static void IVP_Impact_Solver_Long_Term::do_impact_of_two_objects(class IVP_Mindist __near *,class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall IVP_Impact_Solver_Long_Term::do_impact_of_two_objects(
        int a1@<ebp>,
        IVP_Mindist *mindist,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1)
{
  bool v4; // cc
  IVP_Core *physical_core; // ecx
  IVP_Core *v6; // esi
  IVP_Simulation_Unit *sim_unit_of_core; // eax
  IVP_Contact_Point *managed_friction; // eax
  double v9; // rdi
  IVP_Environment *environment; // eax
  unsigned int seconds_low; // ecx
  unsigned int seconds_high; // eax
  int v13; // edx
  IVP_Environment *v14; // ecx
  IVP_Contact_Point *v15; // ecx
  float v16; // xmm1_4
  double rot_speed_uncertainty; // st7
  bool v18; // zf
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  IVP_Environment *v22; // esi
  float rescue_speed_val; // [esp+0h] [ebp-84h]
  IVP_Contact_Point *v24; // [esp+4h] [ebp-80h]
  _DWORD v25[3]; // [esp+18h] [ebp-6Ch] BYREF
  IVP_Impact_System imp_sys; // [esp+24h] [ebp-60h] BYREF
  __int128 event_collision; // [esp+48h] [ebp-3Ch] OVERLAPPED BYREF
  IVP_Time last_time; // [esp+5Ch] [ebp-28h] BYREF
  IVP_Core *v29; // [esp+64h] [ebp-20h]
  double affected_friction_system; // [esp+68h] [ebp-1Ch] OVERLAPPED
  IVP_Time now_time; // [esp+74h] [ebp-10h] BYREF
  void *v32; // [esp+7Ch] [ebp-8h]
  void *retaddr; // [esp+84h] [ebp+0h]

  HIDWORD(now_time.seconds) = a1;
  v32 = retaddr;
  v4 = *(_BYTE *)&obj0->flags < 8;
  physical_core = obj1->physical_core;
  v6 = obj0->physical_core;
  v29 = physical_core;
  if ( v4 )
    sim_unit_of_core = physical_core->sim_unit_of_core;
  else
    sim_unit_of_core = v6->sim_unit_of_core;
  managed_friction = IVP_Mindist::try_to_generate_managed_friction(
                       this: mindist,
                       associated_fs: (IVP_Friction_System **)&last_time,
                       having_new: (IVP_BOOL *)&last_time.seconds + 1,
                       sim_unit_not_destroy: sim_unit_of_core,
                       call_recalc_svals: IVP_TRUE);
  LODWORD(v9) = managed_friction->tmp_contact_info;
  HIDWORD(last_time.seconds) = managed_friction;
  HIDWORD(v9) = IVP_Friction_System::find_pair_of_cores(
                  this: (IVP_Friction_System *)LODWORD(last_time.seconds),
                  core0: v6,
                  core1: v29);
  environment = mindist->synapse[0].l_obj->environment;
  seconds_low = LODWORD(environment->current_time.seconds);
  seconds_high = HIDWORD(environment->current_time.seconds);
  DWORD2(event_collision) = *(_DWORD *)(HIDWORD(v9) + 40);
  v13 = *(_DWORD *)(HIDWORD(v9) + 44);
  *(_DWORD *)(HIDWORD(v9) + 44) = seconds_high;
  *(_DWORD *)(HIDWORD(v9) + 40) = seconds_low;
  affected_friction_system = COERCE_DOUBLE(__PAIR64__(seconds_high, seconds_low));
  v14 = mindist->synapse[0].l_obj->environment;
  HIDWORD(event_collision) = v13;
  LODWORD(now_time.seconds) = v14;
  *(float *)&imp_sys.i_s_pairs.memsize = affected_friction_system - *((double *)&event_collision + 1);
  imp_sys.i_s_pairs.elems = (void **)&v14->standard_gravity_controller;
  imp_sys.associated_fs_system = (IVP_Friction_System *)LODWORD(v9);
  IVP_Environment::fire_event_pre_collision(this: v14, coll: (IVP_Event_Collision *)&imp_sys.i_s_pairs);
  if ( (*(_DWORD *)&obj0->flags & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_pre_collision(
      this: *(IVP_Cluster_Manager **)(LODWORD(now_time.seconds) + 12),
      real_object: obj0,
      event_obj: (IVP_Event_Collision *)&imp_sys.i_s_pairs);
  if ( (*(_DWORD *)&obj1->flags & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_pre_collision(
      this: *(IVP_Cluster_Manager **)(LODWORD(now_time.seconds) + 12),
      real_object: obj1,
      event_obj: (IVP_Event_Collision *)&imp_sys.i_s_pairs);
  v15 = (IVP_Contact_Point *)HIDWORD(last_time.seconds);
  v16 = *(float *)(HIDWORD(last_time.seconds) + 88);
  HIDWORD(affected_friction_system) = 0;
  if ( ivp_mindist_settings.min_coll_dists <= v16 )
    *(_DWORD *)(*(_DWORD *)(HIDWORD(last_time.seconds) + 64) + 88) = 0;
  else
    *((float *)&affected_friction_system + 1) = (float)(ivp_mindist_settings.min_coll_dists - v16)
                                              * obj0->environment->inv_delta_PSI_time;
  v24 = v15;
  rot_speed_uncertainty = IVP_Contact_Point::get_rot_speed_uncertainty(this: v15, a2: v9);
  rescue_speed_val = rot_speed_uncertainty
                   + *((float *)&affected_friction_system + 1)
                   + rot_speed_uncertainty
                   + *((float *)&affected_friction_system + 1);
  IVP_Impact_Solver_Long_Term::do_impact_long_term(
    this: (IVP_Impact_Solver_Long_Term *)LODWORD(v9),
    a2: (int)&now_time.seconds + 4,
    a3: v9,
    pushed_cores: (IVP_Core **)&event_collision + 2,
    rescue_speed_val,
    cp: v24);
  v18 = (*(_BYTE *)&v29->IVP_Core_Fast_Static & 2) == 0;
  v19 = *(float *)(LODWORD(v9) + 32);
  v20 = *(float *)(LODWORD(v9) + 36);
  v21 = *(float *)(LODWORD(v9) + 40);
  *(_QWORD *)&event_collision = __PAIR64__(LODWORD(v20), LODWORD(v19));
  *((float *)&event_collision + 2) = v21;
  if ( !v18 )
  {
    *(float *)&event_collision = v19 * -1.0;
    *((float *)&event_collision + 1) = v20 * -1.0;
    *((float *)&event_collision + 2) = v21 * -1.0;
  }
  v25[2] = 0;
  memset(&imp_sys, 0, 20);
  IVP_Impact_System::init_and_solve_impact_system(
    this: (IVP_Impact_System *)v25,
    mindist,
    fs_system: (IVP_Core *)LODWORD(last_time.seconds),
    start_pair: (IVP_Friction_Core_Pair *)HIDWORD(v9),
    start_fr_dist: (IVP_Contact_Point *)HIDWORD(last_time.seconds));
  IVP_Impact_System::~IVP_Impact_System(this: (IVP_Impact_System *)v25);
  v22 = (IVP_Environment *)LODWORD(now_time.seconds);
  imp_sys.associated_fs_system = (IVP_Friction_System *)LODWORD(v9);
  *(_QWORD *)(LODWORD(v9) + 32) = event_collision;
  *(_DWORD *)(LODWORD(v9) + 40) = DWORD2(event_collision);
  IVP_Environment::fire_event_post_collision(this: v22, coll: (IVP_Event_Collision *)&imp_sys.i_s_pairs);
  if ( (*(_DWORD *)&obj0->flags & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_post_collision(
      this: v22->cluster_manager,
      real_object: obj0,
      event_obj: (IVP_Event_Collision *)&imp_sys.i_s_pairs);
  if ( (*(_DWORD *)&obj1->flags & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_post_collision(
      this: v22->cluster_manager,
      real_object: obj1,
      event_obj: (IVP_Event_Collision *)&imp_sys.i_s_pairs);
}

//------------------------------------------------------------------------------
// Address: 0x10089FF0
// Name: public: virtual void IVP_Mindist::do_impact(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::do_impact(IVP_Mindist *this)
{
  IVP_Environment *environment; // ebx
  IVP_Real_Object **p_l_obj; // edi
  int i; // esi
  IVP_Real_Object *v4; // ecx
  int j; // esi
  IVP_Core *physical_core; // ecx
  IVP_Real_Object *v7; // edx
  IVP_Real_Object *v8; // eax
  IVP_Mindist *v9; // ecx
  IVP_U_Memory *sim_unit_mem; // ecx
  IVP_Real_Object *objects[2]; // [esp+Ch] [ebp-Ch]
  IVP_Mindist *mindist; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  environment = this->synapse[0].l_obj->environment;
  p_l_obj = &this->synapse[0].l_obj;
  mindist = this;
  for ( i = 0; i < 2; ++i )
  {
    v4 = *p_l_obj;
    objects[i] = *p_l_obj;
    IVP_Real_Object::revive_object_for_simulation(this: v4);
    p_l_obj += 7;
  }
  ++environment->sim_unit_mem->transaction_in_use;
  for ( j = 0; j < 2; ++j )
  {
    physical_core = objects[j]->physical_core;
    if ( *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) < 8u
      && (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 0x10) == 0 )
    {
      IVP_Core::synchronize_with_rot_z(this: physical_core, a2: (int)&savedregs, a3: 1, a4: j);
    }
  }
  v7 = objects[1];
  v8 = objects[0];
  v9 = mindist;
  ++environment->mindist_event_timestamp_reference;
  IVP_Impact_Solver_Long_Term::do_impact_of_two_objects(a1: (int)&savedregs, mindist: v9, obj0: v8, obj1: v7);
  sim_unit_mem = environment->sim_unit_mem;
  if ( sim_unit_mem->transaction_in_use-- == 1 )
    IVP_U_Memory::free_mem_transaction(this: sim_unit_mem);
}
