// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_sim_unit.cxx
// Functions: 34
// ============================================================

#include "ivp\ivp_intern\ivp_sim_unit.h"

//------------------------------------------------------------------------------
// Address: 0x10075F50
// Name: public: static void IVP_Simulation_Unit::prefetch0_init_moving_core_for_psi(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Simulation_Unit::prefetch0_init_moving_core_for_psi(IVP_Core *core)
{
  _mm_prefetch((const char *)&core->m_world_f_core_last_psi, 2);
  _mm_prefetch((const char *)&core->m_world_f_core_last_psi.rows[2], 2);
  _mm_prefetch((const char *)&core->rot_speed_change, 2);
  _mm_prefetch((const char *)&core->rot_speed, 2);
}

//------------------------------------------------------------------------------
// Address: 0x10075F80
// Name: public: void IVP_Controller_Manager::ensure_core_in_simulation(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Manager::ensure_core_in_simulation(IVP_Controller_Manager *this, IVP_Core *core)
{
  IVP_Environment::add_revive_core(this: core->environment, c: core);
}

//------------------------------------------------------------------------------
// Address: 0x10075FA0
// Name: public: IVP_Sim_Units_Manager::IVP_Sim_Units_Manager(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Sim_Units_Manager *__thiscall IVP_Sim_Units_Manager::IVP_Sim_Units_Manager(
        IVP_Sim_Units_Manager *this,
        IVP_Environment *env)
{
  this->l_environment = env;
  this->sim_units_slots[0] = nullptr;
  this->still_slot = nullptr;
  this->nb.seconds = 9.729999542236328;
  this->bt.seconds = 0.300000011920929;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10075FF0
// Name: public: void IVP_Sim_Units_Manager::add_sim_unit_to_manager(class IVP_Simulation_Unit __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Sim_Units_Manager::add_sim_unit_to_manager(IVP_Sim_Units_Manager *this, IVP_Simulation_Unit *sim_u)
{
  IVP_Simulation_Unit **sim_units_slots; // edx
  IVP_Simulation_Unit *v3; // ecx

  sim_units_slots = this->sim_units_slots;
  if ( *(_BYTE *)sim_u >= 8 )
    sim_units_slots = &this->still_slot;
  v3 = *sim_units_slots;
  sim_u->next_sim_unit = *sim_units_slots;
  if ( v3 != nullptr )
    v3->prev_sim_unit = sim_u;
  sim_u->prev_sim_unit = nullptr;
  *sim_units_slots = sim_u;
}

//------------------------------------------------------------------------------
// Address: 0x10076020
// Name: public: void IVP_Standard_Gravity_Controller::set_standard_gravity(class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Standard_Gravity_Controller::set_standard_gravity(
        IVP_Standard_Gravity_Controller *this,
        IVP_U_Point *gravity)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = gravity->k[1];
  v3 = gravity->k[2];
  this->grav_vec.k[0] = gravity->k[0];
  this->grav_vec.k[1] = v2;
  this->grav_vec.k[2] = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10076050
// Name: public: void IVP_Standard_Gravity_Controller::set_alternate_gravity(class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Standard_Gravity_Controller::set_alternate_gravity(
        IVP_Standard_Gravity_Controller *this,
        IVP_U_Point *new_gravity)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = new_gravity->k[1];
  v3 = new_gravity->k[2];
  this->alt_grav_vec.k[0] = new_gravity->k[0];
  this->alt_grav_vec.k[1] = v2;
  this->alt_grav_vec.k[2] = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100760D0
// Name: public: class IVP_Core __near * IVP_Simulation_Unit::sim_unit_union_find_test(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Core *__thiscall IVP_Simulation_Unit::sim_unit_union_find_test(IVP_Simulation_Unit *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // esi
  IVP_Core *father; // eax
  IVP_Core *v8; // edi
  int v9; // esi
  IVP_Core *result; // eax
  IVP_Core *father_core; // [esp+Ch] [ebp-8h]
  int i2; // [esp+10h] [ebp-4h]

  v2 = this->sim_unit_cores.n_elems - 1;
  if ( this->sim_unit_cores.n_elems != 0 )
  {
    do
      *((_DWORD *)this->sim_unit_cores.elems[v2--] + 106) = 0;
    while ( v2 >= 0 );
  }
  v3 = this->controller_cores.n_elems - 1;
  i2 = v3;
  if ( this->controller_cores.n_elems != 0 )
  {
    while ( 1 )
    {
      v4 = *(_DWORD *)this->controller_cores.elems[v3];
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
      v6 = *(unsigned __int16 *)(v5 + 2) - 1;
      if ( *(_WORD *)(v5 + 2) != 0 )
      {
        father_core = IVP_Core::union_find_get_father(this: **(IVP_Core ***)(v5 + 4));
        do
        {
          father = IVP_Core::union_find_get_father(this: *(IVP_Core **)(*(_DWORD *)(v5 + 4) + 4 * v6));
          if ( father_core != father )
            father->tmp.union_find_father = father_core;
          --v6;
        }
        while ( v6 >= 0 );
      }
      if ( --i2 < 0 )
        break;
      v3 = i2;
    }
  }
  v8 = IVP_Core::union_find_get_father(this: *(IVP_Core **)this->sim_unit_cores.elems);
  v9 = 0;
  if ( this->sim_unit_cores.n_elems == 0 )
    return nullptr;
  while ( 1 )
  {
    result = IVP_Core::union_find_get_father(this: (IVP_Core *)this->sim_unit_cores.elems[v9]);
    if ( result != v8 )
      break;
    if ( ++v9 >= this->sim_unit_cores.n_elems )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100761A0
// Name: public: void IVP_Simulation_Unit::sim_unit_revive_for_simulation(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::sim_unit_revive_for_simulation(IVP_Simulation_Unit *this, IVP_Environment *env)
{
  int n_elems; // esi
  IVP_Core *v4; // ecx
  IVP_Simulation_Unit *prev_sim_unit; // eax
  IVP_Simulation_Unit *next_sim_unit; // ecx
  IVP_Sim_Units_Manager *sim_units_manager; // eax
  IVP_Simulation_Unit **sim_units_slots; // ecx
  IVP_Simulation_Unit *v9; // eax

revive_all_cores:
  n_elems = this->sim_unit_cores.n_elems;
  while ( --n_elems >= 0 )
  {
    v4 = (IVP_Core *)this->sim_unit_cores.elems[n_elems];
    if ( *((_BYTE *)&v4->IVP_Core_Fast_Static + 1) >= 8u && IVP_Core::revive_simulation_core(this: v4) == IVP_TRUE )
      goto revive_all_cores;
  }
  if ( *(_BYTE *)this == 8 )
  {
    prev_sim_unit = this->prev_sim_unit;
    next_sim_unit = this->next_sim_unit;
    if ( prev_sim_unit != nullptr )
      prev_sim_unit->next_sim_unit = next_sim_unit;
    else
      env->sim_units_manager->still_slot = next_sim_unit;
    if ( next_sim_unit != nullptr )
      next_sim_unit->prev_sim_unit = prev_sim_unit;
    *(_BYTE *)this = 1;
    sim_units_manager = env->sim_units_manager;
    sim_units_slots = sim_units_manager->sim_units_slots;
    if ( *(_BYTE *)this >= 8 )
      sim_units_slots = &sim_units_manager->still_slot;
    v9 = *sim_units_slots;
    this->next_sim_unit = *sim_units_slots;
    if ( v9 != nullptr )
      v9->prev_sim_unit = this;
    this->prev_sim_unit = nullptr;
    *sim_units_slots = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076230
// Name: public: void IVP_Simulation_Unit::sim_unit_ensure_cores_movement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::sim_unit_ensure_cores_movement(IVP_Simulation_Unit *this)
{
  int v2; // esi

  v2 = this->sim_unit_cores.n_elems - 1;
  if ( this->sim_unit_cores.n_elems != 0 )
  {
    do
      IVP_Core::reset_freeze_check_values(this: (IVP_Core *)this->sim_unit_cores.elems[v2--]);
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076260
// Name: public: virtual void IVP_Standard_Gravity_Controller::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Standard_Gravity_Controller::do_simulation_controller(
        IVP_Standard_Gravity_Controller *this,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *core_list)
{
  int v3; // ebx
  void **elems; // edx
  IVP_Core *v6; // esi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v3 = core_list->n_elems - 1;
  if ( core_list->n_elems != 0 )
  {
    do
    {
      elems = core_list->elems;
      v6 = (IVP_Core *)elems[v3];
      if ( (*(_BYTE *)&v6->IVP_Core_Fast_Static & 0x10) == 0 )
      {
        IVP_Core::global_damp_core(
          this: (IVP_Core *)elems[v3],
          a2: COERCE_FLOAT(&savedregs),
          a3: (int)v6,
          d_time: es->delta_time);
        IVP_Core::commit_all_async_pushes(this: v6);
        if ( (*(_BYTE *)&v6->IVP_Core_Fast_Static & 0x20) != 0 )
        {
          v7 = (float)(this->alt_grav_vec.k[1] * es->delta_time) + v6->speed.k[1];
          v8 = (float)(this->alt_grav_vec.k[2] * es->delta_time) + v6->speed.k[2];
          v6->speed.k[0] = (float)(es->delta_time * this->alt_grav_vec.k[0]) + v6->speed.k[0];
          v6->speed.k[1] = v7;
          v6->speed.k[2] = v8;
        }
        else
        {
          v9 = (float)(this->grav_vec.k[1] * es->delta_time) + v6->speed.k[1];
          v10 = (float)(this->grav_vec.k[2] * es->delta_time) + v6->speed.k[2];
          v6->speed.k[0] = (float)(this->grav_vec.k[0] * es->delta_time) + v6->speed.k[0];
          v6->speed.k[1] = v9;
          v6->speed.k[2] = v10;
        }
      }
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076360
// Name: public: enum IVP_BOOL IVP_Simulation_Unit::sim_unit_calc_movement_state(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Simulation_Unit::sim_unit_calc_movement_state(IVP_Simulation_Unit *this, IVP_Environment *env)
{
  IVP_Environment *v2; // ebx
  int v4; // edi
  IVP_Core *v5; // ebx
  char v6; // al
  int v7; // edi
  IVP_Sim_Units_Manager *sim_units_manager; // eax
  IVP_Simulation_Unit **sim_units_slots; // edx
  IVP_Simulation_Unit *prev_sim_unit; // ecx
  IVP_Simulation_Unit *next_sim_unit; // eax
  IVP_Sim_Units_Manager *v12; // eax
  IVP_Simulation_Unit **p_still_slot; // ecx
  IVP_Simulation_Unit *v14; // eax
  IVP_Time current_time; // [esp+Ch] [ebp-Ch]
  IVP_Movement_Type whole_sys; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v2 = env;
  v4 = this->sim_unit_cores.n_elems - 1;
  LOBYTE(whole_sys) = 3;
  current_time.seconds = env->current_time.seconds;
  if ( this->sim_unit_cores.n_elems != 0 )
  {
    do
    {
      v5 = (IVP_Core *)this->sim_unit_cores.elems[v4];
      v6 = IVP_Core::calc_movement_state(this: v5, a2: (int)&savedregs, psi_time: current_time);
      whole_sys = (unsigned __int8)(v6 & whole_sys);
      --v4;
      *((_BYTE *)&v5->IVP_Core_Fast_Static + 1) = v6;
    }
    while ( v4 >= 0 );
    if ( whole_sys != IVP_MT_CALM )
      return 0;
    v2 = env;
  }
  v7 = this->sim_unit_cores.n_elems - 1;
  if ( this->sim_unit_cores.n_elems != 0 )
  {
    do
      IVP_Core::freeze_simulation_core(this: (IVP_Core *)this->sim_unit_cores.elems[v7--]);
    while ( v7 >= 0 );
  }
  sim_units_manager = v2->sim_units_manager;
  sim_units_slots = sim_units_manager->sim_units_slots;
  if ( *(_BYTE *)this >= 8 )
    sim_units_slots = &sim_units_manager->still_slot;
  prev_sim_unit = this->prev_sim_unit;
  next_sim_unit = this->next_sim_unit;
  if ( prev_sim_unit != nullptr )
    prev_sim_unit->next_sim_unit = next_sim_unit;
  else
    *sim_units_slots = next_sim_unit;
  if ( next_sim_unit != nullptr )
    next_sim_unit->prev_sim_unit = prev_sim_unit;
  *(_BYTE *)this = 8;
  v12 = v2->sim_units_manager;
  p_still_slot = v12->sim_units_slots;
  if ( *(_BYTE *)this >= 8 )
    p_still_slot = &v12->still_slot;
  v14 = *p_still_slot;
  this->next_sim_unit = *p_still_slot;
  if ( v14 != nullptr )
    v14->prev_sim_unit = this;
  this->prev_sim_unit = nullptr;
  *p_still_slot = this;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10076440
// Name: public: void IVP_Sim_Units_Manager::reset_time(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Sim_Units_Manager::reset_time(IVP_Sim_Units_Manager *this, IVP_Time offset)
{
  IVP_Simulation_Unit *i; // esi
  int v3; // edi
  int v4; // ecx
  int v5; // edi

  for ( i = this->sim_units_slots[0]; i != nullptr; i = i->next_sim_unit )
  {
    v3 = i->controller_cores.n_elems - 1;
    if ( i->controller_cores.n_elems != 0 )
    {
      do
      {
        v4 = *(_DWORD *)i->controller_cores.elems[v3];
        (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 12))(
          a1: v4,
          a2: LODWORD(offset.seconds),
          a3: HIDWORD(offset.seconds));
        --v3;
      }
      while ( v3 >= 0 );
    }
    v5 = i->sim_unit_cores.n_elems - 1;
    if ( i->sim_unit_cores.n_elems != 0 )
    {
      do
        IVP_Core::reset_time(this: (IVP_Core *)i->sim_unit_cores.elems[v5--], offset);
      while ( v5 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100764B0
// Name: public: IVP_Simulation_Unit::IVP_Simulation_Unit(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Simulation_Unit *__thiscall IVP_Simulation_Unit::IVP_Simulation_Unit(IVP_Simulation_Unit *this)
{
  *(_DWORD *)&this->sim_unit_cores.memsize = 2;
  this->sim_unit_cores.elems = (void **)this->sim_unit_cores.elem_buffer;
  *(_DWORD *)&this->controller_cores.memsize = 0;
  this->controller_cores.elems = nullptr;
  *(_DWORD *)this &= 0xFFFFFCFF;
  *(_BYTE *)this = 8;
  *(_DWORD *)this &= 0xFFFFC3FF;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10076510
// Name: public: void IVP_Controller_Manager::ensure_controller_in_simulation(class IVP_Controller_Dependent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Manager::ensure_controller_in_simulation(
        IVP_Controller_Manager *this,
        IVP_Controller_Dependent *cntrl)
{
  IVP_U_Vector<IVP_Core> *v2; // eax
  IVP_Simulation_Unit *v3; // edi
  int v4; // esi

  v2 = cntrl->get_associated_controlled_cores(this: cntrl);
  if ( v2->n_elems != 0 )
  {
    v3 = *((IVP_Simulation_Unit **)*v2->elems + 83);
    if ( *(_BYTE *)v3 < 8 )
    {
      v4 = v3->sim_unit_cores.n_elems - 1;
      if ( v3->sim_unit_cores.n_elems != 0 )
      {
        do
          IVP_Core::reset_freeze_check_values(this: (IVP_Core *)v3->sim_unit_cores.elems[v4--]);
        while ( v4 >= 0 );
      }
    }
    else
    {
      IVP_Simulation_Unit::sim_unit_revive_for_simulation(
        this: v3,
        env: *((IVP_Environment **)*v3->sim_unit_cores.elems + 3));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076570
// Name: public: void IVP_Simulation_Unit::sim_unit_sort_controllers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::sim_unit_sort_controllers(IVP_Simulation_Unit *this)
{
  int v2; // esi
  int v3; // ebx
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  void **elems; // eax
  void *v8; // ecx
  int v9; // ecx
  void **v10; // eax
  void *v11; // ecx
  int contr_num; // [esp+Ch] [ebp-8h]
  IVP_CONTROLLER_PRIORITY second_prio; // [esp+10h] [ebp-4h]

  v2 = 0;
  v3 = 1;
  contr_num = this->controller_cores.n_elems;
  if ( (unsigned int)contr_num > 1 )
  {
    do
    {
      v4 = *(_DWORD *)this->controller_cores.elems[v3];
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 20))(a1: v4);
      v6 = *(_DWORD *)this->controller_cores.elems[v2];
      second_prio = v5;
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 20))(a1: v6) > v5 )
      {
        elems = this->controller_cores.elems;
        v8 = elems[v2];
        elems[v2] = elems[v3];
        for ( this->controller_cores.elems[v3] = v8; v2 > 0; this->controller_cores.elems[v2--] = v11 )
        {
          v9 = *(_DWORD *)this->controller_cores.elems[v2 - 1];
          if ( (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 20))(a1: v9) <= second_prio )
            break;
          v10 = this->controller_cores.elems;
          v11 = v10[v2 - 1];
          v10[v2 - 1] = v10[v2];
        }
      }
      v2 = v3++;
    }
    while ( v3 < contr_num );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076610
// Name: public: void IVP_Simulation_Unit::throw_cores_into_my_sim_unit(class IVP_Simulation_Unit __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::throw_cores_into_my_sim_unit(
        IVP_Simulation_Unit *this,
        IVP_Simulation_Unit *second_unit)
{
  IVP_Simulation_Unit *v2; // eax
  int v3; // edx
  int v4; // ebx
  IVP_Vector_of_Cores_2 *p_sim_unit_cores; // esi
  _DWORD *v6; // edi
  int v7; // edx
  IVP_Simulation_Unit **v8; // edx
  IVP_Simulation_Unit *prev_sim_unit; // ecx
  IVP_Simulation_Unit *next_sim_unit; // eax

  v2 = second_unit;
  v3 = 0;
  v4 = 0;
  if ( second_unit->sim_unit_cores.n_elems != 0 )
  {
    p_sim_unit_cores = &this->sim_unit_cores;
    do
    {
      v6 = v2->sim_unit_cores.elems[v4];
      if ( p_sim_unit_cores->n_elems >= p_sim_unit_cores->memsize )
      {
        IVP_U_Vector_Base::increment_mem(this: p_sim_unit_cores);
        v2 = second_unit;
      }
      p_sim_unit_cores->elems[p_sim_unit_cores->n_elems++] = v6;
      v3 = v6[3];
      v6[83] = this;
      ++v4;
    }
    while ( v4 < v2->sim_unit_cores.n_elems );
  }
  v7 = *(_DWORD *)(v3 + 8);
  if ( *(_BYTE *)v2 >= 8 )
    v8 = (IVP_Simulation_Unit **)(v7 + 424);
  else
    v8 = (IVP_Simulation_Unit **)(v7 + 24);
  prev_sim_unit = v2->prev_sim_unit;
  next_sim_unit = v2->next_sim_unit;
  if ( prev_sim_unit != nullptr )
    prev_sim_unit->next_sim_unit = next_sim_unit;
  else
    *v8 = next_sim_unit;
  if ( next_sim_unit != nullptr )
    next_sim_unit->prev_sim_unit = prev_sim_unit;
}

//------------------------------------------------------------------------------
// Address: 0x100766A0
// Name: public: void IVP_Simulation_Unit::rem_sim_unit_controller(class IVP_Controller __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::rem_sim_unit_controller(IVP_Simulation_Unit *this, IVP_Controller *rem_controller)
{
  int v3; // esi
  IVP_Controller ***v4; // eax
  char *v5; // edi
  char *v6; // eax

  v3 = this->controller_cores.n_elems - 1;
  if ( this->controller_cores.n_elems != 0 )
  {
    v4 = (IVP_Controller ***)&this->controller_cores.elems[v3];
    do
    {
      if ( **v4 == rem_controller )
        break;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = (char *)this->controller_cores.elems[v3];
  if ( v5 != nullptr )
  {
    v6 = *((char **)v5 + 2);
    if ( v6 != v5 + 12 )
    {
      if ( v6 != nullptr )
        free(data: *((void **)v5 + 2));
      *((_DWORD *)v5 + 2) = 0;
      *((_WORD *)v5 + 2) = 0;
    }
    *((_WORD *)v5 + 3) = 0;
    free(data: v5);
  }
  IVP_U_Vector<IVP_Core>::remove_at(this: &this->controller_cores, index: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10076720
// Name: public: void IVP_Simulation_Unit::remove_controller_of_core(class IVP_Core __near *,class IVP_Controller __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::remove_controller_of_core(
        IVP_Simulation_Unit *this,
        IVP_Core *my_core,
        IVP_Controller *cntrl)
{
  IVP_Simulation_Unit *v3; // ebx
  int v4; // edi
  IVP_Controller ***v5; // eax
  _WORD *v6; // esi
  unsigned __int16 v7; // dx
  int v8; // eax
  IVP_Core **v9; // ecx
  char *v10; // eax

  v3 = this;
  v4 = this->controller_cores.n_elems - 1;
  if ( this->controller_cores.n_elems != 0 )
  {
    v5 = (IVP_Controller ***)&this->controller_cores.elems[v4];
    do
    {
      if ( **v5 == cntrl )
        break;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = this->controller_cores.elems[v4];
  v7 = v6[3];
  v8 = v7 - 1;
  if ( v7 != 0 )
  {
    v9 = (IVP_Core **)(*((_DWORD *)v6 + 2) + 4 * v8);
    do
    {
      if ( *v9 == my_core )
        break;
      --v9;
      --v8;
    }
    while ( v8 >= 0 );
    v3 = this;
  }
  for ( v6[3] = v7 - 1; v8 < (unsigned __int16)v6[3]; ++v8 )
    *(_DWORD *)(*((_DWORD *)v6 + 2) + 4 * v8) = *(_DWORD *)(*((_DWORD *)v6 + 2) + 4 * v8 + 4);
  if ( v6[3] == 0 )
  {
    v10 = *((char **)v6 + 2);
    if ( v10 != (char *)(v6 + 6) )
    {
      if ( v10 != nullptr )
        free(data: v10);
      *((_DWORD *)v6 + 2) = 0;
      v6[2] = 0;
    }
    v6[3] = 0;
    free(data: v6);
    IVP_U_Vector<IVP_Core>::remove_at(this: &v3->controller_cores, index: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100767F0
// Name: public: void IVP_Simulation_Unit::clean_sim_unit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::clean_sim_unit(IVP_Simulation_Unit *this)
{
  int v2; // edi
  char *v3; // esi
  char *v4; // eax
  void **elems; // eax

  v2 = this->controller_cores.n_elems - 1;
  if ( this->controller_cores.n_elems != 0 )
  {
    do
    {
      v3 = (char *)this->controller_cores.elems[v2];
      if ( v3 != nullptr )
      {
        v4 = *((char **)v3 + 2);
        if ( v4 != v3 + 12 )
        {
          if ( v4 != nullptr )
            free(data: *((void **)v3 + 2));
          *((_DWORD *)v3 + 2) = 0;
          *((_WORD *)v3 + 2) = 0;
        }
        *((_WORD *)v3 + 3) = 0;
        free(data: v3);
      }
      --v2;
    }
    while ( v2 >= 0 );
  }
  elems = this->controller_cores.elems;
  if ( elems == (void **)(this + 1) )
  {
    this->controller_cores.n_elems = 0;
  }
  else
  {
    if ( elems != nullptr )
      free(data: this->controller_cores.elems);
    this->controller_cores.elems = nullptr;
    *(_DWORD *)&this->controller_cores.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076870
// Name: public: IVP_Simulation_Unit::~IVP_Simulation_Unit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::~IVP_Simulation_Unit(IVP_Simulation_Unit *this)
{
  void **elems; // eax
  void **v3; // eax

  IVP_Simulation_Unit::clean_sim_unit(this);
  elems = this->controller_cores.elems;
  if ( elems != (void **)(this + 1) )
  {
    if ( elems != nullptr )
      free(data: this->controller_cores.elems);
    this->controller_cores.elems = nullptr;
    this->controller_cores.memsize = 0;
  }
  this->controller_cores.n_elems = 0;
  v3 = this->sim_unit_cores.elems;
  if ( v3 == (void **)this->sim_unit_cores.elem_buffer )
  {
    this->sim_unit_cores.n_elems = 0;
  }
  else
  {
    if ( v3 != nullptr )
      free(data: this->sim_unit_cores.elems);
    this->sim_unit_cores.elems = nullptr;
    *(_DWORD *)&this->sim_unit_cores.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100768D0
// Name: public: void IVP_Core::rem_core_controller(class IVP_Controller __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::rem_core_controller(IVP_Core *this, IVP_Controller *rem_cntrl)
{
  unsigned __int16 n_elems; // si
  int v3; // eax
  IVP_Controller **v4; // edx

  n_elems = this->controllers_of_core.n_elems;
  v3 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v4 = (IVP_Controller **)&this->controllers_of_core.elems[v3];
    do
    {
      if ( *v4 == rem_cntrl )
        break;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  for ( this->controllers_of_core.n_elems = n_elems - 1; v3 < this->controllers_of_core.n_elems; ++v3 )
    this->controllers_of_core.elems[v3] = this->controllers_of_core.elems[v3 + 1];
  IVP_Simulation_Unit::remove_controller_of_core(this: this->sim_unit_of_core, my_core: this, cntrl: rem_cntrl);
}

//------------------------------------------------------------------------------
// Address: 0x10076940
// Name: public: void IVP_Simulation_Unit::add_controller_of_core(class IVP_Core __near *,class IVP_Controller __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::add_controller_of_core(
        IVP_Simulation_Unit *this,
        IVP_Core *my_core,
        IVP_Controller *cntrl)
{
  int v4; // eax
  IVP_Controller ***v5; // ecx
  IVP_Controller *v6; // esi
  IVP_Controller **v7; // eax
  IVP_Controller **v8; // ebx
  int v9; // eax
  void **v10; // ecx
  char *v11; // esi

  v4 = this->controller_cores.n_elems - 1;
  if ( this->controller_cores.n_elems != 0 )
  {
    v5 = (IVP_Controller ***)&this->controller_cores.elems[v4];
    while ( 1 )
    {
      v6 = cntrl;
      if ( **v5 == cntrl )
        break;
      --v5;
      if ( --v4 < 0 )
        goto LABEL_7;
    }
  }
  else
  {
    v6 = cntrl;
LABEL_7:
    v7 = (IVP_Controller **)p_malloc(size: 0x14u);
    if ( v7 != nullptr )
    {
      v7[2] = (IVP_Controller *)(v7 + 3);
      v7[1] = (IVP_Controller *)2;
      v8 = v7;
    }
    else
    {
      v8 = nullptr;
    }
    *v8 = v6;
    if ( this->controller_cores.n_elems >= this->controller_cores.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->controller_cores);
    v6 = cntrl;
    this->controller_cores.elems[this->controller_cores.n_elems++] = v8;
  }
  v9 = this->controller_cores.n_elems - 1;
  if ( this->controller_cores.n_elems != 0 )
  {
    v10 = &this->controller_cores.elems[v9];
    do
    {
      if ( *(IVP_Controller **)*v10 == v6 )
        break;
      --v10;
      --v9;
    }
    while ( v9 >= 0 );
  }
  v11 = (char *)this->controller_cores.elems[v9];
  if ( *((_WORD *)v11 + 3) >= *((_WORD *)v11 + 2) )
    IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)(v11 + 4));
  *(_DWORD *)(*((_DWORD *)v11 + 2) + 4 * (unsigned __int16)(*((_WORD *)v11 + 3))++) = my_core;
  IVP_Simulation_Unit::sim_unit_sort_controllers(this);
}

//------------------------------------------------------------------------------
// Address: 0x10076A10
// Name: public: void IVP_Simulation_Unit::sim_unit_calc_redundants(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::sim_unit_calc_redundants(IVP_Simulation_Unit *this)
{
  int v2; // edx
  IVP_Core *v3; // ecx
  int v4; // eax
  void *v5; // esi
  int v6; // eax
  void **v7; // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int v10; // eax
  void **v11; // ecx
  char *v12; // esi
  int i; // [esp+8h] [ebp-Ch]
  IVP_Core *my_core; // [esp+Ch] [ebp-8h]
  int k; // [esp+10h] [ebp-4h]

  v2 = this->sim_unit_cores.n_elems - 1;
  i = v2;
  if ( this->sim_unit_cores.n_elems != 0 )
  {
    do
    {
      v3 = (IVP_Core *)this->sim_unit_cores.elems[v2];
      v4 = v3->controllers_of_core.n_elems - 1;
      my_core = v3;
      k = v4;
      if ( v3->controllers_of_core.n_elems != 0 )
      {
        while ( 1 )
        {
          v5 = v3->controllers_of_core.elems[v4];
          v6 = this->controller_cores.n_elems - 1;
          if ( this->controller_cores.n_elems != 0 )
          {
            v7 = &this->controller_cores.elems[v6];
            while ( *(void **)*v7 != v5 )
            {
              --v7;
              if ( --v6 < 0 )
                goto LABEL_9;
            }
          }
          else
          {
LABEL_9:
            v8 = p_malloc(size: 0x14u);
            if ( v8 != nullptr )
            {
              v8[2] = v8 + 3;
              v8[1] = 2;
              v9 = v8;
            }
            else
            {
              v9 = nullptr;
            }
            *v9 = v5;
            if ( this->controller_cores.n_elems >= this->controller_cores.memsize )
              IVP_U_Vector_Base::increment_mem(this: &this->controller_cores);
            this->controller_cores.elems[this->controller_cores.n_elems++] = v9;
          }
          v10 = this->controller_cores.n_elems - 1;
          if ( this->controller_cores.n_elems != 0 )
          {
            v11 = &this->controller_cores.elems[v10];
            do
            {
              if ( *(void **)*v11 == v5 )
                break;
              --v11;
              --v10;
            }
            while ( v10 >= 0 );
          }
          v12 = (char *)this->controller_cores.elems[v10];
          if ( *((_WORD *)v12 + 3) >= *((_WORD *)v12 + 2) )
            IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)(v12 + 4));
          *(_DWORD *)(*((_DWORD *)v12 + 2) + 4 * (unsigned __int16)(*((_WORD *)v12 + 3))++) = my_core;
          if ( --k < 0 )
            break;
          v4 = k;
          v3 = my_core;
        }
        v2 = i;
      }
      i = --v2;
    }
    while ( v2 >= 0 );
  }
  IVP_Simulation_Unit::sim_unit_sort_controllers(this);
}

//------------------------------------------------------------------------------
// Address: 0x10076B30
// Name: public: void IVP_Simulation_Unit::split_sim_unit(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::split_sim_unit(IVP_Simulation_Unit *this, IVP_Core *split_father)
{
  int v3; // ebx
  IVP_Simulation_Unit *v4; // eax
  IVP_Simulation_Unit *v5; // esi
  IVP_Sim_Units_Manager *sim_units_manager; // eax
  IVP_Simulation_Unit **sim_units_slots; // ecx
  IVP_Simulation_Unit *v8; // eax
  IVP_Core *father; // eax
  int i; // eax
  IVP_Core *my_core; // [esp+Ch] [ebp-10h]
  IVP_BOOL next_split_necessary; // [esp+10h] [ebp-Ch]
  IVP_Core *next_split_father; // [esp+14h] [ebp-8h]
  IVP_Simulation_Unit *split_new_unit; // [esp+18h] [ebp-4h]

  while ( 1 )
  {
    v3 = 0;
    next_split_father = nullptr;
    next_split_necessary = IVP_FALSE;
    v4 = (IVP_Simulation_Unit *)p_malloc(size: 0x24u);
    if ( v4 != nullptr )
    {
      *(_DWORD *)&v4->sim_unit_cores.memsize = 2;
      v4->sim_unit_cores.elems = (void **)v4->sim_unit_cores.elem_buffer;
      *(_DWORD *)&v4->controller_cores.memsize = 0;
      v4->controller_cores.elems = nullptr;
      *(_DWORD *)v4 &= 0xFFFFFCFF;
      v5 = v4;
      *(_BYTE *)v4 = 8;
      *(_DWORD *)v4 &= 0xFFFFC3FF;
      split_new_unit = v4;
    }
    else
    {
      split_new_unit = nullptr;
      v5 = nullptr;
    }
    *(_BYTE *)v5 = 1;
    sim_units_manager = split_father->environment->sim_units_manager;
    sim_units_slots = sim_units_manager->sim_units_slots;
    if ( *(_BYTE *)v5 >= 8 )
      sim_units_slots = &sim_units_manager->still_slot;
    v8 = *sim_units_slots;
    v5->next_sim_unit = *sim_units_slots;
    if ( v8 != nullptr )
      v8->prev_sim_unit = v5;
    v5->prev_sim_unit = nullptr;
    *sim_units_slots = v5;
    if ( this->sim_unit_cores.n_elems != 0 )
    {
      do
      {
        my_core = (IVP_Core *)this->sim_unit_cores.elems[v3];
        father = IVP_Core::union_find_get_father(this: my_core);
        if ( father == split_father )
        {
          for ( i = v3; i < this->sim_unit_cores.n_elems - 1; ++i )
            this->sim_unit_cores.elems[i] = this->sim_unit_cores.elems[i + 1];
          --this->sim_unit_cores.n_elems;
          --v3;
          if ( v5->sim_unit_cores.n_elems >= v5->sim_unit_cores.memsize )
            IVP_U_Vector_Base::increment_mem(this: &v5->sim_unit_cores);
          v5->sim_unit_cores.elems[v5->sim_unit_cores.n_elems++] = my_core;
          my_core->sim_unit_of_core = split_new_unit;
          v5 = split_new_unit;
        }
        else if ( next_split_father != nullptr )
        {
          if ( father != next_split_father )
            next_split_necessary = IVP_TRUE;
        }
        else
        {
          next_split_father = father;
        }
        ++v3;
      }
      while ( v3 < this->sim_unit_cores.n_elems );
    }
    IVP_Simulation_Unit::sim_unit_calc_redundants(this: v5);
    if ( next_split_necessary != IVP_TRUE )
      break;
    split_father = next_split_father;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076C80
// Name: public: void IVP_Simulation_Unit::fusion_simulation_unities(class IVP_Simulation_Unit __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::fusion_simulation_unities(
        IVP_Simulation_Unit *this,
        IVP_Simulation_Unit *second_unit)
{
  IVP_Simulation_Unit::clean_sim_unit(this);
  IVP_Simulation_Unit::throw_cores_into_my_sim_unit(this, second_unit);
  IVP_Simulation_Unit::sim_unit_calc_redundants(this);
}

//------------------------------------------------------------------------------
// Address: 0x10076CB0
// Name: public: static void IVP_Controller_Manager::remove_controller_from_environment(class IVP_Controller_Dependent __near *,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Controller_Manager::remove_controller_from_environment(
        IVP_Controller_Dependent *cntrl,
        IVP_BOOL silently)
{
  IVP_U_Vector<IVP_Core> *v3; // eax
  int v4; // edi
  IVP_Core *v5; // esi
  unsigned __int16 n_elems; // dx
  int v7; // eax
  IVP_Controller_Dependent **v8; // ecx
  IVP_Simulation_Unit *sim_unit_of_core; // esi
  unsigned int v10; // edx
  int v11; // edi
  IVP_U_Vector<IVP_Core> *controlled_cores; // [esp+10h] [ebp+8h]

  v3 = cntrl->get_associated_controlled_cores(this: cntrl);
  v4 = v3->n_elems - 1;
  controlled_cores = v3;
  if ( v3->n_elems != 0 )
  {
    while ( 1 )
    {
      v5 = (IVP_Core *)v3->elems[v4];
      n_elems = v5->controllers_of_core.n_elems;
      v7 = n_elems - 1;
      if ( n_elems != 0 )
      {
        v8 = (IVP_Controller_Dependent **)&v5->controllers_of_core.elems[v7];
        do
        {
          if ( *v8 == cntrl )
            break;
          --v8;
          --v7;
        }
        while ( v7 >= 0 );
      }
      for ( v5->controllers_of_core.n_elems = n_elems - 1; v7 < v5->controllers_of_core.n_elems; ++v7 )
        v5->controllers_of_core.elems[v7] = v5->controllers_of_core.elems[v7 + 1];
      IVP_Simulation_Unit::remove_controller_of_core(this: v5->sim_unit_of_core, my_core: v5, cntrl);
      --v4;
      sim_unit_of_core = v5->sim_unit_of_core;
      if ( v4 < 0 )
        break;
      v3 = controlled_cores;
    }
    if ( sim_unit_of_core != nullptr )
    {
      v10 = *(_DWORD *)sim_unit_of_core & 0xFFFFFCFF | 0x100;
      *(_DWORD *)sim_unit_of_core = v10;
      if ( silently == IVP_FALSE )
      {
        if ( (char)v10 < 8 )
        {
          v11 = sim_unit_of_core->sim_unit_cores.n_elems - 1;
          if ( sim_unit_of_core->sim_unit_cores.n_elems != 0 )
          {
            do
              IVP_Core::reset_freeze_check_values(this: (IVP_Core *)sim_unit_of_core->sim_unit_cores.elems[v11--]);
            while ( v11 >= 0 );
          }
        }
        else
        {
          IVP_Simulation_Unit::sim_unit_revive_for_simulation(
            this: sim_unit_of_core,
            env: *((IVP_Environment **)*sim_unit_of_core->sim_unit_cores.elems + 3));
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076DA0
// Name: public: static void IVP_Controller_Manager::remove_controller_from_core(class IVP_Controller_Independent __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Controller_Manager::remove_controller_from_core(IVP_Controller_Independent *cntrl, IVP_Core *core)
{
  IVP_Core::rem_core_controller(this: core, rem_cntrl: cntrl);
}

//------------------------------------------------------------------------------
// Address: 0x10076DC0
// Name: public: void IVP_Core::add_core_controller(class IVP_Controller __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Core::add_core_controller(IVP_Core *this, IVP_Controller *add_cntrl)
{
  if ( this->controllers_of_core.n_elems >= this->controllers_of_core.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->controllers_of_core);
  this->controllers_of_core.elems[this->controllers_of_core.n_elems++] = add_cntrl;
  IVP_Simulation_Unit::add_controller_of_core(this: this->sim_unit_of_core, my_core: this, cntrl: add_cntrl);
}

//------------------------------------------------------------------------------
// Address: 0x10076E10
// Name: public: void IVP_Simulation_Unit::do_sim_unit_union_find(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::do_sim_unit_union_find(IVP_Simulation_Unit *this)
{
  IVP_Core *test; // edi

  IVP_Simulation_Unit::clean_sim_unit(this);
  IVP_Simulation_Unit::sim_unit_calc_redundants(this);
  test = IVP_Simulation_Unit::sim_unit_union_find_test(this);
  if ( test != nullptr )
  {
    IVP_Simulation_Unit::clean_sim_unit(this);
    IVP_Simulation_Unit::split_sim_unit(this, split_father: test);
    IVP_Simulation_Unit::sim_unit_calc_redundants(this);
  }
  *(_DWORD *)this &= 0xFFFFFCFF;
}

//------------------------------------------------------------------------------
// Address: 0x10076E50
// Name: public: void IVP_Simulation_Unit::simulate_single_sim_unit_psi(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::simulate_single_sim_unit_psi(
        IVP_Simulation_Unit *this,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *touched_cores)
{
  IVP_Event_Sim *v3; // esi
  IVP_Environment *environment; // eax
  int v6; // ebx
  double seconds; // xmm0_8
  void **elems; // ecx
  void *v9; // esi
  const char *v10; // eax
  double v11; // xmm0_8
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  void *v15; // ebx
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // ecx
  IVP_Environment *v22; // ebx
  bool v23; // zf
  int v24; // eax
  int v25; // ebx
  int i; // ebx
  _DWORD *v27; // eax
  int v28; // esi
  int v30; // eax
  _DWORD *v31; // esi
  int v32; // ebx
  IVP_Core *test; // esi
  IVP_U_Memory *sim_unit_mem; // ecx
  IVP_Time current_time; // [esp+Ch] [ebp-18h]
  int controller_num; // [esp+14h] [ebp-10h]
  float v37; // [esp+18h] [ebp-Ch]
  float v38; // [esp+18h] [ebp-Ch]
  int fast_moving_flag; // [esp+1Ch] [ebp-8h]
  float fast_moving_corea; // [esp+20h] [ebp-4h]
  int fast_moving_core; // [esp+20h] [ebp-4h]
  void *k; // [esp+30h] [ebp+Ch]
  int ka; // [esp+30h] [ebp+Ch]

  v3 = es;
  environment = es->environment;
  es->sim_unit = this;
  ++environment->sim_unit_mem->transaction_in_use;
  v6 = this->sim_unit_cores.n_elems - 1;
  current_time.seconds = es->environment->current_time.seconds;
  seconds = current_time.seconds;
  controller_num = this->controller_cores.n_elems;
  fast_moving_flag = 0;
  if ( v6 >= 1 )
  {
    do
    {
      elems = this->sim_unit_cores.elems;
      v9 = elems[v6];
      v10 = (const char *)elems[v6 - 1];
      v11 = seconds - *((double *)v9 + 38);
      _mm_prefetch(v10 + 96, 2);
      _mm_prefetch(v10 + 128, 2);
      _mm_prefetch(v10 + 160, 2);
      _mm_prefetch(v10 + 192, 2);
      v37 = v11;
      IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)v9 + 17, mat: (IVP_U_Matrix3 *)v9 + 2);
      LODWORD(v11) = *((_DWORD *)v9 + 61);
      v12 = *((float *)v9 + 62);
      v13 = *((float *)v9 + 60);
      _mm_prefetch(**((const char ***)v9 + 21), 2);
      *(float *)&v11 = (float)(*(float *)&v11 * v37) + *((float *)v9 + 57);
      v14 = (float)(v12 * v37) + *((float *)v9 + 58);
      *((float *)v9 + 36) = (float)(v13 * v37) + *((float *)v9 + 56);
      *((_DWORD *)v9 + 37) = LODWORD(v11);
      *((float *)v9 + 38) = v14;
      IVP_Core::commit_all_async_pushes(this: (IVP_Core *)v9);
      fast_moving_flag |= COERCE_UNSIGNED_INT(
                            1.0
                          - (float)((float)((float)(*((float *)v9 + 52) * *((float *)v9 + 52))
                                          + (float)(*((float *)v9 + 53) * *((float *)v9 + 53)))
                                  + (float)(*((float *)v9 + 54) * *((float *)v9 + 54))));
      seconds = current_time.seconds;
      *(_WORD *)v9 &= 0xFF3Fu;
      --v6;
      *((_WORD *)v9 + 1) = 0;
    }
    while ( v6 >= 1 );
    v3 = es;
  }
  v15 = *this->sim_unit_cores.elems;
  v38 = seconds - *((double *)v15 + 38);
  IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)v15 + 17, mat: (IVP_U_Matrix3 *)v15 + 2);
  v16 = *((float *)v15 + 61);
  v17 = *((float *)v15 + 62);
  v18 = *((float *)v15 + 60);
  _mm_prefetch(**((const char ***)v15 + 21), 2);
  v19 = (float)(v16 * v38) + *((float *)v15 + 57);
  v20 = (float)(v17 * v38) + *((float *)v15 + 58);
  *((float *)v15 + 36) = (float)(v18 * v38) + *((float *)v15 + 56);
  *((float *)v15 + 37) = v19;
  *((float *)v15 + 38) = v20;
  IVP_Core::commit_all_async_pushes(this: (IVP_Core *)v15);
  fast_moving_corea = 1.0
                    - (float)((float)((float)(*((float *)v15 + 52) * *((float *)v15 + 52))
                                    + (float)(*((float *)v15 + 53) * *((float *)v15 + 53)))
                            + (float)(*((float *)v15 + 54) * *((float *)v15 + 54)));
  *(_WORD *)v15 &= 0xFF3Fu;
  *((_WORD *)v15 + 1) = 0;
  v21 = *(_DWORD *)this;
  if ( (fast_moving_flag | LODWORD(fast_moving_corea)) >= 0 )
  {
    v24 = v21 ^ ((unsigned __int16)v21 ^ (unsigned __int16)(4 * v21)) & 0x3000;
    *(_DWORD *)this = v24;
    if ( (v24 & 0x3000) != 0 )
    {
      v25 = this->sim_unit_cores.n_elems - 1;
      if ( this->sim_unit_cores.n_elems != 0 )
      {
        do
          IVP_Core::reset_freeze_check_values(this: (IVP_Core *)this->sim_unit_cores.elems[v25--]);
        while ( v25 >= 0 );
      }
    }
    *(_DWORD *)this &= 0xFFFFF3FF;
    v22 = v3->environment;
    v23 = v22->next_movement_check-- == 1;
    if ( v23 )
      goto LABEL_6;
    fast_moving_core = 0;
  }
  else
  {
    *(_DWORD *)this = v21 & 0xFFFFF3FF | 0x400;
    v22 = v3->environment;
    v23 = v22->next_movement_check-- == 1;
    if ( v23 )
    {
LABEL_6:
      v22->next_movement_check = 15 - (int)(ivp_rand() * -5.0);
      fast_moving_core = 1;
      goto LABEL_13;
    }
    fast_moving_core = 0;
  }
LABEL_13:
  for ( i = controller_num - 1; i >= 0; --i )
  {
    v27 = this->controller_cores.elems[i];
    (*(void (__thiscall **)(_DWORD, IVP_Event_Sim *, _DWORD *))(*(_DWORD *)*v27 + 16))(a1: *v27, a2: v3, a3: v27 + 1);
  }
  v28 = this->sim_unit_cores.n_elems - 1;
  if ( this->sim_unit_cores.n_elems != 0 )
  {
    do
    {
      k = this->sim_unit_cores.elems[v28];
      if ( touched_cores->n_elems >= touched_cores->memsize )
        IVP_U_Vector_Base::increment_mem(this: touched_cores);
      touched_cores->elems[touched_cores->n_elems++] = k;
      --v28;
    }
    while ( v28 >= 0 );
  }
  if ( fast_moving_core == 1 )
    IVP_Simulation_Unit::sim_unit_calc_movement_state(this, env: es->environment);
  v30 = this->sim_unit_cores.n_elems - 1;
  ka = v30;
  if ( this->sim_unit_cores.n_elems != 0 )
  {
    do
    {
      v31 = this->sim_unit_cores.elems[v30];
      v32 = *((unsigned __int16 *)v31 + 41) - 1;
      if ( *((_WORD *)v31 + 41) != 0 )
      {
        do
          IVP_Real_Object::recalc_invalid_mindists_of_object(this: *(IVP_Real_Object **)(v31[21] + 4 * v32--));
        while ( v32 >= 0 );
        v30 = ka;
      }
      ka = --v30;
    }
    while ( v30 >= 0 );
  }
  if ( (*(_DWORD *)this & 0x300) != 0 )
  {
    IVP_Simulation_Unit::clean_sim_unit(this);
    IVP_Simulation_Unit::sim_unit_calc_redundants(this);
    test = IVP_Simulation_Unit::sim_unit_union_find_test(this);
    if ( test != nullptr )
    {
      IVP_Simulation_Unit::clean_sim_unit(this);
      IVP_Simulation_Unit::split_sim_unit(this, split_father: test);
      IVP_Simulation_Unit::sim_unit_calc_redundants(this);
    }
    *(_DWORD *)this &= 0xFFFFFCFF;
  }
  sim_unit_mem = es->environment->sim_unit_mem;
  v23 = sim_unit_mem->transaction_in_use-- == 1;
  if ( v23 )
    IVP_U_Memory::free_mem_transaction(this: sim_unit_mem);
}

//------------------------------------------------------------------------------
// Address: 0x10077250
// Name: public: void IVP_Sim_Units_Manager::simulate_sim_units_psi(class IVP_Environment __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Sim_Units_Manager::simulate_sim_units_psi(
        IVP_Sim_Units_Manager *this,
        IVP_Environment *env,
        IVP_U_Vector<IVP_Core> *touched_cores)
{
  IVP_Simulation_Unit *v3; // ebx
  float inv_delta_PSI_time; // xmm0_4
  IVP_Simulation_Unit *next_sim_unit; // esi
  IVP_Simulation_Unit *v6; // ecx
  IVP_Simulation_Unit *i; // edi
  const char *elems; // eax
  int n_elems; // ecx
  const char **v10; // eax
  const char *v11; // ecx
  const char *v12; // eax
  int v13; // edx
  const char **v14; // eax
  const char *v15; // ecx
  char *v16; // eax
  int v17; // ecx
  const char **v18; // eax
  const char *v19; // ecx
  const char *v20; // eax
  IVP_Event_Sim v21; // [esp+0h] [ebp-10h] BYREF
  IVP_Simulation_Unit *n1_su; // [esp+18h] [ebp+8h]

  v3 = this->sim_units_slots[0];
  v21.delta_time = env->delta_PSI_time;
  inv_delta_PSI_time = env->inv_delta_PSI_time;
  v21.environment = env;
  v21.i_delta_time = inv_delta_PSI_time;
  if ( v3 != nullptr )
  {
    next_sim_unit = v3->next_sim_unit;
    if ( next_sim_unit != nullptr )
    {
      v6 = next_sim_unit->next_sim_unit;
      n1_su = v6;
      if ( v6 != nullptr )
      {
        for ( i = v6->next_sim_unit; i != nullptr; v6 = n1_su )
        {
          elems = (const char *)v6->controller_cores.elems;
          _mm_prefetch((const char *)v6->sim_unit_cores.elems, 2);
          n_elems = next_sim_unit->controller_cores.n_elems;
          _mm_prefetch((const char *)i, 2);
          _mm_prefetch((const char *)&i->controller_cores.elems, 2);
          _mm_prefetch(elems, 2);
          if ( (_WORD)n_elems != 0 )
          {
            v10 = (const char **)next_sim_unit->controller_cores.elems;
            v11 = v10[n_elems - 1];
            _mm_prefetch(*v10, 2);
            v12 = (const char *)next_sim_unit->sim_unit_cores.elems[next_sim_unit->sim_unit_cores.n_elems - 1];
            _mm_prefetch(v11, 2);
            _mm_prefetch(v12, 2);
            _mm_prefetch(v12 + 96, 2);
            _mm_prefetch(v12 + 128, 2);
            _mm_prefetch(v12 + 160, 2);
            _mm_prefetch(v12 + 192, 2);
          }
          IVP_Simulation_Unit::simulate_single_sim_unit_psi(this: v3, es: &v21, touched_cores);
          v3 = next_sim_unit;
          next_sim_unit = n1_su;
          n1_su = i;
          i = i->next_sim_unit;
        }
        v13 = next_sim_unit->controller_cores.n_elems;
        _mm_prefetch((const char *)v3->controller_cores.elems, 2);
        _mm_prefetch((const char *)v3->sim_unit_cores.elems, 2);
        if ( (_WORD)v13 != 0 )
        {
          v14 = (const char **)next_sim_unit->controller_cores.elems;
          v15 = v14[v13 - 1];
          _mm_prefetch(*v14, 2);
          v16 = (char *)next_sim_unit->sim_unit_cores.elems[next_sim_unit->sim_unit_cores.n_elems - 1];
          _mm_prefetch(v15, 2);
          _mm_prefetch(v16, 2);
          IVP_Simulation_Unit::prefetch0_init_moving_core_for_psi(core: (IVP_Core *)v16);
          v6 = n1_su;
        }
        IVP_Simulation_Unit::simulate_single_sim_unit_psi(this: v6, es: &v21, touched_cores);
      }
      v17 = v3->controller_cores.n_elems;
      if ( (_WORD)v17 != 0 )
      {
        v18 = (const char **)v3->controller_cores.elems;
        v19 = v18[v17 - 1];
        _mm_prefetch(*v18, 2);
        v20 = (const char *)v3->sim_unit_cores.elems[v3->sim_unit_cores.n_elems - 1];
        _mm_prefetch(v19, 2);
        _mm_prefetch(v20, 2);
        _mm_prefetch(v20 + 96, 2);
        _mm_prefetch(v20 + 128, 2);
        _mm_prefetch(v20 + 160, 2);
        _mm_prefetch(v20 + 192, 2);
      }
      IVP_Simulation_Unit::simulate_single_sim_unit_psi(this: next_sim_unit, es: &v21, touched_cores);
    }
    IVP_Simulation_Unit::simulate_single_sim_unit_psi(this: v3, es: &v21, touched_cores);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100773D0
// Name: public: void IVP_Simulation_Unit::sim_unit_remove_core(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Simulation_Unit::sim_unit_remove_core(IVP_Simulation_Unit *this, IVP_Core *del_core)
{
  unsigned __int16 n_elems; // dx
  int v4; // eax
  IVP_Core **v5; // ecx
  int v6; // eax
  IVP_Controller *v7; // ebx
  int v8; // eax
  void **v9; // ecx
  _WORD *v10; // ecx
  unsigned __int16 v11; // di
  int v12; // eax
  IVP_Core **v13; // edx
  IVP_Sim_Units_Manager *sim_units_manager; // eax
  IVP_Simulation_Unit **sim_units_slots; // edx
  IVP_Simulation_Unit *prev_sim_unit; // ecx
  IVP_Simulation_Unit *next_sim_unit; // eax
  int i; // [esp+Ch] [ebp-4h]

  n_elems = this->sim_unit_cores.n_elems;
  v4 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v5 = (IVP_Core **)&this->sim_unit_cores.elems[v4];
    do
    {
      if ( *v5 == del_core )
        break;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  for ( this->sim_unit_cores.n_elems = n_elems - 1; v4 < this->sim_unit_cores.n_elems; ++v4 )
    this->sim_unit_cores.elems[v4] = this->sim_unit_cores.elems[v4 + 1];
  v6 = del_core->controllers_of_core.n_elems - 1;
  i = v6;
  if ( del_core->controllers_of_core.n_elems != 0 )
  {
    while ( 1 )
    {
      v7 = (IVP_Controller *)del_core->controllers_of_core.elems[v6];
      v8 = this->controller_cores.n_elems - 1;
      if ( this->controller_cores.n_elems != 0 )
      {
        v9 = &this->controller_cores.elems[v8];
        do
        {
          if ( *(IVP_Controller **)*v9 == v7 )
            break;
          --v9;
          --v8;
        }
        while ( v8 >= 0 );
      }
      v10 = this->controller_cores.elems[v8];
      v11 = v10[3];
      v12 = v11 - 1;
      if ( v11 != 0 )
      {
        v13 = (IVP_Core **)(*((_DWORD *)v10 + 2) + 4 * v12);
        do
        {
          if ( *v13 == del_core )
            break;
          --v13;
          --v12;
        }
        while ( v12 >= 0 );
      }
      for ( v10[3] = v11 - 1; v12 < (unsigned __int16)v10[3]; ++v12 )
        *(_DWORD *)(*((_DWORD *)v10 + 2) + 4 * v12) = *(_DWORD *)(*((_DWORD *)v10 + 2) + 4 * v12 + 4);
      if ( v10[3] == 0 )
        IVP_Simulation_Unit::rem_sim_unit_controller(this, rem_controller: v7);
      if ( --i < 0 )
        break;
      v6 = i;
    }
  }
  if ( this->sim_unit_cores.n_elems == 0 )
  {
    sim_units_manager = del_core->environment->sim_units_manager;
    sim_units_slots = sim_units_manager->sim_units_slots;
    if ( *(_BYTE *)this >= 8 )
      sim_units_slots = &sim_units_manager->still_slot;
    prev_sim_unit = this->prev_sim_unit;
    next_sim_unit = this->next_sim_unit;
    if ( prev_sim_unit != nullptr )
      prev_sim_unit->next_sim_unit = next_sim_unit;
    else
      *sim_units_slots = next_sim_unit;
    if ( next_sim_unit != nullptr )
      next_sim_unit->prev_sim_unit = prev_sim_unit;
    IVP_Simulation_Unit::~IVP_Simulation_Unit(this);
    free(data: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077520
// Name: public: static void IVP_Controller_Manager::add_controller_to_core(class IVP_Controller_Independent __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Controller_Manager::add_controller_to_core(IVP_Controller_Independent *cntrl, IVP_Core *core)
{
  if ( core->controllers_of_core.n_elems >= core->controllers_of_core.memsize )
    IVP_U_Vector_Base::increment_mem(this: &core->controllers_of_core);
  core->controllers_of_core.elems[core->controllers_of_core.n_elems++] = cntrl;
  IVP_Simulation_Unit::add_controller_of_core(this: core->sim_unit_of_core, my_core: core, cntrl);
}

//------------------------------------------------------------------------------
// Address: 0x10077570
// Name: public: void IVP_Controller_Manager::announce_controller_to_environment(class IVP_Controller_Dependent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Manager::announce_controller_to_environment(
        IVP_Controller_Manager *this,
        IVP_Controller_Dependent *cntrl)
{
  IVP_U_Vector<IVP_Core> *v2; // eax
  IVP_Simulation_Unit *v3; // ecx
  int v4; // ebx
  void *v5; // edi
  IVP_Simulation_Unit *v6; // esi
  IVP_U_Vector<IVP_Core> *controlled_cores; // [esp+8h] [ebp-10h]
  IVP_BOOL did_fusion; // [esp+Ch] [ebp-Ch]
  IVP_Movement_Type mtype; // [esp+10h] [ebp-8h]
  IVP_Simulation_Unit *reference_unit; // [esp+14h] [ebp-4h]

  v2 = cntrl->get_associated_controlled_cores(this: cntrl);
  v3 = nullptr;
  v4 = v2->n_elems - 1;
  controlled_cores = v2;
  reference_unit = nullptr;
  did_fusion = IVP_FALSE;
  mtype = IVP_MT_NOT_SIM;
  if ( v2->n_elems != 0 )
  {
    do
    {
      v5 = v2->elems[v4];
      if ( (*(_BYTE *)v5 & 2) == 0 )
      {
        mtype = (unsigned __int8)(*((_BYTE *)v5 + 1) & mtype);
        v6 = *((IVP_Simulation_Unit **)v5 + 83);
        if ( v3 != nullptr )
        {
          if ( v6 != v3 )
          {
            IVP_Simulation_Unit::throw_cores_into_my_sim_unit(this: v3, second_unit: *((IVP_Simulation_Unit **)v5 + 83));
            if ( v6 != nullptr )
            {
              IVP_Simulation_Unit::~IVP_Simulation_Unit(this: v6);
              free(data: v6);
            }
            did_fusion = IVP_TRUE;
          }
        }
        else
        {
          reference_unit = *((IVP_Simulation_Unit **)v5 + 83);
        }
        if ( *((_WORD *)v5 + 161) >= *((_WORD *)v5 + 160) )
          IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)v5 + 40);
        *(_DWORD *)(*((_DWORD *)v5 + 81) + 4 * (unsigned __int16)(*((_WORD *)v5 + 161))++) = cntrl;
        IVP_Simulation_Unit::add_controller_of_core(
          this: *((IVP_Simulation_Unit **)v5 + 83),
          my_core: (IVP_Core *)v5,
          cntrl);
        v2 = controlled_cores;
        v3 = reference_unit;
      }
      --v4;
    }
    while ( v4 >= 0 );
    if ( did_fusion == IVP_TRUE )
    {
      IVP_Simulation_Unit::clean_sim_unit(this: v3);
      IVP_Simulation_Unit::sim_unit_calc_redundants(this: reference_unit);
      v3 = reference_unit;
    }
    if ( mtype < IVP_MT_NOT_SIM )
      IVP_Simulation_Unit::sim_unit_revive_for_simulation(this: v3, env: this->l_environment);
  }
}
