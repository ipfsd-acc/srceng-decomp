// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_time.cxx
// Functions: 10
// ============================================================

#include "ivp\ivp_intern\ivp_time.h"

//------------------------------------------------------------------------------
// Address: 0x10084C50
// Name: public: void IVP_Time_Manager::remove_event(class IVP_Time_Event __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Time_Manager::remove_event(IVP_Time_Manager *this, IVP_Time_Event *event)
{
  IVP_U_Min_List::remove_minlist_elem(this: this->min_hash, index: event->index);
}

//------------------------------------------------------------------------------
// Address: 0x10084C70
// Name: public: void IVP_Time_Manager::update_event(class IVP_Time_Event __near *,class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Time_Manager::update_event(IVP_Time_Manager *this, IVP_Time_Event *event, IVP_Time time)
{
  float event_time; // [esp+Ch] [ebp-4h]

  event_time = time.seconds - this->base_time.seconds;
  IVP_U_Min_List::remove_minlist_elem(this: this->min_hash, index: event->index);
  event->index = IVP_U_Min_List::add(this: this->min_hash, elem: event, value: event_time);
}

//------------------------------------------------------------------------------
// Address: 0x10084CC0
// Name: public: void IVP_Time_Manager::event_loop(class IVP_Environment __near *,class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Time_Manager::event_loop(IVP_Time_Manager *this, IVP_Environment *env, IVP_Time time)
{
  env->performancecounter->start_pcount(this: env->performancecounter);
  ((void (__thiscall *)(IVP_Event_Manager *, IVP_Time_Manager *, IVP_Environment *, _DWORD, _DWORD))this->event_manager->simulate_time_events)(
    a1: this->event_manager,
    a2: this,
    a3: env,
    a4: LODWORD(time.seconds),
    a5: HIDWORD(time.seconds));
  env->performancecounter->stop_pcount(this: env->performancecounter);
}

//------------------------------------------------------------------------------
// Address: 0x10084D00
// Name: public: void IVP_Time_Manager::env_set_current_time(class IVP_Environment __near *,class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Time_Manager::env_set_current_time(IVP_Time_Manager *this, IVP_Environment *env, IVP_Time time)
{
  IVP_Environment::set_current_time(this: env, time);
}

//------------------------------------------------------------------------------
// Address: 0x10084D20
// Name: public: void IVP_Time_Manager::reset_time(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Time_Manager::reset_time(IVP_Time_Manager *this, IVP_Time offset)
{
  IVP_U_Min_List *min_hash; // esi
  unsigned int first_element; // edx
  float v4; // xmm0_4
  int v5; // eax

  min_hash = this->min_hash;
  first_element = min_hash->first_element;
  v4 = offset.seconds - this->base_time.seconds;
  while ( first_element != 0xFFFF )
  {
    v5 = (int)&min_hash->elems[first_element];
    first_element = *(unsigned __int16 *)(v5 + 4);
    *(float *)(v5 + 8) = *(float *)(v5 + 8) - v4;
  }
  this->min_hash->min_value = this->min_hash->min_value - v4;
  this->base_time.seconds = 0.0;
  this->last_time = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10084D90
// Name: private: virtual void IVP_Event_Manager_Standard::simulate_time_events(class IVP_Time_Manager __near *,class IVP_Environment __near *,class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Event_Manager_Standard::simulate_time_events(
        IVP_Event_Manager_Standard *this,
        IVP_Time_Manager *tman,
        IVP_Environment *env,
        IVP_Time time)
{
  long double v5; // xmm1_8
  IVP_U_Min_List *min_hash; // ecx
  void (__thiscall ***element)(void *, IVP_Environment *); // esi
  float event_time; // [esp+10h] [ebp+8h]

  v5 = time.seconds - tman->base_time.seconds;
  event_time = tman->min_hash->min_value;
  if ( (float)v5 > event_time )
  {
    do
    {
      min_hash = tman->min_hash;
      element = (void (__thiscall ***)(void *, IVP_Environment *))min_hash->elems[min_hash->first_element].element;
      IVP_U_Min_List::remove_minlist_elem(this: min_hash, index: (unsigned int)element[1]);
      element[1] = (void (__thiscall **)(void *, IVP_Environment *))0xFFFF;
      tman->last_time = event_time;
      IVP_Environment::set_current_time(this: env, time: COERCE_IVP_TIME(event_time + tman->base_time.seconds));
      (**element)(a1: element, a2: env);
      if ( tman->event_manager->mode == 1 )
        break;
      event_time = tman->min_hash->min_value;
    }
    while ( (float)(time.seconds - tman->base_time.seconds) > event_time );
  }
  IVP_Environment::set_current_time(this: env, time);
}

//------------------------------------------------------------------------------
// Address: 0x10084E50
// Name: public: virtual void IVP_Event_Manager::simulate_variable_time_step(class IVP_Time_Manager __near *,class IVP_Environment __near *,class IVP_Time_Event_PSI __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Event_Manager::simulate_variable_time_step(
        IVP_Event_Manager *this,
        IVP_Time_Manager *tman,
        IVP_Environment *env,
        IVP_Time_Event_PSI *psi_event,
        float delta)
{
  IVP_U_Min_List *min_hash; // eax
  IVP_Time_Event_PSI *element; // esi
  IVP_U_Min_List *v8; // ecx
  void (__thiscall *simulate_time_event)(struct IVP_Time_Event_PSI *, IVP_Environment *); // edx
  int psi_counter; // [esp+18h] [ebp-4h]
  float event_time; // [esp+24h] [ebp+8h]

  psi_counter = 0;
  while ( 1 )
  {
    min_hash = tman->min_hash;
    event_time = min_hash->min_value;
    element = (IVP_Time_Event_PSI *)min_hash->elems[min_hash->first_element].element;
    IVP_Environment::set_current_time(this: env, time: COERCE_IVP_TIME(event_time + tman->base_time.seconds));
    if ( element == psi_event )
    {
      if ( ++psi_counter == 2 )
        break;
      IVP_Environment::set_delta_PSI_time(this: env, a2: (int)element, psi_time: delta);
    }
    v8 = tman->min_hash;
    tman->last_time = event_time;
    IVP_U_Min_List::remove_minlist_elem(this: v8, index: element->index);
    simulate_time_event = element->simulate_time_event;
    element->index = 0xFFFF;
    simulate_time_event(this: element, a2: env);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084F00
// Name: public: IVP_Time_Manager::~IVP_Time_Manager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Time_Manager::~IVP_Time_Manager(IVP_Time_Manager *this)
{
  IVP_U_Min_List *min_hash; // ecx
  unsigned int *element; // edi
  IVP_U_Min_List *v4; // edi

  while ( this->min_hash->counter != 0 )
  {
    min_hash = this->min_hash;
    if ( min_hash->counter != 0 )
    {
      element = (unsigned int *)min_hash->elems[min_hash->first_element].element;
      IVP_U_Min_List::remove_minlist_elem(this: min_hash, index: element[1]);
    }
    else
    {
      element = nullptr;
    }
    free(data: element);
  }
  free(data: this->event_manager);
  v4 = this->min_hash;
  this->event_manager = nullptr;
  if ( v4 != nullptr )
  {
    IVP_U_Min_List::~IVP_U_Min_List(this: v4);
    free(data: v4);
  }
  this->min_hash = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10084F80
// Name: public: virtual void IVP_Time_Event_PSI::simulate_time_event(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Time_Event_PSI::simulate_time_event(IVP_Time_Event_PSI *this, IVP_Environment *env)
{
  int seconds_high; // edx
  float delta_PSI_time; // xmm1_4
  double seconds; // xmm0_8
  IVP_Time_Manager *time_manager; // ecx
  IVP_U_Min_List *min_hash; // edi
  unsigned int first_element; // edx
  float v9; // xmm0_4
  int v10; // eax

  seconds_high = HIDWORD(env->current_time.seconds);
  delta_PSI_time = env->delta_PSI_time;
  LODWORD(env->time_of_last_psi.seconds) = LODWORD(env->current_time.seconds);
  HIDWORD(env->time_of_last_psi.seconds) = seconds_high;
  seconds = env->time_of_last_psi.seconds;
  time_manager = env->time_manager;
  env->time_of_next_psi.seconds = delta_PSI_time + seconds;
  min_hash = time_manager->min_hash;
  first_element = min_hash->first_element;
  v9 = seconds;
  while ( first_element != 0xFFFF )
  {
    v10 = (int)&min_hash->elems[first_element];
    first_element = *(unsigned __int16 *)(v10 + 4);
    *(float *)(v10 + 8) = *(float *)(v10 + 8) - v9;
  }
  time_manager->min_hash->min_value = time_manager->min_hash->min_value - v9;
  time_manager->base_time.seconds = env->time_of_last_psi.seconds;
  time_manager->last_time = 0.0;
  IVP_Environment::simulate_psi(this: env, __formal: env->time_of_last_psi);
  this->index = IVP_U_Min_List::add(
                  this: env->time_manager->min_hash,
                  elem: this,
                  value: env->time_of_next_psi.seconds - env->time_manager->base_time.seconds);
}

//------------------------------------------------------------------------------
// Address: 0x10085090
// Name: public: IVP_Time_Manager::IVP_Time_Manager(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Time_Manager *__thiscall IVP_Time_Manager::IVP_Time_Manager(IVP_Time_Manager *this)
{
  IVP_Event_Manager *v2; // eax
  IVP_Time_Event_PSI *v3; // edi
  IVP_U_Min_List *v4; // eax
  IVP_U_Min_List *v5; // eax
  IVP_Time_Event_PSI *v6; // eax
  double seconds; // xmm0_8
  IVP_U_Min_List *min_hash; // ecx

  *(_QWORD *)&this->n_events = 0;
  *(_QWORD *)&this->min_hash = 0;
  *(_QWORD *)&this->last_time = 0;
  this->base_time.seconds = 0.0;
  v2 = (IVP_Event_Manager *)p_malloc(size: 8u);
  v3 = nullptr;
  if ( v2 != nullptr )
    v2->__vftable = (IVP_Event_Manager_vtbl *)&IVP_Event_Manager_Standard::`vftable';
  else
    v2 = nullptr;
  this->event_manager = v2;
  v2->mode = 0;
  v4 = (IVP_U_Min_List *)p_malloc(size: 0x18u);
  if ( v4 != nullptr )
    v5 = IVP_U_Min_List::IVP_U_Min_List(this: v4, start_size: 16);
  else
    v5 = nullptr;
  this->min_hash = v5;
  v6 = (IVP_Time_Event_PSI *)p_malloc(size: 8u);
  if ( v6 != nullptr )
  {
    v6->__vftable = (IVP_Time_Event_PSI_vtbl *)&IVP_Time_Event_PSI::`vftable';
    v3 = v6;
  }
  seconds = this->base_time.seconds;
  min_hash = this->min_hash;
  this->psi_event = v3;
  v3->index = IVP_U_Min_List::add(this: min_hash, elem: v3, value: -seconds);
  return this;
}
