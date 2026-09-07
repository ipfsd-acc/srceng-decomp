// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_object.cxx
// Functions: 47
// ============================================================

#include "ivp\ivp_intern\ivp_object.h"

//------------------------------------------------------------------------------
// Address: 0x1006F0C0
// Name: public: void IVP_Real_Object::change_mass(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::change_mass(IVP_Real_Object *this, float new_mass)
{
  IVP_Core::set_mass(this: this->physical_core, new_mass);
}

//------------------------------------------------------------------------------
// Address: 0x1006F0E0
// Name: public: void IVP_Real_Object::recompile_material_changed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::recompile_material_changed(IVP_Real_Object *this)
{
  IVP_Core::values_changed_recalc_redundants(this: this->physical_core);
}

//------------------------------------------------------------------------------
// Address: 0x1006F0F0
// Name: public: void IVP_Real_Object::add_listener_object(class IVP_Listener_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::add_listener_object(IVP_Real_Object *this, IVP_Listener_Object *listener)
{
  IVP_Cluster_Manager::add_listener_object(this: this->environment->cluster_manager, real_object: this, listener);
}

//------------------------------------------------------------------------------
// Address: 0x1006F110
// Name: public: void IVP_Real_Object::remove_listener_object(class IVP_Listener_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::remove_listener_object(IVP_Real_Object *this, IVP_Listener_Object *listener)
{
  IVP_Cluster_Manager::remove_listener_object(this: this->environment->cluster_manager, real_object: this, listener);
}

//------------------------------------------------------------------------------
// Address: 0x1006F130
// Name: public: void IVP_Real_Object::insert_anchor(class IVP_Anchor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::insert_anchor(IVP_Real_Object *this, IVP_Anchor *new_anchor)
{
  IVP_Anchor *anchors; // edx

  new_anchor->anchor_prev_in_object = nullptr;
  new_anchor->anchor_next_in_object = this->anchors;
  anchors = this->anchors;
  if ( anchors != nullptr )
    anchors->anchor_prev_in_object = new_anchor;
  this->anchors = new_anchor;
}

//------------------------------------------------------------------------------
// Address: 0x1006F160
// Name: public: void IVP_Real_Object::remove_anchor(class IVP_Anchor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::remove_anchor(IVP_Real_Object *this, IVP_Anchor *destroy_anch)
{
  IVP_Anchor *anchor_prev_in_object; // edx
  IVP_Anchor *anchor_next_in_object; // eax

  anchor_prev_in_object = destroy_anch->anchor_prev_in_object;
  anchor_next_in_object = destroy_anch->anchor_next_in_object;
  if ( anchor_prev_in_object != nullptr )
    anchor_prev_in_object->anchor_next_in_object = anchor_next_in_object;
  else
    this->anchors = anchor_next_in_object;
  if ( anchor_next_in_object != nullptr )
    anchor_next_in_object->anchor_prev_in_object = anchor_prev_in_object;
}

//------------------------------------------------------------------------------
// Address: 0x1006F190
// Name: protected: void IVP_Real_Object::update_exact_mindist_events_of_object(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::update_exact_mindist_events_of_object(IVP_Real_Object *this)
{
  IVP_Synapse_Real *exact_synapses; // eax
  int mindist_offset; // esi
  IVP_Synapse_Real *next; // edi
  int v4; // edx
  IVP_Mindist *v5; // esi

  exact_synapses = this->exact_synapses;
  if ( exact_synapses != nullptr )
  {
    do
    {
      mindist_offset = exact_synapses->mindist_offset;
      next = (IVP_Synapse_Real *)exact_synapses->next;
      v4 = *(int *)((char *)&exact_synapses[1].prev + mindist_offset);
      v5 = (IVP_Mindist *)((char *)exact_synapses + mindist_offset);
      if ( *(_DWORD *)(*(_DWORD *)(v4 + 148) + 416) != v5->synapse[1].l_obj->physical_core->mindist_event_already_done )
      {
        IVP_Mindist::recalc_mindist(this: v5);
        if ( (*((_DWORD *)&v5->IVP_Mindist_Base + 5) & 0xC000) == 0 )
          IVP_Mindist::update_exact_mindist_events(
            this: v5,
            allow_hull_conversion: IVP_FALSE,
            event_hint: IVP_EH_BIG_DELAY);
      }
      exact_synapses = next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F1F0
// Name: public: void IVP_Real_Object::revive_object_for_simulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::revive_object_for_simulation(IVP_Real_Object *this)
{
  if ( this->flags == 8 )
    IVP_Simulation_Unit::sim_unit_revive_for_simulation(
      this: this->friction_core->sim_unit_of_core,
      env: this->friction_core->environment);
}

//------------------------------------------------------------------------------
// Address: 0x1006F210
// Name: public: void IVP_Real_Object::recalc_core_radius(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall IVP_Real_Object::recalc_core_radius(IVP_Real_Object *this@<ecx>, int a2@<ebp>)
{
  __int32 v3; // eax
  IVP_SurfaceManager *surface_manager; // ecx
  float v5; // xmm0_4
  IVP_Core *physical_core; // eax
  IVP_Core *v7; // esi
  float v8[3]; // [esp-Ch] [ebp-2Ch] BYREF
  __int64 center_12; // [esp+Ch] [ebp-14h] OVERLAPPED BYREF
  int v10; // [esp+14h] [ebp-Ch]
  float rad_dev; // [esp+18h] [ebp-8h]
  float retaddr; // [esp+20h] [ebp+0h]

  v10 = a2;
  rad_dev = retaddr;
  v3 = this->object_type - 2;
  center_12 = 0;
  if ( v3 != 0 )
  {
    if ( v3 == 1 )
    {
      *(float *)&center_12 = IVP_U_Float_Point::fast_real_length(this: &this->shift_core_f_object);
      *((float *)&center_12 + 1) = *(float *)&center_12;
    }
    else
    {
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_object.cxx", 536);
    }
  }
  else
  {
    surface_manager = this->surface_manager;
    v8[0] = -this->shift_core_f_object.k[0];
    v8[1] = -this->shift_core_f_object.k[1];
    v8[2] = -this->shift_core_f_object.k[2];
    surface_manager->get_radius_and_radius_dev_to_given_center(
      this: surface_manager,
      a2: (const IVP_U_Float_Point *)v8,
      a3: (float *)&center_12 + 1,
      a4: (float *)&center_12);
  }
  v5 = this->extra_radius + *((float *)&center_12 + 1);
  physical_core = this->physical_core;
  *((float *)&center_12 + 1) = v5;
  if ( v5 > physical_core->upper_limit_radius )
    physical_core->upper_limit_radius = v5;
  v7 = this->physical_core;
  if ( *(float *)&center_12 > v7->max_surface_deviation )
    LODWORD(v7->max_surface_deviation) = center_12;
}

//------------------------------------------------------------------------------
// Address: 0x1006F300
// Name: public: void IVP_Real_Object::reset_time(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::reset_time(IVP_Real_Object *this, IVP_Time offset)
{
  IVP_Hull_Manager::reset_time(this: (IVP_Hull_Manager *)&this->hull_manager, offset);
}

//------------------------------------------------------------------------------
// Address: 0x1006F320
// Name: protected: void IVP_Real_Object::recalc_invalid_mindists_of_object(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::recalc_invalid_mindists_of_object(IVP_Real_Object *this)
{
  IVP_Real_Object *v1; // ebx
  IVP_Synapse_Real *invalid_synapses; // eax
  IVP_Synapse_Real *next; // edi
  IVP_Mindist *v4; // esi
  IVP_Mindist_Manager *mindist_manager; // ebx

  v1 = this;
  invalid_synapses = this->invalid_synapses;
  if ( invalid_synapses != nullptr )
  {
    do
    {
      next = (IVP_Synapse_Real *)invalid_synapses->next;
      v4 = (IVP_Mindist *)((char *)invalid_synapses + invalid_synapses->mindist_offset);
      IVP_Mindist::recalc_invalid_mindist(this: v4);
      if ( (*((_DWORD *)&v4->IVP_Mindist_Base + 5) & 0xC000) != 0x4000 )
      {
        mindist_manager = v1->environment->mindist_manager;
        IVP_Mindist_Manager::remove_invalid_mindist(this: mindist_manager, del_mindist: v4);
        IVP_Mindist_Manager::insert_exact_mindist(this: mindist_manager, new_mindist: v4);
        v1 = this;
      }
      invalid_synapses = next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F380
// Name: protected: void IVP_Real_Object::recalc_exact_mindists_of_object(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::recalc_exact_mindists_of_object(IVP_Real_Object *this)
{
  IVP_Mindist_Manager *mindist_manager; // edi
  IVP_Synapse_Real *exact_synapses; // eax
  IVP_Synapse_Real *next; // esi

  mindist_manager = this->environment->mindist_manager;
  exact_synapses = this->exact_synapses;
  if ( exact_synapses != nullptr )
  {
    do
    {
      next = (IVP_Synapse_Real *)exact_synapses->next;
      IVP_Mindist_Manager::recalc_exact_mindist(
        this: mindist_manager,
        mdist: (IVP_Mindist *)((char *)exact_synapses + exact_synapses->mindist_offset));
      exact_synapses = next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F3B0
// Name: protected: void IVP_Real_Object::get_all_near_mindists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::get_all_near_mindists(IVP_Real_Object *this)
{
  IVP_Core *physical_core; // eax
  char v3; // bl
  char temp_obj_movement; // [esp+8h] [ebp-4h]

  physical_core = this->physical_core;
  v3 = *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1);
  *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) = 33;
  LOBYTE(physical_core) = this->flags;
  *(_BYTE *)&this->flags = 33;
  temp_obj_movement = (char)physical_core;
  IVP_Mindist_Manager::recheck_ov_element(this: this->physical_core->environment->mindist_manager, object: this);
  *((_BYTE *)&this->physical_core->IVP_Core_Fast_Static + 1) = v3;
  *(_BYTE *)&this->flags = temp_obj_movement;
}

//------------------------------------------------------------------------------
// Address: 0x1006F400
// Name: public: void IVP_Real_Object::recheck_collision_filter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::recheck_collision_filter(IVP_Real_Object *this)
{
  if ( this->ov_element != nullptr )
    IVP_Mindist_Manager::recheck_ov_element(this: this->physical_core->environment->mindist_manager, object: this);
}

//------------------------------------------------------------------------------
// Address: 0x1006F420
// Name: public: void IVP_Real_Object::force_grow_friction_system(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::force_grow_friction_system(IVP_Real_Object *this)
{
  IVP_Core *physical_core; // eax
  char v3; // bl
  char v4; // [esp+8h] [ebp-4h]

  physical_core = this->physical_core;
  v3 = *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1);
  *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) = 33;
  LOBYTE(physical_core) = this->flags;
  *(_BYTE *)&this->flags = 33;
  v4 = (char)physical_core;
  IVP_Mindist_Manager::recheck_ov_element(this: this->physical_core->environment->mindist_manager, object: this);
  *((_BYTE *)&this->physical_core->IVP_Core_Fast_Static + 1) = v3;
  *(_BYTE *)&this->flags = v4;
  IVP_Core::grow_friction_system(this: this->physical_core);
}

//------------------------------------------------------------------------------
// Address: 0x1006F480
// Name: private: void IVP_Real_Object::unlink_contact_points(enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::unlink_contact_points(IVP_Real_Object *this, IVP_BOOL silent)
{
  IVP_Synapse_Friction *i; // eax
  int contact_point_offset; // esi
  IVP_Friction_System *v4; // edi
  IVP_Contact_Point *v5; // esi
  IVP_Core *friction_core; // ebx

  for ( i = this->friction_synapses; i != nullptr; i = this->friction_synapses )
  {
    contact_point_offset = i->contact_point_offset;
    v4 = *(IVP_Friction_System **)((char *)&i[7].prev + contact_point_offset);
    v5 = (IVP_Contact_Point *)((char *)i + contact_point_offset);
    friction_core = v5->synapse[1].l_obj->friction_core;
    if ( silent == IVP_FALSE )
    {
      IVP_Core::ensure_core_to_be_in_simulation(this: v5->synapse[0].l_obj->friction_core);
      IVP_Core::ensure_core_to_be_in_simulation(this: friction_core);
    }
    IVP_Friction_System::delete_friction_distance(this: v4, old_dist: v5);
    if ( v4->friction_dist_number == 0 )
      ((void (__thiscall *)(IVP_Friction_System *, int))v4->dtr_IVP_Controller)(a1: v4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F4F0
// Name: public: void IVP_Real_Object::unlink_contact_points_for_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::unlink_contact_points_for_object(IVP_Real_Object *this, IVP_Real_Object *pOtherObject)
{
  IVP_Synapse_Friction *friction_synapses; // esi
  int contact_point_offset; // eax
  IVP_Friction_System *v4; // edi
  IVP_Contact_Point *v5; // eax

  friction_synapses = this->friction_synapses;
  if ( friction_synapses != nullptr )
  {
    while ( 1 )
    {
      contact_point_offset = friction_synapses->contact_point_offset;
      v4 = *(IVP_Friction_System **)((char *)&friction_synapses[7].prev + contact_point_offset);
      v5 = (IVP_Contact_Point *)((char *)friction_synapses + contact_point_offset);
      friction_synapses = friction_synapses->next;
      if ( v5->synapse[0].l_obj == pOtherObject || v5->synapse[1].l_obj == pOtherObject )
        IVP_Friction_System::delete_friction_distance(this: v4, old_dist: v5);
      if ( v4->friction_dist_number == 0 )
        break;
      if ( friction_synapses == nullptr )
        return;
    }
    ((void (__thiscall *)(IVP_Friction_System *, int))v4->dtr_IVP_Controller)(a1: v4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F550
// Name: private: void IVP_Real_Object::clear_internal_references(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::clear_internal_references(IVP_Real_Object *this)
{
  IVP_Anchor *anchors; // esi
  IVP_Anchor *i; // ebx
  IVP_Synapse_Real *j; // eax
  char *v5; // ecx

  anchors = this->anchors;
  for ( i = nullptr; anchors != nullptr; anchors = this->anchors )
  {
    IVP_Anchor::object_is_going_to_be_deleted_event(this: anchors, obj: this);
    if ( anchors == i )
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_object.cxx", 786);
    i = anchors;
  }
  IVP_Real_Object::unlink_contact_points(this, silent: IVP_TRUE);
  for ( j = this->exact_synapses; j != nullptr; j = this->exact_synapses )
  {
    v5 = (char *)j + j->mindist_offset;
    if ( v5 != nullptr )
      (*(void (__thiscall **)(char *, int))(*(_DWORD *)v5 + 16))(a1: v5, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F5C0
// Name: public: void IVP_Real_Object::calc_m_core_f_object(class IVP_U_Matrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::calc_m_core_f_object(IVP_Real_Object *this, IVP_U_Matrix *m_core_f_object)
{
  IVP_U_Quat *q_core_f_object; // ecx
  float v4; // xmm0_4
  float v5; // xmm1_4

  IVP_U_Matrix::init(this: m_core_f_object);
  q_core_f_object = this->q_core_f_object;
  if ( q_core_f_object != nullptr )
    IVP_U_Quat::set_matrix(this: q_core_f_object, mat: m_core_f_object);
  else
    IVP_U_Matrix::init(this: m_core_f_object);
  v4 = this->shift_core_f_object.k[1];
  v5 = this->shift_core_f_object.k[2];
  m_core_f_object->vv.k[0] = this->shift_core_f_object.k[0];
  m_core_f_object->vv.k[1] = v4;
  m_core_f_object->vv.k[2] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1006F610
// Name: public: void IVP_Real_Object::calc_at_matrix(class IVP_Time,class IVP_U_Matrix __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Real_Object::calc_at_matrix(
        IVP_Real_Object *this@<ecx>,
        int a2@<ebp>,
        IVP_Time current_time,
        IVP_U_Matrix *m_world_f_object_out)
{
  IVP_Core *physical_core; // esi
  float t; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // esi
  float *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  float v18; // [esp+14h] [ebp-2Ch] BYREF
  float v19; // [esp+18h] [ebp-28h]
  float v20; // [esp+1Ch] [ebp-24h]
  IVP_U_Quat q_world_f_object; // [esp+20h] [ebp-20h]
  float v22; // [esp+30h] [ebp-10h]
  int v23; // [esp+34h] [ebp-Ch]
  void *v24; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  physical_core = this->physical_core;
  t = (float)(current_time.seconds - physical_core->time_of_last_psi.seconds) * physical_core->i_delta_time;
  v22 = *(float *)&this;
  IVP_U_Quat::set_interpolate_smoothly(
    this: (IVP_U_Quat *)&v18,
    a2: (int)physical_core,
    from: &physical_core->q_world_f_core_last_psi,
    to: &physical_core->q_world_f_core_next_psi,
    t);
  v6 = current_time.seconds - physical_core->time_of_last_psi.seconds;
  v7 = (float)(physical_core->delta_world_f_core_psis.k[1] * v6) + physical_core->pos_world_f_core_last_psi.k[1];
  v8 = (float)(physical_core->delta_world_f_core_psis.k[2] * v6) + physical_core->pos_world_f_core_last_psi.k[2];
  m_world_f_object_out->vv.k[0] = (float)(v6 * physical_core->delta_world_f_core_psis.k[0])
                                + physical_core->pos_world_f_core_last_psi.k[0];
  m_world_f_object_out->vv.k[1] = v7;
  m_world_f_object_out->vv.k[2] = v8;
  IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)&v18, mat: m_world_f_object_out);
  v9 = v22;
  if ( (*(_DWORD *)(LODWORD(v22) + 68) & 0x800) == 0 )
    IVP_U_Matrix::vmult4(
      this: m_world_f_object_out,
      p_in: (const IVP_U_Float_Point *)(LODWORD(v22) + 48),
      p_out: &m_world_f_object_out->vv);
  v10 = *(float **)(LODWORD(v9) + 44);
  if ( v10 != nullptr )
  {
    v11 = v10[1];
    v12 = v10[3];
    v13 = *v10;
    v14 = v10[2];
    v15 = (float)((float)((float)(v11 * q_world_f_object.x) + (float)(v12 * v19)) + (float)(*v10 * v20))
        - (float)(v14 * v18);
    v16 = (float)((float)((float)(v12 * v20) + (float)(v14 * q_world_f_object.x)) + (float)(v11 * v18))
        - (float)(*v10 * v19);
    v22 = (float)((float)(v12 * q_world_f_object.x) - (float)(*v10 * v18)) - (float)(v11 * v19);
    v17 = v22 - (float)(v14 * v20);
    v18 = (float)((float)((float)(v12 * v18) + (float)(v13 * q_world_f_object.x)) + (float)(v14 * v19))
        - (float)(v11 * v20);
    v19 = v15;
    v20 = v16;
    q_world_f_object.x = v17;
    IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)&v18, mat: m_world_f_object_out);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F7F0
// Name: public: void IVP_Real_Object::convert_to_phantom(class IVP_Template_Phantom const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::convert_to_phantom(IVP_Real_Object *this, const IVP_Template_Phantom *tmpl)
{
  IVP_Controller_Phantom *controller_phantom; // ecx
  IVP_Controller_Phantom *v4; // eax

  controller_phantom = this->controller_phantom;
  if ( controller_phantom != nullptr )
    ((void (__thiscall *)(IVP_Controller_Phantom *, int))controller_phantom->dtr_IVP_Listener_Object)(
      a1: controller_phantom,
      a2: 1);
  this->controller_phantom = nullptr;
  v4 = (IVP_Controller_Phantom *)p_malloc(size: 0x50u);
  if ( v4 != nullptr )
    this->controller_phantom = IVP_Controller_Phantom::IVP_Controller_Phantom(this: v4, object_in: this, templat: tmpl);
  else
    this->controller_phantom = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006F840
// Name: public: void IVP_Real_Object::ensure_in_simulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::ensure_in_simulation(IVP_Real_Object *this)
{
  if ( this->flags == 8 )
    IVP_Environment::add_revive_core(this: this->environment, c: this->friction_core);
  else
    IVP_Core::reset_freeze_check_values(this: this->physical_core);
}

//------------------------------------------------------------------------------
// Address: 0x1006F870
// Name: public: void IVP_Real_Object::enable_collision_detection(enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::enable_collision_detection(IVP_Real_Object *this, IVP_BOOL enable)
{
  IVP_OV_Element *ov_element; // ecx

  if ( enable != IVP_FALSE )
  {
    if ( (*(_DWORD *)&this->flags & 0x100) == 0 )
    {
      IVP_Mindist_Manager::enable_collision_detection_for_object(this: this->environment->mindist_manager, object: this);
      *(_DWORD *)&this->flags |= 0x100u;
    }
  }
  else if ( (*(_DWORD *)&this->flags & 0x100) != 0 )
  {
    ov_element = this->ov_element;
    if ( ov_element != nullptr )
      ((void (__thiscall *)(IVP_OV_Element *, int))ov_element->dtr_IVP_OV_Element)(a1: ov_element, a2: 1);
    *(_DWORD *)&this->flags &= ~0x100u;
    this->ov_element = nullptr;
    IVP_Real_Object::unlink_contact_points(this, silent: IVP_TRUE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F8E0
// Name: public: void IVP_Real_Object::ensure_in_simulation_now(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::ensure_in_simulation_now(IVP_Real_Object *this)
{
  if ( *((_BYTE *)&this->physical_core->IVP_Core_Fast_Static + 1) == 8 && this->flags == 8 )
    IVP_Simulation_Unit::sim_unit_revive_for_simulation(
      this: this->friction_core->sim_unit_of_core,
      env: this->friction_core->environment);
}

//------------------------------------------------------------------------------
// Address: 0x1006F910
// Name: protected: virtual void IVP_Real_Object::set_new_quat_object_f_core(class IVP_U_Quat const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Real_Object::set_new_quat_object_f_core(
        IVP_Real_Object *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        IVP_U_Quat *new_quat_object_f_core,
        const IVP_U_Point *trans_object_f_core)
{
  void (__thiscall *set_new_m_object_f_core)(IVP_Real_Object *, const IVP_U_Matrix *); // edx
  _BYTE v8[12]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Matrix m; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  m.vv.k[1] = a2;
  m.vv.k[2] = retaddr;
  IVP_U_Quat::set_matrix(this: new_quat_object_f_core, mat: (IVP_U_Matrix3 *)v8);
  set_new_m_object_f_core = this->set_new_m_object_f_core;
  m.rows[2].k[1] = trans_object_f_core->k[0];
  m.rows[2].k[2] = trans_object_f_core->k[1];
  m.rows[2].hesse_val = trans_object_f_core->k[2];
  ((void (__thiscall *)(IVP_Real_Object *, _BYTE *, int))set_new_m_object_f_core)(a1: this, a2: v8, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1006F970
// Name: public: static void IVP_Real_Object::disable_simulation_list(class IVP_Environment __near *,class IVP_Real_Object __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Real_Object::disable_simulation_list(
        IVP_Environment *pEnvironment,
        IVP_Real_Object **pList,
        int listCount)
{
  int seconds_low; // ecx
  int v4; // eax
  int v5; // ebx
  IVP_Real_Object *v6; // edx
  IVP_Core *physical_core; // esi
  int v8; // edi
  long double seconds; // kr00_8
  int v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  IVP_Simulation_Unit *sim_unit_of_core; // esi
  int j; // esi
  IVP_Simulation_Unit *v15; // edi
  IVP_Simulation_Unit *pSimunitList[256]; // [esp+4h] [ebp-410h]
  IVP_Time ref_time; // [esp+404h] [ebp-10h]
  double i; // [esp+40Ch] [ebp-8h]

  seconds_low = LODWORD(pEnvironment->current_time.seconds);
  HIDWORD(i) = HIDWORD(pEnvironment->current_time.seconds);
  LODWORD(i) = seconds_low;
  v4 = 0;
  v5 = 0;
  ref_time.seconds = (float)(i - 20.0);
  for ( HIDWORD(i) = 0; v4 < listCount; HIDWORD(i) = v4 )
  {
    v6 = pList[v4];
    physical_core = v6->physical_core;
    if ( (*(_WORD *)&physical_core->IVP_Core_Fast_Static & 2) == 0 )
    {
      if ( (*(_WORD *)&physical_core->IVP_Core_Fast_Static & 4) != 0 )
        IVP_Environment::remove_revive_core(this: physical_core->environment, c: v6->physical_core);
      if ( *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) < 8u )
      {
        v8 = physical_core->objects.n_elems - 1;
        if ( physical_core->objects.n_elems != 0 )
        {
          do
            IVP_Real_Object::unlink_contact_points(
              this: (IVP_Real_Object *)physical_core->objects.elems[v8--],
              silent: IVP_TRUE);
          while ( v8 >= 0 );
        }
        seconds = ref_time.seconds;
        physical_core->q_world_f_core_calm_reference[0].x = physical_core->q_world_f_core_next_psi.x;
        v10 = 0;
        physical_core->q_world_f_core_calm_reference[0].y = physical_core->q_world_f_core_next_psi.y;
        physical_core->q_world_f_core_calm_reference[0].z = physical_core->q_world_f_core_next_psi.z;
        physical_core->q_world_f_core_calm_reference[0].w = physical_core->q_world_f_core_next_psi.w;
        v11 = physical_core->pos_world_f_core_last_psi.k[1];
        v12 = physical_core->pos_world_f_core_last_psi.k[2];
        physical_core->position_world_f_core_calm_reference[0].k[0] = physical_core->pos_world_f_core_last_psi.k[0];
        physical_core->position_world_f_core_calm_reference[0].k[1] = v11;
        physical_core->position_world_f_core_calm_reference[0].k[2] = v12;
        physical_core->time_of_calm_reference[0].seconds = seconds;
        sim_unit_of_core = physical_core->sim_unit_of_core;
        if ( v5 <= 0 )
        {
LABEL_11:
          if ( v5 >= 256 )
          {
            IVP_Simulation_Unit::do_sim_unit_union_find(this: sim_unit_of_core);
            IVP_Simulation_Unit::sim_unit_calc_movement_state(this: sim_unit_of_core, env: pEnvironment);
          }
          else
          {
            pSimunitList[v5++] = sim_unit_of_core;
          }
        }
        else
        {
          while ( pSimunitList[v10] != sim_unit_of_core )
          {
            if ( ++v10 >= v5 )
              goto LABEL_11;
          }
        }
      }
    }
    v4 = HIDWORD(i) + 1;
  }
  for ( j = 0; j < v5; ++j )
  {
    v15 = pSimunitList[j];
    IVP_Simulation_Unit::do_sim_unit_union_find(this: v15);
    IVP_Simulation_Unit::sim_unit_calc_movement_state(this: v15, env: pEnvironment);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006FB00
// Name: public: enum IVP_BOOL IVP_Real_Object::disable_simulation(void)
// Source: json
//------------------------------------------------------------------------------
IVP_BOOL __thiscall IVP_Real_Object::disable_simulation(IVP_Real_Object *this)
{
  IVP_Core *physical_core; // esi
  int v2; // edi
  double v3; // st7
  float v4; // xmm1_4
  IVP_Simulation_Unit *sim_unit_of_core; // ecx
  double now_time; // [esp+4h] [ebp-8h]

  physical_core = this->physical_core;
  if ( (*(_WORD *)&physical_core->IVP_Core_Fast_Static & 2) != 0 )
    return IVP_TRUE;
  if ( (*(_WORD *)&physical_core->IVP_Core_Fast_Static & 4) != 0 )
    IVP_Environment::remove_revive_core(this: physical_core->environment, c: physical_core);
  if ( *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) >= 8u )
    return IVP_TRUE;
  v2 = physical_core->objects.n_elems - 1;
  if ( physical_core->objects.n_elems != 0 )
  {
    do
      IVP_Real_Object::unlink_contact_points(
        this: (IVP_Real_Object *)physical_core->objects.elems[v2--],
        silent: IVP_TRUE);
    while ( v2 >= 0 );
  }
  physical_core->q_world_f_core_calm_reference[0].x = physical_core->q_world_f_core_next_psi.x;
  physical_core->q_world_f_core_calm_reference[0].y = physical_core->q_world_f_core_next_psi.y;
  physical_core->q_world_f_core_calm_reference[0].z = physical_core->q_world_f_core_next_psi.z;
  physical_core->q_world_f_core_calm_reference[0].w = physical_core->q_world_f_core_next_psi.w;
  v3 = physical_core->pos_world_f_core_last_psi.k[0];
  v4 = physical_core->pos_world_f_core_last_psi.k[2];
  physical_core->position_world_f_core_calm_reference[0].k[1] = physical_core->pos_world_f_core_last_psi.k[1];
  physical_core->position_world_f_core_calm_reference[0].k[0] = v3;
  physical_core->position_world_f_core_calm_reference[0].k[2] = v4;
  now_time = (float)(physical_core->environment->current_time.seconds - 20.0);
  HIDWORD(physical_core->time_of_calm_reference[0].seconds) = HIDWORD(now_time);
  sim_unit_of_core = physical_core->sim_unit_of_core;
  LODWORD(physical_core->time_of_calm_reference[0].seconds) = LODWORD(now_time);
  IVP_Simulation_Unit::do_sim_unit_union_find(this: sim_unit_of_core);
  return IVP_Simulation_Unit::sim_unit_calc_movement_state(
           this: physical_core->sim_unit_of_core,
           env: physical_core->environment);
}

//------------------------------------------------------------------------------
// Address: 0x1006FC10
// Name: public: void IVP_Real_Object::set_extra_radius(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Real_Object::set_extra_radius(IVP_Real_Object *this@<ecx>, int a2@<ebp>, float new_radius)
{
  bool v4; // cc
  IVP_Core *physical_core; // edx
  bool v6; // sf
  int v7; // eax
  void *v8; // esi
  int v9; // eax
  int v10; // ecx
  float v11; // xmm0_4
  int v12; // eax
  int v13; // esi
  float v14[5]; // [esp-20h] [ebp-2Ch] BYREF
  int v15; // [esp-Ch] [ebp-18h]
  float v16; // [esp-8h] [ebp-14h] BYREF
  float v17; // [esp-4h] [ebp-10h] BYREF
  int i; // [esp+0h] [ebp-Ch] BYREF
  void *v19; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  i = a2;
  v19 = retaddr;
  v4 = new_radius <= this->extra_radius;
  this->extra_radius = new_radius;
  if ( v4 )
  {
    this->physical_core->upper_limit_radius = 0.0;
    this->physical_core->max_surface_deviation = 0.0;
    physical_core = this->physical_core;
    v7 = physical_core->objects.n_elems - 1;
    v6 = physical_core->objects.n_elems == 0;
    v15 = v7;
    if ( !v6 )
    {
      while ( 1 )
      {
        v8 = this->physical_core->objects.elems[v7];
        v9 = *((_DWORD *)v8 + 1) - 2;
        v17 = 0.0;
        v16 = 0.0;
        if ( v9 != 0 )
        {
          if ( v9 == 1 )
          {
            v16 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)v8 + 3);
            v17 = v16;
          }
          else
          {
            _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_object.cxx", 536);
          }
        }
        else
        {
          v10 = *((_DWORD *)v8 + 33);
          v14[0] = -*((float *)v8 + 12);
          v14[1] = -*((float *)v8 + 13);
          v14[2] = -*((float *)v8 + 14);
          (*(void (__thiscall **)(int, float *, float *, float *))(*(_DWORD *)v10 + 8))(
            a1: v10,
            a2: v14,
            a3: &v17,
            a4: &v16);
        }
        v11 = *((float *)v8 + 36) + v17;
        v12 = *((_DWORD *)v8 + 37);
        v17 = v11;
        if ( v11 > *(float *)(v12 + 4) )
          *(float *)(v12 + 4) = v11;
        v13 = *((_DWORD *)v8 + 37);
        if ( v16 > *(float *)(v13 + 8) )
          *(float *)(v13 + 8) = v16;
        if ( --v15 < 0 )
          break;
        v7 = v15;
      }
    }
  }
  else
  {
    IVP_Real_Object::recalc_core_radius(this, a2: (int)&i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006FD70
// Name: protected: void IVP_Real_Object::revive_nearest_objects_grow_fs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::revive_nearest_objects_grow_fs(IVP_Real_Object *this)
{
  IVP_Core *physical_core; // ecx
  char v3; // bl
  char flags; // cl
  IVP_Core *v5; // edx
  IVP_Core *v6; // ecx
  char v7; // [esp+4h] [ebp-4h]

  physical_core = this->physical_core;
  if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) != 0 )
  {
    v3 = *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1);
    *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) = 33;
    flags = (char)this->flags;
    v5 = this->physical_core;
    *(_BYTE *)&this->flags = 33;
    v7 = flags;
    IVP_Mindist_Manager::recheck_ov_element(this: v5->environment->mindist_manager, object: this);
    *((_BYTE *)&this->physical_core->IVP_Core_Fast_Static + 1) = v3;
    v6 = this->physical_core;
    *(_BYTE *)&this->flags = v7;
    IVP_Core::grow_friction_system(this: v6);
    IVP_Core::revive_adjacent_to_unmoveable(this: this->physical_core);
  }
  else
  {
    IVP_Core::ensure_core_to_be_in_simulation(this: physical_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006FDE0
// Name: public: void IVP_Real_Object::get_m_world_f_object_AT(class IVP_U_Matrix __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::get_m_world_f_object_AT(IVP_Real_Object *this, IVP_U_Matrix *m_world_f_object_out)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  IVP_Real_Object::calc_at_matrix(
    this,
    a2: (int)&savedregs,
    current_time: this->environment->current_time,
    m_world_f_object_out);
}

//------------------------------------------------------------------------------
// Address: 0x1006FE10
// Name: protected: IVP_Cluster::IVP_Cluster(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Cluster *__thiscall IVP_Cluster::IVP_Cluster(IVP_Cluster *this, IVP_Environment *env)
{
  this->father_cluster = nullptr;
  this->prev_in_cluster = nullptr;
  this->next_in_cluster = nullptr;
  this->environment = env;
  this->name = nullptr;
  this->__vftable = (IVP_Cluster_vtbl *)&IVP_Cluster::`vftable';
  this->objects = nullptr;
  this->object_type = IVP_CLUSTER;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006FE40
// Name: public: virtual IVP_Cluster::~IVP_Cluster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster::~IVP_Cluster(IVP_Cluster *this)
{
  bool v2; // zf
  IVP_Object *objects; // ecx
  IVP_Cluster *father_cluster; // ecx
  IVP_Object *prev_in_cluster; // eax
  IVP_Object *next_in_cluster; // eax

  v2 = this->objects == nullptr;
  this->__vftable = (IVP_Cluster_vtbl *)&IVP_Cluster::`vftable';
  if ( !v2 )
  {
    do
    {
      objects = this->objects;
      if ( objects != nullptr )
        ((void (__thiscall *)(IVP_Object *, int))objects->dtr_IVP_Object)(a1: objects, a2: 1);
    }
    while ( this->objects != nullptr );
  }
  father_cluster = this->father_cluster;
  this->__vftable = (IVP_Cluster_vtbl *)&IVP_Object::`vftable';
  if ( father_cluster != nullptr )
  {
    prev_in_cluster = this->prev_in_cluster;
    if ( prev_in_cluster != nullptr )
      prev_in_cluster->next_in_cluster = this->next_in_cluster;
    else
      father_cluster->objects = this->next_in_cluster;
    next_in_cluster = this->next_in_cluster;
    if ( next_in_cluster != nullptr )
      next_in_cluster->prev_in_cluster = this->prev_in_cluster;
  }
  if ( this->name != nullptr )
  {
    free(data: (void *)this->name);
    this->name = nullptr;
  }
  this->environment = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006FEC0
// Name: public: void IVP_Real_Object::calc_at_quaternion(class IVP_Time,class IVP_U_Quat __near *,class IVP_U_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Real_Object::calc_at_quaternion(
        IVP_Real_Object *this@<ecx>,
        int a2@<ebp>,
        IVP_Time current_time,
        IVP_U_Quat *q_world_f_object_out,
        IVP_U_Point *position_out)
{
  IVP_Core *physical_core; // esi
  float t; // xmm0_4
  IVP_Real_Object *v7; // edx
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float *p_x; // eax
  float z; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  _BYTE v17[12]; // [esp+14h] [ebp-5Ch] BYREF
  IVP_U_Matrix m_world_f_object; // [esp+20h] [ebp-50h]
  IVP_Real_Object *v19; // [esp+60h] [ebp-10h]
  int v20; // [esp+64h] [ebp-Ch]
  void *v21; // [esp+68h] [ebp-8h]
  void *retaddr; // [esp+70h] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  physical_core = this->physical_core;
  t = (float)(current_time.seconds - physical_core->time_of_last_psi.seconds) * physical_core->i_delta_time;
  v19 = this;
  IVP_U_Quat::set_interpolate_smoothly(
    this: q_world_f_object_out,
    a2: (int)physical_core,
    from: &physical_core->q_world_f_core_last_psi,
    to: &physical_core->q_world_f_core_next_psi,
    t);
  v7 = v19;
  v8 = current_time.seconds - physical_core->time_of_last_psi.seconds;
  v9 = (float)(physical_core->delta_world_f_core_psis.k[1] * v8) + physical_core->pos_world_f_core_last_psi.k[1];
  v10 = (float)(physical_core->delta_world_f_core_psis.k[2] * v8) + physical_core->pos_world_f_core_last_psi.k[2];
  position_out->k[0] = (float)(physical_core->delta_world_f_core_psis.k[0] * v8)
                     + physical_core->pos_world_f_core_last_psi.k[0];
  position_out->k[1] = v9;
  position_out->k[2] = v10;
  if ( (*(_DWORD *)&v7->flags & 0x800) == 0 )
  {
    IVP_U_Quat::set_matrix(this: q_world_f_object_out, mat: (IVP_U_Matrix3 *)v17);
    m_world_f_object.rows[2].k[1] = position_out->k[0];
    m_world_f_object.rows[2].k[2] = position_out->k[1];
    m_world_f_object.rows[2].hesse_val = position_out->k[2];
    IVP_U_Matrix::vmult4(this: (IVP_U_Matrix *)v17, p_in: &v19->shift_core_f_object, p_out: position_out);
  }
  p_x = &v19->q_core_f_object->x;
  if ( p_x != nullptr )
  {
    z = q_world_f_object_out->z;
    v13 = p_x[2];
    v14 = (float)((float)((float)(q_world_f_object_out->y * p_x[3]) + (float)(q_world_f_object_out->w * p_x[1]))
                + (float)(*p_x * z))
        - (float)(q_world_f_object_out->x * v13);
    v15 = (float)((float)((float)(z * p_x[3]) + (float)(v13 * q_world_f_object_out->w))
                + (float)(q_world_f_object_out->x * p_x[1]))
        - (float)(*p_x * q_world_f_object_out->y);
    v16 = (float)((float)(p_x[3] * q_world_f_object_out->w) - (float)(q_world_f_object_out->x * *p_x))
        - (float)(q_world_f_object_out->y * p_x[1]);
    q_world_f_object_out->x = (float)((float)((float)(q_world_f_object_out->x * p_x[3])
                                            + (float)(*p_x * q_world_f_object_out->w))
                                    + (float)(v13 * q_world_f_object_out->y))
                            - (float)(z * p_x[1]);
    q_world_f_object_out->y = v14;
    q_world_f_object_out->z = v15;
    q_world_f_object_out->w = v16 - (float)(v13 * z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100700B0
// Name: public: void IVP_Real_Object::init_object_core(class IVP_Environment __near *,class IVP_Template_Real_Object const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge IVP_Real_Object::init_object_core(
        IVP_Real_Object *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Environment *i_environment,
        const IVP_Template_Real_Object *templ)
{
  IVP_U_Matrix *mass_center_override; // eax
  IVP_Environment *v8; // xmm0_4
  IVP_Simulation_Unit *v9; // xmm1_4
  void (__thiscall *set_new_m_object_f_core)(IVP_Real_Object *, const IVP_U_Matrix *); // edx
  IVP_Core *physical_core; // esi
  IVP_SurfaceManager *surface_manager; // ecx
  void (__thiscall *get_radius_and_radius_dev_to_given_center)(IVP_SurfaceManager *, const IVP_U_Float_Point *, float *, float *); // eax
  const IVP_Template_Real_Object *v14; // edx
  IVP_U_Float_Point *p_rot_inertia; // ecx
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  double v21; // st7
  float hesse_val; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // edx
  float v26; // xmm0_4
  int v28; // [esp+2Ch] [ebp-DCh] BYREF
  IVP_U_Matrix m_core_f_object; // [esp+38h] [ebp-D0h] BYREF
  _BYTE m_object_f_core_36[44]; // [esp+9Ch] [ebp-6Ch] OVERLAPPED BYREF
  IVP_Event_Sim v31; // [esp+C8h] [ebp-40h] BYREF
  IVP_U_Float_Point center_4; // [esp+DCh] [ebp-2Ch] OVERLAPPED BYREF
  float upper_limit; // [esp+F0h] [ebp-18h]
  float min_inertia_value[2]; // [esp+F4h] [ebp-14h] OVERLAPPED BYREF
  float mass; // [esp+FCh] [ebp-Ch]
  float rad_dev; // [esp+100h] [ebp-8h]
  float retaddr; // [esp+108h] [ebp+0h]

  mass = a2;
  rad_dev = retaddr;
  LODWORD(center_4.hesse_val) = this->object_type;
  mass_center_override = templ->mass_center_override;
  memset(&m_object_f_core_36[16], 0, 16);
  if ( mass_center_override != nullptr )
  {
    v8 = (IVP_Environment *)LODWORD(mass_center_override->vv.k[1]);
    v9 = (IVP_Simulation_Unit *)LODWORD(mass_center_override->vv.k[2]);
    v31.i_delta_time = mass_center_override->vv.k[0];
    v31.environment = v8;
    v31.sim_unit = v9;
  }
  else
  {
    this->surface_manager->get_mass_center(this: this->surface_manager, a2: (IVP_U_Float_Point *)&v31.i_delta_time);
  }
  IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)&m_object_f_core_36[16], mat: (IVP_U_Matrix *)&m_core_f_object.vv.k[1]);
  set_new_m_object_f_core = this->set_new_m_object_f_core;
  *(float *)m_object_f_core_36 = v31.i_delta_time;
  *(_DWORD *)&m_object_f_core_36[4] = v31.environment;
  *(_DWORD *)&m_object_f_core_36[8] = v31.sim_unit;
  ((void (__thiscall *)(IVP_Real_Object *, float *, int, int))set_new_m_object_f_core)(
    a1: this,
    a2: &m_core_f_object.vv.k[1],
    a3,
    a4);
  physical_core = this->physical_core;
  *(_QWORD *)min_inertia_value = 0;
  if ( LODWORD(center_4.hesse_val) == 2 )
  {
    surface_manager = this->surface_manager;
    get_radius_and_radius_dev_to_given_center = surface_manager->get_radius_and_radius_dev_to_given_center;
    LODWORD(min_inertia_value[0]) = min_inertia_value;
    ((void (__thiscall *)(IVP_SurfaceManager *, float *, float *))get_radius_and_radius_dev_to_given_center)(
      a1: surface_manager,
      a2: &v31.i_delta_time,
      a3: &min_inertia_value[1]);
  }
  else if ( LODWORD(center_4.hesse_val) == 3 )
  {
    *(_QWORD *)min_inertia_value = 0;
  }
  else
  {
    _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_object.cxx", 966);
  }
  min_inertia_value[1] = this->extra_radius + min_inertia_value[1];
  IVP_Core::set_radius(this: physical_core, upper_limit: min_inertia_value[1], max_dev: min_inertia_value[0]);
  v14 = templ;
  upper_limit = templ->mass;
  if ( upper_limit < 0.003 )
    upper_limit = 1.0;
  p_rot_inertia = &physical_core->rot_inertia;
  if ( templ->rot_inertia_is_factor != IVP_FALSE )
  {
    if ( LODWORD(center_4.hesse_val) == 2 )
    {
      this->surface_manager->get_rotation_inertia(this: this->surface_manager, a2: &center_4);
    }
    else
    {
      if ( LODWORD(center_4.hesse_val) == 3 )
      {
        center_4.k[0] = (float)(min_inertia_value[1] * 0.40000001) * min_inertia_value[1];
        center_4.k[1] = center_4.k[0];
        center_4.k[2] = center_4.k[0];
LABEL_18:
        v16 = v14->rot_inertia.k[1] * center_4.k[1];
        v17 = v14->rot_inertia.k[2] * center_4.k[2];
        v18 = upper_limit;
        p_rot_inertia = &physical_core->rot_inertia;
        physical_core->rot_inertia.k[0] = (float)(v14->rot_inertia.k[0] * center_4.k[0]) * upper_limit;
        v19 = v16 * v18;
        v20 = v17 * v18;
        goto LABEL_20;
      }
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_object.cxx", 991);
    }
    v14 = templ;
    goto LABEL_18;
  }
  v19 = templ->rot_inertia.k[1];
  v20 = templ->rot_inertia.k[2];
  p_rot_inertia->k[0] = templ->rot_inertia.k[0];
LABEL_20:
  p_rot_inertia->k[2] = v20;
  p_rot_inertia->k[1] = v19;
  if ( v14->auto_check_rot_inertia != 0.0 )
  {
    v21 = IVP_U_Float_Point::fast_real_length(this: p_rot_inertia) * templ->auto_check_rot_inertia;
    center_4.hesse_val = v21;
    hesse_val = center_4.hesse_val;
    if ( v21 > physical_core->rot_inertia.k[0] )
      physical_core->rot_inertia.k[0] = center_4.hesse_val;
    if ( hesse_val > physical_core->rot_inertia.k[1] )
      physical_core->rot_inertia.k[1] = hesse_val;
    v14 = templ;
    if ( hesse_val > physical_core->rot_inertia.k[2] )
      physical_core->rot_inertia.k[2] = hesse_val;
  }
  physical_core->rot_inertia.hesse_val = upper_limit;
  physical_core->speed_damp_factor = v14->speed_damp_factor;
  v23 = v14->rot_speed_damp_factor.k[1];
  v24 = v14->rot_speed_damp_factor.k[2];
  physical_core->rot_speed_damp_factor.k[0] = v14->rot_speed_damp_factor.k[0];
  LODWORD(min_inertia_value[0]) = &m_core_f_object.vv.k[1];
  physical_core->rot_speed_damp_factor.k[1] = v23;
  physical_core->rot_speed_damp_factor.k[2] = v24;
  IVP_U_Matrix::set_transpose(this: (IVP_U_Matrix *)&v28, in: (const IVP_U_Matrix *)LODWORD(min_inertia_value[0]));
  *(_QWORD *)&physical_core->rot_speed.k[1] = 0;
  physical_core->rot_speed.k[0] = 0.0;
  *(_QWORD *)&physical_core->speed.k[1] = 0;
  physical_core->speed.k[0] = 0.0;
  IVP_Core::calc_calc(this: physical_core);
  IVP_Core::transform_PSI_matrizes_core(this: physical_core, m_core_f_core: (IVP_U_Matrix *)&m_core_f_object.vv.k[1]);
  v25 = *((float *)&i_environment->time_of_next_psi.seconds + 1);
  center_4.k[2] = *(float *)&i_environment->time_of_next_psi.seconds;
  center_4.hesse_val = v25;
  v26 = *(double *)&center_4.k[2] - i_environment->current_time.seconds;
  *(_DWORD *)&m_object_f_core_36[40] = i_environment;
  *(float *)&m_object_f_core_36[32] = v26;
  if ( v26 <= 1.0e-10 )
    *(_DWORD *)&m_object_f_core_36[36] = 1343554297;
  else
    *(float *)&m_object_f_core_36[36] = 1.0 / v26;
  IVP_Core::calc_next_PSI_matrix_zero_speed(this: physical_core, es: (IVP_Event_Sim *)&m_object_f_core_36[32]);
}

//------------------------------------------------------------------------------
// Address: 0x10070420
// Name: public: int IVP_Real_Object::get_collision_check_reference_count(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Real_Object::get_collision_check_reference_count(IVP_Real_Object *this)
{
  IVP_OV_Element *ov_element; // eax

  ov_element = this->ov_element;
  if ( ov_element != nullptr )
    return ov_element->collision_fvector.n_elems;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10070440
// Name: public: void IVP_Real_Object::beam_object_to_new_position(class IVP_U_Quat const __near *,class IVP_U_Point const __near *,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_Real_Object::beam_object_to_new_position(
        IVP_Real_Object *this@<ecx>,
        int a2@<ebp>,
        IVP_U_Quat *rotation_world_f_object,
        const IVP_U_Point *position_w_f_o,
        IVP_BOOL optimize_for_repeated_calls)
{
  bool v6; // zf
  const IVP_U_Quat *v7; // ecx
  IVP_Core *physical_core; // eax
  float v9; // xmm1_4
  IVP_U_Quat *q_core_f_object; // esi
  _BYTE v11[12]; // [esp-Ch] [ebp-8Ch] BYREF
  _BYTE m_world_f_object_36[60]; // [esp+24h] [ebp-5Ch] OVERLAPPED BYREF
  IVP_Core *v13; // [esp+70h] [ebp-10h]
  int v14; // [esp+74h] [ebp-Ch]
  void *v15; // [esp+78h] [ebp-8h]
  void *retaddr; // [esp+80h] [ebp+0h]

  v14 = a2;
  v15 = retaddr;
  v6 = (*(_DWORD *)&this->flags & 0x800) == 0;
  v7 = rotation_world_f_object;
  physical_core = this->physical_core;
  *(IVP_U_Quat *)&m_world_f_object_36[16] = *rotation_world_f_object;
  *(_QWORD *)&m_world_f_object_36[32] = *(_QWORD *)position_w_f_o->k;
  v13 = physical_core;
  *(_QWORD *)&m_world_f_object_36[40] = *(_QWORD *)&position_w_f_o->k[2];
  if ( v6 )
  {
    IVP_U_Quat::set_matrix(this: rotation_world_f_object, mat: (IVP_U_Matrix3 *)v11);
    v9 = this->shift_core_f_object.k[0];
    *(float *)m_world_f_object_36 = position_w_f_o->k[0];
    *(float *)&m_world_f_object_36[4] = position_w_f_o->k[1];
    *(float *)&m_world_f_object_36[8] = position_w_f_o->k[2];
    *(float *)&m_world_f_object_36[48] = -v9;
    *(float *)&m_world_f_object_36[52] = -this->shift_core_f_object.k[1];
    *(float *)&m_world_f_object_36[56] = -this->shift_core_f_object.k[2];
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)v11,
      p_in: (const IVP_U_Float_Point *)&m_world_f_object_36[48],
      p_out: (IVP_U_Float_Point *)&m_world_f_object_36[32]);
    v7 = rotation_world_f_object;
  }
  q_core_f_object = this->q_core_f_object;
  if ( q_core_f_object != nullptr )
    IVP_U_Quat::set_div_unit_quat(this: (IVP_U_Quat *)&m_world_f_object_36[16], q1: v7, q2: q_core_f_object);
  IVP_Calc_Next_PSI_Solver::set_transformation(
    core: v13,
    rotation: (const IVP_U_Quat *)&m_world_f_object_36[16],
    position: (const IVP_U_Point *)&m_world_f_object_36[32],
    optimize_for_repeated_calls);
}

//------------------------------------------------------------------------------
// Address: 0x10070540
// Name: public: void IVP_Real_Object::async_add_speed_object_ws(class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::async_add_speed_object_ws(IVP_Real_Object *this, const IVP_U_Float_Point *speed_vec)
{
  IVP_Core *physical_core; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4

  if ( this->flags == 8 )
    IVP_Environment::add_revive_core(this: this->environment, c: this->friction_core);
  else
    IVP_Core::reset_freeze_check_values(this: this->physical_core);
  physical_core = this->physical_core;
  v4 = speed_vec->k[1] + physical_core->speed_change.k[1];
  v5 = speed_vec->k[2] + physical_core->speed_change.k[2];
  physical_core->speed_change.k[0] = physical_core->speed_change.k[0] + speed_vec->k[0];
  physical_core->speed_change.k[1] = v4;
  physical_core->speed_change.k[2] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100705C0
// Name: public: void IVP_Real_Object::async_add_rot_speed_object_cs(class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::async_add_rot_speed_object_cs(
        IVP_Real_Object *this,
        const IVP_U_Float_Point *rotation_vec)
{
  IVP_Core *physical_core; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4

  if ( this->flags == 8 )
    IVP_Environment::add_revive_core(this: this->environment, c: this->friction_core);
  else
    IVP_Core::reset_freeze_check_values(this: this->physical_core);
  physical_core = this->physical_core;
  v4 = rotation_vec->k[1] + physical_core->rot_speed_change.k[1];
  v5 = rotation_vec->k[2] + physical_core->rot_speed_change.k[2];
  physical_core->rot_speed_change.k[0] = physical_core->rot_speed_change.k[0] + rotation_vec->k[0];
  physical_core->rot_speed_change.k[1] = v4;
  physical_core->rot_speed_change.k[2] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10070640
// Name: public: void IVP_Real_Object::async_push_object_ws(class IVP_U_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Real_Object::async_push_object_ws(
        IVP_Real_Object *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Point *position_ws_,
        const IVP_U_Float_Point *impulse_ws_)
{
  IVP_Core *physical_core; // edi
  _BYTE v6[12]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Matrix m_world_f_core; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Float_Point position_cs; // [esp+40h] [ebp-20h] BYREF
  IVP_U_Float_Point impulse_cs; // [esp+50h] [ebp-10h]
  float retaddr; // [esp+60h] [ebp+0h]

  impulse_cs.k[1] = a2;
  impulse_cs.k[2] = retaddr;
  if ( this->flags == 8 )
    IVP_Environment::add_revive_core(this: this->environment, c: this->friction_core);
  else
    IVP_Core::reset_freeze_check_values(this: this->physical_core);
  physical_core = this->physical_core;
  IVP_Core::calc_at_matrix(
    this: physical_core,
    current_time: this->environment->current_time,
    m_world_f_core_out: (IVP_U_Matrix *)v6);
  IVP_U_Matrix::vimult4(
    this: (IVP_U_Matrix *)v6,
    p_in: position_ws_,
    p_out: (IVP_U_Float_Point *)&m_world_f_core.vv.k[1]);
  IVP_U_Matrix3::vimult3(this: (IVP_U_Matrix3 *)v6, p_in: impulse_ws_, p_out: (IVP_U_Float_Point *)&position_cs.k[1]);
  IVP_Core::async_push_core(
    this: physical_core,
    point_cs: (const IVP_U_Float_Point *)&m_world_f_core.vv.k[1],
    impulse_in_core: (IVP_U_Float_Point *)&position_cs.k[1],
    impulse_in_world: impulse_ws_);
}

//------------------------------------------------------------------------------
// Address: 0x100706E0
// Name: protected: IVP_Real_Object_Fast::IVP_Real_Object_Fast(class IVP_Cluster __near *,class IVP_Template_Object const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Real_Object_Fast *__thiscall IVP_Real_Object_Fast::IVP_Real_Object_Fast(
        IVP_Real_Object_Fast *this,
        IVP_Cluster *father,
        const IVP_Template_Object *templ)
{
  IVP_Environment *environment; // edx
  IVP_Object *objects; // edx

  this->__vftable = (IVP_Real_Object_Fast_vtbl *)&IVP_Object::`vftable';
  environment = father->environment;
  this->prev_in_cluster = nullptr;
  this->next_in_cluster = nullptr;
  this->father_cluster = nullptr;
  this->environment = environment;
  this->name = nullptr;
  this->object_type = IVP_NONE;
  this->next_in_cluster = father->objects;
  this->prev_in_cluster = nullptr;
  objects = father->objects;
  if ( objects != nullptr )
    objects->prev_in_cluster = this;
  father->objects = this;
  this->father_cluster = father;
  this->name = p_strdup(s: templ->name);
  this->__vftable = (IVP_Real_Object_Fast_vtbl *)&IVP_Real_Object_Fast::`vftable';
  IVP_Hull_Manager_Base::IVP_Hull_Manager_Base(this: &this->hull_manager);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10070750
// Name: public: virtual IVP_Real_Object_Fast::~IVP_Real_Object_Fast(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object_Fast::~IVP_Real_Object_Fast(IVP_Real_Object_Fast *this)
{
  IVP_Cluster *father_cluster; // ecx
  IVP_Object *prev_in_cluster; // eax
  IVP_Object *next_in_cluster; // eax

  IVP_Hull_Manager_Base::~IVP_Hull_Manager_Base(this: &this->hull_manager);
  father_cluster = this->father_cluster;
  this->__vftable = (IVP_Real_Object_Fast_vtbl *)&IVP_Object::`vftable';
  if ( father_cluster != nullptr )
  {
    prev_in_cluster = this->prev_in_cluster;
    if ( prev_in_cluster != nullptr )
      prev_in_cluster->next_in_cluster = this->next_in_cluster;
    else
      father_cluster->objects = this->next_in_cluster;
    next_in_cluster = this->next_in_cluster;
    if ( next_in_cluster != nullptr )
      next_in_cluster->prev_in_cluster = this->prev_in_cluster;
  }
  if ( this->name != nullptr )
  {
    free(data: (void *)this->name);
    this->name = nullptr;
  }
  this->environment = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100707B0
// Name: public: void IVP_Real_Object::set_pinned(enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::set_pinned(IVP_Real_Object *this, IVP_BOOL is_pinned)
{
  IVP_Core *physical_core; // esi
  IVP_BOOL v4; // ebx
  IVP_OV_Element *ov_element; // ecx
  float v6; // xmm1_4
  float v7; // xmm2_4

  physical_core = this->physical_core;
  if ( (*(_WORD *)&physical_core->IVP_Core_Fast_Static & 2) == 0 )
  {
    *(_WORD *)&physical_core->IVP_Core_Fast_Static ^= ((unsigned __int8)*(_WORD *)&physical_core->IVP_Core_Fast_Static
                                                     ^ (unsigned __int8)(16 * is_pinned))
                                                    & 0x10;
    *(_QWORD *)&physical_core->speed.k[1] = 0;
    physical_core->speed.k[0] = 0.0;
    *(_QWORD *)&physical_core->rot_speed.k[1] = 0;
    physical_core->rot_speed.k[0] = 0.0;
    if ( is_pinned == IVP_TRUE )
    {
      v4 = (int)(*(_DWORD *)&this->flags << 23) >> 31;
      if ( (*(_DWORD *)&this->flags & 0x100) != 0 )
      {
        ov_element = this->ov_element;
        if ( ov_element != nullptr )
          ((void (__thiscall *)(IVP_OV_Element *, int))ov_element->dtr_IVP_OV_Element)(a1: ov_element, a2: 1);
        *(_DWORD *)&this->flags &= ~0x100u;
        this->ov_element = nullptr;
        IVP_Real_Object::unlink_contact_points(this, silent: IVP_TRUE);
      }
      physical_core->inv_rot_inertia.k[0] = 0.0;
      physical_core->inv_rot_inertia.k[1] = 0.0;
      physical_core->inv_rot_inertia.k[2] = 0.0;
      physical_core->inv_rot_inertia.hesse_val = 0.0;
      physical_core->speed_change.k[2] = 0.0;
      physical_core->speed_change.k[1] = 0.0;
      physical_core->speed_change.k[0] = 0.0;
      physical_core->rot_speed_change.k[2] = 0.0;
      physical_core->rot_speed_change.k[1] = 0.0;
      physical_core->rot_speed_change.k[0] = 0.0;
      IVP_Real_Object::enable_collision_detection(this, enable: v4);
    }
    else
    {
      v6 = 1.0 / physical_core->rot_inertia.k[1];
      v7 = 1.0 / physical_core->rot_inertia.k[2];
      physical_core->inv_rot_inertia.k[0] = 1.0 / physical_core->rot_inertia.k[0];
      physical_core->inv_rot_inertia.k[1] = v6;
      physical_core->inv_rot_inertia.k[2] = v7;
      physical_core->inv_rot_inertia.hesse_val = 1.0 / physical_core->rot_inertia.hesse_val;
      IVP_Mindist_Manager::recheck_ov_element(this: this->environment->mindist_manager, object: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070900
// Name: public: virtual void IVP_Real_Object::set_new_m_object_f_core(class IVP_U_Matrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Real_Object::set_new_m_object_f_core(
        IVP_Real_Object *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Matrix *new_m_object_f_core)
{
  IVP_Anchor *i; // esi
  float v5; // xmm0_4
  float hesse_val; // xmm2_4
  _BYTE v7[12]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Matrix new_m_core_f_object; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  new_m_core_f_object.vv.k[1] = a2;
  new_m_core_f_object.vv.k[2] = retaddr;
  IVP_U_Matrix::set_transpose(this: (IVP_U_Matrix *)v7, in: new_m_object_f_core);
  for ( i = this->anchors; i != nullptr; i = i->anchor_next_in_object )
    IVP_U_Matrix::vmult4(this: (IVP_U_Matrix *)v7, p_in: &i->object_pos, p_out: &i->core_pos);
  v5 = new_m_core_f_object.rows[2].k[2];
  hesse_val = new_m_core_f_object.rows[2].hesse_val;
  if ( (float)((float)((float)(v5 * v5) + (float)(new_m_core_f_object.rows[2].k[1] * new_m_core_f_object.rows[2].k[1]))
             + (float)(hesse_val * hesse_val)) >= 0.0000090000003 )
  {
    this->shift_core_f_object.k[0] = new_m_core_f_object.rows[2].k[1];
    this->shift_core_f_object.k[1] = v5;
    this->shift_core_f_object.k[2] = hesse_val;
    *(_DWORD *)&this->flags &= ~0x800u;
  }
  else
  {
    *(_DWORD *)&this->flags |= 0x800u;
    *(_QWORD *)&this->shift_core_f_object.k[1] = 0;
    this->shift_core_f_object.k[0] = 0.0;
  }
  if ( new_m_object_f_core->rows[0].k[0] == 1.0
    && new_m_object_f_core->rows[1].k[1] == 1.0
    && new_m_object_f_core->rows[2].k[2] == 1.0 )
  {
    free(data: this->q_core_f_object);
    this->q_core_f_object = nullptr;
  }
  else
  {
    if ( this->q_core_f_object == nullptr )
      this->q_core_f_object = (IVP_U_Quat *)p_malloc(size: 0x10u);
    IVP_U_Quat::set_quaternion(this: this->q_core_f_object, mat: (const IVP_U_Matrix3 *)v7);
    IVP_U_Quat::normize_quat(this: this->q_core_f_object);
  }
  if ( this->cache_object != nullptr )
    IVP_Cache_Object_Manager::invalid_cache_object(object: this);
}

//------------------------------------------------------------------------------
// Address: 0x10070A40
// Name: protected: IVP_Real_Object::IVP_Real_Object(class IVP_Cluster __near *,class IVP_SurfaceManager __near *,class IVP_Template_Real_Object const __near *,class IVP_U_Quat const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Real_Object *__userpurge IVP_Real_Object::IVP_Real_Object@<eax>(
        IVP_Real_Object *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Cluster *cluster,
        IVP_SurfaceManager *surface_manager_,
        const IVP_Template_Real_Object *templ_obj,
        const IVP_U_Quat *q_world_f_object,
        const IVP_U_Point *position)
{
  int v10; // eax
  IVP_Core *v11; // ecx
  IVP_Core *v12; // eax
  bool v13; // zf
  _DWORD v16[2]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_Real_Object *v17; // [esp-4h] [ebp-14h]
  IVP_U_Quat q_world_f_object_static; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  q_world_f_object_static.y = a2;
  q_world_f_object_static.z = retaddr;
  IVP_Real_Object_Fast::IVP_Real_Object_Fast(this, father: cluster, templ: templ_obj);
  this->__vftable = (IVP_Real_Object_vtbl *)&IVP_Real_Object::`vftable';
  if ( q_world_f_object == nullptr )
  {
    q_world_f_object = (const IVP_U_Quat *)v16;
    q_world_f_object_static.x = 0.0;
    v17 = nullptr;
    v16[1] = 0;
    v16[0] = 0;
  }
  this->exact_synapses = nullptr;
  this->invalid_synapses = nullptr;
  this->friction_synapses = nullptr;
  this->anchors = nullptr;
  this->ov_element = nullptr;
  this->flags = 0;
  this->q_core_f_object = nullptr;
  this->surface_manager = surface_manager_;
  *(_QWORD *)&this->shift_core_f_object.k[1] = 0;
  this->shift_core_f_object.k[0] = 0.0;
  this->cache_object = nullptr;
  this->controller_phantom = nullptr;
  v10 = ((int (__thiscall *)(IMemAlloc *, int, int, int))_g_pMemAlloc->Alloc_2)(a1: _g_pMemAlloc, a2: 451, a3, a4);
  if ( v10 != 0 )
  {
    v11 = (IVP_Core *)((v10 + 19) & 0xFFFFFFF0);
    v11[-1].tmp_null.old_sync_info = (IVP_Old_Sync_Rot_Z *)v10;
    v12 = IVP_Core::IVP_Core(
            this: v11,
            io: this,
            q_world_f_object_init: q_world_f_object,
            position,
            physical_unmoveable_: templ_obj->physical_unmoveable,
            enable_piling_optimization: templ_obj->enable_piling_optimization);
  }
  else
  {
    v12 = nullptr;
  }
  this->physical_core = v12;
  this->friction_core = v12;
  this->original_core = v12;
  v13 = templ_obj->physical_unmoveable == IVP_FALSE;
  v17 = this;
  *(_BYTE *)&this->flags = 8 * !v13 + 8;
  this->l_default_material = templ_obj->material;
  IVP_Cluster_Manager::add_object(this: v12->environment->cluster_manager, __formal: v17);
  this->client_data = templ_obj->client_data;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10070B60
// Name: protected: virtual IVP_Real_Object::~IVP_Real_Object(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::~IVP_Real_Object(IVP_Real_Object *this)
{
  IVP_Controller_Phantom *controller_phantom; // ecx
  IVP_Environment *environment; // ecx
  IVP_Environment *v4; // eax
  IVP_Core *original_core; // ecx
  IVP_Core *friction_core; // ecx
  IVP_Event_Object event_deleted; // [esp+4h] [ebp-8h] BYREF

  controller_phantom = this->controller_phantom;
  this->__vftable = (IVP_Real_Object_vtbl *)&IVP_Real_Object::`vftable';
  if ( controller_phantom != nullptr )
    ((void (__thiscall *)(IVP_Controller_Phantom *, int))controller_phantom->dtr_IVP_Listener_Object)(
      a1: controller_phantom,
      a2: 1);
  this->controller_phantom = nullptr;
  IVP_Hull_Manager::delete_hull_manager(this: (IVP_Hull_Manager *)&this->hull_manager);
  IVP_Real_Object::clear_internal_references(this);
  environment = this->environment;
  event_deleted.real_object = this;
  event_deleted.environment = environment;
  IVP_Environment::fire_event_object_deleted(this: environment, obj_event: &event_deleted);
  if ( (*(_DWORD *)&this->flags & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_collision_object_deleted(
      this: this->environment->cluster_manager,
      real_object: this);
  if ( (*(_DWORD *)&this->flags & 0x1000) != 0 )
  {
    v4 = this->environment;
    event_deleted.real_object = this;
    event_deleted.environment = v4;
    IVP_Cluster_Manager::fire_event_object_deleted(this: v4->cluster_manager, event_obj: &event_deleted);
  }
  IVP_Cluster_Manager::remove_object(this: this->physical_core->environment->cluster_manager, real_object: this);
  if ( this->cache_object != nullptr )
    IVP_Cache_Object_Manager::invalid_cache_object(object: this);
  IVP_Core::unlink_obj_from_core_and_maybe_destroy(this: this->physical_core, remove_obj: this);
  original_core = this->original_core;
  if ( original_core != this->physical_core )
    IVP_Core::unlink_obj_from_core_and_maybe_destroy(this: original_core, remove_obj: this);
  friction_core = this->friction_core;
  if ( friction_core != this->original_core && friction_core != this->physical_core )
    IVP_Core::unlink_obj_from_core_and_maybe_destroy(this: friction_core, remove_obj: this);
  free(data: this->q_core_f_object);
  this->q_core_f_object = nullptr;
  IVP_Real_Object_Fast::~IVP_Real_Object_Fast(this);
}

//------------------------------------------------------------------------------
// Address: 0x10070C60
// Name: public: void IVP_Real_Object::delete_and_check_vicinity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::delete_and_check_vicinity(IVP_Real_Object *this)
{
  IVP_Core *physical_core; // eax
  IVP_Simulation_Unit *sim_unit_of_core; // ecx

  if ( this != nullptr )
  {
    physical_core = this->physical_core;
    if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) == 0 )
    {
      sim_unit_of_core = physical_core->sim_unit_of_core;
      if ( *(_BYTE *)sim_unit_of_core >= 8 )
      {
        IVP_Simulation_Unit::sim_unit_revive_for_simulation(
          this: sim_unit_of_core,
          env: *((IVP_Environment **)*sim_unit_of_core->sim_unit_cores.elems + 3));
        IVP_Real_Object::revive_nearest_objects_grow_fs(this);
        ((void (__thiscall *)(IVP_Real_Object *, int))this->dtr_IVP_Object)(a1: this, a2: 1);
        return;
      }
      IVP_Simulation_Unit::sim_unit_ensure_cores_movement(this: sim_unit_of_core);
    }
    IVP_Real_Object::revive_nearest_objects_grow_fs(this);
    ((void (__thiscall *)(IVP_Real_Object *, int))this->dtr_IVP_Object)(a1: this, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070D30
// Name: public: void IVP_Real_Object::get_quat_world_f_object_AT(class IVP_U_Quat __near *,class IVP_U_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Real_Object::get_quat_world_f_object_AT(
        IVP_Real_Object *this,
        IVP_U_Quat *quat_world_f_object,
        IVP_U_Point *position)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  IVP_Real_Object::calc_at_quaternion(
    this,
    a2: (int)&savedregs,
    current_time: this->environment->current_time,
    q_world_f_object_out: quat_world_f_object,
    position_out: position);
}
