// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_polygon.cxx
// Functions: 1
// ============================================================

#include "ivp\ivp_intern\ivp_polygon.h"

//------------------------------------------------------------------------------
// Address: 0x100971F0
// Name: protected: IVP_Polygon::IVP_Polygon(class IVP_Cluster __near *,class IVP_SurfaceManager __near *,class IVP_Template_Real_Object const __near *,class IVP_U_Quat const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Polygon *__thiscall IVP_Polygon::IVP_Polygon(
        IVP_Polygon *this,
        IVP_Cluster *cluster,
        IVP_SurfaceManager *surface_manager_,
        const IVP_Template_Real_Object *templ,
        const IVP_U_Quat *q_world_f_obj,
        const IVP_U_Point *position)
{
  IVP_Core *physical_core; // eax
  IVP_Event_Object event_created; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  IVP_Real_Object::IVP_Real_Object(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)templ,
    a4: (int)this,
    cluster,
    surface_manager_,
    templ_obj: templ,
    q_world_f_object: q_world_f_obj,
    position);
  this->__vftable = (IVP_Polygon_vtbl *)&IVP_Real_Object::`vftable';
  this->object_type = IVP_POLYGON;
  this->extra_radius = templ->extra_radius;
  IVP_Real_Object::init_object_core(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)templ,
    a4: (int)this,
    i_environment: cluster->environment,
    templ);
  physical_core = this->physical_core;
  event_created.real_object = this;
  event_created.environment = physical_core->environment;
  IVP_Environment::fire_event_object_created(this: physical_core->environment, obj_event: &event_created);
  return this;
}
