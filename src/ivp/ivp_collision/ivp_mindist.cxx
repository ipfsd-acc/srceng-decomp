// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_mindist.cxx
// Functions: 41
// ============================================================

#include "ivp\ivp_collision\ivp_mindist.h"

//------------------------------------------------------------------------------
// Address: 0x1008DED0
// Name: public: virtual void IVP_Collision::delegator_is_going_to_be_deleted_event(class IVP_Collision_Delegator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision::delegator_is_going_to_be_deleted_event(
        IVP_Collision *this,
        IVP_Collision_Delegator *__formal)
{
  if ( this != nullptr )
    ((void (__thiscall *)(IVP_Collision *, int))this->dtr_IVP_Collision)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1008DF40
// Name: public: void IVP_Mindist_Settings::set_collision_tolerance(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Settings::set_collision_tolerance(IVP_Mindist_Settings *this, float t, float gravLength)
{
  float v3; // xmm0_4
  int v4; // eax
  float *v5; // edx
  float v6; // xmm3_4
  float min_coll_dists; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm0_4

  this->real_coll_dist = t * 0.1;
  v3 = (float)(t * 0.89999998) + (float)(t * 0.1);
  this->min_coll_dists = v3;
  this->minimum_friction_dist = (float)(t * 0.0) + v3;
  v4 = 61;
  v5 = &this->coll_dists[62];
  do
  {
    v5[1] = (float)((float)((float)(v4 + 2) * 0.015625) * (float)(this->minimum_friction_dist - this->min_coll_dists))
          + this->min_coll_dists;
    *v5 = (float)((float)((float)(v4 + 1) * 0.015625) * (float)(this->minimum_friction_dist - this->min_coll_dists))
        + this->min_coll_dists;
    *(v5 - 1) = (float)((float)((float)v4 * 0.015625) * (float)(this->minimum_friction_dist - this->min_coll_dists))
              + this->min_coll_dists;
    *(v5 - 2) = (float)((float)((float)(v4 - 1) * 0.015625) * (float)(this->minimum_friction_dist - this->min_coll_dists))
              + this->min_coll_dists;
    *(v5 - 3) = (float)((float)((float)(v4 - 2) * 0.015625) * (float)(this->minimum_friction_dist - this->min_coll_dists))
              + this->min_coll_dists;
    *(v5 - 4) = (float)((float)((float)(v4 - 3) * 0.015625) * (float)(this->minimum_friction_dist - this->min_coll_dists))
              + this->min_coll_dists;
    *(v5 - 5) = (float)((float)((float)(v4 - 4) * 0.015625) * (float)(this->minimum_friction_dist - this->min_coll_dists))
              + this->min_coll_dists;
    v6 = (float)(v4 - 5) * 0.015625;
    v4 -= 8;
    *(v5 - 6) = (float)(v6 * (float)(this->minimum_friction_dist - this->min_coll_dists)) + this->min_coll_dists;
    v5 -= 8;
  }
  while ( v4 + 2 >= 0 );
  min_coll_dists = this->min_coll_dists;
  v8 = this->minimum_friction_dist + t;
  v9 = (float)(t * 0.30000001) + v8;
  this->keeper_dist = v9;
  this->speed_after_keeper_dist = fsqrt((float)((float)(v9 - min_coll_dists) * 2.0) * gravLength);
  this->distance_keepers_safety = t * 0.0099999998;
  this->max_distance_for_friction = (float)(t * 2.5) + v8;
  this->friction_dist = v8;
  this->max_distance_for_impact_system = (float)(t * 20.0) + v8;
  this->min_vertical_speed_at_collision = t * 2.0;
  this->mindist_change_force_dist = min_coll_dists * 0.1;
}

//------------------------------------------------------------------------------
// Address: 0x1008E1B0
// Name: public: virtual void IVP_Mindist_Base::get_objects(class IVP_Real_Object __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Base::get_objects(IVP_Mindist_Base *this, IVP_Real_Object **objects_out)
{
  *objects_out = this->synapse[0].l_obj;
  objects_out[1] = this->synapse[1].l_obj;
}

//------------------------------------------------------------------------------
// Address: 0x1008E1D0
// Name: public: virtual void IVP_Mindist_Base::get_ledges(class IVP_Compact_Ledge const __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Base::get_ledges(IVP_Mindist_Base *this, const IVP_Compact_Ledge **ledges_out)
{
  *ledges_out = (const IVP_Compact_Ledge *)(((int)this->synapse[0].edge & 0xFFFFFFF0)
                                          - 16 * ((*(_DWORD *)((int)this->synapse[0].edge & 0xFFFFFFF0) & 0xFFF) + 1));
  ledges_out[1] = (const IVP_Compact_Ledge *)(((int)this->synapse[1].edge & 0xFFFFFFF0)
                                            - 16 * ((*(_DWORD *)((int)this->synapse[1].edge & 0xFFFFFFF0) & 0xFFF) + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1008E210
// Name: public: class IVP_Compact_Ledge const __near * IVP_Synapse::get_ledge(void)const
// Source: json
//------------------------------------------------------------------------------
const IVP_Compact_Ledge *__thiscall IVP_Synapse::get_ledge(IVP_Synapse *this)
{
  return (const IVP_Compact_Ledge *)(((int)this->edge & 0xFFFFFFF0)
                                   - 16 * ((*(_DWORD *)((int)this->edge & 0xFFFFFFF0) & 0xFFF) + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1008E230
// Name: public: void IVP_Mindist_Manager::insert_invalid_mindist(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::insert_invalid_mindist(IVP_Mindist_Manager *this, IVP_Mindist *new_mindist)
{
  IVP_Mindist *invalid_mindists; // edx
  IVP_Synapse_Real *invalid_synapses; // edx
  IVP_Synapse *synapse; // ecx
  IVP_Real_Object *l_obj; // edx
  IVP_Synapse *v6; // eax
  IVP_Synapse_Real *v7; // ecx
  IVP_Real_Object *v8; // edx

  *((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) = *((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) & 0xFFC3FFFF
                                                  | 0x80000;
  invalid_mindists = this->invalid_mindists;
  new_mindist->next = invalid_mindists;
  new_mindist->prev = nullptr;
  if ( invalid_mindists != nullptr )
    invalid_mindists->prev = new_mindist;
  this->invalid_mindists = new_mindist;
  invalid_synapses = new_mindist->synapse[0].l_obj->invalid_synapses;
  synapse = new_mindist->synapse;
  new_mindist->synapse[0].next = invalid_synapses;
  if ( invalid_synapses != nullptr )
    invalid_synapses->prev = synapse;
  l_obj = new_mindist->synapse[0].l_obj;
  new_mindist->synapse[0].prev = nullptr;
  v6 = &new_mindist->synapse[1];
  l_obj->invalid_synapses = (IVP_Synapse_Real *)synapse;
  v7 = new_mindist->synapse[1].l_obj->invalid_synapses;
  new_mindist->synapse[1].next = v7;
  if ( v7 != nullptr )
    v7->prev = v6;
  v8 = new_mindist->synapse[1].l_obj;
  new_mindist->synapse[1].prev = nullptr;
  v8->invalid_synapses = (IVP_Synapse_Real *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x1008E2B0
// Name: protected: virtual void IVP_Synapse::hull_manager_is_going_to_be_deleted_event(class IVP_Hull_Manager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Synapse::hull_manager_is_going_to_be_deleted_event(IVP_Synapse *this, IVP_Hull_Manager *__formal)
{
  char *v2; // eax

  v2 = (char *)this + this->mindist_offset;
  if ( v2 != nullptr )
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)v2 + 16))(a1: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1008E2D0
// Name: public: void IVP_Mindist::create_cp_in_advance_pretension(class IVP_Real_Object __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::create_cp_in_advance_pretension(
        IVP_Mindist *this,
        IVP_Real_Object *robject,
        float gap_len)
{
  IVP_Synapse_Friction *friction_synapses; // esi
  IVP_Contact_Point *v4; // edi
  IVP_Contact_Point *v5; // esi
  IVP_Synapse_Friction *seconds_high; // edx
  IVP_Environment *environment; // eax
  int v8; // eax
  IVP_Synapse_Friction *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm4_4
  float *k; // eax
  IVP_Mindist *v13; // ecx
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float *v19; // eax
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  IVP_Real_Object *l_obj; // ecx
  IVP_U_Memory *sim_unit_mem; // ecx
  IVP_Friction_System *associated_fs; // [esp+4h] [ebp-14h] BYREF
  IVP_Mindist *v29; // [esp+8h] [ebp-10h]
  int seconds_low; // [esp+Ch] [ebp-Ch]
  IVP_Synapse_Friction *old_fr_syn; // [esp+10h] [ebp-8h]
  IVP_BOOL success; // [esp+14h] [ebp-4h] BYREF
  IVP_Compact_Edge savedregs; // [esp+18h] [ebp+0h] BYREF

  friction_synapses = robject->friction_synapses;
  v29 = this;
  old_fr_syn = friction_synapses;
  if ( friction_synapses != nullptr )
  {
    ++robject->environment->sim_unit_mem->transaction_in_use;
    v4 = IVP_Mindist::try_to_generate_managed_friction(
           this,
           &associated_fs,
           having_new: &success,
           sim_unit_not_destroy: nullptr,
           call_recalc_svals: IVP_TRUE);
    if ( success == IVP_TRUE )
    {
      v5 = (IVP_Contact_Point *)((char *)old_fr_syn + friction_synapses->contact_point_offset);
      seconds_high = (IVP_Synapse_Friction *)HIDWORD(v5->last_time_of_recalc_friction_s_vals.seconds);
      seconds_low = LODWORD(v5->last_time_of_recalc_friction_s_vals.seconds);
      environment = robject->environment;
      old_fr_syn = seconds_high;
      v5->last_time_of_recalc_friction_s_vals = environment->current_time;
      IVP_Contact_Point::recalc_friction_s_vals(this: v5, a2: &savedregs, env: robject->environment);
      v4->now_friction_pressure = v5->now_friction_pressure;
      v8 = seconds_low;
      v9 = old_fr_syn;
      v5->now_friction_pressure = 0.0;
      LODWORD(v4->last_time_of_recalc_friction_s_vals.seconds) = v8;
      v4->last_gap_len = gap_len;
      HIDWORD(v4->last_time_of_recalc_friction_s_vals.seconds) = v9;
      v10 = v5->span_friction_s[0];
      v11 = v5->span_friction_s[1];
      LODWORD(v5->last_time_of_recalc_friction_s_vals.seconds) = v8;
      k = v5->tmp_contact_info->contact_point_ws.k;
      HIDWORD(v5->last_time_of_recalc_friction_s_vals.seconds) = v9;
      v13 = v29;
      v14 = k[34] * v10;
      v15 = k[33] * v10;
      v16 = (float)(k[36] * v11) + (float)(k[32] * v10);
      v17 = (float)(k[37] * v11) + v15;
      v18 = k[38];
      v19 = v4->tmp_contact_info->contact_point_ws.k;
      v20 = (float)(v18 * v11) + v14;
      v21 = (float)((float)(v19[37] * v17) + (float)(v19[36] * v16)) + (float)(v19[38] * v20);
      v22 = v19[33] * v17;
      v23 = v19[32] * v16;
      v24 = v19[34] * v20;
      v4->span_friction_s[1] = v21;
      v4->span_friction_s[0] = (float)(v22 + v23) + v24;
      l_obj = v13->synapse[((*((_DWORD *)&v13->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].l_obj;
      if ( l_obj->flags == 8 )
        IVP_Real_Object::ensure_in_simulation_now(this: l_obj);
    }
    sim_unit_mem = robject->environment->sim_unit_mem;
    if ( sim_unit_mem->transaction_in_use-- == 1 )
      IVP_U_Memory::free_mem_transaction(this: sim_unit_mem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E490
// Name: public: void IVP_Mindist_Manager::remove_invalid_mindist(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::remove_invalid_mindist(IVP_Mindist_Manager *this, IVP_Mindist *del_mindist)
{
  IVP_Mindist *next; // edx
  IVP_Mindist *prev; // edx
  IVP_Synapse *v4; // ecx
  IVP_Synapse *v5; // ecx
  IVP_Synapse_Real *v6; // edx
  IVP_Synapse *v7; // ecx
  IVP_Synapse *v8; // ecx

  next = del_mindist->next;
  if ( next != nullptr )
    next->prev = del_mindist->prev;
  prev = del_mindist->prev;
  if ( prev != nullptr )
    prev->next = del_mindist->next;
  else
    this->invalid_mindists = del_mindist->next;
  v4 = del_mindist->synapse[0].next;
  if ( v4 != nullptr )
    v4->prev = del_mindist->synapse[0].prev;
  v5 = del_mindist->synapse[0].prev;
  v6 = (IVP_Synapse_Real *)del_mindist->synapse[0].next;
  if ( v5 != nullptr )
    v5->next = v6;
  else
    del_mindist->synapse[0].l_obj->invalid_synapses = v6;
  v7 = del_mindist->synapse[1].next;
  if ( v7 != nullptr )
    v7->prev = del_mindist->synapse[1].prev;
  v8 = del_mindist->synapse[1].prev;
  if ( v8 != nullptr )
    v8->next = del_mindist->synapse[1].next;
  else
    del_mindist->synapse[1].l_obj->invalid_synapses = (IVP_Synapse_Real *)del_mindist->synapse[1].next;
}

//------------------------------------------------------------------------------
// Address: 0x1008E510
// Name: public: void IVP_Mindist_Manager::remove_hull_mindist(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::remove_hull_mindist(IVP_Mindist_Manager *this, IVP_Mindist *del_mindist)
{
  IVP_U_Min_List::remove_minlist_elem(
    this: &del_mindist->synapse[0].l_obj->hull_manager.sorted_synapses,
    index: del_mindist->synapse[0].minlist_index);
  IVP_U_Min_List::remove_minlist_elem(
    this: &del_mindist->synapse[1].l_obj->hull_manager.sorted_synapses,
    index: del_mindist->synapse[1].minlist_index);
}

//------------------------------------------------------------------------------
// Address: 0x1008E540
// Name: public: static void IVP_Mindist_Manager::insert_hull_mindist(class IVP_Mindist __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Manager::insert_hull_mindist(IVP_Mindist *md, float hull_time0, float hull_time1)
{
  IVP_Real_Object *l_obj; // esi
  IVP_Synapse *synapse; // ebx
  float v6; // xmm0_4
  float v7; // xmm1_4
  IVP_Real_Object *v8; // esi
  float mda; // [esp+20h] [ebp+8h]
  float mdb; // [esp+20h] [ebp+8h]

  *((_DWORD *)&md->IVP_Mindist_Base + 5) = *((_DWORD *)&md->IVP_Mindist_Base + 5) & 0xFFC3FFFF | 0x140000;
  l_obj = md->synapse[0].l_obj;
  synapse = md->synapse;
  mda = l_obj->environment->current_time.seconds - l_obj->hull_manager.last_vpsi_time.seconds;
  md->synapse[0].minlist_index = IVP_U_Min_List::add(
                                   this: &l_obj->hull_manager.sorted_synapses,
                                   elem: synapse,
                                   value: (float)((float)(mda * l_obj->hull_manager.gradient)
                                         + l_obj->hull_manager.hull_value_last_vpsi)
                                 + hull_time0);
  v6 = (float)(l_obj->hull_manager.gradient - l_obj->hull_manager.center_gradient) * mda;
  v7 = l_obj->hull_manager.hull_value_last_vpsi - l_obj->hull_manager.hull_center_value_last_vpsi;
  v8 = md->synapse[1].l_obj;
  mdb = v8->environment->current_time.seconds - v8->hull_manager.last_vpsi_time.seconds;
  md->synapse[1].minlist_index = IVP_U_Min_List::add(
                                   this: &v8->hull_manager.sorted_synapses,
                                   elem: &md->synapse[1],
                                   value: (float)((float)(v8->hull_manager.gradient * mdb)
                                         + v8->hull_manager.hull_value_last_vpsi)
                                 + hull_time1);
  md->sum_angular_hull_time = (float)((float)((float)(v8->hull_manager.gradient - v8->hull_manager.center_gradient) * mdb)
                                    + (float)(v8->hull_manager.hull_value_last_vpsi
                                            - v8->hull_manager.hull_center_value_last_vpsi))
                            + (float)(v6 + v7);
}

//------------------------------------------------------------------------------
// Address: 0x1008E650
// Name: public: static void IVP_Mindist_Manager::insert_hull_mindist(class IVP_Mindist __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Manager::insert_hull_mindist(IVP_Mindist *md, float hull_time)
{
  IVP_Real_Object *l_obj; // eax
  IVP_Real_Object *v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm0_4

  l_obj = md->synapse[0].l_obj;
  v3 = md->synapse[1].l_obj;
  if ( (*(_BYTE *)&l_obj->flags & 7) != 0 )
  {
    if ( (*(_BYTE *)&v3->flags & 7) != 0 )
    {
      v4 = (float)(v3->physical_core->max_surface_rot_speed + v3->physical_core->current_speed) + 1.0e-10;
      v5 = (float)(l_obj->physical_core->max_surface_rot_speed + l_obj->physical_core->current_speed) + 1.0e-10;
      IVP_Mindist_Manager::insert_hull_mindist(
        md,
        hull_time0: (float)(hull_time / (float)((float)((float)(v5 * 0.1) + v4) + (float)((float)(v4 * 0.1) + v5)))
      * (float)((float)(v4 * 0.1) + v5),
        hull_time1: (float)(hull_time / (float)((float)((float)(v5 * 0.1) + v4) + (float)((float)(v4 * 0.1) + v5)))
      * (float)((float)(v5 * 0.1) + v4));
    }
    else
    {
      IVP_Mindist_Manager::insert_hull_mindist(md, hull_time0: hull_time, hull_time1: 0.0);
    }
  }
  else
  {
    IVP_Mindist_Manager::insert_hull_mindist(md, hull_time0: 0.0, hull_time1: hull_time);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E730
// Name: public: static void IVP_Mindist_Manager::insert_lazy_hull_mindist(class IVP_Mindist __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Manager::insert_lazy_hull_mindist(IVP_Mindist *md, float hull_time)
{
  IVP_Real_Object *l_obj; // eax
  IVP_Real_Object *v4; // ecx
  IVP_Synapse *synapse; // edi
  IVP_Real_Object *v6; // eax
  float value; // xmm0_4
  IVP_Synapse *v8; // esi
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float speed_corr_1; // [esp+Ch] [ebp-4h]
  float factor; // [esp+18h] [ebp+8h]

  l_obj = md->synapse[0].l_obj;
  v4 = md->synapse[1].l_obj;
  synapse = md->synapse;
  if ( (*(_BYTE *)&l_obj->flags & 7) != 0 )
  {
    if ( (*(_BYTE *)&v4->flags & 7) != 0 )
    {
      v9 = (float)(v4->physical_core->max_surface_rot_speed + v4->physical_core->current_speed) + 1.0e-10;
      v10 = (float)(l_obj->physical_core->max_surface_rot_speed + l_obj->physical_core->current_speed) + 1.0e-10;
      v11 = (float)(v9 * 0.1) + v10;
      speed_corr_1 = (float)(v10 * 0.1) + v9;
      *((_DWORD *)&md->IVP_Mindist_Base + 5) = *((_DWORD *)&md->IVP_Mindist_Base + 5) & 0xFFC3FFFF | 0x140000;
      factor = hull_time / (float)(speed_corr_1 + v11);
      synapse->minlist_index = IVP_U_Min_List::add(
                                 this: &synapse->l_obj->hull_manager.sorted_synapses,
                                 elem: synapse,
                                 value: (float)(factor * v11) + synapse->l_obj->hull_manager.hull_value_next_psi);
      v6 = md->synapse[1].l_obj;
      value = (float)(factor * speed_corr_1) + v6->hull_manager.hull_value_next_psi;
    }
    else
    {
      *((_DWORD *)&md->IVP_Mindist_Base + 5) = *((_DWORD *)&md->IVP_Mindist_Base + 5) & 0xFFC3FFFF | 0x140000;
      md->synapse[0].minlist_index = IVP_U_Min_List::add(
                                       this: &md->synapse[0].l_obj->hull_manager.sorted_synapses,
                                       elem: md->synapse,
                                       value: md->synapse[0].l_obj->hull_manager.hull_value_next_psi + hull_time);
      v6 = md->synapse[1].l_obj;
      value = v6->hull_manager.hull_value_next_psi + 1.0e-10;
    }
    v8 = &md->synapse[1];
  }
  else
  {
    *((_DWORD *)&md->IVP_Mindist_Base + 5) = *((_DWORD *)&md->IVP_Mindist_Base + 5) & 0xFFC3FFFF | 0x140000;
    md->synapse[0].minlist_index = IVP_U_Min_List::add(
                                     this: &md->synapse[0].l_obj->hull_manager.sorted_synapses,
                                     elem: md->synapse,
                                     value: md->synapse[0].l_obj->hull_manager.hull_value_next_psi + 1.0e-10);
    v6 = md->synapse[1].l_obj;
    value = v6->hull_manager.hull_value_next_psi + hull_time;
    v8 = &md->synapse[1];
  }
  v8->minlist_index = IVP_U_Min_List::add(this: &v6->hull_manager.sorted_synapses, elem: v8, value);
}

//------------------------------------------------------------------------------
// Address: 0x1008E8B0
// Name: public: static void IVP_Mindist_Manager::mindist_entered_phantom(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Manager::mindist_entered_phantom(IVP_Mindist *mdist)
{
  int v1; // eax
  IVP_Controller_Phantom *controller_phantom; // ecx
  IVP_Controller_Phantom *v3; // ecx

  v1 = *((_DWORD *)&mdist->IVP_Mindist_Base + 5);
  if ( (v1 & 0xC00) == 0 )
  {
    *((_DWORD *)&mdist->IVP_Mindist_Base + 5) = v1 & 0xFFFCF3FF | 0x10400;
    controller_phantom = mdist->synapse[0].l_obj->controller_phantom;
    if ( controller_phantom != nullptr )
      IVP_Controller_Phantom::mindist_entered_volume(this: controller_phantom, mindist: mdist);
    v3 = mdist->synapse[1].l_obj->controller_phantom;
    if ( v3 != nullptr )
      IVP_Controller_Phantom::mindist_entered_volume(this: v3, mindist: mdist);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E900
// Name: public: static void IVP_Mindist_Manager::mindist_left_phantom(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Mindist_Manager::mindist_left_phantom(IVP_Mindist *mdist)
{
  int v1; // eax
  IVP_Controller_Phantom *controller_phantom; // ecx
  IVP_Controller_Phantom *v3; // ecx

  v1 = *((_DWORD *)&mdist->IVP_Mindist_Base + 5);
  if ( (v1 & 0xC00) != 0 )
  {
    *((_DWORD *)&mdist->IVP_Mindist_Base + 5) = v1 & 0xFFFCF3FF;
    controller_phantom = mdist->synapse[0].l_obj->controller_phantom;
    if ( controller_phantom != nullptr )
      IVP_Controller_Phantom::mindist_left_volume(this: controller_phantom, mindist: mdist);
    v3 = mdist->synapse[1].l_obj->controller_phantom;
    if ( v3 != nullptr )
      IVP_Controller_Phantom::mindist_left_volume(this: v3, mindist: mdist);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E940
// Name: public: IVP_Diff_Hash<class IVP_MM_CMP,class IVP_U_FVector<class IVP_Collision>,class IVP_Collision,class IVP_MM_CMP_Key>::IVP_Diff_Hash<class IVP_MM_CMP,class IVP_U_FVector<class IVP_Collision>,class IVP_Collision,class IVP_MM_CMP_Key>(class IVP_U_FVector<class IVP_Collision> __near *,short __near *,int,class IVP_MM_CMP_Key __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key> *__thiscall IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key>::IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key>(
        IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key> *this,
        IVP_U_FVector<IVP_Collision> *base,
        __int16 *buffer,
        int buffer_size,
        IVP_MM_CMP_Key *reference)
{
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  IVP_U_FVector<IVP_Collision> *base_vector; // edx
  int v10; // edi
  void *v11; // ecx
  int v12; // eax
  __int16 *i; // ecx
  int v15; // [esp+Ch] [ebp-8h] BYREF
  int v16; // [esp+10h] [ebp-4h]

  v6 = buffer_size;
  if ( buffer_size > base->n_elems )
  {
    this->buffersize_minus_one = buffer_size - 1;
    this->private_buffer = IVP_FALSE;
    this->hash_to_vector_index = buffer;
  }
  else
  {
    this->private_buffer = IVP_TRUE;
    v7 = 2 * base->n_elems;
    if ( buffer_size <= v7 )
    {
      do
        v6 *= 2;
      while ( v6 <= v7 );
    }
    this->buffersize_minus_one = v6 - 1;
    this->hash_to_vector_index = (__int16 *)p_malloc(size: 2 * v6);
  }
  v8 = 0;
  this->n_found_objects = 0;
  for ( this->base_vector = base; v8 <= this->buffersize_minus_one; ++v8 )
    this->hash_to_vector_index[v8] = -1;
  base_vector = this->base_vector;
  v10 = base_vector->n_elems - 1;
  if ( base_vector->n_elems != 0 )
  {
    do
    {
      v11 = this->base_vector->elems[v10];
      (*(void (__thiscall **)(void *, int *))(*(_DWORD *)v11 + 8))(a1: v11, a2: &v15);
      v12 = this->buffersize_minus_one & ((v15 ^ (75 * v16)) + 1023 * ((v15 ^ (75 * v16)) >> 8));
      for ( i = this->hash_to_vector_index; i[v12] != -1; v12 = this->buffersize_minus_one & (v12 + 1) )
        ;
      i[v12] = v10--;
    }
    while ( v10 >= 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008EA20
// Name: public: IVP_Diff_Hash<class IVP_OO_CMP,class IVP_U_FVector<class IVP_Collision>,class IVP_Collision,class IVP_Real_Object>::IVP_Diff_Hash<class IVP_OO_CMP,class IVP_U_FVector<class IVP_Collision>,class IVP_Collision,class IVP_Real_Object>(class IVP_U_FVector<class IVP_Collision> __near *,short __near *,int,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object> *__thiscall IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object>::IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object>(
        IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object> *this,
        IVP_U_FVector<IVP_Collision> *base,
        __int16 *buffer,
        int buffer_size,
        IVP_Real_Object *reference)
{
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  IVP_U_FVector<IVP_Collision> *base_vector; // edx
  int v10; // edi
  void *v11; // ecx
  unsigned int v12; // eax
  __int16 *i; // ecx
  int v15; // [esp+Ch] [ebp-8h] BYREF
  int v16; // [esp+10h] [ebp-4h]

  v6 = buffer_size;
  if ( buffer_size > base->n_elems )
  {
    this->buffersize_minus_one = buffer_size - 1;
    this->private_buffer = IVP_FALSE;
    this->hash_to_vector_index = buffer;
  }
  else
  {
    this->private_buffer = IVP_TRUE;
    v7 = 2 * base->n_elems;
    if ( buffer_size <= v7 )
    {
      do
        v6 *= 2;
      while ( v6 <= v7 );
    }
    this->buffersize_minus_one = v6 - 1;
    this->hash_to_vector_index = (__int16 *)p_malloc(size: 2 * v6);
  }
  v8 = 0;
  this->n_found_objects = 0;
  for ( this->base_vector = base; v8 <= this->buffersize_minus_one; ++v8 )
    this->hash_to_vector_index[v8] = -1;
  base_vector = this->base_vector;
  v10 = base_vector->n_elems - 1;
  if ( base_vector->n_elems != 0 )
  {
    do
    {
      v11 = this->base_vector->elems[v10];
      (*(void (__thiscall **)(void *, int *))(*(_DWORD *)v11 + 4))(a1: v11, a2: &v15);
      v12 = this->buffersize_minus_one
          & (((unsigned int)reference ^ v15 ^ v16) + 1023 * ((int)((unsigned int)reference ^ v15 ^ v16) >> 8));
      for ( i = this->hash_to_vector_index; i[v12] != -1; v12 = this->buffersize_minus_one & (v12 + 1) )
        ;
      i[v12] = v10--;
    }
    while ( v10 >= 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008EB40
// Name: public: IVP_Mindist::IVP_Mindist(class IVP_Environment __near *,class IVP_Collision_Delegator __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Mindist *__thiscall IVP_Mindist::IVP_Mindist(
        IVP_Mindist *this,
        IVP_Environment *my_env,
        IVP_Collision_Delegator *del)
{
  this->delegator = del;
  this->fvector_index[1] = -1;
  this->fvector_index[0] = -1;
  this->synapse[0].__vftable = (IVP_Synapse_vtbl *)&IVP_Synapse::`vftable';
  this->synapse[1].__vftable = (IVP_Synapse_vtbl *)&IVP_Synapse::`vftable';
  *((_BYTE *)&this->IVP_Mindist_Base + 20) = 0;
  *((_DWORD *)&this->IVP_Mindist_Base + 5) = *((_DWORD *)&this->IVP_Mindist_Base + 5) & 0xC00000FF | 0xFC00000;
  this->recalc_time_stamp = 0;
  this->last_visited_triangle = nullptr;
  this->sum_angular_hull_time = 0.0;
  this->index = 0xFFFF;
  this->__vftable = (IVP_Mindist_vtbl *)&IVP_Mindist::`vftable';
  ++my_env->statistic_manager.sum_of_mindists;
  ++my_env->statistic_manager.mindists_generated;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008EBB0
// Name: protected: virtual void IVP_Synapse::hull_manager_is_reset(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Synapse::hull_manager_is_reset(IVP_Synapse *this, float dt, float center_dt)
{
  *(float *)((char *)this + this->mindist_offset + 88) = (float)(dt - center_dt)
                                                       + *(float *)((char *)this + this->mindist_offset + 88);
}

//------------------------------------------------------------------------------
// Address: 0x1008EBE0
// Name: public: void IVP_Mindist_Manager::remove_exact_mindist(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::remove_exact_mindist(IVP_Mindist_Manager *this, IVP_Mindist *del_mindist)
{
  IVP_Mindist *next; // eax
  IVP_Mindist *prev; // eax
  IVP_Synapse *v5; // eax
  IVP_Synapse *v6; // eax
  IVP_Synapse *v7; // eax
  IVP_Synapse *v8; // eax
  int v9; // eax
  IVP_Mindist **i; // ecx

  if ( del_mindist->index != 0xFFFF )
  {
    IVP_Time_Manager::remove_event(this: this->environment->time_manager, event: del_mindist);
    del_mindist->index = 0xFFFF;
  }
  next = del_mindist->next;
  if ( next != nullptr )
    next->prev = del_mindist->prev;
  prev = del_mindist->prev;
  if ( prev != nullptr )
    prev->next = del_mindist->next;
  else
    this->exact_mindists = del_mindist->next;
  v5 = del_mindist->synapse[0].next;
  if ( v5 != nullptr )
    v5->prev = del_mindist->synapse[0].prev;
  v6 = del_mindist->synapse[0].prev;
  if ( v6 != nullptr )
    v6->next = del_mindist->synapse[0].next;
  else
    del_mindist->synapse[0].l_obj->exact_synapses = (IVP_Synapse_Real *)del_mindist->synapse[0].next;
  v7 = del_mindist->synapse[1].next;
  if ( v7 != nullptr )
    v7->prev = del_mindist->synapse[1].prev;
  v8 = del_mindist->synapse[1].prev;
  if ( v8 != nullptr )
    v8->next = del_mindist->synapse[1].next;
  else
    del_mindist->synapse[1].l_obj->exact_synapses = (IVP_Synapse_Real *)del_mindist->synapse[1].next;
  v9 = this->wheel_look_ahead_mindists.n_elems - 1;
  if ( this->wheel_look_ahead_mindists.n_elems != 0 )
  {
    for ( i = (IVP_Mindist **)&this->wheel_look_ahead_mindists.elems[v9]; *i != del_mindist; --i )
    {
      if ( --v9 < 0 )
        return;
    }
    if ( v9 >= 0 )
      this->wheel_look_ahead_mindists.elems[v9] = this->wheel_look_ahead_mindists.elems[--this->wheel_look_ahead_mindists.n_elems];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008ECB0
// Name: public: void IVP_Mindist_Manager::recalc_exact_mindist(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::recalc_exact_mindist(IVP_Mindist_Manager *this, IVP_Mindist *mdist)
{
  int v4; // eax
  float len_numerator; // xmm0_4
  float sum_extra_radius; // xmm0_4
  IVP_Controller_Phantom *controller_phantom; // eax
  IVP_Real_Object *l_obj; // ecx
  float uncertanty; // [esp+14h] [ebp+8h]

  IVP_Mindist::recalc_mindist(this: mdist);
  v4 = *((_DWORD *)&mdist->IVP_Mindist_Base + 5);
  if ( (v4 & 0x3000) == 0 )
  {
    if ( (v4 & 0xC000) != 0 )
      mdist->exact_mindist_went_invalid(this: mdist, a2: this);
    return;
  }
  if ( (v4 & 0xC000) != 0 )
  {
    sum_extra_radius = mdist->sum_extra_radius;
  }
  else
  {
    len_numerator = mdist->len_numerator;
    if ( len_numerator > 0.0 )
    {
      if ( (v4 & 0xC00) != 0 )
        IVP_Mindist_Manager::mindist_left_phantom(mdist);
      return;
    }
    LODWORD(sum_extra_radius) = LODWORD(len_numerator) ^ _mask__NegFloat_;
  }
  controller_phantom = mdist->synapse[0].l_obj->controller_phantom;
  l_obj = mdist->synapse[1].l_obj;
  if ( controller_phantom != nullptr )
  {
    if ( l_obj->controller_phantom != nullptr )
      return;
  }
  else
  {
    controller_phantom = l_obj->controller_phantom;
  }
  uncertanty = controller_phantom->exit_policy_extra_radius + sum_extra_radius;
  mdist->is_recursive(this: mdist);
  if ( (*((_DWORD *)&mdist->IVP_Mindist_Base + 5) & 0xC00) == 0 )
  {
    IVP_Mindist_Manager::mindist_entered_phantom(mdist);
    IVP_Mindist_Manager::remove_exact_mindist(this, del_mindist: mdist);
    IVP_Mindist_Manager::insert_lazy_hull_mindist(md: mdist, hull_time: uncertanty);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008ED90
// Name: public: class IVP_Collision __near * IVP_Diff_Hash<class IVP_MM_CMP,class IVP_U_FVector<class IVP_Collision>,class IVP_Collision,class IVP_MM_CMP_Key>::check_element(class IVP_MM_CMP_Key __near *,class IVP_MM_CMP_Key __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Collision *__thiscall IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key>::check_element(
        IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key> *this,
        IVP_MM_CMP_Key *elem,
        IVP_MM_CMP_Key *reference)
{
  int v4; // edi
  int v5; // ebx
  void (__stdcall *v6)(unsigned int *); // eax
  int n_found_objects; // eax
  void *v9; // ecx
  int i; // eax
  int v11; // eax
  void **elems; // ecx
  _DWORD *v13; // edx
  _DWORD *v14; // edi
  unsigned int v15; // [esp+Ch] [ebp-Ch] BYREF
  const IVP_Compact_Ledge *v16; // [esp+10h] [ebp-8h]
  IVP_Collision *base_elem; // [esp+14h] [ebp-4h]
  IVP_U_FVector<IVP_Collision> *elema; // [esp+20h] [ebp+8h]

  v4 = this->buffersize_minus_one
     & (((int)elem->ledge[0] ^ (75 * (int)elem->ledge[1]))
      + 1023 * (((int)elem->ledge[0] ^ (75 * (int)elem->ledge[1])) >> 8));
  v5 = this->hash_to_vector_index[v4];
  if ( v5 == -1 )
    return nullptr;
  while ( 1 )
  {
    v6 = *(void (__stdcall **)(unsigned int *))(*(_DWORD *)this->base_vector->elems[v5] + 8);
    base_elem = (IVP_Collision *)this->base_vector->elems[v5];
    v6(a1: &v15);
    if ( (const IVP_Compact_Ledge *)v15 == elem->ledge[0] && v16 == elem->ledge[1] )
      break;
    v4 = this->buffersize_minus_one & (v4 + 1);
    v5 = this->hash_to_vector_index[v4];
    if ( v5 == -1 )
      return nullptr;
  }
  n_found_objects = this->n_found_objects;
  if ( v5 > n_found_objects )
  {
    v9 = this->base_vector->elems[n_found_objects];
    (*(void (__thiscall **)(void *, unsigned int *))(*(_DWORD *)v9 + 8))(a1: v9, a2: &v15);
    for ( i = this->buffersize_minus_one & ((v15 ^ (75 * (_DWORD)v16)) + 1023 * ((int)(v15 ^ (75 * (_DWORD)v16)) >> 8));
          this->hash_to_vector_index[i] != this->n_found_objects;
          i = this->buffersize_minus_one & (i + 1) )
    {
      ;
    }
    this->hash_to_vector_index[i] = v5;
    this->hash_to_vector_index[v4] = this->n_found_objects;
    v11 = this->n_found_objects;
    elema = this->base_vector;
    elems = elema->elems;
    v13 = elems[v11];
    v14 = elems[v5];
    elems[v11] = v14;
    elema->elems[v5] = v13;
    if ( v13[3] == v11 )
      v13[3] = v5;
    else
      v13[4] = v5;
    if ( v14[3] == v5 )
    {
      v14[3] = v11;
      ++this->n_found_objects;
      return base_elem;
    }
    v14[4] = v11;
  }
  ++this->n_found_objects;
  return base_elem;
}

//------------------------------------------------------------------------------
// Address: 0x1008EED0
// Name: public: class IVP_Collision __near * IVP_Diff_Hash<class IVP_OO_CMP,class IVP_U_FVector<class IVP_Collision>,class IVP_Collision,class IVP_Real_Object>::check_element(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Collision *__thiscall IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object>::check_element(
        IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object> *this,
        IVP_Real_Object *elem,
        IVP_Real_Object *reference)
{
  unsigned int v4; // ebx
  int v5; // edi
  void (__stdcall *v6)(unsigned int *); // eax
  int n_found_objects; // eax
  void *v9; // ecx
  unsigned int i; // eax
  int v11; // eax
  IVP_OBJECT_TYPE object_type; // ecx
  int v13; // edx
  int v14; // ebx
  unsigned int v15; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v16; // [esp+10h] [ebp-8h]
  IVP_Collision *base_elem; // [esp+14h] [ebp-4h]
  IVP_Real_Object *elema; // [esp+20h] [ebp+8h]

  v4 = this->buffersize_minus_one & ((unsigned int)elem + 1023 * ((int)elem >> 8));
  v5 = this->hash_to_vector_index[v4];
  if ( v5 == -1 )
    return nullptr;
  while ( 1 )
  {
    v6 = *(void (__stdcall **)(unsigned int *))(*(_DWORD *)this->base_vector->elems[v5] + 4);
    base_elem = (IVP_Collision *)this->base_vector->elems[v5];
    v6(a1: &v15);
    if ( (IVP_Real_Object *)v15 == elem || (IVP_Real_Object *)v16 == elem )
      break;
    v4 = this->buffersize_minus_one & (v4 + 1);
    v5 = this->hash_to_vector_index[v4];
    if ( v5 == -1 )
      return nullptr;
  }
  n_found_objects = this->n_found_objects;
  if ( v5 > n_found_objects )
  {
    v9 = this->base_vector->elems[n_found_objects];
    (*(void (__thiscall **)(void *, unsigned int *))(*(_DWORD *)v9 + 4))(a1: v9, a2: &v15);
    for ( i = this->buffersize_minus_one
            & (((unsigned int)reference ^ v15 ^ v16) + 1023 * ((int)((unsigned int)reference ^ v15 ^ v16) >> 8));
          this->hash_to_vector_index[i] != this->n_found_objects;
          i = this->buffersize_minus_one & (i + 1) )
    {
      ;
    }
    this->hash_to_vector_index[i] = v5;
    this->hash_to_vector_index[v4] = this->n_found_objects;
    v11 = this->n_found_objects;
    elema = (IVP_Real_Object *)this->base_vector;
    object_type = elema->object_type;
    v13 = *(_DWORD *)(object_type + 4 * v11);
    v14 = *(_DWORD *)(object_type + 4 * v5);
    *(_DWORD *)(object_type + 4 * v11) = v14;
    *(_DWORD *)(elema->object_type + 4 * v5) = v13;
    if ( *(_DWORD *)(v13 + 12) == v11 )
      *(_DWORD *)(v13 + 12) = v5;
    else
      *(_DWORD *)(v13 + 16) = v5;
    if ( *(_DWORD *)(v14 + 12) == v5 )
    {
      *(_DWORD *)(v14 + 12) = v11;
      ++this->n_found_objects;
      return base_elem;
    }
    *(_DWORD *)(v14 + 16) = v11;
  }
  ++this->n_found_objects;
  return base_elem;
}

//------------------------------------------------------------------------------
// Address: 0x1008F000
// Name: public: virtual IVP_Mindist::~IVP_Mindist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::~IVP_Mindist(IVP_Mindist *this)
{
  IVP_Environment *environment; // eax
  IVP_Mindist_Manager *mindist_manager; // edi
  int v4; // eax
  IVP_Controller_Phantom *controller_phantom; // ecx
  IVP_Controller_Phantom *v6; // ecx
  float *p_sum_extra_radius; // eax
  int i; // ecx

  this->__vftable = (IVP_Mindist_vtbl *)&IVP_Mindist::`vftable';
  environment = this->synapse[0].l_obj->environment;
  --environment->statistic_manager.sum_of_mindists;
  ++environment->statistic_manager.mindists_deleted;
  mindist_manager = environment->mindist_manager;
  v4 = *((_DWORD *)&this->IVP_Mindist_Base + 5);
  if ( (v4 & 0xC00) != 0 )
  {
    *((_DWORD *)&this->IVP_Mindist_Base + 5) = v4 & 0xFFFCF3FF;
    controller_phantom = this->synapse[0].l_obj->controller_phantom;
    if ( controller_phantom != nullptr )
      IVP_Controller_Phantom::mindist_left_volume(this: controller_phantom, mindist: this);
    v6 = this->synapse[1].l_obj->controller_phantom;
    if ( v6 != nullptr )
      IVP_Controller_Phantom::mindist_left_volume(this: v6, mindist: this);
  }
  switch ( (int)(*((_DWORD *)&this->IVP_Mindist_Base + 5) << 10) >> 28 )
  {
    case 2:
      IVP_Mindist_Manager::remove_invalid_mindist(this: mindist_manager, del_mindist: this);
      break;
    case 3:
      IVP_Mindist_Manager::remove_exact_mindist(this: mindist_manager, del_mindist: this);
      break;
    case 4:
    case 5:
      IVP_U_Min_List::remove_minlist_elem(
        this: &this->synapse[0].l_obj->hull_manager.sorted_synapses,
        index: this->synapse[0].minlist_index);
      IVP_U_Min_List::remove_minlist_elem(
        this: &this->synapse[1].l_obj->hull_manager.sorted_synapses,
        index: this->synapse[1].minlist_index);
      break;
    default:
      break;
  }
  this->synapse[0].l_obj->surface_manager->remove_reference_to_ledge(
    this: this->synapse[0].l_obj->surface_manager,
    a2: (const IVP_Compact_Ledge *)(((int)this->synapse[0].edge & 0xFFFFFFF0)
                              - 16 * ((*(_DWORD *)((int)this->synapse[0].edge & 0xFFFFFFF0) & 0xFFF) + 1)));
  this->synapse[1].l_obj->surface_manager->remove_reference_to_ledge(
    this: this->synapse[1].l_obj->surface_manager,
    a2: (const IVP_Compact_Ledge *)(((int)this->synapse[1].edge & 0xFFFFFFF0)
                              - 16 * ((*(_DWORD *)((int)this->synapse[1].edge & 0xFFFFFFF0) & 0xFFF) + 1)));
  this->delegator->collision_is_going_to_be_deleted_event(this: this->delegator, a2: this);
  this->__vftable = (IVP_Mindist_vtbl *)&IVP_Mindist_Base::`vftable';
  p_sum_extra_radius = &this->sum_extra_radius;
  for ( i = 1; i >= 0; --i )
  {
    p_sum_extra_radius -= 7;
    *(_DWORD *)p_sum_extra_radius = &IVP_Synapse::`vftable';
  }
  this->__vftable = (IVP_Mindist_vtbl *)&IVP_Collision::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1008F130
// Name: public: void IVP_Mindist_Manager::insert_exact_mindist(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::insert_exact_mindist(IVP_Mindist_Manager *this, IVP_Mindist *new_mindist)
{
  IVP_Mindist *exact_mindists; // eax
  IVP_Synapse_Real *exact_synapses; // edi
  IVP_Synapse *synapse; // eax
  IVP_Synapse *v5; // edx
  IVP_Real_Object *l_obj; // edi
  IVP_Synapse_Real *v7; // edi
  IVP_Real_Object *v8; // edi
  IVP_U_Vector<IVP_Mindist> *p_wheel_look_ahead_mindists; // edi

  *((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) = *((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) & 0xFFC3FFFF
                                                  | 0xC0000;
  exact_mindists = this->exact_mindists;
  new_mindist->next = exact_mindists;
  new_mindist->prev = nullptr;
  if ( exact_mindists != nullptr )
    exact_mindists->prev = new_mindist;
  this->exact_mindists = new_mindist;
  exact_synapses = new_mindist->synapse[0].l_obj->exact_synapses;
  synapse = new_mindist->synapse;
  v5 = &new_mindist->synapse[1];
  new_mindist->synapse[0].next = exact_synapses;
  if ( exact_synapses != nullptr )
    exact_synapses->prev = synapse;
  l_obj = new_mindist->synapse[0].l_obj;
  new_mindist->synapse[0].prev = nullptr;
  l_obj->exact_synapses = (IVP_Synapse_Real *)synapse;
  v7 = new_mindist->synapse[1].l_obj->exact_synapses;
  new_mindist->synapse[1].next = v7;
  if ( v7 != nullptr )
    v7->prev = v5;
  v8 = new_mindist->synapse[1].l_obj;
  new_mindist->synapse[1].prev = nullptr;
  v8->exact_synapses = (IVP_Synapse_Real *)v5;
  if ( (new_mindist->synapse[0].l_obj->physical_core->car_wheel != nullptr
     || new_mindist->synapse[1].l_obj->physical_core->car_wheel != nullptr)
    && (*((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) & 0x3000) != 0x1000 )
  {
    p_wheel_look_ahead_mindists = &this->wheel_look_ahead_mindists;
    if ( this->wheel_look_ahead_mindists.n_elems >= this->wheel_look_ahead_mindists.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->wheel_look_ahead_mindists);
    p_wheel_look_ahead_mindists->elems[p_wheel_look_ahead_mindists->n_elems++] = new_mindist;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F200
// Name: public: virtual void IVP_Mindist::exact_mindist_went_invalid(class IVP_Mindist_Manager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::exact_mindist_went_invalid(IVP_Mindist *this, IVP_Mindist_Manager *mm)
{
  IVP_Mindist_Manager::remove_exact_mindist(this: mm, del_mindist: this);
  IVP_Mindist_Manager::insert_invalid_mindist(this: mm, new_mindist: this);
}

//------------------------------------------------------------------------------
// Address: 0x1008F220
// Name: public: void IVP_Mindist_Manager::recalc_all_exact_wheel_mindist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::recalc_all_exact_wheel_mindist(IVP_Mindist_Manager *this)
{
  int v2; // eax
  IVP_Mindist *v3; // esi
  int v4; // ecx
  int v5; // edi
  const IVP_Compact_Edge *v6; // eax
  int i; // [esp+10h] [ebp-4h]

  v2 = this->wheel_look_ahead_mindists.n_elems - 1;
  i = v2;
  if ( this->wheel_look_ahead_mindists.n_elems != 0 )
  {
    while ( 1 )
    {
      v3 = (IVP_Mindist *)this->wheel_look_ahead_mindists.elems[v2];
      IVP_Mindist_Manager::recalc_exact_mindist(this, mdist: v3);
      v4 = (int)&v3->synapse[(*((_DWORD *)&v3->IVP_Mindist_Base + 5) >> 8) & 3];
      v5 = (int)&v3->synapse[((*((_DWORD *)&v3->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3];
      if ( v3->synapse[(*((_DWORD *)&v3->IVP_Mindist_Base + 5) >> 8) & 3].status != 3 )
      {
        v4 = (int)&v3->synapse[((*((_DWORD *)&v3->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3];
        v5 = (int)&v3->synapse[(*((_DWORD *)&v3->IVP_Mindist_Base + 5) >> 8) & 3];
      }
      v6 = *(const IVP_Compact_Edge **)(v5 + 20);
      if ( v6 != v3->last_visited_triangle
        && *(_WORD *)(v5 + 26) == 2
        && *(_WORD *)(v4 + 26) == 3
        && ivp_mindist_settings.max_distance_for_friction > v3->len_numerator
        && (*(_BYTE *)(((unsigned int)v6 & 0xFFFFFFF0) - 16 * (*(_DWORD *)((unsigned int)v6 & 0xFFFFFFF0) & 0xFFF) - 8)
          & 3) == 0 )
      {
        IVP_Mindist::create_cp_in_advance_pretension(
          this: v3,
          robject: *(IVP_Real_Object **)(v4 + 16),
          gap_len: v3->len_numerator);
        v3->last_visited_triangle = *(const IVP_Compact_Edge **)(v5 + 20);
      }
      if ( --i < 0 )
        break;
      v2 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F300
// Name: public: void IVP_Mindist_Manager::recalc_all_exact_mindists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::recalc_all_exact_mindists(IVP_Mindist_Manager *this)
{
  IVP_Mindist *exact_mindists; // esi
  const char *next; // edi
  int v4; // eax
  float len_numerator; // xmm0_4
  IVP_Controller_Phantom *controller_phantom; // ecx
  IVP_Controller_Phantom *v7; // ecx
  float sum_extra_radius; // xmm0_4
  IVP_Controller_Phantom *v9; // eax
  IVP_Real_Object *l_obj; // ecx
  float exit_policy_extra_radius; // xmm1_4
  bool v12; // zf
  int v13; // eax
  IVP_Controller_Phantom *v14; // ecx
  IVP_Controller_Phantom *v15; // ecx
  IVP_Controller_Phantom *v16; // ecx

  exact_mindists = this->exact_mindists;
  if ( exact_mindists != nullptr )
  {
    do
    {
      next = (const char *)exact_mindists->next;
      if ( next != nullptr )
      {
        _mm_prefetch(next, 2);
        _mm_prefetch(next + 32, 2);
        _mm_prefetch(next + 64, 2);
        _mm_prefetch(next + 96, 2);
      }
      IVP_Mindist::recalc_mindist(this: exact_mindists);
      v4 = *((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5);
      if ( (v4 & 0x3000) == 0 )
      {
        if ( (v4 & 0xC000) != 0 )
          exact_mindists->exact_mindist_went_invalid(this: exact_mindists, a2: this);
        goto LABEL_32;
      }
      if ( (v4 & 0xC000) != 0 )
      {
        sum_extra_radius = exact_mindists->sum_extra_radius;
      }
      else
      {
        len_numerator = exact_mindists->len_numerator;
        if ( len_numerator > 0.0 )
        {
          if ( (v4 & 0xC00) != 0 )
          {
            *((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) = v4 & 0xFFFCF3FF;
            controller_phantom = exact_mindists->synapse[0].l_obj->controller_phantom;
            if ( controller_phantom != nullptr )
              IVP_Controller_Phantom::mindist_left_volume(this: controller_phantom, mindist: exact_mindists);
            v7 = exact_mindists->synapse[1].l_obj->controller_phantom;
            if ( v7 != nullptr )
              IVP_Controller_Phantom::mindist_left_volume(this: v7, mindist: exact_mindists);
          }
          goto LABEL_32;
        }
        LODWORD(sum_extra_radius) = LODWORD(len_numerator) ^ _mask__NegFloat_;
      }
      v9 = exact_mindists->synapse[0].l_obj->controller_phantom;
      l_obj = exact_mindists->synapse[1].l_obj;
      if ( v9 != nullptr )
      {
        if ( l_obj->controller_phantom != nullptr )
          goto LABEL_32;
        exit_policy_extra_radius = v9->exit_policy_extra_radius;
      }
      else
      {
        exit_policy_extra_radius = l_obj->controller_phantom->exit_policy_extra_radius;
      }
      v12 = exact_mindists->is_recursive(this: exact_mindists) == IVP_FALSE;
      v13 = *((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5);
      if ( v12 )
      {
        if ( (v13 & 0xC00) == 0 )
        {
          *((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) = v13 & 0xFFFCF3FF | 0x10400;
          v14 = exact_mindists->synapse[0].l_obj->controller_phantom;
          if ( v14 != nullptr )
            IVP_Controller_Phantom::mindist_entered_volume(this: v14, mindist: exact_mindists);
          v15 = exact_mindists->synapse[1].l_obj->controller_phantom;
LABEL_29:
          if ( v15 != nullptr )
            IVP_Controller_Phantom::mindist_entered_volume(this: v15, mindist: exact_mindists);
          IVP_Mindist_Manager::remove_exact_mindist(this, del_mindist: exact_mindists);
          IVP_Mindist_Manager::insert_lazy_hull_mindist(
            md: exact_mindists,
            hull_time: exit_policy_extra_radius + sum_extra_radius);
        }
      }
      else if ( (v13 & 0xC00) == 0 )
      {
        *((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) = v13 & 0xFFFCF3FF | 0x10400;
        v16 = exact_mindists->synapse[0].l_obj->controller_phantom;
        if ( v16 != nullptr )
          IVP_Controller_Phantom::mindist_entered_volume(this: v16, mindist: exact_mindists);
        v15 = exact_mindists->synapse[1].l_obj->controller_phantom;
        goto LABEL_29;
      }
LABEL_32:
      exact_mindists = (IVP_Mindist *)next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F490
// Name: public: void IVP_Mindist::update_exact_mindist_events(enum IVP_BOOL,enum IVP_MINDIST_EVENT_HINT)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::update_exact_mindist_events(
        IVP_Mindist *this,
        IVP_BOOL allow_hull_conversion,
        IVP_MINDIST_EVENT_HINT event_hint)
{
  IVP_Core *physical_core; // ebx
  bool v5; // zf
  IVP_Core *v6; // eax
  IVP_Environment *environment; // edi
  float worst_case_speed; // xmm0_4
  unsigned int v9; // edx
  float len_numerator; // xmm6_4
  int v11; // ecx
  float v12; // xmm7_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  IVP_Mindist *mindist; // edx
  int mindist_coll_dist_count; // eax
  double seconds; // xmm0_8
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  int seconds_high; // edx
  float v27; // xmm1_4
  IVP_Mindist_Event_Solver mim; // [esp+10h] [ebp-40h] BYREF
  double v29; // [esp+48h] [ebp-8h]

  physical_core = this->synapse[(*((_DWORD *)&this->IVP_Mindist_Base + 5) >> 8) & 3].l_obj->physical_core;
  v5 = this->index == 0xFFFF;
  v6 = this->synapse[((*((_DWORD *)&this->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].l_obj->physical_core;
  environment = this->synapse[0].l_obj->environment;
  mim.sum_max_surface_rot_speed = physical_core->max_surface_rot_speed + v6->max_surface_rot_speed;
  worst_case_speed = (float)(physical_core->current_speed + mim.sum_max_surface_rot_speed) + v6->current_speed;
  HIDWORD(v29) = v6;
  mim.worst_case_speed = worst_case_speed;
  if ( !v5 )
  {
    IVP_Time_Manager::remove_event(this: environment->time_manager, event: this);
    worst_case_speed = mim.worst_case_speed;
    v6 = (IVP_Core *)HIDWORD(v29);
    this->index = 0xFFFF;
  }
  v9 = *((_DWORD *)&this->IVP_Mindist_Base + 5);
  len_numerator = this->len_numerator;
  v11 = (unsigned __int8)(v9 >> 22);
  v12 = ivp_mindist_settings.coll_dists[v11];
  v13 = (float)((float)(environment->delta_PSI_time * worst_case_speed) * 2.0999999) + v12;
  *((float *)&v29 + 1) = v12;
  if ( len_numerator > v13 )
  {
    if ( allow_hull_conversion != IVP_FALSE )
    {
      IVP_Mindist_Manager::remove_exact_mindist(this: environment->mindist_manager, del_mindist: this);
      IVP_Mindist_Manager::insert_hull_mindist(md: this, hull_time: this->len_numerator - *((float *)&v29 + 1));
    }
    return;
  }
  v14 = this->contact_plane.k[1];
  v15 = this->contact_plane.k[0];
  v16 = this->contact_plane.k[2];
  mim.projected_center_speed = (float)((float)((float)(v6->speed.k[1] * v14) + (float)(v6->speed.k[0] * v15))
                                     + (float)(v6->speed.k[2] * v16))
                             - (float)((float)((float)(physical_core->speed.k[1] * v14)
                                             + (float)(v15 * physical_core->speed.k[0]))
                                     + (float)(physical_core->speed.k[2] * v16));
  v17 = (float)((float)(physical_core->rotation_axis_world_space.k[1] * v14)
              + (float)(physical_core->rotation_axis_world_space.k[0] * v15))
      + (float)(physical_core->rotation_axis_world_space.k[2] * v16);
  v18 = (float)((float)(v6->rotation_axis_world_space.k[1] * v14) + (float)(v6->rotation_axis_world_space.k[0] * v15))
      + (float)(v6->rotation_axis_world_space.k[2] * v16);
  v19 = (float)((float)(fsqrt(1.001 - (float)(v17 * v17)) * physical_core->max_surface_rot_speed)
              + (float)(fsqrt(1.001 - (float)(v18 * v18)) * v6->max_surface_rot_speed))
      + mim.projected_center_speed;
  mim.max_coll_speed = v19;
  mim.t_now.seconds = environment->current_time.seconds;
  mim.t_max.seconds = environment->time_of_next_psi.seconds;
  if ( (ivp_mindist_settings.speed_after_keeper_dist <= v19 || v19 >= 1.0e-10)
    && len_numerator < (float)((float)((float)(mim.t_max.seconds - mim.t_now.seconds) * v19) + v12)
    && (v9 & 0x3000) != 0x1000 )
  {
    mindist = this;
    mim.mindist = this;
    mim.environment = environment;
    if ( v11 != 0 )
    {
      mindist_coll_dist_count = environment->mindist_coll_dist_count;
      environment->mindist_coll_dist_count = mindist_coll_dist_count + 1;
      if ( mindist_coll_dist_count > 2 )
      {
        *((_DWORD *)&this->IVP_Mindist_Base + 5) ^= (*((_DWORD *)&this->IVP_Mindist_Base + 5)
                                                   ^ (((*((_DWORD *)&this->IVP_Mindist_Base + 5) >> 22) - 1) << 22))
                                                  & 0x3FC00000;
        environment->mindist_coll_dist_count = 0;
      }
      mindist = mim.mindist;
    }
    IVP_Mindist_Event_Solver::mim_function_table[mindist->synapse[(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 8) & 3].status][mindist->synapse[((*((_DWORD *)&mindist->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].status](a1: &mim);
    if ( mim.event_type_out != IVP_COLL_NONE )
    {
      seconds = mim.event_time_out.seconds;
      v23 = mim.event_time_out.seconds - mim.t_now.seconds;
      if ( v23 >= 0.000001 )
      {
LABEL_28:
        this->index = IVP_U_Min_List::add(
                        this: environment->time_manager->min_hash,
                        elem: this,
                        value: seconds - environment->time_manager->base_time.seconds);
        *((_BYTE *)&this->IVP_Mindist_Base + 20) = mim.event_type_out;
        return;
      }
      if ( event_hint == IVP_EH_NOW )
      {
        mim.event_time_out.seconds = mim.t_now.seconds;
        seconds = mim.t_now.seconds;
        goto LABEL_28;
      }
      v24 = len_numerator - ivp_mindist_settings.real_coll_dist;
      if ( event_hint == IVP_EH_BIG_DELAY || (mim.event_type_out & 0xF) != 0 )
      {
        if ( v24 >= 0.000001 )
        {
          seconds = (float)(v24 / mim.worst_case_speed)
                  + environment->current_time.seconds
                  + (float)((float)(ivp_mindist_settings.event_queue_min_delta_time_base * 0.000099999997)
                          * environment->delta_PSI_time);
          goto LABEL_27;
        }
        v25 = ivp_mindist_settings.event_queue_min_delta_time_base * 0.001;
      }
      else
      {
        if ( v24 >= 0.000001 )
        {
          seconds = (float)((float)(v24 * 0.1) / mim.worst_case_speed)
                  + environment->current_time.seconds
                  + (float)((float)(ivp_mindist_settings.event_queue_min_delta_time_base * 0.0000001)
                          * environment->delta_PSI_time);
          goto LABEL_27;
        }
        v25 = ivp_mindist_settings.event_queue_min_delta_time_base * 0.0000099999997;
      }
      seconds = (float)(v25 * environment->delta_PSI_time) + environment->current_time.seconds;
LABEL_27:
      mim.event_time_out.seconds = seconds;
      seconds_high = HIDWORD(environment->time_of_next_psi.seconds);
      LODWORD(v29) = LODWORD(environment->time_of_next_psi.seconds);
      HIDWORD(v29) = seconds_high;
      v27 = seconds - v29;
      if ( v27 >= 0.0 )
        return;
      goto LABEL_28;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F920
// Name: public: virtual void IVP_Mindist::simulate_time_event(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::simulate_time_event(IVP_Mindist *this, IVP_Environment *env)
{
  unsigned int v3; // eax

  env->performancecounter->pcount(this: env->performancecounter, a2: IVP_PE_AT_INIT);
  IVP_Mindist::recalc_mindist(this);
  v3 = *((_DWORD *)&this->IVP_Mindist_Base + 5);
  if ( (v3 & 0xC000) == 0 )
  {
    if ( (v3 & 0xF) != 0 )
    {
      IVP_Mindist::update_exact_mindist_events(this, allow_hull_conversion: IVP_FALSE, event_hint: IVP_EH_SMALL_DELAY);
    }
    else
    {
      if ( (float)(ivp_mindist_settings.coll_dists[(unsigned __int8)(v3 >> 22)]
                 + ivp_mindist_settings.mindist_change_force_dist) > this->len_numerator )
      {
        ((void (__fastcall *)(IVP_Mindist *))this->do_impact)(a1: this);
        env->performancecounter->pcount(this: env->performancecounter, a2: IVP_PE_AT_END);
        return;
      }
      IVP_Mindist::update_exact_mindist_events(this, allow_hull_conversion: IVP_FALSE, event_hint: IVP_EH_BIG_DELAY);
    }
  }
  env->performancecounter->pcount(this: env->performancecounter, a2: IVP_PE_AT_END);
}

//------------------------------------------------------------------------------
// Address: 0x1008F9B0
// Name: public: IVP_Mindist_Manager::IVP_Mindist_Manager(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Mindist_Manager *__thiscall IVP_Mindist_Manager::IVP_Mindist_Manager(
        IVP_Mindist_Manager *this,
        IVP_Environment *i_env)
{
  *(_QWORD *)&this->scanning_universe = 0;
  *(_QWORD *)&this->exact_mindists = 0;
  *(_QWORD *)&this->wheel_look_ahead_mindists.elems = 0;
  this->environment = i_env;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008F9E0
// Name: public: IVP_Mindist_Manager::~IVP_Mindist_Manager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::~IVP_Mindist_Manager(IVP_Mindist_Manager *this)
{
  IVP_Mindist *exact_mindists; // ecx
  IVP_Mindist *next; // esi
  IVP_Mindist *invalid_mindists; // ecx
  IVP_Mindist *v5; // esi
  void **elems; // eax

  exact_mindists = this->exact_mindists;
  if ( exact_mindists != nullptr )
  {
    do
    {
      next = exact_mindists->next;
      ((void (__stdcall *)(int))exact_mindists->dtr_IVP_Collision)(a1: 1);
      exact_mindists = next;
    }
    while ( next != nullptr );
  }
  invalid_mindists = this->invalid_mindists;
  if ( invalid_mindists != nullptr )
  {
    do
    {
      v5 = invalid_mindists->next;
      ((void (__stdcall *)(int))invalid_mindists->dtr_IVP_Collision)(a1: 1);
      invalid_mindists = v5;
    }
    while ( v5 != nullptr );
  }
  elems = this->wheel_look_ahead_mindists.elems;
  if ( elems == (void **)&this->invalid_mindists )
  {
    this->wheel_look_ahead_mindists.n_elems = 0;
  }
  else
  {
    if ( elems != nullptr )
      free(data: this->wheel_look_ahead_mindists.elems);
    this->wheel_look_ahead_mindists.elems = nullptr;
    *(_DWORD *)&this->wheel_look_ahead_mindists.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FA90
// Name: public: void IVP_Mindist_Manager::insert_and_recalc_exact_mindist(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::insert_and_recalc_exact_mindist(
        IVP_Mindist_Manager *this,
        IVP_Mindist *new_mindist)
{
  IVP_Mindist *next; // eax
  IVP_Synapse_Real *exact_synapses; // eax
  IVP_Synapse *synapse; // edi
  IVP_Synapse_Real *v5; // ebx
  IVP_Real_Object *l_obj; // eax
  IVP_Synapse_Real *v7; // eax

  *((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) = *((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) & 0xFFC3FFFF
                                                  | 0xC0000;
  new_mindist->next = this->exact_mindists;
  next = new_mindist->next;
  new_mindist->prev = nullptr;
  if ( next != nullptr )
    next->prev = new_mindist;
  exact_synapses = new_mindist->synapse[0].l_obj->exact_synapses;
  synapse = new_mindist->synapse;
  v5 = (IVP_Synapse_Real *)&new_mindist->synapse[1];
  new_mindist->synapse[0].next = exact_synapses;
  if ( exact_synapses != nullptr )
    exact_synapses->prev = synapse;
  l_obj = new_mindist->synapse[0].l_obj;
  new_mindist->synapse[0].prev = nullptr;
  l_obj->exact_synapses = (IVP_Synapse_Real *)synapse;
  v7 = new_mindist->synapse[1].l_obj->exact_synapses;
  new_mindist->synapse[1].next = v7;
  if ( v7 != nullptr )
    v7->prev = v5;
  new_mindist->synapse[1].prev = nullptr;
  new_mindist->synapse[1].l_obj->exact_synapses = v5;
  this->exact_mindists = new_mindist;
  IVP_Mindist::recalc_mindist(this: new_mindist);
  if ( new_mindist->synapse[0].l_obj->physical_core->car_wheel != nullptr
    || new_mindist->synapse[1].l_obj->physical_core->car_wheel != nullptr )
  {
    if ( this->wheel_look_ahead_mindists.n_elems >= this->wheel_look_ahead_mindists.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->wheel_look_ahead_mindists);
    this->wheel_look_ahead_mindists.elems[this->wheel_look_ahead_mindists.n_elems++] = new_mindist;
  }
  if ( (*((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) & 0xC000) != 0 )
    new_mindist->exact_mindist_went_invalid(this: new_mindist, a2: this);
  else
    IVP_Mindist::update_exact_mindist_events(
      this: new_mindist,
      allow_hull_conversion: (IVP_BOOL)((unsigned __int8)(*((_BYTE *)&new_mindist->synapse[0].l_obj->physical_core->IVP_Core_Fast_Static + 1)
                                 | *((_BYTE *)&new_mindist->synapse[1].l_obj->physical_core->IVP_Core_Fast_Static + 1)) < 0x21u),
      event_hint: IVP_EH_NOW);
}

//------------------------------------------------------------------------------
// Address: 0x1008FBA0
// Name: public: void IVP_Mindist_Manager::insert_and_recalc_phantom_mindist(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::insert_and_recalc_phantom_mindist(
        IVP_Mindist_Manager *this,
        IVP_Mindist *new_mindist)
{
  int v3; // eax
  float len_numerator; // xmm0_4
  float hull_time; // xmm0_4
  IVP_Controller_Phantom *controller_phantom; // ecx
  IVP_Controller_Phantom *v7; // ecx
  IVP_Controller_Phantom *v8; // eax

  IVP_Mindist::recalc_invalid_mindist(this: new_mindist);
  v3 = *((_DWORD *)&new_mindist->IVP_Mindist_Base + 5);
  if ( (v3 & 0xC000) != 0 )
  {
    hull_time = new_mindist->sum_extra_radius;
  }
  else
  {
    len_numerator = new_mindist->len_numerator;
    if ( len_numerator > 0.0 )
    {
      if ( (v3 & 0xC00) != 0 )
        IVP_Mindist_Manager::mindist_left_phantom(mdist: new_mindist);
      IVP_Mindist_Manager::insert_exact_mindist(this, new_mindist);
      IVP_Mindist::update_exact_mindist_events(
        this: new_mindist,
        allow_hull_conversion: IVP_TRUE,
        event_hint: IVP_EH_BIG_DELAY);
      return;
    }
    LODWORD(hull_time) = LODWORD(len_numerator) ^ _mask__NegFloat_;
  }
  if ( (v3 & 0xC00) == 0 )
  {
    *((_DWORD *)&new_mindist->IVP_Mindist_Base + 5) = v3 & 0xFFFCF3FF | 0x10400;
    controller_phantom = new_mindist->synapse[0].l_obj->controller_phantom;
    if ( controller_phantom != nullptr )
      IVP_Controller_Phantom::mindist_entered_volume(this: controller_phantom, mindist: new_mindist);
    v7 = new_mindist->synapse[1].l_obj->controller_phantom;
    if ( v7 != nullptr )
      IVP_Controller_Phantom::mindist_entered_volume(this: v7, mindist: new_mindist);
  }
  v8 = new_mindist->synapse[0].l_obj->controller_phantom;
  if ( v8 != nullptr || (v8 = new_mindist->synapse[1].l_obj->controller_phantom) != nullptr )
    hull_time = hull_time + v8->exit_policy_extra_radius;
  IVP_Mindist_Manager::insert_lazy_hull_mindist(md: new_mindist, hull_time);
}

//------------------------------------------------------------------------------
// Address: 0x1008FC80
// Name: public: void IVP_Mindist_Manager::recheck_ov_element(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::recheck_ov_element(IVP_Mindist_Manager *this, IVP_Real_Object *object)
{
  IVP_OV_Element *ov_element; // ebx
  IVP_Core *physical_core; // esi
  IVP_Mindist_Manager *v5; // edx
  float v6; // xmm0_4
  float v7; // xmm1_4
  IVP_U_Float_Point *p_center; // ebx
  double v9; // st7
  IVP_Mindist_Manager *v10; // eax
  IVP_Universe_Manager *universe_manager; // ecx
  float min_radius; // xmm0_4
  IVP_Mindist_Manager *v13; // ecx
  IVP_OV_Element *v14; // ebx
  int v15; // eax
  int v16; // ecx
  IVP_Core *v17; // edx
  IVP_Vector_of_Objects_128 *elem_buffer; // ecx
  IVP_Real_Object_Fast::<unnamed_type_flags> flags; // eax
  bool v20; // dl
  int v21; // ebx
  int v22; // esi
  int n_found_objects; // ebx
  int v24; // esi
  void *v25; // ecx
  int v26; // eax
  IVP_Environment *environment; // edx
  int v28; // esi
  int v29; // ebx
  void *v30; // ecx
  float max_radius; // xmm0_4
  IVP_OV_Element *v32; // esi
  float hull_time; // [esp+18h] [ebp-C44h]
  __int16 a_buffer[1024]; // [esp+28h] [ebp-C34h] BYREF
  IVP_Vector_of_OV_Elements_128 colliding_elements; // [esp+828h] [ebp-434h] BYREF
  IVP_Vector_of_Objects_128 new_objects; // [esp+A30h] [ebp-22Ch] BYREF
  IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object> diff_hash; // [esp+C38h] [ebp-24h] BYREF
  IVP_OV_Element *elem; // [esp+C4Ch] [ebp-10h]
  IVP_Collision_Filter *coll_filter; // [esp+C50h] [ebp-Ch]
  IVP_Mindist_Manager *v40; // [esp+C54h] [ebp-8h]
  bool isStaticSolid; // [esp+C5Ah] [ebp-2h]
  bool isDebris; // [esp+C5Bh] [ebp-1h]
  int x; // [esp+C64h] [ebp+8h]
  int xa; // [esp+C64h] [ebp+8h]
  bool x_3; // [esp+C67h] [ebp+Bh]

  ov_element = object->ov_element;
  v40 = this;
  colliding_elements.elems = colliding_elements.elem_buffer;
  *(_DWORD *)&colliding_elements.memsize = 128;
  elem = ov_element;
  if ( ov_element != nullptr )
  {
    physical_core = object->physical_core;
    IVP_OV_Tree_Manager::remove_ov_element(this: this->environment->ov_tree_manager, element: ov_element);
    v5 = v40;
    ++v40->environment->statistic_manager.range_world_exceeded;
    v6 = physical_core->m_world_f_core_last_psi.vv.k[1];
    v7 = physical_core->m_world_f_core_last_psi.vv.k[2];
    ov_element->center.k[0] = physical_core->m_world_f_core_last_psi.vv.k[0];
    p_center = &ov_element->center;
    coll_filter = (IVP_Collision_Filter *)&object->hull_manager;
    p_center->k[1] = v6;
    p_center->k[2] = v7;
    if ( v5->scanning_universe != IVP_FALSE )
    {
      max_radius = physical_core->upper_limit_radius;
      v32 = elem;
      IVP_OV_Tree_Manager::insert_ov_element(
        this: v5->environment->ov_tree_manager,
        element: elem,
        min_radius: max_radius,
        max_radius,
        colliding_balls: nullptr);
      IVP_OV_Element::add_to_hull_manager(this: v32, hm: (IVP_Hull_Manager *)coll_filter, hull_time: 1.0e-10);
    }
    else
    {
      v9 = ((double (__thiscall *)(IVP_Range_Manager *, IVP_Real_Object *))v5->environment->range_manager->get_coll_range_in_world)(
             a1: v5->environment->range_manager,
             a2: object);
      v10 = v40;
      universe_manager = v40->environment->universe_manager;
      *(float *)&x = v9 + physical_core->upper_limit_radius;
      min_radius = *(float *)&x;
      if ( universe_manager != nullptr && (*(_BYTE *)&object->flags & 7) != 0 )
      {
        v40->scanning_universe = IVP_TRUE;
        ((void (__thiscall *)(IVP_Universe_Manager *, IVP_Real_Object *, IVP_U_Float_Point *, int))universe_manager->ensure_objects_in_environment)(
          a1: universe_manager,
          a2: object,
          a3: p_center,
          a4: x);
        v13 = v40;
        min_radius = *(float *)&x;
        v40->scanning_universe = IVP_FALSE;
        v10 = v13;
      }
      v14 = elem;
      hull_time = IVP_OV_Tree_Manager::insert_ov_element(
                    this: v10->environment->ov_tree_manager,
                    element: elem,
                    min_radius,
                    max_radius: min_radius,
                    colliding_balls: &colliding_elements)
                - physical_core->upper_limit_radius;
      IVP_OV_Element::add_to_hull_manager(this: v14, hm: (IVP_Hull_Manager *)coll_filter, hull_time);
      coll_filter = v40->environment->collision_filter;
      v15 = 1024;
      v16 = 4 * (colliding_elements.n_elems + v14->collision_fvector.n_elems) + 4;
      if ( (unsigned int)v16 < 0x400 )
      {
        do
          v15 >>= 1;
        while ( v15 > v16 );
      }
      IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object>::IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object>(
        this: &diff_hash,
        base: &v14->collision_fvector,
        buffer: a_buffer,
        buffer_size: v15,
        reference: object);
      v17 = object->physical_core;
      elem_buffer = (IVP_Vector_of_Objects_128 *)new_objects.elem_buffer;
      new_objects.elems = (void **)new_objects.elem_buffer;
      *(_DWORD *)&new_objects.memsize = 128;
      x_3 = (*(_WORD *)&v17->IVP_Core_Fast_Static & 0x12) != 0;
      flags = object->flags;
      v20 = (*(_WORD *)&flags & 0x200) != 0;
      isDebris = v20;
      if ( (*(_WORD *)&flags & 0x200) != 0 || (isStaticSolid = true, (*(_WORD *)&flags & 0x400) == 0) )
        isStaticSolid = false;
      v21 = colliding_elements.n_elems - 1;
      if ( colliding_elements.n_elems != 0 )
      {
        do
        {
          v22 = *((_DWORD *)colliding_elements.elems[v21] + 9);
          if ( ((*(_BYTE *)&object->flags & 7) != 0 || (*(_BYTE *)(v22 + 68) & 7) != 0)
            && object->friction_core != *(IVP_Core **)(v22 + 152)
            && (!x_3 || (**(_WORD **)(v22 + 148) & 0x12) == 0)
            && (!v20 || (*(_DWORD *)(v22 + 68) & 0x200) == 0) )
          {
            if ( (isStaticSolid && (*(_DWORD *)(v22 + 68) & 0x200) != 0
               || v20 && (*(_DWORD *)(v22 + 68) & 0x400) != 0
               || coll_filter->check_objects_for_collision_detection(
                    this: coll_filter,
                    a2: object,
                    a3: (IVP_Real_Object *)v22) != 0)
              && IVP_Diff_Hash<IVP_OO_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_Real_Object>::check_element(
                   this: &diff_hash,
                   elem: (IVP_Real_Object *)v22,
                   reference: object) == nullptr )
            {
              IVP_U_Vector<IVP_Real_Object>::add(this: &new_objects, elem: (IVP_Real_Object *)v22);
            }
            v20 = isDebris;
          }
          --v21;
        }
        while ( v21 >= 0 );
        elem_buffer = (IVP_Vector_of_Objects_128 *)new_objects.elems;
      }
      n_found_objects = diff_hash.n_found_objects;
      v24 = elem->collision_fvector.n_elems - 1;
      if ( v24 >= diff_hash.n_found_objects )
      {
        do
        {
          v25 = elem->collision_fvector.elems[v24];
          if ( v25 != nullptr )
            (*(void (__thiscall **)(void *, int))(*(_DWORD *)v25 + 16))(a1: v25, a2: 1);
          --v24;
        }
        while ( v24 >= n_found_objects );
        elem_buffer = (IVP_Vector_of_Objects_128 *)new_objects.elems;
      }
      v26 = new_objects.n_elems - 1;
      xa = v26;
      if ( new_objects.n_elems != 0 )
      {
        do
        {
          environment = v40->environment;
          v28 = environment->collision_delegator_roots.n_elems - 1;
          v29 = *((_DWORD *)&elem_buffer->memsize + v26);
          if ( environment->collision_delegator_roots.n_elems != 0 )
          {
            do
            {
              v30 = v40->environment->collision_delegator_roots.elems[v28];
              if ( (*(int (__thiscall **)(void *, IVP_Real_Object *, int))(*(_DWORD *)v30 + 20))(
                     a1: v30,
                     a2: object,
                     a3: v29) != 0 )
                break;
              --v28;
            }
            while ( v28 >= 0 );
            elem_buffer = (IVP_Vector_of_Objects_128 *)new_objects.elems;
            v26 = xa;
          }
          xa = --v26;
        }
        while ( v26 >= 0 );
      }
      if ( elem_buffer != (IVP_Vector_of_Objects_128 *)new_objects.elem_buffer )
      {
        if ( elem_buffer != nullptr )
          free(data: elem_buffer);
        new_objects.elems = nullptr;
        new_objects.memsize = 0;
      }
      new_objects.n_elems = 0;
      if ( diff_hash.private_buffer != IVP_FALSE && diff_hash.hash_to_vector_index != nullptr )
        free(data: diff_hash.hash_to_vector_index);
    }
    if ( colliding_elements.elems != colliding_elements.elem_buffer && colliding_elements.elems != nullptr )
      free(data: colliding_elements.elems);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090010
// Name: public: void IVP_Mindist_Manager::enable_collision_detection_for_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::enable_collision_detection_for_object(
        IVP_Mindist_Manager *this,
        IVP_Real_Object *object)
{
  IVP_OV_Element *ov_element; // ecx
  IVP_OV_Element *v4; // eax

  ov_element = object->ov_element;
  if ( ov_element != nullptr )
    ((void (__thiscall *)(IVP_OV_Element *, int))ov_element->dtr_IVP_OV_Element)(a1: ov_element, a2: 1);
  object->ov_element = nullptr;
  v4 = (IVP_OV_Element *)p_malloc(size: 0x30u);
  if ( v4 != nullptr )
    object->ov_element = IVP_OV_Element::IVP_OV_Element(this: v4, obj: object);
  else
    object->ov_element = nullptr;
  IVP_Mindist_Manager::recheck_ov_element(this, object);
}

//------------------------------------------------------------------------------
// Address: 0x10090080
// Name: public: void IVP_Mindist_Manager::recalc_all_exact_mindists_events(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Manager::recalc_all_exact_mindists_events(IVP_Mindist_Manager *this)
{
  IVP_Mindist *exact_mindists; // esi
  IVP_Mindist *next; // edx
  float *physical_core; // ebx
  bool v4; // zf
  float *v5; // eax
  IVP_Environment *environment; // edi
  float v7; // xmm0_4
  float len_numerator; // xmm6_4
  int v9; // ecx
  float v10; // xmm7_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  IVP_Mindist *v18; // edx
  int mindist_coll_dist_count; // eax
  double v20; // xmm0_8
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  int seconds_high; // eax
  float v25; // xmm1_4
  unsigned int v26; // eax
  char v27; // cl
  float v28; // [esp+10h] [ebp-54h] BYREF
  float v29; // [esp+14h] [ebp-50h]
  float v30; // [esp+18h] [ebp-4Ch]
  float v31; // [esp+1Ch] [ebp-48h]
  IVP_Mindist *v32; // [esp+20h] [ebp-44h]
  IVP_Environment *v33; // [esp+24h] [ebp-40h]
  long double seconds; // [esp+28h] [ebp-3Ch]
  long double v35; // [esp+30h] [ebp-34h]
  int v36; // [esp+38h] [ebp-2Ch]
  double v37; // [esp+40h] [ebp-24h]
  double v38; // [esp+48h] [ebp-1Ch]
  float v39; // [esp+50h] [ebp-14h]
  float v40; // [esp+58h] [ebp-Ch]
  float v41; // [esp+5Ch] [ebp-8h]
  IVP_Mindist *mdist_next; // [esp+60h] [ebp-4h]

  exact_mindists = this->exact_mindists;
  if ( exact_mindists != nullptr )
  {
    while ( 1 )
    {
      next = exact_mindists->next;
      mdist_next = next;
      if ( next != nullptr )
      {
        _mm_prefetch((const char *)next, 2);
        _mm_prefetch((const char *)&next->synapse[0].next, 2);
        _mm_prefetch((const char *)&next->synapse[1].prev, 2);
        _mm_prefetch((const char *)&next->contact_plane, 2);
      }
      physical_core = (float *)exact_mindists->synapse[(*((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) >> 8) & 3].l_obj->physical_core;
      v4 = exact_mindists->index == 0xFFFF;
      v5 = (float *)exact_mindists->synapse[((*((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].l_obj->physical_core;
      environment = exact_mindists->synapse[0].l_obj->environment;
      v28 = physical_core[105] + v5[105];
      v7 = (float)(physical_core[79] + v28) + v5[79];
      v41 = *(float *)&v5;
      v31 = v7;
      if ( !v4 )
      {
        IVP_Time_Manager::remove_event(this: environment->time_manager, event: exact_mindists);
        v7 = v31;
        *(float *)&v5 = v41;
        next = mdist_next;
        exact_mindists->index = 0xFFFF;
      }
      len_numerator = exact_mindists->len_numerator;
      v9 = (unsigned __int8)(*((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) >> 22);
      v10 = ivp_mindist_settings.coll_dists[v9];
      v11 = (float)((float)(environment->delta_PSI_time * v7) * 2.0999999) + v10;
      v40 = v10;
      if ( len_numerator > v11 )
      {
        IVP_Mindist_Manager::remove_exact_mindist(this: environment->mindist_manager, del_mindist: exact_mindists);
        IVP_Mindist_Manager::insert_hull_mindist(md: exact_mindists, hull_time: exact_mindists->len_numerator - v40);
        goto LABEL_28;
      }
      v12 = exact_mindists->contact_plane.k[0];
      v13 = exact_mindists->contact_plane.k[1];
      v14 = exact_mindists->contact_plane.k[2];
      v29 = (float)((float)((float)(v5[53] * v13) + (float)(v12 * v5[52])) + (float)(v5[54] * v14))
          - (float)((float)((float)(physical_core[53] * v13) + (float)(physical_core[52] * v12))
                  + (float)(physical_core[54] * v14));
      v15 = (float)((float)(physical_core[73] * v13) + (float)(physical_core[72] * v12))
          + (float)(physical_core[74] * v14);
      v16 = (float)((float)(v5[73] * v13) + (float)(v12 * v5[72])) + (float)(v5[74] * v14);
      v41 = v16 * v16;
      v17 = (float)((float)(fsqrt(1.001 - (float)(v16 * v16)) * v5[105])
                  + (float)(fsqrt(1.001 - (float)(v15 * v15)) * physical_core[105]))
          + v29;
      v30 = v17;
      seconds = environment->current_time.seconds;
      v35 = environment->time_of_next_psi.seconds;
      v39 = len_numerator;
      if ( ivp_mindist_settings.speed_after_keeper_dist > v17 && v17 < 1.0e-10
        || len_numerator >= (float)((float)((float)(v35 - seconds) * v17) + v10)
        || (*((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) & 0x3000) == 0x1000 )
      {
        goto LABEL_29;
      }
      v18 = exact_mindists;
      v32 = exact_mindists;
      v33 = environment;
      if ( v9 != 0 )
      {
        mindist_coll_dist_count = environment->mindist_coll_dist_count;
        environment->mindist_coll_dist_count = mindist_coll_dist_count + 1;
        if ( mindist_coll_dist_count > 2 )
        {
          *((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) ^= (*((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5)
                                                               ^ (((*((_DWORD *)&exact_mindists->IVP_Mindist_Base + 5) >> 22)
                                                                 - 1) << 22))
                                                              & 0x3FC00000;
          environment->mindist_coll_dist_count = 0;
        }
        v18 = v32;
      }
      IVP_Mindist_Event_Solver::mim_function_table[v18->synapse[(*((_DWORD *)&v18->IVP_Mindist_Base + 5) >> 8) & 3].status][v18->synapse[((*((_DWORD *)&v18->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].status](a1: (IVP_Mindist_Event_Solver *)&v28);
      if ( v36 != 0 )
        break;
LABEL_28:
      next = mdist_next;
LABEL_29:
      exact_mindists = next;
      if ( next == nullptr )
        return;
    }
    v20 = v37;
    v21 = v37 - seconds;
    if ( v21 >= 0.000001 )
      goto LABEL_27;
    v22 = v39 - ivp_mindist_settings.real_coll_dist;
    if ( (v36 & 0xF) != 0 )
    {
      if ( v22 >= 0.000001 )
      {
        v20 = (float)(v22 / v31)
            + environment->current_time.seconds
            + (float)((float)(ivp_mindist_settings.event_queue_min_delta_time_base * 0.000099999997)
                    * environment->delta_PSI_time);
        goto LABEL_26;
      }
      v23 = ivp_mindist_settings.event_queue_min_delta_time_base * 0.001;
    }
    else
    {
      if ( v22 >= 0.000001 )
      {
        v20 = (float)((float)(v22 * 0.1) / v31)
            + environment->current_time.seconds
            + (float)((float)(ivp_mindist_settings.event_queue_min_delta_time_base * 0.0000001)
                    * environment->delta_PSI_time);
        goto LABEL_26;
      }
      v23 = ivp_mindist_settings.event_queue_min_delta_time_base * 0.0000099999997;
    }
    v20 = (float)(v23 * environment->delta_PSI_time) + environment->current_time.seconds;
LABEL_26:
    v37 = v20;
    seconds_high = HIDWORD(environment->time_of_next_psi.seconds);
    LODWORD(v38) = LODWORD(environment->time_of_next_psi.seconds);
    HIDWORD(v38) = seconds_high;
    v25 = v20 - v38;
    if ( v25 < 0.0 )
    {
LABEL_27:
      v26 = IVP_U_Min_List::add(
              this: environment->time_manager->min_hash,
              elem: exact_mindists,
              value: v20 - environment->time_manager->base_time.seconds);
      v27 = v36;
      exact_mindists->index = v26;
      *((_BYTE *)&exact_mindists->IVP_Mindist_Base + 20) = v27;
      goto LABEL_28;
    }
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090510
// Name: protected: void IVP_Mindist::mindist_hull_limit_exceeded_event(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::mindist_hull_limit_exceeded_event(IVP_Mindist *this, float hull_intrusion_value)
{
  unsigned int v3; // ecx
  int v4; // edx
  IVP_Synapse *v5; // eax
  IVP_Real_Object *l_obj; // ecx
  IVP_Real_Object *v7; // edx
  IVP_Hull_Manager *p_hull_manager; // eax
  IVP_Core *physical_core; // ecx
  IVP_Core *v10; // eax
  IVP_Environment *environment; // edx
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm3_4
  float v17; // xmm6_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  IVP_Hull_Manager *v21; // edi
  float v22; // xmm4_4
  IVP_U_Min_List_Element *elems; // ecx
  IVP_U_Min_List_Element *v24; // ecx
  bool v25; // zf
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  IVP_Real_Object *v32; // esi
  IVP_Real_Object *v33; // esi
  IVP_Mindist_Manager *mindist_manager; // edi
  IVP_Time current_time; // [esp+14h] [ebp-28h]
  float v36; // [esp+20h] [ebp-1Ch]
  IVP_Synapse_Real *syn1; // [esp+24h] [ebp-18h]
  IVP_Synapse_Real *syn0; // [esp+28h] [ebp-14h]
  double seconds; // [esp+2Ch] [ebp-10h]
  IVP_Hull_Manager *m0; // [esp+30h] [ebp-Ch]
  float core0; // [esp+34h] [ebp-8h]
  IVP_Hull_Manager *m1; // [esp+38h] [ebp-4h]

  v3 = *((_DWORD *)&this->IVP_Mindist_Base + 5);
  if ( (v3 & 0x3C0000) == 0x100000 )
  {
    IVP_Mindist_Recursive::rec_hull_limit_exceeded_event((IVP_Mindist_Recursive *)this);
  }
  else
  {
    v4 = (v3 >> 8) & 3;
    v5 = &this->synapse[((v3 ^ 0x100) >> 8) & 3];
    l_obj = this->synapse[((v3 ^ 0x100) >> 8) & 3].l_obj;
    syn0 = (IVP_Synapse_Real *)&this->synapse[v4];
    v7 = this->synapse[v4].l_obj;
    _mm_prefetch((const char *)&v7->hull_manager, 2);
    _mm_prefetch((const char *)&v7->hull_manager.sorted_synapses, 2);
    m0 = (IVP_Hull_Manager *)&v7->hull_manager;
    syn1 = (IVP_Synapse_Real *)v5;
    p_hull_manager = (IVP_Hull_Manager *)&l_obj->hull_manager;
    physical_core = l_obj->physical_core;
    m1 = p_hull_manager;
    v10 = v7->physical_core;
    environment = v7->environment;
    v12 = v10->delta_world_f_core_psis.k[1];
    v13 = v10->delta_world_f_core_psis.k[2];
    _mm_prefetch((const char *)&STACK[0x170], 2);
    _mm_prefetch((const char *)m1, 2);
    _mm_prefetch((const char *)&m1->sorted_synapses, 2);
    v14 = physical_core->delta_world_f_core_psis.k[1];
    v15 = physical_core->delta_world_f_core_psis.k[2];
    _mm_prefetch((const char *)&v10->m_world_f_core_last_psi.vv, 2);
    _mm_prefetch((const char *)&physical_core->m_world_f_core_last_psi.vv, 2);
    _mm_prefetch((const char *)&STACK[0x170], 2);
    *(IVP_Time *)&current_time.seconds = environment->current_time;
    v16 = current_time.seconds - v10->time_of_last_psi.seconds;
    v17 = current_time.seconds - physical_core->time_of_last_psi.seconds;
    v18 = (float)((float)(v10->delta_world_f_core_psis.k[0] * v16) + v10->pos_world_f_core_last_psi.k[0])
        - (float)((float)(physical_core->delta_world_f_core_psis.k[0] * v17)
                + physical_core->pos_world_f_core_last_psi.k[0]);
    v19 = (float)((float)(v12 * v16) + v10->pos_world_f_core_last_psi.k[1])
        - (float)((float)(v14 * v17) + physical_core->pos_world_f_core_last_psi.k[1]);
    v20 = (float)((float)(v13 * v16) + v10->pos_world_f_core_last_psi.k[2])
        - (float)((float)(v15 * v17) + physical_core->pos_world_f_core_last_psi.k[2]);
    core0 = (float)(v10->max_surface_rot_speed + v10->current_speed) + 1.0e-10;
    v21 = m0;
    v22 = physical_core->max_surface_rot_speed + physical_core->current_speed;
    elems = m0->sorted_synapses.elems;
    _mm_prefetch((const char *)&elems[m0->sorted_synapses.first_element], 2);
    _mm_prefetch((const char *)&elems[m0->sorted_synapses.first_element + 2], 2);
    _mm_prefetch((const char *)&elems[m0->sorted_synapses.first_long], 2);
    v24 = m1->sorted_synapses.elems;
    _mm_prefetch((const char *)&v24[m1->sorted_synapses.first_element], 2);
    _mm_prefetch((const char *)&v24[m1->sorted_synapses.first_element + 2], 2);
    v25 = (*((_DWORD *)&this->IVP_Mindist_Base + 5) & 0x30000) == 0;
    _mm_prefetch((const char *)&v24[m1->sorted_synapses.first_long], 2);
    v36 = v22 + 1.0e-10;
    v26 = (float)(v22 + 1.0e-10) + core0;
    if ( v25
      && (v27 = (float)((float)(this->contact_plane.k[1] * v19) + (float)(v18 * this->contact_plane.k[0]))
              + (float)(this->contact_plane.k[2] * v20),
          seconds = environment->current_time.seconds,
          v28 = seconds - v21->last_vpsi_time.seconds,
          v29 = seconds - m1->last_vpsi_time.seconds,
          v30 = (float)((float)((float)(v21->gradient - v21->center_gradient) * v28)
                      + (float)(v21->hull_value_last_vpsi - v21->hull_center_value_last_vpsi))
              + (float)((float)((float)(m1->gradient - m1->center_gradient) * v29)
                      + (float)(m1->hull_value_last_vpsi - m1->hull_center_value_last_vpsi)),
          (v31 = (float)((float)(this->len_numerator - (float)(v30 - this->sum_angular_hull_time))
                       - (float)(this->contact_dot_diff_center - v27))
               + hull_intrusion_value) > (float)((float)(environment->delta_PSI_time * v26) * 6.0)) )
    {
      this->sum_angular_hull_time = v30;
      this->contact_dot_diff_center = v27;
      this->len_numerator = v31 - hull_intrusion_value;
      v32 = syn0->l_obj;
      IVP_U_Min_List::remove_minlist_elem(this: &v32->hull_manager.sorted_synapses, index: syn0->minlist_index);
      syn0->minlist_index = IVP_U_Min_List::add(
                              this: &v32->hull_manager.sorted_synapses,
                              elem: syn0,
                              value: (float)((float)(v31 / v26) * core0)
                            + (float)((float)((float)(current_time.seconds - v32->hull_manager.last_vpsi_time.seconds)
                                            * v32->hull_manager.gradient)
                                    + v32->hull_manager.hull_value_last_vpsi));
      v33 = syn1->l_obj;
      IVP_U_Min_List::remove_minlist_elem(this: &v33->hull_manager.sorted_synapses, index: syn1->minlist_index);
      syn1->minlist_index = IVP_U_Min_List::add(
                              this: &v33->hull_manager.sorted_synapses,
                              elem: syn1,
                              value: (float)((float)(v31 / v26) * v36)
                            + (float)((float)((float)(current_time.seconds - v33->hull_manager.last_vpsi_time.seconds)
                                            * v33->hull_manager.gradient)
                                    + v33->hull_manager.hull_value_last_vpsi));
    }
    else
    {
      mindist_manager = environment->mindist_manager;
      IVP_U_Min_List::remove_minlist_elem(
        this: &this->synapse[0].l_obj->hull_manager.sorted_synapses,
        index: this->synapse[0].minlist_index);
      IVP_U_Min_List::remove_minlist_elem(
        this: &this->synapse[1].l_obj->hull_manager.sorted_synapses,
        index: this->synapse[1].minlist_index);
      if ( (*((_DWORD *)&this->IVP_Mindist_Base + 5) & 0x3000) == 0x1000 )
        IVP_Mindist_Manager::insert_and_recalc_phantom_mindist(this: mindist_manager, new_mindist: this);
      else
        IVP_Mindist_Manager::insert_and_recalc_exact_mindist(this: mindist_manager, new_mindist: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090920
// Name: public: void IVP_Mindist::init_mindist(class IVP_Real_Object __near *,class IVP_Real_Object __near *,class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::init_mindist(
        IVP_Mindist *this,
        IVP_Real_Object *pop0,
        IVP_Real_Object *pop1,
        const IVP_Compact_Edge *e0,
        const IVP_Compact_Edge *e1)
{
  IVP_Real_Object *v6; // ecx
  IVP_Synapse *synapse; // esi
  IVP_Synapse *v8; // edi
  IVP_Real_Object *v9; // edx
  IVP_Mindist_Manager *mindist_manager; // eax

  v6 = pop1;
  synapse = this->synapse;
  v8 = &this->synapse[1];
  if ( pop1->object_type == IVP_POLYGON )
  {
    this->synapse[1].mindist_offset = -52;
    this->synapse[1].l_obj = pop1;
    this->synapse[1].edge = e1;
    this->synapse[1].status = 0;
    pop1->surface_manager->add_reference_to_ledge(
      this: pop1->surface_manager,
      a2: (const IVP_Compact_Ledge *)(((unsigned int)e1 & 0xFFFFFFF0)
                                - 16 * ((*(_DWORD *)((unsigned int)e1 & 0xFFFFFFF0) & 0xFFF) + 1)));
    goto LABEL_9;
  }
  if ( pop1->object_type != IVP_BALL )
  {
    _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist.cxx", 257);
LABEL_9:
    v6 = pop1;
    v9 = pop0;
    goto LABEL_10;
  }
  v9 = pop0;
  if ( pop0->object_type != IVP_BALL || pop0->client_data < pop1->client_data )
  {
    synapse = &this->synapse[1];
    v8 = this->synapse;
  }
  v8->mindist_offset = (_WORD)this - (_WORD)v8;
  v8->edge = e1;
  v8->l_obj = pop1;
  v8->status = 3;
LABEL_10:
  if ( v9->object_type == IVP_POLYGON )
  {
    synapse->edge = e0;
    synapse->mindist_offset = (_WORD)this - (_WORD)synapse;
    synapse->status = 0;
    synapse->l_obj = v9;
    v9->surface_manager->add_reference_to_ledge(
      this: pop0->surface_manager,
      a2: (const IVP_Compact_Ledge *)(((unsigned int)e0 & 0xFFFFFFF0)
                                - 16 * ((*(_DWORD *)((unsigned int)e0 & 0xFFFFFFF0) & 0xFFF) + 1)));
    goto LABEL_15;
  }
  if ( v9->object_type != IVP_BALL )
  {
    _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist.cxx", 268);
LABEL_15:
    v6 = pop1;
    v9 = pop0;
    goto LABEL_16;
  }
  synapse->mindist_offset = (_WORD)this - (_WORD)synapse;
  synapse->edge = e0;
  synapse->l_obj = v9;
  synapse->status = 3;
LABEL_16:
  synapse->mindist_offset = (_WORD)this - (_WORD)synapse;
  v8->mindist_offset = (_WORD)this - (_WORD)v8;
  this->sum_extra_radius = v9->extra_radius + v6->extra_radius;
  mindist_manager = v9->environment->mindist_manager;
  if ( v9->controller_phantom != nullptr || v6->controller_phantom != nullptr )
  {
    *((_DWORD *)&this->IVP_Mindist_Base + 5) = *((_DWORD *)&this->IVP_Mindist_Base + 5) & 0xFFFFCFFF | 0x1000;
    IVP_Mindist_Manager::insert_and_recalc_phantom_mindist(this: mindist_manager, new_mindist: this);
  }
  else
  {
    IVP_Mindist_Manager::insert_and_recalc_exact_mindist(this: mindist_manager, new_mindist: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090AD0
// Name: public: static void IVP_Mindist_Manager::create_exact_mindists(class IVP_Real_Object __near *,class IVP_Real_Object __near *,float,class IVP_U_FVector<class IVP_Collision> __near *,class IVP_Compact_Ledge const __near *,class IVP_Compact_Ledge const __near *,class IVP_Compact_Ledge const __near *,class IVP_Compact_Ledge const __near *,class IVP_Collision_Delegator __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Mindist_Manager::create_exact_mindists(
        int a1@<ebp>,
        IVP_Real_Object *pop0,
        IVP_Real_Object *pop1,
        float scan_radius,
        IVP_U_FVector<IVP_Collision> *mindists,
        const IVP_Compact_Ledge *single_ledge0,
        const IVP_Compact_Ledge *single_ledge1,
        const IVP_Compact_Ledge *root_ledge0,
        const IVP_Compact_Ledge *root_ledge1,
        IVP_Collision_Delegator *oo_watcher)
{
  void *v10; // esp
  IVP_Environment *environment; // esi
  IVP_Core *physical_core; // eax
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float extra_radius; // xmm0_4
  IVP_Cache_Object *cache_object; // ecx
  IVP_Core *v20; // eax
  int seconds_low; // ecx
  float v22; // xmm1_4
  float v23; // xmm3_4
  bool v24; // zf
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  IVP_Cache_Object *v28; // ecx
  int n_elems; // eax
  IVP_U_FVector<IVP_Collision> *v30; // edi
  int v31; // ecx
  int v32; // eax
  int v33; // eax
  int v34; // edi
  const IVP_Compact_Ledge *v35; // eax
  IVP_Mindist_Recursive *v36; // eax
  unsigned int v37; // edx
  IVP_Mindist_Recursive *v38; // edi
  IVP_Mindist_Recursive *v39; // eax
  int i; // esi
  void *v41; // ecx
  int v42; // ecx
  void *v43; // esi
  int v44; // eax
  __int16 v45[1024]; // [esp+1Ch] [ebp-1284h] BYREF
  int v46; // [esp+81Ch] [ebp-A84h] BYREF
  int v47; // [esp+820h] [ebp-A80h]
  _DWORD *v48; // [esp+824h] [ebp-A7Ch]
  _DWORD v49[257]; // [esp+828h] [ebp-A78h] BYREF
  IVP_U_BigVector_Base v50; // [esp+C2Ch] [ebp-674h] BYREF
  _BYTE v51[1028]; // [esp+C38h] [ebp-668h] BYREF
  IVP_U_Vector_Base v52; // [esp+103Ch] [ebp-264h] BYREF
  _BYTE v53[512]; // [esp+1044h] [ebp-25Ch] BYREF
  IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key> v54; // [esp+1244h] [ebp-5Ch] BYREF
  const IVP_Compact_Ledge *v55; // [esp+1268h] [ebp-38h]
  int v56; // [esp+126Ch] [ebp-34h]
  int v57; // [esp+1270h] [ebp-30h]
  IVP_MM_CMP_Key v58; // [esp+1274h] [ebp-2Ch] BYREF
  long double seconds; // [esp+128Ch] [ebp-14h]
  int v60; // [esp+1294h] [ebp-Ch]
  void *v61; // [esp+1298h] [ebp-8h]
  void *retaddr; // [esp+12A0h] [ebp+0h]

  v60 = a1;
  v61 = retaddr;
  v10 = alloca(4728);
  v48 = v49;
  v46 = 256;
  v50.memsize = 256;
  environment = pop0->environment;
  v47 = 0;
  v50.elems = (void **)v51;
  v50.n_elems = 0;
  if ( single_ledge0 != nullptr )
  {
    v49[0] = single_ledge0;
    v47 = 1;
  }
  else
  {
    physical_core = pop1->physical_core;
    v13 = physical_core->delta_world_f_core_psis.k[2];
    v14 = physical_core->delta_world_f_core_psis.k[0];
    seconds = environment->current_time.seconds;
    v15 = seconds - physical_core->time_of_last_psi.seconds;
    v16 = (float)(v13 * v15) + physical_core->pos_world_f_core_last_psi.k[2];
    v17 = (float)(v14 * v15) + physical_core->pos_world_f_core_last_psi.k[0];
    *(float *)&v58.object[1] = (float)(physical_core->delta_world_f_core_psis.k[1] * v15)
                             + physical_core->pos_world_f_core_last_psi.k[1];
    extra_radius = pop0->extra_radius;
    *(float *)v58.object = v17;
    *(float *)v58.ledge = v16;
    *((float *)&seconds + 1) = (float)(extra_radius + physical_core->upper_limit_radius) + scan_radius;
    if ( pop0->cache_object == nullptr )
      pop0->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                             this: environment->cache_object_manager,
                             object: pop0);
    if ( *(_BYTE *)&pop0->flags < 8 )
    {
      cache_object = pop0->cache_object;
      if ( pop0->environment->current_time_code > cache_object->valid_until_time_code )
        IVP_Cache_Object::update_cache_object(this: cache_object);
    }
    IVP_U_Matrix::vimult4(
      this: &pop0->cache_object->m_world_f_object,
      p_in: (const IVP_U_Float_Point *)&v58,
      p_out: (IVP_U_Float_Point *)&v54);
    ((void (__stdcall *)(IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key> *, _DWORD, const IVP_Compact_Ledge *, _DWORD, const IVP_Compact_Ledge *, int *))pop0->surface_manager->get_all_ledges_within_radius)(
      a1: &v54,
      a2: HIDWORD(seconds),
      a3: root_ledge0,
      a4: 0,
      a5: single_ledge1,
      a6: &v46);
  }
  if ( single_ledge1 != nullptr )
  {
    if ( v50.n_elems >= v50.memsize )
      IVP_U_BigVector_Base::increment_mem(this: &v50);
    v50.elems[v50.n_elems] = (void *)single_ledge1;
    n_elems = ++v50.n_elems;
  }
  else
  {
    v20 = pop0->physical_core;
    seconds_low = LODWORD(environment->current_time.seconds);
    v22 = v20->delta_world_f_core_psis.k[2];
    v23 = v20->delta_world_f_core_psis.k[0];
    v24 = pop1->cache_object == nullptr;
    HIDWORD(seconds) = HIDWORD(environment->current_time.seconds);
    LODWORD(seconds) = seconds_low;
    v25 = seconds - v20->time_of_last_psi.seconds;
    v26 = (float)(v22 * v25) + v20->pos_world_f_core_last_psi.k[2];
    v27 = (float)(v23 * v25) + v20->pos_world_f_core_last_psi.k[0];
    *(float *)&v58.object[1] = (float)(v20->delta_world_f_core_psis.k[1] * v25) + v20->pos_world_f_core_last_psi.k[1];
    *(float *)v58.object = v27;
    *(float *)v58.ledge = v26;
    *((float *)&seconds + 1) = (float)(v20->upper_limit_radius + pop1->extra_radius) + scan_radius;
    if ( v24 )
      pop1->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                             this: pop1->environment->cache_object_manager,
                             object: pop1);
    if ( *(_BYTE *)&pop1->flags < 8 )
    {
      v28 = pop1->cache_object;
      if ( pop1->environment->current_time_code > v28->valid_until_time_code )
        IVP_Cache_Object::update_cache_object(this: v28);
    }
    IVP_U_Matrix::vimult4(
      this: &pop1->cache_object->m_world_f_object,
      p_in: (const IVP_U_Float_Point *)&v58,
      p_out: (IVP_U_Float_Point *)&v54);
    ((void (__stdcall *)(IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key> *, _DWORD, const IVP_Compact_Ledge *, _DWORD, const IVP_Compact_Ledge *, IVP_U_BigVector_Base *))pop1->surface_manager->get_all_ledges_within_radius)(
      a1: &v54,
      a2: HIDWORD(seconds),
      a3: root_ledge1,
      a4: 0,
      a5: single_ledge0,
      a6: &v50);
    n_elems = v50.n_elems;
  }
  v30 = mindists;
  v31 = 1024;
  v32 = 2 * (mindists->n_elems + v47 * n_elems) + 2;
  if ( v32 < 1024 )
  {
    do
      v31 >>= 1;
    while ( v31 > v32 );
  }
  IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key>::IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key>(
    this: &v54,
    base: mindists,
    buffer: v45,
    buffer_size: v31,
    reference: nullptr);
  v33 = v47 - 1;
  v52.elems = (void **)v53;
  *(_DWORD *)&v52.memsize = 128;
  HIDWORD(seconds) = v47 - 1;
  if ( v47 - 1 >= 0 )
  {
    while ( 1 )
    {
      v34 = v50.n_elems - 1;
      v57 = v48[v33];
      v58.ledge[0] = (const IVP_Compact_Ledge *)v57;
      v58.object[0] = pop0;
      v56 = v50.n_elems - 1;
      if ( v50.n_elems - 1 < 0 )
        goto LABEL_36;
      do
      {
        v35 = (const IVP_Compact_Ledge *)v50.elems[v34];
        v58.object[1] = pop1;
        v55 = v35;
        v58.ledge[1] = v35;
        if ( IVP_Diff_Hash<IVP_MM_CMP,IVP_U_FVector<IVP_Collision>,IVP_Collision,IVP_MM_CMP_Key>::check_element(
               this: &v54,
               elem: &v58,
               reference: nullptr) != nullptr )
          goto LABEL_34;
        if ( (*(_BYTE *)(v57 + 8) & 3) != 0 || (*((_BYTE *)v55 + 8) & 3) != 0 )
        {
          v39 = (IVP_Mindist_Recursive *)p_malloc(size: 0xA0u);
          if ( v39 == nullptr )
          {
LABEL_30:
            v38 = nullptr;
            goto LABEL_31;
          }
          v38 = IVP_Mindist_Recursive::IVP_Mindist_Recursive(this: v39, env: environment, del: oo_watcher);
        }
        else
        {
          v36 = (IVP_Mindist_Recursive *)p_malloc(size: 0x80u);
          if ( v36 == nullptr )
            goto LABEL_30;
          v36->delegator = oo_watcher;
          v36->fvector_index[1] = -1;
          v36->fvector_index[0] = -1;
          v36->synapse[0].__vftable = (IVP_Synapse_vtbl *)&IVP_Synapse::`vftable';
          v36->synapse[1].__vftable = (IVP_Synapse_vtbl *)&IVP_Synapse::`vftable';
          *((_BYTE *)&v36->IVP_Mindist_Base + 20) = 0;
          v37 = *((_DWORD *)&v36->IVP_Mindist_Base + 5) & 0xCFC000FF;
          v36->recalc_time_stamp = 0;
          v36->last_visited_triangle = nullptr;
          *((_DWORD *)&v36->IVP_Mindist_Base + 5) = v37 | 0xFC00000;
          v36->sum_angular_hull_time = 0.0;
          v36->index = 0xFFFF;
          v36->IVP_Mindist::IVP_Mindist_Base::IVP_Collision::IVP_Time_Event::__vftable = (IVP_Mindist_Recursive_vtbl *)&IVP_Mindist::`vftable';
          ++environment->statistic_manager.sum_of_mindists;
          ++environment->statistic_manager.mindists_generated;
          v38 = v36;
        }
LABEL_31:
        IVP_Mindist::init_mindist(
          this: v38,
          pop0,
          pop1,
          e0: (const IVP_Compact_Edge *)(v57 + 20),
          e1: (const IVP_Compact_Edge *)&v55[1].___u1);
        if ( v52.n_elems >= v52.memsize )
          IVP_U_Vector_Base::increment_mem(this: &v52);
        v52.elems[v52.n_elems++] = v38;
        v34 = v56;
LABEL_34:
        v56 = --v34;
      }
      while ( v34 >= 0 );
      v33 = HIDWORD(seconds);
LABEL_36:
      HIDWORD(seconds) = --v33;
      if ( v33 < 0 )
      {
        v30 = mindists;
        break;
      }
    }
  }
  for ( i = v30->n_elems - 1; i >= v54.n_found_objects; --i )
  {
    v41 = v30->elems[i];
    if ( v41 != nullptr )
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)v41 + 16))(a1: v41, a2: 1);
  }
  v42 = v52.n_elems - 1;
  HIDWORD(seconds) = v42;
  if ( v52.n_elems != 0 )
  {
    do
    {
      v43 = v52.elems[v42];
      if ( v30->n_elems >= v30->memsize )
      {
        IVP_U_Vector_Base::increment_mem(this: v30);
        v42 = HIDWORD(seconds);
      }
      v30->elems[v30->n_elems] = v43;
      v44 = v30->n_elems;
      if ( *((_DWORD *)v43 + 3) == -1 )
        *((_DWORD *)v43 + 3) = v44;
      else
        *((_DWORD *)v43 + 4) = v44;
      ++v30->n_elems;
      HIDWORD(seconds) = --v42;
    }
    while ( v42 >= 0 );
  }
  if ( (_BYTE *)v52.elems != v53 )
  {
    if ( v52.elems != nullptr )
      free(data: v52.elems);
    v52.elems = nullptr;
    v52.memsize = 0;
  }
  v52.n_elems = 0;
  if ( v54.private_buffer != IVP_FALSE && v54.hash_to_vector_index != nullptr )
    free(data: v54.hash_to_vector_index);
  if ( (_BYTE *)v50.elems != v51 )
  {
    if ( v50.elems != nullptr )
      free(data: v50.elems);
    v50.elems = nullptr;
    v50.memsize = 0;
  }
  v50.n_elems = 0;
  if ( v48 != v49 && v48 != nullptr )
    free(data: v48);
}

//------------------------------------------------------------------------------
// Address: 0x10091070
// Name: protected: virtual void IVP_Synapse::hull_limit_exceeded_event(class IVP_Hull_Manager __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Synapse::hull_limit_exceeded_event(
        IVP_Synapse *this,
        IVP_Hull_Manager *__formal,
        float hull_intrusion_value)
{
  IVP_Mindist::mindist_hull_limit_exceeded_event(
    this: (IVP_Mindist *)((char *)this + this->mindist_offset),
    hull_intrusion_value);
}
