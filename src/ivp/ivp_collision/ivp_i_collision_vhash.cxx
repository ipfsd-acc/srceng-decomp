// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_i_collision_vhash.cxx
// Functions: 1
// ============================================================

#include "ivp\ivp_collision\ivp_i_collision_vhash.h"

//------------------------------------------------------------------------------
// Address: 0x10097080
// Name: protected: int IVP_Collision_Callback_Table_Hash::object_to_index(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IVP_Collision_Callback_Table_Hash::object_to_index(
        IVP_Object_Callback_Table_Hash *this,
        IVP_Real_Object *real_object)
{
  unsigned int v2; // eax
  unsigned int v3; // eax

  v2 = IVP_Hash_crctab[(unsigned __int8)(~LOBYTE(IVP_Hash_crctab[(unsigned __int8)~(_BYTE)real_object])
                                       ^ BYTE1(real_object))]
     ^ ((IVP_Hash_crctab[(unsigned __int8)~(_BYTE)real_object] ^ 0xFFFFFF) >> 8);
  v3 = IVP_Hash_crctab[(unsigned __int8)(v2 ^ BYTE2(real_object))] ^ (v2 >> 8);
  return IVP_Hash_crctab[(unsigned __int8)(v3 ^ HIBYTE(real_object))] ^ (v3 >> 8) | 0x80000000;
}
