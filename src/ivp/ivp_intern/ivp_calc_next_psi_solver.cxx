// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_calc_next_psi_solver.cxx
// Functions: 7
// ============================================================

#include "ivp\ivp_intern\ivp_calc_next_psi_solver.h"

//------------------------------------------------------------------------------
// Address: 0x100928A0
// Name: public: void IVP_Hull_Manager::check_hull_synapses(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Hull_Manager::check_hull_synapses(IVP_Hull_Manager *this, IVP_Environment *pEnv)
{
  int v3; // eax
  float v4; // xmm0_4
  int v5; // edi
  int i; // ebx

  v3 = IVP_Hull_Manager::get_synapse_check_count(this, pEnvironment: pEnv);
  v4 = this->sorted_synapses.min_value - this->hull_value_next_psi;
  v5 = v3;
  for ( i = v3; v4 < 0.0; v4 = this->sorted_synapses.min_value - this->hull_value_next_psi )
  {
    (*(void (__stdcall **)(IVP_Hull_Manager *, float))(*(_DWORD *)this->sorted_synapses.elems[this->sorted_synapses.first_element].element
                                                     + 4))(
      a1: this,
      a2: COERCE_FLOAT(LODWORD(v4)));
    if ( --v5 < 0 )
    {
      v5 += IVP_Hull_Manager::too_many_synapses_checked_error_get_additional(this, pEnvironment: pEnv, checked: i);
      if ( v5 < 0 )
        return;
      i += v5 + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092920
// Name: private: static void IVP_Calc_Next_PSI_Solver::calc_rotation_matrix(class IVP_Core __near *,float,class IVP_U_Quat restrict __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall IVP_Calc_Next_PSI_Solver::calc_rotation_matrix(
        float a1@<ebp>,
        long double a2@<esi:edi>,
        IVP_Core *core,
        float delta_sim_time,
        IVP_U_Quat *q_core_f_core)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float factor; // xmm1_4
  float v14; // xmm0_4
  int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float w; // xmm1_4
  float y; // xmm2_4
  float x; // xmm0_4
  float z; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  IVP_Constraint_Car_Object *car_wheel; // ecx
  double v28; // xmm0_8
  float v29; // xmm1_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm6_4
  long double v35; // [esp+4h] [ebp-5Ch]
  float v36; // [esp+14h] [ebp-4Ch] BYREF
  float v37; // [esp+18h] [ebp-48h]
  float v38; // [esp+1Ch] [ebp-44h]
  IVP_U_Quat gyro_rotation; // [esp+20h] [ebp-40h] BYREF
  _BYTE outputRotSpeed_4[28]; // [esp+34h] [ebp-2Ch] OVERLAPPED BYREF
  int steps; // [esp+50h] [ebp-10h]
  float dt; // [esp+54h] [ebp-Ch]
  int i; // [esp+58h] [ebp-8h]
  int retaddr; // [esp+60h] [ebp+0h]

  dt = a1;
  i = retaddr;
  v35 = a2;
  HIDWORD(a2) = core;
  if ( (*(_BYTE *)&core->IVP_Core_Fast_Static & 8) != 0 || core->environment->state == IVP_ES_AT )
  {
    car_wheel = core->car_wheel;
    if ( car_wheel != nullptr && core->max_surface_deviation == 0.0 )
    {
      LODWORD(a2) = car_wheel->solver_car->x_idx;
      *(IVP_U_Float_Point *)outputRotSpeed_4 = core->rot_speed;
      *(_DWORD *)&outputRotSpeed_4[4 * LODWORD(a2)] = 0;
      *(_DWORD *)&outputRotSpeed_4[16] = &outputRotSpeed_4[4 * LODWORD(a2)];
      IVP_U_Quat::set_fast_multiple_with_clip(
        this: (IVP_U_Quat *)&v36,
        a2,
        angles: (const IVP_U_Float_Point *)outputRotSpeed_4,
        factor: delta_sim_time);
      memset(outputRotSpeed_4, 0, 12);
      v28 = (float)((float)(core->rot_speed.k[LODWORD(a2)] * 0.5) * delta_sim_time);
      __libm_sse2_sin(x: v35);
      *(float *)&v28 = v28;
      **(_DWORD **)&outputRotSpeed_4[16] = LODWORD(v28);
      v29 = 1.0 - (float)(*(float *)&v28 * *(float *)&v28);
      *(float *)&v28 = gyro_rotation.x;
      v30 = fsqrt(v29);
      v31 = v36;
      v32 = v37;
      v33 = v38;
      q_core_f_core->x = (float)((float)((float)(v36 * v30) + (float)(gyro_rotation.x * *(float *)outputRotSpeed_4))
                               + (float)(v37 * *(float *)&outputRotSpeed_4[8]))
                       - (float)(v38 * *(float *)&outputRotSpeed_4[4]);
      q_core_f_core->y = (float)((float)((float)(v32 * v30) + (float)(*(float *)&v28 * *(float *)&outputRotSpeed_4[4]))
                               + (float)(v33 * *(float *)outputRotSpeed_4))
                       - (float)(v31 * *(float *)&outputRotSpeed_4[8]);
      v34 = (float)((float)((float)(v33 * v30) + (float)(*(float *)&v28 * *(float *)&outputRotSpeed_4[8]))
                  + (float)(v31 * *(float *)&outputRotSpeed_4[4]))
          - (float)(v32 * *(float *)outputRotSpeed_4);
      *(float *)&v28 = (float)((float)((float)(*(float *)&v28 * v30) - (float)(v31 * *(float *)outputRotSpeed_4))
                             - (float)(v32 * *(float *)&outputRotSpeed_4[4]))
                     - (float)(v33 * *(float *)&outputRotSpeed_4[8]);
      q_core_f_core->z = v34;
      q_core_f_core->w = *(float *)&v28;
    }
    else
    {
      HIDWORD(a2) = &core->rot_speed;
      IVP_U_Quat::set_fast_multiple_with_clip(this: q_core_f_core, a2, angles: &core->rot_speed, factor: delta_sim_time);
    }
  }
  else
  {
    v5 = core->rot_inertia.k[1];
    v6 = core->rot_speed.k[1];
    v7 = core->rot_speed.k[2];
    gyro_rotation.y = core->rot_speed.k[0];
    gyro_rotation.z = core->rot_speed.k[1];
    gyro_rotation.w = core->rot_speed.k[2];
    v8 = core->rot_inertia.k[2];
    v36 = (float)(v5 - v8) * core->inv_rot_inertia.k[0];
    v9 = core->rot_inertia.k[0];
    v10 = (float)(v8 - v9) * core->inv_rot_inertia.k[1];
    v11 = (float)(v9 - core->rot_inertia.k[1]) * core->inv_rot_inertia.k[2];
    v37 = v10;
    v12 = core->rot_speed.k[0];
    v38 = v11;
    factor = delta_sim_time;
    v14 = (float)((float)((float)((float)(v12 * v12) + (float)(v6 * v6)) + (float)(v7 * v7)) * factor) * factor;
    *(float *)&outputRotSpeed_4[20] = delta_sim_time;
    *(_DWORD *)&outputRotSpeed_4[16] = 1;
    if ( v14 > 0.02777778 )
    {
      v15 = (int)fsqrt(v14 * 143.99998) + 1;
      factor = delta_sim_time / (float)v15;
      *(_DWORD *)&outputRotSpeed_4[16] = v15;
      *(float *)&outputRotSpeed_4[20] = factor;
    }
    IVP_U_Quat::set_very_fast_multiple(this: q_core_f_core, angles: (const IVP_U_Float_Point *)&gyro_rotation.y, factor);
    *(_DWORD *)&outputRotSpeed_4[24] = 1;
    while ( 1 )
    {
      v16 = (float)((float)((float)(gyro_rotation.w * gyro_rotation.z) * v36) * *(float *)&outputRotSpeed_4[20])
          + gyro_rotation.y;
      v17 = (float)((float)((float)(gyro_rotation.w * gyro_rotation.y) * v37) * *(float *)&outputRotSpeed_4[20])
          + gyro_rotation.z;
      v18 = (float)((float)((float)(gyro_rotation.z * gyro_rotation.y) * v38) * *(float *)&outputRotSpeed_4[20])
          + gyro_rotation.w;
      gyro_rotation.y = v16;
      gyro_rotation.z = v17;
      gyro_rotation.w = v18;
      if ( *(int *)&outputRotSpeed_4[24] >= *(int *)&outputRotSpeed_4[16] )
        break;
      IVP_U_Quat::set_very_fast_multiple(
        this: (IVP_U_Quat *)outputRotSpeed_4,
        angles: (const IVP_U_Float_Point *)&gyro_rotation.y,
        factor: *(float *)&outputRotSpeed_4[20]);
      w = q_core_f_core->w;
      y = q_core_f_core->y;
      x = q_core_f_core->x;
      z = q_core_f_core->z;
      v23 = (float)((float)(y * *(float *)&outputRotSpeed_4[12]) + (float)(w * *(float *)&outputRotSpeed_4[4]))
          + (float)(q_core_f_core->x * *(float *)&outputRotSpeed_4[8]);
      ++*(_DWORD *)&outputRotSpeed_4[24];
      v24 = v23 - (float)(z * *(float *)outputRotSpeed_4);
      v25 = (float)((float)((float)(z * *(float *)&outputRotSpeed_4[12]) + (float)(w * *(float *)&outputRotSpeed_4[8]))
                  + (float)(y * *(float *)outputRotSpeed_4))
          - (float)(x * *(float *)&outputRotSpeed_4[4]);
      *(float *)&steps = (float)((float)(w * *(float *)&outputRotSpeed_4[12]) - (float)(x * *(float *)outputRotSpeed_4))
                       - (float)(y * *(float *)&outputRotSpeed_4[4]);
      v26 = *(float *)&steps - (float)(z * *(float *)&outputRotSpeed_4[8]);
      q_core_f_core->x = (float)((float)((float)(x * *(float *)&outputRotSpeed_4[12])
                                       + (float)(w * *(float *)outputRotSpeed_4))
                               + (float)(z * *(float *)&outputRotSpeed_4[4]))
                       - (float)(y * *(float *)&outputRotSpeed_4[8]);
      q_core_f_core->y = v24;
      q_core_f_core->z = v25;
      q_core_f_core->w = v26;
    }
    core->rot_speed.k[0] = v16;
    core->rot_speed.k[1] = v17;
    core->rot_speed.k[2] = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092D80
// Name: private: static float IVP_Calc_Next_PSI_Solver::calc_psi_rotation_axis(class IVP_Core __near *,class IVP_U_Quat const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IVP_Calc_Next_PSI_Solver::calc_psi_rotation_axis(IVP_Core *core, const IVP_U_Quat *q_core_f_core)
{
  float x; // xmm5_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float y; // xmm6_4
  float z; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float maxSurfaceRotSpeed; // [esp+8h] [ebp+8h]

  x = q_core_f_core->x;
  v4 = 0.0;
  v5 = (float)((float)(x * x) + (float)(q_core_f_core->y * q_core_f_core->y))
     + (float)(q_core_f_core->z * q_core_f_core->z);
  if ( v5 <= 1.0e-10 )
  {
    v11 = 1.0;
    core->rotation_axis_world_space.k[1] = 0.0;
    core->rotation_axis_world_space.k[2] = 0.0;
  }
  else
  {
    y = q_core_f_core->y;
    z = q_core_f_core->z;
    v8 = 1.0 / fsqrt(v5);
    v9 = v8 * v5;
    v4 = (float)((float)((float)((float)((float)((float)(v9 * v9) * v9) * (float)(v9 * v9)) * 0.40414)
                       + (float)((float)((float)((float)(v9 * v9) * v9) * 0.16666667) + v9))
               * 2.0)
       * core->i_delta_time;
    v10 = (float)((float)((float)(core->m_world_f_core_last_psi.rows[2].k[0] * x)
                        + (float)(core->m_world_f_core_last_psi.rows[2].k[1] * y))
                + (float)(core->m_world_f_core_last_psi.rows[2].k[2] * z))
        * v8;
    v11 = (float)((float)((float)(core->m_world_f_core_last_psi.rows[0].k[1] * y)
                        + (float)(core->m_world_f_core_last_psi.rows[0].k[0] * x))
                + (float)(core->m_world_f_core_last_psi.rows[0].k[2] * z))
        * v8;
    core->rotation_axis_world_space.k[1] = (float)((float)((float)(core->m_world_f_core_last_psi.rows[1].k[0] * x)
                                                         + (float)(core->m_world_f_core_last_psi.rows[1].k[1] * y))
                                                 + (float)(core->m_world_f_core_last_psi.rows[1].k[2] * z))
                                         * v8;
    core->rotation_axis_world_space.k[2] = v10;
  }
  core->rotation_axis_world_space.k[0] = v11;
  maxSurfaceRotSpeed = core->max_surface_deviation * v4;
  core->abs_omega = v4;
  core->max_surface_rot_speed = maxSurfaceRotSpeed;
  return maxSurfaceRotSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x10092EF0
// Name: public: static void IVP_Calc_Next_PSI_Solver::set_transformation(class IVP_Core __near *,class IVP_U_Quat const __near *,class IVP_U_Point const __near *,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall IVP_Calc_Next_PSI_Solver::set_transformation(
        IVP_Environment *a1@<ebp>,
        IVP_Core *core,
        IVP_U_Quat *rotation,
        const IVP_U_Point *position,
        IVP_BOOL optimize_for_repeated_calls)
{
  IVP_Environment *environment; // edi
  unsigned int seconds_low; // eax
  float v7; // xmm1_4
  float delta_PSI_time; // xmm0_4
  double inv_delta_PSI_time; // st7
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  bool v16; // sf
  float v17; // eax
  IVP_Real_Object *v18; // eax
  IVP_Hull_Manager *p_hull_manager; // edi
  float v20; // xmm0_4
  bool v21; // cc
  IVP_Real_Object *v22; // eax
  float v23; // xmm0_4
  int additional; // eax
  double seconds; // xmm2_8
  double time_of_next_reset; // xmm0_8
  float v27[3]; // [esp+14h] [ebp-4Ch] BYREF
  _BYTE moved_distance_4[24]; // [esp+24h] [ebp-3Ch] OVERLAPPED BYREF
  float v29; // [esp+40h] [ebp-20h]
  _DWORD *diff; // [esp+44h] [ebp-1Ch]
  IVP_Environment *v31; // [esp+48h] [ebp-18h]
  int c; // [esp+4Ch] [ebp-14h]
  IVP_Real_Object *v33; // [esp+50h] [ebp-10h]
  IVP_Environment *env; // [esp+54h] [ebp-Ch]
  float moved_distance_val; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  env = a1;
  moved_distance_val = retaddr;
  environment = core->environment;
  seconds_low = LODWORD(environment->current_time.seconds);
  *(_DWORD *)&moved_distance_4[20] = HIDWORD(environment->current_time.seconds);
  v31 = environment;
  *(_DWORD *)&moved_distance_4[16] = seconds_low;
  IVP_Environment::set_current_time(
    this: environment,
    time: (IVP_Time)__PAIR64__(*(unsigned int *)&moved_distance_4[20], seconds_low));
  v7 = *(double *)&moved_distance_4[16] - core->time_of_last_psi.seconds;
  delta_PSI_time = environment->delta_PSI_time;
  v29 = v7;
  if ( v7 < delta_PSI_time )
  {
    inv_delta_PSI_time = environment->inv_delta_PSI_time;
    v29 = delta_PSI_time;
    core->i_delta_time = inv_delta_PSI_time;
  }
  else
  {
    core->i_delta_time = 1.0 / v7;
  }
  core->time_of_last_psi = *(IVP_Time *)&moved_distance_4[16];
  core->q_world_f_core_next_psi = *rotation;
  IVP_U_Quat::set_invert_mult(
    this: (IVP_U_Quat *)moved_distance_4,
    q1: &core->q_world_f_core_last_psi,
    q2: &core->q_world_f_core_next_psi);
  core->q_world_f_core_last_psi = *rotation;
  core->time_of_last_psi.seconds = environment->time_of_last_psi.seconds;
  v27[0] = position->k[0] - core->pos_world_f_core_last_psi.k[0];
  v27[1] = position->k[1] - core->pos_world_f_core_last_psi.k[1];
  v27[2] = position->k[2] - core->pos_world_f_core_last_psi.k[2];
  *(float *)&c = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)v27);
  v10 = position->k[1];
  v11 = position->k[2];
  core->pos_world_f_core_last_psi.k[0] = position->k[0];
  core->pos_world_f_core_last_psi.k[1] = v10;
  core->pos_world_f_core_last_psi.k[2] = v11;
  core->delta_world_f_core_psis.k[2] = 0.0;
  core->delta_world_f_core_psis.k[1] = 0.0;
  core->delta_world_f_core_psis.k[0] = 0.0;
  core->speed.k[2] = 0.0;
  core->speed.k[1] = 0.0;
  core->speed.k[0] = 0.0;
  v12 = position->k[1];
  v13 = position->k[2];
  core->m_world_f_core_last_psi.vv.k[0] = position->k[0];
  core->m_world_f_core_last_psi.vv.k[1] = v12;
  core->m_world_f_core_last_psi.vv.k[2] = v13;
  IVP_U_Quat::set_matrix(this: rotation, mat: &core->m_world_f_core_last_psi);
  if ( optimize_for_repeated_calls != IVP_FALSE )
  {
    v14 = *(float *)&c * core->i_delta_time;
  }
  else
  {
    v14 = 0.0;
    memset(moved_distance_4, 0, 16);
  }
  core->current_speed = v14;
  IVP_Calc_Next_PSI_Solver::calc_psi_rotation_axis(core, q_core_f_core: (const IVP_U_Quat *)moved_distance_4);
  v15 = (float)((float)(core->max_surface_deviation * core->max_surface_rot_speed) * v29) + *(float *)&c;
  LODWORD(v17) = core->objects.n_elems - 1;
  v16 = core->objects.n_elems == 0;
  *(float *)&moved_distance_4[20] = v15;
  v29 = v17;
  if ( !v16 )
  {
    while ( 1 )
    {
      v18 = (IVP_Real_Object *)core->objects.elems[LODWORD(v17)];
      p_hull_manager = (IVP_Hull_Manager *)&v18->hull_manager;
      v20 = v18->hull_manager.hull_value_next_psi + v15;
      v18->hull_manager.hull_value_next_psi = v20;
      v18->hull_manager.hull_value_last_vpsi = v20;
      v18->hull_manager.hull_center_value_last_vpsi = v18->hull_manager.hull_center_value_last_vpsi + *(float *)&c;
      v18->hull_manager.gradient = 0.0;
      v18->hull_manager.center_gradient = 0.0;
      v21 = *(_BYTE *)&v18->flags < 8;
      v33 = v18;
      if ( !v21 )
      {
        IVP_Cache_Object_Manager::invalid_cache_object(object: v18);
        IVP_Real_Object::recalc_exact_mindists_of_object(this: v33);
        IVP_Real_Object::recalc_invalid_mindists_of_object(this: v33);
        v18 = v33;
      }
      if ( optimize_for_repeated_calls == IVP_FALSE )
        IVP_Mindist_Manager::recheck_ov_element(this: v31->mindist_manager, object: v18);
      v22 = (IVP_Real_Object *)IVP_Hull_Manager::get_synapse_check_count(this: p_hull_manager, pEnvironment: v31);
      v23 = p_hull_manager->sorted_synapses.min_value - p_hull_manager->hull_value_next_psi;
      v33 = v22;
      for ( diff = &v22->__vftable;
            v23 < 0.0;
            v23 = p_hull_manager->sorted_synapses.min_value - p_hull_manager->hull_value_next_psi )
      {
        (*(void (__stdcall **)(IVP_Hull_Manager *, float))(*(_DWORD *)p_hull_manager->sorted_synapses.elems[p_hull_manager->sorted_synapses.first_element].element
                                                         + 4))(
          a1: p_hull_manager,
          a2: COERCE_FLOAT(LODWORD(v23)));
        v33 = (IVP_Real_Object *)((char *)v33 - 1);
        if ( (int)v33 < 0 )
        {
          additional = IVP_Hull_Manager::too_many_synapses_checked_error_get_additional(
                         this: p_hull_manager,
                         pEnvironment: v31,
                         checked: (int)diff);
          v33 = (IVP_Real_Object *)((char *)v33 + additional);
          if ( (int)v33 < 0 )
            break;
          diff = (IVP_Real_Object_vtbl **)((char *)&v33->__vftable + (_DWORD)diff + 1);
        }
      }
      seconds = p_hull_manager->last_vpsi_time.seconds;
      time_of_next_reset = (double)p_hull_manager->time_of_next_reset;
      diff = &p_hull_manager->time_of_next_reset;
      if ( seconds > time_of_next_reset )
      {
        IVP_Hull_Manager::reset_times(this: p_hull_manager);
        *diff = (int)(p_hull_manager->last_vpsi_time.seconds + 10.0);
      }
      --LODWORD(v29);
      if ( v29 < 0.0 )
        break;
      v15 = *(float *)&moved_distance_4[20];
      v17 = v29;
    }
  }
  core->current_speed = 0.0;
  core->abs_omega = 0.0;
  core->max_surface_rot_speed = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10093280
// Name: public: static void IVP_Calc_Next_PSI_Solver::commit_all_hull_managers(class IVP_Environment __near *,class IVP_U_Vector<class IVP_Hull_Manager_Base> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Calc_Next_PSI_Solver::commit_all_hull_managers(
        IVP_Environment *env,
        IVP_U_Vector<IVP_Hull_Manager_Base> *active_hull_managers)
{
  IVP_U_Vector<IVP_Hull_Manager_Base> *v2; // esi
  int v3; // ebx
  bool i; // zf
  void **elems; // edx
  const char *v6; // eoff
  _DWORD *v7; // eax
  int v8; // edi
  int v9; // esi
  int v10; // eax
  IVP_Hull_Manager *v11; // esi
  int v12; // eax
  float v13; // xmm0_4
  int v14; // edi
  IVP_Hull_Manager *v15; // edi
  IVP_Hull_Manager *v16; // esi
  int checked; // [esp+10h] [ebp-4h]

  v2 = active_hull_managers;
  v3 = active_hull_managers->n_elems - 1;
  for ( i = v3 == 1; v3 > 1; i = v3 == 1 )
  {
    elems = v2->elems;
    v6 = (const char *)elems[v3 - 2];
    _mm_prefetch(v6, 2);
    _mm_prefetch(v6 + 32, 2);
    v7 = elems[v3 - 1];
    v8 = v7[12];
    v9 = v7[9];
    v10 = v7[11];
    _mm_prefetch((const char *)(v9 + 16 * v8), 2);
    _mm_prefetch((const char *)(v9 + 16 * (v8 + 2)), 2);
    _mm_prefetch((const char *)(v9 + 16 * v10), 2);
    v11 = (IVP_Hull_Manager *)elems[v3];
    v12 = IVP_Hull_Manager::get_synapse_check_count(this: v11, pEnvironment: env);
    v13 = v11->sorted_synapses.min_value - v11->hull_value_next_psi;
    v14 = v12;
    for ( checked = v12; v13 < 0.0; v13 = v11->sorted_synapses.min_value - v11->hull_value_next_psi )
    {
      (*(void (__stdcall **)(IVP_Hull_Manager *, float))(*(_DWORD *)v11->sorted_synapses.elems[v11->sorted_synapses.first_element].element
                                                       + 4))(
        a1: v11,
        a2: COERCE_FLOAT(LODWORD(v13)));
      if ( --v14 < 0 )
      {
        v14 += IVP_Hull_Manager::too_many_synapses_checked_error_get_additional(this: v11, pEnvironment: env, checked);
        if ( v14 < 0 )
          break;
        checked += v14 + 1;
      }
    }
    if ( v11->last_vpsi_time.seconds > (double)v11->time_of_next_reset )
    {
      IVP_Hull_Manager::reset_times(this: v11);
      v11->time_of_next_reset = (int)(v11->last_vpsi_time.seconds + 10.0);
    }
    v2 = active_hull_managers;
    --v3;
  }
  if ( i )
  {
    v15 = *((IVP_Hull_Manager **)v2->elems + 1);
    IVP_Hull_Manager::check_hull_synapses(this: v15, pEnv: env);
    if ( v15->last_vpsi_time.seconds > (double)v15->time_of_next_reset )
    {
      IVP_Hull_Manager::reset_times(this: v15);
      v15->time_of_next_reset = (int)(v15->last_vpsi_time.seconds + 10.0);
    }
  }
  else if ( v3 != 0 )
  {
    return;
  }
  v16 = (IVP_Hull_Manager *)*v2->elems;
  IVP_Hull_Manager::check_hull_synapses(this: v16, pEnv: env);
  if ( v16->last_vpsi_time.seconds > (double)v16->time_of_next_reset )
  {
    IVP_Hull_Manager::reset_times(this: v16);
    v16->time_of_next_reset = (int)(v16->last_vpsi_time.seconds + 10.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093410
// Name: public: static void IVP_Calc_Next_PSI_Solver::calc_next_PSI_matrix(class IVP_Core __near *,class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Hull_Manager_Base> __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall IVP_Calc_Next_PSI_Solver::calc_next_PSI_matrix(
        int a1@<ebp>,
        long double a2@<esi:edi>,
        IVP_Core *core,
        IVP_Event_Sim *event_sim,
        IVP_U_Vector<IVP_Hull_Manager_Base> *active_hull_managers_out)
{
  IVP_Environment *environment; // ecx
  float delta_sim_time; // xmm0_4
  IVP_Environment *v7; // eax
  long double v8; // xmm0_8
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float w; // xmm6_4
  float x; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  double v20; // st7
  bool v21; // sf
  int v22; // edx
  float v23; // xmm1_4
  double current_speed; // st7
  IVP_Environment *v25; // eax
  float *v26; // edi
  int seconds_low; // ecx
  int seconds_high; // eax
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  IVP_U_Vector<IVP_Hull_Manager_Base> *v35; // ecx
  _DWORD v36[2]; // [esp+30h] [ebp-2Ch] BYREF
  _BYTE v37[20]; // [esp+38h] [ebp-24h] OVERLAPPED
  int v38; // [esp+4Ch] [ebp-10h]
  int v39; // [esp+50h] [ebp-Ch] BYREF
  float new_speed; // [esp+54h] [ebp-8h]
  float retaddr; // [esp+5Ch] [ebp+0h]

  v39 = a1;
  new_speed = retaddr;
  HIDWORD(a2) = core;
  if ( core->car_wheel == nullptr || core->max_surface_deviation != 0.0 )
  {
    environment = core->environment;
    LODWORD(a2) = environment->anomaly_limits;
    if ( (core->car_wheel == nullptr || core->max_surface_deviation != 0.0)
      && (float)((float)((float)(core->rot_speed.k[0] * core->rot_speed.k[0])
                       + (float)(core->rot_speed.k[1] * core->rot_speed.k[1]))
               + (float)(core->rot_speed.k[2] * core->rot_speed.k[2])) > (float)((float)(environment->inv_delta_PSI_time
                                                                                       * *(float *)(LODWORD(a2) + 16))
                                                                               * (float)(environment->inv_delta_PSI_time
                                                                                       * *(float *)(LODWORD(a2) + 16))) )
    {
      environment->anomaly_manager->max_angular_velocity_exceeded(
        this: environment->anomaly_manager,
        a2: (IVP_Anomaly_Limits *)LODWORD(a2),
        a3: core,
        a4: &core->rot_speed);
    }
    if ( (float)((float)((float)(core->speed.k[0] * core->speed.k[0]) + (float)(core->speed.k[1] * core->speed.k[1]))
               + (float)(core->speed.k[2] * core->speed.k[2])) > (float)(*(float *)(LODWORD(a2) + 8)
                                                                       * *(float *)(LODWORD(a2) + 8)) )
      core->environment->anomaly_manager->max_velocity_exceeded(
        this: core->environment->anomaly_manager,
        a2: (IVP_Anomaly_Limits *)LODWORD(a2),
        a3: core,
        a4: &core->speed);
  }
  core->current_speed = IVP_U_Float_Point::fast_real_length(this: &core->speed);
  delta_sim_time = event_sim->delta_time;
  core->i_delta_time = event_sim->i_delta_time;
  IVP_Calc_Next_PSI_Solver::calc_rotation_matrix(
    a1: COERCE_FLOAT(&v39),
    a2,
    core: (IVP_Core *)HIDWORD(a2),
    delta_sim_time,
    q_core_f_core: (IVP_U_Quat *)v36);
  v7 = core->environment;
  v8 = v7->current_time.seconds - core->time_of_last_psi.seconds;
  core->time_of_last_psi.seconds = v7->current_time.seconds;
  v9 = *(float *)&v36[1];
  v10 = *(float *)v36;
  v11 = *(float *)v37;
  *(float *)&v8 = v8;
  v12 = (float)(core->delta_world_f_core_psis.k[2] * *(float *)&v8) + core->pos_world_f_core_last_psi.k[2];
  v13 = (float)(core->delta_world_f_core_psis.k[1] * *(float *)&v8) + core->pos_world_f_core_last_psi.k[1];
  *(float *)&v8 = (float)(*(float *)&v8 * core->delta_world_f_core_psis.k[0]) + core->pos_world_f_core_last_psi.k[0];
  core->pos_world_f_core_last_psi.k[2] = v12;
  core->pos_world_f_core_last_psi.k[1] = v13;
  core->pos_world_f_core_last_psi.k[0] = *(float *)&v8;
  *(float *)&v8 = core->speed.k[1];
  v14 = core->speed.k[2];
  core->delta_world_f_core_psis.k[0] = core->speed.k[0];
  core->delta_world_f_core_psis.k[2] = v14;
  core->delta_world_f_core_psis.k[1] = *(float *)&v8;
  core->q_world_f_core_last_psi = core->q_world_f_core_next_psi;
  w = core->q_world_f_core_next_psi.w;
  x = core->q_world_f_core_next_psi.x;
  v17 = (float)((float)((float)(*(float *)&v37[4] * core->q_world_f_core_next_psi.y) + (float)(v9 * w))
              + (float)(core->q_world_f_core_next_psi.z * v10))
      - (float)(*(float *)v37 * x);
  v18 = (float)((float)((float)(*(float *)&v37[4] * core->q_world_f_core_next_psi.z) + (float)(v11 * w))
              + (float)(v9 * x))
      - (float)(core->q_world_f_core_next_psi.y * v10);
  v19 = (float)((float)((float)(*(float *)&v37[4] * w) - (float)(x * v10))
              - (float)(v9 * core->q_world_f_core_next_psi.y))
      - (float)(*(float *)v37 * core->q_world_f_core_next_psi.z);
  core->q_world_f_core_next_psi.x = (float)((float)((float)(*(float *)&v37[4] * x) + (float)(v10 * w))
                                          + (float)(*(float *)v37 * core->q_world_f_core_next_psi.y))
                                  - (float)(v9 * core->q_world_f_core_next_psi.z);
  core->q_world_f_core_next_psi.y = v17;
  core->q_world_f_core_next_psi.z = v18;
  core->q_world_f_core_next_psi.w = v19;
  IVP_U_Quat::fast_normize_quat(this: &core->q_world_f_core_next_psi);
  _mm_prefetch((const char *)*core->objects.elems + 72, 2);
  v20 = IVP_Calc_Next_PSI_Solver::calc_psi_rotation_axis(core, q_core_f_core: (const IVP_U_Quat *)v36);
  v22 = core->objects.n_elems - 1;
  v21 = core->objects.n_elems == 0;
  *(float *)&v37[16] = v20 + core->current_speed;
  v38 = v22;
  if ( !v21 )
  {
    v23 = *(float *)&v37[16] * 1.00001;
    *(float *)&v37[16] = *(float *)&v37[16] * 1.00001;
    do
    {
      current_speed = core->current_speed;
      v25 = event_sim->environment;
      v26 = (float *)((char *)core->objects.elems[v22] + 72);
      *(long double *)v37 = v25->current_time.seconds;
      seconds_low = LODWORD(v25->current_time.seconds);
      seconds_high = HIDWORD(v25->current_time.seconds);
      v29 = *(double *)v37 - *(double *)v26;
      v30 = v29;
      v31 = v29 * v26[3];
      v26[3] = current_speed;
      v32 = (float)(v30 * v26[2]) + v26[4];
      v26[5] = v31 + v26[5];
      *(_DWORD *)v26 = seconds_low;
      v33 = (float)(event_sim->delta_time * v23) + v32;
      v26[4] = v32;
      v34 = v26[10] - v33;
      v26[6] = v33;
      *((_DWORD *)v26 + 1) = seconds_high;
      v26[2] = v23;
      if ( v34 < 0.0 )
      {
        v35 = active_hull_managers_out;
        if ( active_hull_managers_out->n_elems >= active_hull_managers_out->memsize )
        {
          IVP_U_Vector_Base::increment_mem(this: active_hull_managers_out);
          v23 = *(float *)&v37[16];
          v35 = active_hull_managers_out;
          v22 = v38;
        }
        v35->elems[v35->n_elems] = v26;
        ++active_hull_managers_out->n_elems;
      }
      v38 = --v22;
    }
    while ( v22 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100937F0
// Name: public: static void IVP_Calc_Next_PSI_Solver::commit_all_calc_next_PSI_matrix(class IVP_Environment __near *,class IVP_U_Vector<class IVP_Core> __near *,class IVP_U_Vector<class IVP_Hull_Manager_Base> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Calc_Next_PSI_Solver::commit_all_calc_next_PSI_matrix(
        IVP_Environment *env,
        IVP_U_Vector<IVP_Core> *cores_which_needs_calc_next_psi,
        IVP_U_Vector<IVP_Hull_Manager_Base> *active_hulls_out)
{
  float delta_PSI_time; // xmm0_4
  long double v4; // rdi
  bool i; // zf
  void **elems; // ecx
  IVP_Event_Sim event_sim; // [esp+0h] [ebp-10h] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  delta_PSI_time = env->delta_PSI_time;
  event_sim.environment = env;
  event_sim.delta_time = delta_PSI_time;
  if ( delta_PSI_time <= 1.0e-10 )
    event_sim.i_delta_time = 1.0e10;
  else
    event_sim.i_delta_time = 1.0 / delta_PSI_time;
  LODWORD(v4) = cores_which_needs_calc_next_psi;
  HIDWORD(v4) = cores_which_needs_calc_next_psi->n_elems - 1;
  for ( i = HIDWORD(v4) == 1; SHIDWORD(v4) > 1; i = HIDWORD(v4) == 1 )
  {
    elems = cores_which_needs_calc_next_psi->elems;
    _mm_prefetch((const char *)elems[HIDWORD(v4) - 2] + 192, 2);
    IVP_Calc_Next_PSI_Solver::calc_next_PSI_matrix(
      a1: (int)&savedregs,
      a2: v4,
      core: (IVP_Core *)elems[HIDWORD(v4)],
      &event_sim,
      active_hull_managers_out: active_hulls_out);
    --HIDWORD(v4);
  }
  if ( i )
  {
    IVP_Calc_Next_PSI_Solver::calc_next_PSI_matrix(
      a1: (int)&savedregs,
      a2: v4,
      core: *(IVP_Core **)(*(_DWORD *)(LODWORD(v4) + 4) + 4),
      &event_sim,
      active_hull_managers_out: active_hulls_out);
  }
  else if ( HIDWORD(v4) != 0 )
  {
    return;
  }
  IVP_Calc_Next_PSI_Solver::calc_next_PSI_matrix(
    a1: (int)&savedregs,
    a2: v4,
    core: **(IVP_Core ***)(LODWORD(v4) + 4),
    &event_sim,
    active_hull_managers_out: active_hulls_out);
}
