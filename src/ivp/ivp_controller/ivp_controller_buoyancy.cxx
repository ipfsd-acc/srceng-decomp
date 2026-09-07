// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_controller_buoyancy.cxx
// Functions: 8
// ============================================================

#include "ivp\ivp_controller\ivp_controller_buoyancy.h"

//------------------------------------------------------------------------------
// Address: 0x10086360
// Name: private: void IVP_Controller_Buoyancy::apply_buoyancy_impulse(class IVP_Real_Object __near *,class IVP_Template_Buoyancy __near *,float,float,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Controller_Buoyancy::apply_buoyancy_impulse(
        IVP_Controller_Buoyancy *this@<ecx>,
        float a2@<ebp>,
        IVP_Real_Object *object,
        IVP_Template_Buoyancy *temp_buoyancy,
        float delta_time,
        float volume_under,
        IVP_U_Float_Point *volume_center_under)
{
  IVP_Environment *environment; // eax
  IVP_Cache_Object *cache_object; // ecx
  float v10; // xmm0_4
  IVP_Core *core; // ecx
  _BYTE v12[12]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Point volume_center_under_ws; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Float_Point impulse_ws; // [esp+10h] [ebp-20h]
  IVP_U_Float_Point dir_ws; // [esp+20h] [ebp-10h] BYREF
  float retaddr; // [esp+30h] [ebp+0h]

  dir_ws.k[1] = a2;
  dir_ws.k[2] = retaddr;
  environment = this->core->environment;
  impulse_ws.k[1] = environment->gravity.k[0];
  impulse_ws.k[2] = environment->gravity.k[1];
  impulse_ws.hesse_val = environment->gravity.k[2];
  if ( volume_under > temp_buoyancy->buoyancy_eps )
  {
    if ( object->cache_object == nullptr )
      object->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                               this: object->environment->cache_object_manager,
                               object);
    if ( *(_BYTE *)&object->flags < 8 )
    {
      cache_object = object->cache_object;
      if ( object->environment->current_time_code > cache_object->valid_until_time_code )
        IVP_Cache_Object::update_cache_object(this: cache_object);
    }
    IVP_Cache_Object::transform_position_to_world_coords(
      this: object->cache_object,
      P_object: volume_center_under,
      P_world_out: (IVP_U_Point *)v12);
    v10 = (float)(COERCE_FLOAT(LODWORD(temp_buoyancy->medium_density) ^ _mask__NegFloat_) * volume_under) * delta_time;
    volume_center_under_ws.k[1] = impulse_ws.k[1] * v10;
    volume_center_under_ws.k[2] = impulse_ws.k[2] * v10;
    core = this->core;
    volume_center_under_ws.hesse_val = impulse_ws.hesse_val * v10;
    IVP_Core::async_push_core_ws(
      this: core,
      a2: COERCE_FLOAT((IVP_U_Float_Point *)&dir_ws.k[1]),
      world_point: (const IVP_U_Point *)v12,
      impulse_in_world: (IVP_U_Point *)&volume_center_under_ws.k[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086470
// Name: protected: virtual enum IVP_CONTROLLER_PRIORITY IVP_Controller_Buoyancy::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Controller_Buoyancy::get_controller_priority(IVP_Controller_Buoyancy *this)
{
  return 1600;
}

//------------------------------------------------------------------------------
// Address: 0x10086480
// Name: protected: virtual char const __near * IVP_Controller_Buoyancy::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Controller_Buoyancy::get_controller_name(IVP_Controller_Buoyancy *this)
{
  return "sys:buoyancy";
}

//------------------------------------------------------------------------------
// Address: 0x10086490
// Name: private: void IVP_Controller_Buoyancy::apply_dampening(class IVP_Real_Object __near *,float,float,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Controller_Buoyancy::apply_dampening(
        IVP_Controller_Buoyancy *this@<ecx>,
        int a2@<ebp>,
        IVP_Real_Object *object,
        float object_visible_surface_content_under,
        float delta_time,
        IVP_U_Float_Point *sum_impulse_x_movevector,
        IVP_U_Float_Point *sum_impulse_x_point,
        IVP_U_Float_Point *sum_impulse)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v11; // ecx
  IVP_Cache_Object *v12; // ecx
  IVP_Cache_Object *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  IVP_Controller_Buoyancy *v16; // edi
  IVP_Core *core; // ecx
  float *v18; // eax
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  _BYTE v26[12]; // [esp-Ch] [ebp-BCh] BYREF
  IVP_U_Matrix m_core_f_object; // [esp+0h] [ebp-B0h] BYREF
  IVP_U_Float_Point sum_impulse_ws; // [esp+40h] [ebp-70h] BYREF
  IVP_U_Float_Point sum_impulse_x_movevector_cs; // [esp+50h] [ebp-60h] BYREF
  IVP_U_Float_Point imp; // [esp+60h] [ebp-50h] BYREF
  IVP_U_Float_Point sum_impulse_x_point_cs; // [esp+70h] [ebp-40h] BYREF
  IVP_U_Point object_center_ws; // [esp+80h] [ebp-30h] BYREF
  IVP_Controller_Buoyancy *v33; // [esp+A0h] [ebp-10h]
  _DWORD v34[3]; // [esp+A4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+B0h] [ebp+0h]

  v34[0] = a2;
  v34[1] = retaddr;
  v33 = this;
  v8 = (float)((float)(fsqrt(object_visible_surface_content_under)
                     * this->attacher_buoyancy->template_buoyancy.torque_factor)
             * -0.1)
     * delta_time;
  sum_impulse_x_movevector->k[0] = sum_impulse_x_movevector->k[0] * v8;
  sum_impulse_x_movevector->k[1] = sum_impulse_x_movevector->k[1] * v8;
  sum_impulse_x_movevector->k[2] = sum_impulse_x_movevector->k[2] * v8;
  sum_impulse_x_point->k[0] = sum_impulse_x_point->k[0] * delta_time;
  sum_impulse_x_point->k[1] = sum_impulse_x_point->k[1] * delta_time;
  sum_impulse_x_point->k[2] = sum_impulse_x_point->k[2] * delta_time;
  sum_impulse->k[0] = sum_impulse->k[0] * delta_time;
  v9 = delta_time * sum_impulse->k[2];
  sum_impulse->k[1] = delta_time * sum_impulse->k[1];
  sum_impulse->k[2] = v9;
  if ( object->cache_object == nullptr )
    object->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                             this: object->environment->cache_object_manager,
                             object);
  if ( *(_BYTE *)&object->flags < 8 )
  {
    cache_object = object->cache_object;
    if ( object->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  sum_impulse_x_movevector_cs.k[1] = sum_impulse->k[0];
  v11 = object->cache_object;
  sum_impulse_x_movevector_cs.k[2] = sum_impulse->k[1];
  sum_impulse_x_movevector_cs.hesse_val = sum_impulse->k[2];
  IVP_Cache_Object::transform_vector_to_world_coords(
    this: v11,
    P_object: (IVP_U_Float_Point *)&sum_impulse_x_movevector_cs.k[1],
    P_world_out: (IVP_U_Float_Point *)&m_core_f_object.vv.k[1]);
  IVP_Real_Object::calc_m_core_f_object(this: object, m_core_f_object: (IVP_U_Matrix *)v26);
  if ( object->cache_object == nullptr )
    object->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                             this: object->environment->cache_object_manager,
                             object);
  if ( *(_BYTE *)&object->flags < 8 )
  {
    v12 = object->cache_object;
    if ( object->environment->current_time_code > v12->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: v12);
  }
  v13 = object->cache_object;
  v14 = v13->m_world_f_object.vv.k[2];
  v15 = v13->m_world_f_object.vv.k[0];
  v16 = v33;
  sum_impulse_x_point_cs.k[2] = v13->m_world_f_object.vv.k[1];
  object_center_ws.k[1] = m_core_f_object.vv.k[1];
  core = v33->core;
  object_center_ws.k[2] = m_core_f_object.vv.k[2];
  sum_impulse_x_point_cs.k[1] = v15;
  sum_impulse_x_point_cs.hesse_val = v14;
  object_center_ws.hesse_val = m_core_f_object.vv.hesse_val;
  IVP_Core::async_push_core_ws(
    this: core,
    a2: COERCE_FLOAT(v34),
    world_point: (const IVP_U_Point *)&sum_impulse_x_point_cs.k[1],
    impulse_in_world: (IVP_U_Point *)&object_center_ws.k[1]);
  IVP_U_Matrix3::vmult3(this: (IVP_U_Matrix3 *)v26, p_in: sum_impulse_x_point, p_out: (IVP_U_Float_Point *)&imp.k[1]);
  IVP_U_Matrix3::vmult3(
    this: (IVP_U_Matrix3 *)v26,
    p_in: sum_impulse_x_movevector,
    p_out: (IVP_U_Float_Point *)&sum_impulse_ws.k[1]);
  v18 = (float *)v16->core;
  v19 = v18[14] * imp.hesse_val;
  v20 = v18[14] * sum_impulse_ws.hesse_val;
  v21 = v18[40] + (float)((float)(v18[12] * sum_impulse_ws.k[1]) + (float)(imp.k[1] * v18[12]));
  v18[41] = v18[41] + (float)((float)(v18[13] * sum_impulse_ws.k[2]) + (float)(v18[13] * imp.k[2]));
  v22 = v18[42] + (float)(v20 + v19);
  v18[40] = v21;
  v18[42] = v22;
  if ( object->object_type == IVP_BALL )
  {
    v23 = (float)(v16->attacher_buoyancy->template_buoyancy.ball_rot_dampening_factor
                * object_visible_surface_content_under)
        / (float)((float)(object->extra_radius * 6.2831855) * object->extra_radius);
    v24 = v18[49] * v23;
    v25 = v18[50] * v23;
    v18[40] = v18[40] - (float)(v18[48] * v23);
    v18[41] = v18[41] - v24;
    v18[42] = v18[42] - v25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086790
// Name: protected: virtual void IVP_Controller_Buoyancy::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge IVP_Controller_Buoyancy::do_simulation_controller(
        IVP_Controller_Buoyancy *this@<ecx>,
        IVP_Template_Buoyancy *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Core *core; // eax
  float v8; // edi
  float v9; // xmm0_4
  float core_visible_surface_content_under; // xmm1_4
  float core_visible_surface_content_under_old; // xmm0_4
  float v12; // xmm0_4
  IVP_Core *v13; // eax
  float object_visible_surface_content_under; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // eax
  int v20; // edi
  IVP_Real_Object *object; // eax
  bool v22; // zf
  IVP_Cache_Object *cache_object; // eax
  IVP_Cache_Object *v24; // edx
  IVP_Cache_Object *v25; // ecx
  IVP_Core *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm2_4
  IVP_Controller_Buoyancy::Attacher_Interpolator *attacher_interpolator; // eax
  float v30; // xmm0_4
  IVP_Core *v31; // eax
  float v32; // xmm3_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  int v40; // [esp+38h] [ebp-21Ch] BYREF
  IVP_U_Matrix m_world_f_object; // [esp+44h] [ebp-210h] BYREF
  float v42; // [esp+D4h] [ebp-180h]
  float v43; // [esp+D8h] [ebp-17Ch]
  float v44; // [esp+DCh] [ebp-178h]
  float v45; // [esp+E0h] [ebp-174h]
  float v46; // [esp+E8h] [ebp-16Ch]
  float v47; // [esp+ECh] [ebp-168h]
  float v48; // [esp+F0h] [ebp-164h]
  float v49; // [esp+F8h] [ebp-15Ch]
  float v50; // [esp+FCh] [ebp-158h]
  float v51; // [esp+100h] [ebp-154h]
  float v52; // [esp+108h] [ebp-14Ch]
  float v53; // [esp+118h] [ebp-13Ch]
  long double v54; // [esp+11Ch] [ebp-138h]
  _DWORD v55[3]; // [esp+128h] [ebp-12Ch] BYREF
  IVP_U_Float_Point rel_speed_of_current_os; // [esp+134h] [ebp-120h] BYREF
  float v57[3]; // [esp+148h] [ebp-10Ch] BYREF
  IVP_U_Float_Point rel_speed_of_current_ws; // [esp+154h] [ebp-100h] BYREF
  IVP_U_Float_Point abs_speed_of_current_ws; // [esp+164h] [ebp-F0h]
  IVP_Buoyancy_Input b_input; // [esp+174h] [ebp-E0h] BYREF
  IVP_U_Float_Hesse surface_os; // [esp+1B4h] [ebp-A0h] BYREF
  IVP_U_Float_Hesse surface_hesse_ws; // [esp+1C4h] [ebp-90h]
  IVP_Buoyancy_Output b_output; // [esp+1D4h] [ebp-80h] BYREF
  IVP_U_Float_Point resulting_speed_of_current_ws; // [esp+234h] [ebp-20h]
  IVP_Cache_Object *v65; // [esp+244h] [ebp-10h]
  IVP_Template_Buoyancy *temp_buoyancy; // [esp+248h] [ebp-Ch] BYREF
  IVP_Environment *environment; // [esp+24Ch] [ebp-8h]
  IVP_Environment *retaddr; // [esp+254h] [ebp+0h]

  temp_buoyancy = a2;
  environment = retaddr;
  core = this->core;
  LODWORD(resulting_speed_of_current_ws.hesse_val) = es->environment;
  v8 = COERCE_FLOAT(
         ((int (__thiscall *)(IVP_Attacher_To_Cores_Buoyancy *, IVP_Core *, int, int))this->attacher_buoyancy->get_parameters_per_core)(
           a1: this->attacher_buoyancy,
           a2: core,
           a3,
           a4));
  v9 = *(float *)(LODWORD(v8) + 4);
  resulting_speed_of_current_ws.k[2] = v8;
  if ( v9 != 0.0 )
  {
    this->attacher_buoyancy->liquid_surface_descriptor->calc_liquid_surface(
      this: this->attacher_buoyancy->liquid_surface_descriptor,
      a2: (IVP_Environment *)&rel_speed_of_current_ws.k[1],
      a3: this->core,
      a4: (IVP_U_Float_Hesse *)&surface_os.k[1],
      a5: (IVP_U_Float_Point *)&rel_speed_of_current_ws.k[1]);
    core_visible_surface_content_under = this->core_visible_surface_content_under;
    core_visible_surface_content_under_old = this->core_visible_surface_content_under_old;
    if ( core_visible_surface_content_under > core_visible_surface_content_under_old )
    {
      v12 = core_visible_surface_content_under_old / core_visible_surface_content_under;
      this->relative_speed_of_current_in_objects_vicinity_old.k[0] = this->relative_speed_of_current_in_objects_vicinity_old.k[0]
                                                                   * v12;
      this->relative_speed_of_current_in_objects_vicinity_old.k[1] = this->relative_speed_of_current_in_objects_vicinity_old.k[1]
                                                                   * v12;
      this->relative_speed_of_current_in_objects_vicinity_old.k[2] = this->relative_speed_of_current_in_objects_vicinity_old.k[2]
                                                                   * v12;
    }
    v13 = this->core;
    this->core_visible_surface_content_under_old = this->core_visible_surface_content_under;
    this->core_visible_surface_content_under = 0.0;
    object_visible_surface_content_under = this->relative_speed_of_current_in_objects_vicinity_old.k[0]
                                         + rel_speed_of_current_ws.k[1];
    v15 = this->relative_speed_of_current_in_objects_vicinity_old.k[1] + rel_speed_of_current_ws.k[2];
    v16 = this->relative_speed_of_current_in_objects_vicinity_old.k[2] + rel_speed_of_current_ws.hesse_val;
    b_output.object_visible_surface_content_under = object_visible_surface_content_under;
    *(&b_output.object_visible_surface_content_under + 1) = v15;
    *(&b_output.object_visible_surface_content_under + 2) = v16;
    v17 = v15 - v13->speed.k[1];
    v18 = v16 - v13->speed.k[2];
    v57[0] = object_visible_surface_content_under - v13->speed.k[0];
    v57[1] = v17;
    v57[2] = v18;
    LODWORD(v19) = v13->objects.n_elems;
    if ( v19 != 0.0 )
    {
      v20 = 0;
      resulting_speed_of_current_ws.hesse_val = v19;
      do
      {
        object = this->attacher_interpolator[v20].object;
        v22 = object->cache_object == nullptr;
        v65 = (IVP_Cache_Object *)object;
        if ( v22 )
        {
          cache_object = IVP_Cache_Object_Manager::get_cache_object(
                           this: object->environment->cache_object_manager,
                           object);
          v24 = v65;
          LODWORD(v65->m_world_f_object.rows[2].k[0]) = cache_object;
          object = (IVP_Real_Object *)v24;
        }
        if ( *(_BYTE *)&object->flags < 8 )
        {
          v25 = object->cache_object;
          if ( object->environment->current_time_code > v25->valid_until_time_code )
          {
            IVP_Cache_Object::update_cache_object(this: v25);
            object = (IVP_Real_Object *)v65;
          }
        }
        v65 = object->cache_object;
        IVP_Cache_Object::transform_vector_to_object_coords(
          this: v65,
          P_world: (const IVP_U_Float_Point *)v57,
          P_object_out: (IVP_U_Float_Point *)v55);
        IVP_Cache_Object::transform_vector_to_object_coords(
          this: v65,
          P_world: (IVP_U_Float_Hesse *)&surface_os.k[1],
          P_object_out: (IVP_U_Float_Point *)&b_input.rot_speed.k[1]);
        IVP_Real_Object::get_m_world_f_object_AT(
          this: this->attacher_interpolator[v20].object,
          m_world_f_object_out: (IVP_U_Matrix *)&v40);
        v26 = this->core;
        LODWORD(b_input.surface_os.k[1]) = v55[0];
        LODWORD(b_input.surface_os.k[2]) = v55[1];
        LODWORD(b_input.surface_os.hesse_val) = v55[2];
        b_input.weight_statistic = b_input.rot_speed.k[1];
        LODWORD(resulting_speed_of_current_ws.hesse_val) = &b_output.object_visible_surface_content_under;
        b_input.time_stamp.seconds = *(long double *)&b_input.rot_speed.k[2];
        surface_os.k[0] = (float)((float)((float)(m_world_f_object.rows[2].k[1] * surface_os.k[1])
                                        + (float)(m_world_f_object.rows[2].k[2] * surface_os.k[2]))
                                + (float)(m_world_f_object.rows[2].hesse_val * surface_os.hesse_val))
                        + surface_hesse_ws.k[0];
        LODWORD(abs_speed_of_current_ws.k[1]) = 12;
        abs_speed_of_current_ws.k[2] = 0.0;
        b_input.rel_speed_of_current_os.k[0] = 0.0;
        b_input.rot_speed.k[0] = 0.0;
        b_input.surface_os.k[0] = surface_os.k[0];
        v27 = v26->rot_speed.k[1];
        v28 = v26->rot_speed.k[2];
        b_input.rel_speed_of_current_os.k[1] = v26->rot_speed.k[0];
        b_input.rel_speed_of_current_os.k[2] = v27;
        b_input.rel_speed_of_current_os.hesse_val = v28;
        LODWORD(surface_hesse_ws.k[1]) = 18;
        surface_hesse_ws.k[2] = 0.0;
        b_output.sum_impulse_x_movevector.k[1] = 0.0;
        b_output.sum_impulse_x_movevector.k[2] = 0.0;
        memset(&b_output.weight_statistic, 0, 12);
        memset(&b_output.volume_center_under.k[1], 0, 12);
        memset(&b_output.sum_impulse.k[1], 0, 12);
        memset(&b_output.sum_impulse_x_point.k[1], 0, 12);
        IVP_Buoyancy_Solver::IVP_Buoyancy_Solver(
          this: (IVP_Buoyancy_Solver *)&m_world_f_object.vv.k[1],
          core_: v26,
          cntrl: this,
          input: (const IVP_Template_Buoyancy *)LODWORD(resulting_speed_of_current_ws.k[2]),
          resulting_speed_of_current_ws_: (const IVP_U_Float_Point *)&b_output.object_visible_surface_content_under);
        rel_speed_of_current_os.k[1] = b_input.surface_os.k[1];
        attacher_interpolator = this->attacher_interpolator;
        rel_speed_of_current_os.k[2] = b_input.surface_os.k[2];
        rel_speed_of_current_os.hesse_val = b_input.surface_os.hesse_val;
        if ( IVP_Buoyancy_Solver::compute_forces(
               this: (IVP_Buoyancy_Solver *)&m_world_f_object.vv.k[1],
               rel_speed_of_current_os: (IVP_U_Float_Point *)&rel_speed_of_current_os.k[1],
               surface_os: (const IVP_U_Float_Hesse *)&b_input.weight_statistic,
               object: attacher_interpolator[v20].object) != IVP_FALSE )
        {
          b_output.sum_impulse_x_movevector.k[1] = v52;
          b_output.weight_statistic = v53;
          b_output.time_stamp.seconds = v54;
          b_output.sum_impulse_x_movevector.k[2] = v42;
          b_output.volume_center_under.k[1] = v43;
          b_output.volume_center_under.k[2] = v44;
          b_output.volume_center_under.hesse_val = v45;
          b_output.sum_impulse.k[1] = v46;
          b_output.sum_impulse.k[2] = v47;
          b_output.sum_impulse.hesse_val = v48;
          b_output.sum_impulse_x_point.k[1] = v49;
          b_output.sum_impulse_x_point.k[2] = v50;
          b_output.sum_impulse_x_point.hesse_val = v51;
        }
        IVP_Controller_Buoyancy::apply_buoyancy_impulse(
          this,
          a2: COERCE_FLOAT(&temp_buoyancy),
          object: this->attacher_interpolator[v20].object,
          temp_buoyancy: (IVP_Template_Buoyancy *)LODWORD(resulting_speed_of_current_ws.k[2]),
          delta_time: es->delta_time,
          volume_under: b_output.sum_impulse_x_movevector.k[1],
          volume_center_under: (IVP_U_Float_Point *)&b_output.weight_statistic);
        IVP_Controller_Buoyancy::apply_dampening(
          this,
          a2: (int)&temp_buoyancy,
          object: this->attacher_interpolator[v20].object,
          object_visible_surface_content_under: COERCE_FLOAT(LODWORD(b_output.sum_impulse_x_movevector.k[2]) & _mask__AbsFloat_),
          delta_time: es->delta_time,
          sum_impulse_x_movevector: (IVP_U_Float_Point *)&b_output.sum_impulse_x_point.k[1],
          sum_impulse_x_point: (IVP_U_Float_Point *)&b_output.sum_impulse.k[1],
          sum_impulse: (IVP_U_Float_Point *)&b_output.volume_center_under.k[1]);
        v30 = COERCE_FLOAT(LODWORD(b_output.sum_impulse_x_movevector.k[2]) & _mask__AbsFloat_)
            + this->core_visible_surface_content_under;
        ++v20;
        v22 = LODWORD(resulting_speed_of_current_ws.hesse_val)-- == 1;
        this->core_visible_surface_content_under = v30;
      }
      while ( !v22 );
      v16 = *(&b_output.object_visible_surface_content_under + 2);
      v15 = *(&b_output.object_visible_surface_content_under + 1);
      object_visible_surface_content_under = b_output.object_visible_surface_content_under;
      v8 = resulting_speed_of_current_ws.k[2];
    }
    v31 = this->core;
    v32 = v31->speed.k[0];
    v33 = v31->speed.k[2] - v16;
    v34 = 1.0 - (float)(*(float *)(LODWORD(v8) + 28) * es->delta_time);
    v35 = v31->speed.k[1];
    this->relative_speed_of_current_in_objects_vicinity_old.k[0] = this->relative_speed_of_current_in_objects_vicinity_old.k[0]
                                                                 * v34;
    this->relative_speed_of_current_in_objects_vicinity_old.k[1] = this->relative_speed_of_current_in_objects_vicinity_old.k[1]
                                                                 * v34;
    this->relative_speed_of_current_in_objects_vicinity_old.k[2] = this->relative_speed_of_current_in_objects_vicinity_old.k[2]
                                                                 * v34;
    v36 = *(float *)(LODWORD(v8) + 32) * es->delta_time;
    v37 = (float)((float)(v35 - v15) * v36) + this->relative_speed_of_current_in_objects_vicinity_old.k[1];
    v38 = (float)(v33 * v36) + this->relative_speed_of_current_in_objects_vicinity_old.k[2];
    this->relative_speed_of_current_in_objects_vicinity_old.k[0] = (float)(v36
                                                                         * (float)(v32
                                                                                 - object_visible_surface_content_under))
                                                                 + this->relative_speed_of_current_in_objects_vicinity_old.k[0];
    this->relative_speed_of_current_in_objects_vicinity_old.k[1] = v37;
    this->relative_speed_of_current_in_objects_vicinity_old.k[2] = v38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086D20
// Name: private: IVP_Controller_Buoyancy::IVP_Controller_Buoyancy(class IVP_Attacher_To_Cores<class IVP_Controller_Buoyancy> __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Controller_Buoyancy *__thiscall IVP_Controller_Buoyancy::IVP_Controller_Buoyancy(
        IVP_Controller_Buoyancy *this,
        IVP_Attacher_To_Cores_Buoyancy *attacher_buoyancy_,
        IVP_Core *core_)
{
  IVP_Core *core; // ecx
  int n_elems; // edi
  IVP_Controller_Buoyancy::Attacher_Interpolator *v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int nr_of_objects; // [esp+14h] [ebp+8h]

  this->attacher_buoyancy = attacher_buoyancy_;
  this->__vftable = (IVP_Controller_Buoyancy_vtbl *)&IVP_Controller_Buoyancy::`vftable';
  this->core = core_;
  IVP_Controller_Manager::add_controller_to_core(cntrl: this, core: core_);
  this->relative_speed_of_current_in_objects_vicinity_old.k[0] = 0.0;
  this->relative_speed_of_current_in_objects_vicinity_old.k[1] = 0.0;
  this->relative_speed_of_current_in_objects_vicinity_old.k[2] = 0.0;
  core = this->core;
  *(_QWORD *)&this->core_visible_surface_content_under = 0;
  n_elems = core->objects.n_elems;
  nr_of_objects = n_elems;
  v6 = (IVP_Controller_Buoyancy::Attacher_Interpolator *)p_malloc(size: 28 * n_elems);
  v7 = 0;
  this->attacher_interpolator = v6;
  if ( n_elems >= 4 )
  {
    v8 = 0;
    do
    {
      this->attacher_interpolator[v8].object = (IVP_Real_Object *)this->core->objects.elems[v7];
      this->attacher_interpolator[v8].last_io_vectors.last_psi_time = 0.0;
      this->attacher_interpolator[v8].nr_interpolated = 0;
      this->attacher_interpolator[v8].nr_not_interpolated = 0;
      this->attacher_interpolator[v8 + 1].object = (IVP_Real_Object *)this->core->objects.elems[v7 + 1];
      this->attacher_interpolator[v8 + 1].last_io_vectors.last_psi_time = 0.0;
      this->attacher_interpolator[v8 + 1].nr_interpolated = 0;
      this->attacher_interpolator[v8 + 1].nr_not_interpolated = 0;
      this->attacher_interpolator[v8 + 2].object = (IVP_Real_Object *)this->core->objects.elems[v7 + 2];
      this->attacher_interpolator[v8 + 2].last_io_vectors.last_psi_time = 0.0;
      this->attacher_interpolator[v8 + 2].nr_interpolated = 0;
      this->attacher_interpolator[v8 + 2].nr_not_interpolated = 0;
      this->attacher_interpolator[v8 + 3].object = (IVP_Real_Object *)this->core->objects.elems[v7 + 3];
      this->attacher_interpolator[v8 + 3].last_io_vectors.last_psi_time = 0.0;
      this->attacher_interpolator[v8 + 3].nr_interpolated = 0;
      this->attacher_interpolator[v8 + 3].nr_not_interpolated = 0;
      n_elems = nr_of_objects;
      v7 += 4;
      v8 += 4;
    }
    while ( v7 < nr_of_objects - 3 );
  }
  if ( v7 < n_elems )
  {
    v9 = v7;
    do
    {
      this->attacher_interpolator[v9].object = (IVP_Real_Object *)this->core->objects.elems[v7];
      this->attacher_interpolator[v9].last_io_vectors.last_psi_time = 0.0;
      this->attacher_interpolator[v9].nr_interpolated = 0;
      this->attacher_interpolator[v9].nr_not_interpolated = 0;
      ++v7;
      ++v9;
    }
    while ( v7 < nr_of_objects );
  }
  this->interpolation_counter = 0;
  this->nr_not_interpolated = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10086F00
// Name: public: IVP_Attacher_To_Cores_Buoyancy::IVP_Attacher_To_Cores_Buoyancy(class IVP_Template_Buoyancy __near &,class IVP_U_Set_Active<class IVP_Core> __near *,class IVP_Liquid_Surface_Descriptor __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Attacher_To_Cores_Buoyancy *__thiscall IVP_Attacher_To_Cores_Buoyancy::IVP_Attacher_To_Cores_Buoyancy(
        IVP_Attacher_To_Cores_Buoyancy *this,
        IVP_Template_Buoyancy *templ,
        IVP_U_Set_Active<IVP_Core> *set_of_cores_,
        IVP_Liquid_Surface_Descriptor *liquid_surface_descriptor_)
{
  IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>::IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>(
    this,
    set_of_cores_in: set_of_cores_);
  this->__vftable = (IVP_Attacher_To_Cores_Buoyancy_vtbl *)&IVP_Attacher_To_Cores_Buoyancy::`vftable';
  this->template_buoyancy.pressure_damp_factor = 0.1;
  this->template_buoyancy.medium_density = 0.30000001;
  this->template_buoyancy.friction_damp_factor = 0.050000001;
  this->template_buoyancy.buoyancy_eps = 1.0e-10;
  this->template_buoyancy.use_stochastic_insertion = IVP_TRUE;
  this->template_buoyancy.insert_extrapol_only = IVP_TRUE;
  this->template_buoyancy.nr_future_psi_for_extrapolation = 1;
  this->template_buoyancy.simulate_wing_behavior = IVP_FALSE;
  this->template_buoyancy.torque_factor = 1.0;
  this->template_buoyancy.viscosity_factor = 0.0099999998;
  this->template_buoyancy.viscosity_input_factor = 2.0;
  this->template_buoyancy.ball_rot_dampening_factor = 0.0099999998;
  this->template_buoyancy.use_interpolation = IVP_FALSE;
  this->template_buoyancy.max_interpolation_tries = 10;
  this->template_buoyancy.max_tries_nr_of_vectors_involved = 15;
  this->template_buoyancy.mi_weights.weight_current_speed = 1.0;
  this->template_buoyancy.mi_weights.weight_surface = 1.0;
  this->template_buoyancy.mi_weights.weight_rot_speed = 1.0;
  this->template_buoyancy.max_res = 0.0099999998;
  qmemcpy(&this->template_buoyancy, templ, sizeof(this->template_buoyancy));
  this->set_of_cores = set_of_cores_;
  this->liquid_surface_descriptor = liquid_surface_descriptor_;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10086FE0
// Name: public: virtual class IVP_Template_Buoyancy __near * IVP_Attacher_To_Cores_Buoyancy::get_parameters_per_core(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Buoyancy *__thiscall IVP_Attacher_To_Cores_Buoyancy::get_parameters_per_core(
        IVP_Attacher_To_Cores_Buoyancy *this,
        IVP_Core *__formal)
{
  return &this->template_buoyancy;
}
