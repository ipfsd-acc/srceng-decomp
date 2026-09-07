// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_car_system.cxx
// Functions: 31
// ============================================================

#include "ivp\ivp_controller\ivp_car_system.h"

//------------------------------------------------------------------------------
// Address: 0x10077670
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_spring_dampening(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_spring_dampening(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL wheel_nr,
        float damp_factor)
{
  IVP_Actuator_Spring::set_damp(this: this->car_spring[wheel_nr], c: damp_factor);
}

//------------------------------------------------------------------------------
// Address: 0x10077690
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_max_body_force(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_max_body_force(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL wheel_nr,
        float mforce)
{
  IVP_Actuator_Suspension::set_max_body_force(this: this->car_spring[wheel_nr], max_force: mforce);
}

//------------------------------------------------------------------------------
// Address: 0x100776B0
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_spring_dampening_compression(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_spring_dampening_compression(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL wheel_nr,
        float damp_factor)
{
  IVP_Actuator_Suspension::set_spring_damp_compression(this: this->car_spring[wheel_nr], comp: damp_factor);
}

//------------------------------------------------------------------------------
// Address: 0x100776D0
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_spring_pre_tension(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_spring_pre_tension(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL wheel_nr,
        float pre_tension_len)
{
  IVP_Actuator_Spring::set_len(this: this->car_spring[wheel_nr], len: 500.0 - pre_tension_len);
}

//------------------------------------------------------------------------------
// Address: 0x10077700
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_spring_length(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_spring_length(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL wheel_nr,
        float spring_length)
{
  IVP_Actuator_Spring::set_len(this: this->car_spring[wheel_nr], len: spring_length);
}

//------------------------------------------------------------------------------
// Address: 0x10077720
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_stabilizer_constant(enum IVP_POS_AXIS,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_stabilizer_constant(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_AXIS axis_nr,
        float stabi_constant)
{
  IVP_Actuator_Stabilizer::set_stabi_constant(this: this->car_stabilizer[axis_nr], val: stabi_constant);
}

//------------------------------------------------------------------------------
// Address: 0x10077750
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_fast_turn_factor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_fast_turn_factor(
        IVP_Car_System_Real_Wheels *this,
        float fast_turn_factor_)
{
  this->fast_turn_factor = fast_turn_factor_;
}

//------------------------------------------------------------------------------
// Address: 0x10077770
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_wheel_torque(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_wheel_torque(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL wheel_nr,
        float torque)
{
  IVP_Actuator_Torque::set_torque(this: this->car_act_torque[wheel_nr], val: torque);
}

//------------------------------------------------------------------------------
// Address: 0x10077790
// Name: public: virtual float IVP_Car_System_Real_Wheels::get_wheel_torque(enum IVP_POS_WHEEL)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Car_System_Real_Wheels::get_wheel_torque(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL wheel_nr)
{
  return this->car_act_torque[wheel_nr]->torque;
}

//------------------------------------------------------------------------------
// Address: 0x100777B0
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_body_downforce(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_body_downforce(IVP_Car_System_Real_Wheels *this, float force)
{
  IVP_Actuator_Force::set_force(this: this->car_act_down_force, nforce: force);
}

//------------------------------------------------------------------------------
// Address: 0x100777D0
// Name: public: virtual void IVP_Car_System_Real_Wheels::update_body_countertorque(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::update_body_countertorque(IVP_Car_System_Real_Wheels *this)
{
  float v1; // xmm0_4
  int n_wheels; // esi
  int v3; // edi
  unsigned int v4; // edx
  IVP_Actuator_Torque **v5; // eax
  IVP_Actuator_Torque **v6; // eax
  int v7; // esi

  v1 = 0.0;
  n_wheels = this->n_wheels;
  v3 = 0;
  if ( n_wheels >= 4 )
  {
    v4 = ((unsigned int)(n_wheels - 4) >> 2) + 1;
    v5 = &this->car_act_torque[1];
    v3 = 4 * v4;
    do
    {
      v1 = (float)((float)((float)(v1 - (*(v5 - 1))->torque) - (*v5)->torque) - v5[1]->torque) - v5[2]->torque;
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
  if ( v3 < n_wheels )
  {
    v6 = &this->car_act_torque[v3];
    v7 = n_wheels - v3;
    do
    {
      v1 = v1 - (*v6++)->torque;
      --v7;
    }
    while ( v7 != 0 );
  }
  IVP_Actuator_Torque::set_torque(this: this->car_act_torque_body, val: this->body_counter_torque_factor * v1);
}

//------------------------------------------------------------------------------
// Address: 0x10077860
// Name: public: virtual void IVP_Car_System_Real_Wheels::change_spring_constant(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::change_spring_constant(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL wheel_nr,
        float constant)
{
  IVP_Actuator_Spring::set_constant(this: this->car_spring[wheel_nr], c: constant);
}

//------------------------------------------------------------------------------
// Address: 0x10077880
// Name: public: virtual float IVP_Car_System_Real_Wheels::get_body_speed(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Car_System_Real_Wheels::get_body_speed(
        IVP_Car_System_Real_Wheels *this,
        IVP_COORDINATE_INDEX idx_z)
{
  IVP_Core *physical_core; // eax

  physical_core = this->car_body->physical_core;
  return physical_core->delta_world_f_core_psis.k[0] * physical_core->m_world_f_core_last_psi.rows[0].k[idx_z]
       + physical_core->delta_world_f_core_psis.k[1] * physical_core->m_world_f_core_last_psi.rows[1].k[idx_z]
       + physical_core->m_world_f_core_last_psi.rows[2].k[idx_z] * physical_core->delta_world_f_core_psis.k[2];
}

//------------------------------------------------------------------------------
// Address: 0x100778C0
// Name: public: virtual float IVP_Car_System_Real_Wheels::get_wheel_angular_velocity(enum IVP_POS_WHEEL)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Car_System_Real_Wheels::get_wheel_angular_velocity(
        IVP_Car_System_Real_Wheels *this,
        IVP_POS_WHEEL i)
{
  return this->car_act_torque[i]->rot_speed_out;
}

//------------------------------------------------------------------------------
// Address: 0x100778E0
// Name: public: virtual void IVP_Car_System_Real_Wheels::activate_booster(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::activate_booster(
        IVP_Car_System_Real_Wheels *this,
        float thrust,
        float duration,
        float delay)
{
  float gravity; // [esp+8h] [ebp-4h]

  if ( (this->booster_actuator[0] == nullptr || thrust == 0.0) && this->booster_seconds_until_ready <= 0.0 )
  {
    gravity = IVP_U_Float_Point::fast_real_length(this: &this->environment->gravity);
    if ( thrust != 0.0 )
      ((void (__thiscall *)(IVP_Car_System_Real_Wheels *, _DWORD))this->set_booster_acceleration)(
        a1: this,
        a2: gravity * thrust);
    this->booster_seconds_to_go = duration;
    this->booster_seconds_until_ready = duration + delay;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077970
// Name: public: virtual void IVP_Car_System_Real_Wheels::set_booster_acceleration(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Car_System_Real_Wheels::set_booster_acceleration(
        IVP_Car_System_Real_Wheels *this@<ecx>,
        int a2@<ebp>,
        float acceleration)
{
  IVP_Actuator_Force *v4; // ecx
  IVP_Real_Object *car_body; // eax
  IVP_Real_Object *static_object; // ecx
  IVP_Constraint_Solver_Car *car_constraint_solver; // edi
  int z_idx; // edx
  IVP_Core *physical_core; // eax
  float v10; // xmm0_4
  IVP_Environment *environment; // ecx
  IVP_Actuator_Force *force; // eax
  IVP_Environment *v13; // ecx
  IVP_Actuator_Force *v14; // ecx
  IVP_Real_Object *v15; // [esp-4h] [ebp-134h]
  IVP_Real_Object *v16; // [esp-4h] [ebp-134h]
  _BYTE v17[12]; // [esp+14h] [ebp-11Ch] BYREF
  IVP_Template_Anchor anchorTempUp[2]; // [esp+20h] [ebp-110h] BYREF
  IVP_Template_Anchor anchorTempForward[2]; // [esp+60h] [ebp-D0h] BYREF
  IVP_U_Float_Point centerPoint; // [esp+A0h] [ebp-90h] BYREF
  _BYTE *v21; // [esp+B0h] [ebp-80h]
  float *v22; // [esp+B4h] [ebp-7Ch]
  IVP_Template_Force forceTempUp; // [esp+B8h] [ebp-78h] BYREF
  IVP_Template_Force forceTempForward; // [esp+D4h] [ebp-5Ch] BYREF
  IVP_U_Float_Point frontPoint; // [esp+F0h] [ebp-40h] BYREF
  IVP_U_Float_Point backPoint; // [esp+100h] [ebp-30h] BYREF
  IVP_U_Float_Point downPoint; // [esp+110h] [ebp-20h]
  IVP_Real_Object *v28; // [esp+120h] [ebp-10h]
  int v29; // [esp+124h] [ebp-Ch]
  IVP_Real_Object *pStaticObject; // [esp+128h] [ebp-8h]
  IVP_Real_Object *retaddr; // [esp+130h] [ebp+0h]

  v29 = a2;
  pStaticObject = retaddr;
  v4 = this->booster_actuator[0];
  if ( acceleration == 0.0 )
  {
    if ( v4 != nullptr )
      ((void (__thiscall *)(IVP_Actuator_Force *, int))v4->dtr_IVP_Controller)(a1: v4, a2: 1);
    v14 = this->booster_actuator[1];
    this->booster_actuator[0] = nullptr;
    if ( v14 != nullptr )
      ((void (__thiscall *)(IVP_Actuator_Force *, int))v14->dtr_IVP_Controller)(a1: v14, a2: 1);
    this->booster_actuator[1] = nullptr;
  }
  else
  {
    car_body = this->car_body;
    v28 = car_body;
    if ( v4 != nullptr )
    {
      IVP_Actuator_Force::set_force(this: v4, nforce: car_body->physical_core->rot_inertia.hesse_val * acceleration);
    }
    else
    {
      IVP_Template_Force::IVP_Template_Force(this: (IVP_Template_Force *)&forceTempUp.active_float_force);
      IVP_Template_Force::IVP_Template_Force(this: (IVP_Template_Force *)&centerPoint.hesse_val);
      static_object = this->environment->static_object;
      car_constraint_solver = this->car_constraint_solver;
      memset(&forceTempForward.active_float_force, 0, 12);
      memset(&frontPoint.k[1], 0, 12);
      z_idx = car_constraint_solver->z_idx;
      LODWORD(downPoint.hesse_val) = static_object;
      *((_DWORD *)&forceTempForward.active_float_force + z_idx) = 1065353216;
      v15 = v28;
      frontPoint.k[car_constraint_solver->z_idx + 1] = -1.0;
      IVP_Template_Anchor::set_anchor_position_cs(
        this: (IVP_Template_Anchor *)&anchorTempUp[1].coords_world.k[1],
        obj: v15,
        coords_cs: (const IVP_U_Float_Point *)&forceTempForward.active_float_force);
      IVP_Template_Anchor::set_anchor_position_cs(
        this: (IVP_Template_Anchor *)&anchorTempForward[0].coords_world.k[1],
        obj: v28,
        coords_cs: (IVP_U_Float_Point *)&frontPoint.k[1]);
      memset(&backPoint.k[1], 0, 12);
      anchorTempForward[1].coords_world.hesse_val = 0.0;
      anchorTempForward[1].coords_world.k[2] = 0.0;
      anchorTempForward[1].coords_world.k[1] = 0.0;
      v16 = v28;
      backPoint.k[car_constraint_solver->y_idx + 1] = -100000000.0;
      IVP_Template_Anchor::set_anchor_position_cs(
        this: (IVP_Template_Anchor *)v17,
        obj: v16,
        coords_cs: (const IVP_U_Float_Point *)&anchorTempForward[1].coords_world.k[1]);
      IVP_Template_Anchor::set_anchor_position_os(
        this: (IVP_Template_Anchor *)&anchorTempUp[0].coords_world.k[1],
        obj: (IVP_Real_Object *)LODWORD(downPoint.hesse_val),
        coords_os: (IVP_U_Float_Point *)&backPoint.k[1]);
      physical_core = v28->physical_core;
      forceTempUp.push_first_object = (IVP_BOOL)&anchorTempUp[1].coords_world.k[1];
      forceTempUp.push_second_object = (IVP_BOOL)&anchorTempForward[0].coords_world.k[1];
      forceTempForward.anchors[0] = nullptr;
      forceTempForward.force = 0.0;
      forceTempForward.anchors[1] = (IVP_Template_Anchor *)1;
      v10 = acceleration * physical_core->rot_inertia.hesse_val;
      v21 = v17;
      *(float *)&forceTempForward.client_data = v10;
      forceTempUp.anchors[0] = nullptr;
      forceTempUp.force = 0.0;
      environment = this->environment;
      v22 = &anchorTempUp[0].coords_world.k[1];
      forceTempUp.anchors[1] = (IVP_Template_Anchor *)1;
      *(float *)&forceTempUp.client_data = (float)(physical_core->rot_inertia.hesse_val * -1.0)
                                         * environment->gravity.k[car_constraint_solver->y_idx];
      force = IVP_Environment::create_force(
                this: environment,
                templ: (IVP_Template_Force *)&forceTempUp.active_float_force);
      v13 = this->environment;
      this->booster_actuator[0] = force;
      this->booster_actuator[1] = IVP_Environment::create_force(
                                    this: v13,
                                    templ: (IVP_Template_Force *)&centerPoint.hesse_val);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077BB0
// Name: public: virtual void IVP_Car_System_Real_Wheels::update_booster(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::update_booster(IVP_Car_System_Real_Wheels *this, float delta_time)
{
  float booster_seconds_until_ready; // xmm0_4
  float booster_seconds_to_go; // xmm0_4
  float v4; // xmm0_4

  booster_seconds_until_ready = this->booster_seconds_until_ready;
  if ( booster_seconds_until_ready > 0.0 )
    this->booster_seconds_until_ready = booster_seconds_until_ready - delta_time;
  booster_seconds_to_go = this->booster_seconds_to_go;
  if ( booster_seconds_to_go > 0.0 )
  {
    v4 = booster_seconds_to_go - delta_time;
    this->booster_seconds_to_go = v4;
    if ( v4 <= 0.0 )
      ((void (__stdcall *)(_DWORD))this->set_booster_acceleration)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077C10
// Name: public: virtual void IVP_Car_System_Real_Wheels::set_powerslide(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::set_powerslide(
        IVP_Car_System_Real_Wheels *this,
        float frontAccel,
        float rearAccel)
{
  IVP_Actuator_Force::set_force(
    this: this->car_act_powerslide_back,
    nforce: this->car_body->physical_core->rot_inertia.hesse_val * frontAccel);
  IVP_Actuator_Force::set_force(
    this: this->car_act_powerslide_front,
    nforce: this->car_body->physical_core->rot_inertia.hesse_val * rearAccel);
}

//------------------------------------------------------------------------------
// Address: 0x10077C70
// Name: public: virtual float IVP_Car_System_Real_Wheels::get_booster_delay(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Car_System_Real_Wheels::get_booster_delay(IVP_Car_System_Real_Wheels *this)
{
  return this->booster_seconds_until_ready;
}

//------------------------------------------------------------------------------
// Address: 0x10077C80
// Name: protected: virtual void IVP_Car_System_Real_Wheels::environment_will_be_deleted(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::environment_will_be_deleted(
        IVP_Car_System_Real_Wheels *this,
        IVP_Environment *__formal)
{
  if ( this != nullptr )
    ((void (__thiscall *)(IVP_Car_System_Real_Wheels *, int))this->dtr_IVP_Car_System)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10077C90
// Name: public: virtual IVP_Car_System::~IVP_Car_System(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System::~IVP_Car_System(IVP_Car_System *this)
{
  this->__vftable = (IVP_Car_System_vtbl *)&IVP_Car_System::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10077CD0
// Name: public: IVP_Car_System::IVP_Car_System(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Car_System *__thiscall IVP_Car_System::IVP_Car_System(IVP_Car_System *this)
{
  this->__vftable = (IVP_Car_System_vtbl *)&IVP_Car_System::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077CE0
// Name: public: virtual void IVP_Car_System_Real_Wheels::GetCarSystemDebugData(struct IVP_CarSystemDebugData_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::GetCarSystemDebugData(
        IVP_Car_System_Real_Wheels *this,
        IVP_CarSystemDebugData_t *carSystemDebugData)
{
  IVP_U_Matrix *p_m_world_f_core_last_psi; // esi

  p_m_world_f_core_last_psi = &this->car_body->physical_core->m_world_f_core_last_psi;
  IVP_U_Matrix::vmult4(
    this: p_m_world_f_core_last_psi,
    p_in: &this->car_act_powerslide_back->anchors[0].core_pos,
    p_out: &carSystemDebugData->backActuatorLeft);
  IVP_U_Matrix::vmult4(
    this: p_m_world_f_core_last_psi,
    p_in: &this->car_act_powerslide_back->anchors[1].core_pos,
    p_out: &carSystemDebugData->backActuatorRight);
  IVP_U_Matrix::vmult4(
    this: p_m_world_f_core_last_psi,
    p_in: &this->car_act_powerslide_front->anchors[0].core_pos,
    p_out: &carSystemDebugData->frontActuatorLeft);
  IVP_U_Matrix::vmult4(
    this: p_m_world_f_core_last_psi,
    p_in: &this->car_act_powerslide_front->anchors[1].core_pos,
    p_out: &carSystemDebugData->frontActuatorRight);
}

//------------------------------------------------------------------------------
// Address: 0x10077D60
// Name: public: virtual void IVP_Car_System_Real_Wheels::do_steering_wheel(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Car_System_Real_Wheels::do_steering_wheel(
        IVP_Car_System_Real_Wheels *this@<ecx>,
        float a2@<ebp>,
        IVP_POS_WHEEL wheel_pos,
        float s_angle)
{
  IVP_Constraint_Solver_Car *car_constraint_solver; // eax
  bool v5; // cc
  double v6; // rdi
  _DWORD v7[3]; // [esp+14h] [ebp-2Ch] BYREF
  IVP_U_Point hp; // [esp+20h] [ebp-20h]
  IVP_U_Point old_translation; // [esp+30h] [ebp-10h]
  float retaddr; // [esp+40h] [ebp+0h]

  old_translation.k[1] = a2;
  old_translation.k[2] = retaddr;
  car_constraint_solver = this->car_constraint_solver;
  HIDWORD(v6) = car_constraint_solver->wheel_objects.elems[wheel_pos];
  hp.k[1] = *(float *)(HIDWORD(v6) + 64);
  LODWORD(v6) = car_constraint_solver->x_idx;
  *(_QWORD *)&hp.k[2] = *(_QWORD *)(HIDWORD(v6) + 68);
  v5 = this->wheel_reversed_sign[wheel_pos] >= 0.0;
  v7[LODWORD(v6)] = 0;
  *(float *)&v7[car_constraint_solver->y_idx] = s_angle;
  LODWORD(v6) = car_constraint_solver->z_idx;
  v7[LODWORD(v6)] = 0;
  if ( !v5 )
    *(float *)&v7[car_constraint_solver->y_idx] = *(float *)&v7[car_constraint_solver->y_idx] + 3.1415927;
  IVP_U_Matrix::init_rot_multiple(
    this: (IVP_U_Matrix *)(HIDWORD(v6) + 16),
    a2: v6,
    angles: (const IVP_U_Point *)v7,
    factor: 1.0);
  *(_QWORD *)(HIDWORD(v6) + 64) = *(_QWORD *)&hp.k[1];
  *(float *)(HIDWORD(v6) + 72) = hp.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x10077E30
// Name: public: virtual void IVP_Car_System_Real_Wheels::do_steering(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Car_System_Real_Wheels::do_steering(
        IVP_Car_System_Real_Wheels *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float s_angle,
        bool bAnalog)
{
  float steering_angle; // xmm0_4
  IVP_Constraint_Solver_Car *car_constraint_solver; // edi
  double v8; // st7
  float *v9; // eax
  IVP_Environment *environment; // eax
  int v11; // edi
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  long double v15; // [esp+14h] [ebp-18h]
  long double v16; // [esp+14h] [ebp-18h]
  int wheels_per_axis; // [esp+1Ch] [ebp-10h]
  float d_alpha; // [esp+20h] [ebp-Ch]
  float dx_front_wheels; // [esp+24h] [ebp-8h]
  float dz_axles; // [esp+28h] [ebp-4h]
  float s_anglea; // [esp+34h] [ebp+8h]

  HIDWORD(v15) = a3;
  steering_angle = this->steering_angle;
  if ( steering_angle != s_angle )
  {
    LODWORD(v15) = a2;
    car_constraint_solver = this->car_constraint_solver;
    dx_front_wheels = 1.0;
    dz_axles = 1.0;
    if ( this->n_wheels >= 4 )
    {
      dx_front_wheels = this->get_orig_front_wheel_distance(this);
      dz_axles = this->get_orig_axles_distance(this);
    }
    v8 = ((double (__thiscall *)(IVP_Car_System_Real_Wheels *, int))this->get_body_speed)(
           a1: this,
           a2: car_constraint_solver->z_idx);
    v9 = &this->car_body->physical_core->rot_speed_change.k[car_constraint_solver->y_idx];
    *v9 = *v9 - v8 * (float)(s_angle - steering_angle) / dz_axles * this->fast_turn_factor;
    environment = this->environment;
    this->steering_angle = s_angle;
    IVP_Controller_Manager::ensure_controller_in_simulation(
      this: environment->controller_manager,
      cntrl: car_constraint_solver);
    v11 = 0;
    wheels_per_axis = this->n_wheels / this->n_axis;
    if ( wheels_per_axis > 0 )
    {
      do
      {
        v12 = s_angle;
        if ( (v11 & 1) != s_angle > 0.0 )
        {
          if ( this->n_wheels < 4 )
          {
            v12 = this->steering_angle;
          }
          else
          {
            LODWORD(v13) = LODWORD(this->steering_angle) & _mask__AbsFloat_;
            d_alpha = this->steering_angle;
            if ( v13 >= 0.001 )
            {
              __libm_sse2_tan(x: v15);
              __libm_sse2_atan(x: v16);
              v14 = (float)(v13 * dz_axles) / (float)((float)(v13 * dx_front_wheels) + dz_axles);
              if ( d_alpha >= 0.0 )
                v12 = 1.0 * v14;
              else
                v12 = -1.0 * v14;
            }
            else
            {
              v12 = this->steering_angle;
            }
          }
        }
        ((void (__thiscall *)(IVP_Car_System_Real_Wheels *, int, _DWORD))this->do_steering_wheel)(
          a1: this,
          a2: v11++,
          a3: LODWORD(v12));
      }
      while ( v11 < wheels_per_axis );
    }
    if ( this->n_wheels > 4 )
    {
      s_anglea = s_angle * 0.5;
      ((void (__thiscall *)(IVP_Car_System_Real_Wheels *, int, _DWORD))this->do_steering_wheel)(
        a1: this,
        a2: 4,
        a3: LODWORD(s_anglea));
      ((void (__thiscall *)(IVP_Car_System_Real_Wheels *, int, _DWORD))this->do_steering_wheel)(
        a1: this,
        a2: 5,
        a3: LODWORD(s_anglea));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078010
// Name: public: virtual float IVP_Car_System_Real_Wheels::get_orig_front_wheel_distance(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Car_System_Real_Wheels::get_orig_front_wheel_distance(IVP_Car_System_Real_Wheels *this)
{
  return -(*((float *)*this->car_constraint_solver->wheel_objects.elems + this->car_constraint_solver->x_idx + 16)
         - *(float *)(*((_DWORD *)this->car_constraint_solver->wheel_objects.elems + 1)
                    + 4 * this->car_constraint_solver->x_idx
                    + 64));
}

//------------------------------------------------------------------------------
// Address: 0x10078030
// Name: public: virtual float IVP_Car_System_Real_Wheels::get_orig_axles_distance(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall IVP_Car_System_Real_Wheels::get_orig_axles_distance(IVP_Car_System_Real_Wheels *this)
{
  return fabs(
           *((float *)*this->car_constraint_solver->wheel_objects.elems + this->car_constraint_solver->z_idx + 16)
         - *(float *)(*((_DWORD *)this->car_constraint_solver->wheel_objects.elems + 2)
                    + 4 * this->car_constraint_solver->z_idx
                    + 64));
}

//------------------------------------------------------------------------------
// Address: 0x10078050
// Name: public: virtual void IVP_Car_System_Real_Wheels::get_skid_info(class IVP_Wheel_Skid_Info __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Car_System_Real_Wheels::get_skid_info(
        IVP_Car_System_Real_Wheels *this,
        IVP_Wheel_Skid_Info *array_of_skid_info_out)
{
  int v2; // esi
  IVP_Time *p_last_skid_time; // eax
  long double *v4; // edx

  v2 = 0;
  if ( this->n_wheels > 0 )
  {
    p_last_skid_time = &array_of_skid_info_out->last_skid_time;
    do
    {
      v4 = (long double *)this->car_constraint_solver->wheel_objects.elems[v2];
      *(IVP_Time *)&p_last_skid_time[-3].seconds = (IVP_Time)v4[10];
      *(IVP_Time *)&p_last_skid_time[-2].seconds = (IVP_Time)v4[11];
      *(float *)&p_last_skid_time[-1].seconds = *((float *)v4 + 24);
      LODWORD(p_last_skid_time->seconds) = *((_DWORD *)v4 + 26);
      HIDWORD(p_last_skid_time->seconds) = *((_DWORD *)v4 + 27);
      ++v2;
      p_last_skid_time += 4;
    }
    while ( v2 < this->n_wheels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100780A0
// Name: public: virtual void IVP_Car_System_Real_Wheels::fix_wheel(enum IVP_POS_WHEEL,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Car_System_Real_Wheels::fix_wheel(
        IVP_Car_System_Real_Wheels *this@<ecx>,
        int a2@<ebp>,
        IVP_POS_WHEEL wheel_nr,
        IVP_BOOL stop_wheel)
{
  IVP_Constraint *v5; // ecx
  bool v6; // zf
  IVP_Core *physical_core; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  IVP_Core *v11; // eax
  IVP_Environment *environment; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  IVP_Constraint *constraint; // eax
  _BYTE v16[12]; // [esp-Ch] [ebp-18Ch] BYREF
  IVP_Real_Object *v17; // [esp+170h] [ebp-10h]
  int v18; // [esp+174h] [ebp-Ch]
  void *v19; // [esp+178h] [ebp-8h]
  void *retaddr; // [esp+180h] [ebp+0h]

  v18 = a2;
  v19 = retaddr;
  if ( stop_wheel != IVP_FALSE )
  {
    v6 = this->fix_wheel_constraint[wheel_nr] == nullptr;
    v17 = this->car_wheel[wheel_nr];
    if ( v6 )
    {
      IVP_Template_Constraint::IVP_Template_Constraint(this: (IVP_Template_Constraint *)v16);
      CPhysicsMotionController::SetEventHandler(this: (IVP_Template_Constraint *)v16, objR: v17);
      IVP_Template_Constraint::set_attached_object(this: (IVP_Template_Constraint *)v16, objA: this->car_body);
      IVP_Template_Constraint::fix_rotation_axis(this: (IVP_Template_Constraint *)v16, which: IVP_INDEX_X);
      IVP_Template_Constraint::free_rotation_axis(this: (IVP_Template_Constraint *)v16, which: IVP_INDEX_Y);
      IVP_Template_Constraint::free_rotation_axis(this: (IVP_Template_Constraint *)v16, which: IVP_INDEX_Z);
      IVP_Template_Constraint::free_translation_axis(this: (IVP_Template_Constraint *)v16, which: IVP_INDEX_X);
      IVP_Template_Constraint::free_translation_axis(this: (IVP_Template_Constraint *)v16, which: IVP_INDEX_Y);
      IVP_Template_Constraint::free_translation_axis(this: (IVP_Template_Constraint *)v16, which: IVP_INDEX_Z);
      physical_core = this->car_body->physical_core;
      v8 = physical_core->rot_speed.k[1];
      v9 = physical_core->rot_speed.k[2];
      v10 = physical_core->rot_speed.k[0];
      v11 = v17->physical_core;
      environment = this->environment;
      v13 = (float)(v8 * 0.25) + v11->rot_speed.k[1];
      v14 = (float)(v9 * 0.25) + v11->rot_speed.k[2];
      v11->rot_speed.k[0] = (float)(v10 * 0.25) + v11->rot_speed.k[0];
      v11->rot_speed.k[1] = v13;
      v11->rot_speed.k[2] = v14;
      constraint = IVP_Environment::create_constraint(this: environment, tmpl: (const IVP_Template_Constraint *)v16);
      this->fix_wheel_constraint[wheel_nr] = constraint;
      *((_DWORD *)this->car_constraint_solver->wheel_objects.elems[wheel_nr] + 28) = constraint;
    }
  }
  else
  {
    *((_DWORD *)this->car_constraint_solver->wheel_objects.elems[wheel_nr] + 28) = 0;
    v5 = this->fix_wheel_constraint[wheel_nr];
    if ( v5 != nullptr )
      ((void (__thiscall *)(IVP_Constraint *, int))v5->dtr_IVP_Controller)(a1: v5, a2: 1);
    this->fix_wheel_constraint[wheel_nr] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078230
// Name: public: virtual float IVP_Car_System_Real_Wheels::get_booster_time_to_go(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Car_System_Real_Wheels::get_booster_time_to_go(IVP_Car_System_Real_Wheels *this)
{
  return this->booster_seconds_to_go;
}

//------------------------------------------------------------------------------
// Address: 0x10078240
// Name: public: IVP_Car_System_Real_Wheels::IVP_Car_System_Real_Wheels(class IVP_Environment __near *,class IVP_Template_Car_System __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IVP_Car_System_Real_Wheels *__userpurge IVP_Car_System_Real_Wheels::IVP_Car_System_Real_Wheels@<eax>(
        IVP_Car_System_Real_Wheels *this@<ecx>,
        int a2@<ebp>,
        IVP_Environment *env,
        IVP_Template_Car_System *templ)
{
  double v4; // rdi
  int v5; // edx
  float *wheel_reversed_sign; // ecx
  float *v7; // eax
  IVP_Constraint_Solver_Car *v8; // eax
  IVP_Constraint_Solver_Car *v9; // eax
  IVP_U_Float_Point *v10; // eax
  bool v11; // cc
  IVP_Template_Anchor *v12; // xmm1_4
  int v13; // xmm0_4
  float hesse_val; // xmm1_4
  int v15; // xmm0_4
  IVP_U_Active_Float *v16; // xmm1_4
  int v17; // eax
  unsigned int v18; // ecx
  float *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm0_4
  IVP_Environment *v22; // ecx
  IVP_Actuator_Suspension *suspension; // eax
  double v24; // st7
  int v25; // eax
  IVP_Real_Object **v26; // edx
  IVP_Real_Object **v27; // ecx
  IVP_Environment *v28; // ecx
  IVP_Actuator_Torque *torque; // eax
  int v30; // ecx
  float v31; // eax
  IVP_Real_Object *v32; // edx
  IVP_Environment *v33; // ecx
  IVP_Actuator_Torque *v34; // eax
  int v35; // ecx
  IVP_Real_Object_vtbl *v36; // xmm0_4
  IVP_Environment *v37; // ecx
  IVP_Actuator_Stabilizer *stabilizer; // eax
  float v39; // ecx
  int v40; // eax
  int v41; // edx
  IVP_Environment *v42; // ecx
  double extra_gravity_height_offset; // st7
  int v44; // eax
  int v45; // edx
  float extra_gravity_force_value; // xmm0_4
  IVP_Environment *v47; // ecx
  IVP_Environment *v48; // ecx
  IVP_Actuator_Force *force; // eax
  IVP_Real_Object *v50; // eax
  IVP_Environment *v51; // ecx
  IVP_Actuator_Force *v52; // eax
  IVP_U_Float_Point *v53; // ecx
  _DWORD *v54; // eax
  int v55; // edx
  IVP_U_Float_Point *v56; // eax
  IVP_Real_Object *y; // [esp+4h] [ebp-494h]
  IVP_Real_Object *ya; // [esp+4h] [ebp-494h]
  IVP_Real_Object *yb; // [esp+4h] [ebp-494h]
  IVP_Real_Object *yc; // [esp+4h] [ebp-494h]
  IVP_Real_Object *yd; // [esp+4h] [ebp-494h]
  _BYTE v63[12]; // [esp+1Ch] [ebp-47Ch] BYREF
  IVP_Template_Anchor anchor_wheel_template[10]; // [esp+28h] [ebp-470h] BYREF
  IVP_Template_Anchor anchor_body_template[10]; // [esp+168h] [ebp-330h] BYREF
  IVP_Template_Anchor v66; // [esp+2BCh] [ebp-1DCh] BYREF
  _BYTE v67[12]; // [esp+2DCh] [ebp-1BCh] BYREF
  IVP_Template_Anchor anchor_down_template; // [esp+2E8h] [ebp-1B0h] BYREF
  IVP_Template_Anchor anchor_center_template; // [esp+308h] [ebp-190h] BYREF
  IVP_Template_Anchor anchor_left_template; // [esp+328h] [ebp-170h] BYREF
  IVP_Template_Anchor anchor_right_template; // [esp+348h] [ebp-150h] BYREF
  float *v72; // [esp+368h] [ebp-130h]
  float *v73; // [esp+36Ch] [ebp-12Ch]
  IVP_Template_Torque torque_template; // [esp+370h] [ebp-128h] BYREF
  _BYTE spring_template[72]; // [esp+390h] [ebp-108h] OVERLAPPED BYREF
  IVP_U_Float_Point center; // [esp+3D8h] [ebp-C0h] BYREF
  float *v77; // [esp+3E8h] [ebp-B0h]
  float *v78; // [esp+3ECh] [ebp-ACh]
  IVP_Template_Force powerslide_template; // [esp+3F0h] [ebp-A8h] BYREF
  IVP_Template_Force force_template; // [esp+40Ch] [ebp-8Ch] BYREF
  _BYTE *v81; // [esp+428h] [ebp-70h]
  IVP_Template_Stabilizer stabi_template; // [esp+42Ch] [ebp-6Ch] BYREF
  unsigned int v83; // [esp+454h] [ebp-44h]
  IVP_U_Vector_Base v84; // [esp+458h] [ebp-40h] BYREF
  int v85; // [esp+460h] [ebp-38h] BYREF
  IVP_U_Vector<IVP_Real_Object> wheels; // [esp+464h] [ebp-34h] BYREF
  int v87; // [esp+46Ch] [ebp-2Ch] BYREF
  IVP_U_Vector<IVP_U_Float_Point> hard_points; // [esp+470h] [ebp-28h]
  IVP_U_Float_Point hp; // [esp+478h] [ebp-20h]
  IVP_U_Float_Point *wheel_pos_Bos; // [esp+488h] [ebp-10h]
  int wheel_nr; // [esp+48Ch] [ebp-Ch]
  IVP_Constraint_Solver_Car *cs_car; // [esp+490h] [ebp-8h]
  IVP_Constraint_Solver_Car *retaddr; // [esp+498h] [ebp+0h]

  wheel_nr = a2;
  cs_car = retaddr;
  this->__vftable = (IVP_Car_System_Real_Wheels_vtbl *)&IVP_Car_System_Real_Wheels::`vftable';
  v4 = COERCE_DOUBLE(__PAIR64__((unsigned int)this, (unsigned int)templ));
  this->n_wheels = templ->n_wheels;
  v5 = 0;
  this->n_axis = templ->n_axis;
  this->booster_actuator[0] = nullptr;
  this->booster_actuator[1] = nullptr;
  this->booster_seconds_to_go = 0.0;
  this->booster_seconds_until_ready = 0.0;
  this->fast_turn_factor = templ->fast_turn_factor;
  this->environment = env;
  this->car_body = templ->car_body;
  if ( this->n_wheels > 0 )
  {
    wheel_reversed_sign = this->wheel_reversed_sign;
    v7 = templ->wheel_reversed_sign;
    do
    {
      *(wheel_reversed_sign - 51) = *(v7 - 30);
      *wheel_reversed_sign = *v7;
      ++v5;
      ++v7;
      ++wheel_reversed_sign;
    }
    while ( v5 < *(_DWORD *)(HIDWORD(v4) + 8) );
    LODWORD(v4) = templ;
  }
  v8 = (IVP_Constraint_Solver_Car *)p_malloc(size: 0x98u);
  if ( v8 != nullptr )
    v9 = IVP_Constraint_Solver_Car::IVP_Constraint_Solver_Car(
           this: v8,
           right: *(IVP_COORDINATE_INDEX *)(LODWORD(v4) + 8),
           up: *(IVP_COORDINATE_INDEX *)(LODWORD(v4) + 12),
           forward: *(IVP_COORDINATE_INDEX *)(LODWORD(v4) + 16),
           is_left_hand: *(IVP_BOOL *)(LODWORD(v4) + 20));
  else
    v9 = nullptr;
  LODWORD(v4) = 0;
  *(_DWORD *)(HIDWORD(v4) + 60) = v9;
  *(_DWORD *)&v84.memsize = 0;
  v84.elems = nullptr;
  *(_DWORD *)&wheels.memsize = 0;
  wheels.elems = nullptr;
  if ( *(int *)(HIDWORD(v4) + 8) > 0 )
  {
    wheel_pos_Bos = templ->wheel_pos_Bos;
    LODWORD(hp.hesse_val) = HIDWORD(v4) + 20;
    do
    {
      hp.k[2] = *(float *)LODWORD(hp.hesse_val);
      if ( v84.n_elems >= v84.memsize )
        IVP_U_Vector_Base::increment_mem(this: &v84);
      v84.elems[v84.n_elems++] = (void *)LODWORD(hp.k[2]);
      if ( wheels.n_elems >= wheels.memsize )
        IVP_U_Vector_Base::increment_mem(this: &wheels);
      v10 = wheel_pos_Bos;
      LODWORD(hp.hesse_val) += 4;
      wheels.elems[wheels.n_elems++] = wheel_pos_Bos;
      ++LODWORD(v4);
      wheel_pos_Bos = v10 + 1;
    }
    while ( SLODWORD(v4) < *(_DWORD *)(HIDWORD(v4) + 8) );
  }
  IVP_Constraint_Solver_Car::init_constraint_system(
    this: *(IVP_Constraint_Solver_Car **)(HIDWORD(v4) + 60),
    env: *(IVP_Environment **)(HIDWORD(v4) + 4),
    body: *(IVP_Real_Object **)(HIDWORD(v4) + 16),
    wheels: (IVP_U_Vector<IVP_Real_Object> *)&v84,
    p_Bos: (IVP_U_Vector<IVP_U_Float_Point> *)&wheels);
  v11 = *(_DWORD *)(HIDWORD(v4) + 8) <= 0;
  hp.hesse_val = *(float *)(HIDWORD(v4) + 60);
  hp.k[2] = 0.0;
  if ( !v11 )
  {
    LODWORD(v4) = templ->spring_dampening;
    v85 = HIDWORD(v4) + 20;
    wheel_pos_Bos = (IVP_U_Float_Point *)&templ->wheel_pos_Bos[0].k[2];
    v83 = 0;
    do
    {
      IVP_Template_Suspension::IVP_Template_Suspension(this: (IVP_Template_Suspension *)&torque_template.max_rotation_speed);
      v12 = (IVP_Template_Anchor *)LODWORD(wheel_pos_Bos[-1].k[2]);
      *(_DWORD *)&spring_template[12] = *(_DWORD *)(LODWORD(v4) - 40);
      v13 = *(_DWORD *)LODWORD(v4);
      stabi_template.anchors[3] = v12;
      hesse_val = wheel_pos_Bos[-1].hesse_val;
      *(_DWORD *)&spring_template[16] = v13;
      v15 = *(_DWORD *)(LODWORD(v4) + 40);
      stabi_template.stabi_constant = hesse_val;
      v16 = (IVP_U_Active_Float *)LODWORD(wheel_pos_Bos->k[0]);
      v17 = *(_DWORD *)(LODWORD(hp.hesse_val) + 44);
      v18 = v83;
      *(_DWORD *)&spring_template[48] = v15;
      *(_DWORD *)&spring_template[52] = *(_DWORD *)(LODWORD(v4) + 80);
      v19 = (float *)&stabi_template.anchors[v17 + 3];
      stabi_template.active_float_stabi_constant = v16;
      v20 = *v19;
      *(_DWORD *)&spring_template[20] = 0;
      *v19 = v20 - 500.0;
      y = *(IVP_Real_Object **)(HIDWORD(v4) + 16);
      *(_QWORD *)spring_template = 1140457472;
      IVP_Template_Anchor::set_anchor_position_os(
        this: (IVP_Template_Anchor *)((char *)&anchor_wheel_template[9].coords_world.k[1] + v18),
        obj: y,
        coords_os: (const IVP_U_Float_Point *)&stabi_template.anchors[3]);
      IVP_Template_Anchor::set_anchor_position_os(
        this: (IVP_Template_Anchor *)&v63[v83],
        obj: *(IVP_Real_Object **)v85,
        x: 0.0,
        y: 0.0,
        z: 0.0);
      v21 = *(float *)spring_template - *(float *)(LODWORD(v4) + 120);
      torque_template.active_float_max_rotation_speed = (IVP_U_Active_Float *)&anchor_wheel_template[9].coords_world.k[v83 / 4 + 1];
      v22 = *(IVP_Environment **)(HIDWORD(v4) + 4);
      torque_template.active_float_rotation_speed_out = (IVP_U_Active_Terminal_Double *)&v63[v83];
      *(float *)spring_template = v21;
      suspension = IVP_Environment::create_suspension(
                     this: v22,
                     templ: (IVP_Template_Suspension *)&torque_template.max_rotation_speed);
      *(_DWORD *)(v85 + 88) = suspension;
      IVP_Template_Torque::IVP_Template_Torque(this: (IVP_Template_Torque *)&force_template.active_float_force);
      v24 = *(float *)(LODWORD(v4) - 420);
      v25 = *(_DWORD *)(LODWORD(hp.hesse_val) + 40);
      v26 = (IVP_Real_Object **)v85;
      stabi_template.anchors[0] = (IVP_Template_Anchor *)LODWORD(templ->wheel_max_rotation_speed[(LOBYTE(hp.k[2]) & 2) != 0]);
      memset(&stabi_template.anchors[3], 0, 12);
      *(float *)&stabi_template.anchors[v25 + 3] = v24;
      IVP_Template_Anchor::set_anchor_position_os(
        this: &v66,
        obj: *v26,
        coords_os: (const IVP_U_Float_Point *)&stabi_template.anchors[3]);
      v27 = (IVP_Real_Object **)v85;
      stabi_template.anchors[*(_DWORD *)(LODWORD(hp.hesse_val) + 40) + 3] = (IVP_Template_Anchor *)(*(_DWORD *)(LODWORD(v4) - 420)
                                                                                                  ^ _mask__NegFloat_);
      IVP_Template_Anchor::set_anchor_position_os(
        this: (IVP_Template_Anchor *)&anchor_body_template[9].coords_world.k[1],
        obj: *v27,
        coords_os: (const IVP_U_Float_Point *)&stabi_template.anchors[3]);
      force_template.push_second_object = (IVP_BOOL)&anchor_body_template[9].coords_world.k[1];
      v28 = *(IVP_Environment **)(HIDWORD(v4) + 4);
      force_template.push_first_object = (IVP_BOOL)&v66;
      v81 = nullptr;
      torque = IVP_Environment::create_torque(
                 this: v28,
                 templ: (IVP_Template_Torque *)&force_template.active_float_force);
      v30 = v85;
      ++wheel_pos_Bos;
      v83 += 32;
      *(_DWORD *)(v85 + 48) = torque;
      v31 = hp.k[2];
      *(_DWORD *)(v30 + 164) = 0;
      LODWORD(v4) += 4;
      LODWORD(hp.k[2]) = LODWORD(v31) + 1;
      v85 = v30 + 4;
    }
    while ( LODWORD(v31) + 1 < *(_DWORD *)(HIDWORD(v4) + 8) );
  }
  IVP_Template_Torque::IVP_Template_Torque(this: (IVP_Template_Torque *)&anchor_right_template.coords_world.hesse_val);
  *(float *)&v4 = hp.hesse_val;
  v32 = *(IVP_Real_Object **)(HIDWORD(v4) + 16);
  torque_template.anchors[1] = (IVP_Template_Anchor *)1134367843;
  hard_points.elems = nullptr;
  *(_DWORD *)&hard_points.memsize = 0;
  v87 = 0;
  *(&v87 + *(_DWORD *)(LODWORD(hp.hesse_val) + 40)) = 1065353216;
  IVP_Template_Anchor::set_anchor_position_cs(
    this: (IVP_Template_Anchor *)&anchor_center_template.coords_world.k[1],
    obj: v32,
    coords_cs: (const IVP_U_Float_Point *)&v87);
  ya = *(IVP_Real_Object **)(HIDWORD(v4) + 16);
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 40)) = -1082130432;
  IVP_Template_Anchor::set_anchor_position_cs(
    this: (IVP_Template_Anchor *)&anchor_left_template.coords_world.k[1],
    obj: ya,
    coords_cs: (const IVP_U_Float_Point *)&v87);
  v73 = &anchor_left_template.coords_world.k[1];
  v33 = *(IVP_Environment **)(HIDWORD(v4) + 4);
  v72 = &anchor_center_template.coords_world.k[1];
  torque_template.client_data = nullptr;
  v34 = IVP_Environment::create_torque(
          this: v33,
          templ: (IVP_Template_Torque *)&anchor_right_template.coords_world.hesse_val);
  v35 = *(_DWORD *)(HIDWORD(v4) + 8);
  *(_DWORD *)(HIDWORD(v4) + 64) = v34;
  *(float *)(HIDWORD(v4) + 304) = templ->body_counter_torque_factor;
  if ( v35 != *(_DWORD *)(HIDWORD(v4) + 12) )
  {
    LODWORD(hp.hesse_val) = HIDWORD(v4) + 148;
    wheel_pos_Bos = (IVP_U_Float_Point *)templ->stabilizer_constant;
    hp.k[2] = 0.0;
    do
    {
      IVP_Template_Stabilizer::IVP_Template_Stabilizer(this: (IVP_Template_Stabilizer *)&force_template.push_first_object);
      v36 = (IVP_Real_Object_vtbl *)LODWORD(wheel_pos_Bos->k[0]);
      force_template.push_second_object = (IVP_BOOL)((char *)&anchor_wheel_template[9].coords_world.k[1]
                                                   + LODWORD(hp.k[2]));
      v81 = &v63[LODWORD(hp.k[2])];
      stabi_template.client_data = (char *)&anchor_body_template[0].coords_world.k[1] + LODWORD(hp.k[2]);
      v37 = *(IVP_Environment **)(HIDWORD(v4) + 4);
      stabi_template.anchors[1] = (IVP_Template_Anchor *)v36;
      stabi_template.anchors[0] = (IVP_Template_Anchor *)((char *)&anchor_wheel_template[0].coords_world.k[1]
                                                        + LODWORD(hp.k[2]));
      stabilizer = IVP_Environment::create_stabilizer(
                     this: v37,
                     templ: (IVP_Template_Stabilizer *)&force_template.push_first_object);
      v39 = hp.hesse_val;
      wheel_pos_Bos = (IVP_U_Float_Point *)((char *)wheel_pos_Bos + 4);
      *(_DWORD *)LODWORD(hp.hesse_val) = stabilizer;
      LODWORD(hp.hesse_val) = LODWORD(v39) + 4;
      LODWORD(hp.k[2]) += 64;
    }
    while ( SLODWORD(hp.k[2]) < 128 );
  }
  wheel_pos_Bos = *(IVP_U_Float_Point **)(*(_DWORD *)(HIDWORD(v4) + 4) + 48);
  IVP_Template_Force::IVP_Template_Force(this: (IVP_Template_Force *)&powerslide_template.active_float_force);
  hard_points.elems = nullptr;
  *(_DWORD *)&hard_points.memsize = 0;
  v87 = 0;
  *((float *)&v87 + *(_DWORD *)(LODWORD(v4) + 44)) = templ->body_down_force_vertical_offset
                                                   + *((float *)&v87 + *(_DWORD *)(LODWORD(v4) + 44));
  IVP_Template_Anchor::set_anchor_position_cs(
    this: (IVP_Template_Anchor *)&anchor_down_template.coords_world.k[1],
    obj: *(IVP_Real_Object **)(HIDWORD(v4) + 16),
    coords_cs: (const IVP_U_Float_Point *)&v87);
  v40 = *(_DWORD *)(HIDWORD(v4) + 4);
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 44)) = 1287568416;
  v41 = *(_DWORD *)(LODWORD(v4) + 44);
  if ( *(float *)(v40 + 4 * v41 + 176) > 0.0 )
    *((float *)&v87 + v41) = *((float *)&v87 + v41) * -1.0;
  IVP_Template_Anchor::set_anchor_position_os(
    this: (IVP_Template_Anchor *)v67,
    obj: (IVP_Real_Object *)wheel_pos_Bos,
    coords_os: (const IVP_U_Float_Point *)&v87);
  powerslide_template.push_second_object = (IVP_BOOL)v67;
  v42 = *(IVP_Environment **)(HIDWORD(v4) + 4);
  powerslide_template.push_first_object = (IVP_BOOL)&anchor_down_template.coords_world.k[1];
  force_template.client_data = nullptr;
  force_template.anchors[1] = (IVP_Template_Anchor *)1;
  force_template.force = 0.0;
  *(_DWORD *)(HIDWORD(v4) + 168) = IVP_Environment::create_force(
                                     this: v42,
                                     templ: (IVP_Template_Force *)&powerslide_template.active_float_force);
  extra_gravity_height_offset = templ->extra_gravity_height_offset;
  memset(&spring_template[60], 0, 12);
  *(float *)&spring_template[4 * *(_DWORD *)(LODWORD(v4) + 44) + 60] = extra_gravity_height_offset;
  IVP_Template_Anchor::set_anchor_position_cs(
    this: (IVP_Template_Anchor *)&anchor_down_template.coords_world.k[1],
    obj: *(IVP_Real_Object **)(HIDWORD(v4) + 16),
    coords_cs: (const IVP_U_Float_Point *)&spring_template[60]);
  v44 = *(_DWORD *)(HIDWORD(v4) + 4);
  hard_points = 0;
  v87 = 0;
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 44)) = 1287568416;
  v45 = *(_DWORD *)(LODWORD(v4) + 44);
  if ( *(float *)(v44 + 4 * v45 + 176) > 0.0 )
    *((float *)&v87 + v45) = *((float *)&v87 + v45) * -1.0;
  IVP_Template_Anchor::set_anchor_position_os(
    this: (IVP_Template_Anchor *)v67,
    obj: (IVP_Real_Object *)wheel_pos_Bos,
    coords_os: (const IVP_U_Float_Point *)&v87);
  extra_gravity_force_value = templ->extra_gravity_force_value;
  powerslide_template.push_first_object = (IVP_BOOL)&anchor_down_template.coords_world.k[1];
  powerslide_template.push_second_object = (IVP_BOOL)v67;
  v47 = *(IVP_Environment **)(HIDWORD(v4) + 4);
  *(float *)&force_template.client_data = extra_gravity_force_value;
  force_template.anchors[1] = (IVP_Template_Anchor *)1;
  force_template.force = 0.0;
  *(_DWORD *)(HIDWORD(v4) + 172) = IVP_Environment::create_force(
                                     this: v47,
                                     templ: (IVP_Template_Force *)&powerslide_template.active_float_force);
  IVP_Template_Force::IVP_Template_Force(this: (IVP_Template_Force *)&center.hesse_val);
  hard_points.elems = nullptr;
  *(_DWORD *)&hard_points.memsize = 0;
  v87 = 0;
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 40)) = -1082130432;
  yb = *(IVP_Real_Object **)(HIDWORD(v4) + 16);
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 48)) = 0x40000000;
  IVP_Template_Anchor::set_anchor_position_cs(
    this: (IVP_Template_Anchor *)&anchor_center_template.coords_world.k[1],
    obj: yb,
    coords_cs: (const IVP_U_Float_Point *)&v87);
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 40)) = 1065353216;
  yc = *(IVP_Real_Object **)(HIDWORD(v4) + 16);
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 48)) = 0x40000000;
  IVP_Template_Anchor::set_anchor_position_cs(
    this: (IVP_Template_Anchor *)&anchor_left_template.coords_world.k[1],
    obj: yc,
    coords_cs: (const IVP_U_Float_Point *)&v87);
  v78 = &anchor_left_template.coords_world.k[1];
  v48 = *(IVP_Environment **)(HIDWORD(v4) + 4);
  v77 = &anchor_center_template.coords_world.k[1];
  powerslide_template.client_data = nullptr;
  force = IVP_Environment::create_force(this: v48, templ: (IVP_Template_Force *)&center.hesse_val);
  hard_points.elems = nullptr;
  *(_DWORD *)&hard_points.memsize = 0;
  v87 = 0;
  *(_DWORD *)(HIDWORD(v4) + 176) = force;
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 40)) = -1082130432;
  v50 = *(IVP_Real_Object **)(HIDWORD(v4) + 16);
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 48)) = -1073741824;
  IVP_Template_Anchor::set_anchor_position_cs(
    this: (IVP_Template_Anchor *)&anchor_center_template.coords_world.k[1],
    obj: v50,
    coords_cs: (const IVP_U_Float_Point *)&v87);
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 40)) = 1065353216;
  yd = *(IVP_Real_Object **)(HIDWORD(v4) + 16);
  *(&v87 + *(_DWORD *)(LODWORD(v4) + 48)) = -1073741824;
  IVP_Template_Anchor::set_anchor_position_cs(
    this: (IVP_Template_Anchor *)&anchor_left_template.coords_world.k[1],
    obj: yd,
    coords_cs: (const IVP_U_Float_Point *)&v87);
  v51 = *(IVP_Environment **)(HIDWORD(v4) + 4);
  v77 = &anchor_center_template.coords_world.k[1];
  v78 = &anchor_left_template.coords_world.k[1];
  powerslide_template.client_data = nullptr;
  v52 = IVP_Environment::create_force(this: v51, templ: (IVP_Template_Force *)&center.hesse_val);
  v53 = nullptr;
  *(_DWORD *)(HIDWORD(v4) + 180) = v52;
  wheel_pos_Bos = nullptr;
  if ( *(int *)(HIDWORD(v4) + 8) > 0 )
  {
    while ( 1 )
    {
      v54 = *(_DWORD **)(HIDWORD(v4) + 60);
      LODWORD(v4) = *(_DWORD *)(v54[3] + 4 * (_DWORD)v53);
      v55 = v54[10];
      stabi_template.anchors[3] = *(IVP_Template_Anchor **)(LODWORD(v4) + 64);
      stabi_template.stabi_constant = *(float *)(LODWORD(v4) + 68);
      stabi_template.active_float_stabi_constant = *(IVP_U_Active_Float **)(LODWORD(v4) + 72);
      v11 = *(float *)(HIDWORD(v4) + 4 * (_DWORD)v53 + 224) >= 0.0;
      *((_DWORD *)&stabi_template.client_data + v55) = 0;
      *((_DWORD *)&stabi_template.client_data + v54[11]) = 0;
      *((_DWORD *)&stabi_template.client_data + v54[12]) = 0;
      if ( !v11 )
        *((float *)&stabi_template.client_data + v54[11]) = *((float *)&stabi_template.client_data + v54[11])
                                                          + 3.1415927;
      IVP_U_Matrix::init_rot_multiple(
        this: (IVP_U_Matrix *)(LODWORD(v4) + 16),
        a2: v4,
        angles: (const IVP_U_Point *)&stabi_template,
        factor: 1.0);
      v56 = wheel_pos_Bos;
      *(_DWORD *)(LODWORD(v4) + 64) = stabi_template.anchors[3];
      *(float *)(LODWORD(v4) + 68) = stabi_template.stabi_constant;
      *(_DWORD *)(LODWORD(v4) + 72) = stabi_template.active_float_stabi_constant;
      wheel_pos_Bos = (IVP_U_Float_Point *)((char *)v56->k + 1);
      if ( (int)v56->k + 1 >= *(_DWORD *)(HIDWORD(v4) + 8) )
        break;
      v53 = wheel_pos_Bos;
    }
  }
  *(_DWORD *)(HIDWORD(v4) + 332) = -1082130432;
  IVP_Car_System_Real_Wheels::do_steering(
    this: (IVP_Car_System_Real_Wheels *)HIDWORD(v4),
    a2: SLODWORD(v4),
    a3: SHIDWORD(v4),
    s_angle: 0.0,
    bAnalog: false);
  if ( (int *)wheels.elems != &v87 )
  {
    if ( wheels.elems != nullptr )
      free(data: wheels.elems);
    wheels.elems = nullptr;
    wheels.memsize = 0;
  }
  wheels.n_elems = 0;
  if ( (int *)v84.elems != &v85 && v84.elems != nullptr )
    free(data: v84.elems);
  return (IVP_Car_System_Real_Wheels *)HIDWORD(v4);
}
