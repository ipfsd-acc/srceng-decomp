// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_environment.cxx
// Functions: 43
// ============================================================

#include "ivp\ivp_intern\ivp_environment.h"

//------------------------------------------------------------------------------
// Address: 0x1007F910
// Name: public: virtual void IVP_Time_Event::simulate_time_event(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Time_Event::simulate_time_event(IVP_Time_Event *this, IVP_Environment *__formal)
{
  _Error(
    a1: "IVP Failed at %s %d\n",
    "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\ivp\\ivp_physics\\ivp_time_event.hxx",
    19);
}

//------------------------------------------------------------------------------
// Address: 0x1007F930
// Name: public: void IVP_Environment::set_delta_PSI_time(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Environment::set_delta_PSI_time(IVP_Environment *this@<ecx>, int a2@<esi>, float psi_time)
{
  long double _FFFFFFFC; // [esp-4h] [ebp-4h]
  long double _FFFFFFFCa; // [esp-4h] [ebp-4h]

  LODWORD(_FFFFFFFC) = a2;
  this->delta_PSI_time = psi_time;
  this->inv_delta_PSI_time = 1.0 / psi_time;
  __libm_sse2_log(x: _FFFFFFFC);
  __libm_sse2_exp(x: _FFFFFFFCa);
  this->integrated_energy_damp = (float)0.8999999761581421 * psi_time;
}

//------------------------------------------------------------------------------
// Address: 0x1007F990
// Name: public: void IVP_Environment::set_gravity(class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::set_gravity(IVP_Environment *this, IVP_U_Point *gravity_)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = gravity_->k[1];
  v3 = gravity_->k[2];
  this->gravity.k[0] = gravity_->k[0];
  this->gravity.k[1] = v2;
  this->gravity.k[2] = v3;
  this->gravity_scalar = IVP_U_Float_Point::fast_real_length(this: gravity_);
  IVP_Standard_Gravity_Controller::set_standard_gravity(this: this->standard_gravity_controller, gravity: gravity_);
}

//------------------------------------------------------------------------------
// Address: 0x1007F9E0
// Name: public: class IVP_Actuator_Torque __near * IVP_Environment::create_torque(class IVP_Template_Torque __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Torque_Active *__thiscall IVP_Environment::create_torque(
        IVP_Environment *this,
        IVP_Template_Torque *templ)
{
  IVP_Actuator_Torque *v3; // eax
  IVP_Actuator_Torque_Active *v5; // eax

  if ( templ->active_float_torque != nullptr || templ->active_float_max_rotation_speed != nullptr )
  {
    v5 = (IVP_Actuator_Torque_Active *)p_malloc(size: 0xE0u);
    if ( v5 != nullptr )
      return IVP_Actuator_Torque_Active::IVP_Actuator_Torque_Active(this: v5, env: this, templ);
  }
  else
  {
    v3 = (IVP_Actuator_Torque *)p_malloc(size: 0xD0u);
    if ( v3 != nullptr )
      return (IVP_Actuator_Torque_Active *)IVP_Actuator_Torque::IVP_Actuator_Torque(this: v3, env: this, templ);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007FA40
// Name: public: class IVP_Actuator_Force __near * IVP_Environment::create_force(class IVP_Template_Force __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Force_Active *__thiscall IVP_Environment::create_force(IVP_Environment *this, IVP_Template_Force *templ)
{
  IVP_Actuator_Force_Active *v3; // eax
  IVP_Actuator_Force *v5; // eax

  if ( templ->active_float_force != nullptr )
  {
    v3 = (IVP_Actuator_Force_Active *)p_malloc(size: 0xC0u);
    if ( v3 != nullptr )
      return IVP_Actuator_Force_Active::IVP_Actuator_Force_Active(this: v3, env: this, templ);
  }
  else
  {
    v5 = (IVP_Actuator_Force *)p_malloc(size: 0xB0u);
    if ( v5 != nullptr )
      return (IVP_Actuator_Force_Active *)IVP_Actuator_Force::IVP_Actuator_Force(this: v5, env: this, templ);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007FAA0
// Name: public: class IVP_Actuator_Spring __near * IVP_Environment::create_spring(class IVP_Template_Spring __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Spring_Active *__thiscall IVP_Environment::create_spring(
        IVP_Environment *this,
        IVP_Template_Spring *templ)
{
  IVP_Actuator_Spring *v3; // eax
  IVP_Actuator_Spring_Active *v5; // eax

  if ( templ->active_float_spring_len != nullptr
    || templ->active_float_spring_constant != nullptr
    || templ->active_float_spring_damp != nullptr
    || templ->active_float_spring_rel_pos_damp != nullptr )
  {
    v5 = (IVP_Actuator_Spring_Active *)p_malloc(size: 0xF0u);
    if ( v5 != nullptr )
      return IVP_Actuator_Spring_Active::IVP_Actuator_Spring_Active(this: v5, env: this, spring_templ: templ);
  }
  else
  {
    v3 = (IVP_Actuator_Spring *)p_malloc(size: 0xD0u);
    if ( v3 != nullptr )
      return (IVP_Actuator_Spring_Active *)IVP_Actuator_Spring::IVP_Actuator_Spring(
                                             this: v3,
                                             env: this,
                                             spring_templ: templ,
                                             act_type: IVP_ACTUATOR_TYPE_SPRING);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007FB10
// Name: public: class IVP_Actuator_Suspension __near * IVP_Environment::create_suspension(class IVP_Template_Suspension __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Suspension *__thiscall IVP_Environment::create_suspension(
        IVP_Environment *this,
        IVP_Template_Suspension *templ)
{
  IVP_Actuator_Suspension *v3; // eax

  v3 = (IVP_Actuator_Suspension *)p_malloc(size: 0xE0u);
  if ( v3 != nullptr )
    return IVP_Actuator_Suspension::IVP_Actuator_Suspension(this: v3, env: this, templ);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007FB40
// Name: public: class IVP_Actuator_Stabilizer __near * IVP_Environment::create_stabilizer(class IVP_Template_Stabilizer __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Stabilizer *__thiscall IVP_Environment::create_stabilizer(
        IVP_Environment *this,
        IVP_Template_Stabilizer *templ)
{
  IVP_Actuator_Stabilizer *v3; // eax

  v3 = (IVP_Actuator_Stabilizer *)p_malloc(size: 0x130u);
  if ( v3 != nullptr )
    return IVP_Actuator_Stabilizer::IVP_Actuator_Stabilizer(this: v3, env: this, templ);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007FB70
// Name: public: static class IVP_Environment_Manager __near * IVP_Environment_Manager::get_environment_manager(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Environment_Manager *__cdecl IVP_Environment_Manager::get_environment_manager()
{
  return &IVP_Environment_Manager::static_environment_manager;
}

//------------------------------------------------------------------------------
// Address: 0x1007FB80
// Name: public: void IVP_Environment::simulate_dtime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::simulate_dtime(IVP_Environment *this, float dtime)
{
  IVP_Time_Manager::event_loop(
    this: this->time_manager,
    env: this,
    time: COERCE_IVP_TIME(dtime + this->current_time.seconds));
}

//------------------------------------------------------------------------------
// Address: 0x1007FBD0
// Name: public: void IVP_Environment::simulate_time_step(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::simulate_time_step(IVP_Environment *this, float sub_psi_time)
{
  IVP_Time_Manager::event_loop(
    this: this->time_manager,
    env: this,
    time: COERCE_IVP_TIME((float)(this->delta_PSI_time * sub_psi_time) + this->time_of_last_psi.seconds));
}

//------------------------------------------------------------------------------
// Address: 0x1007FC20
// Name: private: void IVP_Environment::set_current_time(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::set_current_time(IVP_Environment *this, IVP_Time time)
{
  ++this->current_time_code;
  this->current_time = time;
}

//------------------------------------------------------------------------------
// Address: 0x1007FC40
// Name: public: void IVP_Environment::force_psi_on_next_simulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::force_psi_on_next_simulation(IVP_Environment *this)
{
  IVP_Time_Manager::update_event(
    this: this->time_manager,
    event: this->time_manager->psi_event,
    time: this->current_time);
}

//------------------------------------------------------------------------------
// Address: 0x1007FC60
// Name: public: class IVP_Polygon __near * IVP_Environment::create_polygon(class IVP_SurfaceManager __near *,class IVP_Template_Real_Object const __near *,class IVP_U_Quat const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Polygon *__thiscall IVP_Environment::create_polygon(
        IVP_Environment *this,
        IVP_SurfaceManager *vic,
        const IVP_Template_Real_Object *templ,
        const IVP_U_Quat *rotation,
        const IVP_U_Point *position)
{
  IVP_Polygon *v6; // esi
  IVP_Cluster *root_cluster; // eax

  v6 = (IVP_Polygon *)p_malloc(size: 0xB0u);
  if ( v6 == nullptr )
    return nullptr;
  root_cluster = IVP_Cluster_Manager::get_root_cluster(this: this->cluster_manager);
  return IVP_Polygon::IVP_Polygon(
           this: v6,
           cluster: root_cluster,
           surface_manager_: vic,
           templ,
           q_world_f_obj: rotation,
           position);
}

//------------------------------------------------------------------------------
// Address: 0x1007FCB0
// Name: public: class IVP_Ball __near * IVP_Environment::create_ball(class IVP_Template_Ball const __near *,class IVP_Template_Real_Object const __near *,class IVP_U_Quat const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Ball *__thiscall IVP_Environment::create_ball(
        IVP_Environment *this,
        const IVP_Template_Ball *templ_ball,
        const IVP_Template_Real_Object *templ,
        const IVP_U_Quat *rotation,
        const IVP_U_Point *position)
{
  IVP_Ball *v6; // esi
  IVP_Cluster *root_cluster; // eax

  v6 = (IVP_Ball *)p_malloc(size: 0xB0u);
  if ( v6 == nullptr )
    return nullptr;
  root_cluster = IVP_Cluster_Manager::get_root_cluster(this: this->cluster_manager);
  return IVP_Ball::IVP_Ball(this: v6, father: root_cluster, tball: templ_ball, templ, rotation, position);
}

//------------------------------------------------------------------------------
// Address: 0x1007FD00
// Name: public: static void IVP_Environment::set_global_collision_tolerance(float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Environment::set_global_collision_tolerance(float tolerance, float gravity_length)
{
  IVP_Mindist_Settings::set_collision_tolerance(this: &ivp_mindist_settings, t: tolerance, gravLength: gravity_length);
}

//------------------------------------------------------------------------------
// Address: 0x1007FD30
// Name: public: static float IVP_Environment::get_global_collision_tolerance(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IVP_Environment::get_global_collision_tolerance()
{
  return ivp_mindist_settings.min_coll_dists;
}

//------------------------------------------------------------------------------
// Address: 0x1007FD40
// Name: protected: virtual enum IVP_BOOL IVP_U_Set<class IVP_Real_Object>::compare(void __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_U_Set<IVP_Real_Object>::compare(IVP_U_Set<IVP_Mindist_Base> *this, void *elem0, void *elem1)
{
  return elem0 == elem1;
}

//------------------------------------------------------------------------------
// Address: 0x1007FD90
// Name: public: void IVP_Environment::fire_object_is_removed_from_collision_detection(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_object_is_removed_from_collision_detection(
        IVP_Environment *this,
        IVP_Real_Object *obj)
{
  int v3; // esi
  void *v4; // ecx

  v3 = this->collision_delegator_roots.n_elems - 1;
  if ( this->collision_delegator_roots.n_elems != 0 )
  {
    do
    {
      v4 = this->collision_delegator_roots.elems[v3];
      (*(void (__thiscall **)(void *, IVP_Real_Object *))(*(_DWORD *)v4 + 16))(a1: v4, a2: obj);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FDC0
// Name: public: void IVP_Environment::reset_time(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::reset_time(IVP_Environment *this)
{
  unsigned int seconds_low; // ecx
  unsigned int seconds_high; // edx
  long double seconds; // xmm0_8
  long double v5; // kr00_8

  IVP_Time_Manager::reset_time(this: this->time_manager, offset: this->time_of_last_psi);
  IVP_Sim_Units_Manager::reset_time(this: this->sim_units_manager, offset: this->time_of_last_psi);
  seconds_low = LODWORD(this->time_of_last_psi.seconds);
  seconds_high = HIDWORD(this->time_of_last_psi.seconds);
  seconds = this->current_time.seconds;
  ++this->current_time_code;
  *(float *)&seconds = seconds - COERCE_DOUBLE(__PAIR64__(seconds_high, seconds_low));
  v5 = *(float *)&seconds;
  this->time_of_last_psi.seconds = 0.0;
  *(float *)&seconds = this->delta_PSI_time;
  this->current_time.seconds = v5;
  this->time_of_next_psi.seconds = *(float *)&seconds;
}

//------------------------------------------------------------------------------
// Address: 0x1007FE70
// Name: public: void IVP_Environment::delete_draw_vector_debug(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::delete_draw_vector_debug(IVP_Environment *this)
{
  IVP_Draw_Vector_Debug *draw_vectors; // esi
  IVP_Draw_Vector_Debug *next; // edi

  draw_vectors = this->draw_vectors;
  if ( draw_vectors != nullptr )
  {
    do
    {
      if ( draw_vectors->debug_text != nullptr )
      {
        free(data: draw_vectors->debug_text);
        draw_vectors->debug_text = nullptr;
      }
      next = draw_vectors->next;
      if ( draw_vectors->debug_text != nullptr )
      {
        free(data: draw_vectors->debug_text);
        draw_vectors->debug_text = nullptr;
      }
      free(data: draw_vectors);
      draw_vectors = next;
    }
    while ( next != nullptr );
    this->draw_vectors = nullptr;
  }
  else
  {
    this->draw_vectors = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FEE0
// Name: public: void IVP_Environment::fire_event_object_created(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_object_created(IVP_Environment *this, IVP_Event_Object *obj_event)
{
  int v3; // esi
  void *v4; // ecx

  v3 = this->global_object_listeners.n_elems - 1;
  if ( this->global_object_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->global_object_listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_Event_Object *))(*(_DWORD *)v4 + 4))(a1: v4, a2: obj_event);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FF10
// Name: public: void IVP_Environment::fire_event_object_deleted(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_object_deleted(IVP_Environment *this, IVP_Event_Object *obj_event)
{
  int v3; // esi
  void (__thiscall ***v4)(void *, IVP_Event_Object *); // ecx

  v3 = this->global_object_listeners.n_elems - 1;
  if ( this->global_object_listeners.n_elems != 0 )
  {
    do
    {
      v4 = (void (__thiscall ***)(void *, IVP_Event_Object *))this->global_object_listeners.elems[v3];
      (**v4)(a1: v4, a2: obj_event);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FF40
// Name: public: void IVP_Environment::fire_event_object_frozen(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_object_frozen(IVP_Environment *this, IVP_Event_Object *obj_event)
{
  int v3; // esi
  void *v4; // ecx

  v3 = this->global_object_listeners.n_elems - 1;
  if ( this->global_object_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->global_object_listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_Event_Object *))(*(_DWORD *)v4 + 12))(a1: v4, a2: obj_event);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FF70
// Name: public: void IVP_Environment::fire_event_object_revived(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_object_revived(IVP_Environment *this, IVP_Event_Object *obj_event)
{
  int v3; // esi
  void *v4; // ecx

  v3 = this->global_object_listeners.n_elems - 1;
  if ( this->global_object_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->global_object_listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_Event_Object *))(*(_DWORD *)v4 + 8))(a1: v4, a2: obj_event);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FFA0
// Name: private: void IVP_Environment::fire_event_pre_collision(class IVP_Event_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_pre_collision(IVP_Environment *this, IVP_Event_Collision *coll)
{
  int v3; // esi
  void (__thiscall ***v4)(void *, IVP_Event_Collision *); // ecx

  v3 = this->collision_listeners.n_elems - 1;
  if ( this->collision_listeners.n_elems != 0 )
  {
    do
    {
      v4 = (void (__thiscall ***)(void *, IVP_Event_Collision *))this->collision_listeners.elems[v3];
      if ( ((_BYTE)v4[1] & 8) != 0 )
        (**v4)(a1: v4, a2: coll);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FFE0
// Name: private: void IVP_Environment::fire_event_post_collision(class IVP_Event_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_post_collision(IVP_Environment *this, IVP_Event_Collision *coll)
{
  int v3; // esi
  _BYTE *v4; // ecx

  v3 = this->collision_listeners.n_elems - 1;
  if ( this->collision_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->collision_listeners.elems[v3];
      if ( (v4[4] & 1) != 0 )
        (*(void (__thiscall **)(_BYTE *, IVP_Event_Collision *))(*(_DWORD *)v4 + 4))(a1: v4, a2: coll);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080020
// Name: private: void IVP_Environment::fire_event_friction_created(class IVP_Event_Friction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_friction_created(IVP_Environment *this, IVP_Event_Friction *coll)
{
  int v3; // esi
  _BYTE *v4; // ecx

  v3 = this->collision_listeners.n_elems - 1;
  if ( this->collision_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->collision_listeners.elems[v3];
      if ( (v4[4] & 4) != 0 )
        (*(void (__thiscall **)(_BYTE *, IVP_Event_Friction *))(*(_DWORD *)v4 + 12))(a1: v4, a2: coll);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080060
// Name: private: void IVP_Environment::fire_event_friction_deleted(class IVP_Event_Friction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_friction_deleted(IVP_Environment *this, IVP_Event_Friction *coll)
{
  int v3; // esi
  _BYTE *v4; // ecx

  v3 = this->collision_listeners.n_elems - 1;
  if ( this->collision_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->collision_listeners.elems[v3];
      if ( (v4[4] & 4) != 0 )
        (*(void (__thiscall **)(_BYTE *, IVP_Event_Friction *))(*(_DWORD *)v4 + 16))(a1: v4, a2: coll);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100800A0
// Name: private: void IVP_Environment::fire_event_friction_pair_created(class IVP_Friction_Core_Pair __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_friction_pair_created(IVP_Environment *this, IVP_Friction_Core_Pair *pair)
{
  int v3; // esi
  _BYTE *v4; // ecx

  v3 = this->collision_listeners.n_elems - 1;
  if ( this->collision_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->collision_listeners.elems[v3];
      if ( (v4[4] & 4) != 0 )
        (*(void (__thiscall **)(_BYTE *, IVP_Friction_Core_Pair *))(*(_DWORD *)v4 + 20))(a1: v4, a2: pair);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100800E0
// Name: private: void IVP_Environment::fire_event_friction_pair_deleted(class IVP_Friction_Core_Pair __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_friction_pair_deleted(IVP_Environment *this, IVP_Friction_Core_Pair *pair)
{
  int v3; // esi
  _BYTE *v4; // ecx

  v3 = this->collision_listeners.n_elems - 1;
  if ( this->collision_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->collision_listeners.elems[v3];
      if ( (v4[4] & 4) != 0 )
        (*(void (__thiscall **)(_BYTE *, IVP_Friction_Core_Pair *))(*(_DWORD *)v4 + 24))(a1: v4, a2: pair);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080120
// Name: public: void IVP_Environment::fire_event_constraint_broken(class IVP_Constraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_constraint_broken(IVP_Environment *this, IVP_Constraint *constraint)
{
  int v3; // esi
  void *v4; // ecx

  v3 = this->constraint_listeners.n_elems - 1;
  if ( this->constraint_listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->constraint_listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_Constraint *))(*(_DWORD *)v4 + 4))(a1: v4, a2: constraint);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080150
// Name: public: void IVP_Environment::fire_event_constraint_broken(class hk_Breakable_Constraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::fire_event_constraint_broken(
        IVP_Environment *this,
        hk_Breakable_Constraint *constraint)
{
  int v3; // esi
  void (__thiscall ***v4)(void *, hk_Breakable_Constraint *); // ecx

  v3 = this->constraint_listeners.n_elems - 1;
  if ( this->constraint_listeners.n_elems != 0 )
  {
    do
    {
      v4 = (void (__thiscall ***)(void *, hk_Breakable_Constraint *))this->constraint_listeners.elems[v3];
      (**v4)(a1: v4, a2: constraint);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080180
// Name: public: IVP_Environment::~IVP_Environment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::~IVP_Environment(IVP_Environment *this)
{
  int v2; // edi
  void *v3; // ecx
  IVP_Cluster_Manager *cluster_manager; // edi
  IVP_Standard_Gravity_Controller *standard_gravity_controller; // ecx
  IVP_Time_Manager *time_manager; // edi
  IVP_Mindist_Manager *mindist_manager; // edi
  IVP_OV_Tree_Manager *ov_tree_manager; // edi
  IVP_BetterStatisticsmanager *better_statisticsmanager; // edi
  IVP_PerformanceCounter *performancecounter; // ecx
  IVP_Anomaly_Manager *anomaly_manager; // ecx
  IVP_Anomaly_Limits *anomaly_limits; // ecx
  IVP_U_Active_Value_Manager *l_active_value_manager; // ecx
  IVP_Material_Manager *l_material_manager; // ecx
  IVP_Range_Manager *range_manager; // ecx
  bool v16; // sf
  int v17; // edi
  void *v18; // ecx
  IVP_Environment *elems; // eax
  IVP_U_Memory *short_term_mem; // edi
  IVP_U_Memory *sim_unit_mem; // edi
  IVP_Cache_Object_Manager *cache_object_manager; // edi
  IVP_Environment_Manager *environment_manager; // ecx
  unsigned __int16 n_elems; // di
  int v25; // eax
  IVP_Environment **v26; // edx
  IVP_Environment *v27; // eax
  IVP_Environment *v28; // eax
  IVP_Environment *v29; // eax
  IVP_Environment *v30; // eax
  IVP_Environment *v31; // eax
  IVP_Environment *v32; // eax
  IVP_Controller_Manager *controller_manager; // [esp-8h] [ebp-10h]
  IVP_Sim_Units_Manager *sim_units_manager; // [esp-8h] [ebp-10h]

  if ( this->environment_magic_number == 123456 )
  {
    v2 = this->psi_listeners.n_elems - 1;
    if ( this->psi_listeners.n_elems != 0 )
    {
      do
      {
        v3 = this->psi_listeners.elems[v2];
        (*(void (__thiscall **)(void *, IVP_Environment *))(*(_DWORD *)v3 + 4))(a1: v3, a2: this);
        --v2;
      }
      while ( v2 >= 0 );
    }
    CPolyhedron_AllocByNew::Release(this: (CPolyhedron_AllocByNew *)this->static_object);
    cluster_manager = this->cluster_manager;
    this->static_object = nullptr;
    if ( cluster_manager != nullptr )
    {
      IVP_Cluster_Manager::~IVP_Cluster_Manager(this: cluster_manager);
      free(data: cluster_manager);
    }
    standard_gravity_controller = this->standard_gravity_controller;
    this->cluster_manager = nullptr;
    if ( standard_gravity_controller != nullptr )
      ((void (__thiscall *)(IVP_Standard_Gravity_Controller *, int))standard_gravity_controller->dtr_IVP_Controller)(
        a1: standard_gravity_controller,
        a2: 1);
    controller_manager = this->controller_manager;
    this->standard_gravity_controller = nullptr;
    free(data: controller_manager);
    time_manager = this->time_manager;
    this->controller_manager = nullptr;
    if ( time_manager != nullptr )
    {
      IVP_Time_Manager::~IVP_Time_Manager(this: time_manager);
      free(data: time_manager);
    }
    sim_units_manager = this->sim_units_manager;
    this->time_manager = nullptr;
    free(data: sim_units_manager);
    mindist_manager = this->mindist_manager;
    this->sim_units_manager = nullptr;
    if ( mindist_manager != nullptr )
    {
      IVP_Mindist_Manager::~IVP_Mindist_Manager(this: mindist_manager);
      free(data: mindist_manager);
    }
    ov_tree_manager = this->ov_tree_manager;
    this->mindist_manager = nullptr;
    if ( ov_tree_manager != nullptr )
    {
      IVP_OV_Tree_Manager::~IVP_OV_Tree_Manager(this: ov_tree_manager);
      free(data: ov_tree_manager);
    }
    better_statisticsmanager = this->better_statisticsmanager;
    this->ov_tree_manager = nullptr;
    if ( better_statisticsmanager != nullptr )
    {
      IVP_BetterStatisticsmanager::~IVP_BetterStatisticsmanager(this: better_statisticsmanager);
      free(data: better_statisticsmanager);
    }
    performancecounter = this->performancecounter;
    this->better_statisticsmanager = nullptr;
    performancecounter->environment_is_going_to_be_deleted(this: performancecounter, a2: this);
    this->collision_filter->environment_will_be_deleted(this: this->collision_filter, a2: this);
    anomaly_manager = this->anomaly_manager;
    this->collision_filter = nullptr;
    anomaly_manager->environment_will_be_deleted(this: anomaly_manager, a2: this);
    anomaly_limits = this->anomaly_limits;
    this->anomaly_manager = nullptr;
    anomaly_limits->environment_will_be_deleted(this: anomaly_limits, a2: this);
    l_active_value_manager = this->l_active_value_manager;
    this->anomaly_limits = nullptr;
    l_active_value_manager->environment_will_be_deleted(this: l_active_value_manager, a2: this);
    l_material_manager = this->l_material_manager;
    this->l_active_value_manager = nullptr;
    l_material_manager->environment_will_be_deleted(this: l_material_manager, a2: this);
    range_manager = this->range_manager;
    this->l_material_manager = nullptr;
    range_manager->environment_will_be_deleted(this: range_manager, a2: this);
    v17 = this->collision_delegator_roots.n_elems - 1;
    v16 = this->collision_delegator_roots.n_elems == 0;
    this->range_manager = nullptr;
    if ( !v16 )
    {
      do
      {
        v18 = this->collision_delegator_roots.elems[v17];
        (*(void (__thiscall **)(void *, IVP_Environment *))(*(_DWORD *)v18 + 24))(a1: v18, a2: this);
        --v17;
      }
      while ( v17 >= 0 );
    }
    elems = (IVP_Environment *)this->collision_delegator_roots.elems;
    if ( elems != (IVP_Environment *)&this->debug_information )
    {
      if ( elems != nullptr )
        free(data: this->collision_delegator_roots.elems);
      this->collision_delegator_roots.elems = nullptr;
      this->collision_delegator_roots.memsize = 0;
    }
    this->collision_delegator_roots.n_elems = 0;
    short_term_mem = this->short_term_mem;
    if ( short_term_mem != nullptr )
    {
      IVP_U_Memory::~IVP_U_Memory(this: this->short_term_mem);
      free(data: short_term_mem);
    }
    sim_unit_mem = this->sim_unit_mem;
    this->short_term_mem = nullptr;
    if ( sim_unit_mem != nullptr )
    {
      IVP_U_Memory::~IVP_U_Memory(this: sim_unit_mem);
      free(data: sim_unit_mem);
    }
    cache_object_manager = this->cache_object_manager;
    this->sim_unit_mem = nullptr;
    if ( cache_object_manager != nullptr )
    {
      IVP_Cache_Object_Manager::~IVP_Cache_Object_Manager(this: cache_object_manager);
      free(data: cache_object_manager);
    }
    environment_manager = this->environment_manager;
    this->cache_object_manager = nullptr;
    n_elems = environment_manager->environments.n_elems;
    v25 = n_elems - 1;
    if ( n_elems != 0 )
    {
      v26 = (IVP_Environment **)&environment_manager->environments.elems[v25];
      do
      {
        if ( *v26 == this )
          break;
        --v25;
        --v26;
      }
      while ( v25 >= 0 );
    }
    for ( environment_manager->environments.n_elems = n_elems - 1; v25 < environment_manager->environments.n_elems; ++v25 )
      environment_manager->environments.elems[v25] = environment_manager->environments.elems[v25 + 1];
    IVP_Environment::delete_draw_vector_debug(this);
  }
  v27 = (IVP_Environment *)this->collision_delegator_roots.elems;
  if ( v27 != (IVP_Environment *)&this->debug_information )
  {
    if ( v27 != nullptr )
      free(data: this->collision_delegator_roots.elems);
    this->collision_delegator_roots.elems = nullptr;
    this->collision_delegator_roots.memsize = 0;
  }
  this->collision_delegator_roots.n_elems = 0;
  v28 = (IVP_Environment *)this->global_object_listeners.elems;
  if ( v28 != (IVP_Environment *)&this->collision_delegator_roots )
  {
    if ( v28 != nullptr )
      free(data: this->global_object_listeners.elems);
    this->global_object_listeners.elems = nullptr;
    this->global_object_listeners.memsize = 0;
  }
  this->global_object_listeners.n_elems = 0;
  v29 = (IVP_Environment *)this->constraint_listeners.elems;
  if ( v29 != (IVP_Environment *)&this->environment_manager )
  {
    if ( v29 != nullptr )
      free(data: this->constraint_listeners.elems);
    this->constraint_listeners.elems = nullptr;
    this->constraint_listeners.memsize = 0;
  }
  this->constraint_listeners.n_elems = 0;
  v30 = (IVP_Environment *)this->core_revive_list.elems;
  if ( v30 != (IVP_Environment *)&this->constraint_listeners )
  {
    if ( v30 != nullptr )
      free(data: this->core_revive_list.elems);
    this->core_revive_list.elems = nullptr;
    this->core_revive_list.memsize = 0;
  }
  this->core_revive_list.n_elems = 0;
  v31 = (IVP_Environment *)this->psi_listeners.elems;
  if ( v31 != (IVP_Environment *)&this->core_revive_list )
  {
    if ( v31 != nullptr )
      free(data: this->psi_listeners.elems);
    this->psi_listeners.elems = nullptr;
    this->psi_listeners.memsize = 0;
  }
  this->psi_listeners.n_elems = 0;
  v32 = (IVP_Environment *)this->collision_listeners.elems;
  if ( v32 == (IVP_Environment *)&this->psi_listeners )
  {
    this->collision_listeners.n_elems = 0;
  }
  else
  {
    if ( v32 != nullptr )
      free(data: this->collision_listeners.elems);
    this->collision_listeners.elems = nullptr;
    *(_DWORD *)&this->collision_listeners.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080530
// Name: public: void IVP_Environment::add_listener_object_global(class IVP_Listener_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::add_listener_object_global(IVP_Environment *this, IVP_Listener_Object *listener)
{
  IVP_U_Vector<IVP_Listener_Object> *p_global_object_listeners; // esi

  p_global_object_listeners = &this->global_object_listeners;
  if ( this->global_object_listeners.n_elems >= this->global_object_listeners.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->global_object_listeners);
  p_global_object_listeners->elems[p_global_object_listeners->n_elems++] = listener;
}

//------------------------------------------------------------------------------
// Address: 0x10080570
// Name: public: void IVP_Environment::remove_listener_object_global(class IVP_Listener_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::remove_listener_object_global(IVP_Environment *this, IVP_Listener_Object *listener)
{
  unsigned __int16 n_elems; // si
  int v3; // eax
  IVP_Listener_Object **v4; // edx

  n_elems = this->global_object_listeners.n_elems;
  v3 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v4 = (IVP_Listener_Object **)&this->global_object_listeners.elems[v3];
    do
    {
      if ( *v4 == listener )
        break;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  for ( this->global_object_listeners.n_elems = n_elems - 1; v3 < this->global_object_listeners.n_elems; ++v3 )
    this->global_object_listeners.elems[v3] = this->global_object_listeners.elems[v3 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x100805D0
// Name: public: void IVP_Environment::add_listener_collision_global(class IVP_Listener_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::add_listener_collision_global(IVP_Environment *this, IVP_Listener_Collision *listener)
{
  IVP_U_Vector<IVP_Listener_Collision> *p_collision_listeners; // esi

  p_collision_listeners = &this->collision_listeners;
  if ( this->collision_listeners.n_elems >= this->collision_listeners.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->collision_listeners);
  p_collision_listeners->elems[p_collision_listeners->n_elems++] = listener;
}

//------------------------------------------------------------------------------
// Address: 0x10080610
// Name: public: void IVP_Environment::remove_listener_collision_global(class IVP_Listener_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::remove_listener_collision_global(
        IVP_Environment *this,
        IVP_Listener_Collision *listener)
{
  unsigned __int16 n_elems; // si
  int v3; // eax
  IVP_Listener_Collision **v4; // edx

  n_elems = this->collision_listeners.n_elems;
  v3 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v4 = (IVP_Listener_Collision **)&this->collision_listeners.elems[v3];
    do
    {
      if ( *v4 == listener )
        break;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  for ( this->collision_listeners.n_elems = n_elems - 1; v3 < this->collision_listeners.n_elems; ++v3 )
    this->collision_listeners.elems[v3] = this->collision_listeners.elems[v3 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10080670
// Name: public: void IVP_Environment::add_listener_constraint_global(class IVP_Listener_Constraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::add_listener_constraint_global(
        IVP_Environment *this,
        IVP_Listener_Constraint *listener)
{
  IVP_U_Vector<IVP_Listener_Constraint> *p_constraint_listeners; // esi

  p_constraint_listeners = &this->constraint_listeners;
  if ( this->constraint_listeners.n_elems >= this->constraint_listeners.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->constraint_listeners);
  p_constraint_listeners->elems[p_constraint_listeners->n_elems++] = listener;
}

//------------------------------------------------------------------------------
// Address: 0x100806B0
// Name: public: void IVP_Environment::remove_listener_constraint_global(class IVP_Listener_Constraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::remove_listener_constraint_global(
        IVP_Environment *this,
        IVP_Listener_Constraint *listener)
{
  unsigned __int16 n_elems; // si
  int v3; // eax
  IVP_Listener_Constraint **v4; // edx

  n_elems = this->constraint_listeners.n_elems;
  v3 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v4 = (IVP_Listener_Constraint **)&this->constraint_listeners.elems[v3];
    do
    {
      if ( *v4 == listener )
        break;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  for ( this->constraint_listeners.n_elems = n_elems - 1; v3 < this->constraint_listeners.n_elems; ++v3 )
    this->constraint_listeners.elems[v3] = this->constraint_listeners.elems[v3 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x100807A0
// Name: private: IVP_Environment::IVP_Environment(class IVP_Environment_Manager __near *,class IVP_Application_Environment __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IVP_Environment *__userpurge IVP_Environment::IVP_Environment@<eax>(
        IVP_Environment *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Environment_Manager *manager,
        IVP_Application_Environment *appl_env,
        const char *company_name,
        unsigned int auth_code)
{
  IVP_Application_Environment *v9; // eax
  IVP_Material_Manager *material_manager; // ecx
  IVP_Material_Manager *v11; // eax
  IVP_Material_Manager *v12; // eax
  IVP_U_Active_Value_Manager *env_active_float_manager; // ecx
  IVP_U_Active_Value_Manager *v14; // eax
  IVP_U_Active_Value_Manager *v15; // eax
  IVP_Anomaly_Manager *anomaly_manager; // ecx
  IVP_Anomaly_Manager *v17; // eax
  IVP_Anomaly_Manager *v18; // eax
  IVP_Anomaly_Limits *anomaly_limits; // ecx
  IVP_Anomaly_Limits *v20; // eax
  IVP_Anomaly_Limits *v21; // eax
  float hesse_val; // eax
  IVP_Collision_Delegator_Root_Mindist *v23; // eax
  IVP_Standard_Gravity_Controller *v24; // eax
  IVP_Standard_Gravity_Controller *standard_gravity_controller; // eax
  float v26; // xmm0_4
  float v27; // xmm1_4
  IVP_Controller_Manager *v28; // eax
  IVP_Cluster_Manager *v29; // eax
  IVP_Cluster_Manager *v30; // eax
  IVP_Sim_Units_Manager *v31; // eax
  IVP_Sim_Units_Manager *v32; // eax
  IVP_Time_Manager *v33; // eax
  IVP_Time_Manager *v34; // eax
  IVP_Mindist_Manager *v35; // eax
  IVP_Mindist_Manager *v36; // eax
  IVP_OV_Tree_Manager *v37; // eax
  IVP_OV_Tree_Manager *v38; // eax
  IVP_BetterStatisticsmanager *v39; // eax
  IVP_BetterStatisticsmanager *v40; // eax
  IVP_Range_Manager *v41; // eax
  IVP_Range_Manager *v42; // eax
  IVP_PerformanceCounter_Simple *performancecounter; // eax
  IVP_PerformanceCounter_Simple *v44; // eax
  IVP_Cache_Object_Manager *v45; // eax
  IVP_Cache_Object_Manager *v46; // eax
  float delta_PSI_time; // xmm0_4
  float v48; // eax
  float v49; // edx
  float v50; // eax
  IVP_U_Memory *v51; // eax
  IVP_U_Memory *v52; // eax
  IVP_U_Memory *v53; // eax
  IVP_U_Memory *v54; // eax
  int v55; // edi
  IVP_Ball *v56; // edi
  IVP_Cluster *root_cluster; // eax
  IVP_Ball *v58; // eax
  long double v60; // [esp-1Ch] [ebp-DCh]
  long double v61; // [esp-1Ch] [ebp-DCh]
  IVP_Template_Object v62[3]; // [esp-Ch] [ebp-CCh] BYREF
  IVP_Template_Real_Object t; // [esp+0h] [ebp-C0h] BYREF
  IVP_U_Matrix mco; // [esp+60h] [ebp-60h] BYREF
  IVP_U_Point position_4; // [esp+A4h] [ebp-1Ch] OVERLAPPED BYREF
  int v66; // [esp+B4h] [ebp-Ch]
  void *v67; // [esp+B8h] [ebp-8h]
  void *retaddr; // [esp+C0h] [ebp+0h]

  v66 = a2;
  v67 = retaddr;
  HIDWORD(v60) = a4;
  LODWORD(v60) = a3;
  IVP_Statistic_Manager::IVP_Statistic_Manager(this: &this->statistic_manager);
  *(_DWORD *)&this->collision_listeners.memsize = 0;
  this->collision_listeners.elems = nullptr;
  this->psi_listeners.elems = nullptr;
  *(_DWORD *)&this->psi_listeners.memsize = 0;
  *(_DWORD *)&this->core_revive_list.memsize = 0;
  this->core_revive_list.elems = nullptr;
  *(_DWORD *)&this->constraint_listeners.memsize = 0;
  this->constraint_listeners.elems = nullptr;
  *(_DWORD *)&this->global_object_listeners.memsize = 0;
  this->global_object_listeners.elems = nullptr;
  *(_DWORD *)&this->collision_delegator_roots.memsize = 0;
  this->collision_delegator_roots.elems = nullptr;
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Environment));
  v9 = appl_env;
  this->freeze_manager.freeze_check_dtime = 0.30000001;
  this->state = IVP_ES_AT;
  this->statistic_manager.l_environment = this;
  material_manager = appl_env->material_manager;
  this->l_material_manager = material_manager;
  if ( material_manager == nullptr )
  {
    v11 = (IVP_Material_Manager *)p_malloc(size: 8u);
    if ( v11 != nullptr )
      v12 = IVP_Material_Manager::IVP_Material_Manager(this: v11, delete_on_env_delete_in: IVP_TRUE);
    else
      v12 = nullptr;
    this->l_material_manager = v12;
    v9 = appl_env;
  }
  env_active_float_manager = v9->env_active_float_manager;
  this->l_active_value_manager = env_active_float_manager;
  if ( env_active_float_manager == nullptr )
  {
    v14 = (IVP_U_Active_Value_Manager *)p_malloc(size: 0x28u);
    if ( v14 != nullptr )
      v15 = IVP_U_Active_Value_Manager::IVP_U_Active_Value_Manager(this: v14, delete_on_env_delete_in: IVP_TRUE);
    else
      v15 = nullptr;
    this->l_active_value_manager = v15;
    v9 = appl_env;
  }
  this->collision_filter = v9->collision_filter;
  anomaly_manager = v9->anomaly_manager;
  this->anomaly_manager = anomaly_manager;
  if ( anomaly_manager == nullptr )
  {
    v17 = (IVP_Anomaly_Manager *)p_malloc(size: 8u);
    if ( v17 != nullptr )
      v18 = IVP_Anomaly_Manager::IVP_Anomaly_Manager(this: v17, delete_this_if_env_is_deleted_in: IVP_TRUE);
    else
      v18 = nullptr;
    this->anomaly_manager = v18;
    v9 = appl_env;
  }
  anomaly_limits = v9->anomaly_limits;
  this->anomaly_limits = anomaly_limits;
  if ( anomaly_limits == nullptr )
  {
    v20 = (IVP_Anomaly_Limits *)p_malloc(size: 0x20u);
    if ( v20 != nullptr )
      v21 = IVP_Anomaly_Limits::IVP_Anomaly_Limits(this: v20, delete_this_if_env_is_deleted_in: IVP_TRUE);
    else
      v21 = nullptr;
    this->anomaly_limits = v21;
    v9 = appl_env;
  }
  hesse_val = *(float *)&v9->default_collision_delegator_root;
  position_4.hesse_val = hesse_val;
  if ( hesse_val == 0.0 )
  {
    v23 = (IVP_Collision_Delegator_Root_Mindist *)p_malloc(size: 4u);
    if ( v23 != nullptr )
      LODWORD(position_4.hesse_val) = IVP_Collision_Delegator_Root_Mindist::IVP_Collision_Delegator_Root_Mindist(this: v23);
    else
      position_4.hesse_val = 0.0;
    if ( this->collision_delegator_roots.n_elems >= this->collision_delegator_roots.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->collision_delegator_roots);
    this->collision_delegator_roots.elems[this->collision_delegator_roots.n_elems] = (void *)LODWORD(position_4.hesse_val);
  }
  else
  {
    if ( this->collision_delegator_roots.n_elems >= this->collision_delegator_roots.memsize )
    {
      IVP_U_Vector_Base::increment_mem(this: &this->collision_delegator_roots);
      hesse_val = position_4.hesse_val;
    }
    *(float *)&this->collision_delegator_roots.elems[this->collision_delegator_roots.n_elems] = hesse_val;
  }
  ++this->collision_delegator_roots.n_elems;
  this->universe_manager = appl_env->universe_manager;
  v24 = (IVP_Standard_Gravity_Controller *)p_malloc(size: 0x30u);
  if ( v24 != nullptr )
    v24->__vftable = (IVP_Standard_Gravity_Controller_vtbl *)&IVP_Standard_Gravity_Controller::`vftable';
  else
    v24 = nullptr;
  this->standard_gravity_controller = v24;
  *(_QWORD *)position_4.k = 0x411D47AE00000000LL;
  position_4.k[2] = 0.0;
  this->gravity.k[0] = 0.0;
  this->gravity.k[1] = 9.8299999;
  this->gravity.k[2] = 0.0;
  this->gravity_scalar = IVP_U_Float_Point::fast_real_length(this: &position_4);
  IVP_Standard_Gravity_Controller::set_standard_gravity(this: this->standard_gravity_controller, gravity: &position_4);
  standard_gravity_controller = this->standard_gravity_controller;
  v26 = position_4.k[1];
  v27 = position_4.k[2];
  standard_gravity_controller->grav_vec.k[0] = position_4.k[0];
  standard_gravity_controller->grav_vec.k[1] = v26;
  standard_gravity_controller->grav_vec.k[2] = v27;
  if ( manager->environments.n_elems >= manager->environments.memsize )
    IVP_U_Vector_Base::increment_mem(this: &manager->environments);
  manager->environments.elems[manager->environments.n_elems++] = this;
  this->mindist_coll_dist_count = 0;
  v28 = (IVP_Controller_Manager *)p_malloc(size: 4u);
  if ( v28 != nullptr )
    v28->l_environment = this;
  else
    v28 = nullptr;
  this->delta_PSI_time = 0.015151516;
  this->inv_delta_PSI_time = 66.0;
  this->controller_manager = v28;
  __libm_sse2_log(x: v60);
  __libm_sse2_exp(x: v61);
  this->integrated_energy_damp = (float)0.8999999761581421 * 0.015151516;
  v29 = (IVP_Cluster_Manager *)p_malloc(size: 0x18u);
  if ( v29 != nullptr )
    v30 = IVP_Cluster_Manager::IVP_Cluster_Manager(this: v29, env: this);
  else
    v30 = nullptr;
  this->cluster_manager = v30;
  v31 = (IVP_Sim_Units_Manager *)p_malloc(size: 0x1B0u);
  if ( v31 != nullptr )
    v32 = IVP_Sim_Units_Manager::IVP_Sim_Units_Manager(this: v31, env: this);
  else
    v32 = nullptr;
  this->sim_units_manager = v32;
  v33 = (IVP_Time_Manager *)p_malloc(size: 0x20u);
  if ( v33 != nullptr )
    v34 = IVP_Time_Manager::IVP_Time_Manager(this: v33);
  else
    v34 = nullptr;
  this->time_manager = v34;
  v35 = (IVP_Mindist_Manager *)p_malloc(size: 0x18u);
  if ( v35 != nullptr )
    v36 = IVP_Mindist_Manager::IVP_Mindist_Manager(this: v35, i_env: this);
  else
    v36 = nullptr;
  this->mindist_manager = v36;
  v37 = (IVP_OV_Tree_Manager *)p_malloc(size: 0x38u);
  if ( v37 != nullptr )
    v38 = IVP_OV_Tree_Manager::IVP_OV_Tree_Manager(this: v37);
  else
    v38 = nullptr;
  this->ov_tree_manager = v38;
  v39 = (IVP_BetterStatisticsmanager *)p_malloc(size: 0x20u);
  if ( v39 != nullptr )
    v40 = IVP_BetterStatisticsmanager::IVP_BetterStatisticsmanager(this: v39);
  else
    v40 = nullptr;
  this->better_statisticsmanager = v40;
  this->range_manager = appl_env->range_manager;
  if ( appl_env->range_manager == nullptr )
  {
    v41 = (IVP_Range_Manager *)p_malloc(size: 0x34u);
    if ( v41 != nullptr )
      v42 = IVP_Range_Manager::IVP_Range_Manager(this: v41, env: this, delete_this_on_env_delete: IVP_TRUE);
    else
      v42 = nullptr;
    this->range_manager = v42;
  }
  performancecounter = (IVP_PerformanceCounter_Simple *)appl_env->performancecounter;
  if ( performancecounter == nullptr )
  {
    v44 = (IVP_PerformanceCounter_Simple *)p_malloc(size: 0xA8u);
    if ( v44 != nullptr )
      performancecounter = IVP_PerformanceCounter_Simple::IVP_PerformanceCounter_Simple(this: v44);
    else
      performancecounter = nullptr;
  }
  this->performancecounter = performancecounter;
  v45 = (IVP_Cache_Object_Manager *)p_malloc(size: 0xCu);
  if ( v45 != nullptr )
    v46 = IVP_Cache_Object_Manager::IVP_Cache_Object_Manager(
            this: v45,
            number_of_cache_elements: appl_env->n_cache_object);
  else
    v46 = nullptr;
  *(_QWORD *)&position_4.k[2] = 0;
  delta_PSI_time = this->delta_PSI_time;
  this->cache_object_manager = v46;
  v48 = position_4.k[2];
  *(double *)&position_4.k[2] = delta_PSI_time;
  this->environment_manager = manager;
  v49 = position_4.k[2];
  *(float *)&this->current_time.seconds = v48;
  v50 = position_4.hesse_val;
  this->current_time_code = 1;
  HIDWORD(this->current_time.seconds) = 0;
  *(float *)&this->time_of_next_psi.seconds = v49;
  *((float *)&this->time_of_next_psi.seconds + 1) = v50;
  v51 = (IVP_U_Memory *)p_malloc(size: 0x18u);
  if ( v51 != nullptr )
    v52 = IVP_U_Memory::IVP_U_Memory(this: v51);
  else
    v52 = nullptr;
  this->short_term_mem = v52;
  v53 = (IVP_U_Memory *)p_malloc(size: 0x18u);
  if ( v53 != nullptr )
    v54 = IVP_U_Memory::IVP_U_Memory(this: v53);
  else
    v54 = nullptr;
  this->sim_unit_mem = v54;
  v55 = appl_env->scratchpad_size >> 1;
  IVP_U_Memory::init_mem_transaction_usage(
    this: this->short_term_mem,
    external_mem: appl_env->scratchpad_addr,
    size: v55);
  IVP_U_Memory::init_mem_transaction_usage(
    this: this->sim_unit_mem,
    external_mem: &appl_env->scratchpad_addr[v55],
    size: v55);
  this->next_movement_check = 10;
  IVP_Mindist_Minimize_Solver::init_mms_function_table();
  IVP_Mindist_Event_Solver::init_mim_function_table();
  position_4.hesse_val = 1.0;
  IVP_Template_Real_Object::IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)v62);
  IVP_Template_Object::set_name(this: v62, s: "static_object");
  v62[1].name = (char *)1;
  IVP_U_Matrix::init(this: (IVP_U_Matrix *)&t.mass_center_override);
  memset(&mco.rows[2].k[1], 0, 12);
  LODWORD(t.rot_speed_damp_factor.k[2]) = &t.mass_center_override;
  memset(&mco.vv.k[1], 0, 12);
  v56 = (IVP_Ball *)p_malloc(size: 0xB0u);
  if ( v56 != nullptr )
  {
    root_cluster = IVP_Cluster_Manager::get_root_cluster(this: this->cluster_manager);
    v58 = IVP_Ball::IVP_Ball(
            this: v56,
            father: root_cluster,
            tball: (const IVP_Template_Ball *)&position_4.hesse_val,
            templ: (const IVP_Template_Real_Object *)v62,
            rotation: nullptr,
            position: (const IVP_U_Point *)&mco.vv.k[1]);
  }
  else
  {
    v58 = nullptr;
  }
  this->static_object = v58;
  IVP_Template_Real_Object::~IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)v62);
  this->environment_magic_number = 123456;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10080D70
// Name: public: class IVP_Environment __near * IVP_Environment_Manager::create_environment(class IVP_Application_Environment __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IVP_Environment *__userpurge IVP_Environment_Manager::create_environment@<eax>(
        IVP_Environment_Manager *this@<ecx>,
        int a2@<edi>,
        IVP_Application_Environment *appl_env,
        const char *costumer_name,
        unsigned int auth_code)
{
  IVP_Environment *v6; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v6 = (IVP_Environment *)p_malloc(size: 0x140u);
  if ( v6 != nullptr )
    return IVP_Environment::IVP_Environment(
             this: v6,
             a2: (int)&savedregs,
             a3: a2,
             a4: (int)this,
             manager: this,
             appl_env,
             company_name: costumer_name,
             auth_code);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10080DB0
// Name: private: void IVP_Environment::simulate_psi(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::simulate_psi(IVP_Environment *this, IVP_Time __formal)
{
  bool v3; // zf
  bool v4; // sf
  int v5; // edi
  void (__thiscall ***v6)(void *, IVP_Environment **); // ecx
  IVP_Sim_Units_Manager *sim_units_manager; // ecx
  IVP_Mindist_Manager *mindist_manager; // ecx
  IVP_Mindist_Manager *v9; // ecx
  IVP_Vector_of_Hulls_128 *elems; // eax
  IVP_Vector_of_Cores_128 touched_cores; // [esp+8h] [ebp-414h] BYREF
  IVP_Vector_of_Hulls_128 active_hulls; // [esp+210h] [ebp-20Ch] BYREF
  IVP_Environment *v13; // [esp+418h] [ebp-4h] BYREF

  this->performancecounter->pcount(this: this->performancecounter, a2: IVP_PE_PSI_UNIVERSE);
  v3 = this->core_revive_list.n_elems == 0;
  this->state = IVP_ES_PSI;
  if ( !v3 )
    IVP_Environment::revive_cores_PSI(this);
  if ( this->universe_manager != nullptr )
    IVP_Cluster_Manager::check_for_unused_objects(this: this->cluster_manager, um: this->universe_manager);
  this->l_active_value_manager->refresh_psi_active_values(this: this->l_active_value_manager, a2: this);
  v5 = this->psi_listeners.n_elems - 1;
  v4 = this->psi_listeners.n_elems == 0;
  v13 = this;
  if ( !v4 )
  {
    do
    {
      v6 = (void (__thiscall ***)(void *, IVP_Environment **))this->psi_listeners.elems[v5];
      (**v6)(a1: v6, a2: &v13);
      --v5;
    }
    while ( v5 >= 0 );
  }
  IVP_Mindist_Manager::recalc_all_exact_wheel_mindist(this: this->mindist_manager);
  this->performancecounter->pcount(this: this->performancecounter, a2: IVP_PE_PSI_CONTROLLERS);
  sim_units_manager = this->sim_units_manager;
  touched_cores.elems = touched_cores.elem_buffer;
  *(_DWORD *)&touched_cores.memsize = 128;
  IVP_Sim_Units_Manager::simulate_sim_units_psi(this: sim_units_manager, env: this, &touched_cores);
  this->performancecounter->pcount(this: this->performancecounter, a2: IVP_PE_PSI_INTEGRATORS);
  active_hulls.elems = (void **)active_hulls.elem_buffer;
  *(_DWORD *)&active_hulls.memsize = 128;
  IVP_Calc_Next_PSI_Solver::commit_all_calc_next_PSI_matrix(
    env: this,
    cores_which_needs_calc_next_psi: &touched_cores,
    active_hulls_out: &active_hulls);
  this->performancecounter->pcount(this: this->performancecounter, a2: IVP_PE_PSI_HULL);
  this->state = IVP_ES_PSI_HULL;
  IVP_Calc_Next_PSI_Solver::commit_all_hull_managers(env: this, active_hull_managers: &active_hulls);
  this->performancecounter->pcount(this: this->performancecounter, a2: IVP_PE_PSI_SHORT_MINDISTS);
  mindist_manager = this->mindist_manager;
  this->state = IVP_ES_PSI_SHORT;
  IVP_Mindist_Manager::recalc_all_exact_mindists(this: mindist_manager);
  this->performancecounter->pcount(this: this->performancecounter, a2: IVP_PE_PSI_CRITICAL_MINDISTS);
  v9 = this->mindist_manager;
  this->state = IVP_ES_PSI_CRITIC;
  IVP_Mindist_Manager::recalc_all_exact_mindists_events(this: v9);
  this->performancecounter->pcount(this: this->performancecounter, a2: IVP_PE_PSI_END);
  elems = (IVP_Vector_of_Hulls_128 *)active_hulls.elems;
  this->state = IVP_ES_AT;
  if ( elems != (IVP_Vector_of_Hulls_128 *)active_hulls.elem_buffer )
  {
    if ( elems != nullptr )
      free(data: elems);
    active_hulls.elems = nullptr;
    active_hulls.memsize = 0;
  }
  active_hulls.n_elems = 0;
  if ( touched_cores.elems != touched_cores.elem_buffer && touched_cores.elems != nullptr )
    free(data: touched_cores.elems);
}
