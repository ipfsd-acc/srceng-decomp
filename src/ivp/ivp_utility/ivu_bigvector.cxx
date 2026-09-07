// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_bigvector.cxx
// Functions: 1
// ============================================================

#include "ivp\ivp_utility\ivu_bigvector.h"

//------------------------------------------------------------------------------
// Address: 0x1008D4A0
// Name: public: void IVP_U_BigVector_Base::increment_mem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_BigVector_Base::increment_mem(IVP_U_BigVector_Base *this)
{
  void **v2; // edi
  int i; // eax
  void **elems; // eax

  v2 = (void **)p_malloc(size: 8 * this->memsize + 8);
  this->memsize = 2 * this->memsize + 1;
  for ( i = 0; i < this->n_elems; ++i )
    v2[i] = this->elems[i];
  elems = this->elems;
  if ( elems != (void **)(this + 1) && elems != nullptr )
  {
    free(data: this->elems);
    this->elems = nullptr;
  }
  this->elems = v2;
}
