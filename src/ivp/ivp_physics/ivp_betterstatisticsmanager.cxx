// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/ivp_betterstatisticsmanager.cxx
// Functions: 2
// ============================================================

#include "ivp\ivp_physics\ivp_betterstatisticsmanager.h"

//------------------------------------------------------------------------------
// Address: 0x10097150
// Name: public: IVP_BetterStatisticsmanager::IVP_BetterStatisticsmanager(void)
// Source: json
//------------------------------------------------------------------------------
IVP_BetterStatisticsmanager *__thiscall IVP_BetterStatisticsmanager::IVP_BetterStatisticsmanager(
        IVP_BetterStatisticsmanager *this)
{
  *(_DWORD *)&this->output_callbacks.memsize = 0;
  this->output_callbacks.elems = nullptr;
  this->data_entities.memsize = 0;
  this->data_entities.n_elems = 0;
  this->data_entities.elems = nullptr;
  this->enabled = IVP_TRUE;
  this->update_interval = 1.0;
  this->update_delayed = IVP_TRUE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097190
// Name: public: IVP_BetterStatisticsmanager::~IVP_BetterStatisticsmanager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_BetterStatisticsmanager::~IVP_BetterStatisticsmanager(IVP_BetterStatisticsmanager *this)
{
  IVP_BetterStatisticsmanager *elems; // eax
  void **v3; // eax

  elems = (IVP_BetterStatisticsmanager *)this->data_entities.elems;
  if ( elems != (IVP_BetterStatisticsmanager *)&this->simulation_time )
  {
    if ( elems != nullptr )
      free(data: elems);
    this->data_entities.elems = nullptr;
    this->data_entities.memsize = 0;
  }
  this->data_entities.n_elems = 0;
  v3 = this->output_callbacks.elems;
  if ( v3 == (void **)&this->data_entities )
  {
    this->output_callbacks.n_elems = 0;
  }
  else
  {
    if ( v3 != nullptr )
      free(data: this->output_callbacks.elems);
    this->output_callbacks.elems = nullptr;
    *(_DWORD *)&this->output_callbacks.memsize = 0;
  }
}
