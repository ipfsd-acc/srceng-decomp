// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_i_object_vhash.cxx
// Functions: 2
// ============================================================

#include "ivp\ivp_intern\ivp_i_object_vhash.h"

//------------------------------------------------------------------------------
// Address: 0x100970F0
// Name: protected: virtual enum IVP_BOOL IVP_Object_Callback_Table_Hash::compare(void __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_Object_Callback_Table_Hash::compare(
        IVP_Object_Callback_Table_Hash *this,
        _DWORD *elem0,
        _DWORD *elem1)
{
  return *elem0 == *elem1;
}

//------------------------------------------------------------------------------
// Address: 0x10097110
// Name: public: virtual IVP_Object_Callback_Table_Hash::~IVP_Object_Callback_Table_Hash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Object_Callback_Table_Hash::~IVP_Object_Callback_Table_Hash(IVP_Object_Callback_Table_Hash *this)
{
  int size_mm; // edi
  IVP_VHash_Elem *elems; // eax
  void *elem; // esi

  size_mm = this->size_mm;
  for ( this->__vftable = (IVP_Object_Callback_Table_Hash_vtbl *)&IVP_Collision_Callback_Table_Hash::`vftable';
        size_mm >= 0;
        --size_mm )
  {
    elems = this->elems;
    elem = (void *)elems[size_mm].elem;
    if ( elem != nullptr )
    {
      IVP_Object_Callback_Table::~IVP_Object_Callback_Table(this: (IVP_Collision_Callback_Table *)elems[size_mm].elem);
      free(data: elem);
    }
  }
  IVP_VHash::~IVP_VHash(this);
}
