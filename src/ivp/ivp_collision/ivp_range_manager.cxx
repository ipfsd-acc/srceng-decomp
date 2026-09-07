// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_range_manager.cxx
// Functions: 4
// ============================================================

#include "ivp\ivp_collision\ivp_range_manager.h"

//------------------------------------------------------------------------------
// Address: 0x1009A410
// Name: public: IVP_Range_Manager::IVP_Range_Manager(class IVP_Environment __near *,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
IVP_Range_Manager *__thiscall IVP_Range_Manager::IVP_Range_Manager(
        IVP_Range_Manager *this,
        IVP_Environment *env,
        IVP_BOOL delete_this_on_env_delete)
{
  this->look_ahead_time_world = 1.0;
  this->look_ahead_max_radius_world = 5.0;
  this->look_ahead_min_distance_world = 0.5;
  this->look_ahead_time_intra = 0.5;
  this->look_ahead_max_radius_intra = 0.89999998;
  this->look_ahead_max_distance_world = 15.0;
  this->look_ahead_min_distance_intra = 0.80000001;
  this->__vftable = (IVP_Range_Manager_vtbl *)&IVP_Range_Manager::`vftable';
  this->bound_to_environment = delete_this_on_env_delete;
  this->environment = env;
  this->look_ahead_min_seconds_world = 0.059999999;
  this->look_ahead_max_distance_intra = 10.0;
  this->look_ahead_min_seconds_intra = 0.059999999;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009A4A0
// Name: public: virtual void IVP_Range_Manager::environment_will_be_deleted(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Range_Manager::environment_will_be_deleted(IVP_Range_Manager *this, IVP_Environment *__formal)
{
  if ( this->bound_to_environment != IVP_FALSE )
    free(data: this);
}

//------------------------------------------------------------------------------
// Address: 0x1009A4B0
// Name: public: virtual void IVP_Range_Manager::get_coll_range_intra_objects(class IVP_Real_Object const __near *,class IVP_Real_Object const __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Range_Manager::get_coll_range_intra_objects(
        IVP_Range_Manager *this,
        const IVP_Real_Object *obj0,
        const IVP_Real_Object *obj1,
        float *range0,
        float *range1)
{
  IVP_Core *physical_core; // edx
  IVP_Core *v6; // eax
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float upper_limit_radius; // xmm5_4
  float look_ahead_min_distance_intra; // xmm2_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm3_4

  physical_core = obj1->physical_core;
  v6 = obj0->physical_core;
  v7 = (float)(physical_core->max_surface_rot_speed + physical_core->current_speed) + 1.0e-10;
  v8 = (float)(v6->max_surface_rot_speed + v6->current_speed) + 1.0e-10;
  v9 = v7 + v8;
  if ( physical_core->upper_limit_radius <= v6->upper_limit_radius )
    upper_limit_radius = physical_core->upper_limit_radius;
  else
    upper_limit_radius = v6->upper_limit_radius;
  look_ahead_min_distance_intra = this->look_ahead_time_intra * v9;
  if ( look_ahead_min_distance_intra > (float)(this->look_ahead_max_radius_intra * upper_limit_radius) )
    look_ahead_min_distance_intra = this->look_ahead_max_radius_intra * upper_limit_radius;
  if ( this->look_ahead_min_distance_intra > look_ahead_min_distance_intra )
    look_ahead_min_distance_intra = this->look_ahead_min_distance_intra;
  if ( look_ahead_min_distance_intra > this->look_ahead_max_distance_intra )
    look_ahead_min_distance_intra = this->look_ahead_max_distance_intra;
  v12 = look_ahead_min_distance_intra - (float)(this->environment->delta_PSI_time * v9);
  if ( (float)(this->look_ahead_min_seconds_intra * v9) > v12 )
    v12 = this->look_ahead_min_seconds_intra * v9;
  v13 = (float)(v7 * 0.2) + v8;
  v14 = (float)(v13 * 0.18000001) + v7;
  v15 = 1.0 / (float)(v14 + v13);
  *range0 = (float)(v12 * v13) * v15;
  *range1 = (float)(v12 * v14) * v15;
}

//------------------------------------------------------------------------------
// Address: 0x1009A5D0
// Name: public: virtual float IVP_Range_Manager::get_coll_range_in_world(class IVP_Real_Object const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Range_Manager::get_coll_range_in_world(IVP_Range_Manager *this, const IVP_Real_Object *obj0)
{
  IVP_Core *physical_core; // eax
  float v3; // xmm1_4
  float upper_limit_radius; // xmm3_4
  float look_ahead_min_distance_world; // xmm0_4
  float max_dist; // [esp+8h] [ebp+8h]

  physical_core = obj0->physical_core;
  v3 = (float)(physical_core->max_surface_rot_speed + physical_core->current_speed) + 1.0e-10;
  upper_limit_radius = physical_core->upper_limit_radius;
  look_ahead_min_distance_world = this->look_ahead_time_world * v3;
  if ( look_ahead_min_distance_world > (float)(this->look_ahead_max_radius_world * upper_limit_radius) )
    look_ahead_min_distance_world = this->look_ahead_max_radius_world * upper_limit_radius;
  if ( this->look_ahead_min_distance_world > look_ahead_min_distance_world )
    look_ahead_min_distance_world = this->look_ahead_min_distance_world;
  if ( look_ahead_min_distance_world > this->look_ahead_max_distance_world )
    look_ahead_min_distance_world = this->look_ahead_max_distance_world;
  max_dist = look_ahead_min_distance_world - (float)(this->environment->delta_PSI_time * v3);
  if ( (float)((float)(this->look_ahead_min_seconds_world * v3) + upper_limit_radius) > max_dist )
    return (float)((float)(this->look_ahead_min_seconds_world * v3) + upper_limit_radius);
  return max_dist;
}
