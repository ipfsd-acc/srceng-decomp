// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_i_point_vhash.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_compact_builder\ivp_i_point_vhash.h"

//------------------------------------------------------------------------------
// Address: 0x1004C4E0
// Name: protected: int IVP_I_Point_VHash::point_to_index(class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IVP_I_Point_VHash::point_to_index(IVP_I_Point_VHash *this, IVP_U_Point *point)
{
  unsigned int v2; // eax
  char *v3; // ecx
  int i; // edx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = -1;
  v3 = (char *)point->k + 2;
  for ( i = 2; i != 0; --i )
  {
    v5 = IVP_Hash_crctab[(unsigned __int8)(v2 ^ *(v3 - 2))] ^ (v2 >> 8);
    v6 = IVP_Hash_crctab[(unsigned __int8)(v5 ^ *(v3 - 1))] ^ (v5 >> 8);
    v7 = IVP_Hash_crctab[(unsigned __int8)(v6 ^ *v3)] ^ (v6 >> 8);
    v8 = IVP_Hash_crctab[(unsigned __int8)(v7 ^ v3[1])] ^ (v7 >> 8);
    v9 = IVP_Hash_crctab[(unsigned __int8)(v8 ^ v3[2])] ^ (v8 >> 8);
    v2 = IVP_Hash_crctab[(unsigned __int8)(v9 ^ v3[3])] ^ (v9 >> 8);
    v3 += 6;
  }
  return v2 | 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x10056AA0
// Name: public: virtual IVP_point_hash::~IVP_point_hash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_point_hash::~IVP_point_hash(IVP_I_Point_VHash *this)
{
  this->__vftable = (IVP_I_Point_VHash_vtbl *)&IVP_I_FPoint_VHash::`vftable';
  IVP_VHash::~IVP_VHash(this);
}

//------------------------------------------------------------------------------
// Address: 0x10056AB0
// Name: protected: virtual enum IVP_BOOL IVP_point_hash::compare(void __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_point_hash::compare(IVP_I_Point_VHash *this, _BYTE *elem0, _BYTE *elem1)
{
  _DWORD *v3; // eax
  unsigned int v4; // ecx

  v3 = elem1;
  v4 = 12;
  while ( *(_DWORD *)((char *)v3 + elem0 - elem1) == *v3 )
  {
    v4 -= 4;
    ++v3;
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}
