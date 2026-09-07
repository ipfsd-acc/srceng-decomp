// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_actuator.cxx
// Functions: 32
// ============================================================

#include "ivp\ivp_controller\ivp_actuator.h"

//------------------------------------------------------------------------------
// Address: 0x1008C360
// Name: public: IVP_Template_Two_Point::IVP_Template_Two_Point(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Two_Point *__thiscall IVP_Template_Two_Point::IVP_Template_Two_Point(IVP_Template_Two_Point *this)
{
  *(_QWORD *)&this->client_data = 0;
  this->anchors[1] = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008C380
// Name: public: void IVP_Template_Anchor::set_anchor_position_os(class IVP_Real_Object __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Anchor::set_anchor_position_os(
        IVP_Template_Anchor *this,
        IVP_Real_Object *obj,
        const IVP_U_Float_Point *coords_os)
{
  IVP_Cache_Object *cache_object; // ecx

  this->object = obj;
  if ( obj->cache_object == nullptr )
    obj->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                          this: obj->environment->cache_object_manager,
                          object: obj);
  if ( *(_BYTE *)&obj->flags < 8 )
  {
    cache_object = obj->cache_object;
    if ( obj->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  IVP_Cache_Object::transform_position_to_world_coords(
    this: obj->cache_object,
    P_object: coords_os,
    P_world_out: &this->coords_world);
}

//------------------------------------------------------------------------------
// Address: 0x1008C3E0
// Name: public: void IVP_Template_Anchor::set_anchor_position_os(class IVP_Real_Object __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Template_Anchor::set_anchor_position_os(
        IVP_Template_Anchor *this@<ecx>,
        float a2@<ebp>,
        IVP_Real_Object *obj,
        float x,
        float y,
        float z)
{
  bool v7; // zf
  IVP_Cache_Object *cache_object; // ecx
  _DWORD v9[3]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Float_Point coords_os; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  coords_os.k[1] = a2;
  coords_os.k[2] = retaddr;
  *(float *)v9 = x;
  this->object = obj;
  v7 = obj->cache_object == nullptr;
  *(float *)&v9[1] = y;
  *(float *)&v9[2] = z;
  if ( v7 )
    obj->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                          this: obj->environment->cache_object_manager,
                          object: obj);
  if ( *(_BYTE *)&obj->flags < 8 )
  {
    cache_object = obj->cache_object;
    if ( obj->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  IVP_Cache_Object::transform_position_to_world_coords(
    this: obj->cache_object,
    P_object: (const IVP_U_Float_Point *)v9,
    P_world_out: &this->coords_world);
}

//------------------------------------------------------------------------------
// Address: 0x1008C470
// Name: public: void IVP_Actuator_Two_Point::ensure_actuator_in_simulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Two_Point::ensure_actuator_in_simulation(IVP_Actuator_Two_Point *this)
{
  IVP_Controller_Manager::ensure_controller_in_simulation(
    this: this->anchors[0].l_anchor_object->environment->controller_manager,
    cntrl: this);
}

//------------------------------------------------------------------------------
// Address: 0x1008C480
// Name: public: void IVP_Actuator_Force::set_force(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Force::set_force(IVP_Actuator_Force *this, float nforce)
{
  if ( nforce != this->force )
  {
    this->force = nforce;
    IVP_Controller_Manager::ensure_controller_in_simulation(
      this: this->anchors[0].l_anchor_object->environment->controller_manager,
      cntrl: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C4B0
// Name: protected: virtual void IVP_Actuator_Force_Active::active_float_changed(class IVP_U_Active_Float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Force_Active::active_float_changed(
        IVP_Actuator_Force_Active *this,
        IVP_U_Active_Float *af)
{
  float double_value; // xmm0_4
  float *v3; // ecx

  if ( af == *(IVP_U_Active_Float **)&this->actuator_controlled_cores.memsize )
  {
    double_value = af->double_value;
    v3 = (float *)((char *)this - 176);
    if ( double_value != v3[40] )
    {
      v3[40] = double_value;
      IVP_Controller_Manager::ensure_controller_in_simulation(
        this: *(IVP_Controller_Manager **)(*(_DWORD *)(*((_DWORD *)v3 + 6) + 24) + 52),
        cntrl: (IVP_Controller_Dependent *)v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C4F0
// Name: public: void IVP_Actuator_Torque::set_torque(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Torque::set_torque(IVP_Actuator_Torque *this, float val)
{
  if ( val != this->torque )
  {
    this->torque = val;
    IVP_Controller_Manager::ensure_controller_in_simulation(
      this: this->anchors[0].l_anchor_object->environment->controller_manager,
      cntrl: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C520
// Name: private: virtual void IVP_Actuator_Torque_Active::active_float_changed(class IVP_U_Active_Float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Torque_Active::active_float_changed(
        IVP_Actuator_Torque_Active *this,
        IVP_U_Active_Float *af)
{
  float double_value; // xmm0_4
  bool v4; // zf
  float *v5; // ecx
  float v6; // xmm0_4
  float *v7; // ecx

  if ( af == *(IVP_U_Active_Float **)&this->actuator_controlled_cores.memsize )
  {
    double_value = af->double_value;
    v4 = double_value == *((float *)this - 12);
    v5 = (float *)((char *)this - 208);
    if ( !v4 )
    {
      v5[40] = double_value;
      IVP_Controller_Manager::ensure_controller_in_simulation(
        this: *(IVP_Controller_Manager **)(*(_DWORD *)(*((_DWORD *)v5 + 6) + 24) + 52),
        cntrl: (IVP_Actuator_Torque_Active *)((char *)this - 208));
    }
  }
  if ( af == (IVP_U_Active_Float *)this->actuator_controlled_cores.elems )
  {
    v6 = af->double_value;
    v7 = (float *)((char *)this - 208);
    if ( v6 != *((float *)this - 11) )
    {
      v7[41] = v6;
      IVP_Controller_Manager::ensure_controller_in_simulation(
        this: *(IVP_Controller_Manager **)(*(_DWORD *)(*((_DWORD *)v7 + 6) + 24) + 52),
        cntrl: (IVP_Actuator_Torque_Active *)((char *)this - 208));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C5A0
// Name: protected: virtual void IVP_Actuator_Torque::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Actuator_Torque::do_simulation_controller(
        IVP_Actuator_Torque *this@<ecx>,
        int a2@<ebp>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  float torque; // xmm1_4
  IVP_Real_Object *l_anchor_object; // eax
  IVP_Core *physical_core; // edi
  IVP_U_Active_Terminal_Double *active_float_rotation_speed_out; // ecx
  float hesse_val; // xmm0_4
  float v10[3]; // [esp+1Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point h; // [esp+28h] [ebp-20h]
  const IVP_U_Float_Point *p_axis_in_core_coord_system; // [esp+38h] [ebp-10h]
  int v13; // [esp+3Ch] [ebp-Ch]
  float domega; // [esp+40h] [ebp-8h]
  float retaddr; // [esp+48h] [ebp+0h]

  v13 = a2;
  domega = retaddr;
  torque = this->torque;
  this->rot_speed_out = 0.0;
  if ( torque != 0.0 )
  {
    l_anchor_object = this->anchors[0].l_anchor_object;
    physical_core = l_anchor_object->physical_core;
    if ( *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) < 8u
      && (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 0x10) == 0 )
    {
      if ( physical_core == l_anchor_object->original_core )
      {
        p_axis_in_core_coord_system = &this->axis_in_core_coord_system;
      }
      else
      {
        v10[0] = this->anchors[1].core_pos.k[0] - this->anchors[0].core_pos.k[0];
        v10[1] = this->anchors[1].core_pos.k[1] - this->anchors[0].core_pos.k[1];
        v10[2] = this->anchors[1].core_pos.k[2] - this->anchors[0].core_pos.k[2];
        IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)v10);
        p_axis_in_core_coord_system = (const IVP_U_Float_Point *)v10;
      }
      h.hesse_val = IVP_Core::get_rot_speed_cs(this: physical_core, normized_core_axis: p_axis_in_core_coord_system);
      active_float_rotation_speed_out = this->active_float_rotation_speed_out;
      this->rot_speed_out = h.hesse_val;
      hesse_val = h.hesse_val;
      if ( active_float_rotation_speed_out != nullptr )
      {
        ((void (__stdcall *)(_DWORD, _DWORD))active_float_rotation_speed_out->set_double)(
          a1: LODWORD(h.hesse_val),
          a2: 0);
        hesse_val = h.hesse_val;
      }
      if ( COERCE_FLOAT(LODWORD(hesse_val) & _mask__AbsFloat_) <= this->max_rotation_speed )
        IVP_Core::async_rot_push_core_multiple_cs(
          this: physical_core,
          normized_core_axis: p_axis_in_core_coord_system,
          rot_impulse: this->torque * es->delta_time);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C6C0
// Name: public: void IVP_Anchor::object_is_going_to_be_deleted_event(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Anchor::object_is_going_to_be_deleted_event(IVP_Anchor *this, IVP_Real_Object *obj)
{
  this->l_actuator->anchor_will_be_deleted_event(this: this->l_actuator, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1008C6D0
// Name: public: virtual void IVP_Actuator_Force::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Actuator_Force::do_simulation_controller(
        IVP_Actuator_Force *this@<ecx>,
        int a2@<ebp>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Core *physical_core; // edi
  bool v6; // zf
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float hesse_val; // xmm1_4
  float v11[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Float_Point force_dir_rev; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Point pos1_ws; // [esp+10h] [ebp-50h] BYREF
  IVP_U_Point pos0_ws; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Float_Point force_dir; // [esp+30h] [ebp-30h] BYREF
  IVP_U_Point dir_ws; // [esp+40h] [ebp-20h]
  IVP_Core *v17; // [esp+50h] [ebp-10h]
  int v18; // [esp+54h] [ebp-Ch] BYREF
  float force_val; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  v18 = a2;
  force_val = retaddr;
  dir_ws.hesse_val = this->force;
  if ( dir_ws.hesse_val != 0.0 )
  {
    physical_core = this->anchors[0].l_anchor_object->physical_core;
    v17 = this->anchors[1].l_anchor_object->physical_core;
    IVP_U_Matrix::vmult4(
      this: &physical_core->m_world_f_core_last_psi,
      p_in: &this->anchors[0].core_pos,
      p_out: (IVP_U_Point *)&pos1_ws.k[1]);
    IVP_U_Matrix::vmult4(
      this: &v17->m_world_f_core_last_psi,
      p_in: &this->anchors[1].core_pos,
      p_out: (IVP_U_Float_Point *)&force_dir_rev.k[1]);
    force_dir.k[1] = pos1_ws.k[1] - force_dir_rev.k[1];
    force_dir.k[2] = pos1_ws.k[2] - force_dir_rev.k[2];
    force_dir.hesse_val = pos1_ws.hesse_val - force_dir_rev.hesse_val;
    IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&force_dir.k[1]);
    v6 = (*((_BYTE *)this + 164) & 1) == 0;
    v7 = es->delta_time * dir_ws.hesse_val;
    v8 = force_dir.k[1] * v7;
    v9 = force_dir.k[2] * v7;
    hesse_val = force_dir.hesse_val * v7;
    pos0_ws.k[1] = force_dir.k[1] * v7;
    pos0_ws.k[2] = force_dir.k[2] * v7;
    pos0_ws.hesse_val = force_dir.hesse_val * v7;
    if ( !v6
      && *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) < 8u
      && (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 0x10) == 0 )
    {
      IVP_Core::async_push_core_ws(
        this: physical_core,
        a2: COERCE_FLOAT(&v18),
        world_point: (IVP_U_Point *)&pos1_ws.k[1],
        impulse_in_world: (IVP_U_Point *)&pos0_ws.k[1]);
      hesse_val = pos0_ws.hesse_val;
      v9 = pos0_ws.k[2];
      v8 = pos0_ws.k[1];
    }
    if ( (*((_BYTE *)this + 164) & 2) != 0
      && *((_BYTE *)&v17->IVP_Core_Fast_Static + 1) < 8u
      && (*(_BYTE *)&v17->IVP_Core_Fast_Static & 0x10) == 0 )
    {
      v11[0] = v8 * -1.0;
      v11[1] = v9 * -1.0;
      v11[2] = hesse_val * -1.0;
      IVP_Core::async_push_core_ws(
        this: v17,
        a2: COERCE_FLOAT(&v18),
        world_point: (const IVP_U_Point *)&force_dir_rev.k[1],
        impulse_in_world: (const IVP_U_Float_Point *)v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C840
// Name: public: void IVP_Actuator_Stabilizer::set_stabi_constant(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Stabilizer::set_stabi_constant(IVP_Actuator_Stabilizer *this, float val)
{
  if ( val != this->stabi_constant )
  {
    this->stabi_constant = val;
    IVP_Real_Object::ensure_in_simulation(this: this->anchors[0].l_anchor_object);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C870
// Name: protected: virtual void IVP_Actuator_Stabilizer::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Actuator_Stabilizer::do_simulation_controller(
        IVP_Actuator_Stabilizer *this@<ecx>,
        int a2@<ebp>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Real_Object *l_anchor_object; // eax
  IVP_Core *friction_core; // edx
  IVP_Real_Object *v6; // eax
  IVP_Core *v7; // edx
  IVP_Real_Object *v8; // eax
  IVP_Core *v9; // edx
  IVP_U_Float_Point *p_core_pos; // edi
  int i; // esi
  IVP_U_Matrix *v12; // ecx
  double v13; // st7
  float v14; // eax
  float v15; // xmm3_4
  int *v16; // edi
  int v17; // esi
  int v18; // ecx
  IVP_Core *v19; // xmm2_4
  IVP_Core *v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // ecx
  IVP_U_Float_Point dir[2]; // [esp+80h] [ebp-60h]
  _DWORD v24[2]; // [esp+A0h] [ebp-40h] BYREF
  IVP_Core *core[4]; // [esp+A8h] [ebp-38h] BYREF
  IVP_Core *pc1; // [esp+B8h] [ebp-28h]
  float v27[3]; // [esp+BCh] [ebp-24h] BYREF
  float v28; // [esp+D0h] [ebp-10h]
  _DWORD v29[2]; // [esp+D4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+E0h] [ebp+0h]

  v29[0] = a2;
  v29[1] = retaddr;
  l_anchor_object = this->anchors[1].l_anchor_object;
  LODWORD(dir[1].hesse_val) = this->anchors[0].l_anchor_object->friction_core;
  friction_core = l_anchor_object->friction_core;
  v6 = this->anchors[2].l_anchor_object;
  v24[0] = friction_core;
  v7 = v6->friction_core;
  v8 = this->anchors[3].l_anchor_object;
  v24[1] = v7;
  v9 = v8->friction_core;
  core[2] = (IVP_Core *)this;
  core[0] = v9;
  v28 = COERCE_FLOAT(v27);
  p_core_pos = &this->anchors[0].core_pos;
  for ( i = 0; i < 8; i += 4 )
  {
    v12 = (IVP_U_Matrix *)(*(_DWORD *)(LODWORD(p_core_pos[-2].k[2]) + 152) + 96);
    core[1] = *(IVP_Core **)(LODWORD(p_core_pos[2].k[2]) + 152);
    IVP_U_Matrix::vmult4(this: v12, p_in: p_core_pos, p_out: (IVP_U_Float_Point *)&v29[i - 56]);
    IVP_U_Matrix::vmult4(
      this: &core[1]->m_world_f_core_last_psi,
      p_in: p_core_pos + 4,
      p_out: (IVP_U_Float_Point *)&v29[i - 40]);
    *(float *)&v29[i - 24] = *(float *)&v29[i - 56] - *(float *)&v29[i - 40];
    *(float *)&v29[i - 23] = *(float *)&v29[i - 55] - *(float *)&v29[i - 39];
    *(float *)&v29[i - 22] = *(float *)&v29[i - 54] - *(float *)&v29[i - 38];
    v13 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&v29[i - 24]);
    v14 = v28;
    *(float *)LODWORD(v28) = v13;
    p_core_pos += 8;
    LODWORD(v28) = LODWORD(v14) + 4;
  }
  v15 = (float)((float)(v27[1] - v27[0]) * core[2]->rotation_axis_world_space.k[1]) * es->delta_time;
  v28 = v15;
  v16 = v24;
  v17 = 0;
  do
  {
    v18 = *v16;
    *(float *)&v19 = *(float *)&v29[v17 - 24] * v15;
    *(float *)&v20 = *(float *)&v29[v17 - 23] * v15;
    v21 = *(float *)&v29[v17 - 22] * v15;
    core[3] = v19;
    pc1 = v20;
    v27[0] = v21;
    if ( *(_BYTE *)(v18 + 1) < 8u && (*(_BYTE *)v18 & 0x10) == 0 )
    {
      IVP_Core::async_push_core_ws(
        this: (IVP_Core *)v18,
        a2: COERCE_FLOAT(v29),
        world_point: (const IVP_U_Point *)&v29[v17 - 40],
        impulse_in_world: (const IVP_U_Float_Point *)&core[3]);
      v21 = v27[0];
      v20 = pc1;
      v19 = core[3];
      v15 = v28;
    }
    v22 = *(v16 - 1);
    if ( *(_BYTE *)(v22 + 1) < 8u && (*(_BYTE *)v22 & 0x10) == 0 )
    {
      *(float *)&core[3] = *(float *)&v19 * -1.0;
      *(float *)&pc1 = *(float *)&v20 * -1.0;
      v27[0] = v21 * -1.0;
      IVP_Core::async_push_core_ws(
        this: (IVP_Core *)v22,
        a2: COERCE_FLOAT(v29),
        world_point: (const IVP_U_Point *)&v29[v17 - 56],
        impulse_in_world: (const IVP_U_Float_Point *)&core[3]);
      v15 = v28;
    }
    v17 += 4;
    v16 += 2;
    v15 = v15 * -1.0;
    v28 = v15;
  }
  while ( v17 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x1008CAA0
// Name: public: IVP_Template_Torque::IVP_Template_Torque(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Torque *__thiscall IVP_Template_Torque::IVP_Template_Torque(IVP_Template_Torque *this)
{
  *(_QWORD *)&this->client_data = 0;
  this->anchors[1] = nullptr;
  *(_QWORD *)&this->client_data = 0;
  *(_QWORD *)&this->anchors[1] = 0;
  *(_QWORD *)&this->active_float_torque = 0;
  *(_QWORD *)&this->active_float_max_rotation_speed = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008CAD0
// Name: public: IVP_Template_Stabilizer::IVP_Template_Stabilizer(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Stabilizer *__thiscall IVP_Template_Stabilizer::IVP_Template_Stabilizer(IVP_Template_Stabilizer *this)
{
  *(_QWORD *)&this->client_data = 0;
  *(_QWORD *)&this->anchors[1] = 0;
  *(_QWORD *)&this->client_data = 0;
  *(_QWORD *)&this->anchors[1] = 0;
  *(_QWORD *)&this->anchors[3] = 0;
  this->active_float_stabi_constant = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008CB00
// Name: public: IVP_Template_Force::IVP_Template_Force(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Force *__thiscall IVP_Template_Force::IVP_Template_Force(IVP_Template_Force *this)
{
  *(_QWORD *)&this->client_data = 0;
  *(_QWORD *)&this->client_data = 0;
  *(_QWORD *)&this->anchors[1] = 0;
  *(_QWORD *)&this->active_float_force = 0;
  this->push_first_object = IVP_TRUE;
  this->push_second_object = IVP_FALSE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008CB30
// Name: public: void IVP_Anchor::init_anchor(class IVP_Actuator __near *,class IVP_Template_Anchor __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Anchor::init_anchor(
        IVP_Anchor *this@<ecx>,
        float a2@<ebp>,
        IVP_Actuator *ac,
        IVP_Template_Anchor *ta)
{
  IVP_Real_Object *object; // eax
  IVP_Real_Object *v6; // edi
  IVP_Cache_Object *cache_object; // ecx
  _BYTE v8[12]; // [esp-Ch] [ebp-5Ch] BYREF
  IVP_U_Matrix m_core_f_object; // [esp+0h] [ebp-50h] BYREF
  IVP_U_Point obj_pos; // [esp+40h] [ebp-10h]
  float retaddr; // [esp+50h] [ebp+0h]

  obj_pos.k[1] = a2;
  obj_pos.k[2] = retaddr;
  object = ta->object;
  this->l_actuator = ac;
  this->l_anchor_object = object;
  IVP_Real_Object::calc_m_core_f_object(this: object, m_core_f_object: (IVP_U_Matrix *)v8);
  v6 = ta->object;
  if ( ta->object->cache_object == nullptr )
    v6->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                         this: v6->environment->cache_object_manager,
                         object: v6);
  if ( *(_BYTE *)&v6->flags < 8 )
  {
    cache_object = v6->cache_object;
    if ( v6->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  IVP_Cache_Object::transform_position_to_object_coords(
    this: v6->cache_object,
    P_world: &ta->coords_world,
    P_object_out: (IVP_U_Point *)&m_core_f_object.vv.k[1]);
  this->object_pos.k[0] = m_core_f_object.vv.k[1];
  this->object_pos.k[1] = m_core_f_object.vv.k[2];
  this->object_pos.k[2] = m_core_f_object.vv.hesse_val;
  IVP_U_Matrix::vmult4(this: (IVP_U_Matrix *)v8, p_in: &this->object_pos, p_out: &this->core_pos);
  IVP_Real_Object::insert_anchor(this: this->l_anchor_object, new_anchor: this);
}

//------------------------------------------------------------------------------
// Address: 0x1008CBF0
// Name: public: void IVP_Template_Anchor::set_anchor_position_cs(class IVP_Real_Object __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Template_Anchor::set_anchor_position_cs(
        IVP_Template_Anchor *this@<ecx>,
        float a2@<ebp>,
        IVP_Real_Object *obj,
        const IVP_U_Float_Point *coords_cs)
{
  IVP_Cache_Object *cache_object; // ecx
  _BYTE v6[12]; // [esp-Ch] [ebp-5Ch] BYREF
  IVP_U_Matrix mat; // [esp+0h] [ebp-50h] BYREF
  IVP_U_Float_Point coords_os; // [esp+40h] [ebp-10h]
  float retaddr; // [esp+50h] [ebp+0h]

  coords_os.k[1] = a2;
  coords_os.k[2] = retaddr;
  this->object = obj;
  IVP_Real_Object::calc_m_core_f_object(this: obj, m_core_f_object: (IVP_U_Matrix *)v6);
  IVP_U_Matrix::vimult4(this: (IVP_U_Matrix *)v6, p_in: coords_cs, p_out: (IVP_U_Float_Point *)&mat.vv.k[1]);
  this->object = obj;
  if ( obj->cache_object == nullptr )
    obj->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                          this: obj->environment->cache_object_manager,
                          object: obj);
  if ( *(_BYTE *)&obj->flags < 8 )
  {
    cache_object = obj->cache_object;
    if ( obj->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  IVP_Cache_Object::transform_position_to_world_coords(
    this: obj->cache_object,
    P_object: (const IVP_U_Float_Point *)&mat.vv.k[1],
    P_world_out: &this->coords_world);
}

//------------------------------------------------------------------------------
// Address: 0x1008CC80
// Name: public: virtual char const __near * IVP_Actuator::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Actuator::get_controller_name(IVP_Actuator *this)
{
  return "sys:actuator";
}

//------------------------------------------------------------------------------
// Address: 0x1008CC90
// Name: public: IVP_Actuator_Two_Point::IVP_Actuator_Two_Point(class IVP_Environment __near *,class IVP_Template_Two_Point __near *,enum IVP_ACTUATOR_TYPE)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Two_Point *__thiscall IVP_Actuator_Two_Point::IVP_Actuator_Two_Point(
        IVP_Actuator_Two_Point *this,
        IVP_Environment *env,
        IVP_Core *two_point_templ,
        IVP_ACTUATOR_TYPE __formal)
{
  IVP_Core *physical_core; // eax
  IVP_Core *v6; // ebx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  IVP_Core *core0; // [esp+18h] [ebp+Ch]

  *(_DWORD *)&this->actuator_controlled_cores.memsize = 0;
  this->actuator_controlled_cores.elems = nullptr;
  this->__vftable = (IVP_Actuator_Two_Point_vtbl *)&IVP_Actuator_Two_Point::`vftable';
  this->client_data = (void *)two_point_templ->IVP_Core_Fast_Static;
  IVP_Anchor::init_anchor(
    this: this->anchors,
    a2: COERCE_FLOAT(&savedregs),
    ac: this,
    ta: (IVP_Template_Anchor *)LODWORD(two_point_templ->upper_limit_radius));
  IVP_Anchor::init_anchor(
    this: &this->anchors[1],
    a2: COERCE_FLOAT(&savedregs),
    ac: this,
    ta: (IVP_Template_Anchor *)LODWORD(two_point_templ->max_surface_deviation));
  physical_core = this->anchors[0].l_anchor_object->physical_core;
  v6 = this->anchors[1].l_anchor_object->physical_core;
  core0 = physical_core;
  if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) == 0 )
  {
    if ( this->actuator_controlled_cores.n_elems >= this->actuator_controlled_cores.memsize )
    {
      IVP_U_Vector_Base::increment_mem(this: &this->actuator_controlled_cores);
      physical_core = core0;
    }
    this->actuator_controlled_cores.elems[this->actuator_controlled_cores.n_elems++] = physical_core;
  }
  if ( (*(_BYTE *)&v6->IVP_Core_Fast_Static & 2) == 0 && v6 != physical_core )
  {
    if ( this->actuator_controlled_cores.n_elems >= this->actuator_controlled_cores.memsize )
    {
      IVP_U_Vector_Base::increment_mem(this: &this->actuator_controlled_cores);
      physical_core = core0;
    }
    this->actuator_controlled_cores.elems[this->actuator_controlled_cores.n_elems++] = v6;
  }
  IVP_Controller_Manager::announce_controller_to_environment(
    this: physical_core->environment->controller_manager,
    cntrl: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008CD50
// Name: public: virtual IVP_Actuator_Two_Point::~IVP_Actuator_Two_Point(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Two_Point::~IVP_Actuator_Two_Point(IVP_Actuator_Two_Point *this)
{
  IVP_Anchor *p_client_data; // esi
  int i; // ebx
  IVP_Real_Object *l_anchor_object; // ecx
  IVP_Actuator_Two_Point *elems; // eax

  this->__vftable = (IVP_Actuator_Two_Point_vtbl *)&IVP_Actuator_Two_Point::`vftable';
  IVP_Controller_Manager::remove_controller_from_environment(cntrl: this, silently: IVP_TRUE);
  p_client_data = (IVP_Anchor *)&this->client_data;
  for ( i = 1; i >= 0; --i )
  {
    l_anchor_object = p_client_data[-1].l_anchor_object;
    IVP_Real_Object::remove_anchor(this: l_anchor_object, destroy_anch: --p_client_data);
  }
  this->__vftable = (IVP_Actuator_Two_Point_vtbl *)&IVP_Actuator::`vftable';
  elems = (IVP_Actuator_Two_Point *)this->actuator_controlled_cores.elems;
  if ( elems != &this->IVP_Actuator + 1 )
  {
    if ( elems != nullptr )
      free(data: this->actuator_controlled_cores.elems);
    this->actuator_controlled_cores.elems = nullptr;
    this->actuator_controlled_cores.memsize = 0;
  }
  this->actuator_controlled_cores.n_elems = 0;
  this->__vftable = (IVP_Actuator_Two_Point_vtbl *)&IVP_Controller_Dependent::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1008CDC0
// Name: public: IVP_Actuator_Four_Point::IVP_Actuator_Four_Point(class IVP_Environment __near *,class IVP_Template_Four_Point __near *,enum IVP_ACTUATOR_TYPE)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Four_Point *__thiscall IVP_Actuator_Four_Point::IVP_Actuator_Four_Point(
        IVP_Actuator_Four_Point *this,
        IVP_Environment *env,
        IVP_Template_Four_Point *four_point_templ,
        IVP_ACTUATOR_TYPE __formal)
{
  IVP_Anchor *anchors; // ebx
  IVP_Core *physical_core; // ebx
  int v7; // eax
  void **v8; // ecx
  int v10; // [esp+Ch] [ebp-8h]
  IVP_Template_Anchor **v11; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  IVP_Anchor *four_point_templa; // [esp+20h] [ebp+Ch]

  *(_DWORD *)&this->actuator_controlled_cores.memsize = 0;
  this->actuator_controlled_cores.elems = nullptr;
  this->__vftable = (IVP_Actuator_Four_Point_vtbl *)&IVP_Actuator_Four_Point::`vftable';
  anchors = this->anchors;
  this->client_data = four_point_templ->client_data;
  v11 = four_point_templ->anchors;
  four_point_templa = this->anchors;
  v10 = 4;
  while ( 1 )
  {
    IVP_Anchor::init_anchor(this: anchors, a2: COERCE_FLOAT(&savedregs), ac: this, ta: *v11);
    physical_core = anchors->l_anchor_object->physical_core;
    if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) != 0 )
    {
      v7 = this->actuator_controlled_cores.n_elems - 1;
      if ( this->actuator_controlled_cores.n_elems != 0 )
      {
        v8 = &this->actuator_controlled_cores.elems[v7];
        do
        {
          if ( *v8 == physical_core )
            break;
          --v8;
          --v7;
        }
        while ( v7 >= 0 );
      }
      if ( v7 == -1 )
      {
        if ( this->actuator_controlled_cores.n_elems >= this->actuator_controlled_cores.memsize )
          IVP_U_Vector_Base::increment_mem(this: &this->actuator_controlled_cores);
        this->actuator_controlled_cores.elems[this->actuator_controlled_cores.n_elems++] = physical_core;
      }
    }
    ++four_point_templa;
    ++v11;
    if ( --v10 == 0 )
      break;
    anchors = four_point_templa;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008CE80
// Name: public: virtual IVP_Actuator_Four_Point::~IVP_Actuator_Four_Point(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Four_Point::~IVP_Actuator_Four_Point(IVP_Actuator_Four_Point *this)
{
  IVP_Anchor *p_client_data; // esi
  int i; // ebx
  IVP_Real_Object *l_anchor_object; // ecx
  IVP_Actuator_Four_Point *elems; // eax

  this->__vftable = (IVP_Actuator_Four_Point_vtbl *)&IVP_Actuator_Four_Point::`vftable';
  IVP_Controller_Manager::remove_controller_from_environment(cntrl: this, silently: IVP_TRUE);
  p_client_data = (IVP_Anchor *)&this->client_data;
  for ( i = 3; i >= 0; --i )
  {
    l_anchor_object = p_client_data[-1].l_anchor_object;
    IVP_Real_Object::remove_anchor(this: l_anchor_object, destroy_anch: --p_client_data);
  }
  this->__vftable = (IVP_Actuator_Four_Point_vtbl *)&IVP_Actuator::`vftable';
  elems = (IVP_Actuator_Four_Point *)this->actuator_controlled_cores.elems;
  if ( elems != &this->IVP_Actuator + 1 )
  {
    if ( elems != nullptr )
      free(data: this->actuator_controlled_cores.elems);
    this->actuator_controlled_cores.elems = nullptr;
    this->actuator_controlled_cores.memsize = 0;
  }
  this->actuator_controlled_cores.n_elems = 0;
  this->__vftable = (IVP_Actuator_Four_Point_vtbl *)&IVP_Controller_Dependent::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1008CEF0
// Name: protected: IVP_Actuator_Force::IVP_Actuator_Force(class IVP_Environment __near *,class IVP_Template_Force __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Force *__thiscall IVP_Actuator_Force::IVP_Actuator_Force(
        IVP_Actuator_Force *this,
        IVP_Environment *env,
        IVP_Core *templ)
{
  IVP_Actuator_Two_Point::IVP_Actuator_Two_Point(this, env, two_point_templ: templ, __formal: IVP_ACTUATOR_TYPE_FORCE);
  this->__vftable = (IVP_Actuator_Force_vtbl *)&IVP_Actuator_Force::`vftable';
  this->force = *(float *)&templ->environment;
  *((_DWORD *)this + 41) ^= (*((_DWORD *)this + 41) ^ LODWORD(templ->rot_inertia.k[1])) & 1;
  *((_DWORD *)this + 41) ^= ((unsigned __int8)*((_DWORD *)this + 41)
                           ^ (unsigned __int8)(2 * LODWORD(templ->rot_inertia.k[2])))
                          & 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008CF50
// Name: public: virtual char const __near * IVP_Actuator_Force::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Actuator_Force::get_controller_name(IVP_Actuator_Force *this)
{
  return "sys:force_actuator";
}

//------------------------------------------------------------------------------
// Address: 0x1008CF70
// Name: protected: IVP_Actuator_Torque::IVP_Actuator_Torque(class IVP_Environment __near *,class IVP_Template_Torque __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Torque *__thiscall IVP_Actuator_Torque::IVP_Actuator_Torque(
        IVP_Actuator_Torque *this,
        IVP_Environment *env,
        IVP_Core *templ)
{
  IVP_U_Active_Terminal_Double *hesse_val_low; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4

  IVP_Actuator_Two_Point::IVP_Actuator_Two_Point(this, env, two_point_templ: templ, __formal: IVP_ACTUATOR_TYPE_TORQUE);
  this->__vftable = (IVP_Actuator_Torque_vtbl *)&IVP_Actuator_Torque::`vftable';
  this->max_rotation_speed = templ->rot_inertia.k[1];
  this->rot_speed_out = 0.0;
  hesse_val_low = (IVP_U_Active_Terminal_Double *)LODWORD(templ->rot_inertia.hesse_val);
  this->active_float_rotation_speed_out = hesse_val_low;
  if ( hesse_val_low != nullptr )
    ++hesse_val_low->reference_count;
  if ( this->anchors[0].l_anchor_object->original_core != this->anchors[1].l_anchor_object->original_core )
  {
    printf(format: "Both Anchors of a Torque_Actuator must be attached to just one object.\n");
    _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_controller\\ivp_actuator.cxx", 641);
  }
  v5 = this->anchors[1].core_pos.k[1] - this->anchors[0].core_pos.k[1];
  v6 = this->anchors[1].core_pos.k[2] - this->anchors[0].core_pos.k[2];
  this->axis_in_core_coord_system.k[0] = this->anchors[1].core_pos.k[0] - this->anchors[0].core_pos.k[0];
  this->axis_in_core_coord_system.k[1] = v5;
  this->axis_in_core_coord_system.k[2] = v6;
  IVP_U_Float_Point::fast_normize(this: &this->axis_in_core_coord_system);
  v7 = *(float *)&templ->environment;
  this->torque = v7;
  if ( v7 != 0.0 )
    IVP_Controller_Manager::ensure_controller_in_simulation(
      this: this->anchors[0].l_anchor_object->environment->controller_manager,
      cntrl: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008D050
// Name: protected: virtual char const __near * IVP_Actuator_Torque::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Actuator_Torque::get_controller_name(IVP_Actuator_Torque *this)
{
  return "sys:torque_actuator";
}

//------------------------------------------------------------------------------
// Address: 0x1008D060
// Name: protected: IVP_Actuator_Stabilizer::IVP_Actuator_Stabilizer(class IVP_Environment __near *,class IVP_Template_Stabilizer __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Stabilizer *__thiscall IVP_Actuator_Stabilizer::IVP_Actuator_Stabilizer(
        IVP_Actuator_Stabilizer *this,
        IVP_Environment *env,
        IVP_Template_Stabilizer *templ)
{
  IVP_Actuator_Four_Point::IVP_Actuator_Four_Point(
    this,
    env,
    four_point_templ: templ,
    __formal: IVP_ACTUATOR_TYPE_STABILIZER);
  this->__vftable = (IVP_Actuator_Stabilizer_vtbl *)&IVP_Actuator_Stabilizer::`vftable';
  this->stabi_constant = templ->stabi_constant;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008D090
// Name: protected: virtual char const __near * IVP_Actuator_Stabilizer::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Actuator_Stabilizer::get_controller_name(IVP_Actuator_Stabilizer *this)
{
  return "sys:stabilizer";
}

//------------------------------------------------------------------------------
// Address: 0x1008D190
// Name: protected: IVP_Actuator_Force_Active::IVP_Actuator_Force_Active(class IVP_Environment __near *,class IVP_Template_Force __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Force_Active *__thiscall IVP_Actuator_Force_Active::IVP_Actuator_Force_Active(
        IVP_Actuator_Force_Active *this,
        IVP_Environment *env,
        IVP_Core *templ)
{
  IVP_U_Active_Float *v4; // ecx
  float double_value; // xmm0_4

  IVP_Actuator_Two_Point::IVP_Actuator_Two_Point(this, env, two_point_templ: templ, __formal: IVP_ACTUATOR_TYPE_FORCE);
  this->IVP_Actuator_Force::IVP_Actuator_Two_Point::IVP_Actuator::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Actuator_Force_Active_vtbl *)&IVP_Actuator_Force::`vftable';
  this->force = *(float *)&templ->environment;
  *((_DWORD *)&this->IVP_Actuator_Force + 41) ^= (*((_DWORD *)&this->IVP_Actuator_Force + 41)
                                                ^ LODWORD(templ->rot_inertia.k[1]))
                                               & 1;
  *((_DWORD *)&this->IVP_Actuator_Force + 41) ^= ((unsigned __int8)*((_DWORD *)&this->IVP_Actuator_Force + 41)
                                                ^ (unsigned __int8)(2 * LODWORD(templ->rot_inertia.k[2])))
                                               & 2;
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
  this->IVP_Actuator_Force::IVP_Actuator_Two_Point::IVP_Actuator::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Actuator_Force_Active_vtbl *)&IVP_Actuator_Force_Active::`vftable'{for `IVP_Actuator_Force'};
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_Actuator_Force_Active::`vftable'{for `IVP_U_Active_Float_Listener'};
  v4 = (IVP_U_Active_Float *)LODWORD(templ->rot_inertia.k[0]);
  this->active_float_force = v4;
  if ( v4 != nullptr )
  {
    IVP_U_Active_Float::add_dependency(this: v4, derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
    double_value = this->active_float_force->double_value;
    if ( double_value != this->force )
    {
      this->force = double_value;
      IVP_Controller_Manager::ensure_controller_in_simulation(
        this: this->anchors[0].l_anchor_object->environment->controller_manager,
        cntrl: this);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008D2F0
// Name: public: IVP_Actuator_Torque_Active::IVP_Actuator_Torque_Active(class IVP_Environment __near *,class IVP_Template_Torque __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Actuator_Torque_Active *__thiscall IVP_Actuator_Torque_Active::IVP_Actuator_Torque_Active(
        IVP_Actuator_Torque_Active *this,
        IVP_Environment *env,
        IVP_Core *templ)
{
  IVP_U_Active_Float *v4; // ecx
  float double_value; // xmm0_4
  IVP_U_Active_Float *v6; // ecx
  float v7; // xmm0_4

  IVP_Actuator_Torque::IVP_Actuator_Torque(this, env, templ);
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
  this->IVP_Actuator_Torque::IVP_Actuator_Two_Point::IVP_Actuator::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Actuator_Torque_Active_vtbl *)&IVP_Actuator_Torque_Active::`vftable'{for `IVP_Actuator_Torque'};
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_Actuator_Torque_Active::`vftable'{for `IVP_U_Active_Float_Listener'};
  v4 = (IVP_U_Active_Float *)LODWORD(templ->rot_inertia.k[2]);
  this->active_float_max_rotation_speed = v4;
  if ( v4 != nullptr )
  {
    IVP_U_Active_Float::add_dependency(this: v4, derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
    double_value = this->active_float_max_rotation_speed->double_value;
    if ( double_value != this->max_rotation_speed )
    {
      this->max_rotation_speed = double_value;
      IVP_Controller_Manager::ensure_controller_in_simulation(
        this: this->anchors[0].l_anchor_object->environment->controller_manager,
        cntrl: this);
    }
  }
  v6 = (IVP_U_Active_Float *)LODWORD(templ->rot_inertia.k[0]);
  this->active_float_torque = v6;
  if ( v6 != nullptr )
  {
    IVP_U_Active_Float::add_dependency(this: v6, derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
    v7 = this->active_float_torque->double_value;
    if ( v7 != this->torque )
    {
      this->torque = v7;
      IVP_Controller_Manager::ensure_controller_in_simulation(
        this: this->anchors[0].l_anchor_object->environment->controller_manager,
        cntrl: this);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008D3C0
// Name: public: virtual IVP_Actuator_Torque_Active::~IVP_Actuator_Torque_Active(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Actuator_Torque_Active::~IVP_Actuator_Torque_Active(IVP_Actuator_Torque_Active *this)
{
  IVP_U_Active_Float *active_float_max_rotation_speed; // ecx
  IVP_U_Active_Float *active_float_torque; // ecx
  IVP_U_Active_Terminal_Double *active_float_rotation_speed_out; // ecx

  active_float_max_rotation_speed = this->active_float_max_rotation_speed;
  this->IVP_Actuator_Torque::IVP_Actuator_Two_Point::IVP_Actuator::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Actuator_Torque_Active_vtbl *)&IVP_Actuator_Torque_Active::`vftable'{for `IVP_Actuator_Torque'};
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_Actuator_Torque_Active::`vftable'{for `IVP_U_Active_Float_Listener'};
  if ( active_float_max_rotation_speed != nullptr )
    IVP_U_Active_Float::remove_dependency(
      this: active_float_max_rotation_speed,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
  active_float_torque = this->active_float_torque;
  if ( active_float_torque != nullptr )
    IVP_U_Active_Float::remove_dependency(
      this: active_float_torque,
      derived_active_IVP_FLOAT: &this->IVP_U_Active_Float_Listener);
  active_float_rotation_speed_out = this->active_float_rotation_speed_out;
  this->IVP_U_Active_Float_Listener::__vftable = (IVP_U_Active_Float_Listener_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
  this->IVP_Actuator_Torque::IVP_Actuator_Two_Point::IVP_Actuator::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Actuator_Torque_Active_vtbl *)&IVP_Actuator_Torque::`vftable';
  if ( active_float_rotation_speed_out != nullptr && active_float_rotation_speed_out->reference_count-- == 1 )
    ((void (__thiscall *)(IVP_U_Active_Terminal_Double *, int))active_float_rotation_speed_out->dtr_IVP_U_Active_Value)(
      a1: active_float_rotation_speed_out,
      a2: 1);
  IVP_Actuator_Two_Point::~IVP_Actuator_Two_Point(this);
}
