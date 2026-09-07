// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_physic.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_intern\ivp_physic.h"

//------------------------------------------------------------------------------
// Address: 0x10085B50
// Name: public: void IVP_Statistic_Manager::clear_statistic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Statistic_Manager::clear_statistic(IVP_Statistic_Manager *this)
{
  this->max_rescue_speed = 0.0;
  this->max_speed_gain = 0.0;
  this->impact_sys_num = 0;
  this->impact_counter = 0;
  this->impact_sum_sys = 0;
  this->impact_hard_rescue_counter = 0;
  this->impact_rescue_after_counter = 0;
  this->impact_delayed_counter = 0;
  this->impact_coll_checks = 0;
  this->mindists_deleted = 0;
  this->mindists_generated = 0;
  this->processed_fmindists = 0;
  this->range_intra_exceeded = 0;
  this->range_world_exceeded = 0;
  this->impact_unmov = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10085B90
// Name: public: IVP_Application_Environment::IVP_Application_Environment(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Application_Environment *__thiscall IVP_Application_Environment::IVP_Application_Environment(
        IVP_Application_Environment *this)
{
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Application_Environment));
  this->n_cache_object = 256;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10085BB0
// Name: public: IVP_Statistic_Manager::IVP_Statistic_Manager(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Statistic_Manager *__thiscall IVP_Statistic_Manager::IVP_Statistic_Manager(IVP_Statistic_Manager *this)
{
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Statistic_Manager));
  return this;
}
