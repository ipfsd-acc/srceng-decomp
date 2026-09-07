// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_hull_manager.cxx
// Functions: 7
// ============================================================

#include "ivp\ivp_intern\ivp_hull_manager.h"

//------------------------------------------------------------------------------
// Address: 0x10092720
// Name: public: IVP_Hull_Manager_Base::IVP_Hull_Manager_Base(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Hull_Manager_Base *__thiscall IVP_Hull_Manager_Base::IVP_Hull_Manager_Base(IVP_Hull_Manager_Base *this)
{
  this->last_vpsi_time.seconds = 0.0;
  IVP_U_Min_List::IVP_U_Min_List(this: &this->sorted_synapses, start_size: 8);
  *(_QWORD *)&this->gradient = 0;
  this->hull_value_last_vpsi = 0.0;
  this->hull_center_value_last_vpsi = 0.0;
  *(_QWORD *)&this->hull_value_next_psi = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092760
// Name: public: IVP_Hull_Manager_Base::~IVP_Hull_Manager_Base(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Hull_Manager_Base::~IVP_Hull_Manager_Base(IVP_Hull_Manager_Base *this)
{
  IVP_U_Min_List::~IVP_U_Min_List(this: &this->sorted_synapses);
}

//------------------------------------------------------------------------------
// Address: 0x10092770
// Name: public: void IVP_Hull_Manager::delete_hull_manager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Hull_Manager::delete_hull_manager(IVP_Hull_Manager *this)
{
  void *element; // ecx

  while ( this->sorted_synapses.counter != 0 )
  {
    element = this->sorted_synapses.elems[this->sorted_synapses.first_element].element;
    (*(void (__thiscall **)(void *, IVP_Hull_Manager *))(*(_DWORD *)element + 8))(a1: element, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100927A0
// Name: private: void IVP_Hull_Manager::reset_times(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Hull_Manager::reset_times(IVP_Hull_Manager *this)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  unsigned int first_element; // esi
  IVP_U_Min_List_Element *v5; // eax
  void *element; // ecx
  float mt; // [esp+10h] [ebp-8h]
  int mc; // [esp+14h] [ebp-4h]

  LODWORD(v2) = LODWORD(this->hull_value_last_vpsi) ^ _mask__NegFloat_;
  v3 = LODWORD(this->hull_center_value_last_vpsi) ^ _mask__NegFloat_;
  first_element = this->sorted_synapses.first_element;
  mt = v2;
  mc = v3;
  while ( first_element != 0xFFFF )
  {
    v5 = &this->sorted_synapses.elems[first_element];
    first_element = v5->next;
    element = v5->element;
    v5->value = v2 + v5->value;
    (*(void (__thiscall **)(void *, float, int))(*(_DWORD *)element + 12))(
      a1: element,
      a2: COERCE_FLOAT(LODWORD(v2)),
      a3: v3);
    v3 = mc;
    v2 = mt;
  }
  this->sorted_synapses.min_value = this->sorted_synapses.min_value + v2;
  this->hull_value_last_vpsi = 0.0;
  this->hull_center_value_last_vpsi = 0.0;
  this->hull_value_next_psi = this->hull_value_next_psi + v2;
}

//------------------------------------------------------------------------------
// Address: 0x10092850
// Name: public: void IVP_Hull_Manager::reset_time(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Hull_Manager::reset_time(IVP_Hull_Manager *this, IVP_Time offset)
{
  this->last_vpsi_time.seconds = this->last_vpsi_time.seconds - offset.seconds;
}

//------------------------------------------------------------------------------
// Address: 0x10092870
// Name: public: int IVP_Hull_Manager::too_many_synapses_checked_error_get_additional(class IVP_Environment __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Hull_Manager::too_many_synapses_checked_error_get_additional(
        IVP_Hull_Manager *this,
        IVP_Environment *pEnvironment,
        int checked)
{
  return pEnvironment->anomaly_manager->max_collision_checks_exceeded(this: pEnvironment->anomaly_manager, a2: checked);
}

//------------------------------------------------------------------------------
// Address: 0x10092890
// Name: public: int IVP_Hull_Manager::get_synapse_check_count(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Hull_Manager::get_synapse_check_count(IVP_Hull_Manager *this, IVP_Environment *pEnvironment)
{
  return pEnvironment->anomaly_limits->max_collision_checks_per_psi;
}
