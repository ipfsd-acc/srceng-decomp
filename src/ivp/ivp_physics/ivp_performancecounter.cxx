// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/ivp_performancecounter.cxx
// Functions: 5
// ============================================================

#include "ivp\ivp_physics\ivp_performancecounter.h"

//------------------------------------------------------------------------------
// Address: 0x1009A1B0
// Name: public: virtual void IVP_PerformanceCounter_Simple::reset_and_print_performance_counters(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_PerformanceCounter_Simple::reset_and_print_performance_counters(
        IVP_PerformanceCounter_Simple *this,
        IVP_Time current_time)
{
  float count_PSIs; // xmm1_4
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  float v7; // xmm0_4
  int v8; // edi
  float v9; // xmm3_4
  float v10; // xmm4_4

  count_PSIs = (float)this->count_PSIs;
  if ( count_PSIs != 0.0 )
  {
    v4 = this->counter[5][0];
    v5 = this->counter[6][0];
    v6 = this->counter[8][0];
    v7 = 0.001 / count_PSIs;
    v8 = this->counter[3][0];
    v9 = (float)(v6 + v5 + v4 + this->counter[4][0] + this->counter[1][0]);
    v10 = (float)(v8 + this->counter[2][0]);
    ivp_message(
      templat: "TOT %2.1f%% %2.2f COLL %2.2f  DYN %2.2f     det:  UNIV: %2.2f CONTR: %2.2f INTEGR: %2.2f HULL: %2.2f SHORT: %2.2f "
      "CRITIC: %2.2f AT %2.2f\n",
      (float)((float)((float)(0.001 / count_PSIs) * (float)(v10 + v9)) * 66.0) * 0.1,
      (float)((float)(0.001 / count_PSIs) * (float)(v10 + v9)),
      (float)(v7 * v9),
      (float)(v7 * v10),
      (float)((float)this->counter[1][0] * v7),
      (float)((float)this->counter[2][0] * v7),
      (float)((float)v8 * v7),
      (float)((float)this->counter[4][0] * v7),
      (float)((float)v4 * v7),
      (float)((float)v5 * v7),
      (float)((float)v6 * v7));
    memset(dst: (unsigned __int8 *)&this->IVP_PerformanceCounter + 4, value: 0, count: 0xA4u);
    this->time_of_last_reset = current_time;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A330
// Name: public: virtual void IVP_PerformanceCounter_Simple::environment_is_going_to_be_deleted(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_PerformanceCounter_Simple::environment_is_going_to_be_deleted(
        IVP_PerformanceCounter_Simple *this,
        IVP_Environment *__formal)
{
  if ( this != nullptr )
    ((void (__thiscall *)(IVP_PerformanceCounter_Simple *, int))this->dtr_IVP_PerformanceCounter)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009A340
// Name: public: IVP_PerformanceCounter_Simple::IVP_PerformanceCounter_Simple(void)
// Source: json
//------------------------------------------------------------------------------
IVP_PerformanceCounter_Simple *__thiscall IVP_PerformanceCounter_Simple::IVP_PerformanceCounter_Simple(
        IVP_PerformanceCounter_Simple *this)
{
  this->__vftable = (IVP_PerformanceCounter_Simple_vtbl *)&IVP_PerformanceCounter_Simple::`vftable';
  memset(dst: (unsigned __int8 *)&this->IVP_PerformanceCounter + 4, value: 0, count: 0xA4u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009A390
// Name: public: virtual void IVP_PerformanceCounter_Simple::pcount(enum IVP_PERFORMANCE_ELEMENT)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_PerformanceCounter_Simple::pcount(IVP_PerformanceCounter_Simple *this, IVP_PERFORMANCE_ELEMENT el)
{
  IVP_PERFORMANCE_ELEMENT counting; // ecx
  double v4; // st7
  __int64 Profile_Freq; // [esp+Ch] [ebp-10h] BYREF
  __int64 Profile_Counter; // [esp+14h] [ebp-8h] BYREF

  if ( el == IVP_PE_PSI_UNIVERSE )
    ++this->count_PSIs;
  QueryPerformanceCounter(lpPerformanceCount: (LARGE_INTEGER *)&Profile_Counter);
  QueryPerformanceFrequency(lpFrequency: (LARGE_INTEGER *)&Profile_Freq);
  counting = this->counting;
  v4 = (double)((int)Profile_Counter - this->ref_counter[0]);
  this->ref_counter64 = Profile_Counter;
  this->counter[counting][0] = (int)(v4 * 1000000.0 / (double)Profile_Freq + (double)this->counter[counting][0]);
  this->counting = el;
}

//------------------------------------------------------------------------------
// Address: 0x1009A400
// Name: public: virtual void IVP_PerformanceCounter_Simple::start_pcount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_PerformanceCounter_Simple::start_pcount(IVP_PerformanceCounter_Simple *this)
{
  this->counting = IVP_PE_PSI_START;
}
