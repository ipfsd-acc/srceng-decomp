// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_physic_private.cxx
// Functions: 36
// ============================================================

#include "ivp\ivp_intern\ivp_physic_private.h"

//------------------------------------------------------------------------------
// Address: 0x10006DD0
// Name: public: virtual void IVP_Listener_Collision::event_friction_deleted(class IVP_Event_Friction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Listener_Collision::event_friction_deleted(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1007DF40
// Name: public: class IVP_Cluster __near * IVP_Cluster_Manager::get_root_cluster(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Cluster *__thiscall IVP_Cluster_Manager::get_root_cluster(IVP_Cluster_Manager *this)
{
  return this->root_cluster;
}

//------------------------------------------------------------------------------
// Address: 0x1007DF50
// Name: public: IVP_Cluster_Manager::IVP_Cluster_Manager(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Cluster_Manager *__thiscall IVP_Cluster_Manager::IVP_Cluster_Manager(
        IVP_Cluster_Manager *this,
        IVP_Environment *env)
{
  IVP_Cluster *v3; // eax
  IVP_Cluster *v4; // eax
  IVP_VHash *v5; // eax
  IVP_Object_Callback_Table_Hash *v6; // edi
  IVP_VHash *v7; // eax
  IVP_Collision_Callback_Table_Hash *v8; // edi

  *(_QWORD *)&this->root_cluster = 0;
  *(_QWORD *)&this->obj_callback_hash = 0;
  *(_QWORD *)&this->an_object_to_be_checked = 0;
  this->environment = env;
  v3 = (IVP_Cluster *)p_malloc(size: 0x20u);
  if ( v3 != nullptr )
    v4 = IVP_Cluster::IVP_Cluster(this: v3, env);
  else
    v4 = nullptr;
  this->root_cluster = v4;
  v5 = (IVP_VHash *)p_malloc(size: 0x10u);
  v6 = (IVP_Object_Callback_Table_Hash *)v5;
  if ( v5 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v5, size_i: 16);
    v6->__vftable = (IVP_Object_Callback_Table_Hash_vtbl *)&IVP_Collision_Callback_Table_Hash::`vftable';
  }
  else
  {
    v6 = nullptr;
  }
  this->obj_callback_hash = v6;
  v7 = (IVP_VHash *)p_malloc(size: 0x10u);
  v8 = (IVP_Collision_Callback_Table_Hash *)v7;
  if ( v7 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v7, size_i: 16);
    v8->__vftable = (IVP_Collision_Callback_Table_Hash_vtbl *)&IVP_Collision_Callback_Table_Hash::`vftable';
    this->collision_callback_hash = v8;
  }
  else
  {
    this->collision_callback_hash = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007DFF0
// Name: private: class IVP_Real_Object __near * IVP_Cluster_Manager::get_next_real_object_in_cluster_tree(class IVP_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Real_Object *__thiscall IVP_Cluster_Manager::get_next_real_object_in_cluster_tree(
        IVP_Cluster_Manager *this,
        IVP_Real_Object *object)
{
  IVP_Real_Object *result; // eax
  IVP_Real_Object *next_in_cluster; // edx
  IVP_Cluster *v4; // edx

  if ( this->number_of_real_objects == 0 )
    return nullptr;
  result = object;
  while ( 1 )
  {
    if ( result != nullptr )
    {
      next_in_cluster = (IVP_Real_Object *)result->next_in_cluster;
    }
    else
    {
      result = (IVP_Real_Object *)this->root_cluster->objects;
      next_in_cluster = result;
      if ( result == nullptr )
        return nullptr;
    }
    if ( result->object_type == IVP_CLUSTER )
    {
      result = (IVP_Real_Object *)result->controller_phantom;
      if ( result != nullptr )
        break;
    }
LABEL_11:
    while ( next_in_cluster == nullptr )
    {
      v4 = (IVP_Cluster *)result;
      result = (IVP_Real_Object *)result->father_cluster;
      if ( result == nullptr )
      {
        if ( this->root_cluster == v4 )
          return nullptr;
        result = (IVP_Real_Object *)this->root_cluster->objects;
        if ( result == nullptr )
          return nullptr;
      }
      next_in_cluster = (IVP_Real_Object *)result->next_in_cluster;
    }
    result = next_in_cluster;
    if ( next_in_cluster->object_type != IVP_CLUSTER )
      return result;
  }
  while ( result->object_type == IVP_CLUSTER )
  {
    result = (IVP_Real_Object *)result->controller_phantom;
    if ( result == nullptr )
      goto LABEL_11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E070
// Name: public: void IVP_Cluster_Manager::check_for_unused_objects(class IVP_Universe_Manager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::check_for_unused_objects(IVP_Cluster_Manager *this, IVP_Universe_Manager *um)
{
  const IVP_Universe_Manager_Settings *v3; // ebx
  IVP_Real_Object *v4; // edi
  IVP_Real_Object *an_object_to_be_checked; // edi
  int i; // [esp+8h] [ebp-4h]
  int ia; // [esp+8h] [ebp-4h]

  v3 = um->provide_universe_settings(this: um);
  if ( this->number_of_real_objects >= v3->num_objects_in_environment_threshold_0 )
  {
    i = (int)(float)((float)v3->check_objects_per_second_threshold_0 * this->environment->delta_PSI_time);
    if ( i < 0 )
    {
LABEL_7:
      if ( this->number_of_real_objects >= v3->num_objects_in_environment_threshold_1 )
      {
        for ( ia = (int)(float)((float)v3->check_objects_per_second_threshold_1 * this->environment->delta_PSI_time);
              ia >= 0;
              --ia )
        {
          an_object_to_be_checked = this->an_object_to_be_checked;
          if ( an_object_to_be_checked == nullptr )
            break;
          this->an_object_to_be_checked = IVP_Cluster_Manager::get_next_real_object_in_cluster_tree(
                                            this,
                                            object: this->an_object_to_be_checked);
          if ( IVP_Real_Object::get_collision_check_reference_count(this: an_object_to_be_checked) == 1 )
          {
            um->object_no_longer_needed(this: um, a2: an_object_to_be_checked);
            if ( this->number_of_real_objects < v3->num_objects_in_environment_threshold_1 )
              break;
          }
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v4 = this->an_object_to_be_checked;
        this->an_object_to_be_checked = IVP_Cluster_Manager::get_next_real_object_in_cluster_tree(this, object: v4);
        if ( v4 == nullptr )
          break;
        if ( IVP_Real_Object::get_collision_check_reference_count(this: v4) == 0 )
        {
          um->object_no_longer_needed(this: um, a2: v4);
          if ( this->number_of_real_objects < v3->num_objects_in_environment_threshold_0 )
            break;
        }
        if ( --i < 0 )
          goto LABEL_7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E150
// Name: public: IVP_Cluster_Manager::~IVP_Cluster_Manager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::~IVP_Cluster_Manager(IVP_Cluster_Manager *this)
{
  IVP_Cluster *root_cluster; // ecx
  IVP_Object_Callback_Table_Hash *obj_callback_hash; // ecx
  IVP_Collision_Callback_Table_Hash *collision_callback_hash; // ecx

  root_cluster = this->root_cluster;
  if ( root_cluster != nullptr )
    ((void (__thiscall *)(IVP_Cluster *, int))root_cluster->dtr_IVP_Object)(a1: root_cluster, a2: 1);
  obj_callback_hash = this->obj_callback_hash;
  this->root_cluster = nullptr;
  if ( obj_callback_hash != nullptr )
    ((void (__thiscall *)(IVP_Object_Callback_Table_Hash *, int))obj_callback_hash->dtr_IVP_VHash)(
      a1: obj_callback_hash,
      a2: 1);
  collision_callback_hash = this->collision_callback_hash;
  this->obj_callback_hash = nullptr;
  if ( collision_callback_hash != nullptr )
    ((void (__thiscall *)(IVP_Collision_Callback_Table_Hash *, int))collision_callback_hash->dtr_IVP_VHash)(
      a1: collision_callback_hash,
      a2: 1);
  this->collision_callback_hash = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007E1A0
// Name: public: void IVP_Cluster_Manager::add_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::add_object(IVP_Cluster_Manager *this, IVP_Real_Object *__formal)
{
  ++this->number_of_real_objects;
}

//------------------------------------------------------------------------------
// Address: 0x1007E1B0
// Name: public: void IVP_Friction_System::remove_dist_from_system(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::remove_dist_from_system(IVP_Friction_System *this, IVP_Contact_Point *old_dist)
{
  IVP_Contact_Point *prev_dist_in_friction; // edx
  IVP_Contact_Point *next_dist_in_friction; // eax

  prev_dist_in_friction = old_dist->prev_dist_in_friction;
  next_dist_in_friction = old_dist->next_dist_in_friction;
  if ( old_dist->next_dist_in_friction != nullptr )
    next_dist_in_friction->prev_dist_in_friction = prev_dist_in_friction;
  if ( prev_dist_in_friction != nullptr )
    prev_dist_in_friction->next_dist_in_friction = next_dist_in_friction;
  else
    this->first_friction_dist = next_dist_in_friction;
  --this->friction_dist_number;
}

//------------------------------------------------------------------------------
// Address: 0x1007E1E0
// Name: public: void IVP_Friction_System::dist_added_update_pair_info(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::dist_added_update_pair_info(
        IVP_Friction_System *this,
        IVP_Contact_Point *new_dist)
{
  IVP_Core *physical_core; // ebx
  IVP_Friction_Core_Pair *pair_info_for_objs; // esi
  IVP_Friction_Core_Pair *v5; // eax
  IVP_Core *core1; // [esp+Ch] [ebp-4h]

  physical_core = new_dist->synapse[0].l_obj->physical_core;
  core1 = new_dist->synapse[1].l_obj->physical_core;
  pair_info_for_objs = IVP_Friction_System::get_pair_info_for_objs(this, core0: physical_core, core1);
  if ( pair_info_for_objs == nullptr )
  {
    v5 = (IVP_Friction_Core_Pair *)p_malloc(size: 0x40u);
    if ( v5 != nullptr )
      pair_info_for_objs = IVP_Friction_Core_Pair::IVP_Friction_Core_Pair(this: v5);
    else
      pair_info_for_objs = nullptr;
    pair_info_for_objs->objs[0] = physical_core;
    pair_info_for_objs->objs[1] = core1;
    IVP_Friction_System::add_fr_pair(this, pair: pair_info_for_objs);
  }
  IVP_Compact_Recursive::add_compact_ledge(this: pair_info_for_objs, dist: new_dist);
}

//------------------------------------------------------------------------------
// Address: 0x1007E250
// Name: public: void IVP_Friction_System::add_dist_to_system(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::add_dist_to_system(IVP_Friction_System *this, IVP_Contact_Point *new_dist)
{
  IVP_Contact_Point *first_friction_dist; // edx

  new_dist->l_friction_system = this;
  first_friction_dist = this->first_friction_dist;
  new_dist->prev_dist_in_friction = nullptr;
  new_dist->next_dist_in_friction = first_friction_dist;
  this->first_friction_dist = new_dist;
  if ( first_friction_dist != nullptr )
    first_friction_dist->prev_dist_in_friction = new_dist;
  ++this->friction_dist_number;
}

//------------------------------------------------------------------------------
// Address: 0x1007E2B0
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY IVP_Friction_Sys_Energy::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Friction_Sys_Energy::get_controller_priority(IVP_Friction_Sys_Energy *this)
{
  return 2000;
}

//------------------------------------------------------------------------------
// Address: 0x1007E2C0
// Name: public: virtual char const __near * IVP_Friction_Sys_Energy::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Friction_Sys_Energy::get_controller_name(IVP_Friction_System *this)
{
  return "sys:friction";
}

//------------------------------------------------------------------------------
// Address: 0x1007E2D0
// Name: public: void IVP_Friction_System::fs_recalc_all_contact_points(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::fs_recalc_all_contact_points(IVP_Friction_System *this)
{
  int v1; // eax
  float *v2; // ebx
  int v3; // edi
  IVP_Contact_Point *v4; // esi
  float v5; // xmm0_4
  float old_gap_len; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  float energy_diff_sum; // [esp+8h] [ebp-8h]
  IVP_Friction_System *v9; // [esp+Ch] [ebp-4h]

  v1 = this->fr_pairs_of_objs.n_elems - 1;
  v9 = this;
  i = v1;
  if ( this->fr_pairs_of_objs.n_elems != 0 )
  {
    while ( 1 )
    {
      v2 = (float *)this->fr_pairs_of_objs.elems[v1];
      v3 = *((unsigned __int16 *)v2 + 1) - 1;
      energy_diff_sum = 0.0;
      if ( *((_WORD *)v2 + 1) != 0 )
      {
        do
        {
          v4 = *(IVP_Contact_Point **)(*((_DWORD *)v2 + 1) + 4 * v3);
          old_gap_len = v4->last_gap_len;
          IVP_Contact_Point::recalc_friction_s_vals(this: v4, env: v9->l_environment);
          --v3;
          v5 = (float)((float)(old_gap_len - v4->last_gap_len) * v4->now_friction_pressure) + energy_diff_sum;
          energy_diff_sum = v5;
        }
        while ( v3 >= 0 );
        if ( v5 > 0.0 )
          v2[12] = v2[12] + v5;
      }
      v1 = --i;
      if ( i < 0 )
        break;
      this = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E370
// Name: public: enum IVP_BOOL IVP_Friction_System::dist_removed_update_pair_info(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Friction_System::dist_removed_update_pair_info(
        IVP_Friction_System *this,
        IVP_Contact_Point *old_dist)
{
  IVP_U_Vector<IVP_Listener_Object> *pair_info_for_objs; // esi

  pair_info_for_objs = (IVP_U_Vector<IVP_Listener_Object> *)IVP_Friction_System::get_pair_info_for_objs(
                                                              this,
                                                              core0: old_dist->synapse[0].l_obj->physical_core,
                                                              core1: old_dist->synapse[1].l_obj->physical_core);
  if ( pair_info_for_objs == nullptr )
    _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_physic_private.cxx", 665);
  IVP_U_Vector<IVP_OV_Element>::remove(this: pair_info_for_objs, elem: (IVP_Listener_Object *)old_dist);
  if ( IVP_Friction_Core_Pair::number_of_pair_dists(this: (IVP_Friction_Core_Pair *)pair_info_for_objs) != 0 )
    return 0;
  IVP_Friction_System::del_fr_pair(this, pair: (IVP_Friction_Core_Pair *)pair_info_for_objs);
  if ( pair_info_for_objs != nullptr )
  {
    IVP_Friction_Core_Pair::~IVP_Friction_Core_Pair(this: (IVP_Friction_Core_Pair *)pair_info_for_objs);
    free(data: pair_info_for_objs);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007E400
// Name: public: void IVP_Friction_System::remove_core_from_system(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::remove_core_from_system(IVP_Friction_System *this, IVP_Core *old_obj)
{
  unsigned __int16 n_elems; // dx
  int v4; // eax
  IVP_Core **v5; // ecx

  if ( (*(_BYTE *)&old_obj->IVP_Core_Fast_Static & 2) == 0 )
  {
    IVP_U_Vector<IVP_OV_Element>::remove(
      this: (IVP_U_Vector<IVP_Listener_Object> *)&this->moveable_cores_of_friction_system,
      elem: (IVP_Listener_Object *)old_obj);
    IVP_Core::rem_core_controller(this: old_obj, rem_cntrl: &this->energy_fs_handle);
    IVP_Core::rem_core_controller(this: old_obj, rem_cntrl: this);
    IVP_Core::rem_core_controller(this: old_obj, rem_cntrl: &this->static_fs_handle);
  }
  n_elems = this->cores_of_friction_system.n_elems;
  v4 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v5 = (IVP_Core **)&this->cores_of_friction_system.elems[v4];
    do
    {
      if ( *v5 == old_obj )
        break;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  for ( this->cores_of_friction_system.n_elems = n_elems - 1; v4 < this->cores_of_friction_system.n_elems; ++v4 )
    this->cores_of_friction_system.elems[v4] = this->cores_of_friction_system.elems[v4 + 1];
  --this->friction_obj_number;
}

//------------------------------------------------------------------------------
// Address: 0x1007E480
// Name: private: void IVP_Environment::remove_revive_core(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::remove_revive_core(IVP_Environment *this, IVP_Core *c)
{
  int n_elems; // eax
  IVP_U_Vector<IVP_Sim_Unit_Controller_Core_List> *p_core_revive_list; // ecx
  int v4; // eax
  IVP_Core **i; // edx

  n_elems = this->core_revive_list.n_elems;
  p_core_revive_list = (IVP_U_Vector<IVP_Sim_Unit_Controller_Core_List> *)&this->core_revive_list;
  v4 = n_elems - 1;
  if ( v4 >= 0 )
  {
    for ( i = (IVP_Core **)&p_core_revive_list->elems[v4]; *i != c; --i )
    {
      if ( --v4 < 0 )
        return;
    }
    IVP_U_Vector<IVP_Core>::remove_at(this: p_core_revive_list, index: v4);
    *(_WORD *)&c->IVP_Core_Fast_Static &= ~4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E4D0
// Name: private: void IVP_Environment::revive_cores_PSI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::revive_cores_PSI(IVP_Environment *this)
{
  int v2; // edi
  IVP_Core *v3; // esi
  IVP_Environment *elems; // eax

  v2 = this->core_revive_list.n_elems - 1;
  if ( this->core_revive_list.n_elems != 0 )
  {
    do
    {
      v3 = (IVP_Core *)this->core_revive_list.elems[v2];
      IVP_Core::ensure_core_to_be_in_simulation(this: v3);
      *(_WORD *)&v3->IVP_Core_Fast_Static &= ~4u;
      --v2;
    }
    while ( v2 >= 0 );
  }
  elems = (IVP_Environment *)this->core_revive_list.elems;
  if ( elems == (IVP_Environment *)&this->constraint_listeners )
  {
    this->core_revive_list.n_elems = 0;
  }
  else
  {
    if ( elems != nullptr )
      free(data: elems);
    this->core_revive_list.elems = nullptr;
    *(_DWORD *)&this->core_revive_list.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E540
// Name: public: IVP_Object_Callback_Table::~IVP_Object_Callback_Table(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Object_Callback_Table::~IVP_Object_Callback_Table(IVP_Collision_Callback_Table *this)
{
  IVP_Collision_Callback_Table *elems; // eax

  elems = (IVP_Collision_Callback_Table *)this->listeners.elems;
  if ( elems == this + 1 )
  {
    this->listeners.n_elems = 0;
  }
  else
  {
    if ( elems != nullptr )
      free(data: elems);
    this->listeners.elems = nullptr;
    *(_DWORD *)&this->listeners.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E570
// Name: public: IVP_Friction_System::IVP_Friction_System(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Friction_System *__thiscall IVP_Friction_System::IVP_Friction_System(
        IVP_Friction_System *this,
        IVP_Environment *env)
{
  this->__vftable = (IVP_Friction_System_vtbl *)&IVP_Friction_System::`vftable';
  this->static_fs_handle.__vftable = (IVP_Friction_Sys_Static_vtbl *)&IVP_Friction_Sys_Static::`vftable';
  this->energy_fs_handle.__vftable = (IVP_Friction_Sys_Energy_vtbl *)&IVP_Friction_Sys_Energy::`vftable';
  *(_DWORD *)&this->cores_of_friction_system.memsize = 0;
  this->cores_of_friction_system.elems = nullptr;
  this->moveable_cores_of_friction_system.elems = nullptr;
  this->moveable_cores_of_friction_system.memsize = 0;
  this->moveable_cores_of_friction_system.n_elems = 0;
  this->fr_pairs_of_objs.memsize = 0;
  this->fr_pairs_of_objs.n_elems = 0;
  this->fr_pairs_of_objs.elems = nullptr;
  this->l_environment = env;
  *((_BYTE *)this + 68) = 0;
  this->first_friction_dist = nullptr;
  *(_DWORD *)&this->friction_obj_number = 0;
  this->static_fs_handle.l_friction_system = this;
  this->energy_fs_handle.l_friction_system = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007E5D0
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY IVP_Friction_System::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Friction_System::get_controller_priority(IVP_Friction_System *this)
{
  return 600;
}

//------------------------------------------------------------------------------
// Address: 0x1007E5E0
// Name: public: virtual IVP_Friction_System::~IVP_Friction_System(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::~IVP_Friction_System(IVP_Friction_System *this)
{
  IVP_Friction_System *elems; // eax
  IVP_Friction_System *v3; // eax
  IVP_Friction_System *v4; // eax

  this->__vftable = (IVP_Friction_System_vtbl *)&IVP_Friction_System::`vftable';
  elems = (IVP_Friction_System *)this->fr_pairs_of_objs.elems;
  if ( elems != (IVP_Friction_System *)&this->friction_obj_number )
  {
    if ( elems != nullptr )
      free(data: elems);
    this->fr_pairs_of_objs.elems = nullptr;
    this->fr_pairs_of_objs.memsize = 0;
  }
  this->fr_pairs_of_objs.n_elems = 0;
  v3 = (IVP_Friction_System *)this->moveable_cores_of_friction_system.elems;
  if ( v3 != (IVP_Friction_System *)&this->fr_pairs_of_objs )
  {
    if ( v3 != nullptr )
      free(data: this->moveable_cores_of_friction_system.elems);
    this->moveable_cores_of_friction_system.elems = nullptr;
    this->moveable_cores_of_friction_system.memsize = 0;
  }
  this->moveable_cores_of_friction_system.n_elems = 0;
  v4 = (IVP_Friction_System *)this->cores_of_friction_system.elems;
  if ( v4 != (IVP_Friction_System *)&this->moveable_cores_of_friction_system )
  {
    if ( v4 != nullptr )
      free(data: this->cores_of_friction_system.elems);
    this->cores_of_friction_system.elems = nullptr;
    this->cores_of_friction_system.memsize = 0;
  }
  this->cores_of_friction_system.n_elems = 0;
  this->energy_fs_handle.__vftable = (IVP_Friction_Sys_Energy_vtbl *)&IVP_Controller_Dependent::`vftable';
  this->static_fs_handle.__vftable = (IVP_Friction_Sys_Static_vtbl *)&IVP_Controller_Dependent::`vftable';
  this->__vftable = (IVP_Friction_System_vtbl *)&IVP_Controller_Dependent::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1007E680
// Name: public: void IVP_Friction_System::add_core_to_system(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::add_core_to_system(IVP_Friction_System *this, IVP_Core *new_obj)
{
  if ( this->cores_of_friction_system.n_elems >= this->cores_of_friction_system.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->cores_of_friction_system);
  this->cores_of_friction_system.elems[this->cores_of_friction_system.n_elems++] = new_obj;
  if ( (*(_BYTE *)&new_obj->IVP_Core_Fast_Static & 2) != 0 )
  {
    ++this->friction_obj_number;
  }
  else
  {
    if ( this->moveable_cores_of_friction_system.n_elems >= this->moveable_cores_of_friction_system.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->moveable_cores_of_friction_system);
    this->moveable_cores_of_friction_system.elems[this->moveable_cores_of_friction_system.n_elems++] = new_obj;
    IVP_Core::add_core_controller(this: new_obj, add_cntrl: &this->static_fs_handle);
    IVP_Core::add_core_controller(this: new_obj, add_cntrl: this);
    IVP_Core::add_core_controller(this: new_obj, add_cntrl: &this->energy_fs_handle);
    ++this->friction_obj_number;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E710
// Name: private: void IVP_Environment::add_revive_core(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Environment::add_revive_core(IVP_Environment *this, IVP_Core *c)
{
  IVP_U_Vector<IVP_Core> *p_core_revive_list; // esi

  if ( (*(_BYTE *)&c->IVP_Core_Fast_Static & 4) == 0 )
  {
    p_core_revive_list = &this->core_revive_list;
    if ( this->core_revive_list.n_elems >= this->core_revive_list.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->core_revive_list);
    p_core_revive_list->elems[p_core_revive_list->n_elems++] = c;
    *(_WORD *)&c->IVP_Core_Fast_Static |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E760
// Name: public: void IVP_Cluster_Manager::fire_event_object_deleted(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::fire_event_object_deleted(IVP_Cluster_Manager *this, IVP_Event_Object *event_obj)
{
  IVP_Object_Callback_Table_Hash *obj_callback_hash; // ebx
  IVP_Real_Object *real_object; // edi
  unsigned int v4; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  void (__thiscall ***v7)(_DWORD, IVP_Event_Object *); // ecx
  IVP_Object_Callback_Table_Hash *v8; // esi
  unsigned int v9; // eax
  void *v10; // esi
  IVP_Real_Object *v11; // [esp+Ch] [ebp-20h] BYREF
  int v12; // [esp+10h] [ebp-1Ch]
  void *v13; // [esp+14h] [ebp-18h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-14h] BYREF
  int v15; // [esp+1Ch] [ebp-10h]
  void *data; // [esp+20h] [ebp-Ch]
  _DWORD *v17; // [esp+24h] [ebp-8h] BYREF
  IVP_Cluster_Manager *v18; // [esp+28h] [ebp-4h]

  obj_callback_hash = this->obj_callback_hash;
  v18 = this;
  real_object = event_obj->real_object;
  v15 = 0;
  data = nullptr;
  elem = real_object;
  v4 = IVP_Collision_Callback_Table_Hash::object_to_index(this: obj_callback_hash, real_object);
  v5 = IVP_VHash::find_elem(this: obj_callback_hash, &elem, hash_index: v4);
  v17 = v5;
  if ( data != &v17 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v15) = 0;
  }
  HIWORD(v15) = 0;
  if ( v5 != nullptr )
  {
    v6 = *((unsigned __int16 *)v5 + 3) - 1;
    if ( *((_WORD *)v5 + 3) != 0 )
    {
      do
      {
        v7 = *(void (__thiscall ****)(_DWORD, IVP_Event_Object *))(v5[2] + 4 * v6);
        (**v7)(a1: v7, a2: event_obj);
        if ( v6 > 0 )
        {
          v8 = v18->obj_callback_hash;
          v12 = 0;
          v13 = nullptr;
          v11 = real_object;
          v9 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v8, real_object);
          v10 = IVP_VHash::find_elem(this: v8, elem: &v11, hash_index: v9);
          if ( v13 != &elem )
          {
            if ( v13 != nullptr )
              free(data: v13);
            v13 = nullptr;
            LOWORD(v12) = 0;
          }
          HIWORD(v12) = 0;
          if ( v10 == nullptr )
            return;
          v5 = v17;
        }
        --v6;
      }
      while ( v6 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E850
// Name: public: void IVP_Cluster_Manager::fire_event_object_revived(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::fire_event_object_revived(IVP_Cluster_Manager *this, IVP_Event_Object *event_obj)
{
  IVP_Object_Callback_Table_Hash *obj_callback_hash; // ebx
  IVP_Real_Object *real_object; // edi
  unsigned int v4; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  int v7; // ecx
  IVP_Object_Callback_Table_Hash *v8; // esi
  unsigned int v9; // eax
  void *v10; // esi
  IVP_Real_Object *v11; // [esp+Ch] [ebp-20h] BYREF
  int v12; // [esp+10h] [ebp-1Ch]
  void *v13; // [esp+14h] [ebp-18h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-14h] BYREF
  int v15; // [esp+1Ch] [ebp-10h]
  void *data; // [esp+20h] [ebp-Ch]
  _DWORD *v17; // [esp+24h] [ebp-8h] BYREF
  IVP_Cluster_Manager *v18; // [esp+28h] [ebp-4h]

  obj_callback_hash = this->obj_callback_hash;
  v18 = this;
  real_object = event_obj->real_object;
  v15 = 0;
  data = nullptr;
  elem = real_object;
  v4 = IVP_Collision_Callback_Table_Hash::object_to_index(this: obj_callback_hash, real_object);
  v5 = IVP_VHash::find_elem(this: obj_callback_hash, &elem, hash_index: v4);
  v17 = v5;
  if ( data != &v17 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v15) = 0;
  }
  HIWORD(v15) = 0;
  if ( v5 != nullptr )
  {
    v6 = *((unsigned __int16 *)v5 + 3) - 1;
    if ( *((_WORD *)v5 + 3) != 0 )
    {
      do
      {
        v7 = *(_DWORD *)(v5[2] + 4 * v6);
        (*(void (__thiscall **)(int, IVP_Event_Object *))(*(_DWORD *)v7 + 8))(a1: v7, a2: event_obj);
        if ( v6 > 0 )
        {
          v8 = v18->obj_callback_hash;
          v12 = 0;
          v13 = nullptr;
          v11 = real_object;
          v9 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v8, real_object);
          v10 = IVP_VHash::find_elem(this: v8, elem: &v11, hash_index: v9);
          if ( v13 != &elem )
          {
            if ( v13 != nullptr )
              free(data: v13);
            v13 = nullptr;
            LOWORD(v12) = 0;
          }
          HIWORD(v12) = 0;
          if ( v10 == nullptr )
            return;
          v5 = v17;
        }
        --v6;
      }
      while ( v6 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E940
// Name: public: void IVP_Cluster_Manager::fire_event_pre_collision(class IVP_Real_Object __near *,class IVP_Event_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::fire_event_pre_collision(
        IVP_Cluster_Manager *this,
        IVP_Real_Object *real_object,
        IVP_Event_Collision *event_obj)
{
  IVP_Object_Callback_Table_Hash *collision_callback_hash; // esi
  unsigned int v5; // eax
  IVP_Real_Object *v6; // esi
  int v7; // edi
  IVP_Object_vtbl *v8; // ecx
  IVP_Object_Callback_Table_Hash *v9; // esi
  unsigned int v10; // eax
  void *v11; // esi
  IVP_Real_Object *v12; // [esp+Ch] [ebp-1Ch] BYREF
  int v13; // [esp+10h] [ebp-18h]
  void *v14; // [esp+14h] [ebp-14h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch]
  void *data; // [esp+20h] [ebp-8h]
  IVP_Cluster_Manager *v18; // [esp+24h] [ebp-4h] BYREF
  IVP_Real_Object *real_objecta; // [esp+30h] [ebp+8h]

  collision_callback_hash = (IVP_Object_Callback_Table_Hash *)this->collision_callback_hash;
  v18 = this;
  v16 = 0;
  data = nullptr;
  elem = real_object;
  v5 = IVP_Collision_Callback_Table_Hash::object_to_index(this: collision_callback_hash, real_object);
  v6 = (IVP_Real_Object *)IVP_VHash::find_elem(this: collision_callback_hash, &elem, hash_index: v5);
  real_objecta = v6;
  if ( data != &v18 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v16) = 0;
  }
  HIWORD(v16) = 0;
  if ( v6 != nullptr )
  {
    v7 = HIWORD(v6->object_type) - 1;
    if ( HIWORD(v6->object_type) != 0 )
    {
      do
      {
        v8 = (&v6->next_in_cluster->IVP_Real_Object_Fast::IVP_Real_Object_Fast_Static::IVP_Object::__vftable)[v7];
        if ( ((int)v8[1].dtr_IVP_Object & 8) != 0 )
        {
          (*(void (__thiscall **)(IVP_Object_vtbl *, IVP_Event_Collision *))v8->dtr_IVP_Object)(a1: v8, a2: event_obj);
          if ( v7 > 0 )
          {
            v9 = (IVP_Object_Callback_Table_Hash *)v18->collision_callback_hash;
            v13 = 0;
            v14 = nullptr;
            v12 = real_object;
            v10 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v9, real_object);
            v11 = IVP_VHash::find_elem(this: v9, elem: &v12, hash_index: v10);
            if ( v14 != &elem )
            {
              if ( v14 != nullptr )
                free(data: v14);
              v14 = nullptr;
              LOWORD(v13) = 0;
            }
            HIWORD(v13) = 0;
            if ( v11 == nullptr )
              return;
            v6 = real_objecta;
          }
        }
        --v7;
      }
      while ( v7 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EA30
// Name: public: void IVP_Cluster_Manager::fire_event_post_collision(class IVP_Real_Object __near *,class IVP_Event_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::fire_event_post_collision(
        IVP_Cluster_Manager *this,
        IVP_Real_Object *real_object,
        IVP_Event_Collision *event_obj)
{
  IVP_Object_Callback_Table_Hash *collision_callback_hash; // esi
  unsigned int v5; // eax
  IVP_Real_Object *v6; // esi
  int v7; // edi
  IVP_Object_vtbl *v8; // ecx
  IVP_Object_Callback_Table_Hash *v9; // esi
  unsigned int v10; // eax
  void *v11; // esi
  IVP_Real_Object *v12; // [esp+Ch] [ebp-1Ch] BYREF
  int v13; // [esp+10h] [ebp-18h]
  void *v14; // [esp+14h] [ebp-14h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch]
  void *data; // [esp+20h] [ebp-8h]
  IVP_Cluster_Manager *v18; // [esp+24h] [ebp-4h] BYREF
  IVP_Real_Object *real_objecta; // [esp+30h] [ebp+8h]

  collision_callback_hash = (IVP_Object_Callback_Table_Hash *)this->collision_callback_hash;
  v18 = this;
  v16 = 0;
  data = nullptr;
  elem = real_object;
  v5 = IVP_Collision_Callback_Table_Hash::object_to_index(this: collision_callback_hash, real_object);
  v6 = (IVP_Real_Object *)IVP_VHash::find_elem(this: collision_callback_hash, &elem, hash_index: v5);
  real_objecta = v6;
  if ( data != &v18 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v16) = 0;
  }
  HIWORD(v16) = 0;
  if ( v6 != nullptr )
  {
    v7 = HIWORD(v6->object_type) - 1;
    if ( HIWORD(v6->object_type) != 0 )
    {
      do
      {
        v8 = (&v6->next_in_cluster->IVP_Real_Object_Fast::IVP_Real_Object_Fast_Static::IVP_Object::__vftable)[v7];
        if ( ((int)v8[1].dtr_IVP_Object & 1) != 0 )
        {
          (*((void (__thiscall **)(IVP_Object_vtbl *, IVP_Event_Collision *))v8->dtr_IVP_Object + 1))(
            a1: v8,
            a2: event_obj);
          if ( v7 > 0 )
          {
            v9 = (IVP_Object_Callback_Table_Hash *)v18->collision_callback_hash;
            v13 = 0;
            v14 = nullptr;
            v12 = real_object;
            v10 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v9, real_object);
            v11 = IVP_VHash::find_elem(this: v9, elem: &v12, hash_index: v10);
            if ( v14 != &elem )
            {
              if ( v14 != nullptr )
                free(data: v14);
              v14 = nullptr;
              LOWORD(v13) = 0;
            }
            HIWORD(v13) = 0;
            if ( v11 == nullptr )
              return;
            v6 = real_objecta;
          }
        }
        --v7;
      }
      while ( v7 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EB20
// Name: public: void IVP_Cluster_Manager::fire_event_collision_object_deleted(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::fire_event_collision_object_deleted(
        IVP_Cluster_Manager *this,
        IVP_Real_Object *real_object)
{
  IVP_Object_Callback_Table_Hash *collision_callback_hash; // esi
  unsigned int v4; // eax
  IVP_Real_Object *v5; // esi
  int v6; // ebx
  IVP_Object_vtbl *v7; // ecx
  IVP_Object_Callback_Table_Hash *v8; // esi
  unsigned int v9; // eax
  void *v10; // esi
  IVP_Real_Object *v11; // [esp+Ch] [ebp-1Ch] BYREF
  int v12; // [esp+10h] [ebp-18h]
  void *v13; // [esp+14h] [ebp-14h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch]
  void *data; // [esp+20h] [ebp-8h]
  IVP_Cluster_Manager *v17; // [esp+24h] [ebp-4h] BYREF
  IVP_Real_Object *real_objecta; // [esp+30h] [ebp+8h]

  collision_callback_hash = (IVP_Object_Callback_Table_Hash *)this->collision_callback_hash;
  v17 = this;
  v15 = 0;
  data = nullptr;
  elem = real_object;
  v4 = IVP_Collision_Callback_Table_Hash::object_to_index(this: collision_callback_hash, real_object);
  v5 = (IVP_Real_Object *)IVP_VHash::find_elem(this: collision_callback_hash, &elem, hash_index: v4);
  real_objecta = v5;
  if ( data != &v17 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v15) = 0;
  }
  HIWORD(v15) = 0;
  if ( v5 != nullptr )
  {
    v6 = HIWORD(v5->object_type) - 1;
    if ( HIWORD(v5->object_type) != 0 )
    {
      do
      {
        v7 = (&v5->next_in_cluster->IVP_Real_Object_Fast::IVP_Real_Object_Fast_Static::IVP_Object::__vftable)[v6];
        if ( ((int)v7[1].dtr_IVP_Object & 2) != 0 )
        {
          (*((void (__thiscall **)(IVP_Object_vtbl *, IVP_Real_Object *))v7->dtr_IVP_Object + 2))(
            a1: v7,
            a2: real_object);
          if ( v6 > 0 )
          {
            v8 = (IVP_Object_Callback_Table_Hash *)v17->collision_callback_hash;
            v12 = 0;
            v13 = nullptr;
            v11 = real_object;
            v9 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v8, real_object);
            v10 = IVP_VHash::find_elem(this: v8, elem: &v11, hash_index: v9);
            if ( v13 != &elem )
            {
              if ( v13 != nullptr )
                free(data: v13);
              v13 = nullptr;
              LOWORD(v12) = 0;
            }
            HIWORD(v12) = 0;
            if ( v10 == nullptr )
              return;
            v5 = real_objecta;
          }
        }
        --v6;
      }
      while ( v6 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EC10
// Name: public: void IVP_Cluster_Manager::fire_event_friction_created(class IVP_Real_Object __near *,class IVP_Event_Friction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::fire_event_friction_created(
        IVP_Cluster_Manager *this,
        IVP_Real_Object *real_object,
        IVP_Event_Friction *event_friction)
{
  IVP_Object_Callback_Table_Hash *collision_callback_hash; // esi
  unsigned int v5; // eax
  IVP_Real_Object *v6; // esi
  int v7; // edi
  IVP_Object_vtbl *v8; // ecx
  IVP_Object_Callback_Table_Hash *v9; // esi
  unsigned int v10; // eax
  void *v11; // esi
  IVP_Real_Object *v12; // [esp+Ch] [ebp-1Ch] BYREF
  int v13; // [esp+10h] [ebp-18h]
  void *v14; // [esp+14h] [ebp-14h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch]
  void *data; // [esp+20h] [ebp-8h]
  IVP_Cluster_Manager *v18; // [esp+24h] [ebp-4h] BYREF
  IVP_Real_Object *real_objecta; // [esp+30h] [ebp+8h]

  collision_callback_hash = (IVP_Object_Callback_Table_Hash *)this->collision_callback_hash;
  v18 = this;
  v16 = 0;
  data = nullptr;
  elem = real_object;
  v5 = IVP_Collision_Callback_Table_Hash::object_to_index(this: collision_callback_hash, real_object);
  v6 = (IVP_Real_Object *)IVP_VHash::find_elem(this: collision_callback_hash, &elem, hash_index: v5);
  real_objecta = v6;
  if ( data != &v18 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v16) = 0;
  }
  HIWORD(v16) = 0;
  if ( v6 != nullptr )
  {
    v7 = HIWORD(v6->object_type) - 1;
    if ( HIWORD(v6->object_type) != 0 )
    {
      do
      {
        v8 = (&v6->next_in_cluster->IVP_Real_Object_Fast::IVP_Real_Object_Fast_Static::IVP_Object::__vftable)[v7];
        if ( ((int)v8[1].dtr_IVP_Object & 4) != 0 )
        {
          (*((void (__thiscall **)(IVP_Object_vtbl *, IVP_Event_Friction *))v8->dtr_IVP_Object + 3))(
            a1: v8,
            a2: event_friction);
          if ( v7 > 0 )
          {
            v9 = (IVP_Object_Callback_Table_Hash *)v18->collision_callback_hash;
            v13 = 0;
            v14 = nullptr;
            v12 = real_object;
            v10 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v9, real_object);
            v11 = IVP_VHash::find_elem(this: v9, elem: &v12, hash_index: v10);
            if ( v14 != &elem )
            {
              if ( v14 != nullptr )
                free(data: v14);
              v14 = nullptr;
              LOWORD(v13) = 0;
            }
            HIWORD(v13) = 0;
            if ( v11 == nullptr )
              return;
            v6 = real_objecta;
          }
        }
        --v7;
      }
      while ( v7 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007ED00
// Name: public: void IVP_Cluster_Manager::fire_event_friction_deleted(class IVP_Real_Object __near *,class IVP_Event_Friction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::fire_event_friction_deleted(
        IVP_Cluster_Manager *this,
        IVP_Real_Object *real_object,
        IVP_Event_Friction *event_friction)
{
  IVP_Object_Callback_Table_Hash *collision_callback_hash; // esi
  unsigned int v5; // eax
  IVP_Real_Object *v6; // esi
  int v7; // edi
  IVP_Object_vtbl *v8; // ecx
  IVP_Object_Callback_Table_Hash *v9; // esi
  unsigned int v10; // eax
  void *v11; // esi
  IVP_Real_Object *v12; // [esp+Ch] [ebp-1Ch] BYREF
  int v13; // [esp+10h] [ebp-18h]
  void *v14; // [esp+14h] [ebp-14h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch]
  void *data; // [esp+20h] [ebp-8h]
  IVP_Cluster_Manager *v18; // [esp+24h] [ebp-4h] BYREF
  IVP_Real_Object *real_objecta; // [esp+30h] [ebp+8h]

  collision_callback_hash = (IVP_Object_Callback_Table_Hash *)this->collision_callback_hash;
  v18 = this;
  v16 = 0;
  data = nullptr;
  elem = real_object;
  v5 = IVP_Collision_Callback_Table_Hash::object_to_index(this: collision_callback_hash, real_object);
  v6 = (IVP_Real_Object *)IVP_VHash::find_elem(this: collision_callback_hash, &elem, hash_index: v5);
  real_objecta = v6;
  if ( data != &v18 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v16) = 0;
  }
  HIWORD(v16) = 0;
  if ( v6 != nullptr )
  {
    v7 = HIWORD(v6->object_type) - 1;
    if ( HIWORD(v6->object_type) != 0 )
    {
      do
      {
        v8 = (&v6->next_in_cluster->IVP_Real_Object_Fast::IVP_Real_Object_Fast_Static::IVP_Object::__vftable)[v7];
        if ( ((int)v8[1].dtr_IVP_Object & 4) != 0 )
        {
          (*((void (__thiscall **)(IVP_Object_vtbl *, IVP_Event_Friction *))v8->dtr_IVP_Object + 4))(
            a1: v8,
            a2: event_friction);
          if ( v7 > 0 )
          {
            v9 = (IVP_Object_Callback_Table_Hash *)v18->collision_callback_hash;
            v13 = 0;
            v14 = nullptr;
            v12 = real_object;
            v10 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v9, real_object);
            v11 = IVP_VHash::find_elem(this: v9, elem: &v12, hash_index: v10);
            if ( v14 != &elem )
            {
              if ( v14 != nullptr )
                free(data: v14);
              v14 = nullptr;
              LOWORD(v13) = 0;
            }
            HIWORD(v13) = 0;
            if ( v11 == nullptr )
              return;
            v6 = real_objecta;
          }
        }
        --v7;
      }
      while ( v7 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EDF0
// Name: public: void IVP_Cluster_Manager::add_listener_object(class IVP_Real_Object __near *,class IVP_Listener_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::add_listener_object(
        IVP_Cluster_Manager *this,
        IVP_Real_Object *real_object,
        IVP_Listener_Object *listener)
{
  IVP_Object_Callback_Table_Hash *obj_callback_hash; // esi
  _DWORD *v4; // edi
  unsigned int v5; // eax
  char *v6; // esi
  _DWORD *v7; // eax
  IVP_Object_Callback_Table_Hash *v8; // esi
  int v9; // eax
  IVP_Real_Object *elem; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+10h] [ebp-Ch]
  void *data; // [esp+14h] [ebp-8h]
  IVP_Cluster_Manager *v13; // [esp+18h] [ebp-4h] BYREF

  obj_callback_hash = this->obj_callback_hash;
  v13 = this;
  v4 = nullptr;
  v11 = 0;
  data = nullptr;
  elem = real_object;
  v5 = IVP_Collision_Callback_Table_Hash::object_to_index(this: obj_callback_hash, real_object);
  v6 = (char *)IVP_VHash::find_elem(this: obj_callback_hash, &elem, hash_index: v5);
  if ( data != &v13 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v11) = 0;
  }
  HIWORD(v11) = 0;
  if ( v6 != nullptr )
  {
    if ( *((_WORD *)v6 + 3) >= *((_WORD *)v6 + 2) )
      IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)(v6 + 4));
    *(_DWORD *)(*((_DWORD *)v6 + 2) + 4 * (unsigned __int16)(*((_WORD *)v6 + 3))++) = listener;
  }
  else
  {
    v7 = p_malloc(size: 0xCu);
    if ( v7 != nullptr )
    {
      v7[2] = 0;
      v7[1] = 0;
      v4 = v7;
    }
    *v4 = real_object;
    if ( *((_WORD *)v4 + 3) >= *((_WORD *)v4 + 2) )
      IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)(v4 + 1));
    *(_DWORD *)(v4[2] + 4 * (unsigned __int16)(*((_WORD *)v4 + 3))++) = listener;
    v8 = v13->obj_callback_hash;
    v9 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v8, real_object: (IVP_Real_Object *)*v4);
    IVP_VHash::add_elem(this: v8, elem: v4, hash_index: v9);
    *(_DWORD *)&real_object->flags |= 0x1000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EEF0
// Name: public: void IVP_Cluster_Manager::remove_listener_object(class IVP_Real_Object __near *,class IVP_Listener_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::remove_listener_object(
        IVP_Cluster_Manager *this,
        IVP_Real_Object *real_object,
        IVP_Listener_Object *listener)
{
  IVP_Object_Callback_Table_Hash *obj_callback_hash; // edi
  unsigned int v6; // eax
  char *v7; // edi
  IVP_Object_Callback_Table_Hash *v8; // edi
  unsigned int v9; // eax
  IVP_Real_Object *next_in_cluster; // eax
  _DWORD v11[2]; // [esp+Ch] [ebp-18h] BYREF
  void *v12; // [esp+14h] [ebp-10h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-Ch] BYREF
  int v14; // [esp+1Ch] [ebp-8h]
  void *data; // [esp+20h] [ebp-4h]
  char vars0; // [esp+24h] [ebp+0h] BYREF
  IVP_Real_Object *real_objecta; // [esp+2Ch] [ebp+8h]

  obj_callback_hash = this->obj_callback_hash;
  v14 = 0;
  data = nullptr;
  elem = real_object;
  v6 = IVP_Collision_Callback_Table_Hash::object_to_index(this: obj_callback_hash, real_object);
  v7 = (char *)IVP_VHash::find_elem(this: obj_callback_hash, &elem, hash_index: v6);
  real_objecta = (IVP_Real_Object *)v7;
  if ( data != &vars0 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v14) = 0;
  }
  HIWORD(v14) = 0;
  if ( v7 != nullptr )
  {
    IVP_U_Vector<IVP_OV_Element>::remove(this: (IVP_U_Vector<IVP_Listener_Object> *)(v7 + 4), elem: listener);
    if ( *((_WORD *)v7 + 3) == 0 )
    {
      v8 = this->obj_callback_hash;
      v11[1] = 0;
      v12 = nullptr;
      v11[0] = real_object;
      v9 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v8, real_object);
      IVP_VHash::remove_elem(this: v8, elem: v11, hash_index: v9);
      if ( v12 != &elem && v12 != nullptr )
        free(data: v12);
      next_in_cluster = (IVP_Real_Object *)real_objecta->next_in_cluster;
      if ( next_in_cluster != (IVP_Real_Object *)&real_objecta->prev_in_cluster )
      {
        if ( next_in_cluster != nullptr )
          free(data: real_objecta->next_in_cluster);
        real_objecta->next_in_cluster = nullptr;
        LOWORD(real_objecta->object_type) = 0;
      }
      HIWORD(real_objecta->object_type) = 0;
      free(data: real_objecta);
      *(_DWORD *)&real_object->flags &= ~0x1000u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EFF0
// Name: public: void IVP_Cluster_Manager::remove_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cluster_Manager::remove_object(IVP_Cluster_Manager *this, IVP_Real_Object *real_object)
{
  IVP_Object_Callback_Table_Hash *obj_callback_hash; // ebx
  unsigned int v5; // eax
  IVP_Real_Object *v6; // ebx
  IVP_Object_Callback_Table_Hash *v7; // ebx
  unsigned int v8; // eax
  IVP_Object **next_in_cluster; // eax
  IVP_Object_Callback_Table_Hash *collision_callback_hash; // ebx
  unsigned int v11; // eax
  IVP_Real_Object *v12; // ebx
  IVP_Object_Callback_Table_Hash *v13; // ebx
  unsigned int v14; // eax
  IVP_Real_Object *v15; // eax
  IVP_Real_Object *next_real_object_in_cluster_tree; // eax
  IVP_Universe_Manager *universe_manager; // ecx
  IVP_Real_Object *v18; // [esp+Ch] [ebp-18h] BYREF
  int v19; // [esp+10h] [ebp-14h]
  void *v20; // [esp+14h] [ebp-10h]
  IVP_Real_Object *elem; // [esp+18h] [ebp-Ch] BYREF
  int v22; // [esp+1Ch] [ebp-8h]
  void *data; // [esp+20h] [ebp-4h]
  char vars0; // [esp+24h] [ebp+0h] BYREF
  IVP_Real_Object *real_objecta; // [esp+2Ch] [ebp+8h]
  IVP_Real_Object *real_objectb; // [esp+2Ch] [ebp+8h]

  obj_callback_hash = this->obj_callback_hash;
  --this->number_of_real_objects;
  v22 = 0;
  data = nullptr;
  elem = real_object;
  v5 = IVP_Collision_Callback_Table_Hash::object_to_index(this: obj_callback_hash, real_object);
  v6 = (IVP_Real_Object *)IVP_VHash::find_elem(this: obj_callback_hash, &elem, hash_index: v5);
  real_objecta = v6;
  if ( data != &vars0 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v22) = 0;
  }
  HIWORD(v22) = 0;
  if ( v6 != nullptr )
  {
    v7 = this->obj_callback_hash;
    v19 = 0;
    v20 = nullptr;
    v18 = real_object;
    v8 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v7, real_object);
    IVP_VHash::remove_elem(this: v7, elem: &v18, hash_index: v8);
    if ( v20 != &elem && v20 != nullptr )
      free(data: v20);
    next_in_cluster = (IVP_Object **)real_objecta->next_in_cluster;
    if ( next_in_cluster != &real_objecta->prev_in_cluster )
    {
      if ( next_in_cluster != nullptr )
        free(data: next_in_cluster);
      real_objecta->next_in_cluster = nullptr;
      LOWORD(real_objecta->object_type) = 0;
    }
    HIWORD(real_objecta->object_type) = 0;
    free(data: real_objecta);
  }
  collision_callback_hash = (IVP_Object_Callback_Table_Hash *)this->collision_callback_hash;
  v22 = 0;
  data = nullptr;
  elem = real_object;
  v11 = IVP_Collision_Callback_Table_Hash::object_to_index(this: collision_callback_hash, real_object);
  v12 = (IVP_Real_Object *)IVP_VHash::find_elem(this: collision_callback_hash, &elem, hash_index: v11);
  real_objectb = v12;
  if ( data != &vars0 )
  {
    if ( data != nullptr )
      free(data);
    data = nullptr;
    LOWORD(v22) = 0;
  }
  HIWORD(v22) = 0;
  if ( v12 != nullptr )
  {
    v13 = (IVP_Object_Callback_Table_Hash *)this->collision_callback_hash;
    v20 = nullptr;
    v19 = 0;
    v18 = real_object;
    v14 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v13, real_object);
    IVP_VHash::remove_elem(this: v13, elem: &v18, hash_index: v14);
    if ( v20 != &elem && v20 != nullptr )
      free(data: v20);
    v15 = (IVP_Real_Object *)real_objectb->next_in_cluster;
    if ( v15 != (IVP_Real_Object *)&real_objectb->prev_in_cluster )
    {
      if ( v15 != nullptr )
        free(data: real_objectb->next_in_cluster);
      real_objectb->next_in_cluster = nullptr;
      LOWORD(real_objectb->object_type) = 0;
    }
    HIWORD(real_objectb->object_type) = 0;
    free(data: real_objectb);
  }
  if ( real_object == this->an_object_to_be_checked )
  {
    next_real_object_in_cluster_tree = IVP_Cluster_Manager::get_next_real_object_in_cluster_tree(
                                         this,
                                         object: this->an_object_to_be_checked);
    this->an_object_to_be_checked = next_real_object_in_cluster_tree;
    if ( real_object == next_real_object_in_cluster_tree )
      this->an_object_to_be_checked = nullptr;
  }
  universe_manager = this->environment->universe_manager;
  if ( universe_manager != nullptr )
    universe_manager->event_object_deleted(this: universe_manager, a2: real_object);
}

//------------------------------------------------------------------------------
// Address: 0x1007F1D0
// Name: public: enum IVP_BOOL IVP_Core::revive_simulation_core(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IVP_BOOL __usercall IVP_Core::revive_simulation_core@<eax>(IVP_Core *this@<ecx>, IVP_BOOL a2@<ebp>)
{
  int i; // eax
  _BYTE *v4; // edx
  IVP_Environment *environment; // eax
  int seconds_high; // edx
  float v7; // xmm0_4
  IVP_BOOL result; // eax
  bool v9; // sf
  int v10; // ecx
  int v11; // edi
  IVP_Environment *v12; // eax
  IVP_Environment *v13; // ecx
  float v14[3]; // [esp-Ch] [ebp-4Ch] BYREF
  _BYTE v15[40]; // [esp+4h] [ebp-3Ch] OVERLAPPED BYREF
  int v16; // [esp+2Ch] [ebp-14h]
  char v17; // [esp+33h] [ebp-Dh]
  IVP_BOOL fs_was_grown; // [esp+34h] [ebp-Ch]
  int d; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  fs_was_grown = a2;
  d = retaddr;
  for ( i = this->objects.n_elems - 1; i >= 0; v4[68] = 1 )
    v4 = this->objects.elems[i--];
  memset(v15, 0, 12);
  if ( this->time_of_last_psi.seconds == 0.0 )
  {
    *(IVP_U_Float_Point *)v15 = this->speed;
    *(_QWORD *)&v15[16] = *(_QWORD *)this->rot_speed.k;
    v17 = 1;
    *(_QWORD *)&v15[24] = *(_QWORD *)&this->rot_speed.k[2];
  }
  else
  {
    v17 = 0;
  }
  IVP_Core::init_core_for_simulation(this);
  environment = this->environment;
  seconds_high = HIDWORD(environment->time_of_next_psi.seconds);
  *(_DWORD *)&v15[32] = LODWORD(environment->time_of_next_psi.seconds);
  *(_DWORD *)&v15[36] = seconds_high;
  v7 = *(double *)&v15[32] - environment->current_time.seconds;
  LODWORD(v14[2]) = environment;
  v14[0] = v7;
  if ( v7 <= 1.0e-10 )
    v14[1] = 1.0e10;
  else
    v14[1] = 1.0 / v7;
  IVP_Core::calc_next_PSI_matrix_zero_speed(this, es: (IVP_Event_Sim *)v14);
  if ( v17 != 0 )
  {
    *(_QWORD *)this->speed.k = *(_QWORD *)v15;
    *(_QWORD *)&this->speed.k[2] = *(_QWORD *)&v15[8];
    *(_QWORD *)this->rot_speed.k = *(_QWORD *)&v15[16];
    *(_QWORD *)&this->rot_speed.k[2] = *(_QWORD *)&v15[24];
  }
  result = IVP_Core::grow_friction_system(this);
  v10 = this->objects.n_elems - 1;
  v9 = this->objects.n_elems == 0;
  *(_DWORD *)&v15[36] = result;
  v16 = v10;
  if ( !v9 )
  {
    while ( 1 )
    {
      v12 = this->environment;
      *(_DWORD *)&v15[28] = this->objects.elems[v10];
      v11 = *(_DWORD *)&v15[28];
      *(_DWORD *)&v15[24] = v12;
      IVP_Cluster_Manager::fire_event_object_revived(
        this: v12->cluster_manager,
        event_obj: (IVP_Event_Object *)&v15[24]);
      v13 = this->environment;
      *(_DWORD *)&v15[12] = v11;
      *(_DWORD *)&v15[8] = v13;
      IVP_Environment::fire_event_object_revived(this: v13, obj_event: (IVP_Event_Object *)&v15[8]);
      if ( --v16 < 0 )
        break;
      v10 = v16;
    }
    return *(_DWORD *)&v15[36];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F380
// Name: public: void IVP_Core::fire_event_object_frozen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::fire_event_object_frozen(IVP_Core *this)
{
  IVP_Core *v1; // ebx
  bool v2; // sf
  int v3; // eax
  IVP_Real_Object *v4; // esi
  IVP_Environment *environment; // eax
  IVP_Cluster_Manager *cluster_manager; // eax
  IVP_Object_Callback_Table_Hash *obj_callback_hash; // edi
  unsigned int v8; // eax
  _DWORD *v9; // edi
  int v10; // ebx
  int v11; // ecx
  IVP_Object_Callback_Table_Hash *v12; // edi
  unsigned int v13; // eax
  void *v14; // edi
  IVP_Environment *v15; // ecx
  IVP_Real_Object *v16; // [esp+4h] [ebp-38h] BYREF
  int v17; // [esp+8h] [ebp-34h]
  void *v18; // [esp+Ch] [ebp-30h]
  IVP_Real_Object *elem; // [esp+10h] [ebp-2Ch] BYREF
  int v20; // [esp+14h] [ebp-28h]
  void *data; // [esp+18h] [ebp-24h]
  IVP_Event_Object obj_event; // [esp+1Ch] [ebp-20h] BYREF
  IVP_Event_Object event_frozen; // [esp+24h] [ebp-18h] BYREF
  IVP_Core *v24; // [esp+2Ch] [ebp-10h]
  _DWORD *v25; // [esp+30h] [ebp-Ch]
  IVP_Cluster_Manager *v26; // [esp+34h] [ebp-8h]
  int i; // [esp+38h] [ebp-4h]

  v1 = this;
  v3 = this->objects.n_elems - 1;
  v2 = this->objects.n_elems == 0;
  v24 = this;
  i = v3;
  if ( !v2 )
  {
    while ( 1 )
    {
      v4 = (IVP_Real_Object *)v1->objects.elems[v3];
      environment = v1->environment;
      event_frozen.real_object = v4;
      event_frozen.environment = environment;
      cluster_manager = environment->cluster_manager;
      obj_callback_hash = cluster_manager->obj_callback_hash;
      v26 = cluster_manager;
      v20 = 0;
      data = nullptr;
      elem = v4;
      v8 = IVP_Collision_Callback_Table_Hash::object_to_index(this: obj_callback_hash, real_object: v4);
      v9 = IVP_VHash::find_elem(this: obj_callback_hash, &elem, hash_index: v8);
      v25 = v9;
      if ( data != &obj_event )
      {
        if ( data != nullptr )
          free(data);
        data = nullptr;
        LOWORD(v20) = 0;
      }
      HIWORD(v20) = 0;
      if ( v9 != nullptr )
      {
        v10 = *((unsigned __int16 *)v9 + 3) - 1;
        if ( *((_WORD *)v9 + 3) != 0 )
        {
          do
          {
            v11 = *(_DWORD *)(v9[2] + 4 * v10);
            (*(void (__thiscall **)(int, IVP_Event_Object *))(*(_DWORD *)v11 + 12))(a1: v11, a2: &event_frozen);
            if ( v10 > 0 )
            {
              v12 = v26->obj_callback_hash;
              v17 = 0;
              v18 = nullptr;
              v16 = v4;
              v13 = IVP_Collision_Callback_Table_Hash::object_to_index(this: v12, real_object: v4);
              v14 = IVP_VHash::find_elem(this: v12, elem: &v16, hash_index: v13);
              if ( v18 != &elem )
              {
                if ( v18 != nullptr )
                  free(data: v18);
                v18 = nullptr;
                LOWORD(v17) = 0;
              }
              HIWORD(v17) = 0;
              if ( v14 == nullptr )
                break;
              v9 = v25;
            }
            --v10;
          }
          while ( v10 >= 0 );
        }
        v1 = v24;
      }
      v15 = v1->environment;
      obj_event.real_object = v4;
      obj_event.environment = v15;
      IVP_Environment::fire_event_object_frozen(this: v15, &obj_event);
      if ( --i < 0 )
        break;
      v3 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F4B0
// Name: public: void IVP_Core::freeze_simulation_core(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::freeze_simulation_core(IVP_Core *this)
{
  IVP_Core::stop_physical_movement(this);
  IVP_Core::fire_event_object_frozen(this);
}
