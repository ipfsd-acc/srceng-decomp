// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_actuator_spring.cxx
// Functions: 18
// ============================================================

#include "ivp\ivp_controller\ivp_actuator_spring.h"

//------------------------------------------------------------------------------
// Address: 0x1008B910
// Name: public: IVP_Template_Spring::IVP_Template_Spring(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Spring *__thiscall IVP_Template_Spring::IVP_Template_Spring(IVP_Template_Spring *this)
{
  IVP_Template_Two_Point::IVP_Template_Two_Point(this);
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Template_Spring));
  this->break_max_len = 1.0e20;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008B940
// Name: public: IVP_Template_Suspension::IVP_Template_Suspension(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Suspension *__thiscall IVP_Template_Suspension::IVP_Template_Suspension(IVP_Template_Suspension *this)
{
  IVP_Template_Two_Point::IVP_Template_Two_Point(this);
  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x3Cu);
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Template_Suspension));
  this->break_max_len = 1000000000.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008B970
// Name: public: void IVP_Actuator_Spring::set_len(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Spring::set_len(IVP_Actuator_Spring *this, float len)
{
  if ( this->spring_len != len )
  {
    this->spring_len = len;
    IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B9A0
// Name: public: void IVP_Actuator_Spring::set_constant(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Spring::set_constant(IVP_Actuator_Spring *this, float c)
{
  this->spring_constant = this->spring_values_factor * c;
  IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008B9D0
// Name: public: void IVP_Actuator_Spring::set_damp(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Spring::set_damp(IVP_Actuator_Spring *this, float c)
{
  this->spring_damp = this->spring_values_factor * c;
  IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008BA00
// Name: protected: virtual void IVP_Actuator_Spring_Active::active_float_changed(class IVP_U_Active_Float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Spring_Active::active_float_changed(
        IVP_Actuator_Spring_Active *this,
        IVP_U_Active_Float *af)
{
  float double_value; // xmm0_4
  float v3; // xmm1_4
  float *v4; // ecx
  float v5; // xmm0_4
  float *v6; // ecx
  float v7; // xmm0_4
  float *v8; // ecx
  float v9; // xmm0_4
  float *v10; // ecx

  if ( af == *(IVP_U_Active_Float **)&this->actuator_controlled_cores.memsize )
  {
    double_value = af->double_value;
    v3 = *((float *)this - 11);
    v4 = (float *)((char *)this - 208);
    if ( v3 != double_value )
    {
      v4[41] = double_value;
      IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this: (IVP_Actuator_Two_Point *)v4);
    }
  }
  else if ( af == (IVP_U_Active_Float *)this->actuator_controlled_cores.elems )
  {
    v5 = *((float *)this - 10) * af->double_value;
    v6 = (float *)((char *)this - 208);
    v6[43] = v5;
    IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this: (IVP_Actuator_Two_Point *)v6);
  }
  else if ( af == *((IVP_U_Active_Float **)&this->IVP_Actuator + 3) )
  {
    v7 = *((float *)this - 10) * af->double_value;
    v8 = (float *)((char *)this - 208);
    v8[44] = v7;
    IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this: (IVP_Actuator_Two_Point *)v8);
  }
  else if ( af == (IVP_U_Active_Float *)this->anchors[0].anchor_next_in_object )
  {
    v9 = *((float *)this - 10) * af->double_value;
    v10 = (float *)((char *)this - 208);
    v10[45] = v9;
    IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this: (IVP_Actuator_Two_Point *)v10);
  }
  else
  {
    _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_controller\\ivp_actuator_spring.cxx", 126);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BAD0
// Name: public: void IVP_Actuator_Suspension::set_spring_damp_compression(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Suspension::set_spring_damp_compression(IVP_Actuator_Suspension *this, float comp)
{
  if ( this->spring_dampening_compression != comp )
  {
    this->spring_dampening_compression = this->spring_values_factor * comp;
    IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BB10
// Name: public: void IVP_Actuator_Suspension::set_max_body_force(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Suspension::set_max_body_force(IVP_Actuator_Suspension *this, float max_force)
{
  if ( this->max_body_force != max_force )
  {
    this->max_body_force = max_force;
    IVP_Actuator_Two_Point::ensure_actuator_in_simulation(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BB40
// Name: protected: void IVP_Actuator_Spring::fire_event_spring_broken(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Spring::fire_event_spring_broken(IVP_Actuator_Spring *this)
{
  int v2; // esi
  void (__thiscall ***v3)(void *, IVP_Actuator_Spring *); // ecx

  v2 = this->listeners_spring.n_elems - 1;
  if ( this->listeners_spring.n_elems != 0 )
  {
    do
    {
      v3 = (void (__thiscall ***)(void *, IVP_Actuator_Spring *))this->listeners_spring.elems[v2];
      (**v3)(a1: v3, a2: this);
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BB70
// Name: public: virtual void IVP_Actuator_Spring::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Actuator_Spring::do_simulation_controller(
        IVP_Actuator_Spring *this@<ecx>,
        int a2@<ebp>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Core *physical_core; // edi
  double v6; // st7
  float v7; // xmm0_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  bool v12; // zf
  float v13; // xmm2_4
  float v14; // xmm1_4
  float hesse_val; // xmm3_4
  float v16[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Float_Point relative_world_speed; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Point pos0_ws; // [esp+10h] [ebp-50h] BYREF
  IVP_U_Point pos1_ws; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Float_Point dir_ws; // [esp+30h] [ebp-30h] BYREF
  IVP_U_Float_Point force_vector_ws; // [esp+40h] [ebp-20h]
  IVP_Core *v22; // [esp+50h] [ebp-10h]
  int v23; // [esp+54h] [ebp-Ch] BYREF
  float force; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  v23 = a2;
  force = retaddr;
  physical_core = this->anchors[1].l_anchor_object->physical_core;
  v22 = this->anchors[0].l_anchor_object->physical_core;
  IVP_U_Matrix::vmult4(
    this: &v22->m_world_f_core_last_psi,
    p_in: &this->anchors[0].core_pos,
    p_out: (IVP_U_Float_Point *)&relative_world_speed.k[1]);
  IVP_U_Matrix::vmult4(
    this: &physical_core->m_world_f_core_last_psi,
    p_in: &this->anchors[1].core_pos,
    p_out: (IVP_U_Point *)&pos0_ws.k[1]);
  pos1_ws.k[1] = relative_world_speed.k[1] - pos0_ws.k[1];
  pos1_ws.k[2] = relative_world_speed.k[2] - pos0_ws.k[2];
  pos1_ws.hesse_val = relative_world_speed.hesse_val - pos0_ws.hesse_val;
  v6 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Point *)&pos1_ws.k[1]);
  force_vector_ws.hesse_val = v6;
  if ( v6 >= 1.0e-10 )
  {
    if ( force_vector_ws.hesse_val > this->break_max_len && this->max_len_exceed_type == IVP_SFE_BREAK )
    {
      IVP_Actuator_Spring::fire_event_spring_broken(this);
      ((void (__thiscall *)(IVP_Actuator_Spring *, int))this->dtr_IVP_Controller)(a1: this, a2: 1);
    }
    else if ( this->spring_force_only_on_stretch == IVP_FALSE || force_vector_ws.hesse_val > this->spring_len )
    {
      force_vector_ws.hesse_val = (float)(force_vector_ws.hesse_val - this->spring_len) * this->spring_constant;
      IVP_Core::get_diff_surface_speed_of_two_cores(
        this_core: physical_core,
        other_core: v22,
        obj_point_this: &this->anchors[1].core_pos,
        obj_point_other: &this->anchors[0].core_pos,
        delta_velocity_ws: (IVP_U_Float_Point *)v16);
      force_vector_ws.k[2] = es->delta_time;
      v7 = (float)(force_vector_ws.hesse_val
                 - (float)((float)((float)((float)(v16[1] * pos1_ws.k[2]) + (float)(pos1_ws.k[1] * v16[0]))
                                 + (float)(v16[2] * pos1_ws.hesse_val))
                         * this->spring_damp))
         * force_vector_ws.k[2];
      v8 = pos1_ws.k[1] * v7;
      v9 = pos1_ws.k[2] * v7;
      v10 = pos1_ws.hesse_val * v7;
      LODWORD(v11) = COERCE_UNSIGNED_INT(this->rel_pos_damp * force_vector_ws.k[2]) ^ _mask__NegFloat_;
      v12 = (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 0x10) == 0;
      v13 = (float)(v16[0] * v11) + v8;
      v14 = (float)(v16[1] * v11) + v9;
      hesse_val = (float)(v16[2] * v11) + v10;
      dir_ws.k[1] = v13;
      dir_ws.k[2] = v14;
      dir_ws.hesse_val = hesse_val;
      if ( v12 && *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) < 8u )
      {
        IVP_Core::async_push_core_ws(
          this: physical_core,
          a2: COERCE_FLOAT(&v23),
          world_point: (IVP_U_Point *)&pos0_ws.k[1],
          impulse_in_world: (IVP_U_Float_Point *)&dir_ws.k[1]);
        hesse_val = dir_ws.hesse_val;
        v14 = dir_ws.k[2];
        v13 = dir_ws.k[1];
      }
      if ( (*(_BYTE *)&v22->IVP_Core_Fast_Static & 0x10) == 0 && *((_BYTE *)&v22->IVP_Core_Fast_Static + 1) < 8u )
      {
        dir_ws.k[1] = v13 * -1.0;
        dir_ws.k[2] = v14 * -1.0;
        dir_ws.hesse_val = hesse_val * -1.0;
        IVP_Core::async_push_core_ws(
          this: v22,
          a2: COERCE_FLOAT(&v23),
          world_point: (const IVP_U_Point *)&relative_world_speed.k[1],
          impulse_in_world: (IVP_U_Float_Point *)&dir_ws.k[1]);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BDA0
// Name: protected: IVP_Actuator_Spring::IVP_Actuator_Spring(class IVP_Environment __near *,class IVP_Template_Spring __near *,enum IVP_ACTUATOR_TYPE)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Spring *__thiscall IVP_Actuator_Spring::IVP_Actuator_Spring(
        IVP_Actuator_Spring *this,
        IVP_Environment *env,
        IVP_Template_Spring *spring_templ,
        IVP_ACTUATOR_TYPE act_type)
{
  IVP_Core *physical_core; // ecx
  IVP_Core *v6; // ebx
  long double v7; // st7
  float spring_values_factor; // xmm0_4
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  float min_mass_0; // [esp+1Ch] [ebp+10h]

  IVP_Actuator_Two_Point::IVP_Actuator_Two_Point(this, env, two_point_templ: spring_templ, __formal: act_type);
  this->__vftable = (IVP_Actuator_Spring_vtbl *)&IVP_Actuator_Spring::`vftable';
  *(_DWORD *)&this->listeners_spring.memsize = 0;
  this->listeners_spring.elems = nullptr;
  this->spring_len = spring_templ->spring_len;
  this->break_max_len = spring_templ->break_max_len;
  this->max_len_exceed_type = spring_templ->max_len_exceed_type;
  this->l_environment = env;
  physical_core = this->anchors[0].l_anchor_object->physical_core;
  v6 = this->anchors[1].l_anchor_object->physical_core;
  this->spring_values_factor = 1.0;
  if ( spring_templ->spring_values_are_relative != IVP_FALSE )
  {
    min_mass_0 = IVP_Core::calc_virt_mass(
                   this: physical_core,
                   a2: (int)&savedregs,
                   core_point: &this->anchors[0].core_pos,
                   direction: nullptr);
    v7 = IVP_Core::calc_virt_mass(
           this: v6,
           a2: (int)&savedregs,
           core_point: &this->anchors[1].core_pos,
           direction: nullptr);
    this->spring_values_factor = v7 * min_mass_0 / (v7 + min_mass_0);
  }
  spring_values_factor = this->spring_values_factor;
  this->spring_constant = spring_templ->spring_constant * spring_values_factor;
  this->spring_damp = spring_templ->spring_damp * spring_values_factor;
  this->rel_pos_damp = spring_templ->rel_pos_damp * spring_values_factor;
  this->spring_force_only_on_stretch = spring_templ->spring_force_only_on_stretch;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008BEA0
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY IVP_Actuator::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Actuator::get_controller_priority(IVP_Actuator *this)
{
  return 1500;
}

//------------------------------------------------------------------------------
// Address: 0x1008BEB0
// Name: public: virtual char const __near * IVP_Actuator_Spring::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Actuator_Spring::get_controller_name(IVP_Actuator_Spring *this)
{
  return "sys:spring";
}

//------------------------------------------------------------------------------
// Address: 0x1008BEC0
// Name: protected: IVP_Actuator_Spring_Active::IVP_Actuator_Spring_Active(class IVP_Environment __near *,class IVP_Template_Spring __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Spring_Active *__thiscall IVP_Actuator_Spring_Active::IVP_Actuator_Spring_Active(
        IVP_Actuator_Spring_Active *this,
        IVP_Environment *env,
        IVP_Template_Spring *spring_templ)
{
  IVP_U_Active_Float *active_float_spring_len; // ecx
  IVP_U_Active_Float *active_float_spring_constant; // ecx
  IVP_U_Active_Float *active_float_spring_damp; // ecx
  IVP_U_Active_Float *active_float_spring_rel_pos_damp; // ecx

  IVP_Actuator_Spring::IVP_Actuator_Spring(this, env, spring_templ, act_type: IVP_ACTUATOR_TYPE_SPRING);
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
  this->IVP_Actuator_Spring::IVP_Actuator_Two_Point::IVP_Actuator::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Actuator_Spring_Active_vtbl *)&IVP_Actuator_Spring_Active::`vftable'{for `IVP_Actuator_Spring'};
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_Actuator_Spring_Active::`vftable'{for `IVP_U_Active_Float_Listener'};
  this->active_float_spring_len = spring_templ->active_float_spring_len;
  this->active_float_spring_constant = spring_templ->active_float_spring_constant;
  this->active_float_spring_damp = spring_templ->active_float_spring_damp;
  this->active_float_spring_rel_pos_damp = spring_templ->active_float_spring_rel_pos_damp;
  active_float_spring_len = this->active_float_spring_len;
  if ( active_float_spring_len != nullptr )
  {
    IVP_U_Active_Float::add_dependency(
      this: active_float_spring_len,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
    this->spring_len = this->active_float_spring_len->double_value;
  }
  active_float_spring_constant = this->active_float_spring_constant;
  if ( active_float_spring_constant != nullptr )
  {
    IVP_U_Active_Float::add_dependency(
      this: active_float_spring_constant,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
    this->spring_constant = this->active_float_spring_constant->double_value;
  }
  active_float_spring_damp = this->active_float_spring_damp;
  if ( active_float_spring_damp != nullptr )
  {
    IVP_U_Active_Float::add_dependency(
      this: active_float_spring_damp,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
    this->spring_damp = this->active_float_spring_damp->double_value;
  }
  active_float_spring_rel_pos_damp = this->active_float_spring_rel_pos_damp;
  if ( active_float_spring_rel_pos_damp != nullptr )
  {
    IVP_U_Active_Float::add_dependency(
      this: active_float_spring_rel_pos_damp,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
    this->rel_pos_damp = this->active_float_spring_rel_pos_damp->double_value;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008BFB0
// Name: public: virtual IVP_Actuator_Spring_Active::~IVP_Actuator_Spring_Active(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Spring_Active::~IVP_Actuator_Spring_Active(IVP_Actuator_Spring_Active *this)
{
  IVP_U_Active_Float *active_float_spring_len; // ecx
  IVP_U_Active_Float *active_float_spring_constant; // ecx
  IVP_U_Active_Float *active_float_spring_damp; // ecx
  IVP_U_Active_Float *active_float_spring_rel_pos_damp; // ecx
  IVP_Actuator_Spring_Active *elems; // eax

  active_float_spring_len = this->active_float_spring_len;
  this->IVP_Actuator_Spring::IVP_Actuator_Two_Point::IVP_Actuator::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Actuator_Spring_Active_vtbl *)&IVP_Actuator_Spring_Active::`vftable'{for `IVP_Actuator_Spring'};
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_Actuator_Spring_Active::`vftable'{for `IVP_U_Active_Float_Listener'};
  if ( active_float_spring_len != nullptr )
    IVP_U_Active_Float::remove_dependency(
      this: active_float_spring_len,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
  active_float_spring_constant = this->active_float_spring_constant;
  if ( active_float_spring_constant != nullptr )
    IVP_U_Active_Float::remove_dependency(
      this: active_float_spring_constant,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
  active_float_spring_damp = this->active_float_spring_damp;
  if ( active_float_spring_damp != nullptr )
    IVP_U_Active_Float::remove_dependency(
      this: active_float_spring_damp,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
  active_float_spring_rel_pos_damp = this->active_float_spring_rel_pos_damp;
  if ( active_float_spring_rel_pos_damp != nullptr )
    IVP_U_Active_Float::remove_dependency(
      this: active_float_spring_rel_pos_damp,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
  this->IVP_Actuator_Spring::IVP_Actuator_Two_Point::IVP_Actuator::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Actuator_Spring_Active_vtbl *)&IVP_Actuator_Spring::`vftable';
  elems = (IVP_Actuator_Spring_Active *)this->listeners_spring.elems;
  if ( elems != (IVP_Actuator_Spring_Active *)(&this->listeners_spring + 1) )
  {
    if ( elems != nullptr )
      free(data: this->listeners_spring.elems);
    this->listeners_spring.elems = nullptr;
    this->listeners_spring.memsize = 0;
  }
  this->listeners_spring.n_elems = 0;
  IVP_Actuator_Two_Point::~IVP_Actuator_Two_Point(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008C060
// Name: public: IVP_Actuator_Suspension::IVP_Actuator_Suspension(class IVP_Environment __near *,class IVP_Template_Suspension __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Suspension *__thiscall IVP_Actuator_Suspension::IVP_Actuator_Suspension(
        IVP_Actuator_Suspension *this,
        IVP_Environment *env,
        IVP_Template_Suspension *templ)
{
  float spring_values_factor; // xmm0_4

  IVP_Actuator_Spring::IVP_Actuator_Spring(this, env, spring_templ: templ, act_type: IVP_ACTUATOR_TYPE_SUSPENSION);
  spring_values_factor = this->spring_values_factor;
  this->__vftable = (IVP_Actuator_Suspension_vtbl *)&IVP_Actuator_Suspension::`vftable';
  this->spring_dampening_compression = spring_values_factor * templ->spring_dampening_compression;
  this->max_body_force = templ->max_body_force;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008C0B0
// Name: public: virtual char const __near * IVP_Actuator_Suspension::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Actuator_Suspension::get_controller_name(IVP_Actuator_Suspension *this)
{
  return "sys:suspension";
}

//------------------------------------------------------------------------------
// Address: 0x1008C0C0
// Name: public: virtual void IVP_Actuator_Suspension::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Actuator_Suspension::do_simulation_controller(
        IVP_Actuator_Suspension *this@<ecx>,
        int a2@<ebp>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Core *physical_core; // edi
  double v6; // st7
  float v7; // xmm0_4
  float spring_dampening_compression; // xmm1_4
  float v9; // xmm3_4
  float max_body_force; // xmm1_4
  int v11; // esi
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Float_Point relative_world_speed; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Point pos0_ws; // [esp+10h] [ebp-50h] BYREF
  IVP_U_Point pos1_ws; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Float_Point impulse_vector_ws; // [esp+30h] [ebp-30h] BYREF
  IVP_U_Float_Point dir_ws; // [esp+40h] [ebp-20h]
  float v20; // [esp+50h] [ebp-10h]
  int v21; // [esp+54h] [ebp-Ch] BYREF
  IVP_Core *pc0; // [esp+58h] [ebp-8h]
  IVP_Core *retaddr; // [esp+60h] [ebp+0h]

  v21 = a2;
  pc0 = retaddr;
  physical_core = this->anchors[1].l_anchor_object->physical_core;
  LODWORD(dir_ws.hesse_val) = this->anchors[0].l_anchor_object->physical_core;
  IVP_U_Matrix::vmult4(
    this: (IVP_U_Matrix *)(LODWORD(dir_ws.hesse_val) + 96),
    p_in: &this->anchors[0].core_pos,
    p_out: (IVP_U_Float_Point *)&relative_world_speed.k[1]);
  IVP_U_Matrix::vmult4(
    this: &physical_core->m_world_f_core_last_psi,
    p_in: &this->anchors[1].core_pos,
    p_out: (IVP_U_Point *)&pos0_ws.k[1]);
  impulse_vector_ws.k[1] = relative_world_speed.k[1] - pos0_ws.k[1];
  impulse_vector_ws.k[2] = relative_world_speed.k[2] - pos0_ws.k[2];
  impulse_vector_ws.hesse_val = relative_world_speed.hesse_val - pos0_ws.hesse_val;
  v6 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&impulse_vector_ws.k[1]);
  v20 = v6;
  if ( v6 >= 1.0e-10 )
  {
    v20 = (float)(v20 - this->spring_len) * this->spring_constant;
    IVP_Core::get_diff_surface_speed_of_two_cores(
      this_core: physical_core,
      other_core: (const IVP_Core *)LODWORD(dir_ws.hesse_val),
      obj_point_this: &this->anchors[1].core_pos,
      obj_point_other: &this->anchors[0].core_pos,
      delta_velocity_ws: (IVP_U_Float_Point *)v14);
    v7 = (float)((float)(v14[1] * impulse_vector_ws.k[2]) + (float)(impulse_vector_ws.k[1] * v14[0]))
       + (float)(v14[2] * impulse_vector_ws.hesse_val);
    if ( v7 >= 0.0 )
      spring_dampening_compression = this->spring_dampening_compression;
    else
      spring_dampening_compression = this->spring_damp;
    v9 = v20 - (float)(spring_dampening_compression * v7);
    LODWORD(max_body_force) = LODWORD(v9) ^ _mask__NegFloat_;
    if ( COERCE_FLOAT(LODWORD(this->max_body_force) ^ _mask__NegFloat_) <= COERCE_FLOAT(LODWORD(v9) ^ _mask__NegFloat_) )
    {
      if ( max_body_force > this->max_body_force )
        max_body_force = this->max_body_force;
    }
    else
    {
      LODWORD(max_body_force) = LODWORD(this->max_body_force) ^ _mask__NegFloat_;
    }
    v11 = *((_DWORD *)*physical_core->objects.elems + 10);
    v12 = es->delta_time * v9;
    v20 = es->delta_time * max_body_force;
    pos1_ws.k[1] = impulse_vector_ws.k[1] * v12;
    pos1_ws.k[2] = impulse_vector_ws.k[2] * v12;
    pos1_ws.hesse_val = impulse_vector_ws.hesse_val * v12;
    IVP_Core::async_push_core_ws(
      this: physical_core,
      a2: COERCE_FLOAT(&v21),
      world_point: (IVP_U_Point *)&pos0_ws.k[1],
      impulse_in_world: (IVP_U_Point *)&pos1_ws.k[1]);
    v13 = v20;
    if ( v11 == 0 )
      v13 = v20 * 0.1;
    pos1_ws.k[1] = impulse_vector_ws.k[1] * v13;
    pos1_ws.k[2] = impulse_vector_ws.k[2] * v13;
    pos1_ws.hesse_val = impulse_vector_ws.hesse_val * v13;
    IVP_Core::async_push_core_ws(
      this: (IVP_Core *)LODWORD(dir_ws.hesse_val),
      a2: COERCE_FLOAT(&v21),
      world_point: (const IVP_U_Point *)&relative_world_speed.k[1],
      impulse_in_world: (IVP_U_Point *)&pos1_ws.k[1]);
  }
}
