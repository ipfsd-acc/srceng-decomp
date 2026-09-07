// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_vector.cxx
// Functions: 1
// ============================================================

#include "ivp\ivp_utility\ivu_vector.h"

//------------------------------------------------------------------------------
// Address: 0x10070DC0
// Name: public: void IVP_U_Vector_Base::increment_mem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Vector_Base::increment_mem(IVP_U_Vector_Base *this)
{
  void **v2; // edi
  unsigned int v3; // eax
  int v4; // eax
  void **elems; // eax

  v2 = (void **)p_malloc(size: 8 * this->memsize + 8);
  v3 = 2 * this->memsize + 1;
  if ( v3 <= 0xFFFF )
    this->memsize = v3;
  else
    this->memsize = -1;
  v4 = 0;
  if ( this->n_elems != 0 )
  {
    do
    {
      v2[v4] = this->elems[v4];
      ++v4;
    }
    while ( v4 < this->n_elems );
  }
  elems = this->elems;
  if ( elems != (void **)(this + 1) && elems != nullptr )
  {
    free(data: this->elems);
    this->elems = nullptr;
  }
  this->elems = v2;
}
