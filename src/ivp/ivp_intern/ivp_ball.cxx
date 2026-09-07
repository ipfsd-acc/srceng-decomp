// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_ball.cxx
// Functions: 7
// ============================================================

#include "ivp\ivp_intern\ivp_ball.h"

//------------------------------------------------------------------------------
// Address: 0x10097290
// Name: public: virtual void IVP_SurfaceManager_Ball::get_mass_center(class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Ball::get_mass_center(
        IVP_SurfaceManager_Ball *this,
        IVP_U_Float_Point *mass_center_out)
{
  *(_QWORD *)&mass_center_out->k[1] = 0;
  mass_center_out->k[0] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100972B0
// Name: public: virtual void IVP_SurfaceManager_Ball::get_radius_and_radius_dev_to_given_center(class IVP_U_Float_Point const __near *,float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Ball::get_radius_and_radius_dev_to_given_center(
        IVP_SurfaceManager_Ball *this,
        const IVP_U_Float_Point *__formal,
        const IVP_U_Float_Point *__formala,
        float *a4)
{
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_ball.cxx", 35);
}

//------------------------------------------------------------------------------
// Address: 0x100972D0
// Name: public: virtual void IVP_SurfaceManager_Ball::get_rotation_inertia(class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Ball::get_rotation_inertia(
        IVP_SurfaceManager_Ball *this,
        IVP_U_Float_Point *__formal)
{
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_ball.cxx", 36);
}

//------------------------------------------------------------------------------
// Address: 0x100972F0
// Name: public: virtual void IVP_SurfaceManager_Ball::insert_all_ledges_hitting_ray(class IVP_Ray_Solver __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Ball::insert_all_ledges_hitting_ray(
        IVP_SurfaceManager_Ball *this,
        IVP_Ray_Solver *__formal,
        IVP_Ray_Solver *__formala)
{
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_ball.cxx", 59);
}

//------------------------------------------------------------------------------
// Address: 0x10097350
// Name: protected: IVP_Ball::IVP_Ball(class IVP_Cluster __near *,class IVP_Template_Ball const __near *,class IVP_Template_Real_Object const __near *,class IVP_U_Quat const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Ball *__thiscall IVP_Ball::IVP_Ball(
        IVP_Ball *this,
        IVP_Cluster *father,
        const IVP_Template_Ball *tball,
        const IVP_Template_Real_Object *templ,
        const IVP_U_Quat *rotation,
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
    cluster: father,
    surface_manager_: nullptr,
    templ_obj: templ,
    q_world_f_object: rotation,
    position);
  this->__vftable = (IVP_Ball_vtbl *)&IVP_Ball::`vftable';
  this->object_type = IVP_BALL;
  this->extra_radius = templ->extra_radius + tball->radius;
  this->surface_manager = &ivp_surface_manager_ball_global;
  IVP_Real_Object::init_object_core(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)templ,
    a4: (int)this,
    i_environment: father->environment,
    templ);
  physical_core = this->physical_core;
  event_created.real_object = this;
  event_created.environment = physical_core->environment;
  IVP_Environment::fire_event_object_created(this: physical_core->environment, obj_event: &event_created);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097410
// Name: public: virtual void IVP_SurfaceManager_Ball::get_all_ledges_within_radius(class IVP_U_Point const __near *,float,class IVP_Compact_Ledge const __near *,class IVP_Real_Object __near *,class IVP_Compact_Ledge const __near *,class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Ball::get_all_ledges_within_radius(
        IVP_SurfaceManager_Ball *this,
        const IVP_U_Point *observer_position_object,
        float radius,
        const IVP_Compact_Ledge *__formal,
        IVP_Real_Object *a5,
        const IVP_Compact_Ledge *a6,
        IVP_U_BigVector<IVP_Compact_Ledge> *resulting_ledges)
{
  IVP_Compact_Ledge *compact_ledge; // edi

  if ( (float)((float)((float)(observer_position_object->k[0] * observer_position_object->k[0])
                     + (float)(observer_position_object->k[1] * observer_position_object->k[1]))
             + (float)(observer_position_object->k[2] * observer_position_object->k[2])) <= (float)(radius * radius) )
  {
    compact_ledge = this->compact_ledge;
    if ( resulting_ledges->n_elems >= resulting_ledges->memsize )
      IVP_U_BigVector_Base::increment_mem(this: resulting_ledges);
    resulting_ledges->elems[resulting_ledges->n_elems++] = (void *)compact_ledge;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097470
// Name: public: virtual void IVP_SurfaceManager_Ball::get_all_terminal_ledges(class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Ball::get_all_terminal_ledges(
        IVP_SurfaceManager_Ball *this,
        IVP_U_BigVector<IVP_Compact_Ledge> *resulting_ledges)
{
  IVP_Compact_Ledge *compact_ledge; // edi

  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_ball.cxx", 53);
  compact_ledge = this->compact_ledge;
  if ( resulting_ledges->n_elems >= resulting_ledges->memsize )
    IVP_U_BigVector_Base::increment_mem(this: resulting_ledges);
  resulting_ledges->elems[resulting_ledges->n_elems++] = (void *)compact_ledge;
}
